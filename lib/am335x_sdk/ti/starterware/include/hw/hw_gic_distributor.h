/******************************************************************************
*
* hw_gic_distributor.h - register-level header file for HW_GIC_DISTR
*
* Copyright (c) 2008-2019 Texas Instruments Incorporated.  All rights reserved.
* Software License Agreement
*
* Texas Instruments (TI) is supplying this software for use solely and
* exclusively on TI devices. The software is owned by TI and/or its
* suppliers, and is protected under applicable patent and copyright laws.
*
* You may not combine this software with any open-source software if such
* combination would cause this software to become subject to any of the
* license terms applicable to such open source software.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
* NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
* NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
* A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
* CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
* DAMAGES, FOR ANY REASON WHATSOEVER.
* 
******************************************************************************
*/
#ifndef HW_GIC_DISTRIBUTOR_H_
#define HW_GIC_DISTRIBUTOR_H_

#ifdef __cplusplus
extern "C"
{
#endif

/****************************************************************************************************
* Register Definitions 
****************************************************************************************************/
#define GIC_DISTR_ICDDCR                                                                                    (0x0U)
#define GIC_DISTR_ICDICTR                                                                                   (0x4U)
#define GIC_DISTR_ICDIIDR                                                                                   (0x8U)
#define GIC_DISTR_ICDISR(n)                                                                                 (0x80U + ((n) * 4))
#define GIC_DISTR_ICDISER(n)                                                                                (0x100U + ((n) * 4))
#define GIC_DISTR_ICDICER(n)                                                                                (0x180U + ((n) * 4))
#define GIC_DISTR_ICDISPR(n)                                                                                (0x200U + ((n) * 4))
#define GIC_DISTR_ICDICPR(n)                                                                                (0x280U + ((n) * 4))
#define GIC_DISTR_ICDABR(n)                                                                                 (0x300U + ((n) * 4))
#define GIC_DISTR_ICDIPR(n)                                                                                 (0x400U + ((n) * 4))
#define GIC_DISTR_ICDIPTR(n)                                                                                (0x800U + ((n) * 4))
#define GIC_DISTR_ICDICFR(n)                                                                                (0xc00U + ((n) * 4))
#define GIC_DISTR_PPI_STATUS                                                                                (0xd00U)
#define GIC_DISTR_SPI_STATUS(n)                                                                             (0xd04U + ((n) * 4))
#define GIC_DISTR_ICDSGIR                                                                                   (0xf00U)
#define GIC_DISTR_PERIPH_ID_4                                                                               (0xfd0U)
#define GIC_DISTR_PERIPH_ID_0                                                                               (0xfe0U)
#define GIC_DISTR_PERIPH_ID_1                                                                               (0xfe4U)
#define GIC_DISTR_PERIPH_ID_2                                                                               (0xfe8U)
#define GIC_DISTR_PERIPH_ID_3                                                                               (0xfecU)
#define GIC_DISTR_COMPONENT_ID_0                                                                            (0xff0U)
#define GIC_DISTR_COMPONENT_ID_1                                                                            (0xff4U)
#define GIC_DISTR_COMPONENT_ID_2                                                                            (0xff8U)
#define GIC_DISTR_COMPONENT_ID_3                                                                            (0xffcU)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define GIC_DISTR_ICDDCR_INTERRUPT_IN_EN_SHIFT                                                              (0U)
#define GIC_DISTR_ICDDCR_INTERRUPT_IN_EN_MASK                                                               (0x00000001U)

#define GIC_DISTR_ICDDCR_RESERVED_SHIFT                                                                     (1U)
#define GIC_DISTR_ICDDCR_RESERVED_MASK                                                                      (0xfffffffeU)

#define GIC_DISTR_ICDICTR_SPI_LINE_NUMBER_SHIFT                                                             (0U)
#define GIC_DISTR_ICDICTR_SPI_LINE_NUMBER_MASK                                                              (0x0000001fU)

#define GIC_DISTR_ICDICTR_CPU_NUMBER_SHIFT                                                                  (5U)
#define GIC_DISTR_ICDICTR_CPU_NUMBER_MASK                                                                   (0x000000e0U)

#define GIC_DISTR_ICDICTR_RESERVED_SHIFT                                                                    (8U)
#define GIC_DISTR_ICDICTR_RESERVED_MASK                                                                     (0x00000300U)

#define GIC_DISTR_ICDICTR_DOMAIN_SHIFT                                                                      (10U)
#define GIC_DISTR_ICDICTR_DOMAIN_MASK                                                                       (0x00000400U)

#define GIC_DISTR_ICDICTR_LSPI_SHIFT                                                                        (11U)
#define GIC_DISTR_ICDICTR_LSPI_MASK                                                                         (0x0000f800U)

#define GIC_DISTR_ICDICTR_RESERVED1_SHIFT                                                                   (16U)
#define GIC_DISTR_ICDICTR_RESERVED1_MASK                                                                    (0xffff0000U)

#define GIC_DISTR_ICDIIDR_IMPLEMENTER_SHIFT                                                                 (0U)
#define GIC_DISTR_ICDIIDR_IMPLEMENTER_MASK                                                                  (0x00000fffU)

#define GIC_DISTR_ICDIIDR_REVISION_NUMBER_SHIFT                                                             (12U)
#define GIC_DISTR_ICDIIDR_REVISION_NUMBER_MASK                                                              (0x00fff000U)

#define GIC_DISTR_ICDIIDR_IMPLEMENTATION_DEFINED_SHIFT                                                      (24U)
#define GIC_DISTR_ICDIIDR_IMPLEMENTATION_DEFINED_MASK                                                       (0xff000000U)

#define GIC_DISTR_ICDISR_ID0_SHIFT                                                                          (0U)
#define GIC_DISTR_ICDISR_ID0_MASK                                                                           (0x00000001U)

#define GIC_DISTR_ICDISR_ID1_SHIFT                                                                          (1U)
#define GIC_DISTR_ICDISR_ID1_MASK                                                                           (0x00000002U)

#define GIC_DISTR_ICDISR_ID2_SHIFT                                                                          (2U)
#define GIC_DISTR_ICDISR_ID2_MASK                                                                           (0x00000004U)

#define GIC_DISTR_ICDISR_ID3_SHIFT                                                                          (3U)
#define GIC_DISTR_ICDISR_ID3_MASK                                                                           (0x00000008U)

#define GIC_DISTR_ICDISR_ID4_SHIFT                                                                          (4U)
#define GIC_DISTR_ICDISR_ID4_MASK                                                                           (0x00000010U)

#define GIC_DISTR_ICDISR_ID5_SHIFT                                                                          (5U)
#define GIC_DISTR_ICDISR_ID5_MASK                                                                           (0x00000020U)

#define GIC_DISTR_ICDISR_ID6_SHIFT                                                                          (6U)
#define GIC_DISTR_ICDISR_ID6_MASK                                                                           (0x00000040U)

#define GIC_DISTR_ICDISR_ID7_SHIFT                                                                          (7U)
#define GIC_DISTR_ICDISR_ID7_MASK                                                                           (0x00000080U)

#define GIC_DISTR_ICDISR_ID8_SHIFT                                                                          (8U)
#define GIC_DISTR_ICDISR_ID8_MASK                                                                           (0x00000100U)

#define GIC_DISTR_ICDISR_ID9_SHIFT                                                                          (9U)
#define GIC_DISTR_ICDISR_ID9_MASK                                                                           (0x00000200U)

#define GIC_DISTR_ICDISR_ID10_SHIFT                                                                         (10U)
#define GIC_DISTR_ICDISR_ID10_MASK                                                                          (0x00000400U)

#define GIC_DISTR_ICDISR_ID11_SHIFT                                                                         (11U)
#define GIC_DISTR_ICDISR_ID11_MASK                                                                          (0x00000800U)

#define GIC_DISTR_ICDISR_ID12_SHIFT                                                                         (12U)
#define GIC_DISTR_ICDISR_ID12_MASK                                                                          (0x00001000U)

#define GIC_DISTR_ICDISR_ID13_SHIFT                                                                         (13U)
#define GIC_DISTR_ICDISR_ID13_MASK                                                                          (0x00002000U)

#define GIC_DISTR_ICDISR_ID14_SHIFT                                                                         (14U)
#define GIC_DISTR_ICDISR_ID14_MASK                                                                          (0x00004000U)

#define GIC_DISTR_ICDISR_ID15_SHIFT                                                                         (15U)
#define GIC_DISTR_ICDISR_ID15_MASK                                                                          (0x00008000U)

#define GIC_DISTR_ICDISR_ID28_SHIFT                                                                         (28U)
#define GIC_DISTR_ICDISR_ID28_MASK                                                                          (0x10000000U)

#define GIC_DISTR_ICDISR_ID29_SHIFT                                                                         (29U)
#define GIC_DISTR_ICDISR_ID29_MASK                                                                          (0x20000000U)

#define GIC_DISTR_ICDISR_ID30_SHIFT                                                                         (30U)
#define GIC_DISTR_ICDISR_ID30_MASK                                                                          (0x40000000U)

#define GIC_DISTR_ICDISR_ID31_SHIFT                                                                         (31U)
#define GIC_DISTR_ICDISR_ID31_MASK                                                                          (0x80000000U)

#define GIC_DISTR_ICDISR_ID27_SHIFT                                                                         (27U)
#define GIC_DISTR_ICDISR_ID27_MASK                                                                          (0x08000000U)

#define GIC_DISTR_ICDISR_ID16_SHIFT                                                                         (16U)
#define GIC_DISTR_ICDISR_ID16_MASK                                                                          (0x00010000U)

#define GIC_DISTR_ICDISR_ID17_SHIFT                                                                         (17U)
#define GIC_DISTR_ICDISR_ID17_MASK                                                                          (0x00020000U)

#define GIC_DISTR_ICDISR_ID18_SHIFT                                                                         (18U)
#define GIC_DISTR_ICDISR_ID18_MASK                                                                          (0x00040000U)

#define GIC_DISTR_ICDISR_ID19_SHIFT                                                                         (19U)
#define GIC_DISTR_ICDISR_ID19_MASK                                                                          (0x00080000U)

#define GIC_DISTR_ICDISR_ID20_SHIFT                                                                         (20U)
#define GIC_DISTR_ICDISR_ID20_MASK                                                                          (0x00100000U)

#define GIC_DISTR_ICDISR_ID21_SHIFT                                                                         (21U)
#define GIC_DISTR_ICDISR_ID21_MASK                                                                          (0x00200000U)

#define GIC_DISTR_ICDISR_ID22_SHIFT                                                                         (22U)
#define GIC_DISTR_ICDISR_ID22_MASK                                                                          (0x00400000U)

#define GIC_DISTR_ICDISR_ID23_SHIFT                                                                         (23U)
#define GIC_DISTR_ICDISR_ID23_MASK                                                                          (0x00800000U)

#define GIC_DISTR_ICDISR_ID24_SHIFT                                                                         (24U)
#define GIC_DISTR_ICDISR_ID24_MASK                                                                          (0x01000000U)

#define GIC_DISTR_ICDISR_ID25_SHIFT                                                                         (25U)
#define GIC_DISTR_ICDISR_ID25_MASK                                                                          (0x02000000U)

#define GIC_DISTR_ICDISR_ID26_SHIFT                                                                         (26U)
#define GIC_DISTR_ICDISR_ID26_MASK                                                                          (0x04000000U)

#define GIC_DISTR_ICDISER_ID0_SHIFT                                                                         (0U)
#define GIC_DISTR_ICDISER_ID0_MASK                                                                          (0x00000001U)

#define GIC_DISTR_ICDISER_ID1_SHIFT                                                                         (1U)
#define GIC_DISTR_ICDISER_ID1_MASK                                                                          (0x00000002U)

#define GIC_DISTR_ICDISER_ID2_SHIFT                                                                         (2U)
#define GIC_DISTR_ICDISER_ID2_MASK                                                                          (0x00000004U)

#define GIC_DISTR_ICDISER_ID3_SHIFT                                                                         (3U)
#define GIC_DISTR_ICDISER_ID3_MASK                                                                          (0x00000008U)

#define GIC_DISTR_ICDISER_ID4_SHIFT                                                                         (4U)
#define GIC_DISTR_ICDISER_ID4_MASK                                                                          (0x00000010U)

#define GIC_DISTR_ICDISER_ID5_SHIFT                                                                         (5U)
#define GIC_DISTR_ICDISER_ID5_MASK                                                                          (0x00000020U)

#define GIC_DISTR_ICDISER_ID6_SHIFT                                                                         (6U)
#define GIC_DISTR_ICDISER_ID6_MASK                                                                          (0x00000040U)

#define GIC_DISTR_ICDISER_ID7_SHIFT                                                                         (7U)
#define GIC_DISTR_ICDISER_ID7_MASK                                                                          (0x00000080U)

#define GIC_DISTR_ICDISER_ID8_SHIFT                                                                         (8U)
#define GIC_DISTR_ICDISER_ID8_MASK                                                                          (0x00000100U)

#define GIC_DISTR_ICDISER_ID9_SHIFT                                                                         (9U)
#define GIC_DISTR_ICDISER_ID9_MASK                                                                          (0x00000200U)

#define GIC_DISTR_ICDISER_ID10_SHIFT                                                                        (10U)
#define GIC_DISTR_ICDISER_ID10_MASK                                                                         (0x00000400U)

#define GIC_DISTR_ICDISER_ID11_SHIFT                                                                        (11U)
#define GIC_DISTR_ICDISER_ID11_MASK                                                                         (0x00000800U)

#define GIC_DISTR_ICDISER_ID12_SHIFT                                                                        (12U)
#define GIC_DISTR_ICDISER_ID12_MASK                                                                         (0x00001000U)

#define GIC_DISTR_ICDISER_ID13_SHIFT                                                                        (13U)
#define GIC_DISTR_ICDISER_ID13_MASK                                                                         (0x00002000U)

#define GIC_DISTR_ICDISER_ID14_SHIFT                                                                        (14U)
#define GIC_DISTR_ICDISER_ID14_MASK                                                                         (0x00004000U)

#define GIC_DISTR_ICDISER_ID15_SHIFT                                                                        (15U)
#define GIC_DISTR_ICDISER_ID15_MASK                                                                         (0x00008000U)

#define GIC_DISTR_ICDISER_ID16_SHIFT                                                                        (16U)
#define GIC_DISTR_ICDISER_ID16_MASK                                                                         (0x00010000U)

#define GIC_DISTR_ICDISER_ID17_SHIFT                                                                        (17U)
#define GIC_DISTR_ICDISER_ID17_MASK                                                                         (0x00020000U)

#define GIC_DISTR_ICDISER_ID18_SHIFT                                                                        (18U)
#define GIC_DISTR_ICDISER_ID18_MASK                                                                         (0x00040000U)

#define GIC_DISTR_ICDISER_ID19_SHIFT                                                                        (19U)
#define GIC_DISTR_ICDISER_ID19_MASK                                                                         (0x00080000U)

#define GIC_DISTR_ICDISER_ID20_SHIFT                                                                        (20U)
#define GIC_DISTR_ICDISER_ID20_MASK                                                                         (0x00100000U)

#define GIC_DISTR_ICDISER_ID21_SHIFT                                                                        (21U)
#define GIC_DISTR_ICDISER_ID21_MASK                                                                         (0x00200000U)

#define GIC_DISTR_ICDISER_ID22_SHIFT                                                                        (22U)
#define GIC_DISTR_ICDISER_ID22_MASK                                                                         (0x00400000U)

#define GIC_DISTR_ICDISER_ID23_SHIFT                                                                        (23U)
#define GIC_DISTR_ICDISER_ID23_MASK                                                                         (0x00800000U)

#define GIC_DISTR_ICDISER_ID24_SHIFT                                                                        (24U)
#define GIC_DISTR_ICDISER_ID24_MASK                                                                         (0x01000000U)

#define GIC_DISTR_ICDISER_ID25_SHIFT                                                                        (25U)
#define GIC_DISTR_ICDISER_ID25_MASK                                                                         (0x02000000U)

#define GIC_DISTR_ICDISER_ID26_SHIFT                                                                        (26U)
#define GIC_DISTR_ICDISER_ID26_MASK                                                                         (0x04000000U)

#define GIC_DISTR_ICDISER_ID27_SHIFT                                                                        (27U)
#define GIC_DISTR_ICDISER_ID27_MASK                                                                         (0x08000000U)

#define GIC_DISTR_ICDISER_ID28_SHIFT                                                                        (28U)
#define GIC_DISTR_ICDISER_ID28_MASK                                                                         (0x10000000U)

#define GIC_DISTR_ICDISER_ID29_SHIFT                                                                        (29U)
#define GIC_DISTR_ICDISER_ID29_MASK                                                                         (0x20000000U)

#define GIC_DISTR_ICDISER_ID30_SHIFT                                                                        (30U)
#define GIC_DISTR_ICDISER_ID30_MASK                                                                         (0x40000000U)

#define GIC_DISTR_ICDISER_ID31_SHIFT                                                                        (31U)
#define GIC_DISTR_ICDISER_ID31_MASK                                                                         (0x80000000U)

#define GIC_DISTR_ICDICER_ID0_SHIFT                                                                         (0U)
#define GIC_DISTR_ICDICER_ID0_MASK                                                                          (0x00000001U)

#define GIC_DISTR_ICDICER_ID1_SHIFT                                                                         (1U)
#define GIC_DISTR_ICDICER_ID1_MASK                                                                          (0x00000002U)

#define GIC_DISTR_ICDICER_ID2_SHIFT                                                                         (2U)
#define GIC_DISTR_ICDICER_ID2_MASK                                                                          (0x00000004U)

#define GIC_DISTR_ICDICER_ID3_SHIFT                                                                         (3U)
#define GIC_DISTR_ICDICER_ID3_MASK                                                                          (0x00000008U)

#define GIC_DISTR_ICDICER_ID4_SHIFT                                                                         (4U)
#define GIC_DISTR_ICDICER_ID4_MASK                                                                          (0x00000010U)

#define GIC_DISTR_ICDICER_ID5_SHIFT                                                                         (5U)
#define GIC_DISTR_ICDICER_ID5_MASK                                                                          (0x00000020U)

#define GIC_DISTR_ICDICER_ID6_SHIFT                                                                         (6U)
#define GIC_DISTR_ICDICER_ID6_MASK                                                                          (0x00000040U)

#define GIC_DISTR_ICDICER_ID7_SHIFT                                                                         (7U)
#define GIC_DISTR_ICDICER_ID7_MASK                                                                          (0x00000080U)

#define GIC_DISTR_ICDICER_ID8_SHIFT                                                                         (8U)
#define GIC_DISTR_ICDICER_ID8_MASK                                                                          (0x00000100U)

#define GIC_DISTR_ICDICER_ID9_SHIFT                                                                         (9U)
#define GIC_DISTR_ICDICER_ID9_MASK                                                                          (0x00000200U)

#define GIC_DISTR_ICDICER_ID10_SHIFT                                                                        (10U)
#define GIC_DISTR_ICDICER_ID10_MASK                                                                         (0x00000400U)

#define GIC_DISTR_ICDICER_ID11_SHIFT                                                                        (11U)
#define GIC_DISTR_ICDICER_ID11_MASK                                                                         (0x00000800U)

#define GIC_DISTR_ICDICER_ID12_SHIFT                                                                        (12U)
#define GIC_DISTR_ICDICER_ID12_MASK                                                                         (0x00001000U)

#define GIC_DISTR_ICDICER_ID13_SHIFT                                                                        (13U)
#define GIC_DISTR_ICDICER_ID13_MASK                                                                         (0x00002000U)

#define GIC_DISTR_ICDICER_ID14_SHIFT                                                                        (14U)
#define GIC_DISTR_ICDICER_ID14_MASK                                                                         (0x00004000U)

#define GIC_DISTR_ICDICER_ID15_SHIFT                                                                        (15U)
#define GIC_DISTR_ICDICER_ID15_MASK                                                                         (0x00008000U)

#define GIC_DISTR_ICDICER_ID16_SHIFT                                                                        (16U)
#define GIC_DISTR_ICDICER_ID16_MASK                                                                         (0x00010000U)

#define GIC_DISTR_ICDICER_ID17_SHIFT                                                                        (17U)
#define GIC_DISTR_ICDICER_ID17_MASK                                                                         (0x00020000U)

#define GIC_DISTR_ICDICER_ID18_SHIFT                                                                        (18U)
#define GIC_DISTR_ICDICER_ID18_MASK                                                                         (0x00040000U)

#define GIC_DISTR_ICDICER_ID19_SHIFT                                                                        (19U)
#define GIC_DISTR_ICDICER_ID19_MASK                                                                         (0x00080000U)

#define GIC_DISTR_ICDICER_ID20_SHIFT                                                                        (20U)
#define GIC_DISTR_ICDICER_ID20_MASK                                                                         (0x00100000U)

#define GIC_DISTR_ICDICER_ID21_SHIFT                                                                        (21U)
#define GIC_DISTR_ICDICER_ID21_MASK                                                                         (0x00200000U)

#define GIC_DISTR_ICDICER_ID22_SHIFT                                                                        (22U)
#define GIC_DISTR_ICDICER_ID22_MASK                                                                         (0x00400000U)

#define GIC_DISTR_ICDICER_ID23_SHIFT                                                                        (23U)
#define GIC_DISTR_ICDICER_ID23_MASK                                                                         (0x00800000U)

#define GIC_DISTR_ICDICER_ID24_SHIFT                                                                        (24U)
#define GIC_DISTR_ICDICER_ID24_MASK                                                                         (0x01000000U)

#define GIC_DISTR_ICDICER_ID25_SHIFT                                                                        (25U)
#define GIC_DISTR_ICDICER_ID25_MASK                                                                         (0x02000000U)

#define GIC_DISTR_ICDICER_ID26_SHIFT                                                                        (26U)
#define GIC_DISTR_ICDICER_ID26_MASK                                                                         (0x04000000U)

#define GIC_DISTR_ICDICER_ID27_SHIFT                                                                        (27U)
#define GIC_DISTR_ICDICER_ID27_MASK                                                                         (0x08000000U)

#define GIC_DISTR_ICDICER_ID28_SHIFT                                                                        (28U)
#define GIC_DISTR_ICDICER_ID28_MASK                                                                         (0x10000000U)

#define GIC_DISTR_ICDICER_ID29_SHIFT                                                                        (29U)
#define GIC_DISTR_ICDICER_ID29_MASK                                                                         (0x20000000U)

#define GIC_DISTR_ICDICER_ID30_SHIFT                                                                        (30U)
#define GIC_DISTR_ICDICER_ID30_MASK                                                                         (0x40000000U)

#define GIC_DISTR_ICDICER_ID31_SHIFT                                                                        (31U)
#define GIC_DISTR_ICDICER_ID31_MASK                                                                         (0x80000000U)

#define GIC_DISTR_ICDISPR_ID0_SHIFT                                                                         (0U)
#define GIC_DISTR_ICDISPR_ID0_MASK                                                                          (0x00000001U)

#define GIC_DISTR_ICDISPR_ID1_SHIFT                                                                         (1U)
#define GIC_DISTR_ICDISPR_ID1_MASK                                                                          (0x00000002U)

#define GIC_DISTR_ICDISPR_ID2_SHIFT                                                                         (2U)
#define GIC_DISTR_ICDISPR_ID2_MASK                                                                          (0x00000004U)

#define GIC_DISTR_ICDISPR_ID3_SHIFT                                                                         (3U)
#define GIC_DISTR_ICDISPR_ID3_MASK                                                                          (0x00000008U)

#define GIC_DISTR_ICDISPR_ID4_SHIFT                                                                         (4U)
#define GIC_DISTR_ICDISPR_ID4_MASK                                                                          (0x00000010U)

#define GIC_DISTR_ICDISPR_ID5_SHIFT                                                                         (5U)
#define GIC_DISTR_ICDISPR_ID5_MASK                                                                          (0x00000020U)

#define GIC_DISTR_ICDISPR_ID6_SHIFT                                                                         (6U)
#define GIC_DISTR_ICDISPR_ID6_MASK                                                                          (0x00000040U)

#define GIC_DISTR_ICDISPR_ID7_SHIFT                                                                         (7U)
#define GIC_DISTR_ICDISPR_ID7_MASK                                                                          (0x00000080U)

#define GIC_DISTR_ICDISPR_ID8_SHIFT                                                                         (8U)
#define GIC_DISTR_ICDISPR_ID8_MASK                                                                          (0x00000100U)

#define GIC_DISTR_ICDISPR_ID9_SHIFT                                                                         (9U)
#define GIC_DISTR_ICDISPR_ID9_MASK                                                                          (0x00000200U)

#define GIC_DISTR_ICDISPR_ID10_SHIFT                                                                        (10U)
#define GIC_DISTR_ICDISPR_ID10_MASK                                                                         (0x00000400U)

#define GIC_DISTR_ICDISPR_ID11_SHIFT                                                                        (11U)
#define GIC_DISTR_ICDISPR_ID11_MASK                                                                         (0x00000800U)

#define GIC_DISTR_ICDISPR_ID12_SHIFT                                                                        (12U)
#define GIC_DISTR_ICDISPR_ID12_MASK                                                                         (0x00001000U)

#define GIC_DISTR_ICDISPR_ID13_SHIFT                                                                        (13U)
#define GIC_DISTR_ICDISPR_ID13_MASK                                                                         (0x00002000U)

#define GIC_DISTR_ICDISPR_ID14_SHIFT                                                                        (14U)
#define GIC_DISTR_ICDISPR_ID14_MASK                                                                         (0x00004000U)

#define GIC_DISTR_ICDISPR_ID15_SHIFT                                                                        (15U)
#define GIC_DISTR_ICDISPR_ID15_MASK                                                                         (0x00008000U)

#define GIC_DISTR_ICDISPR_ID16_SHIFT                                                                        (16U)
#define GIC_DISTR_ICDISPR_ID16_MASK                                                                         (0x00010000U)

#define GIC_DISTR_ICDISPR_ID17_SHIFT                                                                        (17U)
#define GIC_DISTR_ICDISPR_ID17_MASK                                                                         (0x00020000U)

#define GIC_DISTR_ICDISPR_ID18_SHIFT                                                                        (18U)
#define GIC_DISTR_ICDISPR_ID18_MASK                                                                         (0x00040000U)

#define GIC_DISTR_ICDISPR_ID19_SHIFT                                                                        (19U)
#define GIC_DISTR_ICDISPR_ID19_MASK                                                                         (0x00080000U)

#define GIC_DISTR_ICDISPR_ID20_SHIFT                                                                        (20U)
#define GIC_DISTR_ICDISPR_ID20_MASK                                                                         (0x00100000U)

#define GIC_DISTR_ICDISPR_ID21_SHIFT                                                                        (21U)
#define GIC_DISTR_ICDISPR_ID21_MASK                                                                         (0x00200000U)

#define GIC_DISTR_ICDISPR_ID22_SHIFT                                                                        (22U)
#define GIC_DISTR_ICDISPR_ID22_MASK                                                                         (0x00400000U)

#define GIC_DISTR_ICDISPR_ID23_SHIFT                                                                        (23U)
#define GIC_DISTR_ICDISPR_ID23_MASK                                                                         (0x00800000U)

#define GIC_DISTR_ICDISPR_ID24_SHIFT                                                                        (24U)
#define GIC_DISTR_ICDISPR_ID24_MASK                                                                         (0x01000000U)

#define GIC_DISTR_ICDISPR_ID25_SHIFT                                                                        (25U)
#define GIC_DISTR_ICDISPR_ID25_MASK                                                                         (0x02000000U)

#define GIC_DISTR_ICDISPR_ID26_SHIFT                                                                        (26U)
#define GIC_DISTR_ICDISPR_ID26_MASK                                                                         (0x04000000U)

#define GIC_DISTR_ICDISPR_ID27_SHIFT                                                                        (27U)
#define GIC_DISTR_ICDISPR_ID27_MASK                                                                         (0x08000000U)

#define GIC_DISTR_ICDISPR_ID28_SHIFT                                                                        (28U)
#define GIC_DISTR_ICDISPR_ID28_MASK                                                                         (0x10000000U)

#define GIC_DISTR_ICDISPR_ID29_SHIFT                                                                        (29U)
#define GIC_DISTR_ICDISPR_ID29_MASK                                                                         (0x20000000U)

#define GIC_DISTR_ICDISPR_ID30_SHIFT                                                                        (30U)
#define GIC_DISTR_ICDISPR_ID30_MASK                                                                         (0x40000000U)

#define GIC_DISTR_ICDISPR_ID31_SHIFT                                                                        (31U)
#define GIC_DISTR_ICDISPR_ID31_MASK                                                                         (0x80000000U)

#define GIC_DISTR_ICDICPR_ID0_SHIFT                                                                         (0U)
#define GIC_DISTR_ICDICPR_ID0_MASK                                                                          (0x00000001U)

#define GIC_DISTR_ICDICPR_ID1_SHIFT                                                                         (1U)
#define GIC_DISTR_ICDICPR_ID1_MASK                                                                          (0x00000002U)

#define GIC_DISTR_ICDICPR_ID2_SHIFT                                                                         (2U)
#define GIC_DISTR_ICDICPR_ID2_MASK                                                                          (0x00000004U)

#define GIC_DISTR_ICDICPR_ID3_SHIFT                                                                         (3U)
#define GIC_DISTR_ICDICPR_ID3_MASK                                                                          (0x00000008U)

#define GIC_DISTR_ICDICPR_ID4_SHIFT                                                                         (4U)
#define GIC_DISTR_ICDICPR_ID4_MASK                                                                          (0x00000010U)

#define GIC_DISTR_ICDICPR_ID5_SHIFT                                                                         (5U)
#define GIC_DISTR_ICDICPR_ID5_MASK                                                                          (0x00000020U)

#define GIC_DISTR_ICDICPR_ID6_SHIFT                                                                         (6U)
#define GIC_DISTR_ICDICPR_ID6_MASK                                                                          (0x00000040U)

#define GIC_DISTR_ICDICPR_ID7_SHIFT                                                                         (7U)
#define GIC_DISTR_ICDICPR_ID7_MASK                                                                          (0x00000080U)

#define GIC_DISTR_ICDICPR_ID8_SHIFT                                                                         (8U)
#define GIC_DISTR_ICDICPR_ID8_MASK                                                                          (0x00000100U)

#define GIC_DISTR_ICDICPR_ID9_SHIFT                                                                         (9U)
#define GIC_DISTR_ICDICPR_ID9_MASK                                                                          (0x00000200U)

#define GIC_DISTR_ICDICPR_ID10_SHIFT                                                                        (10U)
#define GIC_DISTR_ICDICPR_ID10_MASK                                                                         (0x00000400U)

#define GIC_DISTR_ICDICPR_ID11_SHIFT                                                                        (11U)
#define GIC_DISTR_ICDICPR_ID11_MASK                                                                         (0x00000800U)

#define GIC_DISTR_ICDICPR_ID12_SHIFT                                                                        (12U)
#define GIC_DISTR_ICDICPR_ID12_MASK                                                                         (0x00001000U)

#define GIC_DISTR_ICDICPR_ID13_SHIFT                                                                        (13U)
#define GIC_DISTR_ICDICPR_ID13_MASK                                                                         (0x00002000U)

#define GIC_DISTR_ICDICPR_ID14_SHIFT                                                                        (14U)
#define GIC_DISTR_ICDICPR_ID14_MASK                                                                         (0x00004000U)

#define GIC_DISTR_ICDICPR_ID15_SHIFT                                                                        (15U)
#define GIC_DISTR_ICDICPR_ID15_MASK                                                                         (0x00008000U)

#define GIC_DISTR_ICDICPR_ID16_SHIFT                                                                        (16U)
#define GIC_DISTR_ICDICPR_ID16_MASK                                                                         (0x00010000U)

#define GIC_DISTR_ICDICPR_ID17_SHIFT                                                                        (17U)
#define GIC_DISTR_ICDICPR_ID17_MASK                                                                         (0x00020000U)

#define GIC_DISTR_ICDICPR_ID18_SHIFT                                                                        (18U)
#define GIC_DISTR_ICDICPR_ID18_MASK                                                                         (0x00040000U)

#define GIC_DISTR_ICDICPR_ID19_SHIFT                                                                        (19U)
#define GIC_DISTR_ICDICPR_ID19_MASK                                                                         (0x00080000U)

#define GIC_DISTR_ICDICPR_ID20_SHIFT                                                                        (20U)
#define GIC_DISTR_ICDICPR_ID20_MASK                                                                         (0x00100000U)

#define GIC_DISTR_ICDICPR_ID21_SHIFT                                                                        (21U)
#define GIC_DISTR_ICDICPR_ID21_MASK                                                                         (0x00200000U)

#define GIC_DISTR_ICDICPR_ID22_SHIFT                                                                        (22U)
#define GIC_DISTR_ICDICPR_ID22_MASK                                                                         (0x00400000U)

#define GIC_DISTR_ICDICPR_ID23_SHIFT                                                                        (23U)
#define GIC_DISTR_ICDICPR_ID23_MASK                                                                         (0x00800000U)

#define GIC_DISTR_ICDICPR_ID24_SHIFT                                                                        (24U)
#define GIC_DISTR_ICDICPR_ID24_MASK                                                                         (0x01000000U)

#define GIC_DISTR_ICDICPR_ID25_SHIFT                                                                        (25U)
#define GIC_DISTR_ICDICPR_ID25_MASK                                                                         (0x02000000U)

#define GIC_DISTR_ICDICPR_ID26_SHIFT                                                                        (26U)
#define GIC_DISTR_ICDICPR_ID26_MASK                                                                         (0x04000000U)

#define GIC_DISTR_ICDICPR_ID27_SHIFT                                                                        (27U)
#define GIC_DISTR_ICDICPR_ID27_MASK                                                                         (0x08000000U)

#define GIC_DISTR_ICDICPR_ID28_SHIFT                                                                        (28U)
#define GIC_DISTR_ICDICPR_ID28_MASK                                                                         (0x10000000U)

#define GIC_DISTR_ICDICPR_ID29_SHIFT                                                                        (29U)
#define GIC_DISTR_ICDICPR_ID29_MASK                                                                         (0x20000000U)

#define GIC_DISTR_ICDICPR_ID30_SHIFT                                                                        (30U)
#define GIC_DISTR_ICDICPR_ID30_MASK                                                                         (0x40000000U)

#define GIC_DISTR_ICDICPR_ID31_SHIFT                                                                        (31U)
#define GIC_DISTR_ICDICPR_ID31_MASK                                                                         (0x80000000U)

#define GIC_DISTR_ICDABR_ID0_SHIFT                                                                          (0U)
#define GIC_DISTR_ICDABR_ID0_MASK                                                                           (0x00000001U)

#define GIC_DISTR_ICDABR_ID1_SHIFT                                                                          (1U)
#define GIC_DISTR_ICDABR_ID1_MASK                                                                           (0x00000002U)

#define GIC_DISTR_ICDABR_ID2_SHIFT                                                                          (2U)
#define GIC_DISTR_ICDABR_ID2_MASK                                                                           (0x00000004U)

#define GIC_DISTR_ICDABR_ID3_SHIFT                                                                          (3U)
#define GIC_DISTR_ICDABR_ID3_MASK                                                                           (0x00000008U)

#define GIC_DISTR_ICDABR_ID4_SHIFT                                                                          (4U)
#define GIC_DISTR_ICDABR_ID4_MASK                                                                           (0x00000010U)

#define GIC_DISTR_ICDABR_ID5_SHIFT                                                                          (5U)
#define GIC_DISTR_ICDABR_ID5_MASK                                                                           (0x00000020U)

#define GIC_DISTR_ICDABR_ID6_SHIFT                                                                          (6U)
#define GIC_DISTR_ICDABR_ID6_MASK                                                                           (0x00000040U)

#define GIC_DISTR_ICDABR_ID7_SHIFT                                                                          (7U)
#define GIC_DISTR_ICDABR_ID7_MASK                                                                           (0x00000080U)

#define GIC_DISTR_ICDABR_ID8_SHIFT                                                                          (8U)
#define GIC_DISTR_ICDABR_ID8_MASK                                                                           (0x00000100U)

#define GIC_DISTR_ICDABR_ID9_SHIFT                                                                          (9U)
#define GIC_DISTR_ICDABR_ID9_MASK                                                                           (0x00000200U)

#define GIC_DISTR_ICDABR_ID10_SHIFT                                                                         (10U)
#define GIC_DISTR_ICDABR_ID10_MASK                                                                          (0x00000400U)

#define GIC_DISTR_ICDABR_ID11_SHIFT                                                                         (11U)
#define GIC_DISTR_ICDABR_ID11_MASK                                                                          (0x00000800U)

#define GIC_DISTR_ICDABR_ID12_SHIFT                                                                         (12U)
#define GIC_DISTR_ICDABR_ID12_MASK                                                                          (0x00001000U)

#define GIC_DISTR_ICDABR_ID13_SHIFT                                                                         (13U)
#define GIC_DISTR_ICDABR_ID13_MASK                                                                          (0x00002000U)

#define GIC_DISTR_ICDABR_ID14_SHIFT                                                                         (14U)
#define GIC_DISTR_ICDABR_ID14_MASK                                                                          (0x00004000U)

#define GIC_DISTR_ICDABR_ID15_SHIFT                                                                         (15U)
#define GIC_DISTR_ICDABR_ID15_MASK                                                                          (0x00008000U)

#define GIC_DISTR_ICDABR_ID16_SHIFT                                                                         (16U)
#define GIC_DISTR_ICDABR_ID16_MASK                                                                          (0x00010000U)

#define GIC_DISTR_ICDABR_ID17_SHIFT                                                                         (17U)
#define GIC_DISTR_ICDABR_ID17_MASK                                                                          (0x00020000U)

#define GIC_DISTR_ICDABR_ID18_SHIFT                                                                         (18U)
#define GIC_DISTR_ICDABR_ID18_MASK                                                                          (0x00040000U)

#define GIC_DISTR_ICDABR_ID19_SHIFT                                                                         (19U)
#define GIC_DISTR_ICDABR_ID19_MASK                                                                          (0x00080000U)

#define GIC_DISTR_ICDABR_ID20_SHIFT                                                                         (20U)
#define GIC_DISTR_ICDABR_ID20_MASK                                                                          (0x00100000U)

#define GIC_DISTR_ICDABR_ID21_SHIFT                                                                         (21U)
#define GIC_DISTR_ICDABR_ID21_MASK                                                                          (0x00200000U)

#define GIC_DISTR_ICDABR_ID22_SHIFT                                                                         (22U)
#define GIC_DISTR_ICDABR_ID22_MASK                                                                          (0x00400000U)

#define GIC_DISTR_ICDABR_ID23_SHIFT                                                                         (23U)
#define GIC_DISTR_ICDABR_ID23_MASK                                                                          (0x00800000U)

#define GIC_DISTR_ICDABR_ID24_SHIFT                                                                         (24U)
#define GIC_DISTR_ICDABR_ID24_MASK                                                                          (0x01000000U)

#define GIC_DISTR_ICDABR_ID25_SHIFT                                                                         (25U)
#define GIC_DISTR_ICDABR_ID25_MASK                                                                          (0x02000000U)

#define GIC_DISTR_ICDABR_ID26_SHIFT                                                                         (26U)
#define GIC_DISTR_ICDABR_ID26_MASK                                                                          (0x04000000U)

#define GIC_DISTR_ICDABR_ID27_SHIFT                                                                         (27U)
#define GIC_DISTR_ICDABR_ID27_MASK                                                                          (0x08000000U)

#define GIC_DISTR_ICDABR_ID28_SHIFT                                                                         (28U)
#define GIC_DISTR_ICDABR_ID28_MASK                                                                          (0x10000000U)

#define GIC_DISTR_ICDABR_ID29_SHIFT                                                                         (29U)
#define GIC_DISTR_ICDABR_ID29_MASK                                                                          (0x20000000U)

#define GIC_DISTR_ICDABR_ID30_SHIFT                                                                         (30U)
#define GIC_DISTR_ICDABR_ID30_MASK                                                                          (0x40000000U)

#define GIC_DISTR_ICDABR_ID31_SHIFT                                                                         (31U)
#define GIC_DISTR_ICDABR_ID31_MASK                                                                          (0x80000000U)

#define GIC_DISTR_ICDIPR_ID0_SHIFT                                                                          (0U)
#define GIC_DISTR_ICDIPR_ID0_MASK                                                                           (0x000000ffU)

#define GIC_DISTR_ICDIPR_ID1_SHIFT                                                                          (8U)
#define GIC_DISTR_ICDIPR_ID1_MASK                                                                           (0x0000ff00U)

#define GIC_DISTR_ICDIPR_ID2_SHIFT                                                                          (16U)
#define GIC_DISTR_ICDIPR_ID2_MASK                                                                           (0x00ff0000U)

#define GIC_DISTR_ICDIPR_ID3_SHIFT                                                                          (24U)
#define GIC_DISTR_ICDIPR_ID3_MASK                                                                           (0xff000000U)

#define GIC_DISTR_ICDIPTR_ID0_SHIFT                                                                         (0U)
#define GIC_DISTR_ICDIPTR_ID0_MASK                                                                          (0x00000001U)

#define GIC_DISTR_ICDIPTR_ID1_SHIFT                                                                         (8U)
#define GIC_DISTR_ICDIPTR_ID1_MASK                                                                          (0x00000100U)

#define GIC_DISTR_ICDIPTR_ID2_SHIFT                                                                         (16U)
#define GIC_DISTR_ICDIPTR_ID2_MASK                                                                          (0x00010000U)

#define GIC_DISTR_ICDIPTR_ID3_SHIFT                                                                         (24U)
#define GIC_DISTR_ICDIPTR_ID3_MASK                                                                          (0x01000000U)

#define GIC_DISTR_ICDIPTR_RESERVED_SHIFT                                                                    (1U)
#define GIC_DISTR_ICDIPTR_RESERVED_MASK                                                                     (0x000000feU)

#define GIC_DISTR_ICDIPTR_RESERVED1_SHIFT                                                                   (9U)
#define GIC_DISTR_ICDIPTR_RESERVED1_MASK                                                                    (0x0000fe00U)

#define GIC_DISTR_ICDIPTR_RESERVED2_SHIFT                                                                   (17U)
#define GIC_DISTR_ICDIPTR_RESERVED2_MASK                                                                    (0x00fe0000U)

#define GIC_DISTR_ICDIPTR_RESERVED3_SHIFT                                                                   (25U)
#define GIC_DISTR_ICDIPTR_RESERVED3_MASK                                                                    (0xfe000000U)

#define GIC_DISTR_ICDICFR_ID0_SHIFT                                                                         (0U)
#define GIC_DISTR_ICDICFR_ID0_MASK                                                                          (0x00000003U)

#define GIC_DISTR_ICDICFR_ID1_SHIFT                                                                         (2U)
#define GIC_DISTR_ICDICFR_ID1_MASK                                                                          (0x0000000cU)

#define GIC_DISTR_ICDICFR_ID2_SHIFT                                                                         (4U)
#define GIC_DISTR_ICDICFR_ID2_MASK                                                                          (0x00000030U)

#define GIC_DISTR_ICDICFR_ID3_SHIFT                                                                         (6U)
#define GIC_DISTR_ICDICFR_ID3_MASK                                                                          (0x000000c0U)

#define GIC_DISTR_ICDICFR_ID4_SHIFT                                                                         (8U)
#define GIC_DISTR_ICDICFR_ID4_MASK                                                                          (0x00000300U)

#define GIC_DISTR_ICDICFR_ID5_SHIFT                                                                         (10U)
#define GIC_DISTR_ICDICFR_ID5_MASK                                                                          (0x00000c00U)

#define GIC_DISTR_ICDICFR_ID6_SHIFT                                                                         (12U)
#define GIC_DISTR_ICDICFR_ID6_MASK                                                                          (0x00003000U)

#define GIC_DISTR_ICDICFR_ID7_SHIFT                                                                         (14U)
#define GIC_DISTR_ICDICFR_ID7_MASK                                                                          (0x0000c000U)

#define GIC_DISTR_ICDICFR_ID8_SHIFT                                                                         (16U)
#define GIC_DISTR_ICDICFR_ID8_MASK                                                                          (0x00030000U)

#define GIC_DISTR_ICDICFR_ID9_SHIFT                                                                         (18U)
#define GIC_DISTR_ICDICFR_ID9_MASK                                                                          (0x000c0000U)

#define GIC_DISTR_ICDICFR_ID10_SHIFT                                                                        (20U)
#define GIC_DISTR_ICDICFR_ID10_MASK                                                                         (0x00300000U)

#define GIC_DISTR_ICDICFR_ID11_SHIFT                                                                        (22U)
#define GIC_DISTR_ICDICFR_ID11_MASK                                                                         (0x00c00000U)

#define GIC_DISTR_ICDICFR_ID12_SHIFT                                                                        (24U)
#define GIC_DISTR_ICDICFR_ID12_MASK                                                                         (0x03000000U)

#define GIC_DISTR_ICDICFR_ID13_SHIFT                                                                        (26U)
#define GIC_DISTR_ICDICFR_ID13_MASK                                                                         (0x0c000000U)

#define GIC_DISTR_ICDICFR_ID15_SHIFT                                                                        (30U)
#define GIC_DISTR_ICDICFR_ID15_MASK                                                                         (0xc0000000U)

#define GIC_DISTR_ICDICFR_ID14_SHIFT                                                                        (28U)
#define GIC_DISTR_ICDICFR_ID14_MASK                                                                         (0x30000000U)

#define GIC_DISTR_PPI_STATUS_PPI_1_SHIFT                                                                    (12U)
#define GIC_DISTR_PPI_STATUS_PPI_1_MASK                                                                     (0x00001000U)

#define GIC_DISTR_PPI_STATUS_PPI_2_SHIFT                                                                    (13U)
#define GIC_DISTR_PPI_STATUS_PPI_2_MASK                                                                     (0x00002000U)

#define GIC_DISTR_PPI_STATUS_PPI_3_SHIFT                                                                    (14U)
#define GIC_DISTR_PPI_STATUS_PPI_3_MASK                                                                     (0x00004000U)

#define GIC_DISTR_PPI_STATUS_PPI_4_SHIFT                                                                    (15U)
#define GIC_DISTR_PPI_STATUS_PPI_4_MASK                                                                     (0x00008000U)

#define GIC_DISTR_PPI_STATUS_RESERVED_SHIFT                                                                 (0U)
#define GIC_DISTR_PPI_STATUS_RESERVED_MASK                                                                  (0x000007ffU)

#define GIC_DISTR_PPI_STATUS_PPI_0_SHIFT                                                                    (11U)
#define GIC_DISTR_PPI_STATUS_PPI_0_MASK                                                                     (0x00000800U)

#define GIC_DISTR_PPI_STATUS_RESERVED2_SHIFT                                                                (16U)
#define GIC_DISTR_PPI_STATUS_RESERVED2_MASK                                                                 (0xffff0000U)

#define GIC_DISTR_SPI_STATUS_SPI_0_SHIFT                                                                    (0U)
#define GIC_DISTR_SPI_STATUS_SPI_0_MASK                                                                     (0x00000001U)

#define GIC_DISTR_SPI_STATUS_SPI_1_SHIFT                                                                    (1U)
#define GIC_DISTR_SPI_STATUS_SPI_1_MASK                                                                     (0x00000002U)

#define GIC_DISTR_SPI_STATUS_SPI_2_SHIFT                                                                    (2U)
#define GIC_DISTR_SPI_STATUS_SPI_2_MASK                                                                     (0x00000004U)

#define GIC_DISTR_SPI_STATUS_SPI_3_SHIFT                                                                    (3U)
#define GIC_DISTR_SPI_STATUS_SPI_3_MASK                                                                     (0x00000008U)

#define GIC_DISTR_SPI_STATUS_SPI_4_SHIFT                                                                    (4U)
#define GIC_DISTR_SPI_STATUS_SPI_4_MASK                                                                     (0x00000010U)

#define GIC_DISTR_SPI_STATUS_SPI_5_SHIFT                                                                    (5U)
#define GIC_DISTR_SPI_STATUS_SPI_5_MASK                                                                     (0x00000020U)

#define GIC_DISTR_SPI_STATUS_SPI_6_SHIFT                                                                    (6U)
#define GIC_DISTR_SPI_STATUS_SPI_6_MASK                                                                     (0x00000040U)

#define GIC_DISTR_SPI_STATUS_SPI_7_SHIFT                                                                    (7U)
#define GIC_DISTR_SPI_STATUS_SPI_7_MASK                                                                     (0x00000080U)

#define GIC_DISTR_SPI_STATUS_SPI_8_SHIFT                                                                    (8U)
#define GIC_DISTR_SPI_STATUS_SPI_8_MASK                                                                     (0x00000100U)

#define GIC_DISTR_SPI_STATUS_SPI_9_SHIFT                                                                    (9U)
#define GIC_DISTR_SPI_STATUS_SPI_9_MASK                                                                     (0x00000200U)

#define GIC_DISTR_SPI_STATUS_SPI_10_SHIFT                                                                   (10U)
#define GIC_DISTR_SPI_STATUS_SPI_10_MASK                                                                    (0x00000400U)

#define GIC_DISTR_SPI_STATUS_SPI_11_SHIFT                                                                   (11U)
#define GIC_DISTR_SPI_STATUS_SPI_11_MASK                                                                    (0x00000800U)

#define GIC_DISTR_SPI_STATUS_SPI_12_SHIFT                                                                   (12U)
#define GIC_DISTR_SPI_STATUS_SPI_12_MASK                                                                    (0x00001000U)

#define GIC_DISTR_SPI_STATUS_SPI_13_SHIFT                                                                   (13U)
#define GIC_DISTR_SPI_STATUS_SPI_13_MASK                                                                    (0x00002000U)

#define GIC_DISTR_SPI_STATUS_SPI_14_SHIFT                                                                   (14U)
#define GIC_DISTR_SPI_STATUS_SPI_14_MASK                                                                    (0x00004000U)

#define GIC_DISTR_SPI_STATUS_SPI_15_SHIFT                                                                   (15U)
#define GIC_DISTR_SPI_STATUS_SPI_15_MASK                                                                    (0x00008000U)

#define GIC_DISTR_SPI_STATUS_SPI_16_SHIFT                                                                   (16U)
#define GIC_DISTR_SPI_STATUS_SPI_16_MASK                                                                    (0x00010000U)

#define GIC_DISTR_SPI_STATUS_SPI_17_SHIFT                                                                   (17U)
#define GIC_DISTR_SPI_STATUS_SPI_17_MASK                                                                    (0x00020000U)

#define GIC_DISTR_SPI_STATUS_SPI_18_SHIFT                                                                   (18U)
#define GIC_DISTR_SPI_STATUS_SPI_18_MASK                                                                    (0x00040000U)

#define GIC_DISTR_SPI_STATUS_SPI_19_SHIFT                                                                   (19U)
#define GIC_DISTR_SPI_STATUS_SPI_19_MASK                                                                    (0x00080000U)

#define GIC_DISTR_SPI_STATUS_SPI_20_SHIFT                                                                   (20U)
#define GIC_DISTR_SPI_STATUS_SPI_20_MASK                                                                    (0x00100000U)

#define GIC_DISTR_SPI_STATUS_SPI_21_SHIFT                                                                   (21U)
#define GIC_DISTR_SPI_STATUS_SPI_21_MASK                                                                    (0x00200000U)

#define GIC_DISTR_SPI_STATUS_SPI_22_SHIFT                                                                   (22U)
#define GIC_DISTR_SPI_STATUS_SPI_22_MASK                                                                    (0x00400000U)

#define GIC_DISTR_SPI_STATUS_SPI_23_SHIFT                                                                   (23U)
#define GIC_DISTR_SPI_STATUS_SPI_23_MASK                                                                    (0x00800000U)

#define GIC_DISTR_SPI_STATUS_SPI_24_SHIFT                                                                   (24U)
#define GIC_DISTR_SPI_STATUS_SPI_24_MASK                                                                    (0x01000000U)

#define GIC_DISTR_SPI_STATUS_SPI_25_SHIFT                                                                   (25U)
#define GIC_DISTR_SPI_STATUS_SPI_25_MASK                                                                    (0x02000000U)

#define GIC_DISTR_SPI_STATUS_SPI_26_SHIFT                                                                   (26U)
#define GIC_DISTR_SPI_STATUS_SPI_26_MASK                                                                    (0x04000000U)

#define GIC_DISTR_SPI_STATUS_SPI_27_SHIFT                                                                   (27U)
#define GIC_DISTR_SPI_STATUS_SPI_27_MASK                                                                    (0x08000000U)

#define GIC_DISTR_SPI_STATUS_SPI_28_SHIFT                                                                   (28U)
#define GIC_DISTR_SPI_STATUS_SPI_28_MASK                                                                    (0x10000000U)

#define GIC_DISTR_SPI_STATUS_SPI_29_SHIFT                                                                   (29U)
#define GIC_DISTR_SPI_STATUS_SPI_29_MASK                                                                    (0x20000000U)

#define GIC_DISTR_SPI_STATUS_SPI_30_SHIFT                                                                   (30U)
#define GIC_DISTR_SPI_STATUS_SPI_30_MASK                                                                    (0x40000000U)

#define GIC_DISTR_SPI_STATUS_SPI_31_SHIFT                                                                   (31U)
#define GIC_DISTR_SPI_STATUS_SPI_31_MASK                                                                    (0x80000000U)

#define GIC_DISTR_ICDSGIR_SGI_INTID_SHIFT                                                                   (0U)
#define GIC_DISTR_ICDSGIR_SGI_INTID_MASK                                                                    (0x0000000fU)

#define GIC_DISTR_ICDSGIR_SATT_SHIFT                                                                        (15U)
#define GIC_DISTR_ICDSGIR_SATT_MASK                                                                         (0x00008000U)

#define GIC_DISTR_ICDSGIR_CPU_TARGET_LIST_SHIFT                                                             (16U)
#define GIC_DISTR_ICDSGIR_CPU_TARGET_LIST_MASK                                                              (0x000f0000U)

#define GIC_DISTR_ICDSGIR_TARGET_LIST_FILTER_SHIFT                                                          (24U)
#define GIC_DISTR_ICDSGIR_TARGET_LIST_FILTER_MASK                                                           (0x03000000U)

#define GIC_DISTR_ICDSGIR_RESERVED_SHIFT                                                                    (4U)
#define GIC_DISTR_ICDSGIR_RESERVED_MASK                                                                     (0x00007ff0U)

#define GIC_DISTR_ICDSGIR_RESERVED1_SHIFT                                                                   (20U)
#define GIC_DISTR_ICDSGIR_RESERVED1_MASK                                                                    (0x00f00000U)

#define GIC_DISTR_ICDSGIR_RESERVED2_SHIFT                                                                   (26U)
#define GIC_DISTR_ICDSGIR_RESERVED2_MASK                                                                    (0xfc000000U)

#define GIC_DISTR_PERIPH_ID_4_JEP106_C_CODE_SHIFT                                                           (0U)
#define GIC_DISTR_PERIPH_ID_4_JEP106_C_CODE_MASK                                                            (0x0000000fU)

#define GIC_DISTR_PERIPH_ID_4_FOUR_KB_COUNT_SHIFT                                                           (4U)
#define GIC_DISTR_PERIPH_ID_4_FOUR_KB_COUNT_MASK                                                            (0x000000f0U)

#define GIC_DISTR_PERIPH_ID_4_RESERVED_SHIFT                                                                (8U)
#define GIC_DISTR_PERIPH_ID_4_RESERVED_MASK                                                                 (0xffffff00U)

#define GIC_DISTR_PERIPH_ID_0_PART_NUM_0_SHIFT                                                              (0U)
#define GIC_DISTR_PERIPH_ID_0_PART_NUM_0_MASK                                                               (0x000000ffU)

#define GIC_DISTR_PERIPH_ID_0_RESERVED_SHIFT                                                                (8U)
#define GIC_DISTR_PERIPH_ID_0_RESERVED_MASK                                                                 (0xffffff00U)

#define GIC_DISTR_PERIPH_ID_1_PART_NUM_1_SHIFT                                                              (0U)
#define GIC_DISTR_PERIPH_ID_1_PART_NUM_1_MASK                                                               (0x0000000fU)

#define GIC_DISTR_PERIPH_ID_1_JEP106_ID_3_0_SHIFT                                                           (4U)
#define GIC_DISTR_PERIPH_ID_1_JEP106_ID_3_0_MASK                                                            (0x000000f0U)

#define GIC_DISTR_PERIPH_ID_1_RESERVED_SHIFT                                                                (8U)
#define GIC_DISTR_PERIPH_ID_1_RESERVED_MASK                                                                 (0xffffff00U)

#define GIC_DISTR_PERIPH_ID_2_JEP106_ID_6_4_SHIFT                                                           (0U)
#define GIC_DISTR_PERIPH_ID_2_JEP106_ID_6_4_MASK                                                            (0x00000007U)

#define GIC_DISTR_PERIPH_ID_2_JDEC_USED_SHIFT                                                               (3U)
#define GIC_DISTR_PERIPH_ID_2_JDEC_USED_MASK                                                                (0x00000008U)

#define GIC_DISTR_PERIPH_ID_2_ARCH_NUM_SHIFT                                                                (4U)
#define GIC_DISTR_PERIPH_ID_2_ARCH_NUM_MASK                                                                 (0x000000f0U)

#define GIC_DISTR_PERIPH_ID_2_RESERVED_SHIFT                                                                (8U)
#define GIC_DISTR_PERIPH_ID_2_RESERVED_MASK                                                                 (0xffffff00U)

#define GIC_DISTR_PERIPH_ID_3_MOD_NUM_SHIFT                                                                 (0U)
#define GIC_DISTR_PERIPH_ID_3_MOD_NUM_MASK                                                                  (0x0000000fU)

#define GIC_DISTR_PERIPH_ID_3_REVAND_SHIFT                                                                  (4U)
#define GIC_DISTR_PERIPH_ID_3_REVAND_MASK                                                                   (0x000000f0U)

#define GIC_DISTR_PERIPH_ID_3_RESERVED_SHIFT                                                                (8U)
#define GIC_DISTR_PERIPH_ID_3_RESERVED_MASK                                                                 (0xffffff00U)

#define GIC_DISTR_COMPONENT_ID_0_COMPONENT_ID_0_SHIFT                                                       (0U)
#define GIC_DISTR_COMPONENT_ID_0_COMPONENT_ID_0_MASK                                                        (0x000000ffU)

#define GIC_DISTR_COMPONENT_ID_0_RESERVED_SHIFT                                                             (8U)
#define GIC_DISTR_COMPONENT_ID_0_RESERVED_MASK                                                              (0xffffff00U)

#define GIC_DISTR_COMPONENT_ID_1_COMPONENT_ID_1_SHIFT                                                       (0U)
#define GIC_DISTR_COMPONENT_ID_1_COMPONENT_ID_1_MASK                                                        (0x000000ffU)

#define GIC_DISTR_COMPONENT_ID_1_RESERVED_SHIFT                                                             (8U)
#define GIC_DISTR_COMPONENT_ID_1_RESERVED_MASK                                                              (0xffffff00U)

#define GIC_DISTR_COMPONENT_ID_2_COMPONENT_ID_2_SHIFT                                                       (0U)
#define GIC_DISTR_COMPONENT_ID_2_COMPONENT_ID_2_MASK                                                        (0x000000ffU)

#define GIC_DISTR_COMPONENT_ID_2_RESERVED_SHIFT                                                             (8U)
#define GIC_DISTR_COMPONENT_ID_2_RESERVED_MASK                                                              (0xffffff00U)

#define GIC_DISTR_COMPONENT_ID_3_COMPONENT_ID_3_SHIFT                                                       (0U)
#define GIC_DISTR_COMPONENT_ID_3_COMPONENT_ID_3_MASK                                                        (0x000000ffU)

#define GIC_DISTR_COMPONENT_ID_3_RESERVED_SHIFT                                                             (8U)
#define GIC_DISTR_COMPONENT_ID_3_RESERVED_MASK                                                              (0xffffff00U)

#ifdef __cplusplus
}
#endif
#endif  /* _HW_GIC_DISTRIBUTOR_H_ */
