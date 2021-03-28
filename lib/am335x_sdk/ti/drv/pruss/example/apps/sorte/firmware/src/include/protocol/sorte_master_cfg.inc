
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
;
;	Version		Description					Author
; 	0.1     	Created		                Thomas Leyrer
;
	.if ! $defined(__sorte_master_cfg_inc)
	.define	"1", __sorte_master_cfg_inc

;------------------------------------------------------------------------------
;                       State Machine Configuration
;------------------------------------------------------------------------------
	
; default state machine parameters
DISC_REPEAT		.set		3
PARAM_REPEAT	.set		3
SYNC_REPEAT		.set		100
LINED_BURST		.set		5
LINED_CYCLE		.set		8000
	

;------------------------------------------------------------------------------
;                       Ethernet Parameters
;------------------------------------------------------------------------------

MIN_IPG			.set		100			 ; *ocp_clk -> 5ns = 500 ns
PREAMBLE_SIZE	.set		2

	
;------------------------------------------------------------------------------
;                       Application I/O Parameters
;------------------------------------------------------------------------------

IO_CYCLE_TIME	.set		25000	; in ns
MAX_INPUT_DATA	.set		8192
MAX_OUTPUT_DATA	.set		8192
T_IN			.set		100
T_OUT			.set		500
	
;------------------------------------------------------------------------------
;                       Application CNC Parameters
;------------------------------------------------------------------------------

; 1/4000 * 2^n. n = 16, 24, 32
FOUR_US_P32_CONST		.set 	1073742
FOUR_US_P24_CONST		.set	4194
FOUR_US_P16_CONST		.set	16

; 1/f[MHz]*2^16 const
; 250 kHz .. 1kHz, 100 Hz
STEP_TIME_250k_CONST	.set	262144
STEP_TIME_160k_CONST	.set	409600
STEP_TIME_100k_CONST	.set	655360
STEP_TIME_50k_CONST		.set	1310720
STEP_TIME_20k_CONST		.set	3276800
STEP_TIME_10k_CONST		.set	6553600
STEP_TIME_5k_CONST		.set	13107200
STEP_TIME_2k_CONST		.set	32768000
STEP_TIME_1k_CONST		.set	65536000
STEP_TIME_100_CONST		.set	655360000

; operating modes
MODE_BUTTON_POSITION	.set  	0
MODE_BUTTON_SPEED		.set	1
MODE_BUTTON_RAMP		.set	2
MODE_BUTTON_DANCE		.set 	3
MODE_BUTTON_MANUAL		.set 	4

; micro step setting
PROFILE_BUTTON_1		.set 	0 ; full step
PROFILE_BUTTON_2		.set 	1 ;
PROFILE_BUTTON_4		.set 	2 ;
PROFILE_BUTTON_8		.set 	3 ;
PROFILE_BUTTON_16		.set 	4 ;
PROFILE_BUTTON_32		.set 	5 ;
PROFILE_BUTTON_64		.set 	6 ;
PROFILE_BUTTON_128		.set 	7 ;
PROFILE_BUTTON_256		.set 	8 ;

; start button to select motors
START_BUTTON_OFF		.set 	0
START_BUTTON_M1			.set 	1
START_BUTTON_M2			.set 	2
START_BUTTON_M3			.set 	4
START_BUTTON_M4			.set 	8
START_BUTTON_ALL		.set 	0xf

; POSITION MODE STATES

POSITION_IDLE			.set	0
POSITION_WAIT1S			.set	1
POSITION_QUARTER_TURN	.set	2
POSITION_FULL_TURN		.set	3
POSITION_TEN_TURNS		.set 	4

; TURN states
ACCEL_STATE_INIT		.set    0
ACCEL_STATE_WAIT_INIT	.set    1
ACCEL_STATE_WAIT		.set    2
CONST_SPEED_STATE		.set	3
DEACCEL_STATE			.set 	4

;------------------------------------------------------------------------------
;                       PRU0 Data RAM defines
;------------------------------------------------------------------------------

; use first 256 bytes for configuration and status registers
SORTE_REG_INTERFACE		.set	0x0
CRC8_TABLE_OFFESET		.set 	0x100
DISCOV_RX_OFFSET		.set	0x200
OUT_DATA_OFFSET			.set 	0x700
IN_DATA_OFFSET			.set	0x800
SIN2_TBL32_OFFSET		.set    0x900
AXEL_F_TBL_OFFSET		.set	0xA00

CTRL_REG_OFFSET			.set    0x0000
STATUS_REG_OFFSET		.set 	0x0004
CTRL_PARA_OFFSET		.set 	0x0008
FIRMWARE_REV_OFFSET		.set	0x000C
INT_CTRL_OFFSET			.set	0x0010
INT_STATUS_OFFSET		.set 	0x0014
INT_CLEAR_OFFSET		.set	0x0018
; reserved				.set    0x001C
PARAM_DATA_OFFSET		.set	0x0020
; reserved     			.set 	0x0040

; port 0 stats
STATS_P0_OFFSET			.set	0x0050
CYCLE_CNT_P0_OFFSET		.set	0x0050
CRC_ERROR_P0_OFFSET		.set 	0x0054
TIMING_ERR_P0_OFFSET	.set	0x0058
FORMAT_ERR_P0_OFFSET	.set	0x005C

; port 1 stats
STATS_P1_OFFSET			.set	0x0060
CYCLE_CNT_P1_OFFSET		.set	0x0060
CRC_ERROR_P1_OFFSET		.set 	0x0064
TIMING_ERR_P1_OFFSET	.set	0x0068
FORMAT_ERR_P1_OFFSET	.set	0x006C

RETRAIN_CNT_OFFSET		.set 	0x0070
; reserved				.set  	0x0074

NET_TIMING_OFFSET		.set	0x0080

APPL_CTRL_OFFSET		.set    0x00C0
APPL_BUTTON_OFFSET		.set    0x00C0
APPL_FADER_OFFSET		.set 	0x00C4
; speed is 1/f [MHz]*2^16
APPL_SPEED_OFFSET		.set	0x00C8
APPL_FSTEP_OFFSET		.set    0x00E0
APPL_FSTEP_TIME_OFFSET	.set    0x00E4
APPL_PAUSE_OFFSET		.set    0x00E8


	.endif
