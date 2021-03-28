/*
 *  Copyright (c) 2019 Texas Instruments Incorporated
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
 *  \file st_rti.h
 *
 *  \brief This file contains all the structures, macros, enums
 *  used by the RTI UT applications.
 */

#ifndef STW_RTI_H_
#define STW_RTI_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <ti/csl/csl_rti.h>
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

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/**
 * \brief  Enum to select the clock source for RTI module.
 */
typedef enum rtiClockSource
{
    RTI_CLOCK_SOURCE_HFOSC0_CLKOUT = 0U,
    /**< to select clock frequency of hfosc0 */
    RTI_CLOCK_SOURCE_LFOSC_CLKOUT = 1U,
    /**< to select clock frequency of lfosc */
    RTI_CLOCK_SOURCE_12MHZ = 2U,
    /**< to select clock frequency of 12 MHz */
    RTI_CLOCK_SOURCE_32KHZ = 3U,
    /**< to select clock frequency of 32KHz */
}rtiClockSource_t;

/**
 * \brief  Enum to select the clock source for RTI module.
 */
typedef enum rtiIntrType
{
    RTI_CORE_INTERRUPT = 0U,
    /**< route RTI interrupt to core */
    RTI_ESM_INTERRUPT  = 1U,
    /**< route RTI interrupt to ESM */
}rtiIntrType_t;

/**
 *  \brief RTI configuration parameter structure.
 */
typedef struct
{
    uint32_t                   rtiModule;
    /**< RTI module instance base address. */
    uint32_t                   rtiClkSrc;
    /**< RTI clock source. */
    uint32_t                   dwwdWindowSize;
    /**< RTI window size to configure. */
    rtiIntrType_t              rtiIntrType;
    /**< RTI timeout reaction. */
    uint32_t                   rtiTimeoutVal;
    /**< RTI timeout value. */
} stw_RTIConfigParams_t;

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
    stw_RTIConfigParams_t   rtiConfigParams;
    /**< RTI configuration parameters Refer struct #stw_RTIConfigParams_t. */
    Bool                    printEnable;
    /**< Enable/disable print statements, used for stress testing. */
    /*
     * Below variables are initialized in code and not in table!!
     */
    int32_t                 isRun;
    /**< Flag to indicate whether the test case is run or not. */
    Int32                   testResult;
    /**< Test result. */
} st_RTITestcaseParams_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   Entry function of the parser.
 *
 * \retval  returns unit test status.
 */
int32_t rtiParser(void);

/**
 * \brief   Main function for rti single shot tests.
 *
 * \param   testParams      test parameters from st_RTITestcaseParams_t
 *
 * \retval  test case status.
 */
int32_t st_rtiSingleShot_main(st_RTITestcaseParams_t *testParams);

/**
 * \brief   RTI DWWD Code coverage test functions
 *
 * \param   testParams        structure to details of testcase to run.
 *
 * \return  test status.
 */
int32_t st_rtiCodeCoverage_main(st_RTITestcaseParams_t *testParams);


#ifdef __cplusplus
}

#endif /*extern "C" */

#endif
