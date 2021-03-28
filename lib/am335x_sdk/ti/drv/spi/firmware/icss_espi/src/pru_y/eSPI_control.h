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
;  manufactured by or for TI (â€œTI Devicesâ€�).  No hardware patent is licensed hereunder.
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
;  THIS SOFTWARE IS PROVIDED BY TI AND TIâ€™S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
;  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
;  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TIâ€™S
;  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
;  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
;  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
;  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
;  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
;  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 
; file:   eSPI_control.h
;
; brief:  This files contains all control macro definitions
;
;
;  (C) Copyright 2018, Texas Instruments, Inc
;
;
	
    .if    !$defined("__eSPI_control_h")
__eSPI_control_h    .set 1

;;; INCLUDES ;;;
	.include "icss_defines.h"
	.include "icss_intc_regs.h"
	.include "crc.h"
	.include "eSPI_pru_y_defines.h"

	.global HANDLE_FLAG
	
;-------------------------------------------------------------------
; Macro Name: READ_BYTE
; Description: Handle an incoming byte from the bit-bang PRU
; Input Parameters: None
; Output Parameters: byte-indexed register in which to read the data byte
;-------------------------------------------------------------------
READ_BYTE	.macro	DataByte
byte_ready?:
	XIN	BANK0, &r_PruXData, 8
	;; QBNE	HANDLE_FLAG, r_Flags, 0
	QBEQ	byte_ready?, r_PruXCount, r_PruYCount
	MOV	r_PruYCount, r_PruXCount
	MOV	DataByte, r_PruXData
	.endm

;-------------------------------------------------------------------
; Macro Name: READ_BYTE_CRC
; Description: Handle an incoming byte from the bit-bang PRU and calculate CRC
; Output Parameters: byte-indexed register in which to read the data byte
; Input Parameters: CRC calculation register
;-------------------------------------------------------------------
READ_BYTE_CRC	.macro	DataByte, CrcCalc
	READ_BYTE	DataByte
	CALC_CRC_BYTE	CrcCalc, DataByte
	.endm

	
;-------------------------------------------------------------------
; Macro Name: WRITE_BYTE
; Description: Prep a byte to be written by the bit-bang PRU core
; Input Parameters: byte to write
; Output Parameters: none
;-------------------------------------------------------------------
WRITE_BYTE	.macro	Byte
write_ready?:
	MOV	r_Data, Byte
	XOUT	BANK0, &r_Data, 4
write_loop?:
	XIN	BANK0, &r_Count, 4
	QBNE	HANDLE_FLAG, r_Flags, 0
	QBEQ	write_loop?, r_PruXCount, r_PruYCount
	MOV	r_PruYCount, r_PruXCount
	.endm

;-------------------------------------------------------------------
; Macro Name: WRITE_BYTE_CRC
; Description: Prep a byte to be written by the bit-bang PRU core and calculate CRC
; Input Parameters: byte to write
; Input Parameters: CRC calculation register
; Output Parameters: none
;-------------------------------------------------------------------
WRITE_BYTE_CRC	.macro	Byte, CrcCalc
	WRITE_BYTE	Byte
	CALC_CRC_BYTE	CrcCalc, Byte
	.endm

;-------------------------------------------------------------------
; Macro Name: WRITE_CRC
; Description: Send the CRC byte to the bit-bang PRU to write out
; Input Parameters: CRC calculation register
; Output Parameters: none
;-------------------------------------------------------------------
WRITE_CRC	.macro	CrcCalc
write_ready?:
	MOV	r_Data, CrcCalc
	XOUT	BANK0, &r_Data, 4
write_loop?:
	XIN	BANK0, &r_Count, 4
	QBNE	write_end?, r_Flags, 0
	QBEQ	write_loop?, r_PruXCount, r_PruYCount
write_end?:
	MOV	r_PruYCount, r_PruXCount
	.endm

;;; TODO: optimize (probs by putting jump table in known memory location)
;-------------------------------------------------------------------
; Macro Name: SET_PRU_X_STATE
; Description: Tell PRU0 to jump to the specified state
; Input Parameters: byte to write
; Input Parameters: CRC calculation register
; Output Parameters: none
;-------------------------------------------------------------------
SET_PRU_X_STATE	.macro	State
	LDI	r_PruXState, State
	OR	r_PruXState, r_PruXState, r_Mode
	LSL	r_PruXState, r_PruXState, 1
	XOUT	BANK0, &r_PruXState, 4
	.endm

SET_PRU_BB_STATE .macro State, Mode
	LSL	r_PruXState, Mode, 1
	ADD	r_PruXState, r_PruXState, State
	LSL	r_PruXState, r_PruXState, 6 ; 8 (for address) - 2 (bc byte-addressing)
	XOUT	BANK0, &r_PruXState, 4
	.endm

;----------------------------------------------------------------------
; Macro Name: SET_IPC_MESSAGE
; Description: Place a message in the IPC register.
; Output Parameters: none
;----------------------------------------------------------------------
SET_IPC_MESSAGE    .macro	ipc_message
	LDI	r_Tmp1, ipc_message
	SBBO 	&r_Tmp1, r_SharedMemoryBase, IPC_REGISTER_BASE, 4
	.endm
   
;----------------------------------------------------------------------
; Macro Name: RAISE_INTERRUPT_FOR_HOST
; Input Parameters: Label on new memor
; Output Parameters: none
;----------------------------------------------------------------------
RAISE_INTERRUPT_FOR_HOST    .macro
    LDI     r_Tmp0.w0, ICSS_INTC_SRSR0
    LDI32   r_Tmp1, ICSS_ESPI_INTC_BIT_VAL
    SBCO    &r_Tmp1, ICSS_INTC_CONST, r_Tmp0.w0, 4
	.endm

;----------------------------------------------------------------------
; Macro Name: UPDATE_BITS_FROM_REF
; Input Parameters: Copies register with updated bits from reference register
; Output Parameters: none
;----------------------------------------------------------------------
UPDATE_BITS_FROM_REF    .macro	dest, ref, tmp, mask
	LDI32	tmp, (mask)
	NOT	tmp, tmp
	AND	dest, dest, tmp
	NOT	tmp, tmp
	AND	tmp, ref, tmp
	OR	dest, dest, tmp
	.endm

;----------------------------------------------------------------------
; Macro Name: UPDATE_BITS_FROM_REF
; Input Parameters: Copies register with updated bits from reference register
; Output Parameters: none
;----------------------------------------------------------------------
UPDATE_BIT_FROM_REF    .macro	dest, ref, bit
	QBBS	bit_set?, ref, bit
	CLR	dest, dest, bit
	JMP	end?
bit_set?:
	SET	dest, dest, bit
end?:
	.endm
	
    .endif  ;__eSPI_control_h
