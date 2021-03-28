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

#include "am65xx_spi_test.h"
#include <ti/csl/src/ip/mcspi/V0/mcspi.h>
#include <ti/csl/src/ip/mcspi/V0/hw_mcspi.h> 

uint32_t gChNum  = 0;
/* Buffer containing the known data that needs to be written to flash */
uint8_t txBuf[MAX_BUFF_SIZE];
/* Buffer containing the received data */
uint8_t rxBuf[MAX_BUFF_SIZE];
uint8_t cmdBuf[MAX_BUFF_SIZE];

/**
 *  \brief    Function to enable SPI for data transfers
 *
 */
static void BoardDiag_spiFlashStartTransfer(void)
{
	/* Enable the transmitter FIFO of McSPI peripheral.*/
    McSPITxFIFOConfig(MCSPI1_BASE_ADDRESS, MCSPI_TX_FIFO_ENABLE, MCSPI_CHANNEL_0);

    /* Enable the receiver FIFO of McSPI peripheral.*/
    McSPIRxFIFOConfig(MCSPI1_BASE_ADDRESS, MCSPI_RX_FIFO_ENABLE, MCSPI_CHANNEL_0);

	/* Enable the McSPI channel for communication.*/
    McSPIChannelEnable(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0);

    /* SPIEN line is forced to low state.*/
    McSPICSAssert(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0);
}

/**
 *  \brief    Function to disable SPI for data transfers
 *
 */
static void BoardDiag_spiFlashStopTransfer(void)
{
	/* Force SPIEN line to the inactive state.*/
    McSPICSDeAssert(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0);
    /* Disable the McSPI channel.*/
    McSPIChannelDisable(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0);
}

/**
 *  \brief    Writes a block of data to SPI module
 *
 *  \param    dataBuf    [IN]   Buffer with data to write
 *  \param    length     [IN]   Length of data to write
 *
 */
static void BoardDiag_spiFlashWriteData(uint8_t *dataBuf, uint16_t length)
{
    uint16_t data_count = 0;
    uint32_t dummyByte = 0;
    volatile uint32_t channelStatus = 0;

    dummyByte = dummyByte;

	while( data_count < length)
	{
        channelStatus = McSPIChannelStatusGet(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0);
		if ((channelStatus & CSL_MCSPI_CH0STAT_TXS_MASK) == CSL_MCSPI_CH0STAT_TXS_MASK)
        {
            McSPITransmitData(MCSPI1_BASE_ADDRESS, (uint32_t) (*(uint8_t *)dataBuf), MCSPI_CHANNEL_0);
            data_count++;
            dataBuf++;
            
            /* Wait till the transfer is complete */
            while((McSPIChannelStatusGet(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0) & CSL_MCSPI_CH0STAT_EOT_MASK) != CSL_MCSPI_CH0STAT_EOT_MASK);
        }
        
        /* Flush the data dummy data from the Rx buffer */
        if((channelStatus & CSL_MCSPI_CH0STAT_RXS_MASK) == CSL_MCSPI_CH0STAT_RXS_MASK)
        {
            dummyByte = McSPIReceiveData(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0);
        }
	}
}

/**
 *  \brief    Reads a block of data from SPI module
 *
 *  \param    dataBuf    [IN]   Buffer to store the data read
 *  \param    length     [IN]   Length of data to read
 *
 */
static void BoardDiag_spiFlashReadData(uint8_t *dataBuf, uint16_t length)
{
    uint16_t data_count = 0;
    uint8_t dummyByte = 0;
    volatile uint32_t channelStatus = 0;
    
    /* Flush the data dummy data from the Rx buffer */
    channelStatus = McSPIChannelStatusGet(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0);
    while((channelStatus & CSL_MCSPI_CH0STAT_RXS_MASK) == CSL_MCSPI_CH0STAT_RXS_MASK)
    {
        dummyByte = McSPIReceiveData(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0);
        channelStatus = McSPIChannelStatusGet(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0);
    }
    
    dummyByte = 0;

	while( data_count < length)
	{    
        channelStatus = McSPIChannelStatusGet(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0);
        if ((channelStatus & CSL_MCSPI_CH0STAT_RXS_MASK) == CSL_MCSPI_CH0STAT_RXS_MASK)
        {
            *(uint8_t *)dataBuf = (uint8_t)McSPIReceiveData(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0);
            data_count++;
            dataBuf++;
        }        
        
		if ((channelStatus & CSL_MCSPI_CH0STAT_TXS_MASK) == CSL_MCSPI_CH0STAT_TXS_MASK)
        {
            McSPITransmitData(MCSPI1_BASE_ADDRESS, dummyByte, MCSPI_CHANNEL_0);

            /* Wait till the transfer is complete */
            while((McSPIChannelStatusGet(MCSPI1_BASE_ADDRESS, MCSPI_CHANNEL_0) & CSL_MCSPI_CH0STAT_EOT_MASK) != CSL_MCSPI_CH0STAT_EOT_MASK);
        }        
	}
}

/**
 *  \brief    Writes a flash page
 *
 *  \param    dataBuf    [IN]   Buffer with data to write
 *  \param    pageOffset [IN]   NOR flash page offset
 *  \param    length     [IN]   Length of data to write
 *
 */
static void BoardDiag_spiFlashWritePage(uint8_t *dataBuf, uint32_t pageOffset, uint16_t length)
{
    uint8_t cmd[4];
    
    BoardDiag_spiFlashStartTransfer();

    cmd[0] = NOR_CMD_PAGE_PROG;
    cmd[1] = ((pageOffset >> 16) & 0xFF);
    cmd[2] = ((pageOffset >> 8) & 0xFF);
    cmd[3] = (pageOffset & 0xFF);
    
    BoardDiag_spiFlashWriteData(cmd, 4);
    BoardDiag_spiFlashWriteData(dataBuf, length);

    BoardDiag_spiFlashStopTransfer();
}

/**
 *  \brief    Reads a flash page
 *
 *  \param    dataBuf    [IN]   Buffer to store the data read
 *  \param    pageOffset [IN]   NOR flash page offset
 *  \param    length     [IN]   Length of data to read
 *
 */
static void BoardDiag_spiFlashReadPage(uint8_t *dataBuf, uint32_t pageOffset, uint16_t length)
{
    uint8_t cmd[4];
    
    BoardDiag_spiFlashStartTransfer();

    cmd[0] = NOR_CMD_READ;
    cmd[1] = ((pageOffset >> 16) & 0xFF);
    cmd[2] = ((pageOffset >> 8) & 0xFF);
    cmd[3] = (pageOffset & 0xFF);
    
    BoardDiag_spiFlashWriteData(cmd, 4);
    BoardDiag_spiFlashReadData(dataBuf, length);

    BoardDiag_spiFlashStopTransfer();
}

/**
 *  \brief    Function to wait till flash is in busy state
 *
 */
static void BoardDiag_spiFlashBusyWait(void)
{
    uint8_t data = 0;

    do
    {
        BoardDiag_spiFlashStartTransfer();
        data = NOR_CMD_RDSR;
        BoardDiag_spiFlashWriteData(&data, 1);
        BoardDiag_spiFlashReadData(&data, 1);
        BoardDiag_spiFlashStopTransfer();
    } while(data & 0x01);
}

/**
 *  \brief    Sends a command to flash
 *
 *  \param    cmdBuf [IN]   Command buffer pointer
 *  \param    length [IN]   Length of command in bytes
 *
 */
static void BoardDiag_spiFlashSendCmd(uint8_t *cmdBuf, uint16_t length)
{
    BoardDiag_spiFlashStartTransfer();
    BoardDiag_spiFlashWriteData(cmdBuf, length);
    BoardDiag_spiFlashStopTransfer();
}

/**
 *  \brief    Reads SPI flash device ID
 *
 * \return
 * \n      0  - Device ID reading successful
 * \n      -1 - Invalid device ID read
 */
static int8_t BoardDiag_spiFlashReadDevID(void)
{
    UART_printf("Reading Flash Device ID...\n");

	BoardDiag_spiFlashStartTransfer();
    cmdBuf[0] = NOR_CMD_RDID;
    BoardDiag_spiFlashWriteData(cmdBuf, 1);
    BoardDiag_spiFlashReadData(rxBuf, 3);
    
    BoardDiag_spiFlashStopTransfer();

    UART_printf("Device ID 0 - 0x%X\n", rxBuf[0]);
    UART_printf("Device ID 1 - 0x%X\n", rxBuf[1]);
    UART_printf("Device ID 2 - 0x%X\n", rxBuf[2]);

    if((rxBuf[0] == SPI_FLASH_DEVID_BYTE0) &&
       (rxBuf[1] == SPI_FLASH_DEVID_BYTE1) &&
       (rxBuf[2] == SPI_FLASH_DEVID_BYTE2))
    {
        UART_printf("Flash Device ID Match!\n");
    }
    else
    {
        UART_printf("Flash Device ID Mismatch!\n");
        return -1;
    }

	return 0;
}

/**
 *  \brief    Executes SPI NOR flash memory test
 *
 *  \param    pageOffset [IN]   NOR flash page offset
 *
 * \return
 * \n      0   - Success
 * \n      -1  - Failure
 */
static int8_t BoardDiag_spiFlashRunTest(uint32_t  pageOffset)
{
	uint16_t count;
	uint32_t failIndex;

	BoardDiag_genPattern((uint8_t *)cmdBuf, MAX_BUFF_SIZE,
                         BOARD_DIAG_TEST_PATTERN_NULL);
#if defined(DIAG_COMPLIANCE_TEST)
	BoardDiag_genPattern((uint8_t *)txBuf, MAX_BUFF_SIZE,
                         BOARD_DIAG_TEST_PATTERN_AA_55);
#else
    BoardDiag_genPattern((uint8_t *)txBuf, MAX_BUFF_SIZE,
                         BOARD_DIAG_TEST_PATTERN_INC);
#endif
	BoardDiag_genPattern((uint8_t *)rxBuf, MAX_BUFF_SIZE,
                         BOARD_DIAG_TEST_PATTERN_NULL);

    /* Sector erase */
    if(!(pageOffset % SECTOR_SIZE))
    {
        /* Write Enable */
        cmdBuf[0] = NOR_CMD_WREN;
        count = 1U;
        BoardDiag_spiFlashSendCmd(cmdBuf, count);

        cmdBuf[0] = NOR_CMD_SECTOR_ERASE;
        cmdBuf[1] = ((pageOffset >> 16) & 0xFF);
        cmdBuf[2] = ((pageOffset >> 8) & 0xFF);
        cmdBuf[3] = (pageOffset & 0xFF);
        count = 4U;
        BoardDiag_spiFlashSendCmd(cmdBuf, count);

        /* Check for the busy state */
        BoardDiag_spiFlashBusyWait();
    }

    /* Write Enable */
    cmdBuf[0] = NOR_CMD_WREN;
    count = 1U;
    BoardDiag_spiFlashSendCmd(cmdBuf, count);

    /* Write to SPI Flash */
    BoardDiag_spiFlashWritePage(txBuf, pageOffset, MAX_BUFF_SIZE);

	/*  Check for Flash Busy */
    BoardDiag_spiFlashBusyWait();

	/* Read from SPI flash */
    BoardDiag_spiFlashReadPage(rxBuf, pageOffset, MAX_BUFF_SIZE);

    if(BoardDiag_memCompare(txBuf, rxBuf, MAX_BUFF_SIZE, &failIndex) == true)
    {
        if(!(pageOffset%SECTOR_SIZE))
        {
            UART_printf("Data Read matches with Data written\n");
            UART_printf("SPI Flash Test Passed!\n");
        }
    }
    else
    {
        UART_printf("SPI Flash Test Failed at index = 0x%x\n", failIndex);
        return -1;
    }

	return 0;
}

/**
 *  \brief    Function to initialize SPI module
 *
 * \return
 * \n      0   - Success
 * \n      -1  - Failure
 */
static int8_t BoardDiag_spiFlashInit(void)
{
	int8_t status = 1U;

    /* Reset the McSPI instance.*/
    McSPIReset(MCSPI1_BASE_ADDRESS);
	
	/* CLOCKACTIVITY bit - OCP and Functional clocks are maintained           */
    /* SIDLEMODE     bit - Ignore the idle request and configure in normal mode
     */
    /* AUTOIDLE      bit - Disable (OCP clock is running free, no gating)     */
    MCSPISysConfigSetup(MCSPI1_BASE_ADDRESS, MCSPI_CLOCKS_OCP_ON_FUNC_ON,
                        MCSPI_SIDLEMODE_NO, MCSPI_WAKEUP_DISABLE,
                        MCSPI_AUTOIDLE_OFF);

    /* Enable chip select pin.*/
    McSPICSEnable(MCSPI1_BASE_ADDRESS);

    /* Enable master mode of operation.*/
    McSPIMasterModeEnable(MCSPI1_BASE_ADDRESS);
	
	/* Perform the necessary configuration for master mode. */
    status = McSPIMasterModeConfig(MCSPI1_BASE_ADDRESS, MCSPI_SINGLE_CH,
                                   MCSPI_TX_RX_MODE,
                                   MCSPI_DATA_LINE_COMM_MODE_6,
                                   gChNum);
	if(status == 0)
	{
		UART_printf("MCSPI communication failed\n");
		return -1;
	}

	/* Configure the McSPI bus clock depending on clock mode. */
    McSPIClkConfig(MCSPI1_BASE_ADDRESS, MCSPI_IN_CLK, MCSPI_OUT_FREQ, gChNum,
                   MCSPI_CLK_MODE_0);

    /* Configure the word length.*/
    McSPIWordLengthSet(MCSPI1_BASE_ADDRESS, MCSPI_WORD_LENGTH(8), gChNum);

    /* Set polarity of SPIEN to low.*/
    McSPICSPolarityConfig(MCSPI1_BASE_ADDRESS,
                          MCSPI_CS_POL_LOW, gChNum);

    /* SPI_CS1 is connected to a level translator on IDK application card
       which should be pulled high by default for proper operation of NOR
       flash
     */
    McSPICSPolarityConfig(MCSPI1_BASE_ADDRESS,
                          MCSPI_CS_POL_LOW, 1);
	return 0;
}

/**
 *  \brief    Executes SPI NOR flash test
 *
 * \return
 * \n      0   - Test Passed
 * \n      -1  - Test Failed
 */
int8_t BoardDiag_spiFlashTest(void)
{
    uint32_t pageNum;
	int8_t testStatus;

#ifdef DIAG_STRESS_TEST
	UART_printf("\n************************************************\n");
	UART_printf  ("*            SPI FlASH Stress Test             *\n");
	UART_printf  ("************************************************\n");
#else
	UART_printf("\n***************************************\n");
	UART_printf  ("*            SPI FlASH Test           *\n");
	UART_printf  ("***************************************\n");
#endif

    testStatus = BoardDiag_spiFlashInit();
    if(testStatus != 0)
    {
        UART_printf("\nSPI NOR Flash init Failed\n");
        return -1;
    }

    testStatus = BoardDiag_spiFlashReadDevID();
    if(testStatus != 0)
    {
        UART_printf("\nFlash Device ID Read Failed!!\n");
        return -1;
    }
    else
    {
        UART_printf("\nFlash Device ID Read Passed!\n");
    }

    for(pageNum = 0; pageNum < SPI_FLAH_TEST_MAX_PAGES; pageNum += TESTPAGES)
    {
        if(!(pageNum & 0xff))
        {
            UART_printf("\nVerifying Sector - %d\n", (pageNum/PAGES_PER_SECTOR));
        }

        testStatus = BoardDiag_spiFlashRunTest((NOR_PAGE_SIZE * pageNum));
        if(testStatus != 0)
        {
            UART_printf("\nSPI NOR Flash Test Failed\n");
            return -1;
        }
	}

    UART_printf("\nSPI NOR Flash Test Passed\n");

	return testStatus;
}

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
    Board_STATUS status;
    Board_initCfg boardCfg;

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    return BoardDiag_spiFlashTest();
}
#endif

