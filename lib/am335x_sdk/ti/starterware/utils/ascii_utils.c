/**
 *  \file  ascii_utils.c
 *
 * \brief  This file contain functions which compute ASCII for standard
 *         operations.
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

#include <types.h>
#include "ascii_utils.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint8_t ASCIIUtilsCharToDigit(uint8_t byte, uint32_t base)
{
    uint8_t retVal = (uint8_t)E_FAIL;

    if((ASCII_UTILS_BASE_DECIMAL == base) ||
        (ASCII_UTILS_BASE_HEXADECIMAL == base))
    {
        /* For numbers from 0x0 to 0x9.*/
        if((byte >= 48U) && (byte <= 57U))
        {
            retVal = byte - 48U;
        }
        /* For alphabets from A to F.*/
        else if((ASCII_UTILS_BASE_HEXADECIMAL == base) && (byte >= 'A') &&
            (byte <= 'F'))
        {
            retVal = byte - 55U; /* 55 = ('0' + ('A' - '9' - 1)) */
        }
        /* For alphabets from a to f.*/
        else if((ASCII_UTILS_BASE_HEXADECIMAL == base) && (byte >= 'a') &&
            (byte <= 'f'))
        {
           retVal = byte - 87U; /* 87 = ('0' + ('a' - '9' - 1)) */
        }
    }

    return retVal;
}

uint8_t ASCIIUtilsDigitToChar(uint8_t byte, uint32_t base)
{
    uint8_t retVal = (uint8_t)E_FAIL;
    uint8_t nibble = 0x0FU & byte;

    if((ASCII_UTILS_BASE_DECIMAL == base) ||
        (ASCII_UTILS_BASE_HEXADECIMAL == base))
    {
        /* For numbers from 0x0 to 0x9.*/
        if(nibble <= 9U)
        {
            retVal = nibble + 48U;
        }
        /* For alphabets from A to F.*/
        else if((base == ASCII_UTILS_BASE_HEXADECIMAL) && (nibble >= 10) &&
            (nibble <= 15))
        {
            retVal = nibble + 55U; /* 55 = ('0' + ('A' - '9' - 1)) */
        }
    }

    return retVal;
}

int32_t ASCIIUtilsStrToEthrAddr(uint8_t *pStrInput, uint8_t *pEthAddr)
{
    int32_t retVal = E_FAIL;
    uint32_t index = 0U;
    uint8_t lower = 0U;
    uint8_t upper = 0U;

    if((NULL != pStrInput) && (NULL != pEthAddr))
    {
        retVal = S_PASS;
    }

    if(S_PASS == retVal)
    {
        for(index = 0U; ((S_PASS == retVal) && (index < 6U)); index++)
        {
            lower = ASCIIUtilsCharToDigit(pStrInput[3U * index + 1U],
                        ASCII_UTILS_BASE_HEXADECIMAL);
            upper = ASCIIUtilsCharToDigit(pStrInput[3U * index],
                        ASCII_UTILS_BASE_HEXADECIMAL);

            if(((5U != index) && ('-' != pStrInput[3U * index + 2U])) ||
                ((uint8_t)E_FAIL == lower) || ((uint8_t)E_FAIL == upper))
            {
                retVal = E_FAIL;
            }
        }
    }

    if(S_PASS == retVal)
    {
        for(index = 0U; index < 6U; index++)
        {
            lower = ASCIIUtilsCharToDigit(pStrInput[3U * index + 1U],
                        ASCII_UTILS_BASE_HEXADECIMAL);
            upper = ASCIIUtilsCharToDigit(pStrInput[3U * index],
                        ASCII_UTILS_BASE_HEXADECIMAL);
            pEthAddr[index] = (upper << 4U) | lower;
        }
    }

    return retVal;
}

int32_t ASCIIUtilsEthrAddrToStr(uint8_t *pEthrAddrInput, uint8_t *pStrOutput)
{
    int32_t retVal = E_FAIL;
    uint32_t index = 0U;
    uint8_t lower = 0U;
    uint8_t upper = 0U;

    if((NULL != pStrOutput) && (NULL != pEthrAddrInput))
    {
        retVal = S_PASS;
    }

    if(S_PASS == retVal)
    {
        for(index = 0U; ((S_PASS == retVal) && (index < 6U)); index++)
        {
            upper = ASCIIUtilsDigitToChar(pEthrAddrInput[index] >> 4U,
                        ASCII_UTILS_BASE_HEXADECIMAL);
            lower = ASCIIUtilsDigitToChar(pEthrAddrInput[index],
                        ASCII_UTILS_BASE_HEXADECIMAL);

            if(((uint8_t)E_FAIL == lower) || ((uint8_t)E_FAIL == upper))
            {
                retVal = E_FAIL;
            }
        }
    }

    if(S_PASS == retVal)
    {
        for(index = 0U; index < 6U; index++)
        {
            upper = ASCIIUtilsDigitToChar(pEthrAddrInput[index] >> 4U,
                        ASCII_UTILS_BASE_HEXADECIMAL);
            lower = ASCIIUtilsDigitToChar(pEthrAddrInput[index],
                        ASCII_UTILS_BASE_HEXADECIMAL);

            pStrOutput[3U * index + 1U] = lower;
            pStrOutput[3U * index] = upper;

            if(index == 5U)
            {
                pStrOutput[3U * index + 2U] = '\0';
            }
            else
            {
                pStrOutput[3U * index + 2U] = '-';
            }
        }
    }

    return retVal;
}

int32_t ASCIIUtilsTimeToStr(uint32_t timeInput, uint8_t *pStrOutput)
{
    int32_t retVal = E_FAIL;
    uint32_t index = 0U;
    uint8_t lower = 0U;
    uint8_t upper = 0U;

    if((NULL != pStrOutput))
    {
        retVal = S_PASS;
    }

    if(S_PASS == retVal)
    {
        for(index = 0U; ((S_PASS == retVal) && (index < 3U)); index++)
        {
            upper = ASCIIUtilsDigitToChar(timeInput >> (8U * index + 12U),
                        ASCII_UTILS_BASE_DECIMAL);
            lower = ASCIIUtilsDigitToChar(timeInput >> (8U * index + 8U),
                        ASCII_UTILS_BASE_DECIMAL);

            if(((uint8_t)E_FAIL == lower) && ((uint8_t)E_FAIL == upper))
            {
                retVal = E_FAIL;
            }
        }
    }

    if(S_PASS == retVal)
    {
        for(index = 0U; index < 3U; index++)
        {
            upper = ASCIIUtilsDigitToChar(timeInput >> (8U * index + 12U),
                        ASCII_UTILS_BASE_DECIMAL);
            lower = ASCIIUtilsDigitToChar(timeInput >> (8U * index + 8U),
                        ASCII_UTILS_BASE_DECIMAL);
            pStrOutput[3U * (2U - index) + 1U] = lower;
            pStrOutput[3U * (2U - index)] = upper;

            if(index == 0)
            {
                pStrOutput[3U * (2U - index) + 2U] = '\0';
            }
            else
            {
                pStrOutput[3U * (2U - index) + 2U] = ':';
            }
        }
    }

    return retVal;
}

int32_t ASCIIUtilsDateToStr(uint32_t dateInput, uint8_t *pStrOutput)
{
    int32_t retVal = E_FAIL;
    uint32_t index = 0U;
    uint8_t lower = 0U;
    uint8_t upper = 0U;

    if((NULL != pStrOutput))
    {
        retVal = S_PASS;
    }

    if(S_PASS == retVal)
    {
        for(index = 0U; ((S_PASS == retVal) && (index < 3U)); index++)
        {
            upper = ASCIIUtilsDigitToChar(dateInput >> (8U * index + 12U),
                        ASCII_UTILS_BASE_DECIMAL);
            lower = ASCIIUtilsDigitToChar(dateInput >> (8U * index + 8U),
                        ASCII_UTILS_BASE_DECIMAL);

            if(((uint8_t)E_FAIL == lower) && ((uint8_t)E_FAIL == upper))
            {
                retVal = E_FAIL;
            }
        }
    }

    if(S_PASS == retVal)
    {
        for(index = 0U; index < 3U; index++)
        {
            upper = ASCIIUtilsDigitToChar(dateInput >> (8U * index + 12U),
                        ASCII_UTILS_BASE_DECIMAL);
            lower = ASCIIUtilsDigitToChar(dateInput >> (8U * index + 8U),
                        ASCII_UTILS_BASE_DECIMAL);
            pStrOutput[3U * (2U - index) + 1U] = lower;
            pStrOutput[3U * (2U - index)] = upper;

            if(index == 0)
            {
                pStrOutput[3U * (2U - index) + 2U] = '\0';
            }
            else
            {
                pStrOutput[3U * (2U - index) + 2U] = '/';
            }
        }
    }

    return retVal;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */

uint8_t ASCIIToDigit(uint8_t byte, uint32_t base)
{
    return ASCIIUtilsCharToDigit(byte, base);
}

uint8_t DigitToASCII(uint8_t byte, uint32_t base)
{
    return ASCIIUtilsDigitToChar(byte, base);
}

int32_t StrToEthrAddr(uint8_t *pStrInput, uint8_t *pEthAddr)
{
    return ASCIIUtilsStrToEthrAddr(pStrInput, pEthAddr);
}

int32_t EthrAddrToStr(uint8_t *pEthrAddrInput, uint8_t *pStrOutput)
{
    return ASCIIUtilsEthrAddrToStr(pEthrAddrInput, pStrOutput);
}

int32_t TimeToStr(uint32_t timeInput, uint8_t *pStrOutput)
{
    return ASCIIUtilsTimeToStr(timeInput, pStrOutput);
}

int32_t DateToStr(uint32_t dateInput, uint8_t *pStrOutput)
{
    return ASCIIUtilsDateToStr(dateInput, pStrOutput);
}
