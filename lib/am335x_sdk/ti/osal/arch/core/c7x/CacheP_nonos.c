/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
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

void CacheP_wb(const void * addr, int32_t size)
{
  //TODO: Integrate to CSL once C7x arch is supported
  //uint32_t alignedAddr = (uint32_t)addr & ~((uint32_t)0x3u);
  //uint32_t alignedSize =   (uint32_t)size + (uint32_t)addr - (uint32_t)alignedAddr;
  //uint32_t block_addr=alignedAddr;
  //int32_t size_remaining=alignedSize;
  //uint32_t bytes_count;
  //
  //while(size_remaining > 0) {
  //  bytes_count = (size_remaining > CACHE_L2_LINESIZE )? CACHE_L2_LINESIZE:size_remaining;
//	CACHE_wbL2((void *)block_addr,bytes_count,CACHE_WAIT);
//	size_remaining-=CACHE_L2_LINESIZE;
//	block_addr+=CACHE_L2_LINESIZE;
  //}
}

void CacheP_wbInv(const void * addr, int32_t size)
{
  //TODO: Integrate to CSL once C7x arch is supported
  //uint32_t alignedAddr = (uint32_t)addr & ~((uint32_t)0x3u);
  //uint32_t alignedSize =   (uint32_t)size + (uint32_t)addr - (uint32_t)alignedAddr;
  //uint32_t block_addr=alignedAddr;
  //int32_t size_remaining=alignedSize;
  //uint32_t bytes_count;
  //
  //while(size_remaining > 0) {
  //  bytes_count = (size_remaining > CACHE_L2_LINESIZE )? CACHE_L2_LINESIZE:size_remaining;
//	CACHE_wbInvL2((void *)block_addr,bytes_count,CACHE_WAIT);
//	size_remaining-=CACHE_L2_LINESIZE;
//	block_addr+=CACHE_L2_LINESIZE;
  //}
}

void CacheP_Inv(const void * addr, int32_t size)
{
  //TODO: Integrate to CSL once C7x arch is supported
  //uint32_t alignedAddr = (uint32_t)addr & ~((uint32_t)0x3u);
  //uint32_t alignedSize =   (uint32_t)size + (uint32_t)addr - (uint32_t)alignedAddr;
  //uint32_t block_addr=alignedAddr;
  //int32_t size_remaining=alignedSize;
  //uint32_t bytes_count;
  //
  //while(size_remaining > 0) {
  //  bytes_count = (size_remaining > CACHE_L2_LINESIZE )? CACHE_L2_LINESIZE:size_remaining;
  //  CACHE_invL2((void *)block_addr,bytes_count,CACHE_WAIT);
  //  size_remaining-=CACHE_L2_LINESIZE;
  //  block_addr+=CACHE_L2_LINESIZE;
  //}
}


