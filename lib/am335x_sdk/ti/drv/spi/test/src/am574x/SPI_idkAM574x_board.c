/**
 *  \file   SPI_idkAM574x_board.c
 *
 *  \brief  AM574x IDK Board specific GPIO parameters.
 *
 *   This file contains the GPIO hardware parameters specific to board.
 */

/*
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_v1.h>
#include <stdio.h>
#include <ti/csl/soc.h>

/* control module register definitions */
#define CTRL_CORE_PAD_VIN1A_D15                     (0x130U)      //GPIO3_19
#define CTRL_CORE_PAD_VIN1A_D15_PILLUP              (0x20000 | 0x0E)

#define HW_WR_REG32(addr, data)   *(unsigned int*)(addr) =(unsigned int)(data)


/* Port and pin number mask for GPIO Load pin.
   Bits 7-0: Pin number  and Bits 15-8: Port number */
#define AM57X_IDK_GPIO_LD_PIN    (0x0313)


/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Output pin : AM57X_IDK_YEL_GRN */
    AM57X_IDK_GPIO_LD_PIN | GPIO_CFG_OUTPUT
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
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

/* Serializer data */
char serializerData[1] = {0x01};

void MCSPI_Board_crossbarInit(void)
{
    /* SPI3 Clock Enable */
    HW_WR_REG32(0x4A009800, 0x00000002);

    /* GPIO3 Clock Enable */
    HW_WR_REG32(0x4A009768, 0x00000102);

    /* GPIO3_19 */
    HW_WR_REG32((SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_VIN1A_D15),
        (CTRL_CORE_PAD_VIN1A_D15_PILLUP));

#ifdef C66X
    /* Configure xbar connect for MCSPI3: DSP_IRQ_43 (reserved) mapped to MCSPI3 intr */
    CSL_xbarIrqConfigure (CSL_XBAR_IRQ_CPU_ID_DSP1,
                          CSL_XBAR_INST_DSP1_IRQ_43, /* should match with C66 intc eventId in hwAttr */
                          CSL_XBAR_MCSPI3_IRQ);
#endif

#if defined (__TI_ARM_V7M4__)
    /* Configure xbar connect for MCSPI3: IPU1_IRQ_60 (reserved) mapped to MCSPI3 intr */
    CSL_xbarIrqConfigure (CSL_XBAR_IRQ_CPU_ID_IPU1,
                          CSL_XBAR_INST_IPU1_IRQ_60, /* should match with M4 intNum in hwAttr */
                          CSL_XBAR_MCSPI3_IRQ);
#endif
}
