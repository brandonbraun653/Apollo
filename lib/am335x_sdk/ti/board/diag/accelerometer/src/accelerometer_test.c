/**
 *  \file   accelerometer_test.c
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

#if defined(skAM335x)
#define I2C_ACCEL_INSTANCE                        (0U)
#else
#define I2C_ACCEL_INSTANCE                        (1U)
#endif

#define SELF_TEST_LOOPS                     750

#define ACCEL_SLAVE_ADDR                    0x18
#define  WHO_AM_I                           (0x0F)
#define  CTRL_REG1                          (0x20)
#define  CTRL_REG2                          (0x21)
#define  CTRL_REG3                          (0x22)
#define  CTRL_REG4                          (0x23)
#define  CTRL_REG5                          (0x24)
#define  STATUS                             (0x27)
#define  OUT_X_L_DATA                       (0x28)
#define  OUT_X_H_DATA                       (0x29)
#define  OUT_Y_L_DATA                       (0x2A)
#define  OUT_Y_H_DATA                       (0x2B)
#define  OUT_Z_L_DATA                       (0x2C)
#define  OUT_Z_H_DATA                       (0x2D)

uint8_t accel_read(I2C_Handle h, uint8_t reg)
{
    uint8_t rxData = 0;
    uint8_t txData = 0;
    I2C_Transaction t;

    memset(&t, 0, sizeof(t));

    t.slaveAddress = ACCEL_SLAVE_ADDR;
    t.writeBuf = &txData;
    t.writeCount = 1;
    t.readBuf = &rxData;
    t.readCount = 1;
    txData = reg;
    I2C_transfer(h, &t);
    return rxData;
}

void accel_write(I2C_Handle h, uint8_t reg, uint8_t val)
{
    uint8_t txData[2] = {0, 0};
    I2C_Transaction t;

    memset(&t, 0, sizeof(t));

    t.slaveAddress = ACCEL_SLAVE_ADDR;
    t.writeBuf = txData;
    t.writeCount = 2;
    t.readCount = 0;
    txData[0] = reg;
    txData[1] = val;
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

    handle = I2C_open(I2C_ACCEL_INSTANCE, &i2cParams);

    UART_printf("\n*********************************************\n");
    UART_printf  ("*         Accelerometer Test                *\n");
    UART_printf  ("*********************************************\n");

    UART_printf("Test:                Expected Result:    Actual Result:    Result:    \n");
    UART_printf("----------------     ----------------    --------------    -------    \n");

    data = accel_read(handle, WHO_AM_I);
    UART_printf("0x%x            ", data);
    if(data != 0x32)
    {
        UART_printf("FAIL \n");
        retVal = -1;
    }
    else
    {
        UART_printf("PASS\n");
        /* Take out of power-down */
        data = accel_read(handle, CTRL_REG1);
        data |=(1<<5);
        accel_write(handle, CTRL_REG1, data);

        /* Enable self-test */
        data = accel_read(handle, CTRL_REG4);
        data |=(1<<1);
        accel_write(handle, CTRL_REG4, data);

        /* Check X axis */
        UART_printf("Self-Test(X Axis)    120-550             ");
        for(i=0;i<SELF_TEST_LOOPS;i++)
        {
            /* wait for data ready */
            do
            {
              data=accel_read(handle, STATUS);
            }while ( (data&0x1) != 0x1 );
            data=accel_read(handle, OUT_X_L_DATA);
            if(data>=120 && data<=550)
              break;
            }
            UART_printf("%3d               ", data);
            if(data>=120 && data<=550)
            UART_printf("PASS\n");
            else
            {
                UART_printf("FAIL\n");
                retVal=1;
            }

        UART_printf("Self-Test(Y axis)    120-550             ");
        for(i=0;i<SELF_TEST_LOOPS;i++)
        {
            //wait for data ready
            do
            {
              data=accel_read(handle, STATUS);
            }while ( (data&0x2) != 0x2 );
            data=accel_read(handle, OUT_Y_L_DATA);
            if(data>=120 && data<=550)
              break;
        }

        UART_printf("%3d               ", data);
        if(data>=120 && data<=550)
            UART_printf("PASS\n");
        else
        {
            UART_printf("FAIL\n");
            retVal=1;
        }

        //Check Z axis
        UART_printf("Self-Test(Z Axis)    140-750             ");
        for(i=0;i<SELF_TEST_LOOPS;i++)
        {
            //wait for data ready
        do
        {
          data=accel_read(handle, STATUS);
        }while ( (data&0x4) != 0x4 );
        data=accel_read(handle, OUT_Z_L_DATA);
        if(data>=140 && data<=750)
          break;
        }
        UART_printf("%3d               ", data);
        if(data>=140 && data<=750)
            UART_printf("PASS\n");
        else
        {
            UART_printf("FAIL\n");
            retVal=1;
        }
        if(retVal)
        {
            UART_printf("Exiting\n");
            return retVal;
        }
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
