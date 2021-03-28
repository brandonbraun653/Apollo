/* Copyright (c) Texas Instruments Incorporated 2019
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
 *  \file     core_r5_ratTest.c
 *
 *  \brief    This file contains rat API test code for R5 core.
 *
 *  \details  RAT read/write and configuration tests
 **/

/*===========================================================================*/
/*                         Include files                                     */
/*===========================================================================*/
#include <core_r5_test.h>
#include <ti/csl/csl_rat.h>

/*===========================================================================*/
/*                         Declarations                                      */
/*===========================================================================*/


/*===========================================================================*/
/*                         Macros                                            */
/*===========================================================================*/

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

/*===========================================================================*/
/*                         Global Variables                                  */
/*===========================================================================*/

/*===========================================================================*/
/*                   Local Function definitions                              */
/*===========================================================================*/

static int32_t cslcore_r5_ratNegTest(CSL_ratRegs *pRatRegs)
{
    int32_t                   testStatus = CSL_APP_TEST_FAILED;
    uint32_t                  val;
    CSL_RatExceptionInfo      exceptionInfo;
    CSL_RatTranslationCfgInfo translationCfg;

    /* CSL_ratGetRevision negtive test */
    if (CSL_ratGetRevision(NULL_PTR) != 0U)
    {
        UART_printf("CSL_ratGetRevision: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratGetMaxRegions negtive test */
    if (CSL_ratGetMaxRegions(NULL_PTR) != 0U)
    {
        UART_printf("CSL_ratGetMaxRegions: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratIsRegionTranslationEnabled negtive test */
    if (CSL_ratIsRegionTranslationEnabled(NULL_PTR, 0U) != false)
    {
        UART_printf("CSL_ratIsRegionTranslationEnabled: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratIsRegionTranslationEnabled(pRatRegs, CSL_ratGetMaxRegions(pRatRegs) + 1U) != false)
    {
        UART_printf("CSL_ratIsRegionTranslationEnabled: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratSetErrMsgDestId negtive test */
    if (CSL_ratSetErrMsgDestId(NULL_PTR, 0U) != CSL_EFAIL)
    {
        UART_printf("CSL_ratSetErrMsgDestId: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratSetErrMsgDestId(pRatRegs, CSL_RAT_DESTINATION_ID_DEST_ID_MAX + 1U) != CSL_EFAIL)
    {
        UART_printf("CSL_ratSetErrMsgDestId: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratGetErrMsgDestId negtive test */
    if (CSL_ratGetErrMsgDestId(NULL_PTR, &val) != CSL_EFAIL)
    {
        UART_printf("CSL_ratGetErrMsgDestId: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratGetErrMsgDestId(pRatRegs, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("CSL_ratGetErrMsgDestId: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratEnableExceptionLogging negtive test */
    if (CSL_ratEnableExceptionLogging(NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("CSL_ratEnableExceptionLogging: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratDisableExceptionLogging negtive test */
    if (CSL_ratDisableExceptionLogging(NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("CSL_ratDisableExceptionLogging: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratIsIntrPending negtive test */
    if (CSL_ratIsIntrPending(NULL_PTR, CSL_RAT_INTR_SRC_EXCEPTION) != false)
    {
        UART_printf("CSL_ratIsIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratIsIntrPending(pRatRegs, CSL_RAT_INTR_SRC_INVALID) != false)
    {
        UART_printf("CSL_ratIsIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratSetIntrPending negtive test */
    if (CSL_ratSetIntrPending(NULL_PTR, CSL_RAT_INTR_SRC_EXCEPTION) != false)
    {
        UART_printf("CSL_ratSetIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratSetIntrPending(pRatRegs, CSL_RAT_INTR_SRC_INVALID) != false)
    {
        UART_printf("CSL_ratSetIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratClrIntrPending negtive test */
    if (CSL_ratClrIntrPending(NULL_PTR, CSL_RAT_INTR_SRC_EXCEPTION) != false)
    {
        UART_printf("CSL_ratClrIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratClrIntrPending(pRatRegs, CSL_RAT_INTR_SRC_INVALID) != false)
    {
        UART_printf("CSL_ratClrIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratAckIntr negtive test */
    if (CSL_ratAckIntr(NULL_PTR, CSL_RAT_INTR_SRC_EXCEPTION) != false)
    {
        UART_printf("CSL_ratAckIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratAckIntr(pRatRegs, CSL_RAT_INTR_SRC_INVALID) != false)
    {
        UART_printf("CSL_ratAckIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratEnableIntr negtive test */
    if (CSL_ratEnableIntr(NULL_PTR, CSL_RAT_INTR_SRC_EXCEPTION) != false)
    {
        UART_printf("CSL_ratEnableIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratEnableIntr(pRatRegs, CSL_RAT_INTR_SRC_INVALID) != false)
    {
        UART_printf("CSL_ratEnableIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratDisableIntr negtive test */
    if (CSL_ratDisableIntr(NULL_PTR, CSL_RAT_INTR_SRC_EXCEPTION) != false)
    {
        UART_printf("CSL_ratDisableIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratDisableIntr(pRatRegs, CSL_RAT_INTR_SRC_INVALID) != false)
    {
        UART_printf("CSL_ratDisableIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratGetExceptionInfo negtive test */
    if (CSL_ratGetExceptionInfo(NULL_PTR, &exceptionInfo) != false)
    {
        UART_printf("CSL_ratGetExceptionInfo: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratGetExceptionInfo(pRatRegs, NULL_PTR) != false)
    {
        UART_printf("CSL_ratGetExceptionInfo: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratEnableRegionTranslation negtive test */
    if (CSL_ratEnableRegionTranslation(NULL_PTR, 0U) != false)
    {
        UART_printf("CSL_ratEnableRegionTranslation: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratEnableRegionTranslation(pRatRegs, CSL_ratGetMaxRegions(pRatRegs) + 1U) != false)
    {
        UART_printf("CSL_ratEnableRegionTranslation: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratDisableRegionTranslation negtive test */
    if (CSL_ratDisableRegionTranslation(NULL_PTR, 0U) != false)
    {
        UART_printf("CSL_ratDisableRegionTranslation: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratDisableRegionTranslation(pRatRegs, CSL_ratGetMaxRegions(pRatRegs) + 1U) != false)
    {
        UART_printf("CSL_ratDisableRegionTranslation: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratConfigRegionTranslation negtive test */
    if (CSL_ratConfigRegionTranslation(NULL_PTR, 0U, &translationCfg) != false)
    {
        UART_printf("CSL_ratConfigRegionTranslation: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratConfigRegionTranslation(pRatRegs, CSL_ratGetMaxRegions(pRatRegs) + 1U, &translationCfg) != false)
    {
        UART_printf("CSL_ratConfigRegionTranslation: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratConfigRegionTranslation(pRatRegs, 0U, NULL_PTR) != false)
    {
        UART_printf("CSL_ratConfigRegionTranslation: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_ratVerifyConfigRegionTranslation negtive test */
    if (CSL_ratVerifyConfigRegionTranslation(NULL_PTR, 0U, &translationCfg) != CSL_EFAIL)
    {
        UART_printf("CSL_ratVerifyConfigRegionTranslation: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratVerifyConfigRegionTranslation(pRatRegs, CSL_ratGetMaxRegions(pRatRegs) + 1U, &translationCfg) != CSL_EFAIL)
    {
        UART_printf("CSL_ratVerifyConfigRegionTranslation: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_ratVerifyConfigRegionTranslation(pRatRegs, 0U, NULL_PTR) != CSL_EFAIL)
    {
        UART_printf("CSL_ratVerifyConfigRegionTranslation: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    UART_printf("CSL Core R5 RAT Negative Test Passed\n");

    testStatus = CSL_APP_TEST_PASS;
    return testStatus;
}

/*===========================================================================*/
/*                        Test Function definitions                          */
/*===========================================================================*/

/* PRSDK-1673: This test demonstrates the APIs to enable RAT
 */
 
int32_t cslcore_r5_ratTest(void)
{
    /* Declarations of variables */
    CSL_RatExceptionInfo  ratExceptionInfo;
    int32_t    testResult = CSL_APP_TEST_PASS;
    CSL_ratRegs *pRatRegs = (CSL_ratRegs *)CSL_MCU_RAT_CFG_BASE;
    uint32_t    rev, regionIndex = 0;
    uint32_t    maxRegions, destId, status;
    bool        bIsEnabled, isIntrPend, isSuccess;

    /* All RAT API tests - not functionality test */
    rev = CSL_ratGetRevision(pRatRegs);
    cslApp_print("RAT revision is: ");
    cslApp_printArg(rev);
    cslApp_print(" \n ");

    maxRegions = CSL_ratGetMaxRegions(pRatRegs);
    cslApp_print("RAT max regions is: ");
    cslApp_printArg(maxRegions);
    cslApp_print(" \n ");

    bIsEnabled = CSL_ratIsRegionTranslationEnabled(pRatRegs,regionIndex);
    cslApp_print("RAT region 0 translation enabled status (0: disabled, 1: enabled): ");
    cslApp_printArg(bIsEnabled);
    cslApp_print(" \n ");

    CSL_ratSetErrMsgDestId(pRatRegs,0u);
    cslApp_print("RAT setting destination ID: ");
    cslApp_print(" \n ");

    CSL_ratGetErrMsgDestId(pRatRegs, &destId);
    cslApp_print("RAT Error Message ID value is: ");
    cslApp_printArg(destId);
    cslApp_print(" \n ");

    CSL_ratEnableExceptionLogging(pRatRegs);
    cslApp_print("RAT Enabling exception logging");
    cslApp_print(" \n ");

    status = CSL_ratIsExceptionLoggingEnabled(pRatRegs);
    cslApp_print("RAT Exception Logging - Is enabled? : ");
    cslApp_printArg(status);
    cslApp_print(" \n ");

    CSL_ratDisableExceptionLogging(pRatRegs);
    cslApp_print("RAT Enabling exception logging");
    cslApp_print(" \n ");

    status = CSL_ratIsExceptionLoggingEnabled(pRatRegs);
    cslApp_print("RAT Exception Logging - Is enabled? : ");
    cslApp_printArg(status);
    cslApp_print(" \n ");

    isIntrPend = CSL_ratIsIntrPending(pRatRegs, CSL_RAT_INTR_SRC_EXCEPTION);
    cslApp_print("RAT is INTR pending for CSL_RAT_INTR_SRC_EXCEPTION: ");
    cslApp_printArg(isIntrPend);
    cslApp_print(" \n ");

    isSuccess = CSL_ratSetIntrPending(pRatRegs, CSL_RAT_INTR_SRC_EXCEPTION);
    cslApp_print("RAT set INTR pending for CSL_RAT_INTR_SRC_EXCEPTION: ");
    cslApp_printArg(isSuccess);
    cslApp_print(" \n ");

    if (isSuccess != true)
    {
         testResult = CSL_APP_TEST_FAILED;
    }

    if (testResult == CSL_APP_TEST_PASS)
    {
        isSuccess = CSL_ratClrIntrPending(pRatRegs, CSL_RAT_INTR_SRC_EXCEPTION);
        cslApp_print("RAT clr INTR pending for CSL_RAT_INTR_SRC_EXCEPTION: ");
        cslApp_printArg(isSuccess);
        cslApp_print(" \n ");
    }

    if (isSuccess != true)
    {
         testResult = CSL_APP_TEST_FAILED;
    }

    if (testResult == CSL_APP_TEST_PASS)
    {
        isSuccess = CSL_ratGetExceptionInfo(pRatRegs, &ratExceptionInfo);
        cslApp_print("RAT clr INTR pending for CSL_RAT_INTR_SRC_EXCEPTION: ");
        cslApp_printArg(isSuccess);
        cslApp_print(" \n ");
        if (isSuccess != true)
        {
             testResult = CSL_APP_TEST_FAILED;
        }
    }

    if (testResult == CSL_APP_TEST_PASS)
    {
        testResult = cslcore_r5_ratNegTest(pRatRegs);
    }

   return (testResult);
}


/* Nothing past this point */
