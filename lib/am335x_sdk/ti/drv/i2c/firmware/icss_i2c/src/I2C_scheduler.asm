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
; file:   I2C_scheduler.asm
;
; brief:  Round-robin based I2C_scheduler which controls program flow.
;
;
;  (C) Copyright 2017-2018, Texas Instruments, Inc
;
;

    ;.fcnolist   ; suppress listing of false conditional blocks in lister output
    
;;///////////////////////////////////////////////////////
; Includes Section
;;///////////////////////////////////////////////////////
    .include "firmware_version.h"
    .include "I2C_scheduler.h"
    
;.setcallreg CALL_REG
    .retain     ; Required for building .out with assembly file
    .retainrefs ; Required for building .out with assembly file
    
                        .if $defined("AM437X_ICSS0")
; I2C instance context
CTXT_NREGS              .set    10                          ; 10 registers for each I2C instance context
CTXT_SZ                 .set    4*CTXT_NREGS                ; 4 bytes per 32-bit register
I2C0_CTXT               .usect  ".i2c_ctxt", CTXT_SZ, 4     ; I2C0 context
I2C1_CTXT               .usect  ".i2c_ctxt", CTXT_SZ, 4     ; I2C1 context
I2C2_CTXT               .usect  ".i2c_ctxt", CTXT_SZ, 4     ; I2C1 context
I2C3_CTXT               .usect  ".i2c_ctxt", CTXT_SZ, 4     ; I2C1 context

                        .def    PRU_TMP_CTXT
                        .if $defined("PRU0")
; PRU0/1 local copy IEP DIGIO output enable register
PRU_TMP_CTXT            .usect  ".pru0_tmp_ctxt", TMP_CTXT_SZ, 4
                        .else
PRU_TMP_CTXT            .usect  ".pru1_tmp_ctxt", TMP_CTXT_SZ, 4
                        .endif

                        .endif  ; AM437X_ICSS0


    .sect    ".data"
    .retain
    
    .word    I2C_FIRMWARE_TYPE
    .word    I2C_FIRMWARE_VERSION
    .word    I2C_FIRMWARE_FEATURE
    .word    I2C_FIRMWARE_EXTENDED_FEATURE_PTR
    
    .sect    ".text:I2C_scheduler"
    .global  I2C_scheduler
    .global  RESET_MODE

I2C_scheduler:

    ;Firmware Version: To store in shared memory. Can be used by application.
    
    ZERO    &R0, 124        ;Zero all registers
    LDI     R31 , 0

    .if !$defined("AM437X_ICSS0")
    ; Enable support of shifting during XIN/XOUT operation
    ENABLE_XIN_XOUT_SHITFTING
    .endif

    ; Initialize I2C instance 0 registers
    LDI    R10.w0 , ICSS_I2C_INSTANCE0_ADDR
    LDI    R10.w2 , 0x0000
    LDI    R11.w0 , ICSS_I2C_INSTANCE0_TX_MEM
    LDI    R11.w2 , 0x0000
    LDI    R12.w0 , ICSS_I2C_INSTANCE0_RX_MEM
    LDI    R12.w2 , 0x0000
    LDI    R13.w0 , $CODE(RESET_MODE)
    LDI    R13.w2 , 0x0000
    MOV32  R14 , 0x00000000
    MOV32  R15 , 0x00000000
    MOV32  R16 , 0x00000000
    MOV32  R17 , 0x00000000
    MOV32  R18 , 0x00000000
    MOV32  R19 , 0x00000000
    ; Save I2C instance context
    .if !$defined("AM437X_ICSS0")
    ; Save context to SPAD
    .if $defined("PRU0")
    LDI    R0.b0, 0x14
    XOUT   BANK0, &R10, 40
    .else
    LDI    R0.b0, 0x14
    XOUT   BANK2, &R10, 40
    .endif
    .else ; AM437X_ICSS0
    ; Save context to DMEM
    LDI     R0, I2C0_CTXT
    SBBO    &R10, R0, 0, CTXT_SZ
    .endif ; AM437X_ICSS0
    
    ; Initialize I2C instance 1 registers
    LDI    R10.w0 , ICSS_I2C_INSTANCE1_ADDR
    LDI    R10.w2 , 0x0000
    LDI    R11.w0 , ICSS_I2C_INSTANCE1_TX_MEM
    LDI    R11.w2 , 0x0000
    LDI    R12.w0 , ICSS_I2C_INSTANCE1_RX_MEM
    LDI    R12.w2 , 0x0000
    LDI    R13.w0 , $CODE(RESET_MODE)
    LDI    R13.w2 , 0x0000
    MOV32  R14 , 0x00000000
    MOV32  R15 , 0x00000000
    MOV32  R16 , 0x00000000
    MOV32  R17 , 0x00000000
    MOV32  R18 , 0x00000000
    MOV32  R19 , 0x00000000
    ; Save I2C instance context
    .if !$defined("AM437X_ICSS0")
    .if $defined("PRU0")
    LDI    R0.b0, 0x00
    XOUT   BANK0, &R10, 40
    .else
    LDI    R0.b0, 0x00
    XOUT   BANK2, &R10, 40
    .endif
    .else ; AM437X_ICSS0
    ; Save context to DMEM
    LDI     R0, I2C1_CTXT
    SBBO    &R10, R0, 0, CTXT_SZ
    .endif ; AM437X_ICSS0
    
    ; Initialize I2C instance 2 registers
    LDI    R10.w0 , ICSS_I2C_INSTANCE2_ADDR
    LDI    R10.w2 , 0x0000
    LDI    R11.w0 , ICSS_I2C_INSTANCE2_TX_MEM
    LDI    R11.w2 , 0x0000
    LDI    R12.w0 , ICSS_I2C_INSTANCE2_RX_MEM
    LDI    R12.w2 , 0x0000
    LDI    R13.w0 , $CODE(RESET_MODE)
    LDI    R13.w2 , 0x0000
    MOV32  R14 , 0x00000000
    MOV32  R15 , 0x00000000
    MOV32  R16 , 0x00000000
    MOV32  R17 , 0x00000000
    MOV32  R18 , 0x00000000
    MOV32  R19 , 0x00000000
    ; Save I2C instance context
    .if !$defined("AM437X_ICSS0")
    ; Save context to SPAD
    .if $defined("PRU0")
    LDI    R0.b0, 0x0A
    XOUT   BANK0, &R10, 40
    .else
    LDI    R0.b0, 0x0A
    XOUT   BANK2, &R10, 40
    .endif
    .else ; AM437X_ICSS0
    ; Save context to DMEM
    LDI     R0, I2C2_CTXT
    SBBO    &R10, R0, 0, CTXT_SZ
    .endif ; AM437X_ICSS0
    
    ; Initialize I2C instance 3 registers
    LDI    R10.w0 , ICSS_I2C_INSTANCE3_ADDR
    LDI    R10.w2 , 0x0000
    LDI    R11.w0 , ICSS_I2C_INSTANCE3_TX_MEM
    LDI    R11.w2 , 0x0000
    LDI    R12.w0 , ICSS_I2C_INSTANCE3_RX_MEM
    LDI    R12.w2 , 0x0000
    LDI    R13.w0 , $CODE(RESET_MODE)
    LDI    R13.w2 , 0x0000
    MOV32  R14 , 0x00000000
    MOV32  R15 , 0x00000000
    MOV32  R16 , 0x00000000
    MOV32  R17 , 0x00000000
    MOV32  R18 , 0x00000000
    MOV32  R19 , 0x00000000
    ; Save I2C instance context
    .if !$defined("AM437X_ICSS0")
    .if $defined("PRU0")
    LDI    R0.b0, 0x14
    XOUT   BANK1, &R10, 40
    .else
    LDI    R0.b0, 0x0A
    XOUT   BANK1, &R10, 40
    .endif
    .else ; AM437X_ICSS0
    ; Save context to DMEM
    LDI     R0, I2C3_CTXT
    SBBO    &R10, R0, 0, CTXT_SZ
    .endif ; AM437X_ICSS0

    ;add a variable delay for N cyles to avoid contention
    ;between PRU0 and PRU1 if both out of reset at the same time.
    DELAY   DELAY_CYCLE

    ZERO    &R0, 124        ;Zero all registers

    ; decide the global working frequency for I2C FW
    LDI     WORK_REG_5.w0, ICSS_I2C_CONFIG_MEMORY
    ADD     WORK_REG_5.w0, WORK_REG_5.w0, I2C_BUS_FREQUENCY_OFFSET
    LBCO    &I2C_GLOBAL_FREQ_REG.w0, PRU0_DMEM_CONST, WORK_REG_5.w0, 4
    
    ; Setup the DIGIO IEP value
    I2C_SETUP_IEP_DIGIO

    ; Setup the IEP Timer Counter
    I2C_SETUP_IEP_COUNTER

    .if $defined("FW_DEBUG")
    .if $defined("PRU0")
    MOV32   R25, 0x00022000
    .endif  ;PRU0

    .if $defined("PRU1")
    MOV32   R25, 0x00024000
    .endif  ;PRU1
    .endif  ;FW_DEBUG

    ; jump to task_loop based on global frequency
    QBEQ    task_loop_100Khz, I2C_GLOBAL_FREQ_REG.w0, ICSS_I2C_100KHZ_FREQ
    QBEQ    task_loop_400Khz, I2C_GLOBAL_FREQ_REG.w0, ICSS_I2C_400KHZ_FREQ
    .if !$defined("AM437X_ICSS0")
    QBEQ    task_loop_1Mhz, I2C_GLOBAL_FREQ_REG.w0, ICSS_I2C_1MHZ_FREQ
    .else
    QBEQ    task_loop_1Mhz_init, I2C_GLOBAL_FREQ_REG.w0, ICSS_I2C_1MHZ_FREQ
    .endif

error_loop:
    LBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_CFG_REG, 4
    CLR     WORK_REG_1 , WORK_REG_1 , 0
    SBCO    &WORK_REG_1, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_CFG_REG, 4
    LDI     WORK_REG_5.w0, ICSS_INTC_SRSR0
    MOV32   WORK_REG_6, 0x00400000
    SBCO    &WORK_REG_6, ICSS_INTC_CONST, WORK_REG_5.w0, 4
    QBA     error_loop

    ;scheduler for 100Khz mode
task_loop_100Khz:
    ;wait for the IEP CMP event 0 to happen
IEP_CHECK_EVENT0:
    I2C_WAIT_FOR_IEP_CMP
    
    ; clear IEP CMP event and interrupt associated with it.
    I2C_IEP_INTC_CLEAR_EVENT IEP_CHECK_EVENT0

    ;perform the i2c wave transition for I2C0
    I2C_WAVE_FUNCTION0
    
    .if $defined("FW_DEBUG")
    LBBO    &R27, R25, 0x0C, 4
    QBLE    error_loop, R27, 40
    .endif  ;FW_DEBUG

    ;wait for the IEP CMP event 1 to happen
IEP_CHECK_EVENT1:
    I2C_WAIT_FOR_IEP_CMP

    ; clear IEP CMP event and interrupt associated with it.
    I2C_IEP_INTC_CLEAR_EVENT IEP_CHECK_EVENT1

    ;perform the i2c wave transition for I2C1
    I2C_WAVE_FUNCTION1

    ;wait for the IEP CMP event 2 to happen
IEP_CHECK_EVENT2:
    I2C_WAIT_FOR_IEP_CMP

    ; clear IEP CMP event and interrupt associated with it.
    I2C_IEP_INTC_CLEAR_EVENT IEP_CHECK_EVENT2

    ;perform the i2c wave transition for I2C2
    I2C_WAVE_FUNCTION2

    ;wait for the IEP CMP event 3 to happen
IEP_CHECK_EVENT3:
    I2C_WAIT_FOR_IEP_CMP

    ; clear IEP CMP event and interrupt associated with it.
    I2C_IEP_INTC_CLEAR_EVENT IEP_CHECK_EVENT3

    ;perform the i2c wave transition for I2C3
    I2C_WAVE_FUNCTION3

    QBA   task_loop_100Khz

    ;scheduler for 400Khz mode
task_loop_400Khz:
    ;wait for the IEP CMP event 0 to happen
IEP_CHECK_EVENT4:
    I2C_WAIT_FOR_IEP_CMP
    
    ; clear IEP CMP event and interrupt associated with it.
    I2C_IEP_INTC_CLEAR_EVENT IEP_CHECK_EVENT4

    ;perform the i2c wave transition for I2C0
    I2C_WAVE_FUNCTION0
    
    QBA   task_loop_400Khz

    .if !$defined("AM437X_ICSS0")
    ;scheduler for 1MHz mode
task_loop_1Mhz:
    ;wait for the IEP CMP event 0 to happen
IEP_CHECK_EVENT5:
    I2C_WAIT_FOR_IEP_CMP
    
    ; clear IEP CMP event and interrupt associated with it.
    I2C_IEP_INTC_CLEAR_EVENT1

    ;perform the i2c wave transition for I2C0
    I2C_WAVE_FUNCTION0
    
    QBA   task_loop_1Mhz
    
    .else   ; AM437X_ICSS0    
task_loop_1Mhz_init:
    ; Restore I2C instance context
    ; Restore context from DMEM
    LDI     R0, I2C0_CTXT
    LBBO    &R10, R0, 0, CTXT_SZ
 
task_loop_1Mhz:
    ;wait for the IEP CMP event 0 to happen
IEP_CHECK_EVENT5:
    I2C_WAIT_FOR_IEP_CMP

    ; clear IEP CMP event and interrupt associated with it.
    I2C_IEP_INTC_CLEAR_EVENT1

    ; perform the i2c wave transition for I2C0
    ;   no context save/restore to reduce cycle count,
    ;   only single instance supported
    I2C_WAVE_FUNCTION0_SINGLE_I2C_INST
    
    QBA   task_loop_1Mhz

    .endif ; AM437X_ICSS0
