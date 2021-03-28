/*
* hw_cpsw_ss.h
*
* Register-level header file for CPSW_SS
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

#ifndef HW_CPSW_SS_H_
#define HW_CPSW_SS_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define CPSW_SS_PTYPE                                               (0x10U)
#define CPSW_SS_VLAN_LTYPE                                          (0x28U)
#define CPSW_SS_STAT_PORT_EN                                        (0xcU)
#define CPSW_SS_CTRL                                                (0x4U)
#define CPSW_SS_SOFT_IDLE                                           (0x14U)
#define CPSW_SS_ID_VER                                              (0x0U)
#define CPSW_SS_TX_START_WDS                                        (0x20U)
#define CPSW_SS_SOFT_RESET                                          (0x8U)
#define CPSW_SS_GAP_THRESH                                          (0x1cU)
#define CPSW_SS_TS_LTYPE                                            (0x2cU)
#define CPSW_SS_THRU_RATE                                           (0x18U)
#define CPSW_SS_DLR_LTYPE                                           (0x30U)
#define CPSW_SS_FLOW_CTRL                                           (0x24U)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define CPSW_SS_PTYPE_ESC_PRI_LD_VAL_SHIFT                                              (0U)
#define CPSW_SS_PTYPE_ESC_PRI_LD_VAL_MASK                                               (0x0000001fU)

#define CPSW_SS_PTYPE_P0_ESC_SHIFT                                                      (8U)
#define CPSW_SS_PTYPE_P0_ESC_MASK                                                       (0x00000100U)

#define CPSW_SS_PTYPE_P1_ESC_SHIFT                                                      (9U)
#define CPSW_SS_PTYPE_P1_ESC_MASK                                                       (0x00000200U)

#define CPSW_SS_PTYPE_P2_ESC_SHIFT                                                      (10U)
#define CPSW_SS_PTYPE_P2_ESC_MASK                                                       (0x00000400U)

#define CPSW_SS_PTYPE_P1_PRI1_SHAPE_EN_SHIFT                                            (16U)
#define CPSW_SS_PTYPE_P1_PRI1_SHAPE_EN_MASK                                             (0x00010000U)

#define CPSW_SS_PTYPE_P1_PRI2_SHAPE_EN_SHIFT                                            (17U)
#define CPSW_SS_PTYPE_P1_PRI2_SHAPE_EN_MASK                                             (0x00020000U)

#define CPSW_SS_PTYPE_P1_PRI3_SHAPE_EN_SHIFT                                            (18U)
#define CPSW_SS_PTYPE_P1_PRI3_SHAPE_EN_MASK                                             (0x00040000U)

#define CPSW_SS_PTYPE_P2_PRI1_SHAPE_EN_SHIFT                                            (19U)
#define CPSW_SS_PTYPE_P2_PRI1_SHAPE_EN_MASK                                             (0x00080000U)

#define CPSW_SS_PTYPE_P2_PRI2_SHAPE_EN_SHIFT                                            (20U)
#define CPSW_SS_PTYPE_P2_PRI2_SHAPE_EN_MASK                                             (0x00100000U)

#define CPSW_SS_PTYPE_P2_PRI3_SHAPE_EN_SHIFT                                            (21U)
#define CPSW_SS_PTYPE_P2_PRI3_SHAPE_EN_MASK                                             (0x00200000U)

#define CPSW_SS_VLAN_LTYPE_LTYPE1_SHIFT                                                 (0U)
#define CPSW_SS_VLAN_LTYPE_LTYPE1_MASK                                                  (0x0000ffffU)

#define CPSW_SS_VLAN_LTYPE_LTYPE2_SHIFT                                                 (16U)
#define CPSW_SS_VLAN_LTYPE_LTYPE2_MASK                                                  (0xffff0000U)

#define CPSW_SS_STAT_PORT_EN_P0_SHIFT                                                   (0U)
#define CPSW_SS_STAT_PORT_EN_P0_MASK                                                    (0x00000001U)

#define CPSW_SS_STAT_PORT_EN_P1_SHIFT                                                   (1U)
#define CPSW_SS_STAT_PORT_EN_P1_MASK                                                    (0x00000002U)

#define CPSW_SS_STAT_PORT_EN_P2_SHIFT                                                   (2U)
#define CPSW_SS_STAT_PORT_EN_P2_MASK                                                    (0x00000004U)

#define CPSW_SS_CTRL_FIFO_LOOPBACK_SHIFT                                                (0U)
#define CPSW_SS_CTRL_FIFO_LOOPBACK_MASK                                                 (0x00000001U)

#define CPSW_SS_CTRL_VLAN_AWARE_SHIFT                                                   (1U)
#define CPSW_SS_CTRL_VLAN_AWARE_MASK                                                    (0x00000002U)
#define CPSW_SS_CTRL_VLAN_AWARE_EN_0x1                                                   (1U)
#define CPSW_SS_CTRL_VLAN_AWARE_EN_0x0                                                   (0U)

#define CPSW_SS_CTRL_RX_VLAN_ENCAP_SHIFT                                                (2U)
#define CPSW_SS_CTRL_RX_VLAN_ENCAP_MASK                                                 (0x00000004U)

#define CPSW_SS_CTRL_DLR_EN_SHIFT                                                       (3U)
#define CPSW_SS_CTRL_DLR_EN_MASK                                                        (0x00000008U)
#define CPSW_SS_CTRL_DLR_EN_ENABLE                                                       (1U)
#define CPSW_SS_CTRL_DLR_EN_DISABLE                                                      (0U)

#define CPSW_SS_SOFT_IDLE_SHIFT                                                         (0U)
#define CPSW_SS_SOFT_IDLE_MASK                                                          (0x00000001U)
#define CPSW_SS_SOFT_IDLE_EN_0x1                                                         (1U)
#define CPSW_SS_SOFT_IDLE_EN_0x0                                                         (0U)

#define CPSW_SS_ID_VER_3G_MINOR_SHIFT                                                   (0U)
#define CPSW_SS_ID_VER_3G_MINOR_MASK                                                    (0x000000ffU)

#define CPSW_SS_ID_VER_3G_MAJ_SHIFT                                                     (8U)
#define CPSW_SS_ID_VER_3G_MAJ_MASK                                                      (0x00000700U)

#define CPSW_SS_ID_VER_3G_RTL_SHIFT                                                     (11U)
#define CPSW_SS_ID_VER_3G_RTL_MASK                                                      (0x0000f800U)

#define CPSW_SS_ID_VER_3G_IDENT_SHIFT                                                   (16U)
#define CPSW_SS_ID_VER_3G_IDENT_MASK                                                    (0xffff0000U)

#define CPSW_SS_TX_START_WDS_SHIFT                                                      (0U)
#define CPSW_SS_TX_START_WDS_MASK                                                       (0x000007ffU)

#define CPSW_SS_SOFT_RESET_SHIFT                                                        (0U)
#define CPSW_SS_SOFT_RESET_MASK                                                         (0x00000001U)
#define CPSW_SS_SOFT_RESET_IN_PROGRESS                                                   (1U)
#define CPSW_SS_SOFT_RESET_DONE                                                          (0U)

#define CPSW_SS_GAP_THRESH_SHIFT                                                        (0U)
#define CPSW_SS_GAP_THRESH_MASK                                                         (0x0000001fU)

#define CPSW_SS_TS_LTYPE_LTYPE1_SHIFT                                                   (0U)
#define CPSW_SS_TS_LTYPE_LTYPE1_MASK                                                    (0x0000ffffU)

#define CPSW_SS_TS_LTYPE_LTYPE2_SHIFT                                                   (16U)
#define CPSW_SS_TS_LTYPE_LTYPE2_MASK                                                    (0xffff0000U)

#define CPSW_SS_THRU_RATE_CPDMA_SHIFT                                                   (0U)
#define CPSW_SS_THRU_RATE_CPDMA_MASK                                                    (0x0000000fU)

#define CPSW_SS_THRU_RATE_SL_RX_SHIFT                                                   (12U)
#define CPSW_SS_THRU_RATE_SL_RX_MASK                                                    (0x0000f000U)

#define CPSW_SS_DLR_LTYPE_SHIFT                                                         (0U)
#define CPSW_SS_DLR_LTYPE_MASK                                                          (0x0000ffffU)

#define CPSW_SS_FLOW_CTRL_P0_EN_SHIFT                                                   (0U)
#define CPSW_SS_FLOW_CTRL_P0_EN_MASK                                                    (0x00000001U)

#define CPSW_SS_FLOW_CTRL_P1_EN_SHIFT                                                   (1U)
#define CPSW_SS_FLOW_CTRL_P1_EN_MASK                                                    (0x00000002U)

#define CPSW_SS_FLOW_CTRL_P2_EN_SHIFT                                                   (2U)
#define CPSW_SS_FLOW_CTRL_P2_EN_MASK                                                    (0x00000004U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CPSW_SS_H_ */

