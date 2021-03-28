/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 * details of different interfaces of AM65xx idk board.
 *
 */
#ifndef BOARD_CFG_H_
#define BOARD_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

#define AM65XX_BETA_BOARD  (TRUE)

/* Board ID information */
#define BOARD_INFO_CPU_NAME 	"am65xx"
#define BOARD_INFO_BOARD_NAME 	"am65xx_idk"

/* Memory Sections */
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

/* I2C instance connected to PMIC - WKUP I2C0 */
#define BOARD_I2C_PMIC_INSTANCE                 (0U)

/* I2C slave address of TPS 62363 PMICs */
#define BOARD_I2C_TPS62363_PMIC_ADDR            (0x60U)

/* I2C instance connected to EEPROM - WKUP I2C0 */
#define BOARD_I2C_EEPROM_INSTANCE               (0U)

/* I2C instance connected to boot EEPROM - MAIN I2C2 */
/* This instance is used as temporary workaround due to
   silicon issue with MCU I2C instance
*/
#if defined(AM65XX_BETA_BOARD)
#define BOARD_I2C_BOOT_EEPROM_INSTANCE          (1U)
/* I2C address for LEDs in the Beta revision */
#define BOARD_I2C_IOEXP_DEVICE4_ADDR            (0x39)
#else
#define BOARD_I2C_BOOT_EEPROM_INSTANCE          (2U)
#endif

/* I2C address for EEPROM */
#define BOARD_I2C_BOOT_EEPROM_ADDR              (0x52U)
#define BOARD_I2C_EEPROM_ADDR                   (0x50U)
#define BOARD_I2C_EEPROM_ADDR2                  (0x51U)
#define BOARD_APP_EEPROM_ADDR                   (0x52U)
#define BOARD_LCD_EEPROM_ADDR                   (0x55U)
#define BOARD_SERDES_EEPROM_ADDR                (0x54U)

/* SPI instance number */
#define BOARD_SPI_NOR_INSTANCE                  (0U)

/* OSPI instance connected to OSPI NOR flash */
#define BOARD_OSPI_NOR_INSTANCE                 (0U)

/* I2C Slave devices used to control LED Industrial and RST Pins
   are connected to this instance */ 
#define BOARD_I2C_IOEXP_INSTANCE                      (0U)
/* Used to configure Ethernet PHY LED's */
#define BOARD_I2C_IOEXP_DEVICE1_ADDR                  (0x60U)
/* Used for device resets and MUX selections */
#define BOARD_I2C_IOEXP_DEVICE2_ADDR                  (0x21U)
/* Used for Controlling the industrial LED's on the IDK Application Card */
#define BOARD_I2C_IOEXP_DEVICE3_ADDR                  (0x63U)

#define BOARD_GPIO_IOEXP_SPI_RST_PORT_NUM             (0U)
#define BOARD_GPIO_IOEXP_SPI_RST_PIN_NUM              (2U)


/* OSPI instance number */
#define BOARD_OSPI_INSTANCE                           (0U)

#define BOARD_GPIO_IOEXP_OSPI_RST_PORT_NUM            (0U)
#define BOARD_GPIO_IOEXP_OSPI_RST_PIN_NUM             (1U)

/* GPIO port & pin numbers for  MMC reset */
#define GPIO_MMC_SDCD_PORT_NUM                  (0U)
#define GPIO_MMC_SDCD_PIN_NUM                   (0U)

#define BOARD_GPIO_IOEXP_EMMC_RST_PORT_NUM            (0x00U)
#define BOARD_GPIO_IOEXP_EMMC_RST_PIN_NUM             (0x00U)

/* I2C instance for External RTC */
#define BOARD_I2C_EXT_RTC_INSTANCE					  (0U)

/* I2C address for External RTC */
#define BOARD_I2C_EXT_RTC_ADDR						  (0x6FU)

#define BOARD_I2C_TOUCH_INSTANCE                      (1U)

#define BOARD_I2C_TOUCH_SLAVE_ADDR                    (0x14U)

/* Number of LEDS connected to GPIO on CP board */
#if defined(AM65XX_BETA_BOARD)
#define BOARD_GPIO_LED_NUM                            (2U)
#else
#define BOARD_GPIO_LED_NUM                            (4U)
#endif

/* Number fo ICSSG LED's connected to GPIO on IDK application board */
#define BOARD_IDK_GPIO_LED_NUM                        (8U)

/* I2C instance Board Presence Circuit */
#define BOARD_PRES_WKUP_I2C_INSTANCE                  (0U)
/* I2C address Board Presence Circuit */
#define BOARD_PRES_DETECT_SLAVE_ADDR                  (0x38U)

/* LED PIN NUMBERS */
/* Below macros are valid only for AM65xx Alpha board */
/* Pin and port numbers for LD16 on CP board */
#define BOARD_WKUP_GPIO_LD16_PORT_NUM           (0)    /* Port 0 */
#define BOARD_WKUP_GPIO_LD16_PIN_NUM            (0x08) /* Pin 8 */

/* Pin and port numbers for LD17 on CP board */
#define BOARD_WKUP_GPIO_LD17_PORT_NUM           (0)    /* Port 0 */
#define BOARD_WKUP_GPIO_LD17_PIN_NUM            (0x32) /* Pin 50 */
/* End of Aplha board specific macros */

/* Pin and port numbers for GREEN color on bicolor LED LD18 on CP board */
#define BOARD_WKUP_GPIO_LD18_GREEN_PORT_NUM           (0)    /* Port 0 */
#define BOARD_WKUP_GPIO_LD18_GREEN_PIN_NUM            (0)    /* Pin 0 */
/* Pin and port numbers for RED color on bicolor LED LD18 on CP board */
#define BOARD_WKUP_GPIO_LD18_RED_PORT_NUM           (0)      /* Port 0 */
#define BOARD_WKUP_GPIO_LD18_RED_PIN_NUM            (0x1)    /* Pin 1 */

/* IDK Application card LED PIN NUMBERS */
/* Pin and port numbers for GREEN color on bicolor LED LD1 on IDK board */
#define BOARD_IDK_GPIO_LD1_GREEN_PORT_NUM           (0x1)    /* Port 1 */
#define BOARD_IDK_GPIO_LD1_GREEN_PIN_NUM            (0x2E)   /* Pin 46 */
/* Pin and port numbers for RED color on bicolor LED LD1 on IDK board */
#define BOARD_IDK_GPIO_LD1_RED_PORT_NUM             (0x1)    /* Port 1 */
#define BOARD_IDK_GPIO_LD1_RED_PIN_NUM              (0x42)   /* Pin 66 */

/* Pin and port numbers for LD2 on IDK board */
#define BOARD_IDK_GPIO_LD2_PORT_NUM                 (0x1)    /* Port 1 */
#define BOARD_IDK_GPIO_LD2_PIN_NUM                  (0x30)   /* Pin 48 */

/* Pin and port numbers for LD3 on IDK board */
#define BOARD_IDK_GPIO_LD3_PORT_NUM                 (0x1)    /* Port 1 */
#define BOARD_IDK_GPIO_LD3_PIN_NUM                  (0x44)   /* Pin 68 */

/* Pin and port numbers for GREEN color on bicolor LED LD4 on IDK board */
#define BOARD_IDK_GPIO_LD4_GREEN_PORT_NUM           (0)      /* Port 0 */
#define BOARD_IDK_GPIO_LD4_GREEN_PIN_NUM            (0x49)   /* Pin 73 */
/* Pin and port numbers for RED color on bicolor LED LD4 on IDK board */
#define BOARD_IDK_GPIO_LD4_RED_PORT_NUM             (0x0)      /* Port 0 */
#define BOARD_IDK_GPIO_LD4_RED_PIN_NUM              (0x5D)     /* Pin 93 */

/* Pin and port numbers for LD5 on IDK board */
#define BOARD_IDK_GPIO_LD5_PORT_NUM                 (0)    /* Port 0 */
#define BOARD_IDK_GPIO_LD5_PIN_NUM                  (0x4B) /* Pin 75 */

/* Pin and port numbers for LD6 on IDK board */
#define BOARD_IDK_GPIO_LD6_PORT_NUM                 (0)    /* Port 0 */
#define BOARD_IDK_GPIO_LD6_PIN_NUM                  (0x5F) /* Pin 95 */


/* Push buttons */
#define BOARD_GPIO_PUSH_BUTTON_NUM	                  (2U)

#define GPIO_PUSH_BUTTON0_PORT_NUM                    (0x01U) /* Port 0 */
#define GPIO_PUSH_BUTTON0_PIN_NUM                     (0x0DU) /* Pin 13 */

#define GPIO_PUSH_BUTTON1_PORT_NUM                    (0x01U) /* Port 0 */
#define GPIO_PUSH_BUTTON1_PIN_NUM                     (0x1BU) /* Pin 27 */

#define BOARD_ICSS_EMAC_PORT_START              (0)
#define BOARD_ICSS_EMAC_PORT_END                (0x5U)
#define BOARD_MCU_ETH_PORT                      (0x6U)
#define BOARD_ICSS_EMAC_PORT_MAX                (0x6U)
#define BOARD_MCU_EMAC_PORT_MAX                 (0x1U)

/* ICSS0 EMAC PHY MDIO addresses */
#define BOARD_ICSS0_EMAC_PHY0_ADDR              (0x0U)
#define BOARD_ICSS0_EMAC_PHY1_ADDR              (0x3U)

/* ETH0/1_RESETn */
#define BOARD_GPIO_ICSS0_EMAC_PHY_RST_PORT_NUM        (1U) /* GPIO1_34 */
#define BOARD_GPIO_ICSS0_EMAC_PHY_RST_PIN_NUM         (34U)

/* ETH0/1_INTn */
#define BOARD_GPIO_ICSS0_EMAC_PHY_INT_PORT_NUM        (1U) /* GPIO1_37 */
#define BOARD_GPIO_ICSS0_EMAC_PHY_INT_PIN_NUM         (37U)

/* ETH0_LED_LINK */
#define BOARD_GPIO_ICSS0_EMAC_PHY0_LED_LINK_PORT_NUM  (1U) /* GPIO1_39 */
#define BOARD_GPIO_ICSS0_EMAC_PHY0_LED_LINK_PIN_NUM   (39U)

/* ETH1_LED_LINK */
#define BOARD_GPIO_ICSS0_EMAC_PHY1_LED_LINK_PORT_NUM  (0U) /* GPIO0_64 */
#define BOARD_GPIO_ICSS0_EMAC_PHY1_LED_LINK_PIN_NUM   (64U)

/* GPIO to drive PRG0 LED0 */
#define BOARD_GPIO_ICSS0_EMAC_LED0_PORT_NUM           (0U) /* GPIO0_83 */
#define BOARD_GPIO_ICSS0_EMAC_LED0_PIN_NUM            (83U)

/* GPIO to drive PRG0 LED1 */
#define BOARD_GPIO_ICSS0_EMAC_LED1_PORT_NUM           (0U) /* GPIO0_93 */
#define BOARD_GPIO_ICSS0_EMAC_LED1_PIN_NUM            (93U)

/* GPIO to drive PRG0 LED2 */
#define BOARD_GPIO_ICSS0_EMAC_LED2_PORT_NUM           (0U) /* GPIO0_94 */
#define BOARD_GPIO_ICSS0_EMAC_LED2_PIN_NUM            (94U)

/* GPIO to drive PRG0 LED3 */
#define BOARD_GPIO_ICSS0_EMAC_LED3_PORT_NUM           (0U) /* GPIO0_95 */
#define BOARD_GPIO_ICSS0_EMAC_LED3_PIN_NUM            (95U)

/* ICSS1 EMAC PHY MDIO addresses */
#define BOARD_ICSS1_EMAC_PHY0_ADDR              (0x0U)
#define BOARD_ICSS1_EMAC_PHY1_ADDR              (0x03U)

/* ETH2/3_RESETn */
#define BOARD_GPIO_ICSS1_EMAC_RST_PORT_NUM            (0U) /* GPIO0_61 */
#define BOARD_GPIO_ICSS1_EMAC_RST_PIN_NUM             (61U)

/* ETH2/3_INTn */
#define BOARD_GPIO_ICSS1_EMAC_INT_PORT_NUM            (0U) /* GPIO0_81 */
#define BOARD_GPIO_ICSS1_EMAC_INT_PIN_NUM             (81U)

/* ETH2_LED_LINK */
#define BOARD_GPIO_ICSS1_EMAC_PHY0_LED_LINK_PORT_NUM  (1U) /* GPIO1_57 */
#define BOARD_GPIO_ICSS1_EMAC_PHY0_LED_LINK_PIN_NUM   (57U)

/* ETH3_LED_LINK */
#define BOARD_GPIO_ICSS1_EMAC_PHY1_LED_LINK_PORT_NUM  (0U) /* GPIO0_84 */
#define BOARD_GPIO_ICSS1_EMAC_PHY1_LED_LINK_PIN_NUM   (84U)

/* GPIO to drive PRG1 LED0 */
#define BOARD_GPIO_ICSS1_EMAC_LED0_PORT_NUM           (1U) /* GPIO1_54 */
#define BOARD_GPIO_ICSS1_EMAC_LED0_PIN_NUM            (54U)

/* GPIO to drive PRG1 LED1 */
#define BOARD_GPIO_ICSS1_EMAC_LED1_PORT_NUM           (1U) /* GPIO1_38 */
#define BOARD_GPIO_ICSS1_EMAC_LED1_PIN_NUM            (38U)

/* GPIO to drive PRG1 LED2 */
#define BOARD_GPIO_ICSS1_EMAC_LED2_PORT_NUM           (1U) /* GPIO1_59 */
#define BOARD_GPIO_ICSS1_EMAC_LED2_PIN_NUM            (59U)

/* GPIO to drive PRG1 LED3 */
#define BOARD_GPIO_ICSS1_EMAC_LED3_PORT_NUM           (1U) /* GPIO1_58 */
#define BOARD_GPIO_ICSS1_EMAC_LED3_PIN_NUM            (58U)

/* ICSS2 EMAC PHY MDIO addresses */
#define BOARD_ICSS2_EMAC_PHY0_ADDR              (0x0U)
#define BOARD_ICSS2_EMAC_PHY1_ADDR              (0x03U)

/* PRG2_RGMII_RESETn */
#define BOARD_GPIO_IOEXP_ICSS2_EMAC_RST_PORT_NUM      (0U)
#define BOARD_GPIO_IOEXP_ICSS2_EMAC_RST_PIN_NUM       (3U)

/* PRG2_RGMII_INTn */
#define BOARD_GPIO_ICSS2_EMAC_INT_PORT_NUM            (0U) /* WKUP_GPIO0_24  */
#define BOARD_GPIO_ICSS2_EMAC_INT_PIN_NUM             (24U)

/* PRG2_ETH1_LED_LINK */
#define BOARD_GPIO_ICSS2_EMAC_PHY0_LED_LINK_PORT_NUM  (1U) /* GPIO1_13 */
#define BOARD_GPIO_ICSS2_EMAC_PHY0_LED_LINK_PIN_NUM   (13U)

/* PRG2_ETH2_LED_LINK */
#define BOARD_GPIO_ICSS2_EMAC_PHY1_LED_LINK_PORT_NUM  (1U) /* GPIO1_14 */
#define BOARD_GPIO_ICSS2_EMAC_PHY1_LED_LINK_PIN_NUM   (14U)

/* GPIO to drive PRG2 LED0 */
#define BOARD_GPIO_ICSS2_EMAC_LED0_PORT_NUM           (0U) /* WKUP_GPIO0_13 */
#define BOARD_GPIO_ICSS2_EMAC_LED0_PIN_NUM            (13U)

/* GPIO to drive PRG2 LED1 */
#define BOARD_GPIO_ICSS2_EMAC_LED1_PORT_NUM           (0U) /* WKUP_GPIO0_0 */
#define BOARD_GPIO_ICSS2_EMAC_LED1_PIN_NUM            (0U)

/* GPIO to drive PRG2 LED2 */
#define BOARD_GPIO_ICSS2_EMAC_LED2_PORT_NUM           (0U) /* WKUP_GPIO0_1 */
#define BOARD_GPIO_ICSS2_EMAC_LED2_PIN_NUM            (1U)

/* GPIO to drive PRG2 LED3 */
#define BOARD_GPIO_ICSS2_EMAC_LED3_PORT_NUM           (0U) /* WKUP_GPIO0_27 */
#define BOARD_GPIO_ICSS2_EMAC_LED3_PIN_NUM            (27U)

/* MCU EMAC PHY MDIO address */
#define BOARD_MCU_EMAC_PHY_ADDR                       (0U)

/* MCU EMAC MAX REG DUMP */
#define BOARD_MCU_EMAC_REG_DUMP_MAX                   (16U)

/* MCU EMAC PHY register address definitions for reading strap values */
#define BOARD_MCU_EMAC_STRAP_STS1_ADDR                (0x6EU)
#define BOARD_MCU_EMAC_STRAP_STS2_ADDR                (0x6FU)

/* MCU EMAC PHY register address definitions for reading strap values */
#define BOARD_ICSS_EMAC_STRAP_STS1_ADDR                (0x6EU)
#define BOARD_ICSS_EMAC_STRAP_STS2_ADDR                (0x6FU)


/* MCU_ETH1_RESETn */
#define BOARD_GPIO_IOEXP_MCU_EMAC_RST_PORT_NUM        (0U)
#define BOARD_GPIO_IOEXP_MCU_EMAC_RST_PIN_NUM         (4U)

/* MCU_ETH1_INTn */
#define BOARD_GPIO_MCU_EMAC_INT_PORT_NUM              (0U) /* WKUP_GPIO0_32 */
#define BOARD_GPIO_MCU_EMAC_INT_PIN_NUM               (32U)

/* AUTOMATION HEADER */
#define BOARD_TEST_HEADER_I2C_INSTANCE                (2U)
#define BOARD_I2C_BOOT_MODE_SW_ADDR                   (0x22U)

/* TEST_GPIO1 */
#define BOARD_GPIO_IOEXP_TEST_PORT_NUM                (1U)
#define BOARD_GPIO_IOEXP_TEST_PIN_NUM                 (2U)

/* Temperature sensor i2c instance */
#define BOARD_TEMP_SENSOR_I2C_INSTANCE                (2U)

/* Temperature sensor slave device addresses */
#define BOARD_TEMP_SENSOR_I2C_SLAVE_DEVICE1_ADDR       (0x48U)
#define BOARD_TEMP_SENSOR_I2C_SLAVE_DEVICE2_ADDR       (0x49U)

#define BOARD_I2C_CURRENT_MONITOR_INSTANCE      (2U)

/* I2C instance connected to ROTARY SWITCH */
#define BOARD_ROTARY_SWICH_INSTANCE  (0U)

/* I2C address for ROTARY SWITCH */
#define BOARD_I2C_ROTARY_SWITCH		 (0X41U)

/* Instance for interfaces connected to MMCSD */
#define BOARD_MMCSD_SD_INSTANCE                 (1U)
#define BOARD_MMCSD_EMMC_INSTANCE               (0)

/* Enable NOR flash driver */
#define BOARD_NOR_FLASH_IN

/* McSPI instance for master and slave test */
#define BOARD_MCSPI_MASTER_INSTANCE     (1U)
#define BOARD_MCSPI_SLAVE_INSTANCE      (1U)

/* Maximum possible buffer length */
#define BOARD_EEPROM_MAX_BUFF_LENGTH            (197U)

/* EEPROM board ID information */
#define BOARD_EEPROM_HEADER_FIELD_SIZE          (7U)
#define BOARD_EEPROM_TYPE_SIZE                  (1U)
#define BOARD_EEPROM_STRUCT_LENGTH_SIZE         (2U)
#define BOARD_EEPROM_MAGIC_NUMBER               (0xEE3355AA)

#define BOARD_BOARD_FIELD_TYPE                  (0x10)
#define BOARD_DDR_FIELD_TYPE                    (0x11)
#define BOARD_MACINFO_FIELD_TYPE                (0x13)
#define BOARD_ENDLIST                           (0xFE)

#define BOARD_EEPROM_HEADER_ADDR                (0U)

typedef enum
{
	APP_CARD_DETECT = 0,
	LCD_BRD_DETECT,
	SERDES_BRD_DETECT,
	HDMI_BRD_DETECT
}boardPresDetect_t;

/* Below EEPROM board ID info macros are not valid for AM65xx platform. 
   Provided here for backward build compatibility 
 */
#define BOARD_EEPROM_HEADER_LENGTH		(4U)
#define BOARD_EEPROM_BOARD_NAME_LENGTH	(8U)
#define BOARD_EEPROM_SERIAL_NO_LENGTH	(12U)
#define BOARD_EEPROM_VERSION_LENGTH		(4U)
#define BOARD_EEPROM_CONFIG_LENGTH      (32U)

#define BOARD_EEPROM_BOARD_NAME_ADDR	(BOARD_EEPROM_HEADER_ADDR + BOARD_EEPROM_HEADER_LENGTH)
#define BOARD_EEPROM_VERSION_ADDR		(BOARD_EEPROM_BOARD_NAME_ADDR + BOARD_EEPROM_BOARD_NAME_LENGTH)
#define BOARD_EEPROM_SERIAL_NO_ADDR		(BOARD_EEPROM_VERSION_ADDR + BOARD_EEPROM_VERSION_LENGTH)
#define BOARD_EEPROM_CONFIG_ADDR        (BOARD_EEPROM_SERIAL_NO_ADDR + BOARD_EEPROM_SERIAL_NO_LENGTH)

/* Maximum number of SoC domains */
#define BOARD_SOC_DOMAIN_MAX     (3U)
/* Value for indicating SoC main domain */
#define BOARD_SOC_DOMAIN_MAIN    (0)
/* Value for indicating SoC wake-up domain */
#define BOARD_SOC_DOMAIN_WKUP    (1U)
/* Value for indicating SoC MCU domain */
#define BOARD_SOC_DOMAIN_MCU     (2U)

void Board_uartTxPinmuxConfig(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* BOARD_CFG_H_ */
