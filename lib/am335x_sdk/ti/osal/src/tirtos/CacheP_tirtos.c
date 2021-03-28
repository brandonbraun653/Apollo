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

#include <ti/osal/CacheP.h>
#include <ti/sysbios/BIOS.h>
#if defined (_TMS320C6X) && !(defined (SOC_OMAPL137) || defined (SOC_OMAPL138))
#include <ti/sysbios/family/c66/Cache.h>
#elif defined (__TI_ARM_V7M4__)
#include <ti/sysbios/hal/unicache/Cache.h>
#else
#include <ti/sysbios/hal/Cache.h>
#endif


void CacheP_wb(const void * addr, int32_t size)
{

   Cache_wb((Ptr)addr, (SizeT)size, (Bits16)Cache_Type_ALL, (Bool)TRUE);
}
void CacheP_wbInv(const void * addr, int32_t size)
{
   Cache_wbInv((Ptr)addr, (SizeT)size, (Bits16)Cache_Type_ALL, (Bool)TRUE);
}

void CacheP_Inv(const void * addr, int32_t size)
{
  Cache_inv((Ptr)addr, (SizeT)size, (Bits16)Cache_Type_ALL, (Bool)TRUE);
}
/* Nothing past this point */
