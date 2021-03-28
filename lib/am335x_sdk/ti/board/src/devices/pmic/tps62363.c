/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 *   \file    tps62363.c
 *
 *   \brief   This file contains the default API's for configuring TPS62363
 *            PMIC.
 *
 */

#include "tps62363.h"

/**
 * \brief   Conversion of VOUT code to millivolt.
 *
 * This function is used to convert the VOUT code read from the PMIC
 * registers to millivolt.
 *
 * \param   voutCode        [IN]    VOUT code in hexadecimal
 * \param   millivolt       [OUT]   Voltage in millivolt
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps62363ConvertVolt(uint8_t voutCode,
                                       uint16_t *millivolt)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint16_t baseMillivolt = 500, millivoltStep = 10;


    if(millivolt == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if(voutCode >= 0x80)
    {
        return BOARD_INVALID_PARAM;
    }
    *millivolt = (baseMillivolt + (voutCode * millivoltStep));

    return boardStatus;
}

/**
 * \brief   Conversion of millivolt to VOUT code.
 *
 * This function is used to convert the millivolt value to VOUT code
 * to write into the PMIC registers.
 *
 * \param   millivolt       [IN]    Voltage in millivolt
 * \param   voutCode        [OUT]   VOUT code in hexadecimal
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps62363ConvertVoutCode(uint16_t millivolt,
                                           uint8_t *voutCode)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint16_t baseMillivolt = 500, millivoltStep = 10;

    if(voutCode == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    if((millivolt % millivoltStep) || (millivolt < baseMillivolt))
    {
        return BOARD_INVALID_PARAM;
    }

    *voutCode = (millivolt - baseMillivolt) / millivoltStep;

    if(*voutCode >= 0x80)
    {
        return BOARD_INVALID_PARAM;
    }

    return boardStatus;
}

/**
 * \brief   TPS63263 set voltage function.
 *
 * This function is used to set the voltage to the power resource of
 * the TPS63263.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS62363 slave address
 * \param   powerResource   [IN]    TPS62363 Power resource
 *                                  Valid values: BOARD_TPS62363_SET0_VOUT
                                                  BOARD_TPS62363_SET1_VOUT
                                                  BOARD_TPS62363_SET2_VOUT
                                                  BOARD_TPS62363_SET3_VOUT
 * \param   millivolt       [IN]    Voltage in millivolt
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
 Board_STATUS Board_tps62363SetVoltage(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t powerResource,
                                      uint16_t millivolt)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t voutCode;

    if((handle == NULL) || 
       (powerResource > BOARD_TPS62363_SET3_VOUT))
    {
        return BOARD_INVALID_PARAM;
    }

    boardStatus = Board_tps62363ConvertVoutCode(millivolt, &voutCode);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     powerResource,
                                     &voutCode,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }
    return boardStatus;
}

