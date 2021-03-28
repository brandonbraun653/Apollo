/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/** ============================================================================
 *  @file       SPI_icss_hw.h
 *
 *  @brief      ESPI pin definitions
 *  ============================================================================
 */

#include <ti/starterware/include/hw/am437x.h>
#include <ti/starterware/include/hw/hw_control_am43xx.h>

/* GPO Pins */
#define ESPI_D0_OUT_PIN		(0)
#define ESPI_D0_OUT_PIN_NUM	(0)

#define ESPI_D1_OUT_PIN		(CTRL_CONF_LCD_DATA6)
#define ESPI_D1_OUT_PIN_NUM	(6)

#define ESPI_D2_OUT_PIN		(0)
#define ESPI_D2_OUT_PIN_NUM	(0)

#define ESPI_D3_OUT_PIN		(0)
#define ESPI_D3_OUT_PIN_NUM	(0)

#define ESPI_ALERT_PIN		(CTRL_CONF_GPMC_AD13)
#define ESPI_ALERT_PIN_NUM	(11)

#define ESPI_EN_PIN		(CTRL_CONF_GPMC_CSN1)
#define ESPI_EN_PIN_NUM		(8)

/* GPI Pins */
#define ESPI_D0_IN_PIN		(CTRL_CONF_GPMC_AD14)
#define ESPI_D0_IN_PIN_NUM	(16)

#define ESPI_D1_IN_PIN		(0)
#define ESPI_D1_IN_PIN_NUM	(0)

#define ESPI_D2_IN_PIN		(0)
#define ESPI_D2_IN_PIN_NUM	(0)

#define ESPI_D3_IN_PIN		(0)
#define ESPI_D3_IN_PIN_NUM	(0)

#define ESPI_SCL_PIN		(CTRL_CONF_GPMC_AD12)
#define ESPI_SCL_PIN_NUM	(10)

#define ESPI_CS_PIN		(CTRL_CONF_GPMC_CSN2)
#define ESPI_CS_PIN_NUM		(9)

/* GPIO Pins */
#define ESPI_RESET_GPIO_PORT	(5)
#define ESPI_RESET_GPIO_PIN	(9)
