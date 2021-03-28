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

/**
 *  \ingroup DRV_OSAL_MODULE
 *  \defgroup DRV_OSAL_CacheP CacheP
 *            CacheP interface
 *
 *  @{
 */ 
 
/** ============================================================================
 *  @file       CacheP.h
 *
 *  @brief      Cache Handling routines for the RTOS Porting Interface
 *
 *
 *  ============================================================================
 */

#ifndef ti_osal_CacheP__include
#define ti_osal_CacheP__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/** 
 * @brief This enumerator defines the cache coherent or not
 *
 * 
 */
typedef uint32_t Osal_CacheP_isCoherent;
    /** Cache is coherent on this CPU */
#define OSAL_CACHEP_COHERENT                            ((uint32_t) 0U)
    /**Cache is not coherent on this CPU */
#define OSAL_CACHEP_NOT_COHERENT                        ((uint32_t) 1U)

/*!
 *  @brief  Function to write back cache lines
 *
 *  @param  addr  Start address of the cache line/s
 *
 *  @param  size  size (in bytes) of the memory to be written back
 *
 */
extern void CacheP_wb(const void * addr, int32_t size);


/*!
 *  @brief  Function to invalidate cache lines
 *
 *  @param  addr  Start address of the cache line/s
 *
 *  @param  size  size (in bytes) of the memory to invalidate
 *
 */
extern void CacheP_Inv(const void * addr, int32_t size);


/*!
 *  @brief  Function to write back and invalidate cache lines
 *
 *  @param  addr  Start address of the cache line/s
 *
 *  @param  size  size (in bytes) of the memory to be written back and invalidate
 *
 */
extern void CacheP_wbInv(const void * addr, int32_t size);

/*!
 *  @brief  Function to call before handing over the memory buffer to DMA from CPU
 *
 *  @param  addr  Start address of the cache line/s
 *
 *  @param  size  size (in bytes) of the memory to be written back and invalidate
 *
 *  @param  isCoherent  if the cache is coherent on that CPU or not
 *
 */
void CacheP_fenceCpu2Dma(uintptr_t addr, uint32_t size, Osal_CacheP_isCoherent isCoherent);

/*!
 *  @brief  Function to call before reading the memory to CPU after DMA operations 
 *
 *  @param  addr  Start address of the cache line/s
 *
 *  @param  size  size (in bytes) of the memory to be written back and invalidate
 *
 *  @param  isCoherent  if the cache is coherent on that CPU or not @ref Osal_CacheP_isCoherent
 *
 */
void CacheP_fenceDma2Cpu(uintptr_t addr, uint32_t size, Osal_CacheP_isCoherent isCoherent);

#ifdef __cplusplus
}
#endif

#endif /* ti_osal_CacheP__include */
/* @} */
