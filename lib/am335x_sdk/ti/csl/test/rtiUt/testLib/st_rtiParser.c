/*
 *  Copyright (c) 2019 Texas Instruments Incorporated
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
 */

/**
 *  \file st_rtiParser.c
 *
 *  \brief User interface for RTIs driver testing.
 *
 *  This file takes the input from the user specified test file and
 *  then initiates the tests on RTI driver accordingly.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_rti.h>
#include <st_rtiTestCases.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   Parse the testcase data
 *
 * \param   None.
 *
 * \return  None
 */
int32_t rtiParser(void);

/**
 * \brief   Get the index of the testcase to run from st_rtiTestcases.h.
 *
 * \param   testcaseId        Testcase Id to run.
 *
 * \return  None
 */
int32_t rtiGetTestcaseIdx(uint32_t testcaseId);

/**
 * \brief   Fetch testcase data and run the testcase.
 *
 * \param   testParams        structure to details of testcase to run.
 *
 * \return  None
 */
void rtiRunTestcase(st_RTITestcaseParams_t *testParams);

/**
 * \brief   Print main menu.
 *
 * \param   None.
 *
 * \return  None
 */
void st_rtiShowMainMenu(void);

/**
 * \brief   Print main menu.
 *
 * \param   None.
 *
 * \return  None
 */
void st_rtiShowMainMenu(void);

/**
 * \brief   Print RTI testcases.
 *
 * \return  None
 */
void st_rtiPrintTCs(void);

/**
 * \brief   Print RTI testcase details.
 *
 * \return  None
 */
void st_rtiPrintTCDetails(uint32_t testId);

/**
 * \brief   Initialize  RTI testcase details.
 *
 * \return  None
 */
void st_rtiTCResultInit(void);

/**
 * \brief   Initializes board/UART
 */
static void RTIAppInitUart(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t rtiParser(void)
{
    uint32_t done = 0U;
    int32_t  testcaseIdx, testId;

    char option;
    st_RTITestcaseParams_t *testParams;

    RTIAppInitUart();
    st_rtiTCResultInit();

    while(!done)
    {
        st_rtiShowMainMenu();
        UART_printf("\nEnter your choice: ");
        UART_scanFmt("%c", &option);
        switch(option)
        {
            case '1':
                UART_printf("\nEnter testcase ID to run: ");
                UART_scanFmt("%d", &testId);
                testcaseIdx = rtiGetTestcaseIdx(testId);
                if(testcaseIdx < 0)
                {
                    UART_printf("Invalid test case Id.");
                }
                else if(TEST_ENABLE == gRTITestcaseParams[testcaseIdx].enableTest)
                {
                    testParams = &gRTITestcaseParams[testcaseIdx];
                    rtiRunTestcase(testParams);
                }
                UART_printf("RTI UT doesnot allow running tests back to back.\n");
                UART_printf("Exiting RTI UT.\n");
                done = 1;
            break;
            case 'd':
                st_rtiPrintTCs();
            break;
            case 't':
                UART_printf("\nEnter testcase ID: ");
                UART_scanFmt("%d",&testId);
                testcaseIdx = rtiGetTestcaseIdx(testId);
                if(testcaseIdx < 0)
                {
                    UART_printf("Invalid test case Id.");
                }
                else
                {
                    st_rtiPrintTCDetails(testcaseIdx);
                }
            break;
            case 'q':
                UART_printf("Exiting RTI UT.\n");
                done = 1;
            break;
        }
    }

    return 0;
}

int32_t rtiGetTestcaseIdx(uint32_t testcaseId)
{
    int32_t testcaseIdx = -1;
    uint32_t testCnt;
    const st_RTITestcaseParams_t *testParams;

    testParams = &gRTITestcaseParams[0u];
    for(testCnt = 0 ; testCnt < RTI_NUM_TESTCASES ; testCnt++)
    {
        if (testParams[testCnt].testcaseId == testcaseId)
        {
            testcaseIdx = testCnt;
            break;
        }
    }
    return testcaseIdx;
}

void rtiRunTestcase(st_RTITestcaseParams_t *testParams)
{
    UART_printf("\n|TEST START|:: %u ::\n", testParams->testcaseId);
    UART_printf("|TEST PARAM|:: %s ::\n", testParams->testCaseName);

    UART_printf("Testcase Settings:\n");
    UART_printf("--------------------------------------------------------------\n");
    UART_printf("Module                                              :0x%x\n",
        testParams->rtiConfigParams.rtiModule);
    UART_printf("RTI Clock source                                    :0x%x\n",
        testParams->rtiConfigParams.rtiClkSrc);
    if (testParams->testcaseId == APP_RTI_DWWD_CODE_COVERAGE_TEST)
    {
        testParams->testResult = st_rtiCodeCoverage_main(testParams);
    }
    else
    {
        testParams->testResult = st_rtiSingleShot_main(testParams);
    }
    UART_printf("\n======================== FINISHED ==========================\n");

    if(testParams->testResult == 0U)
        UART_printf("|TEST RESULT|PASS|%u|\n", testParams->testcaseId);
    else
        UART_printf("|TEST RESULT|FAIL|%u|\n", testParams->testcaseId);

    UART_printf("|TEST INFO|:: %s ::\n", testParams->testCaseName);
    UART_printf("|TEST END|:: %u ::\n", testParams->testcaseId);

    if (testParams->testResult == 0U)
    {
        UART_printStatus("\n ALL TESTS PASSED \n");
    }
    else
    {
        UART_printStatus("\n Few/all tests Failed \n");
    }
}

void st_rtiShowMainMenu(void)
{
    UART_printf("\n=============\n");
    UART_printf("RTI UT Select\n");
    UART_printf("=============\n");
    UART_printf("\nRTI UT main menu:\n");
    UART_printf("1: Manual testing (select specific test case to run)\n");
    UART_printf("d: Display test cases.\n");
    UART_printf("t: Display test case Details.\n");
    UART_printf("q: Quit.\n");
}

void st_rtiPrintTCs(void)
{
    uint32_t loopCnt;
    const st_RTITestcaseParams_t *testParams;

    UART_printf("RTI Testcase:\n");
    UART_printf("--------------------------------------------------------------\n");
    UART_printf("TC Id\tTC name\n");
    UART_printf("--------------------------------------------------------------\n");
    for(loopCnt = 0 ; loopCnt < RTI_NUM_TESTCASES; loopCnt++)
    {
        testParams = &gRTITestcaseParams[loopCnt];
        if (TEST_ENABLE == testParams->enableTest)
        {
            UART_printf("%d\t%s\n", testParams->testcaseId,testParams->testCaseName);
        }
    }
    UART_printf("--------------------------------------------------------------\n");
}

void st_rtiPrintTCDetails(uint32_t testId)
{
    const st_RTITestcaseParams_t *testParams;

    testParams = &gRTITestcaseParams[testId];
    UART_printf("Testcase Id : %d\n", testParams->testcaseId);
    UART_printf("Testcase Name : %s", testParams->testCaseName);
    UART_printf("\nTestcase Enabled(0-Disabled/1-Enabled) : %d",
           testParams->enableTest);
    UART_printf("\nTestcase Disable Reason : %s", testParams->disableInfo);
    UART_printf("\nTestcase Print Enable(0-Disabled/1-Enabled) : %d\n",
           testParams->printEnable);
}

void st_rtiTCResultInit(void)
{
    uint32_t loopCnt;
    st_RTITestcaseParams_t * testParams;

    for(loopCnt = 0 ; loopCnt < RTI_NUM_TESTCASES; loopCnt++)
    {
        testParams              = &gRTITestcaseParams[loopCnt];
        testParams->isRun       = STW_EFAIL;
        testParams->testResult  = STW_EFAIL;
    }
}

static void RTIAppInitUart(void)
{
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        UART_printf("[Error] Board init failed!!\n");
    }
}

