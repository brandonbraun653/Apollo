/**
 * @file   osdrv_ndkdeviceconfig.h
 *
 * @brief 
 *
*/
/*
 * Copyright (C) 2013 - 2019 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef _OSDRV_NDKDEVICECONFIG_H
#define _OSDRV_NDKDEVICECONFIG_H
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <xdc/std.h>
#include <ti/ndk/inc/stkmain.h>
#include <ti/ndk/inc/netmain.h>
#include "ti/drv/icss_emac/icss_emacDrv.h"
#include "ti/drv/pruss/pruicss.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define MAX_ICSSNIMU_TBL_ENTRIES   3

typedef int (*NIMUInitFn) (STKEVENT_Handle hEvent) ;

typedef void*       NimuHandle;
typedef void*       HANDLE;

//#define info_printf(...) DbgPrintf(0, __VA_ARGS__) /* level 1 = DBG_INFO */
/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */



/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */



/**
 * Desc
 * 		 This API adds initialization function to NDK device table,
 * 		  that will be executed by NDK on startup. This needs to be called before BIOS_Start
 * Params
 * 		 CPSW_NETIF_INIT - To initiate CPSW driver
 * 		 ICSS_NETIF_INIT - To initiate ICSS Netif driver
 * Return
 * 		0 - Failure
 * 		1 - Success
 *
 */
int32_t OSDRV_addNetifEntry(NIMUInitFn initFct, HANDLE emacHandle);

HANDLE OSDRV_getNetifHandle(uint32_t inst);

#ifdef __cplusplus
}
#endif

#endif  //_OSDRV_NDKDEVICECONFIG_H

