/********************************************************************
*
* PRU_ICSSG1 INTERRUPT MAP. header file
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
#ifndef CSLR_PRU_ICSSG1_INTERRUPT_MAP_H_
#define CSLR_PRU_ICSSG1_INTERRUPT_MAP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

/*
* List of intr sources for receiver: PRU_ICSSG1
*/

#define CSLR_PRU_ICSSG1_PR1_EDC0_LATCH0_IN_TIMESYNC_INTRTR0_OUTL_12                                (0U)
#define CSLR_TIMESYNC_INTRTR0_OUTL_PRU_ICSSG1_PR1_EDC0_LATCH0_IN_0                                 (12U)
#define CSLR_PRU_ICSSG1_PR1_EDC0_LATCH1_IN_TIMESYNC_INTRTR0_OUTL_13                                (0U)
#define CSLR_TIMESYNC_INTRTR0_OUTL_PRU_ICSSG1_PR1_EDC0_LATCH1_IN_0                                 (13U)
#define CSLR_PRU_ICSSG1_PR1_EDC1_LATCH0_IN_TIMESYNC_INTRTR0_OUTL_14                                (0U)
#define CSLR_TIMESYNC_INTRTR0_OUTL_PRU_ICSSG1_PR1_EDC1_LATCH0_IN_0                                 (14U)
#define CSLR_PRU_ICSSG1_PR1_EDC1_LATCH1_IN_TIMESYNC_INTRTR0_OUTL_15                                (0U)
#define CSLR_TIMESYNC_INTRTR0_OUTL_PRU_ICSSG1_PR1_EDC1_LATCH1_IN_0                                 (15U)
#define CSLR_PRU_ICSSG1_PR1_IEP0_CAP_INTR_REQ_GPIOMUX_INTRTR0_OUTP_52                              (0U)
#define CSLR_PRU_ICSSG1_PR1_IEP1_CAP_INTR_REQ_GPIOMUX_INTRTR0_OUTP_58                              (0U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_CTRL_MMR0_IPC_SET22_IPC_SET_IPCFG_0                           (0U)
#define CSLR_PRU_ICSSG1_PR1_IEP0_CAP_INTR_REQ_GPIOMUX_INTRTR0_OUTP_53                              (1U)
#define CSLR_PRU_ICSSG1_PR1_IEP1_CAP_INTR_REQ_GPIOMUX_INTRTR0_OUTP_59                              (1U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_CTRL_MMR0_IPC_SET23_IPC_SET_IPCFG_0                           (1U)
#define CSLR_PRU_ICSSG1_PR1_IEP0_CAP_INTR_REQ_GPIOMUX_INTRTR0_OUTP_54                              (2U)
#define CSLR_PRU_ICSSG1_PR1_IEP1_CAP_INTR_REQ_GPIOMUX_INTRTR0_OUTP_60                              (2U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCU_ADC0_GEN_LEVEL_0                                          (2U)
#define CSLR_PRU_ICSSG1_PR1_IEP0_CAP_INTR_REQ_GPIOMUX_INTRTR0_OUTP_55                              (3U)
#define CSLR_PRU_ICSSG1_PR1_IEP1_CAP_INTR_REQ_GPIOMUX_INTRTR0_OUTP_61                              (3U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCU_ADC1_GEN_LEVEL_0                                          (3U)
#define CSLR_PRU_ICSSG1_PR1_IEP0_CAP_INTR_REQ_GPIOMUX_INTRTR0_OUTP_56                              (4U)
#define CSLR_PRU_ICSSG1_PR1_IEP1_CAP_INTR_REQ_GPIOMUX_INTRTR0_OUTP_62                              (4U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_PRU_ICSSG0_PR1_HOST_INTR_PEND_5                               (4U)
#define CSLR_PRU_ICSSG1_PR1_IEP0_CAP_INTR_REQ_GPIOMUX_INTRTR0_OUTP_57                              (5U)
#define CSLR_PRU_ICSSG1_PR1_IEP1_CAP_INTR_REQ_GPIOMUX_INTRTR0_OUTP_63                              (5U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_PRU_ICSSG0_PR1_HOST_INTR_PEND_6                               (5U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_PRU_ICSSG0_PR1_HOST_INTR_PEND_7                               (6U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_GPMC0_GPMC_SINTERRUPT_0                                       (7U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_ECAP1_ECAP_INT_0                                              (8U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_ECAP2_ECAP_INT_0                                              (9U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_GLUELOGIC_SOCA_INT_GLUE_SOCA_INT_0                            (10U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_GLUELOGIC_SOCB_INT_GLUE_SOCB_INT_0                            (11U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EHRPWM0_EPWM_ETINT_0                                          (12U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EHRPWM1_EPWM_ETINT_0                                          (13U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EHRPWM2_EPWM_ETINT_0                                          (14U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EHRPWM3_EPWM_ETINT_0                                          (15U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EHRPWM4_EPWM_ETINT_0                                          (16U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EHRPWM5_EPWM_ETINT_0                                          (17U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EHRPWM0_EPWM_TRIPZINT_0                                       (18U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EHRPWM1_EPWM_TRIPZINT_0                                       (19U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EHRPWM2_EPWM_TRIPZINT_0                                       (20U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EHRPWM3_EPWM_TRIPZINT_0                                       (21U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EHRPWM4_EPWM_TRIPZINT_0                                       (22U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EHRPWM5_EPWM_TRIPZINT_0                                       (23U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EQEP0_EQEP_INT_0                                              (24U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EQEP1_EQEP_INT_0                                              (25U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_EQEP2_EQEP_INT_0                                              (26U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_ECAP0_ECAP_INT_0                                              (27U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_I2C0_POINTRPEND_0                                             (28U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_I2C1_POINTRPEND_0                                             (29U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_I2C2_POINTRPEND_0                                             (30U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_I2C3_POINTRPEND_0                                             (31U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCSPI0_INTR_SPI_0                                             (32U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCSPI1_INTR_SPI_0                                             (33U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCSPI2_INTR_SPI_0                                             (34U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCSPI3_INTR_SPI_0                                             (35U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_NAVSS0_INTR_ROUTER_0_OUTL_INTR_392                            (46U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_NAVSS0_INTR_ROUTER_0_OUTL_INTR_393                            (47U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_NAVSS0_INTR_ROUTER_0_OUTL_INTR_394                            (48U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_NAVSS0_INTR_ROUTER_0_OUTL_INTR_395                            (49U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_NAVSS0_INTR_ROUTER_0_OUTL_INTR_396                            (50U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_NAVSS0_INTR_ROUTER_0_OUTL_INTR_397                            (51U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_NAVSS0_INTR_ROUTER_0_OUTL_INTR_398                            (52U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_NAVSS0_INTR_ROUTER_0_OUTL_INTR_399                            (53U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCASP0_XMIT_INTR_PEND_0                                       (54U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCASP0_REC_INTR_PEND_0                                        (55U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCASP1_XMIT_INTR_PEND_0                                       (56U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCASP1_REC_INTR_PEND_0                                        (57U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCASP2_XMIT_INTR_PEND_0                                       (58U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCASP2_REC_INTR_PEND_0                                        (59U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_UART0_USART_IRQ_0                                             (60U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_UART1_USART_IRQ_0                                             (61U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_UART2_USART_IRQ_0                                             (62U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_UART3_USART_IRQ_0                                             (63U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_UART4_USART_IRQ_0                                             (64U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_UART5_USART_IRQ_0                                             (65U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_UART6_USART_IRQ_0                                             (66U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_UART7_USART_IRQ_0                                             (67U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_UART8_USART_IRQ_0                                             (68U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_UART9_USART_IRQ_0                                             (69U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN7_MCANSS_MCAN_LVL_INT_0                                   (72U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN7_MCANSS_MCAN_LVL_INT_1                                   (73U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN7_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (74U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN8_MCANSS_MCAN_LVL_INT_0                                   (75U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN8_MCANSS_MCAN_LVL_INT_1                                   (76U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN8_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (77U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN9_MCANSS_MCAN_LVL_INT_0                                   (78U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN9_MCANSS_MCAN_LVL_INT_1                                   (79U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN9_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (80U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN10_MCANSS_MCAN_LVL_INT_0                                  (81U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN10_MCANSS_MCAN_LVL_INT_1                                  (82U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN10_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                       (83U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN11_MCANSS_MCAN_LVL_INT_0                                  (84U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN11_MCANSS_MCAN_LVL_INT_1                                  (85U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN11_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                       (86U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN12_MCANSS_MCAN_LVL_INT_0                                  (87U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN12_MCANSS_MCAN_LVL_INT_1                                  (88U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN12_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                       (89U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN13_MCANSS_MCAN_LVL_INT_0                                  (90U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN13_MCANSS_MCAN_LVL_INT_1                                  (91U)
#define CSLR_PRU_ICSSG1_PR1_SLV_INTR_MCAN13_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                       (92U)

#ifdef __cplusplus
}
#endif
#endif /* CSLR_PRU_ICSSG1_INTERRUPT_MAP_H_ */

