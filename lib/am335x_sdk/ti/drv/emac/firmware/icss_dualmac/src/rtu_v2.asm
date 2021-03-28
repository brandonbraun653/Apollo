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

;Test Code for  RTU {{{1
;  2nd version
;  functions:
;    TM2 tasks:  mirror rx tasks on pRU
;    TM1 tasks:  scheduler tick, ipc from PRU, ipc from other RTU, txl2 events
;    BG task:  spin on  PSI READ Status, and pull in packet from PSI and send to PORTQ in external memory
;              add descriptor to portQ or push descriptor to other RTU
; scheduler: run mostly in sched_tick
RX_RAW	.set	1
; includes {{{1
 .include "regs.h"
 .include "smem.h"
 .include "spin.h"
 .include "xfr2vbus_widget.h"
 .include "xfr2psi_widget.h"
 .include "tm.h"
 .include "bsram_rtu.h"
 .include "reg_alias.h"
 .include "rx.h"
 .include "tx.h"
 .include "portq.h"
 .include "lebe.h"
 .include "bpool.h"
 .include "hd_helper.h"
 .include "scheduler.h"
 .include "ipc.h"
 .include "filter.h"
 .include "classi.h"
 .include "txrate.h"
 .include "rtu_psi.h"
 .include "iep.h"
 .include "pa_stat.h"

loop_here .macro
here?:	jmp	here?
	.endm

wait4pru_ready .macro
	.newblock
	ldi32	r1, PRU_READY
	ldi32	r0, FW_CONFIG
$1:	add	r0, r0, 0
	add	r0, r0, 0
	add	r0, r0, 0
	lbbo	&r9, r0, CFG_STATUS, 4
	qbne	$1, r9, r1

	ldi32	r2, RTU_READY
	sbbo	&r2, r0, CFG_RTU_STATUS, 4
 .endm

; r8 - starting address, r12 - address of the 1st pull size
create_8_buff_pools .macro starting_slot
	.newblock
	ldi	r13, 0
	ldi	r14, starting_slot
$1:	lbbo	&r9, r12, 0, 4
	BUFP_CREATE	r14, r8, r9
	add	r8, r8, r9
	add	r8, r8, 128
	add	r13, r13, 1
	add	r14, r14, 1
	add	r12, r12, 4
	qbgt	$1, r13, 8
 .endm

;buffps for Ethernet pkts from wire
create_all_buff_pools .macro
	mov	r8, r18 ; start from the beginning of the buffer memory
;buffps for PSI pkts for this slice
	ldi32	r12, FW_CONFIG + CFG_TX_BS_8
	create_8_buff_pools	BP_SLOT0_RTU
 .endm

create_port_queues .macro
	.newblock
;create portQs :: 8 for this slice and 8 shadow for other slice)
	ldi	r13, 0
	ldi	r14, MQ_SLOT0_RTU
	ldi32	r0, MQBASE_START
	ldi	r1, PQ_MAX_PKT_RTU
$1:	MQ_CREATE	r14, r0, r1
	mov	r0, r5
	add	r14, r14, 1
	add	r13, r13, 1
	qbge	$1, r13, 8

 .endm
 ; Code starts {{{1
 .retain     ; Required for building .out with assembly file
 .retainrefs ; Required for building .out with assembly file
 .sect    ".text:Start"
 .global  Start

Start:
	TM_DISABLE
	zero	&r0, 124
	ldi	r11, 1
	 ;	rtu err counter: b0 = RXdropPsi (widget full), b1=RXdropErr, b2=TXstall, b3= txError
	ldi	r30,0
 .if $isdefed("WAIT_FOR_DEBUGGER")
	mov	r11, 0
 .endif
start_test:
	qbeq	start_test, r11, 0

;	SP_SHIFT_ENABLE
;one time initialization
	wait4pru_ready
; r0 has FW_CONFIG from previouse macro
	lbbo	&r5, r0, CFG_DEF_FLOW, 8 ; r5 - flow, r6 - flags
	lbbo	&r3, r0, CFG_ADDR_LO, 8;

;r3=addrlo, r4=addrhi (not used. todo check against #define and barf)
;r5 = flow
;r6 = flags
;r7 = portstate (RX) VA - we don't have it anymore
;save def flow & flags
;port state conversion to something useful

	ldi	r0, 0
;default:   (3)= fwd plus learn
	set	r0.t3 ;fwd
	set	r0.t4 ;lrn
;hostport tbd

 .if $isdefed ("VLAN_ENABLED")
	set	r6.t0
 .endif
	mov	r7, r0
	RX_TASK_INIT_RTU	r6, r5, r7

	add	r18, r3, 0x80	;skip 128 bytes ..
	mov	r19, r4
	PAGE_SAVE	RTU_GSTATE

	create_all_buff_pools
	create_port_queues

;set up PSI INFO, CONTROL, STATUS TEMPLATES
 .if $isdefed("SLICE0")
	PSI_SETUP_INFO	PSI_INFO_SLOT, 1
 .else
	PSI_SETUP_INFO	PSI_INFO_SLOT, 2
 .endif
	PSI_SETUP_MGR_INFO
	PSI_SETUP_STATUS	PSI_STATUS_SLOT

;initialize txrate limiters for each thread
	ldi	r2, 0
	TXRATE_INIT	0, r1, r2
	TXRATE_INIT	1, r1, r2
	TXRATE_INIT	2, r1, r2
	TXRATE_INIT	3, r1, r2

;setup taskmanager
	TM_RTU_CONFIG	TX_EOD_P, TX_EOD_E, TM_NOP, TX_EOF, TM_NOP, TM_NOP, rtu_rx_task2, TM_NOP, TM_NOP, TM_NOP
	TM_ENABLE

;set up IEP - assume this only needs to get done once
	ENABLE_IEP	IEP_BASEx

;we READY FOR NEW PACKET
	zero	&Ctx, 20	;now set ingress context

;---------------start test------------ {{{1
;init scheduler
	zero	&GRrtu.pqmap, 4
	ldi	GRrtu.qmask, NORM_QMASK	;look at all queues

;intialize PS global state
	ldi	GRrtu.StallMask, 0xf	;no stalls
	QLOCK_INIT	;clear resource lock
	ldi	GRrtu.ActThrdNum, 0	;nothing active
	ldi	GRrtu.StallReason, 0	;no stall reason

;-------------------------------
; RTU BG LOOP	{{{1
;-------------------------------
bg_loop:

;start of psi host egress handler
;-------------------------------------------------------------
; psi is Idle, meaning we aren't actively bring in data from a
; PSI thread.  But we may be stalled
;-------------------------------------------------------------
psi_idle:
	xin	XID_PSI_S, &r1, 8
	and	r1.b0, r1.b0, GRrtu.StallMask
	qbeq	no_psi, r1.b0, 0

	qbbc	$1, r1, 0
	ldi	GRrtu.ActThrdNum, 0x0
	and	GRrtu.StallReason, GRrtu.StallReason, 0xfc
	jmp	start_psi

$1:	qbbc	$2, r1, 1
	ldi	GRrtu.ActThrdNum, 1
	and	GRrtu.StallReason, GRrtu.StallReason, 0xf3
	jmp	start_psi

$2:	qbbc	$3, r1, 2
	ldi	GRrtu.ActThrdNum, 2
	and	GRrtu.StallReason, GRrtu.StallReason, 0xcf
	jmp	start_psi

$3:	qbbc	no_psi, r1, 3
	ldi	GRrtu.ActThrdNum, 3
	and	GRrtu.StallReason, GRrtu.StallReason, 0x3f
	jmp	start_psi

no_psi: jmp psi_idle2
psi_idle3:
	CALL_SUB	sstate_00, psi_idle
	jmp	psi_idle

;---------------------------------------
;PSI is idle but we may have stalled threads
;---------------------------------------
psi_idle2:
;see if we can unstall anyone
	qbeq	psi_idle3, GRrtu.StallMask, 0x0f

;make sure r16, r17 dont get stomped on!!!
	ldi	r16, 0
	ldi	r17, PSI_CNTX0_SLOT
unstall_loop:
	qbbs	skipu, GRrtu.StallMask, r16
	TRY_UNSTALL	r16, r17, skipu
skipu:
	add	r16, r16, 1
	add	r17, r17, 1
	qbgt	unstall_loop, r16, 4
	jmp	psi_idle3

mgr_pkt:
	RTU_POLL_SLOTx	GRrtu.ActThrdNum
	PSI_READ	GRrtu.ActThrdNum, 20
	ldi32	r0, MD_CONTROL0
	qbeq	mgr_pkt, r1, r0
	ldi32	r0, MD_PROINFO
	qbeq	mgr_pkt, r1, r0
	qbne	mgr_pkt01, r1.b2, 0x14;
	; we have 16 bytes of packet now
	; process mgr data
	LEBE_GO	r2, 16
	qbne	mgr_pkt01, r2.b3, 0x81	; not a management packet
	mov	GRrtu.seq_num, r2.b1	; save seq_num
	qbne	mgr_pkt10, r2.b2, 0x01	; shutdown command
	MGR_SHUTDOWN
	ldi32	r2, 0x81010001	; response OK
	mov	r2.b1, GRrtu.seq_num
	TM_DISABLE
	SEND_MGR_PKT
	ldi32	r0, FW_CONFIG
	ldi32	r1, RTU_STOPPED
	sbbo	&r1, r0, CFG_RTU_STATUS, 4
	loop_here

mgr_pkt10:
	qbne	mgr_pkt20, r2.b2, 0x02	; set port state
	ldi32	r0, FW_CONFIG
	sbbo	&r2, r0, CMD_PARAM, 4   ; store the command to smem
	ldi32	r1, RTU_SETPORT
	sbbo	&r1, r0, CFG_RTU_STATUS, 4; tell PRU about the command
	; usually CFG_RTU_STATUS can be updated by RTU only, but
	; we don't want pru to execute the command in endless loop.
	; so pru updates CFG_RTU_STATUS status when it has finished the
	; command
	ldi32	r1, PRU_DONE
mgr_pkt11:
	add	r0, r0, 0	; nop
	lbbo	&r9, r0, CFG_RTU_STATUS, 4
	qbne	mgr_pkt11, r9, r1
	ldi32	r9, RTU_READY
	sbbo	&r9, r0, CFG_RTU_STATUS, 4
	; pru is done, lets update speed_f on rtu
 .if $isdefed("SLICE0")
	and	r2.b0, r2.b0, 0x0e
	and	GRrtu.speed_f, GRrtu.speed_f, 0xf1
 .else
	lsl	r2.b0, r2.b0, 4
	and	r2.b0, r2.b0, 0xe0
	and	GRrtu.speed_f, GRrtu.speed_f, 0x1f
 .endif
	or	GRrtu.speed_f, GRrtu.speed_f, r2.b0
	; OK, tell host we are done
	ldi32	r2, 0x81020001	; response OK
	mov	r2.b1, GRrtu.seq_num
	SEND_MGR_PKT
	jmp	mgr_pkt02

mgr_pkt20:

mgr_unknown:
	ldi	r2.b0, 0x10
	mov	r2.b1, GRrtu.seq_num
	SEND_MGR_PKT
	jmp	psi_idle

mgr_pkt01:
	branch_if_eop	mgr_pkt02
	WAIT_EOP
mgr_pkt02:
	jmp	psi_idle

;-------------------------
; process active thread
; GRrtu.ActThrdNum  = bit of active thread set
; GRrtu.StallMask   = cleared bits => stalled threads
; GRrtu.StallReason = reason for stalled threads
; GRrtu.ResLock     = resource locks taken
;------------------------
start_psi:
;S0: read in INFO
	RTU_PSI_IN_S0	err_exit00, stall_exit00, mgr_pkt
unstall00:

;S1: wait for 1st DATA or control
wait_1stdata0:
	RTU_POLL_SLOTx	GRrtu.ActThrdNum
	RTU_PSI_IN_S1	err_exit01, wait_1stdata0
	CALL_SUB	sstate_00, wait_fdb_done0

;F0: wait for FDB result
;todo: optimizaton: bring in next 2x16 while fdb in progress
wait_fdb_done0:
unstall01:
	RTU_PSI_IN_F0_PART2	stall_exit01, stall_exit02
unstall02:
;r2, 3, 4 wait for remaining 3x16B
	qbeq	sr20, GRrtu.ActThrdNum, 0
	qbeq	sr21, GRrtu.ActThrdNum, 1
	qbeq	sr22, GRrtu.ActThrdNum, 2
	RTU_PSI_READ_SR2_4	XID_PSI_R4, BS_SLOT_PSI3, loop_psi0_0, eop_exit00, eop_exit01
sr22:	RTU_PSI_READ_SR2_4	XID_PSI_R3, BS_SLOT_PSI2, loop_psi0_0, eop_exit00, eop_exit01
sr21:	RTU_PSI_READ_SR2_4	XID_PSI_R2, BS_SLOT_PSI1, loop_psi0_0, eop_exit00, eop_exit01
sr20:	RTU_PSI_READ_SR2_4	XID_PSI_R1, BS_SLOT_PSI0, loop_psi0_0, eop_exit00, eop_exit01

loop_psi0_0:
	DO_WRITE64	XFR2VBUS_XID_WRITE1, 64
	CALL_SUB	sstate_00, loop_psi1_0

;r1, 2, 3, 4 wait for 4x 16Byte chunks;
loop_psi1_0:
	qbeq	sr40, GRrtu.ActThrdNum, 0
	qbeq	sr41, GRrtu.ActThrdNum, 1
	qbeq	sr42, GRrtu.ActThrdNum, 2
	RTU_PSI_READ_SR1_4	XID_PSI_R4, loop_psi2_0, eop_exit02
sr42:	RTU_PSI_READ_SR1_4	XID_PSI_R3, loop_psi2_0, eop_exit02
sr41:	RTU_PSI_READ_SR1_4	XID_PSI_R2, loop_psi2_0, eop_exit02
sr40:	RTU_PSI_READ_SR1_4	XID_PSI_R1, loop_psi2_0, eop_exit02

loop_psi2_0:
	DO_WRITE64	XFR2VBUS_XID_WRITE1, 64
	CALL_SUB	sstate_00, loop_psi1_0
	jmp	loop_psi1_0

;SPECIAL CASES FOR THREADs
;stall cases.  Processing for this thread is stalled
; park context, set b0 to ignore this thread
; (when parking context, label where to restart thread is saved)
stall_exit03: ;stall due to no room in queue
	STALL_N_PARK	SR_QUEUE, PARK_THREAD1, unstall03
	add	r30.b2, r30.b2, 1
	jmp	psi_idle2

stall_exit02: ;stall due to no buffer
	STALL_N_PARK	SR_BUF, PARK_THREAD1, unstall02
	add	r30.b2, r30.b2, 1
	jmp	psi_idle2

stall_exit01: ; STALL on resource lock
	STALL_N_PARK	SR_LOCK, PARK_THREAD0, unstall01
	add	r30.b2, r30.b2, 1
	jmp	psi_idle2

stall_exit00: ;stalled due to rate limiter
	clr	GRrtu.StallMask, GRrtu.StallMask, GRrtu.ActThrdNum
;stall reason is 0 (default)
	add	r11, GRrtu.ActThrdNum, PSI_CNTX0_SLOT
	PARK_THREAD0	r11, unstall00
	add	r30.b2, r30.b2, 1
	jmp	psi_idle2

;--------------------
;EOP exits
;-------------------
;less<64 pkt seen
;special case: len=60, 61, 62, 63
eop_exit00:
eop_exit01:
	qbbc	dow, r1, 1	 ;r1.f_md_eop
	set	Ctx.ippc_flags, Ctx.ippc_flags, f_eop
dow:
	DO_WRITE64	XFR2VBUS_XID_WRITE1, r1.b3
;todo clear crc included bit (cause it couldn't have been)
	jmp	do_eop00

;normal sized packet exit
eop_exit02:
	qbbc	dow2, r1, 1	 ;r1.f_md_eop
	set	Ctx.ippc_flags, Ctx.ippc_flags, f_eop
dow2:
;todo check if crc included or not. if it is then r1.b3 better be >=64
	DO_WRITE64	XFR2VBUS_XID_WRITE1, r1.b3

;do eop processing for pkt (i.e. post it to portQ and/or IPCQ) {{{2
do_eop00:
unstall03:
	DO_EOP	stall_exit03

;last thing to do is wait for EOP
	qbbc	weop, Ctx.ippc_flags, f_eop
	jmp	psi_idle2
weop:
	WAIT_EOP
	jmp	psi_idle2

err_exit00:
	qbbs	err_exit, r1, 1	; don't do anything if eop already set

	;ERROR: Drop pkt. Note: won't service PSI unti we eop on this thread
err_exit01:	;some kind of error..  for now just toss until EOP
	WAIT_EOP
	add	r30.b2, r30.b2, 1
err_exit:
	jmp	psi_idle
;end of psi host egress

	loop_here
;----------------TASK HANDLERS----------------------
;--------------------------------------------------------------
; RX TASK2 (SOF HELPER) - HIGHEST PRIORITY TASK and MUST HAPPEN {{{1
;----------------------
rtu_rx_task2:
	mov	GRrtu.save1, r0.b0
	ldi	r0.b0, 0
	flip_rtu_r0_r23
	ldi	R_RX_STATE, 0x180

;read filter. clobbers r10-12. copy r11, r2 into scratch3, 4
	FILTER_GET_ALL	;blasts into r10-r17
	mov	R_BASIC_F, r11    ;move basic filter results to somewhere safe
	;see	if "to-host" classifier says take it
	TOHOST_OK	R_CLASSI, try_to_host
	;use	classifiers to determine  psi flow
	and	r0.b0, R_CLASSI.b2, CLASSI_FMASK
	lmbd	R_PSI_FLAGS.w0, r0.b0, 1
	ldi	R_RX_STATE.b0, 0x81 ;rx_flags
try_to_host:
	qbbc	rx_task2_done, R_RX_STATE, f_tohost
;PSI flow.  for mac we did earlier
send_info:
	qblt	send_info1, R_PSI_FLAGS.w0, 15 ;
	add	R_PSI_FLAGS.w0, R_PSI_FLAGS.w0, R_RX_STATE_INFO.w0
	jmp	rx_task2_done
send_info1:
	ldi	R_PSI_FLAGS.w0, 0x3fff ;
;todo -> set from filter results (IPv4, v6, udp, tcp)
rx_task2_done:

;send forwarding info to PRU. he will pick it up at start of RX_Block1
; THIS MUST HAPPEN!! ELSE PKT DROPPED In RTU
	mov	r5, R_RX_STATE
	mov	r6, R_PSI_FLAGS ;send flow over
	RTU_IPC_TX_CH1
;read the rxtimestamp
	qbbc	rx_task2_done2, R_RX_STATE, f_tohost
	GET_PKT_RX_TS	R_TS_HI	;note classi clobbered here
	ldi32	r5, FW_CONFIG + RX_TS_BASE
	sbbo	&R_TS_HI, r5, 0, 8

rx_task2_done2:
	ldi	r0.b0, 0
	TM_YIELD
;caution: 2 instr after yield are done in delayed-branch fashion
	flip_rtu_r0_r23
	mov	r0.b0, GRrtu.save1
	loop_here
;========END RX_TASK2==============

TX_EOF: TM_YIELD
	set	GRrtu.flags, GRrtu.flags, f_tstx_ready
	loop_here

TX_EOD_P: TM_YIELD
	set	GRrtu.flags, GRrtu.flags, f_tx0_complete
	loop_here

TX_EOD_E: TM_YIELD
	set	GRrtu.flags, GRrtu.flags, f_tx1_complete
	loop_here

TM_NOP:	TM_YIELD
	loop_here
;-----------------------
;sched co-routine
;-----------------------
sstate_00:
	STATE_00_EP
	jmp	GRrtu.ret_addr


 .include "resource_table.h"

