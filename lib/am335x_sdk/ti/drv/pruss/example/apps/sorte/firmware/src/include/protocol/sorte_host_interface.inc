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
; 	0.1     	Created		                Thomas Mauer
;
	.if ! $defined(__sorte_host_register_inc)
	.define	"1", __sorte_host_register_inc

; parameter in ICCS shared memory
SLAVE_INPUT_LENGTH		.set	0x0000		; .field16
SLAVE_OUTPUT_LENGTH		.set	0x0002		; .field16
MDIO_PHY_CONFIG_OFFSET	.set	0x0004		; .field32
PORT_DELAY				.set	0x0008		; .field32  measured round trip delay
LINE_DELAY_NEXT			.set	0x000C		; .field16	calculated cable line delay between this slave and next slave
LINE_DELAY_PREVIOUS		.set	0x000E		; .field16	line delay between this slave and device before
SYNC_DELAY				.set	0x0010		; .field32	delay provided in current SYNC frame
SYNC_TS					.set	0x0014		; .field32	time stamp of SYNC frame
IOEX_MASTER_SYNC_TS		.set	0x0018		; .field32	expected TS of the master frame in IOEX
SYNC_TS_AVERAGE			.set	0x001C		; .field32
SLAVE_ADDR_OFFSET		.set	0x0024		; .field16
IOEX_FRAME_RECEIVED		.set	0x0026		; .field8
;IOEX_FRAME_TRIG_SYNC	.set	0x0027		; .field8
IOEX_FRAME_MONITOR		.set	0x0028		; .field16	; todo change this to 8 bit later on
PRU0_RESET				.set	0x002a		; .field8
PRU1_RESET				.set	0x002b		; .field8

PHY_STATUS_OFFSET		.set	0x0030		; .field16

DEBUG_PRU0_SLAVE_STATE 	.set	0x0032		; .field8
DEBUG_PRU1_SLAVE_STATE 	.set	0x0033		; .field8

DEBUG_OFFSET_IN_PTR		.set	0x0034		; .field16
DEBUG_OFFSET_OUT_PTR	.set	0x0036		; .field16

DEBUG_PTO_CNT			.set	0x0038		; .field16
;DEBUG_PTO_CMP			.set	0x003A		; .field16

DEBUG_PRU0_CNT			.set	0x003C		; .field16
DEBUG_PRU1_CNT			.set	0x003E		; .field16

;DEBUG_SYNC_OFFSET		.set	0x0040		; 8x .field32 to 0x0050
DEBUG_LINE_DELAY_PREVIOUS .set 0x0040		; .field16
DEBUG_SYNC_MEASUREMENT	.set	0x0044		; .field32

DEBUG_PTO_TIMER			.set	0x0048		; .field32



STATS_CRC_ERROR_PRU0	.set	0x0050		; .field16
STATS_CRC_ERROR_PRU1	.set	0x0052		; .field16
STATS_CRC_NO_ERROR_PRU0 .set	0x0054		; .filed16
STATS_CRC_NO_ERROR_PRU1 .set	0x0056		; .filed16
STATS_RETRAIN			.set	0x0058		; .field16
STATS_DVR8711_STATUS	.set	0x005A		; .field16


IOEX_INDATA_FRAME_BUFFER	.set	0x0060
IOEX_OUTDATA_FRAME_BUFFER	.set	0x0070

DEBUG_BUFFER			.set	0x0080

PARAM_OFFSET			.set	0x0100		;

APP_RAMP_ENTRY				.set	0x0300		; .field16
APP_CYCLE_COUNT				.set	0x0302		; .field16
APP_STATE					.set	0x0304		; .field16
	; .field16
APP_STEP_COUNT				.set	0x0308		; .field32

PTO_TIMER_DELAYED_SYNC		.set	0x0310		; .field32
CMP6_TIMER_DELAYED_SYNC		.set	0x0314		; .field32

DEBUG_SYNC_FLAG				.set	0x0320		; .field16
DEBUG_SYNC_TIME				.set	0x0324		; .field32
DEBUG_SYNC_TIME_NEXT		.set	0x0328		; .field32

PROFILE_RAMP_TABLE_OFFSET 	.set 	0x0400

.endif
