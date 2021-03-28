/********************************************************************
*
* MAIN2MCU_LVL_INTRTR0 INTERRUPT MAP. header file
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
#ifndef CSLR_MAIN2MCU_LVL_INTRTR0_INTERRUPT_MAP_H_
#define CSLR_MAIN2MCU_LVL_INTRTR0_INTERRUPT_MAP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

/*
* List of intr sources for receiver: MAIN2MCU_LVL_INTRTR0
*/

#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_GLUELOGIC_EXT_INTN_GLUE_EXT_INT_LVL_0                         (1U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_CTRL_MMR0_ACCESS_ERR_0                                        (6U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_ELM0_ELM_POROCPSINTERRUPT_LVL_0                               (7U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_GPMC0_GPMC_SINTERRUPT_0                                       (8U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_DDR0_DDRSS_PLL_FREQ_CHANGE_REQ_0                              (9U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_DDR0_DDRSS_CONTROLLER_0                                       (10U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_DDR0_DDRSS_V2A_OTHER_ERR_LVL_0                                (11U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_DDR0_DDRSS_HS_PHY_GLOBAL_ERROR_0                              (12U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN0_MCANSS_MCAN_LVL_INT_0                                   (16U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN0_MCANSS_MCAN_LVL_INT_1                                   (17U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN0_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (18U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN1_MCANSS_MCAN_LVL_INT_0                                   (19U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN1_MCANSS_MCAN_LVL_INT_1                                   (20U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN1_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (21U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN2_MCANSS_MCAN_LVL_INT_0                                   (22U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN2_MCANSS_MCAN_LVL_INT_1                                   (23U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN2_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (24U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN3_MCANSS_MCAN_LVL_INT_0                                   (25U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN3_MCANSS_MCAN_LVL_INT_1                                   (26U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN3_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (27U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MMCSD0_EMMCSS_INTR_0                                          (28U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MMCSD1_EMMCSDSS_INTR_0                                        (29U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCSPI0_INTR_SPI_0                                             (48U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCSPI1_INTR_SPI_0                                             (49U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCSPI2_INTR_SPI_0                                             (50U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCSPI3_INTR_SPI_0                                             (51U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCSPI4_INTR_SPI_0                                             (52U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCSPI5_INTR_SPI_0                                             (53U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCSPI6_INTR_SPI_0                                             (54U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCSPI7_INTR_SPI_0                                             (55U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_I2C0_POINTRPEND_0                                             (56U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_I2C1_POINTRPEND_0                                             (57U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_I2C2_POINTRPEND_0                                             (58U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_I2C3_POINTRPEND_0                                             (59U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_I2C4_POINTRPEND_0                                             (60U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_I2C5_POINTRPEND_0                                             (61U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_I2C6_POINTRPEND_0                                             (62U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_PCIE1_PCIE_PHY_LEVEL_0                                        (73U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_PCIE1_PCIE_LOCAL_LEVEL_0                                      (74U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_PCIE1_PCIE_CPTS_PEND_0                                        (75U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_DCC0_INTR_DONE_LEVEL_0                                        (88U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_DCC1_INTR_DONE_LEVEL_0                                        (89U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_DCC2_INTR_DONE_LEVEL_0                                        (90U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_DCC3_INTR_DONE_LEVEL_0                                        (91U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_DCC4_INTR_DONE_LEVEL_0                                        (92U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_DCC5_INTR_DONE_LEVEL_0                                        (93U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_DCC6_INTR_DONE_LEVEL_0                                        (94U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_UART0_USART_IRQ_0                                             (96U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_UART1_USART_IRQ_0                                             (97U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_UART2_USART_IRQ_0                                             (98U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_UART3_USART_IRQ_0                                             (99U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_UART4_USART_IRQ_0                                             (100U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_UART5_USART_IRQ_0                                             (101U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_UART6_USART_IRQ_0                                             (102U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_UART7_USART_IRQ_0                                             (103U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_UART8_USART_IRQ_0                                             (104U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_UART9_USART_IRQ_0                                             (105U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER0_INTR_PEND_0                                            (108U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER1_INTR_PEND_0                                            (109U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER2_INTR_PEND_0                                            (110U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER3_INTR_PEND_0                                            (111U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER4_INTR_PEND_0                                            (112U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER5_INTR_PEND_0                                            (113U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER6_INTR_PEND_0                                            (114U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER7_INTR_PEND_0                                            (115U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER8_INTR_PEND_0                                            (116U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER9_INTR_PEND_0                                            (117U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER10_INTR_PEND_0                                           (118U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER11_INTR_PEND_0                                           (119U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER12_INTR_PEND_0                                           (120U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER13_INTR_PEND_0                                           (121U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER14_INTR_PEND_0                                           (122U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER15_INTR_PEND_0                                           (123U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER16_INTR_PEND_0                                           (124U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER17_INTR_PEND_0                                           (125U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER18_INTR_PEND_0                                           (126U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_TIMER19_INTR_PEND_0                                           (127U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_USB0_IRQ_0                                                    (128U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_USB0_IRQ_1                                                    (129U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_USB0_IRQ_2                                                    (130U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_USB0_IRQ_3                                                    (131U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_USB0_IRQ_4                                                    (132U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_USB0_IRQ_5                                                    (133U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_USB0_IRQ_6                                                    (134U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_USB0_IRQ_7                                                    (135U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_USB0_OTGIRQ_0                                                 (152U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_GLUELOGIC_MAIN_CBASS_INTR_OR_GLUE_MAIN_CBASS_AGG_ERR_INTR_0   (156U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_USB0_HOST_SYSTEM_ERROR_0                                      (157U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN14_MCANSS_MCAN_LVL_INT_0                                  (160U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN14_MCANSS_MCAN_LVL_INT_1                                  (161U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN14_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                       (162U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN15_MCANSS_MCAN_LVL_INT_0                                  (163U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN15_MCANSS_MCAN_LVL_INT_1                                  (164U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN15_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                       (165U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_CBASS_INFRA0_DEFAULT_ERR_INTR_0                               (167U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_CBASS_INFRA_NON_SAFE0_DEFAULT_ERR_INTR_0                      (168U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN16_MCANSS_MCAN_LVL_INT_0                                  (170U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN16_MCANSS_MCAN_LVL_INT_1                                  (171U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN16_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                       (172U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN17_MCANSS_MCAN_LVL_INT_0                                  (173U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN17_MCANSS_MCAN_LVL_INT_1                                  (174U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN17_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                       (175U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCASP0_XMIT_INTR_PEND_0                                       (176U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCASP0_REC_INTR_PEND_0                                        (177U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCASP1_XMIT_INTR_PEND_0                                       (178U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCASP1_REC_INTR_PEND_0                                        (179U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCASP2_XMIT_INTR_PEND_0                                       (180U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCASP2_REC_INTR_PEND_0                                        (181U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_DEBUGSS0_AQCMPINTR_LEVEL_0                                    (217U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_I3C0_I3C__INT_0                                               (220U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_CPSW0_STAT_PEND_0                                             (221U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_CPSW0_MDIO_PEND_0                                             (222U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_CPSW0_EVNT_PEND_0                                             (223U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN4_MCANSS_MCAN_LVL_INT_0                                   (278U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN4_MCANSS_MCAN_LVL_INT_1                                   (279U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN4_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (280U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN5_MCANSS_MCAN_LVL_INT_0                                   (281U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN5_MCANSS_MCAN_LVL_INT_1                                   (282U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN5_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (283U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN6_MCANSS_MCAN_LVL_INT_0                                   (284U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN6_MCANSS_MCAN_LVL_INT_1                                   (285U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN6_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (286U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN7_MCANSS_MCAN_LVL_INT_0                                   (287U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN7_MCANSS_MCAN_LVL_INT_1                                   (288U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN7_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (289U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN8_MCANSS_MCAN_LVL_INT_0                                   (290U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN8_MCANSS_MCAN_LVL_INT_1                                   (291U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN8_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (292U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN9_MCANSS_MCAN_LVL_INT_0                                   (293U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN9_MCANSS_MCAN_LVL_INT_1                                   (294U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN9_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                        (295U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN10_MCANSS_MCAN_LVL_INT_0                                  (296U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN10_MCANSS_MCAN_LVL_INT_1                                  (297U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN10_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                       (298U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN11_MCANSS_MCAN_LVL_INT_0                                  (299U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN11_MCANSS_MCAN_LVL_INT_1                                  (300U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN11_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                       (301U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN12_MCANSS_MCAN_LVL_INT_0                                  (302U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN12_MCANSS_MCAN_LVL_INT_1                                  (303U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN12_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                       (304U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN13_MCANSS_MCAN_LVL_INT_0                                  (305U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN13_MCANSS_MCAN_LVL_INT_1                                  (306U)
#define CSLR_MAIN2MCU_LVL_INTRTR0_IN_MCAN13_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0                       (307U)

#ifdef __cplusplus
}
#endif
#endif /* CSLR_MAIN2MCU_LVL_INTRTR0_INTERRUPT_MAP_H_ */

