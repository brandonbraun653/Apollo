/*
 *  Copyright (C) 2018 Texas Instruments Incorporated.
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
#include <ti/csl/arch/csl_arch.h>

#define CONTEXT_GU (0x0)
#define CONTEXT_GS (0x1)
#define CONTEXT_U  (0x2)
#define CONTEXT_S  (0x3)
#define CONTEXT_SU (0x4)
#define CONTEXT_SS (0x5)

/**
 * @brief Helper functions which enable MMU HW mode in SS, GS and S modes
 */
void CSL_c7xMmuHwModeEnable(void);
void CSL_c7xMmuHwModeEnableGS(void);
void CSL_c7xMmuHwModeEnableS(void);
/**
 * @brief Helper functions which indicate if MMU HW mode is enabled in SS, GS
 *  and S modes
 */
uint64_t CSL_c7xMmuIsHwModeEnabled(void);
uint64_t CSL_c7xMmuIsHwModeEnabledGS(void);
uint64_t CSL_c7xMmuIsHwModeEnabledS(void);

void CSL_c7xSetL1DCacheSize(uint64_t l1dmod)
{
    volatile uint64_t       value;
    value = CSL_c7xGetL1DCFG() & ~CSL_DMC_L1DCFG_L1DMODE_MASK;
    value |= (l1dmod << CSL_DMC_L1DCFG_L1DMODE_SHIFT) & CSL_DMC_L1DCFG_L1DMODE_MASK;
    CSL_c7xSetL1DCFG(value);
    return;
}

void CSL_c7xSetL2CacheSize(uint64_t l2mod)
{
    volatile uint64_t   size;
    size  = CSL_c7xGetL2CFG() & ~CSL_UMC_L2CFG_L2MODE_MASK;
    size |= (l2mod << CSL_UMC_L2CFG_L2MODE_SHIFT) & CSL_UMC_L2CFG_L2MODE_MASK;
    CSL_c7xSetL2CFG(size);
    return;
}

void CSL_c7xInvalidateL1PCache()
{
    CSL_c7xL1PCacheInvalidateAll();
    return;
}

void CSL_c7xInvalidateL1DCache()
{
    volatile uint64_t       wbinv;
    wbinv  = CSL_c7xGetL1DINV() & ~CSL_DMC_L1DINV_INV_MASK;
    wbinv |= (0x1U << CSL_DMC_L1DINV_INV_SHIFT) & CSL_DMC_L1DINV_INV_MASK;
    CSL_c7xSetL1DINV(wbinv);
    return;
}

void CSL_c7xInvalidateL2Cache()
{
    volatile uint64_t       wbinv;
    wbinv = CSL_c7xGetL2INV() & ~CSL_UMC_L2INV_INV_MASK;
    wbinv |= (0x1U << CSL_UMC_L2INV_INV_SHIFT) & CSL_UMC_L2INV_INV_MASK;
    CSL_c7xSetL2INV(wbinv);
    return;
}

void CSL_c7xCleaninvalidateL1DCache()
{
    volatile uint64_t       wbinv;
    wbinv  = CSL_c7xGetL1DWBINV() & ~CSL_DMC_L1DWBINV_WBINV_MASK;
    wbinv |= (0x1U << CSL_DMC_L1DWBINV_WBINV_SHIFT) & CSL_DMC_L1DWBINV_WBINV_MASK;
    CSL_c7xSetL1DWBINV(wbinv);
    return;
}

void CSL_c7xCleaninvalidateL2Cache()
{
    volatile uint64_t       wbinv;
    wbinv = CSL_c7xGetL2WBINV() & ~CSL_UMC_L2WBINV_WBINV_MASK;
    wbinv |= (0x1U << CSL_UMC_L2WBINV_WBINV_SHIFT) & CSL_UMC_L2WBINV_WBINV_MASK;
    CSL_c7xSetL2WBINV(wbinv);
    return;
}

void CSL_c7xMMUEnable()
{
   uint64_t cpuMode;

   cpuMode = CSL_c7xGetCpuMode();
   if (cpuMode == CONTEXT_SS) CSL_c7xMmuHwModeEnable();
   if (cpuMode == CONTEXT_GS) CSL_c7xMmuHwModeEnableGS();
   if (cpuMode == CONTEXT_S ) CSL_c7xMmuHwModeEnableS();
}

uint64_t CSL_c7xMMUIsEnabled()
{
   uint64_t cpuMode;

   cpuMode = CSL_c7xGetCpuMode();
   if      (cpuMode == CONTEXT_SS) return CSL_c7xMmuIsHwModeEnabled();
   else if (cpuMode == CONTEXT_GS) return CSL_c7xMmuIsHwModeEnabledGS();
   else if (cpuMode == CONTEXT_S ) return CSL_c7xMmuIsHwModeEnabledS();
   else return CSL_c7xMmuIsHwModeEnabled();
}

void CSL_c7xMMUSetMAIR(uint64_t param)
{
  CSL_c7xSetMAR(param);
}

void CSL_c7xCacheInvalidateAll(uint8_t cache_type)
{
  switch (cache_type) {
    case C7X_CACHE_TYPE_L1D :
      CSL_c7xInvalidateL1DCache();
      break;
    case C7X_CACHE_TYPE_L1P :
      CSL_c7xInvalidateL1PCache();
      break;
    case C7X_CACHE_TYPE_L2 :
      CSL_c7xInvalidateL2Cache();
      break;
    default :
      break;
  }
}

void CSL_c7xCacheWriteBackInvalidateAll(uint8_t cache_type)
{
  switch (cache_type) {
    case C7X_CACHE_TYPE_L1D :
      CSL_c7xCleaninvalidateL1DCache();
      break;
    case C7X_CACHE_TYPE_L2 :
      CSL_c7xCleaninvalidateL2Cache();
      break;
    default :
      break;
  }
}

void CSL_c7xSetCacheSize(uint8_t cache_type, uint8_t cache_size)
{
  switch (cache_type) {
    case C7X_CACHE_TYPE_L1D :
      CSL_c7xSetL1DCacheSize(cache_size);
      break;
    case C7X_CACHE_TYPE_L2 :
      CSL_c7xSetL2CacheSize(cache_size);
      break;
    default :
      break;
  }
}
// NOTE: The scope of the CMO functions in the c7x have been limited to the
//       following two functions:
// DCCIC - Data Cache Clean and Invalidate to Point of Coherence
// DCCMIC - Data Cache Invalidate to Point of Coherence
void CSL_c7xCacheWriteBackInvalidateBlock(uint64_t startAddr, uint64_t numBytes)
{
  __se_cache_op((void *) startAddr, __DCCICNS, numBytes);
}

void CSL_c7xCacheInvalidateBlock(uint64_t startAddr, uint64_t numBytes)
{
  __se_cache_op((void *) startAddr, __DCICNS, numBytes);
}

void CSL_c7xMMUInit(uint64_t tcr, uint64_t ttbr, uint64_t mar, uint64_t scr)
{
  CSL_c7xSetTCR0(tcr);
  CSL_c7xSetTBR0(ttbr);
  CSL_c7xSetMAR (mar);
  CSL_c7xSetSCR (scr);
}
