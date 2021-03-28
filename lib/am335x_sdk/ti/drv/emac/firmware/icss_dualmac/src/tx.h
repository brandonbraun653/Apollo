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

;-------------------------------------
;File: tx.h
;Purpose:  tx defines & macros
;--------------------------------------

;for TX_Q
; see bsram_pru.h for slot/size

;macros to end tx

;end w/ CRC
END_TX_CRC	.macro
	ldi r31.w2, 0x2c00 ; (TX_EOF + TX_CRC_HI + TX_CRC_LO)
 .endm

;#define END_TX_NOCRC  mov r31.w2, 0x2000 ; (TX_EOF )

;end w/o crc
END_TX_NOCRC	.macro
	set r31.t29;tx.eof
 .endm

;end with M-crc (ie preempt this pkt)
END_TX_MCRC	.macro
	ldi	r18, 0x80
	xout	40, &r18, 4
 .endm

;macro to start Preemptible frame TX
TX_START_PRE	.macro
	ldi	r18, 0x20;preempt  2
	xout	40, &r18, 4;set tx fifo mode (premptable, start of frame)
 .endm

;macros @start to ADDTAG (preempt/no preempt)
ADDTAG	.macro
	and r0, r18, r18
	ldi	r18, 1;bit 1 insert tag
	xout	40, &r18, 4
	and r18, r0, r0
 .endm

;macros @start to REMTAG (preempt/no preempt)
REMTAG	.macro
	and r0, r18, r18
	ldi	r18, 4;bit 2=remove
	xout	40, &r18, 4
	and r18, r0, r0
 .endm

;super macro to to start of tx frame setup
SOP_TAG_STUFF	.macro	ret_label
	qbbc	chk_rem_tag2?, TxRegs.ds_flags, 1 ;r_desc.f_desc_add_vtag
;todo: write vlan tag to insert into register
	ldi	r18, 1		;bit 1 insert tag
	xout	40, &r18, 4
	jmp ret_label
chk_rem_tag2?:
	qbbc	ret_label, TxRegs.ds_flags, 2	 ; r_desc.f_desc_rem_vtag
	ldi	r18, 4		;bit 2=remove
	xout	40, &r18, 4
 .endm

;same but for preeptible packet
SOP_TAG_STUFF_PP	.macro	r_desc, ret_label
	qbbc	chk_rem_tag2?, TxRegs.ds_flags, 1 ;r_desc.f_desc_add_vtag
;todo: write vlan tag to insert into register
	ldi	r18, 0x21	;bit 1 insert PP tag
	xout	40, &r18, 4
	jmp ret_label
chk_rem_tag2?:
	qbbc	no_tag?, TxRegs.ds_flags, 2	;r_desc.f_desc_rem_vtag
	ldi	r18, 0x24;bit 2=remove   
	xout	40, &r18, 4	; remove PP tag
	jmp ret_label
no_tag?:
	TX_START_PRE
 .endm

;-------------------------------------
;basic macro to set up TX task from BG
; v2 -> use descriptor from RTU-IPC
; !! before start of tx
; must be run in task disabled state!!
; r_d MUST BE < r10
;  note, now only d1 is needed
;------------------------------------
TX_TASK_INIT2_shell	.macro	r_d
	flip_tx_r10_r23
;do tx init
	TX_TASK_INIT2 r_d
	flip_tx_r10_r23
 .endm

;main macro to initialize TX from s&f IPC 'queue'
; r_d  holds descriptor
TX_TASK_INIT2	.macro	r_d
;temporary
	mov	TxRegs.ds_flags, r_d.w2 ;descriptor2(flags, etc)
	mov	GRegs.tx.b.len, r_d.w0  ;save length we are expecting to transmit

;start things off
;set TX fifo mode according to TX_D1 flags..  todo
 .if $isdefed("VLAN_ENABLED")
	SOP_TAG_STUFF load_fifo?
 .endif
load_fifo?:
	ldi	GRegs.tx.b.state, TX_S_ACTIVE
	TX_FILL_FIFO XFR2VBUS_XID_READ0
 .endm


FROM_DMA_TO_TXL2 .macro runit
	XFR2VBUS_WAIT4READY runit
	XFR2VBUS_READ64_RESULT runit
$1:	xin	TXL2, &r19, 4
	qbne	$1, r19.b2, 0
	xout	TXL2, &r2, 64
	.endm

LAST_DMA_TO_TXL2 .macro runit
	XFR2VBUS_WAIT4READY runit
	XFR2VBUS_CANCEL_READ_AUTO_64_CMD (runit)
	nop
	XFR2VBUS_READ64_RESULT (runit)
	BN_TX_N	GRegs.tx.b.len
	.endm
;------------------------------------
;basic macro for TX fifo filling from MSMC
; portQ
; MUST RUN from TX task register state
;---------------------------------------
TX_FILL_FIFO	.macro	runit
	.newblock
;read in data (now in r2 -r17)  [note: on eop some of this may be garbage]
	qbbs	$2, TxRegs.ds_flags, 4	 ; TxRegs.ds_flags.f_desc_read_unit
	qbge	$4, GRegs.tx.b.len, 64
	FROM_DMA_TO_TXL2 runit
	jmp	$3
$2:	qbge	$5, GRegs.tx.b.len, 64
	FROM_DMA_TO_TXL2 (runit + 1)
$3:	sub	GRegs.tx.b.len, GRegs.tx.b.len, 64
	jmp	$9

$4:	LAST_DMA_TO_TXL2 runit
	qbbc	$6, GRegs.speed_f, f_half_d ; don't tell RTU yet 
	SPIN_TOG_LOCK_LOC PRU_RTU_EOD_P_FLAG
	jmp	$6
$5:	LAST_DMA_TO_TXL2 (runit + 1)
	qbbc	$6, GRegs.speed_f, f_half_d ; don't tell RTU yet 
	SPIN_TOG_LOCK_LOC PRU_RTU_EOD_E_FLAG
$6:	;close out tx
	qbbs	$7, TxRegs.ds_flags, 0	;f_desc_do_crc
	set	r31, r31, 29		;tx.eof
	jmp	$8

$7:	or	r31.b3, r31.b3, 0x2c
$8:	ldi	GRegs.tx.b.state, TX_S_W_EOF
$9:
 .endm


