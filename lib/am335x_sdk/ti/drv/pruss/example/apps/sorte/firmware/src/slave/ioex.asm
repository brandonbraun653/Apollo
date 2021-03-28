; Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
;
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
;
; Redistributions of source code must retain the above copyright
; notice, this list of conditions and the following disclaimer.
;
; Redistributions in binary form must reproduce the above copyright
; notice, this list of conditions and the following disclaimer in the
; documentation and/or other materials provided with the
; distribution.
;
; Neither the name of Texas Instruments Incorporated nor the names of
; its contributors may be used to endorse or promote products derived
; from this software without specific prior written permission.
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
; 	file:   ioex.asm
;
; 	brief: contains the IO exchange state implementation
;
;	Version		Description								Author
; 	0.1     	Created									Thomas Mauer
;include section
	.include "../include/macros/macros.inc"
	.include "../include/macros/utils.inc"
	.include "../include/icss/icss_regs.inc"
	.include "../include/protocol/sorte_pru_slave_register.inc"
	.include "../include/protocol/sorte_host_interface.inc"
	.include "../include/protocol/sorte_packet_definition.inc"
	.include "../include/protocol/sorte_slave_cfg.inc"
	.include "../include/protocol/sorte_state_define.inc"
	.global FN_IOEX_MASTER
	.global FN1_IOEX_SETUP_TTS
	.global FN1_SYNC_HANDLER
	.global	FN1_IOEX_PROCESS_DATA
	.global STATE_MACHINE_RETURN
	.global	FN1_IOEX_WAIT_FOR_TTS_COMPLETE
	.global FN_IOEX_MASTER_PROCESS_FRAME

;****************************
; ioex master function
;****************************
; entry point called by main state machine for IOEX  state
; In this context the MASTER is the PRU which receives the IOEX fram from the MASTER.
FN_IOEX_MASTER:
	; new packet coming in
	; 1. synchronize to frame
	; store master frame time stamp
	.if $defined(PRU0)
	lbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CAPR0_REG, 4
	.else
	lbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CAPR2_REG, 4
	.endif
	sbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST, SYNC_TS, 4
	set	DEVICE_STATUS, DEVICE_STATUS, RX_IGNORE_TO_EOF
	jmp	STATE_MACHINE_RETURN


;*************************************
; ioex master store the frame payload
;*************************************
FN_IOEX_MASTER_PROCESS_FRAME:
	; 2. get slave data
IOEX_MASTER_RCV_FRAME_COMPLETE:
	; fetch data from bank
	xin		RXL2_BANK0, &R2, RANGE_R2_R18 ; xin is used to get rx_fifo data into R2 through R18
	; reset RX FIFO
	M_CMD16 (D_RESET_RXFIFO | D_RX_ERROR_CLEAR)

	; updated next sync timestamp value
	mov	TEMP_REG_1.b1, R7.b0
	mov	TEMP_REG_1.b0, R6.b3
	lbco	&TEMP_REG_1.w2, ICSS_SHARED_RAM_CONST, LINE_DELAY_PREVIOUS, 2
	add	TEMP_REG_1, TEMP_REG_1.w0, TEMP_REG_1.w2
	sbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST, IOEX_MASTER_SYNC_TS, 4
	set	DEVICE_STATUS, DEVICE_STATUS, NEW_SYNC_FRAME_FLAG

	;extract data
	ldi	R1.b1, &TEMP_REG_1.b0 ;move address of TEMP_REG_1.b0 into R1.bi 
	ldi	R1.b0, &R2.b2	; master frame has 2 bytes header, data starts at R2.b2
	add	R1.b0, R1.b0, OFFSET_OUT_PTR
	loop	IOEX_MASTER_COPY_DATA, OUTPUT_BYTES_COUNT
	mvib	*R1.b1++, *R1.b0++
IOEX_MASTER_COPY_DATA:
	ldi	TEMP_REG_5.b3, IOEX_OUTDATA_FRAME_BUFFER
	sbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST, TEMP_REG_5.b3, OUTPUT_BYTES_COUNT
	set	DEVICE_STATUS, DEVICE_STATUS, NEW_IOEX_DATA_FLAG


	; IOEX frame monitor flag
	ldi	TEMP_REG_1.b1, 1
	sbco	&TEMP_REG_1.b1, ICSS_SHARED_RAM_CONST, IOEX_FRAME_RECEIVED, 1

	; Check CRC8
	ldi		TEMP_REG_3.b0, 0
	CRC8_CALC	TEMP_REG_3.b0, R2.b0, 18, TEMP_REG_4
	qbeq	IOEX_MASTER_DONE, TEMP_REG_3.b0, R6.b2

	; debug only
	sbco	&R2.b0, ICSS_SHARED_RAM_CONST, DEBUG_BUFFER, 32 + 16

	; CRC8 error, update statistics
	.if $defined(PRU0)
	lbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_ERROR_PRU0, 2
	add	TEMP_REG_1.w0, TEMP_REG_1.w0, 1
	sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_ERROR_PRU0, 2
	.else
	lbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_ERROR_PRU1, 2
	add	TEMP_REG_1.w0, TEMP_REG_1.w0, 1
	sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_ERROR_PRU1, 2
	.endif
	RET1

IOEX_MASTER_DONE:
	.if $defined(PRU0)
	lbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_NO_ERROR_PRU0, 2
	add	TEMP_REG_1.w0, TEMP_REG_1.w0, 1
	sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_NO_ERROR_PRU0, 2
	.else
	lbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_NO_ERROR_PRU1, 2
	add	TEMP_REG_1.w0, TEMP_REG_1.w0, 1
	sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_NO_ERROR_PRU1, 2
	.endif
	RET1


;****************************
; ioex slave function
;****************************
; note: This function is called by the event handler CMP0 event to setup TTS
; Do not use TEMP_REG_5 in this function as it stores the current event,
; This is the transmit flow from the SLAVE device to MASTER device
FN1_IOEX_SETUP_TTS:
	set	DEVICE_STATUS, DEVICE_STATUS, TTS_ACTIVE_FLAG
	; setup time triggered send
	M_SET_MIIRT_TTS_LOCAL

IOEX_CALC_SLAVE_TTS_DELAY:
	; start offset point of TTS: 500ns
	; frame header: 2 bytes frame preamble, 2 bytes frame header, 3 bytes frame payload, 1 byte CRC8 ,
	; IPG: 240ns
	; bridge delay: 320ns --> plus 35ns hardware delay --> part of LINE_DELAY_PREVIOUS
	ldi	TEMP_REG_1, 500
	; each slave can transmit earlier because of cable delay (only the first slave cannot)
	;lbco	&TEMP_REG_2.w2, ICSS_SHARED_RAM_CONST, LINE_DELAY_PREVIOUS, 2
	;sub	TEMP_REG_1, TEMP_REG_1, TEMP_REG_2.w2
	qbeq	IOEX_SETUP_TTS_WRITE_IEP, SLAVE_ADDR, 1
	ldi	TEMP_REG_1, 900
	; each slave adds 1x IFG and 1x payload
	;ldi	TEMP_REG_2.w0, 240 + 640
	;add	TEMP_REG_1, TEMP_REG_1, TEMP_REG_2.w0
	qbeq	IOEX_SETUP_TTS_WRITE_IEP, SLAVE_ADDR, 2
	ldi	TEMP_REG_1, 1360			;1360+100
	;add	TEMP_REG_1, TEMP_REG_1, TEMP_REG_2.w0
	qbeq	IOEX_SETUP_TTS_WRITE_IEP, SLAVE_ADDR, 3
	ldi	TEMP_REG_1, 1800			;1780+100

; setting up for time triggered send (TTS)
IOEX_SETUP_TTS_WRITE_IEP:
	.if $defined(PRU0)
	sbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP4_REG, 4
	.else
	sbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP3_REG, 4
	.endif
	; fill FIFO
	.if $defined(FULL_PREAMBLE)
	ldi	TX_DATA_WORD, 0x5555
	NOP
	M_PUSH_WORD
	ldi	TX_DATA_WORD, 0x5555
	NOP
	M_PUSH_WORD
	ldi	TX_DATA_WORD, 0x5555
	NOP
	M_PUSH_WORD
	NOP
	.endif
	; send 2 byte pre-amble + slave address
	ldi	TX_DATA_WORD, 0xd555
	M_PUSH_WORD
	
	;slave status
	mov	R30.b0, SLAVE_ADDR
	ldi	R30.b1, 0				;DEVICE_STATUS
	qbbc	IOEX_STATUS_2, DEVICE_STATUS, LAST_DEVICE_FLAG
	set	R30.b1, R30.b1, 0		; bit 0 set to ST_LAST
IOEX_STATUS_2:
	qbbc	IOEX_STATUS_3, DEVICE_STATUS, RX_FRAME_CRC_ERROR
	set	R30.b1, R30.b1, 2 	; bit 2 ST_ERROR_BIT
	clr	DEVICE_STATUS, DEVICE_STATUS, RX_FRAME_CRC_ERROR
IOEX_STATUS_3:
	M_PUSH_WORD
	; save transmitted word for CRC8 check
	mov		R2.w0, R30.w0

	; enable CMP3/4 event
	lbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4
	.if $defined(PRU0)
	set	TEMP_REG_1, TEMP_REG_1, 5		; enable CMP4
	.else
	set	TEMP_REG_1, TEMP_REG_1, 4		; enable CMP3
	.endif
	sbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4

	; load payload
	ldi	TX_DATA_WORD, 0x
	lbco	&TX_DATA_WORD, ICSS_SHARED_RAM_CONST, STATS_DVR8711_STATUS, 1
	M_PUSH_WORD
	NOP
	; CRC8
	ldi		TX_DATA_BYTE, 0
	CRC8_CALC	TX_DATA_BYTE, R2.b0, 5, TEMP_REG_1
	M_PUSH_BYTE

IOEX_TTS_DONE:
	RET1

;*************************************************
; IOEX wait for TTS complete to switch MII_RT port
;*************************************************
FN1_IOEX_WAIT_FOR_TTS_COMPLETE:
	qbbs	IOEX_WAIT_FOR_TTS_2, DEVICE_STATUS, DEBUG_TX_FIFO_UNDERFLOW
	ldi		TEMP_REG_2.w0, ICSS_INTC_SRSR1
IOEX_WAIT_TS_UNDERFLOW:
	lbco	&TEMP_REG_1, ICSS_INTC_CONST, TEMP_REG_2.w0, 4
	.if $defined(PRU0)
	qbbc	IOEX_WAIT_TS_UNDERFLOW, TEMP_REG_1, SYS_EVT_PORT1_TX_UNDERFLOW - 32
	.else
	qbbc	IOEX_WAIT_TS_UNDERFLOW, TEMP_REG_1, SYS_EVT_PORT0_TX_UNDERFLOW - 32
	.endif

IOEX_WAIT_FOR_TTS_2:
	clr		DEVICE_STATUS, DEVICE_STATUS, DEBUG_TX_FIFO_UNDERFLOW
	M_SET_MIIRT_AF_LOCAL
	; Disable CMP3/4 event
	lbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4
	.if $defined(PRU0)
	clr	TEMP_REG_1, TEMP_REG_1, 5		; disable CMP4
	.else
	clr	TEMP_REG_1, TEMP_REG_1, 4		; disable CMP3
	.endif
	sbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4
	clr	DEVICE_STATUS, DEVICE_STATUS, TTS_CMP34_FLAG
	clr	DEVICE_STATUS, DEVICE_STATUS, TTS_ACTIVE_FLAG
	RET1

;****************************
; IOEX process data function
;****************************
FN1_IOEX_PROCESS_DATA:
	clr	DEVICE_STATUS, DEVICE_STATUS, NEW_IOEX_DATA_FLAG
	lbco	&R2, ICSS_SHARED_RAM_CONST, IOEX_OUTDATA_FRAME_BUFFER, OUTPUT_BYTES_COUNT
	qbbs	IOEX_PROCESS_DATA_SET_OUT, R2, 10
IOEX_PROCESS_DATA_CLR_OUT:
	RET1
IOEX_PROCESS_DATA_SET_OUT:
	RET1


