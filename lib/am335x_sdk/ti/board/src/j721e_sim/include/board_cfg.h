/******************************************************************************
 * Copyright (c) 2017 - 2018 Texas Instruments Incorporated - http://www.ti.com
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
 * details of different interfaces of J7 sim board.
 *
 */
#ifndef BOARD_CFG_H_
#define BOARD_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Board ID information */
#define BOARD_INFO_CPU_NAME     "j721e"
#define BOARD_INFO_BOARD_NAME   "j721e_sim"

/* Memory sections */
#define BOARD_DDR_START_ADDR           (0x80000000U)
#define BOARD_DDR_SIZE                 (2048 * 1024 * 1024UL)
#define BOARD_DDR_END_ADDR             (0xFFFFFFFFU)

/* UART LLD instance number for primary UART port */
#define BOARD_UART_INSTANCE                     (0U)
/* UART LLD instance number for MAIN UART1 port */
#define BOARD_UART1_INSTANCE                    (1U)
/* MCU UART LLD instance number */
#define BOARD_MCU_UART_INSTANCE                 (0U)
/* WKUP UART LLD instance number */
#define BOARD_WKUP_UART_INSTANCE                (0U)
/* ICSSG UART instance number */
#define BOARD_ICSSG_UART_INSTANCE               (4U)

/* I2C instance connected to EEPROM - WKUP I2C0 */
#define BOARD_I2C_EEPROM_INSTANCE               (0U)

/* I2C instance connected to boot EEPROM - MAIN I2C2 */
/* This instance is used as temporary workaround due to
   silicon issue with MCU I2C instance
*/
#define BOARD_I2C_BOOT_EEPROM_INSTANCE          (2U)

/* I2C address for EEPROM */
#define BOARD_I2C_BOOT_EEPROM_ADDR              (0x54U)
#define BOARD_I2C_EEPROM_ADDR                   (0x50U)
#define BOARD_I2C_EEPROM_ADDR2                  (0x51U)

/* SPI instance number */
#define BOARD_SPI_NOR_INSTANCE                  (0)

/* OSPI instance connected to OSPI NOR flash */
#define BOARD_OSPI_NOR_INSTANCE                 (0U)

/* I2C Slave devices used to control LED Industrial and RST Pins
   are connected to this instance - SoC I2C0 */
#define BOARD_I2C_IOEXP_INSTANCE                      (0U)
/* Used to configure Ethernet PHY LED's */
#define BOARD_I2C_IOEXP_DEVICE1_ADDR                  (0x60U)
/* Used for device resets and MUX selections */
#define BOARD_I2C_IOEXP_DEVICE2_ADDR                  (0x21U)

#define BOARD_GPIO_IOEXP_SPI_RST_PORT_NUM             (0)
#define BOARD_GPIO_IOEXP_SPI_RST_PIN_NUM              (2)

/* OSPI instance number */
#define BOARD_OSPI_INSTANCE                           (0)

#define BOARD_GPIO_IOEXP_OSPI_RST_PORT_NUM            (0)
#define BOARD_GPIO_IOEXP_OSPI_RST_PIN_NUM             (1)

/* GPIO port & pin numbers for  MMC reset */
#define GPIO_MMC_SDCD_PORT_NUM                  (0)
#define GPIO_MMC_SDCD_PIN_NUM                   (0)

#define BOARD_GPIO_IOEXP_EMMC_RST_PORT_NUM            (0x00)
#define BOARD_GPIO_IOEXP_EMMC_RST_PIN_NUM             (0x00)

/* I2C instance for External RTC */
#define BOARD_I2C_EXT_RTC_INSTANCE					  (0U)

/* I2C address for External RTC */
#define BOARD_I2C_EXT_RTC_ADDR						  (0x6FU)

#define BOARD_I2C_TOUCH_INSTANCE                      (1U)

#define BOARD_I2C_TOUCH_SLAVE_ADDR                    (0x14U)

/* Number of LEDS connected to GPIO */
#define BOARD_GPIO_LED_NUM                            (4U)

/* I2C instance Board Presence Circuit */
#define BOARD_PRES_WKUP_I2C_INSTANCE                  (0U)
/* I2C address Board Presence Circuit */
#define BOARD_PRES_DETECT_SLAVE_ADDR                  (0x38U)

/* LED PIN NUMBERS */
/* Pin and port numbers for LD16 on CP board */
#define BOARD_WKUP_GPIO_LD16_PORT_NUM           (0)    /* Port 0 */
#define BOARD_WKUP_GPIO_LD16_PIN_NUM            (0x08) /* Pin 8 */

/* Pin and port numbers for LD17 on CP board */
#define BOARD_WKUP_GPIO_LD17_PORT_NUM           (0)    /* Port 0 */
#define BOARD_WKUP_GPIO_LD17_PIN_NUM            (0x32) /* Pin 50 */

/* Pin and port numbers for GREEN color on bicolor LED LD18 on CP board */
#define BOARD_WKUP_GPIO_LD18_GREEN_PORT_NUM           (0)    /* Port 0 */
#define BOARD_WKUP_GPIO_LD18_GREEN_PIN_NUM            (0)    /* Pin 0 */
/* Pin and port numbers for RED color on bicolor LED LD18 on CP board */
#define BOARD_WKUP_GPIO_LD18_RED_PORT_NUM           (0)      /* Port 0 */
#define BOARD_WKUP_GPIO_LD18_RED_PIN_NUM            (0x1)    /* Pin 1 */

#define BOARD_ICSS_EMAC_PORT_START              (0x4U)
#define BOARD_ICSS_EMAC_PORT_END                (0x5U)
#define BOARD_ICSS_EMAC_PORT_MAX                (0x2U)
#define BOARD_MCU_EMAC_PORT_MAX                 (0x1U)
#define BOARD_MCU_ETH_PORT                      (0x6U)

/* ICSS0 EMAC PHY MDIO addresses */
#define BOARD_ICSS0_EMAC_PHY0_ADDR              (0x0U)
#define BOARD_ICSS0_EMAC_PHY1_ADDR              (0x3U)

/* ICSS2 EMAC PHY register address */
#define BOARD_ICSS2_EMAC_PHY0_ADDR              (0x0)
#define BOARD_ICSS2_EMAC_PHY1_ADDR              (0x03)
/* ICSS1 EMAC PHY MDIO addresses */
#define BOARD_ICSS1_EMAC_PHY0_ADDR              (0x0U)
#define BOARD_ICSS1_EMAC_PHY1_ADDR              (0x03U)

/* PRG2_RGMII_RESETn */
#define BOARD_GPIO_IOEXP_ICSS2_EMAC_RST_PORT_NUM      (0)
#define BOARD_GPIO_IOEXP_ICSS2_EMAC_RST_PIN_NUM       (3)

/* PRG2_RGMII_INTn */
#define BOARD_GPIO_ICSS2_EMAC_INT_PORT_NUM            (0) /* WKUP_GPIO0_24  */
#define BOARD_GPIO_ICSS2_EMAC_INT_PIN_NUM             (24)

/* PRG2_ETH1_LED_LINK */
#define BOARD_GPIO_ICSS2_EMAC_PHY0_LED_LINK_PORT_NUM  (1) /* GPIO1_13 */
#define BOARD_GPIO_ICSS2_EMAC_PHY0_LED_LINK_PIN_NUM   (13)

/* PRG2_ETH2_LED_LINK */
#define BOARD_GPIO_ICSS2_EMAC_PHY1_LED_LINK_PORT_NUM  (1) /* GPIO1_14 */
#define BOARD_GPIO_ICSS2_EMAC_PHY1_LED_LINK_PIN_NUM   (14)

/* GPIO to drive PRG2 LED0 */
#define BOARD_GPIO_ICSS2_EMAC_LED0_PORT_NUM           (0) /* WKUP_GPIO0_13 */
#define BOARD_GPIO_ICSS2_EMAC_LED0_PIN_NUM            (13)

/* GPIO to drive PRG2 LED1 */
#define BOARD_GPIO_ICSS2_EMAC_LED1_PORT_NUM           (0) /* WKUP_GPIO0_0 */
#define BOARD_GPIO_ICSS2_EMAC_LED1_PIN_NUM            (0)

/* GPIO to drive PRG2 LED2 */
#define BOARD_GPIO_ICSS2_EMAC_LED2_PORT_NUM           (0) /* WKUP_GPIO0_1 */
#define BOARD_GPIO_ICSS2_EMAC_LED2_PIN_NUM            (1)

/* GPIO to drive PRG2 LED3 */
#define BOARD_GPIO_ICSS2_EMAC_LED3_PORT_NUM           (0) /* WKUP_GPIO0_27 */
#define BOARD_GPIO_ICSS2_EMAC_LED3_PIN_NUM            (27)

/* MCU EMAC PHY MDIO address */
#define BOARD_MCU_EMAC_PHY_ADDR                 (0U)

/* MCU EMAC MAX REG DUMP */
#define BOARD_MCU_EMAC_REG_DUMP_MAX                   (16U)

/* MCU EMAC PHY register address definitions for reading strap values */
#define BOARD_MCU_EMAC_STRAP_STS1_ADDR                (0x6EU)
#define BOARD_MCU_EMAC_STRAP_STS2_ADDR                (0x6FU)

/* MCU EMAC PHY register address definitions for reading strap values */
#define BOARD_ICSS_EMAC_STRAP_STS1_ADDR                (0x6EU)
#define BOARD_ICSS_EMAC_STRAP_STS2_ADDR                (0x6FU)

/* MCU_ETH1_RESETn */
#define BOARD_GPIO_IOEXP_MCU_EMAC_RST_PORT_NUM        (0)
#define BOARD_GPIO_IOEXP_MCU_EMAC_RST_PIN_NUM         (4)

/* MCU_ETH1_INTn */
#define BOARD_GPIO_MCU_EMAC_INT_PORT_NUM              (0) /* WKUP_GPIO0_32 */
#define BOARD_GPIO_MCU_EMAC_INT_PIN_NUM               (32)

/* AUTOMATION HEADER */
#define BOARD_TEST_HEADER_I2C_INSTANCE                (2U)
#define BOARD_I2C_BOOT_MODE_SW_ADDR                   (0x22U)

/* TEST_GPIO1 */
#define BOARD_GPIO_IOEXP_TEST_PORT_NUM                (1)
#define BOARD_GPIO_IOEXP_TEST_PIN_NUM                 (2)

/* Temperature sensor i2c instance */
#define BOARD_TEMP_SENSOR_I2C_INSTANCE                (2U)

/* Temperature sensor slave device addresses */
#define BOARD_TEMP_SENSOR_I2C_SLAVE_DEVICE1_ADDR       (0x48U)
#define BOARD_TEMP_SENSOR_I2C_SLAVE_DEVICE2_ADDR       (0x49U)

#define BOARD_I2C_CURRENT_MONITOR_INSTANCE      (2U)

/* Enable NOR flash driver */
#define BOARD_NOR_FLASH_IN

/* McSPI instance for master and slave test */
#define BOARD_MCSPI_MASTER_INSTANCE     (1U)
#define BOARD_MCSPI_SLAVE_INSTANCE      (1U)

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

typedef enum
{
	APP_CARD_DETECT = 0,
	LCD_BRD_DETECT,
	SERDES_BRD_DETECT,
	HDMI_BRD_DETECT
}boardPresDetect_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* BOARD_CFG_H_ */
