/**
 * \file   am335x_pinmux.h
 *
 * \brief  This file contains pad configure register offsets and bit-field
 *         value macros for different configurations,
 *
 *           6    SLEWCTRL       Select between faster or slower slew rate
 *           5    RXACTIVE       Input enable value for the Pad
 *           4    PULLTYPESEL    Pad pullup/pulldown type selection
 *           3    PULLUDEN       Pad Pullup/pulldown enable
 *           2-0  MUXMODE        Pad functional signal mux select
 *
 *  \copyright Copyright (CU) 2015-2017 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

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
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDINGU, BUT NOT
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

#ifndef AM335X_PIN_MUX_H_
#define AM335X_PIN_MUX_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "pinmux.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* macro used to define the MUXMODE for pad control registers. */
#define PIN_MODE(mode)               (mode)

/* Active mode configurations. */
/* Pull up/down enable. */
#define PIN_PULL_UD_EN               (0x1U << 3U)
/* Pull up/down type select. */
#define PIN_PULL_TYPE_SEL            (0x1U << 4U)
/* Receiver enable. */
#define PIN_RX_ACTIVE                (0x1U << 5U)
/** \brief Slew rate */
#define PIN_SLEW_SLOW                 (0x1U << 6U)

#define PINMUX_REG_MASK              (0x007FU)

/** Pad config register offset in control module */
enum pinOffsets
{
    PIN_GPMC_AD0          = 0x0800U,
    PIN_OFFSET_MIN        = PIN_GPMC_AD0,
    PIN_GPMC_AD1          = 0x0804U,
    PIN_GPMC_AD2          = 0x0808U,
    PIN_GPMC_AD3          = 0x080cU,
    PIN_GPMC_AD4          = 0x0810U,
    PIN_GPMC_AD5          = 0x0814U,
    PIN_GPMC_AD6          = 0x0818U,
    PIN_GPMC_AD7          = 0x081cU,
    PIN_GPMC_AD8          = 0x0820U,
    PIN_GPMC_AD9          = 0x0824U,
    PIN_GPMC_AD10         = 0x0828U,
    PIN_GPMC_AD11         = 0x082cU,
    PIN_GPMC_AD12         = 0x0830U,
    PIN_GPMC_AD13         = 0x0834U,
    PIN_GPMC_AD14         = 0x0838U,
    PIN_GPMC_AD15         = 0x083cU,
    PIN_GPMC_A0           = 0x0840U,
    PIN_GPMC_A1           = 0x0844U,
    PIN_GPMC_A2           = 0x0848U,
    PIN_GPMC_A3           = 0x084cU,
    PIN_GPMC_A4           = 0x0850U,
    PIN_GPMC_A5           = 0x0854U,
    PIN_GPMC_A6           = 0x0858U,
    PIN_GPMC_A7           = 0x085cU,
    PIN_GPMC_A8           = 0x0860U,
    PIN_GPMC_A9           = 0x0864U,
    PIN_GPMC_A10          = 0x0868U,
    PIN_GPMC_A11          = 0x086cU,
    PIN_GPMC_WAIT0        = 0x0870U,
    PIN_GPMC_WPN          = 0x0874U,
    PIN_GPMC_BE1N         = 0x0878U,
    PIN_GPMC_CSN0         = 0x087cU,
    PIN_GPMC_CSN1         = 0x0880U,
    PIN_GPMC_CSN2         = 0x0884U,
    PIN_GPMC_CSN3         = 0x0888U,
    PIN_GPMC_CLK          = 0x088cU,
    PIN_GPMC_ADVN_ALE     = 0x0890U,
    PIN_GPMC_OEN_REN      = 0x0894U,
    PIN_GPMC_WEN          = 0x0898U,
    PIN_GPMC_BE0N_CLE     = 0x089cU,
    PIN_LCD_DATA0         = 0x08a0U,
    PIN_LCD_DATA1         = 0x08a4U,
    PIN_LCD_DATA2         = 0x08a8U,
    PIN_LCD_DATA3         = 0x08acU,
    PIN_LCD_DATA4         = 0x08b0U,
    PIN_LCD_DATA5         = 0x08b4U,
    PIN_LCD_DATA6         = 0x08b8U,
    PIN_LCD_DATA7         = 0x08bcU,
    PIN_LCD_DATA8         = 0x08c0U,
    PIN_LCD_DATA9         = 0x08c4U,
    PIN_LCD_DATA10        = 0x08c8U,
    PIN_LCD_DATA11        = 0x08ccU,
    PIN_LCD_DATA12        = 0x08d0U,
    PIN_LCD_DATA13        = 0x08d4U,
    PIN_LCD_DATA14        = 0x08d8U,
    PIN_LCD_DATA15        = 0x08dcU,
    PIN_LCD_VSYNC         = 0x08e0U,
    PIN_LCD_HSYNC         = 0x08e4U,
    PIN_LCD_PCLK          = 0x08e8U,
    PIN_LCD_AC_BIAS_EN    = 0x08ecU,
    PIN_MMC0_DAT3         = 0x08f0U,
    PIN_MMC0_DAT2         = 0x08f4U,
    PIN_MMC0_DAT1         = 0x08f8U,
    PIN_MMC0_DAT0         = 0x08fcU,
    PIN_MMC0_CLK          = 0x0900U,
    PIN_MMC0_CMD          = 0x0904U,
	PIN_GMII1_COL         = 0x0908U,
	PIN_GMII1_CRS         = 0x090cU,
	PIN_GMII1_RXER        = 0x0910U,
	PIN_GMII1_TXEN        = 0x0914U,
	PIN_GMII1_RXDV        = 0x0918U,
	PIN_GMII1_TXD3        = 0x091cU,
	PIN_GMII1_TXD2        = 0x0920U,
	PIN_GMII1_TXD1        = 0x0924U,
	PIN_GMII1_TXD0        = 0x0928U,
	PIN_GMII1_TXCLK       = 0x092cU,
	PIN_GMII1_RXCLK       = 0x0930U,
	PIN_GMII1_RXD3        = 0x0934U,
	PIN_GMII1_RXD2        = 0x0938U,
	PIN_GMII1_RXD1        = 0x093cU,
	PIN_GMII1_RXD0        = 0x0940U,
    PIN_RMII1_REFCLK      = 0x0944U,
    PIN_MDIO_DATA         = 0x0948U,
    PIN_MDIO_CLK          = 0x094cU,
    PIN_SPI0_SCLK         = 0x0950U,
    PIN_SPI0_D0           = 0x0954U,
    PIN_SPI0_D1           = 0x0958U,
    PIN_SPI0_CS0          = 0x095cU,
    PIN_SPI0_CS1          = 0x0960U,
    PIN_ECAP0_IN_PWM0_OUT = 0x0964U,
    PIN_UART0_CTSN        = 0x0968U,
    PIN_UART0_RTSN        = 0x096cU,
    PIN_UART0_RXD         = 0x0970U,
    PIN_UART0_TXD         = 0x0974U,
    PIN_UART1_CTSN        = 0x0978U,
    PIN_UART1_RTSN        = 0x097cU,
    PIN_UART1_RXD         = 0x0980U,
    PIN_UART1_TXD         = 0x0984U,
    PIN_I2C0_SDA          = 0x0988U,
    PIN_I2C0_SCL          = 0x098cU,
    PIN_MCASP0_ACLKX      = 0x0990U,
    PIN_MCASP0_FSX        = 0x0994U,
    PIN_MCASP0_AXR0       = 0x0998U,
    PIN_MCASP0_AHCLKR     = 0x099cU,
    PIN_MCASP0_ACLKR      = 0x09a0U,
    PIN_MCASP0_FSR        = 0x09a4U,
    PIN_MCASP0_AXR1       = 0x09a8U,
    PIN_MCASP0_AHCLKX     = 0x09acU,
    PIN_XDMA_EVENT_INTR0  = 0x09b0U,
    PIN_XDMA_EVENT_INTR1  = 0x09b4U,
    PIN_NRESETIN_OUT      = 0x09b8U,
    PIN_PORZ              = 0x09bcU,
    PIN_NNMI              = 0x09c0U,
    PIN_OSC0_IN           = 0x09c4U,
    PIN_OSC0_OUT          = 0x09c8U,
    PIN_TMS               = 0x09d0U,
    PIN_TDI               = 0x09d4U,
    PIN_TDO               = 0x09d8U,
    PIN_TCK               = 0x09dcU,
    PIN_NTRST             = 0x09e0U,
    PIN_EMU0              = 0x09e4U,
    PIN_EMU1              = 0x09e8U,
    PIN_OSC1_IN           = 0x09ecU,
    PIN_OSC1_OUT          = 0x09f0U,
	PIN_RTC_PORZ          = 0x09f8U,
	PIN_PMIC_POWER_EN     = 0x09fcU,
	PIN_EXT_WAKEUP        = 0x0a00U,
    PIN_ENZ_KALDO_1P8V    = 0x0a04U,
    PIN_USB0_DM           = 0x0a08U,
    PIN_USB0_DP           = 0x0a0cU,
    PIN_USB0_CE           = 0x0a10U,
    PIN_USB0_ID           = 0x0a14U,
    PIN_USB0_VBUS         = 0x0a18U,
    PIN_USB0_DRVVBUS      = 0x0a1cU,
    PIN_USB1_DM           = 0x0a20U,
    PIN_USB1_DP           = 0x0a24U,
    PIN_USB1_CE           = 0x0a28U,
    PIN_USB1_ID           = 0x0a2cU,
    PIN_USB1_VBUS         = 0x0a30U,
    PIN_USB1_DRVVBUS      = 0x0a34U,
    PIN_DDR_RESETN        = 0x0a38U,
    PIN_DDR_CSN0          = 0x0a3cU,
    PIN_DDR_CKE           = 0x0a40U,
    PIN_DDR_CK            = 0x0a44U,
    PIN_DDR_NCK           = 0x0a48U,
    PIN_DDR_CASN          = 0x0a4cU,
    PIN_DDR_RASN          = 0x0a50U,
    PIN_DDR_WEN           = 0x0a54U,
    PIN_DDR_BA0           = 0x0a58U,
    PIN_DDR_BA1           = 0x0a5cU,
    PIN_DDR_BA2           = 0x0a60U,
    PIN_DDR_A0            = 0x0a64U,
    PIN_DDR_A1            = 0x0a68U,
    PIN_DDR_A2            = 0x0a6cU,
    PIN_DDR_A3            = 0x0a70U,
    PIN_DDR_A4            = 0x0a74U,
    PIN_DDR_A5            = 0x0a78U,
    PIN_DDR_A6            = 0x0a7cU,
    PIN_DDR_A7            = 0x0a80U,
    PIN_DDR_A8            = 0x0a84U,
    PIN_DDR_A9            = 0x0a88U,
    PIN_DDR_A10           = 0x0a8cU,
    PIN_DDR_A11           = 0x0a90U,
    PIN_DDR_A12           = 0x0a94U,
    PIN_DDR_A13           = 0x0a98U,
    PIN_DDR_A14           = 0x0a9cU,
    PIN_DDR_A15           = 0x0aa0U,
    PIN_DDR_ODT           = 0x0aa4U,
    PIN_DDR_D0            = 0x0aa8U,
    PIN_DDR_D1            = 0x0aacU,
    PIN_DDR_D2            = 0x0ab0U,
    PIN_DDR_D3            = 0x0ab4U,
    PIN_DDR_D4            = 0x0ab8U,
    PIN_DDR_D5            = 0x0abcU,
    PIN_DDR_D6            = 0x0ac0U,
    PIN_DDR_D7            = 0x0ac4U,
    PIN_DDR_D8            = 0x0ac8U,
    PIN_DDR_D9            = 0x0accU,
    PIN_DDR_D10           = 0x0ad0U,
    PIN_DDR_D11           = 0x0ad4U,
    PIN_DDR_D12           = 0x0ad8U,
    PIN_DDR_D13           = 0x0adcU,
    PIN_DDR_D14           = 0x0ae0U,
    PIN_DDR_D15           = 0x0ae4U,
    PIN_DDR_DQM0          = 0x0ae8U,
    PIN_DDR_DQM1          = 0x0aecU,
    PIN_DDR_DQS0          = 0x0af0U,
    PIN_DDR_DQSN0         = 0x0af4U,
    PIN_DDR_DQS1          = 0x0af8U,
    PIN_DDR_DQSN1         = 0x0afcU,
    PIN_DDR_VREF          = 0x0b00U,
    PIN_DDR_VTP           = 0x0b04U,
    PIN_DDR_STRBEN0       = 0x0b08U,
    PIN_DDR_STRBEN1       = 0x0b0cU,
    PIN_AIN7              = 0x0b10U,
    PIN_AIN6              = 0x0b14U,
    PIN_AIN5              = 0x0b18U,
    PIN_AIN4              = 0x0b1cU,
    PIN_AIN3              = 0x0b20U,
    PIN_AIN2              = 0x0b24U,
    PIN_AIN1              = 0x0b28U,
    PIN_AIN0              = 0x0b2cU,
    PIN_VREFP             = 0x0b30U,
    PIN_VREFN             = 0x0b34U,
    PIN_IFORCE            = 0x0b40U,
    PIN_VSENSE            = 0x0b44U,
    PIN_TESTOUT           = 0x0b48U,
    PIN_OFFSET_MAX        = PIN_TESTOUT
};


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Pinmux configuration data for the board. Auto-generated from
           Pinmux tool. */
extern pinmuxBoardCfg_t gGpevmPinmuxData[];

/** \brief Pinmux configuration data for the board. Auto-generated from
           Pinmux tool. */
extern pinmuxBoardCfg_t gEvmskPinmuxData[];

/** \brief Pinmux configuration data for the board. Auto-generated from
           Pinmux tool. */
extern pinmuxBoardCfg_t gBbPinmuxData[];

/** \brief Pinmux configuration data for the board. Auto-generated from
           Pinmux tool. */
extern pinmuxBoardCfg_t gBbbPinmuxData[];

/** \brief Pinmux configuration data for the board. Auto-generated from
           Pinmux tool. */
extern pinmuxBoardCfg_t gIceV1PinmuxData[];

/** \brief Pinmux configuration data for the board. Auto-generated from
           Pinmux tool. */
extern pinmuxBoardCfg_t gIceV2PinmuxData[];

/** \brief Pinmux configuration data for the board. Auto-generated from
           Pinmux tool for IceV2, but with AMIC11x naming. Intended for
           manual deviation from IceV2, if applicable. */
extern pinmuxBoardCfg_t gAMIC11xPinmuxData[];

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* AM335X_PIN_MUX_H_ */
