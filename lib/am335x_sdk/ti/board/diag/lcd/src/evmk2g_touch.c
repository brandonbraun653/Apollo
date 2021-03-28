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
 * \file    evmk2g_touch.c
 *
 * \brief   This file contains functions for touch driver
 *
 ******************************************************************************/
#include <string.h>
#include "platform_internal.h"

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/csl/soc.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

/* Port and pin number mask for touch input.
   Bits 7-0: Pin number  and Bits 15-8: Port number */
#define GPIO_TOUCH_INPUT    (TOUCH_GPIO_PIN_NUM | (TOUCH_GPIO_INSTANCE << 8))

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
	GPIO_TOUCH_INPUT | GPIO_CFG_INPUT
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

static I2C_Params touchI2cParams;
static I2C_Handle touchI2cHandle = NULL;

extern I2C_config_list I2C_config;

/******************************************************************************
 **                      INTERNAL FUNCTION DEFINITIONS
 ******************************************************************************/

/**
 *
 * \brief     Function to configure the TOUCH GPIO.
 *
 * \return    NONE.
 *
 */
static void gpioTouchIntConfigure(void)
{
	GPIO_init();
}

/**
 *
 * \brief     Function to read the status of TOUCH GPIO.
 *
 * \return    0 : if GPIO pin is HIGH.
 *            1 : if GPIO pin is LOW.
 *
 */
uint8_t touchGpioPinRead(void)
{
	uint8_t ret;

	/* Assuming it as active low. Pin goes LOW when there is touch signal */
	ret = GPIO_read(0);

	return (!ret);
}

/**
 *
 * \brief     Function to write the data into touch controller register.
 *
 * \param     reg  [IN] : Register to be written.
 * \param     data [IN] : Data to write into the register.
 *
 * \return    TOUCH_SUCCESS  : On Success.
 *            TOUCH_ERR      : On Failure.
 *
 */
int8_t touchWrite(uint8_t reg, uint8_t data)
{
	I2C_Transaction i2cTransaction;
	uint8_t slaveData[2];
	bool ret = 0;

	slaveData[0] = reg;
	slaveData[1] = data;
    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = TOUCH_SLAVE_ADDR;
    i2cTransaction.writeBuf     = (uint8_t *)&slaveData[0];
    i2cTransaction.writeCount   = 2;
    i2cTransaction.readCount    = 0;

	ret = I2C_transfer(touchI2cHandle, &i2cTransaction);
	if (!ret) {
		IFPRINT (UART_printf("touchWrite: i2c Write error - %d\n", ret));
		ret = TOUCH_ERR;
	}

	return (TOUCH_SUCCESS);
}

/**
 *
 * \brief     Function to read data from the touch controller reg.
 *
 * \param     reg [IN] : Register to be read.
 *
 * \return    Data read from register : On Success.
 *            TOUCH_ERR               : On Failure.
 *
 */
int8_t touchRead(uint32_t reg, uint8_t *data)
{
	I2C_Transaction i2cTransaction;
	uint8_t txData[2];
	bool ret = 0;

	txData[0] = reg;
    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = TOUCH_SLAVE_ADDR;
    i2cTransaction.writeBuf     = &txData[0];
    i2cTransaction.writeCount   = 1;
    i2cTransaction.readBuf      = data;
    i2cTransaction.readCount    = 1;

	ret = I2C_transfer(touchI2cHandle, &i2cTransaction);
	if (!ret) {
		IFPRINT (UART_printf("touchRead - i2c Read error - %d\n", ret));
		return TOUCH_ERR;
	}

	return (TOUCH_SUCCESS);
}

/**
 *
 * \brief     Function to get all the value of Touch Panel registers
 *            from [00h to 1Fh] and save in the array.
 *
 * \param     data [IN]	: Buffer to store the touch data read
 * 			  touches	: No: of touch points
 *
 * \return    TOUCH_SUCCESS	:  On Success.
 *            TOUCH_ERR		:  On Failure.
 *
 */
int8_t touchGetAllData(uint16_t data[][DIMENSIONS], uint8_t touches)
{
	int8_t ret = 0;
	uint8_t regVal = 0;
	uint8_t i;
	uint8_t x = 0;
	uint8_t y = 1;

	memset(data, 0x0, sizeof(data));

	for (i = 0; i < touches; i++)
	{
		ret = touchRead(TOUCH1_XH + (i * 0x6), &regVal);
		if (ret == TOUCH_ERR) {
			IFPRINT (UART_printf("touchRead failed with %d\n", ret));
			UART_printf("touchRead failed with %d\n", ret);
			return TOUCH_ERR;
		}
		if (regVal & 0x80) {
			UART_printf("pen-down for Touch%d\n", i+1);
			data[i][x] = (regVal & 0x0F) << 8;

			ret = touchRead(TOUCH1_XL + (i * 0x6), &regVal);
			if (ret == TOUCH_ERR) {
				IFPRINT (UART_printf("touchRead failed with %d\n", ret));
				return TOUCH_ERR;
			}
			else
				data[i][x] |= regVal;

			ret = touchRead(TOUCH1_YH + (i * 0x6), &regVal);
			if (ret == TOUCH_ERR) {
				IFPRINT (UART_printf("touchRead failed with %d\n", ret));
				return TOUCH_ERR;
			}
			else
				data[i][y] = (regVal & 0x0F) << 8;

			ret = touchRead(TOUCH1_YL + (i * 0x6), &regVal);
			if (ret == TOUCH_ERR) {
				IFPRINT (UART_printf("touchRead failed with %d\n", ret));
				return TOUCH_ERR;
			}
			else
				data[i][y] |= regVal;

		}
	}

	return (TOUCH_SUCCESS);
}

/**
 *
 * \brief     Function to configure the touch controller and clear
 *            the status registers if the touch already exists.
 *
 * \return    TOUCH_SUCCESS : On Success.
 *            TOUCH_ERR     : On Failure.
 *
 */
int8_t touchSetup(void)
{
	int8_t ret = 0;
	int32_t timeOut = 15 * DELAY/2; /* 15 seconds */
//	uint16_t TouchDump[5][2];
	uint8_t regVal = 0;
	uint8_t touch, numTouches;

	/* ID reads */
	UART_printf("\n=====================================\n");
	/* Chip Vendor ID */
	ret = touchRead(ID_G_CIPHER, &regVal);
	if (ret) {
		goto err;
	}
	UART_printf("Chip Vendor ID:---------------->0x%x\n", regVal);

	/* CTPM Vendor's Chip ID */
	ret = touchRead(ID_G_FT5201ID, &regVal);
	if (ret) {
		goto err;
	}
	UART_printf("CTPM Vendor's Chip ID:--------->0x%x\n", regVal);

	/* Firmware ID */
	ret = touchRead(ID_G_FIRMID, &regVal);
	if (ret) {
		goto err;
	}
	UART_printf("Firmware ID:------------------->0x%x\n", regVal);

	/* Firmware version High */
	ret = touchRead(ID_G_LIB_VERSION_H, &regVal);
	if (ret) {
		goto err;
	}
	UART_printf("Firmware version High byte:---->0x%x\n", regVal);

	/* Firmware version Low */
	ret = touchRead(ID_G_LIB_VERSION_L, &regVal);
	if (ret) {
		goto err;
	}
	UART_printf("Firmware version Low byte:----->0x%x\n", regVal);
	UART_printf("=====================================\n\n");

	UART_printf("Touch Setup in Progress.. Please wait...\n");

	/* Calibration */
	ret = touchWrite(ID_G_AUTO_CLB_MODE, 0x00);
	if (ret) {
		goto err;
	}

	/* Delay of 10ms */
	platform_delay(10000);

	while (1)
	{
		ret = touchRead(ID_G_AUTO_CLB_MODE, &regVal);
		if (ret) {
			goto err;
		}
		if (!regVal)
			break;
	}

	ret = touchWrite(DEVICE_MODE, NORMAL_OPMODE);
	if (ret) {
		goto err;
	}

	ret = touchWrite(ID_G_THGROUP, 0x10);
	if (ret) {
		goto err;
	}

	ret = touchWrite(ID_G_THPEAK, 0x3c);
	if (ret) {
		goto err;
	}

	ret = touchWrite(ID_G_THCAL, 0x1d);
	if (ret) {
		goto err;
	}

	ret = touchWrite(ID_G_THWATER, 0xd3);
	if (ret) {
		goto err;
	}

	ret = touchWrite(ID_G_TEMP, 0xeb);
	if (ret) {
		goto err;
	}

	ret = touchWrite(ID_G_THDIFF, 0xa0);
	if (ret)
		goto err;

	ret = touchWrite(ID_G_TIME_ENTER_MONITOR, 0xc8);
	if (ret) {
		goto err;
	}

	ret = touchWrite(ID_G_PERIODACTIVE, 0x06);
	if (ret) {
		goto err;
	}

	ret = touchWrite(ID_G_PERIODMONITOR, 0x28);
	if (ret) {
		goto err;
	}
	ret = touchWrite(ID_G_MODE, 0x01);
	if (ret) {
		goto err;
	}

	/* Sometimes when initializing a touch already exists, we're going to
	   clear it. Timeout is set for 15 seconds */
	do
	{
		touch = touchGpioPinRead();
		ret = touchRead(TD_STATUS, &regVal);
		if (ret < 0)
		{
			IFPRINT (UART_printf("Error in getting touch data\n"));
			goto err;
		}

		touch |= numTouches;
		platform_delay(DELAY);
		timeOut -= DELAY;
	} while (touch && (timeOut <= 0));


err :
	if (ret != 0) {
		IFPRINT (UART_printf("Error in doing touch setup\n"));
	}

	return (ret);
}

/**
 *
 * \brief     Function to initialize the touch controller.
 *
 * No input parameters.
 *
 * \return    NONE.
 *
 */
int8_t touchInit(void)
{
	uint32_t index;

	/* Configure GPIO pin */
	gpioTouchIntConfigure();

	for (index = 0; I2C_config[index].fxnTablePtr != NULL; index++)
	{
		((I2C_HwAttrs *)I2C_config[index].hwAttrs)->enableIntr = false;
	}

	/* Initialize I2C module */
    I2C_init();
    I2C_Params_init(&touchI2cParams);

    touchI2cHandle = I2C_open(TOUCH_I2C_INSTANCE, &touchI2cParams);
    if(touchI2cHandle == NULL)
    {
		return (-1);
	}

	return (0);
}

/* Nothing past this point */
