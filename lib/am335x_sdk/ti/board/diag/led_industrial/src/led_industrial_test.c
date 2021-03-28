/*
 * Copyright (C) 2015-2018 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file   led_industrial_test.c
 *
 *  \brief  Led industrial diagnostic test file.
 *
 *  Targeted Functionality: Verifies all the Industrial LEDs.
 *
 *  Operation: This test verifies the accessing of all the Industrial LEDs
 *             by glowing one by one using i2c interface.
 *
 *  Supported SoCs: AM571x, AM572x, K2G & AM65XX.
 *
 *  Supported Platforms: idkAM571x, idkAM572x, iceK2G, am65xx_evm & am65xx_idk.
 *
 */

#include "led_industrial_test.h"

extern I2C_config_list I2C_config;

/**
 *  \brief    This function is used to set the output level of the LEDs
 *            connected to the i2c slave device.
 *
 *  \param    handle              [IN]   I2C Handler
 *            signalLevelData     [IN]   Device output signal data.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
#if (!defined(SOC_AM65XX))
void led_write(I2C_Handle handle, uint8_t signalLevelData)
{
    uint8_t tx[2];
    I2C_Transaction i2cTransaction;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&i2cTransaction);

    I2C_transactionInit(&i2cTransaction);
    tx[0] = 0x44;
    tx[1] = signalLevelData;
    i2cTransaction.slaveAddress = BOARD_I2C_LED_ADDR;
    i2cTransaction.writeBuf = tx;
    i2cTransaction.writeCount = 2;
    i2cTransaction.readCount = 0;
    I2C_transfer(handle, &i2cTransaction);
}
#endif

/**
 *  \brief    This function is used to generate delays.
 *
 *  \param    delayValue          [IN]   Delay count.
 *
 */
#if ((!(defined(SOC_AM65XX))) || (!(defined(SOC_K2G))))
void BoardDiag_AppDelay(uint32_t delayVal)
{
    volatile uint32_t delay = 0;
    while(delay < delayVal)
    {
        asm("");
        delay++;
    }
}
#endif

/**
 *  \brief    This test glows all the LEDs connected to the I2c slave device.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_i2c_slave_device_led_test(void)
{
    int8_t ret = 0;
    char inputChar = 'y';
    uint8_t writeRegData = 0;
    int8_t index;

#if (!defined(SOC_AM65XX))
    I2C_Params i2cParams;
    I2C_HwAttrs i2cConfig;
    I2C_Handle handle = NULL;

    for(index = 0; index < I2C_HWIP_MAX_CNT; index++)
    {
        I2C_socGetInitCfg(index, &i2cConfig);
        i2cConfig.enableIntr = false;
        I2C_socSetInitCfg(index, &i2cConfig);
    }

    I2C_init();

    I2C_Params_init(&i2cParams);

    handle = I2C_open(BOARD_I2C_LED_INSTANCE, &i2cParams);
#else
    /* Initializes the I2C IO Expansion header Instance */
    Board_i2cIoExpInit();
#endif

    UART_printf("\nTesting Industrial LEDs\n");
    UART_printf("Cycling LEDs 3 times\n");
    writeRegData = 0x80;

    do {
#if !defined (DIAG_STRESS_TEST) && !defined(DIAG_COMPLIANCE_TEST)
        UART_printf("Press 'y' to verify pass, 'r' to cycle leds again,\n");
        UART_printf("or any other character to indicate failure: ");
#endif
        for(index = 0; index < (NUM_OF_TEST_ITERATIONS *
            NUM_OF_CONFIGURABLE_LEDS_PER_ITERATION); index++)
        {
            if((writeRegData & 0xff) == 0)
                 writeRegData = 0x80;
#if (!defined(SOC_AM65XX))
            led_write(handle, writeRegData);
#else
            ret = Board_i2cIoExpWritePort(BOARD_I2C_IOEXP_DEVICE1_ADDR,
                                          PORTNUM_NONE, writeRegData);
            if(ret != 0)
            {
                UART_printf("Writing on to the IO expander port "
                            "failed\n\r");
                return ret;
            }
#endif
            writeRegData >>= 1;
#if defined(SOC_K2G) || defined (SOC_AM65XX)
		    BOARD_delay(200000);
#elif defined (SOC_AM437x)
            BoardDiag_AppDelay(0x1FFFF);
#else
		    BoardDiag_AppDelay(0x1FFFFFF);
#endif
        }
#if !defined (DIAG_STRESS_TEST) && !defined(DIAG_COMPLIANCE_TEST)
        UART_scanFmt("%c", &inputChar);
		if (inputChar == 'r') UART_printf("\nCycling LEDs 3 times again\n");
#else
        inputChar = 'y';
#endif
    } while (inputChar == 'r');

    UART_printf("Received: %c\n", inputChar);
    if(!((inputChar == 'y') || (inputChar == 'Y')))
    {
        UART_printf("\nTest FAILED!\n");
        ret = -1;
    }
    else
    {
        UART_printf("\nTest PASSED!\n");
        ret = 0;
    }

#if defined (am65xx_idk)
    UART_printf("\nTesting Industrial LEDs on AM65xx IDK Board\n");
    UART_printf("Cycling LEDs 3 times\n");
    writeRegData = 0x80;

    do {
#if !defined(DIAG_COMPLIANCE_TEST)
        UART_printf("Press 'y' to verify pass, 'r' to cycle leds again,\n");
        UART_printf("or any other character to indicate failure: ");
#endif
        for(index = 0; index < (NUM_OF_TEST_ITERATIONS *
            NUM_OF_CONFIGURABLE_LEDS_PER_ITERATION); index++)
        {
            if((writeRegData & 0xff) == 0)
                 writeRegData = 0x80;
            ret = Board_i2cIoExpWritePort(0x63,
                                          PORTNUM_NONE, writeRegData);
            if(ret != 0)
            {
                UART_printf("Writing on to the IO expander port "
                            "failed\n\r");
                return ret;
            }
            writeRegData >>= 1;
            BOARD_delay(250000);
        }
#if !defined (DIAG_STRESS_TEST) && !defined(DIAG_COMPLIANCE_TEST)
        UART_scanFmt("%c", &inputChar);
		if (inputChar == 'r') UART_printf("\nCycling LEDs 3 times again\n");
#else
        inputChar = 'y';
#endif
    } while (inputChar == 'r');

    UART_printf("Received: %c\n", inputChar);
    if(!((inputChar == 'y') || (inputChar == 'Y')))
    {
        UART_printf("\nTest FAILED!\n");
        ret = -1;
    }
    else
    {
        UART_printf("\nTest PASSED!\n");
        ret = 0;
    }

#endif

#if defined(SOC_AM65XX)
    Board_i2cIoExpDeInit();
#endif

    return ret;
}

/**
 *  \brief    This test is used to run LED industrial diagnostic test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_run_led_industrial_test(void)
{
    int8_t ret = 0;

    UART_printf("Verifying LED's connected to I2C IO Expander "
                "slave device...\n");

    ret = BoardDiag_i2c_slave_device_led_test();
    if(ret != 0)
    {
        UART_printf("Verifying LED's connected to I2C IO Expander "
                    "slave device failed\n");
    }

    return ret;
}

int8_t BoardDiag_indLedFunctionalTest(void)
{
    int8_t ret = 0;

    UART_printf("\nRunning Industrial Test...\n");

    ret = BoardDiag_run_led_industrial_test();
    return ret;
}

#ifdef DIAG_STRESS_TEST
/**
 *  \brief    The function performs the Industrial LED test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_indLedStressTest(void)
{
    int8_t ret = 0;
    char rdBuf = 'y';
    uint32_t iteration;
    uint32_t passCount = 0;
    uint32_t failCount = 0;

    UART_printf("\n\nRunning Industrial Test in Stress Mode for %d Number of Times...\n", DIAG_STRESS_TEST_ITERATIONS);
    UART_printf("Enter 'b' in Serial Console to Terminate the Test\n\n");

    for(iteration = 1; iteration <= DIAG_STRESS_TEST_ITERATIONS; iteration++)
    {
        ret = BoardDiag_indLedFunctionalTest();
        if (ret == 0)
        {
            UART_printf("\n\n\n\nIteration : %d Industrial Test Passed\n",iteration);
            passCount++;
        }
        else
        {
            UART_printf("\n\n\n\n Industrial Test Failed at iteration - %d\n",iteration);
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

    UART_printf("\n\nIndustrial Stress Test Status\n");
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
 *  \brief   LED industrial diagnostic test main function
 *
 *  \return  int - Industrial Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    int8_t ret = 0;
    Board_initCfg boardCfg;

#if defined(SOC_AM65XX) && !defined (__aarch64__)
    /* MCU I2C instance will be active by default for R5 core.
     * Need update HW attrs to enable MAIN I2C instance.
     */
    enableMAINI2C(0, CSL_I2C0_CFG_BASE);
#endif

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif  /*  #ifdef PDK_RAW_BOOT */
    Board_init(boardCfg);

    UART_printf("\n*********************************************\n");
    UART_printf  ("*            Industrial LED Test            *\n");
    UART_printf  ("*********************************************\n");

#ifdef idkAM437x
    /* Pinmux for I2C instance connected to industrial LEDs
       is not enabled by default for AM437x IDK.
       Call board library function to enable the pinmux
     */
    Board_i2cPinmuxConfig(BOARD_I2C_LED_INSTANCE);
#endif

#ifdef DIAG_STRESS_TEST
    ret = BoardDiag_indLedStressTest();
#else
    ret = BoardDiag_indLedFunctionalTest();
#endif
    if(ret == 0)
    {
        UART_printf("\nIndustrial Test Passed\n");
    }
    else
    {
        UART_printf("\nIndustrial Test Failed\n");
    }

    return ret;
}
