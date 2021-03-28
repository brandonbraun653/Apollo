/**
 *  \file  usb_cdn_dcd.h
 *
 *  \brief A thin layer between Cadence USB driver and the USB driver
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

#ifndef USB_DCD_CDN_H_
#define USB_DCD_CDN_H_


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* USB core and protocol specific files */
#include "usb_dcd_interface.h"

#include "cusb_ch9_if.h"
#include "cusb_ch9_structs_if.h"
#include "cusbd_if.h"
#include "cusbd_obj_if.h"
#include "cusbd_structs_if.h"
#include "cusbdma_if.h"
#include "cusbdma_structs_if.h"


#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

#define CDN_NUM_EP_MEMRES   (32)  /* 32 endpoints. could be reduced down to the 
                                     number of EP actually being used */
#define CDN_NUM_TRB         (16)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/**
 * \brief cdn device object used by the glue layer with CDN driver
 */
typedef struct usbCdnDcdDevice
{
    char                name[10];   /* name of the device controller */

    CUSBD_SysReq        sysReqCusbd;
    CUSBD_Dev*          dev;        /* USB device pointer */
    CUSBD_OBJ*          drv;        /* pointer to cdn driver */

    /* this pD->setupPacketAlloc needs to be in un-cached area */
    CUSBD_PrivateData   pD;         /* cdn private driver data */

    CUSBD_Config        devConfig;  /* Cdn device config */

    usbSpeed_t          usbSpeed;

    usbDcd_t *          pDcdCore;   /* Pointer to the DCD, used for callbacks to the core */
    uint8_t             instanceNo; /* controller number */
    uint8_t             configNo;   /* configuration request num */
    uint8_t             configValue;/* conf# being used */
    uint8_t             devAddr;    /* usb address */
    uint8_t             deviceNewAddrValidFlag;

    uint32_t            baseAddr;   /* controller base addr */

    CUSBD_Req           ep0Req;

    CUSBD_Req           bulkInReq;
    CUSBD_Req           bulkOutReq;

    CUSBD_Ep*           bulkInEp;   /* these bulkIn and Out EPs match with
                                     * the devConfig above. They are init
                                     * at the endpoint configuration time */
    CUSBD_Ep*           bulkOutEp;

    CUSBDMA_MemResources epMemRes[CDN_NUM_EP_MEMRES];

    uint8_t             setupPacketBuffer[64] __attribute__ ((aligned(8)));

    /* need to put this cdnBuff memory in a non-cached area */
    /* 32 endpoints and 16 TRBs each EP */
    CUSBDMA_DmaTrb      cdnBuff[CDN_NUM_EP_MEMRES][CDN_NUM_TRB]
                                        __attribute__ ((aligned(8)));

} usbCdnDcdDevice_t;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief USB Cdn device controller driver core init API.
 *
 * \param pDcdObject pointer to the USB device control driver object
 */
uint32_t USBCdnDcdInit(usbDcd_t * pDcdObject);

/**
 * \brief USB Cdn device interrupt handler.
 *        This will get all the device and endpoint events for all the
 *        endpoints.
 *
 * \param cdn pointer to the dwc3 object
 */
uint32_t USBCdnDcdCoreIntrHandler(usbCdnDcdDevice_t *cdn);

/**
 * \brief This API sets the device characteristics
 *
 * \param pDcdObject pointer to the USB device control object.
 * \param pDevCharacteristic pointer to the device characteristics
 *        structure.
 */
uint32_t USBCdnDcdConfigDevChara( usbDcd_t * pDcdObject,
                                  usbDevChara_t *pDevCharacteristic);

/**
 * \brief Endpoint 0 request for control endpoint
 *
 * \param pDcdObject pointer to the USB device control object.
 * \param req USB request which needs to be handled for endpoint 0
 */
uint32_t USBCdnDcdEp0Req(usbDcd_t *pDcdObject,
                         usbEndpt0Request_t* req);

/**
 * \brief Endpoint request for control bulk and isoch transfers
 *        for all endpoints other than endpoint 0.
 *
 * \param pDcdObject pointer to the USB device control object.
 * \param req USB request which needs to be handled for endpoint other than
 *        endpoint 0.
 */
uint32_t USBCdnDcdEpReq( usbDcd_t*          pDcdObject,
                         usbEndptRequest_t* req);

/** \brief Enable all the wrapper interrupts
 *  \param baseAddr Baseaddress of USB wrapper register
 */
void usbCdnDcdEnableWrapperIntr(uint32_t baseAddr);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef USB_DCD_DWC_H_ */
