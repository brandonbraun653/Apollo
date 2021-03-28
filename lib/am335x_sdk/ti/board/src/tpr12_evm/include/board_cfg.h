/******************************************************************************
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
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
 * \brief  Board library configurations
 *
 * This file configures the instance numbers, address and gpio reset
 * details of different interfaces of TPR12 EVM.
 *
 */
#ifndef BOARD_CFG_H_
#define BOARD_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Board ID information */
#define BOARD_INFO_CPU_NAME     "tpr12"
#define BOARD_INFO_BOARD_NAME   "tpr12_evm"

/* UART LLD instance number for primary UART port */
#define BOARD_UART_INSTANCE                     (0U)

/* I2C instance connected to PMIC - WKUP I2C0 */
#define BOARD_I2C_PMIC_INSTANCE                 (0U)

/* I2C slave address of PMIC */
#define BOARD_I2C_PMIC_ADDR                     (0U)

/* QSPI instance connected to OSPI NOR flash */
#define BOARD_QSPI_NOR_INSTANCE                 (0U)

/* Number of LEDS connected to GPIO */
#define BOARD_GPIO_LED_NUM                      (0U)

#define BOARD_MCU_EMAC_PORT_MAX                 (0x1U)
#define BOARD_MCU_ETH_PORT                      (0x1U)

/* MCU EMAC PHY MDIO address */
#define BOARD_MCU_EMAC_PHY_ADDR                 (0U)

/* MCU EMAC MAX REG DUMP */
#define BOARD_MCU_EMAC_REG_DUMP_MAX             (16U)

/* MCU EMAC PHY register address definitions for reading strap values */
#define BOARD_MCU_EMAC_STRAP_STS1_ADDR          (0x6EU)
#define BOARD_MCU_EMAC_STRAP_STS2_ADDR          (0x6FU)

/* MCU_ETH1_INTn */
#define BOARD_GPIO_MCU_EMAC_INT_PORT_NUM        (0)
#define BOARD_GPIO_MCU_EMAC_INT_PIN_NUM         (0)

/* Temperature sensor i2c instance */
#define BOARD_TEMP_SENSOR_I2C_INSTANCE          (0U)

/* Temperature sensor slave device addresses */
#define BOARD_TEMP_SENSOR_I2C_SLAVE_DEVICE1_ADDR    (0x0)
#define BOARD_TEMP_SENSOR_I2C_SLAVE_DEVICE2_ADDR    (0x0)

#define BOARD_I2C_CURRENT_MONITOR_INSTANCE          (0U)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* BOARD_CFG_H_ */
