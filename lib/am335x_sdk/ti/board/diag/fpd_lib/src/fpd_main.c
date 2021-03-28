/******************************************************************************
 * Copyright (c) 2019-2020 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   fpd_main.c
 *
 *  \brief  fpd lib test file
 *
 *  Targeted Functionality: Verification of basic read write verification 
 *  of FPD library API's
 *
 *  Operation: This test is used to verify write and read back of all
 *  fpd library API's by setting and clearing the most possible bits
 *  of all register configurations supported by library API's.
 *
 *  Supported SoCs: J721E.
 *
 *  Supported Platforms: j721e_evm.
 *
 */
 
#include "fpd_common.h"

/**
 *  \brief   FPD lib Diagnostic test main function
 *
 *  \return    0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
    uint8_t userInput = 0;
    uint8_t ret = 0;

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO |
               BOARD_INIT_PINMUX_CONFIG;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }
	UART_printf("\n*********************************************\n");
	UART_printf("*               FPD LIB TEST                *\n");
	UART_printf("*********************************************\n");

    while ((userInput != 1) || (userInput != 2))
    {
        UART_printf("\n1.FPD DSI (ds90ub941 & ds90ub924)\n");
        UART_printf  ("2.FPD TUNER (ds90ub926 & ds90ub925)\n");
        UART_printf  ("3.FPD CSI (ds90ub9702)\n");
        UART_printf  ("Select Option: ");
        UART_scanFmt("%d", &userInput);
        
        if (userInput == 1)
        {
            ret = BoardDiag_fpd_dsi_test();
            if(ret == 0)
            {
                UART_printf("\nFPD LIB test Passed\n");             
            }
            else
            {
                UART_printf("\nFPD LIB test Failed\n");                     
            }           
        }
        
        if (userInput == 2)
        {
            ret = BoardDiag_fpdTuner_run_test();
            if(ret == 0)
            {
                UART_printf("\nFPD LIB test Passed\n");             
            }
            else
            {
                UART_printf("\nFPD LIB test Failed\n");                     
            }
        }
        if (userInput == 3)
        {
            ret = BoardDiag_fpdCsi_run_test();
            if(ret == 0)
            {
                UART_printf("\nFPD LIB test Passed\n");
            }
            else
            {
                UART_printf("\nFPD LIB test Failed\n");
            }
        }
    }

	return 0;
}
