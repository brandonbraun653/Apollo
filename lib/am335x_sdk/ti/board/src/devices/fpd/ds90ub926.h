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
 * \file  ds90ub926.h
 *
 * \brief This file includes the structures, enums and register offsets
 *        for configuring the ds90ub926 deserailizer.
 *
 */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD 
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB926 DS90UB926 FPD-Link Library
 *
 *  Provides the interfaces for configuring DS90UB926 FPD-Link device.
 *
 *  @{
 *
 */
/* @} */

#ifndef _DS90UB926_H_
#define _DS90UB926_H_

#include <ti/board/src/devices/common/common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD_DS90UB926
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB926_TYPES Data Types
 *
 *  Data types used by DS90UB926 FPD-Link device library.
 *
 *  @{
 *
 */

/** ub926 deserializer i2c instance number */
#define BOARD_FPD_UB926_I2C_INSTANCE                                  (0x03U)

/** ub926 deserializer i2c slave address */
#define BOARD_FPD_UB926_I2C_SLV_ADDR                                  (0x2CU)


/** I2C device Id register address */
#define BOARD_FPD_UB926_I2C_DEVICE_ID_REG_ADDR                        (0x00U)
/** Deserializer reset register address */
#define BOARD_FPD_UB926_RESET_REG_ADDR                                (0x01U)
/** Configuration register address */
#define BOARD_FPD_UB926_CONFIGURATION1_REG_ADDR                       (0x03U)

/** Freeze device Id register address */
#define BOARD_FPD_UB926_DES_FREEZE_DEVID_REG_ADDR                     (0x01)
/** I2C control1 register address */
#define BOARD_FPD_UB926_I2C_CONTROL1_REG_ADDR                         (0x05U)

/** Remote device Id register address */
#define BOARD_FPD_UB926_REMOTE_DEVICE_ID_REG_ADDR                     (0x07U)

/** Slave ID0 register address */
#define BOARD_FPD_UB926_SLAVE_ID0_REG_ADDR                            (0x08U)

/** Slave alias0 register address */
#define BOARD_FPD_UB926_SLAVE_ALIAS0_REG_ADDR                         (0x10U)

/** General status register address */
#define BOARD_FPD_UB926_GENERAL_STATUS_REG_ADDR                       (0x1CU)
/** Data path control register address */
#define BOARD_FPD_UB926_DATA_PATH_CONTROL_REG_ADDR                    (0X22U)
/** SCL high time register address */
#define BOARD_FPD_UB926_SCL_HIGH_TIME_REG_ADDR                        (0x26U)
/** SCL low time register address */
#define BOARD_FPD_UB926_SCL_LOW_TIME_REG_ADDR                         (0x27U)

/** Remote serializer slave device id register address */
#define BOARD_FPD_UB926_RMT_SER_SLAVE_DEVICE_ID_REG_ADDR              (0x18U)
/** Remote serializer alias slave device id register address */
#define BOARD_FPD_UB926_RMT_SER_ALIAS_SLAVE_DEVICE_ID_REG_ADDR        (0x2AU)

/** Digital reset1 field shift count */
#define BOARD_FPD_UB926_DIGITAL_RESET1_SHIFT_CNT                     (1U)
/** Deserializer back channel enable field shift count */
#define BOARD_FPD_UB926_BC_ENABLE_SHIFT_CNT                          (2U)
/** Remote auto-power down field shift count */
#define BOARD_FPD_UB926_REMOTE_AUTO_PWR_DWN_SHIFT_CNT                (7U)

/** I2C device ID register address */
#define BOARD_FPD_UB926_ID_SETTING_SHIFT_CNT                         (0U)
/** I2C device ID register address */
#define BOARD_FPD_UB926_DEVICE_ID_SHIFT_CNT                          (1U)

/** I2C device ID register address */
#define BOARD_FPD_UB926_I2C_PASS_THROUGH_SHIFT_CNT                   (3U)
/** I2C device ID register address */
#define BOARD_FPD_UB926_I2C_PASS_THROUGH_ALL_SHIFT_CNT               (7U)

/** I2C device ID register address */
#define BOARD_FPD_UB926_OVERRIDE_FC_CONFIG_SHIFT_CNT                 (7U)
/** I2C device ID register address */
#define BOARD_FPD_UB926_PASS_RGB_SHIFT_CNT                           (6U)
/** I2C device ID register address */
#define BOARD_FPD_UB926_RGB_18BIT_MODE_SHIFT_CNT                     (2U)
/** I2C device ID register address */
#define BOARD_FPD_UB926_I2S_CHANNEL_B_OVERRIDE_SHIFT_CNT             (3U)
/** I2C device ID register address */
#define BOARD_FPD_UB926_I2S_GEN_SHIFT_CNT                            (4U)
/** I2C device ID register address */
#define BOARD_FPD_UB926_I2S_TRANSPOER_SEL_SHIFT_CNT                  (1U)
/** I2C device ID register address */
#define BOARD_FPD_UB926_I2S_CHANNEL_B_ENABLE_SHIFT_CNT               (0U)
/** I2C device ID register address */
#define BOARD_FPD_UB926_I2S_PLL_LOCK_STATUS_SHIFT_CNT                (3U)

/* Bit mask's used for different deserializer register configurations */
/** I2C device ID register address */
#define BOARD_FPD_UB926_DIGITAL_RESET1_BIT_MASK                      (uint8_t)(0x01 << BOARD_FPD_UB926_DIGITAL_RESET1_SHIFT_CNT)
/** I2C device ID register address */
#define BOARD_FPD_UB926_REMOTE_AUTO_PWR_DWN_BIT_MASK                 (uint8_t)(0x01 << BOARD_FPD_UB926_REMOTE_AUTO_PWR_DWN_SHIFT_CNT)
/** I2C device ID register address */
#define BOARD_FPD_UB926_BC_ENABLE_BIT_MASK                           (uint8_t)(0x01 << BOARD_FPD_UB926_BC_ENABLE_SHIFT_CNT)

/** I2C device ID register address */
#define BOARD_FPD_UB926_ID_SETTING_BIT_MASK                          (uint8_t)(0x01  << BOARD_FPD_UB926_ID_SETTING_SHIFT_CNT)
/** I2C device ID register address */
#define BOARD_FPD_UB926_DEVICE_ID_BIT_MASK                           (uint8_t)(0x07F << BOARD_FPD_UB926_DEVICE_ID_SHIFT_CNT)

/** I2C device ID register address */
#define BOARD_FPD_UB926_I2C_PASS_THROUGH_BIT_MASK                    (uint8_t)(0x01  << BOARD_FPD_UB926_I2C_PASS_THROUGH_SHIFT_CNT)

/** I2C device ID register address */
#define BOARD_FPD_UB926_I2C_PASS_THROUGH_ALL_BIT_MASK                (uint8_t)(0x01  << BOARD_FPD_UB926_I2C_PASS_THROUGH_ALL_SHIFT_CNT)

/** I2C device ID register address */
#define BOARD_FPD_UB926_OVERRIDE_FC_CONFIG_BIT_MASK                  (uint8_t)(0x01 << BOARD_FPD_UB926_OVERRIDE_FC_CONFIG_SHIFT_CNT)
/** I2C device ID register address */
#define BOARD_FPD_UB926_PASS_RGB_BIT_MASK                            (uint8_t)(0x01 << BOARD_FPD_UB926_PASS_RGB_SHIFT_CNT)
/** I2C device ID register address */
#define BOARD_FPD_UB926_I2S_GEN_BIT_MASK                             (uint8_t)(0x01 << BOARD_FPD_UB926_I2S_GEN_SHIFT_CNT)
/** I2C device ID register address */
#define BOARD_FPD_UB926_RGB_18BIT_MODE_BIT_MASK                      (uint8_t)(0x01 << BOARD_FPD_UB926_RGB_18BIT_MODE_SHIFT_CNT)
/** I2C device ID register address */
#define BOARD_FPD_UB926_I2S_TRANSPOER_SEL_BIT_MASK                   (uint8_t)(0x01 << BOARD_FPD_UB926_I2S_TRANSPOER_SEL_SHIFT_CNT)
/** I2C device ID register address */
#define BOARD_FPD_UB926_I2S_CHANNEL_B_ENABLE_BIT_MASK                (uint8_t)(0x01 << BOARD_FPD_UB926_I2S_CHANNEL_B_ENABLE_SHIFT_CNT)
/** I2C device ID register address */
#define BOARD_FPD_UB926_I2S_CHANNEL_B_OVERRIDE_BIT_MASK              (uint8_t)(0x01 << BOARD_FPD_UB926_I2S_CHANNEL_B_OVERRIDE_SHIFT_CNT)
/** I2C device ID register address */
#define BOARD_FPD_UB926_I2S_PLL_LOCK_STATUS_BIT_MASK                 (uint8_t)(0x01 << BOARD_FPD_UB926_I2S_PLL_LOCK_STATUS_SHIFT_CNT)

/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD_DS90UB926
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB926_APIS Application Interfaces
 *
 *  Application Interfaces provided by DS90UB926 FPD-Link device library.
 *
 *  @{
 *
 */

/**
 * \brief  I2S channel-B enable mode control
 *
 *  This function is used for configuring the deserializer
 *  I2S Channel-B mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2SChBEnableModeCtrl(void *handle,
                                                   Board_FpdModuleObj *fpdModParams,
                                                   uint8_t cfgMode);

/**
 * \brief   I2S channel-B override mode control
 *
 * This function is used for configuring the deserializer
 * I2S Channel-B override mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2SChBOverrideModeCtrl(void *handle,
                                                     Board_FpdModuleObj *fpdModParams,
                                                     uint8_t cfgMode);

/**
 * \brief  I2S Transport select mode control
 *
 * This function is used for configuring the deserializer I2S transport
 * select mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2STransportSelModeCtrl(void *handle,
                                                      Board_FpdModuleObj *fpdModParams,
                                                      uint8_t cfgMode);

/**
 * \brief  I2S generation mode control
 *
 * This function is used for configuring the deserializer I2S generation mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2SGenModeCtrl(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t cfgMode);

/**
 * \brief  Pass RGB mode control
 *
 * This function is used for configuring the deserializer RGB pass mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetPassRGBModeCtrl(void *handle,
                                              Board_FpdModuleObj *fpdModParams,
                                              uint8_t cfgMode);

/**
 * \brief  Override forward channel configuation mode control
 *
 * This function is used for configuring the deserializer override
 * forward channel mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetOverrideFCConfigModeCtrl(void *handle,
                                                       Board_FpdModuleObj *fpdModParams,
                                                       uint8_t cfgMode);

/**
 * \brief  RGB 18-bit mode control
 *
 * This function is used for configuring the deserializer RGB
 * 18-bit mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetRGB18bitModeCtrl(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               uint8_t cfgMode);

/**
 * \brief  Get PLL lock status
 *
 * This function is used for reading the deserializer PLL
 * lock status
 *
 * \param   handle        [IN]       Low level driver handle
 * \param   fpdModParams  [IN]       FPD module params
 * \param   pllLockStatus [IN/OUT]   Buffer to hold PLL lock status
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926GetPLLLockStatus(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            bool *pllLockStatus);


/**
 * \brief  Remote serializer slave device id config
 *
 * This function is used for configuring the remote serializer slave device ID
 *
 * \param   handle       [IN] Low level driver handle
 * \param   fpdModParams [IN] FPD module params
 * @param   fpdRmtParams [IN] structure holding the fpd params
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926RmtSerSlvDevAliasIdCfg(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  Board_FpdRmtDevObj *fpdRmtParams);

/**
 * \brief  I2C pass through all mode control
 *
 * This function is used for configuring the deserializer
 * I2C pass through all mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2CPassThrAllModeCtrl(void *handle,
                                                    Board_FpdModuleObj *fpdModParams,
                                                    uint8_t cfgMode);

/**
 * \brief  I2C pass through mode control
 *
 * This function is used for configuring the deserializer
 * I2C pass through mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2CPassThrModeCtrl(void *handle,
                                                 Board_FpdModuleObj *fpdModParams,
                                                 uint8_t cfgMode);

/**
 * \brief  I2C bus frequency set
 *
 * This function is used for setting the deserializer I2C bus frequency
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgBitRate    [IN]   Indicates I2C serial clock frequency
 *                               config modes
 *                               BOARD_FPD_KBPS_100 - 100 KBPS
 *                               BOARD_FPD_KBPS_400 - 400 KBPS
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetI2CBusFreq(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t cfgBitRate);

/**
 * \brief  Deserializer back channel mode control
 *
 * This function is used for configuring the deserializer back channel mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetBackChModeCtrl(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t cfgMode);

/**
 * \brief  Deserializer digital reset1 mode control
 *
 * This function is used for configuring the deserializer digital reset1 mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetDigitalRst1ModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t cfgMode);

/**
 * \brief  Remote auto-power down mode control
 *
 * This function is used for configuring the deserializer auto power down mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb926SetRmtAutoPwrDwnModeCtrl(void *handle,
                                                    Board_FpdModuleObj *fpdModParams,
                                                    uint8_t cfgMode);

/**
 * \brief  Get ub926 i2c address.
 *
 * This function is used to get the I2C address and
 * channel details of UB926 module.
 *
 * \param   domain    [IN]  I2C instance domain
 * \param   chNum     [IN]  buffer to hold i2c channel number
 * \param   i2cAddr   [IN]  buffer to hold i2c address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
void Board_fpdUb926GetI2CAddr(uint8_t *domain,
                              uint8_t *chNum,
                              uint8_t *i2cAddr);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DS90UB926_H_ */

/* @} */
