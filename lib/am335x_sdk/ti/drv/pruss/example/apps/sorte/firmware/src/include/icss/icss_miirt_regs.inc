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
; file:   icss_miirt_regs.inc
;
; brief:  {ICSS MII_RT Module Registers}
;
;
;
;  author     {Vijaya Sarathy}
;
;  version    0.1     Created
;  version 	  0.2	  Ported to PRU C Compiler {Thomas Mauer}
;
	.if ! $defined(__icss_miirt_regs_inc)
	.define	"1", __icss_miirt_regs_inc
ICSS_MIIRT_RXCFG0 	.set	0x0000	; RX Port attached to PRU0 Configuration
ICSS_MIIRT_RXCFG1	.set	0x0004	; RX Port attached to PRU1 Configuration
ICSS_MIIRT_RSVD0	.set	0x0008	; Reserved
ICSS_MIIRT_TXCFG0	.set	0x0010	; TX Port0 Configuration
ICSS_MIIRT_TXCFG1	.set	0x0014	; TX Port1 Configuration
ICSS_MIIRT_RSVD1	.set	0x0018	; Reserved
ICSS_MIIRT_TXCRC0	.set	0x0020	; HW Accumulated TX Port0 CRC32 Read Only
ICSS_MIIRT_TXCRC1	.set	0x0024	; HW Accumulated TX POrt1 CRC32 Read Only
ICSS_MIIRT_TXIPG0	.set	0x0030	; TX Port0 Min Inter Packet Gap
ICSS_MIIRT_TXIPG1	.set	0x0034	; TX Port1 Min Inter Packet Gap
ICSS_MIIRT_PRS0		.set    0x0038	; PRU0 Raw Status Read Only
ICSS_MIIRT_PRS1		.set    0x003c	; PRU1 Raw Status Read Only
ICSS_MIIRT_RXFRMS0	.set	0x0040	; RX Port0 Frame Length Min/Max Limits
ICSS_MIIRT_RXFRMS1	.set	0x0044	; RX Port1 Frame Length Min/Max Limits
ICSS_MIIRT_RXPCNT0	.set	0x0048	; RX Port0 Preamble Length Min/Max Limits
ICSS_MIIRT_RXPCNT1	.set	0x004C	; RX Port1 Preamble Length Min/Max Limits
ICSS_MIIRT_RXERR0	.set	0x0050	; RX Port0 Error Status, Write 1 to Clear
ICSS_MIIRT_RXERR1	.set	0x0054	; RX Port1 Error Status, Write 1 to Clear
	.endif
