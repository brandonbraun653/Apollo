/*
 * Copyright (c) 2015-2018, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== HwiP_tirtos.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include <ti/osal/CacheP.h>
#include <ti/osal/src/nonos/Nonos_config.h>

static uint32_t CacheP_getCacheSize(void);

static uint32_t CacheP_getCacheSize(void)
{
    uint32_t  cacheLineSize;

    cacheLineSize  = CSL_a53v8GetCurrentCacheSize();
    /* Indicates the (log2 (number of words in cache line)) - 2 */
    cacheLineSize &= (uint32_t) 7U;
    cacheLineSize += 2U;
    /* Now get the actual size by left shift operation */
    cacheLineSize = ((uint32_t)1U << cacheLineSize);
    return (cacheLineSize);
}


void CacheP_wb(const void * addr, int32_t size)
{
   uintptr_t i, firstAddr, lastAddr;
   uint32_t cacheLineSize = CacheP_getCacheSize();

   /* Calculate the last address */
   lastAddr = (uintptr_t) addr + (uint32_t)size;

   /* find the first address for cache Wb */
   firstAddr = (uintptr_t ) addr & ~(cacheLineSize -1U);

   for (i = firstAddr; i < lastAddr; i+=cacheLineSize)
   {
      /* clean single entry in DCache to PoC */
       CSL_a53v8CleanDcacheMvaPoC(i);
   }

   return;
}
void CacheP_wbInv(const void * addr, int32_t size)
{
    uintptr_t i, firstAddr, lastAddr;
    uint32_t cacheLineSize = CacheP_getCacheSize();
    
    /* Calculate the last address */
    lastAddr = (uintptr_t) addr + (uint32_t)size;
    
    /* find the first address for cache Wb */
    firstAddr = (uintptr_t ) addr & ~(cacheLineSize -1U);
    
    for (i = firstAddr; i < lastAddr; i+=cacheLineSize)
    {
        /* clean and invalidate single entry in DCache to PoC */
        CSL_a53v8CleanInvalidateDcacheMvaPoC(i);
    }
    
    return;

}
void CacheP_Inv(const void * addr, int32_t size)
{
    uintptr_t i, firstAddr, lastAddr;
    uint32_t cacheLineSize = CacheP_getCacheSize();
    
    /* Calculate the last address */
    lastAddr = (uintptr_t) addr + (uint32_t)size;
    
    /* find the first address for cache Wb */
    firstAddr = (uintptr_t ) addr & ~(cacheLineSize -1U);
    
    for (i = firstAddr; i < lastAddr; i+=cacheLineSize)
    {
        /* invalidate single entry in DCache */
        CSL_a53v8InvalidateDcacheMvaPoC(i);
    }
    return;
}

/* Nothing past this point */
