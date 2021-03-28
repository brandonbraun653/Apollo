/*
 * Copyright (c) 2015 - 2018, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef BOARD_CFG_H_
#define BOARD_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Board ID information */
#define BOARD_INFO_CPU_NAME             "K2G"
#define BOARD_INFO_BOARD_NAME           "EVMK2G"

/* Mmeory Sections */
#define BOARD_DDR3_START_ADDR           0x80000000
#define BOARD_DDR3_SIZE                 (2048 * 1024 * 1024UL)
#define BOARD_DDR3_END_ADDR             (0xFFFFFFFF)

/* UART LLD instance number */
#define BOARD_UART_INSTANCE             0

/* I2C instance connected to EEPROM */
#define BOARD_I2C_EEPROM_INSTANCE       0

/* I2C address for EEPROM */
#define BOARD_I2C_EEPROM_ADDR           0x50

/* I2C instance as master for master/slave test example */
#define BOARD_I2C_MASTER_INSTANCE       0

/* I2C instance as salve for master/slave test example */
#define BOARD_I2C_SLAVE_INSTANCE        0

/* SPI instance connected to NOR flash */
#define BOARD_SPI_NOR_INSTANCE          (1U)

/* SPI instance as master for master/slave test example */
#define BOARD_MCSPI_MASTER_INSTANCE     (1U)

/* SPI instance as slave for master/slave test example */
#define BOARD_MCSPI_SLAVE_INSTANCE      (1U)

/* QSPI instance connected to NOR flash */
#define BOARD_QSPI_NOR_INSTANCE         (0U)

/* Instance for interfaces connected to MMCSD */
#define BOARD_MMCSD_SD_INSTANCE         (0)
#define BOARD_MMCSD_EMMC_INSTANCE       (1U)

/* Enable NOR flash driver */
#define BOARD_NOR_FLASH_IN


#define GPIO_MMC_SDCD_PORT_NUM          (1U)
#define GPIO_MMC_SDCD_PIN_NUM           (12U)

#define GPIO_EMMC_RST_PORT_NUM          (0U)
#define GPIO_EMMC_RST_PIN_NUM           (70U)

/* EEPROM board ID information */
#define BOARD_EEPROM_HEADER_LENGTH		(4U)
#define BOARD_EEPROM_BOARD_NAME_LENGTH	(8U)
#define BOARD_EEPROM_VERSION_LENGTH		(4U)
#define BOARD_EEPROM_SERIAL_NO_LENGTH	(12U)
#define BOARD_EEPROM_CONFIG_LENGTH      (32U)

#define BOARD_EEPROM_HEADER_ADDR		(0U)
#define BOARD_EEPROM_BOARD_NAME_ADDR	(BOARD_EEPROM_HEADER_ADDR + BOARD_EEPROM_HEADER_LENGTH)
#define BOARD_EEPROM_VERSION_ADDR		(BOARD_EEPROM_BOARD_NAME_ADDR + BOARD_EEPROM_BOARD_NAME_LENGTH)
#define BOARD_EEPROM_SERIAL_NO_ADDR		(BOARD_EEPROM_VERSION_ADDR + BOARD_EEPROM_VERSION_LENGTH)
#define BOARD_EEPROM_CONFIG_ADDR        (BOARD_EEPROM_SERIAL_NO_ADDR + BOARD_EEPROM_SERIAL_NO_LENGTH)

/* Number of LEDS connected to GPIO */
#define BOARD_GPIO_LED_NUM				2

/* board input frequency */
#define BOARD_SOC_INPUT_CLK_FREQ        (24000000U)

/* JTAGID value for K2G1x*/
#define JTAGID_1G						0x8BB0602F
#define DEVSPEED600			600
#define DEVSPEED1G			1000 

int Board_getDEVSPEED(void);

#ifdef __cplusplus
}
#endif

#endif
