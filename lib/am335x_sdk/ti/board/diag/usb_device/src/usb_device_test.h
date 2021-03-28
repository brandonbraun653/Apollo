/******************************************************************************
 * Copyright (c) 2017-2018 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
*
* \file   usb_device_test.h
*
* \brief  This is the header file for usb device diagnostic test.
*
*/

#ifndef _USB_DEVICE_TEST_H
#define _USB_DEVICE_TEST_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"

#include <ti/board/board.h>

#include "diag_common_cfg.h"

#include <ti/drv/uart/UART_stdio.h>

#include "timer.h"
#include "ti/drv/usb/example/common/hardware.h"

#include "usb_osal.h"
#include "usb_drv.h"
#include "usbdmsc.h"
#include "usb_msc_structs.h"
#include "csl_intr_router.h"

/* Ramdisk utils header file */
#include "ramdiskutils.h"
#include "ti/drv/usb/example/common/diskimg.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void CSL_A15_INIT_copyVectorTable(void);

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#define SOC_CACHELINE_SIZE_MAX               (64U)

#if (defined(SOC_AM65XX) && defined(BUILD_MCU))
/* following values are MAIN2 MCU interrupt numbers and number of interrupts */
#define MAIN2MCU_LVL_INTRTR0_NUM_INTPUT_INTRS   (192u)
#define MAIN2MCU_LVL_INTRTR0_NUM_OUTPUT_INTRS   (64u)
#define MAIN2MCU_USB0_INT                       (132u)
#define MAIN2MCU_USB1_INT                       (152u)
#endif

#if defined (evmAM437x)
/* only USB#0 on AM437EVM can be USB DEV */
#define USB_DEV_INSTANCE                     (0U)
#else
#define USB_DEV_INSTANCE                     (1U)
#endif


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief    main entry point for USB Miscs interrupt handler.
 *
 *  \param    pUsbParam           [IN]       USB Parameters
 *
 */
void usbMiscIntrHandler(void* pUsbParam);

/**
 *  \brief    main entry point for USB core interrupt handler.
 *
 *  \param    pUsbParam           [IN]       Parameters used
 *                                           for configuring USB.
 *
 */
void usbCoreIntrHandler(void* pUsbParam);

/**
 *  \brief    Opens the USB Driver and performs device test
 *
 *  \return   int8_t
 *               0 - on data comparison match
 *              -1 - on data comparison mismatch.
 *
 */
int8_t BoardDiag_run_usbDevice_test(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#if defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
#define RAM_DISK_MEMORY_SIZE         4U
#elif defined(SOC_AM65XX)
#define RAM_DISK_MEMORY_SIZE         510U
#else
#define RAM_DISK_MEMORY_SIZE         16U
#endif

#if defined(__IAR_SYSTEMS_ICC__)
#pragma data_alignment=(SOC_CACHELINE_SIZE_MAX)
uint8_t gRamDisk[RAM_DISK_MEMORY_SIZE * 1024 *1024];
#else
uint8_t gRamDisk[RAM_DISK_MEMORY_SIZE * 1024] __attribute__ ((aligned(SOC_CACHELINE_SIZE_MAX)))
                                  /*MAXIE_TBD:- Need to which thing need to enable from the below to statements */
                                  __attribute__ ((section ("usbramdisk")));
                                  /* __attribute__ ((section (".bss:extMemCache:ramdisk"))); */
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* #ifndef USB_DEVICE_TEST_H */
