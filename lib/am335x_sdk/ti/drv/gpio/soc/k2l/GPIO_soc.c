/**
 *  \file   k2l/GPIO_soc.c
 *
 *  \brief  K2L SOC specific GPIO hardware attributes.
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
#include <ti/csl/csl_device_interrupt.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

/** \brief Number of gpio pins for each port */
#define GPIO_NUM_PINS_PER_PORT           (64U)

/** \brief Number of gpio ports present in the soc */
#define GPIO_NUM_PORTS                   (CSL_GPIO_PER_CNT)

/* GPIO Pin interrupt configurations */
GPIO_IntCfg GPIO_intCfgs[GPIO_NUM_PORTS][GPIO_NUM_PINS_PER_PORT] =
{
    {
        /* GPIO port 0 pin 0 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in GPIO_socSetInitCfg() API */
            CSL_C66X_COREPAC_GPIO_INTN,  /* GPIO pin interrupt event for DSP corePac 0 */
#else
            CSL_ARM_GIC_GPIO_INT0 + 32,  /* GPIO pin interrupt event for ARM GIC */
            0,
#endif
            INVALID_INTC_MUX_NUM,        /* CIC not used for GPIO pin 0 */
            0,
            0
        },
        /* GPIO port 0 pin 1 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INTN,  /* GPIO pin interrupt event for DSP corePac 1 */
#else
            CSL_ARM_GIC_GPIO_INT1 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 2 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INTN,  /* GPIO pin interrupt event for DSP corePac 2 */
#else
            CSL_ARM_GIC_GPIO_INT2 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 3 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INTN,  /* GPIO pin interrupt event for DSP corePac 3 */
#else
            CSL_ARM_GIC_GPIO_INT3 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 4 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INTN,  /* GPIO pin interrupt event for DSP corePac 4 */
#else
            CSL_ARM_GIC_GPIO_INT4 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 5 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INTN,  /* GPIO pin interrupt event for DSP corePac 5 */
#else
            CSL_ARM_GIC_GPIO_INT5 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 6 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INTN,  /* GPIO pin interrupt event for DSP corePac 6 */
#else
            CSL_ARM_GIC_GPIO_INT6 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 7 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INTN,  /* GPIO pin interrupt event for DSP corePac 7 */
#else
            CSL_ARM_GIC_GPIO_INT7 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 8 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INT8,
#else
            CSL_ARM_GIC_GPIO_INT8 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 9 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INT9,
#else
            CSL_ARM_GIC_GPIO_INT9 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 10 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INT10,
#else
            CSL_ARM_GIC_GPIO_INT10 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 11 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INT11,
#else
            CSL_ARM_GIC_GPIO_INT11 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 12 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INT12,
#else
            CSL_ARM_GIC_GPIO_INT12 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 13 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INT13,
#else
            CSL_ARM_GIC_GPIO_INT13 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 14 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INT14,
#else
            CSL_ARM_GIC_GPIO_INT14 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 15 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            CSL_C66X_COREPAC_GPIO_INT15,
#else
            CSL_ARM_GIC_GPIO_INT15 + 32,
            0,
#endif
            INVALID_INTC_MUX_NUM,
            0,
            0
        },
        /* GPIO port 0 pin 16 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT16,
            6
#else
            CSL_ARM_GIC_GPIO_INT16 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 17 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT17,
            6
#else
            CSL_ARM_GIC_GPIO_INT17 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 18 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT18,
            6
#else
            CSL_ARM_GIC_GPIO_INT18 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 19 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT19,
            6
#else
            CSL_ARM_GIC_GPIO_INT19 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 20 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT20,
            6
#else
            CSL_ARM_GIC_GPIO_INT20 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 21 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT21,
            6
#else
            CSL_ARM_GIC_GPIO_INT21 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 22 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT22,
            6
#else
            CSL_ARM_GIC_GPIO_INT22 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 23 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT23,
            6
#else
            CSL_ARM_GIC_GPIO_INT23 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 24 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT24,
            6
#else
            CSL_ARM_GIC_GPIO_INT24 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 25 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT25,
            6
#else
            CSL_ARM_GIC_GPIO_INT25 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 26 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT26,
            6
#else
            CSL_ARM_GIC_GPIO_INT26 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 27 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT27,
            6
#else
            CSL_ARM_GIC_GPIO_INT27 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 28 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT28,
            6
#else
            CSL_ARM_GIC_GPIO_INT28 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 29 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT29,
            6
#else
            CSL_ARM_GIC_GPIO_INT29 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 30 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT30,
            6
#else
            CSL_ARM_GIC_GPIO_INT30 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 31 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT31,
            6
#else
            CSL_ARM_GIC_GPIO_INT31 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 32 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT32,
            6
#else
            CSL_ARM_GIC_GPIO_INT32 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 33 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT33,
            6
#else
            CSL_ARM_GIC_GPIO_INT33 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 34 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT34,
            6
#else
            CSL_ARM_GIC_GPIO_INT34 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 35 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT35,
            6
#else
            CSL_ARM_GIC_GPIO_INT35 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 36 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT36,
            6
#else
            CSL_ARM_GIC_GPIO_INT36 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 37 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT37,
            6
#else
            CSL_ARM_GIC_GPIO_INT37 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 38 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT38,
            6
#else
            CSL_ARM_GIC_GPIO_INT38 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 39 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT39,
            6
#else
            CSL_ARM_GIC_GPIO_INT39 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 40 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT40,
            6
#else
            CSL_ARM_GIC_GPIO_INT40 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 41 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT41,
            6
#else
            CSL_ARM_GIC_GPIO_INT41 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 42 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT42,
            6
#else
            CSL_ARM_GIC_GPIO_INT42 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 43 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT43,
            6
#else
            CSL_ARM_GIC_GPIO_INT43 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 44 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT44,
            6
#else
            CSL_ARM_GIC_GPIO_INT44 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 45 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT45,
            6
#else
            CSL_ARM_GIC_GPIO_INT45 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 46 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT46,
            6
#else
            CSL_ARM_GIC_GPIO_INT46 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 47 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT47,
            6
#else
            CSL_ARM_GIC_GPIO_INT47 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 48 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT48,
            6
#else
            CSL_ARM_GIC_GPIO_INT48 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 49 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT49,
            6
#else
            CSL_ARM_GIC_GPIO_INT49 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 50 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT50,
            6
#else
            CSL_ARM_GIC_GPIO_INT50 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 51 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT51,
            6
#else
            CSL_ARM_GIC_GPIO_INT51 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 52 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT52,
            6
#else
            CSL_ARM_GIC_GPIO_INT52 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 53 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT53,
            6
#else
            CSL_ARM_GIC_GPIO_INT53 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 54 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT54,
            6
#else
            CSL_ARM_GIC_GPIO_INT54 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 55 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT55,
            6
#else
            CSL_ARM_GIC_GPIO_INT55 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 56 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT56,
            6
#else
            CSL_ARM_GIC_GPIO_INT56 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 57 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT57,
            6
#else
            CSL_ARM_GIC_GPIO_INT57 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 58 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT58,
            6
#else
            CSL_ARM_GIC_GPIO_INT58 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 59 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT59,
            6
#else
            CSL_ARM_GIC_GPIO_INT59 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 60 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT60,
            6
#else
            CSL_ARM_GIC_GPIO_INT60 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 61 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT61,
            6
#else
            CSL_ARM_GIC_GPIO_INT61 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 62 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT62,
            6
#else
            CSL_ARM_GIC_GPIO_INT62 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        },
        /* GPIO port 0 pin 63 */
        {
#ifdef _TMS320C6X
            OSAL_REGINT_INTVEC_EVENT_COMBINER,
            62,
            0,
            CSL_CIC0_GPIO_INT63,
            6
#else
            CSL_ARM_GIC_GPIO_INT63 + 32,
            0,
            INVALID_INTC_MUX_NUM,
            0,
            0
#endif
        }
    },
    {
        /* "pad to full predefined length of array" */
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},

        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}
    }
};

/* GPIO Driver hardware attributes */
GPIO_v0_hwAttrsList GPIO_v0_hwAttrs =
{
    {
        CSL_GPIO_0_CFG_REGS,
        &GPIO_intCfgs[0][0],
        NULL
    },

    {
        CSL_GPIO_1_CFG_REGS,
        &GPIO_intCfgs[1][0],
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
        &GPIO_FxnTable_v0,
        NULL,
        &GPIO_v0_hwAttrs[1]
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

