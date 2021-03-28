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

;------------------------------------------
; FILE: classi.h
;classifier/filter use for basic switch/dual mac
; note: we define precisely how
;   classifiers are used in these two
;   fw builds (see below)
; ASSUMPTION:  Host programs these registers
;  how he wants them to get to these
;  classification cases
;   e.g. if pkt to host and classi bits 0-3 not set  then
;     flow set to default
;   same for portQ.
;
;  nice about this approach is how filters are used..
;  Namely =>  really up to host.
;  f/w just expects filters to be mapped [by host] into the classifiers so that:
;    (a) to-host pkts can be identified and binned to flows
;    (b) cut/no-cut can decision can be made (switch)
;    (c) map of pkt to queue for store&forward can be made (switch)
;    (d) map of pkt into a rate limiter can be made (if desired)
;  So f/w is blissfully unaware about what filter is doing what..
; see classi_example.cpp for example host setup
;-------------------------------------------------------------------

;classi (16 of them)
; 0-3  =>  flow assignment (switch/mac: used only if pkt is to go to host,
;                           and rate limiting)
; 4  =>   determines if pkt is for host (mac)
; 4  =>   custom / not used (switch)
; 5-6    =>  rate limiters (switch)
; 7    =>  cut through eligible (switch)
; 8-15 =>  port Q assignment (switch)
; 8-15 =>  custom (mac).  e.g. use for more ratelimiters
;classi is in word2 of xin value
	.asg w2, classi
	.asg b2.t4, classi_tohost  ;this tells if pkt is to host
	.asg b2.t5, classi_c1
	.asg b2.t6, classi_c2
	.asg b2.t7, classi_c4
	.asg b3.t0, classi_c5
	.asg b3.t1, classi_c6
;""
	.asg b3.t7, classi_c13
	.asg b2, classi_flow    ;bits 0-3 of byte2
	.asg 0x0f, CLASSI_FMASK

;rate limiters supported
	.asg b0, rl_bits   ;all bits of byte0.  0-3 are tied to flow classis, 4, 5 tied to rl classis (switch)

;[MAC]use classi to tell us if pkt should go to host
; r_classi is probably r17 (unless we move before calling macro)
; jumps to nok_lab if we shouldn't take pkt
TOHOST_OK	.macro	r_classi, nok_lab
	qbbc nok_lab, r_classi.b2, 4 ;classi_tohost
 .endm

;rate limiter check
RX_RATE_OK	.macro	r_classi, rate_bad_lab
	lmbd r0.b0, r_classi.b0, 1
	qbne rate_bad_lab, r0.b0,32  ;i.e, if any rate limiter fires, we return bad
 .endm

;filter use
;  really up to host.
;  f/w just expects filters to be mapped into the classifiers so that:
;    (a) to-host pkts can be identified and binned to flows
;    (b) cut/no-cut can decision can be made (switch)
;    (c) map of pkt to queue for store&forward can be made (switch)
;    (d) map of pkt into a rate limiter can be made (if desired)
;    (e) tell if pkt should go to host (mac)
