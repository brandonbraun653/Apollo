/**
 *  \file   pl310.c
 *
 *  \brief  This file contains the APIs for configuring the PL310 cache. PL310
 *          is on-chip secondary cache. It is a unified, physically addressed-
 *          physically tagged cache. The memory can be alternatively configured
 *          as SRAM instead of cache.
 *
 *          The API's are defined to work from Non-secure side with SMC calls
 *          to access the secure only register. If these API's are to be used on
 *          secure side, the implementation has to be enhanced to support the
 *          same.
 *
 *          The API's are implemented to work on single core processors. For
 *          use in multi-core platforms appropriate lock has to be added before
 *          doing any cache operations. The API's are implemented to work with
 *          revision r3p2 and later, as the errata previous to this version are
 *          not considered in the implementation.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated - 
 *             http://www.ti.com/
 */

/**
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifdef OUTER_CACHE_ENABLE

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "hw_types.h"
#include "pl310.h"
#include "pl310_config.h"
#include "misc.h"
#include "error.h"
#include "cpu.h"
#include "cache.h"
#include "pub2mon.h"
#include "rom_config.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

static uint32_t pl310Base = 0;
static uint32_t noWays = 0;
static uint32_t waySize = 0;
static uint32_t cacheSize = 0;
static cacheOuterAttr_t pl310CacheFn;
static pl310Regs_t pl310RegsSaved;

/* ========================================================================== */
/*                      Internal Function Declarations                        */
/* ========================================================================== */

static void pl310Enable(void);
static void pl310InvRange(uint32_t* pStartAddr, uint32_t numBytes);
static void pl310InvAll(void);
static void pl310CleanRange(uint32_t* pStartAddr, uint32_t numBytes);
static void pl310CleanAll(void);
static void pl310CleanInvRange(uint32_t* pStartAddr, uint32_t numBytes);
static void pl310CleanInvAll(void);
static void pl310Sync(void);
static int32_t pl310LockByWay(uint32_t lockWay, uint32_t* pStartAddr, 
                                                          uint32_t numBytes);
static int32_t pl310UnlockByWay(uint32_t unlockWay);

static inline void pl310InvLine(uint32_t* pInvAddr);
static inline void pl310CleanLine(uint32_t* pInvAddr);
static inline void pl310CleanInvLine(uint32_t* pInvAddr);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t PL310Init(uint32_t* pPL310BaseAddr, uint32_t auxMask, uint32_t auxVal,
                                                          uint32_t isCpuSecure)
{
    uint32_t index;
    uint32_t auxCtrlRegVal = 0;
    pl310Base = (uint32_t)pPL310BaseAddr;

    auxCtrlRegVal = HW_RD_REG32(pl310Base + PL310_AUX_CTRL);
    auxVal = (auxVal & auxMask) | auxCtrlRegVal;

    /* Some of the registers are writeable in secure mode only. In Non-Secure
       mode appropriate SMC requests has to be made to the monitor mode. */
    if(FALSE == isCpuSecure)
    {
        /* Configure TAG and DATA RAM Latencies */
        Pub2MonDispatch(
               SMC_ID_TAG_DATA_RAM_LAT_CTRL, /* SMC ID */
               ( /* Tag RAM latencies */
                (PL310_TAG_RAM_READ_LAT_VAL  << 
								PL310_TAG_RAM_LAT_CTRL_READ_ACCESS_SHIFT) |
                (PL310_TAG_RAM_WRITE_LAT_VAL << 
								PL310_TAG_RAM_LAT_CTRL_WRITE_ACCESS_SHIFT) |
                (PL310_TAG_RAM_WRITE_LAT_VAL << 
								PL310_TAG_RAM_LAT_CTRL_SETUP_SHIFT)
               ),
               ( /* DATA RAM latencies */
                (PL310_DATA_RAM_READ_LAT_VAL << 
								PL310_DATA_RAM_LAT_CTRL_READ_ACCESS_SHIFT) |
                (PL310_DATA_RAM_WRITE_LAT_VAL << 
								PL310_DATA_RAM_LAT_CTRL_WRITE_ACCESS_SHIFT) |
                (PL310_DATA_RAM_SETUP_LAT_VAL << 
								PL310_DATA_RAM_LAT_CTRL_SETUP_SHIFT)
               )
            );

        /* Address filtering configurations */
        if(PL310_ADDR_FILTERING_EN)
        {
            /* TODO: Filter config */
			/* End mask, Start mask and enable filtering. */
        }

        /* Write aux value passed by the user */
        Pub2MonDispatch(SMC_ID_AUX_CTRL_REG, auxVal,0);
    }
    else
    {
        return E_INVALID_OPERATION;
    }

    /* Get the number of ways supported */
    if(auxVal & PL310_AUX_CTRL_ASSOCIATIVITY_MASK)
        noWays = 16;
    else
        noWays = 8;

    /* Get the cache size */
    waySize = (auxVal & PL310_AUX_CTRL_WAY_SIZE_MASK) >>
                            PL310_AUX_CTRL_WAY_SIZE_SHIFT;
    waySize = 1 << (waySize + 3);
    cacheSize = noWays * waySize * MEM_SIZE_KB;

    /* Initialized cache */
    if(PL310_CTRL_L2_CACHE_EANBLE_MASK !=
       (HW_RD_REG32(pl310Base + PL310_CTRL) & PL310_CTRL_L2_CACHE_EANBLE_MASK))
    {
        /* Check if access to the registers are allowed */
        if((isCpuSecure) || (auxVal & PL310_AUX_CTRL_NS_LOCKDOWN_EN_MASK))
        {
            /* Make sure the cache is unlocked */
            for (index = 0; index < 8; index++)
            {
                HW_WR_REG32(pl310Base + PL310_DATA_LOCKDOWN_BY_WAY(index), 0);
                HW_WR_REG32(pl310Base + PL310_INSTR_LOCKDOWN_BY_WAY(index), 0);
            }
        }
        else
        {
            return E_INVALID_OPERATION;
        }
    }

    /* Outer cache function pointers */
    pl310CacheFn.pFnOuterCacheEnable          = &pl310Enable;
    pl310CacheFn.pFnOuterCacheDisable         = &PL310Disable;
    pl310CacheFn.pFnOuterCacheInvRange        = &pl310InvRange;
    pl310CacheFn.pFnOuterCacheInvAll          = &pl310InvAll;
    pl310CacheFn.pFnOuterCacheCleanRange      = &pl310CleanRange;
    pl310CacheFn.pFnOuterCacheCleanAll        = &pl310CleanAll;
    pl310CacheFn.pFnOuterCacheCleanInvRange   = &pl310CleanInvRange;
    pl310CacheFn.pFnOuterCacheCleanInvAll     = &pl310CleanInvAll;
    pl310CacheFn.pFnOuterCacheLockByWay       = &pl310LockByWay;
    pl310CacheFn.pFnOuterCacheUnlockByWay     = &pl310UnlockByWay;
    pl310CacheFn.pFnOuterCacheSaveContext     = &PL310SaveContext;
    pl310CacheFn.pFnOuterCacheRestoreContext  = &PL310RestoreContext;
    pl310CacheFn.isOuterCacheEnabled          = TRUE;

    /* Pre-fetch configuration */
    Pub2MonDispatch(SMC_ID_PREFETCH_CTRL_REG, PL310_PREFETCH_CONFIG, 0);

    /* Standby & auto-clock gating configuration */
    HW_WR_REG32(pl310Base + PL310_POWER_CTRL, PL310_POWER_CTRL_CONFIG);

    /* Clear any interrupts */
    HW_WR_REG32(pl310Base + PL310_INTR_CLR, PL310_INTR_CLR_MASK);

    /* Mask interrupts */
    HW_WR_REG32(pl310Base + PL310_INTR_MASK, PL310_INTR_MASK_CONFIG);

    CACHERegisterOuterCache(&pl310CacheFn);

    return S_PASS;
}

void PL310Disable(void)
{
    uint32_t intStatus = CPUIntrDisable();
    uint32_t ctrlVal = HW_RD_REG32(pl310Base + PL310_CTRL);
    ctrlVal &= ~PL310_CTRL_L2_CACHE_EANBLE_MASK;

    pl310CleanInvAll();

    /* Disable cache - write to control register */
    Pub2MonDispatch(SMC_ID_CTRL_REG, ctrlVal, 0);
    DSB();

    pl310CacheFn.isOuterCacheEnabled = FALSE;

    CPUIntrEnable(intStatus);
}

void PL310DebugConfig(uint32_t dbgConfigVal)
{
    /* Configure in Non-Secure mode */
    Pub2MonDispatch(SMC_ID_SET_DEBUG_REG, dbgConfigVal,0);
}

void PL310SaveContext(void)
{
    /* Save PL310 registers */
    pl310RegsSaved.auxCtrl        = 
						HW_RD_REG32(pl310Base + PL310_AUX_CTRL);
    pl310RegsSaved.tagLatency     = 
						HW_RD_REG32(pl310Base + PL310_TAG_RAM_LAT_CTRL);
    pl310RegsSaved.dataLatency    = 
						HW_RD_REG32(pl310Base + PL310_DATA_RAM_LAT_CTRL);
    pl310RegsSaved.filterStart    = 
						HW_RD_REG32(pl310Base + PL310_ADDR_FILTERING_START);
    pl310RegsSaved.filterEnd      = 
						HW_RD_REG32(pl310Base + PL310_ADDR_FILTERING_END);
    pl310RegsSaved.prefetchCtrl   = 
						HW_RD_REG32(pl310Base + PL310_PREFETCH_OFFSET);
    pl310RegsSaved.pwrCtrl        = 
						HW_RD_REG32(pl310Base + PL310_POWER_CTRL);
    pl310RegsSaved.debugCfg       = 
						HW_RD_REG32(pl310Base + PL310_DBG_CTRL);
    pl310RegsSaved.ctrl           = 
						HW_RD_REG32(pl310Base + PL310_CTRL);
    pl310RegsSaved.interruptMask  = 
						HW_RD_REG32(pl310Base + PL310_INTR_MASK);
}

void PL310RestoreContext(void)
{
    /* Auxiliary control register */
    Pub2MonDispatch(SMC_ID_AUX_CTRL_REG, pl310RegsSaved.auxCtrl,0);

    /* Configure TAG and DATA RAM Latencies */
    Pub2MonDispatch(SMC_ID_TAG_DATA_RAM_LAT_CTRL, pl310RegsSaved.tagLatency,
                                                pl310RegsSaved.dataLatency);

    /* TODO: Filter config */

    /* Pre-fetch configuration */
    Pub2MonDispatch(SMC_ID_PREFETCH_CTRL_REG, pl310RegsSaved.prefetchCtrl, 0);

    /* Standby & auto-clock gating configuration */
    HW_WR_REG32(pl310Base + PL310_POWER_CTRL, pl310RegsSaved.pwrCtrl);

    /* Mask interrupts */
    HW_WR_REG32(pl310Base + PL310_INTR_MASK,pl310RegsSaved.interruptMask);

    /* Debug register */
    Pub2MonDispatch(SMC_ID_SET_DEBUG_REG, pl310RegsSaved.debugCfg, 0);

    /* Control register */
    Pub2MonDispatch(SMC_ID_CTRL_REG, pl310RegsSaved.ctrl, 0);
}

/* -------------------------------------------------------------------------- */
/*                       Internal Function definitions                        */
/* -------------------------------------------------------------------------- */

/**
 * \brief   This API provides the interface to enable the cache. This API has
 *          to be called only if the previous cache levels are enabled and
 *          should not be called independently.
 *
 * \param   None
 *
 * \retval  None
 **/
static void pl310Enable(void)
{
    uint32_t intStatus = CPUIntrDisable();

    /* Invalidate the complete cache */
    pl310InvAll();
    /* Enable cache - write to control register */
    Pub2MonDispatch(SMC_ID_CTRL_REG, PL310_CTRL_L2_CACHE_EANBLE_MASK, 0);
    pl310CacheFn.isOuterCacheEnabled = TRUE;

    CPUIntrEnable(intStatus);
}

/**
 * \brief   This API invalidates the cache line corresponding to the address
 *          passed.
 *
 * \param   *pInvAddr - One address in a line which need to be invalidated.
 *
 * \retval  None
 **/
static inline void pl310InvLine(uint32_t* pInvAddr)
{
#ifdef WAIT_FOR_INV_LINE
    /* Wait for any current invalidate operation to complete */
    while(PL310_INV_LINE_BY_PA_C_MASK == (HW_RD_REG32(pl310Base +
           PL310_INV_LINE_BY_PA) & PL310_INV_LINE_BY_PA_C_MASK));
#endif
    /* Invalidate a line */
    HW_WR_REG32(pl310Base + PL310_INV_LINE_BY_PA, (uint32_t)pInvAddr);
}

/**
 * \brief   This API cleans the cache line corresponding to the address
 *          passed.
 *
 * \param   *pInvAddr - One address in a line which need to be cleaned.
 *
 * \retval  None
 **/
static inline void pl310CleanLine(uint32_t* pInvAddr)
{
#ifdef WAIT_FOR_CLEAN_LINE
    /* Wait for any current clean operation to complete */
    while(PL310_CLEAN_LINE_BY_PA_C_MASK == (HW_RD_REG32(pl310Base +
           PL310_CLEAN_LINE_BY_PA) & PL310_CLEAN_LINE_BY_PA_C_MASK));
#endif
    /* Clean a line */
    HW_WR_REG32(pl310Base + PL310_CLEAN_LINE_BY_PA, (uint32_t)pInvAddr);
}

/**
 * \brief   This API cleans and invalidates the cache line corresponding to the
 *          address passed.
 *
 * \param   *pInvAddr - One address in a line which need to be cleaned and
 *                     invalidated.
 *
 * \retval  None
 **/
static inline void pl310CleanInvLine(uint32_t* pInvAddr)
{
    /* Wait for the clean and invalidate operation to complete */
    while(PL310_CLEAN_AND_INV_LINE_BY_PA_C_MASK == (HW_RD_REG32(pl310Base +
        PL310_CLEAN_AND_INV_LINE_BY_PA) & PL310_CLEAN_AND_INV_LINE_BY_PA_C_MASK));

    /* Clean and Invalidate a line */
    HW_WR_REG32(pl310Base + PL310_CLEAN_AND_INV_LINE_BY_PA, (uint32_t)pInvAddr);
}

/**
 * \brief   This API invalidates range of memory from the cache. Invalidating
 *          here means marking the cache entries as invalid which can be
 *          overwritten with new entries.
 *
 * \param   startAddr   Starting address of the memory range to be invalidated
 *                      from cache
 * \param   numBytes    Number of bytes to be invalidated
 *
 * \retval  None
 **/
static void pl310InvRange(uint32_t* pStartAddr, uint32_t numBytes)
{
    uint32_t intStatus = CPUIntrDisable();
    uint32_t startAddr = (uint32_t)pStartAddr;
    uint32_t endAddr = startAddr + numBytes;

    /* If the range to be invalidated is same as cache size, use InvAll() API. */
    if(numBytes >= cacheSize)
    {
        pl310InvAll();
        return;
    }

    /* Check the alignment of start address. If it is not aligned align the
       starting address to line boundary. Also clean and invalidate the first
       line as it is not aligned and might contain addresses other than the
       intended address range. */
    if(startAddr & (PL310_LINE_SIZE - 1))
    {
        startAddr &= ~(PL310_LINE_SIZE - 1);
        pl310CleanInvLine((uint32_t*)startAddr);
        startAddr += PL310_LINE_SIZE;
    }

    /* Check the alignment of end address. */
    if(endAddr & (PL310_LINE_SIZE - 1))
    {
        endAddr &= ~(PL310_LINE_SIZE - 1);
        pl310CleanInvLine((uint32_t*)endAddr);
    }

    /* Invalidate the range - one line at a time. */
    while (startAddr < endAddr)
    {
        pl310InvLine((uint32_t*)startAddr);
        startAddr += PL310_LINE_SIZE;
    }

    /* Wait for the invalidate operation to complete */
    while(PL310_INV_LINE_BY_PA_C_MASK == (HW_RD_REG32(pl310Base +
                     PL310_INV_LINE_BY_PA) & PL310_INV_LINE_BY_PA_C_MASK));

    /* Wait for the buffers to be flushed */
    pl310Sync();

    CPUIntrEnable(intStatus);
}

/**
 * \brief   This API invalidates all the contents from the cache.
 *          Invalidating here means marking the cache entries as invalid which
 *          can be overwritten with new entries.
 *
 * Note:    This function can't be used to invalidate stack memory (if stack is
 *          cache-able).
 *
 * \param   None
 *
 * \retval  None
 **/
static void pl310InvAll(void)
{
    uint32_t intStatus = CPUIntrDisable();

    /* Invalidate all the ways */
    HW_WR_REG32(pl310Base + PL310_INV_BY_WAY,
                                       PL310_INV_BY_WAY_WAYBITS_MASK);
    /* Wait for invalidate operation to complete */
    while(HW_RD_REG32(pl310Base + PL310_INV_BY_WAY) &
                                       PL310_INV_BY_WAY_WAYBITS_MASK);
    /* Wait for the buffers to be flushed */
    pl310Sync();

    DSB();

    CPUIntrEnable(intStatus);
}

/**
 * \brief   This API cleans the given memory range from cache. Cleaning here
 *          means writing back updated data to main memory. However the cache
 *          entries will not be invalidated by this API.
 *
 * \param   startAddr   Starting address of the memory range to be cleaned from
 *                      cache
 * \param   numBytes    Number of byte to be cleaned
 *
 * \retval  None
 **/
static void pl310CleanRange(uint32_t* pStartAddr, uint32_t numBytes)
{
    uint32_t intStatus = 0;
    uint32_t startAddr = (uint32_t)pStartAddr;
    uint32_t endAddr = startAddr + numBytes;

    /* If the range to be cleaned is same as cache size, use InvAll() API. */
    if(numBytes >= cacheSize)
    {
        pl310CleanAll();
        return;
    }

    intStatus = CPUIntrDisable();

    startAddr &= ~(PL310_LINE_SIZE - 1);
    while (startAddr < endAddr)
    {
        pl310CleanLine((uint32_t*)startAddr);
        startAddr += PL310_LINE_SIZE;
    }
    /* Wait for any current clean operation to complete */
    while(PL310_CLEAN_LINE_BY_PA_C_MASK == (HW_RD_REG32(pl310Base +
           PL310_CLEAN_LINE_BY_PA) & PL310_CLEAN_LINE_BY_PA_C_MASK));

    /* Wait for the buffers to be flushed */
    pl310Sync();

    CPUIntrEnable(intStatus);
}

/**
 * \brief   This API cleans the complete cache. Cleaning here means writing
 *          back updated data to main memory. However the cache entries
 *          will not be invalidated by this API.
 *
 * \param   None
 *
 * \retval  None
 **/
static void pl310CleanAll(void)
{
    uint32_t intStatus = CPUIntrDisable();

    HW_WR_REG32(pl310Base + PL310_CLEAN_BY_WAY, PL310_CLEAN_BY_WAY_WAYBITS_MASK);
    /* Wait for the clean operation to complete */
    while(PL310_CLEAN_BY_WAY_WAYBITS_MASK ==
                                     (HW_RD_REG32(pl310Base + PL310_CLEAN_BY_WAY) &
                                       PL310_CLEAN_BY_WAY_WAYBITS_MASK));
    /* Wait for the buffers to be flushed */
    pl310Sync();

    DSB();

    CPUIntrEnable(intStatus);
}

/**
 * \brief   This API cleans and invalidates range of memory from the corresponding
 *          cache. Cleaning here means writing back updated data to main memory.
 *          Invalidating here means marking the cache entries as invalid which
 *          can be overwritten with new entries.
 *
 * \param   startAddr   Starting address of the memory range to be cleaned and
 *                      invalidated from the cache
 * \param   numBytes    Number of bytes to be invalidated
 *
 * \retval  None
 **/
static void pl310CleanInvRange(uint32_t* pStartAddr, uint32_t numBytes)
{
    uint32_t intStatus = 0;
    uint32_t startAddr = (uint32_t)pStartAddr;
    uint32_t endAddr = startAddr + numBytes;

    if (numBytes >= cacheSize)
    {
        pl310CleanInvAll();
        return;
    }

    intStatus = CPUIntrDisable();
    startAddr &= ~(PL310_LINE_SIZE - 1);
    while (startAddr < endAddr)
    {
        pl310CleanInvLine((uint32_t*)startAddr);
        startAddr += PL310_LINE_SIZE;
    }

    /* Wait for the clean operation to complete */
    while(PL310_CLEAN_AND_INV_LINE_BY_PA_C_MASK ==
                          (HW_RD_REG32(pl310Base + PL310_CLEAN_AND_INV_LINE_BY_PA) &
                                      PL310_CLEAN_AND_INV_LINE_BY_PA_C_MASK));
    pl310Sync();
    CPUIntrEnable(intStatus);
}

/**
 * \brief   This API cleans and invalidates complete cache. Cleaning here means
 *          writing back updated data to main memory. Invalidating here means
 *          marking the cache entries as invalid which can be overwritten with
 *          new entries.
 *
 * \param   None
 *
 * \retval  None
 **/
static void pl310CleanInvAll(void)
{
    uint32_t intStatus = CPUIntrDisable();

    HW_WR_REG32(pl310Base + PL310_CLEAN_AND_INV_BY_WAY,
                                      PL310_CLEAN_AND_INV_BY_WAY_WAYBITS_MASK);
    /* Wait for the clean operation to complete */
    while(PL310_CLEAN_AND_INV_BY_WAY_WAYBITS_MASK ==
                                (HW_RD_REG32(pl310Base + PL310_CLEAN_AND_INV_BY_WAY) &
                                      PL310_CLEAN_AND_INV_BY_WAY_WAYBITS_MASK));
    /* Wait for the buffers to be flushed */
    pl310Sync();
    CPUIntrEnable(intStatus);
}

/**
 * \brief   This API drains all the buffers (LRB, LFB, STB, and EB). This
 *          operation need to be performed after clean/invalidate operation
 *          and before disabling the cache.  Sync operation forces the system
 *          to wait for pending operations to complete.
 *
 * \param   None
 *
 * \retval  None
 **/
static void pl310Sync(void)
{
    HW_WR_REG32(pl310Base + PL310_CACHE_SYNC, 0);
    while(PL310_CACHE_SYNC_MASK == (HW_RD_REG32(pl310Base + PL310_CACHE_SYNC) &
                                                 PL310_CACHE_SYNC_MASK));
}

/**
 * \brief   This API locks the cache by Way. The caller is expectred to disable
 *          the interrupts and clean and invalidate the buffer.
 *
 * \param   lockWay     Indicates the way to be locked from eviction
 * \param   startAddr   Start address from where the content should be loaded
 *                      in to cache before cache is locked. If the contents are
 *                      cacheable in L1 cache and exclusive configuration is
 *                      enabled, the contents may not reside in outer cache when
 *                      the lock is applied.
 *
 * \param   numBytes    Number of bytes from the start address to be locked
 *
 * \retval  result      Result of lock operation or error id incase of any error.
 **/
static int32_t pl310LockByWay(uint32_t lockWay, uint32_t* pStartAddr,
                                                              uint32_t numBytes)
{
    uint32_t dataLockStatus = 0;
    uint32_t instLockStatus = 0;
    uint32_t index = 0;
    volatile uint32_t readvalue = 0;

    /* Unlock the way in which the contents should be loaded and lock the
       other ways. */
    dataLockStatus = HW_RD_REG32(pl310Base + PL310_DATA_LOCKDOWN_BY_WAY(0));
    instLockStatus = HW_RD_REG32(pl310Base + PL310_INSTR_LOCKDOWN_BY_WAY(0));

    HW_WR_REG32((pl310Base + PL310_DATA_LOCKDOWN_BY_WAY(0)),
                    (~lockWay) & PL310_DATA_LOCKDOWN_BY_WAY_LOCK_MASK);
    HW_WR_REG32((pl310Base + PL310_INSTR_LOCKDOWN_BY_WAY(0)),
                    (~lockWay) & PL310_INSTR_LOCKDOWN_BY_WAY_LOCK_MASK);

    /* Load memory contents to cache (read allocate enabled for the memory
       region) */
    for(index = 0; (index < numBytes); index += PL310_LINE_SIZE)
    {
        readvalue = *(pStartAddr + index/sizeof(pStartAddr));
        readvalue +=1;
    }

    /* Lock the required way and reload the lock configuration for other ways.*/
    HW_WR_REG32((pl310Base + PL310_DATA_LOCKDOWN_BY_WAY(0)), lockWay | dataLockStatus);
    HW_WR_REG32((pl310Base + PL310_INSTR_LOCKDOWN_BY_WAY(0)), lockWay | instLockStatus);

    /* Wait for the buffers to be flushed */
    pl310Sync();

    return S_PASS;
}

/**
 * \brief   This API unlocks the cache by Way.
 *
 * \param   unlockWay  Indicates the way to be unlocked, so that it can be evicted.
 *
 * \retval  result      Result of unlock operation or error id incase of any error.
 **/
static int32_t pl310UnlockByWay(uint32_t unlockWay)
{
    uint32_t lockVal = 0;

    lockVal = HW_RD_REG32(pl310Base + PL310_DATA_LOCKDOWN_BY_WAY(0));
    lockVal &= ((~unlockWay) & PL310_DATA_LOCKDOWN_BY_WAY_LOCK_MASK);
    HW_WR_REG32((pl310Base + PL310_DATA_LOCKDOWN_BY_WAY(0)), lockVal);

    lockVal = HW_RD_REG32(pl310Base + PL310_INSTR_LOCKDOWN_BY_WAY(0));
    lockVal &= ((~unlockWay) & PL310_INSTR_LOCKDOWN_BY_WAY_LOCK_MASK);
    HW_WR_REG32((pl310Base + PL310_INSTR_LOCKDOWN_BY_WAY(0)), lockVal);

    return S_PASS;
}

#endif /* OUTER_CACHE_ENABLE */
