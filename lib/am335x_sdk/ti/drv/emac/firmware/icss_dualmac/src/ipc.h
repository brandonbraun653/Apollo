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

;-------------------------------------------
;File: ipc.h
; Purpose: rtu - Pru  IPC SPAD defines & macros
;  rtu-rtu IPC via SPADs
; v3
;------------------------------------------

;==================(1) RTU-PRU IPC===================

;------------------Layout--------------------
;RTU-PRU IPC SPAD is 32 bytes wide (mapped to r2-r9)
; propose the following layout:
;   r2-r6 =  RTU to PRU comms
;   r7-r9 =  PRU to RTU comms
;  RTU owns r2-r6
;    r2-r4 = params for  'chan0' = tx descriptor + special flags
;    r5-r6 = params for  'chan1' = RX fwd info:  flags + descriptor
; PRU owns  r7-r9
;    r7, r8,r9 = params for 'chan0' = SOP info  (vlantag + flags)
;    r7, r8,r9 = params for 'chan1' = EOP info  (descriptor & flags)
;-------------Programming Model-----------------
; RTU->PRU
;  rtu reads r2-r9 from ipc
; PRU->RTU is opposite
;
;------------------------------------------------------------------
;-------------------------Defines----------------------------------
;------------------------------------------------------------------
P2P_IPC_XID	.set	15

;-----------------------------------------------------------------
;--------------------MACROS---------------------------------------
;----------------------------------------------------------------

;=========================================
; (1) RTU-PRU IPC
;=========================================

;zap ipc
P2P_IPC_ZAP	.macro
	xout	P2P_IPC_XID, &r2, 32
 .endm

;-------------RTU SIDE------------------
;rtu scheduler pushing a ready packet descriptor to PRU
; data must be in r2
;  Preemptible pkt channel
RTU_IPC_TX_CH0_PPKT	.macro
	xout	P2P_IPC_XID, &r2, 4
 .endm
;rtu scheduler pushing a ready packet descriptor to PRU
; data must be in r3
; Express pacekt channel
RTU_IPC_TX_CH0_EPKT	.macro
	xout	P2P_IPC_XID, &r3, 4
 .endm

;rtu  pushing rx packet routing info to PRU
; data must be in r5, r6
RTU_IPC_TX_CH1	.macro
	xout	P2P_IPC_XID, &r5, 8
 .endm

;-------------PRU SIDE------------------
; data receive from RTU from channel0
; data in r2-r4
;  r2 holds p-pkt descr if preemptEnabled. else holds any pkt
;  r3 holds e-pkt descr if preemptEnabled. Else not used
; bit 23 of r2, r3 is valid bit. 1=>valid data
;  **even if valid, need to check corresponding RXDMA channel status
;  to make sure data is ready
;  ** if tx starts on p-subchan or e-subchan, tx needs to clear valid bit
; bit 0 of r4 is PreemptActive bit  (1=>preempt active)
; bit 1 of r4 is hold/resume bit.  1=>hold, 0 => resume
; macros are:
;  PRU_IPC_RX_CH0q  (param = r2/r3 to indicate which sub-chan to poll)
;  PRU_IPC_RX_CH0_CHK_HOLD
;  PRU_IPC_RX_CH0_CHK_RESUME

;poll subchan queue of chan 0
;  r_tp = r2 or r3 PLEASE!!
;  ru = dma read unit = XFR2VBU_XID_READ0 for r2, READ1 for r3
;  stomps on r18
PRU_IPC_RX_CH0Q	.macro 	 no_new_label, r_tp, ru
	xin	P2P_IPC_XID, &r_tp, 4
	qbbc	no_new_label, r_tp, 23	 ;r_tp.f_desc_valid
	XFR2VBUS_POLL_READ ru
	qbne	no_new_label, r18.w0, 0x5
	clr	r_tp, r_tp, 23
	xout	P2P_IPC_XID, &r_tp, 4
 .endm

;check hold/resume state desired by RTU
PRU_IPC_RX_CH0_CHK_HOLD	.macro 	 no_hold_label
	xin	P2P_IPC_XID, &r4, 4
	qbbc	no_hold_label, r4, 1	 ;replaced: qbbc no_hold_label, r4.f_hold
 .endm

PRU_IPC_RX_CH0_CHK_RESUME	.macro 	 dont_resume_label
	xin	P2P_IPC_XID, &r4, 4
	qbbs	dont_resume_label, r4, 1	 ;replaced: qbbs dont_resume_label, r4.f_hold
 .endm

; data receive from RTU from channel1
;  (at Block 1 time)
; data in r5, r6
PRU_IPC_RX_CH1	.macro
	xin	P2P_IPC_XID, &r5, 8
 .endm

PRU_IPC_RX_CH1_CLRB7	.macro
	clr	r5, r5, 7
	xout	P2P_IPC_XID, &r5, 4
 .endm

