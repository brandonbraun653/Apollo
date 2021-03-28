/*
 * Copyright (c) 2016, Texas Instruments Incorporated
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
 *
 */

/**
*
* \file nand_test.c
*
* \brief This file contains nand test functions.
*
******************************************************************************/

#include "nand_test.h"

#include <ti/drv/uart/UART_stdio.h>

#include "board.h"
#include "board_cfg.h"

#ifdef SOC_K2G
#include "diag_common_cfg.h"
#endif

/**
 *  \brief    Executes NAND flash chip detect test
 *
 *  \param    p_device [IN]   NAND flash device handle
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 */
static TEST_STATUS nand_chip_detect_test(PLATFORM_DEVICE_info *p_device,
                                         void *testArgs)
{
    nandTestArgs_t *args = (nandTestArgs_t *)testArgs;

    p_device = platform_device_open(args->devId, 0);
    if (p_device == NULL)
    {
       UART_printf("NAND Flash Test: Could Not Open NAND Device; errno = 0x%x \n",
                      platform_errno);
       return (TEST_FAIL);
    }

    UART_printf("Device Id - 0x%X\n", p_device->device_id);
    UART_printf("Manufacturer Id - 0x%X\n", p_device->manufacturer_id);
    UART_printf("Device Width - %d\n", p_device->width);
    UART_printf("Block Count - %d\n", p_device->block_count);
    UART_printf("Page Count - %d\n", p_device->page_count);
    UART_printf("Page Size - %d\n", p_device->page_size);
    UART_printf("Spare Area Size - %d\n", p_device->spare_size);
    UART_printf("Column Address - %d\n", p_device->column);

    platform_device_close(p_device->handle);

    return (TEST_PASS);
}

/**
 *  \brief    Executes NAND flash memory read/write test
 *
 *  \param    p_device [IN]   NAND flash device handle
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 */
static TEST_STATUS nand_memory_access_test(PLATFORM_DEVICE_info *p_device,
                                           void *testArgs)
{
    Platform_STATUS status;
    TEST_STATUS     testStatus = TEST_FAIL;
    nandTestArgs_t *args = (nandTestArgs_t *)testArgs;
    uint32_t offset;
    uint8_t  *nandWrBuf = NULL;
    uint8_t  *nandRdBuf = NULL;
#ifdef ENABLE_MEMORY_BACKUP
    uint8_t  *nandBkpBuf = NULL;
#endif

    /* Create buffers */
    nandWrBuf = (uint8_t *) malloc(args->blockLen);
    nandRdBuf = (uint8_t *) malloc(args->blockLen);
    if ((nandWrBuf == NULL) ||
        (nandRdBuf == NULL))
    {
        UART_printf("NAND Flash Test: Buffer Allocation Failed!\n");
        goto NAND_ACCESS_TEST_DONE;
    }

#ifdef ENABLE_MEMORY_BACKUP
    nandBkpBuf = (uint8_t *) malloc(args->blockLen);
    if (nandBkpBuf == NULL)
    {
        UART_printf("NAND Flash Test: Buffer Allocation Failed!\n");
        goto NAND_ACCESS_TEST_DONE;
    }
#endif

    /* Get the NAND offset to the block */
    status = platform_blocknpage_to_offset(p_device->handle, &offset,
                                           args->blockNum, 0);
    if(status != Platform_EOK)
    {
        UART_printf("NAND Flash Test: Block Number to Offset Conversion Failed - ");
        UART_printf("Check the Block Number!!\n");
        goto NAND_ACCESS_TEST_DONE;
    }

#ifdef ENABLE_MEMORY_BACKUP
    status = platform_device_read(p_device->handle, offset,
                                  nandBkpBuf, args->blockLen);
    if(status != Platform_EOK)
    {
        UART_printf("NAND Flash Test: Unable to Read Block %d Page %d errno = 0x%x\n",
                       args->blockNum, 0, platform_errno);
        goto NAND_ACCESS_TEST_DONE;
    }
#endif

    /* Erase our test block so we can write to it */
    status = platform_device_erase_block(p_device->handle, args->blockNum);
    if(status != Platform_EOK)
    {
        UART_printf("NAND Flash Test: Unable to Erase (%d) Block %d errno = 0x%x\n",
                       args->blockNum, platform_errno);
        goto NAND_ACCESS_TEST_DONE;
    }

    /* Fill in a test pattern */
    memset(nandWrBuf, args->testPattern, args->blockLen);
    memset(nandRdBuf, 0, args->blockLen);

    /* Write the test pattern to the test block */
    status = platform_device_write(p_device->handle, offset,
                                   nandWrBuf, args->blockLen);
    if (status != Platform_EOK)
    {
        UART_printf("NAND Flash Test: Unable to Write (%d) Block %d Page %d errno = 0x%x \n",
                       args->blockNum, 0, platform_errno);
        goto NAND_ACCESS_TEST_DONE;
    }

    status = platform_device_read(p_device->handle, offset,
                                  nandRdBuf, args->blockLen);
    if (status != Platform_EOK)
    {
        UART_printf("NAND Flash Test: Unable to Read Block %d Page %d errno = 0x%x\n",
                       args->blockNum, 0, platform_errno);
        goto NAND_ACCESS_TEST_DONE;
    }

    /* Compare to see if what we wrote is what we read */
    if(memcmp(nandWrBuf, nandRdBuf, args->blockLen))
    {
        testStatus = TEST_FAIL;
        UART_printf("NAND Flash Test: Data Verification Failed\n");
    }
    else
    {
        testStatus = TEST_PASS;
        UART_printf("NAND Flash Test: Data Verification Passed\n");
    }

#ifdef ENABLE_MEMORY_BACKUP
    /* Restore the original buffer */
    status = platform_device_erase_block(p_device->handle, args->blockNum);
    if (status != Platform_EOK)
    {
        testStatus = TEST_FAIL;
        UART_printf("NAND Flash Test: Unable to Erase Block %d errno = 0x%x \n",
                       args->blockNum, platform_errno);
        goto NAND_ACCESS_TEST_DONE;
    }

    status = platform_device_write(p_device->handle, offset,
                                   nandBkpBuf, args->blockLen);
    if (status != Platform_EOK)
    {
        testStatus = TEST_FAIL;
        UART_printf("NAND Flash Test: Unable to Write Back Original Data errno = 0x%x \n",
                       platform_errno);
        goto NAND_ACCESS_TEST_DONE;
    }
#endif

NAND_ACCESS_TEST_DONE:

    if (nandWrBuf)
    {
        free(nandWrBuf);
    }

    if (nandRdBuf)
    {
        free(nandRdBuf);
    }

#ifdef ENABLE_MEMORY_BACKUP
    if (nandBkpBuf)
    {
        free(nandBkpBuf);
    }
#endif

    return (testStatus);
}

/**
 *  \brief    Executes NAND flash memory erase test
 *
 *  \param    p_device [IN]   NAND flash device handle
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 */
static TEST_STATUS nand_erase_test(PLATFORM_DEVICE_info *p_device,
                                   void *testArgs)
{
    nandTestArgs_t *args = (nandTestArgs_t *)testArgs;
    Platform_STATUS  status;
    TEST_STATUS      testStatus = TEST_FAIL;

    uint32_t index;
    uint32_t offset;
    uint32_t blockSize;
    uint8_t  *nandRdBuf;
#ifdef ENABLE_MEMORY_BACKUP
    uint8_t  *nandBkpBuf;
#endif

    blockSize = (BYTES_PER_PAGE * PAGES_PER_BLOCK);

    nandRdBuf = malloc(blockSize);
    if(nandRdBuf == NULL)
    {
       UART_printf("NAND Flash Test: Buffer Allocation Failed!\n");
       goto NAND_ERASE_TEST_DONE;
    }

#ifdef ENABLE_MEMORY_BACKUP
    nandBkpBuf = malloc(blockSize);
    if(nandBkpBuf == NULL)
    {
        UART_printf("NAND Flash Test: Buffer Allocation Failed!\n");
        goto NAND_ERASE_TEST_DONE;
    }
#endif

    memset(nandRdBuf, 0, blockSize);

    status = platform_blocknpage_to_offset(p_device->handle, &offset,
                                           args->blockNum, 0);
    if(status != Platform_EOK)
    {
        UART_printf("NAND Flash Test: Block Number to Offset Conversion Failed - ");
        UART_printf("Check the Block Number!!\n");
        goto NAND_ERASE_TEST_DONE;
    }

#ifdef ENABLE_MEMORY_BACKUP
    status = platform_device_read(p_device->handle, offset,
                                  nandBkpBuf, blockSize);
    if(status != Platform_EOK)
    {
        UART_printf("NAND Flash Test: Read Failed  errno = 0x%x\n",
                       platform_errno);
        goto NAND_ERASE_TEST_DONE;
    }
#endif

    status = platform_device_erase_block (p_device->handle, args->blockNum);
    if(status != Platform_EOK)
    {
        UART_printf("NAND Flash Test: Erase Failed for NAND Block %d  errno = 0x%x\n",
                        args->blockNum, platform_errno);
        goto NAND_ERASE_TEST_DONE;
    }

    status = platform_device_read(p_device->handle, offset,
                                  nandRdBuf, blockSize);
    if(status != Platform_EOK)
    {
        UART_printf("NAND Flash Test: Reading Erased Block Failed  errno = 0x%x\n",
                       platform_errno);
        goto NAND_ERASE_TEST_DONE;
    }

    for (index = 0; index < blockSize; index++)
    {
        if(nandRdBuf[index] != 0xFF)
        {
            UART_printf("NAND Flash Test: Erase Data Verification Failed\n");
            testStatus = TEST_FAIL;
            break;
        }
    }

    if(index == blockSize)
    {
        UART_printf("NAND Flash Test: Erase Data Verification Passed\n");
        testStatus = TEST_PASS;
    }

#ifdef ENABLE_MEMORY_BACKUP
    status = platform_device_write(p_device->handle, offset,
                                   nandBkpBuf, blockSize);
    if(status != Platform_EOK)
    {
        UART_printf("NAND Flash Test: Write Back Original Data Failed  errno = 0x%x\n",
                       platform_errno);
        testStatus = TEST_FAIL;
    }
#endif

NAND_ERASE_TEST_DONE:
    if(nandRdBuf)
    {
        free(nandRdBuf);
    }

#ifdef ENABLE_MEMORY_BACKUP
    if(nandBkpBuf)
    {
        free(nandBkpBuf);
    }
#endif

    return (testStatus);
}

/**
 *  \brief    Executes NAND flash tests
 *
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 */
static TEST_STATUS run_nand_test(void *testArgs)
{
    PLATFORM_DEVICE_info *p_device = NULL;
    nandTestArgs_t       *args = (nandTestArgs_t *)testArgs;
    TEST_STATUS          testStatus = TEST_FAIL;

    UART_printf("\nRunning NAND Flash Chip Detect Test\n");

    testStatus = nand_chip_detect_test(p_device, args);
    if(testStatus != TEST_PASS)
    {
        UART_printf("\nNAND Flash Chip Detect Test Failed\n");
        return (testStatus);
    }
    else
    {
        UART_printf("\nNAND Flash Chip Detect Test Passed\n");
    }

    p_device = platform_device_open(args->devId, 0);
    if (p_device == NULL)
    {
        UART_printf("NAND Flash Test: Could Not Open NAND Device; errno = 0x%x \n",
                       platform_errno);
        return (TEST_FAIL);
    }

    UART_printf("\nRunning NAND Flash Block Erase Test\n");

    testStatus = nand_erase_test(p_device, args);
    if(testStatus != TEST_PASS)
    {
        UART_printf("\nNAND Flash Block Erase Test Failed\n");
        goto END_TEST;
    }
    else
    {
        UART_printf("\nNAND Flash Block Erase Test Passed\n");
    }

    UART_printf("\nRunning NAND Flash Memory Access Test - Test Pattern 1\n");
    args->testPattern = NAND_FLASH_TEST_PATTERN1;

    testStatus = nand_memory_access_test(p_device, args);
    if(testStatus != TEST_PASS)
    {
        UART_printf("\nNAND Flash Memory Access Test Failed\n");
        goto END_TEST;
    }
    else
    {
        UART_printf("\nNAND Flash Memory Access Test Passed\n");
    }

    UART_printf("\nRunning NAND Flash Memory Access Test - Test Pattern 2\n");
    args->testPattern = NAND_FLASH_TEST_PATTERN2;

    testStatus = nand_memory_access_test(p_device, args);
    if(testStatus != TEST_PASS)
    {
        UART_printf("\nNAND Flash Memory Access Test Failed\n");
        goto END_TEST;
    }
    else
    {
        UART_printf("\nNAND Flash Memory Access Test Passed\n");
    }

END_TEST:
    platform_device_close(p_device->handle);

    return (testStatus);
}

/**
 * \brief This function performs nand test
 *
 * \param testArgs  - Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
TEST_STATUS nandTest(void *testArgs)
{
    TEST_STATUS testStatus = TEST_PASS;
    nandTestArgs_t *args = (nandTestArgs_t *)testArgs;

    UART_printf("\n***********************\n");
    UART_printf(  "       NAND Test       \n");
    UART_printf(  "***********************\n");

    if(args == NULL)
    {
        UART_printf("Invalid Test Arguments!\n");
        UART_printf("Aborting the Test!!\n");
        return (TEST_FAIL);
    }

    if(args->autoRun == FALSE)
    {
        /* Read test inputs from user if needed */
    }

    testStatus = run_nand_test(args);
    if(testStatus != TEST_PASS)
    {
        UART_printf("\nNAND Flash Test Failed!\n");
    }
    else
    {
        UART_printf("\nNAND Flash Test Passed!\n");
    }

    UART_printf("\nNAND Flash Tests Completed!!\n");
    UART_printf("\n-----------------X-----------------\n\n\n");

    return (testStatus);

} // nandTest

/**
 * \brief Invokes nand test functions
 *
 */
int main(void)
{
    TEST_STATUS        testStatus;
    Platform_STATUS    status;
    nandTestArgs_t     testArgs;
    Board_initCfg      boardCfg;

    testArgs.autoRun     = 0;
    testArgs.blockLen    = BYTES_PER_PAGE;
    testArgs.blockNum    = 0;
    testArgs.devId       = PLATFORM_DEVID_MT29F2G16ABAFA;
    testArgs.testPattern = 0xAA;

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

    /* Invoke NAND flash Test */
    testStatus = nandTest(&testArgs);
    if(testStatus != TEST_PASS)
    {
    	return (-1);
    }

    return (0);
}

/* Nothing past this point */

