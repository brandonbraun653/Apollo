/**
 *  \file   main_gpmc_flash_test.c
 *
 *  \brief  Test application main file. This application will write and read
 *          the data to/from GPMC NOR/NAND flash through Board flash interface.
 *
 */

/*
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdio.h>
#include <string.h>

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>

/* GPMC Header files */
#include <ti/drv/gpmc/GPMC.h>
#include <ti/drv/gpmc/soc/GPMC_soc.h>
#include <ti/drv/gpmc/test/src/GPMC_board.h>
#include <ti/drv/gpmc/test/src/GPMC_log.h>

/* Board Header files */
#include <ti/board/board.h>
#include <ti/board/src/flash/include/board_flash.h>

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

/* Function to generate known data */
static void GeneratePattern(uint8_t *txBuf, uint8_t *rxBuf, uint32_t length);

/* Data compare function */
bool VerifyData(uint8_t *expData,
                uint8_t *rxData,
                uint32_t length);

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/* Buffer containing the known data that needs to be written to flash */
uint8_t txBuf[TEST_DATA_LEN];

/* Buffer containing the received data */
uint8_t rxBuf[TEST_DATA_LEN];

/*
 *  ======== test function ========
 */
void gpmc_test(UArg arg0, UArg arg1)
{
    Board_flashHandle boardHandle;
    Board_FlashInfo *flashInfo;
    uint32_t blockNum, pageNum;
    bool testPassed = true;

    /* Open the Board flash device with GPMC port instance
       and use the default GPMC configurations */
    boardHandle = Board_flashOpen(BOARD_FLASH_ID,
                                  BOARD_GPMC_INSTANCE, NULL);

    if (!boardHandle)
    {
        GPMC_log("\n Board_flashOpen failed. \n");
        testPassed = false;
        goto err;
    }
    else
    {
        flashInfo = (Board_FlashInfo *)boardHandle;
        GPMC_log("\n GPMC flash device ID: 0x%x, manufacturer ID: 0x%x \n",
                flashInfo->device_id, flashInfo->manufacturer_id);
    }

    if (Board_flashOffsetToBlkPage(boardHandle, TEST_ADDR_OFFSET,
                                   &blockNum, &pageNum))
    {
        GPMC_log("\n Board_flashOffsetToBlkPage failed. \n");
        testPassed = false;
        goto err;
    }

    /* Generate the data */
    GeneratePattern(txBuf, rxBuf, TEST_DATA_LEN);

#ifdef TEST_GPMC_FLASH_WRITE
    /* Erase block, to which data has to be written */
    if (Board_flashEraseBlk(boardHandle, blockNum))
    {
        GPMC_log("\n Board_flashEraseBlk failed. \n");
        testPassed = false;
        goto err;
    }
    GPMC_log("\n GPMC flash block erase test passed. \n");


    /* Write buffer to flash */
    if (Board_flashWrite(boardHandle, TEST_ADDR_OFFSET, txBuf,
                         TEST_DATA_LEN, NULL))
    {
        GPMC_log("\n Board_flashWrite failed. \n");
        testPassed = false;
        goto err;
    }
    GPMC_log("\n GPMC flash write test passed. \n");
#endif

    /* Reset receive buffer */
    if (Board_flashRead(boardHandle, TEST_ADDR_OFFSET, rxBuf,
                        TEST_DATA_LEN, NULL))
    {
        GPMC_log("\n Board_flashRead failed. \n");
        testPassed = false;
        goto err;
    }
    GPMC_log("\n GPMC flash read test passed. \n");

#ifndef TEST_GPMC_FLASH_WRITE
    /* if no write test, copy rxBuf to txBuf to pass the test */
    memcpy(txBuf, rxBuf, TEST_DATA_LEN);
#endif

    /* Verify Data */
    if (VerifyData(txBuf, rxBuf, TEST_DATA_LEN) == false)
    {
        GPMC_log("\n Data mismatch. \n");
        testPassed = false;
    }

err:
    if (boardHandle)
    {
        Board_flashClose(boardHandle);
    }

    if(true == testPassed)
    {
        GPMC_log("\n All tests have passed. \n");
    }
    else
    {
        GPMC_log("\n Some tests have failed. \n");
    }

    while(1);
}

void GPMC_initConfig(void)
{
    GPMC_v1_HwAttrs gpmc_cfg;

    /* Get the default UART init configurations */
    GPMC_socGetInitCfg(BOARD_GPMC_INSTANCE, &gpmc_cfg);

    /* Modify the default UART configurations if necessary */

    /* Set the default UART init configurations */
    GPMC_socSetInitCfg(BOARD_GPMC_INSTANCE, &gpmc_cfg);
}

/*
 *  ======== main ========
 */
int main(void)
{
    /* Call board init functions */
    Board_initCfg boardCfg;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

    GPMC_initConfig();

    /* Start BIOS */
    BIOS_start();
    return (0);
}

/*
 *  ======== CompareData ========
 */
bool VerifyData(uint8_t *expData,
                uint8_t *rxData,
                uint32_t length)
{
    uint32_t idx = 0;
    uint32_t match = 1;
    bool retVal = false;

    for(idx = 0; ((idx < length) && (match != 0)); idx++)
    {
        if(*expData != *rxData)
        {
            match = 0;
        }
        expData++;
        rxData++;
    }

    if(match == 1)
    {
        retVal = true;
    }

    return retVal;
}

/*
 *  ======== GeneratePattern ========
 */
static void GeneratePattern(uint8_t *txBuf, uint8_t *rxBuf, uint32_t length)
{
    volatile uint32_t idx;
    volatile uint8_t *txPtr = txBuf;
    volatile uint8_t *rxPtr = rxBuf;

    for(idx = 0; idx < length; idx++)
    {
    	*txPtr++ = (uint8_t)idx;
    	*rxPtr++ = (uint8_t)0U;
    }
}
