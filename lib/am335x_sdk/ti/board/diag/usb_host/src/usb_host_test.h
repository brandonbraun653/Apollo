/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 * \file   usb_host_test.h
 *
 * \brief  This is the header file for usb host diagnostic test.
 *
 */


#ifndef _USB_HOST_TEST_H_
#define _USB_HOST_TEST_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"

#include <ti/board/board.h>

#include "diag_common_cfg.h"

#if (defined(SOC_AM335x) || defined (SOC_AM437x))
#include "example_utils_mmu.h"
#include "mmu.h"

#include "cache.h"
#endif

#include <ti/drv/uart/UART_stdio.h>

#include <ti/fs/fatfs/FATFS.h>

#include "fatfs_port_usbmsc.h"
#include "fs_shell_app_utils.h"

#include "usb_drv.h"
#include "usb_osal.h"
#include "usblib.h"
#include "usbhost.h"
#include "usbhmsc.h"
#include "hw_usb.h"

#include "timer.h"

#if defined(BUILD_ARM) && (defined(SOC_OMAPL137) || defined(SOC_OMAPL138))
#include "ti/csl/arch/arm9/V0/csl_cp15.h"
#endif

#if (defined(SOC_AM65XX) && defined(BUILD_MCU))
#include "intRouter.h"
#endif
#if defined(am65xx_evm)
#include "board_cfg.h"
#include "ti/board/src/evmKeystone3/include/board_i2c_io_exp.h"
#include "ti/board/src/evmKeystone3/include/board_internal.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define USB_INSTANCE_CP             (1U)
#define USB_INSTANCE_SER            (0U)
#define NO_ERROR                (0U)

/* The instance data for the MSC driver. */

void*  g_ulMSCInstance = (void*)NULL;

#if defined(BUILD_ARM) && (defined(SOC_OMAPL137) || defined(SOC_OMAPL138))
/* USB param struture variable should be used as global variable because
 * ARM9 does not support interrupt hander with arguments
 */
USB_Params usb_host_params;
#endif

/**
 *  \brief Enum defining states of the mass storage device.
 */
typedef enum
{
    /* No device is present */
    STATE_NO_DEVICE,

    /* Mass storage device is being enumerated */
    STATE_DEVICE_ENUM,

    /* Mass storage device is ready */
    STATE_DEVICE_READY,

    /* An unsupported device has been attached */
    STATE_UNKNOWN_DEVICE,

    /* A power fault has occurred */
    STATE_POWER_FAULT
} tState;

volatile tState g_eState;


/* FAT fs variables.*/

/**
 *  \brief  USBMSC function table for USB implementation
 */
 
FATFS_DrvFxnTable FATFS_drvFxnTable = {
    /* closeDrvFxn */
    FATFSPortUSBDiskClose,
    /* controlDrvFxn */
    FATFSPortUSBDiskIoctl, 
    /* initDrvFxn */
    FATFSPortUSBDiskInitialize,
    /* openDrvFxn */
    FATFSPortUSBDiskOpen,
    /* writeDrvFxn */
    FATFSPortUSBDiskWrite, 
    /* readDrvFxn */
    FATFSPortUSBDiskRead        
};

/**
 *  \brief FATFS configuration structure.
 */
FATFS_HwAttrs FATFS_initCfg[_VOLUMES] =
{
    {
        0U
    },
    {
        1U
    },
    {
        2U
    },
    {
        3U
    }
};

/* FATFS objects */
FATFS_Object FATFS_objects[_VOLUMES];

/**
 *  \brief FATFS configuration structure.
 */
const FATFS_Config FATFS_config[_VOLUMES + 1] = {
    {
        &FATFS_drvFxnTable,
        &FATFS_objects[0],
        &FATFS_initCfg[0]
    },

    {
         &FATFS_drvFxnTable,
         &FATFS_objects[1],
         &FATFS_initCfg[1]
    },

    {
         &FATFS_drvFxnTable,
         &FATFS_objects[2],
         &FATFS_initCfg[2]
    },

    {
         &FATFS_drvFxnTable,
         &FATFS_objects[3],
         &FATFS_initCfg[3]
    },
    {NULL, NULL, NULL}
};

FATFS_Handle fatfsHandle = NULL;

extern void CSL_A15_INIT_copyVectorTable(void);

/* ========================================================================== */
/*                                Prototypes                                  */
/* ========================================================================== */

/**
 *  \brief    callback from the MSC driver  
 *
 *  \param    ulInstance           [IN]       USB instance used
 *              ulEvent            [IN]       one of the events defined
 *                                            by the driver.
 *              pvData             [IN]       pointer to data passed into
 *                                            the initial call to register
 *                                            the callback.
 *
 */
void MSCCallback(void *ulInstance, uint32_t ulEvent, void *pvData);

/**
 *  \brief    Setting up the MMU for USB.
 */
void setupMMUForUSB(void);

/**
 *  \brief    main entry point for USB core interrupt handler  
 *
 *  \param    pUsbParam           [IN]       Parameters used 
 *                                             for configuring USB
 *
 */
void usbCoreIntrHandler(void* pUsbParam);

/**
 *  \brief   usb host Diagnostic test main function
 *
 *  \return  int - usb host Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int8_t BoardDiag_run_usbHost_test(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* #ifndef _USB_HOST_TEST_H_ */
