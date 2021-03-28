/**
 *   @file  usb_osal.h
 *
 *   @brief
 *      This is the sample OS Adaptation layer which is used by the usb
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
 *           - Rebuild the usb Driver library; ensure that the Include
 *             path points to the directory where the copy of this file
 *             has been provided.
 *           - Please refer to the "test" directory for an example of this
 *       @n <b> Pros: </b>
 *           - Optimizations can be done to remove the level of indirection
 *       @n <b> Cons: </b>
 *           - usb Libraries need to be rebuilt by the customer.
 *
 *  \par
 *  NOTE:
 *      (C) Copyright 2014-2018 Texas Instruments, Inc.
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
#ifndef PDK__USB_OSAL_H
#define PDK__USB_OSAL_H

#include <ti/osal/osal.h>

#ifdef __cplusplus
extern "C" {
#endif

/* semaphore functions */
#define usb_osalCreateBlockingLock(x,y)         SemaphoreP_create(x,y)
#define usb_osalDeleteBlockingLock(X)           SemaphoreP_delete(X)
#define usb_osalSemParamsInit(x)                SemaphoreP_Params_init(x)
#define usb_osalPendLock(X,Y)                   SemaphoreP_pend(X,Y)
#define usb_osalPostLock(X)                     SemaphoreP_post(X)

/* #define usb_osalHardwareIntDisable()            HwiP_disable() */
/* #define usb_osalHardwareIntRestore(X)           HwiP_restore(X) */
#define usb_osalHardwareIntDestruct(X)          HwiP_delete(X)
#define usb_osalRegisterInterrupt(X,Y,Z)        HwiP_create(X,Y,Z)

#if 0
#define usb_osalDisableInterruptNum(intNum)     HwiP_disableInterrupt(intNum)
#define usb_osalEnableInterruptNum(intNum)      HwiP_enableInterrupt(intNum)
#endif

#define usb_osalHwiParamsInit(X)                HwiP_Params_init(X)

/* cache functions */
#define usb_osalCacheInvalidate(addr, size)     CacheP_Inv(addr, size)
#define usb_osalCacheWb(addr, size)             CacheP_wb(addr, size)
#define usb_osalCacheWbInv(addr, size)          CacheP_wbInv(addr, size)

/* extern these osal functions for easier function replacement at 
   user application without recompiling the LLD driver */
extern uint32_t usb_osalHardwareIntDisable(void);
extern void     usb_osalHardwareIntRestore(uint32_t);
extern void     usb_osalDisableInterruptNum(uint32_t);
extern void     usb_osalEnableInterruptNum(uint32_t);

extern void     usb_osalDelayMs(uint32_t);
extern void     usb_osalStartTimerMs(uint32_t);
extern void     usb_osalStopTimer();
extern uint32_t usb_osalIsTimerExpired();
extern void usb_osalClearInterrupt(uint32_t);


/* wrappers to API of the performance monitor unit */
extern void usb_osalInitPerfUnit(void);
extern void usb_osalStartPerfCounter(void);
extern void usb_osalStopPerfCounter(void);
extern void usb_osalClearPerfCounter(void);
extern uint64_t usb_osalGetPerfCounter(void);

#ifdef __cplusplus
}
#endif

#endif /* PDK__USB_OSAL_H */


