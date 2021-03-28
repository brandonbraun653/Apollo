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
; 	file:   firm_main.asm
;
; 	brief:
;
;	Version		Description								Author
; 	0.1     	Created									Thomas Mauer

;include section
	.include "../include/macros/macros.inc"
	.include "../include/macros/utils.inc"
	.include "../include/icss/icss_regs.inc"
	.include "../include/protocol/sorte_pru_slave_register.inc"
	.include "../include/protocol/sorte_state_define.inc"
	.include "../include/protocol/sorte_slave_cfg.inc"
	.include "../include/protocol/sorte_host_interface.inc"
	.include "firmware_version.inc"

;define, set and asg section


;CCS specific settings
	.retain 	; Required for building .out with assembly file
	.retainrefs ; Required for building .out with assembly file
	.global FN_STATE_MACHINE
	.global FN_EVENT_HANDLER
	.sect	".text:firm_main"
	.global	firm_main


;********
;* FIRM_MAIN *
;********
firm_main:
	; PRU init
	; clear R0 to R30
	zero	&R0, 124
	;clear scratch pad banks
	xout	SCRATCH_BANK0, &R0, 120
	xout	SCRATCH_BANK1, &R0, 120
	xout	SCRATCH_BANK2, &R0, 120

;init:
	; reset RX- and TX-FIFO and clear TX errors
	M_CMD16 (D_RESET_RXFIFO | D_RX_ERROR_CLEAR | D_RESET_TXFIFO)
	; set R30 mask to take data from R30.w0 (TX path)
	M_SET_DATA_MASK16 0xFFFF
	; generate MDIO event on both ports to update port status
	ldi32	TEMP_REG_1, 0x00200200	; Set MDIO_MII_LINK[1] and MDIO_MII_LINK[0] bit
	ldi		TEMP_REG_2.w0, ICSS_INTC_SRSR1
	sbco	&TEMP_REG_1, ICSS_INTC_CONST, TEMP_REG_2.w0, 4

	
	; IEP configuration
	; set IEP count to 0
        .if $isdefed("ICSS_REV1")
            zero  &TEMP_REG_1, 4 ; set to 0 by RX preamble count
            sbco  &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 4
        .endif
        .if $isdefed("ICSS_REV2")
	    zero &TEMP_REG_1, 8 ; set to 0 by RX preamble count
	   sbco  &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_COUNT_REG, 8
        .endif

	; disable wrap-around CMP[0] event
	sbco	&TEMP_REG_1.w0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 2

;SET_SYNC:
	; set SYNC0 pulse width to 2us
	ldi		TEMP_REG_1.w0, 399
	ldi		TEMP_REG_1.w2, (ICSS_IEP_SYNC_BLK_INDEX << 8) + ICSS_IEP_SYNC_PWIDTH_REG
	sbco	&TEMP_REG_1.w0, ICSS_IEP_CONST, TEMP_REG_1.w2, 2
	.if $defined(remove)
	; set activation start time 3000ns, which is cmp0 wrap around
	ldi		TEMP_REG_1.w0, 599	; 3000/5-1
	ldi		TEMP_REG_1.w2, (ICSS_IEP_SYNC_BLK_INDEX << 8) + ICSS_IEP_SYNC_START_REG
	sbco	&TEMP_REG_1.w0, ICSS_IEP_CONST, TEMP_REG_1.w2, 2
	ldi32	TEMP_REG_1, 1000		; SYNC0 should output
	sbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP1_REG, 4
	lbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4
	set		TEMP_REG_1, TEMP_REG_1, (1+1)	; CMP[1]
	sbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 4
	.endif

	; set DEBUG_PTO_TIMER for testing
	ldi		TEMP_REG_1, 500
	sbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST, DEBUG_PTO_TIMER, 4
	;ldi		TEMP_REG_1, 0xa28		;2600
	;ldi		TEMP_REG_1, 1000	;
	ldi		TEMP_REG_1, 2000		; set CMP7 trigger to >=2000
	sbco	&TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP7_REG, 4
	;ldi		TEMP_REG_1.w0, 250
	;sbco	&TEMP_REG_1, ICSS_SHARED_RAM_CONST, DEBUG_PTO_CMP, 2

	;EDIO debug
	ldi		EDIO.OFFSET, 0x310

;endless loop to process state machine and events/interrupts. 
control_loop:
	; Receive task
	CALL	FN_STATE_MACHINE
	; event handler
	CALL	FN_EVENT_HANDLER
	qba		control_loop


firmware_version:
	.if $defined(PRU0)
	.word 0x00		; PRU0
	.else
	.word 0x01		; PRU1
	.endif

	.word   ICSS_FIRMWARE_RELEASE_1
	.word   ICSS_FIRMWARE_RELEASE_2
