/**
 *  \file  console_utils_uart.c
 *
 *  \brief This file contains functions which interface interactively
 *         with the user through the serial console to perform some
 *         utility operations.
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


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "error.h"
#include "uart.h"
#include "ascii_utils.h"
/* TODO: Remove when migrate to soc & board */
#if defined(AM335X_FAMILY_BUILD)
#include "soc_am335x.h"
#include "hw_control_am335x.h"
#include "hw_cm_wkup.h"
#include "hw_cm_per.h"
#elif defined(AM43XX_FAMILY_BUILD)
#include "am437x.h"
#include "hw_control_am43xx.h"
#include "hw_cm_wkup.h"
#include "hw_cm_per.h"
#endif /* if defined(AM335X_FAMILY_BUILD) */
#include "console_utils_uart.h"
#include "prcm.h"
#include "chipdb.h"
#include "board.h"
#include "device.h"
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief UART Module Input Clock. */
#define UART_MODULE_INPUT_CLK                      (48000000U)

/** \brief UART Console Port Instance. */
#define CONSOLE_UTILS_UART_INSTANCE                (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function clears the buffer till the current index.
 *
 * \param   pRxConsoleBuf  Pointer to the buffer descriptor.
 *
 * \return  Status. Takes following values.
 *          #S_PASS - Buffer cleared success.
 *          #E_FAIL - Invalid input parameter.
 */
static int32_t ConsoleUtilsUartClearBuf(consoleUtilsBuf_t *pRxConsoleBuf);

/**
 * \brief   This function interprets input and converts to given data type.
 *
 * \details The input is validated for start condition of data type.
 *          - first character shall not be '\n' for all data types except char.
 *          - ignore leading characters '\b', '\t', ' ' for decimal, hex and
 *            unsigned decimal data types.
 *          - check for valid character of data types.
 *          On valid start condition, the input is converted to given data type
 *          till either of termination condition is reached.
 *          - '\n', ' ', '\0' for all data types except char.
 *          - end of the buffer or maximum buffer size.
 *          - invalid character for data type.
 *
 * \param   pRxConsoleBuf  Pointer to the buffer descriptor.
 * \param   pVar           Pointer to the variable.
 * \param   dataType       Data type of variable.
 *
 * \return  Status. Takes following values.
 *          #S_PASS - Successfully extracted variable from input.
 *          #E_FAIL - Not a valid start condition.
 */
static int32_t ConsoleUtilsUartDecode(consoleUtilsBuf_t *pRxConsoleBuf,
                                      void *pVar,
                                      uint32_t dataType);

/**
 * \brief   This function selects the UART0 pins for use. The UART pins
 *          are multiplexed with pins of other peripherals in the SoC
 *
 * \param   consoleUartInstNum     UART instance for Console utils .
 */
static void ConsoleUtilsUartPinMuxSetup(uint32_t consoleUartInstNum);

/**
 * \brief   This function reads input from UART in blocking mode.
 *
 * \details The input is read till either a newline is entered or reached the
 *          end of buffer. On backspace previous character is deleted.
 *
 * \param   pRxConsoleBuf  Pointer to the buffer descriptor.
 *
 * \return  Status. Takes following values.
 *          #S_PASS - Successfully read data from UART.
 *          #E_FAIL - Failed to read input.
 */
static int32_t ConsoleUtilsUartBlockingRead(consoleUtilsBuf_t *pRxConsoleBuf);

/**
 * \brief   This function reads input from UART in non-blocking mode.
 *
 * \details Checking data availability data entered on UART is read and returns
 *          the status. Input is read till either newline is entered or end of
 *          buffer is reached. On backspace previous character is deleted.
 *
 * \param   pRxConsoleBuf  Pointer to the buffer descriptor.
 *
 * \return  Status. Takes following values.
 *          #consoleUtilsReadStatus_t - status of read operation.
 *          #E_FAIL - Failed to read input.
 */
static int32_t ConsoleUtilsUartNonBlockingRead(consoleUtilsBuf_t *pRxConsoleBuf);

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/** \brief UART Console instance base Address. */
static uint32_t gConsoleUtilsUartInstAddr = 0U;

/** \brief Default UART FIFO configuration for Console. */
static const uartFifoCfg_t UART_CONSOLE_DEFAULT =
{
    UART_TRIGGER_LVL_GRAN_1,        /* uartTxGran */
    UART_TRIGGER_LVL_GRAN_1,        /* uartRxGran */
    1U,                             /* uartTxTriggerLvl */
    1U,                             /* uartRxTriggerLvl */
    TRUE,                           /* clearTxFifo */
    TRUE,                           /* clearRxFifo */
    FALSE                           /* enableDma */
};  /* uartFifoCfg_t */

/** \brief Select current configuration settings. */
static const char * const gpHex = "0123456789abcdef";

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t CONSOLEUtilsUartInit(void)
{
    int32_t status = E_FAIL;
    int32_t consoleUartInstNum = 0U;
    uartFifoCfg_t fifoConfig = UART_CONSOLE_DEFAULT;
    consoleUartInstNum = BOARDGetDeviceCtrlModInstNum(DEVICE_ID_CONSOLE, 0U);

    /* Configuring the system clocks for UART0 instance. */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_UART, consoleUartInstNum,
                                FALSE);

    if(S_PASS == status)
    {
        /* Get the UART base address */
        gConsoleUtilsUartInstAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_UART,
                                     consoleUartInstNum);

        /* Performing the Pin Multiplexing for UART0 instance. */
        ConsoleUtilsUartPinMuxSetup(consoleUartInstNum);

        /* Performing a module reset. */
        UARTModuleReset(gConsoleUtilsUartInstAddr);

        /* Configuring the FIFO settings. */
        UARTFifoConfig(gConsoleUtilsUartInstAddr, &fifoConfig);

        /* Set the Baud Rate for the Console */
        UARTSetBaudRate(gConsoleUtilsUartInstAddr, UART_MODULE_INPUT_CLK,
                        UART_BAUD_RATE_115200);

        /* Programming the Line Characteristics. */
        UARTLineCharacteristicConfig(gConsoleUtilsUartInstAddr, UART_CHAR_LENGTH_8BIT,
                                  UART_STOP_BIT_1, UART_PARITY_NONE);

        /* Disabling Break Control. */
        UARTBreakCtrlEnable(gConsoleUtilsUartInstAddr, FALSE);
    }

    return status;
}

int32_t CONSOLEUtilsUartGetChar(void)
{
    int32_t status = E_FAIL;
    int32_t retValue = '\0';
    uint8_t rxBuf[CONSOLE_UTILS_INPUT_SIZE_MAX];
    uint32_t curBufIndex = 0U;
    uint8_t* pRxBuf = rxBuf;

    /* Configure read buffer. */
    consoleUtilsBuf_t rxConsoleBuf = {rxBuf, &curBufIndex,
        CONSOLE_UTILS_INPUT_SIZE_MAX};

    /* Read blocking UART input. */
    status = ConsoleUtilsUartBlockingRead(&rxConsoleBuf);

    if(S_PASS == status)
    {
        retValue = (int32_t) *pRxBuf;
    }

    /* Clear read buffer. */
    ConsoleUtilsUartClearBuf(&rxConsoleBuf);

    return retValue;
}

int32_t CONSOLEUtilsUartPutChar(int32_t character)
{
    int32_t retValue = E_FAIL;
    uint8_t charValue = (uint8_t) character;

    if(charValue <= '~')
    {
        retValue = (uint8_t) charValue;

        if('\n' == charValue)
        {
            UARTPutChar(gConsoleUtilsUartInstAddr, '\n', UART_WAIT_FOREVER);
            UARTPutChar(gConsoleUtilsUartInstAddr, '\r', UART_WAIT_FOREVER);
        }
        /* Write the printable characters on UART. */
        else if(((charValue >= ' ') && (charValue <= '~')) ||
            ('\0' == charValue) || ('\t' == charValue) ||
            ('\b' == charValue) || ('\r' == charValue))
        {
            UARTPutChar(gConsoleUtilsUartInstAddr, charValue, UART_WAIT_FOREVER);
        }
        /* Write the non-printable characters on UART. */
        else if(charValue < ' ')
        {
            UARTPutChar(gConsoleUtilsUartInstAddr, '^', UART_WAIT_FOREVER);
            UARTPutChar(gConsoleUtilsUartInstAddr, charValue + '@',
                        UART_WAIT_FOREVER);
        }
        /* Skip other characters. */
        else
        {
            retValue = E_FAIL;
        }
    }

    return retValue;
}

uint8_t *CONSOLEUtilsUartGetStr(uint8_t *pRxBuffer, uint32_t numBytesToRead)
{
    int32_t status = E_FAIL;
    uint8_t rxBuf[CONSOLE_UTILS_INPUT_SIZE_MAX];
    uint32_t curBufIndex = 0U;
    uint8_t* pRxBuf = rxBuf;

    if(NULL != pRxBuffer)
    {
        if((numBytesToRead > 0) && (numBytesToRead <= CONSOLE_UTILS_INPUT_SIZE_MAX))
        {
            status = S_PASS;
        }
    }

    if(S_PASS == status)
    {
        /* Configure read buffer. */
        consoleUtilsBuf_t rxConsoleBuf = {rxBuf, &curBufIndex, numBytesToRead};

        /* Read blocking UART input. */
        status = ConsoleUtilsUartBlockingRead(&rxConsoleBuf);

        if(S_PASS == status)
        {
            /*
             * Check for valid input character.
             */
            if(*pRxBuf != '\0')
            {
                status = S_PASS;
            }
            else
            {
                status = E_FAIL;
            }

            if(S_PASS == status)
            {
                /*
                 * Extract the variable till a terminate condition. Either
                 * NULL or newline acts as termination.
                 */
                while((*pRxBuf != '\n') && (*pRxBuf != '\r') && (*pRxBuf != '\0'))
                {
                    *pRxBuffer = *pRxBuf;
                    pRxBuf++;
                    pRxBuffer++;
                }

                *pRxBuffer = '\0';
            }
        }

        /* Clear read buffer. */
        ConsoleUtilsUartClearBuf(&rxConsoleBuf);
    }

    return pRxBuffer;
}

int32_t CONSOLEUtilsUartPutStr(const char *pTxBuffer)
{
    int32_t retStatus = E_FAIL;
    uint32_t count = 0;

    if(NULL != pTxBuffer)
    {
        retStatus = S_PASS;
    }

    if(S_PASS == retStatus)
    {
        while('\0' != *pTxBuffer)
        {
            CONSOLEUtilsUartPutChar(*pTxBuffer);
            pTxBuffer++;
            count++;
        }
    }

    if(0U != count)
    {
        retStatus = S_PASS;
    }

    return retStatus;
}

int32_t CONSOLEUtilsUartPrintFmt(const char *pString, va_list vaArg)
{
    int32_t retStatus = E_FAIL;

    if(NULL != pString)
    {
        retStatus = S_PASS;

        /* Loop while there are more characters in the pString. */
        while(*pString)
        {
            /* Find the first non-% character, or the end of the pString. */
            while((*pString != '%') && (*pString != '\0'))
            {
                /* Write this portion of the pString. */
                CONSOLEUtilsUartPutChar(*pString);
                pString++;
            }

            /* See if the next character is a %. */
            if(*pString == '%')
            {
                uint32_t pos = 0U;
                int32_t count = 0;
                uint8_t padChar = ' ';
                uint32_t longQual = 0;
                /* float precision */
                uint32_t precisionValue = 0U;

                /* Skip the %. */
                pString++;

                /*
                 * If this is a zero, and it is the first digit, then the
                 * fill character is a zero instead of a space.
                 */
                if(*pString == '0')
                {
                    padChar = '0';
                    pString++;
                }

                /* Handle the digit characters. */
                while(('0' <= *pString) && (*pString <= '9'))
                {
                    /* Update the digit count. */
                    count *= 10U;
                    count += (*pString - '0');

                    /* Get the next character. */
                    pString++;
                }

                /* Handle precision value for float*/
                if ( *pString == '.')
                {
                    pString++;
                    while(('0' <= *pString) && (*pString <= '9'))
                    {
                        /* Update the precisionValue. */
                        precisionValue *= 10U;
                        precisionValue += (*pString - '0');

                        /* Get the next character. */
                        pString++;
                    }
                    /* field width updated subtracting precision digits */
                    count = count - precisionValue;
                }

                if ((pString[0] == 'l') && (pString[1] == 'l'))
                    longQual = 1, pString += 2;

		if ((pString[0] == 'l') && (pString[1] == 'l'))
		    longQual = 1, pString += 2;

                /* Determine how to handle the next character. */
                switch(*pString++)
                {
                    /* Handle the %c command. */
                    case 'c':
                    {
                        uint32_t charValue = 0U;

                        /* Get the value from the varargs. */
                        charValue = va_arg(vaArg, uint32_t);

                        /* Print out the character. */
                        CONSOLEUtilsUartPutChar(charValue);
                        break;
                    }

                    /* Handle the %f command. */
                    case 'f':
                    {
                        int32_t negFlag = FALSE;
                        /* floatValue to be obtained from Args */
                        double floatValue;
                        /* decimalVal to update the decimal portion */
                        uint64_t decimalVal = 0U;
                        uint32_t idx = 0U;
                        uint8_t buf[32];

                        /* Get the value from the varargs. */
                        floatValue = va_arg(vaArg, double);

                        /*
                         * If the value is negative, make it positive and indicate
                         * that a minus sign is needed.
                         */
                        if(floatValue < 0)
                        {
                            /* Make the value positive. */
                            floatValue *= -1;

                            /* Indicate that the value is negative. */
                            negFlag = TRUE;
                        }

                        /* count the number of digits in Integer part */
                        for(idx = 1U;
                            (((idx * ASCII_UTILS_BASE_DECIMAL) <= floatValue) &&
          (((idx * ASCII_UTILS_BASE_DECIMAL) / ASCII_UTILS_BASE_DECIMAL) == idx));
                            idx *= ASCII_UTILS_BASE_DECIMAL, count--)
                        {
                        }

                        /*
                         * If the value is negative, reduce the count of padding
                         * characters needed.
                         */
                        if(negFlag)
                        {
                            count--;
                        }

                        /*
                         * Reduce the count by one to remove decimal '.' from
                         * the field width.
                         */
                         count--;

                        /* Provide additional padding at the beginning of the
                         * string conversion if needed.i
                         */
                        if((count > 1U) && (count < 24U))
                        {
                            for(count--; count; count--)
                            {
                                buf[pos++] = padChar;
                            }
                        }

                        /*
                         * If the value is negative and the value is padded with
                         * zeros, then place the minus sign before the padding.
                         */
                        if(negFlag && (padChar == '0'))
                        {
                            /* Place the minus sign in the output buffer. */
                            buf[pos++] = '-';

                            /*
                             * The minus sign has been placed, so turn off the
                             * negative flag.
                             */
                            negFlag = FALSE;
                        }

                        /*
                         * If the value is negative, then place the minus sign
                         * before the number.
i                        */
                        if(negFlag)
                        {
                            /* Place the minus sign in the output buffer. */
                            buf[pos++] = '-';
                        }
                        /* Store the float value into a temporary variable */
                        decimalVal = (uint64_t) floatValue;

                        /* Convert the value into a string. */
                        for(; idx; idx /= ASCII_UTILS_BASE_DECIMAL)
                        {
                            buf[pos++] =
                               gpHex[(decimalVal / idx) % ASCII_UTILS_BASE_DECIMAL];
                        }

                        /* save '.' as string  */
                           buf[pos++] = '.';

                        /* default precion value is 6 else calculate */
                        switch (precisionValue)
                        {
                            case 0:
                                precisionValue = 6U;
                                break;
                            default:
                                break;
                        }

                       /* save the value after '.' into string */
                        for (idx = 1U; idx <= precisionValue; idx ++)
                        {
                           floatValue *= 10U;
                           buf[pos++] =
                               gpHex[ ((uint64_t)floatValue) % ASCII_UTILS_BASE_DECIMAL];
                        }

                        /* Write the string. */
                        for(idx = 0U; idx < pos; idx++)
                        {
                            CONSOLEUtilsUartPutChar(buf[idx]);
                        }
                        break;
                    }

                    /* Handle the %d command. */
                    case 'd':
                    {
                        int32_t negFlag = FALSE;
                        int32_t decValue = 0;
                        uint32_t idx = 0U;
                        uint8_t buf[16];

                        /* Get the value from the varargs. */
                        decValue = va_arg(vaArg, int32_t);

                        /*
                         * If the value is negative, make it positive and indicate
                         * that a minus sign is needed.
                         */
                        if(decValue < 0)
                        {
                            /* Make the value positive. */
                            decValue *= -1;

                            /* Indicate that the value is negative. */
                            negFlag = TRUE;
                        }

                        for(idx = 1U;
                            (((idx * ASCII_UTILS_BASE_DECIMAL) <= decValue) &&
          (((idx * ASCII_UTILS_BASE_DECIMAL) / ASCII_UTILS_BASE_DECIMAL) == idx));
                        idx *= ASCII_UTILS_BASE_DECIMAL, count--)
                        {
                        }

                        /*
                         * If the value is negative, reduce the count of padding
                         * characters needed.
                         */
                        if(negFlag)
                        {
                            count--;
                        }

                        /*
                         * If the value is negative and the value is padded with
                         * zeros, then place the minus sign before the padding.
                         */
                        if(negFlag && (padChar == '0'))
                        {
                            /* Place the minus sign in the output buffer. */
                            buf[pos++] = '-';

                            /*
                             * The minus sign has been placed, so turn off the
                             * negative flag.
                             */
                            negFlag = FALSE;
                        }

                        /* Provide additional padding at the beginning of the
                         * string conversion if needed.i
                         */
                        if((count > 1) && (count < 16))
                        {
                            for(count--; count; count--)
                            {
                                buf[pos++] = padChar;
                            }
                        }

                        /*
                         * If the value is negative, then place the minus sign
                         * before the number.
i                        */
                        if(negFlag)
                        {
                            /* Place the minus sign in the output buffer. */
                            buf[pos++] = '-';
                        }

                        /* Convert the value into a string. */
                        for(; idx; idx /= ASCII_UTILS_BASE_DECIMAL)
                        {
                            buf[pos++] =
    gpHex[(decValue / idx) % ASCII_UTILS_BASE_DECIMAL];
                        }

                        /* Write the string. */
                        for(idx = 0U; idx < pos; idx++)
                        {
                            CONSOLEUtilsUartPutChar(buf[idx]);
                        }
                        break;
                    }

                    /* Handle the %s command. */
                    case 's':
                    {
                        uint32_t idx = 0U;
                        uint8_t *pStr;

                        /* Get the string pointer from the varargs. */
                        pStr = va_arg(vaArg, uint8_t *);

                        /* Determine the length of the string. */
                        for(idx = 0U; pStr[idx] != '\0'; idx++)
                        {
                            /* Write the string. */
                            CONSOLEUtilsUartPutChar(pStr[idx]);
                        }

                        /* Write any required padding spaces */
                        if(count > idx)
                        {
                            count -= idx;
                            while(count--)
                            {
                                CONSOLEUtilsUartPutChar(' ');
                            }
                        }
                        break;
                    }

                    /* Handle the %u command. */
                    case 'u':
                    {
                        uint32_t unSignDecValue = 0U;
                        uint32_t idx = 0U;
                        uint8_t buf[32];

                        uint64_t unSignDecValue64 = 0;
                        uint64_t idx64 = 0;

                        /* Get the value from the varargs. */
                        if (longQual)
                            unSignDecValue64 = va_arg(vaArg, uint64_t);
                        else
                            unSignDecValue = va_arg(vaArg, uint32_t);

                        if (longQual)
                            for(idx64 = 1;
                    (((idx64 * ASCII_UTILS_BASE_DECIMAL) <= unSignDecValue64)
                    && (((idx64 * ASCII_UTILS_BASE_DECIMAL) /
                    ASCII_UTILS_BASE_DECIMAL) == idx64));
                    idx64 *= ASCII_UTILS_BASE_DECIMAL, count--);

                        else
                            for(idx = 1U;
                    (((idx * ASCII_UTILS_BASE_DECIMAL) <= unSignDecValue) &&
                    (((idx * ASCII_UTILS_BASE_DECIMAL) / ASCII_UTILS_BASE_DECIMAL) == idx));
                    idx *= ASCII_UTILS_BASE_DECIMAL, count--);

                        /*
                         * Provide additional padding at the beginning of the
                         * string conversion if needed.
                         */
                        if((count > 1) && (count < 32))
                        {
                            for(count--; count; count--)
                            {
                                buf[pos++] = padChar;
                            }
                        }

                        /* Convert the value into a string. */
                        if (longQual)
                            for(; idx64; idx64 /= ASCII_UTILS_BASE_DECIMAL)
                            buf[pos++] =
                            gpHex[(unSignDecValue64 / idx64) %
                            ASCII_UTILS_BASE_DECIMAL];
                        else
                            for(; idx; idx /= ASCII_UTILS_BASE_DECIMAL)
                            buf[pos++] = gpHex[(unSignDecValue / idx) %
                            ASCII_UTILS_BASE_DECIMAL];

                        /* Write the string. */
                        for(idx = 0U; idx < pos; idx++)
                        {
                            CONSOLEUtilsUartPutChar(buf[idx]);
                        }
                        break;
                    }

                    /*
                     * Handle the %x and %X commands.  Note that they are treated
                     * identically; i.e. %X will use lower case letters for a-f
                     * instead of the upper case letters it should use.  We also
                     * alias %p to %x.
                     */
                    case 'x':
                    case 'X':
                    case 'p':
                    {
                        uint32_t hexaDecValue = 0U;
                        uint32_t idx = 0U;
                        uint8_t buf[16];

                        /* Get the value from the varargs. */
                        hexaDecValue = va_arg(vaArg, uint32_t);

                        /*
                         * Determine the number of digits in the string version of
                         * the value.
                         */
                        for(idx = 1U;
    (((idx * ASCII_UTILS_BASE_HEXADECIMAL) <= hexaDecValue) &&
  (((idx * ASCII_UTILS_BASE_HEXADECIMAL) / ASCII_UTILS_BASE_HEXADECIMAL) == idx));
    idx *= ASCII_UTILS_BASE_HEXADECIMAL, count--)
                        {
                        }

                        /*
                         * Provide additional padding at the beginning of the
                         * string conversion if needed.
                         */
                        if((count > 1) && (count < 16))
                        {
                            for(count--; count; count--)
                            {
                                buf[pos++] = padChar;
                            }
                        }

                        /* Convert the value into a string. */
                        for(; idx; idx /= ASCII_UTILS_BASE_HEXADECIMAL)
                        {
                            buf[pos++] =
                     gpHex[(hexaDecValue / idx) % ASCII_UTILS_BASE_HEXADECIMAL];
                        }

                        /* Write the string. */
                        for(idx = 0U; idx < pos; idx++)
                        {
                            CONSOLEUtilsUartPutChar(buf[idx]);
                        }
                        break;
                    }

                    /* Handle the %% command. */
                    case '%':
                    {
                        /* Simply write a single %. */
                        CONSOLEUtilsUartPutStr("%");
                        break;
                    }

                    /* Handle all other commands. */
                    default:
                    {
                        /* Indicate an error. */
                        CONSOLEUtilsUartPutStr("ERROR");
                        retStatus = E_FAIL;
                        break;
                    }
                }
            }
        }
    }

    return retStatus;
}

int32_t CONSOLEUtilsUartScanFmt(const char *pString, va_list vaArg)
{
    int32_t retStatus = E_FAIL;
    uint32_t dataType = CONSOLE_UTILS_DATA_TYPE_MAX;
    uint8_t rxBuf[CONSOLE_UTILS_INPUT_SIZE_MAX];
    uint32_t curBufIndex = 0U;
    consoleUtilsBuf_t rxConsoleBuf = {rxBuf,
    &curBufIndex, CONSOLE_UTILS_INPUT_SIZE_MAX};
    void *pVar = NULL;

    if(NULL != pString)
    {
        retStatus = ConsoleUtilsUartBlockingRead(&rxConsoleBuf);

        if(S_PASS == retStatus)
        {
            curBufIndex = 0U;
        }
    }

    /* Loop while there are more characters in the string. */
    while((S_PASS == retStatus) && (*pString != '\0'))
    {
        /* Find the first % character */
        if((*pString == '%') && (S_PASS == retStatus))
        {
            switch(*(++pString))
            {
                /* Handle the %c command. */
                case 'c':
                {
                    /* Get the address of variable from varargs */
                    pVar = va_arg(vaArg, uint8_t *);
                    dataType = CONSOLE_UTILS_DATA_TYPE_CHAR;
                    break;
                }
                /* Handle the %f command. */
                case 'f':
                {
                    /* Get the address of variable from argument */
                    pVar = va_arg(vaArg, double *);
                    dataType = CONSOLE_UTILS_DATA_TYPE_DECIMAL;
                    break;
                }
                /* Handle the %d command. */
                case 'd':
                {
                    /* Get the address of variable from argument */
                    pVar = va_arg(vaArg, int32_t *);
                    dataType = CONSOLE_UTILS_DATA_TYPE_DECIMAL;
                    break;
                }
                /* Handle the %x,%X and %p command. */
                case 'x':
                case 'X':
                case 'p':
                {
                    /* Get the address of variable from varargs */
                    pVar = va_arg(vaArg, uint32_t *);
                    dataType = CONSOLE_UTILS_DATA_TYPE_HEX;
                    break;
                }
                /* Handle the %s command. */
                case 's':
                {
                    /* Get the address of variable from the argument. */
                    pVar = va_arg(vaArg, uint8_t *);
                    dataType = CONSOLE_UTILS_DATA_TYPE_STR;
                    break;
                }
                /* Handles %u command. */
                case 'u':
                {
                    /* Get the address of variable from varargs */
                    pVar = va_arg(vaArg, uint32_t *);
                    dataType = CONSOLE_UTILS_DATA_TYPE_UNSIGN_DECIMAL;
                    break;
                }
                /* Invalid command. */
                default:
                {
                    retStatus = E_FAIL;
                    dataType = CONSOLE_UTILS_DATA_TYPE_MAX;
                    break;
                }
            }

            if(S_PASS == retStatus)
            {
                retStatus = ConsoleUtilsUartDecode(&rxConsoleBuf, pVar, dataType);
            }
        }
        /* Loop continuously until any character other than space. */
        else if((' ' != *pString) && ('\t' != *pString) && ('\b' != *pString) &&
    ('\n' != *pString))
        {
            retStatus = E_FAIL;
        }
        else
        {
        }

        pString++;
    }

    return retStatus;
}

int32_t CONSOLEUtilsUartGetNonBlockingInput(consoleUtilsBuf_t *pRxConsoleBuf,
                                            void *pVar,
                                            uint32_t dataType,
                                            uint32_t *pStatus)
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
                    if(NULL != pStatus)
                    {
                        retStatus = S_PASS;
                    }
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
        uint32_t spinProcess = TRUE;

        /* Check for the spin status to exit on no action. */
        while(TRUE == spinProcess)
        {
            switch(*pStatus)
            {
                /* Initialize the get input operation. */
                case CONSOLE_UTILS_INPUT_STATUS_INIT:
                {
                    *pStatus = CONSOLE_UTILS_INPUT_STATUS_READ;
                    spinProcess = TRUE;
                    break;
                }

                /* Perform read operation. */
                case CONSOLE_UTILS_INPUT_STATUS_READ:
                {
                    int32_t readStatus =
    ConsoleUtilsUartNonBlockingRead(pRxConsoleBuf);

                    /* Exit on no input. */
                    if(CONSOLE_UTILS_READ_STATUS_CONTINUE == readStatus)
                    {
                        spinProcess = FALSE;
                    }
                    /* On termination condition execute decode operation. */
                    else if(CONSOLE_UTILS_READ_STATUS_TERMINATE ==
    readStatus)
                    {
                        *pStatus = CONSOLE_UTILS_INPUT_STATUS_DECODE;
                        *pRxBufIndex = 0U;
                        spinProcess = TRUE;
                    }
                    /* On error exit the get input operation. */
                    else
                    {
                        ConsoleUtilsUartClearBuf(pRxConsoleBuf);
                        *pStatus = CONSOLE_UTILS_INPUT_STATUS_MAX;
                        spinProcess = FALSE;
                        retStatus = E_FAIL;
                    }
                    break;
                }

                /* Perform decode of read input. */
                case CONSOLE_UTILS_INPUT_STATUS_DECODE:
                {
                    int32_t decodeStatus =
    ConsoleUtilsUartDecode(pRxConsoleBuf, pVar, dataType);

                    ConsoleUtilsUartClearBuf(pRxConsoleBuf);
                    *pStatus = CONSOLE_UTILS_INPUT_STATUS_MAX;
                    spinProcess = FALSE;

                    if(S_PASS != decodeStatus)
                    {
                        retStatus = decodeStatus;
                    }
                    break;
                }

                /* Invalid state. */
                case CONSOLE_UTILS_INPUT_STATUS_MAX:
                {
                    spinProcess = FALSE;
                    break;
                }

                /* Error state. */
                default:
                {
                    spinProcess = FALSE;
                    retStatus = E_FAIL;
                    break;
                }
            }
        }
    }

    return retStatus;
}

int32_t CONSOLEUtilsUartGetBlockingInput(consoleUtilsBuf_t *pRxConsoleBuf,
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

    /* Perform data read operation. */
    if(S_PASS == retStatus)
    {
        int32_t readStatus = ConsoleUtilsUartBlockingRead(pRxConsoleBuf);

        if(S_PASS != readStatus)
        {
            ConsoleUtilsUartClearBuf(pRxConsoleBuf);
            retStatus = E_FAIL;
        }
    }

    /* Perform data decode operation. */
    if(S_PASS == retStatus)
    {
        int32_t decodeStatus = E_FAIL;

        *pRxBufIndex = 0U;
        decodeStatus = ConsoleUtilsUartDecode(pRxConsoleBuf, pVar, dataType);

        ConsoleUtilsUartClearBuf(pRxConsoleBuf);

        if(S_PASS != decodeStatus)
        {
            retStatus = E_FAIL;
        }
    }

    return retStatus;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

int32_t ConsoleUtilsUartClearBuf(consoleUtilsBuf_t *pRxConsoleBuf)
{
    uint8_t *pRxBuf = NULL;
    uint32_t *pRxBufIndex = NULL;
    int32_t retStatus = E_FAIL;

    /* Validate input parameters. */
    if(NULL != pRxConsoleBuf)
    {
        pRxBuf = pRxConsoleBuf->pBuf;
        if(NULL != pRxBuf)
        {
            pRxBufIndex = pRxConsoleBuf->curBufIndex;
            if(NULL != pRxBufIndex)
            {
                retStatus = S_PASS;
            }
        }
    }

    if(S_PASS == retStatus)
    {
        if(*pRxBufIndex > pRxConsoleBuf->bufSize)
        {
            retStatus = E_FAIL;
        }
    }

    if(S_PASS == retStatus)
    {
        pRxBuf += *pRxBufIndex;

        /* Clear the contents of buffer. */
        for(; *pRxBufIndex > 0U; *pRxBufIndex -= 1U)
        {
            pRxBuf--;
            *pRxBuf = '\0';
        }
    }

    return retStatus;
}

int32_t ConsoleUtilsUartDecode(consoleUtilsBuf_t *pRxConsoleBuf,
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
            case CONSOLE_UTILS_DATA_TYPE_CHAR:
            {
                uint8_t *pCharVar = pVar;

                /*
                 * Validate the input parameter.
                 */
                if(*pRxBuf != '\0')
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
            case CONSOLE_UTILS_DATA_TYPE_DECIMAL:
            {
                int32_t *pDecVar = (int32_t *) pVar;
                int32_t sign = 1;
                uint8_t rxDigit = '\0';

                /*
                 * Loop continuously until any character other than space.
                 */
                while((' ' == *pRxBuf) || ('\t' == *pRxBuf) || ('\b' == *pRxBuf))
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
                    if(('\0' == *pRxBuf) || ('\n' == *pRxBuf) || ('\r' == *pRxBuf))
                    {
                        retStatus = E_FAIL;
                    }
                }


                if(S_PASS == retStatus)
                {
                    /*
                     * Account for negative numbers.
                     */
                    if('-' == *pRxBuf)
                    {
                        sign = -1;
                        pRxBuf++;
                        (*pRxBufIndex)++;
                    }

                    /*
                     * Validate the start condition of input parameter.
                     */
                    if((uint8_t)E_FAIL == ASCIIUtilsCharToDigit(*pRxBuf, ASCII_UTILS_BASE_DECIMAL))
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
                        rxDigit = ASCIIUtilsCharToDigit(*pRxBuf, ASCII_UTILS_BASE_DECIMAL);

                        /*
                         * Check input is valid decimal digit.
                         */
                        if((uint8_t)E_FAIL != rxDigit)
                        {
                            decVal = (decVal * ASCII_UTILS_BASE_DECIMAL) + rxDigit;
                            pRxBuf++;
                            (*pRxBufIndex)++;
                        }
                    }

                    /*
                     * Apply the sign of the variable.
                     */
                    if((*pRxBuf == '\t') || (*pRxBuf == ' ') || (*pRxBuf == '\n') || (*pRxBuf == '\r') || (*pRxBuf == '\0') || ((*pRxBufIndex == pRxConsoleBuf->bufSize) && (E_FAIL != rxDigit)))
                    {
                        *pDecVar = sign * decVal;
                    }
                }
                break;
            }
            case CONSOLE_UTILS_DATA_TYPE_HEX:
            {
                uint32_t *pHexaDecVar = (uint32_t *) pVar;
                uint8_t rxDigit = '\0';

                /*
                 * Loop continuously until any character other than space.
                 */
                while((' ' == *pRxBuf) || ('\t' == *pRxBuf) || ('\b' == *pRxBuf))
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
                    if(('\0' == *pRxBuf) || ('\n' == *pRxBuf) || ('\r' == *pRxBuf))
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
                    if(('0' == *pRxBuf) && (('X' == *(pRxBuf + 1U)) || ('x' == *(pRxBuf + 1U))))
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
                    if((uint8_t)E_FAIL == ASCIIUtilsCharToDigit(*pRxBuf, ASCII_UTILS_BASE_HEXADECIMAL))
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
                        rxDigit = ASCIIUtilsCharToDigit(*pRxBuf, ASCII_UTILS_BASE_HEXADECIMAL);

                        /*
                         * Check input is valid decimal digit.
                         */
                        if((uint8_t)E_FAIL != rxDigit)
                        {
                            hexaDecVal = (hexaDecVal * ASCII_UTILS_BASE_HEXADECIMAL) + rxDigit;
                            pRxBuf++;
                            (*pRxBufIndex)++;
                        }
                    }

                    if((*pRxBuf == '\t') || (*pRxBuf == ' ') || (*pRxBuf == '\n') || (*pRxBuf == '\r') || (*pRxBuf == '\0') || ((*pRxBufIndex == pRxConsoleBuf->bufSize) && (E_FAIL != rxDigit)))
                    {
                        *pHexaDecVar = hexaDecVal;
                    }
                }
                break;
            }
            case CONSOLE_UTILS_DATA_TYPE_UNSIGN_DECIMAL:
            {
                uint32_t *pUnsignDecVar = (uint32_t *) pVar;
                uint8_t rxDigit = '\0';

                /*
                 * Loop continuously until any character other than space.
                 */
                while((' ' == *pRxBuf) || ('\t' == *pRxBuf) || ('\b' == *pRxBuf))
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
                    if(('\0' == *pRxBuf) || ('\n' == *pRxBuf) || ('\r' == *pRxBuf))
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
                    if((uint8_t)E_FAIL == ASCIIUtilsCharToDigit(*pRxBuf, ASCII_UTILS_BASE_DECIMAL))
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
                        rxDigit = ASCIIUtilsCharToDigit(*pRxBuf, ASCII_UTILS_BASE_DECIMAL);

                        /*
                         * Check input is valid decimal digit.
                         */
                        if((uint8_t)E_FAIL != rxDigit)
                        {
                            unSignDecVal = (unSignDecVal * ASCII_UTILS_BASE_DECIMAL) + rxDigit;
                            pRxBuf++;
                            (*pRxBufIndex)++;
                        }
                    }

                    if((*pRxBuf == '\t') || (*pRxBuf == ' ') || (*pRxBuf == '\n') || (*pRxBuf == '\r') || (*pRxBuf == '\0') || ((*pRxBufIndex == pRxConsoleBuf->bufSize) && (E_FAIL != rxDigit)))
                    {
                        *pUnsignDecVar = unSignDecVal;
                    }
                }
                break;
            }
            case CONSOLE_UTILS_DATA_TYPE_STR:
            {
                uint8_t *pStrVar = pVar;

                /*
                 * Validate the input parameter.
                 */
                if(*pRxBuf != '\0')
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
                    while((*pRxBuf != '\t') && (*pRxBuf != ' ') && (*pRxBuf != '\n') && (*pRxBuf != '\r') && (*pRxBuf != '\0') && (*pRxBufIndex < pRxConsoleBuf->bufSize))
                    {
                        *pStrVar = *pRxBuf;
                        pRxBuf++;
                        pStrVar++;
                        (*pRxBufIndex)++;
                    }

                    *pStrVar = '\0';
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

/**
 * \brief   This function selects the UART pins for use. The UART pins
 *          are multiplexed with pins of other peripherals in the SoC
 *
 * \note    This pin multiplexing depends on the profile in which the EVM
 *          is configured.
 */
void ConsoleUtilsUartPinMuxSetup(uint32_t consoleUartInstNum)
{
#if defined(AM335X_FAMILY_BUILD)
    switch (consoleUartInstNum)
    {
        case 1:
            /* RXD */
            HW_WR_REG32(SOC_CONTROL_REGS + CONTROL_CONF_UART_RXD(1),
                    (0U | CONTROL_CONF_UART0_RXD_CONF_UART0_RXD_PUTYPESEL |
                    CONTROL_CONF_UART0_RXD_CONF_UART0_RXD_RXACTIVE));

            /* TXD */
            HW_WR_REG32(SOC_CONTROL_REGS + CONTROL_CONF_UART_TXD(1),
                    0U | CONTROL_CONF_UART0_TXD_CONF_UART0_TXD_PUTYPESEL);
            break;
        case 3:
            /* RXD */
            HW_WR_REG32(SOC_CONTROL_REGS + CONTROL_CONF_MII1_RXD3,
                (1U | CONTROL_CONF_UART0_RXD_CONF_UART0_RXD_PUTYPESEL |
                 CONTROL_CONF_UART0_RXD_CONF_UART0_RXD_RXACTIVE));

            /* TXD */
            HW_WR_REG32(SOC_CONTROL_REGS + CONTROL_CONF_MII1_RXD2,
                1U | CONTROL_CONF_UART0_TXD_CONF_UART0_TXD_PUTYPESEL);
            break;

        case 5:
            /* RXD */
            HW_WR_REG32(SOC_CONTROL_REGS + CONTROL_CONF_LCD_DATA(9),
                (4U | CONTROL_CONF_UART0_RXD_CONF_UART0_RXD_PUTYPESEL |
                CONTROL_CONF_UART0_RXD_CONF_UART0_RXD_RXACTIVE));

            /* TXD */
            HW_WR_REG32(SOC_CONTROL_REGS + CONTROL_CONF_LCD_DATA(8),
                4U | CONTROL_CONF_UART0_TXD_CONF_UART0_TXD_PUTYPESEL);
            break;

        case 0:
        default:
            /* RXD */
            HW_WR_REG32(SOC_CONTROL_REGS + CONTROL_CONF_UART_RXD(0),
                (CONTROL_CONF_UART0_RXD_CONF_UART0_RXD_PUTYPESEL |
                 CONTROL_CONF_UART0_RXD_CONF_UART0_RXD_RXACTIVE));

            /* TXD */
            HW_WR_REG32(SOC_CONTROL_REGS + CONTROL_CONF_UART_TXD(0),
               CONTROL_CONF_UART0_TXD_CONF_UART0_TXD_PUTYPESEL);
            break;
}
#elif defined(AM43XX_FAMILY_BUILD)
    switch (consoleUartInstNum)
    {
        case 0:
        default:
            /* RXD */
            HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_CONF_UART0_RXD),
                (CTRL_CONF_UART0_RXD_PUTYPESEL_MASK |
                 CTRL_CONF_UART0_RXD_RXACTIVE_MASK));

            /* TXD */
            HW_WR_REG32((SOC_CONTROL_MODULE_REG + CTRL_CONF_UART0_TXD),
                CTRL_CONF_UART0_TXD_PUTYPESEL_MASK);
            break;
    }
#endif /* if defined(AM335X_FAMILY_BUILD) */
}

int32_t ConsoleUtilsUartBlockingRead(consoleUtilsBuf_t *pRxConsoleBuf)
{
    int32_t retStatus = E_FAIL;
    uint8_t *pRxBuf = NULL;
    uint32_t *pRxBufIndex = NULL;
    uint8_t rxByte = 0xFF;

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
        int32_t readStatus = CONSOLE_UTILS_READ_STATUS_CONTINUE;

        pRxBuf += *pRxBufIndex;

        /* Clear Residual Characters */
        while(CONSOLE_UTILS_READ_STATUS_CONTINUE == readStatus)
        {
            UARTGetChar(gConsoleUtilsUartInstAddr, &rxByte, UART_WAIT_FOREVER);

            if((('\n' == rxByte) || ('\r' == rxByte)))
            {
                *pRxBuf = '\n';
                pRxBuf++;
                *pRxBufIndex += 1U;
                readStatus = CONSOLE_UTILS_READ_STATUS_TERMINATE;
                CONSOLEUtilsUartPutChar('\n');
                CONSOLEUtilsUartPutChar('\r');
            }
            else if(*pRxBufIndex == (pRxConsoleBuf->bufSize - 1U))
            {
                *pRxBuf = rxByte;
                pRxBuf++;
                *pRxBufIndex += 1U;
                readStatus = CONSOLE_UTILS_READ_STATUS_TERMINATE;
                CONSOLEUtilsUartPutChar(rxByte);
                CONSOLEUtilsUartPutChar('\n');
                CONSOLEUtilsUartPutChar('\r');
            }
            /*
             * Account for the backspace to allow user edit the input.
             */
            else if('\b' == rxByte)
            {
                if(*pRxBufIndex > 0U)
                {
                    uint8_t prevRxByte = 0xFF;
                    uint32_t idx = 0U;
                    uint32_t cnt = 0U;

                    pRxBuf--;
                    prevRxByte = (uint8_t)*pRxBuf;
                    *pRxBuf = '\0';
                    *pRxBufIndex -= 1U;

                    if('\t' == prevRxByte)
                    {
                        cnt = 4U;
                    }
                    else if(prevRxByte < ' ')
                    {
                        cnt = 3U;
                    }
                    else
                    {
                        cnt = 1U;
                    }

                    for(idx = 0U; idx < cnt; idx++)
                    {
                        CONSOLEUtilsUartPutChar('\b');
                        CONSOLEUtilsUartPutChar(' ');  /* To clear the character */
                        CONSOLEUtilsUartPutChar('\b');
                    }
                }
                readStatus = CONSOLE_UTILS_READ_STATUS_CONTINUE;
            }
            /*
             * Read the printable characters.
             */
            else if(((rxByte >= ' ') && (rxByte <= '~')) || ('\t' == rxByte))
            {
                *pRxBuf = (uint8_t)rxByte;
                pRxBuf++;
                *pRxBufIndex += 1U;
                readStatus = CONSOLE_UTILS_READ_STATUS_CONTINUE;
                CONSOLEUtilsUartPutChar(rxByte);
            }
            /*
             * Read the non-printable characters.
             */
            else if(rxByte < ' ')
            {
                *pRxBuf = (uint8_t)rxByte;
                pRxBuf++;
                *pRxBufIndex += 1U;
                readStatus = CONSOLE_UTILS_READ_STATUS_CONTINUE;
                CONSOLEUtilsUartPutChar('^');
                CONSOLEUtilsUartPutChar(rxByte + '@');
            }
            /*
             * Skip other characters.
             */
            else
            {
                readStatus = CONSOLE_UTILS_READ_STATUS_CONTINUE;
            }
        }

        if(CONSOLE_UTILS_READ_STATUS_TERMINATE != readStatus)
        {
            retStatus = E_FAIL;
        }
    }

    return retStatus;
}

int32_t ConsoleUtilsUartNonBlockingRead(consoleUtilsBuf_t *pRxConsoleBuf)
{
    int32_t retStatus = E_FAIL;
    uint8_t *pRxBuf = NULL;
    uint32_t *pRxBufIndex = NULL;
    uint8_t rxByte = '\0';

    /* Validate input parameters. */
    if(NULL != pRxConsoleBuf)
    {
        pRxBuf = pRxConsoleBuf->pBuf;
        if(NULL != pRxBuf)
        {
            pRxBufIndex = pRxConsoleBuf->curBufIndex;
            if(NULL != pRxBufIndex)
            {
                retStatus = CONSOLE_UTILS_READ_STATUS_CONTINUE;
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

    if(CONSOLE_UTILS_READ_STATUS_CONTINUE == retStatus)
    {
        pRxBuf += *pRxBufIndex;

        /* Clear Residual Characters */
        while((CONSOLE_UTILS_READ_STATUS_CONTINUE == retStatus) &&
                (TRUE == UARTIsCharAvail(gConsoleUtilsUartInstAddr)))
        {
            UARTGetChar(gConsoleUtilsUartInstAddr, &rxByte, UART_WAIT_FOREVER);

            if((('\n' == rxByte) || ('\r' == rxByte)))
            {
                *pRxBuf = '\n';
                pRxBuf++;
                *pRxBufIndex += 1U;
                retStatus = CONSOLE_UTILS_READ_STATUS_TERMINATE;
                CONSOLEUtilsUartPutChar('\n');
                CONSOLEUtilsUartPutChar('\r');
            }
            else if(*pRxBufIndex == (pRxConsoleBuf->bufSize - 1U))
            {
                *pRxBuf = rxByte;
                pRxBuf++;
                *pRxBufIndex += 1U;
                retStatus = CONSOLE_UTILS_READ_STATUS_TERMINATE;
                CONSOLEUtilsUartPutChar(rxByte);
                CONSOLEUtilsUartPutChar('\n');
                CONSOLEUtilsUartPutChar('\r');
            }
            /*
             * Account for the backspace to allow user edit the input.
             */
            else if('\b' == rxByte)
            {
                if(*pRxBufIndex > 0U)
                {
                    uint8_t prevRxByte = 0xFF;
                    uint32_t idx = 0U;
                    uint32_t cnt = 0U;

                    pRxBuf--;
                    prevRxByte = (uint8_t)*pRxBuf;
                    *pRxBuf = '\0';
                    *pRxBufIndex -= 1U;

                    if('\t' == prevRxByte)
                    {
                        cnt = 4U;
                    }
                    else if(prevRxByte < ' ')
                    {
                        cnt = 3U;
                    }
                    else
                    {
                        cnt = 1U;
                    }

                    for(idx = 0U; idx < cnt; idx++)
                    {
                        CONSOLEUtilsUartPutChar('\b');
                        CONSOLEUtilsUartPutChar(' ');  /* To clear the character */
                        CONSOLEUtilsUartPutChar('\b');
                    }
                }
                retStatus = CONSOLE_UTILS_READ_STATUS_CONTINUE;
            }
            /*
             * Read the printable characters.
             */
            else if(((rxByte >= ' ') && (rxByte <= '~')) || ('\t' == rxByte))
            {
                *pRxBuf = (uint8_t)rxByte;
                pRxBuf++;
                *pRxBufIndex += 1U;
                retStatus = CONSOLE_UTILS_READ_STATUS_CONTINUE;
                CONSOLEUtilsUartPutChar(rxByte);
            }
            /*
             * Read the non-printable characters.
             */
            else if(rxByte < ' ')
            {
                *pRxBuf = (uint8_t)rxByte;
                pRxBuf++;
                *pRxBufIndex += 1U;
                retStatus = CONSOLE_UTILS_READ_STATUS_CONTINUE;
                CONSOLEUtilsUartPutChar('^');
                CONSOLEUtilsUartPutChar(rxByte + '@');
            }
            /*
             * Skip other characters.
             */
            else
            {
                retStatus = CONSOLE_UTILS_READ_STATUS_CONTINUE;
            }
        }
    }

    return retStatus;
}

