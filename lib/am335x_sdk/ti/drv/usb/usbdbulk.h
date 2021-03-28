 /******************************************************************************
 *
 * usbdbulk.h - USBLib support for a generic bulk device.
 *
 * Copyright (c) 2008-2018 Texas Instruments Incorporated.  
 *
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


#ifndef PDK__USBDBULK_H__
#define PDK__USBDBULK_H__

/******************************************************************************
 *
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 *
 ******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

#include "usbdbulkint.h"
#include "usb_drv.h"

/******************************************************************************
 *
 *! \addtogroup bulk_device_class_api
 *! @{
 *
 ******************************************************************************/


/******************************************************************************
 *
 *! The structure used by the application to define operating parameters for
 *! the bulk device.
 *
 ******************************************************************************/
typedef struct
{
    /*
     *! The vendor ID that this device is to present in the device descriptor.
     */
    uint16_t usVID;

    /*
     *! The product ID that this device is to present in the device descriptor.
     */
    uint16_t usPID;

    /*
     *! The maximum power consumption of the device, expressed in milliamps.
     */
    uint16_t usMaxPowermA;

    /*
     *! Indicates whether the device is self- or bus-powered and whether or not
     *! it supports remote wakeup.  Valid values are USB_CONF_ATTR_SELF_PWR or
     *! USB_CONF_ATTR_BUS_PWR, optionally ORed with USB_CONF_ATTR_RWAKE.
     */
    uint8_t ucPwrAttributes;

    /*
     *! A pointer to the callback function which will be called to notify
     *! the application of events related to the device's data receive channel.
     */
    tUSBCallback pfnRxCallback;

    /*
     *! A client-supplied pointer which will be sent as the first
     *! parameter in all calls made to the receive channel callback,
     *! pfnRxCallback.
     */
    void *pvRxCBData;

    /*
     *! A pointer to the callback function which will be called to notify
     *! the application of events related to the device's data transmit
     *! channel.
     */
    tUSBCallback pfnTxCallback;

    /*
     *! A client-supplied pointer which will be sent as the first
     *! parameter in all calls made to the transmit channel callback,
     *! pfnTxCallback.
     */
    void *pvTxCBData;

    /*
     *! A pointer to the string descriptor array for this device.  This array
     *! must contain pointers to the following string descriptors in this
     *! order.  Language descriptor, Manufacturer name string (language 1),
     *! Product name string (language 1), Serial number string (language 1),
     *! Interface description string (language 1) and Configuration description
     *! string (language 1).
     *!
     *! If supporting more than 1 language, the strings for indices 1 through 5
     *! must be repeated for each of the other languages defined in the
     *! language descriptor.
     */
    const uint8_t * const *ppStringDescriptors;

    /*
     *! The number of descriptors provided in the ppStringDescriptors array.
     *! This must be 1 + (5 * number of supported languages).
     */
    uint32_t ulNumStringDescriptors;

    /*
     *! A pointer to private instance data for this device.  This memory must
     *! remain accessible for as int as the bulk device is in use and must not
     *! be modified by any code outside the bulk class driver.
     */
    tBulkInstance *psPrivateBulkData;
}
tUSBDBulkDevice;

extern tDeviceInfo g_sBulkDeviceInfo;

/******************************************************************************
 *
 * API Function Prototypes
 *
 ******************************************************************************/
extern void *USBDBulkInit(void * pUsbGadgetObj,
                          tUSBDBulkDevice *psDevice,
                          USB_Params* pUsbParams);

extern void *USBDBulkCompositeInit(void * pUsbGadgetObj,
                                   tUSBDBulkDevice *psDevice, 
                                   USB_Params* pUsbParams);

extern void USBDBulkTerm(void *pvInstance);
extern void USBDBulkPowerStatusSet(void *pvInstance, uint8_t ucPower);
extern tBoolean USBDBulkRemoteWakeupRequest(void *pvInstance);

extern int32_t USBD_bulkEnumerated(USB_Handle handle);
extern int32_t USBD_bulkWrite(USB_Handle handle, uint8_t* buffer, uint32_t dataSize);
extern int32_t USBD_bulkRead(USB_Handle handle, uint8_t* buffer, uint32_t* dataSize);


/******************************************************************************
 *
 * Close the Doxygen group.
 *! @}
 *
 ******************************************************************************/

/******************************************************************************
 *
 * Mark the end of the C bindings section for C++ compilers.
 *
 ******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif  /* __USBDBULK_H__*/
