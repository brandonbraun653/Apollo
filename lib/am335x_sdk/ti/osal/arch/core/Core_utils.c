/*
 * Copyright (c) 2019, Texas Instruments Incorporated
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
 *  ======== Core_utils.c ========
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ti/osal/osal.h>


#if defined(gnu_targets_arm_A15F)
#include <ti/csl/arch/a15/V0/csl_a15.h>
#endif

int32_t Osal_getCoreId(void)
{
#if defined(gnu_targets_arm_A15F)
    return ((int32_t)CSL_a15ReadCoreId());
#else
    return (osal_UNSUPPORTED);
#endif
}

void CacheP_fenceCpu2Dma(uintptr_t addr, uint32_t size, Osal_CacheP_isCoherent isCoherent)
{
    /* CPU to DMA would be to do Wb call if it is not coherent */
    if (isCoherent == OSAL_CACHEP_NOT_COHERENT)
    {
        CacheP_wb( (const void *) addr, size);
    }
}

void CacheP_fenceDma2Cpu(uintptr_t addr, uint32_t size, Osal_CacheP_isCoherent isCoherent)
{
    /* DMA to CPU would be to do Cache inv call if it is not coherent */
    if (isCoherent == OSAL_CACHEP_NOT_COHERENT)
    {
        CacheP_Inv( (const void *) addr, size);
    }
}
/* Nothing past this point */
