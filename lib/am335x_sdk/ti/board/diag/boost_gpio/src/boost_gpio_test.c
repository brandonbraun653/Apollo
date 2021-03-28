/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   boost_gpio_test.c
 *
 *  \brief  boosterpack gpio diagnostic test file.
 *
 *  Targeted Functionality: Verifies the boosterpack connector pins using
 *                          GPIO loopback.
 *
 *  Operation: This test verifies by transmitting a signal level(High and Low)
 *             form one pin and receive the same from the other pin in
 *             a pair of pins.
 *
 *  Supported SoCs: AM65xx.
 *
 *  Supported Platforms: am65xx_evm & am65xx_idk.
 */

/*
The below is table describes the pin pairs used for this diagnostic
verification:
*********************************************************************************
                 *        Header Pins           *        GPIO Pins              *
*********************************************************************************
*     PinSet * 01   *   J14-5  & J14-7          *    GPIO0_85 & GPIO0_86        *
*     PinSet * 02   *   J14-11 & J14-13         *    GPIO0_93 & GPIO0_83        *
*     PinSet * 03   *   J14-15 & J14-17         *    GPIO0_82 & GPIO1_36        *
*     PinSet * 04   *   J14-19 & J14-20         *    GPIO1_37 & GPIO1_33        *
*     PinSet * 05   *   J15-1  & J15-3          *    GPIO1_41 & GPIO1_42        *
*     PinSet * 06   *   J15-5  & J15-7          *    GPIO1_43 & GPIO1_44        *
*     PinSet * 07   *   J15-9  & J15-11         *    GPIO1_45 & GPIO1_46        *
*     PinSet * 08   *   J15-13 & J15-15         *    GPIO0_95 & GPIO0_94        *
*     PinSet * 09   *   J15-4  & J15-6          *    GPIO0_77 & GPIO0_78        *
*     PinSet * 10   *   J15-12 & J15-14         *    GPIO1_18 & GPIO1_19        *
* 	  PinSet * 11   *   J15-16, J15-18 & J15-20 * GPIO1_61, GPIO1_62 & GPIO0_79 *
*********************************************************************************
*/

#include "boost_gpio_test.h"

boostGpioPinDetails_t boostGpioPinDetails[NUM_PIN_SETS] = {
    {J14_HEADER, {PIN5,  PIN7,  '\0'},  0U,  TWO_PIN_SET},
    {J14_HEADER, {PIN11, PIN13, '\0'},  2U,  TWO_PIN_SET},
    {J14_HEADER, {PIN15, PIN17, '\0'},  4U,  TWO_PIN_SET},
    {J14_HEADER, {PIN19, PIN20, '\0'},  6U,  TWO_PIN_SET},

    {J15_HEADER, {PIN1,  PIN3,  '\0'},  8U,  TWO_PIN_SET},
    {J15_HEADER, {PIN4,  PIN6,  '\0'},  10U, TWO_PIN_SET},
    {J15_HEADER, {PIN5,  PIN7,  '\0'},  12U, TWO_PIN_SET},
    {J15_HEADER, {PIN9,  PIN11, '\0'},  14U, TWO_PIN_SET},
    {J15_HEADER, {PIN13, PIN15, '\0'},  16U, TWO_PIN_SET},
    {J15_HEADER, {PIN12, PIN14, '\0'},  18U, TWO_PIN_SET},
    {J15_HEADER, {PIN16, PIN18, PIN20}, 20U, THREE_PIN_SET},
};

static uint32_t pinMuxgpio[PADCONFIG_MAX_COUNT] =
{
    PIN_PRG1_PRU1_GPO9,
    PIN_PRG1_PRU1_GPO10,
	PIN_PRG1_PRU1_GPO17,
    PIN_SPI0_CLK,
	PIN_PRG1_PRU1_GPO6,
    PIN_PRG0_PRU0_GPO7,
	PIN_PRG0_PRU0_GPO8,
    PIN_PRG0_PRU0_GPO4,
    PIN_PRG0_PRU0_GPO12,
    PIN_PRG0_PRU0_GPO13,
    PIN_PRG0_PRU0_GPO14,
    PIN_PRG0_PRU0_GPO15,
    PIN_PRG0_PRU0_GPO16,
    PIN_PRG0_PRU0_GPO17,
    PIN_PRG1_PRU1_GPO19,
    PIN_PRG1_PRU1_GPO18,
    PIN_PRG1_PRU1_GPO1,
    PIN_PRG1_PRU1_GPO2,
    PIN_SPI0_D1,
    PIN_SPI0_D0,
    PIN_PRG0_PRU1_GPO12,
    PIN_PRG0_PRU1_GPO13,
    PIN_PRG1_PRU1_GPO3
};

/**
 *  \brief    This function used to perform the GPIO loopback
 *            verification test for a pair of pins passed.
 *
 *  \param    index              [IN]      GPIO cfg structure index
 *            gpioSignalLevel    [IN]      Looping back signal level.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_boostGpioPinSetVerification(uint8_t index,
                                                    gpioSignalLevel_t gpioSignalLevel)
{
    int8_t rdSignalLevel;

    GPIO_write(boostGpioPinDetails[index].offsetIndex, gpioSignalLevel);
    BOARD_delay(200);

    if(boostGpioPinDetails[index].pinSetMode == TWO_PIN_SET)
    {
        rdSignalLevel = GPIO_read(boostGpioPinDetails[index].offsetIndex + 1U);
        if(rdSignalLevel != gpioSignalLevel)
        {
            if(gpioSignalLevel == SIGNAL_LEVEL_HIGH)
            {
                UART_printf("Looping back the signal high failed\n\r");
            }
            else
            {
                UART_printf("Looping back the signal low failed\n\r");
            }
            UART_printf("Exiting...\n");
            return -1;
        }
    }
    else
    {
        rdSignalLevel = GPIO_read(boostGpioPinDetails[index].offsetIndex + 1U);
        if(rdSignalLevel != gpioSignalLevel)
        {
            if(gpioSignalLevel == SIGNAL_LEVEL_HIGH)
            {
                UART_printf("Looping back the signal high failed\n\r");
            }
            else
            {
                UART_printf("Looping back the signal low failed\n\r");
            }
            UART_printf("Exiting...\n");
            return -1;
        }

        rdSignalLevel = GPIO_read(boostGpioPinDetails[index].offsetIndex + 2U);
        if(rdSignalLevel != gpioSignalLevel)
        {
            if(gpioSignalLevel == SIGNAL_LEVEL_HIGH)
            {
                UART_printf("Looping back the signal high failed\n\r");
            }
            else
            {
                UART_printf("Looping back the signal low failed\n\r");
            }
            UART_printf("Exiting...\n");
            return -1;
        }
    }
    
    return 0;
}

/**
 *  \brief    The function runs Boosterpack GPIO loopback test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_run_boost_gpio_loopback_test(void)
{
    int8_t ret = 0U;
    uint8_t index;
    uint8_t pinSetCnt = 0U;
    uint8_t pinIndex = 0U;

    /* Intial pinmuxing was not done for the below in the evm board library.
       So, the below is the extra configuration done to disable the deep sleep
       mode of these pins*/
#ifdef am65xx_evm
	volatile uint32_t *addr;
	for(index = START_OF_PWM_OUT_PINS; index < END_OF_PWM_OUT_PINS; index++)
    {
		addr = (uint32_t *)(MAIN_PMUX_CTRL + pinMuxgpio[index]);
		*addr &= DEEP_SLEEP_MASK;
	}

#endif

    for(index = 0; index < PADCONFIG_MAX_COUNT; index++)
    {

        Board_pinMuxSetMode(pinMuxgpio[index], 
							(GPIO_PADCONFIG_MUX_MODE |
							((PIN_PULL_DISABLE | PIN_INPUT_ENABLE) &
							(~PIN_PULL_DIRECTION))));
    }

    GPIO_init();

    UART_printf("\nRunning Boost GPIO loopback test...\n");

    for(index = 0; index < NUM_PIN_SETS; index++)
    {
        UART_printf("Verifying a pin set of J%d header with the pins - ", boostGpioPinDetails[index].headerName);
        pinSetCnt = boostGpioPinDetails[index].pinSetMode;
        pinIndex = 0;
        while(pinSetCnt != 0U)
        {
            UART_printf("PIN_%2d", boostGpioPinDetails[index].pinNum[pinIndex]);
            pinIndex++;
            pinSetCnt--;

            if(pinIndex < PIN_NUM_MAX)
            {
                if(boostGpioPinDetails[index].pinNum[pinIndex] != '\0')
                {
                    if((boostGpioPinDetails[index].pinSetMode - pinIndex) == 1U)
                    {
                        UART_printf(" & ");
                    }
                    else
                    {
                        UART_printf(", ");
                    }
                }
            }
        }

        UART_printf("\n\r");
        /* Verifying the looping back the signal high */
        ret = BoardDiag_boostGpioPinSetVerification(index, SIGNAL_LEVEL_HIGH);
        if(ret != 0)
        {
            return ret;
        }
        /* Verifying the looping back the signal low */
        ret = BoardDiag_boostGpioPinSetVerification(index, SIGNAL_LEVEL_LOW);
        if(ret != 0)
        {
            return ret;
        }
    }

    return ret;
}

int8_t BoardDiag_boostGpioFunctionalTest(void)
{
    int8_t ret = 0;

    ret = BoardDiag_run_boost_gpio_loopback_test();

    return ret;
}

#ifdef DIAG_STRESS_TEST
/**
 *  \brief    The function performs the Boost gpio loopback test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_boostGpioStressTest(void)
{
    int8_t ret = 0;
    char rdBuf = 'y';
    uint32_t iteration;
    uint32_t passCount = 0;
    uint32_t failCount = 0;

    UART_printf("\n\nRunning BOOST GPIO Loopback Test in Stress Mode for %d Number of Times...\n", DIAG_STRESS_TEST_ITERATIONS);
    UART_printf("Enter 'b' in Serial Console to Terminate the Test\n\n");

    for(iteration = 1; iteration <= DIAG_STRESS_TEST_ITERATIONS; iteration++)
    {
        ret = BoardDiag_boostGpioFunctionalTest();
        if (ret == 0)
        {
            UART_printf("\n\n\n\nIteration : %d BOOST GPIO Loopback Test Passed\n",iteration);
            passCount++;
        }
        else
        {
            UART_printf("\n\n\n\nBOOST GPIO Loopback Test Failed at iteration - %d\n",iteration);
            failCount++;
        }

        /* Check if there a input from console to break the test */
        rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((rdBuf == 'b') || (rdBuf == 'B'))
        {
            UART_printf("Received Test Termination... Exiting the Test\n");
            iteration++;
            break;
        }
    }

    UART_printf("\n\nBOOST GPIO Loopback Stress Test Status\n");
    UART_printf("===================================\n");
    UART_printf("Number of Times Executed - %d\n", (iteration - 1));
    UART_printf("Pass Count - %d\n", passCount);
    UART_printf("Fail Count - %d\n", failCount);

    if((iteration != 0) && (failCount == 0))
    {
        UART_printf("Overall Status - PASS\n\n\n" );
    }
    else
    {
        UART_printf("Overall Status - FAIL\n\n\n" );
        ret = -1;
    }

    return ret;
}
#endif

/**
 *  \brief   Boosterpack GPIO test main function
 *
 *  \return  int - Boosterpack GPIO Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
    int8_t ret = 0;
#ifdef SOC_AM65XX
    Board_IDInfo_v2 boardInfo;
    bool isBoardConnected = FALSE;
#endif

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

#ifdef SOC_AM65XX
    BoardDiag_enableI2C(0, CSL_WKUP_I2C0_CFG_BASE);
    /* Check if BoosterPack application card is detected */
    /* Test exits if there is no application card connected.
       However, no error is reported to the caller. */
    if(Board_detectBoard(APP_CARD_DETECT))
    {
        /* Application card connected, confirm that it is a BoosterPack App card */
        if(Board_getIDInfo_v2(&boardInfo, BOARD_APP_EEPROM_ADDR) == BOARD_SOK)
        {
            if(strcmp(boardInfo.boardInfo.boardName, "LAUNCHXL-AM6") == 0)
            {
                isBoardConnected = TRUE;
            }
        }
    }
    BoardDiag_enableI2C(0, CSL_I2C0_CFG_BASE);

    if(isBoardConnected == FALSE)
    {
        UART_printf("\nApplication Card not Connected!!\n");
        UART_printf("Exiting the Test...\n");
        return 0;
    }
#endif

    UART_printf("\n***************************************\n");
    UART_printf(  "        BOOST GPIO Loopback Test       \n");
    UART_printf(  "***************************************\n");

#ifdef DIAG_STRESS_TEST
    ret = BoardDiag_boostGpioStressTest();
#else
    ret = BoardDiag_boostGpioFunctionalTest();
#endif
    if(ret == 0)
    {
        UART_printf("\nBOOST GPIO Loopback Test Passed\n");
    }
    else
    {
        UART_printf("\nBOOST GPIO Loopback Test Failed\n");
    }

    boardCfg = BOARD_INIT_PINMUX_CONFIG;
    Board_init(boardCfg);

    return ret;
}
