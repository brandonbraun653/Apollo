/******************************************************************************
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
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
#include <ti/csl/soc.h>

#if !defined(SOC_TPR12)
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#else
typedef void      *I2C_Handle;
#endif

#ifdef UART_DRV_INSTALLED
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/soc/UART_soc.h>
#endif

#include <ti/board/board.h>
#include <ti/csl/tistdtypes.h>
#include <stdio.h>
#include <stdbool.h>

/*****************************************************************************
 * Internal Objects                                                          *
 *****************************************************************************/
#if !defined(SOC_TPR12)
extern const I2C_Config I2C_config[];
#endif

typedef struct
{
    I2C_Handle i2cHandle;
} Board_gblObj;

extern Board_gblObj Board_obj;

/****************************************************************************/
#define KICK0_UNLOCK_VAL                 (0x01234567U)
#define KICK1_UNLOCK_VAL                 (0x0FEDCBA8U)

/****************************************************************************/
#define BOARD_ETH_PHY_SPEED_MASK             (0x2040U)
#define BOARD_ETH_PHY_AUTONEG_MASK           (0x1000U)
#define BOARD_ETH_PHY_SPEED_1000MPBS         (0x0040U)
#define BOARD_ETH_PHY_SPEED_100MPBS          (0x2000U)

#define CSL_MCU_PLL_CLK_FREQ                 (400000000U)
#define CSL_DSS_PLL_CLK_FREQ                 (450000000U)

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
 * \brief  Unlocks MMR registers
 *
 * \return  Board_STATUS
 */
Board_STATUS Board_unlockMMR(void);

/**
 *
 * \brief PLL Initialization function
 *
 * Initialize all system PLLs .
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_PLLInitAll(void);

#endif /* BOARD_INTERNAL_H_ */
