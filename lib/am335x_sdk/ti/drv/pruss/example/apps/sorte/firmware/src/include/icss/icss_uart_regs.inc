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
; file:   icss_uart_regs.inc
;
; brief:  {ICSS UART Module Registers}
;
; author     {Vijaya Sarathy}
;
;  version    0.1     Created
;  			  0.2	  Ported to PRU C Compiler 		{Thomas Mauer}
;
	.if ! $defined( __icss_uart_regs_inc)
	.define "1", __icss_uart_regs_inc
; NOTE: Address are in byteoffsets. Some regs (Ex: RBR/THR) alias to same word address!
ICSS_UART_RBR		.set	0x0000	; Receiver Buffer Register (Read Only)
ICSS_UART_THR		.set	0x0000	; Transmit Holding Register (Write Only)
ICSS_UART_IER		.set	0x0004	; Interrupt Enable Register
ICSS_UART_IIR		.set	0x0008	; Interrupt Identification Register (Read Only)
ICSS_UART_FCR		.set	0x0008	; FIFO Control Register (Write Only)
ICSS_UART_LCR		.set	0x000C	; Line Control Register
ICSS_UART_MCR		.set	0x0010	; Modem Control Register
ICSS_UART_LSR		.set	0x0014	; Line Status Register
ICSS_UART_MSR		.set	0x0018	; Modem Status Register
ICSS_UART_SCR		.set	0x001C	; Scratch Register
ICSS_UART_DLL		.set	0x0020	; Divisor Latch (LSB)
ICSS_UART_DLH		.set	0x0024	; Divisor Latch (MSB)
ICSS_UART_PID		.set	0x0028	; Peripheral ID Register
ICSS_UART_PID_TYPE	.set	0x002C	; Peripheral ID Type Register
ICSS_UART_EMR		.set	0x0030	; Emulation Management Register
ICSS_UART_PMR		.set	0x0030	; Power Management Register
ICSS_UART_MDR		.set	0x0034	; Mode Management Register
	.endif
