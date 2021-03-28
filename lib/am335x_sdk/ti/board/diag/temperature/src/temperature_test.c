/*
 * Copyright (C) 2014-2019 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file   temperature_test.c
 *
 *  \brief  Temperature sensor diagnostic test file
 *
 *  Targeted Functionality: Verifying the basic functionality of temperature
 *  sensor interface.
 *
 *  Operation: This test is used to read the surrounding temperature
 *  using I2C interface and display it on the serial console
 *  by converting it to actual temperature reading(i.e; degree centigrade).
 *
 *  Supported SoCs: K2G, AM571x, AM572x, AM437x, AM335x, AM65xx & J721E.
 *
 *  Supported Platforms: evmK2G, evmAM571x, evmAM572x, idkAM437x, evmAM335x,
 *  am65xx_evm, am65xx_idk & j721e_evm.
 *
 */

#include "temperature_test.h"

extern I2C_config_list I2C_config;

/**
 *  \brief    Generates a random delay.
 *
 *  \param    delayVal            [IN]   Delay count.
 *
 */
#if (!((defined(SOC_AM65XX)) || (defined(SOC_J721E))))
void BoardDiag_AppDelay(uint32_t delayVal)
{
	uint32_t cnt = 0;
    while(cnt < delayVal)
    {
		asm("");
        cnt++;
    }
}
#else
void BoardDiag_AppDelay(uint32_t delayVal)
{
    BOARD_delay(delayVal);
}
#endif

/**
 *  \brief    Function to read temperature register contents.
 *
 *  \param    handle              [IN]       I2C Handler
 *            slaveAddr           [IN]       Temperature sensor device slave
 *                                           address
 *            tempRdVal           [IN/OUT]   Pointer to a buffer which holds
 *                                           the read temperature value.
 *
 *  \return   int8_t
 *              0 - in case of success
 *             -1 - in case of failure.
 *
 */
static int8_t BoardDiag_read_temp(I2C_Handle handle,
                                  uint8_t slaveAddr,
                                  uint16_t *tempRdVal)
{
    int8_t ret = I2C_STS_SUCCESS;
    uint8_t tx[1];
    uint8_t rx[2];
    I2C_Transaction transaction;

	/* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = tx;
    transaction.writeCount   = 1;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;

    tx[0] = 0x0;
    ret = I2C_transfer(handle, &transaction);
	if(ret != I2C_STS_SUCCESS)
    {
        UART_printf("\nReading the temperature register failed\n");
        return -1;
    }

    BoardDiag_AppDelay(1000);

    transaction.writeBuf     = NULL;
    transaction.writeCount   = 0;
    transaction.readBuf      = rx;
    transaction.readCount    = 2;

    ret = I2C_transfer(handle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        UART_printf("\nReading the temperature register failed\n");
        ret = -1;
		return ret;
    }
	else
	{
		ret = 0;
	}

    *tempRdVal = (rx[0] << 4) | (rx[1] >> 4);
    UART_printf("Read temperature register value - %d\n", *tempRdVal);

    return ret;
}

/**
 *  \brief    Used to convert the read temperature register value to the
 *            degree centigrade format.
 *
 *  \param    temp [IN]   Temperature reg value read.
 *
 *  \return   int32_t
 *              Returns the actual temperature in degree centigrade.
 *
 */
static int32_t BoardDiag_convert_temp(uint16_t temp)
{
    return (temp * 625) / 10000;
}

/**
 *  \brief    This function performs the temperature sensor test by reading the
 *            temperature register and display it on to the serial console by
 *            converting it into degree centigrade.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_run_temperature_test(void)
{
    int8_t     ret = 0;
    uint16_t   index;
    uint16_t   temp;
    I2C_Params i2cParams;
    I2C_HwAttrs i2cConfig;
    I2C_Handle handle = NULL;

#if ((defined(SOC_J721E)) && (defined (__aarch64__)))
    /* Enabling MCU I2C */
    enableI2C(CSL_MCU_I2C0_CFG_BASE);
#endif
    for(index = 0; index < I2C_HWIP_MAX_CNT; index++)
    {
        I2C_socGetInitCfg(index, &i2cConfig);
        i2cConfig.enableIntr = false;
        I2C_socSetInitCfg(index, &i2cConfig);
    }

    /* Initializes the I2C */
    I2C_init();

    /* Initializes the I2C Parameters */
    I2C_Params_init(&i2cParams);
#if ((defined(SOC_AM65XX)) || (defined(SOC_J721E)))
    i2cParams.bitRate = I2C_400kHz;
#endif
    /* Configures the I2C instance with the passed parameters*/
    handle = I2C_open(I2C_INSTANCE, &i2cParams);
    if(handle == NULL)
    {
        UART_printf("\nI2C Open failed!\n");
        ret = -1;
        return ret;
    }

    UART_printf("Running temperature sensor test... \n");

    ret = BoardDiag_read_temp(handle,
	                          TEMP_SLAVE_DEVICE1_ADDR,
                              &temp);
    if(ret == -1)
    {
        UART_printf("Temperature sensor test Failed!\n");
        return ret;
    }
    else
    {
        UART_printf("\nTemperature read from the temperature sensor\n "
                    "slave address - 0x%x is %d degree centigrade\n",
                     TEMP_SLAVE_DEVICE1_ADDR,
                     BoardDiag_convert_temp(temp));
    }

#if ((defined(SOC_AM65XX)) || (defined(SOC_J721E)))
    ret = BoardDiag_read_temp(handle,
	                          TEMP_SLAVE_DEVICE2_ADDR,
                              &temp);
    if(ret == -1)
    {
        UART_printf("Temperature sensor test Failed!\n");
        return ret;
    }
    else
    {
        UART_printf("\nTemperature read from the temperature sensor\n "
                    "slave address - 0x%x is %d degree centigrade\n",
                     TEMP_SLAVE_DEVICE2_ADDR,
                     BoardDiag_convert_temp(temp));

     }
#endif

	/* Closing the temperature sensor i2c instance */
	I2C_close(handle);

    UART_printf("Temperature sensor test Passed!\n");

    return ret;
}

int8_t BoardDiag_tempSensorFunctionalTest(void)
{
    int8_t ret = 0;

    UART_printf("\nRunning Temperature Sensor Test...\n");

    ret = BoardDiag_run_temperature_test();

    return ret;
}

#ifdef DIAG_STRESS_TEST
/**
 *  \brief    The function performs the Temperature sensor Diagnostic test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_tempSensorStressTest(void)
{
    int8_t ret = 0;
    char rdBuf = 'y';
    uint32_t iteration;
    uint32_t passCount = 0;
    uint32_t failCount = 0;

    UART_printf("\n\nRunning Temperature Sensor Test in Stress Mode for %d Number of Times...\n", DIAG_STRESS_TEST_ITERATIONS);
    UART_printf("Enter 'b' in Serial Console to Terminate the Test\n\n");

    for(iteration = 1; iteration <= DIAG_STRESS_TEST_ITERATIONS; iteration++)
    {
        ret = BoardDiag_tempSensorFunctionalTest();
        if (ret == 0)
        {
            UART_printf("\n\n\n\nIteration : %d Temperature Sensor Test Passed\n",iteration);
            passCount++;
        }
        else
        {
            UART_printf("\n\n\n\nTemperature Sensor Test Failed at iteration - %d\n",iteration);
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

    UART_printf("\n\nTemperature Sensor Stress Test Status\n");
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
 *  \brief   Temperature Sensor Diagnostic test main function
 *
 *  \return  int - Temperature Sensor Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    int8_t ret = 0;
    Board_initCfg boardCfg;

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

#if defined(SOC_AM65XX) && !defined (__aarch64__)
    /* MCU I2C instance will be active by default for R5 core.
     * Need update HW attrs to enable MAIN I2C instance.
     */
    enableMAINI2C(2, CSL_I2C2_CFG_BASE);
#endif

    UART_printf("\n*********************************************\n");
    UART_printf  ("*          Temperature Sensor Test          *\n");
    UART_printf  ("*********************************************\n");
  
#ifdef DIAG_STRESS_TEST
    ret = BoardDiag_tempSensorStressTest();
#else
    ret = BoardDiag_tempSensorFunctionalTest();
#endif
    if(ret == 0)
    {
        UART_printf("\nTemperature Sensor Test Passed\n");
    }
    else
    {
        UART_printf("\nTemperature Sensor Test Failed\n");
    }

    return ret;
}
