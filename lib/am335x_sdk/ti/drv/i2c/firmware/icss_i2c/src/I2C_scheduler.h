;
;  TEXAS INSTRUMENTS TEXT FILE LICENSE
; 
;  Copyright (c) 2017-2018 Texas Instruments Incorporated
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
; file:   I2C_scheduler.h
;
; brief:  Round-robin based I2C_scheduler which controls program flow.
;
;
;  (C) Copyright 2017-2018, Texas Instruments, Inc
;
;

    .if    !$defined("__I2C_scheduler_h")
__I2C_scheduler_h    .set 1

    .include "icss_defines.h"
    .include "icss_iep_regs.h"
    .include "icss_intc_regs.h"
    .include "icss_cfg_regs.h"
    .include "icss_ctrl_regs.h"
    .cdecls C,NOLIST
%{
#include "icss_i2c.h"
%}

                        .if $defined("AM437X_ICSS0")                        
                        .global PRU_TMP_CTXT
TMP_CTXT_SZ             .set    8
                        .endif


;----------------------------------------------------------------------
; List of register used for intermediate purpose during a state. These
; registers are used in all source code of PRUSS FW.
; WORK_REG_1-8: is used for storing register offset, temporary loading
; of data, etc.
; IEP_COUNTER_NEXT_VAL1-2: is used for storing the initial counter 
; value of IEP timer during FW boot.
; I2C_GLOBAL_FREQ_REG: decides the global baud rate of I2C FW.
;----------------------------------------------------------------------

    .asg    R1, WORK_REG_1
    .asg    R2, WORK_REG_2
    .asg    R3, WORK_REG_3
    .asg    R4, WORK_REG_4
    .asg    R5, WORK_REG_5
    .asg    R6, WORK_REG_6
    .asg    R7, WORK_REG_7
    .asg    R8, WORK_REG_8
    .asg    R20, IEP_COUNTER_NEXT_VAL1
    .asg    R21, IEP_COUNTER_NEXT_VAL2
    .asg    R22, I2C_GLOBAL_FREQ_REG


PRU0_IEP_CMP_REG                    .set    ICSS_IEP_CMP0_REG
PRU1_IEP_CMP_REG                    .set    ICSS_IEP_CMP1_REG
PRU0_IEP_CMP_ENABLE_BIT             .set    1
PRU1_IEP_CMP_ENABLE_BIT             .set    2
PRU0_IEP_CMP_STATUS_BIT             .set    0
PRU1_IEP_CMP_STATUS_BIT             .set    1


;----------------------------------------------------------------------
; Macro Name: MOV32
; Description: Move a 32bit value to a register
; Input Parameters: Register1 and Value
; Output Parameters: none
;----------------------------------------------------------------------
MOV32    .macro    arg1, arg2               
    ldi     arg1.w0, (arg2 & 0xFFFF)
    ldi     arg1.w2, (arg2 >> 16)
    .endm

;----------------------------------------------------------------------
; Macro Name: DELAY
; Description: ADD a delay of N cycles.
; Input Parameters: Register1
; Output Parameters: none
;----------------------------------------------------------------------
DELAY    .macro    arg1
    ;do nothing for arg1 instructions
    loop delay_loop?, arg1
    ADD R0, R0, 0
    ADD R1, R1, 0
delay_loop?:
    .endm

;----------------------------------------------------------------------
; Macro Name: ENABLE_XIN_XOUT_SHITFTING
; Description: ADD a delay of N cycles.
; Input Parameters: Register1
; Output Parameters: none
;----------------------------------------------------------------------
ENABLE_XIN_XOUT_SHITFTING    .macro
    LBCO    &WORK_REG_1, ICSS_CFG_CONST, ICSS_CFG_SPP, 4
    OR      WORK_REG_1.b0, WORK_REG_1.b0, 0x02
    SBCO    &WORK_REG_1, ICSS_CFG_CONST, ICSS_CFG_SPP, 4
    .endm

;----------------------------------------------------------------------
; Macro Name: I2C_SETUP_IEP_COUNTER
; Description: Setup the IEP timer counter for periodic interrupt.
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
I2C_SETUP_IEP_COUNTER     .macro
    ;read IEP Timer enabled or not
    LBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_CFG_REG, 4
    QBBS    iep_counter_setup_done?, WORK_REG_1 , 0

    ;Reset the Counter value
    .if $defined("ICSS_REV1")
    LBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 4
    MOV32   WORK_REG_1 , 0xFFFFFFFF
    SBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 4
    .endif  ;ICSS_REV1
    .if $defined("ICSS_REV2")
    LBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 8
    MOV32   WORK_REG_1 , 0xFFFFFFFF
    MOV32   WORK_REG_2 , 0xFFFFFFFF
    SBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 8
    .endif  ;ICSS_REV2

    ;Clear overflow status register
    LBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_STATUS_REG, 4
    SET     WORK_REG_1 , WORK_REG_1 , 0
    SBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_STATUS_REG, 4

    ;Clear compare status
    LBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 4
    LDI     WORK_REG_1.w0 , 0xFFFF
    SBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 4

    ;Enable IEP counter
    LBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_CFG_REG, 4
    SET     WORK_REG_1 , WORK_REG_1 , 0
    SBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_CFG_REG, 4

iep_counter_setup_done?:
    ;Set compare values
    .if $defined("ICSS_REV1")
    LDI     WORK_REG_3.w0, ICSS_I2C_CONFIG_MEMORY
    LBCO    &IEP_COUNTER_NEXT_VAL1, PRU0_DMEM_CONST, WORK_REG_3.w0, 4
    LBCO    &WORK_REG_2, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 4
loop1?:    
    ADD     IEP_COUNTER_NEXT_VAL1, IEP_COUNTER_NEXT_VAL1, I2C_GLOBAL_FREQ_REG.w2
    QBGT    loop1?, IEP_COUNTER_NEXT_VAL1, WORK_REG_2
    ADD     IEP_COUNTER_NEXT_VAL1, IEP_COUNTER_NEXT_VAL1, I2C_GLOBAL_FREQ_REG.w2
    SBCO    &IEP_COUNTER_NEXT_VAL1, ICSS_IEP_CONST, PRU0_IEP_CMP_REG, 4
    .endif  ;ICSS_REV1
    
    .if $defined("ICSS_REV2")
    LDI     WORK_REG_3.w0, ICSS_I2C_CONFIG_MEMORY
    LBCO    &IEP_COUNTER_NEXT_VAL1, PRU0_DMEM_CONST, WORK_REG_3.w0, 8
    LBCO    &WORK_REG_2, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 8
loop3?:
    ADD     IEP_COUNTER_NEXT_VAL1, IEP_COUNTER_NEXT_VAL1, I2C_GLOBAL_FREQ_REG.w2
    ADC     IEP_COUNTER_NEXT_VAL2, IEP_COUNTER_NEXT_VAL2, 0x00
    QBGT    loop3?, IEP_COUNTER_NEXT_VAL2, WORK_REG_3
    QBLT    loop4?, IEP_COUNTER_NEXT_VAL2, WORK_REG_3
    QBGT    loop3?, IEP_COUNTER_NEXT_VAL1, WORK_REG_2
loop4?:
    ADD     IEP_COUNTER_NEXT_VAL1, IEP_COUNTER_NEXT_VAL1, I2C_GLOBAL_FREQ_REG.w2
    ADC     IEP_COUNTER_NEXT_VAL2, IEP_COUNTER_NEXT_VAL2, 0x00
    SBCO    &IEP_COUNTER_NEXT_VAL1, ICSS_IEP_CONST, PRU0_IEP_CMP_REG, 8
    .endif  ;ICSS_REV2

    ;Enable compare events
    .if $defined("PRU0")
    ZERO    &WORK_REG_1, 4
    SET     WORK_REG_1, WORK_REG_1, PRU0_IEP_CMP_ENABLE_BIT
    SBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4
    .endif  ;PRU0

    .if $defined("PRU1")
    ZERO    &WORK_REG_1, 4
    SET     WORK_REG_1, WORK_REG_1, PRU1_IEP_CMP_ENABLE_BIT
    SBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4
    .endif  ;PRU1

    .endm

;----------------------------------------------------------------------
; Macro Name: I2C_SETUP_IEP_DIGIO
; Description: Setup the IEP timer counter for periodic interrupt.
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
I2C_SETUP_IEP_DIGIO     .macro
    ;initialize the ICSS_IEP_DIGIO_EXP_REG register
    LDI     WORK_REG_1.w0, 0x0007
    LDI     WORK_REG_2.b1, ICSS_IEP_DIGIO_BLK_INDEX
    LDI     WORK_REG_2.b0, ICSS_IEP_DIGIO_EXP_REG    
    .if !$defined("AM437X_ICSS0")
    ; read Local ICSS IEP register
    LBCO    &WORK_REG_3, ICSS_IEP_CONST, WORK_REG_2.w0 , 4
    .else
    ; read Other ICSS IEP register
    LDI32   WORK_REG_5, ICSS_EXT_PORT_LOCAL     ; load PRU-ICSS1 Ext port address
    ADD     WORK_REG_2, WORK_REG_5, WORK_REG_2.w0
    LBCO    &WORK_REG_3, ICSS_IEP_CONST, WORK_REG_2 , 4
    .endif
    AND     WORK_REG_4.w0, WORK_REG_3.w0, WORK_REG_1.w0
    QBEQ    iep_digio_setup_finished?, WORK_REG_4.w0, WORK_REG_1.w0
    OR      WORK_REG_3.w0, WORK_REG_3.w0, WORK_REG_1.w0
    .if !$defined("AM437X_ICSS0")    
    ; Write Local ICSS IEP register
    SBCO    &WORK_REG_3, ICSS_IEP_CONST, WORK_REG_2.w0 , 4
    .else
    ; Write Other ICSS IEP register
    SBCO    &WORK_REG_3, ICSS_IEP_CONST, WORK_REG_2 , 4
    .endif

    ;initialize the PRU_ICSS_IEP_DIGIO_DATA_OUT register
    LDI     WORK_REG_1.w0, 0x0000
    LDI     WORK_REG_2.b0, ICSS_IEP_DIGIO_DATA_OUT_REG
    .if !$defined("AM437X_ICSS0")    
    ; Write Local ICSS IEP register
    SBCO    &WORK_REG_1, ICSS_IEP_CONST, WORK_REG_2.w0 , 4
    .else
    ; Write Other ICSS IEP register
    SBCO    &WORK_REG_1, ICSS_IEP_CONST, WORK_REG_2 , 4
    .endif

    ;initialize the PRU_ICSS_IEP_DIGIO_DATA_OUT_EN register
    LDI     WORK_REG_1.w0, 0xFFFF
    LDI     WORK_REG_2.b0, ICSS_IEP_DIGIO_DATA_OUT_EN_REG
    .if !$defined("AM437X_ICSS0")    
    ; Write Local ICSS IEP register
    SBCO    &WORK_REG_1, ICSS_IEP_CONST, WORK_REG_2.w0 , 4
    .else
    SBCO    &WORK_REG_1, ICSS_IEP_CONST, WORK_REG_2 , 4
    .endif

iep_digio_setup_finished?:
    .endm


;----------------------------------------------------------------------
; Macro Name: I2C_IEP_INTC_CLEAR_EVENT
; Description: Clear the iep cmp event and intc event for Standard/Full mode
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
I2C_IEP_INTC_CLEAR_EVENT    .macro    arg1
    ; clear the IEP compare event happened
    LBCO   &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 4
    .if $defined("PRU0")
    QBBS    iep_intc_clear?, WORK_REG_1, PRU0_IEP_CMP_STATUS_BIT
    JMP     arg1
    .else
    QBBS    iep_intc_clear?, WORK_REG_1, PRU1_IEP_CMP_STATUS_BIT
    JMP     arg1
    .endif
iep_intc_clear?:
    .if $defined("FW_DEBUG")
    LBBO    &WORK_REG_6, R25, 0x00, 4
    CLR     WORK_REG_6, WORK_REG_6, 3
    SBBO    &WORK_REG_6, R25, 0x00, 4
    MOV32   WORK_REG_6, 0x00000000
    SBBO    &WORK_REG_6, R25, 0x0C, 4
    LBBO    &WORK_REG_6, R25, 0x00, 4
    SET     WORK_REG_6, WORK_REG_6, 3
    SBBO    &WORK_REG_6, R25, 0x00, 4
    .endif  ;FW_DEBUG

    LDI    WORK_REG_1.w0, 0x0000
    .if $defined("PRU0")
    SET    WORK_REG_1, WORK_REG_1, PRU0_IEP_CMP_STATUS_BIT
    .else
    SET    WORK_REG_1, WORK_REG_1, PRU1_IEP_CMP_STATUS_BIT
    .endif
    SBCO   &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 4

    ;Set compare values
    .if $defined("ICSS_REV1")
    ADD     IEP_COUNTER_NEXT_VAL1, IEP_COUNTER_NEXT_VAL1, I2C_GLOBAL_FREQ_REG.w2

    .if $defined("PRU0")
    SBCO    &IEP_COUNTER_NEXT_VAL1, ICSS_IEP_CONST, PRU0_IEP_CMP_REG, 4
    .endif  ;PRU0

    .if $defined("PRU1")
    SBCO    &IEP_COUNTER_NEXT_VAL1, ICSS_IEP_CONST, PRU1_IEP_CMP_REG, 4
    .endif  ;PRU1
    .endif  ;ICSS_REV1
    
    .if $defined("ICSS_REV2")
    ADD     IEP_COUNTER_NEXT_VAL1, IEP_COUNTER_NEXT_VAL1, I2C_GLOBAL_FREQ_REG.w2
    ADC     IEP_COUNTER_NEXT_VAL2, IEP_COUNTER_NEXT_VAL2, 0x00

    .if $defined("PRU0")
    SBCO    &IEP_COUNTER_NEXT_VAL1, ICSS_IEP_CONST, PRU0_IEP_CMP_REG, 8
    .endif  ;PRU0

    .if $defined("PRU1")
    SBCO    &IEP_COUNTER_NEXT_VAL1, ICSS_IEP_CONST, PRU1_IEP_CMP_REG, 8
    .endif  ;PRU1
    .endif  ;ICSS_REV2
    
    ; clear the intc interrupt event flag
    LDI    WORK_REG_1.w0, 0x0080
    LDI    WORK_REG_2.w0, ICSS_INTC_SECR0
    SBCO   &WORK_REG_1, ICSS_INTC_CONST, WORK_REG_2.w0, 4
    
    .endm

;----------------------------------------------------------------------
; Macro Name: I2C_IEP_INTC_CLEAR_EVENT1
; Description: Clear the iep cmp event and intc event for HS mode
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
I2C_IEP_INTC_CLEAR_EVENT1    .macro
    LDI    WORK_REG_1.w0, 0x0000
    .if $defined("PRU0")
    SET    WORK_REG_1, WORK_REG_1, PRU0_IEP_CMP_STATUS_BIT
    .else
    SET    WORK_REG_1, WORK_REG_1, PRU1_IEP_CMP_STATUS_BIT
    .endif
    SBCO   &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 4

    ;Set compare values
    .if $defined("ICSS_REV1")
    ADD     IEP_COUNTER_NEXT_VAL1, IEP_COUNTER_NEXT_VAL1, I2C_GLOBAL_FREQ_REG.w2

    .if $defined("PRU0")
    SBCO    &IEP_COUNTER_NEXT_VAL1, ICSS_IEP_CONST, PRU0_IEP_CMP_REG, 4
    .endif  ;PRU0

    .if $defined("PRU1")
    SBCO    &IEP_COUNTER_NEXT_VAL1, ICSS_IEP_CONST, PRU1_IEP_CMP_REG, 4
    .endif  ;PRU1
    .endif  ;ICSS_REV1
    
    .if $defined("ICSS_REV2")
    ADD     IEP_COUNTER_NEXT_VAL1, IEP_COUNTER_NEXT_VAL1, I2C_GLOBAL_FREQ_REG.w2
    ADC     IEP_COUNTER_NEXT_VAL2, IEP_COUNTER_NEXT_VAL2, 0x00

    .if $defined("PRU0")
    SBCO    &IEP_COUNTER_NEXT_VAL1, ICSS_IEP_CONST, PRU0_IEP_CMP_REG, 8
    .endif  ;PRU0

    .if $defined("PRU1")
    SBCO    &IEP_COUNTER_NEXT_VAL1, ICSS_IEP_CONST, PRU1_IEP_CMP_REG, 8
    .endif  ;PRU1
    .endif  ;ICSS_REV2
    
    ; clear the intc interrupt event flag
    LDI    WORK_REG_1.w0, 0x0080
    LDI    WORK_REG_2.w0, ICSS_INTC_SECR0
    SBCO   &WORK_REG_1, ICSS_INTC_CONST, WORK_REG_2.w0, 4

    .endm

;----------------------------------------------------------------------
; Macro Name: I2C_WAIT_FOR_IEP_CMP
; Description: wait until the IEP CMP Event triggers and interrupt
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
I2C_WAIT_FOR_IEP_CMP    .macro
wait_for_interrupt?:
    QBBC wait_for_interrupt?, R31, 31
    .endm

;----------------------------------------------------------------------
; Macro Name: I2C_WAVE_FUNCTION0
; Description: jump to the next state of i2c0 function
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
I2C_WAVE_FUNCTION0    .macro
    ; Restore I2C instance context
    .if !$defined("AM437X_ICSS0")
    ; restore context from SPAD
    ; select the bank based on PRU and reload all register
    .if $defined("PRU0")
    LDI    R0.b0, 0x14
    XIN    BANK0, &R10, 40
    .else
    LDI    R0.b0, 0x14
    XIN    BANK2, &R10, 40
    .endif

    .else   ; AM437X_ICSS0
    ; Restore context from DMEM
    LDI     R0, I2C0_CTXT
    LBBO    &R10, R0, 0, CTXT_SZ

    .endif ; AM437X_ICSS0
    
    .if $defined("FW_DEBUG")
    AND     R26, R13, R13
    .endif  ;FW_DEBUG

    ;jump and link to the next task function
    JAL    WORK_REG_3.w0, R13.w0
    
    ; Save I2C instance context
    .if !$defined("AM437X_ICSS0")
    ; save context to SPAD
    ; select the bank based on PRU and push all register
    .if $defined("PRU0")
    LDI    R0.b0, 0x14
    XOUT   BANK0, &R10, 40
    .else
    LDI    R0.b0, 0x14
    XOUT   BANK2, &R10, 40
    .endif
    
    .else    ; AM437X_ICSS0
    ; Save context to DMEM
    LDI     R0, I2C0_CTXT
    SBBO    &R10, R0, 0, CTXT_SZ
    
    .endif   ; AM437X_ICSS0
    
    .endm

;----------------------------------------------------------------------
; Macro Name: I2C_WAVE_FUNCTION1
; Description: jump to the next state of i2c1 function
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
I2C_WAVE_FUNCTION1    .macro
    ; Restore I2C instance context
    .if !$defined("AM437X_ICSS0")
    ; restore context from SPAD
    ; select the bank based on PRU and reload all register
    .if $defined("PRU0")
    LDI    R0.b0, 0x00
    XIN    BANK0, &R10, 40
    .else
    LDI    R0.b0, 0x00
    XIN    BANK2, &R10, 40
    .endif
    
    .else   ; AM437X_ICSS0
    ; Restore context from DMEM
    LDI     R0, I2C1_CTXT
    LBBO    &R10, R0, 0, CTXT_SZ    
    
    .endif  ; AM437X_ICSS0
    
    ;jump and link to the next task function
    JAL    WORK_REG_3.w0, R13.w0
    
    ; Save I2C instance context
    .if !$defined("AM437X_ICSS0")
    ; save context to SPAD
    ; select the bank based on PRU and push all register
    .if $defined("PRU0")
    LDI    R0.b0, 0x00
    XOUT   BANK0, &R10, 40
    .else
    LDI    R0.b0, 0x00
    XOUT   BANK2, &R10, 40
    .endif
    
    .else    ; AM437X_ICSS0
    ; Save context to DMEM
    LDI     R0, I2C1_CTXT
    SBBO    &R10, R0, 0, CTXT_SZ
    
    .endif   ; AM437X_ICSS0    
    .endm

;----------------------------------------------------------------------
; Macro Name: I2C_WAVE_FUNCTION2
; Description: jump to the next state of i2c2 function
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
I2C_WAVE_FUNCTION2    .macro
    ; Restore I2C instance context
    .if !$defined("AM437X_ICSS0")
    ; restore context from SPAD
    ; select the bank based on PRU and reload all register
    .if $defined("PRU0")
    LDI    R0.b0, 0x0A
    XIN    BANK0, &R10, 40
    .else
    LDI    R0.b0, 0x0A
    XIN    BANK2, &R10, 40
    .endif
    
    .else   ; AM437X_ICSS0
    ; Restore context from DMEM
    LDI     R0, I2C2_CTXT
    LBBO    &R10, R0, 0, CTXT_SZ

    .endif ; AM437X_ICSS0
    
    ;jump and link to the next task function
    JAL    WORK_REG_3.w0, R13.w0
    
    ; Save I2C instance context
    .if !$defined("AM437X_ICSS0")
    ; save context to SPAD
    ; select the bank based on PRU and push all register
    .if $defined("PRU0")
    LDI    R0.b0, 0x0A
    XOUT   BANK0, &R10, 40
    .else
    LDI    R0.b0, 0x0A
    XOUT   BANK2, &R10, 40
    .endif
    
    .else    ; AM437X_ICSS0
    ; Save context to DMEM
    LDI     R0, I2C2_CTXT
    SBBO    &R10, R0, 0, CTXT_SZ
    
    .endif   ; AM437X_ICSS0

    .endm

;----------------------------------------------------------------------
; Macro Name: I2C_WAVE_FUNCTION3
; Description: jump to the next state of i2c3 function
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
I2C_WAVE_FUNCTION3    .macro
    ; Restore I2C instance context
    .if !$defined("AM437X_ICSS0")
    ; restore context from SPAD
    ; select the bank based on PRU and reload all register
    .if $defined("PRU0")
    LDI    R0.b0, 0x14
    XIN    BANK1, &R10, 40
    .else
    LDI    R0.b0, 0x0A
    XIN    BANK1, &R10, 40
    .endif
    
    .else   ; AM437X_ICSS0
    ; Restore context from DMEM
    LDI     R0, I2C3_CTXT
    LBBO    &R10, R0, 0, CTXT_SZ

    .endif ; AM437X_ICSS0
    
    ;jump and link to the next task function
    JAL    WORK_REG_3.w0, R13.w0
    
    ; Save I2C instance context
    .if !$defined("AM437X_ICSS0")
    ; save context to SPAD
    ; select the bank based on PRU and push all register
    .if $defined("PRU0")
    LDI    R0.b0, 0x14
    XOUT   BANK1, &R10, 40
    .else
    LDI    R0.b0, 0x0A
    XOUT   BANK1, &R10, 40
    .endif
    
    .else    ; AM437X_ICSS0
    ; Save context to DMEM
    LDI     R0, I2C3_CTXT
    SBBO    &R10, R0, 0, CTXT_SZ
    
    .endif   ; AM437X_ICSS0

    .endm

;----------------------------------------------------------------------
; Macro Name: I2C_WAVE_FUNCTION0_SINGLE_I2C_INST
; Description: jump to the next state of i2c0 function
;   Context save/restore not performed to reduce cycle count.
;   Hence only a single I2C instance is supported.
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
I2C_WAVE_FUNCTION0_SINGLE_I2C_INST    .macro    
    ;jump and link to the next task function
    JAL    WORK_REG_3.w0, R13.w0
        
    .endm
    
    .endif  ;__I2C_scheduler_h
