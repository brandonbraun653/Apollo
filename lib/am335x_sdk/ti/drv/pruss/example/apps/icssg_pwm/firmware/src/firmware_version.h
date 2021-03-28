/*
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *	* Redistributions of source code must retain the above copyright
 *	  notice, this list of conditions and the following disclaimer.
 *
 *	* Redistributions in binary form must reproduce the above copyright
 *	  notice, this list of conditions and the following disclaimer in the
 *	  documentation and/or other materials provided with the
 *	  distribution.
 *
 *	* Neither the name of Texas Instruments Incorporated nor the names of
 *	  its contributors may be used to endorse or promote products derived
 *	  from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _FIRMWARE_VERSION_H_
#define _FIRMWARE_VERSION_H_

/*  
    ICSSG_PWM_FIRMWARE_DEVICE_VERSION: 
    bit31..24    Device type 
*/
#define FIRMWARE_DEVICE_ICSS_REV1                   0    
#define FIRMWARE_DEVICE_ICSS_REV2                   1    

/*
    bit23..0    protocol type
*/
#define FIRMWARE_PROTOCOL_CONTROL_CLASS             0x02
#define FIRMWARE_PROTOCOL_TYPE_ICSSG_PWM_VERSION1   0x01

/*
    bit31        release or internal version
*/
#define FIRMWARE_VERSION_INTERNAL                   1    
#define FIRMWARE_VERSION_RELEASE                    0    
/*
    bit30..24    major version number,  for major IP changes.
*/
#define FIRMWARE_VERSION_MAJOR                      0x01
/*
    bit23..16    minor version number,  for feature additions to firmware.
*/
#define FIRMWARE_VERSION_MINOR                      0x00
/*
    bit15..0        build number,       for all other minor changes.
*/
#define FIRMWARE_VERSION_BUILD                      0x00

/* macro for indicating type of firmware and device */
#define ICSSG_PWM_FIRMWARE_TYPE                     ((FIRMWARE_DEVICE_ICSS_REV2 << 24) | (FIRMWARE_PROTOCOL_CONTROL_CLASS << 8) | (FIRMWARE_PROTOCOL_TYPE_ICSSG_PWM_VERSION1 << 0))

/* macro for indicating version of firmware */
#define ICSSG_PWM_FIRMWARE_VERSION                  ((FIRMWARE_VERSION_RELEASE << 31) | (FIRMWARE_VERSION_MAJOR << 24) | (FIRMWARE_VERSION_MINOR << 16) | (FIRMWARE_VERSION_BUILD << 0))

/* Bitmap for various feature supported in firmware */
#define ICSSG_PWM_FIRMWARE_FEATURE                  ( 0x00001998 )  /* Firmware Feature - support for 24 PWMs, 12 IEP0 PWMs, 12 IEP1 PWMs */

/* Offset to an extended feature structure for future use. */
#define ICSSG_PWM_FIRMWARE_EXTENDED_FEATURE_PTR     ( 0 )           /* Firmware Extended Feature - Reserved for future use */

#endif /* _FIRMWARE_VERSION_H_ */
