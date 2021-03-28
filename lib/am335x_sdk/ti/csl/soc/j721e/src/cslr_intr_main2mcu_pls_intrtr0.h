/********************************************************************
*
* MAIN2MCU_PLS_INTRTR0 INTERRUPT MAP. header file
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
#ifndef CSLR_MAIN2MCU_PLS_INTRTR0_INTERRUPT_MAP_H_
#define CSLR_MAIN2MCU_PLS_INTRTR0_INTERRUPT_MAP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

/*
* List of intr sources for receiver: MAIN2MCU_PLS_INTRTR0
*/

#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EHRPWM0_EPWM_ETINT_0                                          (2U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EHRPWM1_EPWM_ETINT_0                                          (3U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EHRPWM2_EPWM_ETINT_0                                          (4U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EHRPWM3_EPWM_ETINT_0                                          (5U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EHRPWM4_EPWM_ETINT_0                                          (6U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EHRPWM5_EPWM_ETINT_0                                          (7U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EHRPWM0_EPWM_TRIPZINT_0                                       (8U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EHRPWM1_EPWM_TRIPZINT_0                                       (9U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EHRPWM2_EPWM_TRIPZINT_0                                       (10U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EHRPWM3_EPWM_TRIPZINT_0                                       (11U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EHRPWM4_EPWM_TRIPZINT_0                                       (12U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EHRPWM5_EPWM_TRIPZINT_0                                       (13U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EQEP0_EQEP_INT_0                                              (14U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EQEP1_EQEP_INT_0                                              (15U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_EQEP2_EQEP_INT_0                                              (16U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_ECAP0_ECAP_INT_0                                              (17U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_ECAP1_ECAP_INT_0                                              (18U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_ECAP2_ECAP_INT_0                                              (19U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PRU_ICSSG0_PR1_TX_SOF_INTR_REQ_0                              (20U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PRU_ICSSG0_PR1_TX_SOF_INTR_REQ_1                              (21U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PRU_ICSSG0_PR1_RX_SOF_INTR_REQ_0                              (22U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PRU_ICSSG0_PR1_RX_SOF_INTR_REQ_1                              (23U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PRU_ICSSG1_PR1_TX_SOF_INTR_REQ_0                              (24U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PRU_ICSSG1_PR1_TX_SOF_INTR_REQ_1                              (25U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PRU_ICSSG1_PR1_RX_SOF_INTR_REQ_0                              (26U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PRU_ICSSG1_PR1_RX_SOF_INTR_REQ_1                              (27U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GLUELOGIC_SOCA_INT_GLUE_SOCA_INT_0                            (28U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GLUELOGIC_SOCB_INT_GLUE_SOCB_INT_0                            (29U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE0_PCIE_LEGACY_PULSE_0                                     (32U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE0_PCIE_DOWNSTREAM_PULSE_0                                 (33U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE0_PCIE_FLR_PULSE_0                                        (34U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE0_PCIE_ERROR_PULSE_0                                      (35U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE0_PCIE_LINK_STATE_PULSE_0                                 (36U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE0_PCIE_PWR_STATE_PULSE_0                                  (37U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE0_PCIE_PTM_VALID_PULSE_0                                  (38U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE0_PCIE_HOT_RESET_PULSE_0                                  (39U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE1_PCIE_LEGACY_PULSE_0                                     (40U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE1_PCIE_DOWNSTREAM_PULSE_0                                 (41U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE1_PCIE_FLR_PULSE_0                                        (42U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE1_PCIE_ERROR_PULSE_0                                      (43U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE1_PCIE_LINK_STATE_PULSE_0                                 (44U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE1_PCIE_PWR_STATE_PULSE_0                                  (45U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE1_PCIE_PTM_VALID_PULSE_0                                  (46U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE1_PCIE_HOT_RESET_PULSE_0                                  (47U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE2_PCIE_LEGACY_PULSE_0                                     (48U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE2_PCIE_DOWNSTREAM_PULSE_0                                 (49U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE2_PCIE_FLR_PULSE_0                                        (50U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE2_PCIE_ERROR_PULSE_0                                      (51U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE2_PCIE_LINK_STATE_PULSE_0                                 (52U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE2_PCIE_PWR_STATE_PULSE_0                                  (53U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE2_PCIE_PTM_VALID_PULSE_0                                  (54U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE2_PCIE_HOT_RESET_PULSE_0                                  (55U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE3_PCIE_LEGACY_PULSE_0                                     (56U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE3_PCIE_DOWNSTREAM_PULSE_0                                 (57U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE3_PCIE_FLR_PULSE_0                                        (58U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE3_PCIE_ERROR_PULSE_0                                      (59U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE3_PCIE_LINK_STATE_PULSE_0                                 (60U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE3_PCIE_PWR_STATE_PULSE_0                                  (61U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE3_PCIE_PTM_VALID_PULSE_0                                  (62U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_PCIE3_PCIE_HOT_RESET_PULSE_0                                  (63U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_0                                        (64U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_1                                        (65U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_2                                        (66U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_3                                        (67U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_4                                        (68U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_5                                        (69U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_6                                        (70U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_7                                        (71U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_8                                        (72U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_9                                        (73U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_10                                       (74U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_11                                       (75U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_12                                       (76U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_13                                       (77U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_14                                       (78U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_15                                       (79U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_16                                       (80U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_17                                       (81U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_18                                       (82U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_19                                       (83U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_20                                       (84U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_21                                       (85U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_22                                       (86U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_23                                       (87U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_24                                       (88U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_25                                       (89U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_26                                       (90U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_27                                       (91U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_28                                       (92U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_29                                       (93U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_30                                       (94U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_GPIOMUX_INTRTR0_OUTP_31                                       (95U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_CMPEVENT_INTRTR0_OUTP_16                                      (96U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_CMPEVENT_INTRTR0_OUTP_17                                      (97U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_CMPEVENT_INTRTR0_OUTP_18                                      (98U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_CMPEVENT_INTRTR0_OUTP_19                                      (99U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_CMPEVENT_INTRTR0_OUTP_20                                      (100U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_CMPEVENT_INTRTR0_OUTP_21                                      (101U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_CMPEVENT_INTRTR0_OUTP_22                                      (102U)
#define CSLR_MAIN2MCU_PLS_INTRTR0_IN_CMPEVENT_INTRTR0_OUTP_23                                      (103U)

#ifdef __cplusplus
}
#endif
#endif /* CSLR_MAIN2MCU_PLS_INTRTR0_INTERRUPT_MAP_H_ */

