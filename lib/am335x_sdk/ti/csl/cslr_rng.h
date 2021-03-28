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
#ifndef CSLR_RNG_H_
#define CSLR_RNG_H_

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
    volatile Uint32 TRNG_OUTPUT_L;
    volatile Uint32 TRNG_OUTPUT_H;
    volatile Uint32 TRNG_STATUS;
    volatile Uint32 TRNG_INTMASK;
    volatile Uint32 TRNG_INTACK;
    volatile Uint32 TRNG_CONTROL;
    volatile Uint32 TRNG_CONFIG;
    volatile Uint32 TRNG_ALARMCNT;
    volatile Uint32 TRNG_FROENABLE;
    volatile Uint32 TRNG_FRODETUNE;
    volatile Uint32 TRNG_ALARMMASK;
    volatile Uint32 TRNG_ALARMSTOP;
    volatile Uint32 TRNG_LFSR_L;
    volatile Uint32 TRNG_LFSR_M;
    volatile Uint32 TRNG_LFSR_H;
    volatile Uint32 TRNG_COUNT;
    volatile Uint32 TRNG_TEST;
    volatile Uint8  RSVD0[52];
    volatile Uint32 TRNG_OPTIONS;
    volatile Uint32 TRNG_EIP_REV;
    volatile Uint8  RSVD1[8024];
    volatile Uint32 MMR_STATUS_EN;
    volatile Uint8  RSVD2[4];
    volatile Uint32 TRNG_REV;
    volatile Uint32 SYS_CONFIG_REG;
    volatile Uint8  RSVD3[4];
    volatile Uint32 MMR_STATUS_SET;
    volatile Uint32 SOFT_RESET_REG;
    volatile Uint32 IRQ_EOI_REG;
    volatile Uint32 TRNG_IRQSTATUS;
} CSL_RngRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Output register for LSW randon number read access to LSW of 64-bit random
 * number */
#define CSL_RNG_TRNG_OUTPUT_L                                   (0x0U)

/* To Read MSW of Random Number read access to MSW of 64-bit random number */
#define CSL_RNG_TRNG_OUTPUT_H                                   (0x4U)

/* Status register */
#define CSL_RNG_TRNG_STATUS                                     (0x8U)

/* Interrupt mask register */
#define CSL_RNG_TRNG_INTMASK                                    (0xCU)

/* Interrupt acknowledge register */
#define CSL_RNG_TRNG_INTACK                                     (0x10U)

/* Control register */
#define CSL_RNG_TRNG_CONTROL                                    (0x14U)

/* Contains the seed */
#define CSL_RNG_TRNG_CONFIG                                     (0x18U)

/* Shutdown interr cntrl registers */
#define CSL_RNG_TRNG_ALARMCNT                                   (0x1CU)

/* FRO enable register */
#define CSL_RNG_TRNG_FROENABLE                                  (0x20U)

/* FRO de-tune bits register */
#define CSL_RNG_TRNG_FRODETUNE                                  (0x24U)

/* Alarm event log register */
#define CSL_RNG_TRNG_ALARMMASK                                  (0x28U)

/* Alarm shutdown register */
#define CSL_RNG_TRNG_ALARMSTOP                                  (0x2CU)

/* Main LFSR bits [31:0] */
#define CSL_RNG_TRNG_LFSR_L                                     (0x30U)

/* Main LFSR bits [63:32] */
#define CSL_RNG_TRNG_LFSR_M                                     (0x34U)

/* Main LFSR bits [80:64] */
#define CSL_RNG_TRNG_LFSR_H                                     (0x38U)

/* Revision number */
#define CSL_RNG_TRNG_COUNT                                      (0x3CU)

/* Engine options information */
#define CSL_RNG_TRNG_TEST                                       (0x40U)

/* Engine options information */
#define CSL_RNG_TRNG_OPTIONS                                    (0x78U)

/* EIP number and core revision */
#define CSL_RNG_TRNG_EIP_REV                                    (0x7CU)

/* A read only reg indicating the Overall interrupt status */
#define CSL_RNG_MMR_STATUS_EN                                   (0x1FD8U)

/* EIP-75t Module revision number */
#define CSL_RNG_TRNG_REV                                        (0x1FE0U)

/* SYS_CONFIG_REG */
#define CSL_RNG_SYS_CONFIG_REG                                  (0x1FE4U)

/* A read write register where the contents of mmr_status_raw can be read from
 * this address. */
#define CSL_RNG_MMR_STATUS_SET                                  (0x1FECU)

/* SOFT_RESET_REG */
#define CSL_RNG_SOFT_RESET_REG                                  (0x1FF0U)

/* To clear top_intr_req */
#define CSL_RNG_IRQ_EOI_REG                                     (0x1FF4U)

/* Interrupt Status */
#define CSL_RNG_TRNG_IRQSTATUS                                  (0x1FF8U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* TRNG_OUTPUT_L */

#define CSL_RNG_TRNG_OUTPUT_L_RNG_OUT_L_MASK                    (0xFFFFFFFFU)
#define CSL_RNG_TRNG_OUTPUT_L_RNG_OUT_L_SHIFT                   (0U)
#define CSL_RNG_TRNG_OUTPUT_L_RNG_OUT_L_RESETVAL                (0x00000000U)
#define CSL_RNG_TRNG_OUTPUT_L_RNG_OUT_L_MAX                     (0xffffffffU)

#define CSL_RNG_TRNG_OUTPUT_L_RESETVAL                          (0x00000000U)

/* TRNG_OUTPUT_H */

#define CSL_RNG_TRNG_OUTPUT_H_RNG_OUT_H_MASK                    (0xFFFFFFFFU)
#define CSL_RNG_TRNG_OUTPUT_H_RNG_OUT_H_SHIFT                   (0U)
#define CSL_RNG_TRNG_OUTPUT_H_RNG_OUT_H_RESETVAL                (0x00000000U)
#define CSL_RNG_TRNG_OUTPUT_H_RNG_OUT_H_MAX                     (0xffffffffU)

#define CSL_RNG_TRNG_OUTPUT_H_RESETVAL                          (0x00000000U)

/* TRNG_STATUS */

#define CSL_RNG_TRNG_STATUS_READY_MASK                          (0x00000001U)
#define CSL_RNG_TRNG_STATUS_READY_SHIFT                         (0U)
#define CSL_RNG_TRNG_STATUS_READY_RESETVAL                      (0x00000000U)
#define CSL_RNG_TRNG_STATUS_READY_MAX                           (0x00000001U)

#define CSL_RNG_TRNG_STATUS_SHUTDOWN_OFLO_MASK                  (0x00000002U)
#define CSL_RNG_TRNG_STATUS_SHUTDOWN_OFLO_SHIFT                 (1U)
#define CSL_RNG_TRNG_STATUS_SHUTDOWN_OFLO_RESETVAL              (0x00000000U)
#define CSL_RNG_TRNG_STATUS_SHUTDOWN_OFLO_MAX                   (0x00000001U)

#define CSL_RNG_TRNG_STATUS_NEED_CLOCK_MASK                     (0x80000000U)
#define CSL_RNG_TRNG_STATUS_NEED_CLOCK_SHIFT                    (31U)
#define CSL_RNG_TRNG_STATUS_NEED_CLOCK_RESETVAL                 (0x00000000U)
#define CSL_RNG_TRNG_STATUS_NEED_CLOCK_MAX                      (0x00000001U)

#define CSL_RNG_TRNG_STATUS_RESETVAL                            (0x00000000U)

/* TRNG_INTMASK */

#define CSL_RNG_TRNG_INTMASK_READY_MASK                         (0x00000001U)
#define CSL_RNG_TRNG_INTMASK_READY_SHIFT                        (0U)
#define CSL_RNG_TRNG_INTMASK_READY_RESETVAL                     (0x00000000U)
#define CSL_RNG_TRNG_INTMASK_READY_MAX                          (0x00000001U)

#define CSL_RNG_TRNG_INTMASK_SHUTDOWN_OFLO_MASK                 (0x00000002U)
#define CSL_RNG_TRNG_INTMASK_SHUTDOWN_OFLO_SHIFT                (1U)
#define CSL_RNG_TRNG_INTMASK_SHUTDOWN_OFLO_RESETVAL             (0x00000000U)
#define CSL_RNG_TRNG_INTMASK_SHUTDOWN_OFLO_MAX                  (0x00000001U)

#define CSL_RNG_TRNG_INTMASK_RESETVAL                           (0x00000000U)

/* TRNG_INTACK */

#define CSL_RNG_TRNG_INTACK_READY_MASK                          (0x00000001U)
#define CSL_RNG_TRNG_INTACK_READY_SHIFT                         (0U)
#define CSL_RNG_TRNG_INTACK_READY_RESETVAL                      (0x00000000U)
#define CSL_RNG_TRNG_INTACK_READY_MAX                           (0x00000001U)

#define CSL_RNG_TRNG_INTACK_SHUTDOWN_OFLO_MASK                  (0x00000002U)
#define CSL_RNG_TRNG_INTACK_SHUTDOWN_OFLO_SHIFT                 (1U)
#define CSL_RNG_TRNG_INTACK_SHUTDOWN_OFLO_RESETVAL              (0x00000000U)
#define CSL_RNG_TRNG_INTACK_SHUTDOWN_OFLO_MAX                   (0x00000001U)

#define CSL_RNG_TRNG_INTACK_RESETVAL                            (0x00000000U)

/* TRNG_CONTROL */

#define CSL_RNG_TRNG_CONTROL_TEST_MODE_MASK                     (0x00000002U)
#define CSL_RNG_TRNG_CONTROL_TEST_MODE_SHIFT                    (1U)
#define CSL_RNG_TRNG_CONTROL_TEST_MODE_RESETVAL                 (0x00000000U)
#define CSL_RNG_TRNG_CONTROL_TEST_MODE_MAX                      (0x00000001U)

#define CSL_RNG_TRNG_CONTROL_NO_LFSR_FB_MASK                    (0x00000004U)
#define CSL_RNG_TRNG_CONTROL_NO_LFSR_FB_SHIFT                   (2U)
#define CSL_RNG_TRNG_CONTROL_NO_LFSR_FB_RESETVAL                (0x00000000U)
#define CSL_RNG_TRNG_CONTROL_NO_LFSR_FB_MAX                     (0x00000001U)

#define CSL_RNG_TRNG_CONTROL_ENABLE_TRNG_MASK                   (0x00000400U)
#define CSL_RNG_TRNG_CONTROL_ENABLE_TRNG_SHIFT                  (10U)
#define CSL_RNG_TRNG_CONTROL_ENABLE_TRNG_RESETVAL               (0x00000000U)
#define CSL_RNG_TRNG_CONTROL_ENABLE_TRNG_MAX                    (0x00000001U)

#define CSL_RNG_TRNG_CONTROL_STARTUP_CYCLES_MASK                (0xFFFF0000U)
#define CSL_RNG_TRNG_CONTROL_STARTUP_CYCLES_SHIFT               (16U)
#define CSL_RNG_TRNG_CONTROL_STARTUP_CYCLES_RESETVAL            (0x00000000U)
#define CSL_RNG_TRNG_CONTROL_STARTUP_CYCLES_MAX                 (0x0000ffffU)

#define CSL_RNG_TRNG_CONTROL_RESETVAL                           (0x00000000U)

/* TRNG_CONFIG */

#define CSL_RNG_TRNG_CONFIG_MIN_REFILL_CYCLES_MASK              (0x000000FFU)
#define CSL_RNG_TRNG_CONFIG_MIN_REFILL_CYCLES_SHIFT             (0U)
#define CSL_RNG_TRNG_CONFIG_MIN_REFILL_CYCLES_RESETVAL          (0x00000000U)
#define CSL_RNG_TRNG_CONFIG_MIN_REFILL_CYCLES_MAX               (0x000000ffU)

#define CSL_RNG_TRNG_CONFIG_SAMPLE_DIV_MASK                     (0x00000F00U)
#define CSL_RNG_TRNG_CONFIG_SAMPLE_DIV_SHIFT                    (8U)
#define CSL_RNG_TRNG_CONFIG_SAMPLE_DIV_RESETVAL                 (0x00000000U)
#define CSL_RNG_TRNG_CONFIG_SAMPLE_DIV_MAX                      (0x0000000fU)

#define CSL_RNG_TRNG_CONFIG_MAX_REFILL_CYCLES_MASK              (0xFFFF0000U)
#define CSL_RNG_TRNG_CONFIG_MAX_REFILL_CYCLES_SHIFT             (16U)
#define CSL_RNG_TRNG_CONFIG_MAX_REFILL_CYCLES_RESETVAL          (0x00000000U)
#define CSL_RNG_TRNG_CONFIG_MAX_REFILL_CYCLES_MAX               (0x0000ffffU)

#define CSL_RNG_TRNG_CONFIG_RESETVAL                            (0x00000000U)

/* TRNG_ALARMCNT */

#define CSL_RNG_TRNG_ALARMCNT_ALARM_THRESHOLD_MASK              (0x000000FFU)
#define CSL_RNG_TRNG_ALARMCNT_ALARM_THRESHOLD_SHIFT             (0U)
#define CSL_RNG_TRNG_ALARMCNT_ALARM_THRESHOLD_RESETVAL          (0x000000ffU)
#define CSL_RNG_TRNG_ALARMCNT_ALARM_THRESHOLD_MAX               (0x000000ffU)

#define CSL_RNG_TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_MASK           (0x001F0000U)
#define CSL_RNG_TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_SHIFT          (16U)
#define CSL_RNG_TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_RESETVAL       (0x00000000U)
#define CSL_RNG_TRNG_ALARMCNT_SHUTDOWN_THRESHOLD_MAX            (0x0000001fU)

#define CSL_RNG_TRNG_ALARMCNT_SHUTDOWN_COUNT_MASK               (0x3F000000U)
#define CSL_RNG_TRNG_ALARMCNT_SHUTDOWN_COUNT_SHIFT              (24U)
#define CSL_RNG_TRNG_ALARMCNT_SHUTDOWN_COUNT_RESETVAL           (0x00000000U)
#define CSL_RNG_TRNG_ALARMCNT_SHUTDOWN_COUNT_MAX                (0x0000003fU)

#define CSL_RNG_TRNG_ALARMCNT_RESETVAL                          (0x000000ffU)

/* TRNG_FROENABLE */

#define CSL_RNG_TRNG_FROENABLE_FRO_ENABLES_MASK                 (0x00FFFFFFU)
#define CSL_RNG_TRNG_FROENABLE_FRO_ENABLES_SHIFT                (0U)
#define CSL_RNG_TRNG_FROENABLE_FRO_ENABLES_RESETVAL             (0x00ffffffU)
#define CSL_RNG_TRNG_FROENABLE_FRO_ENABLES_MAX                  (0x00ffffffU)

#define CSL_RNG_TRNG_FROENABLE_RESETVAL                         (0x00ffffffU)

/* TRNG_FRODETUNE */

#define CSL_RNG_TRNG_FRODETUNE_FRO_DETUNES_MASK                 (0x00FFFFFFU)
#define CSL_RNG_TRNG_FRODETUNE_FRO_DETUNES_SHIFT                (0U)
#define CSL_RNG_TRNG_FRODETUNE_FRO_DETUNES_RESETVAL             (0x00000000U)
#define CSL_RNG_TRNG_FRODETUNE_FRO_DETUNES_MAX                  (0x00ffffffU)

#define CSL_RNG_TRNG_FRODETUNE_RESETVAL                         (0x00000000U)

/* TRNG_ALARMMASK */

#define CSL_RNG_TRNG_ALARMMASK_FRO_ALARMMASKS_MASK              (0x00FFFFFFU)
#define CSL_RNG_TRNG_ALARMMASK_FRO_ALARMMASKS_SHIFT             (0U)
#define CSL_RNG_TRNG_ALARMMASK_FRO_ALARMMASKS_RESETVAL          (0x00000000U)
#define CSL_RNG_TRNG_ALARMMASK_FRO_ALARMMASKS_MAX               (0x00ffffffU)

#define CSL_RNG_TRNG_ALARMMASK_RESETVAL                         (0x00000000U)

/* TRNG_ALARMSTOP */

#define CSL_RNG_TRNG_ALARMSTOP_FRO_ALARMSTOPS_MASK              (0x00FFFFFFU)
#define CSL_RNG_TRNG_ALARMSTOP_FRO_ALARMSTOPS_SHIFT             (0U)
#define CSL_RNG_TRNG_ALARMSTOP_FRO_ALARMSTOPS_RESETVAL          (0x00000000U)
#define CSL_RNG_TRNG_ALARMSTOP_FRO_ALARMSTOPS_MAX               (0x00ffffffU)

#define CSL_RNG_TRNG_ALARMSTOP_RESETVAL                         (0x00000000U)

/* TRNG_LFSR_L */

#define CSL_RNG_TRNG_LFSR_L_LFSR_31_0_MASK                      (0xFFFFFFFFU)
#define CSL_RNG_TRNG_LFSR_L_LFSR_31_0_SHIFT                     (0U)
#define CSL_RNG_TRNG_LFSR_L_LFSR_31_0_RESETVAL                  (0x00000000U)
#define CSL_RNG_TRNG_LFSR_L_LFSR_31_0_MAX                       (0xffffffffU)

#define CSL_RNG_TRNG_LFSR_L_RESETVAL                            (0x00000000U)

/* TRNG_LFSR_M */

#define CSL_RNG_TRNG_LFSR_M_LFSR_63_32_MASK                     (0xFFFFFFFFU)
#define CSL_RNG_TRNG_LFSR_M_LFSR_63_32_SHIFT                    (0U)
#define CSL_RNG_TRNG_LFSR_M_LFSR_63_32_RESETVAL                 (0x00000000U)
#define CSL_RNG_TRNG_LFSR_M_LFSR_63_32_MAX                      (0xffffffffU)

#define CSL_RNG_TRNG_LFSR_M_RESETVAL                            (0x00000000U)

/* TRNG_LFSR_H */

#define CSL_RNG_TRNG_LFSR_H_LFSR_80_64_MASK                     (0xFFFFFFFFU)
#define CSL_RNG_TRNG_LFSR_H_LFSR_80_64_SHIFT                    (0U)
#define CSL_RNG_TRNG_LFSR_H_LFSR_80_64_RESETVAL                 (0x00000000U)
#define CSL_RNG_TRNG_LFSR_H_LFSR_80_64_MAX                      (0xffffffffU)

#define CSL_RNG_TRNG_LFSR_H_RESETVAL                            (0x00000000U)

/* TRNG_COUNT */

#define CSL_RNG_TRNG_COUNT_SAMPLE_COUNTER_MASK                  (0x00FFFFFFU)
#define CSL_RNG_TRNG_COUNT_SAMPLE_COUNTER_SHIFT                 (0U)
#define CSL_RNG_TRNG_COUNT_SAMPLE_COUNTER_RESETVAL              (0x00000000U)
#define CSL_RNG_TRNG_COUNT_SAMPLE_COUNTER_MAX                   (0x00ffffffU)

#define CSL_RNG_TRNG_COUNT_RESETVAL                             (0x00000000U)

/* TRNG_TEST */

#define CSL_RNG_TRNG_TEST_TEST_EN_OUT_MASK                      (0x00000001U)
#define CSL_RNG_TRNG_TEST_TEST_EN_OUT_SHIFT                     (0U)
#define CSL_RNG_TRNG_TEST_TEST_EN_OUT_RESETVAL                  (0x00000000U)
#define CSL_RNG_TRNG_TEST_TEST_EN_OUT_MAX                       (0x00000001U)

#define CSL_RNG_TRNG_TEST_TEST_PATT_FRO_MASK                    (0x00000002U)
#define CSL_RNG_TRNG_TEST_TEST_PATT_FRO_SHIFT                   (1U)
#define CSL_RNG_TRNG_TEST_TEST_PATT_FRO_RESETVAL                (0x00000000U)
#define CSL_RNG_TRNG_TEST_TEST_PATT_FRO_MAX                     (0x00000001U)

#define CSL_RNG_TRNG_TEST_TEST_PATT_DET_MASK                    (0x00000004U)
#define CSL_RNG_TRNG_TEST_TEST_PATT_DET_SHIFT                   (2U)
#define CSL_RNG_TRNG_TEST_TEST_PATT_DET_RESETVAL                (0x00000000U)
#define CSL_RNG_TRNG_TEST_TEST_PATT_DET_MAX                     (0x00000001U)

#define CSL_RNG_TRNG_TEST_TEST_SELECT_MASK                      (0x00001F00U)
#define CSL_RNG_TRNG_TEST_TEST_SELECT_SHIFT                     (8U)
#define CSL_RNG_TRNG_TEST_TEST_SELECT_RESETVAL                  (0x00000000U)
#define CSL_RNG_TRNG_TEST_TEST_SELECT_MAX                       (0x0000001fU)

#define CSL_RNG_TRNG_TEST_TEST_PATTERN_MASK                     (0x0FFF0000U)
#define CSL_RNG_TRNG_TEST_TEST_PATTERN_SHIFT                    (16U)
#define CSL_RNG_TRNG_TEST_TEST_PATTERN_RESETVAL                 (0x00000000U)
#define CSL_RNG_TRNG_TEST_TEST_PATTERN_MAX                      (0x00000fffU)

#define CSL_RNG_TRNG_TEST_RESETVAL                              (0x00000000U)

/* TRNG_OPTIONS */

#define CSL_RNG_TRNG_OPTIONS_NR_OF_FROS_MASK                    (0x00000FC0U)
#define CSL_RNG_TRNG_OPTIONS_NR_OF_FROS_SHIFT                   (6U)
#define CSL_RNG_TRNG_OPTIONS_NR_OF_FROS_RESETVAL                (0x00000018U)
#define CSL_RNG_TRNG_OPTIONS_NR_OF_FROS_MAX                     (0x0000003fU)

#define CSL_RNG_TRNG_OPTIONS_RESETVAL                           (0x00000600U)

/* TRNG_EIP_REV */

#define CSL_RNG_TRNG_EIP_REV_BASIC_EIP_NUMBER_MASK              (0x000000FFU)
#define CSL_RNG_TRNG_EIP_REV_BASIC_EIP_NUMBER_SHIFT             (0U)
#define CSL_RNG_TRNG_EIP_REV_BASIC_EIP_NUMBER_RESETVAL          (0x0000004bU)
#define CSL_RNG_TRNG_EIP_REV_BASIC_EIP_NUMBER_MAX               (0x000000ffU)

#define CSL_RNG_TRNG_EIP_REV_MAJOR_HW_REVISION_MASK             (0x0F000000U)
#define CSL_RNG_TRNG_EIP_REV_MAJOR_HW_REVISION_SHIFT            (24U)
#define CSL_RNG_TRNG_EIP_REV_MAJOR_HW_REVISION_RESETVAL         (0x00000002U)
#define CSL_RNG_TRNG_EIP_REV_MAJOR_HW_REVISION_MAX              (0x0000000fU)

#define CSL_RNG_TRNG_EIP_REV_HW_PATCH_LEVEL_MASK                (0x000F0000U)
#define CSL_RNG_TRNG_EIP_REV_HW_PATCH_LEVEL_SHIFT               (16U)
#define CSL_RNG_TRNG_EIP_REV_HW_PATCH_LEVEL_RESETVAL            (0x00000000U)
#define CSL_RNG_TRNG_EIP_REV_HW_PATCH_LEVEL_MAX                 (0x0000000fU)

#define CSL_RNG_TRNG_EIP_REV_MINOR_HW_REVISION_MASK             (0x00F00000U)
#define CSL_RNG_TRNG_EIP_REV_MINOR_HW_REVISION_SHIFT            (20U)
#define CSL_RNG_TRNG_EIP_REV_MINOR_HW_REVISION_RESETVAL         (0x00000000U)
#define CSL_RNG_TRNG_EIP_REV_MINOR_HW_REVISION_MAX              (0x0000000fU)

#define CSL_RNG_TRNG_EIP_REV_COMPLEMENT_OF_BASIC_EIP_NUMBER_MASK  (0x0000FF00U)
#define CSL_RNG_TRNG_EIP_REV_COMPLEMENT_OF_BASIC_EIP_NUMBER_SHIFT  (8U)
#define CSL_RNG_TRNG_EIP_REV_COMPLEMENT_OF_BASIC_EIP_NUMBER_RESETVAL  (0x000000b4U)
#define CSL_RNG_TRNG_EIP_REV_COMPLEMENT_OF_BASIC_EIP_NUMBER_MAX  (0x000000ffU)

#define CSL_RNG_TRNG_EIP_REV_RESETVAL                           (0x0200b44bU)

/* MMR_STATUS_EN */

#define CSL_RNG_MMR_STATUS_EN_READY_MASK                        (0x00000001U)
#define CSL_RNG_MMR_STATUS_EN_READY_SHIFT                       (0U)
#define CSL_RNG_MMR_STATUS_EN_READY_RESETVAL                    (0x00000000U)
#define CSL_RNG_MMR_STATUS_EN_READY_MAX                         (0x00000001U)

#define CSL_RNG_MMR_STATUS_EN_SHUTDOWN_OFLO_MASK                (0x00000002U)
#define CSL_RNG_MMR_STATUS_EN_SHUTDOWN_OFLO_SHIFT               (1U)
#define CSL_RNG_MMR_STATUS_EN_SHUTDOWN_OFLO_RESETVAL            (0x00000000U)
#define CSL_RNG_MMR_STATUS_EN_SHUTDOWN_OFLO_MAX                 (0x00000001U)

#define CSL_RNG_MMR_STATUS_EN_RESETVAL                          (0x00000000U)

/* TRNG_REV */

#define CSL_RNG_TRNG_REV_REVISION_MASK                          (0x000000FFU)
#define CSL_RNG_TRNG_REV_REVISION_SHIFT                         (0U)
#define CSL_RNG_TRNG_REV_REVISION_RESETVAL                      (0x00000020U)
#define CSL_RNG_TRNG_REV_REVISION_MAX                           (0x000000ffU)

#define CSL_RNG_TRNG_REV_RESETVAL                               (0x00000020U)

/* SYS_CONFIG_REG */

#define CSL_RNG_SYS_CONFIG_REG_IDLE_TYPE_MASK                   (0x00000018U)
#define CSL_RNG_SYS_CONFIG_REG_IDLE_TYPE_SHIFT                  (3U)
#define CSL_RNG_SYS_CONFIG_REG_IDLE_TYPE_RESETVAL               (0x00000000U)
#define CSL_RNG_SYS_CONFIG_REG_IDLE_TYPE_MAX                    (0x00000003U)

#define CSL_RNG_SYS_CONFIG_REG_AUTOIDLE_MASK                    (0x00000001U)
#define CSL_RNG_SYS_CONFIG_REG_AUTOIDLE_SHIFT                   (0U)
#define CSL_RNG_SYS_CONFIG_REG_AUTOIDLE_RESETVAL                (0x00000000U)
#define CSL_RNG_SYS_CONFIG_REG_AUTOIDLE_MAX                     (0x00000001U)

#define CSL_RNG_SYS_CONFIG_REG_RESETVAL                         (0x00000000U)

/* MMR_STATUS_SET */

#define CSL_RNG_MMR_STATUS_SET_SW_INTR_STATUS_SET_MASK          (0x00000003U)
#define CSL_RNG_MMR_STATUS_SET_SW_INTR_STATUS_SET_SHIFT         (0U)
#define CSL_RNG_MMR_STATUS_SET_SW_INTR_STATUS_SET_RESETVAL      (0x00000000U)
#define CSL_RNG_MMR_STATUS_SET_SW_INTR_STATUS_SET_MAX           (0x00000003U)

#define CSL_RNG_MMR_STATUS_SET_RESETVAL                         (0x00000000U)

/* SOFT_RESET_REG */

#define CSL_RNG_SOFT_RESET_REG_SOFT_RESET_MASK                  (0x00000001U)
#define CSL_RNG_SOFT_RESET_REG_SOFT_RESET_SHIFT                 (0U)
#define CSL_RNG_SOFT_RESET_REG_SOFT_RESET_RESETVAL              (0x00000000U)
#define CSL_RNG_SOFT_RESET_REG_SOFT_RESET_MAX                   (0x00000001U)

#define CSL_RNG_SOFT_RESET_REG_RESETVAL                         (0x00000000U)

/* IRQ_EOI_REG */

#define CSL_RNG_IRQ_EOI_REG_PULSE_INT_CLEAR_MASK                (0x00000001U)
#define CSL_RNG_IRQ_EOI_REG_PULSE_INT_CLEAR_SHIFT               (0U)
#define CSL_RNG_IRQ_EOI_REG_PULSE_INT_CLEAR_RESETVAL            (0x00000000U)
#define CSL_RNG_IRQ_EOI_REG_PULSE_INT_CLEAR_MAX                 (0x00000001U)

#define CSL_RNG_IRQ_EOI_REG_RESETVAL                            (0x00000000U)

/* TRNG_IRQSTATUS */

#define CSL_RNG_TRNG_IRQSTATUS_TRNGIRQEN_MASK                   (0x00000001U)
#define CSL_RNG_TRNG_IRQSTATUS_TRNGIRQEN_SHIFT                  (0U)
#define CSL_RNG_TRNG_IRQSTATUS_TRNGIRQEN_RESETVAL               (0x00000000U)
#define CSL_RNG_TRNG_IRQSTATUS_TRNGIRQEN_MAX                    (0x00000001U)

#define CSL_RNG_TRNG_IRQSTATUS_RESETVAL                         (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
