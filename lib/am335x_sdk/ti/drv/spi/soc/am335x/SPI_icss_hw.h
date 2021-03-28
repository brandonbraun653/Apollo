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

#include <ti/starterware/include/hw/soc_am335x.h>
#include <ti/starterware/include/hw/hw_control_am335x.h>

/* GPO Pins */
#define ESPI_D0_OUT_PIN		(CONTROL_CONF_LCD_DATA(4))
#define ESPI_D0_OUT_PIN_NUM	(4)

#define ESPI_D1_OUT_PIN		(CONTROL_CONF_LCD_DATA(5))
#define ESPI_D1_OUT_PIN_NUM	(5)

#define ESPI_D2_OUT_PIN		(CONTROL_CONF_LCD_DATA(6))
#define ESPI_D2_OUT_PIN_NUM	(6)

#define ESPI_D3_OUT_PIN		(CONTROL_CONF_LCD_DATA(7))
#define ESPI_D3_OUT_PIN_NUM	(7)

#define ESPI_ALERT_PIN		(CONTROL_CONF_LCD_HSYNC)
#define ESPI_ALERT_PIN_NUM	(9)

#define ESPI_EN_PIN		(CONTROL_CONF_LCD_PCLK)
#define ESPI_EN_PIN_NUM		(10)

/* GPI Pins */
#define ESPI_D0_IN_PIN		(CONTROL_CONF_LCD_DATA(0))
#define ESPI_D0_IN_PIN_NUM	(0)

#define ESPI_D1_IN_PIN		(CONTROL_CONF_LCD_DATA(1))
#define ESPI_D1_IN_PIN_NUM	(1)

#define ESPI_D2_IN_PIN		(CONTROL_CONF_LCD_DATA(2))
#define ESPI_D2_IN_PIN_NUM	(2)

#define ESPI_D3_IN_PIN		(CONTROL_CONF_LCD_DATA(3))
#define ESPI_D3_IN_PIN_NUM	(3)

#define ESPI_SCL_PIN		(CONTROL_CONF_LCD_VSYNC)
#define ESPI_SCL_PIN_NUM	(8)

#define ESPI_CS_PIN		(CONTROL_CONF_LCD_AC_BIAS_EN)
#define ESPI_CS_PIN_NUM		(11)

/* GPIO Pins */
#define ESPI_RESET_GPIO_PORT	(3)
#define ESPI_RESET_GPIO_PIN	(19)
