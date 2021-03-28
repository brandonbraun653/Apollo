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
#ifndef CSLR_UNICACHECTM_H_
#define CSLR_UNICACHECTM_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 CTCNTL;
    volatile Uint8  RSVD0[28];
    volatile Uint32 CTSTMCNTL;
    volatile Uint32 CTSTMMSTID;
    volatile Uint32 CTSTMINTVL;
    volatile Uint32 CTSTMSEL;
    volatile Uint8  RSVD1[16];
    volatile Uint32 TINTVLR[2];
    volatile Uint8  RSVD2[52];
    volatile Uint32 CTDBGNUM;
    volatile Uint8  RSVD3[112];
    volatile Uint32 CTGNBL;
    volatile Uint8  RSVD4[4];
    volatile Uint32 CTGRST;
    volatile Uint8  RSVD5[4];
    volatile Uint32 CTCR_WT[2];
    volatile Uint32 CTCR_WOT[6];
    volatile Uint8  RSVD6[96];
    volatile Uint32 CTCNTR[8];
} CSL_UnicacheCtmRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* CTCNTL */
#define CSL_UNICACHECTM_CTCNTL                                  (0x0U)

/* This register contains the control and status settings for STM export */
#define CSL_UNICACHECTM_CTSTMCNTL                               (0x20U)

/* CTSTMMSTID */
#define CSL_UNICACHECTM_CTSTMMSTID                              (0x24U)

/* CTSTMINTVL */
#define CSL_UNICACHECTM_CTSTMINTVL                              (0x28U)

/* These registers mark the counters selected for export in the CSM */
#define CSL_UNICACHECTM_CTSTMSEL                                (0x2CU)

/* These registers contain the interval match value for the corresponding
 * timers in the SCTM */
#define CSL_UNICACHECTM_TINTVLR(i)                              (0x40U + ((i) * (0x4U)))

/* Counter Timer Number Debug Event Register */
#define CSL_UNICACHECTM_CTDBGNUM                                (0x7CU)

/* Counter Timer Debug Event Register */
#define CSL_UNICACHECTM_CTDBGEVT(i)                             (0x80U + ((i) * (0x4U)))

/* These registers provide for simultaneous enable/disable of 32 counters */
#define CSL_UNICACHECTM_CTGNBL                                  (0xF0U)

/* These registers provide for simultaneous reset of 32 counters */
#define CSL_UNICACHECTM_CTGRST                                  (0xF8U)

/* These registers contain the control and status settings for a single
 * counter in the module. There will be a CTCR for every counter in the module
 * (WT: with timer) */
#define CSL_UNICACHECTM_CTCR_WT(i)                              (0x100U + ((i) * (0x4U)))

/* These registers contain the control and status settings for a single
 * counter in the module. There will be a CTCR for every counter in the module
 * (WOT: without timer) */
#define CSL_UNICACHECTM_CTCR_WOT(i)                             (0x108U + ((i) * (0x4U)))

/* These registers contain the value of an individual counter in the moduel.
 * There will be a CTCNTR for every counter in the module */
#define CSL_UNICACHECTM_CTCNTR(i)                               (0x180U + ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* CTCNTL */

#define CSL_UNICACHECTM_CTCNTL_ENBL_MASK                        (0x00000001U)
#define CSL_UNICACHECTM_CTCNTL_ENBL_SHIFT                       (0U)
#define CSL_UNICACHECTM_CTCNTL_ENBL_RESETVAL                    (0x00000000U)
#define CSL_UNICACHECTM_CTCNTL_ENBL_DISABLE                     (0x00000000U)
#define CSL_UNICACHECTM_CTCNTL_ENBL_ENABLE                      (0x00000001U)

#define CSL_UNICACHECTM_CTCNTL_IDLEMODE_MASK                    (0x00000006U)
#define CSL_UNICACHECTM_CTCNTL_IDLEMODE_SHIFT                   (1U)
#define CSL_UNICACHECTM_CTCNTL_IDLEMODE_RESETVAL                (0x00000002U)
#define CSL_UNICACHECTM_CTCNTL_IDLEMODE_FORCE_IDLE              (0x00000000U)
#define CSL_UNICACHECTM_CTCNTL_IDLEMODE_NO_IDLE                 (0x00000001U)
#define CSL_UNICACHECTM_CTCNTL_IDLEMODE_SMART_IDLE              (0x00000002U)
#define CSL_UNICACHECTM_CTCNTL_IDLEMODE_SMART_IDLE_WAKEUP       (0x00000003U)

#define CSL_UNICACHECTM_CTCNTL_REVID_MASK                       (0x00000078U)
#define CSL_UNICACHECTM_CTCNTL_REVID_SHIFT                      (3U)
#define CSL_UNICACHECTM_CTCNTL_REVID_RESETVAL                   (0x00000001U)
#define CSL_UNICACHECTM_CTCNTL_REVID_MAX                        (0x0000000fU)

#define CSL_UNICACHECTM_CTCNTL_NUMCNTR_MASK                     (0x00001F80U)
#define CSL_UNICACHECTM_CTCNTL_NUMCNTR_SHIFT                    (7U)
#define CSL_UNICACHECTM_CTCNTL_NUMCNTR_RESETVAL                 (0x00000008U)
#define CSL_UNICACHECTM_CTCNTL_NUMCNTR_MAX                      (0x0000003fU)

#define CSL_UNICACHECTM_CTCNTL_NUMTIMR_MASK                     (0x0003E000U)
#define CSL_UNICACHECTM_CTCNTL_NUMTIMR_SHIFT                    (13U)
#define CSL_UNICACHECTM_CTCNTL_NUMTIMR_RESETVAL                 (0x00000002U)
#define CSL_UNICACHECTM_CTCNTL_NUMTIMR_MAX                      (0x0000001fU)

#define CSL_UNICACHECTM_CTCNTL_NUMINPT_MASK                     (0x03FC0000U)
#define CSL_UNICACHECTM_CTCNTL_NUMINPT_SHIFT                    (18U)
#define CSL_UNICACHECTM_CTCNTL_NUMINPT_RESETVAL                 (0x00000020U)
#define CSL_UNICACHECTM_CTCNTL_NUMINPT_MAX                      (0x000000ffU)

#define CSL_UNICACHECTM_CTCNTL_NUMSTM_MASK                      (0xFC000000U)
#define CSL_UNICACHECTM_CTCNTL_NUMSTM_SHIFT                     (26U)
#define CSL_UNICACHECTM_CTCNTL_NUMSTM_RESETVAL                  (0x00000000U)
#define CSL_UNICACHECTM_CTCNTL_NUMSTM_MAX                       (0x0000003fU)

#define CSL_UNICACHECTM_CTCNTL_RESETVAL                         (0x0080440cU)

/* CTSTMCNTL */

#define CSL_UNICACHECTM_CTSTMCNTL_ENBL_MASK                     (0x00000001U)
#define CSL_UNICACHECTM_CTSTMCNTL_ENBL_SHIFT                    (0U)
#define CSL_UNICACHECTM_CTSTMCNTL_ENBL_RESETVAL                 (0x00000000U)
#define CSL_UNICACHECTM_CTSTMCNTL_ENBL_DISABLE                  (0x00000000U)
#define CSL_UNICACHECTM_CTSTMCNTL_ENBL_ENABLE                   (0x00000001U)

#define CSL_UNICACHECTM_CTSTMCNTL_SENDOVR_MASK                  (0x00000002U)
#define CSL_UNICACHECTM_CTSTMCNTL_SENDOVR_SHIFT                 (1U)
#define CSL_UNICACHECTM_CTSTMCNTL_SENDOVR_RESETVAL              (0x00000001U)
#define CSL_UNICACHECTM_CTSTMCNTL_SENDOVR_MAX                   (0x00000001U)

#define CSL_UNICACHECTM_CTSTMCNTL_CSMXPORT_MASK                 (0x00000004U)
#define CSL_UNICACHECTM_CTSTMCNTL_CSMXPORT_SHIFT                (2U)
#define CSL_UNICACHECTM_CTSTMCNTL_CSMXPORT_RESETVAL             (0x00000000U)
#define CSL_UNICACHECTM_CTSTMCNTL_CSMXPORT_MAX                  (0x00000001U)

#define CSL_UNICACHECTM_CTSTMCNTL_CCMVAIL_MASK                  (0x00000008U)
#define CSL_UNICACHECTM_CTSTMCNTL_CCMVAIL_SHIFT                 (3U)
#define CSL_UNICACHECTM_CTSTMCNTL_CCMVAIL_RESETVAL              (0x00000000U)
#define CSL_UNICACHECTM_CTSTMCNTL_CCMVAIL_MAX                   (0x00000001U)

#define CSL_UNICACHECTM_CTSTMCNTL_CCMXPORT_MASK                 (0x00000010U)
#define CSL_UNICACHECTM_CTSTMCNTL_CCMXPORT_SHIFT                (4U)
#define CSL_UNICACHECTM_CTSTMCNTL_CCMXPORT_RESETVAL             (0x00000000U)
#define CSL_UNICACHECTM_CTSTMCNTL_CCMXPORT_MAX                  (0x00000001U)

#define CSL_UNICACHECTM_CTSTMCNTL_NUMXPORT_MASK                 (0x000003E0U)
#define CSL_UNICACHECTM_CTSTMCNTL_NUMXPORT_SHIFT                (5U)
#define CSL_UNICACHECTM_CTSTMCNTL_NUMXPORT_RESETVAL             (0x00000000U)
#define CSL_UNICACHECTM_CTSTMCNTL_NUMXPORT_MAX                  (0x0000001fU)

#define CSL_UNICACHECTM_CTSTMCNTL_XPORTACT_MASK                 (0x00000400U)
#define CSL_UNICACHECTM_CTSTMCNTL_XPORTACT_SHIFT                (10U)
#define CSL_UNICACHECTM_CTSTMCNTL_XPORTACT_RESETVAL             (0x00000000U)
#define CSL_UNICACHECTM_CTSTMCNTL_XPORTACT_MAX                  (0x00000001U)

#define CSL_UNICACHECTM_CTSTMCNTL_RESETVAL                      (0x00000002U)

/* CTSTMMSTID */

#define CSL_UNICACHECTM_CTSTMMSTID_MASTID_MASK                  (0x0000007FU)
#define CSL_UNICACHECTM_CTSTMMSTID_MASTID_SHIFT                 (0U)
#define CSL_UNICACHECTM_CTSTMMSTID_MASTID_RESETVAL              (0x00000000U)
#define CSL_UNICACHECTM_CTSTMMSTID_MASTID_MAX                   (0x0000007fU)

#define CSL_UNICACHECTM_CTSTMMSTID_RESETVAL                     (0x00000000U)

/* CTSTMINTVL */

#define CSL_UNICACHECTM_CTSTMINTVL_INTERVAL_MASK                (0x0000FFFFU)
#define CSL_UNICACHECTM_CTSTMINTVL_INTERVAL_SHIFT               (0U)
#define CSL_UNICACHECTM_CTSTMINTVL_INTERVAL_RESETVAL            (0x00000000U)
#define CSL_UNICACHECTM_CTSTMINTVL_INTERVAL_MAX                 (0x0000ffffU)

#define CSL_UNICACHECTM_CTSTMINTVL_RESETVAL                     (0x00000000U)

/* CTSTMSEL */

#define CSL_UNICACHECTM_CTSTMSEL_COUNTSEL_MASK                  (0xFFFFFFFFU)
#define CSL_UNICACHECTM_CTSTMSEL_COUNTSEL_SHIFT                 (0U)
#define CSL_UNICACHECTM_CTSTMSEL_COUNTSEL_RESETVAL              (0x00000000U)
#define CSL_UNICACHECTM_CTSTMSEL_COUNTSEL_MAX                   (0xffffffffU)

#define CSL_UNICACHECTM_CTSTMSEL_RESETVAL                       (0x00000000U)

/* TINTVLR */

#define CSL_UNICACHECTM_TINTVLR_INTERVAL_MASK                   (0xFFFFFFFFU)
#define CSL_UNICACHECTM_TINTVLR_INTERVAL_SHIFT                  (0U)
#define CSL_UNICACHECTM_TINTVLR_INTERVAL_RESETVAL               (0x00000000U)
#define CSL_UNICACHECTM_TINTVLR_INTERVAL_MAX                    (0xffffffffU)

#define CSL_UNICACHECTM_TINTVLR_RESETVAL                        (0x00000000U)

/* CTDBGNUM */

#define CSL_UNICACHECTM_CTDBGNUM_NUMEVT_MASK                    (0x00000007U)
#define CSL_UNICACHECTM_CTDBGNUM_NUMEVT_SHIFT                   (0U)
#define CSL_UNICACHECTM_CTDBGNUM_NUMEVT_RESETVAL                (0x00000000U)
#define CSL_UNICACHECTM_CTDBGNUM_NUMEVT_MAX                     (0x00000007U)

#define CSL_UNICACHECTM_CTDBGNUM_RESETVAL                       (0x00000000U)

/* CTDBGEVT */

#define CSL_UNICACHECTM_CTDBGEVT_INPSEL_MASK                    (0x000000FFU)
#define CSL_UNICACHECTM_CTDBGEVT_INPSEL_SHIFT                   (0U)
#define CSL_UNICACHECTM_CTDBGEVT_INPSEL_RESETVAL                (0x00000000U)
#define CSL_UNICACHECTM_CTDBGEVT_INPSEL_MAX                     (0x000000ffU)

#define CSL_UNICACHECTM_CTDBGEVT_RESETVAL                       (0x00000000U)

/* CTGNBL */

#define CSL_UNICACHECTM_CTGNBL_ENABLE_MASK                      (0x000000FFU)
#define CSL_UNICACHECTM_CTGNBL_ENABLE_SHIFT                     (0U)
#define CSL_UNICACHECTM_CTGNBL_ENABLE_RESETVAL                  (0x00000000U)
#define CSL_UNICACHECTM_CTGNBL_ENABLE_MAX                       (0x000000ffU)

#define CSL_UNICACHECTM_CTGNBL_RESETVAL                         (0x00000000U)

/* CTGRST */

#define CSL_UNICACHECTM_CTGRST_RESET_MASK                       (0x000000FFU)
#define CSL_UNICACHECTM_CTGRST_RESET_SHIFT                      (0U)
#define CSL_UNICACHECTM_CTGRST_RESET_RESETVAL                   (0x00000000U)
#define CSL_UNICACHECTM_CTGRST_RESET_MAX                        (0x000000ffU)

#define CSL_UNICACHECTM_CTGRST_RESETVAL                         (0x00000000U)

/* CTCR_WT */

#define CSL_UNICACHECTM_CTCR_WT_ENBL_MASK                       (0x00000001U)
#define CSL_UNICACHECTM_CTCR_WT_ENBL_SHIFT                      (0U)
#define CSL_UNICACHECTM_CTCR_WT_ENBL_RESETVAL                   (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WT_ENBL_MAX                        (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WT_RESET_MASK                      (0x00000002U)
#define CSL_UNICACHECTM_CTCR_WT_RESET_SHIFT                     (1U)
#define CSL_UNICACHECTM_CTCR_WT_RESET_RESETVAL                  (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WT_RESET_MAX                       (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WT_CHAIN_MASK                      (0x00000004U)
#define CSL_UNICACHECTM_CTCR_WT_CHAIN_SHIFT                     (2U)
#define CSL_UNICACHECTM_CTCR_WT_CHAIN_RESETVAL                  (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WT_CHAIN_MAX                       (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WT_DURMODE_MASK                    (0x00000008U)
#define CSL_UNICACHECTM_CTCR_WT_DURMODE_SHIFT                   (3U)
#define CSL_UNICACHECTM_CTCR_WT_DURMODE_RESETVAL                (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WT_DURMODE_MAX                     (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WT_FREE_MASK                       (0x00000010U)
#define CSL_UNICACHECTM_CTCR_WT_FREE_SHIFT                      (4U)
#define CSL_UNICACHECTM_CTCR_WT_FREE_RESETVAL                   (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WT_FREE_MAX                        (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WT_IDLE_MASK                       (0x00000020U)
#define CSL_UNICACHECTM_CTCR_WT_IDLE_SHIFT                      (5U)
#define CSL_UNICACHECTM_CTCR_WT_IDLE_RESETVAL                   (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WT_IDLE_MAX                        (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WT_OVRFLW_MASK                     (0x00000040U)
#define CSL_UNICACHECTM_CTCR_WT_OVRFLW_SHIFT                    (6U)
#define CSL_UNICACHECTM_CTCR_WT_OVRFLW_RESETVAL                 (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WT_OVRFLW_MAX                      (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WT_INT_MASK                        (0x00000100U)
#define CSL_UNICACHECTM_CTCR_WT_INT_SHIFT                       (8U)
#define CSL_UNICACHECTM_CTCR_WT_INT_RESETVAL                    (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WT_INT_MAX                         (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WT_DBG_MASK                        (0x00000200U)
#define CSL_UNICACHECTM_CTCR_WT_DBG_SHIFT                       (9U)
#define CSL_UNICACHECTM_CTCR_WT_DBG_RESETVAL                    (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WT_DBG_MAX                         (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WT_RESTART_MASK                    (0x00000400U)
#define CSL_UNICACHECTM_CTCR_WT_RESTART_SHIFT                   (10U)
#define CSL_UNICACHECTM_CTCR_WT_RESTART_RESETVAL                (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WT_RESTART_MAX                     (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WT_INPSEL_MASK                     (0x001F0000U)
#define CSL_UNICACHECTM_CTCR_WT_INPSEL_SHIFT                    (16U)
#define CSL_UNICACHECTM_CTCR_WT_INPSEL_RESETVAL                 (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WT_INPSEL_MAX                      (0x0000001fU)

#define CSL_UNICACHECTM_CTCR_WT_RESETVAL                        (0x00000000U)

/* CTCR_WOT */

#define CSL_UNICACHECTM_CTCR_WOT_ENBL_MASK                      (0x00000001U)
#define CSL_UNICACHECTM_CTCR_WOT_ENBL_SHIFT                     (0U)
#define CSL_UNICACHECTM_CTCR_WOT_ENBL_RESETVAL                  (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WOT_ENBL_MAX                       (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WOT_RESET_MASK                     (0x00000002U)
#define CSL_UNICACHECTM_CTCR_WOT_RESET_SHIFT                    (1U)
#define CSL_UNICACHECTM_CTCR_WOT_RESET_RESETVAL                 (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WOT_RESET_MAX                      (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WOT_CHAIN_MASK                     (0x00000004U)
#define CSL_UNICACHECTM_CTCR_WOT_CHAIN_SHIFT                    (2U)
#define CSL_UNICACHECTM_CTCR_WOT_CHAIN_RESETVAL                 (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WOT_CHAIN_MAX                      (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WOT_DURMODE_MASK                   (0x00000008U)
#define CSL_UNICACHECTM_CTCR_WOT_DURMODE_SHIFT                  (3U)
#define CSL_UNICACHECTM_CTCR_WOT_DURMODE_RESETVAL               (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WOT_DURMODE_MAX                    (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WOT_FREE_MASK                      (0x00000010U)
#define CSL_UNICACHECTM_CTCR_WOT_FREE_SHIFT                     (4U)
#define CSL_UNICACHECTM_CTCR_WOT_FREE_RESETVAL                  (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WOT_FREE_MAX                       (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WOT_IDLE_MASK                      (0x00000020U)
#define CSL_UNICACHECTM_CTCR_WOT_IDLE_SHIFT                     (5U)
#define CSL_UNICACHECTM_CTCR_WOT_IDLE_RESETVAL                  (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WOT_IDLE_MAX                       (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WOT_OVRFLW_MASK                    (0x00000040U)
#define CSL_UNICACHECTM_CTCR_WOT_OVRFLW_SHIFT                   (6U)
#define CSL_UNICACHECTM_CTCR_WOT_OVRFLW_RESETVAL                (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WOT_OVRFLW_MAX                     (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WOT_INT_MASK                       (0x00000100U)
#define CSL_UNICACHECTM_CTCR_WOT_INT_SHIFT                      (8U)
#define CSL_UNICACHECTM_CTCR_WOT_INT_RESETVAL                   (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WOT_INT_MAX                        (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WOT_DBG_MASK                       (0x00000200U)
#define CSL_UNICACHECTM_CTCR_WOT_DBG_SHIFT                      (9U)
#define CSL_UNICACHECTM_CTCR_WOT_DBG_RESETVAL                   (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WOT_DBG_MAX                        (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WOT_RESTART_MASK                   (0x00000400U)
#define CSL_UNICACHECTM_CTCR_WOT_RESTART_SHIFT                  (10U)
#define CSL_UNICACHECTM_CTCR_WOT_RESTART_RESETVAL               (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WOT_RESTART_MAX                    (0x00000001U)

#define CSL_UNICACHECTM_CTCR_WOT_INPSEL_MASK                    (0x001F0000U)
#define CSL_UNICACHECTM_CTCR_WOT_INPSEL_SHIFT                   (16U)
#define CSL_UNICACHECTM_CTCR_WOT_INPSEL_RESETVAL                (0x00000000U)
#define CSL_UNICACHECTM_CTCR_WOT_INPSEL_MAX                     (0x0000001fU)

#define CSL_UNICACHECTM_CTCR_WOT_RESETVAL                       (0x00000000U)

/* CTCNTR */

#define CSL_UNICACHECTM_CTCNTR_COUNT_MASK                       (0xFFFFFFFFU)
#define CSL_UNICACHECTM_CTCNTR_COUNT_SHIFT                      (0U)
#define CSL_UNICACHECTM_CTCNTR_COUNT_RESETVAL                   (0x00000000U)
#define CSL_UNICACHECTM_CTCNTR_COUNT_MAX                        (0xffffffffU)

#define CSL_UNICACHECTM_CTCNTR_RESETVAL                         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
