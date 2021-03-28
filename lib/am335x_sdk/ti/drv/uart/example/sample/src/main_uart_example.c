
/**
 * @file   main_uart_example.c
 *
 * @brief  This file tests the UART driver APIs with all the suported
 *         input parameters values
 */
/*
 * Copyright (c) 2014 - 2017, Texas Instruments Incorporated
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

#ifndef BARE_METAL
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#endif

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

/* CSL Header files */
#ifdef _TMS320C6X
#include <ti/csl/csl_chip.h>
#endif

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/drv/uart/test/src/UART_board.h>

/*
 *  ======== echoFxn ========
 *  Task for this function is created statically. See the project's .cfg file.
 *
 */

 /* Length of the input in number of characters */
#define INPUT_LENGTH           (16U)

char echoPrompt[]="\nuart driver and utils example test cases :\nEnter 150 characters or press the esc \n";
char echoPrompt1[]="DATA RECEIVED IS\n ";

#if defined (SOC_AM572x) || defined (SOC_AM571x)
void UART_CrossbarConfigure(void);
#endif

void Board_initUART(void)
{
    Board_initCfg boardCfg;

#if defined(evmK2E) || defined(evmC6678)
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_MODULE_CLOCK  |
               BOARD_INIT_UART_STDIO;
#endif

#if defined (evmK2H) || defined (evmK2K) || defined (evmK2E) || defined (evmK2L) || defined(evmK2G) || defined(evmC6678) || defined(evmC6657)
#ifdef _TMS320C6X
    /* boardCfg |= BOARD_INIT_PLL | BOARD_INIT_DDR; */
#endif
#endif
    Board_init(boardCfg);
}

#ifdef BARE_METAL
void main()
#else
Void uart_test(UArg arg0, UArg arg1)
#endif
{
    char input = '\n';
    char *buffPointer;

#ifdef BARE_METAL
    Board_initUART();
#endif
    buffPointer = (char*)malloc(INPUT_LENGTH);
    memset(buffPointer,0,INPUT_LENGTH);

    UART_puts("\nuart driver and utils example test cases :\nEnter 16 characters or press the esc \n",sizeof("uart driver and utils example test cases : please enter 16 characters or press the esc or carriage return\n"));

    while(1) {
        memset(buffPointer,0,INPUT_LENGTH);
        UART_gets(buffPointer, INPUT_LENGTH);
        UART_puts(&input,1);
        UART_printf("Data received is\n");
        UART_puts(buffPointer, INPUT_LENGTH);
        UART_printStatus("\nTest Passed\n");
        UART_puts("\nuart driver and utils example test cases :\nEnter 16 characters or press the esc \n",sizeof("uart driver and utils example test cases : please enter 16 characters or press the esc or carriage return\n"));
    }
} /* uart_test */

#ifndef BARE_METAL
/*
 *  ======== main ========
 */
int main(void)
{
    /* Call board init functions */
    Task_Handle task;
    Error_Block eb;

    Board_initUART();

#if defined(SOC_AM572x) || defined(SOC_AM571x)
    UART_CrossbarConfigure();
#endif


    Error_init(&eb);
    task = Task_create(uart_test, NULL, &eb);
        if (task == NULL) {
            System_printf("Task_create() failed!\n");
            BIOS_exit(0);
        }

    /* Start BIOS */
    BIOS_start();
    return (0);
} /* main */
#endif


#if defined(SOC_AM572x) || defined(SOC_AM571x)
void UART_CrossbarConfigure(void)
{
#if defined (_TMS320C6X)
    /*
     * AM5 DSP does not have a default Xbar connection for UART
     * interrupt, need the following Xbar interrupt configuration
     */
    /* Use reserved DSP1_IRQ_34 */
    CSL_xbarDspIrqConfigure(1,
                            CSL_XBAR_INST_DSP1_IRQ_34,
                            CSL_XBAR_UART3_IRQ);
#endif
}

#endif
