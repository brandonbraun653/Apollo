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
 *  \file     esm_negTest.c
 *
 *  \brief    This file contains ESM Negtive test code.
 *
 *  \details  ESM Negative tests
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
#define ESM_INVALID_INTRS  (0xffffU)

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

/*===========================================================================*/
/*                         Function definitions                              */
/*===========================================================================*/

int32_t cslEsm_negTest(void)
{
    uint32_t             baseAddr = CSL_MCU_ESM0_CFG_BASE;
    int32_t              testStatus = CSL_APP_TEST_PASS;
    uint32_t             val;
    esmRevisionId_t      revId;
    esmInfo_t            info;
    CSL_esmStaticRegs    staticRegs;
    esmGroupIntrStatus_t grpIntrStatus;

    /* ESMSetMode negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetMode(NULL, ESM_OPERATION_MODE_NORMAL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMGetMode negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetMode(0U, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetMode(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMSetInfluenceOnErrPin negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetInfluenceOnErrPin(0U, 0U, false) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetInfluenceOnErrPin(baseAddr, ESM_INVALID_INTRS, false) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMGetInfluenceOnErrPin negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetInfluenceOnErrPin(0U, 0U, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetInfluenceOnErrPin(baseAddr, ESM_INVALID_INTRS, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetInfluenceOnErrPin(baseAddr, 0U, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMSetErrPinLowTimePreload negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetErrPinLowTimePreload(0U, 0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMGetErrPinLowTimePreload negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetErrPinLowTimePreload(0U, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetErrPinLowTimePreload(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMGetCurrErrPinLowTimeCnt negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetCurrErrPinLowTimeCnt(0U, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetCurrErrPinLowTimeCnt(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMGetErrPinStatus negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetErrPinStatus(0U, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetErrPinStatus(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMResetErrPin negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMResetErrPin(0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMIsEnableIntr negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMIsEnableIntr(0U, 0U, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMIsEnableIntr(baseAddr, ESM_INVALID_INTRS, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMIsEnableIntr(baseAddr, 0U, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMEnableIntr negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMEnableIntr(0U, 0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMEnableIntr(baseAddr, ESM_INVALID_INTRS) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMDisableIntr negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMDisableIntr(0U, 0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMDisableIntr(baseAddr, ESM_INVALID_INTRS) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMSetIntrPriorityLvl negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetIntrPriorityLvl(0U, 0U, ESM_INTR_PRIORITY_LEVEL_LOW) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetIntrPriorityLvl(baseAddr, ESM_INVALID_INTRS, ESM_INTR_PRIORITY_LEVEL_LOW) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMGetIntrPriorityLvl negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrPriorityLvl(0U, 0U, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrPriorityLvl(baseAddr, ESM_INVALID_INTRS, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrPriorityLvl(baseAddr, 0U, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMGetIntrStatus negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrStatus(0U, 0U, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrStatus(baseAddr, ESM_INVALID_INTRS, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrStatus(baseAddr, 0U, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMGetGroupIntrStatus negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetGroupIntrStatus(0U, ESM_INTR_PRIORITY_LEVEL_LOW, &grpIntrStatus) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetGroupIntrStatus(baseAddr, ESM_INTR_PRIORITY_LEVEL_LOW, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMClearIntrStatus negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMClearIntrStatus(0U, 0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMClearIntrStatus(baseAddr, ESM_INVALID_INTRS) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMSetIntrStatusRAW negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetIntrStatusRAW(0U, 0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMSetIntrStatusRAW(baseAddr, ESM_INVALID_INTRS) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMGetIntrStatusRAW negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrStatusRAW(0U, 0U, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrStatusRAW(baseAddr, ESM_INVALID_INTRS, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetIntrStatusRAW(baseAddr, 0U, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMWriteEOI negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMWriteEOI(0U, 0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMGetRevisionId negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetRevisionId(0U, &revId) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMGetInfo negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetInfo(0U, &info) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMGetGlobalIntrEnabledStatus negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetGlobalIntrEnabledStatus(0U, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMGetGlobalIntrEnabledStatus(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMEnableGlobalIntr negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMEnableGlobalIntr(0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMDisableGlobalIntr negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMDisableGlobalIntr(0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMReset negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMReset(0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* ESMReadStaticRegs negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMReadStaticRegs(0U, &staticRegs) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (ESMReadStaticRegs(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("cslEsm_negTest: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    return (testStatus);
}

/* Nothing past this point */
