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
; 	file:   sync.asm
;
; 	brief: contains the timer synchronization state implementation
;
;	Version		Description								Author
; 	0.1     	Created									Thomas Mauer
;include section
	.include "../include/macros/macros.inc"
	.include "../include/icss/icss_regs.inc"
	.include "../include/protocol/sorte_pru_slave_register.inc"
	.include "../include/protocol/sorte_host_interface.inc"
	.include "../include/protocol/sorte_packet_definition.inc"
	.include "../include/protocol/sorte_slave_cfg.inc"
	.include "../include/protocol/sorte_state_define.inc"
	.global FN_SYNC_STATE
	.global FN1_SYNC_HANDLER
	.global STATE_MACHINE_RETURN


; entry point called by main state machine for SYNC state
; will get IEP timestamp from the sync frame (at label SYNC_TYPE_OKAY) and forward frame to next slave device.
FN_SYNC_STATE:
	; SYNC header parsing
	; set pointer to first byte of the frame
	ldi		R1.b0, &R2.b0

; DA (1)
	M_XIN_L2_BANK0	SYNC_DA, 1
SYNC_DA:
	mvib	R30.b0, *R1.b0++
	M_PUSH_BYTE

; SA (2)
	M_XIN_L2_BANK0	SYNC_SA, 2
SYNC_SA:
	mvib	R30.b0, *R1.b0++
	M_PUSH_BYTE

; TYPE (3)
	M_XIN_L2_BANK0	SYNC_TYPE, 3
SYNC_TYPE:
	mvib	R30.b0, *R1.b0++
	M_PUSH_BYTE
	
SYNC_TYPE_OKAY:
	; get rx frame timestamp for SOF and save to shared memory
	; set flag to this can be processed at the end of the frame
	.if $defined(PRU0)
	lbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CAPR0_REG, 4
	.else
	lbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CAPR2_REG, 4
	.endif
	sbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST, SYNC_TS, 4
	set		DEVICE_STATUS, DEVICE_STATUS, NEW_SYNC_FRAME_FLAG

; Status (4)
	M_XIN_L2_BANK0	SYNC_STATUS, 4
SYNC_STATUS:
	mvib	R30.b0, *R1.b0++
	qbbc	SYNC_STATUS_2, DEVICE_STATUS, LAST_DEVICE_FLAG
	set		R30.b0, R30.b0, 0		; bit 0 set to ST_LAST
SYNC_STATUS_2:
	qbbc	SYNC_STATUS_3, DEVICE_STATUS, RX_FRAME_CRC_ERROR
	set		R30.b0, R30.b0, 2 	; bit 2 ST_ERROR_BIT
	clr		DEVICE_STATUS, DEVICE_STATUS, RX_FRAME_CRC_ERROR
SYNC_STATUS_3:
	M_PUSH_BYTE
	; store frame status in registers
	mov		FRAME_STATUS, R30.b0
	; State change flag set?
	qbbc	SYNC_STATUS_4, R30.b0, ST_STATECHANGE_BIT; ST_STATE_CHANGE
	; initiate state change switch
	ldi		PROTOCOL_STATE, IOEX_STATE
	set		DEVICE_STATUS, DEVICE_STATUS, SWITCH_PORT_CONFIG
	; master port need to change cycle time after CMP[0] event
	;set		DEVICE_STATUS, DEVICE_STATUS, NEW_CYCLE_TIME_FLAG
SYNC_STATUS_4:

; SYNC_DELAY_FIELD_LOWER (5,6)
	M_XIN_L2_BANK0	SYNC_DELAY_FIELD_LOW, 6
SYNC_DELAY_FIELD_LOW:
	sbco	&R3.w0, ICSS_SHARED_RAM_CONST, SYNC_DELAY, 2
	lbco	&TEMP_REG_5.w2, ICSS_SHARED_RAM_CONST, LINE_DELAY_NEXT, 2		; note: load 16 bit to 32 bit register for ADC
	ldi		TEMP_REG_2.w2, 320+35	; PRU internal delay ToDo: replace with constant
	add		TEMP_REG_6, TEMP_REG_5.w2, TEMP_REG_2.w2
	add		TEMP_REG_6, TEMP_REG_6, R3.w0
	mov		R30.w0, TEMP_REG_6.w0
	M_PUSH_WORD

; SYNC_DELAY_FIELD_UPPER (7,8)
	M_XIN_L2_BANK0	SYNC_DELAY_FIELD_HIGH, 8
SYNC_DELAY_FIELD_HIGH:
	sbco	&R3.w2, ICSS_SHARED_RAM_CONST, SYNC_DELAY+2, 2
	add		R30.w0, TEMP_REG_6.w2, R3.w2
	M_PUSH_WORD

; SYNC_LINE_DELAY_PREVIOUS (9,10)
	M_XIN_L2_BANK0	SYNC_LINE_DELAY_UPPER, 10
SYNC_LINE_DELAY_UPPER:
	; add to line delay previous the bridge delay and line delay next
	ldi		TEMP_REG_1.w2, 320+35	; PRU internal delay ToDo: replace with constant
	add		R30.w0, TEMP_REG_1.w2, TEMP_REG_5.w2
	;add		R30.w0, TEMP_REG_1.w0, TEMP_REG_5.w2
	add		R30.w0, R30.w0, R4.w0
	M_PUSH_WORD
	sbco	&R4.w0, ICSS_SHARED_RAM_CONST, LINE_DELAY_PREVIOUS, 2

	; push CRC32
	M_CMD16 (D_PUSH_CRC_MSWORD_CMD | D_PUSH_CRC_LSWORD_CMD | D_TX_EOF)
	set		DEVICE_STATUS, DEVICE_STATUS, RX_IGNORE_TO_EOF
	jmp		STATE_MACHINE_RETURN

;**************************
; SYNC Handler Function
;**************************
; called from state.asm when NEW_SYNC_FRAME_FLAG is set.
; syncronizing the SLAVE;s IEP timer to the MASTER's IEP timer.
FN1_SYNC_HANDLER:
	qbeq	SYNC_HANDLER_INIT, SYNC_STATE_REG, 0
	add		SYNC_STATE_REG, SYNC_STATE_REG, 1
	qba		SYNC_HANDLER_AVERAGE


SYNC_HANDLER_INIT:
	lbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST,  SYNC_DELAY, 8	; SYNC_DELAY + SYNC_TS (TEMP_REG_2)
	lbco	&TEMP_REG_3, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 4
	sub		TEMP_REG_2, TEMP_REG_3, TEMP_REG_2
	add		TEMP_REG_1, TEMP_REG_1, TEMP_REG_2
	add		TEMP_REG_1, TEMP_REG_1, (12+3+12) * 5					; fixed time to access IEP register with calculations
	sbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 4
	add		SYNC_STATE_REG, SYNC_STATE_REG, 1
	RET1


SYNC_HANDLER_AVERAGE:
	lbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST, SYNC_DELAY, 8	; SYNC_DELAY + SYNC_TS (TEMP_REG_2)
	lbco	&TEMP_REG_3, ICSS_SHARED_RAM_CONST, SYNC_TS_AVERAGE, 4
	sub		TEMP_REG_1, TEMP_REG_1, TEMP_REG_2
	add		TEMP_REG_3, TEMP_REG_3, TEMP_REG_1
	sbco	&TEMP_REG_3, ICSS_SHARED_RAM_CONST, SYNC_TS_AVERAGE, 4
	;qbne	SYNC_HANDLER_AVERAGE_DONE, SYNC_STATE_REG, 9	; 8 averaging
	qbne	SYNC_HANDLER_AVERAGE_DONE, SYNC_STATE_REG, 17	; 16 averaging
	;qbne	SYNC_HANDLER_AVERAGE_DONE, SYNC_STATE_REG, 2	; no averaging
;SYNC_HANDLER_AVERAGE_PROCESSING:
	; init parameters and registers
	zero	&TEMP_REG_1, 4
	sbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST, SYNC_TS_AVERAGE, 4
	; set back sync counter to 1
	ldi		SYNC_STATE_REG, 1
	; compensation count init to 6
	ldi		TEMP_REG_1.b0, 0x06
	; check if positive or negative
	qbbc	SYNC_HANDLER_AV_POSITIVE, TEMP_REG_3, 31
;SYNC_HANDLER_AV_NEGATIVE:
	not		TEMP_REG_3, TEMP_REG_3
	add		TEMP_REG_3, TEMP_REG_3, 1
	; compensation count set to 4
	ldi		TEMP_REG_1.b0, 0x04
SYNC_HANDLER_AV_POSITIVE:
	;lsr		TEMP_REG_3, TEMP_REG_3, 3		; divide by 8
	lsr		TEMP_REG_3, TEMP_REG_3, 4		; divide by 16

	; threshold value if >5ns
	;qbge	SYNC_HANDLER_AVERAGE_DONE, TEMP_REG_3, 5
	; set compensation count value
	sbco	&TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_CFG_REG + 1, 1
	sbco	&TEMP_REG_3.w0, ICSS_IEP_CONST, ICSS_IEP_COMPEN_REG, 2
	; debug
	mov		TEMP_REG_2.b3, TEMP_REG_1.b0
	sbco	&TEMP_REG_2.b3, ICSS_SHARED_RAM_CONST, DEBUG_SYNC_MEASUREMENT, 4	; store the compnesation count value and 3 bytes of the compensation value
SYNC_HANDLER_AVERAGE_DONE:
	RET1

