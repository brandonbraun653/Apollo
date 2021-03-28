/**
 * \file   device.h
 *
 * \brief  This file contains the device module interface. It lists out the
 * identifiers for devices on the boards and provides functions for probing
 * for devices over the I2C bus, for the devices which are connected to I2C.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 *
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

#ifndef DEVICE_H_
#define DEVICE_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Enumerates the device IDs */
typedef enum deviceId
{
    DEVICE_ID_EEPROM                 = 0x0U,
    /**< EEPROM device ID. */
    DEVICE_ID_TMP275                 = 0x1U,
    /**< TMP275 Temperature sensor device ID. */
    DEVICE_ID_LIS331DLH              = 0x2U,
    /**< LIS331DLH Accelerometer device ID. */
    DEVICE_ID_AIC31                  = 0x3U,
    /**< AIC31 device ID. */
    DEVICE_ID_LED                    = 0x4U,
    /**< LED device ID. */
    DEVICE_ID_BUZZER                 = 0x5U,
    /**< Audio buzzer device ID. */
    DEVICE_ID_VTT                    = 0x6U,
    /**< LED device ID. */
    DEVICE_ID_HAPTICS                = 0x7U,
    /**< HAPTICS Motor device ID. */
    DEVICE_ID_W25Q64BV               = 0x8U,
    /**< Winbond SPI flash device ID. */
    DEVICE_ID_FLASH_MX66L51235F      = 0x9U,
    /**< Macronix QSPI flash device ID. */
    DEVICE_ID_ENET_PHY_RGMII         = 0xAU,
    /**< Ethernet PHY. */
    DEVICE_ID_ENET_PHY_RMII          = 0xBU,
    /**< RMII Ethernet PHY. */
    DEVICE_ID_PMIC_TPS65217          = 0xCU,
    /**< Ethernet PHY. */
    DEVICE_ID_PMIC_TPS65910          = 0xDU,
    /**< RMII Ethernet PHY. */
    DEVICE_ID_FLASH_N25Q128A13ESE    = 0x10U,
    /**< Micron QSPI flash device ID. */
    DEVICE_ID_LCD_OSD070T1718_19TS   = 0x11U,
    /**< LCD device ID. */
    DEVICE_ID_LCD_S9700RTWV43_01B    = 0x12U,
    /**< LCD device ID. */
    DEVICE_ID_DCAN_CONNECTOR         = 0x13U,
    /**< DCAN connector device ID. */
    DEVICE_ID_DCARD_LCD4_DISPLAY     = 0x14U,
    /**< LCD device ID. */
    DEVICE_ID_CAMERA_OV2659          = 0x15U,
    /**< Camera sensor device ID. */
    DEVICE_ID_FLASH_MT29F2G08ABAEAWP = 0x16U,
    /**< Micron 2Gb NAND Flash device ID. */
    DEVICE_ID_FLASH_MT29F4G08ABAEAWP = 0x17U,
    /**< Micron 4Gb NAND Flash device ID. */
    DEVICE_ID_CONSOLE                = 0x18U,
    /**< UART Console details for utils. */
    DEVICE_ID_PMIC_TPS65218          = 0x19U,
    /**< brief PMIC Device ID. */
    DEVICE_ID_ENET_PHY_MII           = 0x1AU,
    /** \brief MII Ethernet PHY. */
    DEVICE_ID_I2C_LED                = 0x1BU,
    /**< LED I2C device ID. */
    DEVICE_ID_HVS882                 = 0x1CU,
    /**< HVS SPI device ID. */
    DEVICE_ID_I2C_OLED               = 0x1DU,
    /**< OLED I2C device ID. */
    DEVICE_ID_PRUSS                  = 0x1EU,
    /**< PRUSS */
    DEVICE_ID_RESET_PHY              = 0x1FU,
    /**< PRUSS Phy reset */
    DEVICE_ID_MII_MUX                = 0x20U,
    /**< MII_MUX */
	DEVICE_ID_I2C_ROTARY_SW          = 0x21U,
	/**< Rotary Switch device ID. */
    DEVICE_ID_MAX                    = DEVICE_ID_MII_MUX,
    /** <Maximum no of devices */
    DEVICE_ID_INVALID                = 0xFFFFFFFFU
    /**< Invalid device ID. */
} deviceId_t;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief Probes an I2C bus for a specific device slave address.
 *
 *  \param i2cInstNum    I2C instance number
 *  \param slaveAddr    Slave I2C address
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure
 */
int32_t DEVICEI2cProbeDevice(uint32_t i2cInstNum, uint16_t slaveAddr);

/**
 *  \brief Probes an I2C bus for all devices.
 *
 *  Probes an I2C bus for all possibly connected slaves to it.
 *  Prints the detected slave address on the console.
 *
 *  \param i2cInstNum    I2C instance number
 *
 *  \retval S_PASS      On success
 *  \retval E_FAIL      General failure
 */
int32_t DEVICEI2cProbeAll(uint32_t i2cInstNum);


#ifdef __cplusplus
}
#endif /* ifdef __cplusplus */

#endif  /* #ifndef DEVICE_H_ */
