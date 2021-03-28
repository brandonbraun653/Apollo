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
 *  \file   GPIO_LED_config.c
 *
 *  \brief  WKUP GPIO LED led configuration file.
 *
 */

#include <stdio.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/csl/soc.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include "board_cfg.h"

/* Port and pin number mask for IDK PRG0 and PRG1 ETHERNET LED's.
   Bits 7-0: Pin number  and Bits 15-8: Port number */
#define LED1             ((BOARD_IDK_GPIO_LD1_GREEN_PORT_NUM << 8) |\
                          (BOARD_IDK_GPIO_LD1_GREEN_PIN_NUM))
#define LED2             ((BOARD_IDK_GPIO_LD1_RED_PORT_NUM << 8) |\
                          (BOARD_IDK_GPIO_LD1_RED_PIN_NUM))
#define LED3             ((BOARD_IDK_GPIO_LD2_PORT_NUM << 8) |\
                          (BOARD_IDK_GPIO_LD2_PIN_NUM))
#define LED4             ((BOARD_IDK_GPIO_LD3_PORT_NUM << 8) |\
                          (BOARD_IDK_GPIO_LD3_PIN_NUM))
#define LED5             ((BOARD_IDK_GPIO_LD4_GREEN_PORT_NUM << 8) |\
                          (BOARD_IDK_GPIO_LD4_GREEN_PIN_NUM))
#define LED6             ((BOARD_IDK_GPIO_LD4_RED_PORT_NUM << 8) |\
                          (BOARD_IDK_GPIO_LD4_RED_PIN_NUM))
#define LED7             ((BOARD_IDK_GPIO_LD5_PORT_NUM << 8) |\
                          (BOARD_IDK_GPIO_LD5_PIN_NUM))
#define LED8             ((BOARD_IDK_GPIO_LD6_PORT_NUM << 8) |\
                          (BOARD_IDK_GPIO_LD6_PIN_NUM))

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    LED1 | GPIO_CFG_OUTPUT,
    LED2 | GPIO_CFG_OUTPUT,
    LED3 | GPIO_CFG_OUTPUT,
    LED4 | GPIO_CFG_OUTPUT,
    LED5 | GPIO_CFG_OUTPUT,
    LED6 | GPIO_CFG_OUTPUT,
    LED7 | GPIO_CFG_OUTPUT,
    LED8 | GPIO_CFG_OUTPUT
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
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
