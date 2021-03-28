/**
 *  \file   cp15.h
 *
 *  \brief  CP15 related function prototypes
 *
 *  This file contains the API prototypes for configuring CP15 
 * (ARM coprocessor), which includes cache, MMU and interrupt vector base.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated - 
 *             http://www.ti.com/
 */

/*
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

#ifndef CP15_H_
#define CP15_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** Macros which can be passed to CP15ControlFeatureDisable/Enable APIs as 
    'features'. Any, or an OR combination of the below macros can be passed to
    disable/enable the corresponding feature. */

/** \brief TEX remap mask. */
#define CP15_CONTROL_TEXREMAP                  (0x10000000U)
/** \brief Access Flag Enable mask (part of page table entry). */
#define CP15_CONTROL_ACCESSFLAG                (0x20000000U)
/** \brief Alignment fault checking enable mask. */
#define CP15_CONTROL_ALIGN_CHCK                (0x00000002U)
/** \brief MMU enable mask. */
#define CP15_CONTROL_MMU                       (0x00000001U)
/** \brief L2 Cache enable (specific to Cortex-A8). */
#define CP15_CORTEX_A8_L2EN                    (0x00000002U)

/** \brief Primary part is Cortex-A5. */
#define CP15_PRIMARY_PART_CORTEX_A5            (0xC05U)
/** \brief Primary part is Cortex-A7. */
#define CP15_PRIMARY_PART_CORTEX_A7            (0xC07U)
/** \brief Primary part is Cortex-A8. */
#define CP15_PRIMARY_PART_CORTEX_A8            (0xC08U)
/** \brief Primary part is Cortex-A9. */
#define CP15_PRIMARY_PART_CORTEX_A9            (0xC09U)
/** \brief Primary part is Cortex-A15. */
#define CP15_PRIMARY_PART_CORTEX_A15           (0xC0FU)

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API enables the specified feature in Auxiliary Ctrl Register.
 *
 * \param   enableMask  Bit Mask for the features to be enabled. 
 *              Possible values are,
 *                  #CP15_CORTEX_A8_L2EN
 *
 * Note: Currently only the above value is used. If more configurations are 
 *       needed they can be added as needed.
 **/
void CP15AuxControlFeatureEnable(uint32_t enableMask);

/**
 * \brief   This API disables the specified feature in Auxiliary Ctrl Register.
 *
 * \param   disableMask  Bit Mask for the features to be disabled.
 *              Possible values are,
 *                  #CP15_CORTEX_A8_L2EN
 *
 * Note: Currently only the above value is used. If more configurations are 
 *       needed they can be added as needed.
 **/
void CP15AuxControlFeatureDisable(uint32_t disableMask);

/**
 * \brief   This API cleans the specified buffer from cache. 'Clean' here means
 *          to move the dirty (updated) contents from cache to next level of 
 *          memory (primary memory).
 *
 * \param   bufPtr  Start address of the buffer to be cleaned.
 * \param   size    Size of the buffer to be cleaned.
 **/
void CP15DCacheCleanBuff(uint32_t bufPtr, uint32_t size);

/**
 * \brief   This API cleans and invalidates (flush) the specified buffer from 
 *          cache.
 *          'Clean' here means to move the dirty (updated) contents from cache 
 *          to next level of memory (primary memory).
 *          'Invalidate' here means to mark the cache contents as invalid, so 
 *          that the next access to buffer fetches the contents from next level
 *          of memory (primary memory).
 *
 * \param   bufPtr  Start address of the buffer to be cleaned and invalidated.
 * \param   size    Size of the buffer to be cleaned and invalidated.
 **/
void CP15DCacheCleanFlushBuff(uint32_t bufPtr, uint32_t size);

/**
 * \brief   This API invalidates the specified buffer from data cache. 
 *          'Invalidate' here means to mark the cache contents as invalid, so 
 *          that the next access to buffer fetches the contents from next level
 *          of memory (primary memory).
 *
 * \param   bufPtr  Start address of the buffer to be invalidated.
 * \param   size    Size of the buffer to be invalidated.
 **/
void CP15DCacheFlushBuff(uint32_t bufPtr, uint32_t size);

/**
 * \brief   This API invalidates the specified buffer from instruction cache. 
 *          'Invalidate' here means to mark the cache contents as invalid, so 
 *          that the next access to buffer fetches the contents from next level
 *          of memory (primary memory).
 *
 * \param   bufPtr  Start address of the buffer to be invalidated.
 * \param   size    Size of the buffer to be invalidated.
 **/
void CP15ICacheFlushBuff(uint32_t bufPtr, uint32_t size);

/**
 * \brief   This API disables the instruction cache. It disables all levels of 
 *          cache (L1, L2)
 **/
void CP15ICacheDisable(void);

/**
 * \brief   This API disables the data cache. It disables all levels of 
 *          cache (L1, L2)
 **/
void CP15DCacheDisable(void);

/**
 * \brief   This API disables the instruction cache. It enables all levels of 
 *          cache (L1, L2)
 **/
void CP15ICacheEnable(void);

/**
 * \brief   This API disables the data cache. It enables all levels of 
 *          cache (L1, L2)
 **/
void CP15DCacheEnable(void);

/**
 * \brief   This API cleans and invalidates (flush) the complete data cache. 
 *          'Clean' here means to move the dirty (updated) contents from cache 
 *          to next level of memory (primary memory).
 *          'Invalidate' here means to mark the cache contents as invalid, so 
 *          that the next access to buffer fetches the contents from next level 
 *          of memory (primary memory).
 **/
void CP15DCacheCleanFlush(void);

/**
 * \brief   This API cleans the complete data cache. 
 *          'Clean' here means to move the dirty (updated) contents from cache 
 *          to next level of memory (primary memory).
 **/
void CP15DCacheClean(void);

/**
 * \brief   This API invalidates (flush) the complete data cache. 
 *          'Invalidate' here means to mark the cache contents as invalid, so 
 *          that the next access to buffer fetches the contents from next level 
 *          of memory (primary memory).
 **/
void CP15DCacheFlush(void);

/**
 * \brief   This API invalidates (flush) the complete instruction cache. 
 *          'Invalidate' here means to mark the cache contents as invalid, so 
 *          that the next access to buffer fetches the contents from next level 
 *          of memory (primary memory).
 **/
void CP15ICacheFlush(void);

/**
 * \brief   This API configures the translation table(page table) base address.
 *
 * \param   ttbAddr Translation table base address.
 **/
void CP15Ttb0Set(uint32_t ttbAddr);

/**
 * \brief   This API invalidates the translation look aside buffer.
 **/
void CP15TlbInvalidate(void);

/**
 * \brief   This API disables MMU.
 **/
void CP15MMUDisable(void);

/**
 * \brief   This API enables MMU.
 **/
void CP15MMUEnable(void);

/**
 * \brief   This API configures the interrupt vector table base address. It is 
 *          expected that the interrupt vectors are relocated to this base 
 *          address before calling this API.
 *
 * \param   vecTableBaseaddr  Vector table base address.
 **/
void CP15VectorBaseAddrSet(uint32_t vecTableBaseaddr);

/**
 * \brief   This API invalidates the Branch Target Buffer (BTB).
 **/
void CP15BranchPredictorInvalidate(void);

/**
 * \brief   This API enables the HW branch predictor.
 **/
void CP15BranchPredictionEnable(void);

/**
 * \brief   This API disables the HW branch predictor.
 **/
void CP15BranchPredictionDisable(void);

/**
 * \brief   This API configures domain access mode to 'client' (Accesses are 
 *          checked against the access permission bits in the TLB entry.).
 **/
void CP15DomainAccessClientSet(void);

/**
 * \brief   This API disables the different features in CP15 control register.
 *
 * \param   features   Mask of the features to be disabled.
 **/
void CP15ControlFeatureDisable(uint32_t features);

/**
 * \brief   This API enables the different features in CP15 control register.
 *
 * \param   features   Mask of the features to be enabled.
 **/
void CP15ControlFeatureEnable(uint32_t features);

/**
 * \brief   This API Configures the TTB control register to use only TTB0.
 **/
void CP15TtbCtlTtb0Config(void);

/**
 * \brief   This API returns the primary part number ARM core.
 *
 * \retval  Primary part number. possible values are,
 *            #CP15_PRIMARY_PART_CORTEX_A5
 *            #CP15_PRIMARY_PART_CORTEX_A7
 *            #CP15_PRIMARY_PART_CORTEX_A8
 *            #CP15_PRIMARY_PART_CORTEX_A9
 *            #CP15_PRIMARY_PART_CORTEX_A15
 *              
 **/
uint32_t CP15MainIdPrimPartNumGet(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CP15_H__ */
