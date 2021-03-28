/*
 * Copyright (c) 2015, Texas Instruments Incorporated
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
*  \file  spi_nor_test.c
*
*  \brief This file contains spi nor test functions.
*
******************************************************************************/

#include "norflash_test.h"

#include <ti/drv/gpio/GPIO.h>
#include <ti/csl/soc.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

#ifdef SOC_K2G
#include "diag_common_cfg.h"
#endif

/* Port and pin number mask for flash hold.
   Bits 7-0: Pin number  and Bits 15-8: Port number */
#define GPIO_FLASH_HOLD      (0x0129)

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
	GPIO_FLASH_HOLD | GPIO_CFG_OUTPUT
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL
};

/* GPIO Driver configuration structure */
GPIO_v0_Config GPIO_v0_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};

/**
 *  \brief    Function to configure SPI NOR flash hold signal
 *
 *
 *  \return None
 */
static void configFlashHold(void)
{
	GPIO_init();
	GPIO_write(0, 1);
}

/**
 *  \brief    Executes SPI NOR flash chip detect test
 *
 *  \param    p_device [IN]   NOR flash device handle
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 */
static TEST_STATUS spi_nor_chip_detect_test(PLATFORM_DEVICE_info *p_device,
                                            void *testArgs)
{
    spiNorTestArgs_t *args = (spiNorTestArgs_t *)testArgs;

    p_device = platform_device_open(args->devId, 0);
    if (p_device == NULL)
    {
       UART_printf("SPI NOR Flash Test: Could Not Open NOR Device; errno = 0x%x \n", platform_errno);
       return (TEST_FAIL);
    }

    UART_printf("Device Id - 0x%X\n", p_device->device_id);
    UART_printf("Manufacturer Id - 0x%X\n", p_device->manufacturer_id);
    UART_printf("Device Width - %d\n", p_device->width);
    UART_printf("Block Count - %d\n", p_device->block_count);
    UART_printf("Page Count - %d\n", p_device->page_count);
    UART_printf("Page Size - %d\n", p_device->page_size);

    platform_device_close(p_device->handle);

    return (TEST_PASS);
}

/**
 *  \brief    Executes SPI NOR flash memory read/write test
 *
 *  \param    p_device [IN]   NOR flash device handle
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 */
static TEST_STATUS spi_nor_memory_access_test(PLATFORM_DEVICE_info *p_device,
                                              void *testArgs)
{
    spiNorTestArgs_t *args = (spiNorTestArgs_t *)testArgs;
    Platform_STATUS  status;
    TEST_STATUS      testStatus = TEST_FAIL;

    uint32_t address;
    uint8_t  *norWrBuf;
    uint8_t  *norRdBuf;
#ifdef ENABLE_MEMORY_BACKUP
    uint8_t  *norBkpBuf;
#endif

    norWrBuf = malloc(args->blockLen);
    norRdBuf = malloc(args->blockLen);

    if((norWrBuf == NULL) ||
       (norRdBuf == NULL))
    {
       UART_printf("SPI NOR Flash Test: Buffer Allocation Failed!\n");
       return (TEST_FAIL);
    }

#ifdef ENABLE_MEMORY_BACKUP
    norBkpBuf = malloc(args->blockLen);
    if(norBkpBuf == NULL)
    {
        UART_printf("SPI NOR Flash Test: Buffer Allocation Failed!\n");
        free(norWrBuf);
        free(norRdBuf);
        return (TEST_FAIL);
    }
#endif

    /* Initialize the test pattern */
    memset(norWrBuf, args->testPattern, args->blockLen);
    memset(norRdBuf, 0, args->blockLen);

    address = ((args->sectNum) * (SPI_NOR_SECTOR_SIZE));

#ifdef ENABLE_MEMORY_BACKUP
    status = platform_device_read(p_device->handle, address,
                                  norBkpBuf, args->blockLen);
    if(status != Platform_EOK)
    {
        UART_printf("SPI NOR Flash Test: Read Failed  errno = 0x%x\n", platform_errno);
        goto free;
    }
#endif

    status = platform_device_write(p_device->handle, address,
                                   norWrBuf, args->blockLen);
    if(status != Platform_EOK)
    {
        UART_printf("SPI NOR Flash Test: Write Test Data Failed  errno = 0x%x\n", platform_errno);
        goto free;
    }

    status = platform_device_read(p_device->handle, address,
                                  norRdBuf, args->blockLen);
    if(status != Platform_EOK)
    {
        UART_printf("SPI NOR Flash Test: Read Test Data Failed  errno = 0x%x\n", platform_errno);
        goto free;
    }

    if (memcmp(norWrBuf, norRdBuf, args->blockLen) != 0)
    {
        UART_printf("SPI NOR Flash Test: Data Verification Failed\n");
        testStatus = TEST_FAIL;
    }
    else
    {
        UART_printf("SPI NOR Flash Test: Data Verification Passed\n");
        testStatus = TEST_PASS;
    }

#ifdef ENABLE_MEMORY_BACKUP
    status = platform_device_erase_block (p_device->handle, args->sectNum);
    if(status != Platform_EOK)
    {
        UART_printf("SPI NOR Flash Test: Erase Failed  errno = 0x%x\n",
                       platform_errno);
        testStatus = TEST_FAIL;
    }

    status = platform_device_write(p_device->handle, address,
                                   norBkpBuf, args->blockLen);
    if(status != Platform_EOK)
    {
        UART_printf("SPI NOR Flash Test: Write Back Original Data Failed  errno = 0x%x\n",
                       platform_errno);
        testStatus = TEST_FAIL;
    }
#endif

free:
    free(norWrBuf);
    free(norRdBuf);
#ifdef ENABLE_MEMORY_BACKUP
    free(norBkpBuf);
#endif

    return (testStatus);
}

/**
 *  \brief    Executes SPI NOR flash memory erase test
 *
 *  \param    p_device [IN]   NOR flash device handle
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 */
static TEST_STATUS spi_nor_erase_test(PLATFORM_DEVICE_info *p_device,
                                      void *testArgs)
{
    spiNorTestArgs_t *args = (spiNorTestArgs_t *)testArgs;
    Platform_STATUS  status;
    TEST_STATUS      testStatus = TEST_FAIL;

    uint32_t index;
    uint32_t address;
    uint8_t  *norRdBuf;
#ifdef ENABLE_MEMORY_BACKUP
    uint8_t  *norBkpBuf;
#endif

    norRdBuf = malloc(SPI_NOR_SECTOR_SIZE);
    if(norRdBuf == NULL)
    {
       UART_printf("SPI NOR Flash Test: Buffer Allocation Failed!\n");
       return (testStatus);
    }

#ifdef ENABLE_MEMORY_BACKUP
    norBkpBuf = malloc(SPI_NOR_SECTOR_SIZE);
    if(norBkpBuf == NULL)
    {
        UART_printf("SPI NOR Flash Test: Buffer Allocation Failed!\n");
        free(norRdBuf);
        return (testStatus);
    }
#endif

    memset(norRdBuf, 0, SPI_NOR_SECTOR_SIZE);

    address = ((args->sectNum) * (SPI_NOR_SECTOR_SIZE));

#ifdef ENABLE_MEMORY_BACKUP
    status = platform_device_read(p_device->handle, address,
                                  norBkpBuf, SPI_NOR_SECTOR_SIZE);
    if(status != Platform_EOK)
    {
        UART_printf("SPI NOR Flash Test: Read Failed  errno = 0x%x\n", platform_errno);
        goto free;
    }
#endif

    status = platform_device_erase_block (p_device->handle, args->sectNum);
    if(status != Platform_EOK)
    {
        UART_printf("SPI NOR Flash Test: Erase Failed for Sector %d  errno = 0x%x\n",
                        args->sectNum, platform_errno);
        goto free;
    }

    status = platform_device_read(p_device->handle, address,
                                  norRdBuf, SPI_NOR_SECTOR_SIZE);
    if(status != Platform_EOK)
    {
        UART_printf("SPI NOR Flash Test: Read Test Data Failed  errno = 0x%x\n", platform_errno);
        goto free;
    }

    for (index = 0; index < SPI_NOR_SECTOR_SIZE; index++)
    {
        if(norRdBuf[index] != 0xFF)
        {
            UART_printf("SPI NOR Flash Test: Erase Data Verification Failed\n");
            testStatus = TEST_FAIL;
            break;
        }
    }

    if(index == SPI_NOR_SECTOR_SIZE)
    {
        UART_printf("SPI NOR Flash Test: Erase Data Verification Passed\n");
        testStatus = TEST_PASS;
    }

#ifdef ENABLE_MEMORY_BACKUP
    status = platform_device_write(p_device->handle, address,
                                   norBkpBuf, SPI_NOR_SECTOR_SIZE);
    if(status != Platform_EOK)
    {
        UART_printf("SPI NOR Flash Test: Write Back Original Data Failed  errno = 0x%x\n",
                       platform_errno);
        testStatus = TEST_FAIL;
    }
#endif

free:
    free(norRdBuf);
#ifdef ENABLE_MEMORY_BACKUP
    free(norBkpBuf);
#endif

    return (testStatus);
}

/**
 *  \brief    Executes SPI NOR flash tests
 *
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 */
static TEST_STATUS run_spi_nor_test(void *testArgs)
{
    PLATFORM_DEVICE_info *p_device = NULL;
    spiNorTestArgs_t     *args = (spiNorTestArgs_t *)testArgs;
    TEST_STATUS          testStatus = TEST_FAIL;

    UART_printf("\nRunning SPI NOR Flash Chip Detect Test\n");
    testStatus = spi_nor_chip_detect_test(p_device, args);
    if(testStatus != TEST_PASS)
    {
        UART_printf("\nSPI NOR Flash Chip Detect Test Failed\n");
        goto TEST_END;
    }
    else
    {
        UART_printf("\nSPI NOR Flash Chip Detect Test Passed\n");
    }

    p_device = platform_device_open(args->devId, 0);
    if (p_device == NULL)
    {
       UART_printf("SPI NOR Flash Test: Could Not Open NOR Device; errno = 0x%x \n",
                       platform_errno);
       return (TEST_FAIL);
    }

    UART_printf("\nRunning SPI NOR Flash Block Erase Test\n");
    testStatus = spi_nor_erase_test(p_device, args);
    if(testStatus != TEST_PASS)
    {
        UART_printf("\nSPI NOR Flash Block Erase Test Failed\n");
        goto TEST_END;
    }
    else
    {
        UART_printf("\nSPI NOR Flash Block Erase Test Passed\n");
    }

    UART_printf("\nRunning SPI NOR Flash Memory Access Test - Test Pattern 1\n");
    args->testPattern = NOR_FLASH_TEST_PATTERN1;
    testStatus = spi_nor_memory_access_test(p_device, args);
    if(testStatus != TEST_PASS)
    {
        UART_printf("\nSPI NOR Flash Memory Access Test Failed\n");
        goto TEST_END;
    }
    else
    {
        UART_printf("\nSPI NOR Flash Memory Access Test Passed\n");
    }

    UART_printf("\nRunning SPI NOR Flash Memory Access Test - Test Pattern 2\n");
    args->testPattern = NOR_FLASH_TEST_PATTERN2;
    testStatus = spi_nor_memory_access_test(p_device, args);
    if(testStatus != TEST_PASS)
    {
        UART_printf("\nSPI NOR Flash Memory Access Test Failed\n");
        goto TEST_END;
    }
    else
    {
        UART_printf("\nSPI NOR Flash Memory Access Test Passed\n");
    }

TEST_END:
    platform_device_close(p_device->handle);

    return (testStatus);
}

/**
 * \brief This function performs spi nor test
 *
 * \param testArgs  - Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
TEST_STATUS spiNorTest(void *testArgs)
{
    TEST_STATUS testStatus;

    spiNorTestArgs_t *args = (spiNorTestArgs_t *)testArgs;

    UART_printf("\n********************************\n");
    UART_printf(  "       SPI NOR Flash Test       \n");
    UART_printf(  "********************************\n");

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

    /* Disable flash hold signal to get the access to SPI flash */
    configFlashHold();

    testStatus = run_spi_nor_test(args);
    if(testStatus != TEST_PASS)
    {
        UART_printf("\nSPI NOR Flash Test Failed!\n");
    }
    else
    {
        UART_printf("\nSPI NOR Flash Test Passed!\n");
    }

    UART_printf("\nSPI NOR Flash Tests Completed!!\n");
    UART_printf("\n-----------------X-----------------\n\n\n");

    return (testStatus);

} // spiNorTest

/**
 * \brief Invokes spi nor test functions
 *
 */
int main(void)
{
    TEST_STATUS         testStatus;
    spiNorTestArgs_t    testArgs;
    Board_initCfg       boardCfg;

    testArgs.autoRun     = 0;
    testArgs.blockLen    = SPI_NOR_SECTOR_SIZE;
    testArgs.sectNum     = 0;
    testArgs.devId       = PLATFORM_DEVID_NORN25Q128A13ESF40F;
    testArgs.testPattern = 0xAA;

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

    /* Invoke SPI NOR Test */
    testStatus = spiNorTest(&testArgs);
    if(testStatus != TEST_PASS)
    {
    	return (-1);
    }

    return (0);
}

/* Nothing past this point */

