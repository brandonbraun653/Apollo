;
;  TEXAS INSTRUMENTS TEXT FILE LICENSE
;
;   Copyright (c) 2018-2019 Texas Instruments Incorporated
;
;  All rights reserved not granted herein.
;
;  Limited License.
;
;  Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
;  license under copyrights and patents it now or hereafter owns or controls to
;  make, have made, use, import, offer to sell and sell ("Utilize") this software
;  subject to the terms herein.  With respect to the foregoing patent license,
;  such license is granted  solely to the extent that any such patent is necessary
;  to Utilize the software alone.  The patent license shall not apply to any
;  combinations which include this software, other than combinations with devices
;  manufactured by or for TI (“TI Devices”).  No hardware patent is licensed hereunder.
;
;  Redistributions must preserve existing copyright notices and reproduce this license
;  (including the above copyright notice and the disclaimer and (if applicable) source
;  code license limitations below) in the documentation and/or other materials provided
;  with the distribution.
;
;  Redistribution and use in binary form, without modification, are permitted provided
;  that the following conditions are met:
; 	No reverse engineering, decompilation, or disassembly of this software is
;   permitted with respect to any software provided in binary form.
; 	Any redistribution and use are licensed by TI for use only with TI Devices.
; 	Nothing shall obligate TI to provide you with source code for the software
;   licensed and provided to you in object code.
;
;  If software source code is provided to you, modification and redistribution of the
;  source code are permitted provided that the following conditions are met:
; 	Any redistribution and use of the source code, including any resulting derivative
;   works, are licensed by TI for use only with TI Devices.
; 	Any redistribution and use of any object code compiled from the source code
;   and any resulting derivative works, are licensed by TI for use only with TI Devices.
;
;  Neither the name of Texas Instruments Incorporated nor the names of its suppliers
;  may be used to endorse or promote products derived from this software without
;  specific prior written permission.
;
;  DISCLAIMER.
;
;  THIS SOFTWARE IS PROVIDED BY TI AND TI’S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED
;  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
;  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI’S
;  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
;  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
;  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
;  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
;  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

;---------------------------------------
; file: smem.h
; purpose:  smem layout
;---------------------------------------

;f/w configuration
 .if $isdefed("SLICE0")
FW_CONFIG	.set	0x10000
 .else
FW_CONFIG	.set	0x18000
 .endif
FW_CONFIG_END		.set	(FW_CONFIG+1000 - 1)

;MQ = port queues + 2 queues for RTU2RTU IPC
;  =
;- test (only 64 entries x 8 queue @12bytes) [portq] +
;       (32 entries x 2 queues  @ 8 bytes )  [r2R IPC queues]
MQBASE_START	.set	(FW_CONFIG_END + 1)
MQBASE_END	.set	(MQBASE_START + 64*12*8+32*8*2-1)

;vlan info area
VLAN_START	.set	(MQBASE_END+1)

; static configuration
CFG_STATUS	.set 0x00	; only PRU can write here
CFG_ADDR_LO	.set CFG_STATUS + 4
CFG_ADDDR_HI	.set CFG_ADDR_LO + 4
CFG_TX_BS_0	.set CFG_ADDDR_HI + 4
CFG_TX_BS_8	.set (CFG_TX_BS_0 + 4 * 8)
CFG_ACT_THR_N	.set (CFG_TX_BS_8 + 4 * 8)
CFG_EGR_RATE_LIM_EN	.set CFG_ACT_THR_N + 4
CFG_DEF_FLOW	.set CFG_EGR_RATE_LIM_EN + 4
CFG_MGR_FLOW	.set CFG_DEF_FLOW + 4
CFG_FLAGS	.set CFG_MGR_FLOW + 4
CFG_N_BURST	.set CFG_FLAGS + 4 ;just for debug
CFG_RTU_STATUS	.set CFG_N_BURST + 4 ; only RTU can write here
CFG_OUT		.set CFG_RTU_STATUS + 4
CFG_RES		.set CFG_OUT + 4

CFG_SEED	.set CFG_RES + 4 ; seed to calculate random value
BD_OFS_0	.set CFG_SEED + 4;
BD_OFS_1	.set BD_OFS_0 + 8
TX_IPG		.set BD_OFS_1 + 8
BD_FREE		.set TX_IPG + 4
CMD_PARAM	.set BD_FREE + 4

TX_TS_BASE	.set 0x300

; we will write 4 x 32bit area to process TX TS
; word0 and word1 - TS
; word2 - flags
; word3 - cookie
;

RX_TS_BASE	.set TX_TS_BASE  + 16

;============================================

PRU_READY	.set 0x1234ad52
RTU_READY	.set 0x44554841
PRU_DONE	.set 0x10000001


RTU_STARTED_SHUTDOWN	.set 0x12343333
RTU_SETPORT	.set 0x12344444
RTU_STOPPED	.set 0x1234DEAD
PRU_STOPPED	.set 0x4455DEAD
