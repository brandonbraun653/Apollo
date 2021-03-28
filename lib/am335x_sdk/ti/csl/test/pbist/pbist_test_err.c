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
 *  \brief    This file contains LBIST Error module test code for R5 core.
 *
 *  \details  LBIST Error module tests
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/csl_types.h>
#include <ti/csl/csl_pbist.h>
#include <ti/csl/soc.h>
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

static int32_t PBIST_errNegativeTest(void)
{
    int32_t                    testResult = CSL_PASS;
    CSL_ErrType_t cslRet;
    CSL_PBIST_config_t PBISTConfig;
    Bool PBISTresult;

    /* Call CSL API */
    cslRet = CSL_PBIST_softReset(NULL);
    if (cslRet == CSL_PASS)
    {
        UART_printf("\n  CSL_PBIST_softReset negative test failed \n");
        testResult = -1;
    }

    if (testResult == 0)
    {
        cslRet = CSL_PBIST_start((CSL_pbistRegs *)CSL_MCU_PBIST0_BASE, NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_PBIST_start negative test 1 failed \n");
            testResult = -1;
        }
    }
    if (testResult == 0)
    {
        cslRet = CSL_PBIST_start(NULL, &PBISTConfig);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_PBIST_start negative test 2 failed \n");
            testResult = -1;
        }
    }
    if (testResult == 0)
    {
        cslRet = CSL_PBIST_start(NULL, NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_PBIST_start negative test 3 failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        cslRet = CSL_PBIST_checkResult((CSL_pbistRegs *)CSL_MCU_PBIST0_BASE, NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_PBIST_checkResult negative test 1 failed \n");
            testResult = -1;
        }
    }
    if (testResult == 0)
    {
        cslRet = CSL_PBIST_checkResult(NULL, &PBISTresult);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_PBIST_checkResult negative test 2 failed \n");
            testResult = -1;
        }
    }
    if (testResult == 0)
    {
        cslRet = CSL_PBIST_checkResult(NULL, NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_PBIST_checkResult negative test 3 failed \n");
            testResult = -1;
        }
    }

    if (testResult == 0)
    {
        cslRet = CSL_PBIST_releaseTestMode(NULL);
        if (cslRet == CSL_PASS)
        {
            UART_printf("\n  CSL_PBIST_releaseTestMode negative test failed \n");
            testResult = -1;
        }
    }

    return (testResult);
}

/* PBIST Error module test */
int32_t PBIST_errTest(void)
{
    int32_t    testResult;

    testResult = PBIST_errNegativeTest();

    return (testResult);
}

/* Nothing past this point */
