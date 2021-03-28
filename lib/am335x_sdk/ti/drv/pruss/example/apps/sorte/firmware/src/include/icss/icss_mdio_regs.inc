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
; file:   icss_mdio_regs.inc
;
; brief:  {ICSS MII Management I/F (MDIO) Registers}
;
;  author     {Vijaya Sarathy}
;
;  version    0.1     Created
;  			  0.2	  Ported to PRU C Compiler 		{Thomas Mauer}
;
	.if ! $defined( __icss_mdio_regs_inc)
	.define "1", __icss_mdio_regs_inc
ICSS_MDIO_VER					.set	0x0000	; Module Version
ICSS_MDIO_CNTL					.set	0x0004	; Control
ICSS_MDIO_ALIVE					.set	0x0008	; PHY Ack Status (Addressed PHY present, ack'd)
ICSS_MDIO_LINK					.set	0x000C	; PHY Link Status (Addressed PHY has established link)
ICSS_MDIO_LINKINTRAW			.set	0x0010	; PHY Link Status Change Interrupt (RAW)
ICSS_MDIO_LINKINTMASKED			.set	0x0014	; PHY Link Status Change Interrupt (Masked)
ICSS_MDIO_RSVD0					.set	0x0018	; Reserved Registers 0x0018..0x001C
ICSS_MDIO_USRINTRAW				.set	0x0020	; User Command Complete Interrupt (RAW)
ICSS_MDIO_USRINTMASKED			.set	0x0024	; User Command Complete Interrupt (Masked)
ICSS_MDIO_USRINTMASKSET			.set	0x0028	; User Interrupt Mask Set
ICSS_MDIO_USRINTMASKCLR			.set	0x002C	; User Interrupt Mask Clear
ICSS_MDIO_RSVD1					.set	0x0030	; Reserved Registers 0x0030..0x007C
ICSS_MDIO_USRACCESS0	.set	0x0080	; User Access Register 0
ICSS_MDIO_USRPHYSEL0			.set	0x0084	; User PHY Select Register 0
ICSS_MDIO_USRACCESS1	.set	0x0088	; User Access Register 1
ICSS_MDIO_USRPHYSEL1			.set	0x008C	; User PHY Select Register 1
ICSS_MDIO_RSVD2					.set	0x0090	; Reserved Registers 0x0090..0x00FF
	.endif
