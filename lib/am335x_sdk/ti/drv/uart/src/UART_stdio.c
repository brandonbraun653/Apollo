/**
 * @file   UART_stdio.c
 *
 * @brief  This file contains functions which interface interactively
 *         with the user through the serial console to perform some
 *         utility operations.
 */
/*
 * Copyright (c) 2014-2016, Texas Instruments Incorporated
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

#include "stdint.h"
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <stdarg.h>
#include <ti/drv/uart/src/UART_utils_defs.h>
#include <ti/drv/uart/src/UART_ascii_utils.h>
/* A mapping from an integer between 0 and 15 to its ASCII character
 * equivalent. */

static void uart_console_putc(uint8_t data);
static uint8_t uart_console_getc(void);
static const char *const g_pcHex = "0123456789abcdef";
static int32_t UART_blockingRead(const UART_UtilsBuf_t *pRxConsoleBuf);
static int32_t UART_decode(const UART_UtilsBuf_t *pRxConsoleBuf,
                               void *pVar,
                               uint32_t dataType);
void UART_putNum(int32_t value);
void UART_putHexNum(uint32_t hexValue);
uint32_t UART_getNum(void);
uint32_t UART_getHexNum(void);

extern UART_Config UART_config[];
/*!
 *  @brief      UART_Stdio_Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct UART_Stdio_Object_s
{
    /* UART stdio control variables */
    UART_Handle  uart_handle;  /* UART stdio instance handle */
    void        *sem;          /* UART stdio semaphore */
}UART_Stdio_Object;

UART_Stdio_Object uart_stdio = {NULL, NULL};

/****************************************************************************
**                    EXTERNAL FUNCTION DECLARATIONS
****************************************************************************/
/*****************************************************************************
**                    FUNCTION DEFINITIONS
*****************************************************************************/

/**
 * \brief   This function initializes the specified UART instance for use for
 *          console operations, based on a configuration parameters specified.
 *
 * \param   value instance ID.
 *
 * \param   UART parameters to be used for this instance
 * 
* \return  None.
 *
 */

void UART_stdioInit2(uint32_t instance,UART_Params *params)
{
    SemaphoreP_Params   semParams;
    char                semName[] = "uartStdio";

    if(uart_stdio.uart_handle==NULL) 
    {
      UART_init();
      /* The params is assumed to have been initialized prior to this */
      uart_stdio.uart_handle = UART_open(instance,params);
      /*
       * Construct thread safe semaphore for UART_printf
      */
     UART_osalSemParamsInit(&semParams);
     semParams.mode = SemaphoreP_Mode_BINARY;
     semParams.name = semName;
     uart_stdio.sem = UART_osalCreateBlockingLock(1U, &semParams);
   }
}

/*****************************************************************************
**                    FUNCTION DEFINITIONS
*****************************************************************************/

/**
 * \brief   This function initializes the specified UART instance for use for
 *          console operations.
 *
 * \param   value instance ID.
 *
 * \return  None.
 *
 */

void UART_stdioInit(uint32_t value)
{
    UART_Params         params;
    SemaphoreP_Params   semParams;
    char                semName[] = "uartStdio";

    if(uart_stdio.uart_handle==NULL) 
    {
      UART_init();

      UART_Params_init(&params);
      uart_stdio.uart_handle = UART_open(value, &params);

      /*
       * Construct thread safe semaphore for UART_printf
      */
      UART_osalSemParamsInit(&semParams);
      semParams.mode = SemaphoreP_Mode_BINARY;
      semParams.name = semName;
      uart_stdio.sem = UART_osalCreateBlockingLock(1U, &semParams);
    }
}

/**
 * \brief  This function writes data from a specified buffer onto the
 *         transmitter FIFO of UART.
 *
 * \param  pTxBuffer        Pointer to a buffer in the transmitter.
 * \param  numBytesToWrite  Number of bytes to be transmitted to the
 *                          transmitter FIFO. The user has the freedom to not
 *                          specify any valid value for this if he wants to
 *                          print until the occurence of a NULL character.
 *                          In this case, he has to pass a negative value as
 *                          this parameter.
 *
 * \return  Number of bytes written to the transmitter FIFO.
 *
 * \note   1> Whenever a null character(\0) is encountered in the
 *            data to be transmitted, the transmission is stopped. \n
 *         2> Whenever the transmitter data has a new line character(\n),
 *            it is interpreted as a new line(\n) + carraige return()
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
uint32_t UART_puts(const char *pTxBuffer, int32_t numBytesToWrite)
{
    uint32_t count = 0;
    uint32_t flag  = 0;
    const char *bufPtr = pTxBuffer;

    if (numBytesToWrite < 0)
    {
        flag = 1U;
    }

    while ((char) '\0' != *bufPtr)
    {
        /* Checks if data is a newline character. */
        if ((char) '\n' == *bufPtr)
        {
            /* Ensuring applicability to serial console.*/
            UART_putc(((uint8_t)('\r')));
            UART_putc(((uint8_t)('\n')));
        }
        else
        {
            UART_putc((uint8_t) *bufPtr);
        }
        bufPtr++;
        count++;
        if ((0U == flag) && (((int32_t)(count)) == numBytesToWrite))
        {
            break;
        }
    }
    /* Returns the number of bytes written onto the transmitter FIFO. */
    return count;
}

/**
 * \brief  This function reads data from the receiver FIFO to a buffer
 *         in the receiver.
 *
 * \param  pRxBuffer        Pointer to a buffer in the receiver.
 * \param  numBytesToRead   The number of bytes the receiver buffer can hold.
 *                          However, if the user wishes not to specify this
 *                          parameter, he has freedom to do so. In that case,
 *                          the user has to pass a negative value for this
 *                          parameter.
 *
 * \return  Number of bytes read from the receiver FIFO.
 *
 * \note   The two exit points for this function are:
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

uint32_t UART_gets(char *pRxBuffer, int32_t numBytesToRead)
{
    uint32_t  count = 0;
    uint32_t flag  = 0;
    char *bufPtr = pRxBuffer;

    if (numBytesToRead < 0)
    {
        flag = 1U;
    }
    do
    {
        *bufPtr = (char) UART_getc();

        /* Echoing the typed character back to the serial console. */
        UART_putc((uint8_t) *bufPtr);

        /*
        ** 0xD - ASCII value of Carriage Return.
        ** 0xA - ASCII value of Linefeed.
        ** 0x1B - ASCII value of ESC character.
        */
        if (((char)0xA == *bufPtr) || ((char)0x1B == *bufPtr) || ((char)0xD == *bufPtr))
        {
            *bufPtr = (char) '\0';
            break;
        }

        bufPtr++;
        count++;

    } while (!((0U == flag) && (((int32_t)(count)) == numBytesToRead)));

    return count;
}

/**
 *  \brief   This function prints the specified numbers(positive or negative)
 *           on the serial console.
 *
 *  \param   value     The number to be printed on the serial console.
 *
 *  \return  None.
 *
 *  \note    The numbers that this function can print should lie in the
 *           following range:
 *           [-2^(31)] to [2^(31) - 1] i.e.
 *           0x80000000 to  0x7FFFFFFF
 *
 */

void UART_putNum(int32_t value)
{
    char     num[10]  = {0};
    uint32_t quotient = 0;
    uint32_t dividend = 0;
    uint32_t mod_val  = 0;
    int32_t  count    = 0;
    int32_t  val      = value;

    if (val < 0)
    {
        UART_putc(((uint8_t)('-')));
        /*
        ** Making the negative number as positive.
        ** This is done to simplify further processing and printing.
        */
        val = -val;
    }

    dividend = (uint32_t)val;
    do
    {
        quotient   = dividend / 10U;
        mod_val    = dividend % 10U;
        num[count] = (char) (mod_val);
        if (0U == quotient)
        {
            break;
        }
        count++;
        dividend = quotient;
    } while (count < 10);

    /* Avoid warning for overflow.  Can't actually happen since 10 digits 
     * is sufficent to print any 32-bit number */
    if(count == 10)
    {
        count--;
    }


    /* Printing the digits. */
    do
    {
        /* We add 0x30 to a digit to obtain its respective ASCII value.*/
        UART_putc((uint8_t)num[count] + (uint8_t)0x30U);
        count--;
    } while (count >= 0);
}

/**
 * \brief  This function is used to print hexadecimal numbers on the serial
 *         console.
 *
 * \param  hexValue   The Hexadecimal number to be printed.
 *
 * \return None
 */

void UART_putHexNum(uint32_t hexValue)
{
    uint8_t  num[8]   = {0};
    uint32_t quotient = 0;
    uint32_t dividend = 0;
    uint32_t mod_val  = 0;
    int32_t  count    = 0;

    dividend = hexValue;

    do
    {
        quotient   = dividend / 16U;
        mod_val = dividend % 10U;
        num[count] = (uint8_t) (mod_val);
        if (0U == quotient)
        {
            break;
        }
        count++;
        dividend = quotient;
    } while (count < 8);

    if(count == 8)
    {
        count--;
    }
    UART_putc(((uint8_t)('0')));
    UART_putc(((uint8_t)('x')));

    while (count >= 0)
    {
        /* Checking for alphanumeric numbers. */
        if (((uint8_t)16U - num[count]) <= (uint8_t)6U)
        {
            /* Printing alphanumeric numbers. */
            UART_putc(num[count] + 0x37U);
            count--;
        }
        else
        {
            /* Printing numbers in the range 0 to 9. */
            UART_putc(num[count] + 0x30U);
            count--;
        }
    }
}

/**
 * \brief   This function reads the numbers typed on the serial console.
 *
 * \return  The value entered on the serial console.
 *
 * \note   The numbers that this function can recieve should lie in the
 *          following range:
 *          [-2^(31)] to [2^(31) - 1] i.e.
 *          0x80000000 to  0x7FFFFFFF
 *
 */

uint32_t UART_getNum(void)
{
    char    rxByte;
    int32_t sign  = 1;
    uint32_t value = 0;

    rxByte = (char) UART_getc();

    /* Accounting for negative numbers.*/
    if ((int8_t) '-' == ((int8_t)(rxByte)))
    {
        UART_putc(((uint8_t)('-')));
        sign = (-((int32_t)1));
    }
    else
    {
        UART_putc((uint8_t) rxByte);
        value = (value * 10U) + (((uint32_t)(rxByte)) - 0x30U);
    }

    do
    {
        rxByte = (char) UART_getc();

        /* Echoing the typed characters to the serial console.*/
        UART_putc((uint8_t) rxByte);
        /*
        ** Checking if the entered character is a carriage return.
        ** Pressing the 'Enter' key on the keyboard executes a
        ** carriage return on the serial console.
        */
        if ((int8_t) '\r' == ((int8_t)(rxByte)))
        {
            break;
        }
        /*
        ** Subtracting 0x30 to convert the representation of the digit
        ** from ASCII to hexadecimal.
        */
        value = (value * 10U) + (((uint32_t)(rxByte)) - 0x30U);
    } while (true == true);

    /* Accounting for the sign of the number.*/
    value = value * ((uint32_t)(sign));

    return value;
}

/**
 * \brief   This function receives hexadecimal numbers entered on the serial
 *          console of the host machine.
 *
 *
 * \return  The hexadecimal number entered on the serial console of the host
 *          machine.
 *
 * \note    1> The points below explain the ways of entering hexadecimal
 *             numbers:\n
 *             - 0xABCDEF12 - Hexadecimal number preceded by a '0x'.\n
 *             - 0XABCDEF12 - Hexadecimal number preceded by a '0X'.\n
 *             - 0xabcdef12 - Lower-case alphanumeric numbers are allowed.\n
 *             - 0xaBcDeF12 - Intermixing of lower-case and upper-case
 *                            alphanumeric numbers is allowed.\n
 *             - abcdef12   - A preceding '0x' or '0X' is not requried.
 *                            The entered number shall be treated as a
 *                            hexadecimal number.\n
 *             - 12345678   - Interpreted as 0x12345678 and not decimal
 *                            12345678.\n
 *             - xABCDEF12  - A preceding '0' is not required.\n
 *          2> This function does not take into consideration any character
 *             other than a hexadecimal character after reception.\n
 *             Example: Characters in the range G,H,I,...Z or g,h,...,z
 *             are not taken into consideration.\n
 *          3> The maximum value that can be returned by this function
 *             is 0xFFFFFFFF. The reception exits after eight characters have
 *             been received.\n
 *          4> To input a  number lesser that eight characters (Ex: 0x1AB),
 *             press the 'Enter' key after entering the number.\n
 */

uint32_t UART_getHexNum(void)
{
    char     rxByte;
    uint32_t value = 0;
    uint32_t loopIndex;
    uint32_t byteCount = 0;
    uint8_t ret_flag = 0U;

    for (loopIndex = 0u; loopIndex < 2u; loopIndex++)
    {
        /* Receiving bytes from the host machine through serial console. */
        rxByte = (char) UART_getc();

        /*
        ** Checking if the entered character is a carriage return.
        ** Pressing the 'Enter' key on the keyboard executes a
        ** carriage return on the serial console.
        */
        if ((int8_t) '\r' == ((int8_t)(rxByte)))
        {
            ret_flag = 1U;
        }

        /*
        ** Checking if the character entered is one among the alphanumeric
        ** character set A,B,C...F
        */
        else
        {
            if (((int8_t) 'A' <= ((int8_t)(rxByte))) && (((int8_t)(rxByte)) <= (int8_t) 'F'))
            {
                /* Echoing the typed characters to the serial console.*/
                UART_putc((uint8_t) rxByte);
                value = (value * 16u) + (((uint32_t)(rxByte)) - 0x37u);
                byteCount++;
            }
            /*
            ** Checking if the character entered is one among the alphanumeric
            ** character set a,b,c...f
            */
            else if (((int8_t) 'a' <= ((int8_t)(rxByte))) && (((int8_t)(rxByte)) <= (int8_t) 'f'))
            {
                UART_putc((uint8_t) rxByte);
                value = (value * 16u) + (((uint32_t)(rxByte)) - 0x57u);
                byteCount++;
            }
            /*
            ** Checking if the character entered is one among the decimal
            ** number set 0,1,2,3,....9
            */
            else if (((int8_t) '0' <= ((int8_t)(rxByte))) && (((int8_t)(rxByte)) <= (int8_t) '9'))
            {
                UART_putc((uint8_t) rxByte);
                value = (value * 16u) + (((uint32_t)(rxByte)) - 0x30u);
                byteCount++;
            }
            /*
            ** Checking if the character is either a 'x'(lower-case) or an 'X'
            ** (upper-case).
            */
            else if (((int8_t) 'x' == ((int8_t)(rxByte))) || ((int8_t) 'X' == ((int8_t)(rxByte))))
            {
                UART_putc((uint8_t) rxByte);
                value = 0;
                ret_flag = 1U;
            }
            else 
            {
                /*   Dummy statement for handling MISRA.IF.NO_ELSE warning  */
                ret_flag = 0U;
            }
        }

	      if(ret_flag == 1U)
        {
            break;
        }
    }

    if (0u == value)
    {
        byteCount = 0;
    }

    do
    {
        rxByte = (char) UART_getc();

        if ((int8_t) '\r' == ((int8_t)(rxByte)))
        {
            break;
        }

        /*
        ** Checking if the character entered is one among the alphanumeric
        ** character set A,B,C...F
        */
        if (((int8_t) 'A' <= ((int8_t)(rxByte))) && (((int8_t)(rxByte)) <= (int8_t) 'F'))
        {
            UART_putc((uint8_t) rxByte);
            value = (value * 16u) + (((uint32_t)(rxByte)) - 0x37u);
            byteCount++;
        }
        /*
        ** Checking if the character entered is one among the alphanumeric
        ** character set a,b,c...f
        */
        else if (((int8_t) 'a' <= ((int8_t)(rxByte))) && (((int8_t)(rxByte)) <= (int8_t) 'f'))
        {
            UART_putc((uint8_t) rxByte);
            value = (value * 16u) + (((uint32_t)(rxByte)) - 0x57u);
            byteCount++;
        }
        /*
        ** Checking if the character entered is one among the decimal
        ** number set 0,1,2,3,....9
        */
        else if (((int8_t) '0' <= ((int8_t)(rxByte))) && (((int8_t)(rxByte)) <= (int8_t) '9'))
        {
            UART_putc((uint8_t) rxByte);
            value = (value * 16u) + (((uint32_t)(rxByte)) - 0x30u);
            byteCount++;
        }
        /*
        ** Not receiving any other character other than the one belonging
        ** to the above three categories.
        */
        else
        {
            /* Intentionally left empty. */
        }
    } while (byteCount < 8u);
    return value;
}

/**
 * \brief   This function writes a byte on the serial console.
 *
 * \param   byteTx   The byte to be transmitted.
 *
 * \return  None.
 */

void UART_putc(uint8_t byteTx)
{
    uart_console_putc(byteTx);
}

/**
 * \brief   This function reads a byte entered on the serial console.
 *
 * \return  Returns the entered byte typecasted as an unsigned character.
 */

uint8_t UART_getc(void)
{
    return (uart_console_getc());
}

/**
 * Writes a string of characters to the UART output.
 *
 * \param pcBuf points to a buffer containing the string to transmit.
 * \param ulLen is the length of the string to transmit.
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
 * \return Returns the count of characters written.
 */
int32_t UART_dataWrite(const char *pcBuf, uint32_t ulLen)
{
    uint32_t uIdx;

    /* Send the characters */
    for (uIdx = 0; uIdx < ulLen; uIdx++)
    {
        /* If the character to the UART is \n, then add a \r before it so that
         * \n is translated to \n\r in the output. */
        if (pcBuf[uIdx] == (char) '\n')
        {
            UART_putc(((uint8_t)('\r')));
        }

        /* Send the character to the UART output. */
        UART_putc((uint8_t)pcBuf[uIdx]);
    }

    /* Return the number of characters written. */
    return ((int32_t)uIdx);
}

/**
 * \brief   This function calls to the common procedure in 
 *          uart printf. This functions writes the output in
 *          required format i.e. float, int, char etc.
 *
 * \param   ulValue The value of the resolved variable passed 
                    as argument
 *          ulPos   The buffer position of the printed value
 *          ulBase  The number is decimal, hex or binary
 *          ulNeg   The value is negative or not
 *          ulCount Total number of character to be printed
 *          cFill   The char to be placed between number
 *          pcBuf   buffer storing all the numbers
 *
 * \return  0.
 *
 */
static int32_t UART_convertVal(uint32_t ulValue, uint32_t ulPos, uint32_t ulBase, uint32_t ulNeg, uint32_t ulCount, char cFill, char *pcBuf);
static int32_t UART_convertVal(uint32_t ulValue, uint32_t ulPos, uint32_t ulBase, uint32_t ulNeg, uint32_t ulCount, char cFill, char *pcBuf)
{
    uint32_t ulIdx;
    uint32_t count = ulCount;
    uint32_t neg = ulNeg;
    uint32_t pos = ulPos;

    for (ulIdx = 1u;
         (((ulIdx * ulBase) <= ulValue) &&
          (((ulIdx * ulBase) / ulBase) == ulIdx));
         (ulIdx = (ulIdx * ulBase)))
    {
        count--;
    }

    /* If the value is negative, reduce the count of padding
     * characters needed. */
    if (neg != 0U)
    {
        count--;
    }

    /* If the value is negative and the value is padded with
     * zeros, then place the minus sign before the padding. */
    if ((neg != 0U) && ((int8_t)cFill == (int8_t) '0'))
    {
        /* Place the minus sign in the output buffer. */
        pcBuf[pos] = (char) '-';
        pos++;

        /* The minus sign has been placed, so turn off the
         * negative flag. */
        neg = 0;
    }

    /* Provide additional padding at the beginning of the
     * string conversion if needed. */
    if ((count > 1u) && (count < 16u))
    {
        for (count--; count != 0U; count--)
        {
            pcBuf[pos] = cFill;
            pos++;
        }
    }

    /* If the value is negative, then place the minus sign
     * before the number. */
    if (neg != 0U)
    {
        /* Place the minus sign in the output buffer. */
        pcBuf[pos] = (char) '-';
        pos++;
    }

    /* Convert the value into a string. */
    for (; ulIdx != 0U; ulIdx /= ulBase)
    {
        pcBuf[pos] = g_pcHex[(ulValue / ulIdx) % ulBase];
        pos++;
    }

    /* Write the string. */
    (void)UART_dataWrite(pcBuf, pos);

    return 0;
}

/**
 * A simple UART based printf function supporting \%c, \%d, \%p, \%s, \%u,
 * \%x, and \%X.
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
void UART_printf(const char *pcString, ...)
{
    uint32_t ulIdx, ulValue, ulPos, ulCount, ulBase, ulNeg;
    char    *pcStr, pcBuf[16], cFill;
    va_list  vaArgP;
    int32_t temp_var = 0;
    Osal_ThreadType threadType = UART_osalGetThreadType();
    const char *pStr = pcString;

    if ((threadType != Osal_ThreadType_Main) && (threadType != Osal_ThreadType_Hwi))
    {
        /* Acquire the lock for this particular UART_printf */
        (void)UART_osalPendLock(uart_stdio.sem, SemaphoreP_WAIT_FOREVER);
    }

    /* Start the varargs processing. */
    (void)va_start(vaArgP, pcString);

    /* Loop while there are more characters in the string. */
    while (*pStr != (char)0U)
    {
        /* Find the first non-% character, or the end of the string. */
        for (ulIdx = 0;
             (pStr[ulIdx] != (char) '%') &&
             (pStr[ulIdx] != (char) '\0');
             ulIdx++)
        {}

        /* Write this portion of the string. */
        (void)UART_dataWrite(pStr, ulIdx);

        /* Skip the portion of the string that was written. */
        pStr += ulIdx;

        /* See if the next character is a %. */
        if (*pStr == (char) '%')
        {
            /* Skip the %. */
            pStr++;

            /* Set the digit count to zero, and the fill character to space
             * (i.e. to the defaults). */
            ulCount = 0;
            cFill   = (char) ' ';

            /* Determine how to handle the next character. */ 
            while((*pStr >= (char)'0') && (*pStr <= (char)'9'))
            {
                /* If this is a zero, and it is the first digit, then the
                 * fill character is a zero instead of a space. */
                if ((pStr[-1] == (char) '0') && (ulCount == 0U))
                {
                    cFill = (char) '0';
                }

                /* Update the digit count. */
                ulCount *= 10u;
                ulCount += ((uint32_t)(*pStr)) - (uint32_t) '0';

                /* Get the next character. */
                pStr++;
            }
            switch (*pStr)
            {
                /* Handle the %c command. */
                case (char) 'c':
                {
                    /* Get the value from the varargs. */
                    ulValue = (uint32_t)va_arg(vaArgP, uint32_t);

                    /* Print out the character. */
                    (void)UART_dataWrite((const char *) &ulValue, 1u);

                    /* This command has been handled. */
                    break;
                }

                /* Handle the %d command. */
                case (char) 'd':
                {
                    /* Get the value from the varargs. */
                    ulValue = (uint32_t)va_arg(vaArgP, uint32_t);

                    /* Reset the buffer position. */
                    ulPos = 0;

                    /* If the value is negative, make it positive and indicate
                     * that a minus sign is needed. */
                    if ((int32_t) ulValue < 0)
                    {
                        /* Make the value positive. */
                        temp_var = (0 - ((int32_t)ulValue));
                        ulValue = (uint32_t)temp_var;

                        /* Indicate that the value is negative. */
                        ulNeg = 1u;
                    }
                    else
                    {
                        /* Indicate that the value is positive so that a minus
                         * sign isn't inserted. */
                        ulNeg = 0;
                    }

                    /* Set the base to 10. */
                    ulBase = 10u;

                    /* Convert the value to ASCII. */
                    (void)UART_convertVal(ulValue, ulPos, ulBase, ulNeg, ulCount, cFill, pcBuf);
                    
                    break;
                }

                /* Handle the %s command. */
                case (char) 's':
                {
                    /* Get the string pointer from the varargs. */
                    pcStr = va_arg(vaArgP, char *);

                    /* Determine the length of the string. */
                    for (ulIdx = 0; pcStr[ulIdx] != (char) '\0'; ulIdx++)
                    {}

                    /* Write the string. */
                    (void)UART_dataWrite(pcStr, ulIdx);

                    /* Write any required padding spaces */
                    if (ulCount > ulIdx)
                    {
                        ulCount -= ulIdx;
                        while ((ulCount--)  != 0U)
                        {
                            (void)UART_dataWrite(" ", 1u);
                        }
                    }
                    /* This command has been handled. */
                    break;
                }

                /* Handle the %u command. */
                case (char) 'u':
                {
                    /* Get the value from the varargs. */
                    ulValue = (uint32_t)va_arg(vaArgP, uint32_t);

                    /* Reset the buffer position. */
                    ulPos = 0;

                    /* Set the base to 10. */
                    ulBase = 10u;

                    /* Indicate that the value is positive so that a minus sign
                     * isn't inserted. */
                    ulNeg = 0;

                    /* Convert the value to ASCII. */
                    (void)UART_convertVal(ulValue, ulPos, ulBase, ulNeg, ulCount, cFill, pcBuf);
                    
                    break;
                }

                /* Handle the %x and %X commands.  Note that they are treated
                 * identically; i.e. %X will use lower case letters for a-f
                 * instead of the upper case letters is should use.  We also
                 * alias %p to %x. */
                case (char) 'x':
                case (char) 'X':
                case (char) 'p':
                {
                    /* Get the value from the varargs. */
                    ulValue = (uint32_t)va_arg(vaArgP, uint32_t);

                    /* Reset the buffer position. */
                    ulPos = 0;

                    /* Set the base to 16. */
                    ulBase = 16u;

                    /* Indicate that the value is positive so that a minus sign
                     * isn't inserted. */
                    ulNeg = 0;

                    /* Determine the number of digits in the string version of
                     * the value. */
                    (void)UART_convertVal(ulValue, ulPos, ulBase, ulNeg, ulCount, cFill, pcBuf);
                    
                    break;
                }

                /* Handle the %% command. */
                case (char) '%':
                {
                    /* Simply write a single %. */
                    (void)UART_dataWrite(pStr - 1u, 1u);

                    /* This command has been handled. */
                    break;
                }

                /* Handle all other commands. */
                default:
                {
                    /* Indicate an error. */
                    (void)UART_dataWrite("ERROR", 5u);

                    /* This command has been handled. */
                    break;
                }
            } 
            pStr++;
        }
    }

    /* End the varargs processing. */
    va_end(vaArgP);

    if ((threadType != Osal_ThreadType_Main) && (threadType != Osal_ThreadType_Hwi))
    {
        /* Release the lock for this particular UART_printf */
        (void)UART_osalPostLock(uart_stdio.sem);
    }
}

int32_t UART_scanFmt(const char *pString, ...)
{
    int32_t retStatus = E_FAIL;
    uint32_t dataType = (uint32_t)UART_UTILS_DATA_TYPE_MAX;
    uint8_t rxBuf[UART_UTILS_INPUT_SIZE_MAX];
    uint32_t curBufIndex = 0U;
    UART_UtilsBuf_t rxConsoleBuf;
    va_list  vaArg;
    const char *pStr= pString;

       /* Start the varargs processing. */
    (void)va_start(vaArg, pString);


    void *pVar = NULL;

    rxConsoleBuf.pBuf = rxBuf;
    rxConsoleBuf.curBufIndex = &curBufIndex;
    rxConsoleBuf.bufSize =  UART_UTILS_INPUT_SIZE_MAX;
    if(NULL != pStr)
    {
        retStatus = UART_blockingRead(&rxConsoleBuf);

        if(S_PASS == retStatus)
        {
            curBufIndex = 0U;
        }
    }

    /* Loop while there are more characters in the string. */
    while((S_PASS == retStatus) && (*pStr != ((char)('\0'))))
    {
        /* Find the first % character */
        if((*pStr == ((char)('%'))) && (S_PASS == retStatus))
        {
            ++pStr;
            switch(*(pStr))
            {
                /* Handle the %c command. */
                case ((char)('c')):
                {
                    /* Get the address of variable from varargs */
                    pVar = va_arg(vaArg, uint8_t *);
                    dataType = (uint32_t)UART_UTILS_DATA_TYPE_CHAR;
                    break;
                }
                /* Handle the %d command. */
                case ((char)('d')):
                {
                    /* Get the address of variable from argument */
                    pVar = va_arg(vaArg, int32_t *);
                    dataType = (uint32_t)UART_UTILS_DATA_TYPE_DECIMAL;
                    break;
                }
                /* Handle the %x,%X and %p command. */
                case ((char)('x')):
                case ((char)('X')):
                case ((char)('p')):
                {
                    /* Get the address of variable from varargs */
                    pVar = va_arg(vaArg, uint32_t *);
                    dataType = (uint32_t)UART_UTILS_DATA_TYPE_HEX;
                    break;
                }
                /* Handle the %s command. */
                case ((char)('s')):
                {
                    /* Get the address of variable from the argument. */
                    pVar = va_arg(vaArg, uint8_t *);
                    dataType = (uint32_t)UART_UTILS_DATA_TYPE_STR;
                    break;
                }
                /* Handles %u command. */
                case ((char)('u')):
                {
                    /* Get the address of variable from varargs */
                    pVar = va_arg(vaArg, uint32_t *);
                    dataType = (uint32_t)UART_UTILS_DATA_TYPE_UNSIGN_DECIMAL;
                    break;
                }
                /* Invalid command. */
                default:
                {
                    retStatus = E_FAIL;
                    dataType = (uint32_t)UART_UTILS_DATA_TYPE_MAX;
                    break;
                }
            }

            if(S_PASS == retStatus)
            {
                retStatus = UART_decode(&rxConsoleBuf, pVar, dataType);
            }
        }
        /* Loop continuously until any character other than space. */
        else if((((char)(' ')) != *pStr) && (((char)('\t')) != *pStr) && (((char)('\b')) != *pStr) &&
    (((char)('\n')) != *pStr))
        {
            retStatus = E_FAIL;
        }
        else
        {
            /*   Dummy statement for handling MISRA.IF.NO_ELSE warning  */
            retStatus = S_PASS;
        }

        pStr++;
    }
    va_end(vaArg);
    return retStatus;
}

static int32_t UART_decode(const UART_UtilsBuf_t *pRxConsoleBuf,
                               void *pVar,
                               uint32_t dataType)
{
    int32_t retStatus = E_FAIL;
    uint8_t *pRxBuf = NULL;
    uint32_t *pRxBufIndex = NULL;

    /* Validate input parameters. */
    if(NULL != pRxConsoleBuf)
    {
        pRxBuf = pRxConsoleBuf->pBuf;
        if(NULL != pRxBuf)
        {
            pRxBufIndex = pRxConsoleBuf->curBufIndex;
            if(NULL != pRxBufIndex)
            {
                if(NULL != pVar)
                {
                    retStatus = S_PASS;
                }
            }
        }
    }

    if(S_PASS == retStatus)
    {
        if(*pRxBufIndex >= pRxConsoleBuf->bufSize)
        {
            retStatus = E_FAIL;
        }
    }

    if(S_PASS == retStatus)
    {
        pRxBuf += *pRxBufIndex;

        switch(dataType)
        {
            case (uint32_t)UART_UTILS_DATA_TYPE_CHAR:
            {
                uint8_t *pCharVar = (uint8_t*)pVar;

                /*
                 * Validate the input parameter.
                 */
                if(*pRxBuf != ((uint8_t)('\0')))
                {
                    /*
                     * Extract character from the input buffer.
                     */
                    *pCharVar = *pRxBuf;

                    (*pRxBufIndex)++;
                }
                else
                {
                    retStatus = E_FAIL;
                }
                break;
            }
            case (uint32_t)UART_UTILS_DATA_TYPE_DECIMAL:
            {
                int32_t *pDecVar = (int32_t *) pVar;
                int32_t sign = 1;
                uint8_t rxDigit = ((uint8_t)('\0'));

                /*
                 * Loop continuously until any character other than space.
                 */
                while((((uint8_t)(' ')) == *pRxBuf) || (((uint8_t)('\t')) == *pRxBuf) || (((uint8_t)('\b')) == *pRxBuf))
                {
                    pRxBuf++;
                    (*pRxBufIndex)++;

                    if(*pRxBufIndex >= pRxConsoleBuf->bufSize)
                    {
                        retStatus = E_FAIL;
                    }
                }

                /*
                 * Check for termination condition at start.
                 */
                if(S_PASS == retStatus)
                {
                    if((((uint8_t)('\0')) == *pRxBuf) || (((uint8_t)('\n')) == *pRxBuf) || (((uint8_t)('\r')) == *pRxBuf))
                    {
                        retStatus = E_FAIL;
                    }
                }


                if(S_PASS == retStatus)
                {
                    /*
                     * Account for negative numbers.
                     */
                    if(((uint8_t)('-')) == *pRxBuf)
                    {
                        sign = (-((int32_t)1));
                        pRxBuf++;
                        (*pRxBufIndex)++;
                    }

                    /*
                     * Validate the start condition of input parameter.
                     */
                    if((uint8_t)E_FAIL == UART_ASCIIUtils_charToDigit(*pRxBuf, UART_ASCII_UTILS_BASE_DECIMAL))
                    {
                        retStatus = E_FAIL;
                    }
                }

                if(S_PASS == retStatus)
                {
                    int32_t decVal = 0;

                    /*
                     * Extract the variable till a terminate condition. Either
                     * space or null or invalid character act as termination.
                     */
                    while(((uint8_t)E_FAIL != rxDigit) && (*pRxBufIndex < pRxConsoleBuf->bufSize))
                    {
                        /*
                         * Convert the ASCII value to decimal number.
                         */
                        rxDigit = UART_ASCIIUtils_charToDigit(*pRxBuf, UART_ASCII_UTILS_BASE_DECIMAL);

                        /*
                         * Check input is valid decimal digit.
                         */
                        if((uint8_t)E_FAIL != rxDigit)
                        {
                            decVal = (decVal * ((int32_t)UART_ASCII_UTILS_BASE_DECIMAL)) + (int32_t)rxDigit;
                            pRxBuf++;
                            (*pRxBufIndex)++;
                        }
                    }

                    /*
                     * Apply the sign of the variable.
                     */
                    if((*pRxBuf == ((uint8_t)('\t'))) || (*pRxBuf == ((uint8_t)(' '))) || (*pRxBuf == ((uint8_t)('\n'))) || (*pRxBuf == ((uint8_t)('\r'))) || (*pRxBuf == ((uint8_t)('\0'))) || ((*pRxBufIndex == pRxConsoleBuf->bufSize) && (E_FAIL != (int32_t)rxDigit)))
                    {
                        *pDecVar = sign * decVal;
                    }
                }
                break;
            }
            case (uint32_t)UART_UTILS_DATA_TYPE_HEX:
            {
                uint32_t *pHexaDecVar = (uint32_t *) pVar;
                uint8_t rxDigit = ((uint8_t)('\0'));

                /*
                 * Loop continuously until any character other than space.
                 */
                while((((uint8_t)(' ')) == *pRxBuf) || (((uint8_t)('\t')) == *pRxBuf) || (((uint8_t)('\b')) == *pRxBuf))
                {
                    pRxBuf++;
                    (*pRxBufIndex)++;

                    if(*pRxBufIndex >= pRxConsoleBuf->bufSize)
                    {
                        retStatus = E_FAIL;
                    }
                }

                /*
                 * Check for termination condition at start.
                 */
                if(S_PASS == retStatus)
                {
                    if((((uint8_t)('\0')) == *pRxBuf) || (((uint8_t)('\n')) == *pRxBuf) || (((uint8_t)('\r')) == *pRxBuf))
                    {
                        retStatus = E_FAIL;
                        (*pRxBufIndex)++;
                    }
                }

                /*
                * Check for 0x or 0X.
                 */
                if(S_PASS == retStatus)
                {
                    if((((uint8_t)('0')) == *pRxBuf) && ((((uint8_t)('X')) == *(pRxBuf + 1U)) || (((uint8_t)('x')) == *(pRxBuf + 1U))))
                    {
                        pRxBuf += 2U;
                        (*pRxBufIndex) += 2U;
                    }
                }

                if(S_PASS == retStatus)
                {
                    /*
                     * Validate the start condition of input parameter.
                     */
                    if((uint8_t)E_FAIL == UART_ASCIIUtils_charToDigit(*pRxBuf, UART_ASCII_UTILS_BASE_HEXADECIMAL))
                    {
                        retStatus = E_FAIL;
                    }
                }

                if(S_PASS == retStatus)
                {
                    uint32_t hexaDecVal = 0U;

                    /*
                     * Extract the variable till a terminate condition. Either
                     * space or null or invalid character act as termination.
                     */
                    while(((uint8_t)E_FAIL != rxDigit) && (*pRxBufIndex < pRxConsoleBuf->bufSize))
                    {
                        /*
                         * Convert the ASCII value to decimal number.
                         */
                        rxDigit = UART_ASCIIUtils_charToDigit(*pRxBuf, UART_ASCII_UTILS_BASE_HEXADECIMAL);

                        /*
                         * Check input is valid decimal digit.
                         */
                        if((uint8_t)E_FAIL != rxDigit)
                        {
                            hexaDecVal = (hexaDecVal * UART_ASCII_UTILS_BASE_HEXADECIMAL) + rxDigit;
                            pRxBuf++;
                            (*pRxBufIndex)++;
                        }
                    }

                    if((*pRxBuf == ((uint8_t)('\t'))) || (*pRxBuf == ((uint8_t)(' '))) || (*pRxBuf == ((uint8_t)('\n'))) || (*pRxBuf == ((uint8_t)('\r'))) || (*pRxBuf == ((uint8_t)('\0'))) || ((*pRxBufIndex == pRxConsoleBuf->bufSize) && (E_FAIL != (int32_t)rxDigit)))
                    {
                        *pHexaDecVar = hexaDecVal;
                    }
                }
                break;
            }
            case (uint32_t)UART_UTILS_DATA_TYPE_UNSIGN_DECIMAL:
            {
                uint32_t *pUnsignDecVar = (uint32_t *) pVar;
                uint8_t rxDigit = ((uint8_t)('\0'));

                /*
                 * Loop continuously until any character other than space.
                 */
                while((((uint8_t)(' ')) == *pRxBuf) || (((uint8_t)('\t')) == *pRxBuf) || (((uint8_t)('\b')) == *pRxBuf))
                {
                    pRxBuf++;
                    (*pRxBufIndex)++;

                    if(*pRxBufIndex >= pRxConsoleBuf->bufSize)
                    {
                        retStatus = E_FAIL;
                    }
                }

                /*
                 * Check for termination condition at start.
                 */
                if(S_PASS == retStatus)
                {
                    if((((uint8_t)('\0')) == *pRxBuf) || (((uint8_t)('\n')) == *pRxBuf) || (((uint8_t)('\r')) == *pRxBuf))
                    {
                        retStatus = E_FAIL;
                        (*pRxBufIndex)++;
                    }
                }

                if(S_PASS == retStatus)
                {
                    /*
                     * Validate the start condition of input parameter.
                     */
                    if((uint8_t)E_FAIL == UART_ASCIIUtils_charToDigit(*pRxBuf, UART_ASCII_UTILS_BASE_DECIMAL))
                    {
                        retStatus = E_FAIL;
                    }
                }

                if(S_PASS == retStatus)
                {
                    uint32_t unSignDecVal = 0U;

                    /*
                     * Extract the variable till a terminate condition. Either
                     * space or null or invalid character act as termination.
                     */
                    while(((uint8_t)E_FAIL != rxDigit) && (*pRxBufIndex < pRxConsoleBuf->bufSize))
                    {
                        /*
                         * Convert the ASCII value to decimal number.
                         */
                        rxDigit = UART_ASCIIUtils_charToDigit(*pRxBuf, UART_ASCII_UTILS_BASE_DECIMAL);

                        /*
                         * Check input is valid decimal digit.
                         */
                        if((uint8_t)E_FAIL != rxDigit)
                        {
                            unSignDecVal = (unSignDecVal * UART_ASCII_UTILS_BASE_DECIMAL) + rxDigit;
                            pRxBuf++;
                            (*pRxBufIndex)++;
                        }
                    }

                    if((*pRxBuf == ((uint8_t)('\t'))) || (*pRxBuf == ((uint8_t)(' '))) || (*pRxBuf == ((uint8_t)('\n'))) || (*pRxBuf == ((uint8_t)('\r'))) || (*pRxBuf == ((uint8_t)('\0'))) || ((*pRxBufIndex == pRxConsoleBuf->bufSize) && (E_FAIL != (int32_t)rxDigit)))
                    {
                        *pUnsignDecVar = unSignDecVal;
                    }
                }
                break;
            }
            case (uint32_t)UART_UTILS_DATA_TYPE_STR:
            {
                uint8_t *pStrVar = (uint8_t*)pVar;

                /*
                 * Validate the input parameter.
                 */
                if(*pRxBuf != ((uint8_t)('\0')))
                {
                    retStatus = S_PASS;
                }
                else
                {
                    retStatus = E_FAIL;
                }

                if(S_PASS == retStatus)
                {
                    /*
                     * Extract the variable till a terminate condition. Either
                     * space or null or invalid character act as termination.
                     */
                    while((*pRxBuf != ((uint8_t)('\t'))) && (*pRxBuf != ((uint8_t)(' '))) && (*pRxBuf != ((uint8_t)('\n'))) && (*pRxBuf != ((uint8_t)('\r'))) && (*pRxBuf != ((uint8_t)('\0'))) && (*pRxBufIndex < pRxConsoleBuf->bufSize))
                    {
                        *pStrVar = *pRxBuf;
                        pRxBuf++;
                        pStrVar++;
                        (*pRxBufIndex)++;
                    }

                    *pStrVar = ((uint8_t)('\0'));
                }
                break;
            }
            default:
            {
                retStatus = E_FAIL;
                break;
            }
        }

    }

    return retStatus;
}

static int32_t UART_blockingRead(const UART_UtilsBuf_t *pRxConsoleBuf)
{
    int32_t retStatus = E_FAIL;
    uint8_t *pRxBuf = NULL;
    uint32_t *pRxBufIndex = NULL;
    uint8_t rxByte = 0xFFu;

    /* Validate input parameters. */
    if(NULL != pRxConsoleBuf)
    {
        pRxBuf = pRxConsoleBuf->pBuf;
        if(NULL != pRxBuf)
        {
            pRxBufIndex = pRxConsoleBuf->curBufIndex;
            if(NULL != pRxBufIndex)
            {
                *pRxBufIndex = 0U;
                retStatus = S_PASS;
            }
        }
    }

    if(S_PASS == retStatus)
    {
        uint32_t readStatus = (uint32_t)UART_UTILS_READ_STATUS_CONTINUE;

        pRxBuf += *pRxBufIndex;

        /* Clear Residual Characters */
        while((uint32_t)UART_UTILS_READ_STATUS_CONTINUE == readStatus)
        {
            /* UARTGetChar(0, &rxByte, UART_WAIT_FOREVER);  */
            rxByte = UART_getc();
            if(((((uint8_t)('\n')) == rxByte) || (((uint8_t)('\r')) == rxByte)))
            {
                *pRxBuf = ((uint8_t)('\n'));
                pRxBuf++;
                *pRxBufIndex += 1U;
                readStatus = (uint32_t)UART_UTILS_READ_STATUS_TERMINATE;
                UART_putc(((uint8_t)('\n')));
                UART_putc(((uint8_t)('\r')));
            }
            else if(*pRxBufIndex == (pRxConsoleBuf->bufSize - 1U))
            {
                *pRxBuf = rxByte;
                pRxBuf++;
                *pRxBufIndex += 1U;
                readStatus = (uint32_t)UART_UTILS_READ_STATUS_TERMINATE;
                UART_putc(rxByte);
                UART_putc(((uint8_t)('\n')));
                UART_putc(((uint8_t)('\r')));
            }
            /*
             * Account for the backspace to allow user edit the input.
             */
            else if(((uint8_t)('\b')) == rxByte)
            {
                if(*pRxBufIndex > 0U)
                {
                    uint8_t prevRxByte = 0xFFu;
                    uint32_t idx = 0U;
                    uint32_t cnt = 0U;

                    pRxBuf--;
                    prevRxByte = (uint8_t)*pRxBuf;
                    *pRxBuf = ((uint8_t)('\0'));
                    *pRxBufIndex -= 1U;

                    if(((uint8_t)('\t')) == prevRxByte)
                    {
                        cnt = 4U;
                    }
                    else if(prevRxByte < ((uint8_t)(' ')))
                    {
                        cnt = 3U;
                    }
                    else
                    {
                        cnt = 1U;
                    }

                    for(idx = 0U; idx < cnt; idx++)
                    {
                        UART_putc((uint8_t)('\b'));
                        UART_putc((uint8_t)(' '));  /* To clear the character */
                        UART_putc((uint8_t)('\b'));
                    }
                }
                readStatus = (uint32_t)UART_UTILS_READ_STATUS_CONTINUE;
            }
            /*
             * Read the printable characters.
             */
            else if(((rxByte >= ((uint8_t)(' '))) && (rxByte <= ((uint8_t)('~')))) || (((uint8_t)('\t')) == rxByte))
            {
                *pRxBuf = (uint8_t)rxByte;
                pRxBuf++;
                *pRxBufIndex += 1U;
                readStatus = (uint32_t)UART_UTILS_READ_STATUS_CONTINUE;
                UART_putc(rxByte);
            }
            /*
             * Read the non-printable characters.
             */
            else if(rxByte < ((uint8_t)(' ')))
            {
                *pRxBuf = (uint8_t)rxByte;
                pRxBuf++;
                *pRxBufIndex += 1U;
                readStatus = (uint32_t)UART_UTILS_READ_STATUS_CONTINUE;
                UART_putc((uint8_t)('^'));
                UART_putc(rxByte + ((uint8_t)('@')));
            }
            /*
             * Skip other characters.
             */
            else
            {
                readStatus = (uint32_t)UART_UTILS_READ_STATUS_CONTINUE;
            }
        }

        if((uint32_t)UART_UTILS_READ_STATUS_TERMINATE != readStatus)
        {
            retStatus = E_FAIL;
        }
    }

    return retStatus;
}


/*
** A wrapper function for putting data on UART Console.
*/
static void uart_console_putc(uint8_t data)
{
    Osal_ThreadType threadType = UART_osalGetThreadType();

    if (uart_stdio.uart_handle != NULL)
    {
        if (threadType == Osal_ThreadType_Main)
        {
            (void)UART_writePolling(uart_stdio.uart_handle, &data, 1u);
        }
        else
        {
            (void)UART_write(uart_stdio.uart_handle, &data, 1u);
        }
    }
}

/*
** A wrapper function for getting data from UART Console.
*/
static uint8_t uart_console_getc(void)
{
    uint8_t temp = 0;
    if (uart_stdio.uart_handle != NULL)
    {
        (void)UART_readPolling(uart_stdio.uart_handle, &temp, 1u);
    }
    return(temp);
}

/**
 * \brief   This function de-initializes the UART instance
 *          that is opened for console operations.
 *
 * \param   none.
 *
 * \return  None.
 *
 */
void UART_stdioDeInit(void)
{
    if (uart_stdio.uart_handle != NULL)
    {
        UART_close(uart_stdio.uart_handle);
        (void)UART_osalDeleteBlockingLock(uart_stdio.sem);

        /* 
         * Reset the STDIO handle to NULL so that subsequent stdioInit calls
         * re-open the handle and re-register the interrupt.
         */
        uart_stdio.uart_handle = NULL;
    }
}


/******************************* End of file *********************************/
