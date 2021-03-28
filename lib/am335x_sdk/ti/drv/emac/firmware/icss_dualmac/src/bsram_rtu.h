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

;BS RAM - RTU Uses
;   -- ping pong buffer
;   -- register page
;file: bsram_rtu.h

Q_XID	.set	 (30)   ;for rtu BS

;---------------------------------------------------------
;register paging
;--------------------------------------------------------

;these preserve r10 in r0
PAGE_SAVE	.macro	pn
	mov	r0, r10
	ldi	r10, pn
	xout	Q_XID, &r2, 36
	mov	r10, r0
 .endm

PAGE_RESTORE	.macro	pn, n
	mov	r0, r10
	ldi	r10, pn
	xout	Q_XID, &r10.w0, 2
	xin	Q_XID, &r2, n
	mov	r10, r0
 .endm

;these don't preserve r10
PAGE_SAVE2	.macro	pn
	ldi	r10, pn
	xout	Q_XID, &r2, 36
 .endm

;this assumes r10 already set
PAGE_SAVEQ	.macro
	xout	Q_XID, &r2, 36
 .endm

;these don't preserve r10
PAGE_RESTORE2	.macro	pn, n
	ldi	r10, pn
	xout	Q_XID, &r10.w0, 2
	xin	Q_XID, &r2, n
 .endm

;these preserve r10 in r0
PAGE_SAVE_REG	.macro	pn
	mov	r0, r10
	mov	r10, pn
	xout	Q_XID, &r2, 36
	mov	r10, r0
 .endm

PAGE_RESTORE_REG	.macro	pn, n
	mov	r0, r10
	mov	r10, pn
	xout	Q_XID, &r10.w0, 2
	xin	Q_XID, &r2, n
	mov	r10, r0
 .endm

;these don't preserve r10
PAGE_SAVE2_REG	.macro	pn
	mov	r10, pn
	xout	Q_XID, &r2, 36
 .endm

;these don't preserve r10
PAGE_RESTORE2_REG	.macro	pn, n
	mov	r10, pn
	xout	Q_XID, &r10.w0, 2
	xin	Q_XID, &r2, n
 .endm

;'slots' used for PAGEING
RTU_PAGE0	.set	0x50
RTU_PAGE1	.set	0x51
RTU_PAGE2	.set	0x52

;slot used for gstate
RTU_GSTATE	.set	0x53

;slots used for task stack
RX_TASK_SLOT	.set	0x54
RX_TASK_SLOT1	.set	0x55
TX_TASK_SLOT	.set	0x56
TX_TASK_SLOT1	.set	0x57

;slots used for scheduler
SCHED_MAIN	.set	0x58
SCHED_SHADOW	.set	0x59
;#define  SCHED_EPKT   (see below)

;slots use for psi read
BS_SLOT_PSI0	.set	0x5a
BS_SLOT_PSI1	.set	0x5b
BS_SLOT_PSI2	.set	0x5c
BS_SLOT_PSI3	.set	0x5d
;slots used for psi stash
PSI_CNTX0_SLOT	.set	0x60
PSI_CNTX1_SLOT	.set	0x61
PSI_CNTX2_SLOT	.set	0x62
PSI_CNTX3_SLOT	.set	0x63
;used for portq managment
BSRAM_PQ_LOCK_SLOT	.set	0x64

;PSI PSI INFO, CONTROL, STATUS TEMPLATES
PSI_INFO_SLOT	.set	0x65
PSI_STATUS_SLOT	.set	0x66

;slots for psi control info
PSI_CONTROL_S0	.set	0x67
PSI_CONTROL_S1	.set	0x68
PSI_CONTROL_S2	.set	0x69
PSI_CONTROL_S3	.set	0x6a

SCHED_MAIN_EXP	.set	0x6b
RX_STASH_SLOT	.set	0x6c
SCHED_MAIN2	.set	0x6d

PSI_MGR_INFO_SLOT	.set	0x6e
PSI_TXTS_INFO_SLOT	.set	0x6f

