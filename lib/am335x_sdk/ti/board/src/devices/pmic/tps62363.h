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
 * \file   tps62363.h
 *
 * \brief  The macro definitions, structures and function prototypes for
 *         configuring TPS62363 PMIC.
 *
 *
 */

#ifndef _TPS62363_H_
#define _TPS62363_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>

#include <ti/board/board.h>

#include <ti/board/src/devices/common/common.h>

#ifdef __cplusplus
extern "C" {
#endif

/** BUCK Power resource Register Offsets */
#define BOARD_TPS62363_SET0_VOUT                           (0x00U)
#define BOARD_TPS62363_SET1_VOUT                           (0x01U)
#define BOARD_TPS62363_SET2_VOUT                           (0x02U)
#define BOARD_TPS62363_SET3_VOUT                           (0x03U)

/** I2C number of bytes */
#define BOARD_I2C_NUM_OF_BYTES_01                           (1U)
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
                                      uint16_t millivolt);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _TPS63262_H_ */

/* Nothing past this point */
