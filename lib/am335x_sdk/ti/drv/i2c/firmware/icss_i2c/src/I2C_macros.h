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
; file:   I2C_macros.h
;
; brief:  This files contains all state table macros needed for function
;
;
;  (C) Copyright 2017-2018, Texas Instruments, Inc
;
;

    .if    !$defined("__I2C_macros_h")
__I2C_macros_h    .set 1

    .include "I2C_scheduler.h"

;----------------------------------------------------------------------
; Macro Name: UPDATE_NEXT_LOCAL_STATE
; Description: update next state in state keep register.
; Input Parameters: Label on new memory location
; Output Parameters: none
;----------------------------------------------------------------------
UPDATE_NEXT_LOCAL_STATE    .macro    arg1
    LDI     R13.w0, $CODE(arg1)
    .endm

;----------------------------------------------------------------------
; Macro Name: UPDATE_NEXT_GLOBAL_STATE
; Description: update next state in state keep register.
; Input Parameters: Label on new memory location
; Output Parameters: none
;----------------------------------------------------------------------
UPDATE_NEXT_GLOBAL_STATE    .macro    arg1
    LDI     R17.w0, $CODE(arg1)
    .endm

;----------------------------------------------------------------------
; Macro Name: COPY_LOCAL_TO_GLOBAL_STATE
; Description: copy next state from global state register.
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
COPY_LOCAL_TO_GLOBAL_STATE    .macro
    AND     R13.w0, R17.w0, R17.w0
    .endm

;----------------------------------------------------------------------
; Macro Name: STATE_TASK_OVER
; Description: Return to the scheduler as state task is over.
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
STATE_TASK_OVER    .macro
    JMP     WORK_REG_3.w0
    .endm

;----------------------------------------------------------------------
; Macro Name: CHECK_INTERRUPT_RECEIVED
; Description: Check if the interrupt is recieved by the host & then move to next task.
; Input Parameters: Label on new memory location if interrupt is ACKed
; Input Parameters: Label on new memory location if interrupt is not ACKed
; Output Parameters: none
;----------------------------------------------------------------------
CHECK_INTERRUPT_RECEIVED    .macro    arg1, arg2
    LDI     WORK_REG_5.w0, ICSS_I2C_CONFIG_MEMORY
    ADD     WORK_REG_5.w0, WORK_REG_5.w0, IRQ_COMMON_REGISTER_OFFSET
    LBCO    &WORK_REG_4.w0, PRU0_DMEM_CONST, WORK_REG_5.w0, 2
    QBBC    INTERRUPT_RECEIVED_JMP_STATE?, WORK_REG_4.w0, R14.b3
    JMP     INTERRUPT_RECEIVED_REPEAT_STATE?

INTERRUPT_RECEIVED_JMP_STATE?:
    UPDATE_NEXT_LOCAL_STATE arg1
    STATE_TASK_OVER

INTERRUPT_RECEIVED_REPEAT_STATE?:
    UPDATE_NEXT_LOCAL_STATE arg2
    STATE_TASK_OVER
    .endm

;----------------------------------------------------------------------
; Macro Name: RAISE_INTERRUPT_MEM_FOR_HOST
; Description: raise the interrupt memory for 
;              telling host which instance raise the interrupt.
; Input Parameters: Label on new memory location
; Output Parameters: none
;----------------------------------------------------------------------
RAISE_INTERRUPT_MEM_FOR_HOST    .macro    arg1
    LDI     WORK_REG_4.w0, 0x0000
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET+2, 2

    LDI     WORK_REG_5.w0, ICSS_I2C_CONFIG_MEMORY
    ADD     WORK_REG_5.w0, WORK_REG_5.w0, IRQ_COMMON_REGISTER_OFFSET
    LBCO    &WORK_REG_4.w0, PRU0_DMEM_CONST, WORK_REG_5.w0, 2
    SET     WORK_REG_4.w0, WORK_REG_4.w0, R14.b3
    SBCO    &WORK_REG_4.w0, PRU0_DMEM_CONST, WORK_REG_5.w0, 2
    UPDATE_NEXT_LOCAL_STATE arg1
    STATE_TASK_OVER
    .endm


;----------------------------------------------------------------------
; Macro Name: RAISE_INTERRUPT_FOR_HOST
; Description: raise the interrupt line for Host.
; Input Parameters: Label on new memory location
; Output Parameters: none
;----------------------------------------------------------------------
RAISE_INTERRUPT_FOR_HOST    .macro    arg1
    LDI     WORK_REG_5.w0, ICSS_INTC_SRSR0
    .if $defined("PRU0")
    MOV32   WORK_REG_6, ICSS_I2C_INTC_PRU0_BIT_VAL
    .else
    MOV32   WORK_REG_6, ICSS_I2C_INTC_PRU1_BIT_VAL
    .endif
    SBCO    &WORK_REG_6, ICSS_INTC_CONST, WORK_REG_5.w0, 4
    UPDATE_NEXT_LOCAL_STATE arg1
    STATE_TASK_OVER
    .endm

;----------------------------------------------------------------------
; Macro Name: SET_EDIO_DATAOUT_VALUE
; Description: Set value on all iep digio pins.
;   Currently only used for SMBUS support.
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
SET_EDIO_DATAOUT_VALUE    .macro
    .if $defined("AM437X_ICSS0")    
    LDI32   WORK_REG_2, ICSS_EXT_PORT_LOCAL     ; load PRU-ICSS1 Ext port address
    .endif
    
    LDI     WORK_REG_5.w0, 0x0000
    LDI     WORK_REG_6.b1, ICSS_IEP_DIGIO_BLK_INDEX
    LDI     WORK_REG_6.b0, ICSS_IEP_DIGIO_DATA_OUT_REG
    
    .if !$defined("AM437X_ICSS0")    
    ; Write Local ICSS IEP register
    SBCO    &WORK_REG_5, ICSS_IEP_CONST, WORK_REG_6.w0, 4

    .else   ; AM437X_ICSS0
    ; Write Other ICSS IEP register
    ADD     WORK_REG_6, WORK_REG_2, WORK_REG_6.w0
    SBCO    &WORK_REG_5, ICSS_IEP_CONST, WORK_REG_6, 4

    .endif  ; AM437X_ICSS0

    .endm


;----------------------------------------------------------------------
; Macro Name: SET_SDA_PIN_LOW
; Description: Set low value on SDA pin
; Input Parameters: Label on new memory location
; Output Parameters: none
;----------------------------------------------------------------------
SET_SDA_PIN_LOW    .macro
    LDI     WORK_REG_6.w0, ICSS_IEP_DIGIO_DATA_OUT_EN_REG

    .if $defined("AM437X_ICSS0")    
    LDI32   WORK_REG_5, ICSS_EXT_PORT_LOCAL     ; load PRU-ICSS1 Ext port address
    ADD     WORK_REG_6, WORK_REG_5, WORK_REG_6.w0
    .endif
    
    .if !$defined("AM437X_ICSS0")
    ; Load PRU0/1 local copies of IEP DIGIO output enable register.
    ; Copies contained in SPAD.
    LDI     R0.b0, 0x00
    XIN     BANK1, &R18, 8
    
    .else   ; AM437X_ICSS0
    ; Load PRU0/1 local copies of IEP DIGIO output enable register.
    ; Copies contained in PRU0 DMEM.
    LDI     R0, PRU_TMP_CTXT
    LBBO    &R18, R0, 0, TMP_CTXT_SZ
    
    .endif  ; AM437X_ICSS0
    
    .if $defined("PRU0")
    CLR     R18, R18, R14.b2
    .else
    CLR     R19, R19, R14.b2
    .endif
    OR      WORK_REG_8, R18, R19
    
    .if !$defined("AM437X_ICSS0")
    ; Write Local ICSS IEP register
    SBCO    &WORK_REG_8, ICSS_IEP_CONST, WORK_REG_6.w0, 4
    .else   ; AM437X_ICSS0
    ; Write Other ICSS IEP register
    SBCO    &WORK_REG_8, ICSS_IEP_CONST, WORK_REG_6, 4
    .endif  ; AM437X_ICSS0
    
    .if !$defined("AM437X_ICSS0")
    ; Store PRU0/1 local copies of IEP DIGIO output enable register.
    ; Copies contained in SPAD.
    XOUT    BANK1, &R18, 8
    
    .else   ; AM437X_ICSS0
    ; Store PRU0/1 local copies of IEP DIGIO output enable register.
    ; Copies contained in PRU0 DMEM.
    LDI     R0, PRU_TMP_CTXT
    SBBO    &R18, R0, 0, TMP_CTXT_SZ
    
    .endif  ; AM437X_ICSS0
    
    .endm


;----------------------------------------------------------------------
; Macro Name: SET_SDA_PIN_HIGH
; Description: Set high value on SDA pin
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
SET_SDA_PIN_HIGH    .macro
    LDI     WORK_REG_6.w0, ICSS_IEP_DIGIO_DATA_OUT_EN_REG

    .if $defined("AM437X_ICSS0")    
    LDI32   WORK_REG_5, ICSS_EXT_PORT_LOCAL     ; load PRU-ICSS1 Ext port address
    ADD     WORK_REG_6, WORK_REG_5, WORK_REG_6.w0
    .endif    
    
    .if !$defined("AM437X_ICSS0")
    ; Load PRU0/1 local copies of IEP DIGIO output enable register.
    ; Copies contained in SPAD.
    LDI     R0.b0, 0x00
    XIN     BANK1, &R18, 8

    .else   ; AM437X_ICSS0
    ; Load PRU0/1 local copies of IEP DIGIO output enable register.
    ; Copies contained in PRU0 DMEM.
    LDI     R0, PRU_TMP_CTXT
    LBBO    &R18, R0, 0, TMP_CTXT_SZ
    
    .endif  ; AM437X_ICSS0
    
    .if $defined("PRU0")
    SET     R18, R18, R14.b2
    .else
    SET     R19, R19, R14.b2
    .endif
    OR      WORK_REG_8, R18, R19
    
    .if !$defined("AM437X_ICSS0")
    ; Write Local ICSS IEP register
    SBCO    &WORK_REG_8, ICSS_IEP_CONST, WORK_REG_6.w0, 4
    .else   ; AM437X_ICSS0
    ; Write Other ICSS IEP register
    SBCO    &WORK_REG_8, ICSS_IEP_CONST, WORK_REG_6, 4
    .endif  ; AM437X_ICSS0
    
    .if !$defined("AM437X_ICSS0")
    ; Store PRU0/1 local copies of IEP DIGIO output enable register.
    ; Copies contained in SPAD.    
    XOUT    BANK1, &R18, 8
    
    .else   ; AM437X_ICSS0
    ; Store PRU0/1 local copies of IEP DIGIO output enable register.
    ; Copies contained in PRU0 DMEM.
    LDI     R0, PRU_TMP_CTXT
    SBBO    &R18, R0, 0, TMP_CTXT_SZ
    
    .endif  ; AM437X_ICSS0    
    
    .endm


;----------------------------------------------------------------------
; Macro Name: SET_SCL_PIN_LOW
; Description: Set low value on SCL pin
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
SET_SCL_PIN_LOW    .macro
    CLR     R30, R30, R14.b0
    .endm


;----------------------------------------------------------------------
; Macro Name: SET_SCL_PIN_HIGH
; Description: Set high value on SCL pin
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
SET_SCL_PIN_HIGH    .macro
    SET     R30, R30, R14.b0
    .endm


;----------------------------------------------------------------------
; Macro Name: READ_SDA_PIN_ACK
; Description: Set high value on SCL pin
; Input Parameters: none
; Output Parameters: none
;----------------------------------------------------------------------
READ_SDA_PIN_ACK    .macro
    QBBS    ACK_RECIEVED?, R31, R14.b1
    CLR     R16, R16, ICSS_I2C_ACK_RECIEVED_BIT
    JMP     NO_ACK_RECIEVED?
ACK_RECIEVED?:
    SET     R16, R16, ICSS_I2C_ACK_RECIEVED_BIT
NO_ACK_RECIEVED?:
    .endm


;----------------------------------------------------------------------
; Macro Name: SET_OUTPUT_PIN_VALUE_HIGH
; Description: Set high value on SCL and SDA pin
; Input Parameters: Label on next memory location
; Output Parameters: none
;----------------------------------------------------------------------
SET_OUTPUT_PIN_VALUE_HIGH    .macro    arg1
    SET_SDA_PIN_HIGH
    SET_SCL_PIN_HIGH
    UPDATE_NEXT_LOCAL_STATE arg1
    STATE_TASK_OVER
    .endm


;----------------------------------------------------------------------
; Macro Name: READ_ADDRESS_REGISTER
; Description: Read the address register for slave address
; Input Parameters: Label on new memory location
; Output Parameters: none
;----------------------------------------------------------------------
READ_ADDRESS_REGISTER    .macro    arg1
    QBBS    read_address_register_10bits?, R16, ICSS_I2C_ADDRESSING_MODE_BIT 
    LDI     WORK_REG_4.w0, 0x007F
    JMP     read_address_register_done?

read_address_register_10bits?:
    LDI     WORK_REG_4.w0, 0x03FF

read_address_register_done?:
    LBBO    &R13.w2, R10, ICSS_I2C_SA_OFFSET, 2
    AND     R13.w2, R13.w2, WORK_REG_4.w0
    UPDATE_NEXT_LOCAL_STATE arg1
    STATE_TASK_OVER
    .endm


;----------------------------------------------------------------------
; Macro Name: READ_RW_REGISTER_BIT
; Description: Read the RW bit to find read or write operation
; Input Parameters: Label on new memory location
; Output Parameters: none
;----------------------------------------------------------------------
READ_RW_REGISTER_BIT    .macro    arg1
    QBBS    read_rw_register_bit_10bits?, R16, ICSS_I2C_ADDRESSING_MODE_BIT
    LSL     R13.w2, R13.w2, 9
    QBBC    slave_address_w_setup?, R16, ICSS_I2C_READ_WRITE_BIT
    SET     R13.w2, R13.w2, 8
    JMP     slave_address_rw_setup_return?
slave_address_w_setup?:
    CLR     R13.w2, R13.w2, 8
slave_address_rw_setup_return?:
    JMP     read_rw_register_bit_done?

read_rw_register_bit_10bits?:
    LSL     R13.b3, R13.b3, 1
    QBBC    slave_address_w_setup_10bits?, R16, ICSS_I2C_READ_WRITE_BIT
    SET     R13.b3, R13.b3, 0
    JMP     slave_address_rw_setup_return_10bits?
slave_address_w_setup_10bits?:
    CLR     R13.b3, R13.b3, 0
slave_address_rw_setup_return_10bits?:
    AND     R13.b3, R13.b3, 0x07
    OR      R13.b3, R13.b3, 0xF0

read_rw_register_bit_done?:
    AND     R15.b0, R15.b0, 0x00
    AND     R15.b2, R15.b2, 0x00
    UPDATE_NEXT_LOCAL_STATE arg1
    STATE_TASK_OVER
   .endm


;----------------------------------------------------------------------
; Macro Name: SET_SDA_LOW_FOR_START
; Description: set sda low for start condition
; Input Parameters: Label on new memory location
; Output Parameters: none
;----------------------------------------------------------------------
SET_SDA_LOW_FOR_START    .macro    arg1
    QBBC    start_condition_sda_low_return?, R16, ICSS_I2C_START_BIT
    SET_SDA_PIN_LOW
start_condition_sda_low_return?:
    UPDATE_NEXT_LOCAL_STATE arg1
    STATE_TASK_OVER
   .endm


;----------------------------------------------------------------------
; Macro Name: SET_SCL_LOW_FOR_START
; Description: set scl low for start condition
; Input Parameters: Label on new memory location
; Output Parameters: none
;----------------------------------------------------------------------
SET_SCL_LOW_FOR_START    .macro    arg1
    QBBC    start_condition_scl_low_return?, R16, ICSS_I2C_START_BIT
    SET_SCL_PIN_LOW
start_condition_scl_low_return?:
    UPDATE_NEXT_LOCAL_STATE arg1
    STATE_TASK_OVER
   .endm


;----------------------------------------------------------------------
; Macro Name: MODIFY_SDA_PIN
; Description: Change sda pin based on the data register
; Input Parameters: arg1 is data register for pin value change
; Input Parameters: arg2 is Label on new memory location
; Output Parameters: none
;----------------------------------------------------------------------
MODIFY_SDA_PIN    .macro    arg1, arg2
    QBBC    address_sda_low?, arg1, 7
    SET_SDA_PIN_HIGH
    JMP     address_sda_continue?
address_sda_low?:
    SET_SDA_PIN_LOW
address_sda_continue?:
    LSL     arg1, arg1, 1
    ADD     R15.b0, R15.b0, 0x01
    UPDATE_NEXT_LOCAL_STATE arg2
    STATE_TASK_OVER
   .endm


;----------------------------------------------------------------------
; Macro Name: READ_SDA_PIN
; Description: read sda pin based on the line value
; Input Parameters: arg1 is Label on new memory location
; Output Parameters: none
;----------------------------------------------------------------------
READ_SDA_PIN    .macro    arg1
    QBBS    rx_data_sda_high?, R31, R14.b1
    AND     R15.b1, R15.b1, 0xFE
    JMP     rx_data_sda_read_continue?
rx_data_sda_high?:
    OR      R15.b1, R15.b1, 0x01
rx_data_sda_read_continue?:
    LSL     R15.b1, R15.b1, 1
    ADD     R15.b0, R15.b0, 0x01
    UPDATE_NEXT_LOCAL_STATE arg1
    STATE_TASK_OVER
   .endm


;----------------------------------------------------------------------
; Macro Name: SCL_LOW_NEXT_STATE
; Description: Change scl to low and decide next state
; Input Parameters: arg1 is Label on new memory location
; Input Parameters: arg2 is Label on new memory location
; Output Parameters: none
;----------------------------------------------------------------------
SCL_LOW_NEXT_STATE    .macro    arg1, arg2
    SET_SCL_PIN_LOW
    QBGT    sda_next_bit?, R15.b0, 0x08
    UPDATE_NEXT_LOCAL_STATE arg1
    STATE_TASK_OVER

sda_next_bit?:
    UPDATE_NEXT_LOCAL_STATE arg2
    STATE_TASK_OVER
   .endm


    .endif  ;__I2C_macros_h

