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
; 	file:   appl.asm
;
; 	brief:
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
	;.global STATE_MACHINE_RETURN
	.global FN1_APPL_CHECK_IEP_EVENT

;***********************************
; Application - check for IEP event
;***********************************
FN1_APPL_CHECK_IEP_EVENT:
APPL_CHECK_IEP_EVENT:
    ;----------[CHECK COMPARE 0-1-6-7 FLAG REGISTERS]----------|
    qbbs COMPARE_6, SYNC_PULSE_STATUS, IEP_CMP6_FLAG	; BRANCH IF CMP6 BIT IS SET
    qbbs COMPARE_0, SYNC_PULSE_STATUS, IEP_CMP0_FLAG	; BRANCH IF CMP0 BIT IS SET
    qbbs COMPARE_7, SYNC_PULSE_STATUS, IEP_CMP7_FLAG	; BRANCH IF CMP7 BIT IS SET
    ;----------------------------------------------------------|
APPL_CHECK_IEP_EVENT_DONE:
    RET1

;***********************************
; COMPARE_0 - IEP wrap-around
;***********************************
COMPARE_0:
    ;-----------------[CLEAR COMPARE-0 FLAG BIT]---------------|
    clr		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, IEP_CMP0_FLAG
    qbbc	CMP0_NO_DELAYED_CMP6_ACTIVATED, SYNC_PULSE_STATUS, DELAYED_CMP6_ACTIVATED_FLAG
   	clr		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, DELAYED_CMP6_ACTIVATED_FLAG
	qba		CMP0_IS_ACTIVE_PULSE_FLAG_SET
CMP0_NO_DELAYED_CMP6_ACTIVATED:
	qbbc	CMP0_IS_ACTIVE_PULSE_FLAG_SET, SYNC_PULSE_STATUS, PENDING_PULSE_FLAG
    ;-----------------[ENABLE COMPARE-6]-----------------------|
    lbco 	&TEMP_REG_1.w0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 2
    set 	TEMP_REG_1.w0, TEMP_REG_1.w0, 6+1; SET BIT7 FOR COMPARE6 ENABLE
    sbco 	&TEMP_REG_1.w0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 2;ENABLE COMPARE 6

CMP0_IS_ACTIVE_PULSE_FLAG_SET:
	qbbc	CMP0_NOTHING_TO_DO, SYNC_PULSE_STATUS, ACTIVE_PULSE_FLAG
	qbbs	CMP0_NOTHING_TO_DO, SYNC_PULSE_STATUS, PREV_SYNC_PULSE_OVERLAP
	qbbc	GENERATE_DELAYED_SYNC_WITH_NO_OVERLAP, SYNC_PULSE_STATUS, SYNC_PULSE_OVERLAP
	qba		GENERATE_DELAYED_SYNC_WITH_OVERLAP

CMP0_NOTHING_TO_DO:
 	qba APPL_CHECK_IEP_EVENT

;***********************************
; COMPARE_6 - e/o sync0 pulse
;***********************************
COMPARE_6:
	;CHANGE_EDIO_OUT0
    ;---------[CLEAR COMPARE-6 AND COMPARE-1 FLAG BIT]---------|
    clr	SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, IEP_CMP6_FLAG
    ;----------------------------------------------------------|
    ;-----------------[DISABLE COMPARE-1+6]----------------------|
    lbco &TEMP_REG_1.w0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 2
    clr TEMP_REG_1.w0, TEMP_REG_1.w0, 1+1; CLEAR BIT2 FOR COMPARE1 ENABLE
    clr TEMP_REG_1.w0, TEMP_REG_1.w0, 6+1; CLEAR BIT7 FOR COMPARE6 ENABLE
    sbco &TEMP_REG_1.w0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 2; DISABLE COMPARE 6
    ;----------------------------------------------------------|

;RESTART_SYNC:
    ;----------------------[DISABLE SYNC GENERATION]-----------|
    ldi TEMP_REG_3.w0, 0x02; DISABLE SYNC
    ldi TEMP_REG_4.w0, (ICSS_IEP_SYNC_BLK_INDEX << 8) + ICSS_IEP_SYNC_CTRL_REG
    sbco &TEMP_REG_3.w0, ICSS_IEP_CONST, TEMP_REG_4.w0, 2; DISABLE SYNC
    ;----------------------------------------------------------|
    ;-----------------------[ENABLE SYNC GENERATION]-----------|
    ldi TEMP_REG_3.w0, 0x03
    sbco &TEMP_REG_3.w0, ICSS_IEP_CONST, TEMP_REG_4.w0, 2; ENABLE SYNC
    ;----------------------------------------------------------|
    ;---------------[MAKE PENDING PULSE LOW]-------------------|
    clr SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, PENDING_PULSE_FLAG
    ;----------------------------------------------------------|

	qbbc APPL_CHECK_IEP_EVENT, SYNC_PULSE_STATUS, ACTIVE_PULSE_FLAG

	qbbs GENERATE_DELAYED_SYNC_WITH_OVERLAP, SYNC_PULSE_STATUS, PREV_SYNC_PULSE_OVERLAP
    qba APPL_CHECK_IEP_EVENT


;***********************************
; COMPARE_7 - New I/O data available
;***********************************
COMPARE_7:
    ;CHANGE_EDIO_OUT0
    qbbc	CMP7_NO_ACTIVE_PULSE_FLAG, SYNC_PULSE_STATUS, ACTIVE_PULSE_FLAG
	;CHANGE_EDIO_OUT0

CMP7_NO_ACTIVE_PULSE_FLAG:
    ;----------------------[CLEAR COMPARE-7 STATUS BIT]--------|
    clr	SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, IEP_CMP7_FLAG
    ;----------------------------------------------------------|


;CMP7_LOAD_IOEX_DATA:
	; load pulse time
	;CHANGE_EDIO_OUT0

    lbco	&TEMP_REG_1.w0, ICSS_SHARED_RAM_CONST, IOEX_OUTDATA_FRAME_BUFFER, 2

    ; monitoring the last PTO values
    ;mov		R2.w0, TEMP_REG_1.w0
    ;lbco	&R2.w2, PRU1_DMEM_CONST, 0, 30
    ;sbco	&R2.w0, PRU1_DMEM_CONST, 0, 32
    ;qbne	CMP7_LOAD_DATA_DONE, IO_CYCLE_CNT, 4
    ;sbco	&R2.w0, PRU1_DMEM_CONST, 32, 32

CMP7_LOAD_DATA_DONE:
	; check if a pulse needs to get generated in the next cycle
    qbeq	CMP7_GEN_NO_PULSE, TEMP_REG_1.w0, 0
    ldi		TEMP_REG_2.w0, 0x7FFF
    qbne	CMP7_SET_PULSE_ACTIVE, TEMP_REG_1.w0, TEMP_REG_2.w0
CMP7_GEN_NO_PULSE:
	; need to clear the PREV_SYNC_PULSE_OVERLAP flag to allow CMP0 to set the next pulse
	clr		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, PREV_SYNC_PULSE_OVERLAP

	CHANGE_EDIO_OUT0
	CHANGE_EDIO_OUT0

	qba		APPL_CHECK_IEP_EVENT

CMP7_SET_PULSE_ACTIVE:
	;qble	CMP7_DEBUG_1, TEMP_REG_1.w0, 50
	;add		TEMP_REG_1.w0, TEMP_REG_1.w0, 150
;CMP7_DEBUG_1:
	;ldi		TEMP_REG_1.w2, 3990-50
	;qbge	CMP7_DEBUG_2, TEMP_REG_1.w0, TEMP_REG_1.w2
	;sub		TEMP_REG_1.w0, TEMP_REG_1.w0, 150
	;CHANGE_EDIO_OUT0
;CMP7_DEBUG_2:
    ;-------------------[UPDATE SYNC PULSE STATUS]-------------|
    set 	SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, ACTIVE_PULSE_FLAG;
	SET_EDIO_OUT0
	;CHANGE_EDIO_OUT0
	mov		PTO_TIMER, TEMP_REG_1.w0

    ; the previous pulse is not yet completed
    ; check if the new pulse has a cycle overlap
    ldi		TEMP_REG_3.w0, 2000
    ldi		TEMP_REG_3.w2, 3390
    add		TEMP_REG_1, TEMP_REG_3.w0, PTO_TIMER
    clr		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, SYNC_PULSE_OVERLAP
    mov		NEW_CMP6_VALUE, TEMP_REG_1
    qbgt	CMP7_NO_OVERLAP, TEMP_REG_1, TEMP_REG_3.w2
	set		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, SYNC_PULSE_OVERLAP
	sub 	NEW_CMP6_VALUE, TEMP_REG_1, TEMP_REG_3.w2
CMP7_NO_OVERLAP:
	; NEW_CMP_6_VALUE boundary check
	qbne	CMP7_NEW_CMP6_NOT_ZERO, NEW_CMP6_VALUE, 0
	add		NEW_CMP6_VALUE, NEW_CMP6_VALUE, 10
CMP7_NEW_CMP6_NOT_ZERO:
	ldi		TEMP_REG_1.w0, 3995
	qbge	CMP7_NEW_CMP6_NOT_3990, NEW_CMP6_VALUE, TEMP_REG_1.w0
CMP7_NEW_CMP6_NOT_3990:

    ; check if a pulse is still pending
    qbbc 	CMP7_CALCULTATE_CMP6_FOR_IMMEDIATE, SYNC_PULSE_STATUS, PENDING_PULSE_FLAG
 	; there is a pulse pending
    ; store the new PTO_TIMER value in memory to prevent that next master frame overwrites the value
    ;ldi		TEMP_REG_2.w0, PTO_TIMER_DELAYED_SYNC
	;sbco	&PTO_TIMER, ICSS_SHARED_RAM_CONST, TEMP_REG_2.w0, 4
    qba		APPL_CHECK_IEP_EVENT

CMP7_CALCULTATE_CMP6_FOR_IMMEDIATE:
	;CHANGE_EDIO_OUT0
    clr		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, PREV_SYNC_PULSE_OVERLAP
    qbbc 	CMP7_UPDATE_PREV_SYNC_PULSE_OVERLAP, SYNC_PULSE_STATUS, SYNC_PULSE_OVERLAP
    set		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, PREV_SYNC_PULSE_OVERLAP
    set		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, DELAYED_CMP6_ACTIVATED_FLAG
CMP7_UPDATE_PREV_SYNC_PULSE_OVERLAP:
    ;-----------------[FIND START TIME FOR SYNC PULSE]---------|
    zero &TEMP_REG_4, 8; RE-INITIALISE TEMP_REG_4 and TEMP_REG_4 to 0
    add TEMP_REG_4, PTO_TIMER, 5; ADJUST START TIME SINCE CMP1 VALUE IS 3995
    DIVU5 TEMP_REG_4, TEMP_REG_1, TEMP_REG_5; DIVIDE BY 5 AND LATER SUBTRACT BY 1
    sub TEMP_REG_5, TEMP_REG_5, 1; CALCULATE START TIME VALUE TO BE COPIED TO START SYNC REGISTER
    ;--------------[COPY VALUE TO START SYNC REGISTER]---------|
    ldi TEMP_REG_2.w0, (ICSS_IEP_SYNC_BLK_INDEX << 8) + ICSS_IEP_SYNC_START_REG
    sbco &TEMP_REG_5.w0, ICSS_IEP_CONST, TEMP_REG_2.w0, 2
;IMMEDIATE_SYNC_PRG:;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ; program CMP6
    sbco &NEW_CMP6_VALUE, ICSS_IEP_CONST, ICSS_IEP_CMP6_REG, 4
    ;----------------------------------------------------------|
	; progrm the SYNC0 pulse
    ;-------------[COPY VALUE TO COMPARE1 REGISTER]------------|
    ldi TEMP_REG_1, 3990
    sbco &TEMP_REG_1, ICSS_IEP_CONST, ICSS_IEP_CMP1_REG, 4
    ;----------------------------------------------------------|
    lbco &TEMP_REG_1.w0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 2
    ; ToDo Can we enable CMP1 globally?
    set TEMP_REG_1.w0, TEMP_REG_1.w0, 1+1; COMPARE1 ENABLE
    sbco &TEMP_REG_1.w0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 2
    clr SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, ACTIVE_PULSE_FLAG;
    CLR_EDIO_OUT0
    ;CHANGE_EDIO_OUT0
    set SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, PENDING_PULSE_FLAG
    qba APPL_CHECK_IEP_EVENT


; called by CMP0
GENERATE_DELAYED_SYNC_WITH_NO_OVERLAP:;///////////////////////////////////////////////////////////////////////////////////////////////////////////
	;CHANGE_EDIO_OUT0

	clr		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, PREV_SYNC_PULSE_OVERLAP
	qbbc	GEN_DELAYED_SYNC_NO_OVERLAP, SYNC_PULSE_STATUS, SYNC_PULSE_OVERLAP
	set		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, PREV_SYNC_PULSE_OVERLAP
GEN_DELAYED_SYNC_NO_OVERLAP:
    ;------------[COPY VALUE TO COMPARE6 REGISTER]-------------|
    sbco 	&NEW_CMP6_VALUE.w0, ICSS_IEP_CONST, ICSS_IEP_CMP6_REG, 2
    ;-------------[COPY VALUE TO COMPARE1 REGISTER]------------|
    sbco 	&PTO_TIMER, ICSS_IEP_CONST, ICSS_IEP_CMP1_REG, 4
    ;--------------[COPY VALUE TO START SYNC REGISTER]---------|
    ldi 	TEMP_REG_3, 0
    ldi 	TEMP_REG_2.w0, (ICSS_IEP_SYNC_BLK_INDEX << 8) + ICSS_IEP_SYNC_START_REG
    sbco 	&TEMP_REG_3.w0, ICSS_IEP_CONST, TEMP_REG_2.w0, 2
    ;-----------------[ENABLE COMPARE-6]-----------------------|
    lbco 	&TEMP_REG_1.w0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 2
	qbbs	GEN_DELAYED_SYN_NO_OVERLAP_NO_CMP6, SYNC_PULSE_STATUS, SYNC_PULSE_OVERLAP
    set 	TEMP_REG_1.w0, TEMP_REG_1.w0, 6+1; SET BIT7 FOR COMPARE6 ENABLE
GEN_DELAYED_SYN_NO_OVERLAP_NO_CMP6:
    set 	TEMP_REG_1.w0, TEMP_REG_1.w0, 1+1; SET BIT1 FOR COMPARE1 ENABLE
    sbco 	&TEMP_REG_1.w0, ICSS_IEP_CONST, ICSS_IEP_CMP_CFG_REG, 2
    ;----------------------------------------------------------|
    clr 	SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, ACTIVE_PULSE_FLAG
    CLR_EDIO_OUT0
    set		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, PENDING_PULSE_FLAG
    qba 	APPL_CHECK_IEP_EVENT

; called by CMP6
GENERATE_DELAYED_SYNC_WITH_OVERLAP:
	;CHANGE_EDIO_OUT0
	;set		SYNC_PULSE_STATUS, SYNC_PULSE_STATUS, DELAYED_CMP6_ACTIVATED_FLAG
	qba		GENERATE_DELAYED_SYNC_WITH_NO_OVERLAP

