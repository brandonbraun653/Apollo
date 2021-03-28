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
 *  \file stw_dccTestcases.h
 *
 *  \brief This file defines the test cases for DCC UT.
 */

#ifndef STW_DCC_TEST_CASES_H_
#define STW_DCC_TEST_CASES_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_dcc.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define DCC_NUM_TESTCASES               (sizeof (gDCCTestcaseParams) / sizeof (st_DCCTestcaseParams_t))

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Defines the various DCC test cases. */
st_DCCTestcaseParams_t gDCCTestcaseParams[] =
{
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3698U,
        .testCaseName       = "module: mcudcc0 DCCCLKSRC0_0  DCCCLKSRC1_0",
        .disableInfo        = "None",
        .dccConfigParams    = {
                                DEF_DCC_MODULE,
                                DCC_DCCCLKSRC0_CLKSRC0_0,
                                DCC_DCCCLKSRC1_CLKSRC_0,
                                DEF_DCC_CLK_SRC1_ALT_CLK,
                                DEF_DCC_SEED_SRC0,
                                DEF_DCC_SEED_VALID0,
                                DEF_DCC_SEED_SRC1,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = ST_TT_SANITY,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3699U,
        .testCaseName       = "module: mcudcc0 DCCCLKSRC0_0  DCCCLKSRC1_1",
        .disableInfo        = "None",
        .dccConfigParams    = {
                                DEF_DCC_MODULE,
                                DCC_DCCCLKSRC0_CLKSRC0_0,
                                DCC_DCCCLKSRC1_CLKSRC_1,
                                DEF_DCC_CLK_SRC1_ALT_CLK,
                                DEF_DCC_SEED_SRC0,
                                DEF_DCC_SEED_VALID0,
                                DEF_DCC_SEED_SRC1,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = ST_TT_SANITY,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3700U,
        .testCaseName       = "module: mcudcc0 DCCCLKSRC0_0  DCCCLKSRC1_2",
        .disableInfo        = "None",
        .dccConfigParams    = {
                                DEF_DCC_MODULE,
                                DCC_DCCCLKSRC0_CLKSRC0_0,
                                DCC_DCCCLKSRC1_CLKSRC_2,
                                DEF_DCC_CLK_SRC1_ALT_CLK,
                                DEF_DCC_SEED_SRC0,
                                DEF_DCC_SEED_VALID0,
                                DEF_DCC_SEED_SRC1,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = ST_TT_SANITY,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3701U,
        .testCaseName       = "module: mcudcc0 DCCCLKSRC0_0  DCCCLKSRC1_3",
        .disableInfo        = "None",
        .dccConfigParams    = {
                                DEF_DCC_MODULE,
                                DCC_DCCCLKSRC0_CLKSRC0_0,
                                DCC_DCCCLKSRC1_CLKSRC_3,
                                DEF_DCC_CLK_SRC1_ALT_CLK,
                                DEF_DCC_SEED_SRC0,
                                DEF_DCC_SEED_VALID0,
                                DEF_DCC_SEED_SRC1,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = ST_TT_SANITY,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3702U,
        .testCaseName       = "module: mcudcc0 DCCCLKSRC0_0  DCCCLKSRC1_4",
        .disableInfo        = "None",
        .dccConfigParams    = {
                                DEF_DCC_MODULE,
                                DCC_DCCCLKSRC0_CLKSRC0_0,
                                DCC_DCCCLKSRC1_CLKSRC_4,
                                DEF_DCC_CLK_SRC1_ALT_CLK,
                                DEF_DCC_SEED_SRC0,
                                DEF_DCC_SEED_VALID0,
                                DEF_DCC_SEED_SRC1,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = ST_TT_SANITY,
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3703U,
        .testCaseName       = "module: dcc0 DCCCLKSRC0_0  DCCCLKSRC1_0",
        .disableInfo        = "None",
        .dccConfigParams    = {
                                CSL_DCC0_BASE,
                                DCC_DCCCLKSRC0_CLKSRC0_0,
                                DCC_DCCCLKSRC1_CLKSRC_0,
                                DEF_DCC_CLK_SRC1_ALT_CLK,
                                DEF_DCC_SEED_SRC0,
                                DEF_DCC_SEED_VALID0,
                                DEF_DCC_SEED_SRC1,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = ST_TT_SANITY,
    },
};

#endif /* #ifndef ST_UART_TEST_CASES_H_ */
