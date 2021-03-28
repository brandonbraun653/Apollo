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
;	Version		Description								Author
; 	0.1     	Created						Fabian Fischer, Karthik Bandi
; 	0.2     	Cleanup and additions		Thomas Mauer

CALL .macro func
	jal		RET_ADDR0, func
	.endm

RET .macro
	JMP		RET_ADDR0
	.endm

CALL1 .macro func
	jal		RET_ADDR1, func
	.endm

RET1 .macro
	JMP		RET_ADDR1
	.endm

CALL2 .macro func
	jal		RET_ADDR2, func
	.endm

RET2 .macro
	JMP		RET_ADDR2
	.endm


WAIT .macro delay
	lsr delay, delay, 1
l?:	sub delay,delay,1
	qblt l?,delay,0
	.endm

M_RESET_CYCLCNT .macro temp1_32, temp2_32
	.if $defined(PRU0)
	LDI32	temp1_32, ICSS_PRU0_CNTL_BASE
	.else
	LDI32 	temp1_32, ICSS_PRU1_CNTL_BASE
	.endif
	LBBO	&temp2_32, temp1_32, PRUx_CNTL_CONTROL_OFFSET, 4
	SET		temp2_32, temp2_32, 3		; enable cycle counter
	SBBO	&temp2_32, temp1_32, PRUx_CNTL_CYCLE_COUNT_OFFSET, 4	; clear cycle counter
	SBBO	&temp2_32, temp1_32, PRUx_CNTL_CONTROL_OFFSET, 4
	.endm

M_XMT_GET_FIFO_LEVEL .macro TEMP1_32, TX_CNT_16, FIFO_LEVEL_8
	.if $defined(PRU0)
	LDI32	TEMP1_32, ICSS_CNTL0_BASE
	.else
	LDI32	TEMP1_32, ICSS_CNTL1_BASE
	.endif
	LBBO	&TEMP1_32.w0, TEMP1_32, PRUx_CNTL_CYCLE_COUNT_OFFSET, 2	; read out current cycle counter
	LSR		TEMP1_32.w0, TEMP1_32.w0, 4	; cycle counter divided by 16 --> total number of bytes transmitted
	ADD		TEMP1_32.w2, TX_CNT_16, PREAMBLE_COUNT
	SUB		FIFO_LEVEL_8, TEMP1_32.w2, TEMP1_32.w0	; FIFO level = bytes pushed into TX fifo - cycle counter bytes
	.endm

M_EXTRACT_RXL2STATUS .macro
; extracts the RXL2 status field from the current frame, based on current R18
; requires that frame is in register bank (R10..13 and R18)
; places the frame status in R1.b0
	and		R1.b0, R18.b0, 0x1F
	lsr		R1.b0, R1.b0, 1
	add		R1.b0, R1.b0, &R9.b3	; &R10 - 1
	mvib	R1.b0, *R1.b0
	.endm


READ_CYCLCNT .macro dst
	lbco		&dst, PRU_CTRL_CONST, PRU_CYCLCNT, 4
	.endm

READ_IEPCNT .macro dst
	lbco		&dst, IEP_CONST, IEP_CNT, 4
	.endm


M_XIN_L2_BANK0 .macro	j_label, cnt
l?:
	qble	j_label, R18.b0, cnt
	xin		RXL2_BANK0, &R2, RANGE_R2_R18
	qba		l?
	.endm

NOP .macro
	and			r0, r0, r0
	.endm

NOP_2 .macro
	loop			l?, 2
l?:
	.endm


; DIVU5 : integer divide by 5
; n is in arg1, result is in arg3, arg2 has remainder 1..4 if not modulo 5
; arg2 and arg3 are registers used, arg1 remains unchanged
; cycles: 14/15  (70/75ns)
; instructions: 14/15
DIVU5	.macro	 arg1, arg2, arg3
	; q = (n>>1) + (n>>2)
	LSR     arg2, arg1, 1
	LSR     arg3, arg1, 2
	ADD     arg2, arg2, arg3
	; q = q + (q>>4)
	LSR     arg3, arg2, 4
	ADD		arg2, arg2, arg3
	; q = q + (q>>8)
	LSR     arg3, arg2, 8
	ADD		arg2, arg2, arg3
	; q = q + (q>>16)
	LSR     arg3, arg2, 16
	ADD		arg2, arg2, arg3
	; q = q >> 2
	LSR		arg3, arg2, 2
	; r = n - (q << 2) + q
	; arg2 has already q << 2, but LSB is not correct
	LSL 	arg2, arg3, 2
	ADD  	arg2, arg2 , arg3
	SUB     arg2, arg1, arg2
	; r is in arg2 and q in arg3
	; if arg2 >= 5 then q++
	QBGT    L_DIVU5, arg2, 5
	ADD     arg3, arg3, 1
L_DIVU5:
	.endm


SET_EDIO_OUT0	.macro
	lbco	&EDIO.STATE, c26, EDIO.OFFSET, 1
	set		EDIO.STATE, EDIO.STATE, 0
	sbco	&EDIO.STATE, c26, EDIO.OFFSET, 1
	.endm

CLR_EDIO_OUT0	.macro
	lbco	&EDIO.STATE, c26, EDIO.OFFSET, 1
	clr		EDIO.STATE, EDIO.STATE, 0
	sbco	&EDIO.STATE, c26, EDIO.OFFSET, 1
	.endm

CHANGE_EDIO_OUT0 .macro
	lbco	&EDIO.STATE, c26, EDIO.OFFSET, 1
	xor		EDIO.STATE, EDIO.STATE, (1<<0)
	sbco	&EDIO.STATE, c26, EDIO.OFFSET, 1
	.endm

SET_EDIO_OUT7	.macro
	lbco	&EDIO.STATE, c26, EDIO.OFFSET, 1
	set		EDIO.STATE, EDIO.STATE, 7
	sbco	&EDIO.STATE, c26, EDIO.OFFSET, 1
	.endm

CLR_EDIO_OUT7	.macro
	lbco	&EDIO.STATE, c26, EDIO.OFFSET, 1
	clr		EDIO.STATE, EDIO.STATE, 7
	sbco	&EDIO.STATE, c26, EDIO.OFFSET, 1
	.endm

CHANGE_EDIO_OUT7 .macro
	lbco	&EDIO.STATE, c26, EDIO.OFFSET, 1
	xor		EDIO.STATE, EDIO.STATE, (1<<7)
	sbco	&EDIO.STATE, c26, EDIO.OFFSET, 1
	.endm

