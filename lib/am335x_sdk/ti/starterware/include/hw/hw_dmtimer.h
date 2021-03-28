/*
* hw_dmtimer.h
*
* Register-level header file for DMTIMER
*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/ 
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

#ifndef HW_DMTIMER_H_
#define HW_DMTIMER_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions 
****************************************************************************************************/

#define DMTIMER_TIDR                                                (0x0U)
#define DMTIMER_TIOCP_CFG                                           (0x10U)
#define DMTIMER_IRQ_EOI                                             (0x20U)
#define DMTIMER_IRQSTS_RAW                                          (0x24U)
#define DMTIMER_IRQSTS                                              (0x28U)
#define DMTIMER_IRQEN_SET                                           (0x2cU)
#define DMTIMER_IRQEN_CLR                                           (0x30U)
#define DMTIMER_IRQWAKEEN                                           (0x34U)
#define DMTIMER_TCLR                                                (0x38U)
#define DMTIMER_TCRR                                                (0x3cU)
#define DMTIMER_TLDR                                                (0x40U)
#define DMTIMER_TTGR                                                (0x44U)
#define DMTIMER_TWPS                                                (0x48U)
#define DMTIMER_TMAR                                                (0x4cU)
#define DMTIMER_TCAR1                                               (0x50U)
#define DMTIMER_TSICR                                               (0x54U)
#define DMTIMER_TCAR2                                               (0x58U)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define DMTIMER_TIDR_X_MAJOR_SHIFT                                                      (8U)
#define DMTIMER_TIDR_X_MAJOR_MASK                                                       (0x00000700U)

#define DMTIMER_TIDR_Y_MINOR_SHIFT                                                      (0U)
#define DMTIMER_TIDR_Y_MINOR_MASK                                                       (0x0000003fU)

#define DMTIMER_TIDR_CUSTOM_SHIFT                                                       (6U)
#define DMTIMER_TIDR_CUSTOM_MASK                                                        (0x000000c0U)

#define DMTIMER_TIDR_R_RTL_SHIFT                                                        (11U)
#define DMTIMER_TIDR_R_RTL_MASK                                                         (0x0000f800U)

#define DMTIMER_TIDR_FUNC_SHIFT                                                         (16U)
#define DMTIMER_TIDR_FUNC_MASK                                                          (0x0fff0000U)

#define DMTIMER_TIDR_SCHEME_SHIFT                                                       (30U)
#define DMTIMER_TIDR_SCHEME_MASK                                                        (0xc0000000U)
#define DMTIMER_TIDR_SCHEME_LEGACY                                                       (0U)
#define DMTIMER_TIDR_SCHEME_HIGHLANDER0P8                                                (1U)

#define DMTIMER_TIOCP_CFG_EMUFREE_SHIFT                                                 (1U)
#define DMTIMER_TIOCP_CFG_EMUFREE_MASK                                                  (0x00000002U)
#define DMTIMER_TIOCP_CFG_EMUFREE_TIMER_FROZEN                                           (0U)
#define DMTIMER_TIOCP_CFG_EMUFREE_TIMER_FREE                                             (1U)

#define DMTIMER_TIOCP_CFG_IDLEMODE_SHIFT                                                (2U)
#define DMTIMER_TIOCP_CFG_IDLEMODE_MASK                                                 (0x0000000cU)
#define DMTIMER_TIOCP_CFG_IDLEMODE_FORCEIDLE                                             (0U)
#define DMTIMER_TIOCP_CFG_IDLEMODE_NOIDLE                                                (1U)
#define DMTIMER_TIOCP_CFG_IDLEMODE_SMARTIDLE                                             (2U)
#define DMTIMER_TIOCP_CFG_IDLEMODE_SMARTWAKEUP                                           (3U)

#define DMTIMER_TIOCP_CFG_SOFTRESET_SHIFT                                               (0U)
#define DMTIMER_TIOCP_CFG_SOFTRESET_MASK                                                (0x00000001U)
#define DMTIMER_TIOCP_CFG_SOFTRESET_DONE                                                 (0U)
#define DMTIMER_TIOCP_CFG_SOFTRESET_ONGOING                                              (1U)
#define DMTIMER_TIOCP_CFG_SOFTRESET_INITIATE                                             (1U)

#define DMTIMER_IRQ_EOI_LINE_NUMBER_SHIFT                                               (0U)
#define DMTIMER_IRQ_EOI_LINE_NUMBER_MASK                                                (0x00000001U)

#define DMTIMER_IRQSTS_RAW_MAT_IT_FLAG_SHIFT                                            (0U)
#define DMTIMER_IRQSTS_RAW_MAT_IT_FLAG_MASK                                             (0x00000001U)
#define DMTIMER_IRQSTS_RAW_MAT_IT_FLAG_NONE                                              (0U)
#define DMTIMER_IRQSTS_RAW_MAT_IT_FLAG_PENDING                                           (1U)
#define DMTIMER_IRQSTS_RAW_MAT_IT_FLAG_SET                                               (1U)

#define DMTIMER_IRQSTS_RAW_OVF_IT_FLAG_SHIFT                                            (1U)
#define DMTIMER_IRQSTS_RAW_OVF_IT_FLAG_MASK                                             (0x00000002U)
#define DMTIMER_IRQSTS_RAW_OVF_IT_FLAG_NONE                                              (0U)
#define DMTIMER_IRQSTS_RAW_OVF_IT_FLAG_PENDING                                           (1U)
#define DMTIMER_IRQSTS_RAW_OVF_IT_FLAG_SET                                               (1U)

#define DMTIMER_IRQSTS_RAW_TCAR_IT_FLAG_SHIFT                                           (2U)
#define DMTIMER_IRQSTS_RAW_TCAR_IT_FLAG_MASK                                            (0x00000004U)
#define DMTIMER_IRQSTS_RAW_TCAR_IT_FLAG_NONE                                             (0U)
#define DMTIMER_IRQSTS_RAW_TCAR_IT_FLAG_PENDING                                          (1U)
#define DMTIMER_IRQSTS_RAW_TCAR_IT_FLAG_SET                                              (1U)

#define DMTIMER_IRQSTS_MAT_IT_FLAG_SHIFT                                                (0U)
#define DMTIMER_IRQSTS_MAT_IT_FLAG_MASK                                                 (0x00000001U)
#define DMTIMER_IRQSTS_MAT_IT_FLAG_NONE                                                  (0U)
#define DMTIMER_IRQSTS_MAT_IT_FLAG_PENDING                                               (1U)
#define DMTIMER_IRQSTS_MAT_IT_FLAG_CLEAR                                                 (1U)

#define DMTIMER_IRQSTS_OVF_IT_FLAG_SHIFT                                                (1U)
#define DMTIMER_IRQSTS_OVF_IT_FLAG_MASK                                                 (0x00000002U)
#define DMTIMER_IRQSTS_OVF_IT_FLAG_NONE                                                  (0U)
#define DMTIMER_IRQSTS_OVF_IT_FLAG_PENDING                                               (1U)
#define DMTIMER_IRQSTS_OVF_IT_FLAG_CLEAR                                                 (1U)

#define DMTIMER_IRQSTS_TCAR_IT_FLAG_SHIFT                                               (2U)
#define DMTIMER_IRQSTS_TCAR_IT_FLAG_MASK                                                (0x00000004U)
#define DMTIMER_IRQSTS_TCAR_IT_FLAG_NONE                                                 (0U)
#define DMTIMER_IRQSTS_TCAR_IT_FLAG_PENDING                                              (1U)
#define DMTIMER_IRQSTS_TCAR_IT_FLAG_CLEAR                                                (1U)

#define DMTIMER_IRQEN_SET_MAT_EN_FLAG_SHIFT                                             (0U)
#define DMTIMER_IRQEN_SET_MAT_EN_FLAG_MASK                                              (0x00000001U)
#define DMTIMER_IRQEN_SET_MAT_EN_FLAG_DISABLED                                           (0U)
#define DMTIMER_IRQEN_SET_MAT_EN_FLAG_ENABLED                                            (1U)
#define DMTIMER_IRQEN_SET_MAT_EN_FLAG_ENABLE                                             (1U)

#define DMTIMER_IRQEN_SET_OVF_EN_FLAG_SHIFT                                             (1U)
#define DMTIMER_IRQEN_SET_OVF_EN_FLAG_MASK                                              (0x00000002U)
#define DMTIMER_IRQEN_SET_OVF_EN_FLAG_DISABLED                                           (0U)
#define DMTIMER_IRQEN_SET_OVF_EN_FLAG_ENABLED                                            (1U)
#define DMTIMER_IRQEN_SET_OVF_EN_FLAG_ENABLE                                             (1U)

#define DMTIMER_IRQEN_SET_TCAR_EN_FLAG_SHIFT                                            (2U)
#define DMTIMER_IRQEN_SET_TCAR_EN_FLAG_MASK                                             (0x00000004U)
#define DMTIMER_IRQEN_SET_TCAR_EN_FLAG_DISABLED                                          (0U)
#define DMTIMER_IRQEN_SET_TCAR_EN_FLAG_ENABLED                                           (1U)
#define DMTIMER_IRQEN_SET_TCAR_EN_FLAG_ENABLE                                            (1U)

#define DMTIMER_IRQEN_CLR_MAT_EN_FLAG_SHIFT                                             (0U)
#define DMTIMER_IRQEN_CLR_MAT_EN_FLAG_MASK                                              (0x00000001U)
#define DMTIMER_IRQEN_CLR_MAT_EN_FLAG_DISABLED                                           (0U)
#define DMTIMER_IRQEN_CLR_MAT_EN_FLAG_ENABLED                                            (1U)
#define DMTIMER_IRQEN_CLR_MAT_EN_FLAG_ENABLE                                             (1U)

#define DMTIMER_IRQEN_CLR_OVF_EN_FLAG_SHIFT                                             (1U)
#define DMTIMER_IRQEN_CLR_OVF_EN_FLAG_MASK                                              (0x00000002U)
#define DMTIMER_IRQEN_CLR_OVF_EN_FLAG_DISABLED                                           (0U)
#define DMTIMER_IRQEN_CLR_OVF_EN_FLAG_ENABLED                                            (1U)
#define DMTIMER_IRQEN_CLR_OVF_EN_FLAG_ENABLE                                             (1U)

#define DMTIMER_IRQEN_CLR_TCAR_EN_FLAG_SHIFT                                            (2U)
#define DMTIMER_IRQEN_CLR_TCAR_EN_FLAG_MASK                                             (0x00000004U)
#define DMTIMER_IRQEN_CLR_TCAR_EN_FLAG_DISABLED                                          (0U)
#define DMTIMER_IRQEN_CLR_TCAR_EN_FLAG_ENABLED                                           (1U)
#define DMTIMER_IRQEN_CLR_TCAR_EN_FLAG_ENABLE                                            (1U)

#define DMTIMER_IRQWAKEEN_MAT_WUP_ENA_SHIFT                                             (0U)
#define DMTIMER_IRQWAKEEN_MAT_WUP_ENA_MASK                                              (0x00000001U)
#define DMTIMER_IRQWAKEEN_MAT_WUP_ENA_DISABLE                                            (0U)
#define DMTIMER_IRQWAKEEN_MAT_WUP_ENA_ENABLE                                             (1U)

#define DMTIMER_IRQWAKEEN_OVF_WUP_ENA_SHIFT                                             (1U)
#define DMTIMER_IRQWAKEEN_OVF_WUP_ENA_MASK                                              (0x00000002U)
#define DMTIMER_IRQWAKEEN_OVF_WUP_ENA_DISABLE                                            (0U)
#define DMTIMER_IRQWAKEEN_OVF_WUP_ENA_ENABLE                                             (1U)

#define DMTIMER_IRQWAKEEN_TCAR_WUP_ENA_SHIFT                                            (2U)
#define DMTIMER_IRQWAKEEN_TCAR_WUP_ENA_MASK                                             (0x00000004U)
#define DMTIMER_IRQWAKEEN_TCAR_WUP_ENA_DISABLE                                           (0U)
#define DMTIMER_IRQWAKEEN_TCAR_WUP_ENA_ENABLE                                            (1U)

#define DMTIMER_TCLR_TCM_SHIFT                                                          (8U)
#define DMTIMER_TCLR_TCM_MASK                                                           (0x00000300U)
#define DMTIMER_TCLR_TCM_NOCAPTURE                                                       (0U)
#define DMTIMER_TCLR_TCM_CAPT_LOWHIGH                                                    (1U)
#define DMTIMER_TCLR_TCM_CAPT_HIGHLOW                                                    (2U)
#define DMTIMER_TCLR_TCM_CAPT_BOTH                                                       (3U)

#define DMTIMER_TCLR_ST_SHIFT                                                           (0U)
#define DMTIMER_TCLR_ST_MASK                                                            (0x00000001U)
#define DMTIMER_TCLR_ST_STOP                                                             (0U)
#define DMTIMER_TCLR_ST_START                                                            (1U)

#define DMTIMER_TCLR_PTV_SHIFT                                                          (2U)
#define DMTIMER_TCLR_PTV_MASK                                                           (0x0000001cU)

#define DMTIMER_TCLR_CE_SHIFT                                                           (6U)
#define DMTIMER_TCLR_CE_MASK                                                            (0x00000040U)
#define DMTIMER_TCLR_CE_DISABLE                                                          (0U)
#define DMTIMER_TCLR_CE_ENABLE                                                           (1U)

#define DMTIMER_TCLR_AR_SHIFT                                                           (1U)
#define DMTIMER_TCLR_AR_MASK                                                            (0x00000002U)
#define DMTIMER_TCLR_AR_AUTO                                                             (1U)
#define DMTIMER_TCLR_AR_ONESHOT                                                          (0U)

#define DMTIMER_TCLR_CAPT_MODE_SHIFT                                                    (13U)
#define DMTIMER_TCLR_CAPT_MODE_MASK                                                     (0x00002000U)
#define DMTIMER_TCLR_CAPT_MODE_SINGLE                                                    (0U)
#define DMTIMER_TCLR_CAPT_MODE_SECOND                                                    (1U)

#define DMTIMER_TCLR_TRG_SHIFT                                                          (10U)
#define DMTIMER_TCLR_TRG_MASK                                                           (0x00000c00U)
#define DMTIMER_TCLR_TRG_NOTRIGGER                                                       (0U)
#define DMTIMER_TCLR_TRG_OVERFLOW                                                        (1U)
#define DMTIMER_TCLR_TRG_OVERFLOWANDMATCH                                                (2U)

#define DMTIMER_TCLR_PT_SHIFT                                                           (12U)
#define DMTIMER_TCLR_PT_MASK                                                            (0x00001000U)
#define DMTIMER_TCLR_PT_PULSE                                                            (0U)
#define DMTIMER_TCLR_PT_TOGGLE                                                           (1U)

#define DMTIMER_TCLR_SCPWM_SHIFT                                                        (7U)
#define DMTIMER_TCLR_SCPWM_MASK                                                         (0x00000080U)
#define DMTIMER_TCLR_SCPWM_CLEAR                                                         (0U)
#define DMTIMER_TCLR_SCPWM_SET                                                           (1U)

#define DMTIMER_TCLR_PRE_SHIFT                                                          (5U)
#define DMTIMER_TCLR_PRE_MASK                                                           (0x00000020U)
#define DMTIMER_TCLR_PRE_DISABLE                                                         (0U)
#define DMTIMER_TCLR_PRE_ENABLE                                                          (1U)

#define DMTIMER_TCLR_GPO_CFG_SHIFT                                                      (14U)
#define DMTIMER_TCLR_GPO_CFG_MASK                                                       (0x00004000U)
#define DMTIMER_TCLR_GPO_CFG_DRIVE0                                                      (0U)
#define DMTIMER_TCLR_GPO_CFG_DRIVE1                                                      (1U)

#define DMTIMER_TCLR_IODIRECTION_SHIFT                                                  (14U)
#define DMTIMER_TCLR_IODIRECTION_MASK                                                   (0x00004000U)
#define DMTIMER_TCLR_IODIRECTION_OUTPUT                                                  (0U)
#define DMTIMER_TCLR_IODIRECTION_INPUT                                                   (1U)

#define DMTIMER_TCRR_TIMER_CTR_SHIFT                                                    (0U)
#define DMTIMER_TCRR_TIMER_CTR_MASK                                                     (0xffffffffU)

#define DMTIMER_TLDR_LOAD_VALUE_SHIFT                                                   (0U)
#define DMTIMER_TLDR_LOAD_VALUE_MASK                                                    (0xffffffffU)

#define DMTIMER_TTGR_VALUE_SHIFT                                                        (0U)
#define DMTIMER_TTGR_VALUE_MASK                                                         (0xffffffffU)

#define DMTIMER_TWPS_W_PEND_TMAR_SHIFT                                                  (4U)
#define DMTIMER_TWPS_W_PEND_TMAR_MASK                                                   (0x00000010U)
#define DMTIMER_TWPS_W_PEND_TMAR_NONE                                                    (0U)
#define DMTIMER_TWPS_W_PEND_TMAR_PENDING                                                 (1U)

#define DMTIMER_TWPS_W_PEND_TCRR_SHIFT                                                  (1U)
#define DMTIMER_TWPS_W_PEND_TCRR_MASK                                                   (0x00000002U)
#define DMTIMER_TWPS_W_PEND_TCRR_NONE                                                    (0U)
#define DMTIMER_TWPS_W_PEND_TCRR_PENDING                                                 (1U)

#define DMTIMER_TWPS_W_PEND_TTGR_SHIFT                                                  (3U)
#define DMTIMER_TWPS_W_PEND_TTGR_MASK                                                   (0x00000008U)
#define DMTIMER_TWPS_W_PEND_TTGR_NONE                                                    (0U)
#define DMTIMER_TWPS_W_PEND_TTGR_PENDING                                                 (1U)

#define DMTIMER_TWPS_W_PEND_TCLR_SHIFT                                                  (0U)
#define DMTIMER_TWPS_W_PEND_TCLR_MASK                                                   (0x00000001U)
#define DMTIMER_TWPS_W_PEND_TCLR_NONE                                                    (0U)
#define DMTIMER_TWPS_W_PEND_TCLR_PENDING                                                 (1U)

#define DMTIMER_TWPS_W_PEND_TLDR_SHIFT                                                  (2U)
#define DMTIMER_TWPS_W_PEND_TLDR_MASK                                                   (0x00000004U)
#define DMTIMER_TWPS_W_PEND_TLDR_NONE                                                    (0U)
#define DMTIMER_TWPS_W_PEND_TLDR_PENDING                                                 (1U)

#define DMTIMER_TMAR_COMPARE_VALUE_SHIFT                                                (0U)
#define DMTIMER_TMAR_COMPARE_VALUE_MASK                                                 (0xffffffffU)

#define DMTIMER_TCAR1_CAPTURED_VALUE_SHIFT                                              (0U)
#define DMTIMER_TCAR1_CAPTURED_VALUE_MASK                                               (0xffffffffU)

#define DMTIMER_TSICR_POSTED_SHIFT                                                      (2U)
#define DMTIMER_TSICR_POSTED_MASK                                                       (0x00000004U)
#define DMTIMER_TSICR_POSTED_INACTIVE                                                    (0U)
#define DMTIMER_TSICR_POSTED_ACTIVE                                                      (1U)

#define DMTIMER_TSICR_SFT_SHIFT                                                         (1U)
#define DMTIMER_TSICR_SFT_MASK                                                          (0x00000002U)
#define DMTIMER_TSICR_SFT_RESETDISABLE                                                   (0U)
#define DMTIMER_TSICR_SFT_RESETENABLE                                                    (1U)

#define DMTIMER_TCAR2_CAPTURED_VALUE_SHIFT                                              (0U)
#define DMTIMER_TCAR2_CAPTURED_VALUE_MASK                                               (0xffffffffU)

#ifdef __cplusplus
}
#endif
#endif  /* HW_DMTIMER_H_ */

