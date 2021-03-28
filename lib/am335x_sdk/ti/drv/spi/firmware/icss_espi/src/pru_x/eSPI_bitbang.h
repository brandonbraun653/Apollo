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
; file:   eSPI_bitbang.h
;
; brief:  This files contains all macros needed for bit-banging the I/O lines
;
;
;  (C) Copyright 2018, Texas Instruments, Inc
;
;
	
    .if    !$defined("__eSPI_bitbang_h")
__eSPI_bitbang_h    .set 1

	.include "eSPI_pru_x_defines.h"
	.global ERROR_CS_DEASSERT

;-------------------------------------------------------------------
; Macro Name: CHECK_CS_ERROR
; Description: check if CS has been improperly deasserted
; Input Parameters: none
; Output Parameters: none
;-------------------------------------------------------------------
CHECK_CS_ERROR	.macro
	QBBS	ERROR_CS_DEASSERT, R31, g_CsPin
	.endm

;-------------------------------------------------------------------
; Macro Name: WAIT_SCL_HIGH
; Description: Wait until SCL is high, start checking for errors if it takes too long
; Input Parameters: none
; Output Parameters: none
;-------------------------------------------------------------------
WAIT_SCL_HIGH_SINGLE	.macro
	QBBS	scl_high_single?, R31, g_SclPin
scl_low_single?:
	CHECK_CS_ERROR
	QBBC	scl_low_single?, R31, g_SclPin
scl_high_single?:			
	.endm

WAIT_SCL_HIGH_DUAL	.macro
	QBBS	scl_high_dual?, R31, g_SclPin
scl_low_dual?:
	CHECK_CS_ERROR
	QBBC	scl_low_dual?, R31, g_SclPin
scl_high_dual?:
	.endm

WAIT_SCL_HIGH_QUAD	.macro
	QBBS	scl_high_quad?, R31, g_SclPin
scl_low_quad?:
	CHECK_CS_ERROR
	QBBC	scl_low_quad?, R31, g_SclPin
scl_high_quad?:
	.endm

	
;-------------------------------------------------------------------
; Macro Name: WAIT_SCL_LOW
; Description: Wait until SCL is low, start checking for errors if it takes too long
; Input Parameters: none
; Output Parameters: none
;-------------------------------------------------------------------
WAIT_SCL_LOW_SINGLE	.macro
	QBBC	scl_low_single?, R31, g_SclPin
scl_high_single?:
	CHECK_CS_ERROR
	QBBS	scl_high_single?, R31, g_SclPin
scl_low_single?:
	.endm

WAIT_SCL_LOW_DUAL	.macro
	QBBC	scl_low_dual?, R31, g_SclPin
scl_high_dual?:
	CHECK_CS_ERROR
	QBBS	scl_high_dual?, R31, g_SclPin
scl_low_dual?:
	.endm

WAIT_SCL_LOW_QUAD	.macro
	QBBC	scl_low_quad?, R31, g_SclPin
scl_high_quad?:
	CHECK_CS_ERROR
	QBBS	scl_high_quad?, R31, g_SclPin
scl_low_quad?:
	.endm

;-------------------------------------------------------------------
; Macro Name: READ_DATA_BIT
; Description: read data bit when SCL is high
; Input Parameters: bit position
; Output Parameters: register to read data
;-------------------------------------------------------------------
READ_DATA_BIT	.macro Data, BitPosition
	WAIT_SCL_HIGH_SINGLE
	;; save R31 to tmp reg, then check
	QBBS	set_data_bit_high?, R31, g_D0InPin
	JMP	data_bit_read_done?
set_data_bit_high?:
	SET	Data, Data, BitPosition
data_bit_read_done?:
	CHECK_CS_ERROR
	WAIT_SCL_LOW_SINGLE
	.endm

;-------------------------------------------------------------------
; Macro Name: READ_DATA_BIT_MASK
; Description: read data at selected 
; Input Parameters: bit position
; Output Parameters: register to read data
;-------------------------------------------------------------------
READ_DATA_BIT_MASK	.macro Data, GPI, BitPosition, Mask
	WAIT_SCL_HIGH_SINGLE
	AND	Data, GPI, Mask
	LSR	
	CHECK_CS_ERROR
	WAIT_SCL_LOW_SINGLE
	.endm
	
;-------------------------------------------------------------------
; Macro Name: LOAD_WAIT_STATE_IDEAL
; Description: load WAIT_STATE response for first 8 cycles (HARDCODED CYCLE COUNT)
; Input Parameters: none
; Output Parameters: register in which to load WAIT_STATE response
;-------------------------------------------------------------------
LOAD_WAIT_STATE_IDEAL	.macro DataOut
	WAIT_SCL_HIGH_SINGLE
	LDI	DataOut, g_WaitStateResponseCode
	CHECK_CS_ERROR
	WAIT_SCL_LOW_SINGLE
	.endm

;-------------------------------------------------------------------
; Macro Name: WRITE_DATA_BIT
; Description: Shift out a bit in the data register onto GPO
; Input Parameters: Data byte
; Input Parameters: bit position
; Output Parameters: none
;-------------------------------------------------------------------
WRITE_DATA_BIT	.macro Data, BitPosition
	WAIT_SCL_LOW_SINGLE
	QBBS	set_output_bit_high?, Data, BitPosition
	CLR	R30, R30, g_D1OutPin
	JMP	data_bit_write_done?
set_output_bit_high?:
	SET	R30, R30, g_D1OutPin
data_bit_write_done?:
	CHECK_CS_ERROR
	WAIT_SCL_HIGH_SINGLE
	.endm

DELAY .macro
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	.endm

;-------------------------------------------------------------------
; Macro Name: JMP_TO_STATE
; Description: Jump to a state based on the indexx
; Input Parameters: Data byte
; Input Parameters: bit position
; Output Parameters: none
;-------------------------------------------------------------------
;; JMP_TO_STATE	.macro Idx
;; 	LBBO	&r_NextState.w0, r_StateTableBase, Idx, 2
;; 	JMP 	r_NextState.w0
;; 	.endm

JMP_TO_STATE	.macro Idx
	JMP 	Idx
	.endm





;-------------------------------------------------------------------
; Macro Name: READ_DUAL_BITS0
; Description: read two data bits, shift into Data register
; Input Parameters: bit position
; Output Parameters: register to read data
;-------------------------------------------------------------------
READ_DUAL_BITS0	.macro Data
	WAIT_SCL_HIGH_DUAL
	AND	r_Temp0, R31, r_DualDataMask
	SHIFT_DUAL_0	r_Temp0, r_Temp0, g_DualShiftAmt0
	OR	Data, Data, r_Temp0.b0
	CHECK_CS_ERROR
	WAIT_SCL_LOW_DUAL
	.endm

;-------------------------------------------------------------------
; Macro Name: READ_DUAL_BITS1
; Description: read two data bits, shift into Data register
; Input Parameters: bit position
; Output Parameters: register to read data
;-------------------------------------------------------------------
READ_DUAL_BITS1	.macro Data
	WAIT_SCL_HIGH_DUAL
	AND	r_Temp0, R31, r_DualDataMask
	SHIFT_DUAL_1	r_Temp0, r_Temp0, g_DualShiftAmt1
	OR	Data, Data, r_Temp0.b0
	CHECK_CS_ERROR
	WAIT_SCL_LOW_DUAL
	.endm

;-------------------------------------------------------------------
; Macro Name: READ_DUAL_BITS2
; Description: read two data bits, shift into Data register
; Input Parameters: bit position
; Output Parameters: register to read data
;-------------------------------------------------------------------
READ_DUAL_BITS2	.macro Data
	WAIT_SCL_HIGH_DUAL
	AND	r_Temp0, R31, r_DualDataMask
	SHIFT_DUAL_2	r_Temp0, r_Temp0, g_DualShiftAmt2
	OR	Data, Data, r_Temp0.b0
	CHECK_CS_ERROR
	WAIT_SCL_LOW_DUAL
	.endm

;-------------------------------------------------------------------
; Macro Name: READ_DUAL_BITS3
; Description: read two data bits, shift into Data register
; Input Parameters: bit position
; Output Parameters: register to read data
;-------------------------------------------------------------------
READ_DUAL_BITS3	.macro Data
	WAIT_SCL_HIGH_DUAL
	AND	r_Temp0, R31, r_DualDataMask
	SHIFT_DUAL_3	r_Temp0, r_Temp0, g_DualShiftAmt3
	OR	Data, Data, r_Temp0.b0
	CHECK_CS_ERROR
	WAIT_SCL_LOW_DUAL
	.endm

;-------------------------------------------------------------------
; Macro Name: READ_QUAD_BITS0
; Description: read two data bits, shift into Data register
; Input Parameters: bit position
; Output Parameters: register to read data
;-------------------------------------------------------------------
READ_QUAD_BITS0	.macro Data
	WAIT_SCL_HIGH_QUAD
	AND	r_Temp0, R31, r_QuadDataMask
	SHIFT_QUAD_0	r_Temp0, r_Temp0, g_QuadShiftAmt0
	OR	Data, Data, r_Temp0.b0
	CHECK_CS_ERROR
	WAIT_SCL_LOW_QUAD
	.endm

;-------------------------------------------------------------------
; Macro Name: READ_QUAD_BITS1
; Description: read two data bits, shift into Data register
; Input Parameters: bit position
; Output Parameters: register to read data
;-------------------------------------------------------------------
READ_QUAD_BITS1	.macro Data
	WAIT_SCL_HIGH_QUAD
	AND	r_Temp0, R31, r_QuadDataMask
	SHIFT_QUAD_1	r_Temp0, r_Temp0, g_QuadShiftAmt1
	OR	Data, Data, r_Temp0.b0
	CHECK_CS_ERROR
	WAIT_SCL_LOW_QUAD
	.endm

CLEAR_WRITE_BITS .macro
	NOP
	.endm
	
	
	.endif  ;__eSPI_bitbang_h
