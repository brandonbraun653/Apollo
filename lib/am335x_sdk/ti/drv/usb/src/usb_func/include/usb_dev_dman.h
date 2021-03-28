/**
 * \file    usb_dev_dman.h
 *
 *          Gadget Device manager
 *          This file contains data structures and prototypes encapsulating
 *          the device manager functionlity of a USB gadget. Device manager
 *          is responsible for enumerating a device and ep0 handling .
 *
 *
 *
 */
/**
 *  Copyright (c) Texas Instruments Incorporated 2015-2016
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



#ifndef USB_DEV_DMAN_H_
#define USB_DEV_DMAN_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "usb_dev_object.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
/** \brief Maximum number of devices/gadgets that can be supported equals
           the number of controllers in the SOC.*/
#define MAX_NUM_DEVICE_CONTROLLERS (2U)



/** \brief Function prototype for any standard USB request.*/
typedef void (* pFnStdRequest)(struct usbGadgetObj *pGadgetObject,
        usbSetupPkt_t * pSetup);

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This API initialise the gadget list with the core objects available.
 */
void USBDInitCoreObject(void);

/**
 * \brief   This function initialises the USB gadget device object and then
 *          calls the init routine of the device controller which it represents.
 *
 * \param   pUsbGadgetObj pointer to usb gadget object usbGadgetObj_t
 * \param   pName pointer to string containing controller instance name.
 *          this instance would be assigned with the string passed to it.
 *
 * \retval error status- Status of the API call. Can be any of the following,
 *      S_PASS - indicates the operation is success
 *      E_FAIL - indicates the module is not enabled (timeout)
 *      E_INVALID_PARAM - gadget object pointer not valid
 */
uint32_t USBDeviceInit( usbGadgetObj_t *pUsbGadgetObj, const char* pName );

/**
 * \brief This function handles the request EP0 requests which come
 *        from the lower layer driver. The protocol layer will interpret the
 *        setup packet and call the required function accordingly.
 *
 * \param pUsbGadgetObj pointer to the USB gadget object.
 * \param endptEvent Endpoint event which has occured.
 * \param pSetup pointer to the setup packet received by the USB
 *
 */

uint32_t USBDevEndpt0Handler(struct usbGadgetObj *pUsbGadgetObj,
    usbEndpt0event_t endptEvent, usbSetupPkt_t * pSetup );


/**
 * \brief This function handles the USB EP0 request complete.
 *
 * \param pUsbGadgetObj pointer to the USB gadget object.
 * \param pReq pointer to the USB request which has been completed
 */
void usbEp0reqComplete(struct usbGadgetObj * pUsbGadgetObj,
    struct usbDevRequest *pReq);


/**
 * Setup Endpoint request.
 * This request is requested by the class driver
 * Same function is used for endpoint 0 and other endpoints request.
 *
 * \param  pUsbGadgetObj pointer to the USB gadget object.
 * \param  epNum Endpoint number on which the request has to be made.
 * \param pUsbData Pointer to the data in which data has been received or
 *        the data contained by this pointer is to be sent.
 * \param tokenType The type of token or the direction field.
 * \param length Length of the transfer
 * \param transferType The type of transfer which has to be initiated.
 */
void usbSetupEpReq(void * pUsbGadgetObj,
    uint32_t epNum, uint32_t * pUsbData, usbTokenType_t tokenType,
    uint32_t length, usbTransferType_t transferType);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef USB_DEV_DMAN_H_ */
