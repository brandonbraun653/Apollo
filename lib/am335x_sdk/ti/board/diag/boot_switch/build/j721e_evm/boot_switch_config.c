/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   boot_switch_config.c
 *
 *  \brief  Boot switch gpio configuration file.
 *
 */
#include <stdio.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/csl/soc.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

/*
   Port and pin number mask for GPIO.
   Bits 7-0: Pin number  and Bits 15-8: Port number */

#define BOARD_BOOT_SW8_GPIO_PIN1          (0x0006U) /* GPIO0_6  */
#define BOARD_BOOT_SW8_GPIO_PIN2          (0x0026U) /* GPIO0_38 */
#define BOARD_BOOT_SW8_GPIO_PIN3          (0x0030U) /* GPIO0_48 */
#define BOARD_BOOT_SW8_GPIO_PIN4          (0x0050U) /* GPIO0_80 */
#define BOARD_BOOT_SW8_GPIO_PIN5          (0x010DU) /* GPIO1_13 */
#define BOARD_BOOT_SW8_GPIO_PIN6          (0x010EU) /* GPIO1_14 */
#define BOARD_BOOT_SW8_GPIO_PIN7          (0x0044U) /* GPIO0_68 */
#define BOARD_BOOT_SW8_GPIO_PIN8          (0x003CU) /* GPIO0_60 */

#define BOARD_BOOT_SW9_GPIO_PIN1         (0x0036U) /* WKUP_GPIO0_54 */
#define BOARD_BOOT_SW9_GPIO_PIN2         (0x0000U) /* WKUP_GPIO0_0  */
#define BOARD_BOOT_SW9_GPIO_PIN3         (0x0001U) /* WKUP_GPIO0_1  */
#define BOARD_BOOT_SW9_GPIO_PIN4         (0x0002U) /* WKUP_GPIO0_2  */
#define BOARD_BOOT_SW9_GPIO_PIN5         (0x000EU) /* WKUP_GPIO0_14 */
#define BOARD_BOOT_SW9_GPIO_PIN6         (0x000FU) /* WKUP_GPIO0_15 */
#define BOARD_BOOT_SW9_GPIO_PIN7         (0x000CU) /* WKUP_GPIO0_12 */
#define BOARD_BOOT_SW9_GPIO_PIN8         (0x000DU) /* WKUP_GPIO0_13 */

#define PIN1		(BOARD_BOOT_SW8_GPIO_PIN1)
#define PIN2		(BOARD_BOOT_SW8_GPIO_PIN2)
#define PIN3		(BOARD_BOOT_SW8_GPIO_PIN3)
#define PIN4		(BOARD_BOOT_SW8_GPIO_PIN4)
#define PIN5		(BOARD_BOOT_SW8_GPIO_PIN5)
#define PIN6		(BOARD_BOOT_SW8_GPIO_PIN6)
#define PIN7		(BOARD_BOOT_SW8_GPIO_PIN7)
#define PIN8		(BOARD_BOOT_SW8_GPIO_PIN8)

#define PIN9		(BOARD_BOOT_SW9_GPIO_PIN1)
#define PIN10		(BOARD_BOOT_SW9_GPIO_PIN2)
#define PIN11		(BOARD_BOOT_SW9_GPIO_PIN3)
#define PIN12		(BOARD_BOOT_SW9_GPIO_PIN4)
#define PIN13		(BOARD_BOOT_SW9_GPIO_PIN5)
#define PIN14		(BOARD_BOOT_SW9_GPIO_PIN6)
#define PIN15		(BOARD_BOOT_SW9_GPIO_PIN7)
#define PIN16		(BOARD_BOOT_SW9_GPIO_PIN8)

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    PIN1   | GPIO_CFG_INPUT,
    PIN2   | GPIO_CFG_INPUT,
    PIN3   | GPIO_CFG_INPUT,
    PIN4   | GPIO_CFG_INPUT,
    PIN5   | GPIO_CFG_INPUT,
    PIN6   | GPIO_CFG_INPUT,
    PIN7   | GPIO_CFG_INPUT,
    PIN8   | GPIO_CFG_INPUT,
    PIN9   | GPIO_CFG_INPUT,
    PIN10  | GPIO_CFG_INPUT,
    PIN11  | GPIO_CFG_INPUT,
    PIN12  | GPIO_CFG_INPUT,
    PIN13  | GPIO_CFG_INPUT,
    PIN14  | GPIO_CFG_INPUT,
    PIN15  | GPIO_CFG_INPUT,
    PIN16  | GPIO_CFG_INPUT
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
