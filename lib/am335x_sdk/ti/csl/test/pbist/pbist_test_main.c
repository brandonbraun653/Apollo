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
 *  \file     pbist_test_main.c
 *
 *  \brief    This file contains PBIST test code.
 *
 *  \details  PBIST unit tests
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/test/pbist/pbist_test_main.h>
#include <ti/drv/sciclient/sciclient.h>
#include <ti/osal/osal.h>
#include <ti/osal/TimerP.h>

#ifdef UNITY_INCLUDE_CONFIG_H
#include <ti/build/unit-test/Unity/src/unity.h>
#include <ti/build/unit-test/config/unity_config.h>
#endif

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
#ifdef UNITY_INCLUDE_CONFIG_H
/*
 *  ======== Unity set up and tear down ========
 */
void setUp(void)
{
    /* Do nothing */
}

void tearDown(void)
{
    /* Do nothing */
}
#endif

static 
int32_t PBIST_appInitBoard(void)
{
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;
    int32_t       testResult = CSL_PASS;
    uint64_t mcuClkFreq;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        testResult = CSL_EFAIL;
        UART_printf("[Error] Board init failed!!\n");
    }

#ifdef BUILD_MCU1_0
    /* Following code is needed to set Osal timing */
    /* Get the clock frequency */
    testResult = Sciclient_pmGetModuleClkFreq(TISCI_DEV_MCU_R5FSS0_CORE0,
                                              TISCI_DEV_MCU_R5FSS0_CORE0_CPU_CLK,
                                              &mcuClkFreq,
                                              SCICLIENT_SERVICE_WAIT_FOREVER);
    if (testResult == 0)
    {
        Osal_HwAttrs  hwAttrs;
        uint32_t      ctrlBitmap;

        testResult = Osal_getHwAttrs(&hwAttrs);
        if (testResult == 0)
        {
            /*
             * Change the timer input clock frequency configuration
               based on R5 CPU clock configured
             */
            hwAttrs.cpuFreqKHz = (int32_t)(mcuClkFreq/1000U);
            ctrlBitmap         = OSAL_HWATTR_SET_CPU_FREQ;
            testResult = Osal_setHwAttrs(ctrlBitmap, &hwAttrs);
        }
    }
    UART_printf("mcuClkFreq %d\n", (uint32_t)mcuClkFreq);
#endif
    return (testResult);
}

static
int32_t PBIST_appTest(uint32_t testId)
{
    int32_t    testResult;

    switch (testId)
    {
        case PBIST_FUNC_TEST_ID:
            testResult = PBIST_funcTest();
            UART_printf("\n PBIST Functionality Test");
            if (testResult == CSL_PASS)
            {
                UART_printf(" Passed.\r\n");
            }
            else
            {
                UART_printf(" Failed.\r\n");
            }
            break;

        case PBIST_ERROR_TEST_ID:
            testResult =PBIST_errTest();
            UART_printf("\n PBIST Error Module Test");
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
            UART_printf("\n [Error] Invalid LBIST test ID.\r\n");
            testResult = CSL_EFAIL;
            break;
    }

    return (testResult);
}

void test_csl_pbist_test_app(void)
{
    /* @description: Run pbist tests

       @requirements: PRSDK-6641

       @cores: mcu1_0 */
    uint32_t testId;
    int32_t  testResult;

    for (testId = ((uint32_t)(0U)); testId < PBIST_TOTAL_NUM_TESTS; testId++)
    {
        testResult = PBIST_appTest(testId);
        if (testResult != CSL_PASS)
        {
            break;
        }
    }

    if (testResult == CSL_PASS)
    {
        UART_printStatus("\r\nAll tests have passed. \r\n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_PASS();
#endif
    }
    else
    {
        UART_printStatus("\r\nSome tests have failed. \r\n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_FAIL();
#endif
    }
}

void test_csl_pbist_test_app_runner(void)
{
    /* @description: Test runner for PBIST all tests

       @requirements: PRSDK-6641

       @cores: mcu1_0 */

#ifdef UNITY_INCLUDE_CONFIG_H
    UNITY_BEGIN();
    RUN_TEST(test_csl_pbist_test_app);
    UNITY_END();
    /* Function to print results defined in our unity_config.h file */
    print_unityOutputBuffer_usingUARTstdio();
#else
    test_csl_pbist_test_app();
#endif
}

int32_t main(void)
{
    /* Declaration of variables */
    int32_t  testResult;

    /* Init Board */
    testResult = PBIST_appInitBoard();

    if (testResult == CSL_PASS)
    {
        UART_printf("\nPBIST Test Application\r\n");
        test_csl_pbist_test_app_runner();

    }

    if (testResult == CSL_PASS)
    {
        UART_printStatus("\r\nAll tests have passed. \r\n");
    }
    else
    {
        UART_printStatus("\r\nSome tests have failed. \r\n");
    }

    return (0);
}

/* Nothing past this point */
