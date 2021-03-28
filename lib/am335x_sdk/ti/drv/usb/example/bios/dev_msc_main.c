/*
 * Copyright (C) 2016-2020 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <stdio.h>
#include <ti/sysbios/knl/Task.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <xdc/runtime/Error.h>

#include <ti/board/board.h>

#if !(defined (SOC_AM437x) && defined (SOC_AM335x))
#include <ti/csl/soc.h>
#endif

#include "ti/drv/usb/example/common/hardware.h"
#include "ti/drv/usb/example/common/timer.h"

#include <ti/drv/usb/usb_drv.h>
#include <ti/drv/usb/usb_osal.h>

#include "types.h"

#include "usb_drv.h"
#include "usbdmsc.h"
#include "usb_msc_structs.h"

/* Ramdisk utils header file */
#include "ramdiskutils.h"
#include "ti/drv/usb/example/common/diskimg.h"

#if ((defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(BUILD_MCU))
#include "intRouter.h"
#endif

#include <ti/drv/uart/UART_stdio.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#define SOC_CACHELINE_SIZE_MAX               (64)

#if (defined (evmAM335x) || defined(evmAM437x) || defined(evmOMAPL137) || \
    defined(lcdkOMAPL138) || defined (SOC_DRA72x) || defined (SOC_DRA75x) || \
    defined(j721e_evm))
/* only USB#0 on AM437EVM can be USB DEV */
#define USB_DEV_INSTANCE                     0 
#else
/* on idkAM572x, USB1 is attached to a USB device connector */
#define USB_DEV_INSTANCE                     1
#endif

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
void usbdIntrConfig(USB_Handle usbHandle, USB_Params* usbDevParams);
void consolePrintf(const char *pcString, ...);
void usbMiscIntrHandler(uint32_t* pUsbParam);
void usbCoreIntrHandler(uint32_t* pUsbParam);

void formatRamDisk(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#define RAM_DISK_MEMORY_SIZE         16

#if defined(__IAR_SYSTEMS_ICC__)
#pragma data_alignment=(SOC_CACHELINE_SIZE_MAX)
uint8_t gRamDisk[RAM_DISK_MEMORY_SIZE * 1024 *1024];
#else
uint8_t gRamDisk[RAM_DISK_MEMORY_SIZE * 1024 *1024] __attribute__ ((aligned(SOC_CACHELINE_SIZE_MAX)))
                                  __attribute__ ((section (".bss:extMemCache:ramdisk")));
#endif

/* on AM335x SOC, we might need to reset the USB core and restart
   the USB stack. This flag is for that purpose. It's set to 1
   when the USB stack detects the USB cable is disconnected. */
uint32_t g_resetUsb = 0;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*****************************************************************************
* task function
*
*****************************************************************************/
Void taskFxn(UArg a0, UArg a1)
{
    USB_Params  usb_dev_params;
    USB_Handle  usb_handle;

    consolePrintf("\nRTOS USB Dev MSC example!!\n");

    /* Initialize the RAMDisk */
    RAMDISKUtilsInit((uint8_t *)gRamDisk, sizeof(gRamDisk));
    formatRamDisk();

    usb_dev_params.usbMode = USB_DEVICE_MSC_MODE;
    usb_dev_params.instanceNo = USB_DEV_INSTANCE;  /* USB port # */
    usb_dev_params.usbClassData = (void*)&g_sMSCDevice;
    
    usb_handle = USB_open(usb_dev_params.instanceNo, &usb_dev_params);

    if (usb_handle == 0) 
    {
        consolePrintf("Failed to open USB driver\n");
        UART_printStatus("\n Some tests have failed.\n");
        while(1);
    }

    usbdIntrConfig(usb_handle, &usb_dev_params);

    consolePrintf("Done configuring USB and its interrupt. Example is ready!\n");
    UART_printStatus("\n Test in progress.\n");

    while(1)
    {
        /* Main while loop. All USB dev events are handled in interrupt context */

#if (defined (SOC_AM335x))
        if (g_resetUsb == 1)
        {
            /* we were signaled to reset the USB. Do it here */
            g_resetUsb = 0;
            usb_handle->isOpened = 0;

            resetUsb(&usb_dev_params);
        }
#endif
    }
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------r- */
void usbdIntrConfig(USB_Handle usbHandle, USB_Params* usbDevParams)
{


#if defined(_TMS320C6X)
    HwiP_Handle hwiHandle = NULL;
    OsalRegisterIntrParams_t interruptRegParams;

    /* Initialize with defaults */
    Osal_RegisterInterrupt_initParams(&interruptRegParams);

    /* Populate the interrupt parameters */
    interruptRegParams.corepacConfig.name=NULL;
    interruptRegParams.corepacConfig.corepacEventNum=SYS_INT_USB0; /* Event going in to CPU */
    interruptRegParams.corepacConfig.intVecNum= OSAL_REGINT_INTVEC_EVENT_COMBINER; /* Host Interrupt vector */
    interruptRegParams.corepacConfig.isrRoutine = (void (*)(uintptr_t))usbCoreIntrHandler;
    interruptRegParams.corepacConfig.arg = (uintptr_t)usbDevParams;

    Osal_RegisterInterrupt(&interruptRegParams,&hwiHandle);
#else
    HwiP_Params hwiInputParams;
    int32_t mainIntNo = 0;

    usb_osalHwiParamsInit(&hwiInputParams);

    /* Construct Hwi object for this USB interrupts. */
	hwiInputParams.name = NULL;
    hwiInputParams.arg  = (uintptr_t)usbDevParams;
    hwiInputParams.priority = 0x10U;
    hwiInputParams.evtId = 0;

    if (usbDevParams->instanceNo == 0)
    {
        mainIntNo = SYS_INT_USB0;
    }
#if !defined(SOC_OMAPL137) && !defined(SOC_OMAPL138)
    else
    {
        mainIntNo = SYS_INT_USB1;
    }
#if defined(__ARM_ARCH_7A__)
	hwiInputParams.triggerSensitivity = 0x3; /* interrupt edge triggered */
#endif
#endif

    /* Initialize the object ISR fucntion with application ISR */
    usb_osalRegisterInterrupt(mainIntNo,
                              (HwiP_Fxn)usbCoreIntrHandler,
                              &hwiInputParams);
#endif

#if ((defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(BUILD_MCU))
    /* configure the interrupt router for MCU (R5) build */
    usb_configIntRouter(usbDevParams->instanceNo,TRUE);
#endif

    USB_irqConfig(usbHandle, usbDevParams);

}

/* main entry point for DWC Miscs interrupt handler  with USB Wrapper setup.
 * Matching interrupt call-back function API */
void usbMiscIntrHandler(uint32_t* pUsbParam)
{
    USB_miscIrqHandler(((USB_Params*)pUsbParam)->usbHandle, (USB_Params*)pUsbParam);
}


/* main entry point for DWC core interrupt handler with USB Wrapper setup
* Matching interrupt call-back function API */
void usbCoreIntrHandler(uint32_t* pUsbParam)
{
    USB_coreIrqHandler(((USB_Params*)pUsbParam)->usbHandle, (USB_Params*)pUsbParam);
}


/* format the ramDisk with FAT16 format and have a readme.txt file as content 
 * the disk image is a FAT16 formatted from Linux
 */
void formatRamDisk(void)
{
    uint32_t* wp;
    uint32_t  i;

    memset(gRamDisk, 0, sizeof(gRamDisk));

    wp = (uint32_t*)gRamDisk;

    /* copy the MBR */
    for (i = 0; i<sizeof(img_mbr)/4; i++)
    {
        wp[i] = img_mbr[i];
    }

    /* manually fill the end of BPR / Boot Sector */
    gRamDisk[BS_SIGN_OFFSET]     = BOOT_SECTOR_SIGNATURE_55;
    gRamDisk[BS_SIGN_OFFSET + 1] = BOOT_SECTOR_SIGNATURE_AA;

    /* the FAT#1 - created by mkfs.vfat */
    wp[FF_ENTRY_0]     = FATFS_MEDIA_DESCRIPTOR_0;
    wp[FF_ENTRY_0 + 1] = FATFS_MEDIA_DESCRIPTOR_1;

    /* the FAT#2 - created by mkfs.vfat */
    wp[FF_ENTRY_1]     = FATFS_MEDIA_DESCRIPTOR_0;
    wp[FF_ENTRY_1 + 1] = FATFS_MEDIA_DESCRIPTOR_1;

    /* root dir */
    for (i = 0; i<sizeof(img_rd)/4; i++)
    {
        wp[FF_DIR_CLUSTER + i] = img_rd[i];
    }

    /* copy file content */
    memcpy(&wp[FF_ENTRY_FC], img_fc, sizeof(img_fc));

    /* update the size of the file content */
    wp[FF_ENTRY_FS] = sizeof(img_fc)-1;

}

/*****************************************************************************
 *  main 
*****************************************************************************/
int main(void)
{

    Task_Handle task;
    Task_Params params;
    Error_Block eb;
    volatile uint32_t emuwait_board=1;
    
    Board_initCfg boardCfg;
    Board_STATUS board_status;
    
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO;

    board_status=Board_init(boardCfg);
    if(board_status!=BOARD_SOK) {
		while(emuwait_board);
	}
    Error_init(&eb);
    Task_Params_init(&params);
    params.stackSize = 0x2000;
    task = Task_create(taskFxn, &params, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

#if defined (evmAM335x) || defined (evmOMAPL137) || defined (lcdkOMAPL138) || defined(j721e_evm)
    delayTimerSetup();
#endif

#if defined (idkAM572x) || defined (idkAM574x) || defined (SOC_DRA72x) || defined (SOC_DRA75x)
#if defined(ARM_M4_BUILD)
    /* USB 1 (1 base) */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_72,  CSL_XBAR_USB1_IRQ_INTR0);  /* main irq */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_73,  CSL_XBAR_USB1_IRQ_INTR1);  /* misc irq */

    /* USB 2 (1 base) */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_74,  CSL_XBAR_USB2_IRQ_INTR0);  /* main irq */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_76,  CSL_XBAR_USB2_IRQ_INTR1);  /* misc irq */
#else /* A15 build */
    /* USB 1 (1 base) */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_76,  CSL_XBAR_USB1_IRQ_INTR0);  /* main irq */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_77,  CSL_XBAR_USB1_IRQ_INTR1);  /* misc irq */

    /* USB 2 (1 base) */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_78,  CSL_XBAR_USB2_IRQ_INTR0);  /* main irq */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_92,  CSL_XBAR_USB2_IRQ_INTR1);  /* misc irq */
#endif
#endif

    BIOS_start();    /* does not return */

    return 0;
}

/* 
 * In AM335x, CPPI DMA and MUSB could get into a bad state which the USB seems
 * to send bulk IN with bogus data immediately after an IN token received from 
 * USB host.  This bad state normally happens after USB cable is unplugged
 * while a bulk-in transfer is happening. Cleaning up CPPI/USB pending/stuck
 * transaction does not work yet. Reset the USBSS and USB stack instead for now
 * for AM335x to solve the issue. Please note that this function resets the
 * whole USBSS which resets both USB instances.
 */
#if (defined (SOC_AM335x))
#define USB_USBSS_BASE_ADDR     (0x47400000u)
#define USB_USBSS_SYSCONFIG     (0x10u)
#define USB_USBSS_SOFT_RESET    (1<<0)

static void resetUsb(USB_Params*  usbDdevParams)
{
    USB_Handle usb_handle;
    uint32_t regVal;

    /* soft reset the USB controller */
    regVal = HWREGH(USB_USBSS_BASE_ADDR + USB_USBSS_SYSCONFIG);
    HWREG(USB_USBSS_BASE_ADDR + USB_USBSS_SYSCONFIG) = regVal | USB_USBSS_SOFT_RESET;

    /* restart the USB stack */
    usb_handle = USB_open(usbDdevParams->instanceNo, usbDdevParams);
    usb_handle->handleCppiDmaInApp = TRUE;

    USB_irqConfig(usb_handle, usbDdevParams);
}
#endif

