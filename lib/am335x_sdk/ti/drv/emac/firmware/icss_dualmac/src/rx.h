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

;------------------------------
;File rx.h
; RX State Machine, Macros, etc
;--------------------------------

RX_STATE_IDLE	.set	0
RX_STATE_ACTIVE	.set	1
RX_STATE_PTP	.set	2
;various special states can go here.. (e.g. profinetRT, .. )
RX_STATE_SPECIAL1	.set	3
RX_STATE_SPECIAL2	.set	4
RX_STATE_RV	.set	0x70
RX_STATE_OVER0	.set	0x7e
RX_STATE_DROP	.set	0x7f;dropping

;for PRU
	.asg	w2, rx_pkt_len
;for RTU
	.asg	w2, rx_extra
	.asg	b2, rx_rex_flags  ;flags
	.asg	t16, f_rex_stash ;stashed info
;these should match IPC p2rch0
	.asg	t18, f_rex_rpkt ;R pkt received
	.asg	t19, f_rex_vpkt ;V pkt received
	.asg	t20, f_rex_err ;err w/ previous
	.asg	t21, f_rex_pre ;preemptible pkt start
	.asg	t22, f_rex_frag ;fragment start
	.asg	b3, rx_ex_fc ;frag cnt

;for rxQ info, see bsram_pru.h
RB1_STALL_LIMIT  .set 0x40   ;may have to tune, but this is how long to stall in rxb1 task

 .if $isdefed("SLICE0")
FDB_LEARN_INFO	.set	0xca

 .endif
 .if $isdefed("SLICE1")

FDB_LEARN_INFO	.set	0xcc
 .endif

;address learn work item
; uses ADDR_LEARN_SLOT in BS RAM
	.asg	r2, AL_VALID
	.asg	r3, AL_ADDR3  ;r3 from block0
	.asg	r4, AL_ADDR4  ;r4 from packet
	.asg	r5, AL_FID_INFO   ;matches r10 returned from fdb lookup
	.asg	r6, AL_SLOT   ;matches r11 returned from fdb lookup

;rx state_info (R_STATE_INFO)
;RTU version:
	.asg	t0, f_rps_tx0  ;set if host port is fwd
	.asg	t1, f_rps_tx1  ;set if port 1 is fwd
	.asg	t2, f_rps_tx2  ;set if port 2 is fwd
	.asg	t3, f_rps_rxf  ;set if this rx is forward (clr => blocked)
	.asg	t4, f_rps_lc  ;learn control: set if we can learn on this port
;2 spare bits
	.asg	t7, f_rps_rxd  ;set if rxport is disabled
;PRU version:  just hold rx state 0-3

;set up rx task state info
; -> def flow
; -> flags
; -> port state (RX)
RX_TASK_INIT_RTU	.macro 	 r_flags, r_deflow,r_ports
        ;zap the SPAD
	ldi	r0.b0, 0
	flip_rtu_r0_r23
        zero &r0,(24*4)
	flip_rtu_r0_r23
        ;save rx settings
	mov	R_RX_STATE_INFO.w0, r_deflow.w0
	mov	R_RX_STATE_INFO.b2, r_flags.b0
	mov	R_RX_STATE_INFO.b3, r_ports.b0
	ldi	r0, 0
;load it into scratchpad
 .if $isdefed("SLICE0")
	xout	10, &R_RX_STATE_INFO, 4
 .else
	xout	11, &R_RX_STATE_INFO, 4
 .endif
 .endm

;pru version
RX_TASK_INIT	.macro
	flip_rx_r0_r23
        zero &r0, (24 * 4)
	PAGE_RESTORE GSTATE, 32
	ldi32	r0, FW_CONFIG
	lbbo	&r1, r0, CFG_DEF_FLOW, 4
	mov	RxRegs.def_flow, r1

	ldi	RxRegs.state_flags, 0
	ldi	RxRegs.vlanc, 0
	flip_rx_r0_r23
 .endm

