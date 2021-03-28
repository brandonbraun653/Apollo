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

#ifndef BOARD_CFG_H_
#define BOARD_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Board ID information */
#define BOARD_INFO_CPU_NAME     "DRA78x"
#define BOARD_INFO_BOARD_NAME   "evmDRA78x"

/* Mmeory Sections */
#define BOARD_DDR3_START_ADDR           0x80000000
#define BOARD_DDR3_SIZE                 (2 * 1024 * 1024 * 1024UL)
#define BOARD_DDR3_END_ADDR             (BOARD_DDR3_START_ADDR + BOARD_DDR3_SIZE - 1)

#define BOARD_UART_INSTANCE             0

/* Audio sample rate - 44100 or 48000 */
#define BOARD_AUDIO_SAMPLERATE          48000

/* I2C bus controlling the Audio Codec/ADC/DAC */
#define BOARD_I2C_AUDIO_DEVICE          0

/* McSPI instance to support Master/Slave test */
#define BOARD_MCSPI_MASTER_INSTANCE     (0x1U)
#define BOARD_MCSPI_SLAVE_INSTANCE      (0x1U)

/* I2C instance connected to EEPROM */
#define BOARD_I2C_EEPROM_INSTANCE       0

/* I2C address for EEPROM */
#define BOARD_I2C_EEPROM_ADDR           0x50

/* I2C addresses of the I/O expanders */
#define BOARD_AUDIO_IO_EXP_TCA6416_I2C_ADDR (0x21)
#define BOARD_IO_EXP_TCA6424_1_I2C_ADDR     (0x22)
#define BOARD_IO_EXP_TCA6424_2_I2C_ADDR     (0x23)

/* Port and pin number mask for MMCSD Card Detect pin.
 * Bits 7-0: Pin number and Bits 15-8: (Port number).
 */
#define GPIO_MMC_SDCD_PIN_NUM           (0x1FU)
#define GPIO_MMC_SDCD_PORT_NUM          (0x03U)
#define GPIO_PIN_MMC_SDCD_ACTIVE_STATE  (0x01U)

/* GMAC diagnostic example configuration */
#define GMAC_BASEADDRESS                (0x48484000U)
#define GMAC_PORT1_ETHERNET_PHY_ADRESS  (0x1U)
#define GMAC_PORT2_ETHERNET_PHY_ADRESS  (0x2U)

#ifdef __cplusplus
}
#endif

#endif
