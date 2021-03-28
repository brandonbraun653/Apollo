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
 *  \file st_dcc.h
 *
 *  \brief This file contains all the structures, macros, enums
 *  used by the DCC UT applications.
 */

#ifndef STW_DCC_H_
#define STW_DCC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <ti/csl/csl_dcc.h>
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

/*      Default values      */
#define DEF_DCC_MODULE                  ((uint32_t)CSL_MCU_DCC0_BASE)
#define DEF_DCC_CLK_SRC0                ((uint32_t)DCC_CLK_SRC0_SYS_CLK1)
#define DEF_DCC_CLK_SRC1                ((uint32_t)DCC_CLK_SRC1_DCC1_DPLLCORE_H12)
#define DEF_DCC_CLK_SRC1_ALT_CLK        ((uint32_t)FALSE)
#define DEF_DCC_SEED_SRC0               ((uint32_t)900U)
#define DEF_DCC_SEED_VALID0             ((uint32_t)200U)
#define DEF_DCC_SEED_SRC1               ((uint32_t)1000U)

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

/**
 *  \brief DCC configuration parameter structure.
 */
typedef struct
{
    uint32_t                   dccModule;
    /**< DCC module instance. */
    uint32_t                   dccClkSrc0;
    /**< Clock source for COUNT0 i.e. reference clock. */
    uint32_t                   dccClkSrc1;
    /**< Clock source for COUNT1 i.e. clock signal to be tested.*/
    uint32_t                   alternateClkSrc1;
    /**< Select alternate clock source */
    uint32_t                   dccSeedSrc0;
    /**< Preload value/seed value for COUNT0 */
    uint32_t                   dccSeedValid0;
    /**< Preload value/seed value for VALID0 */
    uint32_t                   dccSeedSrc1;
    /**< Preload value/seed value for COUNT1 */
} stw_DCCConfigParams_t;

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
    stw_DCCConfigParams_t   dccConfigParams;
    /**< DCC Mode. */
    uint32_t                dccMode;
    /**< DCC configuration parameters Refer struct #stw_DCCConfigParams_t. */
    Bool                    printEnable;
    /**< Enable/disable print statements, used for stress testing. */
    uint32_t                testType;
    /**< Type of test  - like BFT, stress etc... */
    /*
     * Below variables are initialized in code and not in table!!
     */
    int32_t                 isRun;
    /**< Flag to indicate whether the test case is run or not. */
    Int32                   testResult;
    /**< Test result. */
} st_DCCTestcaseParams_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   This API to enable the clock for DCC module.
 *
 * \param   module          DCC module to enable.
 *
 * \retval  status          configuration status.
 */
int32_t DCCClockEnable(uint32_t module);

/**
 * \brief   This function returns seed value for COUNT1.
 *
 * \param   testClk          Reference clock frequency in KHz.
 *
 * \param   testClkCnt       Reference clock seed count.
 *
 * \retval  seed value       seed count for COUNT1.
 */
uint32_t DCCAppGetSrc1SeedVal(uint32_t testClk,
                              uint32_t refClkCnt,
                              uint32_t testClkFreq);

/**
 * \brief   This functions returns the frequency of reference and test clock.
 *
 * \param   dccInst          DCC instance used.
 *
 * \param   clk0Src          Reference clock source.
 *
 * \param   clk0Freq         Reference clock frequency.
 *
 * \param   clk1Src          Test clock source.
 *
 * \param   clk1Freq         Test clock frequency.
 *
 * \retval  status           status of operation.
 */
int32_t DCCAppGetTestClkfreqKHz(uint32_t dccInst,
                                 uint32_t clk0Src, uint32_t *clk0Freq,
                                 uint32_t clk1Src, uint32_t *clk1Freq);

/**
 * \brief   This functions enables the ESM module.
 *
 * \param   esmInst          esm instance used.
 *
 * \param   esmEvtNum        esm event number.
 *
 */
void DCCAppEnableEsm(uint32_t esmInst, uint32_t esmEvtNum);

/**
 * \brief   This functions starts dcc operation in single shot mode.
 *
 * \param   testParams          dcc test parameter.
 *
 */
void st_dccSingleShot_main(st_DCCTestcaseParams_t *testParams);

/**
 * \brief   This functions starts dcc operation in continuous mode.
 *
 * \param   testParams          dcc test parameter.
 *
 */
void st_cont_main(st_DCCTestcaseParams_t *testParams);


#ifdef __cplusplus
}

#endif /*extern "C" */

#endif
