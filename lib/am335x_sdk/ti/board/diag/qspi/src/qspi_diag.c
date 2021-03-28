
/*
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* TI-RTOS Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#if !defined (SOC_K2G)
#include <ti/csl/soc/am572x/src/cslr_control_core_pad_io.h>
#endif
#include <stdlib.h>
#include <ti/csl/soc.h>
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/SPI_soc.h>

/* Flash header file */
#if defined(SOC_K2G)
#include <ti/board/src/flash/include/board_flash.h>
#define TEST_ADDR_OFFSET        0x40000
#define TEST_DATA_LEN           (512U)
#define TEST_SECTOR_ERASE_LEN   (2U * 64U * 1024U)
#else
#include "qspi_flash.h"
#endif

#include "board.h"
#include "board_cfg.h"

#ifdef SOC_K2G
#include "diag_common_cfg.h"
#endif

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/

/* Board specific definitions */
#define QSPI_PER_CNT            (1U)
#define QSPI_INSTANCE           (1U)

#if defined (SOC_AM335x) || defined (SOC_AM437x)
#define QSPI_OFFSET             (5U)
#endif
#if defined (SOC_AM572x) || defined (SOC_AM571x) || defined (SOC_AM574x)
#define QSPI_OFFSET             (4U)
#endif

#define CSL_MCSPI_PER_CNT   (4U)
#define CSL_QSPI_PER_CNT    1U


/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

/* Function to generate known data */
static void GeneratePattern(uint8_t *txBuf, uint8_t *rxBuf, uint32_t length);

/* Data compare function */
bool VerifyData(unsigned char *expData,
                unsigned char *rxData,
                unsigned int length);


/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/* Buffer containing the known data that needs to be written to flash */
unsigned int txBuf[1024];

/* Buffer containing the received data */
unsigned int rxBuf[1024];

/* Flash offset address to which data write/read has to be performed */
unsigned int addrValue = 0x000000U;

extern const SPI_Config SPI_config[];

/* transfer length */
uint32_t transferLength = 0;

/*
 *  ======== test function ========
 */
#if defined (SOC_K2G)
int spi_test()
{
    Board_flashHandle boardHandle;
    Board_FlashInfo *flashInfo;
    uint32_t blockNum, pageNum, startSecNum,endSecNum, i;      /* Block, page, Sector number */
    bool testPassed = true;          /* return value */
    uint32_t ioMode = BOARD_FLASH_QSPI_IO_MODE_QUAD;
    QSPI_v0_HwAttrs qspi_cfg;
    bool hybridErase;

    /* Get the default QSPI init configurations */
    QSPI_socGetInitCfg(BOARD_QSPI_NOR_INSTANCE, &qspi_cfg);

    /* Modify the default QSPI configurations if necessary */
    /* Turning off interrupts for baremetal mode. May be re-enabled by app */
    qspi_cfg.intrEnable = false;

    /* Set the default QSPI init configurations */
    QSPI_socSetInitCfg(BOARD_QSPI_NOR_INSTANCE, &qspi_cfg);

    /* Open the Board QSPI NOR device with QSPI port 0
       and use default QSPI configurations */	
#if defined (ICE_K2G)
    boardHandle = Board_flashOpen(BOARD_FLASH_ID_QSPIFLASH_S25FL256S,
                                  BOARD_QSPI_NOR_INSTANCE, NULL);
    hybridErase = true;
#else
    boardHandle = Board_flashOpen(BOARD_FLASH_ID_QSPIFLASH_S25FL512S,
                                  BOARD_QSPI_NOR_INSTANCE, NULL);
    hybridErase = false;
#endif

    if (!boardHandle)
    {
        UART_printf("\n Board_flashOpen failed. \n");
        return -1;
    }
    else
    {
        flashInfo = (Board_FlashInfo *)boardHandle;
        UART_printf("\n QSPI NOR device ID: 0x%x, manufacturer ID: 0x%x \n",
                flashInfo->device_id, flashInfo->manufacturer_id);
    }

    /* Read/Write Test */
    UART_printf("\n****Testing QSPI Read/Write****\n");
    if (Board_flashOffsetToBlkPage(boardHandle, TEST_ADDR_OFFSET,
                                   &blockNum, &pageNum))
    {
        UART_printf("\n Board_flashOffsetToBlkPage failed. \n");
        testPassed = false;
    }

    /* Erase block, to which data has to be written */
    if (Board_flashEraseBlk(boardHandle, blockNum))
    {
        UART_printf("\n Board_flashEraseBlk failed. \n");
        testPassed = false;
    }

    /* Generate the data */
    GeneratePattern((uint8_t *)&txBuf[0], (uint8_t *)&rxBuf[0], TEST_DATA_LEN);

    /* Write buffer to flash */
    if (Board_flashWrite(boardHandle, TEST_ADDR_OFFSET, (uint8_t *)&txBuf,
                         TEST_DATA_LEN, (void *)(&ioMode)))
    {
        UART_printf("\n Board_flashWrite failed. \n");
        testPassed = false;
    }

    /* Reset receive buffer */
    if (Board_flashRead(boardHandle, TEST_ADDR_OFFSET, (uint8_t *)&rxBuf,
                        TEST_DATA_LEN, (void *)(&ioMode)))
    {
        UART_printf("\n Board_flashRead failed. \n");
        testPassed = false;
    }

    /* Verify Data */
    if (VerifyData((unsigned char *)&txBuf[0], (unsigned char *)&rxBuf[0], TEST_DATA_LEN) == false)
    {
        UART_printf("\n Data mismatch. \n");
        testPassed = false;
    }

    if(true == testPassed)
    {
        UART_printf("QSPI Read Write Test PASSED! \n");
    }
    else
    {
        UART_printf("QSPI Read Write Test Failed!\n");
    }

#if defined (ICE_K2G)
    /* Sector Erase Test */
    UART_printf("\n****Testing QSPI Sector Erase****\n");
    if (Board_flashOffsetToSectorPage(boardHandle, TEST_ADDR_OFFSET,
                                   &startSecNum, &pageNum, hybridErase))
    {
        UART_printf("\n Board_flashOffsetToSectorPage failed. \n");
        testPassed = false;
    }
    if (Board_flashOffsetToSectorPage(boardHandle, (TEST_ADDR_OFFSET + TEST_SECTOR_ERASE_LEN),
                                   &endSecNum, &pageNum, hybridErase))
    {
        UART_printf("\n Board_flashOffsetToSectorPage failed. \n");
        testPassed = false;
    }

    /* Erase Sector, to which data has to be written */
    for(i = startSecNum; i <= endSecNum; i++)
    {
        if (Board_flashEraseBlk(boardHandle, i))
        {
            UART_printf("\n Sector Erase Failed!");
            return -1;
        }
    }

    /* Reset receive buffer */
    for (i = 0; i < (TEST_SECTOR_ERASE_LEN / TEST_DATA_LEN); i++)
    {
        memset(txBuf, 0xFF, TEST_DATA_LEN);
        if (Board_flashRead(boardHandle, (TEST_ADDR_OFFSET+(TEST_DATA_LEN * i)), (uint8_t *)&rxBuf,
                            TEST_DATA_LEN, (void *)(&ioMode)))
        {
            UART_printf("\n Board_flashRead failed. \n");
            testPassed = false;
        }
        /* Verify Data */
        if (VerifyData((unsigned char *)&txBuf[0], (unsigned char *)&rxBuf[0], TEST_DATA_LEN) == false)
        {
            UART_printf("\n Data mismatch. \n");
            testPassed = false;
            break;
        }
    }
    if(true == testPassed)
    {
        UART_printf("QSPI Sector Erase Test PASSED! \n");

    }
    else
    {
        UART_printf("QSPI Sector Erase Test Failed!\n");
    }
#endif
    Board_flashClose(boardHandle);
    if(true == testPassed)
    {
        UART_printf("Test PASSED! \n");
        return 0;
    }
    else
    {
        UART_printf("Test Failed!\n");
        return -1;
    }
    while(1);
}
#else
int spi_test()
{
    SPI_Params spiParams;                /* SPI params structure */
    S25FL_Handle flashHandle;            /* Flash handle */
    unsigned int blockNumber = 0U;       /* Block number */
    unsigned int startSectorNum, endSectorNum;
    S25FL_Transaction flashTransaction;  /* Flash transaction structure */
    SPI_Handle handle;                   /* SPI handle */
    QSPI_HwAttrs *hwAttrs;               /* QSPI hardware attributes */
    bool retVal = false;                 /* return value */
    uint32_t addressValue;               /* address parameter */
    int i;

    for (i=0; i<CSL_MCSPI_PER_CNT; i++)
    {
        ((SPI_v1_HWAttrs *)SPI_config[i].hwAttrs)->enableIntr = false;
    }

    for (i=CSL_MCSPI_PER_CNT; i<CSL_MCSPI_PER_CNT+CSL_QSPI_PER_CNT; i++)
    {
        ((QSPI_HwAttrs *)SPI_config[i].hwAttrs)->intrEnable = false;
    }


    /* Init SPI driver */
    SPI_init();

    /* Default SPI configuration parameters */
    SPI_Params_init(&spiParams);

    /* Open QSPI driver */
    //flashHandle = SF25FL_open(0, &spiParams);
    flashHandle = SF25FL_open(((QSPI_INSTANCE - 1)+(QSPI_OFFSET)), &spiParams);

    /* Extract hardware attributes */
    handle = flashHandle->spiHandle;
    hwAttrs = (QSPI_HwAttrs *)handle->hwAttrs;

    /* Print flash Id */
    FlashPrintId(flashHandle);

    /* Erase block, to which data has to be written */
    S25FLFlash_BlockErase(flashHandle, blockNumber);

    /* Set the transfer length in number of 32 bit words */
    transferLength = 50;

    /* Generate the data */
    GeneratePattern((uint8_t *)&txBuf[0], (uint8_t *)&rxBuf[0], transferLength);

    /* Update target address based on the modes. For config mode pass the
       address of the variable containing the flash offset value.
       For memory mapped mode directly pass the flash offset value. */
    addressValue = (QSPI_OPER_MODE_CFG == hwAttrs->operMode) ?
        (uint32_t)&addrValue: addrValue;

    /* Update transaction parameters */
    flashTransaction.data       = (uint8_t *)&txBuf[0];
    flashTransaction.address    = addressValue;
    flashTransaction.dataSize   = transferLength * 4;  /* In bytes */

    /* Write buffer to flash */
    retVal = SF25FL_bufferWrite(flashHandle, &flashTransaction);

    if(QSPI_RX_LINES_QUAD == hwAttrs->rxLines)
    {
        S25FLFlash_QuadModeEnable(flashHandle);
    }

    /* Update transaction parameters */
    flashTransaction.data       = (uint8_t *)&rxBuf[0];
    flashTransaction.address    = addressValue;
    flashTransaction.dataSize   = transferLength * 4; /* In bytes */

    /* Read data from flash */
    retVal = SF25FL_bufferRead(flashHandle, &flashTransaction);

    /* Verify Data */
    retVal = VerifyData((unsigned char *)&txBuf[0], (unsigned char *)&rxBuf[0],
        transferLength);

    SF25FL_close(flashHandle);

    if(true == retVal)
    {
        UART_printf("Test PASSED! \n");
    }
    else
    {
        UART_printf("Data Mismatch\n");
		UART_printf("Test Failed!\n");
    }
    UART_printf("Testing QSPI Sector Erase...\n");
    /* Erasing Sectors 1 to 10  */
    startSectorNum = 0U;
    endSectorNum = 10U;

    /* Erase Sectors from startSectorNum to endSectorNum */
    for(i = startSectorNum; i <= endSectorNum; i++)
    {
        if (!(S25FLFlash_SectorErase(flashHandle, i)))
        {
            retVal = 0;
            break;
        }
        else
        {
            retVal = 1;
        }
    }
    if(retVal)
    {
        UART_printf("Test Passed!\n");
    }
    else
    {
        UART_printf("Test Failed at Sector Number %d!\n", i);
    }
    return retVal;
}
#endif

/*
 *  ======== CompareData ========
 */
bool VerifyData(unsigned char *expData,
                unsigned char *rxData,
                unsigned int length)
{
    unsigned int idx = 0;
    unsigned int match = 1;
    bool retVal = false;
#ifdef SOC_K2G    
    unsigned int lenInBytes = length;
#else
    unsigned int lenInBytes = length * 4;
#endif
    

    for(idx = 0; ((idx < lenInBytes) && (match != 0)); idx++)
    {
        if(*expData != *rxData) match = 0;        
        expData++;
        rxData++;
    }

    if(match == 1) retVal = true;

    return retVal;
}

/*
 *  ======== GeneratePattern ========
 */
static void GeneratePattern(uint8_t *txBuf, uint8_t *rxBuf, uint32_t length)
{
    unsigned int idx;
    unsigned int lenInBytes = length * 4;

    for(idx = 0; idx < lenInBytes; idx++)
    {
        txBuf[idx] = (uint8_t)idx;
        rxBuf[idx] = (uint8_t)0U;
    }
}

int qspi_test()
{
	UART_printf("\n*********************************************\n");
	UART_printf  ("*                 QSPI Test                 *\n");
	UART_printf  ("*********************************************\n");

	UART_printf("\nTesting QSPI read/write...\n");

	return spi_test();
}

/*
 *  ======== main ========
 */
int main(void)
{
    Board_initCfg boardCfg;

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

	return qspi_test();
}
