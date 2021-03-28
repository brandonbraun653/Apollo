/*******************************************************************************/
/* usbdaudio.h - USB audio device class driver. */
/*******************************************************************************/
/**
 *  Copyright (c) Texas Instruments Incorporated 2015-2017
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

#ifndef __USBDAUDIO_H__
#define __USBDAUDIO_H__

#include "usblib.h"

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
//! \addtogroup audio_device_class_api
//! @{
//
//*****************************************************************************

typedef void (* tUSBAudioBufferCallback)(void *pvBuffer, unsigned long ulParam,
                                         unsigned long ulEvent);

//*****************************************************************************
//
// PRIVATE
//
// This structure defines the private instance data and state variables for the
// audio device class.  The memory for this structure is pointed to by
// the psPrivateData field in the tUSBDAudioDevice structure passed on
// USBDAudioInit() and should not be modified by any code outside of the audio
// device.
//
//*****************************************************************************
typedef struct
{
    unsigned long ulUSBBase;
    tDeviceInfo *psDevInfo;
    tConfigDescriptor *psConfDescriptor;

    //
    // The maximum volume expressed as an 8.8 signed value.
    //
    short sVolumeMax;

    //
    // The minimum volume expressed as an 8.8 signed value.
    //
    short sVolumeMin;

    //
    // The minimum volume step expressed as an 8.8 signed value.
    //
    short sVolumeStep;

    struct
    {
        //
        // Pointer to a buffer provided by caller.
        //
        void *pvData;

        //
        // Size of the data area provided in pvData in bytes.
        //
        unsigned long ulSize;

        //
        // Number of valid bytes copied into the pvData area.
        //
        unsigned long ulNumBytes;

        //
        // The buffer callback for this function.
        //
        tUSBAudioBufferCallback pfnCallback;
    } sBuffer;

    struct
    {
        //
        // Pointer to a buffer provided by caller.
        //
        void *pvData;

        //
        // Size of the data area provided in pvData in bytes.
        //
        unsigned long ulSize;

        //
        // Number of valid bytes copied into the pvData area.
        //
        unsigned long ulNumBytes;

        //
        // The buffer callback for this function.
        //
        tUSBAudioBufferCallback pfnCallback;
    } sBufferRec;

    //
    // Pending request type.
    //
    unsigned short usRequestType;

    //
    // Pending request.
    //
    unsigned char ucRequest;

    //
    // Pending update value.
    //
    unsigned short usUpdate;

    //
    // Current Volume setting.
    //
    short sVolume;

    //
    // Current Mute setting.
    //
    unsigned char ucMute;

    //
    // Current Sample rate, this is not writable but the host will try.
    //
    unsigned long ulSampleRate;

    //
    // The OUT endpoint in use by this instance.
    //
    unsigned char ucOUTEndpoint;

    //
    // The IN endpoint in use by this instance.
    //
    unsigned char ucINEndpoint;

    //
    // The OUT endpoint DMA channel in use by this instance.
    //
    unsigned char ucOUTDMA;

    //
    // The control interface number associated with this instance.
    //
    unsigned char ucInterfaceControl;

    //
    // The audio interface number associated with this instance.
    //
    unsigned char ucInterfaceAudio;

    //
    // The play and rec interface CDMA init flag
    //
    unsigned char ucInterfaceAudioCDMAPlayInitFlag;
    unsigned char ucInterfaceAudioCDMARecInitFlag;
}
tAudioInstance;

//*****************************************************************************
//
// Endpoints to use for each of the required endpoints in the driver.
//
//*****************************************************************************
#define ISOC_OUT_ENDPOINT       		USB_EP_1
#define ISOC_IN_ENDPOINT          		USB_EP_2

//*****************************************************************************
//
// Max size is (48000 samples/sec * 4 bytes/sample) * 0.001 seconds/frame.
//
//*****************************************************************************
#define ISOC_OUT_EP_MAX_SIZE    ((48000*4)/1000)
#define ISOC_IN_EP_MAX_SIZE    ((48000*4)/1000)


//*****************************************************************************
//
//! This is the size in bytes of the private data for the device audio class.
//
//*****************************************************************************
#define USB_AUDIO_INSTANCE_SIZE sizeof(tAudioInstance);

//*****************************************************************************
//
//! The size of the memory that should be allocated to create a configuration
//! descriptor for a single instance of the USB Audio Device.
//! This does not include the configuration descriptor which is automatically
//! ignored by the composite device class.
//
// This value must be at least sizeof(g_pIADAudioDescriptor) +
// sizeof(g_pAudioControlInterface) +
// sizeof(g_sAudioStreamInterfaceSection)
//
//*****************************************************************************
#define COMPOSITE_DAUDIO_SIZE   (8 + 52 + 52)

//*****************************************************************************
//
//! The structure used by the application to define operating parameters for
//! the device audio class.
//
//*****************************************************************************
typedef struct
{
    //
    //! The vendor ID that this device is to present in the device descriptor.
    //
    unsigned short usVID;

    //
    //! The product ID that this device is to present in the device descriptor.
    //
    unsigned short usPID;

    //
    //! 8 byte vendor string.
    //
    unsigned char pucVendor[8];

    //
    //! 16 byte vendor string.
    //
    unsigned char pucProduct[16];

    //
    //! 4 byte vendor string.
    //
    unsigned char pucVersion[4];

    //
    //! The maximum power consumption of the device, expressed in mA.
    //
    unsigned short usMaxPowermA;

    //
    //! Indicates whether the device is self or bus-powered and whether or not
    //! it supports remote wake up.  Valid values are USB_CONF_ATTR_SELF_PWR or
    //! USB_CONF_ATTR_BUS_PWR, optionally ORed with USB_CONF_ATTR_RWAKE.
    //
    unsigned char ucPwrAttributes;

    //
    //! A pointer to the string descriptor array for this device.  This array
    //! must contain the following string descriptor pointers in this order.
    //! Language descriptor, Manufacturer name string (language 1), Product
    //! name string (language 1), Serial number string (language 1), Audio
    //! Interface description string (language 1), Configuration description
    //! string (language 1).
    //!
    //! If supporting more than 1 language, the descriptor block (except for
    //! string descriptor 0) must be repeated for each language defined in the
    //! language descriptor.
    //!
    //
    const unsigned char * const *ppStringDescriptors;

    //
    //! The number of descriptors provided in the ppStringDescriptors
    //! array.  This must be 1 + ((5 + (number of strings)) *
    //!                           (number of languages)).
    //
    unsigned long ulNumStringDescriptors;

    //
    //! A pointer to the callback function which will be called to notify
    //! the application of events relating to the operation of the audio
    //! device.
    //
    tUSBCallback pfnCallback;

    //
    //! The maximum volume expressed as an 8.8 signed value.
    //
    short sVolumeMax;

    //
    //! The minimum volume expressed as an 8.8 signed value.
    //
    short sVolumeMin;

    //
    //! The minimum volume step expressed as an 8.8 signed value.
    //
    short sVolumeStep;

    //
    //! A pointer to private instance data for the audio device.  This memory
    //! must remain accessible for as long as the audio device is in use and
    //! must not be modified by any code outside the audio class driver.
    //
    tAudioInstance *psPrivateData;
}
tUSBDAudioDevice;

//*****************************************************************************
//
// Audio specific device class driver events
//
//*****************************************************************************

//*****************************************************************************
//
//! This USB audio event indicates that the device is connected but not active.
//
//*****************************************************************************
#define USBD_AUDIO_EVENT_IDLE   (USBD_AUDIO_EVENT_BASE + 0)

//*****************************************************************************
//
//! This USB audio event indicates that the device is connected and is now
//! active.
//
//*****************************************************************************
#define USBD_AUDIO_EVENT_ACTIVE (USBD_AUDIO_EVENT_BASE + 1)

//*****************************************************************************
//
//! This USB audio event indicates that the device is returning a data buffer
//! provided by the USBAudioBufferOut() function back to the application with
//! valid audio data received from the USB host controller. The \e pvBuffer
//! parameter holds the pointer to the buffer with the new audio data and
//! the \e ulParam value holds the amount of valid data in bytes that are
//! contained in the \e pvBuffer parameter.
//
//*****************************************************************************
#define USBD_AUDIO_EVENT_DATAOUT (USBD_AUDIO_EVENT_BASE + 2)

//*****************************************************************************
//
//! This USB audio event indicates that the device is sending a data buffer
//! through the USBAudioBufferIn() function to the USB host with. The \e pvBuffer
//! parameter holds the pointer to the data buffer with the audio data and
//! the \e ulParam value holds the amount of valid data in bytes that are
//! contained in the \e pvBuffer parameter.
//
//*****************************************************************************
#define USBD_AUDIO_EVENT_DATAIN (USBD_AUDIO_EVENT_BASE + 3)

//*****************************************************************************
//
//! This USB audio event indicates that a volume change has occured.  The
//! \e ulParam value contains a signed 8.8 fixed point value that represents
//! the current volume gain/attenuation in decibels(dB).  The provided message
//! handler should be prepared to handle negative and positive values with the
//! value 0x8000 indicating maximum attenuation.  The \e pvBuffer parameter
//! should be ignored.
//
//*****************************************************************************
#define USBD_AUDIO_EVENT_VOLUME (USBD_AUDIO_EVENT_BASE + 4)

//*****************************************************************************
//
//! This USB audio event indicates that a mute request has occured.  The
//! \e ulParam value will either be a 1 to indicate that the audio is now
//! muted, and a value of 0 indicates that the audio has been unmuted.
//
//*****************************************************************************
#define USBD_AUDIO_EVENT_MUTE   (USBD_AUDIO_EVENT_BASE + 5)

extern tDeviceInfo g_sAudioDeviceInfo;

//*****************************************************************************
//
// API Function Prototypes
//
//*****************************************************************************
extern void *USBDAudioInit(void * pUsbGadgetObj, tUSBDAudioDevice *psDevice);
extern void *USBDAudioCompositeInit(struct usbGadgetObj *pGadgetObj,
                                    const tUSBDAudioDevice *psAudioDevice);
extern void USBDAudioTerm(void *pvInstance);
extern long USBAudioBufferOut(void *pvInstance, void *pvBuffer,
                              unsigned long ulSize,
                              tUSBAudioBufferCallback pfnCallback);
extern long USBAudioBufferIn(void *pvInstance, void *pvBuffer,
                              unsigned long ulSize,
                              tUSBAudioBufferCallback pfnCallback);

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif

