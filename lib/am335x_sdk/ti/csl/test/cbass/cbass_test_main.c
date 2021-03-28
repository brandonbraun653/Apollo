/*
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

 /**
 *  \file     cbass_test_main.c
 *
 *  \brief    This file contains cbass test code for R5 core.
 *
 *  \details  CBASS unit tests
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/test/cbass/cbass_test_main.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */



/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */

static int32_t CBASS_appInitBoard(void)
{
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;
    int32_t       testResult = CSL_PASS;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        testResult = CSL_EFAIL;
        UART_printf("[Error] Board init failed!!\n");
    }

    return (testResult);
}

static int32_t CBASS_appTest(uint32_t testId)
{
    int32_t    testResult;

    switch (testId)
    {
        case CBASS_QOS_TEST_ID:
            testResult = CBASS_qosTest();
            UART_printf("\nCBASS QoS Module Test");
            if (testResult == CSL_PASS)
            {
                UART_printf(" Passed.\r\n");
            }
            else
            {
                UART_printf(" Failed.\r\n");
            }
            break;

        case CBASS_ERROR_TEST_ID:
            testResult = CBASS_errTest();
            UART_printf("\nCBASS Error Module Test");
            if (testResult == CSL_PASS)
            {
                UART_printf(" Passed.\r\n");
            }
            else
            {
                UART_printf(" Failed.\r\n");
            }
            break;

        default:
            UART_printf("\n[Error] Invalid CBASS test ID.\r\n");
            break;
    }

    return (testResult);
}

int32_t main(void)
{
    /* Declaration of variables */
    uint32_t testId;
    int32_t  testResult;

    /* Init Board */
    testResult = CBASS_appInitBoard();

    if (testResult == CSL_PASS)
    {
        UART_printf("\nCBASS Test Application\r\n");

        for (testId = ((uint32_t)(0U)); testId < CBASS_TOTAL_NUM_TESTS; testId++)
        {
            testResult = CBASS_appTest(testId);
            if (testResult != CSL_PASS)
            {
                break;
            }
        }
    }

    if (testResult == CSL_PASS)
    {
        UART_printStatus("\r\n All tests have passed. \r\n");
    }
    else
    {
        UART_printStatus("\r\n Some tests have failed. \r\n");
    }

    return (0);
}

/* Nothing past this point */

