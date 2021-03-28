/* Copyright (c) 2019 Texas Instruments Incorporated
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
 *  \file     esm_apiTest.c
 *
 *  \brief    This file contains ESM API test code.
 *
 *  \details  ESM API tests
 **/
/*===========================================================================*/
/*                         Include files                                     */
/*===========================================================================*/
#include <ti/csl/csl_esm.h>
#include "esm_test.h"

/*===========================================================================*/
/*                         Declarations                                      */
/*===========================================================================*/
/* None */

/*===========================================================================*/
/*                         Macros                                            */
/*===========================================================================*/
/* None */

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

/*===========================================================================*/
/*                         Function definitions                              */
/*===========================================================================*/

int32_t cslEsm_apiTest(void)
{
    uint32_t             baseAddr = CSL_MCU_ESM0_CFG_BASE;
    int32_t              testStatus = CSL_APP_TEST_PASS;
    uint32_t             val;
    esmRevisionId_t      revId;
    esmInfo_t            info;
    CSL_esmStaticRegs    staticRegs;
    esmGroupIntrStatus_t grpIntrStatus;

    /* ESMSetMode API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetMode(baseAddr, ESM_OPERATION_MODE_NORMAL) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetMode API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetMode(baseAddr, &val) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMSetInfluenceOnErrPin API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetInfluenceOnErrPin(baseAddr, 0U, false) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetInfluenceOnErrPin API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetInfluenceOnErrPin(baseAddr, 0U, &val) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMSetErrPinLowTimePreload API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetErrPinLowTimePreload(baseAddr, 0U) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetErrPinLowTimePreload API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetErrPinLowTimePreload(baseAddr, &val) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetCurrErrPinLowTimeCnt API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetCurrErrPinLowTimeCnt(baseAddr, &val) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetErrPinStatus API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetErrPinStatus(baseAddr, &val) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMResetErrPin API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMResetErrPin(baseAddr) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMIsEnableIntr API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMIsEnableIntr(baseAddr, 0U, &val) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMEnableIntr API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMEnableIntr(baseAddr, 0U) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMDisableIntr API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMDisableIntr(baseAddr, 0U) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMSetIntrPriorityLvl API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetIntrPriorityLvl(baseAddr, 0U, ESM_INTR_PRIORITY_LEVEL_LOW) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetIntrPriorityLvl API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrPriorityLvl(baseAddr, 0U, &val) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetIntrStatus API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrStatus(baseAddr, 0U, &val) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetIntrStatus API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrStatus(baseAddr, 0U, &val) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetGroupIntrStatus API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetGroupIntrStatus(baseAddr, ESM_INTR_PRIORITY_LEVEL_LOW, &grpIntrStatus) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMClearIntrStatus API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMClearIntrStatus(baseAddr, 0U) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMSetIntrStatusRAW API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetIntrStatusRAW(baseAddr, 0U) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetIntrStatusRAW API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrStatusRAW(baseAddr, 0U, &val) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMWriteEOI API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMWriteEOI(baseAddr, 0U) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetRevisionId API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetRevisionId(baseAddr, &revId) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetInfo API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetInfo(baseAddr, &info) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMGetGlobalIntrEnabledStatus API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetGlobalIntrEnabledStatus(baseAddr, &val) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMEnableGlobalIntr API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMEnableGlobalIntr(baseAddr) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMDisableGlobalIntr API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMDisableGlobalIntr(baseAddr) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMReset API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMReset(baseAddr) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    /* ESMReadStaticRegs API test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMReadStaticRegs(baseAddr, &staticRegs) != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
            UART_printf("cslEsm_apiTest: failure on line no. %d \n", __LINE__);
        }
    }

    return (testStatus);
}

/* Nothing past this point */
