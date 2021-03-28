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
#ifndef CSLR_ARMGICCPUIF_H_
#define CSLR_ARMGICCPUIF_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 ICR;
    volatile Uint32 PMR;
    volatile Uint32 BPR;
    volatile Uint32 IAR;
    volatile Uint32 EOIR;
    volatile Uint32 RPR;
    volatile Uint32 HPIR;
    volatile Uint32 ABPR;
    volatile Uint32 AIAR;
    volatile Uint32 AEOIR;
    volatile Uint32 AHPPIR;
    volatile Uint8  RSVD0[164];
    volatile Uint32 APR0;
    volatile Uint8  RSVD1[12];
    volatile Uint32 NSAPR0;
    volatile Uint8  RSVD2[24];
    volatile Uint32 IIDR;
    volatile Uint8  RSVD3[3840];
    volatile Uint32 DIR;
} CSL_ArmGicCpuifRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* CPU Interface Control Register */
#define CSL_ARMGICCPUIF_ICR                                     (0x0U)

/* Interrupt Priority Mask Register */
#define CSL_ARMGICCPUIF_PMR                                     (0x4U)

/* Binary Point Register */
#define CSL_ARMGICCPUIF_BPR                                     (0x8U)

/* Interrupt Acknowledge Register */
#define CSL_ARMGICCPUIF_IAR                                     (0xCU)

/* End Of Interrupt Register */
#define CSL_ARMGICCPUIF_EOIR                                    (0x10U)

/* Running Priority Register */
#define CSL_ARMGICCPUIF_RPR                                     (0x14U)

/* Highest Pending Interrupt Register */
#define CSL_ARMGICCPUIF_HPIR                                    (0x18U)

/* Aliased Binary Point Register */
#define CSL_ARMGICCPUIF_ABPR                                    (0x1CU)

/* Aliased Interrupt Acknowledge Register */
#define CSL_ARMGICCPUIF_AIAR                                    (0x20U)

/* End Of Interrupt Register */
#define CSL_ARMGICCPUIF_AEOIR                                   (0x24U)

/* Aliased Highest Priority Pending Interrupt Register */
#define CSL_ARMGICCPUIF_AHPPIR                                  (0x28U)

/* Active Priorities Register */
#define CSL_ARMGICCPUIF_APR0                                    (0xD0U)

/* Non-Secure Active Priorities Register */
#define CSL_ARMGICCPUIF_NSAPR0                                  (0xE0U)

/* CPU Interface Identification Register */
#define CSL_ARMGICCPUIF_IIDR                                    (0xFCU)

/* Deactivate Interrupt Register */
#define CSL_ARMGICCPUIF_DIR                                     (0x1000U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* ICR */

#define CSL_ARMGICCPUIF_ICR_ENS_MASK                            (0x00000001U)
#define CSL_ARMGICCPUIF_ICR_ENS_SHIFT                           (0U)
#define CSL_ARMGICCPUIF_ICR_ENS_RESETVAL                        (0x00000000U)
#define CSL_ARMGICCPUIF_ICR_ENS_MAX                             (0x00000001U)

#define CSL_ARMGICCPUIF_ICR_ENNS_MASK                           (0x00000002U)
#define CSL_ARMGICCPUIF_ICR_ENNS_SHIFT                          (1U)
#define CSL_ARMGICCPUIF_ICR_ENNS_RESETVAL                       (0x00000000U)
#define CSL_ARMGICCPUIF_ICR_ENNS_MAX                            (0x00000001U)

#define CSL_ARMGICCPUIF_ICR_ACKCTL_MASK                         (0x00000004U)
#define CSL_ARMGICCPUIF_ICR_ACKCTL_SHIFT                        (2U)
#define CSL_ARMGICCPUIF_ICR_ACKCTL_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_ICR_ACKCTL_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIF_ICR_FIQEN_MASK                          (0x00000008U)
#define CSL_ARMGICCPUIF_ICR_FIQEN_SHIFT                         (3U)
#define CSL_ARMGICCPUIF_ICR_FIQEN_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_ICR_FIQEN_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_ICR_SBPR_MASK                           (0x00000010U)
#define CSL_ARMGICCPUIF_ICR_SBPR_SHIFT                          (4U)
#define CSL_ARMGICCPUIF_ICR_SBPR_RESETVAL                       (0x00000000U)
#define CSL_ARMGICCPUIF_ICR_SBPR_MAX                            (0x00000001U)

#define CSL_ARMGICCPUIF_ICR_FIQBYPDISABLE_MASK                  (0x00000020U)
#define CSL_ARMGICCPUIF_ICR_FIQBYPDISABLE_SHIFT                 (5U)
#define CSL_ARMGICCPUIF_ICR_FIQBYPDISABLE_RESETVAL              (0x00000000U)
#define CSL_ARMGICCPUIF_ICR_FIQBYPDISABLE_MAX                   (0x00000001U)

#define CSL_ARMGICCPUIF_ICR_IRQBYPDISABLE_MASK                  (0x00000040U)
#define CSL_ARMGICCPUIF_ICR_IRQBYPDISABLE_SHIFT                 (6U)
#define CSL_ARMGICCPUIF_ICR_IRQBYPDISABLE_RESETVAL              (0x00000000U)
#define CSL_ARMGICCPUIF_ICR_IRQBYPDISABLE_MAX                   (0x00000001U)

#define CSL_ARMGICCPUIF_ICR_FIQBYPDISNS_MASK                    (0x00000080U)
#define CSL_ARMGICCPUIF_ICR_FIQBYPDISNS_SHIFT                   (7U)
#define CSL_ARMGICCPUIF_ICR_FIQBYPDISNS_RESETVAL                (0x00000000U)
#define CSL_ARMGICCPUIF_ICR_FIQBYPDISNS_MAX                     (0x00000001U)

#define CSL_ARMGICCPUIF_ICR_IRQBYPDISNS_MASK                    (0x00000100U)
#define CSL_ARMGICCPUIF_ICR_IRQBYPDISNS_SHIFT                   (8U)
#define CSL_ARMGICCPUIF_ICR_IRQBYPDISNS_RESETVAL                (0x00000000U)
#define CSL_ARMGICCPUIF_ICR_IRQBYPDISNS_MAX                     (0x00000001U)

#define CSL_ARMGICCPUIF_ICR_EOIMODE_MASK                        (0x00000200U)
#define CSL_ARMGICCPUIF_ICR_EOIMODE_SHIFT                       (9U)
#define CSL_ARMGICCPUIF_ICR_EOIMODE_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_ICR_EOIMODE_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_ICR_EOIMODENS_MASK                      (0x00000400U)
#define CSL_ARMGICCPUIF_ICR_EOIMODENS_SHIFT                     (10U)
#define CSL_ARMGICCPUIF_ICR_EOIMODENS_RESETVAL                  (0x00000000U)
#define CSL_ARMGICCPUIF_ICR_EOIMODENS_MAX                       (0x00000001U)

#define CSL_ARMGICCPUIF_ICR_RESETVAL                            (0x00000000U)

/* PMR */

#define CSL_ARMGICCPUIF_PMR_PRIORITY_MASK                       (0x000000F8U)
#define CSL_ARMGICCPUIF_PMR_PRIORITY_SHIFT                      (3U)
#define CSL_ARMGICCPUIF_PMR_PRIORITY_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIF_PMR_PRIORITY_MAX                        (0x0000001fU)

#define CSL_ARMGICCPUIF_PMR_RESETVAL                            (0x00000000U)

/* BPR */

#define CSL_ARMGICCPUIF_BPR_BINARYPOINT_MASK                    (0x00000007U)
#define CSL_ARMGICCPUIF_BPR_BINARYPOINT_SHIFT                   (0U)
#define CSL_ARMGICCPUIF_BPR_BINARYPOINT_RESETVAL                (0x00000002U)
#define CSL_ARMGICCPUIF_BPR_BINARYPOINT_MAX                     (0x00000007U)

#define CSL_ARMGICCPUIF_BPR_RESETVAL                            (0x00000002U)

/* IAR */

#define CSL_ARMGICCPUIF_IAR_ACKINTID_MASK                       (0x000003FFU)
#define CSL_ARMGICCPUIF_IAR_ACKINTID_SHIFT                      (0U)
#define CSL_ARMGICCPUIF_IAR_ACKINTID_RESETVAL                   (0x000003ffU)
#define CSL_ARMGICCPUIF_IAR_ACKINTID_MAX                        (0x000003ffU)

#define CSL_ARMGICCPUIF_IAR_CPUID_MASK                          (0x00001C00U)
#define CSL_ARMGICCPUIF_IAR_CPUID_SHIFT                         (10U)
#define CSL_ARMGICCPUIF_IAR_CPUID_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_IAR_CPUID_MAX                           (0x00000007U)

#define CSL_ARMGICCPUIF_IAR_RESETVAL                            (0x000003ffU)

/* EOIR */

#define CSL_ARMGICCPUIF_EOIR_EOIINTID_MASK                      (0x000003FFU)
#define CSL_ARMGICCPUIF_EOIR_EOIINTID_SHIFT                     (0U)
#define CSL_ARMGICCPUIF_EOIR_EOIINTID_RESETVAL                  (0x00000000U)
#define CSL_ARMGICCPUIF_EOIR_EOIINTID_MAX                       (0x000003ffU)

#define CSL_ARMGICCPUIF_EOIR_CPUID_MASK                         (0x00001C00U)
#define CSL_ARMGICCPUIF_EOIR_CPUID_SHIFT                        (10U)
#define CSL_ARMGICCPUIF_EOIR_CPUID_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_EOIR_CPUID_MAX                          (0x00000007U)

#define CSL_ARMGICCPUIF_EOIR_RESETVAL                           (0x00000000U)

/* RPR */

#define CSL_ARMGICCPUIF_RPR_PRIORITY_MASK                       (0x000000FFU)
#define CSL_ARMGICCPUIF_RPR_PRIORITY_SHIFT                      (0U)
#define CSL_ARMGICCPUIF_RPR_PRIORITY_RESETVAL                   (0x000000ffU)
#define CSL_ARMGICCPUIF_RPR_PRIORITY_MAX                        (0x000000ffU)

#define CSL_ARMGICCPUIF_RPR_RESETVAL                            (0x000000ffU)

/* HPIR */

#define CSL_ARMGICCPUIF_HPIR_CPUID_MASK                         (0x00001C00U)
#define CSL_ARMGICCPUIF_HPIR_CPUID_SHIFT                        (10U)
#define CSL_ARMGICCPUIF_HPIR_CPUID_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_HPIR_CPUID_MAX                          (0x00000007U)

#define CSL_ARMGICCPUIF_HPIR_PENDINTID_MASK                     (0x000003FFU)
#define CSL_ARMGICCPUIF_HPIR_PENDINTID_SHIFT                    (0U)
#define CSL_ARMGICCPUIF_HPIR_PENDINTID_RESETVAL                 (0x000003ffU)
#define CSL_ARMGICCPUIF_HPIR_PENDINTID_MAX                      (0x000003ffU)

#define CSL_ARMGICCPUIF_HPIR_RESETVAL                           (0x000003ffU)

/* ABPR */

#define CSL_ARMGICCPUIF_ABPR_BINARYPOINT_MASK                   (0x00000007U)
#define CSL_ARMGICCPUIF_ABPR_BINARYPOINT_SHIFT                  (0U)
#define CSL_ARMGICCPUIF_ABPR_BINARYPOINT_RESETVAL               (0x00000003U)
#define CSL_ARMGICCPUIF_ABPR_BINARYPOINT_MAX                    (0x00000007U)

#define CSL_ARMGICCPUIF_ABPR_RESETVAL                           (0x00000003U)

/* AIAR */

#define CSL_ARMGICCPUIF_AIAR_ACKINTID_MASK                      (0x000003FFU)
#define CSL_ARMGICCPUIF_AIAR_ACKINTID_SHIFT                     (0U)
#define CSL_ARMGICCPUIF_AIAR_ACKINTID_RESETVAL                  (0x000003ffU)
#define CSL_ARMGICCPUIF_AIAR_ACKINTID_MAX                       (0x000003ffU)

#define CSL_ARMGICCPUIF_AIAR_CPUID_MASK                         (0x00001C00U)
#define CSL_ARMGICCPUIF_AIAR_CPUID_SHIFT                        (10U)
#define CSL_ARMGICCPUIF_AIAR_CPUID_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_AIAR_CPUID_MAX                          (0x00000007U)

#define CSL_ARMGICCPUIF_AIAR_RESETVAL                           (0x000003ffU)

/* AEOIR */

#define CSL_ARMGICCPUIF_AEOIR_EOIINTID_MASK                     (0x000003FFU)
#define CSL_ARMGICCPUIF_AEOIR_EOIINTID_SHIFT                    (0U)
#define CSL_ARMGICCPUIF_AEOIR_EOIINTID_RESETVAL                 (0x00000000U)
#define CSL_ARMGICCPUIF_AEOIR_EOIINTID_MAX                      (0x000003ffU)

#define CSL_ARMGICCPUIF_AEOIR_CPUID_MASK                        (0x00001C00U)
#define CSL_ARMGICCPUIF_AEOIR_CPUID_SHIFT                       (10U)
#define CSL_ARMGICCPUIF_AEOIR_CPUID_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_AEOIR_CPUID_MAX                         (0x00000007U)

#define CSL_ARMGICCPUIF_AEOIR_RESETVAL                          (0x00000000U)

/* AHPPIR */

#define CSL_ARMGICCPUIF_AHPPIR_CPUID_MASK                       (0x00001C00U)
#define CSL_ARMGICCPUIF_AHPPIR_CPUID_SHIFT                      (10U)
#define CSL_ARMGICCPUIF_AHPPIR_CPUID_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIF_AHPPIR_CPUID_MAX                        (0x00000007U)

#define CSL_ARMGICCPUIF_AHPPIR_PENDINTID_MASK                   (0x000003FFU)
#define CSL_ARMGICCPUIF_AHPPIR_PENDINTID_SHIFT                  (0U)
#define CSL_ARMGICCPUIF_AHPPIR_PENDINTID_RESETVAL               (0x000003ffU)
#define CSL_ARMGICCPUIF_AHPPIR_PENDINTID_MAX                    (0x000003ffU)

#define CSL_ARMGICCPUIF_AHPPIR_RESETVAL                         (0x000003ffU)

/* APR0 */

#define CSL_ARMGICCPUIF_APR0_AP0_MASK                           (0x00000001U)
#define CSL_ARMGICCPUIF_APR0_AP0_SHIFT                          (0U)
#define CSL_ARMGICCPUIF_APR0_AP0_RESETVAL                       (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP0_MAX                            (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP1_MASK                           (0x00000002U)
#define CSL_ARMGICCPUIF_APR0_AP1_SHIFT                          (1U)
#define CSL_ARMGICCPUIF_APR0_AP1_RESETVAL                       (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP1_MAX                            (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP2_MASK                           (0x00000004U)
#define CSL_ARMGICCPUIF_APR0_AP2_SHIFT                          (2U)
#define CSL_ARMGICCPUIF_APR0_AP2_RESETVAL                       (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP2_MAX                            (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP3_MASK                           (0x00000008U)
#define CSL_ARMGICCPUIF_APR0_AP3_SHIFT                          (3U)
#define CSL_ARMGICCPUIF_APR0_AP3_RESETVAL                       (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP3_MAX                            (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP4_MASK                           (0x00000010U)
#define CSL_ARMGICCPUIF_APR0_AP4_SHIFT                          (4U)
#define CSL_ARMGICCPUIF_APR0_AP4_RESETVAL                       (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP4_MAX                            (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP5_MASK                           (0x00000020U)
#define CSL_ARMGICCPUIF_APR0_AP5_SHIFT                          (5U)
#define CSL_ARMGICCPUIF_APR0_AP5_RESETVAL                       (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP5_MAX                            (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP6_MASK                           (0x00000040U)
#define CSL_ARMGICCPUIF_APR0_AP6_SHIFT                          (6U)
#define CSL_ARMGICCPUIF_APR0_AP6_RESETVAL                       (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP6_MAX                            (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP7_MASK                           (0x00000080U)
#define CSL_ARMGICCPUIF_APR0_AP7_SHIFT                          (7U)
#define CSL_ARMGICCPUIF_APR0_AP7_RESETVAL                       (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP7_MAX                            (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP8_MASK                           (0x00000100U)
#define CSL_ARMGICCPUIF_APR0_AP8_SHIFT                          (8U)
#define CSL_ARMGICCPUIF_APR0_AP8_RESETVAL                       (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP8_MAX                            (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP9_MASK                           (0x00000200U)
#define CSL_ARMGICCPUIF_APR0_AP9_SHIFT                          (9U)
#define CSL_ARMGICCPUIF_APR0_AP9_RESETVAL                       (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP9_MAX                            (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP10_MASK                          (0x00000400U)
#define CSL_ARMGICCPUIF_APR0_AP10_SHIFT                         (10U)
#define CSL_ARMGICCPUIF_APR0_AP10_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP10_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP11_MASK                          (0x00000800U)
#define CSL_ARMGICCPUIF_APR0_AP11_SHIFT                         (11U)
#define CSL_ARMGICCPUIF_APR0_AP11_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP11_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP12_MASK                          (0x00001000U)
#define CSL_ARMGICCPUIF_APR0_AP12_SHIFT                         (12U)
#define CSL_ARMGICCPUIF_APR0_AP12_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP12_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP13_MASK                          (0x00002000U)
#define CSL_ARMGICCPUIF_APR0_AP13_SHIFT                         (13U)
#define CSL_ARMGICCPUIF_APR0_AP13_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP13_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP14_MASK                          (0x00004000U)
#define CSL_ARMGICCPUIF_APR0_AP14_SHIFT                         (14U)
#define CSL_ARMGICCPUIF_APR0_AP14_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP14_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP15_MASK                          (0x00008000U)
#define CSL_ARMGICCPUIF_APR0_AP15_SHIFT                         (15U)
#define CSL_ARMGICCPUIF_APR0_AP15_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP15_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP16_MASK                          (0x00010000U)
#define CSL_ARMGICCPUIF_APR0_AP16_SHIFT                         (16U)
#define CSL_ARMGICCPUIF_APR0_AP16_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP16_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP17_MASK                          (0x00020000U)
#define CSL_ARMGICCPUIF_APR0_AP17_SHIFT                         (17U)
#define CSL_ARMGICCPUIF_APR0_AP17_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP17_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP18_MASK                          (0x00040000U)
#define CSL_ARMGICCPUIF_APR0_AP18_SHIFT                         (18U)
#define CSL_ARMGICCPUIF_APR0_AP18_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP18_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP19_MASK                          (0x00080000U)
#define CSL_ARMGICCPUIF_APR0_AP19_SHIFT                         (19U)
#define CSL_ARMGICCPUIF_APR0_AP19_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP19_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP20_MASK                          (0x00100000U)
#define CSL_ARMGICCPUIF_APR0_AP20_SHIFT                         (20U)
#define CSL_ARMGICCPUIF_APR0_AP20_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP20_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP21_MASK                          (0x00200000U)
#define CSL_ARMGICCPUIF_APR0_AP21_SHIFT                         (21U)
#define CSL_ARMGICCPUIF_APR0_AP21_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP21_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP22_MASK                          (0x00400000U)
#define CSL_ARMGICCPUIF_APR0_AP22_SHIFT                         (22U)
#define CSL_ARMGICCPUIF_APR0_AP22_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP22_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP23_MASK                          (0x00800000U)
#define CSL_ARMGICCPUIF_APR0_AP23_SHIFT                         (23U)
#define CSL_ARMGICCPUIF_APR0_AP23_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP23_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP24_MASK                          (0x01000000U)
#define CSL_ARMGICCPUIF_APR0_AP24_SHIFT                         (24U)
#define CSL_ARMGICCPUIF_APR0_AP24_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP24_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP25_MASK                          (0x02000000U)
#define CSL_ARMGICCPUIF_APR0_AP25_SHIFT                         (25U)
#define CSL_ARMGICCPUIF_APR0_AP25_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP25_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP26_MASK                          (0x04000000U)
#define CSL_ARMGICCPUIF_APR0_AP26_SHIFT                         (26U)
#define CSL_ARMGICCPUIF_APR0_AP26_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP26_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP27_MASK                          (0x08000000U)
#define CSL_ARMGICCPUIF_APR0_AP27_SHIFT                         (27U)
#define CSL_ARMGICCPUIF_APR0_AP27_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP27_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP28_MASK                          (0x10000000U)
#define CSL_ARMGICCPUIF_APR0_AP28_SHIFT                         (28U)
#define CSL_ARMGICCPUIF_APR0_AP28_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP28_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP29_MASK                          (0x20000000U)
#define CSL_ARMGICCPUIF_APR0_AP29_SHIFT                         (29U)
#define CSL_ARMGICCPUIF_APR0_AP29_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP29_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP30_MASK                          (0x40000000U)
#define CSL_ARMGICCPUIF_APR0_AP30_SHIFT                         (30U)
#define CSL_ARMGICCPUIF_APR0_AP30_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP30_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_AP31_MASK                          (0x80000000U)
#define CSL_ARMGICCPUIF_APR0_AP31_SHIFT                         (31U)
#define CSL_ARMGICCPUIF_APR0_AP31_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_APR0_AP31_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIF_APR0_RESETVAL                           (0x00000000U)

/* NSAPR0 */

#define CSL_ARMGICCPUIF_NSAPR0_AP0_MASK                         (0x00000001U)
#define CSL_ARMGICCPUIF_NSAPR0_AP0_SHIFT                        (0U)
#define CSL_ARMGICCPUIF_NSAPR0_AP0_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP0_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP1_MASK                         (0x00000002U)
#define CSL_ARMGICCPUIF_NSAPR0_AP1_SHIFT                        (1U)
#define CSL_ARMGICCPUIF_NSAPR0_AP1_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP1_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP2_MASK                         (0x00000004U)
#define CSL_ARMGICCPUIF_NSAPR0_AP2_SHIFT                        (2U)
#define CSL_ARMGICCPUIF_NSAPR0_AP2_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP2_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP3_MASK                         (0x00000008U)
#define CSL_ARMGICCPUIF_NSAPR0_AP3_SHIFT                        (3U)
#define CSL_ARMGICCPUIF_NSAPR0_AP3_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP3_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP4_MASK                         (0x00000010U)
#define CSL_ARMGICCPUIF_NSAPR0_AP4_SHIFT                        (4U)
#define CSL_ARMGICCPUIF_NSAPR0_AP4_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP4_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP5_MASK                         (0x00000020U)
#define CSL_ARMGICCPUIF_NSAPR0_AP5_SHIFT                        (5U)
#define CSL_ARMGICCPUIF_NSAPR0_AP5_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP5_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP6_MASK                         (0x00000040U)
#define CSL_ARMGICCPUIF_NSAPR0_AP6_SHIFT                        (6U)
#define CSL_ARMGICCPUIF_NSAPR0_AP6_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP6_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP7_MASK                         (0x00000080U)
#define CSL_ARMGICCPUIF_NSAPR0_AP7_SHIFT                        (7U)
#define CSL_ARMGICCPUIF_NSAPR0_AP7_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP7_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP8_MASK                         (0x00000100U)
#define CSL_ARMGICCPUIF_NSAPR0_AP8_SHIFT                        (8U)
#define CSL_ARMGICCPUIF_NSAPR0_AP8_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP8_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP9_MASK                         (0x00000200U)
#define CSL_ARMGICCPUIF_NSAPR0_AP9_SHIFT                        (9U)
#define CSL_ARMGICCPUIF_NSAPR0_AP9_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP9_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP10_MASK                        (0x00000400U)
#define CSL_ARMGICCPUIF_NSAPR0_AP10_SHIFT                       (10U)
#define CSL_ARMGICCPUIF_NSAPR0_AP10_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP10_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP11_MASK                        (0x00000800U)
#define CSL_ARMGICCPUIF_NSAPR0_AP11_SHIFT                       (11U)
#define CSL_ARMGICCPUIF_NSAPR0_AP11_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP11_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP12_MASK                        (0x00001000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP12_SHIFT                       (12U)
#define CSL_ARMGICCPUIF_NSAPR0_AP12_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP12_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP13_MASK                        (0x00002000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP13_SHIFT                       (13U)
#define CSL_ARMGICCPUIF_NSAPR0_AP13_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP13_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP14_MASK                        (0x00004000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP14_SHIFT                       (14U)
#define CSL_ARMGICCPUIF_NSAPR0_AP14_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP14_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP15_MASK                        (0x00008000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP15_SHIFT                       (15U)
#define CSL_ARMGICCPUIF_NSAPR0_AP15_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP15_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP16_MASK                        (0x00010000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP16_SHIFT                       (16U)
#define CSL_ARMGICCPUIF_NSAPR0_AP16_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP16_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP17_MASK                        (0x00020000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP17_SHIFT                       (17U)
#define CSL_ARMGICCPUIF_NSAPR0_AP17_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP17_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP18_MASK                        (0x00040000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP18_SHIFT                       (18U)
#define CSL_ARMGICCPUIF_NSAPR0_AP18_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP18_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP19_MASK                        (0x00080000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP19_SHIFT                       (19U)
#define CSL_ARMGICCPUIF_NSAPR0_AP19_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP19_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP20_MASK                        (0x00100000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP20_SHIFT                       (20U)
#define CSL_ARMGICCPUIF_NSAPR0_AP20_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP20_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP21_MASK                        (0x00200000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP21_SHIFT                       (21U)
#define CSL_ARMGICCPUIF_NSAPR0_AP21_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP21_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP22_MASK                        (0x00400000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP22_SHIFT                       (22U)
#define CSL_ARMGICCPUIF_NSAPR0_AP22_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP22_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP23_MASK                        (0x00800000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP23_SHIFT                       (23U)
#define CSL_ARMGICCPUIF_NSAPR0_AP23_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP23_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP24_MASK                        (0x01000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP24_SHIFT                       (24U)
#define CSL_ARMGICCPUIF_NSAPR0_AP24_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP24_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP25_MASK                        (0x02000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP25_SHIFT                       (25U)
#define CSL_ARMGICCPUIF_NSAPR0_AP25_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP25_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP26_MASK                        (0x04000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP26_SHIFT                       (26U)
#define CSL_ARMGICCPUIF_NSAPR0_AP26_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP26_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP27_MASK                        (0x08000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP27_SHIFT                       (27U)
#define CSL_ARMGICCPUIF_NSAPR0_AP27_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP27_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP28_MASK                        (0x10000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP28_SHIFT                       (28U)
#define CSL_ARMGICCPUIF_NSAPR0_AP28_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP28_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP29_MASK                        (0x20000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP29_SHIFT                       (29U)
#define CSL_ARMGICCPUIF_NSAPR0_AP29_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP29_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP30_MASK                        (0x40000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP30_SHIFT                       (30U)
#define CSL_ARMGICCPUIF_NSAPR0_AP30_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP30_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_AP31_MASK                        (0x80000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP31_SHIFT                       (31U)
#define CSL_ARMGICCPUIF_NSAPR0_AP31_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIF_NSAPR0_AP31_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIF_NSAPR0_RESETVAL                         (0x00000000U)

/* IIDR */

#define CSL_ARMGICCPUIF_IIDR_PRODUCTID_MASK                     (0xFFF00000U)
#define CSL_ARMGICCPUIF_IIDR_PRODUCTID_SHIFT                    (20U)
#define CSL_ARMGICCPUIF_IIDR_PRODUCTID_RESETVAL                 (0x00000000U)
#define CSL_ARMGICCPUIF_IIDR_PRODUCTID_MAX                      (0x00000fffU)

#define CSL_ARMGICCPUIF_IIDR_ARCHITECTUREVERSION_MASK           (0x000F0000U)
#define CSL_ARMGICCPUIF_IIDR_ARCHITECTUREVERSION_SHIFT          (16U)
#define CSL_ARMGICCPUIF_IIDR_ARCHITECTUREVERSION_RESETVAL       (0x00000002U)
#define CSL_ARMGICCPUIF_IIDR_ARCHITECTUREVERSION_MAX            (0x0000000fU)

#define CSL_ARMGICCPUIF_IIDR_REVISION_MASK                      (0x0000F000U)
#define CSL_ARMGICCPUIF_IIDR_REVISION_SHIFT                     (12U)
#define CSL_ARMGICCPUIF_IIDR_REVISION_RESETVAL                  (0x00000000U)
#define CSL_ARMGICCPUIF_IIDR_REVISION_MAX                       (0x0000000fU)

#define CSL_ARMGICCPUIF_IIDR_IMPLEMENTER_MASK                   (0x00000FFFU)
#define CSL_ARMGICCPUIF_IIDR_IMPLEMENTER_SHIFT                  (0U)
#define CSL_ARMGICCPUIF_IIDR_IMPLEMENTER_RESETVAL               (0x0000043bU)
#define CSL_ARMGICCPUIF_IIDR_IMPLEMENTER_MAX                    (0x00000fffU)

#define CSL_ARMGICCPUIF_IIDR_RESETVAL                           (0x0002043bU)

/* DIR */

#define CSL_ARMGICCPUIF_DIR_INTRID_MASK                         (0x000003FFU)
#define CSL_ARMGICCPUIF_DIR_INTRID_SHIFT                        (0U)
#define CSL_ARMGICCPUIF_DIR_INTRID_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIF_DIR_INTRID_MAX                          (0x000003ffU)

#define CSL_ARMGICCPUIF_DIR_CPUID_MASK                          (0x00001C00U)
#define CSL_ARMGICCPUIF_DIR_CPUID_SHIFT                         (10U)
#define CSL_ARMGICCPUIF_DIR_CPUID_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIF_DIR_CPUID_MAX                           (0x00000007U)

#define CSL_ARMGICCPUIF_DIR_RESETVAL                            (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
