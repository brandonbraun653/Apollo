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
; file:   I2C_function.h
;
; brief:  This files contains all state table function 
;
;
;  (C) Copyright 2017-2018, Texas Instruments, Inc
;
;

    .if    !$defined("__I2C_function_h")
__I2C_function_h    .set 1

    .include "I2C_macros.h"

;----------------------------------------------------------------------
; Macro Name: SEND_TX_DATA_CHECK_FOR_ACK
; Description: send 8 bits of Tx data
;              check if ACK is recieved from slave or not.
;              keep on sending until all data is sent.
; Input Parameters: arg1 is register to be used for reading that data.
; Input Parameters: arg2 is Label on new memory location for TX DATA complete
; Input Parameters: arg3 is Label on new memory location for No ACK
; Output Parameters: none
;----------------------------------------------------------------------
SEND_TX_DATA_CHECK_FOR_ACK    .macro    arg1, arg2, arg3
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  modify the SDA pin value based on the most significant bit of DATA value
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
tx_data_sda_begin?:
    QBBC    tx_data_sda_low?, arg1, 7
    SET_SDA_PIN_HIGH
    JMP     tx_data_sda_continue?
tx_data_sda_low?:
    SET_SDA_PIN_LOW
tx_data_sda_continue?:
    LSL     arg1, arg1, 1
    ADD     R15.b0, R15.b0, 0x01
    LDI     R13.w0, $CODE(tx_data_scl_begin?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL high for sending SDA bit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
tx_data_scl_begin?:
    SET_SCL_PIN_HIGH
    LDI     R13.w0, $CODE(tx_data_sda_read?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Jump to next state as this is tx mode, done for matching timing parameter.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
tx_data_sda_read?:
    LDI     R13.w0, $CODE(tx_data_scl_end?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low for stop sending SDA bit
;  make decision for sending next data bit or check for ACK
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
tx_data_scl_end?:
    SET_SCL_PIN_LOW
    QBGT    tx_sda_next_bit?, R15.b0, 0x08
    LDI     R13.w0, $CODE(tx_data_ack_begin?)
    STATE_TASK_OVER

tx_sda_next_bit?:
    LDI     R13.w0, $CODE(tx_data_sda_begin?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  release SDA line so slave can drive it.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
tx_data_ack_begin?:
    SET_SDA_PIN_HIGH
    LDI     R13.w0, $CODE(tx_data_ack_scl_begin?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL high for reading ACK bit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
tx_data_ack_scl_begin?:
    SET_SCL_PIN_HIGH
    LDI     R13.w0, $CODE(tx_data_ack_read?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SDA line for reading ACK bit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
tx_data_ack_read?:
    READ_SDA_PIN_ACK
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
    QBBS    tx_data_ack_read_next_state?, R16, ICSS_I2C_SMBUS_BURST_BIT
    .endif
    LDI     R13.w0, $CODE(tx_data_ack_scl_end?)
    STATE_TASK_OVER

    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
tx_data_ack_read_next_state?:
    LDI     R13.w0, $CODE(tx_data_ack_scl_end_v2?)
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low
;  read if ACK bit is set then check if data is still left to be sent
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
tx_data_ack_scl_end?:
    SET_SCL_PIN_LOW
    QBBS    tx_data_ack_not_recieved?, R16, ICSS_I2C_ACK_RECIEVED_BIT
    ADD     R15.b2, R15.b2, 0x01
    AND     R15.b0, R15.b0, 0x00
    QBGT    tx_mode_continue?, R15.b2, R15.b3
    AND     R15.b2, R15.b2, 0x00
    LDI     R13.w0, $CODE(arg2)
    STATE_TASK_OVER
tx_mode_continue?:
    LBBO    &arg1, R11, R15.b2, 1
    LDI     R13.w0, $CODE(tx_data_sda_begin?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low
;  read if ACK bit is set then check if data is still left to be sent
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
tx_data_ack_scl_end_v2?:
    SET_SCL_PIN_LOW
    QBBS    tx_data_ack_not_recieved?, R16, ICSS_I2C_ACK_RECIEVED_BIT
    AND     R15.b0, R15.b0, 0x00
    AND     R15.b2, R15.b2, 0x00
    CLR     R16, R16, ICSS_I2C_SMBUS_BURST_BIT
    LBBO    &arg1, R11, R15.b2, 1
    LDI     R13.w0, $CODE(arg2)
    STATE_TASK_OVER
    .endif

tx_data_ack_not_recieved?:
    LDI     R13.w0, $CODE(no_tx_data_ack_recieved?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  if no data ack is recieved, response with no ack in response command
;  raise an interrupt
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
no_tx_data_ack_recieved?:
    SET_SCL_PIN_HIGH
    LDI     WORK_REG_4.w0, DATA_ACKNOWLDEGE_FAILED
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    LDI     R13.w0, $CODE(arg3)
    STATE_TASK_OVER

    .endm


;----------------------------------------------------------------------
; Macro Name: READ_RX_DATA_AND_SEND_ACK
; Description: read 8 bits of Rx data then send ack
;              keep on sending until all data is read.
; Input Parameters: arg1 is register to be used for reading data.
; Input Parameters: arg2 is Label on new memory location for DATA complete
; Output Parameters: none
;----------------------------------------------------------------------
READ_RX_DATA_AND_SEND_ACK    .macro    arg1, arg2
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  release SDA line so slave can drive it.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
rx_data_sda_begin?:
    SET_SDA_PIN_HIGH
    LDI     R13.w0, $CODE(rx_data_scl_begin?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL high for reading data value
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
rx_data_scl_begin?:
    SET_SCL_PIN_HIGH
    LSL     arg1, arg1, 1
    LDI     R13.w0, $CODE(rx_data_sda_read?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Read the SDA pin value and store it in the MSB of receive register
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
rx_data_sda_read?:
    QBBS    rx_data_sda_high?, R31, R14.b1
    AND     arg1, arg1, 0xFE
    JMP     rx_data_sda_read_continue?
rx_data_sda_high?:
    OR      arg1, arg1, 0x01
rx_data_sda_read_continue?:
    ADD     R15.b0, R15.b0, 0x01
    LDI     R13.w0, $CODE(rx_data_scl_end?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low for finishing data read
;  also check if all the data needed to read is over then send ACK
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
rx_data_scl_end?:
    SET_SCL_PIN_LOW
    QBGT    rx_sda_next_bit?, R15.b0, 0x08
    ADD     R15.b2, R15.b2, 0x01
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
    QBBS    rx_data_next_state?, R16, ICSS_I2C_SMBUS_BURST_BIT
    .endif
    QBGT    rx_data_next_state?, R15.b2, R15.b3
    QBBC    rx_data_next_state?, R16, ICSS_I2C_RECIEVE_NACK_BIT
    LDI     R13.w0, $CODE(rx_data_nack_begin?)
    STATE_TASK_OVER

rx_data_next_state?:
    LDI     R13.w0, $CODE(rx_data_ack_begin?)
    STATE_TASK_OVER    

rx_sda_next_bit?:
    LDI     R13.w0, $CODE(rx_data_sda_begin?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SDA line low to send an ACK.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
rx_data_ack_begin?:
    SET_SDA_PIN_LOW
    LDI     R13.w0, $CODE(rx_data_ack_scl_begin?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SDA line low to send an NACK.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
rx_data_nack_begin?:
    SET_SDA_PIN_HIGH
    LDI     R13.w0, $CODE(rx_data_ack_scl_begin?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL high for reading ACK bit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
rx_data_ack_scl_begin?:
    SET_SCL_PIN_HIGH
    SBBO    &R15.b3, R10, ICSS_I2C_CNT_OFFSET, 1
    LDI     R13.w0, $CODE(rx_data_ack_read?)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  jump to next state, done to match the timing
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
rx_data_ack_read?:
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
    QBBS    rx_data_ack_read_next_state?, R16, ICSS_I2C_SMBUS_BURST_BIT
    .endif
    LDI     R13.w0, $CODE(rx_data_ack_scl_end?)
    STATE_TASK_OVER

    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
rx_data_ack_read_next_state?:
    LDI     R13.w0, $CODE(rx_data_ack_scl_end_v2?)
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low for finishing data read
;  also check if all the data needed to read is over then finish read
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
rx_data_ack_scl_end?:
    SET_SCL_PIN_LOW
    AND     R15.b0, R15.b0, 0x00
    SUB     WORK_REG_4.b0, R15.b2, 1
    SBBO    &arg1, R12, WORK_REG_4.b0, 1
    QBGT    rx_mode_continue?, R15.b2, R15.b3
    AND     R15.b2, R15.b2, 0x00
    LDI     R13.w0, $CODE(arg2)
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low for finishing data read
;  also check if all the data needed to read is over then finish read
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
rx_data_ack_scl_end_v2?:
    SET_SCL_PIN_LOW
    AND     R15.b0, R15.b0, 0x00
    AND     R15.b2, R15.b2, 0x00
    CLR     R16, R16, ICSS_I2C_SMBUS_BURST_BIT
    LDI     R13.w0, $CODE(arg2)
    STATE_TASK_OVER
    .endif

rx_mode_continue?:
    LDI     R13.w0, $CODE(rx_data_sda_begin?)
    STATE_TASK_OVER

    .endm


    .endif  ;__I2C_function_h
