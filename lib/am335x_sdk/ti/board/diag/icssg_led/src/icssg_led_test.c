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
 *  \file   icssg_led_test.c
 *
 *  \brief  ICSSG Led diagnostic test file.
 *
 *  Targeted Functionality: Verifies all the IDK PRG0 and PRG1 Ethernet LEDs.
 *
 *  Operation: This test verifies by toggling all available IDK
 *             Ethernet LEDs.
 *
 *  Supported SoCs: AM65xx.
 *
 *  Supported Platforms: am65xx_idk.
 */

#include "icssg_led_test.h"
#include "board_i2c_io_exp.h"

/**
 *  \brief    This test runs the LED diagnostic test by toggling
 *            all the PRG0 and PRG1 LEDs that exists.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t icssg_run_led_test(void)
{
    char p = 'y';
    int i, j, k;

    GPIO_init();

    UART_printf("\n********************************************\n");
    UART_printf  ("*              ICSS LED Test               *\n");
    UART_printf  ("********************************************\n");

    UART_printf("\nTesting ICSSG PRG0 and PRG1 LED's\n");
    UART_printf("Blinking LEDs...\n");

    for (i=0; i<BOARD_IDK_GPIO_LED_NUM; i++) {
        GPIO_write(i, GPIO_PIN_VAL_LOW);
    }

    do {
#if !defined(DIAG_COMPLIANCE_TEST)
        UART_printf("Press 'y' to verify pass, 'r' to blink again,\n");
        UART_printf("or any other character to indicate failure: ");
#endif
        for (i=0; i<NUMBER_OF_CYCLES; i++) {
            for (j=0; j<BOARD_IDK_GPIO_LED_NUM; j++) {
                for (k=0; k<BOARD_IDK_GPIO_LED_NUM; k++) {
                    if (j==k) {
                        GPIO_write(k, GPIO_PIN_VAL_HIGH);
                    }
                    else {
                        GPIO_write(k, GPIO_PIN_VAL_LOW);
                    }
                }
                BOARD_delay(250000);
            }
        }
#if !defined (DIAG_STRESS_TEST) && !defined (DIAG_COMPLIANCE_TEST)
        UART_scanFmt("%c", &p);
#endif
        if (p == 'r') UART_printf("\nBlinking again\n");
    } while (p == 'r');

    for (i=0; i<BOARD_IDK_GPIO_LED_NUM; i++) {
        GPIO_write(i, GPIO_PIN_VAL_LOW);
    }

    UART_printf("Received: %c\n", p);
    if ( (p == 'y') || (p == 'Y') ) {
        UART_printf("\nTest PASSED!\n");
        return 0;
    }
    else {
        UART_printf("\nTest FAILED!\n");
        return -1;
    }
}

void enableUART1Sel(void)
{
    Board_i2cIoExpInit();

    /* Setting the pin direction as output */
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  PORTNUM_1,
                                  PIN_NUM_5,
                                  PIN_DIRECTION_OUTPUT);

    /* Pulling the EMMC RST line to low for the reset to happen */
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              PORTNUM_1,
                              PIN_NUM_5,
                              GPIO_SIGNAL_LEVEL_HIGH);
}

int8_t BoardDiag_icssLedFunctionalTest(void)
{
    int8_t ret = 0;

    ret = icssg_run_led_test();

    return ret;
}

#ifdef DIAG_STRESS_TEST
/**
 *  \brief    The function performs the ICSSG LED test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_icssLedStressTest(void)
{
    int8_t ret = 0;
    char rdBuf = 'y';
    uint32_t iteration;
    uint32_t passCount = 0;
    uint32_t failCount = 0;

    UART_printf("\n\nRunning ICSSG LED Test in Stress Mode for %d Number of Times...\n", DIAG_STRESS_TEST_ITERATIONS);
    UART_printf("Enter 'b' in Serial Console to Terminate the Test\n\n");

    for(iteration = 1; iteration <= DIAG_STRESS_TEST_ITERATIONS; iteration++)
    {
        ret = BoardDiag_icssLedFunctionalTest();
        if (ret == 0)
        {
            UART_printf("\n\n\n\nIteration : %d ICSSG LED Test Passed\n",iteration);
            passCount++;
        }
        else
        {
            UART_printf("\n\n\n\nICSSG LED Test Failed at iteration - %d\n",iteration);
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

    UART_printf("\n\nICSSG LED Stress Test Status\n");
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
 *  \brief   ICSSG LED diagnostic test main function
 *
 *  \return  int - ICSSG LED Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
    int8_t ret = 0;

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
    enableMAINI2C(0, CSL_I2C0_CFG_BASE);
#endif

    enableUART1Sel(); 

#ifdef DIAG_STRESS_TEST
    ret = BoardDiag_icssLedStressTest();
#else
    ret = BoardDiag_icssLedFunctionalTest();
#endif
    if(ret == 0)
    {
        UART_printf("\nICSS LED Test Passed\n");
    }
    else
    {
        UART_printf("\nICSS LED Test Failed\n");
    }

    return ret;
}
