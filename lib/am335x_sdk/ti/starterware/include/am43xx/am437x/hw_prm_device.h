/*
* hw_prm_device.h
*
* Register-level header file for PRM_DEVICE
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

#ifndef HW_PRM_DEVICE_H_
#define HW_PRM_DEVICE_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions 
****************************************************************************************************/

#define PRCM_PRM_RSTCTRL                                            (0x0U)
#define PRCM_PRM_RSTST                                              (0x4U)
#define PRCM_PRM_RSTTIME                                            (0x8U)
#define PRCM_PRM_SRAM_COUNT                                         (0xcU)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP                                (0x10U)
#define PRCM_PRM_LDO_SRAM_CORE_CTRL                                 (0x14U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP                                 (0x18U)
#define PRCM_PRM_LDO_SRAM_MPU_CTRL                                  (0x1cU)
#define PRCM_PRM_IO_COUNT                                           (0x20U)
#define PRCM_PRM_IO_PMCTRL                                          (0x24U)
#define PRCM_PRM_VC_VAL_BYPASS                                      (0x28U)
#define PRCM_PRM_EMIF_CTRL                                          (0x30U)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define PRCM_PRM_RSTCTRL_RST_GLOBAL_WARM_SW_SHIFT                                       (0U)
#define PRCM_PRM_RSTCTRL_RST_GLOBAL_WARM_SW_MASK                                        (0x00000001U)
#define PRCM_PRM_RSTCTRL_RST_GLOBAL_WARM_SW_0X0                                          (0U)
#define PRCM_PRM_RSTCTRL_RST_GLOBAL_WARM_SW_0X1                                          (1U)

#define PRCM_PRM_RSTCTRL_RST_GLOBAL_COLD_SW_SHIFT                                       (1U)
#define PRCM_PRM_RSTCTRL_RST_GLOBAL_COLD_SW_MASK                                        (0x00000002U)
#define PRCM_PRM_RSTCTRL_RST_GLOBAL_COLD_SW_0X0                                          (0U)
#define PRCM_PRM_RSTCTRL_RST_GLOBAL_COLD_SW_0X1                                          (1U)

#define PRCM_PRM_RSTST_GLOBAL_COLD_RST_SHIFT                                            (0U)
#define PRCM_PRM_RSTST_GLOBAL_COLD_RST_MASK                                             (0x00000001U)
#define PRCM_PRM_RSTST_GLOBAL_COLD_RST_0X0                                               (0U)
#define PRCM_PRM_RSTST_GLOBAL_COLD_RST_0X1                                               (1U)

#define PRCM_PRM_RSTST_GLOBAL_WARM_SW_RST_SHIFT                                         (1U)
#define PRCM_PRM_RSTST_GLOBAL_WARM_SW_RST_MASK                                          (0x00000002U)
#define PRCM_PRM_RSTST_GLOBAL_WARM_SW_RST_0X0                                            (0U)
#define PRCM_PRM_RSTST_GLOBAL_WARM_SW_RST_0X1                                            (1U)

#define PRCM_PRM_RSTST_MPU_SECURITY_VIOL_RST_SHIFT                                      (2U)
#define PRCM_PRM_RSTST_MPU_SECURITY_VIOL_RST_MASK                                       (0x00000004U)
#define PRCM_PRM_RSTST_MPU_SECURITY_VIOL_RST_0X0                                         (0U)
#define PRCM_PRM_RSTST_MPU_SECURITY_VIOL_RST_0X1                                         (1U)

#define PRCM_PRM_RSTST_WDT0_RST_SHIFT                                                   (3U)
#define PRCM_PRM_RSTST_WDT0_RST_MASK                                                    (0x00000008U)
#define PRCM_PRM_RSTST_WDT0_RST_0X0                                                      (0U)
#define PRCM_PRM_RSTST_WDT0_RST_0X1                                                      (1U)

#define PRCM_PRM_RSTST_EXTERNAL_WARM_RST_SHIFT                                          (5U)
#define PRCM_PRM_RSTST_EXTERNAL_WARM_RST_MASK                                           (0x00000020U)
#define PRCM_PRM_RSTST_EXTERNAL_WARM_RST_0X0                                             (0U)
#define PRCM_PRM_RSTST_EXTERNAL_WARM_RST_0X1                                             (1U)

#define PRCM_PRM_RSTST_ICEPICK_RST_SHIFT                                                (9U)
#define PRCM_PRM_RSTST_ICEPICK_RST_MASK                                                 (0x00000200U)
#define PRCM_PRM_RSTST_ICEPICK_RST_0X0                                                   (0U)
#define PRCM_PRM_RSTST_ICEPICK_RST_0X1                                                   (1U)

#define PRCM_PRM_RSTST_WDT1_RST_SHIFT                                                   (4U)
#define PRCM_PRM_RSTST_WDT1_RST_MASK                                                    (0x00000010U)
#define PRCM_PRM_RSTST_WDT1_RST_0X0                                                      (0U)
#define PRCM_PRM_RSTST_WDT1_RST_0X1                                                      (1U)

#define PRCM_PRM_RSTTIME_RSTTIME1_SHIFT                                                 (0U)
#define PRCM_PRM_RSTTIME_RSTTIME1_MASK                                                  (0x000003ffU)

#define PRCM_PRM_RSTTIME_RSTTIME2_SHIFT                                                 (10U)
#define PRCM_PRM_RSTTIME_RSTTIME2_MASK                                                  (0x00007c00U)

#define PRCM_PRM_SRAM_COUNT_PCHARGECNT_VALUE_SHIFT                                      (0U)
#define PRCM_PRM_SRAM_COUNT_PCHARGECNT_VALUE_MASK                                       (0x0000003fU)

#define PRCM_PRM_SRAM_COUNT_VSETUPCNT_VALUE_SHIFT                                       (8U)
#define PRCM_PRM_SRAM_COUNT_VSETUPCNT_VALUE_MASK                                        (0x0000ff00U)

#define PRCM_PRM_SRAM_COUNT_SLPCNT_VALUE_SHIFT                                          (16U)
#define PRCM_PRM_SRAM_COUNT_SLPCNT_VALUE_MASK                                           (0x00ff0000U)

#define PRCM_PRM_SRAM_COUNT_STARTUP_SHIFT                                               (24U)
#define PRCM_PRM_SRAM_COUNT_STARTUP_MASK                                                (0xff000000U)

#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ABBOFF_ACT_EXPORT_SHIFT                            (1U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ABBOFF_ACT_EXPORT_MASK                             (0x00000002U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ABBOFF_ACT_EXPORT_SRAMNW_VDDS                       (0U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ABBOFF_ACT_EXPORT_SRAMNW_VDDAR                      (1U)

#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ABBOFF_SLEEP_EXPORT_SHIFT                          (2U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ABBOFF_SLEEP_EXPORT_MASK                           (0x00000004U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ABBOFF_SLEEP_EXPORT_SRAMNW_SLP_VDDS                 (0U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ABBOFF_SLEEP_EXPORT_SRAMNW_SLP_VDDAR                (1U)

#define PRCM_PRM_LDO_SRAM_CORE_SETUP_DISABLE_RTA_EXPORT_SHIFT                           (0U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_DISABLE_RTA_EXPORT_MASK                            (0x00000001U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_DISABLE_RTA_EXPORT_ENABLED                          (0U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_DISABLE_RTA_EXPORT_DISABLED                         (1U)

#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC1_EXPORT_SHIFT                               (3U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC1_EXPORT_MASK                                (0x00000008U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC1_EXPORT_SHORT_PROT_DISABLED                  (0U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC1_EXPORT_SHORT_PROT_ENABLED                   (1U)

#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC2_EXPORT_SHIFT                               (4U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC2_EXPORT_MASK                                (0x00000010U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC2_EXPORT_EXT_CAP                              (0U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC2_EXPORT_NO_EXT_CAP                           (1U)

#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC3_EXPORT_SHIFT                               (5U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC3_EXPORT_MASK                                (0x00000020U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC3_EXPORT_SUB_REGUL_DISABLED                   (0U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC3_EXPORT_SUB_REGUL_ENABLED                    (1U)

#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC4_SHIFT                                      (6U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC4_MASK                                       (0x00000040U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC4_EXT_CLOCK                                   (0U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC4_NO_EXT_CLOCK                                (1U)

#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC5_SHIFT                                      (7U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC5_MASK                                       (0x00000080U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC5_ONE_STEP                                    (0U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_ENFUNC5_TWO_STEP                                    (1U)

#define PRCM_PRM_LDO_SRAM_CORE_SETUP_AIPOFF_SHIFT                                       (8U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_AIPOFF_MASK                                        (0x00000100U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_AIPOFF_NO_OVERRIDE                                  (0U)
#define PRCM_PRM_LDO_SRAM_CORE_SETUP_AIPOFF_OVERRIDE                                     (1U)

#define PRCM_PRM_LDO_SRAM_CORE_CTRL_SRAMLDO_STS_SHIFT                                   (8U)
#define PRCM_PRM_LDO_SRAM_CORE_CTRL_SRAMLDO_STS_MASK                                    (0x00000100U)
#define PRCM_PRM_LDO_SRAM_CORE_CTRL_SRAMLDO_STS_ACTIVE                                   (0U)
#define PRCM_PRM_LDO_SRAM_CORE_CTRL_SRAMLDO_STS_RETENTION                                (1U)

#define PRCM_PRM_LDO_SRAM_CORE_CTRL_IN_TRANSITION_SHIFT                                 (9U)
#define PRCM_PRM_LDO_SRAM_CORE_CTRL_IN_TRANSITION_MASK                                  (0x00000200U)
#define PRCM_PRM_LDO_SRAM_CORE_CTRL_IN_TRANSITION_IDLE                                   (0U)
#define PRCM_PRM_LDO_SRAM_CORE_CTRL_IN_TRANSITION                                        (1U)

#define PRCM_PRM_LDO_SRAM_CORE_CTRL_RETMODE_EN_SHIFT                                    (0U)
#define PRCM_PRM_LDO_SRAM_CORE_CTRL_RETMODE_EN_MASK                                     (0x00000001U)
#define PRCM_PRM_LDO_SRAM_CORE_CTRL_RETMODE_EN_DISABLED                                  (0U)
#define PRCM_PRM_LDO_SRAM_CORE_CTRL_RETMODE_EN_ENABLED                                   (1U)

#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ABBOFF_ACT_EXPORT_SHIFT                             (1U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ABBOFF_ACT_EXPORT_MASK                              (0x00000002U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ABBOFF_ACT_EXPORT_SRAMNW_VDDS                        (0U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ABBOFF_ACT_EXPORT_SRAMNW_VDDAR                       (1U)

#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ABBOFF_SLEEP_EXPORT_SHIFT                           (2U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ABBOFF_SLEEP_EXPORT_MASK                            (0x00000004U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ABBOFF_SLEEP_EXPORT_SRAMNW_SLP_VDDS                  (0U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ABBOFF_SLEEP_EXPORT_SRAMNW_SLP_VDDAR                 (1U)

#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC4_SHIFT                                       (6U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC4_MASK                                        (0x00000040U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC4_EXT_CLOCK                                    (0U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC4_NO_EXT_CLOCK                                 (1U)

#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC5_SHIFT                                       (7U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC5_MASK                                        (0x00000080U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC5_ONE_STEP                                     (0U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC5_TWO_STEP                                     (1U)

#define PRCM_PRM_LDO_SRAM_MPU_SETUP_AIPOFF_SHIFT                                        (8U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_AIPOFF_MASK                                         (0x00000100U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_AIPOFF_NO_OVERRIDE                                   (0U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_AIPOFF_OVERRIDE                                      (1U)

#define PRCM_PRM_LDO_SRAM_MPU_SETUP_DISABLE_RTA_EXPORT_SHIFT                            (0U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_DISABLE_RTA_EXPORT_MASK                             (0x00000001U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_DISABLE_RTA_EXPORT_ENABLED                           (0U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_DISABLE_RTA_EXPORT_DISABLED                          (1U)

#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC1_EXPORT_SHIFT                                (3U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC1_EXPORT_MASK                                 (0x00000008U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC1_EXPORT_SHORT_PROT_DISABLED                   (0U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC1_EXPORT_SHORT_PROT_ENABLED                    (1U)

#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC2_EXPORT_SHIFT                                (4U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC2_EXPORT_MASK                                 (0x00000010U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC2_EXPORT_EXT_CAP                               (0U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC2_EXPORT_NO_EXT_CAP                            (1U)

#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC3_EXPORT_SHIFT                                (5U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC3_EXPORT_MASK                                 (0x00000020U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC3_EXPORT_SUB_REGUL_DISABLED                    (0U)
#define PRCM_PRM_LDO_SRAM_MPU_SETUP_ENFUNC3_EXPORT_SUB_REGUL_ENABLED                     (1U)

#define PRCM_PRM_LDO_SRAM_MPU_CTRL_SRAMLDO_STS_SHIFT                                    (8U)
#define PRCM_PRM_LDO_SRAM_MPU_CTRL_SRAMLDO_STS_MASK                                     (0x00000100U)
#define PRCM_PRM_LDO_SRAM_MPU_CTRL_SRAMLDO_STS_ACTIVE                                    (0U)
#define PRCM_PRM_LDO_SRAM_MPU_CTRL_SRAMLDO_STS_RETENTION                                 (1U)

#define PRCM_PRM_LDO_SRAM_MPU_CTRL_IN_TRANSITION_SHIFT                                  (9U)
#define PRCM_PRM_LDO_SRAM_MPU_CTRL_IN_TRANSITION_MASK                                   (0x00000200U)
#define PRCM_PRM_LDO_SRAM_MPU_CTRL_IN_TRANSITION_IDLE                                    (0U)
#define PRCM_PRM_LDO_SRAM_MPU_CTRL_IN_TRANSITION                                         (1U)

#define PRCM_PRM_LDO_SRAM_MPU_CTRL_RETMODE_EN_SHIFT                                     (0U)
#define PRCM_PRM_LDO_SRAM_MPU_CTRL_RETMODE_EN_MASK                                      (0x00000001U)
#define PRCM_PRM_LDO_SRAM_MPU_CTRL_RETMODE_EN_DISABLED                                   (0U)
#define PRCM_PRM_LDO_SRAM_MPU_CTRL_RETMODE_EN_ENABLED                                    (1U)

#define PRCM_PRM_IO_COUNT_ISO_2_ON_TIME_SHIFT                                           (0U)
#define PRCM_PRM_IO_COUNT_ISO_2_ON_TIME_MASK                                            (0x000000ffU)

#define PRCM_PRM_IO_PMCTRL_ISOCLK_OVERRIDE_SHIFT                                        (0U)
#define PRCM_PRM_IO_PMCTRL_ISOCLK_OVERRIDE_MASK                                         (0x00000001U)
#define PRCM_PRM_IO_PMCTRL_ISOCLK_OVERRIDE_NOOVERRIDE                                    (0U)
#define PRCM_PRM_IO_PMCTRL_ISOCLK_OVERRIDE                                               (1U)

#define PRCM_PRM_IO_PMCTRL_ISOCLK_STS_SHIFT                                             (1U)
#define PRCM_PRM_IO_PMCTRL_ISOCLK_STS_MASK                                              (0x00000002U)

#define PRCM_PRM_IO_PMCTRL_WUCLK_CTRL_SHIFT                                             (8U)
#define PRCM_PRM_IO_PMCTRL_WUCLK_CTRL_MASK                                              (0x00000100U)
#define PRCM_PRM_IO_PMCTRL_WUCLK_CTRL_LOW                                                (0U)
#define PRCM_PRM_IO_PMCTRL_WUCLK_CTRL_HIGH                                               (1U)

#define PRCM_PRM_IO_PMCTRL_WUCLK_STS_SHIFT                                              (9U)
#define PRCM_PRM_IO_PMCTRL_WUCLK_STS_MASK                                               (0x00000200U)

#define PRCM_PRM_IO_PMCTRL_GLOBAL_WUEN_SHIFT                                            (16U)
#define PRCM_PRM_IO_PMCTRL_GLOBAL_WUEN_MASK                                             (0x00010000U)
#define PRCM_PRM_IO_PMCTRL_GLOBAL_WUEN_DISABLED                                          (0U)
#define PRCM_PRM_IO_PMCTRL_GLOBAL_WUEN_ENABLED                                           (1U)

#define PRCM_PRM_IO_PMCTRL_ISOOVR_EXTEND_SHIFT                                          (4U)
#define PRCM_PRM_IO_PMCTRL_ISOOVR_EXTEND_MASK                                           (0x00000010U)
#define PRCM_PRM_IO_PMCTRL_ISOOVR_EXTEND_NOOVERRIDE                                      (0U)
#define PRCM_PRM_IO_PMCTRL_ISOOVR_EXTEND_OVERRIDE                                        (1U)

#define PRCM_PRM_IO_PMCTRL_ON_STS_SHIFT                                                 (5U)
#define PRCM_PRM_IO_PMCTRL_ON_STS_MASK                                                  (0x00000020U)
#define PRCM_PRM_IO_PMCTRL_ON_STS_LOW                                                    (0U)
#define PRCM_PRM_IO_PMCTRL_ON_STS_HIGH                                                   (1U)

#define PRCM_PRM_IO_PMCTRL_ISO_CTRL_SHIFT                                               (24U)
#define PRCM_PRM_IO_PMCTRL_ISO_CTRL_MASK                                                (0x01000000U)
#define PRCM_PRM_IO_PMCTRL_ISO_CTRL_OFF                                                  (0U)
#define PRCM_PRM_IO_PMCTRL_ISO_CTRL_ON                                                   (1U)

#define PRCM_PRM_IO_PMCTRL_ISO_STS_SHIFT                                                (25U)
#define PRCM_PRM_IO_PMCTRL_ISO_STS_MASK                                                 (0x02000000U)
#define PRCM_PRM_IO_PMCTRL_ISO_STS_ST_OFF                                                (0U)
#define PRCM_PRM_IO_PMCTRL_ISO_STS_ST_ON                                                 (1U)

#define PRCM_PRM_VC_VAL_BYPASS_OPP_CHANGE_EMIF_LVL_SHIFT                                (25U)
#define PRCM_PRM_VC_VAL_BYPASS_OPP_CHANGE_EMIF_LVL_MASK                                 (0x02000000U)
#define PRCM_PRM_VC_VAL_BYPASS_OPP_CHANGE_EMIF_LVL_EN                                    (0U)
#define PRCM_PRM_VC_VAL_BYPASS_OPP_CHANGE_EMIF_LVL_DIS                                   (1U)

#define PRCM_PRM_EMIF_CTRL_DEVOFF_SHIFT                                                 (0U)
#define PRCM_PRM_EMIF_CTRL_DEVOFF_MASK                                                  (0x00000001U)
#define PRCM_PRM_EMIF_CTRL_DEVOFF_OFF                                                    (0U)
#define PRCM_PRM_EMIF_CTRL_DEVOFF_ON                                                     (1U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_PRM_DEVICE_H_ */

