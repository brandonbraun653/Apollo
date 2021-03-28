; 
; Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
; 
; 
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
; 
;        * Redistributions of source code must retain the above copyright
;          notice, this list of conditions and the following disclaimer.
; 
;        * Redistributions in binary form must reproduce the above copyright
;          notice, this list of conditions and the following disclaimer in the
;          documentation and/or other materials provided with the
;          distribution.
; 
;        * Neither the name of Texas Instruments Incorporated nor the names of
;          its contributors may be used to endorse or promote products derived
;          from this software without specific prior written permission.
; 
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
; "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
; LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
; A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
; OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
; SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
; LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
; DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
; (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
; OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;

; file:   firmware_version.h
;
; brief:  PRU UART Firmware Version Control
;			
	
    .if !$defined("__firmware_version_h")	
__firmware_version_h	.set	1	

; UART_FIRMWARE_DEVICE_VERSION: 
; bit31..24    Device type
FIRMWARE_DEVICE_ICSS_REV1              .set    0    
FIRMWARE_DEVICE_ICSS_REV2              .set    1    

; bit23..0    protocol type
FIRMWARE_PROTOCOL_CONTROL_CLASS        .set    0x02
FIRMWARE_PROTOCOL_TYPE_UART_VERSION1   .set    0x01

; bit31        release or internal version
FIRMWARE_VERSION_INTERNAL              .set    1    
FIRMWARE_VERSION_RELEASE               .set    0    
; bit30..24    major version number                                    ;For major IP changes.
FIRMWARE_VERSION_MAJOR                 .set    0x01    
; bit23..16    minor version number                                    ;For feature additions to firmware.
FIRMWARE_VERSION_MINOR                 .set    0x00
; bit15..0        build number                                         ;For all other minor changes.
FIRMWARE_VERSION_BUILD                 .set    0x00    

; macro for indicating type of firmware and device
    .if $defined("ICSS_REV1")    
UART_FIRMWARE_TYPE                     .set    ((FIRMWARE_DEVICE_ICSS_REV1 << 24) | (FIRMWARE_PROTOCOL_CONTROL_CLASS << 8) | (FIRMWARE_PROTOCOL_TYPE_UART_VERSION1 << 0)) 
    .endif
    .if $defined("ICSS_REV2")    
UART_FIRMWARE_TYPE                     .set    ((FIRMWARE_DEVICE_ICSS_REV2 << 24) | (FIRMWARE_PROTOCOL_CONTROL_CLASS << 8) | (FIRMWARE_PROTOCOL_TYPE_UART_VERSION1 << 0)) 
    .endif

; macro for indicating version of firmware
UART_FIRMWARE_VERSION                  .set    ((FIRMWARE_VERSION_RELEASE << 31) | (FIRMWARE_VERSION_MAJOR << 24) | (FIRMWARE_VERSION_MINOR << 16) | (FIRMWARE_VERSION_BUILD << 0))

    
; Bitmap for various feature supported in firmware
UART_FIRMWARE_FEATURE                  .set    0

; Offset to an extended feature structure for future use.
UART_FIRMWARE_EXTENDED_FEATURE_PTR     .set    0

    .endif	;__firmware_version_h
