/*
 * Copyright (c) 2016-2017, Texas Instruments Incorporated
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
#define BOARD_INFO_BOARD_NAME           "ICEK2G"

/* Memory Sections */
#define BOARD_DDR3_START_ADDR           0x80000000
#define BOARD_DDR3_SIZE                 (512 * 1024 * 1024UL)
#define BOARD_DDR3_END_ADDR             (BOARD_DDR3_START_ADDR + BOARD_DDR3_SIZE)

/* UART LLD instance number */
#define BOARD_UART_INSTANCE             0

/* I2C address for Industrial LEDs */
#define BOARD_I2C_LED_ADDR				0x60

/* I2C address for Clock generator */
#define BOARD_I2C_CLOCK_GENERATOR		0X6D

/* I2C address for Clock generator */
#define BOARD_I2C_ROTARY_SWITCH		0X41

/* I2C instance connected to LED */
#define BOARD_I2C_LED_INSTANCE			1

#define BOARD_I2C_CURRENT_MONITOR_INSTANCE  (2)

#ifdef ICEK2G_BETA_BOARD
/* I2C instance connected to EEPROM */
#define BOARD_I2C_EEPROM_INSTANCE       1
#else
/* I2C instance connected to EEPROM */
#define BOARD_I2C_EEPROM_INSTANCE       0
#endif

/* I2C address for EEPROM */
#define BOARD_I2C_EEPROM_ADDR           0x50

/* IOEXP I2C instance connected to EEPROM */
#define IOEXP_I2C_EEPROM_INSTANCE       0

/* IOEXP I2C address for EEPROM */
#define IOEXP_I2C_EEPROM_ADDR           0x51

/* I2C instance connected to CLOCK GENERATOR */
#define BOARD_CLOCK_GENERATOR_INSTANCE  0

/* I2C instance connected to ROTARY SWITCH */
#define BOARD_ROTARY_SWICH_INSTANCE  1

/* I2C instance connected to OLED DISPLAY */
#define BOARD_OLED_DISPLAY_INSTANCE  1

/* I2C EEPROM TEST DELAY */
#define I2C_EEPROM_TEST_DELAY 100000

/* I2C EEPROM address command size */
#define I2C_EEPROM_ADDR_SIZE     2

/* I2C EEPROM data buffer length in bytes */
#define I2C_EEPROM_TEST_LENGTH   64

/* Read and write test start address */
#define I2C_EEPROM_TEST_ADDR     0xff80

/* QSPI instance connected to NOR flash */
#define BOARD_QSPI_NOR_INSTANCE         (0U)

/* SPI instance connected to EEPROM1 */
#define IOEXP_EEPROM_SPI0_PORT  0

/* SPI instance connected to EEPROM2 */
#define IOEXP_EEPROM_SPI1_PORT  1

/*SPI data buffer length in bytes*/
#define IOEXP_SPI_TEST_BUF_LENGTH 64

/* SPI EEPROM TEST DELAY in usec */
#define SPI_EEPROM_TEST_DELAY 100000

/* SPI EEPROM CLOCK FREQUENCY in Hz */
#define SPI_EEPROM_CLOCK_FREQUENCY 5000000

/* Enable NOR flash driver */
#define BOARD_NOR_FLASH_IN

/* Platform test return type */
typedef short TEST_STATUS;

/* Platform test return codes */
#define TEST_PASS     (0)
#define TEST_FAIL     (-1)

#define GPIO_MMC_SDCD_PORT_NUM          (0U)
#define GPIO_MMC_SDCD_PIN_NUM           (69U)

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
#define BOARD_EEPROM_MACID0_ADDR        (BOARD_EEPROM_CONFIG_ADDR + BOARD_EEPROM_CONFIG_LENGTH)
#define BOARD_EEPROM_MACID3_ADDR        (BOARD_EEPROM_MACID0_ADDR + BOARD_EEPROM_MACID_LENGTH)

/* Number of LEDS connected to GPIO */
#define BOARD_GPIO_LED_NUM				     (13U)

#ifdef ICEK2G_BETA_BOARD
#define BOARD_GIGABIT_EMAC_PHY_ADDR          (1U)

#define BOARD_ICSS_EMAC_PORT0_PHY_ADDR       (4U)
#define BOARD_ICSS_EMAC_PORT1_PHY_ADDR       (5U)
#define BOARD_ICSS_EMAC_PORT2_PHY_ADDR       (6U)
#define BOARD_ICSS_EMAC_PORT3_PHY_ADDR       (7U)

#else

#define BOARD_GIGABIT_EMAC_PHY_ADDR          (0)

#define BOARD_ICSS_EMAC_PORT0_PHY_ADDR       (0)
#define BOARD_ICSS_EMAC_PORT1_PHY_ADDR       (1U)
#define BOARD_ICSS_EMAC_PORT2_PHY_ADDR       (2U)
#define BOARD_ICSS_EMAC_PORT3_PHY_ADDR       (3U)

#endif  /* #ifdef ICEK2G_BETA_BOARD */

/* ICSS EMAC PHY register address definitions for reading strap values */
#define BOARD_ICSS_EMAC_REG_DUMP_MAX          (16U)
#define BOARD_ICSS_EMAC_STRAP_STS1_ADDR       (0x467U)
#define BOARD_ICSS_EMAC_STRAP_STS2_ADDR       (0x468U)

/* Gigabit EMAC PHY register address definitions for reading strap values */
#define BOARD_GIGABIT_EMAC_REG_DUMP_MAX       (16U)
#define BOARD_GIGABIT_EMAC_STRAP_STS1_ADDR    (0x6EU)
#define BOARD_GIGABIT_EMAC_STRAP_STS2_ADDR    (0x6FU)

typedef enum _BoardIcssClkOut
{
    BOARD_ICSS_PLL_CLK_200MHZ,
    BOARD_ICSS_PLL_CLK_225MHZ
} BoardIcssClkOut;

#ifdef __cplusplus
}
#endif

#endif
