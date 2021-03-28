/*
 * Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com/
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

#include <stdio.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/csl/soc.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

/* LEDS for AMIC Board*/
#define AMIC_LED4    (0x0111)
#define AMIC_LED5    (0x0110)
#define AMIC_LED6    (0x0409)
#define AMIC_LED9    (0x021E)
#define AMIC_LED7    (0x0114)
#define AMIC_LED8    (0x0113)
#define AMIC_LED2    (0x0108)
#define AMIC_LED3    (0x020E)
#define AMIC_LED10   (0x020F)
#define AMIC_LED1    (0x0412)
#define AMIC_LED12   (0x0414)
#define AMIC_LED11   (0x021C)
#define AMIC_CTRL    (0x0312)

/* GPIO Driver board specific pin configuration structure for AMIC  */
GPIO_PinConfig gpioPinConfigs_amic[]={
	AMIC_LED1  | GPIO_CFG_OUTPUT,
    AMIC_LED2  | GPIO_CFG_OUTPUT,
    AMIC_LED3  | GPIO_CFG_OUTPUT,
    AMIC_LED4  | GPIO_CFG_OUTPUT,
    AMIC_LED5  | GPIO_CFG_OUTPUT,
    AMIC_LED6  | GPIO_CFG_OUTPUT,
	AMIC_LED7  | GPIO_CFG_OUTPUT,
	AMIC_LED8  | GPIO_CFG_OUTPUT,
	AMIC_LED9  | GPIO_CFG_OUTPUT,
	AMIC_LED10 | GPIO_CFG_OUTPUT,
	AMIC_LED11 | GPIO_CFG_OUTPUT,
	AMIC_LED12 | GPIO_CFG_OUTPUT,
	AMIC_CTRL  | GPIO_CFG_OUTPUT
};

/* GPIO Driver call back functions  for amic*/
GPIO_CallbackFxn gpioCallbackFunctions_amic[] = {
	NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
	NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
	NULL
};

/* GPIO Driver configuration structure */
GPIO_v1_Config GPIO_v1_config = {
    gpioPinConfigs_amic,
    gpioCallbackFunctions_amic,
    sizeof(gpioPinConfigs_amic) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions_amic) / sizeof(GPIO_CallbackFxn),
    0,
};
