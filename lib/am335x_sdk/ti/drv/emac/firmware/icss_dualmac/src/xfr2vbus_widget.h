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

;------------------------------------
;FILE: xfr2vbus_widget.h
;Purpose:  macros, etc for xfr2vbus_widget
;------------------------------------

;-----------------DEFINES-------------------------

;XIDs
XFR2VBUS_XID_READ0	.set	0x60
XFR2VBUS_XID_READ1	.set	0x61
XFR2VBUS_XID_WRITE	.set	0x62
XFR2VBUS_XID_WRITE0	.set	0x62
XFR2VBUS_XID_WRITE1	.set	0x63

	.asg	t2, XFR2VBUS_READ_DONE  ;set if read fifo non empty
;------------------MACROS--------------------------
;read in read result (32)
XFR2VBUS_READ32_RESULT	.macro 	 rnum
	xin	rnum, &r2, 32
 .endm

;issue a oneshot read of 32 bytes from addrss _lo|_hi
; steps on r18, r19,r20
XFR2VBUS_ISSUE_READ_ONESHOT_32	.macro 	 rnum, addr_lo,addr_hi
	and r20, addr_hi, addr_hi;Warning: converted from mov
	and r19, addr_lo, addr_lo;Warning: converted from mov
	ldi	r18, 0x4; [1.2] = 2 => 32 bytes
	add	r0, r0, 0;nop - see instability inr18	..
	xout	rnum, &r18, 12
 .endm
;poll for read complete
;returns in r18.tb2 the result
XFR2VBUS_POLL_READ	.macro 	 rnum
	xin	rnum, &r18, 4
 .endm

;issue a read of 64 bytes from addrss _lo|_hi, auto mode
;clobbers r18-r20
XFR2VBUS_ISSUE_READ_AUTO_64_CMD	.macro 	 rnum, addr_lo,addr_hi
	ldi	r20, addr_hi
	and r19, addr_lo, addr_lo
	ldi	r18, 0x7;(0x1 | 0x3>>1)
	xout	rnum, &r18, 12
 .endm

;issue cmd to stop read auto mode
XFR2VBUS_CANCEL_READ_AUTO_64_CMD	.macro 	 rnum
	ldi	r18, 0
	xout	rnum, &r18, 4
 .endm

;read in data64
; fills in r2-r17
XFR2VBUS_READ64_RESULT	.macro 	 rnum
	xin	rnum, &r2, 64
 .endm

XFR2VBUS_WAIT4READY .macro rnum
$1:	xin	rnum, &r18, 4
	qbne	$1, r18.w0, 0x5
 .endm

;read in data8
; fills in r2-r3
XFR2VBUS_READ8_RESULT	.macro 	 rnum
	xin	rnum, &r2, 8
 .endm

;issue a write of 32 bytes from address _lo|_hi, one shot
; data in r2-r9
; clobbers r10, r11
XFR2VBUS_WRITE32	.macro 	 xid, addr_lo,addr_hi
	and r10, addr_lo, addr_lo;Warning: converted from mov
	and r11, addr_hi, addr_hi;Warning: converted from mov
	xout	xid, &r2, 40
 .endm

