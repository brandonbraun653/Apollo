/**
 * \file   am335x_beaglebone_dcards.h
 *
 * \brief  This file provides LCD4 specific daughter card data for am335x.
 *
 * \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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

#ifndef DCARD_AM335X_LCD4_
#define DCARD_AM335X_LCD4_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "lcdc.h"
#include "lcd_device.h"
#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

typedef enum dCardRevAm335xLCD4_t
{
    DCARD_REV_AM335X_LCD4_MIN,
    /**< Should be the first value of this enumeration. */
    DCARD_REV_AM335X_LCD4_UNKNOWN = DCARD_REV_AM335X_LCD4_MIN,
    /**< Unknown/unsupported dCard revision. */
    DCARD_REV_AM335X_LCD4_A1,
    /**< Board revision A1. */
    DCARD_REV_AM335X_LCD4_MAX = DCARD_REV_AM335X_LCD4_A1
    /**< Max board revision. */
} dCardRevAm335xLCD4_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/* None */
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief This object contains details of LCD4 daughter card. */
extern const dCardData_t gDCardAm335xLCD4Data;
#ifdef __cplusplus
}
#endif /* ifdef __cplusplus */

#endif  /* #ifndef BOARD_AM335X_BEAGLEBONE_ */
