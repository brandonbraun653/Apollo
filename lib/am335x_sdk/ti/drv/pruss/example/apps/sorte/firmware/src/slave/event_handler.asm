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
; 	file:   event_handler.asm
;
; 	brief: - INTC event handler service routines
;
;	Version		Description								Author
; 	0.1     	Created									Thomas Mauer
;include section
	.include "../include/macros/macros.inc"
	.include "../include/icss/icss_regs.inc"
	.include "../include/protocol/sorte_pru_slave_register.inc"
	.include "../include/protocol/sorte_host_interface.inc"
	.include "../include/protocol/sorte_state_define.inc"
	.include "../include/protocol/sorte_slave_cfg.inc"

	.global FN_EVENT_HANDLER
	.global FN1_IOEX_SETUP_TTS
	.global FN1_IOEX_WAIT_FOR_TTS_COMPLETE
	.global FN_RESTART_FIRMWARE

;Entry point to event handler. Process events/interrupts per PRU 0/1 current state.
FN_EVENT_HANDLER:
	.if $defined (PRU0)	; PRU0 event check, used bit 30
	qbbc	EVH_DONE, R31, 30
	; load highest priority currently pending interrupt for host interrupt 0
EVENT_HANDLER_RESTART:
	ldi		TEMP_REG_2.w0, ICSS_INTC_HIPIR0
	.else			; PRU1 event check, used bit 31.
	qbbc	EVH_DONE, R31, 31
	; load highest priority currently pending interrupt for host interrupt 1
EVENT_HANDLER_RESTART:
	ldi		TEMP_REG_2.w0, ICSS_INTC_HIPIR1
	.endif
	; 
	; Store event number in TEMP_REG_6. None of ISRs below should overwrite this register
	lbco	&TEMP_REG_6, ICSS_INTC_CONST, TEMP_REG_2.w0, 4

	qbbs	EVH_DONE, TEMP_REG_6, NONE_HINT_BIT
	; clear event in INTC after event has been handled: TEMP_REG_6 MUST not be overwritten by event handler!
	; TEMP_REG_6 at this time has the event/interrupt number

	; event jump table, check TEMP_REG_6 against defined events to see how to process the event;
	; for example if TEMP_REG_6 contains SYS_EVT_IEP_TIM_CAP_CMP_PEND, then jump to EVH_IEP_EVENT_PEND
	qbeq	EVH_IEP_EVENT_PEND, TEMP_REG_6, SYS_EVT_IEP_TIM_CAP_CMP_PEND
	qbeq	EVH_PRU2PRU_EVENT_PEND, TEMP_REG_6, PRU2PRU_EVT1	; IEP CMP[0] PRU2PRU event
	.if $defined(PRU0)
	qbeq	EVH_RX_EOF_EVENT_PEND, TEMP_REG_6, SYS_EVT_PRU0_RX_EOF
	qbeq	EVH_TX_EOF_EVENT_PEND, TEMP_REG_6, SYS_EVT_PORT1_TX_UNDERFLOW
	qbeq	EVH_CRC_ERROR_PEND, TEMP_REG_6, SYS_EVT_PRU0_RX_CRC
	.else
	qbeq	EVH_RX_EOF_EVENT_PEND, TEMP_REG_6, SYS_EVT_PRU1_RX_EOF
	qbeq	EVH_TX_EOF_EVENT_PEND, TEMP_REG_6, SYS_EVT_PORT0_TX_UNDERFLOW
	qbeq	EVH_CRC_ERROR_PEND, TEMP_REG_6, SYS_EVT_PRU1_RX_CRC
	.endif
	qbeq	EVH_MDIO_EVENT_PEND, TEMP_REG_6, SYS_EVT_MDIO_MII_LINK1
	qbeq	EVH_MDIO_EVENT_PEND, TEMP_REG_6, SYS_EVT_MDIO_MII_LINK0
	qbeq	EVH_TX_OVERFLOW_EVENT_PEND, TEMP_REG_6, SYS_EVT_PORT0_TX_OVERFLOW
	qbeq	EVH_TX_OVERFLOW_EVENT_PEND, TEMP_REG_6, SYS_EVT_PORT1_TX_OVERFLOW

	; Received an event which is not registered.
	; clear this not registered event via EVH_CLR_INTC_EVENT;
	; this is also used to clear a registered event in the PRU-ICSS interrupt controller.
	; reference to EVH_CLR_INTC_EVENT is seen below after processing each event;
EVH_CLR_INTC_EVENT:
	sbco	&TEMP_REG_6, ICSS_INTC_CONST, ICSS_INTC_SICR, 4
	qba 	EVENT_HANDLER_RESTART

EVH_DONE:
	RET

EVH_TX_OVERFLOW_EVENT_PEND:
	lbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, DEBUG_PRU0_CNT, 2
	add		TEMP_REG_1.w0, TEMP_REG_1.w0, 1
	sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, DEBUG_PRU0_CNT, 2
	M_CMD16 D_RESET_TXFIFO
	qba		EVH_CLR_INTC_EVENT


EVH_TX_EOF_EVENT_PEND:
	; the function was moved to FN1_IOEX_WAIT_FOR_TTS_COMPLETE
	set		DEVICE_STATUS, DEVICE_STATUS, DEBUG_TX_FIFO_UNDERFLOW
	qba		EVH_CLR_INTC_EVENT

;*****************************
; RX CRC error event handler
;*****************************
EVH_CRC_ERROR_PEND:
	; in IOEX we use CRC8, do not flag CRC32 errors
	qbeq	EVH_CRC_ERROR_DONE, PROTOCOL_STATE, IOEX_STATE
	.if $defined(PRU0)
	lbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_ERROR_PRU0, 2
	add		TEMP_REG_1.w0, TEMP_REG_1.w0, 1
	sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_ERROR_PRU0, 2
	.else
	lbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_ERROR_PRU1, 2
	add		TEMP_REG_1.w0, TEMP_REG_1.w0, 1
	sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_ERROR_PRU1, 2
	.endif
	set		DEVICE_STATUS, DEVICE_STATUS, RX_FRAME_CRC_ERROR
EVH_CRC_ERROR_DONE:
	qba		EVH_CLR_INTC_EVENT

;*****************************
; IEP event handler
;*****************************
EVH_IEP_EVENT_PEND:
	; read IEP event register and clear event.
	lbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 4
	; clearing hte IEP event has been moved to the end of the function.
	qbbc	EVH_IEP_CMP1, TEMP_REG_1, 0
;EVH_IEP_CMP0:	; IEP CMP0 timer wrap-around
	M_CMD16 (D_RESET_RXFIFO | D_RX_ERROR_CLEAR )
	; Master frame monitoring in IOEX state
	qbne	EVH_IEP_CMP0_SKIP_FRAME_MONITORING, PROTOCOL_STATE, IOEX_STATE
	; increment IO cycle count register
	add		IO_CYCLE_CNT, IO_CYCLE_CNT, 1
	; set CMP0 flag for SYNC0 generation
	set		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, IEP_CMP0_FLAG
	lbco	&TEMP_REG_1.b0, ICSS_SHARED_RAM_CONST, IOEX_FRAME_RECEIVED, 1
	ldi		TEMP_REG_1.b1, 0
	sbco	&TEMP_REG_1.b1, ICSS_SHARED_RAM_CONST, IOEX_FRAME_RECEIVED, 1
	qbne	EVH_IEP_CMP0_RESET_FRAME_MON,TEMP_REG_1.b0, 0
	lbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, IOEX_FRAME_MONITOR, 2
	add		TEMP_REG_1.w0, TEMP_REG_1.w0, 1
	sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, IOEX_FRAME_MONITOR, 2
	qbge	EVH_IEP_CMP0_SKIP_FRAME_MONITORING, TEMP_REG_1.w0, 5
	;ldi		TEMP_REG_1.w0, 0
	;sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, IOEX_FRAME_MONITOR, 2
	.if $defined(remove)
	ldi		TEMP_REG_1.b0, 0x55
	.if $defined(PRU0)
	sbco	&TEMP_REG_1.b0, ICSS_SHARED_RAM_CONST, PRU1_RESET, 1
	.else
	sbco	&TEMP_REG_1.b0, ICSS_SHARED_RAM_CONST, PRU0_RESET, 1
	.endif
	.endif
	JMP		FN_RESTART_FIRMWARE
EVH_IEP_CMP0_RESET_FRAME_MON:
	ldi		TEMP_REG_1.w0, 0
	sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, IOEX_FRAME_MONITOR, 2

EVH_IEP_CMP0_SKIP_FRAME_MONITORING:
	lbco	&TEMP_REG_2, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 4
	.if $defined(remove)
	; re-enable SYNC0
	; clear and set sync_en bit in IEP timer to re-enable CON_CLK trigger
	LDI		TEMP_REG_1, 0x06	; clear sync_en (sync0_en, sync1_en)
	LDI		TEMP_REG_2.w0, (ICSS_IEP_SYNC_BLK_INDEX << 8) + ICSS_IEP_SYNC_CTRL_REG
	SBCO	&TEMP_REG_1, ICSS_IEP_CONST, TEMP_REG_2.w0, 4
	LDI		TEMP_REG_1, 0x07	;  set sync_en (sync0_en, sync1_en)
	SBCO	&TEMP_REG_1, ICSS_IEP_CONST, TEMP_REG_2.w0, 4
	.endif

	; CMP0 event is used for IOEX state only
	qbne	EVH_IEP_CMP1, PROTOCOL_STATE, IOEX_STATE
	; start new TTS
	;CALL1	FN1_IOEX_SETUP_TTS
	; reload ICSS_IEP_CMP_STATUS_REG because FN1_IOEX_SETUP_TTS has used TEMP_REG_1: ToDo clean up
	lbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 4
	qbbc	EVH_IEP_CMP0_CHANGE_PORT, DEVICE_STATUS, NEW_CYCLE_TIME_FLAG
	ldi32	TEMP_REG_2, 4000-5	; 4usec cycle time
	sbco	&TEMP_REG_2, ICSS_IEP_CONST, ICSS_IEP_CMP0_REG, 4
	; enable CMP7 to trigger SYNC0 setting
	lbco	&TEMP_REG_2.w0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 2
	set		TEMP_REG_2.w0, TEMP_REG_2.w0, 7+1
	sbco	&TEMP_REG_2.w0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 2
EVH_IEP_CMP0_CHANGE_PORT:
	;M_SET_MIIRT_AF
EVH_IEP_CMP1:
	qbbc	EVH_IEP_CMP2, TEMP_REG_1, 1
EVH_IEP_CMP2:
	qbbc	EVH_IEP_CMP3, TEMP_REG_1, 2
EVH_IEP_CMP3:
	qbbc	EVH_IEP_CMP4, TEMP_REG_1, 3
	; disable TTS in TXCFG0
	ldi		TEMP_REG_2.b0, 0x01
	sbco	&TEMP_REG_2.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 1
	set		DEVICE_STATUS, DEVICE_STATUS, TTS_CMP34_FLAG
EVH_IEP_CMP4:
	qbbc	EVH_IEP_CMP6, TEMP_REG_1, 4
	; disable TTS in TXCFG1
	ldi		TEMP_REG_2.b0, 0x01
	sbco	&TEMP_REG_2.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 1
	set		DEVICE_STATUS, DEVICE_STATUS, TTS_CMP34_FLAG
EVH_IEP_CMP6:
	qbbc	EVH_IEP_CMP7, TEMP_REG_1, 6
	qbne	EVH_IEP_CMP7, PROTOCOL_STATE, IOEX_STATE
	; set CMP6 flag
	set		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, IEP_CMP6_FLAG
EVH_IEP_CMP7:
	qbbc	EVH_IEP_EVENT_DONE, TEMP_REG_1, 7
	qbne	EVH_IEP_EVENT_DONE, PROTOCOL_STATE, IOEX_STATE
	set		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, IEP_CMP7_FLAG

EVH_IEP_EVENT_DONE:
	; clear IEP CMP events
	sbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_STATUS_REG, 4
	; if TTS_CMP34_FLAG is set, wait for TX_EOF
	qbbc	EVH_IEP_EVENT_DONE_2, DEVICE_STATUS, TTS_CMP34_FLAG
	;
	;CALL1	FN1_IOEX_WAIT_FOR_TTS_COMPLETE
EVH_IEP_EVENT_DONE_2:
	qba		EVH_CLR_INTC_EVENT

;*****************************
; PRU2PRU event handler
;*****************************
EVH_PRU2PRU_EVENT_PEND:
	;qbne	PRU2PRU_EVENT_STATE_CHANGE, PROTOCOL_STATE, IOEX_STATE
	;set		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, IEP_CMP7_FLAG
	;qba		EVH_CLR_INTC_EVENT
;PRU2PRU_EVENT_STATE_CHANGE:
	; initiate IOEX state for slave port
	ldi		PROTOCOL_STATE, IOEX_STATE
	set		DEVICE_STATUS, DEVICE_STATUS, LAST_DEVICE_FLAG
	set		DEVICE_STATUS, DEVICE_STATUS, NEW_CYCLE_TIME_FLAG
	clr		DEVICE_STATUS, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	lbco	&SLAVE_ADDR, ICSS_SHARED_RAM_CONST, SLAVE_ADDR_OFFSET, 1

	; store protocol state in shared memory
	.if $defined(PRU0)
	sbco	&PROTOCOL_STATE, ICSS_SHARED_RAM_CONST, DEBUG_PRU0_SLAVE_STATE, 1
	.else
	sbco	&PROTOCOL_STATE, ICSS_SHARED_RAM_CONST, DEBUG_PRU1_SLAVE_STATE, 1
	.endif

	qba		EVH_CLR_INTC_EVENT


;*****************************
; Receive EOF event handler
;*****************************
EVH_RX_EOF_EVENT_PEND:
	; DEBUG: store slave state
	.if $defined(PRU0)
	sbco	&PROTOCOL_STATE, ICSS_SHARED_RAM_CONST, DEBUG_PRU0_SLAVE_STATE, 1
	.else
	sbco	&PROTOCOL_STATE, ICSS_SHARED_RAM_CONST, DEBUG_PRU1_SLAVE_STATE, 1
	.endif

;EVH_RX_EOF_CHECK_FRAME_CRC:
	qbeq	EVH_RX_EOF_NO_RESET_RXFIFO, PROTOCOL_STATE, IOEX_STATE
	; CRC check is done via dedicated event handler
	xin		RXL2_BANK0, &R18.b0, 1
	xin		RXL2_BANK0, &R10, RANGE_R10_R13
	qbbc	EVH_RX_EOF_EXTRACT_CRC, R18.b0, 4
	xin		RXL2_BANK0, &R10, RANGE_R10_R13
EVH_RX_EOF_EXTRACT_CRC:
	M_EXTRACT_RXL2STATUS
	qbbc	EVH_RX_EOF_RESET_RXFIFO, R1.b0, L2_ERROR_CRC_FLAG_BITNUM	;ERROR_CRC
	; CRC32 error detected, update statistics
	set		DEVICE_STATUS, DEVICE_STATUS, RX_FRAME_CRC_ERROR
	.if $defined(PRU0)
	lbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_ERROR_PRU0, 2
	add		TEMP_REG_1.w0, TEMP_REG_1.w0, 1
	sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_ERROR_PRU0, 2
	.else
	lbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_ERROR_PRU1, 2
	add		TEMP_REG_1.w0, TEMP_REG_1.w0, 1
	sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, STATS_CRC_ERROR_PRU1, 2
	.endif
EVH_RX_EOF_RESET_RXFIFO:
	;qbeq	EVH_RX_EOF_RESET_RXFIFO_2, PROTOCOL_STATE, IOEX_STATE
	M_CMD16 (D_RESET_RXFIFO | D_RX_ERROR_CLEAR )
EVH_RX_EOF_NO_RESET_RXFIFO:
	clr		DEVICE_STATUS, DEVICE_STATUS, RX_IGNORE_TO_EOF
	qbbc	EVH_RX_EOF_RESET_RXFIFO_3, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	;CHANGE_EDIO_OUT7
	set		DEVICE_STATUS, DEVICE_STATUS, IOEX_MASTER_FRAME_EOF
EVH_RX_EOF_RESET_RXFIFO_3:
	qbbc	EVH_CLR_INTC_EVENT, DEVICE_STATUS, SWITCH_PORT_CONFIG
;******************
; Discovery state
;******************
EVH_RX_EOF_SWITCH_DISC:
	qbne	EVH_RX_EOF_SWITCH_PARAM, PROTOCOL_STATE, DISC_STATE
	; Discovery mode: first port is CT, second port is AF
	; The master port must enable CT on his local port (the second port remains in AF)
	qbbc	EVH_RX_EOF_DONE, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	; do not configure MII_RT configuration for last device - it is already configured correctly
	qbbs	EVH_RX_EOF_SWITCH_DISC_IEP_HANDLER_SWITCH, 	DEVICE_STATUS, LAST_DEVICE_FLAG
	M_SET_MIIRT_AF2CT_LOCAL
EVH_RX_EOF_SWITCH_DISC_IEP_HANDLER_SWITCH:
	; set IEP event channel to reverse port PRU and PRU2PRU event to reverse port PRU (swap INTC channel 3/4 to host mapping)
	.if $defined(PRU0)
	ldi		TEMP_REG_1.w0, 0x0001
	.else
	ldi		TEMP_REG_1.w0, 0x0100
	.endif
	ldi		TEMP_REG_1.w2, ICSS_INTC_HMR0 + 3
	sbco	&TEMP_REG_1.w0, ICSS_INTC_CONST, TEMP_REG_1.w2, 2
	qba		EVH_RX_EOF_DONE
;******************
; Parameter state
;******************
EVH_RX_EOF_SWITCH_PARAM:
	qbne	EVH_RX_EOF_SWITCH_LINE_DELAY, PROTOCOL_STATE, PARAM_STATE
	; Param mode: both ports are AF
	; the non-master port or the last slave must configure both ports
	qbbc	EVH_RX_EOF_SWITCH_PARAM_2, DEVICE_STATUS, LAST_DEVICE_FLAG
	; last slave must enable loopback
	M_SET_MIIRT_AF_LB
	qba		EVH_RX_EOF_DONE
EVH_RX_EOF_SWITCH_PARAM_2:
	qbbs	EVH_RX_EOF_DONE, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	M_SET_MIIRT_AF
	; non master port needs to get slave address into register
	lbco	&SLAVE_ADDR, ICSS_SHARED_RAM_CONST, SLAVE_ADDR_OFFSET, 1
	qba		EVH_RX_EOF_DONE
;******************
; Line delay state
;******************
EVH_RX_EOF_SWITCH_LINE_DELAY:
	qbne	EVH_RX_EOF_SWITCH_SYNC, PROTOCOL_STATE, LINED_STATE
	; Line delay mode: initially first port is loopback, second port is open
	qbbs	EVH_RX_EOF_SWITCH_LINE_DELAY_ENABLE_IEP, DEVICE_STATUS, LAST_DEVICE_FLAG
	qbbs	EVH_RX_EOF_DONE, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	; second port will initiate port configuration
	.if $defined (PRU0)
	M_SET_DELAY_S_P1
	M_SET_DELAY_M_P0
	.else
	M_SET_DELAY_S_P0
	M_SET_DELAY_M_P1
	.endif
EVH_RX_EOF_SWITCH_LINE_DELAY_ENABLE_IEP:
	; set IEP timer back to 0 and start IEP timer
	zero	&TEMP_REG_2, 4
	ldi     TEMP_REG_1.b0, 0x51
	sbco  	&TEMP_REG_2, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 4
	sbco    &TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_GLOBAL_CFG_REG, 1
	; clear PORT_DELAY register in shared RAM
	sbco	&TEMP_REG_2, ICSS_SHARED_RAM_CONST, PORT_DELAY, 4
	qba		EVH_RX_EOF_DONE
;******************
; Sync state
;******************
EVH_RX_EOF_SWITCH_SYNC:
	qbne	EVH_RX_EOF_SWITCH_IOEX, PROTOCOL_STATE, SYNC_STATE
	; non-master port will initiate port switch
	qbbs	EVH_RX_EOF_DONE, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	; sync mode:
	M_SET_MIIRT_SYNC_STATE
	; set cycle time with IEP timer
	; ToDo: Do net set CMP0 value
	;ldi32	TEMP_REG_1, 10000	;10us
	;sbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP0_REG, 4
	;lbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4
	;or		TEMP_REG_1.b0, TEMP_REG_1.b0, 0x03
	or		TEMP_REG_1.b0, TEMP_REG_1.b0, 0x07	; including CMP[1] for SYNC0
	; ToDo: Do not set CMP0 war-around and do not enable CMP0 event
	;sbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4
	; ToDo: decide on last slave port configuration
	; calculate line+port delay after line delay measurements
	lbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST, PORT_DELAY, 4
	ldi		TEMP_REG_2.w0, BRIDGE_DELAY_CONST
	sub		TEMP_REG_1, TEMP_REG_1, TEMP_REG_2.w0
	lsr		TEMP_REG_1, TEMP_REG_1, 1
	; ToDo: Next line is debug only
	;ldi32	TEMP_REG_1, 0x300
	sbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, LINE_DELAY_NEXT, 2
	; refresh slave address
	lbco	&SLAVE_ADDR, ICSS_SHARED_RAM_CONST, SLAVE_ADDR_OFFSET, 1
	qba		EVH_RX_EOF_DONE

;******************
; Data I/O state
;******************
EVH_RX_EOF_SWITCH_IOEX:
	qbne	EVH_RX_EOF_DONE, PROTOCOL_STATE, IOEX_STATE

	;CHANGE_EDIO_OUT0
	qbbc	EVH_RX_EOF_SWITCH_IOEX_NOT_LAST_DEVICE, DEVICE_STATUS, LAST_DEVICE_FLAG

	; set IEP event channel to reverse port PRU and PRU2PRU event to reverse port PRU (swap INTC channel 3/4 to host mapping)
	.if $defined(PRU0)
	ldi		TEMP_REG_1.w0, 0x0001
	.else
	ldi		TEMP_REG_1.w0, 0x0100
	.endif
	ldi		TEMP_REG_1.w2, ICSS_INTC_HMR0 + 3
	sbco	&TEMP_REG_1.w0, ICSS_INTC_CONST, TEMP_REG_1.w2, 2

	; modified M_SET_MIIRT_AF macro
	ldi  	TEMP_REG_1.w0, 0x1d15
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG0, 1
	sbco 	&TEMP_REG_1.b1, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG1, 1
	ldi32	TEMP_REG_1, 0x00400301
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 3
	ldi	    TEMP_REG_1.b1, 2
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 3

	; send event to second PRU
	LDI		R31.b0, PRU2PRU_INTR1

	qba		EVH_RX_EOF_SWITCH_IOEX_SET_IEP_TIME

EVH_RX_EOF_SWITCH_IOEX_NOT_LAST_DEVICE:


	; non-master port will initiate port switch
	qbbs	EVH_RX_EOF_DONE, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	M_SET_MIIRT_AF

EVH_RX_EOF_SWITCH_IOEX_SET_IEP_TIME:
	; after last SYNC frame the cycle I/O will start at +10ms
	lbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST, SYNC_TS, 4
	ldi		TEMP_REG_2.w0, 10000
	add		TEMP_REG_1, TEMP_REG_1, TEMP_REG_2.w0
	sbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP0_REG, 4
	ldi		TEMP_REG_1.b0, 0x07 ; including CMP[1] for SYNC0
	sbco	&TEMP_REG_1.b0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 1
	; when CMP[0] is hit, set new cycle time of 4us
	set		DEVICE_STATUS, DEVICE_STATUS, NEW_CYCLE_TIME_FLAG

	; set expected frame TS of the master frame in ioex state
	lbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, LINE_DELAY_PREVIOUS, 2
	ldi		TEMP_REG_1.w2, 500
	add		TEMP_REG_1, TEMP_REG_1.w0, TEMP_REG_1.w2
	sbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST, IOEX_MASTER_SYNC_TS, 4
	; SYNC_DELAY is used in ioex to compare master frame ts with expected ts
	sbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST, SYNC_DELAY, 4	; SYNC_DELAY

EVH_RX_EOF_DONE:
	clr		DEVICE_STATUS, DEVICE_STATUS, SWITCH_PORT_CONFIG
	qba		EVH_CLR_INTC_EVENT

;************************************************************
; MDIO event handler: entry point to process mdio link events
;************************************************************
EVH_MDIO_EVENT_PEND:
	; clear MDIO event in MDIO module; need to write value into a register as below
	; and then use register to write to actual memory.
	ldi		TEMP_REG_1, 0x03
	; memcpy (ICSS_MDIO_CONST + ICSS_MDIO_LINKINTMASKED, &TEMP_REG_1, 4)
	sbco	&TEMP_REG_1, ICSS_MDIO_CONST, ICSS_MDIO_LINKINTMASKED, 4
	; get current link information from MDIO module
	lbco	&TEMP_REG_1, ICSS_MDIO_CONST, ICSS_MDIO_LINK, 4
	ldi	TEMP_REG_2.w0, MDIO_PHY_CONFIG_OFFSET
	; need to retrieve the board specific phy addresses which is configured by the 
        ;SORTE application
	lbco	&TEMP_REG_2, ICSS_SHARED_RAM_CONST, TEMP_REG_2.w0, 4
	; initializng the register to store the result
	zero	&TEMP_REG_3.w0, 2
PM_PHY_0:
	; parse link bit for PHY0
	qbbc	PM_PHY_0_ACT_HIGH, TEMP_REG_2, 16		; 0: active high; 1: active low
;PM_PHY_0_ACT_LOW:
	qbbs	PM_PHY_1, TEMP_REG_1, TEMP_REG_2.b0
	qba		PM_PHY_0_CONFIG
PM_PHY_0_ACT_HIGH:
	qbbc	PM_PHY_1, TEMP_REG_1, TEMP_REG_2.b0
PM_PHY_0_CONFIG:
	set		TEMP_REG_3.b0, TEMP_REG_3.b0, 0	;
PM_PHY_1:
	; parse link bit for PHY1
	qbbc	PM_PHY_1_ACT_HIGH, TEMP_REG_2, 24		; 0: active high; 1: active low
; PM_PHY_1_ACT_LOW:
	qbbs	PM_STORE_PHY_STATUS, TEMP_REG_1, TEMP_REG_2.b1
	qba		PM_PHY_1_CONFIG
PM_PHY_1_ACT_HIGH:
	qbbc	PM_STORE_PHY_STATUS, TEMP_REG_1, TEMP_REG_2.b1
PM_PHY_1_CONFIG:
	set		TEMP_REG_3.b1, TEMP_REG_3.b1, 0
PM_STORE_PHY_STATUS:
	lbco	&TEMP_REG_3.w2, ICSS_SHARED_RAM_CONST, PHY_STATUS_OFFSET, 2
	qbeq	PM_STORE_PHY_STATUS_2, TEMP_REG_3.w0, TEMP_REG_3.w2
	; send event to other PRU about port change
	.if $defined(PRU0)
	ldi32	TEMP_REG_1, 0x00000200	; Set MDIO_MII_LINK[0] bit
	ldi		TEMP_REG_2.w0, ICSS_INTC_SRSR1
	sbco	&TEMP_REG_1, ICSS_INTC_CONST, TEMP_REG_2.w0, 4
	.else
	ldi32	TEMP_REG_1, 0x00200000	; Set MDIO_MII_LINK[1]
	ldi		TEMP_REG_2.w0, ICSS_INTC_SRSR1
	sbco	&TEMP_REG_1, ICSS_INTC_CONST, TEMP_REG_2.w0, 4
	.endif
PM_STORE_PHY_STATUS_2:
	sbco	&TEMP_REG_3.w0, ICSS_SHARED_RAM_CONST, PHY_STATUS_OFFSET, 2
	and		TEMP_REG_3.b0, TEMP_REG_3.b0, TEMP_REG_3.b1
	qbbs	PM_SET_AF_CONFIG, TEMP_REG_3.b0, 0
	or		DEVICE_STATUS, DEVICE_STATUS, (1<<LAST_DEVICE_FLAG) | (1<<PRU_MASTER_PORT_FLAG)
	; set cut-through configuration in RXCFG and TXCFG
	M_SET_MIIRT_CT_LB
	qba		PM_CHECK_FOR_RESTART
PM_SET_AF_CONFIG:
	; can optimize to use "and" command to clear DEVICE_STATUS bits
	clr		DEVICE_STATUS, DEVICE_STATUS, LAST_DEVICE_FLAG
	clr		DEVICE_STATUS, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	; set auto-forward configuration in RXCFG and TXCFG, but only if we are in IDLE state
	qbne	EVH_CLR_INTC_EVENT, PROTOCOL_STATE, IDLE_STATE
	M_SET_MIIRT_AF
PM_CHECK_FOR_RESTART:
	; restart if device is in non-idle state and if master port detects MDIO event
	qbeq	PM_NO_RESTART, PROTOCOL_STATE, IDLE_STATE
	qbbc	PM_NO_RESTART, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	.if $defined(PRU0)
	qbbs	EVH_CLR_INTC_EVENT, TEMP_REG_3.w0, 0		; Port 0 is bit 0
	.else
	qbbs	EVH_CLR_INTC_EVENT, TEMP_REG_3.w0, 8		; Port 1 is bit 8
	.endif
	jmp		FN_RESTART_FIRMWARE
PM_NO_RESTART:
	qba		EVH_CLR_INTC_EVENT
