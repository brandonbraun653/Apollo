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
#ifndef CSLR_PMC_H
#define CSLR_PMC_H

#ifdef __cplusplus
extern "C"
{
#endif

/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* L1PEDEA */

#define CSL_PMC_L1PEDEA_RSVD0_MASK                              (0xFFFE000000000000U)
#define CSL_PMC_L1PEDEA_RSVD0_SHIFT                             (49U)
#define CSL_PMC_L1PEDEA_RSVD0_RESETVAL                          (0x00000000U)
#define CSL_PMC_L1PEDEA_RSVD0_MAX                               (0x00007fffU)

#define CSL_PMC_L1PEDEA_EADDR_MASK                              (0x1FFFFFFFFFFFFU)
#define CSL_PMC_L1PEDEA_EADDR_SHIFT                             (0U)
#define CSL_PMC_L1PEDEA_EADDR_RESETVAL                          (0x00000000U)

#define CSL_PMC_L1PEDEA_RESETVAL                                (0x00000000U)

/* L1PEDES */

#define CSL_PMC_L1PEDES_RSVD0_MASK                              (0xFFFFFFFFFFFFFFF8U)
#define CSL_PMC_L1PEDES_RSVD0_SHIFT                             (3U)
#define CSL_PMC_L1PEDES_RSVD0_RESETVAL                          (0x00000000U)

#define CSL_PMC_L1PEDES_WAY_MASK                                (0x00000006U)
#define CSL_PMC_L1PEDES_WAY_SHIFT                               (1U)
#define CSL_PMC_L1PEDES_WAY_RESETVAL                            (0x00000000U)
#define CSL_PMC_L1PEDES_WAY_MAX                                 (0x00000003U)

#define CSL_PMC_L1PEDES_ERROR_FLAG_MASK                         (0x00000001U)
#define CSL_PMC_L1PEDES_ERROR_FLAG_SHIFT                        (0U)
#define CSL_PMC_L1PEDES_ERROR_FLAG_RESETVAL                     (0x00000000U)
#define CSL_PMC_L1PEDES_ERROR_FLAG_MAX                          (0x00000001U)

#define CSL_PMC_L1PEDES_RESETVAL                                (0x00000000U)

/* L1PEDER */

#define CSL_PMC_L1PEDER_RSVD0_MASK                              (0xFFFFFFFFFFFFFFFEU)
#define CSL_PMC_L1PEDER_RSVD0_SHIFT                             (1U)
#define CSL_PMC_L1PEDER_RSVD0_RESETVAL                          (0x00000000U)

#define CSL_PMC_L1PEDER_ERROR_RESET_MASK                        (0x00000001U)
#define CSL_PMC_L1PEDER_ERROR_RESET_SHIFT                       (0U)
#define CSL_PMC_L1PEDER_ERROR_RESET_RESETVAL                    (0x00000000U)
#define CSL_PMC_L1PEDER_ERROR_RESET_MAX                         (0x00000001U)

#define CSL_PMC_L1PEDER_RESETVAL                                (0x00000000U)

/* L1PEDEC */

#define CSL_PMC_L1PEDEC_RSVD0_MASK                              (0xFFFFFFFF00000000U)
#define CSL_PMC_L1PEDEC_RSVD0_SHIFT                             (32U)
#define CSL_PMC_L1PEDEC_RSVD0_RESETVAL                          (0x00000000U)
#define CSL_PMC_L1PEDEC_RSVD0_MAX                               (0xFFFFFFFFU)

#define CSL_PMC_L1PEDEC_ERROR_COUNT_MASK                        (0xFFFFFFFFU)
#define CSL_PMC_L1PEDEC_ERROR_COUNT_SHIFT                       (0U)
#define CSL_PMC_L1PEDEC_ERROR_COUNT_RESETVAL                    (0x00000000U)
#define CSL_PMC_L1PEDEC_ERROR_COUNT_MAX                         (0xFFFFFFFFU)

#define CSL_PMC_L1PEDEC_RESETVAL                                (0x00000000U)

/* L1PCTAG */

#define CSL_PMC_L1PCTAG_RSVD0_MASK                              (0xFFFFFF8000000000U)
#define CSL_PMC_L1PCTAG_RSVD0_SHIFT                             (39U)
#define CSL_PMC_L1PCTAG_RSVD0_RESETVAL                          (0x00000000U)
#define CSL_PMC_L1PCTAG_RSVD0_MAX                               (0x01ffffffU)

#define CSL_PMC_L1PCTAG_VALID_MASK                              (0x4000000000U)
#define CSL_PMC_L1PCTAG_VALID_SHIFT                             (38U)
#define CSL_PMC_L1PCTAG_VALID_RESETVAL                          (0x00000000U)
#define CSL_PMC_L1PCTAG_VALID_MAX                               (0x00000001U)

#define CSL_PMC_L1PCTAG_SECURE_MASK                             (0x2000000000U)
#define CSL_PMC_L1PCTAG_SECURE_SHIFT                            (37U)
#define CSL_PMC_L1PCTAG_SECURE_RESETVAL                         (0x00000000U)
#define CSL_PMC_L1PCTAG_SECURE_MAX                              (0x00000001U)

#define CSL_PMC_L1PCTAG_ROOT_MASK                               (0x1000000000U)
#define CSL_PMC_L1PCTAG_ROOT_SHIFT                              (36U)
#define CSL_PMC_L1PCTAG_ROOT_RESETVAL                           (0x00000000U)
#define CSL_PMC_L1PCTAG_ROOT_MAX                                (0x00000001U)

#define CSL_PMC_L1PCTAG_TAG_MASK                                (0xFFFFFFFFFU)
#define CSL_PMC_L1PCTAG_TAG_SHIFT                               (0U)
#define CSL_PMC_L1PCTAG_TAG_RESETVAL                            (0x00000000U)

#define CSL_PMC_L1PCTAG_RESETVAL                                (0x00000000U)

/* L1PINV */

#define CSL_PMC_L1PINV_RSVD0_MASK                               (0xFFFFFFFFFFFFFFFEU)
#define CSL_PMC_L1PINV_RSVD0_SHIFT                              (1U)
#define CSL_PMC_L1PINV_RSVD0_RESETVAL                           (0x00000000U)

#define CSL_PMC_L1PINV_INV_MASK                                 (0x00000001U)
#define CSL_PMC_L1PINV_INV_SHIFT                                (0U)
#define CSL_PMC_L1PINV_INV_RESETVAL                             (0x00000000U)
#define CSL_PMC_L1PINV_INV_MAX                                  (0x00000001U)

#define CSL_PMC_L1PINV_RESETVAL                                 (0x00000000U)

/* L1PUINV */

#define CSL_PMC_L1PUINV_RSVD0_MASK                              (0xFFFFFFFFFFFFFFFEU)
#define CSL_PMC_L1PUINV_RSVD0_SHIFT                             (1U)
#define CSL_PMC_L1PUINV_RSVD0_RESETVAL                          (0x00000000U)

#define CSL_PMC_L1PUINV_INV_MASK                                (0x00000001U)
#define CSL_PMC_L1PUINV_INV_SHIFT                               (0U)
#define CSL_PMC_L1PUINV_INV_RESETVAL                            (0x00000000U)
#define CSL_PMC_L1PUINV_INV_MAX                                 (0x00000001U)

#define CSL_PMC_L1PUINV_RESETVAL                                (0x00000000U)

/* L1PSINV */

#define CSL_PMC_L1PSINV_RSVD0_MASK                              (0xFFFFFFFFFFFFFFFEU)
#define CSL_PMC_L1PSINV_RSVD0_SHIFT                             (1U)
#define CSL_PMC_L1PSINV_RSVD0_RESETVAL                          (0x00000000U)

#define CSL_PMC_L1PSINV_INV_MASK                                (0x00000001U)
#define CSL_PMC_L1PSINV_INV_SHIFT                               (0U)
#define CSL_PMC_L1PSINV_INV_RESETVAL                            (0x00000000U)
#define CSL_PMC_L1PSINV_INV_MAX                                 (0x00000001U)

#define CSL_PMC_L1PSINV_RESETVAL                                (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
