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
;--------------------------------------------------
; FILE: bpool.h
; Purpose:  experimental buffer pool alloc, free
; fw implementations available
;---------------------------------------------------

MAX_PKT	.set	0x800

; macros for buffer management
;buffer pool alloc/free.
; assume a circular buffer with bp_head, bp_tail, bp_base,and bp_max ptrs stored somewhere
; assumes buffers are freed in order of alloc.
;    => implies dedicated pool per queue
;  assume length is in proper allocate units (eg 64 bytes)
;    => descriptor or fw has to keep real length & allocate length
; buffer allocated will be linear!!
;  will check for no room on pop and return 0
;
;bp_base = start of pool
;bp_head = address where free area starts
;bp_tail = address where allocated area starts.  bp_head=bp_tail => all available
;bp_max = end of pool
;pool definition assumed to be r2-r5, with r6-r9 available as scratch
; eg xin these from bs  (1 or 2 pools per slot)
; Note: there are two kinds of pools: trimmable (for pkts from wire) and
;  non-trimmable (for pkts from host).
;  fw version set up for non-trimmable => Dual MAc only. Switch won't be correct
;  (affects push (=free) function buffer wrap logic)
;
	.asg	r2, bp_base
	.asg	r3, bp_head
	.asg	r4, bp_tail
	.asg	r5, bp_max
	.asg	r6, bp_s0
	.asg	r7, bp_s1
	.asg	r8, bp_s2
	.asg	r9, bp_s3

;--------------------------
; round length to 64 bytes
;--------------------------
CEIL64	.macro	r_dest, r_len
	add r_dest, r_len, 63
	lsr r_dest, r_dest, 6
	lsl r_dest, r_dest, 6
 .endm

;--------------------
;create a buffer pool
;--------------------
BUFP_CREATE	.macro	slot, r_base, r_size
	mov	bp_base, r_base
	mov	bp_head, r_base
	mov	bp_tail, r_base
	add	bp_max, bp_base, r_size
	PAGE_SAVE_REG slot
 .endm

;-------------------
;alloc buffer bytes
; len == multiple of 64!
; ~ 8 cycles
;------------------
BUFP_POP	.macro	slot, r_len, r_res, no_buf_label
	PAGE_RESTORE2_REG slot, 20
	qbge	h_ge_tail?, bp_tail, bp_head
;bp_head less than bp_tail.
	sub	bp_s0, bp_tail, bp_head
	qblt	len_lt_fs3?, bp_s0, r_len
	jmp no_buf_label

h_ge_tail?:
	sub	bp_s0, bp_max, bp_head
	qble	len_le_fs?, bp_s0, r_len
;won't fit w/o wrapping, so restart from base
	sub	bp_s0, bp_tail, bp_base
	qblt	len_lt_fs2?, bp_s0, r_len
	jmp no_buf_label

len_lt_fs2?:
	mov	bp_head, bp_base
len_lt_fs3?:
len_le_fs?:
	mov	r_res, bp_head
	add	bp_head, bp_head, r_len
done?:
	PAGE_SAVEQ
 .endm

;free buffer bytes
; ~ 6-7 cycles
; - len must be multiple of 64
BUFP_PUSH	.macro	slot, r_len
; setup for non-trimmable.
; (for trimmable, would need to check rollover against MAX_PKT
;	ldi	r1, MAX_PKT
	PAGE_RESTORE2_REG slot, 20
	sub	bp_s0, bp_max, bp_tail
	qble	s_le_m_minus_t?, bp_s0, r_len
	add	bp_tail, bp_base, r_len
	jmp	done?
s_le_m_minus_t?:
	add	bp_tail, bp_tail, r_len
done?:
	PAGE_SAVEQ
 .endm

; trim the previous pop
;  5 cycle
BUFP_TRIM	.macro	slot, r_len
	PAGE_RESTORE2_REG slot, 20
;just move bp_head back r_len bytes
	sub	bp_head, bp_head, r_len
	PAGE_SAVEQ
 .endm

;
;see how much space is available
BUFP_CHECKFW	.macro	slot, r_res, r_len
	PAGE_RESTORE2 slot, 20
	ldi r_res, 1
	qbge	h_ge_tail?, bp_tail, bp_head
;bp_head less than bp_tail.

	sub	bp_s0, bp_tail, r_len
	qblt	done?, bp_s0, r_len
	ldi r_res, 0
	jmp	done?

h_ge_tail?:
	sub	bp_s0, bp_max, bp_tail
	qble	done?, bp_s0, r_len
;won't fit w/o wrapping, so restart from base
	sub	bp_s0, bp_tail, bp_base
	qblt	done?, bp_s0, r_len
	ldi r_res, 0
	jmp	done?

done?:
 .endm

 .if 0 ;we don't use the HW verision yet
;------------------------------------------------
;------------------HW WIdget Versions-------------
;------------------------------------------------
BP_XID	.set	0x9

;opcodes
BP_OP_CREATE	.set	0
BP_OP_PUSH	.set	1
BP_OP_POP	.set	2
BP_OP_TRIM	.set	3

;--------------------
;create a buffer pool
; step on r18..
;--------------------
BUFP_CREATEHW	.macro	slot, r_base, r_size
	ldi	r18.b0, slot	;Warning: converted from mov
	ldi	r18.b1, BP_OP_CREATE
	and r19, r_base, r_base;Warning: converted from mov
	and r20, r_size, r_size;Warning: converted from mov
	xout	BP_XID, &r18, 12
 .endm

BUFP_CREATEHW_R	.macro	slot, r_base, r_size
	and	r18.b0, slot, slot;Warning: converted from mov
	ldi	r18.b1, BP_OP_CREATE
	and r19, r_base, r_base;Warning: converted from mov
	and r20, r_size, r_size;Warning: converted from mov
	xout	BP_XID, &r18, 12
 .endm

;-------------------
;alloc buffer bytes
; ~ 7 cycles
;------------------
BUFP_POPHW	.macro	slot, r_len, r_res, no_buf_label
	ldi	r18.b1, BP_OP_POP
	and r18.b0, slot, slot;Warning: converted from mov
	and r18.w2, r_len, r_len;Warning: converted from mov
	xout	BP_XID, &r18, 4
	xin	BP_XID, &r18, 4
	qbeq	no_buf_label, r18, 0
	and r_res, r18, r18
 .endm

;-------------------
;alloc buffer bytes
; ~ 6 cycles
; assumes r18.w2 = len
;------------------
BUFP_POPHW2	.macro	slot, r_res, no_buf_label
	ldi	r18.b1, BP_OP_POP
	and r18.b0, slot, slot;Warning: converted from mov
	xout	BP_XID, &r18, 4
	xin	BP_XID, &r18, 4
	qbeq	no_buf_label, r18, 0
	and r_res, r18, r18
 .endm
 .endif
