/*
 *  Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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
 *
 */

/**
 * \file   uart_config.c
 *
 * \brief  This file contains functions which interface interactively
 *         with the user through the serial console to perform some
 *         utility operations.
 */
#include "uart_config.h"


/**
 * \brief   This function writes a byte on the serial console.
 *
 * \param   baseAddr    Base Address of UART instance.
 * \param   byteTx      The byte to be transmitted.
 *
 * \return  None.
 */
void UARTConfigPutc(uint32_t baseAddr, uint8_t byteTx)
{
    UART_charPut_v0(baseAddr, byteTx);
}

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
int32_t UARTwrite(uint32_t baseAddr, const char *pcBuf, uint32_t len)
{
    uint32_t uIdx;

    /* Send the characters */
    for (uIdx = 0; uIdx < len; uIdx++)
    {
        /* If the character to the UART is \n, then add a \r before it so that
         * \n is translated to \n\r in the output. */
        if (pcBuf[uIdx] == (char) '\n')
        {
            UARTConfigPutc(baseAddr, (uint8_t) '\r');
        }

        /* Send the character to the UART output. */
        UARTConfigPutc(baseAddr, (uint8_t) pcBuf[uIdx]);
    }

    /* Return the number of characters written. */
    return (int32_t) (uIdx);
}

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
void UARTConfigPrintf(uint32_t baseAddr, const char *pcString, ...)
{
    uint32_t ulIdx, ulValue, ulPos, ulCount, ulBase, ulNeg;
    char    *pcStr, pcBuf[16], cFill;
    va_list  vaArgP;
    char     digitCnt;

    /* Start the varargs processing. */
    va_start(vaArgP, pcString);

    /* Loop while there are more characters in the string. */
    while (*pcString)
    {
        /* Find the first non-% character, or the end of the string. */
        for (ulIdx = 0;
             (pcString[ulIdx] != (char) '%') &&
             (pcString[ulIdx] != (char) '\0');
             ulIdx++)
        {}

        /* Write this portion of the string. */
        UARTwrite(baseAddr, pcString, ulIdx);

        /* Skip the portion of the string that was written. */
        pcString += ulIdx;

        /* See if the next character is a %. */
        if (*pcString == (char) '%')
        {
            /* Skip the %. */
            pcString++;

            /* Set the digit count to zero, and the fill character to space
             * (i.e. to the defaults). */
            ulCount = 0;
            cFill   = (char) ' ';

            /* Handle the digit characters first. */
            switch (*pcString)
            {
                case (char) '0':
                case (char) '1':
                case (char) '2':
                case (char) '3':
                case (char) '4':
                case (char) '5':
                case (char) '6':
                case (char) '7':
                case (char) '8':
                case (char) '9':
                {
                    do {
                        /* If this is a zero, and it is the first digit, then
                         * the
                         * fill character is a zero instead of a space. */
                        if ((pcString[-(int32_t) 1] == (char) '0') &&
                            (ulCount == 0))
                        {
                            cFill = (char) '0';
                        }

                        /* Update the digit count. */
                        ulCount *= 10U;
                        digitCnt = (char) (pcString[-(int32_t) 1] - (char) '0');
                        ulCount += (uint32_t) digitCnt;
                        pcString++;
                    } while ((*pcString >= (char) '0') &&
                             (*pcString <= (char) '9'));
                    break;
                }
                default:
                    break;
            }

            /* Determine how to handle the next character. */
            switch (*pcString)
            {
                /* Handle the %c command. */
                case (char) 'c':
                {
                    /* Get the value from the varargs. */
                    ulValue = va_arg(vaArgP, uint32_t);

                    /* Print out the character. */
                    UARTwrite(baseAddr, (char *) &ulValue, (uint32_t) 1);

                    /* This command has been handled. */
                    break;
                }

                /* Handle the %d command. */
                case (char) 'd':
                {
                    int32_t tempValue;
                    /* Get the value from the varargs. */
                    ulValue = va_arg(vaArgP, uint32_t);

                    /* Reset the buffer position. */
                    ulPos = 0;

                    /* If the value is negative, make it positive and indicate
                     * that a minus sign is needed. */
                    if ((int32_t) ulValue < 0)
                    {
                        /* Make the value positive. */
                        tempValue = -(int32_t) ulValue;
                        ulValue   = (uint32_t) tempValue;

                        /* Indicate that the value is negative. */
                        ulNeg = 1U;
                    }
                    else
                    {
                        /* Indicate that the value is positive so that a minus
                         * sign isn't inserted. */
                        ulNeg = 0;
                    }

                    /* Set the base to 10. */
                    ulBase = 10U;

                    /* Convert the value to ASCII. */
                    ulIdx = 1U;
                    while (((ulIdx * ulBase) <= ulValue) &&
                           (((ulIdx * ulBase) / ulBase) == ulIdx))
                    {
                        ulCount--;
                        ulIdx *= ulBase;
                    }

                    /* If the value is negative, reduce the count of padding
                     * characters needed. */
                    if (ulNeg)
                    {
                        ulCount--;
                    }

                    /* If the value is negative and the value is padded with
                     * zeros, then place the minus sign before the padding. */
                    if ((ulNeg != 0U) && (cFill == (char) '0'))
                    {
                        /* Place the minus sign in the output buffer. */
                        pcBuf[ulPos] = (char) '-';
                        ulPos++;

                        /* The minus sign has been placed, so turn off the
                         * negative flag. */
                        ulNeg = 0;
                    }

                    /* Provide additional padding at the beginning of the
                     * string conversion if needed. */
                    if ((ulCount > 1U) && (ulCount < 16U))
                    {
                        for (ulCount--; ulCount; ulCount--)
                        {
                            pcBuf[ulPos] = cFill;
                            ulPos++;
                        }
                    }

                    /* If the value is negative, then place the minus sign
                     * before the number. */
                    if (ulNeg)
                    {
                        /* Place the minus sign in the output buffer. */
                        pcBuf[ulPos] = (char) '-';
                        ulPos++;
                    }

                    /* Convert the value into a string. */
                    for (; ulIdx; ulIdx /= ulBase)
                    {
                        pcBuf[ulPos] = g_pcHex[(ulValue / ulIdx) % ulBase];
                        ulPos++;
                    }

                    /* Write the string. */
                    UARTwrite(baseAddr, pcBuf, ulPos);

                    /* This command has been handled. */
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
                    UARTwrite(baseAddr, pcStr, ulIdx);

                    /* Write any required padding spaces */
                    if (ulCount > ulIdx)
                    {
                        ulCount -= ulIdx;
                        while (ulCount--)
                        {
                            UARTwrite(baseAddr, " ", (uint32_t) 1);
                        }
                    }
                    /* This command has been handled. */
                    break;
                }

                /* Handle the %u command. */
                case (char) 'u':
                {
                    /* Get the value from the varargs. */
                    ulValue = va_arg(vaArgP, uint32_t);

                    /* Reset the buffer position. */
                    ulPos = 0;

                    /* Set the base to 10. */
                    ulBase = 10U;

                    /* Indicate that the value is positive so that a minus sign
                     * isn't inserted. */
                    ulNeg = 0;

                    /* Convert the value to ASCII. */
                    ulIdx = 1U;
                    while (((ulIdx * ulBase) <= ulValue) &&
                           (((ulIdx * ulBase) / ulBase) == ulIdx))
                    {
                        ulCount--;
                        ulIdx *= ulBase;
                    }

                    /* Provide additional padding at the beginning of the
                     * string conversion if needed. */
                    if ((ulCount > 1U) && (ulCount < 16U))
                    {
                        for (ulCount--; ulCount; ulCount--)
                        {
                            pcBuf[ulPos] = cFill;
                            ulPos++;
                        }
                    }

                    /* Convert the value into a string. */
                    for (; ulIdx; ulIdx /= ulBase)
                    {
                        pcBuf[ulPos] = g_pcHex[(ulValue / ulIdx) % ulBase];
                        ulPos++;
                    }

                    /* Write the string. */
                    UARTwrite(baseAddr, pcBuf, ulPos);

                    /* This command has been handled. */
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
                    ulValue = va_arg(vaArgP, uint32_t);

                    /* Reset the buffer position. */
                    ulPos = 0;

                    /* Set the base to 16. */
                    ulBase = 16U;

                    /* Indicate that the value is positive so that a minus sign
                     * isn't inserted. */
                    ulNeg = 0;

                    /* Determine the number of digits in the string version of
                     * the value. */

                    ulIdx = 1U;
                    while (((ulIdx * ulBase) <= ulValue) &&
                           (((ulIdx * ulBase) / ulBase) == ulIdx))
                    {
                        ulCount--;
                        ulIdx *= ulBase;
                    }

                    /* Provide additional padding at the beginning of the
                     * string conversion if needed. */
                    if ((ulCount > 1U) && (ulCount < 16U))
                    {
                        for (ulCount--; ulCount; ulCount--)
                        {
                            pcBuf[ulPos] = cFill;
                            ulPos++;
                        }
                    }

                    /* Convert the value into a string. */
                    for (; ulIdx; ulIdx /= ulBase)
                    {
                        pcBuf[ulPos] = g_pcHex[(ulValue / ulIdx) % ulBase];
                        ulPos++;
                    }

                    /* Write the string. */
                    UARTwrite(baseAddr, pcBuf, ulPos);

                    /* This command has been handled. */
                    break;
                }

                /* Handle the %% command. */
                case (char) '%':
                {
                    /* Simply write a single %. */
                    UARTwrite(baseAddr, pcString - 1, (uint32_t) 1);

                    /* This command has been handled. */
                    break;
                }

                /* Handle all other commands. */
                default:
                {
                    /* Indicate an error. */
                    UARTwrite(baseAddr, "ERROR", (uint32_t) 5);

                    /* This command has been handled. */
                    break;
                }
            }
            pcString++;
        }
    }

    /* End the varargs processing. */
    va_end(vaArgP);
}


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
                    uint32_t stopBit, uint32_t parity, uint32_t mode)
{
    uint32_t divisorValue = 0U, fifoConfig = 0U;
    
    /* Reset and enable UART TX/RX in free-running mode */
        UART_pwremuConfig_v0(baseAddr, UART_PWREMU_MGMT_ENABLE);

    /* Performing FIFO configurations. */
    /*
    ** - Transmit Trigger Level Granularity is 4
    ** - Receiver Trigger Level Granularity is 1
    ** - Transmit FIFO Space Setting is 56. Hence TX Trigger level
    **   is 8 (64 - 56). The TX FIFO size is 64 bytes.
    ** - The Receiver Trigger Level is 1.
    ** - Clear the Transmit FIFO.
    ** - Clear the Receiver FIFO.
    ** - DMA Mode enabling shall happen through SCR register.
    ** - DMA Mode 0 is enabled. DMA Mode 0 corresponds to No
    **   DMA Mode. Effectively DMA Mode is disabled.
    */
    fifoConfig = UART_FIFO_CONFIG(UART_FIFO_CONFIG_RXTRIG,
                                  UART_FIFO_CONFIG_TXCLR,
                                  UART_FIFO_CONFIG_RXCLR,
                                  UART_FIFO_CONFIG_DMAMODE1);

    /* Configuring the FIFO settings. */
    UART_fIFOConfig_v0(baseAddr, fifoConfig);

    /* Performing Baud Rate settings. */
    /* Computing the Divisor Value. */
    divisorValue = UART_divisorValCompute_v0(UART_MODULE_INPUT_CLK,
                                             baudRate,
                                             mode);
    /* Programming the Divisor Latches. */
    UART_divisorLatchWrite_v0(baseAddr, divisorValue);

    /* Switching to Configuration Mode B. */
    UART_regConfigModeEnable_v0(baseAddr, UART_REG_CONFIG_MODE_B);

    /* Programming the Line Characteristics. */
    UART_lineCharacConfig_v0(baseAddr, (wordLength | stopBit), parity);

    /* Disabling write access to Divisor Latches. */
    UART_divisorLatchDisable_v0(baseAddr);

    /* Disabling Break Control. */
    UART_breakCtl_v0(baseAddr, UART_BREAK_COND_DISABLE);

    /* Uart enable */
    UART_operatingModeSelect_v0(baseAddr, mode);
}


