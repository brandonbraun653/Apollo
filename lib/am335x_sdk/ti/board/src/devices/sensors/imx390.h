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
 * \file  imx390.h
 *
 * This file includes the structures, enums and register offsets
 * for initializing the remote FPD imx390 camera sensor device.
 *
 */
 
/**
 *
 *  \ingroup BOARD_LIB_DEVICES_SENSOR 
 *
 *  \defgroup BOARD_LIB_DEVICES_SENSOR_IMX390 IMX390 Sensor Device Library
 *
 *  @{
 *
 */
/* @} */

#ifndef _IMX390_H_
#define _IMX390_H_
 
#include <ti/board/src/devices/common/common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_SENSOR_IMX390
 *
 *  \defgroup BOARD_LIB_DEVICES_SENSOR_IMX390_TYPES Data Types
 *
 *  Data types used by IMX390 sensor device library
 *
 *  @{
 *
 */

#define BOARD_IMX390_AE_CONTROL_LONG_REG_ADDR_LOW                   (0x000C)
#define BOARD_IMX390_AE_CONTROL_LONG_REG_ADDR_HIGH                  (BOARD_IMX390_AE_CONTROL_LONG_REG_ADDR_LOW + 1)
#define BOARD_IMX390_AE_CONTROL_LONG_REG_ADDR_TOP                   (BOARD_IMX390_AE_CONTROL_LONG_REG_ADDR_HIGH + 1)

#define BOARD_IMX390_AE_CONTROL_SHORT_REG_ADDR_LOW                  (0x0010)
#define BOARD_IMX390_AE_CONTROL_SHORT_REG_ADDR_HIGH                 (BOARD_IMX390_AE_CONTROL_SHORT_REG_ADDR_LOW + 1)
#define BOARD_IMX390_AE_CONTROL_SHORT_REG_ADDR_MSB                  (BOARD_IMX390_AE_CONTROL_SHORT_REG_ADDR_HIGH + 1)

#define BOARD_IMX390_SP1H_ANALOG_GAIN_CONTROL_REG_ADDR              (0x0018U)
#define BOARD_IMX390_SP1H_ANALOG_GAIN_CONTROL_REG_ADDR_HIGH         (BOARD_IMX390_SP1H_ANALOG_GAIN_CONTROL_REG_ADDR + 1U)

#define BOARD_IMX390_SP1L_ANALOG_GAIN_CONTROL_REG_ADDR              (0x001AU)
#define BOARD_IMX390_SP1L_ANALOG_GAIN_CONTROL_REG_ADDR_HIGH         (BOARD_IMX390_SP1L_ANALOG_GAIN_CONTROL_REG_ADDR + 1U)

/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_SENSOR_IMX390
 *
 *  \defgroup BOARD_LIB_DEVICES_SENSOR_IMX390_APIS Application Interfaces
 *
 *  Application Interfaces provided by IMX390 sensor device library
 *
 *  @{
 *
 */

/**
 * \brief  Initializes the imx390 camera sensor device
 *
 * This function is used to initialize the imx390 camera sensor module
 *
 * \param   handle         [IN]  Low level driver handle
 * \param   rmtSlvParams   [IN]  Remote slave params
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_imx390CamCfg(void *handle,
                                Board_FpdRmtDevObj *rmtSlvParams);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _IMX390_H_ */

/* @} */
