/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 *  \file   adc_am65xx.c
 *
 *  \brief  adc diagnostic test file.
 *
 *  Targeted Functionality: Verification of ADC connector.
 *
 *  Operation: This test verifies by reading the Analogue input
			   given to the connector.
 *
 *  Supported SoCs: AM65xx.
 *
 *  Supported Platforms: am65xx_evm & am65xx_idk.
 */

#include "adc_am65xx.h"

adcDetails_t adc[NUM_OF_ADC] = {
	{ CSL_MCU_ADC0_BASE, ADC0_CHANNEL_NO },
	{ CSL_MCU_ADC1_BASE, ADC1_CHANNEL_NO } 
};

static void BoardDiag_adcStop(uint32_t baseAddress)
{
    adcSequencerStatus_t status;

	/* Wait for FSM to go IDLE */
	ADCGetSequencerStatus(baseAddress, &status);
    while ((ADC_ADCSTAT_FSM_BUSY_IDLE != status.fsmBusy) &&
           ADC_ADCSTAT_STEP_ID_IDLE != status.stepId)
    {
        ADCGetSequencerStatus(baseAddress, &status);
    }

    /* Stop ADC */
    ADCStart(baseAddress, FALSE);
    /* Wait for FSM to go IDLE */
    ADCGetSequencerStatus(baseAddress, &status);
    while ((ADC_ADCSTAT_FSM_BUSY_IDLE != status.fsmBusy) &&
           ADC_ADCSTAT_STEP_ID_IDLE != status.stepId)
    {
        ADCGetSequencerStatus(baseAddress, &status);
    }
}

static void BoardDiag_adcStart(uint32_t baseAddress)
{
    adcSequencerStatus_t status;

    /* Check if FSM is idle */
    ADCGetSequencerStatus(baseAddress, &status);
    while ((ADC_ADCSTAT_FSM_BUSY_IDLE != status.fsmBusy) &&
           ADC_ADCSTAT_STEP_ID_IDLE != status.stepId)
    {
        ADCGetSequencerStatus(baseAddress, &status);
    }
    /* Start ADC conversion */
    ADCStart(baseAddress, TRUE);
}

static int8_t BoardDiag_initADC(uint32_t baseAddress)
{
    adcRevisionId_t revId;

    ADCGetRevisionId(baseAddress, &revId);

    UART_printf("\nADC Revision ID:\n");
    UART_printf("scheme: %d\n", revId.scheme);
    UART_printf("Functional number: %d\n", revId.func);
    UART_printf("RTL revision: %d\n", revId.rtlRev);
    UART_printf("Major revision: %d\n", revId.major);
    UART_printf("Custom revision: %d\n", revId.custom);
    UART_printf("Major revision: %d\n\n", revId.minor);

    /* Clear All interrupt status */
    ADCClearIntrStatus(baseAddress, ADC_INTR_STATUS_ALL);

    /* Power up AFE */
    ADCPowerUp(baseAddress, TRUE);

    /* Wait for 4us at least */
    BOARD_delay(400);

    /* Do the internal calibration */
    ADCInit(baseAddress, FALSE, 0U, 0U);

    return 0;
}

static int8_t BoardDiag_run_ADCTest()
{
	adcStepConfig_t adcConfig;
	uint32_t fifoData, configStatus;
	uint32_t intrStatus, voltageLvl;
	int8_t fifoWordCnt, ret;
	int8_t index, stepID, i;

	for (i = 0; i < NUM_OF_ADC; i++)
	{
		UART_printf("\n\nReading ADC %d", i);

		ret = BoardDiag_initADC(adc[i].baseAddress);
		if (ret != 0)
		{
			UART_printf("Failed to initialize ADC %d\n", i);
			return -1;
		}
		/* Enable interrupts */
		ADCEnableIntr(adc[i].baseAddress, (ADC_INTR_SRC_END_OF_SEQUENCE |
										   ADC_INTR_SRC_FIFO0_THRESHOLD |
										   ADC_INTR_SRC_FIFO0_OVERRUN |
										   ADC_INTR_SRC_FIFO0_UNDERFLOW |
										   ADC_INTR_SRC_OUT_OF_RANGE));

		/* Initialize ADC configuration params */
		adcConfig.mode             = ADC_OPERATION_MODE_SINGLE_SHOT;
		adcConfig.openDelay        = 0x1U;
		adcConfig.sampleDelay      = 0U;
		adcConfig.rangeCheckEnable = 0U;
		adcConfig.averaging        = ADC_AVERAGING_NONE;
		adcConfig.fifoNum          = ADC_FIFO_NUM_0;

		for (index = 0; index < adc[i].channelNo; index++)
		{
			adcConfig.channel = index;
			configStatus = ADCSetStepParams(adc[i].baseAddress, 
											index, &adcConfig);
			if (configStatus != 0)
			{
				UART_printf("\nFailed at ADC set parm");
				return -1;
			}
			ADCStepEnable(adc[i].baseAddress, index, TRUE);
		}

		ADCStepIdTagEnable(adc[i].baseAddress, TRUE);
		configStatus = ADCSetCPUFIFOThresholdLevel(adc[i].baseAddress, 
												   ADC_FIFO_NUM_0, 40U);
		if (configStatus != 0)
		{
			UART_printf("\nFailed while setting FIFO threshold level");
			return -1;
		}
		/* Start conversion */
		BoardDiag_adcStart(adc[i].baseAddress);

		intrStatus = ADCGetIntrStatus(adc[i].baseAddress);

		while(!(ADC_INTR_SRC_END_OF_SEQUENCE == (intrStatus & ADC_INTR_SRC_END_OF_SEQUENCE)))
		{ 
			intrStatus = ADCGetIntrStatus(adc[i].baseAddress);
		}

		fifoWordCnt = ADCGetFIFOWordCount(adc[i].baseAddress, ADC_FIFO_NUM_0);

		for (index = 0; index < fifoWordCnt; index++)
		{
			fifoData = ADCGetFIFOData(adc[i].baseAddress, ADC_FIFO_NUM_0);
			stepID   = ((fifoData & ADC_FIFODATA_ADCCHNLID_MASK) >>
								ADC_FIFODATA_ADCCHNLID_SHIFT);
			fifoData = ((fifoData & ADC_FIFODATA_ADCDATA_MASK) >>
						ADC_FIFODATA_ADCDATA_SHIFT);
			voltageLvl  = fifoData * (uint32_t) ADC_REF_VOLTAGE;
			voltageLvl /= (uint32_t) ADC_MAX_RANGE;
			UART_printf("\nChannel %d: Voltage Level is %dmV", stepID, voltageLvl);
		}
		for (index = 0; index < adc[i].channelNo; index++)
		{
			ADCStepEnable(adc[i].baseAddress, index, FALSE);
		}

		BoardDiag_adcStop(adc[i].baseAddress);
		/* Power down ADC */
		ADCPowerUp(adc[i].baseAddress, FALSE);
	}

	return 0;
}

int8_t BoardDiag_adcFunctionalTest(void)
{
    int8_t ret = 0;

    ret = BoardDiag_run_ADCTest();

    return ret;
}

#ifdef DIAG_STRESS_TEST
int8_t BoardDiag_adcStressTest(void)
{
    int8_t ret = 0;
    char rdBuf = 'y';
    uint32_t iteration;
    uint32_t passCount = 0;
    uint32_t failCount = 0;

    UART_printf("\n\nRunning ADC Test in Stress Mode for %d Number of Times...\n", DIAG_STRESS_TEST_ITERATIONS);
    UART_printf("Enter 'b' in Serial Console to Terminate the Test\n\n");

    for(iteration = 1; iteration <= DIAG_STRESS_TEST_ITERATIONS; iteration++)
    {
        ret = BoardDiag_adcFunctionalTest();
        if (ret == 0)
        {
            UART_printf("\n\n\n\nIteration : %d ADC Test Passed\n",iteration);
            passCount++;
        }
        else
        {
            UART_printf("\n\n\n\nADC Test Failed at iteration - %d\n",iteration);
            failCount++;
        }

        /* Check if there a input from console to break the test */
        rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((rdBuf == 'b') || (rdBuf == 'B'))
        {
            UART_printf("Received Test Termination... Exiting the Test\n");
            iteration++;
            break;
        }
    }

    UART_printf("\n\nADC Stress Test Status\n");
    UART_printf("===================================\n");
    UART_printf("Number of Times Executed - %d\n", (iteration - 1));
    UART_printf("Pass Count - %d\n", passCount);
    UART_printf("Fail Count - %d\n", failCount);

    if((iteration != 0) && (failCount == 0))
    {
        UART_printf("Overall Status - PASS\n\n\n" );
    }
    else
    {
        UART_printf("Overall Status - FAIL\n\n\n" );
        ret = -1;
    }

    return ret;
}
#endif

int main()
{
    Board_STATUS status;
    Board_initCfg boardCfg;
    int8_t ret;

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    UART_printf("\n**********************************************\n");
    UART_printf(  "                     ADC Test                 \n");
    UART_printf(  "**********************************************\n");

#ifdef DIAG_STRESS_TEST
    ret = BoardDiag_adcStressTest();
#else
    ret = BoardDiag_adcFunctionalTest();
#endif
    if(ret == 0)
    {
        UART_printf("\nADC Test Passed\n");
    }
    else
    {
        UART_printf("\nADC Test Failed\n");
    }

    return ret;
}
