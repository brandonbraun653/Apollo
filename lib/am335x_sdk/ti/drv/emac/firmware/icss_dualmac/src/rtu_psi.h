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

;-------------------------------------------------
;---file: RTU_PSI.h
;---purpose:  utilities to manage PSI i/f for RTU
;---------------------------------------------------

;----------------------DEFINES------------------------

;global PSI state
	.asg	b0, ssmask  ; mask of threads that are stalled.
	.asg	b1, sactive  ; 0=thread0, 1=thread1, 2=thread2, 3=thread3
	.asg	b2, sreason  ;2bits per thread give reason for stall (valid if smask bit is clear)
	.asg	b3, qlock  ;bit n set => queue n locked

; 2 bits/thread => 4 reasons why thread is stalled
;  b2
SR_RATE	.set	0
SR_LOCK	.set	1
SR_BUF	.set	2
SR_QUEUE	.set	3

;---------------------------
; Resource Lock Utility
; QUICK Version
; just 8 bits.  no queue
;----------------------------
;init lock
QLOCK_INIT	.macro
	ldi	GRrtu.ResLock, 0
 .endm

;get a lock or get stalled
; 1 cycle no
; 3 cycles yes
QLOCK_GET	.macro	r_res, queued_label,gotit_label
	qbbs	queued_label, GRrtu.ResLock, r_res
	set	GRrtu.ResLock, GRrtu.ResLock, r_res
	jmp	gotit_label
 .endm

;poll to see if we can have  lock now
; 1 cycles
QLOCK_POLL	.macro	r_res, gotit_label
	qbbc	gotit_label, GRrtu.ResLock, r_res
 .endm

;clear a lock
; 1 cycles
QLOCK_CLR	.macro	r_res
	clr	GRrtu.ResLock, GRrtu.ResLock, r_res
 .endm

;-------Context save/restore---------------
;park a thread context, case0
PARK_THREAD0	.macro	slot, unstall_exit
	zero &r2, 32
	mov	r2, RCtx.pix0
	mov	r3, RCtx.pix1
	mov	r4, RCtx.pix2
	ldi	r9, $code(unstall_exit)
	PAGE_SAVE2_REG slot
 .endm

;park a thred context, case1
PARK_THREAD1	.macro	slot, unstall_exit
	mov	r2, RCtx.pix0
	mov	r3, RCtx.pix1
	mov	r4, RCtx.pix2
	mov	r5, RCtx.pix3
	mov	r6, RCtx.pix4
	ldi	r9, $code(unstall_exit)
	PAGE_SAVE2_REG slot
 .endm

STALL_N_PARK	.macro stall_reason, park_proc, unstall_label
	clr	GRrtu.StallMask, GRrtu.StallMask, GRrtu.ActThrdNum
	add	r11, GRrtu.ActThrdNum, PSI_CNTX0_SLOT
	ldi	r12, stall_reason
	add	r13, GRrtu.ActThrdNum, GRrtu.ActThrdNum
	lsl	r13, r13, 1
	lsl	r12, r12, r13
	or	GRrtu.StallReason, GRrtu.StallReason, r12
	park_proc	r11, unstall_label
 .endm

;-------------------------------------------
;------------GLobal PSI SM-------------------
;-------------------------------------------
;macros to poll individual psi slots
RTU_POLL_SLOTx	.macro	slot
	.newblock
$1:	xin	XID_PSI_S, &r1, 8
	qbbs	$2, r1, slot
	CALL_SUB sstate_00, $1
	jmp	$1
$2:
 .endm

;State0: read in INFO WORD
; 8 - 13 cycles..
; r2-r5 hold info data
; r1 - holds meta data
; r0 - holds expected metadata
;======================
; INFO WORD KEY DATA
; directed packet: r4.b2 (dst tag low)
; crc provided by host: r2.t23
; portq # provided by host in r4.b3 (dst tag high)
; expected length:
;======================
RTU_PSI_IN_S0	.macro	err_exit, stall_exit, mgr_exit
	.newblock
	PSI_READ	GRrtu.ActThrdNum, 20 ;read in info word
	ldi32	r0, MD_INFO0
	qbne	$5, r1, r0
	zero	&RCtx.pix0, 20

; check if the packet is management
	and	r12.b0, r2.b3, 0xf8
	qbne	$7, r12.b0, 0x80
	jmp	mgr_exit

;see if host already put crc on pkt
; todo : do we need to verify crc then on pkt
$7:	qbbc	$1, r2, 23	 ; r2.t23
	set	Ctx.ippc_flags, Ctx.ippc_flags, f_crcinpkt

$1:
	set	Ctx.ippc_forward, Ctx.ippc_forward, our_port ;to keep it local
	;//set portq
	and	Ctx.ippc_res, r4.b3, 0x07  ;ippc_res set to dst tag hi 
	mov	Ctx.ippc_totlen, r3.w0 ;check rate
 .if $isdefed("TX_RATE_LIMITER")
	mov	r3, GRrtu.ActThrdNum
	qbbc	$6, Ctx.he_flags, r3
	TXRATE_CHK_AND_SOPv2 r3, r2, Ctx.ippc_totlen, $4
 .endif
	jmp	$6
$4:	jmp	stall_exit
$5:	jmp	err_exit
$6:	; done
;rate ok
 .endm

;process in Control Word
; optional. note data already read in
;  assumes r1-r6 contains transfer
;control fields of interest
;word 0: time stam request 'cookie'
;word 1: timestamp request (bit31)
;word 2: udp chksum request
;word 3: ignore
PSI_IN_CONTROL_PROC	.macro
	.newblock
;Control  words already in r1-r5
;r2=  cookie
;r3=  b31-> tx ts
;r4=  udp cs control:  w0=#bytes, b3=loc of result (0rel), b2=start byte (0 rel)
;r5=  spare
	qbbc	$1, r3, 31	 ;no_txts
	set	Ctx.ippc_flags, Ctx.ippc_flags, f_rts
	ldi32	r10, FW_CONFIG + TX_TS_BASE
	mov	r4, r2	; we need cookie after flags
	sbbo	&r3, r10, 8, 8	; save cookie (r4) and flags (r3)
$1:
 .endm

;StateS1: read in 1st 16 data words
; looking for 1st DATA or Control
; Data in r2-r5, meta in r1
; kick of fdb lookup.  Note: we always do lookup, even for
;  directed pkt, to get vlan info
;  todo: optimization for non_vlan case: skip fdb
;
RTU_PSI_IN_S1	.macro	err_exit, control_exit
	.newblock
	PSI_READ	GRrtu.ActThrdNum, 20
	ldi32	r0, MD_CONTROL0
	qbne	$1, r1, r0
;CONTROL DATA- so Process
	PSI_IN_CONTROL_PROC
	jmp	control_exit

$1:
        ;skip  protocol info if present..
        qbeq control_exit,r1.b2, PSI_DT_PROINFO
        ;assume data...
	qbne	err_exit0?, r1.b2, 0x14

	LEBE2_5_swap_6_9   ;shift r2-r5 to r6-r9
	add	r10, GRrtu.ActThrdNum, BS_SLOT_PSI0
	PAGE_SAVEQ   ;save off
	jmp	done?
err_exit0?:  ;trampoline
	jmp	err_exit
done?:
 .endm

branch_if_eop .macro label
	qbbs	label, r1, 4	 ;r1.f_md_lastw
	qbbs	label, r1, 1	 ;r1.f_md_eop
 .endm

;hard loop to process 64 bytes from PSI
; eop_exitX:   finished w/ data
;    X=1 => r1.b3 bytes of data need servicing
;    X=2 => 16+r1.b3 bytes of data need servicing
;    X=3 => 32+r1.b3 bytes of data need servicing
;    X=4 => 48+r1.b3 bytes of data need servicing
; MACRO puts data in right order, ready to go, even for EOP
;  not going to check for errors...
RTU_PSI_READ_SR1_4	.macro	slot, done_exit, eop_exit
	.newblock
$1:	xin	XID_PSI_S, &r1, 8
	qbbc	$1, r1, GRrtu.ActThrdNum
	PSI_READS slot, 20		; Axxx
	branch_if_eop $5
	LEBE2_5_swap_6_9		; xAxx

$2:	xin	XID_PSI_S, &r1, 8
	qbbc	$2, r1, GRrtu.ActThrdNum
	PSI_READS slot, 20		; BAxx
	branch_if_eop $6
	LEBE2_9_swap_10_17		; xxAB

$3:	xin	XID_PSI_S, &r1, 8
	qbbc	$3, r1, GRrtu.ActThrdNum
	PSI_READS slot, 20		; CxAB
	LEBE2_5_swap_6_9		; xCAB
	branch_if_eop $7

$4:	xin	XID_PSI_S, &r1, 8
	qbbc	$4, r1, GRrtu.ActThrdNum
	PSI_READS slot, 20		; DCAB
	LEBE2_9_swap_10_17		; BACD
	LEBE2_5_swap_6_9		; ABCD
	branch_if_eop $8
	jmp	done_exit

$6:	LEBE2_5_swap_6_9		; ABxx
	add	r1.b3, r1.b3, 16
	jmp	eop_exit

$7:	LEBE2_9_swap_10_17		; BACx
	LEBE2_5_swap_6_9		; ABCx
	add	r1.b3, r1.b3, 32
	jmp	eop_exit
$8:
	add	r1.b3, r1.b3, 48
$5:	jmp	eop_exit
 .endm

;hard macro to process  bytes 16-63 from PSI
; (already read 1st 16)
; will pad if EOP seen
; assumption:  if psi gives us N<16 as vaild, and we read in 16, that widget
;   zeros bytes n, n+1,.. 15 (0-rel)
RTU_PSI_READ_SR2_4	.macro	slot, bslot, done_exit, eop_exit, eop_exit1
	.newblock
	zero &r2, 64
	TM_DISABLE
	PAGE_RESTORE2 bslot, 32
	TM_ENABLE
	ldi	r10, 0
;r5-r9 = 1st 16
$1:	xin	XID_PSI_S, &r1, 8
	qbbc	$1, r1, GRrtu.ActThrdNum
	PSI_READS slot, 20
	LEBE2_9_swap_10_17
	branch_if_eop	$4

$2:	xin	XID_PSI_S, &r1, 8
	qbbc	$2, r1, GRrtu.ActThrdNum
	PSI_READS slot, 20
	LEBE2_5_swap_6_9
	branch_if_eop	$5

$3:	xin	XID_PSI_S, &r1, 8
	qbbc	$3, r1, GRrtu.ActThrdNum
	PSI_READS slot, 20
	LEBE2_9_swap_10_17
	LEBE2_5_swap_6_9
	branch_if_eop	$6
	jmp done_exit

$4: ;< 32 byte packet
	LEBE2_9_swap_10_17
	LEBE2_5_swap_6_9
	ldi	r1.b3, 60
	jmp eop_exit
$5: ;only 48 byte packet
	LEBE2_9_swap_10_17
	LEBE2_5_swap_6_9
	ldi	r1.b3, 60
	jmp eop_exit
$6:
;all should be lined up
	add	r1.b3, r1.b3, 48
	qble	eop_exit1, r1.b3, 60
	ldi	r1.b3, 60
	jmp eop_exit
 .endm

;
;Process fdb result to decide how to forward (part2)
;  r2 = xxMASK
RTU_PSI_IN_F0_PART2	.macro	stall_exit_lock,stall_exit_buf
	.newblock
;now allocate buffer(s)
;get a lock on the queue/buffer pools
	QLOCK_GET	Ctx.ippc_res, $1, $2
$1:	jmp	stall_exit_lock  ;can't get lock
$2:	;lock_ok
	add	r1, Ctx.ippc_res, BP_SLOT0_RTU
        CEIL64	r11.w2, Ctx.ippc_totlen
	TM_DISABLE
	BUFP_POP	r1, r11.w2, Ctx.ippx_ptr0, $3
	TM_ENABLE
	jmp	$9
$3:	;no_buffer0
	TM_ENABLE
	jmp	stall_exit_buf
$9: ; done
 .endm

;write 64 bytes to one or both portq buffers
;ADDR_LO needs to be set (r18) to r_pix3, rpix_4
; aslo sets r19 to ADDR_HI
; could be 15 cycles if 2x writes
DO_WRITE64	.macro	unit, len
	.newblock
	LEBE_GO	r2, 64	;NEED_TO_FLIP
	ldi	r19, ADDR_HI
	add	r18, Ctx.ippx_ptr0, Ctx.ippc_curlen
	xout	unit, &r2, 64 + 8
	add	Ctx.ippc_curlen, Ctx.ippc_curlen, len
 .endm

;build descriptor
;push descriptor onto port queue(s)
DO_EOP	.macro	stall_exit
;build common parts of descriptor
	mov	r8.w0, Ctx.ippc_curlen        ;len
	ldi	r8.b2, FROM_US_V
	qbbs	no_crc?, Ctx.ippc_flags, f_crcinpkt
	set	r8.t16 ;force tx to get hw to do crc
no_crc?:
	add	r8.b3, Ctx.ippc_res, BP_SLOT0_RTU ;b2 is 0-7.  add RTU_BASE
	qbbc	no_tx_ts?, Ctx.ippc_flags, f_rts
	set	r8.t21
no_tx_ts?:
	mov	r7, Ctx.ippx_ptr0  ;ptr
	add	r2, Ctx.ippc_res, MQ_SLOT0_RTU ;queue
	TM_DISABLE
	MQ_PUSH	r2, r7, fail?
	add	r2, Ctx.ippc_res, TX_QUEUE_CNT
	sbco	&r2, c9, PA_STAT_R, 1
	set	GRrtu.pqmap, GRrtu.pqmap, Ctx.ippc_res
	TM_ENABLE
	jmp	done?
fail?:
	TM_ENABLE
	jmp	stall_exit

done?:  QLOCK_CLR Ctx.ippc_res ; success - release lock on queue/resources
 .endm

;wait for EOP on thread, tossing data
WAIT_EOP	.macro
	.newblock
	qbeq	$0, GRrtu.ActThrdNum, 0
	qbeq	$1, GRrtu.ActThrdNum, 1
	qbeq	$2, GRrtu.ActThrdNum, 2
$3
	RTU_POLL_SLOTx	3
	PSI_READS XID_PSI_R4, 20
	qbbc	$3, r1, 1	 ;r1.f_md_eop
	jmp	$4
$2:
	RTU_POLL_SLOTx	2
	PSI_READS XID_PSI_R3, 20
	qbbc	$2, r1, 1	 ;r1.f_md_eop
	jmp	$4
$1:
	RTU_POLL_SLOTx	1
	PSI_READS XID_PSI_R2, 20
	qbbc	$1, r1, 1	 ;r1.f_md_eop
	jmp	$4
$0:
	RTU_POLL_SLOTx	0
	PSI_READS XID_PSI_R1, 20
	qbbc	$0, r1, 1	 ;r1.f_md_eop
$4:
 .endm

;UNSTALL a thread
; note: if can unstall, r9 from restored context has where to
; r0.b0 clobbered
TRY_UNSTALL	.macro	thr, bs_slot, fail_exit
	.newblock
;restore state for this thread
	TM_DISABLE
	PAGE_RESTORE2_REG bs_slot, 32
	TM_ENABLE
	lsl	r0.b1, thr, 2
	lsr	r0.b0, GRrtu.StallReason, r0.b1
	and	r0.b0, r0.b0, 0x3
	qbeq	try_us_rate?, r0.b0, SR_RATE
	qbeq	try_us_res?, r0.b0, SR_LOCK
	qbeq	try_us_buf?, r0.b0, SR_BUF
	qbne	fail_exit0?, r0.b0, SR_QUEUE

;Stalled because portQ (or IPC Q) was full
;try to unstall queue block (one or both qpushes failed)
; simply jump to r9 (this will retry DO_EOP macro to close out pkt)
try_us_q?:
	mov	RCtx.pix0, r2
	mov	RCtx.pix1, r3
	mov	RCtx.pix2, r4
	mov	RCtx.pix3, r4
	mov	RCtx.pix4, r5
	set	GRrtu.StallMask, GRrtu.StallMask, thr
	mov	GRrtu.ActThrdNum, thr
	jmp	r9

;Stalled because of rate limiter
;so see if we have credits now
try_us_rate?:
	mov	r18, thr
	TXRATE_CHK_AND_SOPV2	r18, r1, r2.w2, fail_exit0?
;can unstall
	set	GRrtu.StallMask, GRrtu.StallMask, thr
	mov	GRrtu.ActThrdNum, thr
	mov	RCtx.pix0, r2
	mov	RCtx.pix1, r3
	mov	RCtx.pix2, r4
	jmp	r9
fail_exit0?:  jmp fail_exit ;trampoline

;Stalled because resource locked
;so try and get lock for resource
try_us_res?:
	QLOCK_POLL	r3.b2, isuccess_exit1?
	jmp fail_exit
isuccess_exit1?:
;can unstall thread
	mov	RCtx.pix0, r2
	mov	RCtx.pix1, r3
	mov	RCtx.pix2, r4
	set	GRrtu.StallMask, GRrtu.StallMask, thr
	mov	GRrtu.ActThrdNum, thr
	jmp	r9

;stalled becausec couldn't get buffer(s)
;so try and get buffers
try_us_buf?:
	TM_DISABLE
	PAGE_RESTORE2_REG bs_slot, 32
	TM_ENABLE
	mov	RCtx.pix0, r2
	mov	RCtx.pix1, r3
	mov	RCtx.pix2, r4
	mov	RCtx.pix3, r5
	mov	RCtx.pix4, r6
;see if we need local pool
	add	r1, Ctx.ippc_res, BP_SLOT0_RTU
        CEIL64	r11.w2,Ctx.ippc_totlen
	TM_DISABLE
	BUFP_POP	r1, r11.w2, Ctx.ippx_ptr0, no_buffer0?
	TM_ENABLE
;success
	set	GRrtu.StallMask, GRrtu.StallMask, thr
	mov	GRrtu.ActThrdNum, thr
	jmp	r9

no_buffer0?:
	TM_ENABLE
	jmp fail_exit
 .endm

MGR_SHUTDOWN	.macro
	.newblock
; signal PRU we are going to stop
	ldi32	r0, FW_CONFIG
	ldi32	r1, RTU_STARTED_SHUTDOWN
	sbbo	&r1, r0, CFG_RTU_STATUS, 4
; compete all ongoing PSI-L transfers
$1:	ldi	r7, 125		; set 1 usec timeout
$2:	xin	XID_PSI_S, &r1, 8
	mov	r6, r1		; save status at r6
	and	r6, r6, 0xf	;
	qbne	$3, r6, 0	; we have active data
	sub	r7, r7, 1	;
	qbne	$2, r7, 0	;
	jmp	$7		; timeout

$3	qbbc	$4, r6, 0	; read chunks from all threads if any
	PSI_READS XID_PSI_R1, 20
$4:	qbbc	$5, r6, 1
	PSI_READS XID_PSI_R2, 20
$5:	qbbc	$6, r6, 2
	PSI_READS XID_PSI_R3, 20
$6:	qbbc	$1, r6, 3
	PSI_READS XID_PSI_R4, 20
	jmp	$1

; we don't care if TX queue is not empty. We are going to restart firmware anyways
; and reinitialize all buffers and queues  

; wait for PRU complete
$7:	ldi32	r0, FW_CONFIG
	ldi32	r1, PRU_STOPPED
$8:	add	r0, r0, 0
	lbbo	&r9, r0, CFG_STATUS, 4
	qbne	$8, r9, r1
 .endm
