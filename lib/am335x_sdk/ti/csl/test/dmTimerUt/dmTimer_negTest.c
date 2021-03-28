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
 *  \file     dmTimer_negTest.c
 *
 *  \brief    This file contains dmTimer negative test code.
 *
 *  \details  dmTimer negative tests
 **/
/*===========================================================================*/
/*                         Include files                                     */
/*===========================================================================*/
#include <dmTimer_test.h>

/*===========================================================================*/
/*                         Declarations                                      */
/*===========================================================================*/
/* None */

/*===========================================================================*/
/*                         Macros                                            */
/*===========================================================================*/
#define TIMER_INVALID_BASE_ADDR        (0x0U)
#define TIMER_INVALID_TIMER_MODE       (0xffffU)
#define TIMER_INVALID_PRESCALER_VAL    (0x0U)
#define TIMER_INVALID_PRESCALER_VAL2   (TIMER_TCLR_PRE_MASK+1)
#define TIMER_INVALID_GPO_CFG_VAL      (0xffffU)
#define TIMER_INVALID_INT_STATUS_MASK  (0x0U)
#define TIMER_INVALID_POST_MODE        (0xffffU)
#define TIMER_INVALID_IDLE_MODE        (0xffffU)
#define TIMER_INVALID_READ_MODE        (0xffffU)


/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

/*===========================================================================*/
/*                         Function definitions                              */
/*===========================================================================*/

int32_t csldmTimer_negTest(void)
{
    int32_t         testStatus = CSL_APP_TEST_PASS;
    uint32_t        baseAddr = CSL_MCU_TIMER0_CFG_BASE;
    uint32_t        val;
    TIMERSTATICREGS staticRegs;
    TIMERCONTEXT    tmrContext;

    /* TIMEREnable negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMEREnable(TIMER_INVALID_BASE_ADDR) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMEREnable: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERDisable negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERDisable(TIMER_INVALID_BASE_ADDR) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERDisable: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }


    /* TIMERModeConfigureGet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERModeConfigureGet(TIMER_INVALID_BASE_ADDR, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERModeConfigureGet(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERModeConfigureGet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERModeConfigure negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERModeConfigure(TIMER_INVALID_BASE_ADDR, TIMER_ONESHOT_CMP_ENABLE) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERModeConfigure(baseAddr, TIMER_INVALID_TIMER_MODE) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERModeConfigure: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERPreScalerClkEnable negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERPreScalerClkEnable(TIMER_INVALID_BASE_ADDR, TIMER_PRESCALER_CLK_DIV_BY_2) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERPreScalerClkEnable(baseAddr, TIMER_INVALID_PRESCALER_VAL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERPreScalerClkEnable(baseAddr, TIMER_INVALID_PRESCALER_VAL2) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }

    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERPreScalerClkEnable: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERPreScalerClkDisable negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERPreScalerClkDisable(TIMER_INVALID_BASE_ADDR) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERPreScalerClkDisable: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERCounterSet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERCounterSet(TIMER_INVALID_BASE_ADDR, 0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERCounterSet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERReloadSet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERReloadSet(TIMER_INVALID_BASE_ADDR, 0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERReloadSet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERGPOConfigureGet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERGPOConfigureGet(TIMER_INVALID_BASE_ADDR, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERGPOConfigureGet(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERGPOConfigureGet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERGPOConfigure negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERGPOConfigure(TIMER_INVALID_BASE_ADDR, TIMER_GPO_CFG_0) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERGPOConfigure(baseAddr, TIMER_INVALID_GPO_CFG_VAL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERGPOConfigure: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERCompareSet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERCompareSet(TIMER_INVALID_BASE_ADDR, 0x0U) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERCompareSet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERIntRawStatusSet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERIntRawStatusSet(TIMER_INVALID_BASE_ADDR, TIMER_IRQSTATUS_OVF_IT_FLAG_MASK) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERIntRawStatusSet(baseAddr, TIMER_INVALID_INT_STATUS_MASK) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERIntRawStatusSet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERIntStatusClear negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERIntStatusClear(TIMER_INVALID_BASE_ADDR, TIMER_IRQSTATUS_OVF_IT_FLAG_MASK) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERIntStatusClear(baseAddr, TIMER_INVALID_INT_STATUS_MASK) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERIntStatusClear: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERIntEnable negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERIntEnable(TIMER_INVALID_BASE_ADDR, TIMER_INT_OVF_EN_FLAG) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERIntEnable(baseAddr, TIMER_INVALID_INT_STATUS_MASK) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERIntEnable: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERIntDisable negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERIntDisable(TIMER_INVALID_BASE_ADDR, TIMER_INT_OVF_EN_FLAG) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERIntDisable(baseAddr, TIMER_INVALID_INT_STATUS_MASK) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERIntDisable: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERWakeEnable negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERWakeEnable(TIMER_INVALID_BASE_ADDR, TIMER_IRQWAKEEN_OVF_WUP_ENA_MASK) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERWakeEnable(baseAddr, TIMER_INVALID_INT_STATUS_MASK) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERWakeEnable: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERWakeDisable negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERWakeDisable(TIMER_INVALID_BASE_ADDR, TIMER_IRQWAKEEN_OVF_WUP_ENA_MASK) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERWakeDisable(baseAddr, TIMER_INVALID_INT_STATUS_MASK) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERWakeDisable: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERTriggerSet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTriggerSet(TIMER_INVALID_BASE_ADDR) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERTriggerSet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERReset negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERReset(TIMER_INVALID_BASE_ADDR) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }

    /* TIMERResetConfigure negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERResetConfigure(TIMER_INVALID_BASE_ADDR,
                                TIMER_SFT_RESET_ENABLE) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERResetConfigure(baseAddr,
                                TIMER_TSICR_SFT_SFT_1) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERResetConfigure: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERResetConfigureGet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERResetConfigureGet(TIMER_INVALID_BASE_ADDR,
                                   &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERResetConfigureGet(baseAddr, NULL_PTR) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERResetConfigureGet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERReset negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERReset(TIMER_INVALID_BASE_ADDR) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERReset: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERContextSave negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERContextSave(TIMER_INVALID_BASE_ADDR, &tmrContext) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERContextSave(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERContextSave: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERContextRestore negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERContextRestore(TIMER_INVALID_BASE_ADDR, &tmrContext) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERContextRestore(baseAddr, NULL_PTR) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERContextRestore: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERPostedModeConfig negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERPostedModeConfig(TIMER_INVALID_BASE_ADDR, TIMER_POSTED) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERPostedModeConfig(baseAddr, TIMER_INVALID_POST_MODE) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERPostedModeConfig: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERPostedModeConfigGet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERPostedModeConfigGet(TIMER_INVALID_BASE_ADDR, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERPostedModeConfigGet(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERPostedModeConfigGet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERIdleModeConfigureGet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERIdleModeConfigureGet(TIMER_INVALID_BASE_ADDR, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERIdleModeConfigureGet(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERIdleModeConfigureGet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERIdleModeConfigure negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERIdleModeConfigure(TIMER_INVALID_BASE_ADDR, TIMER_FORCE_IDLE) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERIdleModeConfigure(baseAddr, TIMER_INVALID_IDLE_MODE) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERIdleModeConfigure: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMEREmuModeConfigureGet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMEREmuModeConfigureGet(TIMER_INVALID_BASE_ADDR, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMEREmuModeConfigureGet(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMEREmuModeConfigureGet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMEREmuModeConfigure negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMEREmuModeConfigure(TIMER_INVALID_BASE_ADDR, TIMER_FREE) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMEREmuModeConfigure: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERReadModeConfig negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERReadModeConfig(TIMER_INVALID_BASE_ADDR, TIMER_READ_MODE_NONPOSTED) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERReadModeConfig(baseAddr, TIMER_INVALID_READ_MODE) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERReadModeConfig: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERTPIRGet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTPIRGet(TIMER_INVALID_BASE_ADDR, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTPIRGet(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERTPIRGet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERTPIRSet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTPIRSet(TIMER_INVALID_BASE_ADDR, 0x0U) != CSL_EBADARGS)
        {
             testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERTPIRSet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERTPIRGet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTPIRGet(TIMER_INVALID_BASE_ADDR, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTPIRGet(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERTPIRGet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERTNIRSet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTNIRSet(TIMER_INVALID_BASE_ADDR, 0x0U) != CSL_EBADARGS)
        {
             testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERTNIRSet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERTCVRGet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTCVRGet(TIMER_INVALID_BASE_ADDR, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTCVRGet(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERTCVRGet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERTNIRGet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTNIRGet(TIMER_INVALID_BASE_ADDR, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTNIRGet(baseAddr, NULL_PTR) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERTNIRGet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERTCVRSet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTCVRSet(TIMER_INVALID_BASE_ADDR, 0x0U) != CSL_EBADARGS)
        {
             testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERTCVRSet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERTOCRGet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTOCRGet(TIMER_INVALID_BASE_ADDR, &val) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTOCRGet(baseAddr, NULL) != CSL_EBADARGS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERTOCRGet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERTOCRSet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTOCRSet(TIMER_INVALID_BASE_ADDR, 0x0U) != CSL_EBADARGS)
        {
             testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERTOCRSet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERTOWRSet negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERTOWRSet(TIMER_INVALID_BASE_ADDR, 0x0U) != CSL_EBADARGS)
        {
             testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERTOWRSet: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* TIMERGetStaticRegs negative test */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERGetStaticRegs(TIMER_INVALID_BASE_ADDR, &staticRegs) != CSL_EBADARGS)
        {
             testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        if (TIMERGetStaticRegs(baseAddr, NULL) != CSL_EBADARGS)
        {
             testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus != CSL_APP_TEST_PASS)
    {
        UART_printf("TIMERGetStaticRegs: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    return (testStatus);
}

/* Nothing past this point */
