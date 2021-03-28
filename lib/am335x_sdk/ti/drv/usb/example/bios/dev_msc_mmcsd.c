/*
 * Copyright (C) 2016-2019 Texas Instruments Incorporated - http://www.ti.com/
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

/*
 * This example demonstate a USB MMCSD card reader.
 *
 * It shows how to connect USB Device mode MSC class to MMCSD APIs so
 * that the Host PC can read an attached MMCSD card in the EVM via USB.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <stdio.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/osal/HwiP.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <xdc/runtime/Error.h>

#include <ti/board/board.h>

#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

#if defined (idkAM572x) || defined (evmAM572x)
#include <ti/csl/soc/am572x/src/csl_device_xbar.h>
#elif defined (idkAM574x)
#include <ti/csl/soc/am574x/src/csl_device_xbar.h>
#endif

#include "ti/drv/usb/example/common/hardware.h"

#include <ti/drv/usb/usb_drv.h>
#include <ti/drv/usb/usb_osal.h>

#include "types.h"

#include "usb_drv.h"
#include "usbdmsc.h"
#include "usb_msc_structs.h"

/* Ramdisk utils header file */
#include "ramdiskutils.h"
#include "ti/drv/usb/example/common/diskimg.h"

#include "timer.h"


#include <ti/sdo/edma3/drv/edma3_drv.h>
#include <ti/sdo/edma3/rm/edma3_rm.h>
#include <ti/sdo/edma3/drv/sample/bios6_edma3_drv_sample.h>

#include <ti/drv/uart/UART_stdio.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#define NON_SECURE_MODE FALSE

#define SOC_CACHELINE_SIZE_MAX               (64)

#if (defined (evmAM335x)||defined(evmAM437x)||defined (bbbAM335x))
/* only USB#0 on AM437EVM can be USB DEV */
#define USB_DEV_INSTANCE                     0 
#else
/* on idkAM572x, USB1 is attached to a USB device connector */
#define USB_DEV_INSTANCE                     1
#endif

#if defined(SOC_K2G)
/* MMCSD is connected to EDMA_1 for K2G */
#define MMCSD_EDMACC_NUM 1
#else
#define MMCSD_EDMACC_NUM 0
#endif

#define MMCSD_INSTANCE_SDCARD  0
#define MMCSD_INSTANCE_EMMC    1

/* MMCSD controller instance for EMMC/SD-MMC */
#ifdef USB_DEVICE_EMMC
#define MMCSD_INSTANCE MMCSD_INSTANCE_EMMC
#else
#define MMCSD_INSTANCE MMCSD_INSTANCE_SDCARD
#endif

/* GPIO pin value definitions */
#define GPIO_PIN_VAL_LOW     (0U)
#define GPIO_PIN_VAL_HIGH    (1U)

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
void usbdIntrConfig(USB_Handle usbHandle, USB_Params* usbDevParams);
void consolePrintf(const char *pcString, ...);

static void hwiCoreIntrHandler(UArg arg);
#if (defined (SOC_AM335x))
static void hwiDmaHandler(UArg arg);
#endif

#ifdef USB_DEVICE_EMMC
static void EmmcsReset(void);
#endif
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#ifdef USB_DEVICE_EMMC
/* ON Board EMMC Reset pins which are connected to GPIO pins. */
typedef enum GPIO_PIN {
    GPIO_PIN_EMMC_RST      = 0U,
    GPIO_PIN_COUNT
}GPIO_PIN;

/* Port and pin number mask for EMMC reset pin.
   Bits 7-0: Pin number  and Bits 15-8: (Port number) */
#if defined (bbbAM335x)
#define GPIO_EMMC_RST_PIN_NUM       (0x14)
#define GPIO_EMMC_RST_PORT_NUM      (0x02)
#endif

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Output pin : EMMC_RST */
    GPIO_DEVICE_CONFIG(GPIO_EMMC_RST_PORT_NUM, GPIO_EMMC_RST_PIN_NUM) | GPIO_CFG_OUTPUT,
};
#else
/* ON Board LED pins which are connected to GPIO pins. */
typedef enum GPIO_PIN {
    GPIO_PIN_MMC_SDCD      = 0U,
    GPIO_PIN_COUNT
}GPIO_PIN;

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Output pin : AM335X_ICE V2_LD_PIN */
    GPIO_DEVICE_CONFIG(GPIO_MMC_SDCD_PORT_NUM, GPIO_MMC_SDCD_PIN_NUM) |
    GPIO_CFG_IN_INT_BOTH_EDGES | GPIO_CFG_INPUT,
};
#endif

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL,
};

/* GPIO Driver configuration structure */
#if defined(SOC_K2G) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
GPIO_v0_Config GPIO_v0_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};
#else
GPIO_v1_Config GPIO_v1_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};
#endif

EDMA3_RM_Handle gEdmaHandle = NULL;


#define USB_INTERRUPT_EVNT     Event_Id_00
#define USB_DMA_INTERRUPT_EVNT Event_Id_01

Event_Handle hEvents;
uint32_t g_resetUsb = 0;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/* Callback function */
void AppGpioCallbackFxn(void);


/* reset USB stack function */
#if (defined (SOC_AM335x))
static void resetUsb(USB_Params*  usbDdevParams);
#endif

//*****************************************************************************
// task function
//
//*****************************************************************************
Void taskFxn(UArg a0, UArg a1)
{
    USB_Params  usb_dev_params;
    USB_Handle  usb_handle;
    UInt        events;

#if defined (SOC_OMAPL137) || defined (SOC_OMAPL138)
    MMCSD_v0_HwAttrs           hwAttrsConfig;
#else
    MMCSD_v1_HwAttrs           hwAttrsConfig;
#endif

    consolePrintf("\nRTOS USB Dev MSC - MMCSD example!!\n");
    
    /* initialize MMCSD example application */
    EDMA3_DRV_Result edmaResult = 0;
    gEdmaHandle = (EDMA3_RM_Handle)edma3init(MMCSD_EDMACC_NUM, &edmaResult);

    if(MMCSD_socGetInitCfg(MMCSD_INSTANCE,&hwAttrsConfig)!=0) {
        consolePrintf ("\nUnable to obtain config.Exiting. TEST FAILED.\r\n");
        UART_printStatus("\n Some tests have failed.\n");
        return;
    }

    hwAttrsConfig.edmaHandle = gEdmaHandle;

    if(MMCSD_socSetInitCfg(MMCSD_INSTANCE, &hwAttrsConfig)!=0) {
        consolePrintf ("\nUnable to set config.Exiting. TEST FAILED.\r\n");
        UART_printStatus("\n Some tests have failed.\n");
        return;
    }

    /* GPIO initialization */
    GPIO_init();

#ifdef USB_DEVICE_EMMC
    EmmcsReset();
#else
    /* Set the callback function */
    GPIO_setCallback(GPIO_PIN_MMC_SDCD, AppGpioCallbackFxn);

    /* Enable GPIO interrupt on the specific gpio pin */
    GPIO_enableInt(GPIO_PIN_MMC_SDCD);

    if (GPIO_PIN_MMC_SDCD_ACTIVE_STATE == GPIO_read(GPIO_PIN_MMC_SDCD))
    {
        consolePrintf("\nMMCSD card inserted.\r\n");
    }
    else
    {
        consolePrintf("\nPlease insert card.\r\n");
    }
#endif

    /* end of MMCSD app init */

    /* Initialize the MMCSD LLD */
    MMCSD_init();

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
    UART_printStatus("\n Test in progress..\n");

    while(1)
    {
#if (defined (SOC_AM335x))
        if (g_resetUsb == 1)
        {
            g_resetUsb = 0;
            usb_handle->isOpened = 0;

            resetUsb(&usb_dev_params);
        }
#endif

        /* Main while loop. All USB dev events are handled in this task context */
        events = Event_pend(hEvents,
                            Event_Id_NONE,
                            USB_INTERRUPT_EVNT + USB_DMA_INTERRUPT_EVNT,
                            BIOS_WAIT_FOREVER);

        /* calling the main event handler */
        if (events & USB_INTERRUPT_EVNT)
        {
            USB_coreIrqHandler(usb_dev_params.usbHandle, &usb_dev_params);
            HwiP_enableInterrupt(SYS_INT_USB0);
        }

        /* calling the DMA event handler */
        if (events & USB_DMA_INTERRUPT_EVNT)
        {
#if (defined (SOC_AM335x))
            usbDmaIntrHandler(usb_dev_params.drvData);
            HwiP_enableInterrupt(SYS_INT_USBSSINT);
#endif
        }
    }
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------r- */
void usbdIntrConfig(USB_Handle usbHandle, USB_Params* usbDevParams)
{
    HwiP_Params hwiInputParams;
    int32_t mainIntNo = 0;

    usb_osalHwiParamsInit(&hwiInputParams);

    /* Construct Hwi object for this USB interrupts. */
	hwiInputParams.name = NULL;
    hwiInputParams.arg  = (uintptr_t)usbDevParams;
    hwiInputParams.priority = 0x10U;
    hwiInputParams.evtId = 0;
    hwiInputParams.triggerSensitivity = 0x3; /* interrupt edge triggered */

    if (usbDevParams->instanceNo == 0)
    {
        mainIntNo = SYS_INT_USB0;
    }
    else
    {
        mainIntNo = SYS_INT_USB1;
    }

    /* Initialize the object ISR fucntion with application ISR */
    usb_osalRegisterInterrupt(mainIntNo,
                              (HwiP_Fxn)hwiCoreIntrHandler,
                              &hwiInputParams);

#if (defined (SOC_AM335x))
    /* on AM335, the DMA interrupt is handled inside the USB LLD. But we need to handle all 
     * interrupts in task context. So we move the the DMA interrupt handler to application
     * layer. For that we need to tell the USB LLD to not register DMA handler on its own
     * before calling the USB_IrqConfig()
     * 
     * Handling USB events in IRQ is fine if we access RamDisk, but We really need to handle 
     * all USB events in main task context for the interface with MMCSD to work
     */
    usbHandle->handleCppiDmaInApp = TRUE;

    if ((usbHandle->dmaEnabled == TRUE) && (usbHandle->handleCppiDmaInApp == TRUE))
    {
        /* DMA interrupt */
        usb_osalRegisterInterrupt(SYS_INT_USBSSINT,
                                  (HwiP_Fxn)hwiDmaHandler,
                                  &hwiInputParams);
    }
#endif

    USB_irqConfig(usbHandle, usbDevParams);

}

/* main entry point for core interrupt handler */
static void hwiCoreIntrHandler(UArg arg)
{
	HwiP_disableInterrupt(SYS_INT_USB0);
    Event_post(hEvents, USB_INTERRUPT_EVNT);
}

#if (defined (SOC_AM335x))
/* main entry point for DMA interrupt handler */
static void hwiDmaHandler(UArg arg)
{
    HwiP_disableInterrupt(SYS_INT_USBSSINT);
    Event_post(hEvents, USB_DMA_INTERRUPT_EVNT);
}
#endif


/*****************************************************************************
 *  main 
*****************************************************************************/
int main(void)
{

    Task_Handle task;
    Task_Params tskParams;
    Error_Block eb;

    Board_initCfg boardCfg;
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

    Error_init(&eb);

    hEvents = Event_create(NULL, &eb);
    if (hEvents == NULL)
    {
        System_printf("Event_create() failed!\n");
        BIOS_exit(0);
    }

    Task_Params_init(&tskParams);
    tskParams.stackSize = 0x4000;
    task = Task_create(taskFxn, &tskParams, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    delayTimerSetup();

#if defined (idkAM572x) || defined (idkAM574x)
    /* Cross bar configuration for USB interrupts - just use default values
     * Customized interrupt numbers can also be used if neccessary.
     * This code can be commented out since we are using default settings */
    /* USB 1 (1 base) */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_76,  CSL_XBAR_USB1_IRQ_INTR0);  /* main irq */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_77,  CSL_XBAR_USB1_IRQ_INTR1);  /* misc irq */

    /* USB 2 (1 base) */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_78,  CSL_XBAR_USB2_IRQ_INTR0);  /* main irq */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_92,  CSL_XBAR_USB2_IRQ_INTR1);  /* misc irq */
#endif

    BIOS_start();    /* does not return */

    return 0;
}

#ifdef USB_DEVICE_EMMC
/*
 *  ======== EMMC reset function ========
 */
static void EmmcsReset(void)
{
    /* EMMC reset */
    GPIO_write(GPIO_PIN_EMMC_RST, GPIO_PIN_VAL_LOW);
    usb_osalDelayMs(100);
    GPIO_write(GPIO_PIN_EMMC_RST, GPIO_PIN_VAL_HIGH);
    usb_osalDelayMs(100);
}

#else
/*
 *  ======== Callback function ========
 */
void AppGpioCallbackFxn(void)
{
    if (GPIO_PIN_MMC_SDCD_ACTIVE_STATE == GPIO_read(GPIO_PIN_MMC_SDCD))
    {
        consolePrintf("\nCard inserted.\r\n");
    }
    else
    {
        consolePrintf("\nCard removed.\r\n");
    }
}
#endif


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
