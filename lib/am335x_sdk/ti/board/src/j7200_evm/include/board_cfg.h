/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 * details of different interfaces of the board.
 *
 */
#ifndef BOARD_CFG_H_
#define BOARD_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/board/board.h>
#include <ti/board/src/j7200_evm/include/board_pinmux.h>
#include <ti/csl/soc/j7200/src/cslr_wkup_ctrl_mmr.h>

/* Board ID information */
#define BOARD_INFO_CPU_NAME     "j7200"
#define BOARD_INFO_BOARD_NAME   "j7200_evm"

/* Memory sections */
#define BOARD_DDR_START_ADDR                            (0x80000000U)
#define BOARD_DDR_SIZE                                  (2048 * 1024 * 1024UL)
#define BOARD_DDR_END_ADDR                              (0xFFFFFFFFU)
/* Note with ECC enabled, all memory is not usable: 1/8 memory used for inline ECC */
#define BOARD_DDR_ECC_END_ADDR                          (0xF1FFFFFFU)

/* UART LLD instance number for primary UART port */
#define BOARD_UART_INSTANCE                             (0U)
/* UART LLD instance number for MAIN UART1 port */
#define BOARD_UART1_INSTANCE                            (1U)
/* UART LLD instance number for MAIN UART2 port */
#define BOARD_UART2_INSTANCE                            (2U)
/* UART LLD instance number for MAIN UART4 port */
#define BOARD_UART4_INSTANCE                            (4U)
/* WKUP UART LLD instance number */
#define BOARD_WKUP_UART_INSTANCE                        (0U)
/* ICSSG UART instance number */
#define BOARD_ICSSG_UART_INSTANCE                       (4U)

/* INFO and GESI board ID EEPROM address */
#define BOARD_EXP_CON_BOARDID_EEPROM_ADDRS              (0x52U)

/* I2C instance connected to EEPROM - WKUP I2C0 */
#define BOARD_I2C_EEPROM_INSTANCE                       (0U)

/* I2C instance for BOOT EEPROM */
#define BOARD_I2C_BOOT_EEPROM_INSTANCE                  (0U)

/* I2C address for Boot EEPROM */
#define BOARD_I2C_BOOT_EEPROM_ADDR                      (0x50U)
#define BOARD_I2C_BOOT_EEPROM_ADDR2                     (0x51U)

/* I2C address for Board Id EEPROM */
#define BOARD_I2C_EEPROM_ADDR                           (0x50U)

/* QSPI instance number */
#define BOARD_SPI_NOR_INSTANCE                          (1U)

/* I2C Instance connected to clock generator */
#define BOARD_CLOCK_GENERATOR_INSTANCE                  (0U)
/* I2C slave address of clock generator */
#define BOARD_I2C_CLOCK_GENERATOR1                      (0)
#define BOARD_I2C_CLOCK_GENERATOR2_ADDR1                (0x76)
#define BOARD_I2C_CLOCK_GENERATOR2_ADDR2                (0x77)
#define BOARD_I2C_QSGMII_CLOCK_GENERATOR_ADDR1          (0x76)
#define BOARD_I2C_QSGMII_CLOCK_GENERATOR_ADDR2          (0x77)
#define BOARD_I2C_PERI_CLOCK_GENERATOR                  (0x6D)

/* OSPI instance connected to OSPI NOR flash */
#define BOARD_OSPI_NOR_INSTANCE                         (0U)

/* HyperFlash instance number */
#define BOARD_HPF_INSTANCE                              (0)

/* I2C instance connected to IO Expander */
#define BOARD_I2C_IOEXP_DEVICE1_INSTANCE                (0U)
#define BOARD_I2C_IOEXP_DEVICE2_INSTANCE                (0U)
#define BOARD_I2C_IOEXP_DEVICE3_INSTANCE                (3U)
#define BOARD_I2C_IOEXP_DEVICE4_INSTANCE                (1U)
#define BOARD_I2C_IOEXP_DEVICE5_INSTANCE                (6U)
#define BOARD_I2C_AUDIO_IOEXP_DEVICE_INSTANCE           (3U)
#define BOARD_I2C_VIDEO_IOEXP_DEVICE_INSTANCE           (1U)

/* I2C IO Expander Slave devices */
#define BOARD_I2C_IOEXP_DEVICE1_ADDR                    (0x20U)
#define BOARD_I2C_IOEXP_DEVICE2_ADDR                    (0x22U)
#define BOARD_I2C_IOEXP_DEVICE3_ADDR                    (0x20U)
#define BOARD_I2C_IOEXP_DEVICE4_ADDR                    (0x20U)
#define BOARD_I2C_IOEXP_DEVICE5_ADDR                    (0x20U)
#define BOARD_I2C_AUDIO_IOEXP_DEVICE_ADDR               (0x21U)
#define BOARD_I2C_VIDEO_IOEXP_DEVICE_ADDR               (0x21U)

/* I2C instance connected to PMIC - WKUP I2C0 */
#define BOARD_I2C_PMIC_INSTANCE                         (0U)

/* I2C slave address of Leo PMICs */
#define BOARD_I2C_LEO_PMIC_A_ADDR                       (0x48U)
#define BOARD_I2C_LEO_PMIC_B_ADDR                       (0x4CU)
#define BOARD_I2C_LEO_PMIC_A_WDT_ADDR                   (0x12U)
#define BOARD_I2C_LEO_PMIC_B_WDT_ADDR                   (0x13U)

/* OSPI instance number */
#define BOARD_OSPI_INSTANCE                             (0)

/* I2C instance for External RTC */
#define BOARD_I2C_EXT_RTC_INSTANCE                      (0U)

/* I2C address for External RTC */
#define BOARD_I2C_EXT_RTC_ADDR                          (0x6FU)

/* Number of LEDS connected to IO expander on CP board */
#define BOARD_GPIO_LED_NUM                              (2U)

/* User LED Pin Details */
#define BOARD_I2C_USER_LED_INSTANCE                     (0U)

#define BOARD_USER_LED1                                 (6U)
#define BOARD_USER_LED2                                 (7U)
#define BOARD_USER_LED_IOEXP_PORT                       (2U)

#define BOARD_ICSS_EMAC_PORT_MAX                        (4)
#define BOARD_CPSW9G_EMAC_PORT_MAX                      (4)
#define BOARD_CPSW9G_PORT_MAX                           (8)


/* ICSS0 EMAC PHY register address */
#define BOARD_ICSS0_EMAC_PHY0_ADDR                      (0x0)
#define BOARD_ICSS0_EMAC_PHY1_ADDR                      (0x3u)

/* ICSS1 EMAC PHY register address */
#define BOARD_ICSS1_EMAC_PHY0_ADDR                      (0xCu)
#define BOARD_ICSS1_EMAC_PHY1_ADDR                      (0xFu)


/* PRG0_RGMII_RESETn */
#define BOARD_GPIO_IOEXP_ICSS0_EMAC_RST_PORT_NUM        (0U) /* GPIO0_61 */
#define BOARD_GPIO_IOEXP_ICSS0_EMAC_RST_PIN_NUM         (0x3DU)

/* PRG0_RGMII_INTn */
#define BOARD_GPIO_ICSS0_EMAC_INT_PORT_NUM              (1U) /* GPIO1_23 */
#define BOARD_GPIO_ICSS0_EMAC_INT_PIN_NUM               (0x17U)

/* PRG1_RGMII_RESETn */
#define BOARD_GPIO_IOEXP_ICSS1_EMAC_RST_PORT_NUM        (0U) /* GPIO0_62 */
#define BOARD_GPIO_IOEXP_ICSS1_EMAC_RST_PIN_NUM         (0x3EU)

/* PRG1_RGMII_INTn */
#define BOARD_GPIO_ICSS1_EMAC_INT_PORT_NUM              (1U) /* GPIO1_24 */
#define BOARD_GPIO_ICSS1_EMAC_INT_PIN_NUM               (0x18U)

/* MCU EMAC PHY MDIO address */
#define BOARD_MCU_EMAC_PHY_ADDR                         (0U)

/* HDMI IO Exp instances */
#define BOARD_HDMI_IO_EXP_INSTANCE                      (1U)
#define BOARD_HDMI_IO_SLAVE_ADDR                        (0x21U)

/* MCU EMAC MAX REG DUMP */
#define BOARD_MCU_EMAC_REG_DUMP_MAX                     ((16U))

/* MCU EMAC PHY register address definitions for reading strap values */
#define BOARD_MCU_EMAC_STRAP_STS1_ADDR                  (0x6EU)
#define BOARD_MCU_EMAC_STRAP_STS2_ADDR                  (0x6FU)

/* ICSS EMAC PHY register address definitions for reading strap values */
#define BOARD_ICSS_EMAC_STRAP_STS1_ADDR                (0x6EU)
#define BOARD_ICSS_EMAC_STRAP_STS2_ADDR                (0x6FU)

#define BOARD_SGMII_PORT_MAX                            (4U)

/* MCU_ETH1_RESETn */
#define BOARD_GPIO_IOEXP_MCU_EMAC_RST_PORT_NUM          (0U) /* WKUP_GPIO0_3 */
#define BOARD_GPIO_IOEXP_MCU_EMAC_RST_PIN_NUM           (0x03U)

/* MCU_ETH1_INTn */
#define BOARD_GPIO_MCU_EMAC_INT_PORT_NUM                (0U) /* WKUP_GPIO0_55 */
#define BOARD_GPIO_MCU_EMAC_INT_PIN_NUM                 (0X37U)

/* AUTOMATION HEADER */
#define BOARD_TEST_HEADER_I2C_INSTANCE                  (2U)
#define BOARD_I2C_BOOT_MODE_SW_ADDR                     (0x22U)

/* Temperature sensor i2c instance */
#define BOARD_TEMP_SENSOR_I2C_INSTANCE                  (0U)

/* Temperature sensor slave device addresses */
#define BOARD_TEMP_SENSOR_I2C_SLAVE_DEVICE1_ADDR        (0x48U)
#define BOARD_TEMP_SENSOR_I2C_SLAVE_DEVICE2_ADDR        (0x49U)

#define BOARD_I2C_CURRENT_MONITOR_INSTANCE              (2U)

/* Instance for interfaces connected to MMCSD */
#define BOARD_MMCSD_SD_INSTANCE                         (1U)
#define BOARD_MMCSD_EMMC_INSTANCE                       (0U)

/* Enable NOR flash driver */
#define BOARD_NOR_FLASH_IN

/* Maximum possible buffer length */
#define BOARD_EEPROM_MAX_BUFF_LENGTH                    (197U)

/* EEPROM board ID information */
#define BOARD_EEPROM_HEADER_FIELD_SIZE                  (7U)
#define BOARD_EEPROM_TYPE_SIZE                          (1U)
#define BOARD_EEPROM_STRUCT_LENGTH_SIZE                 (2U)
#define BOARD_EEPROM_MAGIC_NUMBER                       (0xEE3355AA)

#define BOARD_BOARD_FIELD_TYPE                          (0x10)
#define BOARD_DDR_FIELD_TYPE                            (0x11)
#define BOARD_MACINFO_FIELD_TYPE                        (0x13)
#define BOARD_ENDLIST                                   (0xFE)

#define BOARD_EEPROM_HEADER_ADDR                        (0U)

/* PinMux data to be programmed to configure a pin to be a GPIO */
#define PINMUX_GPIO_CFG                                 (0x00050007U)

/* Maximum number of SoC domains */
#define BOARD_SOC_DOMAIN_MAX     (3U)
/* Value for indicating SoC main domain */
#define BOARD_SOC_DOMAIN_MAIN    (0)
/* Value for indicating SoC wake-up domain */
#define BOARD_SOC_DOMAIN_WKUP    (1U)
/* Value for indicating SoC MCU domain */
#define BOARD_SOC_DOMAIN_MCU     (2U)
/* Maximum I2C instance number common across the domain */
#define BOARD_I2C_DOMAIN_INSTANCE_MAX     (2U)

/* SoC domain used by UART module */
#if defined (__TI_ARM_V7R5__)
#define BOARD_UART_SOC_DOMAIN    (BOARD_SOC_DOMAIN_MCU)
#else
#define BOARD_UART_SOC_DOMAIN    (BOARD_SOC_DOMAIN_MAIN)
#endif

/* Clock frequency for UART module */
#define BOARD_UART_CLK_MAIN      (48000000U)
#define BOARD_UART_CLK_WKUP      (96000000U)

/* Board detect ID for GESI */
#define BOARD_ID_GESI            (0x0)
/* Board detect ID for infotainment expansion board */
#define BOARD_ID_INFOTAINMENT    (0x1U)
/* Board detect ID for Fusion2 */
#define BOARD_ID_FUSION2         (0x2U)
/* Board detect ID for MV expansion board */
#define BOARD_ID_MV              (0x3U)
/* Board detect ID for LI expansion board */
#define BOARD_ID_LI              (0x4U)
/* Board detect ID for Ethernet expansion board */
#define BOARD_ID_ENET            (0x5U)
/* Board detect ID for display adapter board */
#define BOARD_ID_DISPLAY         (0x6U)
/* Board detect ID for dual PMIC SoM */
#define BOARD_ID_SOM             (0x7U)
/* Board detect ID for CP Board */
#define BOARD_ID_CP              (0x8U)

/* Maximum number of supporting board ID */
#define BOARD_ID_MAX_BOARDS      (0x9U)

#define BOARD_EEPROM_HEADER_LENGTH                      (4U)
#define BOARD_EEPROM_BOARD_NAME_LENGTH                  (8U)
#define BOARD_EEPROM_VERSION_LENGTH                     (4U)
#define BOARD_EEPROM_SERIAL_NO_LENGTH                   (12U)
#define BOARD_EEPROM_CONFIG_LENGTH                      (32U)

#define BOARD_EEPROM_BOARD_NAME_ADDR                    (BOARD_EEPROM_HEADER_ADDR + BOARD_EEPROM_HEADER_LENGTH)
#define BOARD_EEPROM_VERSION_ADDR                       (BOARD_EEPROM_BOARD_NAME_ADDR + BOARD_EEPROM_BOARD_NAME_LENGTH)
#define BOARD_EEPROM_SERIAL_NO_ADDR                     (BOARD_EEPROM_VERSION_ADDR + BOARD_EEPROM_VERSION_LENGTH)
#define BOARD_EEPROM_CONFIG_ADDR                        (BOARD_EEPROM_SERIAL_NO_ADDR + BOARD_EEPROM_SERIAL_NO_LENGTH)

#define BOARD_SOM_EEPROM_SLAVE_ADDR                   (0x50U)
#define BOARD_CP_EEPROM_SLAVE_ADDR                    (0x51U)
#define BOARD_ENET_EEPROM_SLAVE_ADDR                  (0x54U)
#define BOARD_GESI_EEPROM_SLAVE_ADDR                  (0x52U)
#define BOARD_CSI2_EEPROM_SLAVE_ADDR                  (0x52U)
#define BOARD_DISPLAY_EEPROM_SLAVE_ADDR               (0x00U) //J7ES_TBD: Need to update salve addr when board design is complete

#define BOARD_COMMON_EEPROM_I2C_INST                  (0)
#define BOARD_CSI2_EEPROM_I2C_INST                    (6)

#define BOARD_MMC_VOLTAGESWITCH_FN      Board_mmc_voltageSwitchFxn

/* Below macros are retained for compatibility with other K3 platforms.
   Need to review and remove them */
/* PRG0_ETH1_LED_LINK */
#define BOARD_GPIO_ICSS0_EMAC_PHY0_LED_LINK_PORT_NUM    (0)
#define BOARD_GPIO_ICSS0_EMAC_PHY0_LED_LINK_PIN_NUM     (0)

/* PRG0_ETH2_LED_LINK */
#define BOARD_GPIO_ICSS0_EMAC_PHY1_LED_LINK_PORT_NUM    (0)
#define BOARD_GPIO_ICSS0_EMAC_PHY1_LED_LINK_PIN_NUM     (0)

/* GPIO to drive PRG0 LED0 */
#define BOARD_GPIO_ICSS0_EMAC_LED0_PORT_NUM             (0)
#define BOARD_GPIO_ICSS0_EMAC_LED0_PIN_NUM              (0)

/* GPIO to drive PRG0 LED1 */
#define BOARD_GPIO_ICSS0_EMAC_LED1_PORT_NUM             (0)
#define BOARD_GPIO_ICSS0_EMAC_LED1_PIN_NUM              (0)

/* GPIO to drive PRG0 LED2 */
#define BOARD_GPIO_ICSS0_EMAC_LED2_PORT_NUM             (0)
#define BOARD_GPIO_ICSS0_EMAC_LED2_PIN_NUM              (0)

/* GPIO to drive PRG0 LED3 */
#define BOARD_GPIO_ICSS0_EMAC_LED3_PORT_NUM             (0)
#define BOARD_GPIO_ICSS0_EMAC_LED3_PIN_NUM              (0)

#define BOARD_GPIO_IOEXP_SPI_RST_PORT_NUM               (0)
#define BOARD_GPIO_IOEXP_SPI_RST_PIN_NUM                (0)

/* TEST_GPIO1 */
#define BOARD_GPIO_IOEXP_TEST_PORT_NUM                  (0)
#define BOARD_GPIO_IOEXP_TEST_PIN_NUM                   (0)

/* PRG1_ETH1_LED_LINK */
#define BOARD_GPIO_ICSS1_EMAC_PHY0_LED_LINK_PORT_NUM    (0)
#define BOARD_GPIO_ICSS1_EMAC_PHY0_LED_LINK_PIN_NUM     (0)

/* PRG1_ETH2_LED_LINK */
#define BOARD_GPIO_ICSS1_EMAC_PHY1_LED_LINK_PORT_NUM    (0)
#define BOARD_GPIO_ICSS1_EMAC_PHY1_LED_LINK_PIN_NUM     (0)

/* GPIO to drive PRG1 LED0 */
#define BOARD_GPIO_ICSS1_EMAC_LED0_PORT_NUM             (0)
#define BOARD_GPIO_ICSS1_EMAC_LED0_PIN_NUM              (0)

/* GPIO to drive PRG1 LED1 */
#define BOARD_GPIO_ICSS1_EMAC_LED1_PORT_NUM             (0)
#define BOARD_GPIO_ICSS1_EMAC_LED1_PIN_NUM              (0)

/* GPIO to drive PRG1 LED2 */
#define BOARD_GPIO_ICSS1_EMAC_LED2_PORT_NUM             (0)
#define BOARD_GPIO_ICSS1_EMAC_LED2_PIN_NUM              (0)

/* GPIO to drive PRG1 LED3 */
#define BOARD_GPIO_ICSS1_EMAC_LED3_PORT_NUM             (0)
#define BOARD_GPIO_ICSS1_EMAC_LED3_PIN_NUM              (0)

#define BOARD_GPIO_IOEXP_OSPI_RST_PORT_NUM              (0)
#define BOARD_GPIO_IOEXP_OSPI_RST_PIN_NUM               (0)

/* GPIO port & pin numbers for  MMC reset */
#define GPIO_MMC_SDCD_PORT_NUM                          (0)
#define GPIO_MMC_SDCD_PIN_NUM                           (0)

#define BOARD_GPIO_IOEXP_EMMC_RST_PORT_NUM              (0x00)
#define BOARD_GPIO_IOEXP_EMMC_RST_PIN_NUM               (0x00)

#define BOARD_I2C_TOUCH_INSTANCE                        (0)
#define BOARD_I2C_TOUCH_SLAVE_ADDR                      (0)

/* I2C instance Board Presence Circuit */
#define BOARD_PRES_WKUP_I2C_INSTANCE                    (0U)
/* I2C address Board Presence Circuit */
#define BOARD_PRES_DETECT_SLAVE_ADDR                    (0)

/* McSPI instance for master and slave test */
#define BOARD_MCSPI_MASTER_INSTANCE                     (1)
#define BOARD_MCSPI_SLAVE_INSTANCE                      (1)

/* LIN uart instance */
#define BOARD_LIN_UART_INSTANCE                         (8U)
#define BOARD_LIN_UART_BASE                             (CSL_UART8_BASE)

/* Default pinmux configuration of UART Tx pin used by ROM/SBL */
#define BOARD_MCU_UART_TX_PINMUX_VAL                    (PIN_MODE(0U) | ((PIN_PULL_DISABLE) & \
                                                         (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE)))
#define BOARD_MCU_UART_TX_PINMUX_ADDR                   (BOARD_WKUP_PMUX_CTRL_ADDR + PIN_WKUP_GPIO0_12)
#define BOARD_MCU_UART_TX_LOCK_KICK_ADDR                (CSL_WKUP_CTRL_MMR0_CFG0_BASE + \
                                                         CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK0)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif   /* BOARD_CFG_H_ */

