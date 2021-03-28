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
#ifndef CSLR_SEM_H_
#define CSLR_SEM_H_

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
    volatile Uint32 SEM_PID;
    volatile Uint32 SEM_SCRATCH;
    volatile Uint32 SEM_RST_RUN;
    volatile Uint32 SEM_EOI;
    volatile Uint8  RSVD0[240];
    volatile Uint32 SEM[64];
    volatile Uint32 ISEM[64];
    volatile Uint32 QSEM[64];
    volatile Uint32 SEMFLAGL_CLEAR[16];
    volatile Uint32 SEMFLAGH_CLEAR[16];
    volatile Uint32 SEMFLAGL_SET[16];
    volatile Uint32 SEMFLAGH_SET[16];
    volatile Uint32 SEMERR;
    volatile Uint32 SEMERR_CLEAR;
    volatile Uint32 SEMERR_SET;
} CSL_SemRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* SEM_PID */
#define CSL_SEM_SEM_PID                                         (0x0U)

/* SEM_SCRATCH */
#define CSL_SEM_SEM_SCRATCH                                     (0x4U)

/* SEM_RST_RUN */
#define CSL_SEM_SEM_RST_RUN                                     (0x8U)

/* SEM_EOI */
#define CSL_SEM_SEM_EOI                                         (0xCU)

/* SEMERR */
#define CSL_SEM_SEMERR                                          (0x500U)

/* SEMERR_CLEAR */
#define CSL_SEM_SEMERR_CLEAR                                    (0x504U)

/* SEMERR_SET */
#define CSL_SEM_SEMERR_SET                                      (0x508U)

/* SEM */
#define CSL_SEM_SEM(i)                                          (0x100U + ((i) * (0x4U)))

/* ISEM */
#define CSL_SEM_ISEM(i)                                         (0x200U + ((i) * (0x4U)))

/* QSEM */
#define CSL_SEM_QSEM(i)                                         (0x300U + ((i) * (0x4U)))

/* SEMFLAGL */
#define CSL_SEM_SEMFLAGL(i)                                     (0x400U + ((i) * (0x4U)))

/* SEMFLAGL_CLEAR */
#define CSL_SEM_SEMFLAGL_CLEAR(i)                               (0x400U + ((i) * (0x4U)))

/* SEMFLAGL_SET */
#define CSL_SEM_SEMFLAGL_SET(i)                                 (0x480U + ((i) * (0x4U)))

/* SEMFLAGH */
#define CSL_SEM_SEMFLAGH(i)                                     (0x440U + ((i) * (0x4U)))

/* SEMFLAGH_CLEAR */
#define CSL_SEM_SEMFLAGH_CLEAR(i)                               (0x440U + ((i) * (0x4U)))

/* SEMFLAGH_SET */
#define CSL_SEM_SEMFLAGH_SET(i)                                 (0x4C0U + ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* SEM_PID */

#define CSL_SEM_SEM_PID_SCHEME_MASK                             (0xC0000000U)
#define CSL_SEM_SEM_PID_SCHEME_SHIFT                            (30U)
#define CSL_SEM_SEM_PID_SCHEME_RESETVAL                         (0x00000001U)
#define CSL_SEM_SEM_PID_SCHEME_MAX                              (0x00000003U)

#define CSL_SEM_SEM_PID_FUNC_MASK                               (0x0FFF0000U)
#define CSL_SEM_SEM_PID_FUNC_SHIFT                              (16U)
#define CSL_SEM_SEM_PID_FUNC_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEM_PID_FUNC_MAX                                (0x00000fffU)

#define CSL_SEM_SEM_PID_RTL_MASK                                (0x0000F800U)
#define CSL_SEM_SEM_PID_RTL_SHIFT                               (11U)
#define CSL_SEM_SEM_PID_RTL_RESETVAL                            (0x00000000U)
#define CSL_SEM_SEM_PID_RTL_MAX                                 (0x0000001fU)

#define CSL_SEM_SEM_PID_MAJOR_MASK                              (0x00000700U)
#define CSL_SEM_SEM_PID_MAJOR_SHIFT                             (8U)
#define CSL_SEM_SEM_PID_MAJOR_RESETVAL                          (0x00000000U)
#define CSL_SEM_SEM_PID_MAJOR_MAX                               (0x00000007U)

#define CSL_SEM_SEM_PID_CUSTOM_MASK                             (0x000000C0U)
#define CSL_SEM_SEM_PID_CUSTOM_SHIFT                            (6U)
#define CSL_SEM_SEM_PID_CUSTOM_RESETVAL                         (0x00000000U)
#define CSL_SEM_SEM_PID_CUSTOM_MAX                              (0x00000003U)

#define CSL_SEM_SEM_PID_MINOR_MASK                              (0x0000003FU)
#define CSL_SEM_SEM_PID_MINOR_SHIFT                             (0U)
#define CSL_SEM_SEM_PID_MINOR_RESETVAL                          (0x00000000U)
#define CSL_SEM_SEM_PID_MINOR_MAX                               (0x0000003fU)

#define CSL_SEM_SEM_PID_RESETVAL                                (0x40000000U)

/* SEM_SCRATCH */

#define CSL_SEM_SEM_SCRATCH_SCRATCH_MASK                        (0xFFFFFFFFU)
#define CSL_SEM_SEM_SCRATCH_SCRATCH_SHIFT                       (0U)
#define CSL_SEM_SEM_SCRATCH_SCRATCH_RESETVAL                    (0x00000000U)
#define CSL_SEM_SEM_SCRATCH_SCRATCH_MAX                         (0xffffffffU)

#define CSL_SEM_SEM_SCRATCH_RESETVAL                            (0x00000000U)

/* SEM_RST_RUN */

#define CSL_SEM_SEM_RST_RUN_RESET_MASK                          (0x00000001U)
#define CSL_SEM_SEM_RST_RUN_RESET_SHIFT                         (0U)
#define CSL_SEM_SEM_RST_RUN_RESET_RESETVAL                      (0x00000000U)
#define CSL_SEM_SEM_RST_RUN_RESET_MAX                           (0x00000001U)

#define CSL_SEM_SEM_RST_RUN_RESETVAL                            (0x00000000U)

/* SEM_EOI */

#define CSL_SEM_SEM_EOI_EOI_MASK                                (0x000000FFU)
#define CSL_SEM_SEM_EOI_EOI_SHIFT                               (0U)
#define CSL_SEM_SEM_EOI_EOI_RESETVAL                            (0x00000000U)
#define CSL_SEM_SEM_EOI_EOI_MAX                                 (0x000000ffU)

#define CSL_SEM_SEM_EOI_RESETVAL                                (0x00000000U)

/* SEMERR */

#define CSL_SEM_SEMERR_ERR_MASK                                 (0x00000007U)
#define CSL_SEM_SEMERR_ERR_SHIFT                                (0U)
#define CSL_SEM_SEMERR_ERR_RESETVAL                             (0x00000000U)
#define CSL_SEM_SEMERR_ERR_MAX                                  (0x00000007U)

#define CSL_SEM_SEMERR_SEMNUM_MASK                              (0x000001F8U)
#define CSL_SEM_SEMERR_SEMNUM_SHIFT                             (3U)
#define CSL_SEM_SEMERR_SEMNUM_RESETVAL                          (0x00000000U)
#define CSL_SEM_SEMERR_SEMNUM_MAX                               (0x0000003fU)

#define CSL_SEM_SEMERR_FAULTID_MASK                             (0x0000FE00U)
#define CSL_SEM_SEMERR_FAULTID_SHIFT                            (9U)
#define CSL_SEM_SEMERR_FAULTID_RESETVAL                         (0x00000000U)
#define CSL_SEM_SEMERR_FAULTID_MAX                              (0x0000007fU)

#define CSL_SEM_SEMERR_RESETVAL                                 (0x00000000U)

/* SEMERR_CLEAR */

#define CSL_SEM_SEMERR_CLEAR_CLRERR_MASK                        (0x00000001U)
#define CSL_SEM_SEMERR_CLEAR_CLRERR_SHIFT                       (0U)
#define CSL_SEM_SEMERR_CLEAR_CLRERR_RESETVAL                    (0x00000000U)
#define CSL_SEM_SEMERR_CLEAR_CLRERR_MAX                         (0x00000001U)

#define CSL_SEM_SEMERR_CLEAR_RESETVAL                           (0x00000000U)

/* SEMERR_SET */

#define CSL_SEM_SEMERR_SET_ERR_MASK                             (0x00000007U)
#define CSL_SEM_SEMERR_SET_ERR_SHIFT                            (0U)
#define CSL_SEM_SEMERR_SET_ERR_RESETVAL                         (0x00000000U)
#define CSL_SEM_SEMERR_SET_ERR_MAX                              (0x00000007U)

#define CSL_SEM_SEMERR_SET_SEMNUM_MASK                          (0x000001F8U)
#define CSL_SEM_SEMERR_SET_SEMNUM_SHIFT                         (3U)
#define CSL_SEM_SEMERR_SET_SEMNUM_RESETVAL                      (0x00000000U)
#define CSL_SEM_SEMERR_SET_SEMNUM_MAX                           (0x0000003fU)

#define CSL_SEM_SEMERR_SET_FAULTID_MASK                         (0x0000FE00U)
#define CSL_SEM_SEMERR_SET_FAULTID_SHIFT                        (9U)
#define CSL_SEM_SEMERR_SET_FAULTID_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMERR_SET_FAULTID_MAX                          (0x0000007fU)

#define CSL_SEM_SEMERR_SET_RESETVAL                             (0x00000000U)

/* SEM */

#define CSL_SEM_SEM_FREE0_MASK                                  (0x00000001U)
#define CSL_SEM_SEM_FREE0_SHIFT                                 (0U)
#define CSL_SEM_SEM_FREE0_RESETVAL                              (0x00000001U)
#define CSL_SEM_SEM_FREE0_MAX                                   (0x00000001U)

#define CSL_SEM_SEM_FREE8_15_MASK                               (0x0000FF00U)
#define CSL_SEM_SEM_FREE8_15_SHIFT                              (8U)
#define CSL_SEM_SEM_FREE8_15_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEM_FREE8_15_MAX                                (0x000000ffU)

#define CSL_SEM_SEM_RESETVAL                                    (0x00000001U)

/* ISEM */

#define CSL_SEM_ISEM_FREE0_MASK                                 (0x00000001U)
#define CSL_SEM_ISEM_FREE0_SHIFT                                (0U)
#define CSL_SEM_ISEM_FREE0_RESETVAL                             (0x00000001U)
#define CSL_SEM_ISEM_FREE0_MAX                                  (0x00000001U)

#define CSL_SEM_ISEM_FREE8_15_MASK                              (0x0000FF00U)
#define CSL_SEM_ISEM_FREE8_15_SHIFT                             (8U)
#define CSL_SEM_ISEM_FREE8_15_RESETVAL                          (0x00000000U)
#define CSL_SEM_ISEM_FREE8_15_MAX                               (0x000000ffU)

#define CSL_SEM_ISEM_RESETVAL                                   (0x00000001U)

/* QSEM */

#define CSL_SEM_QSEM_FREE0_MASK                                 (0x00000001U)
#define CSL_SEM_QSEM_FREE0_SHIFT                                (0U)
#define CSL_SEM_QSEM_FREE0_RESETVAL                             (0x00000001U)
#define CSL_SEM_QSEM_FREE0_MAX                                  (0x00000001U)

#define CSL_SEM_QSEM_FREE8_15_MASK                              (0x0000FF00U)
#define CSL_SEM_QSEM_FREE8_15_SHIFT                             (8U)
#define CSL_SEM_QSEM_FREE8_15_RESETVAL                          (0x00000000U)
#define CSL_SEM_QSEM_FREE8_15_MAX                               (0x000000ffU)

#define CSL_SEM_QSEM_RESETVAL                                   (0x00000001U)

/* SEMFLAGL */

#define CSL_SEM_SEMFLAGL_F0_MASK                                (0x00000001U)
#define CSL_SEM_SEMFLAGL_F0_SHIFT                               (0U)
#define CSL_SEM_SEMFLAGL_F0_RESETVAL                            (0x00000000U)
#define CSL_SEM_SEMFLAGL_F0_MAX                                 (0x00000001U)

#define CSL_SEM_SEMFLAGL_F1_MASK                                (0x00000002U)
#define CSL_SEM_SEMFLAGL_F1_SHIFT                               (1U)
#define CSL_SEM_SEMFLAGL_F1_RESETVAL                            (0x00000000U)
#define CSL_SEM_SEMFLAGL_F1_MAX                                 (0x00000001U)

#define CSL_SEM_SEMFLAGL_F2_MASK                                (0x00000004U)
#define CSL_SEM_SEMFLAGL_F2_SHIFT                               (2U)
#define CSL_SEM_SEMFLAGL_F2_RESETVAL                            (0x00000000U)
#define CSL_SEM_SEMFLAGL_F2_MAX                                 (0x00000001U)

#define CSL_SEM_SEMFLAGL_F3_MASK                                (0x00000008U)
#define CSL_SEM_SEMFLAGL_F3_SHIFT                               (3U)
#define CSL_SEM_SEMFLAGL_F3_RESETVAL                            (0x00000000U)
#define CSL_SEM_SEMFLAGL_F3_MAX                                 (0x00000001U)

#define CSL_SEM_SEMFLAGL_F4_MASK                                (0x00000010U)
#define CSL_SEM_SEMFLAGL_F4_SHIFT                               (4U)
#define CSL_SEM_SEMFLAGL_F4_RESETVAL                            (0x00000000U)
#define CSL_SEM_SEMFLAGL_F4_MAX                                 (0x00000001U)

#define CSL_SEM_SEMFLAGL_F5_MASK                                (0x00000020U)
#define CSL_SEM_SEMFLAGL_F5_SHIFT                               (5U)
#define CSL_SEM_SEMFLAGL_F5_RESETVAL                            (0x00000000U)
#define CSL_SEM_SEMFLAGL_F5_MAX                                 (0x00000001U)

#define CSL_SEM_SEMFLAGL_F6_MASK                                (0x00000040U)
#define CSL_SEM_SEMFLAGL_F6_SHIFT                               (6U)
#define CSL_SEM_SEMFLAGL_F6_RESETVAL                            (0x00000000U)
#define CSL_SEM_SEMFLAGL_F6_MAX                                 (0x00000001U)

#define CSL_SEM_SEMFLAGL_F7_MASK                                (0x00000080U)
#define CSL_SEM_SEMFLAGL_F7_SHIFT                               (7U)
#define CSL_SEM_SEMFLAGL_F7_RESETVAL                            (0x00000000U)
#define CSL_SEM_SEMFLAGL_F7_MAX                                 (0x00000001U)

#define CSL_SEM_SEMFLAGL_F8_MASK                                (0x00000100U)
#define CSL_SEM_SEMFLAGL_F8_SHIFT                               (8U)
#define CSL_SEM_SEMFLAGL_F8_RESETVAL                            (0x00000000U)
#define CSL_SEM_SEMFLAGL_F8_MAX                                 (0x00000001U)

#define CSL_SEM_SEMFLAGL_F9_MASK                                (0x00000200U)
#define CSL_SEM_SEMFLAGL_F9_SHIFT                               (9U)
#define CSL_SEM_SEMFLAGL_F9_RESETVAL                            (0x00000000U)
#define CSL_SEM_SEMFLAGL_F9_MAX                                 (0x00000001U)

#define CSL_SEM_SEMFLAGL_F10_MASK                               (0x00000400U)
#define CSL_SEM_SEMFLAGL_F10_SHIFT                              (10U)
#define CSL_SEM_SEMFLAGL_F10_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F10_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F11_MASK                               (0x00000800U)
#define CSL_SEM_SEMFLAGL_F11_SHIFT                              (11U)
#define CSL_SEM_SEMFLAGL_F11_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F11_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F12_MASK                               (0x00001000U)
#define CSL_SEM_SEMFLAGL_F12_SHIFT                              (12U)
#define CSL_SEM_SEMFLAGL_F12_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F12_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F13_MASK                               (0x00002000U)
#define CSL_SEM_SEMFLAGL_F13_SHIFT                              (13U)
#define CSL_SEM_SEMFLAGL_F13_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F13_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F14_MASK                               (0x00004000U)
#define CSL_SEM_SEMFLAGL_F14_SHIFT                              (14U)
#define CSL_SEM_SEMFLAGL_F14_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F14_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F15_MASK                               (0x00008000U)
#define CSL_SEM_SEMFLAGL_F15_SHIFT                              (15U)
#define CSL_SEM_SEMFLAGL_F15_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F15_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F16_MASK                               (0x00010000U)
#define CSL_SEM_SEMFLAGL_F16_SHIFT                              (16U)
#define CSL_SEM_SEMFLAGL_F16_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F16_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F17_MASK                               (0x00020000U)
#define CSL_SEM_SEMFLAGL_F17_SHIFT                              (17U)
#define CSL_SEM_SEMFLAGL_F17_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F17_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F18_MASK                               (0x00040000U)
#define CSL_SEM_SEMFLAGL_F18_SHIFT                              (18U)
#define CSL_SEM_SEMFLAGL_F18_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F18_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F19_MASK                               (0x00080000U)
#define CSL_SEM_SEMFLAGL_F19_SHIFT                              (19U)
#define CSL_SEM_SEMFLAGL_F19_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F19_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F20_MASK                               (0x00100000U)
#define CSL_SEM_SEMFLAGL_F20_SHIFT                              (20U)
#define CSL_SEM_SEMFLAGL_F20_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F20_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F21_MASK                               (0x00200000U)
#define CSL_SEM_SEMFLAGL_F21_SHIFT                              (21U)
#define CSL_SEM_SEMFLAGL_F21_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F21_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F22_MASK                               (0x00400000U)
#define CSL_SEM_SEMFLAGL_F22_SHIFT                              (22U)
#define CSL_SEM_SEMFLAGL_F22_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F22_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F23_MASK                               (0x00800000U)
#define CSL_SEM_SEMFLAGL_F23_SHIFT                              (23U)
#define CSL_SEM_SEMFLAGL_F23_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F23_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F24_MASK                               (0x01000000U)
#define CSL_SEM_SEMFLAGL_F24_SHIFT                              (24U)
#define CSL_SEM_SEMFLAGL_F24_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F24_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F25_MASK                               (0x02000000U)
#define CSL_SEM_SEMFLAGL_F25_SHIFT                              (25U)
#define CSL_SEM_SEMFLAGL_F25_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F25_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F26_MASK                               (0x04000000U)
#define CSL_SEM_SEMFLAGL_F26_SHIFT                              (26U)
#define CSL_SEM_SEMFLAGL_F26_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F26_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F27_MASK                               (0x08000000U)
#define CSL_SEM_SEMFLAGL_F27_SHIFT                              (27U)
#define CSL_SEM_SEMFLAGL_F27_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F27_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F28_MASK                               (0x10000000U)
#define CSL_SEM_SEMFLAGL_F28_SHIFT                              (28U)
#define CSL_SEM_SEMFLAGL_F28_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F28_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F29_MASK                               (0x20000000U)
#define CSL_SEM_SEMFLAGL_F29_SHIFT                              (29U)
#define CSL_SEM_SEMFLAGL_F29_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F29_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F30_MASK                               (0x40000000U)
#define CSL_SEM_SEMFLAGL_F30_SHIFT                              (30U)
#define CSL_SEM_SEMFLAGL_F30_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F30_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_F31_MASK                               (0x80000000U)
#define CSL_SEM_SEMFLAGL_F31_SHIFT                              (31U)
#define CSL_SEM_SEMFLAGL_F31_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGL_F31_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGL_RESETVAL                               (0x00000000U)

/* SEMFLAGL_CLEAR */

#define CSL_SEM_SEMFLAGL_CLEAR_F0_MASK                          (0x00000001U)
#define CSL_SEM_SEMFLAGL_CLEAR_F0_SHIFT                         (0U)
#define CSL_SEM_SEMFLAGL_CLEAR_F0_RESETVAL                      (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F0_MAX                           (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F1_MASK                          (0x00000002U)
#define CSL_SEM_SEMFLAGL_CLEAR_F1_SHIFT                         (1U)
#define CSL_SEM_SEMFLAGL_CLEAR_F1_RESETVAL                      (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F1_MAX                           (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F2_MASK                          (0x00000004U)
#define CSL_SEM_SEMFLAGL_CLEAR_F2_SHIFT                         (2U)
#define CSL_SEM_SEMFLAGL_CLEAR_F2_RESETVAL                      (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F2_MAX                           (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F3_MASK                          (0x00000008U)
#define CSL_SEM_SEMFLAGL_CLEAR_F3_SHIFT                         (3U)
#define CSL_SEM_SEMFLAGL_CLEAR_F3_RESETVAL                      (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F3_MAX                           (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F4_MASK                          (0x00000010U)
#define CSL_SEM_SEMFLAGL_CLEAR_F4_SHIFT                         (4U)
#define CSL_SEM_SEMFLAGL_CLEAR_F4_RESETVAL                      (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F4_MAX                           (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F5_MASK                          (0x00000020U)
#define CSL_SEM_SEMFLAGL_CLEAR_F5_SHIFT                         (5U)
#define CSL_SEM_SEMFLAGL_CLEAR_F5_RESETVAL                      (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F5_MAX                           (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F6_MASK                          (0x00000040U)
#define CSL_SEM_SEMFLAGL_CLEAR_F6_SHIFT                         (6U)
#define CSL_SEM_SEMFLAGL_CLEAR_F6_RESETVAL                      (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F6_MAX                           (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F7_MASK                          (0x00000080U)
#define CSL_SEM_SEMFLAGL_CLEAR_F7_SHIFT                         (7U)
#define CSL_SEM_SEMFLAGL_CLEAR_F7_RESETVAL                      (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F7_MAX                           (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F8_MASK                          (0x00000100U)
#define CSL_SEM_SEMFLAGL_CLEAR_F8_SHIFT                         (8U)
#define CSL_SEM_SEMFLAGL_CLEAR_F8_RESETVAL                      (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F8_MAX                           (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F9_MASK                          (0x00000200U)
#define CSL_SEM_SEMFLAGL_CLEAR_F9_SHIFT                         (9U)
#define CSL_SEM_SEMFLAGL_CLEAR_F9_RESETVAL                      (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F9_MAX                           (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F10_MASK                         (0x00000400U)
#define CSL_SEM_SEMFLAGL_CLEAR_F10_SHIFT                        (10U)
#define CSL_SEM_SEMFLAGL_CLEAR_F10_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F10_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F11_MASK                         (0x00000800U)
#define CSL_SEM_SEMFLAGL_CLEAR_F11_SHIFT                        (11U)
#define CSL_SEM_SEMFLAGL_CLEAR_F11_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F11_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F12_MASK                         (0x00001000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F12_SHIFT                        (12U)
#define CSL_SEM_SEMFLAGL_CLEAR_F12_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F12_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F13_MASK                         (0x00002000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F13_SHIFT                        (13U)
#define CSL_SEM_SEMFLAGL_CLEAR_F13_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F13_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F14_MASK                         (0x00004000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F14_SHIFT                        (14U)
#define CSL_SEM_SEMFLAGL_CLEAR_F14_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F14_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F15_MASK                         (0x00008000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F15_SHIFT                        (15U)
#define CSL_SEM_SEMFLAGL_CLEAR_F15_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F15_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F16_MASK                         (0x00010000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F16_SHIFT                        (16U)
#define CSL_SEM_SEMFLAGL_CLEAR_F16_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F16_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F17_MASK                         (0x00020000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F17_SHIFT                        (17U)
#define CSL_SEM_SEMFLAGL_CLEAR_F17_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F17_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F18_MASK                         (0x00040000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F18_SHIFT                        (18U)
#define CSL_SEM_SEMFLAGL_CLEAR_F18_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F18_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F19_MASK                         (0x00080000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F19_SHIFT                        (19U)
#define CSL_SEM_SEMFLAGL_CLEAR_F19_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F19_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F20_MASK                         (0x00100000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F20_SHIFT                        (20U)
#define CSL_SEM_SEMFLAGL_CLEAR_F20_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F20_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F21_MASK                         (0x00200000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F21_SHIFT                        (21U)
#define CSL_SEM_SEMFLAGL_CLEAR_F21_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F21_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F22_MASK                         (0x00400000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F22_SHIFT                        (22U)
#define CSL_SEM_SEMFLAGL_CLEAR_F22_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F22_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F23_MASK                         (0x00800000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F23_SHIFT                        (23U)
#define CSL_SEM_SEMFLAGL_CLEAR_F23_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F23_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F24_MASK                         (0x01000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F24_SHIFT                        (24U)
#define CSL_SEM_SEMFLAGL_CLEAR_F24_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F24_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F25_MASK                         (0x02000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F25_SHIFT                        (25U)
#define CSL_SEM_SEMFLAGL_CLEAR_F25_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F25_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F26_MASK                         (0x04000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F26_SHIFT                        (26U)
#define CSL_SEM_SEMFLAGL_CLEAR_F26_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F26_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F27_MASK                         (0x08000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F27_SHIFT                        (27U)
#define CSL_SEM_SEMFLAGL_CLEAR_F27_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F27_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F28_MASK                         (0x10000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F28_SHIFT                        (28U)
#define CSL_SEM_SEMFLAGL_CLEAR_F28_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F28_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F29_MASK                         (0x20000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F29_SHIFT                        (29U)
#define CSL_SEM_SEMFLAGL_CLEAR_F29_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F29_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F30_MASK                         (0x40000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F30_SHIFT                        (30U)
#define CSL_SEM_SEMFLAGL_CLEAR_F30_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F30_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_F31_MASK                         (0x80000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F31_SHIFT                        (31U)
#define CSL_SEM_SEMFLAGL_CLEAR_F31_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGL_CLEAR_F31_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGL_CLEAR_RESETVAL                         (0x00000000U)

/* SEMFLAGL_SET */

#define CSL_SEM_SEMFLAGL_SET_F0_MASK                            (0x00000001U)
#define CSL_SEM_SEMFLAGL_SET_F0_SHIFT                           (0U)
#define CSL_SEM_SEMFLAGL_SET_F0_RESETVAL                        (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F0_MAX                             (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F1_MASK                            (0x00000002U)
#define CSL_SEM_SEMFLAGL_SET_F1_SHIFT                           (1U)
#define CSL_SEM_SEMFLAGL_SET_F1_RESETVAL                        (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F1_MAX                             (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F2_MASK                            (0x00000004U)
#define CSL_SEM_SEMFLAGL_SET_F2_SHIFT                           (2U)
#define CSL_SEM_SEMFLAGL_SET_F2_RESETVAL                        (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F2_MAX                             (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F3_MASK                            (0x00000008U)
#define CSL_SEM_SEMFLAGL_SET_F3_SHIFT                           (3U)
#define CSL_SEM_SEMFLAGL_SET_F3_RESETVAL                        (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F3_MAX                             (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F4_MASK                            (0x00000010U)
#define CSL_SEM_SEMFLAGL_SET_F4_SHIFT                           (4U)
#define CSL_SEM_SEMFLAGL_SET_F4_RESETVAL                        (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F4_MAX                             (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F5_MASK                            (0x00000020U)
#define CSL_SEM_SEMFLAGL_SET_F5_SHIFT                           (5U)
#define CSL_SEM_SEMFLAGL_SET_F5_RESETVAL                        (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F5_MAX                             (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F6_MASK                            (0x00000040U)
#define CSL_SEM_SEMFLAGL_SET_F6_SHIFT                           (6U)
#define CSL_SEM_SEMFLAGL_SET_F6_RESETVAL                        (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F6_MAX                             (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F7_MASK                            (0x00000080U)
#define CSL_SEM_SEMFLAGL_SET_F7_SHIFT                           (7U)
#define CSL_SEM_SEMFLAGL_SET_F7_RESETVAL                        (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F7_MAX                             (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F8_MASK                            (0x00000100U)
#define CSL_SEM_SEMFLAGL_SET_F8_SHIFT                           (8U)
#define CSL_SEM_SEMFLAGL_SET_F8_RESETVAL                        (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F8_MAX                             (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F9_MASK                            (0x00000200U)
#define CSL_SEM_SEMFLAGL_SET_F9_SHIFT                           (9U)
#define CSL_SEM_SEMFLAGL_SET_F9_RESETVAL                        (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F9_MAX                             (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F10_MASK                           (0x00000400U)
#define CSL_SEM_SEMFLAGL_SET_F10_SHIFT                          (10U)
#define CSL_SEM_SEMFLAGL_SET_F10_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F10_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F11_MASK                           (0x00000800U)
#define CSL_SEM_SEMFLAGL_SET_F11_SHIFT                          (11U)
#define CSL_SEM_SEMFLAGL_SET_F11_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F11_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F12_MASK                           (0x00001000U)
#define CSL_SEM_SEMFLAGL_SET_F12_SHIFT                          (12U)
#define CSL_SEM_SEMFLAGL_SET_F12_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F12_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F13_MASK                           (0x00002000U)
#define CSL_SEM_SEMFLAGL_SET_F13_SHIFT                          (13U)
#define CSL_SEM_SEMFLAGL_SET_F13_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F13_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F14_MASK                           (0x00004000U)
#define CSL_SEM_SEMFLAGL_SET_F14_SHIFT                          (14U)
#define CSL_SEM_SEMFLAGL_SET_F14_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F14_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F15_MASK                           (0x00008000U)
#define CSL_SEM_SEMFLAGL_SET_F15_SHIFT                          (15U)
#define CSL_SEM_SEMFLAGL_SET_F15_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F15_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F16_MASK                           (0x00010000U)
#define CSL_SEM_SEMFLAGL_SET_F16_SHIFT                          (16U)
#define CSL_SEM_SEMFLAGL_SET_F16_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F16_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F17_MASK                           (0x00020000U)
#define CSL_SEM_SEMFLAGL_SET_F17_SHIFT                          (17U)
#define CSL_SEM_SEMFLAGL_SET_F17_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F17_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F18_MASK                           (0x00040000U)
#define CSL_SEM_SEMFLAGL_SET_F18_SHIFT                          (18U)
#define CSL_SEM_SEMFLAGL_SET_F18_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F18_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F19_MASK                           (0x00080000U)
#define CSL_SEM_SEMFLAGL_SET_F19_SHIFT                          (19U)
#define CSL_SEM_SEMFLAGL_SET_F19_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F19_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F20_MASK                           (0x00100000U)
#define CSL_SEM_SEMFLAGL_SET_F20_SHIFT                          (20U)
#define CSL_SEM_SEMFLAGL_SET_F20_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F20_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F21_MASK                           (0x00200000U)
#define CSL_SEM_SEMFLAGL_SET_F21_SHIFT                          (21U)
#define CSL_SEM_SEMFLAGL_SET_F21_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F21_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F22_MASK                           (0x00400000U)
#define CSL_SEM_SEMFLAGL_SET_F22_SHIFT                          (22U)
#define CSL_SEM_SEMFLAGL_SET_F22_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F22_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F23_MASK                           (0x00800000U)
#define CSL_SEM_SEMFLAGL_SET_F23_SHIFT                          (23U)
#define CSL_SEM_SEMFLAGL_SET_F23_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F23_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F24_MASK                           (0x01000000U)
#define CSL_SEM_SEMFLAGL_SET_F24_SHIFT                          (24U)
#define CSL_SEM_SEMFLAGL_SET_F24_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F24_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F25_MASK                           (0x02000000U)
#define CSL_SEM_SEMFLAGL_SET_F25_SHIFT                          (25U)
#define CSL_SEM_SEMFLAGL_SET_F25_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F25_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F26_MASK                           (0x04000000U)
#define CSL_SEM_SEMFLAGL_SET_F26_SHIFT                          (26U)
#define CSL_SEM_SEMFLAGL_SET_F26_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F26_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F27_MASK                           (0x08000000U)
#define CSL_SEM_SEMFLAGL_SET_F27_SHIFT                          (27U)
#define CSL_SEM_SEMFLAGL_SET_F27_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F27_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F28_MASK                           (0x10000000U)
#define CSL_SEM_SEMFLAGL_SET_F28_SHIFT                          (28U)
#define CSL_SEM_SEMFLAGL_SET_F28_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F28_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F29_MASK                           (0x20000000U)
#define CSL_SEM_SEMFLAGL_SET_F29_SHIFT                          (29U)
#define CSL_SEM_SEMFLAGL_SET_F29_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F29_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F30_MASK                           (0x40000000U)
#define CSL_SEM_SEMFLAGL_SET_F30_SHIFT                          (30U)
#define CSL_SEM_SEMFLAGL_SET_F30_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F30_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_F31_MASK                           (0x80000000U)
#define CSL_SEM_SEMFLAGL_SET_F31_SHIFT                          (31U)
#define CSL_SEM_SEMFLAGL_SET_F31_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGL_SET_F31_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGL_SET_RESETVAL                           (0x00000000U)

/* SEMFLAGH */

#define CSL_SEM_SEMFLAGH_F32_MASK                               (0x00000001U)
#define CSL_SEM_SEMFLAGH_F32_SHIFT                              (0U)
#define CSL_SEM_SEMFLAGH_F32_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F32_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F33_MASK                               (0x00000002U)
#define CSL_SEM_SEMFLAGH_F33_SHIFT                              (1U)
#define CSL_SEM_SEMFLAGH_F33_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F33_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F34_MASK                               (0x00000004U)
#define CSL_SEM_SEMFLAGH_F34_SHIFT                              (2U)
#define CSL_SEM_SEMFLAGH_F34_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F34_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F35_MASK                               (0x00000008U)
#define CSL_SEM_SEMFLAGH_F35_SHIFT                              (3U)
#define CSL_SEM_SEMFLAGH_F35_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F35_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F36_MASK                               (0x00000010U)
#define CSL_SEM_SEMFLAGH_F36_SHIFT                              (4U)
#define CSL_SEM_SEMFLAGH_F36_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F36_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F37_MASK                               (0x00000020U)
#define CSL_SEM_SEMFLAGH_F37_SHIFT                              (5U)
#define CSL_SEM_SEMFLAGH_F37_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F37_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F38_MASK                               (0x00000040U)
#define CSL_SEM_SEMFLAGH_F38_SHIFT                              (6U)
#define CSL_SEM_SEMFLAGH_F38_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F38_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F39_MASK                               (0x00000080U)
#define CSL_SEM_SEMFLAGH_F39_SHIFT                              (7U)
#define CSL_SEM_SEMFLAGH_F39_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F39_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F40_MASK                               (0x00000100U)
#define CSL_SEM_SEMFLAGH_F40_SHIFT                              (8U)
#define CSL_SEM_SEMFLAGH_F40_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F40_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F41_MASK                               (0x00000200U)
#define CSL_SEM_SEMFLAGH_F41_SHIFT                              (9U)
#define CSL_SEM_SEMFLAGH_F41_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F41_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F42_MASK                               (0x00000400U)
#define CSL_SEM_SEMFLAGH_F42_SHIFT                              (10U)
#define CSL_SEM_SEMFLAGH_F42_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F42_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F43_MASK                               (0x00000800U)
#define CSL_SEM_SEMFLAGH_F43_SHIFT                              (11U)
#define CSL_SEM_SEMFLAGH_F43_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F43_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F44_MASK                               (0x00001000U)
#define CSL_SEM_SEMFLAGH_F44_SHIFT                              (12U)
#define CSL_SEM_SEMFLAGH_F44_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F44_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F45_MASK                               (0x00002000U)
#define CSL_SEM_SEMFLAGH_F45_SHIFT                              (13U)
#define CSL_SEM_SEMFLAGH_F45_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F45_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F46_MASK                               (0x00004000U)
#define CSL_SEM_SEMFLAGH_F46_SHIFT                              (14U)
#define CSL_SEM_SEMFLAGH_F46_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F46_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F47_MASK                               (0x00008000U)
#define CSL_SEM_SEMFLAGH_F47_SHIFT                              (15U)
#define CSL_SEM_SEMFLAGH_F47_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F47_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F48_MASK                               (0x00010000U)
#define CSL_SEM_SEMFLAGH_F48_SHIFT                              (16U)
#define CSL_SEM_SEMFLAGH_F48_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F48_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F49_MASK                               (0x00020000U)
#define CSL_SEM_SEMFLAGH_F49_SHIFT                              (17U)
#define CSL_SEM_SEMFLAGH_F49_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F49_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F50_MASK                               (0x00040000U)
#define CSL_SEM_SEMFLAGH_F50_SHIFT                              (18U)
#define CSL_SEM_SEMFLAGH_F50_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F50_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F51_MASK                               (0x00080000U)
#define CSL_SEM_SEMFLAGH_F51_SHIFT                              (19U)
#define CSL_SEM_SEMFLAGH_F51_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F51_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F52_MASK                               (0x00100000U)
#define CSL_SEM_SEMFLAGH_F52_SHIFT                              (20U)
#define CSL_SEM_SEMFLAGH_F52_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F52_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F53_MASK                               (0x00200000U)
#define CSL_SEM_SEMFLAGH_F53_SHIFT                              (21U)
#define CSL_SEM_SEMFLAGH_F53_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F53_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F54_MASK                               (0x00400000U)
#define CSL_SEM_SEMFLAGH_F54_SHIFT                              (22U)
#define CSL_SEM_SEMFLAGH_F54_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F54_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F55_MASK                               (0x00800000U)
#define CSL_SEM_SEMFLAGH_F55_SHIFT                              (23U)
#define CSL_SEM_SEMFLAGH_F55_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F55_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F56_MASK                               (0x01000000U)
#define CSL_SEM_SEMFLAGH_F56_SHIFT                              (24U)
#define CSL_SEM_SEMFLAGH_F56_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F56_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F57_MASK                               (0x02000000U)
#define CSL_SEM_SEMFLAGH_F57_SHIFT                              (25U)
#define CSL_SEM_SEMFLAGH_F57_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F57_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F58_MASK                               (0x04000000U)
#define CSL_SEM_SEMFLAGH_F58_SHIFT                              (26U)
#define CSL_SEM_SEMFLAGH_F58_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F58_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F59_MASK                               (0x08000000U)
#define CSL_SEM_SEMFLAGH_F59_SHIFT                              (27U)
#define CSL_SEM_SEMFLAGH_F59_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F59_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F60_MASK                               (0x10000000U)
#define CSL_SEM_SEMFLAGH_F60_SHIFT                              (28U)
#define CSL_SEM_SEMFLAGH_F60_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F60_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F61_MASK                               (0x20000000U)
#define CSL_SEM_SEMFLAGH_F61_SHIFT                              (29U)
#define CSL_SEM_SEMFLAGH_F61_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F61_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F62_MASK                               (0x40000000U)
#define CSL_SEM_SEMFLAGH_F62_SHIFT                              (30U)
#define CSL_SEM_SEMFLAGH_F62_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F62_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_F63_MASK                               (0x80000000U)
#define CSL_SEM_SEMFLAGH_F63_SHIFT                              (31U)
#define CSL_SEM_SEMFLAGH_F63_RESETVAL                           (0x00000000U)
#define CSL_SEM_SEMFLAGH_F63_MAX                                (0x00000001U)

#define CSL_SEM_SEMFLAGH_RESETVAL                               (0x00000000U)

/* SEMFLAGH_CLEAR */

#define CSL_SEM_SEMFLAGH_CLEAR_F32_MASK                         (0x00000001U)
#define CSL_SEM_SEMFLAGH_CLEAR_F32_SHIFT                        (0U)
#define CSL_SEM_SEMFLAGH_CLEAR_F32_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F32_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F33_MASK                         (0x00000002U)
#define CSL_SEM_SEMFLAGH_CLEAR_F33_SHIFT                        (1U)
#define CSL_SEM_SEMFLAGH_CLEAR_F33_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F33_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F34_MASK                         (0x00000004U)
#define CSL_SEM_SEMFLAGH_CLEAR_F34_SHIFT                        (2U)
#define CSL_SEM_SEMFLAGH_CLEAR_F34_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F34_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F35_MASK                         (0x00000008U)
#define CSL_SEM_SEMFLAGH_CLEAR_F35_SHIFT                        (3U)
#define CSL_SEM_SEMFLAGH_CLEAR_F35_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F35_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F36_MASK                         (0x00000010U)
#define CSL_SEM_SEMFLAGH_CLEAR_F36_SHIFT                        (4U)
#define CSL_SEM_SEMFLAGH_CLEAR_F36_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F36_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F37_MASK                         (0x00000020U)
#define CSL_SEM_SEMFLAGH_CLEAR_F37_SHIFT                        (5U)
#define CSL_SEM_SEMFLAGH_CLEAR_F37_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F37_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F38_MASK                         (0x00000040U)
#define CSL_SEM_SEMFLAGH_CLEAR_F38_SHIFT                        (6U)
#define CSL_SEM_SEMFLAGH_CLEAR_F38_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F38_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F39_MASK                         (0x00000080U)
#define CSL_SEM_SEMFLAGH_CLEAR_F39_SHIFT                        (7U)
#define CSL_SEM_SEMFLAGH_CLEAR_F39_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F39_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F40_MASK                         (0x00000100U)
#define CSL_SEM_SEMFLAGH_CLEAR_F40_SHIFT                        (8U)
#define CSL_SEM_SEMFLAGH_CLEAR_F40_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F40_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F41_MASK                         (0x00000200U)
#define CSL_SEM_SEMFLAGH_CLEAR_F41_SHIFT                        (9U)
#define CSL_SEM_SEMFLAGH_CLEAR_F41_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F41_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F42_MASK                         (0x00000400U)
#define CSL_SEM_SEMFLAGH_CLEAR_F42_SHIFT                        (10U)
#define CSL_SEM_SEMFLAGH_CLEAR_F42_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F42_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F43_MASK                         (0x00000800U)
#define CSL_SEM_SEMFLAGH_CLEAR_F43_SHIFT                        (11U)
#define CSL_SEM_SEMFLAGH_CLEAR_F43_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F43_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F44_MASK                         (0x00001000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F44_SHIFT                        (12U)
#define CSL_SEM_SEMFLAGH_CLEAR_F44_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F44_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F45_MASK                         (0x00002000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F45_SHIFT                        (13U)
#define CSL_SEM_SEMFLAGH_CLEAR_F45_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F45_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F46_MASK                         (0x00004000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F46_SHIFT                        (14U)
#define CSL_SEM_SEMFLAGH_CLEAR_F46_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F46_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F47_MASK                         (0x00008000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F47_SHIFT                        (15U)
#define CSL_SEM_SEMFLAGH_CLEAR_F47_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F47_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F48_MASK                         (0x00010000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F48_SHIFT                        (16U)
#define CSL_SEM_SEMFLAGH_CLEAR_F48_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F48_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F49_MASK                         (0x00020000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F49_SHIFT                        (17U)
#define CSL_SEM_SEMFLAGH_CLEAR_F49_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F49_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F50_MASK                         (0x00040000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F50_SHIFT                        (18U)
#define CSL_SEM_SEMFLAGH_CLEAR_F50_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F50_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F51_MASK                         (0x00080000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F51_SHIFT                        (19U)
#define CSL_SEM_SEMFLAGH_CLEAR_F51_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F51_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F52_MASK                         (0x00100000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F52_SHIFT                        (20U)
#define CSL_SEM_SEMFLAGH_CLEAR_F52_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F52_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F53_MASK                         (0x00200000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F53_SHIFT                        (21U)
#define CSL_SEM_SEMFLAGH_CLEAR_F53_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F53_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F54_MASK                         (0x00400000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F54_SHIFT                        (22U)
#define CSL_SEM_SEMFLAGH_CLEAR_F54_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F54_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F55_MASK                         (0x00800000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F55_SHIFT                        (23U)
#define CSL_SEM_SEMFLAGH_CLEAR_F55_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F55_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F56_MASK                         (0x01000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F56_SHIFT                        (24U)
#define CSL_SEM_SEMFLAGH_CLEAR_F56_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F56_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F57_MASK                         (0x02000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F57_SHIFT                        (25U)
#define CSL_SEM_SEMFLAGH_CLEAR_F57_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F57_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F58_MASK                         (0x04000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F58_SHIFT                        (26U)
#define CSL_SEM_SEMFLAGH_CLEAR_F58_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F58_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F59_MASK                         (0x08000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F59_SHIFT                        (27U)
#define CSL_SEM_SEMFLAGH_CLEAR_F59_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F59_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F60_MASK                         (0x10000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F60_SHIFT                        (28U)
#define CSL_SEM_SEMFLAGH_CLEAR_F60_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F60_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F61_MASK                         (0x20000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F61_SHIFT                        (29U)
#define CSL_SEM_SEMFLAGH_CLEAR_F61_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F61_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F62_MASK                         (0x40000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F62_SHIFT                        (30U)
#define CSL_SEM_SEMFLAGH_CLEAR_F62_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F62_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_F63_MASK                         (0x80000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F63_SHIFT                        (31U)
#define CSL_SEM_SEMFLAGH_CLEAR_F63_RESETVAL                     (0x00000000U)
#define CSL_SEM_SEMFLAGH_CLEAR_F63_MAX                          (0x00000001U)

#define CSL_SEM_SEMFLAGH_CLEAR_RESETVAL                         (0x00000000U)

/* SEMFLAGH_SET */

#define CSL_SEM_SEMFLAGH_SET_F32_MASK                           (0x00000001U)
#define CSL_SEM_SEMFLAGH_SET_F32_SHIFT                          (0U)
#define CSL_SEM_SEMFLAGH_SET_F32_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F32_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F33_MASK                           (0x00000002U)
#define CSL_SEM_SEMFLAGH_SET_F33_SHIFT                          (1U)
#define CSL_SEM_SEMFLAGH_SET_F33_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F33_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F34_MASK                           (0x00000004U)
#define CSL_SEM_SEMFLAGH_SET_F34_SHIFT                          (2U)
#define CSL_SEM_SEMFLAGH_SET_F34_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F34_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F35_MASK                           (0x00000008U)
#define CSL_SEM_SEMFLAGH_SET_F35_SHIFT                          (3U)
#define CSL_SEM_SEMFLAGH_SET_F35_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F35_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F36_MASK                           (0x00000010U)
#define CSL_SEM_SEMFLAGH_SET_F36_SHIFT                          (4U)
#define CSL_SEM_SEMFLAGH_SET_F36_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F36_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F37_MASK                           (0x00000020U)
#define CSL_SEM_SEMFLAGH_SET_F37_SHIFT                          (5U)
#define CSL_SEM_SEMFLAGH_SET_F37_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F37_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F38_MASK                           (0x00000040U)
#define CSL_SEM_SEMFLAGH_SET_F38_SHIFT                          (6U)
#define CSL_SEM_SEMFLAGH_SET_F38_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F38_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F39_MASK                           (0x00000080U)
#define CSL_SEM_SEMFLAGH_SET_F39_SHIFT                          (7U)
#define CSL_SEM_SEMFLAGH_SET_F39_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F39_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F40_MASK                           (0x00000100U)
#define CSL_SEM_SEMFLAGH_SET_F40_SHIFT                          (8U)
#define CSL_SEM_SEMFLAGH_SET_F40_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F40_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F41_MASK                           (0x00000200U)
#define CSL_SEM_SEMFLAGH_SET_F41_SHIFT                          (9U)
#define CSL_SEM_SEMFLAGH_SET_F41_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F41_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F42_MASK                           (0x00000400U)
#define CSL_SEM_SEMFLAGH_SET_F42_SHIFT                          (10U)
#define CSL_SEM_SEMFLAGH_SET_F42_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F42_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F43_MASK                           (0x00000800U)
#define CSL_SEM_SEMFLAGH_SET_F43_SHIFT                          (11U)
#define CSL_SEM_SEMFLAGH_SET_F43_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F43_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F44_MASK                           (0x00001000U)
#define CSL_SEM_SEMFLAGH_SET_F44_SHIFT                          (12U)
#define CSL_SEM_SEMFLAGH_SET_F44_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F44_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F45_MASK                           (0x00002000U)
#define CSL_SEM_SEMFLAGH_SET_F45_SHIFT                          (13U)
#define CSL_SEM_SEMFLAGH_SET_F45_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F45_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F46_MASK                           (0x00004000U)
#define CSL_SEM_SEMFLAGH_SET_F46_SHIFT                          (14U)
#define CSL_SEM_SEMFLAGH_SET_F46_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F46_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F47_MASK                           (0x00008000U)
#define CSL_SEM_SEMFLAGH_SET_F47_SHIFT                          (15U)
#define CSL_SEM_SEMFLAGH_SET_F47_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F47_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F48_MASK                           (0x00010000U)
#define CSL_SEM_SEMFLAGH_SET_F48_SHIFT                          (16U)
#define CSL_SEM_SEMFLAGH_SET_F48_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F48_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F49_MASK                           (0x00020000U)
#define CSL_SEM_SEMFLAGH_SET_F49_SHIFT                          (17U)
#define CSL_SEM_SEMFLAGH_SET_F49_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F49_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F50_MASK                           (0x00040000U)
#define CSL_SEM_SEMFLAGH_SET_F50_SHIFT                          (18U)
#define CSL_SEM_SEMFLAGH_SET_F50_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F50_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F51_MASK                           (0x00080000U)
#define CSL_SEM_SEMFLAGH_SET_F51_SHIFT                          (19U)
#define CSL_SEM_SEMFLAGH_SET_F51_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F51_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F52_MASK                           (0x00100000U)
#define CSL_SEM_SEMFLAGH_SET_F52_SHIFT                          (20U)
#define CSL_SEM_SEMFLAGH_SET_F52_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F52_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F53_MASK                           (0x00200000U)
#define CSL_SEM_SEMFLAGH_SET_F53_SHIFT                          (21U)
#define CSL_SEM_SEMFLAGH_SET_F53_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F53_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F54_MASK                           (0x00400000U)
#define CSL_SEM_SEMFLAGH_SET_F54_SHIFT                          (22U)
#define CSL_SEM_SEMFLAGH_SET_F54_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F54_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F55_MASK                           (0x00800000U)
#define CSL_SEM_SEMFLAGH_SET_F55_SHIFT                          (23U)
#define CSL_SEM_SEMFLAGH_SET_F55_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F55_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F56_MASK                           (0x01000000U)
#define CSL_SEM_SEMFLAGH_SET_F56_SHIFT                          (24U)
#define CSL_SEM_SEMFLAGH_SET_F56_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F56_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F57_MASK                           (0x02000000U)
#define CSL_SEM_SEMFLAGH_SET_F57_SHIFT                          (25U)
#define CSL_SEM_SEMFLAGH_SET_F57_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F57_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F58_MASK                           (0x04000000U)
#define CSL_SEM_SEMFLAGH_SET_F58_SHIFT                          (26U)
#define CSL_SEM_SEMFLAGH_SET_F58_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F58_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F59_MASK                           (0x08000000U)
#define CSL_SEM_SEMFLAGH_SET_F59_SHIFT                          (27U)
#define CSL_SEM_SEMFLAGH_SET_F59_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F59_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F60_MASK                           (0x10000000U)
#define CSL_SEM_SEMFLAGH_SET_F60_SHIFT                          (28U)
#define CSL_SEM_SEMFLAGH_SET_F60_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F60_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F61_MASK                           (0x20000000U)
#define CSL_SEM_SEMFLAGH_SET_F61_SHIFT                          (29U)
#define CSL_SEM_SEMFLAGH_SET_F61_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F61_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F62_MASK                           (0x40000000U)
#define CSL_SEM_SEMFLAGH_SET_F62_SHIFT                          (30U)
#define CSL_SEM_SEMFLAGH_SET_F62_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F62_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_F63_MASK                           (0x80000000U)
#define CSL_SEM_SEMFLAGH_SET_F63_SHIFT                          (31U)
#define CSL_SEM_SEMFLAGH_SET_F63_RESETVAL                       (0x00000000U)
#define CSL_SEM_SEMFLAGH_SET_F63_MAX                            (0x00000001U)

#define CSL_SEM_SEMFLAGH_SET_RESETVAL                           (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
