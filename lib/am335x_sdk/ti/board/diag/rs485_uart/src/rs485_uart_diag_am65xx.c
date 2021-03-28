/*
 * Copyright (c) 2018, Texas Instruments Incorporated
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

#include <stdlib.h>
#include <stdint.h>
#include <tistdtypes.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <ti/csl/csl_gpio.h>

#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/soc/UART_soc.h>

#include "board.h"
#include "board_cfg.h"
#include "diag_common_cfg.h"

#include <ti/board/src/am65xx_idk/am65xx_idk_pinmux.h>
#include <ti/drv/pruss/soc/am65xx/pruicss_soc.c>

#define SOC_PAD_COFG_66					(0x108)

/* pin mux mode */
#define GPIO_PADCONFIG_MUX_MODE			(7U)
#define UART_INSTANCE					(2U) 

/*This macro configures the BAUD rate*/
#if defined(DIAG_COMPLIANCE_TEST)
#define BAUD_RATE                       (921600U)
#else
#define BAUD_RATE 						(115200U)
#endif

#define PRU_UART_PWREMU_MGMT                   (CSL_PRU_ICSSG1_PR1_ICSS_UART_UART_SLV_BASE + 0x30)

#if defined(DIAG_STRESS_TEST)
#define FIFO_SIZE                       (256)
#define TEST_DATA_LEN                   (10*1024*1024)   /* 10MB of transmit data */

uint8_t txBuf[TEST_DATA_LEN] __attribute__ ((section ("uartbuffer")));
uint8_t rxBuf[TEST_DATA_LEN] __attribute__ ((section ("uartbuffer")));
#else
char echoPrompt[] =
	"\n*********************************************\n"  
	  "*             PRU-ICSS UART Test            *\n"
	  "*********************************************\n"

	"\nTesting UART print to console at 115.2k baud rate\n"
	"Press 'y' to verify pass: ";

char echoPromptPass[] = " Test Passed\n";
char echoPromptFail[] = " Test Failed\n";

char scanPrompt;
#endif

void BoardDiag_enablePru(void)
{
	uint32_t volatile *addr;

	addr = (volatile uint32_t *)PRU_UART_PWREMU_MGMT;
	*addr = 0x6001;
}

#if defined(DIAG_STRESS_TEST)

/**
 * \brief  Generate pattern function
 *
 * This function generates a test pattern to verify the UART interface
 * read/write access.
 *
 * \param   txBuf  [IN]   Transmit data buffer
 * \param   length [IN]   length of the buffer
 *
 */
static void GeneratePattern(uint8_t *txBuf, uint32_t length)
{
    uint32_t idx;
    uint32_t data = 48;

    for(idx = 0; idx < length; idx++)
    {
        txBuf[idx] = (uint8_t)data;
        data++;
        if(data > 126)
        {
            data = 48;
        }
    }
}
#endif

int BoardDiag_pruIcssUartTest()
{
	UART_Handle uart = NULL;
    UART_Params uartParams;
	UART_HwAttrs uart_cfg;
#if defined(DIAG_STRESS_TEST)
    uint32_t          ret = 0;
    uint32_t          index;
    uint32_t          failIndex;
    uint8_t input = '\n';
#endif
	/* Enabling the uart TX and RX lines */
	BoardDiag_enablePru();
#if !defined(DIAG_STRESS_TEST)
	UART_printf("\n*********************************************\n"); 
	UART_printf  ("*           PRU-ICSS UART Test              *\n");
	UART_printf  ("*********************************************\n");
#endif
	UART_Params_init(&uartParams);

    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.readDataMode = UART_DATA_TEXT;
    uartParams.writeDataMode = UART_DATA_TEXT;
    uartParams.baudRate= BAUD_RATE;
    uartParams.dataLength= UART_LEN_8;
    uartParams.stopBits= UART_STOP_ONE;
    uartParams.parityType= UART_PAR_NONE;

	/* Get the default UART init configurations */
    /* One of the instances of UART driver will be used
       to access the PRU-ICSS UART registers.
       Base address is mapped to PRU core using UART_socSetInitCfg  */
    UART_socGetInitCfg(UART_INSTANCE, &uart_cfg);

    uart_cfg.enableInterrupt = 0;
    uart_cfg.baseAddr = CSL_PRU_ICSSG1_PR1_ICSS_UART_UART_SLV_BASE;
    uart_cfg.frequency = 192000000;

    /* Get the default UART init configurations */
    UART_socSetInitCfg(UART_INSTANCE, &uart_cfg);

    uart = UART_open(UART_INSTANCE, &uartParams);
#if defined(DIAG_COMPLIANCE_TEST)
    /*setting DLL register for maximum baudRate*/
    volatile uint32_t *pru_uart_dll;
    pru_uart_dll = (uint32_t *)(0x0B128020);
    *pru_uart_dll = *pru_uart_dll & (~(0xff));
    *pru_uart_dll = *pru_uart_dll | 0xd;
#endif
	Board_pinMuxSetMode(SOC_PAD_COFG_66, (GPIO_PADCONFIG_MUX_MODE| PIN_INPUT_ENABLE));
	GPIO_init();
#if defined(DIAG_STRESS_TEST)
    /* Generate the data */
    GeneratePattern(txBuf, TEST_DATA_LEN);

    for(index = 0; index < TEST_DATA_LEN; index += FIFO_SIZE)
    {
        GPIO_write(0, GPIO_PIN_HIGH);
        ret = UART_write(uart, (uint8_t *)&txBuf[index], FIFO_SIZE);
        if(!ret)
        {
            UART_close(uart);
            return -1;
        }
        BOARD_delay(1000);
        GPIO_write(0, GPIO_PIN_LOW);
        ret = UART_readPolling(uart,(uint8_t *)&rxBuf[index], FIFO_SIZE);
        if(ret != FIFO_SIZE)
        {
            UART_close(uart);
            return -1;
        }
    }
    /* Verify Data */
    if (BoardDiag_memCompare(&txBuf[0], &rxBuf[0], TEST_DATA_LEN, &failIndex) == false)
    {
        UART_write(uart,&input,1U);
        UART_close(uart);
        return -1;
    }
    else
    {
        UART_write(uart,&input,1U);
        UART_close(uart);
    }
#else
    UART_printf("\nCheck PRU UART console for the test logs\n");
	GPIO_write(0, GPIO_PIN_HIGH);
	UART_write(uart, echoPrompt, sizeof(echoPrompt));
	BOARD_delay(1000);
#if !defined(DIAG_COMPLIANCE_TEST)
	GPIO_write(0, GPIO_PIN_LOW);
	UART_readPolling(uart, &scanPrompt, 1);
	GPIO_write(0, GPIO_PIN_HIGH);
#else
    scanPrompt = 'y';
#endif

	if ( (scanPrompt == 'y') || (scanPrompt == 'Y') ) 
    {
		UART_write(uart, echoPromptPass, sizeof(echoPromptPass));
		UART_close(uart);
	}
	else
    {
		UART_write(uart, echoPromptFail, sizeof(echoPromptFail));
		UART_close(uart);
		return -1;
	}
#endif

    return 0;
}

int main(void)
{
	int ret = 0;
    Board_STATUS status;
    Board_initCfg boardCfg;

#if defined(DIAG_STRESS_TEST)
    boardCfg = BOARD_INIT_UNLOCK_MMR | BOARD_INIT_PINMUX_CONFIG;
#else
    boardCfg = BOARD_INIT_UNLOCK_MMR | BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_UART_STDIO;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
		return -1;
    }

	ret = BoardDiag_pruIcssUartTest();
#if !defined(DIAG_STRESS_TEST)
    if(ret != 0)
    {
        UART_printf("\nPRU-ICSS UART Test Failed!!\n");
        return ret;
    }
    else
    {
        UART_printf("\nPRU-ICSS UART Test Passed!!\n");
    }

    UART_printf("\nPRU-ICSS UART Test Completed!\n");
#endif
    return ret;
}
