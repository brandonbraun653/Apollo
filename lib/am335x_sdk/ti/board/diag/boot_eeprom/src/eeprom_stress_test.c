/******************************************************************************
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   eeprom_stress_test.c
 *
 *  \brief  EEPROM stress test file
 *
 *  Targeted Functionality: Verification of I2C Boot and Board ID EEPROM memory
 *  interfaces under stress conditions.
 *
 *  Operation: This test verifies all the EEPROM pages by writing them with a
 *  fixed pattern and read back the same.
 *
 *  Supported SoCs: AM6X & J721E.
 *
 *  Supported Platforms: am65xx_evm, am65xx_idk & j721e_evm.
 *
 */

#include "eeprom_stress_test.h"

extern I2C_config_list I2C_config;

uint8_t pageRdBuff[BOOT_EEPROM_PAGE_SIZE];
uint8_t pageWrBuff[BOOT_EEPROM_PAGE_SIZE + 2];

/**
 *  \brief    Writes the required number of bytes on to the specified page
 *            address with a fixed pattern.
 *
 *  \param    handle              [IN]   I2C Handler
 *            slaveAddr           [IN]   I2C Slave Address of Boot or Board
 *                                       ID EEPROM device
 *            wrPageAddr          [IN]   Address of the page to be written
 *            pageWrByteCnt       [IN]   Number of bytes of a page to be
 *                                       written.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_eeprom_page_write(I2C_Handle handle,
                                          uint8_t slaveAddr,
                                          uint16_t wrPageAddr,
                                          uint16_t pageWrByteCnt)
{
    int8_t ret = 0;

    I2C_Transaction transaction;
    memset(&transaction, 0, sizeof(transaction));

    /* Control Byte followed by write bit */
    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &pageWrBuff[0];
    transaction.writeCount   = (pageWrByteCnt + 2);
    transaction.readCount    = 0;

    pageWrBuff[0] = (uint8_t)((wrPageAddr & 0xFF00) >> 8);
    pageWrBuff[1] = (uint8_t)(wrPageAddr & 0x00FF);

    BOARD_delay(100000);

    ret = I2C_transfer(handle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        UART_printf("\nI2C EEPROM page write failed\n");
        return -1;
    }

    return 0;
}

/**
 *  \brief    Reads the required number of bytes from a specified page offset.
 *
 *  \param    handle              [IN]   I2C Handler
 *            slaveAddr           [IN]   I2C Slave Address of Boot or Board
 *                                       ID EEPROM device
 *            rdPageAddr          [IN]   Address of a page to be read
 *            pageRdByteCnt       [IN]   Number of bytes of a page to be read.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_eeprom_page_read(I2C_Handle handle,
                                         uint8_t slaveAddr,
                                         uint16_t rdPageAddr,
                                         uint16_t pageRdByteCnt)
{
    int32_t ret = 0;
    uint8_t tx[2];

    I2C_Transaction transaction;

    memset(&transaction, 0, sizeof(transaction));

    /* Control Byte followed by read bit */
    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = tx;
    transaction.readBuf      = &pageRdBuff[0];
    transaction.writeCount   = 2;
    transaction.readCount    = 0;

    tx[0] = (uint8_t)((rdPageAddr & 0xFF00) >> 8);
    tx[1] = (uint8_t)(rdPageAddr & 0x00FF);

    BOARD_delay(100000);

    ret = I2C_transfer(handle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        UART_printf("\nI2C EEPROM page read failed\n");
        return -1;
    }

    transaction.writeCount = 0;
    transaction.readCount  = pageRdByteCnt;

    ret = I2C_transfer(handle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        UART_printf("\nI2C EEPROM page read failed\n");
        return -1;
    }

    return 0;
}

/**
 *  \brief    Clears all the EEPROM pages used for testing.
 *
 *  \param    handle              [IN]   I2C Handler
 *            slaveAddr           [IN]   I2C Slave Address of Boot or Board
 *                                       ID EEPROM device
 *            pageSize            [IN]   Pages size of the EEPROM device.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_eeprom_clear_all_pages(I2C_Handle handle,
                                               uint8_t slaveAddr,
                                               uint16_t pageSize)
{
    int8_t ret = 0;
    uint16_t pageOffset;
    uint16_t pageAddr = 0;

    for(pageOffset = BOARD_EEPROM_FIRST_PAGE; pageOffset <=
        BOARD_EEPROM_LAST_PAGE;    pageOffset++)
    {
        pageAddr = pageOffset * (pageSize);
        BoardDiag_genPattern(&pageWrBuff[0], (pageSize + 2),
                             BOARD_DIAG_TEST_PATTERN_FF);

        /* Clears a EEPROM page */
        ret = BoardDiag_eeprom_page_write(handle,
                                          slaveAddr,
                                          pageAddr,
                                          pageSize);
        if(ret != 0)
        {
            UART_printf("\nClearing EEPROM page - %d failed\n", pageOffset);
        }
    }

    return ret;
}

/**
 *  \brief    Verifies a all pages of a EEPROM devices under stress conditions.
 *
 *  \param    handle              [IN]   I2C Handler
 *            slaveAddr           [IN]   I2C Slave Address of Boot or Board
 *                                       ID EEPROM device
 *            pageSize            [IN]   Pages size of the EEPROM device.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_eeprom_verify_all_pages(I2C_Handle handle,
                                                uint8_t slaveAddr,
                                                uint16_t pageSize)
{
    int8_t ret = 0;
    uint16_t pageOffset;
    uint16_t pageAddr = 0;
    uint32_t failIndex = 0;
    bool compareStatus = 1; 
    
    for(pageOffset = BOARD_EEPROM_FIRST_PAGE; pageOffset <=
        BOARD_EEPROM_LAST_PAGE; pageOffset++)
    {
        UART_printf("\nVerifying the page number - %d\n", pageOffset);
        
        pageAddr = pageOffset * (pageSize);
        BoardDiag_genPattern(&pageWrBuff[0],
                             (pageSize + 2),
                             BOARD_DIAG_TEST_PATTERN_FF);

        /* Clears a EEPROM page */
        ret = BoardDiag_eeprom_page_write(handle,
                                          slaveAddr,
                                          pageAddr,
                                          pageSize);
        if(ret != 0)
        {
            UART_printf("\nClearing EEPROM page - %d failed\n", pageOffset);
            return ret;
        }

        BoardDiag_genPattern(&pageWrBuff[0],
                             (pageSize + 2),
                             BOARD_DIAG_TEST_PATTERN_RANDOM);
        /* Writes a EEPROM page */
        ret = BoardDiag_eeprom_page_write(handle,
                                          slaveAddr,
                                          pageAddr,
                                          pageSize);
        if(ret != 0)
        {
            UART_printf("\nWriting to EEPROM page - %d failed\n", pageOffset);
            return ret;
        }

        BoardDiag_genPattern(&pageRdBuff[0],
                             pageSize,
                             BOARD_DIAG_TEST_PATTERN_NULL);
        /* Reads a EEPROM page */
        ret = BoardDiag_eeprom_page_read(handle,
                                         slaveAddr,
                                         pageAddr,
                                         pageSize);
        if(ret != 0)
        {
            UART_printf("\nReading a EEPROM page - %d failed\n", pageOffset);
            return ret;
        }

        /* Data comparison */
        compareStatus = BoardDiag_memCompare(&pageWrBuff[2],
                                             &pageRdBuff[0],
                                             pageSize,
                                             &failIndex);
        if(!(compareStatus))
        {
            UART_printf("\nData comparison failed at - %d location of page %d\n",
            failIndex, pageOffset);
            ret = -1;
        }
     }

    return ret;

}

/**
 *  \brief    Runs the EEPROM Stress test to verify the boot and
 *            board ID EEPROM.
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_EepromStressTest(void)
{
    int8_t ret = 0;
    uint8_t index;
    I2C_Params i2cParams;
    I2C_HwAttrs i2cConfig;
    I2C_Handle handle = NULL;

    for(index = 0; index < I2C_HWIP_MAX_CNT; index++)
    {
        I2C_socGetInitCfg(index, &i2cConfig);
        i2cConfig.enableIntr = false;
        I2C_socSetInitCfg(index, &i2cConfig);
    }

    /* Initializes the I2C */
    I2C_init();

    /* Initializes the I2C Parameters */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz; /* 400KHz */

    /* Configures the I2C instance with the passed parameters*/
    handle = I2C_open(BOARD_I2C_BOOT_EEPROM_INSTANCE, &i2cParams);
    if(handle == NULL)
    {
        UART_printf("\nI2C Open failed!\n");
        ret = -1;
        return ret;
    }

    UART_printf("\nVerifying the Boot EEPROM interface under stress "
                "conditions...\n");
    /* Verifies all boot EEPROM pages */
    ret = BoardDiag_eeprom_verify_all_pages(handle,
                                            BOARD_I2C_BOOT_EEPROM_ADDR,
                                            BOOT_EEPROM_PAGE_SIZE);
    if(ret != 0)
    {
        UART_printf("\nBoot EEPROM memory verification failed under stress "
                    "conditions\n");
        return ret;
    }
    else
    {
        UART_printf("\nBoot EEPROM memory verification Successful under stress "
                    "conditions\n");
    }

    UART_printf("\nClearing the Boot EEPROM pages used for testing...\n");
    ret = BoardDiag_eeprom_clear_all_pages(handle,
                                           BOARD_I2C_BOOT_EEPROM_ADDR,
                                           BOOT_EEPROM_PAGE_SIZE);
    if(ret != 0)
    {
        UART_printf("\nClearing the Boot EEPROM pages failed...\n");
    }
    else
    {
        UART_printf("\nClearing the Boot EEPROM pages successful...\n");
    }

    I2C_close(handle);

    return ret;
}

/**
 *  \brief   Boot EEPROM Stress test main function
 *
 *  \return  int - EEPROM Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
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
    
    UART_printf("\n*******************************************\n");
    UART_printf("*           Boot EEPROM Stress Test         *\n");
    UART_printf("*********************************************\n");

#if ((defined(SOC_J721E)) && (defined (__aarch64__)))
    /* Enabling MCU I2C */
    enableI2C(CSL_MCU_I2C0_CFG_BASE);
#endif

    return BoardDiag_EepromStressTest();
}
