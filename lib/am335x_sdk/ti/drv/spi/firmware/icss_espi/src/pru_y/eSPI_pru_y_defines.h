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
;  manufactured by or for TI (" Devices”)"No hardware patent is licensed hereunder.
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
;  THIS SOFTWARE IS PROVIDED BY TI AND TI'LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED 
;  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
;  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI'
;  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
;  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
;  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
;  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
;  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
;  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 
; file:   eSPI_pru_y_defines.h
;
; brief:  This files contains all register and constant definitions for PRU Y
;
;
;  (C) Copyright 2018, Texas Instruments, Inc
;
;
	.if    !$defined("__eSPI_pru_y_defines_h")
__eSPI_pru_y_defines_h    .set 1

	.cdecls C, NOLIST, "icss_espi.h"
	.include "eSPI_common.h"

	
;;; REGISTER DEFINES ;;;
	;; R0-R3 are resevered for Inter-PRU Comm registers
	;; Inter-PRU registers
	.asg R0.b0,	r_PruXData
	.asg R1.w0,	r_PruXCount
	.asg R1.w2,	r_Flags
	.asg R2,	r_PruXState
	.asg R3,	r_StatusReg

	;; Named PRU-CC registers
	.asg R4,	r_CrcTableBase
	.asg R5,	r_CmdTableBase
	.asg R6,	r_StateTableBase
	.asg R7,	r_SharedMemoryBase
	.asg R8,	r_LinkReg
	.asg R9.w0,	r_Cmd
	.asg R9.w2,	r_Mode
	.asg R10,	r_DeviceId
	.asg R11,	r_GeneralCapCon
	.asg R12,	r_Ch0CapCon
	.asg R13.b0,	r_CrcCalc
	.asg R13.w2,	r_PruYCount


	.asg R14,	r_Tmp0


	;; General Purpose PRU-CC registers
	.asg R15,	r_Work0
	.asg R16,	r_Work1
	.asg R17,	r_Work2
	.asg R18,	r_Work3
	.asg R19,	r_Work4
	.asg R20,	r_Work5
	.asg R21,	r_Work6
	.asg R22,	r_Work7
	.asg R23,	r_Work8
	.asg R24,	r_Work9
	.asg R25,	r_Work10
	.asg R26,	r_Work11
	.asg R27,	r_Zero
	.asg R28,	r_Tmp1
	.asg R29,	r_Tmp2
	
;;; PRU X STATE INDEX DEFINES ;;;
g_StartStateIdx	.set	0x0000
g_WaitStateIdx	.set	0x0001
g_ReadStateIdx	.set	0x0002
g_TarStateIdx	.set	0x0003
g_WriteStateIdx	.set	0x0004
g_EndStateIdx	.set	0x0005
	
	.endif  ;__eSPI_pru_y_defines_h
