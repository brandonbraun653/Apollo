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
; 	file:   state.asm
;
; 	brief:
;
;	Version		Description								Author
; 	0.1     	Created									Thomas Mauer
;include section
	.include "../include/macros/macros.inc"
	.include "../include/icss/icss_regs.inc"
	.include "../include/protocol/sorte_pru_slave_register.inc"
	.include "../include/protocol/sorte_state_define.inc"
	.include "../include/protocol/sorte_packet_definition.inc"
	.include "../include/protocol/sorte_host_interface.inc"

	.global FN_STATE_MACHINE
	.global FN_DISCOVERY
	.global FN_PARAM
	.global FN_LINE_DELAY_MASTER
	.global FN_LINE_DELAY_SLAVE
	.global STATE_MACHINE_RETURN
	.global FN1_SYNC_HANDLER
	.global	FN1_IOEX_PROCESS_DATA
  	.global FN_SYNC_STATE
	.global FN_IOEX_MASTER
	.global FN1_IOEX_WAIT_FOR_TTS_COMPLETE
	.global FN_IOEX_MASTER_PROCESS_FRAME
	.global FN_RESTART_FIRMWARE
	.global FN1_APPL_CHECK_IEP_EVENT
;*******************************************************************
; DEVICE/SLAVE state machine
;*******************************************************************
FN_STATE_MACHINE:

	; fast jump to IOEX state
	qbeq	STATE_IOEX, PROTOCOL_STATE, IOEX_STATE

; ------------------------------------------------------------------------------
; state: IDLE (INITIAL STATE)
; Check to see if frame has been received from master, determine which pru-icss port
; is connected to the master. 
; State transition criteria: DISOVERY frame received, next state: DISCOVERY  
STATE_IDLE:
	qbne	STATE_DISCOVERY, PROTOCOL_STATE, IDLE_STATE
	qbbs	STATE_MACHINE_RETURN, DEVICE_STATUS, RX_IGNORE_TO_EOF
	xin		RXL2_BANK0, &R18.b0, 1
	qbeq	STATE_MACHINE_RETURN, R18.b0, 0
	; if this is the last slave in line, move directly to discovery state
	; otherwise the slave needs to detect if this Ethernet port receives frame
	; from the master or the reverse direction
	QBBS	STATE_IDLE_NEXT_STATE_LAST_DEVICE, DEVICE_STATUS, LAST_DEVICE_FLAG
	; detect if this Ethernet port receives frame from the master or reverse direction
STATE_IDLE_DETECT_MASTER_PORT:
	xin		RXL2_BANK0, &R2.b0, RANGE_R2_R18
	qbgt	STATE_IDLE_DETECT_MASTER_PORT, R18.b0, 4
	clr		DEVICE_STATUS, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	; check if discovery frame
	qbne	STATE_IGNORE_FRAME_TO_EOF, R2.b0, DA_MC		;broadcast
	qbne	STATE_IGNORE_FRAME_TO_EOF, R2.b2, T_DISCOV_MC;
	; check if LAST bit is set
	qbbs	STATE_IDLE_NEXT_STATE, R2.b3, 0	;ST_LAST
	set		DEVICE_STATUS, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	; initiate port change from AF to CT a
	set		DEVICE_STATUS, DEVICE_STATUS, SWITCH_PORT_CONFIG
	; adjust IEP timer to frame timestamp

STATE_IDLE_NEXT_STATE:
	ldi		PROTOCOL_STATE, DISC_STATE
	set		DEVICE_STATUS, DEVICE_STATUS, SWITCH_PORT_CONFIG
	QBA		STATE_IGNORE_FRAME_TO_EOF

STATE_IDLE_NEXT_STATE_LAST_DEVICE:
	; The last device is in cut through state, need to process data via DISCOVERY
	LDI		PROTOCOL_STATE, DISC_STATE
	set		DEVICE_STATUS, DEVICE_STATUS, SWITCH_PORT_CONFIG

; ------------------------------------------------------------------------------
; state: DISCOVERY
; Respond to discovery frame sent by master, frame payload  will be updated by each
; slave device  in the chain until last slave determines its end of the chain.
; Forward discovery frame to next slave device.
; State transition criteria: Master upon receiving DISCOVERY frame
; will send updated DISCOVERY frame with BIT 3 of status byte set with value of 1.
; This will cause slave device to transition to STATE_PARAM
STATE_DISCOVERY:
	qbne	STATE_PARAM, PROTOCOL_STATE, DISC_STATE
	qbbs	STATE_MACHINE_RETURN, DEVICE_STATUS, RX_IGNORE_TO_EOF
	; reverse port does not need to process data
 	qbbc	STATE_DISCOVERY_REVERSE_PORT, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
STATE_DISCOVERY_MASTER_PORT:
	; fetch R18.b0 L2 buffer write pointer
	;xin		RXL2_BANK0, &R18.b0, 1
	xin		RXL2_BANK0, &R2.b0, RANGE_R2_R18
	qbeq	STATE_MACHINE_RETURN, R18.b0, 0
	jmp		FN_DISCOVERY

STATE_DISCOVERY_REVERSE_PORT:
	; reverse port need to monitor state change in status field
	xin		RXL2_BANK0, &R2.b0, RANGE_R2_R18
	qbeq	STATE_MACHINE_RETURN, R18.b0, 0
	qbgt	STATE_DISCOVERY_REVERSE_PORT, R18.b0, 4
	qbbc	STATE_IGNORE_FRAME_TO_EOF, R2.b3, 3 ; ST_STATE_CHANGE
	ldi		PROTOCOL_STATE, PARAM_STATE
	set		DEVICE_STATUS, DEVICE_STATUS, SWITCH_PORT_CONFIG
	QBA		STATE_IGNORE_FRAME_TO_EOF


; ------------------------------------------------------------------------------
; state: PARAM
; Master send parameterization frame with parameters(network,application, diagnostic/error)
; this frame is not modified by slave but returned back to master
; State transition criteria: BIT 3 of status byte of PARAMETERIZATION frame set 
; to 1, next state LINE_DELAY
STATE_PARAM:
	qbne	STATE_LINEDELAY, PROTOCOL_STATE, PARAM_STATE
	qbbs	STATE_MACHINE_RETURN, DEVICE_STATUS, RX_IGNORE_TO_EOF
	; reverse port does not need to process data
 	qbbc	STATE_PARAM_REVERSE_PORT, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
STATE_PARAM_MASTER_PORT:
	; fetch R18.b0 L2 buffer write pointer
	;xin		RXL2_BANK0, &R18.b0, 1
	xin		RXL2_BANK0, &R2.b0, RANGE_R2_R18
	qbeq	STATE_MACHINE_RETURN, R18.b0, 0
	jmp		FN_PARAM

STATE_PARAM_REVERSE_PORT:
	; reverse port needs to monitor state change bit in status byte
	xin		RXL2_BANK0, &R2.b0, RANGE_R2_R18
	qbeq	STATE_MACHINE_RETURN, R18.b0, 0
	qbgt	STATE_PARAM_REVERSE_PORT, R18.b0, 4
	qbbc	STATE_IGNORE_FRAME_TO_EOF, R2.b3, 3 ; ST_STATE_CHANGE
	ldi		PROTOCOL_STATE, LINED_STATE
	set		DEVICE_STATUS, DEVICE_STATUS, SWITCH_PORT_CONFIG
	qba 	STATE_IGNORE_FRAME_TO_EOF

; ------------------------------------------------------------------------------
; state: LINE_DELAY
; Line Delay frame sent from master to 1st slave;
; 1st slave sends line delay frame back  with a fixed forward delay to master.
; 1st slave also sends line delay frame to next slave, 
; this is repeated until end of slave device chain
; State transition criteria:BIT 3 of  status byte of line delay frame is set 
;   to 1, next state SYNC
STATE_LINEDELAY:
	qbne	STATE_SYNC, PROTOCOL_STATE, LINED_STATE
	; line delay master port?
	;qbbc	FN_LINE_DELAY_MASTER, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	qbbs	STATE_LINEDELAY_SLAVE, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	jmp		FN_LINE_DELAY_MASTER
STATE_LINEDELAY_SLAVE:
	; line delay slave port
	qbbs	STATE_MACHINE_RETURN, DEVICE_STATUS, RX_IGNORE_TO_EOF
	xin		RXL2_BANK0, &R2.b0, RANGE_R2_R18
	qbeq	STATE_MACHINE_RETURN, R18.b0, 0
	jmp		FN_LINE_DELAY_SLAVE
	;qba		FN_LINE_DELAY_SLAVE

; ------------------------------------------------------------------------------
; state: SYNC
; Master send a SYNC frame to slave devices, slaves adjusts internal clock
; so slaves has same IEP timer as MASTER
; State transition criteria:BIT 3 of  status byte of sync frame is set 
; to 1, next state IOEX
STATE_SYNC:
	qbne	STATE_IOEX, PROTOCOL_STATE, SYNC_STATE
	qbbs	STATE_MACHINE_RETURN, DEVICE_STATUS, RX_IGNORE_TO_EOF
	qbbc	STATE_SYNC_SLAVE, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
	xin	RXL2_BANK0, &R2.b0, RANGE_R2_R18
	qbeq	STATE_SYNC_FRAME_PROCESS, R18.b0, 0
	jmp	FN_SYNC_STATE
STATE_SYNC_FRAME_PROCESS:
	qbbc	STATE_MACHINE_RETURN, DEVICE_STATUS, NEW_SYNC_FRAME_FLAG
	clr	DEVICE_STATUS, DEVICE_STATUS, NEW_SYNC_FRAME_FLAG
	CALL1	FN1_SYNC_HANDLER
	qba	STATE_MACHINE_RETURN

STATE_SYNC_SLAVE:
	; line delay slave port
	qbbs	STATE_MACHINE_RETURN, DEVICE_STATUS, RX_IGNORE_TO_EOF
	xin	RXL2_BANK0, &R2.b0, RANGE_R2_R18
	qbeq	STATE_MACHINE_RETURN, R18.b0, 0
	qbgt	STATE_SYNC_SLAVE, R18.b0, 4
	qbbc	STATE_IGNORE_FRAME_TO_EOF, R2.b3, 3 ; ST_STATE_CHANGE
	ldi	PROTOCOL_STATE, IOEX_STATE
	set	DEVICE_STATUS, DEVICE_STATUS, SWITCH_PORT_CONFIG
	qba 	STATE_IGNORE_FRAME_TO_EOF

; ------------------------------------------------------------------------------
; state: IOEX (input/output exchange)
; Master transmits large frame to the slave. each slave will read a 
; dedicated block in the payload and save this in SRAM.
; Since each slaves internal clock(IEP timer) is synced with master, slaves will use
; TTS to respond with a IOEX frame back to the master.
; State transition criteria: if no master IOEX frame is received within pre-configured
; time period, each slave will transition to IDLE.
STATE_IOEX:
	qbne	STATE_DIAG, PROTOCOL_STATE, IOEX_STATE
	qbbc	STATE_IOEX_SLAVE, DEVICE_STATUS, PRU_MASTER_PORT_FLAG
STATE_IOEX_MASTER:
	qbbc	STATE_IOEX_MASTER_2, DEVICE_STATUS, IOEX_MASTER_FRAME_EOF
	clr		DEVICE_STATUS, DEVICE_STATUS, IOEX_MASTER_FRAME_EOF
	CALL1	FN_IOEX_MASTER_PROCESS_FRAME
STATE_IOEX_MASTER_2:
	; process new data if available
	qbbc	STATE_IOEX_MASTER_3, DEVICE_STATUS, NEW_IOEX_DATA_FLAG
	CALL1	FN1_IOEX_PROCESS_DATA
STATE_IOEX_MASTER_3:
	qbbc	STATE_IOEX_MASTER_RCV, DEVICE_STATUS, NEW_SYNC_FRAME_FLAG
	CALL1	FN1_SYNC_HANDLER
STATE_IOEX_MASTER_RCV:
	qbbs	STATE_MACHINE_RETURN, DEVICE_STATUS, RX_IGNORE_TO_EOF
	xin		RXL2_BANK0, &R2, RANGE_R2_R18
	qbeq	STATE_MACHINE_RETURN, R18.b0, 0
	jmp		FN_IOEX_MASTER

STATE_IOEX_SLAVE:
	; setup of TTS is done in event handler CMP0 event
	qbbc	STATE_IOEX_SLAVE_RCV, DEVICE_STATUS, TTS_CMP34_FLAG
	; a TTS has stated, wait for TTS to complete to swithc MII_RT ports as soon as possible into AF mode
	CALL1	FN1_IOEX_WAIT_FOR_TTS_COMPLETE
STATE_IOEX_SLAVE_RCV:
	CALL1	FN1_APPL_CHECK_IEP_EVENT
	; ignore all rcv frames
	qba		STATE_IGNORE_FRAME_TO_EOF

; placeholder for future implementations
STATE_DIAG:
STATE_ERROR:

; pru will ignore received frame until EOF has been reached.
STATE_IGNORE_FRAME_TO_EOF:
	set		DEVICE_STATUS, DEVICE_STATUS, RX_IGNORE_TO_EOF

STATE_MACHINE_RETURN:
	RET



FN_RESTART_FIRMWARE:
	; update STATS
	lbco	&TEMP_REG_3.w0, ICSS_SHARED_RAM_CONST, STATS_RETRAIN, 2
	add		TEMP_REG_3.w0, TEMP_REG_3.w0, 1
	sbco	&TEMP_REG_3.w0, ICSS_SHARED_RAM_CONST, STATS_RETRAIN, 2
	; stop other PRU, reset and restart
	ldi		TEMP_REG_2.w2, 0xfefc; clear ENABLE, SOFT_RST_N, disable SINGLE_STEP
	.if $defined(PRU0)
	ldi32	TEMP_REG_1, 0x24000
	.else
	ldi32	TEMP_REG_1, 0x22000
	.endif
	lbbo	&TEMP_REG_2.w0, TEMP_REG_1, 0, 2
	and		TEMP_REG_2.w0, TEMP_REG_2.w0, TEMP_REG_2.w2
	sbbo	&TEMP_REG_2.w0, TEMP_REG_1, 0, 2
	; clear state and slave ID
	zero	&TEMP_REG_3, 4
	sbco	&TEMP_REG_3.w0, ICSS_SHARED_RAM_CONST, SLAVE_ADDR_OFFSET, 2
	sbco	&TEMP_REG_3.w0, ICSS_SHARED_RAM_CONST, DEBUG_PRU0_SLAVE_STATE, 2
	sbco	&TEMP_REG_3.w0, ICSS_SHARED_RAM_CONST, IOEX_FRAME_MONITOR, 2
	; ENABLE
	set		TEMP_REG_2.w0, TEMP_REG_2.w0, 1
	sbbo	&TEMP_REG_2.w0, TEMP_REG_1, 0, 2
	JMP 0
