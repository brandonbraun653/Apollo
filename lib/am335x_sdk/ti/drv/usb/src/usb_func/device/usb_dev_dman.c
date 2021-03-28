/**
 * \file    usb_dev_dman.c
 *
 * \brief   This file implements the device manager functionality of the
 *          StarterWare USB device stack.
 *          This file defines the hardware resource map which lists contains
 *          device/gadget object.
 *
 */
/**
 *  Copyright (c) Texas Instruments Incorporated 2015-2019
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "error.h"
#include "debug.h"
#include "string.h"
/*Stack specific header files follow.*/

#include "usb_dev_object.h"
#include "usb_dev_dman.h"
#include "usblib.h"

#include "usbdevice.h"
#include "musb.h"
#include "usb_musb_dcd.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define DISABLE_FEATURE 0

/****************************************************************************** */
/* Mask used to preserve various endpoint configuration flags. */
/****************************************************************************** */
#define EP_FLAGS_MASK           (USB_EP_MODE_MASK | USB_EP_DEV_IN |           \
                                 USB_EP_DEV_OUT)


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static void USBDGetStatus(usbGadgetObj_t *pUsbGadgetObj,
                          usbSetupPkt_t * pSetup);

static void USBDSetAddress(usbGadgetObj_t *pUsbGadgetObj,
                           usbSetupPkt_t * pSetup);

static void USBDGetDescriptor(usbGadgetObj_t *pUsbGadgetObj,
                              usbSetupPkt_t * pSetup);

static void USBDSetConfiguration(usbGadgetObj_t *pUsbGadgetObj,
                                 usbSetupPkt_t * pSetup);

static void USBDSetInterface(usbGadgetObj_t *pUsbGadgetObj,
                                 usbSetupPkt_t * pSetup);

static void USBDevSetupDispatcher( usbGadgetObj_t *pUsbGadgetObj,
                                   usbSetupPkt_t * pSetup );


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/** \brief Function table to handle standard requests.*/

static const pFnStdRequest gUsbStdReqTable[] =
{
    USBDGetStatus, /*USBDGetStatus*/
    0, /*USBDClearFeature*/
    0,
    0, /*USBDSetFeature*/
    0,
    USBDSetAddress, /* USBDSetAddress */
    USBDGetDescriptor,/* USBDGetDescriptor */
    0, /*USBDSetDescriptor*/
    0, /*USBDGetConfiguration*/
    USBDSetConfiguration, /*USBDSetConfiguration*/
    0, /*USBDGetInterface*/
    USBDSetInterface, /*USBDSetInterface*/
    0, /*USBDSyncFrame*/
};

/** \brief List of gadget controllers present in the system.*/
usbGadgetObj_t gadgetList [ MAX_NUM_DEVICE_CONTROLLERS ];

/* non-cached buffers that gadget obj will use */
static uint8_t gadgetBuffer[MAX_NUM_DEVICE_CONTROLLERS][MAX_GADGET_BUFF_LEN] \
               __attribute__ ((section (".bss:extMemNonCache:usbXhci"))) \
               __attribute__ ((aligned (32)));


/** \brief Global variable to contain the request which is to be made to
 *         the lower layer driver.
 */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t USBDeviceInit( usbGadgetObj_t *pUsbGadgetObj, const char* pName )
{

    uint32_t initStatus = (uint32_t)E_FAIL;
    usbDevRequest_t* req;
    uint32_t epNum = 0;

    req = &(pUsbGadgetObj->requestbuf[epNum]);

    /* Initializing device request structure. */
    req->deviceAddress = 0U;
    req->pbuf = NULL;
    req->length = 0U;
    req->zeroLengthPacket = 0U;
    req->status = DEV_REQ_STATUS_SUBMIT;
    req->actualLength = 0U;
    req->deviceEndptInfo.endpointType = USB_TRANSFER_TYPE_CONTROL;
    req->deviceEndptInfo.endpointDirection = USB_TOKEN_TYPE_IN;
    req->deviceEndptInfo.MaxEndpointSize = 64U;
    req->deviceEndptInfo.endpointNumber = 0U;
    req->deviceEndptInfo.endpointInterval = 0xFF;

    if (NULL == pUsbGadgetObj)
    {
        /* Invalid parameters have been passed */
        initStatus = (uint32_t)E_INVALID_PARAM;
    }
    else
    {
        /* Start initialising the device object. */
        strncpy (pUsbGadgetObj->name, pName, MAX_GADGET_NAME_LEN-1);

        /* gadget functions */
        pUsbGadgetObj->dcd.gadgetObjCallBack.pFnDevEndpt0Handler =
                                                    USBDevEndpt0Handler;

    }
    return (initStatus);
}

void USBDInitCoreObject( void )
{
    const char * dcdName0 = "TIUSB_0";
    const char * dcdName1 = "TIUSB_1";

    memset(gadgetList, 0, sizeof(gadgetList));

    strncpy (gadgetList[0].name, dcdName0, MAX_GADGET_NAME_LEN-1);
    strncpy (gadgetList[1].name, dcdName1, MAX_GADGET_NAME_LEN-1);

    /* init the buffer pointers in gadgetObj */
    gadgetList[0].gadgetBufferPtr = gadgetBuffer[0];
    gadgetList[1].gadgetBufferPtr = gadgetBuffer[1];
}

void usbSetDeviceCharaParam (usbGadgetObj_t *pUsbGadgetObj,
                    usbDeviceDcdChara_t DcdChara, uint32_t value)
{
    switch (DcdChara)
    {
        case USB_DEVICE_DCD_CHARA_SPEED:
        pUsbGadgetObj->dcdCharecteristics.configparam = USB_DEVICE_DCD_CHARA_SPEED;
        pUsbGadgetObj->dcdCharecteristics.devSpeed           =  (usbSpeed_t)value;
        break;

        case USB_DEVICE_DCD_CHARA_ADDRESS:
        pUsbGadgetObj->dcdCharecteristics.configparam = USB_DEVICE_DCD_CHARA_ADDRESS;
        pUsbGadgetObj->dcdCharecteristics.deviceAddress      =  value;
        break;

        case USB_DEVICE_DCD_CHARA_REMOTE_WAKE:
        pUsbGadgetObj->dcdCharecteristics.configparam = USB_DEVICE_DCD_CHARA_REMOTE_WAKE;
        pUsbGadgetObj->dcdCharecteristics.enableRemoteWakeup =  value;
        break;

       case USB_DEVICE_DCD_EP_CONFIG:
       pUsbGadgetObj->dcdCharecteristics.configparam = USB_DEVICE_DCD_EP_CONFIG;
       pUsbGadgetObj->dcdCharecteristics.epConfigNo =  value;
       break;

       case USB_DEVICE_DCD_EP_INTERFACE:
       pUsbGadgetObj->dcdCharecteristics.configparam = USB_DEVICE_DCD_EP_INTERFACE;
       pUsbGadgetObj->dcdCharecteristics.epInterfaceNo =  value;
       break;
    }
}

uint32_t usbDeviceRemoteWakeEnable(usbGadgetObj_t   *pUsbGadgetObj,
                                   uint32_t         enableRemoteWake)
{

    uint32_t status;
    /* Call dcd function to enable remote wake up sigalling.*/
    usbSetDeviceCharaParam (pUsbGadgetObj,USB_DEVICE_DCD_CHARA_REMOTE_WAKE,
                            enableRemoteWake);

    status = pUsbGadgetObj->dcd.dcdActions.pFnConfigDevChara
                    (&(pUsbGadgetObj->dcd),&(pUsbGadgetObj->dcdCharecteristics));

    if (S_PASS == status)
    {
        pUsbGadgetObj->remoteWakeEnabled = enableRemoteWake ;
    }
    else
    {
        /* dcd remote wake up function failed !.*/
    }
    return status;
}


/*
This function handles bus reset notifications.

This function is called from the low level driver or dcd  whenever
a bus reset is detected.  It performs tidy-up as required and resets the
configuration back to defaults in preparation for descriptor queries from
the host.
*/

uint32_t USBDeviceEnumResetHandler(usbGadgetObj_t *pUsbGadgetObj)
{
    uint32_t status = S_PASS;

    /* Disable remote wake up signaling (as per USB 2.0 spec 9.1.1.6).*/
    usbDeviceRemoteWakeEnable(pUsbGadgetObj,DISABLE_FEATURE);

    /* Call the device dependent code to indicate a bus reset has occurred.*/

    /*Reset the default configuration identifier and alternate function
      selections. */

    /* 1.Set default config as the active configuration.*/
    /* 2. clear alternate setting */

    return status;
}
/* this is the main endpoint 0 handler This function calls the dispatcher if a
    pSetup packet is received.*/
uint32_t USBDevEndpt0Handler(struct usbGadgetObj *pUsbGadgetObj,
    usbEndpt0event_t endptEvent, usbSetupPkt_t * pSetup )
 {
    uint32_t status = S_PASS;

    debug_printf("%s:%d\n", __FUNCTION__, __LINE__);

    switch (endptEvent)
    {
        case USB_ENDPT0_EVENT_SETUP_PACKET_RECEIVED :
            USBDevSetupDispatcher (pUsbGadgetObj,pSetup);
            break;
        case USB_ENDPT0_EVENT_DATA_IN_NAK:
            break;
        case USB_ENDPT0_EVENT_DATA_IN_PARTIAL:
            break;
        case USB_ENDPT0_EVENT_DATA_IN_COMPLETE:
            break;
        case USB_ENDPT0_EVENT_DATA_OUT_NAK :
            break;
        case USB_ENDPT0_EVENT_DATA_OUT_PARTIAL :
            break;
        case USB_ENDPT0_EVENT_DATA_OUT_COMPLETE :
            break;
        case USB_ENDPT0_EVENT_DATA_TOGGLE_ERROR :
            break;
        case USB_ENDPT0_EVENT_TIMEOUT_ERROR :
            break;
        case USB_ENDPT0_EVENT_BUS_ERROR :
            break;
        default:
            break;
    }
    return status;
 }


/*
This internal function reads a request data packet and dispatches it to
either a standard request handler or the registered device request
callback depending upon the request type.
*/
static void USBDevSetupDispatcher( usbGadgetObj_t *pUsbGadgetObj,
usbSetupPkt_t * pSetup )
{

  /* See if this is a standard request or not.*/
    if((pSetup->bmRequestType & USB_RTYPE_TYPE_M) != USB_RTYPE_STANDARD)
    {
        /* Call the installed device handler */
        /* Debug routine ends */
        debug_printf("%s:%d. Gadget Request!\n", __FUNCTION__, __LINE__);

        /*Since this is not a standard request, see if there is
        an external handler present.*/
        if(pUsbGadgetObj->usbClass.classAction.ep0Handler)
        {
            /*Call the class specific handler.*/
            pUsbGadgetObj->usbClass.classAction.ep0Handler(pUsbGadgetObj,
                                                           USB_ENDPT0_EVENT_DATA_IN_COMPLETE,
                                                           pSetup);
        }
        else
        {
          /* If there is no handler then stall this request.*/
            debug_printf("%s:%d. Unsupported request (0x%x). Need to stall this request!!!\n", 
                         __FILE__, __LINE__, pSetup->bRequest);
        }
    }
    /* it is a standard request. */
    else
    {
        debug_printf("%s:%d. Standard Request!\n", __FUNCTION__, __LINE__);

        /* Assure that the jump table is not out of bounds.*/
        if((pSetup->bRequest <
           (sizeof(gUsbStdReqTable) / sizeof(pFnStdRequest))) &&
           (gUsbStdReqTable[pSetup->bRequest] != 0))
        {
            /* Jump table to the appropriate handler.*/
            gUsbStdReqTable[pSetup->bRequest](pUsbGadgetObj, pSetup);
        }
        else
        {
          /* If there is no handler then stall this request.*/
            debug_printf("Unsupported request (0x%x). Need to stall this request!!!\n", 
                         pSetup->bRequest);

        }
    }
}



/*
This function handles the SET_ADDRESS standard USB request.
*/


static void USBDSetAddress(usbGadgetObj_t *pUsbGadgetObj,
                           usbSetupPkt_t * pSetup )
{

    usbDevRequest_t* req;
    uint32_t epNum = 0;

    req = &(pUsbGadgetObj->requestbuf[epNum]);

    /*Return the ZLP .*/
    req->deviceAddress = pUsbGadgetObj->deviceAddress;
    req->pbuf = NULL;
    req->length = 0U;
    req->zeroLengthPacket = 1U;
    req->status = DEV_REQ_STATUS_SUBMIT;
    req->actualLength = 0U;
    req->deviceEndptInfo.endpointType = USB_TRANSFER_TYPE_CONTROL;
    req->deviceEndptInfo.endpointDirection = USB_TOKEN_TYPE_IN;

    req->deviceAddress = pSetup->wValue;
    pUsbGadgetObj->deviceAddress = pSetup->wValue;

    debug_printf("%s:%d. Addr = 0x%x\n", __FUNCTION__, __LINE__, req->deviceAddress);

    /* Transition directly to the status state since there is no data phase
    for this request.*/
    pUsbGadgetObj->dcd.dcdActions.pFnEndpt0Req(&(pUsbGadgetObj->dcd), req);

    /*We need to wait till the set address ACK phase is complete to change
    device address, but for now lets go ahead.*/

    usbSetDeviceCharaParam (pUsbGadgetObj,USB_DEVICE_DCD_CHARA_ADDRESS,
                            pUsbGadgetObj->deviceAddress);

    pUsbGadgetObj->dcd.dcdActions.
            pFnConfigDevChara (&(pUsbGadgetObj->dcd), 
                               &(pUsbGadgetObj->dcdCharecteristics));
}


static void USBDGetDescriptor(struct usbGadgetObj *pUsbGadgetObj,
        usbSetupPkt_t * pSetup)
{
    usbDevRequest_t* req;
    uint32_t epNum = 0;

    /* Which descriptor are we being asked for?*/
    usbConfigHeader_t *pConfigHeader;
    uint32_t loop = 0;
    uint8_t uIndex = 0;
    uint32_t length = 0;
    uint32_t section = 0;
    uint32_t numLang = 0;
    uint32_t numStringsPerLang = 0;
    usbString0Desc_t *pLang;

    req = &(pUsbGadgetObj->requestbuf[epNum]);

    switch(pSetup->wValue >> 8)
    {
        /*This request was for a device descriptor.*/
        case USB_DESC_TYPE_DEVICE:
        {
            debug_printf("%s:%d. Get Device Descriptor\n", __FUNCTION__, __LINE__);

            /*Return the externally provided device descriptor.*/
            req->deviceAddress = pUsbGadgetObj->deviceAddress;

            /* copy the device descriptor to a non-cached buffer that
             * is accessible by USB DMA */
            memcpy(pUsbGadgetObj->gadgetBufferPtr, 
                   pUsbGadgetObj->pDesc.pDeviceDesc,
                   pUsbGadgetObj->pDesc.pDeviceDesc->bLength);

            req->pbuf = pUsbGadgetObj->gadgetBufferPtr;
            req->length = (uint32_t ) pUsbGadgetObj->pDesc.pDeviceDesc->bLength;

            req->zeroLengthPacket = 0U;
            req->status = DEV_REQ_STATUS_SUBMIT;
            req->actualLength = 0U;
            req->deviceEndptInfo.endpointType = USB_TRANSFER_TYPE_CONTROL;
            req->deviceEndptInfo.endpointDirection = USB_TOKEN_TYPE_IN;
            req->reqComplete = usbEp0reqComplete;

            pUsbGadgetObj->dcd.dcdActions.pFnEndpt0Req(&(pUsbGadgetObj->dcd), req);
            break;
        }

        /*This request was for a configuration descriptor.*/
        case USB_DESC_TYPE_CONFIGURATION:
        {
            debug_printf("%s:%d. Get Configuration Descriptor\n", __FUNCTION__, __LINE__);

            uIndex = (uint8_t)(pSetup->wValue & 0xFF);

            if(uIndex >=
                pUsbGadgetObj->pDesc.pDeviceDesc->bNumConfigurations)
            {
                /*This is an invalid configuration index.  Stall EP0 to
                indicate a request error.*/
                /* Stall are yet to be implemented */
            }
            else
            {
                /*Return the externally provided device descriptor.*/
                req->deviceAddress = pUsbGadgetObj->deviceAddress;
                pConfigHeader = pUsbGadgetObj->pDesc.ppConfigDesc[uIndex];
                req->pbuf = pUsbGadgetObj->gadgetBufferPtr;
                memcpy((uint32_t *)req->pbuf,
                       pConfigHeader->pConfigSections[section]->pData,
                       pConfigHeader->pConfigSections[section]->size);
                req->length = 0;
                /* Computing the length of the configuration descriptor */
                for (loop = 0; loop < pConfigHeader->numSections; loop++)
                {
                   req->length += pConfigHeader->pConfigSections[loop]->size;
                }

                length = req->length - pConfigHeader->pConfigSections[section]->size;
                req->pbuf = (uint8_t *)req->pbuf + pConfigHeader->pConfigSections[section]->size;
                while(length)
                {
                    section++;
                    memcpy((uint32_t *)req->pbuf,
                           pConfigHeader->pConfigSections[section]->pData,
                           pConfigHeader->pConfigSections[section]->size);
                    length -= pConfigHeader->pConfigSections[section]->size;
                    req->pbuf = (uint8_t *)req->pbuf + pConfigHeader->pConfigSections[section]->size;
                }
                req->pbuf = (uint8_t *)req->pbuf - req->length;
                if (0x09 == pSetup->wLength)
                {
                    req->length = 9U;
                }
                req->zeroLengthPacket = 0U;
                req->status = DEV_REQ_STATUS_SUBMIT;
                req->actualLength = 0U;
                req->deviceEndptInfo.endpointType = USB_TRANSFER_TYPE_CONTROL;
                req->deviceEndptInfo.endpointDirection = USB_TOKEN_TYPE_IN;

                pUsbGadgetObj->dcd.dcdActions.pFnEndpt0Req(&(pUsbGadgetObj->dcd), req);

            }
            break;
        }

        /*This request was for a string descriptor.*/

        case USB_DESC_TYPE_STRING:
        {
            debug_printf("%s:%d. Get String Descriptor\n", __FUNCTION__, __LINE__);
            /* TODO put proper comments here */
            numLang = (pUsbGadgetObj->pDesc.ppStringDesc[0][0] - 2) / 2;
            /* TODO put comment here */
            numStringsPerLang = ((pUsbGadgetObj->pDesc.numStringDesc - 1) /
                                 numLang);
            pLang = (usbString0Desc_t *)pUsbGadgetObj->pDesc.ppStringDesc[0];
            for(loop = 0; loop < numLang; loop++)
            {
                if(pLang->wLangId[loop] == pSetup->wIndex)
                {
                    uIndex = (numStringsPerLang * loop) + (pSetup->wValue & 0xFF);
                    break;
                }
            }
            if (loop == numLang)
            {
               /* Stall the endpoint as some error has occured */
            }

            /* Length is in byte 0 of the string descriptor */
            req->length = pUsbGadgetObj->pDesc.ppStringDesc[uIndex][0];

            /* copy the string to DMA-aware buffer */
            memcpy(pUsbGadgetObj->gadgetBufferPtr, 
                   pUsbGadgetObj->pDesc.ppStringDesc[uIndex],
                   req->length);

            req->pbuf = pUsbGadgetObj->gadgetBufferPtr;
            req->deviceAddress = pUsbGadgetObj->deviceAddress;
            req->zeroLengthPacket = 0U;
            req->status = DEV_REQ_STATUS_SUBMIT;
            req->actualLength = 0U;
            req->deviceEndptInfo.endpointType = USB_TRANSFER_TYPE_CONTROL;
            req->deviceEndptInfo.endpointDirection = USB_TOKEN_TYPE_IN;

            pUsbGadgetObj->dcd.dcdActions.
                                    pFnEndpt0Req(&(pUsbGadgetObj->dcd), req);
            break;
        }

        /*Any other request is not handled by the default enumeration handler
        so see if it needs to be passed on to another handler.*/

        default:
        {
            debug_printf("%s:%d. Dont know this Get Descriptor request\n", 
                         __FUNCTION__, __LINE__);
            break;
        }
    }
}


static void USBDGetStatus(usbGadgetObj_t *pUsbGadgetObj,
                          usbSetupPkt_t * pSetup)
{
    uint16_t data = 0;
    usbDevRequest_t* req;
    uint32_t epNum = 0;

    req = &(pUsbGadgetObj->requestbuf[epNum]);
 
    debug_printf("%s:%d\n", __FUNCTION__, __LINE__);
    /* Determine which type of status was requested */
    switch(pSetup->bmRequestType & USB_RTYPE_RECIPIENT_M)
    {
        case USB_RTYPE_DEVICE:
            /* Return the current status for the device */
            /* TODO Check how this status is to be stored and where */
            data = 0;
            break;
        case USB_RTYPE_INTERFACE:
            data = 0;
            break;
        case USB_RTYPE_ENDPOINT:
            /* TODO Check logic on how to return this status for endpoints */
            data = 0;
            break;
        default:
            /* Set endpoint stall */
            break;
    }
    
    pUsbGadgetObj->gadgetBufferPtr[0] = data;

    /* Setup the request and send the USB status */
    req->deviceAddress = pUsbGadgetObj->deviceAddress;
    req->pbuf = pUsbGadgetObj->gadgetBufferPtr;
    req->length = 2U;
    req->zeroLengthPacket = 0U;
    req->status = DEV_REQ_STATUS_SUBMIT;
    req->actualLength = 0U;
    req->deviceEndptInfo.endpointType = USB_TRANSFER_TYPE_CONTROL;
    req->deviceEndptInfo.endpointDirection = USB_TOKEN_TYPE_IN;
    req->reqComplete = usbEp0reqComplete;

    pUsbGadgetObj->dcd.dcdActions.pFnEndpt0Req (&(pUsbGadgetObj->dcd), req);

}


static void USBDSetConfiguration(usbGadgetObj_t *pUsbGadgetObj,
                                 usbSetupPkt_t * pSetup )
{
    usbDevRequest_t* req;
    uint32_t epNum = 0;

    req = &(pUsbGadgetObj->requestbuf[epNum]);

    /*Return the ZLP(Zero length packet).*/
    req->deviceAddress = pUsbGadgetObj->deviceAddress;
    req->pbuf = NULL;
    req->length = 0U;
    req->zeroLengthPacket = 1U;
    req->status = DEV_REQ_STATUS_SUBMIT;
    req->actualLength = 0U;
    req->deviceEndptInfo.endpointType = USB_TRANSFER_TYPE_CONTROL;
    req->deviceEndptInfo.endpointDirection = USB_TOKEN_TYPE_OUT;

    /* Transition directly to the status state since there is no data phase
    for this request i.e. it is a 2 stage transfer*/

    /* Set the asked configuration */
    usbSetDeviceCharaParam (pUsbGadgetObj, USB_DEVICE_DCD_EP_CONFIG,
                            pSetup->wValue);

    pUsbGadgetObj->dcd.dcdActions.
                        pFnConfigDevChara(&(pUsbGadgetObj->dcd),
                                          &(pUsbGadgetObj->dcdCharecteristics));

    /* send ACK for EP0 */
    pUsbGadgetObj->dcd.dcdActions.pFnEndpt0Req(&(pUsbGadgetObj->dcd), req);

    /* Call the enumeration complete so that it will setup the USB for
     * first OUT request
     */
    if(pUsbGadgetObj->usbClass.classAction.enumComplete)
    {
        /* If the enum complete handler has been installed, call it */
        pUsbGadgetObj->usbClass.classAction.enumComplete(pUsbGadgetObj);
    }

    pUsbGadgetObj->devState = USB_DEVICE_STATE_CONFIGURED;

    debug_printf("%s:%d. USB DEV is now configured\n", __FUNCTION__, __LINE__);

}
static void
USBDSetInterface(usbGadgetObj_t *pUsbGadgetObj,
                                 usbSetupPkt_t * pSetup )
{
    tDeviceInfo *psDevice;

    /* get tDeviceInfo pointer */
    psDevice = (tDeviceInfo *)pUsbGadgetObj->dcd.ptDeviceInfo;

   /* Set the asked interface */
    usbSetDeviceCharaParam (pUsbGadgetObj, USB_DEVICE_DCD_EP_INTERFACE,
                            pSetup->wIndex);
    /* If any alternate configuration is requested by host, this epConfigNo
     * variable value will be used to change the configuration.
     */
    pUsbGadgetObj->dcdCharecteristics.epConfigNo = pSetup->wValue;

    pUsbGadgetObj->dcd.dcdActions.pFnConfigDevChara(&(pUsbGadgetObj->dcd),
                                          &(pUsbGadgetObj->dcdCharecteristics));
    /*
     * If there is a callback then notify the application of the
     * change to the alternate interface.
     */
    if (psDevice->sCallbacks.pfnInterfaceChange)
    {
        debug_printf("%s:%d, call pfnInterfaceChange\n", __FUNCTION__, __LINE__);
        psDevice->sCallbacks.pfnInterfaceChange(
                                        pUsbGadgetObj,
                                        pSetup->wIndex,
                                        pSetup->wValue);
    }
}

void usbEpreqComplete(struct usbGadgetObj * pUsbGadgetObj,
    struct usbDevRequest *pReq)
{
    uint32_t epNo = 0;

    debug_printf("%s:%d\n", __FUNCTION__, __LINE__);

    epNo = pReq->deviceEndptInfo.endpointNumber;

    /* mark request being completed */
    pReq->status = DEV_REQ_STATUS_COMPLETE;

    /* Ep request has been completed, call the class specific endpoint handler */
    if (USB_TOKEN_TYPE_IN == pReq->deviceEndptInfo.endpointDirection)
    {
        pUsbGadgetObj->usbClass.classAction.epHandler(pUsbGadgetObj,
                                                      USB_GENERIC_EVENT_DATA_IN_COMPLETE,
                                                      epNo,
                                                      pReq->length);
    }
    else
    {
        pUsbGadgetObj->usbClass.classAction.epHandler(pUsbGadgetObj,
                                                      USB_GENERIC_EVENT_DATA_OUT_COMPLETE,
                                                      epNo,
                                                      pReq->length);
    }
}

void usbEp0reqComplete(struct usbGadgetObj * pUsbGadgetObj,
    struct usbDevRequest *pReq)
{
    uint32_t epNum = 0;
    debug_printf("%s:%d\n", __FUNCTION__, __LINE__);

    usbEndptRequest_t* req;

    /* get the request for endpoint 0 */
    req = &(pUsbGadgetObj->requestbuf[epNum]);

   /* Endpoint 0 request has been completed,
    * so necessary action need to be taken
    */
   if (USB_TOKEN_TYPE_IN == req->deviceEndptInfo.endpointDirection)
    {
       if (1u == req->zeroLengthPacket)
       {
            /* do nothing*/
       }
       else
       {
        /* it was the data stage of the device descriptor. */
        /*Return the ZLP .*/
        req->deviceAddress = pUsbGadgetObj->deviceAddress;
        req->pbuf = NULL;
        req->length = 0U;
        req->zeroLengthPacket = 1U;
        req->status = DEV_REQ_STATUS_SUBMIT;
        req->actualLength = 0U;
        req->deviceEndptInfo.endpointType = USB_TRANSFER_TYPE_CONTROL;
        req->deviceEndptInfo.endpointDirection = USB_TOKEN_TYPE_OUT;
        req->reqComplete = usbEp0reqComplete;
        pUsbGadgetObj->dcd.dcdActions.pFnEndpt0Req(&(pUsbGadgetObj->dcd), req);
      }
    }
   else
    {
        /* No Action required here */
    }


}

void usbSetupEpReq(void * pUsbGadgetObj,
    uint32_t epNum, uint32_t * pUsbData, usbTokenType_t tokenType,
    uint32_t length, usbTransferType_t transferType)
{
    /* Setup endpoint request for the required endpoint */
    struct usbGadgetObj * pGadgetObj = ((struct usbGadgetObj *) pUsbGadgetObj);
    usbDevRequest_t*      req = 0;

    /* getting pointer to the request_t for this endpoint */
    if (epNum < MAX_NUM_REQUESTS)
    {        
        req = &(pGadgetObj->requestbuf[epNum]);
    }

    if (req != 0)
    {
        req->deviceAddress = pGadgetObj->deviceAddress;
        req->pbuf = pUsbData;
        req->length = length;
        req->zeroLengthPacket = 0U;
        req->status = DEV_REQ_STATUS_SUBMIT;
        req->actualLength = 0U;
        req->deviceEndptInfo.endpointType = transferType;
        req->deviceEndptInfo.endpointDirection = tokenType;
        req->deviceEndptInfo.endpointNumber = epNum;

        debug_printf("%s:%d. epNum = 0x%x\n", __FUNCTION__, __LINE__, epNum);
        if(0U == epNum)
        {
            req->reqComplete = usbEp0reqComplete;
            pGadgetObj->dcd.dcdActions.pFnEndpt0Req(&(pGadgetObj->dcd), req);
        }
        else
        {
            req->reqComplete = usbEpreqComplete;
            pGadgetObj->dcd.dcdActions.pFnEndptReq(&(pGadgetObj->dcd), req);
        }
    }
}

