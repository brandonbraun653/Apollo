/**
 *  \file   GPIO_idkAM572x_board.c
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
#include <ti/board/board.h>
#include <ti/csl/soc.h>
#include <ti/drv/gpio/test/led_blink/src/GPIO_board.h>

/* GPIO Defintions specific Rev1p2 Board */
/* GPIO pin number connected to the green LED */
#define GPIO_GRN_LED_PIN_NUM_1P2   (0x04)

/* GPIO port number connected to the green LED */
#define GPIO_GRN_LED_PORT_NUM_1P2  (0x04)

/* GPIO pin number connected to the yellow LED */
#define GPIO_YEL_LED_PIN_NUM_1P2   (0x05)

/* GPIO pin number connected to the yellow LED */
#define GPIO_YEL_LED_PORT_NUM_1P2  (0x04)


/* GPIO Defintions specific Rev1p3 Board */
/* GPIO pin number connected to the green LED */
#define GPIO_GRN_LED_PIN_NUM_1P3    (0x17)

/* GPIO port number connected to the green LED */
#define GPIO_GRN_LED_PORT_NUM_1P3   (0x07)

/* GPIO pin number connected to the yellow LED */
#define GPIO_YEL_LED_PIN_NUM_1P3    (0x16)

/* GPIO pin number connected to the yellow LED */
#define GPIO_YEL_LED_PORT_NUM_1P3   (0x07)

Board_IDInfo id;

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs_1p2[] = {
    /* Input pin with interrupt enabled */
    GPIO_DEVICE_CONFIG(GPIO_GRN_LED_PORT_NUM_1P2, GPIO_GRN_LED_PIN_NUM_1P2) |
    GPIO_CFG_IN_INT_RISING | GPIO_CFG_INPUT,

    /* Output pin */
    GPIO_DEVICE_CONFIG(GPIO_YEL_LED_PORT_NUM_1P2, GPIO_YEL_LED_PIN_NUM_1P2) |
    GPIO_CFG_OUTPUT
};


/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs_1p3[] = {
    /* Input pin with interrupt enabled */
    GPIO_DEVICE_CONFIG(GPIO_GRN_LED_PORT_NUM_1P3, GPIO_GRN_LED_PIN_NUM_1P3) |
    GPIO_CFG_IN_INT_RISING | GPIO_CFG_INPUT,

    /* Output pin */
    GPIO_DEVICE_CONFIG(GPIO_YEL_LED_PORT_NUM_1P3, GPIO_YEL_LED_PIN_NUM_1P3) |
    GPIO_CFG_OUTPUT
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL,
    NULL
};

/* GPIO Driver configuration structure */
GPIO_v1_Config GPIO_v1_config = {
    NULL,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs_1p2) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0x20,
    };


/*
 *  ======== GPIOApp_UpdateBoardInfo ========
 */
void GPIOApp_UpdateBoardInfo(void)
{
    Board_STATUS ret;
    ret = Board_getIDInfo(&id);
    if(ret == BOARD_SOK)
    {
        /* Check if version is 1.0 or 1.1 */
        if ((id.version[0] == '1' && id.version[2] == '2'))
        {
            /* Rev1p2 board specific gpio configurations */
            GPIO_v1_config.pinConfigs = (GPIO_PinConfig *)&gpioPinConfigs_1p2;
        }
        else
        {
            /* Rev1p3 board specific gpio configurations */
            GPIO_v1_config.pinConfigs = (GPIO_PinConfig *)&gpioPinConfigs_1p3;
        }
    }
}

/*
 *  ======== AppGPIOInit ========
 */
#if defined(idkAM572x)
void AppGPIOInit(void)
{
#if defined (__TI_ARM_V7M4__)
    CSL_XbarIrqCpuId                   cpu;
    uint32_t                           cpuEvent;
    uint32_t                           xbarIndex;
#endif

    /* GPIO4 Clock Enable */
    *(unsigned int*)0x4A009770 = (unsigned int)(0x00000102);

    /* Pinmux for GPIO4_4 */
    *(unsigned int*)0x4A003574 = (unsigned int)(0x0000000EU);

    /* Pinmux for GPIO4_5 */
    *(unsigned int*)0x4A003578 = (unsigned int)(0x0000000EU);

#if defined (__TI_ARM_V7M4__)
    if ((id.version[0] == '1' && id.version[2] == '2'))
    {
        /* Map IPU Intr 49 to GPIO4_IRQ_1 event id 27 */
        cpu = CSL_XBAR_IRQ_CPU_ID_IPU1;
        cpuEvent = 49;
        xbarIndex = cpuEvent - 22;

        /* Configure xbar */
        CSL_xbarIrqConfigure (cpu, xbarIndex, CSL_XBAR_GPIO4_IRQ_1);
    }
    else
    {
        /* Map IPU Intr 49 to GPIO7_IRQ_1 event id 30 */
        cpu = CSL_XBAR_IRQ_CPU_ID_IPU1;
        cpuEvent = 49;
        xbarIndex = cpuEvent - 22;

        /* Configure xbar */
        CSL_xbarIrqConfigure (cpu, xbarIndex, CSL_XBAR_GPIO7_IRQ_1);
    }
#endif
}
#endif

/*
 *  ======== GPIOAppUpdateConfig ========
 */
void GPIOAppUpdateConfig(uint32_t *gpioBaseAddr, uint32_t *gpioPin)
{
    if ((id.version[0] == '1' && id.version[2] == '2'))
    {
        *gpioBaseAddr = GPIO_INTR_LED_BASE_ADDR_1P2;
        *gpioPin      = GPIO_LED_PIN_NUM_1P2;
    }
    else
    {
        *gpioBaseAddr = GPIO_INTR_LED_BASE_ADDR_1P3;
        *gpioPin      = GPIO_LED_PIN_NUM_1P3;
    }
}
