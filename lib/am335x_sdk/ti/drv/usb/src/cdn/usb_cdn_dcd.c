/**
 *  \file  usb_cdn_dcd.c
 *
 *  \brief CDN thin layer between USB and cusbdss
 *
 *  \copyright Copyright (C) 2019 Texas Instruments Incorporated -
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
#include "usb_drv.h"

#include "usb_cdn_dcd.h"
#include "usb_cdn.h"
#include "usb_osal.h"
#include "usblib.h"
#include "usbdevice.h"
#include "hw_usb.h"

/* field for error handling */
#include "error.h"
#include "debug.h"
#include "cdn_log.h"

#include "byteorder.h"
#include "stdio.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
extern   USB_MEM_S        g_usb_global;
#if 0

static CUSBDMA_MemResources epMemRes[32] = {
    {.memPageIndex = 0, .trbDmaAddr = (uint32_t)((uint64_t)cdnBuff[0])},
    {.memPageIndex = 1, .trbDmaAddr = (uintptr_t)cdnBuff[1]},
    {.memPageIndex = 2, .trbDmaAddr = (uintptr_t)cdnBuff[2]},
    {.memPageIndex = 3, .trbDmaAddr = (uintptr_t)cdnBuff[3]}
};

/* ---------- Cdn Super Speed USB driver configuration ----------------------*/
static CUSBD_Config cdnConfig = {
    .regBase = 0; /* address where USB core is mapped. overwritten during setup */
    .epIN =
    {
        {.bufferingValue = 4}, // ep1in
        {.bufferingValue = 0}, // ep2in
        {.bufferingValue = 0}, // ep3in
        {.bufferingValue = 0}, // ep4in
        {.bufferingValue = 0}, // ep5in
        {.bufferingValue = 0}, // ep6in
        {.bufferingValue = 0}, // ep7in
        {.bufferingValue = 0}, // ep8in
        {.bufferingValue = 0}, // ep9in
        {.bufferingValue = 0}, // ep10in
        {.bufferingValue = 0}, // ep11in
        {.bufferingValue = 0}, // ep12in
        {.bufferingValue = 0}, // ep13in
        {.bufferingValue = 0}, // ep14in
        {.bufferingValue = 0} // ep15in
    },
    .epOUT =
    {
        {.bufferingValue = 4}, //ep1out
        {.bufferingValue = 0}, //ep2out
        {.bufferingValue = 0}, //ep3out
        {.bufferingValue = 0}, //ep4out
        {.bufferingValue = 0}, //ep5out
        {.bufferingValue = 0}, //ep6out
        {.bufferingValue = 0}, //ep7out
        {.bufferingValue = 0}, //ep8out
        {.bufferingValue = 0}, //ep9out
        {.bufferingValue = 0}, //ep10out
        {.bufferingValue = 0}, //ep11out
        {.bufferingValue = 0}, //ep12out
        {.bufferingValue = 0}, //ep13out
        {.bufferingValue = 0}, //ep14out
        {.bufferingValue = 0} //ep15out
    },
    .dmultEnabled = 0, // set to 1 if scatter/gather DMA available
    .dmaInterfaceWidth = CUSBD_DMA_64_WIDTH,
    .preciseBurstLength = CUSBD_PRECISE_BURST_0,
    .epMemRes = &epMemRes
};


#endif

#define BULK_EP_IN 0x81     /* temporary definition to bring up Cdn driver 
                             * these two definitions match with what the 
                             * upper applications will use */
#define BULK_EP_OUT 0x02    /* TODO: need better solution for this */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static uint32_t cdnSetupCb(CUSBD_PrivateData *pD, CH9_UsbSetup *ctrl);
static void     cdnConnectCb(CUSBD_PrivateData *pD);
static void     cdnDisconnectCb(CUSBD_PrivateData *pD);
static void     cdnSuspendCb(CUSBD_PrivateData *pD);
static void     cdnResumeCb(CUSBD_PrivateData *pD);
int32_t         usbCdnDcdSetConfiguration(usbCdnDcdDevice_t *cdn);

#ifdef _DEBUG_
static void     displayDeviceInfo(CUSBD_Dev * dev);
static void     displayEndpointInfo(CUSBD_Ep * ep);
#endif

/* Cadence USB callback functions */
static CUSBD_Callbacks cdnCallbacks = {
    cdnDisconnectCb, cdnConnectCb, cdnSetupCb, cdnSuspendCb, cdnResumeCb
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t USBCdnDcdInit(struct usbDcd *pDcdObject)
{
    int32_t             res = S_PASS;
    uint8_t             instanceNum = 0;
    CUSBD_OBJ*          drv = 0;
    usbCdnDcdDevice_t*  cdnDcd = 0;
    int                 i; 
    CUSBD_PrivateData*  pD;
    CUSBD_Ep            *epIn, *epOut;
    LIST_ListHead       *list;
    CUSBD_Dev*          dev;



    if (pDcdObject == 0)
    {
        res = E_FAIL;
    }

    if (res == S_PASS)
    {
        if (pDcdObject->privateData == 0)
        {
            res = E_FAIL;
        }
    }

    if (res == S_PASS)
    {
        /* Retrieve private data from core object */
        cdnDcd = (usbCdnDcdDevice_t *)(pDcdObject->privateData);

        instanceNum = cdnDcd->instanceNo;

        if (!((instanceNum == 0) || (instanceNum == 1)))
        {
            debug_printf("wrong USB instance number\n");
            res = E_FAIL;
        }
    }

#ifdef _DEBUG_
    g_dbg_enable_log = 0xFFFFFFFF;
    /* g_dbg_log_lvl = DBG_WARN;*/
#endif

    if (res == S_PASS)
    {
        memset(&cdnDcd->devConfig, 0, sizeof(CUSBD_Config));
        memset(cdnDcd->epMemRes,  0, sizeof(cdnDcd->epMemRes));

        /* Init the trb buffers addres for each ep */
        for (i = 0; i < CDN_NUM_EP_MEMRES; i++) {
            cdnDcd->epMemRes[i].trbAddr = (CUSBDMA_DmaTrb*)cdnDcd->cdnBuff[i];
            cdnDcd->epMemRes[i].trbDmaAddr = (uintptr_t) cdnDcd->cdnBuff[i];

            /* Cadence IP operates in a 48-bit space for a given endpoint 
             * top 16 bits are referred as "mem page index", and should be setup at Init time
             * There are 2^16 pages.
             * TRB buffer and DMA buffer should both be in this same page index
             * We might need to force the linker to put the whole TRB and EP buffers 
             * at the beginning of a 4GB memory page.
             */
            cdnDcd->epMemRes[i].memPageIndex = (uint16_t)(((uint64_t) cdnDcd->cdnBuff[i]) >> 32);
            cdnDcd->epMemRes[i].trbBufferSize= CDN_NUM_TRB;
        }

        /* set Cadence USB device base address */
        cdnDcd->devConfig.regBase =  USB_CDN_BASE_ADDR(instanceNum) + 0x20000;

        /* config the bulk endpoint buffers. This matches with the application
           endpoint requirement. TODO: Need to figure out a way to find the endpoint
           from application and config it here */
#if 0
        cdnDcd->devConfig.epIN[0].bufferingValue = 4;   /* ep1 in */
        cdnDcd->devConfig.epOUT[1].bufferingValue = 4;  /* ep2 out */
#else
        /* cadence suggestion */
        /* 2KB of on-chip buffer - as big as single packet size */
        cdnDcd->devConfig.epIN[0].bufferingValue = 2;
        cdnDcd->devConfig.epOUT[0].bufferingValue = 2;
        cdnDcd->devConfig.epIN[1].bufferingValue = 2;   
        cdnDcd->devConfig.epOUT[1].bufferingValue = 2;
#endif

        cdnDcd->devConfig.dmultEnabled = 0;
        cdnDcd->devConfig.dmaInterfaceWidth = CUSBD_DMA_64_WIDTH;
        cdnDcd->devConfig.preciseBurstLength = CUSBD_PRECISE_BURST_0;

        cdnDcd->devConfig.forcedUsbMode = 2; /* HS only  - testing only */

        cdnDcd->devConfig.epMemRes = &cdnDcd->epMemRes;

        cdnDcd->devConfig.setupPacket = (CH9_UsbSetup*)&cdnDcd->setupPacketBuffer;

        /* we have same physical and virtual address
         * This setupPacketDma is physical address that the DMA engine can access to.
         * In case we use different virtual and physical address we need to figure out 
         * the real physical address to give to the driver. 
         */
        cdnDcd->devConfig.setupPacketDma = (uintptr_t)&cdnDcd->setupPacketBuffer;

        drv = CUSBD_GetInstance();

        cdnDcd->drv = drv;  /* save the pointer for quicker access later */

        res = drv->probe(&cdnDcd->devConfig, &cdnDcd->sysReqCusbd);

        if (res != S_PASS)
        {
            debug_printf("fail to probe Cdn driver\n");
        }
    }

    if (res == S_PASS)
    {
        pD = &cdnDcd->pD;
        memset((void*)pD, 0, (size_t)(cdnDcd->sysReqCusbd.privDataSize));

        /* Init cusbd */
        res = drv->init(pD, &cdnDcd->devConfig, &cdnCallbacks);
    }

    if (res == S_PASS)
    {
        debug_printf("CDN drv init passes\n");
        
        /* checking device and endpoints parameters correctness */
        drv->getDevInstance(pD, &cdnDcd->dev);
        dev = cdnDcd->dev;

        /* find Cdn endpoints and store them to our driver
         * How do we make this generic so that it's done at time of application 
         * i.e MSC / Bulk / CDC etc. are init, and not here where we dont
         * yet know the EP address */

        /* find IN endpoint */
        for (list = dev->epList.next; list != &dev->epList; list = list->next) {
            epIn = (CUSBD_Ep *) list;

            if (epIn->address == BULK_EP_IN) {
                cdnDcd->bulkInEp = epIn;
#ifdef _DEBUG_
                displayEndpointInfo(epIn);
#endif
                break;
            }
        }

        /* find OUT endpoint */
        for (list = dev->epList.next; list != &dev->epList; list = list->next) {
            epOut = (CUSBD_Ep *) list;

            if (epOut->address == BULK_EP_OUT) {
                cdnDcd->bulkOutEp = epOut;
#ifdef _DEBUG_
                displayEndpointInfo(epOut);
#endif
                break;
            }
        }

        drv->start(pD); /* start driver */

        /* add reference to the dev object so that call back function
           from Cadence driver knows which USB port it comes from.
           All call back functions have a CUSBD_Dev* passed in. 
           CUSBD_Dev has a "char name[100]" field which can be used for reference
           Since we only need to refernce USB instance #0 or #1 to track back the
           cdnDcd instance, we will use ascii char '0', or '1' for instance 0 
           or instance 1, respectively. Just need to treat the name[0] as uint8 and subtract 
           it with 0x30 to get the port number. This should give us pretty much no cycle 
           penalty when looking for pointers */
        cdnDcd->dev->name[0] = instanceNum + 0x30; /* convert digit to ascii */

#ifdef _DEBUG_
        /* double print here to see if Cadence is using the dev->name. 
           remove after verifying */
        displayDeviceInfo(cdnDcd->dev);
#endif
    }

    return (uint32_t)res;
}

uint32_t USBCdnDcdConfigDevChara( struct usbDcd * pDcdObject,
                                  usbDevChara_t * pDevCharecteristic)
{
    /* Retrieve private data from core object */
    usbCdnDcdDevice_t *cdn = (usbCdnDcdDevice_t *)(pDcdObject->privateData);

    switch(pDevCharecteristic->configparam)
    {
        case USB_DEVICE_DCD_CHARA_SPEED:
            /* This will be handled later */
            break;
        case USB_DEVICE_DCD_CHARA_ADDRESS:
            /* Set the address of the device */
            cdn->devAddr = pDevCharecteristic->deviceAddress;
            cdn->deviceNewAddrValidFlag = 1U;
            break;
        case USB_DEVICE_DCD_EP_CONFIG:
            /* Set endpoint configurations */
            cdn->configNo =  (uint8_t)pDevCharecteristic->epConfigNo;
            usbCdnDcdSetConfiguration(cdn);
            break;
        default :
            /* error condition on default */
            break;
    }
    return S_PASS;
}




/* EP0 transfer complete call back function 
 * This call-back function is called when data is finished sending 
 * to host for IN transaction or when data is finished arriving 
 * at device for OUT transaction
 * we don't do anything if the IN is complete
 * for the OUT transaction this function would tell when data arrives */
static void cdnEp0ReqComplete(CUSBD_Ep *ep, CUSBD_Req * cdnReq) 
{
//    usbCdnDcdDevice_t* cdn = 0; 
//    usbDevRequest_t*   req = 0;

    debug_printf("%s:%d. ep %s\n", __FUNCTION__, __LINE__, ep->name);
    /*displayRequestinfo(req);*/
#if 0    
    /* we know we are ep0, so we can call dev_dman ep0 req complete
     * but we also need to get the pointer to cdn_dcd object. */
    cdn = (usbCdnDcdDevice_t*)cdnReq->context;
    if (cdn != 0)
    {
        /* retrieve request for EP0 */
        req = &(cdn->pDcdCore->pGadgetObject->requestbuf[0]);
        req->reqComplete(cdn->pDcdCore->pGadgetObject, req);
    }
#endif
}

/* API for aplication layer to call to send out EP0 transfer */
uint32_t USBCdnDcdEp0Req( struct usbDcd *pDcdObject,
                          usbEndpt0Request_t* req)
{
    /* Retrieve private data from core object */
    usbCdnDcdDevice_t* cdn = (usbCdnDcdDevice_t*)(pDcdObject->privateData);
    debug_printf("%s:%d!\n", __FUNCTION__, __LINE__);

    /* all DMA buffers should be in un-cached area */
    cdn->ep0Req.buf = (uint8_t*)req->pbuf;
    cdn->ep0Req.dma = (uintptr_t)req->pbuf;
    cdn->ep0Req.complete = cdnEp0ReqComplete;   
                                                   
    cdn->ep0Req.length = req->length;

    /* add our reference ID into CDN req so that when callback happens 
       we can trace to this request */
    cdn->ep0Req.context = (void*)cdn;

    /* it seems CDN driver is smart enough to know if this req would be
       IN or OUT */
    cdn->dev->ep0->ops->reqQueue(&cdn->pD, cdn->dev->ep0, &cdn->ep0Req);
    return S_PASS;
}


/* EPx transfer complete call back function */
/*static*/ void cdnEpReqComplete(CUSBD_Ep* ep, CUSBD_Req* cdnReq) 
{
    usbCdnDcdDevice_t* cdn = 0; 
    usbDevRequest_t*   req = 0;
    uint32_t           epNo = 0;

    debug_printf("%s:%d. ep %d\n", __FUNCTION__, __LINE__, ep->address);

#ifdef _DEBUG_
    /*displayRequestinfo(req);*/
#endif

    /* find the endpoint number */
    epNo = (ep->address & 0xF);

    /* retrieve the DcdObj */
    cdn = (usbCdnDcdDevice_t*)cdnReq->context;
    if (cdn != 0)
    {
        /* retrieve request for EP No */
        req = &(cdn->pDcdCore->pGadgetObject->requestbuf[epNo]);

        debug_printf("receiving %02x %02x %02x %02x %02x...\n", 
                     ((uint8_t*)req->pbuf)[0], 
                     ((uint8_t*)req->pbuf)[1], 
                     ((uint8_t*)req->pbuf)[2], 
                     ((uint8_t*)req->pbuf)[3],
                     ((uint8_t*)req->pbuf)[4]
                    );

        /* update the length with the actual length received by the driver */
        req->length = cdnReq->actual;

        /* call the dev_dman call back function */
        req->reqComplete(cdn->pDcdCore->pGadgetObject, req);
    }
}

/* API for aplication layer to call to send out non EP0 transfer */
uint32_t USBCdnDcdEpReq ( struct usbDcd *pDcdObject,
                          usbEndptRequest_t* req)
{
    /* Retrieve private data from core object */
    usbCdnDcdDevice_t* cdn = (usbCdnDcdDevice_t*)(pDcdObject->privateData);
    CUSBD_Req*         cdnReq;
    CUSBD_Ep*          cdnEp;

    debug_printf("%s:%d!\n", __FUNCTION__, __LINE__);
   
    /* cache write back and invalidate the data buffer in the request 
     * for DMA transaction */ 
    usb_osalCacheWbInv(req->pbuf, req->length);

    if(USB_TOKEN_TYPE_IN == req->deviceEndptInfo.endpointDirection)
    {
        cdnReq = &cdn->bulkInReq;
        cdnEp  = cdn->bulkInEp;

        debug_printf("sending %02x %02x %02x %02x %02x...\n", 
                     ((uint8_t*)req->pbuf)[0], 
                     ((uint8_t*)req->pbuf)[1], 
                     ((uint8_t*)req->pbuf)[2], 
                     ((uint8_t*)req->pbuf)[3],
                     ((uint8_t*)req->pbuf)[4]
                    );
    }
    else
    {
        cdnReq = &cdn->bulkOutReq;
        cdnEp  = cdn->bulkOutEp;
    }

    cdnReq->buf = (uint8_t*)req->pbuf;
    cdnReq->dma = (uintptr_t)req->pbuf;
    cdnReq->complete = cdnEpReqComplete;
    cdnReq->length = req->length;
    cdnReq->streamId = 0;
    
    /* add our reference ID into CDN req so that when callback happens 
       we can trace to this request */
    cdnReq->context = (void*)cdn;

    /* call Cadence driver API */
    cdnEp->ops->reqQueue(&cdn->pD, cdnEp, cdnReq);

    return S_PASS;
}

/* CDN core IRQ interrupt handler.
   Handling most USB device interrupts */
uint32_t USBCdnDcdCoreIntrHandler(usbCdnDcdDevice_t* cdn)
{
    if (cdn != NULL)
    {
        cdn->drv->isr(&cdn->pD);
    }
    return S_PASS;
}


/* -------------- CDN driver callback functions ------------------------- */
/****************************************************************************** */
/****************************************************************************** */
static void cdnConnectCb(CUSBD_PrivateData *pD) {
    CUSBD_Dev *dev;

    CUSBD_OBJ* drv;

    drv = CUSBD_GetInstance();

    drv->getDevInstance(pD, &dev);

    debug_printf("Application: connect at %d speed\n", dev->speed);
}

/****************************************************************************** */
/****************************************************************************** */
static void cdnDisconnectCb(CUSBD_PrivateData *pD) 
{
    CUSBD_Dev *dev;
    CUSBD_OBJ* drv;
    uint8_t             instNo;
    uint32_t            res = S_PASS;
    usbCdnDcdDevice_t*  cdnDcd;
    tDeviceInfo*        ptDeviceInfo;

    drv = CUSBD_GetInstance();
    if (!drv)
        return;

    drv->getDevInstance(pD, &dev);

    debug_printf("Application: disconnect %c\n", ' ');

    /* dev->name[0] is a digit in ascii, i.e char '1' or '0' 
       convert it to number */
    instNo = (uint8_t)(dev->name[0])- 0x30;

    if (instNo>1)
    {
        /* something is really wrong. corruption? */
        debug_printf("bad usb instance number\n");
        res = (uint32_t)E_FAIL;
    }

    if (res == S_PASS)
    {
        cdnDcd = &g_usb_global.drv_instances[instNo].cdnDcd;

        /* clear the previous configuration number */
        cdnDcd->configValue = 0;

        /* calling application disconnect handler */
        ptDeviceInfo = (tDeviceInfo*)cdnDcd->pDcdCore->ptDeviceInfo;
        if (ptDeviceInfo->sCallbacks.pfnDisconnectHandler)
        {
            ptDeviceInfo->sCallbacks.
                        pfnDisconnectHandler(ptDeviceInfo->pvInstance);
        }
    }

#ifdef _DEBUG_
    displayDeviceInfo(dev);
#endif
}

/****************************************************************************** */
/****************************************************************************** */
static void cdnResumeCb(CUSBD_PrivateData *pD) {
    debug_printf("Application: resume %c\n", ' ');
}


/****************************************************************************** 
 * call-back function for USB setup message 
 **************************************************************************** */
static uint32_t cdnSetupCb(CUSBD_PrivateData *pD, CH9_UsbSetup *ctrl) 
{
    CUSBD_Dev*          dev;
    CUSBD_OBJ*          drv;
    uint8_t             instNo;
    uint32_t            res = S_PASS;
    usbCdnDcdDevice_t*  cdnDcd;

    drv = CUSBD_GetInstance();
    drv->getDevInstance(pD, &dev);

    /* dev->name[0] is a digit in ascii, i.e char '1' or '0' 
       convert it to number */
    instNo = (uint8_t)(dev->name[0])- 0x30;

    if (instNo>1)
    {
        /* something is really wrong. corruption? */
        debug_printf("bad usb instance number\n");
        res = (uint32_t)E_FAIL;
    }

    if (res == S_PASS)
    {
        cdnDcd = &g_usb_global.drv_instances[instNo].cdnDcd;

        switch (dev->speed) {
            case CH9_USB_SPEED_FULL:
                cdnDcd->usbSpeed = USB_SPEED_FULL_SPEED;
                break;

            case CH9_USB_SPEED_HIGH:
                cdnDcd->usbSpeed = USB_SPEED_HIGH_SPEED;
                break;

            case CH9_USB_SPEED_SUPER:
                cdnDcd->usbSpeed = USB_SPEED_SUPER_SPEED_30;
                break;

            default:
                break;
        }

        /* call dev_dman API to pass to our stack */
        cdnDcd->pDcdCore->gadgetObjCallBack.
            pFnDevEndpt0Handler(cdnDcd->pDcdCore->pGadgetObject,
                    USB_ENDPT0_EVENT_SETUP_PACKET_RECEIVED,
                    (usbSetupPkt_t *)ctrl);
    }

    return res;
}

/****************************************************************************** */
/****************************************************************************** */
static void cdnSuspendCb(CUSBD_PrivateData *pD) {
    debug_printf("Application: suspend %c\n", ' ');
}


/******************************************************************************
 * debug functions 
 ****************************************************************************** */
#ifdef _DEBUG_
static void displayDeviceInfo(CUSBD_Dev * dev) 
{
    debug_printf("-------Device INFO--------------- %c\n", ' ');
    debug_printf("epList: prev = 0x%08x, next = 0x%08x\n", 
                  (uintptr_t) dev->epList.prev, 
                  (uintptr_t) dev->epList.next);

    debug_printf("ep0: 0x%08x\n", (uintptr_t) dev->ep0);
    debug_printf("speed: %d\n", dev->speed);
    debug_printf("maxSpeed: %d\n", dev->maxSpeed);
    debug_printf("state: %d\n", dev->state);
    debug_printf("sgSupported: %d\n", dev->sgSupported);
    debug_printf("isOtg: %d\n", dev->isOtg);
    debug_printf("isAPeripheral: %d\n", dev->isAPeripheral);
    debug_printf("bHnpEnable: %d\n", dev->bHnpEnable);
    debug_printf("aHnpSupport: %d\n", dev->aHnpSupport);
    debug_printf("name: %s\n", dev->name);
}

static void displayEndpointInfo(CUSBD_Ep * ep) {
    debug_printf("-------Endpoint INFO------------- %c\n", ' ');
    debug_printf("address: %02x\n", ep->address);
    debug_printf("epList: %p\n", (uintptr_t) & ep->epList);
    debug_printf("name: %s\n", ep->name);
    debug_printf("ops: %c\n", ' ');
    debug_printf("maxPacket: %d\n", ep->maxPacket);
    debug_printf("maxStreams: %d\n", ep->maxStreams);
    debug_printf("mult: %d\n", ep->mult);
    debug_printf("maxburst: %d\n", ep->maxburst);
    debug_printf("desc: %08x\n", (uintptr_t) ep->desc);
    debug_printf("desc: %08x\n", (uintptr_t) ep->desc);
    debug_printf("compDesc: %08x\n", (uintptr_t) ep->compDesc);
}

#endif

/****************************************************************************** */
/****************************************************************************** */
int32_t usbCdnDcdSetConfiguration(usbCdnDcdDevice_t *cdn)
{
    CUSBD_Ep*             ep;
    LIST_ListHead*        list;
    CUSBD_Dev*            dev;
    usbDescriptor_t*      pDescs;
    usbConfigHeader_t*    pConfigHdr;
    tConfigDescriptor*    pConfigDesc;
    CUSBD_OBJ*            drv;
    CUSBD_PrivateData*    pD;
    uint32_t              ulLoop;
    uint32_t              ulNumInterfaces;
    uint32_t              ulNumEndpoints;
    uint32_t              ulCount;
    uint32_t              ulSection;
    tEndpointDescriptor*  psEndpoint;
	tInterfaceDescriptor* psInterface;
    tDeviceInfo*          ptDeviceInfo;

    debug_printf("SET CONFIGURATION(%d)\n", cdn->configNo);
    if (cdn->configNo > 1) 
    {
        return -1; // no such configuration
    }

    if (cdn->dev == 0) 
    {
        return -1;
    }

    dev = cdn->dev;
    pD = &cdn->pD;

    /* unconfigure device */
    if (cdn->configNo == 0) {
        cdn->configValue = 0;
        for (list = dev->epList.next; list != &dev->epList; list = list->next) {
            ep = (CUSBD_Ep *) list;
            if (ep->address == BULK_EP_IN) {
            /*if (ep->address & USB_EP_DESC_IN) { */
                /* EP IN */
                ep->ops->epDisable(pD, ep);
                break;
            }
        }
        for (list = dev->epList.next; list != &dev->epList; list = list->next) {
            ep = (CUSBD_Ep *) list;
            if (ep->address == BULK_EP_OUT) {
            /*if (!(ep->address & USB_EP_DESC_IN)) { */
                /* EP OUT */
                ep->ops->epDisable(pD, ep);
                break;
            }
        }
        dev->state = CH9_USB_STATE_ADDRESS;
        return 0;
    }

    /* device already configured */
    if (cdn->configValue == 1 && cdn->configNo == 1) {
        return 0;
    }

    /* configure device */
    cdn->configValue = (uint8_t) cdn->configNo;

    /* find interface and its endpoints */
    pDescs = &(cdn->pDcdCore->pGadgetObject->pDesc);
    pConfigHdr = pDescs->ppConfigDesc[cdn->configNo-1];

    ulNumInterfaces = USBDCDConfigDescGetNum((tConfigHeader*)pConfigHdr,
                                             USB_DTYPE_INTERFACE);
 
    for(ulLoop=0; ulLoop < ulNumInterfaces; ulLoop++)
    {
        /* Get the next interface descriptor in the config descriptor. */
        psInterface = USBDCDConfigGetInterface((tConfigHeader*)pConfigHdr,
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
                                            (tConfigHeader*)pConfigHdr,
                                            psInterface->bInterfaceNumber,
                                            psInterface->bAlternateSetting,
                                            ulCount);

                /* Make sure we got a good pointer. */
                if(psEndpoint)
                {
                    /* Make sure no-one is trying to configure endpoint 0. */
                    if((psEndpoint->bEndpointAddress & 0xF) == 0)
                    {
                        return(false);
                    }

                    for (list = dev->epList.next; list != &dev->epList; list = list->next) 
                    {
                        ep = (CUSBD_Ep *)list;

                        if ((ep->address) == psEndpoint->bEndpointAddress)
                        {
                            debug_printf("configuring EP: 0x%x\n", ep->address);

                            ep->ops->epEnable(pD, ep, (uint8_t*)psEndpoint);
#ifdef _DEBUG_
                            displayEndpointInfo(ep);
#endif
                            /* init the Ep pointers in CdnDcd obj */
                            if ((ep->address & USB_EP_DESC_IN)) 
                            {
                                cdn->bulkInEp = ep; 
                            }
                            else
                            {
                                cdn->bulkOutEp = ep; 
                            }
                            break;
                        }
                    }
                }
            } /* end for */
        } /* if interface */
    } /* for uLoop */

    dev->state = CH9_USB_STATE_CONFIGURED;

    pConfigDesc = (tConfigDescriptor*)
                    USBDCDConfigDescGet((tConfigHeader*)pConfigHdr,
                                        USB_DTYPE_CONFIGURATION,
                                        0, /* first configuration desc */
                                        &ulSection);

    drv = CUSBD_GetInstance();

    /*Code control  Self powered feature of USB*/
    if (pConfigDesc->bmAttributes & CH9_USB_CONFIG_SELF_POWERED) {
        if (drv->dSetSelfpowered) {
            drv->dSetSelfpowered(pD);
        }
    } else {
        if (drv->dClearSelfpowered) {
            drv->dSetSelfpowered(pD);
        }
    }

    /* If there is a configuration change callback then call it. */
    ptDeviceInfo = (tDeviceInfo*)cdn->pDcdCore->ptDeviceInfo;
    if (ptDeviceInfo->sCallbacks.pfnConfigChange)
    {
        ptDeviceInfo->sCallbacks.
                pfnConfigChange(ptDeviceInfo->pvInstance,
                                cdn->configNo, 
                                cdn->instanceNo);
    }
    return 0;
}

