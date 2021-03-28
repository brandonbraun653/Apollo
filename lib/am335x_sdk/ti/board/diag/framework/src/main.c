/**
 * \file   main.c
 *
 * \brief  Diagnostic test framework main file
 */

/**
 * \copyright Copyright (C) 2013-2018 Texas Instruments Incorporated -
 *            http://www.ti.com/
 */

/*
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdio.h>
#include <ti/fs/fatfs/FATFS.h>
#ifdef ICE_K2G
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>
#endif

#include "framework.h"
#include "board.h"

#if defined(SOC_K2G) || defined(SOC_AM65XX) || defined(SOC_J721E)
#include "diag_common_cfg.h"
#endif

#if defined(SOC_AM65XX)
#include <ti/drv/uart/UART_stdio.h>
#endif

FATFS_Handle fatfsHandle = NULL;

#ifdef ICE_K2G
extern MMCSD_v1_HwAttrs MMCSDInitCfg[];
#endif

volatile uint8_t breakDiagLoop = 0;
int main()
{
    Board_initCfg boardCfg;

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#if (defined(SOC_AM65XX) || defined(SOC_J721E)) && !defined(__aarch64__)
    BoardDiag_timerIntrDisable();
#endif

#ifdef SPI_BOOT_FRAMEWORK
    boardCfg = BOARD_INIT_PLL |
               BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
#if defined(SOC_AM335x) || defined(SOC_AM437x)
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_PINMUX_CONFIG | 
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
#endif
    Board_init(boardCfg);

#ifdef ICE_K2G
    MMCSDInitCfg[1].cardType = MMCSD_CARD_SD;
#endif

#ifndef iceAMIC110
    FATFS_init();

    FATFS_open(0U, 0U, &fatfsHandle);
#endif

    while(!breakDiagLoop)
    {
        DIAG_main();
    }

    return 0;
}
