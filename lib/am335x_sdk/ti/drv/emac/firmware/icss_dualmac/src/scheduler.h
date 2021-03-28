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

;----------------------------------------------------------
; scheduler.h:  defines and macros for ICSS-G port scheduler
;   v0.1
;   Notes: runs on RTU
;-----------------------------------------------------------

;----------------------
; utility: cleanup tx
;----------------------
CLEANUP_TX	.macro 	 slot ; {{{1
	TM_DISABLE
	PAGE_RESTORE2 slot, 32
;r7-r8 = descriptor
        add	r0.b0, r8.b3, BP_SLOT0_PRU
        CEIL64  r18.w0,r8.w0
        BUFP_PUSH r0, r18.w0
	TM_ENABLE
 .endm

;==============================
;  STATE 00 state entry point ;STATE_00_EP {{{1
;=============================
; use r2-r9
; step on r18-r20
; preserve r20 in r0 temp
STATE_00_EP	.macro
	.newblock
	SCHED_CHECK_DMA	;see if we can complete previous dma(s)
;(1) preemption not allowed, so we can ping pong dmas
;see if ok to start DMA
	qbbs	$1, GRrtu.flags, f_dmau
	qbbs	done?, GRrtu.flags, f_dma0
	jmp	$2
$1:	qbbs	done?, GRrtu.flags, f_dma1
$2:
;check if we need to send TX_TS here
	qbbc	$4, GRrtu.flags,  f_tstx_ready
	ldi32	r10, FW_CONFIG + TX_TS_BASE
	lbbo	&r2, r10, 0, 16
	set	r4.t0
	SEND_TXTS_PKT
	clr	GRrtu.flags, GRrtu.flags, f_tstx_ready
;ok to start
$4:
	and	GRrtu.spare, GRrtu.qmask, GRrtu.pqmap
	lmbd	GRrtu.spare, GRrtu.spare,1
	qbeq	done?, GRrtu.spare, 32
;GRrtu.spare  holds portq #   7-0
	add	r9, GRrtu.spare, MQ_SLOT0_RTU
	TM_DISABLE
	MQ_POP	r9, qempty_exit?
	qbne	$3, MQ_CNT, 0
	clr	GRrtu.pqmap, GRrtu.pqmap, GRrtu.spare
$3:	; non_empty00
	TM_ENABLE
;r7-r8 = descriptor
	mov	r0, r20

;popped packet, decide which dma to use
	qbbs	use_dma1?, GRrtu.flags, f_dmau
;use dma0 (unit0)
	set	GRrtu.flags, GRrtu.flags, f_dmau
	set	GRrtu.flags, GRrtu.flags, f_dma0
	XFR2VBUS_ISSUE_READ_AUTO_64_CMD	XFR2VBUS_XID_READ0, r7, ADDR_HI
	clr	r8.t20
	mov	r20, r0
	mov	r2, r8
	qbbs	$5, GRrtu.speed_f, f_half_d
	write_bd_to_smem  r7, BD_OFS_0
$5:	RTU_IPC_TX_CH0_PPKT
	PAGE_SAVE2 SCHED_MAIN
	jmp	done?

use_dma1?:
;use dma1 (unit1)
	clr	GRrtu.flags, GRrtu.flags, f_dmau
	XFR2VBUS_ISSUE_READ_AUTO_64_CMD	XFR2VBUS_XID_READ1, r7, ADDR_HI
	set	r8.t20
	set	GRrtu.flags, GRrtu.flags, f_dma1
	mov	r20, r0
	mov	r3, r8
	qbbs	$6, GRrtu.speed_f, f_half_d
	write_bd_to_smem  r7, BD_OFS_1
$6:	RTU_IPC_TX_CH0_EPKT
	PAGE_SAVE2 SCHED_MAIN2
	jmp	done?

qempty_exit?:  ;shouldn't get here if our bitmap is always consistent..
	TM_ENABLE
	clr	GRrtu.pqmap, GRrtu.pqmap, GRrtu.spare
done?:
 .endm

;=====================================
; SCHED_CHECK_DMA {{{1
; utility -> check for dma completion
;=====================================
SCHED_CHECK_DMA	.macro
; we need to decide which dma we want to check first if the both
; packer are completed together
	qbbs	$2, GRrtu.flags, f_dmau

	; dma0 was used first, so let's see if we need to clean it first
	qbbc	$1, GRrtu.flags, f_tx0_complete
	; clean DMA0
	clr	GRrtu.flags, GRrtu.flags, f_tx0_complete
	clr	GRrtu.flags, GRrtu.flags, f_dma0
	CLEANUP_TX SCHED_MAIN
$1:
	qbbc	done?, GRrtu.flags, f_tx1_complete
	; clean DMA1
	clr	GRrtu.flags, GRrtu.flags, f_tx1_complete
	clr	GRrtu.flags, GRrtu.flags, f_dma1
	CLEANUP_TX SCHED_MAIN2
	qba	done?
$2:
	; dma0 was used first, so let's see if we need to clean it first
	qbbc	$3, GRrtu.flags, f_tx1_complete
	; clean DMA1
	clr	GRrtu.flags, GRrtu.flags, f_tx1_complete
	clr	GRrtu.flags, GRrtu.flags, f_dma1
	CLEANUP_TX SCHED_MAIN2
$3:
	qbbc	done?, GRrtu.flags, f_tx0_complete
	; clean DMA0
	clr	GRrtu.flags, GRrtu.flags, f_tx0_complete
	clr	GRrtu.flags, GRrtu.flags, f_dma0
	CLEANUP_TX SCHED_MAIN

done?:
 .endm
