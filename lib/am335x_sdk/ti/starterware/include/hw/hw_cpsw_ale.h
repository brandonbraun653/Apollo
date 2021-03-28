/*
* hw_cpsw_ale.h
*
* Register-level header file for CPSW_ALE
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

#ifndef HW_CPSW_ALE_H_
#define HW_CPSW_ALE_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define CPSW_ALE_TBLCTL                                             (0x20U)
#define CPSW_ALE_UNKNOWN_VLAN                                       (0x18U)
#define CPSW_ALE_IDVER                                              (0x0U)
#define CPSW_ALE_PRESCALE                                           (0x10U)
#define CPSW_ALE_PORTCTL(n)                                         (0x40U + ((n) * 0x4U))
#define CPSW_ALE_CTRL                                               (0x8U)
#define CPSW_ALE_TBLW(n)                                            (0x3cU - ((n) * 0x4U))

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define CPSW_ALE_TBLCTL_ENTRY_POINTER_SHIFT                                             (0U)
#define CPSW_ALE_TBLCTL_ENTRY_POINTER_MASK                                              (0x000003ffU)

#define CPSW_ALE_TBLCTL_WRITE_RDZ_SHIFT                                                 (31U)
#define CPSW_ALE_TBLCTL_WRITE_RDZ_MASK                                                  (0x80000000U)
#define CPSW_ALE_TBLCTL_WRITE_RDZ_EN_0x1                                                 (1U)
#define CPSW_ALE_TBLCTL_WRITE_RDZ_EN_0x0                                                 (0U)

#define CPSW_ALE_UNKNOWN_VLAN_MEMBER_LIST_SHIFT                                         (0U)
#define CPSW_ALE_UNKNOWN_VLAN_MEMBER_LIST_MASK                                          (0x0000003fU)

#define CPSW_ALE_UNKNOWN_VLAN_MCAST_FLOOD_MASK_SHIFT                                    (8U)
#define CPSW_ALE_UNKNOWN_VLAN_MCAST_FLOOD_MASK_MASK                                     (0x00003f00U)

#define CPSW_ALE_UNKNOWN_VLAN_REG_MCAST_FLOOD_MASK_SHIFT                                (16U)
#define CPSW_ALE_UNKNOWN_VLAN_REG_MCAST_FLOOD_MASK_MASK                                 (0x003f0000U)

#define CPSW_ALE_UNKNOWN_VLAN_FORCE_UNTAGGED_EGRESS_SHIFT                               (24U)
#define CPSW_ALE_UNKNOWN_VLAN_FORCE_UNTAGGED_EGRESS_MASK                                (0x3f000000U)

#define CPSW_ALE_IDVER_MINOR_VER_SHIFT                                                  (0U)
#define CPSW_ALE_IDVER_MINOR_VER_MASK                                                   (0x000000ffU)

#define CPSW_ALE_IDVER_MAJ_VER_SHIFT                                                    (8U)
#define CPSW_ALE_IDVER_MAJ_VER_MASK                                                     (0x0000ff00U)

#define CPSW_ALE_IDVER_IDENT_SHIFT                                                      (16U)
#define CPSW_ALE_IDVER_IDENT_MASK                                                       (0xffff0000U)

#define CPSW_ALE_PRESCALE_SHIFT                                                         (0U)
#define CPSW_ALE_PRESCALE_MASK                                                          (0x000fffffU)

#define CPSW_ALE_PORTCTL_PORT_STATE_SHIFT                                               (0U)
#define CPSW_ALE_PORTCTL_PORT_STATE_MASK                                                (0x00000003U)
#define CPSW_ALE_PORTCTL_PORT_STATE_DISABLED                                             (0U)
#define CPSW_ALE_PORTCTL_PORT_STATE_BLOCKED                                              (1U)
#define CPSW_ALE_PORTCTL_PORT_STATE_LEARN                                                (2U)
#define CPSW_ALE_PORTCTL_PORT_STATE_FORWARD                                              (3U)

#define CPSW_ALE_PORTCTL_DROP_UNTAGGED_SHIFT                                            (2U)
#define CPSW_ALE_PORTCTL_DROP_UNTAGGED_MASK                                             (0x00000004U)

#define CPSW_ALE_PORTCTL_VID_INGRESS_CHECK_SHIFT                                        (3U)
#define CPSW_ALE_PORTCTL_VID_INGRESS_CHECK_MASK                                         (0x00000008U)
#define CPSW_ALE_PORTCTL_VID_INGRESS_CHECK_EN_0x1                                        (1U)
#define CPSW_ALE_PORTCTL_VID_INGRESS_CHECK_EN_0x0                                        (0U)

#define CPSW_ALE_PORTCTL_NO_LEARN_SHIFT                                                 (4U)
#define CPSW_ALE_PORTCTL_NO_LEARN_MASK                                                  (0x00000010U)

#define CPSW_ALE_PORTCTL_NO_SA_UPDATE_SHIFT                                             (5U)
#define CPSW_ALE_PORTCTL_NO_SA_UPDATE_MASK                                              (0x00000020U)

#define CPSW_ALE_PORTCTL_MCAST_LIMIT_SHIFT                                              (16U)
#define CPSW_ALE_PORTCTL_MCAST_LIMIT_MASK                                               (0x00ff0000U)

#define CPSW_ALE_PORTCTL_BCAST_LIMIT_SHIFT                                              (24U)
#define CPSW_ALE_PORTCTL_BCAST_LIMIT_MASK                                               (0xff000000U)

#define CPSW_ALE_CTRL_EN_RATE_LIMIT_SHIFT                                               (0U)
#define CPSW_ALE_CTRL_EN_RATE_LIMIT_MASK                                                (0x00000001U)
#define CPSW_ALE_CTRL_EN_RATE_LIMIT_ENA_0x1                                               (1U)
#define CPSW_ALE_CTRL_EN_RATE_LIMIT_ENA_0x0                                               (0U)

#define CPSW_ALE_CTRL_EN_AUTH_MODE_SHIFT                                                (1U)
#define CPSW_ALE_CTRL_EN_AUTH_MODE_MASK                                                 (0x00000002U)
#define CPSW_ALE_CTRL_EN_AUTH_MODE_ENABLE                                                (1U)
#define CPSW_ALE_CTRL_EN_AUTH_MODE_DISABLE                                               (0U)

#define CPSW_ALE_CTRL_VLAN_AWARE_SHIFT                                                  (2U)
#define CPSW_ALE_CTRL_VLAN_AWARE_MASK                                                   (0x00000004U)
#define CPSW_ALE_CTRL_VLAN_AWARE_ENA_0x1                                                 (1U)
#define CPSW_ALE_CTRL_VLAN_AWARE_ENA_0x0                                                 (0U)

#define CPSW_ALE_CTRL_RATE_LIMIT_TX_SHIFT                                               (3U)
#define CPSW_ALE_CTRL_RATE_LIMIT_TX_MASK                                                (0x00000008U)
#define CPSW_ALE_CTRL_RATE_LIMIT_TX_ENA_0x1                                              (1U)
#define CPSW_ALE_CTRL_RATE_LIMIT_TX_ENA_0x0                                              (0U)

#define CPSW_ALE_CTRL_BYPASS_SHIFT                                                      (4U)
#define CPSW_ALE_CTRL_BYPASS_MASK                                                       (0x00000010U)
#define CPSW_ALE_CTRL_BYPASS_ENABLE                                                      (1U)
#define CPSW_ALE_CTRL_BYPASS_DISABLE                                                     (0U)

#define CPSW_ALE_CTRL_EN_OUI_DENY_SHIFT                                                 (5U)
#define CPSW_ALE_CTRL_EN_OUI_DENY_MASK                                                  (0x00000020U)

#define CPSW_ALE_CTRL_EN_VID0_MODE_SHIFT                                                (6U)
#define CPSW_ALE_CTRL_EN_VID0_MODE_MASK                                                 (0x00000040U)

#define CPSW_ALE_CTRL_LEARN_NO_VID_SHIFT                                                (7U)
#define CPSW_ALE_CTRL_LEARN_NO_VID_MASK                                                 (0x00000080U)

#define CPSW_ALE_CTRL_EN_P0_UNI_FLOOD_SHIFT                                             (8U)
#define CPSW_ALE_CTRL_EN_P0_UNI_FLOOD_MASK                                              (0x00000100U)

#define CPSW_ALE_CTRL_AGE_OUT_NOW_SHIFT                                                 (29U)
#define CPSW_ALE_CTRL_AGE_OUT_NOW_MASK                                                  (0x20000000U)
#define CPSW_ALE_CTRL_AGE_OUT_NOW_IN_PROGRESS                                            (1U)
#define CPSW_ALE_CTRL_AGE_OUT_NOW_DONE                                                   (0U)

#define CPSW_ALE_CTRL_CLR_TBL_SHIFT                                                     (30U)
#define CPSW_ALE_CTRL_CLR_TBL_MASK                                                      (0x40000000U)
#define CPSW_ALE_CTRL_CLR_TBL_IN_PROGRESS                                                (1U)
#define CPSW_ALE_CTRL_CLR_TBL_DONE                                                       (0U)

#define CPSW_ALE_CTRL_EN_SHIFT                                                          (31U)
#define CPSW_ALE_CTRL_EN_MASK                                                           (0x80000000U)
#define CPSW_ALE_CTRL_EN_ENABLE                                                          (1U)
#define CPSW_ALE_CTRL_EN_DISABLE                                                         (0U)

#define CPSW_ALE_TBLW_ENTRY31_0_SHIFT                                                   (0U)
#define CPSW_ALE_TBLW_ENTRY31_0_MASK                                                    (0xffffffffU)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CPSW_ALE_H_ */

