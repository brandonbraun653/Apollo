/*
 *  Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file  csl_cache.h
 *
 *  \brief NON-OS Cache Handling routines
 *
 */

#ifndef CSL_CACHE_H_
#define CSL_CACHE_H_


#include <ti/csl/csl_types.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * \brief   Function to write back cache lines
 *
 * \param   addr  Start address of the cache line/s
 * \param  size  size (in bytes) of the memory to be written back
 *
 * \return  None
 *
 **/
extern void CSL_armR5CacheWb(const void * addr, int32_t size);

/**
 * \brief   Function to write back and invalidate cache lines
 *
 * \param   addr  Start address of the cache line/s
 * \param  size  size (in bytes) of the memory to be written back and invalidated
 *
 * \return  None
 *
 **/
extern void CSL_armR5CacheWbInv(const void * addr, int32_t size);

/**
 * \brief   Function to invalidate cache lines
 *
 * \param   addr  Start address of the cache line/s
 * \param  size  size (in bytes) of the memory to be invalidated
 *
 * \return  None
 *
 **/
 extern void CSL_armR5CacheInv(const void * addr, int32_t size);

#ifdef __cplusplus
}
#endif
#endif
