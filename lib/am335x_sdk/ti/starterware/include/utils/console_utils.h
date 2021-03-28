/**
 *  \file      console_utils.h
 *
 *  \brief     This file contains the prototypes of the generic Console
 *             utility functions defined in utils/console_utils.c which allow
 *             user to configure the console type and redirect the I/O
 *             operations to the selected console Type.
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

#ifndef CONSOLE_UTILS_H_
#define CONSOLE_UTILS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <types.h>
#include <misc.h>
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

/**
 *  \brief Enumerates the type of console interfaces.
 */
typedef enum
{
    CONSOLE_UTILS_TYPE_MIN,
    /**< First value of enumeration. Can be used used for validation. */
    CONSOLE_UTILS_TYPE_UART = CONSOLE_UTILS_TYPE_MIN,
    /**< UART console interface. */
    CONSOLE_UTILS_TYPE_DEBUGGER,
    /**< Debugger console interface. */
    CONSOLE_UTILS_TYPE_MAX
    /**< Invalid console interface. */
} consoleUtilsType_t;

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function initializes console for all Input/Output operations.
 *
 * \retval  S_PASS Success.
 * \retval  E_FAIL If an error occurred.
 */
int32_t CONSOLEUtilsInit(void);

/**
 * \brief   This function gives the current console type configuration.
 *
 * \retval  #consoleUtilsType_t  Returns the configured console type.
 */
consoleUtilsType_t CONSOLEUtilsGetType(void);

/**
 * \brief   This function sets up the console for use in all IO operations based
 *          on the option provided by the user.
 *
 * \details UART and Debugger consoles are supported. Debugger console has to be
 *          enabled defining compile time macro SEMIHOSTING else will return an
 *          error on configuring for debugger on runtime. UART console supports
 *          single byte characters only.
 *
 * \param   consoleFlag  Console type. Console type shall be any value from
 *                       #consoleUtilsType_t.
 *
 * \retval  S_PASS Success.
 * \retval  E_FAIL If an error occurred.
 */
int32_t CONSOLEUtilsSetType(consoleUtilsType_t consoleFlag);

/**
 * \brief   This function gets a character entered on console.
 *
 * \details UART and Debugger consoles are supported. Debugger console has to be
 *          enabled defining compile time macro SEMIHOSTING else will return an
 *          error on configuring for debugger on runtime. UART console supports
 *          single byte characters only.
 *
 * \retval  Character Returns the entered byte read from the selected console.
 * \retval  E_FAIL   If an error occurred.
 */
int32_t CONSOLEUtilsGetc(void);

/**
 * \brief   This function shall write a character to the console.
 *
 * \details This function shall write the byte specified character.
 *          UART and Debugger consoles are supported. Debugger console has to be
 *          enabled defining compile time macro SEMIHOSTING else will return an
 *          error on configuring for debugger on runtime. UART console supports
 *          single byte characters only.
 *
 * \param   character   The character to be printed.
 *
 * \retval  Value    Written on console.
 * \retval  E_FAIL  If an error occurred.
 */
int32_t CONSOLEUtilsPutc(int32_t character);

/**
 * \brief   This function gets a string of character entered on console.
 *
 * \details This function reads characters from console into the array rxBuffer
 *          until (size - 1) bytes or a newline is read. The string is terminated
 *          with a NULL character.
 *          UART and Debugger consoles are supported. Debugger console has to be
 *          enabled defining compile time macro SEMIHOSTING else will return an
 *          error on configuring for debugger on runtime. UART console supports
 *          single byte characters only.
 *
 * \param   pRxBuffer  Pointer to a buffer in the receiver.
 * \param   size      The number of bytes the receiver buffer can hold.
 *
 * \retval  pointer  to the buffer containing received data.
 * \retval  NULL     Error.
 */
uint8_t* CONSOLEUtilsGets(uint8_t *pRxBuffer, int32_t size);

/**
 * \brief   This function shall write the string on console.
 *
 * \details This function shall write the string pString followed by newline.
 *          Terminating NULL character shall not be written.
 *          UART and Debugger consoles are supported. Debugger console has to be
 *          enabled defining compile time macro SEMIHOSTING else will return an
 *          error on configuring for debugger on runtime. UART console supports
 *          single byte characters only.
 *
 * \param   pString  Pointer to a string to be printed on the console.
 *
 * \retval  S_PASS  Success.
 * \retval  E_FAIL  If an error occurred.
 */
int32_t CONSOLEUtilsPuts(const char *pString);

/**
 * \brief   This function shall write the formatted output on console.
 *
 * \details Format specifier follows %[fill][width]specifier.
 *          Following formatting specifier are supported.
 *          - %c to print a character.
 *          - %d to print a decimal value.
 *          - %s to print a string.
 *          - %u to print an unsigned decimal value.
 *          - %x, \%X to print a hexadecimal value using lower case letters.
 *          - %llu to print a unsigned long long variable
 *          - %p to print a pointer as a hexadecimal value.
 *          - %\% to print out a \% character.
 *          Width in number of characters to be printed. If the value to be
 *          printed is smaller than width, result is padded with fill character.
 *          Fill character ' ' and '0' are supported for all formats except \%c.
 *          UART and Debugger consoles are supported. Debugger console has to be
 *          enabled defining compile time macro SEMIHOSTING else will return an
 *          error on configuring for debugger on runtime. UART console supports
 *          single byte characters only.
 *
 * \param   pString is the format string.
 * \param   ... are the optional arguments, which depend on the contents of the
 *          format string. The type of the arguments after string must match the
 *          requirements of the format string otherwise behaviour is undefined.
 *
 * \retval  S_PASS  Number of bytes printed.
 * \retval  E_FAIL  If an error occurred.
 */
#ifndef DDRLESS
int32_t CONSOLEUtilsPrintf(const char *pString, ...);
#else
#define CONSOLEUtilsPrintf(x, ...)
#endif

/**
 * \brief   This API shall take formatted input from console.
 *
 * \details Format specifier follows %[width]specifier.
 *          Only the following formatting specifier are supported:
 *          - \%c to read a character.
 *          - \%d to read a decimal value.
 *          - \%s to read a string.
 *          - \%u to read an unsigned decimal value.
 *          - \%x, \%X to read a hexadecimal value using lower case letters.
 *          - \%p to read a pointer as a hexadecimal value.
 *          UART and Debugger consoles are supported. Debugger console has to be
 *          enabled defining compile time macro SEMIHOSTING else will return an
 *          error on configuring for debugger on runtime. UART console supports
 *          single byte characters only.
 *          The width option in the format specifier is not supported on UART
 *          console. So UART console will take input as much as supported by the
 *          data type. The size specification in format specifier will be treated
 *          as invalid specifier.
 *
 * \param   pFormat  Pointer to the format string.
 *
 * \retval  S_PASS  Input values successfully read from the console.
 * \retval  E_FAIL  If an error occurred.
 */
int32_t CONSOLEUtilsScanf(const char *pFormat, ...);

/**
 * \brief   This function gets given data type from UART in non-blocking mode.
 *
 * \details Only UART console is supported. On selecting debugger console an help
 *          info is provided asking user to enter input on UART console.
 *
 * \param   pRxConsoleBuf  Pointer to the buffer descriptor.
 * \param   pVar           Pointer to the variable.
 * \param   dataType       Data type of variable.
 * \param   pStatus        Status takes values from the following enum
 *                         consoleUtilsNonBlockingStatus_t.
 *                         To start fresh get operation pStatus has to be reset
 *                         to CONSOLE_UTILS_INPUTSTATUS_INIT by the caller.
 *                         CONSOLE_UTILS_INPUTSTATUS_MAX indicates end of
 *                         get operation.
 *
 * \retval  S_PASS
            - Read in progress if pStatus is CONSOLE_UTILS_INPUTSTATUS_READ.
 *          - Idle if pStatus is CONSOLE_UTILS_INPUTSTATUS_MAX.
 * \retval  E_FAIL  Failed to get data type.
 */
int32_t CONSOLEUtilsGetNonBlockingInput(consoleUtilsBuf_t *pRxConsoleBuf,
                                        void *pVar,
                                        uint32_t dataType,
                                        uint32_t *pStatus);

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */

/**
 * \brief   This function initializes the UART for use as the Console
 *          for all Input/Output operations.
 */
DEPRECATED(void ConsoleUtilsInit(void));

/**
 * \brief   This function sets up the console for use in all IO operations
 *          based on the option provided by the user.
 */
DEPRECATED(void ConsoleUtilsSetType(consoleUtilsType_t consoleFlag));

/**
 * \brief   This function is a wrapper for printf utility which prints
 *          the input string on the configured console type.
 */
DEPRECATED(void ConsoleUtilsPrintf(const char *string, ...));

/**
 * \brief   This function is a wrapper for scanf utility which reads
 *          the input according to the format specifier from the
 *          configured console type.
 */
DEPRECATED(int32_t ConsoleUtilsScanf(const char *format, ...));

/**
 * \brief  This function is a wrapper for Gets utility which reads
 *         a string from the configured console Type.
 */
DEPRECATED(char* ConsoleUtilsGets(char *rxBuffer, int32_t size));

/**
 * \brief  This function is a wrapper funcion to print a string to
 *         the console type configured.
 */
DEPRECATED(void ConsoleUtilsPuts(char *string));

/**
 * \brief   This function is a wrapper funcion to read a character from
 *          console type configured.
 */
DEPRECATED(uint8_t ConsoleUtilsGetChar(void));

/**
 * \brief   This function is a wrapper funcion to print a character to
 *          the console type configured.
 */
DEPRECATED(void ConsoleUtilsPutChar(uint8_t byte));

#ifdef __cplusplus
}
#endif

#endif /* #ifndef CONSOLE_UTILS_H_ */
