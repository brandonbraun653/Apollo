/**
 *  \file  usb_audio_structs.c
 *
 *  \brief This file contains the data structures defining the
 *         USB audio device.
 */

/**
 * \copyright  Copyright (C) 2017-2019 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "usblib.h"
#include "usbdevice.h"
#include "usbdaudio.h"
#include "usb_audio_structs.h"
#include "usb-ids.h"


/* ========================================================================== */
/*                          Macros and Typedefs                               */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
uint32_t
usbDAudioEventCallback(struct usbGadgetObj *pGadgetObject, void *pvCBData, uint32_t ui32Event, uint32_t ui32MsgParam,
                     void *pvMsgData);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

tAudioInstance g_sAudioInstance;

/* The languages supported by this device */
uint8_t g_pLangDescriptor[] =
{
    4,
    USB_DTYPE_STRING,
    USBShort(USB_LANG_EN_US)
};

/* The manufacturer string */
uint8_t g_pManufacturerString[] =
{
    (17 + 1) * 2,
    USB_DTYPE_STRING,
    'T', 0, 'e', 0, 'x', 0, 'a', 0, 's', 0, ' ', 0, 'I', 0, 'n', 0, 's', 0,
    't', 0, 'r', 0, 'u', 0, 'm', 0, 'e', 0, 'n', 0, 't', 0, 's', 0,
};

/* The product string */
uint8_t g_pProductString[] =
{
	(13 + 1) * 2,
	USB_DTYPE_STRING,
	'A', 0, 'u', 0, 'd', 0, 'i', 0, 'o', 0, ' ', 0, 'E', 0, 'x', 0, 'a', 0,
	'm', 0, 'p', 0, 'l', 0, 'e', 0
};

/* Serial number string */

uint8_t g_pSerialNumberString[] =
{
    (8 + 1) * 2,
    USB_DTYPE_STRING,
    '1', 0, '2', 0, '3', 0, '4', 0, '5', 0, '6', 0, '7', 0, '8', 0
};

/* Audio interface description String */
uint8_t g_pAudioInterfaceString[] =
{
    (15 + 1) * 2,
    USB_DTYPE_STRING,
    'A', 0, 'u', 0, 'd', 0, 'i', 0, 'o', 0, ' ', 0, 'I', 0, 'n', 0,
	't', 0, 'e', 0, 'r', 0, 'f', 0, 'a', 0, 'c', 0, 'e', 0
};

/* Configuration description String */

uint8_t g_pConfigString[] =
{
	(20 + 1) * 2,
	USB_DTYPE_STRING,
	'A', 0, 'u', 0, 'd', 0, 'i', 0, 'o', 0, ' ', 0, 'C', 0, 'o', 0,
	'n', 0, 'f', 0, 'i', 0, 'g', 0, 'u', 0, 'r', 0, 'a', 0, 't', 0,
	'i', 0, 'o', 0, 'n', 0
};

/* String descriptor supported by this device */
uint8_t * g_pStringDescriptors[] =
{
    g_pLangDescriptor,
    g_pManufacturerString,
    g_pProductString,
    g_pSerialNumberString,
    g_pAudioInterfaceString,
    g_pConfigString
};


#define NUM_STRING_DESCRIPTORS (sizeof(g_pStringDescriptors) /                \
                                sizeof(uint8_t *))

const tUSBDAudioDevice g_sAudioDevice =
{
		//
		// The Vendor ID you have been assigned by USB-IF.
		//
		USB_VID_STELLARIS,
		//
		// The product ID you have assigned for this device.
		//
		USB_PID_AUDIO,
		//
		// The vendor string for your device (8 chars).
		//
		"TI      ",
		//
		// The product string for your device (16 chars).
		//
		"Audio Class     ",
		//
		// The revision string for your device (4 chars BCD).
		//
		"1.00",
		//
		// The power consumption of your device in milliamps.
		//
		500,
		//
		// The value to be passed to the host in the USB configuration descriptor’s
		// bmAttributes field.
		//
		USB_CONF_ATTR_SELF_PWR,
		//
		// A pointer to your string table.
		//
		(const unsigned char * const *)g_pStringDescriptors,
		//
		// The number of entries in your string table.
		//
		NUM_STRING_DESCRIPTORS,
		//
		// A pointer to your control callback event handler.
		//
		usbDAudioEventCallback,
		//
		// Maximum volume setting expressed as and 8.8 signed fixed point number.
		//
		100,
		//
		// Minimum volume setting expressed as and 8.8 signed fixed point number.
		//
		0,
		//
		// Minimum volume step expressed as and 8.8 signed fixed point number.
		//
		1,
		//
		// pointer to audio class instance
		//
		&g_sAudioInstance
};
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* None */

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/* None */
