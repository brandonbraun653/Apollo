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
; file:   icss_macros.inc
;
; brief:  Implements the EtherCAT common macros & defines.
;
;
;  author     Kanad Kanhere
;
;  version    0.1     Created
;  version    0.2     Ported to PRU C Compiler {Thomas Mauer}

	.if ! $defined (__icss_macros_inc)
	.define "1", __icss_macros_inc

	.asg	R30.w0,	TX_DATA_WORD
	.asg	R30.b0,	TX_DATA_BYTE
	.asg	R30.w2,	TX_DATA_WORD_MASK

	;------------------------------------
    ; Macros
    ;------------------------------------

        ;-----------------------------------
        ; Macro Name: M_POLL_WORD_RDY
        ; Description: Polls for word ready or EOF or RX_ERR.
        ; Input Parameters: Label if EOF, Label if RX_ERR
        ; Output Parameters: none
        ;-----------------------------------
		;** The word ready check is done twice to ensure
		;** minimum delay between a word to be ready and
		;** word ready detection. Also word ready should
		;** be checked before EOF to ensure it has
		;** highest priority to handle scenarios like
		;** RX FIFO having lot of unprocessed words
		;** at the end of the frame.
M_POLL_WORD_RDY .macro EOF_LABEL, RX_ERR_LABEL
			;QBBS WORD_RDY, R31, D_WORD_READY_FLAG_BITNUM
WORD_CHECK_EOF?:
	.if $defined(NO_RX_EOF_ERROR_FLAG_BITNUM)
			QBBS EOF_LABEL, R31, D_EOF_FLAG_BITNUM
			QBBS RX_ERR_LABEL, R31, D_RX_ERROR_FLAG_BITNUM
	.else
			QBBS EOF_LABEL, R31, D_RX_EOF_ERROR_FLAG_BITNUM
	.endif
			QBBC WORD_CHECK_EOF?, R31, D_WORD_READY_FLAG_BITNUM
WORD_RDY?:
    .endm

        ;-----------------------------------
        ; Macro Name: M_POLL_BYTE_RDY
        ; Description: Polls for byte ready or EOF or RX_ERR
        ; Input Parameters: Label if EOF, Label if RX_ERR
        ; Output Parameters: none
        ;-----------------------------------
		;** The byte ready check is done twice to ensure
		;** minimum delay between a byte to be ready and
		;** byte ready detection. Also byte ready should
		;** be checked before EOF to ensure it has
		;** highest priority to handle scenarios like
		;** RX FIFO having lot of unprocessed bytes
		;** at the end of the frame.
M_POLL_BYTE_RDY .macro  EOF_LABEL, RX_ERR_LABEL
            ;QBBS BYTE_RDY, R31, D_BYTE_READY_FLAG_BITNUM
BYTE_CHECK_EOF?:
	.if $defined(NO_RX_EOF_ERROR_FLAG_BITNUM)
			QBBS EOF_LABEL, R31 ,D_EOF_FLAG_BITNUM
			QBBS RX_ERR_LABEL, R31, D_RX_ERROR_FLAG_BITNUM
	.else
			QBBS EOF_LABEL, R31, D_RX_EOF_ERROR_FLAG_BITNUM
	.endif
			QBBC BYTE_CHECK_EOF?, R31, D_BYTE_READY_FLAG_BITNUM
BYTE_RDY?:
		.endm
    ;-----------------------------------

        ;-----------------------------------
        ; Macro Name: M_CMD16
        ; Description: Issue the given command.
        ; Input Parameters: 16bit command value
        ; Output Parameters: none
        ;-----------------------------------
M_CMD16 .macro cmd_val16
        	LDI R31.w2, cmd_val16
        .endm
        ;-----------------------------------

        ;-----------------------------------
        ; Macro Name: M_SET_DATA_MASK16
        ; Description: Sets the given mask in R30.w2.
        ; Input Parameters: 16bit mask value
        ; Output Parameters: none
        ;-----------------------------------
M_SET_DATA_MASK16 .macro mask_val16
        	LDI R30.w2, mask_val16
        .endm
        ;-----------------------------------

        ;-----------------------------------
        ; Macro Name: M_SET_CMD
        ; Description: Sets the given command R31.w2.
        ; Input Parameters: 16bit mask value
        ; Output Parameters: none
        ;-----------------------------------
M_SET_CMD .macro cmd_val16
        	LDI R31.w2, cmd_val16
        .endm

        ; Macro Name: M_POP_BYTE
        ; Description: Pop a byte from RX FIFO.
        ; Input Parameters: none
        ; Output Parameters: none
        ;-----------------------------------
M_POP_BYTE .macro
        	M_CMD16 D_POP_BYTE_CMD
        .endm

        ;-----------------------------------
        ; Macro Name: M_POP_WORD
        ; Description: Pop a word from RX FIFO.
        ; Input Parameters: none
        ; Output Parameters: none
        ;-----------------------------------
M_POP_WORD .macro
        	M_CMD16 D_POP_WORD_CMD
        .endm

        ;-----------------------------------
        ; Macro Name: M_PUSH_BYTE
        ; Description: Push a byte into TX fifo.
        ; Input Parameters: none
        ; Output Parameters: none
        ;-----------------------------------
M_PUSH_BYTE .macro
        	M_CMD16 D_PUSH_BYTE_CMD
        .endm

        ;-----------------------------------
        ; Macro Name: M_PUSH_WORD
        ; Description: Push a word into TX fifo.
        ; Input Parameters: none
        ; Output Parameters: none
        ;-----------------------------------
M_PUSH_WORD .macro
        	M_CMD16 D_PUSH_WORD_CMD
        .endm

        ;-----------------------------------
        ; Macro Name: M_PUSH_N_POP_BYTE
        ; Description: Push a byte into TX fifo and pop byte from RX FIFO.
        ; Input Parameters: none
        ; Output Parameters: none
        ;-----------------------------------
M_PUSH_N_POP_BYTE .macro
        	M_CMD16 D_PUSH_N_POP_BYTE_CMD
        .endm

        ;-----------------------------------
        ; Macro Name: M_PUSH_N_POP_WORD
        ; Description: Push a word into TX fifo and pop word from RX FIFO.
        ; Input Parameters: none
        ; Output Parameters: none
        ;-----------------------------------
M_PUSH_N_POP_WORD .macro
            M_CMD16 D_PUSH_N_POP_WORD_CMD
        .endm

        ;-----------------------------------
        ; Macro Name: M_PUSH_CRC_MSWORD
        ; Description: Push 31:16 bits of CRC into TX FIFO.
        ; Input Parameters: none
        ; Output Parameters: none
        ;-----------------------------------
M_PUSH_CRC_MSWORD .macro
            M_CMD16 D_PUSH_CRC_MSWORD_CMD
        .endm

        ;-----------------------------------
        ; Macro Name: M_PUSH_CRC_LSWORD
        ; Description: Push 15:0 bits of CRC into TX FIFO.
        ; Input Parameters: none
        ; Output Parameters: none
        ;-----------------------------------
M_PUSH_CRC_LSWORD .macro
            M_CMD16 D_PUSH_CRC_LSWORD_CMD
        .endm

        ;-----------------------------------
        ; Macro Name: M_PUSH_ERR_NIBBLE
        ; Description: Push error marker nibble in TX FIFO.
        ; Input Parameters: none
        ; Output Parameters: none
        ;-----------------------------------
M_PUSH_ERR_NIBBLE .macro
            M_CMD16 D_PUSH_ERR_NIBBLE_CMD
        .endm
		
		;-----------------------------------
        ; Macro Name: M_PUSH_TX_EOF
        ; Description: Push error marker nibble in TX FIFO.
        ; Input Parameters: none
        ; Output Parameters: none
        ;-----------------------------------
M_PUSH_TX_EOF	.macro
            M_CMD16 D_TX_EOF	
        .endm

		;-----------------------------------
        ; Macro Name: M_RESET_RXFIFO
        ; Description: Reset RXFIFO
        ; Input Parameters: none
        ; Output Parameters: none
        ;-----------------------------------
M_RESET_RXFIFO .macro
            M_CMD16 D_RESET_RXFIFO
        .endm
		;-----------------------------------
        ; Macro Name: M_RESET_TXFIFO
        ; Description: Reset TXFIFO
        ; Input Parameters: none
        ; Output Parameters: none
        ;-----------------------------------
M_RESET_TXFIFO .macro
            M_CMD16 D_RESET_TXFIFO
        .endm		

M_IPG960_CFG	.macro	
	LDI		TEMP_REG_1.b0, 0xb8  ; This translates to 920 ns( 0xb8 = 184 *5ns) , 40ns is hardware delay, so we get IFG of 960 ns
	sbco	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXIPG0, 1
	sbco	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXIPG1, 1
	.endm
	
M_IPG640_CFG	.macro	
	LDI		TEMP_REG_1.b0, 0x78  ; This translates to 600 ns( 0x78 = 120 *5ns) , 40ns is hardware delay, so we get IFG of 640 ns
	sbco	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXIPG0, 1
	sbco	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXIPG1, 1
	.endm

M_IPG500_CFG	.macro	
	LDI		TEMP_REG_1.b0, 0x5c  ; This translates to 460 ns( 0x5c = 92 *5ns) , 40ns is hardware delay, so we get IFG of 500 ns
	sbco	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXIPG0, 1
	sbco	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXIPG1, 1
	.endm	
	
M_TX_ENABLE	.macro
	.if	$isdefed("SWITCH_CFG")

	.if	$isdefed("PRU0")
	LDI	 TEMP_REG_1.b0, 0x03	
	sbco &TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 1
	
	.else
	LDI	 TEMP_REG_1.b0, 0x03	
	sbco &TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 1
	.endif	
	.else
	.if	$isdefed("PRU0")
		LDI	 TEMP_REG_1.b0, 0x03	
		sbco &TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 1
	.else
		LDI	 TEMP_REG_1.b0, 0x03
		sbco &TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 1
	.endif	

	.endif 
	.endm

M_TX_DISABLE	.macro
	.if	$isdefed("SWITCH_CFG")
	.if	$isdefed("PRU0")
	ldi  TEMP_REG_1.b0, 0x02
	sbco &TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 1
	.else
	ldi  TEMP_REG_1.b0, 0x02
	sbco &TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 1
	.endif	
	.else
	.if	$isdefed("PRU0")
		ldi  TEMP_REG_1.b0, 0x02
		sbco &TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 1
	.else
		ldi  TEMP_REG_1.b0, 0x02
		sbco &TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 1
	.endif	

	.endif
	.endm
	
; Macros to configure MII_RT for various operating modes
; CT = cut-through, AF = auto-forward, HS = host send, 
; TTS = time triggered send, HR = host receive, P2P = peer to peer

; below code is not optimized. Min instruction memory implementation is one lbco and one sbco
; using external image of first 20 bytes of MII_RT_CFG_CONST
; macros are PRU independent, master (single) port config uses PRU0 and receive port attached to it. 

M_SET_MIIRT_CT	.macro
	ldi  	TEMP_REG_1.w0, 0x5d55
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG0, 1
	sbco 	&TEMP_REG_1.b1, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG1, 1
	ldi32	TEMP_REG_1, 0x60400101
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	ldi	    TEMP_REG_1.b1, 0
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	.endm	

M_SET_MIIRT_CT_LB	.macro
	ldi  	TEMP_REG_1.w0, 0x5d55
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG0, 1
	sbco 	&TEMP_REG_1.b1, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG1, 1
	ldi32	TEMP_REG_1, 0x60400101
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	ldi	    TEMP_REG_1.b1, 0
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.endm
	
M_SET_MIIRT_AF2CT_LOCAL	.macro
	.if $defined (PRU0)
	ldi32	TEMP_REG_1, 0x60400001
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	.else
	ldi32	TEMP_REG_1, 0x60400101
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.endif
	.endm

M_SET_MIIRT_AF2CT_REMOTE .macro
	.if $defined (PRU0)
	ldi32	TEMP_REG_1, 0x60400101
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.else
	ldi32	TEMP_REG_1, 0x60400001
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	.endif
	.endm

M_SET_MIIRT_AF	.macro
	ldi  	TEMP_REG_1.w0, 0x5d55
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG0, 1
	sbco 	&TEMP_REG_1.b1, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG1, 1
	ldi32	TEMP_REG_1, 0x60400301
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	ldi	    TEMP_REG_1.b1, 2
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	.endm	

M_SET_MIIRT_AF_LOCAL .macro
	.if $defined(PRU0)
	ldi  	TEMP_REG_1.w0, 0x5d55
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG0, 1
	ldi32	TEMP_REG_1, 0x60200201
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	.else
	ldi  	TEMP_REG_1.w0, 0x5d55
	sbco 	&TEMP_REG_1.b1, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG1, 1
	ldi32	TEMP_REG_1, 0x60200301
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.endif
	.endm

M_SET_MIIRT_AF_LB	.macro
	ldi  	TEMP_REG_1.w0, 0x5d55
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG0, 1
	sbco 	&TEMP_REG_1.b1, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG1, 1
	ldi32	TEMP_REG_1, 0x60400301
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	ldi	    TEMP_REG_1.b1, 2
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.endm

M_SET_MIIRT_P2P	.macro
	ldi  	TEMP_REG_1.w0, 0x5d55
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG0, 1
	sbco 	&TEMP_REG_1.b1, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG1, 1
	ldi32	TEMP_REG_1, 0x60400001
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	ldi	    TEMP_REG_1.b1, 1
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	.endm	
	
M_SET_MIIRT_HR	.macro
;	ldi  	TEMP_REG_1.w0, 0x1d15
	ldi  	TEMP_REG_1.w0, 0x1911
	.if	$isdefed("PRU0")
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG0, 1
	.else
	sbco 	&TEMP_REG_1.b1, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG1, 1
	.endif
	.endm

M_SET_MIIRT_HS	.macro
	.if	$isdefed("PRU0")
	ldi32	TEMP_REG_1, 0x60400001
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.else
	ldi32	TEMP_REG_1, 0x60400100
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	.endif
	.endm	

M_SET_MIIRT_HS_LOCAL .macro
	.if	$defined(PRU")
	ldi32	TEMP_REG_1, 0x60400100
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	.else
	ldi32	TEMP_REG_1, 0x60400001
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.endif
	.endm

M_SET_MIIRT_TTS	.macro
	ldi32		TEMP_REG_1, 0x60400005
	.if	$isdefed("PRU0")
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.else
	ldi	    TEMP_REG_1.b1, 1
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	.endif
	.endm	

M_SET_MIIRT_TTS_LOCAL .macro
	;ldi32		TEMP_REG_1, 0x00400005
	ldi32		TEMP_REG_1, 0x60200005
	.if	$defined(PRU0)
	NOP		; added for code alignment with PRU1
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	.else
	ldi	    TEMP_REG_1.b1, 1
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.endif
	.endm

M_SET_DELAY_M_P0 .macro
	ldi  	TEMP_REG_1.b0, 0x15
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG0, 1
	ldi32	TEMP_REG_1, 0x60400001
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.endm

M_SET_DELAY_M_P1 .macro
	ldi  	TEMP_REG_1.b0, 0x1d
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG1, 1
	ldi32	TEMP_REG_1, 0x60400101
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	.endm

M_SET_DELAY_S_P0 .macro
	ldi  	TEMP_REG_1.b0, 0x55
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG0, 1
	ldi32	TEMP_REG_1, 0x60400201
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.endm

M_SET_DELAY_S_P1 .macro
	ldi  	TEMP_REG_1.b0, 0x5d
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG1, 1
	ldi32	TEMP_REG_1, 0x60400301
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	.endm


M_SET_MIIRT_SYNC_STATE .macro
	ldi  	TEMP_REG_1.w0, 0x5d55
	sbco 	&TEMP_REG_1.b0, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG0, 1
	sbco 	&TEMP_REG_1.b1, MII_RT_CFG_CONST, ICSS_MIIRT_RXCFG1, 1
	.if $defined (PRU0)
	ldi32	TEMP_REG_1, 0x60400201
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	ldi	    TEMP_REG_1.b1, 1
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.else
	ldi32	TEMP_REG_1, 0x60400001
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG1, 4
	ldi	    TEMP_REG_1.b1, 3
	sbco 	&TEMP_REG_1, MII_RT_CFG_CONST, ICSS_MIIRT_TXCFG0, 4
	.endif
	.endm

	.endif
