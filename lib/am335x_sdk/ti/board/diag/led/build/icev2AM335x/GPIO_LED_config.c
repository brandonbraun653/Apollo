/*
 * Copyright (C) 2015-2016 Texas Instruments Incorporated - http://www.ti.com/
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
#define LED1    (0x0111) //STATUS_LED0 - UART3_TXD/GPIO5_3
#define LED2    (0x0110) //STATUS_LED1 - UART3_RXD/GPIO5_2
#define LED3    (0x0409) //STATUS_LED2 - UART3_RTSn/GPIO5_1
#define LED4    (0x021E) //STATUS_LED3 - UART3_CTSn/GPIO5_0
#define LED5    (0x0114) //STATUS_LED3 - UART3_CTSn/GPIO5_0
#define LED6    (0x0113) //STATUS_LED3 - UART3_CTSn/GPIO5_0

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    LED1 | GPIO_CFG_OUTPUT,
    LED2 | GPIO_CFG_OUTPUT,
    LED3 | GPIO_CFG_OUTPUT,
    LED4 | GPIO_CFG_OUTPUT,
    LED5 | GPIO_CFG_OUTPUT,
    LED6 | GPIO_CFG_OUTPUT
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
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
