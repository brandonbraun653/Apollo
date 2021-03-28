#ifndef TI_TRANSPORT_TIMESYNC_EXAMPLE_H
#define TI_TRANSPORT_TIMESYNC_EXAMPLE_H

/******************************************************************************
 * FILE PURPOSE: Definitions and prototypes for TimeSync Example.
 ******************************************************************************
 * FILE NAME:   example.h
 *
 * DESCRIPTION: Contains definitions and function prototypes for TimeSync
 *              Example.
 *
 * (C) Copyright 2018 Texas Instruments, Inc.
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
/* Standard includes */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* XDC Includes */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>

/* Sys Bios Includes */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/gates/GateHwi.h>
#include <ti/sysbios/hal/Core.h>
#if defined (SOC_AM335x) 
#include <ti/sysbios/family/arm/a8/Cache.h>
#elif defined (SOC_AM437x)
#include <ti/sysbios/family/arm/a9/Cache.h>
#elif defined (__ARM_ARCH_7A__)
#include <ti/sysbios/family/arm/a15/Cache.h>
#elif defined (__TI_ARM_V7M4__)
#include <ti/sysbios/hal/unicache/Cache.h>
#elif defined (__TI_ARM_V5__)  
#include <ti/sysbios/family/arm/arm9/Cache.h>
#elif defined (_TMS320C6X) && !(defined (SOC_OMAPL137) || defined (SOC_OMAPL138))
#include <ti/sysbios/family/c66/Cache.h>
#else
#include <ti/sysbios/hal/Cache.h>
#endif

/* CSL includes */
#include <ti/csl/soc.h>
#ifdef __ARM_ARCH_7A__
#include <ti/csl/csl_armGicAux.h>
#endif

#ifdef _TMS320C6X
#include <ti/sysbios/family/c66/Cache.h>
#endif

/* PDK Control Driver includes */
#include <ti/drv/uart/UART_stdio.h>
#include<ti/drv/pruss/soc/pruicss_v1.h>

#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/drv/icss_emac/soc/icss_emacSoc.h>
#include <ti/drv/icss_emac/test/src/fw_mem_section.h>

/* TI transport includes */
#include <ti/transport/ndk/nimu_icss/nimu_icssEth.h>

/* This module includes (timeSync) */
#include <ti/transport/timeSync/include/icss_timeSync.h>
#include <ti/transport/timeSync/include/icss_timeSync_init.h>
#include <ti/transport/timeSync/timeSync_ver.h>

/* Board lib includes */
#include <ti/board/board.h>


/* Example specific header include */
#include <src/soc/timeSyncExampleSoC.h>
#include <src/common/tiemac_pruss_intc_mapping.h>

#include <src/common/osdrv_ndkdeviceconfig.h>
#include <src/boardcfg/board_i2cLed.h>
#include <src/boardcfg/board_gpioLed.h>
#include <ti/drv/gpio/GPIO.h>
/* External references */
extern ICSS_EmacHandle appEmacHandle;
extern PRUICSS_Handle prusshandle;
extern TimeSync_ParamsHandle_t timeSyncHandle;


/* defines */
#define TIMESYNC_EXAMPLE_TEST_PORT0   1

#if     TIMESYNC_EXAMPLE_TEST_PORT0
#define TIMESYNC_TEST_PORT_NUM        0
#else
#define TIMESYNC_TEST_PORT_NUM        1
#endif



#endif /* TI_TRANSPORT_TIMESYNC_EXAMPLE_H */
