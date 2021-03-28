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
 * \file  oled_display_test.c
 *
 * \brief This file contains oled display test functions.
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART_stdio.h>

#ifdef SOC_K2G
#include "diag_common_cfg.h"
#endif

#include "board.h"
#include "board_cfg.h"
#include "oled_display.h"
#include "icek2g_oled.h"

/* GPIO pin value definitions */
#define GPIO_PIN_VAL_LOW     (0U)
#define GPIO_PIN_VAL_HIGH    (1U)

#define GPIO_INDEX           (0U)

/* Port and pin number mask for LCD GPIO.
   Bits 7-0: Pin number  and Bits 15-8: Port number */
#define LCD_BST_CONV_CTL_GPIO    0x002D
#define LCD_RESET                0x0134

extern I2C_config_list I2C_config;
extern void BOARD_delay(uint32_t usecs);

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    LCD_BST_CONV_CTL_GPIO | GPIO_CFG_OUTPUT,
    LCD_RESET | GPIO_CFG_OUTPUT,
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL
};

GPIO_v0_Config GPIO_v0_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};

/**
 *  \brief    This function executes oled display detection test
 *
 *  \param    void
 *
 * \return
 * \n         TEST_PASS  - Test Passed
 * \n         TEST_FAIL  - Test Failed
 */
static TEST_STATUS oled_display_detect_test(void)
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

    handle = I2C_open(BOARD_OLED_DISPLAY_INSTANCE, &i2cParams);
	if(handle == NULL)
	{
		UART_printf("I2C Handle open failed");
		return(TEST_FAIL);
	}

    I2C_transactionInit(&i2cTransaction);
	i2cTransaction.slaveAddress = OLED_SLAVE_ADDR;
	i2cTransaction.writeBuf = &tx;
	i2cTransaction.writeCount = 1;
	i2cTransaction.readBuf = &rx;
	i2cTransaction.readCount = 0;
	tx = 0x81;
	rx = 0x0;
	I2C_transfer(handle, &i2cTransaction);
	BOARD_delay(1000);
	i2cTransaction.writeCount = 0;
	i2cTransaction.readCount = 1;

	I2C_transfer(handle, &i2cTransaction);
	if(rx == 0x0)
    {
        UART_printf ("Oled display Detection Failed!\n");
        return(TEST_FAIL);
    }

    UART_printf ("\nOled display Detection Successful!\n");

	I2C_close(handle);
    return (TEST_PASS);
}

/**
 * \brief	This function configures voltage regulator gpio's for lcd
 *
 * \param	void
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
static TEST_STATUS lcd_gpio_config(void)
{
    GPIO_write(GPIO_INDEX, GPIO_PIN_VAL_HIGH);
    BOARD_delay(1000);
    GPIO_write(GPIO_INDEX, GPIO_PIN_VAL_LOW);

    GPIO_write(1, GPIO_PIN_VAL_LOW);
    BOARD_delay(1000);
    GPIO_write(1, GPIO_PIN_VAL_HIGH);

	return (TEST_PASS);
}

/**
 *  \brief    This function is used to perform Oled display detection
 *            test and Oled display position test
 *
 *  \param    void
 *
 * \return
 * \n         TEST_PASS  - Test Passed
 * \n         TEST_FAIL  - Test Failed
 */
static TEST_STATUS run_oled_display_test(void)
{
	OLED_RET retVal;
	TEST_STATUS testStatus;

	GPIO_init();

	testStatus = lcd_gpio_config();
	if(testStatus != TEST_PASS)
	{
		UART_printf("\n gpio_config Failed\n");
		return (testStatus);
	}

    UART_printf("\nRunning Oled display Detect Test\n");

    testStatus = oled_display_detect_test();
    if(testStatus != TEST_PASS)
	{
		UART_printf("\nOled display Detect Test Failed!!\n");
		return (testStatus);
	}
	else
	{
		UART_printf("\nOled display Detect Test Passed!\n");
	}

    retVal = oledInit();
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("oledInit: oled module init Failed\n");
		return (TEST_FAIL);
	}
	retVal = clear();
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("clear: oled screen clear Failed\n");
		return (TEST_FAIL);
	}
	retVal = setline(0);
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("setline: line setting to first Failed\n");
		return (TEST_FAIL);
	}
	retVal = setOrientation(1);
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("setOrientation: Horizontal orientation Failed\n");
		return (TEST_FAIL);
	}
	retVal = printstr((int8_t *)"Welcome");
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("printstr: Oled print Failed\n");
		return (TEST_FAIL);
	}
	BOARD_delay(2000);
	retVal = clear();
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("clear: oled screen clear Failed\n");
		return (TEST_FAIL);
	}
	retVal = setline(1);
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("setline: line setting to second Failed\n");
		return (TEST_FAIL);
	}
	retVal = setOrientation(1);
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("setOrientation: Horizontal orientation Failed\n");
		return (TEST_FAIL);
	}
	retVal = printstr((int8_t *)"K2G ICE EVM");
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("printstr: Oled print Failed\n");
		return (TEST_FAIL);
	}
	BOARD_delay(500000);
	retVal = clear();
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("clear: oled screen clear Failed\n");
		return (TEST_FAIL);
	}
	//print two lines
	retVal = setline(0);
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("setline: line setting to first Failed\n");
		return (TEST_FAIL);
	}
	retVal = setOrientation(1);
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("setOrientation: Horizontal orientation Failed\n");
		return (TEST_FAIL);
	}
	retVal = printstr((int8_t *)"Welcome");
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("printstr: Oled print Failed\n");
		return (TEST_FAIL);
	}
	retVal = setline(1);
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("setline: line setting to second Failed\n");
		return (TEST_FAIL);
	}
	retVal = printstr((int8_t *)"K2G ICE EVM");
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("printstr: Oled print Failed\n");
		return (TEST_FAIL);
	}
	BOARD_delay(500000);
	retVal = scrollDisplayLeft();
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("scrollDisplayLeft: Left scroll Failed\n");
		return (TEST_FAIL);
	}
	BOARD_delay(2000000);
	retVal = scrollDisplayRight();
	if (retVal != OLED_SUCCESS)
	{
		UART_printf("scrollDisplayRight: Right scroll Failed\n");
		return (TEST_FAIL);
	}
	BOARD_delay(1000000);

	if (retVal == OLED_SUCCESS)
	{
		UART_printf("OLED LCD Display test PASS\n");
		return TEST_PASS;
	}
	else
	{
		UART_printf("OLED LCD Display test FAIL\n");
		return TEST_FAIL;
	}

    return (testStatus);
}

/**
 * \brief This function performs Oled display test
 *
 * \param void
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
TEST_STATUS oledTest(void)
{
	TEST_STATUS testStatus = 0;

	UART_printf("\n********************************\n");
	UART_printf(  "        OLED DISPLAY Test       \n");
	UART_printf(  "********************************\n");

	//Release OLED reset
	GPIO_init();
	GPIO_write(0, 1);

	testStatus = run_oled_display_test();
	if(testStatus != 0)
	{
		UART_printf("\nOled display Test Failed!\n");
	}
	else
	{
		UART_printf("\nOled display Test Passed!\n");
	}

	UART_printf("\nOled Tests Completed!!\n");
	UART_printf("\n-----------------X-----------------\n\n\n");

	return (testStatus);

} // oledTest

/**
 * \brief Invokes oled test functions
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
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

    /* Invoke oled Test */
    testStatus = oledTest();
    if(testStatus != TEST_PASS)
    {
    	return (-1);
    }

    return (0);
}
