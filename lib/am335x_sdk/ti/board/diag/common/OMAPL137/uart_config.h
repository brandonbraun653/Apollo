/*
* Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/ 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**
 * \file  uart_config.h
 * 
 * \brief The macro definitions and function prototypes for 
 *        UART configurations
 *
 */
#ifndef _UART_CONFIG_H_
#define _UART_CONFIG_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdarg.h>
#include <ti/csl/csl_uart.h>
#include <ti/csl/src/ip/uart/V0/uart.h>
#include <ti/csl/soc.h>

/******************************************************************************
**                      MACRO DEFINITIONS
*******************************************************************************/
#define UART_WORD_LENGTH_8          (0x03)
#define BAUD_RATE_115200            (115200U)
#define UART_STOP_BIT_1             (0)
#define UART_MODULE_INPUT_CLK       (300000000/2)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
static const char *const g_pcHex = "0123456789abcdef";

/**
 * \brief   This function writes a byte on the serial console.
 *
 * \param   baseAddr    Base Address of UART instance.
 * \param   byteTx      The byte to be transmitted.
 *
 * \return  None.
 */
void UARTConfigPutc(uint32_t baseAddr, uint8_t byteTx);

/**
 * brief Writes a string of characters to the UART output.
 *
 * \param pcBuf points to a buffer containing the string to transmit.
 * \param len is the length of the string to transmit.
 *
 * This function will transmit the string to the UART output.  The number of
 * characters transmitted is determined by the \e len parameter.  This
 * function does no interpretation or translation of any characters.  Since
 * the output is sent to a UART, any LF (/n) characters encountered will be
 * replaced with a CRLF pair.
 *
 * Besides using the \e len parameter to stop transmitting the string, if a
 * null character (0) is encountered, then no more characters will be
 * transmitted and the function will return.
 *
 * In non-buffered mode, this function is blocking and will not return until
 * all the characters have been written to the output FIFO.  In buffered mode,
 * the characters are written to the UART transmit buffer and the call returns
 * immediately.  If insufficient space remains in the transmit buffer,
 * additional characters are discarded.
 *
 * \return Returns the count of characters written.
 */
int32_t UARTwrite(uint32_t baseAddr, const char *pcBuf, uint32_t len);

/**
 * \brief   A simple UART based printf function supporting \%c, \%d, \%p, \%s, \%u,
 *          \%x, and \%X.
 *
 * \param pcString is the format string.
 * \param ... are the optional arguments, which depend on the contents of the
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
 * \return None.
 */
void UARTConfigPrintf(uint32_t baseAddr, const char *pcString, ...);

/**
 * \brief   This function initializes the specified UART instance for use for
 *          console operations.
 *
 * \param   baseAddr    Base Address of UART instance.
 *
 * \return  None.
 *
 */
void UARTConfigInit(uint32_t baseAddr, uint32_t baudRate, uint32_t wordLength,
                    uint32_t stopBit, uint32_t parity, uint32_t mode);


#endif /* UART_CONFIG_H_ */
