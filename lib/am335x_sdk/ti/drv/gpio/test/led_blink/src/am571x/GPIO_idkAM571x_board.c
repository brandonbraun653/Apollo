/**
 *  \file   GPIO_idkAM571x_board.c
 *
 *  \brief  AM571x IDK EVM board specific GPIO parameters.
 *
 */

/*
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/drv/gpio/soc/GPIO_soc.h>

/* GPIO pin number connected to the green LED */
#define GPIO_GRN_LED_PIN_NUM      (0x15)

/* GPIO port number connected to the green LED */
#define GPIO_GRN_LED_PORT_NUM     (0x02)

/* GPIO pin number connected to the yellow LED */
#define GPIO_YEL_LED_PIN_NUM      (0x13)

/* GPIO pin number connected to the yellow LED */
#define GPIO_YEL_LED_PORT_NUM     (0x02)

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Input pin with interrupt enabled */
    GPIO_DEVICE_CONFIG(GPIO_GRN_LED_PORT_NUM, GPIO_GRN_LED_PIN_NUM) |
    GPIO_CFG_IN_INT_RISING | GPIO_CFG_INPUT,

    /* Output pin */
    GPIO_DEVICE_CONFIG(GPIO_YEL_LED_PORT_NUM, GPIO_YEL_LED_PIN_NUM) |
    GPIO_CFG_OUTPUT
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL,
    NULL
};

/* GPIO Driver configuration structure */
GPIO_v1_Config GPIO_v1_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0x20,
    };


/*
 *  ======== AppGPIOInit ========
 */
void AppGPIOInit(void)
{
    /* GPIO2 Clock Enable */
    *(unsigned int*)0x4A009760 = (unsigned int)(0x00000102);

    /* Pinmux for GPIO2_21 */
    *(unsigned int*)0x4A0034BC = (unsigned int)(0x0000000EU);

    /* Pinmux for GPIO2_19 */
    *(unsigned int*)0x4A0034B4 = (unsigned int)(0x0000000EU);
}
