/**
 * \file   board_priv.h
 *
 * \brief  This file contains module-private information for the board module.
 * It includes I2C slave addresses for all devices
 *
 */

/*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef BOARD_PRIV_H
#define BOARD_PRIV_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "board.h"

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief I2C address of the EEPROM. */
#define BOARD_EEPROM_I2C_ADDR_0         (0x50U)

/** \brief I2C address of the LED. */
#define BOARD_LED_I2C_ADDR_2         	(0x60U)

/** \brief I2C address of the LED. */
#define BOARD_OLED_I2C_ADDR_0         	(0x3CU)

/** \brief I2C address of rotary switch. */
#define BOARD_ROTARY_SW_ADDR_0         	(0x41U)

/** \brief I2C address of the Temperature Sensor. */
#define BOARD_TMP275_I2C_ADDR_0         (0x48U)

/** \brief I2C address of the Accelerometer Sensor. */
#define BOARD_LIS331DLH_I2C_ADDR_0      (0x18U)

/** \brief I2C address of the AIC31. */
#define BOARD_AIC31_I2C_ADDR_0          (0x1BU)

/** \brief I2C address of TPS65910A (PMIC - control). */
#define BOARD_PMIC_CTRL_I2C_ADDR_0      (0x2DU)
/** \brief I2C address of TPS65910A (PMIC - SR). */
#define BOARD_PMIC_SR_I2C_ADDR_1        (0x12U)

/** \brief I2C address of IP Expander. */
#define BOARD_IO_EXP_I2C_ADDR_0         (0x21u)
/* TBD: Check for other IO expanders. */

/* Defines specific to on-board peripherals */
/* TBD: Add if any. */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

typedef struct boardCommonObj
{
    boardId_t  boardId;
    /**< Board ID. For valid values see #boardId_t. */
    uint32_t baseBoardRev;
    /**< Base Board revision. */
    uint32_t dcBoardRev;
    /**< Daughter card board revision. */
} boardCommonObj_t;


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */


#ifdef __cplusplus
}
#endif

#endif  /* #ifndef BOARD_PRIV_H */

/* @} */
