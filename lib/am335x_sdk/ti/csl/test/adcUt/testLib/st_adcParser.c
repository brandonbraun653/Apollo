/*
 *  Copyright (c) Texas Instruments Incorporated 2019
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
 *  \file st_adcParser.c
 *
 *  \brief User interface for ADCs driver testing.
 *
 *  This file takes the input from the user specified test file and
 *  then initiates the tests on ADC driver accordingly.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_adc.h>
#include <st_adcTestCases.h>

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
 * \brief   Get the index of the testcase to run from st_adcTestcases.h.
 *
 * \param   testcaseId        Testcase Id to run.
 *
 * \return  None
 */
int32_t adcGetTestcaseIdx(uint32_t testcaseId);

/**
 * \brief   Fetch testcase data and run the testcase.
 *
 * \param   testParams        structure to details of testcase to run.
 *
 * \return  None
 */
void adcRunTestcase(st_ADCTestcaseParams_t *testParams);

/**
 * \brief   Print main menu.
 *
 * \param   None.
 *
 * \return  None
 */
void st_adcShowMainMenu(void);

/**
 * \brief   Print ADC testcases.
 *
 * \return  None
 */
void st_adcPrintTCs(void);

/**
 * \brief   Print ADC testcase details.
 *
 * \return  None
 */
void st_adcPrintTCDetails(uint32_t testId);

/**
 * \brief   Initialize  ADC testcase details.
 *
 * \return  None
 */
void st_adcTCResultInit(void);

/**
 * \brief   Prints ADC Test Case Results.
 *
 * \return  None
 */
void st_adcPrintTCResults(void);

/**
 * \brief   Initializes board/UART
 */
static void ADCAppInitUart(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t adcParser(void)
{
    uint32_t numTCPass, numTCFail, totalTCRun, done = 0U;
    int32_t  testcaseIdx, testId;

    char option;
    st_ADCTestcaseParams_t *testParams;

    ADCAppInitUart();
    st_adcTCResultInit();
    st_adcDmaInit();

    numTCPass = 0U;
    numTCFail = 0U;
    totalTCRun = 0U;

    while(!done)
    {
        st_adcShowMainMenu();
        UART_printf("\nEnter your choice: ");
        UART_scanFmt("%c", &option);
        switch(option)
        {
            case '1':
                UART_printf("\nEnter testcase ID to run: ");
                UART_scanFmt("%d", &testId);
                testcaseIdx = adcGetTestcaseIdx(testId);
                if(testcaseIdx < 0)
                {
                    UART_printf("Invalid test case Id.");
                }
                else if(TEST_ENABLE == gADCTestcaseParams[testcaseIdx].enableTest)
                {
                    testParams = &gADCTestcaseParams[testcaseIdx];
                    adcRunTestcase(testParams);
                    if (testParams->isRun != STW_SOK)
                    {
                        testParams->isRun = STW_SOK;
                        totalTCRun++;
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
                UART_printf("\nADC: Total Testcases run:%u/%u\n",totalTCRun, ADC_NUM_TESTCASES);
                UART_printf("ADC: Number of Testcases Passed:%u\n",numTCPass);
                UART_printf("ADC: Number of Testcases Failed:%u\n",numTCFail);
            break;
            case '2':
                for(testcaseIdx = 0;
                    testcaseIdx < ADC_NUM_TESTCASES;
                    testcaseIdx++)
                {
                    testParams = &gADCTestcaseParams[testcaseIdx];
                    if(TEST_ENABLE == testParams->enableTest)
                    {
                        if(ST_TT_SANITY == (testParams->testType & ST_TT_SANITY))
                        {
                            adcRunTestcase(testParams);
                            if (testParams->isRun != STW_SOK)
                            {
                                testParams->isRun = STW_SOK;
                                totalTCRun++;
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
                }
                UART_printf("\nADC: Total Testcases run:%u/%u\n",totalTCRun, ADC_NUM_TESTCASES);
                UART_printf("ADC: Number of Testcases Passed:%u\n",numTCPass);
                UART_printf("ADC: Number of Testcases Failed:%u\n",numTCFail);
                st_adcPrintTCResults();
            break;
            case '3':
                for(testcaseIdx = 0;
                    testcaseIdx < ADC_NUM_TESTCASES;
                    testcaseIdx++)
                {
                    if(TEST_ENABLE == gADCTestcaseParams[testcaseIdx].enableTest)
                    {
                        testParams = &gADCTestcaseParams[testcaseIdx];
                        if(ST_TT_REGRESSION == (testParams->testType & ST_TT_REGRESSION))
                        {
                            adcRunTestcase(testParams);
                            if (testParams->isRun != STW_SOK)
                            {
                                testParams->isRun = STW_SOK;
                                totalTCRun++;
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
                }
                UART_printf("\nADC: Total Testcases run:%d/%d\n",totalTCRun, ADC_NUM_TESTCASES);
                UART_printf("ADC: Number of Testcases Passed:%d\n",numTCPass);
                UART_printf("ADC: Number of Testcases Failed:%d\n",numTCFail);
            break;
            case '4':
                for(testcaseIdx = 0;
                    testcaseIdx < ADC_NUM_TESTCASES;
                    testcaseIdx++)
                {
                    testParams = &gADCTestcaseParams[testcaseIdx];
                    if(TEST_ENABLE == testParams->enableTest)
                    {
                        adcRunTestcase(testParams);
                        if (testParams->isRun != STW_SOK)
                        {
                            testParams->isRun = STW_SOK;
                            totalTCRun++;
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
                UART_printf("\nADC: Total Testcases run:%u/%u\n",totalTCRun, ADC_NUM_TESTCASES);
                UART_printf("ADC: Number of Testcases Passed:%u\n",numTCPass);
                UART_printf("ADC: Number of Testcases Failed:%u\n",numTCFail);
                st_adcPrintTCResults();
            break;
            case 'd':
                st_adcPrintTCs();
            break;
            case 't':
                UART_printf("\nEnter testcase ID: ");
                UART_scanFmt("%d",&testId);
                testcaseIdx = adcGetTestcaseIdx(testId);
                if(testcaseIdx < 0)
                {
                    UART_printf("Invalid test case Id.");
                }
                else
                {
                    st_adcPrintTCDetails(testcaseIdx);
                }
            break;
            case 'g':
                st_adcPrintTCResults();
            break;
            case 'q':
                UART_printf("Exiting ADC UT.\n");
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
    st_adcDmaDeinit();
    return 0;
}

int32_t adcGetTestcaseIdx(uint32_t testcaseId)
{
    int32_t testcaseIdx = -1;
    uint32_t testCnt;
    const st_ADCTestcaseParams_t *testParams;

    testParams = &gADCTestcaseParams[0u];
    for(testCnt = 0 ; testCnt < ADC_NUM_TESTCASES ; testCnt++)
    {
        if (testParams[testCnt].testcaseId == testcaseId)
        {
            testcaseIdx = testCnt;
            break;
        }
    }
    return testcaseIdx;
}

void adcRunTestcase(st_ADCTestcaseParams_t *testParams)
{
    UART_printf("\n|TEST START|:: %u ::\n", testParams->testcaseId);
    UART_printf("|TEST PARAM|:: %s ::\n", testParams->testCaseName);

    UART_printf("Testcase Settings:\n");
    UART_printf("--------------------------------------------------------------\n");
    UART_printf("Module                                              :0x%x\n",
        testParams->adcConfigParams.adcModule);

    if (testParams->adcConfigParams.testMode == ADC_TEST_MODE_CPU)
    {
        st_adcCpuMode_main(testParams);
    }
    else
    {
        st_adcDmaMode_main(testParams);
    }
    UART_printf("\n======================== FINISHED ==========================\n");

    if(testParams->testResult == 0U)
        UART_printf("|TEST RESULT|PASS|%u|\n", testParams->testcaseId);
    else
        UART_printf("|TEST RESULT|FAIL|%u|\n", testParams->testcaseId);

    UART_printf("|TEST INFO|:: %s ::\n", testParams->testCaseName);
    UART_printf("|TEST END|:: %u ::\n", testParams->testcaseId);
}

void st_adcShowMainMenu(void)
{
    UART_printf("\n=============\n");
    UART_printf("ADC UT Select\n");
    UART_printf("=============\n");
    UART_printf("\nADC UT main menu:\n");
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

void st_adcPrintTCs(void)
{
    uint32_t loopCnt;
    const st_ADCTestcaseParams_t *testParams;

    UART_printf("ADC Testcase:\n");
    UART_printf("--------------------------------------------------------------\n");
    UART_printf("TC Id\tTC name\n");
    UART_printf("--------------------------------------------------------------\n");
    for(loopCnt = 0 ; loopCnt < ADC_NUM_TESTCASES; loopCnt++)
    {
        testParams = &gADCTestcaseParams[loopCnt];
        if (TEST_ENABLE == testParams->enableTest)
        {
            UART_printf("%d\t%s\n", testParams->testcaseId,testParams->testCaseName);
        }
    }
    UART_printf("--------------------------------------------------------------\n");
}

void st_adcPrintTCDetails(uint32_t testId)
{
    const st_ADCTestcaseParams_t *testParams;

    testParams = &gADCTestcaseParams[testId];
    UART_printf("Testcase Id : %d\n", testParams->testcaseId);
    UART_printf("Testcase Name : %s", testParams->testCaseName);
    UART_printf("\nTestcase Enabled(0-Disabled/1-Enabled) : %d",
           testParams->enableTest);
    UART_printf("\nTestcase Disable Reason : %s", testParams->disableInfo);
    UART_printf("\nTestcase Type : %d", testParams->testType);
}

void st_adcTCResultInit(void)
{
    uint32_t loopCnt;
    st_ADCTestcaseParams_t * testParams;

    for(loopCnt = 0 ; loopCnt < ADC_NUM_TESTCASES; loopCnt++)
    {
        testParams              = &gADCTestcaseParams[loopCnt];
        testParams->isRun       = STW_EFAIL;
        testParams->testResult  = STW_EFAIL;
    }
}

void st_adcPrintTCResults(void)
{
    uint32_t loopCnt;
    int32_t  testcaseIdx;
    st_ADCTestcaseParams_t *testParams;
    char    *testResult;

    UART_printf(
        "-----------------------------------------------------------------------------------------------------------\r\n");
    UART_printf(
        "ID\t         Description\t\t\t                         Status\r\n");
    UART_printf(
        "-----------------------------------------------------------------------------------------------------------\r\n");
    for (loopCnt = 0; loopCnt < ADC_NUM_TESTCASES; loopCnt++)
    {
        testParams = &gADCTestcaseParams[loopCnt];
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

static void ADCAppInitUart(void)
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
