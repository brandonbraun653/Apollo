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
 *  \file evmDRA75x.c
 *
 *  \brief EVM board file for DRA75x boards.
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

/* UART Driver Header Files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

/* I2C Driver Header Files */
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include "board.h"
#include "board_internal.h"

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
 *  \brief      Configure EVM I/O expanders.
 *
 *  Note that this is EVM-specific and ideally is not required for a production
 *  design that doesn't multiplex board signals.
 */
Board_STATUS Board_ioexpConfig(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void ModuleMcaspEnable(uint32_t instNum)
{
    switch (instNum)
    {
        case 3:
        {
            /* McASP3 Module Control - Select DPLL_ABE_X1 as McASP3 AUX CLK */
            HW_WR_FIELD32(SOC_L4PER_CM_CORE_BASE + CM_L4PER2_MCASP3_CLKCTRL, \
                          CM_L4PER2_MCASP3_CLKCTRL_MODULEMODE, \
                          CM_L4PER2_MCASP3_CLKCTRL_MODULEMODE_ENABLE);

            while (HW_RD_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER2_MCASP3_CLKCTRL) != \
                   CM_L4PER2_MCASP3_CLKCTRL_MODULEMODE_ENABLE)
                ;

            break;
        }
    }
}

void DllAbeConfig(uint32_t sampRate)
{
    /* Choose SYS_CLK2 (22.5792 MHZ) as source for ABE_PLL REF CLK */
    HW_WR_FIELD32(SOC_CKGEN_PRM_BASE + CM_CLKSEL_ABE_PLL_SYS, \
                  CM_CLKSEL_ABE_PLL_REF_CLKSEL, \
                  CM_CLKSEL_ABE_PLL_SYS_CLKSEL_SEL_SYS_CLK2);

    /* Reprogram ABE DPLL for 451.584 MHz output on PER_ABE_X1_GFCLK line */

    /* step 1: disable the PLL, if enabled (ex: via GEL) */
    while (HW_RD_FIELD32(SOC_CKGEN_CM_CORE_AON_BASE + CM_CLKMODE_DPLL_ABE, \
                         CM_CLKMODE_DPLL_ABE_DPLL_EN) ==
           CM_CLKMODE_DPLL_ABE_DPLL_EN_DPLL_LOCK_MODE)
        HW_WR_FIELD32(SOC_CKGEN_CM_CORE_AON_BASE + CM_CLKMODE_DPLL_ABE, \
                      CM_CLKMODE_DPLL_ABE_DPLL_EN, \
                      CM_CLKMODE_DPLL_ABE_DPLL_EN_DPLL_FR_BYP_MODE);

    switch (sampRate)
    {
        case 44100:
        {
            /* Reprogram ABE DPLL for 22.5792 MHz output on PER_ABE_X1_GFCLK line */
            HW_WR_FIELD32(SOC_CKGEN_CM_CORE_AON_BASE + CM_CLKSEL_DPLL_ABE, \
                          CM_CLKSEL_DPLL_ABE_DPLL_MULT, \
                          0x0A);

            HW_WR_FIELD32(SOC_CKGEN_CM_CORE_AON_BASE + CM_CLKSEL_DPLL_ABE, \
                          CM_CLKSEL_DPLL_ABE_DPLL_DIV, \
                          0x09);

            /* step 3: Configure output clocks parameters - M2 = 1  M3 = 1 */
            HW_WR_FIELD32(SOC_CKGEN_CM_CORE_AON_BASE + CM_DIV_M2_DPLL_ABE, \
                          CM_DIV_M2_DPLL_ABE_DIVHS, \
                          0x1);
            HW_WR_FIELD32(SOC_CKGEN_CM_CORE_AON_BASE + CM_DIV_M3_DPLL_ABE, \
                          CM_DIV_M3_DPLL_ABE_DIVHS, \
                          0x1);
            break;
        }

        case 48000:
        {
            /* Reprogram ABE DPLL for 24.576 MHz output on PER_ABE_X1_GFCLK line */
            HW_WR_FIELD32(SOC_CKGEN_CM_CORE_AON_BASE + CM_CLKSEL_DPLL_ABE, \
                          CM_CLKSEL_DPLL_ABE_DPLL_MULT, \
                          0xA0);

            HW_WR_FIELD32(SOC_CKGEN_CM_CORE_AON_BASE + CM_CLKSEL_DPLL_ABE, \
                          CM_CLKSEL_DPLL_ABE_DPLL_DIV, \
                          0x30);

            /* step 3: Configure output clocks parameters - M2 = 3  M3 = 1 */
            HW_WR_FIELD32(SOC_CKGEN_CM_CORE_AON_BASE + CM_DIV_M2_DPLL_ABE, \
                          CM_DIV_M2_DPLL_ABE_DIVHS, \
                          0x3);
            HW_WR_FIELD32(SOC_CKGEN_CM_CORE_AON_BASE + CM_DIV_M3_DPLL_ABE, \
                          CM_DIV_M3_DPLL_ABE_DIVHS, \
                          0x1);
            break;
        }
    }

    /* step 4: Confirm that the PLL has locked */
    while (HW_RD_FIELD32(SOC_CKGEN_CM_CORE_AON_BASE + CM_CLKMODE_DPLL_ABE, \
                         CM_CLKMODE_DPLL_ABE_DPLL_EN) !=
           CM_CLKMODE_DPLL_ABE_DPLL_EN_DPLL_LOCK_MODE)
        HW_WR_FIELD32(SOC_CKGEN_CM_CORE_AON_BASE + CM_CLKMODE_DPLL_ABE, \
                      CM_CLKMODE_DPLL_ABE_DPLL_EN, \
                      CM_CLKMODE_DPLL_ABE_DPLL_EN_DPLL_LOCK_MODE);
}

Board_STATUS Board_init(Board_initCfg cfg)
{
    Board_STATUS status;
    //volatile uint32_t siliconRev = Board_getSiliconRev();

    if (cfg & BOARD_INIT_PLL)
    {
        status = Board_pllConfig();

        if (status != BOARD_SOK)
            return status;
    }

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
#if defined(__ARM_ARCH_7A__)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_92, CSL_XBAR_GMAC_SW_IRQ_RX_PULSE);
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_93, CSL_XBAR_GMAC_SW_IRQ_TX_PULSE);
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_MPU, CSL_XBAR_INST_MPU_IRQ_72, CSL_XBAR_UART1_IRQ);
#elif defined(__TI_ARM_V7M4__)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_60, CSL_XBAR_GMAC_SW_IRQ_RX_PULSE);
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_61, CSL_XBAR_GMAC_SW_IRQ_TX_PULSE);
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1, CSL_XBAR_INST_IPU1_IRQ_24, CSL_XBAR_UART1_IRQ);
#elif defined(_TMS320C6X)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_DSP1, CSL_XBAR_INST_DSP1_IRQ_48, CSL_XBAR_UART1_IRQ);
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
    status = Board_ioexpConfig();
    if (status != BOARD_SOK)
        return status;

    return BOARD_SOK;
}

Board_STATUS Board_moduleEnable(void)
{
    ModuleMcaspEnable(3);

    return BOARD_SOK;
}

Board_STATUS Board_pllConfig(void)
{
    DllAbeConfig(BOARD_AUDIO_SAMPLERATE);

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

Board_STATUS Board_ioexpConfig(void)
{
    I2C_Params i2cParams;
    I2C_Handle handle;
    I2C_Transaction i2cTransaction;
    I2C_HwAttrs     i2cCfg;
    bool            enableIntrTmp;
    char rxTxBuf[2] = {0};
    int16_t ret;

    I2C_init();

    I2C_Params_init(&i2cParams);

    /* I2C1 writes to I/O expanders */
    /* Force I2C1 to operate in polling mode, temporarily */
    I2C_socGetInitCfg(0, &i2cCfg);
    enableIntrTmp     = i2cCfg.enableIntr;
    i2cCfg.enableIntr = false;
    I2C_socSetInitCfg(0, &i2cCfg);

    /* Open I2C1 instance */
    handle = I2C_open(0, &i2cParams);

    if (handle == NULL)
    {
        UART_printf("Board_ioexpConfig: failed to open I2C1\n");

        return BOARD_I2C_OPEN_FAIL;
    }

    /* Common transaction parameters */
    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.writeBuf = (uint8_t *)&rxTxBuf[0];
    i2cTransaction.readBuf  = (uint8_t *)&rxTxBuf[0];
    i2cTransaction.timeout  = 2000U;

    /*
     * Set EXP_ETH0_RSTn = EXP_ETH1_RSTn = 1 (PCF8575's P10 and P11)
     * in order to drive the board's PHYs out of reset
     */
    i2cTransaction.slaveAddress = I2C_ADDR_PCF8575_PHY_NRESET;

    i2cTransaction.writeCount   = 0;
    i2cTransaction.readCount    = 2;
    ret = I2C_transfer(handle, &i2cTransaction);

    if (ret != I2C_STS_SUCCESS)
    {
        UART_printf("Board_ioexpConfig: transfer to slave 0x%x failed: %d\n",
                    i2cTransaction.slaveAddress, ret);
    }

    i2cTransaction.writeCount = 2;
    i2cTransaction.readCount  = 0;
    rxTxBuf[1] |= 0x03;
    ret         = I2C_transfer(handle, &i2cTransaction);

    if (ret != I2C_STS_SUCCESS)
    {
        UART_printf("Board_ioexpConfig: transfer to slave 0x%x failed: %d\n",
                    i2cTransaction.slaveAddress, ret);
    }

    /*
     * Set SEL_ENET_MUX_S0 = 1 (PCF8575's P4) in order to select
     * the EMAC0 pins in the bus switch.
     * Set MMC_PWR_ON = 1 (PCF8575's P5) in order to provide
     * EVM_3V3_SD supply from the bus switch.
     */
    i2cTransaction.slaveAddress = I2C_ADDR_PCF8575_EMAC_PINS;

    i2cTransaction.writeCount   = 0;
    i2cTransaction.readCount    = 2;
    ret = I2C_transfer(handle, &i2cTransaction);

    if (ret != I2C_STS_SUCCESS)
    {
        UART_printf("Board_ioexpConfig: transfer to slave 0x%x failed: %d\n",
                    i2cTransaction.slaveAddress, ret);
    }

    i2cTransaction.writeCount = 2;
    i2cTransaction.readCount  = 0;
    rxTxBuf[0] |= 0x30;
    ret         = I2C_transfer(handle, &i2cTransaction);

    if (ret != I2C_STS_SUCCESS)
    {
        UART_printf("Board_ioexpConfig: transfer to slave 0x%x failed: %d\n",
                    i2cTransaction.slaveAddress, ret);
    }

    I2C_close(handle);

    /* Reset mode of I2C1 operation back to driver default */
    i2cCfg.enableIntr = enableIntrTmp;
    I2C_socSetInitCfg(0, &i2cCfg);

    /* I2C2 writes to I/O expanders */
    /* Force I2C2 to operate in polling mode, temporarily */
    I2C_socGetInitCfg(1, &i2cCfg);
    enableIntrTmp     = i2cCfg.enableIntr;
    i2cCfg.enableIntr = false;
    I2C_socSetInitCfg(1, &i2cCfg);

    /* Open I2C2 instance */
    handle = I2C_open(1, &i2cParams);

    if (handle == NULL)
    {
        UART_printf("Board_ioexpConfig: failed to open I2C2\n");

        return BOARD_I2C_OPEN_FAIL;
    }

    /*
     * Set VIN6_SEL_S0 = 0 (PCF8575's P1) in order to select
     * the McASP3 pins in the bus switch.
     * Set VIN2_S0 = 1 (PCF8575's P2) in order to select RGMII1
     * pins in the VIN/RGMII bus switch.
     */
    i2cTransaction.slaveAddress = I2C_ADDR_PCF8575_MCASP_SEL;

    i2cTransaction.writeCount   = 0;
    i2cTransaction.readCount    = 2;
    ret = I2C_transfer(handle, &i2cTransaction);

    if (ret != I2C_STS_SUCCESS)
    {
        UART_printf("Board_ioexpConfig: transfer to slave 0x%x failed: %d\n",
                    i2cTransaction.slaveAddress, ret);
    }

    i2cTransaction.writeCount = 2;
    i2cTransaction.readCount  = 0;
    rxTxBuf[0] &= ~(0x02);
    rxTxBuf[0] |= 0x04;

    ret         = I2C_transfer(handle, &i2cTransaction);

    if (ret != I2C_STS_SUCCESS)
    {
        UART_printf("Board_ioexpConfig: transfer to slave 0x%x failed: %d\n",
                    i2cTransaction.slaveAddress, ret);
    }

    /* Reset mode of I2C2 operation back to driver default */
    i2cCfg.enableIntr = enableIntrTmp;
    I2C_socSetInitCfg(1, &i2cCfg);

    I2C_close(handle);

    return BOARD_SOK;
}

uint32_t Board_getSiliconRev(void)
{
    uint32_t siliconRev;

    siliconRev = HW_RD_REG32(SOC_CTRL_MODULE_WKUP_CORE_REGISTERS_BASE +
                             CTRL_WKUP_ID_CODE);

    siliconRev = (siliconRev & 0xF0000000U) >> 28U;

    return (siliconRev);
}
