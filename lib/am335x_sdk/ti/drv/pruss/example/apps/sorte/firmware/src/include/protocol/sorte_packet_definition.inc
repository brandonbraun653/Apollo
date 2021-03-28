
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
	.if ! $defined(__sorte_packet_definition_inc)
	.define	"1", __sorte_packet_definition_inc


;------------------------------------------------------------------------------
;                       default packet format
;------------------------------------------------------------------------------
	
	.define		1,DA_SIZE			
	.define		1,SA_SIZE 		
	.define		1,TYPE_SIZE		
	.define		1,STATUS_SIZE	
	.define		DA_SIZE+SA_SIZE+TYPE_SIZE+STATUS_SIZE,HEADER_SIZE		
	.define		4,CRC32_SIZE		
	.define		2,CRC16_SIZE		
	.define		CRC32_SIZE,TRAILER_SIZE

; Destination Address - DA 0: master, 1-254: salves, 255: multicast
	.define		0,DA_MASTER		
	.define		255,DA_MC		
; Source Address - SA 0: master, 1-254, 255 - not defined
	.define		0,SA_MASTER	
; TYPE Field 
	.define		1,T_DISCOV_MC
	.define		2,T_PARAM_MC
	.define 	3,T_LD_REQ_P2P		
	.define 	4,T_LD_RESP_P2P		
	.define		5,T_SYNC_MC
	.define		6,T_OUT_MC
	.define		7,T_IN_UC
	.define		8,T_ALARM_UC
	.define		9,T_DIAG_UC
	.define		10,T_RECON_UC

; status fields used with bit manipulation commands (set, clr, qbbs, qbbc, wbs)
; bit 0
	.define		0,ST_CONTINOUS	
	.define		1,ST_LAST
	.define		0,ST_CONTLAST_BIT
; bit 1	
	.define		0,ST_PENDING		
	.define		1,ST_DONE
	.define		1, ST_PENDONE_BIT
; bit 2
	.define		0,ST_NO_ERROR		
	.define		1,ST_ERROR
	.define		2,ST_ERROR_BIT
; bit 3
	.define		0,ST_NO_STATE_CHANGE	
	.define		1,ST_STATE_CHANGE
	.define		3,ST_STATECHANGE_BIT
; bit 4-7
	.define		1,ST_DISCOV_MC
	.define		2,ST_PARAM_MC
	.define		3,ST_SYNC_MC
	.define 	4,ST_LD_REQ_P2P
	.define 	5,ST_LD_RESP_P2P
	.define		6,ST_OUT_MC
	.define		7,ST_IN_UC
	.define		8,ST_ALARM_UC
	.define		9,ST_DIAG_UC
	.define		10,ST_RECON_UC
	
;------------------------------------------------------------------------------
;                       DISCOVERY packet format
;------------------------------------------------------------------------------
discovery_s .struct
da			.byte
sa			.byte
type		.byte
status		.byte
count		.short
reserved1	.short
	.endstruct

DISCOV_P .sassign r2, discovery_s
 ; 210 header +
DISC_LENGTH		.set 1030	; with FCS, w/o preamble
DISC_WOH_LENGTH	.set 1022  ; - header, - FCS
DISC_IO_OFFSET	.set 10		; offset when I/O data length can be added

; DISC header: DA: 0xff  SA: 0x00 TYPE: 0x01  STATUS: 00
DISC_HEADER .set	0x000100FF

;------------------------------------------------------------------------------
;                       PARAM packet format
; 
; lenght: 28 bytes w/o PA and FCS
;------------------------------------------------------------------------------
param_s .struct
da				.byte
sa				.byte
type			.byte
status			.byte
cycle_time		.word
sync_cycle		.word
delay_period	.short 
delay_burst		.byte
delay_gap		.byte
delay_fwd_time	.word
ipg				.word
t_in			.word
t_out			.word
topology		.byte
diagnostics		.byte
alarm			.byte
crc_mode		.byte
	.endstruct
PARAM_P .sassign r2, param_s

PARAM_SIZE		.set 28
; IO communication cycle time in ns (32 bit)
; Make sure number of devices and data size fits into
CYCLE_TIME_1ms		.set 200000*5
CYCLE_TIME_100us	.set 20000*5
CYCLE_TIME_62_5us	.set 12500*5
CYCLE_TIME_31_25us	.set 6250*5
CYCLE_TIME_10us		.set 2000*5 		
CYCLE_TIME_4us		.set 800*5 		

;	Cycle time of time synchronization in 5 ns (32 bit)
; if _NONE is selected no extra sync packet is used during IO Exchange phase 
; values less or equal 1000 represent a factor of cycle time
; values higher than 1000 represent a dedicated cycle time for sync messages
SYNC_CYCLE_NONE			.set 0
SYNC_CYCLE_FACTOR_100	.set 100
SYNC_CYCLE_TIME_1ms 	.set 200000
SYNC_CYCLE_TIME_100ms	.set 200000*100
SYNC_CYCLE_TIME_1s		.set 200000*1000

;	Period of line delay measurements in ms (16 bit)
DELAY_PERIOD_100ms		.set 100
DELAY_PERIOD_1s			.set 1000
DELAY_PERIOD_10s		.set 10000

;	Burst count of line delay measurement (8 bit)
DELAY_BURST_CNT_1		.set 1
DELAY_BURST_CNT_5		.set 5
DELAY_BURST_CNT_8		.set 8
DELAY_BURST_CNT_10		.set 10
DELAY_BURST_CNT_16		.set 16

;	Gap time for line delay burst in ms (8 bit)
DELAY_GAP_TIME_1ms		.set 1
DELAY_GAP_TIME_8ms		.set 8
DELAY_GAP_TIME_10ms		.set 10
DELAY_GAP_TIME_100ms	.set 100

; delay forward time (16 bit) in ns from request receive to response send
DELAY_FWD_TIME_320ns	.set 320
DELAY_FWD_TIME_640ns	.set 640

; interpacket gap
IPG_960ns				.set (960/5)
IPG_200ns				.set (200/5)
IPG_260ns				.set (260/5)
IPG_500ns				.set (500/5)
IPG_640ns				.set (640/5)

;	Application input time Ti relative to cycle start time in ns (32 bit)
; these values are used to subtract from cycle time
T_IN_0					.set 0
T_IN_1us				.set 1000
T_IN_5us				.set 5000

;	Application output time To relative to cycle start time in ns (32 bit)
T_OUT_0					.set 0
T_OUT_1us				.set 1000
T_OUT_5us				.set 5000

;	Topology mode: 0 = normal, 1 = ring, 2 ring redundant (8 bit)
TOPOLOGY_NORMAL			.set 0
TOPOLOGY_RING			.set 1
TOPOLOGY_RING_REDUNDANT	.set 2

;	Diagnostic mode: 0 = part of payload, 1 = separate diagnostic packet per device. 
DIAGS_MODE_PAYLOAD		.set 0
DIAGS_MODE_PACKET		.set 1

;	Alarm mode: 0 = no immediate network reset on alarms, 1 = network reset on alarms.
ALARM_MODE_NO			.set 0
ALARM_MODE_RST			.set 1
			
;	Failing device in case parameter is not accepted by one slave. 

;   crc mode: master can select CRC algorithm for in and out packets
;            bit 0..3: out packet crc_mode
;			 bit 4..7: in packet crc_mode whihc applies for all slaves
NO_CRC					.set 0
CRC32					.set 1
CRC16					.set 2
CRC8					.set 3
CASTAGNOLI				.set 4

;------------------------------------------------------------------------------
;                       DELAY packet format
;
; lenght: 4 bytes w/o PA and w/o FCS
;------------------------------------------------------------------------------

DELAY_REQ_P				.set	0x200300ff
DELAY_RESP_P			.set 	0x300400ff
 

;------------------------------------------------------------------------------
;                       SYNC packet format
;
; lenght: 10 bytes w/o PA and w/o FCS
;------------------------------------------------------------------------------

SYNC_P				.set	0x400500ff


	.endif
