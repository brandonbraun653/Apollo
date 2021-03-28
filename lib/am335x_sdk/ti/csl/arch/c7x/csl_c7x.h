/*
 *  Copyright (C) 2019 Texas Instruments Incorporated.
 *
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

#ifndef CSL_C7X_H
#define CSL_C7X_H
/**
 *  @{
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <ti/csl/arch/c7x/csl_c7x_misc.h>
#include <ti/csl/arch/c7x/cslr_DMC.h>
#include <ti/csl/arch/c7x/cslr_C7X_CPU.h>
#include <ti/csl/arch/c7x/cslr_PMC.h>
#include <ti/csl/arch/c7x/cslr_UMC.h>
#include <ti/csl/arch/c7x/csl_c7xecr.h>
#include <ti/csl/arch/c7x/csl_c7x_events.h>
#if defined (HOST_EMULATION)
  #if defined (__C7100__)
    #include <c7x_host_emulation.h>
  #endif
#else
  #if defined (__C7100__)
    #include <c7x.h>
  #endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/**
 * @brief Cache type definitions
 */
#define C7X_CACHE_TYPE_L1D (0)
#define C7X_CACHE_TYPE_L1P (1)
#define C7X_CACHE_TYPE_L2  (2)

/**
 * @brief L1D cache size definitions
 */
#define C7X_L1D_CACHE_SIZE_8KB   (2)
#define C7X_L1D_CACHE_SIZE_16KB  (3)
#define C7X_L1D_CACHE_SIZE_32KB  (4)

/**
 * @brief L2 cache size definitions
 */
#define C7X_L2_CACHE_SIZE_0KB   (0)
#define C7X_L2_CACHE_SIZE_32KB  (1)
#define C7X_L2_CACHE_SIZE_64KB  (2)
#define C7X_L2_CACHE_SIZE_128KB (3)
#define C7X_L2_CACHE_SIZE_256KB (4)
#define C7X_L2_CACHE_SIZE_512KB (5)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * @n@b CSL_c7xSetL1DCacheSize
 *
 * @b Description
 * @n  Sets the size of the L1D Cache
 *
 * @b Arguments
 * @n  uint64_t   size
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 * uint64_t      l1dmod;
 *
 * if (cacheksize == 8) { l1dmod = 2}
 * else if (cacheksize == 16) { l1dmod = 3}
 * else if (cacheksize == 32) { l1dmod = 4}
 *
 *  CSL_c7xSetL1DCacheSize(l1dmod);
 * @endverbatim
 */
void CSL_c7xSetL1DCacheSize(uint64_t l1dmod);

/**
 * @n@b CSL_c7xSetL2CacheSize
 *
 * @b Description
 * @n  Sets the size of the L2 Cache
 *
 *
 *
 * @b Arguments
 * @n  uint64_t l2mod
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 * uint64_t        l2mod;
 *
 * if (cacheksize == 0) {l2mod = 0}
 * else if (cacheksize == 32) {l2mod = 1}
 * else if (cacheksize == 64) {l2mod = 2}
 * else if (cacheksize == 128) {l2mod = 3}
 * else if (cacheksize == 256) {l2mod = 4}
 * else if (cacheksize == 512) {l2mod = 5}
 * else if (cacheksize == 1024 {l2mod = 6}
 * else {l2mod = 7}
 *
 * CSL_c7xSetL2CahceSize(l2mod);
 * @endverbatim
 */
void CSL_c7xSetL2CacheSize(uint64_t l2mod);

/**
 * @n@b CSL_c7xInvalidateL1PCache
 *
 * @b Description
 * @n  Invalidates the L1P Cache Contents
 *
 *
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 * CSL_c7xInvalidateL1PCache();
 * @endverbatim
 */
void CSL_c7xInvalidateL1PCache();

/**
 * @n@b CSL_c7xInvalidateL1DCache
 *
 * @b Description
 * @n  Invalidates the contents of the L1D Cache
 *
 *
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  CSL_c7xInvalidateL1DCache();
 * @endverbatim
 */
void CSL_c7xInvalidateL1DCache();

/**
 * @n@b CSL_c7xInvalidateL2Cache
 *
 * @b Description
 * @n  Invalidates the contents of the L2 Cache
 *
 *
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  CSL_c7xInvalidateL12ache();
 * @endverbatim
 */
void CSL_c7xInvalidateL2Cache();

/**
 * @n@b CSL_c7xCleaninvalidateL1DCache
 *
 * @b Description
 * @n   Cleans and Invalidates(forces writeback)  the contents of the L1D Cache
 *
 *
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  CSL_c7xCleaninvalidateL1DCache();
 * @endverbatim
 */
void CSL_c7xCleaninvalidateL1DCache();

/**
 * @n@b CSL_c7xCleaninvalidateL2Cache
 *
 * @b Description
 * @n   Cleans and Invalidates(forces writeback)  the contents of the L2 Cache
 *
 *
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  CSL_c7xCleaninvalidateL2Cache();
 * @endverbatim
 */
void CSL_c7xCleaninvalidateL2Cache();

/**
 * @n@b CSL_c7xCleaninvalidateL2Cache
 *
 * @b Description
 * @n   Cleans and Invalidates(forces writeback)  the contents of the L2 Cache
 *
 *
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  CSL_c7xCleaninvalidateL2Cache();
 * @endverbatim
 */
void CSL_c7xCleaninvalidateL2Cache();

/**
 * @n@b CSL_c7xGetCpuMode
 *
 * @b Description
 * @n   Get the current mode of CPU
 *
 *
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t current_cpu_mode
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *  uint64_t current_cpu_mode;
 *  current_cpu_mode = CSL_c7xGetCpuMode();
 *
 * @endverbatim
 */
uint64_t CSL_c7xGetCpuMode();

/**
 * @n@b CSL_c7xMMUEnable
 *
 * @b Description
 * @n   Enables c7x MMU
 *
 *
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  CSL_c7xMMUEnable();
 * @endverbatim
 */
void CSL_c7xMMUEnable();

/**
 * @n@b CSL_c7xMMUIsEnabled
 *
 * @b Description
 * @n   determines whether MMU is enabled or not
 *
 *
 *
 * @b Arguments
 * @n  None
 *
 * <b> Return Value </b>
 * @n uint64_t mmu_is_enabled
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  uint64_t mmu_is_enabled;
 *  mmu_is_enabled = CSL_c7xMMUIsEnabled();
 * @endverbatim
 */
uint64_t CSL_c7xMMUIsEnabled();

/**
 * @n@b CSL_c7xMMUSetMAIR
 *
 * @b Description
 * @n   sets the Memory Attribute Indirection Register
 *
 *
 *
 * @b Arguments
 * @n  uint64_t param
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  uint64_t param = 0x3D3D3D3D3D3D3D3D;
 *  CSL_c7xMMUSetMAIR(param);
 * @endverbatim
 */
void CSL_c7xMMUSetMAIR(uint64_t param);

/**
 * @n@b CSL_c7xMmuTlbInvByASID
 *
 * @b Description
 * @n   invalidates the entire TLB entries for the given ASID
 *
 *
 *
 * @b Arguments
 * @n  uint64_t asid
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  uint64_t asid = 0x0;
 *  CSL_c7xMmuTlbInvByASID(asid);
 * @endverbatim
 */
void CSL_c7xMmuTlbInvByASID(uint64_t asid);

/**
 * @n@b CSL_c7xMmuTlbInvLL
 *
 * @b Description
 * @n   invalidates the entire TLB entries for the last level
 *
 *
 *
 * @b Arguments
 * @n None
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  CSL_c7xMmuTlbInvLL();
 * @endverbatim
 */
void CSL_c7xMmuTlbInvLL();

/**
 * @n@b CSL_c7xMmuTlbInvByVA
 *
 * @b Description
 * @n   invalidates the entire TLB entries for the given virtual address
 *
 *
 *
 * @b Arguments
 * @n  uint64_t va
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  uint64_t va = 0x800000;
 *  CSL_c7xMmuTlbInvByVA(va);
 * @endverbatim
 */
void CSL_c7xMmuTlbInvByVA(uint64_t va);

/**
 * @n@b CSL_c7xMmuTlbInvAll
 *
 * @b Description
 * @n   invalidates the entire TLB
 *
 *
 *
 * @b Arguments
 * @n None
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  CSL_c7xMmuTlbInvAll();
 * @endverbatim
 */
void CSL_c7xMmuTlbInvAll();

/**
 * @n@b CSL_c7xMmuGetErrInfo
 *
 * @b Description
 * @n   Returns the response information for the translation
 *
 *
 *
 * @b Arguments
 * @n None
 *
 * <b> Return Value </b>
 * @n uint64_t response
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *
 *  uint64_t response = CSL_c7xMmuGetErrInfo();
 * @endverbatim
 */
uint64_t CSL_c7xMmuGetErrInfo();


/**
 * @n@b CSL_c7xCacheInvalidateAll
 *
 * @b Description
 * @n Invalidates the contents of the specified cache
 *
 *
 *
 * @b Arguments
 * @n  uint8_t cache_type
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *  uint8_t cache_type = C7X_CACHE_TYPE_L1;
 *
 *  CSL_c7xCacheInvalidateAll(cache_type);
 * @endverbatim
 */
void CSL_c7xCacheInvalidateAll(uint8_t cache_type);

/**
 * @n@b CSL_c7xCacheWriteBackInvalidateAll
 *
 * @b Description
 * @n Writes back and invalidates the contents of the specified cache
 *
 *
 *
 * @b Arguments
 * @n  uint8_t cache_type
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *  uint8_t cache_type = C7X_CACHE_TYPE_L1;
 *
 *  CSL_c7xCacheWriteBackInvalidateAll(cache_type);
 * @endverbatim
 */
void CSL_c7xCacheWriteBackInvalidateAll(uint8_t cache_type);


/**
 * @n@b CSL_c7xSetCacheSize
 *
 * @b Description
 * @ Enables/disables the specified cache and sets the size specified.
 *
 *
 *
 * @b Arguments
 * @n  uint8_t cache_type
 * @n  uint8_t cache_size
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *  uint8_t cache_type = C7X_CACHE_TYPE_L1;
 *  uint8_t cache_size = C7X_L1D_CACHE_SIZE_8KB;
 *
 *  CSL_c7xSetCacheSize(cache_type, cache_size);
 * @endverbatim
 */
void CSL_c7xSetCacheSize(uint8_t cache_type, uint8_t cache_size);

/**
 * @n@b CSL_c7xCacheWriteBackInvalidateBlock
 *
 * @b Description
 * @ Write-back and invalidate all cache as per input range specified by
 * startAddr and numBytes.
 *
 *
 *
 * @b Arguments
 * @n  uint64_t startAddr
 * @n  uint64_t numBytes
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *  uint64_t startAddr = 0x70000000U;
 *  uint64_t numBytes  = 32;
 *
 *  CSL_c7xCacheWriteBackInvalidateBlock(startAddr, numBytes);
 * @endverbatim
 */
void CSL_c7xCacheWriteBackInvalidateBlock(uint64_t startAddr, uint64_t numBytes);

/**
 * @n@b CSL_c7xCacheInvalidateBlock
 *
 * @b Description
 * @ Invalidate all cache per input range specified by startAddr and numBytes.
 *
 *
 *
 * @b Arguments
 * @n  uint64_t startAddr
 * @n  uint64_t numBytes
 *
 * <b> Return Value </b>
 * @n None
 *
 * <b> Pre Condition </b>
 * @n None
 *
 * <b> Post Condition </n>
 * @n None
 *
 * @b Reads
 * @n None
 *
 * @b Example
 * @verbatim
 *
 *  uint64_t startAddr = 0x70000000U;
 *  uint64_t numBytes  = 32;
 *
 *  CSL_c7xCacheInvalidateBlock(startAddr, numBytes);
 * @endverbatim
 */
void CSL_c7xCacheInvalidateBlock(uint64_t startAddr, uint64_t numBytes);


/**
 * @n@b CSL_c7xMMUInit
 *
 * @b Description
 * @ Initializes the C7x MMU
 *
 *
 *
 * @b Arguments
 * @n  tcr    TCR register in MMU
 * @n  ttbr   TTBR0 register in MMU
 * @n  mar    MAR register in MMU
 * @n  scr    SCR register in MMU
 *
 * <b> Return Value </b>
 * @n None
 *
 */
void CSL_c7xMMUInit(uint64_t tcr, uint64_t ttbr, uint64_t mar, uint64_t scr);

#ifdef __cplusplus
}
#endif
/** @} */

#endif  /* CSL_C7X_H */
