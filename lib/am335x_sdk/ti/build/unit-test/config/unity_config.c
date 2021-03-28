/*
* Copyright (c) 2019, Texas Instruments Incorporated
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

#include "unity_config.h"
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <string.h>

/*
 * Buffer to store unity test results during tests.
 * Assuming the average test result is about 100 characters,
 * this should be enough for around 80 tests.
 */
#define UNITY_OUTPUT_BUFFER_LEN 8192
static char unity_output_buffer[UNITY_OUTPUT_BUFFER_LEN];
static uint32_t buff_index = 0;
static uint8_t overrun_flag = 0;
static const char overrun_msg[] = "\n\nERROR: Unity output buffer overrun.";

void clear_unity_output_buffer(void)
{
    memset(unity_output_buffer, '\0', UNITY_OUTPUT_BUFFER_LEN);
}

void putChar_to_unityOutputBuffer(char a)
{
    if(buff_index < UNITY_OUTPUT_BUFFER_LEN)
    {
        unity_output_buffer[buff_index] = a;
        buff_index++;
    }
    else
    {
        overrun_flag = 1;
    }
}

void print_unityOutputBuffer_usingUART(UART_Handle uart)
{
    UART_write(uart, unity_output_buffer, buff_index);
    clear_unity_output_buffer();
    buff_index = 0;
    if(overrun_flag)
    {
        UART_write(uart, overrun_msg, sizeof(overrun_msg));
    }
}

void print_unityOutputBuffer_usingUARTstdio(void)
{
    UART_puts(unity_output_buffer, buff_index);
    clear_unity_output_buffer();
    buff_index = 0;
    if(overrun_flag)
    {
        UART_puts(overrun_msg, sizeof(overrun_msg));
    }
}
