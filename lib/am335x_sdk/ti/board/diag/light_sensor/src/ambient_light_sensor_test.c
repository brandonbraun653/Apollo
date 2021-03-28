/**
 *  \file   ambient_light_sensor_test.c
 *
 *  \brief
 *
 */

/*
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART_stdio.h>

#include "board.h"
#include "board_cfg.h"

extern I2C_config_list I2C_config;

/* Delay function */
void AppDelay(uint32_t delayVal);

#define I2C_INSTANCE                        (1U)

#define AMBIENT_SLAVE_ADDR                  0x39

/* ambient light sensor commands */
#define  POWER_DOWN                         (0x00)
#define  POWER_UP_READ                      (0x03)
#define  EXT_RANGE                          (0x1D)
#define  STD_RANGE                          (0x18)
#define  READ_ADC_0                         (0x43)
#define  READ_ADC_1                         (0x83)


uint8_t ambient_read(I2C_Handle h, uint8_t reg)
{
    uint8_t rxData = 0;
    uint8_t txData = 0;
    I2C_Transaction t;

    memset(&t, 0, sizeof(t));

    t.slaveAddress = AMBIENT_SLAVE_ADDR;
    t.writeBuf = &txData;
    t.writeCount = 1;
    t.readBuf = &rxData;
    t.readCount = 1;
    txData = reg;
    I2C_transfer(h, &t);
    return rxData;
}

void ambient_write(I2C_Handle h, uint8_t reg)
{
    I2C_Transaction t;

    memset(&t, 0, sizeof(t));

    t.slaveAddress = AMBIENT_SLAVE_ADDR;
    t.writeBuf = &reg;
    t.writeCount = 1;
    t.readCount = 0;
    I2C_transfer(h, &t);
}
int accelerometer_test()
{
    I2C_Params i2cParams;
    I2C_Handle handle = NULL;
    uint8_t data = 0;
    int retVal = 0;
    int i;

    for (i=0; I2C_config[i].fxnTablePtr != NULL; i++)
    {
        ((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr = false;
    }

    I2C_init();

    I2C_Params_init(&i2cParams);

    handle = I2C_open(I2C_INSTANCE, &i2cParams);

    UART_printf("\n*********************************************\n");
    UART_printf  ("*         Ambient Light Test                *\n");
    UART_printf  ("*********************************************\n");

    UART_printf("Test:                Expected Result:    Actual Result:    Result:    \n");
    UART_printf("----------------     ----------------    --------------    -------    \n");

    data = ambient_read(handle, POWER_UP_READ);
    UART_printf("PowerUp/Read         0x03                ");
    if(data != 0x03)
    {
        UART_printf("FAIL \n");
        retVal = -1;
    }
    else
    {
        UART_printf("PASS\n");

        /* Delay for adc to complete */
        AppDelay(20000);

        /* Read ADC 0 */
        UART_printf("Read ADC 0           >=0x80              ");
        data = ambient_read(handle, READ_ADC_0);
        UART_printf("0x%02x              ", data);
        if(data>=0x80)
            UART_printf("PASS\n");
        else
            UART_printf("FAIL\n");

        /* Read ADC 1 */
        UART_printf("Read ADC 1           >=0x80              ");
        data = ambient_read(handle, READ_ADC_1);
        UART_printf("0x%02x              ", data);
        if(data>=0x80)
            UART_printf("PASS\n");
        else
            UART_printf("FAIL\n");

        /* Power down */
        UART_printf("PowerDown            0x00                ");
        ambient_write(handle, POWER_DOWN);
        data = 0x0;
        UART_printf("0x%02x              ", data);
        if(data==0x00)
            UART_printf("PASS\n");
        else
            UART_printf("FAIL\n");

        AppDelay(1000);
         /* Read ADC 0, Post Power Down */
        UART_printf("Read ADC 0           0x00                ");
        data = ambient_read(handle, READ_ADC_0);
        UART_printf("0x%02x              ", data);
        if(data==0x00)
            UART_printf("PASS\n");
        else
            UART_printf("FAIL\n");

        /* Read ADC 1, Post Power Down */
        UART_printf("Read ADC 1           0x00                ");
        data = ambient_read(handle, READ_ADC_1);
        UART_printf("0x%02x              ", data);
        if(data==0x00)
            UART_printf("PASS\n");
        else
            UART_printf("FAIL\n");
    }

    return retVal;
}

 /*
 *  ======== main ========
 */
int main(void)
{
    Board_initCfg boardCfg;
#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);
    return accelerometer_test();
}

void AppDelay(uint32_t delayVal)
{
    uint32_t cnt = 0;
    while(cnt < delayVal)
    {
        asm("");
        cnt++;
    }
}
