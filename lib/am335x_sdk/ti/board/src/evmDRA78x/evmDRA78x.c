/******************************************************************************
 * Copyright (c) 2017 - 2018 Texas Instruments Incorporated - http://www.ti.com
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

/**
 *  \file evmDRA78x.c
 *
 *  \brief EVM board file for DRA78x boards.
 *
 *  This board library serves mainly to enable the various PDK example and test
 *  applications from CCS, which are loaded via CCS debugging session and assume
 *  certain initializations being performed by the GEL script.  When integrating
 *  applications to be loaded via the SBL, and/or in a production system, this
 *  library should be mostly obsoleted as the configurations present here are to
 *  be taken care of through the SBL code.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* CSL Chip Functional Layer Header Files */
#include <ti/csl/soc.h>

/* For MMCSD definition */
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>

/* UART Driver Header Files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

/* I2C Driver Header Files */
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include "board.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief      Configure pinmux for modules used in the examples.
 *
 *  When integrating with SBL, this function should be still be used for pad
 *  configuration as required by the application.  SBL will only perform pad
 *  configuration for the selected boot media and RGMII, since there is no
 *  requirement to configure pad delay or perform the configuration in
 *  isolation like with other DRA7xx devices.
 */
Board_STATUS Board_pinmuxConfig(void);

/**
 *  \brief      Enable additional modules used by the examples.
 *
 *  When integrating with SBL, this function should be obsoleted and instead
 *  the appropriate entries should be added to gModuleEnableTable in
 *  <PDK>/ti/boot/sbl_auto/sbl_utils/src/tda3xx/sbl_utils_tda3xx.c.
 */
Board_STATUS Board_moduleEnable(void);

/**
 *  \brief      Configure Gigabit Ethernet interface.
 */
Board_STATUS Board_gmiiConfig(void);

/**
 *  \brief      Configure EVM I/O expanders.
 *
 *  Note that this is EVM-specific and ideally is not required for a production
 *  design that doesn't multiplex board signals.
 */
Board_STATUS Board_ioexpConfig(Board_initCfg cfg);

static Board_STATUS readTca6424OutputPort(I2C_Handle i2cHandle,
                                          uint32_t   i2cDevAddr,
                                          uint8_t   *regValue,
                                          uint32_t   numRegs);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void ModuleMcaspEnable(uint32_t instNum)
{
    switch(instNum)
    {
        case 1:
        {
            /* McASP1 Module Control */
            HW_WR_FIELD32(SOC_IPU_CM_CORE_AON_BASE + CM_IPU_MCASP1_CLKCTRL, \
                          CM_IPU_MCASP1_CLKCTRL_CLKSEL_AHCLKX, \
                          CM_IPU_MCASP1_CLKCTRL_CLKSEL_AHCLKX_SEL_XREF_CLK0);
            HW_WR_FIELD32(SOC_IPU_CM_CORE_AON_BASE + CM_IPU_MCASP1_CLKCTRL, \
                          CM_IPU_MCASP1_CLKCTRL_CLKSEL_AHCLKR, \
                          CM_IPU_MCASP1_CLKCTRL_CLKSEL_AHCLKR_SEL_XREF_CLK0);
            HW_WR_FIELD32(SOC_IPU_CM_CORE_AON_BASE + CM_IPU_MCASP1_CLKCTRL, \
                          CM_IPU_MCASP1_CLKCTRL_MODULEMODE, \
                          CM_IPU_MCASP1_CLKCTRL_MODULEMODE_ENABLE);

            while ((HW_RD_REG32(SOC_IPU_CM_CORE_AON_BASE + CM_IPU_MCASP1_CLKCTRL) &
                    CM_IPU_MCASP1_CLKCTRL_MODULEMODE_ENABLE) != \
                   CM_IPU_MCASP1_CLKCTRL_MODULEMODE_ENABLE);
            break;
        }
    }
}

void ModuleMcspiEnable(uint32_t instNum)
{
    switch(instNum)
    {
        case 1:
        {
            /* McSPI1 Module Control */
            HW_WR_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MCSPI1_CLKCTRL, 0x02);
            while ((HW_RD_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MCSPI1_CLKCTRL) &
                    CM_L4PER_MCSPI1_CLKCTRL_MODULEMODE_ENABLE) != \
                   CM_L4PER_MCSPI1_CLKCTRL_MODULEMODE_ENABLE);
            break;
        }
    }
}

void ModuleMmcsdEnable(void)
{
    uint32_t tmpRegVal;

    /* Power on */
    tmpRegVal  = HW_RD_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MMC4_CLKCTRL);
    tmpRegVal |= 0x02000000;
    HW_WR_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MMC4_CLKCTRL, tmpRegVal);

    /*MMC PRCM config*/
    HW_WR_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_MMC4_CLKCTRL, CM_L4PER_MMC4_CLKCTRL_MODULEMODE_ENABLE);
}

void PinmuxGpioConfig (uint32_t instNum)
{
    switch(instNum)
    {
        case 3:
        {
            /* Set XREF_CLK0 to select GPIO Bank 3, pin 31 for MMCSD detection */
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_XREF_CLK0, 0x0004000E);
            break;
        }
    }
}

void PinmuxMmcsdConfig (void)
{
    /* MMCSD Pad configurations */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_RXC,   0x00050005);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_RXCTL, 0x00070005);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_RXD3,  0x00070005);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_RXD2,  0x00070005);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_RXD1,  0x00070005);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_RXD0,  0x00070005);
}

void PinmuxMcspiConfig (uint32_t instNum)
{
    switch(instNum)
    {
        case 1:
        {
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_SPI1_CS0,  0x00040000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_SPI1_SCLK, 0x00040000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_SPI1_D0,   0x00040000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_SPI1_D1,   0x00040000);

            break;
        }
    }
}

void PinmuxMcaspConfig (uint32_t instNum)
{
    switch(instNum)
    {
        case 1:
        {
            /* PAD IO Config for McASP1 pins */

            /* XREF_CLK0 */
            HW_WR_FIELD32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_XREF_CLK0, \
                          CTRL_CORE_PAD_IO_XREF_CLK0_MUXMODE, \
                          0x0);

            /* ACLKX */
            HW_WR_FIELD32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_VOUT1_DE, \
                          CTRL_CORE_PAD_IO_VOUT1_DE_MUXMODE, \
                          0x1);

            /* AFSX */
            HW_WR_FIELD32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_VOUT1_FLD, \
                          CTRL_CORE_PAD_IO_VOUT1_FLD_MUXMODE, \
                          0x1);

            /* ACLKR */
            HW_WR_FIELD32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_VOUT1_HSYNC, \
                          CTRL_CORE_PAD_IO_VOUT1_HSYNC_MUXMODE, \
                          0x1);

            /* AFSR */
            HW_WR_FIELD32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_VOUT1_VSYNC, \
                          CTRL_CORE_PAD_IO_VOUT1_VSYNC_MUXMODE, \
                          0x1);

            /* AXR0 */
            HW_WR_FIELD32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_VOUT1_D0, \
                          CTRL_CORE_PAD_IO_VOUT1_D0_MUXMODE, \
                          0x1);

            /* AXR1 */
            HW_WR_FIELD32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_VOUT1_D1, \
                          CTRL_CORE_PAD_IO_VOUT1_D1_MUXMODE, \
                          0x1);

            /* AXR2 */
            HW_WR_FIELD32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_VOUT1_D2, \
                          CTRL_CORE_PAD_IO_VOUT1_D2_MUXMODE, \
                          0x1);

            /* AXR3 */
            HW_WR_FIELD32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_VOUT1_D3, \
                          CTRL_CORE_PAD_IO_VOUT1_D3_MUXMODE, \
                          0x1);

            /* AXR4 */
            HW_WR_FIELD32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_VOUT1_D4, \
                          CTRL_CORE_PAD_IO_VOUT1_D4_MUXMODE, \
                          0x1);

            /* AXR5 */
            HW_WR_FIELD32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_VOUT1_D5, \
                          CTRL_CORE_PAD_IO_VOUT1_D5_MUXMODE, \
                          0x1);
            break;
        }
    }
}

void PinmuxRgmiiConfig (uint32_t instNum)
{
    switch(instNum)
    {
        case 1:
        {
            /* RGMII0 Pad configurations */
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_TXC,   0x00000000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_TXCTL, 0x00000000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_TXD3,  0x00000000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_TXD2,  0x00000000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_TXD1,  0x00000000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_TXD0,  0x00000000);

            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_RXC,   0x00040000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_RXCTL, 0x00040000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_RXD3,  0x00040000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_RXD2,  0x00040000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_RXD1,  0x00040000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_RGMII0_RXD0,  0x00040000);

            break;
        }
    }
}

void PinmuxQspiConfig (void)
{
    /* QSPI Pad configurations */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_GPMC_CS6,   0x60001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_UART1_RTSN, 0x60008);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_GPMC_CS1,   0x60001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_GPMC_CS5,   0x60001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_GPMC_CS4,   0x60001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_GPMC_CS3,   0x60001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_GPMC_CS2,   0x60001);
}

void PinmuxUartConfig (uint32_t instNum)
{
    switch(instNum)
    {
        case 1:
        {
            /* UART Pad configurations */
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_UART1_RXD, 0x00040000);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_UART1_TXD, 0x00000000);
            break;
        }
        case 3:
        {
            /* UART Pad configurations */
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_SPI1_SCLK, 0x00040001);
            HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_IO_SPI1_CS0, 0x00000001);
            break;
        }
    }
}

Board_STATUS Board_init(Board_initCfg cfg)
{
    Board_STATUS status;

    if (cfg & BOARD_INIT_MODULE_CLOCK)
    {
        status = Board_moduleEnable();
        if (status != BOARD_SOK)
            return status;
    }

    if (cfg & BOARD_INIT_ETH_PHY)
    {
        status = Board_gmiiConfig();
        if (status != BOARD_SOK)
            return status;
    }

    if (cfg & BOARD_INIT_UART_STDIO)
    {
        UART_stdioInit(BOARD_UART_INSTANCE);
    }

    /* Do interrupt xbar mapping for GMAC and UART */
#if defined(__TI_ARM_V7M4__)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_44, CSL_XBAR_UART1_IRQ);
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_60, CSL_XBAR_GMAC_SW_IRQ_RX_PULSE);
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_61, CSL_XBAR_GMAC_SW_IRQ_TX_PULSE);
#elif defined(_TMS320C6X)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_DSP1, CSL_XBAR_INST_DSP1_IRQ_44, CSL_XBAR_UART1_IRQ);
#endif

    if (cfg & BOARD_INIT_PINMUX_CONFIG)
    {
        status = Board_pinmuxConfig();
        if (status != BOARD_SOK)
            return status;
    }

    /* Do I/O expander config after UART init and Pinmux config.  There is no
     * flag in the Board_initCfg which enables the application to do this, so
     * we tack on at the end of all other initailizations.  Note that this is
     * only required if running the application on the TI EVM and should not be
     * needed on a custom hardware design.  Also note that if the application
     * does not perform pinmux initialization, then we assume this was already
     * done in the SBL.  Otherwise, this could potentially fail.  Please
     * carefully review the setup done in SBL or application if experiencing
     * unexpected failures.
     */
    status = Board_ioexpConfig(cfg);
    if (status != BOARD_SOK)
        return status;

    return BOARD_SOK;
}

Board_STATUS Board_pinmuxConfig(void)
{
    PinmuxGpioConfig(3U);
    PinmuxMcaspConfig(1U);
    PinmuxMcspiConfig(1U);
    PinmuxQspiConfig();
    PinmuxRgmiiConfig(1U);
    PinmuxUartConfig(1U);

    return BOARD_SOK;
}

Board_STATUS Board_ioexpConfig(Board_initCfg cfg)
{
    Board_STATUS    retVal = BOARD_SOK;
    I2C_Params      i2cParams;
    I2C_Handle      handle;
    I2C_HwAttrs     i2cCfg;
    I2C_Transaction i2cTransaction;
    uint32_t        i2cIoctlCmd;
    int16_t         ret;
    uint8_t         buf[4] = {0};
    bool            enableIntrTmp;

    I2C_init();

    I2C_Params_init(&i2cParams);
    i2cParams.transferMode = I2C_MODE_BLOCKING;

    I2C_socGetInitCfg(0, &i2cCfg);
    enableIntrTmp = i2cCfg.enableIntr;
    i2cCfg.enableIntr = false;
    I2C_socSetInitCfg(0, &i2cCfg);

    /* Open I2C1 instance */
    handle = I2C_open(0, &i2cParams);
    if (handle == NULL)
    {
        UART_printf("Board_ioexpConfig: failed to open I2C1\n");
        return BOARD_I2C_OPEN_FAIL;
    }

    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.timeout = 4000U;

    /* Configure TCA6424 I/O expander (instance #2) */
    i2cTransaction.slaveAddress = BOARD_IO_EXP_TCA6424_2_I2C_ADDR;

    /* Read current configuration */
    retVal = readTca6424OutputPort(handle,
                                   BOARD_IO_EXP_TCA6424_2_I2C_ADDR,
                                   &buf[1],
                                   3);
    if (retVal != BOARD_SOK)
    {
        goto close;
    }

    /* Write to output port 0-2:
     * Select UART1 board mux:
     *  - P00 (Port 0, bit 0) set high
     *  - P11 (Port 1, bit 1) set high
     *  - P12 (Port 1, bit 2) set low
     * If BOARD_INIT_ETH_PHY reqired:
     *   Select EMAC0PHY board mux:
     *     - P06 (Port 0, bit 6) set high
     *     - P17 (Port 1, bit 7) set low
     * Else:
     *   Select MMC1 board mux:
     *     - P06 (Port 0, bit 6) set low
     *     - P17 (Port 1, bit 7) set high
     */
    i2cTransaction.writeBuf = buf;
    i2cTransaction.writeCount = 4U;
    i2cTransaction.readBuf = NULL;
    i2cTransaction.readCount = 0;

    /* Write to output port 0 in incrementing mode */
    buf[0] =  0x84U;

    /* Select UART1 */
    buf[1] |= 0x01U;
    buf[2] |= 0x02U;
    buf[2] &= ~(0x04U);

    if (cfg & BOARD_INIT_ETH_PHY)
    {
        buf[1] |= 0x40U;
        buf[1] &= ~(0x80U);
    }
    else
    {
        buf[1] &= ~(0x40U);
        buf[1] |= 0x80U;
    }

    ret = I2C_transfer(handle, &i2cTransaction);
    if (ret != I2C_STS_SUCCESS)
    {
        retVal = BOARD_I2C_TRANSFER_FAIL;
        goto close;
    }

    /* Write to config port: all pins as output */
    buf[0] = 0x8CU;
    buf[1] = 0x00U;
    buf[2] = 0x00U;
    buf[3] = 0x00U;

    ret = I2C_transfer(handle, &i2cTransaction);
    if (ret != I2C_STS_SUCCESS)
    {
        retVal = BOARD_I2C_TRANSFER_FAIL;
        goto close;
    }

    /* Configure TCA6424 I/O expander (instance #1) */
    i2cTransaction.slaveAddress = BOARD_IO_EXP_TCA6424_1_I2C_ADDR;

    /* Configure every pin as output except SD detect and USR_SW.
     * 1 is input, 0 is output
     */
    buf[0] = 0x8CU;
    buf[1] = 0x00U;
    buf[2] = 0x20U;
    buf[3] = 0x1FU;

    ret = I2C_transfer(handle, &i2cTransaction);
    if (ret != I2C_STS_SUCCESS)
    {
        retVal = BOARD_I2C_TRANSFER_FAIL;
        goto close;
    }

    /* Configure TCA6416 on TDA3x audio daughter card (if available) */
    i2cIoctlCmd = BOARD_AUDIO_IO_EXP_TCA6416_I2C_ADDR;
    ret = I2C_control(handle, I2C_CMD_PROBE, &i2cIoctlCmd);
    if (ret != I2C_STS_SUCCESS)
    {
        /* Not an error, just that the device wasn't found (hence, daughter
         * card not connected).
         */
        goto close;
    }

    i2cTransaction.slaveAddress = BOARD_AUDIO_IO_EXP_TCA6416_I2C_ADDR;
    i2cTransaction.writeCount = 3U;

    /* Set P16 (CONFIG_SEL_A) to high which selects the CODEC path at the mux (U23) */
    buf[0] = 0x02U;
    buf[1] = 0x00U;
    buf[2] = 0x40U;

    ret = I2C_transfer(handle, &i2cTransaction);
    if (ret != I2C_STS_SUCCESS)
    {
        retVal = BOARD_I2C_TRANSFER_FAIL;
        goto close;
    }

    /* Set all pins to output */
    buf[0] = 0x06U;
    buf[1] = 0x00U;
    buf[2] = 0x00U;

    ret = I2C_transfer(handle, &i2cTransaction);
    if (ret != I2C_STS_SUCCESS)
    {
        retVal = BOARD_I2C_TRANSFER_FAIL;
        goto close;
    }

close:
    I2C_close(handle);

    /* Reset mode of I2C1 operation back to driver default */
    i2cCfg.enableIntr = enableIntrTmp;
    I2C_socSetInitCfg(0, &i2cCfg);

    return (retVal);
}

Board_STATUS Board_moduleEnable(void)
{
    ModuleMcaspEnable(1);
    ModuleMcspiEnable(1);
    ModuleMmcsdEnable();

    return BOARD_SOK;
}

Board_STATUS Board_gmiiConfig(void)
{
    /* Set GMII selection as RGMII for ports 1 and 2 */
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE + CTRL_CORE_CONTROL_IO_1,
                  CTRL_CORE_CONTROL_IO_1_GMII1_SEL, 2U);
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE + CTRL_CORE_CONTROL_IO_1,
                  CTRL_CORE_CONTROL_IO_1_GMII2_SEL, 2U);

    /* Enable GMAC reset isolation */
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE + CTRL_CORE_CONTROL_IO_2,
                  CTRL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE, 0U);
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE + CTRL_CORE_CONTROL_IO_2,
                  CTRL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE, 1U);

    return BOARD_SOK;
}

/* Typedefs related to TCA6424 device */
#define DEVICE_IOEXP_TCA6424_NUM_PORTS    (3U)
#define DEVICE_IOEXP_TCA6424_CMD_AUTO_INC (0x80U)
#define DEVICE_IOEXP_TCA6424_REG_OUTPUT0  (0x04U)

static Board_STATUS readTca6424OutputPort(I2C_Handle i2cHandle,
                                          uint32_t   i2cDevAddr,
                                          uint8_t   *regValue,
                                          uint32_t   numRegs)
{
    I2C_Transaction i2cTransaction;
    Board_STATUS retVal = BOARD_SOK;
    uint32_t     cnt;
    int16_t      i2cRet;
    uint8_t      tempRegVal[1U];

    if ((NULL == regValue) || (0U == numRegs) ||
        (numRegs > DEVICE_IOEXP_TCA6424_NUM_PORTS))
    {
        retVal = BOARD_INVALID_PARAM;
    }
    else
    {
        /* Common transaction parameters */
        I2C_transactionInit(&i2cTransaction);
        i2cTransaction.timeout = 2000U;
        i2cTransaction.slaveAddress = i2cDevAddr;

        for (cnt = 0U; cnt < numRegs; cnt++)
        {
            /* Set command */
            tempRegVal[0U] = ((uint8_t) DEVICE_IOEXP_TCA6424_REG_OUTPUT0 |
                              (uint8_t) DEVICE_IOEXP_TCA6424_CMD_AUTO_INC) +
                              (uint8_t) cnt;

            i2cTransaction.writeBuf = tempRegVal;
            i2cTransaction.writeCount = 1U;
            i2cTransaction.readBuf = NULL;
            i2cTransaction.readCount = 0;

            i2cRet = I2C_transfer(i2cHandle, &i2cTransaction);

            if (I2C_STS_SUCCESS == i2cRet)
            {
                i2cTransaction.writeBuf = NULL;
                i2cTransaction.writeCount = 0;
                i2cTransaction.readBuf = &regValue[cnt];
                i2cTransaction.readCount = 1U;

                i2cRet = I2C_transfer(i2cHandle, &i2cTransaction);
            }

            if (I2C_STS_SUCCESS != i2cRet)
            {
                retVal = BOARD_I2C_TRANSFER_FAIL;
                break;
            }
        }
    }

    return (retVal);
}

MMCSD_Error MMCSD_iodelayFxn (uint32_t instanceNum,
                              MMCSD_v1_IodelayParams *iodelayParams)
{
    /* We hijack this function so that we can set up pin mux for MMCSD at
     * run-time rather than during board init.  This is because MMCSD pins
     * are muxed at both SOC and Board level.
     *
     * Typically, this function doesn't need to be implemented for this device
     * and the pad config can be handled by the SBL.
     */
    PinmuxMmcsdConfig();

    return MMCSD_OK;
}
