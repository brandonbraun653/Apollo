/* ***************************************************************************** */
/* usbdcdc.h - USBLib support for generic CDC ACM (serial) device. 
 *
 * Copyright (c) 2008-2019 Texas Instruments Incorporated.  
 *
 *******************************************************************************
 *
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
/* This is part of AM1808 StarterWare USB Library and reused from revision 6288 */
/* of the  Stellaris USB Library. */
/* ***************************************************************************** */

#ifndef __USBDCDC_H__
#define __USBDCDC_H__

/* ***************************************************************************** */
/* If building with a C++ compiler, make all of the definitions in this header */
/* have a C binding. */
/* ***************************************************************************** */
#ifdef __cplusplus
extern "C"
{
#endif

/* ***************************************************************************** */
/* \addtogroup cdc_device_class_api */
/* @{ */
/* ***************************************************************************** */

/* ***************************************************************************** */
/* PRIVATE */
/* The first few sections of this header are private defines that are used by */
/* the USB CDC Serial code and are here only to help with the application */
/* allocating the correct amount of memory for the CDC Serial device code. */
/* ***************************************************************************** */



#define CTL_IN_EP_MAX_SIZE      (16)

/* ***************************************************************************** */
/* PRIVATE */
/* This enumeration holds the various states that the device can be in during */
/* normal operation. */
/* ***************************************************************************** */
typedef enum
{
    /* Unconfigured. */
    CDC_STATE_UNCONFIGURED,

    /* No outstanding transaction remains to be completed. */
    CDC_STATE_IDLE,

    /* Waiting on completion of a receive transaction. */
    CDC_STATE_WAIT_DATA,

    /* waitig for complete of an IN transaction */
    CDC_STATE_WAIT_TX_COMPLETE,

    /* Waiting for client to process data. */
    CDC_STATE_WAIT_CLIENT
}
tCDCState;

/* ***************************************************************************** */
/* PRIVATE */
/* This structure defines the private instance data and state variables for the */
/* CDC Serial device.  The memory for this structure is pointed to by the */
/* psPrivateCDCSerData field in the tUSBDCDCDevice structure passed on */
/* USBDCDCInit(). */
/* ***************************************************************************** */
typedef struct
{
    tDeviceInfo *psDevInfo;
    tConfigDescriptor *psConfDescriptor;
    volatile tCDCState eCDCRxState;
    volatile tCDCState eCDCTxState;
    volatile tCDCState eCDCRequestState;
    volatile tCDCState eCDCInterruptState;
    volatile uint8_t ucPendingRequest;
    uint16_t usBreakDuration;
    uint16_t usControlLineState;
    uint16_t usSerialState;
    volatile uint32_t usDeferredOpFlags;
    uint16_t usLastTxSize;
    uint16_t usLastRxSize;
    tLineCoding sLineCoding;
    volatile tBoolean bRxBlocked;
    volatile tBoolean bControlBlocked;
    volatile tBoolean bConnected;
    uint8_t ucControlEndpoint;
    uint8_t ucBulkINEndpoint;
    uint8_t ucBulkOUTEndpoint;
    uint8_t ucInterfaceControl;
    uint8_t ucInterfaceData;

    /* buffer for interrupt endpoint */
    uint8_t notificationBuf[CTL_IN_EP_MAX_SIZE] __attribute__ ((aligned(32U)));
}
tCDCSerInstance;



/* ***************************************************************************** */
/* The following defines are used when working with composite devices. */
/* ***************************************************************************** */

/* ***************************************************************************** */
/* The size of the memory that should be allocated to create a configuration */
/* descriptor for a single instance of the USB Serial CDC Device. */
/* This does not include the configuration descriptor which is automatically */
/* ignored by the composite device class. */
/* For reference this is sizeof(g_pIADSerDescriptor) + */
/* sizeof(g_pCDCSerCommInterface) + sizeof(g_pCDCSerDataInterface) */
/* ***************************************************************************** */
#define COMPOSITE_DCDC_SIZE     (8 + 35 + 23)

/* ***************************************************************************** */
/* CDC-specific events These events are provided to the application in the */
/* \e ulMsg parameter of the tUSBCallback function. */
/* ***************************************************************************** */

/* The host requests that the device send a BREAK condition on its */
/* serial communication channel.  The BREAK should remain active until */
/* a USBD_CDC_EVENT_CLEAR_BREAK event is received. */
#define USBD_CDC_EVENT_SEND_BREAK (USBD_CDC_EVENT_BASE + 0)

/* The host requests that the device stop sending a BREAK condition on its */
/* serial communication channel. */
#define USBD_CDC_EVENT_CLEAR_BREAK (USBD_CDC_EVENT_BASE + 1)

/* The host requests that the device set the RS232 signaling lines to */
/* a particular state.  The ulMsgValue parameter contains the RTS and */
/* DTR control line states as defined in table 51 of the USB CDC class */
/* definition and is a combination of the following values: */
/* */
/* (RTS) USB_CDC_DEACTIVATE_CARRIER or USB_CDC_ACTIVATE_CARRIER */
/* (DTR) USB_CDC_DTE_NOT_PRESENT or USB_CDC_DTE_PRESENT */
#define USBD_CDC_EVENT_SET_CONTROL_LINE_STATE (USBD_CDC_EVENT_BASE + 2)

/* The host requests that the device set the RS232 communication */
/* parameters.  The pvMsgData parameter points to a tLineCoding structure */
/* defining the required number of bits per character, parity mode, */
/* number of stop bits and the baud rate. */
#define USBD_CDC_EVENT_SET_LINE_CODING (USBD_CDC_EVENT_BASE + 3)

/* The host is querying the current RS232 communication parameters.  The */
/* pvMsgData parameter points to a tLineCoding structure that the */
/* application must fill with the current settings prior to returning */
/* from the callback. */
#define USBD_CDC_EVENT_GET_LINE_CODING (USBD_CDC_EVENT_BASE + 4)

/* ***************************************************************************** */
/* The structure used by the application to define operating parameters for */
/* the CDC device. */
/* ***************************************************************************** */
typedef struct
{
    /* The vendor ID that this device is to present in the device descriptor. */
    uint16_t usVID;


    /* The product ID that this device is to present in the device descriptor. */
    uint16_t usPID;


    /* The maximum power consumption of the device, expressed in milliamps. */
    uint16_t usMaxPowermA;


    /* Indicates whether the device is self- or bus-powered and whether or not */
    /* it supports remote wakeup.  Valid values are USB_CONF_ATTR_SELF_PWR or */
    /* USB_CONF_ATTR_BUS_PWR, optionally ORed with USB_CONF_ATTR_RWAKE. */
    uint8_t ucPwrAttributes;


    /* A pointer to the callback function which will be called to notify */
    /* the application of all asynchronous control events related to the */
    /* operation of the device. */
    tUSBCallback pfnControlCallback;


    /* A client-supplied pointer which will be sent as the first */
    /* parameter in all calls made to the control channel callback, */
    /* pfnControlCallback. */
    void *pvControlCBData;


    /* A pointer to the callback function which will be called to notify */
    /* the application of events related to the device's data receive channel. */
    tUSBCallback pfnRxCallback;


    /* A client-supplied pointer which will be sent as the first */
    /* parameter in all calls made to the receive channel callback, */
    /* pfnRxCallback. */
    void *pvRxCBData;


    /* A pointer to the callback function which will be called to notify */
    /* the application of events related to the device's data transmit */
    /* channel. */
    tUSBCallback pfnTxCallback;


    /* A client-supplied pointer which will be sent as the first */
    /* parameter in all calls made to the transmit channel callback, */
    /* pfnTxCallback. */
    void *pvTxCBData;


    /* A pointer to the string descriptor array for this device.  This array */
    /* must contain the following string descriptor pointers in this order. */
    /* Language descriptor, Manufacturer name string (language 1), Product */
    /* name string (language 1), Serial number string (language 1), */
    /* Control interface description string (language 1), Configuration */
    /* description string (language 1). */
    /* */
    /* If supporting more than 1 language, the strings for indices 1 through 5 */
    /* must be repeated for each of the other languages defined in the */
    /* language descriptor. */
    const uint8_t * const *ppStringDescriptors;

    /* The number of descriptors provided in the ppStringDescriptors */
    /* array.  This must be 1 + (5 * number of supported languages). */
    uint32_t ulNumStringDescriptors;

    /* A pointer to the private instance data for this device.  This memory */
    /* must remain accessible for as long as the CDC device is in use and must */
    /* not be modified by any code outside the CDC class driver. */
    tCDCSerInstance *psPrivateCDCSerData;
}
tUSBDCDCDevice;

extern tDeviceInfo g_sCDCSerDeviceInfo;

/* ***************************************************************************** */
/* API Function Prototypes */
/* ***************************************************************************** */
extern void * USBDCDCCompositeInit(void* pUsbGadgetObj,
                                   tUSBDCDCDevice *psCDCDevice, 
                                   USB_Params* pUsbParams);
extern void *USBDCDCInit(void* pUsbGadgetObj,
                         tUSBDCDCDevice *psCDCDevice, 
                         USB_Params* pUsbParams);


extern void USBDCDCTerm(void *pvInstance);
extern void *USBDCDCSetControlCBData(void *pvInstance, void *pvCBData);
extern void *USBDCDCSetRxCBData(void *pvInstance, void *pvCBData);
extern void *USBDCDCSetTxCBData(void *pvInstance, void *pvCBData);
extern int32_t USBD_cdcWrite(USB_Handle handle, uint8_t *buffer, uint32_t dataSize);
extern int32_t USBD_cdcRead(USB_Handle handle, uint8_t* buffer, uint32_t* dataSize);

extern uint32_t USBDCDCTxPacketAvailable(void *pvInstance);
extern uint32_t USBDCDCRxPacketAvailable(void *pvInstance);
extern void USBDCDCSerialStateChange(void *pvInstance,
                                     uint16_t usState);

/* ***************************************************************************** */
/* Close the Doxygen group. */
/* @} */
/* ***************************************************************************** */

/* ***************************************************************************** */
/* Mark the end of the C bindings section for C++ compilers. */
/* ***************************************************************************** */
#ifdef __cplusplus
}
#endif

#endif /* __USBDCDC_H__ */
