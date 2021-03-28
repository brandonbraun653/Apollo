/**
 *  \file  UART_ascii_utils.h
 *
 * \brief  This file contains the prototypes of the functions present in
 *         src/UART_ascii_utils.c
 *
 *         Copyright (C) 2014 Texas Instruments Incorporated -
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

#ifndef ASCII_UTILS_H_
#define ASCII_UTILS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Base of the decimal number system. */
#define UART_ASCII_UTILS_BASE_DECIMAL                (10U)

/** \brief Base of the hexadecimal number system. */
#define UART_ASCII_UTILS_BASE_HEXADECIMAL            (16U)

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
 * \brief   This function converts the ASCII value of a digit to hexadecimal
 *          or decimal number.
 *
 * \param   byte  ASCII value of a digit.
 *                - Decimal digits ('0' - '9').
 *                - Hexadecimal digits ('0' - '9', 'A' - 'F' or 'a' - 'f').
 * \param   base  Base value selection of input.
 *                - UART_ASCII_UTILS_BASE_DECIMAL for Decimal.
 *                - UART_ASCII_UTILS_BASE_HEXADECIMAL for Hexadecimal.
 *
 * \retval  decimal Hexadecimal (0x0 - 0xF) or decimal (0 - 9) number.
 * \retval  0xFF    Not a valid ASCII value of digit.
 */
uint8_t UART_ASCIIUtils_charToDigit(uint8_t byte, uint32_t base);




#ifdef __cplusplus
}
#endif

#endif /* #ifndef ASCII_UTILS_H_ */
