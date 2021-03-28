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
; file:   eSPI_cmd.asm
;
; brief:  This files contains the CMD subroutines
;
;
;  (C) Copyright 2018, Texas Instruments, Inc
;
				;
;;; INCLUDES ;;;
	.include "crc.h"
	.include "eSPI_cmd.h"
	.include "eSPI_control.h"
	.include "icss_intc_regs.h"
	.include "eSPI_pru_y_defines.h"
	.include "eSPI_slave_registers.h"

;;; GLOBAL REFS ;;;
	.global READY_STATE
	.global FATAL_ERROR
	.global SEND_NON_FATAL_ERROR
	.global HANDLE_FLAG
	
;;; GLOBAL DEFINES ;;;

	.text
	
;-------------------------------------------------------------------
; Subroutine: PUT_PC
; Description: 
;-------------------------------------------------------------------	
PUT_PC:
	JMP NOT_IMPLEMENTED

;-------------------------------------------------------------------
; Subroutine: PUT_NP
; Description: 
;-------------------------------------------------------------------
PUT_NP:
	JMP NOT_IMPLEMENTED

;-------------------------------------------------------------------
; Subroutine: GET_PC
; Description: 
;-------------------------------------------------------------------
GET_PC:
	;; Define local register names
	.asg r_Work0, _PacketInfo
	.asg r_Work1, _Crc	
	.asg r_Work3, _TxPacketPtr
	.asg r_Work4, _TxPacketEndAddr
	.asg r_Work5, _TxBufferBase
	.asg r_Work6, _Tmp0
	.asg r_Work7, _InternalStatusReg
	
;;; CMD PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Set up CRC with CMD value
	INIT_CRC	r_CrcCalc, 0x1

	;; Read Status Register
	LBBO	&r_StatusReg, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4

	;; Read Internal Status Register
	LBBO	&_InternalStatusReg, r_SharedMemoryBase, INTERNAL_STATUS_REGISTER_BASE, 4

	;; Finish reading packet
	;; SET_PRU_X_STATE	g_TarStateIdx		; PRU-BB is already reading last byte, prep TAR state
	SET_PRU_BB_STATE	g_TarState, r_Mode
	READ_BYTE	_Crc.b0 	; CRC
	
;;; TAR+WAIT PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; (>=40 CCs)
	;; Ensure CRC is good to go
	CHECK_CRC	r_CrcCalc, _Crc.b0

	;; Prep write
	;; SET_PRU_X_STATE	g_WriteStateIdx
	SET_PRU_BB_STATE	g_WriteState, r_Mode

	;; If the status register indicates the TXQ is empty
	;; respond with FATAL_ERROR
	QBBC	SEND_FATAL_ERROR, r_StatusReg, STATUS_PC_AVAIL_BIT

	;; Prep TX Buffer
	LDI	_TxBufferBase, CH0_PC_TX_BUFFER_BASE
	ADD	_TxPacketPtr, r_SharedMemoryBase, _TxBufferBase
	
	;; Read packet from TX Buffer
	;; |   byte3   |   byte2   |   byte1   |   byte0   |
	;; |-----------+-----------+-----------+-----------|
	;; | packet b0 |        LENGTH         |   MAGIC   |
	;; |-----------+-----------+-----------+-----------|
	LBBO	&_PacketInfo, _TxPacketPtr, 0, 4
	ADD	_TxPacketPtr, _TxPacketPtr, 3

	;; Check Magic Number
	QBNE	SEND_NON_FATAL_ERROR, _PacketInfo.b0, ESPI_PACKET_MAGIC_NUMBER

	;; Update TXQ_FULL_BIT bit in the Internal Status Register
	CLR	_InternalStatusReg, _InternalStatusReg, CHAN0_PC_TXQ_FULL_BIT
	SBBO	&_InternalStatusReg, r_SharedMemoryBase, INTERNAL_STATUS_REGISTER_BASE, 4
	
	;; Update PC_AVAIL bit in Status Register
	CLR	r_StatusReg, r_StatusReg, STATUS_PC_AVAIL_BIT
	SBBO	&r_StatusReg, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4
	XOUT	BANK0, &r_StatusReg, 4

	;; Setup Packet pointers. Can't use direct offsets, address is too large.
	ADD	_TxPacketEndAddr, r_SharedMemoryBase, _TxBufferBase
	ADD	_TxPacketEndAddr, _TxPacketEndAddr, _PacketInfo.w1
	ADD	_TxPacketEndAddr, _TxPacketEndAddr, 3 ; packet starts after MAGIC + LENGTH

	;; Clear CRC value
	CLEAR_CRC	r_CrcCalc

;;; RSP PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Prepare and write ACCEPT response
	LDI	_Tmp0.b0, g_AcceptResponseCode
	WRITE_BYTE_CRC	_Tmp0.b0, r_CrcCalc

	;; Write packet
get_pc_write_loop:
	LBBO	&_Tmp0.b0, _TxPacketPtr, 0, 1
	WRITE_BYTE_CRC	_Tmp0.b0, r_CrcCalc
	ADD	_TxPacketPtr, _TxPacketPtr, 1
	QBLT	get_pc_write_loop, _TxPacketEndAddr, _TxPacketPtr

	;; Write status register
	WRITE_BYTE_CRC	r_StatusReg.b1, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b0, r_CrcCalc

	;; PRU-BB about to write last byte, prep End state
	;; SET_PRU_X_STATE	g_EndStateIdx
	;; SET_PRU_BB_STATE	g_EndState, r_Zero
	
	;; Write CRC byte
	WRITE_CRC	r_CrcCalc
	SET_PRU_BB_STATE	g_EndState, r_Zero

	;; Fin
	JMP	END_STATE

	;; Destroy local register names
	.unasg _PacketInfo
	.unasg _Crc
	.unasg _TxPacketPtr
	.unasg _TxPacketEndAddr
	.unasg _TxBufferBase
	.unasg _Tmp0
	.unasg _InternalStatusReg

;-------------------------------------------------------------------
; Subroutine: GET_NP
; Description: 
;-------------------------------------------------------------------
GET_NP:
	JMP NOT_IMPLEMENTED

;-------------------------------------------------------------------
; Subroutine: PUT_IORD_SHORT
; Description: Pass packet directly to Host via the NP RXQ
;-------------------------------------------------------------------
PUT_IORD_SHORT_1:
PUT_IORD_SHORT_2:
PUT_IORD_SHORT_4:
	;; Define local register names
	.asg r_Work0, _PacketInfo	; magic number + length + CMD (write when length known)
	.asg r_Work1, _PacketWord	; actual packet
	.asg r_Work3, _InternalStatusReg
	.asg r_Work4, _Tmp0
	.asg r_Work5, _Crc
	
;;; CMD PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
	;; Begin to build packet with CMD opcode value
	MOV	_PacketInfo.b3, r_PruXData
		
	;; Set up CRC with CMD value
	INIT_CRC	r_CrcCalc, r_PruXData

	;; Read Status Register
	LBBO	&r_StatusReg, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4
	
	;; Read Internal Status Register
	LBBO	&_InternalStatusReg, r_SharedMemoryBase, INTERNAL_STATUS_REGISTER_BASE, 4

	;; Finish reading packet
	READ_BYTE_CRC	_PacketWord.b0, r_CrcCalc	; Address
	READ_BYTE_CRC	_PacketWord.b1, r_CrcCalc	; Address
	;; SET_PRU_X_STATE	g_TarStateIdx		; PRU-BB is already reading last byte, prep TAR state
	SET_PRU_BB_STATE	g_TarState, r_Mode
	READ_BYTE	_Crc.b0 	; CRC
	
;;; TAR+WAIT PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; (>=40 CCs)
	;; Ensure CRC is good to go
	CHECK_CRC	r_CrcCalc, _Crc.b0

	;; Prep write
	;; SET_PRU_X_STATE	g_WriteStateIdx
	SET_PRU_BB_STATE	g_WriteState, r_Mode

	;; If the status register indicates there is no room in the RXQ
	;; respond with FATAL_ERROR
	QBBC	SEND_FATAL_ERROR, r_StatusReg, STATUS_NP_FREE_BIT
	
	;; Response to this packet will go into PC TXQ, so if PC TXQ
	;; is full, alert master with a NON_FATAL_ERROR
	QBBS	SEND_NON_FATAL_ERROR, _InternalStatusReg, CHAN0_PC_TXQ_FULL_BIT

	;; Populate PacketInfo with packet length (as read from PRU-BB) and magic number
	LDI	_PacketInfo.b0, ESPI_PACKET_MAGIC_NUMBER
	SUB	_PacketInfo.w1, r_PruYCount, 1 ; count includes CRC byte, dec by 1
	
	;; Write packet to RX Buffer
	;; (single-depth so no need to worry about queue pointer)
	SBBO	&_PacketInfo, r_SharedMemoryBase, CH0_NP_RX_BUFFER_BASE, 8

	;; Update NP_FREE bit in Status Register
	CLR	r_StatusReg, r_StatusReg, STATUS_NP_FREE_BIT
	SBBO	&r_StatusReg, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4
	XOUT	BANK0, &r_StatusReg, 4

	;; Alert host of new RX packet
	LDI	_Tmp0, ICSS_ESPI_IPC_MSG_RX_AVAIL
	SBBO	&_Tmp0, r_SharedMemoryBase, IPC_REGISTER_BASE, 4
	RAISE_INTERRUPT_FOR_HOST
	
;;; RSP PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Respond with DEFER while Host processes the packet
	JMP	SEND_DEFER

	;; Destroy local register names
	.unasg _PacketInfo
	.unasg _PacketWord
	.unasg _InternalStatusReg
	.unasg _Tmp0
	.unasg _Crc

;-------------------------------------------------------------------
; Subroutine: PUT_IOWR_SHORT
; Description: Can probably combine with other short commands
;-------------------------------------------------------------------
PUT_IOWR_SHORT_1:
PUT_IOWR_SHORT_2:
PUT_IOWR_SHORT_4:
	;; Define local register names
	.asg r_Work0, _PacketInfo	; magic number + length + CMD (write when length known)
	.asg r_Work1, _PacketWord0	; actual packet
	.asg r_Work2, _PacketWord1	; actual packet
	.asg r_Work3, _InternalStatusReg
	.asg r_Work4, _Tmp0
	.asg r_Work5, _Crc
	
;;; CMD PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
	;; Begin to build packet with CMD opcode value
	MOV	_PacketInfo.b3, r_PruXData

	;; Set up CRC with CMD value
	INIT_CRC	r_CrcCalc, r_PruXData

	;; Read Status Register
	LBBO	&r_StatusReg, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4
	
	;; Read Internal Status Register
	LBBO	&_InternalStatusReg, r_SharedMemoryBase, INTERNAL_STATUS_REGISTER_BASE, 4

	;; Finish reading packet
	READ_BYTE_CRC	_PacketWord0.b0, r_CrcCalc	; Address
	READ_BYTE_CRC	_PacketWord0.b1, r_CrcCalc	; Address
	READ_BYTE_CRC	_PacketWord0.b2, r_CrcCalc	; Data byte 1
	QBEQ		iowr_short_read_end, _PacketInfo.b3, 0x44 ; end 1 byte read
	
	READ_BYTE_CRC	_PacketWord0.b3, r_CrcCalc	; Data byte 2
	QBEQ		iowr_short_read_end, _PacketInfo.b3, 0x45 ; end 2 byte read
	
	READ_BYTE_CRC	_PacketWord1.b0, r_CrcCalc	; Data byte 3
	READ_BYTE_CRC	_PacketWord1.b1, r_CrcCalc	; Data byte 4
iowr_short_read_end:	
	;; SET_PRU_X_STATE	g_TarStateIdx		; PRU-BB is already reading last byte, prep TAR state
	SET_PRU_BB_STATE	g_TarState, r_Mode
	READ_BYTE	_Crc.b0 	; CRC
	
;;; TAR+WAIT PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; (>=40 CCs)
	;; Ensure CRC is good to go
	CHECK_CRC	r_CrcCalc, _Crc.b0

	;; Prep write
	;; SET_PRU_X_STATE	g_WriteStateIdx
	SET_PRU_BB_STATE	g_WriteState, r_Mode

	;; If the status register indicates there is no room in the RXQ
	;; respond with FATAL_ERROR
	QBBC	SEND_FATAL_ERROR, r_StatusReg, STATUS_NP_FREE_BIT

	;; Populate PacketInfo with packet length (as read from PRU-BB) and magic number
	LDI	_PacketInfo.b0, ESPI_PACKET_MAGIC_NUMBER
	SUB	_PacketInfo.w1, r_PruYCount, 1 ; count includes CRC byte, dec by 1
	
	;; Write packet to RX Buffer
	;; (single-depth so no need to worry about queue pointer)
	;; always write all 12 bytes, the length field in the header will tell host actual length
	SBBO	&_PacketInfo, r_SharedMemoryBase, CH0_NP_RX_BUFFER_BASE, 12

	;; Update NP_FREE bit in Status Register
	CLR	r_StatusReg, r_StatusReg, STATUS_NP_FREE_BIT
	SBBO	&r_StatusReg, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4
	XOUT	BANK0, &r_StatusReg, 4
	
	;; Alert host of new RX packet
	LDI	_Tmp0, ICSS_ESPI_IPC_MSG_RX_AVAIL
	SBBO	&_Tmp0, r_SharedMemoryBase, IPC_REGISTER_BASE, 4
	RAISE_INTERRUPT_FOR_HOST
	
;;; RSP PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Respond with ACCEPT, Host will handle the packet
	JMP	SEND_ACCEPT

	;; Destroy local register names
	.unasg _PacketInfo
	.unasg _PacketWord0
	.unasg _PacketWord1
	.unasg _InternalStatusReg
	.unasg _Tmp0
	.unasg _Crc
	
;-------------------------------------------------------------------
; Subroutine: PUT_MEMRD32_SHORT_0
; Description: Can probably combine with other short commands
;-------------------------------------------------------------------
PUT_MEMRD32_SHORT_1:
PUT_MEMRD32_SHORT_2:
PUT_MEMRD32_SHORT_4:
	;; Define local register names
	.asg r_Work0, _PacketInfo	; magic number + length + CMD(write when length known)
	.asg r_Work1, _PacketWord	; actual packet
	.asg r_Work4, _InternalStatusReg
	.asg r_Work5, _Tmp0
	.asg r_Work3, _Crc

;;; CMD PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Begin to build packet with CMD opcode value
	MOV	_PacketInfo.b3, r_PruXData
	
	;; Set up CRC with CMD value
	INIT_CRC	r_CrcCalc, r_PruXData

	;; Read Status Register
	LBBO	&r_StatusReg, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4
	
	;; Read Internal Status Register
	LBBO	&_InternalStatusReg, r_SharedMemoryBase, INTERNAL_STATUS_REGISTER_BASE, 4

	;; Finish reading packet
	READ_BYTE_CRC	_PacketWord.b0, r_CrcCalc	; Address
	READ_BYTE_CRC	_PacketWord.b1, r_CrcCalc	; Address
	READ_BYTE_CRC	_PacketWord.b2, r_CrcCalc	; Address
	READ_BYTE_CRC	_PacketWord.b3, r_CrcCalc	; Address
	;; SET_PRU_X_STATE	g_TarStateIdx		; PRU-BB is already reading last byte, prep TAR state
	SET_PRU_BB_STATE	g_TarState, r_Mode
	READ_BYTE	_Crc.b0 	; CRC
	
;;; TAR+WAIT PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; (>=40 CCs)
	;; Ensure CRC is good to go
	CHECK_CRC	r_CrcCalc, _Crc.b0

	;; Prep write
	;; SET_PRU_X_STATE	g_WriteStateIdx
	SET_PRU_BB_STATE	g_WriteState, r_Mode

	;; If the status register indicates there is no room in the RXQ
	;; respond with FATAL_ERROR
	QBBC	SEND_FATAL_ERROR, r_StatusReg, STATUS_NP_FREE_BIT
	
	;; Response to this packet will go into PC TXQ, so if PC TXQ
	;; is full, alert master with a NON_FATAL_ERROR
	QBBS	SEND_NON_FATAL_ERROR, _InternalStatusReg, CHAN0_NP_TXQ_FULL_BIT

	;; Populate PacketInfo with packet length (as read from PRU-BB) and magic number
	LDI	_PacketInfo.b0, ESPI_PACKET_MAGIC_NUMBER
	SUB	_PacketInfo.w1, r_PruYCount, 1 ; count includes CRC byte, dec by 1
	
	;; Write packet to RX Buffer
	;; (single-depth so no need to worry about queue pointer)
	SBBO	&_PacketInfo, r_SharedMemoryBase, CH0_NP_RX_BUFFER_BASE, 8

	;; Update NP_FREE bit in Status Register
	CLR	r_StatusReg, r_StatusReg, STATUS_NP_FREE_BIT
	SBBO	&r_StatusReg, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4
	XOUT	BANK0, &r_StatusReg, 4
	
	;; Alert host of new RX packet
	LDI	_Tmp0, ICSS_ESPI_IPC_MSG_RX_AVAIL
	SBBO	&_Tmp0, r_SharedMemoryBase, IPC_REGISTER_BASE, 4
	RAISE_INTERRUPT_FOR_HOST
	
;;; RSP PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Respond with DEFER while Host processes the packet
	JMP	SEND_DEFER

	;; Destroy local register names
	.unasg _PacketInfo
	.unasg _PacketWord
	.unasg _InternalStatusReg
	.unasg _Tmp0
	.unasg _Crc

;-------------------------------------------------------------------
; Subroutine: SEND_NON_FATAL_ERROR
; Description: Respond with NON_FATAL_ERROR
;-------------------------------------------------------------------
SEND_NON_FATAL_ERROR:
	;; Prepare NON_FATAL_ERROR response
	LDI	r_Work0.b0, g_NonFatalErrorResponseCode 
	
	;; RESPONSE PHASE
	CLEAR_CRC	r_CrcCalc
	WRITE_BYTE_CRC	r_Work0.b0, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b1, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b0, r_CrcCalc
	;; SET_PRU_X_STATE	g_EndStateIdx
	;; SET_PRU_BB_STATE	g_EndState, r_Zero
	WRITE_CRC	r_CrcCalc
	SET_PRU_BB_STATE	g_EndState, r_Zero

	JMP	END_STATE

;-------------------------------------------------------------------
; Subroutine: SEND_FATAL_ERROR
; Description: Respond with FATAL_ERROR
;-------------------------------------------------------------------
SEND_FATAL_ERROR:
	;; Prepare FATAL_ERROR response
	LDI	r_Work0.b0, g_FatalErrorResponseCode 
	
	;; RESPONSE PHASE
	CLEAR_CRC	r_CrcCalc
	WRITE_BYTE_CRC	r_Work0.b0, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b1, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b0, r_CrcCalc
	;; SET_PRU_X_STATE	g_EndStateIdx
	;; SET_PRU_BB_STATE	g_EndState, r_Zero
	WRITE_CRC	r_CrcCalc
	SET_PRU_BB_STATE	g_EndState, r_Zero

	JMP	END_STATE

;-------------------------------------------------------------------
; Subroutine: END_STATE
; Description: Wait for PRU-BB to alert that CS has de-asserted properly
;-------------------------------------------------------------------
END_STATE:
	;; Make sure PRU-BB is up to date with the status register known by master
	XOUT	BANK0, &r_StatusReg, 4
wait_for_flag:
	JMP READY_STATE
	XIN	BANK0, &r_Flags, 2
	QBEQ	wait_for_flag, r_Flags, 0
	;;  continue on to handle flag	
HANDLE_FLAG:  ;; Only one flag for now.....keep it simple
FLAG_CS_DEASSERT_GOOD:
FLAG_CS_DEASSERT_BAD:	;; These flags are handled the same.......for now
	;; Make sure PRU-BB is up to date with the status register known by master
	XOUT	BANK0, &r_StatusReg, 4 ; redundant? Yes, but just in case
	
	;; Clear flags
	LDI	r_Flags, 0
	XOUT	BANK0, &r_Flags, 2

	;; CS has been de-asserted so jump to Ready to wait for data
	JMP	READY_STATE

;-------------------------------------------------------------------
; Subroutine: PUT_MEMWR32_SHORT
; Description: Pass directly in PC Queue (can still probably be combined with other shorts)
;-------------------------------------------------------------------
PUT_MEMWR32_SHORT_1:
PUT_MEMWR32_SHORT_2:
PUT_MEMWR32_SHORT_4:
	;; Define local register names
	.asg r_Work0, _PacketInfo	; magic number + length + CMD(write when length known)
	.asg r_Work1, _PacketWord0	; actual packet
	.asg r_Work2, _PacketWord1	; actual packet
	.asg r_Work4, _InternalStatusReg
	.asg r_Work5, _Tmp0
	.asg r_Work3, _Crc

;;; CMD PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Begin to build packet with CMD opcode value
	MOV	_PacketInfo.b3, r_PruXData
	
	;; Set up CRC with CMD value
	INIT_CRC	r_CrcCalc, r_PruXData

	;; Read Status Register
	LBBO	&r_StatusReg, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4
	
	;; Read Internal Status Register
	LBBO	&_InternalStatusReg, r_SharedMemoryBase, INTERNAL_STATUS_REGISTER_BASE, 4

	;; Finish reading packet
	READ_BYTE_CRC	_PacketWord0.b0, r_CrcCalc	; Address
	READ_BYTE_CRC	_PacketWord0.b1, r_CrcCalc	; Address
	READ_BYTE_CRC	_PacketWord0.b2, r_CrcCalc	; Address
	READ_BYTE_CRC	_PacketWord0.b3, r_CrcCalc	; Address
	
	READ_BYTE_CRC	_PacketWord1.b0, r_CrcCalc	; Data byte 1
	QBEQ		memwr_short_read_end, _PacketInfo.b3, 0x4C ; end 1 byte read
	
	READ_BYTE_CRC	_PacketWord1.b1, r_CrcCalc	; Data byte 2
	QBEQ		memwr_short_read_end, _PacketInfo.b3, 0x4D ; end 2 byte read
	
	READ_BYTE_CRC	_PacketWord1.b2, r_CrcCalc	; Data byte 3
	READ_BYTE_CRC	_PacketWord1.b3, r_CrcCalc	; Data byte 4
memwr_short_read_end:	
	;; SET_PRU_X_STATE	g_TarStateIdx	; PRU-BB is already reading last byte, prep TAR state
	SET_PRU_BB_STATE	g_TarState, r_Mode
	READ_BYTE	_Crc.b0 	; CRC
	
;;; TAR+WAIT PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; (>=40 CCs)
	;; Ensure CRC is good to go
	CHECK_CRC	r_CrcCalc, _Crc.b0

	;; Prep write
	;; SET_PRU_X_STATE	g_WriteStateIdx
	SET_PRU_BB_STATE	g_WriteState, r_Mode

	;; If the status register indicates there is no room in the RXQ
	;; respond with FATAL_ERROR
	QBBC	SEND_FATAL_ERROR, r_StatusReg, STATUS_PC_FREE_BIT

	;; Populate PacketInfo with packet length (as read from PRU-BB) and magic number
	LDI	_PacketInfo.b0, ESPI_PACKET_MAGIC_NUMBER
	SUB	_PacketInfo.w1, r_PruYCount, 1 ; count includes CRC byte, dec by 1
	
	;; Write packet to RX Buffer
	;; (single-depth so no need to worry about queue pointer)
	LDI	_Tmp0, CH0_PC_RX_BUFFER_BASE
	SBBO	&_PacketInfo, r_SharedMemoryBase, _Tmp0, 12

	;; Update PC_FREE bit in Status Register
	CLR	r_StatusReg, r_StatusReg, STATUS_PC_FREE_BIT
	SBBO	&r_StatusReg, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4
	XOUT	BANK0, &r_StatusReg, 4
	
	;; Alert host of new RX packet
	LDI	_Tmp0, ICSS_ESPI_IPC_MSG_RX_AVAIL
	SBBO	&_Tmp0, r_SharedMemoryBase, IPC_REGISTER_BASE, 4
	RAISE_INTERRUPT_FOR_HOST
	
;;; RSP PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Respond with ACCEPT, Host will handle the packet
	JMP	SEND_ACCEPT

	;; Destroy local register names
	.unasg _PacketInfo
	.unasg _PacketWord
	.unasg _InternalStatusReg
	.unasg _Tmp0
	.unasg _Crc

;-------------------------------------------------------------------
; Subroutine: PUT_VWIRE
; Description: 
;-------------------------------------------------------------------
PUT_VWIRE:
	JMP NOT_IMPLEMENTED

;-------------------------------------------------------------------
; Subroutine: GET_VWIRE
; Description: 
;-------------------------------------------------------------------
GET_VWIRE:
	JMP NOT_IMPLEMENTED

;-------------------------------------------------------------------
; Subroutine: PUT_OOB
; Description: 
;-------------------------------------------------------------------
PUT_OOB:
	JMP NOT_IMPLEMENTED

;-------------------------------------------------------------------
; Subroutine: GET_OOB
; Description: 
;-------------------------------------------------------------------
GET_OOB:
	JMP NOT_IMPLEMENTED

;-------------------------------------------------------------------
; Subroutine: PUT_FLASH_C
; Description: 
;-------------------------------------------------------------------
PUT_FLASH_C:
	JMP NOT_IMPLEMENTED

;-------------------------------------------------------------------
; Subroutine: GET_FLASH_NP
; Description: 
;-------------------------------------------------------------------
GET_FLASH_NP:
	JMP NOT_IMPLEMENTED

;-------------------------------------------------------------------
; Subroutine: GET_STATUS
; Description: Respond with the status register
;-------------------------------------------------------------------
GET_STATUS:
	.asg r_Work1, _Crc
;;; CMD PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; SET_PRU_X_STATE	g_TarStateIdx		; PRU-BB is already reading last byte, prep TAR state
	SET_PRU_BB_STATE	g_TarState, r_Mode
	
	;; Set up CRC with CMD value
	INIT_CRC	r_CrcCalc,0x23

	;; Finish reading packet
	READ_BYTE	_Crc.b0 	; CRC

;;; TAR+WAIT PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; (>=40 CCs)
	;; Ensure CRC is good to go
	CHECK_CRC	r_CrcCalc, _Crc.b0

	;; Prep write
	;; SET_PRU_X_STATE	g_WriteStateIdx
	SET_PRU_BB_STATE	g_WriteState, r_Mode

	;; Read Status Register
	LBBO	&r_StatusReg, r_SharedMemoryBase, STATUS_REGISTER_BASE, 4
	
;;; RSP PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Write results
	JMP SEND_ACCEPT

	.unasg	_Crc

;-------------------------------------------------------------------
; Subroutine: SET_CONFIGURATION
; Description: Set requested configuration register with provided value
;-------------------------------------------------------------------
SET_CONFIGURATION:
	.asg r_Work0, _Crc
	.asg r_Work1, _PacketAddr
	.asg r_Work2, _PacketData
	.asg r_Work3, _Response
	.asg r_Work4, _Tmp0
	.asg r_Work5, _GenCapConNew
	.asg r_Work6, _Ch0CapConNew
	.asg r_Work7, _ModeNew
	
	
;;; CMD PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
	;; Set up CRC with CMD value
	INIT_CRC	r_CrcCalc,0x22

	;; Read fixed-length packet
	READ_BYTE_CRC	_PacketAddr.b1, r_CrcCalc	; Address
	READ_BYTE_CRC	_PacketAddr.b0, r_CrcCalc	; Address
	READ_BYTE_CRC	_PacketData.b0, r_CrcCalc	; Data
	READ_BYTE_CRC	_PacketData.b1, r_CrcCalc	; Data
	READ_BYTE_CRC	_PacketData.b2, r_CrcCalc	; Data
	READ_BYTE_CRC	_PacketData.b3, r_CrcCalc	; Data
	;; SET_PRU_X_STATE	g_TarStateIdx		; PruX is already reading last byte, prep TAR state
	SET_PRU_BB_STATE	g_TarState, r_Mode
	READ_BYTE	_Crc.b2 	; CRC

;;; TAR+WAIT PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; (>=40 CCs)
	;; Ensure CRC is good to go
	CHECK_CRC	r_CrcCalc, _Crc.b2
	
	;; Prep write
	;; SET_PRU_X_STATE	g_WriteStateIdx
	SET_PRU_BB_STATE	g_WriteState, r_Mode

	;; Ensure address within valid range
	LDI	_Tmp0.w0, 0xFFF
	QBGT	SEND_FATAL_ERROR, _Tmp0.w0, _PacketAddr.w0

	;; Check in order of complexity
	QBEQ	configure_general_cap_con, _PacketAddr.w0, 0x008
	QBEQ	configure_ch0_cap_con, _PacketAddr.w0, 0x010

	;; Ignore any other request (no other channels are supported)
	JMP	SEND_ACCEPT

configure_general_cap_con:
	MOV	_GenCapConNew, r_GeneralCapCon
	
	;; CRC Checking
	UPDATE_BIT_FROM_REF _GenCapConNew, _PacketData, GENERAL_CAP_CON_CRC_CHECKING_ENABLE_OFFSET
	
	;; Response Modifier
	QBBS	SEND_NON_FATAL_ERROR, _PacketData, GENERAL_CAP_CON_RESPONSE_MODIFIER_ENABLE_OFFSET

	;; Alert Mode
	QBBC	SEND_NON_FATAL_ERROR, _PacketData, GENERAL_CAP_CON_ALERT_MODE_OFFSET

	;; I/O Mode
	UPDATE_BITS_FROM_REF _GenCapConNew, _PacketData, _Tmp0, (GENERAL_CAP_CON_IO_MODE_SELECT_MASK << GENERAL_CAP_CON_IO_MODE_SELECT_OFFSET)

	;; Setup mode register for state jumps
	LSR	_ModeNew.w2, _Tmp0, (GENERAL_CAP_CON_IO_MODE_SELECT_OFFSET)

	;; Open Drain Alert
	;; CURRENTLY NOT CHECKING IF SUPPORTED (UNDEFINED BEHAVIOR)
	;; Only one mode supported, so effectively just ignoring bad requests 
	
	;; Maximum Frequency
	;; CURRENTLY NOT CHECKING IF SUPPORTED (UNDEFINED BEHAVIOR)
	;; Only one mode supported, so effectively just ignoring bad requests

	;; Maximum WAIT_STATE
	;; Changing configuration, but effectively ignored
	UPDATE_BITS_FROM_REF _GenCapConNew, _PacketData, _Tmp0, (GENERAL_CAP_CON_MAXIMUM_WAIT_STATE_ALLOWED_MASK << GENERAL_CAP_CON_MAXIMUM_WAIT_STATE_ALLOWED_OFFSET)

	;; Send ACCEPT and set return location for successful write
	JAL	r_LinkReg, send_accept_sc
	
	;; Upon return, update local and global slave register
	MOV	r_Mode, _ModeNew.w2
	MOV	r_GeneralCapCon, _GenCapConNew
	SBBO	&r_GeneralCapCon, r_SharedMemoryBase, GENERAL_CAP_CON_REGISTER_BASE, 4
	JMP	READY_STATE


configure_ch0_cap_con:
	MOV	_Ch0CapConNew, r_Ch0CapCon
	
	;; Read Request Size
	;; CURRENTLY NOT CHECKING IF SUPPORTED (UNDEFINED BEHAVIOR)
	;; Only one mode supported, so effectively just ignoring bad requests

	;; Payload size
	;; CURRENTLY NOT CHECKING IF SUPPORTED (UNDEFINED BEHAVIOR)
	;; Only one mode supported, so effectively just ignoring bad requests

	;; Bus Master Enable
	;; ??
	;; Must be no non-posted cycle pending completion

	;; Enable
	UPDATE_BITS_FROM_REF _Ch0CapConNew, _PacketData, _Tmp0, (PERIPHERAL_CHAN_ENABLE_MASK << PERIPHERAL_CHAN_ENABLE_OFFSET)

	;; Send ACCEPT and set return location for successful write
	JAL	r_LinkReg, send_accept_sc

	;; Upon return, update local and global slave register
	MOV	r_Ch0CapCon, _Ch0CapConNew
	SBBO	&r_Ch0CapCon, r_SharedMemoryBase, CHAN0_CAP_CON_REGISTER_BASE, 4
	JMP	READY_STATE

;;; RSP PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
send_accept_sc:	
	;; Prepare ACCEPT response
	LDI	_Response.b0, g_AcceptResponseCode
	
	;; RESPONSE PHASE
	CLEAR_CRC	r_CrcCalc
	WRITE_BYTE_CRC	_Response.b0, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b1, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b0, r_CrcCalc
	;; SET_PRU_X_STATE	g_EndStateIdx
	;; SET_PRU_BB_STATE	g_EndState, r_Zero
	WRITE_CRC	r_CrcCalc
	SET_PRU_BB_STATE	g_EndState, r_Zero

;; Need a special end state for SET_CONFIGURATION to apply configurations after CS# de-asserts
end_state_sc:
wait_for_flag_sc:
	XIN	BANK0, &r_Flags, 4
	QBEQ	wait_for_flag_sc, r_Flags, 0
	;;  continue on to handle flag
	
HANDLE_FLAG_SC:  ;; Only one flag possible here, as we've actually reached the end state
	;; Clear flags
	LDI	r_Flags, 0
	XOUT	BANK0, &r_Flags, 4

	;; CS has been de-asserted so jump back to finalize configuration
	JMP	r_LinkReg

	.unasg _Crc
	.unasg _PacketAddr
	.unasg _PacketData
	.unasg _Response
	.unasg _Tmp0
	.unasg _GenCapConNew
	.unasg _Ch0CapConNew
	.unasg _ModeNew

;-------------------------------------------------------------------
; Subroutine: GET_CONFIGURATION
; Description: Respond with requested configuration register
;-------------------------------------------------------------------
GET_CONFIGURATION:
	.asg r_Work0, _Crc
	.asg r_Work1, _Packet
	.asg r_Work2, _SlaveReg
	.asg r_Work3, _Tmp0
;;; CMD PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Set up CRC with CMD value
	INIT_CRC	r_CrcCalc, 0x21
	
	;; Read fixed-length packet
	READ_BYTE_CRC	_Packet.b1, r_CrcCalc	; Address
	READ_BYTE_CRC	_Packet.b0, r_CrcCalc	; Address
	;; SET_PRU_X_STATE	g_TarStateIdx		; PruX is already reading last byte, prep TAR state
	SET_PRU_BB_STATE	g_TarState, r_Mode
	READ_BYTE	_Crc.b0 	; CRC

;;; TAR+WAIT PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; (>=40 CCs)
	;; Ensure CRC is good to go
	CHECK_CRC	r_CrcCalc, _Crc.b0

	;; Prep write
	;; SET_PRU_X_STATE	g_WriteStateIdx
	SET_PRU_BB_STATE	g_WriteState, r_Mode
	
	;; Ensure address within valid range
	LDI	_Tmp0.w0, 0xFFF
	QBGT	SEND_FATAL_ERROR, _Tmp0.w0, _Packet.w0

	;; We have a bunch of extra cycles to process these unsupported channels
	;; so this is unoptimized for now
	QBEQ	read_ch1_cap_con, _Packet.w0, 0x020
	QBEQ	read_ch2_cap_con, _Packet.w0, 0x030
	QBEQ	read_ch3_cap_con, _Packet.w0, 0x040
	QBEQ	read_device_id, _Packet.w0, 0x004
	QBEQ	read_general_cap_con, _Packet.w0, 0x008
	QBEQ	read_ch0_cap_con, _Packet.w0, 0x010

	;; Address is RESERVED, respond with ZERO
	LDI32	_SlaveReg, 0x00000000
	JMP	send_slave_register

read_device_id:
	MOV	_SlaveReg, r_DeviceId
	JMP	send_slave_register

read_general_cap_con:
	MOV	_SlaveReg, r_GeneralCapCon
	JMP	send_slave_register

read_ch0_cap_con:
	MOV	_SlaveReg, r_Ch0CapCon
	JMP	send_slave_register

read_ch1_cap_con:
	LBBO	&_SlaveReg, r_SharedMemoryBase, CHAN1_CAP_CON_REGISTER_BASE, 4
	JMP	send_slave_register

read_ch2_cap_con:
	LBBO	&_SlaveReg, r_SharedMemoryBase, CHAN2_CAP_CON_REGISTER_BASE, 4
	JMP	send_slave_register

read_ch3_cap_con:
	LBBO	&_SlaveReg, r_SharedMemoryBase, CHAN3_CAP_CON_REGISTER_BASE, 4
	JMP	send_slave_register
	
send_slave_register:
	;;  Prep ACCEPT response
	LDI	_Tmp0.b0, g_AcceptResponseCode
	
;;; RSP PHASE ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;; Write results
	CLEAR_CRC	r_CrcCalc
	WRITE_BYTE_CRC	_Tmp0.b0, r_CrcCalc
	WRITE_BYTE_CRC	_SlaveReg.b0, r_CrcCalc
	WRITE_BYTE_CRC	_SlaveReg.b1, r_CrcCalc
	WRITE_BYTE_CRC	_SlaveReg.b2, r_CrcCalc
	WRITE_BYTE_CRC	_SlaveReg.b3, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b1, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b0, r_CrcCalc
	;; SET_PRU_X_STATE	g_EndStateIdx
	;; SET_PRU_BB_STATE	g_EndState, r_Zero
	WRITE_CRC	r_CrcCalc
	SET_PRU_BB_STATE	g_EndState, r_Zero

	;; FIN
	JMP	END_STATE

	.unasg _Crc
	.unasg _Packet
	.unasg _SlaveReg
	.unasg _Tmp0

;-------------------------------------------------------------------
; Subroutine: RESET
; Description:  Reset the slave registers
;-------------------------------------------------------------------
RESET:
	;; Reset all slave registers to default values
	RESET_SLAVE_REGISTERS
	
	JMP END_STATE

;-------------------------------------------------------------------
; Subroutine: NO_RESPONSE
; Description: Just wait for CS to de-assert and then head to Ready state
;-------------------------------------------------------------------
NO_RESPONSE:
	JMP END_STATE

;-------------------------------------------------------------------
; Subroutine: SEND_DEFER
; Description: Respond with DEFER
;-------------------------------------------------------------------
SEND_DEFER:
	;; Prepare DEFER response
	LDI	r_Work0.b0, g_DeferResponseCode
	
	;; RESPONSE PHASE
	CLEAR_CRC	r_CrcCalc
	WRITE_BYTE_CRC	r_Work0.b0, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b1, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b0, r_CrcCalc
	;; SET_PRU_X_STATE	g_EndStateIdx
	;; SET_PRU_BB_STATE	g_EndState, r_Zero
	WRITE_CRC	r_CrcCalc
	SET_PRU_BB_STATE	g_EndState, r_Zero

	JMP	END_STATE

;-------------------------------------------------------------------
; Subroutine: SEND_ACCEPT
; Description: Respond with ACCEPT
;-------------------------------------------------------------------
SEND_ACCEPT:
	;; Prepare ACCEPT response
	LDI	r_Work0.b0, g_AcceptResponseCode
	;; LDI	r_Work0.w0, 0xAADD
	
	;; RESPONSE PHASE
	CLEAR_CRC	r_CrcCalc
	WRITE_BYTE_CRC	r_Work0.b0, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b1, r_CrcCalc
	WRITE_BYTE_CRC	r_StatusReg.b0, r_CrcCalc
	;; SET_PRU_X_STATE	g_EndStateIdx
	WRITE_CRC	r_CrcCalc
	SET_PRU_BB_STATE	g_EndState, r_Zero

	JMP	END_STATE


;-------------------------------------------------------------------
; Subroutine: NOT_IMPLEMENTED
; Description: Temporary trap for unimplemented functions
;-------------------------------------------------------------------
NOT_IMPLEMENTED:
	JMP	NO_RESPONSE

;-------------------------------------------------------------------
; Subroutine: ERROR_CRC_MISMATCH
; Description: Temporary trap for CRC mismatch error
;-------------------------------------------------------------------
ERROR_CRC_MISMATCH:
	JMP	NO_RESPONSE
	
	
