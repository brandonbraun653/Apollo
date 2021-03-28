;
;  TEXAS INSTRUMENTS TEXT FILE LICENSE
; 
;  Copyright (c) 2018 Texas Instruments Incorporated
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
;  manufactured by or for TI ("TI Devices").  No hardware patent is licensed hereunder.
; 
;  Redistributions must preserve existing copyright notices and reproduce this license 
;  (including the above copyright notice and the disclaimer and (if applicable) source 
;  code license limitations below) in the documentation and/or other materials provided 
;  with the distribution.
;  
;  Redistribution and use in binary form, without modification, are permitted provided 
;  that the following conditions are met:
;  No reverse engineering, decompilation, or disassembly of this software is 
;  permitted with respect to any software provided in binary form.
;  Any redistribution and use are licensed by TI for use only with TI Devices.
;  Nothing shall obligate TI to provide you with source code for the software 
;  licensed and provided to you in object code.
;  
;  If software source code is provided to you, modification and redistribution of the 
;  source code are permitted provided that the following conditions are met:
;  Any redistribution and use of the source code, including any resulting derivative 
;  works, are licensed by TI for use only with TI Devices.
;  Any redistribution and use of any object code compiled from the source code
;  and any resulting derivative works, are licensed by TI for use only with TI Devices.
; 
;  Neither the name of Texas Instruments Incorporated nor the names of its suppliers 
;  may be used to endorse or promote products derived from this software without 
;  specific prior written permission.
; 
;  DISCLAIMER.
; 
;  THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
;  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
;  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'S
;  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
;  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
;  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
;  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
;  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
;  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 
; file:   eSPI_single_mode.asm
;
; brief:  This files contains the bitbang states for Single Mode
;
;
;  (C) Copyright 2018, Texas Instruments, Inc
;
	
;;; INCLUDES ;;;
	.include "icss_defines.h"
	.include "eSPI_bitbang.h"
	.include "icss_ctrl_regs.h"
	.include "eSPI_state_table.h"
	.include "eSPI_pru_x_defines.h"

;;; GLOBAL DEFINES ;;;
        .global PRU_X_START
	.global ERROR_CS_DEASSERT
	.global RESET_STATE
	.global READY_STATE
	.global END_STATE
	.global main

	.sect    ".text:PRU_X_START"
;-------------------------------------------------------------------
; Subroutine: START_STATE
; Description: Wait for CS to assert (active low) and set things up
;-------------------------------------------------------------------
PRU_X_START:
RESET_STATE:
	;; Clear all registers
	ZERO	&R0, 124

	;; Initialize local registers
	INIT_STATE_TABLE
	LDI32	r_SlaveRegistersBase, g_SharedMemoryBaseAddr

	;; PRU-CC is in charge of initializing everything, and will initialize STS last
	LDI32	r_Temp0, g_DefaultStatusRegVal
pru_cc_handshake:
	LBBO 	&r_CurrStatusReg, r_SlaveRegistersBase, STATUS_REGISTER_BASE, 4
	QBNE	pru_cc_handshake, r_CurrStatusReg, r_Temp0

	;; Status register ready
	MOV	r_StatusReg, r_CurrStatusReg
	XOUT	BANK0, &r_StatusReg, 4

	;; Set up GPO defaults
	ZERO	&R30, 4
	SET	R30, R30, g_AlertPin ; Alert active LOW
	SET	R30, R30, g_EnPin    ; EN active LOW
	MOV	r_GpoDefault, R30

	;; Set up Dual Mode clear mask
	LDI32	r_DualClearMask, g_DualClearMask_inv ; Logical not (~) isn't supported by pre-proc
	NOT	r_DualClearMask, r_DualClearMask

	;; Set up Quad Mode clear mask
	LDI32	r_QuadClearMask, g_QuadClearMask_inv ; Logical not (~) isn't supported by pre-proc
	NOT	r_QuadClearMask, r_QuadClearMask

	;; Set up Dual Mode data mask
	LDI32	r_DualDataMask, g_DualDataMask

	;; Set up Quad data mask
	LDI32	r_QuadDataMask, g_QuadDataMask
	
	JMP	READY_STATE

;-------------------------------------------------------------------
; Subroutine: READY_STATE
; Description: Wait for PRU-CC to give the signal to head to the next state
;-------------------------------------------------------------------
	.sect	".text:ready_state"
READY_STATE:
	;; Reset GPO
	MOV	R30, r_GpoDefault

	;; Read Status register update from PRU-CC (just in case things changed)
	XIN	BANK0, &r_StatusReg, 4

	;; Reset IPC registers
	ZERO	&r_Data, 8
	XOUT	BANK0, &r_Data, 8

cs_wait_loop:	
	;; ALERT if status register changed
	LBBO 	&r_CurrStatusReg, r_SlaveRegistersBase, 0x18, 4
	QBNE	ALERT_STATE, r_CurrStatusReg, r_StatusReg

	;; Check CS assertion
	QBBS 	cs_wait_loop, R31, g_CsPin

	;; CS asserted, jump to next state
	XIN    BANK0, &r_NextState, 4
	JMP_TO_STATE    r_NextState

;-------------------------------------------------------------------
; Subroutine: ALERT_STATE
; Description: Update the status register and raise the alert pin 
;-------------------------------------------------------------------
	.sect	".text:alert_state"
ALERT_STATE:
	;; Update Status register
	MOV	r_StatusReg, r_CurrStatusReg
	XOUT	BANK0, &r_StatusReg, 4

	;; Assert ALERT# pin
	CLR	R30, R30, g_AlertPin

	;; Wait for CS#
alert_wait_for_cs_assert:	
	QBBS 	alert_wait_for_cs_assert, R31, g_CsPin

	;; Can now de-assert ALERT
	SET	R30, R30, g_AlertPin
	
	;; CS asserted, jump to next state
	XIN    BANK0, &r_NextState, 4
	JMP_TO_STATE    r_NextState


;-------------------------------------------------------------------
; Subroutine: END_STATE
; Description: Chill here until CS is not asserted (active low)
;-------------------------------------------------------------------
	.sect	".text:end_state"
END_STATE:
check_CS_deassertion:	
	QBBC	check_CS_deassertion, R31, g_CsPin
	SET	r_Flags, r_Flags, ICSS_ESPI_CS_DEASSERT_GOOD_FLAG_BIT
	XOUT	BANK0, &r_Flags, 4
	JMP 	READY_STATE

;-------------------------------------------------------------------
; Subroutine: ERROR_CS_DEASSERT
; Description: CS has been improperly de-asserted, alert PRU-CC
;-------------------------------------------------------------------
ERROR_CS_DEASSERT:
	SET	r_Flags, r_Flags, ICSS_ESPI_CS_DEASSERT_BAD_FLAG_BIT
	XOUT	BANK0, &r_Flags, 4
	JMP 	READY_STATE
