;
;  TEXAS INSTRUMENTS TEXT FILE LICENSE
; 
;   Copyright (c) 2017-2018 Texas Instruments Incorporated
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
; 
; file:   icss_ctrl_regs.h
;
; brief:  {ICSS PRU Control Registers}
;
;
;
    .if    !$isdefed("__icss_ctrl_regs_h")
__icss_ctrl_regs_h    .set 1

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

