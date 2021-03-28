/*
 * Copyright (C) 2010-2017 Texas Instruments Incorporated - http://www.ti.com/ 
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
 *   @file  test_osal.c
 *
 *   @brief
 *      This is the OS abstraction layer and is used by the EMAC
 *      driver for the EMAC Unit Test Application.
 */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Hwi.h>
#include <xdc/cfg/global.h>

/* CSL Include Files */

#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_cache.h>
#include <ti/csl/csl_cacheAux.h>

#include <ti/drv/emac/emac_hwcfg.h>
#include <ti/drv/emac/emac_drv.h>
#include "test_loc.h"
#include <ti/osal/CacheP.h>
 /**
 *  @b Description
 *  @n
 *      The function is used to indicate that a block of memory is
 *      about to be accessed. If the memory block is cached then this
 *      indicates that the application would need to ensure that the
 *      cache is updated with the data from the actual memory.
 *
 *  @param[in]  addr
 *       Address of memory block
 *  @param[in]  size
 *       Size of memory block in bytes
 *
 *  @retval
 *      None
 */
void Osal_beginMemAccess
(
    void*   addr,
    Uint32  size
)
{
    /* Invalidate the cache for external memory addess */
    if( ((Uint32)(addr) & APP_EXTMEM) |  ((Uint32)(addr) & APP_MSMCMEM) )
    {
#ifdef _TMS320C6X
        CACHE_invL2 (addr, size, CACHE_WAIT);
#else
        CacheP_Inv (addr, size);
#endif
    }
}

/**
 *  @b Description
 *  @n
 *      The function is used to indicate that the block of memory has
 *      finished being accessed. If the memory block is cached then the
 *      application would need to ensure that the contents of the cache
 *      are updated immediately to the actual memory.
 *
 *  @param[in]  addr
 *       Address of memory block
 *  @param[in]  size
 *       Size of memory block in bytes
 *
 *  @retval
 *      None
 */
void
Osal_endMemAccess
(
    void*   addr,
    Uint32  size
)
{
    /* Write back the cache to external memory */
    if( ((Uint32)(addr) & APP_EXTMEM) |  ((Uint32)(addr) & APP_MSMCMEM))
    {
#ifdef _TMS320C6X
        CACHE_wbL2 (addr, size, CACHE_WAIT);
#else
        CacheP_wb (addr, size);
#endif
    }
}

/**
 *  @b Description
 *  @n
 *      The function is used to provide critical section to prevent access of shared
 *      resources from single core and multiple threads.
 *
 *  @param[in]  port_num
 *      EMAC port number which needs critical section to protect its resources.
 *
 *  @retval
 *      None
 */
void
Osal_enterSingleCoreCriticalSection
(
    Uint32      port_num
)
{
#ifdef _TMS320C6X
    if (port_num == 0)
    {
        IER &= ~APP_EMAC0_INT_FLAG;
    }
#endif
#ifdef TWO_PORT_DEV
    else
    {
        IER &= ~APP_EMAC1_INT_FLAG;
    }
#endif
}

/**
 *  @b Description
 *  @n
 *      The function is called to end the critical section access of shared resources
 *      from single cores.
 *
 *  @param[in]  port_num
 *      EMAC port number which needs critical section to protect its resources.
 *
 *  @retval
 *      None
 */
void
Osal_exitSingleCoreCriticalSection
(
    Uint32      port_num
)
{
#ifdef _TMS320C6X
    if (port_num == 0)
    {
        IER |= APP_EMAC0_INT_FLAG;
    }
#endif
#ifdef TWO_PORT_DEV
    else
    {
        IER |= APP_EMAC1_INT_FLAG;
    }
#endif    
}

/**
 *  @b Description
 *  @n
 *      The function is used to provide critical section to prevent access of shared
 *      resources from multiple cores
 *
 *  @retval
 *      None
 */
void
Osal_enterMultipleCoreCriticalSection
(
    Uint32      port_num
)
{
    (void)port_num;
    return;
}

/**
 *  @b Description
 *  @n
 *      The function is called to end the critical section access of shared resources
 *      from multiple cores.
 *
 *  @param[in]
 *
 *  @retval
 *      None
 */
void
Osal_exitMultipleCoreCriticalSection
(
    Uint32      port_num
)
{
    (void)port_num;
    return;
}

/**
 *  @b Description
 *  @n
 *      The function is used to allocate a memory block of the specified size.
 *
 *  @param[in]  num_bytes
 *      Number of bytes to be allocated.
 *
 *  @retval
 *      Allocated block address
 */
void* Osal_malloc
(
    Uint32  num_bytes
)
{
    Error_Block     errorBlock;
    Void*           ptr;

    /* Allocate memory */
    ptr = Memory_alloc(NULL, num_bytes, 4, &errorBlock);
    if (ptr == NULL)
    {
        return NULL;
    }

    /* Return the allocated memory block. */
    return ptr;
}

/**
 *  @b Description
 *  @n
 *      The function is used to clean up a specific memory block
 *
 *  @param[in]  ptr
 *      Pointer to the memory block to be cleaned up.
 *  @param[in]  num_bytes
 *      Size of the memory block being cleaned up.
 *
 *  @retval
 *      Not Applicable
 */
void
Osal_free
(
    void*       ptr,
    Uint32      num_bytes
)
{
    Memory_free(NULL, ptr, num_bytes);
}
