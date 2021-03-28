/******************************************************************************
 * Copyright (c) 2017 Texas Instruments Incorporated - http://www.ti.com
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

#ifndef BOARD_CFG_H_
#define BOARD_CFG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/starterware/include/hw/soc_am335x.h>

/* UART LLD instance number */
#define BOARD_UART_INSTANCE             0

/* McSPI serializer instance */
#define BOARD_MCSPI_SERIALIZER_INSTANCE 0

/* EEPROM Data read length */
#define I2C_EEPROM_RX_LENGTH            10U

#define GPIO_INTR_LED_BASE_ADDR         (SOC_GPIO_0_REGS)
#define GPIO_LED_PIN_NUM                (0x10U)

/* No of LEDs connected to GPIOs. */
#define BOARD_GPIO_LED_NUM              (12U)

/* McSPI instance to support Slave mode is 1.
 * To make the example generic accross AM57x
 * platforms, added 1 to the instance number.
 */
#define BOARD_MCSPI_MASTER_INSTANCE     (0x2U)
#define BOARD_MCSPI_SLAVE_INSTANCE      (0x2U)

/* Board ID information */
#define BOARD_INFO_CPU_NAME             "AM335x"
#define BOARD_INFO_BOARD_NAME           "ICEAMIC110"

/* Mmeory Sections */
#define BOARD_DDR3_START_ADDR           0x80010000
#define BOARD_DDR3_SIZE                 ((512 * 1024 * 1024UL) - 0x00010000)
#define BOARD_DDR3_END_ADDR             (BOARD_DDR3_START_ADDR + BOARD_DDR3_SIZE - 1)

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

/* Enable NOR flash driver */
#define BOARD_NOR_FLASH_IN

/* ICSS EMAC PHY address definitions */
#define BOARD_ICSS_EMAC_PORT0_PHY_ADDR  (1U)
#define BOARD_ICSS_EMAC_PORT1_PHY_ADDR  (13U)

typedef enum _BoardIcssClkOut
{
    BOARD_ICSS_PLL_CLK_200MHZ,
    BOARD_ICSS_PLL_CLK_225MHZ
} BoardIcssClkOut;

#ifdef __cplusplus
}
#endif

#endif
