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
; file:   eSPI_cmd.asm
;
; brief:  This files contains the protocol control logic
;
;
;  (C) Copyright 2018, Texas Instruments, Inc
;
;
	
;;; INCLUDES ;;;
	.include "crc.h"
	.include "icss_defines.h"
	.include "eSPI_control.h"
	.include "eSPI_cmd.h"
	.include "eSPI_pru_y_defines.h"
	.include "eSPI_slave_registers.h"

;;; GLOBAL DEFINES
        .global PRU_Y_START
	.global RESET_STATE
	.global	READY_STATE
	.global main

	.sect    ".text:PRU_Y_START"
;-------------------------------------------------------------------
; Subroutine: INIT_ESPI_CONTROL
; Description: Initialize all eSPI PRU X registers
;-------------------------------------------------------------------	
PRU_Y_START:
RESET_STATE:
	;; Clear registers
    	ZERO	&R0, 124

	;; Setup tables
	INIT_CRC_TABLE
	INIT_CMD_TABLE

	;; Setup shared data
	INIT_SHARED_MEMORY
	RESET_SLAVE_REGISTERS
	RESET_STATUS_REGISTER
	RESET_INTERNAL_SLAVE_REGISTERS

	LDI	 r_Mode, 0x0

;; 	;; TEST
;; 	LDI	r_Work0.b0, ESPI_PACKET_MAGIC_NUMBER
;; 	LDI	r_Work0.w1, 0x5
;; 	LDI	r_Work0.b3, 0x40
;; 	LDI	r_Work1.b0, 0x01
;; 	LDI	r_Work1.b1, 0x02
;; 	LDI	r_Work1.b2, 0x03
;; 	LDI	r_Work1.b3, 0x04
;; 	SBBO	&r_Work0, r_SharedMemoryBase, CH0_NP_RX_BUFFER_BASE, 9		
;; 	LBBO	&R15, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4
;; 	CLR	R15, R15, STATUS_NP_FREE_BIT
;; 	SBBO	&R15, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4

;; 	SET_IPC_MESSAGE	ICSS_ESPI_IPC_MSG_RX_AVAIL
;; 	RAISE_INTERRUPT_FOR_HOST
;; freeze:	
;; 	JMP freeze
;; 	;; TEST
	
;; wait_channel_enable:
;; 	LBBO &r_Work0, r_SharedMemoryBase, CHAN0_CAP_CON_REGISTER_BASE, 4
;; 	QBBC wait_channel_enable, r_Work0, 0

	
;-------------------------------------------------------------------
; Subroutine: READY_STATE
; Description: Read the first byte and jump to the proper CMD handler accordingly
;-------------------------------------------------------------------	
READY_STATE:
	;; Reset IPC registers
	ZERO	&r_PruXData, 12
	
	SET_PRU_BB_STATE	g_ReadState, r_Mode
	READ_BYTE	r_PruXData
	
	;; Read Status Register
	LBBO	&r_StatusReg, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4

	;; Read CMD handler address
	LSL	r_Work0.w0, r_PruXData, 1	; the CMD table has 2-byte entries
	LBBO	&r_Cmd, r_CmdTableBase, r_Work0.w0, 2

	;; Jump to CMD handler
	JMP	r_Cmd
