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

/*
 * Redirect Unity output from stdout to the UART
 */

#ifndef UNITY_CONFIG_H
#define UNITY_CONFIG_H

#include <ti/drv/uart/UART.h>

/* Redefine Unity Output */
#define UNITY_OUTPUT_CHAR(a)    putChar_to_unityOutputBuffer(a)
#define UNITY_OUTPUT_CHAR_HEADER_DECLARATION    putChar_to_unityOutputBuffer(char)

/* Writes one char at a time to the buffer */
void putChar_to_unityOutputBuffer(char);

/*
 * Prints entire contents of the buffer
 * Choose UART or UART_stdio depending on how your project
 * is configured
 */
void print_unityOutputBuffer_usingUART(UART_Handle uart);
void print_unityOutputBuffer_usingUARTstdio(void);

/* Clears the buffer */
void clear_unity_output_buffer(void);

#endif
