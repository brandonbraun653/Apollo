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
 *  \file stw_adcTestcases.h
 *
 *  \brief This file defines the test cases for ADC UT.
 */

#ifndef STW_ADC_TEST_CASES_H_
#define STW_ADC_TEST_CASES_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_adc.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define ADC_NUM_TESTCASES               (sizeof (gADCTestcaseParams) / sizeof (st_ADCTestcaseParams_t))

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Defines the various ADC test cases. */
st_ADCTestcaseParams_t gADCTestcaseParams[] =
{
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 1U,
        .testCaseName       = "MCU ADC0 all channel all steps cpu mode",
        .disableInfo        = "None",
        .adcConfigParams    =
            {
                CSL_MCU_ADC0_BASE,
                ADC_OPERATION_MODE_SINGLE_SHOT,
                (ADC_INTR_SRC_END_OF_SEQUENCE | ADC_INTR_SRC_FIFO0_OVERRUN |
                ADC_INTR_SRC_FIFO0_UNDERFLOW),
                16,
                {
                    {ADC_STEP_1, ADC_CHANNEL_1, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_2, ADC_CHANNEL_2, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_3, ADC_CHANNEL_3, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_4, ADC_CHANNEL_4, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_5, ADC_CHANNEL_5, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_6, ADC_CHANNEL_6, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_7, ADC_CHANNEL_7, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_8, ADC_CHANNEL_8, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_9, ADC_CHANNEL_1, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_10, ADC_CHANNEL_2, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_11, ADC_CHANNEL_3, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_12, ADC_CHANNEL_4, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_13, ADC_CHANNEL_5, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_14, ADC_CHANNEL_6, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_15, ADC_CHANNEL_7, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_16, ADC_CHANNEL_8, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                },
                ADC_TEST_MODE_CPU,
                TRUE,
                32,
                0x3FFU,
                0U,
                TRUE,
                100U,
            },
        .testType           = ST_TT_SANITY,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 2U,
        .testCaseName       = "MCU ADC1 all channel all steps cpu mode",
        .disableInfo        = "None",
        .adcConfigParams    =
            {
                CSL_MCU_ADC1_BASE,
                ADC_OPERATION_MODE_SINGLE_SHOT,
                (ADC_INTR_SRC_END_OF_SEQUENCE | ADC_INTR_SRC_FIFO0_OVERRUN |
                ADC_INTR_SRC_FIFO0_UNDERFLOW),
                16,
                {
                    {ADC_STEP_1, ADC_CHANNEL_1, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_2, ADC_CHANNEL_2, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_3, ADC_CHANNEL_3, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_4, ADC_CHANNEL_4, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_5, ADC_CHANNEL_5, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_6, ADC_CHANNEL_6, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_7, ADC_CHANNEL_7, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_8, ADC_CHANNEL_8, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_9, ADC_CHANNEL_1, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_10, ADC_CHANNEL_2, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_11, ADC_CHANNEL_3, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_12, ADC_CHANNEL_4, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_13, ADC_CHANNEL_5, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_14, ADC_CHANNEL_6, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_15, ADC_CHANNEL_7, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_16, ADC_CHANNEL_8, ADC_FIFO_NUM_1, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                },
                ADC_TEST_MODE_CPU,
                TRUE,
                32,
                0x3FFU,
                0U,
                TRUE,
                100U,
            },
        .testType           = ST_TT_SANITY,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3U,
        .testCaseName       = "MCU ADC0 all channel all steps dma mode",
        .disableInfo        = "None",
        .adcConfigParams    =
            {
                CSL_MCU_ADC0_BASE,
                ADC_OPERATION_MODE_SINGLE_SHOT,
                (ADC_INTR_SRC_END_OF_SEQUENCE | ADC_INTR_SRC_FIFO0_OVERRUN |
                ADC_INTR_SRC_FIFO0_UNDERFLOW),
                16,
                {
                    {ADC_STEP_1, ADC_CHANNEL_1, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_2, ADC_CHANNEL_2, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_3, ADC_CHANNEL_3, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_4, ADC_CHANNEL_4, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_5, ADC_CHANNEL_5, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_6, ADC_CHANNEL_6, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_7, ADC_CHANNEL_7, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_8, ADC_CHANNEL_8, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_9, ADC_CHANNEL_1, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_10, ADC_CHANNEL_2, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_11, ADC_CHANNEL_3, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_12, ADC_CHANNEL_4, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_13, ADC_CHANNEL_5, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_14, ADC_CHANNEL_6, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_15, ADC_CHANNEL_7, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                    {ADC_STEP_16, ADC_CHANNEL_8, ADC_FIFO_NUM_0, ADC_AVERAGING_16_SAMPLES,
                    ADC_OPERATION_MODE_SINGLE_SHOT, 0U, ADC_OPENDELAY_MAX, ADC_SAMPLEDELAY_MAX},
                },
                ADC_TEST_MODE_DMA,
                TRUE,
                32,
                0x3FFU,
                0U,
                TRUE,
                100U,
            },
        .testType           = ST_TT_SANITY,
    },
};

#endif /* #ifndef ST_UART_TEST_CASES_H_ */
