/**
 *  \file  ascii_utils.h
 *
 * \brief  This file contains the prototypes of the functions present in
 *         utils/ascii_utils.c
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

#ifndef ASCII_UTILS_H_
#define ASCII_UTILS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <types.h>
#include <error.h>
#include <misc.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Base of the decimal number system. */
#define ASCII_UTILS_BASE_DECIMAL                (10U)

/** \brief Base of the hexadecimal number system. */
#define ASCII_UTILS_BASE_HEXADECIMAL            (16U)

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
 *                - ASCII_UTILS_BASE_DECIMAL for Decimal.
 *                - ASCII_UTILS_BASE_HEXADECIMAL for Hexadecimal.
 *
 * \retval  decimal Hexadecimal (0x0 - 0xF) or decimal (0 - 9) number.
 * \retval  0xFF    Not a valid ASCII value of digit.
 */
uint8_t ASCIIUtilsCharToDigit(uint8_t byte, uint32_t base);

/**
 * \brief   This function gives the ASCII value of a digit to hexadecimal
 *          or decimal number.
 *
 * \param   byte  Hexadecimal or decimal digit. Upper 4-bits are don't care.
 *                - Hexadecimal digits (0x0 - 0xF).
 *                - Decimal digits (0 - 9).
 * \param   base  Base value selection of input.
 *                - ASCII_UTILS_BASE_DECIMAL for Decimal.
 *                - ASCII_UTILS_BASE_HEXADECIMAL for Hexadecimal.
 *
 * \retval  digit  ASCII value of Hexadecimal ('0' - '9', 'A' - 'F') or decimal
 *                 digits ('0' - '9') digits.
 * \retval  0xFF   Not a valid digit.
 */
uint8_t ASCIIUtilsDigitToChar(uint8_t byte, uint32_t base);

/**
 * \brief   This function converts string to hexadecimal Ethernet Address.
 *          '-' is expected as delimitter like "01-23-45-67-89-ab".
 *
 * \param   pStrInput  Input String of Ethernet Address.
 * \param   pEthAddr   Hexadecimal Ethernet Address output.
 *
 * \retval  S_PASS  Success.
 * \retval  E_FAIL  Failed to convert.
 */
int32_t ASCIIUtilsStrToEthrAddr(uint8_t *pStrInput, uint8_t *pEthAddr);

/**
 * \brief   This function converts Ethernet Address to string. '-' is provide
 *          as delimitter like "01-23-45-67-89-ab".
 *
 * \param   pEthrAddrInput  Hexadecimal Ethernet Address output.
 * \param   pStrOutput      Output String of Ethernet Address.
 *
 * \retval  S_PASS  Success.
 * \retval  E_FAIL  Failed to convert.
 */
int32_t ASCIIUtilsEthrAddrToStr(uint8_t *pEthrAddrInput, uint8_t *pStrOutput);

/**
 * \brief   This function converts Time to string.
 *
 * \param   timeInput      Time input as [15:8]-Sec, [23:16]-Min, [31:24]-Hour.
 * \param   pStrOutput     Output String of Time in "HH:MM:SS".
 *
 * \retval  S_PASS  Success.
 * \retval  E_FAIL  Failed to convert.
 */
int32_t ASCIIUtilsTimeToStr(uint32_t timeInput, uint8_t *pStrOutput);

/**
 * \brief  This function converts Date to string.
 *
 * \param   dateInput      Date input as ([15:8]-Year,[23:16]-Mon,[31:24]-Day).
 * \param   pStrOutput     Output String of Date "DD/MM/YY".
 *
 * \retval  S_PASS  Success.
 * \retval  E_FAIL  Failed to convert.
 */
int32_t ASCIIUtilsDateToStr(uint32_t dateInput, uint8_t *pStrOutput);

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */

/**
 * \brief   This function converts the ASCII value of a digit to hexadecimal
 *          or decimal number.
 */
DEPRECATED(uint8_t ASCIIToDigit(uint8_t byte, uint32_t base));

/**
 * \brief   This function gives the ASCII value of a digit to hexadecimal
 *          or decimal number.
 */
DEPRECATED(uint8_t DigitToASCII(uint8_t byte, uint32_t base));

/**
 * \brief   This function converts string to hexadecimal Ethernet Address.
 *          '-' is expected as delimitter like "01-23-45-67-89-ab".
 */
DEPRECATED(int32_t StrToEthrAddr(uint8_t *pStrInput, uint8_t *pEthAddr));

/**
 * \brief   This function converts Ethernet Address to string. '-' is provide
 *          as delimitter like "01-23-45-67-89-ab".
 */
DEPRECATED(int32_t EthrAddrToStr(uint8_t *pEthrAddrInput, uint8_t *pStrOutput));

/**
 * \brief   This function converts Time to string.
 */
DEPRECATED(int32_t TimeToStr(uint32_t timeInput, uint8_t *pStrOutput));

/**
 * \brief  This function converts Date to string.
 */
DEPRECATED(int32_t DateToStr(uint32_t dateInput, uint8_t *pStrOutput));

#ifdef __cplusplus
}
#endif

#endif /* #ifndef ASCII_UTILS_H_ */
