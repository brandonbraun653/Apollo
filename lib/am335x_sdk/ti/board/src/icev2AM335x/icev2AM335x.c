/******************************************************************************
 * Copyright (c) 2010-2017 Texas Instruments Incorporated - http://www.ti.com
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

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "board_internal.h"
#include "error.h"
#include "chipdb.h"
#include "prcm.h"
#include "board_cfg.h"
#include "hw_cm_wkup.h"
#include "hw_cm_dpll.h"

/* EEPROM data on ICEv 2.1A */
char eepromData[I2C_EEPROM_RX_LENGTH] = {0x55, 0x33, 0xEE, 0x41, 0x33,
                                         0x33, 0x35, 0x5f, 0x49, 0x43};

/* Serializer data */
char serializerData[1] = {0x81};										 

Board_gblObj Board_obj;

/* Configures the display PLL */
static void Board_initDispPll(uint32_t dpllMult,
                              uint32_t dpllDiv,
                              uint32_t dpllPostDivM2)
{
    /* Put the PLL in bypass mode */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_DISP,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN_SHIFT,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN_DPLL_MN_BYP_MODE);

     /* Wait for DPLL to go in to bypass mode */

    while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_DISP,
        CM_WKUP_CM_IDLEST_DPLL_DISP_ST_MN_BYPASS,
        CM_WKUP_CM_IDLEST_DPLL_DISP_ST_MN_BYPASS_SHIFT));

    /* Set the multipler and divider values for the PLL */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_DISP,
        CM_WKUP_CM_CLKSEL_DPLL_DISP_DPLL_MULT,
        CM_WKUP_CM_CLKSEL_DPLL_DISP_DPLL_MULT_SHIFT,
        dpllMult);
    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKSEL_DPLL_DISP,
        CM_WKUP_CM_CLKSEL_DPLL_DISP_DPLL_DIV,
        CM_WKUP_CM_CLKSEL_DPLL_DISP_DPLL_DIV_SHIFT,
        dpllDiv);

    /* Set the CLKOUT2 divider */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_DIV_M2_DPLL_DISP,
        CM_WKUP_CM_DIV_M2_DPLL_DISP_DPLL_CLKOUT_DIV,
        CM_WKUP_CM_DIV_M2_DPLL_DISP_DPLL_CLKOUT_DIV_SHIFT,
        dpllPostDivM2);

    /* Now LOCK the PLL by enabling it */

    HW_WR_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_CLKMODE_DPLL_DISP,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN_SHIFT,
        CM_WKUP_CM_CLKMODE_DPLL_DISP_DPLL_EN);

    while(0U == HW_RD_FIELD32_RAW(SOC_CM_WKUP_REGS + CM_WKUP_CM_IDLEST_DPLL_DISP,
        CM_WKUP_CM_IDLEST_DPLL_DISP_ST_DPLL_CLK,
        CM_WKUP_CM_IDLEST_DPLL_DISP_ST_DPLL_CLK_SHIFT));
}

/* Function to select the ICSS clock output.
 * Supports configuring the ICSS clock to either 200MHz and 225MHz.
 * L3F clock is used as OCP Clock of PRU-ICSS for 200MHz
 * DISP DPLL clock is used as OCP clock of PRU-ICSS for 225MHz.
 *
 * Note that display clock output will be 225MHz when setting
 * ICSS clock to 225MHz. Display applications should take care of
 * this change.
 */
Board_STATUS Board_PLLICSSConfig(BoardIcssClkOut clkOut)
{
    Board_STATUS status = BOARD_SOK;

    if(clkOut == BOARD_ICSS_PLL_CLK_225MHZ)
    {
        /* Change the display PLL to output 225MHz clock */
        Board_initDispPll(BOARD_ICSS_CLK_225MHZ_DISP_DPLL_MULT,
                          BOARD_ICSS_CLK_225MHZ_DISP_DPLL_DIV,
                          BOARD_ICSS_CLK_225MHZ_DISP_DPLL_POST_DIVM2);

        /* Select DISP DPLL clock as OCP clock of PRU-ICSS */
        HW_WR_REG32(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_ICSS_OCP_CLK, 0x01);
    }
    else if(clkOut == BOARD_ICSS_PLL_CLK_200MHZ)
    {
        /* Set the display PLL to 48MHz default output while using
           L3F clock output for ICSS.
           No changes to core PLL are done here as it will be done by SBL */
        Board_initDispPll(BOARD_DISP_DPLL_DEFAULT_MULT,
                          BOARD_DISP_DPLL_DEFAULT_DIV,
                          BOARD_DISP_DPLL_DEFAULT_POST_DIVM2);

        /* Select L3F clock as OCP Clock of PRU-ICSS */
        HW_WR_REG32(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_ICSS_OCP_CLK, 0);
    }
    else
    {
        /* Unsupported configuration  */
        status = BOARD_INVALID_PARAM;
    }

    return status;
}

/* Set the desired DDR3 configuration -- assumes 66.67 MHz DDR3 clock input */
Board_STATUS Board_DDR3Init()
{
    return BOARD_SOK;
}

/* Set the desired DDR3 configuration -- assumes 66.67 MHz DDR3 clock input */
Board_STATUS Board_PLLInit()
{
    return BOARD_SOK;
}

/* Flag indicating pinMux for ICSS (1U) or CPSW (0U) */
uint32_t icssPinMuxFlag = 0U;

/* Set the desired DDR3 configuration -- assumes 66.67 MHz DDR3 clock input */
Board_STATUS Board_moduleClockInit()
{
    int32_t status;
    
    /* UART */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_UART, 0U, 0U);
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_UART, 1U, 0U);
    }
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_UART, 3U, 0U);
    }
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_UART, 4U, 0U);
    }
    
    /* CPSW */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_CPSW, 0U, 0U);
    }    
    
    /* GPIO */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_GPIO, 0U, 0U);
    }
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_GPIO, 1U, 0U);
    }
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_GPIO, 2U, 0U);
    }
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_GPIO, 3U, 0U);
    }

    /* I2C */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_I2C, 0U, 0U);
    }

    /* MCSPI */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_MCSPI, 0U, 0U);
    }
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_MCSPI, 1U, 0U);
    }

    /* EDMA3CC */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_EDMA3CC, 0U, 0U);
    }

    /* EDMA3TC0 */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_EDMA3TC, 0U, 0U);
    }

    /* EDMA3TC1 */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_EDMA3TC, 1U, 0U);
    }

    /* EDMA3TC2 */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_EDMA3TC, 2U, 0U);
    }

    /* MMCSD */
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_MMCSD, 0U, 0U);
    }

    /*GPMC*/
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_GPMC, 0U, 0U);
    }
    
    /*PRU_ICSS*/
    if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_PRU_ICSS, 1U, 0U);
    }

    /* RTCSS */
     if(S_PASS == status)
    {
        status = PRCMModuleEnable(CHIPDB_MOD_ID_RTCSS, 0U, 0U);
    }

    return BOARD_SOK;
}

Board_STATUS Board_init(Board_initCfg cfg)
{
    Board_STATUS ret = BOARD_SOK;

    if (cfg & BOARD_INIT_PLL)
        ret = Board_PLLInit();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_MODULE_CLOCK)
        ret = Board_moduleClockInit();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_DDR)
        ret = Board_DDR3Init();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_ICSS_PINMUX)
    {
        icssPinMuxFlag = 1U;
        ret = Board_pinmuxConfig();
    }
    else if (cfg & BOARD_INIT_PINMUX_CONFIG)
    {
        ret = Board_pinmuxConfig();
    }
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_UART_STDIO)
        ret = Board_uartStdioInit();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_ICSS_ETH_PHY)
        ret = Board_icssEthConfig();
    if (ret != BOARD_SOK)
        return ret;

    return ret;
}
