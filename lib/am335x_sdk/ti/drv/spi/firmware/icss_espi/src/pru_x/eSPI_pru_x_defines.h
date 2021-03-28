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
; file:   eSPI_pru_x_defines.h
;
; brief:  This files contains all register and constant definitions for PRUX
;
;
;  (C) Copyright 2018, Texas Instruments, Inc
;
;

	.if    !$defined("__eSPI_pru_x_defines_h")
__eSPI_pru_x_defines_h    .set 1

;;; INCLUDES ;;;
	.include "eSPI_common.h"
	
;;; C INCLUDES ;;;
	.cdecls C, NOLIST, "icss_espi.h"

;;; REGISTER DEFINES ;;;
	
	;; R0-R3 are resevered for Inter-PRU Comm registers
	
	;; Named PRU-BB registers
	.asg R4,	r_StateTableBase
	.asg R5,	r_Temp2
        .asg R6,	r_SlaveRegistersBase
        .asg R7,	r_CurrStatusReg
        .asg R8,	r_PrevStatusReg
	.asg R9,	r_GpoDefault
	.asg R10,	r_Temp0
	.asg R11,	r_Temp1
	.asg R12,	r_QuadClearMask
	.asg R13,	r_DualClearMask
	.asg R14,	r_DualDataMask
	.asg R15,	r_QuadDataMask
	     
	
;;; PRU X STATE INDEX DEFINES ;;;
g_ResetStateIdx	.set	0x0000
g_ReadyStateIdx	.set	0x0001    
g_ReadStateIdx	.set	0x0002    
g_WriteStateIdx	.set	0x0003    
g_EndStateIdx	.set	0x0004    

;;; R30 Pins
g_D0OutPin	.set	ESPI_D0_OUT_PIN_NUM
g_D1OutPin	.set	ESPI_D1_OUT_PIN_NUM
g_D2OutPin	.set	ESPI_D2_OUT_PIN_NUM
g_D3OutPin	.set	ESPI_D3_OUT_PIN_NUM
g_AlertPin	.set	ESPI_ALERT_PIN_NUM
g_EnPin		.set	ESPI_EN_PIN_NUM
	
;;; R31 Pins
g_D0InPin	.set	ESPI_D0_IN_PIN_NUM
g_D1InPin	.set	ESPI_D1_IN_PIN_NUM
g_D2InPin	.set	ESPI_D2_IN_PIN_NUM
g_D3InPin	.set	ESPI_D3_IN_PIN_NUM
g_SclPin	.set	ESPI_SCL_PIN_NUM
g_CsPin		.set	ESPI_CS_PIN_NUM

;;; Calculate pin masks for Dual/Quad mode
g_DualDataMask	.set	0x3 << g_D0InPin
g_QuadDataMask	.set	0xF << g_D0InPin

g_DualWriteMask3	.set	0x3 << 6
g_DualWriteMask2	.set	0x3 << 4
g_DualWriteMask1	.set	0x3 << 2
g_DualWriteMask0	.set	0x3 << 0

g_QuadWriteMask1	.set	0xF << 4
g_QuadWriteMask0	.set	0xF << 0

g_DualClearMask_inv	.set	(0x3 << g_D0OutPin) ; Annoyingly the pre-processor won't support ~
g_QuadClearMask_inv	.set	(0xF << g_D0OutPin) ; Annoyingly the pre-processor won't support ~

;;; Calculate Dual/Quad mode READ shifting
	;; First
	.if	0 - g_D0InPin < 0
SHIFT_DUAL_0	.set	LSR
SHIFT_QUAD_0	.set	LSR
g_DualShiftAmt0	.set	g_D0InPin - 0
g_QuadShiftAmt0	.set	g_D0InPin - 0
	.else
SHIFT_DUAL_0	.set	LSL
SHIFT_QUAD_0	.set	LSL
g_DualShiftAmt0	.set	0 - g_D0InPin
g_QuadShiftAmt0	.set	0 - g_D0InPin
	.endif

	.if	2 - g_D0InPin < 0
SHIFT_DUAL_1	.set	LSR
g_DualShiftAmt1	.set	g_D0InPin - 2
	.else
SHIFT_DUAL_1	.set	LSL
g_DualShiftAmt1	.set	2 - g_D0InPin
	.endif

	.if	4 - g_D0InPin < 0
SHIFT_DUAL_2	.set	LSR
SHIFT_QUAD_1	.set	LSR
g_DualShiftAmt2	.set	g_D0InPin - 4
g_QuadShiftAmt1	.set	g_D0InPin - 4
	.else
SHIFT_DUAL_2	.set	LSL
SHIFT_QUAD_1	.set	LSL
g_DualShiftAmt2	.set	4 - g_D0InPin
g_QuadShiftAmt1	.set	4 - g_D0InPin
	.endif

	.if	6 - g_D0InPin < 0
SHIFT_DUAL_3	.set	LSR
g_DualShiftAmt3	.set	g_D0InPin - 6
	.else
SHIFT_DUAL_3	.set	LSL
g_DualShiftAmt3	.set	6 - g_D0InPin
	.endif

;;; Calculate Dual/Quad mode WRITE shifting
	;; First
	.if	0 - g_D0OutPin < 0
SHIFT_DUAL_WRITE_0	.set	LSL
SHIFT_QUAD_WRITE_0	.set	LSL
g_DualWriteShiftAmt0	.set	g_D0OutPin - 0
g_QuadWriteShiftAmt0	.set	g_D0OutPin - 0
	.else
SHIFT_DUAL_WRITE_0	.set	LSR
SHIFT_QUAD_WRITE_0	.set	LSR
g_DualWriteShiftAmt0	.set	0 - g_D0OutPin
g_QuadWriteShiftAmt0	.set	0 - g_D0OutPin
	.endif

	.if	2 - g_D0OutPin < 0
SHIFT_DUAL_WRITE_1	.set	LSL
g_DualWriteShiftAmt1	.set	g_D0OutPin - 2
	.else
SHIFT_DUAL_WRITE_1	.set	LSR
g_DualWriteShiftAmt1	.set	2 - g_D0OutPin
	.endif

	.if	4 - g_D0OutPin < 0
SHIFT_DUAL_WRITE_2	.set	LSL
SHIFT_QUAD_WRITE_1	.set	LSL
g_DualWriteShiftAmt2	.set	g_D0OutPin - 4
g_QuadWriteShiftAmt1	.set	g_D0OutPin - 4
	.else
SHIFT_DUAL_WRITE_2	.set	LSR
SHIFT_QUAD_WRITE_1	.set	LSR
g_DualWriteShiftAmt2	.set	4 - g_D0OutPin
g_QuadWriteShiftAmt1	.set	4 - g_D0OutPin
	.endif

	.if	6 - g_D0OutPin < 0
SHIFT_DUAL_WRITE_3	.set	LSL
g_DualWriteShiftAmt3	.set	g_D0OutPin - 6
	.else
SHIFT_DUAL_WRITE_3	.set	LSR
g_DualWriteShiftAmt3	.set	6 - g_D0OutPin
	.endif


	.endif  ;__eSPI_pru_y_defines_h
