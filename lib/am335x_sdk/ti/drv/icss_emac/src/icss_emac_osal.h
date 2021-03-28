/**
 *   @file  icss_emac_osal.h
 *
 *   @brief
 *      This is the sample OS Adaptation layer which is used by the ICSS_EMAC
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
 *           - Rebuild the ICSS_EMAC Driver library; ensure that the Include
 *             path points to the directory where the copy of this file
 *             has been provided.
 *           - Please refer to the "test" directory for an example of this
 *       @n <b> Pros: </b>
 *           - Optimizations can be done to remove the level of indirection
 *       @n <b> Cons: </b>
 *           - ICSS_EMAC Libraries need to be rebuilt by the customer.
 *
 */

/* Copyright (C) {2016} Texas Instruments Incorporated - http://www.ti.com/ 
*
*   Redistribution and use in source and binary forms, with or without 
*   modification, are permitted provided that the following conditions 
*   are met:
*
*     Redistributions of source code must retain the above copyright 
*     notice, this list of conditions and the following disclaimer.
*
*     Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the 
*     documentation and/or other materials provided with the   
*     distribution.
*
*     Neither the name of Texas Instruments Incorporated nor the names of
*     its contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

#ifndef ICSS_EMAC_OSAL__H
#define ICSS_EMAC_OSAL__H



#include <ti/osal/osal.h>

#ifdef __cplusplus
extern "C" {
#endif





#define ICSS_EMAC_osalCreateBlockingLock(x,y)	        (SemaphoreP_create((x),(y)))


#define ICSS_EMAC_osalDeleteBlockingLock(X)             (SemaphoreP_delete(X))


#define ICSS_EMAC_osalSemParamsInit(x)                  (SemaphoreP_Params_init(x))


#define ICSS_EMAC_osalPendLock(X,Y)                     (SemaphoreP_pend((X),(Y)))


#define ICSS_EMAC_osalPostLock(X)                       (SemaphoreP_post(X))


#define ICSS_EMAC_osalHardwareIntDisable()              (HwiP_disable())


#define ICSS_EMAC_osalHardwareIntRestore(X)             (HwiP_restore(X))


#define ICSS_EMAC_osalHardwareIntDestruct(X)            (HwiP_delete(X))


#define ICSS_EMAC_osalRegisterInterrupt(X,Y,Z)          (HwiP_create((X),(Y),(Z)))


#define ICSS_EMAC_osalHwiParamsInit(X)                  (HwiP_Params_init(X))

#define ICSS_EMAC_osalHardwareInterruptEnable(X)        (HwiP_enableInterrupt(X))

#define ICSS_EMAC_osalHardwareInterruptDisable(X)       (HwiP_disableInterrupt(X))

#define ICSS_EMAC_osalCacheInv(X,Y) CacheP_Inv(X, Y)

#define ICSS_EMAC_osalCacheWb(X,Y) CacheP_wb(X,Y)

#define ICSS_EMAC_osalTimerParamsInit(x)                (TimerP_Params_init(x))

#define ICSS_EMAC_osalTimerCreate(W, X,Y)               (TimerP_create((W), (X), (Y)))


#define ICSS_EMAC_osalTimerStart(x)                     (TimerP_start(x))

#define ICSS_EMAC_osalMuxIntcSetup(X, Y)         (MuxIntcP_create((X), (Y)))

#define ICSS_EMAC_osalMuxIntcEnableSysInt(X, Y)  (MuxIntcP_enableInEvent((X), (Y)))


#define ICSS_EMAC_osalMuxIntcDisableSysInt(X, Y) (MuxIntcP_disableInEvent((X), (Y)))


#define ICSS_EMAC_osalMuxIntcClearSysInt(X, Y)   (MuxIntcP_clearInEvent((X), (Y)))


#ifdef __cplusplus
}
#endif

#endif /* __ICSS_EMAC_OSAL_H__ */


