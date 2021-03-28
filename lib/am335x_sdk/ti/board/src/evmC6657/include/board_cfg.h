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
#define BOARD_INFO_CPU_NAME 	"C6657"
#define BOARD_INFO_BOARD_NAME 	"EVMC6657"

/* Mmeory Sections */
#define BOARD_DDR3_START_ADDR			0x80000000
#define BOARD_DDR3_SIZE					(1 * 512 * 1024 * 1024UL)
#define BOARD_DDR3_END_ADDR				(BOARD_DDR3_START_ADDR + BOARD_DDR3_SIZE)

/* UART LLD instance number */
#define BOARD_UART_INSTANCE				0

/* Number of LEDS connected to GPIO */
#define BOARD_GPIO_LED_NUM				4

/* I2C instance connected to EEPROM */
#define BOARD_I2C_EEPROM_INSTANCE		0

/* I2C address for EEPROM */
#define BOARD_I2C_EEPROM_ADDR			0x50

/* SPI instance connected to NOR flash */
#define BOARD_SPI_NOR_INSTANCE			0

/* Enable NOR flash driver */
#define BOARD_NOR_FLASH_IN

#ifdef __cplusplus
}
#endif


#endif
