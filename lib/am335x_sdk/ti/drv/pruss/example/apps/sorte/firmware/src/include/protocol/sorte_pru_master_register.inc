
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
;	Version		Description					Author
; 	0.1     	Created					Thomas Mauer, Thomas Leyrer
;

; EDIO real-time signal for timing measurement and debug
EDIO_DESC		.struct
STATE				.field 8
OFFSET				.field 16
				.endstruct

	.asg		R0, SYNTAX1
	.asg		R1, SYNTAX2
	.asg		R2, RX_L2_DATA
	.asg		R18.b0, RX_L2_PTR
	.asg		R20.b0, PROTOCOL_STATE
	.asg		R20.b1, PROTOCOL_STATE_CNT
	.asg		R20.w2, DEVICE_STATUS
	.asg		R21.w0,	IN_PTR
	.asg		R21.w2, OUT_PTR
	.asg		R22.w0, TX_BYTE_CNT
	.asg		R22.w2, RX_BYTE_CNT
	.asg		R23.b0, SLAVE_ADDR
	.asg		R23.b1, FRAME_STATUS
	.asg		R23.w2, OFFSET_IN_PTR
    .asg		R24.w0,	OFFSET_OUT_PTR
	.asg		R24.b2, SYNC_STATE_REG
EDIO	.sassign R24.b3, EDIO_DESC

	.asg		R20, PRU_CC_REG
	.asg		R20, IO_CYCLE_CNT
	.asg 		R29.w0, RET_ADDR0
	.asg		R29.w2, RET_ADDR1

; temp register are overwritten by XIN of complete RX_L2 which spans over R2-R18	
    .asg		R19, TEMP_REG_6
    .asg		R18, TEMP_REG_5 	; colides with RX_L2 write pointer
	.asg		R17, TEMP_REG_4
	.asg		R16, TEMP_REG_3
	.asg		R15, TEMP_REG_2
	.asg		R14, TEMP_REG_1



; bit definition of DEVICE_STATUS for SLAVE device
LAST_DEVICE_FLAG		.set	0
PRU_MASTER_PORT_FLAG	.set	1		;1-receives Master telegrams, 0-receives revers path telegrams
RX_IGNORE_TO_EOF		.set	2
SWITCH_PORT_CONFIG		.set	3
NEW_SYNC_FRAME_FLAG		.set	4
NEW_CYCLE_TIME_FLAG		.set	5		; set when a new cycle time needs to programmed into CMP0
SETUP_NEW_TTS_FLAG		.set	6
TTS_ACTIVE_FLAG			.set	7		; ToDo: check if this flag can be removed
TTS_CMP34_FLAG			.set	8
NEW_IOEX_DATA_FLAG		.set	9
RX_FRAME_CRC_ERROR		.set	10
DEBUG_TX_FIFO_UNDERFLOW .set	11
IOEX_MASTER_FRAME_EOF	.set	12

; scratch pad definition for SLAVE devcie
SHIFT_LINE_DELAY_TRIGGER	.set	0		; location R14.b0, BANK0
