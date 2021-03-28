/*
* hw_emif4d.h
*
* Register-level header file for EMIF
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

#ifndef HW_EMIF_H_
#define HW_EMIF_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define EMIF_MODULE_ID_AND_REVISION                               (0x0U)
#define EMIF_STS                                                  (0x4U)
#define EMIF_SDRAM_CONFIG                                         (0x8U)
#define EMIF_SDRAM_CONFIG_2                                       (0xcU)
#define EMIF_SDRAM_REF_CTRL                                       (0x10U)
#define EMIF_SDRAM_REF_CTRL_SHDW                                (0x14U)
#define EMIF_SDRAM_TIM_1                                          (0x18U)
#define EMIF_SDRAM_TIM_1_SHDW                                   (0x1cU)
#define EMIF_SDRAM_TIM_2                                          (0x20U)
#define EMIF_SDRAM_TIM_2_SHDW                                   (0x24U)
#define EMIF_SDRAM_TIM_3                                          (0x28U)
#define EMIF_SDRAM_TIM_3_SHDW                                   (0x2cU)
#define EMIF_LPDDR2_NVM_TIM                                       (0x30U)
#define EMIF_LPDDR2_NVM_TIM_SHDW                                (0x34U)
#define EMIF_PWR_MGMT_CTRL                                (0x38U)
#define EMIF_PWR_MGMT_CTRL_SHDW                         (0x3cU)
#define EMIF_LPDDR2_MODE_REG_DATA                                 (0x40U)
#define EMIF_LPDDR2_MODE_REG_CONFIG                               (0x50U)
#define EMIF_OCP_CONFIG                                           (0x54U)
#define EMIF_OCP_CONFIG_VALUE_1                                   (0x58U)
#define EMIF_OCP_CONFIG_VALUE_2                                   (0x5cU)
#define EMIF_IODFT_TLGC                         (0x60U)
#define EMIF_IODFT_TEST_LOGIC_CTRL_MISR_RESULT                    (0x64U)
#define EMIF_IODFT_TEST_LOGIC_ADDR_MISR_RESULT                    (0x68U)
#define EMIF_IODFT_TEST_LOGIC_DATA_MISR_RESULT_1                  (0x6cU)
#define EMIF_IODFT_TEST_LOGIC_DATA_MISR_RESULT_2                  (0x70U)
#define EMIF_IODFT_TEST_LOGIC_DATA_MISR_RESULT_3                  (0x74U)
#define EMIF_PERFORMANCE_CTR_1                                    (0x80U)
#define EMIF_PERFORMANCE_CTR_2                                    (0x84U)
#define EMIF_PERFORMANCE_CTR_CONFIG                               (0x88U)
#define EMIF_PERFORMANCE_CTR_MASTER_REGION_SELECT                 (0x8cU)
#define EMIF_PERFORMANCE_CTR_TIME                                 (0x90U)
#define EMIF_DLL_CALIB_CTRL                                       (0x98U)
#define EMIF_DLL_CALIB_CTRL_SHDW                                (0x9cU)
#define EMIF_END_OF_INTR                                          (0xa0U)
#define EMIF_SYSTEM_OCP_INTR_RAW_STS                              (0xa4U)
#define EMIF_LOW_LAT_OCP_INTR_RAW_STS                             (0xa8U)
#define EMIF_SYSTEM_OCP_INTR_STS                                  (0xacU)
#define EMIF_LOW_LAT_OCP_INTR_STS                                 (0xb0U)
#define EMIF_SYSTEM_OCP_INTR_EN_SET                               (0xb4U)
#define EMIF_LOW_LAT_OCP_INTR_EN_SET                              (0xb8U)
#define EMIF_SYSTEM_OCP_INTR_EN_CLR                               (0xbcU)
#define EMIF_LOW_LAT_OCP_INTR_EN_CLR                              (0xc0U)
#define EMIF_ZQ_CONFIG            (0xc8U)
#define EMIF_TEMP_ALERT_CONFIG                             (0xccU)
#define EMIF_OCP_ERROR_LOG                                        (0xd0U)
#define EMIF_RDWR_LVL_RMP_WIN                      (0xd4U)
#define EMIF_RDWR_LVL_RMP_CTRL                        (0xd8U)
#define EMIF_RDWR_LVL_CTRL                             (0xdcU)
#define EMIF_DDR_PHY_CTRL_1                                       (0xe4U)
#define EMIF_DDR_PHY_CTRL_1_SHDW                                (0xe8U)
#define EMIF_DDR_PHY_CTRL_2                                       (0xecU)
#define EMIF_PRI_COS_MAP                 (0x100U)
#define EMIF_CONNID_COS_1_MAP          (0x104U)
#define EMIF_CONNID_COS_2_MAP          (0x108U)
#define EMIF_ECC_CTRL_REG                                         (0x110U)
#define EMIF_ECC_ADDR_RANGE_1                                     (0x114U)
#define EMIF_ECC_ADDR_RANGE_2                                     (0x118U)
#define EMIF_RD_WR_EXEC_THR                             (0x120U)
#define EMIF_COS_CONFIG                                           (0x124U)
#define EMIF_1B_ECC_ERR_CNT                                       (0x130U)
#define EMIF_1B_ECC_ERR_THRSH                                     (0x134U)
#define EMIF_1B_ECC_ERR_DIST_1                                    (0x138U)
#define EMIF_1B_ECC_ERR_ADDR_LOG                                  (0x13cU)
#define EMIF_2B_ECC_ERR_ADDR_LOG                                  (0x140U)
#define EMIF_PHY_STS_1                                            (0x144U)
#define EMIF_PHY_STS_2                                            (0x148U)
#define EMIF_PHY_STS_3                                            (0x14cU)
#define EMIF_PHY_STS_4                                            (0x150U)
#define EMIF_PHY_STS_5                                            (0x154U)
#define EMIF_PHY_STS_6                                            (0x158U)
#define EMIF_PHY_STS_7                                            (0x15cU)
#define EMIF_PHY_STS_8                                            (0x160U)
#define EMIF_PHY_STS_9                                            (0x164U)
#define EMIF_PHY_STS_10                                           (0x168U)
#define EMIF_PHY_STS_11                                           (0x16cU)
#define EMIF_PHY_STS_12                                           (0x170U)
#define EMIF_PHY_STS_13                                           (0x174U)
#define EMIF_PHY_STS_14                                           (0x178U)
#define EMIF_PHY_STS_15                                           (0x17cU)
#define EMIF_PHY_STS_16                                           (0x180U)
#define EMIF_PHY_STS_17                                           (0x184U)
#define EMIF_PHY_STS_18                                           (0x188U)
#define EMIF_PHY_STS_19                                           (0x18cU)
#define EMIF_PHY_STS_20                                           (0x190U)
#define EMIF_PHY_STS_21                                           (0x194U)
#define EMIF_PHY_STS_22                                           (0x198U)
#define EMIF_PHY_STS_23                                           (0x19cU)
#define EMIF_PHY_STS_24                                           (0x1a0U)
#define EMIF_PHY_STS_25                                           (0x1a4U)
#define EMIF_PHY_STS_26                                           (0x1a8U)
#define EMIF_PHY_STS_27                                           (0x1acU)
#define EMIF_PHY_STS_28                                           (0x1b0U)
#define EMIF_EXT_PHY_CTRL_1                                       (0x200U)
#define EMIF_EXT_PHY_CTRL_1_SHDW                                (0x204U)
#define EMIF_EXT_PHY_CTRL_2                                       (0x208U)
#define EMIF_EXT_PHY_CTRL_2_SHDW                                (0x20cU)
#define EMIF_EXT_PHY_CTRL_3                                       (0x210U)
#define EMIF_EXT_PHY_CTRL_3_SHDW                                (0x214U)
#define EMIF_EXT_PHY_CTRL_4                                       (0x218U)
#define EMIF_EXT_PHY_CTRL_4_SHDW                                (0x21cU)
#define EMIF_EXT_PHY_CTRL_5                                       (0x220U)
#define EMIF_EXT_PHY_CTRL_5_SHDW                                (0x224U)
#define EMIF_EXT_PHY_CTRL_6                                       (0x228U)
#define EMIF_EXT_PHY_CTRL_6_SHDW                                (0x22cU)
#define EMIF_EXT_PHY_CTRL_7                                       (0x230U)
#define EMIF_EXT_PHY_CTRL_7_SHDW                                (0x234U)
#define EMIF_EXT_PHY_CTRL_8                                       (0x238U)
#define EMIF_EXT_PHY_CTRL_8_SHDW                                (0x23cU)
#define EMIF_EXT_PHY_CTRL_9                                       (0x240U)
#define EMIF_EXT_PHY_CTRL_9_SHDW                                (0x244U)
#define EMIF_EXT_PHY_CTRL_10                                      (0x248U)
#define EMIF_EXT_PHY_CTRL_10_SHDW                               (0x24cU)
#define EMIF_EXT_PHY_CTRL_11                                      (0x250U)
#define EMIF_EXT_PHY_CTRL_11_SHDW                               (0x254U)
#define EMIF_EXT_PHY_CTRL_12                                      (0x258U)
#define EMIF_EXT_PHY_CTRL_12_SHDW                               (0x25cU)
#define EMIF_EXT_PHY_CTRL_13                                      (0x260U)
#define EMIF_EXT_PHY_CTRL_13_SHDW                               (0x264U)
#define EMIF_EXT_PHY_CTRL_14                                      (0x268U)
#define EMIF_EXT_PHY_CTRL_14_SHDW                               (0x26cU)
#define EMIF_EXT_PHY_CTRL_15                                      (0x270U)
#define EMIF_EXT_PHY_CTRL_15_SHDW                               (0x274U)
#define EMIF_EXT_PHY_CTRL_16                                      (0x278U)
#define EMIF_EXT_PHY_CTRL_16_SHDW                               (0x27cU)
#define EMIF_EXT_PHY_CTRL_17                                      (0x280U)
#define EMIF_EXT_PHY_CTRL_17_SHDW                               (0x284U)
#define EMIF_EXT_PHY_CTRL_18                                      (0x288U)
#define EMIF_EXT_PHY_CTRL_18_SHDW                               (0x28cU)
#define EMIF_EXT_PHY_CTRL_19                                      (0x290U)
#define EMIF_EXT_PHY_CTRL_19_SHDW                               (0x294U)
#define EMIF_EXT_PHY_CTRL_20                                      (0x298U)
#define EMIF_EXT_PHY_CTRL_20_SHDW                               (0x29cU)
#define EMIF_EXT_PHY_CTRL_21                                      (0x2a0U)
#define EMIF_EXT_PHY_CTRL_21_SHDW                               (0x2a4U)
#define EMIF_EXT_PHY_CTRL_22                                      (0x2a8U)
#define EMIF_EXT_PHY_CTRL_22_SHDW                               (0x2acU)
#define EMIF_EXT_PHY_CTRL_23                                      (0x2b0U)
#define EMIF_EXT_PHY_CTRL_23_SHDW                               (0x2b4U)
#define EMIF_EXT_PHY_CTRL_24                                      (0x2b8U)
#define EMIF_EXT_PHY_CTRL_24_SHDW                               (0x2bcU)
#define EMIF_EXT_PHY_CTRL_25                                      (0x2c0U)
#define EMIF_EXT_PHY_CTRL_25_SHDW                               (0x2c4U)
#define EMIF_EXT_PHY_CTRL_26                                      (0x2c8U)
#define EMIF_EXT_PHY_CTRL_26_SHDW                               (0x2ccU)
#define EMIF_EXT_PHY_CTRL_27                                      (0x2d0U)
#define EMIF_EXT_PHY_CTRL_27_SHDW                               (0x2d4U)
#define EMIF_EXT_PHY_CTRL_28                                      (0x2d8U)
#define EMIF_EXT_PHY_CTRL_28_SHDW                               (0x2dcU)
#define EMIF_EXT_PHY_CTRL_29                                      (0x2e0U)
#define EMIF_EXT_PHY_CTRL_29_SHDW                               (0x2e4U)
#define EMIF_EXT_PHY_CTRL_30                                      (0x2e8U)
#define EMIF_EXT_PHY_CTRL_30_SHDW                               (0x2ecU)
#define EMIF_EXT_PHY_CTRL_31                                      (0x2f0U)
#define EMIF_EXT_PHY_CTRL_31_SHDW                               (0x2f4U)
#define EMIF_EXT_PHY_CTRL_32                                      (0x2f8U)
#define EMIF_EXT_PHY_CTRL_32_SHDW                               (0x2fcU)
#define EMIF_EXT_PHY_CTRL_33                                      (0x300U)
#define EMIF_EXT_PHY_CTRL_33_SHDW                               (0x304U)
#define EMIF_EXT_PHY_CTRL_34                                      (0x308U)
#define EMIF_EXT_PHY_CTRL_34_SHDW                               (0x30cU)
#define EMIF_EXT_PHY_CTRL_35                                      (0x310U)
#define EMIF_EXT_PHY_CTRL_35_SHDW                               (0x314U)
#define EMIF_EXT_PHY_CTRL_36                                      (0x318U)
#define EMIF_EXT_PHY_CTRL_36_SHDW                               (0x31cU)
#define EMIF_MISC_REG                                             (0x94U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define EMIF_MODULE_ID_AND_REVISION_SCHEME_SHIFT                                      (30U)
#define EMIF_MODULE_ID_AND_REVISION_SCHEME_MASK                                       (0xc0000000U)

#define EMIF_MODULE_ID_AND_REVISION_BU_SHIFT                                          (28U)
#define EMIF_MODULE_ID_AND_REVISION_BU_MASK                                           (0x30000000U)

#define EMIF_MODULE_ID_AND_REVISION_SHIFT                                             (16U)
#define EMIF_MODULE_ID_AND_REVISION_MASK                                              (0x0fff0000U)

#define EMIF_MODULE_ID_AND_REVISION_RTL_VERSION_SHIFT                                 (11U)
#define EMIF_MODULE_ID_AND_REVISION_RTL_VERSION_MASK                                  (0x0000f800U)

#define EMIF_MODULE_ID_AND_REVISION_MAJOR_SHIFT                                       (8U)
#define EMIF_MODULE_ID_AND_REVISION_MAJOR_MASK                                        (0x00000700U)

#define EMIF_MODULE_ID_AND_REVISION_MINOR_SHIFT                                       (0U)
#define EMIF_MODULE_ID_AND_REVISION_MINOR_MASK                                        (0x0000003fU)

#define EMIF_STS_BE_SHIFT                                                             (31U)
#define EMIF_STS_BE_MASK                                                              (0x80000000U)

#define EMIF_STS_DUAL_CLK_MODE_SHIFT                                                  (30U)
#define EMIF_STS_DUAL_CLK_MODE_MASK                                                   (0x40000000U)

#define EMIF_STS_FAST_INIT_SHIFT                                                      (29U)
#define EMIF_STS_FAST_INIT_MASK                                                       (0x20000000U)

#define EMIF_STS_RDLVLGATETO_SHIFT                                                    (6U)
#define EMIF_STS_RDLVLGATETO_MASK                                                     (0x00000040U)

#define EMIF_STS_RDLVLTO_SHIFT                                                        (5U)
#define EMIF_STS_RDLVLTO_MASK                                                         (0x00000020U)

#define EMIF_STS_WRLVLTO_SHIFT                                                        (4U)
#define EMIF_STS_WRLVLTO_MASK                                                         (0x00000010U)

#define EMIF_STS_PHY_DLL_READY_SHIFT                                                  (2U)
#define EMIF_STS_PHY_DLL_READY_MASK                                                   (0x00000004U)

#define EMIF_SDRAM_CONFIG_TYPE_SHIFT                                                  (29U)
#define EMIF_SDRAM_CONFIG_TYPE_MASK                                                   (0xe0000000U)

#define EMIF_SDRAM_CONFIG_IBANK_POS_SHIFT                                             (27U)
#define EMIF_SDRAM_CONFIG_IBANK_POS_MASK                                              (0x18000000U)

#define EMIF_SDRAM_CONFIG_DDR_TERM_SHIFT                                              (24U)
#define EMIF_SDRAM_CONFIG_DDR_TERM_MASK                                               (0x07000000U)

#define EMIF_SDRAM_CONFIG_DDR2_DDQS_SHIFT                                             (23U)
#define EMIF_SDRAM_CONFIG_DDR2_DDQS_MASK                                              (0x00800000U)

#define EMIF_SDRAM_CONFIG_DYN_ODT_SHIFT                                               (21U)
#define EMIF_SDRAM_CONFIG_DYN_ODT_MASK                                                (0x00600000U)

#define EMIF_SDRAM_CONFIG_DDR_DISABLE_DLL_SHIFT                                       (20U)
#define EMIF_SDRAM_CONFIG_DDR_DISABLE_DLL_MASK                                        (0x00100000U)

#define EMIF_SDRAM_CONFIG_DRIVE_SHIFT                                                 (18U)
#define EMIF_SDRAM_CONFIG_DRIVE_MASK                                                  (0x000c0000U)

#define EMIF_SDRAM_CONFIG_CWL_SHIFT                                                   (16U)
#define EMIF_SDRAM_CONFIG_CWL_MASK                                                    (0x00030000U)

#define EMIF_SDRAM_CONFIG_NARROW_MODE_SHIFT                                           (14U)
#define EMIF_SDRAM_CONFIG_NARROW_MODE_MASK                                            (0x0000c000U)

#define EMIF_SDRAM_CONFIG_CL_SHIFT                                                    (10U)
#define EMIF_SDRAM_CONFIG_CL_MASK                                                     (0x00003c00U)

#define EMIF_SDRAM_CONFIG_ROWSIZE_SHIFT                                               (7U)
#define EMIF_SDRAM_CONFIG_ROWSIZE_MASK                                                (0x00000380U)

#define EMIF_SDRAM_CONFIG_IBANK_SHIFT                                                 (4U)
#define EMIF_SDRAM_CONFIG_IBANK_MASK                                                  (0x00000070U)

#define EMIF_SDRAM_CONFIG_EBANK_SHIFT                                                 (3U)
#define EMIF_SDRAM_CONFIG_EBANK_MASK                                                  (0x00000008U)

#define EMIF_SDRAM_CONFIG_PAGESIZE_SHIFT                                              (0U)
#define EMIF_SDRAM_CONFIG_PAGESIZE_MASK                                               (0x00000007U)

#define EMIF_SDRAM_CONFIG_2_CS1NVMEN_SHIFT                                            (30U)
#define EMIF_SDRAM_CONFIG_2_CS1NVMEN_MASK                                             (0x40000000U)

#define EMIF_SDRAM_CONFIG_2_EBANK_POS_SHIFT                                           (27U)
#define EMIF_SDRAM_CONFIG_2_EBANK_POS_MASK                                            (0x08000000U)

#define EMIF_SDRAM_CONFIG_2_RDBNUM_SHIFT                                              (4U)
#define EMIF_SDRAM_CONFIG_2_RDBNUM_MASK                                               (0x00000030U)

#define EMIF_SDRAM_CONFIG_2_RDBSIZE_SHIFT                                             (0U)
#define EMIF_SDRAM_CONFIG_2_RDBSIZE_MASK                                              (0x00000007U)

#define EMIF_SDRAM_REF_CTRL_INITREF_DIS_SHIFT                                         (31U)
#define EMIF_SDRAM_REF_CTRL_INITREF_DIS_MASK                                          (0x80000000U)

#define EMIF_SDRAM_REF_CTRL_SRT_SHIFT                                                 (29U)
#define EMIF_SDRAM_REF_CTRL_SRT_MASK                                                  (0x20000000U)

#define EMIF_SDRAM_REF_CTRL_ASR_SHIFT                                                 (28U)
#define EMIF_SDRAM_REF_CTRL_ASR_MASK                                                  (0x10000000U)

#define EMIF_SDRAM_REF_CTRL_PASR_SHIFT                                                (24U)
#define EMIF_SDRAM_REF_CTRL_PASR_MASK                                                 (0x07000000U)

#define EMIF_SDRAM_REF_CTRL_RATE_SHIFT                                                (0U)
#define EMIF_SDRAM_REF_CTRL_RATE_MASK                                                 (0x0000ffffU)

#define EMIF_SDRAM_REF_CTRL_SHDW_RATE_SHDW_SHIFT                                    (0U)
#define EMIF_SDRAM_REF_CTRL_SHDW_RATE_SHDW_MASK                                     (0x0000ffffU)

#define EMIF_SDRAM_TIM_1_T_RTW_SHIFT                                                  (29U)
#define EMIF_SDRAM_TIM_1_T_RTW_MASK                                                   (0xe0000000U)

#define EMIF_SDRAM_TIM_1_T_RP_SHIFT                                                   (25U)
#define EMIF_SDRAM_TIM_1_T_RP_MASK                                                    (0x1e000000U)

#define EMIF_SDRAM_TIM_1_T_RCD_SHIFT                                                  (21U)
#define EMIF_SDRAM_TIM_1_T_RCD_MASK                                                   (0x01e00000U)

#define EMIF_SDRAM_TIM_1_T_WR_SHIFT                                                   (17U)
#define EMIF_SDRAM_TIM_1_T_WR_MASK                                                    (0x001e0000U)

#define EMIF_SDRAM_TIM_1_T_RAS_SHIFT                                                  (12U)
#define EMIF_SDRAM_TIM_1_T_RAS_MASK                                                   (0x0001f000U)

#define EMIF_SDRAM_TIM_1_T_RC_SHIFT                                                   (6U)
#define EMIF_SDRAM_TIM_1_T_RC_MASK                                                    (0x00000fc0U)

#define EMIF_SDRAM_TIM_1_T_RRD_SHIFT                                                  (3U)
#define EMIF_SDRAM_TIM_1_T_RRD_MASK                                                   (0x00000038U)

#define EMIF_SDRAM_TIM_1_T_WTR_SHIFT                                                  (0U)
#define EMIF_SDRAM_TIM_1_T_WTR_MASK                                                   (0x00000007U)

#define EMIF_SDRAM_TIM_1_SHDW_T_RTW_SHDW_SHIFT                                      (29U)
#define EMIF_SDRAM_TIM_1_SHDW_T_RTW_SHDW_MASK                                       (0xe0000000U)

#define EMIF_SDRAM_TIM_1_SHDW_T_RP_SHDW_SHIFT                                       (25U)
#define EMIF_SDRAM_TIM_1_SHDW_T_RP_SHDW_MASK                                        (0x1e000000U)

#define EMIF_SDRAM_TIM_1_SHDW_T_RCD_SHDW_SHIFT                                      (21U)
#define EMIF_SDRAM_TIM_1_SHDW_T_RCD_SHDW_MASK                                       (0x01e00000U)

#define EMIF_SDRAM_TIM_1_SHDW_T_WR_SHDW_SHIFT                                       (17U)
#define EMIF_SDRAM_TIM_1_SHDW_T_WR_SHDW_MASK                                        (0x001e0000U)

#define EMIF_SDRAM_TIM_1_SHDW_T_RAS_SHDW_SHIFT                                      (12U)
#define EMIF_SDRAM_TIM_1_SHDW_T_RAS_SHDW_MASK                                       (0x0001f000U)

#define EMIF_SDRAM_TIM_1_SHDW_T_RC_SHDW_SHIFT                                       (6U)
#define EMIF_SDRAM_TIM_1_SHDW_T_RC_SHDW_MASK                                        (0x00000fc0U)

#define EMIF_SDRAM_TIM_1_SHDW_T_RRD_SHDW_SHIFT                                      (3U)
#define EMIF_SDRAM_TIM_1_SHDW_T_RRD_SHDW_MASK                                       (0x00000038U)

#define EMIF_SDRAM_TIM_1_SHDW_T_WTR_SHDW_SHIFT                                      (0U)
#define EMIF_SDRAM_TIM_1_SHDW_T_WTR_SHDW_MASK                                       (0x00000007U)

#define EMIF_SDRAM_TIM_2_T_XP_SHIFT                                                   (28U)
#define EMIF_SDRAM_TIM_2_T_XP_MASK                                                    (0x70000000U)

#define EMIF_SDRAM_TIM_2_T_ODT_SHIFT                                                  (25U)
#define EMIF_SDRAM_TIM_2_T_ODT_MASK                                                   (0x0e000000U)

#define EMIF_SDRAM_TIM_2_T_XSNR_SHIFT                                                 (16U)
#define EMIF_SDRAM_TIM_2_T_XSNR_MASK                                                  (0x01ff0000U)

#define EMIF_SDRAM_TIM_2_T_XSRD_SHIFT                                                 (6U)
#define EMIF_SDRAM_TIM_2_T_XSRD_MASK                                                  (0x0000ffc0U)

#define EMIF_SDRAM_TIM_2_T_RTP_SHIFT                                                  (3U)
#define EMIF_SDRAM_TIM_2_T_RTP_MASK                                                   (0x00000038U)

#define EMIF_SDRAM_TIM_2_T_CKE_SHIFT                                                  (0U)
#define EMIF_SDRAM_TIM_2_T_CKE_MASK                                                   (0x00000007U)

#define EMIF_SDRAM_TIM_2_SHDW_T_XP_SHDW_SHIFT                                       (28U)
#define EMIF_SDRAM_TIM_2_SHDW_T_XP_SHDW_MASK                                        (0x70000000U)

#define EMIF_SDRAM_TIM_2_SHDW_T_ODSHDW_SHIFT                                        (25U)
#define EMIF_SDRAM_TIM_2_SHDW_T_ODSHDW_MASK                                         (0x0e000000U)

#define EMIF_SDRAM_TIM_2_SHDW_T_XSNR_SHDW_SHIFT                                     (16U)
#define EMIF_SDRAM_TIM_2_SHDW_T_XSNR_SHDW_MASK                                      (0x01ff0000U)

#define EMIF_SDRAM_TIM_2_SHDW_T_XSRD_SHDW_SHIFT                                     (6U)
#define EMIF_SDRAM_TIM_2_SHDW_T_XSRD_SHDW_MASK                                      (0x0000ffc0U)

#define EMIF_SDRAM_TIM_2_SHDW_T_RTP_SHDW_SHIFT                                      (3U)
#define EMIF_SDRAM_TIM_2_SHDW_T_RTP_SHDW_MASK                                       (0x00000038U)

#define EMIF_SDRAM_TIM_2_SHDW_T_CKE_SHDW_SHIFT                                      (0U)
#define EMIF_SDRAM_TIM_2_SHDW_T_CKE_SHDW_MASK                                       (0x00000007U)

#define EMIF_SDRAM_TIM_3_T_PDLL_UL_SHIFT                                              (28U)
#define EMIF_SDRAM_TIM_3_T_PDLL_UL_MASK                                               (0xf0000000U)

#define EMIF_SDRAM_TIM_3_T_CSTA_SHIFT                                                 (24U)
#define EMIF_SDRAM_TIM_3_T_CSTA_MASK                                                  (0x0f000000U)

#define EMIF_SDRAM_TIM_3_T_CKESR_SHIFT                                                (21U)
#define EMIF_SDRAM_TIM_3_T_CKESR_MASK                                                 (0x00e00000U)

#define EMIF_SDRAM_TIM_3_ZQ_ZQCS_SHIFT                                                (15U)
#define EMIF_SDRAM_TIM_3_ZQ_ZQCS_MASK                                                 (0x001f8000U)

#define EMIF_SDRAM_TIM_3_T_TDQSCKMAX_SHIFT                                            (13U)
#define EMIF_SDRAM_TIM_3_T_TDQSCKMAX_MASK                                             (0x00006000U)

#define EMIF_SDRAM_TIM_3_T_RFC_SHIFT                                                  (4U)
#define EMIF_SDRAM_TIM_3_T_RFC_MASK                                                   (0x00001ff0U)

#define EMIF_SDRAM_TIM_3_T_RAS_MAX_SHIFT                                              (0U)
#define EMIF_SDRAM_TIM_3_T_RAS_MAX_MASK                                               (0x0000000fU)

#define EMIF_SDRAM_TIM_3_SHDW_T_PDLL_UL_SHDW_SHIFT                                  (28U)
#define EMIF_SDRAM_TIM_3_SHDW_T_PDLL_UL_SHDW_MASK                                   (0xf0000000U)

#define EMIF_SDRAM_TIM_3_SHDW_T_CSTA_SHDW_SHIFT                                     (24U)
#define EMIF_SDRAM_TIM_3_SHDW_T_CSTA_SHDW_MASK                                      (0x0f000000U)

#define EMIF_SDRAM_TIM_3_SHDW_T_CKESR_SHDW_SHIFT                                    (21U)
#define EMIF_SDRAM_TIM_3_SHDW_T_CKESR_SHDW_MASK                                     (0x00e00000U)

#define EMIF_SDRAM_TIM_3_SHDW_ZQ_ZQCS_SHDW_SHIFT                                    (15U)
#define EMIF_SDRAM_TIM_3_SHDW_ZQ_ZQCS_SHDW_MASK                                     (0x001f8000U)

#define EMIF_SDRAM_TIM_3_SHDW_T_TDQSCKMAX_SHDW_SHIFT                                (13U)
#define EMIF_SDRAM_TIM_3_SHDW_T_TDQSCKMAX_SHDW_MASK                                 (0x00006000U)

#define EMIF_SDRAM_TIM_3_SHDW_T_RFC_SHDW_SHIFT                                      (4U)
#define EMIF_SDRAM_TIM_3_SHDW_T_RFC_SHDW_MASK                                       (0x00001ff0U)

#define EMIF_SDRAM_TIM_3_SHDW_T_RAS_MAX_SHDW_SHIFT                                  (0U)
#define EMIF_SDRAM_TIM_3_SHDW_T_RAS_MAX_SHDW_MASK                                   (0x0000000fU)

#define EMIF_LPDDR2_NVM_TIM_T_XP_SHIFT                                                (28U)
#define EMIF_LPDDR2_NVM_TIM_T_XP_MASK                                                 (0x70000000U)

#define EMIF_LPDDR2_NVM_TIM_T_WTR_SHIFT                                               (24U)
#define EMIF_LPDDR2_NVM_TIM_T_WTR_MASK                                                (0x07000000U)

#define EMIF_LPDDR2_NVM_TIM_T_RP_SHIFT                                                (20U)
#define EMIF_LPDDR2_NVM_TIM_T_RP_MASK                                                 (0x00f00000U)

#define EMIF_LPDDR2_NVM_TIM_T_WRA_SHIFT                                               (16U)
#define EMIF_LPDDR2_NVM_TIM_T_WRA_MASK                                                (0x000f0000U)

#define EMIF_LPDDR2_NVM_TIM_T_RRD_SHIFT                                               (8U)
#define EMIF_LPDDR2_NVM_TIM_T_RRD_MASK                                                (0x0000ff00U)

#define EMIF_LPDDR2_NVM_TIM_T_RCDMIN_SHIFT                                            (0U)
#define EMIF_LPDDR2_NVM_TIM_T_RCDMIN_MASK                                             (0x000000ffU)

#define EMIF_LPDDR2_NVM_TIM_SHDW_T_XP_SHDW_SHIFT                                    (28U)
#define EMIF_LPDDR2_NVM_TIM_SHDW_T_XP_SHDW_MASK                                     (0x70000000U)

#define EMIF_LPDDR2_NVM_TIM_SHDW_T_WTR_SHDW_SHIFT                                   (24U)
#define EMIF_LPDDR2_NVM_TIM_SHDW_T_WTR_SHDW_MASK                                    (0x07000000U)

#define EMIF_LPDDR2_NVM_TIM_SHDW_T_RP_SHDW_SHIFT                                    (20U)
#define EMIF_LPDDR2_NVM_TIM_SHDW_T_RP_SHDW_MASK                                     (0x00f00000U)

#define EMIF_LPDDR2_NVM_TIM_SHDW_T_WRA_SHDW_SHIFT                                   (16U)
#define EMIF_LPDDR2_NVM_TIM_SHDW_T_WRA_SHDW_MASK                                    (0x000f0000U)

#define EMIF_LPDDR2_NVM_TIM_SHDW_T_RRD_SHDW_SHIFT                                   (8U)
#define EMIF_LPDDR2_NVM_TIM_SHDW_T_RRD_SHDW_MASK                                    (0x0000ff00U)

#define EMIF_LPDDR2_NVM_TIM_SHDW_T_RCDMIN_SHDW_SHIFT                                (0U)
#define EMIF_LPDDR2_NVM_TIM_SHDW_T_RCDMIN_SHDW_MASK                                 (0x000000ffU)

#define EMIF_PWR_MGMT_CTRL_PD_TIM_SHIFT                                       (12U)
#define EMIF_PWR_MGMT_CTRL_PD_TIM_MASK                                        (0x0000f000U)

#define EMIF_PWR_MGMT_CTRL_DPD_EN_SHIFT                                       (11U)
#define EMIF_PWR_MGMT_CTRL_DPD_EN_MASK                                        (0x00000800U)

#define EMIF_PWR_MGMT_CTRL_LP_MODE_SHIFT                                      (8U)
#define EMIF_PWR_MGMT_CTRL_LP_MODE_MASK                                       (0x00000700U)

#define EMIF_PWR_MGMT_CTRL_SR_TIM_SHIFT                                       (4U)
#define EMIF_PWR_MGMT_CTRL_SR_TIM_MASK                                        (0x000000f0U)

#define EMIF_PWR_MGMT_CTRL_CS_TIM_SHIFT                                       (0U)
#define EMIF_PWR_MGMT_CTRL_CS_TIM_MASK                                        (0x0000000fU)

#define EMIF_PWR_MGMT_CTRL_SHDW_PD_TIM_SHDW_SHIFT                           (12U)
#define EMIF_PWR_MGMT_CTRL_SHDW_PD_TIM_SHDW_MASK                            (0x0000f000U)

#define EMIF_PWR_MGMT_CTRL_SHDW_SR_TIM_SHDW_SHIFT                           (4U)
#define EMIF_PWR_MGMT_CTRL_SHDW_SR_TIM_SHDW_MASK                            (0x000000f0U)

#define EMIF_PWR_MGMT_CTRL_SHDW_CS_TIM_SHDW_SHIFT                           (0U)
#define EMIF_PWR_MGMT_CTRL_SHDW_CS_TIM_SHDW_MASK                            (0x0000000fU)

#define EMIF_LPDDR2_MODE_REG_DATA_VALUE_0_SHIFT                                       (0U)
#define EMIF_LPDDR2_MODE_REG_DATA_VALUE_0_MASK                                        (0x0000007fU)

#define EMIF_LPDDR2_MODE_REG_CONFIG_CS_SHIFT                                          (31U)
#define EMIF_LPDDR2_MODE_REG_CONFIG_CS_MASK                                           (0x80000000U)

#define EMIF_LPDDR2_MODE_REG_CONFIG_REF_EN_SHIFT                                      (30U)
#define EMIF_LPDDR2_MODE_REG_CONFIG_REF_EN_MASK                                       (0x40000000U)

#define EMIF_LPDDR2_MODE_REG_CONFIG_ADDR_SHIFT                                        (0U)
#define EMIF_LPDDR2_MODE_REG_CONFIG_ADDR_MASK                                         (0x000000ffU)

#define EMIF_OCP_CONFIG_SYS_THRESH_MAX_SHIFT                                          (24U)
#define EMIF_OCP_CONFIG_SYS_THRESH_MAX_MASK                                           (0x0f000000U)

#define EMIF_OCP_CONFIG_MPU_THRESH_MAX_SHIFT                                          (20U)
#define EMIF_OCP_CONFIG_MPU_THRESH_MAX_MASK                                           (0x00f00000U)

#define EMIF_OCP_CONFIG_LL_THRESH_MAX_SHIFT                                           (16U)
#define EMIF_OCP_CONFIG_LL_THRESH_MAX_MASK                                            (0x000f0000U)

#define EMIF_OCP_CONFIG_VALUE_1_SYS_BUS_WIDTH_SHIFT                                   (30U)
#define EMIF_OCP_CONFIG_VALUE_1_SYS_BUS_WIDTH_MASK                                    (0xc0000000U)

#define EMIF_OCP_CONFIG_VALUE_1_LL_BUS_WIDTH_SHIFT                                    (28U)
#define EMIF_OCP_CONFIG_VALUE_1_LL_BUS_WIDTH_MASK                                     (0x30000000U)

#define EMIF_OCP_CONFIG_VALUE_1_WR_FIFO_DEPTH_SHIFT                                   (8U)
#define EMIF_OCP_CONFIG_VALUE_1_WR_FIFO_DEPTH_MASK                                    (0x0000ff00U)

#define EMIF_OCP_CONFIG_VALUE_1_CMD_FIFO_DEPTH_SHIFT                                  (0U)
#define EMIF_OCP_CONFIG_VALUE_1_CMD_FIFO_DEPTH_MASK                                   (0x000000ffU)

#define EMIF_OCP_CONFIG_VALUE_2_RREG_FIFO_DEPTH_SHIFT                                 (16U)
#define EMIF_OCP_CONFIG_VALUE_2_RREG_FIFO_DEPTH_MASK                                  (0x00ff0000U)

#define EMIF_OCP_CONFIG_VALUE_2_RSD_FIFO_DEPTH_SHIFT                                  (8U)
#define EMIF_OCP_CONFIG_VALUE_2_RSD_FIFO_DEPTH_MASK                                   (0x0000ff00U)

#define EMIF_OCP_CONFIG_VALUE_2_RCMD_FIFO_DEPTH_SHIFT                                 (0U)
#define EMIF_OCP_CONFIG_VALUE_2_RCMD_FIFO_DEPTH_MASK                                  (0x000000ffU)

#define EMIF_IODFT_TLGC_TLEC_SHIFT                                  (16U)
#define EMIF_IODFT_TLGC_TLEC_MASK                                   (0xffff0000U)

#define EMIF_IODFT_TLGC_MT_SHIFT                                    (14U)
#define EMIF_IODFT_TLGC_MT_MASK                                     (0x00004000U)

#define EMIF_IODFT_TLGC_ACT_CAP_EN_SHIFT                            (13U)
#define EMIF_IODFT_TLGC_ACT_CAP_EN_MASK                             (0x00002000U)

#define EMIF_IODFT_TLGC_OPG_LD_SHIFT                                (12U)
#define EMIF_IODFT_TLGC_OPG_LD_MASK                                 (0x00001000U)

#define EMIF_IODFT_TLGC_MMS_SHIFT                                   (8U)
#define EMIF_IODFT_TLGC_MMS_MASK                                    (0x00000100U)

#define EMIF_IODFT_TLGC_MC_SHIFT                                    (4U)
#define EMIF_IODFT_TLGC_MC_MASK                                     (0x00000030U)

#define EMIF_IODFT_TLGC_PC_SHIFT                                    (1U)
#define EMIF_IODFT_TLGC_PC_MASK                                     (0x0000000eU)

#define EMIF_IODFT_TLGC_TM_SHIFT                                    (0U)
#define EMIF_IODFT_TLGC_TM_MASK                                     (0x00000001U)

#define EMIF_IODFT_TLGC_RESET_PHY_SHIFT                             (10U)
#define EMIF_IODFT_TLGC_RESET_PHY_MASK                              (0x00000400U)

#define EMIF_IODFT_TEST_LOGIC_CTRL_MISR_RESULT_DQM_TLMR_SHIFT                         (12U)
#define EMIF_IODFT_TEST_LOGIC_CTRL_MISR_RESULT_DQM_TLMR_MASK                          (0x003ff000U)

#define EMIF_IODFT_TEST_LOGIC_CTRL_MISR_RESULT_CTL_TLMR_SHIFT                         (0U)
#define EMIF_IODFT_TEST_LOGIC_CTRL_MISR_RESULT_CTL_TLMR_MASK                          (0x000007ffU)

#define EMIF_IODFT_TEST_LOGIC_ADDR_MISR_RESULT_TLMR_SHIFT                             (0U)
#define EMIF_IODFT_TEST_LOGIC_ADDR_MISR_RESULT_TLMR_MASK                              (0x001fffffU)

#define EMIF_IODFT_TEST_LOGIC_DATA_MISR_RESULT_1_TLMR_31_0_SHIFT                      (0U)
#define EMIF_IODFT_TEST_LOGIC_DATA_MISR_RESULT_1_TLMR_31_0_MASK                       (0xffffffffU)

#define EMIF_IODFT_TEST_LOGIC_DATA_MISR_RESULT_2_TLMR_63_32_SHIFT                     (0U)
#define EMIF_IODFT_TEST_LOGIC_DATA_MISR_RESULT_2_TLMR_63_32_MASK                      (0xffffffffU)

#define EMIF_IODFT_TEST_LOGIC_DATA_MISR_RESULT_3_TLMR_66_64_SHIFT                     (0U)
#define EMIF_IODFT_TEST_LOGIC_DATA_MISR_RESULT_3_TLMR_66_64_MASK                      (0x00000007U)

#define EMIF_PERFORMANCE_CTR_1_CTR1_SHIFT                                             (0U)
#define EMIF_PERFORMANCE_CTR_1_CTR1_MASK                                              (0xffffffffU)

#define EMIF_PERFORMANCE_CTR_2_CTR2_SHIFT                                             (0U)
#define EMIF_PERFORMANCE_CTR_2_CTR2_MASK                                              (0xffffffffU)

#define EMIF_PERFORMANCE_CTR_CONFIG_CNTR2_MCONNID_EN_SHIFT                            (31U)
#define EMIF_PERFORMANCE_CTR_CONFIG_CNTR2_MCONNID_EN_MASK                             (0x80000000U)

#define EMIF_PERFORMANCE_CTR_CONFIG_CNTR2_REGION_EN_SHIFT                             (30U)
#define EMIF_PERFORMANCE_CTR_CONFIG_CNTR2_REGION_EN_MASK                              (0x40000000U)

#define EMIF_PERFORMANCE_CTR_CONFIG_CNTR2_CFG_SHIFT                                   (16U)
#define EMIF_PERFORMANCE_CTR_CONFIG_CNTR2_CFG_MASK                                    (0x000f0000U)

#define EMIF_PERFORMANCE_CTR_CONFIG_CNTR1_MCONNID_EN_SHIFT                            (15U)
#define EMIF_PERFORMANCE_CTR_CONFIG_CNTR1_MCONNID_EN_MASK                             (0x00008000U)

#define EMIF_PERFORMANCE_CTR_CONFIG_CNTR1_REGION_EN_SHIFT                             (14U)
#define EMIF_PERFORMANCE_CTR_CONFIG_CNTR1_REGION_EN_MASK                              (0x00004000U)

#define EMIF_PERFORMANCE_CTR_CONFIG_CNTR1_CFG_SHIFT                                   (0U)
#define EMIF_PERFORMANCE_CTR_CONFIG_CNTR1_CFG_MASK                                    (0x0000000fU)

#define EMIF_PERFORMANCE_CTR_MASTER_REGION_SELECT_MCONNID2_SHIFT                      (24U)
#define EMIF_PERFORMANCE_CTR_MASTER_REGION_SELECT_MCONNID2_MASK                       (0xff000000U)

#define EMIF_PERFORMANCE_CTR_MASTER_REGION_SELECT_SEL2_SHIFT                          (16U)
#define EMIF_PERFORMANCE_CTR_MASTER_REGION_SELECT_SEL2_MASK                           (0x00030000U)

#define EMIF_PERFORMANCE_CTR_MASTER_REGION_SELECT_MCONNID1_SHIFT                      (8U)
#define EMIF_PERFORMANCE_CTR_MASTER_REGION_SELECT_MCONNID1_MASK                       (0x0000ff00U)

#define EMIF_PERFORMANCE_CTR_MASTER_REGION_SELECT_SEL1_SHIFT                          (0U)
#define EMIF_PERFORMANCE_CTR_MASTER_REGION_SELECT_SEL1_MASK                           (0x00000003U)

#define EMIF_PERFORMANCE_CTR_TIME_TOTAL_SHIFT                                         (0U)
#define EMIF_PERFORMANCE_CTR_TIME_TOTAL_MASK                                          (0xffffffffU)

#define EMIF_DLL_CALIB_CTRL_ACK_WAIT_SHIFT                                            (16U)
#define EMIF_DLL_CALIB_CTRL_ACK_WAIT_MASK                                             (0x000f0000U)

#define EMIF_DLL_CALIB_CTRL_INTERVAL_SHIFT                                            (0U)
#define EMIF_DLL_CALIB_CTRL_INTERVAL_MASK                                             (0x000001ffU)

#define EMIF_DLL_CALIB_CTRL_SHDW_ACK_WAIT_SHDW_SHIFT                                (16U)
#define EMIF_DLL_CALIB_CTRL_SHDW_ACK_WAIT_SHDW_MASK                                 (0x000f0000U)

#define EMIF_DLL_CALIB_CTRL_SHDW_INTERVAL_SHDW_SHIFT                                (0U)
#define EMIF_DLL_CALIB_CTRL_SHDW_INTERVAL_SHDW_MASK                                 (0x000001ffU)

#define EMIF_END_OF_INTR_EOI_SHIFT                                                    (0U)
#define EMIF_END_OF_INTR_EOI_MASK                                                     (0x00000001U)

#define EMIF_SYSTEM_OCP_INTR_RAW_STS_DNV_SYS_SHIFT                                    (2U)
#define EMIF_SYSTEM_OCP_INTR_RAW_STS_DNV_SYS_MASK                                     (0x00000004U)

#define EMIF_SYSTEM_OCP_INTR_RAW_STS_TA_SYS_SHIFT                                     (1U)
#define EMIF_SYSTEM_OCP_INTR_RAW_STS_TA_SYS_MASK                                      (0x00000002U)

#define EMIF_SYSTEM_OCP_INTR_RAW_STS_ERR_SYS_SHIFT                                    (0U)
#define EMIF_SYSTEM_OCP_INTR_RAW_STS_ERR_SYS_MASK                                     (0x00000001U)

#define EMIF_LOW_LAT_OCP_INTR_RAW_STS_DNV_LL_SHIFT                                    (2U)
#define EMIF_LOW_LAT_OCP_INTR_RAW_STS_DNV_LL_MASK                                     (0x00000004U)

#define EMIF_LOW_LAT_OCP_INTR_RAW_STS_TA_LL_SHIFT                                     (1U)
#define EMIF_LOW_LAT_OCP_INTR_RAW_STS_TA_LL_MASK                                      (0x00000002U)

#define EMIF_LOW_LAT_OCP_INTR_RAW_STS_ERR_LL_SHIFT                                    (0U)
#define EMIF_LOW_LAT_OCP_INTR_RAW_STS_ERR_LL_MASK                                     (0x00000001U)

#define EMIF_SYSTEM_OCP_INTR_STS_DNV_SYS_SHIFT                                        (2U)
#define EMIF_SYSTEM_OCP_INTR_STS_DNV_SYS_MASK                                         (0x00000004U)

#define EMIF_SYSTEM_OCP_INTR_STS_TA_SYS_SHIFT                                         (1U)
#define EMIF_SYSTEM_OCP_INTR_STS_TA_SYS_MASK                                          (0x00000002U)

#define EMIF_SYSTEM_OCP_INTR_STS_ERR_SYS_SHIFT                                        (0U)
#define EMIF_SYSTEM_OCP_INTR_STS_ERR_SYS_MASK                                         (0x00000001U)

#define EMIF_LOW_LAT_OCP_INTR_STS_DNV_LL_SHIFT                                        (2U)
#define EMIF_LOW_LAT_OCP_INTR_STS_DNV_LL_MASK                                         (0x00000004U)

#define EMIF_LOW_LAT_OCP_INTR_STS_TA_LL_SHIFT                                         (1U)
#define EMIF_LOW_LAT_OCP_INTR_STS_TA_LL_MASK                                          (0x00000002U)

#define EMIF_LOW_LAT_OCP_INTR_STS_ERR_LL_SHIFT                                        (0U)
#define EMIF_LOW_LAT_OCP_INTR_STS_ERR_LL_MASK                                         (0x00000001U)

#define EMIF_SYSTEM_OCP_INTR_EN_SET_DNV_SYS_SHIFT                                     (2U)
#define EMIF_SYSTEM_OCP_INTR_EN_SET_DNV_SYS_MASK                                      (0x00000004U)

#define EMIF_SYSTEM_OCP_INTR_EN_SET_TA_SYS_SHIFT                                      (1U)
#define EMIF_SYSTEM_OCP_INTR_EN_SET_TA_SYS_MASK                                       (0x00000002U)

#define EMIF_SYSTEM_OCP_INTR_EN_SET_ERR_SYS_SHIFT                                     (0U)
#define EMIF_SYSTEM_OCP_INTR_EN_SET_ERR_SYS_MASK                                      (0x00000001U)

#define EMIF_LOW_LAT_OCP_INTR_EN_SET_DNV_LL_SHIFT                                     (2U)
#define EMIF_LOW_LAT_OCP_INTR_EN_SET_DNV_LL_MASK                                      (0x00000004U)

#define EMIF_LOW_LAT_OCP_INTR_EN_SET_TA_LL_SHIFT                                      (1U)
#define EMIF_LOW_LAT_OCP_INTR_EN_SET_TA_LL_MASK                                       (0x00000002U)

#define EMIF_LOW_LAT_OCP_INTR_EN_SET_ERR_LL_SHIFT                                     (0U)
#define EMIF_LOW_LAT_OCP_INTR_EN_SET_ERR_LL_MASK                                      (0x00000001U)

#define EMIF_SYSTEM_OCP_INTR_EN_CLR_DNV_SYS_SHIFT                                     (2U)
#define EMIF_SYSTEM_OCP_INTR_EN_CLR_DNV_SYS_MASK                                      (0x00000004U)

#define EMIF_SYSTEM_OCP_INTR_EN_CLR_TA_SYS_SHIFT                                      (1U)
#define EMIF_SYSTEM_OCP_INTR_EN_CLR_TA_SYS_MASK                                       (0x00000002U)

#define EMIF_SYSTEM_OCP_INTR_EN_CLR_ERR_SYS_SHIFT                                     (0U)
#define EMIF_SYSTEM_OCP_INTR_EN_CLR_ERR_SYS_MASK                                      (0x00000001U)

#define EMIF_LOW_LAT_OCP_INTR_EN_CLR_DNV_LL_SHIFT                                     (2U)
#define EMIF_LOW_LAT_OCP_INTR_EN_CLR_DNV_LL_MASK                                      (0x00000004U)

#define EMIF_LOW_LAT_OCP_INTR_EN_CLR_TA_LL_SHIFT                                      (1U)
#define EMIF_LOW_LAT_OCP_INTR_EN_CLR_TA_LL_MASK                                       (0x00000002U)

#define EMIF_LOW_LAT_OCP_INTR_EN_CLR_ERR_LL_SHIFT                                     (0U)
#define EMIF_LOW_LAT_OCP_INTR_EN_CLR_ERR_LL_MASK                                      (0x00000001U)

#define EMIF_ZQ_CONFIG_ZQ_CS1EN_SHIFT                 (31U)
#define EMIF_ZQ_CONFIG_ZQ_CS1EN_MASK                  (0x80000000U)

#define EMIF_ZQ_CONFIG_ZQ_CS0EN_SHIFT                 (30U)
#define EMIF_ZQ_CONFIG_ZQ_CS0EN_MASK                  (0x40000000U)

#define EMIF_ZQ_CONFIG_ZQ_DUALCALEN_SHIFT             (29U)
#define EMIF_ZQ_CONFIG_ZQ_DUALCALEN_MASK              (0x20000000U)

#define EMIF_ZQ_CONFIG_ZQ_SFEXITEN_SHIFT              (28U)
#define EMIF_ZQ_CONFIG_ZQ_SFEXITEN_MASK               (0x10000000U)

#define EMIF_ZQ_CONFIG_ZQ_ZQINIT_MULT_SHIFT           (18U)
#define EMIF_ZQ_CONFIG_ZQ_ZQINIT_MULT_MASK            (0x000c0000U)

#define EMIF_ZQ_CONFIG_ZQ_ZQCL_MULT_SHIFT             (16U)
#define EMIF_ZQ_CONFIG_ZQ_ZQCL_MULT_MASK              (0x00030000U)

#define EMIF_ZQ_CONFIG_ZQ_REFINTERVAL_SHIFT           (0U)
#define EMIF_ZQ_CONFIG_ZQ_REFINTERVAL_MASK            (0x0000ffffU)

#define EMIF_TEMP_ALERT_CONFIG_TA_CS1EN_SHIFT                                  (31U)
#define EMIF_TEMP_ALERT_CONFIG_TA_CS1EN_MASK                                   (0x80000000U)

#define EMIF_TEMP_ALERT_CONFIG_TA_CS0EN_SHIFT                                  (30U)
#define EMIF_TEMP_ALERT_CONFIG_TA_CS0EN_MASK                                   (0x40000000U)

#define EMIF_TEMP_ALERT_CONFIG_TA_SFEXITEN_SHIFT                               (28U)
#define EMIF_TEMP_ALERT_CONFIG_TA_SFEXITEN_MASK                                (0x10000000U)

#define EMIF_TEMP_ALERT_CONFIG_TA_DEVWDT_SHIFT                                 (26U)
#define EMIF_TEMP_ALERT_CONFIG_TA_DEVWDT_MASK                                  (0x0c000000U)

#define EMIF_TEMP_ALERT_CONFIG_TA_DEVCNT_SHIFT                                 (24U)
#define EMIF_TEMP_ALERT_CONFIG_TA_DEVCNT_MASK                                  (0x03000000U)

#define EMIF_TEMP_ALERT_CONFIG_TA_REFINTERVAL_SHIFT                            (0U)
#define EMIF_TEMP_ALERT_CONFIG_TA_REFINTERVAL_MASK                             (0x003fffffU)

#define EMIF_OCP_ERROR_LOG_MADDRSPACE_SHIFT                                           (14U)
#define EMIF_OCP_ERROR_LOG_MADDRSPACE_MASK                                            (0x0000c000U)

#define EMIF_OCP_ERROR_LOG_MBURSTSEQ_SHIFT                                            (11U)
#define EMIF_OCP_ERROR_LOG_MBURSTSEQ_MASK                                             (0x00003800U)

#define EMIF_OCP_ERROR_LOG_MCMD_SHIFT                                                 (8U)
#define EMIF_OCP_ERROR_LOG_MCMD_MASK                                                  (0x00000700U)

#define EMIF_OCP_ERROR_LOG_MCONNID_SHIFT                                              (0U)
#define EMIF_OCP_ERROR_LOG_MCONNID_MASK                                               (0x000000ffU)

#define EMIF_RDWR_LVL_RMP_WIN_RDWRLVLINC_RMP_WIN_SHIFT                 (0U)
#define EMIF_RDWR_LVL_RMP_WIN_RDWRLVLINC_RMP_WIN_MASK                  (0x00001fffU)

#define EMIF_RDWR_LVL_RMP_CTRL_RDWRLVL_EN_SHIFT                           (31U)
#define EMIF_RDWR_LVL_RMP_CTRL_RDWRLVL_EN_MASK                            (0x80000000U)

#define EMIF_RDWR_LVL_RMP_CTRL_RDWRLVLINC_RMP_PRE_SHIFT                   (24U)
#define EMIF_RDWR_LVL_RMP_CTRL_RDWRLVLINC_RMP_PRE_MASK                    (0x7f000000U)

#define EMIF_RDWR_LVL_RMP_CTRL_RDLVLINC_RMP_INT_SHIFT                     (16U)
#define EMIF_RDWR_LVL_RMP_CTRL_RDLVLINC_RMP_INT_MASK                      (0x00ff0000U)

#define EMIF_RDWR_LVL_RMP_CTRL_RDLVLGATEINC_RMP_INT_SHIFT                 (8U)
#define EMIF_RDWR_LVL_RMP_CTRL_RDLVLGATEINC_RMP_INT_MASK                  (0x0000ff00U)

#define EMIF_RDWR_LVL_RMP_CTRL_WRLVLINC_RMP_INT_SHIFT                     (0U)
#define EMIF_RDWR_LVL_RMP_CTRL_WRLVLINC_RMP_INT_MASK                      (0x000000ffU)

#define EMIF_RDWR_LVL_CTRL_RDWRLVLFULL_START_SHIFT                         (31U)
#define EMIF_RDWR_LVL_CTRL_RDWRLVLFULL_START_MASK                          (0x80000000U)

#define EMIF_RDWR_LVL_CTRL_RDWRLVLINC_PRE_SHIFT                            (24U)
#define EMIF_RDWR_LVL_CTRL_RDWRLVLINC_PRE_MASK                             (0x7f000000U)

#define EMIF_RDWR_LVL_CTRL_RDLVLINC_INT_SHIFT                              (16U)
#define EMIF_RDWR_LVL_CTRL_RDLVLINC_INT_MASK                               (0x00ff0000U)

#define EMIF_RDWR_LVL_CTRL_RDLVLGATEINC_INT_SHIFT                          (8U)
#define EMIF_RDWR_LVL_CTRL_RDLVLGATEINC_INT_MASK                           (0x0000ff00U)

#define EMIF_RDWR_LVL_CTRL_WRLVLINC_INT_SHIFT                              (0U)
#define EMIF_RDWR_LVL_CTRL_WRLVLINC_INT_MASK                               (0x000000ffU)

#define EMIF_DDR_PHY_CTRL_1_RDLVL_MASK_SHIFT                                          (27U)
#define EMIF_DDR_PHY_CTRL_1_RDLVL_MASK_MASK                                           (0x08000000U)

#define EMIF_DDR_PHY_CTRL_1_RDLVLGATE_MASK_SHIFT                                      (26U)
#define EMIF_DDR_PHY_CTRL_1_RDLVLGATE_MASK_MASK                                       (0x04000000U)

#define EMIF_DDR_PHY_CTRL_1_WRLVL_MASK_SHIFT                                          (25U)
#define EMIF_DDR_PHY_CTRL_1_WRLVL_MASK_MASK                                           (0x02000000U)

#define EMIF_DDR_PHY_CTRL_1_HALF_DELAYS_SHIFT                                         (21U)
#define EMIF_DDR_PHY_CTRL_1_HALF_DELAYS_MASK                                          (0x00200000U)

#define EMIF_DDR_PHY_CTRL_1_CLK_STALL_LEVEL_SHIFT                                     (20U)
#define EMIF_DDR_PHY_CTRL_1_CLK_STALL_LEVEL_MASK                                      (0x00100000U)

#define EMIF_DDR_PHY_CTRL_1_DIS_CALIB_RST_SHIFT                                       (19U)
#define EMIF_DDR_PHY_CTRL_1_DIS_CALIB_RST_MASK                                        (0x00080000U)

#define EMIF_DDR_PHY_CTRL_1_INVERT_CLKOUT_SHIFT                                       (18U)
#define EMIF_DDR_PHY_CTRL_1_INVERT_CLKOUT_MASK                                        (0x00040000U)

#define EMIF_DDR_PHY_CTRL_1_DLL_LOCK_DIFF_SHIFT                                       (10U)
#define EMIF_DDR_PHY_CTRL_1_DLL_LOCK_DIFF_MASK                                        (0x0003fc00U)

#define EMIF_DDR_PHY_CTRL_1_FAST_DLL_LOCK_SHIFT                                       (9U)
#define EMIF_DDR_PHY_CTRL_1_FAST_DLL_LOCK_MASK                                        (0x00000200U)

#define EMIF_DDR_PHY_CTRL_1_READ_LAT_SHIFT                                            (0U)
#define EMIF_DDR_PHY_CTRL_1_READ_LAT_MASK                                             (0x0000001fU)

#define EMIF_DDR_PHY_CTRL_1_SHDW_RDLVL_MASK_SHDW_SHIFT                              (27U)
#define EMIF_DDR_PHY_CTRL_1_SHDW_RDLVL_MASK_SHDW_MASK                               (0x08000000U)

#define EMIF_DDR_PHY_CTRL_1_SHDW_RDLVLGATE_MASK_SHDW_SHIFT                          (26U)
#define EMIF_DDR_PHY_CTRL_1_SHDW_RDLVLGATE_MASK_SHDW_MASK                           (0x04000000U)

#define EMIF_DDR_PHY_CTRL_1_SHDW_WRLVL_MASK_SHDW_SHIFT                              (25U)
#define EMIF_DDR_PHY_CTRL_1_SHDW_WRLVL_MASK_SHDW_MASK                               (0x02000000U)

#define EMIF_DDR_PHY_CTRL_1_SHDW_HALF_DELAYS_SHDW_SHIFT                             (21U)
#define EMIF_DDR_PHY_CTRL_1_SHDW_HALF_DELAYS_SHDW_MASK                              (0x00200000U)

#define EMIF_DDR_PHY_CTRL_1_SHDW_CLK_STALL_LEVEL_SHDW_SHIFT                         (20U)
#define EMIF_DDR_PHY_CTRL_1_SHDW_CLK_STALL_LEVEL_SHDW_MASK                          (0x00100000U)

#define EMIF_DDR_PHY_CTRL_1_SHDW_DIS_CALIB_RST_SHDW_SHIFT                           (19U)
#define EMIF_DDR_PHY_CTRL_1_SHDW_DIS_CALIB_RST_SHDW_MASK                            (0x00080000U)

#define EMIF_DDR_PHY_CTRL_1_SHDW_INVERT_CLKOUT_SHDW_SHIFT                           (18U)
#define EMIF_DDR_PHY_CTRL_1_SHDW_INVERT_CLKOUT_SHDW_MASK                            (0x00040000U)

#define EMIF_DDR_PHY_CTRL_1_SHDW_DLL_LOCK_DIFF_SHDW_SHIFT                           (10U)
#define EMIF_DDR_PHY_CTRL_1_SHDW_DLL_LOCK_DIFF_SHDW_MASK                            (0x0003fc00U)

#define EMIF_DDR_PHY_CTRL_1_SHDW_FAST_DLL_LOCK_SHDW_SHIFT                           (9U)
#define EMIF_DDR_PHY_CTRL_1_SHDW_FAST_DLL_LOCK_SHDW_MASK                            (0x00000200U)

#define EMIF_DDR_PHY_CTRL_1_SHDW_READ_LAT_SHDW_SHIFT                                (0U)
#define EMIF_DDR_PHY_CTRL_1_SHDW_READ_LAT_SHDW_MASK                                 (0x0000001fU)

#define EMIF_PRI_COS_MAP_PRI_COS_MAP_EN_SHIFT                (31U)
#define EMIF_PRI_COS_MAP_PRI_COS_MAP_EN_MASK                 (0x80000000U)

#define EMIF_PRI_COS_MAP_PRI_7_COS_SHIFT                     (14U)
#define EMIF_PRI_COS_MAP_PRI_7_COS_MASK                      (0x0000c000U)

#define EMIF_PRI_COS_MAP_PRI_6_COS_SHIFT                     (12U)
#define EMIF_PRI_COS_MAP_PRI_6_COS_MASK                      (0x00003000U)

#define EMIF_PRI_COS_MAP_PRI_5_COS_SHIFT                     (10U)
#define EMIF_PRI_COS_MAP_PRI_5_COS_MASK                      (0x00000c00U)

#define EMIF_PRI_COS_MAP_PRI_4_COS_SHIFT                     (8U)
#define EMIF_PRI_COS_MAP_PRI_4_COS_MASK                      (0x00000300U)

#define EMIF_PRI_COS_MAP_PRI_3_COS_SHIFT                     (6U)
#define EMIF_PRI_COS_MAP_PRI_3_COS_MASK                      (0x000000c0U)

#define EMIF_PRI_COS_MAP_PRI_2_COS_SHIFT                     (4U)
#define EMIF_PRI_COS_MAP_PRI_2_COS_MASK                      (0x00000030U)

#define EMIF_PRI_COS_MAP_PRI_1_COS_SHIFT                     (2U)
#define EMIF_PRI_COS_MAP_PRI_1_COS_MASK                      (0x0000000cU)

#define EMIF_PRI_COS_MAP_PRI_0_COS_SHIFT                     (0U)
#define EMIF_PRI_COS_MAP_PRI_0_COS_MASK                      (0x00000003U)

#define EMIF_CONNID_COS_1_MAP_CONNID_COS_MAP_EN_SHIFT      (31U)
#define EMIF_CONNID_COS_1_MAP_CONNID_COS_MAP_EN_MASK       (0x80000000U)

#define EMIF_CONNID_COS_1_MAP_CONNID_COS_SHIFT             (23U)
#define EMIF_CONNID_COS_1_MAP_CONNID_COS_MASK              (0x7f800000U)

#define EMIF_CONNID_COS_1_MAP_MSK_COS_SHIFT                (20U)
#define EMIF_CONNID_COS_1_MAP_MSK_COS_MASK                 (0x00700000U)

#define EMIF_CONNID_COS_1_MAP_CONNID_2_COS_SHIFT           (12U)
#define EMIF_CONNID_COS_1_MAP_CONNID_2_COS_MASK            (0x000ff000U)

#define EMIF_CONNID_COS_1_MAP_MSK_2_COS_SHIFT              (10U)
#define EMIF_CONNID_COS_1_MAP_MSK_2_COS_MASK               (0x00000c00U)

#define EMIF_CONNID_COS_1_MAP_CONNID_3_COS_SHIFT           (2U)
#define EMIF_CONNID_COS_1_MAP_CONNID_3_COS_MASK            (0x000003fcU)

#define EMIF_CONNID_COS_1_MAP_MSK_3_COS_SHIFT              (0U)
#define EMIF_CONNID_COS_1_MAP_MSK_3_COS_MASK               (0x00000003U)

#define EMIF_CONNID_COS_2_MAP_CONNID_COS_MAP_EN_SHIFT      (31U)
#define EMIF_CONNID_COS_2_MAP_CONNID_COS_MAP_EN_MASK       (0x80000000U)

#define EMIF_CONNID_COS_2_MAP_CONNID_1_COS_SHIFT           (23U)
#define EMIF_CONNID_COS_2_MAP_CONNID_1_COS_MASK            (0x7f800000U)

#define EMIF_CONNID_COS_2_MAP_MSK_1_COS_SHIFT              (20U)
#define EMIF_CONNID_COS_2_MAP_MSK_1_COS_MASK               (0x00700000U)

#define EMIF_CONNID_COS_2_MAP_CONNID_COS_SHIFT             (12U)
#define EMIF_CONNID_COS_2_MAP_CONNID_COS_MASK              (0x000ff000U)

#define EMIF_CONNID_COS_2_MAP_MSK_COS_SHIFT                (10U)
#define EMIF_CONNID_COS_2_MAP_MSK_COS_MASK                 (0x00000c00U)

#define EMIF_CONNID_COS_2_MAP_CONNID_3_COS_SHIFT           (2U)
#define EMIF_CONNID_COS_2_MAP_CONNID_3_COS_MASK            (0x000003fcU)

#define EMIF_CONNID_COS_2_MAP_MSK_3_COS_SHIFT              (0U)
#define EMIF_CONNID_COS_2_MAP_MSK_3_COS_MASK               (0x00000003U)

#define EMIF_ECC_CTRL_REG_EN_SHIFT                                                    (31U)
#define EMIF_ECC_CTRL_REG_EN_MASK                                                     (0x80000000U)

#define EMIF_ECC_CTRL_REG_ADDR_RGN_PROT_SHIFT                                         (30U)
#define EMIF_ECC_CTRL_REG_ADDR_RGN_PROT_MASK                                          (0x40000000U)

#define EMIF_ECC_CTRL_REG_ADDR_RGN_2_EN_SHIFT                                         (1U)
#define EMIF_ECC_CTRL_REG_ADDR_RGN_2_EN_MASK                                          (0x00000002U)

#define EMIF_ECC_CTRL_REG_ADDR_RGN_1_EN_SHIFT                                         (0U)
#define EMIF_ECC_CTRL_REG_ADDR_RGN_1_EN_MASK                                          (0x00000001U)

#define EMIF_ECC_ADDR_RANGE_1_REG_END_SHIFT                                           (16U)
#define EMIF_ECC_ADDR_RANGE_1_REG_END_MASK                                            (0xffff0000U)

#define EMIF_ECC_ADDR_RANGE_1_REG_STRT_SHIFT                                          (0U)
#define EMIF_ECC_ADDR_RANGE_1_REG_STRT_MASK                                           (0x0000ffffU)

#define EMIF_ECC_ADDR_RANGE_2_REG_END_SHIFT                                           (16U)
#define EMIF_ECC_ADDR_RANGE_2_REG_END_MASK                                            (0xffff0000U)

#define EMIF_ECC_ADDR_RANGE_2_REG_STRT_SHIFT                                          (0U)
#define EMIF_ECC_ADDR_RANGE_2_REG_STRT_MASK                                           (0x0000ffffU)

#define EMIF_RD_WR_EXEC_THR_MFLAG_OVERRIDE_SHIFT                            (31U)
#define EMIF_RD_WR_EXEC_THR_MFLAG_OVERRIDE_MASK                             (0x80000000U)

#define EMIF_RD_WR_EXEC_THR_EN_LLBUBBLE_SHIFT                               (30U)
#define EMIF_RD_WR_EXEC_THR_EN_LLBUBBLE_MASK                                (0x40000000U)

#define EMIF_RD_WR_EXEC_THR_WR_THRSH_SHIFT                                  (8U)
#define EMIF_RD_WR_EXEC_THR_WR_THRSH_MASK                                   (0x00001f00U)

#define EMIF_RD_WR_EXEC_THR_RD_THRSH_SHIFT                                  (0U)
#define EMIF_RD_WR_EXEC_THR_RD_THRSH_MASK                                   (0x0000001fU)

#define EMIF_COS_CONFIG_COUNT_1_SHIFT                                                 (16U)
#define EMIF_COS_CONFIG_COUNT_1_MASK                                                  (0x00ff0000U)

#define EMIF_COS_CONFIG_COUNT_2_SHIFT                                                 (8U)
#define EMIF_COS_CONFIG_COUNT_2_MASK                                                  (0x0000ff00U)

#define EMIF_COS_CONFIG_PR_OLD_COUNT_SHIFT                                            (0U)
#define EMIF_COS_CONFIG_PR_OLD_COUNT_MASK                                             (0x000000ffU)

#define EMIF_1B_ECC_ERR_CNT_REG_SHIFT                                                 (0U)
#define EMIF_1B_ECC_ERR_CNT_REG_MASK                                                  (0xffffffffU)

#define EMIF_1B_ECC_ERR_THRSH_REG_SHIFT                                               (24U)
#define EMIF_1B_ECC_ERR_THRSH_REG_MASK                                                (0xff000000U)

#define EMIF_1B_ECC_ERR_THRSH_REG_WIN_SHIFT                                           (0U)
#define EMIF_1B_ECC_ERR_THRSH_REG_WIN_MASK                                            (0x0000ffffU)

#define EMIF_1B_ECC_ERR_DIST_1_REG_SHIFT                                              (0U)
#define EMIF_1B_ECC_ERR_DIST_1_REG_MASK                                               (0xffffffffU)

#define EMIF_1B_ECC_ERR_ADDR_LOG_REG_SHIFT                                            (0U)
#define EMIF_1B_ECC_ERR_ADDR_LOG_REG_MASK                                             (0xffffffffU)

#define EMIF_2B_ECC_ERR_ADDR_LOG_REG_SHIFT                                            (0U)
#define EMIF_2B_ECC_ERR_ADDR_LOG_REG_MASK                                             (0xffffffffU)

#define EMIF_PHY_STS_1_REG_CTRL_DLL_SLAVE_VALUE_SHIFT                                 (12U)
#define EMIF_PHY_STS_1_REG_CTRL_DLL_SLAVE_VALUE_MASK                                  (0x3ffff000U)

#define EMIF_PHY_STS_1_REG_DLL_LOCK_SHIFT                                             (4U)
#define EMIF_PHY_STS_1_REG_DLL_LOCK_MASK                                              (0x000001f0U)

#define EMIF_PHY_STS_1_REG_CTRL_DLL_LOCK_SHIFT                                        (0U)
#define EMIF_PHY_STS_1_REG_CTRL_DLL_LOCK_MASK                                         (0x00000003U)

#define EMIF_PHY_STS_2_REG_DLL_SLAVE_VALUE_LO_SHIFT                                   (0U)
#define EMIF_PHY_STS_2_REG_DLL_SLAVE_VALUE_LO_MASK                                    (0xffffffffU)

#define EMIF_PHY_STS_3_REG_RDFIFO_RDPTR_SHIFT                                         (16U)
#define EMIF_PHY_STS_3_REG_RDFIFO_RDPTR_MASK                                          (0x7fff0000U)

#define EMIF_PHY_STS_3_REG_DLL_SLAVE_VALUE_HI_SHIFT                                   (0U)
#define EMIF_PHY_STS_3_REG_DLL_SLAVE_VALUE_HI_MASK                                    (0x00001fffU)

#define EMIF_PHY_STS_4_REG_GATELVL_FSM_SHIFT                                          (16U)
#define EMIF_PHY_STS_4_REG_GATELVL_FSM_MASK                                           (0x7fff0000U)

#define EMIF_PHY_STS_4_REG_RDFIFO_WRPTR_SHIFT                                         (0U)
#define EMIF_PHY_STS_4_REG_RDFIFO_WRPTR_MASK                                          (0x00007fffU)

#define EMIF_PHY_STS_5_REG_RD_LEVEL_FSM_SHIFT                                         (0U)
#define EMIF_PHY_STS_5_REG_RD_LEVEL_FSM_MASK                                          (0x000fffffU)

#define EMIF_PHY_STS_6_REG_WR_LEVEL_FSM_SHIFT                                         (0U)
#define EMIF_PHY_STS_6_REG_WR_LEVEL_FSM_MASK                                          (0x00007fffU)

#define EMIF_PHY_STS_7_REG_RDLVL_DQS_RATIO1_SHIFT                                     (16U)
#define EMIF_PHY_STS_7_REG_RDLVL_DQS_RATIO1_MASK                                      (0x03ff0000U)

#define EMIF_PHY_STS_7_REG_RDLVL_DQS_RATIO0_SHIFT                                     (0U)
#define EMIF_PHY_STS_7_REG_RDLVL_DQS_RATIO0_MASK                                      (0x000003ffU)

#define EMIF_PHY_STS_8_REG_RDLVL_DQS_RATIO3_SHIFT                                     (16U)
#define EMIF_PHY_STS_8_REG_RDLVL_DQS_RATIO3_MASK                                      (0x03ff0000U)

#define EMIF_PHY_STS_8_REG_RDLVL_DQS_RATIO2_SHIFT                                     (0U)
#define EMIF_PHY_STS_8_REG_RDLVL_DQS_RATIO2_MASK                                      (0x000003ffU)

#define EMIF_PHY_STS_9_REG_RDLVL_DQS_RATIO5_SHIFT                                     (16U)
#define EMIF_PHY_STS_9_REG_RDLVL_DQS_RATIO5_MASK                                      (0x03ff0000U)

#define EMIF_PHY_STS_9_REG_RDLVL_DQS_RATIO4_SHIFT                                     (0U)
#define EMIF_PHY_STS_9_REG_RDLVL_DQS_RATIO4_MASK                                      (0x000003ffU)

#define EMIF_PHY_STS_10_REG_RDLVL_DQS_RATIO7_SHIFT                                    (16U)
#define EMIF_PHY_STS_10_REG_RDLVL_DQS_RATIO7_MASK                                     (0x03ff0000U)

#define EMIF_PHY_STS_10_REG_RDLVL_DQS_RATIO6_SHIFT                                    (0U)
#define EMIF_PHY_STS_10_REG_RDLVL_DQS_RATIO6_MASK                                     (0x000003ffU)

#define EMIF_PHY_STS_11_REG_RDLVL_DQS_RATIO9_SHIFT                                    (16U)
#define EMIF_PHY_STS_11_REG_RDLVL_DQS_RATIO9_MASK                                     (0x03ff0000U)

#define EMIF_PHY_STS_11_REG_RDLVL_DQS_RATIO8_SHIFT                                    (0U)
#define EMIF_PHY_STS_11_REG_RDLVL_DQS_RATIO8_MASK                                     (0x000003ffU)

#define EMIF_PHY_STS_12_REG_RDLVL_FIFOWEIN_RATIO1_SHIFT                               (16U)
#define EMIF_PHY_STS_12_REG_RDLVL_FIFOWEIN_RATIO1_MASK                                (0x07ff0000U)

#define EMIF_PHY_STS_12_REG_RDLVL_FIFOWEIN_RATIO0_SHIFT                               (0U)
#define EMIF_PHY_STS_12_REG_RDLVL_FIFOWEIN_RATIO0_MASK                                (0x000007ffU)

#define EMIF_PHY_STS_13_REG_RDLVL_FIFOWEIN_RATIO3_SHIFT                               (16U)
#define EMIF_PHY_STS_13_REG_RDLVL_FIFOWEIN_RATIO3_MASK                                (0x07ff0000U)

#define EMIF_PHY_STS_13_REG_RDLVL_FIFOWEIN_RATIO2_SHIFT                               (0U)
#define EMIF_PHY_STS_13_REG_RDLVL_FIFOWEIN_RATIO2_MASK                                (0x000007ffU)

#define EMIF_PHY_STS_14_REG_RDLVL_FIFOWEIN_RATIO5_SHIFT                               (16U)
#define EMIF_PHY_STS_14_REG_RDLVL_FIFOWEIN_RATIO5_MASK                                (0x07ff0000U)

#define EMIF_PHY_STS_14_REG_RDLVL_FIFOWEIN_RATIO4_SHIFT                               (0U)
#define EMIF_PHY_STS_14_REG_RDLVL_FIFOWEIN_RATIO4_MASK                                (0x000007ffU)

#define EMIF_PHY_STS_15_REG_RDLVL_FIFOWEIN_RATIO7_SHIFT                               (16U)
#define EMIF_PHY_STS_15_REG_RDLVL_FIFOWEIN_RATIO7_MASK                                (0x07ff0000U)

#define EMIF_PHY_STS_15_REG_RDLVL_FIFOWEIN_RATIO6_SHIFT                               (0U)
#define EMIF_PHY_STS_15_REG_RDLVL_FIFOWEIN_RATIO6_MASK                                (0x000007ffU)

#define EMIF_PHY_STS_16_REG_RDLVL_FIFOWEIN_RATIO9_SHIFT                               (16U)
#define EMIF_PHY_STS_16_REG_RDLVL_FIFOWEIN_RATIO9_MASK                                (0x07ff0000U)

#define EMIF_PHY_STS_16_REG_RDLVL_FIFOWEIN_RATIO8_SHIFT                               (0U)
#define EMIF_PHY_STS_16_REG_RDLVL_FIFOWEIN_RATIO8_MASK                                (0x000007ffU)

#define EMIF_PHY_STS_17_REG_WRLVL_DQ_RATIO1_SHIFT                                     (16U)
#define EMIF_PHY_STS_17_REG_WRLVL_DQ_RATIO1_MASK                                      (0x03ff0000U)

#define EMIF_PHY_STS_17_REG_WRLVL_DQ_RATIO0_SHIFT                                     (0U)
#define EMIF_PHY_STS_17_REG_WRLVL_DQ_RATIO0_MASK                                      (0x000003ffU)

#define EMIF_PHY_STS_18_REG_WRLVL_DQ_RATIO3_SHIFT                                     (16U)
#define EMIF_PHY_STS_18_REG_WRLVL_DQ_RATIO3_MASK                                      (0x03ff0000U)

#define EMIF_PHY_STS_18_REG_WRLVL_DQ_RATIO2_SHIFT                                     (0U)
#define EMIF_PHY_STS_18_REG_WRLVL_DQ_RATIO2_MASK                                      (0x000003ffU)

#define EMIF_PHY_STS_19_REG_WRLVL_DQ_RATIO5_SHIFT                                     (16U)
#define EMIF_PHY_STS_19_REG_WRLVL_DQ_RATIO5_MASK                                      (0x03ff0000U)

#define EMIF_PHY_STS_19_REG_WRLVL_DQ_RATIO4_SHIFT                                     (0U)
#define EMIF_PHY_STS_19_REG_WRLVL_DQ_RATIO4_MASK                                      (0x000003ffU)

#define EMIF_PHY_STS_20_REG_WRLVL_DQ_RATIO7_SHIFT                                     (16U)
#define EMIF_PHY_STS_20_REG_WRLVL_DQ_RATIO7_MASK                                      (0x03ff0000U)

#define EMIF_PHY_STS_20_REG_WRLVL_DQ_RATIO6_SHIFT                                     (0U)
#define EMIF_PHY_STS_20_REG_WRLVL_DQ_RATIO6_MASK                                      (0x000003ffU)

#define EMIF_PHY_STS_21_REG_WRLVL_DQ_RATIO9_SHIFT                                     (16U)
#define EMIF_PHY_STS_21_REG_WRLVL_DQ_RATIO9_MASK                                      (0x03ff0000U)

#define EMIF_PHY_STS_21_REG_WRLVL_DQ_RATIO8_SHIFT                                     (0U)
#define EMIF_PHY_STS_21_REG_WRLVL_DQ_RATIO8_MASK                                      (0x000003ffU)

#define EMIF_PHY_STS_22_REG_WRLVL_DQS_RATIO1_SHIFT                                    (16U)
#define EMIF_PHY_STS_22_REG_WRLVL_DQS_RATIO1_MASK                                     (0x03ff0000U)

#define EMIF_PHY_STS_22_REG_WRLVL_DQS_RATIO0_SHIFT                                    (0U)
#define EMIF_PHY_STS_22_REG_WRLVL_DQS_RATIO0_MASK                                     (0x000003ffU)

#define EMIF_PHY_STS_23_REG_WRLVL_DQS_RATIO3_SHIFT                                    (16U)
#define EMIF_PHY_STS_23_REG_WRLVL_DQS_RATIO3_MASK                                     (0x03ff0000U)

#define EMIF_PHY_STS_23_REG_WRLVL_DQS_RATIO2_SHIFT                                    (0U)
#define EMIF_PHY_STS_23_REG_WRLVL_DQS_RATIO2_MASK                                     (0x000003ffU)

#define EMIF_PHY_STS_24_REG_WRLVL_DQS_RATIO5_SHIFT                                    (16U)
#define EMIF_PHY_STS_24_REG_WRLVL_DQS_RATIO5_MASK                                     (0x03ff0000U)

#define EMIF_PHY_STS_24_REG_WRLVL_DQS_RATIO4_SHIFT                                    (0U)
#define EMIF_PHY_STS_24_REG_WRLVL_DQS_RATIO4_MASK                                     (0x000003ffU)

#define EMIF_PHY_STS_25_REG_WRLVL_DQS_RATIO7_SHIFT                                    (16U)
#define EMIF_PHY_STS_25_REG_WRLVL_DQS_RATIO7_MASK                                     (0x03ff0000U)

#define EMIF_PHY_STS_25_REG_WRLVL_DQS_RATIO6_SHIFT                                    (0U)
#define EMIF_PHY_STS_25_REG_WRLVL_DQS_RATIO6_MASK                                     (0x000003ffU)

#define EMIF_PHY_STS_26_REG_WRLVL_DQS_RATIO9_SHIFT                                    (16U)
#define EMIF_PHY_STS_26_REG_WRLVL_DQS_RATIO9_MASK                                     (0x03ff0000U)

#define EMIF_PHY_STS_26_REG_WRLVL_DQS_RATIO8_SHIFT                                    (0U)
#define EMIF_PHY_STS_26_REG_WRLVL_DQS_RATIO8_MASK                                     (0x000003ffU)

#define EMIF_PHY_STS_27_REG_CTRL_MDLL_UNLOCK_STICKY_SHIFT                             (28U)
#define EMIF_PHY_STS_27_REG_CTRL_MDLL_UNLOCK_STICKY_MASK                              (0x30000000U)

#define EMIF_PHY_STS_27_REG_MDLL_UNLOCK_STICKY_SHIFT                                  (20U)
#define EMIF_PHY_STS_27_REG_MDLL_UNLOCK_STICKY_MASK                                   (0x01f00000U)

#define EMIF_PHY_STS_27_REG_RDC_FIFO_RST_ERR_CNT_SHIFT                                (0U)
#define EMIF_PHY_STS_27_REG_RDC_FIFO_RST_ERR_CNT_MASK                                 (0x000fffffU)

#define EMIF_PHY_STS_28_REG_GATELVL_INC_FAIL_SHIFT                                    (24U)
#define EMIF_PHY_STS_28_REG_GATELVL_INC_FAIL_MASK                                     (0x1f000000U)

#define EMIF_PHY_STS_28_REG_WRLVL_INC_FAIL_SHIFT                                      (16U)
#define EMIF_PHY_STS_28_REG_WRLVL_INC_FAIL_MASK                                       (0x001f0000U)

#define EMIF_PHY_STS_28_REG_RDLVL_INC_FAIL_SHIFT                                      (8U)
#define EMIF_PHY_STS_28_REG_RDLVL_INC_FAIL_MASK                                       (0x00001f00U)

#define EMIF_PHY_STS_28_REG_FIFO_WE_IN_MIASALIGNED_STICKY_SHIFT                       (0U)
#define EMIF_PHY_STS_28_REG_FIFO_WE_IN_MIASALIGNED_STICKY_MASK                        (0x0000001fU)

#define EMIF_EXT_PHY_CTRL_1_REG_SLAVE_RATIO_SHIFT                                     (0U)
#define EMIF_EXT_PHY_CTRL_1_REG_SLAVE_RATIO_MASK                                      (0x3fffffffU)

#define EMIF_EXT_PHY_CTRL_1_SHDW_REG_SLAVE_RATIO_SHIFT                              (0U)
#define EMIF_EXT_PHY_CTRL_1_SHDW_REG_SLAVE_RATIO_MASK                               (0x3fffffffU)

#define EMIF_EXT_PHY_CTRL_2_REG_FIFO_WE_SLAVE_RATIO1_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_2_REG_FIFO_WE_SLAVE_RATIO1_MASK                             (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_2_REG_FIFO_WE_SLAVE_RATIO0_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_2_REG_FIFO_WE_SLAVE_RATIO0_MASK                             (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_2_SHDW_REG_FIFO_WE_SLAVE_RATIO1_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_2_SHDW_REG_FIFO_WE_SLAVE_RATIO1_MASK                      (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_2_SHDW_REG_FIFO_WE_SLAVE_RATIO0_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_2_SHDW_REG_FIFO_WE_SLAVE_RATIO0_MASK                      (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_3_REG_FIFO_WE_SLAVE_RATIO3_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_3_REG_FIFO_WE_SLAVE_RATIO3_MASK                             (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_3_REG_FIFO_WE_SLAVE_RATIO2_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_3_REG_FIFO_WE_SLAVE_RATIO2_MASK                             (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_3_SHDW_REG_FIFO_WE_SLAVE_RATIO3_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_3_SHDW_REG_FIFO_WE_SLAVE_RATIO3_MASK                      (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_3_SHDW_REG_FIFO_WE_SLAVE_RATIO2_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_3_SHDW_REG_FIFO_WE_SLAVE_RATIO2_MASK                      (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_4_REG_FIFO_WE_SLAVE_RATIO5_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_4_REG_FIFO_WE_SLAVE_RATIO5_MASK                             (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_4_REG_FIFO_WE_SLAVE_RATIO4_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_4_REG_FIFO_WE_SLAVE_RATIO4_MASK                             (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_4_SHDW_REG_FIFO_WE_SLAVE_RATIO5_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_4_SHDW_REG_FIFO_WE_SLAVE_RATIO5_MASK                      (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_4_SHDW_REG_FIFO_WE_SLAVE_RATIO4_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_4_SHDW_REG_FIFO_WE_SLAVE_RATIO4_MASK                      (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_5_REG_FIFO_WE_SLAVE_RATIO7_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_5_REG_FIFO_WE_SLAVE_RATIO7_MASK                             (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_5_REG_FIFO_WE_SLAVE_RATIO6_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_5_REG_FIFO_WE_SLAVE_RATIO6_MASK                             (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_5_SHDW_REG_FIFO_WE_SLAVE_RATIO7_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_5_SHDW_REG_FIFO_WE_SLAVE_RATIO7_MASK                      (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_5_SHDW_REG_FIFO_WE_SLAVE_RATIO6_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_5_SHDW_REG_FIFO_WE_SLAVE_RATIO6_MASK                      (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_6_REG_FIFO_WE_SLAVE_RATIO9_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_6_REG_FIFO_WE_SLAVE_RATIO9_MASK                             (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_6_REG_FIFO_WE_SLAVE_RATIO8_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_6_REG_FIFO_WE_SLAVE_RATIO8_MASK                             (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_6_SHDW_REG_FIFO_WE_SLAVE_RATIO9_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_6_SHDW_REG_FIFO_WE_SLAVE_RATIO9_MASK                      (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_6_SHDW_REG_FIFO_WE_SLAVE_RATIO8_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_6_SHDW_REG_FIFO_WE_SLAVE_RATIO8_MASK                      (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_7_REG_RD_DQS_SLAVE_RATIO1_SHIFT                             (16U)
#define EMIF_EXT_PHY_CTRL_7_REG_RD_DQS_SLAVE_RATIO1_MASK                              (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_7_REG_RD_DQS_SLAVE_RATIO0_SHIFT                             (0U)
#define EMIF_EXT_PHY_CTRL_7_REG_RD_DQS_SLAVE_RATIO0_MASK                              (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_7_SHDW_REG_RD_DQS_SLAVE_RATIO1_SHIFT                      (16U)
#define EMIF_EXT_PHY_CTRL_7_SHDW_REG_RD_DQS_SLAVE_RATIO1_MASK                       (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_7_SHDW_REG_RD_DQS_SLAVE_RATIO0_SHIFT                      (0U)
#define EMIF_EXT_PHY_CTRL_7_SHDW_REG_RD_DQS_SLAVE_RATIO0_MASK                       (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_8_REG_RD_DQS_SLAVE_RATIO3_SHIFT                             (16U)
#define EMIF_EXT_PHY_CTRL_8_REG_RD_DQS_SLAVE_RATIO3_MASK                              (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_8_REG_RD_DQS_SLAVE_RATIO2_SHIFT                             (0U)
#define EMIF_EXT_PHY_CTRL_8_REG_RD_DQS_SLAVE_RATIO2_MASK                              (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_8_SHDW_REG_RD_DQS_SLAVE_RATIO3_SHIFT                      (16U)
#define EMIF_EXT_PHY_CTRL_8_SHDW_REG_RD_DQS_SLAVE_RATIO3_MASK                       (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_8_SHDW_REG_RD_DQS_SLAVE_RATIO2_SHIFT                      (0U)
#define EMIF_EXT_PHY_CTRL_8_SHDW_REG_RD_DQS_SLAVE_RATIO2_MASK                       (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_9_REG_RD_DQS_SLAVE_RATIO5_SHIFT                             (16U)
#define EMIF_EXT_PHY_CTRL_9_REG_RD_DQS_SLAVE_RATIO5_MASK                              (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_9_REG_RD_DQS_SLAVE_RATIO4_SHIFT                             (0U)
#define EMIF_EXT_PHY_CTRL_9_REG_RD_DQS_SLAVE_RATIO4_MASK                              (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_9_SHDW_REG_RD_DQS_SLAVE_RATIO5_SHIFT                      (16U)
#define EMIF_EXT_PHY_CTRL_9_SHDW_REG_RD_DQS_SLAVE_RATIO5_MASK                       (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_9_SHDW_REG_RD_DQS_SLAVE_RATIO4_SHIFT                      (0U)
#define EMIF_EXT_PHY_CTRL_9_SHDW_REG_RD_DQS_SLAVE_RATIO4_MASK                       (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_10_REG_RD_DQS_SLAVE_RATIO7_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_10_REG_RD_DQS_SLAVE_RATIO7_MASK                             (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_10_REG_RD_DQS_SLAVE_RATIO6_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_10_REG_RD_DQS_SLAVE_RATIO6_MASK                             (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_10_SHDW_REG_RD_DQS_SLAVE_RATIO7_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_10_SHDW_REG_RD_DQS_SLAVE_RATIO7_MASK                      (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_10_SHDW_REG_RD_DQS_SLAVE_RATIO6_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_10_SHDW_REG_RD_DQS_SLAVE_RATIO6_MASK                      (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_11_REG_RD_DQS_SLAVE_RATIO9_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_11_REG_RD_DQS_SLAVE_RATIO9_MASK                             (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_11_REG_RD_DQS_SLAVE_RATIO8_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_11_REG_RD_DQS_SLAVE_RATIO8_MASK                             (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_11_SHDW_REG_RD_DQS_SLAVE_RATIO9_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_11_SHDW_REG_RD_DQS_SLAVE_RATIO9_MASK                      (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_11_SHDW_REG_RD_DQS_SLAVE_RATIO8_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_11_SHDW_REG_RD_DQS_SLAVE_RATIO8_MASK                      (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_12_REG_WR_DATA_SLAVE_RATIO1_SHIFT                           (16U)
#define EMIF_EXT_PHY_CTRL_12_REG_WR_DATA_SLAVE_RATIO1_MASK                            (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_12_REG_WR_DATA_SLAVE_RATIO0_SHIFT                           (0U)
#define EMIF_EXT_PHY_CTRL_12_REG_WR_DATA_SLAVE_RATIO0_MASK                            (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_12_SHDW_REG_WR_DATA_SLAVE_RATIO1_SHIFT                    (16U)
#define EMIF_EXT_PHY_CTRL_12_SHDW_REG_WR_DATA_SLAVE_RATIO1_MASK                     (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_12_SHDW_REG_WR_DATA_SLAVE_RATIO0_SHIFT                    (0U)
#define EMIF_EXT_PHY_CTRL_12_SHDW_REG_WR_DATA_SLAVE_RATIO0_MASK                     (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_13_REG_WR_DATA_SLAVE_RATIO3_SHIFT                           (16U)
#define EMIF_EXT_PHY_CTRL_13_REG_WR_DATA_SLAVE_RATIO3_MASK                            (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_13_REG_WR_DATA_SLAVE_RATIO2_SHIFT                           (0U)
#define EMIF_EXT_PHY_CTRL_13_REG_WR_DATA_SLAVE_RATIO2_MASK                            (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_13_SHDW_REG_WR_DATA_SLAVE_RATIO3_SHIFT                    (16U)
#define EMIF_EXT_PHY_CTRL_13_SHDW_REG_WR_DATA_SLAVE_RATIO3_MASK                     (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_13_SHDW_REG_WR_DATA_SLAVE_RATIO2_SHIFT                    (0U)
#define EMIF_EXT_PHY_CTRL_13_SHDW_REG_WR_DATA_SLAVE_RATIO2_MASK                     (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_14_REG_WR_DATA_SLAVE_RATIO5_SHIFT                           (16U)
#define EMIF_EXT_PHY_CTRL_14_REG_WR_DATA_SLAVE_RATIO5_MASK                            (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_14_REG_WR_DATA_SLAVE_RATIO4_SHIFT                           (0U)
#define EMIF_EXT_PHY_CTRL_14_REG_WR_DATA_SLAVE_RATIO4_MASK                            (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_14_SHDW_REG_WR_DATA_SLAVE_RATIO5_SHIFT                    (16U)
#define EMIF_EXT_PHY_CTRL_14_SHDW_REG_WR_DATA_SLAVE_RATIO5_MASK                     (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_14_SHDW_REG_WR_DATA_SLAVE_RATIO4_SHIFT                    (0U)
#define EMIF_EXT_PHY_CTRL_14_SHDW_REG_WR_DATA_SLAVE_RATIO4_MASK                     (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_15_REG_WR_DATA_SLAVE_RATIO7_SHIFT                           (16U)
#define EMIF_EXT_PHY_CTRL_15_REG_WR_DATA_SLAVE_RATIO7_MASK                            (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_15_REG_WR_DATA_SLAVE_RATIO6_SHIFT                           (0U)
#define EMIF_EXT_PHY_CTRL_15_REG_WR_DATA_SLAVE_RATIO6_MASK                            (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_15_SHDW_REG_WR_DATA_SLAVE_RATIO7_SHIFT                    (16U)
#define EMIF_EXT_PHY_CTRL_15_SHDW_REG_WR_DATA_SLAVE_RATIO7_MASK                     (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_15_SHDW_REG_WR_DATA_SLAVE_RATIO6_SHIFT                    (0U)
#define EMIF_EXT_PHY_CTRL_15_SHDW_REG_WR_DATA_SLAVE_RATIO6_MASK                     (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_16_REG_WR_DATA_SLAVE_RATIO9_SHIFT                           (16U)
#define EMIF_EXT_PHY_CTRL_16_REG_WR_DATA_SLAVE_RATIO9_MASK                            (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_16_REG_WR_DATA_SLAVE_RATIO8_SHIFT                           (0U)
#define EMIF_EXT_PHY_CTRL_16_REG_WR_DATA_SLAVE_RATIO8_MASK                            (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_16_SHDW_REG_WR_DATA_SLAVE_RATIO9_SHIFT                    (16U)
#define EMIF_EXT_PHY_CTRL_16_SHDW_REG_WR_DATA_SLAVE_RATIO9_MASK                     (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_16_SHDW_REG_WR_DATA_SLAVE_RATIO8_SHIFT                    (0U)
#define EMIF_EXT_PHY_CTRL_16_SHDW_REG_WR_DATA_SLAVE_RATIO8_MASK                     (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_17_REG_WR_DQS_SLAVE_RATIO1_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_17_REG_WR_DQS_SLAVE_RATIO1_MASK                             (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_17_REG_WR_DQS_SLAVE_RATIO0_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_17_REG_WR_DQS_SLAVE_RATIO0_MASK                             (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_17_SHDW_REG_WR_DQS_SLAVE_RATIO1_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_17_SHDW_REG_WR_DQS_SLAVE_RATIO1_MASK                      (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_17_SHDW_REG_WR_DQS_SLAVE_RATIO0_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_17_SHDW_REG_WR_DQS_SLAVE_RATIO0_MASK                      (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_18_REG_WR_DQS_SLAVE_RATIO3_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_18_REG_WR_DQS_SLAVE_RATIO3_MASK                             (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_18_REG_WR_DQS_SLAVE_RATIO2_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_18_REG_WR_DQS_SLAVE_RATIO2_MASK                             (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_18_SHDW_REG_WR_DQS_SLAVE_RATIO3_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_18_SHDW_REG_WR_DQS_SLAVE_RATIO3_MASK                      (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_18_SHDW_REG_WR_DQS_SLAVE_RATIO2_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_18_SHDW_REG_WR_DQS_SLAVE_RATIO2_MASK                      (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_19_REG_WR_DQS_SLAVE_RATIO5_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_19_REG_WR_DQS_SLAVE_RATIO5_MASK                             (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_19_REG_WR_DQS_SLAVE_RATIO4_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_19_REG_WR_DQS_SLAVE_RATIO4_MASK                             (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_19_SHDW_REG_WR_DQS_SLAVE_RATIO5_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_19_SHDW_REG_WR_DQS_SLAVE_RATIO5_MASK                      (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_19_SHDW_REG_WR_DQS_SLAVE_RATIO4_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_19_SHDW_REG_WR_DQS_SLAVE_RATIO4_MASK                      (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_20_REG_WR_DQS_SLAVE_RATIO7_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_20_REG_WR_DQS_SLAVE_RATIO7_MASK                             (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_20_REG_WR_DQS_SLAVE_RATIO6_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_20_REG_WR_DQS_SLAVE_RATIO6_MASK                             (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_20_SHDW_REG_WR_DQS_SLAVE_RATIO7_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_20_SHDW_REG_WR_DQS_SLAVE_RATIO7_MASK                      (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_20_SHDW_REG_WR_DQS_SLAVE_RATIO6_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_20_SHDW_REG_WR_DQS_SLAVE_RATIO6_MASK                      (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_21_REG_WR_DQS_SLAVE_RATIO9_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_21_REG_WR_DQS_SLAVE_RATIO9_MASK                             (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_21_REG_WR_DQS_SLAVE_RATIO8_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_21_REG_WR_DQS_SLAVE_RATIO8_MASK                             (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_21_SHDW_REG_WR_DQS_SLAVE_RATIO9_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_21_SHDW_REG_WR_DQS_SLAVE_RATIO9_MASK                      (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_21_SHDW_REG_WR_DQS_SLAVE_RATIO8_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_21_SHDW_REG_WR_DQS_SLAVE_RATIO8_MASK                      (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_22_REG_FIFO_WE_IN_DELAY_SHIFT                               (16U)
#define EMIF_EXT_PHY_CTRL_22_REG_FIFO_WE_IN_DELAY_MASK                                (0x01ff0000U)

#define EMIF_EXT_PHY_CTRL_22_REG_SLAVE_DELAY_SHIFT                                    (0U)
#define EMIF_EXT_PHY_CTRL_22_REG_SLAVE_DELAY_MASK                                     (0x000001ffU)

#define EMIF_EXT_PHY_CTRL_22_SHDW_REG_FIFO_WE_IN_DELAY_SHIFT                        (16U)
#define EMIF_EXT_PHY_CTRL_22_SHDW_REG_FIFO_WE_IN_DELAY_MASK                         (0x01ff0000U)

#define EMIF_EXT_PHY_CTRL_22_SHDW_REG_SLAVE_DELAY_SHIFT                             (0U)
#define EMIF_EXT_PHY_CTRL_22_SHDW_REG_SLAVE_DELAY_MASK                              (0x000001ffU)

#define EMIF_EXT_PHY_CTRL_23_REG_WR_DQS_SLAVE_DELAY_SHIFT                             (16U)
#define EMIF_EXT_PHY_CTRL_23_REG_WR_DQS_SLAVE_DELAY_MASK                              (0x01ff0000U)

#define EMIF_EXT_PHY_CTRL_23_REG_RD_DQS_SLAVE_DELAY_SHIFT                             (0U)
#define EMIF_EXT_PHY_CTRL_23_REG_RD_DQS_SLAVE_DELAY_MASK                              (0x000001ffU)

#define EMIF_EXT_PHY_CTRL_23_SHDW_REG_WR_DQS_SLAVE_DELAY_SHIFT                      (16U)
#define EMIF_EXT_PHY_CTRL_23_SHDW_REG_WR_DQS_SLAVE_DELAY_MASK                       (0x01ff0000U)

#define EMIF_EXT_PHY_CTRL_23_SHDW_REG_RD_DQS_SLAVE_DELAY_SHIFT                      (0U)
#define EMIF_EXT_PHY_CTRL_23_SHDW_REG_RD_DQS_SLAVE_DELAY_MASK                       (0x000001ffU)

#define EMIF_EXT_PHY_CTRL_24_REG_DQ_OFFSET_HI_SHIFT                                   (24U)
#define EMIF_EXT_PHY_CTRL_24_REG_DQ_OFFSET_HI_MASK                                    (0x7f000000U)

#define EMIF_EXT_PHY_CTRL_24_REG_GATELVL_INIT_MODE_SHIFT                              (16U)
#define EMIF_EXT_PHY_CTRL_24_REG_GATELVL_INIT_MODE_MASK                               (0x00010000U)

#define EMIF_EXT_PHY_CTRL_24_REG_USE_RANK0_DELAYS_SHIFT                               (12U)
#define EMIF_EXT_PHY_CTRL_24_REG_USE_RANK0_DELAYS_MASK                                (0x00001000U)

#define EMIF_EXT_PHY_CTRL_24_REG_WR_DATA_SLAVE_DELAY_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_24_REG_WR_DATA_SLAVE_DELAY_MASK                             (0x000001ffU)

#define EMIF_EXT_PHY_CTRL_24_SHDW_REG_DQ_OFFSET_HI_SHIFT                            (24U)
#define EMIF_EXT_PHY_CTRL_24_SHDW_REG_DQ_OFFSET_HI_MASK                             (0x7f000000U)

#define EMIF_EXT_PHY_CTRL_24_SHDW_REG_GATELVL_INIT_MODE_SHIFT                       (16U)
#define EMIF_EXT_PHY_CTRL_24_SHDW_REG_GATELVL_INIT_MODE_MASK                        (0x00010000U)

#define EMIF_EXT_PHY_CTRL_24_SHDW_REG_USE_RANK0_DELAYS_SHIFT                        (12U)
#define EMIF_EXT_PHY_CTRL_24_SHDW_REG_USE_RANK0_DELAYS_MASK                         (0x00001000U)

#define EMIF_EXT_PHY_CTRL_24_SHDW_REG_WR_DATA_SLAVE_DELAY_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_24_SHDW_REG_WR_DATA_SLAVE_DELAY_MASK                      (0x000001ffU)

#define EMIF_EXT_PHY_CTRL_25_REG_DQ_OFFSET_SHIFT                                      (0U)
#define EMIF_EXT_PHY_CTRL_25_REG_DQ_OFFSET_MASK                                       (0x0fffffffU)

#define EMIF_EXT_PHY_CTRL_25_SHDW_REG_DQ_OFFSET_SHIFT                               (0U)
#define EMIF_EXT_PHY_CTRL_25_SHDW_REG_DQ_OFFSET_MASK                                (0x0fffffffU)

#define EMIF_EXT_PHY_CTRL_26_REG_GATELVL_INIT_RATIO1_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_26_REG_GATELVL_INIT_RATIO1_MASK                             (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_26_REG_GATELVL_INIT_RATIO0_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_26_REG_GATELVL_INIT_RATIO0_MASK                             (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_26_SHDW_REG_GATELVL_INIT_RATIO1_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_26_SHDW_REG_GATELVL_INIT_RATIO1_MASK                      (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_26_SHDW_REG_GATELVL_INIT_RATIO0_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_26_SHDW_REG_GATELVL_INIT_RATIO0_MASK                      (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_27_REG_GATELVL_INIT_RATIO3_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_27_REG_GATELVL_INIT_RATIO3_MASK                             (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_27_REG_GATELVL_INIT_RATIO2_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_27_REG_GATELVL_INIT_RATIO2_MASK                             (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_27_SHDW_REG_GATELVL_INIT_RATIO3_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_27_SHDW_REG_GATELVL_INIT_RATIO3_MASK                      (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_27_SHDW_REG_GATELVL_INIT_RATIO2_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_27_SHDW_REG_GATELVL_INIT_RATIO2_MASK                      (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_28_REG_GATELVL_INIT_RATIO5_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_28_REG_GATELVL_INIT_RATIO5_MASK                             (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_28_REG_GATELVL_INIT_RATIO4_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_28_REG_GATELVL_INIT_RATIO4_MASK                             (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_28_SHDW_REG_GATELVL_INIT_RATIO5_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_28_SHDW_REG_GATELVL_INIT_RATIO5_MASK                      (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_28_SHDW_REG_GATELVL_INIT_RATIO4_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_28_SHDW_REG_GATELVL_INIT_RATIO4_MASK                      (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_29_REG_GATELVL_INIT_RATIO7_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_29_REG_GATELVL_INIT_RATIO7_MASK                             (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_29_REG_GATELVL_INIT_RATIO6_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_29_REG_GATELVL_INIT_RATIO6_MASK                             (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_29_SHDW_REG_GATELVL_INIT_RATIO7_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_29_SHDW_REG_GATELVL_INIT_RATIO7_MASK                      (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_29_SHDW_REG_GATELVL_INIT_RATIO6_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_29_SHDW_REG_GATELVL_INIT_RATIO6_MASK                      (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_30_REG_GATELVL_INIT_RATIO9_SHIFT                            (16U)
#define EMIF_EXT_PHY_CTRL_30_REG_GATELVL_INIT_RATIO9_MASK                             (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_30_REG_GATELVL_INIT_RATIO8_SHIFT                            (0U)
#define EMIF_EXT_PHY_CTRL_30_REG_GATELVL_INIT_RATIO8_MASK                             (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_30_SHDW_REG_GATELVL_INIT_RATIO9_SHIFT                     (16U)
#define EMIF_EXT_PHY_CTRL_30_SHDW_REG_GATELVL_INIT_RATIO9_MASK                      (0x07ff0000U)

#define EMIF_EXT_PHY_CTRL_30_SHDW_REG_GATELVL_INIT_RATIO8_SHIFT                     (0U)
#define EMIF_EXT_PHY_CTRL_30_SHDW_REG_GATELVL_INIT_RATIO8_MASK                      (0x000007ffU)

#define EMIF_EXT_PHY_CTRL_31_REG_WRLVL_INIT_RATIO1_SHIFT                              (16U)
#define EMIF_EXT_PHY_CTRL_31_REG_WRLVL_INIT_RATIO1_MASK                               (0x003f0000U)

#define EMIF_EXT_PHY_CTRL_31_REG_WRLVL_INIT_RATIO0_SHIFT                              (0U)
#define EMIF_EXT_PHY_CTRL_31_REG_WRLVL_INIT_RATIO0_MASK                               (0x0000003fU)

#define EMIF_EXT_PHY_CTRL_31_SHDW_REG_WRLVL_INIT_RATIO1_SHIFT                       (16U)
#define EMIF_EXT_PHY_CTRL_31_SHDW_REG_WRLVL_INIT_RATIO1_MASK                        (0x003f0000U)

#define EMIF_EXT_PHY_CTRL_31_SHDW_REG_WRLVL_INIT_RATIO0_SHIFT                       (0U)
#define EMIF_EXT_PHY_CTRL_31_SHDW_REG_WRLVL_INIT_RATIO0_MASK                        (0x0000003fU)

#define EMIF_EXT_PHY_CTRL_32_REG_WRLVL_INIT_RATIO3_SHIFT                              (16U)
#define EMIF_EXT_PHY_CTRL_32_REG_WRLVL_INIT_RATIO3_MASK                               (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_32_REG_WRLVL_INIT_RATIO2_SHIFT                              (0U)
#define EMIF_EXT_PHY_CTRL_32_REG_WRLVL_INIT_RATIO2_MASK                               (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_32_SHDW_REG_WRLVL_INIT_RATIO3_SHIFT                       (16U)
#define EMIF_EXT_PHY_CTRL_32_SHDW_REG_WRLVL_INIT_RATIO3_MASK                        (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_32_SHDW_REG_WRLVL_INIT_RATIO2_SHIFT                       (0U)
#define EMIF_EXT_PHY_CTRL_32_SHDW_REG_WRLVL_INIT_RATIO2_MASK                        (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_33_REG_WRLVL_INIT_RATIO5_SHIFT                              (16U)
#define EMIF_EXT_PHY_CTRL_33_REG_WRLVL_INIT_RATIO5_MASK                               (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_33_REG_WRLVL_INIT_RATIO4_SHIFT                              (0U)
#define EMIF_EXT_PHY_CTRL_33_REG_WRLVL_INIT_RATIO4_MASK                               (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_33_SHDW_REG_WRLVL_INIT_RATIO5_SHIFT                       (16U)
#define EMIF_EXT_PHY_CTRL_33_SHDW_REG_WRLVL_INIT_RATIO5_MASK                        (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_33_SHDW_REG_WRLVL_INIT_RATIO4_SHIFT                       (0U)
#define EMIF_EXT_PHY_CTRL_33_SHDW_REG_WRLVL_INIT_RATIO4_MASK                        (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_34_REG_WRLVL_INIT_RATIO7_SHIFT                              (16U)
#define EMIF_EXT_PHY_CTRL_34_REG_WRLVL_INIT_RATIO7_MASK                               (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_34_REG_WRLVL_INIT_RATIO6_SHIFT                              (0U)
#define EMIF_EXT_PHY_CTRL_34_REG_WRLVL_INIT_RATIO6_MASK                               (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_34_SHDW_REG_WRLVL_INIT_RATIO7_SHIFT                       (16U)
#define EMIF_EXT_PHY_CTRL_34_SHDW_REG_WRLVL_INIT_RATIO7_MASK                        (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_34_SHDW_REG_WRLVL_INIT_RATIO6_SHIFT                       (0U)
#define EMIF_EXT_PHY_CTRL_34_SHDW_REG_WRLVL_INIT_RATIO6_MASK                        (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_35_REG_WRLVL_INIT_RATIO9_SHIFT                              (16U)
#define EMIF_EXT_PHY_CTRL_35_REG_WRLVL_INIT_RATIO9_MASK                               (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_35_REG_WRLVL_INIT_RATIO8_SHIFT                              (0U)
#define EMIF_EXT_PHY_CTRL_35_REG_WRLVL_INIT_RATIO8_MASK                               (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_35_SHDW_REG_WRLVL_INIT_RATIO9_SHIFT                       (16U)
#define EMIF_EXT_PHY_CTRL_35_SHDW_REG_WRLVL_INIT_RATIO9_MASK                        (0x03ff0000U)

#define EMIF_EXT_PHY_CTRL_35_SHDW_REG_WRLVL_INIT_RATIO8_SHIFT                       (0U)
#define EMIF_EXT_PHY_CTRL_35_SHDW_REG_WRLVL_INIT_RATIO8_MASK                        (0x000003ffU)

#define EMIF_EXT_PHY_CTRL_36_REG_RDC_FIFO_RST_ERR_CNT_CLR_SHIFT                       (10U)
#define EMIF_EXT_PHY_CTRL_36_REG_RDC_FIFO_RST_ERR_CNT_CLR_MASK                        (0x00000400U)

#define EMIF_EXT_PHY_CTRL_36_REG_MDLL_UNLOCK_CLR_SHIFT                                (9U)
#define EMIF_EXT_PHY_CTRL_36_REG_MDLL_UNLOCK_CLR_MASK                                 (0x00000200U)

#define EMIF_EXT_PHY_CTRL_36_REG_FIFO_WE_IN_MISALIGNED_CLR_SHIFT                      (8U)
#define EMIF_EXT_PHY_CTRL_36_REG_FIFO_WE_IN_MISALIGNED_CLR_MASK                       (0x00000100U)

#define EMIF_EXT_PHY_CTRL_36_REG_WRLVL_NUM_OF_DQ0_SHIFT                               (4U)
#define EMIF_EXT_PHY_CTRL_36_REG_WRLVL_NUM_OF_DQ0_MASK                                (0x000000f0U)

#define EMIF_EXT_PHY_CTRL_36_REG_GATELVL_NUM_OF_DQ0_SHIFT                             (0U)
#define EMIF_EXT_PHY_CTRL_36_REG_GATELVL_NUM_OF_DQ0_MASK                              (0x0000000fU)

#define EMIF_EXT_PHY_CTRL_36_SHDW_REG_RDC_FIFO_RST_ERR_CNT_CLR_SHIFT                (10U)
#define EMIF_EXT_PHY_CTRL_36_SHDW_REG_RDC_FIFO_RST_ERR_CNT_CLR_MASK                 (0x00000400U)

#define EMIF_EXT_PHY_CTRL_36_SHDW_REG_MDLL_UNLOCK_CLR_SHIFT                         (9U)
#define EMIF_EXT_PHY_CTRL_36_SHDW_REG_MDLL_UNLOCK_CLR_MASK                          (0x00000200U)

#define EMIF_EXT_PHY_CTRL_36_SHDW_REG_FIFO_WE_IN_MISALIGNED_CLR_SHIFT               (8U)
#define EMIF_EXT_PHY_CTRL_36_SHDW_REG_FIFO_WE_IN_MISALIGNED_CLR_MASK                (0x00000100U)

#define EMIF_EXT_PHY_CTRL_36_SHDW_REG_WRLVL_NUM_OF_DQ0_SHIFT                        (4U)
#define EMIF_EXT_PHY_CTRL_36_SHDW_REG_WRLVL_NUM_OF_DQ0_MASK                         (0x000000f0U)

#define EMIF_EXT_PHY_CTRL_36_SHDW_REG_GATELVL_NUM_OF_DQ0_SHIFT                      (0U)
#define EMIF_EXT_PHY_CTRL_36_SHDW_REG_GATELVL_NUM_OF_DQ0_MASK                       (0x0000000fU)

#define EMIF_MISC_REG_DLL_CALIB_OS_SHIFT                                              (0U)
#define EMIF_MISC_REG_DLL_CALIB_OS_MASK                                               (0x00000001U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_EMIF_H_ */
