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

#ifndef BOARD_CFG_H_
#define BOARD_CFG_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Board ID information */
#define BOARD_INFO_CPU_NAME             "OMAPL138"
#define BOARD_INFO_BOARD_NAME           "LCDKOMAPL138"

/* Memory Sections */
#define BOARD_DDR3_START_ADDR           (0xC0000000U)
#define BOARD_DDR3_SIZE                 (128 * 1024 * 1024UL)
#define BOARD_DDR3_END_ADDR             (BOARD_DDR3_START_ADDR + BOARD_DDR3_SIZE)

/* UART LLD instance number */
#define BOARD_UART_INSTANCE             (2U)

/* Audio codec I2C slave address */
#define BOARD_I2C_CODEC_ADDR            (0x18)

/* MMCSD instance */
#define BOARD_MMCSD_INSTANCE            (0)

/* SPI port cfg */
#define BOARD_SPI_NOR_INSTANCE          (0)
#define TEST_SPI_PORT                   (BOARD_SPI_NOR_INSTANCE)

/* GPIO pin and port numbers for on-board LED */
#define GPIO_LED0_PIN_NUM        (108U)  
#define GPIO_LED0_PORT_NUM       (0U)   
#define GPIO_LED1_PIN_NUM        (109U)  
#define GPIO_LED1_PORT_NUM       (0U)

#ifdef _TMS320C6X
#define GPIO_MUX_SEL             (16U) 
#else
#define GPIO_MUX_SEL             (0U)  
#endif

#define GPIO_MMC_SDCD_PORT_NUM          (0U)
#define GPIO_MMC_SDCD_PIN_NUM           (64U)

/* Number of LEDS connected to GPIO */
#define BOARD_GPIO_LED_NUM				(13U)

/* I2C instance as master for master/slave test example */
#define BOARD_I2C_MASTER_INSTANCE       0
/* I2C instance as salve for master/slave test example */
#define BOARD_I2C_SLAVE_INSTANCE        0

/* Ethernet PHY address */
#define BOARD_ETH_PHY_ADDR         (0x07)

#ifdef __cplusplus
}
#endif

#endif  /* BOARD_CFG_H_ */
