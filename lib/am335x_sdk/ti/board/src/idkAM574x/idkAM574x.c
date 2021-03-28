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

#include "board_internal.h"

Board_gblObj Board_obj;

Board_STATUS Board_unlockMMR(void)
{
    CSL_control_coreRegs *ctrlCoreReg =
        (CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS;

    /* unlock MMR1 space for region 0x0100 to 0x079F */
    ctrlCoreReg->MMR_LOCK_1 = 804367403U;
    /* unlock MMR2 space for region 0x07A0 to 0x0D9F */
    ctrlCoreReg->MMR_LOCK_2 = 4149738944U;
    /* unlock MMR3 space for region 0x0DA0 to 0x0FFF */
    ctrlCoreReg->MMR_LOCK_3 = 3803986541U;
    /* unlock MMR4 space for region 0x1000 to 0x13FF */
    ctrlCoreReg->MMR_LOCK_4 = 515838749U;
    /* unlock MMR5 space for region 0x1400 to 0x1FFF */
    ctrlCoreReg->MMR_LOCK_5 = 1865817605U;

    return BOARD_SOK;
}

Board_STATUS Board_watchdogDisable()
{
    CSL_watchdogocp2Regs *watchdogRegs = (CSL_watchdogocp2Regs *) CSL_MPU_WD_TIMER2_REGS;

    /* Wait until reset complete */
    while(CSL_WATCHDOGOCP2_WDST_RESETVAL !=
        CSL_FEXT(watchdogRegs->WDST, WATCHDOGOCP2_WDST_RESETDONE));

    /* Disable watchdog timer */
    CSL_FINS(watchdogRegs->WSPR, WATCHDOGOCP2_WSPR_WSPR_VALUE, 0xAAAAU);

    while(CSL_WATCHDOGOCP2_WWPS_W_PEND_WSPR_RESETVAL !=
        CSL_FEXT(watchdogRegs->WWPS,WATCHDOGOCP2_WWPS_W_PEND_WSPR));

    /* Disable 32Khz watchdog timer */
    CSL_FINS(watchdogRegs->WSPR, WATCHDOGOCP2_WSPR_WSPR_VALUE, 0x5555U);

    while(CSL_WATCHDOGOCP2_WWPS_W_PEND_WSPR_RESETVAL !=
        CSL_FEXT(watchdogRegs->WWPS,WATCHDOGOCP2_WWPS_W_PEND_WSPR));

    return BOARD_SOK;
}

Board_STATUS Board_init(Board_initCfg cfg)
{
    Board_STATUS ret = BOARD_SOK;

    if (cfg & BOARD_INIT_UNLOCK_MMR)
        ret = Board_unlockMMR();
    if (ret != BOARD_SOK)
        return ret;

   if (cfg & BOARD_INIT_PLL)
        ret = Board_PLLInit(OPP_NOM);
    else if(cfg & BOARD_INIT_PLL_OPP_HIGH)
	    ret = Board_PLLInit(OPP_HIGH);
    else if(cfg & BOARD_INIT_PLL_OPP_OD)
	    ret = Board_PLLInit(OPP_OD);
    else if(cfg & BOARD_INIT_PLL_OPP_NOM)
	    ret = Board_PLLInit(OPP_NOM);
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_MODULE_CLOCK)
        ret = Board_moduleClockInit();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_PINMUX_CONFIG)
        ret = Board_pinmuxConfig();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_DDR)
        ret = Board_DDR3Init(0);
    if (ret != BOARD_SOK)
        return ret;
	
    if (cfg & BOARD_INIT_DDR_ECC)
        ret = Board_DDR3Init(1);
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_WATCHDOG_DISABLE)
        ret = Board_watchdogDisable();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_UART_STDIO)
        ret = Board_uartStdioInit();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_ETH_PHY)
        ret = Board_gigEthConfig();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_ICSS_ETH_PHY)
        ret = Board_icssEthConfig();
    if (ret != BOARD_SOK)
        return ret;

    return ret;
}
