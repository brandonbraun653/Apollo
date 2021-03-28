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
 *  \file     lbist_test_err.c
 *
 *  \brief    This file contains LBIST module error tests.
 *
 *  \details  LBIST Error tests
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/csl_types.h>
#include <ti/csl/csl_lbist.h>
#include <ti/drv/uart/UART_stdio.h>

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

static int32_t LBIST_errNegativeTest(void)
{
    int32_t testResult = 0;
    int32_t cslRet;

    /* Call CSL API */
    cslRet = CSL_LBIST_enableIsolation(NULL);
    if (cslRet == CSL_PASS)
    {
        UART_printf("\n  CSL_LBIST_enableIsolation negative test failed \n");
        testResult = -1;
    }

    if (testResult == 0)
    {
        cslRet = CSL_LBIST_disableIsolation(NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_LBIST_disableIsolation negative test failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        cslRet = CSL_LBIST_reset(NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_LBIST_reset negative test failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        cslRet = CSL_LBIST_enableRunBISTMode(NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_LBIST_enableRunBISTMode negative test failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        cslRet = CSL_LBIST_clearRunBISTMode(NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_LBIST_clearRunBISTMode negative test failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        cslRet = CSL_LBIST_start(NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_LBIST_start negative test failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        cslRet = CSL_LBIST_stop(NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_LBIST_stop negative test failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        cslRet = CSL_LBIST_isRunning(NULL, NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_LBIST_isRunning negative test failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        cslRet = CSL_LBIST_isDone(NULL, NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_LBIST_isDone negative test failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        cslRet = CSL_LBIST_programConfig(NULL, NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_LBIST_programConfig negative test failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        cslRet = CSL_LBIST_getMISR(NULL, NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_LBIST_getMISR negative test failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        cslRet = CSL_LBIST_getExpectedMISR(NULL, NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_LBIST_getMISR negative test failed \n");
            testResult = -1;
        }
    }

    return (testResult);
}


/* LBIST Error module test */
int32_t LBIST_errTest(void)
{
    int32_t testResult;

    testResult = LBIST_errNegativeTest();

    return (testResult);
}

/* Nothing past this point */
