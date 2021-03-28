/**
 *   @file  EMAC_osal.h
 *
 *   @brief
 *      This is the sample OS Adaptation layer which is used by the EMAC
 *      driver. The OSAL layer can be ported in either of the following
 *      manners to a native OS:
 *
 *      <b> Approach 1: </b>
 *      @n  Use Prebuilt Libraries
 *           - Ensure that the provide an implementation of all
 *             Osal_XXX API for their native OS.
 *           - Link the prebuilt libraries with their application.
 *           - Refer to the "example" directory for an example of this
 *       @n <b> Pros: </b>
 *           - Customers can reuse prebuilt TI provided libraries
 *       @n <b> Cons: </b>
 *           - Level of indirection in the API to get to the actual OS call
 *
 *      <b> Approach 2: </b>
 *      @n  Rebuilt Library
 *           - Create a copy of this file and modify it to directly
 *             inline the native OS calls
 *           - Rebuild the EMAC Driver library; ensure that the Include
 *             path points to the directory where the copy of this file
 *             has been provided.
 *           - Please refer to the "test" directory for an example of this
 *       @n <b> Pros: </b>
 *           - Optimizations can be done to remove the level of indirection
 *       @n <b> Cons: </b>
 *           - EMAC Libraries need to be rebuilt by the customer.
 *
 */

/*
 * Copyright (C) 2014 - 2017 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef EMAC_OSAL_V5_H
#define EMAC_OSAL_V5_H

#ifdef __cplusplus
extern "C" {
#endif

/* include TI OSAL library interface header files */
#include <ti/osal/osal.h>
#include <ti/drv/emac/src/emac_osal.h>

#define Emac_osalPhysToVirt(x) (void *)((uintptr_t)x)
#define Emac_osalVirtToPhys(x) (physptr_t)(x)
static inline void *Emac_osalMallocAlign
(
    uint32_t region, 
    uint32_t size, 
    uint32_t align,
    uint32_t fWordAccess
)
{
   size += align;
   void *result = Osal_malloc(size);
   if (result) 
   {
       uintptr_t *aligned = (uintptr_t *)((uintptr_t)result & ~(align - 1));
       if ((uintptr_t)aligned == (uintptr_t)result)
       {
           aligned = (uintptr_t *)((uintptr_t)result + align);
       }
       *(aligned - 1) = (uintptr_t)result; /* save original result for free */
       result = (void *)aligned;
   }
   return result;
}

static inline void Emac_osalFreeAlign
(
    void *ptr,
    uint32_t size
)
{
    uintptr_t *aligned = (uintptr_t *)ptr;
    void *result = (void *)*(aligned - 1);
    Osal_free(result, size);
}

#if defined (__aarch64__)
typedef uint64_t physptr_t;
#else
typedef uint32_t physptr_t;
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif /* EMAC_OSAL_V5_H */
