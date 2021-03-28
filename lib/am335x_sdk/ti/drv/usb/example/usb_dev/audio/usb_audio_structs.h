/**
 *  \file  usb_audio_structs.h
 *
 *  \brief Data Structures defining the audio class USB device.
 *
 *
 *
 *  \copyright Copyright (C) 2017-2019 Texas Instruments Incorporated -
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

#ifndef USB_AUDIO_STRUCTS_H
#define USB_AUDIO_STRUCTS_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
extern const tUSBDAudioDevice g_sAudioDevice;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */
/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/** \brief This API is the externally provided mass storage class event call back
 *        function
 */
extern uint32_t USBDAudioEventCallback(struct usbGadgetObj *pGadgetObject, void *pvCBData, uint32_t ulEvent,
                                       uint32_t ulMsgParam,
                                       void *pvMsgData);

//*****************************************************************************
//
// These are the Volume control basics that are provided back to the USB host
// controller and are based on the Texas Instruments TLV320AIC23B device.
//
//*****************************************************************************
#define VOLUME_MAX              ((short)0x0073)  // 59.5db
#define VOLUME_MIN              ((short)0x0000)  // 0db
#define VOLUME_STEP             ((short)0x0001)  // 0.5db


#ifdef __cplusplus
}
#endif

#endif /* #ifndef USB_AUDIO_STRUCTS_H */
