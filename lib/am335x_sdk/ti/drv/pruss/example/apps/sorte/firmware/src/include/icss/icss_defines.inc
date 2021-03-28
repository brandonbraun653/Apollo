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
; file:   icss_defines.inc
;
; brief:  ICSS Specific Defines
;
;  author     {Thomas Leyrer, Thomas Mauer}
;
;  version    0.1     Created

	.if ! $defined( __icss_defines_inc)
	.define "1", __icss_defines_inc

; Bank ids for Xfer instructions
SCRATCH_BANK0	.set		10		 
SCRATCH_BANK1	.set		11		
SCRATCH_BANK2	.set		12		
RXL2_BANK0		.set		20  ; RX_L2 Fifo bank 0
RXL2_BANK1		.set		21  ; RX_L2 Fifo bank 1
RANGE_R2_R18 	.set   (4*16+1)	; only up to R18.b0
RANGE_R2_R13	.set   (4*12)
RANGE_R2_R9		.set   (4*8)
RANGE_R10_R13	.set   (4*4)

	.if	$isdefed("SWITCH_CFG")
	.if	$isdefed("PRU0")
MII_CARRIER_SENSE_REG	.set  ICSS_MIIRT_PRS1
	.else
MII_CARRIER_SENSE_REG	.set  ICSS_MIIRT_PRS0
	.endif
	.else
	.if	$isdefed("PRU0")
MII_CARRIER_SENSE_REG	.set  ICSS_MIIRT_PRS0
	.else
MII_CARRIER_SENSE_REG	.set  ICSS_MIIRT_PRS1
	.endif
	.endif

	.endif
