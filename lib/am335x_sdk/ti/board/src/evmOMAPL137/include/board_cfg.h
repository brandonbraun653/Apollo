/**
 *  @file   board_cfg.h
 *
 *  @brief  Board specific configuration definitions
 *
 *  ============================================================================
 */
/*
 * Copyright (c) 2017, Texas Instruments Incorporated
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

#ifndef _BOARD_CFG_H_
#define _BOARD_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Board ID information */
#define BOARD_INFO_CPU_NAME             "OMAPL137"
#define BOARD_INFO_BOARD_NAME           "EVMOMAPL137"

/* Memory Sections */
#define BOARD_DDR3_START_ADDR           (0xC3000000U)
#define BOARD_DDR3_SIZE                 (64 * 1024 * 1024UL)
#define BOARD_DDR3_END_ADDR             (BOARD_DDR3_START_ADDR + BOARD_DDR3_SIZE)

/* UART LLD instance number */
#define BOARD_UART_INSTANCE             (2U)

/* I2C instance connected to EEPROM */
#define BOARD_I2C_EEPROM_INSTANCE       (0)

/* EEPROM I2C slave address */
#define BOARD_I2C_EEPROM_ADDR           (0x50U)

/* Audio codec I2C slave address */
#define BOARD_I2C_CODEC_ADDR            (0x18U)

/* I2C EEPROM TEST DELAY */
#define I2C_EEPROM_TEST_DELAY           (100000U)

/* I2C EEPROM address command size */
#define I2C_EEPROM_ADDR_SIZE            (2U)

/* I2C EEPROM data buffer length in bytes */
#define I2C_EEPROM_TEST_LENGTH          (64U)

/* Read and write test start address */
#define I2C_EEPROM_TEST_ADDR            (0xff80U)

/* SPI instance connected to Flash */
#define TEST_SPI_PORT                   (0U)

#define BOARD_SPI_NOR_INSTANCE          (0U)

/* Enable NOR flash driver */
#define BOARD_NOR_FLASH_IN

/* GPIO pin and port numbers for on-board LED */
#define GPIO_LED0_PIN_NUM               (12U)
#define GPIO_LED0_PORT_NUM              (0U)
#define GPIO_LED1_PIN_NUM               (13U)
#define GPIO_LED1_PORT_NUM              (0U)

#define GPIO_MMC_SDCD_PORT_NUM          (0U)
#define GPIO_MMC_SDCD_PIN_NUM           (34U)

#ifdef _TMS320C6X
#define GPIO_MUX_SEL                    (16U)
#else
#define GPIO_MUX_SEL                    (0U)
#endif

/* Ethernet PHY addressess */
#define BOARD_ETH_PHY0_I2C_ADDR         (0x5D)
#define BOARD_ETH_PHY1_I2C_ADDR         (0x5F)

#define BOARD_ETH_PHY0_ADDR             (0x01)
#define BOARD_ETH_PHY1_ADDR             (0x02)

/* Aliases for default PHY port used by board and applications */
#define BOARD_ETH_PHY_I2C_ADDR          (BOARD_ETH_PHY1_I2C_ADDR)
#define BOARD_ETH_PHY_ADDR              (BOARD_ETH_PHY0_ADDR)

/* EEPROM board ID information */
#define BOARD_EEPROM_HEADER_LENGTH		(4U)
#define BOARD_EEPROM_BOARD_NAME_LENGTH	(8U)
#define BOARD_EEPROM_VERSION_LENGTH		(4U)
#define BOARD_EEPROM_SERIAL_NO_LENGTH	(12U)
#define BOARD_EEPROM_CONFIG_LENGTH      (32U)
#define BOARD_EEPROM_MACID_LENGTH       (6U)

#define BOARD_EEPROM_ID_SIZE            (BOARD_EEPROM_HEADER_LENGTH + \
                                         BOARD_EEPROM_BOARD_NAME_LENGTH + \
                                         BOARD_EEPROM_VERSION_LENGTH + \
                                         BOARD_EEPROM_SERIAL_NO_LENGTH + \
                                         BOARD_EEPROM_CONFIG_LENGTH + \
                                         (2*BOARD_EEPROM_MACID_LENGTH))

#define BOARD_EEPROM_HEADER_ADDR		(0U)
#define BOARD_EEPROM_BOARD_NAME_ADDR	(BOARD_EEPROM_HEADER_ADDR + BOARD_EEPROM_HEADER_LENGTH)
#define BOARD_EEPROM_VERSION_ADDR		(BOARD_EEPROM_BOARD_NAME_ADDR + BOARD_EEPROM_BOARD_NAME_LENGTH)
#define BOARD_EEPROM_SERIAL_NO_ADDR		(BOARD_EEPROM_VERSION_ADDR + BOARD_EEPROM_VERSION_LENGTH)
#define BOARD_EEPROM_CONFIG_ADDR        (BOARD_EEPROM_SERIAL_NO_ADDR + BOARD_EEPROM_SERIAL_NO_LENGTH)

#ifdef __cplusplus
}
#endif

#endif   /* _BOARD_CFG_H_ */
