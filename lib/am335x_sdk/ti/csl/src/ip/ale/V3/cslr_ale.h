/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
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
 *  Name        : cslr_ale.h
*/
#ifndef CSLR_ALE_H_
#define CSLR_ALE_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t IDVER_REG;                 /* idver_reg */
    volatile uint32_t STATUS_REG;                /* status_reg */
    volatile uint32_t CONTROL_REG;               /* control_reg */
    volatile uint32_t CONTROL2_REG;              /* control2_reg */
    volatile uint32_t PRESCALE_REG;              /* prescale_reg */
    volatile uint32_t AGING_TIMER_REG;           /* aging_timer_reg */
    volatile uint8_t  Resv_32[8];
    volatile uint32_t TABLE_CONTROL_REG;         /* table_control_reg */
    volatile uint8_t  Resv_52[16];
    volatile uint32_t TABLE_WORD2_REG;           /* table_word2_reg */
    volatile uint32_t TABLE_WORD1_REG;           /* table_word1_reg */
    volatile uint32_t TABLE_WORD0_REG;           /* table_word0_reg */
    volatile uint32_t PORT_CONTROL_REG[2];       /* port_control_reg */
    volatile uint8_t  Resv_144[72];
    volatile uint32_t UNKNOWN_VLAN_REG;          /* unknown_vlan_reg */
    volatile uint32_t UNKNOWN_MCAST_FLOOD_REG;   /* unknown_mcast_flood_reg */
    volatile uint32_t UNKNOWN_REG_MCAST_FLOOD_REG;   /* unknown_reg_mcast_flood_reg */
    volatile uint32_t FORCE_UNTAGGED_EGRESS_REG;   /* force_untagged_egress_reg */
    volatile uint8_t  Resv_192[32];
#ifndef CSL_MODIFICATION
    volatile uint32_t VLAN_MASK_MUX_REG[8];
#else
    volatile uint32_t VLAN_MASK_MUX0_REG;        /* vlan_mask_mux_reg */
    volatile uint32_t VLAN_MASK_MUX1_REG;        /* vlan_mask_mux_reg */
    volatile uint32_t VLAN_MASK_MUX2_REG;        /* vlan_mask_mux_reg */
    volatile uint32_t VLAN_MASK_MUX3_REG;        /* vlan_mask_mux_reg */
    volatile uint32_t VLAN_MASK_MUX4_REG;        /* vlan_mask_mux_reg */
    volatile uint32_t VLAN_MASK_MUX5_REG;        /* vlan_mask_mux_reg */
    volatile uint32_t VLAN_MASK_MUX6_REG;        /* vlan_mask_mux_reg */
    volatile uint32_t VLAN_MASK_MUX7_REG;        /* vlan_mask_mux_reg */
#endif
    volatile uint8_t  Resv_256[32];
    volatile uint32_t POLICER_PORT_OUI_REG;      /* policer_port_oui_reg */
    volatile uint32_t POLICER_DA_SA_REG;         /* policer_da_sa_reg */
    volatile uint32_t POLICER_VLAN_REG;          /* policer_vlan_reg */
    volatile uint32_t POLICER_ETHERTYPE_IPSA_REG;   /* policer_ethertype_ipsa_reg */
    volatile uint32_t POLICER_IPDA_REG;          /* policer_ipda_reg */
    volatile uint8_t  Resv_280[4];
    volatile uint32_t POLICER_PIR_REG;           /* policer_pir_reg */
    volatile uint32_t POLICER_CIR_REG;           /* policer_cir_reg */
    volatile uint32_t POLICER_TBL_CTL_REG;       /* policer_tbl_ctl_reg */
    volatile uint32_t POLICER_CTL_REG;           /* policer_ctl_reg */
    volatile uint32_t POLICER_TEST_CTL_REG;      /* policer_test_ctl_reg */
    volatile uint32_t POLICER_HIT_STATUS_REG;    /* policer_hit_status_reg */
    volatile uint8_t  Resv_308[4];
    volatile uint32_t THREAD_DEF_REG;            /* thread_def_reg */
    volatile uint32_t THREAD_CTL_REG;            /* thread_ctl_reg */
    volatile uint32_t THREAD_VAL_REG;            /* thread_val_reg */
} CSL_AleRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_ALE_IDVER_REG                                                      (0x00000000U)
#define CSL_ALE_STATUS_REG                                                     (0x00000004U)
#define CSL_ALE_CONTROL_REG                                                    (0x00000008U)
#define CSL_ALE_CONTROL2_REG                                                   (0x0000000CU)
#define CSL_ALE_PRESCALE_REG                                                   (0x00000010U)
#define CSL_ALE_AGING_TIMER_REG                                                (0x00000014U)
#define CSL_ALE_TABLE_CONTROL_REG                                              (0x00000020U)
#define CSL_ALE_TABLE_WORD2_REG                                                (0x00000034U)
#define CSL_ALE_TABLE_WORD1_REG                                                (0x00000038U)
#define CSL_ALE_TABLE_WORD0_REG                                                (0x0000003CU)
#define CSL_ALE_PORT_CONTROL_REG(PORT_CONTROL_REG)                             (0x00000040U+((PORT_CONTROL_REG)*0x4U))
#define CSL_ALE_UNKNOWN_VLAN_REG                                               (0x00000090U)
#define CSL_ALE_UNKNOWN_MCAST_FLOOD_REG                                        (0x00000094U)
#define CSL_ALE_UNKNOWN_REG_MCAST_FLOOD_REG                                    (0x00000098U)
#define CSL_ALE_FORCE_UNTAGGED_EGRESS_REG                                      (0x0000009CU)
#ifndef CSL_MODIFICATION
#define CSL_ALE_VLAN_MASK_MUX_REG(i)                                           (0xC0U + ((i) * (0x4U)))
#else
#define CSL_ALE_VLAN_MASK_MUX0_REG                                             (0x000000C0U)
#define CSL_ALE_VLAN_MASK_MUX1_REG                                             (0x000000C4U)
#define CSL_ALE_VLAN_MASK_MUX2_REG                                             (0x000000C8U)
#define CSL_ALE_VLAN_MASK_MUX3_REG                                             (0x000000CCU)
#define CSL_ALE_VLAN_MASK_MUX4_REG                                             (0x000000D0U)
#define CSL_ALE_VLAN_MASK_MUX5_REG                                             (0x000000D4U)
#define CSL_ALE_VLAN_MASK_MUX6_REG                                             (0x000000D8U)
#define CSL_ALE_VLAN_MASK_MUX7_REG                                             (0x000000DCU)
#endif
#define CSL_ALE_POLICER_PORT_OUI_REG                                           (0x00000100U)
#define CSL_ALE_POLICER_DA_SA_REG                                              (0x00000104U)
#define CSL_ALE_POLICER_VLAN_REG                                               (0x00000108U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG                                     (0x0000010CU)
#define CSL_ALE_POLICER_IPDA_REG                                               (0x00000110U)
#define CSL_ALE_POLICER_PIR_REG                                                (0x00000118U)
#define CSL_ALE_POLICER_CIR_REG                                                (0x0000011CU)
#define CSL_ALE_POLICER_TBL_CTL_REG                                            (0x00000120U)
#define CSL_ALE_POLICER_CTL_REG                                                (0x00000124U)
#define CSL_ALE_POLICER_TEST_CTL_REG                                           (0x00000128U)
#define CSL_ALE_POLICER_HIT_STATUS_REG                                         (0x0000012CU)
#define CSL_ALE_THREAD_DEF_REG                                                 (0x00000134U)
#define CSL_ALE_THREAD_CTL_REG                                                 (0x00000138U)
#define CSL_ALE_THREAD_VAL_REG                                                 (0x0000013CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* IDVER_REG */

#define CSL_ALE_IDVER_REG_MINOR_VER_MASK                                       (0x000000FFU)
#define CSL_ALE_IDVER_REG_MINOR_VER_SHIFT                                      (0x00000000U)
#define CSL_ALE_IDVER_REG_MINOR_VER_RESETVAL                                   (0x00000004U)
#define CSL_ALE_IDVER_REG_MINOR_VER_MAX                                        (0x000000FFU)

#define CSL_ALE_IDVER_REG_MAJOR_VER_MASK                                       (0x00000700U)
#define CSL_ALE_IDVER_REG_MAJOR_VER_SHIFT                                      (0x00000008U)
#define CSL_ALE_IDVER_REG_MAJOR_VER_RESETVAL                                   (0x00000001U)
#define CSL_ALE_IDVER_REG_MAJOR_VER_MAX                                        (0x00000007U)

#define CSL_ALE_IDVER_REG_RTL_VER_MASK                                         (0x0000F800U)
#define CSL_ALE_IDVER_REG_RTL_VER_SHIFT                                        (0x0000000BU)
#define CSL_ALE_IDVER_REG_RTL_VER_RESETVAL                                     (0x00000007U)
#define CSL_ALE_IDVER_REG_RTL_VER_MAX                                          (0x0000001FU)

#define CSL_ALE_IDVER_REG_IDENT_MASK                                           (0xFFFF0000U)
#define CSL_ALE_IDVER_REG_IDENT_SHIFT                                          (0x00000010U)
#define CSL_ALE_IDVER_REG_IDENT_RESETVAL                                       (0x00000029U)
#define CSL_ALE_IDVER_REG_IDENT_MAX                                            (0x0000FFFFU)

#define CSL_ALE_IDVER_REG_RESETVAL                                             (0x00293904U)

/* STATUS_REG */

#define CSL_ALE_STATUS_REG_ENTRIES_DIV_1024_MASK                               (0x000000FFU)
#define CSL_ALE_STATUS_REG_ENTRIES_DIV_1024_SHIFT                              (0x00000000U)
#define CSL_ALE_STATUS_REG_ENTRIES_DIV_1024_RESETVAL                           (0x00000040U)
#define CSL_ALE_STATUS_REG_ENTRIES_DIV_1024_MAX                                (0x000000FFU)

#define CSL_ALE_STATUS_REG_POLICERS_DIV_8_MASK                                 (0x0000FF00U)
#define CSL_ALE_STATUS_REG_POLICERS_DIV_8_SHIFT                                (0x00000008U)
#define CSL_ALE_STATUS_REG_POLICERS_DIV_8_RESETVAL                             (0x00000001U)
#define CSL_ALE_STATUS_REG_POLICERS_DIV_8_MAX                                  (0x000000FFU)

#define CSL_ALE_STATUS_REG_RESETVAL                                            (0x00000140U)

/* CONTROL_REG */

#define CSL_ALE_CONTROL_REG_ENABLE_RATE_LIMIT_MASK                             (0x00000001U)
#define CSL_ALE_CONTROL_REG_ENABLE_RATE_LIMIT_SHIFT                            (0x00000000U)
#define CSL_ALE_CONTROL_REG_ENABLE_RATE_LIMIT_RESETVAL                         (0x00000000U)
#define CSL_ALE_CONTROL_REG_ENABLE_RATE_LIMIT_MAX                              (0x00000001U)

#define CSL_ALE_CONTROL_REG_ENABLE_AUTH_MODE_MASK                              (0x00000002U)
#define CSL_ALE_CONTROL_REG_ENABLE_AUTH_MODE_SHIFT                             (0x00000001U)
#define CSL_ALE_CONTROL_REG_ENABLE_AUTH_MODE_RESETVAL                          (0x00000000U)
#define CSL_ALE_CONTROL_REG_ENABLE_AUTH_MODE_MAX                               (0x00000001U)

#define CSL_ALE_CONTROL_REG_VLAN_AWARE_MASK                                    (0x00000004U)
#define CSL_ALE_CONTROL_REG_VLAN_AWARE_SHIFT                                   (0x00000002U)
#define CSL_ALE_CONTROL_REG_VLAN_AWARE_RESETVAL                                (0x00000000U)
#define CSL_ALE_CONTROL_REG_VLAN_AWARE_MAX                                     (0x00000001U)

#define CSL_ALE_CONTROL_REG_RATE_LIMIT_TX_MASK                                 (0x00000008U)
#define CSL_ALE_CONTROL_REG_RATE_LIMIT_TX_SHIFT                                (0x00000003U)
#define CSL_ALE_CONTROL_REG_RATE_LIMIT_TX_RESETVAL                             (0x00000000U)
#define CSL_ALE_CONTROL_REG_RATE_LIMIT_TX_MAX                                  (0x00000001U)

#define CSL_ALE_CONTROL_REG_BYPASS_MASK                                        (0x00000010U)
#define CSL_ALE_CONTROL_REG_BYPASS_SHIFT                                       (0x00000004U)
#define CSL_ALE_CONTROL_REG_BYPASS_RESETVAL                                    (0x00000000U)
#define CSL_ALE_CONTROL_REG_BYPASS_MAX                                         (0x00000001U)

#define CSL_ALE_CONTROL_REG_ENABLE_OUI_DENY_MASK                               (0x00000020U)
#define CSL_ALE_CONTROL_REG_ENABLE_OUI_DENY_SHIFT                              (0x00000005U)
#define CSL_ALE_CONTROL_REG_ENABLE_OUI_DENY_RESETVAL                           (0x00000000U)
#define CSL_ALE_CONTROL_REG_ENABLE_OUI_DENY_MAX                                (0x00000001U)

#define CSL_ALE_CONTROL_REG_EN_VID0_MODE_MASK                                  (0x00000040U)
#define CSL_ALE_CONTROL_REG_EN_VID0_MODE_SHIFT                                 (0x00000006U)
#define CSL_ALE_CONTROL_REG_EN_VID0_MODE_RESETVAL                              (0x00000000U)
#define CSL_ALE_CONTROL_REG_EN_VID0_MODE_MAX                                   (0x00000001U)

#define CSL_ALE_CONTROL_REG_LEARN_NO_VID_MASK                                  (0x00000080U)
#define CSL_ALE_CONTROL_REG_LEARN_NO_VID_SHIFT                                 (0x00000007U)
#define CSL_ALE_CONTROL_REG_LEARN_NO_VID_RESETVAL                              (0x00000000U)
#define CSL_ALE_CONTROL_REG_LEARN_NO_VID_MAX                                   (0x00000001U)

#define CSL_ALE_CONTROL_REG_UNI_FLOOD_TO_HOST_MASK                             (0x00000100U)
#define CSL_ALE_CONTROL_REG_UNI_FLOOD_TO_HOST_SHIFT                            (0x00000008U)
#define CSL_ALE_CONTROL_REG_UNI_FLOOD_TO_HOST_RESETVAL                         (0x00000000U)
#define CSL_ALE_CONTROL_REG_UNI_FLOOD_TO_HOST_MAX                              (0x00000001U)

#define CSL_ALE_CONTROL_REG_MIRROR_SEN_MASK                                    (0x00000400U)
#define CSL_ALE_CONTROL_REG_MIRROR_SEN_SHIFT                                   (0x0000000AU)
#define CSL_ALE_CONTROL_REG_MIRROR_SEN_RESETVAL                                (0x00000000U)
#define CSL_ALE_CONTROL_REG_MIRROR_SEN_MAX                                     (0x00000001U)

#define CSL_ALE_CONTROL_REG_MIRROR_DEN_MASK                                    (0x00000800U)
#define CSL_ALE_CONTROL_REG_MIRROR_DEN_SHIFT                                   (0x0000000BU)
#define CSL_ALE_CONTROL_REG_MIRROR_DEN_RESETVAL                                (0x00000000U)
#define CSL_ALE_CONTROL_REG_MIRROR_DEN_MAX                                     (0x00000001U)

#define CSL_ALE_CONTROL_REG_MIRROR_MEN_MASK                                    (0x00001000U)
#define CSL_ALE_CONTROL_REG_MIRROR_MEN_SHIFT                                   (0x0000000CU)
#define CSL_ALE_CONTROL_REG_MIRROR_MEN_RESETVAL                                (0x00000000U)
#define CSL_ALE_CONTROL_REG_MIRROR_MEN_MAX                                     (0x00000001U)

#define CSL_ALE_CONTROL_REG_UVLAN_NO_LEARN_MASK                                (0x00002000U)
#define CSL_ALE_CONTROL_REG_UVLAN_NO_LEARN_SHIFT                               (0x0000000DU)
#define CSL_ALE_CONTROL_REG_UVLAN_NO_LEARN_RESETVAL                            (0x00000000U)
#define CSL_ALE_CONTROL_REG_UVLAN_NO_LEARN_MAX                                 (0x00000001U)

#define CSL_ALE_CONTROL_REG_REG_UPD_STATIC_MASK                                (0x00008000U)
#define CSL_ALE_CONTROL_REG_REG_UPD_STATIC_SHIFT                               (0x0000000FU)
#define CSL_ALE_CONTROL_REG_REG_UPD_STATIC_RESETVAL                            (0x00000000U)
#define CSL_ALE_CONTROL_REG_REG_UPD_STATIC_MAX                                 (0x00000001U)

#define CSL_ALE_CONTROL_REG_MIRROR_TOP_MASK                                    (0x00010000U)
#define CSL_ALE_CONTROL_REG_MIRROR_TOP_SHIFT                                   (0x00000010U)
#define CSL_ALE_CONTROL_REG_MIRROR_TOP_RESETVAL                                (0x00000000U)
#define CSL_ALE_CONTROL_REG_MIRROR_TOP_MAX                                     (0x00000001U)

#define CSL_ALE_CONTROL_REG_UPD_BW_CTL_MASK                                    (0x00E00000U)
#define CSL_ALE_CONTROL_REG_UPD_BW_CTL_SHIFT                                   (0x00000015U)
#define CSL_ALE_CONTROL_REG_UPD_BW_CTL_RESETVAL                                (0x00000000U)
#define CSL_ALE_CONTROL_REG_UPD_BW_CTL_MAX                                     (0x00000007U)

#define CSL_ALE_CONTROL_REG_MIRROR_DP_MASK                                     (0x01000000U)
#define CSL_ALE_CONTROL_REG_MIRROR_DP_SHIFT                                    (0x00000018U)
#define CSL_ALE_CONTROL_REG_MIRROR_DP_RESETVAL                                 (0x00000000U)
#define CSL_ALE_CONTROL_REG_MIRROR_DP_MAX                                      (0x00000001U)

#define CSL_ALE_CONTROL_REG_AGE_OUT_NOW_MASK                                   (0x20000000U)
#define CSL_ALE_CONTROL_REG_AGE_OUT_NOW_SHIFT                                  (0x0000001DU)
#define CSL_ALE_CONTROL_REG_AGE_OUT_NOW_RESETVAL                               (0x00000000U)
#define CSL_ALE_CONTROL_REG_AGE_OUT_NOW_MAX                                    (0x00000001U)

#define CSL_ALE_CONTROL_REG_CLEAR_TABLE_MASK                                   (0x40000000U)
#define CSL_ALE_CONTROL_REG_CLEAR_TABLE_SHIFT                                  (0x0000001EU)
#define CSL_ALE_CONTROL_REG_CLEAR_TABLE_RESETVAL                               (0x00000000U)
#define CSL_ALE_CONTROL_REG_CLEAR_TABLE_MAX                                    (0x00000001U)

#define CSL_ALE_CONTROL_REG_ENABLE_MASK                                        (0x80000000U)
#define CSL_ALE_CONTROL_REG_ENABLE_SHIFT                                       (0x0000001FU)
#define CSL_ALE_CONTROL_REG_ENABLE_RESETVAL                                    (0x00000000U)
#define CSL_ALE_CONTROL_REG_ENABLE_MAX                                         (0x00000001U)

#define CSL_ALE_CONTROL_REG_RESETVAL                                           (0x00000000U)

/* CONTROL2_REG */

#define CSL_ALE_CONTROL2_REG_TRK_EN_DST_MASK                                   (0x80000000U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_DST_SHIFT                                  (0x0000001FU)
#define CSL_ALE_CONTROL2_REG_TRK_EN_DST_RESETVAL                               (0x00000000U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_DST_MAX                                    (0x00000001U)

#define CSL_ALE_CONTROL2_REG_TRK_EN_SRC_MASK                                   (0x40000000U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_SRC_SHIFT                                  (0x0000001EU)
#define CSL_ALE_CONTROL2_REG_TRK_EN_SRC_RESETVAL                               (0x00000000U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_SRC_MAX                                    (0x00000001U)

#define CSL_ALE_CONTROL2_REG_TRK_EN_PRI_MASK                                   (0x20000000U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_PRI_SHIFT                                  (0x0000001DU)
#define CSL_ALE_CONTROL2_REG_TRK_EN_PRI_RESETVAL                               (0x00000000U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_PRI_MAX                                    (0x00000001U)

#define CSL_ALE_CONTROL2_REG_TRK_EN_VLAN_MASK                                  (0x08000000U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_VLAN_SHIFT                                 (0x0000001BU)
#define CSL_ALE_CONTROL2_REG_TRK_EN_VLAN_RESETVAL                              (0x00000000U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_VLAN_MAX                                   (0x00000001U)

#define CSL_ALE_CONTROL2_REG_TRK_EN_SIP_MASK                                   (0x02000000U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_SIP_SHIFT                                  (0x00000019U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_SIP_RESETVAL                               (0x00000000U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_SIP_MAX                                    (0x00000001U)

#define CSL_ALE_CONTROL2_REG_TRK_EN_DIP_MASK                                   (0x01000000U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_DIP_SHIFT                                  (0x00000018U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_DIP_RESETVAL                               (0x00000000U)
#define CSL_ALE_CONTROL2_REG_TRK_EN_DIP_MAX                                    (0x00000001U)

#define CSL_ALE_CONTROL2_REG_TRK_BASE_MASK                                     (0x00070000U)
#define CSL_ALE_CONTROL2_REG_TRK_BASE_SHIFT                                    (0x00000010U)
#define CSL_ALE_CONTROL2_REG_TRK_BASE_RESETVAL                                 (0x00000000U)
#define CSL_ALE_CONTROL2_REG_TRK_BASE_MAX                                      (0x00000007U)

#define CSL_ALE_CONTROL2_REG_MIRROR_MIDX_MASK                                  (0x0000003FU)
#define CSL_ALE_CONTROL2_REG_MIRROR_MIDX_SHIFT                                 (0x00000000U)
#define CSL_ALE_CONTROL2_REG_MIRROR_MIDX_RESETVAL                              (0x00000000U)
#define CSL_ALE_CONTROL2_REG_MIRROR_MIDX_MAX                                   (0x0000003FU)

#define CSL_ALE_CONTROL2_REG_RESETVAL                                          (0x00000000U)

/* PRESCALE_REG */

#define CSL_ALE_PRESCALE_REG_PRESCALE_MASK                                     (0x000FFFFFU)
#define CSL_ALE_PRESCALE_REG_PRESCALE_SHIFT                                    (0x00000000U)
#define CSL_ALE_PRESCALE_REG_PRESCALE_RESETVAL                                 (0x00000000U)
#define CSL_ALE_PRESCALE_REG_PRESCALE_MAX                                      (0x000FFFFFU)

#define CSL_ALE_PRESCALE_REG_RESETVAL                                          (0x00000000U)

/* AGING_TIMER_REG */

#define CSL_ALE_AGING_TIMER_REG_AGING_TIMER_MASK                               (0x00FFFFFFU)
#define CSL_ALE_AGING_TIMER_REG_AGING_TIMER_SHIFT                              (0x00000000U)
#define CSL_ALE_AGING_TIMER_REG_AGING_TIMER_RESETVAL                           (0x00000000U)
#define CSL_ALE_AGING_TIMER_REG_AGING_TIMER_MAX                                (0x00FFFFFFU)

#define CSL_ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE_MASK                        (0x40000000U)
#define CSL_ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE_SHIFT                       (0x0000001EU)
#define CSL_ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE_RESETVAL                    (0x00000000U)
#define CSL_ALE_AGING_TIMER_REG_PRESCALE_2_DISABLE_MAX                         (0x00000001U)

#define CSL_ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE_MASK                        (0x80000000U)
#define CSL_ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE_SHIFT                       (0x0000001FU)
#define CSL_ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE_RESETVAL                    (0x00000000U)
#define CSL_ALE_AGING_TIMER_REG_PRESCALE_1_DISABLE_MAX                         (0x00000001U)

#define CSL_ALE_AGING_TIMER_REG_RESETVAL                                       (0x00000000U)

/* TABLE_CONTROL_REG */

#define CSL_ALE_TABLE_CONTROL_REG_ENTRY_POINTER_MASK                           (0x0000003FU)
#define CSL_ALE_TABLE_CONTROL_REG_ENTRY_POINTER_SHIFT                          (0x00000000U)
#define CSL_ALE_TABLE_CONTROL_REG_ENTRY_POINTER_RESETVAL                       (0x00000000U)
#define CSL_ALE_TABLE_CONTROL_REG_ENTRY_POINTER_MAX                            (0x0000003FU)

#define CSL_ALE_TABLE_CONTROL_REG_WRITE_RDZ_MASK                               (0x80000000U)
#define CSL_ALE_TABLE_CONTROL_REG_WRITE_RDZ_SHIFT                              (0x0000001FU)
#define CSL_ALE_TABLE_CONTROL_REG_WRITE_RDZ_RESETVAL                           (0x00000000U)
#define CSL_ALE_TABLE_CONTROL_REG_WRITE_RDZ_MAX                                (0x00000001U)

#define CSL_ALE_TABLE_CONTROL_REG_RESETVAL                                     (0x00000000U)

/* TABLE_WORD2_REG */

#define CSL_ALE_TABLE_WORD2_REG_ENTRY_71_64_MASK                               (0x0000007FU)
#define CSL_ALE_TABLE_WORD2_REG_ENTRY_71_64_SHIFT                              (0x00000000U)
#define CSL_ALE_TABLE_WORD2_REG_ENTRY_71_64_RESETVAL                           (0x00000000U)
#define CSL_ALE_TABLE_WORD2_REG_ENTRY_71_64_MAX                                (0x0000007FU)

#define CSL_ALE_TABLE_WORD2_REG_RESETVAL                                       (0x00000000U)

/* TABLE_WORD1_REG */

#define CSL_ALE_TABLE_WORD1_REG_ENTRY_63_32_MASK                               (0xFFFFFFFFU)
#define CSL_ALE_TABLE_WORD1_REG_ENTRY_63_32_SHIFT                              (0x00000000U)
#define CSL_ALE_TABLE_WORD1_REG_ENTRY_63_32_RESETVAL                           (0x00000000U)
#define CSL_ALE_TABLE_WORD1_REG_ENTRY_63_32_MAX                                (0xFFFFFFFFU)

#define CSL_ALE_TABLE_WORD1_REG_RESETVAL                                       (0x00000000U)

/* TABLE_WORD0_REG */

#define CSL_ALE_TABLE_WORD0_REG_ENTRY_31_0_MASK                                (0xFFFFFFFFU)
#define CSL_ALE_TABLE_WORD0_REG_ENTRY_31_0_SHIFT                               (0x00000000U)
#define CSL_ALE_TABLE_WORD0_REG_ENTRY_31_0_RESETVAL                            (0x00000000U)
#define CSL_ALE_TABLE_WORD0_REG_ENTRY_31_0_MAX                                 (0xFFFFFFFFU)

#define CSL_ALE_TABLE_WORD0_REG_RESETVAL                                       (0x00000000U)

/* PORT_CONTROL_REG */
#define CSL_ALE_PORT_CONTROL_REG_PORT_STATE_MASK                               (0x00000003U)
#define CSL_ALE_PORT_CONTROL_REG_PORT_STATE_SHIFT                              (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_PORT_STATE_RESETVAL                           (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_PORT_STATE_MAX                                (0x00000003U)

#define CSL_ALE_PORT_CONTROL_REG_DROP_UNTAGGED_MASK                            (0x00000004U)
#define CSL_ALE_PORT_CONTROL_REG_DROP_UNTAGGED_SHIFT                           (0x00000002U)
#define CSL_ALE_PORT_CONTROL_REG_DROP_UNTAGGED_RESETVAL                        (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_DROP_UNTAGGED_MAX                             (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_VID_INGRESS_CHECK_MASK                        (0x00000008U)
#define CSL_ALE_PORT_CONTROL_REG_VID_INGRESS_CHECK_SHIFT                       (0x00000003U)
#define CSL_ALE_PORT_CONTROL_REG_VID_INGRESS_CHECK_RESETVAL                    (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_VID_INGRESS_CHECK_MAX                         (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_NO_LEARN_MASK                                 (0x00000010U)
#define CSL_ALE_PORT_CONTROL_REG_NO_LEARN_SHIFT                                (0x00000004U)
#define CSL_ALE_PORT_CONTROL_REG_NO_LEARN_RESETVAL                             (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_NO_LEARN_MAX                                  (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_NO_SA_UPDATE_MASK                             (0x00000020U)
#define CSL_ALE_PORT_CONTROL_REG_NO_SA_UPDATE_SHIFT                            (0x00000005U)
#define CSL_ALE_PORT_CONTROL_REG_NO_SA_UPDATE_RESETVAL                         (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_NO_SA_UPDATE_MAX                              (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_MIRROR_SP_MASK                                (0x00000080U)
#define CSL_ALE_PORT_CONTROL_REG_MIRROR_SP_SHIFT                               (0x00000007U)
#define CSL_ALE_PORT_CONTROL_REG_MIRROR_SP_RESETVAL                            (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_MIRROR_SP_MAX                                 (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_TRUNK_NUMBER_MASK                             (0x00000300U)
#define CSL_ALE_PORT_CONTROL_REG_TRUNK_NUMBER_SHIFT                            (0x00000008U)
#define CSL_ALE_PORT_CONTROL_REG_TRUNK_NUMBER_RESETVAL                         (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_TRUNK_NUMBER_MAX                              (0x00000003U)

#define CSL_ALE_PORT_CONTROL_REG_TRUNK_EN_MASK                                 (0x00000400U)
#define CSL_ALE_PORT_CONTROL_REG_TRUNK_EN_SHIFT                                (0x0000000AU)
#define CSL_ALE_PORT_CONTROL_REG_TRUNK_EN_RESETVAL                             (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_TRUNK_EN_MAX                                  (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_MAC_ONLY_MASK                                 (0x00000800U)
#define CSL_ALE_PORT_CONTROL_REG_MAC_ONLY_SHIFT                                (0x0000000BU)
#define CSL_ALE_PORT_CONTROL_REG_MAC_ONLY_RESETVAL                             (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_MAC_ONLY_MAX                                  (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_DISABLE_AUTH_MODE_MASK                        (0x00001000U)
#define CSL_ALE_PORT_CONTROL_REG_DISABLE_AUTH_MODE_SHIFT                       (0x0000000CU)
#define CSL_ALE_PORT_CONTROL_REG_DISABLE_AUTH_MODE_RESETVAL                    (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_DISABLE_AUTH_MODE_MAX                         (0x00000001U)

#ifndef CSL_MODIFICATION
#define CSL_ALE_PORT_CONTROL_REG_MACONLY_CAF_MASK                              (0x00002000U)
#define CSL_ALE_PORT_CONTROL_REG_MACONLY_CAF_SHIFT                             (0x0000000DU)
#define CSL_ALE_PORT_CONTROL_REG_MACONLY_CAF_RESETVAL                          (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_MACONLY_CAF_MAX                               (0x00000001U)
#else
#define CSL_ALE_PORT_CONTROL_REG_MAC_ONLY_CAF_MASK                             (0x00002000U)
#define CSL_ALE_PORT_CONTROL_REG_MAC_ONLY_CAF_SHIFT                            (0x0000000DU)
#define CSL_ALE_PORT_CONTROL_REG_MAC_ONLY_CAF_RESETVAL                         (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_MAC_ONLY_CAF_MAX                              (0x00000001U)
#endif

#define CSL_ALE_PORT_CONTROL_REG_DROP_DUAL_VLAN_MASK                           (0x00004000U)
#define CSL_ALE_PORT_CONTROL_REG_DROP_DUAL_VLAN_SHIFT                          (0x0000000EU)
#define CSL_ALE_PORT_CONTROL_REG_DROP_DUAL_VLAN_RESETVAL                       (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_DROP_DUAL_VLAN_MAX                            (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_DROP_DBL_VLAN_MASK                            (0x00008000U)
#define CSL_ALE_PORT_CONTROL_REG_DROP_DBL_VLAN_SHIFT                           (0x0000000FU)
#define CSL_ALE_PORT_CONTROL_REG_DROP_DBL_VLAN_RESETVAL                        (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_DROP_DBL_VLAN_MAX                             (0x00000001U)

#define CSL_ALE_PORT_CONTROL_REG_MCAST_LIMIT_MASK                              (0x00FF0000U)
#define CSL_ALE_PORT_CONTROL_REG_MCAST_LIMIT_SHIFT                             (0x00000010U)
#define CSL_ALE_PORT_CONTROL_REG_MCAST_LIMIT_RESETVAL                          (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_MCAST_LIMIT_MAX                               (0x000000FFU)

#define CSL_ALE_PORT_CONTROL_REG_BCAST_LIMIT_MASK                              (0xFF000000U)
#define CSL_ALE_PORT_CONTROL_REG_BCAST_LIMIT_SHIFT                             (0x00000018U)
#define CSL_ALE_PORT_CONTROL_REG_BCAST_LIMIT_RESETVAL                          (0x00000000U)
#define CSL_ALE_PORT_CONTROL_REG_BCAST_LIMIT_MAX                               (0x000000FFU)

#define CSL_ALE_PORT_CONTROL_REG_RESETVAL                                      (0x00000000U)

/* UNKNOWN_VLAN_REG */

#define CSL_ALE_UNKNOWN_VLAN_REG_LIST_MASK                                     (0x00000003U)
#define CSL_ALE_UNKNOWN_VLAN_REG_LIST_SHIFT                                    (0x00000000U)
#define CSL_ALE_UNKNOWN_VLAN_REG_LIST_RESETVAL                                 (0x00000000U)
#define CSL_ALE_UNKNOWN_VLAN_REG_LIST_MAX                                      (0x00000003U)

#define CSL_ALE_UNKNOWN_VLAN_REG_RESETVAL                                      (0x00000000U)

/* UNKNOWN_MCAST_FLOOD_REG */

#define CSL_ALE_UNKNOWN_MCAST_FLOOD_REG_MASK_MASK                              (0x00000003U)
#define CSL_ALE_UNKNOWN_MCAST_FLOOD_REG_MASK_SHIFT                             (0x00000000U)
#define CSL_ALE_UNKNOWN_MCAST_FLOOD_REG_MASK_RESETVAL                          (0x00000000U)
#define CSL_ALE_UNKNOWN_MCAST_FLOOD_REG_MASK_MAX                               (0x00000003U)

#define CSL_ALE_UNKNOWN_MCAST_FLOOD_REG_RESETVAL                               (0x00000000U)

/* UNKNOWN_REG_MCAST_FLOOD_REG */

#define CSL_ALE_UNKNOWN_REG_MCAST_FLOOD_REG_MASK_MASK                          (0x00000003U)
#define CSL_ALE_UNKNOWN_REG_MCAST_FLOOD_REG_MASK_SHIFT                         (0x00000000U)
#define CSL_ALE_UNKNOWN_REG_MCAST_FLOOD_REG_MASK_RESETVAL                      (0x00000000U)
#define CSL_ALE_UNKNOWN_REG_MCAST_FLOOD_REG_MASK_MAX                           (0x00000003U)

#define CSL_ALE_UNKNOWN_REG_MCAST_FLOOD_REG_RESETVAL                           (0x00000000U)

/* FORCE_UNTAGGED_EGRESS_REG */

#define CSL_ALE_FORCE_UNTAGGED_EGRESS_REG_MASK_MASK                            (0x00000003U)
#define CSL_ALE_FORCE_UNTAGGED_EGRESS_REG_MASK_SHIFT                           (0x00000000U)
#define CSL_ALE_FORCE_UNTAGGED_EGRESS_REG_MASK_RESETVAL                        (0x00000000U)
#define CSL_ALE_FORCE_UNTAGGED_EGRESS_REG_MASK_MAX                             (0x00000003U)

#define CSL_ALE_FORCE_UNTAGGED_EGRESS_REG_RESETVAL                             (0x00000000U)

#ifndef CSL_MODIFICATION
/* VLAN_MASK_MUX_REG */
#define CSL_ALE_VLAN_MASK_MUX_REG_MASK_MASK                                    (0x00000003U)
#define CSL_ALE_VLAN_MASK_MUX_REG_MASK_SHIFT                                   (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX_REG_MASK_RESETVAL                                (0x00000003U)
#define CSL_ALE_VLAN_MASK_MUX_REG_MASK_MAX                                     (0x00000003U)

#define CSL_ALE_VLAN_MASK_MUX_REG_RESETVAL                                     (0x00000000U)
#else
/* VLAN_MASK_MUX0_REG */

#define CSL_ALE_VLAN_MASK_MUX0_REG_MASK_MASK                                   (0x00000003U)
#define CSL_ALE_VLAN_MASK_MUX0_REG_MASK_SHIFT                                  (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX0_REG_MASK_RESETVAL                               (0x00000003U)
#define CSL_ALE_VLAN_MASK_MUX0_REG_MASK_MAX                                    (0x00000003U)

#define CSL_ALE_VLAN_MASK_MUX0_REG_RESETVAL                                    (0x00000003U)

/* VLAN_MASK_MUX1_REG */

#define CSL_ALE_VLAN_MASK_MUX1_REG_MASK_MASK                                   (0x00000003U)
#define CSL_ALE_VLAN_MASK_MUX1_REG_MASK_SHIFT                                  (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX1_REG_MASK_RESETVAL                               (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX1_REG_MASK_MAX                                    (0x00000003U)

#define CSL_ALE_VLAN_MASK_MUX1_REG_RESETVAL                                    (0x00000000U)

/* VLAN_MASK_MUX2_REG */

#define CSL_ALE_VLAN_MASK_MUX2_REG_MASK_MASK                                   (0x00000003U)
#define CSL_ALE_VLAN_MASK_MUX2_REG_MASK_SHIFT                                  (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX2_REG_MASK_RESETVAL                               (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX2_REG_MASK_MAX                                    (0x00000003U)

#define CSL_ALE_VLAN_MASK_MUX2_REG_RESETVAL                                    (0x00000000U)

/* VLAN_MASK_MUX3_REG */

#define CSL_ALE_VLAN_MASK_MUX3_REG_MASK_MASK                                   (0x00000003U)
#define CSL_ALE_VLAN_MASK_MUX3_REG_MASK_SHIFT                                  (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX3_REG_MASK_RESETVAL                               (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX3_REG_MASK_MAX                                    (0x00000003U)

#define CSL_ALE_VLAN_MASK_MUX3_REG_RESETVAL                                    (0x00000000U)

/* VLAN_MASK_MUX4_REG */

#define CSL_ALE_VLAN_MASK_MUX4_REG_MASK_MASK                                   (0x00000003U)
#define CSL_ALE_VLAN_MASK_MUX4_REG_MASK_SHIFT                                  (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX4_REG_MASK_RESETVAL                               (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX4_REG_MASK_MAX                                    (0x00000003U)

#define CSL_ALE_VLAN_MASK_MUX4_REG_RESETVAL                                    (0x00000000U)

/* VLAN_MASK_MUX5_REG */

#define CSL_ALE_VLAN_MASK_MUX5_REG_MASK_MASK                                   (0x00000003U)
#define CSL_ALE_VLAN_MASK_MUX5_REG_MASK_SHIFT                                  (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX5_REG_MASK_RESETVAL                               (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX5_REG_MASK_MAX                                    (0x00000003U)

#define CSL_ALE_VLAN_MASK_MUX5_REG_RESETVAL                                    (0x00000000U)

/* VLAN_MASK_MUX6_REG */

#define CSL_ALE_VLAN_MASK_MUX6_REG_MASK_MASK                                   (0x00000003U)
#define CSL_ALE_VLAN_MASK_MUX6_REG_MASK_SHIFT                                  (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX6_REG_MASK_RESETVAL                               (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX6_REG_MASK_MAX                                    (0x00000003U)

#define CSL_ALE_VLAN_MASK_MUX6_REG_RESETVAL                                    (0x00000000U)

/* VLAN_MASK_MUX7_REG */

#define CSL_ALE_VLAN_MASK_MUX7_REG_MASK_MASK                                   (0x00000003U)
#define CSL_ALE_VLAN_MASK_MUX7_REG_MASK_SHIFT                                  (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX7_REG_MASK_RESETVAL                               (0x00000000U)
#define CSL_ALE_VLAN_MASK_MUX7_REG_MASK_MAX                                    (0x00000003U)

#define CSL_ALE_VLAN_MASK_MUX7_REG_RESETVAL                                    (0x00000000U)

#endif

/* POLICER_PORT_OUI_REG */

#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_MEN_MASK                             (0x80000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_MEN_SHIFT                            (0x0000001FU)
#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_MEN_RESETVAL                         (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_MEN_MAX                              (0x00000001U)

#define CSL_ALE_POLICER_PORT_OUI_REG_TRUNK_ID_MASK                             (0x40000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_TRUNK_ID_SHIFT                            (0x0000001EU)
#define CSL_ALE_POLICER_PORT_OUI_REG_TRUNK_ID_RESETVAL                         (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_TRUNK_ID_MAX                              (0x00000001U)

#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_NUM_MASK                             (0x02000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_NUM_SHIFT                            (0x00000019U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_NUM_RESETVAL                         (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PORT_NUM_MAX                              (0x00000001U)

#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_MEN_MASK                              (0x00080000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_MEN_SHIFT                             (0x00000013U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_MEN_RESETVAL                          (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_MEN_MAX                               (0x00000001U)

#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_VAL_MASK                              (0x00070000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_VAL_SHIFT                             (0x00000010U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_VAL_RESETVAL                          (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_PRI_VAL_MAX                               (0x00000007U)

#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_MEN_MASK                              (0x00008000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_MEN_SHIFT                             (0x0000000FU)
#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_MEN_RESETVAL                          (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_MEN_MAX                               (0x00000001U)

#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_INDEX_MASK                            (0x0000003FU)
#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_INDEX_SHIFT                           (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_INDEX_RESETVAL                        (0x00000000U)
#define CSL_ALE_POLICER_PORT_OUI_REG_OUI_INDEX_MAX                             (0x0000003FU)

#define CSL_ALE_POLICER_PORT_OUI_REG_RESETVAL                                  (0x00000000U)

/* POLICER_DA_SA_REG */

#define CSL_ALE_POLICER_DA_SA_REG_DST_MEN_MASK                                 (0x80000000U)
#define CSL_ALE_POLICER_DA_SA_REG_DST_MEN_SHIFT                                (0x0000001FU)
#define CSL_ALE_POLICER_DA_SA_REG_DST_MEN_RESETVAL                             (0x00000000U)
#define CSL_ALE_POLICER_DA_SA_REG_DST_MEN_MAX                                  (0x00000001U)

#define CSL_ALE_POLICER_DA_SA_REG_DST_INDEX_MASK                               (0x003F0000U)
#define CSL_ALE_POLICER_DA_SA_REG_DST_INDEX_SHIFT                              (0x00000010U)
#define CSL_ALE_POLICER_DA_SA_REG_DST_INDEX_RESETVAL                           (0x00000000U)
#define CSL_ALE_POLICER_DA_SA_REG_DST_INDEX_MAX                                (0x0000003FU)

#define CSL_ALE_POLICER_DA_SA_REG_SRC_MEN_MASK                                 (0x00008000U)
#define CSL_ALE_POLICER_DA_SA_REG_SRC_MEN_SHIFT                                (0x0000000FU)
#define CSL_ALE_POLICER_DA_SA_REG_SRC_MEN_RESETVAL                             (0x00000000U)
#define CSL_ALE_POLICER_DA_SA_REG_SRC_MEN_MAX                                  (0x00000001U)

#define CSL_ALE_POLICER_DA_SA_REG_SRC_INDEX_MASK                               (0x0000003FU)
#define CSL_ALE_POLICER_DA_SA_REG_SRC_INDEX_SHIFT                              (0x00000000U)
#define CSL_ALE_POLICER_DA_SA_REG_SRC_INDEX_RESETVAL                           (0x00000000U)
#define CSL_ALE_POLICER_DA_SA_REG_SRC_INDEX_MAX                                (0x0000003FU)

#define CSL_ALE_POLICER_DA_SA_REG_RESETVAL                                     (0x00000000U)

/* POLICER_VLAN_REG */

#define CSL_ALE_POLICER_VLAN_REG_OVLAN_MEN_MASK                                (0x80000000U)
#define CSL_ALE_POLICER_VLAN_REG_OVLAN_MEN_SHIFT                               (0x0000001FU)
#define CSL_ALE_POLICER_VLAN_REG_OVLAN_MEN_RESETVAL                            (0x00000000U)
#define CSL_ALE_POLICER_VLAN_REG_OVLAN_MEN_MAX                                 (0x00000001U)

#define CSL_ALE_POLICER_VLAN_REG_OVLAN_INDEX_MASK                              (0x003F0000U)
#define CSL_ALE_POLICER_VLAN_REG_OVLAN_INDEX_SHIFT                             (0x00000010U)
#define CSL_ALE_POLICER_VLAN_REG_OVLAN_INDEX_RESETVAL                          (0x00000000U)
#define CSL_ALE_POLICER_VLAN_REG_OVLAN_INDEX_MAX                               (0x0000003FU)

#define CSL_ALE_POLICER_VLAN_REG_IVLAN_MEN_MASK                                (0x00008000U)
#define CSL_ALE_POLICER_VLAN_REG_IVLAN_MEN_SHIFT                               (0x0000000FU)
#define CSL_ALE_POLICER_VLAN_REG_IVLAN_MEN_RESETVAL                            (0x00000000U)
#define CSL_ALE_POLICER_VLAN_REG_IVLAN_MEN_MAX                                 (0x00000001U)

#define CSL_ALE_POLICER_VLAN_REG_IVLAN_INDEX_MASK                              (0x0000003FU)
#define CSL_ALE_POLICER_VLAN_REG_IVLAN_INDEX_SHIFT                             (0x00000000U)
#define CSL_ALE_POLICER_VLAN_REG_IVLAN_INDEX_RESETVAL                          (0x00000000U)
#define CSL_ALE_POLICER_VLAN_REG_IVLAN_INDEX_MAX                               (0x0000003FU)

#define CSL_ALE_POLICER_VLAN_REG_RESETVAL                                      (0x00000000U)

/* POLICER_ETHERTYPE_IPSA_REG */

#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_MEN_MASK                  (0x80000000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_MEN_SHIFT                 (0x0000001FU)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_MEN_RESETVAL              (0x00000000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_MEN_MAX                   (0x00000001U)

#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_INDEX_MASK                (0x003F0000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_INDEX_SHIFT               (0x00000010U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_INDEX_RESETVAL            (0x00000000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_ETHERTYPE_INDEX_MAX                 (0x0000003FU)

#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_MEN_MASK                      (0x00008000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_MEN_SHIFT                     (0x0000000FU)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_MEN_RESETVAL                  (0x00000000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_MEN_MAX                       (0x00000001U)

#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_INDEX_MASK                    (0x0000003FU)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_INDEX_SHIFT                   (0x00000000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_INDEX_RESETVAL                (0x00000000U)
#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_IPSRC_INDEX_MAX                     (0x0000003FU)

#define CSL_ALE_POLICER_ETHERTYPE_IPSA_REG_RESETVAL                            (0x00000000U)

/* POLICER_IPDA_REG */

#define CSL_ALE_POLICER_IPDA_REG_IPDST_MEN_MASK                                (0x80000000U)
#define CSL_ALE_POLICER_IPDA_REG_IPDST_MEN_SHIFT                               (0x0000001FU)
#define CSL_ALE_POLICER_IPDA_REG_IPDST_MEN_RESETVAL                            (0x00000000U)
#define CSL_ALE_POLICER_IPDA_REG_IPDST_MEN_MAX                                 (0x00000001U)

#define CSL_ALE_POLICER_IPDA_REG_IPDST_INDEX_MASK                              (0x003F0000U)
#define CSL_ALE_POLICER_IPDA_REG_IPDST_INDEX_SHIFT                             (0x00000010U)
#define CSL_ALE_POLICER_IPDA_REG_IPDST_INDEX_RESETVAL                          (0x00000000U)
#define CSL_ALE_POLICER_IPDA_REG_IPDST_INDEX_MAX                               (0x0000003FU)

#define CSL_ALE_POLICER_IPDA_REG_RESETVAL                                      (0x00000000U)

/* POLICER_PIR_REG */

#define CSL_ALE_POLICER_PIR_REG_PRI_IDLE_INC_VAL_MASK                          (0xFFFFFFFFU)
#define CSL_ALE_POLICER_PIR_REG_PRI_IDLE_INC_VAL_SHIFT                         (0x00000000U)
#define CSL_ALE_POLICER_PIR_REG_PRI_IDLE_INC_VAL_RESETVAL                      (0x00000000U)
#define CSL_ALE_POLICER_PIR_REG_PRI_IDLE_INC_VAL_MAX                           (0xFFFFFFFFU)

#define CSL_ALE_POLICER_PIR_REG_RESETVAL                                       (0x00000000U)

/* POLICER_CIR_REG */

#define CSL_ALE_POLICER_CIR_REG_CIR_IDLE_INC_VAL_MASK                          (0xFFFFFFFFU)
#define CSL_ALE_POLICER_CIR_REG_CIR_IDLE_INC_VAL_SHIFT                         (0x00000000U)
#define CSL_ALE_POLICER_CIR_REG_CIR_IDLE_INC_VAL_RESETVAL                      (0x00000000U)
#define CSL_ALE_POLICER_CIR_REG_CIR_IDLE_INC_VAL_MAX                           (0xFFFFFFFFU)

#define CSL_ALE_POLICER_CIR_REG_RESETVAL                                       (0x00000000U)

/* POLICER_TBL_CTL_REG */

#define CSL_ALE_POLICER_TBL_CTL_REG_WRITE_ENABLE_MASK                          (0x80000000U)
#define CSL_ALE_POLICER_TBL_CTL_REG_WRITE_ENABLE_SHIFT                         (0x0000001FU)
#define CSL_ALE_POLICER_TBL_CTL_REG_WRITE_ENABLE_RESETVAL                      (0x00000000U)
#define CSL_ALE_POLICER_TBL_CTL_REG_WRITE_ENABLE_MAX                           (0x00000001U)

#define CSL_ALE_POLICER_TBL_CTL_REG_POL_TBL_INDEX_MASK                         (0x00000007U)
#define CSL_ALE_POLICER_TBL_CTL_REG_POL_TBL_INDEX_SHIFT                        (0x00000000U)
#define CSL_ALE_POLICER_TBL_CTL_REG_POL_TBL_INDEX_RESETVAL                     (0x00000000U)
#define CSL_ALE_POLICER_TBL_CTL_REG_POL_TBL_INDEX_MAX                          (0x00000007U)

#define CSL_ALE_POLICER_TBL_CTL_REG_RESETVAL                                   (0x00000000U)

/* POLICER_CTL_REG */

#define CSL_ALE_POLICER_CTL_REG_POL_EN_MASK                                    (0x80000000U)
#define CSL_ALE_POLICER_CTL_REG_POL_EN_SHIFT                                   (0x0000001FU)
#define CSL_ALE_POLICER_CTL_REG_POL_EN_RESETVAL                                (0x00000000U)
#define CSL_ALE_POLICER_CTL_REG_POL_EN_MAX                                     (0x00000001U)

#define CSL_ALE_POLICER_CTL_REG_RED_DROP_EN_MASK                               (0x20000000U)
#define CSL_ALE_POLICER_CTL_REG_RED_DROP_EN_SHIFT                              (0x0000001DU)
#define CSL_ALE_POLICER_CTL_REG_RED_DROP_EN_RESETVAL                           (0x00000000U)
#define CSL_ALE_POLICER_CTL_REG_RED_DROP_EN_MAX                                (0x00000001U)

#define CSL_ALE_POLICER_CTL_REG_YELLOW_DROP_EN_MASK                            (0x10000000U)
#define CSL_ALE_POLICER_CTL_REG_YELLOW_DROP_EN_SHIFT                           (0x0000001CU)
#define CSL_ALE_POLICER_CTL_REG_YELLOW_DROP_EN_RESETVAL                        (0x00000000U)
#define CSL_ALE_POLICER_CTL_REG_YELLOW_DROP_EN_MAX                             (0x00000001U)

#define CSL_ALE_POLICER_CTL_REG_YELLOW_THRESH_MASK                             (0x07000000U)
#define CSL_ALE_POLICER_CTL_REG_YELLOW_THRESH_SHIFT                            (0x00000018U)
#define CSL_ALE_POLICER_CTL_REG_YELLOW_THRESH_RESETVAL                         (0x00000000U)
#define CSL_ALE_POLICER_CTL_REG_YELLOW_THRESH_MAX                              (0x00000007U)

#define CSL_ALE_POLICER_CTL_REG_POL_MATCH_MODE_MASK                            (0x00C00000U)
#define CSL_ALE_POLICER_CTL_REG_POL_MATCH_MODE_SHIFT                           (0x00000016U)
#define CSL_ALE_POLICER_CTL_REG_POL_MATCH_MODE_RESETVAL                        (0x00000000U)
#define CSL_ALE_POLICER_CTL_REG_POL_MATCH_MODE_MAX                             (0x00000003U)

#define CSL_ALE_POLICER_CTL_REG_RESETVAL                                       (0x00000000U)

/* POLICER_TEST_CTL_REG */

#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_MASK                              (0x80000000U)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_SHIFT                             (0x0000001FU)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_RESETVAL                          (0x00000000U)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_MAX                               (0x00000001U)

#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_RED_MASK                          (0x40000000U)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_RED_SHIFT                         (0x0000001EU)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_RED_RESETVAL                      (0x00000000U)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_RED_MAX                           (0x00000001U)

#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_YELLOW_MASK                       (0x20000000U)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_YELLOW_SHIFT                      (0x0000001DU)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_YELLOW_RESETVAL                   (0x00000000U)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_YELLOW_MAX                        (0x00000001U)

#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_SELECTED_MASK                     (0x10000000U)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_SELECTED_SHIFT                    (0x0000001CU)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_SELECTED_RESETVAL                 (0x00000000U)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_CLR_SELECTED_MAX                      (0x00000001U)

#define CSL_ALE_POLICER_TEST_CTL_REG_POL_TEST_ENTRY_MASK                       (0x00000007U)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_TEST_ENTRY_SHIFT                      (0x00000000U)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_TEST_ENTRY_RESETVAL                   (0x00000000U)
#define CSL_ALE_POLICER_TEST_CTL_REG_POL_TEST_ENTRY_MAX                        (0x00000007U)

#define CSL_ALE_POLICER_TEST_CTL_REG_RESETVAL                                  (0x00000000U)

/* POLICER_HIT_STATUS_REG */

#define CSL_ALE_POLICER_HIT_STATUS_REG_POL_HIT_MASK                            (0x80000000U)
#define CSL_ALE_POLICER_HIT_STATUS_REG_POL_HIT_SHIFT                           (0x0000001FU)
#define CSL_ALE_POLICER_HIT_STATUS_REG_POL_HIT_RESETVAL                        (0x00000000U)
#define CSL_ALE_POLICER_HIT_STATUS_REG_POL_HIT_MAX                             (0x00000001U)

#define CSL_ALE_POLICER_HIT_STATUS_REG_POL_HIT_RED_MASK                        (0x40000000U)
#define CSL_ALE_POLICER_HIT_STATUS_REG_POL_HIT_RED_SHIFT                       (0x0000001EU)
#define CSL_ALE_POLICER_HIT_STATUS_REG_POL_HIT_RED_RESETVAL                    (0x00000000U)
#define CSL_ALE_POLICER_HIT_STATUS_REG_POL_HIT_RED_MAX                         (0x00000001U)

#define CSL_ALE_POLICER_HIT_STATUS_REG_POL_HIT_YELLOW_MASK                     (0x20000000U)
#define CSL_ALE_POLICER_HIT_STATUS_REG_POL_HIT_YELLOW_SHIFT                    (0x0000001DU)
#define CSL_ALE_POLICER_HIT_STATUS_REG_POL_HIT_YELLOW_RESETVAL                 (0x00000000U)
#define CSL_ALE_POLICER_HIT_STATUS_REG_POL_HIT_YELLOW_MAX                      (0x00000001U)

#define CSL_ALE_POLICER_HIT_STATUS_REG_RESETVAL                                (0x00000000U)

/* THREAD_DEF_REG */

#define CSL_ALE_THREAD_DEF_REG_ENABLE_MASK                                     (0x00008000U)
#define CSL_ALE_THREAD_DEF_REG_ENABLE_SHIFT                                    (0x0000000FU)
#define CSL_ALE_THREAD_DEF_REG_ENABLE_RESETVAL                                 (0x00000000U)
#define CSL_ALE_THREAD_DEF_REG_ENABLE_MAX                                      (0x00000001U)

#define CSL_ALE_THREAD_DEF_REG_VALUE_MASK                                      (0x0000003FU)
#define CSL_ALE_THREAD_DEF_REG_VALUE_SHIFT                                     (0x00000000U)
#define CSL_ALE_THREAD_DEF_REG_VALUE_RESETVAL                                  (0x00000000U)
#define CSL_ALE_THREAD_DEF_REG_VALUE_MAX                                       (0x0000003FU)

#define CSL_ALE_THREAD_DEF_REG_RESETVAL                                        (0x00000000U)

/* THREAD_CTL_REG */

#define CSL_ALE_THREAD_CTL_REG_ENTRY_PTR_MASK                                  (0x00000007U)
#define CSL_ALE_THREAD_CTL_REG_ENTRY_PTR_SHIFT                                 (0x00000000U)
#define CSL_ALE_THREAD_CTL_REG_ENTRY_PTR_RESETVAL                              (0x00000000U)
#define CSL_ALE_THREAD_CTL_REG_ENTRY_PTR_MAX                                   (0x00000007U)

#define CSL_ALE_THREAD_CTL_REG_RESETVAL                                        (0x00000000U)

/* THREAD_VAL_REG */

#define CSL_ALE_THREAD_VAL_REG_ENABLE_MASK                                     (0x00008000U)
#define CSL_ALE_THREAD_VAL_REG_ENABLE_SHIFT                                    (0x0000000FU)
#define CSL_ALE_THREAD_VAL_REG_ENABLE_RESETVAL                                 (0x00000000U)
#define CSL_ALE_THREAD_VAL_REG_ENABLE_MAX                                      (0x00000001U)

#define CSL_ALE_THREAD_VAL_REG_VALUE_MASK                                      (0x0000003FU)
#define CSL_ALE_THREAD_VAL_REG_VALUE_SHIFT                                     (0x00000000U)
#define CSL_ALE_THREAD_VAL_REG_VALUE_RESETVAL                                  (0x00000000U)
#define CSL_ALE_THREAD_VAL_REG_VALUE_MAX                                       (0x0000003FU)

#define CSL_ALE_THREAD_VAL_REG_RESETVAL                                        (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
