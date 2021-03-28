/**
 *  \file  usb_Musb_dcd.c
 *
 *  \brief MUSB driver wrapper. 
 *
 *  \copyright Copyright (C) 2015-2019 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "hw_types.h"
#include "usblib.h"
#include "musb.h"
#include "usb_dev_object.h"
#include "usb_musb_dcd.h"
#include "usbdevice.h"
#include "usb_osal.h"

/* field for error handling */
#include "error.h"
#include "debug.h"

#ifdef DMA_MODE
#include "cppi41dma.h"
#endif

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* This is a flag used with g_sUSBDeviceState.ulDevAddress to indicate that a */
/* device address change is pending. */
#define DEV_ADDR_PENDING        0x80000000


/*****************************************************************************
 DMA configuration Parameters 
*****************************************************************************/
#define MAX_TRANSFER_SIZE       USB_PACKET_LENGTH
#define DMA_TX_MAX_CHUNK_SIZE   (MAX_TRANSFER_SIZE*8)  /* 512 blocks size, 8 blocks */
#define DMA_RX_MAX_CHUNK_SIZE   MAX_TRANSFER_SIZE      /* 1 block */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/****************************************************************************** */
/* The FIFO configuration for USB mass storage class device. */
/****************************************************************************** */

/****************************************************************************** */
/*! The default USB endpoint FIFO configuration structure.  This structure */
/*! contains definitions to set all USB FIFOs into single buffered mode with */
/*! no DMA use.  Each endpoint's FIFO is sized to hold the largest maximum */
/*! packet size for any interface alternate setting in the current */
/*! configuration descriptor.  A pointer to this structure may be passed in the */
/*! psFIFOConfig field of the tDeviceInfo structure passed to USBCDCInit if the */
/*! application does not require any special handling of the USB controller */
/*! FIFO. */
/****************************************************************************** */
const tFIFOConfig g_sUSBDefaultFIFOConfig =
{
    {
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 }
    },
    {
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 },
        { 1, false, 0 }
    },
};


/* ========================================================================== */
/*                 External Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief Perform the core operations required
 *        on receiving USB reset Event
 *
 * \param Musb pointer to the Musb device object
 */
void usbMusbDcdRstEvntHandler(usbMusbDcdDevice_t *musb);

/**
 * \brief Perform the operations required on connect
 *        done event.
 *
 * \param Musb Pointer to the Musb device object
 */
void usbMusbDcdCnctDoneEvntHandler(usbMusbDcdDevice_t *musb);

/**
 * \brief EP0 interrupt handler(Default control endpoint)
 *        All other endpoint interrupts are handled separetely.
 *
 * \param Musb pointer to the Musb device object
 */
void usbMusbDcdEp0EvntHandler(usbMusbDcdDevice_t *musb);

/**
 * \brief usb main interrupt handler
 *
 * \param Musb pointer to the Musb device object.
 *
 */
void usbMusbDcdCoreIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam);

/**
 * \brief This function sets or clear endpoint stall.
 *
 * \param Musb pointer to the Musb device object
 * \param phEpId Physical endpoint number for which the stall has to be
 *        set or cleared.
 * \param flag - TRUE - set stall
 *        flag - FLASE - clear stall
 */
void usbMusbDcdSetEpStall(usbMusbDcdDevice_t *musb, uint32_t phEpId, uint32_t flag);

/**
 * \brief This API is called when the set configuration request comes from the
 *        host driver.
 *
 * \param Musb pointer to the Musb device object
 */
void usbMusbDcdSetConfiguration(usbMusbDcdDevice_t *musb);

/**
 * \brief This API is called when the set interface request comes from the
 *        host driver.
 *
 * \param Musb pointer to the Musb device object
 */
void usbMusbDcdSetInterface(usbMusbDcdDevice_t *musb, tDeviceInfo *psDeviceInfo);



/*
 * handling EP0 transmisstion state
 */
static void USBDEP0StateTx(usbMusbDcdDevice_t *musb);

uint32_t usbMusbDcdDeviceConfig(usbMusbDcdDevice_t* musb, 
                                const usbConfigHeader_t *psConfig,
                                const tFIFOConfig *psFIFOConfig);

static uint32_t
GetEndpointFIFOSize(uint32_t ulMaxPktSize, const tFIFOEntry *psFIFOParams,
                    uint32_t *pupBytesUsed);

static void
GetEPDescriptorType(tEndpointDescriptor *psEndpoint, uint32_t *pulEPIndex,
                    uint32_t *pulMaxPktSize, uint32_t *pulFlags);
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* The buffer for reading data coming into EP0 */
static unsigned char g_pucDataBufferIn[EP0_MAX_PACKET_SIZE];

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**  
 * \brief  set USB to full speed
 *
**/
void UsbMusbDcdFullSpeedSet(uint32_t baseAddr)
{
	HWREGB(baseAddr + USB_O_POWER) &= 0xdf;
}

uint32_t USBMusbDcdInit(struct usbDcd *pDcdObject)
{
    /* Retrieve private data from core object */
    usbMusbDcdDevice_t *musb = (usbMusbDcdDevice_t *)(pDcdObject->privateData);


    USBModuleClkEnable(musb->controllerId, musb->baseAddr);
    USBReset(musb->uiSubBaseAddr);
    // USB 1.1?
   if (pDcdObject->pGadgetObject->pDesc.pDeviceDesc->bcdUSB==0x110)
   {
       /* Set USB full speed */
       UsbMusbDcdFullSpeedSet(musb->baseAddr);
   };
   
    /* Turn on USB Phy clock. */
    UsbPhyOn(musb->phyBaseAddr);


    /* Make sure we disconnect from the host for a while.  This ensures */
    /* that the host will enumerate us even if we were previously */
    /* connected to the bus. */
    USBDevDisconnect(musb->baseAddr);

    /* Wait about 100mS. */
    usb_osalDelayMs(100);

    /* Attach the device using the soft connect. */
    USBDevConnect(musb->baseAddr);

    return S_PASS;
}

uint32_t USBMusbDcdConfigDevChara( struct usbDcd * pDcdObject,
                                   usbDevChara_t * pDevCharecteristic)
{
    /* Retrieve private data from core object */
    usbMusbDcdDevice_t *musb = (usbMusbDcdDevice_t *)(pDcdObject->privateData);

    debug_printf("%s:%d. configparam=0x%x\n", 
                __FUNCTION__, __LINE__, 
                pDevCharecteristic->configparam);

    switch(pDevCharecteristic->configparam)
    {
        case USB_DEVICE_DCD_CHARA_SPEED:
            /* This will be handled later */
            break;
        case USB_DEVICE_DCD_CHARA_ADDRESS:
            /* Set the address of the device */
            musb->devAddr = pDevCharecteristic->deviceAddress;
            musb->deviceNewAddrValidFlag = 1U;

            /* Save the device address as we cannot change address until the status */
            /* phase is complete. */
            musb->deviceInstance.ulDevAddress = musb->devAddr | DEV_ADDR_PENDING;

            /* Need to ACK the data on end point 0 with last data set as this has no */
            /* data phase. */
            USBDevEndpointDataAck(musb->baseAddr, USB_EP_0, true);

            /* Transition directly to the status state since there is no data phase */
            /* for this request. */
            musb->deviceInstance.eEP0State = USB_MUSB_STATE_STATUS;

            break;

        case USB_DEVICE_DCD_EP_CONFIG:
            /* Set endpoint configurations */
            musb->deviceInstance.ulConfiguration = (uint8_t)pDevCharecteristic->epConfigNo;
            usbMusbDcdSetConfiguration(musb);
            break;

        case USB_DEVICE_DCD_EP_INTERFACE:
            /* Set endpoint interafces */
            musb->deviceInstance.ulInterface = pDevCharecteristic->epInterfaceNo;
            musb->deviceInstance.ulAlternateConfig = pDevCharecteristic->epConfigNo;
			usbMusbDcdSetInterface(musb, pDcdObject->ptDeviceInfo);
            break;

        default :
            /* error condition on default */
            break;
    }
    return S_PASS;
}

/****************************************************************************** */
/****************************************************************************** */
uint32_t USBMusbDcdEp0Req( struct usbDcd *pDcdObject,
    usbEndpt0Request_t* req)
{
    /* Retrieve private data from core object */
    usbMusbDcdDevice_t *musb = (usbMusbDcdDevice_t *)(pDcdObject->privateData);

    debug_printf("%s:%d. State=%d. req->length=%d\n", __FUNCTION__, __LINE__, 
                (musb->deviceInstance.eEP0State), req->length);

    /* Check which kind of transfer has been requested */
    switch(musb->deviceInstance.eEP0State)
    {
        case USB_MUSB_STATE_IDLE:
            if(1U == req->zeroLengthPacket)
            {
                /* It is a 2 state request, no data phase */
                /* EP0 remains in IDLE state when there is no data phase */
                musb->deviceInstance.eEP0State = USB_MUSB_STATE_IDLE; 
            }
            else
            {
                /* This is a 2 state request */
                if(USB_TOKEN_TYPE_IN == req->deviceEndptInfo.endpointDirection)
                {
                    /* This is a in data request */
                    musb->deviceInstance.eEP0State = USB_MUSB_STATE_TX;

                    musb->deviceInstance.pEP0Data = req->pbuf;
                    musb->deviceInstance.ulEP0DataRemain = req->length;
                    musb->deviceInstance.ulOUTDataSize = req->length;

                    USBDEP0StateTx(musb);
                } 
                else if(USB_TOKEN_TYPE_OUT == req->deviceEndptInfo.endpointDirection)
                {
                    /* This is a out data request */
                    musb->deviceInstance.eEP0State = USB_MUSB_STATE_RX;

                    
                    musb->deviceInstance.pEP0Data = req->pbuf;
                    musb->deviceInstance.ulEP0DataRemain = req->length;
                    musb->deviceInstance.ulOUTDataSize = req->length;

                }
            }
            break;
        default:
            /* This condition is not taken care of, error */
            break;
    }
    return S_PASS;
}

/****************************************************************************** */
/****************************************************************************** */
uint32_t USBMusbDcdEpReq( struct usbDcd *   pDcdObject,
                          usbEndptRequest_t* req)
{
    /* Retrieve private data from core object */
    usbMusbDcdDevice_t *musb = (usbMusbDcdDevice_t *)(pDcdObject->privateData);
    uint32_t    epNum;
    uint32_t    isConfigured;
    uint8_t*    rxBuffer;

    epNum = req->deviceEndptInfo.endpointNumber;

    debug_printf("%s:%d. epNum=0x%x\n", __FUNCTION__, __LINE__, epNum);

    isConfigured = (musb->pDcdCore->pGadgetObject->devState == 
                                            USB_DEVICE_STATE_CONFIGURED);
   
    if (isConfigured == 0) 
    {
        /* not yet configured. Don't expect to use unconfigured endpoints.         */
        debug_printf("%s:%d. not yet configured\n", __FUNCTION__, __LINE__);
        return S_PASS;
    }


    if(USB_TOKEN_TYPE_IN == req->deviceEndptInfo.endpointDirection)
    {
        musb->inEpReq = req;
        musb->lastReqDirection = MUSB_DCD_EP_DIR_IN;

        debug_printf("sending %02x %02x %02x %02x %02x...\n", 
                     ((uint8_t*)req->pbuf)[0], 
                     ((uint8_t*)req->pbuf)[1], 
                     ((uint8_t*)req->pbuf)[2], 
                     ((uint8_t*)req->pbuf)[3],
                     ((uint8_t*)req->pbuf)[4]
                    );
        
#ifdef DMA_MODE
        /* update request status */
        req->status = DEV_REQ_STATUS_BEING_PROCESSED;
        /* using DMA to dump data into USB core for sending data to host
           Associate application provided data buffer into a packet descriptor */
        doDmaTxTransfer(musb->controllerId, (uint8_t*)req->pbuf,
                       req->length, INDEX_TO_USB_EP(epNum));

#else
        /* FIFO mode */
        /* taking the endpoint number from the dcd data (req) and
           convert it to the end point value that the hw uses. */
        USBEndpointDataPut(musb->baseAddr,  INDEX_TO_USB_EP(epNum), 
                           req->pbuf, 
                           req->length);

        USBEndpointDataSend(musb->baseAddr, INDEX_TO_USB_EP(epNum), USB_TRANS_IN);
#endif

    }
    else
    {
        /* we're expecting incoming data from host (OUT req) */
        musb->lastReqDirection = MUSB_DCD_EP_DIR_OUT;

        /* save the pointer of the request */
        musb->outEpReq = req;

        /* No preparation needed for the hw to receive data. */
        /* actual receving is handling at the interrupt handler. */

        /* debug code: */
        if (isConfigured) 
        {
            debug_printf("waiting for incoming BULK OUT\n");
        }

#ifdef DMA_MODE

#ifdef DMA_MULTIBUFFER_ALLOCATION
        /* OMAP requires this mode while AM335x does not */
        rxBuffer = (uint8_t*)cppiDmaAllocBuffer();
#else
        rxBuffer = req->pbuf;
#endif

        /* Need to replenish the RX queue with BD. associate the application 
        provided buffer to a BD and put it into RX free queue */
        doDmaRxTransfer(musb->controllerId, req->length, 
                        (uint8_t*)rxBuffer, INDEX_TO_USB_EP(epNum));

        /* mark request for being processed */
        req->status = DEV_REQ_STATUS_BEING_PROCESSED;
#endif
    }

    return S_PASS;
}

void consolePrintf(const char *pcString, ...);

/****************************************************************************** */
/****************************************************************************** */
uint32_t USBMusbDcdIntrHandler(usbMusbDcdDevice_t *musb)
{
    uint32_t      ulStatus;
    tDeviceInfo*  ptDeviceInfo;
    uint16_t      outEpNumber = 0;
    uint32_t      epNum;

    usbDevRequest_t*      req = 0;

    musb->ulIrqStatus |= USBIntStatusControl(musb->baseAddr);  

    ulStatus = musb->ulIrqStatus;

    musb->ulUSBIntCount++;

    /* Received a reset from the host. */
    if(ulStatus & USB_INTCTRL_RESET)
    {
        debug_printf(".\n");
        musb->ulUSBRstCount++;
        usbMusbDcdRstEvntHandler(musb);
        return 0;
    }

    /* USB device was disconnected. */
    if(ulStatus & USB_INTCTRL_DISCONNECT)
    {
        ptDeviceInfo = (tDeviceInfo*)musb->pDcdCore->ptDeviceInfo;

        /* Call the DisconnectHandler() if it was specified. */
        if (ptDeviceInfo->sCallbacks.pfnDisconnectHandler)
        {
            ptDeviceInfo->sCallbacks.pfnDisconnectHandler(ptDeviceInfo->pvInstance);
        }

#ifdef DMA_MODE
        /* clean up DMA buffer descriptors that are in the RX Queue */
        /* doing this only after we have setup the DMA for the OUT transaction */
        /* skipping endpoint 0 since we don't do DMA on EP0 */
        for (epNum = 1; epNum<MAX_NUM_REQUESTS; epNum++)
        {
            req = &(musb->pDcdCore->pGadgetObject->requestbuf[epNum]);

            /* looking for pending OUT request that has setup DMA transaction */
            if ((USB_TOKEN_TYPE_OUT == req->deviceEndptInfo.endpointDirection) &&
                (req->status == DEV_REQ_STATUS_BEING_PROCESSED))
            {
                debug_printf("^^\n");
                outEpNumber = req->deviceEndptInfo.endpointNumber;

                /* convert the number for MUSB */
                outEpNumber = INDEX_TO_USB_EP(outEpNumber);
                Cppi41DmaRxChTeardown (musb->controllerId, outEpNumber);

                req->status = DEV_REQ_STATUS_COMPLETE;
            }
        }
#endif

        musb->deviceInstance.eEP0State = USB_MUSB_STATE_IDLE;
        return 0;
    }

    /* Start of Frame was received. */
    if(ulStatus & USB_INTCTRL_SOF)
    {
        /* Increment the global Start of Frame counter. */
        musb->ulUSBSOFCount++;
        
        /* do we neeed to handle this SOF for MSC app? */
        /*return 0; */
    }


    /* Handle end point 0 interrupts. */
    if(musb->epIrqStatus & USB_INTEP_0)
    {
        debug_printf(".\n");
        musb->ulUSBEP0IntCount++;
        usbMusbDcdEp0EvntHandler(musb);
    }
 
#ifdef DMA_MODE
    DMAQueuePendHandler((void *)musb);
#endif    

    /* Other endpoint and device interrupts */
    if (musb->epIrqStatus & 0xFFFEFFFE) 
    {   
        debug_printf("+\n");
        musb->ulUSBEPIntCount++;

        usbMusbDcdEpEvntHandler(musb);
    }

    return 0;

} /* USBMusbDcdIntrHandler */

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

void usbMusbDcdRstEvntHandler(usbMusbDcdDevice_t *musb)
{
    debug_printf("%s:%d\n", __FUNCTION__, __LINE__);
    /* Disable remote wake up signaling (as per USB 2.0 spec 9.1.1.6). */
    musb->deviceInstance.ucStatus &= ~USB_STATUS_REMOTE_WAKE;
    musb->deviceInstance.bRemoteWakeup = false;

    /* Reset the default configuration identifier and alternate function */
    /* selections. */
    musb->deviceInstance.ulConfiguration = musb->deviceInstance.ulDefaultConfiguration;
    
    musb->pDcdCore->pGadgetObject->devState = USB_DEVICE_STATE_RESET;
}

void usbMusbDcdCnctDoneEvntHandler(usbMusbDcdDevice_t *musb)
{
}



/****************************************************************************** */
/* This is interrupt handler for endpoint zero. */
/* This function handles all interrupts on endpoint zero in order to maintain */
/* the state needed for the control endpoint on endpoint zero.  In order to */
/* successfully enumerate and handle all USB standard requests, all requests */
/* on endpoint zero must pass through this function.  The endpoint has the */
/* following states: \b USB_MUSB_STATE_IDLE, \b USB_MUSB_STATE_TX, \b USB_MUSB_STATE_RX, */
/* \b USB_MUSB_STATE_STALL, and \b USB_MUSB_STATE_STATUS.  In the \b USB_MUSB_STATE_IDLE */
/* state the USB controller has not received the start of a request, and once */
/* it does receive the data for the request it will either enter the */
/* \b USB_MUSB_STATE_TX, \b USB_MUSB_STATE_RX, or \b USB_MUSB_STATE_STALL depending on the */
/* command.  If the controller enters the \b USB_MUSB_STATE_TX or \b USB_MUSB_STATE_RX */
/* then once all data has been sent or received, it must pass through the */
/* \b USB_MUSB_STATE_STATUS state to allow the host to acknowledge completion of */
/* the request.  The \b USB_MUSB_STATE_STALL is entered from \b USB_MUSB_STATE_IDLE in */
/* the event that the USB request was not valid.  Both the \b USB_MUSB_STATE_STALL */
/* and \b USB_MUSB_STATE_STATUS are transitional states that return to the */
/* \b USB_MUSB_STATE_IDLE state. */
/* \return None. */
/* USB_MUSB_STATE_IDLE -*--> USB_MUSB_STATE_TX -*-> USB_MUSB_STATE_STATUS -*->USB_MUSB_STATE_IDLE */
/*                      |                       |                     | */
/*                      |--> USB_MUSB_STATE_RX -                      | */
/*                      |                                             | */
/*                      |--> USB_MUSB_STATE_STALL ---------->--------- */
/*  --------------------------------------------------------------------------- */
/* | Current State            | State 0                | State 1              | */
/* | -------------------------|------------------------|---------------------- */
/* | USB_MUSB_STATE_IDLE      | USB_MUSB_STATE_TX/RX   | USB_MUSB_STATE_STALL | */
/* | USB_MUSB_STATE_TX        | USB_MUSB_STATE_STATUS  |                      | */
/* | USB_MUSB_STATE_RX        | USB_MUSB_STATE_STATUS  |                      | */
/* | USB_MUSB_STATE_STATUS    | USB_MUSB_STATE_IDLE    |                      | */
/* | USB_MUSB_STATE_STALL     | USB_MUSB_STATE_IDLE    |                      | */
/*  --------------------------------------------------------------------------- */
/****************************************************************************** */
void usbMusbDcdEp0EvntHandler(usbMusbDcdDevice_t *musb)
{
    uint32_t ulEPStatus;
    uint32_t ulSize;
    uint32_t ulDataSize;
    usbDevRequest_t* req = 0;
    usbSetupPkt_t * pSetup = 0;

    /* Get the end point 0 status. */
    ulEPStatus = USBEndpointStatus(musb->baseAddr, USB_EP_0);

    switch(musb->deviceInstance.eEP0State)
    {
        /* In the IDLE state the code is waiting to receive data from the host. */
        case USB_MUSB_STATE_IDLE:
        {
            debug_printf("%s:%d. IDLE state\n", __FUNCTION__, __LINE__);
            /* Is there a packet waiting for us? */
            if(ulEPStatus & USB_DEV_EP0_OUT_PKTRDY)
            {
                ulSize = EP0_MAX_PACKET_SIZE;

                /* Get the data from the USB controller end point 0. */
                USBEndpointDataGet(musb->baseAddr,
                                   USB_EP_0,
                                   g_pucDataBufferIn,
                                   &ulSize);

                /* If there was a null setup packet then just return. */
                if(!ulSize)
                {
                    return;
                }

                /* ACK for this phase.
                 * Send ACK on non-standard requests since dev_dman already 
                 * handles standard requests properly.
                 * non-standard (i.e class) requests go to the class handler which
                 * doesn't have any generic API to ACK to USB requests
                 */
                pSetup = (usbSetupPkt_t *)g_pucDataBufferIn;
                if((pSetup->bmRequestType & USB_RTYPE_TYPE_M) != USB_RTYPE_STANDARD)
                {
                    USBDevEndpointDataAck(musb->baseAddr, USB_EP_0, FALSE);
                }

                /* Parsing the setup command bytes */
                /* Call the callback function */
                musb->pDcdCore->gadgetObjCallBack.
                    pFnDevEndpt0Handler(musb->pDcdCore->pGadgetObject,
                                        USB_ENDPT0_EVENT_SETUP_PACKET_RECEIVED,
                                        (usbSetupPkt_t *) g_pucDataBufferIn);
            }
            break;
        }

        /* Handle the status state, this is a transitory state from */
        /* USB_MUSB_STATE_TX or USB_MUSB_STATE_RX back to USB_MUSB_STATE_IDLE. */
        case USB_MUSB_STATE_STATUS:
        {
            debug_printf("%s:%d. STATUS state\n", __FUNCTION__, __LINE__);

            /* completion of status phase of transfer */
            /* EP0 is now idle */
            req = &(musb->pDcdCore->pGadgetObject->requestbuf[0]); /* req for EP0 */
            req->reqComplete(musb->pDcdCore->pGadgetObject, req);

            musb->deviceInstance.eEP0State = USB_MUSB_STATE_IDLE;

            /* If there is a pending address change then set the address. */
            if(musb->deviceInstance.ulDevAddress & DEV_ADDR_PENDING)
            {
                musb->deviceInstance.ulDevAddress &= ~DEV_ADDR_PENDING;
                USBDevAddrSet(musb->baseAddr, musb->deviceInstance.ulDevAddress);
            }

            /* debug: read back the address to see if its already taken */
            debug_printf("current dev address from hw: 0x%x\n", 
                            USBDevAddrGet(musb->baseAddr));
            /* If a new packet is already pending, we need to read it */
            /* and handle whatever request it contains. */
            if(ulEPStatus & USB_DEV_EP0_OUT_PKTRDY)
            {
                /* Process the newly arrived packet. */
                ulSize = EP0_MAX_PACKET_SIZE;

                /* Get the data from the USB controller end point 0. */
                USBEndpointDataGet(musb->baseAddr,
                                   USB_EP_0,
                                   g_pucDataBufferIn,
                                   &ulSize);

                /* If there was a null setup packet then just return. */
                if(!ulSize)
                {
                    break;
                }

                /* ACK for this phase.
                 * Send ACK on non-standard requests since dev_dman already 
                 * handles standard requests properly.
                 * Hardware already actually sends out an ACK to host.
                 * This ACK only acks to the hardware.
                 */
                pSetup = (usbSetupPkt_t *)g_pucDataBufferIn;
                if((pSetup->bmRequestType & USB_RTYPE_TYPE_M) != USB_RTYPE_STANDARD)
                {
                    USBDevEndpointDataAck(musb->baseAddr, USB_EP_0, FALSE);
                }

                /* Parsing the setup command bytes */
                /* Call the callback function */
                musb->pDcdCore->gadgetObjCallBack.
                    pFnDevEndpt0Handler(musb->pDcdCore->pGadgetObject,
                                        USB_ENDPT0_EVENT_SETUP_PACKET_RECEIVED,
                                        (usbSetupPkt_t *) g_pucDataBufferIn);
            }

            break;
        }


        /* Data is still being sent to the host so handle this in the */
        /* EP0StateTx() function. */
        case USB_MUSB_STATE_TX:
        {
            debug_printf("%s:%d. TX state\n", __FUNCTION__, __LINE__);
            USBDEP0StateTx(musb);
            break;
        }

        /* We are still in the middle of sending the configuration descriptor */
        /* so handle this in the EP0StateTxConfig() function. */
        /* Not valid with DCD driver. May need to enable later. */
        /*case USB_MUSB_STATE_TX_CONFIG: */
        /*{ */
        /*    USBDEP0StateTxConfig(ulIndex); */
        /*    break; */
        /*} */

        /* Handle the receive state for commands that are receiving data on */
        /* endpoint zero. */
        case USB_MUSB_STATE_RX:
        {
            debug_printf("%s:%d. RX state\n", __FUNCTION__, __LINE__);

            /* Set the number of bytes to get out of this next packet. */
            if(musb->deviceInstance.ulEP0DataRemain > EP0_MAX_PACKET_SIZE)
            {
                /* Don't send more than EP0_MAX_PACKET_SIZE bytes. */
                ulDataSize = EP0_MAX_PACKET_SIZE;
            }
            else
            {
                /* There was space so send the remaining bytes. */
                ulDataSize = musb->deviceInstance.ulEP0DataRemain;
            }

            /* Get the data from the USB controller end point 0. */
            USBEndpointDataGet(musb->baseAddr, USB_EP_0, 
                               musb->deviceInstance.pEP0Data, 
                               &ulDataSize);

            /* If there we not more that EP0_MAX_PACKET_SIZE or more bytes */
            /* remaining then this transfer is complete.  If there were less than */
            /* EP0_MAX_PACKET_SIZE remaining then there still needs to be */
            /* null packet sent before this is complete. */
            if(musb->deviceInstance.ulEP0DataRemain <= EP0_MAX_PACKET_SIZE)
            {
                /* Need to ACK the data on end point 0 in this case and set the */
                /* data end as this is the last of the data. */
                USBDevEndpointDataAck(musb->baseAddr, USB_EP_0, true);

                /* Return to the idle state. */
                musb->deviceInstance.eEP0State =  USB_MUSB_STATE_IDLE;

                req = &(musb->pDcdCore->pGadgetObject->requestbuf[0]); /* req for EP0 */
                req->reqComplete(musb->pDcdCore->pGadgetObject, req);

                tDeviceInfo *deviceInfo = (tDeviceInfo *)musb->pDcdCore->pGadgetObject->dcd.ptDeviceInfo;

                /* If there is a receive callback then call it. */
                if((deviceInfo->sCallbacks.pfnDataReceived) &&
                   (musb->deviceInstance.ulOUTDataSize != 0))
                {
                    /* Call the custom receive handler to handle the data */
                    /* that was received. */
                    deviceInfo->sCallbacks.pfnDataReceived(
                        (void *)musb->pDcdCore->pGadgetObject,
                        musb->deviceInstance.ulOUTDataSize, musb->controllerId);

                    /* Indicate that there is no longer any data being waited */
                    /* on. */
                    musb->deviceInstance.ulOUTDataSize = 0;
                }
            }
            else
            {
                /* Need to ACK the data on end point 0 in this case */
                /* without setting data end because more data is coming. */
                /*USBDevEndpointDataAck(musb->uiBaseAddr, USB_EP_0, false); */

                req = &(musb->pDcdCore->pGadgetObject->requestbuf[0]); /* req for EP0 */
                req->reqComplete(musb->pDcdCore->pGadgetObject, req);
            }

            /* Advance the pointer. */
            musb->deviceInstance.pEP0Data += ulDataSize;

            /* Decrement the number of bytes that are being waited on. */
            musb->deviceInstance.ulEP0DataRemain -= ulDataSize;

            break;
        }
        /* The device stalled endpoint zero so check if the stall needs to be */
        /* cleared once it has been successfully sent. */
        case USB_MUSB_STATE_STALL:
        {
            debug_printf("%s:%d. STALL state\n", __FUNCTION__, __LINE__);
            /* If we sent a stall then acknowledge this interrupt. */
            if(ulEPStatus & USB_DEV_EP0_SENT_STALL)
            {
                /* Clear the Setup End condition. */
                USBDevEndpointStatusClear(musb->baseAddr, USB_EP_0,
                                          USB_DEV_EP0_SENT_STALL);

                /* Reset the global end point 0 state to IDLE. */
                musb->deviceInstance.eEP0State = USB_MUSB_STATE_IDLE;

            }
            break;
        }
        /* Halt on an unknown state, but only in DEBUG mode builds. */
        default:
        {
            debug_printf("%s:%d. unexpected error\n", __FUNCTION__, __LINE__);

            ASSERT(0);
        }
    }
} /* usbMusbDcdEp0EvntHandler */

/****************************************************************************** */
/* wrapper to MUSB driver function */
/****************************************************************************** */
void usbMusbDcdSetConfiguration(usbMusbDcdDevice_t *musb)
{
    usbDescriptor_t*    pDescs;
    tDeviceInfo*        ptDeviceInfo;

    debug_printf("%s:%d\n", __FUNCTION__, __LINE__);

    /* pointer to the descriptors */
    pDescs = &(musb->pDcdCore->pGadgetObject->pDesc);

    /* Need to ACK the data on end point 0 with last data set as this has no */
    /* data phase. */
    USBDevEndpointDataAck(musb->baseAddr, USB_EP_0, true);

    /* Cannot set the configuration to one that does not exist so check the */
    /* enumeration structure to see how many valid configurations are present. */
    if(musb->deviceInstance.ulConfiguration > pDescs->pDeviceDesc->bNumConfigurations)
    {
        /* The passed configuration number is not valid.  Stall the endpoint to */
        /* signal the error to the host. */
        USBDevEndpointStall(musb->baseAddr, USB_EP_0, USB_EP_DEV_OUT);
        musb->deviceInstance.eEP0State = USB_MUSB_STATE_STALL;
    }
    else
    {
        /* If passed a configuration other than 0 (which tells us that we are */
        /* not currently configured), configure the endpoints (other than EP0) */
        /* appropriately. */
        if(musb->deviceInstance.ulConfiguration)
        {
            /*TODO: might have to record self power attribute from the descriptor */
            /* bmAttributes from config descriptor header */

            /* Configure endpoints for the new configuration. */
            usbMusbDcdDeviceConfig(musb,
                            pDescs->ppConfigDesc[musb->deviceInstance.
                                                 ulConfiguration-1],
                            &g_sUSBDefaultFIFOConfig);
        }

        /* If there is a configuration change callback then call it. */
        ptDeviceInfo = (tDeviceInfo*)musb->pDcdCore->ptDeviceInfo;
        if (ptDeviceInfo->sCallbacks.pfnConfigChange)
        {
            ptDeviceInfo->sCallbacks.
                    pfnConfigChange(ptDeviceInfo->pvInstance,
                                    musb->deviceInstance.ulConfiguration,
                                    musb->controllerId);
        }
    }
}

/****************************************************************************** */
/* main entry point for Musb Miscs interrupt handler  with USB Wrapper setup */
/****************************************************************************** */
void usbMusbDcdMiscIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    /* dummy function for compilation  */
    debug_printf("%s:%d\n", __FUNCTION__, __LINE__);
}


/****************************************************************************** */
/* main entry point for Musb core interrupt handler with USB Wrapper setup */
/****************************************************************************** */
void usbMusbDcdCoreIntrHandler(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    usbMusbDcdDevice_t* musb;

    musb = (usbMusbDcdDevice_t*)pUserParam;

    uint32_t ulStatus = 0;

    /*Get Interrupt Controller Status*/
	ulStatus = USBGetEndpointIntrStatus(musb->uiSubBaseAddr, &musb->ulIrqStatus, &musb->epIrqStatus);


	/* Clear the interrupt status. */
	USBClearInt(musb->uiSubBaseAddr, ulStatus, musb->epIrqStatus);

    /* Call device interrupt handler */
    USBMusbDcdIntrHandler(musb);

    
    /* Clear the interrupt which occured */
    HWREG(musb->uiSubBaseAddr + USB_0_IRQ_EOI) = 0;

} /* usbMusbDcdCoreIntrHandler */ 



/****************************************************************************** */
/* This internal function handles sending data on endpoint zero. */
/* \param ulIndex is the index of the USB controller which is to be */
/* initialized. */
/* \return None. */
/****************************************************************************** */
static void
USBDEP0StateTx(usbMusbDcdDevice_t *musb)
{
    uint32_t ulNumBytes;
    unsigned char *pData;

    debug_printf("%s:%d. TX state\n", __FUNCTION__, __LINE__);

    /* In the TX state on endpoint zero. */
    musb->deviceInstance.eEP0State = USB_MUSB_STATE_TX;

    /* Set the number of bytes to send this iteration. */
    ulNumBytes = musb->deviceInstance.ulEP0DataRemain;

    /* Limit individual transfers to 64 bytes. */
    if(ulNumBytes > EP0_MAX_PACKET_SIZE)
    {
        ulNumBytes = EP0_MAX_PACKET_SIZE;
    }

    /* Save the pointer so that it can be passed to the USBEndpointDataPut() */
    /* function. */
    pData = (unsigned char *)musb->deviceInstance.pEP0Data;

    /* Advance the data pointer and counter to the next data to be sent. */
    musb->deviceInstance.ulEP0DataRemain -= ulNumBytes;
    musb->deviceInstance.pEP0Data += ulNumBytes;

    debug_printf("%s:%d. pData=0x%x. ulNumBytes=%d. remain=%d\n", 
                __FUNCTION__, __LINE__, pData, ulNumBytes,
                musb->deviceInstance.ulEP0DataRemain 
                );

    /* Put the data in the correct FIFO. */
    USBEndpointDataPut(musb->baseAddr, USB_EP_0, pData, ulNumBytes);

    /* If this is exactly 64 then don't set the last packet yet. */
    if(ulNumBytes == EP0_MAX_PACKET_SIZE)
    {
        /* There is more data to send or exactly 64 bytes were sent, this */
        /* means that there is either more data coming or a null packet needs */
        /* to be sent to complete the transaction. */
        USBEndpointDataSend(musb->baseAddr, USB_EP_0, USB_TRANS_IN);
    }
    else
    {
        /* Now go to the status state and wait for the transmit to complete. */
        musb->deviceInstance.eEP0State = USB_MUSB_STATE_STATUS;

        /* Send the last bit of data. */
        USBEndpointDataSend(musb->baseAddr, USB_EP_0, 
                                USB_TRANS_IN_LAST);

        /* If there is a sent callback then call it. */
#if 0
        if((musb->deviceInstance.psInfo->sCallbacks.pfnDataSent) &&
           (musb->deviceInstance.ulOUTDataSize != 0))
        {
            /* Call the custom handler. */
            musb->deviceInstance.psInfo->sCallbacks.pfnDataSent(
                                        musb->deviceInstance.pvInstance, 
                                        musb->deviceInstance.ulOUTDataSize, 
                                        musb->controllerId);

            /* There is no longer any data pending to be sent. */
            musb->deviceInstance.ulOUTDataSize = 0;
        }
#endif
    }
}



/****************************************************************************** */
/* Mask used to preserve various endpoint configuration flags. */
/****************************************************************************** */
#define EP_FLAGS_MASK           (USB_EP_MODE_MASK | USB_EP_DEV_IN |           \
                                 USB_EP_DEV_OUT)

/****************************************************************************** */
/* Structure used in compiling FIFO size and endpoint properties from a */
/* configuration descriptor. */
/****************************************************************************** */
typedef struct
{
    uint32_t ulSize[2];
    uint32_t ulType[2];
}
tUSBEndpointInfo;

/****************************************************************************** */
/* Indices used when accessing the tUSBEndpointInfo structure. */
/****************************************************************************** */
#define EP_INFO_IN              0
#define EP_INFO_OUT             1


/****************************************************************************** */
/* This internal configures device and endpoints. */
/****************************************************************************** */

uint32_t usbMusbDcdDeviceConfig(usbMusbDcdDevice_t* musb, 
                                const usbConfigHeader_t *psConfig,
                                const tFIFOConfig *psFIFOConfig)
{
    uint32_t ulLoop;
    uint32_t ulCount;
    uint32_t ulNumInterfaces;
    uint32_t ulEpIndex;
    uint32_t ulEpType;
    uint32_t ulMaxPkt;
    uint32_t ulNumEndpoints;
    uint32_t ulFlags;
    uint32_t ulBytesUsed;
    uint32_t ulSection;
    tInterfaceDescriptor *psInterface;
    tEndpointDescriptor *psEndpoint;
    tUSBEndpointInfo psEPInfo[NUM_USB_EP - 1];

    ASSERT(((musb->controllerId == 0) || (musb->controllerId == 1)));

    /* Catch bad pointers in a debug build. */
    ASSERT(psConfig);
    ASSERT(psFIFOConfig);

    /* Clear out our endpoint info. */
    for(ulLoop = 0; ulLoop < (NUM_USB_EP - 1); ulLoop++)
    {
        psEPInfo[ulLoop].ulSize[EP_INFO_IN] = 0;
        psEPInfo[ulLoop].ulType[EP_INFO_IN] = 0;
        psEPInfo[ulLoop].ulSize[EP_INFO_OUT] = 0;
        psEPInfo[ulLoop].ulType[EP_INFO_OUT] = 0;
    }

    /* How many (total) endpoints does this configuration describe? */
    ulNumEndpoints = USBDCDConfigDescGetNum((tConfigHeader*)psConfig,
                                            USB_DTYPE_ENDPOINT);

    /* How many interfaces are included? */
    /* NOTE: TODO: better to convert all these USBDCDConfigDesc functions */
    /* to use usbConfigHeader_t instead of tConfigHeader */
    ulNumInterfaces = USBDCDConfigDescGetNum((tConfigHeader*)psConfig,
                                             USB_DTYPE_INTERFACE);

    /* Look at each endpoint and determine the largest max packet size for */
    /* each endpoint.  This will determine how we partition the USB FIFO. */
    for(ulLoop = 0; ulLoop < ulNumEndpoints; ulLoop++)
    {
        /* Get a pointer to the endpoint descriptor. */
        psEndpoint = (tEndpointDescriptor *)USBDCDConfigDescGet(
                                (tConfigHeader*)psConfig, 
                                USB_DTYPE_ENDPOINT, 
                                ulLoop,
                                &ulSection);

        /* Extract the endpoint number and whether it is an IN or OUT */
        /* endpoint. */
        ulEpIndex = (uint32_t)
                        psEndpoint->bEndpointAddress & USB_EP_DESC_NUM_M;
        ulEpType =  (psEndpoint->bEndpointAddress & USB_EP_DESC_IN) ?
                     EP_INFO_IN : EP_INFO_OUT;

        /* Make sure the endpoint number is valid for our controller.  If not, */
        /* return false to indicate an error.  Note that 0 is invalid since */
        /* you shouldn't reference endpoint 0 in the config descriptor. */
        if((ulEpIndex >= NUM_USB_EP) || (ulEpIndex == 0))
        {
            return(false);
        }

        /* Does this endpoint have a max packet size requirement larger than */
        /* any previous use we have seen? */
        if(psEndpoint->wMaxPacketSize >
           psEPInfo[ulEpIndex - 1].ulSize[ulEpType])
        {
            /* Yes - remember the new maximum packet size. */
            psEPInfo[ulEpIndex - 1].ulSize[ulEpType] =
                psEndpoint->wMaxPacketSize;
        }
    }

    /* At this point, we have determined the maximum packet size required */
    /* for each endpoint by any possible alternate setting of any interface */
    /* in this configuration.  Now determine the endpoint settings required */
    /* for the interface setting we are actually going to use. */
    for(ulLoop = 0; ulLoop < ulNumInterfaces; ulLoop++)
    {
        /* Get the next interface descriptor in the config descriptor. */
        psInterface = USBDCDConfigGetInterface((tConfigHeader*)psConfig,
                                               ulLoop,
                                               USB_DESC_ANY,
                                               &ulSection);

        /* Is this the default interface (bAlternateSetting set to 0)? */
        if(psInterface && (psInterface->bAlternateSetting == 0))
        {
            /* This is an interface we are interested in so gather the */
            /* information on its endpoints. */
            ulNumEndpoints = (uint32_t)psInterface->bNumEndpoints;

            /* Walk through each endpoint in this interface and configure */
            /* it appropriately. */
            for(ulCount = 0; ulCount < ulNumEndpoints; ulCount++)
            {
                /* Get a pointer to the endpoint descriptor. */
                psEndpoint = USBDCDConfigGetInterfaceEndpoint(
                                            (tConfigHeader*)psConfig,
                                            psInterface->bInterfaceNumber,
                                            psInterface->bAlternateSetting,
                                            ulCount);

                /* Make sure we got a good pointer. */
                if(psEndpoint)
                {
                    /* Determine maximum packet size and flags from the */
                    /* endpoint descriptor. */
                    GetEPDescriptorType(psEndpoint, &ulEpIndex, &ulMaxPkt,
                                        &ulFlags);

                    /* Make sure no-one is trying to configure endpoint 0. */
                    if(!ulEpIndex)
                    {
                        return(false);
                    }

                    /* Include any additional flags that the user wants. */
                    if((ulFlags & (USB_EP_DEV_IN | USB_EP_DEV_OUT)) ==
                        USB_EP_DEV_IN)
                    {
                        /* This is an IN endpoint. */
                        ulFlags |= (uint32_t)(
                                  psFIFOConfig->sIn[ulEpIndex - 1].usEPFlags);
                        psEPInfo[ulEpIndex - 1].ulType[EP_INFO_IN] = ulFlags;
                    }
                    else
                    {
                        /* This is an OUT endpoint. */
                        ulFlags |= (uint32_t)(
                                  psFIFOConfig->sOut[ulEpIndex - 1].usEPFlags);
                        psEPInfo[ulEpIndex - 1].ulType[EP_INFO_OUT] = ulFlags;
                    }

                    /* Set the endpoint configuration. */
                    USBDevEndpointConfigSet(musb->baseAddr,
                                            INDEX_TO_USB_EP(ulEpIndex),
                                            ulMaxPkt, ulFlags);
                }
            }
        }
    }

    /* At this point, we have configured all the endpoints that are to be */
    /* used by this configuration's alternate setting 0.  Now we go on and */
    /* partition the FIFO based on the maximum packet size information we */
    /* extracted earlier.  Endpoint 0 is automatically configured to use the */
    /* first MAX_PACKET_SIZE_EP0 bytes of the FIFO so we start from there. */
    ulCount = MAX_PACKET_SIZE_EP0;
    for(ulLoop = 1; ulLoop < NUM_USB_EP; ulLoop++)
    {
        /* Configure the IN endpoint at this index if it is referred to */
        /* anywhere. */
        if(psEPInfo[ulLoop - 1].ulSize[EP_INFO_IN])
        {
            /* What FIFO size flag do we use for this endpoint? */
            ulMaxPkt = GetEndpointFIFOSize(
                                     psEPInfo[ulLoop - 1].ulSize[EP_INFO_IN],
                                     &(psFIFOConfig->sIn[ulLoop - 1]),
                                     &ulBytesUsed);

            /* If we are told that 0 bytes of FIFO will be used, this implies */
            /* that there is an error in psFIFOConfig or the descriptor */
            /* somewhere so return an error indicator to the caller. */
            if(!ulBytesUsed)
            {
                return(false);
            }

            /* Now actually configure the FIFO for this endpoint. */
            USBFIFOConfigSet(musb->baseAddr, 
                             INDEX_TO_USB_EP(ulLoop), ulCount,
                             ulMaxPkt, USB_EP_DEV_IN);

            ulCount += ulBytesUsed;

#if DMA_MODE
            /* enable TX DMA */
            enableCoreTxDMA(musb->controllerId, INDEX_TO_USB_EP(ulLoop)); 
#endif
        }

        /* Configure the OUT endpoint at this index. */
        if(psEPInfo[ulLoop - 1].ulSize[EP_INFO_OUT])
        {
            /* What FIFO size flag do we use for this endpoint? */
            ulMaxPkt = GetEndpointFIFOSize(
                                     psEPInfo[ulLoop - 1].ulSize[EP_INFO_OUT],
                                     &(psFIFOConfig->sOut[ulLoop - 1]),
                                     &ulBytesUsed);

            /* If we are told that 0 bytes of FIFO will be used, this implies */
            /* that there is an error in psFIFOConfig or the descriptor */
            /* somewhere so return an error indicator to the caller. */
            if(!ulBytesUsed)
            {
                return(false);
            }

            /* Now actually configure the FIFO for this endpoint. */
            USBFIFOConfigSet(musb->baseAddr, 
                             INDEX_TO_USB_EP(ulLoop), ulCount,
                             ulMaxPkt, USB_EP_DEV_OUT);
            ulCount += ulBytesUsed;

#if DMA_MODE
            /* enable RX DMA */
            enableCoreRxDMA(musb->controllerId, INDEX_TO_USB_EP(ulLoop)); 
#endif
        }

    }

    /* If we get to the end, all is well. */
    return(true);
}

/****************************************************************************** */
/* Given a maximum packet size and the user's FIFO scaling requirements, */
/* determine the flags to use to configure the endpoint FIFO and the number */
/* of bytes of FIFO space occupied. */
/****************************************************************************** */
static uint32_t
GetEndpointFIFOSize(uint32_t ulMaxPktSize, const tFIFOEntry *psFIFOParams,
                    uint32_t *pupBytesUsed)
{
    uint32_t ulBytes;
    uint32_t ulLoop;
    uint32_t ulFIFOSize;

    /* A zero multiplier would not be a good thing. */
    ASSERT(psFIFOParams->cMultiplier);

    /* What is the basic size required for a single buffered FIFO entry */
    /* containing the required number of packets? */
    ulBytes = ulMaxPktSize * (uint32_t)psFIFOParams->cMultiplier;

    /* Now we need to find the nearest supported size that accommodates the */
    /* requested size.  Step through each of the supported sizes until we */
    /* find one that will do. */
    for(ulLoop = USB_FIFO_SZ_8; ulLoop <= USB_FIFO_SZ_8192; ulLoop++) 
    {
        /* How many bytes does this FIFO value represent? */
        ulFIFOSize = USB_FIFO_SZ_TO_BYTES(ulLoop);

        /* Is this large enough to satisfy the request? */
        if(ulFIFOSize >= ulBytes)
        {
            /* Yes - are we being asked to double-buffer the FIFO for this */
            /* endpoint? */
            if(psFIFOParams->bDoubleBuffer)
            {
                /* Yes - FIFO requirement is double in this case. */
                *pupBytesUsed = ulFIFOSize * 2;
                return(ulLoop | USB_FIFO_SIZE_DB_FLAG);
            }
            else
            {
                /* No double buffering so just return the size and associated */
                /* flag. */
                *pupBytesUsed = ulFIFOSize;
                return(ulLoop);
            }
        }
    }

    /* If we drop out, we can't support the FIFO size requested.  Signal a */
    /* problem by returning 0 in the pBytesUsed */
    *pupBytesUsed = 0;
    return(USB_FIFO_SZ_8);
}

/*****************************************************************************
 *
 * Configure the affected USB endpoints appropriately for one alternate
 * interface setting.
 *
 * \param ulIndex is the zero-based index of the USB controller which is to
 * be configured.
 * \param psConfig is a pointer to the configuration descriptor that contains
 * the interface whose alternate settings is to be configured.
 * \param ucInterfaceNum is the number of the interface whose alternate
 * setting is to be configured.  This number corresponds to the
 * bInterfaceNumber field in the desired interface descriptor.
 * \param ucAlternateSetting is the alternate setting number for the desired
 * interface.  This number corresponds to the bAlternateSetting field in the
 * desired interface descriptor.
 *
 * This function may be used to reconfigure the endpoints of an interface
 * for operation in one of the interface's alternate settings.  Note that this
 * function assumes that the endpoint FIFO settings will not need to change
 * and only the endpoint mode is changed.  This assumption is valid if the
 * USB controller was initialized using a previous call to USBDCDConfig().
 *
 * In reconfiguring the interface endpoints, any additional configuration
 * bits set in the endpoint configuration other than the direction (\b
 * USB_EP_DEV_IN or \b USB_EP_DEV_OUT) and mode (\b USB_EP_MODE_MASK) are
 * preserved.
 *
 * \return Returns \b true on success or \b false on failure.
 *******************************************************************************/
tBoolean
USBDConfigAlternate(usbMusbDcdDevice_t *musb, uint32_t ulIndex,
                    uint8_t ucInterfaceNum, uint8_t ucAlternateSetting)
{
    uint32_t ulNumInterfaces;
    uint32_t ulNumEndpoints;
    uint32_t ulLoop;
    uint32_t ulCount;
    uint32_t ulMaxPkt;
    uint32_t ulOldMaxPkt;
    uint32_t ulEpIndex;
    uint32_t ulFlags;
    uint32_t ulOldFlags;
    uint32_t ulSection;
    usbDescriptor_t*    pDescs;
	tInterfaceDescriptor *psInterface;
    tEndpointDescriptor *psEndpoint;

    /* pointer to the descriptors */
    pDescs = &(musb->pDcdCore->pGadgetObject->pDesc);

    /* How many interfaces are included in the descriptor?*/
    ulNumInterfaces = USBDCDConfigDescGetNum((const tConfigHeader *)pDescs->ppConfigDesc[musb->deviceInstance.
                                             ulConfiguration - 1], USB_DTYPE_INTERFACE);

    for(ulLoop = 0; ulLoop < ulNumInterfaces; ulLoop++)
    {
        /*Get the next interface descriptor in the configuration descriptor.*/
        psInterface = USBDCDConfigGetInterface((const tConfigHeader *)pDescs->ppConfigDesc[musb->deviceInstance.
                                               ulConfiguration - 1] , ulLoop, USB_DESC_ANY,
                                                &ulSection);

        /*Is this the required interface with the correct alternate setting?*/
        if(psInterface &&
           (psInterface->bInterfaceNumber == musb->deviceInstance.ulInterface) &&
           (psInterface->bAlternateSetting == musb->deviceInstance.ulAlternateConfig))
        {
            /*
             * This is an interface we are interested in and the descriptor
             * representing the alternate setting we want so go ahead and
             * reconfigure the endpoints.
             */

            /* How many endpoints does this interface have? */
            ulNumEndpoints = (unsigned int)psInterface->bNumEndpoints;

            /* Walk through each endpoint in turn. */
            for(ulCount = 0; ulCount < ulNumEndpoints; ulCount++)
            {
                /* Get a pointer to the endpoint descriptor. */
                psEndpoint = USBDCDConfigGetInterfaceEndpoint(
                                (const tConfigHeader *)pDescs->ppConfigDesc[
                                    musb->deviceInstance.ulConfiguration - 1],
                                              psInterface->bInterfaceNumber,
                                              psInterface->bAlternateSetting,
                                              ulCount);
                /* Make sure the pointer is not NULL */
                if(psEndpoint)
                {
                    /*
                     * Determine maximum packet size and flags from the
                     * endpoint descriptor.
                     */
                    GetEPDescriptorType(psEndpoint, &ulEpIndex, &ulMaxPkt,
                                        &ulFlags);
                    /* Make sure no-one is trying to configure endpoint 0. */
                    if(!ulEpIndex)
                    {
                        return(false);
                    }

                    /*
                     * Get the existing endpoint configuration and mask in the
                     * new mode and direction bits, leaving everything else
                     * unchanged.
                     */
                    ulOldFlags = ulFlags;
                    USBDevEndpointConfigGet(musb->baseAddr,
                                            INDEX_TO_USB_EP(ulEpIndex),
                                            &ulOldMaxPkt,
                                            &ulOldFlags);
                    /* Mask in the previous DMA and auto-set bits. */
                    ulFlags = (ulFlags & EP_FLAGS_MASK) |
                              (ulOldFlags & ~EP_FLAGS_MASK);

                    /* Set the endpoint configuration. */
                    USBDevEndpointConfigSet(musb->baseAddr,
                                            INDEX_TO_USB_EP(ulEpIndex),
                                            ulMaxPkt, ulFlags);
                }
            }
            /*
             * At this point, we have reconfigured the desired interface so
             * return indicating all is well.
             */
            return(true);

        }
    }
    return (false);
}

/****************************************************************************** */
/* wrapper to MUSB driver function */
/****************************************************************************** */
void usbMusbDcdSetInterface(usbMusbDcdDevice_t *musb, tDeviceInfo *psDevice)
{
    tInterfaceDescriptor *psInterface;
    usbDescriptor_t*    pDescs;
    uint32_t ulNumInterfaces;
    uint32_t ulLoop;
    uint32_t ulSection;
    uint32_t ucInterface;

    /* pointer to the descriptors */
    pDescs = &(musb->pDcdCore->pGadgetObject->pDesc);

    /* How many interfaces are included in the descriptor?*/
    ulNumInterfaces = USBDCDConfigDescGetNum((const tConfigHeader *)pDescs->ppConfigDesc[musb->deviceInstance.
                                             ulConfiguration - 1], USB_DTYPE_INTERFACE);
    debug_printf("%s:%d. ulNumInterfaces=%d\n", __FUNCTION__, __LINE__, ulNumInterfaces);

    for(ulLoop = 0; ulLoop < ulNumInterfaces; ulLoop++)
    {
        /*Get the next interface descriptor in the configuration descriptor.*/
        psInterface = USBDCDConfigGetInterface((const tConfigHeader *)pDescs->ppConfigDesc[musb->deviceInstance.
                                               ulConfiguration - 1] , ulLoop, USB_DESC_ANY,
                                                &ulSection);

        /*Is this the required interface with the correct alternate setting?*/
        if(psInterface &&
           (psInterface->bInterfaceNumber == musb->deviceInstance.ulInterface) &&
           (psInterface->bAlternateSetting == musb->deviceInstance.ulAlternateConfig))
        {
            ucInterface = psInterface->bInterfaceNumber;

            /*
             * Make sure we don't write outside the bounds of the pucAltSetting
             * array (in a debug build, anyway, since this indicates an error
             * in the device descriptor).
             */
            ASSERT(ucInterface < USB_MAX_INTERFACES_PER_DEVICE);

            /*
             * If anything changed, reconfigure the endpoints for the new
             * alternate setting.
             */
            if(musb->deviceInstance.pucAltSetting[ucInterface] !=
               psInterface->bAlternateSetting)
            {
                /*
                 * This is the correct interface descriptor so save the
                 * setting.
                 */
                musb->deviceInstance.pucAltSetting[ucInterface] =
                                                psInterface->bAlternateSetting;

                /*
                 * Reconfigure the endpoints to match the requirements of the
                 * new alternate setting for the interface.
                 */
                USBDConfigAlternate(musb, 0, ucInterface,
                                    psInterface->bAlternateSetting);
            }
	        /*
	         * Need to ACK the data on end point 0 with last data set as this has no
	         *data phase.
	         */
            if (psDevice->sCallbacks.pfnInterfaceChange == NULL)
            {
	            USBDevEndpointDataAck(musb->baseAddr, USB_EP_0, true);
            }

            debug_printf("%s:%d. USB Interface is now configured\n", __FUNCTION__, __LINE__);
            return;
        }
    }
}

/****************************************************************************** */
/* Translate a USB endpoint descriptor into the values we need to pass to the */
/* USBDevEndpointConfigSet() API. */
/****************************************************************************** */
static void
GetEPDescriptorType(tEndpointDescriptor *psEndpoint, uint32_t *pulEPIndex,
                    uint32_t *pulMaxPktSize, uint32_t *pulFlags)
{
    /* Get the endpoint index. */
    *pulEPIndex = psEndpoint->bEndpointAddress & USB_EP_DESC_NUM_M;

    /* Extract the maximum packet size. */
    *pulMaxPktSize = psEndpoint->wMaxPacketSize & USB_EP_MAX_PACKET_COUNT_M;

    /* Is this an IN or an OUT endpoint? */
    *pulFlags = (psEndpoint->bEndpointAddress & USB_EP_DESC_IN) ?
                 USB_EP_DEV_IN : USB_EP_DEV_OUT;

    /* Set the endpoint mode. */
    switch(psEndpoint->bmAttributes & USB_EP_ATTR_TYPE_M)
    {
        case USB_EP_ATTR_CONTROL:
            *pulFlags |= USB_EP_MODE_CTRL;
            break;

        case USB_EP_ATTR_BULK:
            *pulFlags |= USB_EP_MODE_BULK;
            break;

        case USB_EP_ATTR_INT:
            *pulFlags |= USB_EP_MODE_INT;
            break;

        case USB_EP_ATTR_ISOC:
            *pulFlags |= USB_EP_MODE_ISOC;
            break;
    }
}


