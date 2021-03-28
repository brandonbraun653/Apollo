
/**
 * @file   main_uart_example.c
 *
 * @brief  This file tests the UART driver APIs with all the suported
 *         input parameters values
 */
/*
 * Copyright (c) 2014 - 2019, Texas Instruments Incorporated
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

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* CSL Header files */
#include <ti/csl/csl_chip.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/soc/UART_soc.h>

/* Board Header files */
#include <ti/board/board.h>
#include <ti/starterware/include/prcm.h>

// Test UART instance
#define UART_TEST_INSTANCE      ( 9U )

// Length of the input in number of characters
#define INPUT_LENGTH            ( 16U )

char echoPrompt[]="\nuart driver and utils example test cases :\nEnter 150 characters or press the esc \n";
char echoPrompt1[]="DATA RECEIVED IS\n ";

bool Board_initUART(void)
{
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;
    int32_t status;
    bool ret = true;

    /* 
       Initialize the UART PRU FW configuration.
       Place before Board_init() to allow configuration to include BOARD_INIT_UART_STDIO.
    */
    UART_socInitFwCfg();
    
    boardCfg = BOARD_INIT_PLL | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_DDR | BOARD_INIT_ICSS_PINMUX;
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        ret = false;
    }
    
    if (ret == true)
    {
        // Enable PRU-ICSS module
        status = PRCMModuleEnable(CHIPDB_MOD_ID_PRU_ICSS, 1U, 0U);
        if (status != S_PASS)
        {
            ret = false;
        }
    }
    
    if (ret == true)
    {
        // Enable UART1 HW module
        status = PRCMModuleEnable(CHIPDB_MOD_ID_UART, 1U, 0U);
        if (status != S_PASS)
        {
            ret = false;
        }
    }

    return ret;
}

Void uart_test(UArg arg0, UArg arg1)
{
    uint32_t uartInst;
    char input = '\n';
    char *buffPointer;

    // get UART instance ID
    uartInst = (uint32_t)arg0;
    
    UART_stdioInit(uartInst);    
    
    buffPointer = (char *)malloc(INPUT_LENGTH);
    memset(buffPointer, 0, INPUT_LENGTH);

    UART_puts("\nuart driver and utils example test cases :\nEnter 16 characters or press the esc \n",sizeof("uart driver and utils example test cases : please enter 16 characters or press the esc or carriage return\n"));

    while (1) 
    {
        memset(buffPointer,0,INPUT_LENGTH);
        UART_gets(buffPointer, INPUT_LENGTH);
        UART_puts(&input,1);
        UART_printf("Data received is\n");
        UART_puts(buffPointer, INPUT_LENGTH);
        UART_printStatus("\nTest Passed\n");
        UART_puts("\nuart driver and utils example test cases :\nEnter 16 characters or press the esc \n",sizeof("uart driver and utils example test cases : please enter 16 characters or press the esc or carriage return\n"));
    }
} /* uart_test */

/*
 *  ======== main ========
 */
int main(void)
{
    Task_Handle task;
    Task_Params taskParams;
    Error_Block eb;

    if (Board_initUART() == false)
    {
        System_printf("\nBoard_initUART failed!\n");
        BIOS_exit(0);
    }

    Error_init(&eb);
    
    // Initialize task params
    Task_Params_init(&taskParams);
    taskParams.arg0 = (UArg)UART_TEST_INSTANCE;
    taskParams.arg1 = (UArg)0;
    taskParams.stackSize = 1024*8;

    // Create task
    task = Task_create(uart_test, &taskParams, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    /* Start BIOS */
    BIOS_start();
    return (0);
} /* main */
