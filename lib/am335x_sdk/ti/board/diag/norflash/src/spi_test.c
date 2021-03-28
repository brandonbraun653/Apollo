/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 *  \file   spi_test.c
 *
 *  \brief  spi diagnostic test main file
 *
 *  This file implements SPI diagnostic test for the NOR flash.
 *  This test verifies the SPI flash memory read and write access by writing
 *  a test pattern to a memory page and reading the same page for
 *  data verification.
 *
 *  Supported SoCs : AM65XX
 *
 *  Supported Platforms: am65xx-evm,am65xx_idk
 *
 */

#include "spi_test.h"

/* Buffer containing the known data that needs to be written to flash */
uint8_t txBuf[MAX_BUFF_SIZE];
/* Buffer containing the received data */
uint8_t rxBuf[MAX_BUFF_SIZE] ;
uint8_t verifyBuf[MAX_BUFF_SIZE];

extern const SPI_Config SPI_config[];

/**
 * \brief  spi flash read/write test function
 *
 *  This test executes SPI NOR flash memory read/write test by writing
 *  a pattern to to the memory and reading the same  for the 
 *  verification.
 *
 * \return  int
 *             0  - In case of success
 *            -1  - In case of failure
 *
 */
int BoardDiag_SpiReadWriteTest(Board_flashHandle  handle,
                               uint32_t           offset)
{
    uint32_t blockNum, pageNum;      /* Block, page number */
    uint32_t failIndex;
    
    if (Board_flashOffsetToBlkPage(handle,offset,&blockNum, &pageNum))
    {
        UART_printf("\n Board_flashOffsetToBlkPage failed. \n");
        return -1;
    }

    /* Erase block, to which data has to be written */
    if (Board_flashEraseBlk(handle, blockNum))
    {
        UART_printf("\n Board_flashEraseBlk failed. \n");
        return -1;
    }

    /* Write buffer to flash */
    if (Board_flashWrite(handle, offset,
                (uint8_t *)&txBuf,TEST_DATA_LEN, NULL))
    {
        UART_printf("\n Board_flashWrite failed. \n");
        return -1;
    }

    /* Read the flash memory */
    if (Board_flashRead(handle, offset,
                      (uint8_t *)&rxBuf, TEST_DATA_LEN, NULL))
    {
        UART_printf("\n Board_flashRead failed. \n");
        return -1;
    }

    /* Verify Data */
    if (BoardDiag_memCompare(&txBuf[0],&rxBuf[0],TEST_DATA_LEN, &failIndex) == false)
    {
        UART_printf("\n Data mismatch at offset = 0x%x\n", failIndex);
    }

    /* Erase block */
    if (Board_flashEraseBlk(handle, blockNum))
    {
        UART_printf("\n Board_flashEraseBlk failed. \n");
        return -1;
    }
    
    return 0;
}

/**
 * \brief  spi flash test function
 *
 *  This test executes SPI NOR flash memory test by writting a pattern to
 *  to the first and last pages of the memory and reading the same  for the 
 *  verification.
 *
 * \return  int
 *             0  - In case of success
 *            -1  - In case of failure
 *
 */
#ifdef USE_FLASH_LIB
/* This function verifies the SPI flash memory without using the flash library
 * This function is added for debugging purpose during bring-up 
 */
int BoardDiag_SpiFlashTest(void)
{
    SPI_Params spiParams;                /* SPI params structure */
    SPI_Handle handle;                   /* SPI handle */
    SPI_Transaction transaction;         /* SPI transaction */
    bool retVal = false; 				/* return value */
    uint32_t  xferEnable;	
    uint32_t i;
    uint32_t failIndex;

    for (i = 0; i < CSL_SPI_PER_CNT; i++)
    {
        ((SPI_v1_HWAttrs *)SPI_config[i].hwAttrs)->enableIntr = false;
    }

    /* Init SPI driver */
    SPI_init();

    /* Default SPI configuration parameters */
    SPI_Params_init(&spiParams);

    /* Open SPI driver */
    handle = SPI_open(BOARD_SPI_NOR_INSTANCE, &spiParams);
	
	/* Enable transfer*/
	xferEnable = 1;
    SPI_control(handle, SPI_V0_CMD_XFER_ACTIVATE, (void *)&xferEnable);
    
    BoardDiag_genPattern((uint8_t *)&txBuf[4], MAX_BUFF_SIZE,
                         BOARD_DIAG_TEST_PATTERN_RANDOM);

    /* Write Enable */
    txBuf[0] = NOR_CMD_WREN;
    transaction.count = 1U;
    transaction.txBuf = &txBuf[0];
    transaction.rxBuf = &rxBuf[0];
    retVal = SPI_transfer(handle, &transaction);
    if(retVal == false)
    {
        UART_printf("Write Enable Failed \n");
        SPI_close(handle);
        return -1;
    }

    /* Sector erase */
    txBuf[0] = NOR_CMD_SECTOR_ERASE;
    txBuf[1] = 0x00U;
    txBuf[2] = 0x0U;
    txBuf[3] = 0x0U;
    transaction.count = 4U;

    retVal = SPI_transfer(handle, &transaction);
    if(retVal == false)
    {
        UART_printf("Sector erase Failed \n");
        SPI_close(handle);
        return -1;
    }

   /*  Check for Flash Busy */
    do{
        txBuf[0] = NOR_CMD_RDSR;
        txBuf[1] = 0xFFU;
        transaction.count = 2U;
        retVal = SPI_transfer(handle, &transaction);
    } while(rxBuf[1] & 0x01);

    /* Write Enable */
    txBuf[0] = NOR_CMD_WREN;
    transaction.count = 1U;
    retVal = SPI_transfer(handle, &transaction);
    if(retVal == false)
    {
        UART_printf("Write Enable Failed \n");
        SPI_close(handle);
        return -1;
    }
	
    /* Write to SPI Flash */
    txBuf[0] = NOR_CMD_PAGE_PROG;
    txBuf[1] = 0x00U;
    txBuf[2] = 0x0U;
    txBuf[3] = 0x0U;
    transaction.count = MAX_BUFF_SIZE;

    retVal = SPI_transfer(handle, &transaction);
    if(retVal == true)
        UART_printf("SPI Write Successful \n");
    else
    {
        UART_printf("SPI Write Failed \n");
        SPI_close(handle);
        return -1;
    }

	/*  Check for Flash Busy */
    do{
        txBuf[0] = NOR_CMD_RDSR;
        txBuf[1] = 0xFFU;
        transaction.count = 2U;
        retVal = SPI_transfer(handle, &transaction);
    } while(rxBuf[1] & 0x01);
    
	
	/* Read from SPI flash */
    txBuf[0] = NOR_CMD_READ;
    txBuf[1] = 0x00U;
    txBuf[2] = 0x0U;
    txBuf[3] = 0x0U;
    transaction.count  = MAX_BUFF_SIZE;

    retVal = SPI_transfer(handle, &transaction);
    if(retVal == true)
    {
        UART_printf("SPI Read Successful \n");
    }
    else
    {
        UART_printf("SPI Read Failed \n");
        SPI_close(handle);
        return -1;
    }

    if(BoardDiag_memCompare(&txBuf[4], &rxBuf[4], BUFF_SIZE, &failIndex) == true)
    {
        UART_printf("Data Read matches with Data written\n");
        UART_printf("SPI Flash Test Passed!\n");
    }
    else
    {
        UART_printf("SPI Flash Test Failed at index = 0x%x\n", failIndex);
        SPI_close(handle);
        return -1;
    }

	/* Write Enable */
    txBuf[0] = NOR_CMD_WREN;
    transaction.count = 1U;
    retVal = SPI_transfer(handle, &transaction);
    if(retVal == false)
    {
        UART_printf("Write Enable Failed \n");
        SPI_close(handle);
        return -1;
    }

    /* Sector erase */
    txBuf[0] = NOR_CMD_SECTOR_ERASE;
    txBuf[1] = 0x00U;
    txBuf[2] = 0x0U;
    txBuf[3] = 0x0U;
    transaction.count = 4U;
    retVal = SPI_transfer(handle, &transaction);
    if(retVal == false)
    {
        UART_printf("Sector erase Failed \n");
        SPI_close(handle);
        return -1;
    }
	/*  Check for Flash Busy */
    do{
        txBuf[0] = NOR_CMD_RDSR;
        txBuf[1] = 0xFFU;
        transaction.count = 2U;
        retVal = SPI_transfer(handle, &transaction);
    } while(rxBuf[1] & 0x01);
	
    SPI_close(handle);

    return 0;
}
#else
int BoardDiag_SpiFlashTest(void)
{
    Board_flashHandle boardHandle;
    Board_FlashInfo *flashInfo;
    bool testStatus = true;          /* return value */
    SPI_v1_HWAttrs spi_cfg;

    /* Get the default SPI init configurations */
    SPI_socGetInitCfg(BOARD_SPI_NOR_INSTANCE, &spi_cfg);

    /* Modify the default SPI configurations if necessary */
    /* Turning off interrupts for baremetal mode. May be re-enabled by app */
    spi_cfg.enableIntr = false;

    /* Set the default SPI init configurations */
    SPI_socSetInitCfg(BOARD_SPI_NOR_INSTANCE, &spi_cfg);

    /* Open the Board SPI NOR device with SPI port 0
       and use default SPI configurations */

    boardHandle = Board_flashOpen(BOARD_FLASH_ID_NORN25Q128A13ESF40F,
                                  BOARD_SPI_NOR_INSTANCE, NULL);
    if (!boardHandle)
    {
        UART_printf("\n Board_flashOpen Failed. \n");
        return -1;
    }
    else
    {
        flashInfo = (Board_FlashInfo *)boardHandle;
        UART_printf("\nSPI NOR device ID: 0x%x, manufacturer ID: 0x%x \n",
                flashInfo->device_id, flashInfo->manufacturer_id);
    }

    /* Generate the data */
    BoardDiag_genPattern((uint8_t *)&txBuf[0], TEST_DATA_LEN,
                         BOARD_DIAG_TEST_PATTERN_RANDOM);
                
    UART_printf("\n Verifying the SPI Flash first page...\n");
    testStatus = BoardDiag_SpiReadWriteTest(boardHandle, BOARD_SPI_FIRST_PAGE);
    if(testStatus == true)
    {
        UART_printf("SPI NOR Flash first page verification Sucessful\n");
    }
    else
    {
        UART_printf("SPI NOR Flash first page verification Failed\n");
        return -1;
    }

    UART_printf("\n Verifying the SPI Flash last page...\n");
    testStatus = BoardDiag_SpiReadWriteTest(boardHandle, BOARD_SPI_LAST_PAGE);
    if(testStatus == true)
    {
        UART_printf("SPI NOR Flash last page verification Sucessful\n");
    }
    else
    {
        UART_printf("SPI NOR Flash last page verification Failed\n");
        return -1;
    }

    UART_printf("\nSPI NOR Flash verification Successful\n");

    Board_flashClose(boardHandle);

    return 0;
}
#endif /* #ifndef USE_FLASH_LIB  */

/**
 * \brief  spi flash stress test function
 *
 *  This test verifies the SPI flash memory by Writing and reading 
 *  whole memory of SPI flash
 *
 * \return  int
 *             0  - in case of success 
 *            -1  - in case of failure
 *
 */
int BoardDiag_SpiFlashStressTest(void)
{
    Board_flashHandle boardHandle;
    Board_FlashInfo *flashInfo;
    bool testStatus = 0;          /* return value */
    SPI_v1_HWAttrs spi_cfg;
    uint32_t offset;
    SPI_Params      spiParams;
    void *params;
    
    SPI_Params_init(&spiParams);
    spiParams.bitRate = MAX_CLOCK;
    params = &spiParams;
    
    /* Get the default SPI init configurations */
    SPI_socGetInitCfg(BOARD_SPI_NOR_INSTANCE, &spi_cfg);

    /* Modify the default SPI configurations if necessary */
    /* Turning off interrupts for baremetal mode. May be re-enabled by app */
    spi_cfg.enableIntr = false;

    /* Set the default SPI init configurations */
    SPI_socSetInitCfg(BOARD_SPI_NOR_INSTANCE, &spi_cfg);

    /* Open the Board SPI NOR device with SPI port 0
       and use default SPI configurations */

    boardHandle = Board_flashOpen(BOARD_FLASH_ID_NORN25Q128A13ESF40F,
                                  BOARD_SPI_NOR_INSTANCE, params);
    if (!boardHandle)
    {
        UART_printf("\n Board_flashOpen Failed. \n");
        return -1;
    }
    else
    {
        flashInfo = (Board_FlashInfo *)boardHandle;
        UART_printf("\nSPI NOR device ID: 0x%x, manufacturer ID: 0x%x \n",
                flashInfo->device_id, flashInfo->manufacturer_id);
    }

    /* Generate the data */
    BoardDiag_genPattern((uint8_t *)&txBuf[0], TEST_DATA_LEN,
                         BOARD_DIAG_TEST_PATTERN_RANDOM);

    UART_printf("\nVerifying the SPI Flash ...\n");
    /* This loop verifies the read/write access of whole memory */
    for(offset=BOARD_SPI_FIRST_PAGE; offset<=BOARD_SPI_LAST_PAGE; offset+=NOR_PAGE_SIZE)
    {
        testStatus = BoardDiag_SpiReadWriteTest(boardHandle,offset);
        if(testStatus != 0)
        {
            UART_printf("SPI NOR Flash page verification Failed at \
                                offset 0x%x\n",offset);
            Board_flashClose(boardHandle);
            return -1;
        }
    }
    
    UART_printf("\nSPI NOR Flash verification Successful\n");        

    Board_flashClose(boardHandle);

    return testStatus;
}

/**
 * \brief  spi test function
 *
 * This function executes spi flash test
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 */
int BoardDiag_SpiTest(void)
{
#ifdef DIAG_STRESS_TEST
	UART_printf("\n****************************************************\n");
	UART_printf  ("*            SPI FLASH Stress Test                 *\n");
	UART_printf  ("****************************************************\n");
    return BoardDiag_SpiFlashStressTest();
#else
	UART_printf("\n*********************************************\n");
	UART_printf  ("*            SPI FLASH Test                 *\n");
	UART_printf  ("*********************************************\n");    
    return BoardDiag_SpiFlashTest();
#endif /* #ifndef DIAG_STRESS_TEST */
}

#if defined(SOC_AM65XX)
#if !defined (__aarch64__)
void enableMAINSPI(void)
{
    SPI_v1_HWAttrs spi_cfg;

    SPI_socGetInitCfg(0, &spi_cfg);

    spi_cfg.baseAddr = CSL_MCSPI0_CFG_BASE;
    spi_cfg.enableIntr = 0;

    SPI_socSetInitCfg(0, &spi_cfg);
}
#endif
#endif

/**
 * \brief  main function
 *
 *  This function performs board intializations and calls spi test
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 */
#ifndef SPI_BOOT_FRAMEWORK
int main(void)
{
    uint32_t status;
    Board_initCfg boardCfg;

#if defined(SOC_AM65XX)
#if !defined (__aarch64__)
    enableMAINSPI();
#endif
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    status = Board_init(boardCfg);
    if (status != BOARD_SOK)
    {
        return -1;
    }

    return BoardDiag_SpiTest();
}
#endif

