/*
 * Auto-generated CSL section
 */
/*
 *
 * Copyright (C) 2013 - 2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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
#ifndef CSLR_INTERRUPT_H
#define CSLR_INTERRUPT_H

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Auto-generated CSL section
 */
/******************************************************************************\
* Interrupt Event IDs
\******************************************************************************/

/**
 * @brief   Interrupt Event IDs
 */

#define INTC_EVENT_CNT 127
/* Output of event combiner 0, for events 1 to 31                             */
#define    CSL_INTC_EVENTID_EVT0                (0)
/* Output of event combiner 0, for events 32 to 63                            */
#define    CSL_INTC_EVENTID_EVT1                (1)
/* Output of event combiner 0, for events 64 to 95                            */
#define    CSL_INTC_EVENTID_EVT2                (2)
/* Output of event combiner 0, for events 96 to 127                           */
#define    CSL_INTC_EVENTID_EVT3                (3)

/* Timer 64P0 lower counter interrupt                                         */
#define    CSL_INTC_EVENTID_T64P0_TINT12        (4)

/* SYSCFG CHIPSIG Register Interrupt                                          */
#define    CSL_INTC_EVENTID_BOOTCFGINT0         (5)

#define    CSL_INTC_EVENTID_EHRPWM0             (7)

/* CC Completion Interrupt for region 1                                       */
#define    CSL_INTC_EVENTID_EDMA3_0_CC0_INT1    (8)
/* EMU interrupt                                                              */
#define    CSL_INTC_EVENTID_EMU_DTDMA           (9)

/* HiResTimer Trip Zone Interrupt                                             */
#define    CSL_INTC_EVENTID_EHRPWM0TZ           (10)

/* EMU real time data exchange receive complete                               */
#define    CSL_INTC_EVENTID_EMU_RTDXRX          (11)
/* EMU RTDX transmit complete                                                 */
#define    CSL_INTC_EVENTID_EMU_RTDXTX          (12)

/* IDMA Channel 0 Interrupt                                                   */
#define    CSL_INTC_EVENTID_IDMA0               (13)
/* IDMA Channel 1 Interrupt                                                   */
#define    CSL_INTC_EVENTID_IDMA1               (14)

/* mmcsd0 mmcsd interrupt                                                     */
#define    CSL_INTC_EVENTID_MMCSD0_INT0         (15)
/* mmcsd0 SDIO interrupt                                                      */
#define    CSL_INTC_EVENTID_MMCSD0_INT1         (16)

#define    CSL_INTC_EVENTID_EHRPWM1             (18)

/* USB Interrupt                                                              */
#define    CSL_INTC_EVENTID_USBINT0             (19)
#define    CSL_INTC_EVENTID_USB1_HCINT          (20)
#define    CSL_INTC_EVENTID_USB1_RWAKEUP        (21)

#define    CSL_INTC_EVENTID_EHRPWM1TZ           (23)

/* SATA interrupt                                                             */
#define    CSL_INTC_EVENTID_SATAINT             (24)

/* Timer 64P2 COMBINED counter interrupt                                      */
#define    CSL_INTC_EVENTID_T64P2_TINTALL       (25)

/* EMAC Interrupt                                                             */
#define     CSL_INTC_EVENTID_EMAC_RXTHRHC0      (26)
#define     CSL_INTC_EVENTID_EMAC_RXC0          (27)
#define     CSL_INTC_EVENTID_EMAC_TXC0          (28)
#define     CSL_INTC_EVENTID_EMAC_MISCC0        (29)
#define     CSL_INTC_EVENTID_EMAC_RXTHRHC1      (30)
#define     CSL_INTC_EVENTID_EMAC_RXC1          (31)
#define     CSL_INTC_EVENTID_EMAC_TXC1          (32)
#define     CSL_INTC_EVENTID_EMAC_MISCC1        (33)

/* UHPI DSPI Interrupt                                                        */
#define     CSL_INTC_EVENTID_UHPI_DSPINT        (34)

/* I2C interrupt                                                              */
#define    CSL_INTC_EVENTID_I2CINT0             (36)

/* SPI interrupt                                                              */
#define    CSL_INTC_EVENTID_SPIINT0             (37)

/* UART interrupt                                                             */
#define    CSL_INTC_EVENTID_UARTINT0            (38)

/* Timer 64P1 lower counter interrupt                                         */
#define    CSL_INTC_EVENTID_T64P1_TINT12        (40)

/* GPIO BANK 1 interrupt                                                      */
#define    CSL_INTC_EVENTID_GPIO_BNK1_INT       (41)

#define    CSL_INTC_EVENTID_I2CINT1             (42)

/* SPI interrupt                                                              */
#define    CSL_INTC_EVENTID_SPIINT1             (43)

/* ECAP0 interrupt                                                            */
#define    CSL_INTC_EVENTID_ECAPINT0            (45)

/* UART INTERRUPT                                                             */
#define    CSL_INTC_EVENTID_UARTINT1            (46)

/* ECAP1 interrupt                                                            */
#define    CSL_INTC_EVENTID_ECAPINT1            (47)

/* Timer 64P1 higher counter interrupt                                        */
#define    CSL_INTC_EVENTID_T64P1_TINT34        (48)

/* GPIO BANK 2 interrupt                                                      */
#define    CSL_INTC_EVENTID_GPIO_BNK2_INT       (49)

/* ECAP2 interrupt                                                            */
#define    CSL_INTC_EVENTID_ECAPINT2            (51)

/* GPIO BANK 3 interrupt                                                      */
#define    CSL_INTC_EVENTID_GPIO_BNK3_INT       (52)

/* mmcsd1 SDIO interrupt                                                      */
#define    CSL_INTC_EVENTID_MMCSD1_INT1         (53)

/* GPIO BANK 4 interrupt                                                      */
#define    CSL_INTC_EVENTID_GPIO_BNK4_INT       (54)

/* EMIFA Error Interrupt                                                      */
#define    CSL_INTC_EVENTID_EMIFAINT            (55)

/* EDMA3 CC Interrupt                                                         */
#define    CSL_INTC_EVENTID_EDMA3_0_CC0_ERRINT  (56)
/* EDMA3 TC Interrupt                                                         */
#define    CSL_INTC_EVENTID_EDMA3_0_TC0_ERRINT  (57)
#define    CSL_INTC_EVENTID_EDMA3_0_TC1_ERRINT  (58)

/* GPIO BANK 5 interrupt                                                      */
#define    CSL_INTC_EVENTID_GPIO_BNK5_INT       (59)

/* DDR2 memory err interrupt                                                  */
#define    CSL_INTC_EVENTID_DDR2_MEMERR         (60)

/* McASP combined interrupt                                                   */
#define    CSL_INTC_EVENTID_MCASP0INT           (61)

/* GPIO BANK 6 interrupt                                                      */
#define    CSL_INTC_EVENTID_GPIO_BNK6_INT       (62)

/* RTC Combined Interrupt                                                     */
#define    CSL_INTC_EVENTID_RTC_IRQS            (63)

/* Timer 64P0 higher counter interrupt                                        */
#define    CSL_INTC_EVENTID_T64P0_TINT34        (64)

/* GPIO BANK 0 interrupt                                                      */
#define    CSL_INTC_EVENTID_GPIO_BNK0_INT       (65)

/* SYSCFG_CHIPSIG Register                                                    */
#define    CSL_INTC_EVENTID_SYSCFG_CHIPINT3     (67)

/* MMCSD 1 interrupt                                                          */
#define    CSL_INTC_EVENTID_MMCSD1_INT0         (68)

/* uart2 interrupt                                                            */
#define    CSL_INTC_EVENTID_UARTINT2            (69)
/* PSC interrupt                                                              */
#define    CSL_INTC_EVENTID_PSC0_ALLINT         (70)
#define    CSL_INTC_EVENTID_PSC1_ALLINT         (71)

/* GPIO bank 7 interrupt                                                      */
#define    CSL_INTC_EVENTID_GPIO_BNK7_INT       (72)

/* LCDC interrupt                                                             */
#define    CSL_INTC_EVENTID_LCDC_INT0           (73)

/* SYSCFG Protection Shared Interrupt                                         */
#define    CSL_INTC_EVENTID_PROTERR             (74)

/* GPIO bank 8 interrupt                                                      */
#define    CSL_INTC_EVENTID_GPIO_BNK8_INT       (75)

/* Timer 64P2 Compare Interrupt                                               */
#define    CSL_INTC_EVENTID_T64P2_CMPINT0       (78)
#define    CSL_INTC_EVENTID_T64P2_CMPINT1       (79)
#define    CSL_INTC_EVENTID_T64P2_CMPINT2       (80)
#define    CSL_INTC_EVENTID_T64P2_CMPINT3       (81)
#define    CSL_INTC_EVENTID_T64P2_CMPINT4       (82)
#define    CSL_INTC_EVENTID_T64P2_CMPINT5       (83)
#define    CSL_INTC_EVENTID_T64P2_CMPINT6       (84)
#define    CSL_INTC_EVENTID_T64P2_CMPINT7       (85)
/* Timer 64P3 Compare Interrupt                                               */
#define    CSL_INTC_EVENTID_T64P3_TINTALL       (86)

/* McBSP0 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCBSP0_RXINT        (87)
/* McBSP0 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCBSP0_TXINT        (88)
/* McBSP1 RX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCBSP1_RXINT        (89)
/* McBSP1 TX interrupt                                                        */
#define    CSL_INTC_EVENTID_MCBSP1_TXINT        (90)

/* CC1 region 1 interrupt                                                     */
#define    CSL_INTC_EVENTID_EDMA3_1_CC0_INT1   (91)

/* CC1 Error Interrupt                                                        */
#define    CSL_INTC_EVENTID_EDMA3_1_CC0_ERRINT (92)

/* TC2 Error Interrupt                                                        */
#define    CSL_INTC_EVENTID_EDMA3_1_TC0_ERRINT (93)

/* UPP interrupt event                                                        */
#define    CSL_INTC_EVENTID_UPPINT              (94)
/* VPIF INTERRUPT EVENT                                                       */
#define    CSL_INTC_EVENTID_VPIFINT             (95)
/* Dropped CPU interrupt event                                                */
#define    CSL_INTC_EVENTID_INTERR              (96)
/* EMC Invalid IDMA parameters                                                */
#define    CSL_INTC_EVENTID_EMC_IDMAERR         (97)

/* PMC Single bit error detected during DMA read                              */
#define    CSL_INTC_EVENTID_PMC_ED              (113)

/* UMC single bit error detected                                              */
#define    CSL_INTC_EVENTID_UMC_ED1             (116)
/* UMC two bit error detected                                                 */
#define    CSL_INTC_EVENTID_UMC_ED2             (117)
/* Power Down sleep interrupt                                                 */
#define    CSL_INTC_EVENTID_PDC_INT             (118)

/* SYS CMPA CPU memory protection fault                                       */
#define    CSL_INTC_EVENTID_SYS_CMPA            (119)

/* PMC CPU memory protection fault                                            */
#define    CSL_INTC_EVENTID_PMC_CMPA            (120)
/* PMC DMA memory protection fault                                            */
#define    CSL_INTC_EVENTID_PMC_DMPA            (121)
/* DMC CPU memory protection fault                                            */
#define    CSL_INTC_EVENTID_DMC_CMPA            (122)
/* DMC DMA memory protection fault                                            */
#define    CSL_INTC_EVENTID_DMC_DMPA            (123)
/* UMC CPU memory protection fault                                            */
#define    CSL_INTC_EVENTID_UMC_CMPA            (124)
/* UMC DMA memory protection fault                                            */
#define    CSL_INTC_EVENTID_UMC_DMPA            (125)
/* IDMA CPU memory protection fault                                           */
#define    CSL_INTC_EVENTID_EMC_CMPA            (126)
/* IDMA Bus error interrupt                                                   */
#define    CSL_INTC_EVENTID_EMC_BUSERR          (127)




#ifdef __cplusplus
}
#endif

#endif
