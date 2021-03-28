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
#ifndef CSLR_C7X_CPU_H
#define CSLR_C7X_CPU_H

#ifdef __cplusplus
extern "C"
{
#endif

/**************************************************************************
* Field Definition Macros
**************************************************************************/

    /* CPUID */

#define CSL_C7X_CPU_CPUID_RSVD0_MASK                            (0xFFFFFFFF00000000U)
#define CSL_C7X_CPU_CPUID_RSVD0_SHIFT                           (32U)
#define CSL_C7X_CPU_CPUID_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_CPUID_RSVD0_MAX                             (0xFFFFFFFFU)

#define CSL_C7X_CPU_CPUID_SCHEME_MASK                           (0xC0000000U)
#define CSL_C7X_CPU_CPUID_SCHEME_SHIFT                          (30U)
#define CSL_C7X_CPU_CPUID_SCHEME_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_CPUID_SCHEME_MAX                            (0x00000003U)

#define CSL_C7X_CPU_CPUID_BU_MASK                               (0x30000000U)
#define CSL_C7X_CPU_CPUID_BU_SHIFT                              (28U)
#define CSL_C7X_CPU_CPUID_BU_RESETVAL                           (0x00000000U)
#define CSL_C7X_CPU_CPUID_BU_MAX                                (0x00000003U)

#define CSL_C7X_CPU_CPUID_FUNC_MASK                             (0x0FFF0000U)
#define CSL_C7X_CPU_CPUID_FUNC_SHIFT                            (16U)
#define CSL_C7X_CPU_CPUID_FUNC_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_CPUID_FUNC_MAX                              (0x00000fffU)

#define CSL_C7X_CPU_CPUID_RTL_MASK                              (0x0000F800U)
#define CSL_C7X_CPU_CPUID_RTL_SHIFT                             (11U)
#define CSL_C7X_CPU_CPUID_RTL_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_CPUID_RTL_MAX                               (0x0000001fU)

#define CSL_C7X_CPU_CPUID_MAJOR_MASK                            (0x00000700U)
#define CSL_C7X_CPU_CPUID_MAJOR_SHIFT                           (8U)
#define CSL_C7X_CPU_CPUID_MAJOR_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_CPUID_MAJOR_MAX                             (0x00000007U)

#define CSL_C7X_CPU_CPUID_CUSTOM_MASK                           (0x000000C0U)
#define CSL_C7X_CPU_CPUID_CUSTOM_SHIFT                          (6U)
#define CSL_C7X_CPU_CPUID_CUSTOM_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_CPUID_CUSTOM_MAX                            (0x00000003U)

#define CSL_C7X_CPU_CPUID_MINOR_MASK                            (0x0000003FU)
#define CSL_C7X_CPU_CPUID_MINOR_SHIFT                           (0U)
#define CSL_C7X_CPU_CPUID_MINOR_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_CPUID_MINOR_MAX                             (0x0000003fU)

#define CSL_C7X_CPU_CPUID_RESETVAL                              (0x00000000U)

    /* PMR */

#define CSL_C7X_CPU_PMR_RSVD0_MASK                              (0xFFFFFFFFFFFFFFC0U)
#define CSL_C7X_CPU_PMR_RSVD0_SHIFT                             (6U)
#define CSL_C7X_CPU_PMR_RSVD0_RESETVAL                          (0x00000000U)

#define CSL_C7X_CPU_PMR_PWRD_MASK                               (0x0000003FU)
#define CSL_C7X_CPU_PMR_PWRD_SHIFT                              (0U)
#define CSL_C7X_CPU_PMR_PWRD_RESETVAL                           (0x00000000U)
#define CSL_C7X_CPU_PMR_PWRD_MAX                                (0x0000003fU)

#define CSL_C7X_CPU_PMR_RESETVAL                                (0x00000000U)

    /* DNUM */

#define CSL_C7X_CPU_DNUM_RSVD0_MASK                             (0xFFFFFFFFFF000000U)
#define CSL_C7X_CPU_DNUM_RSVD0_SHIFT                            (24U)
#define CSL_C7X_CPU_DNUM_RSVD0_RESETVAL                         (0x00000000U)

#define CSL_C7X_CPU_DNUM_CLUSTRNUM_MASK                         (0x00FF0000U)
#define CSL_C7X_CPU_DNUM_CLUSTRNUM_SHIFT                        (16U)
#define CSL_C7X_CPU_DNUM_CLUSTRNUM_RESETVAL                     (0x00000000U)
#define CSL_C7X_CPU_DNUM_CLUSTRNUM_MAX                          (0x000000ffU)

#define CSL_C7X_CPU_DNUM_COREPACNUM_MASK                        (0x0000FF00U)
#define CSL_C7X_CPU_DNUM_COREPACNUM_SHIFT                       (8U)
#define CSL_C7X_CPU_DNUM_COREPACNUM_RESETVAL                    (0x00000000U)
#define CSL_C7X_CPU_DNUM_COREPACNUM_MAX                         (0x000000ffU)

#define CSL_C7X_CPU_DNUM_CPUNUM_MASK                            (0x000000FFU)
#define CSL_C7X_CPU_DNUM_CPUNUM_SHIFT                           (0U)
#define CSL_C7X_CPU_DNUM_CPUNUM_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_DNUM_CPUNUM_MAX                             (0x000000ffU)

#define CSL_C7X_CPU_DNUM_RESETVAL                               (0x00000000U)

    /* TSC */

#define CSL_C7X_CPU_TSC_TSC_MASK                                (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_TSC_TSC_SHIFT                               (0U)
#define CSL_C7X_CPU_TSC_TSC_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_TSC_TSC_MAX                                 (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_TSC_RESETVAL                                (0x00000000U)

    /* TSR */

#define CSL_C7X_CPU_TSR_RSVD5_MASK                              (0xFE00000000000000U)
#define CSL_C7X_CPU_TSR_RSVD5_SHIFT                             (57U)
#define CSL_C7X_CPU_TSR_RSVD5_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD5_MAX                               (0x0000007fU)

#define CSL_C7X_CPU_TSR_EN_MASK                                 (0x100000000000000U)
#define CSL_C7X_CPU_TSR_EN_SHIFT                                (56U)
#define CSL_C7X_CPU_TSR_EN_RESETVAL                             (0x00000000U)
#define CSL_C7X_CPU_TSR_EN_MAX                                  (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD4_MASK                              (0xE0000000000000U)
#define CSL_C7X_CPU_TSR_RSVD4_SHIFT                             (53U)
#define CSL_C7X_CPU_TSR_RSVD4_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD4_MAX                               (0x00000007U)

#define CSL_C7X_CPU_TSR_VLX_MASK                                (0x1F000000000000U)
#define CSL_C7X_CPU_TSR_VLX_SHIFT                               (48U)
#define CSL_C7X_CPU_TSR_VLX_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_TSR_VLX_MAX                                 (0x0000001fU)

#define CSL_C7X_CPU_TSR_RSVD_SA7_MASK                           (0x800000000000U)
#define CSL_C7X_CPU_TSR_RSVD_SA7_SHIFT                          (47U)
#define CSL_C7X_CPU_TSR_RSVD_SA7_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD_SA7_MAX                            (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD_SA6_MASK                           (0x400000000000U)
#define CSL_C7X_CPU_TSR_RSVD_SA6_SHIFT                          (46U)
#define CSL_C7X_CPU_TSR_RSVD_SA6_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD_SA6_MAX                            (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD_SA5_MASK                           (0x200000000000U)
#define CSL_C7X_CPU_TSR_RSVD_SA5_SHIFT                          (45U)
#define CSL_C7X_CPU_TSR_RSVD_SA5_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD_SA5_MAX                            (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD_SA4_MASK                           (0x100000000000U)
#define CSL_C7X_CPU_TSR_RSVD_SA4_SHIFT                          (44U)
#define CSL_C7X_CPU_TSR_RSVD_SA4_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD_SA4_MAX                            (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD_SA3_MASK                           (0x80000000000U)
#define CSL_C7X_CPU_TSR_RSVD_SA3_SHIFT                          (43U)
#define CSL_C7X_CPU_TSR_RSVD_SA3_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD_SA3_MAX                            (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD_SA2_MASK                           (0x40000000000U)
#define CSL_C7X_CPU_TSR_RSVD_SA2_SHIFT                          (42U)
#define CSL_C7X_CPU_TSR_RSVD_SA2_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD_SA2_MAX                            (0x00000001U)

#define CSL_C7X_CPU_TSR_SA1_MASK                                (0x20000000000U)
#define CSL_C7X_CPU_TSR_SA1_SHIFT                               (41U)
#define CSL_C7X_CPU_TSR_SA1_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_TSR_SA1_MAX                                 (0x00000001U)

#define CSL_C7X_CPU_TSR_SA0_MASK                                (0x10000000000U)
#define CSL_C7X_CPU_TSR_SA0_SHIFT                               (40U)
#define CSL_C7X_CPU_TSR_SA0_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_TSR_SA0_MAX                                 (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD_SE7_MASK                           (0x8000000000U)
#define CSL_C7X_CPU_TSR_RSVD_SE7_SHIFT                          (39U)
#define CSL_C7X_CPU_TSR_RSVD_SE7_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD_SE7_MAX                            (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD_SE6_MASK                           (0x4000000000U)
#define CSL_C7X_CPU_TSR_RSVD_SE6_SHIFT                          (38U)
#define CSL_C7X_CPU_TSR_RSVD_SE6_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD_SE6_MAX                            (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD_SE5_MASK                           (0x2000000000U)
#define CSL_C7X_CPU_TSR_RSVD_SE5_SHIFT                          (37U)
#define CSL_C7X_CPU_TSR_RSVD_SE5_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD_SE5_MAX                            (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD_SE4_MASK                           (0x1000000000U)
#define CSL_C7X_CPU_TSR_RSVD_SE4_SHIFT                          (36U)
#define CSL_C7X_CPU_TSR_RSVD_SE4_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD_SE4_MAX                            (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD_SE3_MASK                           (0x800000000U)
#define CSL_C7X_CPU_TSR_RSVD_SE3_SHIFT                          (35U)
#define CSL_C7X_CPU_TSR_RSVD_SE3_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD_SE3_MAX                            (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD_SE2_MASK                           (0x400000000U)
#define CSL_C7X_CPU_TSR_RSVD_SE2_SHIFT                          (34U)
#define CSL_C7X_CPU_TSR_RSVD_SE2_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD_SE2_MAX                            (0x00000001U)

#define CSL_C7X_CPU_TSR_SE1_MASK                                (0x200000000U)
#define CSL_C7X_CPU_TSR_SE1_SHIFT                               (33U)
#define CSL_C7X_CPU_TSR_SE1_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_TSR_SE1_MAX                                 (0x00000001U)

#define CSL_C7X_CPU_TSR_SE0_MASK                                (0x100000000U)
#define CSL_C7X_CPU_TSR_SE0_SHIFT                               (32U)
#define CSL_C7X_CPU_TSR_SE0_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_TSR_SE0_MAX                                 (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD3_MASK                              (0xE0000000U)
#define CSL_C7X_CPU_TSR_RSVD3_SHIFT                             (29U)
#define CSL_C7X_CPU_TSR_RSVD3_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD3_MAX                               (0x00000007U)

#define CSL_C7X_CPU_TSR_DBGM_MASK                               (0x10000000U)
#define CSL_C7X_CPU_TSR_DBGM_SHIFT                              (28U)
#define CSL_C7X_CPU_TSR_DBGM_RESETVAL                           (0x00000000U)
#define CSL_C7X_CPU_TSR_DBGM_MAX                                (0x00000001U)

#define CSL_C7X_CPU_TSR_SUDEN_MASK                              (0x0C000000U)
#define CSL_C7X_CPU_TSR_SUDEN_SHIFT                             (26U)
#define CSL_C7X_CPU_TSR_SUDEN_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_TSR_SUDEN_MAX                               (0x00000003U)

#define CSL_C7X_CPU_TSR_GEE_MASK                                (0x02000000U)
#define CSL_C7X_CPU_TSR_GEE_SHIFT                               (25U)
#define CSL_C7X_CPU_TSR_GEE_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_TSR_GEE_MAX                                 (0x00000001U)

#define CSL_C7X_CPU_TSR_PROT_MASK                               (0x01000000U)
#define CSL_C7X_CPU_TSR_PROT_SHIFT                              (24U)
#define CSL_C7X_CPU_TSR_PROT_RESETVAL                           (0x00000000U)
#define CSL_C7X_CPU_TSR_PROT_MAX                                (0x00000001U)

#define CSL_C7X_CPU_TSR_RSVD2_MASK                              (0x00FE0000U)
#define CSL_C7X_CPU_TSR_RSVD2_SHIFT                             (17U)
#define CSL_C7X_CPU_TSR_RSVD2_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD2_MAX                               (0x0000007fU)

#define CSL_C7X_CPU_TSR_COP_MASK                                (0x0001FF00U)
#define CSL_C7X_CPU_TSR_COP_SHIFT                               (8U)
#define CSL_C7X_CPU_TSR_COP_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_TSR_COP_MAX                                 (0x000001ffU)

#define CSL_C7X_CPU_TSR_RSVD1_MASK                              (0x000000F0U)
#define CSL_C7X_CPU_TSR_RSVD1_SHIFT                             (4U)
#define CSL_C7X_CPU_TSR_RSVD1_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_TSR_RSVD1_MAX                               (0x0000000fU)

#define CSL_C7X_CPU_TSR_EVT_MASK                                (0x00000008U)
#define CSL_C7X_CPU_TSR_EVT_SHIFT                               (3U)
#define CSL_C7X_CPU_TSR_EVT_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_TSR_EVT_MAX                                 (0x00000001U)

#define CSL_C7X_CPU_TSR_CXM_MASK                                (0x00000007U)
#define CSL_C7X_CPU_TSR_CXM_SHIFT                               (0U)
#define CSL_C7X_CPU_TSR_CXM_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_TSR_CXM_MAX                                 (0x00000007U)

#define CSL_C7X_CPU_TSR_RESETVAL                                (0x00000000U)

    /* RP */

#define CSL_C7X_CPU_RP_RP_MASK                                  (0xFFFFFFFFFFFFFFFCU)
#define CSL_C7X_CPU_RP_RP_SHIFT                                 (2U)
#define CSL_C7X_CPU_RP_RP_RESETVAL                              (0x00000000U)

#define CSL_C7X_CPU_RP_RSV_MASK                                 (0x00000002U)
#define CSL_C7X_CPU_RP_RSV_SHIFT                                (1U)
#define CSL_C7X_CPU_RP_RSV_RESETVAL                             (0x00000000U)
#define CSL_C7X_CPU_RP_RSV_MAX                                  (0x00000001U)

#define CSL_C7X_CPU_RP_SYSCALL_MASK                             (0x00000001U)
#define CSL_C7X_CPU_RP_SYSCALL_SHIFT                            (0U)
#define CSL_C7X_CPU_RP_SYSCALL_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_RP_SYSCALL_MAX                              (0x00000001U)

#define CSL_C7X_CPU_RP_RESETVAL                                 (0x00000000U)

    /* BPCR */

#define CSL_C7X_CPU_BPCR_RSVD0_MASK                             (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_BPCR_RSVD0_SHIFT                            (1U)
#define CSL_C7X_CPU_BPCR_RSVD0_RESETVAL                         (0x00000000U)

#define CSL_C7X_CPU_BPCR_BPOFF_MASK                             (0x00000001U)
#define CSL_C7X_CPU_BPCR_BPOFF_SHIFT                            (0U)
#define CSL_C7X_CPU_BPCR_BPOFF_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_BPCR_BPOFF_MAX                              (0x00000001U)

#define CSL_C7X_CPU_BPCR_RESETVAL                               (0x00000000U)

    /* FPCR */

#define CSL_C7X_CPU_FPCR_RSVD0_MASK                             (0xFFFFFFFFFFFFFFE0U)
#define CSL_C7X_CPU_FPCR_RSVD0_SHIFT                            (5U)
#define CSL_C7X_CPU_FPCR_RSVD0_RESETVAL                         (0x00000000U)

#define CSL_C7X_CPU_FPCR_FTZ_MASK                               (0x00000010U)
#define CSL_C7X_CPU_FPCR_FTZ_SHIFT                              (4U)
#define CSL_C7X_CPU_FPCR_FTZ_RESETVAL                           (0x00000000U)
#define CSL_C7X_CPU_FPCR_FTZ_MAX                                (0x00000001U)

#define CSL_C7X_CPU_FPCR_RSVD_RMODE_MASK                        (0x0000000CU)
#define CSL_C7X_CPU_FPCR_RSVD_RMODE_SHIFT                       (2U)
#define CSL_C7X_CPU_FPCR_RSVD_RMODE_RESETVAL                    (0x00000000U)
#define CSL_C7X_CPU_FPCR_RSVD_RMODE_MAX                         (0x00000003U)

#define CSL_C7X_CPU_FPCR_RMODE_MASK                             (0x00000003U)
#define CSL_C7X_CPU_FPCR_RMODE_SHIFT                            (0U)
#define CSL_C7X_CPU_FPCR_RMODE_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_FPCR_RMODE_MAX                              (0x00000003U)

#define CSL_C7X_CPU_FPCR_RESETVAL                               (0x00000000U)

    /* FSR */

#define CSL_C7X_CPU_FSR_RSVD0_MASK                              (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_FSR_RSVD0_SHIFT                             (8U)
#define CSL_C7X_CPU_FSR_RSVD0_RESETVAL                          (0x00000000U)

#define CSL_C7X_CPU_FSR_SAT_MASK                                (0x00000080U)
#define CSL_C7X_CPU_FSR_SAT_SHIFT                               (7U)
#define CSL_C7X_CPU_FSR_SAT_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_FSR_SAT_MAX                                 (0x00000001U)

#define CSL_C7X_CPU_FSR_UNORD_MASK                              (0x00000040U)
#define CSL_C7X_CPU_FSR_UNORD_SHIFT                             (6U)
#define CSL_C7X_CPU_FSR_UNORD_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_FSR_UNORD_MAX                               (0x00000001U)

#define CSL_C7X_CPU_FSR_DEN_MASK                                (0x00000020U)
#define CSL_C7X_CPU_FSR_DEN_SHIFT                               (5U)
#define CSL_C7X_CPU_FSR_DEN_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_FSR_DEN_MAX                                 (0x00000001U)

#define CSL_C7X_CPU_FSR_INEX_MASK                               (0x00000010U)
#define CSL_C7X_CPU_FSR_INEX_SHIFT                              (4U)
#define CSL_C7X_CPU_FSR_INEX_RESETVAL                           (0x00000000U)
#define CSL_C7X_CPU_FSR_INEX_MAX                                (0x00000001U)

#define CSL_C7X_CPU_FSR_UNDER_MASK                              (0x00000008U)
#define CSL_C7X_CPU_FSR_UNDER_SHIFT                             (3U)
#define CSL_C7X_CPU_FSR_UNDER_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_FSR_UNDER_MAX                               (0x00000001U)

#define CSL_C7X_CPU_FSR_OVER_MASK                               (0x00000004U)
#define CSL_C7X_CPU_FSR_OVER_SHIFT                              (2U)
#define CSL_C7X_CPU_FSR_OVER_RESETVAL                           (0x00000000U)
#define CSL_C7X_CPU_FSR_OVER_MAX                                (0x00000001U)

#define CSL_C7X_CPU_FSR_DIV0_MASK                               (0x00000002U)
#define CSL_C7X_CPU_FSR_DIV0_SHIFT                              (1U)
#define CSL_C7X_CPU_FSR_DIV0_RESETVAL                           (0x00000000U)
#define CSL_C7X_CPU_FSR_DIV0_MAX                                (0x00000001U)

#define CSL_C7X_CPU_FSR_INVAL_MASK                              (0x00000001U)
#define CSL_C7X_CPU_FSR_INVAL_SHIFT                             (0U)
#define CSL_C7X_CPU_FSR_INVAL_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_FSR_INVAL_MAX                               (0x00000001U)

#define CSL_C7X_CPU_FSR_RESETVAL                                (0x00000000U)

    /* ECLMR0 */

#define CSL_C7X_CPU_ECLMR0_ECLMR_MASK                           (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_ECLMR0_ECLMR_SHIFT                          (0U)
#define CSL_C7X_CPU_ECLMR0_ECLMR_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_ECLMR0_ECLMR_MAX                            (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_ECLMR0_RESETVAL                             (0x00000000U)

    /* EASGR0 */

#define CSL_C7X_CPU_EASGR0_EASGR_MASK                           (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_EASGR0_EASGR_SHIFT                          (0U)
#define CSL_C7X_CPU_EASGR0_EASGR_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EASGR0_EASGR_MAX                            (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_EASGR0_RESETVAL                             (0x00000000U)

    /* EPRI0 */

#define CSL_C7X_CPU_EPRI0_RSVD1_MASK                            (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI0_RSVD1_SHIFT                           (8U)
#define CSL_C7X_CPU_EPRI0_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_EPRI0_EPRI_MASK                             (0x000000E0U)
#define CSL_C7X_CPU_EPRI0_EPRI_SHIFT                            (5U)
#define CSL_C7X_CPU_EPRI0_EPRI_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_EPRI0_EPRI_MAX                              (0x00000007U)

#define CSL_C7X_CPU_EPRI0_RSVD0_MASK                            (0x0000001FU)
#define CSL_C7X_CPU_EPRI0_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_EPRI0_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI0_RSVD0_MAX                             (0x0000001fU)

#define CSL_C7X_CPU_EPRI0_RESETVAL                              (0x00000000U)

    /* EPRI1 */

#define CSL_C7X_CPU_EPRI1_RSVD1_MASK                            (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI1_RSVD1_SHIFT                           (8U)
#define CSL_C7X_CPU_EPRI1_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_EPRI1_EPRI_MASK                             (0x000000E0U)
#define CSL_C7X_CPU_EPRI1_EPRI_SHIFT                            (5U)
#define CSL_C7X_CPU_EPRI1_EPRI_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_EPRI1_EPRI_MAX                              (0x00000007U)

#define CSL_C7X_CPU_EPRI1_RSVD0_MASK                            (0x0000001FU)
#define CSL_C7X_CPU_EPRI1_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_EPRI1_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI1_RSVD0_MAX                             (0x0000001fU)

#define CSL_C7X_CPU_EPRI1_RESETVAL                              (0x00000000U)

    /* EPRI2 */

#define CSL_C7X_CPU_EPRI2_RSVD1_MASK                            (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI2_RSVD1_SHIFT                           (8U)
#define CSL_C7X_CPU_EPRI2_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_EPRI2_EPRI_MASK                             (0x000000E0U)
#define CSL_C7X_CPU_EPRI2_EPRI_SHIFT                            (5U)
#define CSL_C7X_CPU_EPRI2_EPRI_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_EPRI2_EPRI_MAX                              (0x00000007U)

#define CSL_C7X_CPU_EPRI2_RSVD0_MASK                            (0x0000001FU)
#define CSL_C7X_CPU_EPRI2_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_EPRI2_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI2_RSVD0_MAX                             (0x0000001fU)

#define CSL_C7X_CPU_EPRI2_RESETVAL                              (0x00000000U)

    /* EPRI3 */

#define CSL_C7X_CPU_EPRI3_RSVD1_MASK                            (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI3_RSVD1_SHIFT                           (8U)
#define CSL_C7X_CPU_EPRI3_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_EPRI3_EPRI_MASK                             (0x000000E0U)
#define CSL_C7X_CPU_EPRI3_EPRI_SHIFT                            (5U)
#define CSL_C7X_CPU_EPRI3_EPRI_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_EPRI3_EPRI_MAX                              (0x00000007U)

#define CSL_C7X_CPU_EPRI3_RSVD0_MASK                            (0x0000001FU)
#define CSL_C7X_CPU_EPRI3_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_EPRI3_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI3_RSVD0_MAX                             (0x0000001fU)

#define CSL_C7X_CPU_EPRI3_RESETVAL                              (0x00000000U)

    /* EPRI4 */

#define CSL_C7X_CPU_EPRI4_RSVD1_MASK                            (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI4_RSVD1_SHIFT                           (8U)
#define CSL_C7X_CPU_EPRI4_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_EPRI4_EPRI_MASK                             (0x000000E0U)
#define CSL_C7X_CPU_EPRI4_EPRI_SHIFT                            (5U)
#define CSL_C7X_CPU_EPRI4_EPRI_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_EPRI4_EPRI_MAX                              (0x00000007U)

#define CSL_C7X_CPU_EPRI4_RSVD0_MASK                            (0x0000001FU)
#define CSL_C7X_CPU_EPRI4_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_EPRI4_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI4_RSVD0_MAX                             (0x0000001fU)

#define CSL_C7X_CPU_EPRI4_RESETVAL                              (0x00000000U)

    /* EPRI5 */

#define CSL_C7X_CPU_EPRI5_RSVD1_MASK                            (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI5_RSVD1_SHIFT                           (8U)
#define CSL_C7X_CPU_EPRI5_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_EPRI5_EPRI_MASK                             (0x000000E0U)
#define CSL_C7X_CPU_EPRI5_EPRI_SHIFT                            (5U)
#define CSL_C7X_CPU_EPRI5_EPRI_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_EPRI5_EPRI_MAX                              (0x00000007U)

#define CSL_C7X_CPU_EPRI5_RSVD0_MASK                            (0x0000001FU)
#define CSL_C7X_CPU_EPRI5_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_EPRI5_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI5_RSVD0_MAX                             (0x0000001fU)

#define CSL_C7X_CPU_EPRI5_RESETVAL                              (0x00000000U)

    /* EPRI6 */

#define CSL_C7X_CPU_EPRI6_RSVD1_MASK                            (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI6_RSVD1_SHIFT                           (8U)
#define CSL_C7X_CPU_EPRI6_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_EPRI6_EPRI_MASK                             (0x000000E0U)
#define CSL_C7X_CPU_EPRI6_EPRI_SHIFT                            (5U)
#define CSL_C7X_CPU_EPRI6_EPRI_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_EPRI6_EPRI_MAX                              (0x00000007U)

#define CSL_C7X_CPU_EPRI6_RSVD0_MASK                            (0x0000001FU)
#define CSL_C7X_CPU_EPRI6_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_EPRI6_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI6_RSVD0_MAX                             (0x0000001fU)

#define CSL_C7X_CPU_EPRI6_RESETVAL                              (0x00000000U)

    /* EPRI7 */

#define CSL_C7X_CPU_EPRI7_RSVD1_MASK                            (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI7_RSVD1_SHIFT                           (8U)
#define CSL_C7X_CPU_EPRI7_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_EPRI7_EPRI_MASK                             (0x000000E0U)
#define CSL_C7X_CPU_EPRI7_EPRI_SHIFT                            (5U)
#define CSL_C7X_CPU_EPRI7_EPRI_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_EPRI7_EPRI_MAX                              (0x00000007U)

#define CSL_C7X_CPU_EPRI7_RSVD0_MASK                            (0x0000001FU)
#define CSL_C7X_CPU_EPRI7_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_EPRI7_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI7_RSVD0_MAX                             (0x0000001fU)

#define CSL_C7X_CPU_EPRI7_RESETVAL                              (0x00000000U)

    /* EPRI8 */

#define CSL_C7X_CPU_EPRI8_RSVD1_MASK                            (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI8_RSVD1_SHIFT                           (8U)
#define CSL_C7X_CPU_EPRI8_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_EPRI8_EPRI_MASK                             (0x000000E0U)
#define CSL_C7X_CPU_EPRI8_EPRI_SHIFT                            (5U)
#define CSL_C7X_CPU_EPRI8_EPRI_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_EPRI8_EPRI_MAX                              (0x00000007U)

#define CSL_C7X_CPU_EPRI8_RSVD0_MASK                            (0x0000001FU)
#define CSL_C7X_CPU_EPRI8_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_EPRI8_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI8_RSVD0_MAX                             (0x0000001fU)

#define CSL_C7X_CPU_EPRI8_RESETVAL                              (0x00000000U)

    /* EPRI9 */

#define CSL_C7X_CPU_EPRI9_RSVD1_MASK                            (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI9_RSVD1_SHIFT                           (8U)
#define CSL_C7X_CPU_EPRI9_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_EPRI9_EPRI_MASK                             (0x000000E0U)
#define CSL_C7X_CPU_EPRI9_EPRI_SHIFT                            (5U)
#define CSL_C7X_CPU_EPRI9_EPRI_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_EPRI9_EPRI_MAX                              (0x00000007U)

#define CSL_C7X_CPU_EPRI9_RSVD0_MASK                            (0x0000001FU)
#define CSL_C7X_CPU_EPRI9_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_EPRI9_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI9_RSVD0_MAX                             (0x0000001fU)

#define CSL_C7X_CPU_EPRI9_RESETVAL                              (0x00000000U)

    /* EPRI10 */

#define CSL_C7X_CPU_EPRI10_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI10_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI10_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI10_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI10_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI10_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI10_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI10_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI10_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI10_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI10_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI10_RESETVAL                             (0x00000000U)

    /* EPRI11 */

#define CSL_C7X_CPU_EPRI11_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI11_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI11_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI11_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI11_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI11_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI11_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI11_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI11_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI11_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI11_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI11_RESETVAL                             (0x00000000U)

    /* EPRI12 */

#define CSL_C7X_CPU_EPRI12_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI12_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI12_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI12_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI12_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI12_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI12_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI12_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI12_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI12_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI12_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI12_RESETVAL                             (0x00000000U)

    /* EPRI13 */

#define CSL_C7X_CPU_EPRI13_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI13_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI13_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI13_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI13_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI13_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI13_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI13_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI13_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI13_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI13_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI13_RESETVAL                             (0x00000000U)

    /* EPRI14 */

#define CSL_C7X_CPU_EPRI14_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI14_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI14_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI14_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI14_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI14_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI14_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI14_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI14_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI14_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI14_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI14_RESETVAL                             (0x00000000U)

    /* EPRI15 */

#define CSL_C7X_CPU_EPRI15_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI15_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI15_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI15_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI15_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI15_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI15_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI15_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI15_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI15_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI15_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI15_RESETVAL                             (0x00000000U)

    /* EPRI16 */

#define CSL_C7X_CPU_EPRI16_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI16_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI16_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI16_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI16_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI16_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI16_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI16_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI16_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI16_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI16_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI16_RESETVAL                             (0x00000000U)

    /* EPRI17 */

#define CSL_C7X_CPU_EPRI17_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI17_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI17_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI17_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI17_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI17_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI17_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI17_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI17_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI17_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI17_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI17_RESETVAL                             (0x00000000U)

    /* EPRI18 */

#define CSL_C7X_CPU_EPRI18_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI18_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI18_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI18_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI18_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI18_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI18_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI18_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI18_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI18_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI18_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI18_RESETVAL                             (0x00000000U)

    /* EPRI19 */

#define CSL_C7X_CPU_EPRI19_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI19_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI19_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI19_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI19_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI19_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI19_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI19_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI19_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI19_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI19_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI19_RESETVAL                             (0x00000000U)

    /* EPRI20 */

#define CSL_C7X_CPU_EPRI20_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI20_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI20_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI20_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI20_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI20_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI20_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI20_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI20_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI20_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI20_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI20_RESETVAL                             (0x00000000U)

    /* EPRI21 */

#define CSL_C7X_CPU_EPRI21_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI21_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI21_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI21_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI21_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI21_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI21_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI21_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI21_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI21_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI21_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI21_RESETVAL                             (0x00000000U)

    /* EPRI22 */

#define CSL_C7X_CPU_EPRI22_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI22_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI22_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI22_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI22_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI22_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI22_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI22_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI22_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI22_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI22_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI22_RESETVAL                             (0x00000000U)

    /* EPRI23 */

#define CSL_C7X_CPU_EPRI23_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI23_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI23_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI23_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI23_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI23_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI23_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI23_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI23_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI23_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI23_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI23_RESETVAL                             (0x00000000U)

    /* EPRI24 */

#define CSL_C7X_CPU_EPRI24_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI24_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI24_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI24_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI24_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI24_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI24_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI24_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI24_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI24_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI24_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI24_RESETVAL                             (0x00000000U)

    /* EPRI25 */

#define CSL_C7X_CPU_EPRI25_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI25_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI25_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI25_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI25_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI25_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI25_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI25_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI25_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI25_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI25_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI25_RESETVAL                             (0x00000000U)

    /* EPRI26 */

#define CSL_C7X_CPU_EPRI26_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI26_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI26_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI26_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI26_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI26_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI26_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI26_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI26_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI26_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI26_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI26_RESETVAL                             (0x00000000U)

    /* EPRI27 */

#define CSL_C7X_CPU_EPRI27_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI27_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI27_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI27_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI27_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI27_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI27_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI27_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI27_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI27_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI27_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI27_RESETVAL                             (0x00000000U)

    /* EPRI28 */

#define CSL_C7X_CPU_EPRI28_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI28_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI28_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI28_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI28_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI28_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI28_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI28_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI28_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI28_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI28_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI28_RESETVAL                             (0x00000000U)

    /* EPRI29 */

#define CSL_C7X_CPU_EPRI29_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI29_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI29_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI29_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI29_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI29_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI29_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI29_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI29_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI29_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI29_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI29_RESETVAL                             (0x00000000U)

    /* EPRI30 */

#define CSL_C7X_CPU_EPRI30_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI30_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI30_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI30_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI30_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI30_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI30_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI30_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI30_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI30_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI30_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI30_RESETVAL                             (0x00000000U)

    /* EPRI31 */

#define CSL_C7X_CPU_EPRI31_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI31_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI31_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI31_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI31_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI31_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI31_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI31_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI31_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI31_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI31_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI31_RESETVAL                             (0x00000000U)

    /* EPRI32 */

#define CSL_C7X_CPU_EPRI32_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI32_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI32_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI32_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI32_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI32_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI32_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI32_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI32_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI32_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI32_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI32_RESETVAL                             (0x00000000U)

    /* EPRI33 */

#define CSL_C7X_CPU_EPRI33_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI33_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI33_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI33_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI33_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI33_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI33_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI33_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI33_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI33_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI33_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI33_RESETVAL                             (0x00000000U)

    /* EPRI34 */

#define CSL_C7X_CPU_EPRI34_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI34_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI34_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI34_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI34_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI34_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI34_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI34_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI34_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI34_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI34_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI34_RESETVAL                             (0x00000000U)

    /* EPRI35 */

#define CSL_C7X_CPU_EPRI35_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI35_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI35_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI35_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI35_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI35_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI35_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI35_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI35_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI35_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI35_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI35_RESETVAL                             (0x00000000U)

    /* EPRI36 */

#define CSL_C7X_CPU_EPRI36_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI36_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI36_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI36_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI36_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI36_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI36_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI36_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI36_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI36_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI36_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI36_RESETVAL                             (0x00000000U)

    /* EPRI37 */

#define CSL_C7X_CPU_EPRI37_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI37_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI37_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI37_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI37_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI37_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI37_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI37_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI37_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI37_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI37_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI37_RESETVAL                             (0x00000000U)

    /* EPRI38 */

#define CSL_C7X_CPU_EPRI38_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI38_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI38_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI38_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI38_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI38_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI38_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI38_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI38_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI38_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI38_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI38_RESETVAL                             (0x00000000U)

    /* EPRI39 */

#define CSL_C7X_CPU_EPRI39_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI39_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI39_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI39_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI39_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI39_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI39_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI39_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI39_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI39_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI39_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI39_RESETVAL                             (0x00000000U)

    /* EPRI40 */

#define CSL_C7X_CPU_EPRI40_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI40_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI40_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI40_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI40_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI40_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI40_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI40_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI40_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI40_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI40_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI40_RESETVAL                             (0x00000000U)

    /* EPRI41 */

#define CSL_C7X_CPU_EPRI41_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI41_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI41_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI41_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI41_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI41_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI41_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI41_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI41_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI41_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI41_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI41_RESETVAL                             (0x00000000U)

    /* EPRI42 */

#define CSL_C7X_CPU_EPRI42_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI42_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI42_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI42_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI42_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI42_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI42_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI42_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI42_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI42_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI42_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI42_RESETVAL                             (0x00000000U)

    /* EPRI43 */

#define CSL_C7X_CPU_EPRI43_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI43_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI43_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI43_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI43_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI43_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI43_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI43_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI43_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI43_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI43_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI43_RESETVAL                             (0x00000000U)

    /* EPRI44 */

#define CSL_C7X_CPU_EPRI44_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI44_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI44_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI44_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI44_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI44_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI44_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI44_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI44_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI44_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI44_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI44_RESETVAL                             (0x00000000U)

    /* EPRI45 */

#define CSL_C7X_CPU_EPRI45_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI45_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI45_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI45_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI45_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI45_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI45_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI45_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI45_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI45_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI45_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI45_RESETVAL                             (0x00000000U)

    /* EPRI46 */

#define CSL_C7X_CPU_EPRI46_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI46_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI46_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI46_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI46_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI46_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI46_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI46_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI46_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI46_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI46_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI46_RESETVAL                             (0x00000000U)

    /* EPRI47 */

#define CSL_C7X_CPU_EPRI47_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI47_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI47_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI47_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI47_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI47_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI47_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI47_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI47_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI47_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI47_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI47_RESETVAL                             (0x00000000U)

    /* EPRI48 */

#define CSL_C7X_CPU_EPRI48_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI48_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI48_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI48_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI48_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI48_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI48_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI48_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI48_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI48_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI48_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI48_RESETVAL                             (0x00000000U)

    /* EPRI49 */

#define CSL_C7X_CPU_EPRI49_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI49_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI49_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI49_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI49_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI49_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI49_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI49_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI49_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI49_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI49_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI49_RESETVAL                             (0x00000000U)

    /* EPRI50 */

#define CSL_C7X_CPU_EPRI50_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI50_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI50_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI50_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI50_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI50_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI50_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI50_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI50_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI50_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI50_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI50_RESETVAL                             (0x00000000U)

    /* EPRI51 */

#define CSL_C7X_CPU_EPRI51_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI51_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI51_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI51_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI51_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI51_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI51_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI51_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI51_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI51_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI51_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI51_RESETVAL                             (0x00000000U)

    /* EPRI52 */

#define CSL_C7X_CPU_EPRI52_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI52_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI52_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI52_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI52_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI52_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI52_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI52_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI52_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI52_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI52_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI52_RESETVAL                             (0x00000000U)

    /* EPRI53 */

#define CSL_C7X_CPU_EPRI53_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI53_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI53_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI53_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI53_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI53_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI53_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI53_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI53_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI53_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI53_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI53_RESETVAL                             (0x00000000U)

    /* EPRI54 */

#define CSL_C7X_CPU_EPRI54_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI54_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI54_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI54_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI54_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI54_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI54_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI54_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI54_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI54_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI54_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI54_RESETVAL                             (0x00000000U)

    /* EPRI55 */

#define CSL_C7X_CPU_EPRI55_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI55_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI55_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI55_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI55_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI55_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI55_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI55_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI55_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI55_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI55_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI55_RESETVAL                             (0x00000000U)

    /* EPRI56 */

#define CSL_C7X_CPU_EPRI56_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI56_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI56_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI56_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI56_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI56_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI56_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI56_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI56_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI56_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI56_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI56_RESETVAL                             (0x00000000U)

    /* EPRI57 */

#define CSL_C7X_CPU_EPRI57_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI57_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI57_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI57_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI57_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI57_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI57_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI57_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI57_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI57_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI57_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI57_RESETVAL                             (0x00000000U)

    /* EPRI58 */

#define CSL_C7X_CPU_EPRI58_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI58_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI58_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI58_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI58_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI58_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI58_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI58_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI58_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI58_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI58_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI58_RESETVAL                             (0x00000000U)

    /* EPRI59 */

#define CSL_C7X_CPU_EPRI59_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI59_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI59_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI59_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI59_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI59_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI59_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI59_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI59_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI59_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI59_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI59_RESETVAL                             (0x00000000U)

    /* EPRI60 */

#define CSL_C7X_CPU_EPRI60_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI60_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI60_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI60_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI60_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI60_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI60_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI60_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI60_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI60_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI60_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI60_RESETVAL                             (0x00000000U)

    /* EPRI61 */

#define CSL_C7X_CPU_EPRI61_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI61_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI61_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI61_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI61_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI61_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI61_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI61_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI61_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI61_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI61_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI61_RESETVAL                             (0x00000000U)

    /* EPRI62 */

#define CSL_C7X_CPU_EPRI62_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI62_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI62_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI62_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI62_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI62_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI62_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI62_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI62_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI62_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI62_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI62_RESETVAL                             (0x00000000U)

    /* EPRI63 */

#define CSL_C7X_CPU_EPRI63_RSVD1_MASK                           (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_EPRI63_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_EPRI63_RSVD1_RESETVAL                       (0x00000000U)

#define CSL_C7X_CPU_EPRI63_EPRI_MASK                            (0x000000E0U)
#define CSL_C7X_CPU_EPRI63_EPRI_SHIFT                           (5U)
#define CSL_C7X_CPU_EPRI63_EPRI_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_EPRI63_EPRI_MAX                             (0x00000007U)

#define CSL_C7X_CPU_EPRI63_RSVD0_MASK                           (0x0000001FU)
#define CSL_C7X_CPU_EPRI63_RSVD0_SHIFT                          (0U)
#define CSL_C7X_CPU_EPRI63_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EPRI63_RSVD0_MAX                            (0x0000001fU)

#define CSL_C7X_CPU_EPRI63_RESETVAL                             (0x00000000U)

    /* EER0 */

#define CSL_C7X_CPU_EER0_EER_MASK                               (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_EER0_EER_SHIFT                              (0U)
#define CSL_C7X_CPU_EER0_EER_RESETVAL                           (0x00000000U)
#define CSL_C7X_CPU_EER0_EER_MAX                                (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_EER0_RESETVAL                               (0x00000000U)

    /* EESET0 */

#define CSL_C7X_CPU_EESET0_EESET_MASK                           (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_EESET0_EESET_SHIFT                          (0U)
#define CSL_C7X_CPU_EESET0_EESET_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EESET0_EESET_MAX                            (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_EESET0_RESETVAL                             (0x00000000U)

    /* EECLR0 */

#define CSL_C7X_CPU_EECLR0_EECLR_MASK                           (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_EECLR0_EECLR_SHIFT                          (0U)
#define CSL_C7X_CPU_EECLR0_EECLR_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EECLR0_EECLR_MAX                            (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_EECLR0_RESETVAL                             (0x00000000U)

    /* DEPR */

#define CSL_C7X_CPU_DEPR_RSVD0_MASK                             (0xFFFFFFFFFFFFFF00U)
#define CSL_C7X_CPU_DEPR_RSVD0_SHIFT                            (8U)
#define CSL_C7X_CPU_DEPR_RSVD0_RESETVAL                         (0x00000000U)

#define CSL_C7X_CPU_DEPR_DEPR_MASK                              (0x000000E0U)
#define CSL_C7X_CPU_DEPR_DEPR_SHIFT                             (5U)
#define CSL_C7X_CPU_DEPR_DEPR_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_DEPR_DEPR_MAX                               (0x00000007U)

#define CSL_C7X_CPU_DEPR_RSVD1_MASK                             (0x0000001FU)
#define CSL_C7X_CPU_DEPR_RSVD1_SHIFT                            (0U)
#define CSL_C7X_CPU_DEPR_RSVD1_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_DEPR_RSVD1_MAX                              (0x0000001fU)

#define CSL_C7X_CPU_DEPR_RESETVAL                               (0x00000000U)

    /* EFR0 */

#define CSL_C7X_CPU_EFR0_EFR_MASK                               (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_EFR0_EFR_SHIFT                              (0U)
#define CSL_C7X_CPU_EFR0_EFR_RESETVAL                           (0x00000000U)
#define CSL_C7X_CPU_EFR0_EFR_MAX                                (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_EFR0_RESETVAL                               (0x00000000U)

    /* EFSET0 */

#define CSL_C7X_CPU_EFSET0_EFSET_MASK                           (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_EFSET0_EFSET_SHIFT                          (0U)
#define CSL_C7X_CPU_EFSET0_EFSET_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EFSET0_EFSET_MAX                            (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_EFSET0_RESETVAL                             (0x00000000U)

    /* EFCLR0 */

#define CSL_C7X_CPU_EFCLR0_EFCLR_MASK                           (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_EFCLR0_EFCLR_SHIFT                          (0U)
#define CSL_C7X_CPU_EFCLR0_EFCLR_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_EFCLR0_EFCLR_MAX                            (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_EFCLR0_RESETVAL                             (0x00000000U)

    /* IESET0 */

#define CSL_C7X_CPU_IESET0_IESET_MASK                           (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_IESET0_IESET_SHIFT                          (0U)
#define CSL_C7X_CPU_IESET0_IESET_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_IESET0_IESET_MAX                            (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_IESET0_RESETVAL                             (0x00000000U)

    /* ESTP_SS */

#define CSL_C7X_CPU_ESTP_SS_ESTB_MASK                           (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_ESTP_SS_ESTB_SHIFT                          (0U)
#define CSL_C7X_CPU_ESTP_SS_ESTB_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_ESTP_SS_ESTB_MAX                            (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_ESTP_SS_RESETVAL                            (0x00000000U)

    /* ESTP_S */

#define CSL_C7X_CPU_ESTP_S_ESTB_MASK                            (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_ESTP_S_ESTB_SHIFT                           (0U)
#define CSL_C7X_CPU_ESTP_S_ESTB_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_ESTP_S_ESTB_MAX                             (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_ESTP_S_RESETVAL                             (0x00000000U)

    /* ESTP_GS */

#define CSL_C7X_CPU_ESTP_GS_ESTB_MASK                           (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_ESTP_GS_ESTB_SHIFT                          (0U)
#define CSL_C7X_CPU_ESTP_GS_ESTB_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_ESTP_GS_ESTB_MAX                            (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_ESTP_GS_RESETVAL                            (0x00000000U)

    /* EDR0 */

#define CSL_C7X_CPU_EDR0_EDR_MASK                               (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_EDR0_EDR_SHIFT                              (0U)
#define CSL_C7X_CPU_EDR0_EDR_RESETVAL                           (0x00000000U)
#define CSL_C7X_CPU_EDR0_EDR_MAX                                (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_EDR0_RESETVAL                               (0x00000000U)

    /* ECSP_SS */

#define CSL_C7X_CPU_ECSP_SS_ECSP_MASK                           (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_ECSP_SS_ECSP_SHIFT                          (0U)
#define CSL_C7X_CPU_ECSP_SS_ECSP_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_ECSP_SS_ECSP_MAX                            (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_ECSP_SS_RESETVAL                            (0x00000000U)

    /* ECSP_S */

#define CSL_C7X_CPU_ECSP_S_ECSP_MASK                            (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_ECSP_S_ECSP_SHIFT                           (0U)
#define CSL_C7X_CPU_ECSP_S_ECSP_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_ECSP_S_ECSP_MAX                             (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_ECSP_S_RESETVAL                             (0x00000000U)

    /* ECSP_GS */

#define CSL_C7X_CPU_ECSP_GS_ECSP_MASK                           (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_ECSP_GS_ECSP_SHIFT                          (0U)
#define CSL_C7X_CPU_ECSP_GS_ECSP_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_ECSP_GS_ECSP_MAX                            (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_ECSP_GS_RESETVAL                            (0x00000000U)

    /* TCSP */

#define CSL_C7X_CPU_TCSP_TCSP_MASK                              (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_TCSP_TCSP_SHIFT                             (0U)
#define CSL_C7X_CPU_TCSP_TCSP_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_TCSP_TCSP_MAX                               (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_TCSP_RESETVAL                               (0x00000000U)

    /* RXMR_SS */

#define CSL_C7X_CPU_RXMR_SS_RSVD1_MASK                          (0xFFFFFFF800000000U)
#define CSL_C7X_CPU_RXMR_SS_RSVD1_SHIFT                         (35U)
#define CSL_C7X_CPU_RXMR_SS_RSVD1_RESETVAL                      (0x00000000U)
#define CSL_C7X_CPU_RXMR_SS_RSVD1_MAX                           (0x1fffffffU)

#define CSL_C7X_CPU_RXMR_SS_SYSCALL_MASK                        (0x700000000U)
#define CSL_C7X_CPU_RXMR_SS_SYSCALL_SHIFT                       (32U)
#define CSL_C7X_CPU_RXMR_SS_SYSCALL_RESETVAL                    (0x00000000U)
#define CSL_C7X_CPU_RXMR_SS_SYSCALL_MAX                         (0x00000007U)

#define CSL_C7X_CPU_RXMR_SS_RSVD0_MASK                          (0xFFFFFFF8U)
#define CSL_C7X_CPU_RXMR_SS_RSVD0_SHIFT                         (3U)
#define CSL_C7X_CPU_RXMR_SS_RSVD0_RESETVAL                      (0x00000000U)
#define CSL_C7X_CPU_RXMR_SS_RSVD0_MAX                           (0x1fffffffU)

#define CSL_C7X_CPU_RXMR_SS_CXM_MASK                            (0x00000007U)
#define CSL_C7X_CPU_RXMR_SS_CXM_SHIFT                           (0U)
#define CSL_C7X_CPU_RXMR_SS_CXM_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_RXMR_SS_CXM_MAX                             (0x00000007U)

#define CSL_C7X_CPU_RXMR_SS_RESETVAL                            (0x00000000U)

    /* RXMR_S */

#define CSL_C7X_CPU_RXMR_S_RSVD1_MASK                           (0xFFFFFFF800000000U)
#define CSL_C7X_CPU_RXMR_S_RSVD1_SHIFT                          (35U)
#define CSL_C7X_CPU_RXMR_S_RSVD1_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_RXMR_S_RSVD1_MAX                            (0x1fffffffU)

#define CSL_C7X_CPU_RXMR_S_SYSCALL_MASK                         (0x700000000U)
#define CSL_C7X_CPU_RXMR_S_SYSCALL_SHIFT                        (32U)
#define CSL_C7X_CPU_RXMR_S_SYSCALL_RESETVAL                     (0x00000000U)
#define CSL_C7X_CPU_RXMR_S_SYSCALL_MAX                          (0x00000007U)

#define CSL_C7X_CPU_RXMR_S_RSVD0_MASK                           (0xFFFFFFF8U)
#define CSL_C7X_CPU_RXMR_S_RSVD0_SHIFT                          (3U)
#define CSL_C7X_CPU_RXMR_S_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_RXMR_S_RSVD0_MAX                            (0x1fffffffU)

#define CSL_C7X_CPU_RXMR_S_CXM_MASK                             (0x00000007U)
#define CSL_C7X_CPU_RXMR_S_CXM_SHIFT                            (0U)
#define CSL_C7X_CPU_RXMR_S_CXM_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_RXMR_S_CXM_MAX                              (0x00000007U)

#define CSL_C7X_CPU_RXMR_S_RESETVAL                             (0x00000000U)

    /* AHPEE */

#define CSL_C7X_CPU_AHPEE_RSVD0_MASK                            (0xFFFFFFFFFFFFFFC0U)
#define CSL_C7X_CPU_AHPEE_RSVD0_SHIFT                           (6U)
#define CSL_C7X_CPU_AHPEE_RSVD0_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_AHPEE_NUM_MASK                              (0x0000003FU)
#define CSL_C7X_CPU_AHPEE_NUM_SHIFT                             (0U)
#define CSL_C7X_CPU_AHPEE_NUM_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_AHPEE_NUM_MAX                               (0x0000003fU)

#define CSL_C7X_CPU_AHPEE_RESETVAL                              (0x00000000U)

    /* PHPEE */

#define CSL_C7X_CPU_PHPEE_RSVD0_MASK                            (0xFFFFFFFFFFFFFFC0U)
#define CSL_C7X_CPU_PHPEE_RSVD0_SHIFT                           (6U)
#define CSL_C7X_CPU_PHPEE_RSVD0_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_PHPEE_NUM_MASK                              (0x0000003FU)
#define CSL_C7X_CPU_PHPEE_NUM_SHIFT                             (0U)
#define CSL_C7X_CPU_PHPEE_NUM_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_PHPEE_NUM_MAX                               (0x0000003fU)

#define CSL_C7X_CPU_PHPEE_RESETVAL                              (0x00000000U)

    /* IEBER0 */

#define CSL_C7X_CPU_IEBER0_IEBER_MASK                           (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_IEBER0_IEBER_SHIFT                          (0U)
#define CSL_C7X_CPU_IEBER0_IEBER_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_IEBER0_IEBER_MAX                            (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_IEBER0_RESETVAL                             (0x00000000U)

    /* IERR */

#define CSL_C7X_CPU_IERR_IERR_MASK                              (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_IERR_IERR_SHIFT                             (0U)
#define CSL_C7X_CPU_IERR_IERR_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_IERR_IERR_MAX                               (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_IERR_RESETVAL                               (0x00000000U)

    /* IEAR */

#define CSL_C7X_CPU_IEAR_IEAR_MASK                              (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_IEAR_IEAR_SHIFT                             (0U)
#define CSL_C7X_CPU_IEAR_IEAR_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_IEAR_IEAR_MAX                               (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_IEAR_RESETVAL                               (0x00000000U)

    /* IESR */

#define CSL_C7X_CPU_IESR_IESR_MASK                              (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_IESR_IESR_SHIFT                             (0U)
#define CSL_C7X_CPU_IESR_IESR_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_IESR_IESR_MAX                               (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_IESR_RESETVAL                               (0x00000000U)

    /* IEDR */

#define CSL_C7X_CPU_IEDR_IEDR_MASK                              (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_IEDR_IEDR_SHIFT                             (0U)
#define CSL_C7X_CPU_IEDR_IEDR_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_IEDR_IEDR_MAX                               (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_IEDR_RESETVAL                               (0x00000000U)

    /* TCR */

#define CSL_C7X_CPU_TCR_TCR_MASK                                (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_TCR_TCR_SHIFT                               (0U)
#define CSL_C7X_CPU_TCR_TCR_RESETVAL                            (0x00000000U)
#define CSL_C7X_CPU_TCR_TCR_MAX                                 (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_TCR_RESETVAL                                (0x00000000U)

    /* TCCR */

#define CSL_C7X_CPU_TCCR_TCCR_MASK                              (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_TCCR_TCCR_SHIFT                             (0U)
#define CSL_C7X_CPU_TCCR_TCCR_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_TCCR_TCCR_MAX                               (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_TCCR_RESETVAL                               (0x00000000U)

    /* GMER */

#define CSL_C7X_CPU_GMER_RSVD0_MASK                             (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_GMER_RSVD0_SHIFT                            (1U)
#define CSL_C7X_CPU_GMER_RSVD0_RESETVAL                         (0x00000000U)

#define CSL_C7X_CPU_GMER_SECCALLEN_MASK                         (0x00000001U)
#define CSL_C7X_CPU_GMER_SECCALLEN_SHIFT                        (0U)
#define CSL_C7X_CPU_GMER_SECCALLEN_RESETVAL                     (0x00000000U)
#define CSL_C7X_CPU_GMER_SECCALLEN_MAX                          (0x00000001U)

#define CSL_C7X_CPU_GMER_RESETVAL                               (0x00000000U)

    /* UMER */

#define CSL_C7X_CPU_UMER_RSVD0_MASK                             (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_UMER_RSVD0_SHIFT                            (1U)
#define CSL_C7X_CPU_UMER_RSVD0_RESETVAL                         (0x00000000U)

#define CSL_C7X_CPU_UMER_UMEN_MASK                              (0x00000001U)
#define CSL_C7X_CPU_UMER_UMEN_SHIFT                             (0U)
#define CSL_C7X_CPU_UMER_UMEN_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_UMER_UMEN_MAX                               (0x00000001U)

#define CSL_C7X_CPU_UMER_RESETVAL                               (0x00000000U)

    /* SPBR */

#define CSL_C7X_CPU_SPBR_SPBR_MASK                              (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_SPBR_SPBR_SHIFT                             (0U)
#define CSL_C7X_CPU_SPBR_SPBR_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_SPBR_SPBR_MAX                               (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_SPBR_RESETVAL                               (0x00000000U)

    /* LTBR0 */

#define CSL_C7X_CPU_LTBR0_RSVD1_MASK                            (0xFFFFFFFFFFFF0000U)
#define CSL_C7X_CPU_LTBR0_RSVD1_SHIFT                           (16U)
#define CSL_C7X_CPU_LTBR0_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_LTBR0_BASE_MASK                             (0x0000FF00U)
#define CSL_C7X_CPU_LTBR0_BASE_SHIFT                            (8U)
#define CSL_C7X_CPU_LTBR0_BASE_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTBR0_BASE_MAX                              (0x000000ffU)

#define CSL_C7X_CPU_LTBR0_RSVD0_MASK                            (0x000000FFU)
#define CSL_C7X_CPU_LTBR0_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_LTBR0_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTBR0_RSVD0_MAX                             (0x000000ffU)

#define CSL_C7X_CPU_LTBR0_RESETVAL                              (0x00000000U)

    /* LTBR1 */

#define CSL_C7X_CPU_LTBR1_RSVD1_MASK                            (0xFFFFFFFFFFFF0000U)
#define CSL_C7X_CPU_LTBR1_RSVD1_SHIFT                           (16U)
#define CSL_C7X_CPU_LTBR1_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_LTBR1_BASE_MASK                             (0x0000FF00U)
#define CSL_C7X_CPU_LTBR1_BASE_SHIFT                            (8U)
#define CSL_C7X_CPU_LTBR1_BASE_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTBR1_BASE_MAX                              (0x000000ffU)

#define CSL_C7X_CPU_LTBR1_RSVD0_MASK                            (0x000000FFU)
#define CSL_C7X_CPU_LTBR1_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_LTBR1_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTBR1_RSVD0_MAX                             (0x000000ffU)

#define CSL_C7X_CPU_LTBR1_RESETVAL                              (0x00000000U)

    /* LTBR2 */

#define CSL_C7X_CPU_LTBR2_RSVD1_MASK                            (0xFFFFFFFFFFFF0000U)
#define CSL_C7X_CPU_LTBR2_RSVD1_SHIFT                           (16U)
#define CSL_C7X_CPU_LTBR2_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_LTBR2_BASE_MASK                             (0x0000FF00U)
#define CSL_C7X_CPU_LTBR2_BASE_SHIFT                            (8U)
#define CSL_C7X_CPU_LTBR2_BASE_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTBR2_BASE_MAX                              (0x000000ffU)

#define CSL_C7X_CPU_LTBR2_RSVD0_MASK                            (0x000000FFU)
#define CSL_C7X_CPU_LTBR2_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_LTBR2_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTBR2_RSVD0_MAX                             (0x000000ffU)

#define CSL_C7X_CPU_LTBR2_RESETVAL                              (0x00000000U)

    /* LTBR3 */

#define CSL_C7X_CPU_LTBR3_RSVD1_MASK                            (0xFFFFFFFFFFFF0000U)
#define CSL_C7X_CPU_LTBR3_RSVD1_SHIFT                           (16U)
#define CSL_C7X_CPU_LTBR3_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_LTBR3_BASE_MASK                             (0x0000FF00U)
#define CSL_C7X_CPU_LTBR3_BASE_SHIFT                            (8U)
#define CSL_C7X_CPU_LTBR3_BASE_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTBR3_BASE_MAX                              (0x000000ffU)

#define CSL_C7X_CPU_LTBR3_RSVD0_MASK                            (0x000000FFU)
#define CSL_C7X_CPU_LTBR3_RSVD0_SHIFT                           (0U)
#define CSL_C7X_CPU_LTBR3_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTBR3_RSVD0_MAX                             (0x000000ffU)

#define CSL_C7X_CPU_LTBR3_RESETVAL                              (0x00000000U)

    /* LTCR0 */

#define CSL_C7X_CPU_LTCR0_RSVD1_MASK                            (0xFFFFFFFFFC000000U)
#define CSL_C7X_CPU_LTCR0_RSVD1_SHIFT                           (26U)
#define CSL_C7X_CPU_LTCR0_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_LTCR0_PROMO_MASK                            (0x03000000U)
#define CSL_C7X_CPU_LTCR0_PROMO_SHIFT                           (24U)
#define CSL_C7X_CPU_LTCR0_PROMO_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR0_PROMO_MAX                             (0x00000003U)

#define CSL_C7X_CPU_LTCR0_TSIZE_MASK                            (0x00FF0000U)
#define CSL_C7X_CPU_LTCR0_TSIZE_SHIFT                           (16U)
#define CSL_C7X_CPU_LTCR0_TSIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR0_TSIZE_MAX                             (0x000000ffU)

#define CSL_C7X_CPU_LTCR0_RSVD0_MASK                            (0x0000C000U)
#define CSL_C7X_CPU_LTCR0_RSVD0_SHIFT                           (14U)
#define CSL_C7X_CPU_LTCR0_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR0_RSVD0_MAX                             (0x00000003U)

#define CSL_C7X_CPU_LTCR0_WSIZE_MASK                            (0x00003800U)
#define CSL_C7X_CPU_LTCR0_WSIZE_SHIFT                           (11U)
#define CSL_C7X_CPU_LTCR0_WSIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR0_WSIZE_MAX                             (0x00000007U)

#define CSL_C7X_CPU_LTCR0_INTER_MASK                            (0x00000700U)
#define CSL_C7X_CPU_LTCR0_INTER_SHIFT                           (8U)
#define CSL_C7X_CPU_LTCR0_INTER_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR0_INTER_MAX                             (0x00000007U)

#define CSL_C7X_CPU_LTCR0_SAT_MASK                              (0x00000080U)
#define CSL_C7X_CPU_LTCR0_SAT_SHIFT                             (7U)
#define CSL_C7X_CPU_LTCR0_SAT_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_LTCR0_SAT_MAX                               (0x00000001U)

#define CSL_C7X_CPU_LTCR0_SIGN_MASK                             (0x00000040U)
#define CSL_C7X_CPU_LTCR0_SIGN_SHIFT                            (6U)
#define CSL_C7X_CPU_LTCR0_SIGN_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTCR0_SIGN_MAX                              (0x00000001U)

#define CSL_C7X_CPU_LTCR0_ESIZE_MASK                            (0x00000038U)
#define CSL_C7X_CPU_LTCR0_ESIZE_SHIFT                           (3U)
#define CSL_C7X_CPU_LTCR0_ESIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR0_ESIZE_MAX                             (0x00000007U)

#define CSL_C7X_CPU_LTCR0_NTBL_MASK                             (0x00000007U)
#define CSL_C7X_CPU_LTCR0_NTBL_SHIFT                            (0U)
#define CSL_C7X_CPU_LTCR0_NTBL_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTCR0_NTBL_MAX                              (0x00000007U)

#define CSL_C7X_CPU_LTCR0_RESETVAL                              (0x00000000U)

    /* LTCR1 */

#define CSL_C7X_CPU_LTCR1_RSVD1_MASK                            (0xFFFFFFFFFC000000U)
#define CSL_C7X_CPU_LTCR1_RSVD1_SHIFT                           (26U)
#define CSL_C7X_CPU_LTCR1_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_LTCR1_PROMO_MASK                            (0x03000000U)
#define CSL_C7X_CPU_LTCR1_PROMO_SHIFT                           (24U)
#define CSL_C7X_CPU_LTCR1_PROMO_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR1_PROMO_MAX                             (0x00000003U)

#define CSL_C7X_CPU_LTCR1_TSIZE_MASK                            (0x00FF0000U)
#define CSL_C7X_CPU_LTCR1_TSIZE_SHIFT                           (16U)
#define CSL_C7X_CPU_LTCR1_TSIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR1_TSIZE_MAX                             (0x000000ffU)

#define CSL_C7X_CPU_LTCR1_RSVD0_MASK                            (0x0000C000U)
#define CSL_C7X_CPU_LTCR1_RSVD0_SHIFT                           (14U)
#define CSL_C7X_CPU_LTCR1_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR1_RSVD0_MAX                             (0x00000003U)

#define CSL_C7X_CPU_LTCR1_WSIZE_MASK                            (0x00003800U)
#define CSL_C7X_CPU_LTCR1_WSIZE_SHIFT                           (11U)
#define CSL_C7X_CPU_LTCR1_WSIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR1_WSIZE_MAX                             (0x00000007U)

#define CSL_C7X_CPU_LTCR1_INTER_MASK                            (0x00000700U)
#define CSL_C7X_CPU_LTCR1_INTER_SHIFT                           (8U)
#define CSL_C7X_CPU_LTCR1_INTER_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR1_INTER_MAX                             (0x00000007U)

#define CSL_C7X_CPU_LTCR1_SAT_MASK                              (0x00000080U)
#define CSL_C7X_CPU_LTCR1_SAT_SHIFT                             (7U)
#define CSL_C7X_CPU_LTCR1_SAT_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_LTCR1_SAT_MAX                               (0x00000001U)

#define CSL_C7X_CPU_LTCR1_SIGN_MASK                             (0x00000040U)
#define CSL_C7X_CPU_LTCR1_SIGN_SHIFT                            (6U)
#define CSL_C7X_CPU_LTCR1_SIGN_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTCR1_SIGN_MAX                              (0x00000001U)

#define CSL_C7X_CPU_LTCR1_ESIZE_MASK                            (0x00000038U)
#define CSL_C7X_CPU_LTCR1_ESIZE_SHIFT                           (3U)
#define CSL_C7X_CPU_LTCR1_ESIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR1_ESIZE_MAX                             (0x00000007U)

#define CSL_C7X_CPU_LTCR1_NTBL_MASK                             (0x00000007U)
#define CSL_C7X_CPU_LTCR1_NTBL_SHIFT                            (0U)
#define CSL_C7X_CPU_LTCR1_NTBL_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTCR1_NTBL_MAX                              (0x00000007U)

#define CSL_C7X_CPU_LTCR1_RESETVAL                              (0x00000000U)

/* LTCR2 */

#define CSL_C7X_CPU_LTCR2_RSVD1_MASK                            (0xFFFFFFFFFC000000U)
#define CSL_C7X_CPU_LTCR2_RSVD1_SHIFT                           (26U)
#define CSL_C7X_CPU_LTCR2_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_LTCR2_PROMO_MASK                            (0x03000000U)
#define CSL_C7X_CPU_LTCR2_PROMO_SHIFT                           (24U)
#define CSL_C7X_CPU_LTCR2_PROMO_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR2_PROMO_MAX                             (0x00000003U)

#define CSL_C7X_CPU_LTCR2_TSIZE_MASK                            (0x00FF0000U)
#define CSL_C7X_CPU_LTCR2_TSIZE_SHIFT                           (16U)
#define CSL_C7X_CPU_LTCR2_TSIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR2_TSIZE_MAX                             (0x000000ffU)

#define CSL_C7X_CPU_LTCR2_RSVD0_MASK                            (0x0000C000U)
#define CSL_C7X_CPU_LTCR2_RSVD0_SHIFT                           (14U)
#define CSL_C7X_CPU_LTCR2_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR2_RSVD0_MAX                             (0x00000003U)

#define CSL_C7X_CPU_LTCR2_WSIZE_MASK                            (0x00003800U)
#define CSL_C7X_CPU_LTCR2_WSIZE_SHIFT                           (11U)
#define CSL_C7X_CPU_LTCR2_WSIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR2_WSIZE_MAX                             (0x00000007U)

#define CSL_C7X_CPU_LTCR2_INTER_MASK                            (0x00000700U)
#define CSL_C7X_CPU_LTCR2_INTER_SHIFT                           (8U)
#define CSL_C7X_CPU_LTCR2_INTER_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR2_INTER_MAX                             (0x00000007U)

#define CSL_C7X_CPU_LTCR2_SAT_MASK                              (0x00000080U)
#define CSL_C7X_CPU_LTCR2_SAT_SHIFT                             (7U)
#define CSL_C7X_CPU_LTCR2_SAT_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_LTCR2_SAT_MAX                               (0x00000001U)

#define CSL_C7X_CPU_LTCR2_SIGN_MASK                             (0x00000040U)
#define CSL_C7X_CPU_LTCR2_SIGN_SHIFT                            (6U)
#define CSL_C7X_CPU_LTCR2_SIGN_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTCR2_SIGN_MAX                              (0x00000001U)

#define CSL_C7X_CPU_LTCR2_ESIZE_MASK                            (0x00000038U)
#define CSL_C7X_CPU_LTCR2_ESIZE_SHIFT                           (3U)
#define CSL_C7X_CPU_LTCR2_ESIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR2_ESIZE_MAX                             (0x00000007U)

#define CSL_C7X_CPU_LTCR2_NTBL_MASK                             (0x00000007U)
#define CSL_C7X_CPU_LTCR2_NTBL_SHIFT                            (0U)
#define CSL_C7X_CPU_LTCR2_NTBL_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTCR2_NTBL_MAX                              (0x00000007U)

#define CSL_C7X_CPU_LTCR2_RESETVAL                              (0x00000000U)

/* LTCR3 */

#define CSL_C7X_CPU_LTCR3_RSVD1_MASK                            (0xFFFFFFFFFC000000U)
#define CSL_C7X_CPU_LTCR3_RSVD1_SHIFT                           (26U)
#define CSL_C7X_CPU_LTCR3_RSVD1_RESETVAL                        (0x00000000U)

#define CSL_C7X_CPU_LTCR3_PROMO_MASK                            (0x03000000U)
#define CSL_C7X_CPU_LTCR3_PROMO_SHIFT                           (24U)
#define CSL_C7X_CPU_LTCR3_PROMO_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR3_PROMO_MAX                             (0x00000003U)

#define CSL_C7X_CPU_LTCR3_TSIZE_MASK                            (0x00FF0000U)
#define CSL_C7X_CPU_LTCR3_TSIZE_SHIFT                           (16U)
#define CSL_C7X_CPU_LTCR3_TSIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR3_TSIZE_MAX                             (0x000000ffU)

#define CSL_C7X_CPU_LTCR3_RSVD0_MASK                            (0x0000C000U)
#define CSL_C7X_CPU_LTCR3_RSVD0_SHIFT                           (14U)
#define CSL_C7X_CPU_LTCR3_RSVD0_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR3_RSVD0_MAX                             (0x00000003U)

#define CSL_C7X_CPU_LTCR3_WSIZE_MASK                            (0x00003800U)
#define CSL_C7X_CPU_LTCR3_WSIZE_SHIFT                           (11U)
#define CSL_C7X_CPU_LTCR3_WSIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR3_WSIZE_MAX                             (0x00000007U)

#define CSL_C7X_CPU_LTCR3_INTER_MASK                            (0x00000700U)
#define CSL_C7X_CPU_LTCR3_INTER_SHIFT                           (8U)
#define CSL_C7X_CPU_LTCR3_INTER_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR3_INTER_MAX                             (0x00000007U)

#define CSL_C7X_CPU_LTCR3_SAT_MASK                              (0x00000080U)
#define CSL_C7X_CPU_LTCR3_SAT_SHIFT                             (7U)
#define CSL_C7X_CPU_LTCR3_SAT_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_LTCR3_SAT_MAX                               (0x00000001U)

#define CSL_C7X_CPU_LTCR3_SIGN_MASK                             (0x00000040U)
#define CSL_C7X_CPU_LTCR3_SIGN_SHIFT                            (6U)
#define CSL_C7X_CPU_LTCR3_SIGN_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTCR3_SIGN_MAX                              (0x00000001U)

#define CSL_C7X_CPU_LTCR3_ESIZE_MASK                            (0x00000038U)
#define CSL_C7X_CPU_LTCR3_ESIZE_SHIFT                           (3U)
#define CSL_C7X_CPU_LTCR3_ESIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_LTCR3_ESIZE_MAX                             (0x00000007U)

#define CSL_C7X_CPU_LTCR3_NTBL_MASK                             (0x00000007U)
#define CSL_C7X_CPU_LTCR3_NTBL_SHIFT                            (0U)
#define CSL_C7X_CPU_LTCR3_NTBL_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTCR3_NTBL_MAX                              (0x00000007U)

#define CSL_C7X_CPU_LTCR3_RESETVAL                              (0x00000000U)

/* LTER */

#define CSL_C7X_CPU_LTER_RSVD0_MASK                             (0xFFFFFFFFFFFFC000U)
#define CSL_C7X_CPU_LTER_RSVD0_SHIFT                            (14U)
#define CSL_C7X_CPU_LTER_RSVD0_RESETVAL                         (0x00000000U)

#define CSL_C7X_CPU_LTER_LUTE3_MASK                             (0x00003000U)
#define CSL_C7X_CPU_LTER_LUTE3_SHIFT                            (12U)
#define CSL_C7X_CPU_LTER_LUTE3_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTER_LUTE3_MAX                              (0x00000003U)

#define CSL_C7X_CPU_LTER_RSVD1_MASK                             (0x00000C00U)
#define CSL_C7X_CPU_LTER_RSVD1_SHIFT                            (10U)
#define CSL_C7X_CPU_LTER_RSVD1_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTER_RSVD1_MAX                              (0x00000003U)

#define CSL_C7X_CPU_LTER_LUTE2_MASK                             (0x00000300U)
#define CSL_C7X_CPU_LTER_LUTE2_SHIFT                            (8U)
#define CSL_C7X_CPU_LTER_LUTE2_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTER_LUTE2_MAX                              (0x00000003U)

#define CSL_C7X_CPU_LTER_RSVD2_MASK                             (0x000000C0U)
#define CSL_C7X_CPU_LTER_RSVD2_SHIFT                            (6U)
#define CSL_C7X_CPU_LTER_RSVD2_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTER_RSVD2_MAX                              (0x00000003U)

#define CSL_C7X_CPU_LTER_LUTE1_MASK                             (0x00000030U)
#define CSL_C7X_CPU_LTER_LUTE1_SHIFT                            (4U)
#define CSL_C7X_CPU_LTER_LUTE1_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTER_LUTE1_MAX                              (0x00000003U)

#define CSL_C7X_CPU_LTER_RSVD3_MASK                             (0x0000000CU)
#define CSL_C7X_CPU_LTER_RSVD3_SHIFT                            (2U)
#define CSL_C7X_CPU_LTER_RSVD3_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTER_RSVD3_MAX                              (0x00000003U)

#define CSL_C7X_CPU_LTER_LUTE0_MASK                             (0x00000003U)
#define CSL_C7X_CPU_LTER_LUTE0_SHIFT                            (0U)
#define CSL_C7X_CPU_LTER_LUTE0_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_LTER_LUTE0_MAX                              (0x00000003U)

#define CSL_C7X_CPU_LTER_RESETVAL                               (0x00000000U)

/* DBGCTXT */

#define CSL_C7X_CPU_DBGCTXT_DBGCTXT_MASK                        (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_DBGCTXT_DBGCTXT_SHIFT                       (0U)
#define CSL_C7X_CPU_DBGCTXT_DBGCTXT_RESETVAL                    (0x00000000U)
#define CSL_C7X_CPU_DBGCTXT_DBGCTXT_MAX                         (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_DBGCTXT_RESETVAL                            (0x00000000U)

/* PC_PROF */

#define CSL_C7X_CPU_PC_PROF_PC_PROF_MASK                        (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_PC_PROF_PC_PROF_SHIFT                       (0U)
#define CSL_C7X_CPU_PC_PROF_PC_PROF_RESETVAL                    (0x00000000U)
#define CSL_C7X_CPU_PC_PROF_PC_PROF_MAX                         (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_PC_PROF_RESETVAL                            (0x00000000U)

/* GPLY */

#define CSL_C7X_CPU_GPLY_RSVD0_MASK                             (0xFFFFFFFF00000000U)
#define CSL_C7X_CPU_GPLY_RSVD0_SHIFT                            (32U)
#define CSL_C7X_CPU_GPLY_RSVD0_RESETVAL                         (0x00000000U)
#define CSL_C7X_CPU_GPLY_RSVD0_MAX                              (0xFFFFFFFFU)

#define CSL_C7X_CPU_GPLY_GPLY_MASK                              (0xFFFFFFFFU)
#define CSL_C7X_CPU_GPLY_GPLY_SHIFT                             (0U)
#define CSL_C7X_CPU_GPLY_GPLY_RESETVAL                          (0x00000000U)
#define CSL_C7X_CPU_GPLY_GPLY_MAX                               (0xFFFFFFFFU)

#define CSL_C7X_CPU_GPLY_RESETVAL                               (0x00000000U)

/* GFPGFR */

#define CSL_C7X_CPU_GFPGFR_RSVD0_MASK                           (0xFFFFFFF800000000U)
#define CSL_C7X_CPU_GFPGFR_RSVD0_SHIFT                          (35U)
#define CSL_C7X_CPU_GFPGFR_RSVD0_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_GFPGFR_RSVD0_MAX                            (0x1fffffffU)

#define CSL_C7X_CPU_GFPGFR_SIZE_MASK                            (0x700000000U)
#define CSL_C7X_CPU_GFPGFR_SIZE_SHIFT                           (32U)
#define CSL_C7X_CPU_GFPGFR_SIZE_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_GFPGFR_SIZE_MAX                             (0x00000007U)

#define CSL_C7X_CPU_GFPGFR_RSVD1_MASK                           (0xFFFFFF00U)
#define CSL_C7X_CPU_GFPGFR_RSVD1_SHIFT                          (8U)
#define CSL_C7X_CPU_GFPGFR_RSVD1_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_GFPGFR_RSVD1_MAX                            (0x00ffffffU)

#define CSL_C7X_CPU_GFPGFR_POLY_MASK                            (0x000000FFU)
#define CSL_C7X_CPU_GFPGFR_POLY_SHIFT                           (0U)
#define CSL_C7X_CPU_GFPGFR_POLY_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_GFPGFR_POLY_MAX                             (0x000000ffU)

#define CSL_C7X_CPU_GFPGFR_RESETVAL                             (0x00000000U)

/* CUCR0 */

#define CSL_C7X_CPU_CUCR0_RESETVAL                              (0x00000000U)

/* CUCR1 */

#define CSL_C7X_CPU_CUCR1_RESETVAL                              (0x00000000U)

/* CUCR2 */

#define CSL_C7X_CPU_CUCR2_RESETVAL                              (0x00000000U)

/* CUCR3 */

#define CSL_C7X_CPU_CUCR3_RESETVAL                              (0x00000000U)

/* STRACR0 */

#define CSL_C7X_CPU_STRACR0_RESETVAL                            (0x00000000U)

/* STRACNTR0 */

#define CSL_C7X_CPU_STRACNTR0_RESETVAL                          (0x00000000U)

/* STRACR1 */

#define CSL_C7X_CPU_STRACR1_RESETVAL                            (0x00000000U)

/* STRACNTR1 */

#define CSL_C7X_CPU_STRACNTR1_RESETVAL                          (0x00000000U)

/* STRACR2 */

#define CSL_C7X_CPU_STRACR2_RESETVAL                            (0x00000000U)

/* STRACNTR2 */

#define CSL_C7X_CPU_STRACNTR2_RESETVAL                          (0x00000000U)

/* STRACR3 */

#define CSL_C7X_CPU_STRACR3_RESETVAL                            (0x00000000U)

/* STRACNTR3 */

#define CSL_C7X_CPU_STRACNTR3_RESETVAL                          (0x00000000U)

/* PC */

#define CSL_C7X_CPU_PC_PC_MASK                                  (0x1FFFFFFFFFFFFU)
#define CSL_C7X_CPU_PC_PC_SHIFT                                 (0U)
#define CSL_C7X_CPU_PC_PC_RESETVAL                              (0x00000000U)

#define CSL_C7X_CPU_PC_RESETVAL                                 (0x00000000U)

/* ILCNT */

#define CSL_C7X_CPU_ILCNT_ILCNT_MASK                            (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_ILCNT_ILCNT_SHIFT                           (0U)
#define CSL_C7X_CPU_ILCNT_ILCNT_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_ILCNT_ILCNT_MAX                             (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_ILCNT_RESETVAL                              (0x00000000U)

/* OLCNT */

#define CSL_C7X_CPU_OLCNT_OLCNT_MASK                            (0xFFFFFFFFFFFFFFFFU)
#define CSL_C7X_CPU_OLCNT_OLCNT_SHIFT                           (0U)
#define CSL_C7X_CPU_OLCNT_OLCNT_RESETVAL                        (0x00000000U)
#define CSL_C7X_CPU_OLCNT_OLCNT_MAX                             (0xFFFFFFFFFFFFFFFFU)

#define CSL_C7X_CPU_OLCNT_RESETVAL                              (0x00000000U)

/* LCNTFLG0 */

#define CSL_C7X_CPU_LCNTFLG0_RSVD0_MASK                         (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG0_RSVD0_SHIFT                        (1U)
#define CSL_C7X_CPU_LCNTFLG0_RSVD0_RESETVAL                     (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG0_FLG_MASK                           (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG0_FLG_SHIFT                          (0U)
#define CSL_C7X_CPU_LCNTFLG0_FLG_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG0_FLG_MAX                            (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG0_RESETVAL                           (0x00000000U)

/* LCNTFLG1 */

#define CSL_C7X_CPU_LCNTFLG1_RSVD0_MASK                         (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG1_RSVD0_SHIFT                        (1U)
#define CSL_C7X_CPU_LCNTFLG1_RSVD0_RESETVAL                     (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG1_FLG_MASK                           (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG1_FLG_SHIFT                          (0U)
#define CSL_C7X_CPU_LCNTFLG1_FLG_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG1_FLG_MAX                            (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG1_RESETVAL                           (0x00000000U)

/* LCNTFLG2 */

#define CSL_C7X_CPU_LCNTFLG2_RSVD0_MASK                         (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG2_RSVD0_SHIFT                        (1U)
#define CSL_C7X_CPU_LCNTFLG2_RSVD0_RESETVAL                     (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG2_FLG_MASK                           (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG2_FLG_SHIFT                          (0U)
#define CSL_C7X_CPU_LCNTFLG2_FLG_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG2_FLG_MAX                            (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG2_RESETVAL                           (0x00000000U)

/* LCNTFLG3 */

#define CSL_C7X_CPU_LCNTFLG3_RSVD0_MASK                         (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG3_RSVD0_SHIFT                        (1U)
#define CSL_C7X_CPU_LCNTFLG3_RSVD0_RESETVAL                     (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG3_FLG_MASK                           (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG3_FLG_SHIFT                          (0U)
#define CSL_C7X_CPU_LCNTFLG3_FLG_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG3_FLG_MAX                            (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG3_RESETVAL                           (0x00000000U)

/* LCNTFLG4 */

#define CSL_C7X_CPU_LCNTFLG4_RSVD0_MASK                         (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG4_RSVD0_SHIFT                        (1U)
#define CSL_C7X_CPU_LCNTFLG4_RSVD0_RESETVAL                     (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG4_FLG_MASK                           (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG4_FLG_SHIFT                          (0U)
#define CSL_C7X_CPU_LCNTFLG4_FLG_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG4_FLG_MAX                            (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG4_RESETVAL                           (0x00000000U)

/* LCNTFLG5 */

#define CSL_C7X_CPU_LCNTFLG5_RSVD0_MASK                         (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG5_RSVD0_SHIFT                        (1U)
#define CSL_C7X_CPU_LCNTFLG5_RSVD0_RESETVAL                     (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG5_FLG_MASK                           (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG5_FLG_SHIFT                          (0U)
#define CSL_C7X_CPU_LCNTFLG5_FLG_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG5_FLG_MAX                            (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG5_RESETVAL                           (0x00000000U)

/* LCNTFLG6 */

#define CSL_C7X_CPU_LCNTFLG6_RSVD0_MASK                         (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG6_RSVD0_SHIFT                        (1U)
#define CSL_C7X_CPU_LCNTFLG6_RSVD0_RESETVAL                     (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG6_FLG_MASK                           (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG6_FLG_SHIFT                          (0U)
#define CSL_C7X_CPU_LCNTFLG6_FLG_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG6_FLG_MAX                            (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG6_RESETVAL                           (0x00000000U)

/* LCNTFLG7 */

#define CSL_C7X_CPU_LCNTFLG7_RSVD0_MASK                         (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG7_RSVD0_SHIFT                        (1U)
#define CSL_C7X_CPU_LCNTFLG7_RSVD0_RESETVAL                     (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG7_FLG_MASK                           (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG7_FLG_SHIFT                          (0U)
#define CSL_C7X_CPU_LCNTFLG7_FLG_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG7_FLG_MAX                            (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG7_RESETVAL                           (0x00000000U)

/* LCNTFLG8 */

#define CSL_C7X_CPU_LCNTFLG8_RSVD0_MASK                         (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG8_RSVD0_SHIFT                        (1U)
#define CSL_C7X_CPU_LCNTFLG8_RSVD0_RESETVAL                     (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG8_FLG_MASK                           (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG8_FLG_SHIFT                          (0U)
#define CSL_C7X_CPU_LCNTFLG8_FLG_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG8_FLG_MAX                            (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG8_RESETVAL                           (0x00000000U)

/* LCNTFLG9 */

#define CSL_C7X_CPU_LCNTFLG9_RSVD0_MASK                         (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG9_RSVD0_SHIFT                        (1U)
#define CSL_C7X_CPU_LCNTFLG9_RSVD0_RESETVAL                     (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG9_FLG_MASK                           (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG9_FLG_SHIFT                          (0U)
#define CSL_C7X_CPU_LCNTFLG9_FLG_RESETVAL                       (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG9_FLG_MAX                            (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG9_RESETVAL                           (0x00000000U)

/* LCNTFLG10 */

#define CSL_C7X_CPU_LCNTFLG10_RSVD0_MASK                        (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG10_RSVD0_SHIFT                       (1U)
#define CSL_C7X_CPU_LCNTFLG10_RSVD0_RESETVAL                    (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG10_FLG_MASK                          (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG10_FLG_SHIFT                         (0U)
#define CSL_C7X_CPU_LCNTFLG10_FLG_RESETVAL                      (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG10_FLG_MAX                           (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG10_RESETVAL                          (0x00000000U)

/* LCNTFLG11 */

#define CSL_C7X_CPU_LCNTFLG11_RSVD0_MASK                        (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG11_RSVD0_SHIFT                       (1U)
#define CSL_C7X_CPU_LCNTFLG11_RSVD0_RESETVAL                    (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG11_FLG_MASK                          (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG11_FLG_SHIFT                         (0U)
#define CSL_C7X_CPU_LCNTFLG11_FLG_RESETVAL                      (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG11_FLG_MAX                           (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG11_RESETVAL                          (0x00000000U)

/* LCNTFLG12 */

#define CSL_C7X_CPU_LCNTFLG12_RSVD0_MASK                        (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG12_RSVD0_SHIFT                       (1U)
#define CSL_C7X_CPU_LCNTFLG12_RSVD0_RESETVAL                    (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG12_FLG_MASK                          (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG12_FLG_SHIFT                         (0U)
#define CSL_C7X_CPU_LCNTFLG12_FLG_RESETVAL                      (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG12_FLG_MAX                           (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG12_RESETVAL                          (0x00000000U)

/* LCNTFLG13 */

#define CSL_C7X_CPU_LCNTFLG13_RSVD0_MASK                        (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG13_RSVD0_SHIFT                       (1U)
#define CSL_C7X_CPU_LCNTFLG13_RSVD0_RESETVAL                    (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG13_FLG_MASK                          (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG13_FLG_SHIFT                         (0U)
#define CSL_C7X_CPU_LCNTFLG13_FLG_RESETVAL                      (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG13_FLG_MAX                           (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG13_RESETVAL                          (0x00000000U)

/* LCNTFLG14 */

#define CSL_C7X_CPU_LCNTFLG14_RSVD0_MASK                        (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG14_RSVD0_SHIFT                       (1U)
#define CSL_C7X_CPU_LCNTFLG14_RSVD0_RESETVAL                    (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG14_FLG_MASK                          (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG14_FLG_SHIFT                         (0U)
#define CSL_C7X_CPU_LCNTFLG14_FLG_RESETVAL                      (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG14_FLG_MAX                           (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG14_RESETVAL                          (0x00000000U)

/* LCNTFLG15 */

#define CSL_C7X_CPU_LCNTFLG15_RSVD0_MASK                        (0xFFFFFFFFFFFFFFFEU)
#define CSL_C7X_CPU_LCNTFLG15_RSVD0_SHIFT                       (1U)
#define CSL_C7X_CPU_LCNTFLG15_RSVD0_RESETVAL                    (0x00000000U)

#define CSL_C7X_CPU_LCNTFLG15_FLG_MASK                          (0x00000001U)
#define CSL_C7X_CPU_LCNTFLG15_FLG_SHIFT                         (0U)
#define CSL_C7X_CPU_LCNTFLG15_FLG_RESETVAL                      (0x00000000U)
#define CSL_C7X_CPU_LCNTFLG15_FLG_MAX                           (0x00000001U)

#define CSL_C7X_CPU_LCNTFLG15_RESETVAL                          (0x00000000U)

/* SCRB */

#define CSL_C7X_CPU_SCRB_RESETVAL                               (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
