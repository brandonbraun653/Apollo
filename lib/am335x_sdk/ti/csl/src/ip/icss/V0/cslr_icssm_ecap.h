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
#ifndef CSLR_ICSSM_ECAP_H_
#define CSLR_ICSSM_ECAP_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for ecapaddressBlockTable
**************************************************************************/
typedef struct {
    volatile Uint32 TSCNT;
    volatile Uint32 CNTPHS;
    volatile Uint32 CAP1;
    volatile Uint32 CAP2;
    volatile Uint32 CAP3;
    volatile Uint32 CAP4;
    volatile Uint8  RSVD0[16];
    volatile Uint32 ECCTL1;
    volatile Uint32 ECCTL2;
    volatile Uint32 ECEINT;
    volatile Uint32 ECFLG;
    volatile Uint32 ECCLR;
    volatile Uint32 ECFRC;
    volatile Uint8  RSVD1[36];
    volatile Uint32 PID;
} CSL_icssm_ecapRegs;


/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_ICSSM_ECAP_TSCNT                                    (0x0U)
#define CSL_ICSSM_ECAP_CNTPHS                                   (0x4U)
#define CSL_ICSSM_ECAP_CAP1                                     (0x8U)
#define CSL_ICSSM_ECAP_CAP2                                     (0xCU)
#define CSL_ICSSM_ECAP_CAP3                                     (0x10U)
#define CSL_ICSSM_ECAP_CAP4                                     (0x14U)
#define CSL_ICSSM_ECAP_ECCTL1                                   (0x28U)
#define CSL_ICSSM_ECAP_ECCTL2                                   (0x2AU)
#define CSL_ICSSM_ECAP_ECEINT                                   (0x2CU)
#define CSL_ICSSM_ECAP_ECFLG                                    (0x2EU)
#define CSL_ICSSM_ECAP_ECCLR                                    (0x30U)
#define CSL_ICSSM_ECAP_ECFRC                                    (0x34U)
#define CSL_ICSSM_ECAP_PID                                      (0x5CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* TSCNT */

#define CSL_ICSSM_ECAP_TSCNT_TSCNT_MASK                         (0xFFFFFFFFU)
#define CSL_ICSSM_ECAP_TSCNT_TSCNT_SHIFT                        (0x00000000U)
#define CSL_ICSSM_ECAP_TSCNT_TSCNT_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_TSCNT_TSCNT_MAX                          (0xffffffffU)

#define CSL_ICSSM_ECAP_TSCNT_RESETVAL                           (0x00000000U)

/* CNTPHS */

#define CSL_ICSSM_ECAP_CNTPHS_CNTPHS_MASK                       (0xFFFFFFFFU)
#define CSL_ICSSM_ECAP_CNTPHS_CNTPHS_SHIFT                      (0x00000000U)
#define CSL_ICSSM_ECAP_CNTPHS_CNTPHS_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_ECAP_CNTPHS_CNTPHS_MAX                        (0xffffffffU)

#define CSL_ICSSM_ECAP_CNTPHS_RESETVAL                          (0x00000000U)

/* CAP1 */

#define CSL_ICSSM_ECAP_CAP1_CAP1_MASK                           (0xFFFFFFFFU)
#define CSL_ICSSM_ECAP_CAP1_CAP1_SHIFT                          (0x00000000U)
#define CSL_ICSSM_ECAP_CAP1_CAP1_RESETVAL                       (0x00000000U)
#define CSL_ICSSM_ECAP_CAP1_CAP1_MAX                            (0xffffffffU)

#define CSL_ICSSM_ECAP_CAP1_RESETVAL                            (0x00000000U)

/* CAP2 */

#define CSL_ICSSM_ECAP_CAP2_CAP2_MASK                           (0xFFFFFFFFU)
#define CSL_ICSSM_ECAP_CAP2_CAP2_SHIFT                          (0x00000000U)
#define CSL_ICSSM_ECAP_CAP2_CAP2_RESETVAL                       (0x00000000U)
#define CSL_ICSSM_ECAP_CAP2_CAP2_MAX                            (0xffffffffU)

#define CSL_ICSSM_ECAP_CAP2_RESETVAL                            (0x00000000U)

/* CAP3 */

#define CSL_ICSSM_ECAP_CAP3_CAP3_MASK                           (0xFFFFFFFFU)
#define CSL_ICSSM_ECAP_CAP3_CAP3_SHIFT                          (0x00000000U)
#define CSL_ICSSM_ECAP_CAP3_CAP3_RESETVAL                       (0x00000000U)
#define CSL_ICSSM_ECAP_CAP3_CAP3_MAX                            (0xffffffffU)

#define CSL_ICSSM_ECAP_CAP3_RESETVAL                            (0x00000000U)

/* CAP4 */

#define CSL_ICSSM_ECAP_CAP4_CAP4_MASK                           (0xFFFFFFFFU)
#define CSL_ICSSM_ECAP_CAP4_CAP4_SHIFT                          (0x00000000U)
#define CSL_ICSSM_ECAP_CAP4_CAP4_RESETVAL                       (0x00000000U)
#define CSL_ICSSM_ECAP_CAP4_CAP4_MAX                            (0xffffffffU)

#define CSL_ICSSM_ECAP_CAP4_RESETVAL                            (0x00000000U)

/* ECCTL1 */

#define CSL_ICSSM_ECAP_ECCTL1_SOFT_MASK                         (0x00004000U)
#define CSL_ICSSM_ECAP_ECCTL1_SOFT_SHIFT                        (0x0000000EU)
#define CSL_ICSSM_ECAP_ECCTL1_SOFT_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_SOFT_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL1_FREE_MASK                         (0x00008000U)
#define CSL_ICSSM_ECAP_ECCTL1_FREE_SHIFT                        (0x0000000FU)
#define CSL_ICSSM_ECAP_ECCTL1_FREE_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_FREE_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL1_EVTFLTPS_MASK                     (0x00003E00U)
#define CSL_ICSSM_ECAP_ECCTL1_EVTFLTPS_SHIFT                    (0x00000009U)
#define CSL_ICSSM_ECAP_ECCTL1_EVTFLTPS_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_EVTFLTPS_MAX                      (0x0000001fU)

#define CSL_ICSSM_ECAP_ECCTL1_CAPLDEN_MASK                      (0x00000100U)
#define CSL_ICSSM_ECAP_ECCTL1_CAPLDEN_SHIFT                     (0x00000008U)
#define CSL_ICSSM_ECAP_ECCTL1_CAPLDEN_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_CAPLDEN_MAX                       (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL1_CTRRST4_MASK                      (0x00000080U)
#define CSL_ICSSM_ECAP_ECCTL1_CTRRST4_SHIFT                     (0x00000007U)
#define CSL_ICSSM_ECAP_ECCTL1_CTRRST4_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_CTRRST4_MAX                       (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL1_CAP4POL_MASK                      (0x00000040U)
#define CSL_ICSSM_ECAP_ECCTL1_CAP4POL_SHIFT                     (0x00000006U)
#define CSL_ICSSM_ECAP_ECCTL1_CAP4POL_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_CAP4POL_MAX                       (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL1_CTRRST3_MASK                      (0x00000020U)
#define CSL_ICSSM_ECAP_ECCTL1_CTRRST3_SHIFT                     (0x00000005U)
#define CSL_ICSSM_ECAP_ECCTL1_CTRRST3_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_CTRRST3_MAX                       (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL1_CAP3POL_MASK                      (0x00000010U)
#define CSL_ICSSM_ECAP_ECCTL1_CAP3POL_SHIFT                     (0x00000004U)
#define CSL_ICSSM_ECAP_ECCTL1_CAP3POL_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_CAP3POL_MAX                       (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL1_CTRRST2_MASK                      (0x00000008U)
#define CSL_ICSSM_ECAP_ECCTL1_CTRRST2_SHIFT                     (0x00000003U)
#define CSL_ICSSM_ECAP_ECCTL1_CTRRST2_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_CTRRST2_MAX                       (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL1_CAP2POL_MASK                      (0x00000004U)
#define CSL_ICSSM_ECAP_ECCTL1_CAP2POL_SHIFT                     (0x00000002U)
#define CSL_ICSSM_ECAP_ECCTL1_CAP2POL_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_CAP2POL_MAX                       (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL1_CTRRST1_MASK                      (0x00000002U)
#define CSL_ICSSM_ECAP_ECCTL1_CTRRST1_SHIFT                     (0x00000001U)
#define CSL_ICSSM_ECAP_ECCTL1_CTRRST1_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_CTRRST1_MAX                       (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL1_CAP1POL_MASK                      (0x00000001U)
#define CSL_ICSSM_ECAP_ECCTL1_CAP1POL_SHIFT                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_CAP1POL_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL1_CAP1POL_MAX                       (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL1_RESETVAL                          (0x00000000U)

/* ECCTL2 */

#define CSL_ICSSM_ECAP_ECCTL2_FILTER_MASK                       (0x0000F800U)
#define CSL_ICSSM_ECAP_ECCTL2_FILTER_SHIFT                      (0x0000000BU)
#define CSL_ICSSM_ECAP_ECCTL2_FILTER_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL2_FILTER_MAX                        (0x0000001fU)

#define CSL_ICSSM_ECAP_ECCTL2_APWMPOL_MASK                      (0x00000400U)
#define CSL_ICSSM_ECAP_ECCTL2_APWMPOL_SHIFT                     (0x0000000AU)
#define CSL_ICSSM_ECAP_ECCTL2_APWMPOL_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL2_APWMPOL_MAX                       (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL2_CAPAPWM_MASK                      (0x00000200U)
#define CSL_ICSSM_ECAP_ECCTL2_CAPAPWM_SHIFT                     (0x00000009U)
#define CSL_ICSSM_ECAP_ECCTL2_CAPAPWM_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL2_CAPAPWM_MAX                       (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL2_SWSYNC_MASK                       (0x00000100U)
#define CSL_ICSSM_ECAP_ECCTL2_SWSYNC_SHIFT                      (0x00000008U)
#define CSL_ICSSM_ECAP_ECCTL2_SWSYNC_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL2_SWSYNC_MAX                        (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL2_SYNCO_SEL_MASK                    (0x000000C0U)
#define CSL_ICSSM_ECAP_ECCTL2_SYNCO_SEL_SHIFT                   (0x00000006U)
#define CSL_ICSSM_ECAP_ECCTL2_SYNCO_SEL_RESETVAL                (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL2_SYNCO_SEL_MAX                     (0x00000003U)

#define CSL_ICSSM_ECAP_ECCTL2_SYNCI_EN_MASK                     (0x00000020U)
#define CSL_ICSSM_ECAP_ECCTL2_SYNCI_EN_SHIFT                    (0x00000005U)
#define CSL_ICSSM_ECAP_ECCTL2_SYNCI_EN_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL2_SYNCI_EN_MAX                      (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL2_TSCNTSTP_MASK                     (0x00000010U)
#define CSL_ICSSM_ECAP_ECCTL2_TSCNTSTP_SHIFT                    (0x00000004U)
#define CSL_ICSSM_ECAP_ECCTL2_TSCNTSTP_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL2_TSCNTSTP_MAX                      (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL2_REARMRESET_MASK                   (0x00000008U)
#define CSL_ICSSM_ECAP_ECCTL2_REARMRESET_SHIFT                  (0x00000003U)
#define CSL_ICSSM_ECAP_ECCTL2_REARMRESET_RESETVAL               (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL2_REARMRESET_MAX                    (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL2_STOPVALUE_MASK                    (0x00000006U)
#define CSL_ICSSM_ECAP_ECCTL2_STOPVALUE_SHIFT                   (0x00000001U)
#define CSL_ICSSM_ECAP_ECCTL2_STOPVALUE_RESETVAL                (0x00000003U)
#define CSL_ICSSM_ECAP_ECCTL2_STOPVALUE_MAX                     (0x00000003U)

#define CSL_ICSSM_ECAP_ECCTL2_CONTONESHT_MASK                   (0x00000001U)
#define CSL_ICSSM_ECAP_ECCTL2_CONTONESHT_SHIFT                  (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL2_CONTONESHT_RESETVAL               (0x00000000U)
#define CSL_ICSSM_ECAP_ECCTL2_CONTONESHT_MAX                    (0x00000001U)

#define CSL_ICSSM_ECAP_ECCTL2_RESETVAL                          (0x00000006U)

/* ECEINT */

#define CSL_ICSSM_ECAP_ECEINT__RESV1_MASK                       (0x0000FF00U)
#define CSL_ICSSM_ECAP_ECEINT__RESV1_SHIFT                      (0x00000008U)
#define CSL_ICSSM_ECAP_ECEINT__RESV1_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_ECAP_ECEINT__RESV1_MAX                        (0x000000ffU)

#define CSL_ICSSM_ECAP_ECEINT_CMPEQ_MASK                        (0x00000080U)
#define CSL_ICSSM_ECAP_ECEINT_CMPEQ_SHIFT                       (0x00000007U)
#define CSL_ICSSM_ECAP_ECEINT_CMPEQ_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECEINT_CMPEQ_MAX                         (0x00000001U)

#define CSL_ICSSM_ECAP_ECEINT_PRDEQ_MASK                        (0x00000040U)
#define CSL_ICSSM_ECAP_ECEINT_PRDEQ_SHIFT                       (0x00000006U)
#define CSL_ICSSM_ECAP_ECEINT_PRDEQ_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECEINT_PRDEQ_MAX                         (0x00000001U)

#define CSL_ICSSM_ECAP_ECEINT_CNTOVF_MASK                       (0x00000020U)
#define CSL_ICSSM_ECAP_ECEINT_CNTOVF_SHIFT                      (0x00000005U)
#define CSL_ICSSM_ECAP_ECEINT_CNTOVF_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_ECAP_ECEINT_CNTOVF_MAX                        (0x00000001U)

#define CSL_ICSSM_ECAP_ECEINT_CEVT4_MASK                        (0x00000010U)
#define CSL_ICSSM_ECAP_ECEINT_CEVT4_SHIFT                       (0x00000004U)
#define CSL_ICSSM_ECAP_ECEINT_CEVT4_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECEINT_CEVT4_MAX                         (0x00000001U)

#define CSL_ICSSM_ECAP_ECEINT_CEVT3_MASK                        (0x00000008U)
#define CSL_ICSSM_ECAP_ECEINT_CEVT3_SHIFT                       (0x00000003U)
#define CSL_ICSSM_ECAP_ECEINT_CEVT3_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECEINT_CEVT3_MAX                         (0x00000001U)

#define CSL_ICSSM_ECAP_ECEINT_CEVT2_MASK                        (0x00000004U)
#define CSL_ICSSM_ECAP_ECEINT_CEVT2_SHIFT                       (0x00000002U)
#define CSL_ICSSM_ECAP_ECEINT_CEVT2_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECEINT_CEVT2_MAX                         (0x00000001U)

#define CSL_ICSSM_ECAP_ECEINT_CEVT1_MASK                        (0x00000002U)
#define CSL_ICSSM_ECAP_ECEINT_CEVT1_SHIFT                       (0x00000001U)
#define CSL_ICSSM_ECAP_ECEINT_CEVT1_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECEINT_CEVT1_MAX                         (0x00000001U)

#define CSL_ICSSM_ECAP_ECEINT__RESV0_MASK                       (0x00000001U)
#define CSL_ICSSM_ECAP_ECEINT__RESV0_SHIFT                      (0x00000000U)
#define CSL_ICSSM_ECAP_ECEINT__RESV0_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_ECAP_ECEINT__RESV0_MAX                        (0x00000001U)

#define CSL_ICSSM_ECAP_ECEINT_RESETVAL                          (0x00000000U)

/* ECFLG */

#define CSL_ICSSM_ECAP_ECFLG__RESV0_MASK                        (0x0000FF00U)
#define CSL_ICSSM_ECAP_ECFLG__RESV0_SHIFT                       (0x00000008U)
#define CSL_ICSSM_ECAP_ECFLG__RESV0_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECFLG__RESV0_MAX                         (0x000000ffU)

#define CSL_ICSSM_ECAP_ECFLG_CMPEQ_MASK                         (0x00000080U)
#define CSL_ICSSM_ECAP_ECFLG_CMPEQ_SHIFT                        (0x00000007U)
#define CSL_ICSSM_ECAP_ECFLG_CMPEQ_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECFLG_CMPEQ_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECFLG_PRDEQ_MASK                         (0x00000040U)
#define CSL_ICSSM_ECAP_ECFLG_PRDEQ_SHIFT                        (0x00000006U)
#define CSL_ICSSM_ECAP_ECFLG_PRDEQ_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECFLG_PRDEQ_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECFLG_CNTOVF_MASK                        (0x00000020U)
#define CSL_ICSSM_ECAP_ECFLG_CNTOVF_SHIFT                       (0x00000005U)
#define CSL_ICSSM_ECAP_ECFLG_CNTOVF_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECFLG_CNTOVF_MAX                         (0x00000001U)

#define CSL_ICSSM_ECAP_ECFLG_CEVT4_MASK                         (0x00000010U)
#define CSL_ICSSM_ECAP_ECFLG_CEVT4_SHIFT                        (0x00000004U)
#define CSL_ICSSM_ECAP_ECFLG_CEVT4_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECFLG_CEVT4_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECFLG_CEVT3_MASK                         (0x00000008U)
#define CSL_ICSSM_ECAP_ECFLG_CEVT3_SHIFT                        (0x00000003U)
#define CSL_ICSSM_ECAP_ECFLG_CEVT3_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECFLG_CEVT3_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECFLG_CEVT2_MASK                         (0x00000004U)
#define CSL_ICSSM_ECAP_ECFLG_CEVT2_SHIFT                        (0x00000002U)
#define CSL_ICSSM_ECAP_ECFLG_CEVT2_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECFLG_CEVT2_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECFLG_CEVT1_MASK                         (0x00000002U)
#define CSL_ICSSM_ECAP_ECFLG_CEVT1_SHIFT                        (0x00000001U)
#define CSL_ICSSM_ECAP_ECFLG_CEVT1_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECFLG_CEVT1_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECFLG_INT_MASK                           (0x00000001U)
#define CSL_ICSSM_ECAP_ECFLG_INT_SHIFT                          (0x00000000U)
#define CSL_ICSSM_ECAP_ECFLG_INT_RESETVAL                       (0x00000000U)
#define CSL_ICSSM_ECAP_ECFLG_INT_MAX                            (0x00000001U)

#define CSL_ICSSM_ECAP_ECFLG_RESETVAL                           (0x00000000U)

/* ECCLR */

#define CSL_ICSSM_ECAP_ECCLR__RESV0_MASK                        (0x0000FF00U)
#define CSL_ICSSM_ECAP_ECCLR__RESV0_SHIFT                       (0x00000008U)
#define CSL_ICSSM_ECAP_ECCLR__RESV0_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECCLR__RESV0_MAX                         (0x000000ffU)

#define CSL_ICSSM_ECAP_ECCLR_CMPEQ_MASK                         (0x00000080U)
#define CSL_ICSSM_ECAP_ECCLR_CMPEQ_SHIFT                        (0x00000007U)
#define CSL_ICSSM_ECAP_ECCLR_CMPEQ_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECCLR_CMPEQ_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECCLR_PRDEQ_MASK                         (0x00000040U)
#define CSL_ICSSM_ECAP_ECCLR_PRDEQ_SHIFT                        (0x00000006U)
#define CSL_ICSSM_ECAP_ECCLR_PRDEQ_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECCLR_PRDEQ_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECCLR_CNTOVF_MASK                        (0x00000020U)
#define CSL_ICSSM_ECAP_ECCLR_CNTOVF_SHIFT                       (0x00000005U)
#define CSL_ICSSM_ECAP_ECCLR_CNTOVF_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECCLR_CNTOVF_MAX                         (0x00000001U)

#define CSL_ICSSM_ECAP_ECCLR_CEVT4_MASK                         (0x00000010U)
#define CSL_ICSSM_ECAP_ECCLR_CEVT4_SHIFT                        (0x00000004U)
#define CSL_ICSSM_ECAP_ECCLR_CEVT4_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECCLR_CEVT4_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECCLR_CEVT3_MASK                         (0x00000008U)
#define CSL_ICSSM_ECAP_ECCLR_CEVT3_SHIFT                        (0x00000003U)
#define CSL_ICSSM_ECAP_ECCLR_CEVT3_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECCLR_CEVT3_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECCLR_CEVT2_MASK                         (0x00000004U)
#define CSL_ICSSM_ECAP_ECCLR_CEVT2_SHIFT                        (0x00000002U)
#define CSL_ICSSM_ECAP_ECCLR_CEVT2_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECCLR_CEVT2_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECCLR_CEVT1_MASK                         (0x00000002U)
#define CSL_ICSSM_ECAP_ECCLR_CEVT1_SHIFT                        (0x00000001U)
#define CSL_ICSSM_ECAP_ECCLR_CEVT1_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECCLR_CEVT1_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECCLR_INT_MASK                           (0x00000001U)
#define CSL_ICSSM_ECAP_ECCLR_INT_SHIFT                          (0x00000000U)
#define CSL_ICSSM_ECAP_ECCLR_INT_RESETVAL                       (0x00000000U)
#define CSL_ICSSM_ECAP_ECCLR_INT_MAX                            (0x00000001U)

#define CSL_ICSSM_ECAP_ECCLR_RESETVAL                           (0x00000000U)

/* ECFRC */

#define CSL_ICSSM_ECAP_ECFRC__RESV1_MASK                        (0x0000FF00U)
#define CSL_ICSSM_ECAP_ECFRC__RESV1_SHIFT                       (0x00000008U)
#define CSL_ICSSM_ECAP_ECFRC__RESV1_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECFRC__RESV1_MAX                         (0x000000ffU)

#define CSL_ICSSM_ECAP_ECFRC_CMPEQ_MASK                         (0x00000080U)
#define CSL_ICSSM_ECAP_ECFRC_CMPEQ_SHIFT                        (0x00000007U)
#define CSL_ICSSM_ECAP_ECFRC_CMPEQ_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECFRC_CMPEQ_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECFRC_PRDEQ_MASK                         (0x00000040U)
#define CSL_ICSSM_ECAP_ECFRC_PRDEQ_SHIFT                        (0x00000006U)
#define CSL_ICSSM_ECAP_ECFRC_PRDEQ_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECFRC_PRDEQ_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECFRC_CNTOVF_MASK                        (0x00000020U)
#define CSL_ICSSM_ECAP_ECFRC_CNTOVF_SHIFT                       (0x00000005U)
#define CSL_ICSSM_ECAP_ECFRC_CNTOVF_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECFRC_CNTOVF_MAX                         (0x00000001U)

#define CSL_ICSSM_ECAP_ECFRC_CEVT4_MASK                         (0x00000010U)
#define CSL_ICSSM_ECAP_ECFRC_CEVT4_SHIFT                        (0x00000004U)
#define CSL_ICSSM_ECAP_ECFRC_CEVT4_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECFRC_CEVT4_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECFRC_CEVT3_MASK                         (0x00000008U)
#define CSL_ICSSM_ECAP_ECFRC_CEVT3_SHIFT                        (0x00000003U)
#define CSL_ICSSM_ECAP_ECFRC_CEVT3_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECFRC_CEVT3_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECFRC_CEVT2_MASK                         (0x00000004U)
#define CSL_ICSSM_ECAP_ECFRC_CEVT2_SHIFT                        (0x00000002U)
#define CSL_ICSSM_ECAP_ECFRC_CEVT2_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECFRC_CEVT2_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECFRC_CEVT1_MASK                         (0x00000002U)
#define CSL_ICSSM_ECAP_ECFRC_CEVT1_SHIFT                        (0x00000001U)
#define CSL_ICSSM_ECAP_ECFRC_CEVT1_RESETVAL                     (0x00000000U)
#define CSL_ICSSM_ECAP_ECFRC_CEVT1_MAX                          (0x00000001U)

#define CSL_ICSSM_ECAP_ECFRC__RESV0_MASK                        (0x00000001U)
#define CSL_ICSSM_ECAP_ECFRC__RESV0_SHIFT                       (0x00000000U)
#define CSL_ICSSM_ECAP_ECFRC__RESV0_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_ECAP_ECFRC__RESV0_MAX                         (0x00000001U)

#define CSL_ICSSM_ECAP_ECFRC_RESETVAL                           (0x00000000U)

/* PID */

#define CSL_ICSSM_ECAP_PID_REVID_MASK                           (0xFFFFFFFFU)
#define CSL_ICSSM_ECAP_PID_REVID_SHIFT                          (0x00000000U)
#define CSL_ICSSM_ECAP_PID_REVID_RESETVAL                       (0x44d22100U)
#define CSL_ICSSM_ECAP_PID_REVID_MAX                            (0xffffffffU)

#define CSL_ICSSM_ECAP_PID_RESETVAL                             (0x44d22100U)

#ifdef __cplusplus
}
#endif
#endif
