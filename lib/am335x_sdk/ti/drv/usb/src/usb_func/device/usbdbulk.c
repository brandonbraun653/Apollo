/***************************************************************************** 
 * 
 * usbdbulk.c - USB bulk device class driver.
 *
 * Copyright (c) 2008-2018 Texas Instruments Incorporated. 
 ******************************************************************************/
/*
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the fosllowing disclaimer.
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

#include "types.h"
#include "usb_drv.h"
#include "usblib.h"
#include "usbdevice.h"
#include "usbdbulk.h"
#include "usblibpriv.h"
#include "debug.h"

#include "usb_dev_dman.h"
#include "musb.h"   
#include "usb_musb_dcd.h"
#include "usb_osal.h"

/****************************************************************************** 
 *
 * \addtogroup bulk_device_class_api 
 * @{ 
 *
 ****************************************************************************** */

/****************************************************************************** 
* Endpoint number to use for each of the required endpoints in the driver. 
* Note: the number chosen here matched with what the MSC class has since the 
* DWC DCD driver hard-codes the endpoint to these two endpoints. Need to fix it
****************************************************************************** */
#define DATA_IN_ENDPOINT        1
#define DATA_OUT_ENDPOINT       2

/****************************************************************************** */
/* Maximum packet size for the bulk endpoints used for serial data */
/* transmission and reception and the associated FIFO sizes to set aside */
/* for each endpoint. */
/****************************************************************************** */
#define DATA_IN_EP_MAX_SIZE     (512)
#define DATA_OUT_EP_MAX_SIZE    (512)

/****************************************************************************** */
/* USB instance Object */
/****************************************************************************** */
extern tUSBInstanceObject g_USBInstance[];

/****************************************************************************** */
/* Device Descriptor.  This is stored in RAM to allow several fields to be */
/* changed at runtime based on the client's requirements. */
/****************************************************************************** */
uint8_t g_pBulkDeviceDescriptor[] =
{
    18,                         /* Size of this structure. */
    USB_DTYPE_DEVICE,           /* Type of this structure. */
    USBShort(0x200),            /* USB version 2.0, hosts assume */
                                /* high-speed - see USB 2.0 spec 9.2.6.6) */
    USB_CLASS_VEND_SPECIFIC,    /* USB Device Class */
    0,                          /* USB Device Sub-class */
    0,                          /* USB Device protocol */
    64,                         /* Maximum packet size for default pipe. */
    USBShort(0),                /* Vendor ID (VID). */
    USBShort(0),                /* Product ID (PID). */
    USBShort(0x100),            /* Device Version BCD. */
    1,                          /* Manufacturer string identifier. */
    2,                          /* Product string identifier. */
    3,                          /* Product serial number. */
    1                           /* Number of configurations. */
};

/******************************************************************************
 *
 * Bulk device configuration descriptor. 
 *
 * It is vital that the configuration descriptor bConfigurationValue field 
 * (byte 6) is 1 for the first configuration and increments by 1 for each 
 * additional configuration defined here.  This relationship is assumed in the 
 * device stack for simplicity even though the USB 2.0 specification imposes
 * no such restriction on the bConfigurationValue values. 
 *
 * Note that this structure is deliberately located in RAM since we need to 
 * be able to patch some values in it based on client requirements. 
 *
 ****************************************************************************** */
uint8_t g_pBulkDescriptor[] =
{
    /* Configuration descriptor header. */
    9,                          /* Size of the configuration descriptor. */
    USB_DTYPE_CONFIGURATION,    /* Type of this descriptor. */
    USBShort(32),               /* The total size of this full structure. */
    1,                          /* The number of interfaces in this */
                                /* configuration. */
    1,                          /* The unique value for this configuration. */
    5,                          /* The string identifier that describes this */
                                /* configuration. */
    USB_CONF_ATTR_SELF_PWR,     /* Bus Powered, Self Powered, remote wake up. */
    250,                        /* The maximum power in 2mA increments. */
};

/****************************************************************************** 
 *
 * The remainder of the configuration descriptor is stored in flash since we 
 * don't need to modify anything in it at runtime. 
 *
 ****************************************************************************** */
const uint8_t g_pBulkInterface[] =
{
    /* Vendor-specific Interface Descriptor. */
    9,                          /* Size of the interface descriptor. */
    USB_DTYPE_INTERFACE,        /* Type of this descriptor. */
    0,                          /* The index for this interface. */
    0,                          /* The alternate setting for this interface. */
    2,                          /* The number of endpoints used by this */
                                /* interface. */
    USB_CLASS_VEND_SPECIFIC,    /* The interface class */
    0,                          /* The interface sub-class. */
    0,                          /* The interface protocol for the sub-class */
                                /* specified above. */
    4,                          /* The string index for this interface. */

    /* Endpoint Descriptor */
    7,                               /* The size of the endpoint descriptor. */
    USB_DTYPE_ENDPOINT,              /* Descriptor type is an endpoint. */
    USB_EP_DESC_IN | DATA_IN_ENDPOINT,
    USB_EP_ATTR_BULK,                /* Endpoint is a bulk endpoint. */
    USBShort(DATA_IN_EP_MAX_SIZE),   /* The maximum packet size. */
    0,                               /* The polling interval for this endpoint. */

    /* Endpoint Descriptor */
    7,                               /* The size of the endpoint descriptor. */
    USB_DTYPE_ENDPOINT,              /* Descriptor type is an endpoint. */
    USB_EP_DESC_OUT | DATA_OUT_ENDPOINT,
    USB_EP_ATTR_BULK,                /* Endpoint is a bulk endpoint. */
    USBShort(DATA_OUT_EP_MAX_SIZE),  /* The maximum packet size. */
    0,                               /* The polling interval for this endpoint. */
};

/****************************************************************************** 
 *
 * The serial config descriptor is defined as two sections, one containing 
 * just the 9 byte USB configuration descriptor and the other containing 
 * everything else that is sent to the host along with it. 
 *
 ****************************************************************************** */
const tConfigSection g_sBulkConfigSection =
{
    sizeof(g_pBulkDescriptor),
    g_pBulkDescriptor
};

const tConfigSection g_sBulkInterfaceSection =
{
    sizeof(g_pBulkInterface),
    g_pBulkInterface
};

/****************************************************************************** 
 *
 * This array lists all the sections that must be concatenated to make a 
 * single, complete bulk device configuration descriptor. 
 *
 ****************************************************************************** */
const tConfigSection *g_psBulkSections[] =
{
    &g_sBulkConfigSection,
    &g_sBulkInterfaceSection
};

#define NUM_BULK_SECTIONS (sizeof(g_psBulkSections) /                         \
                           sizeof(tConfigSection *))

/******************************************************************************
 *
 * The header for the single configuration we support.  This is the root of
 * the data structure that defines all the bits and pieces that are pulled
 * together to generate the configuration descriptor.
 *
 ****************************************************************************** */
const tConfigHeader g_sBulkConfigHeader =
{
    NUM_BULK_SECTIONS,
    g_psBulkSections
};

/****************************************************************************** */
/* Configuration Descriptor. */
/****************************************************************************** */
const tConfigHeader * const g_pBulkConfigDescriptors[] =
{
    &g_sBulkConfigHeader
};

/****************************************************************************** */
/* Forward references for device handler callbacks */
/****************************************************************************** */
static void HandleConfigChange(void *pvInstance, 
                               uint32_t ulInfo, 
                               uint32_t ulIndex);

static void HandleDisconnect(void *pvInstance);

static void HandleEndpoints(struct usbGadgetObj *pGadgetObject,
                            usbGenericEvent_t endptEvent, 
                            uint32_t epNo,
                            uint32_t length);

static void HandleSuspend(void *pvInstance);
static void HandleResume(void *pvInstance);
static void HandleDevice(void *pvInstance, uint32_t ulRequest,
                         void *pvRequestData);
static void HandleReset(void *pvInstance);

/****************************************************************************** */
/* The device information structure for the USB serial device. */
/****************************************************************************** */
tDeviceInfo g_sBulkDeviceInfo =
{
    /* Device event handler callbacks. */
    {
        0,                     /* pfnGetDescriptor */
        0,                     /* pfnRequestHandler */
        0,                     /* pfnInterfaceChange */
        HandleConfigChange,    /* pfnConfigChange */
        0,                     /* pfnDataReceived */
        0,                     /* pfnDataSentCallback */
        HandleReset,           /* pfnResetHandler */
        HandleSuspend,         /* pfnSuspendHandler */
        HandleResume,          /* pfnResumeHandler */
        HandleDisconnect,      /* pfnDisconnectHandler */
        HandleEndpoints,       /* pfnEndpointHandler */
        HandleDevice           /* pfnDevicehandler. */
    },                         /* sCallbacks */

    g_pBulkDeviceDescriptor,
    (usbConfigHeader_t **)g_pBulkConfigDescriptors,
    0,                         /* Will be completed during USBDBulkInit(). */
    0,                         /* Will be completed during USBDBulkInit(). */
    0,                         /* pvInstance */
    0                          /* pGadgetObj */
};


/****************************************************************************** */
 
/* Receives notifications related to data received from the host. */
/* \param psDevice is the device instance whose endpoint is to be processed. */
/* \param ulStatus is the USB interrupt status that caused this function to */
/* be called. */

/* This function is called from HandleEndpoints for all interrupts signaling */
/* the arrival of data on the bulk OUT endpoint (in other words, whenever the */
/* host has sent us a packet of data).  We inform the client that a packet */
/* is available and, on return, check to see if the packet has been read.  If */
/* not, we schedule another notification to the client for a later time. */
 
/* \return Returns \b TRUE on success or \b FALSE on failure. */
 
/****************************************************************************** */
static tBoolean
ProcessDataFromHost(struct usbGadgetObj *pGadgetObj, 
                    const tUSBDBulkDevice *psDevice,
                    uint32_t length)
{
    tBulkInstance *psInst;

    /* Get a pointer to our instance data. */
    psInst = psDevice->psPrivateBulkData;

    /* handle DMA transaction.
       We got here because we have received a bulk-out interrupt
     */
    psInst->eBulkRxState = BULK_STATE_IDLE;
    psInst->usLastRxSize = length;

    usb_osalPostLock(psInst->readSem);

    /* data should be already received. */
    psDevice->pfnRxCallback(pGadgetObj, 
                        psDevice->pvRxCBData,
                        USB_EVENT_RX_AVAILABLE, 
                        length,
                        (void *)0);

    return (TRUE);
}

/****************************************************************************** */
/* Receives notifications related to data sent to the host. */
/* \param psDevice is the device instance whose endpoint is to be processed. */

/* This function is called from HandleEndpoints for all interrupts originating */
/* from the bulk IN endpoint (in other words, whenever data has been */
/* transmitted to the USB host).  We examine the cause of the interrupt and, */
/* if due to completion of a transmission, notify the client. */

/* \return Returns \b TRUE on success or \b FALSE on failure. */

/****************************************************************************** */
static tBoolean
ProcessDataToHost(struct usbGadgetObj *pGadgetObject, 
                    const tUSBDBulkDevice *psDevice,
                    int32_t length)
{
    tBulkInstance *psInst;


    /* Get a pointer to our instance data. */
    psInst = psDevice->psPrivateBulkData;

    /* Our last transmission completed.  Clear our state back to idle and */
    /* see if we need to send any more data. */
    psInst->eBulkTxState = BULK_STATE_IDLE;

    /* Notify the client that the last transmission completed. */
    psInst->usLastTxSize = length;

    usb_osalPostLock(psInst->writeSem);

    if (psDevice->pfnTxCallback)
    {
        psDevice->pfnTxCallback(NULL,
                            psDevice->pvTxCBData, 
                            USB_EVENT_TX_COMPLETE,
                            length, (void *)0);
    }


    return (TRUE);
}

/******************************************************************************
*
* Called by the USB stack for any activity involving one of our endpoints 
* other than EP0.  This function is a fan out that merely directs the call to 
* the correct handler depending upon the endpoint and transaction direction 
* signaled in ulStatus. 
*
****************************************************************************** */
static void 
HandleEndpoints(struct usbGadgetObj *pGadgetObj,
                usbGenericEvent_t endptEvent, 
                uint32_t epNo,
                uint32_t length)

{
    const tUSBDBulkDevice *psBulkInst;
    void* privData;

    debug_printf("%s:%d\n", __FUNCTION__, __LINE__);

    ASSERT(pGadgetObj != 0);
 
    /* Determine if the serial device is in single or composite mode because */
    /* the meaning of ulIndex is different in both cases. */
    privData = pGadgetObj->usbClass.privateData;
    psBulkInst = (const tUSBDBulkDevice *)privData;

    switch(endptEvent)
    {
        case USB_GENERIC_EVENT_DATA_IN_COMPLETE:
        {
            /* Handler for the bulk IN data endpoint. */
            ProcessDataToHost(pGadgetObj, psBulkInst, length);

            break;
        }
        
        case USB_GENERIC_EVENT_DATA_OUT_COMPLETE:
        {
            /* Handler for the bulk OUT data endpoint. */
            /* Data is being sent to us from the host. */
            ProcessDataFromHost(pGadgetObj, psBulkInst, length);

            break;
        }

        default:
            break;
    }
}

/******************************************************************************
 *
 * Called by the USB stack whenever a configuration change occurs.
 *
 ****************************************************************************** */
static void
HandleConfigChange(void *pvInstance, uint32_t ulInfo,  
                                            uint32_t ulIndex)
{
    tBulkInstance *psInst;
    const tUSBDBulkDevice *psDevice;

    ASSERT(pvInstance != 0);

 
    /* Create a device instance pointer. */
    psDevice = (const tUSBDBulkDevice *)pvInstance;

    /* Get a pointer to our instance data. */
    psInst = psDevice->psPrivateBulkData;
 
    /* Set all our endpoints to idle state. */
    psInst->eBulkRxState = BULK_STATE_IDLE;
    psInst->eBulkTxState = BULK_STATE_IDLE;

 
    /* If we have a control callback, let the client know we are open for */
    /* business. */
    if(psDevice->pfnRxCallback)
    {
        /* Pass the connected event to the client. */
        psDevice->pfnRxCallback(NULL,
                                psDevice->pvRxCBData, 
                                USB_EVENT_CONNECTED, 
                                0,
                                (void *)0);
    }
 
    /* Remember that we are connected. */
    psInst->bConnected = TRUE;

}

/******************************************************************************
 *
 * Device instance specific handler.
 *
 ****************************************************************************** */
static void
HandleDevice(void *pvInstance, uint32_t ulRequest, void *pvRequestData)
{
    tBulkInstance *psInst;
    uint8_t *pucData;

    debug_printf("%s:%d. \n", __FUNCTION__, __LINE__ );
 
    /* Create the serial instance data. */
    psInst = ((tUSBDBulkDevice *)pvInstance)->psPrivateBulkData;

 
    /* Create the char array used by the events supported by the USB CDC */
    /* serial class. */
    pucData = (uint8_t *)pvRequestData;

    switch(ulRequest)
    {
     
        /* This was an interface change event. */
        case USB_EVENT_COMP_IFACE_CHANGE:
        {
            psInst->ucInterface = pucData[1];
            break;
        }

     
        /* This was an endpoint change event. */
        case USB_EVENT_COMP_EP_CHANGE:
        {
         
            /* Determine if this is an IN or OUT endpoint that has changed. */
            if(pucData[0] & USB_EP_DESC_IN)
            {
                psInst->ucINEndpoint = (pucData[1] & 0x7f);
            }
            else
            {
             
                /* Extract the new endpoint number. */
                psInst->ucOUTEndpoint = (pucData[1] & 0x7f);
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

/******************************************************************************
 *
 * This function is called by the USB device stack whenever the device is
 * disconnected from the host.
 *
 ****************************************************************************** */
static void
HandleDisconnect(void *pvInstance)
{
    const tUSBDBulkDevice *psBulkDevice;
    tBulkInstance *psInst;

    ASSERT(pvInstance != 0);

 
    /* Create the instance pointer. */
    psBulkDevice = (const tUSBDBulkDevice *)pvInstance;

 
    /* Get a pointer to our instance data. */
    psInst = psBulkDevice->psPrivateBulkData;

    /* cancel the previous semaphores if they are pended */
    if(psInst->eBulkRxState == BULK_STATE_WAIT_DATA)
    {
        usb_osalPostLock(psInst->readSem);
        psInst->eBulkRxState = BULK_STATE_UNCONFIGURED;
    }

    if(psInst->eBulkTxState == BULK_STATE_WAIT_DATA)
    {
        usb_osalPostLock(psInst->writeSem);
        psInst->eBulkTxState = BULK_STATE_UNCONFIGURED;
    }
 
    /* If we are not currently connected so let the client know we are open */
    /* for business. */
    if(psInst->bConnected)
    {
        /* Pass the disconnected event to the client. */
        psBulkDevice->pfnRxCallback(NULL,
                                    psBulkDevice->pvRxCBData,
                                    USB_EVENT_DISCONNECTED, 0, (void *)0);
    }

 
    /* Remember that we are no longer connected. */
    psInst->bConnected = FALSE;
}

/****************************************************************************** */
/* This function is called by the USB device stack whenever the bus is put into */
/* suspend state. */
/****************************************************************************** */
static void
HandleSuspend(void *pvInstance)
{
    const tUSBDBulkDevice *psBulkDevice;

    ASSERT(pvInstance != 0);

 
    /* Create the instance pointer. */
    psBulkDevice = (const tUSBDBulkDevice *)pvInstance;

 
    /* Pass the event on to the client. */
    psBulkDevice->pfnRxCallback(NULL,
                                psBulkDevice->pvRxCBData, 
                                USB_EVENT_SUSPEND, 0,
                                (void *)0);
}

/****************************************************************************** */
/* This function is called by the USB device stack whenever the bus is taken */
/* out of suspend state. */
/****************************************************************************** */
static void
HandleResume(void *pvInstance)
{
    const tUSBDBulkDevice *psBulkDevice;

    ASSERT(pvInstance != 0);

 
    /* Create the instance pointer. */
    psBulkDevice = (const tUSBDBulkDevice *)pvInstance;

 
    /* Pass the event on to the client. */
    psBulkDevice->pfnRxCallback(NULL, 
                                psBulkDevice->pvRxCBData, 
                                USB_EVENT_RESUME, 0,
                                (void *)0);
}

/**************************************************************************** 
* This function is called by the USB device stack whenever the device is 
* reset by the USB host
*****************************************************************************/
static void HandleReset(void *pvInstance)
{
    tBulkInstance *psInst;
    const tUSBDBulkDevice *psDevice;

    debug_printf("%s:%d. \n", __FUNCTION__, __LINE__ );

    ASSERT(pvInstance != 0);

    /* Create a device instance pointer. */
    psDevice = (const tUSBDBulkDevice *)pvInstance;

    /* Get a pointer to our instance data. */
    psInst = psDevice->psPrivateBulkData;

#if defined(SOC_AM571x) || defined (SOC_AM572x) || \
    defined(SOC_AM570x) || defined (SOC_AM574x) || \
    defined(SOC_DRA75x) || defined (SOC_DRA72x)

    /* on AM5xx, the USB disconnect event currently is missing.
     * a workaround for this issue is to call the disconnect 
     * handler in the reset handler so that disconnect handling
     * is still called, though it's a little delayed. 
     */
    HandleDisconnect(pvInstance);
 
#endif

    /* clear the transfer size */
    psInst->usLastRxSize = 0;
    psInst->usLastTxSize = 0;
}

/****************************************************************************** 
 *
 * Initializes bulk device operation for a given USB controller.
 *
 * \param ulIndex is the index of the USB controller which is to be 
 * initialized for bulk device operation.
 * \param psDevice points to a structure containing parameters customizing
 * the operation of the bulk device.
 *
 * An application wishing to make use of a USB bulk communication channel
 * must call this function to initialize the USB controller and attach the
 * device to the USB bus.  This function performs all required USB
 * initialization.
 *
 * On successful completion, this function will return the \e psDevice pointer
 * passed to it.  This must be passed on all future calls to the device driver
 * related to this device.
 *
 * \note The application must not make any calls to the low level USB Device
 * API if interacting with USB via the USB bulk device class API.  Doing so
 * will cause unpredictable (though almost certainly unpleasant) behavior.
 *
 * \return Returns NULL on failure or the psDevice pointer on success.
 *
 ****************************************************************************** */
void *
USBDBulkInit(void* pUsbGadgetObj, tUSBDBulkDevice *psDevice, USB_Params* pUsbParams)
{
    
    struct usbGadgetObj* pGadgetObj;

    /* Check parameter validity. */
    ASSERT(pUsbGadgetObj);
    ASSERT(psDevice);
    ASSERT(pUsbParams);

    USBDBulkCompositeInit(pUsbGadgetObj, psDevice, pUsbParams);

    /*
     * All is well so now pass the descriptors to the lower layer and put
     * the bulk device on the bus.
     */
    pGadgetObj = (struct usbGadgetObj*)pUsbGadgetObj;
    pGadgetObj->dcd.dcdActions.pFnDcInit(&(pGadgetObj->dcd));

    return ((void *)psDevice);
}

/******************************************************************************
 *
 * Initializes bulk device operation for a given USB controller.
 *
 * \param ulIndex is the index of the USB controller which is to be
 * initialized for bulk device operation.
 * \param psDevice points to a structure containing parameters customizing
 * the operation of the bulk device.
 *
 * An application wishing to make use of a composite
 * USB bulk communication channel needs to call this function.
 * This function is used for initializing an instance related information of the
 * bulk device.
 *
 * \return Returns zero on failure or a non-zero value that should be
 * used with the remaining USB HID Bulk APIs.
 *
 ****************************************************************************** */
void *
USBDBulkCompositeInit(void* pUsbGadgetObj, tUSBDBulkDevice *psDevice, USB_Params* pUsbParams)
{
    tBulkInstance *psInst;
    tDeviceDescriptor *psDevDesc;
    struct usbGadgetObj* pGadgetObj;

    /* Check parameter validity. */
    ASSERT(pUsbGadgetObj);
    ASSERT(psDevice);
    ASSERT(pUsbParams);
    ASSERT(psDevice->ppStringDescriptors);
    ASSERT(psDevice->psPrivateBulkData);
    ASSERT(psDevice->pfnRxCallback);
    ASSERT(psDevice->pfnTxCallback);


    pGadgetObj = (struct usbGadgetObj*)pUsbGadgetObj;

    /* Initialize the workspace in the passed instance structure. */
    psInst = psDevice->psPrivateBulkData;
    psInst->psConfDescriptor = (tConfigDescriptor *)g_pBulkDescriptor;
    psInst->psDevInfo = &g_sBulkDeviceInfo;

    psInst->eBulkRxState = BULK_STATE_UNCONFIGURED;
    psInst->eBulkTxState = BULK_STATE_UNCONFIGURED;
    psInst->usDeferredOpFlags = 0;
    psInst->bConnected = FALSE;

 
    /* Set the default endpoint and interface assignments. */
    psInst->ucINEndpoint = DATA_IN_ENDPOINT;
    psInst->ucOUTEndpoint = DATA_OUT_ENDPOINT;
    psInst->ucInterface = 0;

 
    /* Fix up the device descriptor with the client-supplied values. */
    psDevDesc = (tDeviceDescriptor *)psInst->psDevInfo->pDeviceDescriptor;
    psDevDesc->idVendor = psDevice->usVID;
    psDevDesc->idProduct = psDevice->usPID;

 
    /* Fix up the configuration descriptor with client-supplied values. */
    psInst->psConfDescriptor->bmAttributes = psDevice->ucPwrAttributes;
    psInst->psConfDescriptor->bMaxPower =
                        (uint8_t)(psDevice->usMaxPowermA / 2);

 
    /* Plug in the client's string stable to the device information */
    /* structure. */
    psInst->psDevInfo->ppStringDescriptors = 
                            (uint8_t **)psDevice->ppStringDescriptors;

    psInst->psDevInfo->ulNumStringDescriptors = 
                                    psDevice->ulNumStringDescriptors;

 
    /* Set the device instance. */
    psInst->psDevInfo->pvInstance = (void *)psDevice;
    psInst->psDevInfo->pGadgetObj = pGadgetObj;
    psInst->readSem               = pUsbParams->readSem;
    psInst->writeSem              = pUsbParams->writeSem;

    /* Set the pointer of bulk device in the gadget object */
    pGadgetObj->usbClass.privateData = psDevice;
    pGadgetObj->usbClass.classAction.epHandler = HandleEndpoints;

    /* Set the values of the descriptors required */
    /* Device descriptor */
    pGadgetObj->pDesc.pDeviceDesc = (usbDeviceDesc_t *)psInst->
                                                psDevInfo->pDeviceDescriptor;

    pGadgetObj->pDesc.ppConfigDesc = psInst->psDevInfo->ppConfigDescriptors;
    pGadgetObj->pDesc.ppStringDesc = (uint8_t**)psDevice->ppStringDescriptors;
    pGadgetObj->pDesc.numStringDesc = psDevice->ulNumStringDescriptors;

    /*  setup the device instance and pvInstance in dcd info */
    pGadgetObj->dcd.ptDeviceInfo = psInst->psDevInfo;

    /* Return the pointer to the instance indicating that everything went well. */
    return((void *)psDevice);
}

/******************************************************************************
 *
 * Shut down the bulk device.
 *
 * \param pvInstance is the pointer to the device instance structure as
 * returned by USBDBulkInit().
 *
 * This function terminates device operation for the instance supplied and
 * removes the device from the USB bus.  This function should not be called
 * if the bulk device is part of a composite device and instead the
 * USBDCompositeTerm() function should be called for the full composite
 * device.
 *
 * Following this call, the \e pvInstance instance should not me used in any
 * other calls.
 *
 * \return None.
 *
 ****************************************************************************** */
void
USBDBulkTerm(void *pvInstance)
{
    tBulkInstance *psInst;

    ASSERT(pvInstance);

    /*
     * Get a pointer to our instance data.
     */
    psInst = ((tUSBDBulkDevice *)pvInstance)->psPrivateBulkData;

    /*
     * Terminate the requested instance.
     */
    
    /*USBDCDTerm(0);*/

    psInst->psDevInfo = (tDeviceInfo *)0;
    psInst->psConfDescriptor = (tConfigDescriptor *)0;

    return;
}


/****************************************************************************** 
 *
 * Reports the device power status (bus- or self-powered) to the USB library. 
 *
 * \param pvInstance is the pointer to the bulk device instance structure. 
 * \param ucPower indicates the current power status, either \b 
 * USB_STATUS_SELF_PWR or \b USB_STATUS_BUS_PWR. 
 *
 * Applications which support switching between bus- or self-powered 
 * operation should call this function whenever the power source changes 
 * to indicate the current power status to the USB library.  This information 
 * is required by the USB library to allow correct responses to be provided 
 * when the host requests status from the device. 
 *
 * \return None. 
 *
 ****************************************************************************** */
void
USBDBulkPowerStatusSet(void *pvInstance, uint8_t ucPower)
{
    ASSERT(pvInstance);

 
    /* Pass the request through to the lower layer. */
    /*USBDCDPowerStatusSet(0, ucPower);*/
}

/****************************************************************************** 
 *
 * Requests a remote wake up to resume communication when in suspended state. 
 *
 * \param pvInstance is the pointer to the bulk device instance structure.
 *
 * When the bus is suspended, an application which supports remote wake up 
 * (advertised to the host via the configuration descriptor) may call this function 
 * to initiate remote wake up signaling to the host.  If the remote wake up 
 * feature has not been disabled by the host, this will cause the bus to 
 * resume operation within 20mS.  If the host has disabled remote wake up, 
 * \b FALSE will be returned to indicate that the wake up request was not 
 * successful. 
 *
 * \return Returns \b TRUE if the remote wake up is not disabled and the 
 * signaling was started or \b FALSE if remote wake up is disabled or if 
 * signaling is currently ongoing following a previous call to this function. 
 *
****************************************************************************** */
tBoolean
USBDBulkRemoteWakeupRequest(void *pvInstance)
{
    ASSERT(pvInstance);

    /* Pass the request through to the lower layer. */
    /* nothing for now */
    return TRUE;
}



/****************************************************************************** 
 *
 * send data via Bulk pipe. 
 *
 * Return 0 if nothing is sent
 * return the data size if it has no problem
 ******************************************************************************/
int32_t USBD_bulkWrite(USB_Handle handle, uint8_t* buffer, uint32_t dataSize)
{
    USB_Params* usbParams;
    tUSBDBulkDevice* pusbBulkDevice;
    tBulkInstance *psInst;
    int32_t retSize = 0;
    
    struct usbGadgetObj* pGadgetObj;

    usbParams = handle->usbParams; 
    pusbBulkDevice = (tUSBDBulkDevice*)usbParams->usbClassData;
    psInst = pusbBulkDevice->psPrivateBulkData;
    
    /* Setup request for the lower layer IN transfer */
    pGadgetObj = (struct usbGadgetObj*)psInst->psDevInfo->pGadgetObj;

    if (psInst->eBulkTxState == BULK_STATE_IDLE)
    {
        if ((dataSize <= DATA_IN_EP_MAX_SIZE) && (dataSize > 0))
        {
            psInst->eBulkTxState = BULK_STATE_WAIT_DATA;

            usbSetupEpReq(pGadgetObj,
                    psInst->ucINEndpoint,   /* IN EP # */
                    (uint32_t*)buffer,
                    USB_TOKEN_TYPE_IN,
                    dataSize,
                    USB_TRANSFER_TYPE_BULK);

            usb_osalPendLock(psInst->writeSem, SemaphoreP_WAIT_FOREVER);

            retSize = psInst->usLastTxSize;
        }
        else
        {
            retSize = 0;
        }
    }
    else
    {
        retSize = 0;
    }

    return retSize;
}


/****************************************************************************** 
 *
 * Receive data via Bulk pipe. 
 *
 * Only run this function after the bulk device has been configured 
 * Return 0 if nothing is received
 * return the data size if it has no problem
 ******************************************************************************/
int32_t USBD_bulkRead(USB_Handle handle, uint8_t* buffer, uint32_t* dataSize)
{
    USB_Params* usbParams;
    tUSBDBulkDevice* pusbBulkDevice;
    struct usbGadgetObj* pGadgetObj;
    tBulkInstance *psInst;
    int32_t size = 0;

    usbParams = handle->usbParams; 
    pusbBulkDevice = (tUSBDBulkDevice*)usbParams->usbClassData;
    psInst = pusbBulkDevice->psPrivateBulkData;
    
    /* Setup request for the lower layer OUT transfer */
    pGadgetObj = (struct usbGadgetObj*)psInst->psDevInfo->pGadgetObj;

    if (psInst->eBulkRxState == BULK_STATE_IDLE)
    {
        /* prepare for incoming bulk connection from host */
        *dataSize = psInst->usLastRxSize = 0;

        /* set state to waiting */
        psInst->eBulkRxState = BULK_STATE_WAIT_DATA;

        /* Setup request for the lower layer to be ready for OUT transfer */
        usbSetupEpReq(pGadgetObj,
                psInst->ucOUTEndpoint,
                (uint32_t*)buffer,
                USB_TOKEN_TYPE_OUT,
                DATA_OUT_EP_MAX_SIZE,
                USB_TRANSFER_TYPE_BULK);

        usb_osalPendLock(psInst->readSem, SemaphoreP_WAIT_FOREVER);
        *dataSize = psInst->usLastRxSize;

        size = psInst->usLastRxSize;
    }
    else 
    {
        size = 0;
    }

    return size;
}

/****************************************************************************** 
 *
 * Check if USB device is enumerated
 *
 * Return 1 if device has been enumerated and EP0 is in IDLE state
 * return 0 if not
 ******************************************************************************/
int32_t USBD_bulkEnumerated(USB_Handle handle)
{
    USB_Params* usbParams;
    tUSBDBulkDevice* pusbBulkDevice;
    struct usbGadgetObj* pGadgetObj;
    tBulkInstance *psInst;

    usbParams = handle->usbParams; 
    pusbBulkDevice = (tUSBDBulkDevice*)usbParams->usbClassData;
    psInst = pusbBulkDevice->psPrivateBulkData;
    
    /* Setup request for the lower lObj->ayer OUT transfer */
    pGadgetObj = (struct usbGadgetObj*)psInst->psDevInfo->pGadgetObj;
   
    if ((pGadgetObj->devState ==  USB_DEVICE_STATE_CONFIGURED))
    {
        return 1;
    } 
    else
    {
        return 0;
    } 
}

/****************************************************************************** 
 *
 * Close the Doxygen group.
 * @}
 *
 ****************************************************************************** */


