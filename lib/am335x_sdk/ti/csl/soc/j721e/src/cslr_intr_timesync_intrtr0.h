/********************************************************************
*
* TIMESYNC_INTRTR0 INTERRUPT MAP. header file
*
* Copyright (C) 2015-2019 Texas Instruments Incorporated.
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
#ifndef CSLR_TIMESYNC_INTRTR0_INTERRUPT_MAP_H_
#define CSLR_TIMESYNC_INTRTR0_INTERRUPT_MAP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

/*
* List of intr sources for receiver: TIMESYNC_INTRTR0
*/

#define CSLR_TIMESYNC_INTRTR0_IN_GTC0_GTC_PUSH_EVENT_0                                             (1U)
#define CSLR_GTC0_GTC_PUSH_EVENT_TIMESYNC_INTRTR0_IN_1                                             (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_TIMER14_TIMER_PWM_0                                               (2U)
#define CSLR_TIMER14_TIMER_PWM_TIMESYNC_INTRTR0_IN_2                                               (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_TIMER15_TIMER_PWM_0                                               (3U)
#define CSLR_TIMER15_TIMER_PWM_TIMESYNC_INTRTR0_IN_3                                               (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_GENF0_0                                              (4U)
#define CSLR_NAVSS0_CPTS0_GENF0_TIMESYNC_INTRTR0_IN_4                                              (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_GENF1_0                                              (5U)
#define CSLR_NAVSS0_CPTS0_GENF1_TIMESYNC_INTRTR0_IN_5                                              (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_GENF2_0                                              (6U)
#define CSLR_NAVSS0_CPTS0_GENF2_TIMESYNC_INTRTR0_IN_6                                              (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_GENF3_0                                              (7U)
#define CSLR_NAVSS0_CPTS0_GENF3_TIMESYNC_INTRTR0_IN_7                                              (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_GENF4_0                                              (8U)
#define CSLR_NAVSS0_CPTS0_GENF4_TIMESYNC_INTRTR0_IN_8                                              (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_GENF5_0                                              (9U)
#define CSLR_NAVSS0_CPTS0_GENF5_TIMESYNC_INTRTR0_IN_9                                              (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE0_PCIE_CPTS_GENF0_0                                           (10U)
#define CSLR_PCIE0_PCIE_CPTS_GENF0_TIMESYNC_INTRTR0_IN_10                                          (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE1_PCIE_CPTS_GENF0_0                                           (11U)
#define CSLR_PCIE1_PCIE_CPTS_GENF0_TIMESYNC_INTRTR0_IN_11                                          (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE2_PCIE_CPTS_GENF0_0                                           (12U)
#define CSLR_PCIE2_PCIE_CPTS_GENF0_TIMESYNC_INTRTR0_IN_12                                          (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE3_PCIE_CPTS_GENF0_0                                           (13U)
#define CSLR_PCIE3_PCIE_CPTS_GENF0_TIMESYNC_INTRTR0_IN_13                                          (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_CPSW0_CPTS_GENF0_0                                                (14U)
#define CSLR_CPSW0_CPTS_GENF0_TIMESYNC_INTRTR0_IN_14                                               (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_CPSW0_CPTS_GENF1_0                                                (15U)
#define CSLR_CPSW0_CPTS_GENF1_TIMESYNC_INTRTR0_IN_15                                               (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_MCU_CPSW0_CPTS_GENF0_0                                            (16U)
#define CSLR_MCU_CPSW0_CPTS_GENF0_TIMESYNC_INTRTR0_IN_16                                           (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_MCU_CPSW0_CPTS_GENF1_0                                            (17U)
#define CSLR_MCU_CPSW0_CPTS_GENF1_TIMESYNC_INTRTR0_IN_17                                           (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE0_PCIE_CPTS_HW1_PUSH_0                                        (20U)
#define CSLR_PCIE0_PCIE_CPTS_HW1_PUSH_TIMESYNC_INTRTR0_IN_20                                       (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE1_PCIE_CPTS_HW1_PUSH_0                                        (21U)
#define CSLR_PCIE1_PCIE_CPTS_HW1_PUSH_TIMESYNC_INTRTR0_IN_21                                       (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE2_PCIE_CPTS_HW1_PUSH_0                                        (22U)
#define CSLR_PCIE2_PCIE_CPTS_HW1_PUSH_TIMESYNC_INTRTR0_IN_22                                       (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE3_PCIE_CPTS_HW1_PUSH_0                                        (23U)
#define CSLR_PCIE3_PCIE_CPTS_HW1_PUSH_TIMESYNC_INTRTR0_IN_23                                       (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PRU_ICSSG0_PR1_EDC0_SYNC0_OUT_0                                   (24U)
#define CSLR_PRU_ICSSG0_PR1_EDC0_SYNC0_OUT_TIMESYNC_INTRTR0_IN_24                                  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PRU_ICSSG0_PR1_EDC0_SYNC1_OUT_0                                   (25U)
#define CSLR_PRU_ICSSG0_PR1_EDC0_SYNC1_OUT_TIMESYNC_INTRTR0_IN_25                                  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PRU_ICSSG0_PR1_EDC1_SYNC0_OUT_0                                   (26U)
#define CSLR_PRU_ICSSG0_PR1_EDC1_SYNC0_OUT_TIMESYNC_INTRTR0_IN_26                                  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PRU_ICSSG0_PR1_EDC1_SYNC1_OUT_0                                   (27U)
#define CSLR_PRU_ICSSG0_PR1_EDC1_SYNC1_OUT_TIMESYNC_INTRTR0_IN_27                                  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PRU_ICSSG1_PR1_EDC0_SYNC0_OUT_0                                   (28U)
#define CSLR_PRU_ICSSG1_PR1_EDC0_SYNC0_OUT_TIMESYNC_INTRTR0_IN_28                                  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PRU_ICSSG1_PR1_EDC0_SYNC1_OUT_0                                   (29U)
#define CSLR_PRU_ICSSG1_PR1_EDC0_SYNC1_OUT_TIMESYNC_INTRTR0_IN_29                                  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PRU_ICSSG1_PR1_EDC1_SYNC0_OUT_0                                   (30U)
#define CSLR_PRU_ICSSG1_PR1_EDC1_SYNC0_OUT_TIMESYNC_INTRTR0_IN_30                                  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PRU_ICSSG1_PR1_EDC1_SYNC1_OUT_0                                   (31U)
#define CSLR_PRU_ICSSG1_PR1_EDC1_SYNC1_OUT_TIMESYNC_INTRTR0_IN_31                                  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE0_PCIE_CPTS_SYNC_0                                            (32U)
#define CSLR_PCIE0_PCIE_CPTS_SYNC_TIMESYNC_INTRTR0_IN_32                                           (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE1_PCIE_CPTS_SYNC_0                                            (33U)
#define CSLR_PCIE1_PCIE_CPTS_SYNC_TIMESYNC_INTRTR0_IN_33                                           (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE2_PCIE_CPTS_SYNC_0                                            (34U)
#define CSLR_PCIE2_PCIE_CPTS_SYNC_TIMESYNC_INTRTR0_IN_34                                           (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE3_PCIE_CPTS_SYNC_0                                            (35U)
#define CSLR_PCIE3_PCIE_CPTS_SYNC_TIMESYNC_INTRTR0_IN_35                                           (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_SYNC_0                                               (36U)
#define CSLR_NAVSS0_CPTS0_SYNC_TIMESYNC_INTRTR0_IN_36                                              (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_CPSW0_CPTS_SYNC_0                                                 (37U)
#define CSLR_CPSW0_CPTS_SYNC_TIMESYNC_INTRTR0_IN_37                                                (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_MCU_CPSW0_CPTS_SYNC_0                                             (38U)
#define CSLR_MCU_CPSW0_CPTS_SYNC_TIMESYNC_INTRTR0_IN_38                                            (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_TIMER16_TIMER_PWM_0                                               (40U)
#define CSLR_TIMER16_TIMER_PWM_TIMESYNC_INTRTR0_IN_40                                              (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_TIMER17_TIMER_PWM_0                                               (41U)
#define CSLR_TIMER17_TIMER_PWM_TIMESYNC_INTRTR0_IN_41                                              (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_TIMER18_TIMER_PWM_0                                               (42U)
#define CSLR_TIMER18_TIMER_PWM_TIMESYNC_INTRTR0_IN_42                                              (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_TIMER19_TIMER_PWM_0                                               (43U)
#define CSLR_TIMER19_TIMER_PWM_TIMESYNC_INTRTR0_IN_43                                              (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_CPTS0_HW1TSPUSHIN_CPTS0_HW1TSPUSH_0                   (44U)
#define CSLR_PINFUNCTION_CPTS0_HW1TSPUSHIN_CPTS0_HW1TSPUSH_TIMESYNC_INTRTR0_IN_44                  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_CPTS0_HW2TSPUSHIN_CPTS0_HW2TSPUSH_0                   (45U)
#define CSLR_PINFUNCTION_CPTS0_HW2TSPUSHIN_CPTS0_HW2TSPUSH_TIMESYNC_INTRTR0_IN_45                  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_MCU_CPTS0_HW1TSPUSHIN_MCU_CPTS0_HW1TSPUSH_0           (46U)
#define CSLR_PINFUNCTION_MCU_CPTS0_HW1TSPUSHIN_MCU_CPTS0_HW1TSPUSH_TIMESYNC_INTRTR0_IN_46          (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_MCU_CPTS0_HW2TSPUSHIN_MCU_CPTS0_HW2TSPUSH_0           (47U)
#define CSLR_PINFUNCTION_MCU_CPTS0_HW2TSPUSHIN_MCU_CPTS0_HW2TSPUSH_TIMESYNC_INTRTR0_IN_47          (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_PRG0_IEP0_EDC_LATCH_IN0IN_PRG0_IEP0_EDC_LATCH_IN0_0   (48U)
#define CSLR_PINFUNCTION_PRG0_IEP0_EDC_LATCH_IN0IN_PRG0_IEP0_EDC_LATCH_IN0_TIMESYNC_INTRTR0_IN_48  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_PRG0_IEP0_EDC_LATCH_IN1IN_PRG0_IEP0_EDC_LATCH_IN1_0   (49U)
#define CSLR_PINFUNCTION_PRG0_IEP0_EDC_LATCH_IN1IN_PRG0_IEP0_EDC_LATCH_IN1_TIMESYNC_INTRTR0_IN_49  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_PRG0_IEP1_EDC_LATCH_IN0IN_PRG0_IEP1_EDC_LATCH_IN0_0   (50U)
#define CSLR_PINFUNCTION_PRG0_IEP1_EDC_LATCH_IN0IN_PRG0_IEP1_EDC_LATCH_IN0_TIMESYNC_INTRTR0_IN_50  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_PRG0_IEP1_EDC_LATCH_IN1IN_PRG0_IEP1_EDC_LATCH_IN1_0   (51U)
#define CSLR_PINFUNCTION_PRG0_IEP1_EDC_LATCH_IN1IN_PRG0_IEP1_EDC_LATCH_IN1_TIMESYNC_INTRTR0_IN_51  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_PRG1_IEP0_EDC_LATCH_IN0IN_PRG1_IEP0_EDC_LATCH_IN0_0   (52U)
#define CSLR_PINFUNCTION_PRG1_IEP0_EDC_LATCH_IN0IN_PRG1_IEP0_EDC_LATCH_IN0_TIMESYNC_INTRTR0_IN_52  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_PRG1_IEP0_EDC_LATCH_IN1IN_PRG1_IEP0_EDC_LATCH_IN1_0   (53U)
#define CSLR_PINFUNCTION_PRG1_IEP0_EDC_LATCH_IN1IN_PRG1_IEP0_EDC_LATCH_IN1_TIMESYNC_INTRTR0_IN_53  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_PRG1_IEP1_EDC_LATCH_IN0IN_PRG1_IEP1_EDC_LATCH_IN0_0   (54U)
#define CSLR_PINFUNCTION_PRG1_IEP1_EDC_LATCH_IN0IN_PRG1_IEP1_EDC_LATCH_IN0_TIMESYNC_INTRTR0_IN_54  (0U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_PRG1_IEP1_EDC_LATCH_IN1IN_PRG1_IEP1_EDC_LATCH_IN1_0   (55U)
#define CSLR_PINFUNCTION_PRG1_IEP1_EDC_LATCH_IN1IN_PRG1_IEP1_EDC_LATCH_IN1_TIMESYNC_INTRTR0_IN_55  (0U)

#ifdef __cplusplus
}
#endif
#endif /* CSLR_TIMESYNC_INTRTR0_INTERRUPT_MAP_H_ */

