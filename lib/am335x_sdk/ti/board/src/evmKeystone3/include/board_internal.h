/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

#ifndef BOARD_INTERNAL_H_
#define BOARD_INTERNAL_H_

/*****************************************************************************
 * Include Files                                                             *
 *****************************************************************************/
#include <ti/csl/csl_types.h>
#include <ti/csl/cslr_device.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/soc/UART_soc.h>

#include <ti/board/board.h>
#include <ti/csl/tistdtypes.h>
#include <stdio.h>
#include <stdbool.h>

/*****************************************************************************
 * Internal Objects                                                          *
 *****************************************************************************/
extern I2C_config_list I2C_config;

typedef struct
{
    I2C_Handle i2cHandle;
} Board_gblObj;

typedef struct pruicssMdioInfo
{
    uint32_t mdioBaseAddrs;
    uint8_t  phyAddrs;
}pruicssMdioInfo;

extern Board_gblObj Board_obj;

/****************************************************************************/

#define ENABLE_DDR4_1600MHZ (1)

#define KICK0_UNLOCK_VAL                 (0x68EF3490U)
#define KICK1_UNLOCK_VAL                 (0xD172BC5AU)

/* The below macro are for temporary use only, Once the CSL macros are 
 *  added these can be removed */ 

#define MAIN_PSC_ADDR_OFFSET                 (0x80000000U)
#define WAKEUP_PSC_ADDR_OFFSET               (0x20000000U)

/*
 * macro definitions for the WKUP_PSC
 */

/* power domain indices */
#define CSL_PSC_PD_WKUP                      (0)
#define CSL_PSC_PD_MCU                       (1)
#define CSL_PSC_PD_MCU_PULSAR                (2)

/* lpsc indices */
#define CSL_PSC_LPSC_WKUP_COMMON             (0)
#define CSL_PSC_LPSC_DMSC                    (1)
#define CSL_PSC_LPSC_WKUP2MCU                (2)
#define CSL_PSC_LPSC_WKUP2MAIN_INFRA         (3)
#define CSL_PSC_LPSC_DEBUG2DMSC              (4)
#define CSL_PSC_LPSC_WKUP_GPIO               (5)
#define CSL_PSC_LPSC_MCU2MAIN_INFRA          (6)
#define CSL_PSC_LPSC_MCU2MAIN                (7)
#define CSL_PSC_LPSC_MCU2WKUP                (8)
#define CSL_PSC_LPSC_MAIN2MCU                (9)
#define CSL_PSC_LPSC_MCU_COMMON              (10)
#define CSL_PSC_LPSC_MCU_TEST                (11)
#define CSL_PSC_LPSC_MCU_MCAN_0              (12)
#define CSL_PSC_LPSC_MCU_MCAN_1              (13)
#define CSL_PSC_LPSC_MCU_OSPI_0              (14)
#define CSL_PSC_LPSC_MCU_OSPI_1              (15)
#define CSL_PSC_LPSC_MCU_HYPERBUS            (16)
#define CSL_PSC_LPSC_MCU_DEBUG               (17)
#define CSL_PSC_LPSC_MCU_R5_0                (19)
#define CSL_PSC_LPSC_MCU_R5_1                (20)

/*
 * macro definitions for the MAIN_PSC
*/

/* power domain indices */
#define CSL_PSC_GP_CORE_CTL                  (0)
#define CSL_PSC_PD_CC_TOP                    (1)
#define CSL_PSC_PD_A53_0                     (2)
#define CSL_PSC_PD_A53_1                     (3)
#define CSL_PSC_PD_A53_2                     (4)
#define CSL_PSC_PD_A53_3                     (5)
#define CSL_PSC_PD_A53_CLUSTER_0             (6)
#define CSL_PSC_PD_A53_CLUSTER_1             (7)
#define CSL_PSC_PD_DEBUG                     (8)
#define CSL_PSC_PD_PER                       (9)
#define CSL_PSC_PD_SERDES                    (10)
#define CSL_PSC_PD_ICSSG                     (11)
#define CSL_PSC_PD_GPU                       (12)
#define CSL_PSC_PD_EMIF                      (13)

/* LPSC indices */
#define CSL_PSC_LPSC_MAIN_INFRA              (0)
#define CSL_PSC_LPSC_MAIN_TEST               (1)
#define CSL_PSC_LPSC_MAIN_PBIST              (2)
#define CSL_PSC_LPSC_CC_TOP                  (5)
#define CSL_PSC_LPSC_CC_TOP_PBIST            (6)
#define CSL_PSC_LPSC_A53_0                   (7)
#define CSL_PSC_LPSC_A53_1                   (8)
#define CSL_PSC_LPSC_A53_2                   (9)
#define CSL_PSC_LPSC_A53_3                   (10)
#define CSL_PSC_LPSC_A53_CLUSTER_0           (11)
#define CSL_PSC_LPSC_A53_CLUSTER_0_PBIST     (12)
#define CSL_PSC_LPSC_A53_CLUSTER_1           (13)
#define CSL_PSC_LPSC_A53_CLUSTER_1_PBIST     (14)
#define CSL_PSC_LPSC_MAIN_DEBUG              (15)
#define CSL_PSC_LPSC_DSS                     (16)
#define CSL_PSC_LPSC_MMC                     (17)
#define CSL_PSC_LPSC_CAL                     (18)
#define CSL_PSC_LPSC_PCIE_0                  (19)
#define CSL_PSC_LPSC_PCIE_1                  (20)
#define CSL_PSC_LPSC_USB_0                   (21)
#define CSL_PSC_LPSC_USB_1                   (22)
#define CSL_PSC_LPSC_SAUL                    (23)
#define CSL_PSC_LPSC_PER_COMMON              (24)
#define CSL_PSC_LPSC_NB                      (25)
#define CSL_PSC_LPSC_SERDES_0                (27)
#define CSL_PSC_LPSC_SERDES_1                (28)
#define CSL_PSC_LPSC_ICSSG_0                 (29)
#define CSL_PSC_LPSC_ICSSG_1                 (30)
#define CSL_PSC_LPSC_ICSSG_2                 (31)
#define CSL_PSC_LPSC_GPU                     (32)
#define CSL_PSC_LPSC_GPU_PBIST               (33)
#define CSL_PSC_LPSC_EMIF_DATA               (34)
#define CSL_PSC_LPSC_EMIF_CFG                (35)

/* PSC Register Definitions */
#define WAKEUP_PSC_BASE                      (0x42000000)
#define MAIN_PSC_BASE                        (0x00400000)
#define PSC_PID                              (0x44827A00)
#define M3_SOC_OFFSET                        (0x60000000)
#define M3_RAT_CTRL                          (0x44200020)      

#define PSC_MODSTATE_ENABLE                  (3)

#define MAIN_PSC_INDEX                       (0)
#define WAKEUP_PSC_INDEX                     (1)

#define PSC_MDCTL00                          (0xA00)
#define PSC_MDSTAT00                         (0x800)
#define PSC_PDCTL00                          (0x300)
#define PSC_PDSTAT00                         (0x200)
#define PSC_PTCMD                            (0x120)
#define PSC_PTSTAT                           (0x128)

#define PSC_PD_OFF                           (0x0)
#define PSC_PD_ON                            (0x1)

#define PSC_SYNCRESETDISABLE                 (0x0)
#define PSC_SYNCRESET                        (0x1)
#define PSC_DISABLE                          (0x2)
#define PSC_ENABLE                           (0x3)

#define PSC_TIMEOUT                          (0x100)

#define WAKEUP_PSC_MDCTL_BASE                (WAKEUP_PSC_BASE + PSC_MDCTL00)
#define WAKEUP_PSC_MDSTAT_BASE               (WAKEUP_PSC_BASE + PSC_MDSTAT00)
#define WAKEUP_PSC_PDCTL_BASE                (WAKEUP_PSC_BASE + PSC_PDCTL00)
#define WAKEUP_PSC_PDSTAT_BASE               (WAKEUP_PSC_BASE + PSC_PDSTAT00)
#define WAKEUP_PSC_PTCMD_BASE                (WAKEUP_PSC_BASE + PSC_PTCMD)
#define WAKEUP_PSC_PTSTAT_BASE               (WAKEUP_PSC_BASE + PSC_PTSTAT)
#define WAKEUP_PSC_PTCMD                     (WAKEUP_PSC_PTCMD_BASE)
#define WAKEUP_PSC_PTSTAT                    (WAKEUP_PSC_PTSTAT_BASE)

#define MAIN_PSC_MDCTL_BASE                  (MAIN_PSC_BASE + PSC_MDCTL00)
#define MAIN_PSC_MDSTAT_BASE                 (MAIN_PSC_BASE + PSC_MDSTAT00)
#define MAIN_PSC_PDCTL_BASE                  (MAIN_PSC_BASE + PSC_PDCTL00)
#define MAIN_PSC_PDSTAT_BASE                 (MAIN_PSC_BASE + PSC_PDSTAT00)
#define MAIN_PSC_PTCMD_BASE                  (MAIN_PSC_BASE + PSC_PTCMD)
#define MAIN_PSC_PTSTAT_BASE                 (MAIN_PSC_BASE + PSC_PTSTAT)
#define MAIN_PSC_PTCMD                       (MAIN_PSC_PTCMD_BASE)
#define MAIN_PSC_PTSTAT                      (MAIN_PSC_PTSTAT_BASE)

/****************************************************************************/

/* DDR control register addresses */
#define DDR4_SSCFG_V2H_CTL_REG_VALUE         (0x000073FFU)
#define LPDDR4_SSCFG_V2H_CTL_REG_VALUE       (0x000073FFU)

#define BOARD_ETH_PHY_SPEED_MASK             (0x2040U)
#define BOARD_ETH_PHY_AUTONEG_MASK           (0x1000U)
#define BOARD_ETH_PHY_SPEED_1000MPBS         (0x0040U)
#define BOARD_ETH_PHY_SPEED_100MPBS          (0x2000U)

#define CSL_MCU_PLL_CLK_FREQ                 (100000000)
#define CSL_MAIN_PLL_CLK_FREQ                (100000000)
#define CSL_ARM0_PLL_CLK_FREQ                (800000000)
#define CSL_ARM1_PLL_CLK_FREQ                (800000000)
#define CSL_DDR_PLL_CLK_FREQ                 (400000000)
#define CSL_PER0_PLL_CLK_FREQ                (960000000)
#define CSL_PER1_PLL_CLK_FREQ                (300000000)
#define CSL_CPSW_PLL_CLK_FREQ                (250000000)
#define CSL_DSS_PLL_CLK_FREQ                 (497500000)

#define BOARD_NAVSS0_NBSS_NB0_CFG_ADDR       (0x3802010U)


#define BOARD_ETHPHY_REGCR_REG_ADDR             (0xDU)
#define BOARD_ETHPHY_REGCR_ADDR_EN              (0x1FU)
#define BOARD_ETHPHY_REGCR_DATA_EN              (0x401FU)
#define BOARD_ETHPHY_ADDAR_REG_ADDR             (0xEU)

#define BOARD_ETHPHY_LEDCR1_REG_ADDR            (0x18U)

#define BOARD_ETHPHY_FLD_THRESH_REG_ADDR        (0x2EU)

#define BOARD_ETHPHY_RGMIICTL_REG_ADDR          (0x32U)
#define BOARD_ETHPHY_RGMIICTL_CLKDELAY_MASK     (0x3U)
#define BOARD_ETHPHY_RGMIICTL_TXDELAY_EN        (0x2U)
#define BOARD_ETHPHY_RGMIICTL_RXDELAY_EN        (0x1U)

#define BOARD_ETHPHY_STRAP_STS1_REG_ADDR        (0x6EU)
#define BOARD_ETHPHY_STRAP_STS2_REG_ADDR        (0x6FU)

#define BOARD_ETHPHY_RGMIIDCTL_REG_ADDR         (0x86U)

#define BOARD_ETHPHY_GPIO_MUX_CTRL2_REG_ADDR    (0x172U)

/*****************************************************************************
 * Function Prototypes                                                       *
 *****************************************************************************/

/**
 *
 * \brief  Board pinmuxing enable function
 *
 * Enables pinmux for the Maxwell idk board interfaces. Pin mux is done based on the
 * default/primary functionality of the board. Any pins shared by multiple
 * interfaces need to be reconfigured to access the secondary functionality.
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pinmuxConfig(void);

/**
 *
 * \brief  Board PLL initialization function
 *
 *  Configures different PLL controller modules. This enables all the PLL
 *  controllers on the SoC with default configurations.
 *
 * \return BOARD_SOK in case of success or appropriate error code
 */
Board_STATUS Board_PLLInit(uint32_t modId, uint32_t clkId, uint64_t clkRate);

/**
 *
 * \brief DDR4 Initialization function
 *
 * Initializes the DDR timing parameters. Sets the DDR timing parameters
 * based in the DDR PLL controller configuration done by the board library.
 * Any changes to DDR PLL requires change to DDR timing.
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_DDRInit(void);

/**
 *
 * \brief clock Initialization function
 *
 * Enables different power domains and peripheral clocks of the SoC.
 * Some of the power domains and peripherals will be off by default.
 * Enabling the power domains is mandatory before accessing using
 * board interfaces connected to those peripherals.
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_moduleClockInit(void);

/**
 * \brief  Board specific configurations for Gigabit Ethernet PHYs
 *
 * This function takes care of configuring the internal delays for gigabit
 * Ethernet PHY. 2.25ns delay is configured for Rx, and .25ns delay is
 * configured for Tx
 *
 * \return  none
 */
Board_STATUS Board_mcuEthConfig(void);

/**
 * \brief  Board specific configurations for ICSS EMAC Ethernet PHYs
 *
 *  This function takes care of making several board level configurations
 *  required for ICSS EMAC PHY as listed below.
 *   - Disabling internal SoC pull up/down for the pins used for strapping
 *   - Setting the GPIOs for PHY reset, routing ICSS signals to PHYs,
 *     PHY interrupt lines.
 *   - Resetting the PHYs for proper address latching
 *   - MDIO initialization
 *   - MDIO configuration for setting MII mode
 *
 * \return  none
 */
Board_STATUS Board_icssEthConfig(void);

/**
 * \brief   This function initializes the default UART instance for use for
 *          console operations.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_uartStdioInit(void);

/**
 * \brief   This function initializes the i2c instance connected to the
 *          board Id EEPROM.
 *
 * This function disables the interrupt mode as the Board i2c instance
 * doesn't require interrupt mode and restores back original at the end.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_internalInitI2C(void);

/**
 *  \brief   This function is to get the i2c handle of the requested
 *           instance of the specifed domain
 *
 *  \param   domainType [IN] Domain of I2C controller
 *                             BOARD_SOC_DOMAIN_MAIN - Main Domain
 *                             BOARD_SOC_DOMAIN_WKUP - Wakeup domain
 *                             BOARD_SOC_DOMAIN_MCU - MCU domain
 *
 *  \param   i2cInst    [IN]        I2C instance
 *
 *  \return  Board_STATUS in case of success or appropriate error code.
 *
 */
I2C_Handle Board_getI2CHandle(uint8_t domainType,
                              uint32_t i2cInst);

/**
 * \brief board detect test
 *
 * This function used to check whether the specified board exists.
 *
 * \param   detectBoard  [IN]  enum used to send the name of the
 *                             board going to be detected.
 *
 * \return   bool
 *                    true   - In case of specified board detected
 *                    false  - In case of specified board not detected.
 *
 */
bool Board_detectBoard(boardPresDetect_t detectBoard);

/**
 * \brief  Unlocks MMR registers
 *
 * \return  Board_STATUS
 */
Board_STATUS Board_unlockMMR(void);


Board_STATUS Board_PLLInitAll(void);

#endif /* BOARD_INTERNAL_H_ */
