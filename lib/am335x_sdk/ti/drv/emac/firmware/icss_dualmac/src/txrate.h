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

;-------------------------------------------------
;---file: TXRATE.h
;---purpose:  utilities to manage txrate units
;---------------------------------------------------

;--------------------DEFINES----------------------

 .if $isdefed("SLICE0")
TXRATE_BASE	.set	  (_MII_RT_CFG_BASE+0x50c)
 .else
TXRATE_BASE	.set	  (_MII_RT_CFG_BASE+0xad8)
 .endif

;----------------------
;PIR policing rate in Mbit/s = (200 * rx_cir_idle[31:0]) >> 15
;rx_rate_cfg[n] =  ( rate-in-MHz * 32768 ) / 200
;For 100Mbit/S, set rx_rate_cfg[n]  to be 16384
;  for 1Mbps :163
;  for 100kbps:  16
;  for  ~10kbps:  1 or 2

TXRATE_1G	.set	163840
TXRATE_100M	.set	16384
TXRATE_10M	.set	1638
TXRATE_1M	.set	163
TXRATE_100K	.set	16

;-------------------MACROS------------------------

;initialize TX_RATE
;unit = 0, 1,2,3
TXRATE_INIT	.macro 	 unit, r_scratch,r_thresh

	ldi32	r0, TXRATE_BASE
	sbbo	&r_thresh, r0, (8*unit), 4
	lbbo	&r_scratch, r0, ((8*unit)+4), 4
 .if $isdefed("later")
	ldi r_scratch, 0
	clr r_scratch.t16
	sbbo r_scratch, r0,((8*unit)+4),4
	add r0, r0,0
	add r0, r0,0
	add r0, r0,0
	add r0, r0,0
	add r0, r0,0
	set r_scratch.t16
	sbbo r_scratch, r0,((8*unit)+4),4
 .endif
 .endm

TXRATE_DUMP	.macro 	 unit, r_scratch1,r_scratch2

	ldi32	r0, TXRATE_BASE
	lbbo	&r_scratch1, r0, (8*unit), 4
	lbbo	&r_scratch2, r0, (8*unit)+4, 4
 .endm

;chk & indicate sop to txrate unit
TXRATE_CHK_AND_SOP	.macro 	 unit, r_scratch,r_len,nogo_exit

	ldi32	r0, TXRATE_BASE

;ldi  r_scratch, 0  ;remove me!
;lbbo r_scratch, r0,unit+4,4
;qbbc nogo_exit, r_scratch.t17
	and r_scratch.w0, r_len, r_len
	set	r_scratch, r_scratch, 16
	sbbo	&r_scratch, r0, ((8*unit)+4), 4
	lbbo	&r_scratch, r0, ((8*unit)+4), 4
	qbbc	nogo_exit, r_scratch, 17	 ;replaced: qbbc nogo_exit, r_scratch.t17
 .endm

;chk & indicate sop to txrate unit
;v2
TXRATE_CHK_AND_SOPv2	.macro 	 r_unit, r_scratch,r_len,nogo_exit

	ldi32	r0, TXRATE_BASE
	lsr r_unit, r_unit,3  ;x8
	add r_unit, r_unit,4  ;+4
;ldi  r_scratch, 0  ;remove me!
;lbbo r_scratch, r0,unit+4,4
;qbbc nogo_exit, r_scratch.t17
	and r_scratch.w0, r_len, r_len;Warning: converted from mov
	set	r_scratch, r_scratch, 16
	sbbo	&r_scratch, r0, r_unit, 4
	lbbo	&r_scratch, r0, r_unit, 4
	qbbc	nogo_exit, r_scratch, 17	 ;replaced: qbbc nogo_exit, r_scratch.t17
 .endm

