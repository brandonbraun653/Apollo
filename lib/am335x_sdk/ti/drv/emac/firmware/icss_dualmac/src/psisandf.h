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

;------------------------
;File: psisandf.h
;Purpose:
;   experimental do sandf to host over psi (instead of cutthrough)
;------------------------

;----------------------------------------------
;free slot management
;----------------------------------------------

;BSram slots used (96) = 3072 bytes = ~ 2x 1500 byte pkts
MAXPS .set  127  ;last slot for 32 byte chuncks
MINPS .set  32   ;1st slot for 32 byte chunks

;----------------------
;called by Rx Task
;----------------------
;push r2-r9 to a bs slot, start of packet
;push r2-r9 to a bs slot
; GR_AUX_STATE holds slot control info (r/w ptr)
P_W32	.macro  full_label
	.newblock
        mov     r10, GRegs.snf.b.wr_cur
        xout    Q_XID, &r2, 36
        add     GRegs.snf.b.wr_cur, GRegs.snf.b.wr_cur, 1
        qbge    $1, GRegs.snf.b.wr_cur, MAXPS
        ldi     GRegs.snf.b.wr_cur, MINPS
$1:     qbeq    full_label, GRegs.snf.b.wr_cur, GRegs.snf.b.rd_cur
 .endm

P_W32_S .macro  full_label
        mov     GRegs.snf.b.wr_orig, GRegs.snf.b.wr_cur   ;stash original write pointer in case we abort
	P_W32	full_label
 .endm

P_W32_ABORT .macro
        mov	GRegs.snf.b.wr_cur, GRegs.snf.b.wr_orig ; restore write pointer
 .endm

;usefull macro to poll until psiwidget txfifo status says there is room
; steps on r1/r2
PSILOOP_STALL_TX_OK .macro
	.newblock
$1:     xin XID_PSI_S, &r1, 8
        qbbs $2, r2, TB_WRITE  ;only send if widget unblocked
        add r30.w2, r30.w2, 1  ;debug -> count # of stalls
        jmp $1
$2:
  .endm

; called by bg task
;'tx' init for tohost store and forward 
; r_d.w0 = len
; r_d.w2 = flow
; r_strti = bsram fifo state snapshot 
PSISANDF_TX_INIT2 .macro   r_d, r_starti
        mov	r11.w0, r_d.w2			;save flow
        mov	GRegs.snf.b.rd_cur, r_starti.b1 ;save start slot #
        ;save length we are expecting to transmit
        mov	BgRegs.len2host, r_d.w0
        mov	BgRegs.len_orig, r_d.w0
        ldi	BgRegs.psi2h_active, 1
        ;send info
        TM_DISABLE
        ;ok to write to PSI since we checked before entry to this macro!
        PSI_GET_INFO2 PSI_INFO_SLOT, r11.w0
        TM_ENABLE
        PSI_WRITE
        PSILOOP_STALL_TX_OK  ;stall until PSI tx status good
        PSISANDF_TX md_lab?, eop_lab? ;now write 2 x 16bytes to PSI, checking that data is available from dma
md_lab?:
        PSILOOP_STALL_TX_OK
        PSISANDF_TX md_lab2?, eop_lab? ;now write 2 x 16bytes to PSI, checking that data is available from dma
md_lab2?:
eop_lab?:
 .endm

READ_PAGE	.macro	page
        TM_DISABLE
        mov	r10.w0, page
	xout	Q_XID, &r10.w0, 2
	xin	Q_XID, &r2, 32 
        TM_ENABLE
 .endm

;poll routine for bg.  read 32 bytes from BS and send to host in 2 psi transfers
; r_s = psi state
; returns to more_data_lab if still more data, else returns to eop_lab
PSISANDF_TX	.macro 	 more_data_label, eop_label

;have data ready
	qbge	tx_cont1a?, BgRegs.len2host, 32
;read the 32 bytes & write to PSI in 2 transactions
        READ_PAGE GRegs.snf.b.rd_cur
	ldi32	r1, MD_DATA0
	PSI_WRITE
        PSILOOP_STALL_TX_OK  ;stall until PSI tx status good
	LEBE2_5_swap_6_9
	ldi32	r1, MD_DATA0
	PSI_WRITE
	sub	BgRegs.len2host, BgRegs.len2host, 32
        add	GRegs.snf.b.rd_cur, GRegs.snf.b.rd_cur, 1
        qbge	more_data_label, GRegs.snf.b.rd_cur, MAXPS
        ldi	GRegs.snf.b.rd_cur, MINPS
	jmp	more_data_label

tx_cont1a?:   ;eop 
        READ_PAGE GRegs.snf.b.rd_cur
        add	GRegs.snf.b.rd_cur, GRegs.snf.b.rd_cur, 1
        qbge	chk_len?, GRegs.snf.b.rd_cur, MAXPS
        ldi	GRegs.snf.b.rd_cur,MINPS
chk_len?
	qble	mt16?, BgRegs.len2host, 16
;just have 16bytes or less
	ldi32	r1, MD_DATA1
	add	r0.b0, BgRegs.len2host, 4
	PSI_WRITE_N
	jmp	tx_done2?
mt16?:
;just have 32bytes or less
	ldi32	r1, MD_DATA0
	PSI_WRITE
        PSILOOP_STALL_TX_OK  ;stall until PSI tx status good
	LEBE2_5_swap_6_9
	ldi32	r1, MD_DATA1
	sub	BgRegs.len2host, BgRegs.len2host, 16
	add	r0.b0, BgRegs.len2host, 4
	PSI_WRITE_N
tx_done2?:
;send status
        PSILOOP_STALL_TX_OK  ;stall until PSI tx status good
        ;todo get rx timestamp in here
	ldi32	r1, FW_CONFIG + RX_TS_BASE
	lbbo	&r11, r1, 0, 8
        TM_DISABLE
        PSI_GET_STATUS2 PSI_STATUS_SLOT, r12, r11, r13
        TM_ENABLE
        mov	r5, BgRegs.len_orig
        PSI_WRITE
;set tx state
	ldi	BgRegs.psi2h_active, 0
	jmp	eop_label
tx_done?:
 .endm
