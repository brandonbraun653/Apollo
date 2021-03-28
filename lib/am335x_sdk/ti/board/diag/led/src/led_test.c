/*
 * Copyright (C) 2015-2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *  \file   led_test.c
 *
 *  \brief  Led diagnostic test file.
 *
 *  Targeted Functionality: Verifies all the General purpose LEDs.
 *
 *  Operation: This test verifies by toggling all available general
 *             purpose LEDs.
 *
 *  Supported SoCs: AM335x, AM437x, AM571x, AM572x, K2G, AM65xx & J721E.
 *
 *  Supported Platforms: bbbAM335x, skAM335x, icev2AM335x, iceAMIC110,
 *                       evmAM437x, idkAM437x, skAM437x, evmAM571x, idkAM571x,
 *                       evmAM572x, idkAM572x, evmK2G, iceK2G, am65xx_evm,
 *                       am65xx_idk & j721e_evm.
 */

#include "led_test.h"

#if defined(SOC_J721E)
    i2cIoExpPinNumber_t gUserLeds[BOARD_GPIO_LED_NUM] = { PIN_NUM_6,
                                                          PIN_NUM_7 };
#endif

/**
 *  \brief    This function is used to generate delays.
 *
 *  \param    delayValue          [IN]   Delay count.
 *
 */
#if (!(defined(AM65XX) || defined(SOC_J721E)))
void BoardDiag_AppDelay(uint32_t delayVal)
{
    uint32_t cnt = 0;
    while(cnt < delayVal)
    {
        asm("");
        cnt++;
    }
}
#endif


#if defined(SOC_AM65XX) && defined(AM65XX_BETA_BOARD)
/* Function to enable IO expander based LEDs */
void led_write(I2C_Handle handle, uint8_t signalLevelData)
{
    uint8_t tx[2];
    I2C_Transaction i2cTransaction;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&i2cTransaction);

    I2C_transactionInit(&i2cTransaction);
    tx[0] = 0x1;
    tx[1] = signalLevelData;
    i2cTransaction.slaveAddress = BOARD_I2C_IOEXP_DEVICE4_ADDR;
    i2cTransaction.writeBuf = tx;
    i2cTransaction.writeCount = 2;
    i2cTransaction.readCount = 0;
    I2C_transfer(handle, &i2cTransaction);
}

/* Function to configure the IO expander pin direction */
void led_configure(I2C_Handle handle, uint8_t signalLevelData)
{
    uint8_t tx[2];
    I2C_Transaction i2cTransaction;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&i2cTransaction);

    I2C_transactionInit(&i2cTransaction);
    tx[0] = 0x3;
    tx[1] = signalLevelData;
    i2cTransaction.slaveAddress = BOARD_I2C_IOEXP_DEVICE4_ADDR;
    i2cTransaction.writeBuf = tx;
    i2cTransaction.writeCount = 2;
    i2cTransaction.readCount = 0;
    I2C_transfer(handle, &i2cTransaction);
}
#endif

/**
 *  \brief    This is the Application callback function used while
 *            running the LED test in interrupt mode.
 *
 */
#if defined (iceK2G)
void AppGpioCallbackFxn(void)
{
    if(gLedNum != USER_LED0)
    {
        GPIO_write(USER_LED0, GPIO_PIN_VAL_LOW);
        GPIO_write(gLedNum, GPIO_PIN_VAL_HIGH);
    }
}
#endif /* iceK2G */

/**
 *  \brief    This test performs the LED diagnostic test by toggling
 *            all the LEDs that exists.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t led_run_test(void)
{
#if defined(SOC_J721E)
    Board_I2cInitCfg_t i2cCfg;
#endif
    char p = 'y';
    int i, j, k;

#if defined (iceK2G) /*  Test is executed with GPIO interrupts enabled on iceK2G */
    /* Setup GPIO interrupt configurations */
    GPIO_socSetIntMux(GPIO_LED0_PORT_NUM, GPIO_LED0_PIN_NUM, NULL, GPIO_MUX_SEL);

    /* GPIO initialization */
    GPIO_init();

    /* Set the callback function */
    GPIO_setCallback(USER_LED0, AppGpioCallbackFxn);

    /* Enable GPIO interrupt on the specific gpio pin */
    GPIO_enableInt(USER_LED0);
#else
#if defined(SOC_AM65XX)
    GPIO_v0_HwAttrs gpioCfg;
    GPIO_socGetInitCfg(0, &gpioCfg);
    gpioCfg.baseAddr = CSL_WKUP_GPIO0_BASE;
    GPIO_socSetInitCfg(0, &gpioCfg);
    GPIO_init();
#elif defined(SOC_J721E)
    i2cCfg.i2cInst   = BOARD_I2C_IOEXP_DEVICE2_INSTANCE;
    i2cCfg.socDomain = BOARD_SOC_DOMAIN_MAIN;
    i2cCfg.enableIntr = false;
    Board_setI2cInitConfig(&i2cCfg);

    Board_i2cIoExpInit();
#else
    GPIO_init();
#endif

#if defined(SOC_AM65XX) && defined(AM65XX_BETA_BOARD)
    I2C_Params i2cParams;
    I2C_Handle handle = NULL;
    I2C_HwAttrs i2cCfg;
    I2C_socGetInitCfg(0, &i2cCfg);
    i2cCfg.baseAddr = CSL_WKUP_I2C0_CFG_BASE;
    i2cCfg.enableIntr = 0;
    I2C_socSetInitCfg(0, &i2cCfg);

    I2C_init();
    I2C_Params_init(&i2cParams);
    handle = I2C_open(0, &i2cParams);
    led_configure(handle, 0x9F);

#endif
#ifdef iceAMIC110
    GPIO_write(BOARD_GPIO_LED_NUM, GPIO_PIN_VAL_HIGH);
#endif
#endif    /* #if defined (iceK2G) */

    UART_printf("\n*********************************************\n");
    UART_printf  ("*                 LED Test                  *\n");
    UART_printf  ("*********************************************\n");

    UART_printf("\nTesting LED\n");
    UART_printf("Blinking LEDs...\n");

    for (i=0; i<BOARD_GPIO_LED_NUM; i++) {
#if defined(SOC_J721E)
        Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                      THREE_PORT_IOEXP,
                                      PORTNUM_2,
                                      gUserLeds[i],
                                      PIN_DIRECTION_OUTPUT);

        Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  THREE_PORT_IOEXP,
                                  PORTNUM_2,
                                  gUserLeds[i],
                                  GPIO_SIGNAL_LEVEL_HIGH);
#else
        GPIO_write(i, GPIO_PIN_VAL_LOW);
#endif
    }

    do {
#if !defined (DIAG_STRESS_TEST) && !defined(DIAG_COMPLIANCE_TEST)
        UART_printf("Press 'y' to verify pass, 'r' to blink again,\n");
        UART_printf("or any other character to indicate failure: ");
#endif
        for (i=0; i<NUMBER_OF_CYCLES; i++) {
            for (j=0; j<BOARD_GPIO_LED_NUM; j++) {
                for (k=0; k<BOARD_GPIO_LED_NUM; k++) {
                    if (j==k) {
#if defined (iceK2G)
                        gLedNum = k;
                        GPIO_toggle(USER_LED0);
#elif defined(SOC_J721E)
                        Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                                  THREE_PORT_IOEXP,
                                                  PORTNUM_2,
                                                  gUserLeds[k],
                                                  GPIO_SIGNAL_LEVEL_LOW);
#else
                        GPIO_write(k, GPIO_PIN_VAL_HIGH);
#endif
                    }
                    else {
#if defined(SOC_J721E)
                        Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                                  THREE_PORT_IOEXP,
                                                  PORTNUM_2,
                                                  gUserLeds[k],
                                                  GPIO_SIGNAL_LEVEL_HIGH);
#else
                        GPIO_write(k, GPIO_PIN_VAL_LOW);
#endif
                    }
                }
#if (!(defined(SOC_AM65XX) || defined(SOC_J721E)))
                BoardDiag_AppDelay(5000000);
#else
                BOARD_delay(250000);
#endif
            }
#if defined(SOC_AM65XX) && defined(AM65XX_BETA_BOARD)
            led_write(handle, 0x9F);
            BOARD_delay(250000);
            led_write(handle, 0xFF);
#endif
        }
#if !defined (DIAG_STRESS_TEST) && !defined(DIAG_COMPLIANCE_TEST)
        UART_scanFmt("%c", &p);
#endif
        if (p == 'r') UART_printf("\nBlinking again\n");
    } while (p == 'r');

    for (i=0; i<BOARD_GPIO_LED_NUM; i++) {
#if defined(SOC_J721E)
    /* Turn OFF the user LEDs */
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              THREE_PORT_IOEXP,
                              PORTNUM_2,
                              gUserLeds[i],
                              GPIO_SIGNAL_LEVEL_HIGH);
#else
        GPIO_write(i, GPIO_PIN_VAL_LOW);
#endif
    }

    UART_printf("Received: %c\n", p);

#if defined(SOC_AM65XX) && defined(AM65XX_BETA_BOARD)
    I2C_close(handle);
#elif defined(SOC_J721E)
    Board_i2cIoExpDeInit();
#endif

    if ( (p == 'y') || (p == 'Y') ) {
        UART_printf("\nTest PASSED!\n");
        return 0;
    }
    else {
        UART_printf("\nTest FAILED!\n");
        return -1;
    }
}

int8_t BoardDiag_gpioLedFunctionalTest(void)
{
    int8_t ret = 0;

    ret = led_run_test();

    return ret;
}

#ifdef DIAG_STRESS_TEST
/**
 *  \brief    The function performs the  LED test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_gpioLedStressTest(void)
{
    int8_t ret = 0;
    char rdBuf = 'y';
    uint32_t iteration;
    uint32_t passCount = 0;
    uint32_t failCount = 0;

    UART_printf("\n\nRunning LED Test in Stress Mode for %d Number of Times...\n", DIAG_STRESS_TEST_ITERATIONS);
    UART_printf("Enter 'b' in Serial Console to Terminate the Test\n\n");

    for(iteration = 1; iteration <= DIAG_STRESS_TEST_ITERATIONS; iteration++)
    {
        ret = BoardDiag_gpioLedFunctionalTest();
        if (ret == 0)
        {
            UART_printf("\n\n\n\nIteration : %d LED Test Passed\n",iteration);
            passCount++;
        }
        else
        {
            UART_printf("\n\n\n\n LED Test Failed at iteration - %d\n",iteration);
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

    UART_printf("\n\nLED Stress Test Status\n");
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
 *  \brief   LED diagnostic test main function
 *
 *  \return  int - LED Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
#ifndef SPI_BOOT_FRAMEWORK
int main(void)
{
    int8_t ret = 0;
    Board_initCfg boardCfg;

#if defined (iceK2G)
    CSL_A15_INIT_copyVectorTable();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif  /*  #ifdef PDK_RAW_BOOT */
    Board_init(boardCfg);

#ifdef DIAG_STRESS_TEST
    ret = BoardDiag_gpioLedStressTest();
#else
    ret = BoardDiag_gpioLedFunctionalTest();
#endif
    if(ret == 0)
    {
        UART_printf("\nLED Test Passed\n");
    }
    else
    {
        UART_printf("\nLED Test Failed\n");
    }

    return ret;
}

#endif /* #ifndef SPI_BOOT_FRAMEWORK */
