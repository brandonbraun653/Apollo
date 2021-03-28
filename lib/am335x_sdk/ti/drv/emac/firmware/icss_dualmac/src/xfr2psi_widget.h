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

;------------------------------------
;FILE: xfr2psi_widget.h
;Purpose:  macros, etc for xfr2psi_widget
;------------------------------------

;-----------------DEFINES-------------------------

;psi defines
; psi-l spec
; psi spec
PSI_DT_INFO	.set	0
PSI_DT_CONTROL	.set	12
PSI_DT_DATA	.set	20
PSI_DT_STATUS	.set	24
PSI_DT_PROINFO	.set	16 ; we think..

;bits to check in status
TB_READ0	.set	0x0
TB_READ1	.set	0x1
TB_READ2	.set	0x2
TB_READ3	.set	0x3
TB_WRITE	.set	0x0

;xids to use
XID_PSI_S	.set	0x50
XID_PSI_W	.set	0x51
XID_PSI_R1	.set	0x51
XID_PSI_R2	.set	0x52
XID_PSI_R3	.set	0x53
XID_PSI_R4	.set	0x54
XID_PSI_W2	.set	0x52

XID_PSI_GS	.set	0x58
XID_PSI_GW	.set	0x59

WR_SIZE	.set	16

ICSS_PT	.set	0x38
;-----------------STRUCTURES-----------------------------

;meta data per transaction
	.asg	t0, f_md_sop
	.asg	t1, f_md_eop
	.asg	t2, f_md_sol
	.asg	t3, f_md_eol
	.asg	t4, f_md_lastw
	.asg	t5, f_md_drop

psi_l_md	.struct
flags		.ushort;flags:  SOP=0x1, EOP=0x2
data_type	.ubyte;psi data type
count		.ubyte;# of bytes in the transaction
 .endstruct

md	.sassign	r1, psi_l_md

;some canned/expected meta data settings...

MD_DATA0	.set	0x0f140000
MD_DATA1	.set	0x00140010

MD_INFO0	.set	0x0f000011
MD_CONTROL0	.set	0x0f0c0010
MD_STATUS0	.set	0x0f180012
MD_PROINFO	.set	0x0f100010

;------------------MACROS--------------------------
PSI_READ	.macro 	 rs, len
	.newblock
	qbeq	$0, rs, 0
	qbeq	$1, rs, 1
	qbeq	$2, rs, 2
	qbeq	$3, rs, 3
	jmp	$4
$0:
	xin	XID_PSI_R1, &r1, len
	jmp	$4
$1:
	xin	XID_PSI_R2, &r1, len
	jmp	$4
$2:
	xin	XID_PSI_R3, &r1, len
	jmp	$4
$3:
	xin	XID_PSI_R4, &r1, len
$4:
 .endm

PSI_READS	.macro 	 slot, len
	xin	slot, &r1, len
 .endm

PSI_WRITEG	.macro
	xout	XID_PSI_GW, &r1, 20
 .endm

PSI_WRITE	.macro
	xout	XID_PSI_W, &r1, 20
 .endm

PSI_WRITE_N	.macro
	xout	XID_PSI_W, &r1, b0
 .endm

;write ABORT to gasket
PSI_ABORT	.macro
	.newblock
$1:     xin XID_PSI_S,&r1,8
	qbbc	$1, r2, TB_WRITE  ;only send if widget unblocked
	zero	&r1, 20
	or	md.flags, md.flags, 0x32 ;eop + lastwd + drop
	ldi	md.data_type, PSI_DT_STATUS	;status
	ldi	md.count, 0xf
	xout	XID_PSI_W, &r1, 20
 .endm

;build template PSI_INFO words and (r1) meta data
PSI_SETUP_INFO	.macro 	 slot, port
	zero	&r1, 4
	or	md.flags, md.flags, 0x11	;SOP| LASTW
	ldi	md.data_type, PSI_DT_INFO	;INFO
	ldi	md.count, 0xf			;byte enables
;now build info0-3
	ldi	r2.b3, ICSS_PT
	ldi	r2.b2, 0x00
	or	r2.b2, r2.b2, 0x10	;tbd psi flags:  indicate cut thru
	ldi	r2.w0, 0x3fff		;no flow - use default for this channel in udma-p
	ldi32	r3, 0x013FFFFF
;or   r3, r3,pex.totlen
	ldi	r4, 0xffff
	ldi	r5.w2, port	;ethernet port
	ldi	r5.w0, 0	;don't use pktid currently
	mov	r9, r1		;put r1 at end
	PAGE_SAVE slot		;save it
 .endm

;get info
; clobbers r1-r10
; updates r2.b0 with flow
PSI_GET_INFO2	.macro 	 slot, flow
	PAGE_RESTORE2 slot, 32  ;r10 clobbered!
	mov	r2.w0, flow	;note upper 2 bits must be 0 (reserved). flow is 14 bits
	mov	r1, r9
 .endm

;build template PSI_STATUS words and (r1) meta data
PSI_SETUP_STATUS	.macro 	 slot
	zero	&r1, 20
	or	md.flags, md.flags, 0x12 ;eop + lastwd
	ldi	md.data_type, PSI_DT_STATUS;status
	ldi	md.count, 0xf
	mov	r9, r1	;put r1 at end
	PAGE_SAVE slot
 .endm

;get status, v2
; clobbers r1-r4, r5 set to 0
; updates crc, timestamp
PSI_GET_STATUS2	.macro	slot, tsh, tsl, flags
	mov	r2, tsl
	mov	r3, tsh
	mov	r4, flags
	ldi	r5, 0
	ldi32	r1, MD_STATUS0
 .endm

PSI_SETUP_MGR_INFO	.macro
	ldi32	r0, FW_CONFIG
	lbbo	&r2, r0, CFG_MGR_FLOW, 4
	ldi	r2.w2, 0x8010  ; set mgr packet type
	ldi32	r3, 0x13ffffff ; ????
	ldi32	r4, 0x0000ffff ;
 .if $isdefed("SLICE0")	
	ldi32	r5, 0x00010000 ;
 .else
	ldi32	r5, 0x00020000 ;
 .endif
	ldi	r10, PSI_MGR_INFO_SLOT ; save r2-r9 to page MGR_INFO
	xout	Q_XID, &r2, 36
; we also create the TX TS timestamp INFO here
	add	r2.w0, r2.w0, 1	; next flow id is for tx_ts tamestamp
	ldi	r10, PSI_TXTS_INFO_SLOT
	xout	Q_XID, &r2, 36
	.endm

; this macro sends r2 - r5 - 16 bytes packet over management PSI channel
SEND_MGR_PKT	.macro
	LEBE2_5_swap_6_9
	PAGE_RESTORE2	PSI_MGR_INFO_SLOT, 16
	ldi32	r1, 0x0f000011
	xout	XID_PSI_W, &r1, 20
	LEBE2_5_swap_6_9
	ldi32	r1, 0x10140012
	xout	XID_PSI_W, &r1, 20
 .endm

SEND_TXTS_PKT	.macro
	LEBE2_5_swap_6_9
	PAGE_RESTORE2	PSI_TXTS_INFO_SLOT, 16
	ldi32	r1, 0x0f000011
	xout	XID_PSI_W, &r1, 20
	LEBE2_5_swap_6_9
	ldi32	r1, 0x10140012
	xout	XID_PSI_W, &r1, 20
 .endm
