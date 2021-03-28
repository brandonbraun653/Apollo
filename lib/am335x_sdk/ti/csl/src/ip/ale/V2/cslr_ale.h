/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_ALE_H_
#define CSLR_ALE_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for ALL
**************************************************************************/
typedef struct {
    volatile Uint32 IDVER;
    volatile Uint8  RSVD0[4];
    volatile Uint32 CONTROL;
    volatile Uint8  RSVD1[4];
    volatile Uint32 PRESCALE;
    volatile Uint8  RSVD2[4];
    volatile Uint32 UNKNOWN_VLAN;
    volatile Uint8  RSVD3[4];
    volatile Uint32 TBLCTL;
    volatile Uint8  RSVD4[16];
    volatile Uint32 TBLW2;
    volatile Uint32 TBLW1;
    volatile Uint32 TBLW0;
    volatile Uint32 PORTCTL0;
    volatile Uint32 PORTCTL1;
    volatile Uint32 PORTCTL2;
    volatile Uint32 PORTCTL3;
    volatile Uint32 PORTCTL4;
    volatile Uint32 PORTCTL5;
    volatile Uint8  RSVD5[280];
} CSL_AleRegs;


/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_ALE_TBLW2                                           (0x34U)
#define CSL_ALE_PORTCTL4                                        (0x50U)
#define CSL_ALE_TBLCTL                                          (0x20U)
#define CSL_ALE_UNKNOWN_VLAN                                    (0x18U)
#define CSL_ALE_PORTCTL1                                        (0x44U)
#define CSL_ALE_TBLW1                                           (0x38U)
#define CSL_ALE_IDVER                                           (0x0U)
#define CSL_ALE_PORTCTL2                                        (0x48U)
#define CSL_ALE_PRESCALE                                        (0x10U)
#define CSL_ALE_PORTCTL0                                        (0x40U)
#define CSL_ALE_CONTROL                                         (0x8U)
#define CSL_ALE_TBLW0                                           (0x3CU)
#define CSL_ALE_PORTCTL5                                        (0x54U)
#define CSL_ALE_PORTCTL3                                        (0x4CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* TBLW2 */

#define CSL_ALE_TBLW2_ENTRY71_64_MASK                           (0x000000FFU)
#define CSL_ALE_TBLW2_ENTRY71_64_SHIFT                          (0U)
#define CSL_ALE_TBLW2_ENTRY71_64_RESETVAL                       (0x00000000U)
#define CSL_ALE_TBLW2_ENTRY71_64_MAX                            (0x000000ffU)

#define CSL_ALE_TBLW2_RESETVAL                                  (0x00000000U)

/* PORTCTL4 */

#define CSL_ALE_PORTCTL4_PORT_STATE_MASK                        (0x00000003U)
#define CSL_ALE_PORTCTL4_PORT_STATE_SHIFT                       (0U)
#define CSL_ALE_PORTCTL4_PORT_STATE_RESETVAL                    (0x00000000U)
#define CSL_ALE_PORTCTL4_PORT_STATE_MAX                         (0x00000003U)

#define CSL_ALE_PORTCTL4_DROP_UNTAGGED_MASK                     (0x00000004U)
#define CSL_ALE_PORTCTL4_DROP_UNTAGGED_SHIFT                    (2U)
#define CSL_ALE_PORTCTL4_DROP_UNTAGGED_RESETVAL                 (0x00000000U)
#define CSL_ALE_PORTCTL4_DROP_UNTAGGED_MAX                      (0x00000001U)

#define CSL_ALE_PORTCTL4_VID_INGRESS_CHECK_MASK                 (0x00000008U)
#define CSL_ALE_PORTCTL4_VID_INGRESS_CHECK_SHIFT                (3U)
#define CSL_ALE_PORTCTL4_VID_INGRESS_CHECK_RESETVAL             (0x00000000U)
#define CSL_ALE_PORTCTL4_VID_INGRESS_CHECK_MAX                  (0x00000001U)

#define CSL_ALE_PORTCTL4_NO_LEARN_MASK                          (0x00000010U)
#define CSL_ALE_PORTCTL4_NO_LEARN_SHIFT                         (4U)
#define CSL_ALE_PORTCTL4_NO_LEARN_RESETVAL                      (0x00000000U)
#define CSL_ALE_PORTCTL4_NO_LEARN_MAX                           (0x00000001U)

#define CSL_ALE_PORTCTL4_NO_SA_UPDATE_MASK                      (0x00000020U)
#define CSL_ALE_PORTCTL4_NO_SA_UPDATE_SHIFT                     (5U)
#define CSL_ALE_PORTCTL4_NO_SA_UPDATE_RESETVAL                  (0x00000000U)
#define CSL_ALE_PORTCTL4_NO_SA_UPDATE_MAX                       (0x00000001U)

#define CSL_ALE_PORTCTL4_MCAST_LIMIT_MASK                       (0x00FF0000U)
#define CSL_ALE_PORTCTL4_MCAST_LIMIT_SHIFT                      (16U)
#define CSL_ALE_PORTCTL4_MCAST_LIMIT_RESETVAL                   (0x00000000U)
#define CSL_ALE_PORTCTL4_MCAST_LIMIT_MAX                        (0x000000ffU)

#define CSL_ALE_PORTCTL4_BCAST_LIMIT_MASK                       (0xFF000000U)
#define CSL_ALE_PORTCTL4_BCAST_LIMIT_SHIFT                      (24U)
#define CSL_ALE_PORTCTL4_BCAST_LIMIT_RESETVAL                   (0x00000000U)
#define CSL_ALE_PORTCTL4_BCAST_LIMIT_MAX                        (0x000000ffU)

#define CSL_ALE_PORTCTL4_RESETVAL                               (0x00000000U)

/* TBLCTL */

#define CSL_ALE_TBLCTL_ENTRY_POINTER_MASK                       (0x000003FFU)
#define CSL_ALE_TBLCTL_ENTRY_POINTER_SHIFT                      (0U)
#define CSL_ALE_TBLCTL_ENTRY_POINTER_RESETVAL                   (0x00000000U)
#define CSL_ALE_TBLCTL_ENTRY_POINTER_MAX                        (0x000003ffU)

#define CSL_ALE_TBLCTL_WRITE_RDZ_MASK                           (0x80000000U)
#define CSL_ALE_TBLCTL_WRITE_RDZ_SHIFT                          (31U)
#define CSL_ALE_TBLCTL_WRITE_RDZ_RESETVAL                       (0x00000000U)
#define CSL_ALE_TBLCTL_WRITE_RDZ_MAX                            (0x00000001U)

#define CSL_ALE_TBLCTL_RESETVAL                                 (0x00000000U)

/* UNKNOWN_VLAN */

#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_VLAN_MEMBER_LIST_MASK      (0x0000003FU)
#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_VLAN_MEMBER_LIST_SHIFT     (0U)
#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_VLAN_MEMBER_LIST_RESETVAL  (0x00000000U)
#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_VLAN_MEMBER_LIST_MAX       (0x0000003fU)

#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_MCAST_FLOOD_MASK_MASK      (0x00003F00U)
#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_MCAST_FLOOD_MASK_SHIFT     (8U)
#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_MCAST_FLOOD_MASK_RESETVAL  (0x00000000U)
#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_MCAST_FLOOD_MASK_MAX       (0x0000003fU)

#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_REG_MCAST_FLOOD_MASK_MASK  (0x003F0000U)
#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_REG_MCAST_FLOOD_MASK_SHIFT  (16U)
#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_REG_MCAST_FLOOD_MASK_RESETVAL  (0x00000000U)
#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_REG_MCAST_FLOOD_MASK_MAX   (0x0000003fU)

#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_FORCE_UNTAGGED_EGRESS_MASK  (0x3F000000U)
#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_FORCE_UNTAGGED_EGRESS_SHIFT  (24U)
#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_FORCE_UNTAGGED_EGRESS_RESETVAL  (0x00000000U)
#define CSL_ALE_UNKNOWN_VLAN_UNKNOWN_FORCE_UNTAGGED_EGRESS_MAX  (0x0000003fU)

#define CSL_ALE_UNKNOWN_VLAN_RESETVAL                           (0x00000000U)

/* PORTCTL1 */

#define CSL_ALE_PORTCTL1_PORT_STATE_MASK                        (0x00000003U)
#define CSL_ALE_PORTCTL1_PORT_STATE_SHIFT                       (0U)
#define CSL_ALE_PORTCTL1_PORT_STATE_RESETVAL                    (0x00000000U)
#define CSL_ALE_PORTCTL1_PORT_STATE_MAX                         (0x00000003U)

#define CSL_ALE_PORTCTL1_DROP_UNTAGGED_MASK                     (0x00000004U)
#define CSL_ALE_PORTCTL1_DROP_UNTAGGED_SHIFT                    (2U)
#define CSL_ALE_PORTCTL1_DROP_UNTAGGED_RESETVAL                 (0x00000000U)
#define CSL_ALE_PORTCTL1_DROP_UNTAGGED_MAX                      (0x00000001U)

#define CSL_ALE_PORTCTL1_VID_INGRESS_CHECK_MASK                 (0x00000008U)
#define CSL_ALE_PORTCTL1_VID_INGRESS_CHECK_SHIFT                (3U)
#define CSL_ALE_PORTCTL1_VID_INGRESS_CHECK_RESETVAL             (0x00000000U)
#define CSL_ALE_PORTCTL1_VID_INGRESS_CHECK_MAX                  (0x00000001U)

#define CSL_ALE_PORTCTL1_NO_LEARN_MASK                          (0x00000010U)
#define CSL_ALE_PORTCTL1_NO_LEARN_SHIFT                         (4U)
#define CSL_ALE_PORTCTL1_NO_LEARN_RESETVAL                      (0x00000000U)
#define CSL_ALE_PORTCTL1_NO_LEARN_MAX                           (0x00000001U)

#define CSL_ALE_PORTCTL1_NO_SA_UPDATE_MASK                      (0x00000020U)
#define CSL_ALE_PORTCTL1_NO_SA_UPDATE_SHIFT                     (5U)
#define CSL_ALE_PORTCTL1_NO_SA_UPDATE_RESETVAL                  (0x00000000U)
#define CSL_ALE_PORTCTL1_NO_SA_UPDATE_MAX                       (0x00000001U)

#define CSL_ALE_PORTCTL1_MCAST_LIMIT_MASK                       (0x00FF0000U)
#define CSL_ALE_PORTCTL1_MCAST_LIMIT_SHIFT                      (16U)
#define CSL_ALE_PORTCTL1_MCAST_LIMIT_RESETVAL                   (0x00000000U)
#define CSL_ALE_PORTCTL1_MCAST_LIMIT_MAX                        (0x000000ffU)

#define CSL_ALE_PORTCTL1_BCAST_LIMIT_MASK                       (0xFF000000U)
#define CSL_ALE_PORTCTL1_BCAST_LIMIT_SHIFT                      (24U)
#define CSL_ALE_PORTCTL1_BCAST_LIMIT_RESETVAL                   (0x00000000U)
#define CSL_ALE_PORTCTL1_BCAST_LIMIT_MAX                        (0x000000ffU)

#define CSL_ALE_PORTCTL1_RESETVAL                               (0x00000000U)

/* TBLW1 */

#define CSL_ALE_TBLW1_ENTRY63_32_MASK                           (0xFFFFFFFFU)
#define CSL_ALE_TBLW1_ENTRY63_32_SHIFT                          (0U)
#define CSL_ALE_TBLW1_ENTRY63_32_RESETVAL                       (0x00000000U)
#define CSL_ALE_TBLW1_ENTRY63_32_MAX                            (0xffffffffU)

#define CSL_ALE_TBLW1_RESETVAL                                  (0x00000000U)

/* IDVER */

#define CSL_ALE_IDVER_MINOR_VER_MASK                            (0x000000FFU)
#define CSL_ALE_IDVER_MINOR_VER_SHIFT                           (0U)
#define CSL_ALE_IDVER_MINOR_VER_RESETVAL                        (0x00000004U)
#define CSL_ALE_IDVER_MINOR_VER_MAX                             (0x000000ffU)

#define CSL_ALE_IDVER_MAJ_VER_MASK                              (0x0000FF00U)
#define CSL_ALE_IDVER_MAJ_VER_SHIFT                             (8U)
#define CSL_ALE_IDVER_MAJ_VER_RESETVAL                          (0x00000001U)
#define CSL_ALE_IDVER_MAJ_VER_MAX                               (0x000000ffU)

#define CSL_ALE_IDVER_IDENT_MASK                                (0xFFFF0000U)
#define CSL_ALE_IDVER_IDENT_SHIFT                               (16U)
#define CSL_ALE_IDVER_IDENT_RESETVAL                            (0x00000029U)
#define CSL_ALE_IDVER_IDENT_MAX                                 (0x0000ffffU)

#define CSL_ALE_IDVER_RESETVAL                                  (0x00290104U)

/* PORTCTL2 */

#define CSL_ALE_PORTCTL2_PORT_STATE_MASK                        (0x00000003U)
#define CSL_ALE_PORTCTL2_PORT_STATE_SHIFT                       (0U)
#define CSL_ALE_PORTCTL2_PORT_STATE_RESETVAL                    (0x00000000U)
#define CSL_ALE_PORTCTL2_PORT_STATE_MAX                         (0x00000003U)

#define CSL_ALE_PORTCTL2_DROP_UNTAGGED_MASK                     (0x00000004U)
#define CSL_ALE_PORTCTL2_DROP_UNTAGGED_SHIFT                    (2U)
#define CSL_ALE_PORTCTL2_DROP_UNTAGGED_RESETVAL                 (0x00000000U)
#define CSL_ALE_PORTCTL2_DROP_UNTAGGED_MAX                      (0x00000001U)

#define CSL_ALE_PORTCTL2_VID_INGRESS_CHECK_MASK                 (0x00000008U)
#define CSL_ALE_PORTCTL2_VID_INGRESS_CHECK_SHIFT                (3U)
#define CSL_ALE_PORTCTL2_VID_INGRESS_CHECK_RESETVAL             (0x00000000U)
#define CSL_ALE_PORTCTL2_VID_INGRESS_CHECK_MAX                  (0x00000001U)

#define CSL_ALE_PORTCTL2_NO_LEARN_MASK                          (0x00000010U)
#define CSL_ALE_PORTCTL2_NO_LEARN_SHIFT                         (4U)
#define CSL_ALE_PORTCTL2_NO_LEARN_RESETVAL                      (0x00000000U)
#define CSL_ALE_PORTCTL2_NO_LEARN_MAX                           (0x00000001U)

#define CSL_ALE_PORTCTL2_NO_SA_UPDATE_MASK                      (0x00000020U)
#define CSL_ALE_PORTCTL2_NO_SA_UPDATE_SHIFT                     (5U)
#define CSL_ALE_PORTCTL2_NO_SA_UPDATE_RESETVAL                  (0x00000000U)
#define CSL_ALE_PORTCTL2_NO_SA_UPDATE_MAX                       (0x00000001U)

#define CSL_ALE_PORTCTL2_MCAST_LIMIT_MASK                       (0x00FF0000U)
#define CSL_ALE_PORTCTL2_MCAST_LIMIT_SHIFT                      (16U)
#define CSL_ALE_PORTCTL2_MCAST_LIMIT_RESETVAL                   (0x00000000U)
#define CSL_ALE_PORTCTL2_MCAST_LIMIT_MAX                        (0x000000ffU)

#define CSL_ALE_PORTCTL2_BCAST_LIMIT_MASK                       (0xFF000000U)
#define CSL_ALE_PORTCTL2_BCAST_LIMIT_SHIFT                      (24U)
#define CSL_ALE_PORTCTL2_BCAST_LIMIT_RESETVAL                   (0x00000000U)
#define CSL_ALE_PORTCTL2_BCAST_LIMIT_MAX                        (0x000000ffU)

#define CSL_ALE_PORTCTL2_RESETVAL                               (0x00000000U)

/* PRESCALE */

#define CSL_ALE_PRESCALE_PRESCALE_MASK                          (0x000FFFFFU)
#define CSL_ALE_PRESCALE_PRESCALE_SHIFT                         (0U)
#define CSL_ALE_PRESCALE_PRESCALE_RESETVAL                      (0x00000000U)
#define CSL_ALE_PRESCALE_PRESCALE_MAX                           (0x000fffffU)

#define CSL_ALE_PRESCALE_RESETVAL                               (0x00000000U)

/* PORTCTL0 */

#define CSL_ALE_PORTCTL0_PORT_STATE_MASK                        (0x00000003U)
#define CSL_ALE_PORTCTL0_PORT_STATE_SHIFT                       (0U)
#define CSL_ALE_PORTCTL0_PORT_STATE_RESETVAL                    (0x00000000U)
#define CSL_ALE_PORTCTL0_PORT_STATE_MAX                         (0x00000003U)

#define CSL_ALE_PORTCTL0_DROP_UNTAGGED_MASK                     (0x00000004U)
#define CSL_ALE_PORTCTL0_DROP_UNTAGGED_SHIFT                    (2U)
#define CSL_ALE_PORTCTL0_DROP_UNTAGGED_RESETVAL                 (0x00000000U)
#define CSL_ALE_PORTCTL0_DROP_UNTAGGED_MAX                      (0x00000001U)

#define CSL_ALE_PORTCTL0_VID_INGRESS_CHECK_MASK                 (0x00000008U)
#define CSL_ALE_PORTCTL0_VID_INGRESS_CHECK_SHIFT                (3U)
#define CSL_ALE_PORTCTL0_VID_INGRESS_CHECK_RESETVAL             (0x00000000U)
#define CSL_ALE_PORTCTL0_VID_INGRESS_CHECK_MAX                  (0x00000001U)

#define CSL_ALE_PORTCTL0_NO_LEARN_MASK                          (0x00000010U)
#define CSL_ALE_PORTCTL0_NO_LEARN_SHIFT                         (4U)
#define CSL_ALE_PORTCTL0_NO_LEARN_RESETVAL                      (0x00000000U)
#define CSL_ALE_PORTCTL0_NO_LEARN_MAX                           (0x00000001U)

#define CSL_ALE_PORTCTL0_NO_SA_UPDATE_MASK                      (0x00000020U)
#define CSL_ALE_PORTCTL0_NO_SA_UPDATE_SHIFT                     (5U)
#define CSL_ALE_PORTCTL0_NO_SA_UPDATE_RESETVAL                  (0x00000000U)
#define CSL_ALE_PORTCTL0_NO_SA_UPDATE_MAX                       (0x00000001U)

#define CSL_ALE_PORTCTL0_MCAST_LIMIT_MASK                       (0x00FF0000U)
#define CSL_ALE_PORTCTL0_MCAST_LIMIT_SHIFT                      (16U)
#define CSL_ALE_PORTCTL0_MCAST_LIMIT_RESETVAL                   (0x00000000U)
#define CSL_ALE_PORTCTL0_MCAST_LIMIT_MAX                        (0x000000ffU)

#define CSL_ALE_PORTCTL0_BCAST_LIMIT_MASK                       (0xFF000000U)
#define CSL_ALE_PORTCTL0_BCAST_LIMIT_SHIFT                      (24U)
#define CSL_ALE_PORTCTL0_BCAST_LIMIT_RESETVAL                   (0x00000000U)
#define CSL_ALE_PORTCTL0_BCAST_LIMIT_MAX                        (0x000000ffU)

#define CSL_ALE_PORTCTL0_RESETVAL                               (0x00000000U)

/* CONTROL */

#define CSL_ALE_CONTROL_ENABLE_RATE_LIMIT_MASK                  (0x00000001U)
#define CSL_ALE_CONTROL_ENABLE_RATE_LIMIT_SHIFT                 (0U)
#define CSL_ALE_CONTROL_ENABLE_RATE_LIMIT_RESETVAL              (0x00000000U)
#define CSL_ALE_CONTROL_ENABLE_RATE_LIMIT_MAX                   (0x00000001U)

#define CSL_ALE_CONTROL_ENABLE_AUTH_MODE_MASK                   (0x00000002U)
#define CSL_ALE_CONTROL_ENABLE_AUTH_MODE_SHIFT                  (1U)
#define CSL_ALE_CONTROL_ENABLE_AUTH_MODE_RESETVAL               (0x00000000U)
#define CSL_ALE_CONTROL_ENABLE_AUTH_MODE_MAX                    (0x00000001U)

#define CSL_ALE_CONTROL_VLAN_AWARE_MASK                         (0x00000004U)
#define CSL_ALE_CONTROL_VLAN_AWARE_SHIFT                        (2U)
#define CSL_ALE_CONTROL_VLAN_AWARE_RESETVAL                     (0x00000000U)
#define CSL_ALE_CONTROL_VLAN_AWARE_MAX                          (0x00000001U)

#define CSL_ALE_CONTROL_RATE_LIMIT_TX_MASK                      (0x00000008U)
#define CSL_ALE_CONTROL_RATE_LIMIT_TX_SHIFT                     (3U)
#define CSL_ALE_CONTROL_RATE_LIMIT_TX_RESETVAL                  (0x00000000U)
#define CSL_ALE_CONTROL_RATE_LIMIT_TX_MAX                       (0x00000001U)

#define CSL_ALE_CONTROL_BYPASS_MASK                             (0x00000010U)
#define CSL_ALE_CONTROL_BYPASS_SHIFT                            (4U)
#define CSL_ALE_CONTROL_BYPASS_RESETVAL                         (0x00000000U)
#define CSL_ALE_CONTROL_BYPASS_MAX                              (0x00000001U)

#define CSL_ALE_CONTROL_ENABLE_OUI_DENY_MASK                    (0x00000020U)
#define CSL_ALE_CONTROL_ENABLE_OUI_DENY_SHIFT                   (5U)
#define CSL_ALE_CONTROL_ENABLE_OUI_DENY_RESETVAL                (0x00000000U)
#define CSL_ALE_CONTROL_ENABLE_OUI_DENY_MAX                     (0x00000001U)

#define CSL_ALE_CONTROL_EN_VID0_MODE_MASK                       (0x00000040U)
#define CSL_ALE_CONTROL_EN_VID0_MODE_SHIFT                      (6U)
#define CSL_ALE_CONTROL_EN_VID0_MODE_RESETVAL                   (0x00000000U)
#define CSL_ALE_CONTROL_EN_VID0_MODE_MAX                        (0x00000001U)

#define CSL_ALE_CONTROL_LEARN_NO_VID_MASK                       (0x00000080U)
#define CSL_ALE_CONTROL_LEARN_NO_VID_SHIFT                      (7U)
#define CSL_ALE_CONTROL_LEARN_NO_VID_RESETVAL                   (0x00000000U)
#define CSL_ALE_CONTROL_LEARN_NO_VID_MAX                        (0x00000001U)

#define CSL_ALE_CONTROL_EN_P0_UNI_FLOOD_MASK                    (0x00000100U)
#define CSL_ALE_CONTROL_EN_P0_UNI_FLOOD_SHIFT                   (8U)
#define CSL_ALE_CONTROL_EN_P0_UNI_FLOOD_RESETVAL                (0x00000000U)
#define CSL_ALE_CONTROL_EN_P0_UNI_FLOOD_MAX                     (0x00000001U)

#define CSL_ALE_CONTROL_AGE_OUT_NOW_MASK                        (0x20000000U)
#define CSL_ALE_CONTROL_AGE_OUT_NOW_SHIFT                       (29U)
#define CSL_ALE_CONTROL_AGE_OUT_NOW_RESETVAL                    (0x00000000U)
#define CSL_ALE_CONTROL_AGE_OUT_NOW_MAX                         (0x00000001U)

#define CSL_ALE_CONTROL_CLEAR_TABLE_MASK                        (0x40000000U)
#define CSL_ALE_CONTROL_CLEAR_TABLE_SHIFT                       (30U)
#define CSL_ALE_CONTROL_CLEAR_TABLE_RESETVAL                    (0x00000000U)
#define CSL_ALE_CONTROL_CLEAR_TABLE_MAX                         (0x00000001U)

#define CSL_ALE_CONTROL_ENABLE_ALE_MASK                         (0x80000000U)
#define CSL_ALE_CONTROL_ENABLE_ALE_SHIFT                        (31U)
#define CSL_ALE_CONTROL_ENABLE_ALE_RESETVAL                     (0x00000000U)
#define CSL_ALE_CONTROL_ENABLE_ALE_MAX                          (0x00000001U)

#define CSL_ALE_CONTROL_RESETVAL                                (0x00000000U)

/* TBLW0 */

#define CSL_ALE_TBLW0_ENTRY31_0_MASK                            (0xFFFFFFFFU)
#define CSL_ALE_TBLW0_ENTRY31_0_SHIFT                           (0U)
#define CSL_ALE_TBLW0_ENTRY31_0_RESETVAL                        (0x00000000U)
#define CSL_ALE_TBLW0_ENTRY31_0_MAX                             (0xffffffffU)

#define CSL_ALE_TBLW0_RESETVAL                                  (0x00000000U)

/* PORTCTL5 */

#define CSL_ALE_PORTCTL5_PORT_STATE_MASK                        (0x00000003U)
#define CSL_ALE_PORTCTL5_PORT_STATE_SHIFT                       (0U)
#define CSL_ALE_PORTCTL5_PORT_STATE_RESETVAL                    (0x00000000U)
#define CSL_ALE_PORTCTL5_PORT_STATE_MAX                         (0x00000003U)

#define CSL_ALE_PORTCTL5_DROP_UNTAGGED_MASK                     (0x00000004U)
#define CSL_ALE_PORTCTL5_DROP_UNTAGGED_SHIFT                    (2U)
#define CSL_ALE_PORTCTL5_DROP_UNTAGGED_RESETVAL                 (0x00000000U)
#define CSL_ALE_PORTCTL5_DROP_UNTAGGED_MAX                      (0x00000001U)

#define CSL_ALE_PORTCTL5_VID_INGRESS_CHECK_MASK                 (0x00000008U)
#define CSL_ALE_PORTCTL5_VID_INGRESS_CHECK_SHIFT                (3U)
#define CSL_ALE_PORTCTL5_VID_INGRESS_CHECK_RESETVAL             (0x00000000U)
#define CSL_ALE_PORTCTL5_VID_INGRESS_CHECK_MAX                  (0x00000001U)

#define CSL_ALE_PORTCTL5_NO_LEARN_MASK                          (0x00000010U)
#define CSL_ALE_PORTCTL5_NO_LEARN_SHIFT                         (4U)
#define CSL_ALE_PORTCTL5_NO_LEARN_RESETVAL                      (0x00000000U)
#define CSL_ALE_PORTCTL5_NO_LEARN_MAX                           (0x00000001U)

#define CSL_ALE_PORTCTL5_NO_SA_UPDATE_MASK                      (0x00000020U)
#define CSL_ALE_PORTCTL5_NO_SA_UPDATE_SHIFT                     (5U)
#define CSL_ALE_PORTCTL5_NO_SA_UPDATE_RESETVAL                  (0x00000000U)
#define CSL_ALE_PORTCTL5_NO_SA_UPDATE_MAX                       (0x00000001U)

#define CSL_ALE_PORTCTL5_MCAST_LIMIT_MASK                       (0x00FF0000U)
#define CSL_ALE_PORTCTL5_MCAST_LIMIT_SHIFT                      (16U)
#define CSL_ALE_PORTCTL5_MCAST_LIMIT_RESETVAL                   (0x00000000U)
#define CSL_ALE_PORTCTL5_MCAST_LIMIT_MAX                        (0x000000ffU)

#define CSL_ALE_PORTCTL5_BCAST_LIMIT_MASK                       (0xFF000000U)
#define CSL_ALE_PORTCTL5_BCAST_LIMIT_SHIFT                      (24U)
#define CSL_ALE_PORTCTL5_BCAST_LIMIT_RESETVAL                   (0x00000000U)
#define CSL_ALE_PORTCTL5_BCAST_LIMIT_MAX                        (0x000000ffU)

#define CSL_ALE_PORTCTL5_RESETVAL                               (0x00000000U)

/* PORTCTL3 */

#define CSL_ALE_PORTCTL3_PORT_STATE_MASK                        (0x00000003U)
#define CSL_ALE_PORTCTL3_PORT_STATE_SHIFT                       (0U)
#define CSL_ALE_PORTCTL3_PORT_STATE_RESETVAL                    (0x00000000U)
#define CSL_ALE_PORTCTL3_PORT_STATE_MAX                         (0x00000003U)

#define CSL_ALE_PORTCTL3_DROP_UNTAGGED_MASK                     (0x00000004U)
#define CSL_ALE_PORTCTL3_DROP_UNTAGGED_SHIFT                    (2U)
#define CSL_ALE_PORTCTL3_DROP_UNTAGGED_RESETVAL                 (0x00000000U)
#define CSL_ALE_PORTCTL3_DROP_UNTAGGED_MAX                      (0x00000001U)

#define CSL_ALE_PORTCTL3_VID_INGRESS_CHECK_MASK                 (0x00000008U)
#define CSL_ALE_PORTCTL3_VID_INGRESS_CHECK_SHIFT                (3U)
#define CSL_ALE_PORTCTL3_VID_INGRESS_CHECK_RESETVAL             (0x00000000U)
#define CSL_ALE_PORTCTL3_VID_INGRESS_CHECK_MAX                  (0x00000001U)

#define CSL_ALE_PORTCTL3_NO_LEARN_MASK                          (0x00000010U)
#define CSL_ALE_PORTCTL3_NO_LEARN_SHIFT                         (4U)
#define CSL_ALE_PORTCTL3_NO_LEARN_RESETVAL                      (0x00000000U)
#define CSL_ALE_PORTCTL3_NO_LEARN_MAX                           (0x00000001U)

#define CSL_ALE_PORTCTL3_NO_SA_UPDATE_MASK                      (0x00000020U)
#define CSL_ALE_PORTCTL3_NO_SA_UPDATE_SHIFT                     (5U)
#define CSL_ALE_PORTCTL3_NO_SA_UPDATE_RESETVAL                  (0x00000000U)
#define CSL_ALE_PORTCTL3_NO_SA_UPDATE_MAX                       (0x00000001U)

#define CSL_ALE_PORTCTL3_MCAST_LIMIT_MASK                       (0x00FF0000U)
#define CSL_ALE_PORTCTL3_MCAST_LIMIT_SHIFT                      (16U)
#define CSL_ALE_PORTCTL3_MCAST_LIMIT_RESETVAL                   (0x00000000U)
#define CSL_ALE_PORTCTL3_MCAST_LIMIT_MAX                        (0x000000ffU)

#define CSL_ALE_PORTCTL3_BCAST_LIMIT_MASK                       (0xFF000000U)
#define CSL_ALE_PORTCTL3_BCAST_LIMIT_SHIFT                      (24U)
#define CSL_ALE_PORTCTL3_BCAST_LIMIT_RESETVAL                   (0x00000000U)
#define CSL_ALE_PORTCTL3_BCAST_LIMIT_MAX                        (0x000000ffU)

#define CSL_ALE_PORTCTL3_RESETVAL                               (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
