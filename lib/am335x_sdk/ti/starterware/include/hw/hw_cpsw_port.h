/*
* hw_cpsw_port.h
*
* Register-level header file for CPSW_PORT
*
* Copyright (C) 2013 - 2019 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef HW_CPSW_PORT_H_
#define HW_CPSW_PORT_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define CPSW_PORT_P_SA_LO(n)                                        (0x20U + ((n) * 0x100U))
#define CPSW_PORT_P_MAX_BLKS(n)                                     (0x8U + ((n) * 0x100U))
#define CPSW_PORT_P_SA_HI(n)                                        (0x24U + ((n) * 0x100U))
#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP                               (0x1cU)
#define CPSW_PORT_P_BLK_CNT(n)                                      (0xcU + ((n) * 0x100U))
#define CPSW_PORT_P_RX_DSCP_PRI_MAP(n, m)                           (0x30U + ((m) * 0x4U) + ((n) * 0x100U))
#define CPSW_PORT_P_TX_IN_CTL(n)                                    (0x10U + ((n) * 0x100U))
#define CPSW_PORT_P_SEND_PERCENT(n)                                 (0x28U + ((n) * 0x100U))
#define CPSW_PORT_P_VLAN(n)                                         (0x14U + ((n) * 0x100U))
#define CPSW_PORT_P_TX_PRI_MAP(n)                                   (0x18U + ((n) * 0x100U))
#define CPSW_PORT_P_TS_SEQ_MTYPE(n)                                 (0x1cU + ((n) * 0x100U))
#define CPSW_PORT_P_CTRL(n)                                         (0x0U + ((n) * 0x100U))
#define CPSW_PORT_P0_CPDMA_RX_CH_MAP                                (0x20U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define CPSW_PORT_P_SA_LO_MACSRCADDR_15_8_SHIFT                                         (0U)
#define CPSW_PORT_P_SA_LO_MACSRCADDR_15_8_MASK                                          (0x000000ffU)

#define CPSW_PORT_P_SA_LO_MACSRCADDR_7_0_SHIFT                                          (8U)
#define CPSW_PORT_P_SA_LO_MACSRCADDR_7_0_MASK                                           (0x0000ff00U)

#define CPSW_PORT_P_MAX_BLKS_RX_SHIFT                                                   (0U)
#define CPSW_PORT_P_MAX_BLKS_RX_MASK                                                    (0x0000000fU)

#define CPSW_PORT_P_MAX_BLKS_TX_SHIFT                                                   (4U)
#define CPSW_PORT_P_MAX_BLKS_TX_MASK                                                    (0x000001f0U)

#define CPSW_PORT_P_SA_HI_MACSRCADDR_47_40_SHIFT                                        (0U)
#define CPSW_PORT_P_SA_HI_MACSRCADDR_47_40_MASK                                         (0x000000ffU)

#define CPSW_PORT_P_SA_HI_MACSRCADDR_39_32_SHIFT                                        (8U)
#define CPSW_PORT_P_SA_HI_MACSRCADDR_39_32_MASK                                         (0x0000ff00U)

#define CPSW_PORT_P_SA_HI_MACSRCADDR_31_24_SHIFT                                        (16U)
#define CPSW_PORT_P_SA_HI_MACSRCADDR_31_24_MASK                                         (0x00ff0000U)

#define CPSW_PORT_P_SA_HI_MACSRCADDR_23_16_SHIFT                                        (24U)
#define CPSW_PORT_P_SA_HI_MACSRCADDR_23_16_MASK                                         (0xff000000U)

#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI0_SHIFT                                        (0U)
#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI0_MASK                                         (0x00000007U)

#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI1_SHIFT                                        (4U)
#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI1_MASK                                         (0x00000070U)

#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI2_SHIFT                                        (8U)
#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI2_MASK                                         (0x00000700U)

#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI3_SHIFT                                        (12U)
#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI3_MASK                                         (0x00007000U)

#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI4_SHIFT                                        (16U)
#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI4_MASK                                         (0x00070000U)

#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI5_SHIFT                                        (20U)
#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI5_MASK                                         (0x00700000U)

#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI6_SHIFT                                        (24U)
#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI6_MASK                                         (0x07000000U)

#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI7_SHIFT                                        (28U)
#define CPSW_PORT_P0_CPDMA_TX_PRI_MAP_PRI7_MASK                                         (0x70000000U)

#define CPSW_PORT_P_BLK_CNT_RX_SHIFT                                                    (0U)
#define CPSW_PORT_P_BLK_CNT_RX_MASK                                                     (0x0000000fU)

#define CPSW_PORT_P_BLK_CNT_TX_SHIFT                                                    (4U)
#define CPSW_PORT_P_BLK_CNT_TX_MASK                                                     (0x000001f0U)

#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI0_SHIFT                                          (0U)
#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI0_MASK                                           (0x00000007U)

#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI1_SHIFT                                          (4U)
#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI1_MASK                                           (0x00000070U)

#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI2_SHIFT                                          (8U)
#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI2_MASK                                           (0x00000700U)

#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI3_SHIFT                                          (12U)
#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI3_MASK                                           (0x00007000U)

#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI4_SHIFT                                          (16U)
#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI4_MASK                                           (0x00070000U)

#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI5_SHIFT                                          (20U)
#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI5_MASK                                           (0x00700000U)

#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI6_SHIFT                                          (24U)
#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI6_MASK                                           (0x07000000U)

#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI7_SHIFT                                          (28U)
#define CPSW_PORT_P_RX_DSCP_PRI_MAP_PRI7_MASK                                           (0x70000000U)

#define CPSW_PORT_P_TX_IN_CTL_PRI_WDS_SHIFT                                             (0U)
#define CPSW_PORT_P_TX_IN_CTL_PRI_WDS_MASK                                              (0x000003ffU)

#define CPSW_PORT_P_TX_IN_CTL_BLKS_REM_SHIFT                                            (12U)
#define CPSW_PORT_P_TX_IN_CTL_BLKS_REM_MASK                                             (0x0000f000U)

#define CPSW_PORT_P_TX_IN_CTL_SEL_SHIFT                                                 (16U)
#define CPSW_PORT_P_TX_IN_CTL_SEL_MASK                                                  (0x00030000U)
#define CPSW_PORT_P_TX_IN_CTL_SEL_EN_0x1                                                 (1U)

#define CPSW_PORT_P_TX_IN_CTL_RATE_EN_SHIFT                                             (20U)
#define CPSW_PORT_P_TX_IN_CTL_RATE_EN_MASK                                              (0x00f00000U)

#define CPSW_PORT_P_VLAN_VID_SHIFT                                                      (0U)
#define CPSW_PORT_P_VLAN_VID_MASK                                                       (0x00000fffU)

#define CPSW_PORT_P_VLAN_CFI_SHIFT                                                      (12U)
#define CPSW_PORT_P_VLAN_CFI_MASK                                                       (0x00001000U)

#define CPSW_PORT_P_VLAN_PRI_SHIFT                                                      (13U)
#define CPSW_PORT_P_VLAN_PRI_MASK                                                       (0x0000e000U)

#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P1_PRI0_SHIFT                                      (0U)
#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P1_PRI0_MASK                                       (0x00000007U)

#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P1_PRI1_SHIFT                                      (4U)
#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P1_PRI1_MASK                                       (0x00000070U)

#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P1_PRI2_SHIFT                                      (8U)
#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P1_PRI2_MASK                                       (0x00000700U)

#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P1_PRI3_SHIFT                                      (12U)
#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P1_PRI3_MASK                                       (0x00007000U)

#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P2_PRI0_SHIFT                                      (16U)
#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P2_PRI0_MASK                                       (0x00070000U)

#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P2_PRI1_SHIFT                                      (20U)
#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P2_PRI1_MASK                                       (0x00700000U)

#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P2_PRI2_SHIFT                                      (24U)
#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P2_PRI2_MASK                                       (0x07000000U)

#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P2_PRI3_SHIFT                                      (28U)
#define CPSW_PORT_P0_CPDMA_RX_CH_MAP_P2_PRI3_MASK                                       (0x70000000U)

#define CPSW_PORT_P_TX_PRI_MAP_PRI0_SHIFT                                               (0U)
#define CPSW_PORT_P_TX_PRI_MAP_PRI0_MASK                                                (0x00000003U)

#define CPSW_PORT_P_TX_PRI_MAP_PRI1_SHIFT                                               (4U)
#define CPSW_PORT_P_TX_PRI_MAP_PRI1_MASK                                                (0x00000030U)

#define CPSW_PORT_P_TX_PRI_MAP_PRI2_SHIFT                                               (8U)
#define CPSW_PORT_P_TX_PRI_MAP_PRI2_MASK                                                (0x00000300U)

#define CPSW_PORT_P_TX_PRI_MAP_PRI3_SHIFT                                               (12U)
#define CPSW_PORT_P_TX_PRI_MAP_PRI3_MASK                                                (0x00003000U)

#define CPSW_PORT_P_TX_PRI_MAP_PRI4_SHIFT                                               (16U)
#define CPSW_PORT_P_TX_PRI_MAP_PRI4_MASK                                                (0x00030000U)

#define CPSW_PORT_P_TX_PRI_MAP_PRI5_SHIFT                                               (20U)
#define CPSW_PORT_P_TX_PRI_MAP_PRI5_MASK                                                (0x00300000U)

#define CPSW_PORT_P_TX_PRI_MAP_PRI6_SHIFT                                               (24U)
#define CPSW_PORT_P_TX_PRI_MAP_PRI6_MASK                                                (0x03000000U)

#define CPSW_PORT_P_TX_PRI_MAP_PRI7_SHIFT                                               (28U)
#define CPSW_PORT_P_TX_PRI_MAP_PRI7_MASK                                                (0x30000000U)

#define CPSW_PORT_P_TS_SEQ_MTYPE_MSG_TYPE_EN_SHIFT                                      (0U)
#define CPSW_PORT_P_TS_SEQ_MTYPE_MSG_TYPE_EN_MASK                                       (0x0000ffffU)

#define CPSW_PORT_P_TS_SEQ_MTYPE_ID_OFFSET_SHIFT                                        (16U)
#define CPSW_PORT_P_TS_SEQ_MTYPE_ID_OFFSET_MASK                                         (0x003f0000U)

#define CPSW_PORT_P_CTRL_DSCP_PRI_EN_SHIFT                                              (16U)
#define CPSW_PORT_P_CTRL_DSCP_PRI_EN_MASK                                               (0x00010000U)

#define CPSW_PORT_P_CTRL_VLAN_LTYPE1_EN_SHIFT                                           (20U)
#define CPSW_PORT_P_CTRL_VLAN_LTYPE1_EN_MASK                                            (0x00100000U)

#define CPSW_PORT_P_CTRL_VLAN_LTYPE2_EN_SHIFT                                           (21U)
#define CPSW_PORT_P_CTRL_VLAN_LTYPE2_EN_MASK                                            (0x00200000U)

#define CPSW_PORT_P_CTRL_PASS_PRI_TAGGED_SHIFT                                          (24U)
#define CPSW_PORT_P_CTRL_PASS_PRI_TAGGED_MASK                                           (0x01000000U)

#define CPSW_PORT_P_CTRL_DLR_CPDMA_CH_SHIFT                                             (28U)
#define CPSW_PORT_P_CTRL_DLR_CPDMA_CH_MASK                                              (0x70000000U)

#define CPSW_PORT_P_SEND_PERCENT_PRI1_SHIFT                                             (0U)
#define CPSW_PORT_P_SEND_PERCENT_PRI1_MASK                                              (0x0000007fU)

#define CPSW_PORT_P_SEND_PERCENT_PRI2_SHIFT                                             (8U)
#define CPSW_PORT_P_SEND_PERCENT_PRI2_MASK                                              (0x00007f00U)

#define CPSW_PORT_P_SEND_PERCENT_PRI3_SHIFT                                             (16U)
#define CPSW_PORT_P_SEND_PERCENT_PRI3_MASK                                              (0x007f0000U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CPSW_PORT_H_ */

