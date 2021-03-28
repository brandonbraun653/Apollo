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
#ifndef CSLR_CPSGMII_V1_H
#define CSLR_CPSGMII_V1_H

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
    volatile Uint32 SOFT_RESET_REG;
    volatile Uint8  RSVD0[8];
    volatile Uint32 CONTROL_REG;
    volatile Uint32 STATUS_REG;
    volatile Uint32 MR_ADV_ABILITY_REG;
    volatile Uint32 MR_NP_TX_REG;
    volatile Uint32 MR_LP_ADV_ABILITY_REG;
    volatile Uint32 MR_LP_NP_RX_REG;
    volatile Uint8  RSVD1[8];
    volatile Uint32 TX_CFG_REG;
    volatile Uint32 RX_CFG_REG;
    volatile Uint32 AUX_CFG_REG;
    volatile Uint8  RSVD2[4];
    volatile Uint32 DIAG_CLEAR_REG;
    volatile Uint32 DIAG_CONTROL_REG;
    volatile Uint32 DIAG_STATUS_REG;

    /* Modified by the CSL team for:
     *
     *  (1) Adding extra padding to offset correctly
     *      to the next SGMII module start.
     */
#ifndef  CSLR_EMAC_NOMOD
    volatile Uint8  RSVD4[180];
#endif

} CSL_CpsgmiiRegs;

/* Modified by CSL team for:
 *
 */
#ifndef  CSLR_EMAC_NOMOD
typedef struct  {
    CSL_CpsgmiiRegs SGMII_PORT [8];        
} CSL_Cpsgmii_PortRegs;
#endif

/**************************************************************************
* Register Macros
**************************************************************************/

/* IDVER_REG */
#define CSL_CPSGMII_IDVER_REG                                   (0x0U)

/* SOFT_RESET_REG */
#define CSL_CPSGMII_SOFT_RESET_REG                              (0x4U)

/* CONTROL_REG */
#define CSL_CPSGMII_CONTROL_REG                                 (0x10U)

/* STATUS_REG */
#define CSL_CPSGMII_STATUS_REG                                  (0x14U)

/* MR_ADV_ABILITY_REG */
#define CSL_CPSGMII_MR_ADV_ABILITY_REG                          (0x18U)

/* MR_NP_TX_REG */
#define CSL_CPSGMII_MR_NP_TX_REG                                (0x1CU)

/* MR_LP_ADV_ABILITY_REG */
#define CSL_CPSGMII_MR_LP_ADV_ABILITY_REG                       (0x20U)

/* MR_LP_NP_RX_REG */
#define CSL_CPSGMII_MR_LP_NP_RX_REG                             (0x24U)

/* TX_CFG_REG */
#define CSL_CPSGMII_TX_CFG_REG                                  (0x30U)

/* RX_CFG_REG */
#define CSL_CPSGMII_RX_CFG_REG                                  (0x34U)

/* AUX_CFG_REG */
#define CSL_CPSGMII_AUX_CFG_REG                                 (0x38U)

/* DIAG_CLEAR_REG */
#define CSL_CPSGMII_DIAG_CLEAR_REG                              (0x40U)

/* DIAG_CONTROL_REG */
#define CSL_CPSGMII_DIAG_CONTROL_REG                            (0x44U)

/* DIAG_STATUS_REG */
#define CSL_CPSGMII_DIAG_STATUS_REG                             (0x48U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* IDVER_REG */

#define CSL_CPSGMII_IDVER_REG_MINOR_VER_MASK                    (0x000000FFU)
#define CSL_CPSGMII_IDVER_REG_MINOR_VER_SHIFT                   (0U)
#define CSL_CPSGMII_IDVER_REG_MINOR_VER_RESETVAL                (0x00000000U)
#define CSL_CPSGMII_IDVER_REG_MINOR_VER_MAX                     (0x000000ffU)

#define CSL_CPSGMII_IDVER_REG_MAJOR_VER_MASK                    (0x00000700U)
#define CSL_CPSGMII_IDVER_REG_MAJOR_VER_SHIFT                   (8U)
#define CSL_CPSGMII_IDVER_REG_MAJOR_VER_RESETVAL                (0x00000000U)
#define CSL_CPSGMII_IDVER_REG_MAJOR_VER_MAX                     (0x00000007U)

#define CSL_CPSGMII_IDVER_REG_RTL_VER_MASK                      (0x0000F800U)
#define CSL_CPSGMII_IDVER_REG_RTL_VER_SHIFT                     (11U)
#define CSL_CPSGMII_IDVER_REG_RTL_VER_RESETVAL                  (0x00000000U)
#define CSL_CPSGMII_IDVER_REG_RTL_VER_MAX                       (0x0000001fU)

#define CSL_CPSGMII_IDVER_REG_TX_IDENT_MASK                     (0xFFFF0000U)
#define CSL_CPSGMII_IDVER_REG_TX_IDENT_SHIFT                    (16U)
#define CSL_CPSGMII_IDVER_REG_TX_IDENT_RESETVAL                 (0x00000000U)
#define CSL_CPSGMII_IDVER_REG_TX_IDENT_MAX                      (0x0000ffffU)

#define CSL_CPSGMII_IDVER_REG_RESETVAL                          (0x00000000U)

/* SOFT_RESET_REG */

#define CSL_CPSGMII_SOFT_RESET_REG_SOFT_RESET_MASK              (0x00000001U)
#define CSL_CPSGMII_SOFT_RESET_REG_SOFT_RESET_SHIFT             (0U)
#define CSL_CPSGMII_SOFT_RESET_REG_SOFT_RESET_RESETVAL          (0x00000000U)
#define CSL_CPSGMII_SOFT_RESET_REG_SOFT_RESET_MAX               (0x00000001U)

#define CSL_CPSGMII_SOFT_RESET_REG_RT_SOFT_RESET_MASK           (0x00000002U)
#define CSL_CPSGMII_SOFT_RESET_REG_RT_SOFT_RESET_SHIFT          (1U)
#define CSL_CPSGMII_SOFT_RESET_REG_RT_SOFT_RESET_RESETVAL       (0x00000000U)
#define CSL_CPSGMII_SOFT_RESET_REG_RT_SOFT_RESET_MAX            (0x00000001U)

#define CSL_CPSGMII_SOFT_RESET_REG_RESETVAL                     (0x00000000U)

/* CONTROL_REG */

#define CSL_CPSGMII_CONTROL_REG_MR_AN_ENABLE_MASK               (0x00000001U)
#define CSL_CPSGMII_CONTROL_REG_MR_AN_ENABLE_SHIFT              (0U)
#define CSL_CPSGMII_CONTROL_REG_MR_AN_ENABLE_RESETVAL           (0x00000000U)
#define CSL_CPSGMII_CONTROL_REG_MR_AN_ENABLE_MAX                (0x00000001U)

#define CSL_CPSGMII_CONTROL_REG_MR_AN_RESTART_MASK              (0x00000002U)
#define CSL_CPSGMII_CONTROL_REG_MR_AN_RESTART_SHIFT             (1U)
#define CSL_CPSGMII_CONTROL_REG_MR_AN_RESTART_RESETVAL          (0x00000000U)
#define CSL_CPSGMII_CONTROL_REG_MR_AN_RESTART_MAX               (0x00000001U)

#define CSL_CPSGMII_CONTROL_REG_FAST_LINK_TIMER_MASK            (0x00000004U)
#define CSL_CPSGMII_CONTROL_REG_FAST_LINK_TIMER_SHIFT           (2U)
#define CSL_CPSGMII_CONTROL_REG_FAST_LINK_TIMER_RESETVAL        (0x00000000U)
#define CSL_CPSGMII_CONTROL_REG_FAST_LINK_TIMER_MAX             (0x00000001U)

#define CSL_CPSGMII_CONTROL_REG_MR_NP_LOADED_MASK               (0x00000008U)
#define CSL_CPSGMII_CONTROL_REG_MR_NP_LOADED_SHIFT              (3U)
#define CSL_CPSGMII_CONTROL_REG_MR_NP_LOADED_RESETVAL           (0x00000000U)
#define CSL_CPSGMII_CONTROL_REG_MR_NP_LOADED_MAX                (0x00000001U)

#define CSL_CPSGMII_CONTROL_REG_LOOPBACK_MASK                   (0x00000010U)
#define CSL_CPSGMII_CONTROL_REG_LOOPBACK_SHIFT                  (4U)
#define CSL_CPSGMII_CONTROL_REG_LOOPBACK_RESETVAL               (0x00000000U)
#define CSL_CPSGMII_CONTROL_REG_LOOPBACK_MAX                    (0x00000001U)

#define CSL_CPSGMII_CONTROL_REG_MASTER_MASK                     (0x00000020U)
#define CSL_CPSGMII_CONTROL_REG_MASTER_SHIFT                    (5U)
#define CSL_CPSGMII_CONTROL_REG_MASTER_RESETVAL                 (0x00000000U)
#define CSL_CPSGMII_CONTROL_REG_MASTER_MAX                      (0x00000001U)

#define CSL_CPSGMII_CONTROL_REG_TEST_PATTERN_EN_MASK            (0x00000040U)
#define CSL_CPSGMII_CONTROL_REG_TEST_PATTERN_EN_SHIFT           (6U)
#define CSL_CPSGMII_CONTROL_REG_TEST_PATTERN_EN_RESETVAL        (0x00000000U)
#define CSL_CPSGMII_CONTROL_REG_TEST_PATTERN_EN_MAX             (0x00000001U)

#define CSL_CPSGMII_CONTROL_REG_RESETVAL                        (0x00000000U)

/* STATUS_REG */

#define CSL_CPSGMII_STATUS_REG_LINK_MASK                        (0x00000001U)
#define CSL_CPSGMII_STATUS_REG_LINK_SHIFT                       (0U)
#define CSL_CPSGMII_STATUS_REG_LINK_RESETVAL                    (0x00000000U)
#define CSL_CPSGMII_STATUS_REG_LINK_MAX                         (0x00000001U)

#define CSL_CPSGMII_STATUS_REG_AN_ERROR_MASK                    (0x00000002U)
#define CSL_CPSGMII_STATUS_REG_AN_ERROR_SHIFT                   (1U)
#define CSL_CPSGMII_STATUS_REG_AN_ERROR_RESETVAL                (0x00000000U)
#define CSL_CPSGMII_STATUS_REG_AN_ERROR_MAX                     (0x00000001U)

#define CSL_CPSGMII_STATUS_REG_MR_AN_COMPLETE_MASK              (0x00000004U)
#define CSL_CPSGMII_STATUS_REG_MR_AN_COMPLETE_SHIFT             (2U)
#define CSL_CPSGMII_STATUS_REG_MR_AN_COMPLETE_RESETVAL          (0x00000000U)
#define CSL_CPSGMII_STATUS_REG_MR_AN_COMPLETE_MAX               (0x00000001U)

#define CSL_CPSGMII_STATUS_REG_MR_PAGE_RX_MASK                  (0x00000008U)
#define CSL_CPSGMII_STATUS_REG_MR_PAGE_RX_SHIFT                 (3U)
#define CSL_CPSGMII_STATUS_REG_MR_PAGE_RX_RESETVAL              (0x00000000U)
#define CSL_CPSGMII_STATUS_REG_MR_PAGE_RX_MAX                   (0x00000001U)

#define CSL_CPSGMII_STATUS_REG_LOCK_MASK                        (0x00000010U)
#define CSL_CPSGMII_STATUS_REG_LOCK_SHIFT                       (4U)
#define CSL_CPSGMII_STATUS_REG_LOCK_RESETVAL                    (0x00000000U)
#define CSL_CPSGMII_STATUS_REG_LOCK_MAX                         (0x00000001U)

#define CSL_CPSGMII_STATUS_REG_FIB_SIG_DETECT_MASK              (0x00000020U)
#define CSL_CPSGMII_STATUS_REG_FIB_SIG_DETECT_SHIFT             (5U)
#define CSL_CPSGMII_STATUS_REG_FIB_SIG_DETECT_RESETVAL          (0x00000000U)
#define CSL_CPSGMII_STATUS_REG_FIB_SIG_DETECT_MAX               (0x00000001U)

#define CSL_CPSGMII_STATUS_REG_RESETVAL                         (0x00000000U)

/* MR_ADV_ABILITY_REG */

#define CSL_CPSGMII_MR_ADV_ABILITY_REG_MR_ADV_ABILITY_MASK      (0x0000FFFFU)
#define CSL_CPSGMII_MR_ADV_ABILITY_REG_MR_ADV_ABILITY_SHIFT     (0U)
#define CSL_CPSGMII_MR_ADV_ABILITY_REG_MR_ADV_ABILITY_RESETVAL  (0x00000000U)
#define CSL_CPSGMII_MR_ADV_ABILITY_REG_MR_ADV_ABILITY_MAX       (0x0000ffffU)

#define CSL_CPSGMII_MR_ADV_ABILITY_REG_RESETVAL                 (0x00000000U)

/* MR_NP_TX_REG */

#define CSL_CPSGMII_MR_NP_TX_REG_MR_NP_TX_MASK                  (0x0000FFFFU)
#define CSL_CPSGMII_MR_NP_TX_REG_MR_NP_TX_SHIFT                 (0U)
#define CSL_CPSGMII_MR_NP_TX_REG_MR_NP_TX_RESETVAL              (0x00000000U)
#define CSL_CPSGMII_MR_NP_TX_REG_MR_NP_TX_MAX                   (0x0000ffffU)

#define CSL_CPSGMII_MR_NP_TX_REG_RESETVAL                       (0x00000000U)

/* MR_LP_ADV_ABILITY_REG */

#define CSL_CPSGMII_MR_LP_ADV_ABILITY_REG_MR_LP_ADV_ABILITY_MASK  (0x0000FFFFU)
#define CSL_CPSGMII_MR_LP_ADV_ABILITY_REG_MR_LP_ADV_ABILITY_SHIFT  (0U)
#define CSL_CPSGMII_MR_LP_ADV_ABILITY_REG_MR_LP_ADV_ABILITY_RESETVAL  (0x00000000U)
#define CSL_CPSGMII_MR_LP_ADV_ABILITY_REG_MR_LP_ADV_ABILITY_MAX  (0x0000ffffU)

#define CSL_CPSGMII_MR_LP_ADV_ABILITY_REG_RESETVAL              (0x00000000U)

/* MR_LP_NP_RX_REG */

#define CSL_CPSGMII_MR_LP_NP_RX_REG_MR_LP_NP_RX_MASK            (0x0000FFFFU)
#define CSL_CPSGMII_MR_LP_NP_RX_REG_MR_LP_NP_RX_SHIFT           (0U)
#define CSL_CPSGMII_MR_LP_NP_RX_REG_MR_LP_NP_RX_RESETVAL        (0x00000000U)
#define CSL_CPSGMII_MR_LP_NP_RX_REG_MR_LP_NP_RX_MAX             (0x0000ffffU)

#define CSL_CPSGMII_MR_LP_NP_RX_REG_RESETVAL                    (0x00000000U)

/* TX_CFG_REG */

#define CSL_CPSGMII_TX_CFG_REG_TX_CFG_MASK                      (0xFFFFFFFFU)
#define CSL_CPSGMII_TX_CFG_REG_TX_CFG_SHIFT                     (0U)
#define CSL_CPSGMII_TX_CFG_REG_TX_CFG_RESETVAL                  (0x00000000U)
#define CSL_CPSGMII_TX_CFG_REG_TX_CFG_MAX                       (0xffffffffU)

#define CSL_CPSGMII_TX_CFG_REG_RESETVAL                         (0x00000000U)

/* RX_CFG_REG */

#define CSL_CPSGMII_RX_CFG_REG_RX_CFG_MASK                      (0xFFFFFFFFU)
#define CSL_CPSGMII_RX_CFG_REG_RX_CFG_SHIFT                     (0U)
#define CSL_CPSGMII_RX_CFG_REG_RX_CFG_RESETVAL                  (0x00000000U)
#define CSL_CPSGMII_RX_CFG_REG_RX_CFG_MAX                       (0xffffffffU)

#define CSL_CPSGMII_RX_CFG_REG_RESETVAL                         (0x00000000U)

/* AUX_CFG_REG */

#define CSL_CPSGMII_AUX_CFG_REG_AUX_CFG_MASK                    (0xFFFFFFFFU)
#define CSL_CPSGMII_AUX_CFG_REG_AUX_CFG_SHIFT                   (0U)
#define CSL_CPSGMII_AUX_CFG_REG_AUX_CFG_RESETVAL                (0x00000000U)
#define CSL_CPSGMII_AUX_CFG_REG_AUX_CFG_MAX                     (0xffffffffU)

#define CSL_CPSGMII_AUX_CFG_REG_RESETVAL                        (0x00000000U)

/* DIAG_CLEAR_REG */

#define CSL_CPSGMII_DIAG_CLEAR_REG_DIAG_CLEAR_MASK              (0x00000001U)
#define CSL_CPSGMII_DIAG_CLEAR_REG_DIAG_CLEAR_SHIFT             (0U)
#define CSL_CPSGMII_DIAG_CLEAR_REG_DIAG_CLEAR_RESETVAL          (0x00000000U)
#define CSL_CPSGMII_DIAG_CLEAR_REG_DIAG_CLEAR_MAX               (0x00000001U)

#define CSL_CPSGMII_DIAG_CLEAR_REG_RESETVAL                     (0x00000000U)

/* DIAG_CONTROL_REG */

#define CSL_CPSGMII_DIAG_CONTROL_REG_DIAG_EDGE_SEL_MASK         (0x00000003U)
#define CSL_CPSGMII_DIAG_CONTROL_REG_DIAG_EDGE_SEL_SHIFT        (0U)
#define CSL_CPSGMII_DIAG_CONTROL_REG_DIAG_EDGE_SEL_RESETVAL     (0x00000000U)
#define CSL_CPSGMII_DIAG_CONTROL_REG_DIAG_EDGE_SEL_MAX          (0x00000003U)

#define CSL_CPSGMII_DIAG_CONTROL_REG_DIAG_SM_SEL_MASK           (0x00000070U)
#define CSL_CPSGMII_DIAG_CONTROL_REG_DIAG_SM_SEL_SHIFT          (4U)
#define CSL_CPSGMII_DIAG_CONTROL_REG_DIAG_SM_SEL_RESETVAL       (0x00000000U)
#define CSL_CPSGMII_DIAG_CONTROL_REG_DIAG_SM_SEL_MAX            (0x00000007U)

#define CSL_CPSGMII_DIAG_CONTROL_REG_RESETVAL                   (0x00000000U)

/* DIAG_STATUS_REG */

#define CSL_CPSGMII_DIAG_STATUS_REG_DIAG_STATUS_MASK            (0x0000FFFFU)
#define CSL_CPSGMII_DIAG_STATUS_REG_DIAG_STATUS_SHIFT           (0U)
#define CSL_CPSGMII_DIAG_STATUS_REG_DIAG_STATUS_RESETVAL        (0x00000000U)
#define CSL_CPSGMII_DIAG_STATUS_REG_DIAG_STATUS_MAX             (0x0000ffffU)

#define CSL_CPSGMII_DIAG_STATUS_REG_RESETVAL                    (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
