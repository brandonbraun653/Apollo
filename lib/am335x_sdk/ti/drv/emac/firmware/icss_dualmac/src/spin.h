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
; spin.h:  defines and macros for SPINLOCK  engine on ICSSG
;-----------------------------------------------------------

;-----------------DEFINES-------------------------

;XIDs
SPIN_XID_LOC	.set	0x90
;#define SPIN_XID_LOC  90    ;local lock
SPIN_XID_REM1	.set	0x91
SPIN_XID_REM2	.set	0x92

;spin lock flag defines
SPIN_FDB_FLAG	.set	0x1
SPIN_FDB_HOST_FLAG	.set	0x2

 .if $isdefed("SLICE0")
PRU_RTU_EOD_P_FLAG	.set	0x6
PRU_RTU_EOD_E_FLAG	.set	0x7
PSI_GLITCH_FLAG	.set	0xa
PRU_RTU_SOF_FLAG	.set	0xa
PRU_RTU_EOF_FLAG	.set	0xb
RTU_RTU_IPC_FLAG	.set	0xc
PRU_RTU_TX_TS_READY	.set	0x10
 .endif
 .if $isdefed("SLICE1")
PRU_RTU_EOD_P_FLAG	.set	0x8
PRU_RTU_EOD_E_FLAG	.set	0x9
PSI_GLITCH_FLAG	.set	0xd
PRU_RTU_SOF_FLAG	.set	0xd
PRU_RTU_EOF_FLAG	.set	0xe
RTU_RTU_IPC_FLAG	.set	0xf
PRU_RTU_TX_TS_READY	.set	0x11
 .endif

;-----------------STRUCTURES-----------------------------

;-----------------STRUCTURE OVERLAYS-----------

;------------------MACROS--------------------------

SPIN_SET_LOCK_LOC	.macro 	  flagno
	ldi	r1.b0, flagno
	xin	SPIN_XID_LOC, &r1.b3, 1
 .endm

;spin lock with fail label and bit to test
;testbit == flagno
SPIN_SET_LOCK_LOC_LAB	.macro 	  flagno, lab_fail
	ldi	r1.b0, flagno
	xin	SPIN_XID_LOC, &r1.b3, 1
	qbbc	lab_fail, r1, 24	 ;replaced: qbbc lab_fail, r1.t24
 .endm

SPIN_CLR_LOCK_LOC	.macro 	 flagno
	ldi	r1.b0, flagno
	xout	SPIN_XID_LOC, &r1.b3, 1
 .endm

SPIN_TOG_LOCK_LOC	.macro		flagno
	ldi	r1.b0, flagno
	xin	SPIN_XID_LOC, &r1.b3, 1
	xout	SPIN_XID_LOC, &r1.b3, 1
 .endm
