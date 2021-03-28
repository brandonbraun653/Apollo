
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
	.if ! $defined(__sorte_state_define_inc)
	.define	"1", __sorte_state_define_inc

;------------------------------------------------------------------------------
;                       State Machine Configuration
;------------------------------------------------------------------------------
; default values for SORTE state machine
	.define 0, IDLE_STATE
	.define	1, DISC_STATE
	.define	2, PARAM_STATE
	.define	3, LINED_STATE
	.define	4, SYNC_STATE
	.define	5, IOEX_STATE
	.define	6, DIAG_STATE
	.define	7, ERROR_STATE
	
;------------------------------------------------------------------------------
;                       State dependent MII_RT Configuration
;------------------------------------------------------------------------------

;MII Configuration		
; Cut-through (CT)
	.define 0x55, RXCFG0_CT
	.define 0x5d, RXCFG1_CT
	.define 0x00400101, TXCFG0_CT
	.define	0x00400001, TXCFG1_CT

; Auto-forward (AF)	
	.define 0x55, RXCFG0_AF
	.define 0x5d, RXCFG1_AF
	.define 0x00400301, TXCFG0_AF
	.define	0x00400201, TXCFG1_AF
	
; Host receive (HR)
	.define 0x15, RXCFG0_HR
	.define 0x1d, RXCFG1_HR

; Host send (HS)
	.define 0x00400001, TXCFG0_HS
	.define 0x00400101, TXCFG1_HS
	
; Time triggered send (TTS)
	.define 0x00400005, TXCFG0_TTS
	.define 0x00400105, TXCFG1_TTS
	
; Peer to Peer (P2P)
	.define 0x55, RXCFG0_P2P
	.define 0x5d, RXCFG1_P2P
	.define 0x00400001, TXCFG0_P2P
	.define	0x00400101, TXCFG1_P2P
	
	.endif
	

