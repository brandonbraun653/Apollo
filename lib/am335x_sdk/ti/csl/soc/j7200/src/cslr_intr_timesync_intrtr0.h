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
#define CSLR_TIMESYNC_INTRTR0_IN_TIMER14_TIMER_PWM_0                                               (2U)
#define CSLR_TIMESYNC_INTRTR0_IN_TIMER15_TIMER_PWM_0                                               (3U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_GENF0_0                                              (4U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_GENF1_0                                              (5U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_GENF2_0                                              (6U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_GENF3_0                                              (7U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_GENF4_0                                              (8U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_GENF5_0                                              (9U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE1_PCIE_CPTS_GENF0_0                                           (11U)
#define CSLR_TIMESYNC_INTRTR0_IN_CPSW0_CPTS_GENF0_0                                                (14U)
#define CSLR_TIMESYNC_INTRTR0_IN_CPSW0_CPTS_GENF1_0                                                (15U)
#define CSLR_TIMESYNC_INTRTR0_IN_MCU_CPSW0_CPTS_GENF0_0                                            (16U)
#define CSLR_TIMESYNC_INTRTR0_IN_MCU_CPSW0_CPTS_GENF1_0                                            (17U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE1_PCIE_CPTS_HW1_PUSH_0                                        (21U)
#define CSLR_TIMESYNC_INTRTR0_IN_PCIE1_PCIE_CPTS_SYNC_0                                            (33U)
#define CSLR_TIMESYNC_INTRTR0_IN_NAVSS0_CPTS0_SYNC_0                                               (36U)
#define CSLR_TIMESYNC_INTRTR0_IN_CPSW0_CPTS_SYNC_0                                                 (37U)
#define CSLR_TIMESYNC_INTRTR0_IN_MCU_CPSW0_CPTS_SYNC_0                                             (38U)
#define CSLR_TIMESYNC_INTRTR0_IN_TIMER16_TIMER_PWM_0                                               (40U)
#define CSLR_TIMESYNC_INTRTR0_IN_TIMER17_TIMER_PWM_0                                               (41U)
#define CSLR_TIMESYNC_INTRTR0_IN_TIMER18_TIMER_PWM_0                                               (42U)
#define CSLR_TIMESYNC_INTRTR0_IN_TIMER19_TIMER_PWM_0                                               (43U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_CPTS0_HW1TSPUSHIN_CPTS0_HW1TSPUSH_0                   (44U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_CPTS0_HW2TSPUSHIN_CPTS0_HW2TSPUSH_0                   (45U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_MCU_CPTS0_HW1TSPUSHIN_MCU_CPTS0_HW1TSPUSH_0           (46U)
#define CSLR_TIMESYNC_INTRTR0_IN_PINFUNCTION_MCU_CPTS0_HW2TSPUSHIN_MCU_CPTS0_HW2TSPUSH_0           (47U)

#ifdef __cplusplus
}
#endif
#endif /* CSLR_TIMESYNC_INTRTR0_INTERRUPT_MAP_H_ */

