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
; file:   icss_intc_regs.h
;
; brief:  ICSS Interrupt Controller Module Registers
;
;
;  (C) Copyright 2017-2018, Texas Instruments, Inc
;
;
	
	.if !$defined("__icss_intc_regs_h")	
__icss_intc_regs_h	.set	1	
	

    .if $defined("ICSS_REV1")
ICSS_INTC_REVID         .set    (CSL_ICSSM_INTC_REVID)
ICSS_INTC_CR            .set    (CSL_ICSSM_INTC_CR)
ICSS_INTC_GER           .set    (CSL_ICSSM_INTC_GER)
ICSS_INTC_GNLR          .set    (CSL_ICSSM_INTC_GNLR)
ICSS_INTC_SISR          .set    (CSL_ICSSM_INTC_SISR)
ICSS_INTC_SICR          .set    (CSL_ICSSM_INTC_SICR)
ICSS_INTC_EISR          .set    (CSL_ICSSM_INTC_EISR)
ICSS_INTC_EICR          .set    (CSL_ICSSM_INTC_EICR)
ICSS_INTC_HIEISR        .set    (CSL_ICSSM_INTC_HIEISR)
ICSS_INTC_HIDSR         .set    (CSL_ICSSM_INTC_HIDISR)
ICSS_INTC_GPIR          .set    (CSL_ICSSM_INTC_GPIR)
ICSS_INTC_SRSR0         .set    (CSL_ICSSM_INTC_SRSR0)
ICSS_INTC_SRSR1         .set    (CSL_ICSSM_INTC_SRSR1)
ICSS_INTC_SECR0         .set    (CSL_ICSSM_INTC_SECR0)
ICSS_INTC_SECR1         .set    (CSL_ICSSM_INTC_SECR1)
ICSS_INTC_ESR0          .set    (CSL_ICSSM_INTC_ESR0)
ICSS_INTC_ESR1          .set    (CSL_ICSSM_INTC_ERS1)
ICSS_INTC_ECR0          .set    (CSL_ICSSM_INTC_ECR0)
ICSS_INTC_ECR1          .set    (CSL_ICSSM_INTC_ECR1)
ICSS_INTC_CMR0          .set    (CSL_ICSSM_INTC_CMR0)
ICSS_INTC_CMR1          .set    (CSL_ICSSM_INTC_CMR1)
ICSS_INTC_CMR2          .set    (CSL_ICSSM_INTC_CMR2)
ICSS_INTC_CMR3          .set    (CSL_ICSSM_INTC_CMR3)
ICSS_INTC_CMR4          .set    (CSL_ICSSM_INTC_CMR4)
ICSS_INTC_CMR5          .set    (CSL_ICSSM_INTC_CMR5)
ICSS_INTC_CMR6          .set    (CSL_ICSSM_INTC_CMR6)
ICSS_INTC_CMR7          .set    (CSL_ICSSM_INTC_CMR7)
ICSS_INTC_CMR8          .set    (CSL_ICSSM_INTC_CMR8)
ICSS_INTC_CMR9          .set    (CSL_ICSSM_INTC_CMR9)
ICSS_INTC_CMR10         .set    (CSL_ICSSM_INTC_CMR10)
ICSS_INTC_CMR11         .set    (CSL_ICSSM_INTC_CMR11)
ICSS_INTC_CMR12         .set    (CSL_ICSSM_INTC_CMR12)
ICSS_INTC_CMR13         .set    (CSL_ICSSM_INTC_CMR13)
ICSS_INTC_CMR14         .set    (CSL_ICSSM_INTC_CMR14)
ICSS_INTC_CMR15         .set    (CSL_ICSSM_INTC_CMR15)
ICSS_INTC_HMR0          .set    (CSL_ICSSM_INTC_HMR0)
ICSS_INTC_HMR1          .set    (CSL_ICSSM_INTC_HMR1)
ICSS_INTC_HMR2          .set    (CSL_ICSSM_INTC_HMR2)
ICSS_INTC_HIPIR0        .set    (CSL_ICSSM_INTC_HIPIR0)
ICSS_INTC_HIPIR1        .set    (CSL_ICSSM_INTC_HIPIR1)
ICSS_INTC_HIPIR2        .set    (CSL_ICSSM_INTC_HIPIR2)
ICSS_INTC_HIPIR3        .set    (CSL_ICSSM_INTC_HIPIR3)
ICSS_INTC_HIPIR4        .set    (CSL_ICSSM_INTC_HIPIR4)
ICSS_INTC_HIPIR5        .set    (CSL_ICSSM_INTC_HIPIR5)
ICSS_INTC_HIPIR6        .set    (CSL_ICSSM_INTC_HIPIR6)
ICSS_INTC_HIPIR7        .set    (CSL_ICSSM_INTC_HIPIR7)
ICSS_INTC_HIPIR8        .set    (CSL_ICSSM_INTC_HIPIR8)
ICSS_INTC_HIPIR9        .set    (CSL_ICSSM_INTC_HIPIR9)
ICSS_INTC_SIPR0         .set    (CSL_ICSSM_INTC_SIPR0)
ICSS_INTC_SIPR1         .set    (CSL_ICSSM_INTC_SIPR1)
ICSS_INTC_SITR0         .set    (CSL_ICSSM_INTC_SITR0)
ICSS_INTC_SITR1         .set    (CSL_ICSSM_INTC_SITR1)
ICSS_INTC_HINLR0        .set    (CSL_ICSSM_INTC_HINLR0)
ICSS_INTC_HINLR1        .set    (CSL_ICSSM_INTC_HINLR1)
ICSS_INTC_HINLR2        .set    (CSL_ICSSM_INTC_HINLR2)
ICSS_INTC_HINLR3        .set    (CSL_ICSSM_INTC_HINLR3)
ICSS_INTC_HINLR4        .set    (CSL_ICSSM_INTC_HINLR4)
ICSS_INTC_HINLR5        .set    (CSL_ICSSM_INTC_HINLR5)
ICSS_INTC_HINLR6        .set    (CSL_ICSSM_INTC_HINLR6)
ICSS_INTC_HINLR7        .set    (CSL_ICSSM_INTC_HINLR7)
ICSS_INTC_HINLR8        .set    (CSL_ICSSM_INTC_HINLR8)
ICSS_INTC_HINLR9        .set    (CSL_ICSSM_INTC_HINLR9)
ICSS_INTC_HIER          .set    (CSL_ICSSM_INTC_HIER)
    .endif    ;ICSS_REV1

    .if $defined("ICSS_REV2")
ICSS_INTC_REVID         .set    (CSL_ICSSINTC_REVID)
ICSS_INTC_CR            .set    (CSL_ICSSINTC_CR)
ICSS_INTC_GER           .set    (CSL_ICSSINTC_GER)
ICSS_INTC_GNLR          .set    (CSL_ICSSINTC_GNLR)
ICSS_INTC_SISR          .set    (CSL_ICSSINTC_SISR)
ICSS_INTC_SICR          .set    (CSL_ICSSINTC_SICR)
ICSS_INTC_EISR          .set    (CSL_ICSSINTC_EISR)
ICSS_INTC_EICR          .set    (CSL_ICSSINTC_EICR)
ICSS_INTC_HIEISR        .set    (CSL_ICSSINTC_HIEISR)
ICSS_INTC_HIDSR         .set    (CSL_ICSSINTC_HIDISR)
ICSS_INTC_GPIR          .set    (CSL_ICSSINTC_GPIR)
ICSS_INTC_SRSR0         .set    (CSL_ICSSINTC_SRSR0)
ICSS_INTC_SRSR1         .set    (CSL_ICSSINTC_SRSR1)
ICSS_INTC_SECR0         .set    (CSL_ICSSINTC_SECR0)
ICSS_INTC_SECR1         .set    (CSL_ICSSINTC_SECR1)
ICSS_INTC_ESR0          .set    (CSL_ICSSINTC_ESR0)
ICSS_INTC_ESR1          .set    (CSL_ICSSINTC_ERS1)
ICSS_INTC_ECR0          .set    (CSL_ICSSINTC_ECR0)
ICSS_INTC_ECR1          .set    (CSL_ICSSINTC_ECR1)
ICSS_INTC_CMR0          .set    (CSL_ICSSINTC_CMR0)
ICSS_INTC_CMR1          .set    (CSL_ICSSINTC_CMR1)
ICSS_INTC_CMR2          .set    (CSL_ICSSINTC_CMR2)
ICSS_INTC_CMR3          .set    (CSL_ICSSINTC_CMR3)
ICSS_INTC_CMR4          .set    (CSL_ICSSINTC_CMR4)
ICSS_INTC_CMR5          .set    (CSL_ICSSINTC_CMR5)
ICSS_INTC_CMR6          .set    (CSL_ICSSINTC_CMR6)
ICSS_INTC_CMR7          .set    (CSL_ICSSINTC_CMR7)
ICSS_INTC_CMR8          .set    (CSL_ICSSINTC_CMR8)
ICSS_INTC_CMR9          .set    (CSL_ICSSINTC_CMR9)
ICSS_INTC_CMR10         .set    (CSL_ICSSINTC_CMR10)
ICSS_INTC_CMR11         .set    (CSL_ICSSINTC_CMR11)
ICSS_INTC_CMR12         .set    (CSL_ICSSINTC_CMR12)
ICSS_INTC_CMR13         .set    (CSL_ICSSINTC_CMR13)
ICSS_INTC_CMR14         .set    (CSL_ICSSINTC_CMR14)
ICSS_INTC_CMR15         .set    (CSL_ICSSINTC_CMR15)
ICSS_INTC_HMR0          .set    (CSL_ICSSINTC_HMR0)
ICSS_INTC_HMR1          .set    (CSL_ICSSINTC_HMR1)
ICSS_INTC_HMR2          .set    (CSL_ICSSINTC_HMR2)
ICSS_INTC_HIPIR0        .set    (CSL_ICSSINTC_HIPIR0)
ICSS_INTC_HIPIR1        .set    (CSL_ICSSINTC_HIPIR1)
ICSS_INTC_HIPIR2        .set    (CSL_ICSSINTC_HIPIR2)
ICSS_INTC_HIPIR3        .set    (CSL_ICSSINTC_HIPIR3)
ICSS_INTC_HIPIR4        .set    (CSL_ICSSINTC_HIPIR4)
ICSS_INTC_HIPIR5        .set    (CSL_ICSSINTC_HIPIR5)
ICSS_INTC_HIPIR6        .set    (CSL_ICSSINTC_HIPIR6)
ICSS_INTC_HIPIR7        .set    (CSL_ICSSINTC_HIPIR7)
ICSS_INTC_HIPIR8        .set    (CSL_ICSSINTC_HIPIR8)
ICSS_INTC_HIPIR9        .set    (CSL_ICSSINTC_HIPIR9)
ICSS_INTC_SIPR0         .set    (CSL_ICSSINTC_SIPR0)
ICSS_INTC_SIPR1         .set    (CSL_ICSSINTC_SIPR1)
ICSS_INTC_SITR0         .set    (CSL_ICSSINTC_SITR0)
ICSS_INTC_SITR1         .set    (CSL_ICSSINTC_SITR1)
ICSS_INTC_HINLR0        .set    (CSL_ICSSINTC_HINLR0)
ICSS_INTC_HINLR1        .set    (CSL_ICSSINTC_HINLR1)
ICSS_INTC_HINLR2        .set    (CSL_ICSSINTC_HINLR2)
ICSS_INTC_HINLR3        .set    (CSL_ICSSINTC_HINLR3)
ICSS_INTC_HINLR4        .set    (CSL_ICSSINTC_HINLR4)
ICSS_INTC_HINLR5        .set    (CSL_ICSSINTC_HINLR5)
ICSS_INTC_HINLR6        .set    (CSL_ICSSINTC_HINLR6)
ICSS_INTC_HINLR7        .set    (CSL_ICSSINTC_HINLR7)
ICSS_INTC_HINLR8        .set    (CSL_ICSSINTC_HINLR8)
ICSS_INTC_HINLR9        .set    (CSL_ICSSINTC_HINLR9)
ICSS_INTC_HIER          .set    (CSL_ICSSINTC_HIER)
    .endif    ;ICSS_REV2

    .endif	;__icss_intc_regs_h

