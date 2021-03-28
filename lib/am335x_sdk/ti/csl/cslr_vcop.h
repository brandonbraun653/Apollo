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
#ifndef CSLR_VCOP_H_
#define CSLR_VCOP_H_

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
    volatile Uint32 PID;
    volatile Uint32 CTRL;
    volatile Uint32 STS;
    volatile Uint32 MAX_ITERS;
    volatile Uint32 ERROR;
    volatile Uint8  RSVD0[12];
    volatile Uint32 VLOOP_PTR;
    volatile Uint32 PARAM_PTR;
    volatile Uint8  RSVD1[8];
    volatile Uint32 I0_I1;
    volatile Uint32 I2_I3;
    volatile Uint32 I4;
    volatile Uint8  RSVD2[4];
    volatile Uint32 LD_PTR0;
    volatile Uint32 LD_PTR1;
    volatile Uint32 LD_PTR2;
    volatile Uint32 LD_PTR3;
    volatile Uint32 LD_PTR4;
    volatile Uint32 LD_PTR5;
    volatile Uint32 LD_PTR6;
    volatile Uint32 LD_PTR7;
    volatile Uint32 ST_PTR0;
    volatile Uint32 ST_PTR1;
    volatile Uint32 ST_PTR2;
    volatile Uint32 ST_PTR3;
    volatile Uint32 ST_PTR4;
    volatile Uint32 ST_PTR5;
    volatile Uint32 ST_PTR6;
    volatile Uint32 ST_PTR7;
} CSL_VcopRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* PID */
#define CSL_VCOP_PID                                            (0x0U)

/* CTRL */
#define CSL_VCOP_CTRL                                           (0x4U)

/* STS */
#define CSL_VCOP_STS                                            (0x8U)

/* MAX_ITERS */
#define CSL_VCOP_MAX_ITERS                                      (0xCU)

/* ERROR */
#define CSL_VCOP_ERROR                                          (0x10U)

/* VLOOP_PTR */
#define CSL_VCOP_VLOOP_PTR                                      (0x20U)

/* PARAM_PTR */
#define CSL_VCOP_PARAM_PTR                                      (0x24U)

/* I0_I1 */
#define CSL_VCOP_I0_I1                                          (0x30U)

/* I2_I3 */
#define CSL_VCOP_I2_I3                                          (0x34U)

/* I4 */
#define CSL_VCOP_I4                                             (0x38U)

/* LD_PTR0 */
#define CSL_VCOP_LD_PTR0                                        (0x40U)

/* LD_PTR1 */
#define CSL_VCOP_LD_PTR1                                        (0x44U)

/* LD_PTR2 */
#define CSL_VCOP_LD_PTR2                                        (0x48U)

/* LD_PTR3 */
#define CSL_VCOP_LD_PTR3                                        (0x4CU)

/* LD_PTR4 */
#define CSL_VCOP_LD_PTR4                                        (0x50U)

/* LD_PTR5 */
#define CSL_VCOP_LD_PTR5                                        (0x54U)

/* LD_PTR6 */
#define CSL_VCOP_LD_PTR6                                        (0x58U)

/* LD_PTR7 */
#define CSL_VCOP_LD_PTR7                                        (0x5CU)

/* ST_PTR0 */
#define CSL_VCOP_ST_PTR0                                        (0x60U)

/* ST_PTR1 */
#define CSL_VCOP_ST_PTR1                                        (0x64U)

/* ST_PTR2 */
#define CSL_VCOP_ST_PTR2                                        (0x68U)

/* ST_PTR3 */
#define CSL_VCOP_ST_PTR3                                        (0x6CU)

/* ST_PTR4 */
#define CSL_VCOP_ST_PTR4                                        (0x70U)

/* ST_PTR5 */
#define CSL_VCOP_ST_PTR5                                        (0x74U)

/* ST_PTR6 */
#define CSL_VCOP_ST_PTR6                                        (0x78U)

/* ST_PTR7 */
#define CSL_VCOP_ST_PTR7                                        (0x7CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* PID */

#define CSL_VCOP_PID_PID_MASK                                   (0xFFFFFFFFU)
#define CSL_VCOP_PID_PID_SHIFT                                  (0U)
#define CSL_VCOP_PID_PID_RESETVAL                               (0x00000000U)
#define CSL_VCOP_PID_PID_MAX                                    (0xffffffffU)

#define CSL_VCOP_PID_RESETVAL                                   (0x00000000U)

/* CTRL */

#define CSL_VCOP_CTRL_STEP_EN_MASK                              (0x00000001U)
#define CSL_VCOP_CTRL_STEP_EN_SHIFT                             (0U)
#define CSL_VCOP_CTRL_STEP_EN_RESETVAL                          (0x00000000U)
#define CSL_VCOP_CTRL_STEP_EN_MAX                               (0x00000001U)

#define CSL_VCOP_CTRL_STEP_GO_MASK                              (0x00000002U)
#define CSL_VCOP_CTRL_STEP_GO_SHIFT                             (1U)
#define CSL_VCOP_CTRL_STEP_GO_RESETVAL                          (0x00000000U)
#define CSL_VCOP_CTRL_STEP_GO_MAX                               (0x00000001U)

#define CSL_VCOP_CTRL_RESVD_MASK                                (0xFFFFFFFCU)
#define CSL_VCOP_CTRL_RESVD_SHIFT                               (2U)
#define CSL_VCOP_CTRL_RESVD_RESETVAL                            (0x00000000U)
#define CSL_VCOP_CTRL_RESVD_MAX                                 (0x3fffffffU)

#define CSL_VCOP_CTRL_RESETVAL                                  (0x00000000U)

/* STS */

#define CSL_VCOP_STS_STEP_RDY_MASK                              (0x00000001U)
#define CSL_VCOP_STS_STEP_RDY_SHIFT                             (0U)
#define CSL_VCOP_STS_STEP_RDY_RESETVAL                          (0x00000000U)
#define CSL_VCOP_STS_STEP_RDY_MAX                               (0x00000001U)

#define CSL_VCOP_STS_VEC_DONE_MASK                              (0x00000002U)
#define CSL_VCOP_STS_VEC_DONE_SHIFT                             (1U)
#define CSL_VCOP_STS_VEC_DONE_RESETVAL                          (0x00000000U)
#define CSL_VCOP_STS_VEC_DONE_MAX                               (0x00000001U)

#define CSL_VCOP_STS_VEC_RDY_MASK                               (0x00000004U)
#define CSL_VCOP_STS_VEC_RDY_SHIFT                              (2U)
#define CSL_VCOP_STS_VEC_RDY_RESETVAL                           (0x00000000U)
#define CSL_VCOP_STS_VEC_RDY_MAX                                (0x00000001U)

#define CSL_VCOP_STS_RESVD_MASK                                 (0xFFFFFFF8U)
#define CSL_VCOP_STS_RESVD_SHIFT                                (3U)
#define CSL_VCOP_STS_RESVD_RESETVAL                             (0x00000000U)
#define CSL_VCOP_STS_RESVD_MAX                                  (0x1fffffffU)

#define CSL_VCOP_STS_RESETVAL                                   (0x00000000U)

/* MAX_ITERS */

#define CSL_VCOP_MAX_ITERS_MAX_ITERS_MASK                       (0x0000FFFFU)
#define CSL_VCOP_MAX_ITERS_MAX_ITERS_SHIFT                      (0U)
#define CSL_VCOP_MAX_ITERS_MAX_ITERS_RESETVAL                   (0x00000000U)
#define CSL_VCOP_MAX_ITERS_MAX_ITERS_MAX                        (0x0000ffffU)

#define CSL_VCOP_MAX_ITERS_RESVD_MASK                           (0xFFFF0000U)
#define CSL_VCOP_MAX_ITERS_RESVD_SHIFT                          (16U)
#define CSL_VCOP_MAX_ITERS_RESVD_RESETVAL                       (0x00000000U)
#define CSL_VCOP_MAX_ITERS_RESVD_MAX                            (0x0000ffffU)

#define CSL_VCOP_MAX_ITERS_RESETVAL                             (0x00000000U)

/* ERROR */

#define CSL_VCOP_ERROR_ERR_ST0_MASK                             (0x00000001U)
#define CSL_VCOP_ERROR_ERR_ST0_SHIFT                            (0U)
#define CSL_VCOP_ERROR_ERR_ST0_RESETVAL                         (0x00000000U)
#define CSL_VCOP_ERROR_ERR_ST0_MAX                              (0x00000001U)

#define CSL_VCOP_ERROR_ERR_ST1_MASK                             (0x00000002U)
#define CSL_VCOP_ERROR_ERR_ST1_SHIFT                            (1U)
#define CSL_VCOP_ERROR_ERR_ST1_RESETVAL                         (0x00000000U)
#define CSL_VCOP_ERROR_ERR_ST1_MAX                              (0x00000001U)

#define CSL_VCOP_ERROR_ERR_ST2_MASK                             (0x00000004U)
#define CSL_VCOP_ERROR_ERR_ST2_SHIFT                            (2U)
#define CSL_VCOP_ERROR_ERR_ST2_RESETVAL                         (0x00000000U)
#define CSL_VCOP_ERROR_ERR_ST2_MAX                              (0x00000001U)

#define CSL_VCOP_ERROR_ERR_ST3_MASK                             (0x00000008U)
#define CSL_VCOP_ERROR_ERR_ST3_SHIFT                            (3U)
#define CSL_VCOP_ERROR_ERR_ST3_RESETVAL                         (0x00000000U)
#define CSL_VCOP_ERROR_ERR_ST3_MAX                              (0x00000001U)

#define CSL_VCOP_ERROR_ERR_ST4_MASK                             (0x00000010U)
#define CSL_VCOP_ERROR_ERR_ST4_SHIFT                            (4U)
#define CSL_VCOP_ERROR_ERR_ST4_RESETVAL                         (0x00000000U)
#define CSL_VCOP_ERROR_ERR_ST4_MAX                              (0x00000001U)

#define CSL_VCOP_ERROR_ERR_ST5_MASK                             (0x00000020U)
#define CSL_VCOP_ERROR_ERR_ST5_SHIFT                            (5U)
#define CSL_VCOP_ERROR_ERR_ST5_RESETVAL                         (0x00000000U)
#define CSL_VCOP_ERROR_ERR_ST5_MAX                              (0x00000001U)

#define CSL_VCOP_ERROR_ERR_ST6_MASK                             (0x00000040U)
#define CSL_VCOP_ERROR_ERR_ST6_SHIFT                            (6U)
#define CSL_VCOP_ERROR_ERR_ST6_RESETVAL                         (0x00000000U)
#define CSL_VCOP_ERROR_ERR_ST6_MAX                              (0x00000001U)

#define CSL_VCOP_ERROR_ERR_ST7_MASK                             (0x00000080U)
#define CSL_VCOP_ERROR_ERR_ST7_SHIFT                            (7U)
#define CSL_VCOP_ERROR_ERR_ST7_RESETVAL                         (0x00000000U)
#define CSL_VCOP_ERROR_ERR_ST7_MAX                              (0x00000001U)

#define CSL_VCOP_ERROR_ERR_DIS0_MASK                            (0x00010000U)
#define CSL_VCOP_ERROR_ERR_DIS0_SHIFT                           (16U)
#define CSL_VCOP_ERROR_ERR_DIS0_RESETVAL                        (0x00000000U)
#define CSL_VCOP_ERROR_ERR_DIS0_MAX                             (0x00000001U)

#define CSL_VCOP_ERROR_ERR_DIS1_MASK                            (0x00020000U)
#define CSL_VCOP_ERROR_ERR_DIS1_SHIFT                           (17U)
#define CSL_VCOP_ERROR_ERR_DIS1_RESETVAL                        (0x00000000U)
#define CSL_VCOP_ERROR_ERR_DIS1_MAX                             (0x00000001U)

#define CSL_VCOP_ERROR_ERR_DIS2_MASK                            (0x00040000U)
#define CSL_VCOP_ERROR_ERR_DIS2_SHIFT                           (18U)
#define CSL_VCOP_ERROR_ERR_DIS2_RESETVAL                        (0x00000000U)
#define CSL_VCOP_ERROR_ERR_DIS2_MAX                             (0x00000001U)

#define CSL_VCOP_ERROR_ERR_DIS3_MASK                            (0x00080000U)
#define CSL_VCOP_ERROR_ERR_DIS3_SHIFT                           (19U)
#define CSL_VCOP_ERROR_ERR_DIS3_RESETVAL                        (0x00000000U)
#define CSL_VCOP_ERROR_ERR_DIS3_MAX                             (0x00000001U)

#define CSL_VCOP_ERROR_ERR_DIS4_MASK                            (0x00100000U)
#define CSL_VCOP_ERROR_ERR_DIS4_SHIFT                           (20U)
#define CSL_VCOP_ERROR_ERR_DIS4_RESETVAL                        (0x00000000U)
#define CSL_VCOP_ERROR_ERR_DIS4_MAX                             (0x00000001U)

#define CSL_VCOP_ERROR_ERR_DIS5_MASK                            (0x00200000U)
#define CSL_VCOP_ERROR_ERR_DIS5_SHIFT                           (21U)
#define CSL_VCOP_ERROR_ERR_DIS5_RESETVAL                        (0x00000000U)
#define CSL_VCOP_ERROR_ERR_DIS5_MAX                             (0x00000001U)

#define CSL_VCOP_ERROR_ERR_DIS6_MASK                            (0x00400000U)
#define CSL_VCOP_ERROR_ERR_DIS6_SHIFT                           (22U)
#define CSL_VCOP_ERROR_ERR_DIS6_RESETVAL                        (0x00000000U)
#define CSL_VCOP_ERROR_ERR_DIS6_MAX                             (0x00000001U)

#define CSL_VCOP_ERROR_ERR_DIS7_MASK                            (0x00800000U)
#define CSL_VCOP_ERROR_ERR_DIS7_SHIFT                           (23U)
#define CSL_VCOP_ERROR_ERR_DIS7_RESETVAL                        (0x00000000U)
#define CSL_VCOP_ERROR_ERR_DIS7_MAX                             (0x00000001U)

#define CSL_VCOP_ERROR_RESVD1_MASK                              (0x0000FF00U)
#define CSL_VCOP_ERROR_RESVD1_SHIFT                             (8U)
#define CSL_VCOP_ERROR_RESVD1_RESETVAL                          (0x00000000U)
#define CSL_VCOP_ERROR_RESVD1_MAX                               (0x000000ffU)

#define CSL_VCOP_ERROR_RESVD2_MASK                              (0xFF000000U)
#define CSL_VCOP_ERROR_RESVD2_SHIFT                             (24U)
#define CSL_VCOP_ERROR_RESVD2_RESETVAL                          (0x00000000U)
#define CSL_VCOP_ERROR_RESVD2_MAX                               (0x000000ffU)

#define CSL_VCOP_ERROR_RESETVAL                                 (0x00000000U)

/* VLOOP_PTR */

#define CSL_VCOP_VLOOP_PTR_VLOOP_PTR_MASK                       (0xFFFFFFFFU)
#define CSL_VCOP_VLOOP_PTR_VLOOP_PTR_SHIFT                      (0U)
#define CSL_VCOP_VLOOP_PTR_VLOOP_PTR_RESETVAL                   (0x00000000U)
#define CSL_VCOP_VLOOP_PTR_VLOOP_PTR_MAX                        (0xffffffffU)

#define CSL_VCOP_VLOOP_PTR_RESETVAL                             (0x00000000U)

/* PARAM_PTR */

#define CSL_VCOP_PARAM_PTR_PARAM_PTR_MASK                       (0xFFFFFFFFU)
#define CSL_VCOP_PARAM_PTR_PARAM_PTR_SHIFT                      (0U)
#define CSL_VCOP_PARAM_PTR_PARAM_PTR_RESETVAL                   (0x00000000U)
#define CSL_VCOP_PARAM_PTR_PARAM_PTR_MAX                        (0xffffffffU)

#define CSL_VCOP_PARAM_PTR_RESETVAL                             (0x00000000U)

/* I0_I1 */

#define CSL_VCOP_I0_I1_I0_MASK                                  (0x0000FFFFU)
#define CSL_VCOP_I0_I1_I0_SHIFT                                 (0U)
#define CSL_VCOP_I0_I1_I0_RESETVAL                              (0x00000000U)
#define CSL_VCOP_I0_I1_I0_MAX                                   (0x0000ffffU)

#define CSL_VCOP_I0_I1_I1_MASK                                  (0xFFFF0000U)
#define CSL_VCOP_I0_I1_I1_SHIFT                                 (16U)
#define CSL_VCOP_I0_I1_I1_RESETVAL                              (0x00000000U)
#define CSL_VCOP_I0_I1_I1_MAX                                   (0x0000ffffU)

#define CSL_VCOP_I0_I1_RESETVAL                                 (0x00000000U)

/* I2_I3 */

#define CSL_VCOP_I2_I3_I2_MASK                                  (0x0000FFFFU)
#define CSL_VCOP_I2_I3_I2_SHIFT                                 (0U)
#define CSL_VCOP_I2_I3_I2_RESETVAL                              (0x00000000U)
#define CSL_VCOP_I2_I3_I2_MAX                                   (0x0000ffffU)

#define CSL_VCOP_I2_I3_I3_MASK                                  (0xFFFF0000U)
#define CSL_VCOP_I2_I3_I3_SHIFT                                 (16U)
#define CSL_VCOP_I2_I3_I3_RESETVAL                              (0x00000000U)
#define CSL_VCOP_I2_I3_I3_MAX                                   (0x0000ffffU)

#define CSL_VCOP_I2_I3_RESETVAL                                 (0x00000000U)

/* I4 */

#define CSL_VCOP_I4_I4_MASK                                     (0x0000FFFFU)
#define CSL_VCOP_I4_I4_SHIFT                                    (0U)
#define CSL_VCOP_I4_I4_RESETVAL                                 (0x00000000U)
#define CSL_VCOP_I4_I4_MAX                                      (0x0000ffffU)

#define CSL_VCOP_I4_RESVD_MASK                                  (0xFFFF0000U)
#define CSL_VCOP_I4_RESVD_SHIFT                                 (16U)
#define CSL_VCOP_I4_RESVD_RESETVAL                              (0x00000000U)
#define CSL_VCOP_I4_RESVD_MAX                                   (0x0000ffffU)

#define CSL_VCOP_I4_RESETVAL                                    (0x00000000U)

/* LD_PTR0 */

#define CSL_VCOP_LD_PTR0_LD_PTR1_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_LD_PTR0_LD_PTR1_SHIFT                          (0U)
#define CSL_VCOP_LD_PTR0_LD_PTR1_RESETVAL                       (0x00000000U)
#define CSL_VCOP_LD_PTR0_LD_PTR1_MAX                            (0xffffffffU)

#define CSL_VCOP_LD_PTR0_RESETVAL                               (0x00000000U)

/* LD_PTR1 */

#define CSL_VCOP_LD_PTR1_LD_PTR1_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_LD_PTR1_LD_PTR1_SHIFT                          (0U)
#define CSL_VCOP_LD_PTR1_LD_PTR1_RESETVAL                       (0x00000000U)
#define CSL_VCOP_LD_PTR1_LD_PTR1_MAX                            (0xffffffffU)

#define CSL_VCOP_LD_PTR1_RESETVAL                               (0x00000000U)

/* LD_PTR2 */

#define CSL_VCOP_LD_PTR2_LD_PTR2_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_LD_PTR2_LD_PTR2_SHIFT                          (0U)
#define CSL_VCOP_LD_PTR2_LD_PTR2_RESETVAL                       (0x00000000U)
#define CSL_VCOP_LD_PTR2_LD_PTR2_MAX                            (0xffffffffU)

#define CSL_VCOP_LD_PTR2_RESETVAL                               (0x00000000U)

/* LD_PTR3 */

#define CSL_VCOP_LD_PTR3_LD_PTR3_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_LD_PTR3_LD_PTR3_SHIFT                          (0U)
#define CSL_VCOP_LD_PTR3_LD_PTR3_RESETVAL                       (0x00000000U)
#define CSL_VCOP_LD_PTR3_LD_PTR3_MAX                            (0xffffffffU)

#define CSL_VCOP_LD_PTR3_RESETVAL                               (0x00000000U)

/* LD_PTR4 */

#define CSL_VCOP_LD_PTR4_LD_PTR4_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_LD_PTR4_LD_PTR4_SHIFT                          (0U)
#define CSL_VCOP_LD_PTR4_LD_PTR4_RESETVAL                       (0x00000000U)
#define CSL_VCOP_LD_PTR4_LD_PTR4_MAX                            (0xffffffffU)

#define CSL_VCOP_LD_PTR4_RESETVAL                               (0x00000000U)

/* LD_PTR5 */

#define CSL_VCOP_LD_PTR5_LD_PTR5_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_LD_PTR5_LD_PTR5_SHIFT                          (0U)
#define CSL_VCOP_LD_PTR5_LD_PTR5_RESETVAL                       (0x00000000U)
#define CSL_VCOP_LD_PTR5_LD_PTR5_MAX                            (0xffffffffU)

#define CSL_VCOP_LD_PTR5_RESETVAL                               (0x00000000U)

/* LD_PTR6 */

#define CSL_VCOP_LD_PTR6_LD_PTR6_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_LD_PTR6_LD_PTR6_SHIFT                          (0U)
#define CSL_VCOP_LD_PTR6_LD_PTR6_RESETVAL                       (0x00000000U)
#define CSL_VCOP_LD_PTR6_LD_PTR6_MAX                            (0xffffffffU)

#define CSL_VCOP_LD_PTR6_RESETVAL                               (0x00000000U)

/* LD_PTR7 */

#define CSL_VCOP_LD_PTR7_LD_PTR7_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_LD_PTR7_LD_PTR7_SHIFT                          (0U)
#define CSL_VCOP_LD_PTR7_LD_PTR7_RESETVAL                       (0x00000000U)
#define CSL_VCOP_LD_PTR7_LD_PTR7_MAX                            (0xffffffffU)

#define CSL_VCOP_LD_PTR7_RESETVAL                               (0x00000000U)

/* ST_PTR0 */

#define CSL_VCOP_ST_PTR0_ST_PTR0_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_ST_PTR0_ST_PTR0_SHIFT                          (0U)
#define CSL_VCOP_ST_PTR0_ST_PTR0_RESETVAL                       (0x00000000U)
#define CSL_VCOP_ST_PTR0_ST_PTR0_MAX                            (0xffffffffU)

#define CSL_VCOP_ST_PTR0_RESETVAL                               (0x00000000U)

/* ST_PTR1 */

#define CSL_VCOP_ST_PTR1_ST_PTR1_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_ST_PTR1_ST_PTR1_SHIFT                          (0U)
#define CSL_VCOP_ST_PTR1_ST_PTR1_RESETVAL                       (0x00000000U)
#define CSL_VCOP_ST_PTR1_ST_PTR1_MAX                            (0xffffffffU)

#define CSL_VCOP_ST_PTR1_RESETVAL                               (0x00000000U)

/* ST_PTR2 */

#define CSL_VCOP_ST_PTR2_ST_PTR2_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_ST_PTR2_ST_PTR2_SHIFT                          (0U)
#define CSL_VCOP_ST_PTR2_ST_PTR2_RESETVAL                       (0x00000000U)
#define CSL_VCOP_ST_PTR2_ST_PTR2_MAX                            (0xffffffffU)

#define CSL_VCOP_ST_PTR2_RESETVAL                               (0x00000000U)

/* ST_PTR3 */

#define CSL_VCOP_ST_PTR3_ST_PTR3_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_ST_PTR3_ST_PTR3_SHIFT                          (0U)
#define CSL_VCOP_ST_PTR3_ST_PTR3_RESETVAL                       (0x00000000U)
#define CSL_VCOP_ST_PTR3_ST_PTR3_MAX                            (0xffffffffU)

#define CSL_VCOP_ST_PTR3_RESETVAL                               (0x00000000U)

/* ST_PTR4 */

#define CSL_VCOP_ST_PTR4_ST_PTR4_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_ST_PTR4_ST_PTR4_SHIFT                          (0U)
#define CSL_VCOP_ST_PTR4_ST_PTR4_RESETVAL                       (0x00000000U)
#define CSL_VCOP_ST_PTR4_ST_PTR4_MAX                            (0xffffffffU)

#define CSL_VCOP_ST_PTR4_RESETVAL                               (0x00000000U)

/* ST_PTR5 */

#define CSL_VCOP_ST_PTR5_ST_PTR5_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_ST_PTR5_ST_PTR5_SHIFT                          (0U)
#define CSL_VCOP_ST_PTR5_ST_PTR5_RESETVAL                       (0x00000000U)
#define CSL_VCOP_ST_PTR5_ST_PTR5_MAX                            (0xffffffffU)

#define CSL_VCOP_ST_PTR5_RESETVAL                               (0x00000000U)

/* ST_PTR6 */

#define CSL_VCOP_ST_PTR6_ST_PTR6_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_ST_PTR6_ST_PTR6_SHIFT                          (0U)
#define CSL_VCOP_ST_PTR6_ST_PTR6_RESETVAL                       (0x00000000U)
#define CSL_VCOP_ST_PTR6_ST_PTR6_MAX                            (0xffffffffU)

#define CSL_VCOP_ST_PTR6_RESETVAL                               (0x00000000U)

/* ST_PTR7 */

#define CSL_VCOP_ST_PTR7_ST_PTR7_MASK                           (0xFFFFFFFFU)
#define CSL_VCOP_ST_PTR7_ST_PTR7_SHIFT                          (0U)
#define CSL_VCOP_ST_PTR7_ST_PTR7_RESETVAL                       (0x00000000U)
#define CSL_VCOP_ST_PTR7_ST_PTR7_MAX                            (0xffffffffU)

#define CSL_VCOP_ST_PTR7_RESETVAL                               (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
