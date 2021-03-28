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
;  manufactured by or for TI (“TI Devices”).  No hardware patent is licensed hereunder.
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
;  THIS SOFTWARE IS PROVIDED BY TI AND TI’S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED 
;  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
;  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI’S 
;  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
;  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
;  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
;  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
;  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
;  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 
; file:   eSPI_common.h
;
; brief:  This files contains all register and constant definitions for PRUX
;
;
;  (C) Copyright 2018, Texas Instruments, Inc
;
;

	.if    !$defined("__eSPI_common_h")
__eSPI_common_h    .set 1

		;; Inter-PRU registers
g_IpcRegsLen	.set	8
	.asg R0,	r_IpcRegs
	.asg R0.b0,	r_Data
	.asg R1.w0,	r_Count
	.asg R1.w2,	r_Flags
	.asg R2,	r_NextState
	.asg R3,	r_StatusReg


;;; RESPONSE CODES
g_AcceptResponseCode		.set 0x08 ; NO MODIFIER SUPPORT
g_DeferResponseCode		.set 0x01 ; NO MODIFIER SUPPORT
g_FatalErrorResponseCode	.set 0x03	
g_NonFatalErrorResponseCode	.set 0x02
g_WaitStateResponseCode		.set 0x0F

;; SHARED MEMORY ADDRESS
g_SharedMemoryBaseAddr	.set	0x00010000	
	
;; DEFAULT REGISTER VALUES
g_DefaultStatusRegVal	.set	0x0000030F	

	;; PRU-BB State Addresses
g_ReadyState	.set	0x2
g_EndState	.set	0x4
g_ReadState	.set	0x6
g_WriteState	.set	0xC
g_TarState	.set	0x12	
;----------------------------------------------------------------------
; Macro Name: LDI32
; Description: Load a 32bit value to a register
; Input Parameters: Register1 and Value
; Output Parameters: none
;----------------------------------------------------------------------
LDI32    .macro    arg1, arg2               
	ldi     arg1.w0, (arg2 & 0xFFFF)
	ldi     arg1.w2, (arg2 >> 16)
	.endm

;----------------------------------------------------------------------
; Macro Name: WRITE_IPC_REGS
; Description: Write out the IPC registers to the scratchpad
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
WRITE_IPC_REGS    .macro
	XOUT	BANK0, &r_IpcRegs, g_IpcRegsLen
	.endm

;----------------------------------------------------------------------
; Macro Name: READ_IPC_REGS
; Description: Read the IPC registers from the scratchpad
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
READ_IPC_REGS    .macro
	XIN	BANK0, &r_IpcRegs, g_IpcRegsLen
	.endm
	

	.endif  ;__eSPI_common_h	
