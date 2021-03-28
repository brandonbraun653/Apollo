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
#ifndef CSLR_ECAP_H_
#define CSLR_ECAP_H_

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
    volatile Uint32 TSCTR;
    volatile Uint32 CTRPHS;
    volatile Uint32 CAP1;
    volatile Uint32 CAP2;
    volatile Uint32 CAP3;
    volatile Uint32 CAP4;
    volatile Uint8  RSVD0[16];
    volatile Uint16 ECCTL1;
    volatile Uint16 ECCTL2;
    volatile Uint16 ECEINT;
    volatile Uint16 ECFLG;
    volatile Uint16 ECCLR;
    volatile Uint16 ECFRC;
    volatile Uint8  RSVD1[41];
    volatile Uint32 REVID;
    volatile Uint8  RSVD2[304];
} CSL_EcapRegs;


/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_ECAP_REVID                                          (0x5CU)
#define CSL_ECAP_ECEINT                                         (0x2CU)
#define CSL_ECAP_ECCTL1                                         (0x28U)
#define CSL_ECAP_ECCLR                                          (0x30U)
#define CSL_ECAP_CTRPHS                                         (0x4U)
#define CSL_ECAP_ECFRC                                          (0x32U)
#define CSL_ECAP_CAP2                                           (0xCU)
#define CSL_ECAP_CAP3                                           (0x10U)
#define CSL_ECAP_TSCTR                                          (0x0U)
#define CSL_ECAP_ECFLG                                          (0x2EU)
#define CSL_ECAP_CAP1                                           (0x8U)
#define CSL_ECAP_ECCTL2                                         (0x2AU)
#define CSL_ECAP_CAP4                                           (0x14U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVID */

#define CSL_ECAP_REVID_REV_MASK                                 (0xFFFFFFFFU)
#define CSL_ECAP_REVID_REV_SHIFT                                (0U)
#define CSL_ECAP_REVID_REV_RESETVAL                             (0x44d22100U)
#define CSL_ECAP_REVID_REV_MAX                                  (0xffffffffU)

#define CSL_ECAP_REVID_RESETVAL                                 (0x44d22100U)

/* ECEINT */

#define CSL_ECAP_ECEINT_CEVT1_MASK                              (0x00000002U)
#define CSL_ECAP_ECEINT_CEVT1_SHIFT                             (1U)
#define CSL_ECAP_ECEINT_CEVT1_RESETVAL                          (0x00000000U)
#define CSL_ECAP_ECEINT_CEVT1_DISABLE                           (0x00000000U)
#define CSL_ECAP_ECEINT_CEVT1_ENABLE                            (0x00000001U)

#define CSL_ECAP_ECEINT_CEVT2_MASK                              (0x00000004U)
#define CSL_ECAP_ECEINT_CEVT2_SHIFT                             (2U)
#define CSL_ECAP_ECEINT_CEVT2_RESETVAL                          (0x00000000U)
#define CSL_ECAP_ECEINT_CEVT2_DISABLE                           (0x00000000U)
#define CSL_ECAP_ECEINT_CEVT2_EN_0X1                            (0x00000001U)

#define CSL_ECAP_ECEINT_CEVT3_MASK                              (0x00000008U)
#define CSL_ECAP_ECEINT_CEVT3_SHIFT                             (3U)
#define CSL_ECAP_ECEINT_CEVT3_RESETVAL                          (0x00000000U)
#define CSL_ECAP_ECEINT_CEVT3_ENABLE                            (0x00000001U)
#define CSL_ECAP_ECEINT_CEVT3_DISABLE                           (0x00000000U)

#define CSL_ECAP_ECEINT_CEVT4_MASK                              (0x00000010U)
#define CSL_ECAP_ECEINT_CEVT4_SHIFT                             (4U)
#define CSL_ECAP_ECEINT_CEVT4_RESETVAL                          (0x00000000U)
#define CSL_ECAP_ECEINT_CEVT4_ENABLE                            (0x00000001U)
#define CSL_ECAP_ECEINT_CEVT4_DISABLE                           (0x00000000U)

#define CSL_ECAP_ECEINT_CNTOVF_MASK                             (0x00000020U)
#define CSL_ECAP_ECEINT_CNTOVF_SHIFT                            (5U)
#define CSL_ECAP_ECEINT_CNTOVF_RESETVAL                         (0x00000000U)
#define CSL_ECAP_ECEINT_CNTOVF_DISABLE                          (0x00000000U)
#define CSL_ECAP_ECEINT_CNTOVF_ENABLE                           (0x00000001U)

#define CSL_ECAP_ECEINT_PRDEQ_MASK                              (0x00000040U)
#define CSL_ECAP_ECEINT_PRDEQ_SHIFT                             (6U)
#define CSL_ECAP_ECEINT_PRDEQ_RESETVAL                          (0x00000000U)
#define CSL_ECAP_ECEINT_PRDEQ_ENABLE                            (0x00000001U)
#define CSL_ECAP_ECEINT_PRDEQ_DISABLE                           (0x00000000U)

#define CSL_ECAP_ECEINT_CMPEQ_MASK                              (0x00000080U)
#define CSL_ECAP_ECEINT_CMPEQ_SHIFT                             (7U)
#define CSL_ECAP_ECEINT_CMPEQ_RESETVAL                          (0x00000000U)
#define CSL_ECAP_ECEINT_CMPEQ_ENABLE                            (0x00000001U)
#define CSL_ECAP_ECEINT_CMPEQ_DISABLE                           (0x00000000U)

#define CSL_ECAP_ECEINT_RESETVAL                                (0x00000000U)

/* ECCTL1 */

#define CSL_ECAP_ECCTL1_CAP1POL_MASK                            (0x00000001U)
#define CSL_ECAP_ECCTL1_CAP1POL_SHIFT                           (0U)
#define CSL_ECAP_ECCTL1_CAP1POL_RESETVAL                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CAP1POL_RE                              (0x00000000U)
#define CSL_ECAP_ECCTL1_CAP1POL_FE                              (0x00000001U)

#define CSL_ECAP_ECCTL1_CTRRST1_MASK                            (0x00000002U)
#define CSL_ECAP_ECCTL1_CTRRST1_SHIFT                           (1U)
#define CSL_ECAP_ECCTL1_CTRRST1_RESETVAL                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CTRRST1_NO_RESET                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CTRRST1_RESET                           (0x00000001U)

#define CSL_ECAP_ECCTL1_CAP2POL_MASK                            (0x00000004U)
#define CSL_ECAP_ECCTL1_CAP2POL_SHIFT                           (2U)
#define CSL_ECAP_ECCTL1_CAP2POL_RESETVAL                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CAP2POL_RE                              (0x00000000U)
#define CSL_ECAP_ECCTL1_CAP2POL_FE                              (0x00000001U)

#define CSL_ECAP_ECCTL1_CTRRST2_MASK                            (0x00000008U)
#define CSL_ECAP_ECCTL1_CTRRST2_SHIFT                           (3U)
#define CSL_ECAP_ECCTL1_CTRRST2_RESETVAL                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CTRRST2_NO_RESET                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CTRRST2_RESET                           (0x00000001U)

#define CSL_ECAP_ECCTL1_CAP3POL_MASK                            (0x00000010U)
#define CSL_ECAP_ECCTL1_CAP3POL_SHIFT                           (4U)
#define CSL_ECAP_ECCTL1_CAP3POL_RESETVAL                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CAP3POL_FE                              (0x00000001U)
#define CSL_ECAP_ECCTL1_CAP3POL_RE                              (0x00000000U)

#define CSL_ECAP_ECCTL1_CTRRST3_MASK                            (0x00000020U)
#define CSL_ECAP_ECCTL1_CTRRST3_SHIFT                           (5U)
#define CSL_ECAP_ECCTL1_CTRRST3_RESETVAL                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CTRRST3_NO_RESET                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CTRRST3_RESET                           (0x00000001U)

#define CSL_ECAP_ECCTL1_CAP4POL_MASK                            (0x00000040U)
#define CSL_ECAP_ECCTL1_CAP4POL_SHIFT                           (6U)
#define CSL_ECAP_ECCTL1_CAP4POL_RESETVAL                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CAP4POL_FE                              (0x00000001U)
#define CSL_ECAP_ECCTL1_CAP4POL_RE                              (0x00000000U)

#define CSL_ECAP_ECCTL1_CTRRST4_MASK                            (0x00000080U)
#define CSL_ECAP_ECCTL1_CTRRST4_SHIFT                           (7U)
#define CSL_ECAP_ECCTL1_CTRRST4_RESETVAL                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CTRRST4_NO_RESET                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CTRRST4_RESET                           (0x00000001U)

#define CSL_ECAP_ECCTL1_CAPLDEN_MASK                            (0x00000100U)
#define CSL_ECAP_ECCTL1_CAPLDEN_SHIFT                           (8U)
#define CSL_ECAP_ECCTL1_CAPLDEN_RESETVAL                        (0x00000000U)
#define CSL_ECAP_ECCTL1_CAPLDEN_DISABLE                         (0x00000000U)
#define CSL_ECAP_ECCTL1_CAPLDEN_ENABLE                          (0x00000001U)

#define CSL_ECAP_ECCTL1_PRESCALE_MASK                           (0x00003E00U)
#define CSL_ECAP_ECCTL1_PRESCALE_SHIFT                          (9U)
#define CSL_ECAP_ECCTL1_PRESCALE_RESETVAL                       (0x00000000U)
#define CSL_ECAP_ECCTL1_PRESCALE_MAX                            (0x0000001fU)

#define CSL_ECAP_ECCTL1_FREE_SOFT_MASK                          (0x0000C000U)
#define CSL_ECAP_ECCTL1_FREE_SOFT_SHIFT                         (14U)
#define CSL_ECAP_ECCTL1_FREE_SOFT_RESETVAL                      (0x00000000U)
#define CSL_ECAP_ECCTL1_FREE_SOFT_RUN_FREE1                     (0x00000002U)
#define CSL_ECAP_ECCTL1_FREE_SOFT_RUN_0                         (0x00000001U)
#define CSL_ECAP_ECCTL1_FREE_SOFT_STOP                          (0x00000000U)
#define CSL_ECAP_ECCTL1_FREE_SOFT_RUN_FREE2                     (0x00000003U)

#define CSL_ECAP_ECCTL1_RESETVAL                                (0x00000000U)

/* ECCLR */

#define CSL_ECAP_ECCLR_INT_MASK                                 (0x00000001U)
#define CSL_ECAP_ECCLR_INT_SHIFT                                (0U)
#define CSL_ECAP_ECCLR_INT_RESETVAL                             (0x00000000U)
#define CSL_ECAP_ECCLR_INT_NO_EFFECT                            (0x00000000U)
#define CSL_ECAP_ECCLR_INT_CLEAR                                (0x00000001U)

#define CSL_ECAP_ECCLR_CEVT1_MASK                               (0x00000002U)
#define CSL_ECAP_ECCLR_CEVT1_SHIFT                              (1U)
#define CSL_ECAP_ECCLR_CEVT1_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECCLR_CEVT1_CLEAR                              (0x00000001U)
#define CSL_ECAP_ECCLR_CEVT1_NO_EFFECT                          (0x00000000U)

#define CSL_ECAP_ECCLR_CEVT2_MASK                               (0x00000004U)
#define CSL_ECAP_ECCLR_CEVT2_SHIFT                              (2U)
#define CSL_ECAP_ECCLR_CEVT2_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECCLR_CEVT2_NO_EFFECT                          (0x00000000U)
#define CSL_ECAP_ECCLR_CEVT2_CLEAR                              (0x00000001U)

#define CSL_ECAP_ECCLR_CEVT3_MASK                               (0x00000008U)
#define CSL_ECAP_ECCLR_CEVT3_SHIFT                              (3U)
#define CSL_ECAP_ECCLR_CEVT3_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECCLR_CEVT3_NO_EFFECT                          (0x00000000U)
#define CSL_ECAP_ECCLR_CEVT3_CLEAR                              (0x00000001U)

#define CSL_ECAP_ECCLR_CEVT4_MASK                               (0x00000010U)
#define CSL_ECAP_ECCLR_CEVT4_SHIFT                              (4U)
#define CSL_ECAP_ECCLR_CEVT4_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECCLR_CEVT4_NO_EFFECT                          (0x00000000U)
#define CSL_ECAP_ECCLR_CEVT4_CLEAR                              (0x00000001U)

#define CSL_ECAP_ECCLR_CNTOVF_MASK                              (0x00000020U)
#define CSL_ECAP_ECCLR_CNTOVF_SHIFT                             (5U)
#define CSL_ECAP_ECCLR_CNTOVF_RESETVAL                          (0x00000000U)
#define CSL_ECAP_ECCLR_CNTOVF_CLEAR                             (0x00000001U)
#define CSL_ECAP_ECCLR_CNTOVF_NO_EFFECT                         (0x00000000U)

#define CSL_ECAP_ECCLR_PRDEQ_MASK                               (0x00000040U)
#define CSL_ECAP_ECCLR_PRDEQ_SHIFT                              (6U)
#define CSL_ECAP_ECCLR_PRDEQ_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECCLR_PRDEQ_CLEAR                              (0x00000001U)
#define CSL_ECAP_ECCLR_PRDEQ_NO_EFFECT                          (0x00000000U)

#define CSL_ECAP_ECCLR_CMPEQ_MASK                               (0x00000080U)
#define CSL_ECAP_ECCLR_CMPEQ_SHIFT                              (7U)
#define CSL_ECAP_ECCLR_CMPEQ_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECCLR_CMPEQ_CLEAR                              (0x00000001U)
#define CSL_ECAP_ECCLR_CMPEQ_NO_EFFECT                          (0x00000000U)

#define CSL_ECAP_ECCLR_RESETVAL                                 (0x00000000U)

/* CTRPHS */

#define CSL_ECAP_CTRPHS_CTRPHS_MASK                             (0xFFFFFFFFU)
#define CSL_ECAP_CTRPHS_CTRPHS_SHIFT                            (0U)
#define CSL_ECAP_CTRPHS_CTRPHS_RESETVAL                         (0x00000000U)
#define CSL_ECAP_CTRPHS_CTRPHS_MAX                              (0xffffffffU)

#define CSL_ECAP_CTRPHS_RESETVAL                                (0x00000000U)

/* ECFRC */

#define CSL_ECAP_ECFRC_CEVT1_MASK                               (0x00000002U)
#define CSL_ECAP_ECFRC_CEVT1_SHIFT                              (1U)
#define CSL_ECAP_ECFRC_CEVT1_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECFRC_CEVT1_SET                                (0x00000001U)
#define CSL_ECAP_ECFRC_CEVT1_NO_EFFECT                          (0x00000000U)

#define CSL_ECAP_ECFRC_CEVT2_MASK                               (0x00000004U)
#define CSL_ECAP_ECFRC_CEVT2_SHIFT                              (2U)
#define CSL_ECAP_ECFRC_CEVT2_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECFRC_CEVT2_NO_EFFECT                          (0x00000000U)
#define CSL_ECAP_ECFRC_CEVT2_SET                                (0x00000001U)

#define CSL_ECAP_ECFRC_CEVT3_MASK                               (0x00000008U)
#define CSL_ECAP_ECFRC_CEVT3_SHIFT                              (3U)
#define CSL_ECAP_ECFRC_CEVT3_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECFRC_CEVT3_NO_EFFECT                          (0x00000000U)
#define CSL_ECAP_ECFRC_CEVT3_SET                                (0x00000001U)

#define CSL_ECAP_ECFRC_CEVT4_MASK                               (0x00000010U)
#define CSL_ECAP_ECFRC_CEVT4_SHIFT                              (4U)
#define CSL_ECAP_ECFRC_CEVT4_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECFRC_CEVT4_NO_EFFECT                          (0x00000000U)
#define CSL_ECAP_ECFRC_CEVT4_SET                                (0x00000001U)

#define CSL_ECAP_ECFRC_CNTOVF_MASK                              (0x00000020U)
#define CSL_ECAP_ECFRC_CNTOVF_SHIFT                             (5U)
#define CSL_ECAP_ECFRC_CNTOVF_RESETVAL                          (0x00000000U)
#define CSL_ECAP_ECFRC_CNTOVF_NO_EFFECT                         (0x00000000U)
#define CSL_ECAP_ECFRC_CNTOVF_SET                               (0x00000001U)

#define CSL_ECAP_ECFRC_PRDEQ_MASK                               (0x00000040U)
#define CSL_ECAP_ECFRC_PRDEQ_SHIFT                              (6U)
#define CSL_ECAP_ECFRC_PRDEQ_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECFRC_PRDEQ_NO_EFFECT                          (0x00000000U)
#define CSL_ECAP_ECFRC_PRDEQ_SET                                (0x00000001U)

#define CSL_ECAP_ECFRC_CMPEQ_MASK                               (0x00000080U)
#define CSL_ECAP_ECFRC_CMPEQ_SHIFT                              (7U)
#define CSL_ECAP_ECFRC_CMPEQ_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECFRC_CMPEQ_NO_EFFECT                          (0x00000000U)
#define CSL_ECAP_ECFRC_CMPEQ_SET                                (0x00000001U)

#define CSL_ECAP_ECFRC_RESETVAL                                 (0x00000000U)

/* CAP2 */

#define CSL_ECAP_CAP2_CAP2_MASK                                 (0xFFFFFFFFU)
#define CSL_ECAP_CAP2_CAP2_SHIFT                                (0U)
#define CSL_ECAP_CAP2_CAP2_RESETVAL                             (0x00000000U)
#define CSL_ECAP_CAP2_CAP2_MAX                                  (0xffffffffU)

#define CSL_ECAP_CAP2_RESETVAL                                  (0x00000000U)

/* CAP3 */

#define CSL_ECAP_CAP3_CAP3_MASK                                 (0xFFFFFFFFU)
#define CSL_ECAP_CAP3_CAP3_SHIFT                                (0U)
#define CSL_ECAP_CAP3_CAP3_RESETVAL                             (0x00000000U)
#define CSL_ECAP_CAP3_CAP3_MAX                                  (0xffffffffU)

#define CSL_ECAP_CAP3_RESETVAL                                  (0x00000000U)

/* TSCTR */

#define CSL_ECAP_TSCTR_TSCTR_MASK                               (0xFFFFFFFFU)
#define CSL_ECAP_TSCTR_TSCTR_SHIFT                              (0U)
#define CSL_ECAP_TSCTR_TSCTR_RESETVAL                           (0x00000000U)
#define CSL_ECAP_TSCTR_TSCTR_MAX                                (0xffffffffU)

#define CSL_ECAP_TSCTR_RESETVAL                                 (0x00000000U)

/* ECFLG */

#define CSL_ECAP_ECFLG_INT_MASK                                 (0x00000001U)
#define CSL_ECAP_ECFLG_INT_SHIFT                                (0U)
#define CSL_ECAP_ECFLG_INT_RESETVAL                             (0x00000000U)
#define CSL_ECAP_ECFLG_INT_NO_INTERRUPT                         (0x00000000U)
#define CSL_ECAP_ECFLG_INT_INTERRUPT                            (0x00000001U)

#define CSL_ECAP_ECFLG_CEVT1_MASK                               (0x00000002U)
#define CSL_ECAP_ECFLG_CEVT1_SHIFT                              (1U)
#define CSL_ECAP_ECFLG_CEVT1_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECFLG_CEVT1_EVENT                              (0x00000001U)
#define CSL_ECAP_ECFLG_CEVT1_NO_EVENT                           (0x00000000U)

#define CSL_ECAP_ECFLG_CEVT2_MASK                               (0x00000004U)
#define CSL_ECAP_ECFLG_CEVT2_SHIFT                              (2U)
#define CSL_ECAP_ECFLG_CEVT2_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECFLG_CEVT2_NO_EVENT                           (0x00000000U)
#define CSL_ECAP_ECFLG_CEVT2_EVENT                              (0x00000001U)

#define CSL_ECAP_ECFLG_CEVT3_MASK                               (0x00000008U)
#define CSL_ECAP_ECFLG_CEVT3_SHIFT                              (3U)
#define CSL_ECAP_ECFLG_CEVT3_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECFLG_CEVT3_NO_EVENT                           (0x00000000U)
#define CSL_ECAP_ECFLG_CEVT3_EVENT                              (0x00000001U)

#define CSL_ECAP_ECFLG_CEVT4_MASK                               (0x00000010U)
#define CSL_ECAP_ECFLG_CEVT4_SHIFT                              (4U)
#define CSL_ECAP_ECFLG_CEVT4_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECFLG_CEVT4_EVENT                              (0x00000001U)
#define CSL_ECAP_ECFLG_CEVT4_NO_EVENT                           (0x00000000U)

#define CSL_ECAP_ECFLG_CNTOVF_MASK                              (0x00000020U)
#define CSL_ECAP_ECFLG_CNTOVF_SHIFT                             (5U)
#define CSL_ECAP_ECFLG_CNTOVF_RESETVAL                          (0x00000000U)
#define CSL_ECAP_ECFLG_CNTOVF_NO_EVENT                          (0x00000000U)
#define CSL_ECAP_ECFLG_CNTOVF_EVENT                             (0x00000001U)

#define CSL_ECAP_ECFLG_PRDEQ_MASK                               (0x00000040U)
#define CSL_ECAP_ECFLG_PRDEQ_SHIFT                              (6U)
#define CSL_ECAP_ECFLG_PRDEQ_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECFLG_PRDEQ_NO_EVENT                           (0x00000000U)
#define CSL_ECAP_ECFLG_PRDEQ_EVENT                              (0x00000001U)

#define CSL_ECAP_ECFLG_CMPEQ_MASK                               (0x00000080U)
#define CSL_ECAP_ECFLG_CMPEQ_SHIFT                              (7U)
#define CSL_ECAP_ECFLG_CMPEQ_RESETVAL                           (0x00000000U)
#define CSL_ECAP_ECFLG_CMPEQ_NO_EVENT                           (0x00000000U)
#define CSL_ECAP_ECFLG_CMPEQ_EVENT                              (0x00000001U)

#define CSL_ECAP_ECFLG_RESETVAL                                 (0x00000000U)

/* CAP1 */

#define CSL_ECAP_CAP1_CAP1_MASK                                 (0xFFFFFFFFU)
#define CSL_ECAP_CAP1_CAP1_SHIFT                                (0U)
#define CSL_ECAP_CAP1_CAP1_RESETVAL                             (0x00000000U)
#define CSL_ECAP_CAP1_CAP1_MAX                                  (0xffffffffU)

#define CSL_ECAP_CAP1_RESETVAL                                  (0x00000000U)

/* ECCTL2 */

#define CSL_ECAP_ECCTL2_CONT_ONESHT_MASK                        (0x00000001U)
#define CSL_ECAP_ECCTL2_CONT_ONESHT_SHIFT                       (0U)
#define CSL_ECAP_ECCTL2_CONT_ONESHT_RESETVAL                    (0x00000000U)
#define CSL_ECAP_ECCTL2_CONT_ONESHT_CONTINUOUS                  (0x00000000U)
#define CSL_ECAP_ECCTL2_CONT_ONESHT_ONESHOT                     (0x00000001U)

#define CSL_ECAP_ECCTL2_STOP_WRAP_MASK                          (0x00000006U)
#define CSL_ECAP_ECCTL2_STOP_WRAP_SHIFT                         (1U)
#define CSL_ECAP_ECCTL2_STOP_WRAP_RESETVAL                      (0x00000000U)
#define CSL_ECAP_ECCTL2_STOP_WRAP_CAPT_EVT1                     (0x00000000U)
#define CSL_ECAP_ECCTL2_STOP_WRAP_CAPT_EVT4                     (0x00000003U)
#define CSL_ECAP_ECCTL2_STOP_WRAP_CAPT_EVT2                     (0x00000001U)
#define CSL_ECAP_ECCTL2_STOP_WRAP_CAPT_EVT3                     (0x00000002U)

#define CSL_ECAP_ECCTL2_REARM_MASK                              (0x00000008U)
#define CSL_ECAP_ECCTL2_REARM_SHIFT                             (3U)
#define CSL_ECAP_ECCTL2_REARM_RESETVAL                          (0x00000000U)
#define CSL_ECAP_ECCTL2_REARM_NO_EFFECT                         (0x00000000U)
#define CSL_ECAP_ECCTL2_REARM_ARMS                              (0x00000001U)

#define CSL_ECAP_ECCTL2_TSCTRSTOP_MASK                          (0x00000010U)
#define CSL_ECAP_ECCTL2_TSCTRSTOP_SHIFT                         (4U)
#define CSL_ECAP_ECCTL2_TSCTRSTOP_RESETVAL                      (0x00000000U)
#define CSL_ECAP_ECCTL2_TSCTRSTOP_FREE_RUNNING                  (0x00000001U)
#define CSL_ECAP_ECCTL2_TSCTRSTOP_STOPPED                       (0x00000000U)

#define CSL_ECAP_ECCTL2_SYNCI_EN_MASK                           (0x00000020U)
#define CSL_ECAP_ECCTL2_SYNCI_EN_SHIFT                          (5U)
#define CSL_ECAP_ECCTL2_SYNCI_EN_RESETVAL                       (0x00000000U)
#define CSL_ECAP_ECCTL2_SYNCI_EN_DISABLE                        (0x00000000U)
#define CSL_ECAP_ECCTL2_SYNCI_EN_ENABLE                         (0x00000001U)

#define CSL_ECAP_ECCTL2_SYNCO_SEL_MASK                          (0x000000C0U)
#define CSL_ECAP_ECCTL2_SYNCO_SEL_SHIFT                         (6U)
#define CSL_ECAP_ECCTL2_SYNCO_SEL_RESETVAL                      (0x00000000U)
#define CSL_ECAP_ECCTL2_SYNCO_SEL_DISABLE2                      (0x00000003U)
#define CSL_ECAP_ECCTL2_SYNCO_SEL_PRDEQ                         (0x00000001U)
#define CSL_ECAP_ECCTL2_SYNCO_SEL_DISABLE1                      (0x00000002U)
#define CSL_ECAP_ECCTL2_SYNCO_SEL_SYNC_IN                       (0x00000000U)

#define CSL_ECAP_ECCTL2_SWSYNC_MASK                             (0x00000100U)
#define CSL_ECAP_ECCTL2_SWSYNC_SHIFT                            (8U)
#define CSL_ECAP_ECCTL2_SWSYNC_RESETVAL                         (0x00000000U)
#define CSL_ECAP_ECCTL2_SWSYNC_NO_EFFECT                        (0x00000000U)
#define CSL_ECAP_ECCTL2_SWSYNC_SHADOW_LOAD                      (0x00000001U)

#define CSL_ECAP_ECCTL2_CAP_APWM_MASK                           (0x00000200U)
#define CSL_ECAP_ECCTL2_CAP_APWM_SHIFT                          (9U)
#define CSL_ECAP_ECCTL2_CAP_APWM_RESETVAL                       (0x00000000U)
#define CSL_ECAP_ECCTL2_CAP_APWM_CAPTURE_MODE                   (0x00000000U)
#define CSL_ECAP_ECCTL2_CAP_APWM_APWM_MODE                      (0x00000001U)

#define CSL_ECAP_ECCTL2_APWMPOL_MASK                            (0x00000400U)
#define CSL_ECAP_ECCTL2_APWMPOL_SHIFT                           (10U)
#define CSL_ECAP_ECCTL2_APWMPOL_RESETVAL                        (0x00000000U)
#define CSL_ECAP_ECCTL2_APWMPOL_ACTIVE_LOW                      (0x00000001U)
#define CSL_ECAP_ECCTL2_APWMPOL_ACTIVE_HIGH                     (0x00000000U)

#define CSL_ECAP_ECCTL2_RESETVAL                                (0x00000000U)

/* CAP4 */

#define CSL_ECAP_CAP4_CAP4_MASK                                 (0xFFFFFFFFU)
#define CSL_ECAP_CAP4_CAP4_SHIFT                                (0U)
#define CSL_ECAP_CAP4_CAP4_RESETVAL                             (0x00000000U)
#define CSL_ECAP_CAP4_CAP4_MAX                                  (0xffffffffU)

#define CSL_ECAP_CAP4_RESETVAL                                  (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
