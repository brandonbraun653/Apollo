/**
 *  \file  console_utils_uart.h
 *
 *  \brief This file provides structure, api, variable and macro required to
 *         use user interface example utils.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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
 *
 */

#ifndef CONSOLE_UTILS_UART_H_
#define CONSOLE_UTILS_UART_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "uart.h"
#include "console_utils_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function initializes the specified UART instance of use for
 *          console operations.
 *
 * \retval  #S_PASS Success.
 * \retval  #E_FAIL If an error occurred.
 *
 * \note    TODO: This function to be changed for soc, board data.
 */
int32_t CONSOLEUtilsUartInit(void);

/**
 * \brief   This function reads a single byte character entered on UART console.
 *
 * \retval  Returns the entered byte read from the selected console.
 * \retval  #E_FAIL If an error occurred.
 */
int32_t CONSOLEUtilsUartGetChar(void);

/**
 * \brief   This function writes a byte on the serial console.
 *
 * \param   byteTx   The byte to be transmitted.
 *
 * \retval  Value   Written on console.
 * \retval  #E_FAIL If an error occurred.
 */
int32_t CONSOLEUtilsUartPutChar(int32_t character);

/**
 * \brief   This function reads data from UART and stores them in buffer.
 *
 * \details Reads data from UART till any of the termination condition is reached.
 *          - carriage return.
 *          - until (numBytesToRead - 1) characters have been read.
 *
 * \param   pRxBuffer       Pointer to a buffer in the receiver.
 * \param   numBytesToRead  The number of bytes the receiver buffer can hold,
 *                          including the terminating null character at end
 *                          of the string. 0 is not a valid entry.
 *
 * \retval  pointer to the buffer containing received data.
 * \retval  NULL on error.
 */
uint8_t *CONSOLEUtilsUartGetStr(uint8_t *pRxBuffer, uint32_t numBytesToRead);

/**
 * \brief   This function writes data from a specified buffer onto transmitter
 *          FIFO of UART till a newline character.
 *
 * \param   pTxBuffer  Pointer to a buffer in the transmitter.
 *
 * \retval  #S_PASS Success.
 * \retval  #E_FAIL If an error occurred.
 */
int32_t CONSOLEUtilsUartPutStr(const char *pTxBuffer);

/**
 * \brief   This function shall write the formatted output on UART console.
 *
 * \detail  Format specifier follows %[fill][width]specifier
 *          Following formatting specifier are supported.
 *          - %c to print a character.
 *          - %f to print a float/double value.
 *          Float or Double can used with the format of %f or %16.11f(example)
 *          default precision for %f is 6 digits after decimal.
 *          %16.11f contains 16 as total width and 11 digits after
 *          decimal value.
 *          - %d to print a decimal value.
 *          - %s to print a string.
 *          - %u to print an unsigned decimal value.
 *          - %x, \%X to print a hexadecimal value using lower case letters.
 *          - %p to print a pointer as a hexadecimal value.
 *          - %\% to print out a \% character.
 *          Width in number of characters to be printed. If the value to be
 *          printed is smaller than width, result is padded with fill character.
 *          Fill character ' ' and '0' are supported for all formats except \%c.
 *
 * \param   pFormat  Pointer to the format string.
 * \param   vaArg    Variables arguments list.
 *
 * \retval  #S_PASS  Sucessfully executed.
 * \retval  #E_FAIL  If an error occurred.
 */
int32_t CONSOLEUtilsUartPrintFmt(const char *pFormat, va_list vaArg);

/**
 * \brief   A function takes formatted input from UART console.
 *
 * \detail  This function is very similar to the C library vscanf() function.
 *          All of its input will be read from the UART console. The input
 *          characters are stored into locations pointed by pointer arguments.
 *          The destination address pointed to by the pointers is not validated.
 *          Only the following formatting characters are supported:
 *          - \%c to read a character.
 *          - \%d to read a decimal value.
 *          - \%s to read a string.
 *          - \%u to read an unsigned decimal value.
 *          - \%x, \%X to read a hexadecimal value using lower case letters.
 *          - \%p to read a pointer as a hexadecimal value.
 *          White space charaters (' ', '\t') act as delimeters.
 *          Newline, carriage return and size of input buffer used to read used
 *          input (#CONSOLE_UTILS_INPUT_SIZE_MAX) are termination conditions.
 *          The width option in the format specifier is not supported. So this
 *          function will take input as much as supported by the data type. The
 *          size specification in the format specifier will be treated as
 *          invalid specifier.
 *
 * \param   pFormat  Pointer to the format string.
 * \param   vaArg    Variables arguments list.
 *
 * \retval  #S_PASS Input values successfully read from the uart console.
 * \retval  #E_FAIL If an error occurred. Following are possible error cases.
 *                  - Entered input is not of required type.
 *                  - Not recieved input for all parameters.
 */
int32_t CONSOLEUtilsUartScanFmt(const char *pFormat, va_list vaArg);

/**
 * \brief   This function gets given data type from UART in non-blocking mode.
 *
 * \details On initialization clears the buffer. Reads UART input in non-blocking
 *          mode with #CONSOLEUtilsUartReadNonBlockingInput. On successfully read
 *          #CONSOLEUtilsUartDecode converts the input to given data type.
 *
 * \param   pRxConsoleBuf  Pointer to the buffer descriptor.
 * \param   pVar           Pointer to the variable.
 * \param   dataType       Data type of variable.
 * \param   pStatus        Status takes #consoleUtilsNonBlockingStatus_t values.
 *                         To start fresh get operation pStatus has to be reset
 *                         to #UARTCONSOLEUTILS_INPUTSTATUS_INIT by the caller.
 *                         #UARTCONSOLEUTILS_INPUTSTATUS_MAX indicates end of
 *                         get operation.
 *
 * \retval  #S_PASS
            - Read in progress if pStatus is #UARTCONSOLEUTILS_INPUTSTATUS_READ.
 *          - Idle if pStatus is #UARTCONSOLEUTILS_INPUTSTATUS_MAX.
 * \retval  #E_FAIL - Failed to get data type.
 * \retval  #E_INVALID_PARAM - Invalid input parameter.
 */
int32_t CONSOLEUtilsUartGetNonBlockingInput(consoleUtilsBuf_t *pRxConsoleBuf,
                                            void *pVar,
                                            uint32_t dataType,
                                            uint32_t *pStatus);

/**
 * \brief   This function reads given data type from UART in blocking mode.
 *
 * \param   pRxConsoleBuf  Pointer to the buffer descriptor.
 * \param   pVar           Pointer to the variable.
 * \param   dataType       Data type of variable.
 *
 * \return  Status. Takes following values.
 *          #S_PASS - Successfully extracted variable from input.
 *          #E_FAIL - Failed to read data type.
 */
int32_t CONSOLEUtilsUartGetBlockingInput(consoleUtilsBuf_t *pRxConsoleBuf,
                                         void *pVar,
                                         uint32_t dataType);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef CONSOLE_UTILS_UART_H_ */
