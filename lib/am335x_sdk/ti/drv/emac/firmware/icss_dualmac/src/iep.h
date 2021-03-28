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
;----------------------------------------------------------
; iep.h:  defines and macros for IEP ICSSG
;-----------------------------------------------------------

;-----------------DEFINES-------------------------

;define this in order to get minimal iep access latency
; -> bring with it 4ns clock resolution instead of 5
IEP_SYNC_MODE	.set	1

 .if $isdefed("SLICE0")
IEP_BASEx	.set	0x2e000
 .else
IEP_BASEx	.set	0x2f000
 .endif

IEP_BASE0	.set	0x2e000
IEP_BASE1	.set	0x2f000
IEP_CFG1_BASEx	.set	 (0x26000+0x30)

IEP_GCFG	.set	0x00
IEP_C64_HI	.set	0x14
IEP_C64_LO	.set	0x10
IEP_CAP_RX_S0	.set	0x20
IEP_CAP_RX_S1	.set	0x30
IEP_CAP_TX_S0	.set	0x40
IEP_CAP_TX_S1	.set	0x48
IEP_CMP_CFG	.set	0x70
IEP_CMP_REG_BASE0_7	.set	0x78
IEP_CMP_REG_BASE8_15	.set	0xc0

;-----------------STRUCTURES-----------------------------

;-----------------STRUCTURE OVERLAYS-----------

;------------------MACROS--------------------------

;enable sync mode for iep
SET_IEP_SYNC_MODE	.macro 	 base
 .if $isdefed("IEP_SYNC_MODE")
	ldi32	r0, base
	ldi	r1, 0x1;make core clock the iep clock (250 mhz), synchronous now with cores
	sbbo	&r1, r0, 0, 4
 .endif
 .endm

;turn on iep
; set
ENABLE_IEP	.macro 	 base
	ldi32	r0, base
	lbbo	&r1, r0, 0, 4
	clr	r1, r1, 0
	sbbo	&r1, r0, 0, 4;make sure its not running
 .if $isdefed("IEP_SYNC_MODE")
	ldi	r1.b0, 0x40
 .endif
	set	r1, r1, 0
	sbbo	&r1, r0, 0, 4
 .endm

ENABLE_CMP	.macro 	 base, cnum, r_scratch
	ldi32	r0, base
	add	r0, r0, IEP_CMP_CFG
	ldi	r_scratch, 1
	lsl r_scratch, r_scratch,cnum
	lsl r_scratch, r_scratch,1
	lbbo	&r1, r0, 0, 4
	or	r1, r1, r_scratch
	sbbo	&r1, r0, 0, 4
 .endm

;enable cmp event for now+ val  ns
SET_CMP8_15	.macro 	 base, cnum,r_scr0,r_scr1,r_val
;r_scrx should be 2 regs consecutive:
;cnum needs to be the byte offset to cmp register h/l pair for iep channel
;  8 => 0
;  9 => 8
;/ 15=> 56
	ldi32	r0, base
;read 64bit time
	lbbo	&r_scr0, r0, 0x10, 8
	add	r0, r0, IEP_CMP_REG_BASE8_15
	add r_scr0, r_scr0,r_val
	adc r_scr1, r_scr1,0
	sbbo	&r_scr0, r0, cnum, 8
 .endm

;read iep counter for (fw) timestamp
; assumes iep0
; uses r0
GET_FW_TS	.macro	r_ts_h
	ldi r0, (IEP_BASE0+IEP_C64_HI)
	lbbo &r_ts_h, r0,0,8
 .endm

;read iep for rx timestamp
; assumes iep0 for sWITCH
; for MAC, use iep0 for slice0, iep1 for slice1
; uses r0
GET_PKT_RX_TS	.macro 	 r_ts_h
 .if $isdefed("SLICE0")
	ldi32	r0, (IEP_BASE0+IEP_CAP_RX_S0)
 .else  ;slice1
	ldi32	r0, (IEP_BASE1+IEP_CAP_RX_S1)
 .endif
	lbbo	&r_ts_h, r0, 0, 8
 .endm

;read iep for tx timestamp
; assumes iep0 is used for switch
; (MAC uses iep0 for slice0, iep1 for slice1)
; (note for switch, slice0 needs tx timestamp for port1 and viceversa)
; uses r0
GET_PKT_TX_TS	.macro 	 r_ts_h
 .if $isdefed("SLICE0")
	ldi32	r0, (IEP_BASE0+IEP_CAP_TX_S0)
 .else ; slice1
	ldi32	r0, (IEP_BASE1+IEP_CAP_TX_S1)
 .endif
	lbbo	&r_ts_h, r0, 0, 8
 .endm

GET_IEP_CNT	.macro reg
 .if $isdefed("SLICE0")
	ldi32	r0, (IEP_BASE0+IEP_C64_LO)
 .else ; slice1
	ldi32	r0, (IEP_BASE1+IEP_C64_LO)
 .endif
	lbbo	&reg, r0, 0, 4
 .endm

