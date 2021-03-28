/*
 * Copyright (C) 2015-2016 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file  uart_test.c
 *
 *  \brief  Example application main file. This application will demonstrate
 *          UART RTOS driver for interrupt mode.
 *   This file performs as mentioned below:
 *
 *      1. Configure UART using structure UART_Params where user can configure
 *         readmode writemode etc. different parameters.
 *      2. First call UART_init()
 *      3. Call UART_open with UART_Params structure to get UART instance handle.
 *      4. Then user is expected to input some data(can be upto max 1000 chars)
 *         and it is printed back on console using UART RTOS API's
 *         UART_read() and UART_write() respectively.
 *   Note
 *      1. The sample application is written for TDAXX EVM, DRA75X EVM and AM57XX.
 *      2. The UART instance used is UART1 for TDA2XX,AM57XX,DRA75X and
 *         UART3 for TDA3XX,DRA78X
 *
**/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/soc.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#if defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_DRA75x) || defined (SOC_AM572x) || defined (SOC_TDA2EX) || defined (SOC_AM571x)
#define UART_INSTANCE 0
#define XBAR_INST CSL_XBAR_INST_IPU1_IRQ_44
#define XBAR_IRQ CSL_XBAR_UART1_IRQ
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
#define UART_INSTANCE 2
#endif

/* ========================================================================== */
/*                          Internal Function Declarations                    */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
UART_Handle uart_handle;

/* UART parameters structure polled mode*/
const UART_Params user_params = {
    UART_MODE_BLOCKING,     /* readMode */
    UART_MODE_BLOCKING,     /* writeMode */
    SemaphoreP_WAIT_FOREVER,/* readTimeout */
    SemaphoreP_WAIT_FOREVER,/* writeTimeout */
    NULL,                  /* readCallback */
    NULL,                 /* writeCallback */
    UART_RETURN_NEWLINE,  /* readReturnMode */
    UART_DATA_TEXT,       /* readDataMode */
    UART_DATA_TEXT,       /* writeDataMode */
    UART_ECHO_ON,         /* readEcho */
    115200,               /* baudRate */
    UART_LEN_8,           /* dataLength */
    UART_STOP_ONE,        /* stopBits */
    UART_PAR_NONE         /* parityType */
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void padConfig_prcmEnable()
{
#if defined (SOC_AM572x) || defined (SOC_AM571x)
    /*Pad configurations */
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_UART1_RXD,0x00040000);
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_UART1_TXD,0x00000000);
#endif
#if defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_TDA2EX) || defined (SOC_DRA75x)
    /*Pad configurations */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_RXD,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_TXD,0x00000000);
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /*Pad configurations */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_SCLK,0x00040001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_CS0,0x00000001);
#endif
}

void uart_test(UArg arg0, UArg arg1)
{
    UART_Params      params;
    int32_t count;
    char input = '\n';
    char buffPointer[1000];
    char echoPrompt[] = "\nuart driver example test:\nEnter some data or press the esc \n";
    char echoPrompt1[] = "Data received is\n";

    padConfig_prcmEnable();
#if defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_DRA75x) || defined (SOC_AM572x) || defined (SOC_TDA2EX) || defined (SOC_AM571x)
    CSL_xbarIrqConfigure(CSL_XBAR_IRQ_CPU_ID_IPU1,XBAR_INST,XBAR_IRQ);
#endif

    UART_init();
    params = user_params;
    uart_handle = UART_open(UART_INSTANCE, &params);

    UART_write(uart_handle,echoPrompt,sizeof(echoPrompt));

    while(1)
       {
        count=UART_read(uart_handle,buffPointer,1000);
        UART_write(uart_handle,&input,1U);
        UART_write(uart_handle,echoPrompt1,sizeof(echoPrompt1));
        UART_write(uart_handle,buffPointer,count);
        UART_write(uart_handle,echoPrompt,sizeof(echoPrompt));
       }
}

int main(void)
{
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);

    task = Task_create(uart_test, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    /* Start BIOS */
    BIOS_start();
    return (0);
}
/********************************* End of file ******************************/
