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
 *  \file st_adc.h
 *
 *  \brief This file contains all the structures, macros, enums
 *  used by the ADC UT applications.
 */

#ifndef ST_ADC_H_
#define ST_ADC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <ti/csl/csl_adc.h>
#include <ti/csl/soc.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>
#include <ti/osal/osal.h>
#include <ti/csl/csl_esm.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
#define TEST_ENABLE                     (TRUE)
#define TEST_DISABLE                    (FALSE)
#define PRINT_ENABLE                    (TRUE)
#define PRINT_DISABLE                   (FALSE)

#define ADC_TEST_MODE_CPU               (0U)
#define ADC_TEST_MODE_DMA               (1U)
/*      Default values      */
#define DEF_ADC_MODULE                  ((uint32_t)CSL_MCU_ADC0_BASE)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/**
 *  \brief Test types.
 */
typedef enum
{
    ST_TT_SANITY      = 0x01,
    ST_TT_REGRESSION  = 0x02,
    ST_TT_FULL        = 0x04,
    ST_TT_FUNCTIONAL  = 0x08,
    ST_TT_STRESS      = 0x10,
    ST_TT_NEGATIVE    = 0x20,
    ST_TT_PERFORMANCE = 0x40,
    ST_TT_MISC        = 0x80,
    ST_TT_API         = 0x100
} st_TestType;

typedef struct
{
    uint32_t    stepId;
    uint32_t    channel;
    uint32_t    fifoNum;
    uint32_t    averaging;
    uint32_t    mode;
    uint32_t    rangeCheckEnable;
    uint32_t    openDelay;
    uint32_t    sampleDelay;
} stw_ADCStepConfigParams_t;
/**
 *  \brief ADC configuration parameter structure.
 */
typedef struct
{
    uint32_t    adcModule;
    /**< ADC module instance. */
    uint32_t    adcMode;
    /**< ADC operational mode. */
    uint32_t    intrEnable;
    /**< Interrupts to enable.*/
    uint32_t    numSteps;
    stw_ADCStepConfigParams_t adcSteps[16];
    /**< Step to configure. */
    uint32_t    testMode;
    uint32_t    fifoEnable;
    uint32_t    fifoThreshold;
    uint32_t    highRange;
    /**< Upper limit for conversion. */
    uint32_t    lowRange;
    /**< Lower limit for conversion. */
    uint32_t    stepIdTagEnable;
    /**< Enable/disable step ID tagging. */
    uint32_t    errOffset;
    /**< Allowed offset in measured voltage. */
} stw_ADCConfigParams_t;

/**
 *  \brief Test case parameter structure.
 */
typedef struct
{
    Bool                    enableTest;
    /**< Whether test case should be executed or not. */
    uint32_t                testcaseId;
    /**< Test case ID. */
    char                    *testCaseName;
    /**< Test case name. */
    char                    *disableInfo;
    /**< Reason string for disabling a test case. */
    stw_ADCConfigParams_t   adcConfigParams;
    /**< ADC Mode. */
    uint32_t                adcMode;
    /**< ADC configuration parameters Refer struct #stw_ADCConfigParams_t. */
    uint32_t                testType;
    /**< Type of test  - like BFT, stress etc... */
    /*
     * Below variables are initialized in code and not in table!!
     */
    int32_t                 isRun;
    /**< Flag to indicate whether the test case is run or not. */
    Int32                   testResult;
    /**< Test result. */
} st_ADCTestcaseParams_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   Parse the testcase data
 *
 * \param   None.
 *
 * \return  None
 */
int32_t adcParser(void);

int32_t st_adcCpuMode_main(st_ADCTestcaseParams_t *testParams);
int32_t st_adcDmaMode_main(st_ADCTestcaseParams_t *testParams);

int32_t st_adcDmaInit(void);
int32_t st_adcDmaDeinit(void);

int32_t st_adcModuleInit(uint32_t adcModule);
void st_adcModuleDeinit(uint32_t adcModule);
int32_t st_adcStepConfig(st_ADCTestcaseParams_t *testParams);

void st_adcModuleStart(uint32_t adcModule);
void st_adcModuleStop(st_ADCTestcaseParams_t *testParams);

int32_t st_adcValidateFifoData(st_ADCTestcaseParams_t *testParams, uint32_t *adcDataBuff, uint32_t numSamples);

#ifdef __cplusplus
}

#endif /*extern "C" */

#endif
