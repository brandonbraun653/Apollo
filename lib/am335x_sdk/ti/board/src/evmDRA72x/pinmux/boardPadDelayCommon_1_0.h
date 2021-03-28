/**
 * \file  boardPadDelayTable.h
 *
 * \brief   This file contain manual/virtual iodelay mode definitions
 *
 * \copyright Copyright (CU) 2018 Texas Instruments Incorporated -
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

#include <ti/board/src/evmDRA72x/pinmux/boardPadDelayTune.h>

/** {PADCONF_REG_OFFSET, PADCONF_VALUE, {CFG_X_IN offset, aDelay, gDelay}, {CFG_X_OEN offset, aDelay, gDelay}, {CFG_X_OUT offset, aDelay, gDelay}} **/
#if (USING_TI_EVM)
    /* RGMII1_TXC */
    {0x198, 0x10103,
      {0x0,   0,      0}, {0x0, 0, 0}, {0xA70, 150, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D12, 0x10103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_TXCTL */
    {0x19C, 0x10103,
      {0x0,   0,      0}, {0x0, 0, 0}, {0xA7C, 1500, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D13, 0x10103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_TXD3 */
    {0x1A0, 0x10103,
      {0x0,   0,      0}, {0x0, 0, 0}, {0xA88, 1600, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D14, 0x10103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_TXD2 */
    {0x1A4, 0x10103,
      {0x0,   0,      0}, {0x0, 0, 0}, {0xA94, 900, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D15, 0x10103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_TXD1 */
    {0x1A8, 0x10103,
      {0x0,   0,      0}, {0x0, 0, 0}, {0xAA0, 680, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D16, 0x10103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_TXD0 */
    {0x1AC, 0x10103,
      {0x0,   0,      0}, {0x0, 0, 0}, {0xAAC, 500, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D17, 0x10103, {N/A}, {N/A}, {N/A}} **/
#else
    /* RGMII1_TXC */
    {0x198, 0x10103,
      {0x0,   0,      0}, {0x0, 0, 0}, {0xA70, 1551, 115}},
    /** {CTRL_CORE_PAD_VIN2A_D12, 0x10103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_TXCTL */
    {0x19C, 0x10103,
      {0x0,   0,      0}, {0x0, 0, 0}, {0xA7C, 816, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D13, 0x10103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_TXD3 */
    {0x1A0, 0x10103,
      {0x0,   0,      0}, {0x0, 0, 0}, {0xA88, 876, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D14, 0x10103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_TXD2 */
    {0x1A4, 0x10103,
      {0x0,   0,      0}, {0x0, 0, 0}, {0xA94, 312, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D15, 0x10103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_TXD1 */
    {0x1A8, 0x10103,
      {0x0,   0,      0}, {0x0, 0, 0}, {0xAA0, 58, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D16, 0x10103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_TXD0 */
    {0x1AC, 0x10103,
      {0x0,   0,      0}, {0x0, 0, 0}, {0xAAC, 0, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D17, 0x10103, {N/A}, {N/A}, {N/A}} **/
#endif
    /* RGMII1_RXC */
    {0x1B0, 0x50103,
      {0xAB0,   136,      976}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D18, 0x50103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_RXCTL */
    {0x1B4, 0x50103,
      {0xABC,   210,      1357}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D19, 0x50103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_RXD3 */
    {0x1B8, 0x50103,
      {0xAD4,   189,      1462}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D20, 0x50103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_RXD2 */
    {0x1BC, 0x50103,
      {0xAE0,   232,      1278}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D21, 0x50103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_RXD1 */
    {0x1C0, 0x50103,
      {0xAEC,   0,      1397}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D22, 0x50103, {N/A}, {N/A}, {N/A}} **/
    /* RGMII1_RXD0 */
    {0x1C4, 0x50103,
      {0xAF8,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_VIN2A_D23, 0x50103, {N/A}, {N/A}, {N/A}} **/
    {0x23C, 0xE0000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MDIO_MCLK, 0xE0000, {N/A}, {N/A}, {N/A}} **/
    {0x240, 0xE0000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MDIO_D, 0xE0000, {N/A}, {N/A}, {N/A}} **/
#if (USING_TI_EVM)
    {0x250, 0x10100,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x740, 0, 220}},
    /** {CTRL_CORE_PAD_RGMII0_TXC, 0x10100, {N/A}, {N/A}, {N/A}} **/
    {0x254, 0x10100,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x74C, 1820, 180}},
    /** {CTRL_CORE_PAD_RGMII0_TXCTL, 0x10100, {N/A}, {N/A}, {N/A}} **/
    {0x258, 0x10100,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x77C, 1740, 440}},
    /** {CTRL_CORE_PAD_RGMII0_TXD3, 0x10100, {N/A}, {N/A}, {N/A}} **/
    {0x25C, 0x10100,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x770, 1680, 380}},
    /** {CTRL_CORE_PAD_RGMII0_TXD2, 0x10100, {N/A}, {N/A}, {N/A}} **/
    {0x260, 0x10100,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x764, 1740, 240}},
    /** {CTRL_CORE_PAD_RGMII0_TXD1, 0x10100, {N/A}, {N/A}, {N/A}} **/
    {0x264, 0x10100,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x758, 1740, 440}},
    /** {CTRL_CORE_PAD_RGMII0_TXD0, 0x10100, {N/A}, {N/A}, {N/A}} **/
#else
    {0x250, 0x10100,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x740, 300, 200}},
    /** {CTRL_CORE_PAD_RGMII0_TXC, 0x10100, {N/A}, {N/A}, {N/A}} **/
    {0x254, 0x10100,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x74C, 200, 0}},
    /** {CTRL_CORE_PAD_RGMII0_TXCTL, 0x10100, {N/A}, {N/A}, {N/A}} **/
    {0x258, 0x10100,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x77C, 250, 60}},
    /** {CTRL_CORE_PAD_RGMII0_TXD3, 0x10100, {N/A}, {N/A}, {N/A}} **/
    {0x25C, 0x10100,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x770, 0, 0}},
    /** {CTRL_CORE_PAD_RGMII0_TXD2, 0x10100, {N/A}, {N/A}, {N/A}} **/
    {0x260, 0x10100,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x764, 150, 0}},
    /** {CTRL_CORE_PAD_RGMII0_TXD1, 0x10100, {N/A}, {N/A}, {N/A}} **/
    {0x264, 0x10100,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x758, 250, 60}},
    /** {CTRL_CORE_PAD_RGMII0_TXD0, 0x10100, {N/A}, {N/A}, {N/A}} **/
#endif
    {0x268, 0x50100,
      {0x6F0,   359,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_RGMII0_RXC, 0x50100, {N/A}, {N/A}, {N/A}} **/
    {0x26C, 0x50100,
      {0x6FC,   129,      1896}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_RGMII0_RXCTL, 0x50100, {N/A}, {N/A}, {N/A}} **/
    {0x270, 0x50100,
      {0x72C,   0,      1956}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_RGMII0_RXD3, 0x50100, {N/A}, {N/A}, {N/A}} **/
    {0x274, 0x50100,
      {0x720, 40,      1860}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_RGMII0_RXD2, 0x50100, {N/A}, {N/A}, {N/A}} **/
    {0x278, 0x50100,
      {0x714,   196,      1522}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_RGMII0_RXD1, 0x50100, {N/A}, {N/A}, {N/A}} **/
    {0x27C, 0x50100,
      {0x708,   80,      1391}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_RGMII0_RXD0, 0x50100, {N/A}, {N/A}, {N/A}} **/
    {0x280, 0x90000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_USB1_DRVVBUS, 0x90000, {N/A}, {N/A}, {N/A}} **/
    {0x284, 0x90000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_USB2_DRVVBUS, 0x90000, {N/A}, {N/A}, {N/A}} **/
    /* McASP3_AHCLKX */
    {0x29C, 0x40003,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_XREF_CLK2, 0x40003, {N/A}, {N/A}, {N/A}} **/
    /* I2C5_SDA */
    {0x2B4, 0x6000A,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MCASP1_AXR0, 0x6000A, {N/A}, {N/A}, {N/A}} **/
    /* I2C5_SCL */
    {0x2B8, 0x6000A,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MCASP1_AXR1, 0x6000A, {N/A}, {N/A}, {N/A}} **/
    {0x324, 0x40000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MCASP3_ACLKX, 0x40000, {N/A}, {N/A}, {N/A}} **/
    {0x328, 0xC0000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MCASP3_FSX, 0xC0000, {N/A}, {N/A}, {N/A}} **/
    {0x32C, 0xC0000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MCASP3_AXR0, 0xC0000, {N/A}, {N/A}, {N/A}} **/
    {0x330, 0xC0000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MCASP3_AXR1, 0xC0000, {N/A}, {N/A}, {N/A}} **/
    {0x354, 0x40000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MMC1_CLK, 0x40000, {N/A}, {N/A}, {N/A}} **/
    {0x358, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MMC1_CMD, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x35C, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MMC1_DAT0, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x360, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MMC1_DAT1, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x364, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MMC1_DAT2, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x368, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_MMC1_DAT3, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x3A4, 0xC0000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_SPI1_SCLK, 0xC0000, {N/A}, {N/A}, {N/A}} **/
    {0x3A8, 0xC0000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_SPI1_D1, 0xC0000, {N/A}, {N/A}, {N/A}} **/
    {0x3AC, 0xC0000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_SPI1_D0, 0xC0000, {N/A}, {N/A}, {N/A}} **/
    {0x3B0, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_SPI1_CS0, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x3E0, 0x40000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_UART1_RXD, 0x40000, {N/A}, {N/A}, {N/A}} **/
    {0x3E4, 0x80000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_UART1_TXD, 0x80000, {N/A}, {N/A}, {N/A}} **/
    {0x3E8, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_UART1_CTSN, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x3EC, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_UART1_RTSN, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x400, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_I2C1_SDA, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x404, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_I2C1_SCL, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x408, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_I2C2_SDA, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x40C, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_I2C2_SCL, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x430, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_TMS, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x434, 0xE0000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_TDI, 0xE0000, {N/A}, {N/A}, {N/A}} **/
    {0x438, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_TDO, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x43C, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_TCLK, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x440, 0x40000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_TRSTN, 0x40000, {N/A}, {N/A}, {N/A}} **/
    {0x444, 0x50000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_RTCK, 0x50000, {N/A}, {N/A}, {N/A}} **/
    {0x448, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_EMU0, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x44C, 0x60000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_EMU1, 0x60000, {N/A}, {N/A}, {N/A}} **/
    {0x45C, 0x20000,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_RESETN, 0x20000, {N/A}, {N/A}, {N/A}} **/
    {0x460, 0x0,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_NMIN_DSP, 0x0, {N/A}, {N/A}, {N/A}} **/
    {0x464, 0x0,
      {0x0,   0,      0}, {0x0, 0, 0}, {0x0, 0, 0}},
    /** {CTRL_CORE_PAD_RSTOUTN, 0x0, {N/A}, {N/A}, {N/A}} **/
