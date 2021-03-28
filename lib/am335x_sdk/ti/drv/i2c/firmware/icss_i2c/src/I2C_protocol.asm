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
; file:   I2C_protocol.asm
;
; brief:  This files contains all state table transition function.
;
;
;  (C) Copyright 2017-2018, Texas Instruments, Inc
;
;

    ;.fcnolist   ; suppress listing of false conditional blocks in lister output

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; In all state, the processing is broken into multiple state we have a tight budget of 
; 20 cycles per state.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Includes Section
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .include "I2C_function.h"

    .def    RESET_MODE
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
    ;
    ; SMBUS not supported on AM437x ICSS0.
    ;   AM437x IMEM size 4 kB.
    ;   This is too small for current program size w/ SMBUS support.
    ;
    
    ; These functions are exported for SMBSUS functionality.
    ; Otherwise used locally in this file.
    .def    STOP_CONDITION_SCL_HIGH             
    .def    RAISE_HOST_INTERRUPT_MEM_FOR_READY
    .def    RX_DATA_SDA_BEGIN
    .def    START_CONDITION_SDA_LOW             
    .def    TX_DATA_SDA_BEGIN
    .def    DATA_PROCESSING_COMPLETE
    
    .def    CMD_CODE_SDA_BEGIN      ; SMBUS  
    .ref    QUICK_CMD_MODE          ; SMBUS
    .ref    SEND_BYTE_MODE          ; SMBUS
    .ref    RECEIVE_BYTE_MODE       ; SMBUS
    .ref    WRITE_BYTE_MODE         ; SMBUS
    .ref    READ_BYTE_MODE          ; SMBUS
    .ref    WRITE_WORD_MODE         ; SMBUS
    .ref    READ_WORD_MODE          ; SMBUS
    .ref    BLOCK_WRITE_MODE        ; SMBUS
    .ref    BLOCK_READ_MODE         ; SMBUS
    .endif


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This is the initial mode in which comes out of reset
;  It checks if the enabled bit is set or not.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RESET_MODE:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_CON_OFFSET, 4
    QBBC    RESET_MODE_RETURN, WORK_REG_4, ICSS_I2C_MODULE_ENABLE_BIT
    UPDATE_NEXT_LOCAL_STATE CHECK_SETUP_COMMAND

RESET_MODE_RETURN:
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  In this state, firmware is only out of reset
;  The only command it can accept in the state is setup command.
;  if any other command is passed it will send invalid command response back
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CHECK_SETUP_COMMAND:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBEQ    CHECK_SETUP_COMMAND_RETURN, WORK_REG_4.w2, 0x00
    QBNE    CHECK_SETUP_COMMAND_ERROR, WORK_REG_4.w2, ICSS_I2C_SETUP_CMD
     
    UPDATE_NEXT_LOCAL_STATE SETUP_I2C_PRU_PIN_NUM
    STATE_TASK_OVER

CHECK_SETUP_COMMAND_ERROR:
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_ERROR
    LDI     WORK_REG_4.w0, INVALID_COMMAND
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    STATE_TASK_OVER

CHECK_SETUP_COMMAND_RETURN:
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This state load the PRU pins no. for the instance.
;  It load SDA -> IEP DIGIO, SCL -> PRU GPO and SDA -> PRU GPI pins numbers 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SETUP_I2C_PRU_PIN_NUM:
    LBBO    &R14, R10, ICSS_I2C_PRU_PIN_OFFSET, 4
    LDI     R14.b3, 0x00
    UPDATE_NEXT_LOCAL_STATE SETUP_I2C_INST_ID
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This instance id of the FW is being loaded into the register.
;  This id helps the FW to decide which bit to raise high when raising an interrupt.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SETUP_I2C_INST_ID:
    LBBO    &R14.b3, R10, ICSS_I2C_PRU_INST_ID_OFFSET, 1
    UPDATE_NEXT_LOCAL_STATE SETUP_I2C_SCL_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This set the SCL clk line and SDA data line high.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SETUP_I2C_SCL_SDA_HIGH:
    SET_SCL_PIN_HIGH
    SET_SDA_PIN_HIGH
    UPDATE_NEXT_LOCAL_STATE SETUP_I2C_TX_FIFO_SIZE
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This configures the Tx fifo size of the firmware
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SETUP_I2C_TX_FIFO_SIZE:
    LBBO    &R16.b2, R10, ICSS_I2C_BUF_OFFSET, 1
    UPDATE_NEXT_LOCAL_STATE SETUP_I2C_RX_FIFO_SIZE
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This configures the Rx fifo size of the firmware
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SETUP_I2C_RX_FIFO_SIZE:
    LBBO    &R16.b3, R10, ICSS_I2C_BUF_OFFSET+1, 1
    UPDATE_NEXT_LOCAL_STATE SETUP_I2C_MASTER_SLAVE_MODE
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This configures the firmware into master or slave mode
;  currently only master mode is supported.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SETUP_I2C_MASTER_SLAVE_MODE:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_CON_OFFSET, 4
    QBBC    SETUP_I2C_MASTER_SLAVE_ERROR, WORK_REG_4, ICSS_I2C_MASTER_SLAVE_MODE_BIT
    UPDATE_NEXT_LOCAL_STATE SETUP_I2C_ADDRESSING_MODE
    STATE_TASK_OVER

SETUP_I2C_MASTER_SLAVE_ERROR:
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_ERROR
    LDI     WORK_REG_4.w0, MASTER_SLAVE_MODE_FAILED
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This configures the firmware for 10 bits or 8 bits addressing mode
;  currently only 7 bits mode is supported.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SETUP_I2C_ADDRESSING_MODE:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_CON_OFFSET, 4
    QBBS    SETUP_I2C_ADDRESSING_10BIT, WORK_REG_4, ICSS_I2C_ADDRESSING_MODE_BIT
    CLR     R16, R16, ICSS_I2C_ADDRESSING_MODE_BIT
    JMP     SETUP_I2C_ADDRESSING_DONE

SETUP_I2C_ADDRESSING_10BIT:
    SET     R16, R16, ICSS_I2C_ADDRESSING_MODE_BIT

SETUP_I2C_ADDRESSING_DONE:
    UPDATE_NEXT_LOCAL_STATE SETUP_I2C_START_CTRL
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This configures the firmware for sending start bit at beginning or not
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SETUP_I2C_START_CTRL:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_CON_OFFSET, 4
    QBBC    SETUP_I2C_NO_START_CTRL, WORK_REG_4, ICSS_I2C_START_BIT
    SET     R16, R16, ICSS_I2C_START_BIT
    JMP     SETUP_I2C_START_DONE

SETUP_I2C_NO_START_CTRL:
    CLR     R16, R16, ICSS_I2C_START_BIT

SETUP_I2C_START_DONE:
    UPDATE_NEXT_LOCAL_STATE SETUP_I2C_STOP_CTRL
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This configures the firmware for sending stop bit at end of data transfer
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SETUP_I2C_STOP_CTRL:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_CON_OFFSET, 4
    QBBC    SETUP_I2C_NO_STOP_CTRL, WORK_REG_4, ICSS_I2C_STOP_BIT
    SET     R16, R16, ICSS_I2C_STOP_BIT
    JMP     SETUP_I2C_STOP_DONE

SETUP_I2C_NO_STOP_CTRL:
    CLR     R16, R16, ICSS_I2C_STOP_BIT

SETUP_I2C_STOP_DONE:
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
    UPDATE_NEXT_LOCAL_STATE SETUP_I2C_SMBUS_BURST_CTRL
    .else ; remove SMBUS, bypass SMBUS Burst mode set up
    UPDATE_NEXT_LOCAL_STATE SETUP_I2C_NACK_CTRL
    .endif
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This configures the firmware for sending start bit at beginning or not
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
SETUP_I2C_SMBUS_BURST_CTRL:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_CON_OFFSET, 4
    QBBC    SETUP_I2C_NO_SMBUS_BURST_CTRL, WORK_REG_4, ICSS_I2C_SMBUS_BURST_BIT
    SET     R16, R16, ICSS_I2C_SMBUS_BURST_BIT
    JMP     SETUP_I2C_SMBUS_BURST_DONE

SETUP_I2C_NO_SMBUS_BURST_CTRL:
    CLR     R16, R16, ICSS_I2C_SMBUS_BURST_BIT

SETUP_I2C_SMBUS_BURST_DONE:
    UPDATE_NEXT_LOCAL_STATE SETUP_I2C_NACK_CTRL
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  This configures the firmware for ending the read operation with NACK or not
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SETUP_I2C_NACK_CTRL:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_CON_OFFSET, 4
    QBBC    SETUP_I2C_NO_NACK_CTRL, WORK_REG_4, ICSS_I2C_RECIEVE_NACK_BIT
    SET     R16, R16, ICSS_I2C_RECIEVE_NACK_BIT
    JMP     SETUP_I2C_NACK_DONE

SETUP_I2C_NO_NACK_CTRL:
    CLR     R16, R16, ICSS_I2C_RECIEVE_NACK_BIT

SETUP_I2C_NACK_DONE:
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_READY
    LDI     WORK_REG_4.w0, COMMAND_SUCCESS
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Set the MMap for host to find out which instance raised the interrupt.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RAISE_HOST_INTERRUPT_MEM_FOR_ERROR:
    RAISE_INTERRUPT_MEM_FOR_HOST RAISE_HOST_INTERRUPT_FOR_ERROR

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Raise interrupt for Host while the firmware was trying to configure
;  setup procedures.
;  after raising the interrupt wait for host to respond.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RAISE_HOST_INTERRUPT_FOR_ERROR:
    RAISE_INTERRUPT_FOR_HOST CHECK_HOST_INTERRUPT_ERROR_RECEIVED

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  check for host to receive the command response
;  then jump to "reset" mode again for reconfiguration
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CHECK_HOST_INTERRUPT_ERROR_RECEIVED:
    CHECK_INTERRUPT_RECEIVED RESET_MODE, RAISE_HOST_INTERRUPT_FOR_ERROR

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Set the MMap for host to find out which instance raised the interrupt.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RAISE_HOST_INTERRUPT_MEM_FOR_READY:
    RAISE_INTERRUPT_MEM_FOR_HOST RAISE_HOST_INTERRUPT_FOR_READY

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Raise interrupt for Host while the firmware succesfully does setup configuration
;  but fails to any transaction i.e. read or write.
;  after raising the interrupt wait for host to respond.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RAISE_HOST_INTERRUPT_FOR_READY:
    RAISE_INTERRUPT_FOR_HOST CHECK_HOST_INTERRUPT_READY_RECEIVED

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  check for host to receive the command response
;  then jump to "firmware ready" mode again to do a transaction again
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CHECK_HOST_INTERRUPT_READY_RECEIVED:
    CHECK_INTERRUPT_RECEIVED FIRMWARE_READY, RAISE_HOST_INTERRUPT_FOR_READY

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  In this state, firmware is out of reset succesfully
;  firmware is ready to accept any command and check if the command word is not "0x0000"
;  then start to check which command is passed.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
FIRMWARE_READY:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBEQ    FIRMWARE_READY_RETURN, WORK_REG_4.w2, 0x00
    UPDATE_NEXT_LOCAL_STATE ICSS_I2C_RESET_CMD_CHECK

FIRMWARE_READY_RETURN:
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the reset command has been passed.
;  if reset command is passed then resets the firmware else check for another command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ICSS_I2C_RESET_CMD_CHECK:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_I2C_RESET_CMD_CHECK_RETURN, WORK_REG_4.w2, ICSS_I2C_RESET_CMD
    UPDATE_NEXT_LOCAL_STATE RESET_SCL_SDA_HIGH
    LDI     WORK_REG_4.w0, COMMAND_SUCCESS
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    STATE_TASK_OVER

ICSS_I2C_RESET_CMD_CHECK_RETURN:
    UPDATE_NEXT_LOCAL_STATE ICSS_I2C_SETUP_CMD_CHECK
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the value on iep gpo enable register to high value
;  this will pull the line to high impedence and open drain will keep the line high
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RESET_SCL_SDA_HIGH:
    SET_OUTPUT_PIN_VALUE_HIGH RAISE_HOST_INTERRUPT_MEM_FOR_ERROR

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the setup command has been passed.
;  if setup command is passed then redo the firmware setup procedure 
;  else check for another command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ICSS_I2C_SETUP_CMD_CHECK:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_I2C_SETUP_CMD_CHECK_RETURN, WORK_REG_4.w2, ICSS_I2C_SETUP_CMD
    UPDATE_NEXT_LOCAL_STATE RESET_MODE
    STATE_TASK_OVER

ICSS_I2C_SETUP_CMD_CHECK_RETURN:
    UPDATE_NEXT_LOCAL_STATE ICSS_I2C_RX_CMD_CHECK
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the Rx command has been passed.
;  if Rx command is passed then start receive data procedure
;  else check for another command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ICSS_I2C_RX_CMD_CHECK:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_I2C_RX_CMD_CHECK_RETURN, WORK_REG_4.w2, ICSS_I2C_RX_CMD
    UPDATE_NEXT_LOCAL_STATE RX_MODE
    STATE_TASK_OVER

ICSS_I2C_RX_CMD_CHECK_RETURN:
    UPDATE_NEXT_LOCAL_STATE ICSS_I2C_TX_CMD_CHECK
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the Tx command has been passed.
;  if Tx command is passed then start transmit data procedure
;  else check for another command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ICSS_I2C_TX_CMD_CHECK:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_I2C_TX_CMD_CHECK_RETURN, WORK_REG_4.w2, ICSS_I2C_TX_CMD
    UPDATE_NEXT_LOCAL_STATE TX_MODE
    STATE_TASK_OVER

ICSS_I2C_TX_CMD_CHECK_RETURN:
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
    UPDATE_NEXT_LOCAL_STATE ICSS_SMBUS_QUICK_CHECK
    .else ; remove SMBUS, bypass all SMBUS command checks
    UPDATE_NEXT_LOCAL_STATE ICSS_I2C_READ_SCL_CMD_CHECK
    .endif
    STATE_TASK_OVER


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the smbus Quick command has been passed.
;  if Quick command is passed then start Quick data procedure
;  else check for another command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
ICSS_SMBUS_QUICK_CHECK:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_SMBUS_QUICK_CMD_CHECK_NEXT, WORK_REG_4.w2, ICSS_SMBUS_QUICK_CMD
    UPDATE_NEXT_LOCAL_STATE QUICK_CMD_MODE
    STATE_TASK_OVER
    
ICSS_SMBUS_QUICK_CMD_CHECK_NEXT:
    UPDATE_NEXT_LOCAL_STATE ICSS_SMBUS_SEND_BYTE
    STATE_TASK_OVER
    .endif
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the smbus send byte command has been passed.
;  if send byte command is passed then start send byte data procedure
;  else check for another command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
ICSS_SMBUS_SEND_BYTE:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_SMBUS_SEND_BYTE_CHECK_NEXT, WORK_REG_4.w2, ICSS_SMBUS_SEND_BYTE_CMD
    UPDATE_NEXT_LOCAL_STATE SEND_BYTE_MODE
    STATE_TASK_OVER
    
ICSS_SMBUS_SEND_BYTE_CHECK_NEXT:
    UPDATE_NEXT_LOCAL_STATE ICSS_SMBUS_RECEIVE_BYTE
    STATE_TASK_OVER
    .endif
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the smbus receive byte command has been passed.
;  if receive byte command is passed then start receive byte data procedure
;  else check for another command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
ICSS_SMBUS_RECEIVE_BYTE:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_SMBUS_RECEIVE_BYTE_CHECK_NEXT, WORK_REG_4.w2, ICSS_SMBUS_RECEIVE_BYTE_CMD
    UPDATE_NEXT_LOCAL_STATE RECEIVE_BYTE_MODE
    STATE_TASK_OVER
    
ICSS_SMBUS_RECEIVE_BYTE_CHECK_NEXT:
    UPDATE_NEXT_LOCAL_STATE ICSS_SMBUS_WRITE_BYTE
    STATE_TASK_OVER
    .endif
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the smbus write byte command has been passed.
;  if write byte command is passed then start write byte data procedure
;  else check for another command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
ICSS_SMBUS_WRITE_BYTE:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_SMBUS_WRITE_BYTE_CHECK_NEXT, WORK_REG_4.w2, ICSS_SMBUS_WRITE_BYTE_CMD
    UPDATE_NEXT_LOCAL_STATE WRITE_BYTE_MODE
    STATE_TASK_OVER
    
ICSS_SMBUS_WRITE_BYTE_CHECK_NEXT:
    UPDATE_NEXT_LOCAL_STATE ICSS_SMBUS_READ_BYTE
    STATE_TASK_OVER
    .endif
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the smbus read byte command has been passed.
;  if read byte command is passed then start read byte data procedure
;  else check for another command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
ICSS_SMBUS_READ_BYTE:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_SMBUS_READ_BYTE_CHECK_NEXT, WORK_REG_4.w2, ICSS_SMBUS_READ_BYTE_CMD
    UPDATE_NEXT_LOCAL_STATE READ_BYTE_MODE
    STATE_TASK_OVER
    
ICSS_SMBUS_READ_BYTE_CHECK_NEXT:
    UPDATE_NEXT_LOCAL_STATE ICSS_SMBUS_WRITE_WORD
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the smbus write word command has been passed.
;  if write word command is passed then start write word data procedure
;  else check for another command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
ICSS_SMBUS_WRITE_WORD:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_SMBUS_WRITE_WORD_CHECK_NEXT, WORK_REG_4.w2, ICSS_SMBUS_WRITE_WORD_CMD
    UPDATE_NEXT_LOCAL_STATE WRITE_WORD_MODE
    STATE_TASK_OVER
    
ICSS_SMBUS_WRITE_WORD_CHECK_NEXT:
    UPDATE_NEXT_LOCAL_STATE ICSS_SMBUS_READ_WORD
    STATE_TASK_OVER
    .endif
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the smbus read word command has been passed.
;  if read word command is passed then start read word data procedure
;  else check for another command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
ICSS_SMBUS_READ_WORD:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_SMBUS_READ_WORD_CHECK_NEXT, WORK_REG_4.w2, ICSS_SMBUS_READ_WORD_CMD
    UPDATE_NEXT_LOCAL_STATE READ_WORD_MODE
    STATE_TASK_OVER
    
ICSS_SMBUS_READ_WORD_CHECK_NEXT:
    UPDATE_NEXT_LOCAL_STATE ICSS_SMBUS_BLOCK_WRITE
    STATE_TASK_OVER
    .endif
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the smbus block write command has been passed.
;  if block write command is passed then start block write data procedure
;  else check for another command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
ICSS_SMBUS_BLOCK_WRITE:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_SMBUS_BLOCK_WRITE_CHECK_NEXT, WORK_REG_4.w2, ICSS_SMBUS_BLOCK_WRITE_CMD
    UPDATE_NEXT_LOCAL_STATE BLOCK_WRITE_MODE
    STATE_TASK_OVER

ICSS_SMBUS_BLOCK_WRITE_CHECK_NEXT:
    UPDATE_NEXT_LOCAL_STATE ICSS_SMBUS_BLOCK_READ
    STATE_TASK_OVER
    .endif
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the smbus block read command has been passed.
;  if block read command is passed then start block read data procedure
;  else no matching command has been found
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
ICSS_SMBUS_BLOCK_READ:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_SMBUS_BLOCK_READ_CHECK_NEXT, WORK_REG_4.w2, ICSS_SMBUS_BLOCK_READ_CMD
    UPDATE_NEXT_LOCAL_STATE BLOCK_READ_MODE
    STATE_TASK_OVER
    
ICSS_SMBUS_BLOCK_READ_CHECK_NEXT:
    UPDATE_NEXT_LOCAL_STATE ICSS_I2C_READ_SCL_CMD_CHECK
    STATE_TASK_OVER
    .endif
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the I2C read SCL command has been passed.
;  if this command requires the host to change the pinmux to input for SCL pin
;  else no matching command has been found
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ICSS_I2C_READ_SCL_CMD_CHECK:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_I2C_READ_SCL_CMD_CHECK_NEXT, WORK_REG_4.w2, ICSS_I2C_READ_SCL_CMD
    UPDATE_NEXT_LOCAL_STATE READ_SCL_PIN_SETUP
    STATE_TASK_OVER

ICSS_I2C_READ_SCL_CMD_CHECK_NEXT:
    UPDATE_NEXT_LOCAL_STATE ICSS_I2C_RESET_SLAVE_CMD_CHECK
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the I2C reset slave command has been passed.
;  if this command will send 9 clock pulse to device for reseting it.
;  else no matching command has been found
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ICSS_I2C_RESET_SLAVE_CMD_CHECK:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_I2C_RESET_SLAVE_CMD_CHECK_NEXT, WORK_REG_4.w2, ICSS_I2C_RESET_SLAVE_CMD
    UPDATE_NEXT_LOCAL_STATE RESET_SLAVE_SCL_BEGIN
    STATE_TASK_OVER

ICSS_I2C_RESET_SLAVE_CMD_CHECK_NEXT:
    UPDATE_NEXT_LOCAL_STATE ICSS_I2C_LOOPBACK_CMD_CHECK
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  checks if the I2C reset slave command has been passed.
;  if this command will send 9 clock pulse to device for reseting it.
;  else no matching command has been found
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ICSS_I2C_LOOPBACK_CMD_CHECK:
    LBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 4
    QBNE    ICSS_I2C_LOOPBACK_CMD_CHECK_NEXT, WORK_REG_4.w2, ICSS_I2C_LOOPBACK_CMD
    UPDATE_NEXT_LOCAL_STATE LOOPBACK_DATA_COUNT
    STATE_TASK_OVER

ICSS_I2C_LOOPBACK_CMD_CHECK_NEXT:
    UPDATE_NEXT_LOCAL_STATE FIRMWARE_READY_COMMAND_ERROR
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  no known command has been matched with passed cmd 
;  raise an interrupt and respond with error reponse word
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
FIRMWARE_READY_COMMAND_ERROR:
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_READY
    LDI     WORK_REG_4.w0, INVALID_COMMAND
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the local register to indicate tx mode
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
TX_MODE:
    CLR     R16, R16, ICSS_I2C_READ_WRITE_BIT
    UPDATE_NEXT_GLOBAL_STATE TX_DATA_SDA_BEGIN
    UPDATE_NEXT_LOCAL_STATE SET_SCL_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the local register to indicate rx mode
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RX_MODE:
    SET     R16, R16, ICSS_I2C_READ_WRITE_BIT
    UPDATE_NEXT_GLOBAL_STATE RX_DATA_SDA_BEGIN
    UPDATE_NEXT_LOCAL_STATE SET_SCL_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  set the value on iep gpo enable register to high value
;  this will pull the line to high impedence and open drain will keep the line high
;  set the value on iep gpo to low value for pulling the line
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SET_SCL_SDA_HIGH:
    SET_OUTPUT_PIN_VALUE_HIGH SLAVE_ADDRESS_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  read the slave address from configuration registers.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SLAVE_ADDRESS_SETUP:
    READ_ADDRESS_REGISTER SLAVE_ADDRESS_RW_SETUP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  configure the read/write bit in the slave address register for transmission
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SLAVE_ADDRESS_RW_SETUP:    
    READ_RW_REGISTER_BIT DATA_COUNT

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Read the number of 8 bits data need to be read or writen 
;  also initialize the data count and bit count register to 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
DATA_COUNT:
    LBBO    &WORK_REG_4.w0, R10, ICSS_I2C_CNT_OFFSET, 2
    QBLT    DATA_COUNT_ERROR, WORK_REG_4.w0, 0xFF
    QBGT    DATA_COUNT_ERROR, WORK_REG_4.w0, 0x01
    AND     R15.b3, WORK_REG_4.b0, 0xFF
    AND     R15.b2, R15.b2, 0x00
    LBBO    &R15.b1, R11, R15.b2, 1
    UPDATE_NEXT_LOCAL_STATE START_CONDITION_SDA_LOW
    STATE_TASK_OVER

DATA_COUNT_ERROR:
    LDI     WORK_REG_4.w0, INVALID_DATA_COUNT
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_READY
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SDA low for start condition
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
START_CONDITION_SDA_LOW:
    QBBC    START_CONDITION_SDA_LOW_RETURN, R16, ICSS_I2C_START_BIT
    SET_SDA_PIN_LOW
START_CONDITION_SDA_LOW_RETURN:
    UPDATE_NEXT_LOCAL_STATE START_CONDITION_SCL_LOW
    STATE_TASK_OVER
   
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low for start condition
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
START_CONDITION_SCL_LOW:
    QBBC    START_CONDITION_SCL_LOW_RETURN, R16, ICSS_I2C_START_BIT
    SET_SCL_PIN_LOW
START_CONDITION_SCL_LOW_RETURN:
    UPDATE_NEXT_LOCAL_STATE ADDRESS_SDA_BEGIN
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  modify the SDA pin value based on the most significant bit of Address register
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ADDRESS_SDA_BEGIN:
    RSB     WORK_REG_5.b0, R15.b0, 15
    QBBC    ADDRESS_SDA_LOW, R13.w2, WORK_REG_5.b0
    SET_SDA_PIN_HIGH
    JMP     ADDRESS_SDA_CONTINUE
ADDRESS_SDA_LOW:
    SET_SDA_PIN_LOW
ADDRESS_SDA_CONTINUE:
    ADD     R15.b0, R15.b0, 0x01
    UPDATE_NEXT_LOCAL_STATE ADDRESS_SCL_BEGIN
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL high for sending SDA bit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ADDRESS_SCL_BEGIN:
    SET_SCL_PIN_HIGH
    UPDATE_NEXT_LOCAL_STATE ADDRESS_SDA_READ
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  nothing to be read in address tx mode
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ADDRESS_SDA_READ:
    UPDATE_NEXT_LOCAL_STATE ADDRESS_SCL_END
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low for ending the transmission of bit
;  also decide the next state based on all the bits have been sent or not.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ADDRESS_SCL_END:
    SET_SCL_PIN_LOW
    QBGT    SDA_NEXT_BIT, R15.b0, 0x08
    UPDATE_NEXT_LOCAL_STATE ADDRESS_ACK_BEGIN
    STATE_TASK_OVER

SDA_NEXT_BIT:
    UPDATE_NEXT_LOCAL_STATE ADDRESS_SDA_BEGIN
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  release SDA line so slave can drive it.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ADDRESS_ACK_BEGIN:
    SET_SDA_PIN_HIGH
    UPDATE_NEXT_LOCAL_STATE ADDRESS_ACK_SCL_BEGIN
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL high for reading ACK bit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ADDRESS_ACK_SCL_BEGIN:
    SET_SCL_PIN_HIGH
    AND     R15.b0, R15.b0, 0x00
    UPDATE_NEXT_LOCAL_STATE ADDRESS_ACK_READ
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SDA line for reading ACK bit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ADDRESS_ACK_READ:
    READ_SDA_PIN_ACK
    UPDATE_NEXT_LOCAL_STATE ADDRESS_ACK_SCL_END
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low
;  read if ACK bit is set then start sending or receiving data else indicate no ack
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ADDRESS_ACK_SCL_END:
    SET_SCL_PIN_LOW
    QBBS    ADDRESS_ACK_NOT_RECIEVED, R16, ICSS_I2C_ACK_RECIEVED_BIT
    QBBC    ADDRESS_ACK_SCL_END_DONE, R16, ICSS_I2C_ADDRESSING_MODE_BIT
    QBEQ    ADDRESS_ACK_SCL_END_DONE, R15.b2, 0x01
    ADD     R15.b2, R15.b2, 0x01
    UPDATE_NEXT_LOCAL_STATE ADDRESS_SDA_BEGIN
    STATE_TASK_OVER

ADDRESS_ACK_SCL_END_DONE:
    AND     R15.b2, R15.b2, 0x00
    COPY_LOCAL_TO_GLOBAL_STATE
    STATE_TASK_OVER

ADDRESS_ACK_NOT_RECIEVED:
    UPDATE_NEXT_LOCAL_STATE NO_ADDRESS_ACK_RECIEVED
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  if no address ack is recieved, response with no ack in response command
;  raise an interrupt
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
NO_ADDRESS_ACK_RECIEVED:
    SET_SCL_PIN_HIGH
    LDI     WORK_REG_4.w0, ADDRESS_ACKNOWLDEGE_FAILED
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_READY
    STATE_TASK_OVER
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  start sending TX data and wait for ACK receive
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
TX_DATA_SDA_BEGIN:
    SEND_TX_DATA_CHECK_FOR_ACK R15.b1, DATA_PROCESSING_COMPLETE, RAISE_HOST_INTERRUPT_MEM_FOR_READY

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  start sending RX data and send ACK to device
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RX_DATA_SDA_BEGIN:
    READ_RX_DATA_AND_SEND_ACK R15.b1, DATA_PROCESSING_COMPLETE

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  start sending TX data and wait for ACK receive for smbus Burst Mode
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
TX_DATA_SDA_BEGIN_BURST:
    SEND_TX_DATA_CHECK_FOR_ACK R17.b2, TX_DATA_SDA_BEGIN, RAISE_HOST_INTERRUPT_MEM_FOR_READY
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  start sending RX data and send ACK to device for smbus Burst Mode
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
RX_DATA_SDA_BEGIN_BURST:
    READ_RX_DATA_AND_SEND_ACK R15.b3, RX_DATA_SDA_BEGIN
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  modify the SDA pin value based on the most significant bit of DATA value
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
CMD_CODE_SDA_BEGIN:
    QBBC    CMD_CODE_SDA_LOW, R15.b1, 7
    SET_SDA_PIN_HIGH
    JMP     CMD_CODE_SDA_CONTINUE
CMD_CODE_SDA_LOW:
    SET_SDA_PIN_LOW
CMD_CODE_SDA_CONTINUE:
    LSL     R15.b1, R15.b1, 1
    ADD     R15.b0, R15.b0, 0x01
    UPDATE_NEXT_LOCAL_STATE CMD_CODE_SCL_BEGIN
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL high for sending SDA bit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
CMD_CODE_SCL_BEGIN:
    SET_SCL_PIN_HIGH
    UPDATE_NEXT_LOCAL_STATE CMD_CODE_SDA_READ
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Jump to next state as this is tx mode, done for matching timing parameter.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
CMD_CODE_SDA_READ:
    UPDATE_NEXT_LOCAL_STATE CMD_CODE_SCL_END
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low for stop sending SDA bit
;  make decision for sending next data bit or check for ACK
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
CMD_CODE_SCL_END:
    SET_SCL_PIN_LOW
    QBGT    CMD_CODE_SDA_NEXT_BIT, R15.b0, 0x08
    UPDATE_NEXT_LOCAL_STATE CMD_CODE_ACK_BEGIN
    STATE_TASK_OVER

CMD_CODE_SDA_NEXT_BIT:
    UPDATE_NEXT_LOCAL_STATE CMD_CODE_SDA_BEGIN
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  release SDA line so slave can drive it.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
CMD_CODE_ACK_BEGIN:
    SET_SDA_PIN_HIGH
    SET     R13.w2, R13.w2, 0
    UPDATE_NEXT_LOCAL_STATE CMD_CODE_ACK_SCL_BEGIN
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL high for reading ACK bit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
CMD_CODE_ACK_SCL_BEGIN:
    SET_SCL_PIN_HIGH
    UPDATE_NEXT_LOCAL_STATE CMD_CODE_ACK_READ
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SDA line for reading ACK bit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
CMD_CODE_ACK_READ:
    READ_SDA_PIN_ACK
    QBBS    CMD_CODE_ACK_READ_NEXT_STATE, R16, ICSS_I2C_SMBUS_BURST_BIT
    UPDATE_NEXT_LOCAL_STATE CMD_CODE_ACK_SCL_END
    STATE_TASK_OVER

CMD_CODE_ACK_READ_NEXT_STATE:
    UPDATE_NEXT_LOCAL_STATE CMD_CODE_ACK_SCL_END_V2
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low
;  read if ACK bit is set then check if data is still left to be sent
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
CMD_CODE_ACK_SCL_END:
    SET_SCL_PIN_LOW
    QBBS    CMD_CODE_ACK_NOT_RECIEVED, R16, ICSS_I2C_ACK_RECIEVED_BIT
    AND     R15.b2, R15.b2, 0x00
    AND     R15.b0, R15.b0, 0x00
    QBBS    CMD_CODE_RX, R16, ICSS_I2C_READ_WRITE_BIT
    LBBO    &R15.b1, R11, R15.b2, 1
    UPDATE_NEXT_LOCAL_STATE TX_DATA_SDA_BEGIN
    STATE_TASK_OVER

CMD_CODE_RX:
     UPDATE_NEXT_LOCAL_STATE START_CONDITION_SDA_LOW
     SET    R13.w2, R13.w2, 8
     UPDATE_NEXT_GLOBAL_STATE RX_DATA_SDA_BEGIN
     STATE_TASK_OVER
    .endif
    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low
;  read if ACK bit is set then check if data is still left to be sent
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
CMD_CODE_ACK_SCL_END_V2:
    SET_SCL_PIN_LOW
    QBBS    CMD_CODE_ACK_NOT_RECIEVED, R16, ICSS_I2C_ACK_RECIEVED_BIT
    AND     R15.b2, R15.b2, 0x00
    AND     R15.b0, R15.b0, 0x00
    QBBS    CMD_CODE_RX_V2, R16, ICSS_I2C_READ_WRITE_BIT
    LBBO    &R15.b1, R11, R15.b2, 1
    UPDATE_NEXT_LOCAL_STATE TX_DATA_SDA_BEGIN_BURST
    STATE_TASK_OVER

CMD_CODE_RX_V2:
    UPDATE_NEXT_LOCAL_STATE START_CONDITION_SDA_LOW
    SET    R13.w2, R13.w2, 8
    UPDATE_NEXT_GLOBAL_STATE RX_DATA_SDA_BEGIN_BURST
    STATE_TASK_OVER
    .endif
     
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
CMD_CODE_ACK_NOT_RECIEVED:
    UPDATE_NEXT_LOCAL_STATE NO_CMD_CODE_ACK_RECIEVED
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  if no data ack is received, response with no ack in response command
;  raise an interrupt
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    .if !$defined(AM437X_ICSS0) ; remove SMBUS for AM437x ICSS0
NO_CMD_CODE_ACK_RECIEVED:
    LDI     WORK_REG_4.w0, DATA_ACKNOWLDEGE_FAILED
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_READY
    STATE_TASK_OVER
    .endif

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  data transmit or receive is over
;  check whether to sent stop bit or not
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
DATA_PROCESSING_COMPLETE:
    SET_SDA_PIN_LOW
    QBBC    COMPLETE_WITH_NO_STOP, R16, ICSS_I2C_STOP_BIT
    UPDATE_NEXT_LOCAL_STATE STOP_CONDITION_SCL_HIGH
    STATE_TASK_OVER

COMPLETE_WITH_NO_STOP:
    UPDATE_NEXT_LOCAL_STATE NO_STOP_CONDITION_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  send stop condition by making SCL high first
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
STOP_CONDITION_SCL_HIGH:
    SET_SCL_PIN_HIGH
    UPDATE_NEXT_LOCAL_STATE STOP_CONDITION_SDA_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  send stop condition by making SDA high next
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
STOP_CONDITION_SDA_HIGH:
    SET_SDA_PIN_HIGH
    LDI     WORK_REG_4.w0, COMMAND_SUCCESS
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_READY
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  do not send stop condition by making SDA high first
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
NO_STOP_CONDITION_SDA_HIGH:
    SET_SDA_PIN_HIGH
    UPDATE_NEXT_LOCAL_STATE NO_STOP_CONDITION_SCL_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  do not send stop condition by making SCL high next
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
NO_STOP_CONDITION_SCL_HIGH:
    SET_SCL_PIN_HIGH
    LDI     WORK_REG_4.w0, COMMAND_SUCCESS
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_READY
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  prepare to read clk value for 10 clk cycles
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_SCL_PIN_SETUP:
    LDI    R15.w0, 0x0000
    LDI    R15.w2, 0x0A00
    UPDATE_NEXT_LOCAL_STATE READ_SCL_PIN_VALUE
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  read the scl clk value for 10 clk cycles
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_SCL_PIN_VALUE:
    ADD     R15.b0, R15.b0, 0x01
    QBBS    SCL_PIN_VALUE_HIGH, R31, R14.b0
    ADD     R15.b2, R15.b2, 0x01

SCL_PIN_VALUE_HIGH:
    QBGT    READ_SCL_PIN_VALUE_REPEAT, R15.b0, R15.b3
    UPDATE_NEXT_LOCAL_STATE READ_SCL_PIN_DONE

READ_SCL_PIN_VALUE_REPEAT:
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  read scl pins for 10 cycles is done.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
READ_SCL_PIN_DONE:
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_READY
    QBEQ    SCL_PIN_READ_VALUE_LOW, R15.b0, R15.b2
    LDI     WORK_REG_4.w0, SCL_VALUE_HIGH
    JMP     READ_SCL_PIN_DONE_RETURN

SCL_PIN_READ_VALUE_LOW:
    LDI     WORK_REG_4.w0, SCL_VALUE_LOW

READ_SCL_PIN_DONE_RETURN:
    LDI    R15.w0, 0x0000
    LDI    R15.w2, 0x0000
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  setup for reseting the slave
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RESET_SLAVE_SCL_BEGIN:
    LDI    R15.w0, 0x0000
    LDI    R15.w2, 0x0900
    UPDATE_NEXT_LOCAL_STATE RESET_SLAVE_SCL_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL high
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RESET_SLAVE_SCL_HIGH:
    SET_SCL_PIN_HIGH
    UPDATE_NEXT_LOCAL_STATE RESET_SLAVE_SCL_WAIT1
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  wait to match the timing parameters
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RESET_SLAVE_SCL_WAIT1:
    UPDATE_NEXT_LOCAL_STATE RESET_SLAVE_SCL_LOW
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  make SCL low 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RESET_SLAVE_SCL_LOW:
    SET_SCL_PIN_LOW
    ADD     R15.b0, R15.b0, 0x01
    UPDATE_NEXT_LOCAL_STATE RESET_SLAVE_SCL_WAIT2
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  wait to match the timing parameters
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RESET_SLAVE_SCL_WAIT2:
    QBGT    RESET_SLAVE_SCL_RETURN, R15.b0, R15.b3
    UPDATE_NEXT_LOCAL_STATE RESET_SLAVE_RETURN
    STATE_TASK_OVER

RESET_SLAVE_SCL_RETURN:
    UPDATE_NEXT_LOCAL_STATE RESET_SLAVE_SCL_HIGH
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Finish reseting slave
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RESET_SLAVE_RETURN:
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_READY
    LDI     WORK_REG_4.w0, RESET_SLAVE_DONE
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  Read the number of 8 bits data need to be copied over
;  also initialize the data count and bit count register to 0
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
LOOPBACK_DATA_COUNT:
    LBBO    &WORK_REG_4.w0, R10, ICSS_I2C_CNT_OFFSET, 2
    QBLT    LOOPBACK_DATA_COUNT_ERROR, WORK_REG_4.w0, 0xFF
    QBGT    LOOPBACK_DATA_COUNT_ERROR, WORK_REG_4.w0, 0x01
    AND     R15.b3, WORK_REG_4.b0, 0xFF
    AND     R15.b2, R15.b2, 0x00
    UPDATE_NEXT_LOCAL_STATE LOOPBACK_COPY_DATA
    STATE_TASK_OVER

LOOPBACK_DATA_COUNT_ERROR:
    LDI     WORK_REG_4.w0, INVALID_DATA_COUNT
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_READY
    STATE_TASK_OVER

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;  copy data from Tx to Rx buffer.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
LOOPBACK_COPY_DATA:
    LBBO    &R15.b1, R11, R15.b2, 1
    SBBO    &R15.b1, R12, R15.b2, 1
    ADD     R15.b2, R15.b2, 1
    QBGE    LOOPBACK_COPY_DATA_RETURN, R15.b3, R15.b2
    STATE_TASK_OVER

LOOPBACK_COPY_DATA_RETURN:
    UPDATE_NEXT_LOCAL_STATE RAISE_HOST_INTERRUPT_MEM_FOR_READY
    LDI     WORK_REG_4.w0, COMMAND_SUCCESS
    SBBO    &WORK_REG_4, R10, ICSS_I2C_COMMAND_OFFSET, 2
    STATE_TASK_OVER



