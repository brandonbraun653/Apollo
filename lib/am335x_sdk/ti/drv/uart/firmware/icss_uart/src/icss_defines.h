; 
; Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
; 
; 
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
; 
;        * Redistributions of source code must retain the above copyright
;          notice, this list of conditions and the following disclaimer.
; 
;        * Redistributions in binary form must reproduce the above copyright
;          notice, this list of conditions and the following disclaimer in the
;          documentation and/or other materials provided with the
;          distribution.
; 
;        * Neither the name of Texas Instruments Incorporated nor the names of
;          its contributors may be used to endorse or promote products derived
;          from this software without specific prior written permission.
; 
; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
; "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
; LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
; A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
; OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
; SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
; LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
; DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
; THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
; (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
; OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
; 

; file:   icss_defines.h
;
; brief:  ICSS Global Defines
;
	
    .if    !$defined("__icss_defines_h")
__icss_defines_h    .set 1
	
; Bank ids for Xfer instructions
BANK0                 .set    10
BANK1                 .set    11
BANK2                 .set    12
    
; Constants need to be defined with correct offset before using. Typically done on HOST side.
    .asg    c0,     ICSS_INTC_CONST
    .asg    c26,    ICSS_IEP_CONST
    .asg    c4,     ICSS_CFG_CONST
    .asg    c24,    PRU0_DMEM_CONST
    .asg    c25,    PRU1_DMEM_CONST
    .asg    c28,    ICSS_SHARED_CONST

    .asg    R24.w2, CALL_REG    
    .asg    R24.w0, L1_CALL_REG   

; PRU-ICSS Control Regs
ICSS_PRU0_CTRL_LOCAL    .set    (0x00022000U)   ; PRU0
ICSS_PRU1_CTRL_LOCAL    .set    (0x00024000U)   ; PRU1

; PRU-ICSS IEP Regs
ICSS_IEP_LOCAL          .set    (0x0002e000U)

; PRU-ICSS Ext Port
ICSS_EXT_PORT_LOCAL     .set    (0x00040000U)


    .endif	;__icss_defines_h
