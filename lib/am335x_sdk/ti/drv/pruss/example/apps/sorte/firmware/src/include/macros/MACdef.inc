; Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
;
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
;
; Redistributions of source code must retain the above copyright
; notice, this list of conditions and the following disclaimer.
;
; Redistributions in binary form must reproduce the above copyright
; notice, this list of conditions and the following disclaimer in the
; documentation and/or other materials provided with the
; distribution.
;
; Neither the name of Texas Instruments Incorporated nor the names of
; its contributors may be used to endorse or promote products derived
; from this software without specific prior written permission.
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
; defines
MAC_DEV_ID   .set    0
MAC_MODE_MPY .set    0
MAC_MODE_MAC .set    1


MAC_s .struct
ctlreg32     .uint
resL32         .uint
resH32         .uint
op1_32         .uint
op2_32         .uint
sMAC_size    .endstruct

sMAC .sassign R25,MAC_s
    .asg  sMAC.ctlreg32 ,R25


; MACclear : Clear the carry bit and the accumulator

MACclear    .macro
            OR sMAC.ctlreg32,sMAC.ctlreg32,2
            XOUT MAC_DEV_ID,&sMAC.ctlreg32,1
            XOR sMAC.ctlreg32,sMAC.ctlreg32,2
            .endm

;MACsetmode : Set the MAC module in MPY or MAC mode

MACsetmode     .macro mode
            LDI    sMAC.ctlreg32, mode
            xout MAC_DEV_ID, &sMAC.ctlreg32, 1
            .endm

