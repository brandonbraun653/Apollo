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

;---------------------------
;file: regalias.h
;----------------------------

;==========================================================================
Struct_RXTASK	.struct
pq_cur		.ushort	;
res1		.ubyte	;
res2		.ubyte	;
vlanc		.uint	;
; state aux
aux_flags	.ubyte	;
priority	.ubyte	;0-7
dcs		.ubyte	;ipc contol
res3		.ubyte	;spare1
; state info
def_flow	.ushort	;base flow for port
state_flags	.ubyte	;
port_state	.ubyte	;
	.endstruct ;Struct_RXTASK

RxRegs	.sassign r20, Struct_RXTASK ; r20-r23

; aux flags definitions
f_fh     	.set	0 ;half of rx fifo we are working in
f_vstrip 	.set	1 ;hard strip of vlan tag needed
f_vadd   	.set	2 ;hard add of vlan tag needed
f_untag  	.set	3 ;set if pkt arrived un-tagged so we are running with "virtual internal tag"
f_dcpp   	.set	4
f_b1_seen	.set	5
; info flags

f_vlan	   	.set	0 ;vlan enabled
f_unitohost    	.set	1 ;ukn unicast to host (switch)
f_promiscuous  	.set	2 ;promiscuous mode (mac)
f_m_promiscuous	.set	3 ;mcast promiscuous (mac)
f_preemptive   	.set	4 ;preemption active
f_prm	   	.set	5 ;priority remap


;==========================================================================
Struct_TXTASK	.struct
res		.ushort
ds_flags	.ushort	;descriptor info
stash_ds_flags	.ushort
stash_tx_len	.ushort
;
res2		.uint
	.endstruct ;Struct_TXTASK


TxRegs	.sassign r21, Struct_TXTASK

;==========================================================================
;---BG TASK
;r0  temp
;r1  temp
;r2-r9 various
;r10 - r19

Struct_BGTASK .struct
bg_cnt		.uint	; BG loop counter
psi2h_active	.ubyte	; 1 - active, 0 - idle
res9		.ubyte	;
len2host	.ushort	;
res10		.ushort ;
len_orig	.ushort ;
	.endstruct ;Struct_BGTASK

BgRegs	.sassign r20, Struct_BGTASK

;==========================================================================
Struct_GLOBAL	.struct
rx	.union
x		.uint
s		.struct
fl_n_state		.ushort
pkt_len			.ushort
		.endstruct
b		.struct
flags			.ubyte
state			.ubyte
pkt_len			.ushort
		.endstruct
	.endunion ;rx

speed_f	.ubyte		; speed/duplex flags
ret_cnt	.ubyte		; retransmission counter
tx_blk	.ubyte		; tx 64 byte blocks counter
res	.ubyte		; 

tx	.union
x		.uint
b		.struct
state			.ubyte
flags			.ubyte
len			.ushort
		.endstruct ;b
	.endunion ;tx

pkt_cnt	.union
x		.uint
w		.struct
rx			.ushort
tx			.ushort
		.endstruct ;w
	.endunion ;pkt_cnt

snf	.union		; psi store and forward
x	.uint
b	.struct
wr_cur		.ubyte	; current write slot
wr_orig		.ubyte	; original write slot
rd_cur		.ubyte	; current read slot
dbg_cnt		.ubyte
	.endstruct
	.endunion ;snf

psiq	.union
x		.uint
b		.struct
head			.ubyte
tail			.ubyte
num_elem		.ubyte
res			.ubyte
		.endstruct ;b
	.endunion ; psiq
	.endstruct ;Struct_GLOBAL

GRegs	.sassign r24, Struct_GLOBAL

; 100/10Mbps/half duplex port flags. That is mirror of the correcponding bits
; of the ICSSG_RGMII_CFG register
 .if $isdefed("SLICE0")
f_100mbps	.set	1
f_1gbps		.set	2
f_half_d	.set	3
f_mask_o	.set	0xe
f_mask_a	.set	0xf1

f_col_detected	.set	4
f_stopped_due_col .set	5
f_wait_ipg	.set	6


 .else
f_100mbps	.set	5
f_1gbps		.set	6
f_half_d	.set	7
f_mask_o	.set	0xe0
f_mask_a	.set	0x1f

f_col_detected	.set	0
f_stopped_due_col .set	1
f_wait_ipg	.set	2
 .endif

;RX flags
f_tohost	.set 0
f_rx_sof	.set 7

;TX states
TX_S_IDLE	.set	0
TX_S_ACTIVE	.set	1
TX_S_ERR	.set	2
TX_S_W_EOF	.set	3
;TX_S_W_CEOF	.set	3
TX_S_W_PEOF	.set	4
;TX_S_DC	.set	5
;TX_S_CUT	.set	6
TX_S_LOOP	.set	7

; TX flags
;f_tx_spare0	.set	0
f_tx_stash 	.set	1 ;if set then there is a preempted packet present in stash
f_tx_hold 	.set	2 ;set if hold active
f_tx_efq  	.set	3 ;express frame is queued! (from portq)
f_tx_efqd 	.set	4 ;express frame is queued!  (from DC queue)
f_next_dma	.set	5 ;dma to check next (non PSA=ping/pong case)


;==========================================================================
Struct_PktCtx	.struct
; -0-
ippc_flags	.ubyte
ippc_forward	.ubyte
ippc_totlen	.ushort	;expected length of packet
; -1-
ippc_curlen	.ushort	;current length of pkt
ippc_res   	.ubyte	;resource (queue number)
ippc_es    	.ubyte	;extra state (details on what we might stall on)
; -2-
he_flags	.ubyte	;seebelow
;bits 0-3: 1 => thread x uses rate limiter
;bits 4:  spare
;bit  6:  Shutting_down (clear out any ongoing/stalled transfers)
;bit  7:  PSI DOWN (no host egress)
he_dq01 	.ubyte	;default port queues for threads 0 (high nibble), 1
he_dq23 	.ubyte	; "" for threads 2 (high nibble), 3
he_spare	.ubyte
; -3 & 4 -
ippx_ptr0	.uint	;buffer pointer0 - this slice
ippx_ptr1	.uint	;buffer pointer1 - other slice

	.endstruct

;;r_pix2
; .if $isdefed("HE_CS_SUPPORT") ;not in pg1.0
;	.asg	 r_pix2, ippx_cw2 ;control word2
;	.asg	b3, cs_loc  ;offset to where csum should be placed (should contain partial cs already (1 relative)
;	.asg	b2, cs_start ;offset where to start checksum (1 relative)
;	.asg	t15, cs_inv  ;if st then 0 cs qqill eb inverted and sent as 0xffff
;	.asg	w0, cs_bc   ; bytes to checksum (>0 => do checksum so test this to see if checksum needed
; .endif

; Struct_RCtx is alias of the Struct_PktCtx and used
; only to save or restore some of the struct registers
Struct_RCtx	.struct
pix0	.uint
pix1	.uint
pix2	.uint
pix3	.uint
pix4	.uint
	.endstruct

Ctx	.sassign R20, Struct_PktCtx
RCtx	.sassign R20, Struct_RCtx

f_rts     	.set	7  ;request egress timestamp
f_crcinpkt	.set	6  ;if set, crc is already included in packet so hw shouldn't add
f_vadd2   	.set	5  ;if set, vlan tag needs to be added
f_vrem2   	.set	4  ;if set, vlan tag needs to be removed
f_cs      	.set	3  ;checksum needed (see ippc_cw2)
f_eop     	.set	2  ;eop seen

f_ippc_spare0 	.set	0  ;to line up with forward macro 'res' format
f_port0       	.set	1  ;egress port 0
f_port1       	.set	2  ;egress port 1
f_is_unicast  	.set	3
f_is_broadcast	.set	4
f_is_multicast	.set	5
f_is_express  	.set	6  ;future

f_es_b0		.set	0   ;buffer for this slice
f_es_b1		.set	1   ;buffer for other slice
f_es_q0		.set	2   ;queue slot for this slice
f_es_q1		.set	3   ;queue slot for the other slice

HE_SPARE	.set	4
HE_SHUT 	.set	6  ;
HE_DOWN 	.set	7  ;no host egress

; for switch we have our and other ports
 .if $isdefed("SLICE0")
our_port   	.set	1
other_port 	.set	2
 .else
our_port   	.set	2
other_port 	.set	1
 .endif

;==========================================================================

;--- Tasks:TASK1(block0), RX_TASK4 (eof)
; --highest priority
	.asg	r14, R_PSI_FLAGS ;overlay w/scratch4
	.asg	r15, R_TS_HI
	.asg	r16, R_TS_LO
	.asg	r16, R_BASIC_F  ;overlay w/ TS_LO
	.asg	r17, R_CLASSI ;overlay
	.asg	r21, R_RX_STATE_INFO
	.asg	r22, R_RX_STATE

;==========================================================================
Struct_RTU_GLOBAL .struct
;-1-
ret_addr	.ushort
res		.ubyte
speed_f		.ubyte

;-2-
StallMask	.ubyte
ActThrdNum	.ubyte
StallReason	.ubyte
ResLock		.ubyte
;-3-
pqmap		.ubyte	;bit i=1 => queue i has something
state		.ubyte
flags		.ushort
;-4-
qmask		.ubyte	;mask of queues to check
qmask_old	.ubyte	;preserved queue mask
spare		.ubyte
seq_num		.ubyte	; save seq number for mgr packet
;-5-
save1		.ubyte  ;
save2		.ubyte  ;
save3		.ubyte  ;
save4		.ubyte  ;

	.endstruct ;Struct_RTU_GLOBAL

f_dmau      	.set	0   ; next dma unit
f_hold      	.set	1   ; hold set=> means only queues HOLDQ mask will be serviced (these are 'express' queues)
f_cut       	.set	2  ; cut-thru set
f_dma0      	.set	3  ; dma1 active
f_dma1      	.set	4  ; dma0 active
f_tstx_ready  .set	5
f_pend      	.set	6  ;true if hold/resume transision pending
f_pactive   	.set	7  ;true if preempt active (assume this can only be changed when scheduler is in idle state..
f_tx0_complete	.set	8
f_tx1_complete	.set	9
f_tx0_preempt 	.set	10 ;tbd if need

;scheduler state/shadow state (s_state)GRrtu
;Note: only 00 and 30 used currently (with PSA feature)
SCHED_STATE_00	.set	0
SCHED_STATE_10	.set	1
SCHED_STATE_20	.set	2
SCHED_STATE_30	.set	3
SCHED_STATE_31	.set	4
SCHED_STATE_34	.set	5

NORM_QMASK	.set	0xff
HOLD_QMASK	.set	0x80
EPKT_QMASK	.set	 (HOLD_QMASK)   ; same

GRrtu	.sassign r25, Struct_RTU_GLOBAL
