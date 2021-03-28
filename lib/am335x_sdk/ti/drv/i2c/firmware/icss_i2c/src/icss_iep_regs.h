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
; file:   icss_iep_regs.h
;
; brief:  ICSS Industrial Ethernet Peripheral Registers
;
;
;  (C) Copyright 2017-2018, Texas Instruments, Inc
;
;
	
	.if !$defined("__icss_iep_regs_h")
__icss_iep_regs_h	.set	1	

    .cdecls C,NOLIST
%{
#include "cslr_icss.h"
%}


ICSS_IEP_TIMER_BLK_INDEX           .set    0    

    .if $defined("ICSS_REV1")        
ICSS_IEP_GLOBAL_CFG_REG           .set    (CSL_ICSSM_IEP_GLOBAL_CFG)
ICSS_IEP_GLOBAL_STATUS_REG        .set    (CSL_ICSSM_IEP_GLOBAL_STATUS)
ICSS_IEP_COMPEN_REG               .set    (CSL_ICSSM_IEP_COMPEN)
ICSS_IEP_COUNT_REG                .set    (CSL_ICSSM_IEP_COUNT)
ICSS_IEP_CAP_CFG_REG              .set    (CSL_ICSSM_IEP_CAP_CFG)
ICSS_IEP_CAP_STATUS_REG           .set    (CSL_ICSSM_IEP_CAP_STATUS)
ICSS_IEP_CAPR0_REG                .set    (CSL_ICSSM_IEP_CAPR0)
ICSS_IEP_CAPR1_REG                .set    (CSL_ICSSM_IEP_CAPR1)
ICSS_IEP_CAPR2_REG                .set    (CSL_ICSSM_IEP_CAPR2)
ICSS_IEP_CAPR3_REG                .set    (CSL_ICSSM_IEP_CAPR3)
ICSS_IEP_CAPR4_REG                .set    (CSL_ICSSM_IEP_CAPR4)
ICSS_IEP_CAPR5_REG                .set    (CSL_ICSSM_IEP_CAPR5)
ICSS_IEP_CAPR6_REG                .set    (CSL_ICSSM_IEP_CAPR6)
ICSS_IEP_CAPF6_REG                .set    (CSL_ICSSM_IEP_CAPF6)
ICSS_IEP_CAPR7_REG                .set    (CSL_ICSSM_IEP_CAPR7)
ICSS_IEP_CAPF7_REG                .set    (CSL_ICSSM_IEP_CAPF7)
ICSS_IEP_CMP_CFG_REG              .set    (CSL_ICSSM_IEP_CMP_CFG)
ICSS_IEP_CMP_STATUS_REG           .set    (CSL_ICSSM_IEP_CMP_STATUS)
ICSS_IEP_CMP0_REG                 .set    (CSL_ICSSM_IEP_CMP0)
ICSS_IEP_CMP1_REG                 .set    (CSL_ICSSM_IEP_CMP1)
ICSS_IEP_CMP2_REG                 .set    (CSL_ICSSM_IEP_CMP2)
ICSS_IEP_CMP3_REG                 .set    (CSL_ICSSM_IEP_CMP3)
ICSS_IEP_CMP4_REG                 .set    (CSL_ICSSM_IEP_CMP4)
ICSS_IEP_CMP5_REG                 .set    (CSL_ICSSM_IEP_CMP5)
ICSS_IEP_CMP6_REG                 .set    (CSL_ICSSM_IEP_CMP6)
ICSS_IEP_CMP7_REG                 .set    (CSL_ICSSM_IEP_CMP7)
ICSS_IEP_RXIPG0_REG               .set    (CSL_ICSSM_IEP_RXIPG0)
ICSS_IEP_RXIPG1_REG               .set    (CSL_ICSSM_IEP_RXIPG1)
                        
ICSS_IEP_SYNC_BLK_INDEX           .set    (CSL_ICSSM_IEP_SYNC_CTRL >> 8)
ICSS_IEP_SYNC_CTRL_REG            .set    (CSL_ICSSM_IEP_SYNC_CTRL)
ICSS_IEP_SYNC_FIRST_STATUS_REG    .set    (CSL_ICSSM_IEP_SYNC_FIRST_STAT)
ICSS_IEP_SYNC0_STATUS_REG         .set    (CSL_ICSSM_IEP_SYNC0_STAT)
ICSS_IEP_SYNC1_STATUS_REG         .set    (CSL_ICSSM_IEP_SYNC1_STAT)
ICSS_IEP_SYNC_PWIDTH_REG          .set    (CSL_ICSSM_IEP_SYNC_PWIDTH)
ICSS_IEP_SYNC0_PERIOD_REG         .set    (CSL_ICSSM_IEP_SYNC0_PERIOD)
ICSS_IEP_SYNC1_DELAY_REG          .set    (CSL_ICSSM_IEP_SYNC1_DELAY)
ICSS_IEP_SYNC_START_REG           .set    (CSL_ICSSM_IEP_SYNC_START)
                        
ICSS_IEP_WD_BLK_INDEX             .set    (CSL_ICSSM_IEP_WD_PREDIV >> 8)
ICSS_IEP_WD_PREDIV_REG            .set    (CSL_ICSSM_IEP_WD_PREDIV)
ICSS_IEP_PDI_WD_TIM_REG           .set    (CSL_ICSSM_IEP_PDI_WD_TIM)
ICSS_IEP_PD_WD_TIM_REG            .set    (CSL_ICSSM_IEP_PD_WD_TIM)
ICSS_IEP_WD_STATUS_REG            .set    (CSL_ICSSM_IEP_WD_STATUS)
ICSS_IEP_EXP_COUNTER_REG          .set    (CSL_ICSSM_IEP_WD_EXP_CNT)
ICSS_IEP_WD_CTRL_REG              .set    (CSL_ICSSM_IEP_WD_CTRL)
                        
ICSS_IEP_DIGIO_BLK_INDEX          .set    (CSL_ICSSM_IEP_DIGIO_CTRL >> 8)
ICSS_IEP_DIGIO_CTRL_REG           .set    (CSL_ICSSM_IEP_DIGIO_CTRL)
ICSS_IEP_DIGIO_STATUS_REG         .set    (CSL_ICSSM_IEP_DIGIO_STATUS)
ICSS_IEP_DIGIO_DATA_IN_REG        .set    (CSL_ICSSM_IEP_DIGIO_DATA_IN)
ICSS_IEP_DIGIO_DATA_IN_RAW_REG    .set    (CSL_ICSSM_IEP_DIGIO_DATA_IN_RAW)
ICSS_IEP_DIGIO_DATA_OUT_REG       .set    (CSL_ICSSM_IEP_DIGIO_DATA_OUT)
ICSS_IEP_DIGIO_DATA_OUT_EN_REG    .set    (CSL_ICSSM_IEP_DIGIO_DATA_OUT_EN)
ICSS_IEP_DIGIO_EXP_REG            .set    (CSL_ICSSM_IEP_DIGIO_EXP)
    .endif    ;ICSS_REV1    

    .if $defined("ICSS_REV2")        
ICSS_IEP_GLOBAL_CFG_REG            .set    (CSL_ICSSIEP_GLOBAL_CFG_REG)
ICSS_IEP_GLOBAL_STATUS_REG         .set    (CSL_ICSSIEP_GLOBAL_STATUS_REG)
ICSS_IEP_COMPEN_REG                .set    (CSL_ICSSIEP_COMPEN_REG)
ICSS_IEP_SLOW_COMPEN_REG           .set    (CSL_ICSSIEP_SLOW_COMPEN_REG)
ICSS_IEP_COUNT_REG                 .set    (CSL_ICSSIEP_COUNT_REG0)
ICSS_IEP_COUNT_REG1                .set    (CSL_ICSSIEP_COUNT_REG1)
ICSS_IEP_CAP_CFG_REG               .set    (CSL_ICSSIEP_CAP_CFG_REG)
ICSS_IEP_CAP_STATUS_REG            .set    (CSL_ICSSIEP_CAP_STATUS_REG)
ICSS_IEP_CAPR0_REG                 .set    (CSL_ICSSIEP_CAPR0_REG0)
ICSS_IEP_CAPR0_REG1                .set    (CSL_ICSSIEP_CAPR0_REG1)
ICSS_IEP_CAPR1_REG                 .set    (CSL_ICSSIEP_CAPR1_REG0)
ICSS_IEP_CAPR1_REG1                .set    (CSL_ICSSIEP_CAPR1_REG1)
ICSS_IEP_CAPR2_REG                 .set    (CSL_ICSSIEP_CAPR2_REG0)
ICSS_IEP_CAPR2_REG1                .set    (CSL_ICSSIEP_CAPR2_REG1)
ICSS_IEP_CAPR3_REG                 .set    (CSL_ICSSIEP_CAPR3_REG0)
ICSS_IEP_CAPR3_REG1                .set    (CSL_ICSSIEP_CAPR3_REG1)
ICSS_IEP_CAPR4_REG                 .set    (CSL_ICSSIEP_CAPR4_REG0)
ICSS_IEP_CAPR4_REG1                .set    (CSL_ICSSIEP_CAPR4_REG1)
ICSS_IEP_CAPR5_REG                 .set    (CSL_ICSSIEP_CAPR5_REG0)
ICSS_IEP_CAPR5_REG1                .set    (CSL_ICSSIEP_CAPR5_REG1)
ICSS_IEP_CAPR6_REG                 .set    (CSL_ICSSIEP_CAPR6_REG0)
ICSS_IEP_CAPR6_REG1                .set    (CSL_ICSSIEP_CAPR6_REG1)
ICSS_IEP_CAPF6_REG                 .set    (CSL_ICSSIEP_CAPF6_REG0)
ICSS_IEP_CAPF6_REG1                .set    (CSL_ICSSIEP_CAPF6_REG1)
ICSS_IEP_CAPR7_REG                 .set    (CSL_ICSSIEP_CAPR7_REG0)
ICSS_IEP_CAPR7_REG1                .set    (CSL_ICSSIEP_CAPR7_REG1)
ICSS_IEP_CAPF7_REG                 .set    (CSL_ICSSIEP_CAPF7_REG0)
ICSS_IEP_CAPF7_REG1                .set    (CSL_ICSSIEP_CAPF7_REG1)
ICSS_IEP_CMP_CFG_REG               .set    (CSL_ICSSIEP_CMP_CFG_REG)
ICSS_IEP_CMP_STATUS_REG            .set    (CSL_ICSSIEP_CMP_STATUS_REG)
ICSS_IEP_CMP0_REG                  .set    (CSL_ICSSIEP_CMP0_REG0)
ICSS_IEP_CMP0_REG1                 .set    (CSL_ICSSIEP_CMP0_REG1)
ICSS_IEP_CMP1_REG                  .set    (CSL_ICSSIEP_CMP1_REG0)
ICSS_IEP_CMP1_REG1                 .set    (CSL_ICSSIEP_CMP1_REG1)
ICSS_IEP_CMP2_REG                  .set    (CSL_ICSSIEP_CMP2_REG0)
ICSS_IEP_CMP2_REG1                 .set    (CSL_ICSSIEP_CMP2_REG1)
ICSS_IEP_CMP3_REG                  .set    (CSL_ICSSIEP_CMP3_REG0)
ICSS_IEP_CMP3_REG1                 .set    (CSL_ICSSIEP_CMP3_REG1)
ICSS_IEP_CMP4_REG                  .set    (CSL_ICSSIEP_CMP4_REG0)
ICSS_IEP_CMP4_REG1                 .set    (CSL_ICSSIEP_CMP4_REG1)
ICSS_IEP_CMP5_REG                  .set    (CSL_ICSSIEP_CMP5_REG0)
ICSS_IEP_CMP5_REG1                 .set    (CSL_ICSSIEP_CMP5_REG1)
ICSS_IEP_CMP6_REG                  .set    (CSL_ICSSIEP_CMP6_REG0)
ICSS_IEP_CMP6_REG1                 .set    (CSL_ICSSIEP_CMP6_REG1)
ICSS_IEP_CMP7_REG                  .set    (CSL_ICSSIEP_CMP7_REG0)
ICSS_IEP_CMP7_REG1                 .set    (CSL_ICSSIEP_CMP7_REG1)
ICSS_IEP_RXIPG0_REG                .set    (CSL_ICSSIEP_RXIPG0_REG)
ICSS_IEP_RXIPG1_REG                .set    (CSL_ICSSIEP_RXIPG1_REG)
ICSS_IEP_CMP8_REG                  .set    (CSL_ICSSIEP_CMP8_REG0)
ICSS_IEP_CMP8_REG1                 .set    (CSL_ICSSIEP_CMP8_REG1)
ICSS_IEP_CMP9_REG                  .set    (CSL_ICSSIEP_CMP9_REG0)
ICSS_IEP_CMP9_REG1                 .set    (CSL_ICSSIEP_CMP9_REG1)
ICSS_IEP_CMP10_REG                 .set    (CSL_ICSSIEP_CMP10_REG0)
ICSS_IEP_CMP10_REG1                .set    (CSL_ICSSIEP_CMP10_REG1)
ICSS_IEP_CMP11_REG                 .set    (CSL_ICSSIEP_CMP11_REG0)
ICSS_IEP_CMP11_REG1                .set    (CSL_ICSSIEP_CMP11_REG1)
ICSS_IEP_CMP12_REG                 .set    (CSL_ICSSIEP_CMP12_REG0)
ICSS_IEP_CMP12_REG1                .set    (CSL_ICSSIEP_CMP12_REG1)
ICSS_IEP_CMP13_REG                 .set    (CSL_ICSSIEP_CMP13_REG0)
ICSS_IEP_CMP13_REG1                .set    (CSL_ICSSIEP_CMP13_REG1)
ICSS_IEP_CMP14_REG                 .set    (CSL_ICSSIEP_CMP14_REG0)
ICSS_IEP_CMP14_REG1                .set    (CSL_ICSSIEP_CMP14_REG1)
ICSS_IEP_CMP15_REG                 .set    (CSL_ICSSIEP_CMP15_REG0)
ICSS_IEP_CMP15_REG1                .set    (CSL_ICSSIEP_CMP15_REG1)
ICSS_IEP_COUNT_RESET_VAL_REG       .set    (CSL_ICSSIEP_COUNT_RESET_VAL_REG0)
ICSS_IEP_COUNT_RESET_VAL_REG1      .set    (CSL_ICSSIEP_COUNT_RESET_VAL_REG1)
ICSS_IEP_PWM_REG                   .set    (CSL_ICSSIEP_PWM_REG)
                        
ICSS_IEP_SYNC_BLK_INDEX            .set    (CSL_ICSSIEP_SYNC_CTRL_REG >> 8)
ICSS_IEP_SYNC_CTRL_REG             .set    (CSL_ICSSIEP_SYNC_CTRL_REG)
ICSS_IEP_SYNC_FIRST_STATUS_REG     .set    (CSL_ICSSIEP_SYNC_FIRST_STAT_REG)
ICSS_IEP_SYNC0_STATUS_REG          .set    (CSL_ICSSIEP_SYNC0_STAT_REG)
ICSS_IEP_SYNC1_STATUS_REG          .set    (CSL_ICSSIEP_SYNC1_STAT_REG)
ICSS_IEP_SYNC_PWIDTH_REG           .set    (CSL_ICSSIEP_SYNC_PWIDTH_REG)
ICSS_IEP_SYNC0_PERIOD_REG          .set    (CSL_ICSSIEP_SYNC0_PERIOD_REG)
ICSS_IEP_SYNC1_DELAY_REG           .set    (CSL_ICSSIEP_SYNC1_DELAY_REG)
ICSS_IEP_SYNC_START_REG            .set    (CSL_ICSSIEP_SYNC_START_REG)
                                   
ICSS_IEP_WD_BLK_INDEX              .set    (CSL_ICSSIEP_WD_PREDIV_REG >> 8)
ICSS_IEP_WD_PREDIV_REG             .set    (CSL_ICSSIEP_WD_PREDIV_REG)
ICSS_IEP_PDI_WD_TIM_REG            .set    (CSL_ICSSIEP_PDI_WD_TIM_REG)
ICSS_IEP_PD_WD_TIM_REG             .set    (CSL_ICSSIEP_PD_WD_TIM_REG)
ICSS_IEP_WD_STATUS_REG             .set    (CSL_ICSSIEP_WD_STATUS_REG)
ICSS_IEP_EXP_COUNTER_REG           .set    (CSL_ICSSIEP_WD_EXP_CNT_REG)
ICSS_IEP_WD_CTRL_REG               .set    (CSL_ICSSIEP_WD_CTRL_REG)
                        
ICSS_IEP_DIGIO_BLK_INDEX           .set    (CSL_ICSSIEP_DIGIO_CTRL_REG >> 8)
ICSS_IEP_DIGIO_CTRL_REG            .set    (CSL_ICSSIEP_DIGIO_CTRL_REG)
ICSS_IEP_DIGIO_STATUS_REG          .set    (CSL_ICSSIEP_DIGIO_STATUS_REG)
ICSS_IEP_DIGIO_DATA_IN_REG         .set    (CSL_ICSSIEP_DIGIO_DATA_IN_REG)
ICSS_IEP_DIGIO_DATA_IN_RAW_REG     .set    (CSL_ICSSIEP_DIGIO_DATA_IN_RAW_REG)
ICSS_IEP_DIGIO_DATA_OUT_REG        .set    (CSL_ICSSIEP_DIGIO_DATA_OUT_REG)
ICSS_IEP_DIGIO_DATA_OUT_EN_REG     .set    (CSL_ICSSIEP_DIGIO_DATA_OUT_EN_REG)
ICSS_IEP_DIGIO_EXP_REG             .set    (CSL_ICSSIEP_DIGIO_EXP_REG)
    .endif    ;ICSS_REV2    

	.endif	;__icss_iep_regs_h
