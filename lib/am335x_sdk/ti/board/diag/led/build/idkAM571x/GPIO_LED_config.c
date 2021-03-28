/*
 * Copyright (C) 2015 Texas Instruments Incorporated - http://www.ti.com/
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

/* Port and pin number mask for Green LED.
   Bits 7-0: Pin number  and Bits 15-8: Port number */
#define LED1	(0x0613)
#define LED2	(0x0400)
#define LED3	(0x0104)
#define LED4	(0x0607)
#define LED5	(0x021D)
#define LED6	(0x0105)
#define LED7	(0x0709)
#define LED8	(0x0708)
#define LED9	(0x070A)
#define LED10	(0x070B)
#define LED11	(0x0110)
#define LED12	(0x0111)
#define LED13	(0x0219)
#define LED14	(0x021A)
#define LED15	(0x021B)
#define LED16	(0x021C)
#define LED17	(0x0215)
#define LED18	(0x0213)

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
	LED1 | GPIO_CFG_OUTPUT,
	LED2 | GPIO_CFG_OUTPUT,
	LED3 | GPIO_CFG_OUTPUT,
	LED4 | GPIO_CFG_OUTPUT,
	LED5 | GPIO_CFG_OUTPUT,
	LED6 | GPIO_CFG_OUTPUT,
	LED7 | GPIO_CFG_OUTPUT,
	LED8 | GPIO_CFG_OUTPUT,
	LED9 | GPIO_CFG_OUTPUT,
	LED10 | GPIO_CFG_OUTPUT,
	LED11 | GPIO_CFG_OUTPUT,
	LED12 | GPIO_CFG_OUTPUT,
	LED13 | GPIO_CFG_OUTPUT,
	LED14 | GPIO_CFG_OUTPUT,
	LED15 | GPIO_CFG_OUTPUT,
	LED16 | GPIO_CFG_OUTPUT,
	LED17 | GPIO_CFG_OUTPUT,
	LED18 | GPIO_CFG_OUTPUT
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
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
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

/* GPIO Driver configuration structure */
GPIO_v1_Config GPIO_v1_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};
