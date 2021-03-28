/**
 *  \file   main_test.c
 *
 *  \brief  Example application main file. This application will read the data
 *          from eeprom and compares it with the known data.
 *
 */

/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

#include <ti/drv/i2c/test/firmware_test/src/test_utils.h>

/*
 *  ======== Board_initI2C ========
 */
bool Board_initI2C(void)
{
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;
    I2C_SwIPAttrs   i2c_cfg;

#if defined (I2C_TEST_INSTANCE1)
    /* Initialize the I2C fw configuration */
    I2C_socInitFwCfg();

    /* Get the default I2C init configurations */
    I2C_socGetFwCfg(I2C_TEST_INSTANCE1, &i2c_cfg);

    /* Modify the default I2C configurations if necessary */

    /* Set the default I2C init configurations */
    I2C_socSetFwCfg(I2C_TEST_INSTANCE1, &i2c_cfg);
#endif
#if defined (idkAM572x) || defined (idkAM574x) || defined (idkAM571x)
    boardCfg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO | BOARD_INIT_ICSS_ETH_PHY;
#endif
#if defined(icev2AM335x) || defined(idkAM437x) || defined(bbbAM335x)
    boardCfg = BOARD_INIT_PLL| BOARD_INIT_MODULE_CLOCK |  BOARD_INIT_DDR | BOARD_INIT_ICSS_PINMUX | BOARD_INIT_UART_STDIO | BOARD_INIT_ICSS_ETH_PHY;
#endif
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        return (false);
    }
    
#if defined(idkAM437x)
    pruGpioMuxConfigI2cUnused();
#endif

    return (true);
}

/*
 *  ======== test function ========
 */
void i2c_test(UArg arg0, UArg arg1)
{
    uint32_t testId = 0;
    I2C_BitRate dataRate;
    int32_t status = 0;

#if defined (I2C_TEST_INSTANCE1)
    /* testing instance at 100KHz board rate */
    dataRate = I2C_100kHz;
    testId++;
    printTestCase(testId, I2C_TEST_INSTANCE1, dataRate);
    status = i2c_feature_test(I2C_TEST_INSTANCE1, dataRate, I2C_EEPROM_ADDR, false);
    if(-1 == status)
    {
        UART_printStatus("\n Some tests have failed. \n");
        while(1);
    }
    else
    {
        I2C_log("\n Normal Read/Write test passed \n");
    }

#ifndef AM437X_ICSS0 // remove SMBUS test for AM437x ICSS0
    status = i2c_feature_test(I2C_TEST_INSTANCE1, dataRate, I2C_SMBUS_DEV_ADDR, true);
    if(-1 == status)
    {
        UART_printStatus("\n Some tests have failed. \n");
        while(1);
    }
    else
    {
        I2C_log("\n SMBUS test passed \n");
    }
#endif

    /* testing instance at 400KHz board rate */
    dataRate = I2C_400kHz;
    testId++;
    printTestCase(testId, I2C_TEST_INSTANCE1, dataRate);
    status = i2c_feature_test(I2C_TEST_INSTANCE1, dataRate, I2C_EEPROM_ADDR, false);
    if(-1 == status)
    {
        UART_printStatus("\n Some tests have failed. \n");
        while(1);
    }
    else
    {
        I2C_log("\n Normal Read/Write test passed \n");
    }

#ifndef AM437X_ICSS0 // remove SMBUS test for AM437x ICSS0
    status = i2c_feature_test(I2C_TEST_INSTANCE1, dataRate, I2C_SMBUS_DEV_ADDR, true);
    if(-1 == status)
    {
        UART_printStatus("\n Some tests have failed. \n");
        while(1);
    }
    else
    {
        I2C_log("\n SMBUS test passed \n");
    }
#endif

    /* testing instance at 1MHz board rate */
    dataRate = I2C_1P0Mhz;
    testId++;
    printTestCase(testId, I2C_TEST_INSTANCE1, dataRate);
    status = i2c_feature_test(I2C_TEST_INSTANCE1, dataRate, I2C_EEPROM_ADDR, false);
    if(-1 == status)
    {
        UART_printStatus("\n Some tests have failed. \n");
        while(1);
    }
    else
    {
        I2C_log("\n Normal Read/Write test passed \n");
    }
    
#endif // I2C_TEST_INSTANCE1

#if defined (I2C_TEST_INSTANCE2)
    /* testing instance at 100KHz board rate */
    dataRate = I2C_100kHz;
    testId++;
    printTestCase(testId, I2C_TEST_INSTANCE2, dataRate);
    status = i2c_feature_test(I2C_TEST_INSTANCE2, dataRate, I2C_EEPROM_ADDR, false);
    if(-1 == status)
    {
        UART_printStatus("\n Some tests have failed. \n");
        while(1);
    }
    else
    {
        I2C_log("\n Normal Read/Write test passed \n");
    }

#ifndef AM437X_ICSS0 // remove SMBUS test for AM437x ICSS0
    status = i2c_feature_test(I2C_TEST_INSTANCE2, dataRate, I2C_SMBUS_DEV_ADDR, true);
    if(-1 == status)
    {
        UART_printStatus("\n Some tests have failed. \n");
        while(1);
    }
    else
    {
        I2C_log("\n SMBUS test passed \n");
    }
#endif

#endif // I2C_TEST_INSTANCE2

    UART_printStatus("\n All tests have passed. \n");
}

/*
 *  ======== main ========
 */
int main(void)
{
    Task_Handle task;
    Error_Block eb;
    Task_Params taskParams;

    Error_init(&eb);

    if (Board_initI2C() == false)
    {
        return (0);
    }

    Task_Params_init(&taskParams);
#ifndef _TMS320C6X
    taskParams.priority = 10;
#endif
    taskParams.instance->name = "i2cTest1";
    task = Task_create(i2c_test, &taskParams, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    /* Start BIOS */
    BIOS_start();
    return (0);
}


