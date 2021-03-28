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
 * \file  rotary_switch_test.c
 *
 * \brief This file contains rotary switch test functions.
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/csl/soc.h>

#include "diag_common_cfg.h"

#include "board.h"
#include "board_cfg.h"

#if defined(SOC_AM65XX)
/* Platform test return type */
typedef	int16_t TEST_STATUS;
/* Platform test return codes */
#define TEST_PASS     (0)
#define TEST_FAIL     (-1)
#endif

extern I2C_config_list I2C_config;
extern void BOARD_delay(uint32_t usecs);


/**
 *  \brief    This function executes rotary switch detection test
 *
 *  \param    void
 *
 * \return
 * \n         TEST_PASS  - Test Passed
 * \n         TEST_FAIL  - Test Failed
 */
static TEST_STATUS rotary_switch_detect_test(void)
{
	uint32_t index;
	I2C_Params i2cParams;
    I2C_Handle handle = NULL;
	uint8_t tx;
	uint8_t rx;
	I2C_Transaction i2cTransaction;
	
	for (index=0; I2C_config[index].fxnTablePtr != NULL; index++)
	{
		((I2C_HwAttrs *)I2C_config[index].hwAttrs)->enableIntr = false;
	}
	
	I2C_init();

    I2C_Params_init(&i2cParams);
#if defined (DIAG_COMPLIANCE_TEST)
	 i2cParams.bitRate = I2C_400kHz; /* 400KHz */
#endif
    handle = I2C_open(BOARD_ROTARY_SWICH_INSTANCE, &i2cParams);
	if(handle == NULL)
	{
		UART_printf("I2C Handle open failed");
		return(TEST_FAIL);
	}
	
    I2C_transactionInit(&i2cTransaction);
	i2cTransaction.slaveAddress = BOARD_I2C_ROTARY_SWITCH;
	i2cTransaction.writeBuf = &tx;
	i2cTransaction.writeCount = 1;
	i2cTransaction.readBuf = &rx;
	i2cTransaction.readCount = 0;
	tx = 0x0;
	rx = 0x0;
	I2C_transfer(handle, &i2cTransaction);

    BOARD_delay(1000);

	i2cTransaction.writeCount = 0;
	i2cTransaction.readCount = 1;
	
	I2C_transfer(handle, &i2cTransaction);
	if(rx == 0x0)
    {
        UART_printf ("Rotary switch Detection Failed!\n");
        return(TEST_FAIL);
    }

    UART_printf ("\nRotary switch Detection Successful!\n");

	I2C_close(handle);
    return (TEST_PASS);
}

/**
 *  \brief    This function executes rotary switch position indicator test
 *
 *  \param    void
 *
 * \return
 * \n         TEST_PASS  - Test Passed
 * \n         TEST_FAIL  - Test Failed
 */
static TEST_STATUS rotary_switch_position_test(void)
{
	uint32_t index;
	I2C_Params i2cParams;
    I2C_Handle handle = NULL;
	TEST_STATUS testStatus;
	uint8_t  regRdBuf;
	uint8_t  regWrBuf;
	I2C_Transaction i2cTransaction;
	
	for (index=0; I2C_config[index].fxnTablePtr != NULL; index++)
	{
		((I2C_HwAttrs *)I2C_config[index].hwAttrs)->enableIntr = false;
	}
	
	I2C_init();

    I2C_Params_init(&i2cParams);

    handle = I2C_open(BOARD_ROTARY_SWICH_INSTANCE, &i2cParams);
	if(handle == NULL)
	{
		UART_printf("I2C Handle open failed");
		return(TEST_FAIL);
	}
	
    I2C_transactionInit(&i2cTransaction);
	i2cTransaction.slaveAddress = BOARD_I2C_ROTARY_SWITCH;
	i2cTransaction.writeBuf = &regWrBuf;
	i2cTransaction.writeCount = 0;
	i2cTransaction.readBuf = &regRdBuf;
	i2cTransaction.readCount = 1;
	regWrBuf = 0x0;
	regRdBuf = 0x0;
	I2C_transfer(handle, &i2cTransaction);

	BOARD_delay(1000);
	
	/*Make the higher nibble of Input Port Register to 0 to reset don't care bits*/
	regRdBuf = regRdBuf & 0x0f;
	if(regRdBuf == 0x01)
	{
		UART_printf("The rotary switch is at position 1\n");
		I2C_close(handle);
		testStatus = TEST_PASS;
	}
	else if(regRdBuf == 0x02)
	{
		UART_printf("The rotary switch is at position 2\n");
		I2C_close(handle);
		testStatus = TEST_PASS;
	}
	else if(regRdBuf == 0x03)
	{
		UART_printf("The rotary switch is at position 3\n");
		I2C_close(handle);
		testStatus = TEST_PASS;
	}
	else if(regRdBuf == 0x04)
	{
		UART_printf("The rotary switch is at position 4\n");
		I2C_close(handle);
		testStatus = TEST_PASS;
	}
	else if(regRdBuf == 0x05)
	{
		UART_printf("The rotary switch is at position 5\n");
		I2C_close(handle);
		testStatus = TEST_PASS;
	}
	else if(regRdBuf == 0x06)
	{
		UART_printf("The rotary switch is at position 6\n");
		I2C_close(handle);
		testStatus = TEST_PASS;
	}
	else if(regRdBuf == 0x07)
	{
		UART_printf("The rotary switch is at position 7\n");
		I2C_close(handle);
		testStatus = TEST_PASS;
	}
	else if(regRdBuf == 0x08)
	{
		UART_printf("The rotary switch is at position 8\n");
		I2C_close(handle);
		testStatus = TEST_PASS;
	}
	else if(regRdBuf == 0x09)
	{
		UART_printf("The rotary switch is at position 9\n");
		I2C_close(handle);
		testStatus = TEST_PASS;
	}
	else if(regRdBuf == 0x00)
	{
		UART_printf("The rotary switch is at position 0\n");
		I2C_close(handle);
		testStatus = TEST_PASS;
	}
	else
	{
		UART_printf("Unknown position Rotary switch position test failed\n");
		I2C_close(handle);
		testStatus = TEST_FAIL;
	}

	return(testStatus);
}

/**
 *  \brief    This function is used to perform Rotary switch detection
 *            test and Rotary switch position test
 *
 *  \param    void
 *
 * \return
 * \n         TEST_PASS  - Test Passed
 * \n         TEST_FAIL  - Test Failed
 */
static TEST_STATUS run_rotary_switch_test(void)
{
	TEST_STATUS testStatus;

    UART_printf("\nRunning Rotary switch Detect Test\n");

    testStatus = rotary_switch_detect_test();
    if(testStatus != TEST_PASS)
	{
		UART_printf("\nRotary switch Detect Test Failed!!\n");
		return (testStatus);
	}
	else
	{
		UART_printf("\nRotary switch Detect Test Passed!\n");
	}
	
    UART_printf("\nRunning Rotary switch position Test\n\n");

    testStatus = rotary_switch_position_test();
    if(testStatus != TEST_PASS)
    {
   	    UART_printf("\nRotary switch position Test Failed!!\n");
   		return (testStatus);
   	}
   	else
   	{
		UART_printf("\nRotary switch position Test Passed!\n");
	}

    return (testStatus);
}

/**
 * \brief This function performs Rotary switch Test test
 *
 * \param void
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
static TEST_STATUS rotaryswitchTest(void)
{
	TEST_STATUS testStatus = 0;
	int8_t p = 'r';

	UART_printf("\n********************************\n");
	UART_printf(  "       ROTARY SWITCH Test       \n");
	UART_printf(  "********************************\n");

	do {
		testStatus = run_rotary_switch_test();
		UART_printf("\nPress 'r' to run the test again,\n");
		UART_printf("or any other character to exit: ");
#if defined (DIAG_COMPLIANCE_TEST)
		p='y';
#else
		UART_scanFmt("%c", &p);
#endif
        if (p == 'r') UART_printf("\nRunning rotary switch test again\n");
	} while (p == 'r');
	if(testStatus != 0)
	{
		UART_printf("\nRotary switch Test Failed!\n");
	}
	else
	{
		UART_printf("\nRotary switch Test Passed!\n");
	}

	UART_printf("\nRotary switch Tests Completed!!\n");
	UART_printf("\n-----------------X-----------------\n\n\n");

	return (testStatus);

} // rotaryswitchTest

/**
 * \brief Invokes rotary switch test functions
 *
 */
int main(void)
{
    TEST_STATUS      testStatus;
    Board_initCfg    boardCfg;

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

#if defined(SOC_AM65XX) && !defined (__aarch64__)
    /* MCU I2C instance will be active by default for R5 core.
     * Need update HW attrs to enable MAIN I2C instance.
     */
    enableMAINI2C(0, CSL_I2C0_CFG_BASE);
#endif

    /* Invoke Rotary switch Test */
    testStatus = rotaryswitchTest();
    if(testStatus != TEST_PASS)
    {
    	return (-1);
    }

    return (0);
}
/* Nothing past this point */
