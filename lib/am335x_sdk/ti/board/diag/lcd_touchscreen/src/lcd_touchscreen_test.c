/**
 *  \file   main.c
 *
 *  \brief  Example application main file. This application will toggle the led.
 *          The led toggling will be done inside an callback function, which
 *          will be called by Interrupt Service Routine. Interrupts are
 *          triggered manually and no external source is used to trigger
 *          interrupts.
 *
 */

/*
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/csl/soc/am572x/src/cslr_control_core_pad_io.h>

#include "include/lcd_touchscreen.h"

#include "board.h"
#include "board_cfg.h"

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/
void AppDelay(uint32_t delayVal);
extern I2C_config_list I2C_config;

/* Board specific definitions */
#define SOC_CORE_PAD_IO_REGISTERS_BASE              (0x4a003400U)
#define CTRL_CORE_PAD_GPIO6_15						(0x28cU)
#define CTRL_CORE_PAD_GPIO6_15_PIN                  (0x20000 | 0x0E)
#define CM_WKUPAON_GPIO1_CLKCTRL                    (0x4AE07838)
#define CM_L4PER_GPIO6_CLKCTRL						(0x4A009780)
#define CLK_ENABLE_VAL                              (0x00000082)
#define HW_WR_REG32(addr, data)   *(unsigned int*)(addr) =(unsigned int)(data)
#define GPIO_PIN_VAL_LOW     (0U)
#define GPIO_PIN_VAL_HIGH    (1U)
#define I2C_INSTANCE           (0U)

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

int tsCtrlWrite(I2C_Handle h, uint8_t reg, uint8_t val)
{
	int ret = 0;
	uint8_t tx[2];
	I2C_Transaction t;

    memset(&t, 0, sizeof(t));
	t.slaveAddress = TOUCH_SLAVE_ADDR;
	t.writeBuf = tx;
	t.writeCount = 2;
	t.readCount = 0;
	tx[0] = reg;
	tx[1] = val;
	I2C_transfer(h, &t);
	return ret;
}

uint8_t tsCtrlRead(I2C_Handle h, uint8_t reg)
{
	
	uint8_t tx[1];
	uint8_t rx[1];
	I2C_Transaction t;

    memset(&t, 0, sizeof(t));
	t.slaveAddress = TOUCH_SLAVE_ADDR;
	t.writeBuf = tx;
	t.writeCount = 1;
	t.readBuf = rx;
	t.readCount = 1;
	tx[0] = reg;
	I2C_transfer(h, &t);
	return rx[0];
}

int touchInit(I2C_Handle h)
{
	int ret = 0;
    tsCtrlWrite(h, ID_G_AUTO_CLB_MODE, 0x00);   //calibrate
    AppDelay(100);
    while(!tsCtrlRead(h, ID_G_AUTO_CLB_MODE));
    tsCtrlWrite(h, DEVICE_MODE, NORMAL_OPMODE);
    tsCtrlWrite(h, ID_G_THGROUP, 0x23);
    tsCtrlWrite(h, ID_G_THPEAK, 0x3c);
    tsCtrlWrite(h, ID_G_THCAL, 0x1d);
    tsCtrlWrite(h, ID_G_THWATER, 0xd3);
    tsCtrlWrite(h, ID_G_TEMP, 0xeb);
    tsCtrlWrite(h, ID_G_THDIFF, 0xa0);
    tsCtrlWrite(h, ID_G_TIME_ENTER_MONITOR, 0xc8);
    tsCtrlWrite(h, ID_G_PERIODACTIVE, 0x06);
    tsCtrlWrite(h, ID_G_PERIODMONITOR, 0x28);
    tsCtrlWrite(h, ID_G_MODE, 0x01);
	return ret;
}

int tsReadAll(I2C_Handle h, uint8_t *rx)
{
	uint8_t tx[1] = {0};
	I2C_Transaction t;

    memset(&t, 0, sizeof(t));
	t.slaveAddress = TOUCH_SLAVE_ADDR;
	t.writeBuf = tx;
	t.writeCount = 1;
	t.readBuf = rx;
	t.readCount = 255;
	I2C_transfer(h, &t);
	return 0;
}

void touchLoop(I2C_Handle h)
{
	uint8_t rx[255] = {0};
	UART_printf("Input 9 touches to exit test\n");
	UART_printf("Touch\tt1\t\tt2\t\tt3\t\tt4\t\tt5\t\tt6\t\tt7\t\tt8\t\tt9\n");
	while(rx[TD_STATUS] != 0x9)
	{
		tsReadAll(h, rx);
		if (rx[TD_STATUS] > 0 && rx[TD_STATUS] < 10)
		{
			UART_printf("%d\t%4d,%4d\t%4d,%4d\t%4d,%4d\t%4d,%4d\t%4d,%4d\t%4d,%4d\t%4d,%4d\t%4d,%4d\t%4d,%4d\n",
					rx[TD_STATUS],
              (((rx[TOUCH1_XH]&0x0F)<<8) | (rx[TOUCH1_XL])),
              (((rx[TOUCH1_YH]&0x0F)<<8) | (rx[TOUCH1_YL])),
              (((rx[TOUCH2_XH]&0x0F)<<8) | (rx[TOUCH2_XL])),
              (((rx[TOUCH2_YH]&0x0F)<<8) | (rx[TOUCH2_YL])),
              (((rx[TOUCH3_XH]&0x0F)<<8) | (rx[TOUCH3_XL])),
              (((rx[TOUCH3_YH]&0x0F)<<8) | (rx[TOUCH3_YL])),
              (((rx[TOUCH4_XH]&0x0F)<<8) | (rx[TOUCH4_XL])),
              (((rx[TOUCH4_YH]&0x0F)<<8) | (rx[TOUCH4_YL])),
              (((rx[TOUCH5_XH]&0x0F)<<8) | (rx[TOUCH5_XL])),
              (((rx[TOUCH5_YH]&0x0F)<<8) | (rx[TOUCH5_YL])),
              (((rx[TOUCH6_XH]&0x0F)<<8) | (rx[TOUCH6_XL])),
              (((rx[TOUCH6_YH]&0x0F)<<8) | (rx[TOUCH6_YL])),
              (((rx[TOUCH7_XH]&0x0F)<<8) | (rx[TOUCH7_XL])),
              (((rx[TOUCH7_YH]&0x0F)<<8) | (rx[TOUCH7_YL])),
              (((rx[TOUCH8_XH]&0x0F)<<8) | (rx[TOUCH8_XL])),
              (((rx[TOUCH8_YH]&0x0F)<<8) | (rx[TOUCH8_YL])),
              (((rx[TOUCH9_XH]&0x0F)<<8) | (rx[TOUCH9_XL])),
              (((rx[TOUCH9_YH]&0x0F)<<8) | (rx[TOUCH9_YL]))
			);
		}
		AppDelay(10000000);
	}
}

/*
 *  ======== test function ========
 */
int touchscreen_test()
{
	uint8_t messageSize = 4;
	int ret = 0;
	int i;
    I2C_Params i2cParams;
    I2C_Handle handle = NULL;

	for (i=0; I2C_config[i].fxnTablePtr != NULL; i++)
	{
		((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr = false;
	}

    I2C_init();

    I2C_Params_init(&i2cParams);

    handle = I2C_open(I2C_INSTANCE, &i2cParams);

	UART_printf("\n*********************************************\n"); 
	UART_printf  ("*             Touchscreen Test              *\n");
	UART_printf  ("*********************************************\n");

	touchInit(handle);
	touchLoop(handle);
	I2C_close(handle);
	return ret;
}

/*
 *  ======== main ========
 */
int main(void)
{
    Board_initCfg boardCfg;
#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG | 
    	BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);
	return touchscreen_test();
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
