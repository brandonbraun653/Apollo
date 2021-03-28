/****************************************************************************** */
/* usbdaudio.c - USB audio device class driver. */
/****************************************************************************** */
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

#include "types.h"
#include "debug.h"
#include "hw_usb.h"
#include "usblib.h"
#include "usbdevice.h"
#include "usblibpriv.h"
#include "usb_dev_object.h"
#include "usb_dev_dman.h"
#include "musb.h"
#include "usb_musb_dcd.h"
#include "usbdaudio.h"
#include "usbaudio.h"
#include "usb_osal.h"


#ifdef DMA_MODE
#include "cppi41dma.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*****************************************************************************
//
//! \addtogroup audio_device_class_api
//! @{
//
//*****************************************************************************
#define REC_PATH

//*****************************************************************************
//
// The following are the USB audio descriptor identifiers.
//
//*****************************************************************************
#define AUDIO_IN_TERMINAL_ID    1
#define AUDIO_OUT_TERMINAL_ID   2
#define AUDIO_CONTROL_ID        3

//*****************************************************************************
//
// The following are the USB interface numbers for this audio device.
//
//*****************************************************************************
#define AUDIO_INTERFACE_CONTROL 0
#define AUDIO_INTERFACE_PLAY   1
#define AUDIO_INTERFACE_REC      2

//*****************************************************************************
//
// The following are the USB treminal numbers for play path.
//
//*****************************************************************************
#define AUDIO_IN_TERM_STRM_PLAY_ID    	1
#define AUDIO_FU_PLAY_ID    			2
#define AUDIO_OUT_TERM_SPKR_ID    		3

//*****************************************************************************
//
// The following are the USB treminal numbers for record path.
//
//*****************************************************************************
#ifdef REC_PATH
#define AUDIO_IN_TERM_MIC_ID    		4
#define AUDIO_FU_REC_ID      			5
#define AUDIO_OUT_TERM_STRM_REC_ID    	6
#endif

//*****************************************************************************
//
// Device Descriptor.  This is stored in RAM to allow several fields to be
// changed at runtime based on the client's requirements.
//
//*****************************************************************************
static unsigned char g_pAudioDeviceDescriptor[] =
{
    18,                     // Size of this structure.
    USB_DTYPE_DEVICE,       // Type of this structure.
    USBShort(0x110),        // USB version 1.1 (if we say 2.0, hosts assume
                            // high-speed - see USB 2.0 spec 9.2.6.6)
    0,                      // USB Device Class (spec 5.1.1)
    0,                      // USB Device Sub-class (spec 5.1.1)
    0,                      // USB Device protocol (spec 5.1.1)
    64,                     // Maximum packet size for default pipe.
    USBShort(0),            // Vendor ID (filled in during USBDAudioInit).
    USBShort(0),            // Product ID (filled in during USBDAudioInit).
    USBShort(0x100),        // Device Version BCD.
    1,                      // Manufacturer string identifier.
    2,                      // Product string identifier.
    3,                      // Product serial number.
    1                       // Number of configurations.
};

//*****************************************************************************
//
// Audio class device configuration descriptor.
//
// It is vital that the configuration descriptor bConfigurationValue field
// (byte 6) is 1 for the first configuration and increments by 1 for each
// additional configuration defined here.  This relationship is assumed in the
// device stack for simplicity even though the USB 2.0 specification imposes
// no such restriction on the bConfigurationValue values.
//
// Note that this structure is deliberately located in RAM since we need to
// be able to patch some values in it based on client requirements.
//
//*****************************************************************************
static unsigned char g_pAudioDescriptor[] =
{
    //
    // Configuration descriptor header.
    //
    9,                          // Size of the configuration descriptor.
    USB_DTYPE_CONFIGURATION,    // Type of this descriptor.
#ifndef REC_PATH
    USBShort((9+8+52+52)),	// The total size of this full structure.
    2,                          // The number of interfaces in this
#else
    USBShort((9+8+87+104)),	// The total size of this full structure.
    3,                          // The number of interfaces in this
#endif
                                // configuration.
    1,                          // The unique value for this configuration.
    0,                          // The string identifier that describes this
                                // configuration.
    USB_CONF_ATTR_BUS_PWR,      // Bus Powered, Self Powered, remote wake up.
    250,                        // The maximum power in 2mA increments.
};

//*****************************************************************************
//
// This is the Interface Association Descriptor for the serial device used in
// composite devices.
//
//*****************************************************************************
unsigned char g_pIADAudioDescriptor[] =
{

    8,                          // Size of the interface descriptor.
    USB_DTYPE_INTERFACE_ASC,    // Interface Association Type.
    0x0,                        // Default starting interface is 0.
#ifndef REC_PATH
    0x2,                        // Number of interfaces in this association IF-0 Control; IF-1 Play.
#else
    0x3,                        // Number of interfaces in this association IF-0 Control; IF-1 Play; IF-2 Record.
#endif
    USB_CLASS_AUDIO,            // The device class for this association.
    USB_SUBCLASS_UNDEFINED,     // The device subclass for this association.
    USB_PROTOCOL_UNDEFINED,     // The protocol for this association.
    0                           // The string index for this association.
};

const tConfigSection g_sIADAudioConfigSection =
{
    sizeof(g_pIADAudioDescriptor),
    g_pIADAudioDescriptor
};

//*****************************************************************************
//
// The remainder of the configuration descriptor is stored in flash since we
// don't need to modify anything in it at runtime.
//
//*****************************************************************************
const unsigned char g_pAudioControlInterface[] =
{
    //
    // Vendor-specific Interface Descriptor for CONTROL.
    //
    9,                          // Size of the interface descriptor.
    USB_DTYPE_INTERFACE,        // Type of this descriptor.
    AUDIO_INTERFACE_CONTROL,    // The index for this interface.
    0,                          // The alternate setting for this interface.
    0,                          // The number of endpoints used by this
                                // interface.
    USB_CLASS_AUDIO,            // The interface class
    USB_ASC_AUDIO_CONTROL,      // The interface sub-class.
    0,                          // The interface protocol for the sub-class
                                // specified above.
    0,                          // The string index for this interface.

    //
    // Audio Header Descriptor Audio Class.
    //
#ifndef REC_PATH
    9,                          // The size of this descriptor.
#else
    10,                          // The size of this descriptor.
#endif
    USB_DTYPE_CS_INTERFACE,     // Interface descriptor is class specific.
    USB_ACDSTYPE_HEADER,        // Descriptor sub-type is HEADER.
    USBShort(0x0100),           // Audio Device Class Specification Release
                                // Number in Binary-Coded Decimal.
                                // Total number of bytes in
                                // g_pAudioControlInterface
#ifndef REC_PATH
    USBShort((9+9+12+13+9)),
    1,                          // Number of streaming interfaces.
    AUDIO_INTERFACE_PLAY,     // Index of the play streaming interface.
#else
    USBShort((9+10+12+13+9+12+13+9)),
    2,                          // Number of streaming interfaces.
    AUDIO_INTERFACE_PLAY,     // Index of the play streaming interface.
    AUDIO_INTERFACE_REC,     // Index of the record streaming interface.
#endif
    // Start of PLAYBACK PATH
    //
    // Audio Input Terminal Descriptor for PLAYBACK PATH.
    //
    12,                         // The size of this descriptor.
    USB_DTYPE_CS_INTERFACE,     // Interface descriptor is class specific.
    USB_ACDSTYPE_IN_TERMINAL,   // Descriptor sub-type is INPUT_TERMINAL.
    AUDIO_IN_TERM_STRM_PLAY_ID,       // Terminal ID for this interface.
                                // USB streaming interface.
    USBShort(USB_TTYPE_STREAMING),
    0,                          // ID of the Output Terminal to which this
                                // Input Terminal is associated.
    2,                          // Number of logical output channels in the
                                // Terminal's output audio channel cluster.
    USBShort(0x0300),            // Describes the spatial location of the logical channels.
    0,                          // Channel Name string index.
    0,                          // Terminal Name string index.

    //
    // Audio Feature Unit Descriptor for Control of PLAYBACK PATH
    //
    13,                         // The size of this descriptor.
    USB_DTYPE_CS_INTERFACE,     // Interface descriptor is class specific.
    USB_ACDSTYPE_FEATURE_UNIT,  // Descriptor sub-type is FEATURE_UNIT.
    AUDIO_FU_PLAY_ID,           // Unit ID for this interface.
    AUDIO_IN_TERM_STRM_PLAY_ID,       // ID of the Unit or Terminal to which this
                                // Feature Unit is connected.
    2,                          // Size in bytes of an element of the
                                // bmaControls() array that follows.
                                // Master Mute control.
    USBShort(USB_ACONTROL_MUTE),
                                // Left channel volume control.
    USBShort(USB_ACONTROL_VOLUME),
                                // Right channel volume control.
    USBShort(USB_ACONTROL_VOLUME),
    0,                          // Feature unit string index.

    //
    // Audio Output Terminal Descriptor of PLAYBACK PATH.
    //
    9,                          // The size of this descriptor.
    USB_DTYPE_CS_INTERFACE,     // Interface descriptor is class specific.
    USB_ACDSTYPE_OUT_TERMINAL,  // Descriptor sub-type is INPUT_TERMINAL.
    AUDIO_OUT_TERM_SPKR_ID,      // Terminal ID for this interface.
                                // Output type is a generic speaker.
    USBShort(USB_ATTYPE_SPEAKER),
    0,       					// ID of the input terminal to which this
                                // output terminal is connected.
    AUDIO_FU_PLAY_ID,           // ID of the feature unit that this output
                                // terminal is connected to.
    0,                          // Output terminal string index.
    // end of the playback path

#ifdef REC_PATH
    // start of record path
    //
    // Audio Input Terminal Descriptor.
    //
    12,                         // The size of this descriptor.
    USB_DTYPE_CS_INTERFACE,     // Interface descriptor is class specific.
    USB_ACDSTYPE_IN_TERMINAL,  	// Descriptor sub-type is INPUT_TERMINAL.
    AUDIO_IN_TERM_MIC_ID,      	// Terminal ID for this interface.
                                // Output type is a generic speaker.
    USBShort(USB_ATTYPE_MICROPHONE),
    0,       					// ID of the input terminal to which this
                                // output terminal is connected.
    2,                          // Number of logical output channels in the
                                // Terminal's output audio channel cluster.
    USBShort(0x0300),            // Describes the spatial location of the logical channels.
    0,                          // Channel Name string index.
    0,                          // Terminal Name string index.

    //
    // Audio Feature Unit Descriptor
    //
    13,                         // The size of this descriptor.
    USB_DTYPE_CS_INTERFACE,     // Interface descriptor is class specific.
    USB_ACDSTYPE_FEATURE_UNIT,  // Descriptor sub-type is FEATURE_UNIT.
    AUDIO_FU_REC_ID,           // Unit ID for this interface.
    AUDIO_IN_TERM_MIC_ID,       // ID of the Unit or Terminal to which this
                                // Feature Unit is connected.
    2,                          // Size in bytes of an element of the
                                // bmaControls() array that follows.
                                // Master Mute control.
    USBShort(USB_ACONTROL_MUTE),
                                // Left channel volume control.
    USBShort(USB_ACONTROL_VOLUME),
                                // Right channel volume control.
    USBShort(USB_ACONTROL_VOLUME),
    0,                          // Feature unit string index.

    //
    // Audio Output Terminal Descriptor.
    //
    9,                         // The size of this descriptor.
    USB_DTYPE_CS_INTERFACE,     // Interface descriptor is class specific.
    USB_ACDSTYPE_OUT_TERMINAL,   // Descriptor sub-type is OUTPUT_TERMINAL.
    AUDIO_OUT_TERM_STRM_REC_ID,       // Terminal ID for this interface.
                                // USB streaming interface.
    USBShort(USB_TTYPE_STREAMING),
    0,                          // ID of the Output Terminal to which this
                                // Output Terminal is associated.
    AUDIO_FU_REC_ID,   // bSourceID=ID-N
    0,                          // Terminal Name string index.
    // end of the record path
#endif
};

//*****************************************************************************
//
// The audio streaming interface descriptor.  This describes the two valid
// interfaces for this class.  The first interface has no endpoints and is used
// by host operating systems to put the device in idle mode, while the second
// is used when the audio device is active.
//
//*****************************************************************************
const unsigned char g_pAudioStreamInterface[] =
{
    // Start of PLAYBACK INTERFACE
    //
    // Vendor-specific Interface Descriptor.
    //
    9,                          // Size of the interface descriptor.
    USB_DTYPE_INTERFACE,        // Type of this descriptor.
    AUDIO_INTERFACE_PLAY,     // The index for this interface.
    0,                          // The alternate setting for this interface.
    0,                          // The number of endpoints used by this
                                // interface.
    USB_CLASS_AUDIO,            // The interface class
    USB_ASC_AUDIO_STREAMING,    // The interface sub-class.
    0,                          // Unused must be 0.
    0,                          // The string index for this interface.

    //
    // Vendor-specific Interface Descriptor.
    //
    9,                          // Size of the interface descriptor.
    USB_DTYPE_INTERFACE,        // Type of this descriptor.
    AUDIO_INTERFACE_PLAY,     // The index for this interface.
    1,                          // The alternate setting for this interface.
    1,                          // The number of endpoints used by this
                                // interface.
    USB_CLASS_AUDIO,            // The interface class
    USB_ASC_AUDIO_STREAMING,    // The interface sub-class.
    0,                          // Unused must be 0.
    0,                          // The string index for this interface.

    //
    // Class specific Audio Streaming Interface descriptor.
    //
    7,                          // Size of the interface descriptor.
    USB_DTYPE_CS_INTERFACE,     // Interface descriptor is class specific.
    USB_ASDSTYPE_GENERAL,       // General information.
    AUDIO_IN_TERM_STRM_PLAY_ID, // ID of the terminal to which this streaming
                                // interface is connected.
    1,                          // One frame delay.
    USBShort(USB_ADF_PCM),      //

    //
    // Format type Audio Streaming descriptor.
    //
    11,                         // Size of the interface descriptor.
    USB_DTYPE_CS_INTERFACE,     // Interface descriptor is class specific.
    USB_ASDSTYPE_FORMAT_TYPE,   // Audio Streaming format type.
    USB_AF_TYPE_TYPE_I,         // Type I audio format type.
    2,                          // Two audio channels.
    2,                          // 2 bytes per audio sub-frame.
    16,                         // 16 bits per sample.
    1,                          // One sample rate provided.
    USB3Byte(48000),            // Only 48000 sample rate supported.

    //
    // Endpoint Descriptor
    //
    9,                              // The size of the endpoint descriptor.
    USB_DTYPE_ENDPOINT,             // Descriptor type is an endpoint.
                                    // OUT endpoint with address
                                    // ISOC_OUT_ENDPOINT.
    USB_EP_DESC_OUT | USB_EP_TO_INDEX(ISOC_OUT_ENDPOINT),
    USB_EP_ATTR_ISOC |              // Endpoint is an adaptive isochronous data
    USB_EP_ATTR_ISOC_ADAPT |        //  endpoint.
    USB_EP_ATTR_USAGE_DATA,
    USBShort(ISOC_OUT_EP_MAX_SIZE), // The maximum packet size.
    1,                              // The polling interval for this endpoint.
    0,                              // Refresh is unused.
    0,                              // Synch endpoint address.

    //
    // Audio Streaming Isochronous Audio Data Endpoint Descriptor
    //
    7,                              // The size of the descriptor.
    USB_ACSDT_ENDPOINT,             // Audio Class Specific Endpoint Descriptor.
    USB_ASDSTYPE_GENERAL,           // This is a general descriptor.
    0,
	USB_EP_LOCKDELAY_UNDEF,         // Undefined lock delay units.
    USBShort(0),                    // No lock delay.
    // End of PLAYBACK INTERFACE

#ifdef REC_PATH
    // Start of RECORD INTERFACE
    //
    // Vendor-specific Interface Descriptor.
    //
    9,                          // Size of the interface descriptor.
    USB_DTYPE_INTERFACE,        // Type of this descriptor.
    AUDIO_INTERFACE_REC,     // The index for this interface.
    0,                          // The alternate setting for this interface.
    0,                          // The number of endpoints used by this
                                // interface.
    USB_CLASS_AUDIO,            // The interface class
    USB_ASC_AUDIO_STREAMING,    // The interface sub-class.
    0,                          // Unused must be 0.
    0,                          // The string index for this interface.

    //
    // Vendor-specific Interface Descriptor.
    //
    9,                          // Size of the interface descriptor.
    USB_DTYPE_INTERFACE,        // Type of this descriptor.
    AUDIO_INTERFACE_REC,     // The index for this interface.
    1,                          // The alternate setting for this interface.
    1,                          // The number of endpoints used by this
                                // interface.
    USB_CLASS_AUDIO,            // The interface class
    USB_ASC_AUDIO_STREAMING,    // The interface sub-class.
    0,                          // Unused must be 0.
    0,                          // The string index for this interface.

    //
    // Class specific Audio Streaming Interface descriptor.
    //
    7,                          // Size of the interface descriptor.
    USB_DTYPE_CS_INTERFACE,     // Interface descriptor is class specific.
    USB_ASDSTYPE_GENERAL,       // General information.
    AUDIO_OUT_TERM_STRM_REC_ID, // ID of the terminal to which this streaming
                                // interface is connected.
    1,                          // One frame delay.
    USBShort(USB_ADF_PCM),      //

    //
    // Format type Audio Streaming descriptor.
    //
    11,                         // Size of the interface descriptor.
    USB_DTYPE_CS_INTERFACE,     // Interface descriptor is class specific.
    USB_ASDSTYPE_FORMAT_TYPE,   // Audio Streaming format type.
    USB_AF_TYPE_TYPE_I,         // Type I audio format type.
    2,                          // Two audio channels.
    2,                          // 2 bytes per audio sub-frame.
    16,                         // 16 bits per sample.
    1,                          // One sample rate provided.
    USB3Byte(48000),            // Only 48000 sample rate supported.

    //
    // Endpoint Descriptor
    //
    9,                              // The size of the endpoint descriptor.
    USB_DTYPE_ENDPOINT,             // Descriptor type is an endpoint.
                                    // IN endpoint with address
                                    // ISOC_IN_ENDPOINT.
    USB_EP_DESC_IN| USB_EP_TO_INDEX(ISOC_IN_ENDPOINT),
    USB_EP_ATTR_ISOC |              // Endpoint is an adaptive isochronous data
    USB_EP_ATTR_ISOC_ADAPT |        //  endpoint.
    USB_EP_ATTR_USAGE_DATA,
    USBShort(ISOC_IN_EP_MAX_SIZE), // The maximum packet size.
    1,                              // The polling interval for this endpoint.
    0,                              // Refresh is unused.
    0,                              // Synch endpoint address.

    //
    // Audio Streaming Isochronous Audio Data Endpoint Descriptor
    //
    7,                              // The size of the descriptor.
    USB_ACSDT_ENDPOINT,             // Audio Class Specific Endpoint Descriptor.
    USB_ASDSTYPE_GENERAL,           // This is a general descriptor.
    0,
	USB_EP_LOCKDELAY_UNDEF,         // Undefined lock delay units.
    USBShort(0),                    // No lock delay.
    // End of RECORD INTERFACE
#endif
};

//*****************************************************************************
//
// The audio device configuration descriptor is defined as three sections,
// one containing just the 9 byte USB configuration descriptor.  The second
// holds the audio streaming interface and the third holds the audio control
// interface.
//
//*****************************************************************************
const tConfigSection g_sAudioConfigSection =
{
    sizeof(g_pAudioDescriptor),
    g_pAudioDescriptor
};

const tConfigSection g_sAudioStreamInterfaceSection =
{
    sizeof(g_pAudioStreamInterface),
    g_pAudioStreamInterface
};

const tConfigSection g_sAudioControlInterfaceSection =
{
    sizeof(g_pAudioControlInterface),
    g_pAudioControlInterface
};

//*****************************************************************************
//
// This array lists all the sections that must be concatenated to make a
// single, complete audio device configuration descriptor.
//
//*****************************************************************************
const tConfigSection *g_psAudioSections[] =
{
    &g_sAudioConfigSection,
    &g_sIADAudioConfigSection,
    &g_sAudioControlInterfaceSection,
    &g_sAudioStreamInterfaceSection
};

#define NUM_AUDIO_SECTIONS      (sizeof(g_psAudioSections) /                  \
                                 sizeof(tConfigSection *))

//*****************************************************************************
//
// The header for the single configuration we support.  This is the root of
// the data structure that defines all the bits and pieces that are pulled
// together to generate the configuration descriptor.
//
//*****************************************************************************
const tConfigHeader g_sAudioConfigHeader =
{
    NUM_AUDIO_SECTIONS,
    g_psAudioSections
};

//*****************************************************************************
//
// Configuration Descriptor.
//
//*****************************************************************************
const tConfigHeader * const g_pAudioConfigDescriptors[] =
{
    &g_sAudioConfigHeader
};

//*****************************************************************************
//
// Various internal handlers needed by this class.
//
//*****************************************************************************
static void HandleDisconnect(void *pvInstance);
static void InterfaceChange(void *pvInstance, uint8_t ucInterface,
                            uint8_t ucAlternateSetting);
static void ConfigChangeHandler(void *pvInstance, uint32_t ulValue, uint32_t ulIndex);
static void DataReceived(void *pvGadgetObj, uint32_t ulInfo, uint32_t ulIndex);
static void HandleEndpoints(struct usbGadgetObj *pUsbGadgetObj, 
                            usbGenericEvent_t endptEvent, 
                            uint32_t epNo, 
                            uint32_t length);
static void HandleRequests(struct usbGadgetObj *pGadgetObj, usbEndpt0event_t endptEvent, usbSetupPkt_t * setup);
static void HandleDevice(void *pvInstance, uint32_t ulRequest,
                          void *pvRequestData);
uint8_t * SoundBufferFillGet();
uint8_t * SoundBufferFillAdj();

//*****************************************************************************
//
// The FIFO configuration for USB audio device class.
//
//*****************************************************************************
const tFIFOConfig g_sUSBAudioFIFOConfig =
{
    //
    // IN endpoints.
    //
    {
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN },
        { FALSE, USB_EP_DEV_IN }
    },

    //
    // OUT endpoints.
    //
    {
        { FALSE, USB_EP_DEV_OUT | USB_EP_AUTO_CLEAR },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT },
        { FALSE, USB_EP_DEV_OUT }
    },
};

//*****************************************************************************
//
// The device information structure for the USB Audio device.
//
//*****************************************************************************
tDeviceInfo g_sAudioDeviceInfo =
{
    //
    // Device event handler callbacks.
    //
    {
        //
        // GetDescriptor
        //
        0,

        //
        // RequestHandler
        //
        HandleRequests,

        //
        // InterfaceChange
        //
        InterfaceChange,

        //
        // ConfigChange
        //
        (tInfoCallback)ConfigChangeHandler,

        //
        // DataReceived
        //
		(tInfoCallback)DataReceived,

        //
        // DataSentCallback
        //
        0,

        //
        // ResetHandler
        //
        0,

        //
        // SuspendHandler
        //
        0,

        //
        // ResumeHandler
        //
        0,

        //
        // DisconnectHandler
        //
        HandleDisconnect,

        //
        // EndpointHandler
        //
        HandleEndpoints,

        //
        // Device handler
        //
        HandleDevice
    },
    g_pAudioDeviceDescriptor,
    ( usbConfigHeader_t **)g_pAudioConfigDescriptors,
    0,
    0,
    0
};

//*****************************************************************************
//
// This function is called to handle data being received back from the host so
// that the application callback can be called when the new data is ready.
//
//*****************************************************************************
static void
DataReceived(void *pvGadgetObj, uint32_t ulInfo, uint32_t ulIndex)
{
    tAudioInstance *psInst;
    const tUSBDAudioDevice *psDevice;
    usbGadgetObj_t *pGadgetObj;

    ASSERT(pvGadgetObj != 0);

    pGadgetObj = (usbGadgetObj_t *)pvGadgetObj;

    //
    // Create the instance pointer.
    //
    psDevice = (tUSBDAudioDevice *)pGadgetObj->usbClass.privateData;

    //
    // Make a copy of this pointer for ease of use in this function.
    //
    psInst = psDevice->psPrivateData;

    debug_printf("%s:%d. ucRequest=%d\n",
                __FUNCTION__, __LINE__, psInst->ucRequest);

    //
    // If there is an update pending and the request was to set a current
    // value then check which value was set.
    //
    if(psInst->usUpdate && (psInst->ucRequest == USB_AC_SET_CUR))
    {
        //
        // Only handling interface requests.
        //
        if((psInst->usRequestType & USB_RTYPE_RECIPIENT_M) ==
           USB_RTYPE_INTERFACE)
        {
            if(psInst->usUpdate == VOLUME_CONTROL)
            {
                //
                // Inform the callback of the new volume.
                //
                psDevice->pfnCallback(NULL, 0, USBD_AUDIO_EVENT_VOLUME,
                                      psInst->sVolume, 0);
            }
            else if(psInst->usUpdate == MUTE_CONTROL)
            {
                //
                // Inform the callback of the new data.
                //
                psDevice->pfnCallback(NULL, 0, USBD_AUDIO_EVENT_MUTE, psInst->ucMute,
                                      0);
            }
        }
        psInst->usUpdate = 0;
    }
}

//*****************************************************************************
//
// This function is called to handle the interrupts on the isochronous endpoint
// for the audio device class.
//
//*****************************************************************************
static void
HandleEndpoints(struct usbGadgetObj *pUsbGadgetObj,
                usbGenericEvent_t endptEvent,
                uint32_t epNo,
                uint32_t length)
{
    unsigned long ulEPStatus;
    tAudioInstance *psInst;
    unsigned char *pucData;
    const tUSBDAudioDevice *psDevice;
    usbMusbDcdDevice_t *musb;
    uint32_t epNum, byteNum;
#ifdef DMA_MODE
    uint32_t dmaSize;
#endif

    musb = (usbMusbDcdDevice_t *)pUsbGadgetObj->dcd.privateData;

    ASSERT(pUsbGadgetObj != 0);

    //
    // Create the instance pointer.
    //
    psDevice = (const tUSBDAudioDevice *)pUsbGadgetObj->usbClass.privateData;

    //
    // Make a copy of this pointer for ease of use later in this function.
    //
    psInst = psDevice->psPrivateData;

    if (endptEvent==USB_GENERIC_EVENT_DATA_OUT_COMPLETE)
    {
        if (psInst->sBuffer.pvData != 0)
        {
            //
            // Get the pointer to the data buffer.
            //
            pucData = psInst->sBuffer.pvData;
            epNum = ISOC_OUT_ENDPOINT;
            byteNum = ISOC_OUT_EP_MAX_SIZE;
#ifdef DMA_MODE
            /* handling CDMA RX completion for OUT transaction */
            dmaRxCompletion(musb->controllerId, epNum, &dmaSize);

            //
            // Inform the callback of the new data.
            //
            psInst->sBuffer.ulSize = dmaSize;
            psInst->sBuffer.pfnCallback(pucData, psInst->sBuffer.ulSize,
                                        USBD_AUDIO_EVENT_DATAOUT);

            //
            // Read out the current endpoint status.
            //
            ulEPStatus = USBEndpointStatus(musb->baseAddr, psInst->ucOUTEndpoint);

            //
            // Acknowledge that the data was read, this will not cause a bus
            // acknowledgment.
            //
            USBDevEndpointDataAck(musb->baseAddr, psInst->ucOUTEndpoint, 0);

            //
            // Clear the status bits.
            //
            USBDevEndpointStatusClear(musb->baseAddr, psInst->ucOUTEndpoint,
                                          ulEPStatus);
            /* Need to replenish the RX queue with BD. associate the application
            provided buffer to a BD and put it into RX free queue */
            doDmaRxTransfer(musb->controllerId, byteNum,
                            (uint8_t*)pucData, epNum);

            /* data should have been written by DMA. no need to copy them out now.
               Data buffer was associated to DMA transfer in USBMusbDcdEpReq() */
#else
            // get the ISO OUT data
            USBEndpointDataGet(musb->baseAddr, epNum, pucData, &byteNum);
            //
            // Inform the callback of the new data.
            //
            psInst->sBuffer.ulSize = byteNum;
            psInst->sBuffer.pfnCallback(pucData, psInst->sBuffer.ulSize,
                                        USBD_AUDIO_EVENT_DATAOUT);

            //
            // Read out the current endpoint status.
            //
            ulEPStatus = USBEndpointStatus(musb->baseAddr, psInst->ucOUTEndpoint);

            //
            // Acknowledge that the data was read, this will not cause a bus
            // acknowledgment.
            //
            USBDevEndpointDataAck(musb->baseAddr, psInst->ucOUTEndpoint, 0);

            //
            // Clear the status bits.
            //
            USBDevEndpointStatusClear(musb->baseAddr, psInst->ucOUTEndpoint,
                                          ulEPStatus);
#endif //DMA_MODE
        }
    }

    if (endptEvent==USB_GENERIC_EVENT_DATA_IN_COMPLETE)
    {
	    if (psInst->sBufferRec.pvData != 0)
	    {
            //
            // Get the pointer to the data buffer.
            //
            pucData = psInst->sBufferRec.pvData;
            epNum = ISOC_IN_ENDPOINT;
            byteNum = ISOC_IN_EP_MAX_SIZE;

#ifdef DMA_MODE
            /* handle DMA completion for IN transaction here */
            dmaTxCompletion(musb->controllerId, epNum);

            //
            // Inform the callback of the sent data.
            //
            psInst->sBufferRec.ulSize = byteNum;
            psInst->sBufferRec.pfnCallback(pucData, psInst->sBufferRec.ulSize,
                                     USBD_AUDIO_EVENT_DATAIN);

            /* using DMA to dump data into USB core for sending data to host
               Associate application provided data buffer into a packet descriptor */
               {
            doDmaTxTransfer(musb->controllerId, (uint8_t*)pucData,
			byteNum, epNum);
               }
#else
            // get the ISO IN data
            USBEndpointDataPut(musb->baseAddr, epNum, pucData, byteNum);
            USBEndpointDataSend(musb->baseAddr, epNum, USB_TRANS_IN);

            //
            // Inform the callback of the sent data.
            //
            psInst->sBufferRec.ulSize = byteNum;
            psInst->sBufferRec.pfnCallback(pucData, psInst->sBufferRec.ulSize,
                                     USBD_AUDIO_EVENT_DATAIN);
#endif //DMA_MODE
	    }
    }
}

//*****************************************************************************
//
// Device instance specific handler.
//
//*****************************************************************************
static void
HandleDevice(void *pvInstance, uint32_t ulRequest, void *pvRequestData)
{
    tAudioInstance *psInst;
    unsigned char *pucData;

    //
    // Create the serial instance data.
    //
    psInst = ((tUSBDAudioDevice *)pvInstance)->psPrivateData;

    //
    // Create the char array used by the events supported by the USB CDC
    // serial class.
    //
    pucData = (unsigned char *)pvRequestData;

    switch(ulRequest)
    {
        //
        // This was an interface change event.
        //
        case USB_EVENT_COMP_IFACE_CHANGE:
        {
            //
            // Save the change to the appropriate interface number.
            //
            if(pucData[0] == AUDIO_INTERFACE_CONTROL)
            {
                debug_printf("%s:%d. ucInterfaceControl=%d\n",
                            __FUNCTION__, __LINE__, pucData[1]);

                psInst->ucInterfaceControl = pucData[1];
            }
            else if(pucData[0] == AUDIO_INTERFACE_PLAY)
            {
                debug_printf("%s:%d. ucInterfaceAudio=%d\n",
                            __FUNCTION__, __LINE__, pucData[1]);

                psInst->ucInterfaceAudio = pucData[1];
            }
            break;
        }

        //
        // This was an endpoint change event.
        //
        case USB_EVENT_COMP_EP_CHANGE:
        {
            //
            // Determine if this is an IN or OUT endpoint that has changed.
            //
            if((pucData[0] & USB_EP_DESC_IN) == 0)
            {
                //
                // Extract the new endpoint number without the DIR bit.
                //
                psInst->ucOUTEndpoint = INDEX_TO_USB_EP(pucData[1] & 0x7f);
                debug_printf("%s:%d. ucOUTEndpoint=%d\n",
                            __FUNCTION__, __LINE__, psInst->ucOUTEndpoint);
            }else
            {
                //
                // Extract the new endpoint number without the DIR bit.
                //
                psInst->ucINEndpoint = INDEX_TO_USB_EP(pucData[1] & 0x7f);
                debug_printf("%s:%d. ucOUTEndpoint=%d\n",
                            __FUNCTION__, __LINE__, psInst->ucOUTEndpoint);
            }
            break;
        }

        //
        // Handle class specific reconfiguring of the configuration descriptor
        // once the composite class has built the full descriptor.
        //
        case USB_EVENT_COMP_CONFIG:
        {
            //
            // This sets the bFirstInterface of the Interface Association
            // descriptor to the first interface which is the control
            // interface used by this instance.
            //
            pucData[2] = psInst->ucInterfaceControl;
            debug_printf("%s:%d. ucInterfaceControl=%d\n",
                        __FUNCTION__, __LINE__, pucData[2]);

            break;
        }

        default:
        {
            debug_printf("%s:%d. default\n",
                        __FUNCTION__, __LINE__);
            break;
        }
    }
}

//*****************************************************************************
//
// This function is called by the USB device stack whenever the device is
// disconnected from the host.
//
//*****************************************************************************
static void
HandleDisconnect(void *pvInstance)
{
    const tUSBDAudioDevice *psDevice;

    ASSERT(pvInstance != 0);

    debug_printf("%s:%d.\n",
                __FUNCTION__, __LINE__);

    //
    // Create the instance pointer.
    //
    psDevice = (const tUSBDAudioDevice *)pvInstance;

    //
    // Inform the application that the device has been disconnected.
    //
    psDevice->pfnCallback(NULL, 0, USB_EVENT_DISCONNECTED, 0, 0);
}

//*****************************************************************************
//
// This function is called by the USB device stack whenever the device
// interface changes.  This occurs when the audio device transitions between
// being active and inactive.  Interface AUDIO_INTERFACE_CONTROL is the
// inactive interface that has no endpoints, while interface
// AUDIO_INTERFACE_AUDIO has the single Isochronous OUT endpoint.
//
//*****************************************************************************
static void
InterfaceChange(void *pUsbGadgetObj, unsigned char ucInterface,
                unsigned char ucAlternateSetting)
{
    usbGadgetObj_t *pGadgetObj;
    tAudioInstance *psInst;
    unsigned char *pucData;
    tUSBDAudioDevice *psDevice;
    uint32_t epNum, byteNum;
#ifdef DMA_MODE
    usbMusbDcdDevice_t *musb;
#endif

    ASSERT(pUsbGadgetObj != 0);

    pGadgetObj = (usbGadgetObj_t *)pUsbGadgetObj;
#ifdef DMA_MODE
    musb = (usbMusbDcdDevice_t *)pGadgetObj->dcd.privateData;
#endif

    //
    // Create the instance pointer.
    //
    psDevice = (tUSBDAudioDevice *)pGadgetObj->usbClass.privateData;

    //
    // Make a copy of this pointer for ease of use later in this function.
    //
    psInst = psDevice->psPrivateData;

    debug_printf("%s:%d. ucAlternateSetting=%d\n",
                __FUNCTION__, __LINE__, ucAlternateSetting);

    //
    // Check which interface to change into.
    //
    if(ucAlternateSetting == 0)
    {
        //
        // Alternate setting 0 is an inactive state.
        //
    }
    else
    {
	/* if the interface is AUDIO_INTERFACE_REC */
	/* we need to fill the TX FIFO with zero */
	/* and make the TX ready to go */

	if ((ucInterface==AUDIO_INTERFACE_REC)&&(psInst->sBufferRec.pvData != 0)&&(psInst->ucInterfaceAudioCDMARecInitFlag==0))
	{
		psInst->ucInterfaceAudioCDMARecInitFlag = 1;
		//
		// Get the pointer to the data buffer.
		//
		pucData = psInst->sBufferRec.pvData;
		epNum = ISOC_IN_ENDPOINT;
		byteNum = ISOC_IN_EP_MAX_SIZE;

#ifdef DMA_MODE
        /* using DMA to dump data into USB core for sending data to host
           Associate application provided data buffer into a packet descriptor */
        doDmaTxTransfer(musb->controllerId, (uint8_t*)pucData,
        		byteNum, epNum);

#else	// Fill the USB TX FIFO with zeros
		USBEndpointDataPut(psInst->ulUSBBase, epNum, pucData, byteNum);

		// ebnable the USB TX transfer
		USBEndpointDataSend(psInst->ulUSBBase, epNum, USB_TRANS_IN);
#endif
	}

	/* if the interface is AUDIO_INTERFACE_PLAY */
	/* we need to fill the RX CDMA queue with descriptor */
	/* and make the RX CDMA ready to receive */

#ifdef DMA_MODE
	if ((ucInterface==AUDIO_INTERFACE_PLAY)&&(psInst->sBuffer.pvData != 0)&&(psInst->ucInterfaceAudioCDMAPlayInitFlag==0))
	{
		psInst->ucInterfaceAudioCDMAPlayInitFlag = 1;
		//
		// Get the pointer to the data buffer.
		//
		pucData = psInst->sBuffer.pvData;
		epNum = ISOC_OUT_ENDPOINT;
		byteNum = ISOC_OUT_EP_MAX_SIZE;

            /* Need to replenish the RX queue with BD. associate the application
            provided buffer to a BD and put it into RX free queue */
            doDmaRxTransfer(musb->controllerId, byteNum,
                            (uint8_t*)pucData, epNum);
	}
#endif
    }

    USBDevEndpointDataAck(psInst->ulUSBBase, USB_EP_0, true);
}

//*****************************************************************************
//
// This function is called by the USB device stack whenever the device
// configuration changes.
//
//*****************************************************************************
static void
ConfigChangeHandler(void *pvInstance, uint32_t ulValue, uint32_t ulIndex)
{
    const tUSBDAudioDevice *psDevice;

    ASSERT(pvInstance != 0);

    debug_printf("%s:%d. ulValue=%d\n",
                __FUNCTION__, __LINE__, ulValue);

    //
    // Create the instance pointer.
    //
    psDevice = (const tUSBDAudioDevice *)pvInstance;

    //
    // If we have a control callback, let the client know we are open for
    // business.
    //
    if(psDevice->pfnCallback)
    {
        //
        // Pass the connected event to the client.
        //
        psDevice->pfnCallback(NULL, pvInstance, USB_EVENT_CONNECTED, 0, 0);
    }
}

//*****************************************************************************
//
//! This function should be called once for the audio class device to
//! initialized basic operation and prepare for enumeration.
//!
//! \param ulIndex is the index of the USB controller to initialize for
//! audio class device operation.
//! \param psDevice points to a structure containing parameters customizing
//! the operation of the audio device.
//!
//! In order for an application to initialize the USB audio device class, it
//! must first call this function with the a valid audio device class structure
//! in the \e psDevice parameter.  This allows this function to initialize the
//! USB controller and device code to be prepared to enumerate and function as
//! a USB audio device.
//!
//! This function returns a void pointer that must be passed in to all other
//! APIs used by the audio class.
//!
//! See the documentation on the tUSBDAudioDevice structure for more
//! information on how to properly fill the structure members.
//!
//! \return Returns 0 on failure or a non-zero void pointer on success.
//
//*****************************************************************************
void *
USBDAudioInit(void * pUsbGadgetObj, tUSBDAudioDevice *psDevice)
{
    debug_printf("%s:%d.\n",
                __FUNCTION__, __LINE__);

    /* Call usb composite init function */
    USBDAudioCompositeInit(pUsbGadgetObj, psDevice);

    /*
     * All is well so now pass the descriptors to the lower layer and put
     * the bulk device on the bus.
     */
    ((struct usbGadgetObj  *)pUsbGadgetObj)->dcd.dcdActions.pFnDcInit(&((struct usbGadgetObj  *)pUsbGadgetObj)->dcd);

    return ((void *)psDevice);
}

//*****************************************************************************
//
//! This function should be called once for the audio class device to
//! initialized basic operation and prepare for enumeration.
//!
//! \param ulIndex is the index of the USB controller to initialize for
//! audio class device operation.
//! \param psDevice points to a structure containing parameters customizing
//! the operation of the audio device.
//!
//! In order for an application to initialize the USB audio device class, it
//! must first call this function with the a valid audio device class structure
//! in the \e psDevice parameter.  This allows this function to initialize the
//! USB controller and device code to be prepared to enumerate and function as
//! a USB audio device.
//!
//! This function returns a void pointer that must be passed in to all other
//! APIs used by the audio class.
//!
//! See the documentation on the tUSBDAudioDevice structure for more
//! information on how to properly fill the structure members.
//!
//! \return Returns 0 on failure or a non-zero void pointer on success.
//
//*****************************************************************************
void *
USBDAudioCompositeInit(struct usbGadgetObj *pGadgetObj, const tUSBDAudioDevice *psDevice)
{
    tAudioInstance *psInst;
    tDeviceDescriptor *psDevDesc;
    usbMusbDcdDevice_t *musb;

    //
    // Check parameter validity.
    //
    ASSERT(pGadgetObj);
    ASSERT(psDevice);
    ASSERT(psDevice->ppStringDescriptors);
    ASSERT(psDevice->psPrivateData);

    debug_printf("%s:%d.\n",
                __FUNCTION__, __LINE__);

    musb = (usbMusbDcdDevice_t *)pGadgetObj->dcd.privateData;

    //
    // Make a copy of this pointer for ease of use in this function.
    //
    psInst = psDevice->psPrivateData;

    //
    // Initialize the workspace in the passed instance structure.
    //
    psInst->psConfDescriptor = (tConfigDescriptor *)g_pAudioDescriptor;
    psInst->psDevInfo = &g_sAudioDeviceInfo;
    psInst->ulUSBBase = musb->baseAddr;
    pGadgetObj->dcd.ptDeviceInfo = (void *)&g_sAudioDeviceInfo;

    //
    // The Control interface is at index 0.
    //
    psInst->ucInterfaceControl = AUDIO_INTERFACE_CONTROL;

    //
    // The Audio interface is at index 1.
    //
    psInst->ucInterfaceAudio = AUDIO_INTERFACE_PLAY;

    //
    // Set the default Isochronous OUT endpoint.
    //
    psInst->ucOUTEndpoint = ISOC_OUT_ENDPOINT;
    psInst->ucINEndpoint = ISOC_IN_ENDPOINT;

    //
    // Save the volume settings.
    //
    psInst->sVolumeMax = psDevice->sVolumeMax;
    psInst->sVolumeMin = psDevice->sVolumeMin;
    psInst->sVolumeStep = psDevice->sVolumeStep;

    //
    // No update pending to any command.
    //
    psInst->usUpdate = 0;

    //
    // Fix up the device descriptor with the client-supplied values.
    //
    psDevDesc = (tDeviceDescriptor *)psInst->psDevInfo->pDeviceDescriptor;
    psDevDesc->idVendor = psDevice->usVID;
    psDevDesc->idProduct = psDevice->usPID;
    //
    // Fix up the configuration descriptor with client-supplied values.
    //
    psInst->psConfDescriptor->bmAttributes = psDevice->ucPwrAttributes;
    psInst->psConfDescriptor->bMaxPower =
        (unsigned char)(psDevice->usMaxPowermA / 2);

    //
    // Plug in the client's string stable to the device information
    // structure.
    //
    psInst->psDevInfo->ppStringDescriptors = (uint8_t **)psDevice->ppStringDescriptors;
    psInst->psDevInfo->ulNumStringDescriptors =
        psDevice->ulNumStringDescriptors;
    psInst->psDevInfo->pvInstance = (void *)psDevice;

	/* Set the pointer of msc device in the gadget object */
    ((struct usbGadgetObj *)pGadgetObj)->usbClass.privateData = (void *)psDevice;
    ((struct usbGadgetObj *)pGadgetObj)->usbClass.classAction.epHandler = HandleEndpoints;
    ((struct usbGadgetObj *)pGadgetObj)->usbClass.classAction.ep0Handler = HandleRequests;

    /* Set the values of the descriptors required */
    /* Device descriptor */
    ((struct usbGadgetObj *)pGadgetObj)->pDesc.pDeviceDesc = (usbDeviceDesc_t *)psInst->psDevInfo->pDeviceDescriptor;
    ((struct usbGadgetObj *)pGadgetObj)->pDesc.ppConfigDesc = psInst->psDevInfo->ppConfigDescriptors;
    ((struct usbGadgetObj *)pGadgetObj)->pDesc.ppStringDesc = (uint8_t **)psDevice->ppStringDescriptors;
    ((struct usbGadgetObj *)pGadgetObj)->pDesc.numStringDesc = psDevice->ulNumStringDescriptors;

    //
    // Return the pointer to the instance indicating that everything went well.
    //
    return((void *)psDevice);
}

#if 0
//*****************************************************************************
//
//! Shuts down the audio device.
//!
//! \param pvInstance is the pointer to the device instance structure as
//! returned by USBDAudioInit().
//!
//! This function terminates audio interface for the instance supplied.  This
//! function should not be called if the audio device is part of a composite
//! device and instead the USBDCompositeTerm() function should be called for
//! the full composite device.
//! Following this call, the \e pvInstance instance should not me used in any
//! other calls.
//!
//! \return None.
//
//*****************************************************************************
void
USBDAudioTerm(void *pvInstance)
{
    ASSERT(pvInstance != 0);

    //
    // Cleanly exit device mode.
    //
    USBDCDTerm(0);
}
#endif

//*****************************************************************************
//
// This function is called by the USB device stack whenever a non-standard
// request is received.
//
// \param pvInstance is the instance data for this request.
// \param pUSBRequest points to the request received.
//
// This call parses the provided request structure to the type of request and
// will respond to all commands that are understood by the class.
//
// \return None.
//
//*****************************************************************************
static void
HandleRequests(struct usbGadgetObj *pGadgetObj,
    usbEndpt0event_t endptEvent, usbSetupPkt_t * setup )
{
    unsigned long ulControl;
    unsigned long ulRecipient;
    unsigned long ulStall;
    tAudioInstance *psInst;
    tUSBRequest *pUSBRequest;
    const tUSBDAudioDevice *psDevice;

    ASSERT(pGadgetObj != 0);

    //
    // Create the instance pointer.
    //
    psDevice = (const tUSBDAudioDevice *)pGadgetObj->usbClass.privateData;

    //
    // Make a copy of this pointer for ease of use in this function.
    //
    psInst = psDevice->psPrivateData;
    pUSBRequest = (tUSBRequest *)setup;

    //
    // Make sure to acknowledge that the data was read, this will not send and
    // ACK that has already been done at this point.  This just tells the
    // hardware that the data was read.
    //
    USBDevEndpointDataAck(psInst->ulUSBBase, USB_EP_0, FALSE);

    //
    // Don't stall by default.
    //
    ulStall = 0;

    //
    // Get the request type.
    //
    ulRecipient = pUSBRequest->bmRequestType & USB_RTYPE_RECIPIENT_M;

    //
    // Save the request type and request value.
    //
    psInst->usRequestType = pUSBRequest->bmRequestType;
    psInst->ucRequest = pUSBRequest->bRequest;

    //
    // Check if this is an endpoint request to the audio streaming endpoint.
    //
    if((ulRecipient == USB_RTYPE_ENDPOINT) &&
       (pUSBRequest->wIndex == USB_EP_TO_INDEX(psInst->ucOUTEndpoint)))
    {
        //
        // Determine the type of request.
        //
        switch(psInst->ucRequest)
        {
            case USB_AC_SET_CUR:
            {
                //
                // Handle retrieving the sample rate.
                //
                if(pUSBRequest->wValue == SAMPLING_FREQ_CONTROL)
                {
                    debug_printf("%s:%d. set ulSampleRate=%d\n",
                                __FUNCTION__, __LINE__, psInst->ulSampleRate);

                    //
                    // Retrieve the requested sample rate.
                    //
                    usbSetupEpReq(pGadgetObj,
                                  0U,
								  (uint32_t *)&psInst->ulSampleRate,
                                  USB_TOKEN_TYPE_OUT,
                                  3U,
                                  USB_TRANSFER_TYPE_CONTROL);

                    //
                    // Save what we are updating.
                    //
                    psInst->usUpdate = SAMPLING_FREQ_CONTROL;
                }
                break;
            }
            case USB_AC_GET_CUR:
            {
                //
                // Handle retrieving the sample rate.
                //
                if(pUSBRequest->wValue == SAMPLING_FREQ_CONTROL)
                {
                    //
                    // Send back the current sample rate.
                    //
                    usbSetupEpReq(pGadgetObj,
                                  0U,
								  (uint32_t *)&psInst->ulSampleRate,
                                  USB_TOKEN_TYPE_IN,
                                  3U,
                                  USB_TRANSFER_TYPE_CONTROL);

                    debug_printf("%s:%d. get ulSampleRate=%d\n",
                                __FUNCTION__, __LINE__, psInst->ulSampleRate);
                }
                break;
            }
            default:
            {
                //
                // Stall on unknown commands.
                //
                ulStall = 1;
                break;
            }
        }
    }
    else if(ulRecipient == USB_RTYPE_INTERFACE)
    {
        //
        // Make sure the request was for the control interface.
        //
        if((unsigned char)pUSBRequest->wIndex != psInst->ucInterfaceControl)
        {
            debug_printf("%s:%d. wrong wIndex\n",
                        __FUNCTION__, __LINE__);
            return;
        }

        //
        // Extract the control value from the message.
        //
        ulControl = pUSBRequest->wValue & USB_CS_CONTROL_M;

        //
        // Handle an audio control request to the feature control unit.
        //
#ifdef REC_PATH
        if (((AUDIO_FU_PLAY_ID << 8) == (pUSBRequest->wIndex & USB_CS_CONTROL_M)) ||
        	((AUDIO_FU_REC_ID << 8) == (pUSBRequest->wIndex & USB_CS_CONTROL_M)))
#else
            if ((AUDIO_FU_PLAY_ID << 8) == (pUSBRequest->wIndex & USB_CS_CONTROL_M))
#endif
        {
            //
            // Determine the type of request.
            //
            switch(psInst->ucRequest)
            {
                case USB_AC_GET_MAX:
                {
                    if(ulControl == VOLUME_CONTROL)
                    {
                        //
                        // Return the maximum volume setting.
                        //
                        usbSetupEpReq(pGadgetObj,
                                      0U,
								  (uint32_t *)&psInst->sVolumeMax,
                                      USB_TOKEN_TYPE_IN,
                                      2U,
                                      USB_TRANSFER_TYPE_CONTROL);

                        debug_printf("%s:%d. get sVolumeMax=%d\n",
                                    __FUNCTION__, __LINE__, psInst->sVolumeMax);
                    }
                    else
                    {
                        //
                        // Stall on unknown commands.
                        //
                        ulStall = 1;
                    }
                    break;
                }
                case USB_AC_GET_MIN:
                {
                    if(ulControl == VOLUME_CONTROL)
                    {
                        //
                        // Return the minimum volume setting.
                        //
                        usbSetupEpReq(pGadgetObj,
                                      0U,
								  (uint32_t *)&psInst->sVolumeMin,
                                      USB_TOKEN_TYPE_IN,
                                      2U,
                                      USB_TRANSFER_TYPE_CONTROL);
                        debug_printf("%s:%d. get sVolumeMin=%d\n",
                                    __FUNCTION__, __LINE__, psInst->sVolumeMin);
                    }
                    else
                    {
                        //
                        // Stall on unknown commands.
                        //
                        ulStall = 1;
                    }
                    break;
                }
                case USB_AC_GET_RES:
                {
                    if(ulControl == VOLUME_CONTROL)
                    {
                        //
                        // Return the volume step setting.
                        //
                        usbSetupEpReq(pGadgetObj,
                                      0U,
								  (uint32_t *)&psInst->sVolumeStep,
                                      USB_TOKEN_TYPE_IN,
                                      2U,
                                      USB_TRANSFER_TYPE_CONTROL);
                        debug_printf("%s:%d. get sVolumeStep=%d\n",
                                    __FUNCTION__, __LINE__, psInst->sVolumeStep);
                    }
                    else
                    {
                        //
                        // Stall on unknown commands.
                        //
                        ulStall = 1;
                    }
                    break;
                }
                case USB_AC_GET_CUR:
                {
                    if(ulControl == VOLUME_CONTROL)
                    {
                        //
                        // Send back the current volume level.
                        //
                        usbSetupEpReq(pGadgetObj,
                                      0U,
								  (uint32_t *)&psInst->sVolume,
                                      USB_TOKEN_TYPE_IN,
                                      2U,
                                      USB_TRANSFER_TYPE_CONTROL);
                        debug_printf("%s:%d. get sVolume=%d\n",
                                    __FUNCTION__, __LINE__, psInst->sVolume);
                    }
                    else if(ulControl == MUTE_CONTROL)
                    {
                        //
                        // Send back the current mute value.
                        //
                        usbSetupEpReq(pGadgetObj,
                                      0U,
								  (uint32_t *)&psInst->ucMute,
                                      USB_TOKEN_TYPE_IN,
                                      1U,
                                      USB_TRANSFER_TYPE_CONTROL);
                        debug_printf("%s:%d. get ucMute=%d\n",
                                    __FUNCTION__, __LINE__, psInst->ucMute);
                    }
                    else
                    {
                        //
                        // Stall on unknown commands.
                        //
                        ulStall = 1;
                    }
                    break;
                }
                case USB_AC_SET_CUR:
                {
                    if(ulControl == VOLUME_CONTROL)
                    {
                        //
                        // Read the new volume level.
                        //
                        usbSetupEpReq(pGadgetObj,
                                      0U,
								  (uint32_t *)&psInst->sVolume,
                                      USB_TOKEN_TYPE_OUT,
                                      2U,
				      USB_TRANSFER_TYPE_CONTROL);
                        debug_printf("%s:%d. set sVolume=%d\n",
                                    __FUNCTION__, __LINE__, psInst->sVolume);

                        //
                        // Save what we are updating.
                        //
                        psInst->usUpdate = VOLUME_CONTROL;
                    }
                    else if(ulControl == MUTE_CONTROL)
                    {
                        //
                        // Read the new mute setting.
                        //
                        usbSetupEpReq(pGadgetObj,
                                      0U,
								  (uint32_t *)&psInst->ucMute,
                                      USB_TOKEN_TYPE_OUT,
                                      1U,
                                      USB_TRANSFER_TYPE_CONTROL);
                        debug_printf("%s:%d. set ucMute=%d\n",
                                    __FUNCTION__, __LINE__, psInst->ucMute);

                        //
                        // Save what we are updating.
                        //
                        psInst->usUpdate = MUTE_CONTROL;
                    }
                    else
                    {
                        //
                        // Stall on unknown commands.
                        //
                        ulStall = 1;
                    }
                    break;
                }
                case USB_AC_SET_RES:
                {
                    if(ulControl == VOLUME_CONTROL)
                    {
                        //
                        // Read the new volume step setting.
                        //
                        usbSetupEpReq(pGadgetObj,
                                      0U,
								  (uint32_t *)&psInst->sVolumeStep,
                                      USB_TOKEN_TYPE_OUT,
                                      2U,
                                      USB_TRANSFER_TYPE_CONTROL);
                        debug_printf("%s:%d. set sVolumeStep=%d\n",
                                    __FUNCTION__, __LINE__, psInst->sVolumeStep);

                        //
                        // Save what we are updating.
                        //
                        psInst->usUpdate = VOLUME_CONTROL;
                    }
                    else
                    {
                        //
                        // Stall on unknown commands.
                        //
                        ulStall = 1;
                    }
                    break;
                }
                default:
                {
                    //
                    // Stall on unknown commands.
                    //
                    ulStall = 1;
                    break;
                }
            }
        }
    }

    //
    // Stall on all unknown commands.
    //
    if(ulStall)
    {
        debug_printf("%s:%d. stall\n",
                    __FUNCTION__, __LINE__);
    }
}

//*****************************************************************************
//
//! This function is used to supply buffers to the audio class to be filled
//! from the USB host device.
//!
//! \param pvInstance is the pointer to the device instance structure as
//! returned by USBDAudioInit() or USBDAudioInitComposite().
//! \param pvBuffer is a pointer to the buffer to fill with audio data.
//! \param ulSize is the size in bytes of the buffer pointed to by the pvBuffer
//! parameter.
//! \param pfnCallback is a callback that will provide notification when this
//! buffer has valid data.
//!
//! This function fills the buffer pointed to by the \e pvBuffer parameter with
//! at most \e ulSize one packet of data from the host controller.  The ulSize
//! has a minimum value of \b ISOC_OUT_EP_MAX_SIZE since each USB packet can be
//! at most \b ISOC_OUT_EP_MAX_SIZE bytes in size.  Since the audio data may
//! not be received in amounts that evenly fit in the buffer provided, the
//! buffer may not be completely filled.  The \e pfnCallback function will
//! provide the amount of valid data that was actually stored in the buffer
//! provided.  The function will return zero if the buffer could be scheduled
//! to be filled, otherwise the function will return a non-zero value if there
//! was some reason that the buffer could not be added.
//!
//! \return Returns 0 to indicate success any other value indicates that the
//! buffer will not be filled.
//
//*****************************************************************************
long
USBAudioBufferOut(void *pvInstance, void *pvBuffer, unsigned long ulSize,
                  tUSBAudioBufferCallback pfnCallback)
{
    tAudioInstance *psInst;

    //
    // Make sure we were not passed NULL pointers.
    //
    ASSERT(pvInstance != 0);
    ASSERT(pvBuffer != 0);

    debug_printf("%s:%d.\n",
                __FUNCTION__, __LINE__);

    //
    // Buffer must be at least one packet in size.
    //
    ASSERT(ulSize >= ISOC_OUT_EP_MAX_SIZE);
    ASSERT(pfnCallback);

    //
    // Create a pointer of the correct type from the private pointer.
    //
    psInst = (tAudioInstance *)pvInstance;

    //
    // Initialize the buffer instance.
    //
    psInst->sBuffer.pvData = pvBuffer;
    psInst->sBuffer.ulSize = ulSize;
    psInst->sBuffer.ulNumBytes = 0;
    psInst->sBuffer.pfnCallback = pfnCallback;

	usb_osalCacheWb(&(psInst->sBuffer), sizeof(psInst->sBuffer));

    return(0);
}

//*****************************************************************************
//
//! This function is used to supply audio data for the USB host request.
//!
//! \param pvInstance is the pointer to the device instance structure as
//! returned by USBDAudioInit() or USBDAudioInitComposite().
//! \param pvBuffer is a pointer to the audio data.
//! \param ulSize is the size in bytes of the data pointed to by the pvBuffer
//! parameter.
//! \param pfnCallback is a callback that will provide notification when this
//! data has transmitted to USB host.
//!
//! This function transmits the data pointed to by the \e pvBuffer parameter with
//! at most \e ulSize one packet of data to the host controller.  The ulSize
//! has a maximum value of \b ISOC_IN_EP_MAX_SIZE since each USB packet can be
//! at most \b ISOC_IN_EP_MAX_SIZE bytes in size.  Since the audio data may
//! not be sent in amounts of ISOC_IN_EP_MAX_SIZE bytes, the
//! buffer may not be completely full.  The \e pfnCallback function
//! provides the amount of audio data that was actually stored in the buffer
//! provided in ulSize.  The function will return zero if the buffer has been sent out
//! properly, otherwise the function will return a non-zero value if there
//! was some reason that the data could not be sent.
//!
//! \return Returns 0 to indicate success any other value indicates that the
//! data has not be sent out.
//
//*****************************************************************************
long
USBAudioBufferIn(void *pvInstance, void *pvBuffer, unsigned long ulSize,
                  tUSBAudioBufferCallback pfnCallback)
{
    tAudioInstance *psInst;

    //
    // Make sure we were not passed NULL pointers.
    //
    ASSERT(pvInstance != 0);
    ASSERT(pvBuffer != 0);

    debug_printf("%s:%d.\n",
                __FUNCTION__, __LINE__);

    //
    // Buffer must be at least one packet in size.
    //
    ASSERT(ulSize >= ISOC_IN_EP_MAX_SIZE);
    ASSERT(pfnCallback);

    //
    // Create a pointer of the correct type from the private pointer.
    //
    psInst = (tAudioInstance *)pvInstance;

    //
    // Initialize the buffer instance.
    //
    psInst->sBufferRec.pvData = pvBuffer;
    psInst->sBufferRec.ulSize = ulSize;
    psInst->sBufferRec.ulNumBytes = 0;
    psInst->sBufferRec.pfnCallback = pfnCallback;

	usb_osalCacheWb(&(psInst->sBuffer), sizeof(psInst->sBuffer));

    return(0);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

