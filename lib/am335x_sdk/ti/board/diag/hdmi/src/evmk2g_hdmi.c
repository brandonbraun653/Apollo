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
 * \file    evmk2g_hdmi.c
 *
 * \brief   This file contains the hdmi functions
 *
 ******************************************************************************/
#include <string.h>
#include "platform_internal.h"
#include "board_internal.h"

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/csl/soc.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

/* Port and pin number mask for HDMI enable and interrupt pins.
   Bits 7-0: Pin number  and Bits 15-8: Port number */
#define GPIO_HDMI_ENABLE    (HDMI_ENABLE_GPIO_PIN | (HDMI_ENABLE_GPIO_INSTANCE << 8))
#define GPIO_HDMI_INT       (HDMI_INT_GPIO_PIN | (HDMI_INT_GPIO_INSTANCE << 8))

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
	GPIO_HDMI_ENABLE | GPIO_CFG_OUTPUT,
	GPIO_HDMI_INT | GPIO_CFG_INPUT
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL,
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

static I2C_Params hdmiI2cParams;
static I2C_Handle hdmiI2cHandle = NULL;

/******************************************************************************
 **                          GLOBAL DEFINITIONS
 ******************************************************************************/

static uint8_t audioInfoFrame[15] = {
	0xC2,    /* Audio InfoFrame Enable required for the HDMI Transmitter
		    (programs register 0xBF) */
	0x84,    /* frame type */
	0x01,    /* version */
	0x0A,    /* length */
	0x00,    /* cksum */
	HDMI_SH_PCM | HDMI_SH_TWO_CHANNELS,
	HDMI_SH_44KHz | HDMI_SH_16BIT,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static uint8_t hdmi_reg_defs[] = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05,
		0x06, 0x07, 0x08, 0x09, 0x0A, 0x1A,
		0x1B, 0x1E, 0x1F, 0x20, 0x21, 0x22,
		0x23, 0x24,	0x25, 0x26, 0x27, 0x29,
		0x2A, 0xBC, 0xBD, 0xBE, 0xC7};


/******************************************************************************
 **                      INTERNAL FUNCTION DEFINITIONS
 ******************************************************************************/

/**
 *
 * \brief    This function is used to write the data onto HDMI chip.
 *
 * \param    reg   [IN]  : HDMI register to write.
 * \param    data  [IN]  : Data to be written into the register.
 *
 * \return   HDMI_SUCCESS	- On Success.
 *           HDMI_ERR		- On Failure.
 *
 */
static int8_t hdmiWrite(uint8_t reg, uint8_t data)
{
	I2C_Transaction i2cTransaction;
	uint8_t slaveData[2];
	bool ret;

    I2C_transactionInit(&i2cTransaction);
	slaveData[0] = reg;
	slaveData[1] = data;

    i2cTransaction.slaveAddress = HDMI_SLAVE_ADDR;
    i2cTransaction.writeBuf     = (uint8_t *)&slaveData[0];
    i2cTransaction.writeCount   = 2;
    i2cTransaction.readCount    = 0;

	/* Delay of 1 milli sec */
	platform_delay(1000);

	ret = I2C_transfer(hdmiI2cHandle, &i2cTransaction);
	if (!ret) {
		IFPRINT(UART_printf("hdmiWrite: i2c Write error : ret = %d\n", ret));
		return (HDMI_ERR);
	}

	return (HDMI_SUCCESS);
}

/**
 *
 * \brief    This function is used to read the data from HDMI chip.
 *
 * \param    reg     [IN]	: Register to read the data.
 * \param    data    [IN]	: Pointer to store the data read.
 * \param    dataLen [IN]	: Length of the data to be read in bytes.
 *
 * \return   HDMI_SUCCESS	- On Success.
 *           HDMI_ERR		- On Failure.
 *
 */
static int8_t hdmiRead(uint32_t reg, uint8_t *data, uint32_t dataLen)
{
	I2C_Transaction i2cTransaction;
	uint8_t txData[2];
	bool ret;

	txData[0] = reg;
    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = HDMI_SLAVE_ADDR;
    i2cTransaction.writeBuf     = &txData[0];
    i2cTransaction.writeCount   = 1;
    i2cTransaction.readBuf      = data;
    i2cTransaction.readCount    = 1;

	ret = I2C_transfer(hdmiI2cHandle, &i2cTransaction);
	if (!ret) {
		IFPRINT(UART_printf("hdmiRead: i2c Read error : read = %d\n", ret));
		return (HDMI_ERR);
	}

	return (HDMI_SUCCESS);
}

/**
 *
 * \brief    This function is used to mute or unmute the HDMI audio.
 *
 * \param    mute [IN]		: Mute/Unmute HDMI Audio.
 *           HDMI_AUDIO_UNMUTE	: Unmute.
 *           HDMI_AUDIO_MUTE	: Mute.
 *
 * \return   HDMI_SUCCESS	- On Success
 *           HDMI_ERR		- On Failure
 *
 */
static int8_t hdmiAudioMute(uint8_t mute)
{
	int8_t ret;

	if (!mute) {
        /* I2S, UnMute, PCM */
		ret = hdmiWrite(HDMI_REG_26, 0x81);
		if (ret) {
			goto err;
		}
	}
	else {
		/* I2S, Mute, PCM */
		ret = hdmiWrite(HDMI_REG_26, 0x91);
	}

err :
	return (ret);
}

/**
 *
 * \brief    This function is used to initialize HDMI Audio
 *
 * \return   HDMI_SUCCESS	- On Success.
 *           HDMI_ERR		- On Failure.
 *
 */
static int8_t hdmiAudioSetup(void)
{
	int8_t ret;
	uint8_t val;
	uint8_t ckSum;
	uint8_t i;
	uint8_t miscInfoFrameDataStart;

	/* Power Up Transistor set to D0 power state 00 to 0x1E address */
	val = 0;
	ret = hdmiWrite(HDMI_TPI_POWER_STATE_CTRL_REG, val);
	if (ret) {
		goto err;
	}

	/* security HDCP disabled */
	ret = hdmiWrite(HDMI_TPI_HDCP_CONTROLDATA_REG, val);
	if (ret) {
		goto err;
	}

	/* Delay of 64 milli sec */
	platform_delay(64000);

	do
	{
		ret = hdmiRead(HDMI_TPI_HDCP_QUERYDATA_REG, &val, 1);
		if (ret) {
			goto err;
		}
	} while(!((val & 0xF0) == 0x00));

	/* Disable TMDS output, select HDMI */
	val = 0x11;
	ret = hdmiWrite(HDMI_SYS_CTRL_DATA_REG, val);
	if (ret) {
		goto err;
	}

	/* Delay of 128 milli sec */
	platform_delay(128000);

	ret = hdmiRead(HDMI_SYS_CTRL_DATA_REG, &val, 1);
	if (ret) {
		goto err;
	}
	IFPRINT (UART_printf("HDMI_SYS_CTRL_DATA_REG = 0x%x\n", val));

	/* Mute audio */
	ret = hdmiAudioMute(HDMI_AUDIO_MUTE);
	if (ret) {
		IFPRINT (UART_printf("HDMI Audio Mute failed\n"));
		goto err;
	}

	/* I2S Input configuration : Rising, 256fs ,ws-low=left, left justify,
	   MSB 1st, 1 bit shift */
	ret = hdmiWrite(HDMI_REG_20, 0x90);
	if (ret) {
		goto err;
	}

	/* Select SD pin SD0 to be connected to FIFO */
	ret = hdmiWrite(HDMI_REG_1F, 0x80);
	if (ret) {
		goto err;
	}

	/* Disable SD pin SD1 */
	ret = hdmiWrite(HDMI_REG_1F, 0x19);
	if (ret) {
		goto err;
	}

	/* Disable SD pin SD2 */
	ret = hdmiWrite(HDMI_REG_1F, 0x2A);
	if (ret) {
		goto err;
	}

	/* Disable SD pin SD3 */
	ret = hdmiWrite(HDMI_REG_1F, 0x3B);
	if (ret) {
		goto err;
	}

	/* 16bit, 44.1kHz, 2 channel = 0x50 */
	ret = hdmiWrite(HDMI_REG_27, 0x50);
	if (ret) {
		goto err;
	}

	ret = hdmiWrite(HDMI_REG_21, 0x0);
	if (ret) {
		goto err;
	}

	ret = hdmiWrite(HDMI_REG_22, 0x0);
	if (ret) {
		goto err;
	}

	ret = hdmiWrite(HDMI_REG_23, 0x0);
	if (ret) {
		goto err;
	}

	/* 44.1KHz Sampling frequency */
	ret = hdmiWrite(HDMI_REG_24, 0x0);
	if (ret) {
		goto err;
	}

	/* 16bit word length */
	ret = hdmiWrite(HDMI_REG_25, 0x02);
	if (ret) {
		goto err;
	}

	ret = hdmiRead(HDMI_REG_25, &val, 1);
	if (ret) {
		goto err;
	}
	IFPRINT (UART_printf("HDMI_REG_25 = 0x%x\n", val));

	ckSum = 0;

	for (i = 1; i < 15; i++)
	{
		ckSum += audioInfoFrame[i];
	}
	audioInfoFrame[4] = 0x100 - ckSum;

	/* Audio InfoFrame information */

	miscInfoFrameDataStart = 0xBF;

	for (i = 0; i < sizeof(audioInfoFrame); i++)
	{
		ret = hdmiWrite(miscInfoFrameDataStart, audioInfoFrame[i]);
		if (ret) {
			goto err;
		}
		ret = hdmiRead(miscInfoFrameDataStart, &val, 1);
		if (ret) {
			goto err;
		}
		IFPRINT (UART_printf("0x%x = 0x%x\n", miscInfoFrameDataStart,
				       val));
		miscInfoFrameDataStart++;
	}

	/* Decode Level 0 Packets */
	ret = hdmiWrite(HDMI_REG_BC, 0x02);
	if (ret) {
		goto err;
	}

	ret = hdmiWrite (HDMI_REG_BD, 0x24);
	if (ret) {
		goto err;
	}

	ret = hdmiWrite(HDMI_REG_BE, 0x02);
	if (ret) {
		goto err;
	}

	/* Unmute audio */
	ret = hdmiAudioMute(HDMI_AUDIO_UNMUTE);
	if (ret) {
		IFPRINT (UART_printf("HDMI Audio UnMute failed\n"));
		goto err;
	}

	/* Enable TMDS output */
	ret = hdmiWrite(HDMI_SYS_CTRL_DATA_REG, 0x01);

err :
	if (ret != 0) {
		IFPRINT (UART_printf("Error during HDMI audio setup - %d\n", ret));
	}

	return (ret);
}
/**
 *
 * \brief    Configures GPIO pins for HDMI controller.
 *
 * \return   NONE.
 *
 */
static void hdmiGpioSetup(void)
{
	GPIO_init();
	GPIO_write(0, 0);
}

/**
 *
 * \brief   Initializes the HDMI controller.
 *
 * \param   NULL.
 *
 * \return  NONE.
 *
 */
int8_t hdmiInit(void)
{
	uint32_t index;

	/* GPIO Initialization */
	hdmiGpioSetup();

	for (index = 0; I2C_config[index].fxnTablePtr != NULL; index++)
	{
		((I2C_HwAttrs *)I2C_config[index].hwAttrs)->enableIntr = false;
	}

	/* Initialize I2C module */
    I2C_init();
    I2C_Params_init(&hdmiI2cParams);

    hdmiI2cHandle = I2C_open(HDMI_I2C_INSTANCE, &hdmiI2cParams);
    if(hdmiI2cHandle == NULL)
    {
		return (-1);
	}

	return (0);
}

/**
 *
 * \brief    This function is used to set all the registers to enable
 *           the HDMI transmitter.
 *
 * \param    NULL.
 *
 * \return  HDMI_SUCCESS	- On Success.
 *          HDMI_ERR		- On Failure.
 *
 */
int8_t hdmiHwEnable(void)
{
	int8_t err, i;
	uint8_t	vals[14];
	uint8_t val;
	uint16_t horizontalRes;
	uint16_t verticalRes;
	uint16_t pixelClk;
	uint8_t hdmi_reg_val[1] = {0};

	memset(vals, 0, 14);

	horizontalRes = 0;
	verticalRes   = 0;
	pixelClk      = 0;

	/*  Fill the TPI Video Mode Data structure */
	vals[0] = (pixelClk & 0xFF);                /* Pixel clock */
	vals[1] = ((pixelClk & 0xFF00) >> 8);
	vals[2] = VERTICAL_FREQ;                    /* Vertical freq */

	/* register programming information on how vertical freq is to be
	   programmed to Hdmi not clear. Hence setting to 60 for now */
	vals[3] = 0x00;
	vals[4] = (horizontalRes & 0xFF);           /* Horizontal pixels*/
	vals[5] = ((horizontalRes & 0xFF00) >> 8);
	vals[6] = (verticalRes & 0xFF);             /* Vertical pixels */
	vals[7] = ((verticalRes & 0xFF00) >> 8);

	/*  Write out the TPI Video Mode Data */
	for (i = 0; i <= 7; i++)
	{
		err = hdmiWrite(HDMI_TPI_VIDEO_DATA_BASE_REG + i, vals[i]);
		if (err != 0) {
			IFPRINT(UART_printf("ERROR: writing TPI video mode"
					       " data\n"));
			return (err);
		}
	}

    /* Write out the TPI Input bus and pixel repetition Data:
	   (24 bit wide bus, falling edge, no pixel replication, 1:1
	   CLK ration) */
	val = TPI_AVI_PIXEL_REP_BUS_24BIT |
		  TPI_AVI_PIXEL_REP_FALLING_EDGE |
		  TPI_AVI_PIXEL_REP_NONE | TPI_CLK_RATIO_1X;

	err = hdmiWrite(HDMI_TPI_PIXEL_REPETITION_REG, val);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: writing TPI pixel repetition data\n"));
		return (err);
	}

	/*  Write out the TPI AVI Input Format */
	val = TPI_AVI_INPUT_BITMODE_8BIT |
		  TPI_AVI_INPUT_RANGE_AUTO |
		  TPI_AVI_INPUT_COLORSPACE_RGB;

	err = hdmiWrite(HDMI_TPI_AVI_IN_FORMAT_REG, val);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: writing TPI AVI Input format\n"));
		return (err);
	}

	/*  Write out the TPI AVI Output Format */
	val = TPI_AVI_OUTPUT_CONV_BT709 |
		TPI_AVI_OUTPUT_RANGE_AUTO |
		TPI_AVI_OUTPUT_COLORSPACE_RGBHDMI;

	err = hdmiWrite(HDMI_TPI_AVI_OUT_FORMAT_REG, val);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: writing TPI AVI output format\n"));
		return (err);
	}

	/* Write out the TPI System Control Data to power down */
	val = TPI_SYS_CTRL_POWER_DOWN;
	err = hdmiWrite(HDMI_SYS_CTRL_DATA_REG, val);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: writing TPI power down control"
				       " data\n"));
		return (err);
	}

	/* Move from ENABLED -> FULLY ENABLED Power State  */
	val = TPI_AVI_POWER_STATE_D0;
	err = hdmiWrite(HDMI_TPI_POWER_STATE_CTRL_REG, val);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Setting device power state to D0\n"));
		return (err);
	}

	/* Write out the TPI System Control Data to power up and
	 * select output mode
	 */
	val = TPI_SYS_CTRL_POWER_ACTIVE | TPI_SYS_CTRL_OUTPUT_MODE_HDMI;
	err = hdmiWrite(HDMI_SYS_CTRL_DATA_REG, val);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Writing system control data\n"));
		return (err);
	}

	/* Delay of 20 milli sec */
	platform_delay(20000);

	/*  Read back TPI System Control Data to latch settings */
	err = hdmiRead(HDMI_SYS_CTRL_DATA_REG, &val, 1);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Reading system control data\n"));
		return (err);
	}

	/* HDCP */
	val = 0; /* DISABLED */
	err = hdmiWrite(HDMI_TPI_HDCP_CONTROLDATA_REG, val);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Writing HDCP control data"));
		return (err);
	}

	IFPRINT(UART_printf("hdmi enabled\n"));

#if 0
	for (i = 0; i < sizeof(hdmi_reg_defs); i++) {
		err = hdmiRead(hdmi_reg_defs[i], hdmi_reg_val, 1);
		if (err != 0) {
			UART_printf("ERROR: Reading reg 0x%x\n", hdmi_reg_defs[i]);
		}
		else
			UART_printf("Value at reg 0x%x = 0x%x\n", hdmi_reg_defs[i], hdmi_reg_val[0]);
	}
#endif

	return HDMI_SUCCESS;
}

/**
 * \brief    Enables the power state of HDMI controller.
 *
 * \return  HDMI_SUCCESS	-      On Success
 *          HDMI_ERR		-      On Failure
 *
 */
int8_t hdmiConnect(void)
{
	int err = 0;

	IFPRINT(UART_printf("hdmiConnect: CONNECT\n"));

	/* Move from LOW -> ENABLED Power state */
	err = hdmiWrite(HDMI_TPI_POWER_STATE_CTRL_REG,
			        TPI_AVI_POWER_STATE_D2);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Setting device power state"
				       " to D2\n"));
	}

	return (err);
}

/**
 * \brief    Reads the HDMI edid information.
 *
 * \param    data	 [IN] Pointer to the data buffer
 * \param    dataLen [IN] Length of edid data to be read.
 *
 * \return   HDMI_SUCCESS	- On Success
 *           HDMI_ERR		- On Failure
 *
 */
int8_t hdmiReadEdid(uint8_t *data, uint32_t dataLen)
{
	int8_t err =  0;
	uint32_t len = dataLen;
	uint8_t val = 0;
	int8_t retries = 0;

	len = (len < HDMI_EDID_MAX_LEN) ? len : HDMI_EDID_MAX_LEN;

	/* Request DDC bus access to read EDID info from HDTV */
	IFPRINT(UART_printf("Reading HDMI EDID\n"));

	val = 0;
	err = hdmiRead(0x3D, &val, 1);
	if (err != 0) {
		IFPRINT(UART_printf(	"ERROR: Reading Monitor Status register\n"));
		return (err);
	}
	IFPRINT(UART_printf("Monitor status reg read Val = 0x%x\n", val));
	if (val & 0x2) {
		IFPRINT(UART_printf(" MONITOR PRESENT \n"));
	} else {
		IFPRINT(UART_printf(" MONITOR NOT PRESENT \n"));
	}

	/* Disable TMDS clock */
	val = 0x11;
	err = hdmiWrite(HDMI_SYS_CTRL_DATA_REG, val);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Failed to disable TMDS clock\n"));
		return (err);
	}
	val = 0;

	/* Read TPI system control register*/
	err = hdmiRead(HDMI_SYS_CTRL_DATA_REG, &val, 1);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Reading DDC BUS REQUEST\n"));
		return (err);
	}

	/* The host writes 0x1A[2]=1 to request the
	 * DDC(Display Data Channel) bus
	 */
	val |= TPI_SYS_CTRL_DDC_BUS_REQUEST;
	err = hdmiWrite(HDMI_SYS_CTRL_DATA_REG, val);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Writing DDC BUS REQUEST\n"));
		return (err);
	}

	/*  Poll for bus DDC Bus control to be granted */
	IFPRINT(UART_printf("Poll for DDC bus access\n"));
	val = 0;
	do {
		err = hdmiRead(HDMI_SYS_CTRL_DATA_REG, &val, 1);
		if (retries++ > 100) {
			IFPRINT(UART_printf("Polling for DDC bus access failed\n"));
			return (err);
		}

	} while ((val & TPI_SYS_CTRL_DDC_BUS_GRANTED) == 0);

	/*  Close the switch to the DDC */
	val |= TPI_SYS_CTRL_DDC_BUS_REQUEST | TPI_SYS_CTRL_DDC_BUS_GRANTED;
	err = hdmiWrite(HDMI_SYS_CTRL_DATA_REG, val);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Close switch to DDC BUS REQUEST\n"));
		return (err);
	}

	memset(data, 0, len);

    /* Change I2C SetSlaveAddress to HDMI_I2C_MONITOR_ADDRESS */
	/* Read the EDID structure from the monitor I2C address  */
	err = hdmiRead(0x00, data, len);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Reading EDID\n"));
		return (err);
	}

	/* Release DDC bus access */
	val &= ~(TPI_SYS_CTRL_DDC_BUS_REQUEST | TPI_SYS_CTRL_DDC_BUS_GRANTED);

	retries = 0;
	do {
		err = hdmiWrite(HDMI_SYS_CTRL_DATA_REG, val);
		if (err >= 0) {
			break;
		}
		retries++;
	} while (retries < 5);

	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Releasing DDC Bus Access\n"));
		return (err);
	}

	return HDMI_SUCCESS;
}

/**
 *
 * \brief    This function is used to check the HDMI chip version.
 *
 * \param    chipVer : Pointer to the buffer passed from test app.
 *
 * \return   HDMI_SUCCESS	- On Success.
 *           HDMI_ERR		- On Failure.
 *
 */
int8_t hdmiProbeChipVersion(uint8_t *chipVer)
{
	int8_t err = 0;

	/* Probe for hdmi chip version*/
	err = hdmiWrite(HDMI_REG_TPI_RQB, 0x00);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Writing HDMI configuration to "
				               "reg - SI9022_REG_TPI_RQB\n"));
		return (err);
	}

	err = hdmiRead(HDMI_REG_CHIPID0, chipVer, 1);
	if (err != 0) {
		IFPRINT(UART_printf("ERROR: Reading chip ID\n"));
	}

	return (err);
}

/**
 *
 * \brief    Configures HDMI audio
 *
 * \param    NULL.
 *
 * \return   HDMI_SUCCESS	- On Success
 *           HDMI_ERR		- On Failure
 *
 */
int8_t hdmiAudioConfigure(void)
{
	int8_t ret;

	ret = hdmiAudioSetup();

	return (ret);
}

/* Nothing past this point */
