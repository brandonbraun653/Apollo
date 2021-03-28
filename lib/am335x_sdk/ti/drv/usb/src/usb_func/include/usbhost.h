/****************************************************************************** */
/* usbhost.h - Host specific definitions for the USB host library. */
/****************************************************************************** */
/**
 *  Copyright (c) Texas Instruments Incorporated 2015
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


#ifndef PDK__USBHOST_H
#define PDK__USBHOST_H

/****************************************************************************** */
/* If building with a C++ compiler, make all of the definitions in this header */
/* have a C binding. */
/****************************************************************************** */
#ifdef __cplusplus
extern "C"
{
#endif

#include "usblib.h"
#include "usb_drv.h"
/****************************************************************************** */
/*! \addtogroup usblib_hcd */
/*! @{ */
/****************************************************************************** */
/* This is the type used to identify what the pipe is currently in use for. */
/****************************************************************************** */
#define USBHCD_PIPE_UNUSED          0x00100000
#define USBHCD_PIPE_CONTROL         0x00130000
#define USBHCD_PIPE_BULK_OUT        0x00210000
#define USBHCD_PIPE_BULK_IN         0x00220000
#define USBHCD_PIPE_INTR_OUT        0x00410000
#define USBHCD_PIPE_INTR_IN         0x00420000
#define USBHCD_PIPE_ISOC_OUT        0x00810000
#define USBHCD_PIPE_ISOC_IN         0x00820000
#define USBHCD_PIPE_ISOC_OUT_DMA    0x01810000
#define USBHCD_PIPE_ISOC_IN_DMA     0x01820000
#define USBHCD_PIPE_BULK_OUT_DMA    0x01210000
#define USBHCD_PIPE_BULK_IN_DMA     0x01220000


/****************************************************************************** */
/* These are the defines that are used with USBHCDPowerConfigInit(). */
/****************************************************************************** */
#define USBHCD_FAULT_LOW        0x00000010
#define USBHCD_FAULT_HIGH       0x00000030
#define USBHCD_FAULT_VBUS_NONE  0x00000000
#define USBHCD_FAULT_VBUS_TRI   0x00000140
#define USBHCD_FAULT_VBUS_DIS   0x00000400
#define USBHCD_VBUS_MANUAL      0x00000004
#define USBHCD_VBUS_AUTO_LOW    0x00000002
#define USBHCD_VBUS_AUTO_HIGH   0x00000003
#define USBHCD_VBUS_FILTER      0x00010000

/****************************************************************************** */
/* This is a fixed number as it relates to the maximum number of USB pipes */
/* available on any USB controller.  The actual number on a given device may */
/* be less than this number. */
/****************************************************************************** */
#define USBHCD_DEV_RECOVER_RETRY 3

/****************************************************************************** */
/* This is a fixed number as it relates to the maximum number of USB pipes */
/* available on any USB controller.  The actual number on a given device may */
/* be less than this number. */
/****************************************************************************** */
#define MAX_NUM_PIPES           15

/****************************************************************************** */
/* This is a fixed number as it relates to the number of USB pipes available */
/* in the USB controller. */
/****************************************************************************** */
#define MAX_NUM_DMA_CHANNELS    6

/****************************************************************************** */
/* Marker for an unused DMA channel slot. */
/****************************************************************************** */
#define USBHCD_DMA_UNUSED       0xff

/****************************************************************************** */
/* This structure holds the timeOut values for different communications. */
/****************************************************************************** */
#define USB_EP0_TIMEOUT_MILLISECS                   7000
#define USB_NONEP0_TIMEOUT_MILLISECS                7000
#define USB_TIMEOUT_DISABLE                           -1

typedef struct
{
    signed int slEP0;
    signed int slNonEP0;
}
tUSBHTimeOutType;
typedef struct
{
    tUSBHTimeOutType Value;
    tUSBHTimeOutType Status;
}
tUSBHTimeOut;

/****************************************************************************** */
/*! This macro is used to declare an instance of an Event driver for the USB */
/*! library. */
/*! */
/*! \param VarName is the name of the variable. */
/*! \param pfnOpen is the callback for the Open call to this driver.  This */
/*! value is currently reserved and should be set to 0. */
/*! \param pfnClose is the callback for the Close call to this driver.  This */
/*! value is currently reserved and should be set to 0. */
/*! \param pfnEvent is the callback that will be called for various USB events. */
/*! */
/*! The first parameter is the actual name of the variable that will */
/*! be declared by this macro.  The second and third parameter are reserved */
/*! for future functionality and are unused and should be set to zero.  The */
/*! last parameter is the actual callback function and is specified as */
/*! a function pointer of the type: */
/*! */
/*! void (*pfnEvent)(void *pvData); */
/*! */
/*! When the \e pfnEvent function is called the void pointer that is passed in */
/*! as a parameter should be cast to a pointer to a structure of type */
/*! tEventInfo.  This will contain the event that caused the pfnEvent function */
/*! to be called. */
/****************************************************************************** */
#define DECLARE_EVENT_DRIVER(VarName, pfnOpen, pfnClose, pfnEvent)          \
void IntFn(void *pvData);                                                   \
const tUSBHostClassDriver VarName =                                         \
{                                                                           \
    USB_CLASS_EVENTS,                                                       \
    0,                                                                      \
    0,                                                                      \
    pfnEvent                                                                \
}

/****************************************************************************** */
/*! This is the structure that holds all of the information for devices */
/*! that are enumerated in the system.   It is passed in to Open function of */
/*! USB host class drivers so that they can allocate any endpoints and parse */
/*! out other information that the device class needs to complete enumeration. */
/****************************************************************************** */
typedef struct
{
    /*! The current device address for this device. */
    uint32_t ulAddress;

    /*! The current interface for this device. */
    uint32_t ulInterface;

    /*! A pointer to the device descriptor for this device. */
    tDeviceDescriptor DeviceDescriptor;

    /*! A pointer to the configuration descriptor for this device. */
    tConfigDescriptor *pConfigDescriptor;

    /*! The size of the buffer allocated to pConfigDescriptor. */
    uint32_t ulConfigDescriptorSize;
	
    /*! Operating speed of the device */
    uint32_t ulDeviceSpeed;
}
tUSBHostDevice;

/****************************************************************************** */
/*! This structure defines a USB host class driver interface, it is parsed to */
/*! find a USB class driver once a USB device is enumerated. */
/****************************************************************************** */
typedef struct
{
    /*! The interface class that this device class driver supports. */
    uint32_t ulInterfaceClass;

    /*! The function is called when this class of device has been detected. */
    void * (*pfnOpen)(tUSBHostDevice *pDevice, void* usbClass);

    /*! The function is called when the device, originally opened with a call */
    /*! to the pfnOpen function, is disconnected. */
    void (*pfnClose)(void *usbClass);

    /*! This is the optional interrupt handler that will be called when an */
    /*! endpoint associated with this device instance generates an interrupt. */
    void (*pfnIntHandler)(void *usbClass);
}
tUSBHostClassDriver;

/****************************************************************************** */
/*! This structure is used to return generic event based information to an */
/*! application.  The following events are currently supported: */
/*! USB_EVENT_CONNECTED, USB_EVENT_DISCONNECTED, and USB_EVENT_POWER_FAULT. */
/****************************************************************************** */
typedef struct
{
    uint32_t ulEvent;
    void*    usbClass;
}
tEventInfo;

/****************************************************************************** */
/* This is the type definition a call back for events on USB Pipes allocated */
/* by USBHCDPipeAlloc(). */
/* \param ulPipe is well the pipe */
/* \param ulEvent is well the event */
/* inter def thand may need more text in order to be recogized what should */
/* this really say about ourselves. */
/* \return None. */
/****************************************************************************** */
typedef void (* tHCDPipeCallback)(uint32_t ulIndex, uint32_t ulPipe,
                                  uint32_t ulEvent);

/****************************************************************************** */
/* Close the Doxygen group. */
/*! @} */
/****************************************************************************** */

/****************************************************************************** */
/* If the g_USBEventDriver is included in the host controller driver list then */
/* this function must be provided by the application. */
/****************************************************************************** */
void USBHCDEvents(void *pvData);
void USBMOUSEHCDEvents(void *pvData);


/****************************************************************************** */
/* Prototypes for the USB Host controller APIs. */
/****************************************************************************** */
extern uint32_t USBHCDMain(uint32_t ulIndex, void* usbClass);
extern void USBHCDInit(uint32_t ulIndex, void *pData,
                       uint32_t ulSize);
extern void USBHCDPowerConfigInit(uint32_t ulIndex,
                                  uint32_t ulFlags);
extern uint32_t USBHCDPowerConfigGet(uint32_t ulIndex);
extern uint32_t USBHCDPowerConfigSet(uint32_t ulIndex,
                                     uint32_t ulConfig);
extern uint32_t USBHCDPowerAutomatic(uint32_t ulIndex);
extern void
       USBHCDRegisterDrivers(uint32_t ulIndex,
                             const tUSBHostClassDriver * const *ppHClassDrvrs,
                             uint32_t ulNumDrivers);
extern void USBHCDTerm(uint32_t ulIndex);
extern void USBHCDSetConfig(uint32_t ulIndex, uint32_t ulDevice,
                            uint32_t ulConfiguration);
extern void USBHCDSetInterface(uint32_t ulIndex, uint32_t ulDevice,
                               uint32_t ulInterface,
                               unsigned ulAltSetting);
extern uint32_t USBHCDGetSpeed(uint32_t ulIndex);
extern void USBHCDSuspend(uint32_t ulIndex);
extern void USBHCDResume(uint32_t ulIndex);
extern void USBHCDReset(uint32_t ulIndex);
extern void USBHCDPipeFree(uint32_t ulIndex, uint32_t ulPipe);
extern uint32_t USBHCDPipeAlloc(uint32_t ulIndex,
                                uint32_t ulEndpointType,
                                uint32_t ulDevAddr,
                                tHCDPipeCallback pCallback);
extern uint32_t USBHCDPipeAllocSize(uint32_t ulIndex,
                                    uint32_t ulEndpointType,
                                    uint32_t ulDevAddr,
                                    uint32_t ulFIFOSize,
                                    tHCDPipeCallback pCallback);
extern uint32_t USBHCDPipeConfig(uint32_t ulIndex,
                                 uint32_t ulPipe,
                                 uint32_t ulMaxPayload,
                                 uint32_t ulInterval,
                                 uint32_t ulTargetEndpoint);
extern uint32_t USBHCDPipeStatus(uint32_t ulPipe);
extern uint32_t USBHCDPipeWrite(uint32_t ulIndex,
                                uint32_t ulPipe,
                                unsigned char *pData,
                                uint32_t ulSize);
extern uint32_t USBHCDPipeRead(uint32_t ulIndex,
                               uint32_t ulPipe, 
                               unsigned char *pData,
                               uint32_t ulSize);
extern uint32_t USBHCDPipeSchedule(uint32_t ulIndex,
                                   uint32_t ulPipe,
                                   unsigned char *pucData,
                                   uint32_t ulSize);
extern uint32_t USBHCDPipeReadNonBlocking(uint32_t ulIndex, 
                                          uint32_t ulPipe,
                                          unsigned char *pucData,
                                          uint32_t ulSize);
extern uint32_t USBHCDControlTransfer(uint32_t ulIndex,
                                      tUSBRequest *pSetupPacket,
                                      uint32_t ulAddress,
                                      unsigned char *pData,
                                      uint32_t ulSize,
                                      uint32_t ulMaxPacketSize);
extern void USB0HostIntHandler(void);
extern void USB1HostIntHandler(void);
extern void USBHCDTimeOutHook(uint32_t ulIndex, 
                              tUSBHTimeOut **USBHTimeOut);

/****************************************************************************** */
/* The host class drivers supported by the USB library. */
/****************************************************************************** */
extern const tUSBHostClassDriver g_USBHostMSCClassDriver;
extern const tUSBHostClassDriver g_USBHIDClassDriver;
extern const tUSBHostClassDriver g_USBHostAudioClassDriver;

typedef enum    
{
        PIPE_READING = 0,
        PIPE_DATA_READY,
        PIPE_DATA_SENT,
        PIPE_WRITING,
        PIPE_STALLED,
        PIPE_ERROR,
        PIPE_IDLE,
        PIPE_DISABLED
} PIPE_STATE_E;

/****************************************************************************** */
/* This is the structure used to hold the information for a given USB pipe */
/* that is attached to a device. */
/****************************************************************************** */
typedef struct
{
    /* The current address for this pipe. */
    uint32_t ulDevAddr;

    /* The current address for this pipe. */
    unsigned char ucEPNumber;

    /* The DMA channel assigned to this endpoint. */
    unsigned char ucDMAChannel;

    /* The current type for this pipe. */
    uint32_t ulType;

    /* The millisecond interval for this pipe. */
    uint32_t ulInterval;

    /* The next tick value to trigger and event on this pipe. */
    uint32_t ulNextEventTick;

    /* The current call back for this pipe. */
    tHCDPipeCallback pfnCallback;

    /* The state of a given USB pipe. */
    volatile PIPE_STATE_E eState;

    /* The actual FIFO offset allocated to this endpoint. */
    unsigned short usFIFOAddr;

    /* The size of the FIFO entry based on the size parameter.  These are */
    /* equivalent to the USB_FIFO_SZ_* values in usb.h. */
    unsigned char ucFIFOSize;

    /* The bit offset in the allocation structure. */
    unsigned char ucFIFOBitOffset;
	
    /* Speed of the pipe. */
    uint32_t ulPipeSpeed;

    /* Speed of the pipe. */
    uint32_t ulEpMaxPacketSize;	

}
tUSBHCDPipe;

/****************************************************************************** */
/* The internal state of the device. */
/****************************************************************************** */
typedef enum
{
    HCD_DEV_DISCONNECTED,
    HCD_DEV_CONNECTED,
    HCD_DEV_REQUEST,
    HCD_DEV_RESET,
    HCD_DEV_ADDRESSED,
    HCD_DEV_CONFIGURED,
    HCD_DEV_GETSTRINGS,
    HCD_DEV_ERROR,
    HCD_VBUS_ERROR,
    HCD_POWER_FAULT,
    HCD_IDLE,
    HCD_BABBLE_ERROR,
    HCD_DEV_RUNNING
}
tUSBHDeviceState;


/****************************************************************************** */
/* This structure holds the state information for a given host controller. */
/****************************************************************************** */
typedef struct
{

        
    uint32_t ulUSBBase;
    uint32_t ulIndex;
    
    unsigned char *rxBuffer;
    volatile uint32_t ulUSBHIntEvents;
    volatile uint32_t ulDMAPending;
    uint32_t ulPowerConfig;
    volatile uint32_t ulCurrentTick;
    int iUSBHActiveDriver;
    void *pvDriverInstance;

    tUSBHCDPipe USBControlPipe;
    tUSBHCDPipe USBOUTPipes[MAX_NUM_PIPES];
    tUSBHCDPipe USBINPipes[MAX_NUM_PIPES];
    unsigned char ucDMAChannels[MAX_NUM_DMA_CHANNELS];

    /* Each devices state. */
    tUSBHostDevice USBDevice[1];

    /* Holds the current state of the device. */
    volatile tUSBHDeviceState eDeviceState[1];

    /* Pointer to the memory pool for this controller. */
    void *pvPool;

    /* The pool size for this controller. */
    uint32_t ulPoolSize;

    /* The class drivers for this controller. */
    const tUSBHostClassDriver * const *pClassDrivers;

    /* The number of class drivers. */
    uint32_t ulNumClassDrivers;

    /* This is the index in the driver list of the event driver. */
    int iEventDriver;

    /* This is the generic event information used by the event driver. */
    tEventInfo EventInfo;

    uint32_t ulClass;

    /* Error handling specific information. */
    /* This indicates the number of times host trys to re-initiate communication with device before */
    /* escalating to the application. By default, it is initialized to USBHCD_DEV_RECOVER_RETRY */
    /* in HCDINIT. User can update this using 'SET_CONNECT_RETRY' MACRO after HCDINIT */
    uint32_t ulConnectRetry;

    /* This field is maintained by the USB stack and stores the Timeout related information. */
    tUSBHTimeOut USBHTimeOut;

    /* This is a pointer to Timeout related information and can be used by 
       the application. */
    tUSBHTimeOut *pUSBHTimeOut;
}
tUSBHCD;

extern uint32_t g_ulConnectRetry[USB_NUM_INSTANCE];
#define SET_CONNECT_RETRY(USBINSTANCE, RETRY_COUNT) g_ulConnectRetry[USBINSTANCE] = RETRY_COUNT

/****************************************************************************** */
/* Mark the end of the C bindings section for C++ compilers. */
/****************************************************************************** */
#ifdef __cplusplus
}
#endif

#endif /* PDK__USBHOST_H */
