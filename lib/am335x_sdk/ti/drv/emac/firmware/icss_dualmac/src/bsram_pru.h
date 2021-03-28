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


;BS RAM - PRU Uses
;   -- basic q
;   -- ping pong buffer
;   -- register page
;file: bsram_pru.h

BSRAM_READ_AUTO	.set	0x8000

;define BSRAM_SET_AUTO	r10.t15 ;TODO: this macro is used by the latest code
;we cannot use it as is in the .set operation
;so replace is in all placess where is is used

PQ_XID	.set	 48
Q_XID	.set	 48
BSRAM_SIZE	.set	 4096/32   ;#of slots

BSRAM_ZERO_BANK	.macro	count
	ldi	r10, BSRAM_READ_AUTO
	xout	Q_XID, &r10, 2
	zero &r2, 32
	ldi	count, BSRAM_SIZE
fzba_label?:
	xout	Q_XID, &r2, 32
	sub count, count,1
	qbne	fzba_label?, r1, 0
	ldi	r10, 0x0000
	xout	Q_XID, &r10, 2
 .endm

;----------------------
; BS RAM SLOT assignment
;-----------------------
; tohost (delayed psi) Queue:  slots 0-23  (max depth = 24)
PSIQ_SLOT       .set    0x00  ;0-23
PSIQ_NE         .set    24    ;24 elements in queue
BG_STATE	.set	0x18  ;slot 24
GSTATE	        .set	0x19
PSI_INFO_SLOT	.set	0x1a
PSI_STATUS_SLOT	.set	0x1b
TX_STASH_SLOT	.set	0x1c
RX_STASH_SLOT	.set	0x1d
; slots 0x1e-0x1f spare

;------------------------------------------
;-----------------PORTQ---------------------
;------------------------------------------

;faster way.  keep portq info in one register (and let users manage)

;=============================================
; Q Implementation Using BS
;=============================================
;	b0, Q_HEAD
;	b1, Q_TAIL
;	b2, Q_NUM_ELEM

MAX_PSIQ_SLOT .set	(PSIQ_SLOT+PSIQ_NE-1)

PSIQ_CREATE	.macro
	ldi	GRegs.psiq.b.head, PSIQ_SLOT
	ldi	GRegs.psiq.b.num_elem, 0
	ldi	GRegs.psiq.b.tail, PSIQ_SLOT
 .endm

PSIQ_POP	.macro
	.newblock
	mov	r10, GRegs.psiq.b.head
	add	GRegs.psiq.b.head, GRegs.psiq.b.head, 1
	sub	GRegs.psiq.b.num_elem, GRegs.psiq.b.num_elem, 1
	qbgt	$1, GRegs.psiq.b.head, MAX_PSIQ_SLOT
	ldi	GRegs.psiq.b.head, PSIQ_SLOT
$1:	xout	Q_XID, &r10.w0, 2
	xin	Q_XID, &r2, 32
 .endm

;push (full32)
PSIQ_PUSH	.macro	full_lab
	.newblock
	qbeq	full_lab, GRegs.psiq.b.num_elem, PSIQ_NE
	mov	r10, GRegs.psiq.b.tail
	add	GRegs.psiq.b.tail, GRegs.psiq.b.tail, 1
	add	GRegs.psiq.b.num_elem, GRegs.psiq.b.num_elem, 1
	qbgt	$1, GRegs.psiq.b.tail, MAX_PSIQ_SLOT
	ldi	GRegs.psiq.b.tail, PSIQ_SLOT
$1:	xout	Q_XID, &r2, 36
 .endm

;---------------------------------------------------------
;register paging
;--------------------------------------------------------

PAGE_SAVE	.macro	pn
	ldi	r10, pn
	xout	Q_XID, &r2, 36
 .endm
	.asg	 PAGE_SAVE, PAGE_SAVE2

PAGE_SAVEQ	.macro
	xout	Q_XID, &r2, 36
 .endm

PAGE_RESTORE	.macro	pn, n
	ldi     r10, pn
	xout	Q_XID, &r10.w0, 2
	xin	Q_XID, &r2, n
 .endm

	.asg	 PAGE_RESTORE, PAGE_RESTORE2
