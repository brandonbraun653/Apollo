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
#ifndef CSLR_UMC_H
#define CSLR_UMC_H

#ifdef __cplusplus
extern "C"
{
#endif

/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* L2CFG */

#define CSL_UMC_L2CFG_RSVD0_MASK                                (0xFFFFFFFFFFFFFFF0ULL)
#define CSL_UMC_L2CFG_RSVD0_SHIFT                               (4ULL)
#define CSL_UMC_L2CFG_RSVD0_RESETVAL                            (0x00000000ULL)

#define CSL_UMC_L2CFG_NOINIT_MASK                               (0x00000008ULL)
#define CSL_UMC_L2CFG_NOINIT_SHIFT                              (3ULL)
#define CSL_UMC_L2CFG_NOINIT_RESETVAL                           (0x00000000ULL)
#define CSL_UMC_L2CFG_NOINIT_MAX                                (0x00000001ULL)

#define CSL_UMC_L2CFG_L2MODE_MASK                               (0x00000007ULL)
#define CSL_UMC_L2CFG_L2MODE_SHIFT                              (0ULL)
#define CSL_UMC_L2CFG_L2MODE_RESETVAL                           (0x00000000ULL)
#define CSL_UMC_L2CFG_L2MODE_MAX                                (0x00000007ULL)

#define CSL_UMC_L2CFG_RESETVAL                                  (0x00000000ULL)

/* L2CC */

#define CSL_UMC_L2CC_RSVD0_MASK                                 (0xFFFFFFFFFFFFFFF8ULL)
#define CSL_UMC_L2CC_RSVD0_SHIFT                                (3ULL)
#define CSL_UMC_L2CC_RSVD0_RESETVAL                             (0x00000000ULL)

#define CSL_UMC_L2CC_POPER_MASK                                 (0x00000004ULL)
#define CSL_UMC_L2CC_POPER_SHIFT                                (2ULL)
#define CSL_UMC_L2CC_POPER_RESETVAL                             (0x00000000ULL)
#define CSL_UMC_L2CC_POPER_MAX                                  (0x00000001ULL)

#define CSL_UMC_L2CC_RSVD1_MASK                                 (0x00000002ULL)
#define CSL_UMC_L2CC_RSVD1_SHIFT                                (1ULL)
#define CSL_UMC_L2CC_RSVD1_RESETVAL                             (0x00000000ULL)
#define CSL_UMC_L2CC_RSVD1_MAX                                  (0x00000001ULL)

#define CSL_UMC_L2CC_OPER_MASK                                  (0x00000001ULL)
#define CSL_UMC_L2CC_OPER_SHIFT                                 (0ULL)
#define CSL_UMC_L2CC_OPER_RESETVAL                              (0x00000000ULL)
#define CSL_UMC_L2CC_OPER_MAX                                   (0x00000001ULL)

#define CSL_UMC_L2CC_RESETVAL                                   (0x00000000ULL)

/* L2WB */

#define CSL_UMC_L2WB_RSVD0_MASK                                 (0xFFFFFFFFFFFFFFFEULL)
#define CSL_UMC_L2WB_RSVD0_SHIFT                                (1ULL)
#define CSL_UMC_L2WB_RSVD0_RESETVAL                             (0x00000000ULL)

#define CSL_UMC_L2WB_WB_MASK                                    (0x00000001ULL)
#define CSL_UMC_L2WB_WB_SHIFT                                   (0ULL)
#define CSL_UMC_L2WB_WB_RESETVAL                                (0x00000000ULL)
#define CSL_UMC_L2WB_WB_MAX                                     (0x00000001ULL)

#define CSL_UMC_L2WB_RESETVAL                                   (0x00000000ULL)

/* L2WBINV */

#define CSL_UMC_L2WBINV_RSVD0_MASK                              (0xFFFFFFFFFFFFFFFEULL)
#define CSL_UMC_L2WBINV_RSVD0_SHIFT                             (1ULL)
#define CSL_UMC_L2WBINV_RSVD0_RESETVAL                          (0x00000000ULL)

#define CSL_UMC_L2WBINV_WBINV_MASK                              (0x00000001ULL)
#define CSL_UMC_L2WBINV_WBINV_SHIFT                             (0ULL)
#define CSL_UMC_L2WBINV_WBINV_RESETVAL                          (0x00000000ULL)
#define CSL_UMC_L2WBINV_WBINV_MAX                               (0x00000001ULL)

#define CSL_UMC_L2WBINV_RESETVAL                                (0x00000000ULL)

/* L2INV */

#define CSL_UMC_L2INV_RSVD0_MASK                                (0xFFFFFFFFFFFFFFFEULL)
#define CSL_UMC_L2INV_RSVD0_SHIFT                               (1ULL)
#define CSL_UMC_L2INV_RSVD0_RESETVAL                            (0x00000000ULL)

#define CSL_UMC_L2INV_INV_MASK                                  (0x00000001ULL)
#define CSL_UMC_L2INV_INV_SHIFT                                 (0ULL)
#define CSL_UMC_L2INV_INV_RESETVAL                              (0x00000000ULL)
#define CSL_UMC_L2INV_INV_MAX                                   (0x00000001ULL)

#define CSL_UMC_L2INV_RESETVAL                                  (0x00000000ULL)

/* L2EMUCMD */

#define CSL_UMC_L2EMUCMD_RSVD0_MASK                             (0xFFFFFFFFFFFFFFFCULL)
#define CSL_UMC_L2EMUCMD_RSVD0_SHIFT                            (2ULL)
#define CSL_UMC_L2EMUCMD_RSVD0_RESETVAL                         (0x00000000ULL)

#define CSL_UMC_L2EMUCMD_TAGMOD_MASK                            (0x00000002ULL)
#define CSL_UMC_L2EMUCMD_TAGMOD_SHIFT                           (1ULL)
#define CSL_UMC_L2EMUCMD_TAGMOD_RESETVAL                        (0x00000000ULL)
#define CSL_UMC_L2EMUCMD_TAGMOD_MAX                             (0x00000001ULL)

#define CSL_UMC_L2EMUCMD_FRZ_MASK                               (0x00000001ULL)
#define CSL_UMC_L2EMUCMD_FRZ_SHIFT                              (0ULL)
#define CSL_UMC_L2EMUCMD_FRZ_RESETVAL                           (0x00000000ULL)
#define CSL_UMC_L2EMUCMD_FRZ_MAX                                (0x00000001ULL)

#define CSL_UMC_L2EMUCMD_RESETVAL                               (0x00000000ULL)

/* L2CTAG */

#define CSL_UMC_L2CTAG_RSVD0_MASK                               (0xFFFFFFFC00000000ULL)
#define CSL_UMC_L2CTAG_RSVD0_SHIFT                              (34ULL)
#define CSL_UMC_L2CTAG_RSVD0_RESETVAL                           (0x00000000ULL)
#define CSL_UMC_L2CTAG_RSVD0_MAX                                (0x3fffffffULL)

#define CSL_UMC_L2CTAG_MESI_MASK                                (0x300000000ULL)
#define CSL_UMC_L2CTAG_MESI_SHIFT                               (32ULL)
#define CSL_UMC_L2CTAG_MESI_RESETVAL                            (0x00000000ULL)
#define CSL_UMC_L2CTAG_MESI_MAX                                 (0x00000003ULL)

#define CSL_UMC_L2CTAG_TAG_MASK                                 (0xFFFFFFFFULL)
#define CSL_UMC_L2CTAG_TAG_SHIFT                                (0ULL)
#define CSL_UMC_L2CTAG_TAG_RESETVAL                             (0x00000000ULL)
#define CSL_UMC_L2CTAG_TAG_MAX                                  (0xFFFFFFFFULL)

#define CSL_UMC_L2CTAG_RESETVAL                                 (0x00000000ULL)

/* L2EDCFG */

#define CSL_UMC_L2EDCFG_RSVD0_MASK                              (0xFFFFFFFFFFFFFFF8ULL)
#define CSL_UMC_L2EDCFG_RSVD0_SHIFT                             (3ULL)
#define CSL_UMC_L2EDCFG_RSVD0_RESETVAL                          (0x00000000ULL)

#define CSL_UMC_L2EDCFG_ENABLE_MASK                             (0x00000004ULL)
#define CSL_UMC_L2EDCFG_ENABLE_SHIFT                            (2ULL)
#define CSL_UMC_L2EDCFG_ENABLE_RESETVAL                         (0x00000000ULL)
#define CSL_UMC_L2EDCFG_ENABLE_MAX                              (0x00000001ULL)

#define CSL_UMC_L2EDCFG_SUSP_MASK                               (0x00000002ULL)
#define CSL_UMC_L2EDCFG_SUSP_SHIFT                              (1ULL)
#define CSL_UMC_L2EDCFG_SUSP_RESETVAL                           (0x00000000ULL)
#define CSL_UMC_L2EDCFG_SUSP_MAX                                (0x00000001ULL)

#define CSL_UMC_L2EDCFG_SCEN_MASK                               (0x00000001ULL)
#define CSL_UMC_L2EDCFG_SCEN_SHIFT                              (0ULL)
#define CSL_UMC_L2EDCFG_SCEN_RESETVAL                           (0x00000000ULL)
#define CSL_UMC_L2EDCFG_SCEN_MAX                                (0x00000001ULL)

#define CSL_UMC_L2EDCFG_RESETVAL                                (0x00000000ULL)

/* L2EDSTAT */

#define CSL_UMC_L2EDSTAT_RSVD0_MASK                             (0xFFFFFFFFFFFFFFF8ULL)
#define CSL_UMC_L2EDSTAT_RSVD0_SHIFT                            (3ULL)
#define CSL_UMC_L2EDSTAT_RSVD0_RESETVAL                         (0x00000000ULL)

#define CSL_UMC_L2EDSTAT_ENABLE_MASK                            (0x00000004ULL)
#define CSL_UMC_L2EDSTAT_ENABLE_SHIFT                           (2ULL)
#define CSL_UMC_L2EDSTAT_ENABLE_RESETVAL                        (0x00000000ULL)
#define CSL_UMC_L2EDSTAT_ENABLE_MAX                             (0x00000001ULL)

#define CSL_UMC_L2EDSTAT_SUSP_MASK                              (0x00000002ULL)
#define CSL_UMC_L2EDSTAT_SUSP_SHIFT                             (1ULL)
#define CSL_UMC_L2EDSTAT_SUSP_RESETVAL                          (0x00000000ULL)
#define CSL_UMC_L2EDSTAT_SUSP_MAX                               (0x00000001ULL)

#define CSL_UMC_L2EDSTAT_SCEN_MASK                              (0x00000001ULL)
#define CSL_UMC_L2EDSTAT_SCEN_SHIFT                             (0ULL)
#define CSL_UMC_L2EDSTAT_SCEN_RESETVAL                          (0x00000000ULL)
#define CSL_UMC_L2EDSTAT_SCEN_MAX                               (0x00000001ULL)

#define CSL_UMC_L2EDSTAT_RESETVAL                               (0x00000000ULL)

/* L2COREDEA */

#define CSL_UMC_L2COREDEA_RSVD0_MASK                            (0xFFFFF00000000000ULL)
#define CSL_UMC_L2COREDEA_RSVD0_SHIFT                           (44ULL)
#define CSL_UMC_L2COREDEA_RSVD0_RESETVAL                        (0x00000000ULL)
#define CSL_UMC_L2COREDEA_RSVD0_MAX                             (0x000fffffULL)

#define CSL_UMC_L2COREDEA_EADDR_MASK                            (0xFFFFFFFFFFFULL)
#define CSL_UMC_L2COREDEA_EADDR_SHIFT                           (0ULL)
#define CSL_UMC_L2COREDEA_EADDR_RESETVAL                        (0x00000000ULL)

#define CSL_UMC_L2COREDEA_RESETVAL                              (0x00000000ULL)

/* L2COREDES */

#define CSL_UMC_L2COREDES_RSVD0_MASK                            (0xFFFFFFFFFFFF8000ULL)
#define CSL_UMC_L2COREDES_RSVD0_SHIFT                           (15ULL)
#define CSL_UMC_L2COREDES_RSVD0_RESETVAL                        (0x00000000ULL)

#define CSL_UMC_L2COREDES_BITPOS_MASK                           (0x00007F80ULL)
#define CSL_UMC_L2COREDES_BITPOS_SHIFT                          (7ULL)
#define CSL_UMC_L2COREDES_BITPOS_RESETVAL                       (0x00000000ULL)
#define CSL_UMC_L2COREDES_BITPOS_MAX                            (0x000000ffULL)

#define CSL_UMC_L2COREDES_RQSTR_MASK                            (0x00000060ULL)
#define CSL_UMC_L2COREDES_RQSTR_SHIFT                           (5ULL)
#define CSL_UMC_L2COREDES_RQSTR_RESETVAL                        (0x00000000ULL)
#define CSL_UMC_L2COREDES_RQSTR_MAX                             (0x00000003ULL)

#define CSL_UMC_L2COREDES_MEME_MASK                             (0x00000018ULL)
#define CSL_UMC_L2COREDES_MEME_SHIFT                            (3ULL)
#define CSL_UMC_L2COREDES_MEME_RESETVAL                         (0x00000000ULL)
#define CSL_UMC_L2COREDES_MEME_MAX                              (0x00000003ULL)

#define CSL_UMC_L2COREDES_BANK_MASK                             (0x00000006ULL)
#define CSL_UMC_L2COREDES_BANK_SHIFT                            (1ULL)
#define CSL_UMC_L2COREDES_BANK_RESETVAL                         (0x00000000ULL)
#define CSL_UMC_L2COREDES_BANK_MAX                              (0x00000003ULL)

#define CSL_UMC_L2COREDES_ERROR_FLAG_MASK                       (0x00000001ULL)
#define CSL_UMC_L2COREDES_ERROR_FLAG_SHIFT                      (0ULL)
#define CSL_UMC_L2COREDES_ERROR_FLAG_RESETVAL                   (0x00000000ULL)
#define CSL_UMC_L2COREDES_ERROR_FLAG_MAX                        (0x00000001ULL)

#define CSL_UMC_L2COREDES_RESETVAL                              (0x00000000ULL)

/* L2COREDER */

#define CSL_UMC_L2COREDER_RSVD0_MASK                            (0xFFFFFFFFFFFFFFFEULL)
#define CSL_UMC_L2COREDER_RSVD0_SHIFT                           (1ULL)
#define CSL_UMC_L2COREDER_RSVD0_RESETVAL                        (0x00000000ULL)

#define CSL_UMC_L2COREDER_ERROR_RESET_MASK                      (0x00000001ULL)
#define CSL_UMC_L2COREDER_ERROR_RESET_SHIFT                     (0ULL)
#define CSL_UMC_L2COREDER_ERROR_RESET_RESETVAL                  (0x00000000ULL)
#define CSL_UMC_L2COREDER_ERROR_RESET_MAX                       (0x00000001ULL)

#define CSL_UMC_L2COREDER_RESETVAL                              (0x00000000ULL)

/* L2COREDEC */

#define CSL_UMC_L2COREDEC_RSVD0_MASK                            (0xFFFFFFFF00000000ULL)
#define CSL_UMC_L2COREDEC_RSVD0_SHIFT                           (32ULL)
#define CSL_UMC_L2COREDEC_RSVD0_RESETVAL                        (0x00000000ULL)
#define CSL_UMC_L2COREDEC_RSVD0_MAX                             (0xFFFFFFFFULL)

#define CSL_UMC_L2COREDEC_ERROR_COUNT_MASK                      (0xFFFFFFFFULL)
#define CSL_UMC_L2COREDEC_ERROR_COUNT_SHIFT                     (0ULL)
#define CSL_UMC_L2COREDEC_ERROR_COUNT_RESETVAL                  (0x00000000ULL)
#define CSL_UMC_L2COREDEC_ERROR_COUNT_MAX                       (0xFFFFFFFFULL)

#define CSL_UMC_L2COREDEC_RESETVAL                              (0x00000000ULL)

/* L2NCOREDEA */

#define CSL_UMC_L2NCOREDEA_RSVD0_MASK                           (0xFFFFF00000000000ULL)
#define CSL_UMC_L2NCOREDEA_RSVD0_SHIFT                          (44ULL)
#define CSL_UMC_L2NCOREDEA_RSVD0_RESETVAL                       (0x00000000ULL)
#define CSL_UMC_L2NCOREDEA_RSVD0_MAX                            (0x000fffffULL)

#define CSL_UMC_L2NCOREDEA_EADDR_MASK                           (0xFFFFFFFFFFFULL)
#define CSL_UMC_L2NCOREDEA_EADDR_SHIFT                          (0ULL)
#define CSL_UMC_L2NCOREDEA_EADDR_RESETVAL                       (0x00000000ULL)

#define CSL_UMC_L2NCOREDEA_RESETVAL                             (0x00000000ULL)

/* L2NCOREDES */

#define CSL_UMC_L2NCOREDES_RSVD0_MASK                           (0xFFFFFFFFFFFFFF80ULL)
#define CSL_UMC_L2NCOREDES_RSVD0_SHIFT                          (7ULL)
#define CSL_UMC_L2NCOREDES_RSVD0_RESETVAL                       (0x00000000ULL)

#define CSL_UMC_L2NCOREDES_RQSTR_MASK                           (0x00000060ULL)
#define CSL_UMC_L2NCOREDES_RQSTR_SHIFT                          (5ULL)
#define CSL_UMC_L2NCOREDES_RQSTR_RESETVAL                       (0x00000000ULL)
#define CSL_UMC_L2NCOREDES_RQSTR_MAX                            (0x00000003ULL)

#define CSL_UMC_L2NCOREDES_MEME_MASK                            (0x00000018ULL)
#define CSL_UMC_L2NCOREDES_MEME_SHIFT                           (3ULL)
#define CSL_UMC_L2NCOREDES_MEME_RESETVAL                        (0x00000000ULL)
#define CSL_UMC_L2NCOREDES_MEME_MAX                             (0x00000003ULL)

#define CSL_UMC_L2NCOREDES_BANK_MASK                            (0x00000006ULL)
#define CSL_UMC_L2NCOREDES_BANK_SHIFT                           (1ULL)
#define CSL_UMC_L2NCOREDES_BANK_RESETVAL                        (0x00000000ULL)
#define CSL_UMC_L2NCOREDES_BANK_MAX                             (0x00000003ULL)

#define CSL_UMC_L2NCOREDES_ERROR_FLAG_MASK                      (0x00000001ULL)
#define CSL_UMC_L2NCOREDES_ERROR_FLAG_SHIFT                     (0ULL)
#define CSL_UMC_L2NCOREDES_ERROR_FLAG_RESETVAL                  (0x00000000ULL)
#define CSL_UMC_L2NCOREDES_ERROR_FLAG_MAX                       (0x00000001ULL)

#define CSL_UMC_L2NCOREDES_RESETVAL                             (0x00000000ULL)

/* L2NCOREDER */

#define CSL_UMC_L2NCOREDER_RSVD0_MASK                           (0xFFFFFFFFFFFFFFFEULL)
#define CSL_UMC_L2NCOREDER_RSVD0_SHIFT                          (1ULL)
#define CSL_UMC_L2NCOREDER_RSVD0_RESETVAL                       (0x00000000ULL)

#define CSL_UMC_L2NCOREDER_ERROR_RESET_MASK                     (0x00000001ULL)
#define CSL_UMC_L2NCOREDER_ERROR_RESET_SHIFT                    (0ULL)
#define CSL_UMC_L2NCOREDER_ERROR_RESET_RESETVAL                 (0x00000000ULL)
#define CSL_UMC_L2NCOREDER_ERROR_RESET_MAX                      (0x00000001ULL)

#define CSL_UMC_L2NCOREDER_RESETVAL                             (0x00000000ULL)

/* L2NCOREDEC */

#define CSL_UMC_L2NCOREDEC_RSVD0_MASK                           (0xFFFFFFFF00000000ULL)
#define CSL_UMC_L2NCOREDEC_RSVD0_SHIFT                          (32ULL)
#define CSL_UMC_L2NCOREDEC_RSVD0_RESETVAL                       (0x00000000ULL)
#define CSL_UMC_L2NCOREDEC_RSVD0_MAX                            (0xFFFFFFFFULL)

#define CSL_UMC_L2NCOREDEC_ERROR_COUNT_MASK                     (0xFFFFFFFFULL)
#define CSL_UMC_L2NCOREDEC_ERROR_COUNT_SHIFT                    (0ULL)
#define CSL_UMC_L2NCOREDEC_ERROR_COUNT_RESETVAL                 (0x00000000ULL)
#define CSL_UMC_L2NCOREDEC_ERROR_COUNT_MAX                      (0xFFFFFFFFULL)

#define CSL_UMC_L2NCOREDEC_RESETVAL                             (0x00000000ULL)

/* L2ADDREEA */

#define CSL_UMC_L2ADDREEA_RSVD0_MASK                            (0xFFFFF00000000000ULL)
#define CSL_UMC_L2ADDREEA_RSVD0_SHIFT                           (44ULL)
#define CSL_UMC_L2ADDREEA_RSVD0_RESETVAL                        (0x00000000ULL)
#define CSL_UMC_L2ADDREEA_RSVD0_MAX                             (0x000fffffULL)

#define CSL_UMC_L2ADDREEA_EADDR_MASK                            (0xFFFFFFFFFFFULL)
#define CSL_UMC_L2ADDREEA_EADDR_SHIFT                           (0ULL)
#define CSL_UMC_L2ADDREEA_EADDR_RESETVAL                        (0x00000000ULL)

#define CSL_UMC_L2ADDREEA_RESETVAL                              (0x00000000ULL)

/* L2ADDREES */

#define CSL_UMC_L2ADDREES_RSVD0_MASK                            (0xFFFFFFFFFFFFFF80ULL)
#define CSL_UMC_L2ADDREES_RSVD0_SHIFT                           (7ULL)
#define CSL_UMC_L2ADDREES_RSVD0_RESETVAL                        (0x00000000ULL)

#define CSL_UMC_L2ADDREES_RQSTR_MASK                            (0x00000060ULL)
#define CSL_UMC_L2ADDREES_RQSTR_SHIFT                           (5ULL)
#define CSL_UMC_L2ADDREES_RQSTR_RESETVAL                        (0x00000000ULL)
#define CSL_UMC_L2ADDREES_RQSTR_MAX                             (0x00000003ULL)

#define CSL_UMC_L2ADDREES_ERROR_TYPE_MASK                       (0x00000018ULL)
#define CSL_UMC_L2ADDREES_ERROR_TYPE_SHIFT                      (3ULL)
#define CSL_UMC_L2ADDREES_ERROR_TYPE_RESETVAL                   (0x00000000ULL)
#define CSL_UMC_L2ADDREES_ERROR_TYPE_MAX                        (0x00000003ULL)

#define CSL_UMC_L2ADDREES_BANK_MASK                             (0x00000006ULL)
#define CSL_UMC_L2ADDREES_BANK_SHIFT                            (1ULL)
#define CSL_UMC_L2ADDREES_BANK_RESETVAL                         (0x00000000ULL)
#define CSL_UMC_L2ADDREES_BANK_MAX                              (0x00000003ULL)

#define CSL_UMC_L2ADDREES_ERROR_FLAG_MASK                       (0x00000001ULL)
#define CSL_UMC_L2ADDREES_ERROR_FLAG_SHIFT                      (0ULL)
#define CSL_UMC_L2ADDREES_ERROR_FLAG_RESETVAL                   (0x00000000ULL)
#define CSL_UMC_L2ADDREES_ERROR_FLAG_MAX                        (0x00000001ULL)

#define CSL_UMC_L2ADDREES_RESETVAL                              (0x00000000ULL)

/* L2ADDREER */

#define CSL_UMC_L2ADDREER_RSVD0_MASK                            (0xFFFFFFFFFFFFFFFEULL)
#define CSL_UMC_L2ADDREER_RSVD0_SHIFT                           (1ULL)
#define CSL_UMC_L2ADDREER_RSVD0_RESETVAL                        (0x00000000ULL)

#define CSL_UMC_L2ADDREER_ERROR_RESET_MASK                      (0x00000001ULL)
#define CSL_UMC_L2ADDREER_ERROR_RESET_SHIFT                     (0ULL)
#define CSL_UMC_L2ADDREER_ERROR_RESET_RESETVAL                  (0x00000000ULL)
#define CSL_UMC_L2ADDREER_ERROR_RESET_MAX                       (0x00000001ULL)

#define CSL_UMC_L2ADDREER_RESETVAL                              (0x00000000ULL)

/* L2ALLOCEEA */

#define CSL_UMC_L2ALLOCEEA_RSVD0_MASK                           (0xFFFFF00000000000ULL)
#define CSL_UMC_L2ALLOCEEA_RSVD0_SHIFT                          (44ULL)
#define CSL_UMC_L2ALLOCEEA_RSVD0_RESETVAL                       (0x00000000ULL)
#define CSL_UMC_L2ALLOCEEA_RSVD0_MAX                            (0x000fffffULL)

#define CSL_UMC_L2ALLOCEEA_EADDR_MASK                           (0xFFFFFFFFFFFULL)
#define CSL_UMC_L2ALLOCEEA_EADDR_SHIFT                          (0ULL)
#define CSL_UMC_L2ALLOCEEA_EADDR_RESETVAL                       (0x00000000ULL)

#define CSL_UMC_L2ALLOCEEA_RESETVAL                             (0x00000000ULL)

/* L2ALLOCEES */

#define CSL_UMC_L2ALLOCEES_RSVD0_MASK                           (0xFFFFFFFFFFFFFF80ULL)
#define CSL_UMC_L2ALLOCEES_RSVD0_SHIFT                          (7ULL)
#define CSL_UMC_L2ALLOCEES_RSVD0_RESETVAL                       (0x00000000ULL)

#define CSL_UMC_L2ALLOCEES_RQSTR_MASK                           (0x00000060ULL)
#define CSL_UMC_L2ALLOCEES_RQSTR_SHIFT                          (5ULL)
#define CSL_UMC_L2ALLOCEES_RQSTR_RESETVAL                       (0x00000000ULL)
#define CSL_UMC_L2ALLOCEES_RQSTR_MAX                            (0x00000003ULL)

#define CSL_UMC_L2ALLOCEES_ERROR_TYPE_MASK                      (0x00000018ULL)
#define CSL_UMC_L2ALLOCEES_ERROR_TYPE_SHIFT                     (3ULL)
#define CSL_UMC_L2ALLOCEES_ERROR_TYPE_RESETVAL                  (0x00000000ULL)
#define CSL_UMC_L2ALLOCEES_ERROR_TYPE_MAX                       (0x00000003ULL)

#define CSL_UMC_L2ALLOCEES_BANK_MASK                            (0x00000006ULL)
#define CSL_UMC_L2ALLOCEES_BANK_SHIFT                           (1ULL)
#define CSL_UMC_L2ALLOCEES_BANK_RESETVAL                        (0x00000000ULL)
#define CSL_UMC_L2ALLOCEES_BANK_MAX                             (0x00000003ULL)

#define CSL_UMC_L2ALLOCEES_ERROR_FLAG_MASK                      (0x00000001ULL)
#define CSL_UMC_L2ALLOCEES_ERROR_FLAG_SHIFT                     (0ULL)
#define CSL_UMC_L2ALLOCEES_ERROR_FLAG_RESETVAL                  (0x00000000ULL)
#define CSL_UMC_L2ALLOCEES_ERROR_FLAG_MAX                       (0x00000001ULL)

#define CSL_UMC_L2ALLOCEES_RESETVAL                             (0x00000000ULL)

/* L2ALLOCEER */

#define CSL_UMC_L2ALLOCEER_RSVD0_MASK                           (0xFFFFFFFFFFFFFFFEULL)
#define CSL_UMC_L2ALLOCEER_RSVD0_SHIFT                          (1ULL)
#define CSL_UMC_L2ALLOCEER_RSVD0_RESETVAL                       (0x00000000ULL)

#define CSL_UMC_L2ALLOCEER_ERROR_RESET_MASK                     (0x00000001ULL)
#define CSL_UMC_L2ALLOCEER_ERROR_RESET_SHIFT                    (0ULL)
#define CSL_UMC_L2ALLOCEER_ERROR_RESET_RESETVAL                 (0x00000000ULL)
#define CSL_UMC_L2ALLOCEER_ERROR_RESET_MAX                      (0x00000001ULL)

#define CSL_UMC_L2ALLOCEER_RESETVAL                             (0x00000000ULL)

#ifdef __cplusplus
}
#endif
#endif
