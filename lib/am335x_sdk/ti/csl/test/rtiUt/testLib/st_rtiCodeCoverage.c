/*
 *   Copyright (c) 2019 Texas Instruments Incorporated
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
 *  \file     st_rtiCodeCoverage.c
 *
 *  \brief    This file contains RTI DWWD code coverage test code.
 *
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_rti.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define RTI_RTIDWD_INVALID_BASE_ADDR  (0U)
#define RTI_RTIDWD_INVALID_PRLD_VAL   (RTI_RTIDWDPRLD_DWDPRLD_MAX << 13U)
#define RTI_RTIDWD_PRELOAD_VAL1       (100U << 13U)
#define RTI_RTIDWD_PRELOAD_VAL2       (200U << 13U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static int32_t RTIDwwdWindowConfigAPITest(uint32_t baseAddr,
                            uint32_t dwwdReaction,
                            uint32_t dwwdPreloadVal,
                            uint32_t dwwdWindowSize);
static int32_t RTIDwwdCntrAPITest(uint32_t baseAddr);
static int32_t RTIDwwdStatusAPITest(uint32_t baseAddr);
static int32_t RTIDwwdReactionAPITest(uint32_t baseAddr);
static int32_t RTIDwwdTimeAPITest(uint32_t baseAddr);
static int32_t RTIDwwdNegTest(uint32_t baseAddr);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t st_rtiCodeCoverage_main(st_RTITestcaseParams_t *testParams)
{
    uint32_t baseAddr, rtiWindow_size, rtiPreload_value, rtiReaction;
    int32_t  retVal = CSL_PASS;
    rtiDwwdStaticRegs_t    staticRegs;

    /* Latch to Configure RTI parameters */
    baseAddr         = testParams->rtiConfigParams.rtiModule;
    rtiWindow_size   = testParams->rtiConfigParams.dwwdWindowSize;
    rtiReaction      = RTI_DWWD_REACTION_GENERATE_NMI;
    rtiPreload_value = testParams->rtiConfigParams.rtiTimeoutVal << 5u;


    /* Now Go through all the API tests to make sure the APIs have code coverage done */

    /* 1. DWWD window configure test */
    retVal = RTIDwwdWindowConfigAPITest(baseAddr, rtiReaction,
                                        rtiPreload_value,
                                        rtiWindow_size);
    /* Proceed to next API test */
    if (retVal == CSL_PASS)
    {
        retVal = RTIDwwdCntrAPITest(baseAddr);
    }

    /* Proceed to next API test */
    if (retVal == CSL_PASS)
    {
        retVal = RTIDwwdStatusAPITest(baseAddr);
    }

    if (retVal == CSL_PASS)
    {
        retVal = RTIDwwdReactionAPITest(baseAddr);
    }

    if (retVal == CSL_PASS)
    {
        retVal = RTIDwwdTimeAPITest(baseAddr);
    }

    if (retVal == CSL_PASS)
    {
        retVal = RTI_DWWDReadStaticRegs(baseAddr, &staticRegs);
    }

    if (retVal == CSL_PASS)
    {
        retVal = RTIDwwdNegTest(baseAddr);
    }

    return retVal;
}

static int32_t RTIDwwdWindowConfigAPITest(uint32_t baseAddr,
                            uint32_t dwwdReaction,
                            uint32_t dwwdPreloadVal,
                            uint32_t dwwdWindowSize)
{
    int32_t    testRes = CSL_EFAIL;
    int32_t    cslRet;
    uint32_t   invalidReaction   = (RTI_DWWD_REACTION_GENERATE_NMI + RTI_RTIDWWDRXNCTRL_DWWDRXN_RESET);
    uint32_t   invalidPreloadVal = RTI_RTIDWDPRLD_DWDPRLD_MAX << 13U;
    uint32_t   invalidWinSize    = (RTI_DWWD_WINDOWSIZE_3_125_PERCENT + RTI_DWWD_WINDOWSIZE_6_25_PERCENT);
    uint32_t   winSz;

    /* Check with null base addr invalid arguments and expect CSL_FAIL */
    cslRet = RTIDwwdWindowConfig(NULL, dwwdReaction,
                                    dwwdPreloadVal,
                                    dwwdWindowSize);
    if (cslRet == CSL_EFAIL)
    {
        /* Check with invalid reaction invalid arguments and expect CSL_FAIL */
        cslRet = RTIDwwdWindowConfig(baseAddr, invalidReaction,
                                            dwwdPreloadVal,
                                            dwwdWindowSize);

        if (cslRet == CSL_EFAIL)
        {
            /* Check with invalid preload value and expect failure */
            cslRet = RTIDwwdWindowConfig(baseAddr, dwwdReaction,
                                            invalidPreloadVal,
                                            dwwdWindowSize);

            if (cslRet == CSL_EFAIL)
            {
                /* Check with invalid window size invalid arguments and expect CSL_FAIL */
                cslRet = RTIDwwdWindowConfig(baseAddr, dwwdReaction,
                                                dwwdPreloadVal,
                                                invalidWinSize);
            }
        }
    }

    /* Get and Set API tets */
    if (cslRet == CSL_EFAIL) /* Value set to invalid Win Size attempt to set before */
    {
        cslRet = RTIDwwdGetWindowSize(baseAddr, &winSz);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = RTIDwwdSetWindowSize(baseAddr, winSz);
    }

    if (cslRet == CSL_PASS)
    {
        testRes = CSL_PASS;
    }
    /* No other test arguments are needed as other cases (valid args) are tested with other tests */

    /* Return the API test restuls */
    return (testRes);
}

static int32_t RTIDwwdCntrAPITest(uint32_t baseAddr)
{
    int32_t    testRes = CSL_EFAIL;
    int32_t    cslRet;
    uint32_t   cntrEnabled;

    /* Check with null base addr invalid arguments and expect CSL_FAIL */
    cslRet = RTIDwwdIsCounterEnabled(baseAddr, &cntrEnabled);

    if (cslRet == CSL_PASS) /* Expected results, try next test */
    {
         testRes = CSL_PASS;
    }

    /* No other test arguments are needed as other cases (valid args) are tested with other tests */
    /* Return the API test restuls */
    return (testRes);
}

static int32_t RTIDwwdStatusAPITest(uint32_t baseAddr)
{
    int32_t    testRes = CSL_EFAIL;
    int32_t    cslRet;
    uint32_t   lastResetStatus, dwwdStatus, keySeqStatus;

    /* Check with null base addr invalid arguments and expect CSL_FAIL */
    cslRet = RTIDwwdGetLastResetStatus(baseAddr, &lastResetStatus);

    if (cslRet == CSL_PASS)
    {
        cslRet = RTIDwwdGetStatus(baseAddr, &dwwdStatus);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = RTIDwwdClearStatus(baseAddr, dwwdStatus);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = RTIIsDwwdKeySequenceCorrect(baseAddr, &keySeqStatus);
    }

    if (cslRet == CSL_PASS) /* Expected results, try next test */
    {
         testRes = CSL_PASS;
    }

    /* No other test arguments are needed as other cases (valid args) are tested with other tests */
    /* Return the API test restuls */
    return (testRes);
}

static int32_t RTIDwwdReactionAPITest(uint32_t baseAddr)
{
    int32_t             testRes = CSL_PASS;
    int32_t             cslRet;
    rtiDwwdReaction_t   reaction;

    cslRet = RTIDwwdGetReaction(baseAddr, &reaction);
    if (cslRet != CSL_PASS) /* Expected results, try next test */
    {
         testRes = CSL_EFAIL;
    }
    else
    {
        cslRet = RTIDwwdSetReaction(baseAddr, reaction);
        if (cslRet != CSL_PASS)
        {
            testRes = CSL_EFAIL;
        }
    }
    return (testRes);
}

static int32_t RTIDwwdTimeAPITest(uint32_t baseAddr)
{
    int32_t    testRes = CSL_EFAIL;
    int32_t    cslRet;
    uint32_t   timeOut, clkTicks;

    cslRet = RTIDwwdGetTimeOut(baseAddr, &timeOut);

    if (cslRet == CSL_PASS)
    {
        cslRet = RTIDwwdGetTicksToOpenWindow(baseAddr, &clkTicks);
    }
    if (cslRet == CSL_PASS) /* Expected results, try next test */
    {
         testRes = CSL_PASS;
    }
    return (testRes);
}

static int32_t RTIDwwdNegTest(uint32_t baseAddr)
{
    int32_t             testStatus = CSL_EFAIL;
    rtiDwwdStaticRegs_t staticRegs;
    uint32_t            val;

    /* RTI_DWWDReadStaticRegs negtive test */
    if (RTI_DWWDReadStaticRegs(RTI_RTIDWD_INVALID_BASE_ADDR, &staticRegs) != CSL_EFAIL)
    {
        UART_printf("RTI_DWWDReadStaticRegs: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTI_DWWDReadStaticRegs(baseAddr, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("RTI_DWWDReadStaticRegs: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdWindowConfig negtive test */
    if (RTIDwwdWindowConfig(RTI_RTIDWD_INVALID_BASE_ADDR,
                            RTI_DWWD_REACTION_GENERATE_RESET,
                            RTI_RTIDWD_PRELOAD_VAL1,
                            RTI_DWWD_WINDOWSIZE_100_PERCENT) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdWindowConfig: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdWindowConfig(baseAddr,
                            RTI_RTIDWWDRXNCTRL_DWWDRXN_MASK,
                            RTI_RTIDWD_PRELOAD_VAL1,
                            RTI_DWWD_WINDOWSIZE_100_PERCENT) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdWindowConfig: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdWindowConfig(baseAddr,
                            RTI_DWWD_REACTION_GENERATE_RESET,
                            RTI_RTIDWD_INVALID_PRLD_VAL,
                            RTI_DWWD_WINDOWSIZE_100_PERCENT) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdWindowConfig: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdWindowConfig(baseAddr,
                            RTI_DWWD_REACTION_GENERATE_RESET,
                            RTI_RTIDWD_PRELOAD_VAL1,
                            RTI_RTIDWWDSIZECTRL_DWWDSIZE_MASK) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdWindowConfig: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdWindowVerifyConfig negtive test */
    if (RTIDwwdWindowVerifyConfig(RTI_RTIDWD_INVALID_BASE_ADDR,
                                  RTI_DWWD_REACTION_GENERATE_RESET,
                                  RTI_RTIDWD_PRELOAD_VAL1,
                                  RTI_DWWD_WINDOWSIZE_100_PERCENT) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdWindowVerifyConfig: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdWindowVerifyConfig(baseAddr,
                                  RTI_RTIDWWDRXNCTRL_DWWDRXN_MASK,
                                  RTI_RTIDWD_PRELOAD_VAL1,
                                  RTI_DWWD_WINDOWSIZE_100_PERCENT) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdWindowVerifyConfig: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    if (RTIDwwdWindowConfig(baseAddr,
                            RTI_DWWD_REACTION_GENERATE_RESET,
                            RTI_RTIDWD_PRELOAD_VAL1,
                            RTI_DWWD_WINDOWSIZE_100_PERCENT) != CSL_PASS)
    {
        UART_printf("RTIDwwdWindowConfig: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdWindowVerifyConfig(baseAddr,
                                  RTI_DWWD_REACTION_GENERATE_NMI,
                                  RTI_RTIDWD_PRELOAD_VAL1,
                                  RTI_DWWD_WINDOWSIZE_100_PERCENT) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdWindowVerifyConfig: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdWindowVerifyConfig(baseAddr,
                                  RTI_DWWD_REACTION_GENERATE_RESET,
                                  RTI_RTIDWD_PRELOAD_VAL2,
                                  RTI_DWWD_WINDOWSIZE_100_PERCENT) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdWindowVerifyConfig: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdWindowVerifyConfig(baseAddr,
                                  RTI_DWWD_REACTION_GENERATE_RESET,
                                  RTI_RTIDWD_PRELOAD_VAL1,
                                  RTI_DWWD_WINDOWSIZE_50_PERCENT) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdWindowVerifyConfig: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdCounterEnable negtive test */
    if (RTIDwwdCounterEnable(RTI_RTIDWD_INVALID_BASE_ADDR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdCounterEnable: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdIsCounterEnabled negtive test */
    if (RTIDwwdIsCounterEnabled(RTI_RTIDWD_INVALID_BASE_ADDR, &val) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdIsCounterEnabled: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdIsCounterEnabled(baseAddr, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdIsCounterEnabled: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdService negtive test */
    if (RTIDwwdService(RTI_RTIDWD_INVALID_BASE_ADDR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdService: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdGetLastResetStatus negtive test */
    if (RTIDwwdGetLastResetStatus(RTI_RTIDWD_INVALID_BASE_ADDR, &val) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetLastResetStatus: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdGetLastResetStatus(baseAddr, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetLastResetStatus: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdSetPreload negtive test */
    if (RTIDwwdSetPreload(RTI_RTIDWD_INVALID_BASE_ADDR, RTI_RTIDWD_PRELOAD_VAL1) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdSetPreload: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdSetPreload(baseAddr, RTI_RTIDWD_INVALID_PRLD_VAL) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdSetPreload: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdSetReaction negtive test */
    if (RTIDwwdSetReaction(RTI_RTIDWD_INVALID_BASE_ADDR,
                           RTI_DWWD_REACTION_GENERATE_RESET) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdSetReaction: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdSetWindowSize negtive test */
    if (RTIDwwdSetWindowSize(RTI_RTIDWD_INVALID_BASE_ADDR,
                             RTI_DWWD_WINDOWSIZE_100_PERCENT) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdSetWindowSize: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdIsClosedWindow negtive test */
    if (RTIDwwdIsClosedWindow(RTI_RTIDWD_INVALID_BASE_ADDR,
                              &val) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdIsClosedWindow: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdIsClosedWindow(baseAddr,
                              NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdIsClosedWindow: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdGenerateSysReset negtive test */
    if (RTIDwwdGenerateSysReset(RTI_RTIDWD_INVALID_BASE_ADDR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGenerateSysReset: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdGetStatus negtive test */
    if (RTIDwwdGetStatus(RTI_RTIDWD_INVALID_BASE_ADDR, &val) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetStatus: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdGetStatus(baseAddr, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetStatus: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdClearStatus negtive test */
    if (RTIDwwdClearStatus(RTI_RTIDWD_INVALID_BASE_ADDR,
                           RTI_RTIWDSTATUS_AWDST_MASK) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdClearStatus: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdGetCurrentDownCounter negtive test */
    if (RTIDwwdGetCurrentDownCounter(RTI_RTIDWD_INVALID_BASE_ADDR,
                                     &val) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetCurrentDownCounter: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdGetCurrentDownCounter(baseAddr, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetCurrentDownCounter: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIIsDwwdKeySequenceCorrect negtive test */
    if (RTIIsDwwdKeySequenceCorrect(RTI_RTIDWD_INVALID_BASE_ADDR,
                                    &val) != CSL_EFAIL)
    {
        UART_printf("RTIIsDwwdKeySequenceCorrect: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIIsDwwdKeySequenceCorrect(baseAddr, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("RTIIsDwwdKeySequenceCorrect: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdGetPreload negtive test */
    if (RTIDwwdGetPreload(RTI_RTIDWD_INVALID_BASE_ADDR,
                          &val) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetPreload: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdGetPreload(baseAddr, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetPreload: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdGetWindowSize negtive test */
    if (RTIDwwdGetWindowSize(RTI_RTIDWD_INVALID_BASE_ADDR,
                             &val) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetWindowSize: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdGetWindowSize(baseAddr, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetWindowSize: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdGetTimeOut negtive test */
    if (RTIDwwdGetTimeOut(RTI_RTIDWD_INVALID_BASE_ADDR,
                          &val) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetTimeOut: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdGetTimeOut(baseAddr, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetTimeOut: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdGetTicksToOpenWindow negtive test */
    if (RTIDwwdGetTicksToOpenWindow(RTI_RTIDWD_INVALID_BASE_ADDR,
                                    &val) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetTicksToOpenWindow: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdGetTicksToOpenWindow(baseAddr, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetTicksToOpenWindow: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* RTIDwwdGetReaction negtive test */
    if (RTIDwwdGetReaction(RTI_RTIDWD_INVALID_BASE_ADDR,
                           &val) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetReaction: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (RTIDwwdGetReaction(baseAddr, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("RTIDwwdGetReaction: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    testStatus = CSL_PASS;
    UART_printf("\n RTI Negatove Test : pass \n");

    return (testStatus);

}

/********************************* End of file ******************************/
