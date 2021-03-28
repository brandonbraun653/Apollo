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
 * \file  ds90ub925.h
 *
 * \brief This file includes the structures, enums and register offsets
 *        for configuring the ds90ub925 serailizer.
 *
 */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD 
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB925 DS90UB925 FPD-Link Library
 *
 *  Provides the interfaces for configuring DS90UB925 FPD-Link device.
 *
 *  @{
 *
 */
/* @} */

#ifndef _DS90UB925_H_
#define _DS90UB925_H_

#include <ti/board/src/devices/common/common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD_DS90UB925
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB925_TYPES Data Types
 *
 *  Data types used by DS90UB925 FPD-Link device library.
 *
 *  @{
 *
 */
 
/** ub925 remote serializer slave address */
#define BOARD_FPD_UB925_I2C_SLV_ADDR                           (0x1BU)

/** Serializer Register Offset Address */
/** Configuration1 register address */
#define BOARD_FPD_UB925_CONFIGURATION1_REG_ADDR                  (0x04U)
/** General status register address */
#define BOARD_FPD_UB925_GENERAL_STATUS_REG_ADDR                  (0x0CU)
/** Data path control register address */
#define BOARD_FPD_UB925_DATA_PATH_CONTROL_REG_ADDR               (0x12U)

/** RGB DE gate field shift count */
#define BOARD_FPD_UB925_RGB_DE_GATE_SHIFT_CNT                    (4U)
/** I2S channel-B override field shift count */
#define BOARD_FPD_UB925_I2S_CHANNEL_B_OVERRIDE_SHIFT_CNT         (3U)
/** RGB 18-bit mode field shift count */
#define BOARD_FPD_UB925_RGB_18BIT_MODE_SHIFT_CNT                 (2U)
/** Transport select field shift count */
#define BOARD_FPD_UB925_I2S_TRANSPOER_SEL_SHIFT_CNT              (1U)
/** I2S channel-B enable field shift count */
#define BOARD_FPD_UB925_I2S_CHANNEL_B_ENABLE_SHIFT_CNT           (0U)
/** PCLK status field shift count */
#define BOARD_FPD_UB925_PCLK_STATUS_SHIFT_CNT                    (2U)

/** RGB DE gate field bit mask */
#define BOARD_FPD_UB925_RGB_DE_GATE_BIT_MASK                     (uint8_t)(0x01 << BOARD_FPD_UB925_RGB_DE_GATE_SHIFT_CNT)
/** I2S channel-B override field bit mask */
#define BOARD_FPD_UB925_I2S_CHANNEL_B_OVERRIDE_BIT_MASK          (uint8_t)(0x01 << BOARD_FPD_UB925_I2S_CHANNEL_B_OVERRIDE_SHIFT_CNT)
/** RGB 18-bit mode field bit mask */
#define BOARD_FPD_UB925_RGB_18BIT_MODE_BIT_MASK                  (uint8_t)(0x01 << BOARD_FPD_UB925_RGB_18BIT_MODE_SHIFT_CNT)
/** Transport select field bit mask */
#define BOARD_FPD_UB925_I2S_TRANSPOER_SEL_BIT_MASK               (uint8_t)(0x01 << BOARD_FPD_UB925_I2S_TRANSPOER_SEL_SHIFT_CNT)
/** I2S channel-B enable field bit mask */
#define BOARD_FPD_UB925_I2S_CHANNEL_B_ENABLE_BIT_MASK            (uint8_t)(0x01 << BOARD_FPD_UB925_I2S_CHANNEL_B_ENABLE_SHIFT_CNT)
/** PCLK status field bit mask */
#define BOARD_FPD_UB925_PCLK_STATUS_BIT_MASK                     (uint8_t)(0x01 << BOARD_FPD_UB925_PCLK_STATUS_SHIFT_CNT)

/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD_DS90UB925
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB925_APIS Application Interfaces
 *
 *  Application Interfaces provided by DS90UB925 FPD-Link device library.
 *
 *  @{
 *
 */

/**
 * \brief  RGB gate data enable mode control
 *
 *  This function is used for configuring the serializer
 *  RGB gate DE mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb925SetRGBGateDEModeCtrl(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t cfgMode);

/**
 * \brief  I2S channel-B mode control
 *
 *  This function is used for configuring the serializer
 *  I2S channel-B mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb925SetI2SChBModeCtrl(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t cfgMode);


/**
 * \brief  I2S channel-B override mode control
 *
 *  This function is used for configuring the serializer
 *  I2S channel-B override mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb925SetI2SChBOverrideModeCtrl(void *handle,
                                                     Board_FpdModuleObj *fpdModParams,
                                                     uint8_t cfgMode);

/**
 * \brief  I2S transport select mode control
 *
 *  This function is used for configuring the serializer
 *  I2S transport select mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb925SetI2STransSelModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t cfgMode);

/**
 * \brief  RGB 18-bit mode control
 *
 *  This function is used for configuring the serializer
 *  RGB 18-bit mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb925SetRGB18bitModeCtrl(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               uint8_t cfgMode);

/**
 * \brief  Get PCLK lock status
 *
 * This function is used for reading the serializer PCLK
 * lock status
 *
 * \param   handle         [IN]       Low level driver handle
 * \param   fpdModParams   [IN]       FPD module parameters
 * \param   pclkLockStatus [IN/OUT]   Buffer to hold PLL lock status
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb925GetPCLKLockStatus(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            bool *pclkLockStatus);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DS90UB925_H_ */

/* @} */
