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
; 	file:   discovery.asm
;
; 	brief:  contains the discovery state implementation
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
	.global FN_DISCOVERY
	.global STATE_MACHINE_RETURN

; entry point called by main state machine for DISCOVERY state
FN_DISCOVERY:
	; DISCOVERY header parsing
	; set pointer to first byte of the frame
	ldi		R1.b0, &R2.b0

; DA (1)
	M_XIN_L2_BANK0	DISC_DA, 1
DISC_DA:
	mvib	R30.b0, *R1.b0++
	M_PUSH_BYTE

; SA (2)
	M_XIN_L2_BANK0	DISC_SA, 2
DISC_SA:
	mvib	R30.b0, *R1.b0++
	M_PUSH_BYTE

; TYPE (3)
	M_XIN_L2_BANK0	DISC_TYPE, 3
DISC_TYPE:
	mvib	R30.b0, *R1.b0++
	M_PUSH_BYTE

; Status (4)
	M_XIN_L2_BANK0	DISC_STATUS, 4
DISC_STATUS:
	mvib	R30.b0, *R1.b0++
	qbbc	DISC_STATUS_2, DEVICE_STATUS, LAST_DEVICE_FLAG
	set		R30.b0, R30.b0, 0		; bit 0 set to ST_LAST
DISC_STATUS_2:
	qbbc	DISC_STATUS_3, DEVICE_STATUS, RX_FRAME_CRC_ERROR
	set		R30.b0, R30.b0, 2 	; bit 2 ST_ERROR_BIT
	clr		DEVICE_STATUS, DEVICE_STATUS, RX_FRAME_CRC_ERROR
DISC_STATUS_3:
	M_PUSH_BYTE
	; store frame status in registers
	mov		FRAME_STATUS, R30.b0
	; State change flag set?
	; check bit 3 of status field to determine if state change should occur
	qbbc	DISC_STATUS_4, R30.b0, 3		; ST_STATE_CHANGE
	; initiate state change switch
	ldi		PROTOCOL_STATE, PARAM_STATE
	set		DEVICE_STATUS, DEVICE_STATUS, SWITCH_PORT_CONFIG
DISC_STATUS_4:

; Slave Count (5, 6)
	M_XIN_L2_BANK0	DISC_SLV_CNT, 6
DISC_SLV_CNT:
	add		R3.w0, R3.w0, 1
	mviw	R30.w0, *R1.b0++
	M_PUSH_WORD
	mov		SLAVE_ADDR, R3.w0	; each slave device will store its address in shared memory.
	sbco	&R3.w0, ICSS_SHARED_RAM_CONST, SLAVE_ADDR_OFFSET, 2

; OFFSET_IN_PTR (7,8)
	M_XIN_L2_BANK0	DISC_OFFSET_IN_PTR, 8
DISC_OFFSET_IN_PTR:
	add		R30.w0, R3.w2, INPUT_BYTES_COUNT
	M_PUSH_WORD
	mov		OFFSET_IN_PTR, R3.w2
	sbco	&OFFSET_IN_PTR, ICSS_SHARED_RAM_CONST, DEBUG_OFFSET_IN_PTR, 2

; OFFSET_OUT_PTR (9,10)
	M_XIN_L2_BANK0	DISC_OFFSET_OUT_PTR, 10
DISC_OFFSET_OUT_PTR:
	add		R30.w0, R3.w2, OUTPUT_BYTES_COUNT
	M_PUSH_WORD
	mov		OFFSET_OUT_PTR, R4.w0
	sbco	&OFFSET_OUT_PTR, ICSS_SHARED_RAM_CONST, DEBUG_OFFSET_OUT_PTR, 2

; discovery payload (11..DISC_LENGTH)
	ldi		R0.w2, DISC_IO_OFFSET	; read pointer
	ldi		R0.w0, DISC_LENGTH-4	; frame length without CRC
	M_XIN_L2_BANK0	DISC_PAYLOAD, 11
DISC_PAYLOAD:
	; check if slave needs to add input/output data
	sub		R1.w2, SLAVE_ADDR, 1
	lsl		R1.w2, R1.w2, 2
	add		R1.w2, R1.w2, DISC_IO_OFFSET
	qbeq	DISC_INSERT_INPUT_OUTPUT, R0.w2, R1.w2
	; push new byte
DISC_PAYLOAD_REFRESH_L2:
	xin		RXL2_BANK0, &R2.b0, RANGE_R2_R18
	qbbc	DISC_PAYLOAD_CHECK_NEW_DATA, R0.w2, 5
	xin		RXL2_BANK1, &R2.b0, RANGE_R2_R18
DISC_PAYLOAD_CHECK_NEW_DATA:
	and		R1.b0, R0.b2, 0x3F
	qbeq	DISC_PAYLOAD_REFRESH_L2, R1.b0, R18.b0
	; new data available, push to TX FIFO
	and		R1.b0, R1.b0, 0x1F
	add		R1.b0, R1.b0, &R2.b0
	mvib	R30.b0, *R1.b0
	M_PUSH_BYTE
	add		R0.w2, R0.w2, 1
DISC_PAYLOAD_CHECK_EOF:
	qbgt	DISC_PAYLOAD, R0.w2, R0.w0
	; reach e/o frame, now push CRC + EOF
	M_CMD16 (D_PUSH_CRC_MSWORD_CMD | D_PUSH_CRC_LSWORD_CMD | D_TX_EOF)
	; Those NOPs are needed, otherwise sometimes one additonal byte is transmitted.
	NOP
	NOP
	NOP
	NOP
	; set ignore frame and let the RX_EOF event handler check the CRC
	set		DEVICE_STATUS, DEVICE_STATUS, RX_IGNORE_TO_EOF
DISC_DEBUG1:
	jmp		STATE_MACHINE_RETURN

DISC_INSERT_INPUT_OUTPUT:
	; 4 next byte are slaves input/output length or offset
	ldi		R30.w0, INPUT_BYTES_COUNT
	M_PUSH_WORD
	add		R0.w2, R0.w2, 4
	NOP
	ldi		R30.w0, OUTPUT_BYTES_COUNT
	M_PUSH_WORD
	; now wait until read and write counter match
	and		R1.b0, R0.b2, 0x3F
DISC_INSERT_I0_WAIT:
	xin		RXL2_BANK0, &R18.b0, 1
	qbne	DISC_INSERT_I0_WAIT, R1.b0, R18.b0
	qba		DISC_PAYLOAD_CHECK_EOF

