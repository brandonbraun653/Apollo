/*
* hw_hs_mmcsd.h
*
* Register-level header file for SD
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
#ifndef HW_HS_MMC_SD_H_
#define HW_HS_MMC_SD_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define HS_MMC_SD_ADMAES                                               (0x254U)
#define HS_MMC_SD_PSTATE                                               (0x224U)
#define HS_MMC_SD_ADMASAH                                              (0x25cU)
#define HS_MMC_SD_FE                                                   (0x250U)
#define HS_MMC_SD_RSP76                                                (0x21cU)
#define HS_MMC_SD_RSP54                                                (0x218U)
#define HS_MMC_SD_SYSCONFIG                                            (0x110U)
#define HS_MMC_SD_CAPA                                                 (0x240U)
#define HS_MMC_SD_HCTL                                                 (0x228U)
#define HS_MMC_SD_SYSTEST                                              (0x128U)
#define HS_MMC_SD_DATA                                                 (0x220U)
#define HS_MMC_SD_AC12                                                 (0x23cU)
#define HS_MMC_SD_ADMASAL                                              (0x258U)
#define HS_MMC_SD_ISE                                                  (0x238U)
#define HS_MMC_SD_CMD                                                  (0x20cU)
#define HS_MMC_SD_CSRE                                                 (0x124U)
#define HS_MMC_SD_PWCNT                                                (0x130U)
#define HS_MMC_SD_ARG                                                  (0x208U)
#define HS_MMC_SD_REV                                                  (0x2fcU)
#define HS_MMC_SD_STAT                                                 (0x230U)
#define HS_MMC_SD_CON                                                  (0x12cU)
#define HS_MMC_SD_IE                                                   (0x234U)
#define HS_MMC_SD_CUR_CAPA                                             (0x248U)
#define HS_MMC_SD_SYSCTL                                               (0x22cU)
#define HS_MMC_SD_RSP32                                                (0x214U)
#define HS_MMC_SD_BLK                                                  (0x204U)
#define HS_MMC_SD_RSP10                                                (0x210U)
#define HS_MMC_SD_SDMASA                                               (0x200U)
#define HS_MMC_SD_SYSSTATUS                                            (0x114U)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define HS_MMC_SD_ADMAES_AES_SHIFT                                     (0U)
#define HS_MMC_SD_ADMAES_AES_MASK                                      (0x00000003U)
#define HS_MMC_SD_ADMAES_AES_ST_STOP_ERR_DESCR                          (1U)
#define HS_MMC_SD_ADMAES_AES_ST_TFR                                     (3U)
#define HS_MMC_SD_ADMAES_AES_NOT_USED                                   (2U)
#define HS_MMC_SD_ADMAES_AES_ST_STOP_SYS_SDR                            (0U)

#define HS_MMC_SD_ADMAES_LME_SHIFT                                     (2U)
#define HS_MMC_SD_ADMAES_LME_MASK                                      (0x00000004U)
#define HS_MMC_SD_ADMAES_LME_NO_ERR                                     (0U)
#define HS_MMC_SD_ADMAES_LME_ERR                                        (1U)

#define HS_MMC_SD_PSTATE_CMDI_SHIFT                                    (0U)
#define HS_MMC_SD_PSTATE_CMDI_MASK                                     (0x00000001U)
#define HS_MMC_SD_PSTATE_CMDI_NOT_ALLOWED                               (1U)
#define HS_MMC_SD_PSTATE_CMDI_ALLOWED                                   (0U)

#define HS_MMC_SD_PSTATE_DATI_SHIFT                                    (1U)
#define HS_MMC_SD_PSTATE_DATI_MASK                                     (0x00000002U)
#define HS_MMC_SD_PSTATE_DATI_NOT_ALLOWED                               (1U)
#define HS_MMC_SD_PSTATE_DATI_ALLOWED                                   (0U)

#define HS_MMC_SD_PSTATE_DLA_SHIFT                                     (2U)
#define HS_MMC_SD_PSTATE_DLA_MASK                                      (0x00000004U)
#define HS_MMC_SD_PSTATE_DLA_ACTIVE                                     (1U)
#define HS_MMC_SD_PSTATE_DLA_INACTIVE                                   (0U)

#define HS_MMC_SD_PSTATE_WTA_SHIFT                                     (8U)
#define HS_MMC_SD_PSTATE_WTA_MASK                                      (0x00000100U)
#define HS_MMC_SD_PSTATE_WTA_ONGOING                                    (1U)
#define HS_MMC_SD_PSTATE_WTA_NO_VALID_DATA                              (0U)

#define HS_MMC_SD_PSTATE_RTA_SHIFT                                     (9U)
#define HS_MMC_SD_PSTATE_RTA_MASK                                      (0x00000200U)
#define HS_MMC_SD_PSTATE_RTA_NO_VALID_DATA                              (0U)
#define HS_MMC_SD_PSTATE_RTA_ONGOING                                    (1U)

#define HS_MMC_SD_PSTATE_BWE_SHIFT                                     (10U)
#define HS_MMC_SD_PSTATE_BWE_MASK                                      (0x00000400U)
#define HS_MMC_SD_PSTATE_BWE_SPACE                                      (1U)
#define HS_MMC_SD_PSTATE_BWE_NO_ROOM                                    (0U)

#define HS_MMC_SD_PSTATE_BRE_SHIFT                                     (11U)
#define HS_MMC_SD_PSTATE_BRE_MASK                                      (0x00000800U)
#define HS_MMC_SD_PSTATE_BRE_ENABLE                                     (1U)
#define HS_MMC_SD_PSTATE_BRE_DISABLE                                    (0U)

#define HS_MMC_SD_PSTATE_CINS_SHIFT                                    (16U)
#define HS_MMC_SD_PSTATE_CINS_MASK                                     (0x00010000U)
#define HS_MMC_SD_PSTATE_CINS_NO_CARD_DETECT                            (0U)
#define HS_MMC_SD_PSTATE_CINS_CARD_DETECT                               (1U)

#define HS_MMC_SD_PSTATE_CSS_SHIFT                                     (17U)
#define HS_MMC_SD_PSTATE_CSS_MASK                                      (0x00020000U)
#define HS_MMC_SD_PSTATE_CSS_RESET0                                     (0U)
#define HS_MMC_SD_PSTATE_CSS_RESET1                                     (1U)

#define HS_MMC_SD_PSTATE_CDPL_SHIFT                                    (18U)
#define HS_MMC_SD_PSTATE_CDPL_MASK                                     (0x00040000U)
#define HS_MMC_SD_PSTATE_CDPL_VAL0                                      (1U)
#define HS_MMC_SD_PSTATE_CDPL_VAL1                                      (0U)

#define HS_MMC_SD_PSTATE_WP_SHIFT                                      (19U)
#define HS_MMC_SD_PSTATE_WP_MASK                                       (0x00080000U)
#define HS_MMC_SD_PSTATE_WP_WRITEPROT                                   (0U)
#define HS_MMC_SD_PSTATE_WP_NO_WRITEPROT                                (1U)

#define HS_MMC_SD_PSTATE_DLEV_SHIFT                                    (20U)
#define HS_MMC_SD_PSTATE_DLEV_MASK                                     (0x00f00000U)

#define HS_MMC_SD_PSTATE_CLEV_SHIFT                                    (24U)
#define HS_MMC_SD_PSTATE_CLEV_MASK                                     (0x01000000U)
#define HS_MMC_SD_PSTATE_CLEV_LEVEL0                                    (0U)
#define HS_MMC_SD_PSTATE_CLEV_LEVEL1                                    (1U)

#define HS_MMC_SD_ADMASAH_ADMA_A32B_SHIFT                              (0U)
#define HS_MMC_SD_ADMASAH_ADMA_A32B_MASK                               (0xffffffffU)

#define HS_MMC_SD_FE_ACNE_SHIFT                                        (0U)
#define HS_MMC_SD_FE_ACNE_MASK                                         (0x00000001U)
#define HS_MMC_SD_FE_ACNE_INT                                           (1U)
#define HS_MMC_SD_FE_ACNE_NO_INT                                        (0U)

#define HS_MMC_SD_FE_ACTO_SHIFT                                        (1U)
#define HS_MMC_SD_FE_ACTO_MASK                                         (0x00000002U)
#define HS_MMC_SD_FE_ACTO_INT                                           (1U)
#define HS_MMC_SD_FE_ACTO_NO_INT                                        (0U)

#define HS_MMC_SD_FE_ACCE_SHIFT                                        (2U)
#define HS_MMC_SD_FE_ACCE_MASK                                         (0x00000004U)
#define HS_MMC_SD_FE_ACCE_INT                                           (1U)
#define HS_MMC_SD_FE_ACCE_NO_INT                                        (0U)

#define HS_MMC_SD_FE_ACEB_SHIFT                                        (3U)
#define HS_MMC_SD_FE_ACEB_MASK                                         (0x00000008U)
#define HS_MMC_SD_FE_ACEB_INT                                           (1U)
#define HS_MMC_SD_FE_ACEB_NO_INT                                        (0U)

#define HS_MMC_SD_FE_ACIE_SHIFT                                        (4U)
#define HS_MMC_SD_FE_ACIE_MASK                                         (0x00000010U)
#define HS_MMC_SD_FE_ACIE_INT                                           (1U)
#define HS_MMC_SD_FE_ACIE_NO_INT                                        (0U)

#define HS_MMC_SD_FE_CNI_SHIFT                                         (7U)
#define HS_MMC_SD_FE_CNI_MASK                                          (0x00000080U)
#define HS_MMC_SD_FE_CNI_INT                                            (1U)
#define HS_MMC_SD_FE_CNI_NO_INT                                         (0U)

#define HS_MMC_SD_FE_CTO_SHIFT                                         (16U)
#define HS_MMC_SD_FE_CTO_MASK                                          (0x00010000U)
#define HS_MMC_SD_FE_CTO_INT                                            (1U)
#define HS_MMC_SD_FE_CTO_NO_INT                                         (0U)

#define HS_MMC_SD_FE_CCRC_SHIFT                                        (17U)
#define HS_MMC_SD_FE_CCRC_MASK                                         (0x00020000U)
#define HS_MMC_SD_FE_CCRC_INT                                           (1U)
#define HS_MMC_SD_FE_CCRC_NO_INT                                        (0U)

#define HS_MMC_SD_FE_CEB_SHIFT                                         (18U)
#define HS_MMC_SD_FE_CEB_MASK                                          (0x00040000U)
#define HS_MMC_SD_FE_CEB_INT                                            (1U)
#define HS_MMC_SD_FE_CEB_NO_INT                                         (0U)

#define HS_MMC_SD_FE_CIE_SHIFT                                         (19U)
#define HS_MMC_SD_FE_CIE_MASK                                          (0x00080000U)
#define HS_MMC_SD_FE_CIE_INT                                            (1U)
#define HS_MMC_SD_FE_CIE_NO_INT                                         (0U)

#define HS_MMC_SD_FE_DTO_SHIFT                                         (20U)
#define HS_MMC_SD_FE_DTO_MASK                                          (0x00100000U)
#define HS_MMC_SD_FE_DTO_INT                                            (1U)
#define HS_MMC_SD_FE_DTO_NO_INT                                         (0U)

#define HS_MMC_SD_FE_DCRC_SHIFT                                        (21U)
#define HS_MMC_SD_FE_DCRC_MASK                                         (0x00200000U)
#define HS_MMC_SD_FE_DCRC_INT                                           (1U)
#define HS_MMC_SD_FE_DCRC_NO_INT                                        (0U)

#define HS_MMC_SD_FE_DEB_SHIFT                                         (22U)
#define HS_MMC_SD_FE_DEB_MASK                                          (0x00400000U)
#define HS_MMC_SD_FE_DEB_INT                                            (1U)
#define HS_MMC_SD_FE_DEB_NO_INT                                         (0U)

#define HS_MMC_SD_FE_ACE_SHIFT                                         (24U)
#define HS_MMC_SD_FE_ACE_MASK                                          (0x01000000U)
#define HS_MMC_SD_FE_ACE_INT                                            (1U)
#define HS_MMC_SD_FE_ACE_NO_INT                                         (0U)

#define HS_MMC_SD_FE_ADMAE_SHIFT                                       (25U)
#define HS_MMC_SD_FE_ADMAE_MASK                                        (0x02000000U)
#define HS_MMC_SD_FE_ADMAE_INT                                          (1U)
#define HS_MMC_SD_FE_ADMAE_NO_INT                                       (0U)

#define HS_MMC_SD_FE_CERR_SHIFT                                        (28U)
#define HS_MMC_SD_FE_CERR_MASK                                         (0x10000000U)
#define HS_MMC_SD_FE_CERR_INT                                           (1U)
#define HS_MMC_SD_FE_CERR_NO_INT                                        (0U)

#define HS_MMC_SD_FE_BADA_SHIFT                                        (29U)
#define HS_MMC_SD_FE_BADA_MASK                                         (0x20000000U)
#define HS_MMC_SD_FE_BADA_INT                                           (1U)
#define HS_MMC_SD_FE_BADA_NO_INT                                        (0U)

#define HS_MMC_SD_RSP76_RSP6_SHIFT                                     (0U)
#define HS_MMC_SD_RSP76_RSP6_MASK                                      (0x0000ffffU)

#define HS_MMC_SD_RSP76_RSP7_SHIFT                                     (16U)
#define HS_MMC_SD_RSP76_RSP7_MASK                                      (0xffff0000U)

#define HS_MMC_SD_RSP54_RSP4_SHIFT                                     (0U)
#define HS_MMC_SD_RSP54_RSP4_MASK                                      (0x0000ffffU)

#define HS_MMC_SD_RSP54_RSP5_SHIFT                                     (16U)
#define HS_MMC_SD_RSP54_RSP5_MASK                                      (0xffff0000U)

#define HS_MMC_SD_SYSCONFIG_AUTOIDLE_SHIFT                             (0U)
#define HS_MMC_SD_SYSCONFIG_AUTOIDLE_MASK                              (0x00000001U)
#define HS_MMC_SD_SYSCONFIG_AUTOIDLE_GATING                             (1U)
#define HS_MMC_SD_SYSCONFIG_AUTOIDLE_FREE_RUN                           (0U)

#define HS_MMC_SD_SYSCONFIG_SOFTRESET_SHIFT                            (1U)
#define HS_MMC_SD_SYSCONFIG_SOFTRESET_MASK                             (0x00000002U)
#define HS_MMC_SD_SYSCONFIG_SOFTRESET_NO_EFFECT                         (0U)
#define HS_MMC_SD_SYSCONFIG_SOFTRESET_RESET                             (1U)
#define HS_MMC_SD_SYSCONFIG_SOFTRESET_NORMAL                            (0U)
#define HS_MMC_SD_SYSCONFIG_SOFTRESET_TRIG_RST                          (1U)

#define HS_MMC_SD_SYSCONFIG_ENAWAKEUP_SHIFT                            (2U)
#define HS_MMC_SD_SYSCONFIG_ENAWAKEUP_MASK                             (0x00000004U)
#define HS_MMC_SD_SYSCONFIG_ENAWAKEUP_DISABLED                          (0U)
#define HS_MMC_SD_SYSCONFIG_ENAWAKEUP_ENABLED                           (1U)

#define HS_MMC_SD_SYSCONFIG_SIDLEMODE_SHIFT                            (3U)
#define HS_MMC_SD_SYSCONFIG_SIDLEMODE_MASK                             (0x00000018U)
#define HS_MMC_SD_SYSCONFIG_SIDLEMODE_RESERVED                          (3U)
#define HS_MMC_SD_SYSCONFIG_SIDLEMODE_UNCOND_ACK                        (0U)
#define HS_MMC_SD_SYSCONFIG_SIDLEMODE_WAKE_UP                           (2U)
#define HS_MMC_SD_SYSCONFIG_SIDLEMODE_IGNORE                            (1U)

#define HS_MMC_SD_SYSCONFIG_CLOCKACTIVITY_SHIFT                        (8U)
#define HS_MMC_SD_SYSCONFIG_CLOCKACTIVITY_MASK                         (0x00000300U)
#define HS_MMC_SD_SYSCONFIG_CLOCKACTIVITY_INF_ON_FUNC_OFF               (1U)
#define HS_MMC_SD_SYSCONFIG_CLOCKACTIVITY_FUNC_ON_INF_OFF               (2U)
#define HS_MMC_SD_SYSCONFIG_CLOCKACTIVITY_BOTH_OFF                      (0U)
#define HS_MMC_SD_SYSCONFIG_CLOCKACTIVITY_BOTH_ON                       (3U)

#define HS_MMC_SD_SYSCONFIG_STANDBYMODE_SHIFT                          (12U)
#define HS_MMC_SD_SYSCONFIG_STANDBYMODE_MASK                           (0x00003000U)
#define HS_MMC_SD_SYSCONFIG_STANDBYMODE_NO_STANDBY                      (1U)
#define HS_MMC_SD_SYSCONFIG_STANDBYMODE_FORCE_STANDBY                   (0U)
#define HS_MMC_SD_SYSCONFIG_STANDBYMODE_SMART_STANDBY                   (2U)
#define HS_MMC_SD_SYSCONFIG_STANDBYMODE_SMART_STANDBY_WU                (3U)

#define HS_MMC_SD_CAPA_TCF_SHIFT                                       (0U)
#define HS_MMC_SD_CAPA_TCF_MASK                                        (0x0000003fU)
#define HS_MMC_SD_CAPA_TCF_FREQ_DEPEND                                  (0U)

#define HS_MMC_SD_CAPA_TCU_SHIFT                                       (7U)
#define HS_MMC_SD_CAPA_TCU_MASK                                        (0x00000080U)
#define HS_MMC_SD_CAPA_TCU_MHZ                                          (1U)
#define HS_MMC_SD_CAPA_TCU_KHZ                                          (0U)

#define HS_MMC_SD_CAPA_BCF_SHIFT                                       (8U)
#define HS_MMC_SD_CAPA_BCF_MASK                                        (0x00003f00U)

#define HS_MMC_SD_CAPA_MBL_SHIFT                                       (16U)
#define HS_MMC_SD_CAPA_MBL_MASK                                        (0x00030000U)
#define HS_MMC_SD_CAPA_MBL_LEN_1024                                     (1U)
#define HS_MMC_SD_CAPA_MBL_LEN_512                                      (0U)
#define HS_MMC_SD_CAPA_MBL_LEN_2048                                     (2U)

#define HS_MMC_SD_CAPA_AD2S_SHIFT                                      (19U)
#define HS_MMC_SD_CAPA_AD2S_MASK                                       (0x00080000U)
#define HS_MMC_SD_CAPA_AD2S_SUPPORT                                     (0U)
#define HS_MMC_SD_CAPA_AD2S_NO_SUPPORT                                  (1U)

#define HS_MMC_SD_CAPA_HSS_SHIFT                                       (21U)
#define HS_MMC_SD_CAPA_HSS_MASK                                        (0x00200000U)
#define HS_MMC_SD_CAPA_HSS_NO_SUPPORT                                   (0U)
#define HS_MMC_SD_CAPA_HSS_SUPPORT                                      (1U)

#define HS_MMC_SD_CAPA_DS_SHIFT                                        (22U)
#define HS_MMC_SD_CAPA_DS_MASK                                         (0x00400000U)
#define HS_MMC_SD_CAPA_DS_NO_SUPPORT                                    (0U)
#define HS_MMC_SD_CAPA_DS_SUPPORT                                       (1U)

#define HS_MMC_SD_CAPA_SRS_SHIFT                                       (23U)
#define HS_MMC_SD_CAPA_SRS_MASK                                        (0x00800000U)
#define HS_MMC_SD_CAPA_SRS_NO_SUPPORT                                   (0U)
#define HS_MMC_SD_CAPA_SRS_SUPPORT                                      (1U)

#define HS_MMC_SD_CAPA_VS33_SHIFT                                      (24U)
#define HS_MMC_SD_CAPA_VS33_MASK                                       (0x01000000U)
#define HS_MMC_SD_CAPA_VS33_SUPPORT_33W                                 (1U)
#define HS_MMC_SD_CAPA_VS33_SUPPORT_33R                                 (1U)
#define HS_MMC_SD_CAPA_VS33_NO_SUPPORT_33W                              (0U)
#define HS_MMC_SD_CAPA_VS33_NO_SUPPORT_33R                              (0U)

#define HS_MMC_SD_CAPA_VS30_SHIFT                                      (25U)
#define HS_MMC_SD_CAPA_VS30_MASK                                       (0x02000000U)
#define HS_MMC_SD_CAPA_VS30_NO_SUPPORT_30W                              (0U)
#define HS_MMC_SD_CAPA_VS30_SUPPORT_30W                                 (1U)
#define HS_MMC_SD_CAPA_VS30_NO_SUPPORT_30R                              (0U)
#define HS_MMC_SD_CAPA_VS30_SUPPORT_30R                                 (1U)

#define HS_MMC_SD_CAPA_VS18_SHIFT                                      (26U)
#define HS_MMC_SD_CAPA_VS18_MASK                                       (0x04000000U)
#define HS_MMC_SD_CAPA_VS18_SUPPORT_18W                                 (1U)
#define HS_MMC_SD_CAPA_VS18_NO_SUPPORT_18W                              (0U)
#define HS_MMC_SD_CAPA_VS18_NO_SUPPORT_18R                              (0U)
#define HS_MMC_SD_CAPA_VS18_SUPPORT_18R                                 (1U)

#define HS_MMC_SD_CAPA_BUS_64BIT_SHIFT                                 (28U)
#define HS_MMC_SD_CAPA_BUS_64BIT_MASK                                  (0x10000000U)
#define HS_MMC_SD_CAPA_BUS_64BIT_BUS64                                  (1U)
#define HS_MMC_SD_CAPA_BUS_64BIT_BUS32                                  (0U)

#define HS_MMC_SD_HCTL_DTW_SHIFT                                       (1U)
#define HS_MMC_SD_HCTL_DTW_MASK                                        (0x00000002U)
#define HS_MMC_SD_HCTL_DTW_WIDTH_1BIT                                   (0U)
#define HS_MMC_SD_HCTL_DTW_WIDTH_4BIT                                   (1U)

#define HS_MMC_SD_HCTL_HSPE_SHIFT                                      (2U)
#define HS_MMC_SD_HCTL_HSPE_MASK                                       (0x00000004U)
#define HS_MMC_SD_HCTL_HSPE_HIGH_SPEED                                  (1U)
#define HS_MMC_SD_HCTL_HSPE_NORMAL_SPEED                                (0U)

#define HS_MMC_SD_HCTL_DMAS_SHIFT                                      (3U)
#define HS_MMC_SD_HCTL_DMAS_MASK                                       (0x00000018U)
#define HS_MMC_SD_HCTL_DMAS_RESERVED3                                   (3U)
#define HS_MMC_SD_HCTL_DMAS_RESERVED1                                   (0U)
#define HS_MMC_SD_HCTL_DMAS_RESERVED2                                   (1U)
#define HS_MMC_SD_HCTL_DMAS_ADD_32BIT                                   (2U)

#define HS_MMC_SD_HCTL_CDTL_SHIFT                                      (6U)
#define HS_MMC_SD_HCTL_CDTL_MASK                                       (0x00000040U)

#define HS_MMC_SD_HCTL_CDSS_SHIFT                                      (7U)
#define HS_MMC_SD_HCTL_CDSS_MASK                                       (0x00000080U)
#define HS_MMC_SD_HCTL_CDSS_NORMAL                                      (0U)
#define HS_MMC_SD_HCTL_CDSS_TEST                                        (1U)

#define HS_MMC_SD_HCTL_SDBP_SHIFT                                      (8U)
#define HS_MMC_SD_HCTL_SDBP_MASK                                       (0x00000100U)
#define HS_MMC_SD_HCTL_SDBP_PWR_ON                                      (1U)
#define HS_MMC_SD_HCTL_SDBP_PWR_OFF                                     (0U)

#define HS_MMC_SD_HCTL_SDVS_SHIFT                                      (9U)
#define HS_MMC_SD_HCTL_SDVS_MASK                                       (0x00000e00U)
#define HS_MMC_SD_HCTL_SDVS_V33                                         (7U)
#define HS_MMC_SD_HCTL_SDVS_V30                                         (6U)
#define HS_MMC_SD_HCTL_SDVS_V18                                         (5U)

#define HS_MMC_SD_HCTL_SBGR_SHIFT                                      (16U)
#define HS_MMC_SD_HCTL_SBGR_MASK                                       (0x00010000U)
#define HS_MMC_SD_HCTL_SBGR_STOP                                        (1U)
#define HS_MMC_SD_HCTL_SBGR_TRANSFER                                    (0U)

#define HS_MMC_SD_HCTL_CR_SHIFT                                        (17U)
#define HS_MMC_SD_HCTL_CR_MASK                                         (0x00020000U)
#define HS_MMC_SD_HCTL_CR_NO_EFFECT                                     (0U)
#define HS_MMC_SD_HCTL_CR_TRANSFER_RESTART                              (1U)

#define HS_MMC_SD_HCTL_RWC_SHIFT                                       (18U)
#define HS_MMC_SD_HCTL_RWC_MASK                                        (0x00040000U)
#define HS_MMC_SD_HCTL_RWC_DISABLE                                      (0U)
#define HS_MMC_SD_HCTL_RWC_ENABLE                                       (1U)

#define HS_MMC_SD_HCTL_IBG_SHIFT                                       (19U)
#define HS_MMC_SD_HCTL_IBG_MASK                                        (0x00080000U)
#define HS_MMC_SD_HCTL_IBG_ENABLE                                       (1U)
#define HS_MMC_SD_HCTL_IBG_DISABLE                                      (0U)

#define HS_MMC_SD_HCTL_IWE_SHIFT                                       (24U)
#define HS_MMC_SD_HCTL_IWE_MASK                                        (0x01000000U)
#define HS_MMC_SD_HCTL_IWE_DISABLE                                      (0U)
#define HS_MMC_SD_HCTL_IWE_ENABLE                                       (1U)

#define HS_MMC_SD_HCTL_INS_SHIFT                                       (25U)
#define HS_MMC_SD_HCTL_INS_MASK                                        (0x02000000U)
#define HS_MMC_SD_HCTL_INS_DISABLE                                      (0U)
#define HS_MMC_SD_HCTL_INS_ENABLE                                       (1U)

#define HS_MMC_SD_HCTL_REM_SHIFT                                       (26U)
#define HS_MMC_SD_HCTL_REM_MASK                                        (0x04000000U)
#define HS_MMC_SD_HCTL_REM_ENABLE                                       (1U)
#define HS_MMC_SD_HCTL_REM_DISABLE                                      (0U)

#define HS_MMC_SD_HCTL_OBWE_SHIFT                                      (27U)
#define HS_MMC_SD_HCTL_OBWE_MASK                                       (0x08000000U)
#define HS_MMC_SD_HCTL_OBWE_ENABLE                                      (1U)
#define HS_MMC_SD_HCTL_OBWE_DISABLE                                     (0U)

#define HS_MMC_SD_SYSTEST_MCKD_SHIFT                                   (0U)
#define HS_MMC_SD_SYSTEST_MCKD_MASK                                    (0x00000001U)
#define HS_MMC_SD_SYSTEST_MCKD_RET0                                     (0U)
#define HS_MMC_SD_SYSTEST_MCKD_RET1                                     (1U)
#define HS_MMC_SD_SYSTEST_MCKD_HIGH                                     (1U)
#define HS_MMC_SD_SYSTEST_MCKD_LOW                                      (0U)

#define HS_MMC_SD_SYSTEST_CDIR_SHIFT                                   (1U)
#define HS_MMC_SD_SYSTEST_CDIR_MASK                                    (0x00000002U)
#define HS_MMC_SD_SYSTEST_CDIR_RET0                                     (0U)
#define HS_MMC_SD_SYSTEST_CDIR_RET1                                     (1U)
#define HS_MMC_SD_SYSTEST_CDIR_OUTPUT                                   (0U)
#define HS_MMC_SD_SYSTEST_CDIR_INPUT                                    (1U)

#define HS_MMC_SD_SYSTEST_CDAT_SHIFT                                   (2U)
#define HS_MMC_SD_SYSTEST_CDAT_MASK                                    (0x00000004U)
#define HS_MMC_SD_SYSTEST_CDAT_OUTPUT_MODE_CMD_HIGH_W                   (1U)
#define HS_MMC_SD_SYSTEST_CDAT_INPUT_MODE_CMD_LOW_R                     (0U)
#define HS_MMC_SD_SYSTEST_CDAT_OUTPUT_MODE_CMD_LOW_W                    (0U)
#define HS_MMC_SD_SYSTEST_CDAT_INPUT_MODE_CMD_HIGH_R                    (1U)

#define HS_MMC_SD_SYSTEST_DDIR_SHIFT                                   (3U)
#define HS_MMC_SD_SYSTEST_DDIR_MASK                                    (0x00000008U)
#define HS_MMC_SD_SYSTEST_DDIR_RET0                                     (0U)
#define HS_MMC_SD_SYSTEST_DDIR_RET1                                     (1U)
#define HS_MMC_SD_SYSTEST_DDIR_OUTPUT                                   (0U)
#define HS_MMC_SD_SYSTEST_DDIR_INPUT                                    (1U)

#define HS_MMC_SD_SYSTEST_D0D_SHIFT                                    (4U)
#define HS_MMC_SD_SYSTEST_D0D_MASK                                     (0x00000010U)
#define HS_MMC_SD_SYSTEST_D0D_INPUT_MODE_DAT0_HIGH_R                    (1U)
#define HS_MMC_SD_SYSTEST_D0D_OUTPUT_MODE_DAT0_HIGH_W                   (1U)
#define HS_MMC_SD_SYSTEST_D0D_OUTPUT_MODE_DAT0_LOW_W                    (0U)
#define HS_MMC_SD_SYSTEST_D0D_INPUT_MODE_DAT0_LOW_R                     (0U)

#define HS_MMC_SD_SYSTEST_D1D_SHIFT                                    (5U)
#define HS_MMC_SD_SYSTEST_D1D_MASK                                     (0x00000020U)
#define HS_MMC_SD_SYSTEST_D1D_INPUT_MODE_DAT1_LOW_R                     (0U)
#define HS_MMC_SD_SYSTEST_D1D_OUTPUT_MODE_DAT1_HIGH_W                   (1U)
#define HS_MMC_SD_SYSTEST_D1D_OUTPUT_MODE_DAT1_LOW_W                    (0U)
#define HS_MMC_SD_SYSTEST_D1D_INPUT_MODE_DAT1_HIGH_R                    (1U)

#define HS_MMC_SD_SYSTEST_D2D_SHIFT                                    (6U)
#define HS_MMC_SD_SYSTEST_D2D_MASK                                     (0x00000040U)
#define HS_MMC_SD_SYSTEST_D2D_OUTPUT_MODE_DAT2_HIGH_W                   (1U)
#define HS_MMC_SD_SYSTEST_D2D_INPUT_MODE_DAT2_HIGH_R                    (1U)
#define HS_MMC_SD_SYSTEST_D2D_INPUT_MODE_DAT2_LOW_R                     (0U)
#define HS_MMC_SD_SYSTEST_D2D_OUTPUT_MODE_DAT2_LOW_W                    (0U)

#define HS_MMC_SD_SYSTEST_D3D_SHIFT                                    (7U)
#define HS_MMC_SD_SYSTEST_D3D_MASK                                     (0x00000080U)
#define HS_MMC_SD_SYSTEST_D3D_OUTPUT_MODE_DAT3_LOW_W                    (0U)
#define HS_MMC_SD_SYSTEST_D3D_INPUT_MODE_DAT3_HIGH_R                    (1U)
#define HS_MMC_SD_SYSTEST_D3D_OUTPUT_MODE_DAT3_HIGH_W                   (1U)
#define HS_MMC_SD_SYSTEST_D3D_INPUT_MODE_DAT3_LOW_R                     (0U)

#define HS_MMC_SD_SYSTEST_D4D_SHIFT                                    (8U)
#define HS_MMC_SD_SYSTEST_D4D_MASK                                     (0x00000100U)
#define HS_MMC_SD_SYSTEST_D4D_OUTPUT_MODE_DAT4_LOW_W                    (0U)
#define HS_MMC_SD_SYSTEST_D4D_INPUT_MODE_DAT4_LOW_R                     (0U)
#define HS_MMC_SD_SYSTEST_D4D_OUTPUT_MODE_DAT4_HIGH_W                   (1U)
#define HS_MMC_SD_SYSTEST_D4D_INPUT_MODE_DAT4_HIGH_R                    (1U)

#define HS_MMC_SD_SYSTEST_D5D_SHIFT                                    (9U)
#define HS_MMC_SD_SYSTEST_D5D_MASK                                     (0x00000200U)
#define HS_MMC_SD_SYSTEST_D5D_INPUT_MODE_DAT5_LOW_R                     (0U)
#define HS_MMC_SD_SYSTEST_D5D_OUTPUT_MODE_DAT5_LOW_W                    (0U)
#define HS_MMC_SD_SYSTEST_D5D_INPUT_MODE_DAT5_HIGH_R                    (1U)
#define HS_MMC_SD_SYSTEST_D5D_OUTPUT_MODE_DAT5_HIGH_W                   (1U)

#define HS_MMC_SD_SYSTEST_D6D_SHIFT                                    (10U)
#define HS_MMC_SD_SYSTEST_D6D_MASK                                     (0x00000400U)
#define HS_MMC_SD_SYSTEST_D6D_INPUT_MODE_DAT6_LOW_R                     (0U)
#define HS_MMC_SD_SYSTEST_D6D_OUTPUT_MODE_DAT6_HIGH_W                   (1U)
#define HS_MMC_SD_SYSTEST_D6D_OUTPUT_MODE_DAT6_LOW_W                    (0U)
#define HS_MMC_SD_SYSTEST_D6D_INPUT_MODE_DAT6_HIGH_R                    (1U)

#define HS_MMC_SD_SYSTEST_D7D_SHIFT                                    (11U)
#define HS_MMC_SD_SYSTEST_D7D_MASK                                     (0x00000800U)
#define HS_MMC_SD_SYSTEST_D7D_INPUT_MODE_DAT7_LOW_R                     (0U)
#define HS_MMC_SD_SYSTEST_D7D_OUTPUT_MODE_DAT7_HIGH_W                   (1U)
#define HS_MMC_SD_SYSTEST_D7D_INPUT_MODE_DAT7_HIGH_R                    (1U)
#define HS_MMC_SD_SYSTEST_D7D_OUTPUT_MODE_DAT7_LOW_W                    (0U)

#define HS_MMC_SD_SYSTEST_SSB_SHIFT                                    (12U)
#define HS_MMC_SD_SYSTEST_SSB_MASK                                     (0x00001000U)
#define HS_MMC_SD_SYSTEST_SSB_RET0                                      (0U)
#define HS_MMC_SD_SYSTEST_SSB_RET1                                      (1U)
#define HS_MMC_SD_SYSTEST_SSB_CLR                                       (0U)
#define HS_MMC_SD_SYSTEST_SSB_FORCE_1                                   (1U)

#define HS_MMC_SD_SYSTEST_WAKD_SHIFT                                   (13U)
#define HS_MMC_SD_SYSTEST_WAKD_MASK                                    (0x00002000U)
#define HS_MMC_SD_SYSTEST_WAKD_RET0                                     (0U)
#define HS_MMC_SD_SYSTEST_WAKD_LOW                                      (0U)
#define HS_MMC_SD_SYSTEST_WAKD_RET1                                     (1U)
#define HS_MMC_SD_SYSTEST_WAKD_HIGH                                     (1U)

#define HS_MMC_SD_SYSTEST_SDWP_SHIFT                                   (14U)
#define HS_MMC_SD_SYSTEST_SDWP_MASK                                    (0x00004000U)
#define HS_MMC_SD_SYSTEST_SDWP_HIGH                                     (1U)
#define HS_MMC_SD_SYSTEST_SDWP_LOW                                      (0U)

#define HS_MMC_SD_SYSTEST_SDCD_SHIFT                                   (15U)
#define HS_MMC_SD_SYSTEST_SDCD_MASK                                    (0x00008000U)
#define HS_MMC_SD_SYSTEST_SDCD_LOW                                      (0U)
#define HS_MMC_SD_SYSTEST_SDCD_HIGH                                     (1U)

#define HS_MMC_SD_SYSTEST_OBI_SHIFT                                    (16U)
#define HS_MMC_SD_SYSTEST_OBI_MASK                                     (0x00010000U)
#define HS_MMC_SD_SYSTEST_OBI_HIGH                                      (1U)
#define HS_MMC_SD_SYSTEST_OBI_LOW                                       (0U)

#define HS_MMC_SD_DATA_SHIFT                                           (0U)
#define HS_MMC_SD_DATA_MASK                                            (0xffffffffU)

#define HS_MMC_SD_AC12_ACNE_SHIFT                                      (0U)
#define HS_MMC_SD_AC12_ACNE_MASK                                       (0x00000001U)
#define HS_MMC_SD_AC12_ACNE_EXECUTED                                    (0U)
#define HS_MMC_SD_AC12_ACNE_NOT_EXECUTED                                (1U)

#define HS_MMC_SD_AC12_ACTO_SHIFT                                      (1U)
#define HS_MMC_SD_AC12_ACTO_MASK                                       (0x00000002U)
#define HS_MMC_SD_AC12_ACTO_NO_ERR                                      (0U)
#define HS_MMC_SD_AC12_ACTO_ERR                                         (1U)

#define HS_MMC_SD_AC12_ACCE_SHIFT                                      (2U)
#define HS_MMC_SD_AC12_ACCE_MASK                                       (0x00000004U)
#define HS_MMC_SD_AC12_ACCE_NO_ERR                                      (0U)
#define HS_MMC_SD_AC12_ACCE_ERR                                         (1U)

#define HS_MMC_SD_AC12_ACEB_SHIFT                                      (3U)
#define HS_MMC_SD_AC12_ACEB_MASK                                       (0x00000008U)
#define HS_MMC_SD_AC12_ACEB_ERR                                         (1U)
#define HS_MMC_SD_AC12_ACEB_NO_ERR                                      (0U)

#define HS_MMC_SD_AC12_ACIE_SHIFT                                      (4U)
#define HS_MMC_SD_AC12_ACIE_MASK                                       (0x00000010U)
#define HS_MMC_SD_AC12_ACIE_ERR                                         (1U)
#define HS_MMC_SD_AC12_ACIE_NO_ERR                                      (0U)

#define HS_MMC_SD_AC12_CNI_SHIFT                                       (7U)
#define HS_MMC_SD_AC12_CNI_MASK                                        (0x00000080U)
#define HS_MMC_SD_AC12_CNI_ERR                                          (1U)
#define HS_MMC_SD_AC12_CNI_NO_ERR                                       (0U)

#define HS_MMC_SD_ADMASAL_ADMA_A32B_SHIFT                              (0U)
#define HS_MMC_SD_ADMASAL_ADMA_A32B_MASK                               (0xffffffffU)

#define HS_MMC_SD_ISE_CC_SIGEN_SHIFT                                   (0U)
#define HS_MMC_SD_ISE_CC_SIGEN_MASK                                    (0x00000001U)
#define HS_MMC_SD_ISE_CC_SIGEN_ENABLED                                  (1U)
#define HS_MMC_SD_ISE_CC_SIGEN_MASKED                                   (0U)

#define HS_MMC_SD_ISE_TC_SIGEN_SHIFT                                   (1U)
#define HS_MMC_SD_ISE_TC_SIGEN_MASK                                    (0x00000002U)
#define HS_MMC_SD_ISE_TC_SIGEN_ENABLED                                  (1U)
#define HS_MMC_SD_ISE_TC_SIGEN_MASKED                                   (0U)

#define HS_MMC_SD_ISE_BGE_SIGEN_SHIFT                                  (2U)
#define HS_MMC_SD_ISE_BGE_SIGEN_MASK                                   (0x00000004U)
#define HS_MMC_SD_ISE_BGE_SIGEN_ENABLED                                 (1U)
#define HS_MMC_SD_ISE_BGE_SIGEN_MASKED                                  (0U)

#define HS_MMC_SD_ISE_DMA_SIGEN_SHIFT                                  (3U)
#define HS_MMC_SD_ISE_DMA_SIGEN_MASK                                   (0x00000008U)
#define HS_MMC_SD_ISE_DMA_SIGEN_ENABLED                                 (1U)
#define HS_MMC_SD_ISE_DMA_SIGEN_MASKED                                  (0U)

#define HS_MMC_SD_ISE_BWR_SIGEN_SHIFT                                  (4U)
#define HS_MMC_SD_ISE_BWR_SIGEN_MASK                                   (0x00000010U)
#define HS_MMC_SD_ISE_BWR_SIGEN_ENABLED                                 (1U)
#define HS_MMC_SD_ISE_BWR_SIGEN_MASKED                                  (0U)

#define HS_MMC_SD_ISE_BRR_SIGEN_SHIFT                                  (5U)
#define HS_MMC_SD_ISE_BRR_SIGEN_MASK                                   (0x00000020U)
#define HS_MMC_SD_ISE_BRR_SIGEN_ENABLED                                 (1U)
#define HS_MMC_SD_ISE_BRR_SIGEN_MASKED                                  (0U)

#define HS_MMC_SD_ISE_CINS_SIGEN_SHIFT                                 (6U)
#define HS_MMC_SD_ISE_CINS_SIGEN_MASK                                  (0x00000040U)
#define HS_MMC_SD_ISE_CINS_SIGEN_ENABLED                                (1U)
#define HS_MMC_SD_ISE_CINS_SIGEN_MASKED                                 (0U)

#define HS_MMC_SD_ISE_CREM_SIGEN_SHIFT                                 (7U)
#define HS_MMC_SD_ISE_CREM_SIGEN_MASK                                  (0x00000080U)
#define HS_MMC_SD_ISE_CREM_SIGEN_ENABLED                                (1U)
#define HS_MMC_SD_ISE_CREM_SIGEN_MASKED                                 (0U)

#define HS_MMC_SD_ISE_CIRQ_SIGEN_SHIFT                                 (8U)
#define HS_MMC_SD_ISE_CIRQ_SIGEN_MASK                                  (0x00000100U)
#define HS_MMC_SD_ISE_CIRQ_SIGEN_ENABLED                                (1U)
#define HS_MMC_SD_ISE_CIRQ_SIGEN_MASKED                                 (0U)

#define HS_MMC_SD_ISE_OBI_SIGEN_SHIFT                                  (9U)
#define HS_MMC_SD_ISE_OBI_SIGEN_MASK                                   (0x00000200U)
#define HS_MMC_SD_ISE_OBI_SIGEN_ENABLED                                 (1U)
#define HS_MMC_SD_ISE_OBI_SIGEN_MASKED                                  (0U)

#define HS_MMC_SD_ISE_BSR_SIGEN_SHIFT                                  (10U)
#define HS_MMC_SD_ISE_BSR_SIGEN_MASK                                   (0x00000400U)
#define HS_MMC_SD_ISE_BSR_SIGEN_ENABLED                                 (1U)
#define HS_MMC_SD_ISE_BSR_SIGEN_MASKED                                  (0U)

#define HS_MMC_SD_ISE_NULL_SHIFT                                       (15U)
#define HS_MMC_SD_ISE_NULL_MASK                                        (0x00008000U)

#define HS_MMC_SD_ISE_CTO_SIGEN_SHIFT                                  (16U)
#define HS_MMC_SD_ISE_CTO_SIGEN_MASK                                   (0x00010000U)
#define HS_MMC_SD_ISE_CTO_SIGEN_ENABLED                                 (1U)
#define HS_MMC_SD_ISE_CTO_SIGEN_MASKED                                  (0U)

#define HS_MMC_SD_ISE_CCRC_SIGEN_SHIFT                                 (17U)
#define HS_MMC_SD_ISE_CCRC_SIGEN_MASK                                  (0x00020000U)
#define HS_MMC_SD_ISE_CCRC_SIGEN_ENABLED                                (1U)
#define HS_MMC_SD_ISE_CCRC_SIGEN_MASKED                                 (0U)

#define HS_MMC_SD_ISE_CEB_SIGEN_SHIFT                                  (18U)
#define HS_MMC_SD_ISE_CEB_SIGEN_MASK                                   (0x00040000U)
#define HS_MMC_SD_ISE_CEB_SIGEN_ENABLED                                 (1U)
#define HS_MMC_SD_ISE_CEB_SIGEN_MASKED                                  (0U)

#define HS_MMC_SD_ISE_CIE_SIGEN_SHIFT                                  (19U)
#define HS_MMC_SD_ISE_CIE_SIGEN_MASK                                   (0x00080000U)
#define HS_MMC_SD_ISE_CIE_SIGEN_ENABLED                                 (1U)
#define HS_MMC_SD_ISE_CIE_SIGEN_MASKED                                  (0U)

#define HS_MMC_SD_ISE_DTO_SIGEN_SHIFT                                  (20U)
#define HS_MMC_SD_ISE_DTO_SIGEN_MASK                                   (0x00100000U)
#define HS_MMC_SD_ISE_DTO_SIGEN_MASKED                                  (0U)
#define HS_MMC_SD_ISE_DTO_SIGEN_ENABLED                                 (1U)

#define HS_MMC_SD_ISE_DCRC_SIGEN_SHIFT                                 (21U)
#define HS_MMC_SD_ISE_DCRC_SIGEN_MASK                                  (0x00200000U)
#define HS_MMC_SD_ISE_DCRC_SIGEN_ENABLED                                (1U)
#define HS_MMC_SD_ISE_DCRC_SIGEN_MASKED                                 (0U)

#define HS_MMC_SD_ISE_DEB_SIGEN_SHIFT                                  (22U)
#define HS_MMC_SD_ISE_DEB_SIGEN_MASK                                   (0x00400000U)
#define HS_MMC_SD_ISE_DEB_SIGEN_ENABLED                                 (1U)
#define HS_MMC_SD_ISE_DEB_SIGEN_MASKED                                  (0U)

#define HS_MMC_SD_ISE_ACE_SIGEN_SHIFT                                  (24U)
#define HS_MMC_SD_ISE_ACE_SIGEN_MASK                                   (0x01000000U)
#define HS_MMC_SD_ISE_ACE_SIGEN_ENABLED                                 (1U)
#define HS_MMC_SD_ISE_ACE_SIGEN_MASKED                                  (0U)

#define HS_MMC_SD_ISE_ADMA_SIGEN_SHIFT                                 (25U)
#define HS_MMC_SD_ISE_ADMA_SIGEN_MASK                                  (0x02000000U)
#define HS_MMC_SD_ISE_ADMA_SIGEN_ENABLED                                (1U)
#define HS_MMC_SD_ISE_ADMA_SIGEN_MASKED                                 (0U)

#define HS_MMC_SD_ISE_CERR_SIGEN_SHIFT                                 (28U)
#define HS_MMC_SD_ISE_CERR_SIGEN_MASK                                  (0x10000000U)
#define HS_MMC_SD_ISE_CERR_SIGEN_ENABLED                                (1U)
#define HS_MMC_SD_ISE_CERR_SIGEN_MASKED                                 (0U)

#define HS_MMC_SD_ISE_BADA_SIGEN_SHIFT                                 (29U)
#define HS_MMC_SD_ISE_BADA_SIGEN_MASK                                  (0x20000000U)
#define HS_MMC_SD_ISE_BADA_SIGEN_ENABLED                                (1U)
#define HS_MMC_SD_ISE_BADA_SIGEN_MASKED                                 (0U)

#define HS_MMC_SD_CMD_DE_SHIFT                                         (0U)
#define HS_MMC_SD_CMD_DE_MASK                                          (0x00000001U)
#define HS_MMC_SD_CMD_DE_DISABLE                                        (0U)
#define HS_MMC_SD_CMD_DE_ENABLE                                         (1U)

#define HS_MMC_SD_CMD_BCE_SHIFT                                        (1U)
#define HS_MMC_SD_CMD_BCE_MASK                                         (0x00000002U)
#define HS_MMC_SD_CMD_BCE_DISABLED                                      (0U)
#define HS_MMC_SD_CMD_BCE_ENABLED                                       (1U)

#define HS_MMC_SD_CMD_ACEN_SHIFT                                       (2U)
#define HS_MMC_SD_CMD_ACEN_MASK                                        (0x00000004U)
#define HS_MMC_SD_CMD_ACEN_ENABLED                                      (1U)
#define HS_MMC_SD_CMD_ACEN_DISABLED                                     (0U)

#define HS_MMC_SD_CMD_DDIR_SHIFT                                       (4U)
#define HS_MMC_SD_CMD_DDIR_MASK                                        (0x00000010U)
#define HS_MMC_SD_CMD_DDIR_WRITE                                        (0U)
#define HS_MMC_SD_CMD_DDIR_READ                                         (1U)

#define HS_MMC_SD_CMD_MSBS_SHIFT                                       (5U)
#define HS_MMC_SD_CMD_MSBS_MASK                                        (0x00000020U)
#define HS_MMC_SD_CMD_MSBS_MULTI_BLK                                    (1U)
#define HS_MMC_SD_CMD_MSBS_SINGLE_BLK                                   (0U)

#define HS_MMC_SD_CMD_RSP_TYPE_SHIFT                                   (16U)
#define HS_MMC_SD_CMD_RSP_TYPE_MASK                                    (0x00030000U)
#define HS_MMC_SD_CMD_RSP_TYPE_LEN_136                                  (1U)
#define HS_MMC_SD_CMD_RSP_TYPE_NORSP                                    (0U)
#define HS_MMC_SD_CMD_RSP_TYPE_LEN_48                                   (2U)
#define HS_MMC_SD_CMD_RSP_TYPE_LEN_48BUSY                               (3U)

#define HS_MMC_SD_CMD_CCCE_SHIFT                                       (19U)
#define HS_MMC_SD_CMD_CCCE_MASK                                        (0x00080000U)
#define HS_MMC_SD_CMD_CCCE_ENABLE                                       (1U)
#define HS_MMC_SD_CMD_CCCE_DISABLE                                      (0U)

#define HS_MMC_SD_CMD_CICE_SHIFT                                       (20U)
#define HS_MMC_SD_CMD_CICE_MASK                                        (0x00100000U)
#define HS_MMC_SD_CMD_CICE_DISABLE                                      (0U)
#define HS_MMC_SD_CMD_CICE_ENABLE                                       (1U)

#define HS_MMC_SD_CMD_DP_SHIFT                                         (21U)
#define HS_MMC_SD_CMD_DP_MASK                                          (0x00200000U)
#define HS_MMC_SD_CMD_DP_NO_TX                                          (0U)
#define HS_MMC_SD_CMD_DP_TX                                             (1U)

#define HS_MMC_SD_CMD_TYPE_SHIFT                                       (22U)
#define HS_MMC_SD_CMD_TYPE_MASK                                        (0x00c00000U)
#define HS_MMC_SD_CMD_TYPE_IO_ABORT                                     (3U)
#define HS_MMC_SD_CMD_TYPE_BUS_SUSP                                     (1U)
#define HS_MMC_SD_CMD_TYPE_FUNC_SEL                                     (2U)
#define HS_MMC_SD_CMD_TYPE_OTHER                                        (0U)

#define HS_MMC_SD_CMD_INDX_SHIFT                                       (24U)
#define HS_MMC_SD_CMD_INDX_MASK                                        (0x3f000000U)

#define HS_MMC_SD_CSRE_SHIFT                                           (0U)
#define HS_MMC_SD_CSRE_MASK                                            (0xffffffffU)

#define HS_MMC_SD_PWCNT_PWRCNT_SHIFT                                   (0U)
#define HS_MMC_SD_PWCNT_PWRCNT_MASK                                    (0x0000ffffU)
#define HS_MMC_SD_PWCNT_PWRCNT_TCF_DLY                                  (1U)
#define HS_MMC_SD_PWCNT_PWRCNT_TCF_65534_DLY                            (65534U)
#define HS_MMC_SD_PWCNT_PWRCNT_TCF_65535_DLY                            (65535U)
#define HS_MMC_SD_PWCNT_PWRCNT_TCF_2_DLY                                (2U)
#define HS_MMC_SD_PWCNT_PWRCNT_NO_DLY                                   (0U)

#define HS_MMC_SD_ARG_SHIFT                                            (0U)
#define HS_MMC_SD_ARG_MASK                                             (0xffffffffU)

#define HS_MMC_SD_REV_SIS_SHIFT                                        (0U)
#define HS_MMC_SD_REV_SIS_MASK                                         (0x00000001U)
#define HS_MMC_SD_REV_SIS_DEASSERTED                                    (0U)
#define HS_MMC_SD_REV_SIS_ASSERTED                                      (1U)

#define HS_MMC_SD_REV_SREV_SHIFT                                       (16U)
#define HS_MMC_SD_REV_SREV_MASK                                        (0x00ff0000U)
#define HS_MMC_SD_REV_SREV_VER1_0                                       (0U)

#define HS_MMC_SD_REV_VREV_SHIFT                                       (24U)
#define HS_MMC_SD_REV_VREV_MASK                                        (0xff000000U)

#define HS_MMC_SD_STAT_CC_SHIFT                                        (0U)
#define HS_MMC_SD_STAT_CC_MASK                                         (0x00000001U)
#define HS_MMC_SD_STAT_CC_UNCHANGED                                     (0U)
#define HS_MMC_SD_STAT_CC_COMPLETE                                      (1U)
#define HS_MMC_SD_STAT_CC_CLEARED                                       (1U)
#define HS_MMC_SD_STAT_CC_NOT_COMPLETE                                  (0U)

#define HS_MMC_SD_STAT_TC_SHIFT                                        (1U)
#define HS_MMC_SD_STAT_TC_MASK                                         (0x00000002U)
#define HS_MMC_SD_STAT_TC_NOT_COMPLETE                                  (0U)
#define HS_MMC_SD_STAT_TC_UNCHANGED                                     (0U)
#define HS_MMC_SD_STAT_TC_COMPLETE                                      (1U)
#define HS_MMC_SD_STAT_TC_CLEARED                                       (1U)

#define HS_MMC_SD_STAT_BGE_SHIFT                                       (2U)
#define HS_MMC_SD_STAT_BGE_MASK                                        (0x00000004U)
#define HS_MMC_SD_STAT_BGE_NO_BGEVT                                     (0U)
#define HS_MMC_SD_STAT_BGE_UNCHANGED                                    (0U)
#define HS_MMC_SD_STAT_BGE_CLEARED                                      (1U)
#define HS_MMC_SD_STAT_BGE_STOPPED                                      (1U)

#define HS_MMC_SD_STAT_DMA_SHIFT                                       (3U)
#define HS_MMC_SD_STAT_DMA_MASK                                        (0x00000008U)
#define HS_MMC_SD_STAT_DMA_INT_DETECTED                                 (0U)
#define HS_MMC_SD_STAT_DMA_NO_INT                                       (1U)
#define HS_MMC_SD_STAT_DMA_UNCHANGED                                    (0U)
#define HS_MMC_SD_STAT_DMA_CLEARED                                      (1U)

#define HS_MMC_SD_STAT_BWR_SHIFT                                       (4U)
#define HS_MMC_SD_STAT_BWR_MASK                                        (0x00000010U)
#define HS_MMC_SD_STAT_BWR_NOT_READY                                    (0U)
#define HS_MMC_SD_STAT_BWR_UNCHANGED                                    (0U)
#define HS_MMC_SD_STAT_BWR_READY                                        (1U)
#define HS_MMC_SD_STAT_BWR_CLEARED                                      (1U)

#define HS_MMC_SD_STAT_BRR_SHIFT                                       (5U)
#define HS_MMC_SD_STAT_BRR_MASK                                        (0x00000020U)
#define HS_MMC_SD_STAT_BRR_READY                                        (1U)
#define HS_MMC_SD_STAT_BRR_NOT_READY                                    (0U)
#define HS_MMC_SD_STAT_BRR_UNCHANGED                                    (0U)
#define HS_MMC_SD_STAT_BRR_CLEARED                                      (1U)

#define HS_MMC_SD_STAT_CINS_SHIFT                                      (6U)
#define HS_MMC_SD_STAT_CINS_MASK                                       (0x00000040U)
#define HS_MMC_SD_STAT_CINS_UNCHANGED                                   (0U)
#define HS_MMC_SD_STAT_CINS_INSERTED                                    (1U)
#define HS_MMC_SD_STAT_CINS_STABLE                                      (0U)
#define HS_MMC_SD_STAT_CINS_CLEARED                                     (1U)

#define HS_MMC_SD_STAT_CREM_SHIFT                                      (7U)
#define HS_MMC_SD_STAT_CREM_MASK                                       (0x00000080U)
#define HS_MMC_SD_STAT_CREM_UNCHANGED                                   (0U)
#define HS_MMC_SD_STAT_CREM_CLEARED                                     (1U)
#define HS_MMC_SD_STAT_CREM_STABLE                                      (0U)
#define HS_MMC_SD_STAT_CREM_REMOVED                                     (1U)

#define HS_MMC_SD_STAT_CIRQ_SHIFT                                      (8U)
#define HS_MMC_SD_STAT_CIRQ_MASK                                       (0x00000100U)
#define HS_MMC_SD_STAT_CIRQ_GEN_INT                                     (1U)
#define HS_MMC_SD_STAT_CIRQ_NO_INT                                      (0U)

#define HS_MMC_SD_STAT_OBI_SHIFT                                       (9U)
#define HS_MMC_SD_STAT_OBI_MASK                                        (0x00000200U)
#define HS_MMC_SD_STAT_OBI_NO_INT                                       (0U)
#define HS_MMC_SD_STAT_OBI_UNCHANGED                                    (0U)
#define HS_MMC_SD_STAT_OBI_INT                                          (1U)
#define HS_MMC_SD_STAT_OBI_CLEARED                                      (1U)

#define HS_MMC_SD_STAT_BSR_SHIFT                                       (10U)
#define HS_MMC_SD_STAT_BSR_MASK                                        (0x00000400U)
#define HS_MMC_SD_STAT_BSR_INT                                          (1U)
#define HS_MMC_SD_STAT_BSR_NO_INT                                       (0U)
#define HS_MMC_SD_STAT_BSR_UNCHANGED                                    (0U)
#define HS_MMC_SD_STAT_BSR_CLEARED                                      (1U)

#define HS_MMC_SD_STAT_ERRI_SHIFT                                      (15U)
#define HS_MMC_SD_STAT_ERRI_MASK                                       (0x00008000U)
#define HS_MMC_SD_STAT_ERRI_NO_INT                                      (0U)
#define HS_MMC_SD_STAT_ERRI_INT                                         (1U)

#define HS_MMC_SD_STAT_CTO_SHIFT                                       (16U)
#define HS_MMC_SD_STAT_CTO_MASK                                        (0x00010000U)
#define HS_MMC_SD_STAT_CTO_UNCHANGED                                    (0U)
#define HS_MMC_SD_STAT_CTO_NO_ERR                                       (0U)
#define HS_MMC_SD_STAT_CTO_ERR                                          (1U)
#define HS_MMC_SD_STAT_CTO_CLEARED                                      (1U)

#define HS_MMC_SD_STAT_CCRC_SHIFT                                      (17U)
#define HS_MMC_SD_STAT_CCRC_MASK                                       (0x00020000U)
#define HS_MMC_SD_STAT_CCRC_ERR                                         (1U)
#define HS_MMC_SD_STAT_CCRC_UNCHANGED                                   (0U)
#define HS_MMC_SD_STAT_CCRC_NO_ERR                                      (0U)
#define HS_MMC_SD_STAT_CCRC_CLEARED                                     (1U)

#define HS_MMC_SD_STAT_CEB_SHIFT                                       (18U)
#define HS_MMC_SD_STAT_CEB_MASK                                        (0x00040000U)
#define HS_MMC_SD_STAT_CEB_ERR                                          (1U)
#define HS_MMC_SD_STAT_CEB_UNCHANGED                                    (0U)
#define HS_MMC_SD_STAT_CEB_NO_ERR                                       (0U)
#define HS_MMC_SD_STAT_CEB_CLEARED                                      (1U)

#define HS_MMC_SD_STAT_CIE_SHIFT                                       (19U)
#define HS_MMC_SD_STAT_CIE_MASK                                        (0x00080000U)
#define HS_MMC_SD_STAT_CIE_UNCHANGED                                    (0U)
#define HS_MMC_SD_STAT_CIE_ERR                                          (1U)
#define HS_MMC_SD_STAT_CIE_NO_ERR                                       (0U)
#define HS_MMC_SD_STAT_CIE_CLEARED                                      (1U)

#define HS_MMC_SD_STAT_DTO_SHIFT                                       (20U)
#define HS_MMC_SD_STAT_DTO_MASK                                        (0x00100000U)
#define HS_MMC_SD_STAT_DTO_ERR                                          (1U)
#define HS_MMC_SD_STAT_DTO_UNCHANGED                                    (0U)
#define HS_MMC_SD_STAT_DTO_NO_ERR                                       (0U)
#define HS_MMC_SD_STAT_DTO_CLEARED                                      (1U)

#define HS_MMC_SD_STAT_DCRC_SHIFT                                      (21U)
#define HS_MMC_SD_STAT_DCRC_MASK                                       (0x00200000U)
#define HS_MMC_SD_STAT_DCRC_ERR                                         (1U)
#define HS_MMC_SD_STAT_DCRC_UNCHANGED                                   (0U)
#define HS_MMC_SD_STAT_DCRC_NO_ERR                                      (0U)
#define HS_MMC_SD_STAT_DCRC_CLEARED                                     (1U)

#define HS_MMC_SD_STAT_DEB_SHIFT                                       (22U)
#define HS_MMC_SD_STAT_DEB_MASK                                        (0x00400000U)
#define HS_MMC_SD_STAT_DEB_UNCHANGED                                    (0U)
#define HS_MMC_SD_STAT_DEB_NO_ERR                                       (0U)
#define HS_MMC_SD_STAT_DEB_ERR                                          (1U)
#define HS_MMC_SD_STAT_DEB_CLEARED                                      (1U)

#define HS_MMC_SD_STAT_ACE_SHIFT                                       (24U)
#define HS_MMC_SD_STAT_ACE_MASK                                        (0x01000000U)
#define HS_MMC_SD_STAT_ACE_ERR                                          (1U)
#define HS_MMC_SD_STAT_ACE_UNCHANGED                                    (0U)
#define HS_MMC_SD_STAT_ACE_NO_ERR                                       (0U)
#define HS_MMC_SD_STAT_ACE_CLEARED                                      (1U)

#define HS_MMC_SD_STAT_ADMAE_SHIFT                                     (25U)
#define HS_MMC_SD_STAT_ADMAE_MASK                                      (0x02000000U)
#define HS_MMC_SD_STAT_ADMAE_ERR                                        (1U)
#define HS_MMC_SD_STAT_ADMAE_NO_ERR                                     (0U)
#define HS_MMC_SD_STAT_ADMAE_UNCHANGED                                  (0U)
#define HS_MMC_SD_STAT_ADMAE_CLEARED                                    (1U)

#define HS_MMC_SD_STAT_CERR_SHIFT                                      (28U)
#define HS_MMC_SD_STAT_CERR_MASK                                       (0x10000000U)
#define HS_MMC_SD_STAT_CERR_UNCHANGED                                   (0U)
#define HS_MMC_SD_STAT_CERR_NO_ERR                                      (0U)
#define HS_MMC_SD_STAT_CERR_ERR                                         (1U)
#define HS_MMC_SD_STAT_CERR_CLEARED                                     (1U)

#define HS_MMC_SD_STAT_BADA_SHIFT                                      (29U)
#define HS_MMC_SD_STAT_BADA_MASK                                       (0x20000000U)
#define HS_MMC_SD_STAT_BADA_ERR                                         (1U)
#define HS_MMC_SD_STAT_BADA_NO_ERR                                      (0U)
#define HS_MMC_SD_STAT_BADA_UNCHANGED                                   (0U)
#define HS_MMC_SD_STAT_BADA_CLEARED                                     (1U)

#define HS_MMC_SD_CON_OD_SHIFT                                         (0U)
#define HS_MMC_SD_CON_OD_MASK                                          (0x00000001U)
#define HS_MMC_SD_CON_OD_OPENDRAIN                                      (1U)
#define HS_MMC_SD_CON_OD_NO_OPENDRAIN                                   (0U)

#define HS_MMC_SD_CON_INIT_SHIFT                                       (1U)
#define HS_MMC_SD_CON_INIT_MASK                                        (0x00000002U)
#define HS_MMC_SD_CON_INIT_NO_INITSEQ                                   (0U)
#define HS_MMC_SD_CON_INIT_INITSEQ                                      (1U)

#define HS_MMC_SD_CON_HR_SHIFT                                         (2U)
#define HS_MMC_SD_CON_HR_MASK                                          (0x00000004U)
#define HS_MMC_SD_CON_HR_NO_RESP                                        (0U)
#define HS_MMC_SD_CON_HR_RESP                                           (1U)

#define HS_MMC_SD_CON_STR_SHIFT                                        (3U)
#define HS_MMC_SD_CON_STR_MASK                                         (0x00000008U)
#define HS_MMC_SD_CON_STR_BLOCK                                         (0U)
#define HS_MMC_SD_CON_STR_STREAM                                        (1U)

#define HS_MMC_SD_CON_MODE_SHIFT                                       (4U)
#define HS_MMC_SD_CON_MODE_MASK                                        (0x00000010U)
#define HS_MMC_SD_CON_MODE_FUNC                                         (0U)
#define HS_MMC_SD_CON_MODE_SYSTEST                                      (1U)

#define HS_MMC_SD_CON_DW8_SHIFT                                        (5U)
#define HS_MMC_SD_CON_DW8_MASK                                         (0x00000020U)
#define HS_MMC_SD_CON_DW8_EIGHT_BIT                                     (1U)
#define HS_MMC_SD_CON_DW8_ONE_OR_FOUR_BIT                               (0U)

#define HS_MMC_SD_CON_MIT_SHIFT                                        (6U)
#define HS_MMC_SD_CON_MIT_MASK                                         (0x00000040U)
#define HS_MMC_SD_CON_MIT_ENABLED                                       (0U)
#define HS_MMC_SD_CON_MIT_DISABLED                                      (1U)

#define HS_MMC_SD_CON_CDP_SHIFT                                        (7U)
#define HS_MMC_SD_CON_CDP_MASK                                         (0x00000080U)
#define HS_MMC_SD_CON_CDP_LOW                                           (1U)
#define HS_MMC_SD_CON_CDP_HIGH                                          (0U)

#define HS_MMC_SD_CON_WPP_SHIFT                                        (8U)
#define HS_MMC_SD_CON_WPP_MASK                                         (0x00000100U)
#define HS_MMC_SD_CON_WPP_LOW                                           (1U)
#define HS_MMC_SD_CON_WPP_HIGH                                          (0U)

#define HS_MMC_SD_CON_DVAL_SHIFT                                       (9U)
#define HS_MMC_SD_CON_DVAL_MASK                                        (0x00000600U)
#define HS_MMC_SD_CON_DVAL_PRD_231US                                    (1U)
#define HS_MMC_SD_CON_DVAL_PRD_33US                                     (0U)
#define HS_MMC_SD_CON_DVAL_PRD_1MS                                      (2U)
#define HS_MMC_SD_CON_DVAL_PRD_8_4MS                                    (3U)

#define HS_MMC_SD_CON_CTPL_SHIFT                                       (11U)
#define HS_MMC_SD_CON_CTPL_MASK                                        (0x00000800U)
#define HS_MMC_SD_CON_CTPL_ENABLE_MMC_DAT1                              (1U)
#define HS_MMC_SD_CON_CTPL_DISABLE_ALL                                  (0U)

#define HS_MMC_SD_CON_CEATA_SHIFT                                      (12U)
#define HS_MMC_SD_CON_CEATA_MASK                                       (0x00001000U)
#define HS_MMC_SD_CON_CEATA_STANDARD                                    (0U)
#define HS_MMC_SD_CON_CEATA_CE_ATA                                      (1U)

#define HS_MMC_SD_CON_PADEN_SHIFT                                      (15U)
#define HS_MMC_SD_CON_PADEN_MASK                                       (0x00008000U)
#define HS_MMC_SD_CON_PADEN_FORCED                                      (1U)
#define HS_MMC_SD_CON_PADEN_NOT_FORCED                                  (0U)

#define HS_MMC_SD_CON_CLKEXTFREE_SHIFT                                 (16U)
#define HS_MMC_SD_CON_CLKEXTFREE_MASK                                  (0x00010000U)
#define HS_MMC_SD_CON_CLKEXTFREE_CUT_OFF                                (0U)
#define HS_MMC_SD_CON_CLKEXTFREE_MAINTAINED                             (1U)

#define HS_MMC_SD_CON_BOOT_ACK_SHIFT                                   (17U)
#define HS_MMC_SD_CON_BOOT_ACK_MASK                                    (0x00020000U)
#define HS_MMC_SD_CON_BOOT_ACK_NOACKRX                                  (0U)
#define HS_MMC_SD_CON_BOOT_ACK_ACKRX                                    (1U)

#define HS_MMC_SD_CON_BOOT_CF0_SHIFT                                   (18U)
#define HS_MMC_SD_CON_BOOT_CF0_MASK                                    (0x00040000U)
#define HS_MMC_SD_CON_BOOT_CF0_ENABLED_AFTER_CMD                        (1U)
#define HS_MMC_SD_CON_BOOT_CF0_NOT_FORCED                               (0U)
#define HS_MMC_SD_CON_BOOT_CF0_ENABLED                                  (0U)
#define HS_MMC_SD_CON_BOOT_CF0_RELEASED                                 (1U)

#define HS_MMC_SD_CON_DDR_SHIFT                                        (19U)
#define HS_MMC_SD_CON_DDR_MASK                                         (0x00080000U)
#define HS_MMC_SD_CON_DDR_SINGLE_EDGE                                   (0U)
#define HS_MMC_SD_CON_DDR_BOTH_EDGES                                    (1U)

#define HS_MMC_SD_CON_DMA_MNS_SHIFT                                    (20U)
#define HS_MMC_SD_CON_DMA_MNS_MASK                                     (0x00100000U)
#define HS_MMC_SD_CON_DMA_MNS_NOT_AVAIL                                 (1U)
#define HS_MMC_SD_CON_DMA_MNS_SLAVE                                     (0U)

#define HS_MMC_SD_CON_SDMA_LNE_SHIFT                                   (21U)
#define HS_MMC_SD_CON_SDMA_LNE_MASK                                    (0x00200000U)
#define HS_MMC_SD_CON_SDMA_LNE_EDGE_SENS                                (0U)
#define HS_MMC_SD_CON_SDMA_LNE_LEVEL_SENS                               (1U)

#define HS_MMC_SD_IE_CC_ENABLE_SHIFT                                   (0U)
#define HS_MMC_SD_IE_CC_ENABLE_MASK                                    (0x00000001U)
#define HS_MMC_SD_IE_CC_ENABLE_ENABLED                                  (1U)
#define HS_MMC_SD_IE_CC_ENABLE_MASKED                                   (0U)

#define HS_MMC_SD_IE_TC_ENABLE_SHIFT                                   (1U)
#define HS_MMC_SD_IE_TC_ENABLE_MASK                                    (0x00000002U)
#define HS_MMC_SD_IE_TC_ENABLE_ENABLED                                  (1U)
#define HS_MMC_SD_IE_TC_ENABLE_MASKED                                   (0U)

#define HS_MMC_SD_IE_BGE_ENABLE_SHIFT                                  (2U)
#define HS_MMC_SD_IE_BGE_ENABLE_MASK                                   (0x00000004U)
#define HS_MMC_SD_IE_BGE_ENABLE_ENABLED                                 (1U)
#define HS_MMC_SD_IE_BGE_ENABLE_MASKED                                  (0U)

#define HS_MMC_SD_IE_DMA_ENABLE_SHIFT                                  (3U)
#define HS_MMC_SD_IE_DMA_ENABLE_MASK                                   (0x00000008U)
#define HS_MMC_SD_IE_DMA_ENABLE_ENABLED                                 (1U)
#define HS_MMC_SD_IE_DMA_ENABLE_MASKED                                  (0U)

#define HS_MMC_SD_IE_BWR_ENABLE_SHIFT                                  (4U)
#define HS_MMC_SD_IE_BWR_ENABLE_MASK                                   (0x00000010U)
#define HS_MMC_SD_IE_BWR_ENABLE_ENABLED                                 (1U)
#define HS_MMC_SD_IE_BWR_ENABLE_MASKED                                  (0U)

#define HS_MMC_SD_IE_BRR_ENABLE_SHIFT                                  (5U)
#define HS_MMC_SD_IE_BRR_ENABLE_MASK                                   (0x00000020U)
#define HS_MMC_SD_IE_BRR_ENABLE_ENABLED                                 (1U)
#define HS_MMC_SD_IE_BRR_ENABLE_MASKED                                  (0U)

#define HS_MMC_SD_IE_CINS_ENABLE_SHIFT                                 (6U)
#define HS_MMC_SD_IE_CINS_ENABLE_MASK                                  (0x00000040U)
#define HS_MMC_SD_IE_CINS_ENABLE_ENABLED                                (1U)
#define HS_MMC_SD_IE_CINS_ENABLE_MASKED                                 (0U)

#define HS_MMC_SD_IE_CREM_ENABLE_SHIFT                                 (7U)
#define HS_MMC_SD_IE_CREM_ENABLE_MASK                                  (0x00000080U)
#define HS_MMC_SD_IE_CREM_ENABLE_ENABLED                                (1U)
#define HS_MMC_SD_IE_CREM_ENABLE_MASKED                                 (0U)

#define HS_MMC_SD_IE_CIRQ_ENABLE_SHIFT                                 (8U)
#define HS_MMC_SD_IE_CIRQ_ENABLE_MASK                                  (0x00000100U)
#define HS_MMC_SD_IE_CIRQ_ENABLE_ENABLED                                (1U)
#define HS_MMC_SD_IE_CIRQ_ENABLE_MASKED                                 (0U)

#define HS_MMC_SD_IE_OBI_ENABLE_SHIFT                                  (9U)
#define HS_MMC_SD_IE_OBI_ENABLE_MASK                                   (0x00000200U)
#define HS_MMC_SD_IE_OBI_ENABLE_ENABLED                                 (1U)
#define HS_MMC_SD_IE_OBI_ENABLE_MASKED                                  (0U)

#define HS_MMC_SD_IE_BSR_ENABLE_SHIFT                                  (10U)
#define HS_MMC_SD_IE_BSR_ENABLE_MASK                                   (0x00000400U)
#define HS_MMC_SD_IE_BSR_ENABLE_ENABLED                                 (1U)
#define HS_MMC_SD_IE_BSR_ENABLE_MASKED                                  (0U)

#define HS_MMC_SD_IE_NULL_SHIFT                                        (15U)
#define HS_MMC_SD_IE_NULL_MASK                                         (0x00008000U)

#define HS_MMC_SD_IE_CTO_ENABLE_SHIFT                                  (16U)
#define HS_MMC_SD_IE_CTO_ENABLE_MASK                                   (0x00010000U)
#define HS_MMC_SD_IE_CTO_ENABLE_ENABLED                                 (1U)
#define HS_MMC_SD_IE_CTO_ENABLE_MASKED                                  (0U)

#define HS_MMC_SD_IE_CCRC_ENABLE_SHIFT                                 (17U)
#define HS_MMC_SD_IE_CCRC_ENABLE_MASK                                  (0x00020000U)
#define HS_MMC_SD_IE_CCRC_ENABLE_ENABLED                                (1U)
#define HS_MMC_SD_IE_CCRC_ENABLE_MASKED                                 (0U)

#define HS_MMC_SD_IE_CEB_ENABLE_SHIFT                                  (18U)
#define HS_MMC_SD_IE_CEB_ENABLE_MASK                                   (0x00040000U)
#define HS_MMC_SD_IE_CEB_ENABLE_ENABLED                                 (1U)
#define HS_MMC_SD_IE_CEB_ENABLE_MASKED                                  (0U)

#define HS_MMC_SD_IE_CIE_ENABLE_SHIFT                                  (19U)
#define HS_MMC_SD_IE_CIE_ENABLE_MASK                                   (0x00080000U)
#define HS_MMC_SD_IE_CIE_ENABLE_ENABLED                                 (1U)
#define HS_MMC_SD_IE_CIE_ENABLE_MASKED                                  (0U)

#define HS_MMC_SD_IE_DTO_ENABLE_SHIFT                                  (20U)
#define HS_MMC_SD_IE_DTO_ENABLE_MASK                                   (0x00100000U)
#define HS_MMC_SD_IE_DTO_ENABLE_ENABLED                                 (1U)
#define HS_MMC_SD_IE_DTO_ENABLE_MASKED                                  (0U)

#define HS_MMC_SD_IE_DCRC_ENABLE_SHIFT                                 (21U)
#define HS_MMC_SD_IE_DCRC_ENABLE_MASK                                  (0x00200000U)
#define HS_MMC_SD_IE_DCRC_ENABLE_ENABLED                                (1U)
#define HS_MMC_SD_IE_DCRC_ENABLE_MASKED                                 (0U)

#define HS_MMC_SD_IE_DEB_ENABLE_SHIFT                                  (22U)
#define HS_MMC_SD_IE_DEB_ENABLE_MASK                                   (0x00400000U)
#define HS_MMC_SD_IE_DEB_ENABLE_ENABLED                                 (1U)
#define HS_MMC_SD_IE_DEB_ENABLE_MASKED                                  (0U)

#define HS_MMC_SD_IE_ACE_ENABLE_SHIFT                                  (24U)
#define HS_MMC_SD_IE_ACE_ENABLE_MASK                                   (0x01000000U)
#define HS_MMC_SD_IE_ACE_ENABLE_ENABLED                                 (1U)
#define HS_MMC_SD_IE_ACE_ENABLE_MASKED                                  (0U)

#define HS_MMC_SD_IE_ADMA_ENABLE_SHIFT                                 (25U)
#define HS_MMC_SD_IE_ADMA_ENABLE_MASK                                  (0x02000000U)
#define HS_MMC_SD_IE_ADMA_ENABLE_ENABLED                                (1U)
#define HS_MMC_SD_IE_ADMA_ENABLE_MASKED                                 (0U)

#define HS_MMC_SD_IE_CERR_ENABLE_SHIFT                                 (28U)
#define HS_MMC_SD_IE_CERR_ENABLE_MASK                                  (0x10000000U)
#define HS_MMC_SD_IE_CERR_ENABLE_ENABLED                                (1U)
#define HS_MMC_SD_IE_CERR_ENABLE_MASKED                                 (0U)

#define HS_MMC_SD_IE_BADA_ENABLE_SHIFT                                 (29U)
#define HS_MMC_SD_IE_BADA_ENABLE_MASK                                  (0x20000000U)
#define HS_MMC_SD_IE_BADA_ENABLE_ENABLED                                (1U)
#define HS_MMC_SD_IE_BADA_ENABLE_MASKED                                 (0U)

#define HS_MMC_SD_CUR_CAPA_3V3_SHIFT                                   (0U)
#define HS_MMC_SD_CUR_CAPA_3V3_MASK                                    (0x000000ffU)
#define HS_MMC_SD_CUR_CAPA_3V3_NOT_AVAIL                                (0U)

#define HS_MMC_SD_CUR_CAPA_3V0_SHIFT                                   (8U)
#define HS_MMC_SD_CUR_CAPA_3V0_MASK                                    (0x0000ff00U)
#define HS_MMC_SD_CUR_CAPA_3V0_NOT_AVAIL                                (0U)

#define HS_MMC_SD_CUR_CAPA_1V8_SHIFT                                   (16U)
#define HS_MMC_SD_CUR_CAPA_1V8_MASK                                    (0x00ff0000U)
#define HS_MMC_SD_CUR_CAPA_1V8_NOT_AVAIL                                (0U)

#define HS_MMC_SD_SYSCTL_ICE_SHIFT                                     (0U)
#define HS_MMC_SD_SYSCTL_ICE_MASK                                      (0x00000001U)
#define HS_MMC_SD_SYSCTL_ICE_OSCILLATES                                 (1U)
#define HS_MMC_SD_SYSCTL_ICE_STOPPED                                    (0U)

#define HS_MMC_SD_SYSCTL_ICS_SHIFT                                     (1U)
#define HS_MMC_SD_SYSCTL_ICS_MASK                                      (0x00000002U)
#define HS_MMC_SD_SYSCTL_ICS_NOT_STABLE                                 (0U)
#define HS_MMC_SD_SYSCTL_ICS_STABLE                                     (1U)

#define HS_MMC_SD_SYSCTL_CEN_SHIFT                                     (2U)
#define HS_MMC_SD_SYSCTL_CEN_MASK                                      (0x00000004U)
#define HS_MMC_SD_SYSCTL_CEN_CLK_NOT_PROVIDED                           (0U)
#define HS_MMC_SD_SYSCTL_CEN_CLK_PROVIDED                               (1U)

#define HS_MMC_SD_SYSCTL_CLKD_SHIFT                                    (6U)
#define HS_MMC_SD_SYSCTL_CLKD_MASK                                     (0x0000ffc0U)
#define HS_MMC_SD_SYSCTL_CLKD_DIV3                                      (3U)
#define HS_MMC_SD_SYSCTL_CLKD_DIV1023                                   (1023U)
#define HS_MMC_SD_SYSCTL_CLKD_BYPASS0                                   (0U)
#define HS_MMC_SD_SYSCTL_CLKD_BYPASS1                                   (1U)
#define HS_MMC_SD_SYSCTL_CLKD_DIV2                                      (2U)

#define HS_MMC_SD_SYSCTL_DTO_SHIFT                                     (16U)
#define HS_MMC_SD_SYSCTL_DTO_MASK                                      (0x000f0000U)
#define HS_MMC_SD_SYSCTL_DTO_EXP27                                      (14U)
#define HS_MMC_SD_SYSCTL_DTO_RESERVED                                   (15U)
#define HS_MMC_SD_SYSCTL_DTO_EXP13                                      (0U)
#define HS_MMC_SD_SYSCTL_DTO_EXP14                                      (1U)

#define HS_MMC_SD_SYSCTL_SRA_SHIFT                                     (24U)
#define HS_MMC_SD_SYSCTL_SRA_MASK                                      (0x01000000U)
#define HS_MMC_SD_SYSCTL_SRA_SW_RESET                                   (1U)
#define HS_MMC_SD_SYSCTL_SRA_RESET_COMPLETE                             (0U)

#define HS_MMC_SD_SYSCTL_SRC_SHIFT                                     (25U)
#define HS_MMC_SD_SYSCTL_SRC_MASK                                      (0x02000000U)
#define HS_MMC_SD_SYSCTL_SRC_SW_RESET                                   (1U)
#define HS_MMC_SD_SYSCTL_SRC_RESET_COMPLETE                             (0U)

#define HS_MMC_SD_SYSCTL_SRD_SHIFT                                     (26U)
#define HS_MMC_SD_SYSCTL_SRD_MASK                                      (0x04000000U)
#define HS_MMC_SD_SYSCTL_SRD_SW_RESET                                   (1U)
#define HS_MMC_SD_SYSCTL_SRD_RESET_COMPLETE                             (0U)

#define HS_MMC_SD_RSP32_RSP2_SHIFT                                     (0U)
#define HS_MMC_SD_RSP32_RSP2_MASK                                      (0x0000ffffU)

#define HS_MMC_SD_RSP32_RSP3_SHIFT                                     (16U)
#define HS_MMC_SD_RSP32_RSP3_MASK                                      (0xffff0000U)

#define HS_MMC_SD_BLK_BLEN_SHIFT                                       (0U)
#define HS_MMC_SD_BLK_BLEN_MASK                                        (0x00000fffU)
#define HS_MMC_SD_BLK_BLEN_LEN_2048                                     (2048U)
#define HS_MMC_SD_BLK_BLEN_NOTX                                         (0U)
#define HS_MMC_SD_BLK_BLEN_LEN_511                                      (511U)
#define HS_MMC_SD_BLK_BLEN_LEN_3                                        (3U)
#define HS_MMC_SD_BLK_BLEN_LEN_2047                                     (2047U)
#define HS_MMC_SD_BLK_BLEN_LEN_512                                      (512U)
#define HS_MMC_SD_BLK_BLEN_LEN_2                                        (2U)
#define HS_MMC_SD_BLK_BLEN_LEN_1                                        (1U)

#define HS_MMC_SD_BLK_NBLK_SHIFT                                       (16U)
#define HS_MMC_SD_BLK_NBLK_MASK                                        (0xffff0000U)
#define HS_MMC_SD_BLK_NBLK_65535                                        (65535U)
#define HS_MMC_SD_BLK_NBLK_STOP_CNT                                     (0U)
#define HS_MMC_SD_BLK_NBLK_1                                            (1U)
#define HS_MMC_SD_BLK_NBLK_2                                            (2U)

#define HS_MMC_SD_RSP10_RSP0_SHIFT                                     (0U)
#define HS_MMC_SD_RSP10_RSP0_MASK                                      (0x0000ffffU)

#define HS_MMC_SD_RSP10_RSP1_SHIFT                                     (16U)
#define HS_MMC_SD_RSP10_RSP1_MASK                                      (0xffff0000U)

#define HS_MMC_SD_SDMASA_SDMA_SYSADDR_SHIFT                            (0U)
#define HS_MMC_SD_SDMASA_SDMA_SYSADDR_MASK                             (0xffffffffU)

#define HS_MMC_SD_SYSSTATUS_RESETDONE_SHIFT                            (0U)
#define HS_MMC_SD_SYSSTATUS_RESETDONE_MASK                             (0x00000001U)
#define HS_MMC_SD_SYSSTATUS_RESETDONE_ONGOING                           (0U)
#define HS_MMC_SD_SYSSTATUS_RESETDONE_COMPLETED                         (1U)

#ifdef __cplusplus
}
#endif

#endif /* HW_HS_MMC_SD_H_ */