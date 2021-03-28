/**
 * \file    dal_misc.c
 *
 * \brief   This file contains implementations for miscellaneous
 *          functions used commonly by the DAL.
 *
 */

/**
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
#include "dal_misc.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief  Macro to specify the Decimal base value */
#define   BASE_DECIMAL                      (10U)

/** \brief Macro to indicate the Mask value to identify the lower nibble. */
#define   NIBBLE_MASK                       (0x0FU)

/** \brief Macro specifying the lower nibble shift value. */
#define   NIBBLE_SHIFT                       (4U)

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

uint32_t MISCBcdToDec(uint32_t bcdNum)
{
    uint32_t decNum = 0U;
    uint32_t multiplier = 1U;

    while(bcdNum > 0U)
    {
        decNum += (bcdNum & NIBBLE_MASK) * multiplier;
        multiplier = multiplier * BASE_DECIMAL;
        bcdNum = bcdNum >> NIBBLE_SHIFT;
    }

    return decNum;
}

uint32_t MISCDecToBcd(uint32_t decNum)
{
    uint32_t bcdNum = 0U;
    uint32_t digit = 0U;
    uint32_t count = 0U;

    while(decNum > 0U)
    {
        digit = (decNum % 10);
        bcdNum += (digit << (NIBBLE_SHIFT * count));
        count++;
        decNum = (decNum/BASE_DECIMAL);
    }

    return bcdNum;
}
