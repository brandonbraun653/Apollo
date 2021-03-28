/**
 *  \file   main_temperature_sensor.c
 *
 *  \brief  Example application main file. This application will get the
 *          temperature from the temperature sensor through I2C interface and
 *          displays on the serial console.
 *
 */

/*
 * Copyright (C) 2014 - 2016 Texas Instruments Incorporated - http://www.ti.com/
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


/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <stdio.h>
#include <string.h>


#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/i2c/test/eeprom_read/src/I2C_log.h>
#include <ti/drv/i2c/test/eeprom_read/src/I2C_board.h>

/* Temperature sensor slave address */
#define I2C_TEMP_SENSOR_SLAVE_ADDR     (0x48U)

/* Instance of I2C controller that is connected to the temperature sensor */
#define I2C_TEMP_SENSOR_INSTANCE       (0U)

#define I2C_TRANSACTION_TIMEOUT         (2000U)

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/
/* Delay function */
static void AppDelay(uint32_t delayVal);

/* Temperature conversion function */
static int convertTemp(uint16_t temp);

/* Board initialization function */
static void Board_initI2C(void);

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/*
 *  ======== Board_initI2C ========
 */
static void Board_initI2C(void)
{
    Board_initCfg boardCfg;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);
}


/*
 *  ======== test function ========
 */
void i2c_test(UArg arg0, UArg arg1)
{
    I2C_Params i2cParams;
    I2C_Handle handle = NULL;
    I2C_Transaction i2cTransaction;
    uint8_t txBuf[1] = {0x00};
    uint8_t rxBuf[2] = {0x00, 0x00};
    int16_t status;
    uint16_t val;
    uint16_t temp;

    I2C_log("\n I2C Temperature Sensor Application \n");

    I2C_init();

    I2C_Params_init(&i2cParams);

    handle = I2C_open(I2C_TEMP_SENSOR_INSTANCE, &i2cParams);

    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = I2C_TEMP_SENSOR_SLAVE_ADDR;
    i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount = 1;
    i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
    i2cTransaction.readCount = 0;
    i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
    status = I2C_transfer(handle, &i2cTransaction);

    AppDelay(100);

    if(I2C_STS_SUCCESS == status)
    {
        I2C_transactionInit(&i2cTransaction);
        i2cTransaction.slaveAddress = I2C_TEMP_SENSOR_SLAVE_ADDR;
        i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
        i2cTransaction.writeCount = 0;
        i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
        i2cTransaction.readCount = 2;
        i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
        status = I2C_transfer(handle, &i2cTransaction);

        if(I2C_STS_SUCCESS == status)
        {
            val = (rxBuf[0] << 4) | (rxBuf[1] >> 4);
            temp = convertTemp(val);

            I2C_log("\n Temperature = %d C \n", temp);
            UART_printStatus("\n All tests have passed. \n");
        }
        else
        {
            UART_printStatus("\n Some tests have failed. \n");
        }
    }
    else
    {
        UART_printStatus("\n Some tests have failed. \n");
    }

    I2C_close(handle);

    while (1) {
    }
}

/*
 *  ======== main ========
 */
int main(void)
{
    Board_initI2C();

#if defined (SOC_AM335X) || defined (SOC_AM437x)
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);

    task = Task_create(i2c_test, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }
#endif

    /* Start BIOS */
    BIOS_start();
    return (0);
}

/*
 *  ======== AppDelay ========
 */
static void AppDelay(uint32_t delayVal)
{
    uint32_t cnt = 0;
    while(cnt < delayVal)
    {
        cnt++;
    }
}

/*
 *  ======== convertTemp ========
 */
static int convertTemp(uint16_t temp)
{
    return (temp * 625) / 10000;
}
