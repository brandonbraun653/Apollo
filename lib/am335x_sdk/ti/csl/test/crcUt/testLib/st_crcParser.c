/*
 *  Copyright (C) 2019 Texas Instruments Incorporated
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
 *  \file st_crcParser.c
 *
 *  \brief User interface for CRCs driver testing.
 *
 *  This file takes the input from the user specified test file and
 *  then initiates the tests on CRC driver accordingly.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_crc.h>
#include <st_crcTestCases.h>

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
 * \brief   Get the index of the testcase to run from st_crcTestcases.h.
 *
 * \param   testcaseId        Testcase Id to run.
 *
 * \return  None
 */
static int32_t crcGetTestcaseIdx(uint32_t testcaseId);

/**
 * \brief   Print main menu.
 *
 * \param   None.
 *
 * \return  None
 */
static void st_crcShowMainMenu(void);

/**
 * \brief   Print CRC testcases.
 *
 * \return  None
 */
static void st_crcPrintTCs(void);

/**
 * \brief   Print CRC testcase details.
 *
 * \return  None
 */
static void st_crcPrintTCDetails(uint32_t testId);

/**
 * \brief   Initialize  CRC testcase details.
 *
 * \return  None
 */
static void st_crcTCResultInit(void);

/**
 * \brief   Prints CRC Test Case Results.
 *
 * \return  None
 */
static void st_crcPrintTCResults(void);

/**
 * \brief   Print messages on UART console.
 *
 * \param   None.
 *
 * \return  None
 */
static void st_crcUARTConfig(void);

#ifdef UNITY_INCLUDE_CONFIG_H
static  char st_crcGetAutoTestOption(char curOption);
#endif

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/**
 *  \brief global variable for holding data buffer of DDR.
 */
uint8_t gDdrCrcSrcBuffer[CRC_DDR_BUF_MAX_SIZE] __attribute__((aligned(128), section(".benchmark_buffer"))) = {1U};

/**
 *  \brief global variable for holding data buffer of MSMC.
 */
uint8_t gMsmcCrcSrcBuffer[CRC_MSMC_BUF_MAX_SIZE] __attribute__((aligned(128), section(".data"))) = {1U};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t crcParser(void)
{
    uint32_t numTCPass, numTCFail, totalTCRun, done = 0U;
    int32_t  testcaseIdx, testId;

    char option = '1';
    st_CRCTestcaseParams_t *testParams;

    st_crcUARTConfig();
    st_crcTCResultInit();

    /* Enable CRC clock. */
    st_crcClockEnable();
    st_crcSemiCPU_init();

    numTCPass  = 0U;
    numTCFail  = 0U;
    totalTCRun = 0U;

    while (!done)
    {
        st_crcShowMainMenu();
        UART_printf("\nEnter your choice: ");
#ifdef UNITY_INCLUDE_CONFIG_H
        option = st_crcGetAutoTestOption(option);
        UART_printf("%c \n", option);
#else
        UART_scanFmt("%c", &option);
#endif
        switch(option)
        {
            case '1':
                UART_printf("\nEnter testcase ID to run: ");
                UART_scanFmt("%d", &testId);
                testcaseIdx = crcGetTestcaseIdx(testId);
                if (testcaseIdx < 0)
                {
                    UART_printf("Invalid test case Id.");
                }
                else if(TEST_ENABLE == gCRCTestcaseParams[testcaseIdx].enableTest)
                {
                    testParams = &gCRCTestcaseParams[testcaseIdx];
                        totalTCRun++;
                        testParams->testCaseFxnPtr(testParams);
                        if (CSL_PASS == testParams->testResult)
                        {
                            numTCPass++;
                        }
                        else
                        {
                            numTCFail++;
                        }
                }
                UART_printf("\nCRC: Total Testcases run:%u/%u\n", totalTCRun, CRC_NUM_TESTCASES - 1U);
                UART_printf("CRC: Number of Testcases Passed:%u\n", numTCPass);
                UART_printf("CRC: Number of Testcases Failed:%u\n", numTCFail);
                break;
            case '2':
                for (testcaseIdx = 0;
                     testcaseIdx < CRC_NUM_TESTCASES;
                     testcaseIdx++)
                {
                    testParams = &gCRCTestcaseParams[testcaseIdx];
                    if(TEST_ENABLE == testParams->enableTest)
                    {
                        if(ST_TT_SANITY == (testParams->testType & ST_TT_SANITY))
                        {
                            totalTCRun++;
                            testParams->testCaseFxnPtr(testParams);
                            if(CSL_PASS == testParams->testResult)
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
                UART_printf("\nCRC: Total Testcases run:%u/%u\n", totalTCRun,
                           (CRC_NUM_TESTCASES - 1));
                UART_printf("CRC: Number of Testcases Passed:%u\n", numTCPass);
                UART_printf("CRC: Number of Testcases Failed:%u\n", numTCFail);
                st_crcPrintTCResults();
                break;
            case '3':
                for (testcaseIdx = 0;
                     testcaseIdx < CRC_NUM_TESTCASES;
                     testcaseIdx++)
                {
                    testParams = &gCRCTestcaseParams[testcaseIdx];
                    if(TEST_ENABLE == testParams->enableTest)
                    {
                        if (ST_TT_REGRESSION == (testParams->testType & ST_TT_REGRESSION))
                        {
                            totalTCRun++;
                            testParams->testCaseFxnPtr(testParams);
                            if (CSL_PASS == testParams->testResult)
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
                UART_printf("\nCRC: Total Testcases run:%d/%d\n", totalTCRun,
                           CRC_NUM_TESTCASES);
                UART_printf("CRC: Number of Testcases Passed:%d\n", numTCPass);
                UART_printf("CRC: Number of Testcases Failed:%d\n", numTCFail);
                break;
            case '4':
                for (testcaseIdx = 0;
                     testcaseIdx < CRC_NUM_TESTCASES;
                     testcaseIdx++)
                {
                    testParams = &gCRCTestcaseParams[testcaseIdx];
                    if (TEST_ENABLE == testParams->enableTest)
                    {
                        totalTCRun++;
                        testParams->testCaseFxnPtr(testParams);
                        if (CSL_PASS == testParams->testResult)
                        {
                            numTCPass++;
                        }
                        else
                        {
                            numTCFail++;
                        }
                    }
                }
                UART_printf("\nCRC: Total Testcases run:%u/%u\n", totalTCRun,
                           (CRC_NUM_TESTCASES - 1));
                UART_printf("CRC: Number of Testcases Passed:%u\n", numTCPass);
                UART_printf("CRC: Number of Testcases Failed:%u\n", numTCFail);
                st_crcPrintTCResults();
                break;
            case 'd':
                st_crcPrintTCs();
                break;
            case 't':
                UART_printf("\nEnter testcase ID: ");
                UART_scanFmt("%d",&testId);
                testcaseIdx = crcGetTestcaseIdx(testId);
                if (testcaseIdx < 0)
                {
                    UART_printf("Invalid test case Id.");
                }
                else
                {
                    st_crcPrintTCDetails(testcaseIdx);
                }
                break;
            case 'g':
                st_crcPrintTCResults();
                break;
            case 's':
                for (testcaseIdx = 0;
                     testcaseIdx < CRC_NUM_TESTCASES;
                     testcaseIdx++)
                {
                    testParams = &gCRCTestcaseParams[testcaseIdx];
                    if ((TEST_ENABLE == testParams->enableTest) &&
                        (testParams->testcaseId >= 8000U))
                    {
                        totalTCRun++;
                        testParams->testCaseFxnPtr(testParams);
                        if (CSL_PASS == testParams->testResult)
                        {
                            numTCPass++;
                        }
                        else
                        {
                            numTCFail++;
                        }
                    }
                }
                UART_printf("\nCRC: Total Testcases run:%u/%u\n", totalTCRun,
                           (CRC_NUM_TESTCASES - 1));
                UART_printf("CRC: Number of Testcases Passed:%u\n", numTCPass);
                UART_printf("CRC: Number of Testcases Failed:%u\n", numTCFail);
                if (totalTCRun == numTCPass)
                {
                    UART_printStatus("\r\n All tests have passed. \r\n");
#if defined (UNITY_INCLUDE_CONFIG_H)
                    TEST_PASS();
#endif
                }
                else
                {
                    UART_printStatus("\r\n Some tests have failed. \r\n");
#if defined (UNITY_INCLUDE_CONFIG_H)
                    TEST_FAIL();
#endif
                }
                break;
            case 'q':
                UART_printf("Exiting CRC UT.\n");
                done = 1;
                break;
        }
    }

    st_crcSemiCPU_deinit();

    if (0U == numTCFail)
    {
        UART_printf("\nAll Test-cases have PASSED.\n");
#if defined (UNITY_INCLUDE_CONFIG_H)
        TEST_PASS();
#endif
    }
    else
    {
        UART_printf("\nSome of the Test-cases have FAILED.\n");
#if defined (UNITY_INCLUDE_CONFIG_H)
        TEST_FAIL();
#endif
    }
    return 0;
}

static int32_t crcGetTestcaseIdx(uint32_t testcaseId)
{
    int32_t  testcaseIdx = -1;
    uint32_t testCnt;
    const st_CRCTestcaseParams_t *testParams;

    testParams = &gCRCTestcaseParams[0u];
    for (testCnt = 0; testCnt < CRC_NUM_TESTCASES; testCnt++)
    {
        if (testParams[testCnt].testcaseId == testcaseId)
        {
            testcaseIdx = testCnt;
            break;
        }
    }
    return testcaseIdx;
}

void crcRunTestcase(st_CRCTestcaseParams_t *testParams)
{
    UART_printf("\n|TEST START|:: %u ::\n", testParams->testcaseId);
    UART_printf("|TEST PARAM|:: %s ::\n", testParams->testCaseName);

    UART_printf("Testcase Settings:\n");
    UART_printf("-------------------------------------------------------------------\n");
    if (testParams->crcConfigParams.crcChannelNumber == 0U)
    {
        UART_printf("Channel                                                       :all channels\n");
    }
    else
    {
        UART_printf("Channel                                                       :%u\n",
                   testParams->crcConfigParams.crcChannelNumber);
    }
    UART_printf("Op Mode(0.Data Cap/1.Auto/2.SEMI CPU/3.Full CPU/4.Code Cover) :%u\n",
               testParams->crcConfigParams.crcMode);
    UART_printf("Pattern Size(in Bytes)                                        :%u\n",
               testParams->crcConfigParams.crcPatternSize);
    UART_printf("Source Memory                                                 :0x%x\n",
               testParams->sourceMemory);
    UART_printf("Data Size                                                     :%u\n",
               testParams->dataSize);
    UART_printf("======================RUNNING====================================\n");
    switch (testParams->crcConfigParams.crcMode)
    {
        case CRC_OPERATION_MODE_SEMICPU:
            st_crcSemiCPU_main(testParams);
            break;
        case CRC_OPERATION_MODE_FULLCPU:
            st_crcFullCPU_main(testParams);
            break;
        case CRC_OPERATION_MODE_DATA:
            st_crcData_main(testParams);
            break;
        default:
            st_crcCodeCover_main(testParams);
            break;
    }
    testParams->isRun = CSL_PASS;
    UART_printf("\n======================FINISHED==========================\n");
    if (testParams->testResult == 0U)
        UART_printf("|TEST RESULT|PASS|%u|\n", testParams->testcaseId);
    else
        UART_printf("|TEST RESULT|FAIL|%u|\n", testParams->testcaseId);

    UART_printf("|TEST INFO|:: %s ::\n", testParams->testCaseName);
    UART_printf("|TEST END|:: %u ::\n", testParams->testcaseId);
}

static void st_crcShowMainMenu(void)
{
    UART_printf("\n=============\n");
    UART_printf("CRC UT Select\n");
    UART_printf("=============\n");
    UART_printf("\nCRC UT main menu:\n");
    UART_printf("1: Manual testing (select specific test case to run)\n");
    UART_printf("2. Sanity testing.\n");
    UART_printf("3: Regression testing.\n");
    UART_printf("4: Full testing.\n");
    UART_printf("5: Performance testing.\n");
    UART_printf("s: Full v2 testing.\n");
    UART_printf("d: Display test cases.\n");
    UART_printf("t: Display test case Details.\n");
    UART_printf("g: Generate test report.\n");
    UART_printf("q: Quit.\n");
}

static void st_crcPrintTCs(void)
{
    uint32_t loopCnt;
    const st_CRCTestcaseParams_t *testParams;

    UART_printf("CRC Testcase:\n");
    UART_printf(
        "--------------------------------------------------------------\n");
    UART_printf("TC Id\tTC name\n");
    UART_printf(
        "--------------------------------------------------------------\n");
    for (loopCnt = 0; loopCnt < CRC_NUM_TESTCASES; loopCnt++)
    {
	    testParams = &gCRCTestcaseParams[loopCnt];
        if (TEST_ENABLE == testParams->enableTest)
        {
            UART_printf("%d\t%s\n", testParams->testcaseId,
                       testParams->testCaseName);
        }
    }
    UART_printf(
        "--------------------------------------------------------------\n");
}

static void st_crcPrintTCDetails(uint32_t testId)
{
    const st_CRCTestcaseParams_t *testParams;

    testParams = &gCRCTestcaseParams[testId];
    UART_printf("Testcase Id : %d\n", testParams->testcaseId);
    UART_printf("Testcase Name : %s", testParams->testCaseName);
    UART_printf("\nTestcase Enabled(0-Disabled/1-Enabled) : %d",
               testParams->enableTest);
    UART_printf("\nTestcase Disable Reason : %s", testParams->disableReason);
    UART_printf("\nTestcase Type : %d", testParams->testType);
    UART_printf("\nTestcase Print Enable(0-Disabled/1-Enabled) : %d\n",
               testParams->printEnable);
}

static void st_crcTCResultInit(void)
{
    uint32_t loopCnt;
    st_CRCTestcaseParams_t *testParams;

    for (loopCnt = 1; loopCnt < CRC_NUM_TESTCASES; loopCnt++)
    {
        testParams             = &gCRCTestcaseParams[loopCnt];
        testParams->isRun      = CSL_EFAIL;
        testParams->testResult = CSL_EFAIL;
    }
}

static void st_crcPrintTCResults(void)
{
    uint32_t loopCnt;
    int32_t  testcaseIdx;
    st_CRCTestcaseParams_t *testParams;
    char    *testResult;

    UART_printf(
        "-----------------------------------------------------------------------------------------------------------\r\n");
    UART_printf(
        "ID\t\t%60s%s\r\n", "Description", "status");
    UART_printf(
        "-----------------------------------------------------------------------------------------------------------\r\n");
    for (loopCnt = 0; loopCnt < CRC_NUM_TESTCASES; loopCnt++)
    {
        testParams  = &gCRCTestcaseParams[loopCnt];
        testcaseIdx = testParams->testcaseId;
        if (CSL_PASS == testParams->testResult)
        {
            testResult = "PASS";
        }
        else if (CSL_PASS == testParams->isRun)
        {
            testResult = "FAIL";
        }
        else
        {
            testResult = "NRQ";
        }
        UART_printf(
            "%d\t\t%60s%s\r\n",
            testcaseIdx, testParams->testCaseName, testResult);
    }

    UART_printf(
        "\n-----------------------------------------------------------------------------------------------------------\r\n");
}

void st_crcUARTConfig(void)
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

#ifdef UNITY_INCLUDE_CONFIG_H
static  char st_crcGetAutoTestOption(char curOption)
{
    char option;
    switch(curOption)
    {
        /* '1' : Manual testing option */ 
        case '1':
            option = '2';
            break;
        /* '2': Sanity Testing */
        case '2':
            option = '3';
            break;
        /* '3': Regression Testing */
        case '3':
            option = '4';
            break;
        /* '4': Full testing */
        case '4':
            option = 'd';
            break;
        /* 'd':  Display Test Cases */
        case 'd':
            option = 'g';
            break;
        /* 'g': Generate Test Report */
        case 'g':
            option = 's';
            break;
        /* 's': Full v2 testing */
        case 's':
        /* 'q': Quit the test */
        default:
            option = 'q';
            break;
    }

    return (option);
}
#endif


