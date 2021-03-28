/**
 * @file   UART_stdio.h
 *
 * @brief  This header file contains function prototypes which interface
 *         interactively with the user through the serial console to perform
 *         some utility operations.
 */
/*
 * Copyright (c) 2014-2015, Texas Instruments Incorporated
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

#ifndef UARTSTDIO_H_
#define UARTSTDIO_H_

#include <stdint.h>
#include <stdarg.h>

#include <ti/drv/uart/UART.h>
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
**                    MACRO DEFINITIONS
****************************************************************************/

#ifndef E_PASS
#define E_PASS    ((int32_t)(0))
#endif
#ifndef E_FAIL
#define E_FAIL    (-((int32_t)1))
#endif

#define S_PASS                  (0)
/****************************************************************************
**                    FUNCTION PROTOTYPES
****************************************************************************/

/**
 * @brief  This function writes data from a specified buffer onto the
 *         transmitter FIFO of UART.
 *
 * @param  pTxBuffer        Pointer to a buffer in the transmitter.
 * @param  numBytesToWrite  Number of bytes to be transmitted to the
 *                          transmitter FIFO. The user has the freedom to not
 *                          specify any valid value for this if he wants to
 *                          print until the occurence of a NULL character.
 *                          In this case, he has to pass a negative value as
 *                          this parameter.
 *
 * @return  Number of bytes written to the transmitter FIFO.
 *
 * @note   1> Whenever a null character(\\0) is encountered in the
 *            data to be transmitted, the transmission is stopped. \n
 *         2> - Whenever the transmitter data has a new line character(\\n),
 *            it is interpreted as a new line(\\n) + carraige return(\\r)
 *            characters. This is because the serial console interprets a
 *            new line character as it is and does not introduce a carraige
 *            return. \n
 *
 *         Some example function calls of this function are: \n
 *
 *         UARTPuts(txArray, -2): This shall print the contents of txArray[]
 *         until the occurence of a NULL character. \n
 *
 *         UARTPuts("Hello World", 8): This shall print the first 8 characters
 *         of the string shown. \n
 *
 *         UARTPuts("Hello World", 20): This shall print the string shown until
 *         the occurence of the NULL character. Here, the NULL character is
 *         encountered earlier than the length of 20 bytes.\n
 *
 */
uint32_t UART_puts(const char *pTxBuffer, int32_t numBytesToWrite);

/**
 * @brief  This function reads data from the receiver FIFO to a buffer
 *         in the receiver.
 *
 * @param  pRxBuffer        Pointer to a buffer in the receiver.
 * @param  numBytesToRead   The number of bytes the receiver buffer can hold.
 *                          However, if the user wishes not to specify this
 *                          parameter, he has freedom to do so. In that case,
 *                          the user has to pass a negative value for this
 *                          parameter.
 *
 * @return  Number of bytes read from the receiver FIFO.
 *
 * @note   The two exit points for this function are:
 *         1> To enter an ESC character or a carraige return character('Enter'
 *            key on the Keyboard).\n
 *         2> Specify a limit to the number of bytes to be read. \n
 *
 *         Some example function calls of this function are:
 *
 *         UARTGets(rxBuffer, -2): This reads characters from
 *         the receiver FIFO of UART until the occurence of a carriage return
 *         ('Enter' key on the keyboard pressed) or an ESC character.
 *
 *         UARTGets(rxBuffer, 12): This reads characters until
 *         12 characters have been read or until an occurence of a carriage
 *         return or an ESC character, whichever occurs first.
 */
uint32_t UART_gets(char *pRxBuffer, int32_t numBytesToRead);


/**
 * Writes a string of characters to the UART output.
 *
 * @param pcBuf points to a buffer containing the string to transmit.
 * @param ulLen is the length of the string to transmit.
 *
 * This function will transmit the string to the UART output.  The number of
 * characters transmitted is determined by the \e ulLen parameter.  This
 * function does no interpretation or translation of any characters.  Since
 * the output is sent to a UART, any LF (/n) characters encountered will be
 * replaced with a CRLF pair.
 *
 * Besides using the \e ulLen parameter to stop transmitting the string, if a
 * null character (0) is encountered, then no more characters will be
 * transmitted and the function will return.
 *
 * In non-buffered mode, this function is blocking and will not return until
 * all the characters have been written to the output FIFO.  In buffered mode,
 * the characters are written to the UART transmit buffer and the call returns
 * immediately.  If insufficient space remains in the transmit buffer,
 * additional characters are discarded.
 *
 * @return Returns the count of characters written.
 */
int32_t UART_dataWrite(const char *pcBuf, uint32_t ulLen);

/**
 * A simple UART based printf function supporting \%c, \%d, \%p, \%s, \%u,
 * \%x, and \%X.
 *
 * @param pcString is the format string.
 * @param ... are the optional arguments, which depend on the contents of the
 * format string.
 *
 * This function is very similar to the C library <tt>fprintf()</tt> function.
 * All of its output will be sent to the UART.  Only the following formatting
 * characters are supported:
 *
 * - \%c to print a character
 * - \%d to print a decimal value
 * - \%s to print a string
 * - \%u to print an unsigned decimal value
 * - \%x to print a hexadecimal value using lower case letters
 * - \%X to print a hexadecimal value using lower case letters (not upper case
 * letters as would typically be used)
 * - \%p to print a pointer as a hexadecimal value
 * - \%\% to print out a \% character
 *
 * For \%s, \%d, \%u, \%p, \%x, and \%X, an optional number may reside
 * between the \% and the format character, which specifies the minimum number
 * of characters to use for that value; if preceded by a 0 then the extra
 * characters will be filled with zeros instead of spaces.  For example,
 * ``\%8d'' will use eight characters to print the decimal value with spaces
 * added to reach eight; ``\%08d'' will use eight characters as well but will
 * add zeroes instead of spaces.
 *
 * The type of the arguments after \e pcString must match the requirements of
 * the format string.  For example, if an integer was passed where a string
 * was expected, an error of some kind will most likely occur.
 *
 * @return None.
 */
void UART_printf(const char *pcString, ...);

void UART_putc(uint8_t byteTx);


uint8_t UART_getc(void);

/**
 * @brief   This function initializes the specified UART instance for use for
 *          console operations , with a configuration specified by 'uartParams'
 *
 * @param   instance - uart instance ID.
 *
 * @param   uartParams - Configuration parameters.
 *
 * @return  None.
 *
 */
void UART_stdioInit2(uint32_t instance,UART_Params *uartParams);

/**
 * @brief   This function initializes the specified UART instance for use for
 *          console operations.
 *
 * @param   value - the UART instance number
 * 
 * @return  None.
 *
 */
void UART_stdioInit(uint32_t value);


/**
 * @brief   This function shall read the formatted input from UART console.
 *          Format specifier follows %[fill][width]specifier
 *          Following formatting specifier are supported.
 *          - %c to input a character.
 *          - %d to input a decimal value.
 *          - %s to input a string.
 *          - %u to input an unsigned decimal value.
 *          - %x, \%X to input a hexadecimal value using lower case letters.
 *          - %p to input a pointer as a hexadecimal value.
 *
 * @param   pString  Pointer to the format string.
 *
 * @retval   S_PASS  Sucessfully executed.
 * @retval   E_FAIL  If an error occurred.
 */
int32_t UART_scanFmt(const char *pString, ...);

/**
 * @brief   This function de-initializes the UART instance
 *          that is opened for console operations.
 *
 * @return  None.
 *
 */
void UART_stdioDeInit(void);

/**
 * @brief   This function prints the status on the UART instance
 *          that is opened for console operations.
 *
 * @param   statusString  - string pointer.
 *
 * @return  None.
 *
 */
void UART_printStatus(const char *statusString);

#ifdef __cplusplus
}
#endif
#endif
