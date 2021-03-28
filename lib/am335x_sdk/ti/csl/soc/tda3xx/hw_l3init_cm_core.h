/*
 *  Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file   hw_l3init_cm_core.h
 *
 *  \brief  Register-level header file for PRCM
 *
**/

#ifndef HW_L3INIT_CM_CORE_H_
#define HW_L3INIT_CM_CORE_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define CM_L3INIT_CLKSTCTRL                                         (0x0U)
#define CM_L3INIT_STATICDEP                                         (0x4U)
#define CM_L3INIT_DYNAMICDEP                                   (0x8U)
#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL                       (0x78U)
#define CM_PCIE_CLKSTCTRL                                      (0xa0U)
#define CM_GMAC_CLKSTCTRL                                      (0xc0U)
#define CM_GMAC_STATICDEP                                      (0xc4U)
#define CM_GMAC_DYNAMICDEP                                     (0xc8U)
#define CM_GMAC_GMAC_CLKCTRL                                                                                (0xd0U)
#define CM_L3INIT_OCP2SCP1_CLKCTRL                             (0xe0U)
#define CM_L3INIT_OCP2SCP3_CLKCTRL                             (0xe8U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define CM_L3INIT_CLKSTCTRL_CLKTRCTRL_SHIFT                                             (0U)
#define CM_L3INIT_CLKSTCTRL_CLKTRCTRL_MASK                                              (0x00000003U)
#define CM_L3INIT_CLKSTCTRL_CLKTRCTRL_NO_SLEEP                                           (0U)
#define CM_L3INIT_CLKSTCTRL_CLKTRCTRL_SW_SLEEP                                           (1U)
#define CM_L3INIT_CLKSTCTRL_CLKTRCTRL_SW_WKUP                                            (2U)
#define CM_L3INIT_CLKSTCTRL_CLKTRCTRL_HW_AUTO                                            (3U)

#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_L3_GICLK_SHIFT                                               (8U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_L3_GICLK_MASK                                                (0x00000100U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_L3_GICLK_INACT                                                (0U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_L3_GICLK_ACT                                                  (1U)

#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_L4_GICLK_SHIFT                                               (9U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_L4_GICLK_MASK                                                (0x00000200U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_L4_GICLK_INACT                                                (0U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_L4_GICLK_ACT                                                  (1U)

#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_48M_GFCLK_SHIFT                                              (11U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_48M_GFCLK_MASK                                               (0x00000800U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_48M_GFCLK_INACT                                               (0U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_48M_GFCLK_ACT                                                 (1U)

#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_HSI_GFCLK_SHIFT                                 (14U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_HSI_GFCLK_MASK                                  (0x00004000U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_HSI_GFCLK_INACT                                  (0U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_HSI_GFCLK_ACT                                    (1U)

#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_USB_DPLL_CLK_SHIFT                              (12U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_USB_DPLL_CLK_MASK                               (0x00001000U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_USB_DPLL_CLK_INACT                               (0U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_USB_DPLL_CLK_ACT                                 (1U)

#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_USB_DPLL_HS_CLK_SHIFT                           (13U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_USB_DPLL_HS_CLK_MASK                            (0x00002000U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_USB_DPLL_HS_CLK_INACT                            (0U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_USB_DPLL_HS_CLK_ACT                              (1U)

#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_USB_OTG_SS_REF_CLK_SHIFT                        (20U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_USB_OTG_SS_REF_CLK_MASK                         (0x00100000U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_USB_OTG_SS_REF_CLK_INACT                         (0U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_USB_OTG_SS_REF_CLK_ACT                           (1U)

#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_USB_LFPS_TX_GFCLK_SHIFT                                      (10U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_USB_LFPS_TX_GFCLK_MASK                                       (0x00000400U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_USB_LFPS_TX_GFCLK_INACT                                       (0U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_USB_LFPS_TX_GFCLK_ACT                                         (1U)

#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_480M_GFCLK_SHIFT                                             (21U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_480M_GFCLK_MASK                                              (0x00200000U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_480M_GFCLK_INACT                                              (0U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_480M_GFCLK_ACT                                                (1U)

#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_960M_GFCLK_SHIFT                                             (22U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_960M_GFCLK_MASK                                              (0x00400000U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_960M_GFCLK_INACT                                              (0U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_960M_GFCLK_ACT                                                (1U)

#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_32K_GFCLK_SHIFT                                              (23U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_32K_GFCLK_MASK                                               (0x00800000U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_32K_GFCLK_INACT                                               (0U)
#define CM_L3INIT_CLKSTCTRL_CLKACTIVITY_L3INIT_32K_GFCLK_ACT                                                 (1U)

#define CM_L3INIT_STATICDEP_EMIF_STATDEP_SHIFT                                          (4U)
#define CM_L3INIT_STATICDEP_EMIF_STATDEP_MASK                                           (0x00000010U)
#define CM_L3INIT_STATICDEP_EMIF_STATDEP_ENABLED                                         (1U)
#define CM_L3INIT_STATICDEP_EMIF_STATDEP_DISABLED                                        (0U)

#define CM_L3INIT_STATICDEP_L3MAIN1_STATDEP_SHIFT                                       (5U)
#define CM_L3INIT_STATICDEP_L3MAIN1_STATDEP_MASK                                        (0x00000020U)
#define CM_L3INIT_STATICDEP_L3MAIN1_STATDEP_ENABLED                                      (1U)

#define CM_L3INIT_STATICDEP_L4CFG_STATDEP_SHIFT                                         (12U)
#define CM_L3INIT_STATICDEP_L4CFG_STATDEP_MASK                                          (0x00001000U)
#define CM_L3INIT_STATICDEP_L4CFG_STATDEP_ENABLED                                        (1U)
#define CM_L3INIT_STATICDEP_L4CFG_STATDEP_DISABLED                                       (0U)

#define CM_L3INIT_STATICDEP_L4PER_STATDEP_SHIFT                                         (13U)
#define CM_L3INIT_STATICDEP_L4PER_STATDEP_MASK                                          (0x00002000U)
#define CM_L3INIT_STATICDEP_L4PER_STATDEP_ENABLED                                        (1U)
#define CM_L3INIT_STATICDEP_L4PER_STATDEP_DISABLED                                       (0U)

#define CM_L3INIT_STATICDEP_L4SEC_STATDEP_SHIFT                                         (14U)
#define CM_L3INIT_STATICDEP_L4SEC_STATDEP_MASK                                          (0x00004000U)
#define CM_L3INIT_STATICDEP_L4SEC_STATDEP_ENABLED                                        (1U)
#define CM_L3INIT_STATICDEP_L4SEC_STATDEP_DISABLED                                       (0U)

#define CM_L3INIT_STATICDEP_WKUPAON_STATDEP_SHIFT                                       (15U)
#define CM_L3INIT_STATICDEP_WKUPAON_STATDEP_MASK                                        (0x00008000U)
#define CM_L3INIT_STATICDEP_WKUPAON_STATDEP_ENABLED                                      (1U)
#define CM_L3INIT_STATICDEP_WKUPAON_STATDEP_DISABLED                                     (0U)

#define CM_L3INIT_STATICDEP_L4PER3_STATDEP_SHIFT                                        (27U)
#define CM_L3INIT_STATICDEP_L4PER3_STATDEP_MASK                                         (0x08000000U)
#define CM_L3INIT_STATICDEP_L4PER3_STATDEP_ENABLED                                       (1U)
#define CM_L3INIT_STATICDEP_L4PER3_STATDEP_DISABLED                                      (0U)

#define CM_L3INIT_DYNAMICDEP_L3MAIN1_DYNDEP_SHIFT                                  (5U)
#define CM_L3INIT_DYNAMICDEP_L3MAIN1_DYNDEP_MASK                                   (0x00000020U)
#define CM_L3INIT_DYNAMICDEP_L3MAIN1_DYNDEP_DISABLED                                (0U)

#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_IDLEST_SHIFT                              (16U)
#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_IDLEST_MASK                               (0x00030000U)
#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_IDLEST_DISABLE                             (3U)
#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_IDLEST_IDLE                                (2U)
#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_IDLEST_FUNC                                (0U)
#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_IDLEST_TRANS                               (1U)

#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_STBYST_SHIFT                              (18U)
#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_STBYST_MASK                               (0x00040000U)
#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_STBYST_FUNC                                (0U)
#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_STBYST_STANDBY                             (1U)

#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_MODULEMODE_SHIFT                          (0U)
#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_MODULEMODE_MASK                           (0x00000003U)
#define CM_L3INIT_IEEE1500_2_OCP_CLKCTRL_MODULEMODE_AUTO                            (1U)

#define CM_PCIE_CLKSTCTRL_CLKTRCTRL_SHIFT                                          (0U)
#define CM_PCIE_CLKSTCTRL_CLKTRCTRL_MASK                                           (0x00000003U)
#define CM_PCIE_CLKSTCTRL_CLKTRCTRL_NO_SLEEP                                        (0U)
#define CM_PCIE_CLKSTCTRL_CLKTRCTRL_SW_SLEEP                                        (1U)
#define CM_PCIE_CLKSTCTRL_CLKTRCTRL_SW_WKUP                                         (2U)
#define CM_PCIE_CLKSTCTRL_CLKTRCTRL_HW_AUTO                                         (3U)

#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_L3_GICLK_SHIFT                                                   (8U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_L3_GICLK_MASK                                                    (0x00000100U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_L3_GICLK_INACT                                                    (0U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_L3_GICLK_ACT                                                      (1U)

#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_PHY_GCLK_SHIFT                                                   (9U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_PHY_GCLK_MASK                                                    (0x00000200U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_PHY_GCLK_INACT                                                    (0U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_PHY_GCLK_ACT                                                      (1U)

#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_PHY_DIV_GCLK_SHIFT                                               (10U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_PHY_DIV_GCLK_MASK                                                (0x00000400U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_PHY_DIV_GCLK_INACT                                                (0U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_PHY_DIV_GCLK_ACT                                                  (1U)

#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_REF_GFCLK_SHIFT                                                  (11U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_REF_GFCLK_MASK                                                   (0x00000800U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_REF_GFCLK_INACT                                                   (0U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_REF_GFCLK_ACT                                                     (1U)

#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_SYS_GFCLK_SHIFT                                                  (12U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_SYS_GFCLK_MASK                                                   (0x00001000U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_SYS_GFCLK_INACT                                                   (0U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_SYS_GFCLK_ACT                                                     (1U)

#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_32K_GFCLK_SHIFT                                                  (13U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_32K_GFCLK_MASK                                                   (0x00002000U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_32K_GFCLK_INACT                                                   (0U)
#define CM_PCIE_CLKSTCTRL_CLKACTIVITY_PCIE_32K_GFCLK_ACT                                                     (1U)

#define CM_GMAC_CLKSTCTRL_CLKTRCTRL_SHIFT                                          (0U)
#define CM_GMAC_CLKSTCTRL_CLKTRCTRL_MASK                                           (0x00000003U)
#define CM_GMAC_CLKSTCTRL_CLKTRCTRL_NO_SLEEP                                        (0U)
#define CM_GMAC_CLKSTCTRL_CLKTRCTRL_SW_SLEEP                                        (1U)
#define CM_GMAC_CLKSTCTRL_CLKTRCTRL_SW_WKUP                                         (2U)
#define CM_GMAC_CLKSTCTRL_CLKTRCTRL_HW_AUTO                                         (3U)

#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_GMII_250MHZ_CLK_SHIFT                        (8U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_GMII_250MHZ_CLK_MASK                         (0x00000100U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_GMII_250MHZ_CLK_INACT                         (0U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_GMII_250MHZ_CLK_ACT                           (1U)

#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_RGMII_5MHZ_CLK_SHIFT                         (9U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_RGMII_5MHZ_CLK_MASK                          (0x00000200U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_RGMII_5MHZ_CLK_INACT                          (0U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_RGMII_5MHZ_CLK_ACT                            (1U)

#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_GMAC_RFT_CLK_SHIFT                                                    (11U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_GMAC_RFT_CLK_MASK                                                     (0x00000800U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_GMAC_RFT_CLK_INACT                                                     (0U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_GMAC_RFT_CLK_ACT                                                       (1U)

#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_GMAC_MAIN_CLK_SHIFT                                                   (12U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_GMAC_MAIN_CLK_MASK                                                    (0x00001000U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_GMAC_MAIN_CLK_INACT                                                    (0U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_GMAC_MAIN_CLK_ACT                                                      (1U)

#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_RMII_50MHZ_CLK_SHIFT                         (10U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_RMII_50MHZ_CLK_MASK                          (0x00000400U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_RMII_50MHZ_CLK_INACT                          (0U)
#define CM_GMAC_CLKSTCTRL_CLKACTIVITY_RMII_50MHZ_CLK_ACT                            (1U)

#define CM_GMAC_STATICDEP_EMIF_STATDEP_SHIFT                                       (4U)
#define CM_GMAC_STATICDEP_EMIF_STATDEP_MASK                                        (0x00000010U)
#define CM_GMAC_STATICDEP_EMIF_STATDEP_ENABLED                                      (1U)
#define CM_GMAC_STATICDEP_EMIF_STATDEP_DISABLED                                     (0U)

#define CM_GMAC_STATICDEP_L3MAIN1_STATDEP_SHIFT                                    (5U)
#define CM_GMAC_STATICDEP_L3MAIN1_STATDEP_MASK                                     (0x00000020U)
#define CM_GMAC_STATICDEP_L3MAIN1_STATDEP_ENABLED                                   (1U)

#define CM_GMAC_STATICDEP_L4PER2_STATDEP_SHIFT                                     (26U)
#define CM_GMAC_STATICDEP_L4PER2_STATDEP_MASK                                      (0x04000000U)
#define CM_GMAC_STATICDEP_L4PER2_STATDEP_ENABLED                                    (1U)
#define CM_GMAC_STATICDEP_L4PER2_STATDEP_DISABLED                                   (0U)

#define CM_GMAC_DYNAMICDEP_L3MAIN1_DYNDEP_SHIFT                                    (5U)
#define CM_GMAC_DYNAMICDEP_L3MAIN1_DYNDEP_MASK                                     (0x00000020U)
#define CM_GMAC_DYNAMICDEP_L3MAIN1_DYNDEP_DISABLED                                  (0U)

#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_REF_SHIFT                                                               (24U)
#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_REF_MASK                                                                (0x01000000U)
#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_REF_SEL_GMAC_RMII_HS_CLK                                                 (0U)
#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_REF_SEL_GMAC_RMII_CLK                                                    (1U)

#define CM_GMAC_GMAC_CLKCTRL_IDLEST_SHIFT                                                                   (16U)
#define CM_GMAC_GMAC_CLKCTRL_IDLEST_MASK                                                                    (0x00030000U)
#define CM_GMAC_GMAC_CLKCTRL_IDLEST_DISABLE                                                                  (3U)
#define CM_GMAC_GMAC_CLKCTRL_IDLEST_IDLE                                                                     (2U)
#define CM_GMAC_GMAC_CLKCTRL_IDLEST_FUNC                                                                     (0U)
#define CM_GMAC_GMAC_CLKCTRL_IDLEST_TRANS                                                                    (1U)

#define CM_GMAC_GMAC_CLKCTRL_STBYST_SHIFT                                                                   (18U)
#define CM_GMAC_GMAC_CLKCTRL_STBYST_MASK                                                                    (0x00040000U)
#define CM_GMAC_GMAC_CLKCTRL_STBYST_FUNC                                                                     (0U)
#define CM_GMAC_GMAC_CLKCTRL_STBYST_STANDBY                                                                  (1U)

#define CM_GMAC_GMAC_CLKCTRL_MODULEMODE_SHIFT                                                               (0U)
#define CM_GMAC_GMAC_CLKCTRL_MODULEMODE_MASK                                                                (0x00000003U)
#define CM_GMAC_GMAC_CLKCTRL_MODULEMODE_DISABLED                                                             (0U)
#define CM_GMAC_GMAC_CLKCTRL_MODULEMODE_RESERVED_1                                                           (1U)
#define CM_GMAC_GMAC_CLKCTRL_MODULEMODE_ENABLED                                                              (2U)
#define CM_GMAC_GMAC_CLKCTRL_MODULEMODE_RESERVED                                                             (3U)

#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_RFT_SHIFT                                                               (25U)
#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_RFT_MASK                                                                (0x0e000000U)
#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_RFT_SEL_VIDEO1_CLK                                                       (0U)
#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_RFT_SEL_VIDEO2_CLK                                                       (1U)
#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_RFT_SEL_PER_ABE_X1_GFCLK                                                 (2U)
#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_RFT_SEL_HDMI_CLK                                                         (3U)
#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_RFT_SEL_L3_ICLK                                                          (4U)
#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_RFT_RESERVED                                                             (5U)
#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_RFT_RESERVED1                                                            (6U)
#define CM_GMAC_GMAC_CLKCTRL_CLKSEL_RFT_RESERVED2                                                            (7U)

#define CM_L3INIT_OCP2SCP1_CLKCTRL_IDLEST_SHIFT                                    (16U)
#define CM_L3INIT_OCP2SCP1_CLKCTRL_IDLEST_MASK                                     (0x00030000U)
#define CM_L3INIT_OCP2SCP1_CLKCTRL_IDLEST_DISABLE                                   (3U)
#define CM_L3INIT_OCP2SCP1_CLKCTRL_IDLEST_IDLE                                      (2U)
#define CM_L3INIT_OCP2SCP1_CLKCTRL_IDLEST_FUNC                                      (0U)
#define CM_L3INIT_OCP2SCP1_CLKCTRL_IDLEST_TRANS                                     (1U)

#define CM_L3INIT_OCP2SCP1_CLKCTRL_MODULEMODE_SHIFT                                (0U)
#define CM_L3INIT_OCP2SCP1_CLKCTRL_MODULEMODE_MASK                                 (0x00000003U)
#define CM_L3INIT_OCP2SCP1_CLKCTRL_MODULEMODE_DISABLED                              (0U)
#define CM_L3INIT_OCP2SCP1_CLKCTRL_MODULEMODE_AUTO                                  (1U)
#define CM_L3INIT_OCP2SCP1_CLKCTRL_MODULEMODE_RESERVED_2                            (2U)
#define CM_L3INIT_OCP2SCP1_CLKCTRL_MODULEMODE_RESERVED                              (3U)

#define CM_L3INIT_OCP2SCP3_CLKCTRL_IDLEST_SHIFT                                    (16U)
#define CM_L3INIT_OCP2SCP3_CLKCTRL_IDLEST_MASK                                     (0x00030000U)
#define CM_L3INIT_OCP2SCP3_CLKCTRL_IDLEST_DISABLE                                   (3U)
#define CM_L3INIT_OCP2SCP3_CLKCTRL_IDLEST_IDLE                                      (2U)
#define CM_L3INIT_OCP2SCP3_CLKCTRL_IDLEST_FUNC                                      (0U)
#define CM_L3INIT_OCP2SCP3_CLKCTRL_IDLEST_TRANS                                     (1U)

#define CM_L3INIT_OCP2SCP3_CLKCTRL_MODULEMODE_SHIFT                                (0U)
#define CM_L3INIT_OCP2SCP3_CLKCTRL_MODULEMODE_MASK                                 (0x00000003U)
#define CM_L3INIT_OCP2SCP3_CLKCTRL_MODULEMODE_DISABLED                              (0U)
#define CM_L3INIT_OCP2SCP3_CLKCTRL_MODULEMODE_AUTO                                  (1U)
#define CM_L3INIT_OCP2SCP3_CLKCTRL_MODULEMODE_RESERVED_2                            (2U)
#define CM_L3INIT_OCP2SCP3_CLKCTRL_MODULEMODE_RESERVED                              (3U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_L3INIT_CM_CORE_H_ */

