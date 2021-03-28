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
 *  \file     dmTimer_apiTest.c
 *
 *  \brief    This file contains dmTimer API test code.
 *
 *  \details  dmTimer API tests
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
/* None */

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

/*===========================================================================*/
/*                         Function definitions                              */
/*===========================================================================*/

int32_t csldmTimer_apiTest(void)
{
    uint32_t    baseAddr                = CSL_MCU_TIMER0_CFG_BASE;
    uint32_t    timerMode, readMode, idleMode, emuMode, regVal;
    uint32_t    ptv                     = TIMER_PRESCALER_CLK_DIV_BY_2;
    uint32_t    counter, gpoVal, compareVal, intFlags;
    TIMERSTATICREGS staticRegs;
    TIMERCONTEXT    tmrContext;
    int32_t     testStatus, cslRet                  = CSL_PASS;

    if (cslRet == CSL_PASS)
    {
        cslRet =  TIMEREnable(baseAddr);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet =  TIMERDisable(baseAddr);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERModeConfigureGet(baseAddr, &timerMode);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet =  TIMERModeConfigure(baseAddr, timerMode);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERPreScalerClkEnable(baseAddr, ptv);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERPreScalerClkDisable(baseAddr);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        counter=TIMERCounterGet(baseAddr);
        cslRet = TIMERCounterSet(baseAddr, counter);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        regVal = TIMERReloadGet( baseAddr);
        cslRet = TIMERReloadSet( baseAddr, regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERGPOConfigureGet(baseAddr, &gpoVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERGPOConfigure(baseAddr, gpoVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        compareVal = TIMERCompareGet( baseAddr);
        cslRet = TIMERCompareSet( baseAddr,  compareVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        intFlags = TIMERIntRawStatusGet(baseAddr);
        intFlags |= TIMER_IRQSTATUS_OVF_IT_FLAG_MASK;
        cslRet = TIMERIntRawStatusSet( baseAddr, intFlags);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        intFlags = TIMERIntStatusGet(baseAddr);
        intFlags = TIMER_IRQSTATUS_OVF_IT_FLAG_MASK;
        cslRet = TIMERIntStatusClear(baseAddr, intFlags);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        intFlags = TIMER_INT_OVF_EN_FLAG;
        cslRet = TIMERIntEnable( baseAddr,  intFlags);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERIntDisable( baseAddr, intFlags);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERWakeEnable(baseAddr, TIMER_IRQWAKEEN_OVF_WUP_ENA_MASK);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERWakeDisable(baseAddr, TIMER_IRQWAKEEN_OVF_WUP_ENA_MASK);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERTriggerSet(baseAddr);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        intFlags = TIMERIntEnableGet(baseAddr);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERResetConfigure(baseAddr, TIMER_SFT_RESET_ENABLE);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERResetConfigureGet(baseAddr, &regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERReadModeConfigGet(baseAddr, &regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERReset(baseAddr);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERContextSave(baseAddr,  &tmrContext);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERContextRestore(baseAddr,  &tmrContext);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERPostedModeConfigGet(baseAddr, &regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERPostedModeConfig(baseAddr, regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        regVal = TIMERWritePostedStatusGet(baseAddr);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERIdleModeConfigureGet(baseAddr, &idleMode);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        idleMode = TIMER_NO_IDLE;
        cslRet = TIMERIdleModeConfigure(baseAddr, idleMode);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMEREmuModeConfigureGet(baseAddr, &emuMode);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        emuMode = TIMER_FREE;
        cslRet = TIMEREmuModeConfigure( baseAddr,  emuMode);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }



    if (cslRet == CSL_PASS)
    {
        readMode = TIMER_READ_MODE_NONPOSTED;
        cslRet = TIMERReadModeConfig( baseAddr, readMode);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERTPIRGet(baseAddr,  &regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERTPIRSet(baseAddr,  regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERTNIRGet( baseAddr,  &regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERTNIRSet( baseAddr,  regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERTCVRGet( baseAddr,  &regVal);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERTCVRSet( baseAddr,  regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERTOCRGet( baseAddr,  &regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }


    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERTOCRSet( baseAddr,  regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        regVal = TIMERTOWRGet(baseAddr);
        cslRet = TIMERTOWRSet(baseAddr, regVal);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERGetStaticRegs(baseAddr, &staticRegs);
    }
    else
    {
        UART_printf("csldmTimer_apiTest: failure on line no. %d \n", __LINE__);
    }

    if (cslRet == CSL_PASS)
    {
        testStatus = CSL_APP_TEST_PASS;
    }
    else
    {
        testStatus = CSL_APP_TEST_FAILED;
    }
    return (testStatus);
}

/* Nothing past this point */
