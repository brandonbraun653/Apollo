/*
 *  Copyright (c) Texas Instruments Incorporated 2018
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
 */

/**
 *  \file st_dccCont.c
 *
 *  \brief This is the main function for continuous mode operation.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_dcc.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
volatile uint32_t gIsrFlag = 0U, gLastIntr = 3U;
static uint32_t gModule, gEsmInst, gEsmEvtNum;
static HwiP_Handle gHwiHandleErr = NULL;
/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   This function is used to configure and enable CPU interrupt.
 *
 * \param   dccInst          DCC module.
 *
 * \retval  status          Configuration status.
 */
static int32_t DCCAppRegisterIsr(uint32_t dccInst);

/**
 * \brief   This function is used to unregister the interrupts.
 *
 * \param   dccInst          DCC module.
 *
 * \retval  status          Configuration status.
 */
static int32_t DCCAppUnregisterIsr(void);

/**
 * \brief   This Interrupt Service Routine for DCC error interrupt.
 *
 * \param   none.
 *
 * \retval  none.
 */
void DCCContAppErrorIntrISR(uintptr_t handle);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void st_cont_main(st_DCCTestcaseParams_t *testParams)
{
    int32_t status = 0;
    uint32_t testClkFreq, testClkCnt, refClkFreqKHz, refClkCnt;
    volatile uint32_t timeOutms = 5000U;
    dccConfigParams_t configParams;
    dccRevisionId_t   revId;

    /* Set result to fail */
    testParams->testResult = STW_EFAIL;
    gIsrFlag = 0U;
    gLastIntr = 3U;

    /* Get the ref clock and test clock frequency */
    DCCAppGetTestClkfreqKHz(testParams->dccConfigParams.dccModule,
                            testParams->dccConfigParams.dccClkSrc0,
                            &refClkFreqKHz,
                            testParams->dccConfigParams.dccClkSrc1,
                            &testClkFreq);

    refClkCnt = (testParams->dccConfigParams.dccSeedSrc0 +
                (testParams->dccConfigParams.dccSeedValid0 / 2));

    /* Get the test clock seed value */
    testClkCnt = DCCAppGetSrc1SeedVal(refClkFreqKHz,
                                      refClkCnt, testClkFreq);

    /* Initialize DCC configuration parameters */
    gModule = testParams->dccConfigParams.dccModule;
    configParams.mode = testParams->dccMode;
    configParams.clkSrc0 = testParams->dccConfigParams.dccClkSrc0;
    configParams.clkSrc1 = testParams->dccConfigParams.dccClkSrc1;
    configParams.seedSrc0 = testParams->dccConfigParams.dccSeedSrc0;
    configParams.seedValid0 = testParams->dccConfigParams.dccSeedValid0;
    configParams.alternateClkSrc1 = testParams->dccConfigParams.alternateClkSrc1;
    configParams.seedSrc1 = testClkCnt;

    status = DCCAppRegisterIsr(gModule);

    if(CSL_PASS == status)
    {
        /* Enable DCC module */
        status = DCCClockEnable(gModule);
        if(STW_SOK != status)
        {
            UART_printf("ERROR in enabling DCC module.\n");
        }
        else
        {
            UART_printf("Module enabled.\n");
        }
    }
    if (STW_SOK == status)
    {
        /* Get revision ID */
        DCCGetRevisionId(gModule, &revId);
        UART_printf("Scheme :0x%x\n", revId.scheme);
        UART_printf("Functional release number :0x%x\n", revId.func);
        UART_printf("Design Release Number :0x%x\n", revId.rtlReleaseNum);
        UART_printf("Major Revision Number :0x%x\n", revId.major);
        UART_printf("Minor revision number :0x%x\n", revId.minor);
        UART_printf("Special version of the module  :0x%x\n", revId.custom);
        /* Configure DCC module */
        status = DCCSetConfig(gModule, &configParams);
        if(STW_EFAIL == status)
        {
            UART_printf("ERROR in DCC configuration.\n");
        }
        else
        {
            UART_printf("Running the DCC in continuous mode. Test will end in %d ms.\n", timeOutms);
            DCCEnableIntr(gModule, DCC_INTERRUPTS_ERROR);
            /* Enable DCC operation/module */
            DCCEnable(gModule, TRUE);
            /* Wait here till interrupt is generated */
            Osal_delay(timeOutms);

            /* Check if the error interrupts generated. */
            if (gIsrFlag != 0)
            {
                /* Interrupt happened mark the test case as fail. */
                testParams->testResult = STW_EFAIL;
                UART_printf("Try to run application again.\n");
                status = STW_EFAIL;
            }
        }
    }
    if (STW_SOK == status)
    {
        /* Test error case */
        /* Update the seed value for test clk to generate error. */
        UART_printf("Changing test clock seed value to inject error.\n");
        configParams.seedSrc1 = configParams.seedSrc1 * 2;

        /* Configure DCC module */
        status = DCCSetConfig(gModule,
                                    &configParams);
        if(STW_EFAIL == status)
        {
            UART_printf("ERROR in DCC configuration.\n");
        }
        else
        {
            while(0U == gIsrFlag);
            if(2U == gLastIntr)
            {
                gIsrFlag = 0U;
                gLastIntr = 0U;
                testParams->testResult = STW_SOK;
                UART_printf("Application ran successfully.\n");
            }
            else
            {
                testParams->testResult = STW_EFAIL;
                UART_printf("Try to run application again.\n");
            }
        }
    }
    /* Disable DCC interrupts */
    DCCDisableIntr(gModule, DCC_INTERRUPTS_ERROR);

    DCCAppUnregisterIsr();

    testParams->isRun = STW_SOK;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */
static int32_t DCCAppRegisterIsr(uint32_t dccInst)
{
    int32_t retVal = CSL_PASS;
    OsalRegisterIntrParams_t intrPrmsErr;
    OsalInterruptRetCode_e osalRetVal = OSAL_INT_SUCCESS;

    Osal_RegisterInterrupt_initParams(&intrPrmsErr);
    intrPrmsErr.corepacConfig.arg          = (uintptr_t)0;
    intrPrmsErr.corepacConfig.priority     = 1U;
    intrPrmsErr.corepacConfig.corepacEventNum = 0U; /* NOT USED ? */
    intrPrmsErr.corepacConfig.isrRoutine   = &DCCContAppErrorIntrISR;

    switch (dccInst)
    {
        case CSL_MCU_DCC0_BASE :
            gEsmInst = CSL_MCU_ESM0_CFG_BASE;
            gEsmEvtNum = CSL_ESM1_INTR_DCC0_INTR_ERR_LEVEL;
            DCCAppEnableEsm(gEsmInst, gEsmEvtNum);
            intrPrmsErr.corepacConfig.intVecNum    = CSL_MCU0_INTR_ESM1_ESM_INT_HI_LVL;
        break;
        case CSL_MCU_DCC1_BASE :
            gEsmInst = CSL_MCU_ESM0_CFG_BASE;
            gEsmEvtNum = CSL_ESM1_INTR_DCC1_INTR_ERR_LEVEL;
            DCCAppEnableEsm(gEsmInst, gEsmEvtNum);
            intrPrmsErr.corepacConfig.intVecNum    = CSL_MCU0_INTR_ESM1_ESM_INT_HI_LVL;
        break;
        case CSL_MCU_DCC2_BASE :
            gEsmInst = CSL_MCU_ESM0_CFG_BASE;
            gEsmEvtNum = CSL_ESM1_INTR_DCC2_INTR_ERR_LEVEL;
            DCCAppEnableEsm(gEsmInst, gEsmEvtNum);
            intrPrmsErr.corepacConfig.intVecNum    = CSL_MCU0_INTR_ESM1_ESM_INT_HI_LVL;
        break;
        case CSL_DCC0_BASE :
            gEsmInst = CSL_ESM0_CFG_BASE;
            gEsmEvtNum = CSL_ESM0_INTR_DCC0_BUS_INTR_ERR_LEVEL;
            DCCAppEnableEsm(gEsmInst, gEsmEvtNum);
            intrPrmsErr.corepacConfig.intVecNum    = CSL_MCU0_INTR_ESM2_ESM_INT_HI_LVL;
        break;

        default :
            UART_printf(": Error : DCC Instance not supported in"
                        " this example !!!\r\n");
            retVal = CSL_EFAIL;
        break;
    }
    if (CSL_PASS == retVal)
    {
        osalRetVal += Osal_RegisterInterrupt(&intrPrmsErr, &gHwiHandleErr);
        if(OSAL_INT_SUCCESS != osalRetVal)
        {
            retVal = CSL_EFAIL;
            UART_printf(": Error Could not register ISR !!!\n");
        }
    }
    return (retVal);
}

static int32_t DCCAppUnregisterIsr(void)
{
    int32_t retVal = CSL_PASS;
    if (gHwiHandleErr != NULL)
    {
        retVal = Osal_DeleteInterrupt(gHwiHandleErr, 0U);
        gHwiHandleErr = NULL;
    }
    return retVal;
}

void DCCContAppErrorIntrISR(uintptr_t handle)
{
    uint32_t status;
    dccConfigParams_t configParams;
    uint32_t srcCnt1, srcCnt0, srcValid0;

    status = DCCGetIntrStatus(gModule);
    UART_printf("In ISR...\n");
    UART_printf("Interrupt Status: 0x%x.\n", status);
    UART_printf("ERROR interrupt generated.\n");
    DCCGetConfig(gModule, &configParams);
    srcCnt0 = HW_RD_REG32(gModule + DCC_DCCCNT0);
    srcValid0 = HW_RD_REG32(gModule + DCC_DCCVALID0);
    srcCnt1 = HW_RD_REG32(gModule + DCC_DCCCNT1);
    if(configParams.seedSrc0 == srcCnt0)
    {
        UART_printf("Reference clock is not present.\n");
    }
    if(configParams.seedSrc1 == srcCnt1)
    {
        UART_printf("Test clock is not present.\n");
    }
    else
    {
        UART_printf("Test clock is drifted.\n");
        UART_printf("Count0=>%d/%d\nValid0=>%d/%d\nCount1=>%d/%d\n",
                srcCnt0, configParams.seedSrc0, srcValid0,
                configParams.seedValid0, srcCnt1, configParams.seedSrc1);
    }
    DCCClearIntrStatus(gModule, DCC_INTERRUPTS_ERROR);

    /* Clear ESM registers. */
    ESMClearIntrStatus(gEsmInst, gEsmEvtNum);
    ESMResetErrPin(gEsmInst);

    gIsrFlag = 1U;
    gLastIntr = 2U;
}

