/*
 * Copyright (C) 2015 - 2016 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file  i2c_led_blink.c
 *
 *  \brief  Example application main file. This application will demonstrate I2C
 *          RTOS driver.
 *   This file performs tests on the following:
 *
 *      1. Blink the LEDS connected to the user LEDs
 *
 *
 *   Note
 *      1. The sample application is written for TDAXX EVM.
 *      2. The only available i2c instance for sample application use is I2c0
 *
**/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/* XDCtools Header files */
#include <ti/sysbios/BIOS.h>
#include <xdc/runtime/Error.h>
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/knl/Task.h>
#include <stdio.h>

/* TI-RTOS Header files */
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define I2C_LED_INSTANCE    (0U)

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
/* I2C address of TCA6424 expander - 2. */
#define HSI2C_SLAVE_ADDR            ((uint8_t) 0x22U)
#else
/* I2C address of PCF8575 expander. */
#define HSI2C_SLAVE_ADDR            ((uint8_t) 0x20U)
#endif

/* Turn on the LEDs. */
#define HSI2C_EXP_PORT0_LED_ON      ((uint8_t) 0xF0U)

/* Turn off the LEDs. */
#define HSI2C_EXP_PORT0_LED_OFF     ((uint8_t) 0x00U)

/* Number of times led toggles. */
#define HSI2C_LED_TOGGLE_NO         (10U)

/* Led toggle check value*/
#define HSI2C_LED_TOGGLE_END        (0U)

/* Transfer Size */
#define HSI2C_TRANSFER_SIZE         (5U)

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
#define TCA6424_CMD_AUTO_INC            ((uint8_t) 0x80U)

/* Output register to change state of output BIT set to 1, output set HIGH */
#define TCA6424_REG_OUTPUT0             ((uint8_t) 0x04U)
#define TCA6424_REG_OUTPUT1             ((uint8_t) 0x05U)
#define TCA6424_REG_OUTPUT2             ((uint8_t) 0x06U)

/* Configuration register. BIT = '1' sets port to input, BIT = '0' sets
 * port to output */
#define TCA6424_REG_CONFIG0             ((uint8_t) 0x0CU)
#define TCA6424_REG_CONFIG1             ((uint8_t) 0x0DU)
#define TCA6424_REG_CONFIG2             ((uint8_t) 0x0EU)

#endif
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
uint8_t dataToSlave[HSI2C_TRANSFER_SIZE];
I2C_Params i2cParams;
char rxBuf[];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void SetupI2CTransmit(uint8_t *data, uint32_t numBytes);
static void ioexpDataWrite(uint8_t *data);
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
static void initialize_ioexp(void);
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void i2c_led_blink_test(UArg arg0, UArg arg1)
{
    uint8_t          data;
    uint32_t         num;

    I2C_init();

    I2C_Params_init(&i2cParams);
    i2cParams.transferMode = I2C_MODE_BLOCKING;
    i2cParams.bitRate = I2C_400kHz;
    i2cParams.transferCallbackFxn = NULL;

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    initialize_ioexp();
#endif

    for (num = HSI2C_LED_TOGGLE_NO; num != HSI2C_LED_TOGGLE_END; num--)
    {
        data = HSI2C_EXP_PORT0_LED_ON;
        ioexpDataWrite(&data);
        Task_sleep(500);

        data = HSI2C_EXP_PORT0_LED_OFF;
        ioexpDataWrite(&data);
        Task_sleep(500);
    }

    return;
}

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
static void initialize_ioexp(void)
{
    /* TCA6424 ioexpander pins should be configure as output
     * In config register write 1 for input, 0 for output */
    dataToSlave[0] = TCA6424_REG_CONFIG0 | TCA6424_CMD_AUTO_INC;
    dataToSlave[1] = 0x0U;
    SetupI2CTransmit(&dataToSlave[0], 2);
}
#endif

void SetupI2CTransmit(uint8_t *data, uint32_t numBytes)
{
    I2C_Transaction i2cTransaction;
    I2C_Handle handle = NULL;
    bool status;

    handle = I2C_open(I2C_LED_INSTANCE, &i2cParams);

    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = HSI2C_SLAVE_ADDR;
    i2cTransaction.writeBuf = (uint8_t *)&data[0];
    i2cTransaction.writeCount = numBytes;
    i2cTransaction.readBuf = NULL;
    i2cTransaction.readCount = 0;
    status = I2C_transfer(handle, &i2cTransaction);

    if(FALSE == status)
    {
        printf("\n Data Transfer failed. \n");
    }

    I2C_close(handle);
}

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
static void ioexpDataWrite(uint8_t *data)
{
    dataToSlave[0] = TCA6424_REG_OUTPUT0 | (uint32_t) TCA6424_CMD_AUTO_INC;
    dataToSlave[1] = (((*data) >> 4U) & 0x0FU);
    dataToSlave[2] = 0U;
    dataToSlave[3] = 0U;
    SetupI2CTransmit(&dataToSlave[0], 4);
}
#endif

#if defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_TDA2EX)
static void ioexpDataWrite(uint8_t *data)
{
    dataToSlave[0] = *data;
    dataToSlave[1] = 0U;
    SetupI2CTransmit(&dataToSlave[0], 2);
}
#endif

int main(void)
{
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);

    task = Task_create(i2c_led_blink_test, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    /* Start BIOS */
    BIOS_start();
    return (0);
}
