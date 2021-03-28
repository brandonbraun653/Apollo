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
#ifndef CSLR_I2C_H
#define CSLR_I2C_H

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for TOP_LEVEL
**************************************************************************/
typedef struct {
    volatile Uint32 ICOAR;
    volatile Uint32 ICIMR;
    volatile Uint32 ICSTR;
    volatile Uint32 ICCLKL;
    volatile Uint32 ICCLKH;
    volatile Uint32 ICCNT;
    volatile Uint32 ICDRR;
    volatile Uint32 ICSAR;
    volatile Uint32 ICDXR;
    volatile Uint32 ICMDR;
    volatile Uint32 ICIVR;
    volatile Uint32 ICEMDR;
    volatile Uint32 ICPSC;
    volatile Uint32 ICPID1;
    volatile Uint32 ICPID2;
    volatile Uint32 ICDMAC;
    volatile Uint8  RSVD0[8];
    volatile Uint32 ICPFUNC;
    volatile Uint32 ICPDIR;
    volatile Uint32 ICPDIN;
    volatile Uint32 ICPDOUT;
    volatile Uint32 ICPDSET;
    volatile Uint32 ICPDCLR;
    volatile Uint32 ICPDRV;
    volatile Uint32 ICPPDIS;
    volatile Uint32 ICPPSEL;
    volatile Uint32 ICPSRS;
} CSL_I2cRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* ICOAR */
#define CSL_I2C_ICOAR                                           (0x0U)

/* ICIMR */
#define CSL_I2C_ICIMR                                           (0x4U)

/* ICSTR */
#define CSL_I2C_ICSTR                                           (0x8U)

/* ICCLKL */
#define CSL_I2C_ICCLKL                                          (0xCU)

/* ICCLKH */
#define CSL_I2C_ICCLKH                                          (0x10U)

/* ICCNT */
#define CSL_I2C_ICCNT                                           (0x14U)

/* ICDRR */
#define CSL_I2C_ICDRR                                           (0x18U)

/* ICSAR */
#define CSL_I2C_ICSAR                                           (0x1CU)

/* ICDXR */
#define CSL_I2C_ICDXR                                           (0x20U)

/* ICMDR */
#define CSL_I2C_ICMDR                                           (0x24U)

/* ICIVR */
#define CSL_I2C_ICIVR                                           (0x28U)

/* ICEMDR */
#define CSL_I2C_ICEMDR                                          (0x2CU)

/* ICPSC */
#define CSL_I2C_ICPSC                                           (0x30U)

/* ICPID1 */
#define CSL_I2C_ICPID1                                          (0x34U)

/* ICPID2 */
#define CSL_I2C_ICPID2                                          (0x38U)

/* ICDMAC */
#define CSL_I2C_ICDMAC                                          (0x3CU)

/* ICPFUNC */
#define CSL_I2C_ICPFUNC                                         (0x48U)

/* ICPDIR */
#define CSL_I2C_ICPDIR                                          (0x4CU)

/* ICPDIN */
#define CSL_I2C_ICPDIN                                          (0x50U)

/* ICPDOUT */
#define CSL_I2C_ICPDOUT                                         (0x54U)

/* ICPDSET */
#define CSL_I2C_ICPDSET                                         (0x58U)

/* ICPDCLR */
#define CSL_I2C_ICPDCLR                                         (0x5CU)

/* ICPDRV */
#define CSL_I2C_ICPDRV                                          (0x60U)

/* ICPPDIS */
#define CSL_I2C_ICPPDIS                                         (0x64U)

/* ICPPSEL */
#define CSL_I2C_ICPPSEL                                         (0x68U)

/* ICPSRS */
#define CSL_I2C_ICPSRS                                          (0x6CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* ICOAR */

#define CSL_I2C_ICOAR_OADDR_MASK                                (0x000003FFU)
#define CSL_I2C_ICOAR_OADDR_SHIFT                               (0U)
#define CSL_I2C_ICOAR_OADDR_RESETVAL                            (0x00000000U)
#define CSL_I2C_ICOAR_OADDR_MAX                                 (0x000003ffU)

#define CSL_I2C_ICOAR_RESETVAL                                  (0x00000000U)

/* ICIMR */

#define CSL_I2C_ICIMR_AL_MASK                                   (0x00000001U)
#define CSL_I2C_ICIMR_AL_SHIFT                                  (0U)
#define CSL_I2C_ICIMR_AL_RESETVAL                               (0x00000000U)
#define CSL_I2C_ICIMR_AL_DISABLE                                (0x00000000U)
#define CSL_I2C_ICIMR_AL_ENABLE                                 (0x00000001U)

#define CSL_I2C_ICIMR_NACK_MASK                                 (0x00000002U)
#define CSL_I2C_ICIMR_NACK_SHIFT                                (1U)
#define CSL_I2C_ICIMR_NACK_RESETVAL                             (0x00000000U)
#define CSL_I2C_ICIMR_NACK_DISABLE                              (0x00000000U)
#define CSL_I2C_ICIMR_NACK_ENABLE                               (0x00000001U)

#define CSL_I2C_ICIMR_ARDY_MASK                                 (0x00000004U)
#define CSL_I2C_ICIMR_ARDY_SHIFT                                (2U)
#define CSL_I2C_ICIMR_ARDY_RESETVAL                             (0x00000000U)
#define CSL_I2C_ICIMR_ARDY_DISABLE                              (0x00000000U)
#define CSL_I2C_ICIMR_ARDY_ENABLE                               (0x00000001U)

#define CSL_I2C_ICIMR_ICRRDY_MASK                               (0x00000008U)
#define CSL_I2C_ICIMR_ICRRDY_SHIFT                              (3U)
#define CSL_I2C_ICIMR_ICRRDY_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICIMR_ICRRDY_DISABLE                            (0x00000000U)
#define CSL_I2C_ICIMR_ICRRDY_ENABLE                             (0x00000001U)

#define CSL_I2C_ICIMR_ICXRDY_MASK                               (0x00000010U)
#define CSL_I2C_ICIMR_ICXRDY_SHIFT                              (4U)
#define CSL_I2C_ICIMR_ICXRDY_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICIMR_ICXRDY_DISABLE                            (0x00000000U)
#define CSL_I2C_ICIMR_ICXRDY_ENABLE                             (0x00000001U)

#define CSL_I2C_ICIMR_SCD_MASK                                  (0x00000020U)
#define CSL_I2C_ICIMR_SCD_SHIFT                                 (5U)
#define CSL_I2C_ICIMR_SCD_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICIMR_SCD_DISABLE                               (0x00000000U)
#define CSL_I2C_ICIMR_SCD_ENABLE                                (0x00000001U)

#define CSL_I2C_ICIMR_AAS_MASK                                  (0x00000040U)
#define CSL_I2C_ICIMR_AAS_SHIFT                                 (6U)
#define CSL_I2C_ICIMR_AAS_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICIMR_AAS_DISABLE                               (0x00000000U)
#define CSL_I2C_ICIMR_AAS_ENABLE                                (0x00000001U)

#define CSL_I2C_ICIMR_RESETVAL                                  (0x00000000U)

/* ICSTR */

#define CSL_I2C_ICSTR_AL_MASK                                   (0x00000001U)
#define CSL_I2C_ICSTR_AL_SHIFT                                  (0U)
#define CSL_I2C_ICSTR_AL_RESETVAL                               (0x00000000U)
#define CSL_I2C_ICSTR_AL_MAX                                    (0x00000001U)

#define CSL_I2C_ICSTR_NACK_MASK                                 (0x00000002U)
#define CSL_I2C_ICSTR_NACK_SHIFT                                (1U)
#define CSL_I2C_ICSTR_NACK_RESETVAL                             (0x00000000U)
#define CSL_I2C_ICSTR_NACK_MAX                                  (0x00000001U)

#define CSL_I2C_ICSTR_ARDY_MASK                                 (0x00000004U)
#define CSL_I2C_ICSTR_ARDY_SHIFT                                (2U)
#define CSL_I2C_ICSTR_ARDY_RESETVAL                             (0x00000000U)
#define CSL_I2C_ICSTR_ARDY_MAX                                  (0x00000001U)

#define CSL_I2C_ICSTR_ICRRDY_MASK                               (0x00000008U)
#define CSL_I2C_ICSTR_ICRRDY_SHIFT                              (3U)
#define CSL_I2C_ICSTR_ICRRDY_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICSTR_ICRRDY_MAX                                (0x00000001U)

#define CSL_I2C_ICSTR_ICXRDY_MASK                               (0x00000010U)
#define CSL_I2C_ICSTR_ICXRDY_SHIFT                              (4U)
#define CSL_I2C_ICSTR_ICXRDY_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICSTR_ICXRDY_MAX                                (0x00000001U)

#define CSL_I2C_ICSTR_SCD_MASK                                  (0x00000020U)
#define CSL_I2C_ICSTR_SCD_SHIFT                                 (5U)
#define CSL_I2C_ICSTR_SCD_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICSTR_SCD_MAX                                   (0x00000001U)

#define CSL_I2C_ICSTR_AD0_MASK                                  (0x00000100U)
#define CSL_I2C_ICSTR_AD0_SHIFT                                 (8U)
#define CSL_I2C_ICSTR_AD0_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICSTR_AD0_MAX                                   (0x00000001U)

#define CSL_I2C_ICSTR_AAS_MASK                                  (0x00000200U)
#define CSL_I2C_ICSTR_AAS_SHIFT                                 (9U)
#define CSL_I2C_ICSTR_AAS_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICSTR_AAS_MAX                                   (0x00000001U)

#define CSL_I2C_ICSTR_XSMT__MASK                                (0x00000400U)
#define CSL_I2C_ICSTR_XSMT__SHIFT                               (10U)
#define CSL_I2C_ICSTR_XSMT__RESETVAL                            (0x00000000U)
#define CSL_I2C_ICSTR_XSMT__MAX                                 (0x00000001U)

#define CSL_I2C_ICSTR_RSFULL_MASK                               (0x00000800U)
#define CSL_I2C_ICSTR_RSFULL_SHIFT                              (11U)
#define CSL_I2C_ICSTR_RSFULL_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICSTR_RSFULL_MAX                                (0x00000001U)

#define CSL_I2C_ICSTR_BB_MASK                                   (0x00001000U)
#define CSL_I2C_ICSTR_BB_SHIFT                                  (12U)
#define CSL_I2C_ICSTR_BB_RESETVAL                               (0x00000000U)
#define CSL_I2C_ICSTR_BB_MAX                                    (0x00000001U)

#define CSL_I2C_ICSTR_NACKSNT_MASK                              (0x00002000U)
#define CSL_I2C_ICSTR_NACKSNT_SHIFT                             (13U)
#define CSL_I2C_ICSTR_NACKSNT_RESETVAL                          (0x00000000U)
#define CSL_I2C_ICSTR_NACKSNT_MAX                               (0x00000001U)

#define CSL_I2C_ICSTR_SDIR_MASK                                 (0x00004000U)
#define CSL_I2C_ICSTR_SDIR_SHIFT                                (14U)
#define CSL_I2C_ICSTR_SDIR_RESETVAL                             (0x00000000U)
#define CSL_I2C_ICSTR_SDIR_MAX                                  (0x00000001U)

#define CSL_I2C_ICSTR_RESETVAL                                  (0x00000000U)

/* ICCLKL */

#define CSL_I2C_ICCLKL_ICCL_MASK                                (0x0000FFFFU)
#define CSL_I2C_ICCLKL_ICCL_SHIFT                               (0U)
#define CSL_I2C_ICCLKL_ICCL_RESETVAL                            (0x00000000U)
#define CSL_I2C_ICCLKL_ICCL_MAX                                 (0x0000ffffU)

#define CSL_I2C_ICCLKL_RESETVAL                                 (0x00000000U)

/* ICCLKH */

#define CSL_I2C_ICCLKH_ICCH_MASK                                (0x0000FFFFU)
#define CSL_I2C_ICCLKH_ICCH_SHIFT                               (0U)
#define CSL_I2C_ICCLKH_ICCH_RESETVAL                            (0x00000000U)
#define CSL_I2C_ICCLKH_ICCH_MAX                                 (0x0000ffffU)

#define CSL_I2C_ICCLKH_RESETVAL                                 (0x00000000U)

/* ICCNT */

#define CSL_I2C_ICCNT_ICDC_MASK                                 (0x0000FFFFU)
#define CSL_I2C_ICCNT_ICDC_SHIFT                                (0U)
#define CSL_I2C_ICCNT_ICDC_RESETVAL                             (0x00000000U)
#define CSL_I2C_ICCNT_ICDC_MAX                                  (0x0000ffffU)

#define CSL_I2C_ICCNT_RESETVAL                                  (0x00000000U)

/* ICDRR */

#define CSL_I2C_ICDRR_D_MASK                                    (0x000000FFU)
#define CSL_I2C_ICDRR_D_SHIFT                                   (0U)
#define CSL_I2C_ICDRR_D_RESETVAL                                (0x00000000U)
#define CSL_I2C_ICDRR_D_MAX                                     (0x000000ffU)

#define CSL_I2C_ICDRR_RESETVAL                                  (0x00000000U)

/* ICSAR */

#define CSL_I2C_ICSAR_SADDR_MASK                                (0x000003FFU)
#define CSL_I2C_ICSAR_SADDR_SHIFT                               (0U)
#define CSL_I2C_ICSAR_SADDR_RESETVAL                            (0x00000000U)
#define CSL_I2C_ICSAR_SADDR_MAX                                 (0x000003ffU)

#define CSL_I2C_ICSAR_RESETVAL                                  (0x00000000U)

/* ICDXR */

#define CSL_I2C_ICDXR_D_MASK                                    (0x000000FFU)
#define CSL_I2C_ICDXR_D_SHIFT                                   (0U)
#define CSL_I2C_ICDXR_D_RESETVAL                                (0x00000000U)
#define CSL_I2C_ICDXR_D_MAX                                     (0x000000ffU)

#define CSL_I2C_ICDXR_RESETVAL                                  (0x00000000U)

/* ICMDR */

#define CSL_I2C_ICMDR_BC_MASK                                   (0x00000007U)
#define CSL_I2C_ICMDR_BC_SHIFT                                  (0U)
#define CSL_I2C_ICMDR_BC_RESETVAL                               (0x00000000U)
#define CSL_I2C_ICMDR_BC_MAX                                    (0x00000007U)

#define CSL_I2C_ICMDR_FDF_MASK                                  (0x00000008U)
#define CSL_I2C_ICMDR_FDF_SHIFT                                 (3U)
#define CSL_I2C_ICMDR_FDF_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICMDR_FDF_MAX                                   (0x00000001U)

#define CSL_I2C_ICMDR_STB_MASK                                  (0x00000010U)
#define CSL_I2C_ICMDR_STB_SHIFT                                 (4U)
#define CSL_I2C_ICMDR_STB_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICMDR_STB_MAX                                   (0x00000001U)

#define CSL_I2C_ICMDR_IRS_MASK                                  (0x00000020U)
#define CSL_I2C_ICMDR_IRS_SHIFT                                 (5U)
#define CSL_I2C_ICMDR_IRS_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICMDR_IRS_MAX                                   (0x00000001U)

#define CSL_I2C_ICMDR_DLB_MASK                                  (0x00000040U)
#define CSL_I2C_ICMDR_DLB_SHIFT                                 (6U)
#define CSL_I2C_ICMDR_DLB_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICMDR_DLB_MAX                                   (0x00000001U)

#define CSL_I2C_ICMDR_RM_MASK                                   (0x00000080U)
#define CSL_I2C_ICMDR_RM_SHIFT                                  (7U)
#define CSL_I2C_ICMDR_RM_RESETVAL                               (0x00000000U)
#define CSL_I2C_ICMDR_RM_MAX                                    (0x00000001U)

#define CSL_I2C_ICMDR_XA_MASK                                   (0x00000100U)
#define CSL_I2C_ICMDR_XA_SHIFT                                  (8U)
#define CSL_I2C_ICMDR_XA_RESETVAL                               (0x00000000U)
#define CSL_I2C_ICMDR_XA_MAX                                    (0x00000001U)

#define CSL_I2C_ICMDR_TRX_MASK                                  (0x00000200U)
#define CSL_I2C_ICMDR_TRX_SHIFT                                 (9U)
#define CSL_I2C_ICMDR_TRX_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICMDR_TRX_MAX                                   (0x00000001U)

#define CSL_I2C_ICMDR_MST_MASK                                  (0x00000400U)
#define CSL_I2C_ICMDR_MST_SHIFT                                 (10U)
#define CSL_I2C_ICMDR_MST_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICMDR_MST_MAX                                   (0x00000001U)

#define CSL_I2C_ICMDR_STP_MASK                                  (0x00000800U)
#define CSL_I2C_ICMDR_STP_SHIFT                                 (11U)
#define CSL_I2C_ICMDR_STP_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICMDR_STP_MAX                                   (0x00000001U)

#define CSL_I2C_ICMDR_RES_MASK                                  (0x00001000U)
#define CSL_I2C_ICMDR_RES_SHIFT                                 (12U)
#define CSL_I2C_ICMDR_RES_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICMDR_RES_MAX                                   (0x00000001U)

#define CSL_I2C_ICMDR_STT_MASK                                  (0x00002000U)
#define CSL_I2C_ICMDR_STT_SHIFT                                 (13U)
#define CSL_I2C_ICMDR_STT_RESETVAL                              (0x00000000U)
#define CSL_I2C_ICMDR_STT_MAX                                   (0x00000001U)

#define CSL_I2C_ICMDR_FREE_MASK                                 (0x00004000U)
#define CSL_I2C_ICMDR_FREE_SHIFT                                (14U)
#define CSL_I2C_ICMDR_FREE_RESETVAL                             (0x00000000U)
#define CSL_I2C_ICMDR_FREE_MAX                                  (0x00000001U)

#define CSL_I2C_ICMDR_NACKMOD_MASK                              (0x00008000U)
#define CSL_I2C_ICMDR_NACKMOD_SHIFT                             (15U)
#define CSL_I2C_ICMDR_NACKMOD_RESETVAL                          (0x00000000U)
#define CSL_I2C_ICMDR_NACKMOD_MAX                               (0x00000001U)

#define CSL_I2C_ICMDR_RESETVAL                                  (0x00000000U)

/* ICIVR */

#define CSL_I2C_ICIVR_INTCODE_MASK                              (0x00000007U)
#define CSL_I2C_ICIVR_INTCODE_SHIFT                             (0U)
#define CSL_I2C_ICIVR_INTCODE_RESETVAL                          (0x00000000U)
#define CSL_I2C_ICIVR_INTCODE_NONE                              (0x00000000U)
#define CSL_I2C_ICIVR_INTCODE_AL                                (0x00000001U)
#define CSL_I2C_ICIVR_INTCODE_NACK                              (0x00000002U)
#define CSL_I2C_ICIVR_INTCODE_RAR                               (0x00000003U)
#define CSL_I2C_ICIVR_INTCODE_RDR                               (0x00000004U)
#define CSL_I2C_ICIVR_INTCODE_TDR                               (0x00000005U)
#define CSL_I2C_ICIVR_INTCODE_SCD                               (0x00000006U)
#define CSL_I2C_ICIVR_INTCODE_AAS                               (0x00000007U)

#define CSL_I2C_ICIVR_TESTMD_MASK                               (0x00000007U)
#define CSL_I2C_ICIVR_TESTMD_SHIFT                              (0U)
#define CSL_I2C_ICIVR_TESTMD_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICIVR_TESTMD_MAX                                (0x00000007U)

#define CSL_I2C_ICIVR_RESETVAL                                  (0x00000000U)

/* ICEMDR */

#define CSL_I2C_ICEMDR_BCM_MASK                                 (0x00000001U)
#define CSL_I2C_ICEMDR_BCM_SHIFT                                (0U)
#define CSL_I2C_ICEMDR_BCM_RESETVAL                             (0x00000000U)
#define CSL_I2C_ICEMDR_BCM_MAX                                  (0x00000001U)

#define CSL_I2C_ICEMDR_IGNACK_MASK                              (0x00000002U)
#define CSL_I2C_ICEMDR_IGNACK_SHIFT                             (1U)
#define CSL_I2C_ICEMDR_IGNACK_RESETVAL                          (0x00000000U)
#define CSL_I2C_ICEMDR_IGNACK_MAX                               (0x00000001U)

#define CSL_I2C_ICEMDR_RESETVAL                                 (0x00000000U)

/* ICPSC */

#define CSL_I2C_ICPSC_IPSC_MASK                                 (0x000000FFU)
#define CSL_I2C_ICPSC_IPSC_SHIFT                                (0U)
#define CSL_I2C_ICPSC_IPSC_RESETVAL                             (0x00000000U)
#define CSL_I2C_ICPSC_IPSC_MAX                                  (0x000000ffU)

#define CSL_I2C_ICPSC_RESETVAL                                  (0x00000000U)

/* ICPID1 */

#define CSL_I2C_ICPID1_REVISION_MASK                            (0x000000FFU)
#define CSL_I2C_ICPID1_REVISION_SHIFT                           (0U)
#define CSL_I2C_ICPID1_REVISION_RESETVAL                        (0x00000000U)
#define CSL_I2C_ICPID1_REVISION_MAX                             (0x000000ffU)

#define CSL_I2C_ICPID1_CLASS_MASK                               (0x0000FF00U)
#define CSL_I2C_ICPID1_CLASS_SHIFT                              (8U)
#define CSL_I2C_ICPID1_CLASS_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICPID1_CLASS_MAX                                (0x000000ffU)

#define CSL_I2C_ICPID1_RESETVAL                                 (0x00000000U)

/* ICPID2 */

#define CSL_I2C_ICPID2_TYPE_MASK                                (0x000000FFU)
#define CSL_I2C_ICPID2_TYPE_SHIFT                               (0U)
#define CSL_I2C_ICPID2_TYPE_RESETVAL                            (0x00000000U)
#define CSL_I2C_ICPID2_TYPE_MAX                                 (0x000000ffU)

#define CSL_I2C_ICPID2_RESETVAL                                 (0x00000000U)

/* ICDMAC */

#define CSL_I2C_ICDMAC_RXDMAEN_MASK                             (0x00000001U)
#define CSL_I2C_ICDMAC_RXDMAEN_SHIFT                            (0U)
#define CSL_I2C_ICDMAC_RXDMAEN_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICDMAC_RXDMAEN_MAX                              (0x00000001U)

#define CSL_I2C_ICDMAC_TXDMAEN_MASK                             (0x00000002U)
#define CSL_I2C_ICDMAC_TXDMAEN_SHIFT                            (1U)
#define CSL_I2C_ICDMAC_TXDMAEN_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICDMAC_TXDMAEN_MAX                              (0x00000001U)

#define CSL_I2C_ICDMAC_RESETVAL                                 (0x00000000U)

/* ICPFUNC */

#define CSL_I2C_ICPFUNC_PFUNC0_MASK                             (0x00000001U)
#define CSL_I2C_ICPFUNC_PFUNC0_SHIFT                            (0U)
#define CSL_I2C_ICPFUNC_PFUNC0_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICPFUNC_PFUNC0_MAX                              (0x00000001U)

#define CSL_I2C_ICPFUNC_RESETVAL                                (0x00000000U)

/* ICPDIR */

#define CSL_I2C_ICPDIR_PDIR0_MASK                               (0x00000001U)
#define CSL_I2C_ICPDIR_PDIR0_SHIFT                              (0U)
#define CSL_I2C_ICPDIR_PDIR0_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICPDIR_PDIR0_MAX                                (0x00000001U)

#define CSL_I2C_ICPDIR_PDIR1_MASK                               (0x00000002U)
#define CSL_I2C_ICPDIR_PDIR1_SHIFT                              (1U)
#define CSL_I2C_ICPDIR_PDIR1_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICPDIR_PDIR1_MAX                                (0x00000001U)

#define CSL_I2C_ICPDIR_RESETVAL                                 (0x00000000U)

/* ICPDIN */

#define CSL_I2C_ICPDIN_PDIN0_MASK                               (0x00000001U)
#define CSL_I2C_ICPDIN_PDIN0_SHIFT                              (0U)
#define CSL_I2C_ICPDIN_PDIN0_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICPDIN_PDIN0_MAX                                (0x00000001U)

#define CSL_I2C_ICPDIN_PDIN1_MASK                               (0x00000002U)
#define CSL_I2C_ICPDIN_PDIN1_SHIFT                              (1U)
#define CSL_I2C_ICPDIN_PDIN1_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICPDIN_PDIN1_MAX                                (0x00000001U)

#define CSL_I2C_ICPDIN_RESETVAL                                 (0x00000000U)

/* ICPDOUT */

#define CSL_I2C_ICPDOUT_PDOUT0_MASK                             (0x00000001U)
#define CSL_I2C_ICPDOUT_PDOUT0_SHIFT                            (0U)
#define CSL_I2C_ICPDOUT_PDOUT0_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICPDOUT_PDOUT0_MAX                              (0x00000001U)

#define CSL_I2C_ICPDOUT_PDOUT1_MASK                             (0x00000002U)
#define CSL_I2C_ICPDOUT_PDOUT1_SHIFT                            (1U)
#define CSL_I2C_ICPDOUT_PDOUT1_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICPDOUT_PDOUT1_MAX                              (0x00000001U)

#define CSL_I2C_ICPDOUT_RESETVAL                                (0x00000000U)

/* ICPDSET */

#define CSL_I2C_ICPDSET_PDSET0_MASK                             (0x00000001U)
#define CSL_I2C_ICPDSET_PDSET0_SHIFT                            (0U)
#define CSL_I2C_ICPDSET_PDSET0_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICPDSET_PDSET0_MAX                              (0x00000001U)

#define CSL_I2C_ICPDSET_PDSET1_MASK                             (0x00000002U)
#define CSL_I2C_ICPDSET_PDSET1_SHIFT                            (1U)
#define CSL_I2C_ICPDSET_PDSET1_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICPDSET_PDSET1_MAX                              (0x00000001U)

#define CSL_I2C_ICPDSET_RESETVAL                                (0x00000000U)

/* ICPDCLR */

#define CSL_I2C_ICPDCLR_PDCLR0_MASK                             (0x00000001U)
#define CSL_I2C_ICPDCLR_PDCLR0_SHIFT                            (0U)
#define CSL_I2C_ICPDCLR_PDCLR0_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICPDCLR_PDCLR0_MAX                              (0x00000001U)

#define CSL_I2C_ICPDCLR_PDCLR1_MASK                             (0x00000002U)
#define CSL_I2C_ICPDCLR_PDCLR1_SHIFT                            (1U)
#define CSL_I2C_ICPDCLR_PDCLR1_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICPDCLR_PDCLR1_MAX                              (0x00000001U)

#define CSL_I2C_ICPDCLR_RESETVAL                                (0x00000000U)

/* ICPDRV */

#define CSL_I2C_ICPDRV_PDRV0_MASK                               (0x00000001U)
#define CSL_I2C_ICPDRV_PDRV0_SHIFT                              (0U)
#define CSL_I2C_ICPDRV_PDRV0_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICPDRV_PDRV0_MAX                                (0x00000001U)

#define CSL_I2C_ICPDRV_PDRV1_MASK                               (0x00000002U)
#define CSL_I2C_ICPDRV_PDRV1_SHIFT                              (1U)
#define CSL_I2C_ICPDRV_PDRV1_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICPDRV_PDRV1_MAX                                (0x00000001U)

#define CSL_I2C_ICPDRV_RESETVAL                                 (0x00000000U)

/* ICPPDIS */

#define CSL_I2C_ICPPDIS_PPDIS0_MASK                             (0x00000001U)
#define CSL_I2C_ICPPDIS_PPDIS0_SHIFT                            (0U)
#define CSL_I2C_ICPPDIS_PPDIS0_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICPPDIS_PPDIS0_MAX                              (0x00000001U)

#define CSL_I2C_ICPPDIS_PPDIS1_MASK                             (0x00000002U)
#define CSL_I2C_ICPPDIS_PPDIS1_SHIFT                            (1U)
#define CSL_I2C_ICPPDIS_PPDIS1_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICPPDIS_PPDIS1_MAX                              (0x00000001U)

#define CSL_I2C_ICPPDIS_RESETVAL                                (0x00000000U)

/* ICPPSEL */

#define CSL_I2C_ICPPSEL_PPSEL0_MASK                             (0x00000001U)
#define CSL_I2C_ICPPSEL_PPSEL0_SHIFT                            (0U)
#define CSL_I2C_ICPPSEL_PPSEL0_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICPPSEL_PPSEL0_MAX                              (0x00000001U)

#define CSL_I2C_ICPPSEL_PPSEL1_MASK                             (0x00000002U)
#define CSL_I2C_ICPPSEL_PPSEL1_SHIFT                            (1U)
#define CSL_I2C_ICPPSEL_PPSEL1_RESETVAL                         (0x00000000U)
#define CSL_I2C_ICPPSEL_PPSEL1_MAX                              (0x00000001U)

#define CSL_I2C_ICPPSEL_RESETVAL                                (0x00000000U)

/* ICPSRS */

#define CSL_I2C_ICPSRS_PSRS0_MASK                               (0x00000001U)
#define CSL_I2C_ICPSRS_PSRS0_SHIFT                              (0U)
#define CSL_I2C_ICPSRS_PSRS0_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICPSRS_PSRS0_MAX                                (0x00000001U)

#define CSL_I2C_ICPSRS_PSRS1_MASK                               (0x00000002U)
#define CSL_I2C_ICPSRS_PSRS1_SHIFT                              (1U)
#define CSL_I2C_ICPSRS_PSRS1_RESETVAL                           (0x00000000U)
#define CSL_I2C_ICPSRS_PSRS1_MAX                                (0x00000001U)

#define CSL_I2C_ICPSRS_RESETVAL                                 (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
