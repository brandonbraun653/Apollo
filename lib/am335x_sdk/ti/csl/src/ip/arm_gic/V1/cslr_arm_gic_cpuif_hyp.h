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
#ifndef CSLR_ARMGICCPUIFHYP_H_
#define CSLR_ARMGICCPUIFHYP_H_

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
    volatile Uint32 HCR;
    volatile Uint32 VTR;
    volatile Uint32 VMCR;
    volatile Uint8  RSVD0[4];
    volatile Uint32 MISR;
    volatile Uint8  RSVD1[12];
    volatile Uint32 EISR0;
    volatile Uint8  RSVD2[12];
    volatile Uint32 ELSR0;
    volatile Uint8  RSVD3[188];
    volatile Uint32 APR0;
    volatile Uint8  RSVD4[12];
    volatile Uint32 LR0;
    volatile Uint32 LR1;
    volatile Uint32 LR2;
    volatile Uint32 LR3;
} CSL_ArmGicCpuifHypRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Hypervisor Control Register */
#define CSL_ARMGICCPUIFHYP_HCR                                  (0x0U)

/* VGIC Type Register */
#define CSL_ARMGICCPUIFHYP_VTR                                  (0x4U)

/* Virtual Machine Control Register */
#define CSL_ARMGICCPUIFHYP_VMCR                                 (0x8U)

/* Maintenance Interrupt Status Register */
#define CSL_ARMGICCPUIFHYP_MISR                                 (0x10U)

/* EOI Interrupt Status Register */
#define CSL_ARMGICCPUIFHYP_EISR0                                (0x20U)

/* Empty List Register Status Register */
#define CSL_ARMGICCPUIFHYP_ELSR0                                (0x30U)

/* Active Priorities Register */
#define CSL_ARMGICCPUIFHYP_APR0                                 (0xF0U)

/* List Register 0 */
#define CSL_ARMGICCPUIFHYP_LR0                                  (0x100U)

/* List Register 1 */
#define CSL_ARMGICCPUIFHYP_LR1                                  (0x104U)

/* List Register 2 */
#define CSL_ARMGICCPUIFHYP_LR2                                  (0x108U)

/* List Register 3 */
#define CSL_ARMGICCPUIFHYP_LR3                                  (0x10CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* HCR */

#define CSL_ARMGICCPUIFHYP_HCR_EOICOUNT_MASK                    (0xF8000000U)
#define CSL_ARMGICCPUIFHYP_HCR_EOICOUNT_SHIFT                   (27U)
#define CSL_ARMGICCPUIFHYP_HCR_EOICOUNT_RESETVAL                (0x00000000U)
#define CSL_ARMGICCPUIFHYP_HCR_EOICOUNT_MAX                     (0x0000001fU)

#define CSL_ARMGICCPUIFHYP_HCR_VDNSIE_MASK                      (0x00000080U)
#define CSL_ARMGICCPUIFHYP_HCR_VDNSIE_SHIFT                     (7U)
#define CSL_ARMGICCPUIFHYP_HCR_VDNSIE_RESETVAL                  (0x00000000U)
#define CSL_ARMGICCPUIFHYP_HCR_VDNSIE_MAX                       (0x00000001U)

#define CSL_ARMGICCPUIFHYP_HCR_VENSIE_MASK                      (0x00000040U)
#define CSL_ARMGICCPUIFHYP_HCR_VENSIE_SHIFT                     (6U)
#define CSL_ARMGICCPUIFHYP_HCR_VENSIE_RESETVAL                  (0x00000000U)
#define CSL_ARMGICCPUIFHYP_HCR_VENSIE_MAX                       (0x00000001U)

#define CSL_ARMGICCPUIFHYP_HCR_VDSIE_MASK                       (0x00000020U)
#define CSL_ARMGICCPUIFHYP_HCR_VDSIE_SHIFT                      (5U)
#define CSL_ARMGICCPUIFHYP_HCR_VDSIE_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_HCR_VDSIE_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_HCR_VESIE_MASK                       (0x00000010U)
#define CSL_ARMGICCPUIFHYP_HCR_VESIE_SHIFT                      (4U)
#define CSL_ARMGICCPUIFHYP_HCR_VESIE_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_HCR_VESIE_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_HCR_NPIE_MASK                        (0x00000008U)
#define CSL_ARMGICCPUIFHYP_HCR_NPIE_SHIFT                       (3U)
#define CSL_ARMGICCPUIFHYP_HCR_NPIE_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_HCR_NPIE_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_HCR_SKIDIE_MASK                      (0x00000004U)
#define CSL_ARMGICCPUIFHYP_HCR_SKIDIE_SHIFT                     (2U)
#define CSL_ARMGICCPUIFHYP_HCR_SKIDIE_RESETVAL                  (0x00000000U)
#define CSL_ARMGICCPUIFHYP_HCR_SKIDIE_MAX                       (0x00000001U)

#define CSL_ARMGICCPUIFHYP_HCR_UIE_MASK                         (0x00000002U)
#define CSL_ARMGICCPUIFHYP_HCR_UIE_SHIFT                        (1U)
#define CSL_ARMGICCPUIFHYP_HCR_UIE_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIFHYP_HCR_UIE_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIFHYP_HCR_EN_MASK                          (0x00000001U)
#define CSL_ARMGICCPUIFHYP_HCR_EN_SHIFT                         (0U)
#define CSL_ARMGICCPUIFHYP_HCR_EN_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIFHYP_HCR_EN_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIFHYP_HCR_RESETVAL                         (0x00000000U)

/* VTR */

#define CSL_ARMGICCPUIFHYP_VTR_LISTREGS_MASK                    (0x0000003FU)
#define CSL_ARMGICCPUIFHYP_VTR_LISTREGS_SHIFT                   (0U)
#define CSL_ARMGICCPUIFHYP_VTR_LISTREGS_RESETVAL                (0x00000003U)
#define CSL_ARMGICCPUIFHYP_VTR_LISTREGS_MAX                     (0x0000003fU)

#define CSL_ARMGICCPUIFHYP_VTR_PREBITS_MASK                     (0x1C000000U)
#define CSL_ARMGICCPUIFHYP_VTR_PREBITS_SHIFT                    (26U)
#define CSL_ARMGICCPUIFHYP_VTR_PREBITS_RESETVAL                 (0x00000004U)
#define CSL_ARMGICCPUIFHYP_VTR_PREBITS_MAX                      (0x00000007U)

#define CSL_ARMGICCPUIFHYP_VTR_PRIBITS_MASK                     (0xE0000000U)
#define CSL_ARMGICCPUIFHYP_VTR_PRIBITS_SHIFT                    (29U)
#define CSL_ARMGICCPUIFHYP_VTR_PRIBITS_RESETVAL                 (0x00000004U)
#define CSL_ARMGICCPUIFHYP_VTR_PRIBITS_MAX                      (0x00000007U)

#define CSL_ARMGICCPUIFHYP_VTR_RESETVAL                         (0x90000003U)

/* VMCR */

#define CSL_ARMGICCPUIFHYP_VMCR_VMSEN_MASK                      (0x00000001U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMSEN_SHIFT                     (0U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMSEN_RESETVAL                  (0x00000000U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMSEN_MAX                       (0x00000001U)

#define CSL_ARMGICCPUIFHYP_VMCR_VMNSEN_MASK                     (0x00000002U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMNSEN_SHIFT                    (1U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMNSEN_RESETVAL                 (0x00000000U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMNSEN_MAX                      (0x00000001U)

#define CSL_ARMGICCPUIFHYP_VMCR_VMACKCTL_MASK                   (0x00000004U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMACKCTL_SHIFT                  (2U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMACKCTL_RESETVAL               (0x00000000U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMACKCTL_MAX                    (0x00000001U)

#define CSL_ARMGICCPUIFHYP_VMCR_VMFIQEN_MASK                    (0x00000008U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMFIQEN_SHIFT                   (3U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMFIQEN_RESETVAL                (0x00000000U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMFIQEN_MAX                     (0x00000001U)

#define CSL_ARMGICCPUIFHYP_VMCR_VMSBPR_MASK                     (0x00000010U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMSBPR_SHIFT                    (4U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMSBPR_RESETVAL                 (0x00000000U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMSBPR_MAX                      (0x00000001U)

#define CSL_ARMGICCPUIFHYP_VMCR_VEM_MASK                        (0x00000200U)
#define CSL_ARMGICCPUIFHYP_VMCR_VEM_SHIFT                       (9U)
#define CSL_ARMGICCPUIFHYP_VMCR_VEM_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_VMCR_VEM_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_VMCR_VMNSBP_MASK                     (0x001C0000U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMNSBP_SHIFT                    (18U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMNSBP_RESETVAL                 (0x00000003U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMNSBP_MAX                      (0x00000007U)

#define CSL_ARMGICCPUIFHYP_VMCR_VMBP_MASK                       (0x00E00000U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMBP_SHIFT                      (21U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMBP_RESETVAL                   (0x00000002U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMBP_MAX                        (0x00000007U)

#define CSL_ARMGICCPUIFHYP_VMCR_VMPRIMASK_MASK                  (0xF8000000U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMPRIMASK_SHIFT                 (27U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMPRIMASK_RESETVAL              (0x00000000U)
#define CSL_ARMGICCPUIFHYP_VMCR_VMPRIMASK_MAX                   (0x0000001fU)

#define CSL_ARMGICCPUIFHYP_VMCR_RESETVAL                        (0x004c0000U)

/* MISR */

#define CSL_ARMGICCPUIFHYP_MISR_EI_MASK                         (0x00000001U)
#define CSL_ARMGICCPUIFHYP_MISR_EI_SHIFT                        (0U)
#define CSL_ARMGICCPUIFHYP_MISR_EI_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIFHYP_MISR_EI_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIFHYP_MISR_UI_MASK                         (0x00000002U)
#define CSL_ARMGICCPUIFHYP_MISR_UI_SHIFT                        (1U)
#define CSL_ARMGICCPUIFHYP_MISR_UI_RESETVAL                     (0x00000000U)
#define CSL_ARMGICCPUIFHYP_MISR_UI_MAX                          (0x00000001U)

#define CSL_ARMGICCPUIFHYP_MISR_SKDI_MASK                       (0x00000004U)
#define CSL_ARMGICCPUIFHYP_MISR_SKDI_SHIFT                      (2U)
#define CSL_ARMGICCPUIFHYP_MISR_SKDI_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_MISR_SKDI_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_MISR_NPI_MASK                        (0x00000008U)
#define CSL_ARMGICCPUIFHYP_MISR_NPI_SHIFT                       (3U)
#define CSL_ARMGICCPUIFHYP_MISR_NPI_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_MISR_NPI_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_MISR_VESI_MASK                       (0x00000010U)
#define CSL_ARMGICCPUIFHYP_MISR_VESI_SHIFT                      (4U)
#define CSL_ARMGICCPUIFHYP_MISR_VESI_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_MISR_VESI_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_MISR_VDSI_MASK                       (0x00000020U)
#define CSL_ARMGICCPUIFHYP_MISR_VDSI_SHIFT                      (5U)
#define CSL_ARMGICCPUIFHYP_MISR_VDSI_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_MISR_VDSI_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_MISR_VENSI_MASK                      (0x00000040U)
#define CSL_ARMGICCPUIFHYP_MISR_VENSI_SHIFT                     (6U)
#define CSL_ARMGICCPUIFHYP_MISR_VENSI_RESETVAL                  (0x00000000U)
#define CSL_ARMGICCPUIFHYP_MISR_VENSI_MAX                       (0x00000001U)

#define CSL_ARMGICCPUIFHYP_MISR_VDNSI_MASK                      (0x00000080U)
#define CSL_ARMGICCPUIFHYP_MISR_VDNSI_SHIFT                     (7U)
#define CSL_ARMGICCPUIFHYP_MISR_VDNSI_RESETVAL                  (0x00000000U)
#define CSL_ARMGICCPUIFHYP_MISR_VDNSI_MAX                       (0x00000001U)

#define CSL_ARMGICCPUIFHYP_MISR_RESETVAL                        (0x00000000U)

/* EISR0 */

#define CSL_ARMGICCPUIFHYP_EISR0_LR0_MASK                       (0x00000001U)
#define CSL_ARMGICCPUIFHYP_EISR0_LR0_SHIFT                      (0U)
#define CSL_ARMGICCPUIFHYP_EISR0_LR0_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_EISR0_LR0_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_EISR0_LR1_MASK                       (0x00000002U)
#define CSL_ARMGICCPUIFHYP_EISR0_LR1_SHIFT                      (1U)
#define CSL_ARMGICCPUIFHYP_EISR0_LR1_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_EISR0_LR1_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_EISR0_LR2_MASK                       (0x00000004U)
#define CSL_ARMGICCPUIFHYP_EISR0_LR2_SHIFT                      (2U)
#define CSL_ARMGICCPUIFHYP_EISR0_LR2_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_EISR0_LR2_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_EISR0_LR3_MASK                       (0x00000008U)
#define CSL_ARMGICCPUIFHYP_EISR0_LR3_SHIFT                      (3U)
#define CSL_ARMGICCPUIFHYP_EISR0_LR3_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_EISR0_LR3_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_EISR0_RESETVAL                       (0x00000000U)

/* ELSR0 */

#define CSL_ARMGICCPUIFHYP_ELSR0_LR0_MASK                       (0x00000001U)
#define CSL_ARMGICCPUIFHYP_ELSR0_LR0_SHIFT                      (0U)
#define CSL_ARMGICCPUIFHYP_ELSR0_LR0_RESETVAL                   (0x00000001U)
#define CSL_ARMGICCPUIFHYP_ELSR0_LR0_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_ELSR0_LR1_MASK                       (0x00000002U)
#define CSL_ARMGICCPUIFHYP_ELSR0_LR1_SHIFT                      (1U)
#define CSL_ARMGICCPUIFHYP_ELSR0_LR1_RESETVAL                   (0x00000001U)
#define CSL_ARMGICCPUIFHYP_ELSR0_LR1_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_ELSR0_LR2_MASK                       (0x00000004U)
#define CSL_ARMGICCPUIFHYP_ELSR0_LR2_SHIFT                      (2U)
#define CSL_ARMGICCPUIFHYP_ELSR0_LR2_RESETVAL                   (0x00000001U)
#define CSL_ARMGICCPUIFHYP_ELSR0_LR2_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_ELSR0_LR3_MASK                       (0x00000008U)
#define CSL_ARMGICCPUIFHYP_ELSR0_LR3_SHIFT                      (3U)
#define CSL_ARMGICCPUIFHYP_ELSR0_LR3_RESETVAL                   (0x00000001U)
#define CSL_ARMGICCPUIFHYP_ELSR0_LR3_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_ELSR0_RESETVAL                       (0x0000000fU)

/* APR0 */

#define CSL_ARMGICCPUIFHYP_APR0_AP0_MASK                        (0x00000001U)
#define CSL_ARMGICCPUIFHYP_APR0_AP0_SHIFT                       (0U)
#define CSL_ARMGICCPUIFHYP_APR0_AP0_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP0_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP1_MASK                        (0x00000002U)
#define CSL_ARMGICCPUIFHYP_APR0_AP1_SHIFT                       (1U)
#define CSL_ARMGICCPUIFHYP_APR0_AP1_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP1_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP2_MASK                        (0x00000004U)
#define CSL_ARMGICCPUIFHYP_APR0_AP2_SHIFT                       (2U)
#define CSL_ARMGICCPUIFHYP_APR0_AP2_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP2_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP3_MASK                        (0x00000008U)
#define CSL_ARMGICCPUIFHYP_APR0_AP3_SHIFT                       (3U)
#define CSL_ARMGICCPUIFHYP_APR0_AP3_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP3_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP4_MASK                        (0x00000010U)
#define CSL_ARMGICCPUIFHYP_APR0_AP4_SHIFT                       (4U)
#define CSL_ARMGICCPUIFHYP_APR0_AP4_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP4_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP5_MASK                        (0x00000020U)
#define CSL_ARMGICCPUIFHYP_APR0_AP5_SHIFT                       (5U)
#define CSL_ARMGICCPUIFHYP_APR0_AP5_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP5_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP6_MASK                        (0x00000040U)
#define CSL_ARMGICCPUIFHYP_APR0_AP6_SHIFT                       (6U)
#define CSL_ARMGICCPUIFHYP_APR0_AP6_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP6_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP7_MASK                        (0x00000080U)
#define CSL_ARMGICCPUIFHYP_APR0_AP7_SHIFT                       (7U)
#define CSL_ARMGICCPUIFHYP_APR0_AP7_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP7_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP8_MASK                        (0x00000100U)
#define CSL_ARMGICCPUIFHYP_APR0_AP8_SHIFT                       (8U)
#define CSL_ARMGICCPUIFHYP_APR0_AP8_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP8_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP9_MASK                        (0x00000200U)
#define CSL_ARMGICCPUIFHYP_APR0_AP9_SHIFT                       (9U)
#define CSL_ARMGICCPUIFHYP_APR0_AP9_RESETVAL                    (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP9_MAX                         (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP10_MASK                       (0x00000400U)
#define CSL_ARMGICCPUIFHYP_APR0_AP10_SHIFT                      (10U)
#define CSL_ARMGICCPUIFHYP_APR0_AP10_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP10_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP11_MASK                       (0x00000800U)
#define CSL_ARMGICCPUIFHYP_APR0_AP11_SHIFT                      (11U)
#define CSL_ARMGICCPUIFHYP_APR0_AP11_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP11_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP12_MASK                       (0x00001000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP12_SHIFT                      (12U)
#define CSL_ARMGICCPUIFHYP_APR0_AP12_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP12_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP13_MASK                       (0x00002000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP13_SHIFT                      (13U)
#define CSL_ARMGICCPUIFHYP_APR0_AP13_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP13_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP14_MASK                       (0x00004000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP14_SHIFT                      (14U)
#define CSL_ARMGICCPUIFHYP_APR0_AP14_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP14_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP15_MASK                       (0x00008000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP15_SHIFT                      (15U)
#define CSL_ARMGICCPUIFHYP_APR0_AP15_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP15_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP16_MASK                       (0x00010000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP16_SHIFT                      (16U)
#define CSL_ARMGICCPUIFHYP_APR0_AP16_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP16_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP17_MASK                       (0x00020000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP17_SHIFT                      (17U)
#define CSL_ARMGICCPUIFHYP_APR0_AP17_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP17_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP18_MASK                       (0x00040000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP18_SHIFT                      (18U)
#define CSL_ARMGICCPUIFHYP_APR0_AP18_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP18_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP19_MASK                       (0x00080000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP19_SHIFT                      (19U)
#define CSL_ARMGICCPUIFHYP_APR0_AP19_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP19_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP20_MASK                       (0x00100000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP20_SHIFT                      (20U)
#define CSL_ARMGICCPUIFHYP_APR0_AP20_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP20_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP21_MASK                       (0x00200000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP21_SHIFT                      (21U)
#define CSL_ARMGICCPUIFHYP_APR0_AP21_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP21_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP22_MASK                       (0x00400000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP22_SHIFT                      (22U)
#define CSL_ARMGICCPUIFHYP_APR0_AP22_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP22_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP23_MASK                       (0x00800000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP23_SHIFT                      (23U)
#define CSL_ARMGICCPUIFHYP_APR0_AP23_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP23_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP24_MASK                       (0x01000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP24_SHIFT                      (24U)
#define CSL_ARMGICCPUIFHYP_APR0_AP24_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP24_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP25_MASK                       (0x02000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP25_SHIFT                      (25U)
#define CSL_ARMGICCPUIFHYP_APR0_AP25_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP25_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP26_MASK                       (0x04000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP26_SHIFT                      (26U)
#define CSL_ARMGICCPUIFHYP_APR0_AP26_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP26_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP27_MASK                       (0x08000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP27_SHIFT                      (27U)
#define CSL_ARMGICCPUIFHYP_APR0_AP27_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP27_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP28_MASK                       (0x10000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP28_SHIFT                      (28U)
#define CSL_ARMGICCPUIFHYP_APR0_AP28_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP28_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP29_MASK                       (0x20000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP29_SHIFT                      (29U)
#define CSL_ARMGICCPUIFHYP_APR0_AP29_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP29_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP30_MASK                       (0x40000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP30_SHIFT                      (30U)
#define CSL_ARMGICCPUIFHYP_APR0_AP30_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP30_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_AP31_MASK                       (0x80000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP31_SHIFT                      (31U)
#define CSL_ARMGICCPUIFHYP_APR0_AP31_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_APR0_AP31_MAX                        (0x00000001U)

#define CSL_ARMGICCPUIFHYP_APR0_RESETVAL                        (0x00000000U)

/* LR0 */

#define CSL_ARMGICCPUIFHYP_LR0_HW_MASK                          (0x80000000U)
#define CSL_ARMGICCPUIFHYP_LR0_HW_SHIFT                         (31U)
#define CSL_ARMGICCPUIFHYP_LR0_HW_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR0_HW_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIFHYP_LR0_NS_MASK                          (0x40000000U)
#define CSL_ARMGICCPUIFHYP_LR0_NS_SHIFT                         (30U)
#define CSL_ARMGICCPUIFHYP_LR0_NS_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR0_NS_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIFHYP_LR0_STATE_MASK                       (0x30000000U)
#define CSL_ARMGICCPUIFHYP_LR0_STATE_SHIFT                      (28U)
#define CSL_ARMGICCPUIFHYP_LR0_STATE_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR0_STATE_MAX                        (0x00000003U)

#define CSL_ARMGICCPUIFHYP_LR0_PRIORITY_MASK                    (0x0F800000U)
#define CSL_ARMGICCPUIFHYP_LR0_PRIORITY_SHIFT                   (23U)
#define CSL_ARMGICCPUIFHYP_LR0_PRIORITY_RESETVAL                (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR0_PRIORITY_MAX                     (0x0000001fU)

#define CSL_ARMGICCPUIFHYP_LR0_PHYSICALID_MASK                  (0x000FFC00U)
#define CSL_ARMGICCPUIFHYP_LR0_PHYSICALID_SHIFT                 (10U)
#define CSL_ARMGICCPUIFHYP_LR0_PHYSICALID_RESETVAL              (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR0_PHYSICALID_MAX                   (0x000003ffU)

#define CSL_ARMGICCPUIFHYP_LR0_VIRTUALNUMBER_MASK               (0x000003FFU)
#define CSL_ARMGICCPUIFHYP_LR0_VIRTUALNUMBER_SHIFT              (0U)
#define CSL_ARMGICCPUIFHYP_LR0_VIRTUALNUMBER_RESETVAL           (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR0_VIRTUALNUMBER_MAX                (0x000003ffU)

#define CSL_ARMGICCPUIFHYP_LR0_RESETVAL                         (0x00000000U)

/* LR1 */

#define CSL_ARMGICCPUIFHYP_LR1_HW_MASK                          (0x80000000U)
#define CSL_ARMGICCPUIFHYP_LR1_HW_SHIFT                         (31U)
#define CSL_ARMGICCPUIFHYP_LR1_HW_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR1_HW_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIFHYP_LR1_NS_MASK                          (0x40000000U)
#define CSL_ARMGICCPUIFHYP_LR1_NS_SHIFT                         (30U)
#define CSL_ARMGICCPUIFHYP_LR1_NS_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR1_NS_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIFHYP_LR1_STATE_MASK                       (0x30000000U)
#define CSL_ARMGICCPUIFHYP_LR1_STATE_SHIFT                      (28U)
#define CSL_ARMGICCPUIFHYP_LR1_STATE_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR1_STATE_MAX                        (0x00000003U)

#define CSL_ARMGICCPUIFHYP_LR1_PRIORITY_MASK                    (0x0F800000U)
#define CSL_ARMGICCPUIFHYP_LR1_PRIORITY_SHIFT                   (23U)
#define CSL_ARMGICCPUIFHYP_LR1_PRIORITY_RESETVAL                (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR1_PRIORITY_MAX                     (0x0000001fU)

#define CSL_ARMGICCPUIFHYP_LR1_PHYSICALID_MASK                  (0x000FFC00U)
#define CSL_ARMGICCPUIFHYP_LR1_PHYSICALID_SHIFT                 (10U)
#define CSL_ARMGICCPUIFHYP_LR1_PHYSICALID_RESETVAL              (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR1_PHYSICALID_MAX                   (0x000003ffU)

#define CSL_ARMGICCPUIFHYP_LR1_VIRTUALNUMBER_MASK               (0x000003FFU)
#define CSL_ARMGICCPUIFHYP_LR1_VIRTUALNUMBER_SHIFT              (0U)
#define CSL_ARMGICCPUIFHYP_LR1_VIRTUALNUMBER_RESETVAL           (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR1_VIRTUALNUMBER_MAX                (0x000003ffU)

#define CSL_ARMGICCPUIFHYP_LR1_RESETVAL                         (0x00000000U)

/* LR2 */

#define CSL_ARMGICCPUIFHYP_LR2_HW_MASK                          (0x80000000U)
#define CSL_ARMGICCPUIFHYP_LR2_HW_SHIFT                         (31U)
#define CSL_ARMGICCPUIFHYP_LR2_HW_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR2_HW_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIFHYP_LR2_NS_MASK                          (0x40000000U)
#define CSL_ARMGICCPUIFHYP_LR2_NS_SHIFT                         (30U)
#define CSL_ARMGICCPUIFHYP_LR2_NS_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR2_NS_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIFHYP_LR2_STATE_MASK                       (0x30000000U)
#define CSL_ARMGICCPUIFHYP_LR2_STATE_SHIFT                      (28U)
#define CSL_ARMGICCPUIFHYP_LR2_STATE_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR2_STATE_MAX                        (0x00000003U)

#define CSL_ARMGICCPUIFHYP_LR2_PRIORITY_MASK                    (0x0F800000U)
#define CSL_ARMGICCPUIFHYP_LR2_PRIORITY_SHIFT                   (23U)
#define CSL_ARMGICCPUIFHYP_LR2_PRIORITY_RESETVAL                (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR2_PRIORITY_MAX                     (0x0000001fU)

#define CSL_ARMGICCPUIFHYP_LR2_PHYSICALID_MASK                  (0x000FFC00U)
#define CSL_ARMGICCPUIFHYP_LR2_PHYSICALID_SHIFT                 (10U)
#define CSL_ARMGICCPUIFHYP_LR2_PHYSICALID_RESETVAL              (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR2_PHYSICALID_MAX                   (0x000003ffU)

#define CSL_ARMGICCPUIFHYP_LR2_VIRTUALNUMBER_MASK               (0x000003FFU)
#define CSL_ARMGICCPUIFHYP_LR2_VIRTUALNUMBER_SHIFT              (0U)
#define CSL_ARMGICCPUIFHYP_LR2_VIRTUALNUMBER_RESETVAL           (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR2_VIRTUALNUMBER_MAX                (0x000003ffU)

#define CSL_ARMGICCPUIFHYP_LR2_RESETVAL                         (0x00000000U)

/* LR3 */

#define CSL_ARMGICCPUIFHYP_LR3_HW_MASK                          (0x80000000U)
#define CSL_ARMGICCPUIFHYP_LR3_HW_SHIFT                         (31U)
#define CSL_ARMGICCPUIFHYP_LR3_HW_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR3_HW_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIFHYP_LR3_NS_MASK                          (0x40000000U)
#define CSL_ARMGICCPUIFHYP_LR3_NS_SHIFT                         (30U)
#define CSL_ARMGICCPUIFHYP_LR3_NS_RESETVAL                      (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR3_NS_MAX                           (0x00000001U)

#define CSL_ARMGICCPUIFHYP_LR3_STATE_MASK                       (0x30000000U)
#define CSL_ARMGICCPUIFHYP_LR3_STATE_SHIFT                      (28U)
#define CSL_ARMGICCPUIFHYP_LR3_STATE_RESETVAL                   (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR3_STATE_MAX                        (0x00000003U)

#define CSL_ARMGICCPUIFHYP_LR3_PRIORITY_MASK                    (0x0F800000U)
#define CSL_ARMGICCPUIFHYP_LR3_PRIORITY_SHIFT                   (23U)
#define CSL_ARMGICCPUIFHYP_LR3_PRIORITY_RESETVAL                (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR3_PRIORITY_MAX                     (0x0000001fU)

#define CSL_ARMGICCPUIFHYP_LR3_PHYSICALID_MASK                  (0x000FFC00U)
#define CSL_ARMGICCPUIFHYP_LR3_PHYSICALID_SHIFT                 (10U)
#define CSL_ARMGICCPUIFHYP_LR3_PHYSICALID_RESETVAL              (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR3_PHYSICALID_MAX                   (0x000003ffU)

#define CSL_ARMGICCPUIFHYP_LR3_VIRTUALNUMBER_MASK               (0x000003FFU)
#define CSL_ARMGICCPUIFHYP_LR3_VIRTUALNUMBER_SHIFT              (0U)
#define CSL_ARMGICCPUIFHYP_LR3_VIRTUALNUMBER_RESETVAL           (0x00000000U)
#define CSL_ARMGICCPUIFHYP_LR3_VIRTUALNUMBER_MAX                (0x000003ffU)

#define CSL_ARMGICCPUIFHYP_LR3_RESETVAL                         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
