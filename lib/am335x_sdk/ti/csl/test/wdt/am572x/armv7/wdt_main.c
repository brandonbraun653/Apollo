/**
 * \file   wdt_main.c
 *
 * \brief  Example application main source file, which configures the WDT IP
 *         and executes the CPU reset use case. On overflow of the Watchdog
 *         timer a reset will occur on the CPU.
 */

/**
 * \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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
#include <ti/csl/tistdtypes.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_wdt.h>
#include <ti/csl/csl_wdtAux.h>
#include <ti/board/board.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/drv/uart/UART_stdio.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** @{ */
/** \brief Counter value to be programmed. */
#define INITIAL_COUNT_VALUE          (0xFFFE0000u)

/** \brief Reload count value to be programmed. */
#define RELOAD_COUNT_VALUE           (0xFFFE0000u)
/** @} */

/* Enable the below macro to have prints on the IO Console */
//#define IO_CONSOLE

#ifndef IO_CONSOLE
#define WDT_log                UART_printf
#else
#define WDT_log                printf
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

Int32 main()
{
    Uint32 status = 0U;
    Uint32 prescaler = CSL_WDT_PRESCALER_CLK_DIV_1;
    Uint32 counterVal = INITIAL_COUNT_VALUE;
    Uint32 reloadVal = RELOAD_COUNT_VALUE;
    Board_initCfg boardCfg;

    /* Call board init functions */
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

    /* Reset the Watchdog timer. */
    CSL_wdtReset((CSL_wdtHandle) CSL_MPU_WD_TIMER2_REGS);

    /* Disable the Watchdog timer. */
    CSL_wdtEnable((CSL_wdtHandle) CSL_MPU_WD_TIMER2_REGS, FALSE);

    /* Enable and configure the prescaler clock. */
    CSL_wdtPrescalerClkEnable((CSL_wdtHandle) CSL_MPU_WD_TIMER2_REGS, prescaler);

    /* Configure the WDT counter. */
    CSL_wdtSetCounter((CSL_wdtHandle) CSL_MPU_WD_TIMER2_REGS, counterVal);

    /* Configure the WDT reload value. */
    CSL_wdtSetReloadVal((CSL_wdtHandle) CSL_MPU_WD_TIMER2_REGS, reloadVal);

    /* Enable the Watchdog timer. */
    CSL_wdtEnable((CSL_wdtHandle) CSL_MPU_WD_TIMER2_REGS, TRUE);

    /* Send the message to UART console */
    WDT_log("Program reset will occur on timeout!\n\r");

    while(1)
    {
        /*
        ** WDT will timeout and reset will occur.
        */
        ;
    }

    return(status);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */
