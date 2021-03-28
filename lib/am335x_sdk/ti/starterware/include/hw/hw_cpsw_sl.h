/*
* hw_cpsw_sl.h
*
* Register-level header file for CPSW_SL
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

#ifndef HW_CPSW_SL_H_
#define HW_CPSW_SL_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define CPSW_SL_RX_PAUSE                                            (0x18U)
#define CPSW_SL_RX_MAXLEN                                           (0x10U)
#define CPSW_SL_TX_GAP                                              (0x28U)
#define CPSW_SL_TX_PAUSE                                            (0x1cU)
#define CPSW_SL_IDVER                                               (0x0U)
#define CPSW_SL_RX_PRI_MAP                                          (0x24U)
#define CPSW_SL_EMCTRL                                              (0x20U)
#define CPSW_SL_MACSTS                                              (0x8U)
#define CPSW_SL_SOFT_RESET                                          (0xcU)
#define CPSW_SL_BOFFTEST                                            (0x14U)
#define CPSW_SL_MACCTRL                                             (0x4U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define CPSW_SL_RX_PAUSE_PAUSETIMER_SHIFT                                               (0U)
#define CPSW_SL_RX_PAUSE_PAUSETIMER_MASK                                                (0x0000ffffU)

#define CPSW_SL_RX_MAXLEN_SHIFT                                                         (0U)
#define CPSW_SL_RX_MAXLEN_MASK                                                          (0x00003fffU)

#define CPSW_SL_TX_GAP_SHIFT                                                            (0U)
#define CPSW_SL_TX_GAP_MASK                                                             (0x000001ffU)

#define CPSW_SL_TX_PAUSE_PAUSETIMER_SHIFT                                               (0U)
#define CPSW_SL_TX_PAUSE_PAUSETIMER_MASK                                                (0x0000ffffU)

#define CPSW_SL_IDVER_Y_SHIFT                                                           (0U)
#define CPSW_SL_IDVER_Y_MASK                                                            (0x000000ffU)

#define CPSW_SL_IDVER_X_SHIFT                                                           (8U)
#define CPSW_SL_IDVER_X_MASK                                                            (0x00000700U)

#define CPSW_SL_IDVER_Z_SHIFT                                                           (11U)
#define CPSW_SL_IDVER_Z_MASK                                                            (0x0000f800U)

#define CPSW_SL_IDVER_IDENT_SHIFT                                                       (16U)
#define CPSW_SL_IDVER_IDENT_MASK                                                        (0xffff0000U)

#define CPSW_SL_RX_PRI_MAP_PRI0_SHIFT                                                   (0U)
#define CPSW_SL_RX_PRI_MAP_PRI0_MASK                                                    (0x00000007U)

#define CPSW_SL_RX_PRI_MAP_PRI1_SHIFT                                                   (4U)
#define CPSW_SL_RX_PRI_MAP_PRI1_MASK                                                    (0x00000070U)

#define CPSW_SL_RX_PRI_MAP_PRI2_SHIFT                                                   (8U)
#define CPSW_SL_RX_PRI_MAP_PRI2_MASK                                                    (0x00000700U)

#define CPSW_SL_RX_PRI_MAP_PRI3_SHIFT                                                   (12U)
#define CPSW_SL_RX_PRI_MAP_PRI3_MASK                                                    (0x00007000U)

#define CPSW_SL_RX_PRI_MAP_PRI4_SHIFT                                                   (16U)
#define CPSW_SL_RX_PRI_MAP_PRI4_MASK                                                    (0x00070000U)

#define CPSW_SL_RX_PRI_MAP_PRI5_SHIFT                                                   (20U)
#define CPSW_SL_RX_PRI_MAP_PRI5_MASK                                                    (0x00700000U)

#define CPSW_SL_RX_PRI_MAP_PRI6_SHIFT                                                   (24U)
#define CPSW_SL_RX_PRI_MAP_PRI6_MASK                                                    (0x07000000U)

#define CPSW_SL_RX_PRI_MAP_PRI7_SHIFT                                                   (28U)
#define CPSW_SL_RX_PRI_MAP_PRI7_MASK                                                    (0x70000000U)

#define CPSW_SL_EMCTRL_FREE_SHIFT                                                       (0U)
#define CPSW_SL_EMCTRL_FREE_MASK                                                        (0x00000001U)

#define CPSW_SL_EMCTRL_SOFT_SHIFT                                                       (1U)
#define CPSW_SL_EMCTRL_SOFT_MASK                                                        (0x00000002U)

#define CPSW_SL_MACSTS_TX_FLOW_ACT_SHIFT                                                (0U)
#define CPSW_SL_MACSTS_TX_FLOW_ACT_MASK                                                 (0x00000001U)

#define CPSW_SL_MACSTS_RX_FLOW_ACT_SHIFT                                                (1U)
#define CPSW_SL_MACSTS_RX_FLOW_ACT_MASK                                                 (0x00000002U)

#define CPSW_SL_MACSTS_EXT_FULLDUPLEX_SHIFT                                             (3U)
#define CPSW_SL_MACSTS_EXT_FULLDUPLEX_MASK                                              (0x00000008U)

#define CPSW_SL_MACSTS_EXT_GIG_SHIFT                                                    (4U)
#define CPSW_SL_MACSTS_EXT_GIG_MASK                                                     (0x00000010U)

#define CPSW_SL_MACSTS_IDLE_SHIFT                                                       (31U)
#define CPSW_SL_MACSTS_IDLE_MASK                                                        (0x80000000U)

#define CPSW_SL_SOFT_RESET_SHIFT                                                        (0U)
#define CPSW_SL_SOFT_RESET_MASK                                                         (0x00000001U)
#define CPSW_SL_SOFT_RESET_IN_PROGRESS                                                   (1U)
#define CPSW_SL_SOFT_RESET_DONE                                                          (0U)

#define CPSW_SL_BOFFTEST_TX_BACKOFF_SHIFT                                               (0U)
#define CPSW_SL_BOFFTEST_TX_BACKOFF_MASK                                                (0x000003ffU)

#define CPSW_SL_BOFFTEST_COLL_COUNT_SHIFT                                               (12U)
#define CPSW_SL_BOFFTEST_COLL_COUNT_MASK                                                (0x0000f000U)

#define CPSW_SL_BOFFTEST_RNDNUM_SHIFT                                                   (16U)
#define CPSW_SL_BOFFTEST_RNDNUM_MASK                                                    (0x03ff0000U)

#define CPSW_SL_BOFFTEST_PACEVAL_SHIFT                                                  (26U)
#define CPSW_SL_BOFFTEST_PACEVAL_MASK                                                   (0x7c000000U)

#define CPSW_SL_MACCTRL_FULLDUPLEX_SHIFT                                                (0U)
#define CPSW_SL_MACCTRL_FULLDUPLEX_MASK                                                 (0x00000001U)
#define CPSW_SL_MACCTRL_FULLDUPLEX_ENABLE                                                (1U)
#define CPSW_SL_MACCTRL_FULLDUPLEX_DISABLE                                               (0U)

#define CPSW_SL_MACCTRL_LOOPBACK_SHIFT                                                  (1U)
#define CPSW_SL_MACCTRL_LOOPBACK_MASK                                                   (0x00000002U)

#define CPSW_SL_MACCTRL_MTEST_SHIFT                                                     (2U)
#define CPSW_SL_MACCTRL_MTEST_MASK                                                      (0x00000004U)

#define CPSW_SL_MACCTRL_RX_FLOW_EN_SHIFT                                                (3U)
#define CPSW_SL_MACCTRL_RX_FLOW_EN_MASK                                                 (0x00000008U)

#define CPSW_SL_MACCTRL_TX_FLOW_EN_SHIFT                                                (4U)
#define CPSW_SL_MACCTRL_TX_FLOW_EN_MASK                                                 (0x00000010U)

#define CPSW_SL_MACCTRL_GMII_EN_SHIFT                                                   (5U)
#define CPSW_SL_MACCTRL_GMII_EN_MASK                                                    (0x00000020U)
#define CPSW_SL_MACCTRL_GMII_EN_ENABLE                                                   (1U)
#define CPSW_SL_MACCTRL_GMII_EN_DISABLE                                                  (0U)

#define CPSW_SL_MACCTRL_TX_PACE_SHIFT                                                   (6U)
#define CPSW_SL_MACCTRL_TX_PACE_MASK                                                    (0x00000040U)

#define CPSW_SL_MACCTRL_GIG_SHIFT                                                       (7U)
#define CPSW_SL_MACCTRL_GIG_MASK                                                        (0x00000080U)
#define CPSW_SL_MACCTRL_GIG_ENABLE                                                       (1U)
#define CPSW_SL_MACCTRL_GIG_DISABLE                                                      (0U)

#define CPSW_SL_MACCTRL_TX_SHORT_GAP_EN_SHIFT                                           (10U)
#define CPSW_SL_MACCTRL_TX_SHORT_GAP_EN_MASK                                            (0x00000400U)

#define CPSW_SL_MACCTRL_CMD_IDLE_SHIFT                                                  (11U)
#define CPSW_SL_MACCTRL_CMD_IDLE_MASK                                                   (0x00000800U)

#define CPSW_SL_MACCTRL_IFCTL_A_SHIFT                                                   (15U)
#define CPSW_SL_MACCTRL_IFCTL_A_MASK                                                    (0x00008000U)
#define CPSW_SL_MACCTRL_IFCTL_A_100                                                      (1U)
#define CPSW_SL_MACCTRL_IFCTL_A_10                                                       (0U)

#define CPSW_SL_MACCTRL_IFCTL_B_SHIFT                                                   (16U)
#define CPSW_SL_MACCTRL_IFCTL_B_MASK                                                    (0x00010000U)
#define CPSW_SL_MACCTRL_IFCTL_B_100                                                      (1U)
#define CPSW_SL_MACCTRL_IFCTL_B_10                                                       (0U)

#define CPSW_SL_MACCTRL_GIG_FORCE_SHIFT                                                 (17U)
#define CPSW_SL_MACCTRL_GIG_FORCE_MASK                                                  (0x00020000U)
#define CPSW_SL_MACCTRL_GIG_FORCE_ENABLE                                                 (1U)
#define CPSW_SL_MACCTRL_GIG_FORCE_DISABLE                                                (0U)

#define CPSW_SL_MACCTRL_EXT_EN_SHIFT                                                    (18U)
#define CPSW_SL_MACCTRL_EXT_EN_MASK                                                     (0x00040000U)
#define CPSW_SL_MACCTRL_EXT_EN_ENABLE                                                    (1U)
#define CPSW_SL_MACCTRL_EXT_EN_DISABLE                                                   (0U)

#define CPSW_SL_MACCTRL_TX_SHORT_GAP_LIM_EN_SHIFT                                       (21U)
#define CPSW_SL_MACCTRL_TX_SHORT_GAP_LIM_EN_MASK                                        (0x00200000U)

#define CPSW_SL_MACCTRL_RX_CEF_EN_SHIFT                                                 (22U)
#define CPSW_SL_MACCTRL_RX_CEF_EN_MASK                                                  (0x00400000U)

#define CPSW_SL_MACCTRL_RX_CSF_EN_SHIFT                                                 (23U)
#define CPSW_SL_MACCTRL_RX_CSF_EN_MASK                                                  (0x00800000U)

#define CPSW_SL_MACCTRL_RX_CMF_EN_SHIFT                                                 (24U)
#define CPSW_SL_MACCTRL_RX_CMF_EN_MASK                                                  (0x01000000U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CPSW_SL_H_ */

