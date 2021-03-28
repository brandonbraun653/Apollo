/*
 *  Copyright (c) Texas Instruments Incorporated 2018
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
 *  \file st_dccParser.c
 *
 *  \brief User interface for DCCs driver testing.
 *
 *  This file takes the input from the user specified test file and
 *  then initiates the tests on DCC driver accordingly.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_dcc.h>
#include <st_dccTestCases.h>

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
int32_t dccParser(void);

/**
 * \brief   Get the index of the testcase to run from st_dccTestcases.h.
 *
 * \param   testcaseId        Testcase Id to run.
 *
 * \return  None
 */
int32_t dccGetTestcaseIdx(uint32_t testcaseId);

/**
 * \brief   Fetch testcase data and run the testcase.
 *
 * \param   testParams        structure to details of testcase to run.
 *
 * \return  None
 */
void dccRunTestcase(st_DCCTestcaseParams_t *testParams);

/**
 * \brief   Print main menu.
 *
 * \param   None.
 *
 * \return  None
 */
void st_dccShowMainMenu(void);

/**
 * \brief   Print main menu.
 *
 * \param   None.
 *
 * \return  None
 */
void st_dccShowMainMenu(void);

/**
 * \brief   Print DCC testcases.
 *
 * \return  None
 */
void st_dccPrintTCs(void);

/**
 * \brief   Print DCC testcase details.
 *
 * \return  None
 */
void st_dccPrintTCDetails(uint32_t testId);

/**
 * \brief   Initialize  DCC testcase details.
 *
 * \return  None
 */
void st_dccTCResultInit(void);

/**
 * \brief   Prints DCC Test Case Results.
 *
 * \return  None
 */
void st_dccPrintTCResults(void);

/**
 * \brief   Initializes board/UART
 */
static void DCCAppInitUart(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t dccParser(void)
{
    uint32_t numTCPass, numTCFail, totalTCRun, done = 0U;
    int32_t  testcaseIdx, testId;

    char option;
    st_DCCTestcaseParams_t *testParams;

    DCCAppInitUart();
    st_dccTCResultInit();

    numTCPass = 0U;
    numTCFail = 0U;
    totalTCRun = 0U;

    while(!done)
    {
        st_dccShowMainMenu();
        UART_printf("\nEnter your choice: ");
        UART_scanFmt("%c", &option);
        switch(option)
        {
            case '1':
                UART_printf("\nEnter testcase ID to run: ");
                UART_scanFmt("%d", &testId);
                testcaseIdx = dccGetTestcaseIdx(testId);
                if(testcaseIdx < 0)
                {
                    UART_printf("Invalid test case Id.");
                }
                else if(TEST_ENABLE == gDCCTestcaseParams[testcaseIdx].enableTest)
                {
                    testParams = &gDCCTestcaseParams[testcaseIdx];
                    totalTCRun++;
                    dccRunTestcase(testParams);
                    if(STW_SOK == testParams->testResult)
                    {
                        numTCPass++;
                    }
                    else
                    {
                        numTCFail++;
                    }
                }
                UART_printf("\nDCC: Total Testcases run:%u/%u\n",totalTCRun, (DCC_NUM_TESTCASES - 1U));
                UART_printf("DCC: Number of Testcases Passed:%u\n",numTCPass);
                UART_printf("DCC: Number of Testcases Failed:%u\n",numTCFail);
            break;
            case '2':
                for(testcaseIdx = 0;
                    testcaseIdx < DCC_NUM_TESTCASES;
                    testcaseIdx++)
                {
                    testParams = &gDCCTestcaseParams[testcaseIdx];
                    if(TEST_ENABLE == testParams->enableTest)
                    {
                        if(ST_TT_SANITY == (testParams->testType & ST_TT_SANITY))
                        {
                            totalTCRun++;
                            dccRunTestcase(testParams);
                            if(STW_SOK == testParams->testResult)
                            {
                                numTCPass++;
                            }
                            else
                            {
                                numTCFail++;
                            }
                        }
                    }
                }
                UART_printf("\nDCC: Total Testcases run:%u/%u\n",totalTCRun, (DCC_NUM_TESTCASES - 1U));
                UART_printf("DCC: Number of Testcases Passed:%u\n",numTCPass);
                UART_printf("DCC: Number of Testcases Failed:%u\n",numTCFail);
                st_dccPrintTCResults();
            break;
            case '3':
                for(testcaseIdx = 0;
                    testcaseIdx < DCC_NUM_TESTCASES;
                    testcaseIdx++)
                {
                    if(TEST_ENABLE == gDCCTestcaseParams[testcaseIdx].enableTest)
                    {
                        testParams = &gDCCTestcaseParams[testcaseIdx];
                        if(ST_TT_REGRESSION == (testParams->testType & ST_TT_REGRESSION))
                        {
                            totalTCRun++;
                            dccRunTestcase(testParams);
                            if(STW_SOK == testParams->testResult)
                            {
                                numTCPass++;
                            }
                            else
                            {
                                numTCFail++;
                            }
                        }
                    }
                }
                UART_printf("\nDCC: Total Testcases run:%d/%d\n",totalTCRun, (DCC_NUM_TESTCASES - 1U));
                UART_printf("DCC: Number of Testcases Passed:%d\n",numTCPass);
                UART_printf("DCC: Number of Testcases Failed:%d\n",numTCFail);
            break;
            case '4':
                for(testcaseIdx = 0;
                    testcaseIdx < DCC_NUM_TESTCASES;
                    testcaseIdx++)
                {
                    testParams = &gDCCTestcaseParams[testcaseIdx];
                    if(TEST_ENABLE == testParams->enableTest)
                    {
                        totalTCRun++;
                        dccRunTestcase(testParams);
                        if(STW_SOK == testParams->testResult)
                        {
                            numTCPass++;
                        }
                        else
                        {
                            numTCFail++;
                        }
                    }
                }
                UART_printf("\nDCC: Total Testcases run:%u/%u\n",totalTCRun, (DCC_NUM_TESTCASES - 1U));
                UART_printf("DCC: Number of Testcases Passed:%u\n",numTCPass);
                UART_printf("DCC: Number of Testcases Failed:%u\n",numTCFail);
                st_dccPrintTCResults();
            break;
            case 'd':
                st_dccPrintTCs();
            break;
            case 't':
                UART_printf("\nEnter testcase ID: ");
                UART_scanFmt("%d",&testId);
                testcaseIdx = dccGetTestcaseIdx(testId);
                if(testcaseIdx < 0)
                {
                    UART_printf("Invalid test case Id.");
                }
                else
                {
                    st_dccPrintTCDetails(testcaseIdx);
                }
            break;
            case 'g':
                st_dccPrintTCResults();
            break;
            case 'q':
                UART_printf("Exiting DCC UT.\n");
                done = 1;
            break;
        }
    }

    if(0U == numTCFail)
    {
        UART_printf("\nAll Test-cases have PASSED.\n");
    }
    else
    {
        UART_printf("\nSome of the Test-cases have FAILED.\n");
    }
    return 0;
}

int32_t dccGetTestcaseIdx(uint32_t testcaseId)
{
    int32_t testcaseIdx = -1;
    uint32_t testCnt;
    const st_DCCTestcaseParams_t *testParams;

    testParams = &gDCCTestcaseParams[0u];
    for(testCnt = 0 ; testCnt < DCC_NUM_TESTCASES ; testCnt++)
    {
        if (testParams[testCnt].testcaseId == testcaseId)
        {
            testcaseIdx = testCnt;
            break;
        }
    }
    return testcaseIdx;
}

void dccRunTestcase(st_DCCTestcaseParams_t *testParams)
{
    UART_printf("\n|TEST START|:: %u ::\n", testParams->testcaseId);
    UART_printf("|TEST PARAM|:: %s ::\n", testParams->testCaseName);

    UART_printf("Testcase Settings:\n");
    UART_printf("--------------------------------------------------------------\n");
    UART_printf("Module                                              :0x%x\n",
        testParams->dccConfigParams.dccModule);
    UART_printf("Clock Source for COUNT0                             :0x%x\n",
        testParams->dccConfigParams.dccClkSrc0);
    UART_printf("Clock Source for COUNT1                             :0x%x\n",
        testParams->dccConfigParams.dccClkSrc1);
    UART_printf("===============Running Single shot 1 mode ====================\n");
    testParams->dccMode = DCC_OPERATION_MODE_SINGLE_SHOT1;
    st_dccSingleShot_main(testParams);
    UART_printf("===============Running Single shot 2 mode ====================\n");
    testParams->dccMode = DCC_OPERATION_MODE_SINGLE_SHOT2;
    st_dccSingleShot_main(testParams);
    UART_printf("=================Running Continuous mode =====================\n");
    testParams->dccMode = DCC_OPERATION_MODE_CONTINUOUS;
    st_cont_main(testParams);
    testParams->isRun      = STW_SOK;
    UART_printf("\n======================== FINISHED ==========================\n");

    if(testParams->testResult == 0U)
        UART_printf("|TEST RESULT|PASS|%u|\n", testParams->testcaseId);
    else
        UART_printf("|TEST RESULT|FAIL|%u|\n", testParams->testcaseId);

    UART_printf("|TEST INFO|:: %s ::\n", testParams->testCaseName);
    UART_printf("|TEST END|:: %u ::\n", testParams->testcaseId);
}

void st_dccShowMainMenu(void)
{
    UART_printf("\n=============\n");
    UART_printf("DCC UT Select\n");
    UART_printf("=============\n");
    UART_printf("\nDCC UT main menu:\n");
    UART_printf("1: Manual testing (select specific test case to run)\n");
    UART_printf("2. Sanity testing.\n");
    UART_printf("3: Regression testing.\n");
    UART_printf("4: Full testing.\n");
    UART_printf("5: Performance testing.\n");
    UART_printf("d: Display test cases.\n");
    UART_printf("t: Display test case Details.\n");
    UART_printf("g: Generate test report.\n");
    UART_printf("q: Quit.\n");
}

void st_dccPrintTCs(void)
{
    uint32_t loopCnt;
    const st_DCCTestcaseParams_t *testParams;

    UART_printf("DCC Testcase:\n");
    UART_printf("--------------------------------------------------------------\n");
    UART_printf("TC Id\tTC name\n");
    UART_printf("--------------------------------------------------------------\n");
    for(loopCnt = 0 ; loopCnt < DCC_NUM_TESTCASES; loopCnt++)
    {
        testParams = &gDCCTestcaseParams[loopCnt];
        if (TEST_ENABLE == testParams->enableTest)
        {
            UART_printf("%d\t%s\n", testParams->testcaseId,testParams->testCaseName);
        }
    }
    UART_printf("--------------------------------------------------------------\n");
}

void st_dccPrintTCDetails(uint32_t testId)
{
    const st_DCCTestcaseParams_t *testParams;

    testParams = &gDCCTestcaseParams[testId];
    UART_printf("Testcase Id : %d\n", testParams->testcaseId);
    UART_printf("Testcase Name : %s", testParams->testCaseName);
    UART_printf("\nTestcase Enabled(0-Disabled/1-Enabled) : %d",
           testParams->enableTest);
    UART_printf("\nTestcase Disable Reason : %s", testParams->disableInfo);
    UART_printf("\nTestcase Type : %d", testParams->testType);
    UART_printf("\nTestcase Print Enable(0-Disabled/1-Enabled) : %d\n",
           testParams->printEnable);
}

void st_dccTCResultInit(void)
{
    uint32_t loopCnt;
    st_DCCTestcaseParams_t * testParams;

    for(loopCnt = 0 ; loopCnt < DCC_NUM_TESTCASES; loopCnt++)
    {
        testParams              = &gDCCTestcaseParams[loopCnt];
        testParams->isRun       = STW_EFAIL;
        testParams->testResult  = STW_EFAIL;
    }
}

void st_dccPrintTCResults(void)
{
    uint32_t loopCnt;
    int32_t  testcaseIdx;
    st_DCCTestcaseParams_t *testParams;
    char    *testResult;

    UART_printf(
        "-----------------------------------------------------------------------------------------------------------\r\n");
    UART_printf(
        "ID\t         Description\t\t\t                         Status\r\n");
    UART_printf(
        "-----------------------------------------------------------------------------------------------------------\r\n");
    for (loopCnt = 0; loopCnt < DCC_NUM_TESTCASES; loopCnt++)
    {
        testParams = &gDCCTestcaseParams[loopCnt];
        testcaseIdx = testParams->testcaseId;
        if (STW_SOK == testParams->testResult)
        {
            testResult = "PASS";
        }
        else if (STW_SOK == testParams->isRun)
        {
            testResult = "FAIL";
        }
        else
        {
            testResult = "NRQ";
        }
        UART_printf(
            "%d\t         %s\t                         %s\r\n",
            testcaseIdx, testParams->testCaseName, testResult);
    }

            UART_printf(
        "\n-----------------------------------------------------------------------------------------------------------\r\n");
}

static void DCCAppInitUart(void)
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

