/**
 *   @file  pruicss_osal.h
 *
 *   @brief
 *      This is the sample OS Adaptation layer which is used by the PRUICSS
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
 *           - Rebuild the PRUICSS Driver library; ensure that the Include
 *             path points to the directory where the copy of this file
 *             has been provided.
 *           - Please refer to the "test" directory for an example of this
 *       @n <b> Pros: </b>
 *           - Optimizations can be done to remove the level of indirection
 *       @n <b> Cons: </b>
 *           - PRUICSS Libraries need to be rebuilt by the customer.
 *
 *  \par
 *  NOTE:
 *      (C) Copyright 2015 Texas Instruments, Inc.
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
 *  \par
*/
#ifndef PRUICSS_OSAL_H
#define PRUICSS_OSAL_H

#include <ti/osal/osal.h>

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************
 ************************* Extern Declarations ************************
 **********************************************************************/

/* #include <string.h> is here because there used to be
 * memcpy/memset prototypes here.  This #include prevents warnings in
 * other code that unintentionally worked because of these prototypes
 */
#include <string.h>


#define PRUICSS_osalCreateBlockingLock(x,y)        (SemaphoreP_create((x),(y)))


#define PRUICSS_osalDeleteBlockingLock(X)       (SemaphoreP_delete(X))


#define PRUICSS_osalSemParamsInit(x)  (SemaphoreP_Params_init(x))


#define PRUICSS_osalPendLock(X,Y)         (SemaphoreP_pend((X),(Y)))


#define PRUICSS_osalPostLock(X)     (SemaphoreP_post(X))


#define PRUICSS_osalHardwareIntDisable() (HwiP_disable())


#define PRUICSS_osalHardwareIntRestore(X) (HwiP_restore(X))


#define PRUICSS_osalHardwareIntDestruct(X)  (HwiP_delete(X))


#define PRUICSS_osalRegisterInterrupt(X,Y,Z)     (HwiP_create((X),(Y),(Z)))


#define PRUICSS_osalHwiParamsInit(X)             (HwiP_Params_init(X))

#define PRUICSS_osalMuxIntcSetup(X, Y)         (MuxIntcP_create((X), (Y)))


#define PRUICSS_osalMuxIntcEnableSysInt(X, Y)  (MuxIntcP_enableInEvent((X), (Y)))


#define PRUICSS_osalMuxIntcDisableSysInt(X, Y) (MuxIntcP_disableInEvent((X), (Y)))


#define PRUICSS_osalMuxIntcClearSysInt(X, Y)   (MuxIntcP_clearInEvent((X), (Y)))


#define PRUICSS_WAIT_FOREVER (~((uint32_t)0U))

#ifdef __cplusplus
}
#endif

#endif /* __PRUICSS_OSAL_H__ */


