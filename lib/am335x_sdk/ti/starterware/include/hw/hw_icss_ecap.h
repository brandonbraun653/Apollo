/*
* hw_icss_ecap.h
*
* Register-level header file for HW_ICSS_ECAP
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
#ifndef HW_ICSS_ECAP_H_
#define HW_ICSS_ECAP_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define HW_ICSS_ECAP_TSCNT                                     (0x0U)
#define HW_ICSS_ECAP_CNTPHS                                    (0x4U)
#define HW_ICSS_ECAP_CAP1                                      (0x8U)
#define HW_ICSS_ECAP_CAP2                                      (0xcU)
#define HW_ICSS_ECAP_CAP3                                      (0x10U)
#define HW_ICSS_ECAP_CAP4                                      (0x14U)
#define HW_ICSS_ECAP_ECCTL1                                    (0x28U)
#define HW_ICSS_ECAP_ECCTL2                                    (0x2aU)
#define HW_ICSS_ECAP_ECEINT                                    (0x2cU)
#define HW_ICSS_ECAP_ECFLG                                     (0x2eU)
#define HW_ICSS_ECAP_ECCLR                                     (0x30U)
#define HW_ICSS_ECAP_ECFRC                                     (0x34U)
#define HW_ICSS_ECAP_PID                                       (0x5cU)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define HW_ICSS_ECAP_TSCNT_SHIFT                               (0U)
#define HW_ICSS_ECAP_TSCNT_MASK                                (0xffffffffU)

#define HW_ICSS_ECAP_CAP3_SHIFT                                (0U)
#define HW_ICSS_ECAP_CAP3_MASK                                 (0xffffffffU)

#define HW_ICSS_ECAP_CAP4_SHIFT                                (0U)
#define HW_ICSS_ECAP_CAP4_MASK                                 (0xffffffffU)

#define HW_ICSS_ECAP_ECCTL1_CAP1POL_SHIFT                      (0U)
#define HW_ICSS_ECAP_ECCTL1_CAP1POL_MASK                       (0x00000001U)

#define HW_ICSS_ECAP_ECCTL1_CTRRST1_SHIFT                      (1U)
#define HW_ICSS_ECAP_ECCTL1_CTRRST1_MASK                       (0x00000002U)

#define HW_ICSS_ECAP_ECCTL1_CAP2POL_SHIFT                      (2U)
#define HW_ICSS_ECAP_ECCTL1_CAP2POL_MASK                       (0x00000004U)

#define HW_ICSS_ECAP_ECCTL1_CTRRST2_SHIFT                      (3U)
#define HW_ICSS_ECAP_ECCTL1_CTRRST2_MASK                       (0x00000008U)

#define HW_ICSS_ECAP_ECCTL1_CAP3POL_SHIFT                      (4U)
#define HW_ICSS_ECAP_ECCTL1_CAP3POL_MASK                       (0x00000010U)

#define HW_ICSS_ECAP_ECCTL1_CTRRST3_SHIFT                      (5U)
#define HW_ICSS_ECAP_ECCTL1_CTRRST3_MASK                       (0x00000020U)

#define HW_ICSS_ECAP_ECCTL1_CAP4POL_SHIFT                      (6U)
#define HW_ICSS_ECAP_ECCTL1_CAP4POL_MASK                       (0x00000040U)

#define HW_ICSS_ECAP_ECCTL1_CTRRST4_SHIFT                      (7U)
#define HW_ICSS_ECAP_ECCTL1_CTRRST4_MASK                       (0x00000080U)

#define HW_ICSS_ECAP_ECCTL1_CAPLDEN_SHIFT                      (8U)
#define HW_ICSS_ECAP_ECCTL1_CAPLDEN_MASK                       (0x00000100U)

#define HW_ICSS_ECAP_ECCTL1_EVTFLTPS_SHIFT                     (9U)
#define HW_ICSS_ECAP_ECCTL1_EVTFLTPS_MASK                      (0x00003e00U)

#define HW_ICSS_ECAP_ECCTL1_SOFT_SHIFT                         (14U)
#define HW_ICSS_ECAP_ECCTL1_SOFT_MASK                          (0x00004000U)

#define HW_ICSS_ECAP_ECCTL1_FREE_SHIFT                         (15U)
#define HW_ICSS_ECAP_ECCTL1_FREE_MASK                          (0x00008000U)

#define HW_ICSS_ECAP_ECCTL2_CONTONESHT_SHIFT                   (0U)
#define HW_ICSS_ECAP_ECCTL2_CONTONESHT_MASK                    (0x00000001U)

#define HW_ICSS_ECAP_ECCTL2_STOPVALUE_SHIFT                    (1U)
#define HW_ICSS_ECAP_ECCTL2_STOPVALUE_MASK                     (0x00000006U)

#define HW_ICSS_ECAP_ECCTL2_TSCNTSTP_SHIFT                     (4U)
#define HW_ICSS_ECAP_ECCTL2_TSCNTSTP_MASK                      (0x00000010U)

#define HW_ICSS_ECAP_ECCTL2_SYNCI_EN_SHIFT                     (5U)
#define HW_ICSS_ECAP_ECCTL2_SYNCI_EN_MASK                      (0x00000020U)

#define HW_ICSS_ECAP_ECCTL2_SYNCO_SEL_SHIFT                    (6U)
#define HW_ICSS_ECAP_ECCTL2_SYNCO_SEL_MASK                     (0x000000c0U)

#define HW_ICSS_ECAP_ECCTL2_CAPAPWM_SHIFT                      (9U)
#define HW_ICSS_ECAP_ECCTL2_CAPAPWM_MASK                       (0x00000200U)

#define HW_ICSS_ECAP_ECCTL2_APWMPOL_SHIFT                      (10U)
#define HW_ICSS_ECAP_ECCTL2_APWMPOL_MASK                       (0x00000400U)

#define HW_ICSS_ECAP_ECCTL2_FILTER_SHIFT                       (11U)
#define HW_ICSS_ECAP_ECCTL2_FILTER_MASK                        (0x0000f800U)

#define HW_ICSS_ECAP_ECEINT_RESV0_SHIFT                        (0U)
#define HW_ICSS_ECAP_ECEINT_RESV0_MASK                         (0x00000001U)

#define HW_ICSS_ECAP_ECEINT_CEVT1_SHIFT                        (1U)
#define HW_ICSS_ECAP_ECEINT_CEVT1_MASK                         (0x00000002U)

#define HW_ICSS_ECAP_ECEINT_CEVT2_SHIFT                        (2U)
#define HW_ICSS_ECAP_ECEINT_CEVT2_MASK                         (0x00000004U)

#define HW_ICSS_ECAP_ECEINT_CEVT3_SHIFT                        (3U)
#define HW_ICSS_ECAP_ECEINT_CEVT3_MASK                         (0x00000008U)

#define HW_ICSS_ECAP_ECEINT_CEVT4_SHIFT                        (4U)
#define HW_ICSS_ECAP_ECEINT_CEVT4_MASK                         (0x00000010U)

#define HW_ICSS_ECAP_ECEINT_CNTOVF_SHIFT                       (5U)
#define HW_ICSS_ECAP_ECEINT_CNTOVF_MASK                        (0x00000020U)

#define HW_ICSS_ECAP_ECEINT_PRDEQ_SHIFT                        (6U)
#define HW_ICSS_ECAP_ECEINT_PRDEQ_MASK                         (0x00000040U)

#define HW_ICSS_ECAP_ECEINT_CMPEQ_SHIFT                        (7U)
#define HW_ICSS_ECAP_ECEINT_CMPEQ_MASK                         (0x00000080U)

#define HW_ICSS_ECAP_ECEINT_RESV1_SHIFT                        (8U)
#define HW_ICSS_ECAP_ECEINT_RESV1_MASK                         (0x0000ff00U)

#define HW_ICSS_ECAP_ECFLG_INT_SHIFT                           (0U)
#define HW_ICSS_ECAP_ECFLG_INT_MASK                            (0x00000001U)

#define HW_ICSS_ECAP_ECFLG_CEVT1_SHIFT                         (1U)
#define HW_ICSS_ECAP_ECFLG_CEVT1_MASK                          (0x00000002U)

#define HW_ICSS_ECAP_ECFLG_CEVT2_SHIFT                         (2U)
#define HW_ICSS_ECAP_ECFLG_CEVT2_MASK                          (0x00000004U)

#define HW_ICSS_ECAP_ECFLG_CEVT3_SHIFT                         (3U)
#define HW_ICSS_ECAP_ECFLG_CEVT3_MASK                          (0x00000008U)

#define HW_ICSS_ECAP_ECFLG_CEVT4_SHIFT                         (4U)
#define HW_ICSS_ECAP_ECFLG_CEVT4_MASK                          (0x00000010U)

#define HW_ICSS_ECAP_ECFLG_CNTOVF_SHIFT                        (5U)
#define HW_ICSS_ECAP_ECFLG_CNTOVF_MASK                         (0x00000020U)

#define HW_ICSS_ECAP_ECFLG_PRDEQ_SHIFT                         (6U)
#define HW_ICSS_ECAP_ECFLG_PRDEQ_MASK                          (0x00000040U)

#define HW_ICSS_ECAP_ECFLG_CMPEQ_SHIFT                         (7U)
#define HW_ICSS_ECAP_ECFLG_CMPEQ_MASK                          (0x00000080U)

#define HW_ICSS_ECAP_ECFLG_RESV0_SHIFT                         (8U)
#define HW_ICSS_ECAP_ECFLG_RESV0_MASK                          (0x0000ff00U)

#define HW_ICSS_ECAP_ECCLR_INT_SHIFT                           (0U)
#define HW_ICSS_ECAP_ECCLR_INT_MASK                            (0x00000001U)

#define HW_ICSS_ECAP_ECCLR_CEVT1_SHIFT                         (1U)
#define HW_ICSS_ECAP_ECCLR_CEVT1_MASK                          (0x00000002U)

#define HW_ICSS_ECAP_ECCLR_CEVT2_SHIFT                         (2U)
#define HW_ICSS_ECAP_ECCLR_CEVT2_MASK                          (0x00000004U)

#define HW_ICSS_ECAP_ECCLR_CEVT3_SHIFT                         (3U)
#define HW_ICSS_ECAP_ECCLR_CEVT3_MASK                          (0x00000008U)

#define HW_ICSS_ECAP_ECCLR_CEVT4_SHIFT                         (4U)
#define HW_ICSS_ECAP_ECCLR_CEVT4_MASK                          (0x00000010U)

#define HW_ICSS_ECAP_ECCLR_CNTOVF_SHIFT                        (5U)
#define HW_ICSS_ECAP_ECCLR_CNTOVF_MASK                         (0x00000020U)

#define HW_ICSS_ECAP_ECCLR_PRDEQ_SHIFT                         (6U)
#define HW_ICSS_ECAP_ECCLR_PRDEQ_MASK                          (0x00000040U)

#define HW_ICSS_ECAP_ECCLR_CMPEQ_SHIFT                         (7U)
#define HW_ICSS_ECAP_ECCLR_CMPEQ_MASK                          (0x00000080U)

#define HW_ICSS_ECAP_ECCLR_RESV0_SHIFT                         (8U)
#define HW_ICSS_ECAP_ECCLR_RESV0_MASK                          (0x0000ff00U)

#define HW_ICSS_ECAP_ECFRC_RESV0_SHIFT                         (0U)
#define HW_ICSS_ECAP_ECFRC_RESV0_MASK                          (0x00000001U)

#define HW_ICSS_ECAP_ECFRC_CEVT1_SHIFT                         (1U)
#define HW_ICSS_ECAP_ECFRC_CEVT1_MASK                          (0x00000002U)

#define HW_ICSS_ECAP_ECFRC_CEVT2_SHIFT                         (2U)
#define HW_ICSS_ECAP_ECFRC_CEVT2_MASK                          (0x00000004U)

#define HW_ICSS_ECAP_ECFRC_CEVT3_SHIFT                         (3U)
#define HW_ICSS_ECAP_ECFRC_CEVT3_MASK                          (0x00000008U)

#define HW_ICSS_ECAP_ECFRC_CEVT4_SHIFT                         (4U)
#define HW_ICSS_ECAP_ECFRC_CEVT4_MASK                          (0x00000010U)

#define HW_ICSS_ECAP_ECFRC_CNTOVF_SHIFT                        (5U)
#define HW_ICSS_ECAP_ECFRC_CNTOVF_MASK                         (0x00000020U)

#define HW_ICSS_ECAP_ECFRC_PRDEQ_SHIFT                         (6U)
#define HW_ICSS_ECAP_ECFRC_PRDEQ_MASK                          (0x00000040U)

#define HW_ICSS_ECAP_ECFRC_CMPEQ_SHIFT                         (7U)
#define HW_ICSS_ECAP_ECFRC_CMPEQ_MASK                          (0x00000080U)

#define HW_ICSS_ECAP_ECFRC_RESV1_SHIFT                         (8U)
#define HW_ICSS_ECAP_ECFRC_RESV1_MASK                          (0x0000ff00U)

#define HW_ICSS_ECAP_PID_REVID_SHIFT                           (0U)
#define HW_ICSS_ECAP_PID_REVID_MASK                            (0xffffffffU)

#ifdef __cplusplus
}
#endif

#endif /* HW_ICSS_ECAP_H_ */
