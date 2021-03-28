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
; file:   eSPI_state_table.h
;
; brief:  This files contains the state table jump locations
;
;
;  (C) Copyright 2018, Texas Instruments, Inc
;
;

	.if    !$defined("__eSPI_state_table_h")
__eSPI_state_table_h    .set 1

;;; INCLUDES ;;;
	.include "eSPI_pru_x_defines.h"

;;; GLOBAL REFS ;;;
	
	.global RESET_STATE
	.global READY_STATE
	.global END_STATE
	
	.global READ_STATE_SINGLE
	.global TAR_AND_WAIT_STATE_SINGLE
	.global WRITE_STATE_SINGLE
	.global READ_STATE_DUAL
	.global TAR_AND_WAIT_STATE_DUAL
	.global WRITE_STATE_DUAL
	.global READ_STATE_QUAD
	.global TAR_AND_WAIT_STATE_QUAD
	.global WRITE_STATE_QUAD

;;; MACROS ;;;
;-------------------------------------------------------------------
; Macro Name: INIT_STATE_TABLE
; Description: set up the global state table register
; Input Parameters: none
; Output Parameters: none
;-------------------------------------------------------------------
INIT_STATE_TABLE	.macro
	LDI	r_StateTableBase,	||espi_state_table||
	.endm

;;; DATA ;;;
;-------------------------------------------------------------------
; Table Name: espi_state_table
; Description: Bit-bang states. Empty table entries are to allow for
;	       easier indexing based on Single/Dual/Quad mode codes 
;	       (used as bits 3-4 in the index register)
;-------------------------------------------------------------------
	.data
	.clink
	.align  1
||espi_state_table||:
	.uhalf   $CODE(RESET_STATE)             ; espi_state_table[0x0] 
	.uhalf   $CODE(READY_STATE)             ; espi_state_table[0x1]
	.uhalf   $CODE(READ_STATE_SINGLE)	; espi_state_table[0x2]
	.uhalf   $CODE(TAR_AND_WAIT_STATE_SINGLE)        ; espi_state_table[0x3]
	.uhalf   $CODE(WRITE_STATE_SINGLE)      ; espi_state_table[0x4]
	.uhalf   $CODE(END_STATE)               ; espi_state_table[0x5]
	.uhalf   0x0000				; espi_state_table[0x6]
	.uhalf   0x0000				; espi_state_table[0x7]
	.uhalf   0x0000				; espi_state_table[0x8]
	.uhalf   0x0000				; espi_state_table[0x9]
	.uhalf   0x0000				; espi_state_table[0xA]
	.uhalf   0x0000				; espi_state_table[0xB]
	.uhalf   0x0000				; espi_state_table[0xC]
	.uhalf   0x0000				; espi_state_table[0xD]
	.uhalf   0x0000				; espi_state_table[0xE]
	.uhalf   0x0000				; espi_state_table[0xF]
	.uhalf   $CODE(RESET_STATE)             ; espi_state_table[0x10] 
	.uhalf   $CODE(READY_STATE)             ; espi_state_table[0x11]
	.uhalf   $CODE(READ_STATE_DUAL)		; espi_state_table[0x12]
	.uhalf   $CODE(TAR_AND_WAIT_STATE_DUAL)	; espi_state_table[0x13]
	.uhalf   $CODE(WRITE_STATE_DUAL)	; espi_state_table[0x14]
	.uhalf   $CODE(END_STATE)               ; espi_state_table[0x15]
	.uhalf   0x0000				; espi_state_table[0x16]
	.uhalf   0x0000				; espi_state_table[0x17]
	.uhalf   0x0000				; espi_state_table[0x18]
	.uhalf   0x0000				; espi_state_table[0x19]
	.uhalf   0x0000				; espi_state_table[0x1A]
	.uhalf   0x0000				; espi_state_table[0x1B]
	.uhalf   0x0000				; espi_state_table[0x1C]
	.uhalf   0x0000				; espi_state_table[0x1D]
	.uhalf   0x0000				; espi_state_table[0x1E]
	.uhalf   0x0000				; espi_state_table[0x1F]
	.uhalf   $CODE(RESET_STATE)             ; espi_state_table[0x20] 
	.uhalf   $CODE(READY_STATE)             ; espi_state_table[0x21]
	.uhalf   $CODE(READ_STATE_QUAD)		; espi_state_table[0x22]
	.uhalf   $CODE(TAR_AND_WAIT_STATE_QUAD) ; espi_state_table[0x23]
	.uhalf   $CODE(WRITE_STATE_QUAD)	; espi_state_table[0x24]
	.uhalf   $CODE(END_STATE)               ; espi_state_table[0x25]
	.uhalf   0x0000				; espi_state_table[0x26]
	.uhalf   0x0000				; espi_state_table[0x27]
	.uhalf   0x0000				; espi_state_table[0x28]
	.uhalf   0x0000				; espi_state_table[0x29]
	.uhalf   0x0000				; espi_state_table[0x2A]
	.uhalf   0x0000				; espi_state_table[0x2B]
	.uhalf   0x0000				; espi_state_table[0x2C]
	.uhalf   0x0000				; espi_state_table[0x2D]
	.uhalf   0x0000				; espi_state_table[0x2E]
	.uhalf   0x0000				; espi_state_table[0x2F]

	

	.endif  ;__eSPI_state_table_h
