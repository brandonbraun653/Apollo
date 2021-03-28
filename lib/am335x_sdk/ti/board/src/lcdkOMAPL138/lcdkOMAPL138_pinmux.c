/**
 *   @file  lcdkOMAP138_pinmux.c
 *
 *   @brief
 *      This is the pin configuration for LCDK OMAPL138.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2017, Texas Instruments, Inc.
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

#include "board_internal.h"
#include <ti/csl/csl_syscfg.h>

/*
 *  \brief  Function to configure McASP module pin mux
 *  
 *  \return None
 */
static void Board_configMcaspPinMux(void)
{
    hSysCfg->PINMUX0 &= (~(CSL_SYSCFG_PINMUX0_PINMUX0_23_20_MASK |
                           CSL_SYSCFG_PINMUX0_PINMUX0_19_16_MASK |
                           CSL_SYSCFG_PINMUX0_PINMUX0_15_12_MASK |
                           CSL_SYSCFG_PINMUX0_PINMUX0_11_8_MASK  |
                           CSL_SYSCFG_PINMUX0_PINMUX0_7_4_MASK   |
                           CSL_SYSCFG_PINMUX0_PINMUX0_3_0_MASK));
    hSysCfg->PINMUX0 |= BOARD_PINMUX0_MCASP_ENABLE;

    hSysCfg->PINMUX1 &= (~(CSL_SYSCFG_PINMUX1_PINMUX1_31_28_MASK |
                           CSL_SYSCFG_PINMUX1_PINMUX1_11_8_MASK  |
                           CSL_SYSCFG_PINMUX1_PINMUX1_7_4_MASK   |
                           CSL_SYSCFG_PINMUX1_PINMUX1_3_0_MASK));
    hSysCfg->PINMUX1 |= BOARD_PINMUX1_MCASP_ENABLE;

    hSysCfg->PINMUX2 &= (~(CSL_SYSCFG_PINMUX2_PINMUX2_3_0_MASK));
    hSysCfg->PINMUX2 |= BOARD_PINMUX2_MCASP_ENABLE;
}

 /*
 *  \brief  Function to configure I2C module pin mux
 *  
 *  \return None
 */
static void Board_configI2cPinMux(void)
{
     /* Enable the pinmux registers for I2c  */
    hSysCfg->PINMUX4 &= (~(CSL_SYSCFG_PINMUX4_PINMUX4_15_12_MASK |
	                       CSL_SYSCFG_PINMUX4_PINMUX4_11_8_MASK ));

    hSysCfg->PINMUX4  |= BOARD_PINMUX4_I2C_ENABLE;  /* I2c0 */
}

/*
 *  \brief  Function to configure MMCSD module pin mux
 *  
 *  \return None
 */
static void Board_configMmcsdPinMux(void)
{
    /* Enable the pinmux configuration for the MMCSD device                   */
    hSysCfg->PINMUX10 &= (~(CSL_SYSCFG_PINMUX10_PINMUX10_31_28_MASK |
                           CSL_SYSCFG_PINMUX10_PINMUX10_27_24_MASK |
                           CSL_SYSCFG_PINMUX10_PINMUX10_23_20_MASK |
                           CSL_SYSCFG_PINMUX10_PINMUX10_19_16_MASK |
                           CSL_SYSCFG_PINMUX10_PINMUX10_15_12_MASK |
                           CSL_SYSCFG_PINMUX10_PINMUX10_11_8_MASK  |
                           CSL_SYSCFG_PINMUX10_PINMUX10_7_4_MASK   |
                           CSL_SYSCFG_PINMUX10_PINMUX10_3_0_MASK));
    hSysCfg->PINMUX10 |= BOARD_PINMUX10_MMCSD_ENABLE;

    hSysCfg->PINMUX11 &= (~(CSL_SYSCFG_PINMUX11_PINMUX11_7_4_MASK   |
                            CSL_SYSCFG_PINMUX11_PINMUX11_3_0_MASK));
    hSysCfg->PINMUX11 |= BOARD_PINMUX11_MMCSD_ENABLE;

    hSysCfg->PINMUX18 &= (~(CSL_SYSCFG_PINMUX18_PINMUX18_19_16_MASK |
                           CSL_SYSCFG_PINMUX18_PINMUX18_15_12_MASK |
                           CSL_SYSCFG_PINMUX18_PINMUX18_11_8_MASK));
    hSysCfg->PINMUX18 |= BOARD_PINMUX18_MMCSD_ENABLE;

    hSysCfg->PINMUX19 &= (~(CSL_SYSCFG_PINMUX19_PINMUX19_19_16_MASK |
                            CSL_SYSCFG_PINMUX19_PINMUX19_15_12_MASK |
                            CSL_SYSCFG_PINMUX19_PINMUX19_11_8_MASK));
    hSysCfg->PINMUX19 |= BOARD_PINMUX19_MMCSD_ENABLE;
}

/*
 *  \brief  Function to configure UART module pin mux
 *  
 *  \return None
 */
static void Board_configUartPinMux(void)
{
    /* enable the pinmux registers for Uart                                   */
    hSysCfg->PINMUX4 &= (~(CSL_SYSCFG_PINMUX4_PINMUX4_31_28_MASK |
                           CSL_SYSCFG_PINMUX4_PINMUX4_27_24_MASK |
                           CSL_SYSCFG_PINMUX4_PINMUX4_23_20_MASK |
                           CSL_SYSCFG_PINMUX4_PINMUX4_19_16_MASK));
    hSysCfg->PINMUX4 |= BOARD_PINMUX4_UART_ENABLE;
}

/*
 *  \brief  Function to configure GPIO module pin mux
 *  
 *  \return None
 */
static void Board_configGpioPinMux(void)
{
    hSysCfg->PINMUX0 &= (~(CSL_SYSCFG_PINMUX0_PINMUX0_27_24_MASK));
    hSysCfg->PINMUX0 |= BOARD_PINMUX0_GPIO_ENABLE;

    hSysCfg->PINMUX1 &= (~(CSL_SYSCFG_PINMUX1_PINMUX1_27_24_MASK |
                           CSL_SYSCFG_PINMUX1_PINMUX1_23_20_MASK |
                           CSL_SYSCFG_PINMUX1_PINMUX1_19_16_MASK |
                           CSL_SYSCFG_PINMUX1_PINMUX1_15_12_MASK));

    hSysCfg->PINMUX1 |= BOARD_PINMUX1_GPIO_ENABLE;

    hSysCfg->PINMUX5 &= (~(CSL_SYSCFG_PINMUX5_PINMUX5_15_12_MASK));
    hSysCfg->PINMUX5 |= BOARD_PINMUX5_GPIO_ENABLE;

    hSysCfg->PINMUX6 &= (~(CSL_SYSCFG_PINMUX6_PINMUX6_15_12_MASK |
                           CSL_SYSCFG_PINMUX6_PINMUX6_11_8_MASK  |
                           CSL_SYSCFG_PINMUX6_PINMUX6_7_4_MASK));
    hSysCfg->PINMUX6 |= BOARD_PINMUX6_GPIO_ENABLE;

    hSysCfg->PINMUX13 &= (~(CSL_SYSCFG_PINMUX13_PINMUX13_31_28_MASK |
                           CSL_SYSCFG_PINMUX13_PINMUX13_27_24_MASK |
                           CSL_SYSCFG_PINMUX13_PINMUX13_23_20_MASK |
                           CSL_SYSCFG_PINMUX13_PINMUX13_19_16_MASK |
                           CSL_SYSCFG_PINMUX13_PINMUX13_15_12_MASK |
                           CSL_SYSCFG_PINMUX13_PINMUX13_11_8_MASK  |
                           CSL_SYSCFG_PINMUX13_PINMUX13_7_4_MASK   |
                           CSL_SYSCFG_PINMUX13_PINMUX13_3_0_MASK));
    hSysCfg->PINMUX13 |= BOARD_PINMUX13_GPIO_ENABLE;

    hSysCfg->PINMUX18 &= (~(CSL_SYSCFG_PINMUX18_PINMUX18_31_28_MASK |
                           CSL_SYSCFG_PINMUX18_PINMUX18_23_20_MASK));
    hSysCfg->PINMUX18 |= BOARD_PINMUX18_GPIO_ENABLE;
}

/*
 *  \brief  Function to configure SPI module pin mux
 *
 *  \return None
 */
static void Board_configSPIPinMux(void)
{
    /* Enable the pinmux registers for SPI  */
    hSysCfg->PINMUX5 &= (~(CSL_SYSCFG_PINMUX5_PINMUX5_23_20_MASK |
                           CSL_SYSCFG_PINMUX5_PINMUX5_19_16_MASK |
                           CSL_SYSCFG_PINMUX5_PINMUX5_11_8_MASK  |
                           CSL_SYSCFG_PINMUX5_PINMUX5_7_4_MASK   |
                           CSL_SYSCFG_PINMUX5_PINMUX5_3_0_MASK));
    hSysCfg->PINMUX5 |= BOARD_PINMUX5_SPI_ENABLE;
}

/*
 *  \brief  Function to configure EMAC module pin mux
 *
 *  \return None
 */
static void Board_configEmacPinMux(void)
{
    /* Enable the pinmux registers for EMAC Tx */
    hSysCfg->PINMUX2 &= (~(CSL_SYSCFG_PINMUX2_PINMUX2_7_4_MASK |
                         CSL_SYSCFG_PINMUX2_PINMUX2_11_8_MASK  |
                         CSL_SYSCFG_PINMUX2_PINMUX2_15_12_MASK |
                         CSL_SYSCFG_PINMUX2_PINMUX2_19_16_MASK |
                         CSL_SYSCFG_PINMUX2_PINMUX2_23_20_MASK |
                         CSL_SYSCFG_PINMUX2_PINMUX2_27_24_MASK |
                         CSL_SYSCFG_PINMUX2_PINMUX2_31_28_MASK ));
    hSysCfg->PINMUX2 |= BOARD_PINMUX2_EMAC_ENABLE;

    /* Enable the pinmux registers for EMAC Rx */
    hSysCfg->PINMUX3 &= (~(CSL_SYSCFG_PINMUX3_PINMUX3_3_0_MASK |
                         CSL_SYSCFG_PINMUX3_PINMUX3_7_4_MASK   |
                         CSL_SYSCFG_PINMUX3_PINMUX3_11_8_MASK  |
                         CSL_SYSCFG_PINMUX3_PINMUX3_15_12_MASK |
                         CSL_SYSCFG_PINMUX3_PINMUX3_19_16_MASK |
                         CSL_SYSCFG_PINMUX3_PINMUX3_23_20_MASK |
                         CSL_SYSCFG_PINMUX3_PINMUX3_27_24_MASK |
                         CSL_SYSCFG_PINMUX3_PINMUX3_31_28_MASK ));
    hSysCfg->PINMUX3 |= BOARD_PINMUX3_EMAC_ENABLE;

    /* Enable the pinmux registers for EMAC MDIO */
    hSysCfg->PINMUX4 &= (~(CSL_SYSCFG_PINMUX4_PINMUX4_3_0_MASK |
                           CSL_SYSCFG_PINMUX4_PINMUX4_7_4_MASK));
    hSysCfg->PINMUX4  |= BOARD_PINMUX4_EMAC_ENABLE;

    /* Select MII mode */
    hSysCfg->CFGCHIP3 &= (~(CSL_SYSCFG_CFGCHIP3_RMII_SEL_MASK ));
    hSysCfg->CFGCHIP3 |= 0x00u;
}

/*
 *  \brief  Function to configure VPIF module pin mux
 *
 *  \return None
 */
static void Board_configVpifPinMux(void)
{
    hSysCfg->PINMUX14 &= (~(CSL_SYSCFG_PINMUX14_PINMUX14_31_28_MASK |
                           CSL_SYSCFG_PINMUX14_PINMUX14_27_24_MASK |
                           CSL_SYSCFG_PINMUX14_PINMUX14_23_20_MASK |
                           CSL_SYSCFG_PINMUX14_PINMUX14_19_16_MASK |
                           CSL_SYSCFG_PINMUX14_PINMUX14_15_12_MASK |
                           CSL_SYSCFG_PINMUX14_PINMUX14_11_8_MASK  |
                           CSL_SYSCFG_PINMUX14_PINMUX14_7_4_MASK   |
                           CSL_SYSCFG_PINMUX14_PINMUX14_3_0_MASK));
    hSysCfg->PINMUX14 |= BOARD_PINMUX14_VPIF_ENABLE;

    hSysCfg->PINMUX15 &= (~(CSL_SYSCFG_PINMUX15_PINMUX15_31_28_MASK |
                           CSL_SYSCFG_PINMUX15_PINMUX15_27_24_MASK |
                           CSL_SYSCFG_PINMUX15_PINMUX15_15_12_MASK |
                           CSL_SYSCFG_PINMUX15_PINMUX15_11_8_MASK  |
                           CSL_SYSCFG_PINMUX15_PINMUX15_7_4_MASK   |
                           CSL_SYSCFG_PINMUX15_PINMUX15_3_0_MASK));
    hSysCfg->PINMUX15 |= BOARD_PINMUX15_VPIF_ENABLE;

    hSysCfg->PINMUX16 &= (~(CSL_SYSCFG_PINMUX16_PINMUX16_7_4_MASK   |
                           CSL_SYSCFG_PINMUX16_PINMUX16_3_0_MASK));
    hSysCfg->PINMUX16 |= BOARD_PINMUX16_VPIF_ENABLE;
}

/*
 *  \brief  Function to configure LCD module pin mux
 *
 *  \return None
 */
static void Board_configLcdPinMux(void)
{
    hSysCfg->PINMUX16 &= (~(CSL_SYSCFG_PINMUX16_PINMUX16_31_28_MASK |
                           CSL_SYSCFG_PINMUX16_PINMUX16_27_24_MASK |
                           CSL_SYSCFG_PINMUX16_PINMUX16_23_20_MASK |
                           CSL_SYSCFG_PINMUX16_PINMUX16_19_16_MASK |
                           CSL_SYSCFG_PINMUX16_PINMUX16_15_12_MASK |
                           CSL_SYSCFG_PINMUX16_PINMUX16_11_8_MASK));
    hSysCfg->PINMUX16 |= BOARD_PINMUX16_LCD_ENABLE;

    hSysCfg->PINMUX17 &= (~(CSL_SYSCFG_PINMUX17_PINMUX17_31_28_MASK |
                           CSL_SYSCFG_PINMUX17_PINMUX17_27_24_MASK |
                           CSL_SYSCFG_PINMUX17_PINMUX17_23_20_MASK |
                           CSL_SYSCFG_PINMUX17_PINMUX17_19_16_MASK |
                           CSL_SYSCFG_PINMUX17_PINMUX17_15_12_MASK |
                           CSL_SYSCFG_PINMUX17_PINMUX17_11_8_MASK  |
                           CSL_SYSCFG_PINMUX17_PINMUX17_7_4_MASK   |
                           CSL_SYSCFG_PINMUX17_PINMUX17_3_0_MASK));
    hSysCfg->PINMUX17 |= BOARD_PINMUX17_LCD_ENABLE;

    hSysCfg->PINMUX18 &= (~(CSL_SYSCFG_PINMUX18_PINMUX18_27_24_MASK |
                            CSL_SYSCFG_PINMUX18_PINMUX18_7_4_MASK   |
                            CSL_SYSCFG_PINMUX18_PINMUX18_3_0_MASK));
    hSysCfg->PINMUX18 |= BOARD_PINMUX18_LCD_ENABLE;

    hSysCfg->PINMUX19 &= (~(CSL_SYSCFG_PINMUX19_PINMUX19_27_24_MASK |
                            CSL_SYSCFG_PINMUX19_PINMUX19_7_4_MASK   |
                            CSL_SYSCFG_PINMUX19_PINMUX19_3_0_MASK));
    hSysCfg->PINMUX19 |= BOARD_PINMUX19_LCD_ENABLE;
}

/*
 *  \brief  Function to configure EMIF module pin mux
 *
 *  This global function is provided to configure the pinmuxing of EMIF
 *  module. EMIF module pin mux is not done as part of Board_init as it
 *  will not work for the programs that are runnning from SDRAM.
 *  This function is intended for the applications which needs to enable
 *  EMIF before loading the user application to SDRAM.
 *
 *  \return None
 */
Board_STATUS Board_configEmifPinMux(void)
{
    hSysCfg->PINMUX5 &= (~(CSL_SYSCFG_PINMUX5_PINMUX5_31_28_MASK |
                           CSL_SYSCFG_PINMUX5_PINMUX5_27_24_MASK));
    hSysCfg->PINMUX5 |= BOARD_PINMUX5_EMIF_ENABLE;

    hSysCfg->PINMUX6 &= (~(CSL_SYSCFG_PINMUX6_PINMUX6_31_28_MASK |
                           CSL_SYSCFG_PINMUX6_PINMUX6_27_24_MASK |
                           CSL_SYSCFG_PINMUX6_PINMUX6_23_20_MASK |
                           CSL_SYSCFG_PINMUX6_PINMUX6_19_16_MASK |
                           CSL_SYSCFG_PINMUX6_PINMUX6_3_0_MASK));
    hSysCfg->PINMUX6 |= BOARD_PINMUX6_EMIF_ENABLE;

    hSysCfg->PINMUX7 &= (~(CSL_SYSCFG_PINMUX7_PINMUX7_31_28_MASK |
                           CSL_SYSCFG_PINMUX7_PINMUX7_27_24_MASK |
                           CSL_SYSCFG_PINMUX7_PINMUX7_23_20_MASK |
                           CSL_SYSCFG_PINMUX7_PINMUX7_19_16_MASK |
                           CSL_SYSCFG_PINMUX7_PINMUX7_15_12_MASK |
                           CSL_SYSCFG_PINMUX7_PINMUX7_11_8_MASK  |
                           CSL_SYSCFG_PINMUX7_PINMUX7_7_4_MASK   |
                           CSL_SYSCFG_PINMUX7_PINMUX7_3_0_MASK));
    hSysCfg->PINMUX7 |= BOARD_PINMUX7_EMIF_ENABLE;

    hSysCfg->PINMUX8 &= (~(CSL_SYSCFG_PINMUX8_PINMUX8_31_28_MASK |
                           CSL_SYSCFG_PINMUX8_PINMUX8_27_24_MASK |
                           CSL_SYSCFG_PINMUX8_PINMUX8_23_20_MASK |
                           CSL_SYSCFG_PINMUX8_PINMUX8_19_16_MASK |
                           CSL_SYSCFG_PINMUX8_PINMUX8_15_12_MASK |
                           CSL_SYSCFG_PINMUX8_PINMUX8_11_8_MASK  |
                           CSL_SYSCFG_PINMUX8_PINMUX8_7_4_MASK   |
                           CSL_SYSCFG_PINMUX8_PINMUX8_3_0_MASK));
    hSysCfg->PINMUX8 |= BOARD_PINMUX8_EMIF_ENABLE;

    hSysCfg->PINMUX9 &= (~(CSL_SYSCFG_PINMUX9_PINMUX9_31_28_MASK |
                           CSL_SYSCFG_PINMUX9_PINMUX9_27_24_MASK |
                           CSL_SYSCFG_PINMUX9_PINMUX9_23_20_MASK |
                           CSL_SYSCFG_PINMUX9_PINMUX9_19_16_MASK |
                           CSL_SYSCFG_PINMUX9_PINMUX9_15_12_MASK |
                           CSL_SYSCFG_PINMUX9_PINMUX9_11_8_MASK  |
                           CSL_SYSCFG_PINMUX9_PINMUX9_7_4_MASK   |
                           CSL_SYSCFG_PINMUX9_PINMUX9_3_0_MASK));
    hSysCfg->PINMUX9 |= BOARD_PINMUX9_EMIF_ENABLE;

    hSysCfg->PINMUX11 &= (~(CSL_SYSCFG_PINMUX11_PINMUX11_31_28_MASK |
                           CSL_SYSCFG_PINMUX11_PINMUX11_27_24_MASK |
                           CSL_SYSCFG_PINMUX11_PINMUX11_23_20_MASK |
                           CSL_SYSCFG_PINMUX11_PINMUX11_19_16_MASK |
                           CSL_SYSCFG_PINMUX11_PINMUX11_15_12_MASK));
    hSysCfg->PINMUX11 |= BOARD_PINMUX11_EMIF_ENABLE;

    hSysCfg->PINMUX12 &= (~(CSL_SYSCFG_PINMUX12_PINMUX12_31_28_MASK |
                           CSL_SYSCFG_PINMUX12_PINMUX12_27_24_MASK |
                           CSL_SYSCFG_PINMUX12_PINMUX12_23_20_MASK |
                           CSL_SYSCFG_PINMUX12_PINMUX12_19_16_MASK |
                           CSL_SYSCFG_PINMUX12_PINMUX12_15_12_MASK |
                           CSL_SYSCFG_PINMUX12_PINMUX12_11_8_MASK  |
                           CSL_SYSCFG_PINMUX12_PINMUX12_7_4_MASK   |
                           CSL_SYSCFG_PINMUX12_PINMUX12_3_0_MASK));
    hSysCfg->PINMUX12 |= BOARD_PINMUX12_EMIF_ENABLE;

    return (BOARD_SOK);
}

/**
 * \brief  Configures default mode for pinmuxing sys config registers
 *
 * \return  none
 */
Board_STATUS Board_pinmuxConfig (void)
{
	/* Configure UART Pin mux */
	Board_configUartPinMux();

	/* Configure I2C Pin mux */
	Board_configI2cPinMux();

	/* Configure McASP Pin mux */
	Board_configMcaspPinMux();

	/* Configure MMCSDP Pin mux */
	Board_configMmcsdPinMux();

	/* Configure GPIO Pin mux */
	Board_configGpioPinMux();

    /* Configure SPI Pin mux */
    Board_configSPIPinMux();

    /* Configure EMAC Pin mux */
    Board_configEmacPinMux();

    /* Configure EMIF Pin mux */
    Board_configLcdPinMux();

    /* Configure EMIF Pin mux */
    Board_configVpifPinMux();

    /* Use the default pin mux configuration */
    return (BOARD_SOK);
}
