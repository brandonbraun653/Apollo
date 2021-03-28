/**
 *   @file  iceK2G_ethernet_config.c
 *
 *   @brief
 *      This file contains the Ethernet PHY configurations for K2G ICE board
 *
 *      Ethernet PHYs on K2G ICE board have issues with default PHY
 *      configurations based on the strapping value. This module provides
 *      APIs to workaround those issue. Software module working on Ethernet
 *      interfaces can make use of the APIs provided here to avoid additional
 *      configurations of the Ethernet PHYs.
 *
 *      This file exposes two functions to the applications
 *      Board_gigEthConfig: This API configures the gigabit Ethernet PHY delays.
 *      2.25ns delay is set for Rx path and 0.25ns delay is set for Tx path.
 *
 *      Board_icssEthConfig: This API configures 10/100 PHYs connected to four
 *      ICSS ports. Several configurations are needed for normal operation of
 *      the ICSS Ethernet PHYs which will be taken care by this function.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016, Texas Instruments, Inc.
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
 *  \par
*/

#include <ti/csl/csl_mdio.h>
#include <ti/csl/cslr_mdio.h>
#include <ti/csl/csl_mdioAux.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_gpio.h>
#include <ti/csl/csl_gpioAux.h>

#include "board_internal.h"
#include "board_utils.h"
#include "board_pinmux.h"
#include "iceK2G_ethernet_config.h"

static CSL_GpioHandle gpioHandle0;
static CSL_GpioHandle gpioHandle1;

#ifdef ICEK2G_BETA_BOARD

/* Padconfig numbers for the pins which are used for ICSS Ethernet PHY strapping */
static const uint32_t icssEthPhyConfig[BOARD_ICSS_ETHPHY_STRAP_PIN_COUNT] =
{
    PADCONFIG_PIN_NUM(139),
    PADCONFIG_PIN_NUM(140),
    PADCONFIG_PIN_NUM(141),
    PADCONFIG_PIN_NUM(142),
    PADCONFIG_PIN_NUM(143),
    PADCONFIG_PIN_NUM(144),
    PADCONFIG_PIN_NUM(148),
    PADCONFIG_PIN_NUM(149),
    PADCONFIG_PIN_NUM(159),
    PADCONFIG_PIN_NUM(161),
    PADCONFIG_PIN_NUM(162),
    PADCONFIG_PIN_NUM(163),
    PADCONFIG_PIN_NUM(164),
    PADCONFIG_PIN_NUM(168),
    PADCONFIG_PIN_NUM(169),
    PADCONFIG_PIN_NUM(181),
    PADCONFIG_PIN_NUM(182),
    PADCONFIG_PIN_NUM(183),
    PADCONFIG_PIN_NUM(184),
    PADCONFIG_PIN_NUM(185),
    PADCONFIG_PIN_NUM(186),
    PADCONFIG_PIN_NUM(190),
    PADCONFIG_PIN_NUM(191),
    PADCONFIG_PIN_NUM(201),
    PADCONFIG_PIN_NUM(202),
    PADCONFIG_PIN_NUM(203),
    PADCONFIG_PIN_NUM(204),
    PADCONFIG_PIN_NUM(210)
};
#endif

/**
 * \brief  Configures pin mux mode of a pad config register
 *
 * \param   padCfgId [IN]    Pad config register Id; 0 - 259
 * \param   muxMode  [IN]    Pad config mux mode
 *
 * \return  none
 */
void pinMuxSetMode(uint32_t padCfgId, PADCONFIG_MUX_MODE muxMode)
{
  volatile uint32_t *padCfgBase;

    padCfgBase = &hBootCfg->PADCONFIG0;
    CSL_FINS(*(padCfgBase + padCfgId), BOOTCFG_PADCONFIG0_MUXMODE, muxMode);
}

/**
 * \brief  Function to write extended address registers of Ethernet PHY
 *
 * \param   baseAddr [IN]    MDIO base address
 * \param   phyAddr  [IN]    Ethernet PHY address
 * \param   regNum   [IN]    PHY Register address
 * \param   pData    [OUT]   Values read from register
 *
 * \return  none
 */
void Mdio_PhyExtendedRegRead(uint32_t baseAddr,
                             uint32_t phyAddr,
                             uint32_t regNum,
                             uint16_t *pData)
{
	CSL_MDIO_phyRegWrite(baseAddr, phyAddr, 0x0D, 0x001F);
	CSL_MDIO_phyRegWrite(baseAddr, phyAddr, 0x0E, regNum);
	CSL_MDIO_phyRegWrite(baseAddr, phyAddr, 0x0D, 0x401F);
	CSL_MDIO_phyRegRead(baseAddr, phyAddr, 0x0E, pData);
} 

/**
 * \brief  Function to write extended address registers of Ethernet PHY
 *
 * \param   baseAddr [IN]    MDIO base address
 * \param   phyAddr  [IN]    Ethernet PHY address
 * \param   regNum   [IN]    PHY Register address
 * \param   regVal   [IN]    Register value to be written
 *
 * \return  none
 */
static void Mdio_PhyExtendedRegWrite(uint32_t baseAddr,
                                     uint32_t phyAddr,
                                     uint32_t regNum,
                                     uint16_t regVal)
{
	CSL_MDIO_phyRegWrite(baseAddr, phyAddr, 0x0D, 0x001F);
	CSL_MDIO_phyRegWrite(baseAddr, phyAddr, 0x0E, regNum);
	CSL_MDIO_phyRegWrite(baseAddr, phyAddr, 0x0D, 0x401F);
	CSL_MDIO_phyRegWrite(baseAddr, phyAddr, 0x0E, regVal);
}

#ifdef ICEK2G_BETA_BOARD
/**
 * \brief  Resets the ICSS Ethernet PHYs
 *
 * \return  none
 */
static void icssEthPhy_reset(void)
{
	/* Configure GPIO_PR0_MII0_RESETn */
	pinMuxSetMode(BOARD_PR0_MII0_RESET_PADCONFIG,
	              PADCONFIG_MUX_MODE_QUATERNARY);
	CSL_GPIO_setPinDirOutput(gpioHandle0, BOARD_PR0_MII0_RESET_GPIO_PIN);
	CSL_GPIO_clearOutputData(gpioHandle0, BOARD_PR0_MII0_RESET_GPIO_PIN);
	BOARD_delay(BOARD_PHYCFG_DELAY);
	CSL_GPIO_setOutputData(gpioHandle0, BOARD_PR0_MII0_RESET_GPIO_PIN);

	/* Configure GPIO_PR0_MII1_RESETn */
	pinMuxSetMode(BOARD_PR0_MII1_RESET_PADCONFIG,
	              PADCONFIG_MUX_MODE_QUATERNARY);
	CSL_GPIO_setPinDirOutput(gpioHandle0, BOARD_PR0_MII1_RESET_GPIO_PIN);
	CSL_GPIO_clearOutputData(gpioHandle0, BOARD_PR0_MII1_RESET_GPIO_PIN);
	BOARD_delay(BOARD_PHYCFG_DELAY);
	CSL_GPIO_setOutputData(gpioHandle0, BOARD_PR0_MII1_RESET_GPIO_PIN);

    /* Configure GPIO_PR1_MII0_RESETn */
    pinMuxSetMode(BOARD_PR1_MII0_RESET_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirOutput(gpioHandle0, BOARD_PR1_MII0_RESET_GPIO_PIN);
    CSL_GPIO_clearOutputData(gpioHandle0, BOARD_PR1_MII0_RESET_GPIO_PIN);
    BOARD_delay(BOARD_PHYCFG_DELAY);
    CSL_GPIO_setOutputData(gpioHandle0, BOARD_PR1_MII0_RESET_GPIO_PIN);

    /* Configure GPIO_PR1_MII1_RESETn */
    pinMuxSetMode(BOARD_PR1_MII1_RESET_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirOutput(gpioHandle0, BOARD_PR1_MII1_RESET_GPIO_PIN);
    CSL_GPIO_clearOutputData(gpioHandle0, BOARD_PR1_MII1_RESET_GPIO_PIN);
    BOARD_delay(BOARD_PHYCFG_DELAY);
    CSL_GPIO_setOutputData(gpioHandle0, BOARD_PR1_MII1_RESET_GPIO_PIN);
}

/**
 * \brief  Disables pull up/down for SoC pins used for strapping
 *
 * \return  none
 */
static void icssEthPhy_config_pulldowns(void)
{
	uint16_t index;

	for (index = 0; index < BOARD_ICSS_ETHPHY_STRAP_PIN_COUNT; index++)
	{
		pinMuxDisablePullUD(icssEthPhyConfig[index]);
	}
}
#else
/**
 * \brief  Releases Reset lines of the ICSS Ethernet PHYs
 *
 * \return  none
 */
static void icssEthPhy_resetRelease(void)
{
    /* Configure GPIO_PR0_MII0_RESETn */
    pinMuxSetMode(BOARD_PR0_MII0_RESET_PADCONFIG,
	              PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirOutput(gpioHandle0, BOARD_PR0_MII0_RESET_GPIO_PIN);
    CSL_GPIO_setOutputData(gpioHandle0, BOARD_PR0_MII0_RESET_GPIO_PIN);

    /* Configure GPIO_PR0_MII1_RESETn */
    pinMuxSetMode(BOARD_PR0_MII1_RESET_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirOutput(gpioHandle0, BOARD_PR0_MII1_RESET_GPIO_PIN);
	CSL_GPIO_setOutputData(gpioHandle0, BOARD_PR0_MII1_RESET_GPIO_PIN);

    /* Configure GPIO_PR1_MII0_RESETn */
    pinMuxSetMode(BOARD_PR1_MII0_RESET_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirOutput(gpioHandle0, BOARD_PR1_MII0_RESET_GPIO_PIN);
    CSL_GPIO_setOutputData(gpioHandle0, BOARD_PR1_MII0_RESET_GPIO_PIN);

    /* Configure GPIO_PR1_MII1_RESETn */
    pinMuxSetMode(BOARD_PR1_MII1_RESET_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirOutput(gpioHandle0, BOARD_PR1_MII1_RESET_GPIO_PIN);
    CSL_GPIO_setOutputData(gpioHandle0, BOARD_PR1_MII1_RESET_GPIO_PIN);
}
#endif

/**
 * \brief  Resets the ICSS Ethernet PHYs
 *
 * \return  none
 */
static void icssEthPhy_gpio_setup(void)
{
    /* Configure MUX_MII_CTL_PRU0MII0 */
    pinMuxSetMode(BOARD_MUX_MII_CTL_PRU0MII0_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirOutput(gpioHandle0, BOARD_MUX_MII_CTL_PRU0MII0_GPIO_PIN);
	CSL_GPIO_clearOutputData(gpioHandle0, BOARD_MUX_MII_CTL_PRU0MII0_GPIO_PIN);

	/* Configure MUX_MII_CTL_PRU0MII1 */
    pinMuxSetMode(BOARD_MUX_MII_CTL_PRU0MII1_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirOutput(gpioHandle0, BOARD_MUX_MII_CTL_PRU0MII1_GPIO_PIN);
	CSL_GPIO_clearOutputData(gpioHandle0, BOARD_MUX_MII_CTL_PRU0MII1_GPIO_PIN);


	/* Configure OE_PRU0MII0_1 */
    pinMuxSetMode(BOARD_OE_PRU0MII0_1_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirOutput(gpioHandle1, BOARD_OE_PRU0MII0_1_GPIO_PIN);
	CSL_GPIO_clearOutputData(gpioHandle1, BOARD_OE_PRU0MII0_1_GPIO_PIN);

	/* Configure OE_PRU0MII0_2 */
    pinMuxSetMode(BOARD_OE_PRU0MII0_2_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirOutput(gpioHandle1, BOARD_OE_PRU0MII0_2_GPIO_PIN);
	CSL_GPIO_clearOutputData(gpioHandle1, BOARD_OE_PRU0MII0_2_GPIO_PIN);

	/* Configure OE_PRU0MII1_1 */
    pinMuxSetMode(BOARD_OE_PRU0MII1_1_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirOutput(gpioHandle1, BOARD_OE_PRU0MII1_1_GPIO_PIN);
	CSL_GPIO_clearOutputData(gpioHandle1, BOARD_OE_PRU0MII1_1_GPIO_PIN);

	/* Configure OE_PRU0MII1_2 */
    pinMuxSetMode(BOARD_OE_PRU0MII1_2_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirOutput(gpioHandle1, BOARD_OE_PRU0MII1_2_GPIO_PIN);
	CSL_GPIO_clearOutputData(gpioHandle1, BOARD_OE_PRU0MII1_2_GPIO_PIN);


	/* Configure PR0_MII0_INTn */
    pinMuxSetMode(BOARD_PR0_MII0_INT_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirInput(gpioHandle0, BOARD_PR0_MII0_INT_GPIO_PIN);

	/* Configure PR0_MII1_INTn */
    pinMuxSetMode(BOARD_PR0_MII1_INT_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirInput(gpioHandle0, BOARD_PR0_MII1_INT_GPIO_PIN);

	/* Configure PR1_MII0_INTn */
    pinMuxSetMode(BOARD_PR1_MII0_INT_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirInput(gpioHandle0, BOARD_PR1_MII0_INT_GPIO_PIN);

    /* Configure PR1_MII1_INTn */
    pinMuxSetMode(BOARD_PR1_MII1_INT_PADCONFIG,
                  PADCONFIG_MUX_MODE_QUATERNARY);
    CSL_GPIO_setPinDirInput(gpioHandle0, BOARD_PR1_MII1_INT_GPIO_PIN);
}

/**
 * \brief  Board specific configurations for Gigabit Ethernet PHYs
 *
 * This function takes care of configuring the internal delays for gigabit
 * Ethernet PHY. 2.25ns delay is configured for Rx, and .25ns delay is
 * configured for Tx
 *
 * \return  none
 */
Board_STATUS Board_gigEthConfig(void)
{
	uint32_t baseAddr;

	baseAddr = (CSL_NSS_0_CFG_REGS + 0x00200F00);
	CSL_MDIO_init(baseAddr,
	              BOARD_SWITCH_DEFAULT_MDIOCLOCKFREQ,
	              BOARD_SWITCH_DEFAULT_MDIOBUSFREQ);
	/* Disable EEE mode - It is OK to have this config for Beta board as well */
	Mdio_PhyExtendedRegWrite(baseAddr, BOARD_GIGABIT_EMAC_PHY_ADDR, 0x31, 0x170);
	/* TX delay to 0.25ns and the Rx delay to 2.25ns */
    Mdio_PhyExtendedRegWrite(baseAddr, BOARD_GIGABIT_EMAC_PHY_ADDR, 0x86, 0x08);
    Mdio_PhyExtendedRegWrite(baseAddr, BOARD_GIGABIT_EMAC_PHY_ADDR, 0x32, 0xd3);

	return BOARD_SOK;
}

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
Board_STATUS Board_icssEthConfig(void)
{
#ifdef ICEK2G_BETA_BOARD
	gpioHandle0 = CSL_GPIO_open(CSL_GPIO_0);
	gpioHandle1 = CSL_GPIO_open(CSL_GPIO_1);

	/* Disabling internal SoC pull up/down for the pins used for strapping */
	icssEthPhy_config_pulldowns();

	/* Setting the GPIOs for PHY reset, routing ICSS signals to PHYs, PHY interrupt lines */
	icssEthPhy_gpio_setup();

	/* Resetting the PHYs for proper address latching */
	icssEthPhy_reset();

	/* MDIO initialization */
	CSL_MDIO_init(CSL_ICSS_0_MII_MDIO_REGS,
	              BOARD_SWITCH_DEFAULT_MDIOCLOCKFREQ,
	              BOARD_SWITCH_DEFAULT_MDIOBUSFREQ);

	/* MDIO configuration for setting MII mode */
    CSL_MDIO_phyRegWrite(CSL_ICSS_0_MII_MDIO_REGS,
                         BOARD_ICSS_EMAC_PORT0_PHY_ADDR, 0, 0x8000);
	BOARD_delay(BOARD_PHYCFG_DELAY);
    CSL_MDIO_phyRegWrite(CSL_ICSS_0_MII_MDIO_REGS,
                         BOARD_ICSS_EMAC_PORT0_PHY_ADDR, 0x17, 0x41);
    BOARD_delay(BOARD_PHYCFG_DELAY);

    CSL_MDIO_phyRegWrite(CSL_ICSS_0_MII_MDIO_REGS,
                         BOARD_ICSS_EMAC_PORT1_PHY_ADDR, 0, 0x8000);
	BOARD_delay(BOARD_PHYCFG_DELAY);
    CSL_MDIO_phyRegWrite(CSL_ICSS_0_MII_MDIO_REGS,
                         BOARD_ICSS_EMAC_PORT1_PHY_ADDR, 0x17, 0x41);
    BOARD_delay(BOARD_PHYCFG_DELAY);

	CSL_MDIO_init(CSL_ICSS_1_MII_MDIO_REGS,
	              BOARD_SWITCH_DEFAULT_MDIOCLOCKFREQ,
	              BOARD_SWITCH_DEFAULT_MDIOBUSFREQ);

    CSL_MDIO_phyRegWrite(CSL_ICSS_1_MII_MDIO_REGS,
                         BOARD_ICSS_EMAC_PORT2_PHY_ADDR, 0, 0x8000);
	BOARD_delay(BOARD_PHYCFG_DELAY);
    CSL_MDIO_phyRegWrite(CSL_ICSS_1_MII_MDIO_REGS,
                         BOARD_ICSS_EMAC_PORT2_PHY_ADDR, 0x17, 0x41);
    BOARD_delay(BOARD_PHYCFG_DELAY);

    CSL_MDIO_phyRegWrite(CSL_ICSS_1_MII_MDIO_REGS,
                         BOARD_ICSS_EMAC_PORT3_PHY_ADDR, 0, 0x8000);
	BOARD_delay(BOARD_PHYCFG_DELAY);
    CSL_MDIO_phyRegWrite(CSL_ICSS_1_MII_MDIO_REGS,
                         BOARD_ICSS_EMAC_PORT3_PHY_ADDR, 0x17, 0x41);
    BOARD_delay(BOARD_PHYCFG_DELAY);
#else
    uint16_t regVal;

    gpioHandle0 = CSL_GPIO_open(CSL_GPIO_0);
    gpioHandle1 = CSL_GPIO_open(CSL_GPIO_1);

    /* Setting the GPIOs for PHY reset, routing ICSS signals to PHYs, PHY interrupt lines */
    icssEthPhy_gpio_setup();

    /* Release the PHY reset lines.
       All Ethernet PHYs will be out of reset by default.
       Call this function to ensure PHYs are out of reset in any case */
    icssEthPhy_resetRelease();

	/* MDIO initialization */
	CSL_MDIO_init(CSL_ICSS_0_MII_MDIO_REGS,
	              BOARD_SWITCH_DEFAULT_MDIOCLOCKFREQ,
	              BOARD_SWITCH_DEFAULT_MDIOBUSFREQ);

	/* Enable EEE mode PHY0 */
	Mdio_PhyExtendedRegRead(CSL_ICSS_0_MII_MDIO_REGS,
	                        BOARD_ICSS_EMAC_PORT0_PHY_ADDR,
							0x4D1, &regVal);
	regVal = regVal | 0x1;
	Mdio_PhyExtendedRegWrite(CSL_ICSS_0_MII_MDIO_REGS,
	                         BOARD_ICSS_EMAC_PORT0_PHY_ADDR,
							 0x4D1, regVal);
	BOARD_delay(BOARD_PHYCFG_DELAY);

	/* Enable EEE mode - PHY1 */
	Mdio_PhyExtendedRegRead(CSL_ICSS_0_MII_MDIO_REGS,
	                        BOARD_ICSS_EMAC_PORT1_PHY_ADDR,
							0x4D1, &regVal);
	regVal = regVal | 0x1;
	Mdio_PhyExtendedRegWrite(CSL_ICSS_0_MII_MDIO_REGS,
	                         BOARD_ICSS_EMAC_PORT1_PHY_ADDR,
							 0x4D1, regVal);
	BOARD_delay(BOARD_PHYCFG_DELAY);

	CSL_MDIO_init(CSL_ICSS_1_MII_MDIO_REGS,
	              BOARD_SWITCH_DEFAULT_MDIOCLOCKFREQ,
	              BOARD_SWITCH_DEFAULT_MDIOBUSFREQ);

	/* Enable EEE mode - PHY 2 */
	Mdio_PhyExtendedRegRead(CSL_ICSS_1_MII_MDIO_REGS,
	                        BOARD_ICSS_EMAC_PORT2_PHY_ADDR,
							0x4D1, &regVal);
	regVal = regVal | 0x1;
	Mdio_PhyExtendedRegWrite(CSL_ICSS_1_MII_MDIO_REGS,
	                         BOARD_ICSS_EMAC_PORT2_PHY_ADDR,
							 0x4D1, regVal);
	BOARD_delay(BOARD_PHYCFG_DELAY);

	/* Enable EEE mode - PHY 3 */
	Mdio_PhyExtendedRegRead(CSL_ICSS_1_MII_MDIO_REGS,
	                        BOARD_ICSS_EMAC_PORT3_PHY_ADDR,
							0x4D1, &regVal);
	regVal = regVal | 0x1;
	Mdio_PhyExtendedRegWrite(CSL_ICSS_1_MII_MDIO_REGS,
	                         BOARD_ICSS_EMAC_PORT3_PHY_ADDR,
							 0x4D1, regVal);
	BOARD_delay(BOARD_PHYCFG_DELAY);

#endif

	return BOARD_SOK;
}
