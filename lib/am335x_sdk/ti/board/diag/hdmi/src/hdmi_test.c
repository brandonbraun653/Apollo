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
 * \file  hdmi_test.c
 *
 * \brief This file contains hdmi test functions.
 *
 ******************************************************************************/

#include "hdmi_test.h"
#include "platform_internal.h"

#ifdef SOC_K2G
#include "diag_common_cfg.h"
#endif

#if 1
lcdCfg_t hdmiCfg = {
        640,        /** LcdWidth    */
        480,       /** LcdHeight    */
        24750000,  /** LcdPclk      */
        92,        /** HsyncWidth   */
		34,       /** HFrontPorch  */
        34,        /** HBackPorch   */
        3,        /** VsyncWidth   */
        3,        /** VFrontPorch  */
        42,        /** VBackPorch   */
};
#endif
#if 0
lcdCfg_t hdmiCfg = {
        640,        /** LcdWidth    */
        480,       /** LcdHeight    */
        27000000,  /** LcdPclk      */
        44,        /** HsyncWidth   */
        21,       /** HFrontPorch  */
        113,        /** HBackPorch   */
        3,        /** VsyncWidth   */
        10,        /** VFrontPorch  */
        30,        /** VBackPorch   */
};
#endif
#if 0
lcdCfg_t hdmiCfg = {
        1280,        /** LcdWidth    */
        720,       /** LcdHeight    */
        74250000,  /** LcdPclk      */
        81,        /** HsyncWidth   */
        73,        /** HFrontPorch  */
        217,        /** HBackPorch   */
		6,        /** VsyncWidth   */
		3,       /** VFrontPorch  */
		22,        /** VBackPorch   */
};
#endif

//#define ENABLE_HDMI_AUDIO_TEST   (1)

#ifdef ENABLE_HDMI_AUDIO_TEST
TEST_STATUS audioPlayback(void *testArgs);

/**
 * \brief Reads state of the audio dc board detect pin
 *
 * \return
 * \n      0 - Audio DC is connected
 * \n      1 - Audio DC is not connected
 *
 */
static uint32_t check_audiodc_detect(void)
{
	uint32_t gpioState = 0;

    pinMuxSetMode(21, PADCONFIG_MUX_MODE_QUATERNARY);
    gpioSetDirection(0, 21, GPIO_IN);
	gpioState = gpioReadInput(0, 21);

    return(gpioState);
}
#endif

/**
 * \brief Function to display color and read user input or
 *        wait for some time after HDMI display
 *
 *  \param    input [IN]   Flag to indicate wait for user input
 *  \param    color [IN]   Value of Color
 *  \param    name  [IN]   Name of the pattern displayed on HDMI
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
static TEST_STATUS displayColor(uint8_t input, int color, char *name)
{
	uint8_t c = 0;

	if(input == FALSE)
	{
		UART_printf("\rDisplaying %s... WAIT  Press 'y' if %s is displayed, any other key for failure: ", name, name);

		hdmiColorDisplay(&hdmiCfg, color);

		UART_scanFmt("%c", &c);
		if((c == 'y') || (c == 'Y'))
		{
			UART_printf("\rDisplay %s - PASS                                                                            \n", name);
		}
		else
		{
			UART_printf("\rDisplay %s - FAIL                                                                            \n", name);
			return (TEST_FAIL);
		}
	}
	else
	{
		UART_printf("\rDisplaying %s...\n", name);
		hdmiColorDisplay(&hdmiCfg, color);
    	delay_secs(HDMI_DISPLAY_DELAY);
	}

	return (TEST_PASS);
}

/**
 *  \brief    This function performs HDMI, DSS initialization
 *            and verifies HDMI display
 *
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 */
static TEST_STATUS run_hdmi_test(void *testArgs)
{
	hdmiTestArgs_t *args = (hdmiTestArgs_t *)testArgs;
	TEST_STATUS status = TEST_PASS;
	uint8_t c = 0;
#ifdef ENABLE_HDMI_AUDIO_TEST
    audioTestArgs_t audioTestArgs;
    uint32_t        audioDCDetect = 0;

    audioDCDetect = check_audiodc_detect();

    audioTestArgs.autoRun  = 0;
    audioTestArgs.mode     = AUDIO_TEST_MODE_PLAYBACK;

    if(audioDCDetect)
    {
    	audioTestArgs.mcaspNum = MCASP_PORT_0;
	}
	else
	{
		audioTestArgs.mcaspNum = MCASP_PORT_2;
	}

#endif

#if 0
	uint8_t edid[HDMI_EDID_MAX_LENGTH];
#endif
	uint8_t ver;

	/* HDMI i2c init */
	hdmiInit();

	UART_printf("Running HDMI Device Detect Test\n");

	status = hdmiProbeChipVersion(&ver);
	if (status)
	{
		UART_printf("ERROR: Reading HDMI version Id\n");
		UART_printf("HDMI Device Detect Test Failed\n");
		goto err;
	}
	else
	{
		if (ver != HDMI_CHIPID_902x)
		{
			UART_printf("Not a valid verId: 0x%x\n", ver);
			UART_printf("HDMI Device Detect Test Failed\n");
			goto err;
		}
		else
		{
			UART_printf("sil9022 HDMI Chip version ="
						   " %x\n", ver);
		}
	}

	UART_printf("HDMI Device Detect Test Passed\n\n");

	status = hdmiConnect();
	if (status)
	{
		UART_printf("Error in Enabling power for HDMI\n");
        goto err;
	}

	status = hdmiHwEnable();
	if (status)
	{
		UART_printf("Error during enabling HDMI\n");
        goto err;
	}
#if 0
	status = hdmiReadEdid(edid, 256);
	if (status)
	{
		UART_printf("ERROR: Reading HDMI EDID.\n");
        goto err;
	}
	else
	{
		UART_printf("edid[0] = 0x%x edid[1] = 0x%x edid[2]"
					   " = 0x%x\n",edid[0], edid[1], edid[2]);
	}
#endif
	status = hdmiPanelInit(&hdmiCfg);
	if (status != DSS_RET_OK)
	{
		UART_printf("ERROR: Initializing HDMI Panel\n");
        goto err;
	}

	if(args->autoRun == FALSE)
	{
		UART_printf("\rDisplaying Colorbar... WAIT  Press 'y' if Colorbar is displayed, any other key for failure: ");
	}
	else
	{
		UART_printf("\rDisplaying Colorbar...\n");
	}

	hdmiColorBarDisplay(&hdmiCfg);

	if(args->autoRun == FALSE)
	{
		UART_scanFmt("%c", &c);
		if((c == 'y') || (c == 'Y'))
		{
			UART_printf("\rDisplay Colorbar   - PASS                                                                            \n");
		}
		else
		{
			UART_printf("\rDisplay Colorbar   - FAIL                                                                            \n");
			return (TEST_FAIL);
		}
	}
	else
	{
    	delay_secs(HDMI_DISPLAY_DELAY);
	}

	if(displayColor(args->autoRun, HDMI_WHITE, "WHITE"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, HDMI_BLUE, "BLUE"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, HDMI_GREEN, "GREEN"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, HDMI_RED, "RED"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, HDMI_PURPLE, "PURPLE"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, HDMI_PINK, "PINK"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, HDMI_BLACK, "BLACK"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, HDMI_YELLOW, "YELLOW"))
	{
		return (TEST_FAIL);
	}

#ifdef ENABLE_HDMI_AUDIO_TEST

	UART_printf("\nRunning HDMI Audio Test\n");
	UART_printf("Audio Tone Should be Played on HDMI Device Connected\n");

	if(audioDCDetect)
	{
		UART_printf("\nINFO: Audio DC is not Connected\n");
	}
	else
	{
		UART_printf("\nINFO: Audio DC is Connected\n");
	}

	status = hdmiAudioConfigure();
	if (status != 0)
	{
		UART_printf("ERROR: Initializing HDMI Audio\n");
        goto err;
	}

	hdmiColorBarDisplay(&hdmiCfg);

	if(hdmiAudioPlayback(&audioTestArgs))
	{
		UART_printf("\nHDMI Audio Test Failed!\n");
		status = TEST_FAIL;
	}
	else
	{
		status = TEST_PASS;
	}
#endif

err :	return (status);
}

/**
 * \brief This function performs hdmi test
 *
 * \param testArgs  - Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
TEST_STATUS hdmiTest(void *testArgs)
{
	TEST_STATUS testStatus = TEST_PASS;
	hdmiTestArgs_t *args = (hdmiTestArgs_t *)testArgs;

	UART_printf("\n***********************\n");
	UART_printf(  "       HDMI Test       \n");
	UART_printf(  "***********************\n");

	testStatus = run_hdmi_test(args);
	if(testStatus != TEST_PASS)
	{
		UART_printf("\nHDMI Test Failed!\n");
	}
	else
	{
		//UART_printf("\nHDMI Test Passed!\n");
	}

	UART_printf("\nHDMI Tests Completed!!\n");
	UART_printf("\n-----------------X-----------------\n\n\n");

	return (testStatus);

} // hdmiTest

/**
 * \brief Invokes hdmi test functions
 *
 */
int main(void)
{
    TEST_STATUS     testStatus;
    hdmiTestArgs_t  testArgs;
    Board_initCfg      boardCfg;

    testArgs.autoRun = 0;

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

    /* Invoke HDMI Test */
    testStatus = hdmiTest(&testArgs);
    if(testStatus != TEST_PASS)
    {
    	return (-1);
    }

    return (0);
}

/* Nothing past this point */
