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
; 	file:   param.asm
;
; 	brief: contains the parameterization state implementation

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
	.global FN_PARAM
	.global STATE_MACHINE_RETURN

; entry point called by main state machine for PARAM state
; stores parameterization related parameters in shared memory.
FN_PARAM:
	M_XIN_L2_BANK0	PARAM_PROCESS_DATA, $sizeof(param_s)
PARAM_PROCESS_DATA:
	mov		FRAME_STATUS, R2.b3
	ldi		TEMP_REG_1.w0, PARAM_OFFSET
	sbco	&R3.b0, ICSS_SHARED_RAM_CONST, TEMP_REG_1.w0, 7*4; param without 4 byte header
	add		TEMP_REG_1.w0, TEMP_REG_1.w0, 7*4
	xin		RXL2_BANK1, &R2, RANGE_R2_R13
	sbco	&R2.b0, ICSS_SHARED_RAM_CONST, TEMP_REG_1.w0, $sizeof(param_s) - 4 - 7*4; param without 4 byte header
	set		DEVICE_STATUS, DEVICE_STATUS, RX_IGNORE_TO_EOF

	qbbc	FN_PARAM_DONE, FRAME_STATUS, 3		; ST_STATE_CHANGE
	; initiate state change switch
	ldi		PROTOCOL_STATE, LINED_STATE
	set		DEVICE_STATUS, DEVICE_STATUS, SWITCH_PORT_CONFIG


FN_PARAM_DONE:
	jmp		STATE_MACHINE_RETURN
