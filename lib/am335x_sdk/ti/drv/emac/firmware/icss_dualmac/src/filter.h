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
; filter.h:  defines and macros for FILTER  engine on ICSSG
;-----------------------------------------------------------

;-----------------DEFINES-------------------------

;XIDs
FILTER_XID_READ	.set	22
USE_MEM_FOR_MATCH_INFO	.set	1 ;use smem/dmem instead of BS ram for match info

_MII_RT_CFG_BASE	.set	0x33000

;filter type 1 - cfg register block for an individual filter
;  add to FT_1_P_BASE below
FT_1_DA0	.set	0x00
FT_1_DA1	.set	0x04
FT_1_MASK0	.set	0x8
FT_1_MASK1	.set	0xc
FT_1_R_LEN	.set	0x10
FT_1_R_LEN_S	.set	4

;filter type 3 - cfg register block for an indivual filter
FT_3_START	.set	0x00
FT_3_STARTA	.set	0x04
FT_3_STARTL	.set	0x08
FT_3_JMPO	.set	0x0c
FT_3_LEN	.set	0x10
FT_3_CFG	.set	0x14
FT_3_T	.set	0x18
FT_3_T_MASK	.set	0x1c
FT_3_RT_LEN	.set	0x20
FT_3_RT_LEN_S	.set	5
;P bits
FT_3_P0	.set	0x00
FT_3_P1	.set	0x04
FT_3_MP0	.set	0x08
FT_3_MP1	.set	0xc0
FT_3_RP_LEN	.set	0x10
FT_3_RP_LEN_S	.set	4

 .if $isdefed("SLICE0")
;pru0..
FT_1_P_SL	.set	0x80
FT_1_P_CFG	.set	0x84
FT_1_P_BASE	.set	0x88
FT_3_PT_BASE	.set	0x108
FT_3_PP_BASE	.set	0x308
 .endif

 .if $isdefed("SLICE1")
;pru1..
FT_1_P_SL	.set	0x64c
FT_1_0_CFG	.set	0x650
FT_1_P_BASE	.set	0x654
FT_3_PT_BASE	.set	0x6d4
FT_3_PP_BASE	.set	0x8d4
 .endif

;-----------------STRUCTURES-----------------------------
	.asg	t8, f_IS_UNICAST
	.asg	t9, f_IS_MULTICAST
	.asg	t10, f_IS_BROADCAST
	.asg	t11, f_SAV_ERR
	.asg	t12, f_FW
	.asg	t13, f_TOHOST0  ;if MC or BS or MAC_I
	.asg	t14, f_VLAN
	.asg	t15, f_TOHOST1 ;if MAC_P
	.asg	t16, f_TOHOST2 ;if MAC_I

filter_result	.struct
cur_byte	.uint
fflags0	.uint
flags_f1	.uint
flags_f3a	.uint
flags_f3b	.uint
sa_hash	.uint
conn_hash	.uint
rate	.uint
 .endstruct

filter_info	.struct
spare0	.ubyte
spare1	.ubyte
flow_id	.ushort
 .endstruct

;-----------------STRUCTURE OVERLAYS-----------

FILTER_RESULT	.sassign	r10, filter_result
FILTER0	.sassign	r2, filter_info
FILTER1	.sassign	r3, filter_info
FILTER2	.sassign	r4, filter_info
FILTER3	.sassign	r5, filter_info
FILTER4	.sassign	r6, filter_info
FILTER5	.sassign	r7, filter_info
FILTER6	.sassign	r8, filter_info
FILTER7	.sassign	r9, filter_info

;------------------MACROS--------------------------
;get all the filter info
; clobbers r10-r17
FILTER_GET_ALL	.macro
	xin FILTER_XID_READ, &r10, 32
 .endm

