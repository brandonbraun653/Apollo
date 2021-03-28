/**
 *  @file  UART_ascii_utils.c
 *
 *  @brief  This file contain functions which compute ASCII for standard
 *         operations.
 *
 *         Copyright (C) 2014-2015 Texas Instruments Incorporated -
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
#include <stdint.h>
#include <ti/drv/uart/src/UART_ascii_utils.h>
#include <ti/drv/uart/src/UART_utils_defs.h>
#include <ti/drv/uart/UART_stdio.h>
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

uint8_t UART_ASCIIUtils_charToDigit(uint8_t byte, uint32_t base)
{
    uint8_t retVal = (uint8_t)E_FAIL;

    if((UART_ASCII_UTILS_BASE_DECIMAL == base) ||
        (UART_ASCII_UTILS_BASE_HEXADECIMAL == base))
    {
        /* For numbers from 0x0 to 0x9.*/
        if((byte >= 48U) && (byte <= 57U))
        {
            retVal = byte - 48U;
        }
        /* For alphabets from A to F.*/
        else if((UART_ASCII_UTILS_BASE_HEXADECIMAL == base) && (byte >= ((uint8_t)('A'))) &&
            (byte <= ((uint8_t)('F'))))
        {
            retVal = byte - 55U; /* 55 = ('0' + ('A' - '9' - 1)) */
        }
        /* For alphabets from a to f.*/
        else if((UART_ASCII_UTILS_BASE_HEXADECIMAL == base) && (byte >= ((uint8_t)('a'))) &&
            (byte <= ((uint8_t)('f'))))
        {
           retVal = byte - 87U; /* 87 = ('0' + ('a' - '9' - 1)) */
        } 
        else 
        {
           retVal = (uint8_t)E_FAIL;
        }
    }

    return retVal;
}
