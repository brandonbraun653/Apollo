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
; TM.h:  defines and macros for TASK MANAGER engine on ICSSG
;-----------------------------------------------------------

;XIDs
TM_XID_YIELD	.set	252

;TM-related registers (offsets to TM_BASE_xxx)
TM_GLOB_CFG	.set	0x00
TM_GLOB_STAT	.set	0x04
TM_TS1_PC_S0	.set	0x08
TM_TS1_PC_S1	.set	0x0c
TM_TS1_PC_S2	.set	0x10
TM_TS1_PC_S3	.set	0x14
TM_TS1_PC_S4	.set	0x18
TM_TS2_PC_S0	.set	0x1c
TM_TS2_PC_S1	.set	0x20
TM_TS2_PC_S2	.set	0x24
TM_TS2_PC_S3	.set	0x28
TM_TS2_PC_S4	.set	0x2c
TM_RX_CFG	.set	0x30
TM_TX_CFG	.set	0x34
TM_TS1_GEN_CFG	.set	0x38
TM_TS2_GEN_CFG	.set	0x3c
TM_CAP_NEW_EN	.set	0x48

TM_DISABLE	.macro
	TSEN 0
 .endm

TM_ENABLE	.macro
	TSEN 1
 .endm

TM_YIELD	.macro
	xin	TM_XID_YIELD, &r0.b3, 1
 .endm

 .if $isdefed("SLICE0")
rx_scratch_bank .set 10
tx_scratch_bank .set 11
rtu_scratch_bank .set 10
 .else
rx_scratch_bank .set 12
tx_scratch_bank .set 13
rtu_scratch_bank .set 11
 .endif

flip_rx_r0_r23	.macro
	xchg	rx_scratch_bank, &r0, 96
 .endm

flip_tx_r0_r23	.macro
	xchg	tx_scratch_bank, &r0, 96
 .endm

flip_tx_r10_r23	.macro
	xchg	tx_scratch_bank, &r10, 56
 .endm

flip_rtu_r0_r23	.macro
	xchg	rtu_scratch_bank, &r0, 96
 .endm

TM_PRU_CONFIG	.macro 	 rpc0, rpc1,rpc2,rpc3,rpc4, tpc0, tpc1,tpc2,tpc3,tpc4
	ldi	r2, 0xff9
	sbco	&r2, c10, 0, 4
	ldi	r2, $code(rpc0)
	ldi	r3, $code(rpc1)
	ldi	r4, $code(rpc2)
	ldi	r5, $code(rpc3)
	ldi	r6, $code(rpc4)
	ldi	r7, $code(tpc0)
	ldi	r8, $code(tpc1)
	ldi	r9, $code(tpc2)
	ldi	r10, $code(tpc3)
	ldi	r11, $code(tpc4)
	sbco	&r2, c10, TM_TS1_PC_S0, 40
	ldi	r2, 0x7fff
	ldi	r3, 0x0002
	sbco	&r2, c10, TM_RX_CFG, 8
;set RX Bn to be queuable (cap_new_ts1_en_s3= bit3))
	ldi	r2, 0x8
	sbco	&r2, c10, TM_CAP_NEW_EN, 4
 .endm

CALL_SUB .macro sub_addr, return_addr
	ldi	GRrtu.ret_addr, $CODE(return_addr)
	jmp	sub_addr
 .endm

TM_RTU_CONFIG	.macro 	 rpc0,rpc1,rpc2,rpc3,rpc4,tpc0,tpc1,tpc2,tpc3,tpc4
;set up mux
	ldi	r3, 0x1f ;5->iep capture (timer tick)
 .if $isdefed("SLICE0")
	ldi32	r2, 0x50064746 ;4, 3,2,1 -> spinlock 6, spinlock 7, tx_wm, tx_ts_ready
 .else
	ldi32	r2, 0x51064948 ;4, 3,2,1 -> spinlock 8, spinlock 9, ,tx-wm, tx_ts_ready
 .endif
	ldi32	r4, 0x03020100 ;4, 3,2,1 -> rx-bn, rx-b1, rx-b0, rx-sof
	ldi	r5, 0x04;5
	sbco	&r2, c10, TM_TS1_GEN_CFG, 16

	ldi	r2, 0x12c ;hp event1 &4  l lp  events 1, 2 & 5
	sbco	&r2, c10, 0, 4

	ldi	r2, $code(rpc0)
	ldi	r3, $code(rpc1)
	ldi	r4, $code(rpc2)
	ldi	r5, $code(rpc3)
	ldi	r6, $code(rpc4)
	ldi	r7, $code(tpc0)
	ldi	r8, $code(tpc1)
	ldi	r9, $code(tpc2)
	ldi	r10, $code(tpc3)
	ldi	r11, $code(tpc4)
	sbco	&r2, c10, TM_TS1_PC_S0, 40
;prgram rx, tx cfg
	ldi	r2, 0x7fff
	ldi	r3, 0x0002
	sbco	&r2, c10, TM_RX_CFG, 8
;enable tm
	lbco	&r2, c10, 0, 4
	or	r2, r2, 0x2
	sbco	&r2, c10, 0, 4
 .endm
