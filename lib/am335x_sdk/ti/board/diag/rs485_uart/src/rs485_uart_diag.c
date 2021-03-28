/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <ti/drv/uart/UART_stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <tistdtypes.h>
#include <ti/csl/hw_types.h>

#include <ti/drv/uart/UART.h>

#include "board.h"
#include "board_cfg.h"

#include "ti/drv/pruss/soc/am572x/pruicss_soc.c"
#include "test_pruss_intc_mapping.h"


#include "rs485_prufirmware.h"

#define UART_INSTANCE	1 //UART2

#define PRUSS_INSTANCE_IN_USE 2

/*This macro configures the BAUD rate*/
#define BAUD_RATE 230400

PRUICSS_Handle pruIcssHandle;
static unsigned char prussIcssInstance = PRUSS_INSTANCE_IN_USE;

#define LONG_STRING

#ifdef LONG_STRING
char echoPrompt[50] = "RS485 Test - 1234567890 abcdefghijklmnopqrstuvwxyz";
char scanPrompt[sizeof(echoPrompt)];
#else
char echoPrompt[] = {0x45, 0x98, 0x89,0x77};
char scanPrompt[sizeof(echoPrompt)];
#endif

void Delay(uint32_t delay)
{
    volatile uint32_t delay1 = delay*10;
    while (delay1--) ;
}

int uart_test()
{

    char p = 'r';
	int dev=0,i=0,err=0;
	UART_Handle uart = NULL;
    UART_Params uartParams;

	UART_printf("\n*********************************************\n");
	UART_printf  ("*           RS485 UART Test                 *\n");
	UART_printf  ("*********************************************\n");

	UART_Params_init(&uartParams);

    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.readDataMode = UART_DATA_TEXT;
    uartParams.writeDataMode = UART_DATA_TEXT;
    uartParams.baudRate= BAUD_RATE;
    uartParams.dataLength= UART_LEN_8;
    uartParams.stopBits= UART_STOP_ONE;
    uartParams.parityType= UART_PAR_NONE;


    uart = UART_open(UART_INSTANCE, &uartParams);

	UART_printf("\nTesting UART print to console at 115.2k baud rate\n");
	UART_printf("Press '1' for Diag and '2' for echo");
	UART_scanFmt("%d", &dev);

	if(dev==1)
	{
		while(1)
		{
			UART_write(uart, echoPrompt, sizeof(echoPrompt));
			UART_printf("\nData sent to EVM2\n");
			UART_printf("Check for received data in EVM2 and press any key");
			UART_scanFmt("%d", &dev);

			UART_printf("Waiting to receive from EVM2\n");
			UART_readPolling(uart, scanPrompt, sizeof(scanPrompt));

			for(i=0;i<sizeof(scanPrompt);i++)
			{
				if(scanPrompt[i]!=echoPrompt[i])
				{
					UART_printf("\nData Mismatch - %d byte value is %x should be %x",i,scanPrompt[i],echoPrompt[i]);
					err++;
				}
			}

			if (!err) {
				UART_printf("\n%s\n",scanPrompt);
				UART_printf("\nData Received Successfully - Test PASSED!\n");
				err=0;
			}

			UART_printf("Send Data to EVM2 and press any key");
			UART_scanFmt("%d", &dev);

		}

	}
	else //dev==2
	{
		while(1)
		{
			UART_printf("\nWaiting to receive from EVM1\n");
			UART_readPolling(uart, scanPrompt, sizeof(scanPrompt));

			for(i=0;i<sizeof(scanPrompt);i++)
			{
				if(scanPrompt[i]!=echoPrompt[i])
				{
					UART_printf("\nData Mismatch - %d byte value is %x should be %x",i,scanPrompt[i],echoPrompt[i]);
					err++;
				}
			}

			if (!err) {
				UART_printf("\n%s\n",scanPrompt);
				UART_printf("\nData Received Successfully - Test PASSED!\n");
				err=0;
			}

			UART_printf("Send Data to EVM2 and press any key");
			UART_scanFmt("%d", &dev);

			UART_write(uart, echoPrompt, sizeof(echoPrompt));

			UART_printf("\nData sent to EVM1\n");

			UART_printf("Check for received data on EVM1 and press any key");
			UART_scanFmt("%d", &dev);
		}
	}

	UART_close(uart);

	if (!err) {
		UART_printf("\nTest PASSED!\n");
		return 0;
	}
	else {
		UART_printf("\nTest FAILED!\n");
		return -1;
	}

}

int pruss_init(int prussn)
{
    uint32_t pruss_base=0;

    if(prussn==1)
        pruss_base = CSL_MPU_PRUSS1_U_CFG_REGS;
    else
        pruss_base = CSL_MPU_PRUSS2_U_CFG_REGS;

    //Enable the PRUSS clock
    if(prussn==1)
    {
        HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_PRUSS1_CLKCTRL) = 0;
    }
    else
    {
        HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_PRUSS2_CLKCTRL) = 0;
    }

    Delay(50);

    if(prussn==1)
    {
        HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_PRUSS1_CLKCTRL) = 2;
        while(0 != (HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_PRUSS1_CLKCTRL) & 0x00030000));
    }
    else
    {
        HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_PRUSS2_CLKCTRL) = 2;
        while(0 != (HWREG(CSL_MPU_L4PER_CM_CORE_REGS + CM_L4PER2_PRUSS2_CLKCTRL) & 0x00030000));
    }

    HWREG(pruss_base + 0x04) = 0x06; //NO_STANDBY
    Delay(50);

	return 0;

}

int rs485_pru_firmware()
{
	pruss_init(prussIcssInstance);

	pruIcssHandle = PRUICSS_create(pruss_config,(int) prussIcssInstance);

    PRUICSS_pruDisable(pruIcssHandle, 1);

	PRUICSS_setPRUBuffer(pruIcssHandle,1, (void*)PRU2_FIRMWARE_NAME, sizeof(PRU2_FIRMWARE_NAME));

	PRUICSS_pruWriteMemory(pruIcssHandle,PRU_ICSS_DATARAM((uint32_t)1),0U,(uint32_t *)PRU2_FIRMWARE_DATA,sizeof(PRU2_FIRMWARE_DATA));

	PRUICSS_pruExecProgram(pruIcssHandle,1);

   	PRUICSS_pruEnable(pruIcssHandle,1);

	return 0;
}

int main(void)
{
    Board_initCfg boardCfg;
#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

	rs485_pru_firmware();

    return uart_test();
}
