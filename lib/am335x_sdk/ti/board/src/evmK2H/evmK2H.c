/******************************************************************************
 * Copyright (c) 2010-2018 Texas Instruments Incorporated - http://www.ti.com
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
#include "board_utils.h"

Board_gblObj Board_obj;

/* external input clock to System/PA/ARM/DDR3 PLLs */
const uint32_t Board_ext_clk[CSL_PLL_MAX] =
{
    EXT_CLK_122M88,  /* sys clock */
    EXT_CLK_122M88,  /* PA clock */
    EXT_CLK_125M,    /* ARM clock */
    EXT_CLK_100M,    /* DDR3A clock */
    EXT_CLK_100M     /* DDR3B clock */
};

Board_STATUS Board_unlockMMR(void)
{
    CSL_BootCfgUnlockKicker();

    return BOARD_SOK;
}

/**
 * \brief  Board library initialization function
 *
 *  BOARD_INIT_PINMUX_CONFIG -
 *      Pinmuxing is not supported on K2H platform.
 *      Calling Board_init with flag BOARD_INIT_PINMUX_CONFIG
 *      does not have any effect, but returns BOARD_SOK
 *      to the application call.
 *
 */

Board_STATUS Board_init(Board_initCfg cfg)
{
    Board_STATUS ret = BOARD_SOK;

    BOARD_initPerfCounters();

    if (cfg & BOARD_INIT_UNLOCK_MMR)
        ret = Board_unlockMMR();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_PLL)
        ret = Board_PLLInit();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_DDR)
        ret = Board_DDR3Init();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_WATCHDOG_DISABLE)
        return BOARD_UNSUPPORTED_FEATURE;

    if (cfg & BOARD_INIT_PINMUX_CONFIG)
        ret = Board_pinmuxConfig();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_UART_STDIO)
        ret = Board_uartStdioInit();
    if (ret != BOARD_SOK)
        return ret;

    if (cfg & BOARD_INIT_MODULE_CLOCK)
        ret = Board_moduleClockInit();
    if (ret != BOARD_SOK)
        return ret;

    return ret;
}
