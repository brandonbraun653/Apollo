/*
 * Copyright (c) 2015-2018, Texas Instruments Incorporated
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
#define BOARD_INFO_CPU_NAME     "AM335x"
#define BOARD_INFO_BOARD_NAME   "EVMAM335x"

/* Mmeory Sections */
#define BOARD_DDR3_START_ADDR           0x80010000
#define BOARD_DDR3_SIZE                 ((1 * 1024 * 1024 * 1024UL) - 0x00010000)
#define BOARD_DDR3_END_ADDR             (BOARD_DDR3_START_ADDR + BOARD_DDR3_SIZE - 1)


/* UART LLD instance number */
#define BOARD_UART_INSTANCE				0

/* EEPROM Data read length */
#define I2C_EEPROM_RX_LENGTH            10U

/* Port and pin number mask for MMCSD Card Detect pin.
   Bits 7-0: Pin number  and Bits 15-8: (Port number + 1) */
#define GPIO_MMC_SDCD_PIN_NUM          (0x6)
#define GPIO_MMC_SDCD_PORT_NUM         (0x1)
#define GPIO_PIN_MMC_SDCD_ACTIVE_STATE (0x0)

/* I2C instance connected to EEPROM */
#define BOARD_I2C_EEPROM_INSTANCE       0

/* I2C address for EEPROM */
#define BOARD_I2C_EEPROM_ADDR           (0x50)

/* EEPROM board ID information */
#define BOARD_EEPROM_HEADER_LENGTH      4
#define BOARD_EEPROM_BOARD_NAME_LENGTH  8
#define BOARD_EEPROM_VERSION_LENGTH     4
#define BOARD_EEPROM_SERIAL_NO_LENGTH   12
#define BOARD_EEPROM_HEADER_ADDR        0
#define BOARD_EEPROM_BOARD_NAME_ADDR    (BOARD_EEPROM_HEADER_ADDR + BOARD_EEPROM_HEADER_LENGTH)
#define BOARD_EEPROM_VERSION_ADDR       (BOARD_EEPROM_BOARD_NAME_ADDR + BOARD_EEPROM_BOARD_NAME_LENGTH)
#define BOARD_EEPROM_SERIAL_NO_ADDR     (BOARD_EEPROM_VERSION_ADDR + BOARD_EEPROM_VERSION_LENGTH)

#define CPLD_CTRLREG_OFFSET             (0x10)
#define CPLD_I2C_ADDR                   (0x35)

#define AM335x_GPEVM_PROFILE_2          (2)

/* Instance for interfaces connected to MMCSD */
#define BOARD_MMCSD_SD_INSTANCE         (0)

#ifdef __cplusplus
}
#endif

#endif
