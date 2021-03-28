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
 *  \file stw_rtiTestcases.h
 *
 *  \brief This file defines the test cases for RTI UT.
 */

#ifndef STW_RTI_TEST_CASES_H_
#define STW_RTI_TEST_CASES_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_rti.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define RTI_NUM_TESTCASES               (sizeof (gRTITestcaseParams) / sizeof (st_RTITestcaseParams_t))
#define APP_RTI_DWWD_CODE_COVERAGE_TEST (30)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Defines the various RTI test cases. */
st_RTITestcaseParams_t gRTITestcaseParams[] =
{
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 1U,
        .testCaseName       = "MCU RTI0 core interrupt 100% window",
        .disableInfo        = "None",
        .rtiConfigParams    = {
                                CSL_MCU_RTI0_CFG_BASE,
                                RTI_CLOCK_SOURCE_32KHZ,
                                RTI_DWWD_WINDOWSIZE_100_PERCENT,
                                RTI_CORE_INTERRUPT,
                                10000U,
                            },
        .printEnable        = PRINT_ENABLE,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 2U,
        .testCaseName       = "MCU RTI0 core interrupt 50% window",
        .disableInfo        = "None",
        .rtiConfigParams    = {
                                CSL_MCU_RTI0_CFG_BASE,
                                RTI_CLOCK_SOURCE_32KHZ,
                                RTI_DWWD_WINDOWSIZE_50_PERCENT,
                                RTI_CORE_INTERRUPT,
                                10000U,
                            },
        .printEnable        = PRINT_ENABLE,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3U,
        .testCaseName       = "MCU RTI0 core interrupt 25% window",
        .disableInfo        = "None",
        .rtiConfigParams    = {
                                CSL_MCU_RTI0_CFG_BASE,
                                RTI_CLOCK_SOURCE_32KHZ,
                                RTI_DWWD_WINDOWSIZE_25_PERCENT,
                                RTI_CORE_INTERRUPT,
                                10000U,
                            },
        .printEnable        = PRINT_ENABLE,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 4U,
        .testCaseName       = "MCU RTI0 core interrupt 12.5% window",
        .disableInfo        = "None",
        .rtiConfigParams    = {
                                CSL_MCU_RTI0_CFG_BASE,
                                RTI_CLOCK_SOURCE_32KHZ,
                                RTI_DWWD_WINDOWSIZE_12_5_PERCENT,
                                RTI_CORE_INTERRUPT,
                                10000U,
                            },
        .printEnable        = PRINT_ENABLE,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 5U,
        .testCaseName       = "MCU RTI0 core interrupt 6.25% window",
        .disableInfo        = "None",
        .rtiConfigParams    = {
                                CSL_MCU_RTI0_CFG_BASE,
                                RTI_CLOCK_SOURCE_32KHZ,
                                RTI_DWWD_WINDOWSIZE_6_25_PERCENT,
                                RTI_CORE_INTERRUPT,
                                10000U,
                            },
        .printEnable        = PRINT_ENABLE,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 6U,
        .testCaseName       = "MCU RTI0 core interrupt 3.125% window",
        .disableInfo        = "None",
        .rtiConfigParams    = {
                                CSL_MCU_RTI0_CFG_BASE,
                                RTI_CLOCK_SOURCE_32KHZ,
                                RTI_DWWD_WINDOWSIZE_3_125_PERCENT,
                                RTI_CORE_INTERRUPT,
                                10000U,
                            },
        .printEnable        = PRINT_ENABLE,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 10U,
        .testCaseName       = "MCU RTI0 ESM Interrupt",
        .disableInfo        = "None",
        .rtiConfigParams    = {
                                CSL_MCU_RTI0_CFG_BASE,
                                RTI_CLOCK_SOURCE_32KHZ,
                                RTI_DWWD_WINDOWSIZE_50_PERCENT,
                                RTI_ESM_INTERRUPT,
                                10000U,
                            },
        .printEnable        = PRINT_ENABLE,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 20U,
        .testCaseName       = "MCU RTI1 core interrupt 50% window",
        .disableInfo        = "None",
        .rtiConfigParams    = {
                                CSL_MCU_RTI1_CFG_BASE,
                                RTI_CLOCK_SOURCE_32KHZ,
                                RTI_DWWD_WINDOWSIZE_50_PERCENT,
                                RTI_CORE_INTERRUPT,
                                10000U,
                            },
        .printEnable        = PRINT_ENABLE,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 21U,
        .testCaseName       = "MCU RTI1 ESM Interrupt",
        .disableInfo        = "None",
        .rtiConfigParams    = {
                                CSL_MCU_RTI1_CFG_BASE,
                                RTI_CLOCK_SOURCE_32KHZ,
                                RTI_DWWD_WINDOWSIZE_50_PERCENT,
                                RTI_ESM_INTERRUPT,
                                10000U,
                            },
        .printEnable        = PRINT_ENABLE,
    },
     {
         .enableTest         = TEST_ENABLE,
         .testcaseId         = APP_RTI_DWWD_CODE_COVERAGE_TEST, /* 0x30u */
         .testCaseName       = "MCU RTI-DWWD Code Coverage",
         .disableInfo        = "None",
         .rtiConfigParams    = {
                                 CSL_MCU_RTI1_CFG_BASE,
                                 RTI_CLOCK_SOURCE_32KHZ,
                                 RTI_DWWD_WINDOWSIZE_50_PERCENT,
                                 RTI_CORE_INTERRUPT,
                                 10000U,
                             },
         .printEnable        = PRINT_ENABLE,
     }

};

#endif /* #ifndef ST_UART_TEST_CASES_H_ */
