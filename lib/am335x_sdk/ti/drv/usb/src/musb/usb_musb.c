/**
 * @file   usb_musb.c
 *
 * @brief  This file contains the top level USB functions related to MUSB
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
#include "UsbDefs.h"

#include "usblib.h"
#include "usbhost.h"

/* USB MSC class related header files */
#include "usbdaudio.h"

/* USB AC class related header files */
#include "usbdaudio.h"
/* USB MSC class related header files */
#include "usbdmsc.h"
#include "usb_dev_dman.h"

/* USB Bulk */
#include "usbdbulk.h"

/* USB CDC */
#include "usbcdc.h"
#include "usbdcdc.h"

#include "musb.h"
#include "usb_musb_dcd.h"

#include "usb_osal.h"

#ifdef DMA_MODE
#include "cppi41dma.h"
#endif


#include "usb_wrapper.h"

#ifdef DMA_MODE
/* ****************************************************************************
* DMA endpoint settings for MSC - need configure with all end points?
                                - since this config could be different from
                                the config that user application can set.
***************************************************************************** */
endpointInfo epInfo[]=
{
    {
        USB_EP_TO_INDEX(USB_EP_1),
        CPDMA_DIR_RX,
#ifdef USE_GRNDIS
        CPDMA_MODE_SET_GRNDIS,
#else
        CPDMA_MODE_SET_TRANSPARENT,
#endif
    },

    {
        USB_EP_TO_INDEX(USB_EP_1),
        CPDMA_DIR_TX,
        CPDMA_MODE_SET_TRANSPARENT,
    },

    {
        USB_EP_TO_INDEX(USB_EP_2),
        CPDMA_DIR_RX,
#ifdef USE_GRNDIS
        CPDMA_MODE_SET_GRNDIS,
#else
        CPDMA_MODE_SET_TRANSPARENT,
#endif
    },

    {
        USB_EP_TO_INDEX(USB_EP_2),
        CPDMA_DIR_TX,
        CPDMA_MODE_SET_TRANSPARENT,
    }

};

#define NUMBER_OF_ENDPOINTS 4

#endif


/****************************************************************************** */
/* global USB host info */
/****************************************************************************** */
usbMusbDcdDevice_t musbObj[USB_NUM_INSTANCE];
tUSBInstanceObject g_USBInstance[USB_NUM_INSTANCE];

/* USB_musb functions */
USB_Handle   USB_open_musb(USB_Handle handle, USB_Params *params);
void         USB_irqConfig_musb(USB_Handle handle, USB_Params* params);
void         USB_irqCore_musb(USB_Handle handle, USB_Params* params);
void         USB_irqMisc_musb(USB_Handle handle, USB_Params* params);


/*
 * \brief USB main interrupt handler.
 * It gets all the interrupts for host, device and the wrapper layer.
 * Here it is decided which kind of interrupt has occured
 * and required fucntions are called
 */
void usbMusbDcdMiscIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam);

/* \brief core interrupt handler */
void usbMusbDcdCoreIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam);

/* MUSB DMA interrupt handler */
void usbDmaIntrHandler(uint32_t* pUsbParam);

/* other functions from the core driver */
void usbPhyOn(uint32_t portNumber, uint32_t invertPol);
void usbClockCfg(uint32_t portNumber);

/* regular prototypes */
static void setupMusbDevMsc(USB_Params* params);
static void setupMusbHostMsc(USB_Params* params);
static void setupMusbDevAc(USB_Params* params);

/* extern functions */
void USB_Host_Init(uint32_t ulIndex);

/*
 *  ======== USB_open_musb ========
 */
USB_Handle USB_open_musb(USB_Handle handle, USB_Params *params)
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
    if (params->usbMode == USB_DEVICE_BULK_MODE)
    {
        usb_osalSemParamsInit(&semParams);
        semParams.mode = SemaphoreP_Mode_BINARY;

        semParams.name = "writeSem";
        params->writeSem = usb_osalCreateBlockingLock(0, &semParams);

        semParams.name = "readSem";
        params->readSem = usb_osalCreateBlockingLock(0, &semParams);
    }

    switch (params->usbMode)
    {
        case USB_HOST_MSC_MODE:
            setupMusbHostMsc(params);

        break;

        case USB_DEVICE_MSC_MODE:
        case USB_DEVICE_BULK_MODE:
        case USB_DEVICE_CDC_MODE:
            setupMusbDevMsc(params);
        break;

        case USB_DEVICE_AC_MODE:
            setupMusbDevAc(params);
        break;

        default:
            return 0;
    }

#ifdef DMA_MODE
    handle->dmaEnabled = TRUE;

    /* by default, and for backward compatibility LLD takes care of DMA
     * interrupts. But if user needs to do USB interrupt in task context
     * or in main code loop task context, this flag needs to change to TRUE
     */
    handle->handleCppiDmaInApp = FALSE;
#else
    handle->dmaEnabled = FALSE;
#endif

    return handle;
}

void USB_irqConfig_musb(USB_Handle handle, USB_Params* params)
{
    switch (params->usbMode)
    {
        case USB_HOST_MSC_MODE:
            /*usb_set_wrapper(params->instanceNo); */

        break;

        case USB_DEVICE_MSC_MODE:
        case USB_DEVICE_AC_MODE:
        case USB_DEVICE_BULK_MODE:
        case USB_DEVICE_CDC_MODE:
            /* Enable USB Interrupts. */
            USBEnableOtgIntr(musbObj[params->instanceNo].uiSubBaseAddr);

            USBIntEnableControl(musbObj[params->instanceNo].baseAddr, 
                                               USB_INTCTRL_RESET |
                                               USB_INTCTRL_DISCONNECT |
                                               USB_INTCTRL_RESUME |
                                               USB_INTCTRL_SUSPEND |
                                               USB_INTCTRL_SOF);

            USBIntEnableEndpoint(musbObj[params->instanceNo].baseAddr, 
                                 USB_INTEP_ALL);

#ifdef DMA_MODE
            if (handle->handleCppiDmaInApp == FALSE)
            {
                USBDmaIntEnable(params);
            }
#endif

        break;

        default:
            return;
    }
}

/*
 *  ======== irq main handler ========
 */
void USB_irqCore_musb(USB_Handle handle, USB_Params* params)
{
    switch (params->usbMode)
    {
        case USB_HOST_MSC_MODE:
            usbHostIntrHandler(params);
        break;

        case USB_DEVICE_MSC_MODE:
        case USB_DEVICE_BULK_MODE:
        case USB_DEVICE_CDC_MODE:
        case USB_DEVICE_AC_MODE:
            usbMusbDcdCoreIntrHandler(0, 0, params->drvData);
        break;

        default:
            return;
    }
}

/*
 *  ======== irq main handler ========
 */
void USB_irqMisc_musb(USB_Handle handle, USB_Params* params)
{
    switch (params->usbMode)
    {
        case USB_HOST_MSC_MODE:
            usbHostIntrHandler(params);
        break;

        case USB_DEVICE_MSC_MODE:
        case USB_DEVICE_BULK_MODE:
        case USB_DEVICE_CDC_MODE:
        case USB_DEVICE_AC_MODE:
            usbMusbDcdMiscIntrHandler(0, 0, params->drvData);
        break;

        default:
            return;
    }
}

/*
 *  ======== setup MSC dev  ========
 */
static void setupMusbDevMsc(USB_Params* params)
{
    int32_t status = S_PASS;
#ifdef DMA_MULTIBUFFER_ALLOCATION
	uint32_t index = 0;
	uint8_t *dataBuffer;
#endif
	usbMusbDcdDevice_t *musb = NULL;

    memset(&musbObj[params->instanceNo], 0, sizeof(usbMusbDcdDevice_t));

    musb = &musbObj[params->instanceNo];
    USBInitMUSBDevCfg(musb, params->instanceNo);

    /* Enable USB phy and initialise the device controller */
    UsbPhyOn(musbObj[params->instanceNo].phyBaseAddr);
    usbClockCfg(params->instanceNo);

    usbDcd_t * pDcdCoreInterface = NULL;

    USBDInitCoreObject();

    status = USBDcdIntfRegisterDcd( &pDcdCoreInterface, 
                                    musbObj[params->instanceNo].name );

    if ( S_PASS == status)
    {
        /* this initialisation should be done in the dwc3 device control driver */
        musbObj[params->instanceNo].pDcdCore            = pDcdCoreInterface;
        pDcdCoreInterface->dcdActions.pFnDcInit         = &USBMusbDcdInit;

        /* device characteristics */
        pDcdCoreInterface->dcdActions.pFnConfigDevChara = &USBMusbDcdConfigDevChara;  

        pDcdCoreInterface->dcdActions.pFnEndpt0Req      = &USBMusbDcdEp0Req;
        pDcdCoreInterface->dcdActions.pFnEndptReq       = &USBMusbDcdEpReq;
        pDcdCoreInterface->privateData                  = &musbObj[params->instanceNo];
    }
    else
    {
    	while(1);	/* some setup errors. Trap it here. */
    }

    params->drvData = (void*)&musbObj[params->instanceNo];


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

#ifdef DMA_MODE
    Cppi41DmaInit(params->instanceNo, epInfo, NUMBER_OF_ENDPOINTS);

#ifdef DMA_MULTIBUFFER_ALLOCATION
	for(index = 0; index < NUM_OF_RX_BDs; index++)
    {
        dataBuffer = (unsigned char *)cppiDmaAllocBuffer();
        doDmaRxTransfer(params->instanceNo, USB_PACKET_LENGTH, dataBuffer,
                           INDEX_TO_USB_EP(2));
    }
#endif
#endif


}

/*
 *  ======== setup AC dev  ========
 */
static void setupMusbDevAc(USB_Params* params)
{
    int32_t status = S_PASS;
    usbMusbDcdDevice_t *musb = NULL;

    memset(&musbObj[params->instanceNo], 0, sizeof(usbMusbDcdDevice_t));

    musb = &musbObj[params->instanceNo];
    USBInitMUSBDevCfg(musb, params->instanceNo);
   
    /* Enable USB phy and initialise the device controller */
    UsbPhyOn(musbObj[params->instanceNo].phyBaseAddr);
    usbClockCfg(params->instanceNo);

    usbDcd_t * pDcdCoreInterface = NULL;

    USBDInitCoreObject();

    status = USBDcdIntfRegisterDcd( &pDcdCoreInterface, 
                                    musbObj[params->instanceNo].name );

    if ( S_PASS == status)
    {
        /* this initialisation should be done in the dwc3 device control driver */
        musbObj[params->instanceNo].pDcdCore            = pDcdCoreInterface;
        pDcdCoreInterface->dcdActions.pFnDcInit         = &USBMusbDcdInit;

        /* device characteristics */
        pDcdCoreInterface->dcdActions.pFnConfigDevChara = &USBMusbDcdConfigDevChara;  

        pDcdCoreInterface->dcdActions.pFnEndpt0Req      = &USBMusbDcdEp0Req;
        pDcdCoreInterface->dcdActions.pFnEndptReq       = &USBMusbDcdEpReq;
        pDcdCoreInterface->privateData                  = &musbObj[params->instanceNo];
    }
    else
    {
    	while(1);	/* some setup errors. Trap it here. */
    }

    params->drvData = (void*)&musbObj[params->instanceNo];


    /* Call the USB Audio init function here
       This call registers the class driver with the protocol layer */
    USBDAudioInit((void *) pDcdCoreInterface->pGadgetObject,
                (tUSBDAudioDevice *)params->usbClassData);

#ifdef DMA_MODE
    Cppi41DmaInit(params->instanceNo, epInfo, NUMBER_OF_ENDPOINTS);
#endif


}




/****************************************************************************** */
/* The global that holds all of the host drivers in use in the application. */
/* In this case, only the MSC class is loaded. */
/****************************************************************************** */
static tUSBHostClassDriver const * const g_ppHostClassDrivers[] =
{
    &g_USBHostMSCClassDriver
};

/****************************************************************************** */
/* This global holds the number of class drivers in the g_ppHostClassDrivers */
/* list. */
/****************************************************************************** */
#define NUM_CLASS_DRIVERS       (sizeof(g_ppHostClassDrivers) /               \
                                 sizeof(g_ppHostClassDrivers[0]))

/****************************************************************************** */
/* The size of the host controller's memory pool in bytes. */
/****************************************************************************** */
#define HCD_MEMORY_SIZE         128

/****************************************************************************** */
/* The memory pool to provide to the Host controller driver. */
/****************************************************************************** */
unsigned char g_pHCDPool[HCD_MEMORY_SIZE];






/*
 *  ======== setup MSC Host  ========
 */
static void setupMusbHostMsc(USB_Params* params)
{

    /* Enable Clocking to the USB controller. */
    USB_Host_Init(params->instanceNo);
    
    /* Initialize the power configuration.  This sets the power enable signal */
    /* to be active high and does not enable the power fault. */
    USBHCDPowerConfigInit(params->instanceNo, USBHCD_VBUS_AUTO_HIGH);

    /* Register the host class drivers. */
    USBHCDRegisterDrivers(params->instanceNo,
                          g_ppHostClassDrivers,
                          NUM_CLASS_DRIVERS);

#ifdef DMA_MODE
    Cppi41DmaInit(params->instanceNo, epInfo, NUMBER_OF_ENDPOINTS);
#endif

    /* Initialize the usblib host controller. */
    USBHCDInit(params->instanceNo, g_pHCDPool, HCD_MEMORY_SIZE);

    /* setup interrup call back user parametter */
}


/** \brief Enable all the wrapper interrupts
 *  \param baseAddr Baseaddress of USB wrapper register
 */
void usbMusbDcdEnableWrapperIntr(uint32_t baseAddr)
{
/* dummy function */
}

/*#endif */

