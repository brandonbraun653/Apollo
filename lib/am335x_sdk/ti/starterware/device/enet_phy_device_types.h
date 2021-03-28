/**
 *  \file  enet_phy_device_types.h
 *
 *  \brief This file contains the register definitions of Ethernet PHY.
 *
 *  \copyright Copyright (C) 2013 - 2019 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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

#ifndef ENET_PHY_DEVICE_TYPES_H_
#define ENET_PHY_DEVICE_TYPES_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

#define ENET_PHY_DEV_BMC                                        (0x00U)
#define ENET_PHY_DEV_BMS                                        (0x01U)
#define ENET_PHY_DEV_ID1                                        (0x02U)
#define ENET_PHY_DEV_ID2                                        (0x03U)
#define ENET_PHY_DEV_AUTO_NEG_ADV                               (0x04U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY              (0x05U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION                         (0x06U)
#define ENET_PHY_DEV_AUTO_NEG_NEXT_PAGE_TX                      (0x07U)
#define ENET_PHY_DEV_LINK_PARTNER_NEXT_PAGE                     (0x08U)
#define ENET_PHY_DEV_GIG_CTRL                                   (0x09U)
#define ENET_PHY_DEV_GIG_STS                                    (0x0AU)
#define ENET_PHY_DEV_EXTENDED_STS                               (0x0FU)
#define ENET_PHY_DEV_CTRL2                                      (0x12U)
#define ENET_PHY_DEV_LOOPBACK_CTRL2                             (0x13U)
#define ENET_PHY_DEV_RX_ERR_CNT                                 (0x14U)
#define ENET_PHY_DEV_MI_CTRL                                    (0x15U)
#define ENET_PHY_DEV_CFG                                        (0x16U)
#define ENET_PHY_DEV_CTRL                                       (0x17U)
#define ENET_PHY_DEV_INTR_MASK                                  (0x18U)
#define ENET_PHY_DEV_INTR_STS                                   (0x19U)
#define ENET_PHY_DEV_STS                                        (0x1AU)
#define ENET_PHY_DEV_LED_CTRL(n)                                (0x1BU + ((n) * 0x1U))
#define ENET_PHY_DEV_DIAGNOSTICS_CTRL                           (0x1EU)
#define ENET_PHY_DEV_DIAGNOSTICS_STS                            (0x1FU)

#define ENET_PHY_DEV_BMC                                        (0x00U)

#define ENET_PHY_DEV_BMC_SPEED_MASK                             (0x2040U)
#define ENET_PHY_DEV_BMC_SPEED_SHIFT                            (6U)
#define ENET_PHY_DEV_BMC_SPEED_10                                (0x00U)
#define ENET_PHY_DEV_BMC_SPEED_100                               (0x80U)
#define ENET_PHY_DEV_BMC_SPEED_1000                              (0x01U)

#define ENET_PHY_DEV_BMC_COLLISON_TEST_MASK                     (0x0080U)
#define ENET_PHY_DEV_BMC_COLLISON_TEST_SHIFT                    (7U)
#define ENET_PHY_DEV_BMC_COLLISON_TEST_ENABLE                    (1U)
#define ENET_PHY_DEV_BMC_COLLISON_TEST_DISABLE                   (0U)

#define ENET_PHY_DEV_BMC_DUPLEX_MODE_MASK                       (0x0100U)
#define ENET_PHY_DEV_BMC_DUPLEX_MODE_SHIFT                      (8U)
#define ENET_PHY_DEV_BMC_DUPLEX_MODE_FULL                        (1U)
#define ENET_PHY_DEV_BMC_DUPLEX_MODE_HALF                        (0U)

#define ENET_PHY_DEV_BMC_RESTART_AUTONEG_MASK                   (0x0200U)
#define ENET_PHY_DEV_BMC_RESTART_AUTONEG_SHIFT                  (9U)
#define ENET_PHY_DEV_BMC_RESTART_AUTONEG_ENABLE                  (1U)
#define ENET_PHY_DEV_BMC_RESTART_AUTONEG_DISABLE                 (0U)

#define ENET_PHY_DEV_BMC_ISOLATE_MASK                           (0x0400U)
#define ENET_PHY_DEV_BMC_ISOLATE_SHIFT                          (10U)
#define ENET_PHY_DEV_BMC_ISOLATE_ENABLE                          (1U)
#define ENET_PHY_DEV_BMC_ISOLATE_DISABLE                         (0U)

#define ENET_PHY_DEV_BMC_PWR_DWN_MASK                           (0x0800U)
#define ENET_PHY_DEV_BMC_PWR_DWN_SHIFT                          (11U)
#define ENET_PHY_DEV_BMC_PWR_DWN_ENABLE                          (1U)
#define ENET_PHY_DEV_BMC_PWR_DWN_DISABLE                         (0U)

#define ENET_PHY_DEV_BMC_AUTONEG_ENABLE_MASK                    (0x1000U)
#define ENET_PHY_DEV_BMC_AUTONEG_ENABLE_SHIFT                   (12U)
#define ENET_PHY_DEV_BMC_AUTONEG_ENABLE                          (1U)
#define ENET_PHY_DEV_BMC_AUTONEG_DISABLE                         (0U)

#define ENET_PHY_DEV_BMC_LOOPBACK_MASK                          (0x4000U)
#define ENET_PHY_DEV_BMC_LOOPBACK_SHIFT                         (14U)
#define ENET_PHY_DEV_BMC_LOOPBACK_ENABLE                         (1U)
#define ENET_PHY_DEV_BMC_LOOPBACK_DISABLE                        (0U)

#define ENET_PHY_DEV_BMC_RESET_MASK                             (0x8000U)
#define ENET_PHY_DEV_BMC_RESET_SHIFT                            (15U)
#define ENET_PHY_DEV_BMC_RESET_ENABLE                            (1U)
#define ENET_PHY_DEV_BMC_RESET_DISABLE                           (0U)

#define ENET_PHY_DEV_BMS                                        (0x01U)

#define ENET_PHY_DEV_BMS_EXTENDED_CAPABILITY_MASK               (0x0001U)
#define ENET_PHY_DEV_BMS_EXTENDED_CAPABILITY_SHIFT              (0U)
#define ENET_PHY_DEV_BMS_EXTENDED_CAPABILITY_ENABLE              (1U)
#define ENET_PHY_DEV_BMS_EXTENDED_CAPABILITY_DISABLE             (0U)

#define ENET_PHY_DEV_BMS_JABBER_MASK                            (0x0002U)
#define ENET_PHY_DEV_BMS_JABBER_SHIFT                           (1U)
#define ENET_PHY_DEV_BMS_JABBER_DETECTED                         (1U)
#define ENET_PHY_DEV_BMS_JABBER_NOT_DETECTED                     (0U)

#define ENET_PHY_DEV_BMS_LINKS_STS_MASK                         (0x0004U)
#define ENET_PHY_DEV_BMS_LINKS_STS_SHIFT                        (2U)
#define ENET_PHY_DEV_BMS_LINKS_STS_UP                            (1U)
#define ENET_PHY_DEV_BMS_LINKS_STS_DWN                           (0U)

#define ENET_PHY_DEV_BMS_AUTONEG_ABILITY_MASK                   (0x0008U)
#define ENET_PHY_DEV_BMS_AUTONEG_ABILITY_SHIFT                  (3U)
#define ENET_PHY_DEV_BMS_AUTONEG_ABILITY_CAPABLE                 (1U)
#define ENET_PHY_DEV_BMS_AUTONEG_ABILITY_NOT_CAPABLE             (0U)

#define ENET_PHY_DEV_BMS_REMOTE_FAULT_MASK                      (0x0010U)
#define ENET_PHY_DEV_BMS_REMOTE_FAULT_SHIFT                     (4U)
#define ENET_PHY_DEV_BMS_REMOTE_FAULT_DETECTED                   (1U)
#define ENET_PHY_DEV_BMS_REMOTE_FAULT_NOT_DETECTED               (0U)

#define ENET_PHY_DEV_BMS_AUTONEG_PROCESS_MASK                   (0x0020U)
#define ENET_PHY_DEV_BMS_AUTONEG_PROCESS_SHIFT                  (5U)
#define ENET_PHY_DEV_BMS_AUTONEG_PROCESS_COMPLETE                (1U)
#define ENET_PHY_DEV_BMS_AUTONEG_PROCESS_NOT_COMPLETE            (0U)

#define ENET_PHY_DEV_BMS_MF_PREAMBLE_SUPRESS_MASK               (0x0040U)
#define ENET_PHY_DEV_BMS_MF_PREAMBLE_SUPRESS_SHIFT              (6U)
#define ENET_PHY_DEV_BMS_MF_PREAMBLE_SUPRESS_ACCEPTED            (1U)
#define ENET_PHY_DEV_BMS_MF_PREAMBLE_SUPRESS_NOT_ACCEPTED        (0U)

#define ENET_PHY_DEV_BMS_EXTENDED_STS_MASK                      (0x0100U)
#define ENET_PHY_DEV_BMS_EXTENDED_STS_SHIFT                     (8U)
#define ENET_PHY_DEV_BMS_EXTENDED_STS_ENABLE                     (1U)
#define ENET_PHY_DEV_BMS_EXTENDED_STS_DISABLE                    (0U)

#define ENET_PHY_DEV_BMS_100_T2_HALF_MASK                       (0x0200U)
#define ENET_PHY_DEV_BMS_100_T2_HALF_SHIFT                      (9U)
#define ENET_PHY_DEV_BMS_100_T2_HALF_CAPABLE                     (1U)
#define ENET_PHY_DEV_BMS_100_T2_HALF_NOT_CAPABLE                 (0U)

#define ENET_PHY_DEV_BMS_100_T2_FULL_MASK                       (0x0400U)
#define ENET_PHY_DEV_BMS_100_T2_FULL_SHIFT                      (10U)
#define ENET_PHY_DEV_BMS_100_T2_FULL_CAPABLE                     (1U)
#define ENET_PHY_DEV_BMS_100_T2_FULL_NOT_CAPABLE                 (0U)

#define ENET_PHY_DEV_BMS_10_T_HALF_MASK                         (0x0800U)
#define ENET_PHY_DEV_BMS_10_T_HALF_SHIFT                        (11U)
#define ENET_PHY_DEV_BMS_10_T_HALF_CAPABLE                       (1U)
#define ENET_PHY_DEV_BMS_10_T_HALF_NOT_CAPABLE                   (0U)

#define ENET_PHY_DEV_BMS_10_T_FULL_MASK                         (0x1000U)
#define ENET_PHY_DEV_BMS_10_T_FULL_SHIFT                        (12U)
#define ENET_PHY_DEV_BMS_10_T_FULL_CAPABLE                       (1U)
#define ENET_PHY_DEV_BMS_10_T_FULL_NOT_CAPABLE                   (0U)

#define ENET_PHY_DEV_BMS_100_X_HALF_MASK                        (0x2000U)
#define ENET_PHY_DEV_BMS_100_X_HALF_SHIFT                       (13U)
#define ENET_PHY_DEV_BMS_100_X_HALF_CAPABLE                      (1U)
#define ENET_PHY_DEV_BMS_100_X_HALF_NOT_CAPABLE                  (0U)

#define ENET_PHY_DEV_BMS_100_X_FULL_MASK                        (0x4000U)
#define ENET_PHY_DEV_BMS_100_X_FULL_SHIFT                       (14U)
#define ENET_PHY_DEV_BMS_100_X_FULL_CAPABLE                      (1U)
#define ENET_PHY_DEV_BMS_100_X_FULL_NOT_CAPABLE                  (0U)

#define ENET_PHY_DEV_BMS_100_T4_MASK                            (0x8000U)
#define ENET_PHY_DEV_BMS_100_T4_SHIFT                           (15U)
#define ENET_PHY_DEV_BMS_100_T4_CAPABLE                          (1U)
#define ENET_PHY_DEV_BMS_100_T4_NOT_CAPABLE                      (0U)

#define ENET_PHY_DEV_ID1                                        (0x02U)

#define ENET_PHY_DEV_ID1_OUI_3_18_MASK                          (0xFFFFU)
#define ENET_PHY_DEV_ID1_OUI_3_18_SHIFT                         (0U)

#define ENET_PHY_DEV_ID2                                        (0x03U)

#define ENET_PHY_DEV_ID2_OUI_19_24_MASK                         (0xFC00U)
#define ENET_PHY_DEV_ID2_OUI_19_24_SHIFT                        (10U)
#define ENET_PHY_DEV_ID2_MODEL_NUM_MASK                         (0x03F0U)
#define ENET_PHY_DEV_ID2_MODEL_NUM_SHIFT                        (4U)
#define ENET_PHY_DEV_ID2_REV_NUM_MASK                           (0x000FU)
#define ENET_PHY_DEV_ID2_REV_NUM_SHIFT                          (0U)

#define ENET_PHY_DEV_AUTO_NEG_ADV                               (0x04U)

#define ENET_PHY_DEV_AUTO_NEG_ADV_SEL_MASK                      (0x001FU)
#define ENET_PHY_DEV_AUTO_NEG_ADV_SEL_SHIFT                     (0U)

#define ENET_PHY_DEV_AUTO_NEG_ADV_10_T_HALF_MASK                (0x0020U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_10_T_HALF_SHIFT               (5U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_10_T_HALF_CAPABLE              (1U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_10_T_HALF_NOT_CAPABLE          (0U)

#define ENET_PHY_DEV_AUTO_NEG_ADV_10_T_FULL_MASK                (0x0040U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_10_T_FULL_SHIFT               (6U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_10_T_FULL_CAPABLE              (1U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_10_T_FULL_NOT_CAPABLE          (0U)

#define ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_HALF_MASK              (0x0080U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_HALF_SHIFT             (7U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_HALF_CAPABLE            (1U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_HALF_NOT_CAPABLE        (0U)

#define ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_FULL_MASK              (0x0100U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_FULL_SHIFT             (8U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_FULL_CAPABLE            (1U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_100_TX_FULL_NOT_CAPABLE        (0U)

#define ENET_PHY_DEV_AUTO_NEG_ADV_100_T4_MASK                   (0x0200U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_100_T4_SHIFT                  (9U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_100_T4_CAPABLE                 (1U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_100_T4_NOT_CAPABLE             (0U)

#define ENET_PHY_DEV_AUTO_NEG_ADV_PAUSE_MASK                    (0x0400U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_PAUSE_SHIFT                   (10U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_PAUSE_CAPABLE                  (1U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_PAUSE_NOT_CAPABLE              (0U)

#define ENET_PHY_DEV_AUTO_NEG_ADV_ASYNC_PAUSE_MASK              (0x0800U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_ASYNC_PAUSE_SHIFT             (11U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_ASYNC_PAUSE_CAPABLE            (1U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_ASYNC_PAUSE_NOT_CAPABLE        (0U)

#define ENET_PHY_DEV_AUTO_NEG_ADV_REMOTE_FAULT_MASK             (0x2000U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_REMOTE_FAULT_SHIFT            (13U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_REMOTE_FAULT_DETECT            (1U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_REMOTE_FAULT_NOT_DETECT        (0U)

#define ENET_PHY_DEV_AUTO_NEG_ADV_NEXT_PAGE_MASK                (0x8000U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_NEXT_PAGE_SHIFT               (15U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_NEXT_PAGE_SUPPORT              (1U)
#define ENET_PHY_DEV_AUTO_NEG_ADV_NEXT_PAGE_NOT_SUPPORT          (0U)

#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY              (0x05U)

#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_SEL_MASK                     (0x001FU)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_SEL_SHIFT                    (0U)

#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_10_T_HALF_MASK               (0x0020U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_10_T_HALF_SHIFT              (5U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_10_T_HALF_CAPABLE             (1U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_10_T_HALF_NOT_CAPABLE         (0U)

#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_10_T_FULL_MASK               (0x0040U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_10_T_FULL_SHIFT              (6U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_10_T_FULL_CAPABLE             (1U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_10_T_FULL_NOT_CAPABLE         (0U)

#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_TX_HALF_MASK             (0x0080U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_TX_HALF_SHIFT            (7U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_TX_HALF_CAPABLE           (1U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_TX_HALF_NOT_CAPABLE       (0U)

#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_TX_FULL_MASK             (0x0100U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_TX_FULL_SHIFT            (8U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_TX_FULL_CAPABLE           (1U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_TX_FULL_NOT_CAPABLE       (0U)

#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_T4_MASK                  (0x0200U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_T4_SHIFT                 (9U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_T4_CAPABLE                (1U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_100_T4_NOT_CAPABLE            (0U)

#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_PAUSE_MASK                   (0x0400U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_PAUSE_SHIFT                  (10U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_PAUSE_CAPABLE                 (1U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_PAUSE_NOT_CAPABLE             (0U)

#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_ASYNC_PAUSE_MASK             (0x0800U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_ASYNC_PAUSE_SHIFT            (11U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_ASYNC_PAUSE_CAPABLE           (1U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_ASYNC_PAUSE_NOT_CAPABLE       (0U)

#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_REMOTE_FAULT_MASK            (0x2000U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_REMOTE_FAULT_SHIFT           (13U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_REMOTE_FAULT_DETECT           (1U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_REMOTE_FAULT_NOT_DETECT       (0U)

#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_ACK_MASK                     (0x4000U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_ACK_SHIFT                    (14U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_ACK_RECEIVED                  (1U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_ACK_NOT_RECEIVED              (0U)

#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_NEXT_PAGE_MASK               (0x8000U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_NEXT_PAGE_SHIFT              (15U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_NEXT_PAGE_SUPPORT             (1U)
#define ENET_PHY_DEV_AUTO_NEG_LINK_PARTNER_ABILITY_NEXT_PAGE_NOT_SUPPORT         (0U)

#define ENET_PHY_DEV_AUTO_NEG_EXPANSION                         (0x06U)

#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_AUTO_NEG_MASK           (0x0001U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_AUTO_NEG_SHIFT          (0U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_AUTO_NEG_CAPABLE         (1U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_AUTO_NEG_NOT_CAPABLE     (0U)

#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_PAGE_MASK               (0x0002U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_PAGE_SHIFT              (1U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_PAGE_REVEIVED            (1U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_PAGE_NOT_REVEIVED        (0U)

#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_NEXT_PAGE_MASK          (0x0004U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_NEXT_PAGE_SHIFT         (2U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_NEXT_PAGE_CAPABLE        (1U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_NEXT_PAGE_NOT_CAPABLE    (0U)

#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_LINK_NEXT_PAGE_MASK     (0x0008U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_LINK_NEXT_PAGE_SHIFT    (3U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_LINK_NEXT_PAGE_CAPABLE     (1U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_LINK_NEXT_PAGE_NOT_CAPABLE (0U)

#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_LINK_FAULT_MASK         (0x0010U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_LINK_FAULT_SHIFT        (4U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_LINK_FAULT_DETECTED      (1U)
#define ENET_PHY_DEV_AUTO_NEG_EXPANSION_LINK_FAULT_NOT_DETECTED  (0U)

#define ENET_PHY_DEV_AUTO_NEG_NEXT_PAGE_TX                      (0x07U)

#define ENET_PHY_DEV_LINK_PARTNER_NEXT_PAGE                     (0x08U)

#define ENET_PHY_DEV_GIG_CTRL                                   (0x09U)

#define ENET_PHY_DEV_GIG_CTRL_ADV_1000_HALF_MASK                (0x0100U)
#define ENET_PHY_DEV_GIG_CTRL_ADV_1000_HALF_SHIFT               (8U)
#define ENET_PHY_DEV_GIG_CTRL_ADV_1000_HALF_CAPABLE              (1U)
#define ENET_PHY_DEV_GIG_CTRL_ADV_1000_HALF_NOT_CAPABLE          (0U)

#define ENET_PHY_DEV_GIG_CTRL_ADV_1000_FULL_MASK                (0x0200U)
#define ENET_PHY_DEV_GIG_CTRL_ADV_1000_FULL_SHIFT               (9U)
#define ENET_PHY_DEV_GIG_CTRL_ADV_1000_FULL_CAPABLE              (1U)
#define ENET_PHY_DEV_GIG_CTRL_ADV_1000_FULL_NOT_CAPABLE          (0U)

#define ENET_PHY_DEV_GIG_CTRL_PORT_TYPE_MASK                    (0x0400U)
#define ENET_PHY_DEV_GIG_CTRL_PORT_TYPE_SHIFT                   (10U)
#define ENET_PHY_DEV_GIG_CTRL_PORT_TYPE_MULTI                    (1U)
#define ENET_PHY_DEV_GIG_CTRL_PORT_TYPE_SINGLE                   (0U)

#define ENET_PHY_DEV_GIG_CTRL_PHY_CONFIG_MASK                   (0x0800U)
#define ENET_PHY_DEV_GIG_CTRL_PHY_CONFIG_SHIFT                  (11U)
#define ENET_PHY_DEV_GIG_CTRL_PHY_CONFIG_MASTER                  (1U)
#define ENET_PHY_DEV_GIG_CTRL_PHY_CONFIG_SLAVE                   (0U)

#define ENET_PHY_DEV_GIG_CTRL_PHY_CONFIG_EN_MASK                (0x1000U)
#define ENET_PHY_DEV_GIG_CTRL_PHY_CONFIG_EN_SHIFT               (12U)
#define ENET_PHY_DEV_GIG_CTRL_PHY_CONFIG_EN_MANUAL               (1U)
#define ENET_PHY_DEV_GIG_CTRL_PHY_CONFIG_EN_AUTO                 (0U)

#define ENET_PHY_DEV_GIG_STS                                    (0x0AU)

#define ENET_PHY_DEV_GIG_STS_LINK_1000_HALF_MASK                (0x0400U)
#define ENET_PHY_DEV_GIG_STS_LINK_1000_HALF_SHIFT               (10U)
#define ENET_PHY_DEV_GIG_STS_LINK_1000_HALF_CAPABLE              (1U)
#define ENET_PHY_DEV_GIG_STS_LINK_1000_HALF_NOT_CAPABLE          (0U)

#define ENET_PHY_DEV_GIG_STS_LINK_1000_FULL_MASK                (0x0800U)
#define ENET_PHY_DEV_GIG_STS_LINK_1000_FULL_SHIFT               (11U)
#define ENET_PHY_DEV_GIG_STS_LINK_1000_FULL_CAPABLE              (1U)
#define ENET_PHY_DEV_GIG_STS_LINK_1000_FULL_NOT_CAPABLE          (0U)

#define ENET_PHY_DEV_EXTENDED_STS                               (0x0FU)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef ENET_PHY_DEVICE_TYPES_H_ */
