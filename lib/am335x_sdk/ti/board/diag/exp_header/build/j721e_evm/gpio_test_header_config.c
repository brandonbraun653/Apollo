/******************************************************************************
 * Copyright (c) 2019-2020 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   gpio_test_header_config.c
 *
 *  \brief  GPIO test header configuration file.
 *
 */
#include <stdio.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/csl/soc.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

/*
   Port and pin number mask for GPIO.
   Bits 7-0: Pin number  and Bits 15-8: Port number */
/* pin Mux Line GPIO0_48 --> PROFI_UART_SEL */
#define PIN1       (0x0030)
/* USS/IMU sensor header pin - 1 and 3 for I2C, 2,4,8 and 10 for UART, 7 and 9 for IMU */
#define PIN2       (0x0053)
#define PIN3       (0x0054)
#define PIN4       (0x001C)
#define PIN5       (0x001D)
/* MOTOR CONTROL header pins */
#define PIN6       (0x001A)
#define PIN7       (0x0014)
#define PIN8       (0x0013)
#define PIN9       (0x0012)
#define PIN10      (0x0027)
#define PIN11      (0x0009)
#define PIN12      (0x000A)
#define PIN13      (0x000B)
#define PIN14      (0x0028)
#define PIN15      (0x0006)
/* I3C test header pin - 2 and 3 */
#define PIN16      (0x003C)
#define PIN17      (0x003D)
/* PRG1_PWM pins for Alpha */
#define PIN18      (0x0029)
#define PIN19      (0x002A)
/* MOTOR CONTROL header pins */
#define PIN20      (0x0034)
#define PIN21      (0x000D)
#define PIN22      (0x000F)
#define PIN23      (0x000E)
#define PIN24      (0x0010)
#define PIN25      (0x0011)
#define PIN26      (0x000C)
#define PIN27      (0x0008)
#define PIN28      (0x0007)
#define PIN29      (0x0026)
#define PIN30      (0x0005)
#define PIN31      (0x0004)
/* MLB header pins CLOCK, SIGNAL and DATA */
#define PIN32      (0x007F)  /* GPIO0_127 */
#define PIN33      (0x007B)  /* GPIO0_123 */
#define PIN34      (0x0100)  /* GPIO1_0   */

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    /* pin Mux Line PROFI_UART_SEL */
    PIN1  | GPIO_CFG_OUTPUT,
    /* USS/IMU sensor header */
    PIN2 | GPIO_CFG_OUTPUT,
    PIN3 | GPIO_CFG_INPUT,
    PIN4 | GPIO_CFG_OUTPUT,
    PIN5 | GPIO_CFG_INPUT,
    PIN6 | GPIO_CFG_OUTPUT,
    PIN7 | GPIO_CFG_INPUT,
    /* MOTOR CONTROL header */
    PIN8 | GPIO_CFG_OUTPUT,
    PIN9 | GPIO_CFG_INPUT,
    PIN10 | GPIO_CFG_OUTPUT,
    PIN11 | GPIO_CFG_INPUT,
    PIN12 | GPIO_CFG_OUTPUT,
    PIN13 | GPIO_CFG_INPUT,
    PIN14 | GPIO_CFG_OUTPUT,
    PIN15 | GPIO_CFG_INPUT,
    PIN16 | GPIO_CFG_OUTPUT,
    PIN17 | GPIO_CFG_INPUT,
	/* PRG1_PWM pins for Alpha */
    PIN18 | GPIO_CFG_OUTPUT,
    PIN19 | GPIO_CFG_INPUT,
    PIN20 | GPIO_CFG_OUTPUT,
    PIN21 | GPIO_CFG_INPUT,
    PIN22 | GPIO_CFG_OUTPUT,
    PIN23 | GPIO_CFG_INPUT,
    PIN24 | GPIO_CFG_OUTPUT,
    PIN25 | GPIO_CFG_INPUT,
    PIN26 | GPIO_CFG_OUTPUT,
    PIN27 | GPIO_CFG_INPUT,
    PIN28 | GPIO_CFG_OUTPUT,
    PIN29 | GPIO_CFG_INPUT,
    PIN30 | GPIO_CFG_OUTPUT,
    PIN31 | GPIO_CFG_INPUT,
	/* MLB header pins CLOCK, SIGNAL and DATA */
    PIN32 | GPIO_CFG_OUTPUT,
    PIN33 | GPIO_CFG_OUTPUT,
    PIN34 | GPIO_CFG_OUTPUT,
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL,
};

/* GPIO Driver configuration structure */
GPIO_v0_Config GPIO_v0_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};
