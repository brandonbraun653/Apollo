/********************************************************************
 * Copyright (C) 2016 Texas Instruments Incorporated.
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
 *  Name        : cslr_semaphore.h
*/
#ifndef CSLR_SEMAPHORE_H_
#define CSLR_SEMAPHORE_H_

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
    volatile uint32_t REVISION;                  /* Peripheral ID register */
    volatile uint32_t SCRATCH;                   /* Scratch register */
    volatile uint32_t RST_RUN;                   /* Software reset register */
    volatile uint32_t EOI;                       /* Re-arm interrupt lines after processing an existing interrupt */
    volatile uint8_t  Resv_256[240];
    volatile uint32_t SEM[64];                   /* Semaphore[a] status register */
    volatile uint32_t ISEM[64];                  /* Semaphore[a] indirect register */
    volatile uint32_t QSEM[64];                  /* Semaphore[a] query register */
    volatile uint32_t SEMFLAGL[16];              /* Set and Clear for master a, for semaphores 0 to 31 */
    volatile uint32_t SEMFLAGH[16];              /* Set and Clear for master a, for semaphores 32 to 63 */
    volatile uint32_t SEMFLAGL_SET[16];          /* Explicitly set semaphore flags 0 to 31 for master 'a' */
    volatile uint32_t SEMFLAGH_SET[16];          /* Explicitly set semaphore flags 32 to 63 for master 'a' */
    volatile uint32_t ERR;                       /* Semaphore Error Register */
    volatile uint32_t ERR_CLEAR;                 /* Semaphore Error Clear Register */
    volatile uint32_t ERR_SET;                   /* Semaphore Error Set Register */
} CSL_semaphoreRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_SEMAPHORE_REVISION                                                 (0x00000000U)
#define CSL_SEMAPHORE_SCRATCH                                                  (0x00000004U)
#define CSL_SEMAPHORE_RST_RUN                                                  (0x00000008U)
#define CSL_SEMAPHORE_EOI                                                      (0x0000000CU)
#define CSL_SEMAPHORE_SEM(SEM)                                                 (((SEM)*0x4U)+0x100U)
#define CSL_SEMAPHORE_ISEM(ISEM)                                               (((ISEM)*0x4U)+0x200U)
#define CSL_SEMAPHORE_QSEM(QSEM)                                               (((QSEM)*0x4U)+0x300U)
#define CSL_SEMAPHORE_SEMFLAGL(SEMFLAGL)                                       (((SEMFLAGL)*0x4U)+0x400U)
#define CSL_SEMAPHORE_SEMFLAGH(SEMFLAGH)                                       (((SEMFLAGH)*0x4U)+0x440U)
#define CSL_SEMAPHORE_SEMFLAGL_SET(SEMFLAGL_SET)                               (((SEMFLAGL_SET)*0x4U)+0x480U)
#define CSL_SEMAPHORE_SEMFLAGH_SET(SEMFLAGH_SET)                               (((SEMFLAGH_SET)*0x4U)+0x4C0U)
#define CSL_SEMAPHORE_ERR                                                      (0x00000500U)
#define CSL_SEMAPHORE_ERR_CLEAR                                                (0x00000504U)
#define CSL_SEMAPHORE_ERR_SET                                                  (0x00000508U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* REVISION */

#define CSL_SEMAPHORE_REVISION_SCHEME_MASK                                     (0xC0000000U)
#define CSL_SEMAPHORE_REVISION_SCHEME_SHIFT                                    (0x0000001EU)
#define CSL_SEMAPHORE_REVISION_SCHEME_RESETVAL                                 (0x00000001U)
#define CSL_SEMAPHORE_REVISION_SCHEME_MAX                                      (0x00000003U)

#define CSL_SEMAPHORE_REVISION_RSVD_MASK                                       (0x30000000U)
#define CSL_SEMAPHORE_REVISION_RSVD_SHIFT                                      (0x0000001CU)
#define CSL_SEMAPHORE_REVISION_RSVD_RESETVAL                                   (0x00000002U)
#define CSL_SEMAPHORE_REVISION_RSVD_MAX                                        (0x00000003U)

#define CSL_SEMAPHORE_REVISION_FUNCTION_MASK                                   (0x0FFF0000U)
#define CSL_SEMAPHORE_REVISION_FUNCTION_SHIFT                                  (0x00000010U)
#define CSL_SEMAPHORE_REVISION_FUNCTION_RESETVAL                               (0x000006FEU)
#define CSL_SEMAPHORE_REVISION_FUNCTION_MAX                                    (0x00000FFFU)

#define CSL_SEMAPHORE_REVISION_RTL_VER_MASK                                    (0x0000F800U)
#define CSL_SEMAPHORE_REVISION_RTL_VER_SHIFT                                   (0x0000000BU)
#define CSL_SEMAPHORE_REVISION_RTL_VER_RESETVAL                                (0x00000007U)
#define CSL_SEMAPHORE_REVISION_RTL_VER_MAX                                     (0x0000001FU)

#define CSL_SEMAPHORE_REVISION_MAJOR_REV_MASK                                  (0x00000700U)
#define CSL_SEMAPHORE_REVISION_MAJOR_REV_SHIFT                                 (0x00000008U)
#define CSL_SEMAPHORE_REVISION_MAJOR_REV_RESETVAL                              (0x00000002U)
#define CSL_SEMAPHORE_REVISION_MAJOR_REV_MAX                                   (0x00000007U)

#define CSL_SEMAPHORE_REVISION_CUSTOM_MASK                                     (0x000000C0U)
#define CSL_SEMAPHORE_REVISION_CUSTOM_SHIFT                                    (0x00000006U)
#define CSL_SEMAPHORE_REVISION_CUSTOM_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_REVISION_CUSTOM_MAX                                      (0x00000003U)

#define CSL_SEMAPHORE_REVISION_MINOR_REV_MASK                                  (0x0000003FU)
#define CSL_SEMAPHORE_REVISION_MINOR_REV_SHIFT                                 (0x00000000U)
#define CSL_SEMAPHORE_REVISION_MINOR_REV_RESETVAL                              (0x00000000U)
#define CSL_SEMAPHORE_REVISION_MINOR_REV_MAX                                   (0x0000003FU)

#define CSL_SEMAPHORE_REVISION_RESETVAL                                        (0x66FE3A00U)

/* SCRATCH */

#define CSL_SEMAPHORE_SCRATCH_SCRATCH_MASK                                     (0xFFFFFFFFU)
#define CSL_SEMAPHORE_SCRATCH_SCRATCH_SHIFT                                    (0x00000000U)
#define CSL_SEMAPHORE_SCRATCH_SCRATCH_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_SCRATCH_SCRATCH_MAX                                      (0xFFFFFFFFU)

#define CSL_SEMAPHORE_SCRATCH_RESETVAL                                         (0x00000000U)

/* RST_RUN */

#define CSL_SEMAPHORE_RST_RUN_RESET_MASK                                       (0x00000001U)
#define CSL_SEMAPHORE_RST_RUN_RESET_SHIFT                                      (0x00000000U)
#define CSL_SEMAPHORE_RST_RUN_RESET_RESETVAL                                   (0x00000000U)
#define CSL_SEMAPHORE_RST_RUN_RESET_MAX                                        (0x00000001U)

#define CSL_SEMAPHORE_RST_RUN_RESETVAL                                         (0x00000000U)

/* EOI */

#define CSL_SEMAPHORE_EOI_SEL_INTERRUPT_MASK                                   (0x000000FFU)
#define CSL_SEMAPHORE_EOI_SEL_INTERRUPT_SHIFT                                  (0x00000000U)
#define CSL_SEMAPHORE_EOI_SEL_INTERRUPT_RESETVAL                               (0x00000000U)
#define CSL_SEMAPHORE_EOI_SEL_INTERRUPT_MAX                                    (0x000000FFU)

#define CSL_SEMAPHORE_EOI_RESETVAL                                             (0x00000000U)

/* SEM */

#define CSL_SEMAPHORE_SEM_FREE_MASK                                            (0x00000001U)
#define CSL_SEMAPHORE_SEM_FREE_SHIFT                                           (0x00000000U)
#define CSL_SEMAPHORE_SEM_FREE_RESETVAL                                        (0x00000001U)
#define CSL_SEMAPHORE_SEM_FREE_MAX                                             (0x00000001U)

#define CSL_SEMAPHORE_SEM_OWNER_MASK                                           (0x0000FF00U)
#define CSL_SEMAPHORE_SEM_OWNER_SHIFT                                          (0x00000008U)
#define CSL_SEMAPHORE_SEM_OWNER_RESETVAL                                       (0x00000000U)
#define CSL_SEMAPHORE_SEM_OWNER_MAX                                            (0x000000FFU)

#define CSL_SEMAPHORE_SEM_RESETVAL                                             (0x00000001U)

/* ISEM */

#define CSL_SEMAPHORE_ISEM_FREE_MASK                                           (0x00000001U)
#define CSL_SEMAPHORE_ISEM_FREE_SHIFT                                          (0x00000000U)
#define CSL_SEMAPHORE_ISEM_FREE_RESETVAL                                       (0x00000001U)
#define CSL_SEMAPHORE_ISEM_FREE_MAX                                            (0x00000001U)

#define CSL_SEMAPHORE_ISEM_OWNER_MASK                                          (0x0000FF00U)
#define CSL_SEMAPHORE_ISEM_OWNER_SHIFT                                         (0x00000008U)
#define CSL_SEMAPHORE_ISEM_OWNER_RESETVAL                                      (0x00000000U)
#define CSL_SEMAPHORE_ISEM_OWNER_MAX                                           (0x000000FFU)

#define CSL_SEMAPHORE_ISEM_RESETVAL                                            (0x00000001U)

/* QSEM */

#define CSL_SEMAPHORE_QSEM_FREE_MASK                                           (0x00000001U)
#define CSL_SEMAPHORE_QSEM_FREE_SHIFT                                          (0x00000000U)
#define CSL_SEMAPHORE_QSEM_FREE_RESETVAL                                       (0x00000001U)
#define CSL_SEMAPHORE_QSEM_FREE_MAX                                            (0x00000001U)

#define CSL_SEMAPHORE_QSEM_OWNER_MASK                                          (0x0000FF00U)
#define CSL_SEMAPHORE_QSEM_OWNER_SHIFT                                         (0x00000008U)
#define CSL_SEMAPHORE_QSEM_OWNER_RESETVAL                                      (0x00000000U)
#define CSL_SEMAPHORE_QSEM_OWNER_MAX                                           (0x000000FFU)

#define CSL_SEMAPHORE_QSEM_RESETVAL                                            (0x00000001U)

/* SEMFLAGL */

#define CSL_SEMAPHORE_SEMFLAGL_F0_MASK                                         (0x00000001U)
#define CSL_SEMAPHORE_SEMFLAGL_F0_SHIFT                                        (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F0_RESETVAL                                     (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F0_MAX                                          (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F1_MASK                                         (0x00000002U)
#define CSL_SEMAPHORE_SEMFLAGL_F1_SHIFT                                        (0x00000001U)
#define CSL_SEMAPHORE_SEMFLAGL_F1_RESETVAL                                     (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F1_MAX                                          (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F2_MASK                                         (0x00000004U)
#define CSL_SEMAPHORE_SEMFLAGL_F2_SHIFT                                        (0x00000002U)
#define CSL_SEMAPHORE_SEMFLAGL_F2_RESETVAL                                     (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F2_MAX                                          (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F3_MASK                                         (0x00000008U)
#define CSL_SEMAPHORE_SEMFLAGL_F3_SHIFT                                        (0x00000003U)
#define CSL_SEMAPHORE_SEMFLAGL_F3_RESETVAL                                     (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F3_MAX                                          (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F4_MASK                                         (0x00000010U)
#define CSL_SEMAPHORE_SEMFLAGL_F4_SHIFT                                        (0x00000004U)
#define CSL_SEMAPHORE_SEMFLAGL_F4_RESETVAL                                     (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F4_MAX                                          (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F5_MASK                                         (0x00000020U)
#define CSL_SEMAPHORE_SEMFLAGL_F5_SHIFT                                        (0x00000005U)
#define CSL_SEMAPHORE_SEMFLAGL_F5_RESETVAL                                     (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F5_MAX                                          (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F6_MASK                                         (0x00000040U)
#define CSL_SEMAPHORE_SEMFLAGL_F6_SHIFT                                        (0x00000006U)
#define CSL_SEMAPHORE_SEMFLAGL_F6_RESETVAL                                     (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F6_MAX                                          (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F7_MASK                                         (0x00000080U)
#define CSL_SEMAPHORE_SEMFLAGL_F7_SHIFT                                        (0x00000007U)
#define CSL_SEMAPHORE_SEMFLAGL_F7_RESETVAL                                     (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F7_MAX                                          (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F8_MASK                                         (0x00000100U)
#define CSL_SEMAPHORE_SEMFLAGL_F8_SHIFT                                        (0x00000008U)
#define CSL_SEMAPHORE_SEMFLAGL_F8_RESETVAL                                     (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F8_MAX                                          (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F9_MASK                                         (0x00000200U)
#define CSL_SEMAPHORE_SEMFLAGL_F9_SHIFT                                        (0x00000009U)
#define CSL_SEMAPHORE_SEMFLAGL_F9_RESETVAL                                     (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F9_MAX                                          (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F10_MASK                                        (0x00000400U)
#define CSL_SEMAPHORE_SEMFLAGL_F10_SHIFT                                       (0x0000000AU)
#define CSL_SEMAPHORE_SEMFLAGL_F10_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F10_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F11_MASK                                        (0x00000800U)
#define CSL_SEMAPHORE_SEMFLAGL_F11_SHIFT                                       (0x0000000BU)
#define CSL_SEMAPHORE_SEMFLAGL_F11_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F11_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F12_MASK                                        (0x00001000U)
#define CSL_SEMAPHORE_SEMFLAGL_F12_SHIFT                                       (0x0000000CU)
#define CSL_SEMAPHORE_SEMFLAGL_F12_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F12_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F13_MASK                                        (0x00002000U)
#define CSL_SEMAPHORE_SEMFLAGL_F13_SHIFT                                       (0x0000000DU)
#define CSL_SEMAPHORE_SEMFLAGL_F13_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F13_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F14_MASK                                        (0x00004000U)
#define CSL_SEMAPHORE_SEMFLAGL_F14_SHIFT                                       (0x0000000EU)
#define CSL_SEMAPHORE_SEMFLAGL_F14_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F14_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F15_MASK                                        (0x00008000U)
#define CSL_SEMAPHORE_SEMFLAGL_F15_SHIFT                                       (0x0000000FU)
#define CSL_SEMAPHORE_SEMFLAGL_F15_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F15_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F16_MASK                                        (0x00010000U)
#define CSL_SEMAPHORE_SEMFLAGL_F16_SHIFT                                       (0x00000010U)
#define CSL_SEMAPHORE_SEMFLAGL_F16_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F16_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F17_MASK                                        (0x00020000U)
#define CSL_SEMAPHORE_SEMFLAGL_F17_SHIFT                                       (0x00000011U)
#define CSL_SEMAPHORE_SEMFLAGL_F17_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F17_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F18_MASK                                        (0x00040000U)
#define CSL_SEMAPHORE_SEMFLAGL_F18_SHIFT                                       (0x00000012U)
#define CSL_SEMAPHORE_SEMFLAGL_F18_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F18_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F19_MASK                                        (0x00080000U)
#define CSL_SEMAPHORE_SEMFLAGL_F19_SHIFT                                       (0x00000013U)
#define CSL_SEMAPHORE_SEMFLAGL_F19_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F19_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F20_MASK                                        (0x00100000U)
#define CSL_SEMAPHORE_SEMFLAGL_F20_SHIFT                                       (0x00000014U)
#define CSL_SEMAPHORE_SEMFLAGL_F20_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F20_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F21_MASK                                        (0x00200000U)
#define CSL_SEMAPHORE_SEMFLAGL_F21_SHIFT                                       (0x00000015U)
#define CSL_SEMAPHORE_SEMFLAGL_F21_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F21_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F22_MASK                                        (0x00400000U)
#define CSL_SEMAPHORE_SEMFLAGL_F22_SHIFT                                       (0x00000016U)
#define CSL_SEMAPHORE_SEMFLAGL_F22_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F22_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F23_MASK                                        (0x00800000U)
#define CSL_SEMAPHORE_SEMFLAGL_F23_SHIFT                                       (0x00000017U)
#define CSL_SEMAPHORE_SEMFLAGL_F23_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F23_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F24_MASK                                        (0x01000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F24_SHIFT                                       (0x00000018U)
#define CSL_SEMAPHORE_SEMFLAGL_F24_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F24_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F25_MASK                                        (0x02000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F25_SHIFT                                       (0x00000019U)
#define CSL_SEMAPHORE_SEMFLAGL_F25_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F25_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F26_MASK                                        (0x04000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F26_SHIFT                                       (0x0000001AU)
#define CSL_SEMAPHORE_SEMFLAGL_F26_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F26_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F27_MASK                                        (0x08000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F27_SHIFT                                       (0x0000001BU)
#define CSL_SEMAPHORE_SEMFLAGL_F27_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F27_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F28_MASK                                        (0x10000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F28_SHIFT                                       (0x0000001CU)
#define CSL_SEMAPHORE_SEMFLAGL_F28_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F28_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F29_MASK                                        (0x20000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F29_SHIFT                                       (0x0000001DU)
#define CSL_SEMAPHORE_SEMFLAGL_F29_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F29_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F30_MASK                                        (0x40000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F30_SHIFT                                       (0x0000001EU)
#define CSL_SEMAPHORE_SEMFLAGL_F30_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F30_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_F31_MASK                                        (0x80000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F31_SHIFT                                       (0x0000001FU)
#define CSL_SEMAPHORE_SEMFLAGL_F31_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_F31_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_RESETVAL                                        (0x00000000U)

/* SEMFLAGH */

#define CSL_SEMAPHORE_SEMFLAGH_F32_MASK                                        (0x00000001U)
#define CSL_SEMAPHORE_SEMFLAGH_F32_SHIFT                                       (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F32_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F32_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F33_MASK                                        (0x00000002U)
#define CSL_SEMAPHORE_SEMFLAGH_F33_SHIFT                                       (0x00000001U)
#define CSL_SEMAPHORE_SEMFLAGH_F33_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F33_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F34_MASK                                        (0x00000004U)
#define CSL_SEMAPHORE_SEMFLAGH_F34_SHIFT                                       (0x00000002U)
#define CSL_SEMAPHORE_SEMFLAGH_F34_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F34_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F35_MASK                                        (0x00000008U)
#define CSL_SEMAPHORE_SEMFLAGH_F35_SHIFT                                       (0x00000003U)
#define CSL_SEMAPHORE_SEMFLAGH_F35_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F35_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F36_MASK                                        (0x00000010U)
#define CSL_SEMAPHORE_SEMFLAGH_F36_SHIFT                                       (0x00000004U)
#define CSL_SEMAPHORE_SEMFLAGH_F36_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F36_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F37_MASK                                        (0x00000020U)
#define CSL_SEMAPHORE_SEMFLAGH_F37_SHIFT                                       (0x00000005U)
#define CSL_SEMAPHORE_SEMFLAGH_F37_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F37_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F38_MASK                                        (0x00000040U)
#define CSL_SEMAPHORE_SEMFLAGH_F38_SHIFT                                       (0x00000006U)
#define CSL_SEMAPHORE_SEMFLAGH_F38_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F38_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F39_MASK                                        (0x00000080U)
#define CSL_SEMAPHORE_SEMFLAGH_F39_SHIFT                                       (0x00000007U)
#define CSL_SEMAPHORE_SEMFLAGH_F39_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F39_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F40_MASK                                        (0x00000100U)
#define CSL_SEMAPHORE_SEMFLAGH_F40_SHIFT                                       (0x00000008U)
#define CSL_SEMAPHORE_SEMFLAGH_F40_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F40_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F41_MASK                                        (0x00000200U)
#define CSL_SEMAPHORE_SEMFLAGH_F41_SHIFT                                       (0x00000009U)
#define CSL_SEMAPHORE_SEMFLAGH_F41_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F41_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F42_MASK                                        (0x00000400U)
#define CSL_SEMAPHORE_SEMFLAGH_F42_SHIFT                                       (0x0000000AU)
#define CSL_SEMAPHORE_SEMFLAGH_F42_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F42_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F43_MASK                                        (0x00000800U)
#define CSL_SEMAPHORE_SEMFLAGH_F43_SHIFT                                       (0x0000000BU)
#define CSL_SEMAPHORE_SEMFLAGH_F43_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F43_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F44_MASK                                        (0x00001000U)
#define CSL_SEMAPHORE_SEMFLAGH_F44_SHIFT                                       (0x0000000CU)
#define CSL_SEMAPHORE_SEMFLAGH_F44_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F44_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F45_MASK                                        (0x00002000U)
#define CSL_SEMAPHORE_SEMFLAGH_F45_SHIFT                                       (0x0000000DU)
#define CSL_SEMAPHORE_SEMFLAGH_F45_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F45_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F46_MASK                                        (0x00004000U)
#define CSL_SEMAPHORE_SEMFLAGH_F46_SHIFT                                       (0x0000000EU)
#define CSL_SEMAPHORE_SEMFLAGH_F46_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F46_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F47_MASK                                        (0x00008000U)
#define CSL_SEMAPHORE_SEMFLAGH_F47_SHIFT                                       (0x0000000FU)
#define CSL_SEMAPHORE_SEMFLAGH_F47_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F47_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F48_MASK                                        (0x00010000U)
#define CSL_SEMAPHORE_SEMFLAGH_F48_SHIFT                                       (0x00000010U)
#define CSL_SEMAPHORE_SEMFLAGH_F48_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F48_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F49_MASK                                        (0x00020000U)
#define CSL_SEMAPHORE_SEMFLAGH_F49_SHIFT                                       (0x00000011U)
#define CSL_SEMAPHORE_SEMFLAGH_F49_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F49_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F50_MASK                                        (0x00040000U)
#define CSL_SEMAPHORE_SEMFLAGH_F50_SHIFT                                       (0x00000012U)
#define CSL_SEMAPHORE_SEMFLAGH_F50_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F50_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F51_MASK                                        (0x00080000U)
#define CSL_SEMAPHORE_SEMFLAGH_F51_SHIFT                                       (0x00000013U)
#define CSL_SEMAPHORE_SEMFLAGH_F51_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F51_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F52_MASK                                        (0x00100000U)
#define CSL_SEMAPHORE_SEMFLAGH_F52_SHIFT                                       (0x00000014U)
#define CSL_SEMAPHORE_SEMFLAGH_F52_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F52_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F53_MASK                                        (0x00200000U)
#define CSL_SEMAPHORE_SEMFLAGH_F53_SHIFT                                       (0x00000015U)
#define CSL_SEMAPHORE_SEMFLAGH_F53_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F53_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F54_MASK                                        (0x00400000U)
#define CSL_SEMAPHORE_SEMFLAGH_F54_SHIFT                                       (0x00000016U)
#define CSL_SEMAPHORE_SEMFLAGH_F54_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F54_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F55_MASK                                        (0x00800000U)
#define CSL_SEMAPHORE_SEMFLAGH_F55_SHIFT                                       (0x00000017U)
#define CSL_SEMAPHORE_SEMFLAGH_F55_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F55_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F56_MASK                                        (0x01000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F56_SHIFT                                       (0x00000018U)
#define CSL_SEMAPHORE_SEMFLAGH_F56_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F56_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F57_MASK                                        (0x02000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F57_SHIFT                                       (0x00000019U)
#define CSL_SEMAPHORE_SEMFLAGH_F57_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F57_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F58_MASK                                        (0x04000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F58_SHIFT                                       (0x0000001AU)
#define CSL_SEMAPHORE_SEMFLAGH_F58_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F58_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F59_MASK                                        (0x08000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F59_SHIFT                                       (0x0000001BU)
#define CSL_SEMAPHORE_SEMFLAGH_F59_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F59_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F60_MASK                                        (0x10000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F60_SHIFT                                       (0x0000001CU)
#define CSL_SEMAPHORE_SEMFLAGH_F60_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F60_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F61_MASK                                        (0x20000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F61_SHIFT                                       (0x0000001DU)
#define CSL_SEMAPHORE_SEMFLAGH_F61_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F61_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F62_MASK                                        (0x40000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F62_SHIFT                                       (0x0000001EU)
#define CSL_SEMAPHORE_SEMFLAGH_F62_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F62_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_F63_MASK                                        (0x80000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F63_SHIFT                                       (0x0000001FU)
#define CSL_SEMAPHORE_SEMFLAGH_F63_RESETVAL                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_F63_MAX                                         (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_RESETVAL                                        (0x00000000U)

/* SEMFLAGL_SET */

#define CSL_SEMAPHORE_SEMFLAGL_SET_F0_MASK                                     (0x00000001U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F0_SHIFT                                    (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F0_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F0_MAX                                      (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F1_MASK                                     (0x00000002U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F1_SHIFT                                    (0x00000001U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F1_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F1_MAX                                      (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F2_MASK                                     (0x00000004U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F2_SHIFT                                    (0x00000002U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F2_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F2_MAX                                      (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F3_MASK                                     (0x00000008U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F3_SHIFT                                    (0x00000003U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F3_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F3_MAX                                      (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F4_MASK                                     (0x00000010U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F4_SHIFT                                    (0x00000004U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F4_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F4_MAX                                      (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F5_MASK                                     (0x00000020U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F5_SHIFT                                    (0x00000005U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F5_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F5_MAX                                      (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F6_MASK                                     (0x00000040U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F6_SHIFT                                    (0x00000006U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F6_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F6_MAX                                      (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F7_MASK                                     (0x00000080U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F7_SHIFT                                    (0x00000007U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F7_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F7_MAX                                      (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F8_MASK                                     (0x00000100U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F8_SHIFT                                    (0x00000008U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F8_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F8_MAX                                      (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F9_MASK                                     (0x00000200U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F9_SHIFT                                    (0x00000009U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F9_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F9_MAX                                      (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F10_MASK                                    (0x00000400U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F10_SHIFT                                   (0x0000000AU)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F10_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F10_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F11_MASK                                    (0x00000800U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F11_SHIFT                                   (0x0000000BU)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F11_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F11_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F12_MASK                                    (0x00001000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F12_SHIFT                                   (0x0000000CU)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F12_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F12_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F13_MASK                                    (0x00002000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F13_SHIFT                                   (0x0000000DU)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F13_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F13_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F14_MASK                                    (0x00004000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F14_SHIFT                                   (0x0000000EU)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F14_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F14_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F15_MASK                                    (0x00008000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F15_SHIFT                                   (0x0000000FU)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F15_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F15_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F16_MASK                                    (0x00010000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F16_SHIFT                                   (0x00000010U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F16_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F16_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F17_MASK                                    (0x00020000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F17_SHIFT                                   (0x00000011U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F17_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F17_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F18_MASK                                    (0x00040000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F18_SHIFT                                   (0x00000012U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F18_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F18_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F19_MASK                                    (0x00080000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F19_SHIFT                                   (0x00000013U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F19_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F19_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F20_MASK                                    (0x00100000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F20_SHIFT                                   (0x00000014U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F20_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F20_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F21_MASK                                    (0x00200000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F21_SHIFT                                   (0x00000015U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F21_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F21_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F22_MASK                                    (0x00400000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F22_SHIFT                                   (0x00000016U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F22_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F22_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F23_MASK                                    (0x00800000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F23_SHIFT                                   (0x00000017U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F23_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F23_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F24_MASK                                    (0x01000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F24_SHIFT                                   (0x00000018U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F24_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F24_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F25_MASK                                    (0x02000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F25_SHIFT                                   (0x00000019U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F25_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F25_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F26_MASK                                    (0x04000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F26_SHIFT                                   (0x0000001AU)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F26_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F26_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F27_MASK                                    (0x08000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F27_SHIFT                                   (0x0000001BU)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F27_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F27_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F28_MASK                                    (0x10000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F28_SHIFT                                   (0x0000001CU)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F28_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F28_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F29_MASK                                    (0x20000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F29_SHIFT                                   (0x0000001DU)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F29_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F29_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F30_MASK                                    (0x40000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F30_SHIFT                                   (0x0000001EU)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F30_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F30_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_F31_MASK                                    (0x80000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F31_SHIFT                                   (0x0000001FU)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F31_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGL_SET_F31_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGL_SET_RESETVAL                                    (0x00000000U)

/* SEMFLAGH_SET */

#define CSL_SEMAPHORE_SEMFLAGH_SET_F32_MASK                                    (0x00000001U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F32_SHIFT                                   (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F32_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F32_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F33_MASK                                    (0x00000002U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F33_SHIFT                                   (0x00000001U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F33_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F33_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F34_MASK                                    (0x00000004U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F34_SHIFT                                   (0x00000002U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F34_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F34_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F35_MASK                                    (0x00000008U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F35_SHIFT                                   (0x00000003U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F35_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F35_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F36_MASK                                    (0x00000010U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F36_SHIFT                                   (0x00000004U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F36_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F36_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F37_MASK                                    (0x00000020U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F37_SHIFT                                   (0x00000005U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F37_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F37_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F38_MASK                                    (0x00000040U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F38_SHIFT                                   (0x00000006U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F38_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F38_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F39_MASK                                    (0x00000080U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F39_SHIFT                                   (0x00000007U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F39_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F39_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F40_MASK                                    (0x00000100U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F40_SHIFT                                   (0x00000008U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F40_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F40_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F41_MASK                                    (0x00000200U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F41_SHIFT                                   (0x00000009U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F41_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F41_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F42_MASK                                    (0x00000400U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F42_SHIFT                                   (0x0000000AU)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F42_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F42_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F43_MASK                                    (0x00000800U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F43_SHIFT                                   (0x0000000BU)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F43_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F43_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F44_MASK                                    (0x00001000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F44_SHIFT                                   (0x0000000CU)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F44_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F44_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F45_MASK                                    (0x00002000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F45_SHIFT                                   (0x0000000DU)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F45_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F45_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F46_MASK                                    (0x00004000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F46_SHIFT                                   (0x0000000EU)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F46_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F46_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F47_MASK                                    (0x00008000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F47_SHIFT                                   (0x0000000FU)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F47_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F47_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F48_MASK                                    (0x00010000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F48_SHIFT                                   (0x00000010U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F48_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F48_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F49_MASK                                    (0x00020000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F49_SHIFT                                   (0x00000011U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F49_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F49_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F50_MASK                                    (0x00040000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F50_SHIFT                                   (0x00000012U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F50_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F50_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F51_MASK                                    (0x00080000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F51_SHIFT                                   (0x00000013U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F51_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F51_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F52_MASK                                    (0x00100000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F52_SHIFT                                   (0x00000014U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F52_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F52_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F53_MASK                                    (0x00200000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F53_SHIFT                                   (0x00000015U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F53_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F53_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F54_MASK                                    (0x00400000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F54_SHIFT                                   (0x00000016U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F54_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F54_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F55_MASK                                    (0x00800000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F55_SHIFT                                   (0x00000017U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F55_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F55_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F56_MASK                                    (0x01000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F56_SHIFT                                   (0x00000018U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F56_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F56_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F57_MASK                                    (0x02000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F57_SHIFT                                   (0x00000019U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F57_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F57_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F58_MASK                                    (0x04000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F58_SHIFT                                   (0x0000001AU)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F58_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F58_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F59_MASK                                    (0x08000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F59_SHIFT                                   (0x0000001BU)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F59_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F59_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F60_MASK                                    (0x10000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F60_SHIFT                                   (0x0000001CU)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F60_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F60_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F61_MASK                                    (0x20000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F61_SHIFT                                   (0x0000001DU)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F61_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F61_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F62_MASK                                    (0x40000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F62_SHIFT                                   (0x0000001EU)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F62_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F62_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_F63_MASK                                    (0x80000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F63_SHIFT                                   (0x0000001FU)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F63_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_SEMFLAGH_SET_F63_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_SEMFLAGH_SET_RESETVAL                                    (0x00000000U)

/* ERR */

#define CSL_SEMAPHORE_ERR_ERR_MASK                                             (0x00000007U)
#define CSL_SEMAPHORE_ERR_ERR_SHIFT                                            (0x00000000U)
#define CSL_SEMAPHORE_ERR_ERR_RESETVAL                                         (0x00000000U)
#define CSL_SEMAPHORE_ERR_ERR_MAX                                              (0x00000007U)

#define CSL_SEMAPHORE_ERR_SEMNUM_MASK                                          (0x000001F8U)
#define CSL_SEMAPHORE_ERR_SEMNUM_SHIFT                                         (0x00000003U)
#define CSL_SEMAPHORE_ERR_SEMNUM_RESETVAL                                      (0x00000000U)
#define CSL_SEMAPHORE_ERR_SEMNUM_MAX                                           (0x0000003FU)

#define CSL_SEMAPHORE_ERR_FAULTID_MASK                                         (0x0000FE00U)
#define CSL_SEMAPHORE_ERR_FAULTID_SHIFT                                        (0x00000009U)
#define CSL_SEMAPHORE_ERR_FAULTID_RESETVAL                                     (0x00000000U)
#define CSL_SEMAPHORE_ERR_FAULTID_MAX                                          (0x0000007FU)

#define CSL_SEMAPHORE_ERR_RESETVAL                                             (0x00000000U)

/* ERR_CLEAR */

#define CSL_SEMAPHORE_ERR_CLEAR_CLRERR_MASK                                    (0x00000001U)
#define CSL_SEMAPHORE_ERR_CLEAR_CLRERR_SHIFT                                   (0x00000000U)
#define CSL_SEMAPHORE_ERR_CLEAR_CLRERR_RESETVAL                                (0x00000000U)
#define CSL_SEMAPHORE_ERR_CLEAR_CLRERR_MAX                                     (0x00000001U)

#define CSL_SEMAPHORE_ERR_CLEAR_RESETVAL                                       (0x00000000U)

/* ERR_SET */

#define CSL_SEMAPHORE_ERR_SET_ERR_MASK                                         (0x00000007U)
#define CSL_SEMAPHORE_ERR_SET_ERR_SHIFT                                        (0x00000000U)
#define CSL_SEMAPHORE_ERR_SET_ERR_RESETVAL                                     (0x00000000U)
#define CSL_SEMAPHORE_ERR_SET_ERR_MAX                                          (0x00000007U)

#define CSL_SEMAPHORE_ERR_SET_SEMNUM_MASK                                      (0x000001F8U)
#define CSL_SEMAPHORE_ERR_SET_SEMNUM_SHIFT                                     (0x00000003U)
#define CSL_SEMAPHORE_ERR_SET_SEMNUM_RESETVAL                                  (0x00000000U)
#define CSL_SEMAPHORE_ERR_SET_SEMNUM_MAX                                       (0x0000003FU)

#define CSL_SEMAPHORE_ERR_SET_FAULTID_MASK                                     (0x0000FE00U)
#define CSL_SEMAPHORE_ERR_SET_FAULTID_SHIFT                                    (0x00000009U)
#define CSL_SEMAPHORE_ERR_SET_FAULTID_RESETVAL                                 (0x00000000U)
#define CSL_SEMAPHORE_ERR_SET_FAULTID_MAX                                      (0x0000007FU)

#define CSL_SEMAPHORE_ERR_SET_RESETVAL                                         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
