/******************************************************************************
*
* hw_gic_cpu.h - register-level header file for HW_GIC_CPU
*
* Copyright (c) 2008-2013 Texas Instruments Incorporated.  All rights reserved.
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
#ifndef HW_GIC_CPU_H_
#define HW_GIC_CPU_H_

#ifdef __cplusplus
extern "C"
{
#endif

/****************************************************************************************************
* Register Definitions 
****************************************************************************************************/
#define GIC_CPU_ICCICR                                                                                      (0x0U)
#define GIC_CPU_ICCPMR                                                                                      (0x4U)
#define GIC_CPU_ICCBPR                                                                                      (0x8U)
#define GIC_CPU_ICCIAR                                                                                      (0xcU)
#define GIC_CPU_ICCEOIR                                                                                     (0x10U)
#define GIC_CPU_ICCRPR                                                                                      (0x14U)
#define GIC_CPU_ICCHPIR                                                                                     (0x18U)
#define GIC_CPU_ICCABPR                                                                                     (0x1cU)
#define GIC_CPU_ICCICR_NS                                                                                   (0x0U)
#define GIC_CPU_ICCIIDR                                                                                     (0xfcU)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define GIC_CPU_ICCICR_ENABLES_SHIFT                                                                        (0U)
#define GIC_CPU_ICCICR_ENABLES_MASK                                                                         (0x00000001U)

#define GIC_CPU_ICCICR_ENABLENS_SHIFT                                                                       (1U)
#define GIC_CPU_ICCICR_ENABLENS_MASK                                                                        (0x00000002U)

#define GIC_CPU_ICCICR_ACKCTL_SHIFT                                                                         (2U)
#define GIC_CPU_ICCICR_ACKCTL_MASK                                                                          (0x00000004U)

#define GIC_CPU_ICCICR_FIQEN_SHIFT                                                                          (3U)
#define GIC_CPU_ICCICR_FIQEN_MASK                                                                           (0x00000008U)

#define GIC_CPU_ICCICR_SBPR_SHIFT                                                                           (4U)
#define GIC_CPU_ICCICR_SBPR_MASK                                                                            (0x00000010U)

#define GIC_CPU_ICCICR_RESERVED_SHIFT                                                                       (5U)
#define GIC_CPU_ICCICR_RESERVED_MASK                                                                        (0xffffffe0U)

#define GIC_CPU_ICCPMR_PRIORITY_SHIFT                                                                       (3U)
#define GIC_CPU_ICCPMR_PRIORITY_MASK                                                                        (0x000000f8U)

#define GIC_CPU_ICCPMR_RESERVED_SHIFT                                                                       (0U)
#define GIC_CPU_ICCPMR_RESERVED_MASK                                                                        (0x00000007U)

#define GIC_CPU_ICCPMR_RESERVED1_SHIFT                                                                      (8U)
#define GIC_CPU_ICCPMR_RESERVED1_MASK                                                                       (0xffffff00U)

#define GIC_CPU_ICCBPR_BINARY_POINT_SHIFT                                                                   (0U)
#define GIC_CPU_ICCBPR_BINARY_POINT_MASK                                                                    (0x00000007U)

#define GIC_CPU_ICCBPR_RESERVED_SHIFT                                                                       (3U)
#define GIC_CPU_ICCBPR_RESERVED_MASK                                                                        (0xfffffff8U)

#define GIC_CPU_ICCIAR_ACK_INTID_SHIFT                                                                      (0U)
#define GIC_CPU_ICCIAR_ACK_INTID_MASK                                                                       (0x000003ffU)

#define GIC_CPU_ICCIAR_SOURCE_CPUID_SHIFT                                                                   (10U)
#define GIC_CPU_ICCIAR_SOURCE_CPUID_MASK                                                                    (0x00001c00U)

#define GIC_CPU_ICCIAR_RESERVED_SHIFT                                                                       (13U)
#define GIC_CPU_ICCIAR_RESERVED_MASK                                                                        (0xffffe000U)

#define GIC_CPU_ICCEOIR_EOI_INTID_SHIFT                                                                     (0U)
#define GIC_CPU_ICCEOIR_EOI_INTID_MASK                                                                      (0x000003ffU)

#define GIC_CPU_ICCEOIR_SOURCE_CPUID_SHIFT                                                                  (10U)
#define GIC_CPU_ICCEOIR_SOURCE_CPUID_MASK                                                                   (0x00001c00U)

#define GIC_CPU_ICCEOIR_RESERVED_SHIFT                                                                      (13U)
#define GIC_CPU_ICCEOIR_RESERVED_MASK                                                                       (0xffffe000U)

#define GIC_CPU_ICCRPR_PRIORITY_SHIFT                                                                       (3U)
#define GIC_CPU_ICCRPR_PRIORITY_MASK                                                                        (0x000000f8U)

#define GIC_CPU_ICCRPR_RESERVED_SHIFT                                                                       (0U)
#define GIC_CPU_ICCRPR_RESERVED_MASK                                                                        (0x00000007U)

#define GIC_CPU_ICCRPR_RESERVED1_SHIFT                                                                      (8U)
#define GIC_CPU_ICCRPR_RESERVED1_MASK                                                                       (0xffffff00U)

#define GIC_CPU_ICCHPIR_PENDINTID_SHIFT                                                                     (0U)
#define GIC_CPU_ICCHPIR_PENDINTID_MASK                                                                      (0x000003ffU)

#define GIC_CPU_ICCHPIR_SOURCE_CPUID_SHIFT                                                                  (10U)
#define GIC_CPU_ICCHPIR_SOURCE_CPUID_MASK                                                                   (0x00001c00U)

#define GIC_CPU_ICCHPIR_RESERVED_SHIFT                                                                      (13U)
#define GIC_CPU_ICCHPIR_RESERVED_MASK                                                                       (0xffffe000U)

#define GIC_CPU_ICCABPR_BINARYPOINTER_SHIFT                                                                 (0U)
#define GIC_CPU_ICCABPR_BINARYPOINTER_MASK                                                                  (0x00000007U)

#define GIC_CPU_ICCABPR_RESERVED_SHIFT                                                                      (3U)
#define GIC_CPU_ICCABPR_RESERVED_MASK                                                                       (0xfffffff8U)

#define GIC_CPU_ICCICR_NS_ENABLE_SHIFT                                                                      (0U)
#define GIC_CPU_ICCICR_NS_ENABLE_MASK                                                                       (0x00000001U)

#define GIC_CPU_ICCICR_NS_RESERVED_SHIFT                                                                    (1U)
#define GIC_CPU_ICCICR_NS_RESERVED_MASK                                                                     (0xfffffffeU)

#define GIC_CPU_ICCIIDR_IMPLEMENTER_SHIFT                                                                   (0U)
#define GIC_CPU_ICCIIDR_IMPLEMENTER_MASK                                                                    (0x00000fffU)

#define GIC_CPU_ICCIIDR_REVISION_NUMBER_SHIFT                                                               (12U)
#define GIC_CPU_ICCIIDR_REVISION_NUMBER_MASK                                                                (0x0000f000U)

#define GIC_CPU_ICCIIDR_ARCHITECTURE_NUMBER_SHIFT                                                           (16U)
#define GIC_CPU_ICCIIDR_ARCHITECTURE_NUMBER_MASK                                                            (0x000f0000U)

#define GIC_CPU_ICCIIDR_PART_NUMBER_SHIFT                                                                   (20U)
#define GIC_CPU_ICCIIDR_PART_NUMBER_MASK                                                                    (0xfff00000U)

#ifdef __cplusplus
}
#endif
#endif  /* _HW_GIC_CPU_H_ */
