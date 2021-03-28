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

#if (!(defined (SOC_AM335x) && defined (SOC_AM437x)))
#include <ti/csl/soc.h>
#endif

#include "ti/drv/usb/example/common/hardware.h"

#include <ti/fs/fatfs/diskio.h>
#include <ti/fs/fatfs/FATFS.h>

#include "timer.h"
#include "types.h"
#include "fatfs_port_usbmsc.h"
#include "fs_shell_app_utils.h"

#include <ti/drv/usb/usb_drv.h>
#include <ti/drv/usb/usb_osal.h>
#include "usblib.h"
#include "usbhost.h"
#include "usbhmsc.h"


#if ((defined(SOC_AM65XX) || defined(SOC_J721E)) && defined(BUILD_MCU))
#include "intRouter.h"
#endif

#include <ti/drv/uart/UART_stdio.h>

/*****************************************************************************
*
* The instance data for the MSC driver.
*
*****************************************************************************/
tUSBHMSCInstance* g_ulMSCInstance = 0;


/*****************************************************************************
*
* Hold the current state for the application.
*
****************************************************************************/
typedef enum
{
    /*
    * No device is present.
    */
    STATE_NO_DEVICE,

    /*
    * Mass storage device is being enumerated.
    */
    STATE_DEVICE_ENUM,

    /*
    * Mass storage device is ready.
    */
    STATE_DEVICE_READY,

    /*
    * An unsupported device has been attached.
    */
    STATE_UNKNOWN_DEVICE,

    /*
    * A power fault has occurred.
    */
    STATE_POWER_FAULT
} tState;

volatile tState g_eState;



/*****************************************************************************
*
* FAT fs variables.
*
*****************************************************************************/
/* USBMSC function table for USB implementation */

FATFS_DrvFxnTable FATFS_drvFxnTable = {
    FATFSPortUSBDiskClose,      /* closeDrvFxn */
    FATFSPortUSBDiskIoctl,      /* controlDrvFxn */
    FATFSPortUSBDiskInitialize, /* initDrvFxn */
    FATFSPortUSBDiskOpen,       /* openDrvFxn */
    FATFSPortUSBDiskWrite,      /* writeDrvFxn */
    FATFSPortUSBDiskRead        /* readDrvFxn */
};

/* FATFS configuration structure */
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

/* FATFS configuration structure */
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
uint32_t     g_fsHasOpened = 0;


/* ========================================================================== */
/*                                Prototypes                                  */
/* ========================================================================== */
void usbHostIntrConfig(USB_Params* usbParams);
void MSCCallback(void* classInstance, uint32_t ulEvent, void *pvData);
void usbCoreIntrHandler(uint32_t* pUsbParam);

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#if defined (evmAM335x) || defined(evmAM437x) || defined(SOC_DRA72x) || defined(SOC_DRA75x)
#define USB_INSTANCE            1       /* USB #1 (the HOST port) on the EVM */
#else
/* on idkAM572x, K2G USB0 is attached to USB-A connector */
#define USB_INSTANCE            0       /* USB #0 (the USB-A host port) on the EVM */
                                        /* USB #1 (the USB-OTG port) on the EVM */
#endif


extern void consolePrintf(const char *pcString, ...);
extern void usbcGpioInit();

/*****************************************************************************
* main 
*
*****************************************************************************/
Void taskFxn(UArg a0, UArg a1)
{
    USB_Params  usb_host_params;
    USB_Handle  usb_handle;
    int         rc;

#ifdef USB3SS_EN
    USB_Config* usb_config;
#endif

    consolePrintf("\nRTOS USB Host MSC example!!\n");
    /*osalTimerTest();*/

#ifdef USB3SS_EN
    USB_getConfig(USB_INSTANCE, &usb_config);

    if (usb_config!=0)
    {
        usb_config->usb30Enabled = 1;
    }

#if defined(j721e_evm)
    /* J721E EVM has USB-C connector - init the USB-C monitor code now
     * we only need to use this USB-C monitor if we enable USB3.0 which
     * would require SERDES lane swapping when USB-C cable is inverted */
    usbcGpioInit();
#endif
#endif

    usb_host_params.usbMode      = USB_HOST_MSC_MODE;
    usb_host_params.instanceNo   = USB_INSTANCE;
    usb_handle = USB_open(usb_host_params.instanceNo, &usb_host_params);

    if (usb_handle == 0) 
    {
        UART_printStatus("\n Some tests have failed.\n");
        /* failed to open the USB driver */
        while(1);
    }

    /*
    *Setup the INT Controller
    */
	usbHostIntrConfig (&usb_host_params);

    /*
    * Initialize the file system.
    */
    FATFS_init();


    /*
    * Open an instance of the mass storage class driver.
    */
    g_ulMSCInstance = USBHMSCDriveOpen(usb_host_params.instanceNo, 0, MSCCallback);

    UART_printStatus("\n Test in progress.\n");

    while(1) {    
        rc = USBHCDMain(USB_INSTANCE, (void*)g_ulMSCInstance);

        if (rc != 0)
        {
            consolePrintf("USBHCDMain failed with this error: 0x%x\n", rc);
            while(1);
        }
        if(g_eState == STATE_DEVICE_ENUM)
        {
            /*
            * Take it easy on the Mass storage device if it is slow to
            * start up after connecting.
            */
            if(USBHMSCDriveReady(g_ulMSCInstance) != 0)
            {
                /*
                * Wait about 100ms before attempting to check if the
                * device is ready again.
                */
                usb_osalDelayMs(100);
            }

            if (!g_fsHasOpened)
            {
                /* USBMSC FATFS initialization */
                rc = FATFS_open(0U, NULL, &fatfsHandle);
                if (rc != FR_OK)
                {
                    consolePrintf("Failed to open FATFS\n");
                }
                else
                {
                    g_fsHasOpened = 1;
                }
            }

            /* only do this when the device is already enummerated. */
            FSShellAppUtilsProcess();
        }
    }
}




void usbHostIntrConfig(USB_Params* usbParams)
{
#if defined(SOC_AM65XX)
    /* we are not utilizing interrupt in host mode for xHCI yet. 
       if we enable interrupt, the interrupt pre-empts the main while loop that 
       handles the USB host events. So return here */
    return;

#else
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
    interruptRegParams.corepacConfig.arg = (uintptr_t)usbParams;

    Osal_RegisterInterrupt(&interruptRegParams,&hwiHandle);
#else
    int32_t mainIntNo = 0;
    HwiP_Params hwiInputParams;

    usb_osalHwiParamsInit(&hwiInputParams);

    /* Construct Hwi object for this USB interrupts. */
    hwiInputParams.name = NULL;
    hwiInputParams.arg  = (uintptr_t)usbParams;
    hwiInputParams.priority = 0x10U;
    hwiInputParams.evtId = 0;

    if (usbParams->instanceNo == 0) 
    {
#if defined(SOC_J721E)
        /* J7 has different interrupt for USB host or USB device */
        mainIntNo = SYS_INT_USB0_HOST;
#else
        mainIntNo = SYS_INT_USB0;
#endif
    } 

#if !defined(SOC_OMAPL137) && !defined(SOC_OMAPL138)
    else 
    {
        mainIntNo = SYS_INT_USB1;
    }

    hwiInputParams.triggerSensitivity = 0x3; /* interrupt edge triggered */
#endif
    usb_osalRegisterInterrupt(mainIntNo,
                              (HwiP_Fxn)usbCoreIntrHandler,
							  &hwiInputParams);
#endif

#if ((defined(SOC_AM65XX) || defined (SOC_J721E)) && defined(BUILD_MCU))
    /* configure the interrupt router for MCU (R5) build */
    usb_configIntRouter(usbParams->instanceNo,TRUE);
#endif

    USB_irqConfig(usbParams->usbHandle, usbParams);
#endif    
}



/*****************************************************************************
*
* This is the callback from the MSC driver.
*
* \param ulInstance is the driver instance which is needed when communicating
* with the driver.
* \param ulEvent is one of the events defined by the driver.
* \param pvData is a pointer to data passed into the initial call to register
* the callback.
*
* This function handles callback events from the MSC driver.  The only events
* currently handled are the MSC_EVENT_OPEN and MSC_EVENT_CLOSE.  This allows
* the main routine to know when an MSC device has been detected and
* enumerated and when an MSC device has been removed from the system.
*
* \return Returns \e true on success or \e false on failure.
*
*****************************************************************************/
void
MSCCallback(void* usbClassInstance, uint32_t ulEvent, void *pvData)
{
    /*
    * Determine the event.
    */
    switch(ulEvent)
    {
        /*
        * Called when the device driver has successfully enumerated an MSC
        * device.
        */
        case MSC_EVENT_OPEN:
        {
            /*
            * Proceed to the enumeration state.
            */
            g_eState = STATE_DEVICE_ENUM;
            break;
        }

        /*
        * Called when the device driver has been unloaded due to error or
        * the device is no longer present.
        */
        case MSC_EVENT_CLOSE:
        {
            /*
            * Go back to the "no device" state and wait for a new connection.
            */
            g_eState = STATE_NO_DEVICE;

            consolePrintf("USB device detached!\n");

            g_fsHasOpened = 0;

            FATFS_close(fatfsHandle);

            break;
        }

        default:
        {
            break;
        }
    }
}



/* main entry point for USB host core interrupt handler with USB Wrapper setup
* Matching interrupt call-back function API */
void usbCoreIntrHandler(uint32_t* pUsbParam)
{
    USB_coreIrqHandler(((USB_Params*)pUsbParam)->usbHandle, (USB_Params*)pUsbParam);
}

/*****************************************************************************
* main 
*
*****************************************************************************/
int main(void)
{

    Task_Handle task;
    Task_Params params;
    Error_Block eb;
    Board_STATUS boardRc;

    System_printf("enter main()\n");


    Board_initCfg boardCfg;

    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO;

    boardRc = Board_init(boardCfg);
    if (boardRc != BOARD_SOK)
    {
        System_printf("Board Init failed with code: 0x%x!\n", boardRc);
    }

    Error_init(&eb);
    Task_Params_init(&params);
    params.stackSize = 0x2000;
    task = Task_create(taskFxn, &params, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    delayTimerSetup();

#if defined (idkAM574x) || (defined (idkAM572x) || defined (idkAM571x)) || defined (SOC_DRA72x) || defined (SOC_DRA75x)
    /* USB 1 (1 base) */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_76,  CSL_XBAR_USB1_IRQ_INTR0);  /* main irq */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_77,  CSL_XBAR_USB1_IRQ_INTR1);  /* misc irq */

    /* USB 2 (1 base) */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_78,  CSL_XBAR_USB2_IRQ_INTR0);  /* main irq */
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_92,  CSL_XBAR_USB2_IRQ_INTR1);  /* misc irq */
#endif

    BIOS_start();    /* does not return */

    return 0;
}


