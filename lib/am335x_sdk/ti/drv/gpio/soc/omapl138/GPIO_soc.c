/**
 *  \file   omapl138/GPIO_soc.c
 *
 *  \brief  OMAPL138 SOC specific GPIO hardware attributes.
 *
 *   This file contains the GPIO hardware attributes like base address and
 *   interrupt ids.
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

#include <ti/csl/csl_utils.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/csl_device_interrupt.h>
#include <ti/csl/cslr_bootcfg.h>
#include <ti/csl/hw_types.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

/** \brief Number of gpio pins for each port */
#define GPIO_NUM_PINS_PER_PORT           (144U)

/** \brief Number of gpio pins for each Bank */
#define GPIO_NUM_PINS_PER_EACH_BANK           (16U)

/** \brief Number of gpio banks for each port */
#define GPIO_NUM_BANKS_PER_PORT           (9U)

/** \brief Number of gpio ports present in the soc */
#define GPIO_NUM_PORTS                   (CSL_GPIO_CNT)

GPIO_IntCfg GPIO_defaultIntCfg[GPIO_NUM_BANKS_PER_PORT] =
{
    /* GPIO port 0 bank 0 */
    {
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in GPIO_socSetInitCfg() API */
        CSL_INTC_EVENTID_GPIO_BNK0_INT,
#else
        42,  /* ARM interrupt number */
        12,
#endif
        INVALID_INTC_MUX_NUM,  /* No INTC Mux */
        0,
        0
    },
    /* GPIO port 0 bank 1 */
    {
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in GPIO_socSetInitCfg() API */
        CSL_INTC_EVENTID_GPIO_BNK1_INT,
#else
        43,  /* ARM interrupt number */
        12,
#endif
        INVALID_INTC_MUX_NUM,  /* No INTC Mux */
        0,
        0
    },
    /* GPIO port 0 bank 2 */
    {
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in GPIO_socSetInitCfg() API */
        CSL_INTC_EVENTID_GPIO_BNK2_INT,
#else
        44,  /* ARM interrupt number */
        12,
#endif
        INVALID_INTC_MUX_NUM,  /* No INTC Mux */
        0,
        0
    },
    /* GPIO port 0 bank 3 */
    {
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in GPIO_socSetInitCfg() API */
        CSL_INTC_EVENTID_GPIO_BNK3_INT,
#else
        45,  /* ARM interrupt number */
        12,
#endif
        INVALID_INTC_MUX_NUM,  /* No INTC Mux */
        0,
        0
    },
    /* GPIO port 0 bank 4 */
    {
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in GPIO_socSetInitCfg() API */
        CSL_INTC_EVENTID_GPIO_BNK4_INT,
#else
        46,  /* ARM interrupt number */
        12,
#endif
        INVALID_INTC_MUX_NUM,  /* No INTC Mux */
        0,
        0
    },
    /* GPIO port 0 bank 5 */
    {
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in GPIO_socSetInitCfg() API */
        CSL_INTC_EVENTID_GPIO_BNK5_INT,
#else
        47,  /* ARM interrupt number */
        12,
#endif
        INVALID_INTC_MUX_NUM,  /* No INTC Mux */
        0,
        0
    },
    /* GPIO port 0 bank 6 */
    {
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in GPIO_socSetInitCfg() API */
        CSL_INTC_EVENTID_GPIO_BNK6_INT,
#else
        48,  /* ARM interrupt number */
        12,
#endif
        INVALID_INTC_MUX_NUM,  /* No INTC Mux */
        0,
        0
    },
    /* GPIO port 0 bank 7 */
    {
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in GPIO_socSetInitCfg() API */
        CSL_INTC_EVENTID_GPIO_BNK7_INT,
#else
        49,  /* ARM interrupt number */
        12,
#endif
        INVALID_INTC_MUX_NUM,  /* No INTC Mux */
        0,
        0
    },
    /* GPIO port 0 bank 8 */
    {   
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in GPIO_socSetInitCfg() API */
        CSL_INTC_EVENTID_GPIO_BNK8_INT,
#else
        50,  /* ARM interrupt number */
        12,
#endif
        INVALID_INTC_MUX_NUM,  /* No INTC Mux */
        0,
        0
    }

};

/* GPIO Pin interrupt configurations */
GPIO_IntCfg GPIO_intCfgs[GPIO_NUM_PORTS][GPIO_NUM_PINS_PER_PORT];

/* GPIO Driver hardware attributes */
GPIO_v0_hwAttrsList GPIO_v0_hwAttrs =
{
    {
        CSL_GPIO_0_REGS,
        &GPIO_intCfgs[0][0],
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

/**
 * \brief  This API sets the GPIO Bank for GPIO interrupts
 *
 * \param  index     GPIO bank number.
 * \param  pinNum    Pin number of the GPIO instance.
 * \param  cfg       pointer to GPIO interrupt configuration data
 *                   if NULL use the default configurations.
 * \return           0 success: -1: error
 *
 */
int32_t GPIO_socSetBankInt(uint32_t index, uint32_t pinNum, const GPIO_IntCfg *cfg)
{
    uint32_t intNum;
    uint32_t indxBank;
    GPIO_IntCfg *intCfg;
    int32_t retVal = 0;

    /* Get the GPIO pin interrupt number */
    if (index == 0)
    {
        intNum = pinNum;
    }
    else if (index == 1U)
    {
        intNum = pinNum + GPIO_NUM_PINS_PER_PORT;
        if (intNum > 255U)
        {
            retVal = -1;
        }
    }
    else
    {
        retVal = -1;
    }

    if(retVal == 0)
    {
    	indxBank = (pinNum / GPIO_NUM_PINS_PER_EACH_BANK);
        /* Setup GPIO pin interrupt configurations */
        intCfg = GPIO_v0_hwAttrs[index].intCfg + pinNum;
        if (cfg == NULL)
        {
            *intCfg = GPIO_defaultIntCfg[indxBank];
        }
        else
        {
            *intCfg = *cfg;
        }

    }

    return (retVal);
}
