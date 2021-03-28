/*
 *  Copyright (C) 2013-2018 Texas Instruments Incorporated - http://www.ti.com/
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
 * \file   uartConfig.c
 *
 * \brief  This file contains functions which interface interactively
 *         with the user through the serial console to perform some
 *         utility operations.
 */

#include <stdint.h>
#include <stdarg.h>
#include <uartConfig.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/example/utils/common/inc/app_utils.h>

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* A mapping from an integer between 0 and 15 to its ASCII character
 * equivalent. */
static const char *const g_pcHex = "0123456789abcdef";

/*****************************************************************************
**                    FUNCTION DEFINITIONS
*****************************************************************************/

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
 * \brief   This function initializes the specified UART instance for use for
 *          console operations.
 *
 * \param   baseAddr    Base Address of UART instance.
 *
 * \return  None.
 *
 */
#if defined (SOC_K2G) || defined(SOC_K2K)||defined(SOC_K2H)||defined(SOC_K2L)||defined(SOC_K2E)||defined(SOC_C6678)||defined(SOC_C6657)
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
#else
void UARTConfigInit(uint32_t baseAddr, uint32_t baudRate, uint32_t wordLength,
                    uint32_t stopBit, uint32_t parity, uint32_t mode)
{
    uint32_t divisorValue = 0U, fifoConfig = 0U;

    /* Performing a module reset. */
    UARTModuleReset(baseAddr);

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
    fifoConfig = UART_FIFO_CONFIG(UART_TRIG_LVL_GRANULARITY_4,
                                  UART_TRIG_LVL_GRANULARITY_1,
                                  UART_FCR_TX_TRIG_LVL_56,
                                  1,
                                  1,
                                  1,
                                  UART_DMA_EN_PATH_SCR,
                                  UART_DMA_MODE_0_ENABLE);

    /* Configuring the FIFO settings. */
    UARTFIFOConfig(baseAddr, fifoConfig);

    /* Performing Baud Rate settings. */
    /* Computing the Divisor Value. */
    divisorValue = UARTDivisorValCompute(UART_MODULE_INPUT_CLK,
                                         baudRate,
                                         mode,
                                         UART_MIR_OVERSAMPLING_RATE_42);
    /* Programming the Divisor Latches. */
    UARTDivisorLatchWrite(baseAddr, divisorValue);

    /* Switching to Configuration Mode B. */
    UARTRegConfigModeEnable(baseAddr, UART_REG_CONFIG_MODE_B);

    /* Programming the Line Characteristics. */
    UARTLineCharacConfig(baseAddr, (wordLength | stopBit), parity);

    /* Disabling write access to Divisor Latches. */
    UARTDivisorLatchDisable(baseAddr);

    /* Disabling Break Control. */
    UARTBreakCtl(baseAddr, UART_BREAK_COND_DISABLE);

    /* Uart enable */
    UARTOperatingModeSelect(baseAddr, mode);
}
#endif

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
#if defined (SOC_K2G) || defined(SOC_K2K)||defined(SOC_K2H)||defined(SOC_K2L)||defined(SOC_K2E)||defined(SOC_C6678)||defined(SOC_C6657)
    UART_charPut_v0(baseAddr, byteTx);
#else
    UARTCharPut(baseAddr, byteTx);
#endif
}

/**
 * \brief   This function reads a byte entered on the serial console.
 *
 * \param   baseAddr    Base Address of UART instance.
 *
 * \return  Returns the entered byte typecasted as an unsigned character.
 */

uint8_t UARTConfigGetc(uint32_t baseAddr)
{
#if defined (SOC_K2G) || defined(SOC_K2K)||defined(SOC_K2H)||defined(SOC_K2L)||defined(SOC_K2E)||defined(SOC_C6678)||defined(SOC_C6657)
    return UART_charGet_v0(baseAddr);
#else
    return UARTCharGet(baseAddr);
#endif
}

/**
 *  \brief   This function reads a byte entered on the serial console in a
 *           non-blocking way.
 *
 *  \param   baseAddr    Base Address of UART instance.
 *
 *  \return  Returns -1 if no char read. 0 if a char is read.
 */

int8_t UARTGetcNonBlocking(uint32_t baseAddr)
{
#if defined (SOC_K2G) || defined(SOC_K2K)||defined(SOC_K2H)||defined(SOC_K2L)||defined(SOC_K2E)||defined(SOC_C6678)||defined(SOC_C6657)
    return UART_charGetNonBlocking_v0(baseAddr);
#else
    return UARTCharGetNonBlocking(baseAddr);
#endif
}

#if defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_TDA2EX) || defined (SOC_TDA3XX)
/**
 * \brief   This function reads a byte entered on the serial console within the
 *          timeout period specified in msec.
 *
 * \param   baseAddr    Base Address of UART instance.
 * \param   msec        timeout value in msec.
 *
 * \return  Returns the entered byte typecasted as an unsigned character.
 */

int8_t UARTConfigGetcTimeout(uint32_t baseAddr, int8_t *ch, uint32_t msec)
{
    int32_t  retVal = STW_SOK;
    uint32_t startCount, elapsedCount, cycleDelay;
    int32_t  status;

    /* To config 32K Counter in run state when A15(Tda2xx)/M4(Tda3xx) is
     * halted */
    AppUtils_appConfig32KCounterSuspendState();

    retVal     = AppUtils_appGet32KCounterValue(&startCount);
    cycleDelay = (msec * APPUTILS_APP_32K_TIMER_FREQ) / 1000U;
    do
    {
        *ch = UARTGetcNonBlocking(baseAddr);
        if (*ch !=  -((int32_t) 1))
        {
            retVal = STW_SOK;
            break;
        }
        retVal = STW_EFAIL;
        status = AppUtils_appGetElapsedValue(startCount, &elapsedCount);
    } while ((STW_SOK == status) && (elapsedCount <= cycleDelay));

    return (retVal);
}
#endif

/**
 * \brief  This function writes data from a specified buffer onto the
 *         transmitter FIFO of UART.
 *
 * \param  baseAddr         Base Address of UART instance.
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
 *            it is interpreted as a new line(\n) + carraige return(\r)
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
uint32_t UARTConfigPuts(uint32_t baseAddr, const char *pTxBuffer,
                        int32_t numBytesToWrite)
{
    uint32_t count = 0U;
    uint32_t flag  = 0U;

    if (numBytesToWrite < 0)
    {
        flag = 1U;
    }

    while ('\0' != *pTxBuffer)
    {
        /* Checks if data is a newline character. */
        if ('\n' == *pTxBuffer)
        {
            /* Ensuring applicability to serial console.*/
            UARTConfigPutc(baseAddr, '\r');
            UARTConfigPutc(baseAddr, '\n');
        }
        else
        {
            UARTConfigPutc(baseAddr, (uint8_t) *pTxBuffer);
        }
        pTxBuffer++;
        count++;
        if ((0U == flag) && (count == numBytesToWrite))
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
 * \param  baseAddr         Base Address of UART instance.
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

uint32_t UARTConfigGets(uint32_t baseAddr, char *pRxBuffer,
                        int32_t numBytesToRead)
{
    int32_t  count = 0;
    uint32_t flag  = 0U;
    uint8_t  tmp;

    if (numBytesToRead < 0)
    {
        flag = 1U;
    }
    do
    {
        *pRxBuffer = (char) UARTConfigGetc(baseAddr);

        /*
        ** 0xD - ASCII value of Carriage Return.
        ** 0x1B - ASCII value of ESC character.
        */
        tmp = (uint8_t)*pRxBuffer;
        if (0xDU == tmp || 0x1BU == tmp)
        {
            *pRxBuffer = '\0';
            break;
        }

        /* Echoing the typed character back to the serial console. */
        UARTConfigPutc(baseAddr, (uint8_t) *pRxBuffer);
        pRxBuffer++;
        count++;
        if (0U == flag && (count == numBytesToRead))
        {
            break;
        }
    } while (1U);

    return count;
}

/**
 *  \brief   This function prints the specified numbers(positive or negative)
 *           on the serial console.
 *
 *  \param   baseAddr   Base Address of UART instance.
 *  \param   value      The number to be printed on the serial console.
 *
 *  \return  None.
 *
 *  \note    The numbers that this function can print should lie in the
 *           following range:
 *           [-2^(31)] to [2^(31) - 1] i.e.
 *           0x80000000 to  0x7FFFFFFF
 *
 */

void UARTConfigPutNum(uint32_t baseAddr, int32_t value)
{
    uint8_t  num[10]  = {0U};
    uint32_t quotient = 0U;
    uint32_t dividend = 0U;
    int32_t  count    = 0;

    if (value < 0)
    {
        UARTConfigPutc(baseAddr, '-');
        /*
        ** Making the negative number as positive.
        ** This is done to simplify further processing and printing.
        */
        value = -value;
    }

    dividend = value;
    do
    {
        quotient   = dividend / 10U;
        num[count] = (uint8_t) (dividend % 10U);
        if (0U == quotient)
        {
            break;
        }
        count++;
        dividend = quotient;
    } while (count < 10);

    /* If we exceed limit, reduce and print from actual digits */
    if (count == 10)
    {
        count--;
    }

    /* Printing the digits. */
    do
    {
        /* We add 0x30 to a digit to obtain its respective ASCII value.*/
        UARTConfigPutc(baseAddr, num[count--] + 0x30);
    } while (count >= 0);
}

/**
 * \brief   This function reads the numbers typed on the serial console.
 *
 * \param   baseAddr    Base Address of UART instance.
 * \return  The value entered on the serial console.
 *
 * \note   The numbers that this function can recieve should lie in the
 *          following range:
 *          [-2^(31)] to [2^(31) - 1] i.e.
 *          0x80000000 to  0x7FFFFFFF
 *
 */

int32_t UARTConfigGetNum(uint32_t baseAddr)
{
    char    rxByte;
    int32_t sign  = 1;
    int32_t value = 0;

    rxByte = (char) UARTConfigGetc(baseAddr);

    /* Accounting for negative numbers.*/
    if ('-' == rxByte)
    {
        UARTConfigPutc(baseAddr, '-');
        sign = (-(int32_t)1);
    }
    else
    {
        UARTConfigPutc(baseAddr, (uint8_t) rxByte);
        value = value * 10U + ((uint8_t)rxByte - 0x30U);
    }

    do
    {
        rxByte = (char) UARTConfigGetc(baseAddr);

        /* Echoing the typed characters to the serial console.*/
        UARTConfigPutc(baseAddr, (uint8_t) rxByte);
        /*
        ** Checking if the entered character is a carriage return.
        ** Pressing the 'Enter' key on the keyboard executes a
        ** carriage return on the serial console.
        */
        if ('\r' == rxByte)
        {
            break;
        }
        /*
        ** Subtracting 0x30 to convert the representation of the digit
        ** from ASCII to hexadecimal.
        */
        value = value * 10U + ((uint8_t)rxByte - 0x30U);
    } while (1);

    /* Accounting for the sign of the number.*/
    value = value * sign;

    return value;
}

/**
 * \brief  This function is used to print hexadecimal numbers on the serial
 *         console.
 *
 * \param  baseAddr   Base Address of UART instance.
 * \param  hexValue   The Hexadecimal number to be printed.
 *
 * \return None
 */
void UARTConfigPutHexNum(uint32_t baseAddr, uint32_t hexValue)
{
    uint8_t  num[8]   = {0};
    uint32_t quotient = 0U;
    uint32_t dividend = 0U;
    int32_t  count    = 0;

    dividend = hexValue;

    do
    {
        quotient   = dividend / 16U;
        num[count] = (uint8_t) (dividend % 16U);
        if (0U == quotient)
        {
            break;
        }
        count++;
        dividend = quotient;
    } while (count < 8);

    /* If we exceed limit, reduce and print from actual digits */
    if (count == 8)
    {
        count--;
    }

    UARTConfigPutc(baseAddr, (uint8_t)'0');
    UARTConfigPutc(baseAddr, (uint8_t)'x');

    while (count >= 0)
    {
        /* Checking for alphanumeric numbers. */
        if ((16 - num[count]) <= 6U)
        {
            /* Printing alphanumeric numbers. */
            UARTConfigPutc(baseAddr, num[count--] + 0x37U);
        }
        else
        {
            /* Printing numbers in the range 0 to 9. */
            UARTConfigPutc(baseAddr, num[count--] + 0x30U);
        }
    }
}

/**
 * \brief   This function receives hexadecimal numbers entered on the serial
 *          console of the host machine.
 *
 * \param   None
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

uint32_t UARTConfigGetHexNum(uint32_t baseAddr)
{
    char     rxByte;
    uint32_t value = 0U;
    uint32_t loopIndex;
    uint32_t byteCount = 0U;

    for (loopIndex = 0U; loopIndex < 2U; loopIndex++)
    {
        /* Receiving bytes from the host machine through serial console. */
        rxByte = (char) UARTConfigGetc(baseAddr);

        /*
        ** Checking if the entered character is a carriage return.
        ** Pressing the 'Enter' key on the keyboard executes a
        ** carriage return on the serial console.
        */
        if ('\r' == rxByte)
        {
            break;
        }

        /*
        ** Checking if the character entered is one among the alphanumeric
        ** character set A,B,C...F
        */
        if (('A' <= rxByte) && (rxByte <= 'F'))
        {
            /* Echoing the typed characters to the serial console.*/
            UARTConfigPutc(baseAddr, (uint8_t) rxByte);
            value = value * 16U + ((uint8_t) rxByte - 0x37U);
            byteCount++;
        }
        /*
        ** Checking if the character entered is one among the alphanumeric
        ** character set a,b,c...f
        */
        else if (('a' <= rxByte) && (rxByte <= 'f'))
        {
            UARTConfigPutc(baseAddr, (uint8_t) rxByte);
            value = value * 16U + ((uint8_t)rxByte - 0x57U);
            byteCount++;
        }
        /*
        ** Checking if the character entered is one among the decimal
        ** number set 0,1,2,3,....9
        */
        else if (('0' <= rxByte) && ((uint8_t)rxByte <= '9'))
        {
            UARTConfigPutc(baseAddr, (uint8_t) rxByte);
            value = value * 16U + ((uint8_t)rxByte - 0x30U);
            byteCount++;
        }
        /*
        ** Checking if the character is either a 'x'(lower-case) or an 'X'
        ** (upper-case).
        */
        else if (('x' == rxByte) || ('X' == rxByte))
        {
            UARTConfigPutc(baseAddr, (uint8_t) rxByte);
            value = 0U;
            break;
        }
    }

    if (0U == value)
    {
        byteCount = 0U;
    }

    do
    {
        rxByte = (char) UARTConfigGetc(baseAddr);

        if ('\r' == rxByte)
        {
            break;
        }

        /*
        ** Checking if the character entered is one among the alphanumeric
        ** character set A,B,C...F
        */
        if (('A' <= rxByte) && (rxByte <= 'F'))
        {
            UARTConfigPutc(baseAddr, (uint8_t) rxByte);
            value = value * 16U + ((uint8_t)rxByte - 0x37U);
            byteCount++;
        }
        /*
        ** Checking if the character entered is one among the alphanumeric
        ** character set a,b,c...f
        */
        else if (('a' <= rxByte) && (rxByte <= 'f'))
        {
            UARTConfigPutc(baseAddr, (uint8_t) rxByte);
            value = value * 16U + ((uint8_t)rxByte - 0x57U);
            byteCount++;
        }
        /*
        ** Checking if the character entered is one among the decimal
        ** number set 0,1,2,3,....9
        */
        else if (('0' <= rxByte) && (rxByte <= '9'))
        {
            UARTConfigPutc(baseAddr, (uint8_t) rxByte);
            value = value * 16U + ((uint8_t)rxByte - 0x30U);
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
    } while (byteCount < 8U);

    return value;
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
void UARTConfigvPrintf(uint32_t baseAddr, const char *pcString, va_list vaArgP)
{
    uint32_t ulIdx, ulValue, ulPos, ulCount, ulBase, ulNeg;
    char    *pcStr, pcBuf[16], cFill;
    char     digitCnt;

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
                    char tempValue;
                    /* Get the value from the varargs. */
                    ulValue   = va_arg(vaArgP, uint32_t);
                    tempValue = (char) ulValue;

                    /* Print out the character. */
                    UARTwrite(baseAddr, &tempValue, (uint32_t) 1);

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
}

/******************************* End of file *********************************/
