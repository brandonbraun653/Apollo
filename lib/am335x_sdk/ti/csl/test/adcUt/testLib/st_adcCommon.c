/*
 *  Copyright (c) Texas Instruments Incorporated 2019
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
 *  \file st_adcCommon.c
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <st_adc.h>
#include <ti/drv/sciclient/sciclient.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* Reference voltage for ADC - should be given in mV*/
#define APP_ADC_REFERENCE_VOLTAGE_MV    (1800U)
#define APP_ADC_RANGE_MAX               (4096U)

/** Volatage Levels given to ADC module
 *  These levels will be used to compare against converted values for PASS/FAIL
 *  Criteria
 */
#define MCUADC0_CHANNEL_1_VOLTAGE_MV            (1800U)
#define MCUADC0_CHANNEL_2_VOLTAGE_MV            (1600U)
#define MCUADC0_CHANNEL_3_VOLTAGE_MV            (1400U)
#define MCUADC0_CHANNEL_4_VOLTAGE_MV            (1200U)
#define MCUADC0_CHANNEL_5_VOLTAGE_MV            (1000U)
#define MCUADC0_CHANNEL_6_VOLTAGE_MV            (800U)
#define MCUADC0_CHANNEL_7_VOLTAGE_MV            (600U)
#define MCUADC0_CHANNEL_8_VOLTAGE_MV            (400U)
#define MCUADC1_CHANNEL_1_VOLTAGE_MV            (200U)
#define MCUADC1_CHANNEL_2_VOLTAGE_MV            (1400U)


/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

static int32_t ADCClockEnable(uint32_t module, uint32_t clkEnable);
static int32_t ADCGetChannelId(st_ADCTestcaseParams_t *testParams, uint32_t stepId, uint32_t *channelId);
static uint32_t ADCGetExpectedVol(uint32_t adcModule, uint32_t channelId);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t st_adcModuleInit(uint32_t adcModule)
{
    int32_t status;
    /* Enable ADC clock */
    status = ADCClockEnable(adcModule, TRUE);

    /* Power up AFE */
    ADCPowerUp(adcModule, TRUE);

    /* Wait for 4us at least */
    Osal_delay(1);

    /* Do the internal calibration */
    ADCInit(adcModule, FALSE, 0U, 0U);

    /* Clear All interrupt status */
    ADCClearIntrStatus(adcModule, ADC_INTR_STATUS_ALL);

    return status;
}

void st_adcModuleDeinit(uint32_t adcModule)
{
    ADCPowerUp(adcModule, FALSE);
    ADCClockEnable(adcModule, FALSE);
    return;
}

void st_adcModuleStart(uint32_t adcModule)
{
    adcSequencerStatus_t adcSeqStatus;

    /* Check if FSM is idle */
    ADCGetSequencerStatus(adcModule, &adcSeqStatus);
    while((ADC_ADCSTAT_FSM_BUSY_IDLE != adcSeqStatus.fsmBusy) &&
           ADC_ADCSTAT_STEP_ID_IDLE != adcSeqStatus.stepId)
    {
        ADCGetSequencerStatus(adcModule, &adcSeqStatus);
    }
    /* Start ADC conversion */
    ADCStart(adcModule, TRUE);

    return;
}

void st_adcModuleStop(st_ADCTestcaseParams_t *testParams)
{
    uint32_t                loopCnt;
    uint32_t                adcModule;
    adcSequencerStatus_t    adcSeqStatus;

    adcModule = testParams->adcConfigParams.adcModule;

    /* step disable */
    for (loopCnt = 0U; loopCnt < testParams->adcConfigParams.numSteps;
         loopCnt++)
    {
        ADCStepEnable(adcModule,
                      testParams->adcConfigParams.adcSteps[loopCnt].stepId,
                      FALSE);
    }

    /* Wait for FSM to go IDLE */
    ADCGetSequencerStatus(adcModule, &adcSeqStatus);
    while((ADC_ADCSTAT_FSM_BUSY_IDLE != adcSeqStatus.fsmBusy) &&
           ADC_ADCSTAT_STEP_ID_IDLE != adcSeqStatus.stepId)
    {
        ADCGetSequencerStatus(adcModule, &adcSeqStatus);
    }

    /* Stop ADC */
    ADCStart(adcModule, FALSE);

    /* Wait for FSM to go IDLE */
    ADCGetSequencerStatus(adcModule, &adcSeqStatus);
    while((ADC_ADCSTAT_FSM_BUSY_IDLE != adcSeqStatus.fsmBusy) &&
           ADC_ADCSTAT_STEP_ID_IDLE != adcSeqStatus.stepId)
    {
        ADCGetSequencerStatus(adcModule, &adcSeqStatus);
    }

    return;
}


int32_t st_adcStepConfig(st_ADCTestcaseParams_t *testParams)
{
    int32_t status = STW_SOK;
    uint32_t loopCnt;
    adcStepConfig_t adcConfig;
    uint32_t    adcModule;

    adcModule = testParams->adcConfigParams.adcModule;
    for (loopCnt = 0; loopCnt < testParams->adcConfigParams.numSteps; loopCnt++)
    {
        stw_ADCStepConfigParams_t *adcStepConfig = &(testParams->adcConfigParams.adcSteps[loopCnt]);
        adcConfig.channel           = adcStepConfig->channel;
        adcConfig.openDelay         = adcStepConfig->openDelay;
        adcConfig.sampleDelay       = adcStepConfig->sampleDelay;
        adcConfig.rangeCheckEnable  = adcStepConfig->rangeCheckEnable;
        adcConfig.averaging         = adcStepConfig->averaging;
        adcConfig.fifoNum           = adcStepConfig->fifoNum;
        adcConfig.mode              = testParams->adcConfigParams.adcSteps[loopCnt].mode;
        status  += ADCSetStepParams(
            adcModule,
            testParams->adcConfigParams.adcSteps[loopCnt].stepId,
            &adcConfig);
    }
    if (STW_SOK != status)
    {
        UART_printf("Error in ADC step configuration.\n");
    }

    if (TRUE == testParams->adcConfigParams.stepIdTagEnable)
    {
        ADCStepIdTagEnable(adcModule, TRUE);
    }
    else
    {
        ADCStepIdTagEnable(adcModule, FALSE);
    }

    /* step enable */
    for (loopCnt = 0U; loopCnt < testParams->adcConfigParams.numSteps;
         loopCnt++)
    {
        ADCStepEnable(adcModule,
                      testParams->adcConfigParams.adcSteps[loopCnt].stepId,
                      TRUE);
    }
    return status;
}

int32_t st_adcValidateFifoData(st_ADCTestcaseParams_t *testParams, uint32_t *adcDataBuff, uint32_t numSamples)
{
    int32_t  status = STW_SOK;
    uint32_t stepId, channelId, loopCnt;
    uint32_t fifoData, voltLvl, expectedVolmV;

    for (loopCnt = 0U; loopCnt < numSamples; loopCnt++)
    {
        fifoData = *adcDataBuff;
        stepId   = ((fifoData & ADC_FIFODATA_ADCCHNLID_MASK) >>
                    ADC_FIFODATA_ADCCHNLID_SHIFT);
        fifoData = ((fifoData & ADC_FIFODATA_ADCDATA_MASK) >>
                    ADC_FIFODATA_ADCDATA_SHIFT);
        voltLvl = ((fifoData * APP_ADC_REFERENCE_VOLTAGE_MV) /
                   APP_ADC_RANGE_MAX);
        if (STW_SOK == ADCGetChannelId(testParams, stepId, &channelId))
        {
            expectedVolmV = ADCGetExpectedVol(testParams->adcConfigParams.adcModule, channelId);
            if ((voltLvl >= (expectedVolmV + testParams->adcConfigParams.errOffset)) ||
                (voltLvl <= (expectedVolmV - testParams->adcConfigParams.errOffset)))
            {
                UART_printf("Step ID : %d Channel Id: %d Expected: %dmV Observed voltage: %dmV (Voltage Matching failed).\n",
                    (stepId + 1U), channelId, expectedVolmV, voltLvl);
                status = STW_EFAIL;
            }
            else
            {
                UART_printf("Step ID : %d Channel Id: %d Expected: %dmV Observed voltage: %dmV.\n",
                    (stepId + 1U), channelId, expectedVolmV, voltLvl);
            }
        }
        adcDataBuff++;
    }
    return status;
}


static int32_t ADCClockEnable(uint32_t module, uint32_t clkEnable)
{
    int32_t status;
    uint32_t clkEnableFlag;

    if (clkEnable == TRUE)
    {
        clkEnableFlag = TISCI_MSG_VALUE_DEVICE_SW_STATE_ON;
    }
    else
    {
        clkEnableFlag = TISCI_MSG_VALUE_DEVICE_SW_STATE_AUTO_OFF;
    }
    switch (module)
    {
        case CSL_MCU_ADC0_BASE:
            /* Enable ADC module */
            status = Sciclient_pmSetModuleState(TISCI_DEV_MCU_ADC0,
                clkEnableFlag,
                TISCI_MSG_FLAG_AOP,
                SCICLIENT_SERVICE_WAIT_FOREVER);
            break;
        case CSL_MCU_ADC1_BASE:
            /* Enable ADC module */
            status = Sciclient_pmSetModuleState(TISCI_DEV_MCU_ADC1,
                clkEnableFlag,
                TISCI_MSG_FLAG_AOP,
                SCICLIENT_SERVICE_WAIT_FOREVER);
            break;
        default:
            status = CSL_EFAIL;
            break;
    }
    return status;
}

static int32_t ADCGetChannelId(st_ADCTestcaseParams_t *testParams, uint32_t stepId, uint32_t *channelId)
{
    int32_t retVal = STW_EFAIL;
    uint32_t loopCnt;
    for (loopCnt = 0U; loopCnt < testParams->adcConfigParams.numSteps; loopCnt++)
    {
        if (stepId == testParams->adcConfigParams.adcSteps[loopCnt].stepId)
        {
            *channelId = testParams->adcConfigParams.adcSteps[loopCnt].channel;
            retVal = STW_SOK;
            break;
        }
    }
    return retVal;
}

static uint32_t ADCGetExpectedVol(uint32_t adcModule, uint32_t channelId)
{
    uint32_t voltLvl;

    if (adcModule == CSL_MCU_ADC0_BASE)
    {
        switch (channelId)
        {
            case ADC_CHANNEL_1:
                voltLvl = MCUADC0_CHANNEL_1_VOLTAGE_MV;
                break;
            case ADC_CHANNEL_2:
                voltLvl = MCUADC0_CHANNEL_2_VOLTAGE_MV;
                break;
            case ADC_CHANNEL_3:
                voltLvl = MCUADC0_CHANNEL_3_VOLTAGE_MV;
                break;
            case ADC_CHANNEL_4:
                voltLvl = MCUADC0_CHANNEL_4_VOLTAGE_MV;
                break;
            case ADC_CHANNEL_5:
                voltLvl = MCUADC0_CHANNEL_5_VOLTAGE_MV;
                break;
            case ADC_CHANNEL_6:
                voltLvl = MCUADC0_CHANNEL_6_VOLTAGE_MV;
                break;
            case ADC_CHANNEL_7:
                voltLvl = MCUADC0_CHANNEL_7_VOLTAGE_MV;
                break;
            case ADC_CHANNEL_8:
                voltLvl = MCUADC0_CHANNEL_8_VOLTAGE_MV;
                break;
            default:
                voltLvl = 0U;
                break;
        }
    }
    if (adcModule == CSL_MCU_ADC1_BASE)
    {
        switch (channelId)
        {
            case ADC_CHANNEL_1:
                voltLvl = MCUADC1_CHANNEL_1_VOLTAGE_MV;
                break;
            case ADC_CHANNEL_2:
            case ADC_CHANNEL_3:
            case ADC_CHANNEL_4:
            case ADC_CHANNEL_5:
            case ADC_CHANNEL_6:
            case ADC_CHANNEL_7:
            case ADC_CHANNEL_8:
                voltLvl = MCUADC1_CHANNEL_2_VOLTAGE_MV;
                break;
            default:
                voltLvl = 0U;
                break;
        }
    }
    return voltLvl;
}
