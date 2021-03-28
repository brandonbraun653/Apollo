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
 * \file  ds90ub960.h
 *
 * \brief This file includes the structures, enums and register offsets
 *        for configuring the ds90ub960 deserailizer.
 *
 */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD 
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB960 DS90UB960 FPD-Link Library
 *
 *  Provides the interfaces for configuring DS90UB960 FPD-Link device.
 *
 *  @{
 *
 */
/* @} */

#ifndef _DS90UB960_H_
#define _DS90UB960_H_

#include <ti/board/src/devices/common/common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD_DS90UB960
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB960_TYPES Data Types
 *
 *  Data types used by DS90UB960 FPD-Link device library.
 *
 *  @{
 *
 */

/** Serializer address */
#define BOARD_FPD_UB953_PORT_0_SER_ALIAS_ADDR                   (0x74U)
/** Sensor address */
#define BOARD_PORT_0_SENSOR_ALIAS_ADDR                          (0x40U)
/** Serializer address */
#define BOARD_FPD_UB953_PORT_1_SER_ALIAS_ADDR                   (0x76U)
/** Sensor address */
#define BOARD_PORT_1_SENSOR_ALIAS_ADDR                          (0x42U)
/** Serializer address */
#define BOARD_FPD_UB953_PORT_2_SER_ALIAS_ADDR                   (0x78U)
/** Sensor address */
#define BOARD_PORT_2_SENSOR_ALIAS_ADDR                          (0x44U)
/** Serializer address */
#define BOARD_FPD_UB953_PORT_3_SER_ALIAS_ADDR                   (0x7AU)
/** Sensor address */
#define BOARD_PORT_3_SENSOR_ALIAS_ADDR                          (0x46U)

/**
 *  \anchor DESUB960_patternType
 *  \name   Pattern type for generation
 *  \brief  Id for pattern generation.
 *
 *  @{
 */
/** \brief Pattern type: RGB888 1280x720 30fps */
#define BOARD_FPD_UB960_PG_RGB888_1280_720_30_FPS             ((uint32_t) 0x0U)
/** \brief Pattern type: RGB888 1920x1080 30fps */
#define BOARD_FPD_UB960_PG_RGB888_1920_1080_30_FPS            ((uint32_t) 0x1U)
/** \brief Pattern type: RGB888 1920x1080 30fps from UB953*/
#define BOARD_FPD_UB960_UB953_PG_RGB888_1920_1080_30_FPS      ((uint32_t) 0x2U)
/** \brief Pattern type: Maximum Val */
#define BOARD_FPD_UB960_PG_MAX                                ((uint32_t) 0x3U)
/* @} */

/**
 *  \anchor BOARD_csiInst
 *  \name   CSIRX Module instance
 *  \brief  CSIRX Module instance used to get the I2C instance.
 *
 *  @{
 */
/** \brief CSIRX Instance: 0 */
#define BOARD_CSI_INST_0             ((uint32_t) 0x0U)
/** \brief CSIRX Instance: 1 */
#define BOARD_CSI_INST_1             ((uint32_t) 0x1U)
/* @} */

/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD_DS90UB960
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB960_APIS Application Interfaces
 *
 *  Application Interfaces provided by DS90UB960 FPD-Link device library.
 *
 *  @{
 *
 */

/**
 * \brief UB960 register write function
 *
 * \param   handle      [IN]  I2C driver handle
 * \param   slaveAddr   [IN]  Device slave address
 * \param   regAddr     [IN]  Register offset address
 * \param   regData     [IN]  Register data
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb960WriteReg(void *handle,
                                    uint32_t slaveAddr,
                                    uint8_t regAddr,
                                    uint8_t regData);

/**
 * \brief UB960 register read fuunction
 *
 * \param   handle      [IN]  I2C driver handle
 * \param   slaveAddr   [IN]  Device slave address
 * \param   regAddr     [IN]  Register offset address
 * \param   regData     [OUT]  Register data pointer
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb960ReadReg(void *handle,
                                   uint32_t slaveAddr,
                                   uint8_t regAddr,
                                   uint8_t *regData);
/**
 * \brief  Get ub960 i2c address.
 *
 * This function is used to get the I2C address and
 * channel details of UB960 module.
 *
 * \param   chNum     [IN]  buffer to hold i2c channel number
 * \param   i2cAddr   [IN]  buffer to hold i2c address
 * \param   csiInst   [IN]  CSIRX Instance
 *                          See \ref BOARD_csiInst for more details.
 *
 * \return  In case of wrong parameters, chNum and i2cAddr are sent back as '0'.
 */
void Board_fpdU960GetI2CAddr(uint8_t *chNum,
                             uint8_t *i2cAddr,
                             uint32_t csiInst);

/**
 * \brief  FPD ub960 pattern generation configurations.
 *
 * This function is used for configuring the pattern generator for FPD UB960
 *
 * \param   handle          [IN]  Low level driver handle
 * \param   fpdModParams    [IN]  FPD module params
 * \param   pgType          [IN]  Pattern Generation Type
 *                                See \ref DESUB960_patternType for details.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb960CfgPG(void *handle,
                                 Board_FpdModuleObj *fpdModParams,
                                 uint32_t pgType);

/**
 * \brief  Initializes the FPD UB960 module.
 *
 * This function is used to initialize the fpd ub960 module
 *
 * \param   handle         [IN]  Low level driver handle
 * \param   fpdModParams   [IN]  FPD module params
] *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb960DesInit(void *handle,
                                   Board_FpdModuleObj *fpdModParams);

/**
 * \brief  Initializes the FPD UB960 module for OV2775 sensor module.
 *
 * This function is used to initialize the fpd ub960 module for OV2775 sensor
 *
 * \param   handle         [IN]  Low level driver handle
 * \param   fpdModParams   [IN]  FPD module params
] *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb960DesInitFusionBoardTIDA1130(void *handle,
                                            Board_FpdModuleObj *fpdModParams);

/**
 * \brief  FPD ub960 configurations.
 *
 * This function is used for configuring the FPD UB960 de-serializer
 *
 * \param   handle          [IN]  Low level driver handle
 * \param   fpdModParams    [IN]  FPD module params
 * \param   ub960Cfg        [IN]  Configuration Info
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb960Cfg(void *handle,
                               Board_FpdModuleObj *fpdModParams,
                               Board_I2cRegProgObj *ub960Cfg);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DS90UB960_H_ */

/* @} */
