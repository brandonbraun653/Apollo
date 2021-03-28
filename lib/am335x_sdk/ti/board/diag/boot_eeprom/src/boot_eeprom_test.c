/******************************************************************************
 * Copyright (c) 2017-2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   boot_eeprom_test.c
 *
 *  \brief  Boot EEPROM diagnostic test file
 *
 *  Targeted Functionality: Verification of basic functionality of I2C Boot
 *  EEPROM memory interface.
 *
 *  Operation: This test is used for detection the Boot EEPROM device,
 *  Verification of the Boot EEPROM memory access by writing a Boot EEPROM page
 *  and reading the same page for data verification with a max possible i2c
 *  clock speed.
 *
 *  Supported SoCs: AM65XX & J721E.
 *
 *  Supported Platforms: am65xx_evm, am65xx_idk & j721e_evm.
 *
 */

#include "boot_eeprom_test.h"

extern I2C_config_list I2C_config;

uint8_t pageRdBuff[BOOT_EEPROM_PAGE_SIZE];
uint8_t pageWrBuff[BOOT_EEPROM_PAGE_SIZE + 2];

/**
 *  \brief    Writes the required number of bytes on to the specified page 
 *            offset with a fixed pattern passed.
 *
 *  \param    handle              [IN]   I2C Handler
 *            slaveAddr           [IN]   I2C Slave Address
 *            wrPageAddr          [IN]   Address of a page to be written
 *            pageWrByteCnt       [IN]   Number of bytes of a page to be 
										 written.
 *
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_boot_eeprom_page_write(I2C_Handle handle,
                                               uint8_t slaveAddr,
                                               uint16_t wrPageAddr,
                                               uint16_t pageWrByteCnt)
{   
    int32_t ret = 0;   
    
	I2C_Transaction transaction;
    
    memset(&transaction, 0, sizeof(transaction));
    /*Control Byte followed by write bit */
	transaction.slaveAddress = slaveAddr;
	transaction.writeBuf     = &pageWrBuff[0];
	transaction.writeCount   = (pageWrByteCnt + 2);
	transaction.readCount    = 0;    

    /* Clear the lower half and shifts the upper half to the lower half */
	pageWrBuff[0] = (uint8_t)((wrPageAddr & 0xFF00) >> 8);
    
    /* Clear the upper half */
	pageWrBuff[1] = (uint8_t)(wrPageAddr & 0x00FF);

	BOARD_delay(10000);

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
 *            slaveAddr           [IN]   I2C Slave Address
 *            rdPageAddr          [IN]   Address of a page to be read
 *            pageRdByteCnt       [IN]   Number of bytes of a page to be read.
 *
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_boot_eeprom_page_read(I2C_Handle handle,
                                              uint8_t slaveAddr,
                                              uint16_t rdPageAddr,
                                              uint16_t pageRdByteCnt)
{
	
    int32_t ret = 0;   
	uint8_t tx[2];
    
	I2C_Transaction transaction;

    memset(&transaction, 0, sizeof(transaction));
    /*Control Byte followed by read bit */
	transaction.slaveAddress = slaveAddr;
	transaction.writeBuf     = tx;
	transaction.readBuf      = &pageRdBuff[0];
	transaction.writeCount   = 2;
    transaction.readCount    = 0;
    
    /* Clear the lower half and shifts the upper half to the lower half */
	tx[0] = (uint8_t)((rdPageAddr & 0xFF00) >> 8);
    
    /* Clear the upper half */
	tx[1] = (uint8_t)(rdPageAddr & 0x00FF);

	BOARD_delay(10000);

	ret = I2C_transfer(handle, &transaction);
	if(ret != I2C_STS_SUCCESS)
    {
        UART_printf("\nI2C EEPROM page read failed\n");
        return -1;
    }

    transaction.writeCount   = 0;
    transaction.readCount    = pageRdByteCnt;

	ret = I2C_transfer(handle, &transaction);
	if(ret != I2C_STS_SUCCESS)
    {
        UART_printf("\nI2C EEPROM page read failed\n");
        return -1;
    }

    return 0;
}

/**
 *  \brief    Boot EEPROM device detection test.
 *
 *  \param    handle              [IN]   I2C Handler.
 *
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_boot_eeprom_device_detect_test(I2C_Handle handle)
{
    int8_t ret = 0;
    uint16_t numOfRdBytes, numOfWrBytes, pageAddr;
    uint32_t failIndex = 0;
    bool compareStatus = 1; 
    
    pageAddr = (BOARD_EEPROM_FIRST_PAGE * BOOT_EEPROM_PAGE_SIZE);    
    BoardDiag_genPattern(&pageWrBuff[0],
                         (BOOT_EEPROM_PAGE_SIZE + 2),
                         BOARD_DIAG_TEST_PATTERN_FF);
    /* Clears the first page of the Boot EEPROM device */
    ret = BoardDiag_boot_eeprom_page_write(handle,
                                           BOARD_I2C_BOOT_EEPROM_ADDR,
                                           pageAddr, 
                                           BOOT_EEPROM_PAGE_SIZE);
	if(ret != 0)
    {
		UART_printf("\nClearing EEPROM page first location failed\n");
		return ret;
    }
    
    BoardDiag_genPattern(&pageWrBuff[0], (BOOT_EEPROM_PAGE_SIZE + 2), 
    BOARD_DIAG_TEST_PATTERN_AA);
    numOfWrBytes = 1;    
    /* Writes the first byte of the first page */
    ret = BoardDiag_boot_eeprom_page_write(handle,
                                           BOARD_I2C_BOOT_EEPROM_ADDR,
                                           pageAddr,
                                           numOfWrBytes);
	if(ret != 0)
    {
		UART_printf("\nWriting EEPROM page first location failed\n");
		return ret;
    }
    
    BoardDiag_genPattern(&pageRdBuff[0], BOOT_EEPROM_PAGE_SIZE, 
    BOARD_DIAG_TEST_PATTERN_NULL);
    numOfRdBytes = 1;    
    /* Reads the first byte of the first page */
    ret = BoardDiag_boot_eeprom_page_read(handle,
                                          BOARD_I2C_BOOT_EEPROM_ADDR,
                                          pageAddr,
                                          numOfRdBytes);
	if(ret != 0)
    {
		UART_printf("\nReading EEPROM page first location failed\n");
		return ret;
    }
    
    /* Data comparison */
    compareStatus = BoardDiag_memCompare(&pageWrBuff[2], &pageRdBuff[0], 1, 
                    &failIndex);
    if(!(compareStatus))
    {
        ret = -1;        
    }
    
    return ret;
    
}

/**
 *  \brief    Verifies a page of a boot EEPROM device.
 *
 *  \param    handle              [IN]   I2C Handler
 *            slaveAddr           [IN]   I2C Slave Address
 *            pageOffset          [IN]   Offset number of a page to be verified
 *
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_boot_eeprom_verify_page(I2C_Handle handle,
                                                uint8_t slaveAddr,
                                                uint16_t pageOffset)
{
    int8_t ret = 0;
    uint16_t pageAddr;
    uint32_t failIndex = 0;
    bool compareStatus = 1; 

    pageAddr = pageOffset * (BOOT_EEPROM_PAGE_SIZE);    
    BoardDiag_genPattern(&pageWrBuff[0], (BOOT_EEPROM_PAGE_SIZE + 2), 
    BOARD_DIAG_TEST_PATTERN_FF);
    /* Clears the first page of the Boot EEPROM device */
    ret = BoardDiag_boot_eeprom_page_write(handle,
                                           slaveAddr,
                                           pageAddr,
                                           BOOT_EEPROM_PAGE_SIZE);
	if(ret != 0)
    {
		UART_printf("\nClearing EEPROM page - %d failed\n", pageOffset);
		return ret;
    }
#if defined(DIAG_COMPLIANCE_TEST)
    BoardDiag_genPattern(&pageWrBuff[0], (BOOT_EEPROM_PAGE_SIZE + 2),
    BOARD_DIAG_TEST_PATTERN_AA_55);
#else
    BoardDiag_genPattern(&pageWrBuff[0], (BOOT_EEPROM_PAGE_SIZE + 2), 
    BOARD_DIAG_TEST_PATTERN_AA);
#endif
    /* Writes the first page */
    ret = BoardDiag_boot_eeprom_page_write(handle,
                                           slaveAddr,
                                           pageAddr,
                                           BOOT_EEPROM_PAGE_SIZE);
	if(ret != 0)
    {
		UART_printf("\nWriting EEPROM page - %d failed\n", pageOffset);
		return ret;
    }
	
    BoardDiag_genPattern(&pageRdBuff[0], BOOT_EEPROM_PAGE_SIZE, 
    BOARD_DIAG_TEST_PATTERN_NULL);
    /* Reads the first page */
    ret = BoardDiag_boot_eeprom_page_read(handle,
                                          slaveAddr,
                                          pageAddr,
                                          BOOT_EEPROM_PAGE_SIZE);
	if(ret != 0)
    {
		UART_printf("\nReading EEPROM page - %d failed\n", pageOffset);
		return ret;
    }
    
    /* Data comparison */
    compareStatus = BoardDiag_memCompare(&pageWrBuff[2], &pageRdBuff[0], 
                    BOOT_EEPROM_PAGE_SIZE, &failIndex);
    if(!(compareStatus))
    {
		UART_printf("\nData comparison failed at - %d location of page %d\n",  
        failIndex, pageOffset);
        ret = -1;        
    }        

    return ret;
}

/**
 *  \brief    Performs the boundary verification by validating the first and  
 *            last page of boot EEPROM device.
 *
 *  \param    handle              [IN]   I2C Handler
 *            slaveAddr           [IN]   I2C slave Address
 *
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_boot_eeprom_boundary_verification_test(I2C_Handle handle)
{
    int8_t ret = 0;
    uint16_t pageAddr;
    
#if defined(SOC_J721E)
    UART_printf("\n\nVerifying Boot EEPROM First Block\n");
#endif
    UART_printf("\nVerifying the Boot EEPROM first page...\n"); 
    /* Verifies the boot EEPROM first page */
    ret = BoardDiag_boot_eeprom_verify_page(handle,
                                            BOARD_I2C_BOOT_EEPROM_ADDR,
                                            BOARD_EEPROM_FIRST_PAGE);
    if(ret != 0)
    {
        UART_printf("\nBoot EEPROM first page verification failed\n"); 
        return ret;
    }

    pageAddr = BOARD_EEPROM_FIRST_PAGE * (BOOT_EEPROM_PAGE_SIZE);
    BoardDiag_genPattern(&pageWrBuff[0], (BOOT_EEPROM_PAGE_SIZE + 2), 
    BOARD_DIAG_TEST_PATTERN_FF);
    /* Clears the first page of the Boot EEPROM device */
    ret = BoardDiag_boot_eeprom_page_write(handle,
                                           BOARD_I2C_BOOT_EEPROM_ADDR,
                                           pageAddr,
                                           BOOT_EEPROM_PAGE_SIZE);
	if(ret != 0)
    {
		UART_printf("\nClearing EEPROM first page failed\n");
		return ret;
    }
#if !defined(DIAG_COMPLIANCE_TEST)
    UART_printf("\nVerifying the Boot EEPROM last page...\n"); 
    /* Verifies the boot EEPROM last page */
    ret = BoardDiag_boot_eeprom_verify_page(handle,
                                            BOARD_I2C_BOOT_EEPROM_ADDR,
                                            BOARD_EEPROM_LAST_PAGE);
    if(ret != 0)
    {
        UART_printf("\nBoot EEPROM last page verification failed\n"); 
        return ret;
    }
    
    pageAddr = BOARD_EEPROM_LAST_PAGE * (BOOT_EEPROM_PAGE_SIZE);
    BoardDiag_genPattern(&pageWrBuff[0], (BOOT_EEPROM_PAGE_SIZE + 2), 
    BOARD_DIAG_TEST_PATTERN_FF);
    /* Clears the last page of the Boot EEPROM device */
    ret = BoardDiag_boot_eeprom_page_write(handle,
                                           BOARD_I2C_BOOT_EEPROM_ADDR,
                                           pageAddr,
                                           BOOT_EEPROM_PAGE_SIZE);
	if(ret != 0)
    {
		UART_printf("\nClearing EEPROM last page failed\n");
		return ret;
    }
#if defined(SOC_J721E)
    UART_printf("\n\nVerifying Boot EEPROM Second Block\n");
    UART_printf("\n\nVerifying the Boot EEPROM first page...");

    ret = BoardDiag_boot_eeprom_verify_page(handle,
                                            BOARD_I2C_BOOT_EEPROM_ADDR2,
                                            BOARD_EEPROM_BLOCK2_FIRST_PAGE);
    if(ret != 0)
    {
        UART_printf("\nBoot EEPROM first page verification failed\n");
        return ret;
    }

    pageAddr = BOARD_EEPROM_BLOCK2_FIRST_PAGE * (BOOT_EEPROM_PAGE_SIZE);
    BoardDiag_genPattern(&pageWrBuff[0], (BOOT_EEPROM_PAGE_SIZE + 2),
                         BOARD_DIAG_TEST_PATTERN_FF);
    /* Clears the first page of the second block */
    ret = BoardDiag_boot_eeprom_page_write(handle,
                                           BOARD_I2C_BOOT_EEPROM_ADDR2,
                                           pageAddr,
                                           BOOT_EEPROM_PAGE_SIZE);
    if(ret != 0)
    {
        UART_printf("\nClearing EEPROM first page failed\n");
        return ret;
    }

    UART_printf("\n\nVerifying the Boot EEPROM last page...\n");
    /* Verifies the boot EEPROM last page */
    ret = BoardDiag_boot_eeprom_verify_page(handle,
                                            BOARD_I2C_BOOT_EEPROM_ADDR2,
                                            BOARD_EEPROM_BLOCK2_LAST_PAGE);
    if(ret != 0)
    {
        UART_printf("\nBoot EEPROM last page verification failed\n");
        return ret;
    }

    pageAddr = BOARD_EEPROM_BLOCK2_LAST_PAGE * (BOOT_EEPROM_PAGE_SIZE);
    BoardDiag_genPattern(&pageWrBuff[0], (BOOT_EEPROM_PAGE_SIZE + 2),
    BOARD_DIAG_TEST_PATTERN_FF);
    /* Clears the last page of the Boot EEPROM device */
    ret = BoardDiag_boot_eeprom_page_write(handle,
                                           BOARD_I2C_BOOT_EEPROM_ADDR2,
                                           pageAddr,
                                           BOOT_EEPROM_PAGE_SIZE);
	if(ret != 0)
    {
		UART_printf("\nClearing EEPROM last page failed\n");
		return ret;
    }
#endif
#endif
	return ret;
}

/**
 *  \brief    Runs the boot EEPROM diagnostic test.
 *
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_run_boot_eeprom_test(void)
{
    int8_t ret = 0;
    uint8_t index;

    I2C_Params i2cParams;
    I2C_HwAttrs i2cConfig;
    I2C_Handle handle = NULL;

#if ((defined(SOC_J721E)) && (defined (__aarch64__)))
    /* Enabling MCU I2C */
    enableI2C(CSL_MCU_I2C0_CFG_BASE);
#endif
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

#if defined(SOC_J721E)
    GPIO_v0_HwAttrs gpioCfg;
    GPIO_socGetInitCfg(0, &gpioCfg);
    gpioCfg.baseAddr = CSL_WKUP_GPIO0_BASE;
    GPIO_socSetInitCfg(0, &gpioCfg);
    GPIO_init();
    /* Making Write protect line low to enable write access */
    GPIO_write(0, GPIO_SIGNAL_LOW);
#endif

    UART_printf("\nDetecting the Boot EEPROM device...\n"); 

    /* Detects the boot EEPROM device */
    ret = BoardDiag_boot_eeprom_device_detect_test(handle);    
    if(ret == 0)
    {
        UART_printf("\nBoot EEPROM device detection successful\n"); 

        UART_printf("\nBoot EEPROM boundary verification test...\n"); 
        /* Verifies the boot EEPROM first page */
        ret = BoardDiag_boot_eeprom_boundary_verification_test(handle);
        if(ret != 0)
        {
            UART_printf("\nBoot EEPROM boundary verification test failed\n"); 
            return ret;
        }
        else
        {
            UART_printf("\nBoot EEPROM boundary verification test "
            "successful\n"); 
        }
    }
    else
    {
        UART_printf("\nBoot EEPROM device detection failed\n"); 
    }

    I2C_close(handle);
    
    return ret;    
}

/**
 *  \brief    The function performs the Boot EEPROM Diagnostic test.
 *
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_boot_eeprom_test(void)
{
	int8_t ret = 0;

	UART_printf("\n*********************************************\n"); 
	UART_printf("*              Boot EEPROM Test                  *\n");
	UART_printf("*********************************************\n");    

    UART_printf("\nRunning Boot EEPROM test\n");             
    
    ret = BoardDiag_run_boot_eeprom_test();
    if(ret == 0)
    {
        UART_printf("\nBoot EEPROM test Passed\n");             
    }
    else
    {
        UART_printf("\nBoot EEPROM test Failed\n");                     
    }
       
    return ret;
    
}

/**
 *  \brief   Boot EEPROM Diagnostic test main function
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

#if defined(SOC_AM65XX) && !defined (__aarch64__)
    /* MCU I2C instance will be active by default for R5 core.
     * Need update HW attrs to enable MAIN I2C instance.
     */
    enableMAINI2C(1, CSL_I2C1_CFG_BASE);
#endif

	return BoardDiag_boot_eeprom_test();
}
