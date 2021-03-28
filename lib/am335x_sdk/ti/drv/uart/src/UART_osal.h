/**
 *   @file  UART_osal.h
 *
 *   @brief
 *      This is the sample OS Adaptation layer which is used by the UART
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
 *           - Rebuild the UART Driver library; ensure that the Include
 *             path points to the directory where the copy of this file
 *             has been provided.
 *           - Please refer to the "test" directory for an example of this
 *       @n <b> Pros: </b>
 *           - Optimizations can be done to remove the level of indirection
 *       @n <b> Cons: </b>
 *           - UART Libraries need to be rebuilt by the customer.
 *
 *  \par
 *  NOTE:
 *      (C) Copyright 2014-2015 Texas Instruments, Inc.
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
#ifndef UART_OSAL_H
#define UART_OSAL_H

#include <ti/osal/osal.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UART_osalCreateBlockingLock(x,y)        (SemaphoreP_create((x),(y)))


#define UART_osalDeleteBlockingLock(X)       (SemaphoreP_delete(X))


#define UART_osalSemParamsInit(x)  (SemaphoreP_Params_init(x))


#define UART_osalPendLock(X,Y)         (SemaphoreP_pend((X),(Y)))


#define UART_osalPostLock(X)     (SemaphoreP_post(X))


#define UART_osalHardwareIntDisable() (HwiP_disable())


#define UART_osalHardwareIntRestore(X) (HwiP_restore(X))


#define UART_osalHardwareIntDestruct(X,Y)     (Osal_DeleteInterrupt((X),(Y)))

#define UART_osalRegisterInterrupt(X,Y)     (Osal_RegisterInterrupt((X),(Y)))

#define UART_osalHwiParamsInit(X)            (HwiP_Params_init(X))


#define UART_osalHardwareIntrDisable(X,Y)    (Osal_DisableInterrupt((X),(Y)))

#define UART_osalHardwareIntrEnable(X,Y)     (Osal_EnableInterrupt((X),(Y)))

#define UART_osalHardwareIntrClear(X,Y)      (Osal_ClearInterrupt((X),(Y)))


#define UART_osalMuxIntcSetup(X, Y)         (MuxIntcP_create((X), (Y)))


#define UART_osalMuxIntcEnableSysInt(X, Y)  (MuxIntcP_enableInEvent((X), (Y)))


#define UART_osalMuxIntcDisableSysInt(X, Y) (MuxIntcP_disableInEvent((X), (Y)))


#define UART_osalMuxIntcClearSysInt(X, Y)   (MuxIntcP_clearInEvent((X), (Y)))

#define UART_osalGetThreadType()            (Osal_getThreadType())

#define UART_osalDelay(X)                   (Osal_delay(X))


#ifdef __cplusplus
}
#endif

#endif /* __UART_OSAL_H__ */


