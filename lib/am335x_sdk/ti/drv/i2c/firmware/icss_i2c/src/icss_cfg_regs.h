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
; file:   icss_cfg_regs.h
;
; brief:  {ICSS Global Configuration Module Registers}
;
;
;
    .if    !$isdefed("__icss_cfg_regs_h")
__icss_cfg_regs_h    .set 1

    .if $defined("ICSS_REV1")
ICSS_CFG_REVID          .set    (CSL_ICSSM_CFG_REVID)
ICSS_CFG_SYSCFG         .set    (CSL_ICSSM_CFG_SYSCFG)
ICSS_CFG_GPCFG0         .set    (CSL_ICSSM_CFG_GPCFG0)
ICSS_CFG_GPCFG1         .set    (CSL_ICSSM_CFG_GPCFG1)
ICSS_CFG_CGR            .set    (CSL_ICSSM_CFG_CGR)
ICSS_CFG_ISRP           .set    (CSL_ICSSM_CFG_ISRP)
ICSS_CFG_ISP            .set    (CSL_ICSSM_CFG_ISP)
ICSS_CFG_IESP           .set    (CSL_ICSSM_CFG_IESP)
ICSS_CFG_IECP           .set    (CSL_ICSSM_CFG_IECP)
ICSS_CFG_SCRP           .set    (CSL_ICSSM_CFG_SCRP)
ICSS_CFG_PMAO           .set    (CSL_ICSSM_CFG_PMAO)
ICSS_CFG_MIIRTEN        .set    (CSL_ICSSM_CFG_MII_RT)
ICSS_CFG_IEPCLK         .set    (CSL_ICSSM_CFG_IEPCLK)
ICSS_CFG_SPP            .set    (CSL_ICSSM_CFG_SPP)
ICSS_CFG_PIN_MX         .set    (CSL_ICSSM_CFG_PIN_MX)
    .endif  ;ICSS_REV1

    .if $defined("ICSS_REV2")
ICSS_CFG_REVID          .set    (CSL_ICSSCFG_REVID)
ICSS_CFG_SYSCFG         .set    (CSL_ICSSCFG_SYSCFG)
ICSS_CFG_GPCFG0         .set    (CSL_ICSSCFG_GPCFG0)
ICSS_CFG_GPCFG1         .set    (CSL_ICSSCFG_GPCFG1)
ICSS_CFG_CGR            .set    (CSL_ICSSCFG_CGR)
ICSS_CFG_ISRP           .set    (CSL_ICSSCFG_ISRP)
ICSS_CFG_ISP            .set    (CSL_ICSSCFG_ISP)
ICSS_CFG_IESP           .set    (CSL_ICSSCFG_IESP)
ICSS_CFG_IECP           .set    (CSL_ICSSCFG_IECP)
ICSS_CFG_SCRP           .set    (CSL_ICSSCFG_SCRP)
ICSS_CFG_PMAO           .set    (CSL_ICSSCFG_PMAO)
ICSS_CFG_MIIRTEN        .set    (CSL_ICSSCFG_MII_RT)
ICSS_CFG_IEPCLK         .set    (CSL_ICSSCFG_IEPCLK)
ICSS_CFG_SPP            .set    (CSL_ICSSCFG_SPP)
ICSS_CFG_PIN_MX         .set    (CSL_ICSSCFG_PIN_MX)
    .endif  ;ICSS_REV2
    .endif
