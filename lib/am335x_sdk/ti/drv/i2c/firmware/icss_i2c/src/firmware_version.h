;
;  TEXAS INSTRUMENTS TEXT FILE LICENSE
; 
;   Copyright (c) 2017-2018 Texas Instruments Incorporated
; 
;  All rights reserved not granted herein.
;  
;  Limited License.  
; 
;  Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive 
;  license under copyrights and patents it now or hereafter owns or controls to 
;  make, have made, use, import, offer to sell and sell ("Utilize") this software 
;  subject to the terms herein.  With respect to the foregoing patent license, 
;  such license is granted  solely to the extent that any such patent is necessary 
;  to Utilize the software alone.  The patent license shall not apply to any 
;  combinations which include this software, other than combinations with devices 
;  manufactured by or for TI (“TI Devices”).  No hardware patent is licensed hereunder.
; 
;  Redistributions must preserve existing copyright notices and reproduce this license 
;  (including the above copyright notice and the disclaimer and (if applicable) source 
;  code license limitations below) in the documentation and/or other materials provided 
;  with the distribution.
;  
;  Redistribution and use in binary form, without modification, are permitted provided 
;  that the following conditions are met:
; 	No reverse engineering, decompilation, or disassembly of this software is 
;   permitted with respect to any software provided in binary form.
; 	Any redistribution and use are licensed by TI for use only with TI Devices.
; 	Nothing shall obligate TI to provide you with source code for the software 
;   licensed and provided to you in object code.
;  
;  If software source code is provided to you, modification and redistribution of the 
;  source code are permitted provided that the following conditions are met:
; 	Any redistribution and use of the source code, including any resulting derivative 
;   works, are licensed by TI for use only with TI Devices.
; 	Any redistribution and use of any object code compiled from the source code
;   and any resulting derivative works, are licensed by TI for use only with TI Devices.
; 
;  Neither the name of Texas Instruments Incorporated nor the names of its suppliers 
;  may be used to endorse or promote products derived from this software without 
;  specific prior written permission.
; 
;  DISCLAIMER.
; 
;  THIS SOFTWARE IS PROVIDED BY TI AND TI’S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED 
;  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
;  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI’S 
;  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
;  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
;  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
;  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
;  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
;  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 
; file:   firmware_version.h
;
; brief:  ICSS Ethernet MAC Firmware Version Control
;			
;
;  (C) Copyright 2017, Texas Instruments, Inc
;
;
	
    .if !$defined("__firmware_version_h")	
__firmware_version_h	.set	1	
	
; I2C_FIRMWARE_DEVICE_VERSION: 
; bit31..24    Device type
FIRMWARE_DEVICE_ICSS_REV1              .set    0    
FIRMWARE_DEVICE_ICSS_REV2              .set    1    

; bit23..0    protocol type
FIRMWARE_PROTOCOL_CONTROL_CLASS        .set    0x01
FIRMWARE_PROTOCOL_TYPE_I2C_VERSION1    .set    0x01

; bit31        release or internal version
FIRMWARE_VERSION_INTERNAL              .set    1    
FIRMWARE_VERSION_RELEASE               .set    0    
; bit30..24    major version number                                    ;For major IP changes.
FIRMWARE_VERSION_MAJOR                 .set    0x01    
; bit23..16    minor version number                                    ;For feature additions to firmware.
FIRMWARE_VERSION_MINOR                 .set    0x01
; bit15..0        build number                                         ;For all other minor changes.
FIRMWARE_VERSION_BUILD                 .set    0x00    

; macro for indicating type of firmware and device
    .if $defined("ICSS_REV1")    
I2C_FIRMWARE_TYPE                      .set    ((FIRMWARE_DEVICE_ICSS_REV1 << 24) | (FIRMWARE_PROTOCOL_CONTROL_CLASS << 8) | (FIRMWARE_PROTOCOL_TYPE_I2C_VERSION1 << 0)) 
    .endif
    .if $defined("ICSS_REV2")    
I2C_FIRMWARE_TYPE                      .set    ((FIRMWARE_DEVICE_ICSS_REV2 << 24) | (FIRMWARE_PROTOCOL_CONTROL_CLASS << 8) | (FIRMWARE_PROTOCOL_TYPE_I2C_VERSION1 << 0)) 
    .endif

; macro for indicating version of firmware
I2C_FIRMWARE_VERSION                   .set    ((FIRMWARE_VERSION_RELEASE << 31) | (FIRMWARE_VERSION_MAJOR << 24) | (FIRMWARE_VERSION_MINOR << 16) | (FIRMWARE_VERSION_BUILD << 0))

    
; Bitmap for various feature supported in firmware
I2C_FIRMWARE_FEATURE                   .set    0

; Offset to an extended feature structure for future use.
I2C_FIRMWARE_EXTENDED_FEATURE_PTR      .set    0

    .endif	;__firmware_version_h
