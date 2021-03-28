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
* Register Overlay Structure
**************************************************************************/
typedef struct {
    volatile Uint32 IDVER_REG;
    volatile Uint32 STATUS_REG;
    volatile Uint32 CONTROL_REG;
    volatile Uint8  RSVD0[4];
    volatile Uint32 PRESCALE_REG;
    volatile Uint32 AGING_TIMER_REG;
    volatile Uint8  RSVD1[8];
    volatile Uint32 TABLE_CONTROL_REG;
    volatile Uint8  RSVD2[16];
    volatile Uint32 TABLE_WORD2_REG;
    volatile Uint32 TABLE_WORD1_REG;
    volatile Uint32 TABLE_WORD0_REG;
    volatile Uint32 PORT_CONTROL_REG[8];
    volatile Uint8  RSVD3[48];
    volatile Uint32 UNKNOWN_VLAN_REG;
    volatile Uint32 UNKNOWN_MCAST_FLOOD_REG;
    volatile Uint32 UNKNOWN_REG_MCAST_FLOOD_REG;
    volatile Uint32 FORCE_UNTAGGED_EGRESS_REG;
    volatile Uint8  RSVD4[32];
    volatile Uint32 VLAN_MASK_MUX_REG[4];
    volatile Uint8  RSVD5[48];
    volatile Uint32 POLICER_PORT_OUI_REG;
    volatile Uint32 POLICER_DA_SA_REG;
    volatile Uint32 POLICER_VLAN_REG;
    volatile Uint32 POLICER_ETHERTYPE_IPSA_REG;
    volatile Uint32 POLICER_IPDA_REG;
    volatile Uint8  RSVD6[12];
    volatile Uint32 POLICER_TBL_CTL_REG;
    volatile Uint8  RSVD7[16];
    volatile Uint32 THREAD_DEF_REG;
    volatile Uint32 THREAD_CTL_REG;
    volatile Uint32 THREAD_VAL_REG;
} CSL_AleRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* ID / Version */
#define CSL_ALE_IDVER_REG                                       (0x0U)

/* Status */
#define CSL_ALE_STATUS_REG                                      (0x4U)

/* Control */
#define CSL_ALE_CONTROL_REG                                     (0x8U)

/* Prescale */
#define CSL_ALE_PRESCALE_REG                                    (0x10U)

/* Aging Timer */
#define CSL_ALE_AGING_TIMER_REG                                 (0x14U)

/* Table Control */
#define CSL_ALE_TABLE_CONTROL_REG                               (0x20U)

/* Table Word 2 */
#define CSL_ALE_TABLE_WORD2_REG                                 (0x34U)

/* Table Word 1 */
#define CSL_ALE_TABLE_WORD1_REG                                 (0x38U)

/* Table Word 0 */
#define CSL_ALE_TABLE_WORD0_REG                                 (0x3CU)

/* Port N Control */
#define CSL_ALE_PORT_CONTROL_REG(i)                             (0x40U + ((i) * (0x4U)))

/* Unknown VLAN Member List */
#define CSL_ALE_UNKNOWN_VLAN_REG                                (0x90U)

/* Unknown VLAN Multicast Flood Mask */
#define CSL_ALE_UNKNOWN_MCAST_FLOOD_REG                         (0x94U)

/* Unknown VLAN Multicast Flood Mask */
#define CSL_ALE_UNKNOWN_REG_MCAST_FLOOD_REG                     (0x98U)

/* Unknown VLAN Force Untagged Egress */
#define CSL_ALE_FORCE_UNTAGGED_EGRESS_REG                       (0x9CU)

/* VLAN Mask Mux n Select */
#define CSL_ALE_VLAN_MASK_MUX_REG(i)                            (0xC0U + ((i) * (0x4U)))

/* Specifies the port, frame priority, and OUI address index as well as match
 * enables for port, frame priority, and OUI address matching */
#define CSL_ALE_POLICER_PORT_OUI_REG                            (0x100U)

/* Specifies the match enable/match index for the L2 destination and L2 source
 * addresses */
#define CSL_ALE_POLICER_DA_SA_REG                               (0x104U)

/* Specifies the match enable/match index for the Outer VLAN and Inner VLAN
 * addresses */
#define CSL_ALE_POLICER_VLAN_REG                                (0x108U)

/* Specifies the match enable/match index for the Ether Type and IP Source
 * address */
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG                      (0x10CU)

/* Specifies the match enable/match index for the IP Destination address */
#define CSL_ALE_POLICER_IPDA_REG                                (0x110U)

/* The Policing Table Control is used to read or write the selected
 * policing/classifier entry */
#define CSL_ALE_POLICER_TBL_CTL_REG                             (0x120U)

/* The THREAD Mapping Default Value register is used to set the default thread
 * ID when no classifier is matched */
#define CSL_ALE_THREAD_DEF_REG                                  (0x134U)

/* The THREAD Mapping Control register allows the highest matched classifier
 * to return a particular thread ID for traffic sent to the host */
#define CSL_ALE_THREAD_CTL_REG                                  (0x138U)

/* The THREAD Mapping Value register is used to set the thread ID for a
 * particular classifier entry */
#define CSL_ALE_THREAD_VAL_REG                                  (0x13CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* IDVER_REG */

#define CSL_ALE_IDVER_REG_MINOR_VER_MASK                        (0x000000FFU)
#define CSL_ALE_IDVER_REG_MINOR_VER_SHIFT                       (0U)
#define CSL_ALE_IDVER_REG_MINOR_VER_RESETVAL                    (0x00000000U)
#define CSL_ALE_IDVER_REG_MINOR_VER_MAX                         (0x000000ffU)

#define CSL_ALE_IDVER_REG_MAJOR_VER_MASK                        (0x00000700U)
#define CSL_ALE_IDVER_REG_MAJOR_VER_SHIFT                       (8U)
#define CSL_ALE_IDVER_REG_MAJOR_VER_RESETVAL                    (0x00000000U)
#define CSL_ALE_IDVER_REG_MAJOR_VER_MAX                         (0x00000007U)

#define CSL_ALE_IDVER_REG_RTL_VER_MASK                          (0x0000F800U)
#define CSL_ALE_IDVER_REG_RTL_VER_SHIFT                         (11U)
#define CSL_ALE_IDVER_REG_RTL_VER_RESETVAL                      (0x00000000U)
#define CSL_ALE_IDVER_REG_RTL_VER_MAX                           (0x0000001fU)

#define CSL_ALE_IDVER_REG_IDENT_MASK                            (0xFFFF0000U)
#define CSL_ALE_IDVER_REG_IDENT_SHIFT                           (16U)
#define CSL_ALE_IDVER_REG_IDENT_RESETVAL                        (0x00000000U)
#define CSL_ALE_IDVER_REG_IDENT_MAX                             (0x0000ffffU)

#define CSL_ALE_IDVER_REG_RESETVAL                              (0x00000000U)

/* STATUS_REG */

#define CSL_ALE_STATUS_REG_ENTRIES_DIV_1024_MASK                (0x000000FFU)
#define CSL_ALE_STATUS_REG_ENTRIES_DIV_1024_SHIFT               (0U)
#define CSL_ALE_STATUS_REG_ENTRIES_DIV_1024_RESETVAL            (0x00000000U)
#define CSL_ALE_STATUS_REG_ENTRIES_DIV_1024_MAX                 (0x000000ffU)

#define CSL_ALE_STATUS_REG_POLICERS_DIV_8_MASK                  (0x0000FF00U)
#define CSL_ALE_STATUS_REG_POLICERS_DIV_8_SHIFT                 (8U)
#define CSL_ALE_STATUS_REG_POLICERS_DIV_8_RESETVAL              (0x00000000U)
#define CSL_ALE_STATUS_REG_POLICERS_DIV_8_MAX                   (0x000000ffU)

#define CSL_ALE_STATUS_REG_RESETVAL                             (0x00000000U)

/* CONTROL_REG */

#define CSL_ALE_CONTROL_REG_ENABLE_RATE_LIMIT_MASK              (0x00000001U)
#define CSL_ALE_CONTROL_REG_ENABLE_RATE_LIMIT_SHIFT             (0U)
#define CSL_ALE_CONTROL_REG_ENABLE_RATE_LIMIT_RESETVAL          (0x00000000U)
#define CSL_ALE_CONTROL_REG_ENABLE_RATE_LIMIT_MAX               (0x00000001U)

#define CSL_ALE_CONTROL_REG_ENABLE_AUTH_MODE_MASK               (0x00000002U)
#define CSL_ALE_CONTROL_REG_ENABLE_AUTH_MODE_SHIFT              (1U)
#define CSL_ALE_CONTROL_REG_ENABLE_AUTH_MODE_RESETVAL           (0x00000000U)
#define CSL_ALE_CONTROL_REG_ENABLE_AUTH_MODE_MAX                (0x00000001U)

#define CSL_ALE_CONTROL_REG_VLAN_AWARE_MASK                     (0x00000004U)
#define CSL_ALE_CONTROL_REG_VLAN_AWARE_SHIFT                    (2U)
#define CSL_ALE_CONTROL_REG_VLAN_AWARE_RESETVAL                 (0x00000000U)
#define CSL_ALE_CONTROL_REG_VLAN_AWARE_MAX                      (0x00000001U)

#define CSL_ALE_CONTROL_REG_RATE_LIMIT_TX_MASK                  (0x00000008U)
#define CSL_ALE_CONTROL_REG_RATE_LIMIT_TX_SHIFT                 (3U)
#define CSL_ALE_CONTROL_REG_RATE_LIMIT_TX_RESETVAL              (0x00000000U)
#define CSL_ALE_CONTROL_REG_RATE_LIMIT_TX_MAX                   (0x00000001U)

#define CSL_ALE_CONTROL_REG_BYPASS_MASK                         (0x00000010U)
#define CSL_ALE_CONTROL_REG_BYPASS_SHIFT                        (4U)
#define CSL_ALE_CONTROL_REG_BYPASS_RESETVAL                     (0x00000000U)
#define CSL_ALE_CONTROL_REG_BYPASS_MAX                          (0x00000001U)

#define CSL_ALE_CONTROL_REG_ENABLE_OUI_DENY_MASK                (0x00000020U)
#define CSL_ALE_CONTROL_REG_ENABLE_OUI_DENY_SHIFT               (5U)
#define CSL_ALE_CONTROL_REG_ENABLE_OUI_DENY_RESETVAL            (0x00000000U)
#define CSL_ALE_CONTROL_REG_ENABLE_OUI_DENY_MAX                 (0x00000001U)

#define CSL_ALE_CONTROL_REG_EN_VID0_MODE_MASK                   (0x00000040U)
#define CSL_ALE_CONTROL_REG_EN_VID0_MODE_SHIFT                  (6U)
#define CSL_ALE_CONTROL_REG_EN_VID0_MODE_RESETVAL               (0x00000000U)
#define CSL_ALE_CONTROL_REG_EN_VID0_MODE_MAX                    (0x00000001U)

#define CSL_ALE_CONTROL_REG_LEARN_NO_VID_MASK                   (0x00000080U)
#define CSL_ALE_CONTROL_REG_LEARN_NO_VID_SHIFT                  (7U)
#define CSL_ALE_CONTROL_REG_LEARN_NO_VID_RESETVAL               (0x00000000U)
#define CSL_ALE_CONTROL_REG_LEARN_NO_VID_MAX                    (0x00000001U)

#define CSL_ALE_CONTROL_REG_UNI_FLOOD_TO_HOST_MASK              (0x00000100U)
#define CSL_ALE_CONTROL_REG_UNI_FLOOD_TO_HOST_SHIFT             (8U)
#define CSL_ALE_CONTROL_REG_UNI_FLOOD_TO_HOST_RESETVAL          (0x00000000U)
#define CSL_ALE_CONTROL_REG_UNI_FLOOD_TO_HOST_MAX               (0x00000001U)

#define CSL_ALE_CONTROL_REG_UVLAN_NO_LEARN_MASK                 (0x00002000U)
#define CSL_ALE_CONTROL_REG_UVLAN_NO_LEARN_SHIFT                (13U)
#define CSL_ALE_CONTROL_REG_UVLAN_NO_LEARN_RESETVAL             (0x00000000U)
#define CSL_ALE_CONTROL_REG_UVLAN_NO_LEARN_MAX                  (0x00000001U)

#define CSL_ALE_CONTROL_REG_UPD_BW_CTL_MASK                     (0x00E00000U)
#define CSL_ALE_CONTROL_REG_UPD_BW_CTL_SHIFT                    (21U)
#define CSL_ALE_CONTROL_REG_UPD_BW_CTL_RESETVAL                 (0x00000000U)
#define CSL_ALE_CONTROL_REG_UPD_BW_CTL_MAX                      (0x00000007U)

#define CSL_ALE_CONTROL_REG_AGE_OUT_NOW_MASK                    (0x20000000U)
#define CSL_ALE_CONTROL_REG_AGE_OUT_NOW_SHIFT                   (29U)
#define CSL_ALE_CONTROL_REG_AGE_OUT_NOW_RESETVAL                (0x00000000U)
#define CSL_ALE_CONTROL_REG_AGE_OUT_NOW_MAX                     (0x00000001U)

#define CSL_ALE_CONTROL_REG_CLEAR_TABLE_MASK                    (0x40000000U)
#define CSL_ALE_CONTROL_REG_CLEAR_TABLE_SHIFT                   (30U)
#define CSL_ALE_CONTROL_REG_CLEAR_TABLE_RESETVAL                (0x00000000U)
#define CSL_ALE_CONTROL_REG_CLEAR_TABLE_MAX                     (0x00000001U)

#define CSL_ALE_CONTROL_REG_ENABLE_MASK                         (0x80000000U)
#define CSL_ALE_CONTROL_REG_ENABLE_SHIFT                        (31U)
#define CSL_ALE_CONTROL_REG_ENABLE_RESETVAL                     (0x00000000U)
#define CSL_ALE_CONTROL_REG_ENABLE_MAX                          (0x00000001U)

#define CSL_ALE_CONTROL_REG_RESETVAL                            (0x00000000U)

/* PRESCALE_REG */

#define CSL_ALE_PRESCALE_REG_PRESCALE_MASK                      (0x000FFFFFU)
#define CSL_ALE_PRESCALE_REG_PRESCALE_SHIFT                     (0U)
#define CSL_ALE_PRESCALE_REG_PRESCALE_RESETVAL                  (0x00000000U)
#define CSL_ALE_PRESCALE_REG_PRESCALE_MAX                       (0x000fffffU)

#define CSL_ALE_PRESCALE_REG_RESETVAL                           (0x00000000U)

/* AGING_TIMER_REG */

#define CSL_ALE_AGING_TIMER_REG_AGING_TIMER_MASK                (0x00FFFFFFU)
#define CSL_ALE_AGING_TIMER_REG_AGING_TIMER_SHIFT               (0U)
#define CSL_ALE_AGING_TIMER_REG_AGING_TIMER_RESETVAL            (0x00000000U)
#define CSL_ALE_AGING_TIMER_REG_AGING_TIMER_MAX                 (0x00ffffffU)

#define CSL_ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE_MASK         (0x40000000U)
#define CSL_ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE_SHIFT        (30U)
#define CSL_ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE_RESETVAL     (0x00000000U)
#define CSL_ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE_MAX          (0x00000001U)

#define CSL_ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE_MASK         (0x80000000U)
#define CSL_ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE_SHIFT        (31U)
#define CSL_ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE_RESETVAL     (0x00000000U)
#define CSL_ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE_MAX          (0x00000001U)

#define CSL_ALE_AGING_TIMER_REG_RESETVAL                        (0x00000000U)

/* TABLE_CONTROL_REG */

#define CSL_ALE_TABLE_CONTROL_REG_ENTRY_POINTER_MASK            (0x00003FFFU)
#define CSL_ALE_TABLE_CONTROL_REG_ENTRY_POINTER_SHIFT           (0U)
#define CSL_ALE_TABLE_CONTROL_REG_ENTRY_POINTER_RESETVAL        (0x00000000U)
#define CSL_ALE_TABLE_CONTROL_REG_ENTRY_POINTER_MAX             (0x00003fffU)

#define CSL_ALE_TABLE_CONTROL_REG_WRITE_RDZ_MASK                (0x80000000U)
#define CSL_ALE_TABLE_CONTROL_REG_WRITE_RDZ_SHIFT               (31U)
#define CSL_ALE_TABLE_CONTROL_REG_WRITE_RDZ_RESETVAL            (0x00000000U)
#define CSL_ALE_TABLE_CONTROL_REG_WRITE_RDZ_MAX                 (0x00000001U)

#define CSL_ALE_TABLE_CONTROL_REG_RESETVAL                      (0x00000000U)

/* TABLE_WORD2_REG */

#define CSL_ALE_TABLE_WORD2_REG_ENTRY_71_64_MASK                (0x0000007FU)
#define CSL_ALE_TABLE_WORD2_REG_ENTRY_71_64_SHIFT               (0U)
#define CSL_ALE_TABLE_WORD2_REG_ENTRY_71_64_RESETVAL            (0x00000000U)
#define CSL_ALE_TABLE_WORD2_REG_ENTRY_71_64_MAX                 (0x0000007fU)

#define CSL_ALE_TABLE_WORD2_REG_RESETVAL                        (0x00000000U)

/* TABLE_WORD1_REG */

#define CSL_ALE_TABLE_WORD1_REG_ENTRY_63_32_MASK                (0xFFFFFFFFU)
#define CSL_ALE_TABLE_WORD1_REG_ENTRY_63_32_SHIFT               (0U)
#define CSL_ALE_TABLE_WORD1_REG_ENTRY_63_32_RESETVAL            (0x00000000U)
#define CSL_ALE_TABLE_WORD1_REG_ENTRY_63_32_MAX                 (0xffffffffU)

#define CSL_ALE_TABLE_WORD1_REG_RESETVAL                        (0x00000000U)

/* TABLE_WORD0_REG */

#define CSL_ALE_TABLE_WORD0_REG_ENTRY_31_0_MASK                 (0xFFFFFFFFU)
#define CSL_ALE_TABLE_WORD0_REG_ENTRY_31_0_SHIFT                (0U)
#define CSL_ALE_TABLE_WORD0_REG_ENTRY_31_0_RESETVAL             (0x00000000U)
#define CSL_ALE_TABLE_WORD0_REG_ENTRY_31_0_MAX                  (0xffffffffU)

#define CSL_ALE_TABLE_WORD0_REG_RESETVAL                        (0x00000000U)

/* PORT_CONTROL_REG */

#define CSL_ALE_PORT_CONTROL_REG_PORT_STATE_MASK                (0x00000003U)
#define CSL_ALE_PORT_CONTROL_REG_PORT_STATE_SHIFT               (0U)
#define CSL_ALE_PORT_CONTROL_REG_PORT_STATE_RESETVAL            (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_PORT_STATE_MAX                 (0x00000003U)

#define CSL_ALE_PORT_CONTROL_REG_DROP_UNTAGGED_MASK             (0x00000004U)
#define CSL_ALE_PORT_CONTROL_REG_DROP_UNTAGGED_SHIFT            (2U)
#define CSL_ALE_PORT_CONTROL_REG_DROP_UNTAGGED_RESETVAL         (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_DROP_UNTAGGED_MAX              (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_VID_INGRESS_CHECK_MASK         (0x00000008U)
#define CSL_ALE_PORT_CONTROL_REG_VID_INGRESS_CHECK_SHIFT        (3U)
#define CSL_ALE_PORT_CONTROL_REG_VID_INGRESS_CHECK_RESETVAL     (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_VID_INGRESS_CHECK_MAX          (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_NO_LEARN_MASK                  (0x00000010U)
#define CSL_ALE_PORT_CONTROL_REG_NO_LEARN_SHIFT                 (4U)
#define CSL_ALE_PORT_CONTROL_REG_NO_LEARN_RESETVAL              (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_NO_LEARN_MAX                   (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_NO_SA_UPDATE_MASK              (0x00000020U)
#define CSL_ALE_PORT_CONTROL_REG_NO_SA_UPDATE_SHIFT             (5U)
#define CSL_ALE_PORT_CONTROL_REG_NO_SA_UPDATE_RESETVAL          (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_NO_SA_UPDATE_MAX               (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_MAC_ONLY_MASK                  (0x00000800U)
#define CSL_ALE_PORT_CONTROL_REG_MAC_ONLY_SHIFT                 (11U)
#define CSL_ALE_PORT_CONTROL_REG_MAC_ONLY_RESETVAL              (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_MAC_ONLY_MAX                   (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_DISABLE_AUTH_MODE_MASK         (0x00001000U)
#define CSL_ALE_PORT_CONTROL_REG_DISABLE_AUTH_MODE_SHIFT        (12U)
#define CSL_ALE_PORT_CONTROL_REG_DISABLE_AUTH_MODE_RESETVAL     (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_DISABLE_AUTH_MODE_MAX          (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_MACONLY_CAF_MASK               (0x00002000U)
#define CSL_ALE_PORT_CONTROL_REG_MACONLY_CAF_SHIFT              (13U)
#define CSL_ALE_PORT_CONTROL_REG_MACONLY_CAF_RESETVAL           (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_MACONLY_CAF_MAX                (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_MCAST_LIMIT_MASK               (0x00FF0000U)
#define CSL_ALE_PORT_CONTROL_REG_MCAST_LIMIT_SHIFT              (16U)
#define CSL_ALE_PORT_CONTROL_REG_MCAST_LIMIT_RESETVAL           (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_MCAST_LIMIT_MAX                (0x000000ffU)

#define CSL_ALE_PORT_CONTROL_REG_BCAST_LIMIT_MASK               (0xFF000000U)
#define CSL_ALE_PORT_CONTROL_REG_BCAST_LIMIT_SHIFT              (24U)
#define CSL_ALE_PORT_CONTROL_REG_BCAST_LIMIT_RESETVAL           (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_BCAST_LIMIT_MAX                (0x000000ffU)

#define CSL_ALE_PORT_CONTROL_REG_RESETVAL                       (0x00000000U)

/* UNKNOWN_VLAN_REG */

#define CSL_ALE_UNKNOWN_VLAN_REG_LIST_MASK                      (0x0000001FU)
#define CSL_ALE_UNKNOWN_VLAN_REG_LIST_SHIFT                     (0U)
#define CSL_ALE_UNKNOWN_VLAN_REG_LIST_RESETVAL                  (0x00000000U)
#define CSL_ALE_UNKNOWN_VLAN_REG_LIST_MAX                       (0x0000001fU)

#define CSL_ALE_UNKNOWN_VLAN_REG_RESETVAL                       (0x00000000U)

/* UNKNOWN_MCAST_FLOOD_REG */

#define CSL_ALE_UNKNOWN_MCAST_FLOOD_REG_MASK_MASK               (0x0000001FU)
#define CSL_ALE_UNKNOWN_MCAST_FLOOD_REG_MASK_SHIFT              (0U)
#define CSL_ALE_UNKNOWN_MCAST_FLOOD_REG_MASK_RESETVAL           (0x00000000U)
#define CSL_ALE_UNKNOWN_MCAST_FLOOD_REG_MASK_MAX                (0x0000001fU)

#define CSL_ALE_UNKNOWN_MCAST_FLOOD_REG_RESETVAL                (0x00000000U)

/* UNKNOWN_REG_MCAST_FLOOD_REG */

#define CSL_ALE_UNKNOWN_REG_MCAST_FLOOD_REG_MASK_MASK           (0x0000001FU)
#define CSL_ALE_UNKNOWN_REG_MCAST_FLOOD_REG_MASK_SHIFT          (0U)
#define CSL_ALE_UNKNOWN_REG_MCAST_FLOOD_REG_MASK_RESETVAL       (0x00000000U)
#define CSL_ALE_UNKNOWN_REG_MCAST_FLOOD_REG_MASK_MAX            (0x0000001fU)

#define CSL_ALE_UNKNOWN_REG_MCAST_FLOOD_REG_RESETVAL            (0x00000000U)

/* FORCE_UNTAGGED_EGRESS_REG */

#define CSL_ALE_FORCE_UNTAGGED_EGRESS_REG_MASK_MASK             (0x0000001FU)
#define CSL_ALE_FORCE_UNTAGGED_EGRESS_REG_MASK_SHIFT            (0U)
#define CSL_ALE_FORCE_UNTAGGED_EGRESS_REG_MASK_RESETVAL         (0x00000000U)
#define CSL_ALE_FORCE_UNTAGGED_EGRESS_REG_MASK_MAX              (0x0000001fU)

#define CSL_ALE_FORCE_UNTAGGED_EGRESS_REG_RESETVAL              (0x00000000U)

/* VLAN_MASK_MUX_REG */

#define CSL_ALE_VLAN_MASK_MUX_REG_MASK_MASK                     (0x0000001FU)
#define CSL_ALE_VLAN_MASK_MUX_REG_MASK_SHIFT                    (0U)
#define CSL_ALE_VLAN_MASK_MUX_REG_MASK_RESETVAL                 (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX_REG_MASK_MAX                      (0x0000001fU)

#define CSL_ALE_VLAN_MASK_MUX_REG_RESETVAL                      (0x00000000U)

/* POLICER_PORT_OUI_REG */

#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_MEN_MASK              (0x80000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_MEN_SHIFT             (31U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_MEN_RESETVAL          (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_MEN_MAX               (0x00000001U)

#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_NUM_MASK              (0x1E000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_NUM_SHIFT             (25U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_NUM_RESETVAL          (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_NUM_MAX               (0x0000000fU)

#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_MEN_MASK               (0x00080000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_MEN_SHIFT              (19U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_MEN_RESETVAL           (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_MEN_MAX                (0x00000001U)

#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_VAL_MASK               (0x00070000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_VAL_SHIFT              (16U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_VAL_RESETVAL           (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_VAL_MAX                (0x00000007U)

#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_MEN_MASK               (0x00008000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_MEN_SHIFT              (15U)
#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_MEN_RESETVAL           (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_MEN_MAX                (0x00000001U)

#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_INDEX_MASK             (0x00001FFFU)
#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_INDEX_SHIFT            (0U)
#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_INDEX_RESETVAL         (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_INDEX_MAX              (0x00001fffU)

#define CSL_ALE_POLICER_PORT_OUI_REG_RESETVAL                   (0x00000000U)

/* POLICER_DA_SA_REG */

#define CSL_ALE_POLICER_DA_SA_REG_DST_MEN_MASK                  (0x80000000U)
#define CSL_ALE_POLICER_DA_SA_REG_DST_MEN_SHIFT                 (31U)
#define CSL_ALE_POLICER_DA_SA_REG_DST_MEN_RESETVAL              (0x00000000U)
#define CSL_ALE_POLICER_DA_SA_REG_DST_MEN_MAX                   (0x00000001U)

#define CSL_ALE_POLICER_DA_SA_REG_DST_INDEX_MASK                (0x1FFF0000U)
#define CSL_ALE_POLICER_DA_SA_REG_DST_INDEX_SHIFT               (16U)
#define CSL_ALE_POLICER_DA_SA_REG_DST_INDEX_RESETVAL            (0x00000000U)
#define CSL_ALE_POLICER_DA_SA_REG_DST_INDEX_MAX                 (0x00001fffU)

#define CSL_ALE_POLICER_DA_SA_REG_SRC_MEN_MASK                  (0x00008000U)
#define CSL_ALE_POLICER_DA_SA_REG_SRC_MEN_SHIFT                 (15U)
#define CSL_ALE_POLICER_DA_SA_REG_SRC_MEN_RESETVAL              (0x00000000U)
#define CSL_ALE_POLICER_DA_SA_REG_SRC_MEN_MAX                   (0x00000001U)

#define CSL_ALE_POLICER_DA_SA_REG_SRC_INDEX_MASK                (0x00001FFFU)
#define CSL_ALE_POLICER_DA_SA_REG_SRC_INDEX_SHIFT               (0U)
#define CSL_ALE_POLICER_DA_SA_REG_SRC_INDEX_RESETVAL            (0x00000000U)
#define CSL_ALE_POLICER_DA_SA_REG_SRC_INDEX_MAX                 (0x00001fffU)

#define CSL_ALE_POLICER_DA_SA_REG_RESETVAL                      (0x00000000U)

/* POLICER_VLAN_REG */

#define CSL_ALE_POLICER_VLAN_REG_OVLAN_MEN_MASK                 (0x80000000U)
#define CSL_ALE_POLICER_VLAN_REG_OVLAN_MEN_SHIFT                (31U)
#define CSL_ALE_POLICER_VLAN_REG_OVLAN_MEN_RESETVAL             (0x00000000U)
#define CSL_ALE_POLICER_VLAN_REG_OVLAN_MEN_MAX                  (0x00000001U)

#define CSL_ALE_POLICER_VLAN_REG_OVLAN_INDEX_MASK               (0x1FFF0000U)
#define CSL_ALE_POLICER_VLAN_REG_OVLAN_INDEX_SHIFT              (16U)
#define CSL_ALE_POLICER_VLAN_REG_OVLAN_INDEX_RESETVAL           (0x00000000U)
#define CSL_ALE_POLICER_VLAN_REG_OVLAN_INDEX_MAX                (0x00001fffU)

#define CSL_ALE_POLICER_VLAN_REG_IVLAN_MEN_MASK                 (0x00008000U)
#define CSL_ALE_POLICER_VLAN_REG_IVLAN_MEN_SHIFT                (15U)
#define CSL_ALE_POLICER_VLAN_REG_IVLAN_MEN_RESETVAL             (0x00000000U)
#define CSL_ALE_POLICER_VLAN_REG_IVLAN_MEN_MAX                  (0x00000001U)

#define CSL_ALE_POLICER_VLAN_REG_IVLAN_INDEX_MASK               (0x00001FFFU)
#define CSL_ALE_POLICER_VLAN_REG_IVLAN_INDEX_SHIFT              (0U)
#define CSL_ALE_POLICER_VLAN_REG_IVLAN_INDEX_RESETVAL           (0x00000000U)
#define CSL_ALE_POLICER_VLAN_REG_IVLAN_INDEX_MAX                (0x00001fffU)

#define CSL_ALE_POLICER_VLAN_REG_RESETVAL                       (0x00000000U)

/* POLICER_ETHERTYPE_IPSA_REG */

#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_MEN_MASK   (0x80000000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_MEN_SHIFT  (31U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_MEN_RESETVAL  (0x00000000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_MEN_MAX    (0x00000001U)

#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_INDEX_MASK  (0x1FFF0000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_INDEX_SHIFT  (16U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_INDEX_RESETVAL  (0x00000000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_INDEX_MAX  (0x00001fffU)

#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_MEN_MASK       (0x00008000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_MEN_SHIFT      (15U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_MEN_RESETVAL   (0x00000000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_MEN_MAX        (0x00000001U)

#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_INDEX_MASK     (0x00001FFFU)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_INDEX_SHIFT    (0U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_INDEX_RESETVAL  (0x00000000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_INDEX_MAX      (0x00001fffU)

#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_RESETVAL             (0x00000000U)

/* POLICER_IPDA_REG */

#define CSL_ALE_POLICER_IPDA_REG_IPDST_MEN_MASK                 (0x80000000U)
#define CSL_ALE_POLICER_IPDA_REG_IPDST_MEN_SHIFT                (31U)
#define CSL_ALE_POLICER_IPDA_REG_IPDST_MEN_RESETVAL             (0x00000000U)
#define CSL_ALE_POLICER_IPDA_REG_IPDST_MEN_MAX                  (0x00000001U)

#define CSL_ALE_POLICER_IPDA_REG_IPDST_INDEX_MASK               (0x1FFF0000U)
#define CSL_ALE_POLICER_IPDA_REG_IPDST_INDEX_SHIFT              (16U)
#define CSL_ALE_POLICER_IPDA_REG_IPDST_INDEX_RESETVAL           (0x00000000U)
#define CSL_ALE_POLICER_IPDA_REG_IPDST_INDEX_MAX                (0x00001fffU)

#define CSL_ALE_POLICER_IPDA_REG_RESETVAL                       (0x00000000U)

/* POLICER_TBL_CTL_REG */

#define CSL_ALE_POLICER_TBL_CTL_REG_WRITE_ENABLE_MASK           (0x80000000U)
#define CSL_ALE_POLICER_TBL_CTL_REG_WRITE_ENABLE_SHIFT          (31U)
#define CSL_ALE_POLICER_TBL_CTL_REG_WRITE_ENABLE_RESETVAL       (0x00000000U)
#define CSL_ALE_POLICER_TBL_CTL_REG_WRITE_ENABLE_MAX            (0x00000001U)

#define CSL_ALE_POLICER_TBL_CTL_REG_POL_TBL_INDEX_MASK          (0x0000001FU)
#define CSL_ALE_POLICER_TBL_CTL_REG_POL_TBL_INDEX_SHIFT         (0U)
#define CSL_ALE_POLICER_TBL_CTL_REG_POL_TBL_INDEX_RESETVAL      (0x00000000U)
#define CSL_ALE_POLICER_TBL_CTL_REG_POL_TBL_INDEX_MAX           (0x0000001fU)

#define CSL_ALE_POLICER_TBL_CTL_REG_RESETVAL                    (0x00000000U)

/* THREAD_DEF_REG */

#define CSL_ALE_THREAD_DEF_REG_ENABLE_MASK                      (0x00008000U)
#define CSL_ALE_THREAD_DEF_REG_ENABLE_SHIFT                     (15U)
#define CSL_ALE_THREAD_DEF_REG_ENABLE_RESETVAL                  (0x00000000U)
#define CSL_ALE_THREAD_DEF_REG_ENABLE_MAX                       (0x00000001U)

#define CSL_ALE_THREAD_DEF_REG_VALUE_MASK                       (0x0000003FU)
#define CSL_ALE_THREAD_DEF_REG_VALUE_SHIFT                      (0U)
#define CSL_ALE_THREAD_DEF_REG_VALUE_RESETVAL                   (0x00000000U)
#define CSL_ALE_THREAD_DEF_REG_VALUE_MAX                        (0x0000003fU)

#define CSL_ALE_THREAD_DEF_REG_RESETVAL                         (0x00000000U)

/* THREAD_CTL_REG */

#define CSL_ALE_THREAD_CTL_REG_ENTRY_PTR_MASK                   (0x0000003FU)
#define CSL_ALE_THREAD_CTL_REG_ENTRY_PTR_SHIFT                  (0U)
#define CSL_ALE_THREAD_CTL_REG_ENTRY_PTR_RESETVAL               (0x00000000U)
#define CSL_ALE_THREAD_CTL_REG_ENTRY_PTR_MAX                    (0x0000003fU)

#define CSL_ALE_THREAD_CTL_REG_RESETVAL                         (0x00000000U)

/* THREAD_VAL_REG */

#define CSL_ALE_THREAD_VAL_REG_ENABLE_MASK                      (0x00008000U)
#define CSL_ALE_THREAD_VAL_REG_ENABLE_SHIFT                     (15U)
#define CSL_ALE_THREAD_VAL_REG_ENABLE_RESETVAL                  (0x00000000U)
#define CSL_ALE_THREAD_VAL_REG_ENABLE_MAX                       (0x00000001U)

#define CSL_ALE_THREAD_VAL_REG_VALUE_MASK                       (0x0000003FU)
#define CSL_ALE_THREAD_VAL_REG_VALUE_SHIFT                      (0U)
#define CSL_ALE_THREAD_VAL_REG_VALUE_RESETVAL                   (0x00000000U)
#define CSL_ALE_THREAD_VAL_REG_VALUE_MAX                        (0x0000003fU)

#define CSL_ALE_THREAD_VAL_REG_RESETVAL                         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
