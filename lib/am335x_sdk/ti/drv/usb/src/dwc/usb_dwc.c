/**
 * @file   USB_dwc.c
 *
 * @brief  Top level DWC usb functions
 */
/*
 * Copyright (c) 2016-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================*/

#include "types.h"
#include "error.h"

/* pdk includes */
#include <ti/drv/usb/usb_drv.h>

#include "hw_usb.h"
#include "usb_hcd_xhci.h"
#include "usb_dwc_dcd.h"
#include "UsbDefs.h"
#include "usb_dwc.h"

#include "usblib.h"
#include "usbhost.h"
#include "usb_osal.h"

/* USB MSC class related header files */
#include "usbdmsc.h"
#include "usb_dev_dman.h"
#include "usb_wrapper.h"

/* Bulk */
#include "usbdbulk.h"

/* USB CDC */
#include "usbcdc.h"
#include "usbdcdc.h"

/****************************************************************************** */
/* global USB info */
/****************************************************************************** */
tUSBInstanceObject  g_USBInstance[USB_NUM_INSTANCE];

/* The following USB memory has to be in a non-cached memory section
   User application is responsible for directing this section and 
   setting MMU attribute of this mem block */
USB_MEM_S           g_usb_global __attribute__ ((section (".bss:extMemNonCache:usbXhci")));



/* USB_dwc functions */
USB_Handle   USB_open_dwc(USB_Handle handle, USB_Params *params);
void         USB_irqConfig_dwc(USB_Handle handle, USB_Params* params);
void         USB_irqCore_dwc(USB_Handle handle, USB_Params* params);
void         USB_irqMisc_dwc(USB_Handle handle, USB_Params* params);


/*
 * \brief USB main interrupt handler.
 * It gets all the interrupts for host, device and the wrapper layer.
 * Here it is decided which kind of interrupt has occured
 * and required fucntions are called
 */
void usbDwcDcdMiscIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam);

/* \brief core interrupt handler */
void usbDwcDcdCoreIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam);


/* other functions from the core driver */
void usbPhyOn(uint32_t portNumber, uint32_t invertPol);
void usbClockCfg(uint32_t portNumber);

/* regular prototypes */
static void setupDwcDevMsc(USB_Params* params);
static void setupDwcHostMsc(USB_Params* params);

/*
 *  ======== USB_open_dwc ========
 */
USB_Handle USB_open_dwc(USB_Handle handle, USB_Params *params)
{
    SemaphoreP_Params           semParams;

    if (handle->isOpened == 1) 
    {
        /* this handle has been used; */
        return 0;
    }

    /* mark used */
    handle->isOpened = 1;

    /* save the handle for interrupt handler */
    params->usbHandle = handle;
    handle->usbParams = params;

    /* initialize semaphores for the driver to use 
       Currently only USB generic bulk transport demo uses semaphore
     */
    usb_osalSemParamsInit(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;

    semParams.name = (char *) ("writeSem");
    params->writeSem = usb_osalCreateBlockingLock(0, &semParams);

    semParams.name = (char *) ("readSem");
    params->readSem = usb_osalCreateBlockingLock(0, &semParams);

    switch (params->usbMode)
    {
        case USB_HOST_MSC_MODE:
            setupDwcHostMsc(params);

        break;

        case USB_DEVICE_MSC_MODE:
        case USB_DEVICE_BULK_MODE:
        case USB_DEVICE_CDC_MODE:
            setupDwcDevMsc(params);
        break;

        default:
            return 0;
    }

    return handle;
}

void USB_irqConfig_dwc(USB_Handle handle, USB_Params* params)
{
    uint32_t baseAddr;
    switch (params->usbMode)
    {
        case USB_HOST_MSC_MODE:
            usb_set_wrapper(params->instanceNo);
        break;

        case USB_DEVICE_MSC_MODE:
        case USB_DEVICE_BULK_MODE:
        case USB_DEVICE_CDC_MODE:
            baseAddr = USB_DWC3_WRAPPER_BASE_ADDR(params->instanceNo);
            usbDwcDcdEnableWrapperIntr(baseAddr);
        break;

        default:
            return;
    }
}

/*
 *  ======== irq main handler ========
 */
void USB_irqCore_dwc(USB_Handle handle, USB_Params* params)
{
    switch (params->usbMode)
    {
        case USB_HOST_MSC_MODE:
            usbHostIntrHandler(params->drvData);
        break;

        case USB_DEVICE_MSC_MODE:
        case USB_DEVICE_BULK_MODE:
        case USB_DEVICE_CDC_MODE:
            usbDwcDcdCoreIntrHandler(0, 0, params->drvData);
        break;

        default:
            return;
    }
}

/*
 *  ======== irq main handler ========
 */
void USB_irqMisc_dwc(USB_Handle handle, USB_Params* params)
{
    switch (params->usbMode)
    {
        case USB_HOST_MSC_MODE:
            usbHostIntrHandler(params->drvData);
        break;

        case USB_DEVICE_MSC_MODE:
        case USB_DEVICE_BULK_MODE:
        case USB_DEVICE_CDC_MODE:
            usbDwcDcdMiscIntrHandler(0, 0, params->drvData);
        break;

        default:
            return;
    }
}

/*
 *  ======== setup MSC dev  ========
 */
void setupDwcDevMsc(USB_Params* params)
{
    int32_t status = S_PASS;

    usbDwcDcdDevice_t* dwc3;

    /* clear the memory since it could be in NOLOAD memory */
    memset(&g_usb_global.drv_instances[params->instanceNo], 0, sizeof(dwc_instance_u));

    dwc3 = &g_usb_global.drv_instances[params->instanceNo].dwc3;

    /* Enable USB phy and initialise the device controller */
    usbPhyOn(params->instanceNo, 0); /* port No and no invert polarity */

    usbClockCfg(params->instanceNo);

    usb_wrapper_setup_device_mode(params->instanceNo);

    /** The registration process starts here */
    if (params->instanceNo == 0)
    {
        strcpy(dwc3->name, "DWC3_0");
        dwc3->baseAddr = USB0_DWC_WRAPPER_BASE_ADDR + USB_DWC_CORE_OFFSET;
        dwc3->wrapperAddr = USB0_DWC_WRAPPER_BASE_ADDR;
    }
    else if (params->instanceNo == 1)
    {
        strcpy(dwc3->name, "DWC3_1");
        dwc3->baseAddr = USB1_DWC_WRAPPER_BASE_ADDR + USB_DWC_CORE_OFFSET;
        dwc3->wrapperAddr = USB1_DWC_WRAPPER_BASE_ADDR;
    }

    usbDcd_t * pDcdCoreInterface = NULL;

    USBDInitCoreObject();
    status = USBDcdIntfRegisterDcd( &pDcdCoreInterface, dwc3->name );

    if ( S_PASS == status)
    {
        /* this initialisation should be done in the dwc3 device control driver */
        dwc3->pDcdCore = pDcdCoreInterface;
        pDcdCoreInterface->dcdActions.pFnDcInit         = &USBDwcDcdInit;
        pDcdCoreInterface->dcdActions.pFnConfigDevChara = &USBDwcDcdConfigDevChara;
        pDcdCoreInterface->dcdActions.pFnEndpt0Req      = &USBDwcDcdEp0Req;
        pDcdCoreInterface->dcdActions.pFnEndptReq       = &USBDwcDcdEpReq;
        pDcdCoreInterface->privateData                  = dwc3 ;
    }

    params->drvData = (void*)dwc3;

    switch (params->usbMode)
    {
        case USB_DEVICE_MSC_MODE:

            /* Call the USB Msc init function here
               This call registers the class driver with the protocol layer */
            USBDMSCInit((void *) pDcdCoreInterface->pGadgetObject,
                        (tUSBDMSCDevice *)params->usbClassData);
            break;

        case USB_DEVICE_BULK_MODE:
            USBDBulkInit((void *) pDcdCoreInterface->pGadgetObject,
                        (tUSBDBulkDevice *)params->usbClassData, params);
            break;

        case USB_DEVICE_CDC_MODE:
            USBDCDCInit((void *) pDcdCoreInterface->pGadgetObject,
                        (tUSBDCDCDevice *)params->usbClassData, params);
            break;

        default:
            break;
    }
}

/****************************************************************************** 
 *
 * The global that holds all of the host drivers in use in the application. 
 * In this case, only the MSC class is loaded.
 * 
 ****************************************************************************** */
static tUSBHostClassDriver const * const g_ppHostClassDrivers[] =
{
    &g_USBHostMSCClassDriver
};

/****************************************************************************** 
 * 
 * This global holds the number of class drivers in the g_ppHostClassDrivers 
 * list.
 *
 ****************************************************************************** */
#define NUM_CLASS_DRIVERS       (sizeof(g_ppHostClassDrivers) /               \
                                 sizeof(g_ppHostClassDrivers[0]))

/****************************************************************************** 
 * 
 * The size of the host controller's memory pool in bytes.
 * 
 ****************************************************************************** */
#define HCD_MEMORY_SIZE         128

/****************************************************************************** 
 *
 * The memory pool to provide to the Host controller driver. 
 *
 ****************************************************************************** */
unsigned char g_pHCDPool[HCD_MEMORY_SIZE];

/*
 *  ======== setup MSC host  ========
 */
static void setupDwcHostMsc(USB_Params* params)
{
    XHCI_DATA_S*  xhciData;

    /* clear the memory since it could be in NOLOAD memory */
    memset(&g_usb_global.drv_instances[params->instanceNo], 0, sizeof(dwc_instance_u));

    xhciData = &g_usb_global.drv_instances[params->instanceNo].xhciData;

    /*
     * Init the clock, power domains, and USB controller.
     */
    USB_Host_Init(params->instanceNo);
    
    /* setup the wrapper */
    usb_wrapper_setup_host_mode(params->instanceNo);

    /* 
     * Initialize the power configuration.  This sets the power enable signal 
     * to be active high and does not enable the power fault. */
    USBHCDPowerConfigInit(params->instanceNo, USBHCD_VBUS_AUTO_HIGH);

    /*
     * Register the host class drivers. 
     * */
    USBHCDRegisterDrivers(params->instanceNo,
                          g_ppHostClassDrivers,
                          NUM_CLASS_DRIVERS);

    /* 
     * Initialize the usblib host controller. 
     */
    USBHCDInit(params->instanceNo, g_pHCDPool, HCD_MEMORY_SIZE);

    /* setup interrup call back user parametter */
    params->drvData = (void*)xhciData;

}


