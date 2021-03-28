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
#ifndef CSLR_CPGMAC_SL_H_
#define CSLR_CPGMAC_SL_H_

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
    volatile Uint32 IDVER;
    volatile Uint32 MACCONTROL;
    volatile Uint32 MACSTATUS;
    volatile Uint32 SOFT_RESET;
    volatile Uint32 RX_MAXLEN;
    volatile Uint32 BOFFTEST;
    volatile Uint32 RX_PAUSE;
    volatile Uint32 TX_PAUSE;
    volatile Uint32 EMCONTROL;
    volatile Uint32 PRI_MAP;
    volatile Uint32 TX_GAP;
} CSL_Cpgmac_SlRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* IDVER */
#define CSL_CPGMAC_SL_IDVER                                     (0x0U)

/* MACCONTROL */
#define CSL_CPGMAC_SL_MACCONTROL                                (0x4U)

/* MACSTATUS */
#define CSL_CPGMAC_SL_MACSTATUS                                 (0x8U)

/* SOFT_RESET */
#define CSL_CPGMAC_SL_SOFT_RESET                                (0xCU)

/* RX_MAXLEN */
#define CSL_CPGMAC_SL_RX_MAXLEN                                 (0x10U)

/* BOFFTEST */
#define CSL_CPGMAC_SL_BOFFTEST                                  (0x14U)

/* RX_PAUSE */
#define CSL_CPGMAC_SL_RX_PAUSE                                  (0x18U)

/* TX_PAUSE */
#define CSL_CPGMAC_SL_TX_PAUSE                                  (0x1CU)

/* EMCONTROL */
#define CSL_CPGMAC_SL_EMCONTROL                                 (0x20U)

/* PRI_MAP */
#define CSL_CPGMAC_SL_PRI_MAP                                   (0x24U)

/* TX_GAP */
#define CSL_CPGMAC_SL_TX_GAP                                    (0x28U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* IDVER */

#define CSL_CPGMAC_SL_IDVER_Y_MASK                              (0x000000FFU)
#define CSL_CPGMAC_SL_IDVER_Y_SHIFT                             (0U)
#define CSL_CPGMAC_SL_IDVER_Y_RESETVAL                          (0x00000000U)
#define CSL_CPGMAC_SL_IDVER_Y_MAX                               (0x000000ffU)

#define CSL_CPGMAC_SL_IDVER_X_MASK                              (0x00000700U)
#define CSL_CPGMAC_SL_IDVER_X_SHIFT                             (8U)
#define CSL_CPGMAC_SL_IDVER_X_RESETVAL                          (0x00000000U)
#define CSL_CPGMAC_SL_IDVER_X_MAX                               (0x00000007U)

#define CSL_CPGMAC_SL_IDVER_Z_MASK                              (0x0000F800U)
#define CSL_CPGMAC_SL_IDVER_Z_SHIFT                             (11U)
#define CSL_CPGMAC_SL_IDVER_Z_RESETVAL                          (0x00000000U)
#define CSL_CPGMAC_SL_IDVER_Z_MAX                               (0x0000001fU)

#define CSL_CPGMAC_SL_IDVER_IDENT_MASK                          (0xFFFF0000U)
#define CSL_CPGMAC_SL_IDVER_IDENT_SHIFT                         (16U)
#define CSL_CPGMAC_SL_IDVER_IDENT_RESETVAL                      (0x00000000U)
#define CSL_CPGMAC_SL_IDVER_IDENT_MAX                           (0x0000ffffU)

#define CSL_CPGMAC_SL_IDVER_RESETVAL                            (0x00000000U)

/* MACCONTROL */

#define CSL_CPGMAC_SL_MACCONTROL_FULLDUPLEX_MASK                (0x00000001U)
#define CSL_CPGMAC_SL_MACCONTROL_FULLDUPLEX_SHIFT               (0U)
#define CSL_CPGMAC_SL_MACCONTROL_FULLDUPLEX_RESETVAL            (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_FULLDUPLEX_MAX                 (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_LOOPBACK_MASK                  (0x00000002U)
#define CSL_CPGMAC_SL_MACCONTROL_LOOPBACK_SHIFT                 (1U)
#define CSL_CPGMAC_SL_MACCONTROL_LOOPBACK_RESETVAL              (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_LOOPBACK_MAX                   (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_MTEST_MASK                     (0x00000004U)
#define CSL_CPGMAC_SL_MACCONTROL_MTEST_SHIFT                    (2U)
#define CSL_CPGMAC_SL_MACCONTROL_MTEST_RESETVAL                 (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_MTEST_MAX                      (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_RX_FLOW_EN_MASK                (0x00000008U)
#define CSL_CPGMAC_SL_MACCONTROL_RX_FLOW_EN_SHIFT               (3U)
#define CSL_CPGMAC_SL_MACCONTROL_RX_FLOW_EN_RESETVAL            (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_RX_FLOW_EN_MAX                 (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_TX_FLOW_EN_MASK                (0x00000010U)
#define CSL_CPGMAC_SL_MACCONTROL_TX_FLOW_EN_SHIFT               (4U)
#define CSL_CPGMAC_SL_MACCONTROL_TX_FLOW_EN_RESETVAL            (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_TX_FLOW_EN_MAX                 (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_GMII_EN_MASK                   (0x00000020U)
#define CSL_CPGMAC_SL_MACCONTROL_GMII_EN_SHIFT                  (5U)
#define CSL_CPGMAC_SL_MACCONTROL_GMII_EN_RESETVAL               (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_GMII_EN_MAX                    (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_TX_PACE_MASK                   (0x00000040U)
#define CSL_CPGMAC_SL_MACCONTROL_TX_PACE_SHIFT                  (6U)
#define CSL_CPGMAC_SL_MACCONTROL_TX_PACE_RESETVAL               (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_TX_PACE_MAX                    (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_GIG_MASK                       (0x00000080U)
#define CSL_CPGMAC_SL_MACCONTROL_GIG_SHIFT                      (7U)
#define CSL_CPGMAC_SL_MACCONTROL_GIG_RESETVAL                   (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_GIG_MAX                        (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_TX_SHORT_GAP_ENABLE_MASK       (0x00000400U)
#define CSL_CPGMAC_SL_MACCONTROL_TX_SHORT_GAP_ENABLE_SHIFT      (10U)
#define CSL_CPGMAC_SL_MACCONTROL_TX_SHORT_GAP_ENABLE_RESETVAL   (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_TX_SHORT_GAP_ENABLE_MAX        (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_CMD_IDLE_MASK                  (0x00000800U)
#define CSL_CPGMAC_SL_MACCONTROL_CMD_IDLE_SHIFT                 (11U)
#define CSL_CPGMAC_SL_MACCONTROL_CMD_IDLE_RESETVAL              (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_CMD_IDLE_MAX                   (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_CRS_FLOW_EN_MASK               (0x00001000U)
#define CSL_CPGMAC_SL_MACCONTROL_CRS_FLOW_EN_SHIFT              (12U)
#define CSL_CPGMAC_SL_MACCONTROL_CRS_FLOW_EN_RESETVAL           (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_CRS_FLOW_EN_MAX                (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_IFCTL_A_MASK                   (0x00008000U)
#define CSL_CPGMAC_SL_MACCONTROL_IFCTL_A_SHIFT                  (15U)
#define CSL_CPGMAC_SL_MACCONTROL_IFCTL_A_RESETVAL               (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_IFCTL_A_MAX                    (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_IFCTL_B_MASK                   (0x00010000U)
#define CSL_CPGMAC_SL_MACCONTROL_IFCTL_B_SHIFT                  (16U)
#define CSL_CPGMAC_SL_MACCONTROL_IFCTL_B_RESETVAL               (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_IFCTL_B_MAX                    (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_GIG_FORCE_MASK                 (0x00020000U)
#define CSL_CPGMAC_SL_MACCONTROL_GIG_FORCE_SHIFT                (17U)
#define CSL_CPGMAC_SL_MACCONTROL_GIG_FORCE_RESETVAL             (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_GIG_FORCE_MAX                  (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_EXT_EN_MASK                    (0x00040000U)
#define CSL_CPGMAC_SL_MACCONTROL_EXT_EN_SHIFT                   (18U)
#define CSL_CPGMAC_SL_MACCONTROL_EXT_EN_RESETVAL                (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_EXT_EN_MAX                     (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_TX_SHORT_GAP_LIM_EN_MASK       (0x00200000U)
#define CSL_CPGMAC_SL_MACCONTROL_TX_SHORT_GAP_LIM_EN_SHIFT      (21U)
#define CSL_CPGMAC_SL_MACCONTROL_TX_SHORT_GAP_LIM_EN_RESETVAL   (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_TX_SHORT_GAP_LIM_EN_MAX        (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_RX_CEF_EN_MASK                 (0x00400000U)
#define CSL_CPGMAC_SL_MACCONTROL_RX_CEF_EN_SHIFT                (22U)
#define CSL_CPGMAC_SL_MACCONTROL_RX_CEF_EN_RESETVAL             (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_RX_CEF_EN_MAX                  (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_RX_CSF_EN_MASK                 (0x00800000U)
#define CSL_CPGMAC_SL_MACCONTROL_RX_CSF_EN_SHIFT                (23U)
#define CSL_CPGMAC_SL_MACCONTROL_RX_CSF_EN_RESETVAL             (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_RX_CSF_EN_MAX                  (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_RX_CMF_EN_MASK                 (0x01000000U)
#define CSL_CPGMAC_SL_MACCONTROL_RX_CMF_EN_SHIFT                (24U)
#define CSL_CPGMAC_SL_MACCONTROL_RX_CMF_EN_RESETVAL             (0x00000000U)
#define CSL_CPGMAC_SL_MACCONTROL_RX_CMF_EN_MAX                  (0x00000001U)

#define CSL_CPGMAC_SL_MACCONTROL_RESETVAL                       (0x00000000U)

/* MACSTATUS */

#define CSL_CPGMAC_SL_MACSTATUS_TX_FLOW_ACT_MASK                (0x00000001U)
#define CSL_CPGMAC_SL_MACSTATUS_TX_FLOW_ACT_SHIFT               (0U)
#define CSL_CPGMAC_SL_MACSTATUS_TX_FLOW_ACT_RESETVAL            (0x00000000U)
#define CSL_CPGMAC_SL_MACSTATUS_TX_FLOW_ACT_MAX                 (0x00000001U)

#define CSL_CPGMAC_SL_MACSTATUS_RX_FLOW_ACT_MASK                (0x00000002U)
#define CSL_CPGMAC_SL_MACSTATUS_RX_FLOW_ACT_SHIFT               (1U)
#define CSL_CPGMAC_SL_MACSTATUS_RX_FLOW_ACT_RESETVAL            (0x00000000U)
#define CSL_CPGMAC_SL_MACSTATUS_RX_FLOW_ACT_MAX                 (0x00000001U)

#define CSL_CPGMAC_SL_MACSTATUS_EXT_FULLDUPLEX_MASK             (0x00000008U)
#define CSL_CPGMAC_SL_MACSTATUS_EXT_FULLDUPLEX_SHIFT            (3U)
#define CSL_CPGMAC_SL_MACSTATUS_EXT_FULLDUPLEX_RESETVAL         (0x00000000U)
#define CSL_CPGMAC_SL_MACSTATUS_EXT_FULLDUPLEX_MAX              (0x00000001U)

#define CSL_CPGMAC_SL_MACSTATUS_EXT_GIG_MASK                    (0x00000010U)
#define CSL_CPGMAC_SL_MACSTATUS_EXT_GIG_SHIFT                   (4U)
#define CSL_CPGMAC_SL_MACSTATUS_EXT_GIG_RESETVAL                (0x00000000U)
#define CSL_CPGMAC_SL_MACSTATUS_EXT_GIG_MAX                     (0x00000001U)

#define CSL_CPGMAC_SL_MACSTATUS_IDLE_MASK                       (0x80000000U)
#define CSL_CPGMAC_SL_MACSTATUS_IDLE_SHIFT                      (31U)
#define CSL_CPGMAC_SL_MACSTATUS_IDLE_RESETVAL                   (0x00000000U)
#define CSL_CPGMAC_SL_MACSTATUS_IDLE_MAX                        (0x00000001U)

#define CSL_CPGMAC_SL_MACSTATUS_RESETVAL                        (0x00000000U)

/* SOFT_RESET */

#define CSL_CPGMAC_SL_SOFT_RESET_SOFT_RESET_MASK                (0x00000001U)
#define CSL_CPGMAC_SL_SOFT_RESET_SOFT_RESET_SHIFT               (0U)
#define CSL_CPGMAC_SL_SOFT_RESET_SOFT_RESET_RESETVAL            (0x00000000U)
#define CSL_CPGMAC_SL_SOFT_RESET_SOFT_RESET_MAX                 (0x00000001U)

#define CSL_CPGMAC_SL_SOFT_RESET_RESETVAL                       (0x00000000U)

/* RX_MAXLEN */

#define CSL_CPGMAC_SL_RX_MAXLEN_RX_MAXLEN_MASK                  (0x00003FFFU)
#define CSL_CPGMAC_SL_RX_MAXLEN_RX_MAXLEN_SHIFT                 (0U)
#define CSL_CPGMAC_SL_RX_MAXLEN_RX_MAXLEN_RESETVAL              (0x00000000U)
#define CSL_CPGMAC_SL_RX_MAXLEN_RX_MAXLEN_MAX                   (0x00003fffU)

#define CSL_CPGMAC_SL_RX_MAXLEN_RESETVAL                        (0x00000000U)

/* BOFFTEST */

#define CSL_CPGMAC_SL_BOFFTEST_TX_BACKOFF_MASK                  (0x000003FFU)
#define CSL_CPGMAC_SL_BOFFTEST_TX_BACKOFF_SHIFT                 (0U)
#define CSL_CPGMAC_SL_BOFFTEST_TX_BACKOFF_RESETVAL              (0x00000000U)
#define CSL_CPGMAC_SL_BOFFTEST_TX_BACKOFF_MAX                   (0x000003ffU)

#define CSL_CPGMAC_SL_BOFFTEST_COLL_COUNT_MASK                  (0x0000F000U)
#define CSL_CPGMAC_SL_BOFFTEST_COLL_COUNT_SHIFT                 (12U)
#define CSL_CPGMAC_SL_BOFFTEST_COLL_COUNT_RESETVAL              (0x00000000U)
#define CSL_CPGMAC_SL_BOFFTEST_COLL_COUNT_MAX                   (0x0000000fU)

#define CSL_CPGMAC_SL_BOFFTEST_RNDNUM_MASK                      (0x03FF0000U)
#define CSL_CPGMAC_SL_BOFFTEST_RNDNUM_SHIFT                     (16U)
#define CSL_CPGMAC_SL_BOFFTEST_RNDNUM_RESETVAL                  (0x00000000U)
#define CSL_CPGMAC_SL_BOFFTEST_RNDNUM_MAX                       (0x000003ffU)

#define CSL_CPGMAC_SL_BOFFTEST_PACEVAL_MASK                     (0x7C000000U)
#define CSL_CPGMAC_SL_BOFFTEST_PACEVAL_SHIFT                    (26U)
#define CSL_CPGMAC_SL_BOFFTEST_PACEVAL_RESETVAL                 (0x00000000U)
#define CSL_CPGMAC_SL_BOFFTEST_PACEVAL_MAX                      (0x0000001fU)

#define CSL_CPGMAC_SL_BOFFTEST_RESETVAL                         (0x00000000U)

/* RX_PAUSE */

#define CSL_CPGMAC_SL_RX_PAUSE_RX_PAUSETIMER_MASK               (0x0000FFFFU)
#define CSL_CPGMAC_SL_RX_PAUSE_RX_PAUSETIMER_SHIFT              (0U)
#define CSL_CPGMAC_SL_RX_PAUSE_RX_PAUSETIMER_RESETVAL           (0x00000000U)
#define CSL_CPGMAC_SL_RX_PAUSE_RX_PAUSETIMER_MAX                (0x0000ffffU)

#define CSL_CPGMAC_SL_RX_PAUSE_RESETVAL                         (0x00000000U)

/* TX_PAUSE */

#define CSL_CPGMAC_SL_TX_PAUSE_TX_PAUSETIMER_MASK               (0x0000FFFFU)
#define CSL_CPGMAC_SL_TX_PAUSE_TX_PAUSETIMER_SHIFT              (0U)
#define CSL_CPGMAC_SL_TX_PAUSE_TX_PAUSETIMER_RESETVAL           (0x00000000U)
#define CSL_CPGMAC_SL_TX_PAUSE_TX_PAUSETIMER_MAX                (0x0000ffffU)

#define CSL_CPGMAC_SL_TX_PAUSE_RESETVAL                         (0x00000000U)

/* EMCONTROL */

#define CSL_CPGMAC_SL_EMCONTROL_FREE_MASK                       (0x00000001U)
#define CSL_CPGMAC_SL_EMCONTROL_FREE_SHIFT                      (0U)
#define CSL_CPGMAC_SL_EMCONTROL_FREE_RESETVAL                   (0x00000000U)
#define CSL_CPGMAC_SL_EMCONTROL_FREE_MAX                        (0x00000001U)

#define CSL_CPGMAC_SL_EMCONTROL_SOFT_MASK                       (0x00000002U)
#define CSL_CPGMAC_SL_EMCONTROL_SOFT_SHIFT                      (1U)
#define CSL_CPGMAC_SL_EMCONTROL_SOFT_RESETVAL                   (0x00000000U)
#define CSL_CPGMAC_SL_EMCONTROL_SOFT_MAX                        (0x00000001U)

#define CSL_CPGMAC_SL_EMCONTROL_RESETVAL                        (0x00000000U)

/* PRI_MAP */

#define CSL_CPGMAC_SL_PRI_MAP_PRI0_MASK                         (0x00000007U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI0_SHIFT                        (0U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI0_RESETVAL                     (0x00000000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI0_MAX                          (0x00000007U)

#define CSL_CPGMAC_SL_PRI_MAP_PRI1_MASK                         (0x00000070U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI1_SHIFT                        (4U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI1_RESETVAL                     (0x00000000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI1_MAX                          (0x00000007U)

#define CSL_CPGMAC_SL_PRI_MAP_PRI2_MASK                         (0x00000700U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI2_SHIFT                        (8U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI2_RESETVAL                     (0x00000000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI2_MAX                          (0x00000007U)

#define CSL_CPGMAC_SL_PRI_MAP_PRI3_MASK                         (0x00007000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI3_SHIFT                        (12U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI3_RESETVAL                     (0x00000000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI3_MAX                          (0x00000007U)

#define CSL_CPGMAC_SL_PRI_MAP_PRI4_MASK                         (0x00070000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI4_SHIFT                        (16U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI4_RESETVAL                     (0x00000000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI4_MAX                          (0x00000007U)

#define CSL_CPGMAC_SL_PRI_MAP_PRI5_MASK                         (0x00700000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI5_SHIFT                        (20U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI5_RESETVAL                     (0x00000000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI5_MAX                          (0x00000007U)

#define CSL_CPGMAC_SL_PRI_MAP_PRI6_MASK                         (0x07000000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI6_SHIFT                        (24U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI6_RESETVAL                     (0x00000000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI6_MAX                          (0x00000007U)

#define CSL_CPGMAC_SL_PRI_MAP_PRI7_MASK                         (0x70000000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI7_SHIFT                        (28U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI7_RESETVAL                     (0x00000000U)
#define CSL_CPGMAC_SL_PRI_MAP_PRI7_MAX                          (0x00000007U)

#define CSL_CPGMAC_SL_PRI_MAP_RESETVAL                          (0x00000000U)

/* TX_GAP */

#define CSL_CPGMAC_SL_TX_GAP_TX_GAP_MASK                        (0x000001FFU)
#define CSL_CPGMAC_SL_TX_GAP_TX_GAP_SHIFT                       (0U)
#define CSL_CPGMAC_SL_TX_GAP_TX_GAP_RESETVAL                    (0x00000000U)
#define CSL_CPGMAC_SL_TX_GAP_TX_GAP_MAX                         (0x000001ffU)

#define CSL_CPGMAC_SL_TX_GAP_RESETVAL                           (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
