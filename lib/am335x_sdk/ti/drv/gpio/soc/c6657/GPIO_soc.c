/**
 *  \file   c6657/GPIO_soc.c
 *
 *  \brief  C6657 SOC specific GPIO hardware attributes.
 *
 *   This file contains the GPIO hardware attributes like base address and
 *   interrupt ids.
 */

/*
 * Copyright (C) 2015 - 2016 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/csl/csl_utils.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/csl_chipAux.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

/** \brief Number of gpio pins for each port */
#define GPIO_NUM_PINS_PER_PORT           (32U)

/** \brief Number of gpio ports present in the soc */
#define GPIO_NUM_PORTS                   (CSL_GPIO_PER_CNT)

/* GPIO Pin interrupt configurations */
GPIO_IntCfg GPIO_intCfgs[GPIO_NUM_PINS_PER_PORT] =
{
    /* GPIO port 0 pin 0 */
    {
        10, /* default DSP Interrupt vector number, can be set in GPIO_socSetInitCfg() API */
        CSL_GEM_GPINTN,  /* DSP corePac GPIO pin 0 interrupt event for Core 0 */
        INVALID_INTC_MUX_NUM,  /* CIC not used for GPIO pin 0 */
    },
    /* GPIO port 0 pin 1 */
    {
        10,
        CSL_GEM_GPINTN, /* DSP corePac GPIO pin 1 interrupt event for Core 1 */
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 2 */
    {
        10,
        CSL_GEM_GPINT2, /* DSP corePac GPIO pin 2 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 3 */
    {
        10,
        CSL_GEM_GPINT3, /* DSP corePac GPIO pin 3 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 4 */
    {
        10,
        CSL_GEM_GPINT4, /* DSP corePac GPIO pin 4 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 5 */
    {
        10,
        CSL_GEM_GPINT5, /* DSP corePac GPIO pin 5 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 6 */
    {
        10,
        CSL_GEM_GPINT6, /* DSP corePac GPIO pin 6 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 7 */
    {
        10,
        CSL_GEM_GPINT7, /* DSP corePac GPIO pin 7 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 8 */
    {
        10,
        CSL_GEM_GPINT8, /* DSP corePac GPIO pin 8 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 9 */
    {
        10,
        CSL_GEM_GPINT9, /* DSP corePac GPIO pin 9 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 10 */
    {
        10,
        CSL_GEM_GPINT10, /* DSP corePac GPIO pin 10 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
        /* GPIO port 0 pin 11 */
    {
        10,
        CSL_GEM_GPINT11, /* DSP corePac GPIO pin 11 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 12 */
    {
        10,
        CSL_GEM_GPINT12, /* DSP corePac GPIO pin 12 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 13 */
    {
        10,
        CSL_GEM_GPINT13, /* DSP corePac GPIO pin 13 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 14 */
    {
        10,
        CSL_GEM_GPINT14, /* DSP corePac GPIO pin 14 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 15 */
    {
        10,
        CSL_GEM_GPINT15, /* DSP corePac GPIO pin 15 interrupt event*/
        INVALID_INTC_MUX_NUM,
    },
    /* GPIO port 0 pin 16 */
    {
        10,
        25, /* default DSP INTC GPIO Event ID, can be set in GPIO_socSetInitCfg() API */
        0,  /* CIC number 0 */
        CSL_INTC0_GPINT16, /* CIC GPIO Event ID */
        3   /* default CIC Host Interrupt, map to CIC0_OUT(3+20*n) event */
    },
    /* GPIO port 0 pin 17 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT17,
        3
    },
    /* GPIO port 0 pin 18 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT18,
        3
    },
    /* GPIO port 0 pin 19 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT19,
        3
    },
    /* GPIO port 0 pin 20 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT20,
        3
    },
    /* GPIO port 0 pin 21 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT21,
        3
    },
    /* GPIO port 0 pin 22 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT22,
        3
    },
    /* GPIO port 0 pin 23 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT23,
        3
    },
    /* GPIO port 0 pin 24 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT24,
        3
    },
    /* GPIO port 0 pin 25 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT25,
        3
    },
    /* GPIO port 0 pin 26 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT26,
        3
    },
    /* GPIO port 0 pin 27 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT27,
        3
    },
    /* GPIO port 0 pin 28 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT28,
        3
    },
    /* GPIO port 0 pin 29 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT29,
        3
    },
    /* GPIO port 0 pin 30 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT30,
        3
    },
    /* GPIO port 0 pin 31 */
    {
        10,
        25,
        0,
        CSL_INTC0_GPINT31,
        3
    }
};

/* GPIO Driver hardware attributes */
GPIO_v0_hwAttrsList GPIO_v0_hwAttrs =
{
    {
        CSL_GPIO_REGS,
        &GPIO_intCfgs[0],
        NULL
    },

    {
        0,
        NULL,
        NULL
    }
};

/* GPIO configuration structure */
CSL_PUBLIC_CONST GPIOConfigList GPIO_config =
{
    {
        &GPIO_FxnTable_v0,
        NULL,
        &GPIO_v0_hwAttrs[0]
    },

    {
        NULL,
        NULL,
        NULL
    },
    /* "pad to full predefined length of array" */
    {
        NULL,
        NULL,
        NULL
    }
};

/**
 * \brief  This API gets the SoC level of GPIO intial configuration
 *
 * \param  index     GPIO instance index.
 * \param  cfg       Pointer to GPIO SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t GPIO_socGetInitCfg(uint32_t index, GPIO_v0_HwAttrs *cfg)
{
	int32_t ret = 0;

    if (index < GPIO_NUM_PORTS)
    {
        *cfg = GPIO_v0_hwAttrs[index];
    }
    else
    {
        ret = -1;
    }

    return ret;
}

/**
 * \brief  This API sets the SoC level of GPIO intial configuration
 *
 * \param  index     GPIO instance index.
 * \param  cfg       Pointer to GPIO SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t GPIO_socSetInitCfg(uint32_t index, const GPIO_v0_HwAttrs *cfg)
{
	int32_t ret = 0;

    if (index < GPIO_NUM_PORTS)
    {
        GPIO_v0_hwAttrs[index] = *cfg;
    }
    else
    {
        ret = -1;
    }

    return ret;
}

/**
 * \brief  This API gets the number of GPIO pins per port
 *         and GPIO number of ports
 *
 * \param  numPins     pointer to numPins variable.
 * \param  numPorts    pointer to numPorts variable.
 *
 * \return none
 *
 */
void GPIO_socGetNumPinsPorts(uint32_t *numPins, uint32_t *numPorts)
{
    *numPins = GPIO_NUM_PINS_PER_PORT;
    *numPorts = GPIO_NUM_PORTS;
}

