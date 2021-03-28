/*
 * Copyright (c) 2016, Texas Instruments Incorporated
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

#include "board.h"
#include "board_cfg.h"

#include <ti/drv/gpio/GPIO.h>
#include <ti/csl/soc.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

#ifdef SOC_K2G
#include "diag_common_cfg.h"
#endif

/* Port and pin number mask for config.
   Bits 7-0: Pin number  and Bits 15-8: Port number */
#define GPIO_SERIAL_CFG      (0x0136)

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
	GPIO_SERIAL_CFG | GPIO_CFG_OUTPUT
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL
};

/* GPIO Driver configuration structure */
GPIO_v0_Config GPIO_v0_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};

extern void BOARD_delay(uint32_t usecs);

int uart_test()
{
    char p = 'r';
    uint32_t mode = 0;

	pinMuxSetMode(125, 3);
	GPIO_init();

	UART_printf("\n*************************************************\n");
	UART_printf  ("*                 UART2USB Test                 *\n");
	UART_printf  ("*************************************************\n");

    mode = GPIO_read(0);
    if (mode == 0)
    {
	    UART_printf("\nCheck the messages on UART2USB console\n");
	    BOARD_delay(250000);
	    GPIO_write(0, 1);
	    BOARD_delay(250000);
    }
    else
    {
        UART_printf("Already using USB UART mode...\n");
    }

    UART_printf("\nTesting UART print to console at 115.2k baud rate\n");
	UART_printf("Press 'y' to verify pass: ");

	UART_scanFmt("%c", &p);

    if (mode == 0)
	{
        GPIO_write(0, 0);
	    BOARD_delay(250000);
    }

	UART_printf("\nReceived: %c\n", p);
	if ( (p == 'y') || (p == 'Y') ) {
		UART_printf("\nTest PASSED!\n");
		return 0;
	}
	else {
		UART_printf("\nTest FAILED!\n");
		return -1;
	}
}

int main(void)
{
    Board_initCfg boardCfg;

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);
    return uart_test();
}
