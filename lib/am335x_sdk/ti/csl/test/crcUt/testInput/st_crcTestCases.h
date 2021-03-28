/*
 *  Copyright (C) 2019 Texas Instruments Incorporated
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
 */

/**
 *  \file stw_crcTestcases.h
 *
 *  \brief This file defines the test cases for CRC UT.
 */

#ifndef STW_CRC_TEST_CASES_H_
#define STW_CRC_TEST_CASES_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include<string.h>
#include <st_crc.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define CRC_NUM_TESTCASES   (sizeof (gCRCTestcaseParams) / sizeof (st_CRCTestcaseParams_t))

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Defines the various CRC test cases. */
st_CRCTestcaseParams_t gCRCTestcaseParams[] =
{
    /* enableTest, testCaseId,
     * testCaseFxnPtr,
     * *reqId,
     * *testCaseName,
     * *disableReason
     * dataSize,
     * sourceMemory,
     * crcConfigParams,
     * printEnable,
     * testType,
     */
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3734U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "mcu navss mcrc full cpu 720p framesize",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_720P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_MCU_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_1,
                                (uint32_t) CRC_OPERATION_MODE_FULLCPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0xf2c2e9eeU,
                                0xebeb19c1U,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3735U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "navss mcrc full cpu 720p framesize",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_720P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_1,
                                (uint32_t) CRC_OPERATION_MODE_FULLCPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0xf2c2e9eeU,
                                0xebeb19c1U,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3736U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "mcu navss mcrc semi cpu small framesize",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_SMALL_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_MCU_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_1,
                                (uint32_t) CRC_OPERATION_MODE_SEMICPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0x18633761U,
                                0x83A8C73AU,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3737U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "navss mcrc semi cpu small framesize",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_SMALL_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_1,
                                (uint32_t) CRC_OPERATION_MODE_SEMICPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0x18633761U,
                                0x83A8C73AU,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3738U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "mcu navss mcrc semi cpu 720p framesize",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_720P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_MCU_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_1,
                                (uint32_t) CRC_OPERATION_MODE_SEMICPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0xf2c2e9eeU,
                                0xebeb19c1U,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3739U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "navss mcrc semi cpu 720p framesize",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_720P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_1,
                                (uint32_t) CRC_OPERATION_MODE_SEMICPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0xf2c2e9eeU,
                                0xebeb19c1U,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3740U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "mcu navss mcrc ch2 full cpu 720p framesize",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_720P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_MCU_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_2,
                                (uint32_t) CRC_OPERATION_MODE_FULLCPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0xf2c2e9eeU,
                                0xebeb19c1U,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3741U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "mcu navss mcrc ch3 full cpu 720p framesize",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_720P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_MCU_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_3,
                                (uint32_t) CRC_OPERATION_MODE_FULLCPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0xf2c2e9eeU,
                                0xebeb19c1U,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3742U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "mcu navss mcrc ch4 full cpu 720p framesize",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_720P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_MCU_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_4,
                                (uint32_t) CRC_OPERATION_MODE_FULLCPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0xf2c2e9eeU,
                                0xebeb19c1U,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3743U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "mcu navss mcrc semi cpu pat size 8",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_720P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_MCU_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_1,
                                (uint32_t) CRC_OPERATION_MODE_SEMICPU,
                                8U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0x8bacd4feU,
                                0x10598f29U,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3744U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "navss mcrc semi cpu 720p pat size 8",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_720P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_1,
                                (uint32_t) CRC_OPERATION_MODE_SEMICPU,
                                8U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0x8bacd4feU,
                                0x10598f29U,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3745U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "navss mcrc full cpu Msmc buf",
        .disableReason      = NULL,
        .dataSize           = CRC_MSMC_BUF_MAX_SIZE,
        .sourceMemory       = (uint32_t) &gMsmcCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_1,
                                (uint32_t) CRC_OPERATION_MODE_FULLCPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0x958b7a02U,
                                0x1871ec9aU,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3746U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "navss mcrc semi cpu Msmc buf",
        .disableReason      = NULL,
        .dataSize           = CRC_MSMC_BUF_MAX_SIZE,
        .sourceMemory       = (uint32_t) &gMsmcCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_1,
                                (uint32_t) CRC_OPERATION_MODE_SEMICPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0x958b7a02U,
                                0x1871ec9aU,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 3747U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "navss mcrc semi cpu DDR 1080P buf",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_1080P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_NAVSS0_MCRC_BASE,
                                (uint32_t) CRC_CHANNEL_1,
                                (uint32_t) CRC_OPERATION_MODE_SEMICPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0xff441b4dU,
                                0xc8e87dbaU,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 8000U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "mcrc full cpu 4 channels DDR 1080P buf",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_1080P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_NAVSS0_MCRC_BASE,
                                /* test all the channels if crcChannelNumber set to 0 */
                                (uint32_t) 0U,
                                (uint32_t) CRC_OPERATION_MODE_FULLCPU,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0xff441b4dU,
                                0xc8e87dbaU,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY | ST_TT_PERFORMANCE),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 8001U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "mcrc data capture DDR 1080P buf",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_1080P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_NAVSS0_MCRC_BASE,
                                /* test all the channels if crcChannelNumber set to 0 */
                                (uint32_t) 0U,
                                (uint32_t) CRC_OPERATION_MODE_DATA,
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0U,
                                0U,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY),
    },
    {
        .enableTest         = TEST_ENABLE,
        .testcaseId         = 8002U,
        .testCaseFxnPtr     = &crcRunTestcase,
        .testCaseName       = "mcrc code cover test",
        .disableReason      = NULL,
        .dataSize           = CRC_DDR_1080P_BUF_SIZE,
        .sourceMemory       = (uint32_t) &gDdrCrcSrcBuffer[0],
        .crcConfigParams    = {
                                CSL_NAVSS0_MCRC_BASE,
                                /* test all the channels if crcChannelNumber set to 0 */
                                (uint32_t) 0U,
                                /* invalid op mode triggers code coverage test */
                                (uint32_t) (CRC_CTRL2_CH1_MODE_FULLCPU + 1U),
                                4U,
                                DEF_CRC_PATTERN_COUNT,
                                DEF_CRC_SECTOR_COUNT,
                                DEF_CRC_WATCHDOG_PRELOAD,
                                DEF_CRC_BLOCK_PRELOAD,
                                0U,
                                0U,
                            },
        .printEnable        = PRINT_ENABLE,
        .testType           = (ST_TT_SANITY),
    },
};

#endif /* #ifndef ST_UART_TEST_CASES_H_ */

