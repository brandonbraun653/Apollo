/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
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
#define BOARD_INFO_CPU_NAME 	"AM571x"
#define BOARD_INFO_BOARD_NAME 	"EVMAM571x"

/* Mmeory Sections */
#define BOARD_DDR3_START_ADDR			0x80000000
#define BOARD_DDR3_SIZE					(1 * 1024 * 1024 * 1024UL)
#define BOARD_DDR3_END_ADDR				(BOARD_DDR3_START_ADDR + BOARD_DDR3_SIZE)

/* UART LLD instance number */
#define BOARD_UART_INSTANCE				2

/* Number of LEDS connected to GPIO */
#define BOARD_GPIO_LED_NUM				4

/* I2C instance connected to LED */
#define BOARD_I2C_LED_INSTANCE			0

/* I2C address for Industrial LEDs */
#define BOARD_I2C_LED_ADDR				0x60

/* I2C instance connected to EEPROM */
#define BOARD_I2C_EEPROM_INSTANCE		0

/* I2C address for EEPROM */
#define BOARD_I2C_EEPROM_ADDR			0x50

/* I2C instance connected to touchscreen controller */
#define BOARD_I2C_TOUCHSCREEN_INSTANCE	0

/* I2C address for touchscreen controller */
#define BOARD_I2C_TOUCHSCREEN_ADDR		0x38

/* EEPROM board ID information */
#define BOARD_EEPROM_HEADER_LENGTH		4
#define BOARD_EEPROM_BOARD_NAME_LENGTH	8
#define BOARD_EEPROM_VERSION_LENGTH		4
#define BOARD_EEPROM_SERIAL_NO_LENGTH	12
#define BOARD_EEPROM_HEADER_ADDR		0
#define BOARD_EEPROM_BOARD_NAME_ADDR	(BOARD_EEPROM_HEADER_ADDR + BOARD_EEPROM_HEADER_LENGTH)
#define BOARD_EEPROM_VERSION_ADDR		(BOARD_EEPROM_BOARD_NAME_ADDR + BOARD_EEPROM_BOARD_NAME_LENGTH)
#define BOARD_EEPROM_SERIAL_NO_ADDR		(BOARD_EEPROM_VERSION_ADDR + BOARD_EEPROM_VERSION_LENGTH)

/* GMAC diagnostic example configuration */
#define GMAC_BASEADDRESS				(0x48484000U)
#define GMAC_PORT1_ETHERNET_PHY_ADRESS  (0x1U)
#define GMAC_PORT2_ETHERNET_PHY_ADRESS  (0x2U)

#ifdef __cplusplus
}
#endif

#endif
