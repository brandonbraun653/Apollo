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
*  \file lcd_test.c
*
*  \brief This file contains lcd test functions.
*
******************************************************************************/

#include "lcd_test.h"
#include "platform_internal.h"

#include "board.h"
#include "board_cfg.h"

#ifdef SOC_K2G
#include "diag_common_cfg.h"
#endif

uint16_t touchData[5][DIMENSIONS];

/** LCD Panel configuration for NHD 4.3 -480272EF-ATXL-CTP */
lcdCfg_t lcdCfg = {
        480,        /** LcdWidth    */
        272,        /** LcdHeight    */
        9000000,    /** LcdPclk      */
        41,         /** HsyncWidth   */
        2,          /** HFrontPorch  */
        2,          /** HBackPorch   */
        10,         /** VsyncWidth   */
        2,          /** VFrontPorch  */
        2,          /** VBackPorch   */
};

/**
 *
 * \brief     Function to get touch data.
 *
 * \param     none
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
static int8_t detect_touch_points(void)
{
	uint8_t fTouch;
	uint8_t c = 0;
	uint8_t val = 0;
	int8_t ret;
	uint8_t i, x, y;

	memset(touchData, 0x0, sizeof(touchData));

	ret = touchSetup();
	if (ret)
	{
		UART_printf("Failed to do Touch Setup\n");
		return (TEST_FAIL);
	}
	else
		UART_printf("Touch Setup done\n");


	UART_printf("Please touch with single/multiple fingers on the touchscreen\n");

	while(1)
	{
		fTouch = touchGpioPinRead();
		if (fTouch)
		{
			platform_delay(WAIT_DELAY/2);
			/* Get number of touches */
			ret = touchRead(TD_STATUS, &val);
			val &= 0x7;
		    /* Get and save touch data */
			ret = touchGetAllData(touchData, val);
			if (ret)
			{
				UART_printf("Failed to Get All Touch Data\n");
				return (TEST_FAIL);
			}
			for (i=0, x=0, y=1;i<val;i++)
				UART_printf("Touch point %d X-Loc: %d Y-Loc:%d \n", (i+1), touchData[i][x], touchData[i][y]);

			UART_printf("Press X/x for exiting the test\n");
			UART_printf("Press Y/y to continue\n");
			UART_scanFmt("%c", &c);
			if((c == 'x') || (c == 'X'))
			{
				UART_printf("\nExit...\n");
				break;
			}
			if((c == 'y') || (c == 'Y'))
			{
				UART_printf("\nContinue...\n\n");
			}
		}
	}

	return (TEST_PASS);
}

/**
 *  \brief    Executes Touch tests
 *
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 */
static TEST_STATUS run_touch_test(void *testArgs)
{
	TEST_STATUS status;
	DSS_RET  retVal;
	uint8_t ret;

	status = TEST_PASS;

    ret = touchInit();
	if (ret)
	{
		UART_printf("Touch initialization failed\n");
		return (TEST_FAIL);
	}

    lcdColorDisplay(&lcdCfg, LCD_WHITE);

	UART_printf("Touch Point Read Test\n");

	status = detect_touch_points();
	if (status)
	{
		UART_printf("Touch Point Read Test Failed\n");
		return (status);
	}

	UART_printf("Touch Point Read Test Completed\n");

	return (status);
}

/**
 * \brief Function to display color and read user input or
 *        wait for some time after LCD display
 *
 *  \param    input [IN]   Flag to indicate wait for user input
 *  \param    color [IN]   Value of Color
 *  \param    name  [IN]   Name of the pattern displayed on LCD
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

		lcdColorDisplay(&lcdCfg, color);

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
		lcdColorDisplay(&lcdCfg, color);
    	delay_secs(LCD_DISPLAY_DELAY);
	}

	return (TEST_PASS);
}

/**
 * \brief This function performs lcd initialization, panel initialization
 *        and DSS init
 *
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
TEST_STATUS lcd_display_test(void *testArgs)
{
	lcdTestArgs_t *args = (lcdTestArgs_t *)testArgs;
    TEST_STATUS status = TEST_PASS;
    uint8_t c = 0;
    uint8_t ret;

	ret = pwmInit();
	if (ret)
	{
		UART_printf("PWM initialization failed\n");
		return (TEST_FAIL);
	}

    status = lcdPanelInit(&lcdCfg);
    if (status != DSS_RET_OK)
    {
    	return (TEST_FAIL);
	}

#ifdef DISPLAY_LOGO
    lcdLogoDisplay();
#endif

	if(args->autoRun == FALSE)
	{
		UART_printf("\rDisplaying Colorbar... WAIT  Press 'y' if Colorbar is displayed, any other key for failure: ");
	}
	else
	{
		UART_printf("\rDisplaying Colorbar...\n");
	}

    lcdColorBarDisplay(&lcdCfg);

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
    	delay_secs(LCD_DISPLAY_DELAY);
	}

	if(displayColor(args->autoRun, LCD_WHITE, "WHITE"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, LCD_BLUE, "BLUE"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, LCD_GREEN, "GREEN"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, LCD_RED, "RED"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, LCD_PURPLE, "PURPLE"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, LCD_PINK, "PINK"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, LCD_BLACK, "BLACK"))
	{
		return (TEST_FAIL);
	}

	if(displayColor(args->autoRun, LCD_YELLOW, "YELLOW"))
	{
		return (TEST_FAIL);
	}

    return (TEST_PASS);
}

/**
 *
 * \brief    This function is used to test the LCD backlight by increasing and
 *           decreasing the brightness.
 *
 * No parameters.
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
TEST_STATUS lcd_backlight_test(void)
{
	int8_t  count;
	uint8_t ret;

	/* Set the LCD background to white for backlight test */
	lcdColorDisplay(&lcdCfg, LCD_WHITE);

	ret = pwmInit();
	if (ret)
	{
		UART_printf("PWM initialization failed\n");
		return (TEST_FAIL);
	}

	/* Increase the LCD backlight brightness from 0 to 100% */
	for (count = 0; count <= 100; count++)
	{
		ret = pwmSetDutyCycle(count);
		if (ret)
		{
			return (TEST_FAIL);
		}

		/* Wait for some time */
		platform_delay(30000);
	}

	/* Wait for some time */
	platform_delay(50000);

	/* Decrease the LCD backlight brightness from 100 to 0% */
	for (count = 100; count >= 0; count--)
	{
		ret = pwmSetDutyCycle(count);
		if (ret)
		{
			return (TEST_FAIL);
		}

		/* Wait for some time */
		platform_delay(30000);
	}

	/* Wait for some time */
	platform_delay(250000);

    /* Set LCD backlight brightness to 50% */
	ret = pwmSetDutyCycle(50);
	if (ret)
	{
		return (TEST_FAIL);
	}

	return (TEST_PASS);
}

/**
 *  \brief    Executes LCD tests
 *
 *  \param    testArgs [IN]   Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 */
static TEST_STATUS run_lcd_test(void *testArgs)
{
	TEST_STATUS status = TEST_PASS;
	uint8_t c;

	UART_printf("\nRunning LCD Display Test\n\n");

	status = lcd_display_test(testArgs);
	if(status != TEST_PASS)
	{
		UART_printf("\nLCD Display Test Failed\n");
		return (status);
	}

	UART_printf("\nRunning LCD Backlight Test\n");

	UART_printf("\nChanging Backlight... WAIT, Check the LCD panel");

	status = lcd_backlight_test();
	if(status != TEST_PASS)
	{
		UART_printf("\nLCD Backlight Test Failed\n");
		return (status);
	}
	else
	{
		UART_printf("  Press 'y' if Brightness is Increasing/Decreasing, Any other key for failure: ");
		UART_scanFmt("%c", &c);
		if((c == 'y') || (c == 'Y'))
		{
			UART_printf("\rChange Backlight - PASS                                                                                                               \n");
		}
		else
		{
			UART_printf("\rChange Backlight - FAIL                                                                                                               \n");
			status = TEST_FAIL;
		}
	}

	UART_printf("\nRunning LCD Touch Test\n");
	status = run_touch_test(testArgs);
	if(status != TEST_PASS)
	{
		UART_printf("\nLCD Touch Test Failed\n");
		return (status);
	}

	return (status);
}

/**
 * \brief This function performs lcd test
 *
 * \param testArgs  - Test arguments
 *
 * \return
 * \n      TEST_PASS  - Test Passed
 * \n      TEST_FAIL  - Test Failed
 *
 */
TEST_STATUS lcdTest(void *testArgs)
{
    TEST_STATUS testStatus;
	lcdTestArgs_t *args = (lcdTestArgs_t *)testArgs;

	UART_printf("\n**********************\n");
	UART_printf(  "       LCD Test       \n");
	UART_printf(  "**********************\n");

	testStatus = run_lcd_test(args);
	if(testStatus != TEST_PASS)
	{
		UART_printf("\nLCD Test Failed!\n");
	}
	else
	{
		//UART_printf("\nLCD Test Passed!\n");
	}

	UART_printf("\nLCD Tests Completed!!\n");
	UART_printf("\n-----------------X-----------------\n\n\n");

    return(testStatus);

} // lcdTest

/**
 * \brief Invokes lcd test functions
 *
 */
int main(void)
{
    TEST_STATUS        testStatus;
    lcdTestArgs_t      testArgs;
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

    /* Invoke LCD Test */
    testStatus = lcdTest(&testArgs);
    if(testStatus != TEST_PASS)
    {
    	return (-1);
    }

    return (0);
}

/* Nothing past this point */
