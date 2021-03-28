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
; file:   icss_esc_defs.inc
;
; brief:  This header file defines ICSS ESC firmware specific constants
;
;
;
;	Version		Description							Author
;
; 	0.1     	Created								Thomas Mauer
;

	.if ! $defined(__icss_event_defs_inc)
	.define "1", __icss_event_defs_inc

SYS_EVT_PRU1_RX_EOF				.set		54
SYS_EVT_MDIO_MII_LINK1			.set		53
SYS_EVT_PORT1_TX_OVERFLOW		.set		52
SYS_EVT_PORT1_TX_UNDERFLOW		.set		51
SYS_EVT_PRU1_RX_OVERFLOW		.set		50
SYS_EVT_PRU1_RX_CRC				.set		48
SYS_EVT_PRU1_RX_SOF				.set		47
SYS_EVT_PRU1_RX_ERR32			.set		45
SYS_EVT_PRU1_RX_ERR				.set		44
SYS_EVT_PRU0_RX_EOF				.set		42
SYS_EVT_MDIO_MII_LINK0			.set		41
SYS_EVT_PORT0_TX_OVERFLOW		.set		40
SYS_EVT_PORT0_TX_UNDERFLOW		.set		39
SYS_EVT_PRU0_RX_OVERFLOW		.set		38
SYS_EVT_PRU0_RX_CRC				.set		36
SYS_EVT_PRU0_RX_SOF				.set		35
SYS_EVT_PRU0_RX_ERR32			.set		33
SYS_EVT_PRU0_RX_ERR				.set		32
; system events 31 to 16 are PRU generated events
; please define them in the protocol specific files
SYS_EVT_ECAP_PEND				.set		15
SYS_EVT_SYNC0_OUT_PEND			.set		14
SYS_EVT_SYNC1_OUT_PEND			.set		13
SYS_EVT_LATCH0_IN_PEND			.set		12
SYS_EVT_LATCH1_IN_PEND			.set		11
SYS_EVT_PDI_WD_EXP_PEND			.set		10
SYS_EVT_PD_WD_EXP_PEND			.set		9
SYS_EVT_IEP_TIM_CAP_CMP_PEND	.set		7


; R31 Status flags
D_DATA_READY_FLAG_BITNUM    	.set	16
D_BYTE_READY_FLAG_BITNUM    	.set	17
D_WORD_READY_FLAG_BITNUM    	.set	18
D_RX_ERROR_FLAG_BITNUM 			.set	19
D_EOF_FLAG_BITNUM           	.set	20
D_SFD_FLAG_BITNUM           	.set	21
D_SOF_FLAG_BITNUM          		.set	22
D_ERROR_NIBBLE_FLAG_BITNUM		.set	23
D_CRC_ERR_FLAG_BITNUM     		.set	24
D_RX_ERR_FLAG_BITNUM			.set	25
D_RX_MAX_PRE_CNT_ERR_FLAG_BITNUM .set	26
D_RX_EOF_ERROR_FLAG_BITNUM		.set	27
D_RX_MAX_FRM_CNT_ERR_FLAG_BITNUM .set	28
D_RX_MIN_FRM_CNT_ERR_FLAG_BITNUM .set	29


D_DATA_READY_FLAG_MASK	.set	(1 << 0)
D_BYTE_READY_FLAG_MASK	.set	(1 << 1)
D_WORD_READY_FLAG_MASK	.set	(1 << 2)
D_RX_ERROR_FLAG_MASK	.set	(1 << 3)
D_EOF_FLAG_MASK			.set	(1 << 4)
D_SFD_FLAG_MASK			.set	(1 << 5)
D_SOF_FLAG_MASK			.set	(1 << 6)
D_ERROR_NIBBLE_FLAG_MASK .set	(1 << 7)
D_CRC_ERR_FLAG_MASK		.set	(1 << 8)
D_RX_ERR_FLAG_MASK		.set	(1 << 9)


; R31 Command masks

D_TX_CRC_ERR					.set	0x8000
D_RESET_TXFIFO					.set	0x4000
D_TX_EOF						.set	0x2000
D_PUSH_ERR_NIBBLE_CMD           .set    0x1000

D_PUSH_CRC_MSWORD_CMD           .set    0x0800
D_PUSH_CRC_LSWORD_CMD           .set    0x0400
D_PUSH_WORD_CMD                 .set    0x0200
D_PUSH_BYTE_CMD                 .set    0x0100


D_RX_ERROR_CLEAR				.set	0x0080
D_RX_SOF_CLEAR					.set	0x0040
D_RX_SFD_CLEAR					.set	0x0020
D_RX_EOF_CLEAR					.set	0x0010

D_RESET_RXFIFO					.set	0x0004
D_POP_WORD_CMD                  .set    0x0002
D_POP_BYTE_CMD                  .set    0x0001

D_PUSH_N_POP_BYTE_CMD           .set    (D_POP_BYTE_CMD | D_PUSH_BYTE_CMD)
D_PUSH_N_POP_WORD_CMD           .set    (D_POP_WORD_CMD | D_PUSH_WORD_CMD)

; RX L2 Status
L2_ERROR_CRC_MASK			.set	(1 << 7)
L2_ERROR_NIBBLE_MASK		.set	(1 << 6)
L2_RX_SOF_MASK				.set	(1 << 5)
L2_RX_SFD_MASK				.set	(1 << 4)
L2_RX_EOF_MASK				.set	(1 << 3)
L2_RX_ERROR_MASK			.set	(1 << 2)
L2_STATUS_RDY_MASK			.set	(1 << 1)
L2_RX_ERR_MASK				.set	(1 << 0)

L2_ERROR_CRC_FLAG_BITNUM	.set	7
L2_ERROR_NIBBLE_FLAG_BITNUM	.set	6
L2_RX_EOF_FLAG_BITNUM		.set	3

	.endif
