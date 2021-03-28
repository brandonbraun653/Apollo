/********************************************************************
 * Copyright (C) 2017 Texas Instruments Incorporated.
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
 *  Name        : cslr_pbist.h
*/
#ifndef CSLR_PBIST_H_
#define CSLR_PBIST_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint8_t  Resv_256[256];
    volatile uint32_t A0;                        /* Variable Address Registers */
    volatile uint32_t A1;                        /* Variable Address Registers */
    volatile uint32_t A2;                        /* Variable Address Registers */
    volatile uint32_t A3;                        /* Variable Address Registers */
    volatile uint32_t L0;                        /* Variable Loop Count Registers */
    volatile uint32_t L1;                        /* Variable Loop Count Registers */
    volatile uint32_t L2;                        /* Variable Loop Count Registers */
    volatile uint32_t L3;                        /* Variable Loop Count Registers */
    volatile uint32_t D;                         /* Data Registers */
    volatile uint32_t E;                         /* Data Registers */
    volatile uint8_t  Resv_304[8];
    volatile uint32_t CA0;                       /* Constant Address Registers */
    volatile uint32_t CA1;                       /* Constant Address Registers */
    volatile uint32_t CA2;                       /* Constant Address Registers */
    volatile uint32_t CA3;                       /* Constant Address Registers */
    volatile uint32_t CL0;                       /* Constant Loop Count Registers */
    volatile uint32_t CL1;                       /* Constant Loop Count Registers */
    volatile uint32_t CL2;                       /* Constant Loop Count Registers */
    volatile uint32_t CL3;                       /* Constant Loop Count Registers */
    volatile uint32_t I0;                        /* Constant Increment Registers */
    volatile uint32_t I1;                        /* Constant Increment Registers */
    volatile uint32_t I2;                        /* Constant Increment Registers */
    volatile uint32_t I3;                        /* Constant Increment Registers */
    volatile uint32_t RAMT;                      /* RAM Configuration Register */
    volatile uint32_t DLR;                       /* Datalogger Register */
    volatile uint32_t CMS;                       /* Clock-Mux Select Register */
    volatile uint32_t STR;                       /* Program Control Register */
    volatile uint64_t SCR;                       /* Address Scrambling Register */
    volatile uint32_t CSR;                       /* Chip Select Register */
    volatile uint32_t FDLY;                      /* Fail Delay Register */
    volatile uint32_t PACT;                      /* PACT Register */
    volatile uint32_t PID;                       /* PBIST_ID Register */
    volatile uint32_t OVER;                      /* Override Register */
    volatile uint8_t  Resv_400[4];
    volatile uint64_t FSRF;                      /* Fail Status Fail Register */
    volatile uint64_t FSRC;                      /* Fail Status Count Register */
    volatile uint64_t FSRA;                      /* Fail Status Address Register */
    volatile uint32_t FSRDL0;                    /* Fail Status Data Registers */
    volatile uint8_t  Resv_432[4];
    volatile uint32_t FSRDL1;                    /* Fail Status Data Registers */
    volatile uint32_t MARGIN_MODE;               /* Fail Status Fail Register */
    volatile uint32_t WRENZ;                     /* Fail Status Fail Register */
    volatile uint32_t PAGE_PGS;                  /* Fail Status Fail Register */
    volatile uint32_t ROM;                       /* ROM Mask Register */
    volatile uint32_t ALGO;                      /* Algorithm Mask Register */
    volatile uint64_t RINFO;                     /* RAM Info Mask Register */
} CSL_pbistRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_PBIST_A0                                                           (0x00000100U)
#define CSL_PBIST_A1                                                           (0x00000104U)
#define CSL_PBIST_A2                                                           (0x00000108U)
#define CSL_PBIST_A3                                                           (0x0000010CU)
#define CSL_PBIST_L0                                                           (0x00000110U)
#define CSL_PBIST_L1                                                           (0x00000114U)
#define CSL_PBIST_L2                                                           (0x00000118U)
#define CSL_PBIST_L3                                                           (0x0000011CU)
#define CSL_PBIST_D                                                            (0x00000120U)
#define CSL_PBIST_E                                                            (0x00000124U)
#define CSL_PBIST_CA0                                                          (0x00000130U)
#define CSL_PBIST_CA1                                                          (0x00000134U)
#define CSL_PBIST_CA2                                                          (0x00000138U)
#define CSL_PBIST_CA3                                                          (0x0000013CU)
#define CSL_PBIST_CL0                                                          (0x00000140U)
#define CSL_PBIST_CL1                                                          (0x00000144U)
#define CSL_PBIST_CL2                                                          (0x00000148U)
#define CSL_PBIST_CL3                                                          (0x0000014CU)
#define CSL_PBIST_I0                                                           (0x00000150U)
#define CSL_PBIST_I1                                                           (0x00000154U)
#define CSL_PBIST_I2                                                           (0x00000158U)
#define CSL_PBIST_I3                                                           (0x0000015CU)
#define CSL_PBIST_RAMT                                                         (0x00000160U)
#define CSL_PBIST_DLR                                                          (0x00000164U)
#define CSL_PBIST_CMS                                                          (0x00000168U)
#define CSL_PBIST_STR                                                          (0x0000016CU)
#define CSL_PBIST_SCR                                                          (0x00000170U)
#define CSL_PBIST_CSR                                                          (0x00000178U)
#define CSL_PBIST_FDLY                                                         (0x0000017CU)
#define CSL_PBIST_PACT                                                         (0x00000180U)
#define CSL_PBIST_PID                                                          (0x00000184U)
#define CSL_PBIST_OVER                                                         (0x00000188U)
#define CSL_PBIST_FSRF                                                         (0x00000190U)
#define CSL_PBIST_FSRC                                                         (0x00000198U)
#define CSL_PBIST_FSRA                                                         (0x000001A0U)
#define CSL_PBIST_FSRDL0                                                       (0x000001A8U)
#define CSL_PBIST_FSRDL1                                                       (0x000001B0U)
#define CSL_PBIST_MARGIN_MODE                                                  (0x000001B4U)
#define CSL_PBIST_WRENZ                                                        (0x000001B8U)
#define CSL_PBIST_PAGE_PGS                                                     (0x000001BCU)
#define CSL_PBIST_ROM                                                          (0x000001C0U)
#define CSL_PBIST_ALGO                                                         (0x000001C4U)
#define CSL_PBIST_RINFO                                                        (0x000001C8U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* A0 */

#define CSL_PBIST_A0_A0_MASK                                                   (0x0000FFFFU)
#define CSL_PBIST_A0_A0_SHIFT                                                  (0x00000000U)
#define CSL_PBIST_A0_A0_MAX                                                    (0x0000FFFFU)

/* A1 */

#define CSL_PBIST_A1_A1_MASK                                                   (0x0000FFFFU)
#define CSL_PBIST_A1_A1_SHIFT                                                  (0x00000000U)
#define CSL_PBIST_A1_A1_MAX                                                    (0x0000FFFFU)

/* A2 */

#define CSL_PBIST_A2_A2_MASK                                                   (0x0000FFFFU)
#define CSL_PBIST_A2_A2_SHIFT                                                  (0x00000000U)
#define CSL_PBIST_A2_A2_MAX                                                    (0x0000FFFFU)

/* A3 */

#define CSL_PBIST_A3_A3_MASK                                                   (0x0000FFFFU)
#define CSL_PBIST_A3_A3_SHIFT                                                  (0x00000000U)
#define CSL_PBIST_A3_A3_MAX                                                    (0x0000FFFFU)

/* L0 */

#define CSL_PBIST_L0_L0_MASK                                                   (0x0000FFFFU)
#define CSL_PBIST_L0_L0_SHIFT                                                  (0x00000000U)
#define CSL_PBIST_L0_L0_MAX                                                    (0x0000FFFFU)

/* L1 */

#define CSL_PBIST_L1_L1_MASK                                                   (0x0000FFFFU)
#define CSL_PBIST_L1_L1_SHIFT                                                  (0x00000000U)
#define CSL_PBIST_L1_L1_MAX                                                    (0x0000FFFFU)

/* L2 */

#define CSL_PBIST_L2_L2_MASK                                                   (0x0000FFFFU)
#define CSL_PBIST_L2_L2_SHIFT                                                  (0x00000000U)
#define CSL_PBIST_L2_L2_MAX                                                    (0x0000FFFFU)

/* L3 */

#define CSL_PBIST_L3_L3_MASK                                                   (0x0000FFFFU)
#define CSL_PBIST_L3_L3_SHIFT                                                  (0x00000000U)
#define CSL_PBIST_L3_L3_MAX                                                    (0x0000FFFFU)

/* D */

#define CSL_PBIST_D_D0_MASK                                                    (0x0000FFFFU)
#define CSL_PBIST_D_D0_SHIFT                                                   (0x00000000U)
#define CSL_PBIST_D_D0_MAX                                                     (0x0000FFFFU)

#define CSL_PBIST_D_D1_MASK                                                    (0xFFFF0000U)
#define CSL_PBIST_D_D1_SHIFT                                                   (0x00000010U)
#define CSL_PBIST_D_D1_MAX                                                     (0x0000FFFFU)

/* E */

#define CSL_PBIST_E_E0_MASK                                                    (0x0000FFFFU)
#define CSL_PBIST_E_E0_SHIFT                                                   (0x00000000U)
#define CSL_PBIST_E_E0_MAX                                                     (0x0000FFFFU)

#define CSL_PBIST_E_E1_MASK                                                    (0xFFFF0000U)
#define CSL_PBIST_E_E1_SHIFT                                                   (0x00000010U)
#define CSL_PBIST_E_E1_MAX                                                     (0x0000FFFFU)

/* CA0 */

#define CSL_PBIST_CA0_CA0_MASK                                                 (0x0000FFFFU)
#define CSL_PBIST_CA0_CA0_SHIFT                                                (0x00000000U)
#define CSL_PBIST_CA0_CA0_MAX                                                  (0x0000FFFFU)

/* CA1 */

#define CSL_PBIST_CA1_CA1_MASK                                                 (0x0000FFFFU)
#define CSL_PBIST_CA1_CA1_SHIFT                                                (0x00000000U)
#define CSL_PBIST_CA1_CA1_MAX                                                  (0x0000FFFFU)

/* CA2 */

#define CSL_PBIST_CA2_CA2_MASK                                                 (0x0000FFFFU)
#define CSL_PBIST_CA2_CA2_SHIFT                                                (0x00000000U)
#define CSL_PBIST_CA2_CA2_MAX                                                  (0x0000FFFFU)

/* CA3 */

#define CSL_PBIST_CA3_CA3_MASK                                                 (0x0000FFFFU)
#define CSL_PBIST_CA3_CA3_SHIFT                                                (0x00000000U)
#define CSL_PBIST_CA3_CA3_MAX                                                  (0x0000FFFFU)

/* CL0 */

#define CSL_PBIST_CL0_CL0_MASK                                                 (0x0000FFFFU)
#define CSL_PBIST_CL0_CL0_SHIFT                                                (0x00000000U)
#define CSL_PBIST_CL0_CL0_MAX                                                  (0x0000FFFFU)

/* CL1 */

#define CSL_PBIST_CL1_CL1_MASK                                                 (0x0000FFFFU)
#define CSL_PBIST_CL1_CL1_SHIFT                                                (0x00000000U)
#define CSL_PBIST_CL1_CL1_MAX                                                  (0x0000FFFFU)

/* CL2 */

#define CSL_PBIST_CL2_CL2_MASK                                                 (0x0000FFFFU)
#define CSL_PBIST_CL2_CL2_SHIFT                                                (0x00000000U)
#define CSL_PBIST_CL2_CL2_MAX                                                  (0x0000FFFFU)

/* CL3 */

#define CSL_PBIST_CL3_CL3_MASK                                                 (0x0000FFFFU)
#define CSL_PBIST_CL3_CL3_SHIFT                                                (0x00000000U)
#define CSL_PBIST_CL3_CL3_MAX                                                  (0x0000FFFFU)

/* I0 */

#define CSL_PBIST_I0_I0_MASK                                                   (0x0000FFFFU)
#define CSL_PBIST_I0_I0_SHIFT                                                  (0x00000000U)
#define CSL_PBIST_I0_I0_MAX                                                    (0x0000FFFFU)

/* I1 */

#define CSL_PBIST_I1_I0_MASK                                                   (0x0000FFFFU)
#define CSL_PBIST_I1_I0_SHIFT                                                  (0x00000000U)
#define CSL_PBIST_I1_I0_MAX                                                    (0x0000FFFFU)

/* I2 */

#define CSL_PBIST_I2_I0_MASK                                                   (0x0000FFFFU)
#define CSL_PBIST_I2_I0_SHIFT                                                  (0x00000000U)
#define CSL_PBIST_I2_I0_MAX                                                    (0x0000FFFFU)

/* I3 */

#define CSL_PBIST_I3_I0_MASK                                                   (0x0000FFFFU)
#define CSL_PBIST_I3_I0_SHIFT                                                  (0x00000000U)
#define CSL_PBIST_I3_I0_MAX                                                    (0x0000FFFFU)

/* RAMT */

#define CSL_PBIST_RAMT_RLS_MASK                                                (0x00000003U)
#define CSL_PBIST_RAMT_RLS_SHIFT                                               (0x00000000U)
#define CSL_PBIST_RAMT_RLS_MAX                                                 (0x00000003U)

#define CSL_PBIST_RAMT_PLS_MASK                                                (0x0000003CU)
#define CSL_PBIST_RAMT_PLS_SHIFT                                               (0x00000002U)
#define CSL_PBIST_RAMT_PLS_MAX                                                 (0x0000000FU)

#define CSL_PBIST_RAMT_DWR_MASK                                                (0x0000FF00U)
#define CSL_PBIST_RAMT_DWR_SHIFT                                               (0x00000008U)
#define CSL_PBIST_RAMT_DWR_MAX                                                 (0x000000FFU)

#define CSL_PBIST_RAMT_RDS_MASK                                                (0x00FF0000U)
#define CSL_PBIST_RAMT_RDS_SHIFT                                               (0x00000010U)
#define CSL_PBIST_RAMT_RDS_MAX                                                 (0x000000FFU)

#define CSL_PBIST_RAMT_RGS_MASK                                                (0xFF000000U)
#define CSL_PBIST_RAMT_RGS_SHIFT                                               (0x00000018U)
#define CSL_PBIST_RAMT_RGS_MAX                                                 (0x000000FFU)

/* DLR */

#define CSL_PBIST_DLR_DLR0_DCM_MASK                                            (0x00000001U)
#define CSL_PBIST_DLR_DLR0_DCM_SHIFT                                           (0x00000000U)
#define CSL_PBIST_DLR_DLR0_DCM_MAX                                             (0x00000001U)

#define CSL_PBIST_DLR_DLR0_IDDQ_MASK                                           (0x00000002U)
#define CSL_PBIST_DLR_DLR0_IDDQ_SHIFT                                          (0x00000001U)
#define CSL_PBIST_DLR_DLR0_IDDQ_MAX                                            (0x00000001U)

#define CSL_PBIST_DLR_DLR0_ROM_MASK                                            (0x00000004U)
#define CSL_PBIST_DLR_DLR0_ROM_SHIFT                                           (0x00000002U)
#define CSL_PBIST_DLR_DLR0_ROM_MAX                                             (0x00000001U)

#define CSL_PBIST_DLR_DLR0_TCK_MASK                                            (0x00000008U)
#define CSL_PBIST_DLR_DLR0_TCK_SHIFT                                           (0x00000003U)
#define CSL_PBIST_DLR_DLR0_TCK_MAX                                             (0x00000001U)

#define CSL_PBIST_DLR_DLR0_CAM_MASK                                            (0x00000010U)
#define CSL_PBIST_DLR_DLR0_CAM_SHIFT                                           (0x00000004U)
#define CSL_PBIST_DLR_DLR0_CAM_MAX                                             (0x00000001U)

#define CSL_PBIST_DLR_DLR0_ECAM_MASK                                           (0x00000020U)
#define CSL_PBIST_DLR_DLR0_ECAM_SHIFT                                          (0x00000005U)
#define CSL_PBIST_DLR_DLR0_ECAM_MAX                                            (0x00000001U)

#define CSL_PBIST_DLR_DLR0_CFMM_MASK                                           (0x00000040U)
#define CSL_PBIST_DLR_DLR0_CFMM_SHIFT                                          (0x00000006U)
#define CSL_PBIST_DLR_DLR0_CFMM_MAX                                            (0x00000001U)

#define CSL_PBIST_DLR_DLR0_TSM_MASK                                            (0x00000080U)
#define CSL_PBIST_DLR_DLR0_TSM_SHIFT                                           (0x00000007U)
#define CSL_PBIST_DLR_DLR0_TSM_MAX                                             (0x00000001U)

#define CSL_PBIST_DLR_DLR1_MISR_MASK                                           (0x00000100U)
#define CSL_PBIST_DLR_DLR1_MISR_SHIFT                                          (0x00000008U)
#define CSL_PBIST_DLR_DLR1_MISR_MAX                                            (0x00000001U)

#define CSL_PBIST_DLR_DLR1_GNG_MASK                                            (0x00000200U)
#define CSL_PBIST_DLR_DLR1_GNG_SHIFT                                           (0x00000009U)
#define CSL_PBIST_DLR_DLR1_GNG_MAX                                             (0x00000001U)

#define CSL_PBIST_DLR_DLR1_RTM_MASK                                            (0x00000400U)
#define CSL_PBIST_DLR_DLR1_RTM_SHIFT                                           (0x0000000AU)
#define CSL_PBIST_DLR_DLR1_RTM_MAX                                             (0x00000001U)

#define CSL_PBIST_DLR_BRP_MASK                                                 (0x00FF0000U)
#define CSL_PBIST_DLR_BRP_SHIFT                                                (0x00000010U)
#define CSL_PBIST_DLR_BRP_MAX                                                  (0x000000FFU)

/* CMS */

#define CSL_PBIST_CMS_CMS_MASK                                                 (0x0000000FU)
#define CSL_PBIST_CMS_CMS_SHIFT                                                (0x00000000U)
#define CSL_PBIST_CMS_CMS_MAX                                                  (0x0000000FU)

/* STR */

#define CSL_PBIST_STR_START_MASK                                               (0x00000001U)
#define CSL_PBIST_STR_START_SHIFT                                              (0x00000000U)
#define CSL_PBIST_STR_START_MAX                                                (0x00000001U)

#define CSL_PBIST_STR_RES_MASK                                                 (0x00000002U)
#define CSL_PBIST_STR_RES_SHIFT                                                (0x00000001U)
#define CSL_PBIST_STR_RES_MAX                                                  (0x00000001U)

#define CSL_PBIST_STR_STOP_MASK                                                (0x00000004U)
#define CSL_PBIST_STR_STOP_SHIFT                                               (0x00000002U)
#define CSL_PBIST_STR_STOP_MAX                                                 (0x00000001U)

#define CSL_PBIST_STR_STEP_MASK                                                (0x00000008U)
#define CSL_PBIST_STR_STEP_SHIFT                                               (0x00000003U)
#define CSL_PBIST_STR_STEP_MAX                                                 (0x00000001U)

#define CSL_PBIST_STR_CHK_MASK                                                 (0x00000010U)
#define CSL_PBIST_STR_CHK_SHIFT                                                (0x00000004U)
#define CSL_PBIST_STR_CHK_MAX                                                  (0x00000001U)

/* SCR */

#define CSL_PBIST_SCR_SCR0_MASK                                                (0x00000000000000FFU)
#define CSL_PBIST_SCR_SCR0_SHIFT                                               (0x0000000000000000U)
#define CSL_PBIST_SCR_SCR0_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_SCR_SCR1_MASK                                                (0x000000000000FF00U)
#define CSL_PBIST_SCR_SCR1_SHIFT                                               (0x0000000000000008U)
#define CSL_PBIST_SCR_SCR1_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_SCR_SCR2_MASK                                                (0x0000000000FF0000U)
#define CSL_PBIST_SCR_SCR2_SHIFT                                               (0x0000000000000010U)
#define CSL_PBIST_SCR_SCR2_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_SCR_SCR3_MASK                                                (0x00000000FF000000U)
#define CSL_PBIST_SCR_SCR3_SHIFT                                               (0x0000000000000018U)
#define CSL_PBIST_SCR_SCR3_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_SCR_SCR4_MASK                                                (0x000000FF00000000U)
#define CSL_PBIST_SCR_SCR4_SHIFT                                               (0x0000000000000020U)
#define CSL_PBIST_SCR_SCR4_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_SCR_SCR5_MASK                                                (0x0000FF0000000000U)
#define CSL_PBIST_SCR_SCR5_SHIFT                                               (0x0000000000000028U)
#define CSL_PBIST_SCR_SCR5_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_SCR_SCR6_MASK                                                (0x00FF000000000000U)
#define CSL_PBIST_SCR_SCR6_SHIFT                                               (0x0000000000000030U)
#define CSL_PBIST_SCR_SCR6_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_SCR_SCR7_MASK                                                (0xFF00000000000000U)
#define CSL_PBIST_SCR_SCR7_SHIFT                                               (0x0000000000000038U)
#define CSL_PBIST_SCR_SCR7_MAX                                                 (0x00000000000000FFU)

/* CSR */

#define CSL_PBIST_CSR_CSR0_MASK                                                (0x000000FFU)
#define CSL_PBIST_CSR_CSR0_SHIFT                                               (0x00000000U)
#define CSL_PBIST_CSR_CSR0_MAX                                                 (0x000000FFU)

#define CSL_PBIST_CSR_CSR1_MASK                                                (0x0000FF00U)
#define CSL_PBIST_CSR_CSR1_SHIFT                                               (0x00000008U)
#define CSL_PBIST_CSR_CSR1_MAX                                                 (0x000000FFU)

#define CSL_PBIST_CSR_CSR2_MASK                                                (0x00FF0000U)
#define CSL_PBIST_CSR_CSR2_SHIFT                                               (0x00000010U)
#define CSL_PBIST_CSR_CSR2_MAX                                                 (0x000000FFU)

#define CSL_PBIST_CSR_CSR3_MASK                                                (0xFF000000U)
#define CSL_PBIST_CSR_CSR3_SHIFT                                               (0x00000018U)
#define CSL_PBIST_CSR_CSR3_MAX                                                 (0x000000FFU)

/* FDLY */

#define CSL_PBIST_FDLY_FDLY_MASK                                               (0x000000FFU)
#define CSL_PBIST_FDLY_FDLY_SHIFT                                              (0x00000000U)
#define CSL_PBIST_FDLY_FDLY_MAX                                                (0x000000FFU)

/* PACT */

#define CSL_PBIST_PACT_PACT_MASK                                               (0x00000001U)
#define CSL_PBIST_PACT_PACT_SHIFT                                              (0x00000000U)
#define CSL_PBIST_PACT_PACT_MAX                                                (0x00000001U)

/* PID */

#define CSL_PBIST_PID_PID_MASK                                                 (0x0000001FU)
#define CSL_PBIST_PID_PID_SHIFT                                                (0x00000000U)
#define CSL_PBIST_PID_PID_MAX                                                  (0x0000001FU)

/* OVER */

#define CSL_PBIST_OVER_RINFO_MASK                                              (0x00000001U)
#define CSL_PBIST_OVER_RINFO_SHIFT                                             (0x00000000U)
#define CSL_PBIST_OVER_RINFO_MAX                                               (0x00000001U)

#define CSL_PBIST_OVER_READ_MASK                                               (0x00000002U)
#define CSL_PBIST_OVER_READ_SHIFT                                              (0x00000001U)
#define CSL_PBIST_OVER_READ_MAX                                                (0x00000001U)

#define CSL_PBIST_OVER_MM_MASK                                                 (0x00000004U)
#define CSL_PBIST_OVER_MM_SHIFT                                                (0x00000002U)
#define CSL_PBIST_OVER_MM_MAX                                                  (0x00000001U)

#define CSL_PBIST_OVER_ALGO_MASK                                               (0x00000008U)
#define CSL_PBIST_OVER_ALGO_SHIFT                                              (0x00000003U)
#define CSL_PBIST_OVER_ALGO_MAX                                                (0x00000001U)

/* FSRF */

#define CSL_PBIST_FSRF_FRSF0_MASK                                              (0x0000000000000001U)
#define CSL_PBIST_FSRF_FRSF0_SHIFT                                             (0x0000000000000000U)
#define CSL_PBIST_FSRF_FRSF0_MAX                                               (0x0000000000000001U)

#define CSL_PBIST_FSRF_FRSF1_MASK                                              (0x0000000100000000U)
#define CSL_PBIST_FSRF_FRSF1_SHIFT                                             (0x0000000000000020U)
#define CSL_PBIST_FSRF_FRSF1_MAX                                               (0x0000000000000001U)

/* FSRC */

#define CSL_PBIST_FSRC_FSRC0_MASK                                              (0x000000000000000FU)
#define CSL_PBIST_FSRC_FSRC0_SHIFT                                             (0x0000000000000000U)
#define CSL_PBIST_FSRC_FSRC0_MAX                                               (0x000000000000000FU)

#define CSL_PBIST_FSRC_FSRC1_MASK                                              (0x0000000F00000000U)
#define CSL_PBIST_FSRC_FSRC1_SHIFT                                             (0x0000000000000020U)
#define CSL_PBIST_FSRC_FSRC1_MAX                                               (0x000000000000000FU)

/* FSRA */

#define CSL_PBIST_FSRA_FSRA0_MASK                                              (0x000000000000FFFFU)
#define CSL_PBIST_FSRA_FSRA0_SHIFT                                             (0x0000000000000000U)
#define CSL_PBIST_FSRA_FSRA0_MAX                                               (0x000000000000FFFFU)

#define CSL_PBIST_FSRA_FSRA1_MASK                                              (0x0000FFFF00000000U)
#define CSL_PBIST_FSRA_FSRA1_SHIFT                                             (0x0000000000000020U)
#define CSL_PBIST_FSRA_FSRA1_MAX                                               (0x000000000000FFFFU)

/* FSRDL0 */

#define CSL_PBIST_FSRDL0_FSRDL0_MASK                                           (0xFFFFFFFFU)
#define CSL_PBIST_FSRDL0_FSRDL0_SHIFT                                          (0x00000000U)
#define CSL_PBIST_FSRDL0_FSRDL0_MAX                                            (0xFFFFFFFFU)

/* FSRDL1 */

#define CSL_PBIST_FSRDL1_FSRDL1_MASK                                           (0xFFFFFFFFU)
#define CSL_PBIST_FSRDL1_FSRDL1_SHIFT                                          (0x00000000U)
#define CSL_PBIST_FSRDL1_FSRDL1_MAX                                            (0xFFFFFFFFU)

/* MARGIN_MODE */

#define CSL_PBIST_MARGIN_MODE_PBIST_DFT_WRITE_MASK                             (0x00000003U)
#define CSL_PBIST_MARGIN_MODE_PBIST_DFT_WRITE_SHIFT                            (0x00000000U)
#define CSL_PBIST_MARGIN_MODE_PBIST_DFT_WRITE_MAX                              (0x00000003U)

#define CSL_PBIST_MARGIN_MODE_PBIST_DFT_READ_MASK                              (0x0000000CU)
#define CSL_PBIST_MARGIN_MODE_PBIST_DFT_READ_SHIFT                             (0x00000002U)
#define CSL_PBIST_MARGIN_MODE_PBIST_DFT_READ_MAX                               (0x00000003U)

/* WRENZ */

#define CSL_PBIST_WRENZ_WRENZ_MASK                                             (0x00000003U)
#define CSL_PBIST_WRENZ_WRENZ_SHIFT                                            (0x00000000U)
#define CSL_PBIST_WRENZ_WRENZ_MAX                                              (0x00000003U)

/* PAGE_PGS */

#define CSL_PBIST_PAGE_PGS_PGS_MASK                                            (0x00000003U)
#define CSL_PBIST_PAGE_PGS_PGS_SHIFT                                           (0x00000000U)
#define CSL_PBIST_PAGE_PGS_PGS_MAX                                             (0x00000003U)

/* ROM */

#define CSL_PBIST_ROM_ROM_MASK                                                 (0x00000003U)
#define CSL_PBIST_ROM_ROM_SHIFT                                                (0x00000000U)
#define CSL_PBIST_ROM_ROM_MAX                                                  (0x00000003U)

/* ALGO */

#define CSL_PBIST_ALGO_ALGO_0_MASK                                             (0x000000FFU)
#define CSL_PBIST_ALGO_ALGO_0_SHIFT                                            (0x00000000U)
#define CSL_PBIST_ALGO_ALGO_0_MAX                                              (0x000000FFU)

#define CSL_PBIST_ALGO_ALGO_1_MASK                                             (0x0000FF00U)
#define CSL_PBIST_ALGO_ALGO_1_SHIFT                                            (0x00000008U)
#define CSL_PBIST_ALGO_ALGO_1_MAX                                              (0x000000FFU)

#define CSL_PBIST_ALGO_ALGO_2_MASK                                             (0x00FF0000U)
#define CSL_PBIST_ALGO_ALGO_2_SHIFT                                            (0x00000010U)
#define CSL_PBIST_ALGO_ALGO_2_MAX                                              (0x000000FFU)

#define CSL_PBIST_ALGO_ALGO_3_MASK                                             (0xFF000000U)
#define CSL_PBIST_ALGO_ALGO_3_SHIFT                                            (0x00000018U)
#define CSL_PBIST_ALGO_ALGO_3_MAX                                              (0x000000FFU)

/* RINFO */

#define CSL_PBIST_RINFO_L0_MASK                                                (0x00000000000000FFU)
#define CSL_PBIST_RINFO_L0_SHIFT                                               (0x0000000000000000U)
#define CSL_PBIST_RINFO_L0_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_RINFO_L1_MASK                                                (0x000000000000FF00U)
#define CSL_PBIST_RINFO_L1_SHIFT                                               (0x0000000000000008U)
#define CSL_PBIST_RINFO_L1_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_RINFO_L2_MASK                                                (0x0000000000FF0000U)
#define CSL_PBIST_RINFO_L2_SHIFT                                               (0x0000000000000010U)
#define CSL_PBIST_RINFO_L2_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_RINFO_L3_MASK                                                (0x00000000FF000000U)
#define CSL_PBIST_RINFO_L3_SHIFT                                               (0x0000000000000018U)
#define CSL_PBIST_RINFO_L3_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_RINFO_U0_MASK                                                (0x000000FF00000000U)
#define CSL_PBIST_RINFO_U0_SHIFT                                               (0x0000000000000020U)
#define CSL_PBIST_RINFO_U0_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_RINFO_U1_MASK                                                (0x0000FF0000000000U)
#define CSL_PBIST_RINFO_U1_SHIFT                                               (0x0000000000000028U)
#define CSL_PBIST_RINFO_U1_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_RINFO_U2_MASK                                                (0x00FF000000000000U)
#define CSL_PBIST_RINFO_U2_SHIFT                                               (0x0000000000000030U)
#define CSL_PBIST_RINFO_U2_MAX                                                 (0x00000000000000FFU)

#define CSL_PBIST_RINFO_U3_MASK                                                (0xFF00000000000000U)
#define CSL_PBIST_RINFO_U3_SHIFT                                               (0x0000000000000038U)
#define CSL_PBIST_RINFO_U3_MAX                                                 (0x00000000000000FFU)

#ifdef __cplusplus
}
#endif
#endif
