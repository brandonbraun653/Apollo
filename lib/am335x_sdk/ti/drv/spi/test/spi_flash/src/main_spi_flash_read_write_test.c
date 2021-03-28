/**
 *  \file   main_spi_flash_read_write.c
 *
 *  \brief  Example application main file. This application will write and read
 *          the data to/from SPI_NOR flash through Board flash interface.
 *
 */

/*
 * Copyright (C) 2015 - 2017 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef BARE_METAL
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <stdio.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#endif

/* SPI Header files */
#include <ti/drv/spi/SPI.h>
#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2E) || defined(SOC_K2L) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657)
#include <ti/drv/spi/src/v0/SPI_v0.h>
#endif
#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/drv/spi/test/src/SPI_log.h>
#include <ti/drv/spi/test/src/SPI_test.h>

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
uint8_t txBuf[TEST_TX_LENGTH];

/* Buffer containing the received data */
uint8_t rxBuf[TEST_TX_LENGTH];

/* transfer length */
uint32_t transferLength;

/*
 *  ======== Board_initSPI ========
 */
void Board_initSPI(void)
{
    Board_initCfg boardCfg;
#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2E) || defined(SOC_K2L) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657)
    SPI_v0_HWAttrs spi_cfg;
    Board_SoCInfo socInfo;

    /* Get the default SPI init configurations */
    SPI_socGetInitCfg(TEST_SPI_PORT, &spi_cfg);

    /* Update the SPI functional clock based on CPU clock*/
    Board_getSoCInfo(&socInfo);
    if(socInfo.sysClock != BOARD_SYS_CLK_DEFAULT)
    {
        spi_cfg.inputClkFreq = socInfo.sysClock/SPI_MODULE_CLOCK_DIVIDER;
    }

    /* Set the default SPI init configurations */
    SPI_socSetInitCfg(TEST_SPI_PORT, &spi_cfg);
#endif

#if defined(evmK2E) || defined(evmC6678)
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);
}


/*
 *  ======== test function ========
 */
#ifdef BARE_METAL
void main()
#else
void spi_test(UArg arg0, UArg arg1)
#endif
{
    Board_flashHandle  boardHandle;
    Board_FlashInfo   *flashInfo;
    uint32_t           blockNum, pageNum;
    SPI_Params         spiParams;  /* SPI params structure */
    bool               testPassed = true;

#ifdef BARE_METAL
    /* Call board init functions */
    Board_initSPI();
#endif

    /* Open the Board flash NOR device with test SPI port
       and use the default SPI configurations */
    SPI_Params_init(&spiParams);
    spiParams.frameFormat  = SPI_POL0_PHA1;
    boardHandle = Board_flashOpen(TEST_NOR_DEV_ID,
                                  TEST_SPI_PORT,
                                  (void *)(&spiParams));
    if (!boardHandle)
    {
        SPI_log("\n Board_flashOpen failed. \n");
        goto err;
    }
    else
    {
        flashInfo = (Board_FlashInfo *)boardHandle;
        SPI_log("\n SPI NOR device ID: 0x%x, manufacturer ID: 0x%x \n",
                flashInfo->device_id, flashInfo->manufacturer_id);
    }

    if (Board_flashOffsetToBlkPage(boardHandle, TEST_NOR_ADDR,
                                   &blockNum, &pageNum))
    {
        SPI_log("\n Board_flashOffsetToBlkPage failed. \n");
        testPassed = false;
        goto err;
    }

    /* Set the transfer length in number of 32 bit words */
    transferLength = TEST_TX_LENGTH;

    /* Generate the data */
    GeneratePattern(txBuf, rxBuf, transferLength);

#ifdef TEST_SPI_NOR_WRITE
    /* Erase block, to which data has to be written */
    if (Board_flashEraseBlk(boardHandle, blockNum))
    {
        SPI_log("\n Board_flashEraseBlk failed. \n");
        testPassed = false;
        goto err;
    }

    /* Write buffer to flash */
    if (Board_flashWrite(boardHandle, TEST_NOR_ADDR, txBuf,
                         TEST_TX_LENGTH, NULL))
    {
        SPI_log("\n Board_flashWrite failed. \n");
        testPassed = false;
        goto err;
    }
#endif

    /* Read data from flash */
    if (Board_flashRead(boardHandle, TEST_NOR_ADDR, (uint8_t *)&rxBuf[0],
                        TEST_TX_LENGTH, NULL))
    {
        SPI_log("\n Board_flashRead failed. \n");
        testPassed = false;
        goto err;
    }

#ifndef TEST_SPI_NOR_WRITE
    /* if no write test, copy rxBuf to txBuf to pass the test */
    memcpy(txBuf, rxBuf, transferLength);
#endif

    /* Verify Data */
    if (VerifyData(txBuf, rxBuf, transferLength) == false)
    {
        SPI_log("\n Data mismatch. \n");
        testPassed = false;
    }

    Board_flashClose(boardHandle);

err:
    if(true == testPassed)
    {
        SPI_log("\n All tests have passed. \n");
    }
    else
    {
        SPI_log("\n Some tests have failed. \n");
    }

    while(1);
}

/*
 *  ======== main ========
 */
#ifndef BARE_METAL
int main(void)
{
    /* Call board init functions */
    Board_initSPI();

    /* Start BIOS */
    BIOS_start();
    return (0);
}
#endif

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
