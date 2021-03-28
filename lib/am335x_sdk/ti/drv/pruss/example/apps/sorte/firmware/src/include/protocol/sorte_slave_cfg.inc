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
; 	0.1     	Created		                Thomas Leyrer
;
	.if ! $defined(__sorte_master_cfg_inc)
	.define	"1", __sorte_master_cfg_inc

;------------------------------------------------------------------------------
;                       Slave Configuration
;------------------------------------------------------------------------------
BRIDGE_DELAY_CONST	.set	360		; brige delay 360ns
IEP_RW_ACCESS_CONST	.set	15		; read/write access to IEP timer

CYCLE_TIME_10US		.set	10000	; 10 usec cuycle time value

;line delay measurment cycles
LD_SHIFT_16			.set	4
LD_SHIFT_8			.set	3

; event configuration
PRU2PRU_EVT1					.set	26
PRU2PRU_EVT2					.set	27
PRU2PRU_INTR1					.set	(0x20 | (PRU2PRU_EVT1-16))
PRU2PRU_INTR2					.set	(0x20 | (PRU2PRU_EVT2-16))

;------------------------------------------------------------------------------
;                       State Machine Configuration
;------------------------------------------------------------------------------
	
; default state machine parameters
DISC_REPEAT		.set		3
PARAM_REPEAT	.set		3
SYNC_REPEAT		.set		100
LINED_BURST		.set		5
LINED_CYCLE		.set		8000	; in ms
	

;------------------------------------------------------------------------------
;                       Ethernet Parameters
;------------------------------------------------------------------------------

	;define		MIN_IPG			100 ; *ocp_clk -> 5ns = 500 ns
	;define		PREAMBLE_SIZE	2
	;define     CRC32			0
	;define 	CRC16			1
	;define		FCS_TYPE		CRC32 
	
;------------------------------------------------------------------------------
;                       Application Parameters
;------------------------------------------------------------------------------

	;define		IOEX_CYCLE			25000	; in ns
	;define		MAX_INPUT_DATA		8192
	;define		MAX_OUTPUT_DATA		8192
	;define		T_IN				1000
	;define		T_OUT				1000

;------------------------------------------------------------------------------
;                       Application Parameters
;------------------------------------------------------------------------------
INPUT_BYTES_COUNT	.set		4
OUTPUT_BYTES_COUNT	.set		4

;------------------------------------------------------------------------------
;                       PRU0 Data RAM defines
;------------------------------------------------------------------------------

; use first 256 bytes for configuration and status registers
SORTE_REG_INTERFACE	.set	0x0
CRC8_TABLE_OFFESET	.set 	0x100
DISCOV_RX_OFFSET	.set	0x200
OUT_DATA_OFFSET		.set 	0x700
IN_DATA_OFFSET		.set	0x800

	.endif
