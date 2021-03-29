/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   hyperbus_test.c
 *
 *  \brief  hyperbus Example main file
 *
 *  Targeted Functionality: This file implements hyperbus test.
 *
 *  Operation: Verification of hyperbus by accessing the device connected to it.
 *
 *  Supported SoCs : J721E
 *
 *  Supported Platforms: j721e_evm
 *
 */

#include "hyperbus_test.h"

/**
 * \brief  Generate test pattern function
 *
 * This function fills the data buffer passed as input parameter with
 * different test patterns as indicated by 'flag' parameter.
 * Below are the different test patterns supported
 *
 * APP_TEST_PATTERN_FF     - Fills the buffer with 0xFF
 * APP_TEST_PATTERN_AA     - Fills the buffer with 0xAA
 * APP_TEST_PATTERN_55     - Fills the buffer with 0x55
 * APP_TEST_PATTERN_NULL   - Fills buffer with 0
 * APP_TEST_PATTERN_RANDOM - Fills the buffer with randon pattern
 * APP_TEST_PATTERN_INC    - Fills the buffer with increment pattern
 *                                  starting from 0
 * APP_TEST_PATTERN_AA_55  - Fills the buffer with 0xAA in even locations
 *                                  0x55 in odd locations
 *
 * If 'flag' does match with any of the above values, buffer will be filled
 * with 0 by default.
 *
 * \param   buf    [IN]   Buffer to fill with the test pattern
 * \param   length [IN]   Length of the buffer
 * \param   flag   [IN]   Flag to set the test pattern
 *
 */
void App_genPattern(uint8_t *buf, uint32_t length, uint8_t flag)
{
    uint8_t data         = 0;
    uint8_t incFlag      = 0;
    uint8_t randFlag     = 0;
    uint8_t checkerBoard = 0;
    uint32_t idx;

    switch(flag)
    {
        case APP_TEST_PATTERN_FF:
        case APP_TEST_PATTERN_AA:
        case APP_TEST_PATTERN_55:
        case APP_TEST_PATTERN_NULL:
             data = flag;
             break;
        case APP_TEST_PATTERN_INC:
             data    = 0;
             incFlag = 1;
             break;
        case APP_TEST_PATTERN_RANDOM:
             data     = rand();
             randFlag = 1;
        case APP_TEST_PATTERN_AA_55:
             data         = 0xAA;
             checkerBoard = 1;
             break;
        default:
             data = flag;
             break;
    }

    for(idx = 0; idx < length; idx++)
    {
        buf[idx] = data;
        
        if(incFlag)
            data++;
        
        if(randFlag)
            data = rand();

        if(checkerBoard)
            data = ~data;
    }
}

/**
 * \brief  Compares two data buffers
 *
 * This function verifies the data in two buffers passed as parameters and
 * returns the result. 'failIndex' contains the index of the first mismatch
 * when buffer comparision fails.
 *
 * \param   buf1      [IN]   Data buffer 1
 * \param   buf2      [IN]   Data buffer 2
 * \param   length    [IN]   Length of the buffers
 * \param   failIndex [OUT]  Index of first data mismatch
 *
 * \return
 *          1  - In case of success
 *          0  - In case of failure
 *
 */
bool App_memCompare(uint8_t *buf1, uint8_t *buf2, uint32_t length,  
                          uint32_t *failIndex)
{
    uint32_t idx = 0;
    bool match   = 1;
    
    for(idx = 0; ((idx < length) && (match == 1)); idx++)
    {
        if(buf1[idx] != buf2[idx])
        {
            match      = 0;
            *failIndex = idx;
        }            
    }

    return (match);
}

/**
 * \brief   This function writes data, reads back the written data and compares.
 *
 * \param   offset      [IN]    Offset Address to write
 * \param   numOfBytes  [IN]    Number of bytes to write.
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t App_hpbReadWriteTest(Board_flashHandle handle,
                                         uint32_t offset,
                                         uint32_t numOfBytes)
{
    Board_flash_STATUS retVal;
    uint32_t blockNum, pageNum;
    uint32_t failIndex;
    uint8_t txBuf[APP_HPB_TEST_BYTES];
    uint8_t rxBuf[APP_HPB_TEST_BYTES];

    retVal = Board_flashOffsetToBlkPage(handle, offset, &blockNum, &pageNum);
    if (retVal != BOARD_FLASH_EOK)
    {
        UART_printf("\nBoard_flashOffsetToBlkPage failed\n");
        return -1;
    }

    /* Erase block, to which data has to be written */
    retVal = Board_flashEraseBlk(handle, blockNum);
    if (retVal != BOARD_FLASH_EOK)
    {
        UART_printf("\nBoard_flashEraseBlk failed\n");
        return -1;
    }

    App_genPattern(&txBuf[0], numOfBytes,
                         APP_TEST_PATTERN_RANDOM);

    /* Write buffer to hyperflash */
    retVal = Board_flashWrite(handle, offset,
                              &txBuf[0], numOfBytes, NULL);
    if (retVal != BOARD_FLASH_EOK)
    {
        UART_printf("\nBoard_flashWrite failed\n");
        return -1;
    }

    /* Read the hyperflash memory */
    retVal = Board_flashRead(handle, offset,
                             &rxBuf[0], numOfBytes, NULL);
    if (retVal != BOARD_FLASH_EOK)
    {
        UART_printf("\nBoard_flashRead failed\n");
        return -1;
    }

    if (App_memCompare(&txBuf[0], &rxBuf[0], numOfBytes, &failIndex)
                                                                    == false)
    {
        UART_printf("\nData mismatch at offset = 0x%x\n", failIndex);
        return -1;
    }
    return 0;
}

/**
 * \brief   This function runs Hyper Flash boundary verification test.
 *
 * \param   chipSel     [IN]    Chip select number of HyperFlash
 * \param   baseAddr    [IN]    Base Address of HyperFlash
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t App_hpbRunHyperFlashTest()
{
    Board_flashHandle boardHandle;
    Board_FlashInfo *flashInfo;
    int8_t ret;

    boardHandle = Board_flashOpen(BOARD_FLASH_ID_S71KS512S,
                                  BOARD_HPF_INSTANCE, NULL);
    if (!boardHandle)
    {
        UART_printf("Board_flashOpen Failed\n");
        return -1;
    }
    else
    {
        flashInfo = (Board_FlashInfo *)boardHandle;
        UART_printf("\nHyperFlash Device ID: 0x%x, Manufacturer ID: 0x%x \n",
                            flashInfo->device_id, flashInfo->manufacturer_id);
    }

    UART_printf("\n\nVerifying First 512 bytes...");
    ret = App_hpbReadWriteTest(boardHandle,
                                     APP_HPB_FIRST_VERIFY_ADDR,
                                     APP_HPB_TEST_BYTES);
    if (ret != 0)
    {
        UART_printf("Verifying first 512 bytes failed\n");
        Board_flashClose(boardHandle);
        return -1;
    }
    UART_printf("\nVerification of first 512 bytes was successful");

    UART_printf("\n\nVerifying Last 512 bytes...");
    ret = App_hpbReadWriteTest(boardHandle,
                                     APP_HPB_LAST_VERIFY_ADDR,
                                     APP_HPB_TEST_BYTES);
    if (ret != 0)
    {
        UART_printf("Verifying last 512 bytes failed\n");
        Board_flashClose(boardHandle);
        return -1;
    }
    UART_printf("\nVerification of last 512 bytes was successful\n");
    Board_flashClose(boardHandle);

    return 0;
}

/**
 * \brief   The function runs the Hyperbus test.
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t App_HyperBusTest(void)
{
    int8_t ret;

    ret = App_hpbRunHyperFlashTest();
    if (ret)
    {
        UART_printf("\nHyper Flash Test Failed!!\n");
    }
    else
    {
        UART_printf("\nHyper Flash Test Passed!");
    }

    return ret;
}

/**
 *  \brief   Hyperbus test main function
 *
 *  \return  int - Hyperbus test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
#ifndef SPI_BOOT_FRAMEWORK
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
    Board_PinmuxConfig_t pixmuxCfg;
    int ret = 0;

    /* Configure the pinmux for hyperbus as the default
       pinmux configuration is set for OSPI */
    Board_pinmuxGetCfg(&pixmuxCfg);
    pixmuxCfg.fssCfg = BOARD_PINMUX_FSS_HPB;
    Board_pinmuxSetCfg(&pixmuxCfg);

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO | 
               BOARD_INIT_PINMUX_CONFIG;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    UART_printf("\n*********************************************\n");
    UART_printf  ("*              HYPERBUS Test                *\n");
    UART_printf  ("*********************************************\n");

    UART_printf("\nConfiguring PLLs...");
    status = Board_init(BOARD_INIT_PLL);
    if(status != BOARD_SOK)
    {
        /* PLL configuration failure is observed with some of the clocks
           while running from JTAG but HyperBus clock gets configured properly.
           Print fail message and continue with the test.
         */
        UART_printf("PLL Configurations Failed!!");
    }
    else
    {
        UART_printf("Done\n");
    }

    ret = App_HyperBusTest();

    /* Switch back to default pinmux */
    Board_pinmuxGetCfg(&pixmuxCfg);
    pixmuxCfg.fssCfg = BOARD_PINMUX_FSS_OSPI;
    Board_pinmuxSetCfg(&pixmuxCfg);
    Board_init(BOARD_INIT_PINMUX_CONFIG);

    return ret;
}
#endif