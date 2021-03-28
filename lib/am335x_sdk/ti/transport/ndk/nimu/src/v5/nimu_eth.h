/*
 * nimu_eth.h
 *
 * Copyright (C) 2011-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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
 *   @file  nimu_eth.h
 *
 *   @brief
 *      This file defines the interface applications can use when
 *      integrating the Network Interface Module Ethernet driver adaptation layer
 *
 */

#ifndef _NIMU_ETH_H
#define _NIMU_ETH_H  /* #defined if this .h file has been included */

#include <ti/drv/qmss/qmss_qm.h>
#include <ti/drv/cppi/cppi_drv.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NIMU Library Version */
#define NIMU_LIB_VERSION "3.00.00.01"


extern void Osal_TaskCreate(void*);
extern void Osal_TaskSleep(uint32_t sleepTime);


extern Ptr Osal_nimuMalloc (uint32_t num_bytes, uint32_t alignment);
extern void Osal_nimuFree (Ptr dataPtr, uint32_t num_bytes);

extern Ptr Osal_cppiCsEnter (void);
extern void Osal_cppiCsExit (Ptr CsHandle);


extern Qmss_QueueHnd NIMU_qmssGetFreeQ (void);

extern Cppi_Handle NIMU_cppiGetPASSHandle (void);

extern void NIMU_qmssQPushDescSize (Qmss_QueueHnd handler,void *descAddr, uint32_t descSize);

extern void Osal_enterSingleCoreCriticalSection(Uint32      port_num);

extern void Osal_exitSingleCoreCriticalSection(Uint32      port_num);

#ifdef __cplusplus
}
#endif

#endif
