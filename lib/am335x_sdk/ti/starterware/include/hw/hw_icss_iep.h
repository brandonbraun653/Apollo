/*
* hw_icss_iep.h
*
* Register-level header file for HW_ICSS_IEP
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
#ifndef HW_ICSS_IEP_H_
#define HW_ICSS_IEP_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define HW_ICSS_IEP_GLOBAL_CFG                                 (0x0U)
#define HW_ICSS_IEP_GLOBAL_STATUS                              (0x4U)
#define HW_ICSS_IEP_COMPEN                                     (0x8U)
#define HW_ICSS_IEP_COUNT                                      (0xcU)
#define HW_ICSS_IEP_CAP_CFG                                    (0x10U)
#define HW_ICSS_IEP_CAP_STATUS                                 (0x14U)
#define HW_ICSS_IEP_CAPR0                                      (0x18U)
#define HW_ICSS_IEP_CAPR1                                      (0x1cU)
#define HW_ICSS_IEP_CAPR2                                      (0x20U)
#define HW_ICSS_IEP_CAPR3                                      (0x24U)
#define HW_ICSS_IEP_CAPR4                                      (0x28U)
#define HW_ICSS_IEP_CAPR5                                      (0x2cU)
#define HW_ICSS_IEP_CAPR6                                      (0x30U)
#define HW_ICSS_IEP_CAPF6                                      (0x34U)
#define HW_ICSS_IEP_CAPR7                                      (0x38U)
#define HW_ICSS_IEP_CAPF7                                      (0x3cU)
#define HW_ICSS_IEP_CMP_CFG                                    (0x40U)
#define HW_ICSS_IEP_CMP_STATUS                                 (0x44U)
#define HW_ICSS_IEP_CMP0                                       (0x48U)
#define HW_ICSS_IEP_CMP1                                       (0x4cU)
#define HW_ICSS_IEP_CMP2                                       (0x50U)
#define HW_ICSS_IEP_CMP3                                       (0x54U)
#define HW_ICSS_IEP_CMP4                                       (0x58U)
#define HW_ICSS_IEP_CMP5                                       (0x5cU)
#define HW_ICSS_IEP_CMP6                                       (0x60U)
#define HW_ICSS_IEP_CMP7                                       (0x64U)
#define HW_ICSS_IEP_RXIPG0                                     (0x80U)
#define HW_ICSS_IEP_RXIPG1                                     (0x84U)
#define HW_ICSS_IEP_CMP8                                       (0x88U)
#define HW_ICSS_IEP_CMP9                                       (0x8cU)
#define HW_ICSS_IEP_CMP10                                      (0x90U)
#define HW_ICSS_IEP_CMP11                                      (0x94U)
#define HW_ICSS_IEP_CMP12                                      (0x98U)
#define HW_ICSS_IEP_CMP13                                      (0x9cU)
#define HW_ICSS_IEP_CMP14                                      (0xa0U)
#define HW_ICSS_IEP_CMP15                                      (0xa4U)
#define HW_ICSS_IEP_COUNT_RESET                                (0xa8U)
#define HW_ICSS_IEP_PWM                                        (0xacU)
#define HW_ICSS_IEP_SYNC_CTRL                                  (0x100U)
#define HW_ICSS_IEP_SYNC_FIRST_STAT                            (0x104U)
#define HW_ICSS_IEP_SYNC0_STAT                                 (0x108U)
#define HW_ICSS_IEP_SYNC1_STAT                                 (0x10cU)
#define HW_ICSS_IEP_SYNC_PWIDTH                                (0x110U)
#define HW_ICSS_IEP_SYNC0_PERIOD                               (0x114U)
#define HW_ICSS_IEP_SYNC1_DELAY                                (0x118U)
#define HW_ICSS_IEP_SYNC_START                                 (0x11cU)
#define HW_ICSS_IEP_WD_PREDIV                                  (0x200U)
#define HW_ICSS_IEP_PDI_WD_TIM                                 (0x204U)
#define HW_ICSS_IEP_PD_WD_TIM                                  (0x208U)
#define HW_ICSS_IEP_WD_STATUS                                  (0x20cU)
#define HW_ICSS_IEP_WD_EXP_CNT                                 (0x210U)
#define HW_ICSS_IEP_WD_CTRL                                    (0x214U)
#define HW_ICSS_IEP_DIGIO_CTRL                                 (0x300U)
#define HW_ICSS_IEP_DIGIO_STATUS                               (0x304U)
#define HW_ICSS_IEP_DIGIO_DATA_IN                              (0x308U)
#define HW_ICSS_IEP_DIGIO_DATA_IN_RAW                          (0x30cU)
#define HW_ICSS_IEP_DIGIO_DATA_OUT                             (0x310U)
#define HW_ICSS_IEP_DIGIO_DATA_OUT_EN                          (0x314U)
#define HW_ICSS_IEP_DIGIO_EXP                                  (0x318U)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define HW_ICSS_IEP_GLOBAL_CFG_CNT_ENABLE_SHIFT                (0U)
#define HW_ICSS_IEP_GLOBAL_CFG_CNT_ENABLE_MASK                 (0x00000001U)

#define HW_ICSS_IEP_GLOBAL_CFG_DEFAULT_INC_SHIFT               (4U)
#define HW_ICSS_IEP_GLOBAL_CFG_DEFAULT_INC_MASK                (0x000000f0U)

#define HW_ICSS_IEP_GLOBAL_CFG_CMP_INC_SHIFT                   (8U)
#define HW_ICSS_IEP_GLOBAL_CFG_CMP_INC_MASK                    (0x000fff00U)

#define HW_ICSS_IEP_GLOBAL_STATUS_CNT_OVF_SHIFT                (0U)
#define HW_ICSS_IEP_GLOBAL_STATUS_CNT_OVF_MASK                 (0x00000001U)

#define HW_ICSS_IEP_COMPEN_CNT_SHIFT                           (0U)
#define HW_ICSS_IEP_COMPEN_CNT_MASK                            (0x007fffffU)

#define HW_ICSS_IEP_COUNT_SHIFT                                (0U)
#define HW_ICSS_IEP_COUNT_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CAP_CFG_1ST_EVENT_EN_SHIFT                 (0U)
#define HW_ICSS_IEP_CAP_CFG_1ST_EVENT_EN_MASK                  (0x0000003fU)

#define HW_ICSS_IEP_CAP_CFG_CAP6R_1ST_EVENT_EN_SHIFT           (6U)
#define HW_ICSS_IEP_CAP_CFG_CAP6R_1ST_EVENT_EN_MASK            (0x00000040U)

#define HW_ICSS_IEP_CAP_CFG_CAP6F_1ST_EVENT_EN_SHIFT           (7U)
#define HW_ICSS_IEP_CAP_CFG_CAP6F_1ST_EVENT_EN_MASK            (0x00000080U)

#define HW_ICSS_IEP_CAP_CFG_CAP7R_1ST_EVENT_EN_SHIFT           (8U)
#define HW_ICSS_IEP_CAP_CFG_CAP7R_1ST_EVENT_EN_MASK            (0x00000100U)

#define HW_ICSS_IEP_CAP_CFG_CAP7F_1ST_EVENT_EN_SHIFT           (9U)
#define HW_ICSS_IEP_CAP_CFG_CAP7F_1ST_EVENT_EN_MASK            (0x00000200U)

#define HW_ICSS_IEP_CAP_CFG_ASYNC_EN_SHIFT                     (10U)
#define HW_ICSS_IEP_CAP_CFG_ASYNC_EN_MASK                      (0x0003fc00U)

#define HW_ICSS_IEP_CAP_STATUS_CAPR_VALID_SHIFT                (0U)
#define HW_ICSS_IEP_CAP_STATUS_CAPR_VALID_MASK                 (0x0000003fU)

#define HW_ICSS_IEP_CAP_STATUS_CAPR6_VALID_SHIFT               (6U)
#define HW_ICSS_IEP_CAP_STATUS_CAPR6_VALID_MASK                (0x00000040U)

#define HW_ICSS_IEP_CAP_STATUS_CAPF6_VALID_SHIFT               (7U)
#define HW_ICSS_IEP_CAP_STATUS_CAPF6_VALID_MASK                (0x00000080U)

#define HW_ICSS_IEP_CAP_STATUS_CAPR7_VALID_SHIFT               (8U)
#define HW_ICSS_IEP_CAP_STATUS_CAPR7_VALID_MASK                (0x00000100U)

#define HW_ICSS_IEP_CAP_STATUS_CAPF7_VALID_SHIFT               (9U)
#define HW_ICSS_IEP_CAP_STATUS_CAPF7_VALID_MASK                (0x00000200U)

#define HW_ICSS_IEP_CAP_STATUS_VALID_SHIFT                     (10U)
#define HW_ICSS_IEP_CAP_STATUS_VALID_MASK                      (0x00000400U)

#define HW_ICSS_IEP_CAP_STATUS_RAW_SHIFT                       (16U)
#define HW_ICSS_IEP_CAP_STATUS_RAW_MASK                        (0x00ff0000U)

#define HW_ICSS_IEP_CAPR0_SHIFT                                (0U)
#define HW_ICSS_IEP_CAPR0_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CAPR1_SHIFT                                (0U)
#define HW_ICSS_IEP_CAPR1_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CAPR2_SHIFT                                (0U)
#define HW_ICSS_IEP_CAPR2_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CAPR3_SHIFT                                (0U)
#define HW_ICSS_IEP_CAPR3_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CAPR4_SHIFT                                (0U)
#define HW_ICSS_IEP_CAPR4_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CAPR5_SHIFT                                (0U)
#define HW_ICSS_IEP_CAPR5_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CAPR6_SHIFT                                (0U)
#define HW_ICSS_IEP_CAPR6_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CAPF6_SHIFT                                (0U)
#define HW_ICSS_IEP_CAPF6_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CAPR7_SHIFT                                (0U)
#define HW_ICSS_IEP_CAPR7_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CAPF7_SHIFT                                (0U)
#define HW_ICSS_IEP_CAPF7_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CMP_CFG_CMP0_RST_CNT_EN_SHIFT              (0U)
#define HW_ICSS_IEP_CMP_CFG_CMP0_RST_CNT_EN_MASK               (0x00000001U)

#define HW_ICSS_IEP_CMP_CFG_EN_SHIFT                           (1U)
#define HW_ICSS_IEP_CMP_CFG_EN_MASK                            (0x000001feU)

#define HW_ICSS_IEP_CMP_STATUS_HIT_SHIFT                       (0U)
#define HW_ICSS_IEP_CMP_STATUS_HIT_MASK                        (0x000000ffU)

#define HW_ICSS_IEP_CMP0_SHIFT                                 (0U)
#define HW_ICSS_IEP_CMP0_MASK                                  (0xffffffffU)

#define HW_ICSS_IEP_CMP1_SHIFT                                 (0U)
#define HW_ICSS_IEP_CMP1_MASK                                  (0xffffffffU)

#define HW_ICSS_IEP_CMP2_SHIFT                                 (0U)
#define HW_ICSS_IEP_CMP2_MASK                                  (0xffffffffU)

#define HW_ICSS_IEP_CMP3_SHIFT                                 (0U)
#define HW_ICSS_IEP_CMP3_MASK                                  (0xffffffffU)

#define HW_ICSS_IEP_CMP4_SHIFT                                 (0U)
#define HW_ICSS_IEP_CMP4_MASK                                  (0xffffffffU)

#define HW_ICSS_IEP_CMP5_SHIFT                                 (0U)
#define HW_ICSS_IEP_CMP5_MASK                                  (0xffffffffU)

#define HW_ICSS_IEP_CMP6_SHIFT                                 (0U)
#define HW_ICSS_IEP_CMP6_MASK                                  (0xffffffffU)

#define HW_ICSS_IEP_CMP7_SHIFT                                 (0U)
#define HW_ICSS_IEP_CMP7_MASK                                  (0xffffffffU)

#define HW_ICSS_IEP_RXIPG0_RX_IPG_SHIFT                        (0U)
#define HW_ICSS_IEP_RXIPG0_RX_IPG_MASK                         (0x0000ffffU)

#define HW_ICSS_IEP_RXIPG0_RX_MIN_IPG_SHIFT                    (16U)
#define HW_ICSS_IEP_RXIPG0_RX_MIN_IPG_MASK                     (0xffff0000U)

#define HW_ICSS_IEP_RXIPG1_RX_IPG_SHIFT                        (0U)
#define HW_ICSS_IEP_RXIPG1_RX_IPG_MASK                         (0x0000ffffU)

#define HW_ICSS_IEP_RXIPG1_RX_MIN_IPG_SHIFT                    (16U)
#define HW_ICSS_IEP_RXIPG1_RX_MIN_IPG_MASK                     (0xffff0000U)

#define HW_ICSS_IEP_CMP8_SHIFT                                 (0U)
#define HW_ICSS_IEP_CMP8_MASK                                  (0xffffffffU)

#define HW_ICSS_IEP_CMP9_SHIFT                                 (0U)
#define HW_ICSS_IEP_CMP9_MASK                                  (0xffffffffU)

#define HW_ICSS_IEP_CMP10_SHIFT                                (0U)
#define HW_ICSS_IEP_CMP10_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CMP11_SHIFT                                (0U)
#define HW_ICSS_IEP_CMP11_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CMP12_SHIFT                                (0U)
#define HW_ICSS_IEP_CMP12_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CMP13_SHIFT                                (0U)
#define HW_ICSS_IEP_CMP13_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CMP14_SHIFT                                (0U)
#define HW_ICSS_IEP_CMP14_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_CMP15_SHIFT                                (0U)
#define HW_ICSS_IEP_CMP15_MASK                                 (0xffffffffU)

#define HW_ICSS_IEP_COUNT_RESET_VAL_SHIFT                      (0U)
#define HW_ICSS_IEP_COUNT_RESET_VAL_MASK                       (0xffffffffU)

#define HW_ICSS_IEP_PWM_PWM0_RST_CNT_EN_SHIFT                  (0U)
#define HW_ICSS_IEP_PWM_PWM0_RST_CNT_EN_MASK                   (0x00000001U)
#define HW_ICSS_IEP_PWM_PWM0_RST_CNT_EN_DISABLE                (0U)
#define HW_ICSS_IEP_PWM_PWM0_RST_CNT_EN_ENABLE                 (1U)

#define HW_ICSS_IEP_PWM_PWM0_HIT_SHIFT                         (1U)
#define HW_ICSS_IEP_PWM_PWM0_HIT_MASK                          (0x00000002U)
#define HW_ICSS_IEP_PWM_PWM0_HIT_EVENT                         (1U)
#define HW_ICSS_IEP_PWM_PWM0_HIT_CLEAR                         (1U)

#define HW_ICSS_IEP_PWM_PWM3_HIT_SHIFT                         (3U)
#define HW_ICSS_IEP_PWM_PWM3_HIT_MASK                          (0x00000008U)
#define HW_ICSS_IEP_PWM_PWM3_HIT_EVENT                         (1U)
#define HW_ICSS_IEP_PWM_PWM3_HIT_CLEAR                         (1U)

#define HW_ICSS_IEP_PWM_PWM3_RST_CNT_EN_SHIFT                  (2U)
#define HW_ICSS_IEP_PWM_PWM3_RST_CNT_EN_MASK                   (0x00000004U)
#define HW_ICSS_IEP_PWM_PWM3_RST_CNT_EN_DISABLE                (0U)
#define HW_ICSS_IEP_PWM_PWM3_RST_CNT_EN_ENABLE                 (1U)

#define HW_ICSS_IEP_SYNC_CTRL_EN_SHIFT                         (0U)
#define HW_ICSS_IEP_SYNC_CTRL_EN_MASK                          (0x00000001U)

#define HW_ICSS_IEP_SYNC_CTRL_SYNC0_EN_SHIFT                   (1U)
#define HW_ICSS_IEP_SYNC_CTRL_SYNC0_EN_MASK                    (0x00000002U)

#define HW_ICSS_IEP_SYNC_CTRL_SYNC1_EN_SHIFT                   (2U)
#define HW_ICSS_IEP_SYNC_CTRL_SYNC1_EN_MASK                    (0x00000004U)

#define HW_ICSS_IEP_SYNC_CTRL_SYNC0_ACK_EN_SHIFT               (4U)
#define HW_ICSS_IEP_SYNC_CTRL_SYNC0_ACK_EN_MASK                (0x00000010U)

#define HW_ICSS_IEP_SYNC_CTRL_SYNC0_CYCLIC_EN_SHIFT            (5U)
#define HW_ICSS_IEP_SYNC_CTRL_SYNC0_CYCLIC_EN_MASK             (0x00000020U)

#define HW_ICSS_IEP_SYNC_CTRL_SYNC1_ACK_EN_SHIFT               (6U)
#define HW_ICSS_IEP_SYNC_CTRL_SYNC1_ACK_EN_MASK                (0x00000040U)

#define HW_ICSS_IEP_SYNC_CTRL_SYNC1_CYCLIC_EN_SHIFT            (7U)
#define HW_ICSS_IEP_SYNC_CTRL_SYNC1_CYCLIC_EN_MASK             (0x00000080U)

#define HW_ICSS_IEP_SYNC_CTRL_SYNC1_IND_EN_SHIFT               (8U)
#define HW_ICSS_IEP_SYNC_CTRL_SYNC1_IND_EN_MASK                (0x00000100U)

#define HW_ICSS_IEP_SYNC_FIRST_STAT_SYNC0_SHIFT                (0U)
#define HW_ICSS_IEP_SYNC_FIRST_STAT_SYNC0_MASK                 (0x00000001U)

#define HW_ICSS_IEP_SYNC_FIRST_STAT_SYNC1_SHIFT                (1U)
#define HW_ICSS_IEP_SYNC_FIRST_STAT_SYNC1_MASK                 (0x00000002U)

#define HW_ICSS_IEP_SYNC0_STAT_PEND_SHIFT                      (0U)
#define HW_ICSS_IEP_SYNC0_STAT_PEND_MASK                       (0x00000001U)

#define HW_ICSS_IEP_SYNC1_STAT_PEND_SHIFT                      (0U)
#define HW_ICSS_IEP_SYNC1_STAT_PEND_MASK                       (0x00000001U)

#define HW_ICSS_IEP_SYNC_PWIDTH_HPW_SHIFT                      (0U)
#define HW_ICSS_IEP_SYNC_PWIDTH_HPW_MASK                       (0xffffffffU)

#define HW_ICSS_IEP_SYNC0_PERIOD_SHIFT                         (0U)
#define HW_ICSS_IEP_SYNC0_PERIOD_MASK                          (0xffffffffU)

#define HW_ICSS_IEP_SYNC1_DELAY_SHIFT                          (0U)
#define HW_ICSS_IEP_SYNC1_DELAY_MASK                           (0xffffffffU)

#define HW_ICSS_IEP_SYNC_START_SHIFT                           (0U)
#define HW_ICSS_IEP_SYNC_START_MASK                            (0xffffffffU)

#define HW_ICSS_IEP_WD_PREDIV_PRE_DIV_SHIFT                    (0U)
#define HW_ICSS_IEP_WD_PREDIV_PRE_DIV_MASK                     (0x0000ffffU)

#define HW_ICSS_IEP_PDI_WD_TIM_TIME_SHIFT                      (0U)
#define HW_ICSS_IEP_PDI_WD_TIM_TIME_MASK                       (0x0000ffffU)

#define HW_ICSS_IEP_PD_WD_TIM_TIME_SHIFT                       (0U)
#define HW_ICSS_IEP_PD_WD_TIM_TIME_MASK                        (0x0000ffffU)

#define HW_ICSS_IEP_WD_STATUS_PD_STAT_SHIFT                    (0U)
#define HW_ICSS_IEP_WD_STATUS_PD_STAT_MASK                     (0x00000001U)

#define HW_ICSS_IEP_WD_STATUS_PDI_STAT_SHIFT                   (16U)
#define HW_ICSS_IEP_WD_STATUS_PDI_STAT_MASK                    (0x00010000U)

#define HW_ICSS_IEP_WD_EXP_CNT_PDI_SHIFT                       (0U)
#define HW_ICSS_IEP_WD_EXP_CNT_PDI_MASK                        (0x000000ffU)

#define HW_ICSS_IEP_WD_EXP_CNT_PD_SHIFT                        (8U)
#define HW_ICSS_IEP_WD_EXP_CNT_PD_MASK                         (0x0000ff00U)

#define HW_ICSS_IEP_WD_CTRL_PD_EN_SHIFT                        (0U)
#define HW_ICSS_IEP_WD_CTRL_PD_EN_MASK                         (0x00000001U)

#define HW_ICSS_IEP_WD_CTRL_PDI_EN_SHIFT                       (16U)
#define HW_ICSS_IEP_WD_CTRL_PDI_EN_MASK                        (0x00010000U)

#define HW_ICSS_IEP_DIGIO_CTRL_OUTVALID_POL_SHIFT              (0U)
#define HW_ICSS_IEP_DIGIO_CTRL_OUTVALID_POL_MASK               (0x00000001U)

#define HW_ICSS_IEP_DIGIO_CTRL_OUTVALID_MODE_SHIFT             (1U)
#define HW_ICSS_IEP_DIGIO_CTRL_OUTVALID_MODE_MASK              (0x00000002U)

#define HW_ICSS_IEP_DIGIO_CTRL_BIDI_MODE_SHIFT                 (2U)
#define HW_ICSS_IEP_DIGIO_CTRL_BIDI_MODE_MASK                  (0x00000004U)

#define HW_ICSS_IEP_DIGIO_CTRL_WD_MODE_SHIFT                   (3U)
#define HW_ICSS_IEP_DIGIO_CTRL_WD_MODE_MASK                    (0x00000008U)

#define HW_ICSS_IEP_DIGIO_CTRL_IN_MODE_SHIFT                   (4U)
#define HW_ICSS_IEP_DIGIO_CTRL_IN_MODE_MASK                    (0x00000030U)

#define HW_ICSS_IEP_DIGIO_CTRL_OUT_MODE_SHIFT                  (6U)
#define HW_ICSS_IEP_DIGIO_CTRL_OUT_MODE_MASK                   (0x000000c0U)

#define HW_ICSS_IEP_DIGIO_STATUS_STAT_SHIFT                    (0U)
#define HW_ICSS_IEP_DIGIO_STATUS_STAT_MASK                     (0xffffffffU)

#define HW_ICSS_IEP_DIGIO_DATA_IN_SHIFT                        (0U)
#define HW_ICSS_IEP_DIGIO_DATA_IN_MASK                         (0xffffffffU)

#define HW_ICSS_IEP_DIGIO_DATA_IN_RAW_SHIFT                    (0U)
#define HW_ICSS_IEP_DIGIO_DATA_IN_RAW_MASK                     (0xffffffffU)

#define HW_ICSS_IEP_DIGIO_DATA_OUT_SHIFT                       (0U)
#define HW_ICSS_IEP_DIGIO_DATA_OUT_MASK                        (0xffffffffU)

#define HW_ICSS_IEP_DIGIO_DATA_OUT_EN_SHIFT                    (0U)
#define HW_ICSS_IEP_DIGIO_DATA_OUT_EN_MASK                     (0xffffffffU)

#define HW_ICSS_IEP_DIGIO_EXP_SW_DATA_OUT_UPDATE_SHIFT         (0U)
#define HW_ICSS_IEP_DIGIO_EXP_SW_DATA_OUT_UPDATE_MASK          (0x00000001U)

#define HW_ICSS_IEP_DIGIO_EXP_OUTVALID_OVR_EN_SHIFT            (1U)
#define HW_ICSS_IEP_DIGIO_EXP_OUTVALID_OVR_EN_MASK             (0x00000002U)

#define HW_ICSS_IEP_DIGIO_EXP_SW_OUTVALID_SHIFT                (2U)
#define HW_ICSS_IEP_DIGIO_EXP_SW_OUTVALID_MASK                 (0x00000004U)

#define HW_ICSS_IEP_DIGIO_EXP_OUTVALID_DLY_SHIFT               (4U)
#define HW_ICSS_IEP_DIGIO_EXP_OUTVALID_DLY_MASK                (0x000000f0U)

#define HW_ICSS_IEP_DIGIO_EXP_SOF_DLY_SHIFT                    (8U)
#define HW_ICSS_IEP_DIGIO_EXP_SOF_DLY_MASK                     (0x00000f00U)

#define HW_ICSS_IEP_DIGIO_EXP_SOF_SEL_SHIFT                    (12U)
#define HW_ICSS_IEP_DIGIO_EXP_SOF_SEL_MASK                     (0x00001000U)

#define HW_ICSS_IEP_DIGIO_EXP_EOF_SEL_SHIFT                    (13U)
#define HW_ICSS_IEP_DIGIO_EXP_EOF_SEL_MASK                     (0x00002000U)

#ifdef __cplusplus
}
#endif

#endif /* HW_ICSS_IEP_H_ */
