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

;--------------------
; File: portq.h
;  define portq stuff
;  (in external memory)
;-------------------
;icss_g_filter version (supporting dynamic base address)
;---------------------------------------------------
ADDR_HI	.set	0x0

PQ_MAX_PKT	.set	64
PQ_MAX_PKT_RTU	.set	64
PQ_MAX_PKT_R2R	.set	32

;slots used for PORTQ Control (when portq is in DMEM)
MQ_SLOT0_PRU	.set	0x20
MQ_SLOT0_RTU	.set	0x20
MQ_SLOT0S_RTU	.set	0x28

;slots used for bpool
BP_SLOT0_PRU	.set	0x0
BP_SLOT0_RTU	.set	0x8

;----------------------MACROS--------------------
;================================
;DESCRIPTOR FORMAT
;================================
DESC_SZ	.set	12
;1st 32 bits= ptr   addr lo
;2nd 32 bits:: W0 = pkt len
;              w2 =  (b2) flags, (b3) poolid
	.asg	b2, desc_flags
	.asg	t16, f_desc_do_crc ;do crc
	.asg	t17, f_desc_add_vtag ;add tag
	.asg	t18, f_desc_rem_vtag ;remove tag
	.asg	t19, f_desc_drop ;drop this descriptor
	.asg	t20, f_desc_express ;set -> express (TBD)
	.asg	t20, f_desc_read_unit ;set by scheduler
	.asg	t21, f_tx_ts ;do tx timestamp
	.asg	t22, f_desc_slice ;0 = slice0, 1=slice1
	.asg	t23, f_desc_valid ;1=>valid
	.asg	b3, desc_poolid   ;0-23  (0-7) PRU pool, (8-15) RTU pool, (16-23) RTU shadow pool (other slice)

;-------------------------
; poolID:
;   bit 0-2 ->  priority
;-------------------------

;some shortcuts
 .if $isdefed("SLICE0")
FROM_US	.set	0x00
FROM_US_V	.set	0x80
 .else ; $isdefed("SLICE1")
FROM_US	.set	0x40
FROM_US_V	.set	0xc0
 .endif

;==============================
; MQ :: API =
;      CREATE
;      POP
;      PUSH
; Queue management stuff (head/tail, etc)
;   saved in BS RAM slot
; Queue itself in memory somewhere
;   (r_base)
; 12 bytes per entry (todo:: move to 8)
;==============================

;CREATE A MQ
; r_base= base address (LO 32)
; r_size = # entries (descriptors)
;   each entry = 3x4 bytes
	.asg	r2, mq_head
	.asg	r3, mq_tail
	.asg	r4, mq_min
	.asg	r5, mq_max
	.asg	r6.w0, mq_num
	.asg	r6.w2, mq_maxn
MQ_CREATE	.macro 	 slot, r_base,r_size
;r7/r8/r9 are spares..
;  meaning use these to hold descriptor to be pushed/popped!
	mov	r2, r_base	;head
	mov	r3, r_base	;tail
	mov	r4, r_base	;min
	lsl	r5, r_size, 3	; r5 = r_size * 8
	add	r5, r4, r5	;max
	ldi	r6.w0, 0	;# entries
	mov	r6.w2, r_size
	PAGE_SAVE2_REG slot
 .endm

;push descriptor into queue
; r_d 1st of 3 consecutive regs to hold descriptor
; r1= is qnum
MQ_PUSH	.macro 	 slot, r_d,fail_exit
	.newblock
	PAGE_RESTORE2_REG slot, 20
	qble	fail_exit, mq_num, mq_maxn
	sbbo	&r_d, mq_tail, 0, 8;costly!!
	add	mq_tail, mq_tail, 8
	qbgt	$1, mq_tail, mq_max
	mov	mq_tail, mq_min
$1:	add	mq_num, mq_num, 1
	PAGE_SAVEQ
 .endm

;same as above but assume r10 set by caller
MQ_PUSHv2	.macro 	 r_d, fail_exit
	.newblock
	xout	Q_XID, &r10.w0, 2
	xin	Q_XID, &r2, 20
	qble	fail_exit, mq_num, mq_maxn
	sbbo	&r_d, mq_tail, 0, 8;costly!!
	add	mq_tail, mq_tail, 8
	qbgt	$1, mq_tail, mq_max
	mov	mq_tail, mq_min
$1:	add	mq_num, mq_num, 1
	PAGE_SAVEQ
 .endm

;pop descriptor in r7-r9
MQ_POP	.macro 	 slot, fail_exit
	.newblock
	PAGE_RESTORE2_REG slot, 20
	qbeq	fail_exit, mq_num, 0
	lbbo	&r7, mq_head, 0, 8
	add	mq_head, mq_head, 8
	qbgt	$1, mq_head, mq_max
	mov	mq_head, mq_min
$1:	sub	mq_num, mq_num, 1
	PAGE_SAVEQ
 .endm

;PEEK descriptor in r7-r9
MQ_PEEK	.macro 	 slot, fail_exit
	PAGE_RESTORE2 slot, 20
	qbeq	fail_exit, mq_num, 0
	lbbo	&r8, mq_head, 4, 4
 .endm

	.asg	mq_num, MQ_CNT
