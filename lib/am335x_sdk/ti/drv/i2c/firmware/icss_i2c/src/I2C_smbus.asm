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
; file:   I2C_smbus.asm
;
; brief:  This files contains all state table transition function for smbus command.
;
;
;  (C) Copyright 2017-2018, Texas Instruments, Inc
;
;

;;///////////////////////////////////////////////////////
; Includes Section
;;///////////////////////////////////////////////////////
    .include "I2C_function.h"

    .def    QUICK_CMD_MODE      ; SMBUS
    .def    SEND_BYTE_MODE      ; SMBUS
    .def    RECEIVE_BYTE_MODE   ; SMBUS
    .def    WRITE_BYTE_MODE     ; SMBUS
    .def    READ_BYTE_MODE      ; SMBUS
    .def    WRITE_WORD_MODE     ; SMBUS
    .def    READ_WORD_MODE      ; SMBUS
    .def    BLOCK_WRITE_MODE    ; SMBUS
    .def    BLOCK_READ_MODE     ; SMBUS
    
    .ref    STOP_CONDITION_SCL_HIGH
    .ref    RAISE_HOST_INTERRUPT_MEM_FOR_READY
    .ref    RX_DATA_SDA_BEGIN
    .ref    START_CONDITION_SDA_LOW
    .ref    TX_DATA_SDA_BEGIN
    .ref    DATA_PROCESSING_COMPLETE
    .ref    CMD_CODE_SDA_BEGIN


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the local register to indicate smbus quick command mode
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
QUICK_CMD_MODE:
    SET_EDIO_DATAOUT_VALUE
    CLR     R16, R16, ICSS_I2C_ADDRESSING_MODE_BIT 
    UPDATE_NEXT_GLOBAL_STATE DATA_PROCESSING_COMPLETE
    UPDATE_NEXT_LOCAL_STATE QUICK_CMD_SET_SCL_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the value on iep gpo enable register to high value
;  this will pull the line to high impedence and open drain will keep the line high
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
QUICK_CMD_SET_SCL_SDA_HIGH:
    SET_OUTPUT_PIN_VALUE_HIGH QUICK_CMD_SLAVE_ADDRESS_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  read the slave address from configuration registers.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
QUICK_CMD_SLAVE_ADDRESS_SETUP:
    READ_ADDRESS_REGISTER QUICK_CMD_SLAVE_ADDRESS_RW_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  configure the read/write bit in the slave address register for transmission
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
QUICK_CMD_SLAVE_ADDRESS_RW_SETUP:    
    READ_RW_REGISTER_BIT START_CONDITION_SDA_LOW

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the local register to indicate smbus send byte command mode
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SEND_BYTE_MODE:
    SET_EDIO_DATAOUT_VALUE
    CLR     R16, R16, ICSS_I2C_ADDRESSING_MODE_BIT 
    UPDATE_NEXT_GLOBAL_STATE TX_DATA_SDA_BEGIN
    UPDATE_NEXT_LOCAL_STATE SEND_BYTE_SET_SCL_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the value on iep gpo enable register to high value
;  this will pull the line to high impedence and open drain will keep the line high
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SEND_BYTE_SET_SCL_SDA_HIGH:
    SET_OUTPUT_PIN_VALUE_HIGH SEND_BYTE_SLAVE_ADDRESS_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  read the slave address from configuration registers.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SEND_BYTE_SLAVE_ADDRESS_SETUP:
    READ_ADDRESS_REGISTER SEND_BYTE_SLAVE_ADDRESS_RW_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  configure the read/write bit in the slave address register for transmission
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SEND_BYTE_SLAVE_ADDRESS_RW_SETUP:    
    LSL     R13.w2, R13.w2, 9
    CLR     R16, R16, ICSS_I2C_READ_WRITE_BIT
    CLR     R13.w2, R13.w2, 8
    AND     R15.b0, R15.b0, 0x00
    UPDATE_NEXT_LOCAL_STATE SEND_BYTE_DATA_COUNT
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Read the number of 8 bits data need to be read or writen 
;  also initialize the data count and bit count register to 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SEND_BYTE_DATA_COUNT:
    LDI     R15.b3, 0x01
    AND     R15.b2, R15.b2, 0x00
    UPDATE_NEXT_LOCAL_STATE START_CONDITION_SDA_LOW
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the local register to indicate smbus receive byte command mode
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RECEIVE_BYTE_MODE:
    SET_EDIO_DATAOUT_VALUE
    CLR     R16, R16, ICSS_I2C_ADDRESSING_MODE_BIT 
    UPDATE_NEXT_GLOBAL_STATE RX_DATA_SDA_BEGIN
    UPDATE_NEXT_LOCAL_STATE RECEIVE_BYTE_SET_SCL_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the value on iep gpo enable register to high value
;  this will pull the line to high impedence and open drain will keep the line high
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RECEIVE_BYTE_SET_SCL_SDA_HIGH:
    SET_OUTPUT_PIN_VALUE_HIGH RECEIVE_BYTE_SLAVE_ADDRESS_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  read the slave address from configuration registers.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RECEIVE_BYTE_SLAVE_ADDRESS_SETUP:
    READ_ADDRESS_REGISTER RECEIVE_BYTE_SLAVE_ADDRESS_RW_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  configure the read/write bit in the slave address register for transmission
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RECEIVE_BYTE_SLAVE_ADDRESS_RW_SETUP:    
    LSL     R13.w2, R13.w2, 9
    SET     R16, R16, ICSS_I2C_READ_WRITE_BIT
    SET     R13.w2, R13.w2, 8
    AND     R15.b0, R15.b0, 0x00
    UPDATE_NEXT_LOCAL_STATE RECEIVE_BYTE_DATA_COUNT
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Read the number of 8 bits data need to be read or writen 
;  also initialize the data count and bit count register to 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RECEIVE_BYTE_DATA_COUNT:
    LDI     R15.b3, 0x01
    AND     R15.b2, R15.b2, 0x00
    UPDATE_NEXT_LOCAL_STATE START_CONDITION_SDA_LOW
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the local register to indicate smbus write byte command mode
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
WRITE_BYTE_MODE:
    SET_EDIO_DATAOUT_VALUE
    CLR     R16, R16, ICSS_I2C_ADDRESSING_MODE_BIT 
    UPDATE_NEXT_GLOBAL_STATE CMD_CODE_SDA_BEGIN
    UPDATE_NEXT_LOCAL_STATE WRITE_BYTE_SET_SCL_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the value on iep gpo enable register to high value
;  this will pull the line to high impedence and open drain will keep the line high
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
WRITE_BYTE_SET_SCL_SDA_HIGH:
    SET_OUTPUT_PIN_VALUE_HIGH WRITE_BYTE_SLAVE_ADDRESS_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  read the slave address from configuration registers.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
WRITE_BYTE_SLAVE_ADDRESS_SETUP:
    READ_ADDRESS_REGISTER WRITE_BYTE_SLAVE_ADDRESS_RW_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  configure the read/write bit in the slave address register for transmission
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
WRITE_BYTE_SLAVE_ADDRESS_RW_SETUP:    
    LSL     R13.w2, R13.w2, 9
    CLR     R16, R16, ICSS_I2C_READ_WRITE_BIT
    CLR     R13.w2, R13.w2, 8
    AND     R15.b0, R15.b0, 0x00
    UPDATE_NEXT_LOCAL_STATE WRITE_BYTE_DATA_COUNT
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Read the number of 8 bits data need to be read or writen 
;  also initialize the data count and bit count register to 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
WRITE_BYTE_DATA_COUNT:
    LDI     R15.b3, 0x01
    AND     R15.b2, R15.b2, 0x00
    LBBO    &R15.b1, R10, ICSS_I2C_PRU_CMD_CODE_OFFSET, 1
    UPDATE_NEXT_LOCAL_STATE START_CONDITION_SDA_LOW
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the local register to indicate smbus read byte command mode
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_BYTE_MODE:
    SET_EDIO_DATAOUT_VALUE
    CLR     R16, R16, ICSS_I2C_ADDRESSING_MODE_BIT 
    UPDATE_NEXT_GLOBAL_STATE CMD_CODE_SDA_BEGIN
    UPDATE_NEXT_LOCAL_STATE READ_BYTE_SET_SCL_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the value on iep gpo enable register to high value
;  this will pull the line to high impedence and open drain will keep the line high
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_BYTE_SET_SCL_SDA_HIGH:
    SET_OUTPUT_PIN_VALUE_HIGH READ_BYTE_SLAVE_ADDRESS_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  read the slave address from configuration registers.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_BYTE_SLAVE_ADDRESS_SETUP:
    READ_ADDRESS_REGISTER READ_BYTE_SLAVE_ADDRESS_RW_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  configure the read/write bit in the slave address register for transmission
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_BYTE_SLAVE_ADDRESS_RW_SETUP:    
    LSL     R13.w2, R13.w2, 9
    SET     R16, R16, ICSS_I2C_READ_WRITE_BIT
    CLR     R13.w2, R13.w2, 8
    AND     R15.b0, R15.b0, 0x00
    UPDATE_NEXT_LOCAL_STATE READ_BYTE_DATA_COUNT
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Read the number of 8 bits data need to be read or writen 
;  also initialize the data count and bit count register to 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_BYTE_DATA_COUNT:
    LDI     R15.b3, 0x01
    AND     R15.b2, R15.b2, 0x00
    LBBO    &R15.b1, R10, ICSS_I2C_PRU_CMD_CODE_OFFSET, 1
    UPDATE_NEXT_LOCAL_STATE START_CONDITION_SDA_LOW
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the local register to indicate smbus write word command mode
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
WRITE_WORD_MODE:
    SET_EDIO_DATAOUT_VALUE
    CLR     R16, R16, ICSS_I2C_ADDRESSING_MODE_BIT 
    UPDATE_NEXT_GLOBAL_STATE CMD_CODE_SDA_BEGIN
    UPDATE_NEXT_LOCAL_STATE WRITE_WORD_SET_SCL_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the value on iep gpo enable register to high value
;  this will pull the line to high impedence and open drain will keep the line high
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
WRITE_WORD_SET_SCL_SDA_HIGH:
    SET_OUTPUT_PIN_VALUE_HIGH WRITE_WORD_SLAVE_ADDRESS_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  read the slave address from configuration registers.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
WRITE_WORD_SLAVE_ADDRESS_SETUP:
    READ_ADDRESS_REGISTER WRITE_WORD_SLAVE_ADDRESS_RW_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  configure the read/write bit in the slave address register for transmission
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
WRITE_WORD_SLAVE_ADDRESS_RW_SETUP:    
    LSL     R13.w2, R13.w2, 9
    CLR     R16, R16, ICSS_I2C_READ_WRITE_BIT
    CLR     R13.w2, R13.w2, 8
    AND     R15.b0, R15.b0, 0x00
    UPDATE_NEXT_LOCAL_STATE WRITE_WORD_DATA_COUNT
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Read the number of 8 bits data need to be read or writen 
;  also initialize the data count and bit count register to 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
WRITE_WORD_DATA_COUNT:
    LDI     R15.b3, 0x02
    AND     R15.b2, R15.b2, 0x00
    LBBO    &R15.b1, R10, ICSS_I2C_PRU_CMD_CODE_OFFSET, 1
    UPDATE_NEXT_LOCAL_STATE START_CONDITION_SDA_LOW
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the local register to indicate smbus read word command mode
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_WORD_MODE:
    SET_EDIO_DATAOUT_VALUE
    CLR     R16, R16, ICSS_I2C_ADDRESSING_MODE_BIT 
    UPDATE_NEXT_GLOBAL_STATE CMD_CODE_SDA_BEGIN
    UPDATE_NEXT_LOCAL_STATE READ_WORD_SET_SCL_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the value on iep gpo enable register to high value
;  this will pull the line to high impedence and open drain will keep the line high
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_WORD_SET_SCL_SDA_HIGH:
    SET_OUTPUT_PIN_VALUE_HIGH READ_WORD_SLAVE_ADDRESS_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  read the slave address from configuration registers.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_WORD_SLAVE_ADDRESS_SETUP:
    READ_ADDRESS_REGISTER READ_WORD_SLAVE_ADDRESS_RW_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  configure the read/write bit in the slave address register for transmission
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_WORD_SLAVE_ADDRESS_RW_SETUP:    
    LSL     R13.w2, R13.w2, 9
    SET     R16, R16, ICSS_I2C_READ_WRITE_BIT
    CLR     R13.w2, R13.w2, 8
    AND     R15.b0, R15.b0, 0x00
    UPDATE_NEXT_LOCAL_STATE READ_WORD_DATA_COUNT
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Read the number of 8 bits data need to be read or writen 
;  also initialize the data count and bit count register to 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_WORD_DATA_COUNT:
    LDI     R15.b3, 0x02
    AND     R15.b2, R15.b2, 0x00
    LBBO    &R15.b1, R10, ICSS_I2C_PRU_CMD_CODE_OFFSET, 1
    UPDATE_NEXT_LOCAL_STATE START_CONDITION_SDA_LOW
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the local register to indicate smbus block write command mode
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
BLOCK_WRITE_MODE:
    SET_EDIO_DATAOUT_VALUE
    CLR     R16, R16, ICSS_I2C_ADDRESSING_MODE_BIT 
    UPDATE_NEXT_GLOBAL_STATE CMD_CODE_SDA_BEGIN
    UPDATE_NEXT_LOCAL_STATE BLOCK_WRITE_SET_SCL_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the value on iep gpo enable register to high value
;  this will pull the line to high impedence and open drain will keep the line high
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
BLOCK_WRITE_SET_SCL_SDA_HIGH:
    SET_OUTPUT_PIN_VALUE_HIGH BLOCK_WRITE_SLAVE_ADDRESS_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  read the slave address from configuration registers.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
BLOCK_WRITE_SLAVE_ADDRESS_SETUP:
    READ_ADDRESS_REGISTER BLOCK_WRITE_SLAVE_ADDRESS_RW_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  configure the read/write bit in the slave address register for transmission
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
BLOCK_WRITE_SLAVE_ADDRESS_RW_SETUP:    
    LSL     R13.w2, R13.w2, 9
    CLR     R16, R16, ICSS_I2C_READ_WRITE_BIT
    CLR     R13.w2, R13.w2, 8
    AND     R15.b0, R15.b0, 0x00
    UPDATE_NEXT_LOCAL_STATE BLOCK_WRITE_DATA_COUNT
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Read the number of 8 bits data need to be read or writen 
;  also initialize the data count and bit count register to 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
BLOCK_WRITE_DATA_COUNT:
    LBBO    &WORK_REG_4.w0, R10, ICSS_I2C_CNT_OFFSET, 2
    QBLT    BLOCK_WRITE_DATA_COUNT_ERROR, WORK_REG_4.w0, 0xFF
    QBGT    BLOCK_WRITE_DATA_COUNT_ERROR, WORK_REG_4.w0, 0x01
    AND     R15.b3, WORK_REG_4.b0, 0xFF
    AND     R17.b2, R15.b3, R15.b3
    AND     R15.b2, R15.b2, 0x00
    LBBO    &R15.b1, R10, ICSS_I2C_PRU_CMD_CODE_OFFSET, 1
    UPDATE_NEXT_LOCAL_STATE START_CONDITION_SDA_LOW
    STATE_TASK_OVER

BLOCK_WRITE_DATA_COUNT_ERROR:
    LDI     WORK_REG_4.w0, INVALID_DATA_COUNT
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_READY
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the local register to indicate smbus block read command mode
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
BLOCK_READ_MODE:
    SET_EDIO_DATAOUT_VALUE
    CLR     R16, R16, ICSS_I2C_ADDRESSING_MODE_BIT 
    UPDATE_NEXT_GLOBAL_STATE CMD_CODE_SDA_BEGIN
    UPDATE_NEXT_LOCAL_STATE BLOCK_READ_SET_SCL_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the value on iep gpo enable register to high value
;  this will pull the line to high impedence and open drain will keep the line high
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
BLOCK_READ_SET_SCL_SDA_HIGH:
    SET_OUTPUT_PIN_VALUE_HIGH BLOCK_READ_SLAVE_ADDRESS_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  read the slave address from configuration registers.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
BLOCK_READ_SLAVE_ADDRESS_SETUP:
    READ_ADDRESS_REGISTER BLOCK_READ_SLAVE_ADDRESS_RW_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  configure the read/write bit in the slave address register for transmission
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
BLOCK_READ_SLAVE_ADDRESS_RW_SETUP:    
    LSL     R13.w2, R13.w2, 9
    SET     R16, R16, ICSS_I2C_READ_WRITE_BIT
    CLR     R13.w2, R13.w2, 8
    AND     R15.b0, R15.b0, 0x00
    UPDATE_NEXT_LOCAL_STATE BLOCK_READ_DATA_COUNT
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Read the number of 8 bits data need to be read or writen 
;  also initialize the data count and bit count register to 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
BLOCK_READ_DATA_COUNT:
    AND     R15.b2, R15.b2, 0x00
    LBBO    &R15.b1, R10, ICSS_I2C_PRU_CMD_CODE_OFFSET, 1
    UPDATE_NEXT_LOCAL_STATE START_CONDITION_SDA_LOW
    STATE_TASK_OVER


