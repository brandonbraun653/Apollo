; 
; Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
; 
; 
; Redistribution and use in source and binary forms, with or without
; modification, are permitted provided that the following conditions
; are met:
; 
;        * Redistributions of source code must retain the above copyright
;          notice, this list of conditions and the following disclaimer.
; 
;        * Redistributions in binary form must reproduce the above copyright
;          notice, this list of conditions and the following disclaimer in the
;          documentation and/or other materials provided with the
;          distribution.
; 
;        * Neither the name of Texas Instruments Incorporated nor the names of
;          its contributors may be used to endorse or promote products derived
;          from this software without specific prior written permission.
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

; file:   icss_ctrl_regs.h
;
; brief:  ICSS PRU Control Registers
;

    .if    !$isdefed("__icss_ctrl_regs_h")
__icss_ctrl_regs_h    .set 1

    .cdecls C,NOLIST
%{
#include "cslr_icss.h"
%}

    .if $defined("ICSS_REV1")
ICSS_PRU_CTRL_CONTROL       .set    (CSL_ICSSM_PRU_CTRL_CONTROL)
ICSS_PRU_CTRL_STATUS        .set    (CSL_ICSSM_PRU_CTRL_STATUS)
ICSS_PRU_CTRL_WAKEUP_EN     .set    (CSL_ICSSM_PRU_CTRL_WAKEUP_EN)
ICSS_PRU_CTRL_CYCLE         .set    (CSL_ICSSM_PRU_CTRL_CYCLE)
ICSS_PRU_CTRL_STALL         .set    (CSL_ICSSM_PRU_CTRL_STALL)
ICSS_PRU_CTRL_CTBIR0        .set    (CSL_ICSSM_PRU_CTRL_CTBIR0)
ICSS_PRU_CTRL_CTBIR1        .set    (CSL_ICSSM_PRU_CTRL_CTBIR1)
ICSS_PRU_CTRL_CTPPR0        .set    (CSL_ICSSM_PRU_CTRL_CTPPR0)
ICSS_PRU_CTRL_CTPPR1        .set    (CSL_ICSSM_PRU_CTRL_CTPPR1)
    .endif  ;ICSS_REV1

    .if $defined("ICSS_REV2")
ICSS_PRU_CTRL_CONTROL       .set    (CSL_ICSSPRUCTRL_CONTROL)
ICSS_PRU_CTRL_STATUS        .set    (CSL_ICSSPRUCTRL_STATUS)
ICSS_PRU_CTRL_WAKEUP_EN     .set    (CSL_ICSSPRUCTRL_WAKEUP_EN)
ICSS_PRU_CTRL_CYCLE         .set    (CSL_ICSSPRUCTRL_CYCLE)
ICSS_PRU_CTRL_STALL         .set    (CSL_ICSSPRUCTRL_STALL)
ICSS_PRU_CTRL_CTBIR0        .set    (CSL_ICSSPRUCTRL_CTBIR0)
ICSS_PRU_CTRL_CTBIR1        .set    (CSL_ICSSPRUCTRL_CTBIR1)
ICSS_PRU_CTRL_CTPPR0        .set    (CSL_ICSSPRUCTRL_CTPPR0)
ICSS_PRU_CTRL_CTPPR1        .set    (CSL_ICSSPRUCTRL_CTPPR1)
    .endif  ;ICSS_REV2
    .endif
