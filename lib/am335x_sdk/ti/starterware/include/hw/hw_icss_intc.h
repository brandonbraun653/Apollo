/*
* hw_icss_intc.h
*
* Register-level header file for HW_ICSS_INTC
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
#ifndef HW_ICSS_INTC_H_
#define HW_ICSS_INTC_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define HW_ICSS_INTC_REVID                                     (0x0U)
#define HW_ICSS_INTC_CR                                        (0x4U)
#define HW_ICSS_INTC_GER                                       (0x10U)
#define HW_ICSS_INTC_GNLR                                      (0x1cU)
#define HW_ICSS_INTC_SISR                                      (0x20U)
#define HW_ICSS_INTC_SICR                                      (0x24U)
#define HW_ICSS_INTC_EISR                                      (0x28U)
#define HW_ICSS_INTC_EICR                                      (0x2cU)
#define HW_ICSS_INTC_HIEISR                                    (0x34U)
#define HW_ICSS_INTC_HIDISR                                    (0x38U)
#define HW_ICSS_INTC_GPIR                                      (0x80U)
#define HW_ICSS_INTC_SRSR0                                     (0x200U)
#define HW_ICSS_INTC_SRSR1                                     (0x204U)
#define HW_ICSS_INTC_SECR0                                     (0x280U)
#define HW_ICSS_INTC_SECR1                                     (0x284U)
#define HW_ICSS_INTC_ESR0                                      (0x300U)
#define HW_ICSS_INTC_ERS1                                      (0x304U)
#define HW_ICSS_INTC_ECR0                                      (0x380U)
#define HW_ICSS_INTC_ECR1                                      (0x384U)
#define HW_ICSS_INTC_CMR0                                      (0x400U)
#define HW_ICSS_INTC_CMR1                                      (0x404U)
#define HW_ICSS_INTC_CMR2                                      (0x408U)
#define HW_ICSS_INTC_CMR3                                      (0x40cU)
#define HW_ICSS_INTC_CMR4                                      (0x410U)
#define HW_ICSS_INTC_CMR5                                      (0x414U)
#define HW_ICSS_INTC_CMR6                                      (0x418U)
#define HW_ICSS_INTC_CMR7                                      (0x41cU)
#define HW_ICSS_INTC_CMR8                                      (0x420U)
#define HW_ICSS_INTC_CMR9                                      (0x424U)
#define HW_ICSS_INTC_CMR10                                     (0x428U)
#define HW_ICSS_INTC_CMR11                                     (0x42cU)
#define HW_ICSS_INTC_CMR12                                     (0x430U)
#define HW_ICSS_INTC_CMR13                                     (0x434U)
#define HW_ICSS_INTC_CMR14                                     (0x438U)
#define HW_ICSS_INTC_CMR15                                     (0x43cU)
#define HW_ICSS_INTC_HMR0                                      (0x800U)
#define HW_ICSS_INTC_HMR1                                      (0x804U)
#define HW_ICSS_INTC_HMR2                                      (0x808U)
#define HW_ICSS_INTC_HIPIR0                                    (0x900U)
#define HW_ICSS_INTC_HIPIR1                                    (0x904U)
#define HW_ICSS_INTC_HIPIR2                                    (0x908U)
#define HW_ICSS_INTC_HIPIR3                                    (0x90cU)
#define HW_ICSS_INTC_HIPIR4                                    (0x910U)
#define HW_ICSS_INTC_HIPIR5                                    (0x914U)
#define HW_ICSS_INTC_HIPIR6                                    (0x918U)
#define HW_ICSS_INTC_HIPIR7                                    (0x91cU)
#define HW_ICSS_INTC_HIPIR8                                    (0x920U)
#define HW_ICSS_INTC_HIPIR9                                    (0x924U)
#define HW_ICSS_INTC_SIPR0                                     (0xd00U)
#define HW_ICSS_INTC_SIPR1                                     (0xd04U)
#define HW_ICSS_INTC_SITR0                                     (0xd80U)
#define HW_ICSS_INTC_SITR1                                     (0xd84U)
#define HW_ICSS_INTC_HINLR0                                    (0x1100U)
#define HW_ICSS_INTC_HINLR1                                    (0x1104U)
#define HW_ICSS_INTC_HINLR2                                    (0x1108U)
#define HW_ICSS_INTC_HINLR3                                    (0x110cU)
#define HW_ICSS_INTC_HINLR4                                    (0x1110U)
#define HW_ICSS_INTC_HINLR5                                    (0x1114U)
#define HW_ICSS_INTC_HINLR6                                    (0x1118U)
#define HW_ICSS_INTC_HINLR7                                    (0x111cU)
#define HW_ICSS_INTC_HINLR8                                    (0x1120U)
#define HW_ICSS_INTC_HINLR9                                    (0x1124U)
#define HW_ICSS_INTC_HIER                                      (0x1500U)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define HW_ICSS_INTC_REVID_REV_MINOR_SHIFT                     (0U)
#define HW_ICSS_INTC_REVID_REV_MINOR_MASK                      (0x0000003fU)

#define HW_ICSS_INTC_REVID_REV_CUSTOM_SHIFT                    (6U)
#define HW_ICSS_INTC_REVID_REV_CUSTOM_MASK                     (0x000000c0U)

#define HW_ICSS_INTC_REVID_REV_MAJOR_SHIFT                     (8U)
#define HW_ICSS_INTC_REVID_REV_MAJOR_MASK                      (0x00000700U)

#define HW_ICSS_INTC_REVID_REV_RTL_SHIFT                       (11U)
#define HW_ICSS_INTC_REVID_REV_RTL_MASK                        (0x0000f800U)

#define HW_ICSS_INTC_REVID_REV_MODULE_SHIFT                    (16U)
#define HW_ICSS_INTC_REVID_REV_MODULE_MASK                     (0x0fff0000U)

#define HW_ICSS_INTC_REVID_REV_SCHEME_SHIFT                    (30U)
#define HW_ICSS_INTC_REVID_REV_SCHEME_MASK                     (0xc0000000U)

#define HW_ICSS_INTC_CR_WAKEUP_MODE_SHIFT                      (1U)
#define HW_ICSS_INTC_CR_WAKEUP_MODE_MASK                       (0x00000002U)

#define HW_ICSS_INTC_CR_NEST_MODE_SHIFT                        (2U)
#define HW_ICSS_INTC_CR_NEST_MODE_MASK                         (0x0000000cU)

#define HW_ICSS_INTC_CR_PRIORITY_HOLD_MODE_SHIFT               (4U)
#define HW_ICSS_INTC_CR_PRIORITY_HOLD_MODE_MASK                (0x00000010U)

#define HW_ICSS_INTC_GER_ENABLE_HINT_ANY_SHIFT                 (0U)
#define HW_ICSS_INTC_GER_ENABLE_HINT_ANY_MASK                  (0x00000001U)

#define HW_ICSS_INTC_GNLR_GLB_NEST_LEVEL_SHIFT                 (0U)
#define HW_ICSS_INTC_GNLR_GLB_NEST_LEVEL_MASK                  (0x000001ffU)

#define HW_ICSS_INTC_GNLR_AUTO_OVERRIDE_SHIFT                  (31U)
#define HW_ICSS_INTC_GNLR_AUTO_OVERRIDE_MASK                   (0x80000000U)

#define HW_ICSS_INTC_SISR_STATUS_SET_INDEX_SHIFT               (0U)
#define HW_ICSS_INTC_SISR_STATUS_SET_INDEX_MASK                (0x000003ffU)

#define HW_ICSS_INTC_SICR_STATUS_CLR_INDEX_SHIFT               (0U)
#define HW_ICSS_INTC_SICR_STATUS_CLR_INDEX_MASK                (0x000003ffU)

#define HW_ICSS_INTC_EISR_ENABLE_SET_INDEX_SHIFT               (0U)
#define HW_ICSS_INTC_EISR_ENABLE_SET_INDEX_MASK                (0x000003ffU)

#define HW_ICSS_INTC_EICR_ENABLE_CLR_INDEX_SHIFT               (0U)
#define HW_ICSS_INTC_EICR_ENABLE_CLR_INDEX_MASK                (0x000003ffU)

#define HW_ICSS_INTC_HIEISR_HINT_ENABLE_SET_INDEX_SHIFT        (0U)
#define HW_ICSS_INTC_HIEISR_HINT_ENABLE_SET_INDEX_MASK         (0x000003ffU)

#define HW_ICSS_INTC_HIDISR_HINT_ENABLE_CLR_INDEX_SHIFT        (0U)
#define HW_ICSS_INTC_HIDISR_HINT_ENABLE_CLR_INDEX_MASK         (0x000003ffU)

#define HW_ICSS_INTC_GPIR_GLB_PRI_INTR_SHIFT                   (0U)
#define HW_ICSS_INTC_GPIR_GLB_PRI_INTR_MASK                    (0x000003ffU)

#define HW_ICSS_INTC_GPIR_GLB_NONE_SHIFT                       (31U)
#define HW_ICSS_INTC_GPIR_GLB_NONE_MASK                        (0x80000000U)

#define HW_ICSS_INTC_SRSR0_RAW_STATUS_31_0_SHIFT               (0U)
#define HW_ICSS_INTC_SRSR0_RAW_STATUS_31_0_MASK                (0xffffffffU)

#define HW_ICSS_INTC_SRSR1_RAW_STATUS_63_32_SHIFT              (0U)
#define HW_ICSS_INTC_SRSR1_RAW_STATUS_63_32_MASK               (0xffffffffU)

#define HW_ICSS_INTC_SECR0_ENA_STATUS_31_0_SHIFT               (0U)
#define HW_ICSS_INTC_SECR0_ENA_STATUS_31_0_MASK                (0xffffffffU)

#define HW_ICSS_INTC_SECR1_ENA_STATUS_63_32_SHIFT              (0U)
#define HW_ICSS_INTC_SECR1_ENA_STATUS_63_32_MASK               (0xffffffffU)

#define HW_ICSS_INTC_ESR0_ENABLE_SET_31_0_SHIFT                (0U)
#define HW_ICSS_INTC_ESR0_ENABLE_SET_31_0_MASK                 (0xffffffffU)

#define HW_ICSS_INTC_ERS1_ENABLE_SET_63_32_SHIFT               (0U)
#define HW_ICSS_INTC_ERS1_ENABLE_SET_63_32_MASK                (0xffffffffU)

#define HW_ICSS_INTC_ECR0_ENABLE_CLR_31_0_SHIFT                (0U)
#define HW_ICSS_INTC_ECR0_ENABLE_CLR_31_0_MASK                 (0xffffffffU)

#define HW_ICSS_INTC_ECR1_ENABLE_CLR_63_32_SHIFT               (0U)
#define HW_ICSS_INTC_ECR1_ENABLE_CLR_63_32_MASK                (0xffffffffU)

#define HW_ICSS_INTC_CMR0_CH_MAP_0_SHIFT                       (0U)
#define HW_ICSS_INTC_CMR0_CH_MAP_0_MASK                        (0x0000000fU)

#define HW_ICSS_INTC_CMR0_CH_MAP_1_SHIFT                       (8U)
#define HW_ICSS_INTC_CMR0_CH_MAP_1_MASK                        (0x00000f00U)

#define HW_ICSS_INTC_CMR0_CH_MAP_2_SHIFT                       (16U)
#define HW_ICSS_INTC_CMR0_CH_MAP_2_MASK                        (0x000f0000U)

#define HW_ICSS_INTC_CMR0_CH_MAP_3_SHIFT                       (24U)
#define HW_ICSS_INTC_CMR0_CH_MAP_3_MASK                        (0x0f000000U)

#define HW_ICSS_INTC_CMR1_CH_MAP_4_SHIFT                       (0U)
#define HW_ICSS_INTC_CMR1_CH_MAP_4_MASK                        (0x0000000fU)

#define HW_ICSS_INTC_CMR1_CH_MAP_5_SHIFT                       (8U)
#define HW_ICSS_INTC_CMR1_CH_MAP_5_MASK                        (0x00000f00U)

#define HW_ICSS_INTC_CMR1_CH_MAP_6_SHIFT                       (16U)
#define HW_ICSS_INTC_CMR1_CH_MAP_6_MASK                        (0x000f0000U)

#define HW_ICSS_INTC_CMR1_CH_MAP_7_SHIFT                       (24U)
#define HW_ICSS_INTC_CMR1_CH_MAP_7_MASK                        (0x0f000000U)

#define HW_ICSS_INTC_CMR2_CH_MAP_8_SHIFT                       (0U)
#define HW_ICSS_INTC_CMR2_CH_MAP_8_MASK                        (0x0000000fU)

#define HW_ICSS_INTC_CMR2_CH_MAP_9_SHIFT                       (8U)
#define HW_ICSS_INTC_CMR2_CH_MAP_9_MASK                        (0x00000f00U)

#define HW_ICSS_INTC_CMR2_CH_MAP_10_SHIFT                      (16U)
#define HW_ICSS_INTC_CMR2_CH_MAP_10_MASK                       (0x000f0000U)

#define HW_ICSS_INTC_CMR2_CH_MAP_11_SHIFT                      (24U)
#define HW_ICSS_INTC_CMR2_CH_MAP_11_MASK                       (0x0f000000U)

#define HW_ICSS_INTC_CMR3_CH_MAP_12_SHIFT                      (0U)
#define HW_ICSS_INTC_CMR3_CH_MAP_12_MASK                       (0x0000000fU)

#define HW_ICSS_INTC_CMR3_CH_MAP_13_SHIFT                      (8U)
#define HW_ICSS_INTC_CMR3_CH_MAP_13_MASK                       (0x00000f00U)

#define HW_ICSS_INTC_CMR3_CH_MAP_14_SHIFT                      (16U)
#define HW_ICSS_INTC_CMR3_CH_MAP_14_MASK                       (0x000f0000U)

#define HW_ICSS_INTC_CMR3_CH_MAP_15_SHIFT                      (24U)
#define HW_ICSS_INTC_CMR3_CH_MAP_15_MASK                       (0x0f000000U)

#define HW_ICSS_INTC_CMR4_CH_MAP_16_SHIFT                      (0U)
#define HW_ICSS_INTC_CMR4_CH_MAP_16_MASK                       (0x0000000fU)

#define HW_ICSS_INTC_CMR4_CH_MAP_17_SHIFT                      (8U)
#define HW_ICSS_INTC_CMR4_CH_MAP_17_MASK                       (0x00000f00U)

#define HW_ICSS_INTC_CMR4_CH_MAP_18_SHIFT                      (16U)
#define HW_ICSS_INTC_CMR4_CH_MAP_18_MASK                       (0x000f0000U)

#define HW_ICSS_INTC_CMR4_CH_MAP_19_SHIFT                      (24U)
#define HW_ICSS_INTC_CMR4_CH_MAP_19_MASK                       (0x0f000000U)

#define HW_ICSS_INTC_CMR5_CH_MAP_20_SHIFT                      (0U)
#define HW_ICSS_INTC_CMR5_CH_MAP_20_MASK                       (0x0000000fU)

#define HW_ICSS_INTC_CMR5_CH_MAP_21_SHIFT                      (8U)
#define HW_ICSS_INTC_CMR5_CH_MAP_21_MASK                       (0x00000f00U)

#define HW_ICSS_INTC_CMR5_CH_MAP_22_SHIFT                      (16U)
#define HW_ICSS_INTC_CMR5_CH_MAP_22_MASK                       (0x000f0000U)

#define HW_ICSS_INTC_CMR5_CH_MAP_23_SHIFT                      (24U)
#define HW_ICSS_INTC_CMR5_CH_MAP_23_MASK                       (0x0f000000U)

#define HW_ICSS_INTC_CMR6_CH_MAP_24_SHIFT                      (0U)
#define HW_ICSS_INTC_CMR6_CH_MAP_24_MASK                       (0x0000000fU)

#define HW_ICSS_INTC_CMR6_CH_MAP_25_SHIFT                      (8U)
#define HW_ICSS_INTC_CMR6_CH_MAP_25_MASK                       (0x00000f00U)

#define HW_ICSS_INTC_CMR6_CH_MAP_26_SHIFT                      (16U)
#define HW_ICSS_INTC_CMR6_CH_MAP_26_MASK                       (0x000f0000U)

#define HW_ICSS_INTC_CMR6_CH_MAP_27_SHIFT                      (24U)
#define HW_ICSS_INTC_CMR6_CH_MAP_27_MASK                       (0x0f000000U)

#define HW_ICSS_INTC_CMR7_CH_MAP_28_SHIFT                      (0U)
#define HW_ICSS_INTC_CMR7_CH_MAP_28_MASK                       (0x0000000fU)

#define HW_ICSS_INTC_CMR7_CH_MAP_29_SHIFT                      (8U)
#define HW_ICSS_INTC_CMR7_CH_MAP_29_MASK                       (0x00000f00U)

#define HW_ICSS_INTC_CMR7_CH_MAP_30_SHIFT                      (16U)
#define HW_ICSS_INTC_CMR7_CH_MAP_30_MASK                       (0x000f0000U)

#define HW_ICSS_INTC_CMR7_CH_MAP_31_SHIFT                      (24U)
#define HW_ICSS_INTC_CMR7_CH_MAP_31_MASK                       (0x0f000000U)

#define HW_ICSS_INTC_CMR8_CH_MAP_32_SHIFT                      (0U)
#define HW_ICSS_INTC_CMR8_CH_MAP_32_MASK                       (0x0000000fU)

#define HW_ICSS_INTC_CMR8_CH_MAP_33_SHIFT                      (8U)
#define HW_ICSS_INTC_CMR8_CH_MAP_33_MASK                       (0x00000f00U)

#define HW_ICSS_INTC_CMR8_CH_MAP_34_SHIFT                      (16U)
#define HW_ICSS_INTC_CMR8_CH_MAP_34_MASK                       (0x000f0000U)

#define HW_ICSS_INTC_CMR8_CH_MAP_35_SHIFT                      (24U)
#define HW_ICSS_INTC_CMR8_CH_MAP_35_MASK                       (0x0f000000U)

#define HW_ICSS_INTC_CMR9_CH_MAP_36_SHIFT                      (0U)
#define HW_ICSS_INTC_CMR9_CH_MAP_36_MASK                       (0x0000000fU)

#define HW_ICSS_INTC_CMR9_CH_MAP_37_SHIFT                      (8U)
#define HW_ICSS_INTC_CMR9_CH_MAP_37_MASK                       (0x00000f00U)

#define HW_ICSS_INTC_CMR9_CH_MAP_38_SHIFT                      (16U)
#define HW_ICSS_INTC_CMR9_CH_MAP_38_MASK                       (0x000f0000U)

#define HW_ICSS_INTC_CMR9_CH_MAP_39_SHIFT                      (24U)
#define HW_ICSS_INTC_CMR9_CH_MAP_39_MASK                       (0x0f000000U)

#define HW_ICSS_INTC_CMR10_CH_MAP_40_SHIFT                     (0U)
#define HW_ICSS_INTC_CMR10_CH_MAP_40_MASK                      (0x0000000fU)

#define HW_ICSS_INTC_CMR10_CH_MAP_41_SHIFT                     (8U)
#define HW_ICSS_INTC_CMR10_CH_MAP_41_MASK                      (0x00000f00U)

#define HW_ICSS_INTC_CMR10_CH_MAP_42_SHIFT                     (16U)
#define HW_ICSS_INTC_CMR10_CH_MAP_42_MASK                      (0x000f0000U)

#define HW_ICSS_INTC_CMR10_CH_MAP_43_SHIFT                     (24U)
#define HW_ICSS_INTC_CMR10_CH_MAP_43_MASK                      (0x0f000000U)

#define HW_ICSS_INTC_CMR11_CH_MAP_44_SHIFT                     (0U)
#define HW_ICSS_INTC_CMR11_CH_MAP_44_MASK                      (0x0000000fU)

#define HW_ICSS_INTC_CMR11_CH_MAP_45_SHIFT                     (8U)
#define HW_ICSS_INTC_CMR11_CH_MAP_45_MASK                      (0x00000f00U)

#define HW_ICSS_INTC_CMR11_CH_MAP_46_SHIFT                     (16U)
#define HW_ICSS_INTC_CMR11_CH_MAP_46_MASK                      (0x000f0000U)

#define HW_ICSS_INTC_CMR11_CH_MAP_47_SHIFT                     (24U)
#define HW_ICSS_INTC_CMR11_CH_MAP_47_MASK                      (0x0f000000U)

#define HW_ICSS_INTC_CMR12_CH_MAP_48_SHIFT                     (0U)
#define HW_ICSS_INTC_CMR12_CH_MAP_48_MASK                      (0x0000000fU)

#define HW_ICSS_INTC_CMR12_CH_MAP_49_SHIFT                     (8U)
#define HW_ICSS_INTC_CMR12_CH_MAP_49_MASK                      (0x00000f00U)

#define HW_ICSS_INTC_CMR12_CH_MAP_50_SHIFT                     (16U)
#define HW_ICSS_INTC_CMR12_CH_MAP_50_MASK                      (0x000f0000U)

#define HW_ICSS_INTC_CMR12_CH_MAP_51_SHIFT                     (24U)
#define HW_ICSS_INTC_CMR12_CH_MAP_51_MASK                      (0x0f000000U)

#define HW_ICSS_INTC_CMR13_CH_MAP_52_SHIFT                     (0U)
#define HW_ICSS_INTC_CMR13_CH_MAP_52_MASK                      (0x0000000fU)

#define HW_ICSS_INTC_CMR13_CH_MAP_53_SHIFT                     (8U)
#define HW_ICSS_INTC_CMR13_CH_MAP_53_MASK                      (0x00000f00U)

#define HW_ICSS_INTC_CMR13_CH_MAP_54_SHIFT                     (16U)
#define HW_ICSS_INTC_CMR13_CH_MAP_54_MASK                      (0x000f0000U)

#define HW_ICSS_INTC_CMR13_CH_MAP_55_SHIFT                     (24U)
#define HW_ICSS_INTC_CMR13_CH_MAP_55_MASK                      (0x0f000000U)

#define HW_ICSS_INTC_CMR14_CH_MAP_56_SHIFT                     (0U)
#define HW_ICSS_INTC_CMR14_CH_MAP_56_MASK                      (0x0000000fU)

#define HW_ICSS_INTC_CMR14_CH_MAP_57_SHIFT                     (8U)
#define HW_ICSS_INTC_CMR14_CH_MAP_57_MASK                      (0x00000f00U)

#define HW_ICSS_INTC_CMR14_CH_MAP_58_SHIFT                     (16U)
#define HW_ICSS_INTC_CMR14_CH_MAP_58_MASK                      (0x000f0000U)

#define HW_ICSS_INTC_CMR14_CH_MAP_59_SHIFT                     (24U)
#define HW_ICSS_INTC_CMR14_CH_MAP_59_MASK                      (0x0f000000U)

#define HW_ICSS_INTC_CMR15_CH_MAP_60_SHIFT                     (0U)
#define HW_ICSS_INTC_CMR15_CH_MAP_60_MASK                      (0x0000000fU)

#define HW_ICSS_INTC_CMR15_CH_MAP_61_SHIFT                     (8U)
#define HW_ICSS_INTC_CMR15_CH_MAP_61_MASK                      (0x00000f00U)

#define HW_ICSS_INTC_CMR15_CH_MAP_62_SHIFT                     (16U)
#define HW_ICSS_INTC_CMR15_CH_MAP_62_MASK                      (0x000f0000U)

#define HW_ICSS_INTC_CMR15_CH_MAP_63_SHIFT                     (24U)
#define HW_ICSS_INTC_CMR15_CH_MAP_63_MASK                      (0x0f000000U)

#define HW_ICSS_INTC_HMR0_HINT_MAP_0_SHIFT                     (0U)
#define HW_ICSS_INTC_HMR0_HINT_MAP_0_MASK                      (0x0000000fU)

#define HW_ICSS_INTC_HMR0_HINT_MAP_1_SHIFT                     (8U)
#define HW_ICSS_INTC_HMR0_HINT_MAP_1_MASK                      (0x00000f00U)

#define HW_ICSS_INTC_HMR0_HINT_MAP_2_SHIFT                     (16U)
#define HW_ICSS_INTC_HMR0_HINT_MAP_2_MASK                      (0x000f0000U)

#define HW_ICSS_INTC_HMR0_HINT_MAP_3_SHIFT                     (24U)
#define HW_ICSS_INTC_HMR0_HINT_MAP_3_MASK                      (0x0f000000U)

#define HW_ICSS_INTC_HMR1_HINT_MAP_4_SHIFT                     (0U)
#define HW_ICSS_INTC_HMR1_HINT_MAP_4_MASK                      (0x0000000fU)

#define HW_ICSS_INTC_HMR1_HINT_MAP_5_SHIFT                     (8U)
#define HW_ICSS_INTC_HMR1_HINT_MAP_5_MASK                      (0x00000f00U)

#define HW_ICSS_INTC_HMR1_HINT_MAP_6_SHIFT                     (16U)
#define HW_ICSS_INTC_HMR1_HINT_MAP_6_MASK                      (0x000f0000U)

#define HW_ICSS_INTC_HMR1_HINT_MAP_7_SHIFT                     (24U)
#define HW_ICSS_INTC_HMR1_HINT_MAP_7_MASK                      (0x0f000000U)

#define HW_ICSS_INTC_HMR2_HINT_MAP_8_SHIFT                     (0U)
#define HW_ICSS_INTC_HMR2_HINT_MAP_8_MASK                      (0x0000000fU)

#define HW_ICSS_INTC_HMR2_HINT_MAP_9_SHIFT                     (8U)
#define HW_ICSS_INTC_HMR2_HINT_MAP_9_MASK                      (0x00000f00U)

#define HW_ICSS_INTC_HIPIR0_PRI_HINT_0_SHIFT                   (0U)
#define HW_ICSS_INTC_HIPIR0_PRI_HINT_0_MASK                    (0x000003ffU)

#define HW_ICSS_INTC_HIPIR0_NONE_HINT_0_SHIFT                  (31U)
#define HW_ICSS_INTC_HIPIR0_NONE_HINT_0_MASK                   (0x80000000U)

#define HW_ICSS_INTC_HIPIR1_PRI_HINT_1_SHIFT                   (0U)
#define HW_ICSS_INTC_HIPIR1_PRI_HINT_1_MASK                    (0x000003ffU)

#define HW_ICSS_INTC_HIPIR1_NONE_HINT_1_SHIFT                  (31U)
#define HW_ICSS_INTC_HIPIR1_NONE_HINT_1_MASK                   (0x80000000U)

#define HW_ICSS_INTC_HIPIR2_PRI_HINT_2_SHIFT                   (0U)
#define HW_ICSS_INTC_HIPIR2_PRI_HINT_2_MASK                    (0x000003ffU)

#define HW_ICSS_INTC_HIPIR2_NONE_HINT_2_SHIFT                  (31U)
#define HW_ICSS_INTC_HIPIR2_NONE_HINT_2_MASK                   (0x80000000U)

#define HW_ICSS_INTC_HIPIR3_PRI_HINT_3_SHIFT                   (0U)
#define HW_ICSS_INTC_HIPIR3_PRI_HINT_3_MASK                    (0x000003ffU)

#define HW_ICSS_INTC_HIPIR3_NONE_HINT_3_SHIFT                  (31U)
#define HW_ICSS_INTC_HIPIR3_NONE_HINT_3_MASK                   (0x80000000U)

#define HW_ICSS_INTC_HIPIR4_PRI_HINT_4_SHIFT                   (0U)
#define HW_ICSS_INTC_HIPIR4_PRI_HINT_4_MASK                    (0x000003ffU)

#define HW_ICSS_INTC_HIPIR4_NONE_HINT_4_SHIFT                  (31U)
#define HW_ICSS_INTC_HIPIR4_NONE_HINT_4_MASK                   (0x80000000U)

#define HW_ICSS_INTC_HIPIR5_PRI_HINT_5_SHIFT                   (0U)
#define HW_ICSS_INTC_HIPIR5_PRI_HINT_5_MASK                    (0x000003ffU)

#define HW_ICSS_INTC_HIPIR5_NONE_HINT_5_SHIFT                  (31U)
#define HW_ICSS_INTC_HIPIR5_NONE_HINT_5_MASK                   (0x80000000U)

#define HW_ICSS_INTC_HIPIR6_PRI_HINT_6_SHIFT                   (0U)
#define HW_ICSS_INTC_HIPIR6_PRI_HINT_6_MASK                    (0x000003ffU)

#define HW_ICSS_INTC_HIPIR6_NONE_HINT_6_SHIFT                  (31U)
#define HW_ICSS_INTC_HIPIR6_NONE_HINT_6_MASK                   (0x80000000U)

#define HW_ICSS_INTC_HIPIR7_PRI_HINT_7_SHIFT                   (0U)
#define HW_ICSS_INTC_HIPIR7_PRI_HINT_7_MASK                    (0x000003ffU)

#define HW_ICSS_INTC_HIPIR7_NONE_HINT_7_SHIFT                  (31U)
#define HW_ICSS_INTC_HIPIR7_NONE_HINT_7_MASK                   (0x80000000U)

#define HW_ICSS_INTC_HIPIR8_PRI_HINT_8_SHIFT                   (0U)
#define HW_ICSS_INTC_HIPIR8_PRI_HINT_8_MASK                    (0x000003ffU)

#define HW_ICSS_INTC_HIPIR8_NONE_HINT_8_SHIFT                  (31U)
#define HW_ICSS_INTC_HIPIR8_NONE_HINT_8_MASK                   (0x80000000U)

#define HW_ICSS_INTC_HIPIR9_PRI_HINT_9_SHIFT                   (0U)
#define HW_ICSS_INTC_HIPIR9_PRI_HINT_9_MASK                    (0x000003ffU)

#define HW_ICSS_INTC_HIPIR9_NONE_HINT_9_SHIFT                  (31U)
#define HW_ICSS_INTC_HIPIR9_NONE_HINT_9_MASK                   (0x80000000U)

#define HW_ICSS_INTC_SIPR0_POLARITY_31_0_SHIFT                 (0U)
#define HW_ICSS_INTC_SIPR0_POLARITY_31_0_MASK                  (0xffffffffU)

#define HW_ICSS_INTC_SIPR1_POLARITY_63_32_SHIFT                (0U)
#define HW_ICSS_INTC_SIPR1_POLARITY_63_32_MASK                 (0xffffffffU)

#define HW_ICSS_INTC_SITR0_TYPE_31_0_SHIFT                     (0U)
#define HW_ICSS_INTC_SITR0_TYPE_31_0_MASK                      (0xffffffffU)

#define HW_ICSS_INTC_SITR1_TYPE_63_32_SHIFT                    (0U)
#define HW_ICSS_INTC_SITR1_TYPE_63_32_MASK                     (0xffffffffU)

#define HW_ICSS_INTC_HINLR0_NEST_HINT_0_SHIFT                  (0U)
#define HW_ICSS_INTC_HINLR0_NEST_HINT_0_MASK                   (0x000001ffU)

#define HW_ICSS_INTC_HINLR0_AUTO_OVERRIDE_SHIFT                (31U)
#define HW_ICSS_INTC_HINLR0_AUTO_OVERRIDE_MASK                 (0x80000000U)

#define HW_ICSS_INTC_HINLR1_NEST_HINT_1_SHIFT                  (0U)
#define HW_ICSS_INTC_HINLR1_NEST_HINT_1_MASK                   (0x000001ffU)

#define HW_ICSS_INTC_HINLR1_AUTO_OVERRIDE_SHIFT                (31U)
#define HW_ICSS_INTC_HINLR1_AUTO_OVERRIDE_MASK                 (0x80000000U)

#define HW_ICSS_INTC_HINLR2_NEST_HINT_2_SHIFT                  (0U)
#define HW_ICSS_INTC_HINLR2_NEST_HINT_2_MASK                   (0x000001ffU)

#define HW_ICSS_INTC_HINLR2_AUTO_OVERRIDE_SHIFT                (31U)
#define HW_ICSS_INTC_HINLR2_AUTO_OVERRIDE_MASK                 (0x80000000U)

#define HW_ICSS_INTC_HINLR3_NEST_HINT_3_SHIFT                  (0U)
#define HW_ICSS_INTC_HINLR3_NEST_HINT_3_MASK                   (0x000001ffU)

#define HW_ICSS_INTC_HINLR3_AUTO_OVERRIDE_SHIFT                (31U)
#define HW_ICSS_INTC_HINLR3_AUTO_OVERRIDE_MASK                 (0x80000000U)

#define HW_ICSS_INTC_HINLR4_NEST_HINT_4_SHIFT                  (0U)
#define HW_ICSS_INTC_HINLR4_NEST_HINT_4_MASK                   (0x000001ffU)

#define HW_ICSS_INTC_HINLR4_AUTO_OVERRIDE_SHIFT                (31U)
#define HW_ICSS_INTC_HINLR4_AUTO_OVERRIDE_MASK                 (0x80000000U)

#define HW_ICSS_INTC_HINLR5_NEST_HINT_5_SHIFT                  (0U)
#define HW_ICSS_INTC_HINLR5_NEST_HINT_5_MASK                   (0x000001ffU)

#define HW_ICSS_INTC_HINLR5_AUTO_OVERRIDE_SHIFT                (31U)
#define HW_ICSS_INTC_HINLR5_AUTO_OVERRIDE_MASK                 (0x80000000U)

#define HW_ICSS_INTC_HINLR6_NEST_HINT_6_SHIFT                  (0U)
#define HW_ICSS_INTC_HINLR6_NEST_HINT_6_MASK                   (0x000001ffU)

#define HW_ICSS_INTC_HINLR6_AUTO_OVERRIDE_SHIFT                (31U)
#define HW_ICSS_INTC_HINLR6_AUTO_OVERRIDE_MASK                 (0x80000000U)

#define HW_ICSS_INTC_HINLR7_NEST_HINT_7_SHIFT                  (0U)
#define HW_ICSS_INTC_HINLR7_NEST_HINT_7_MASK                   (0x000001ffU)

#define HW_ICSS_INTC_HINLR7_AUTO_OVERRIDE_SHIFT                (31U)
#define HW_ICSS_INTC_HINLR7_AUTO_OVERRIDE_MASK                 (0x80000000U)

#define HW_ICSS_INTC_HINLR8_NEST_HINT_8_SHIFT                  (0U)
#define HW_ICSS_INTC_HINLR8_NEST_HINT_8_MASK                   (0x000001ffU)

#define HW_ICSS_INTC_HINLR8_AUTO_OVERRIDE_SHIFT                (31U)
#define HW_ICSS_INTC_HINLR8_AUTO_OVERRIDE_MASK                 (0x80000000U)

#define HW_ICSS_INTC_HINLR9_NEST_HINT_9_SHIFT                  (0U)
#define HW_ICSS_INTC_HINLR9_NEST_HINT_9_MASK                   (0x000001ffU)

#define HW_ICSS_INTC_HINLR9_AUTO_OVERRIDE_SHIFT                (31U)
#define HW_ICSS_INTC_HINLR9_AUTO_OVERRIDE_MASK                 (0x80000000U)

#define HW_ICSS_INTC_HIER_ENABLE_HINT_SHIFT                    (0U)
#define HW_ICSS_INTC_HIER_ENABLE_HINT_MASK                     (0x000003ffU)

#ifdef __cplusplus
}
#endif

#endif /* HW_ICSS_INTC_H_ */
