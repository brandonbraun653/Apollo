/**
 *  \file   main_qspi_flash_read_write_board.c
 *
 *  \brief  Example application main file. This application will write and read
 *          the data to/from QSPI NOR flash through board flash interface.
 *
 */

/*
 * Copyright (C) 2016 - 2017 Texas Instruments Incorporated - http://www.ti.com/
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


/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <stdio.h>
#include <ti/sysbios/knl/Task.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <xdc/runtime/Error.h>

/* TI-RTOS Header files */
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/drv/spi/test/qspi_flash/src/QSPI_board.h>
#include <ti/drv/spi/test/qspi_flash/src/SPI_log.h>

#include <ti/board/board.h>
#include <ti/board/src/flash/include/board_flash.h>

#include <ti/csl/csl_psc.h>
#include <ti/csl/csl_pscAux.h>

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
uint8_t txBuf[1024];

/* Buffer containing the received data */
uint8_t rxBuf[1024];

void QSPI_clkEnable(bool enable)
{
#if defined(evmK2G) || defined(iceK2G)
    if (enable == false)
    {
        /* Set NSS Power domain to ON */
        CSL_PSC_disablePowerDomain (CSL_PSC_PD_SYS_COMP);
    }
    else
    {
        /* Set NSS Power domain to ON */
        CSL_PSC_enablePowerDomain (CSL_PSC_PD_SYS_COMP);

        /* Enable the clocks for NSS modules */
        CSL_PSC_setModuleNextState (CSL_PSC_LPSC_QSPI, PSC_MODSTATE_ENABLE);

        /* Start the state transition */
        CSL_PSC_startStateTransition (CSL_PSC_PD_SYS_COMP);

        /* Wait until the state transition process is completed. */
        while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_SYS_COMP));
    }
#endif
}

/*
 *  ======== test function ========
 */
void spi_test(UArg arg0, UArg arg1)
{
    Board_flashHandle boardHandle;
    Board_FlashInfo *flashInfo;
    uint32_t blockNum, pageNum;      /* Block, page number */
    bool testPassed = true;          /* return value */
    uint32_t ioMode;

    /* Open the Board QSPI NOR device with QSPI port 0
       and use default QSPI configurations */
    boardHandle = Board_flashOpen(BOARD_FLASH_ID_QSPIFLASH_S25FL512S,
                                  BOARD_QSPI_NOR_INSTANCE, NULL);

    if (!boardHandle)
    {
        SPI_log("\n Board_flashOpen failed. \n");
        goto err;
    }
    else
    {
        flashInfo = (Board_FlashInfo *)boardHandle;
        SPI_log("\n QSPI NOR device ID: 0x%x, manufacturer ID: 0x%x \n",
                flashInfo->device_id, flashInfo->manufacturer_id);
    }

    ioMode = BOARD_FLASH_QSPI_IO_MODE_QUAD;

    if (Board_flashOffsetToBlkPage(boardHandle, TEST_ADDR_OFFSET,
                                   &blockNum, &pageNum))
    {
        SPI_log("\n Board_flashOffsetToBlkPage failed. \n");
        testPassed = false;
        goto err;
    }

    /* Erase block, to which data has to be written */
    if (Board_flashEraseBlk(boardHandle, blockNum))
    {
        SPI_log("\n Board_flashEraseBlk failed. \n");
        testPassed = false;
        goto err;
    }

    /* Generate the data */
    GeneratePattern(txBuf, rxBuf, TEST_DATA_LEN);

    /* Write buffer to flash */
    if (Board_flashWrite(boardHandle, TEST_ADDR_OFFSET, txBuf,
                         TEST_DATA_LEN, (void *)(&ioMode)))
    {
        SPI_log("\n Board_flashWrite failed. \n");
        testPassed = false;
        goto err;
    }

    /* Reset receive buffer */
    if (Board_flashRead(boardHandle, TEST_ADDR_OFFSET, rxBuf,
                        TEST_DATA_LEN, (void *)(&ioMode)))
    {
        SPI_log("\n Board_flashRead failed. \n");
        testPassed = false;
        goto err;
    }

    /* Verify Data */
    if (VerifyData(txBuf, rxBuf, TEST_DATA_LEN) == false)
    {
        SPI_log("\n Data mismatch. \n");
        testPassed = false;
        goto err;
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

void QSPI_initConfig(void)
{
    QSPI_v0_HwAttrs qspi_cfg;

    /* Get the default UART init configurations */
    QSPI_socGetInitCfg(BOARD_QSPI_NOR_INSTANCE, &qspi_cfg);

    /* Modify the default UART configurations if necessary */

    /* Set the default UART init configurations */
    QSPI_socSetInitCfg(BOARD_QSPI_NOR_INSTANCE, &qspi_cfg);
}

/*
 *  ======== main ========
 */
int main(void)
{
    /* Call board init functions */
    Board_initCfg boardCfg;

    /*
     * In QSPI-96/QSPI-48 boot mode, ROM configures QSPI clock/baud rate,
     * In order to re-configure the QSPI baud rate, QSPI clock need to be
     * disabled and enabled again.
     */
    QSPI_clkEnable(false);
    QSPI_clkEnable(true);

#if defined (SOC_AM335x) || defined (SOC_AM437x)
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);
    task = Task_create(spi_test, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }
#endif

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

    QSPI_initConfig();

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
