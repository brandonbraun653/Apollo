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
 *  \file     dmTimer_funcTest.c
 *
 *  \brief    This file contains dmTimer functional test code.
 *
 *  \details  dmTimer functional tests
 **/

/*===========================================================================*/
/*                         Include files                                     */
/*===========================================================================*/
#include <dmTimer_test.h>
#include <ti/osal/osal.h>

/*===========================================================================*/
/*                         Declarations                                      */
/*===========================================================================*/
typedef void (*dmTimerFxn)(uintptr_t arg);

/*===========================================================================*/
/*                         Macros                                            */
/*===========================================================================*/
#define CSL_TEST_TIMER_DM_TWPS_W_PEND_TCLR    (0x1u)
#define CSL_TEST_TIMER_DM_TWPS_W_PEND_TCRR    (0x2u)
#define CSL_TEST_TIMER_DM_TWPS_W_PEND_TLDR    (0x4u)
#define CSL_TEST_TIMER_COUNTER_VAL            (0xffffe000u)

#if defined (BUILD_MCU)
#define TEST_TIMER_BASE_ADDR                  (CSL_MCU_TIMER2_CFG_BASE)
#define TEST_TIMER_INT_NUM                    (CSL_MCU0_INTR_TIMER2_INTR_PEND)
#endif

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/
static int32_t csldmTimer_testInitObj(uint32_t     timerBaseAddr);
static int32_t csldmTimer_continuousTest(uint32_t  timerBaseAddr);
static int32_t csldmTimer_registerTimerInt(uint32_t  timerBaseAddr);
static int32_t csldmTimer_unRegisterTimerInt(uint32_t  timerBaseAddr);
static void csldmTimerTest_Stub(uintptr_t arg);
static int32_t csldmTimer_stop(uint32_t baseAddr);
static int32_t csldmTimer_setMode(uint32_t  baseAddr, uint32_t timerMode);


/*===========================================================================*/
/*                         Global variables                                  */
/*===========================================================================*/
HwiP_Handle      gdmTimerTest_HwiPHandle;
volatile uint32_t         gdmTimerTest_IsrCount = 0u;

/*===========================================================================*/
/*                         Function definitions                              */
/*===========================================================================*/
static void csldmTimerTest_Stub(uintptr_t arg)
{
  uint32_t baseAddr = (uint32_t) (TEST_TIMER_BASE_ADDR);

  /* Disable the Timer interrupts */
  TIMERIntDisable(baseAddr, TIMER_INT_OVF_EN_FLAG);

  /* acknowledge the interrupt */
  TIMERIntStatusClear(baseAddr, TIMER_IRQSTATUS_OVF_IT_FLAG_MASK);

  gdmTimerTest_IsrCount++;

   /* Enable the Timer interrupts */
  TIMERIntEnable(baseAddr, TIMER_INT_OVF_EN_FLAG);
}

static int32_t csldmTimer_unRegisterTimerInt(uint32_t  baseAddr)
{
    int32_t    testStatus;
    OsalInterruptRetCode_e   retVal;
    retVal = Osal_DeleteInterrupt(gdmTimerTest_HwiPHandle, NULL);

    if (retVal == OSAL_INT_SUCCESS)
    {
        testStatus = CSL_APP_TEST_PASS;
    }
    else
    {
        testStatus = CSL_APP_TEST_FAILED;
    }
    return (testStatus);
}

static int32_t csldmTimer_registerTimerInt(uint32_t  baseAddr)
{
    int32_t                  testStatus;
    OsalInterruptRetCode_e   retVal;
    OsalRegisterIntrParams_t interruptRegParams;
    /* Initialize with defaults */
    Osal_RegisterInterrupt_initParams(&interruptRegParams);

    /* Populate the interrupt parameters */
    interruptRegParams.corepacConfig.arg=(uintptr_t) TEST_TIMER_BASE_ADDR;
    interruptRegParams.corepacConfig.name=NULL;
    interruptRegParams.corepacConfig.isrRoutine=csldmTimerTest_Stub;
    interruptRegParams.corepacConfig.triggerSensitivity =  OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
    interruptRegParams.corepacConfig.priority = 0x20U;

    interruptRegParams.corepacConfig.intVecNum=TEST_TIMER_INT_NUM; /* Host Interrupt vector */
    interruptRegParams.corepacConfig.corepacEventNum = 0u;

    /* Register interrupts */
    retVal = Osal_RegisterInterrupt(&interruptRegParams,&(gdmTimerTest_HwiPHandle));

    if (retVal == OSAL_INT_SUCCESS)
    {
        testStatus = CSL_APP_TEST_PASS;
    }
    else
    {
        testStatus = CSL_APP_TEST_FAILED;
    }
    return (testStatus);
}

static int32_t csldmTimer_testInitObj(uint32_t baseAddr)
{
    int32_t cslRet = CSL_EFAIL, testStatus;
    uint32_t status;
    /* Create the Timer ISR hook before enabling the timer */
    testStatus = csldmTimer_registerTimerInt(baseAddr);

    /* Reset the timer */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        cslRet = TIMERReset(baseAddr);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMEREmuModeConfigure(baseAddr, TIMER_FREE);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERIdleModeConfigure(baseAddr, TIMER_NO_IDLE);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERPostedModeConfig(baseAddr, TIMER_NONPOSTED);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERReadModeConfig(baseAddr, TIMER_READ_MODE_NONPOSTED);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERCounterSet(baseAddr, CSL_TEST_TIMER_COUNTER_VAL);
        do {
          status = (TIMERWritePostedStatusGet(baseAddr) & CSL_TEST_TIMER_DM_TWPS_W_PEND_TCRR);
        } while (status != (uint32_t) 0u);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERReloadSet(baseAddr, CSL_TEST_TIMER_COUNTER_VAL);
        do {
          status = (TIMERWritePostedStatusGet(baseAddr) & CSL_TEST_TIMER_DM_TWPS_W_PEND_TLDR);
        } while (status != (uint32_t) 0u);
    }

    if (cslRet == CSL_PASS)
    {
        /* Enable the Timer Wakeup events represented by wakeFlags */
        cslRet = TIMERWakeEnable(baseAddr, TIMER_IRQWAKEEN_OVF_WUP_ENA_MASK);
    }

    if (cslRet == CSL_PASS)
    {
        TIMERIntEnable(baseAddr, TIMER_INT_OVF_EN_FLAG);
    }
    if (cslRet == CSL_PASS)
    {
        cslRet = TIMERDisable(baseAddr);
    }

    /* Return the operation status */
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

static int32_t csldmTimer_stop(uint32_t baseAddr)
{
    uint32_t  tisr = 0u;
    int32_t   cslRet;
    /* Disable the Timer */
    cslRet = TIMERDisable(baseAddr);

    if (cslRet == CSL_PASS)
    {
        tisr = TIMERIntStatusGet(baseAddr);
    }

    if(tisr) {
      /* Clear all pending interrupts */
      cslRet = TIMERIntStatusClear(baseAddr, tisr);
    }

    return (CSL_APP_TEST_PASS);
}

static int32_t csldmTimer_setMode(uint32_t  baseAddr, uint32_t timerMode)
{
    int32_t     testStatus, cslRet;
    uint32_t    key;

    key        = HwiP_disable();
    testStatus = csldmTimer_stop(baseAddr);

    if (testStatus == CSL_APP_TEST_PASS)
    {
        /* Clear the timer interrupt */
        HwiP_clearInterrupt(TEST_TIMER_INT_NUM);
        HwiP_enableInterrupt(TEST_TIMER_INT_NUM);

        cslRet = TIMERModeConfigure(baseAddr, timerMode);
        if (cslRet != CSL_PASS)
        {
            testStatus = CSL_APP_TEST_FAILED;
        }
    }
    if (testStatus == CSL_APP_TEST_PASS)
    {
        cslRet = TIMEREnable(baseAddr);
    }
    HwiP_restore(key);

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


static int32_t csldmTimer_continuousTest(uint32_t  baseAddr)
{
    int32_t     testStatus;
    uint32_t    timeOutVal = 0xfffffff0;

    testStatus = csldmTimer_setMode(baseAddr, TIMER_AUTORLD_NOCMP_ENABLE);

    /* Wait for the timer ISR to happen */
    while (timeOutVal != 1u)
    {
        if (gdmTimerTest_IsrCount > 100)
        {
            break;
        }
        timeOutVal--;
    }

    if (timeOutVal == 1u)
    {
        /* Interrupt did not happen, declare failure */
        testStatus = CSL_APP_TEST_FAILED;
    }
    else
    {
        testStatus = CSL_APP_TEST_PASS;
    }

    csldmTimer_stop(baseAddr);
    return (testStatus);
}

int32_t csldmTimer_funcTest(void)
{
    int32_t     testStatus;
    uint32_t    timerAddr =  (uint32_t)  TEST_TIMER_BASE_ADDR;

    /* Init the Timer */
    testStatus = csldmTimer_testInitObj(timerAddr);

    /* Test for continuous Timer */
    if (testStatus == CSL_APP_TEST_PASS)
    {
        gdmTimerTest_IsrCount = 0;
        testStatus = csldmTimer_continuousTest(timerAddr);
    }

    if (testStatus == CSL_APP_TEST_PASS)
    {
        testStatus = csldmTimer_unRegisterTimerInt(timerAddr);
    }
    return (testStatus);
}

/* Nothing past this point */
