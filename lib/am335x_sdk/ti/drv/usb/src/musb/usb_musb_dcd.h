/**
 *  \file  usb_musb_dcd.h
 *
 *  \brief Device Abstraction layer header for USB MUSB device
 *         contoller driver.
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

#ifndef USB_DCD_MUSB_H_
#define USB_DCD_MUSB_H_


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "hw_usb.h"


/* USB core and protocol specific files */
#include "usb_dcd_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* Define the max packet size for endpoint zero. */
#define EP0_MAX_PACKET_SIZE     64

/****************************************************************************** */
/*! The maximum number of independent interfaces that any single device */
/*! implementation can support.  Independent interfaces means interface */
/*! descriptors with different bInterfaceNumber values - several interface */
/*! descriptors offering different alternative settings but the same interface */
/*! number count as a single interface. */
/****************************************************************************** */
#define USB_MAX_INTERFACES_PER_DEVICE 8


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */



/**
 * \brief This enum contains the possible values of
 *        state of endpoint 0
 */
typedef enum usbMusbDcdEp0State
{
    /* The USB device is waiting on a request from the host controller on */
    /* endpoint zero. */
    USB_MUSB_STATE_IDLE = 0,

    /* The USB device is sending data back to the host due to an IN request. */
    USB_MUSB_STATE_TX,

    /* The USB device is sending the configuration descriptor back to the host */
    /* due to an IN request. */
    USB_MUSB_STATE_TX_CONFIG,

    /* The USB device is receiving data from the host due to an OUT */
    /* request from the host. */
    USB_MUSB_STATE_RX,

    /* The USB device has completed the IN or OUT request and is now waiting */
    /* for the host to acknowledge the end of the IN/OUT transaction.  This */
    /* is the status phase for a USB control transaction. */
    USB_MUSB_STATE_STATUS,

    /* This endpoint has signaled a stall condition and is waiting for the */
    /* stall to be acknowledged by the host controller. */
    USB_MUSB_STATE_STALL

}tEP0State;

/* macros to flag if an endpoint request  */
/* is an OUT or an IN request. Used for DCD interface. */
#define MUSB_DCD_EP_DIR_OUT     0x10
#define MUSB_DCD_EP_DIR_IN      0x80

/* will be removed after we integrate Bulk transport with DCD */
#define MUSB_DCD_EP_BULK_DIR_IN 0x88

/****************************************************************************** */
/* The USB controller device information. */
/****************************************************************************** */
typedef struct
{
    /* The device information for the USB device. */
    tDeviceInfo *psInfo;

    /* The instance data for the USB device. */
    void *pvInstance;

    /* The current state of endpoint zero. */
    volatile tEP0State eEP0State;

    /* The devices current address, this also has a change pending bit in the */
    /* MSB of this value specified by DEV_ADDR_PENDING. */
    volatile unsigned int ulDevAddress;

    /* This holds the current active configuration for this device. */
    unsigned int ulConfiguration;

	/*This holds the alternate configuration for this device required by host*/
	uint32_t ulAlternateConfig;

    /* This holds the configuration id that will take effect after a reset. */
    unsigned int ulDefaultConfiguration;

    /* This holds the current active interface for this device. */
    unsigned int ulInterface;

    /* This holds the interface id that will take effect after a reset. */
    unsigned int ulDefaultInterface;

    /* This holds the current alternate interface for this device. */
    unsigned char pucAltSetting[USB_MAX_INTERFACES_PER_DEVICE];

    /* This is the pointer to the current data being sent out or received */
    /* on endpoint zero. */
    unsigned char *pEP0Data;

    /* This is the number of bytes that remain to be sent from or received */
    /* into the g_sUSBDeviceState.pEP0Data data buffer. */
    volatile unsigned int ulEP0DataRemain;

    /* The amount of data being sent/received due to a custom request. */
    unsigned int ulOUTDataSize;

    /* Holds the current device status. */
    unsigned char ucStatus;

    /* Holds the endpoint status for the HALT condition.  This array is sized */
    /* to hold halt status for all IN and OUT endpoints. */
    unsigned char ucHalt[2][NUM_USB_EP - 1];

    /* Holds the configuration descriptor section number currently being sent */
    /* to the host. */
    unsigned char ucConfigSection;

    /* Holds the offset within the configuration descriptor section currently */
    /* being sent to the host. */
    unsigned char ucSectionOffset;

    /* Holds the index of the configuration that we are currently sending back */
    /* to the host. */
    unsigned char ucConfigIndex;

    /* This flag is set to true if the client has called USBDPowerStatusSet */
    /* and tells the USB library not to try to determine the current power */
    /* status from the configuration descriptor. */
    tBoolean bPwrSrcSet;

    /* This flag indicates whether or not remote wake up signaling is in */
    /* progress. */
    tBoolean bRemoteWakeup;

    /* During remote wake up signaling, this counter is used to track the */
    /* number of milliseconds since the signaling was initiated. */
    unsigned char ucRemoteWakeupCount;
}
tDeviceInstance;



/**
 * \brief Musb device object used by the MUSB driver
 */
typedef struct usbMusbDcdDevice
{
    uint32_t baseAddr;               /**< Base address of the USB core  */

    uint32_t uiSubBaseAddr;          /**< Base address of the USB wrapper/controller */

    uint32_t phyBaseAddr;            /**< Base address of USB PHY control registers */

    char name[10];                   /**< name of the device controller */
    uint32_t controllerId;           /**< ID of the controllerr */ 
    uint32_t deviceNewAddrValidFlag; /**< Check if New device address 
                                          has been assigned */
    uint32_t devAddr;                /**< Device address */
    usbDcd_t *pDcdCore;              /**< Pointer to the DCD code, 
                                          used for callbacks to the core */

    uint32_t isConnected;         /* Flag to tell whether USB is connected or not */

    usbEndptRequest_t*  inEpReq;   /**< Current endpoint request for in transfer*/

    usbEndptRequest_t* outEpReq;   /**< Current endpoint request for out transfer */

    uint32_t ulIrqStatus;         /* 15 TX FIFO interrupts and device interrupt */
    uint32_t epIrqStatus;         /* endpoint interrupt status */
    uint32_t dmaStatus;           /* USBSS IRQ status */

    uint32_t lastReqDirection;    /* last request is an IN/OUT req */

    tDeviceInstance    deviceInstance;  /* musb pvInstance */
    
    uint32_t ulUSBSOFCount;       /* debug & stats of interrupts and events */
    uint32_t ulUSBEP0IntCount;
    uint32_t ulUSBIntCount;
    uint32_t ulUSBEPIntCount;
    uint32_t ulUSBRstCount;
}usbMusbDcdDevice_t;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief USB MUSB device controller driver core init API.
 *
 * \param pDcdObject pointer to the USB device control driver object
 */
uint32_t USBMusbDcdInit(usbDcd_t * pDcdObject);

/**
 * \brief USB MUSB device interrupt handler.
 *        This will get all the device and endpoint events for all the
 *        endpoints.
 *
 * \param MUSB pointer to the MUSB object
 */
uint32_t USBMusbDcdIntrHandler(usbMusbDcdDevice_t *MUSB);

/**
 * \brief This API sets the device characteristics
 *
 * \param pDcdObject pointer to the USB device control object.
 * \param pDevCharacteristic pointer to the device characteristics
 *        structure.
 */
uint32_t USBMusbDcdConfigDevChara( usbDcd_t * pDcdObject,
                                   usbDevChara_t *pDevCharacteristic);

/**
 * \brief Endpoint 0 request for control endpoint
 *
 * \param pDcdObject pointer to the USB device control object.
 * \param req USB request which needs to be handled for endpoint 0
 */
uint32_t USBMusbDcdEp0Req(usbDcd_t *pDcdObject,
                          usbEndpt0Request_t* req);

/**
 * \brief Endpoint request for control bulk and isoch transfers
 *        for all endpoints other than endpoint 0.
 *
 * \param pDcdObject pointer to the USB device control object.
 * \param req USB request which needs to be handled for endpoint other than
 *        endpoint 0.
 */
uint32_t USBMusbDcdEpReq( usbDcd_t * pDcdObject,
                          usbEndptRequest_t* req);

/** \brief Enable all the wrapper interrupts
 *  \param baseAddr Baseaddress of USB wrapper register
 */
void usbMusbDcdEnableWrapperIntr(uint32_t baseAddr);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef USB_DCD_MUSB_H_ */
