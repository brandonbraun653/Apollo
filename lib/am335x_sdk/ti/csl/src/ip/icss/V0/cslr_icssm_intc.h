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
#ifndef CSLR_ICSSM_INTC_H_
#define CSLR_ICSSM_INTC_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for intcaddressBlockTable
**************************************************************************/
typedef struct {
    volatile Uint32 REVID;
    volatile Uint32 CR;
    volatile Uint8  RSVD0[8];
    volatile Uint32 GER;
    volatile Uint8  RSVD1[8];
    volatile Uint32 GNLR;
    volatile Uint32 SISR;
    volatile Uint32 SICR;
    volatile Uint32 EISR;
    volatile Uint32 EICR;
    volatile Uint8  RSVD2[4];
    volatile Uint32 HIEISR;
    volatile Uint32 HIDISR;
    volatile Uint8  RSVD3[68];
    volatile Uint32 GPIR;
    volatile Uint8  RSVD4[380];
    volatile Uint32 SRSR0;
    volatile Uint32 SRSR1;
    volatile Uint8  RSVD5[120];
    volatile Uint32 SECR0;
    volatile Uint32 SECR1;
    volatile Uint8  RSVD6[120];
    volatile Uint32 ESR0;
    volatile Uint32 ERS1;
    volatile Uint8  RSVD7[120];
    volatile Uint32 ECR0;
    volatile Uint32 ECR1;
    volatile Uint8  RSVD8[120];
    volatile Uint32 CMR0;
    volatile Uint32 CMR1;
    volatile Uint32 CMR2;
    volatile Uint32 CMR3;
    volatile Uint32 CMR4;
    volatile Uint32 CMR5;
    volatile Uint32 CMR6;
    volatile Uint32 CMR7;
    volatile Uint32 CMR8;
    volatile Uint32 CMR9;
    volatile Uint32 CMR10;
    volatile Uint32 CMR11;
    volatile Uint32 CMR12;
    volatile Uint32 CMR13;
    volatile Uint32 CMR14;
    volatile Uint32 CMR15;
    volatile Uint8  RSVD9[960];
    volatile Uint32 HMR0;
    volatile Uint32 HMR1;
    volatile Uint32 HMR2;
    volatile Uint8  RSVD10[244];
    volatile Uint32 HIPIR0;
    volatile Uint32 HIPIR1;
    volatile Uint32 HIPIR2;
    volatile Uint32 HIPIR3;
    volatile Uint32 HIPIR4;
    volatile Uint32 HIPIR5;
    volatile Uint32 HIPIR6;
    volatile Uint32 HIPIR7;
    volatile Uint32 HIPIR8;
    volatile Uint32 HIPIR9;
    volatile Uint8  RSVD11[984];
    volatile Uint32 SIPR0;
    volatile Uint32 SIPR1;
    volatile Uint8  RSVD12[120];
    volatile Uint32 SITR0;
    volatile Uint32 SITR1;
    volatile Uint8  RSVD13[888];
    volatile Uint32 HINLR0;
    volatile Uint32 HINLR1;
    volatile Uint32 HINLR2;
    volatile Uint32 HINLR3;
    volatile Uint32 HINLR4;
    volatile Uint32 HINLR5;
    volatile Uint32 HINLR6;
    volatile Uint32 HINLR7;
    volatile Uint32 HINLR8;
    volatile Uint32 HINLR9;
    volatile Uint8  RSVD14[984];
    volatile Uint32 HIER;
} CSL_icssm_intcRegs;


/**************************************************************************
* Register Macros
**************************************************************************/
#define CSL_ICSSM_INTC_REVID                                    (0x0U)
#define CSL_ICSSM_INTC_CR                                       (0x4U)
#define CSL_ICSSM_INTC_SIPR0                                    (0xD00U)
#define CSL_ICSSM_INTC_SIPR1                                    (0xD04U)
#define CSL_ICSSM_INTC_SITR0                                    (0xD80U)
#define CSL_ICSSM_INTC_SITR1                                    (0xD84U)
#define CSL_ICSSM_INTC_SISR                                     (0x20U)
#define CSL_ICSSM_INTC_SICR                                     (0x24U)
#define CSL_ICSSM_INTC_SRSR0                                    (0x200U)
#define CSL_ICSSM_INTC_SECR0                                    (0x280U)
#define CSL_ICSSM_INTC_SRSR1                                    (0x204U)
#define CSL_ICSSM_INTC_SECR1                                    (0x284U)
#define CSL_ICSSM_INTC_EISR                                     (0x28U)
#define CSL_ICSSM_INTC_EICR                                     (0x2CU)
#define CSL_ICSSM_INTC_ESR0                                     (0x300U)
#define CSL_ICSSM_INTC_ECR0                                     (0x380U)
#define CSL_ICSSM_INTC_ERS1                                     (0x304U)
#define CSL_ICSSM_INTC_ECR1                                     (0x384U)
#define CSL_ICSSM_INTC_CMR0                                     (0x400U)
#define CSL_ICSSM_INTC_CMR1                                     (0x404U)
#define CSL_ICSSM_INTC_CMR2                                     (0x408U)
#define CSL_ICSSM_INTC_CMR3                                     (0x40CU)
#define CSL_ICSSM_INTC_CMR4                                     (0x410U)
#define CSL_ICSSM_INTC_CMR5                                     (0x414U)
#define CSL_ICSSM_INTC_CMR6                                     (0x418U)
#define CSL_ICSSM_INTC_CMR7                                     (0x41CU)
#define CSL_ICSSM_INTC_CMR8                                     (0x420U)
#define CSL_ICSSM_INTC_CMR9                                     (0x424U)
#define CSL_ICSSM_INTC_CMR10                                    (0x428U)
#define CSL_ICSSM_INTC_CMR11                                    (0x42CU)
#define CSL_ICSSM_INTC_CMR12                                    (0x430U)
#define CSL_ICSSM_INTC_CMR13                                    (0x434U)
#define CSL_ICSSM_INTC_CMR14                                    (0x438U)
#define CSL_ICSSM_INTC_CMR15                                    (0x43CU)
#define CSL_ICSSM_INTC_HMR0                                     (0x800U)
#define CSL_ICSSM_INTC_HMR1                                     (0x804U)
#define CSL_ICSSM_INTC_HMR2                                     (0x808U)
#define CSL_ICSSM_INTC_GNLR                                     (0x1CU)
#define CSL_ICSSM_INTC_HINLR0                                   (0x1100U)
#define CSL_ICSSM_INTC_HINLR1                                   (0x1104U)
#define CSL_ICSSM_INTC_HINLR2                                   (0x1108U)
#define CSL_ICSSM_INTC_HINLR3                                   (0x110CU)
#define CSL_ICSSM_INTC_HINLR4                                   (0x1110U)
#define CSL_ICSSM_INTC_HINLR5                                   (0x1114U)
#define CSL_ICSSM_INTC_HINLR6                                   (0x1118U)
#define CSL_ICSSM_INTC_HINLR7                                   (0x111CU)
#define CSL_ICSSM_INTC_HINLR8                                   (0x1120U)
#define CSL_ICSSM_INTC_HINLR9                                   (0x1124U)
#define CSL_ICSSM_INTC_HIPIR0                                   (0x900U)
#define CSL_ICSSM_INTC_HIPIR1                                   (0x904U)
#define CSL_ICSSM_INTC_HIPIR2                                   (0x908U)
#define CSL_ICSSM_INTC_HIPIR3                                   (0x90CU)
#define CSL_ICSSM_INTC_HIPIR4                                   (0x910U)
#define CSL_ICSSM_INTC_HIPIR5                                   (0x914U)
#define CSL_ICSSM_INTC_HIPIR6                                   (0x918U)
#define CSL_ICSSM_INTC_HIPIR7                                   (0x91CU)
#define CSL_ICSSM_INTC_HIPIR8                                   (0x920U)
#define CSL_ICSSM_INTC_HIPIR9                                   (0x924U)
#define CSL_ICSSM_INTC_GPIR                                     (0x80U)
#define CSL_ICSSM_INTC_HIEISR                                   (0x34U)
#define CSL_ICSSM_INTC_HIDISR                                   (0x38U)
#define CSL_ICSSM_INTC_HIER                                     (0x1500U)
#define CSL_ICSSM_INTC_GER                                      (0x10U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVID */

#define CSL_ICSSM_INTC_REVID_REV_MINOR_MASK                     (0x0000003FU)
#define CSL_ICSSM_INTC_REVID_REV_MINOR_SHIFT                    (0x00000000U)
#define CSL_ICSSM_INTC_REVID_REV_MINOR_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_REVID_REV_MINOR_MAX                      (0x0000003fU)

#define CSL_ICSSM_INTC_REVID_REV_CUSTOM_MASK                    (0x000000C0U)
#define CSL_ICSSM_INTC_REVID_REV_CUSTOM_SHIFT                   (0x00000006U)
#define CSL_ICSSM_INTC_REVID_REV_CUSTOM_RESETVAL                (0x00000000U)
#define CSL_ICSSM_INTC_REVID_REV_CUSTOM_MAX                     (0x00000003U)

#define CSL_ICSSM_INTC_REVID_REV_MAJOR_MASK                     (0x00000700U)
#define CSL_ICSSM_INTC_REVID_REV_MAJOR_SHIFT                    (0x00000008U)
#define CSL_ICSSM_INTC_REVID_REV_MAJOR_RESETVAL                 (0x00000001U)
#define CSL_ICSSM_INTC_REVID_REV_MAJOR_MAX                      (0x00000007U)

#define CSL_ICSSM_INTC_REVID_REV_RTL_MASK                       (0x0000F800U)
#define CSL_ICSSM_INTC_REVID_REV_RTL_SHIFT                      (0x0000000BU)
#define CSL_ICSSM_INTC_REVID_REV_RTL_RESETVAL                   (0x00000015U)
#define CSL_ICSSM_INTC_REVID_REV_RTL_MAX                        (0x0000001fU)

#define CSL_ICSSM_INTC_REVID_REV_MODULE_MASK                    (0x0FFF0000U)
#define CSL_ICSSM_INTC_REVID_REV_MODULE_SHIFT                   (0x00000010U)
#define CSL_ICSSM_INTC_REVID_REV_MODULE_RESETVAL                (0x00000e82U)
#define CSL_ICSSM_INTC_REVID_REV_MODULE_MAX                     (0x00000fffU)

#define CSL_ICSSM_INTC_REVID_REV_SCHEME_MASK                    (0xC0000000U)
#define CSL_ICSSM_INTC_REVID_REV_SCHEME_SHIFT                   (0x0000001EU)
#define CSL_ICSSM_INTC_REVID_REV_SCHEME_RESETVAL                (0x00000001U)
#define CSL_ICSSM_INTC_REVID_REV_SCHEME_MAX                     (0x00000003U)

#define CSL_ICSSM_INTC_REVID_RESETVAL                           (0x4e82a900U)

/* CR */

#define CSL_ICSSM_INTC_CR_PRIORITY_HOLD_MODE_MASK               (0x00000010U)
#define CSL_ICSSM_INTC_CR_PRIORITY_HOLD_MODE_SHIFT              (0x00000004U)
#define CSL_ICSSM_INTC_CR_PRIORITY_HOLD_MODE_RESETVAL           (0x00000000U)
#define CSL_ICSSM_INTC_CR_PRIORITY_HOLD_MODE_MAX                (0x00000001U)

#define CSL_ICSSM_INTC_CR_NEST_MODE_MASK                        (0x0000000CU)
#define CSL_ICSSM_INTC_CR_NEST_MODE_SHIFT                       (0x00000002U)
#define CSL_ICSSM_INTC_CR_NEST_MODE_RESETVAL                    (0x00000000U)
#define CSL_ICSSM_INTC_CR_NEST_MODE_MAX                         (0x00000003U)

#define CSL_ICSSM_INTC_CR_WAKEUP_MODE_MASK                      (0x00000002U)
#define CSL_ICSSM_INTC_CR_WAKEUP_MODE_SHIFT                     (0x00000001U)
#define CSL_ICSSM_INTC_CR_WAKEUP_MODE_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CR_WAKEUP_MODE_MAX                       (0x00000001U)

#define CSL_ICSSM_INTC_CR_RESETVAL                              (0x00000000U)

/* SIPR0 */

#define CSL_ICSSM_INTC_SIPR0_POLARITY_31_0_MASK                 (0xFFFFFFFFU)
#define CSL_ICSSM_INTC_SIPR0_POLARITY_31_0_SHIFT                (0x00000000U)
#define CSL_ICSSM_INTC_SIPR0_POLARITY_31_0_RESETVAL             (0x00000001U)
#define CSL_ICSSM_INTC_SIPR0_POLARITY_31_0_MAX                  (0xffffffffU)

#define CSL_ICSSM_INTC_SIPR0_RESETVAL                           (0x00000001U)

/* SIPR1 */

#define CSL_ICSSM_INTC_SIPR1_POLARITY_63_32_MASK                (0xFFFFFFFFU)
#define CSL_ICSSM_INTC_SIPR1_POLARITY_63_32_SHIFT               (0x00000000U)
#define CSL_ICSSM_INTC_SIPR1_POLARITY_63_32_RESETVAL            (0x00000001U)
#define CSL_ICSSM_INTC_SIPR1_POLARITY_63_32_MAX                 (0xffffffffU)

#define CSL_ICSSM_INTC_SIPR1_RESETVAL                           (0x00000001U)

/* SITR0 */

#define CSL_ICSSM_INTC_SITR0_TYPE_31_0_MASK                     (0xFFFFFFFFU)
#define CSL_ICSSM_INTC_SITR0_TYPE_31_0_SHIFT                    (0x00000000U)
#define CSL_ICSSM_INTC_SITR0_TYPE_31_0_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_SITR0_TYPE_31_0_MAX                      (0xffffffffU)

#define CSL_ICSSM_INTC_SITR0_RESETVAL                           (0x00000000U)

/* SITR1 */

#define CSL_ICSSM_INTC_SITR1_TYPE_63_32_MASK                    (0xFFFFFFFFU)
#define CSL_ICSSM_INTC_SITR1_TYPE_63_32_SHIFT                   (0x00000000U)
#define CSL_ICSSM_INTC_SITR1_TYPE_63_32_RESETVAL                (0x00000000U)
#define CSL_ICSSM_INTC_SITR1_TYPE_63_32_MAX                     (0xffffffffU)

#define CSL_ICSSM_INTC_SITR1_RESETVAL                           (0x00000000U)

/* SISR */

#define CSL_ICSSM_INTC_SISR_STATUS_SET_INDEX_MASK               (0x000003FFU)
#define CSL_ICSSM_INTC_SISR_STATUS_SET_INDEX_SHIFT              (0x00000000U)
#define CSL_ICSSM_INTC_SISR_STATUS_SET_INDEX_RESETVAL           (0x00000000U)
#define CSL_ICSSM_INTC_SISR_STATUS_SET_INDEX_MAX                (0x000003ffU)

#define CSL_ICSSM_INTC_SISR_RESETVAL                            (0x00000000U)

/* SICR */

#define CSL_ICSSM_INTC_SICR_STATUS_CLR_INDEX_MASK               (0x000003FFU)
#define CSL_ICSSM_INTC_SICR_STATUS_CLR_INDEX_SHIFT              (0x00000000U)
#define CSL_ICSSM_INTC_SICR_STATUS_CLR_INDEX_RESETVAL           (0x00000000U)
#define CSL_ICSSM_INTC_SICR_STATUS_CLR_INDEX_MAX                (0x000003ffU)

#define CSL_ICSSM_INTC_SICR_RESETVAL                            (0x00000000U)

/* SRSR0 */

#define CSL_ICSSM_INTC_SRSR0_RAW_STATUS_31_0_MASK               (0xFFFFFFFFU)
#define CSL_ICSSM_INTC_SRSR0_RAW_STATUS_31_0_SHIFT              (0x00000000U)
#define CSL_ICSSM_INTC_SRSR0_RAW_STATUS_31_0_RESETVAL           (0x00000000U)
#define CSL_ICSSM_INTC_SRSR0_RAW_STATUS_31_0_MAX                (0xffffffffU)

#define CSL_ICSSM_INTC_SRSR0_RESETVAL                           (0x00000000U)

/* SECR0 */

#define CSL_ICSSM_INTC_SECR0_ENA_STATUS_31_0_MASK               (0xFFFFFFFFU)
#define CSL_ICSSM_INTC_SECR0_ENA_STATUS_31_0_SHIFT              (0x00000000U)
#define CSL_ICSSM_INTC_SECR0_ENA_STATUS_31_0_RESETVAL           (0x00000000U)
#define CSL_ICSSM_INTC_SECR0_ENA_STATUS_31_0_MAX                (0xffffffffU)

#define CSL_ICSSM_INTC_SECR0_RESETVAL                           (0x00000000U)

/* SRSR1 */

#define CSL_ICSSM_INTC_SRSR1_RAW_STATUS_63_32_MASK              (0xFFFFFFFFU)
#define CSL_ICSSM_INTC_SRSR1_RAW_STATUS_63_32_SHIFT             (0x00000000U)
#define CSL_ICSSM_INTC_SRSR1_RAW_STATUS_63_32_RESETVAL          (0x00000000U)
#define CSL_ICSSM_INTC_SRSR1_RAW_STATUS_63_32_MAX               (0xffffffffU)

#define CSL_ICSSM_INTC_SRSR1_RESETVAL                           (0x00000000U)

/* SECR1 */

#define CSL_ICSSM_INTC_SECR1_ENA_STATUS_63_32_MASK              (0xFFFFFFFFU)
#define CSL_ICSSM_INTC_SECR1_ENA_STATUS_63_32_SHIFT             (0x00000000U)
#define CSL_ICSSM_INTC_SECR1_ENA_STATUS_63_32_RESETVAL          (0x00000000U)
#define CSL_ICSSM_INTC_SECR1_ENA_STATUS_63_32_MAX               (0xffffffffU)

#define CSL_ICSSM_INTC_SECR1_RESETVAL                           (0x00000000U)

/* EISR */

#define CSL_ICSSM_INTC_EISR_ENABLE_SET_INDEX_MASK               (0x000003FFU)
#define CSL_ICSSM_INTC_EISR_ENABLE_SET_INDEX_SHIFT              (0x00000000U)
#define CSL_ICSSM_INTC_EISR_ENABLE_SET_INDEX_RESETVAL           (0x00000000U)
#define CSL_ICSSM_INTC_EISR_ENABLE_SET_INDEX_MAX                (0x000003ffU)

#define CSL_ICSSM_INTC_EISR_RESETVAL                            (0x00000000U)

/* EICR */

#define CSL_ICSSM_INTC_EICR_ENABLE_CLR_INDEX_MASK               (0x000003FFU)
#define CSL_ICSSM_INTC_EICR_ENABLE_CLR_INDEX_SHIFT              (0x00000000U)
#define CSL_ICSSM_INTC_EICR_ENABLE_CLR_INDEX_RESETVAL           (0x00000000U)
#define CSL_ICSSM_INTC_EICR_ENABLE_CLR_INDEX_MAX                (0x000003ffU)

#define CSL_ICSSM_INTC_EICR_RESETVAL                            (0x00000000U)

/* ESR0 */

#define CSL_ICSSM_INTC_ESR0_ENABLE_SET_31_0_MASK                (0xFFFFFFFFU)
#define CSL_ICSSM_INTC_ESR0_ENABLE_SET_31_0_SHIFT               (0x00000000U)
#define CSL_ICSSM_INTC_ESR0_ENABLE_SET_31_0_RESETVAL            (0x00000000U)
#define CSL_ICSSM_INTC_ESR0_ENABLE_SET_31_0_MAX                 (0xffffffffU)

#define CSL_ICSSM_INTC_ESR0_RESETVAL                            (0x00000000U)

/* ECR0 */

#define CSL_ICSSM_INTC_ECR0_ENABLE_CLR_31_0_MASK                (0xFFFFFFFFU)
#define CSL_ICSSM_INTC_ECR0_ENABLE_CLR_31_0_SHIFT               (0x00000000U)
#define CSL_ICSSM_INTC_ECR0_ENABLE_CLR_31_0_RESETVAL            (0x00000000U)
#define CSL_ICSSM_INTC_ECR0_ENABLE_CLR_31_0_MAX                 (0xffffffffU)

#define CSL_ICSSM_INTC_ECR0_RESETVAL                            (0x00000000U)

/* ERS1 */

#define CSL_ICSSM_INTC_ERS1_ENABLE_SET_63_32_MASK               (0xFFFFFFFFU)
#define CSL_ICSSM_INTC_ERS1_ENABLE_SET_63_32_SHIFT              (0x00000000U)
#define CSL_ICSSM_INTC_ERS1_ENABLE_SET_63_32_RESETVAL           (0x00000000U)
#define CSL_ICSSM_INTC_ERS1_ENABLE_SET_63_32_MAX                (0xffffffffU)

#define CSL_ICSSM_INTC_ERS1_RESETVAL                            (0x00000000U)

/* ECR1 */

#define CSL_ICSSM_INTC_ECR1_ENABLE_CLR_63_32_MASK               (0xFFFFFFFFU)
#define CSL_ICSSM_INTC_ECR1_ENABLE_CLR_63_32_SHIFT              (0x00000000U)
#define CSL_ICSSM_INTC_ECR1_ENABLE_CLR_63_32_RESETVAL           (0x00000000U)
#define CSL_ICSSM_INTC_ECR1_ENABLE_CLR_63_32_MAX                (0xffffffffU)

#define CSL_ICSSM_INTC_ECR1_RESETVAL                            (0x00000000U)

/* CMR0 */

#define CSL_ICSSM_INTC_CMR0_CH_MAP_3_MASK                       (0x0F000000U)
#define CSL_ICSSM_INTC_CMR0_CH_MAP_3_SHIFT                      (0x00000018U)
#define CSL_ICSSM_INTC_CMR0_CH_MAP_3_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_INTC_CMR0_CH_MAP_3_MAX                        (0x0000000fU)

#define CSL_ICSSM_INTC_CMR0_CH_MAP_2_MASK                       (0x000F0000U)
#define CSL_ICSSM_INTC_CMR0_CH_MAP_2_SHIFT                      (0x00000010U)
#define CSL_ICSSM_INTC_CMR0_CH_MAP_2_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_INTC_CMR0_CH_MAP_2_MAX                        (0x0000000fU)

#define CSL_ICSSM_INTC_CMR0_CH_MAP_1_MASK                       (0x00000F00U)
#define CSL_ICSSM_INTC_CMR0_CH_MAP_1_SHIFT                      (0x00000008U)
#define CSL_ICSSM_INTC_CMR0_CH_MAP_1_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_INTC_CMR0_CH_MAP_1_MAX                        (0x0000000fU)

#define CSL_ICSSM_INTC_CMR0_CH_MAP_0_MASK                       (0x0000000FU)
#define CSL_ICSSM_INTC_CMR0_CH_MAP_0_SHIFT                      (0x00000000U)
#define CSL_ICSSM_INTC_CMR0_CH_MAP_0_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_INTC_CMR0_CH_MAP_0_MAX                        (0x0000000fU)

#define CSL_ICSSM_INTC_CMR0_RESETVAL                            (0x00000000U)

/* CMR1 */

#define CSL_ICSSM_INTC_CMR1_CH_MAP_7_MASK                       (0x0F000000U)
#define CSL_ICSSM_INTC_CMR1_CH_MAP_7_SHIFT                      (0x00000018U)
#define CSL_ICSSM_INTC_CMR1_CH_MAP_7_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_INTC_CMR1_CH_MAP_7_MAX                        (0x0000000fU)

#define CSL_ICSSM_INTC_CMR1_CH_MAP_6_MASK                       (0x000F0000U)
#define CSL_ICSSM_INTC_CMR1_CH_MAP_6_SHIFT                      (0x00000010U)
#define CSL_ICSSM_INTC_CMR1_CH_MAP_6_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_INTC_CMR1_CH_MAP_6_MAX                        (0x0000000fU)

#define CSL_ICSSM_INTC_CMR1_CH_MAP_5_MASK                       (0x00000F00U)
#define CSL_ICSSM_INTC_CMR1_CH_MAP_5_SHIFT                      (0x00000008U)
#define CSL_ICSSM_INTC_CMR1_CH_MAP_5_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_INTC_CMR1_CH_MAP_5_MAX                        (0x0000000fU)

#define CSL_ICSSM_INTC_CMR1_CH_MAP_4_MASK                       (0x0000000FU)
#define CSL_ICSSM_INTC_CMR1_CH_MAP_4_SHIFT                      (0x00000000U)
#define CSL_ICSSM_INTC_CMR1_CH_MAP_4_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_INTC_CMR1_CH_MAP_4_MAX                        (0x0000000fU)

#define CSL_ICSSM_INTC_CMR1_RESETVAL                            (0x00000000U)

/* CMR2 */

#define CSL_ICSSM_INTC_CMR2_CH_MAP_11_MASK                      (0x0F000000U)
#define CSL_ICSSM_INTC_CMR2_CH_MAP_11_SHIFT                     (0x00000018U)
#define CSL_ICSSM_INTC_CMR2_CH_MAP_11_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR2_CH_MAP_11_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR2_CH_MAP_10_MASK                      (0x000F0000U)
#define CSL_ICSSM_INTC_CMR2_CH_MAP_10_SHIFT                     (0x00000010U)
#define CSL_ICSSM_INTC_CMR2_CH_MAP_10_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR2_CH_MAP_10_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR2_CH_MAP_9_MASK                       (0x00000F00U)
#define CSL_ICSSM_INTC_CMR2_CH_MAP_9_SHIFT                      (0x00000008U)
#define CSL_ICSSM_INTC_CMR2_CH_MAP_9_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_INTC_CMR2_CH_MAP_9_MAX                        (0x0000000fU)

#define CSL_ICSSM_INTC_CMR2_CH_MAP_8_MASK                       (0x0000000FU)
#define CSL_ICSSM_INTC_CMR2_CH_MAP_8_SHIFT                      (0x00000000U)
#define CSL_ICSSM_INTC_CMR2_CH_MAP_8_RESETVAL                   (0x00000000U)
#define CSL_ICSSM_INTC_CMR2_CH_MAP_8_MAX                        (0x0000000fU)

#define CSL_ICSSM_INTC_CMR2_RESETVAL                            (0x00000000U)

/* CMR3 */

#define CSL_ICSSM_INTC_CMR3_CH_MAP_15_MASK                      (0x0F000000U)
#define CSL_ICSSM_INTC_CMR3_CH_MAP_15_SHIFT                     (0x00000018U)
#define CSL_ICSSM_INTC_CMR3_CH_MAP_15_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR3_CH_MAP_15_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR3_CH_MAP_14_MASK                      (0x000F0000U)
#define CSL_ICSSM_INTC_CMR3_CH_MAP_14_SHIFT                     (0x00000010U)
#define CSL_ICSSM_INTC_CMR3_CH_MAP_14_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR3_CH_MAP_14_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR3_CH_MAP_13_MASK                      (0x00000F00U)
#define CSL_ICSSM_INTC_CMR3_CH_MAP_13_SHIFT                     (0x00000008U)
#define CSL_ICSSM_INTC_CMR3_CH_MAP_13_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR3_CH_MAP_13_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR3_CH_MAP_12_MASK                      (0x0000000FU)
#define CSL_ICSSM_INTC_CMR3_CH_MAP_12_SHIFT                     (0x00000000U)
#define CSL_ICSSM_INTC_CMR3_CH_MAP_12_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR3_CH_MAP_12_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR3_RESETVAL                            (0x00000000U)

/* CMR4 */

#define CSL_ICSSM_INTC_CMR4_CH_MAP_19_MASK                      (0x0F000000U)
#define CSL_ICSSM_INTC_CMR4_CH_MAP_19_SHIFT                     (0x00000018U)
#define CSL_ICSSM_INTC_CMR4_CH_MAP_19_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR4_CH_MAP_19_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR4_CH_MAP_18_MASK                      (0x000F0000U)
#define CSL_ICSSM_INTC_CMR4_CH_MAP_18_SHIFT                     (0x00000010U)
#define CSL_ICSSM_INTC_CMR4_CH_MAP_18_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR4_CH_MAP_18_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR4_CH_MAP_17_MASK                      (0x00000F00U)
#define CSL_ICSSM_INTC_CMR4_CH_MAP_17_SHIFT                     (0x00000008U)
#define CSL_ICSSM_INTC_CMR4_CH_MAP_17_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR4_CH_MAP_17_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR4_CH_MAP_16_MASK                      (0x0000000FU)
#define CSL_ICSSM_INTC_CMR4_CH_MAP_16_SHIFT                     (0x00000000U)
#define CSL_ICSSM_INTC_CMR4_CH_MAP_16_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR4_CH_MAP_16_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR4_RESETVAL                            (0x00000000U)

/* CMR5 */

#define CSL_ICSSM_INTC_CMR5_CH_MAP_23_MASK                      (0x0F000000U)
#define CSL_ICSSM_INTC_CMR5_CH_MAP_23_SHIFT                     (0x00000018U)
#define CSL_ICSSM_INTC_CMR5_CH_MAP_23_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR5_CH_MAP_23_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR5_CH_MAP_22_MASK                      (0x000F0000U)
#define CSL_ICSSM_INTC_CMR5_CH_MAP_22_SHIFT                     (0x00000010U)
#define CSL_ICSSM_INTC_CMR5_CH_MAP_22_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR5_CH_MAP_22_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR5_CH_MAP_21_MASK                      (0x00000F00U)
#define CSL_ICSSM_INTC_CMR5_CH_MAP_21_SHIFT                     (0x00000008U)
#define CSL_ICSSM_INTC_CMR5_CH_MAP_21_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR5_CH_MAP_21_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR5_CH_MAP_20_MASK                      (0x0000000FU)
#define CSL_ICSSM_INTC_CMR5_CH_MAP_20_SHIFT                     (0x00000000U)
#define CSL_ICSSM_INTC_CMR5_CH_MAP_20_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR5_CH_MAP_20_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR5_RESETVAL                            (0x00000000U)

/* CMR6 */

#define CSL_ICSSM_INTC_CMR6_CH_MAP_27_MASK                      (0x0F000000U)
#define CSL_ICSSM_INTC_CMR6_CH_MAP_27_SHIFT                     (0x00000018U)
#define CSL_ICSSM_INTC_CMR6_CH_MAP_27_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR6_CH_MAP_27_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR6_CH_MAP_26_MASK                      (0x000F0000U)
#define CSL_ICSSM_INTC_CMR6_CH_MAP_26_SHIFT                     (0x00000010U)
#define CSL_ICSSM_INTC_CMR6_CH_MAP_26_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR6_CH_MAP_26_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR6_CH_MAP_25_MASK                      (0x00000F00U)
#define CSL_ICSSM_INTC_CMR6_CH_MAP_25_SHIFT                     (0x00000008U)
#define CSL_ICSSM_INTC_CMR6_CH_MAP_25_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR6_CH_MAP_25_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR6_CH_MAP_24_MASK                      (0x0000000FU)
#define CSL_ICSSM_INTC_CMR6_CH_MAP_24_SHIFT                     (0x00000000U)
#define CSL_ICSSM_INTC_CMR6_CH_MAP_24_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR6_CH_MAP_24_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR6_RESETVAL                            (0x00000000U)

/* CMR7 */

#define CSL_ICSSM_INTC_CMR7_CH_MAP_31_MASK                      (0x0F000000U)
#define CSL_ICSSM_INTC_CMR7_CH_MAP_31_SHIFT                     (0x00000018U)
#define CSL_ICSSM_INTC_CMR7_CH_MAP_31_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR7_CH_MAP_31_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR7_CH_MAP_30_MASK                      (0x000F0000U)
#define CSL_ICSSM_INTC_CMR7_CH_MAP_30_SHIFT                     (0x00000010U)
#define CSL_ICSSM_INTC_CMR7_CH_MAP_30_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR7_CH_MAP_30_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR7_CH_MAP_29_MASK                      (0x00000F00U)
#define CSL_ICSSM_INTC_CMR7_CH_MAP_29_SHIFT                     (0x00000008U)
#define CSL_ICSSM_INTC_CMR7_CH_MAP_29_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR7_CH_MAP_29_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR7_CH_MAP_28_MASK                      (0x0000000FU)
#define CSL_ICSSM_INTC_CMR7_CH_MAP_28_SHIFT                     (0x00000000U)
#define CSL_ICSSM_INTC_CMR7_CH_MAP_28_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR7_CH_MAP_28_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR7_RESETVAL                            (0x00000000U)

/* CMR8 */

#define CSL_ICSSM_INTC_CMR8_CH_MAP_35_MASK                      (0x0F000000U)
#define CSL_ICSSM_INTC_CMR8_CH_MAP_35_SHIFT                     (0x00000018U)
#define CSL_ICSSM_INTC_CMR8_CH_MAP_35_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR8_CH_MAP_35_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR8_CH_MAP_34_MASK                      (0x000F0000U)
#define CSL_ICSSM_INTC_CMR8_CH_MAP_34_SHIFT                     (0x00000010U)
#define CSL_ICSSM_INTC_CMR8_CH_MAP_34_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR8_CH_MAP_34_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR8_CH_MAP_33_MASK                      (0x00000F00U)
#define CSL_ICSSM_INTC_CMR8_CH_MAP_33_SHIFT                     (0x00000008U)
#define CSL_ICSSM_INTC_CMR8_CH_MAP_33_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR8_CH_MAP_33_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR8_CH_MAP_32_MASK                      (0x0000000FU)
#define CSL_ICSSM_INTC_CMR8_CH_MAP_32_SHIFT                     (0x00000000U)
#define CSL_ICSSM_INTC_CMR8_CH_MAP_32_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR8_CH_MAP_32_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR8_RESETVAL                            (0x00000000U)

/* CMR9 */

#define CSL_ICSSM_INTC_CMR9_CH_MAP_39_MASK                      (0x0F000000U)
#define CSL_ICSSM_INTC_CMR9_CH_MAP_39_SHIFT                     (0x00000018U)
#define CSL_ICSSM_INTC_CMR9_CH_MAP_39_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR9_CH_MAP_39_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR9_CH_MAP_38_MASK                      (0x000F0000U)
#define CSL_ICSSM_INTC_CMR9_CH_MAP_38_SHIFT                     (0x00000010U)
#define CSL_ICSSM_INTC_CMR9_CH_MAP_38_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR9_CH_MAP_38_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR9_CH_MAP_37_MASK                      (0x00000F00U)
#define CSL_ICSSM_INTC_CMR9_CH_MAP_37_SHIFT                     (0x00000008U)
#define CSL_ICSSM_INTC_CMR9_CH_MAP_37_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR9_CH_MAP_37_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR9_CH_MAP_36_MASK                      (0x0000000FU)
#define CSL_ICSSM_INTC_CMR9_CH_MAP_36_SHIFT                     (0x00000000U)
#define CSL_ICSSM_INTC_CMR9_CH_MAP_36_RESETVAL                  (0x00000000U)
#define CSL_ICSSM_INTC_CMR9_CH_MAP_36_MAX                       (0x0000000fU)

#define CSL_ICSSM_INTC_CMR9_RESETVAL                            (0x00000000U)

/* CMR10 */

#define CSL_ICSSM_INTC_CMR10_CH_MAP_43_MASK                     (0x0F000000U)
#define CSL_ICSSM_INTC_CMR10_CH_MAP_43_SHIFT                    (0x00000018U)
#define CSL_ICSSM_INTC_CMR10_CH_MAP_43_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR10_CH_MAP_43_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR10_CH_MAP_42_MASK                     (0x000F0000U)
#define CSL_ICSSM_INTC_CMR10_CH_MAP_42_SHIFT                    (0x00000010U)
#define CSL_ICSSM_INTC_CMR10_CH_MAP_42_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR10_CH_MAP_42_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR10_CH_MAP_41_MASK                     (0x00000F00U)
#define CSL_ICSSM_INTC_CMR10_CH_MAP_41_SHIFT                    (0x00000008U)
#define CSL_ICSSM_INTC_CMR10_CH_MAP_41_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR10_CH_MAP_41_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR10_CH_MAP_40_MASK                     (0x0000000FU)
#define CSL_ICSSM_INTC_CMR10_CH_MAP_40_SHIFT                    (0x00000000U)
#define CSL_ICSSM_INTC_CMR10_CH_MAP_40_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR10_CH_MAP_40_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR10_RESETVAL                           (0x00000000U)

/* CMR11 */

#define CSL_ICSSM_INTC_CMR11_CH_MAP_47_MASK                     (0x0F000000U)
#define CSL_ICSSM_INTC_CMR11_CH_MAP_47_SHIFT                    (0x00000018U)
#define CSL_ICSSM_INTC_CMR11_CH_MAP_47_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR11_CH_MAP_47_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR11_CH_MAP_46_MASK                     (0x000F0000U)
#define CSL_ICSSM_INTC_CMR11_CH_MAP_46_SHIFT                    (0x00000010U)
#define CSL_ICSSM_INTC_CMR11_CH_MAP_46_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR11_CH_MAP_46_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR11_CH_MAP_45_MASK                     (0x00000F00U)
#define CSL_ICSSM_INTC_CMR11_CH_MAP_45_SHIFT                    (0x00000008U)
#define CSL_ICSSM_INTC_CMR11_CH_MAP_45_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR11_CH_MAP_45_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR11_CH_MAP_44_MASK                     (0x0000000FU)
#define CSL_ICSSM_INTC_CMR11_CH_MAP_44_SHIFT                    (0x00000000U)
#define CSL_ICSSM_INTC_CMR11_CH_MAP_44_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR11_CH_MAP_44_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR11_RESETVAL                           (0x00000000U)

/* CMR12 */

#define CSL_ICSSM_INTC_CMR12_CH_MAP_51_MASK                     (0x0F000000U)
#define CSL_ICSSM_INTC_CMR12_CH_MAP_51_SHIFT                    (0x00000018U)
#define CSL_ICSSM_INTC_CMR12_CH_MAP_51_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR12_CH_MAP_51_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR12_CH_MAP_50_MASK                     (0x000F0000U)
#define CSL_ICSSM_INTC_CMR12_CH_MAP_50_SHIFT                    (0x00000010U)
#define CSL_ICSSM_INTC_CMR12_CH_MAP_50_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR12_CH_MAP_50_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR12_CH_MAP_49_MASK                     (0x00000F00U)
#define CSL_ICSSM_INTC_CMR12_CH_MAP_49_SHIFT                    (0x00000008U)
#define CSL_ICSSM_INTC_CMR12_CH_MAP_49_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR12_CH_MAP_49_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR12_CH_MAP_48_MASK                     (0x0000000FU)
#define CSL_ICSSM_INTC_CMR12_CH_MAP_48_SHIFT                    (0x00000000U)
#define CSL_ICSSM_INTC_CMR12_CH_MAP_48_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR12_CH_MAP_48_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR12_RESETVAL                           (0x00000000U)

/* CMR13 */

#define CSL_ICSSM_INTC_CMR13_CH_MAP_55_MASK                     (0x0F000000U)
#define CSL_ICSSM_INTC_CMR13_CH_MAP_55_SHIFT                    (0x00000018U)
#define CSL_ICSSM_INTC_CMR13_CH_MAP_55_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR13_CH_MAP_55_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR13_CH_MAP_54_MASK                     (0x000F0000U)
#define CSL_ICSSM_INTC_CMR13_CH_MAP_54_SHIFT                    (0x00000010U)
#define CSL_ICSSM_INTC_CMR13_CH_MAP_54_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR13_CH_MAP_54_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR13_CH_MAP_53_MASK                     (0x00000F00U)
#define CSL_ICSSM_INTC_CMR13_CH_MAP_53_SHIFT                    (0x00000008U)
#define CSL_ICSSM_INTC_CMR13_CH_MAP_53_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR13_CH_MAP_53_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR13_CH_MAP_52_MASK                     (0x0000000FU)
#define CSL_ICSSM_INTC_CMR13_CH_MAP_52_SHIFT                    (0x00000000U)
#define CSL_ICSSM_INTC_CMR13_CH_MAP_52_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR13_CH_MAP_52_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR13_RESETVAL                           (0x00000000U)

/* CMR14 */

#define CSL_ICSSM_INTC_CMR14_CH_MAP_59_MASK                     (0x0F000000U)
#define CSL_ICSSM_INTC_CMR14_CH_MAP_59_SHIFT                    (0x00000018U)
#define CSL_ICSSM_INTC_CMR14_CH_MAP_59_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR14_CH_MAP_59_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR14_CH_MAP_58_MASK                     (0x000F0000U)
#define CSL_ICSSM_INTC_CMR14_CH_MAP_58_SHIFT                    (0x00000010U)
#define CSL_ICSSM_INTC_CMR14_CH_MAP_58_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR14_CH_MAP_58_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR14_CH_MAP_57_MASK                     (0x00000F00U)
#define CSL_ICSSM_INTC_CMR14_CH_MAP_57_SHIFT                    (0x00000008U)
#define CSL_ICSSM_INTC_CMR14_CH_MAP_57_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR14_CH_MAP_57_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR14_CH_MAP_56_MASK                     (0x0000000FU)
#define CSL_ICSSM_INTC_CMR14_CH_MAP_56_SHIFT                    (0x00000000U)
#define CSL_ICSSM_INTC_CMR14_CH_MAP_56_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR14_CH_MAP_56_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR14_RESETVAL                           (0x00000000U)

/* CMR15 */

#define CSL_ICSSM_INTC_CMR15_CH_MAP_63_MASK                     (0x0F000000U)
#define CSL_ICSSM_INTC_CMR15_CH_MAP_63_SHIFT                    (0x00000018U)
#define CSL_ICSSM_INTC_CMR15_CH_MAP_63_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR15_CH_MAP_63_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR15_CH_MAP_62_MASK                     (0x000F0000U)
#define CSL_ICSSM_INTC_CMR15_CH_MAP_62_SHIFT                    (0x00000010U)
#define CSL_ICSSM_INTC_CMR15_CH_MAP_62_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR15_CH_MAP_62_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR15_CH_MAP_61_MASK                     (0x00000F00U)
#define CSL_ICSSM_INTC_CMR15_CH_MAP_61_SHIFT                    (0x00000008U)
#define CSL_ICSSM_INTC_CMR15_CH_MAP_61_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR15_CH_MAP_61_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR15_CH_MAP_60_MASK                     (0x0000000FU)
#define CSL_ICSSM_INTC_CMR15_CH_MAP_60_SHIFT                    (0x00000000U)
#define CSL_ICSSM_INTC_CMR15_CH_MAP_60_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_CMR15_CH_MAP_60_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_CMR15_RESETVAL                           (0x00000000U)

/* HMR0 */

#define CSL_ICSSM_INTC_HMR0_HINT_MAP_3_MASK                     (0x0F000000U)
#define CSL_ICSSM_INTC_HMR0_HINT_MAP_3_SHIFT                    (0x00000018U)
#define CSL_ICSSM_INTC_HMR0_HINT_MAP_3_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_HMR0_HINT_MAP_3_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_HMR0_HINT_MAP_2_MASK                     (0x000F0000U)
#define CSL_ICSSM_INTC_HMR0_HINT_MAP_2_SHIFT                    (0x00000010U)
#define CSL_ICSSM_INTC_HMR0_HINT_MAP_2_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_HMR0_HINT_MAP_2_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_HMR0_HINT_MAP_1_MASK                     (0x00000F00U)
#define CSL_ICSSM_INTC_HMR0_HINT_MAP_1_SHIFT                    (0x00000008U)
#define CSL_ICSSM_INTC_HMR0_HINT_MAP_1_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_HMR0_HINT_MAP_1_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_HMR0_HINT_MAP_0_MASK                     (0x0000000FU)
#define CSL_ICSSM_INTC_HMR0_HINT_MAP_0_SHIFT                    (0x00000000U)
#define CSL_ICSSM_INTC_HMR0_HINT_MAP_0_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_HMR0_HINT_MAP_0_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_HMR0_RESETVAL                            (0x00000000U)

/* HMR1 */

#define CSL_ICSSM_INTC_HMR1_HINT_MAP_7_MASK                     (0x0F000000U)
#define CSL_ICSSM_INTC_HMR1_HINT_MAP_7_SHIFT                    (0x00000018U)
#define CSL_ICSSM_INTC_HMR1_HINT_MAP_7_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_HMR1_HINT_MAP_7_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_HMR1_HINT_MAP_6_MASK                     (0x000F0000U)
#define CSL_ICSSM_INTC_HMR1_HINT_MAP_6_SHIFT                    (0x00000010U)
#define CSL_ICSSM_INTC_HMR1_HINT_MAP_6_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_HMR1_HINT_MAP_6_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_HMR1_HINT_MAP_5_MASK                     (0x00000F00U)
#define CSL_ICSSM_INTC_HMR1_HINT_MAP_5_SHIFT                    (0x00000008U)
#define CSL_ICSSM_INTC_HMR1_HINT_MAP_5_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_HMR1_HINT_MAP_5_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_HMR1_HINT_MAP_4_MASK                     (0x0000000FU)
#define CSL_ICSSM_INTC_HMR1_HINT_MAP_4_SHIFT                    (0x00000000U)
#define CSL_ICSSM_INTC_HMR1_HINT_MAP_4_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_HMR1_HINT_MAP_4_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_HMR1_RESETVAL                            (0x00000000U)

/* HMR2 */

#define CSL_ICSSM_INTC_HMR2_HINT_MAP_9_MASK                     (0x00000F00U)
#define CSL_ICSSM_INTC_HMR2_HINT_MAP_9_SHIFT                    (0x00000008U)
#define CSL_ICSSM_INTC_HMR2_HINT_MAP_9_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_HMR2_HINT_MAP_9_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_HMR2_HINT_MAP_8_MASK                     (0x0000000FU)
#define CSL_ICSSM_INTC_HMR2_HINT_MAP_8_SHIFT                    (0x00000000U)
#define CSL_ICSSM_INTC_HMR2_HINT_MAP_8_RESETVAL                 (0x00000000U)
#define CSL_ICSSM_INTC_HMR2_HINT_MAP_8_MAX                      (0x0000000fU)

#define CSL_ICSSM_INTC_HMR2_RESETVAL                            (0x00000000U)

/* GNLR */

#define CSL_ICSSM_INTC_GNLR_AUTO_OVERRIDE_MASK                  (0x80000000U)
#define CSL_ICSSM_INTC_GNLR_AUTO_OVERRIDE_SHIFT                 (0x0000001FU)
#define CSL_ICSSM_INTC_GNLR_AUTO_OVERRIDE_RESETVAL              (0x00000000U)
#define CSL_ICSSM_INTC_GNLR_AUTO_OVERRIDE_MAX                   (0x00000001U)

#define CSL_ICSSM_INTC_GNLR_GLB_NEST_LEVEL_MASK                 (0x000001FFU)
#define CSL_ICSSM_INTC_GNLR_GLB_NEST_LEVEL_SHIFT                (0x00000000U)
#define CSL_ICSSM_INTC_GNLR_GLB_NEST_LEVEL_RESETVAL             (0x00000100U)
#define CSL_ICSSM_INTC_GNLR_GLB_NEST_LEVEL_MAX                  (0x000001ffU)

#define CSL_ICSSM_INTC_GNLR_RESETVAL                            (0x00000100U)

/* HINLR0 */

#define CSL_ICSSM_INTC_HINLR0_AUTO_OVERRIDE_MASK                (0x80000000U)
#define CSL_ICSSM_INTC_HINLR0_AUTO_OVERRIDE_SHIFT               (0x0000001FU)
#define CSL_ICSSM_INTC_HINLR0_AUTO_OVERRIDE_RESETVAL            (0x00000000U)
#define CSL_ICSSM_INTC_HINLR0_AUTO_OVERRIDE_MAX                 (0x00000001U)

#define CSL_ICSSM_INTC_HINLR0_NEST_HINT_0_MASK                  (0x000001FFU)
#define CSL_ICSSM_INTC_HINLR0_NEST_HINT_0_SHIFT                 (0x00000000U)
#define CSL_ICSSM_INTC_HINLR0_NEST_HINT_0_RESETVAL              (0x00000100U)
#define CSL_ICSSM_INTC_HINLR0_NEST_HINT_0_MAX                   (0x000001ffU)

#define CSL_ICSSM_INTC_HINLR0_RESETVAL                          (0x00000100U)

/* HINLR1 */

#define CSL_ICSSM_INTC_HINLR1_AUTO_OVERRIDE_MASK                (0x80000000U)
#define CSL_ICSSM_INTC_HINLR1_AUTO_OVERRIDE_SHIFT               (0x0000001FU)
#define CSL_ICSSM_INTC_HINLR1_AUTO_OVERRIDE_RESETVAL            (0x00000000U)
#define CSL_ICSSM_INTC_HINLR1_AUTO_OVERRIDE_MAX                 (0x00000001U)

#define CSL_ICSSM_INTC_HINLR1_NEST_HINT_1_MASK                  (0x000001FFU)
#define CSL_ICSSM_INTC_HINLR1_NEST_HINT_1_SHIFT                 (0x00000000U)
#define CSL_ICSSM_INTC_HINLR1_NEST_HINT_1_RESETVAL              (0x00000100U)
#define CSL_ICSSM_INTC_HINLR1_NEST_HINT_1_MAX                   (0x000001ffU)

#define CSL_ICSSM_INTC_HINLR1_RESETVAL                          (0x00000100U)

/* HINLR2 */

#define CSL_ICSSM_INTC_HINLR2_AUTO_OVERRIDE_MASK                (0x80000000U)
#define CSL_ICSSM_INTC_HINLR2_AUTO_OVERRIDE_SHIFT               (0x0000001FU)
#define CSL_ICSSM_INTC_HINLR2_AUTO_OVERRIDE_RESETVAL            (0x00000000U)
#define CSL_ICSSM_INTC_HINLR2_AUTO_OVERRIDE_MAX                 (0x00000001U)

#define CSL_ICSSM_INTC_HINLR2_NEST_HINT_2_MASK                  (0x000001FFU)
#define CSL_ICSSM_INTC_HINLR2_NEST_HINT_2_SHIFT                 (0x00000000U)
#define CSL_ICSSM_INTC_HINLR2_NEST_HINT_2_RESETVAL              (0x00000100U)
#define CSL_ICSSM_INTC_HINLR2_NEST_HINT_2_MAX                   (0x000001ffU)

#define CSL_ICSSM_INTC_HINLR2_RESETVAL                          (0x00000100U)

/* HINLR3 */

#define CSL_ICSSM_INTC_HINLR3_AUTO_OVERRIDE_MASK                (0x80000000U)
#define CSL_ICSSM_INTC_HINLR3_AUTO_OVERRIDE_SHIFT               (0x0000001FU)
#define CSL_ICSSM_INTC_HINLR3_AUTO_OVERRIDE_RESETVAL            (0x00000000U)
#define CSL_ICSSM_INTC_HINLR3_AUTO_OVERRIDE_MAX                 (0x00000001U)

#define CSL_ICSSM_INTC_HINLR3_NEST_HINT_3_MASK                  (0x000001FFU)
#define CSL_ICSSM_INTC_HINLR3_NEST_HINT_3_SHIFT                 (0x00000000U)
#define CSL_ICSSM_INTC_HINLR3_NEST_HINT_3_RESETVAL              (0x00000100U)
#define CSL_ICSSM_INTC_HINLR3_NEST_HINT_3_MAX                   (0x000001ffU)

#define CSL_ICSSM_INTC_HINLR3_RESETVAL                          (0x00000100U)

/* HINLR4 */

#define CSL_ICSSM_INTC_HINLR4_AUTO_OVERRIDE_MASK                (0x80000000U)
#define CSL_ICSSM_INTC_HINLR4_AUTO_OVERRIDE_SHIFT               (0x0000001FU)
#define CSL_ICSSM_INTC_HINLR4_AUTO_OVERRIDE_RESETVAL            (0x00000000U)
#define CSL_ICSSM_INTC_HINLR4_AUTO_OVERRIDE_MAX                 (0x00000001U)

#define CSL_ICSSM_INTC_HINLR4_NEST_HINT_4_MASK                  (0x000001FFU)
#define CSL_ICSSM_INTC_HINLR4_NEST_HINT_4_SHIFT                 (0x00000000U)
#define CSL_ICSSM_INTC_HINLR4_NEST_HINT_4_RESETVAL              (0x00000100U)
#define CSL_ICSSM_INTC_HINLR4_NEST_HINT_4_MAX                   (0x000001ffU)

#define CSL_ICSSM_INTC_HINLR4_RESETVAL                          (0x00000100U)

/* HINLR5 */

#define CSL_ICSSM_INTC_HINLR5_AUTO_OVERRIDE_MASK                (0x80000000U)
#define CSL_ICSSM_INTC_HINLR5_AUTO_OVERRIDE_SHIFT               (0x0000001FU)
#define CSL_ICSSM_INTC_HINLR5_AUTO_OVERRIDE_RESETVAL            (0x00000000U)
#define CSL_ICSSM_INTC_HINLR5_AUTO_OVERRIDE_MAX                 (0x00000001U)

#define CSL_ICSSM_INTC_HINLR5_NEST_HINT_5_MASK                  (0x000001FFU)
#define CSL_ICSSM_INTC_HINLR5_NEST_HINT_5_SHIFT                 (0x00000000U)
#define CSL_ICSSM_INTC_HINLR5_NEST_HINT_5_RESETVAL              (0x00000100U)
#define CSL_ICSSM_INTC_HINLR5_NEST_HINT_5_MAX                   (0x000001ffU)

#define CSL_ICSSM_INTC_HINLR5_RESETVAL                          (0x00000100U)

/* HINLR6 */

#define CSL_ICSSM_INTC_HINLR6_AUTO_OVERRIDE_MASK                (0x80000000U)
#define CSL_ICSSM_INTC_HINLR6_AUTO_OVERRIDE_SHIFT               (0x0000001FU)
#define CSL_ICSSM_INTC_HINLR6_AUTO_OVERRIDE_RESETVAL            (0x00000000U)
#define CSL_ICSSM_INTC_HINLR6_AUTO_OVERRIDE_MAX                 (0x00000001U)

#define CSL_ICSSM_INTC_HINLR6_NEST_HINT_6_MASK                  (0x000001FFU)
#define CSL_ICSSM_INTC_HINLR6_NEST_HINT_6_SHIFT                 (0x00000000U)
#define CSL_ICSSM_INTC_HINLR6_NEST_HINT_6_RESETVAL              (0x00000100U)
#define CSL_ICSSM_INTC_HINLR6_NEST_HINT_6_MAX                   (0x000001ffU)

#define CSL_ICSSM_INTC_HINLR6_RESETVAL                          (0x00000100U)

/* HINLR7 */

#define CSL_ICSSM_INTC_HINLR7_AUTO_OVERRIDE_MASK                (0x80000000U)
#define CSL_ICSSM_INTC_HINLR7_AUTO_OVERRIDE_SHIFT               (0x0000001FU)
#define CSL_ICSSM_INTC_HINLR7_AUTO_OVERRIDE_RESETVAL            (0x00000000U)
#define CSL_ICSSM_INTC_HINLR7_AUTO_OVERRIDE_MAX                 (0x00000001U)

#define CSL_ICSSM_INTC_HINLR7_NEST_HINT_7_MASK                  (0x000001FFU)
#define CSL_ICSSM_INTC_HINLR7_NEST_HINT_7_SHIFT                 (0x00000000U)
#define CSL_ICSSM_INTC_HINLR7_NEST_HINT_7_RESETVAL              (0x00000100U)
#define CSL_ICSSM_INTC_HINLR7_NEST_HINT_7_MAX                   (0x000001ffU)

#define CSL_ICSSM_INTC_HINLR7_RESETVAL                          (0x00000100U)

/* HINLR8 */

#define CSL_ICSSM_INTC_HINLR8_NEST_HINT_8_MASK                  (0x000001FFU)
#define CSL_ICSSM_INTC_HINLR8_NEST_HINT_8_SHIFT                 (0x00000000U)
#define CSL_ICSSM_INTC_HINLR8_NEST_HINT_8_RESETVAL              (0x00000100U)
#define CSL_ICSSM_INTC_HINLR8_NEST_HINT_8_MAX                   (0x000001ffU)

#define CSL_ICSSM_INTC_HINLR8_AUTO_OVERRIDE_MASK                (0x80000000U)
#define CSL_ICSSM_INTC_HINLR8_AUTO_OVERRIDE_SHIFT               (0x0000001FU)
#define CSL_ICSSM_INTC_HINLR8_AUTO_OVERRIDE_RESETVAL            (0x00000000U)
#define CSL_ICSSM_INTC_HINLR8_AUTO_OVERRIDE_MAX                 (0x00000001U)

#define CSL_ICSSM_INTC_HINLR8_RESETVAL                          (0x00000100U)

/* HINLR9 */

#define CSL_ICSSM_INTC_HINLR9_AUTO_OVERRIDE_MASK                (0x80000000U)
#define CSL_ICSSM_INTC_HINLR9_AUTO_OVERRIDE_SHIFT               (0x0000001FU)
#define CSL_ICSSM_INTC_HINLR9_AUTO_OVERRIDE_RESETVAL            (0x00000000U)
#define CSL_ICSSM_INTC_HINLR9_AUTO_OVERRIDE_MAX                 (0x00000001U)

#define CSL_ICSSM_INTC_HINLR9_NEST_HINT_9_MASK                  (0x000001FFU)
#define CSL_ICSSM_INTC_HINLR9_NEST_HINT_9_SHIFT                 (0x00000000U)
#define CSL_ICSSM_INTC_HINLR9_NEST_HINT_9_RESETVAL              (0x00000100U)
#define CSL_ICSSM_INTC_HINLR9_NEST_HINT_9_MAX                   (0x000001ffU)

#define CSL_ICSSM_INTC_HINLR9_RESETVAL                          (0x00000100U)

/* HIPIR0 */

#define CSL_ICSSM_INTC_HIPIR0_NONE_HINT_0_MASK                  (0x80000000U)
#define CSL_ICSSM_INTC_HIPIR0_NONE_HINT_0_SHIFT                 (0x0000001FU)
#define CSL_ICSSM_INTC_HIPIR0_NONE_HINT_0_RESETVAL              (0x00000001U)
#define CSL_ICSSM_INTC_HIPIR0_NONE_HINT_0_MAX                   (0x00000001U)

#define CSL_ICSSM_INTC_HIPIR0_PRI_HINT_0_MASK                   (0x000003FFU)
#define CSL_ICSSM_INTC_HIPIR0_PRI_HINT_0_SHIFT                  (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR0_PRI_HINT_0_RESETVAL               (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR0_PRI_HINT_0_MAX                    (0x000003ffU)

#define CSL_ICSSM_INTC_HIPIR0_RESETVAL                          (0x80000000U)

/* HIPIR1 */

#define CSL_ICSSM_INTC_HIPIR1_NONE_HINT_1_MASK                  (0x80000000U)
#define CSL_ICSSM_INTC_HIPIR1_NONE_HINT_1_SHIFT                 (0x0000001FU)
#define CSL_ICSSM_INTC_HIPIR1_NONE_HINT_1_RESETVAL              (0x00000001U)
#define CSL_ICSSM_INTC_HIPIR1_NONE_HINT_1_MAX                   (0x00000001U)

#define CSL_ICSSM_INTC_HIPIR1_PRI_HINT_1_MASK                   (0x000003FFU)
#define CSL_ICSSM_INTC_HIPIR1_PRI_HINT_1_SHIFT                  (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR1_PRI_HINT_1_RESETVAL               (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR1_PRI_HINT_1_MAX                    (0x000003ffU)

#define CSL_ICSSM_INTC_HIPIR1_RESETVAL                          (0x80000000U)

/* HIPIR2 */

#define CSL_ICSSM_INTC_HIPIR2_NONE_HINT_2_MASK                  (0x80000000U)
#define CSL_ICSSM_INTC_HIPIR2_NONE_HINT_2_SHIFT                 (0x0000001FU)
#define CSL_ICSSM_INTC_HIPIR2_NONE_HINT_2_RESETVAL              (0x00000001U)
#define CSL_ICSSM_INTC_HIPIR2_NONE_HINT_2_MAX                   (0x00000001U)

#define CSL_ICSSM_INTC_HIPIR2_PRI_HINT_2_MASK                   (0x000003FFU)
#define CSL_ICSSM_INTC_HIPIR2_PRI_HINT_2_SHIFT                  (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR2_PRI_HINT_2_RESETVAL               (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR2_PRI_HINT_2_MAX                    (0x000003ffU)

#define CSL_ICSSM_INTC_HIPIR2_RESETVAL                          (0x80000000U)

/* HIPIR3 */

#define CSL_ICSSM_INTC_HIPIR3_NONE_HINT_3_MASK                  (0x80000000U)
#define CSL_ICSSM_INTC_HIPIR3_NONE_HINT_3_SHIFT                 (0x0000001FU)
#define CSL_ICSSM_INTC_HIPIR3_NONE_HINT_3_RESETVAL              (0x00000001U)
#define CSL_ICSSM_INTC_HIPIR3_NONE_HINT_3_MAX                   (0x00000001U)

#define CSL_ICSSM_INTC_HIPIR3_PRI_HINT_3_MASK                   (0x000003FFU)
#define CSL_ICSSM_INTC_HIPIR3_PRI_HINT_3_SHIFT                  (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR3_PRI_HINT_3_RESETVAL               (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR3_PRI_HINT_3_MAX                    (0x000003ffU)

#define CSL_ICSSM_INTC_HIPIR3_RESETVAL                          (0x80000000U)

/* HIPIR4 */

#define CSL_ICSSM_INTC_HIPIR4_NONE_HINT_4_MASK                  (0x80000000U)
#define CSL_ICSSM_INTC_HIPIR4_NONE_HINT_4_SHIFT                 (0x0000001FU)
#define CSL_ICSSM_INTC_HIPIR4_NONE_HINT_4_RESETVAL              (0x00000001U)
#define CSL_ICSSM_INTC_HIPIR4_NONE_HINT_4_MAX                   (0x00000001U)

#define CSL_ICSSM_INTC_HIPIR4_PRI_HINT_4_MASK                   (0x000003FFU)
#define CSL_ICSSM_INTC_HIPIR4_PRI_HINT_4_SHIFT                  (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR4_PRI_HINT_4_RESETVAL               (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR4_PRI_HINT_4_MAX                    (0x000003ffU)

#define CSL_ICSSM_INTC_HIPIR4_RESETVAL                          (0x80000000U)

/* HIPIR5 */

#define CSL_ICSSM_INTC_HIPIR5_NONE_HINT_5_MASK                  (0x80000000U)
#define CSL_ICSSM_INTC_HIPIR5_NONE_HINT_5_SHIFT                 (0x0000001FU)
#define CSL_ICSSM_INTC_HIPIR5_NONE_HINT_5_RESETVAL              (0x00000001U)
#define CSL_ICSSM_INTC_HIPIR5_NONE_HINT_5_MAX                   (0x00000001U)

#define CSL_ICSSM_INTC_HIPIR5_PRI_HINT_5_MASK                   (0x000003FFU)
#define CSL_ICSSM_INTC_HIPIR5_PRI_HINT_5_SHIFT                  (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR5_PRI_HINT_5_RESETVAL               (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR5_PRI_HINT_5_MAX                    (0x000003ffU)

#define CSL_ICSSM_INTC_HIPIR5_RESETVAL                          (0x80000000U)

/* HIPIR6 */

#define CSL_ICSSM_INTC_HIPIR6_NONE_HINT_6_MASK                  (0x80000000U)
#define CSL_ICSSM_INTC_HIPIR6_NONE_HINT_6_SHIFT                 (0x0000001FU)
#define CSL_ICSSM_INTC_HIPIR6_NONE_HINT_6_RESETVAL              (0x00000001U)
#define CSL_ICSSM_INTC_HIPIR6_NONE_HINT_6_MAX                   (0x00000001U)

#define CSL_ICSSM_INTC_HIPIR6_PRI_HINT_6_MASK                   (0x000003FFU)
#define CSL_ICSSM_INTC_HIPIR6_PRI_HINT_6_SHIFT                  (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR6_PRI_HINT_6_RESETVAL               (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR6_PRI_HINT_6_MAX                    (0x000003ffU)

#define CSL_ICSSM_INTC_HIPIR6_RESETVAL                          (0x80000000U)

/* HIPIR7 */

#define CSL_ICSSM_INTC_HIPIR7_NONE_HINT_7_MASK                  (0x80000000U)
#define CSL_ICSSM_INTC_HIPIR7_NONE_HINT_7_SHIFT                 (0x0000001FU)
#define CSL_ICSSM_INTC_HIPIR7_NONE_HINT_7_RESETVAL              (0x00000001U)
#define CSL_ICSSM_INTC_HIPIR7_NONE_HINT_7_MAX                   (0x00000001U)

#define CSL_ICSSM_INTC_HIPIR7_PRI_HINT_7_MASK                   (0x000003FFU)
#define CSL_ICSSM_INTC_HIPIR7_PRI_HINT_7_SHIFT                  (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR7_PRI_HINT_7_RESETVAL               (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR7_PRI_HINT_7_MAX                    (0x000003ffU)

#define CSL_ICSSM_INTC_HIPIR7_RESETVAL                          (0x80000000U)

/* HIPIR8 */

#define CSL_ICSSM_INTC_HIPIR8_NONE_HINT_8_MASK                  (0x80000000U)
#define CSL_ICSSM_INTC_HIPIR8_NONE_HINT_8_SHIFT                 (0x0000001FU)
#define CSL_ICSSM_INTC_HIPIR8_NONE_HINT_8_RESETVAL              (0x00000001U)
#define CSL_ICSSM_INTC_HIPIR8_NONE_HINT_8_MAX                   (0x00000001U)

#define CSL_ICSSM_INTC_HIPIR8_PRI_HINT_8_MASK                   (0x000003FFU)
#define CSL_ICSSM_INTC_HIPIR8_PRI_HINT_8_SHIFT                  (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR8_PRI_HINT_8_RESETVAL               (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR8_PRI_HINT_8_MAX                    (0x000003ffU)

#define CSL_ICSSM_INTC_HIPIR8_RESETVAL                          (0x80000000U)

/* HIPIR9 */

#define CSL_ICSSM_INTC_HIPIR9_NONE_HINT_9_MASK                  (0x80000000U)
#define CSL_ICSSM_INTC_HIPIR9_NONE_HINT_9_SHIFT                 (0x0000001FU)
#define CSL_ICSSM_INTC_HIPIR9_NONE_HINT_9_RESETVAL              (0x00000001U)
#define CSL_ICSSM_INTC_HIPIR9_NONE_HINT_9_MAX                   (0x00000001U)

#define CSL_ICSSM_INTC_HIPIR9_PRI_HINT_9_MASK                   (0x000003FFU)
#define CSL_ICSSM_INTC_HIPIR9_PRI_HINT_9_SHIFT                  (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR9_PRI_HINT_9_RESETVAL               (0x00000000U)
#define CSL_ICSSM_INTC_HIPIR9_PRI_HINT_9_MAX                    (0x000003ffU)

#define CSL_ICSSM_INTC_HIPIR9_RESETVAL                          (0x80000000U)

/* GPIR */

#define CSL_ICSSM_INTC_GPIR_GLB_NONE_MASK                       (0x80000000U)
#define CSL_ICSSM_INTC_GPIR_GLB_NONE_SHIFT                      (0x0000001FU)
#define CSL_ICSSM_INTC_GPIR_GLB_NONE_RESETVAL                   (0x00000001U)
#define CSL_ICSSM_INTC_GPIR_GLB_NONE_MAX                        (0x00000001U)

#define CSL_ICSSM_INTC_GPIR_GLB_PRI_INTR_MASK                   (0x000003FFU)
#define CSL_ICSSM_INTC_GPIR_GLB_PRI_INTR_SHIFT                  (0x00000000U)
#define CSL_ICSSM_INTC_GPIR_GLB_PRI_INTR_RESETVAL               (0x00000000U)
#define CSL_ICSSM_INTC_GPIR_GLB_PRI_INTR_MAX                    (0x000003ffU)

#define CSL_ICSSM_INTC_GPIR_RESETVAL                            (0x80000000U)

/* HIEISR */

#define CSL_ICSSM_INTC_HIEISR_HINT_ENABLE_SET_INDEX_MASK        (0x000003FFU)
#define CSL_ICSSM_INTC_HIEISR_HINT_ENABLE_SET_INDEX_SHIFT       (0x00000000U)
#define CSL_ICSSM_INTC_HIEISR_HINT_ENABLE_SET_INDEX_RESETVAL    (0x00000000U)
#define CSL_ICSSM_INTC_HIEISR_HINT_ENABLE_SET_INDEX_MAX         (0x000003ffU)

#define CSL_ICSSM_INTC_HIEISR_RESETVAL                          (0x00000000U)

/* HIDISR */

#define CSL_ICSSM_INTC_HIDISR_HINT_ENABLE_CLR_INDEX_MASK        (0x000003FFU)
#define CSL_ICSSM_INTC_HIDISR_HINT_ENABLE_CLR_INDEX_SHIFT       (0x00000000U)
#define CSL_ICSSM_INTC_HIDISR_HINT_ENABLE_CLR_INDEX_RESETVAL    (0x00000000U)
#define CSL_ICSSM_INTC_HIDISR_HINT_ENABLE_CLR_INDEX_MAX         (0x000003ffU)

#define CSL_ICSSM_INTC_HIDISR_RESETVAL                          (0x00000000U)

/* HIER */

#define CSL_ICSSM_INTC_HIER_ENABLE_HINT_MASK                    (0x000003FFU)
#define CSL_ICSSM_INTC_HIER_ENABLE_HINT_SHIFT                   (0x00000000U)
#define CSL_ICSSM_INTC_HIER_ENABLE_HINT_RESETVAL                (0x00000000U)
#define CSL_ICSSM_INTC_HIER_ENABLE_HINT_MAX                     (0x000003ffU)

#define CSL_ICSSM_INTC_HIER_RESETVAL                            (0x00000000U)

/* GER */

#define CSL_ICSSM_INTC_GER_ENABLE_HINT_ANY_MASK                 (0x00000001U)
#define CSL_ICSSM_INTC_GER_ENABLE_HINT_ANY_SHIFT                (0x00000000U)
#define CSL_ICSSM_INTC_GER_ENABLE_HINT_ANY_RESETVAL             (0x00000000U)
#define CSL_ICSSM_INTC_GER_ENABLE_HINT_ANY_MAX                  (0x00000001U)

#define CSL_ICSSM_INTC_GER_RESETVAL                             (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
