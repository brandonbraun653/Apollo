/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2019
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
 */

/*
 * main_a53.c
 */
#include <stdio.h>
#include <stdint.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>
#include "ecc_msmc.h"

#include <ti/osal/osal.h>
#include <ti/board/board.h>

/* ----------------- Constant definitions ----------------- */

/* The following statements define Menu options */
#define MAIN_MSMC_ECC_TEST            ('1')

/* ------------------------------------------------------- */

/* ----------------- Function prototypes ----------------- */

static void mainMenu(char *option);


/* --------------------------------------------------- */

/* ----------------- Global variables ----------------- */
uint32_t gUartBaseAddr = CSL_UART0_BASE;


/* --------------------------------------------------- */

/* The main code here initializes the platform and processes
 * commands through UART port.
 * The menu commands are hierarchical and starts with the main menu with
 * the class of tests. The test classes include OCMC ecc test, EMIF ecc test
 * and DSP ECC test.
 * The OCMC err test & EMIF err test functions are in thier respective
 * separate c files and are used by all cores.
 * Once the class of tests are selected, then the submenu options for
 * the chosen class, are processed.
 */
int main(void)
{
    int32_t           retVal   = CSL_PASS;
    char              mainMenuOption;
    Board_initCfg     boardCfg;

    boardCfg = (Board_initCfg) (((uint32_t) BOARD_INIT_PINMUX_CONFIG ) |
                                ((uint32_t) BOARD_INIT_UART_STDIO ));

    Board_init(boardCfg);


    /* Do main command line processing */
    while (1)
    {
        mainMenu(&mainMenuOption);
        if (MAIN_MSMC_ECC_TEST == mainMenuOption)
        {
            /* Handle MSMC ECC test menu */
            retVal = msmcEccTest();
            /* exit the test */
           break;
        }
        else
        {
            UARTConfigPuts(gUartBaseAddr, "\r\n  ECC test exiting...", -1);
            break;
        }
    };
    return retVal;
}

/* The following routine handles main menu options*/
static void mainMenu(char *option)
{
    while (1)
    {
        *option = MAIN_MSMC_ECC_TEST;
        break;
    }
}
