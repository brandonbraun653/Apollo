/**
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

/**
 * \file   AM65xx_pinmux_data.c
 *
 * \brief  This file contains the pin mux configurations for the boards.
 *         These are prepared based on how the peripherals are extended on
 *         the boards.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "AM65xx_pinmux.h"

/** Peripheral Pin Configurations */


static pinmuxPerCfg_t gCal0PinCfg[] =
{
    {PINMUX_END}
};

static pinmuxModuleCfg_t gCalPinCfg[] =
{
    {0, TRUE, gCal0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gDdr0PinCfg[] =
{
    {PINMUX_END}
};

static pinmuxModuleCfg_t gDdrPinCfg[] =
{
    {0, TRUE, gDdr0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gDebugss0PinCfg[] =
{
    /* DEBUGSS -> TMS -> A21 */
    {
        PIN_TMS, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* DEBUGSS -> TDI -> C20 */
    {
        PIN_TDI, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* DEBUGSS -> TDO -> A20 */
    {
        PIN_TDO, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gDebugssPinCfg[] =
{
    {0, TRUE, gDebugss0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gEcap0PinCfg[] =
{
    /* ECAP0 -> ECAP0_IN_APWM_OUT -> D21 */
    {
        PIN_ECAP0_IN_APWM_OUT, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gEcapPinCfg[] =
{
    {0, TRUE, gEcap0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gGpio0PinCfg[] =
{
    /* GPIO0 -> GPIO0_61 -> AF27 */
    {
        PIN_PRG1_PRU0_GPO5, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO0 -> GPIO0_64 -> AF28 */
    {
        PIN_PRG1_PRU0_GPO8, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO0 -> GPIO0_65 -> AF26 */
    {
        PIN_PRG1_PRU0_GPO8, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO0 -> GPIO0_73 -> AH26 */
    {
        PIN_PRG1_PRU0_GPO17, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO0 -> GPIO0_81 -> AC22 */
    {
        PIN_PRG1_PRU1_GPO5, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO0 -> GPIO0_75 -> AG26 */
    {
        PIN_PRG1_PRU0_GPO19, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO0 -> GPIO0_84 -> AE24 */
    {
        PIN_PRG1_PRU1_GPO8, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
	/* GPIO0 -> GPIO0_95 -> AC21 */
    {
        PIN_PRG1_PRU1_GPO19, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO0 -> GPIO0_93 -> AE23 */
    {
        PIN_PRG1_PRU1_GPO17, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO0 -> GPIO0_65 -> AF26 */
    {
        PIN_PRG1_PRU0_GPO9, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};
static pinmuxPerCfg_t gGpio1PinCfg[] =
{
#if !(defined(AM65XX_BETA_BOARD))
    /* GPIO1 -> GPIO1_14 -> B23 */
    {
        PIN_MMC0_SDWP, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
#endif
    /* GPIO1 -> GPIO1_34 -> V28 */
    {
        PIN_PRG0_PRU0_GPO5, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_37 -> V27 */
    {
        PIN_PRG0_PRU0_GPO8, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_38 -> V26 */
    {
        PIN_PRG0_PRU0_GPO9, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_39 -> U25 */
    {
        PIN_PRG0_PRU0_GPO10, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_46 -> U26 */
    {
        PIN_PRG0_PRU0_GPO17, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_48 -> U24 */
    {
        PIN_PRG0_PRU0_GPO19, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_54 -> U23 */
    {
        PIN_PRG0_PRU1_GPO5, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_57 -> W27 */
    {
        PIN_PRG0_PRU1_GPO8, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_58 -> Y28 */
    {
        PIN_PRG0_PRU1_GPO9, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_59 -> AA28 */
    {
        PIN_PRG0_PRU1_GPO10, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_66 -> Y27 */
    {
        PIN_PRG0_PRU1_GPO17, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_68 -> W26 */
    {
        PIN_PRG0_PRU1_GPO19, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_81 -> F18 */
    {
        PIN_NMIN, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_47 */
    {
        PIN_PRG0_PRU0_GPO18, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* GPIO1 -> GPIO1_67 */
    {
        PIN_PRG0_PRU1_GPO18, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gGpioPinCfg[] =
{
    {0, TRUE, gGpio0PinCfg},
    {1, TRUE, gGpio1PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gI2c0PinCfg[] =
{
    /* I2C0 -> I2C0_SCL -> D20 */
    {
        PIN_I2C0_SCL, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* I2C0 -> I2C0_SDA -> C21 */
    {
        PIN_I2C0_SDA, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};
static pinmuxPerCfg_t gI2c1PinCfg[] =
{
    /* I2C1 -> I2C1_SCL -> B21 */
    {
        PIN_I2C1_SCL, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* I2C1 -> I2C1_SDA -> E21 */
    {
        PIN_I2C1_SDA, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};
static pinmuxPerCfg_t gI2c2PinCfg[] =
{
    /* I2C2 -> I2C2_SCL -> T27 */
    {
        PIN_GPMC0_CSN3, PIN_MODE(5) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* I2C2 -> I2C2_SDA -> R25 */
    {
        PIN_GPMC0_CSN2, PIN_MODE(5) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gI2cPinCfg[] =
{
    {0, TRUE, gI2c0PinCfg},
    {1, TRUE, gI2c1PinCfg},
    {2, TRUE, gI2c2PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gMcu_adc0PinCfg[] =
{
    {PINMUX_END}
};
static pinmuxPerCfg_t gMcu_adc1PinCfg[] =
{
    {PINMUX_END}
};

static pinmuxModuleCfg_t gMcu_adcPinCfg[] =
{
    {0, TRUE, gMcu_adc0PinCfg},
    {1, TRUE, gMcu_adc1PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gMcu_cpsw0PinCfg[] =
{
    /* MCU_CPSW -> MCU_RGMII1_TX_CTL -> N4 */
    {
        PIN_MCU_RGMII1_TX_CTL, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_CPSW -> MCU_RGMII1_RX_CTL -> N5 */
    {
        PIN_MCU_RGMII1_RX_CTL, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_CPSW -> MCU_RGMII1_TD3 -> M2 */
    {
        PIN_MCU_RGMII1_TD3, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MCU_CPSW -> MCU_RGMII1_TD2 -> M3 */
    {
        PIN_MCU_RGMII1_TD2, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MCU_CPSW -> MCU_RGMII1_TD1 -> M4 */
    {
        PIN_MCU_RGMII1_TD1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MCU_CPSW -> MCU_RGMII1_TD0 -> M5 */
    {
        PIN_MCU_RGMII1_TD0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MCU_CPSW -> MCU_RGMII1_RD3 -> L2 */
    {
        PIN_MCU_RGMII1_RD3, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_CPSW -> MCU_RGMII1_RD2 -> L5 */
    {
        PIN_MCU_RGMII1_RD2, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_CPSW -> MCU_RGMII1_RD1 -> M6 */
    {
        PIN_MCU_RGMII1_RD1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_CPSW -> MCU_RGMII1_RD0 -> L6 */
    {
        PIN_MCU_RGMII1_RD0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_CPSW -> MCU_RGMII1_TXC -> N1 */
    {
        PIN_MCU_RGMII1_TXC, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_CPSW -> MCU_RGMII1_RXC -> M1 */
    {
        PIN_MCU_RGMII1_RXC, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gMcu_cpswPinCfg[] =
{
    {0, TRUE, gMcu_cpsw0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gMcu_fss0_ospi0PinCfg[] =
{
    /* MCU_OSPI0 -> MCU_OSPI0_CLK -> V1 */
    {
        PIN_MCU_OSPI0_CLK, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MCU_OSPI0 -> MCU_OSPI0_CSn0 -> R4 */
    {
        PIN_MCU_OSPI0_CSN0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MCU_OSPI0 -> MCU_OSPI0_D0 -> U4 */
    {
        PIN_MCU_OSPI0_D0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_OSPI0 -> MCU_OSPI0_D1 -> U5 */
    {
        PIN_MCU_OSPI0_D1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_OSPI0 -> MCU_OSPI0_D2 -> T2 */
    {
        PIN_MCU_OSPI0_D2, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_OSPI0 -> MCU_OSPI0_D3 -> T3 */
    {
        PIN_MCU_OSPI0_D3, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_OSPI0 -> MCU_OSPI0_D4 -> T4 */
    {
        PIN_MCU_OSPI0_D4, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_OSPI0 -> MCU_OSPI0_D5 -> T5 */
    {
        PIN_MCU_OSPI0_D5, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_OSPI0 -> MCU_OSPI0_D6 -> R2 */
    {
        PIN_MCU_OSPI0_D6, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_OSPI0 -> MCU_OSPI0_D7 -> R3 */
    {
        PIN_MCU_OSPI0_D7, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_OSPI0 -> MCU_OSPI0_DQS -> U2 */
    {
        PIN_MCU_OSPI0_DQS, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gMcu_fss0_ospiPinCfg[] =
{
    {0, TRUE, gMcu_fss0_ospi0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gMcu_i2c0PinCfg[] =
{
    /* MCU_I2C0 -> MCU_I2C0_SCL -> AD8 */
    {
        PIN_MCU_I2C0_SCL, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_I2C0 -> MCU_I2C0_SDA -> AD7 */
    {
        PIN_MCU_I2C0_SDA, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gMcu_i2cPinCfg[] =
{
    {0, TRUE, gMcu_i2c0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gMcu_mcan0PinCfg[] =
{
    /* MCU_MCAN0 -> MCU_MCAN0_RX -> W2 */
    {
        PIN_MCU_MCAN0_RX, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_MCAN0 -> MCU_MCAN0_TX -> W1 */
    {
        PIN_MCU_MCAN0_TX, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};
static pinmuxPerCfg_t gMcu_mcan1PinCfg[] =
{
    /* MCU_MCAN1 -> MCU_MCAN1_RX -> AD3 */
    {
        PIN_WKUP_GPIO0_5, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_MCAN1 -> MCU_MCAN1_TX -> AC3 */
    {
        PIN_WKUP_GPIO0_4, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gMcu_mcanPinCfg[] =
{
    {0, TRUE, gMcu_mcan0PinCfg},
    {1, TRUE, gMcu_mcan1PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gMcu_mdio0PinCfg[] =
{
    /* MCU_MDIO0 -> MCU_MDIO0_MDC -> L1 */
    {
        PIN_MCU_MDIO0_MDC, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MCU_MDIO0 -> MCU_MDIO0_MDIO -> L4 */
    {
        PIN_MCU_MDIO0_MDIO, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gMcu_mdioPinCfg[] =
{
    {0, TRUE, gMcu_mdio0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gMcu_spi0PinCfg[] =
{
    /* MCU_SPI -> MCU_SPI0_CLK -> Y1 */
    {
        PIN_MCU_SPI0_CLK, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MCU_SPI -> MCU_SPI0_CS0 -> Y4 */
    {
        PIN_MCU_SPI0_CS0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MCU_SPI -> MCU_SPI0_D0 -> Y3 */
    {
        PIN_MCU_SPI0_D0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gMcu_spiPinCfg[] =
{
    {0, TRUE, gMcu_spi0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gMcu_uart0PinCfg[] =
{
    /* MCU_UART0 -> MCU_UART0_RXD -> P4 */
    {
        PIN_MCU_OSPI1_D1, PIN_MODE(4) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_UART0 -> MCU_UART0_TXD -> P5 */
    {
        PIN_MCU_OSPI1_D2, PIN_MODE(4) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MCU_UART0 -> MCU_UART0_CTS -> P1 */
    {
        PIN_MCU_OSPI1_D3, PIN_MODE(4) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MCU_UART0 -> MCU_UART0_RTS -> P4 */
    {
        PIN_MCU_OSPI1_CSN1, PIN_MODE(4) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gMcu_uartPinCfg[] =
{
    {0, TRUE, gMcu_uart0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gMmc0PinCfg[] =
{
    /* MMC0 -> MMC0_CLK -> B25 */
    {
        PIN_MMC0_CLK, PIN_MODE(0) | \
        ((PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE & ~PIN_PULL_DIRECTION))
    },
    /* MMC0 -> MMC0_CMD -> B27 */
    {
        PIN_MMC0_CMD, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC0 -> MMC0_DAT0 -> A26 */
    {
        PIN_MMC0_DAT0, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC0 -> MMC0_DAT1 -> E25 */
    {
        PIN_MMC0_DAT1, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC0 -> MMC0_DAT2 -> C26 */
    {
        PIN_MMC0_DAT2, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC0 -> MMC0_DAT3 -> A25 */
    {
        PIN_MMC0_DAT3, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC0 -> MMC0_DAT4 -> E24 */
    {
        PIN_MMC0_DAT4, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC0 -> MMC0_DAT5 -> A24 */
    {
        PIN_MMC0_DAT5, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC0 -> MMC0_DAT6 -> B26 */
    {
        PIN_MMC0_DAT6, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC0 -> MMC0_DAT7 -> D25 */
    {
        PIN_MMC0_DAT7, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC0 -> MMC0_DS -> C25 */
    {
        PIN_MMC0_DS, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* MMC0 -> MMC0_SDCD -> A23 */
    {
        PIN_MMC0_SDCD, PIN_MODE(0) | \
        ((PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION | ~PIN_PULL_DISABLE))
    },
#if defined(AM65XX_BETA_BOARD)
    /* MMC0 -> MMC0_SDWP -> B23 */
    {
        PIN_MMC0_SDWP, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
#endif
    {PINMUX_END}
};
static pinmuxPerCfg_t gMmc1PinCfg[] =
{
    /* MMC1 -> MMC1_CLK -> C27 */
    {
        PIN_MMC1_CLK, PIN_MODE(0) | \
        ((PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE & ~PIN_PULL_DIRECTION))
    },
    /* MMC1 -> MMC1_CMD -> C28 */
    {
        PIN_MMC1_CMD, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC1 -> MMC1_DAT0 -> D28 */
    {
        PIN_MMC1_DAT0, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC1 -> MMC1_DAT1 -> E27 */
    {
        PIN_MMC1_DAT1, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC1 -> MMC1_DAT2 -> D26 */
    {
        PIN_MMC1_DAT2, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC1 -> MMC1_DAT3 -> D27 */
    {
        PIN_MMC1_DAT3, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    /* MMC1 -> MMC1_SDCD -> B24 */
    {
        PIN_MMC1_SDCD, PIN_MODE(0) | \
        ((PIN_PULL_DIRECTION | PIN_INPUT_ENABLE) & (~PIN_PULL_DISABLE))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gMmcPinCfg[] =
{
    {0, TRUE, gMmc0PinCfg},
    {1, TRUE, gMmc1PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gOldi0PinCfg[] =
{
    {PINMUX_END}
};

static pinmuxModuleCfg_t gOldiPinCfg[] =
{
    {0, TRUE, gOldi0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gOsc00PinCfg[] =
{
    {PINMUX_END}
};

static pinmuxModuleCfg_t gOsc0PinCfg[] =
{
    {0, TRUE, gOsc00PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gPru_icssg0_mdio0PinCfg[] =
{
    /* PRU_ICSSG0_MDIO -> PRG0_MDIO0_MDIO -> AE26 */
    {
        PIN_PRG0_MDIO0_MDIO, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_MDIO -> PRG0_MDIO0_MDC -> AE28 */
    {
        PIN_PRG0_MDIO0_MDC, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gPru_icssg0_mdioPinCfg[] =
{
    {0, TRUE, gPru_icssg0_mdio0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gPru_icssg0_rgmii1PinCfg[] =
{
    /* PRU_ICSSG0_RGMII1 -> PRG0_RGMII1_RD0 -> V24 */
    {
        PIN_PRG0_PRU0_GPO0, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_RGMII1 -> PRG0_RGMII1_RD1 -> W25 */
    {
        PIN_PRG0_PRU0_GPO1, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_RGMII1 -> PRG0_RGMII1_RD2 -> W24 */
    {
        PIN_PRG0_PRU0_GPO2, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_RGMII1 -> PRG0_RGMII1_RD3 -> AA27 */
    {
        PIN_PRG0_PRU0_GPO3, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_RGMII1 -> PRG0_RGMII1_TD0 -> AD27 */
    {
        PIN_PRG0_PRU0_GPO12, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG0_RGMII1 -> PRG0_RGMII1_TD1 -> AC26 */
    {
        PIN_PRG0_PRU0_GPO13, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG0_RGMII1 -> PRG0_RGMII1_TD2 -> AD26 */
    {
        PIN_PRG0_PRU0_GPO14, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG0_RGMII1 -> PRG0_RGMII1_TD3 -> AA24 */
    {
        PIN_PRG0_PRU0_GPO15, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG0_RGMII1 -> PRG0_RGMII1_TXC -> AD28 */
    {
        PIN_PRG0_PRU0_GPO16, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_RGMII1 -> PRG0_RGMII1_TX_CTL -> AB25 */
    {
        PIN_PRG0_PRU0_GPO11, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG0_RGMII1 -> PRG0_RGMII1_RXC -> Y25 */
    {
        PIN_PRG0_PRU0_GPO6, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_RGMII1 -> PRG0_RGMII1_RX_CTL -> Y24 */
    {
        PIN_PRG0_PRU0_GPO4, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};
static pinmuxPerCfg_t gPru_icssg0_rgmii2PinCfg[] =
{
    /* PRU_ICSSG0_RGMII2 -> PRG0_RGMII2_RD0 -> AB28 */
    {
        PIN_PRG0_PRU1_GPO0, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_RGMII2 -> PRG0_RGMII2_RD1 -> AC28 */
    {
        PIN_PRG0_PRU1_GPO1, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_RGMII2 -> PRG0_RGMII2_RD2 -> AC27 */
    {
        PIN_PRG0_PRU1_GPO2, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_RGMII2 -> PRG0_RGMII2_RD3 -> AB26 */
    {
        PIN_PRG0_PRU1_GPO3, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_RGMII2 -> PRG0_RGMII2_TD0 -> AC25 */
    {
        PIN_PRG0_PRU1_GPO12, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG0_RGMII2 -> PRG0_RGMII2_TD1 -> AD25 */
    {
        PIN_PRG0_PRU1_GPO13, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG0_RGMII2 -> PRG0_RGMII2_TD2 -> AD24 */
    {
        PIN_PRG0_PRU1_GPO14, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG0_RGMII2 -> PRG0_RGMII2_TD3 -> AE27 */
    {
        PIN_PRG0_PRU1_GPO15, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG0_RGMII2 -> PRG0_RGMII2_TXC -> AC24 */
    {
        PIN_PRG0_PRU1_GPO16, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_RGMII2 -> PRG0_RGMII2_TX_CTL -> AB24 */
    {
        PIN_PRG0_PRU1_GPO11, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG0_RGMII2 -> PRG0_RGMII2_RXC -> AB27 */
    {
        PIN_PRG0_PRU1_GPO6, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG0_RGMII2 -> PRG0_RGMII2_RX_CTL -> AA25 */
    {
        PIN_PRG0_PRU1_GPO4, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gPru_icssg0_rgmiiPinCfg[] =
{
    {1, TRUE, gPru_icssg0_rgmii1PinCfg},
    {2, TRUE, gPru_icssg0_rgmii2PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gPru_icssg1_mdio0PinCfg[] =
{
    /* PRU_ICSSG1_MDIO -> PRG1_MDIO0_MDIO -> AD18 */
    {
        PIN_PRG1_MDIO0_MDIO, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_MDIO -> PRG1_MDIO0_MDC -> AH18 */
    {
        PIN_PRG1_MDIO0_MDC, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gPru_icssg1_mdioPinCfg[] =
{
    {0, TRUE, gPru_icssg1_mdio0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gPru_icssg1_rgmii1PinCfg[] =
{
    /* PRU_ICSSG1_RGMII1 -> PRG1_RGMII1_RD0 -> AE22 */
    {
        PIN_PRG1_PRU0_GPO0, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_RGMII1 -> PRG1_RGMII1_RD1 -> AG24 */
    {
        PIN_PRG1_PRU0_GPO1, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_RGMII1 -> PRG1_RGMII1_RD2 -> AF23 */
    {
        PIN_PRG1_PRU0_GPO2, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_RGMII1 -> PRG1_RGMII1_RD3 -> AD21 */
    {
        PIN_PRG1_PRU0_GPO3, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_RGMII1 -> PRG1_RGMII1_TD0 -> AH20 */
    {
        PIN_PRG1_PRU0_GPO12, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG1_RGMII1 -> PRG1_RGMII1_TD1 -> AH21 */
    {
        PIN_PRG1_PRU0_GPO13, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG1_RGMII1 -> PRG1_RGMII1_TD2 -> AG20 */
    {
        PIN_PRG1_PRU0_GPO14, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG1_RGMII1 -> PRG1_RGMII1_TD3 -> AD19 */
    {
        PIN_PRG1_PRU0_GPO15, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG1_RGMII1 -> PRG1_RGMII1_TXC -> AD20 */
    {
        PIN_PRG1_PRU0_GPO16, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_RGMII1 -> PRG1_RGMII1_TX_CTL -> AF21 */
    {
        PIN_PRG1_PRU0_GPO11, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG1_RGMII1 -> PRG1_RGMII1_RXC -> AF22 */
    {
        PIN_PRG1_PRU0_GPO6, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_RGMII1 -> PRG1_RGMII1_RX_CTL -> AG23 */
    {
        PIN_PRG1_PRU0_GPO4, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};
static pinmuxPerCfg_t gPru_icssg1_rgmii2PinCfg[] =
{
    /* PRU_ICSSG1_RGMII2 -> PRG1_RGMII2_RD0 -> AH24 */
    {
        PIN_PRG1_PRU1_GPO0, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_RGMII2 -> PRG1_RGMII2_RD1 -> AH23 */
    {
        PIN_PRG1_PRU1_GPO1, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_RGMII2 -> PRG1_RGMII2_RD2 -> AG21 */
    {
        PIN_PRG1_PRU1_GPO2, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_RGMII2 -> PRG1_RGMII2_RD3 -> AH22 */
    {
        PIN_PRG1_PRU1_GPO3, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_RGMII2 -> PRG1_RGMII2_TD0 -> AE20 */
    {
        PIN_PRG1_PRU1_GPO12, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG1_RGMII2 -> PRG1_RGMII2_TD1 -> AF19 */
    {
        PIN_PRG1_PRU1_GPO13, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG1_RGMII2 -> PRG1_RGMII2_TD2 -> AH19 */
    {
        PIN_PRG1_PRU1_GPO14, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG1_RGMII2 -> PRG1_RGMII2_TD3 -> AG19 */
    {
        PIN_PRG1_PRU1_GPO15, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG1_RGMII2 -> PRG1_RGMII2_TXC -> AE19 */
    {
        PIN_PRG1_PRU1_GPO16, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_RGMII2 -> PRG1_RGMII2_TX_CTL -> AC20 */
    {
        PIN_PRG1_PRU1_GPO11, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG1_RGMII2 -> PRG1_RGMII2_RXC -> AG22 */
    {
        PIN_PRG1_PRU1_GPO6, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG1_RGMII2 -> PRG1_RGMII2_RX_CTL -> AE21 */
    {
        PIN_PRG1_PRU1_GPO4, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gPru_icssg1_rgmiiPinCfg[] =
{
    {1, TRUE, gPru_icssg1_rgmii1PinCfg},
    {2, TRUE, gPru_icssg1_rgmii2PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gPru_icssg2_mdio0PinCfg[] =
{
    /* PRU_ICSSG2_MDIO -> PRG2_MDIO0_MDIO -> AC19 */
    {
        PIN_PRG2_PRU0_GPO7, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_MDIO -> PRG2_MDIO0_MDC -> AE15 */
    {
        PIN_PRG2_PRU1_GPO7, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gPru_icssg2_mdioPinCfg[] =
{
    {0, TRUE, gPru_icssg2_mdio0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gPru_icssg2_rgmii1PinCfg[] =
{
    /* PRU_ICSSG2_RGMII1 -> PRG2_RGMII1_RD0 -> AF18 */
    {
        PIN_PRG2_PRU0_GPO0, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_RGMII1 -> PRG2_RGMII1_RD1 -> AE18 */
    {
        PIN_PRG2_PRU0_GPO1, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_RGMII1 -> PRG2_RGMII1_RD2 -> AH17 */
    {
        PIN_PRG2_PRU0_GPO2, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_RGMII1 -> PRG2_RGMII1_RD3 -> AG18 */
    {
        PIN_PRG2_PRU0_GPO3, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_RGMII1 -> PRG2_RGMII1_TD0 -> AH16 */
    {
        PIN_PRG2_PRU0_GPO8, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG2_RGMII1 -> PRG2_RGMII1_TD1 -> AG16 */
    {
        PIN_PRG2_PRU0_GPO9, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG2_RGMII1 -> PRG2_RGMII1_TD2 -> AF16 */
    {
        PIN_PRG2_PRU0_GPO10, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG2_RGMII1 -> PRG2_RGMII1_TD3 -> AE16 */
    {
        PIN_PRG2_PRU0_GPO11, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG2_RGMII1 -> PRG2_RGMII1_TXC -> AD16 */
    {
        PIN_PRG2_PRU0_GPO16, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_RGMII1 -> PRG2_RGMII1_TX_CTL -> AE17 */
    {
        PIN_PRG2_PRU0_GPO6, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG2_RGMII1 -> PRG2_RGMII1_RXC -> AF17 */
    {
        PIN_PRG2_PRU0_GPO5, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_RGMII1 -> PRG2_RGMII1_RX_CTL -> AG17 */
    {
        PIN_PRG2_PRU0_GPO4, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};
static pinmuxPerCfg_t gPru_icssg2_rgmii2PinCfg[] =
{
    /* PRU_ICSSG2_RGMII2 -> PRG2_RGMII2_RD0 -> AH15 */
    {
        PIN_PRG2_PRU1_GPO0, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_RGMII2 -> PRG2_RGMII2_RD1 -> AC16 */
    {
        PIN_PRG2_PRU1_GPO1, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_RGMII2 -> PRG2_RGMII2_RD2 -> AD17 */
    {
        PIN_PRG2_PRU1_GPO2, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_RGMII2 -> PRG2_RGMII2_RD3 -> AH14 */
    {
        PIN_PRG2_PRU1_GPO3, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_RGMII2 -> PRG2_RGMII2_TD0 -> AD15 */
    {
        PIN_PRG2_PRU1_GPO8, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG2_RGMII2 -> PRG2_RGMII2_TD1 -> AF14 */
    {
        PIN_PRG2_PRU1_GPO9, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG2_RGMII2 -> PRG2_RGMII2_TD2 -> AC15 */
    {
        PIN_PRG2_PRU1_GPO10, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG2_RGMII2 -> PRG2_RGMII2_TD3 -> AD14 */
    {
        PIN_PRG2_PRU1_GPO11, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG2_RGMII2 -> PRG2_RGMII2_TXC -> AE14 */
    {
        PIN_PRG2_PRU1_GPO16, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_RGMII2 -> PRG2_RGMII2_TX_CTL -> AC17 */
    {
        PIN_PRG2_PRU1_GPO6, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* PRU_ICSSG2_RGMII2 -> PRG2_RGMII2_RXC -> AG15 */
    {
        PIN_PRG2_PRU1_GPO5, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* PRU_ICSSG2_RGMII2 -> PRG2_RGMII2_RX_CTL -> AG14 */
    {
        PIN_PRG2_PRU1_GPO4, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gPru_icssg2_rgmiiPinCfg[] =
{
    {1, TRUE, gPru_icssg2_rgmii1PinCfg},
    {2, TRUE, gPru_icssg2_rgmii2PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gSerdes0PinCfg[] =
{
    {PINMUX_END}
};
static pinmuxPerCfg_t gSerdes1PinCfg[] =
{
    {PINMUX_END}
};

static pinmuxModuleCfg_t gSerdesPinCfg[] =
{
    {0, TRUE, gSerdes0PinCfg},
    {1, TRUE, gSerdes1PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gSpi0PinCfg[] =
{
    /* SPI0 -> SPI0_CLK -> AH13 */
    {
        PIN_SPI0_CLK, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* SPI0 -> SPI0_D0 -> AE13 */
    {
        PIN_SPI0_D0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* SPI0 -> SPI0_D1 -> AD13 */
    {
        PIN_SPI0_D1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* SPI0 -> SPI0_CS0 -> AG13 */
    {
        PIN_SPI0_CS0, PIN_MODE(0) | \
        ((~PIN_PULL_DISABLE) & (PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* SPI0 -> SPI0_CS1 -> AF13 */
    {
        PIN_SPI0_CS1, PIN_MODE(0) | \
        ((~PIN_PULL_DISABLE) & (PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxPerCfg_t gSpi1PinCfg[] =
{
    /* SPI1 -> SPI1_CLK -> AH12 */
    {
        PIN_SPI1_CLK, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* SPI1 -> SPI1_D0 -> AE12 */
    {
        PIN_SPI1_D0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* SPI1 -> SPI1_D1 -> AF12 */
    {
        PIN_SPI1_D1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* SPI1 -> SPI1_CS0 -> AD12 */
    {
        PIN_SPI1_CS0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* SPI1 -> SPI1_CS1 -> AG12 */
    {
        PIN_SPI1_CS1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gSpiPinCfg[] =
{
    {0, TRUE, gSpi0PinCfg},
    {1, TRUE, gSpi1PinCfg},
    {PINMUX_END}
};


pinmuxPerCfg_t gSystem0PinCfgPG1[] =
{
    /* SYSTEM -> RESETz -> F17 */
    {
        PIN_RESETZ, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* SYSTEM -> PORz -> E19 */
    {
        PIN_PORZ, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* SYSTEM -> RESETSTATz -> D19 */
    {
        PIN_RESETSTATZ, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* SYSTEM -> PORz_OUT -> C19 */
    {
        PIN_PORZ_OUT, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* SYSTEM -> SOC_SAFETY_ERRORn -> E20 */
    {
        PIN_SOC_SAFETY_ERRORN, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxPerCfg_t gSystem0PinCfg[] =
{
    /* SYSTEM -> RESETz -> F17 */
    {
        PIN_RESETZ, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* SYSTEM -> PORz -> E19 */
    {
        PIN_PORZ, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* SYSTEM -> RESETSTATz -> D19 */
    {
        PIN_RESETSTATZ, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* SYSTEM -> PORz_OUT -> C19 */
    {
        PIN_PORZ_OUT, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* SYSTEM -> SOC_SAFETY_ERRORn -> E20 */
    {
        PIN_SOC_SAFETY_ERRORN, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

pinmuxModuleCfg_t gSystemPinCfg[] =
{
    {0, FALSE, gSystem0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gTimer0PinCfg[] =
{
    /* TIMER -> TIMER_IO0 -> B22 */
    {
        PIN_TIMER_IO0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* TIMER -> TIMER_IO1 -> C23 */
    {
        PIN_TIMER_IO1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gTimerPinCfg[] =
{
    {0, TRUE, gTimer0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gUart0PinCfg[] =
{
    /* UART0 -> UART0_RXD -> AF11 */
    {
        PIN_UART0_RXD, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* UART0 -> UART0_TXD -> AE11 */
    {
        PIN_UART0_TXD, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* UART0 -> UART0_CTSn -> AG11 */
    {
        PIN_UART0_CTSN, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* UART0 -> UART0_RTSn -> AD11 */
    {
        PIN_UART0_RTSN, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gUartPinCfg[] =
{
    {0, TRUE, gUart0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gUsb0PinCfg[] =
{
    /* USB0 -> USB0_DRVVBUS -> AD9 */
    {
        PIN_USB0_DRVVBUS, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};
static pinmuxPerCfg_t gUsb1PinCfg[] =
{
    /* USB1 -> USB1_DRVVBUS -> AC8 */
    {
        PIN_USB1_DRVVBUS, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gUsbPinCfg[] =
{
    {0, TRUE, gUsb0PinCfg},
    {1, TRUE, gUsb1PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gVout0PinCfg[] =
{
    /* MyVOUT1 -> VOUT1_VSYNC -> T25 */
    {
        PIN_GPMC0_WPN, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_HSYNC -> T24 */
    {
        PIN_GPMC0_DIR, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_PCLK -> R24 */
    {
        PIN_GPMC0_CSN0, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DE -> T23 */
    {
        PIN_GPMC0_CSN1, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA0 -> M27 */
    {
        PIN_GPMC0_AD0, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA1 -> M23 */
    {
        PIN_GPMC0_AD1, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA2 -> M28 */
    {
        PIN_GPMC0_AD2, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA3 -> M24 */
    {
        PIN_GPMC0_AD3, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA4 -> N24 */
    {
        PIN_GPMC0_AD4, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA5 -> N27 */
    {
        PIN_GPMC0_AD5, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA6 -> N28 */
    {
        PIN_GPMC0_AD6, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA7 -> M25 */
    {
        PIN_GPMC0_AD7, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA8 -> N23 */
    {
        PIN_GPMC0_AD8, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA9 -> M26 */
    {
        PIN_GPMC0_AD9, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA10 -> P28 */
    {
        PIN_GPMC0_AD10, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA11 -> P27 */
    {
        PIN_GPMC0_AD11, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA12 -> N26 */
    {
        PIN_GPMC0_AD12, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA13 -> N25 */
    {
        PIN_GPMC0_AD13, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA14 -> P24 */
    {
        PIN_GPMC0_AD14, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA15 -> R27 */
    {
        PIN_GPMC0_AD15, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA16 -> R28 */
    {
        PIN_GPMC0_CLK, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA17 -> P25 */
    {
        PIN_GPMC0_ADVN_ALE, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA18 -> P26 */
    {
        PIN_GPMC0_OEN_REN, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA19 -> U28 */
    {
        PIN_GPMC0_WEN, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA20 -> T28 */
    {
        PIN_GPMC0_BE0N_CLE, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA21 -> P23 */
    {
        PIN_GPMC0_BE1N, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA22 -> R26 */
    {
        PIN_GPMC0_WAIT0, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* MyVOUT1 -> VOUT1_DATA23 -> R23 */
    {
        PIN_GPMC0_WAIT1, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gVoutPinCfg[] =
{
    {0, TRUE, gVout0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gWkup_debugss0PinCfg[] =
{
    /* WKUP_DEBUGSS -> TCK -> AA4 */
    {
        PIN_TCK, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_DEBUGSS -> TRSTn -> AA3 */
    {
        PIN_TRSTN, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_DEBUGSS -> EMU0 -> AA2 */
    {
        PIN_EMU0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_DEBUGSS -> EMU1 -> AA1 */
    {
        PIN_EMU1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gWkup_debugssPinCfg[] =
{
    {0, TRUE, gWkup_debugss0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gWkup_gpio0PinCfg[] =
{
    /* WKUP_GPIO0 -> WKUP_GPIO0_0 -> AF4 */
    {
        PIN_WKUP_GPIO0_0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_GPIO0 -> WKUP_GPIO0_1 -> AF3 */
    {
        PIN_WKUP_GPIO0_1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_GPIO0 -> WKUP_GPIO0_8 -> AC5 */
    {
        PIN_WKUP_GPIO0_8, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_GPIO0 -> WKUP_GPIO0_13 -> U1 */
    {
        PIN_MCU_OSPI0_LBCLKO, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_GPIO0 -> WKUP_GPIO0_24 -> R5 */
    {
        PIN_MCU_OSPI0_CSN1, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_GPIO0 -> WKUP_GPIO0_25 -> T1 */
    {
        PIN_MCU_OSPI1_CLK, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_GPIO0 -> WKUP_GPIO0_26 -> R1 */
    {
        PIN_MCU_OSPI1_LBCLKO, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_GPIO0 -> WKUP_GPIO0_27 -> P2 */
    {
        PIN_MCU_OSPI1_DQS, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_GPIO0 -> WKUP_GPIO0_28 -> P3 */
    {
        PIN_MCU_OSPI1_D0, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_GPIO0 -> WKUP_GPIO0_32 -> N2 */
    {
        PIN_MCU_OSPI1_CSN0, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_GPIO0 -> WKUP_GPIO0_50 -> Y2 */
    {
        PIN_MCU_SPI0_D1, PIN_MODE(7) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gWkup_gpioPinCfg[] =
{
    {0, TRUE, gWkup_gpio0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gWkup_i2c0PinCfg[] =
{
    /* WKUP_I2C0 -> WKUP_I2C0_SCL -> AC7 */
    {
        PIN_WKUP_I2C0_SCL, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_I2C0 -> WKUP_I2C0_SDA -> AD6 */
    {
        PIN_WKUP_I2C0_SDA, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gWkup_i2cPinCfg[] =
{
    {0, TRUE, gWkup_i2c0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gWkup_osc00PinCfg[] =
{
    {PINMUX_END}
};

static pinmuxModuleCfg_t gWkup_osc0PinCfg[] =
{
    {0, TRUE, gWkup_osc00PinCfg},
    {PINMUX_END}
};


pinmuxPerCfg_t gWkup_system0PinCfgPG1[] =
{
    /* WKUP_SYSTEM -> PMIC_POWER_EN0 -> Y5 */
    {
        PIN_PMIC_POWER_EN0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* WKUP_SYSTEM -> PMIC_POWER_EN1 -> AA5 */
    {
        PIN_PMIC_POWER_EN1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* WKUP_SYSTEM -> MCU_SAFETY_ERRORn -> W3 */
    {
        PIN_MCU_SAFETY_ERRORN, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* WKUP_SYSTEM -> MCU_RESETz -> W4 */
    {
        PIN_MCU_RESETZ, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* WKUP_SYSTEM -> MCU_RESETSTATz -> V3 */
    {
        PIN_MCU_RESETSTATZ, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* WKUP_SYSTEM -> MCU_PORz_OUT -> V2 */
    {
        PIN_MCU_PORZ_OUT, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxPerCfg_t gWkup_system0PinCfg[] =
{
    /* WKUP_SYSTEM -> PMIC_POWER_EN0 -> Y5 */
    {
        PIN_PMIC_POWER_EN0, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_SYSTEM -> PMIC_POWER_EN1 -> AA5 */
    {
        PIN_PMIC_POWER_EN1, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_SYSTEM -> MCU_SAFETY_ERRORn -> W3 */
    {
        PIN_MCU_SAFETY_ERRORN, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_SYSTEM -> MCU_RESETz -> W4 */
    {
        PIN_MCU_RESETZ, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_SYSTEM -> MCU_RESETSTATz -> V3 */
    {
        PIN_MCU_RESETSTATZ, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_SYSTEM -> MCU_PORz_OUT -> V2 */
    {
        PIN_MCU_PORZ_OUT, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    {PINMUX_END}
};

pinmuxModuleCfg_t gWkup_systemPinCfg[] =
{
    {0, FALSE, gWkup_system0PinCfg},
    {PINMUX_END}
};


static pinmuxPerCfg_t gWkup_uart0PinCfg[] =
{
    /* WKUP_UART0 -> WKUP_UART0_RXD -> AB1 */
    {
        PIN_WKUP_UART0_RXD, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_UART0 -> WKUP_UART0_TXD -> AB5 */
    {
        PIN_WKUP_UART0_TXD, PIN_MODE(0) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* WKUP_UART0 -> WKUP_UART0_CTSn -> AC2 */
    {
        PIN_WKUP_GPIO0_6, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* WKUP_UART0 -> WKUP_UART0_RTSn -> AC1 */
    {
        PIN_WKUP_GPIO0_7, PIN_MODE(1) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gWkup_uartPinCfg[] =
{
    {0, TRUE, gWkup_uart0PinCfg},
    {PINMUX_END}
};

static pinmuxPerCfg_t gpru_uart0PinCfg[] =
{
    /* RS485_UART -> RS485_UART_RX -> AF25 */
    {
        PIN_PRG1_PRU1_GPO9, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) & (~PIN_PULL_DIRECTION))
    },
    /* RS485_UART -> RS485_UART_TX -> AF24 */
    {
        PIN_PRG1_PRU1_GPO10, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    /* RS485_UART -> RS485_UART_RTSn -> AH25 */
    {
        PIN_PRG1_PRU0_GPO10, PIN_MODE(2) | \
        ((PIN_PULL_DISABLE) & (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE))
    },
    {PINMUX_END}
};

static pinmuxModuleCfg_t gpru_uartPinCfg[] =
{
    {0, TRUE, gpru_uart0PinCfg},
    {PINMUX_END}
};

pinmuxBoardCfg_t gAM65xxMainPinmuxData[] =
{
    {0, gCalPinCfg},
    {1, gDdrPinCfg},
    {2, gDebugssPinCfg},
    {3, gEcapPinCfg},
    {4, gGpioPinCfg},
    {5, gI2cPinCfg},
    {6, gMmcPinCfg},
    {7, gOldiPinCfg},
    {8, gOsc0PinCfg},
    {9, gPru_icssg0_mdioPinCfg},
    {10, gPru_icssg0_rgmiiPinCfg},
    {11, gPru_icssg1_mdioPinCfg},
    {12, gPru_icssg1_rgmiiPinCfg},
    {13, gPru_icssg2_mdioPinCfg},
    {14, gPru_icssg2_rgmiiPinCfg},
    {15, gSerdesPinCfg},
    {16, gSpiPinCfg},
    {17, gSystemPinCfg},
    {18, gTimerPinCfg},
    {19, gUartPinCfg},
    {20, gUsbPinCfg},
    {21, gVoutPinCfg},
    {22,gpru_uartPinCfg},
    {PINMUX_END}
};

pinmuxBoardCfg_t gAM65xxWkupPinmuxData[] =
{
    {0, gMcu_adcPinCfg},
    {1, gMcu_cpswPinCfg},
    {2, gMcu_fss0_ospiPinCfg},
    {3, gMcu_i2cPinCfg},
    {4, gMcu_mcanPinCfg},
    {5, gMcu_mdioPinCfg},
    {6, gMcu_spiPinCfg},
    {7, gMcu_uartPinCfg},
    {8, gWkup_debugssPinCfg},
    {9, gWkup_gpioPinCfg},
    {10, gWkup_i2cPinCfg},
    {11, gWkup_osc0PinCfg},
    {12, gWkup_systemPinCfg},
    {13, gWkup_uartPinCfg},
    {PINMUX_END}
};

