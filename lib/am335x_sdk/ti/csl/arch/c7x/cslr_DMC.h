/********************************************************************
 * Copyright (C) 2019 Texas Instruments Incorporated.
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
#ifndef CSLR_DMC_H
#define CSLR_DMC_H

#ifdef __cplusplus
extern "C"
{
#endif

/**************************************************************************
* Field Definition Macros
**************************************************************************/

    /* L1DCFG */

#define CSL_DMC_L1DCFG_RSVD0_MASK                               (0xFFFFFFFFFFFFFFF8U)
#define CSL_DMC_L1DCFG_RSVD0_SHIFT                              (3U)
#define CSL_DMC_L1DCFG_RSVD0_RESETVAL                           (0x00000000U)

#define CSL_DMC_L1DCFG_L1DMODE_MASK                             (0x00000007U)
#define CSL_DMC_L1DCFG_L1DMODE_SHIFT                            (0U)
#define CSL_DMC_L1DCFG_L1DMODE_RESETVAL                         (0x00000000U)
#define CSL_DMC_L1DCFG_L1DMODE_MAX                              (0x00000007U)

#define CSL_DMC_L1DCFG_RESETVAL                                 (0x00000000U)

    /* L1DCC */

#define CSL_DMC_L1DCC_RSVD0_MASK                                (0xFFFFFFFFFFFE0000U)
#define CSL_DMC_L1DCC_RSVD0_SHIFT                               (17U)
#define CSL_DMC_L1DCC_RSVD0_RESETVAL                            (0x00000000U)

#define CSL_DMC_L1DCC_POPER_MASK                                (0x00010000U)
#define CSL_DMC_L1DCC_POPER_SHIFT                               (16U)
#define CSL_DMC_L1DCC_POPER_RESETVAL                            (0x00000000U)
#define CSL_DMC_L1DCC_POPER_MAX                                 (0x00000001U)

#define CSL_DMC_L1DCC_RSVD1_MASK                                (0x0000FFFEU)
#define CSL_DMC_L1DCC_RSVD1_SHIFT                               (1U)
#define CSL_DMC_L1DCC_RSVD1_RESETVAL                            (0x00000000U)
#define CSL_DMC_L1DCC_RSVD1_MAX                                 (0x00007fffU)

#define CSL_DMC_L1DCC_OPER_MASK                                 (0x00000001U)
#define CSL_DMC_L1DCC_OPER_SHIFT                                (0U)
#define CSL_DMC_L1DCC_OPER_RESETVAL                             (0x00000000U)
#define CSL_DMC_L1DCC_OPER_MAX                                  (0x00000001U)

#define CSL_DMC_L1DCC_RESETVAL                                  (0x00000000U)

    /* L1DWB */

#define CSL_DMC_L1DWB_RSVD0_MASK                                (0xFFFFFFFFFFFFFFFEU)
#define CSL_DMC_L1DWB_RSVD0_SHIFT                               (1U)
#define CSL_DMC_L1DWB_RSVD0_RESETVAL                            (0x00000000U)

#define CSL_DMC_L1DWB_WB_MASK                                   (0x00000001U)
#define CSL_DMC_L1DWB_WB_SHIFT                                  (0U)
#define CSL_DMC_L1DWB_WB_RESETVAL                               (0x00000000U)
#define CSL_DMC_L1DWB_WB_MAX                                    (0x00000001U)

#define CSL_DMC_L1DWB_RESETVAL                                  (0x00000000U)

    /* L1DWBINV */

#define CSL_DMC_L1DWBINV_RSVD0_MASK                             (0xFFFFFFFFFFFFFFFEU)
#define CSL_DMC_L1DWBINV_RSVD0_SHIFT                            (1U)
#define CSL_DMC_L1DWBINV_RSVD0_RESETVAL                         (0x00000000U)

#define CSL_DMC_L1DWBINV_WBINV_MASK                             (0x00000001U)
#define CSL_DMC_L1DWBINV_WBINV_SHIFT                            (0U)
#define CSL_DMC_L1DWBINV_WBINV_RESETVAL                         (0x00000000U)
#define CSL_DMC_L1DWBINV_WBINV_MAX                              (0x00000001U)

#define CSL_DMC_L1DWBINV_RESETVAL                               (0x00000000U)

    /* L1DINV */

#define CSL_DMC_L1DINV_RSVD0_MASK                               (0xFFFFFFFFFFFFFFFEU)
#define CSL_DMC_L1DINV_RSVD0_SHIFT                              (1U)
#define CSL_DMC_L1DINV_RSVD0_RESETVAL                           (0x00000000U)

#define CSL_DMC_L1DINV_INV_MASK                                 (0x00000001U)
#define CSL_DMC_L1DINV_INV_SHIFT                                (0U)
#define CSL_DMC_L1DINV_INV_RESETVAL                             (0x00000000U)
#define CSL_DMC_L1DINV_INV_MAX                                  (0x00000001U)

#define CSL_DMC_L1DINV_RESETVAL                                 (0x00000000U)

    /* L1DEMUCMD */

#define CSL_DMC_L1DEMUCMD_RSVD0_MASK                            (0xFFFFFFFFFFFFFFFEU)
#define CSL_DMC_L1DEMUCMD_RSVD0_SHIFT                           (1U)
#define CSL_DMC_L1DEMUCMD_RSVD0_RESETVAL                        (0x00000000U)

#define CSL_DMC_L1DEMUCMD_TAGMOD_MASK                           (0x00000001U)
#define CSL_DMC_L1DEMUCMD_TAGMOD_SHIFT                          (0U)
#define CSL_DMC_L1DEMUCMD_TAGMOD_RESETVAL                       (0x00000000U)
#define CSL_DMC_L1DEMUCMD_TAGMOD_MAX                            (0x00000001U)

#define CSL_DMC_L1DEMUCMD_RESETVAL                              (0x00000000U)

    /* L1DCTAG */

#define CSL_DMC_L1DCTAG_RSVD0_MASK                              (0xFFFFFFFC00000000U)
#define CSL_DMC_L1DCTAG_RSVD0_SHIFT                             (34U)
#define CSL_DMC_L1DCTAG_RSVD0_RESETVAL                          (0x00000000U)
#define CSL_DMC_L1DCTAG_RSVD0_MAX                               (0x3fffffffU)

#define CSL_DMC_L1DCTAG_MESI_MASK                               (0x300000000U)
#define CSL_DMC_L1DCTAG_MESI_SHIFT                              (32U)
#define CSL_DMC_L1DCTAG_MESI_RESETVAL                           (0x00000000U)
#define CSL_DMC_L1DCTAG_MESI_MAX                                (0x00000003U)

#define CSL_DMC_L1DCTAG_TAG_MASK                                (0xFFFFFFFFU)
#define CSL_DMC_L1DCTAG_TAG_SHIFT                               (0U)
#define CSL_DMC_L1DCTAG_TAG_RESETVAL                            (0x00000000U)
#define CSL_DMC_L1DCTAG_TAG_MAX                                 (0xFFFFFFFFU)

#define CSL_DMC_L1DCTAG_RESETVAL                                (0x00000000U)

    /* L1DEDCFG */

#define CSL_DMC_L1DEDCFG_RSVD0_MASK                             (0xFFFFFFFFFFFFFFFCU)
#define CSL_DMC_L1DEDCFG_RSVD0_SHIFT                            (2U)
#define CSL_DMC_L1DEDCFG_RSVD0_RESETVAL                         (0x00000000U)

#define CSL_DMC_L1DEDCFG_ENABLE_MASK                            (0x00000002U)
#define CSL_DMC_L1DEDCFG_ENABLE_SHIFT                           (1U)
#define CSL_DMC_L1DEDCFG_ENABLE_RESETVAL                        (0x00000000U)
#define CSL_DMC_L1DEDCFG_ENABLE_MAX                             (0x00000001U)

#define CSL_DMC_L1DEDCFG_SUSP_MASK                              (0x00000001U)
#define CSL_DMC_L1DEDCFG_SUSP_SHIFT                             (0U)
#define CSL_DMC_L1DEDCFG_SUSP_RESETVAL                          (0x00000000U)
#define CSL_DMC_L1DEDCFG_SUSP_MAX                               (0x00000001U)

#define CSL_DMC_L1DEDCFG_RESETVAL                               (0x00000000U)

    /* L1DEDSTAT */

#define CSL_DMC_L1DEDSTAT_RSVD0_MASK                            (0xFFFFFFFFFFFFFFFCU)
#define CSL_DMC_L1DEDSTAT_RSVD0_SHIFT                           (2U)
#define CSL_DMC_L1DEDSTAT_RSVD0_RESETVAL                        (0x00000000U)

#define CSL_DMC_L1DEDSTAT_ENABLE_MASK                           (0x00000002U)
#define CSL_DMC_L1DEDSTAT_ENABLE_SHIFT                          (1U)
#define CSL_DMC_L1DEDSTAT_ENABLE_RESETVAL                       (0x00000000U)
#define CSL_DMC_L1DEDSTAT_ENABLE_MAX                            (0x00000001U)

#define CSL_DMC_L1DEDSTAT_SUSP_MASK                             (0x00000001U)
#define CSL_DMC_L1DEDSTAT_SUSP_SHIFT                            (0U)
#define CSL_DMC_L1DEDSTAT_SUSP_RESETVAL                         (0x00000000U)
#define CSL_DMC_L1DEDSTAT_SUSP_MAX                              (0x00000001U)

#define CSL_DMC_L1DEDSTAT_RESETVAL                              (0x00000000U)

    /* L1DCOREDEA */

#define CSL_DMC_L1DCOREDEA_RSVD0_MASK                           (0xFFFFF00000000000U)
#define CSL_DMC_L1DCOREDEA_RSVD0_SHIFT                          (44U)
#define CSL_DMC_L1DCOREDEA_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_DMC_L1DCOREDEA_RSVD0_MAX                            (0x000fffffU)

#define CSL_DMC_L1DCOREDEA_EADDR_MASK                           (0xFFFFFFFFFFFU)
#define CSL_DMC_L1DCOREDEA_EADDR_SHIFT                          (0U)
#define CSL_DMC_L1DCOREDEA_EADDR_RESETVAL                       (0x00000000U)

#define CSL_DMC_L1DCOREDEA_RESETVAL                             (0x00000000U)

    /* L1DCOREDES */

#define CSL_DMC_L1DCOREDES_RSVD0_MASK                           (0xFFFFFFFFFFFE0000U)
#define CSL_DMC_L1DCOREDES_RSVD0_SHIFT                          (17U)
#define CSL_DMC_L1DCOREDES_RSVD0_RESETVAL                       (0x00000000U)

#define CSL_DMC_L1DCOREDES_BITPOS_MASK                          (0x0001FE00U)
#define CSL_DMC_L1DCOREDES_BITPOS_SHIFT                         (9U)
#define CSL_DMC_L1DCOREDES_BITPOS_RESETVAL                      (0x00000000U)
#define CSL_DMC_L1DCOREDES_BITPOS_MAX                           (0x000000ffU)

#define CSL_DMC_L1DCOREDES_RQSTR_MASK                           (0x00000180U)
#define CSL_DMC_L1DCOREDES_RQSTR_SHIFT                          (7U)
#define CSL_DMC_L1DCOREDES_RQSTR_RESETVAL                       (0x00000000U)
#define CSL_DMC_L1DCOREDES_RQSTR_MAX                            (0x00000003U)

#define CSL_DMC_L1DCOREDES_MEME_MASK                            (0x00000060U)
#define CSL_DMC_L1DCOREDES_MEME_SHIFT                           (5U)
#define CSL_DMC_L1DCOREDES_MEME_RESETVAL                        (0x00000000U)
#define CSL_DMC_L1DCOREDES_MEME_MAX                             (0x00000003U)

#define CSL_DMC_L1DCOREDES_BANK_MASK                            (0x0000001EU)
#define CSL_DMC_L1DCOREDES_BANK_SHIFT                           (1U)
#define CSL_DMC_L1DCOREDES_BANK_RESETVAL                        (0x00000000U)
#define CSL_DMC_L1DCOREDES_BANK_MAX                             (0x0000000fU)

#define CSL_DMC_L1DCOREDES_ERROR_FLAG_MASK                      (0x00000001U)
#define CSL_DMC_L1DCOREDES_ERROR_FLAG_SHIFT                     (0U)
#define CSL_DMC_L1DCOREDES_ERROR_FLAG_RESETVAL                  (0x00000000U)
#define CSL_DMC_L1DCOREDES_ERROR_FLAG_MAX                       (0x00000001U)

#define CSL_DMC_L1DCOREDES_RESETVAL                             (0x00000000U)

    /* L1DCOREDER */

#define CSL_DMC_L1DCOREDER_RSVD0_MASK                           (0xFFFFFFFFFFFFFFFEU)
#define CSL_DMC_L1DCOREDER_RSVD0_SHIFT                          (1U)
#define CSL_DMC_L1DCOREDER_RSVD0_RESETVAL                       (0x00000000U)

#define CSL_DMC_L1DCOREDER_ERROR_RESET_MASK                     (0x00000001U)
#define CSL_DMC_L1DCOREDER_ERROR_RESET_SHIFT                    (0U)
#define CSL_DMC_L1DCOREDER_ERROR_RESET_RESETVAL                 (0x00000000U)
#define CSL_DMC_L1DCOREDER_ERROR_RESET_MAX                      (0x00000001U)

#define CSL_DMC_L1DCOREDER_RESETVAL                             (0x00000000U)

    /* L1DCOREDEC */

#define CSL_DMC_L1DCOREDEC_RSVD0_MASK                           (0xFFFFFFFF00000000U)
#define CSL_DMC_L1DCOREDEC_RSVD0_SHIFT                          (32U)
#define CSL_DMC_L1DCOREDEC_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_DMC_L1DCOREDEC_RSVD0_MAX                            (0xFFFFFFFFU)

#define CSL_DMC_L1DCOREDEC_ERROR_COUNT_MASK                     (0xFFFFFFFFU)
#define CSL_DMC_L1DCOREDEC_ERROR_COUNT_SHIFT                    (0U)
#define CSL_DMC_L1DCOREDEC_ERROR_COUNT_RESETVAL                 (0x00000000U)
#define CSL_DMC_L1DCOREDEC_ERROR_COUNT_MAX                      (0xFFFFFFFFU)

#define CSL_DMC_L1DCOREDEC_RESETVAL                             (0x00000000U)

    /* L1DNCOREDEA */

#define CSL_DMC_L1DNCOREDEA_RSVD0_MASK                          (0xFFFFF00000000000U)
#define CSL_DMC_L1DNCOREDEA_RSVD0_SHIFT                         (44U)
#define CSL_DMC_L1DNCOREDEA_RSVD0_RESETVAL                      (0x00000000U)
#define CSL_DMC_L1DNCOREDEA_RSVD0_MAX                           (0x000fffffU)

#define CSL_DMC_L1DNCOREDEA_EADDR_MASK                          (0xFFFFFFFFFFFU)
#define CSL_DMC_L1DNCOREDEA_EADDR_SHIFT                         (0U)
#define CSL_DMC_L1DNCOREDEA_EADDR_RESETVAL                      (0x00000000U)

#define CSL_DMC_L1DNCOREDEA_RESETVAL                            (0x00000000U)

    /* L1DNCOREDES */

#define CSL_DMC_L1DNCOREDES_RSVD0_MASK                          (0xFFFFFFFFFFFFFE00U)
#define CSL_DMC_L1DNCOREDES_RSVD0_SHIFT                         (9U)
#define CSL_DMC_L1DNCOREDES_RSVD0_RESETVAL                      (0x00000000U)

#define CSL_DMC_L1DNCOREDES_RQSTR_MASK                          (0x00000180U)
#define CSL_DMC_L1DNCOREDES_RQSTR_SHIFT                         (7U)
#define CSL_DMC_L1DNCOREDES_RQSTR_RESETVAL                      (0x00000000U)
#define CSL_DMC_L1DNCOREDES_RQSTR_MAX                           (0x00000003U)

#define CSL_DMC_L1DNCOREDES_MEME_MASK                           (0x00000060U)
#define CSL_DMC_L1DNCOREDES_MEME_SHIFT                          (5U)
#define CSL_DMC_L1DNCOREDES_MEME_RESETVAL                       (0x00000000U)
#define CSL_DMC_L1DNCOREDES_MEME_MAX                            (0x00000003U)

#define CSL_DMC_L1DNCOREDES_BANK_MASK                           (0x0000001EU)
#define CSL_DMC_L1DNCOREDES_BANK_SHIFT                          (1U)
#define CSL_DMC_L1DNCOREDES_BANK_RESETVAL                       (0x00000000U)
#define CSL_DMC_L1DNCOREDES_BANK_MAX                            (0x0000000fU)

#define CSL_DMC_L1DNCOREDES_ERROR_FLAG_MASK                     (0x00000001U)
#define CSL_DMC_L1DNCOREDES_ERROR_FLAG_SHIFT                    (0U)
#define CSL_DMC_L1DNCOREDES_ERROR_FLAG_RESETVAL                 (0x00000000U)
#define CSL_DMC_L1DNCOREDES_ERROR_FLAG_MAX                      (0x00000001U)

#define CSL_DMC_L1DNCOREDES_RESETVAL                            (0x00000000U)

    /* L1DNCOREDER */

#define CSL_DMC_L1DNCOREDER_RSVD0_MASK                          (0xFFFFFFFFFFFFFFFEU)
#define CSL_DMC_L1DNCOREDER_RSVD0_SHIFT                         (1U)
#define CSL_DMC_L1DNCOREDER_RSVD0_RESETVAL                      (0x00000000U)

#define CSL_DMC_L1DNCOREDER_ERROR_RESET_MASK                    (0x00000001U)
#define CSL_DMC_L1DNCOREDER_ERROR_RESET_SHIFT                   (0U)
#define CSL_DMC_L1DNCOREDER_ERROR_RESET_RESETVAL                (0x00000000U)
#define CSL_DMC_L1DNCOREDER_ERROR_RESET_MAX                     (0x00000001U)

#define CSL_DMC_L1DNCOREDER_RESETVAL                            (0x00000000U)

    /* L1DNCOREDEC */

#define CSL_DMC_L1DNCOREDEC_RSVD0_MASK                          (0xFFFFFFFF00000000U)
#define CSL_DMC_L1DNCOREDEC_RSVD0_SHIFT                         (32U)
#define CSL_DMC_L1DNCOREDEC_RSVD0_RESETVAL                      (0x00000000U)
#define CSL_DMC_L1DNCOREDEC_RSVD0_MAX                           (0xFFFFFFFFU)

#define CSL_DMC_L1DNCOREDEC_ERROR_COUNT_MASK                    (0xFFFFFFFFU)
#define CSL_DMC_L1DNCOREDEC_ERROR_COUNT_SHIFT                   (0U)
#define CSL_DMC_L1DNCOREDEC_ERROR_COUNT_RESETVAL                (0x00000000U)
#define CSL_DMC_L1DNCOREDEC_ERROR_COUNT_MAX                     (0xFFFFFFFFU)

#define CSL_DMC_L1DNCOREDEC_RESETVAL                            (0x00000000U)

    /* L1DADDREEA */

#define CSL_DMC_L1DADDREEA_RSVD0_MASK                           (0xFFFFF00000000000U)
#define CSL_DMC_L1DADDREEA_RSVD0_SHIFT                          (44U)
#define CSL_DMC_L1DADDREEA_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_DMC_L1DADDREEA_RSVD0_MAX                            (0x000fffffU)

#define CSL_DMC_L1DADDREEA_EADDR_MASK                           (0xFFFFFFFFFFFU)
#define CSL_DMC_L1DADDREEA_EADDR_SHIFT                          (0U)
#define CSL_DMC_L1DADDREEA_EADDR_RESETVAL                       (0x00000000U)

#define CSL_DMC_L1DADDREEA_RESETVAL                             (0x00000000U)

    /* L1DADDREES */

#define CSL_DMC_L1DADDREES_RSVD0_MASK                           (0xFFFFFFFFFFFFFE00U)
#define CSL_DMC_L1DADDREES_RSVD0_SHIFT                          (9U)
#define CSL_DMC_L1DADDREES_RSVD0_RESETVAL                       (0x00000000U)

#define CSL_DMC_L1DADDREES_RQSTR_MASK                           (0x00000180U)
#define CSL_DMC_L1DADDREES_RQSTR_SHIFT                          (7U)
#define CSL_DMC_L1DADDREES_RQSTR_RESETVAL                       (0x00000000U)
#define CSL_DMC_L1DADDREES_RQSTR_MAX                            (0x00000003U)

#define CSL_DMC_L1DADDREES_ERROR_TYPE_MASK                      (0x00000060U)
#define CSL_DMC_L1DADDREES_ERROR_TYPE_SHIFT                     (5U)
#define CSL_DMC_L1DADDREES_ERROR_TYPE_RESETVAL                  (0x00000000U)
#define CSL_DMC_L1DADDREES_ERROR_TYPE_MAX                       (0x00000003U)

#define CSL_DMC_L1DADDREES_BANK_MASK                            (0x0000001EU)
#define CSL_DMC_L1DADDREES_BANK_SHIFT                           (1U)
#define CSL_DMC_L1DADDREES_BANK_RESETVAL                        (0x00000000U)
#define CSL_DMC_L1DADDREES_BANK_MAX                             (0x0000000fU)

#define CSL_DMC_L1DADDREES_ERROR_FLAG_MASK                      (0x00000001U)
#define CSL_DMC_L1DADDREES_ERROR_FLAG_SHIFT                     (0U)
#define CSL_DMC_L1DADDREES_ERROR_FLAG_RESETVAL                  (0x00000000U)
#define CSL_DMC_L1DADDREES_ERROR_FLAG_MAX                       (0x00000001U)

#define CSL_DMC_L1DADDREES_RESETVAL                             (0x00000000U)

    /* L1DADDREER */

#define CSL_DMC_L1DADDREER_RSVD0_MASK                           (0xFFFFFFFFFFFFFFFEU)
#define CSL_DMC_L1DADDREER_RSVD0_SHIFT                          (1U)
#define CSL_DMC_L1DADDREER_RSVD0_RESETVAL                       (0x00000000U)

#define CSL_DMC_L1DADDREER_ERROR_RESET_MASK                     (0x00000001U)
#define CSL_DMC_L1DADDREER_ERROR_RESET_SHIFT                    (0U)
#define CSL_DMC_L1DADDREER_ERROR_RESET_RESETVAL                 (0x00000000U)
#define CSL_DMC_L1DADDREER_ERROR_RESET_MAX                      (0x00000001U)

#define CSL_DMC_L1DADDREER_RESETVAL                             (0x00000000U)

    /* L1DCMDEEA */

#define CSL_DMC_L1DCMDEEA_RSVD0_MASK                            (0xFFFFF00000000000U)
#define CSL_DMC_L1DCMDEEA_RSVD0_SHIFT                           (44U)
#define CSL_DMC_L1DCMDEEA_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_DMC_L1DCMDEEA_RSVD0_MAX                             (0x000fffffU)

#define CSL_DMC_L1DCMDEEA_EADDR_MASK                            (0xFFFFFFFFFFFU)
#define CSL_DMC_L1DCMDEEA_EADDR_SHIFT                           (0U)
#define CSL_DMC_L1DCMDEEA_EADDR_RESETVAL                        (0x00000000U)

#define CSL_DMC_L1DCMDEEA_RESETVAL                              (0x00000000U)

    /* L1DCMDEES */

#define CSL_DMC_L1DCMDEES_RSVD0_MASK                            (0xFFFFFFFFFFFFFFFCU)
#define CSL_DMC_L1DCMDEES_RSVD0_SHIFT                           (2U)
#define CSL_DMC_L1DCMDEES_RSVD0_RESETVAL                        (0x00000000U)

#define CSL_DMC_L1DCMDEES_ERROR_TYPE_MASK                       (0x00000002U)
#define CSL_DMC_L1DCMDEES_ERROR_TYPE_SHIFT                      (1U)
#define CSL_DMC_L1DCMDEES_ERROR_TYPE_RESETVAL                   (0x00000000U)
#define CSL_DMC_L1DCMDEES_ERROR_TYPE_MAX                        (0x00000001U)

#define CSL_DMC_L1DCMDEES_ERROR_FLAG_MASK                       (0x00000001U)
#define CSL_DMC_L1DCMDEES_ERROR_FLAG_SHIFT                      (0U)
#define CSL_DMC_L1DCMDEES_ERROR_FLAG_RESETVAL                   (0x00000000U)
#define CSL_DMC_L1DCMDEES_ERROR_FLAG_MAX                        (0x00000001U)

#define CSL_DMC_L1DCMDEES_RESETVAL                              (0x00000000U)

    /* L1DCMDEER */

#define CSL_DMC_L1DCMDEER_RSVD0_MASK                            (0xFFFFFFFFFFFFFFFEU)
#define CSL_DMC_L1DCMDEER_RSVD0_SHIFT                           (1U)
#define CSL_DMC_L1DCMDEER_RSVD0_RESETVAL                        (0x00000000U)

#define CSL_DMC_L1DCMDEER_ERROR_RESET_MASK                      (0x00000001U)
#define CSL_DMC_L1DCMDEER_ERROR_RESET_SHIFT                     (0U)
#define CSL_DMC_L1DCMDEER_ERROR_RESET_RESETVAL                  (0x00000000U)
#define CSL_DMC_L1DCMDEER_ERROR_RESET_MAX                       (0x00000001U)

#define CSL_DMC_L1DCMDEER_RESETVAL                              (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
