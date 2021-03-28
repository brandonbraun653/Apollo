/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   boost_gpio_config.c
 *
 *  \brief  Boosterpack GPIO loopback test configuration file.
 *
 */
#include <stdio.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/csl/soc.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

/*
   Port and pin number mask for GPIO.
   Bits 7-0: Pin number  and Bits 15-8: Port number */
#define PIN1		(0x0055U)
#define PIN2		(0x0056U)
#define PIN3		(0x005DU)
#define PIN4		(0x0111U)
#define PIN5		(0x0052U)
#define PIN6		(0x0124U)
#define PIN7		(0x0125U)
#define PIN8		(0x0121U)
#define PIN9		(0x0129U)
#define PIN10		(0x012AU)
#define PIN11		(0x012BU)
#define PIN12		(0x012CU)
#define PIN13		(0x012DU)
#define PIN14		(0x012EU)
#define PIN15		(0x005FU)
#define PIN16		(0x005EU)
#define PIN17		(0x004DU)
#define PIN18		(0x004EU)
#define PIN19		(0x0112U)
#define PIN20		(0x0113U)
#define PIN21		(0x013DU)
#define PIN22		(0x013EU)
#define PIN23		(0x004FU)

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    PIN1   | GPIO_CFG_OUTPUT,
    PIN2   | GPIO_CFG_INPUT,
    PIN3   | GPIO_CFG_OUTPUT,
    PIN4   | GPIO_CFG_INPUT,
    PIN5   | GPIO_CFG_OUTPUT,
    PIN6   | GPIO_CFG_INPUT,
    PIN7   | GPIO_CFG_OUTPUT,
    PIN8   | GPIO_CFG_INPUT,
    PIN9   | GPIO_CFG_OUTPUT,
    PIN10  | GPIO_CFG_INPUT, 
    PIN11  | GPIO_CFG_OUTPUT,
    PIN12  | GPIO_CFG_INPUT,
    PIN13  | GPIO_CFG_OUTPUT,
    PIN14  | GPIO_CFG_INPUT,
    PIN15  | GPIO_CFG_OUTPUT,
    PIN16  | GPIO_CFG_INPUT,
    PIN17  | GPIO_CFG_OUTPUT,
    PIN18  | GPIO_CFG_INPUT,
    PIN19  | GPIO_CFG_OUTPUT,
    PIN20  | GPIO_CFG_INPUT,
    PIN21  | GPIO_CFG_OUTPUT,
    PIN22  | GPIO_CFG_INPUT,
    PIN23  | GPIO_CFG_INPUT
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
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

/* GPIO Driver configuration structure */
GPIO_v0_Config GPIO_v0_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};
