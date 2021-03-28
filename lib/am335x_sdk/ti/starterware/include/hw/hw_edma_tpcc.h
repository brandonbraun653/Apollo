/*
* hw_edma_tpcc.h
*
* Register-level header file for EDMA_TPCC
*
* Copyright (C) 2013-2019 Texas Instruments Incorporated - http://www.ti.com/
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
#ifndef HW_EDMA_TPCC_H_
#define HW_EDMA_TPCC_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define EDMA_TPCC_PID                                           (0x0U)
#define EDMA_TPCC_CCCFG                                         (0x4U)
#define EDMA_TPCC_SYSCONFIG                                     (0x10U)
#define EDMA_TPCC_DCHMAP(n)                                     ((uint32_t)0x100U + ((n) * 0x4U))
#define EDMA_TPCC_DCHMAP_NUM_ELEMS                              (64U)
#define EDMA_TPCC_QCHMAP(n)                                     ((uint32_t)0x200U + ((n) * 0x4U))
#define EDMA_TPCC_QCHMAP_NUM_ELEMS                              (8U)
#define EDMA_TPCC_DMAQNUM(n)                                    ((uint32_t)0x240U + ((n) * 0x4U))
#define EDMA_TPCC_DMAQNUM_NUM_ELEMS                             (8U)
#define EDMA_TPCC_QDMAQNUM                                      (0x260U)
#define EDMA_TPCC_QUEPRI                                        (0x284U)
#define EDMA_TPCC_EMR                                           (0x300U)
#define EDMA_TPCC_EMRH                                          (0x304U)
#define EDMA_TPCC_EMCR                                          (0x308U)
#define EDMA_TPCC_EMCRH                                         (0x30cU)
#define EDMA_TPCC_QEMR                                          (0x310U)
#define EDMA_TPCC_QEMCR                                         (0x314U)
#define EDMA_TPCC_CCERR                                         (0x318U)
#define EDMA_TPCC_CCERRCLR                                      (0x31cU)
#define EDMA_TPCC_EEVAL                                         (0x320U)
#define EDMA_TPCC_DRAE0                                         (0x340U)
#define EDMA_TPCC_DRAEH0                                        (0x344U)
#define EDMA_TPCC_DRAE1                                         (0x348U)
#define EDMA_TPCC_DRAEH1                                        (0x34cU)
#define EDMA_TPCC_DRAE2                                         (0x350U)
#define EDMA_TPCC_DRAEH2                                        (0x354U)
#define EDMA_TPCC_DRAE3                                         (0x358U)
#define EDMA_TPCC_DRAEH3                                        (0x35cU)
#define EDMA_TPCC_DRAE4                                         (0x360U)
#define EDMA_TPCC_DRAEH4                                        (0x364U)
#define EDMA_TPCC_DRAE5                                         (0x368U)
#define EDMA_TPCC_DRAEH5                                        (0x36cU)
#define EDMA_TPCC_DRAE6                                         (0x370U)
#define EDMA_TPCC_DRAEH6                                        (0x374U)
#define EDMA_TPCC_DRAE7                                         (0x378U)
#define EDMA_TPCC_DRAEH7                                        (0x37cU)
#define EDMA_TPCC_QRAE(n)                                       ((uint32_t)0x380U + ((n) * 0x4U))
#define EDMA_TPCC_QRAE_NUM_ELEMS                                (8U)
#define EDMA_TPCC_Q0E(n)                                        ((uint32_t)0x400U + ((n) * 0x4U))
#define EDMA_TPCC_Q0E_NUM_ELEMS                                 (16U)
#define EDMA_TPCC_Q1E(n)                                        ((uint32_t)0x440U + ((n) * 0x4U))
#define EDMA_TPCC_Q1E_NUM_ELEMS                                 (16U)
#define EDMA_TPCC_Q2E(n)                                        ((uint32_t)0x480U + ((n) * 0x4U))
#define EDMA_TPCC_Q2E_NUM_ELEMS                                 (16U)
#define EDMA_TPCC_QSTAT(n)                                      ((uint32_t)0x600U + ((n) * 0x4U))
#define EDMA_TPCC_QSTAT_NUM_ELEMS                               (3U)
#define EDMA_TPCC_QWMTHRA                                       (0x620U)
#define EDMA_TPCC_CCSTAT                                        (0x640U)
#define EDMA_TPCC_MPFAR                                         (0x800U)
#define EDMA_TPCC_MPFSR                                         (0x804U)
#define EDMA_TPCC_MPFCR                                         (0x808U)
#define EDMA_TPCC_MPPAG                                         (0x80cU)
#define EDMA_TPCC_MPPA(n)                                       ((uint32_t)0x810U + ((n) * 0x4U))
#define EDMA_TPCC_MPPA_NUM_ELEMS                                (8U)
#define EDMA_TPCC_ER                                            (0x1000U)
#define EDMA_TPCC_ERH                                           (0x1004U)
#define EDMA_TPCC_ECR                                           (0x1008U)
#define EDMA_TPCC_ECRH                                          (0x100cU)
#define EDMA_TPCC_ESR                                           (0x1010U)
#define EDMA_TPCC_ESRH                                          (0x1014U)
#define EDMA_TPCC_CER                                           (0x1018U)
#define EDMA_TPCC_CERH                                          (0x101cU)
#define EDMA_TPCC_EER                                           (0x1020U)
#define EDMA_TPCC_EERH                                          (0x1024U)
#define EDMA_TPCC_EECR                                          (0x1028U)
#define EDMA_TPCC_EECRH                                         (0x102cU)
#define EDMA_TPCC_EESR                                          (0x1030U)
#define EDMA_TPCC_EESRH                                         (0x1034U)
#define EDMA_TPCC_SER                                           (0x1038U)
#define EDMA_TPCC_SERH                                          (0x103cU)
#define EDMA_TPCC_SECR                                          (0x1040U)
#define EDMA_TPCC_SECRH                                         (0x1044U)
#define EDMA_TPCC_IER                                           (0x1050U)
#define EDMA_TPCC_IERH                                          (0x1054U)
#define EDMA_TPCC_IECR                                          (0x1058U)
#define EDMA_TPCC_IECRH                                         (0x105cU)
#define EDMA_TPCC_IESR                                          (0x1060U)
#define EDMA_TPCC_IESRH                                         (0x1064U)
#define EDMA_TPCC_IPR                                           (0x1068U)
#define EDMA_TPCC_IPRH                                          (0x106cU)
#define EDMA_TPCC_ICR                                           (0x1070U)
#define EDMA_TPCC_ICRH                                          (0x1074U)
#define EDMA_TPCC_IEVAL                                         (0x1078U)
#define EDMA_TPCC_QER                                           (0x1080U)
#define EDMA_TPCC_QEER                                          (0x1084U)
#define EDMA_TPCC_QEECR                                         (0x1088U)
#define EDMA_TPCC_QEESR                                         (0x108cU)
#define EDMA_TPCC_QSER                                          (0x1090U)
#define EDMA_TPCC_QSECR                                         (0x1094U)
#define EDMA_TPCC_S_ER(m)                                       ((uint32_t)0x2000U + ((m) * 0x200U))
#define EDMA_TPCC_S_ER_NUM_ELEMS                                (7U)
#define EDMA_TPCC_S_ERH(m)                                      ((uint32_t)0x2004U + ((m) * 0x200U))
#define EDMA_TPCC_S_ERH_NUM_ELEMS                               (7U)
#define EDMA_TPCC_S_ECR(m)                                      ((uint32_t)0x2008U + ((m) * 0x200U))
#define EDMA_TPCC_S_ECR_NUM_ELEMS                               (7U)
#define EDMA_TPCC_S_ECRH(m)                                     ((uint32_t)0x200cU + ((m) * 0x200U))
#define EDMA_TPCC_S_ECRH_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_ESR(m)                                      ((uint32_t)0x2010U + ((m) * 0x200U))
#define EDMA_TPCC_S_ESR_NUM_ELEMS                               (7U)
#define EDMA_TPCC_S_ESRH(m)                                     ((uint32_t)0x2014U + ((m) * 0x200U))
#define EDMA_TPCC_S_ESRH_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_CER(m)                                      ((uint32_t)0x2018U + ((m) * 0x200U))
#define EDMA_TPCC_S_CER_NUM_ELEMS                               (7U)
#define EDMA_TPCC_S_CERH(m)                                     ((uint32_t)0x201cU + ((m) * 0x200U))
#define EDMA_TPCC_S_CERH_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_EER(m)                                      ((uint32_t)0x2020U + ((m) * 0x200U))
#define EDMA_TPCC_S_EER_NUM_ELEMS                               (7U)
#define EDMA_TPCC_S_EERH(m)                                     ((uint32_t)0x2024U + ((m) * 0x200U))
#define EDMA_TPCC_S_EERH_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_EECR(m)                                     ((uint32_t)0x2028U + ((m) * 0x200U))
#define EDMA_TPCC_S_EECR_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_EECRH(m)                                    ((uint32_t)0x202cU + ((m) * 0x200U))
#define EDMA_TPCC_S_EECRH_NUM_ELEMS                             (7U)
#define EDMA_TPCC_S_EESR(m)                                     ((uint32_t)0x2030U + ((m) * 0x200U))
#define EDMA_TPCC_S_EESR_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_EESRH(m)                                    ((uint32_t)0x2034U + ((m) * 0x200U))
#define EDMA_TPCC_S_EESRH_NUM_ELEMS                             (7U)
#define EDMA_TPCC_S_SER(m)                                      ((uint32_t)0x2038U + ((m) * 0x200U))
#define EDMA_TPCC_S_SER_NUM_ELEMS                               (7U)
#define EDMA_TPCC_S_SERH(m)                                     ((uint32_t)0x203cU + ((m) * 0x200U))
#define EDMA_TPCC_S_SERH_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_SECR(m)                                     ((uint32_t)0x2040U + ((m) * 0x200U))
#define EDMA_TPCC_S_SECR_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_SECRH(m)                                    ((uint32_t)0x2044U + ((m) * 0x200U))
#define EDMA_TPCC_S_SECRH_NUM_ELEMS                             (7U)
#define EDMA_TPCC_S_IER(m)                                      ((uint32_t)0x2050U + ((m) * 0x200U))
#define EDMA_TPCC_S_IER_NUM_ELEMS                               (7U)
#define EDMA_TPCC_S_IERH(m)                                     ((uint32_t)0x2054U + ((m) * 0x200U))
#define EDMA_TPCC_S_IERH_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_IECR(m)                                     ((uint32_t)0x2058U + ((m) * 0x200U))
#define EDMA_TPCC_S_IECR_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_IECRH(m)                                    ((uint32_t)0x205cU + ((m) * 0x200U))
#define EDMA_TPCC_S_IECRH_NUM_ELEMS                             (7U)
#define EDMA_TPCC_S_IESR(m)                                     ((uint32_t)0x2060U + ((m) * 0x200U))
#define EDMA_TPCC_S_IESR_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_IESRH(m)                                    ((uint32_t)0x2064U + ((m) * 0x200U))
#define EDMA_TPCC_S_IESRH_NUM_ELEMS                             (7U)
#define EDMA_TPCC_S_IPR(m)                                      ((uint32_t)0x2068U + ((m) * 0x200U))
#define EDMA_TPCC_S_IPR_NUM_ELEMS                               (7U)
#define EDMA_TPCC_S_IPRH(m)                                     ((uint32_t)0x206cU + ((m) * 0x200U))
#define EDMA_TPCC_S_IPRH_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_ICR(m)                                      ((uint32_t)0x2070U + ((m) * 0x200U))
#define EDMA_TPCC_S_ICR_NUM_ELEMS                               (7U)
#define EDMA_TPCC_S_ICRH(m)                                     ((uint32_t)0x2074U + ((m) * 0x200U))
#define EDMA_TPCC_S_ICRH_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_IEVAL(m)                                    ((uint32_t)0x2078U + ((m) * 0x200U))
#define EDMA_TPCC_S_IEVAL_NUM_ELEMS                             (7U)
#define EDMA_TPCC_S_QER(m)                                      ((uint32_t)0x2080U + ((m) * 0x200U))
#define EDMA_TPCC_S_QER_NUM_ELEMS                               (7U)
#define EDMA_TPCC_S_QEER(m)                                     ((uint32_t)0x2084U + ((m) * 0x200U))
#define EDMA_TPCC_S_QEER_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_QEECR(m)                                    ((uint32_t)0x2088U + ((m) * 0x200U))
#define EDMA_TPCC_S_QEECR_NUM_ELEMS                             (7U)
#define EDMA_TPCC_S_QEESR(m)                                    ((uint32_t)0x208cU + ((m) * 0x200U))
#define EDMA_TPCC_S_QEESR_NUM_ELEMS                             (7U)
#define EDMA_TPCC_S_QSER(m)                                     ((uint32_t)0x2090U + ((m) * 0x200U))
#define EDMA_TPCC_S_QSER_NUM_ELEMS                              (7U)
#define EDMA_TPCC_S_QSECR(m)                                    ((uint32_t)0x2094U + ((m) * 0x200U))
#define EDMA_TPCC_S_QSECR_NUM_ELEMS                             (7U)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define EDMA_TPCC_PID_SHIFT                                     (0U)
#define EDMA_TPCC_PID_MASK                                      (0x0000ffffU)

#define EDMA_TPCC_CCCFG_NUM_DMACH_SHIFT                         (0U)
#define EDMA_TPCC_CCCFG_NUM_DMACH_MASK                          (0x00000007U)
#define EDMA_TPCC_CCCFG_NUM_DMACH_RESERVED1                      (0U)
#define EDMA_TPCC_CCCFG_NUM_DMACH_RESERVED2                      (4U)
#define EDMA_TPCC_CCCFG_NUM_DMACH_CH_64                          (5U)
#define EDMA_TPCC_CCCFG_NUM_DMACH_RESERVED3                      (6U)
#define EDMA_TPCC_CCCFG_NUM_DMACH_RESERVED4                      (7U)

#define EDMA_TPCC_CCCFG_NUM_QDMACH_SHIFT                        (4U)
#define EDMA_TPCC_CCCFG_NUM_QDMACH_MASK                         (0x00000070U)
#define EDMA_TPCC_CCCFG_NUM_QDMACH_RESERVED1                     (0U)
#define EDMA_TPCC_CCCFG_NUM_QDMACH_RESERVED2                     (3U)
#define EDMA_TPCC_CCCFG_NUM_QDMACH_CH_8                          (4U)
#define EDMA_TPCC_CCCFG_NUM_QDMACH_RESERVED3                     (5U)
#define EDMA_TPCC_CCCFG_NUM_QDMACH_RESERVED4                     (7U)

#define EDMA_TPCC_CCCFG_NUM_INTCH_SHIFT                         (8U)
#define EDMA_TPCC_CCCFG_NUM_INTCH_MASK                          (0x00000700U)
#define EDMA_TPCC_CCCFG_NUM_INTCH_RESERVED1                      (0U)
#define EDMA_TPCC_CCCFG_NUM_INTCH_RESERVED2                      (3U)
#define EDMA_TPCC_CCCFG_NUM_INTCH_CH_64                          (4U)
#define EDMA_TPCC_CCCFG_NUM_INTCH_RESERVED3                      (5U)
#define EDMA_TPCC_CCCFG_NUM_INTCH_RESERVED4                      (7U)

#define EDMA_TPCC_CCCFG_NUM_PAENTRY_SHIFT                       (12U)
#define EDMA_TPCC_CCCFG_NUM_PAENTRY_MASK                        (0x00007000U)
#define EDMA_TPCC_CCCFG_NUM_PAENTRY_RESERVED1                    (0U)
#define EDMA_TPCC_CCCFG_NUM_PAENTRY_RESERVED2                    (3U)
#define EDMA_TPCC_CCCFG_NUM_PAENTRY_PARAM_256                    (4U)
#define EDMA_TPCC_CCCFG_NUM_PAENTRY_RESERVED3                    (5U)
#define EDMA_TPCC_CCCFG_NUM_PAENTRY_RESERVED4                    (7U)

#define EDMA_TPCC_CCCFG_NUM_EVQUE_SHIFT                         (16U)
#define EDMA_TPCC_CCCFG_NUM_EVQUE_MASK                          (0x00070000U)
#define EDMA_TPCC_CCCFG_NUM_EVQUE_RESERVED1                      (0U)
#define EDMA_TPCC_CCCFG_NUM_EVQUE_RESERVED2                      (1U)
#define EDMA_TPCC_CCCFG_NUM_EVQUE_QUEUE_3                        (2U)
#define EDMA_TPCC_CCCFG_NUM_EVQUE_RESERVED3                      (3U)
#define EDMA_TPCC_CCCFG_NUM_EVQUE_RESERVED4                      (7U)

#define EDMA_TPCC_CCCFG_NUM_REGN_SHIFT                          (20U)
#define EDMA_TPCC_CCCFG_NUM_REGN_MASK                           (0x00300000U)
#define EDMA_TPCC_CCCFG_NUM_REGN_RESERVED1                       (0U)
#define EDMA_TPCC_CCCFG_NUM_REGN_RESERVED2                       (1U)
#define EDMA_TPCC_CCCFG_NUM_REGN_REG_4                           (2U)
#define EDMA_TPCC_CCCFG_NUM_REGN_RESERVED3                       (3U)

#define EDMA_TPCC_CCCFG_CHMAP_EXIST_SHIFT                       (24U)
#define EDMA_TPCC_CCCFG_CHMAP_EXIST_MASK                        (0x01000000U)
#define EDMA_TPCC_CCCFG_CHMAP_EXIST_RESERVED                     (0U)
#define EDMA_TPCC_CCCFG_CHMAP_EXIST_TRUE                         (1U)

#define EDMA_TPCC_CCCFG_MP_EXIST_SHIFT                          (25U)
#define EDMA_TPCC_CCCFG_MP_EXIST_MASK                           (0x02000000U)
#define EDMA_TPCC_CCCFG_MP_EXIST_RESERVED                        (0U)
#define EDMA_TPCC_CCCFG_MP_EXIST_TRUE                            (1U)

#define EDMA_TPCC_SYSCONFIG_IDLEMODE_SHIFT                      (2U)
#define EDMA_TPCC_SYSCONFIG_IDLEMODE_MASK                       (0x0000000cU)
#define EDMA_TPCC_SYSCONFIG_IDLEMODE_FORCE_IDLE                  (0U)
#define EDMA_TPCC_SYSCONFIG_IDLEMODE_NO_IDLE                     (1U)
#define EDMA_TPCC_SYSCONFIG_IDLEMODE_SMART_IDLE                  (2U)
#define EDMA_TPCC_SYSCONFIG_IDLEMODE_SMART_IDLE_WAKEUP           (3U)

#define EDMA_TPCC_DCHMAP_PAENTRY_SHIFT                          (5U)
#define EDMA_TPCC_DCHMAP_PAENTRY_MASK                           (0x00003fe0U)

#define EDMA_TPCC_QCHMAP_TRWORD_SHIFT                           (2U)
#define EDMA_TPCC_QCHMAP_TRWORD_MASK                            (0x0000001cU)

#define EDMA_TPCC_QCHMAP_PAENTRY_SHIFT                          (5U)
#define EDMA_TPCC_QCHMAP_PAENTRY_MASK                           (0x00003fe0U)
#define EDMA_TPCC_QCHMAP_PAENTRY_ENTRY                           (0U)
#define EDMA_TPCC_QCHMAP_PAENTRY_RESERVED                        (1U)

#define EDMA_TPCC_DMAQNUM_E0_SHIFT                              (0U)
#define EDMA_TPCC_DMAQNUM_E0_MASK                               (0x00000007U)
#define EDMA_TPCC_DMAQNUM_E0_Q0                                  (0U)
#define EDMA_TPCC_DMAQNUM_E0_Q1                                  (1U)
#define EDMA_TPCC_DMAQNUM_E0_Q2                                  (2U)
#define EDMA_TPCC_DMAQNUM_E0_RESERVED1                           (3U)
#define EDMA_TPCC_DMAQNUM_E0_RESERVED2                           (7U)

#define EDMA_TPCC_DMAQNUM_E1_SHIFT                              (4U)
#define EDMA_TPCC_DMAQNUM_E1_MASK                               (0x00000070U)
#define EDMA_TPCC_DMAQNUM_E1_Q0                                  (0U)
#define EDMA_TPCC_DMAQNUM_E1_Q1                                  (1U)
#define EDMA_TPCC_DMAQNUM_E1_Q2                                  (2U)
#define EDMA_TPCC_DMAQNUM_E1_RESERVED1                           (3U)
#define EDMA_TPCC_DMAQNUM_E1_RESERVED2                           (7U)

#define EDMA_TPCC_DMAQNUM_E2_SHIFT                              (8U)
#define EDMA_TPCC_DMAQNUM_E2_MASK                               (0x00000700U)
#define EDMA_TPCC_DMAQNUM_E2_Q0                                  (0U)
#define EDMA_TPCC_DMAQNUM_E2_Q1                                  (1U)
#define EDMA_TPCC_DMAQNUM_E2_Q2                                  (2U)
#define EDMA_TPCC_DMAQNUM_E2_RESERVED1                           (3U)
#define EDMA_TPCC_DMAQNUM_E2_RESERVED2                           (7U)

#define EDMA_TPCC_DMAQNUM_E3_SHIFT                              (12U)
#define EDMA_TPCC_DMAQNUM_E3_MASK                               (0x00007000U)
#define EDMA_TPCC_DMAQNUM_E3_Q0                                  (0U)
#define EDMA_TPCC_DMAQNUM_E3_Q1                                  (1U)
#define EDMA_TPCC_DMAQNUM_E3_Q2                                  (2U)
#define EDMA_TPCC_DMAQNUM_E3_RESERVED1                           (3U)
#define EDMA_TPCC_DMAQNUM_E3_RESERVED2                           (7U)

#define EDMA_TPCC_DMAQNUM_E4_SHIFT                              (16U)
#define EDMA_TPCC_DMAQNUM_E4_MASK                               (0x00070000U)
#define EDMA_TPCC_DMAQNUM_E4_Q0                                  (0U)
#define EDMA_TPCC_DMAQNUM_E4_Q1                                  (1U)
#define EDMA_TPCC_DMAQNUM_E4_Q2                                  (2U)
#define EDMA_TPCC_DMAQNUM_E4_RESERVED1                           (3U)
#define EDMA_TPCC_DMAQNUM_E4_RESERVED2                           (7U)

#define EDMA_TPCC_DMAQNUM_E5_SHIFT                              (20U)
#define EDMA_TPCC_DMAQNUM_E5_MASK                               (0x00700000U)
#define EDMA_TPCC_DMAQNUM_E5_Q0                                  (0U)
#define EDMA_TPCC_DMAQNUM_E5_Q1                                  (1U)
#define EDMA_TPCC_DMAQNUM_E5_Q2                                  (2U)
#define EDMA_TPCC_DMAQNUM_E5_RESERVED1                           (3U)
#define EDMA_TPCC_DMAQNUM_E5_RESERVED2                           (7U)

#define EDMA_TPCC_DMAQNUM_E6_SHIFT                              (24U)
#define EDMA_TPCC_DMAQNUM_E6_MASK                               (0x07000000U)
#define EDMA_TPCC_DMAQNUM_E6_Q0                                  (0U)
#define EDMA_TPCC_DMAQNUM_E6_Q1                                  (1U)
#define EDMA_TPCC_DMAQNUM_E6_Q2                                  (2U)
#define EDMA_TPCC_DMAQNUM_E6_RESERVED1                           (3U)
#define EDMA_TPCC_DMAQNUM_E6_RESERVED2                           (7U)

#define EDMA_TPCC_DMAQNUM_E7_SHIFT                              (28U)
#define EDMA_TPCC_DMAQNUM_E7_MASK                               (0x70000000U)
#define EDMA_TPCC_DMAQNUM_E7_Q0                                  (0U)
#define EDMA_TPCC_DMAQNUM_E7_Q1                                  (1U)
#define EDMA_TPCC_DMAQNUM_E7_Q2                                  (2U)
#define EDMA_TPCC_DMAQNUM_E7_RESERVED1                           (3U)
#define EDMA_TPCC_DMAQNUM_E7_RESERVED2                           (7U)

#define EDMA_TPCC_QDMAQNUM_E0_SHIFT                             (0U)
#define EDMA_TPCC_QDMAQNUM_E0_MASK                              (0x00000007U)
#define EDMA_TPCC_QDMAQNUM_E0_Q0                                 (0U)
#define EDMA_TPCC_QDMAQNUM_E0_Q1                                 (1U)
#define EDMA_TPCC_QDMAQNUM_E0_Q2                                 (2U)
#define EDMA_TPCC_QDMAQNUM_E0_RESERVED1                          (3U)
#define EDMA_TPCC_QDMAQNUM_E0_RESERVED2                          (7U)

#define EDMA_TPCC_QDMAQNUM_E1_SHIFT                             (4U)
#define EDMA_TPCC_QDMAQNUM_E1_MASK                              (0x00000070U)
#define EDMA_TPCC_QDMAQNUM_E1_Q0                                 (0U)
#define EDMA_TPCC_QDMAQNUM_E1_Q1                                 (1U)
#define EDMA_TPCC_QDMAQNUM_E1_Q2                                 (2U)
#define EDMA_TPCC_QDMAQNUM_E1_RESERVED1                          (3U)
#define EDMA_TPCC_QDMAQNUM_E1_RESERVED2                          (7U)

#define EDMA_TPCC_QDMAQNUM_E2_SHIFT                             (8U)
#define EDMA_TPCC_QDMAQNUM_E2_MASK                              (0x00000700U)
#define EDMA_TPCC_QDMAQNUM_E2_Q0                                 (0U)
#define EDMA_TPCC_QDMAQNUM_E2_Q1                                 (1U)
#define EDMA_TPCC_QDMAQNUM_E2_Q2                                 (2U)
#define EDMA_TPCC_QDMAQNUM_E2_RESERVED1                          (3U)
#define EDMA_TPCC_QDMAQNUM_E2_RESERVED2                          (7U)

#define EDMA_TPCC_QDMAQNUM_E3_SHIFT                             (12U)
#define EDMA_TPCC_QDMAQNUM_E3_MASK                              (0x00007000U)
#define EDMA_TPCC_QDMAQNUM_E3_Q0                                 (0U)
#define EDMA_TPCC_QDMAQNUM_E3_Q1                                 (1U)
#define EDMA_TPCC_QDMAQNUM_E3_Q2                                 (2U)
#define EDMA_TPCC_QDMAQNUM_E3_RESERVED1                          (3U)
#define EDMA_TPCC_QDMAQNUM_E3_RESERVED2                          (7U)

#define EDMA_TPCC_QDMAQNUM_E4_SHIFT                             (16U)
#define EDMA_TPCC_QDMAQNUM_E4_MASK                              (0x00070000U)
#define EDMA_TPCC_QDMAQNUM_E4_Q0                                 (0U)
#define EDMA_TPCC_QDMAQNUM_E4_Q1                                 (1U)
#define EDMA_TPCC_QDMAQNUM_E4_Q2                                 (2U)
#define EDMA_TPCC_QDMAQNUM_E4_RESERVED1                          (3U)
#define EDMA_TPCC_QDMAQNUM_E4_RESERVED2                          (7U)

#define EDMA_TPCC_QDMAQNUM_E5_SHIFT                             (20U)
#define EDMA_TPCC_QDMAQNUM_E5_MASK                              (0x00700000U)
#define EDMA_TPCC_QDMAQNUM_E5_Q0                                 (0U)
#define EDMA_TPCC_QDMAQNUM_E5_Q1                                 (1U)
#define EDMA_TPCC_QDMAQNUM_E5_Q2                                 (2U)
#define EDMA_TPCC_QDMAQNUM_E5_RESERVED1                          (3U)
#define EDMA_TPCC_QDMAQNUM_E5_RESERVED2                          (7U)

#define EDMA_TPCC_QDMAQNUM_E6_SHIFT                             (24U)
#define EDMA_TPCC_QDMAQNUM_E6_MASK                              (0x07000000U)
#define EDMA_TPCC_QDMAQNUM_E6_Q0                                 (0U)
#define EDMA_TPCC_QDMAQNUM_E6_Q1                                 (1U)
#define EDMA_TPCC_QDMAQNUM_E6_Q2                                 (2U)
#define EDMA_TPCC_QDMAQNUM_E6_RESERVED1                          (3U)
#define EDMA_TPCC_QDMAQNUM_E6_RESERVED2                          (7U)

#define EDMA_TPCC_QDMAQNUM_E7_SHIFT                             (28U)
#define EDMA_TPCC_QDMAQNUM_E7_MASK                              (0x70000000U)
#define EDMA_TPCC_QDMAQNUM_E7_Q0                                 (0U)
#define EDMA_TPCC_QDMAQNUM_E7_Q1                                 (1U)
#define EDMA_TPCC_QDMAQNUM_E7_Q2                                 (2U)
#define EDMA_TPCC_QDMAQNUM_E7_RESERVED1                          (3U)
#define EDMA_TPCC_QDMAQNUM_E7_RESERVED2                          (7U)

#define EDMA_TPCC_QUEPRI_PRIQ0_SHIFT                            (0U)
#define EDMA_TPCC_QUEPRI_PRIQ0_MASK                             (0x00000007U)

#define EDMA_TPCC_QUEPRI_PRIQ1_SHIFT                            (4U)
#define EDMA_TPCC_QUEPRI_PRIQ1_MASK                             (0x00000070U)

#define EDMA_TPCC_QUEPRI_PRIQ2_SHIFT                            (8U)
#define EDMA_TPCC_QUEPRI_PRIQ2_MASK                             (0x00000700U)

#define EDMA_TPCC_EMR_EN_SHIFT                                  (0U)
#define EDMA_TPCC_EMR_EN_MASK                                   (0xffffffffU)
#define EDMA_TPCC_EMR_EN_NO_MISSED                               (0U)
#define EDMA_TPCC_EMR_EN_MISSED                                  (1U)

#define EDMA_TPCC_EMRH_EN_SHIFT                                 (0U)
#define EDMA_TPCC_EMRH_EN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_EMRH_EN_NO_MISSED                              (0U)
#define EDMA_TPCC_EMRH_EN_MISSED                                 (1U)

#define EDMA_TPCC_EMCR_EN_SHIFT                                 (0U)
#define EDMA_TPCC_EMCR_EN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_EMCR_EN_NO_EFFECT                              (0U)
#define EDMA_TPCC_EMCR_EN_CLEARED                                (1U)

#define EDMA_TPCC_EMCRH_EN_SHIFT                                (0U)
#define EDMA_TPCC_EMCRH_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_EMCRH_EN_NO_EFFECT                             (0U)
#define EDMA_TPCC_EMCRH_EN_CLEARED                               (1U)

#define EDMA_TPCC_QEMR_EN_SHIFT                                 (0U)
#define EDMA_TPCC_QEMR_EN_MASK                                  (0x000000ffU)
#define EDMA_TPCC_QEMR_EN_NO_MISSED                              (0U)
#define EDMA_TPCC_QEMR_EN_MISSED                                 (1U)

#define EDMA_TPCC_QEMCR_EN_SHIFT                                (0U)
#define EDMA_TPCC_QEMCR_EN_MASK                                 (0x000000ffU)
#define EDMA_TPCC_QEMCR_EN_NO_EFFECT                             (0U)
#define EDMA_TPCC_QEMCR_EN_CLEARED                               (1U)

#define EDMA_TPCC_CCERR_QTHRXCD0_SHIFT                          (0U)
#define EDMA_TPCC_CCERR_QTHRXCD0_MASK                           (0x00000001U)
#define EDMA_TPCC_CCERR_QTHRXCD0_NOT_EXCEEDED                    (0U)
#define EDMA_TPCC_CCERR_QTHRXCD0_EXCEEDED                        (1U)

#define EDMA_TPCC_CCERR_QTHRXCD1_SHIFT                          (1U)
#define EDMA_TPCC_CCERR_QTHRXCD1_MASK                           (0x00000002U)
#define EDMA_TPCC_CCERR_QTHRXCD1_NOT_EXCEEDED                    (0U)
#define EDMA_TPCC_CCERR_QTHRXCD1_EXCEEDED                        (1U)

#define EDMA_TPCC_CCERR_QTHRXCD2_SHIFT                          (2U)
#define EDMA_TPCC_CCERR_QTHRXCD2_MASK                           (0x00000004U)
#define EDMA_TPCC_CCERR_QTHRXCD2_NOT_EXCEEDED                    (0U)
#define EDMA_TPCC_CCERR_QTHRXCD2_EXCEEDED                        (1U)

#define EDMA_TPCC_CCERR_TCCERR_SHIFT                            (16U)
#define EDMA_TPCC_CCERR_TCCERR_MASK                             (0x00010000U)
#define EDMA_TPCC_CCERR_TCCERR_NOT_REACHED                       (0U)
#define EDMA_TPCC_CCERR_TCCERR_REACHED                           (1U)

#define EDMA_TPCC_CCERRCLR_QTHRXCD0_SHIFT                       (0U)
#define EDMA_TPCC_CCERRCLR_QTHRXCD0_MASK                        (0x00000001U)
#define EDMA_TPCC_CCERRCLR_QTHRXCD0_NO_EFFECT                    (0U)
#define EDMA_TPCC_CCERRCLR_QTHRXCD0_CLEAR                        (1U)

#define EDMA_TPCC_CCERRCLR_QTHRXCD1_SHIFT                       (1U)
#define EDMA_TPCC_CCERRCLR_QTHRXCD1_MASK                        (0x00000002U)
#define EDMA_TPCC_CCERRCLR_QTHRXCD1_NO_EFFECT                    (0U)
#define EDMA_TPCC_CCERRCLR_QTHRXCD1_CLEAR                        (1U)

#define EDMA_TPCC_CCERRCLR_QTHRXCD2_SHIFT                       (2U)
#define EDMA_TPCC_CCERRCLR_QTHRXCD2_MASK                        (0x00000004U)
#define EDMA_TPCC_CCERRCLR_QTHRXCD2_NO_EFFECT                    (0U)
#define EDMA_TPCC_CCERRCLR_QTHRXCD2_CLEAR                        (1U)

#define EDMA_TPCC_CCERRCLR_QTHRXCD3_SHIFT                       (3U)
#define EDMA_TPCC_CCERRCLR_QTHRXCD3_MASK                        (0x00000008U)
#define EDMA_TPCC_CCERRCLR_QTHRXCD3_NO_EFFECT                    (0U)
#define EDMA_TPCC_CCERRCLR_QTHRXCD3_CLEAR                        (1U)

#define EDMA_TPCC_CCERRCLR_TCCERR_SHIFT                         (16U)
#define EDMA_TPCC_CCERRCLR_TCCERR_MASK                          (0x00010000U)
#define EDMA_TPCC_CCERRCLR_TCCERR_NO_EFFECT                      (0U)
#define EDMA_TPCC_CCERRCLR_TCCERR_CLEAR                          (1U)

#define EDMA_TPCC_EEVAL_EVAL_SHIFT                              (0U)
#define EDMA_TPCC_EEVAL_EVAL_MASK                               (0x00000001U)
#define EDMA_TPCC_EEVAL_EVAL_NO_EFFECT                           (0U)
#define EDMA_TPCC_EEVAL_EVAL_CLEAR                               (1U)

#define EDMA_TPCC_DRAE0_EN_SHIFT                                (0U)
#define EDMA_TPCC_DRAE0_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_DRAE0_EN_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_DRAE0_EN_ALLOWED                               (1U)

#define EDMA_TPCC_DRAEH0_EN_SHIFT                               (0U)
#define EDMA_TPCC_DRAEH0_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_DRAEH0_EN_NOT_ALLOWED                          (0U)
#define EDMA_TPCC_DRAEH0_EN_ALLOWED                              (1U)

#define EDMA_TPCC_DRAE1_EN_SHIFT                                (0U)
#define EDMA_TPCC_DRAE1_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_DRAE1_EN_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_DRAE1_EN_ALLOWED                               (1U)

#define EDMA_TPCC_DRAEH1_EN_SHIFT                               (0U)
#define EDMA_TPCC_DRAEH1_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_DRAEH1_EN_NOT_ALLOWED                          (0U)
#define EDMA_TPCC_DRAEH1_EN_ALLOWED                              (1U)

#define EDMA_TPCC_DRAE2_EN_SHIFT                                (0U)
#define EDMA_TPCC_DRAE2_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_DRAE2_EN_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_DRAE2_EN_ALLOWED                               (1U)

#define EDMA_TPCC_DRAEH2_EN_SHIFT                               (0U)
#define EDMA_TPCC_DRAEH2_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_DRAEH2_EN_NOT_ALLOWED                          (0U)
#define EDMA_TPCC_DRAEH2_EN_ALLOWED                              (1U)

#define EDMA_TPCC_DRAE3_EN_SHIFT                                (0U)
#define EDMA_TPCC_DRAE3_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_DRAE3_EN_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_DRAE3_EN_ALLOWED                               (1U)

#define EDMA_TPCC_DRAEH3_EN_SHIFT                               (0U)
#define EDMA_TPCC_DRAEH3_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_DRAEH3_EN_NOT_ALLOWED                          (0U)
#define EDMA_TPCC_DRAEH3_EN_ALLOWED                              (1U)

#define EDMA_TPCC_DRAE4_EN_SHIFT                                (0U)
#define EDMA_TPCC_DRAE4_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_DRAE4_EN_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_DRAE4_EN_ALLOWED                               (1U)

#define EDMA_TPCC_DRAEH4_EN_SHIFT                               (0U)
#define EDMA_TPCC_DRAEH4_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_DRAEH4_EN_NOT_ALLOWED                          (0U)
#define EDMA_TPCC_DRAEH4_EN_ALLOWED                              (1U)

#define EDMA_TPCC_DRAE5_EN_SHIFT                                (0U)
#define EDMA_TPCC_DRAE5_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_DRAE5_EN_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_DRAE5_EN_ALLOWED                               (1U)

#define EDMA_TPCC_DRAEH5_EN_SHIFT                               (0U)
#define EDMA_TPCC_DRAEH5_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_DRAEH5_EN_NOT_ALLOWED                          (0U)
#define EDMA_TPCC_DRAEH5_EN_ALLOWED                              (1U)

#define EDMA_TPCC_DRAE6_EN_SHIFT                                (0U)
#define EDMA_TPCC_DRAE6_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_DRAE6_EN_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_DRAE6_EN_ALLOWED                               (1U)

#define EDMA_TPCC_DRAEH6_EN_SHIFT                               (0U)
#define EDMA_TPCC_DRAEH6_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_DRAEH6_EN_NOT_ALLOWED                          (0U)
#define EDMA_TPCC_DRAEH6_EN_ALLOWED                              (1U)

#define EDMA_TPCC_DRAE7_EN_SHIFT                                (0U)
#define EDMA_TPCC_DRAE7_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_DRAE7_EN_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_DRAE7_EN_ALLOWED                               (1U)

#define EDMA_TPCC_DRAEH7_EN_SHIFT                               (0U)
#define EDMA_TPCC_DRAEH7_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_DRAEH7_EN_NOT_ALLOWED                          (0U)
#define EDMA_TPCC_DRAEH7_EN_ALLOWED                              (1U)

#define EDMA_TPCC_QRAE_EN_SHIFT                                 (0U)
#define EDMA_TPCC_QRAE_EN_MASK                                  (0x000000ffU)
#define EDMA_TPCC_QRAE_EN_NOT_ALLOWED                            (0U)
#define EDMA_TPCC_QRAE_EN_ALLOWED                                (1U)

#define EDMA_TPCC_Q0E_ENUM_SHIFT                                (0U)
#define EDMA_TPCC_Q0E_ENUM_MASK                                 (0x0000003fU)

#define EDMA_TPCC_Q0E_ETYPE_SHIFT                               (6U)
#define EDMA_TPCC_Q0E_ETYPE_MASK                                (0x000000c0U)
#define EDMA_TPCC_Q0E_ETYPE_ER                                   (0U)
#define EDMA_TPCC_Q0E_ETYPE_QER                                  (1U)

#define EDMA_TPCC_Q1E_ENUM_SHIFT                                (0U)
#define EDMA_TPCC_Q1E_ENUM_MASK                                 (0x0000003fU)

#define EDMA_TPCC_Q1E_ETYPE_SHIFT                               (6U)
#define EDMA_TPCC_Q1E_ETYPE_MASK                                (0x000000c0U)
#define EDMA_TPCC_Q1E_ETYPE_ER                                   (0U)
#define EDMA_TPCC_Q1E_ETYPE_QER                                  (1U)

#define EDMA_TPCC_Q2E_ENUM_SHIFT                                (0U)
#define EDMA_TPCC_Q2E_ENUM_MASK                                 (0x0000003fU)

#define EDMA_TPCC_Q2E_ETYPE_SHIFT                               (6U)
#define EDMA_TPCC_Q2E_ETYPE_MASK                                (0x000000c0U)
#define EDMA_TPCC_Q2E_ETYPE_ER                                   (0U)
#define EDMA_TPCC_Q2E_ETYPE_QER                                  (1U)

#define EDMA_TPCC_QSTAT_STRTPTR_SHIFT                           (0U)
#define EDMA_TPCC_QSTAT_STRTPTR_MASK                            (0x0000000fU)

#define EDMA_TPCC_QSTAT_NUMVAL_SHIFT                            (8U)
#define EDMA_TPCC_QSTAT_NUMVAL_MASK                             (0x00001f00U)
#define EDMA_TPCC_QSTAT_NUMVAL_VAL                               (0U)
#define EDMA_TPCC_QSTAT_NUMVAL_RESERVED                          (1U)

#define EDMA_TPCC_QSTAT_WM_SHIFT                                (16U)
#define EDMA_TPCC_QSTAT_WM_MASK                                 (0x001f0000U)
#define EDMA_TPCC_QSTAT_WM_VAL                                   (0U)
#define EDMA_TPCC_QSTAT_WM_RESERVED                              (1U)

#define EDMA_TPCC_QSTAT_THRXCD_SHIFT                            (24U)
#define EDMA_TPCC_QSTAT_THRXCD_MASK                             (0x01000000U)
#define EDMA_TPCC_QSTAT_THRXCD_NOT_EXCEEDED                      (0U)
#define EDMA_TPCC_QSTAT_THRXCD_EXCEEDED                          (1U)

#define EDMA_TPCC_QWMTHRA_Q0_SHIFT                              (0U)
#define EDMA_TPCC_QWMTHRA_Q0_MASK                               (0x0000001fU)
#define EDMA_TPCC_QWMTHRA_Q0_VAL                                 (0U)
#define EDMA_TPCC_QWMTHRA_Q0_DISABLE                             (17U)
#define EDMA_TPCC_QWMTHRA_Q0_RESERVED                            (18U)

#define EDMA_TPCC_QWMTHRA_Q1_SHIFT                              (8U)
#define EDMA_TPCC_QWMTHRA_Q1_MASK                               (0x00001f00U)
#define EDMA_TPCC_QWMTHRA_Q1_VAL                                 (0U)
#define EDMA_TPCC_QWMTHRA_Q1_DISABLE                             (17U)
#define EDMA_TPCC_QWMTHRA_Q1_RESERVED                            (18U)

#define EDMA_TPCC_QWMTHRA_Q2_SHIFT                              (16U)
#define EDMA_TPCC_QWMTHRA_Q2_MASK                               (0x001f0000U)
#define EDMA_TPCC_QWMTHRA_Q2_VAL                                 (0U)
#define EDMA_TPCC_QWMTHRA_Q2_DISABLE                             (17U)
#define EDMA_TPCC_QWMTHRA_Q2_RESERVED                            (18U)

#define EDMA_TPCC_CCSTAT_EVTACTV_SHIFT                          (0U)
#define EDMA_TPCC_CCSTAT_EVTACTV_MASK                           (0x00000001U)
#define EDMA_TPCC_CCSTAT_EVTACTV_INACTIVE                        (0U)
#define EDMA_TPCC_CCSTAT_EVTACTV_ACTIVE                          (1U)

#define EDMA_TPCC_CCSTAT_QEVTACTV_SHIFT                         (1U)
#define EDMA_TPCC_CCSTAT_QEVTACTV_MASK                          (0x00000002U)
#define EDMA_TPCC_CCSTAT_QEVTACTV_INACTIVE                       (0U)
#define EDMA_TPCC_CCSTAT_QEVTACTV_ACTIVE                         (1U)

#define EDMA_TPCC_CCSTAT_TRACTV_SHIFT                           (2U)
#define EDMA_TPCC_CCSTAT_TRACTV_MASK                            (0x00000004U)
#define EDMA_TPCC_CCSTAT_TRACTV_INACTIVE                         (0U)
#define EDMA_TPCC_CCSTAT_TRACTV_ACTIVE                           (1U)

#define EDMA_TPCC_CCSTAT_ACTV_SHIFT                             (4U)
#define EDMA_TPCC_CCSTAT_ACTV_MASK                              (0x00000010U)
#define EDMA_TPCC_CCSTAT_ACTV_IDLE                               (0U)
#define EDMA_TPCC_CCSTAT_ACTV_BUSY                               (1U)

#define EDMA_TPCC_CCSTAT_COMPACTV_SHIFT                         (8U)
#define EDMA_TPCC_CCSTAT_COMPACTV_MASK                          (0x00003f00U)
#define EDMA_TPCC_CCSTAT_COMPACTV_NO_REQUEST                     (0U)
#define EDMA_TPCC_CCSTAT_COMPACTV_REQUEST                        (1U)

#define EDMA_TPCC_CCSTAT_QUEACTV0_SHIFT                         (16U)
#define EDMA_TPCC_CCSTAT_QUEACTV0_MASK                          (0x00010000U)
#define EDMA_TPCC_CCSTAT_QUEACTV0_NO_EVENT                       (0U)
#define EDMA_TPCC_CCSTAT_QUEACTV0_EVENT                          (1U)

#define EDMA_TPCC_CCSTAT_QUEACTV1_SHIFT                         (17U)
#define EDMA_TPCC_CCSTAT_QUEACTV1_MASK                          (0x00020000U)
#define EDMA_TPCC_CCSTAT_QUEACTV1_NO_EVENT                       (0U)
#define EDMA_TPCC_CCSTAT_QUEACTV1_EVENT                          (1U)

#define EDMA_TPCC_CCSTAT_QUEACTV2_SHIFT                         (18U)
#define EDMA_TPCC_CCSTAT_QUEACTV2_MASK                          (0x00040000U)
#define EDMA_TPCC_CCSTAT_QUEACTV2_NO_EVENT                       (0U)
#define EDMA_TPCC_CCSTAT_QUEACTV2_EVENT                          (1U)

#define EDMA_TPCC_MPFAR_FADDR_SHIFT                             (0U)
#define EDMA_TPCC_MPFAR_FADDR_MASK                              (0xffffffffU)

#define EDMA_TPCC_MPFSR_UXE_SHIFT                               (0U)
#define EDMA_TPCC_MPFSR_UXE_MASK                                (0x00000001U)
#define EDMA_TPCC_MPFSR_UXE_NO_ERROR                             (0U)
#define EDMA_TPCC_MPFSR_UXE_ERROR                                (1U)

#define EDMA_TPCC_MPFSR_UWE_SHIFT                               (1U)
#define EDMA_TPCC_MPFSR_UWE_MASK                                (0x00000002U)
#define EDMA_TPCC_MPFSR_UWE_NO_ERROR                             (0U)
#define EDMA_TPCC_MPFSR_UWE_ERROR                                (1U)

#define EDMA_TPCC_MPFSR_URE_SHIFT                               (2U)
#define EDMA_TPCC_MPFSR_URE_MASK                                (0x00000004U)
#define EDMA_TPCC_MPFSR_URE_NO_ERROR                             (0U)
#define EDMA_TPCC_MPFSR_URE_ERROR                                (1U)

#define EDMA_TPCC_MPFSR_SXE_SHIFT                               (3U)
#define EDMA_TPCC_MPFSR_SXE_MASK                                (0x00000008U)
#define EDMA_TPCC_MPFSR_SXE_NO_ERROR                             (0U)
#define EDMA_TPCC_MPFSR_SXE_ERROR                                (1U)

#define EDMA_TPCC_MPFSR_SWE_SHIFT                               (4U)
#define EDMA_TPCC_MPFSR_SWE_MASK                                (0x00000010U)
#define EDMA_TPCC_MPFSR_SWE_NO_ERROR                             (0U)
#define EDMA_TPCC_MPFSR_SWE_ERROR                                (1U)

#define EDMA_TPCC_MPFSR_SRE_SHIFT                               (5U)
#define EDMA_TPCC_MPFSR_SRE_MASK                                (0x00000020U)
#define EDMA_TPCC_MPFSR_SRE_NO_ERROR                             (0U)
#define EDMA_TPCC_MPFSR_SRE_ERROR                                (1U)

#define EDMA_TPCC_MPFSR_FID_SHIFT                               (9U)
#define EDMA_TPCC_MPFSR_FID_MASK                                (0x00001e00U)

#define EDMA_TPCC_MPFCR_MPFCLR_SHIFT                            (0U)
#define EDMA_TPCC_MPFCR_MPFCLR_MASK                             (0x00000001U)
#define EDMA_TPCC_MPFCR_MPFCLR_NO_EFFECT                         (0U)
#define EDMA_TPCC_MPFCR_MPFCLR_CLEARED                           (1U)

#define EDMA_TPCC_MPPAG_UX_SHIFT                                (0U)
#define EDMA_TPCC_MPPAG_UX_MASK                                 (0x00000001U)
#define EDMA_TPCC_MPPAG_UX_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_MPPAG_UX_ALLOWED                               (1U)

#define EDMA_TPCC_MPPAG_UW_SHIFT                                (1U)
#define EDMA_TPCC_MPPAG_UW_MASK                                 (0x00000002U)
#define EDMA_TPCC_MPPAG_UW_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_MPPAG_UW_ALLOWED                               (1U)

#define EDMA_TPCC_MPPAG_UR_SHIFT                                (2U)
#define EDMA_TPCC_MPPAG_UR_MASK                                 (0x00000004U)
#define EDMA_TPCC_MPPAG_UR_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_MPPAG_UR_ALLOWED                               (1U)

#define EDMA_TPCC_MPPAG_SX_SHIFT                                (3U)
#define EDMA_TPCC_MPPAG_SX_MASK                                 (0x00000008U)
#define EDMA_TPCC_MPPAG_SX_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_MPPAG_SX_ALLOWED                               (1U)

#define EDMA_TPCC_MPPAG_SW_SHIFT                                (4U)
#define EDMA_TPCC_MPPAG_SW_MASK                                 (0x00000010U)
#define EDMA_TPCC_MPPAG_SW_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_MPPAG_SW_ALLOWED                               (1U)

#define EDMA_TPCC_MPPAG_SR_SHIFT                                (5U)
#define EDMA_TPCC_MPPAG_SR_MASK                                 (0x00000020U)
#define EDMA_TPCC_MPPAG_SR_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_MPPAG_SR_ALLOWED                               (1U)

#define EDMA_TPCC_MPPAG_EXT_SHIFT                               (9U)
#define EDMA_TPCC_MPPAG_EXT_MASK                                (0x00000200U)
#define EDMA_TPCC_MPPAG_EXT_NOT_ALLOWED                          (0U)
#define EDMA_TPCC_MPPAG_EXT_ALLOWED                              (1U)

#define EDMA_TPCC_MPPAG_AIDM_SHIFT                              (10U)
#define EDMA_TPCC_MPPAG_AIDM_MASK                               (0x0000fc00U)
#define EDMA_TPCC_MPPAG_AIDM_NOT_ALLOWED                         (0U)
#define EDMA_TPCC_MPPAG_AIDM_ALLOWED                             (1U)

#define EDMA_TPCC_MPPA_UX_SHIFT                                 (1U)
#define EDMA_TPCC_MPPA_UX_MASK                                  (0x00000002U)
#define EDMA_TPCC_MPPA_UX_NOT_ALLOWED                            (0U)
#define EDMA_TPCC_MPPA_UX_ALLOWED                                (1U)

#define EDMA_TPCC_MPPA_UW_SHIFT                                 (2U)
#define EDMA_TPCC_MPPA_UW_MASK                                  (0x00000004U)
#define EDMA_TPCC_MPPA_UW_NOT_ALLOWED                            (0U)
#define EDMA_TPCC_MPPA_UW_ALLOWED                                (1U)

#define EDMA_TPCC_MPPA_UR_SHIFT                                 (3U)
#define EDMA_TPCC_MPPA_UR_MASK                                  (0x00000008U)
#define EDMA_TPCC_MPPA_UR_NOT_ALLOWED                            (0U)
#define EDMA_TPCC_MPPA_UR_ALLOWED                                (1U)

#define EDMA_TPCC_MPPA_SX_SHIFT                                 (4U)
#define EDMA_TPCC_MPPA_SX_MASK                                  (0x00000010U)
#define EDMA_TPCC_MPPA_SX_NOT_ALLOWED                            (0U)
#define EDMA_TPCC_MPPA_SX_ALLOWED                                (1U)

#define EDMA_TPCC_MPPA_SW_SHIFT                                 (5U)
#define EDMA_TPCC_MPPA_SW_MASK                                  (0x00000020U)
#define EDMA_TPCC_MPPA_SW_NOT_ALLOWED                            (0U)
#define EDMA_TPCC_MPPA_SW_ALLOWED                                (1U)

#define EDMA_TPCC_MPPA_SR_SHIFT                                 (6U)
#define EDMA_TPCC_MPPA_SR_MASK                                  (0x00000040U)
#define EDMA_TPCC_MPPA_SR_NOT_ALLOWED                            (0U)
#define EDMA_TPCC_MPPA_SR_ALLOWED                                (1U)

#define EDMA_TPCC_MPPA_EXT_SHIFT                                (10U)
#define EDMA_TPCC_MPPA_EXT_MASK                                 (0x00000400U)
#define EDMA_TPCC_MPPA_EXT_NOT_ALLOWED                           (0U)
#define EDMA_TPCC_MPPA_EXT_ALLOWED                               (1U)

#define EDMA_TPCC_MPPA_AIDM_SHIFT                               (11U)
#define EDMA_TPCC_MPPA_AIDM_MASK                                (0x0001f800U)
#define EDMA_TPCC_MPPA_AIDM_NOT_ALLOWED                          (0U)
#define EDMA_TPCC_MPPA_AIDM_ALLOWED                              (1U)

#define EDMA_TPCC_ER_EN_SHIFT                                   (0U)
#define EDMA_TPCC_ER_EN_MASK                                    (0xffffffffU)
#define EDMA_TPCC_ER_EN_NOT_ASSERTED                             (0U)
#define EDMA_TPCC_ER_EN_ASSERTED                                 (1U)

#define EDMA_TPCC_ERH_EN_SHIFT                                  (0U)
#define EDMA_TPCC_ERH_EN_MASK                                   (0xffffffffU)
#define EDMA_TPCC_ERH_EN_NOT_ASSERTED                            (0U)
#define EDMA_TPCC_ERH_EN_ASSERTED                                (1U)

#define EDMA_TPCC_ECR_EN_SHIFT                                  (0U)
#define EDMA_TPCC_ECR_EN_MASK                                   (0xffffffffU)
#define EDMA_TPCC_ECR_EN_NO_EFFECT                               (0U)
#define EDMA_TPCC_ECR_EN_CLEARED                                 (1U)

#define EDMA_TPCC_ECRH_EN_SHIFT                                 (0U)
#define EDMA_TPCC_ECRH_EN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_ECRH_EN_NO_EFFECT                              (0U)
#define EDMA_TPCC_ECRH_EN_CLEARED                                (1U)

#define EDMA_TPCC_ESR_EN_SHIFT                                  (0U)
#define EDMA_TPCC_ESR_EN_MASK                                   (0xffffffffU)
#define EDMA_TPCC_ESR_EN_NO_EFFECT                               (0U)
#define EDMA_TPCC_ESR_EN_PRIORITIZED                             (1U)

#define EDMA_TPCC_ESRH_EN_SHIFT                                 (0U)
#define EDMA_TPCC_ESRH_EN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_ESRH_EN_NO_EFFECT                              (0U)
#define EDMA_TPCC_ESRH_EN_PRIORITIZED                            (1U)

#define EDMA_TPCC_CER_EN_SHIFT                                  (0U)
#define EDMA_TPCC_CER_EN_MASK                                   (0xffffffffU)
#define EDMA_TPCC_CER_EN_NO_EFFECT                               (0U)
#define EDMA_TPCC_CER_EN_PRIORITIZED                             (1U)

#define EDMA_TPCC_CERH_EN_SHIFT                                 (0U)
#define EDMA_TPCC_CERH_EN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_CERH_EN_NO_EFFECT                              (0U)
#define EDMA_TPCC_CERH_EN_PRIORITIZED                            (1U)

#define EDMA_TPCC_EER_EN_SHIFT                                  (0U)
#define EDMA_TPCC_EER_EN_MASK                                   (0xffffffffU)
#define EDMA_TPCC_EER_EN_DISABLED                                (0U)
#define EDMA_TPCC_EER_EN_ENABLED                                 (1U)

#define EDMA_TPCC_EERH_EN_SHIFT                                 (0U)
#define EDMA_TPCC_EERH_EN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_EERH_EN_DISABLED                               (0U)
#define EDMA_TPCC_EERH_EN_ENABLED                                (1U)

#define EDMA_TPCC_EECR_EN_SHIFT                                 (0U)
#define EDMA_TPCC_EECR_EN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_EECR_EN_NO_EFFECT                              (0U)
#define EDMA_TPCC_EECR_EN_DISABLED                               (1U)

#define EDMA_TPCC_EECRH_EN_SHIFT                                (0U)
#define EDMA_TPCC_EECRH_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_EECRH_EN_NO_EFFECT                             (0U)
#define EDMA_TPCC_EECRH_EN_DISABLED                              (1U)

#define EDMA_TPCC_EESR_EN_SHIFT                                 (0U)
#define EDMA_TPCC_EESR_EN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_EESR_EN_NO_EFFECT                              (0U)
#define EDMA_TPCC_EESR_EN_ENABLED                                (1U)

#define EDMA_TPCC_EESRH_EN_SHIFT                                (0U)
#define EDMA_TPCC_EESRH_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_EESRH_EN_NO_EFFECT                             (0U)
#define EDMA_TPCC_EESRH_EN_ENABLED                               (1U)

#define EDMA_TPCC_SER_EN_SHIFT                                  (0U)
#define EDMA_TPCC_SER_EN_MASK                                   (0xffffffffU)
#define EDMA_TPCC_SER_EN_NOT_STORED                              (0U)
#define EDMA_TPCC_SER_EN_STORED                                  (1U)

#define EDMA_TPCC_SERH_EN_SHIFT                                 (0U)
#define EDMA_TPCC_SERH_EN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_SERH_EN_NOT_STORED                             (0U)
#define EDMA_TPCC_SERH_EN_STORED                                 (1U)

#define EDMA_TPCC_SECR_EN_SHIFT                                 (0U)
#define EDMA_TPCC_SECR_EN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_SECR_EN_NO_EFFECT                              (0U)
#define EDMA_TPCC_SECR_EN_CLEARED                                (1U)

#define EDMA_TPCC_SECRH_EN_SHIFT                                (0U)
#define EDMA_TPCC_SECRH_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_SECRH_EN_NO_EFFECT                             (0U)
#define EDMA_TPCC_SECRH_EN_CLEARED                               (1U)

#define EDMA_TPCC_IER_IN_SHIFT                                  (0U)
#define EDMA_TPCC_IER_IN_MASK                                   (0xffffffffU)
#define EDMA_TPCC_IER_IN_DISABLED                                (0U)
#define EDMA_TPCC_IER_IN_ENABLED                                 (1U)

#define EDMA_TPCC_IERH_IN_SHIFT                                 (0U)
#define EDMA_TPCC_IERH_IN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_IERH_IN_DISABLED                               (0U)
#define EDMA_TPCC_IERH_IN_ENABLED                                (1U)

#define EDMA_TPCC_IECR_IN_SHIFT                                 (0U)
#define EDMA_TPCC_IECR_IN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_IECR_IN_NO_EFFECT                              (0U)
#define EDMA_TPCC_IECR_IN_CLEARED                                (1U)

#define EDMA_TPCC_IECRH_IN_SHIFT                                (0U)
#define EDMA_TPCC_IECRH_IN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_IECRH_IN_NO_EFFECT                             (0U)
#define EDMA_TPCC_IECRH_IN_CLEARED                               (1U)

#define EDMA_TPCC_IESR_IN_SHIFT                                 (0U)
#define EDMA_TPCC_IESR_IN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_IESR_IN_NO_EFFECT                              (0U)
#define EDMA_TPCC_IESR_IN_SET                                    (1U)

#define EDMA_TPCC_IESRH_IN_SHIFT                                (0U)
#define EDMA_TPCC_IESRH_IN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_IESRH_IN_NO_EFFECT                             (0U)
#define EDMA_TPCC_IESRH_IN_SET                                   (1U)

#define EDMA_TPCC_IPR_IN_SHIFT                                  (0U)
#define EDMA_TPCC_IPR_IN_MASK                                   (0xffffffffU)
#define EDMA_TPCC_IPR_IN_NOT_DETECTED                            (0U)
#define EDMA_TPCC_IPR_IN_DETECTED                                (1U)

#define EDMA_TPCC_IPRH_IN_SHIFT                                 (0U)
#define EDMA_TPCC_IPRH_IN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_IPRH_IN_NOT_DETECTED                           (0U)
#define EDMA_TPCC_IPRH_IN_DETECTED                               (1U)

#define EDMA_TPCC_ICR_IN_SHIFT                                  (0U)
#define EDMA_TPCC_ICR_IN_MASK                                   (0xffffffffU)
#define EDMA_TPCC_ICR_IN_NO_EFFECT                               (0U)
#define EDMA_TPCC_ICR_IN_CLEARED                                 (1U)

#define EDMA_TPCC_ICRH_IN_SHIFT                                 (0U)
#define EDMA_TPCC_ICRH_IN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_ICRH_IN_NO_EFFECT                              (0U)
#define EDMA_TPCC_ICRH_IN_CLEARED                                (1U)

#define EDMA_TPCC_IEVAL_EVAL_SHIFT                              (0U)
#define EDMA_TPCC_IEVAL_EVAL_MASK                               (0x00000001U)
#define EDMA_TPCC_IEVAL_EVAL_NO_EFFECT                           (0U)
#define EDMA_TPCC_IEVAL_EVAL_PULSE                               (1U)

#define EDMA_TPCC_QER_EN_SHIFT                                  (0U)
#define EDMA_TPCC_QER_EN_MASK                                   (0x000000ffU)
#define EDMA_TPCC_QER_EN_NO_EFFECT                               (0U)
#define EDMA_TPCC_QER_EN_PRIORITIZED                             (1U)

#define EDMA_TPCC_QEER_EN_SHIFT                                 (0U)
#define EDMA_TPCC_QEER_EN_MASK                                  (0x000000ffU)
#define EDMA_TPCC_QEER_EN_DISABLED                               (0U)
#define EDMA_TPCC_QEER_EN_ENABLED                                (1U)

#define EDMA_TPCC_QEECR_EN_SHIFT                                (0U)
#define EDMA_TPCC_QEECR_EN_MASK                                 (0x000000ffU)
#define EDMA_TPCC_QEECR_EN_NO_EFFECT                             (0U)
#define EDMA_TPCC_QEECR_EN_DISABLED                              (1U)

#define EDMA_TPCC_QEESR_EN_SHIFT                                (0U)
#define EDMA_TPCC_QEESR_EN_MASK                                 (0x000000ffU)
#define EDMA_TPCC_QEESR_EN_NO_EFFECT                             (0U)
#define EDMA_TPCC_QEESR_EN_ENABLED                               (1U)

#define EDMA_TPCC_QSER_EN_SHIFT                                 (0U)
#define EDMA_TPCC_QSER_EN_MASK                                  (0x000000ffU)
#define EDMA_TPCC_QSER_EN_NOT_STORED                             (0U)
#define EDMA_TPCC_QSER_EN_STORED                                 (1U)

#define EDMA_TPCC_QSECR_EN_SHIFT                                (0U)
#define EDMA_TPCC_QSECR_EN_MASK                                 (0x000000ffU)
#define EDMA_TPCC_QSECR_EN_NO_EFFECT                             (0U)
#define EDMA_TPCC_QSECR_EN_CLEARED                               (1U)

#define EDMA_TPCC_S_ER_EN_SHIFT                                 (0U)
#define EDMA_TPCC_S_ER_EN_MASK                                  (0xffffffffU)
#define EDMA_TPCC_S_ER_EN_NOT_ASSERTED                           (0U)
#define EDMA_TPCC_S_ER_EN_ASSERTED                               (1U)

#define EDMA_TPCC_S_ERH_EN_SHIFT                                (0U)
#define EDMA_TPCC_S_ERH_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_S_ERH_EN_NOT_ASSERTED                          (0U)
#define EDMA_TPCC_S_ERH_EN_ASSERTED                              (1U)

#define EDMA_TPCC_S_ECR_EN_SHIFT                                (0U)
#define EDMA_TPCC_S_ECR_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_S_ECR_EN_NO_EFFECT                             (0U)
#define EDMA_TPCC_S_ECR_EN_CLEARED                               (1U)

#define EDMA_TPCC_S_ECRH_EN_SHIFT                               (0U)
#define EDMA_TPCC_S_ECRH_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_ECRH_EN_NO_EFFECT                            (0U)
#define EDMA_TPCC_S_ECRH_EN_CLEARED                              (1U)

#define EDMA_TPCC_S_ESR_EN_SHIFT                                (0U)
#define EDMA_TPCC_S_ESR_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_S_ESR_EN_NO_EFFECT                             (0U)
#define EDMA_TPCC_S_ESR_EN_PRIORITIZED                           (1U)

#define EDMA_TPCC_S_ESRH_EN_SHIFT                               (0U)
#define EDMA_TPCC_S_ESRH_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_ESRH_EN_NO_EFFECT                            (0U)
#define EDMA_TPCC_S_ESRH_EN_PRIORITIZED                          (1U)

#define EDMA_TPCC_S_CER_EN_SHIFT                                (0U)
#define EDMA_TPCC_S_CER_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_S_CER_EN_NO_EFFECT                             (0U)
#define EDMA_TPCC_S_CER_EN_PRIORITIZED                           (1U)

#define EDMA_TPCC_S_CERH_EN_SHIFT                               (0U)
#define EDMA_TPCC_S_CERH_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_CERH_EN_NO_EFFECT                            (0U)
#define EDMA_TPCC_S_CERH_EN_PRIORITIZED                          (1U)

#define EDMA_TPCC_S_EER_EN_SHIFT                                (0U)
#define EDMA_TPCC_S_EER_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_S_EER_EN_DISABLED                              (0U)
#define EDMA_TPCC_S_EER_EN_ENABLED                               (1U)

#define EDMA_TPCC_S_EERH_EN_SHIFT                               (0U)
#define EDMA_TPCC_S_EERH_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_EERH_EN_DISABLED                             (0U)
#define EDMA_TPCC_S_EERH_EN_ENABLED                              (1U)

#define EDMA_TPCC_S_EECR_EN_SHIFT                               (0U)
#define EDMA_TPCC_S_EECR_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_EECR_EN_NO_EFFECT                            (0U)
#define EDMA_TPCC_S_EECR_EN_DISABLED                             (1U)

#define EDMA_TPCC_S_EECRH_EN_SHIFT                              (0U)
#define EDMA_TPCC_S_EECRH_EN_MASK                               (0xffffffffU)
#define EDMA_TPCC_S_EECRH_EN_NO_EFFECT                           (0U)
#define EDMA_TPCC_S_EECRH_EN_DISABLED                            (1U)

#define EDMA_TPCC_S_EESR_EN_SHIFT                               (0U)
#define EDMA_TPCC_S_EESR_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_EESR_EN_NO_EFFECT                            (0U)
#define EDMA_TPCC_S_EESR_EN_ENABLED                              (1U)

#define EDMA_TPCC_S_EESRH_EN_SHIFT                              (0U)
#define EDMA_TPCC_S_EESRH_EN_MASK                               (0xffffffffU)
#define EDMA_TPCC_S_EESRH_EN_NO_EFFECT                           (0U)
#define EDMA_TPCC_S_EESRH_EN_ENABLED                             (1U)

#define EDMA_TPCC_S_SER_EN_SHIFT                                (0U)
#define EDMA_TPCC_S_SER_EN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_S_SER_EN_NOT_STORED                            (0U)
#define EDMA_TPCC_S_SER_EN_STORED                                (1U)

#define EDMA_TPCC_S_SERH_EN_SHIFT                               (0U)
#define EDMA_TPCC_S_SERH_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_SERH_EN_NOT_STORED                           (0U)
#define EDMA_TPCC_S_SERH_EN_STORED                               (1U)

#define EDMA_TPCC_S_SECR_EN_SHIFT                               (0U)
#define EDMA_TPCC_S_SECR_EN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_SECR_EN_NO_EFFECT                            (0U)
#define EDMA_TPCC_S_SECR_EN_CLEARED                              (1U)

#define EDMA_TPCC_S_SECRH_EN_SHIFT                              (0U)
#define EDMA_TPCC_S_SECRH_EN_MASK                               (0xffffffffU)
#define EDMA_TPCC_S_SECRH_EN_NO_EFFECT                           (0U)
#define EDMA_TPCC_S_SECRH_EN_CLEARED                             (1U)

#define EDMA_TPCC_S_IER_IN_SHIFT                                (0U)
#define EDMA_TPCC_S_IER_IN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_S_IER_IN_DISABLED                              (0U)
#define EDMA_TPCC_S_IER_IN_ENABLED                               (1U)

#define EDMA_TPCC_S_IERH_IN_SHIFT                               (0U)
#define EDMA_TPCC_S_IERH_IN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_IERH_IN_DISABLED                             (0U)
#define EDMA_TPCC_S_IERH_IN_ENABLED                              (1U)

#define EDMA_TPCC_S_IECR_IN_SHIFT                               (0U)
#define EDMA_TPCC_S_IECR_IN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_IECR_IN_NO_EFFECT                            (0U)
#define EDMA_TPCC_S_IECR_IN_CLEARED                              (1U)

#define EDMA_TPCC_S_IECRH_IN_SHIFT                              (0U)
#define EDMA_TPCC_S_IECRH_IN_MASK                               (0xffffffffU)
#define EDMA_TPCC_S_IECRH_IN_NO_EFFECT                           (0U)
#define EDMA_TPCC_S_IECRH_IN_CLEARED                             (1U)

#define EDMA_TPCC_S_IESR_IN_SHIFT                               (0U)
#define EDMA_TPCC_S_IESR_IN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_IESR_IN_NO_EFFECT                            (0U)
#define EDMA_TPCC_S_IESR_IN_SET                                  (1U)

#define EDMA_TPCC_S_IESRH_IN_SHIFT                              (0U)
#define EDMA_TPCC_S_IESRH_IN_MASK                               (0xffffffffU)
#define EDMA_TPCC_S_IESRH_IN_NO_EFFECT                           (0U)
#define EDMA_TPCC_S_IESRH_IN_SET                                 (1U)

#define EDMA_TPCC_S_IPR_IN_SHIFT                                (0U)
#define EDMA_TPCC_S_IPR_IN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_S_IPR_IN_NOT_DETECTED                          (0U)
#define EDMA_TPCC_S_IPR_IN_DETECTED                              (1U)

#define EDMA_TPCC_S_IPRH_IN_SHIFT                               (0U)
#define EDMA_TPCC_S_IPRH_IN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_IPRH_IN_NOT_DETECTED                         (0U)
#define EDMA_TPCC_S_IPRH_IN_DETECTED                             (1U)

#define EDMA_TPCC_S_ICR_IN_SHIFT                                (0U)
#define EDMA_TPCC_S_ICR_IN_MASK                                 (0xffffffffU)
#define EDMA_TPCC_S_ICR_IN_NO_EFFECT                             (0U)
#define EDMA_TPCC_S_ICR_IN_CLEARED                               (1U)

#define EDMA_TPCC_S_ICRH_IN_SHIFT                               (0U)
#define EDMA_TPCC_S_ICRH_IN_MASK                                (0xffffffffU)
#define EDMA_TPCC_S_ICRH_IN_NO_EFFECT                            (0U)
#define EDMA_TPCC_S_ICRH_IN_CLEARED                              (1U)

#define EDMA_TPCC_S_IEVAL_EVAL_SHIFT                            (0U)
#define EDMA_TPCC_S_IEVAL_EVAL_MASK                             (0x00000001U)
#define EDMA_TPCC_S_IEVAL_EVAL_NO_EFFECT                         (0U)
#define EDMA_TPCC_S_IEVAL_EVAL_PULSE                             (1U)

#define EDMA_TPCC_S_QER_EN_SHIFT                                (0U)
#define EDMA_TPCC_S_QER_EN_MASK                                 (0x000000ffU)
#define EDMA_TPCC_S_QER_EN_NO_EFFECT                             (0U)
#define EDMA_TPCC_S_QER_EN_PRIORITIZED                           (1U)

#define EDMA_TPCC_S_QEER_EN_SHIFT                               (0U)
#define EDMA_TPCC_S_QEER_EN_MASK                                (0x000000ffU)
#define EDMA_TPCC_S_QEER_EN_DISABLED                             (0U)
#define EDMA_TPCC_S_QEER_EN_ENABLED                              (1U)

#define EDMA_TPCC_S_QEECR_EN_SHIFT                              (0U)
#define EDMA_TPCC_S_QEECR_EN_MASK                               (0x000000ffU)
#define EDMA_TPCC_S_QEECR_EN_NO_EFFECT                           (0U)
#define EDMA_TPCC_S_QEECR_EN_DISABLED                            (1U)

#define EDMA_TPCC_S_QEESR_EN_SHIFT                              (0U)
#define EDMA_TPCC_S_QEESR_EN_MASK                               (0x000000ffU)
#define EDMA_TPCC_S_QEESR_EN_NO_EFFECT                           (0U)
#define EDMA_TPCC_S_QEESR_EN_ENABLED                             (1U)

#define EDMA_TPCC_S_QSER_EN_SHIFT                               (0U)
#define EDMA_TPCC_S_QSER_EN_MASK                                (0x000000ffU)
#define EDMA_TPCC_S_QSER_EN_NOT_STORED                           (0U)
#define EDMA_TPCC_S_QSER_EN_STORED                               (1U)

#define EDMA_TPCC_S_QSECR_EN_SHIFT                              (0U)
#define EDMA_TPCC_S_QSECR_EN_MASK                               (0x000000ffU)
#define EDMA_TPCC_S_QSECR_EN_NO_EFFECT                           (0U)
#define EDMA_TPCC_S_QSECR_EN_CLEARED                             (1U)

#ifdef __cplusplus
}
#endif

#endif /* HW_EDMA_TPCC_H_ */
