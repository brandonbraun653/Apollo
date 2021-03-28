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
 *  \file     st_adcCpuMode.c
 *
 *  \brief    This file contains ADC test code for CPU mode.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_adc.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define APP_ADC_MAX_SAMPLES             (300U)
#define APP_ADC_DIV                     (8U)

#define ADC_VOLTAGE_ERR_OFFSET_MV       (100U)
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static uint32_t             gAdcModule;
static volatile uint32_t    gIsrFlag = 1U;
static uint64_t             gTimeStampBeforeADC, gTimeStampAfterADC;
static HwiP_Handle          gHwiHandleDone = NULL;

/* Application Buffers */
uint32_t gAdcCpuDestBuf[APP_ADC_MAX_SAMPLES];


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   This Interrupt Service Routine for ADC interrupt.
 *
 * \param   none.
 *
 * \retval  none.
 */
static void AppADCIntrISR(uintptr_t handle);

static int32_t ADCAppRegisterIsr(uint32_t adcInst);

static uint32_t ADCExtractFifoData(uint32_t fifoNum, uint32_t *dstBuff);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t st_adcCpuMode_main(st_ADCTestcaseParams_t *testParams)
{
    int32_t         status;
    uint32_t        loopCnt, numElems;

    gIsrFlag = 1U;
    /* Initialize ADC configuration params */
    gAdcModule = testParams->adcConfigParams.adcModule;

    UART_printf("Starting ADC UT test id %d.\n", testParams->testcaseId);

    for (loopCnt = 0U; loopCnt < APP_ADC_MAX_SAMPLES; loopCnt++)
    {
        gAdcCpuDestBuf[loopCnt] = 0U;
    }

    /* Initialize ADC module. */
    status = st_adcModuleInit(gAdcModule);

    /* Register ADC interrupts */
    status += ADCAppRegisterIsr(gAdcModule);

    if (STW_SOK != status)
    {
        UART_printf("Error in ADC Initialization.\n");
    }

    /* Configure ADC step */
    status = st_adcStepConfig(testParams);
    if (STW_SOK != status)
    {
        UART_printf("Error in ADC step configuration.\n");
    }

    /* Enable ADC FIFO */
    if (testParams->adcConfigParams.fifoEnable == TRUE)
    {
        status = ADCSetCPUFIFOThresholdLevel(
            gAdcModule, ADC_FIFO_NUM_0,
            testParams->adcConfigParams.fifoThreshold);
        status += ADCSetCPUFIFOThresholdLevel(
            gAdcModule, ADC_FIFO_NUM_1,
            testParams->adcConfigParams.fifoThreshold);
        if (STW_SOK != status)
        {
            UART_printf("Error in ADC CPU threshold configuration.\n");
        }
    }

    gTimeStampBeforeADC = TimerP_getTimeInUsecs();
    ADCSetRange(gAdcModule,
                testParams->adcConfigParams.highRange,
                testParams->adcConfigParams.lowRange);
    /* Clear All interrupts */
    ADCClearIntrStatus(gAdcModule, ADC_INTR_ALL);
    /* Enable interrupts */
    ADCEnableIntr(gAdcModule, testParams->adcConfigParams.intrEnable);

    /* Start ADC conversion */
    st_adcModuleStart(gAdcModule);

    /* wait for adc completion */
    while (1U == gIsrFlag)
    {}

    /*Get FIFO data and Validate */
    numElems = ADCExtractFifoData(ADC_FIFO_NUM_0, &gAdcCpuDestBuf[0]);
    if (numElems != 0U)
    {
        status =  st_adcValidateFifoData(testParams, &gAdcCpuDestBuf[0], numElems);
    }
    numElems = ADCExtractFifoData(ADC_FIFO_NUM_1, &gAdcCpuDestBuf[0]);
    if (numElems != 0U)
    {
        status =  st_adcValidateFifoData(testParams, &gAdcCpuDestBuf[0], numElems);
    }

    /* Disable ADC interrupts */
    ADCDisableIntr(gAdcModule, testParams->adcConfigParams.intrEnable);

    /* Stop ADC */
    st_adcModuleStop(testParams);

    /* De initialize ADC module. */
    st_adcModuleDeinit(gAdcModule);

    UART_printf(
        "Time taken for conversion is %d us.\n",
        (uint32_t) (gTimeStampAfterADC - gTimeStampBeforeADC));
    testParams->testResult = status;
    return 0;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */
/**
 * \brief   This API is used to introduce error.
 *
 * \param   testParams      test case parameters.
 *
 * \retval  status          Run status.
 */
static uint32_t ADCExtractFifoData(uint32_t fifoNum, uint32_t *dstBuff)
{
    uint32_t loopCnt, numElems;
    numElems = ADCGetFIFOWordCount(gAdcModule, fifoNum);

    for (loopCnt = 0U; loopCnt < numElems; loopCnt++)
    {
        *dstBuff = ADCGetFIFOData(gAdcModule, fifoNum);
        dstBuff++;
    }
    return numElems;
}

static int32_t ADCAppRegisterIsr(uint32_t adcInst)
{
    int32_t retVal = CSL_PASS;
    OsalInterruptRetCode_e osalRetVal = OSAL_INT_SUCCESS;

    OsalRegisterIntrParams_t intrPrmsDone;
    Osal_RegisterInterrupt_initParams(&intrPrmsDone);
    intrPrmsDone.corepacConfig.arg          = (uintptr_t)0;
    intrPrmsDone.corepacConfig.priority     = 1U;
    intrPrmsDone.corepacConfig.corepacEventNum = 0U; /* NOT USED ? */
    intrPrmsDone.corepacConfig.isrRoutine   = &AppADCIntrISR;

    switch (adcInst)
    {
        case CSL_MCU_ADC0_BASE :
            intrPrmsDone.corepacConfig.intVecNum    = CSL_MCU0_INTR_ADC0_GEN_LEVEL;
        break;
        case CSL_MCU_ADC1_BASE :
            intrPrmsDone.corepacConfig.intVecNum    = CSL_MCU0_INTR_ADC1_GEN_LEVEL;
        break;
        default :
            UART_printf(": Error : ADC Instance not supported in"
                        " this example !!!\r\n");
            retVal = CSL_EFAIL;
        break;
    }
    if (CSL_PASS == retVal)
    {
        osalRetVal += Osal_RegisterInterrupt(&intrPrmsDone, &gHwiHandleDone);
        if(OSAL_INT_SUCCESS != osalRetVal)
        {
            retVal = CSL_EFAIL;
            UART_printf(": Error Could not register ISR !!!\n");
        }
    }
    return (retVal);
}

static void AppADCIntrISR(uintptr_t handle)
{
    uint32_t status;
    uint32_t fifoWordCnt, fifoData, stepID, loopcnt, highRange, lowRange;

    gTimeStampAfterADC = TimerP_getTimeInUsecs();
    UART_printf("In ISR...\n");
    status = ADCGetIntrRawStatus(gAdcModule);
    UART_printf("Interrupt RAW status:0x%x.\n", status);
    status = ADCGetIntrStatus(gAdcModule);
    if (ADC_INTR_SRC_END_OF_SEQUENCE == (status & ADC_INTR_SRC_END_OF_SEQUENCE))
    {
        UART_printf("End of sequence interrupt occurred.\n");
    }
    if (ADC_INTR_SRC_FIFO0_THRESHOLD == (status & ADC_INTR_SRC_FIFO0_THRESHOLD))
    {
        UART_printf("FIFO 0 threshold interrupt occurred.\n");
        fifoWordCnt = ADCGetFIFOWordCount(gAdcModule, ADC_FIFO_NUM_0);
        UART_printf("Number of samples in FIFO:%d.\n", fifoWordCnt);
        if (0U != fifoWordCnt)
        {
            UART_printf("FIFO Data:\n");
        }
        for (loopcnt = 0U; loopcnt < fifoWordCnt; loopcnt++)
        {
            fifoData = ADCGetFIFOData(gAdcModule, ADC_FIFO_NUM_0);
            stepID   = ((fifoData & ADC_FIFODATA_ADCCHNLID_MASK) >>
                        ADC_FIFODATA_ADCCHNLID_SHIFT);
            fifoData = ((fifoData & ADC_FIFODATA_ADCDATA_MASK) >>
                        ADC_FIFODATA_ADCDATA_SHIFT);
            UART_printf("Step ID : %d.    Data : %dmV.\n", stepID + 1,
                   ((fifoData * 1800) / 4096));
        }
    }
    if (ADC_INTR_SRC_FIFO0_OVERRUN == (status & ADC_INTR_SRC_FIFO0_OVERRUN))
    {
        UART_printf("FIFO 0 overrun interrupt occurred.\n");
    }
    if (ADC_INTR_SRC_FIFO0_UNDERFLOW == (status & ADC_INTR_SRC_FIFO0_UNDERFLOW))
    {
        UART_printf("FIFO 0 underflow interrupt occurred.\n");
    }
    if (ADC_INTR_SRC_FIFO1_THRESHOLD == (status & ADC_INTR_SRC_FIFO1_THRESHOLD))
    {
        UART_printf("FIFO 1 threshold interrupt occurred.\n");
        fifoWordCnt = ADCGetFIFOWordCount(gAdcModule, ADC_FIFO_NUM_1);
        UART_printf("Number of samples in FIFO:%d.\n", fifoWordCnt);
        if (0U != fifoWordCnt)
        {
            UART_printf("FIFO Data:\n");
        }
        for (loopcnt = 0U; loopcnt < fifoWordCnt; loopcnt++)
        {
            fifoData = ADCGetFIFOData(gAdcModule, ADC_FIFO_NUM_1);
            stepID   = ((fifoData & ADC_FIFODATA_ADCCHNLID_MASK) >>
                        ADC_FIFODATA_ADCCHNLID_SHIFT);
            fifoData = ((fifoData & ADC_FIFODATA_ADCDATA_MASK) >>
                        ADC_FIFODATA_ADCDATA_SHIFT);
            UART_printf("Step ID : %d.    Data : %dmV.\n", stepID + 1,
                   ((fifoData * 1800) / 4096));
        }
    }
    if (ADC_INTR_SRC_FIFO1_OVERRUN == (status & ADC_INTR_SRC_FIFO1_OVERRUN))
    {
        UART_printf("FIFO 1 overrun interrupt occurred.\n");
    }
    if (ADC_INTR_SRC_FIFO1_UNDERFLOW == (status & ADC_INTR_SRC_FIFO1_UNDERFLOW))
    {
        UART_printf("FIFO 1 underflow interrupt occurred.\n");
    }
    if (ADC_INTR_SRC_OUT_OF_RANGE == (status & ADC_INTR_SRC_OUT_OF_RANGE))
    {
        UART_printf("Out of range interrupt occurred.\n");
        fifoWordCnt = ADCGetFIFOWordCount(gAdcModule, ADC_FIFO_NUM_0);
        UART_printf("Number of samples in FIFO:%d.\n", fifoWordCnt);
        if (0U != fifoWordCnt)
        {
            UART_printf("FIFO Data:\n");
        }
        for (loopcnt = 0U; loopcnt < fifoWordCnt; loopcnt++)
        {
            fifoData = ADCGetFIFOData(gAdcModule, ADC_FIFO_NUM_0);
            stepID   = ((fifoData & ADC_FIFODATA_ADCCHNLID_MASK) >>
                        ADC_FIFODATA_ADCCHNLID_SHIFT);
            fifoData = ((fifoData & ADC_FIFODATA_ADCDATA_MASK) >>
                        ADC_FIFODATA_ADCDATA_SHIFT);
            UART_printf("Step ID : %d.    Data : %dmV.\n", stepID + 1,
                   fifoData);
        }
        ADCGetRange(gAdcModule, &highRange, &lowRange);
        UART_printf("Programmed range:(%d,%d)\n", lowRange, highRange);
    }
    ADCClearIntrStatus(gAdcModule, ADCGetIntrRawStatus(gAdcModule));
    ADCWriteEOI(gAdcModule);
    gIsrFlag = 0U;
}
