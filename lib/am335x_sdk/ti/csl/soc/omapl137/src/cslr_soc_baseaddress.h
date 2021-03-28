/*
 * cslr_soc_baseaddress.h
 *
 * This file contains the peripheral registers base addresseses, peripheral
 * counts, peripheral inettupr details etc for the respective SoC
 *
 * Copyright (C) 2009-2017 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef CSLR_SOC_BASEADDRESS_H_
#define CSLR_SOC_BASEADDRESS_H_

/* =============================================================================
 *  Revision History
 *  ===============
 *  15-Feb-2007 NS  File created.
 *  Aug 27, 2008           SRIRAM M       Updated for OMAPL137 SoC
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/**************************************************************************\
* SOC file
\**************************************************************************/

/******************************************************************************\
* Static inline definition
\******************************************************************************/
#ifndef CSL_IDEF_INLINE
#define CSL_IDEF_INLINE static inline
#endif

/******************************************************************************\
* Peripheral Instance count
\******************************************************************************/

/** @brief Number of UHPI instances                                           */
#define CSL_HPI_CNT                         1

/** @brief Number of McASP instances                                          */
#define CSL_MCASP_CNT                       3

/** @brief Number of TIMER instances                                          */
#define CSL_TIMER_CNT                       2

/** @brief Number of PSC instances                                            */
#define CSL_PSC_CNT                     2

/** @brief Number of UART instances                                           */
#define CSL_UART_CNT                    3

/** @brief Number of SPI instances                                            */
#define CSL_SPI_CNT                     2

/** @brief Number of I2C instances                                            */
#define CSL_I2C_CNT                     2

/** @brief Number of PLL instances                                            */
#define CSL_PLLC_CNT                    1

/** @brief Number of MMCSD instances                                          */
#define CSL_MMCSD_CNT                   1

/** @brief Number of LCDC instances                                            */
#define CSL_LCDC_CNT                     1

/** @brief Number of EDMA3 CC instances                                       */
#define CSL_EDMA3CC_CNT                     1

/** @brief Number of EDMA3 TC instances                                       */
#define CSL_EDMA3TC_CNT                     2

/** @brief Number of EMIFA instances                                          */
#define CSL_EMIFA_CNT                   1

/** @brief Number of EMIFB instances                                          */
#define CSL_EMIFB_CNT                   1

/** @brief Number of EMAC instances                                           */
#define CSL_EMAC_CNT                    1

/** @brief Number of MDIO instances                                           */
#define CSL_MDIO_CNT                    1

/** @brief Number of EHRPWM instances                                         */
#define CSL_EHRPWM_CNT                  3

/** @brief Number of ECAP instances                                           */
#define CSL_ECAP_CNT                    3

/** @brief Number of EQEP instances                                           */
#define CSL_EQEP_CNT                    2

/** @brief Number of USB instances                              */
#define CSL_USB_CNT                     2

/** @brief Number of INTC instances                             */
#define CSL_INTC_CNT                    1

/** @brief Number of AINTC instances                            */
#define CSL_AINTC_CNT                   1

/** @brief Number of RTC instances                              */
#define CSL_RTC_CNT                     1

/** @brief Number of GPIO instances                             */
#define CSL_GPIO_CNT                    1

/** @brief Number of ECTL instances                             */
#define CSL_ECTL_CNT                    1

/** @brief Number of SYSCFG instances                           */
#define CSL_SYSCFG_CNT                  1
/******************************************************************************\
* Peripheral Instance definitions.
\******************************************************************************/

/** @brief Peripheral Instances of UHPI instances                             */
#define CSL_HPI                             (0)

/** @brief Peripheral Instances of McASP instances                            */
#define CSL_MCASP_0                         (0)
#define CSL_MCASP_1                         (1)
#define CSL_MCASP_2                         (2)

/** @brief Peripheral Instance of EDMA CC instances                           */
#define CSL_EDMA3CC                         (0)

/** @brief Peripheral Instance of EDMA TC instances                           */
#define CSL_EDMA3TC_0                       (0)
#define CSL_EDMA3TC_1                       (1)

/** @brief Peripheral Instance of Timer 64 instances                          */
#define CSL_TMR_0                           (0)
#define CSL_TMR_1                           (1)

/** @brief Peripheral Instances of PSC instances                              */
#define CSL_PSC_0                           (0)
#define CSL_PSC_1                           (1)

/** @brief Peripheral Instances of UART instances                             */
#define CSL_UART_0                          (0)
#define CSL_UART_1                          (1)
#define CSL_UART_2                          (2)

/** @brief Peripheral Instances of SPI instances                              */
#define CSL_SPI_0                           (0)
#define CSL_SPI_1                           (1)

/** @brief Peripheral Instances of I2C instances                              */
#define CSL_I2C_0                           (0)
#define CSL_I2C_1                           (1)

/** @brief Peripheral Instances of MMCSD instances                            */
#define CSL_MMCSD_0                         (0)

/** @brief Peripheral Instances of LCDC instances                              */
#define CSL_LCDC                            (0)

/** @brief Instance number of PLL controller                                  */
#define CSL_PLLC                            (0)

/** @brief Peripheral Instance of EMIFA instances                             */
#define CSL_EMIFA                           (0)

/** @brief Peripheral Instance of EMIFB instances                             */
#define CSL_EMIFB                           (0)

/** @brief Peripheral Instance of EMAC instances                              */
#define CSL_EMAC                            (0)

/** @brief Peripheral Instance of MDIO instances                              */
#define CSL_MDIO                            (0)

/** @brief Peripheral Instance of EHRPWM instances                            */
#define CSL_EHRPWM_0                        (0)
#define CSL_EHRPWM_1                        (1)
#define CSL_EHRPWM_2                        (2)

/** @brief Peripheral Instance of ECAP instances                              */
#define CSL_ECAP_0                          (0)
#define CSL_ECAP_1                          (1)
#define CSL_ECAP_2                          (2)

/** @brief Peripheral Instance of EQEP instances                              */
#define CSL_EQEP_0                          (0)
#define CSL_EQEP_1                          (1)

/** @brief Peripheral Instance of USB instances                               */
#define CSL_USB_0                           (0)
#define CSL_USB_1                           (1)

/** @brief Peripheral Instance of INTC instances                              */
#define CSL_INTC                            (0)

/** @brief Peripheral Instance of AINTC instances                             */
#define CSL_AINTC                           (0)

/** @brief Peripheral Instance of MPU instances                             */
#define CSL_MPU_0                           (0)
#define CSL_MPU_1                           (1)

/** @brief Peripheral Instance of TIMER instances                             */
#define CSL_TIMER_0                           (0)
#define CSL_TIMER_1                           (1)

/** @brief Peripheral Instance of RTC instances                               */
#define CSL_RTC                             (0)

/** @brief Peripheral Instance of GPIO instances                              */
#define CSL_GPIO_0                            (0)
/** @brief GPIO pin and bank information                                      */
#define CSL_GPIO_NUM_PINS                   (128)
#define CSL_GPIO_NUM_BANKS                  ((CSL_GPIO_NUM_PINS + 15)/16)

/** @brief Peripheral Instance of ECTL instances                              */
#define CSL_ECTL                            (0)

/** @brief Peripheral Instance of SYSCFG instances                            */
#define CSL_SYSCFG                          (0)

/*******************************************************************************
* Peripheral Base Address
*******************************************************************************/

/** @brief Base address of INTC memory mapped registers                       */
#define CSL_INTC_0_REGS                     (0x01800000u)
#define CSL_INTC_0_REGS_SIZE                (0x10000u)

/** @brief Base address of AINTC memory mapped registers                      */
#define CSL_AINTC_0_REGS                    (0xFFFEE000u)
#define CSL_AINTC_0_REGS_SIZE               (0x2000u)

/** #brief Cache Module memory mapped address                                 */
#define CSL_CACHE_0_REGS                    (0x01840000u)
#define CSL_CACHE_0_REGS_SIZE               (0x10000u)

/** @brief Base address of PDC memory mapped registers                        */
#define CSL_PWRDWN_PDC_REGS                 (0x01810000u)
#define CSL_PWRDWN_PDC_REGS_SIZE            (0x1000u)

/** @brief Base address of SYS - Security ID register                         */
#define CSL_SYS_0_SECURITY_ID_REGS          (0x01811000u)
#define CSL_SYS_0_SECURITY_ID_REGS_SIZE     (0x1000u)

/** @brief Base address of SYS - Revision ID register                         */
#define CSL_SYS_0_REV_ID_REGS               (0x01812000u)
#define CSL_SYS_0_REV_ID_REGS_SIZE          (0x1000u)

/** #brief IDMA Module memory mapped address  */
#define CSL_IDMA_0_REGS                     (0x01820000u)
#define CSL_IDMA_0_REGS_SIZE                (0x10000u) //????????????????

/** #brief EMC Module memory mapped address                                   */
#define CSL_EMC_0_REGS                      (0x01820000u)
#define CSL_EMC_0_REGS_SIZE                 (0x10000u)

/** @brief Base address of UMC Memory protection registers                    */
#define CSL_MEMPROT_L2_REGS                 (0x00800000u)
#define CSL_MEMPROT_L2_REGS_SIZE            (0x40000u)

/** @brief Base address of PMC memory Protection registers                    */
#define CSL_MEMPROT_L1P_REGS                (0x00E00000u)
#define CSL_MEMPROT_L1P_REGS_SIZE           (0x8000u)

 /** @brief Base address of DMC memory protection registers                   */
#define CSL_MEMPROT_L1D_REGS                (0x00F00000u)
#define CSL_MEMPROT_L1D_REGS_SIZE           (0x8000u)

/** @brief Base address of HPI memory mapped registers                        */
#define CSL_HPI_0_REGS                      (0x01E10000u)
#define CSL_HPI_0_REGS_SIZE                 (0x1000u)

/** @brief Base address of McASP memory mapped registers                      */
#define CSL_MCASP_0_CFG_REGS               (0x01D00000u)
#define CSL_MCASP_0_CFG_REGS_SIZE          (0x1000u)
#define CSL_MCASP_0_FIFO_CFG_REGS          (0x01D01000u)
#define CSL_MCASP_0_FIFO_CFG_REGS_SIZE     (0x1000u)
#define CSL_MCASP_0_SLV_REGS               (0x01D02000u)
#define CSL_MCASP_0_SLV_REGS_SIZE          (0x1000u)
#define CSL_MCASP_1_CFG_REGS               (0x01D04000u)
#define CSL_MCASP_1_CFG_REGS_SIZE          (0x1000u)
#define CSL_MCASP_1_FIFO_CFG_REGS          (0x01D05000u)
#define CSL_MCASP_1_FIFO_CFG_REGS_SIZE     (0x1000u)
#define CSL_MCASP_1_SLV_REGS               (0x01D06000u)
#define CSL_MCASP_1_SLV_REGS_SIZE          (0x1000u)
#define CSL_MCASP_2_CFG_REGS               (0x01D08000u)
#define CSL_MCASP_2_CFG_REGS_SIZE          (0x1000u)
#define CSL_MCASP_2_FIFO_CFG_REGS          (0x01D09000u)
#define CSL_MCASP_2_FIFO_CFG_REGS_SIZE     (0x1000u)
#define CSL_MCASP_2_SLV_REGS               (0x01D0A000u)
#define CSL_MCASP_2_SLV_REGS_SIZE          (0x1000u)
/** @brief Base address of TIMER memory mapped registers                      */
#define CSL_TIMER_0_CFG_REGS                      (0x01C20000u)
#define CSL_TIMER_0_CFG_REGS_SIZE                 (0x1000u)
#define CSL_TIMER_1_CFG_REGS                      (0x01C21000u)
#define CSL_TIMER_1_CFG_REGS_SIZE                 (0x1000u)

/** @brief Base address of PSC memory mapped registers                        */
#define CSL_PSC_0_REGS                      (0x01C10000u)
#define CSL_PSC_0_REGS_SIZE                 (0x1000u)
#define CSL_PSC_1_REGS                      (0x01E27000u)
#define CSL_PSC_1_REGS_SIZE                 (0x1000u)

/** @brief Base address of UART memory mapped registers                       */
#define CSL_UART_0_REGS                     (0x01C42000u)
#define CSL_UART_0_REGS_SIZE                (0x1000u)
#define CSL_UART_1_REGS                     (0x01D0C000u)
#define CSL_UART_1_REGS_SIZE                (0x1000u)
#define CSL_UART_2_REGS                     (0x01D0D000u)
#define CSL_UART_2_REGS_SIZE                (0x1000u)

/** @brief Base address of SPI memory mapped registers                        */
#define CSL_SPI_0_SLV_REGS                      (0x01C41000u)
#define CSL_SPI_0_SLV_REGS_SIZE                 (0x1000u)
#define CSL_SPI_1_SLV_REGS                      (0x01E12000u)
#define CSL_SPI_1_SLV_REGS_SIZE                 (0x1000u)

/** @brief Base address of I2C memory mapped registers                        */
#define CSL_I2C_0_DATA_CFG                      (0x01C22000u)
#define CSL_I2C_0_DATA_CFG_SIZE                 (0x1000u)
#define CSL_I2C_1_DATA_CFG                      (0x01E28000u)
#define CSL_I2C_1_DATA_CFG_SIZE                 (0x1000u)

/** @brief Base address of GPIO memory mapped registers                       */
#define CSL_GPIO_0_REGS                     (0x01E26000u)
#define CSL_GPIO_0_REGS_SIZE                (0x1000u)

/** @brief Base address of DEV memory mapped registers                        */
#define CSL_SYSCFG_0_REGS                   (0x01C14000u)
#define CSL_SYSCFG_0_REGS_SIZE              (0x1000u)

/** @brief Base address of MMCSD memory mapped registers                      */
#define CSL_MMCSD_0_S_REGS                    (0x01C40000)
#define CSL_MMCSD_0_S_REGS_SIZE               (0x1000)

/** @brief Base address of LCDC memory mapped registers                        */
#define CSL_LCDC_0_REGS                     (0x01E13000u)
#define CSL_LCDC_0_REGS_SIZE                (0x1000u)

/** @brief PLL controller instance 1 module address                           */
#define CSL_PLLC_CFG_REGS                     (0x01C11000u)
#define CSL_PLLC_CFG_REGS_SIZE                (0x1000u)

/** @brief Base address of Channel controller  memory mapped registers        */
#define CSL_EDMA3CC_0_REGS                  (0x01C00000u)
#define CSL_EDMA3CC_0_REGS_SIZE             (0x8000u)

/** @brief Base address of Transfer controller  memory mapped registers       */
#define CSL_EDMA3TC_0_REGS                  (0x01C08000u)
#define CSL_EDMA3TC_0_REGS_SIZE             (0x400u)
#define CSL_EDMA3TC_1_REGS                  (0x01C08400u)
#define CSL_EDMA3TC_1_REGS_SIZE             (0x400u)

/** @brief Base address of EPWM memory mapped registers                       */
#define CSL_PWM_0_EHR_CFG_REGS                   (0x01F00000u)
#define CSL_PWM_0_EHR_CFG_REGS_SIZE              (0x1000u)
#define CSL_PWM_1_EHR_CFG_REGS                   (0x01F02000u)
#define CSL_PWM_1_EHR_CFG_REGS_SIZE              (0x1000u)
#define CSL_PWM_2_EHR_CFG_REGS                   (0x01F04000u)
#define CSL_PWM_2_EHR_CFG_REGS_SIZE              (0x1000u)

/** @brief Base address of MDIO memory mapped registers                       */
#define CSL_MII_MDIO_REGS                     (0x01E24000u)
#define CSL_MII_MDIO_REGS_SIZE                (0x1000u)

/** @brief Base address of ECAP memory mapped registers                       */
#define CSL_ECAP_0_REGS                     (0x01F06000u)
#define CSL_ECAP_0_REGS_SIZE                (0x1000u)
#define CSL_ECAP_1_REGS                     (0x01F07000u)
#define CSL_ECAP_1_REGS_SIZE                (0x1000u)
#define CSL_ECAP_2_REGS                     (0x01F08000u)
#define CSL_ECAP_2_REGS_SIZE                (0x1000u)

/** @brief Base address of EQEP memory mapped registers                       */
#define CSL_EQEP_0_CFG_REGS                     (0x01F09000u)
#define CSL_EQEP_0_CFG_REGS_SZIE                (0x1000u)
#define CSL_EQEP_1_CFG_REGS                     (0x01F0A000u)
#define CSL_EQEP_1_CFG_REGS_SIZE                (0x1000u)

/** @brief Base address of EMIFA memory mapped registers                      */
#define CSL_EMIFA_0_REGS                    (0x68000000u)
#define CSL_EMIFA_0_REGS_SIZE               (0x8000u)

/** @brief Base address of EMIFA_CS0 memory                                   */
#define CSL_EMIFA_CS0_ADDR                  (0x40000000u)
#define CSL_EMIFA_CS0_ADDR_SIZE             (0x8000000u)

/** @brief Base address of EMIFA_CS2 memory                                   */
#define CSL_EMIFA_CS2_ADDR                  (0x60000000u)
#define CSL_EMIFA_CS2_ADDR_SIZE             (0x2000000u)

/** @brief Base address of EMIFA_CS3 memory                                   */
#define CSL_EMIFA_CS3_ADDR                  (0x62000000u)
#define CSL_EMIFA_CS3_ADDR_SIZE             (0x2000000u)

/** @brief Base address of EMIFA_CS4 memory                                   */
#define CSL_EMIFA_CS4_ADDR                  (0x64000000u)
#define CSL_EMIFA_CS4_ADDR_SIZE             (0x2000000u)

/** @brief Base address of EMIFA_CS5 memory                                   */
#define CSL_EMIFA_CS5_ADDR                  (0x66000000u)
#define CSL_EMIFA_CS5_ADDR_SIZE             (0x2000000u)

/** @brief Base address of EMIFB Control Registers                            */
#define CSL_EMIFB_0_REGS                    (0xB0000000u)
#define CSL_EMIFB_0_REGS_SIZE               (0x8000u)

/** @brief Base address of EMIFB SDRAM memory                                 */
#define CSL_EMIFB_SDRAM_ADDR                (0xC0000000u)
#define CSL_EMIFB_SDRAM_ADDR_SIZE           (0x8000000u)

/** @brief Base address of USB memory                                         */
#define CSL_USB_0_PHY_CFG_REGS                      (0x01E00000u)
#define CSL_USB_0_PHY_CFG_REGS_SIZE                 (0x10000u)
#define CSL_USB_1_PHY_CFG_REGS                      (0x01E25000u)
#define CSL_USB_1_PHY_CFG_REGS_SIZE                 (0x10000u)

#define CSL_MPU_0_REGS                      (0x01E14000u)
#define CSL_MPU_0_REGS_SIZE                 (0x1000u)
#define CSL_MPU_1_REGS                      (0x01E15000u)
#define CSL_MPU_1_REGS_SIZE                 (0x1000u)

/** @brief Base address of EMAC memory                                        */
#define CSL_EMAC_DSC_CTRL_MOD_RAM           (0x01E20000u)
#define CSL_EMAC_DSC_CTRL_MOD_RAM_SIZE      (0x2000u)
#define CSL_EMAC_DSC_CTRL_MOD_REG           (0x01E22000u)
#define CSL_EMAC_DSC_CTRL_MOD_REG_SIZE      (0x1000u)
#define CSL_EMAC_DSC_CONTROL_REG            (0x01E23000u)
#define CSL_EMAC_DSC_CONTROL_REG_SZIE       (0x1000u)
#define CSL_MDIO_0_REGS                     (0x01E24000u)
#define CSL_MDIO_0_REGS_SIZE                (0x1000u)


/** @brief Base address of ECTL memory                                        */
#define CSL_ECTL_0_REGS                   (0x01E22000u)
#define CSL_ECTL_0_REGS_SIZE              (0x1000u)

/** @brief Base address of RTC memory                                         */
#define CSL_RTC_0_REGS                    (0x01C23000u)
#define CSL_RTC_0_REGS_SIZE               (0x1000u)






/*************************** EDMA RELATED DEFINES  ****************************/


/******************************************************************************\
*  Parameterizable Configuration:- These are fed directly from the RTL
*  parameters for the given SOC
\******************************************************************************/

#define CSL_EDMA3_NUM_DMACH                 64
#define CSL_EDMA3_NUM_QDMACH                8
#define CSL_EDMA3_NUM_PARAMSETS             128
#define CSL_EDMA3_NUM_EVQUE                 2
#define CSL_EDMA3_CHMAPEXIST                0
#define CSL_EDMA3_NUM_REGIONS               4
#define CSL_EDMA3_MEMPROTECT                0

/******************************************************************************\
* Channel Instance count
\******************************************************************************/
#define CSL_EDMA3_CHA_CNT                   (CSL_EDMA3_NUM_DMACH + \
                                             CSL_EDMA3_NUM_QDMACH)

/* EDMA channel synchronization events                                        */

/* McASP0 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP0_RX             0
/* McASP0 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP0_TX             1
/* McASP1 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP1_RX             2
/* McASP1 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP1_TX             3
/* McASP2 Receive Event                                                       */
#define CSL_EDMA3_CHA_MCASP2_RX             4
/* McASP2 Transmit Event                                                      */
#define CSL_EDMA3_CHA_MCASP2_TX             5

/* GPIO Bank0 event                                                           */
#define CSL_EDMA3_CHA_GPIO_BNKINT0          6
/* GPIO Bank0 event                                                           */
#define CSL_EDMA3_CHA_GPIO_BNKINT1          7
/* GPIO Bank0 event                                                           */
#define CSL_EDMA3_CHA_GPIO_BNKINT2          22
/* GPIO Bank0 event                                                           */
#define CSL_EDMA3_CHA_GPIO_BNKINT3          23
/* GPIO Bank0 event                                                           */
#define CSL_EDMA3_CHA_GPIO_BNKINT4          28
/* GPIO Bank0 event                                                           */
#define CSL_EDMA3_CHA_GPIO_BNKINT5          29

/* UART0 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART0_RX              8
/* UART0 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART0_TX              9
/* UART1 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART1_RX              12
/* UART1 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART1_TX              13
/* UART2 Receive Event                                                        */
#define CSL_EDMA3_CHA_UART2_RX              30
/* UART2 Transmit Event                                                       */
#define CSL_EDMA3_CHA_UART2_TX              31

/* Timer 64P Event Out 12                                                     */
#define CSL_EDMA3_CHA_TIMER64P_EVT12        10
/* Timer 64P Event Out 34                                                     */
#define CSL_EDMA3_CHA_TIMER64P_EVT34        11

/* SPI0 Receive Event                                                         */
#define CSL_EDMA3_CHA_SPI0_RX               14
/* SPI0 Transmit Event                                                        */
#define CSL_EDMA3_CHA_SPI0_TX               15
/* SPI1 Receive Event                                                         */
#define CSL_EDMA3_CHA_SPI1_RX               18
/* SPI1 Transmit Event                                                        */
#define CSL_EDMA3_CHA_SPI1_TX               19

/* MMCSD Receive Event                                                        */
#define CSL_EDMA3_CHA_MMCSD_RX              16
/* MMCSD Transmit Event                                                       */
#define CSL_EDMA3_CHA_MMCSD_TX              17

/* I2C0 Receive Event                                                         */
#define CSL_EDMA3_CHA_I2C0_RX               24
/* I2C0 Transmit Event                                                        */
#define CSL_EDMA3_CHA_I2C0_TX               25
/* I2C1 Receive Event                                                         */
#define CSL_EDMA3_CHA_I2C1_RX               26
/* I2C1 Transmit Event                                                        */
#define CSL_EDMA3_CHA_I2C1_TX               27



/* QDMA channels                                                              */
#define    CSL_EDMA3_QCHA_BASE              CSL_EDMA3_NUM_DMACH         /* QDMA Channel Base */
#define    CSL_EDMA3_QCHA_0                 (CSL_EDMA3_QCHA_BASE + 0)   /* QDMA Channel 0 */
#define    CSL_EDMA3_QCHA_1                 (CSL_EDMA3_QCHA_BASE + 1)   /* QDMA Channel 1 */
#define    CSL_EDMA3_QCHA_2                 (CSL_EDMA3_QCHA_BASE + 2)   /* QDMA Channel 2 */
#define    CSL_EDMA3_QCHA_3                 (CSL_EDMA3_QCHA_BASE + 3)   /* QDMA Channel 3 */
#define    CSL_EDMA3_QCHA_4                 (CSL_EDMA3_QCHA_BASE + 4)   /* QDMA Channel 4 */
#define    CSL_EDMA3_QCHA_5                 (CSL_EDMA3_QCHA_BASE + 5)   /* QDMA Channel 5 */
#define    CSL_EDMA3_QCHA_6                 (CSL_EDMA3_QCHA_BASE + 6)   /* QDMA Channel 6 */
#define    CSL_EDMA3_QCHA_7                 (CSL_EDMA3_QCHA_BASE + 7)   /* QDMA Channel 7 */

/* Enumerations for EDMA Event Queues */
#if 0
//typedef enum {
//    CSL_EDMA3_QUE_0            =            0, /* Queue 0                     */
//    CSL_EDMA3_QUE_1            =            1  /* Queue 1                     */
//} CSL_Edma3Que;
#endif
/* Enumerations for EDMA Transfer Controllers
 *
 * There are 2 Transfer Controllers. Typically a one to one mapping exists
 * between Event Queues and Transfer Controllers.
 *
 */
typedef enum {
    CSL_EDMA3_TC_0         =                0, /* TC 0                        */
    CSL_EDMA3_TC_1         =                1  /* TC 1                        */
} CSL_Edma3Tc;

/*
#define CSL_EDMA3_REGION_GLOBAL            -1
#define CSL_EDMA3_REGION_0                  0
#define CSL_EDMA3_REGION_1                  1
#define CSL_EDMA3_REGION_2                  2
#define CSL_EDMA3_REGION_3                  3
*/


/******************************* DAT RELATED DEFINES **************************/

/******************************************************************************\
*  Parameterizable Configuration:- These are fed directly from the RTL
*  parameters for the given SOC
\******************************************************************************/
/******************************************************************************\
* Channel Instance count
\******************************************************************************/
/** @brief Number of Generic Channel instances                                */


/** @brief Enumerations for EDMA channels
*
*  There are 8 QDMA channels -
*
*/

#define    CSL_DAT_QCHA_0                   0 /**<   QDMA Channel 0           */
#define    CSL_DAT_QCHA_1                   1 /**<   QDMA Channel 1           */
#define    CSL_DAT_QCHA_2                   2 /**<   QDMA Channel 2           */
#define    CSL_DAT_QCHA_3                   3 /**<   QDMA Channel 3           */
#define    CSL_DAT_QCHA_4                   4 /**<   QDMA Channel 4           */
#define    CSL_DAT_QCHA_5                   5 /**<   QDMA Channel 5           */
#define    CSL_DAT_QCHA_6                   6 /**<   QDMA Channel 6           */
#define    CSL_DAT_QCHA_7                   7 /**<   QDMA Channel 7           */

/** @brief Enumerations for EDMA Event Queues
*
*  There are two Event Queues. Q0 is the highest priority and Q1 is the least
*  priority
*
*/
typedef enum {
    CSL_DAT_PRI_DEFAULT    =                0, /* Queue 0 is default          */
    CSL_DAT_PRI_0          =                0, /* Queue 0                     */
    CSL_DAT_PRI_1          =                1  /* Queue 1                     */
} CSL_DatPriority;

/** @brief Enumeration for EDMA Regions
*
*
*/

#define CSL_DAT_REGION_GLOBAL              -1         /* Global Region        */
#define CSL_DAT_REGION_0                    0         /* EDMA Region 0        */
#define CSL_DAT_REGION_1                    1         /* EDMA Region 1        */
#define CSL_DAT_REGION_2                    2         /* EDMA Region 2        */
#define CSL_DAT_REGION_3                    3         /* EDMA Region 3        */

/** @brief Enumeration for peripheral frequencies
*
*
*/

#define CSL_SYSCLK_1_FREQ                   (300000000)
#define CSL_SYSCLK_2_FREQ                   (CSL_SYSCLK_1_FREQ/2)
#define CSL_SYSCLK_3_FREQ                   (CSL_SYSCLK_1_FREQ/3)
#define CSL_SYSCLK_4_FREQ                   (CSL_SYSCLK_1_FREQ/4)

#define CSL_ASYNC_2_FREQ                    (24000000)

/** I2C      */
#define CSL_I2C_0_MODULE_FREQ               (CSL_ASYNC_2_FREQ)
#define CSL_I2C_1_MODULE_FREQ               (CSL_SYSCLK_4_FREQ)

/** LCDC     */
#define CSL_LCDC_0_MODULE_FREQ              (CSL_SYSCLK_2_FREQ)

/** SPI      */
#define CSL_SPI_0_MODULE_FREQ               (CSL_SYSCLK_2_FREQ)
#define CSL_SPI_1_MODULE_FREQ               (CSL_SYSCLK_2_FREQ)

/** UART     */
#define CSL_UART_0_MODULE_FREQ              (CSL_SYSCLK_2_FREQ)
#define CSL_UART_1_MODULE_FREQ              (CSL_SYSCLK_2_FREQ)
#define CSL_UART_2_MODULE_FREQ              (CSL_SYSCLK_2_FREQ)

/** EMAC register aliases   */
#define CSL_EMAC_0_REGS                     (CSL_EMAC_DSC_CONTROL_REG)
#define CSL_EMAC_DSC_BASE_ADDR              (CSL_EMAC_DSC_CTRL_MOD_RAM)


#ifdef __cplusplus
}
#endif

#endif  /* CSLR_SOC_BASEADDRESS_H_ */
