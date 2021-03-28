;
;  TEXAS INSTRUMENTS TEXT FILE LICENSE
;
;   Copyright (c) 2018-2019 Texas Instruments Incorporated
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
;-----------------------------------
;basicio.h
;  basic rx, tx i/o routines
;------------------------------------
RXL2_BANK0	.set	20
RXL2_BANK1	.set	21
TXL2	.set	40
CS	.set	38
XFR2PSI_XID	.set	0x31
PSI_PAT	.set	0x10

;B_EOF RX + BANK0  (rcv only) - clobbers: r18, r2-r9,
RX_EOF_RCV_BANK0	.macro
	.newblock
	xin	RXL2_BANK0, &r18, 2 ;read len
	min	r0.b0, r18.b0, 32
	qbeq	$1, r18.w0, 0 ;skip if no data
	xin	RXL2_BANK0, &r2, b0 ;read in only what we need
$1:
 .endm

;B_EOF RX + BANK1  (rcv only) - clobbers: r18, r2-r9,
RX_EOF_RCV_BANK1	.macro
	.newblock
	xin	RXL2_BANK1, &r18, 2 ;read len
	sub	r18, r18, 32
	min	r0.b0, r18.b0, 32
	qbeq	$1, r18.w0, 0 ;skip if no data
	xin	RXL2_BANK1, &r2, b0;read in only what we need
$1:
 .endm

;move n  bytes from XFR2VBUS Read fifo to TXL2 fifo (n in .b0)
BN_TX_N	.macro	cnt
	.newblock
$1:	xin	TXL2, &r19, 4
	qbne	$1, r19.b2, 0
	mov	r0.b0, cnt
	xout	TXL2, &r2, b0
 .endm
