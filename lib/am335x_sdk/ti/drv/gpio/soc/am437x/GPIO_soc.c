/**
 *  \file   am437x/GPIO_soc.c
 *
 *  \brief  AM437x SOC specific GPIO hardware attributes.
 *
 *   This file contains the GPIO hardware attributes like base address and
 *   interrupt ids.
 */

/*
 * Copyright (C) 2014-2015 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/drv/gpio/GPIO.h>
#include <ti/starterware/include/hw/am437x.h>
#include <ti/csl/csl_types.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

/* Number of GPIO ports */
#define CSL_GPIO_PER_CNT    6U

/* GPIO Driver hardware attributes */
GPIO_v1_hwAttrs_list GPIO_v1_hwAttrs = {
    {
	   SOC_GPIO0_REG,
       128,
       129,
       0,
       0
    },
    {
	/* GPIO 1*/
       SOC_GPIO1_REG,
       130,
       131,
       0,
       0
    },
    {
	/* GPIO 2*/
       SOC_GPIO2_REG,
       64,
       65,
       0,
       0
    },
    {
	/* GPIO 3*/
       SOC_GPIO3_REG,
       94,
       95,
       0,
       0
    },
    {
	/* GPIO 4*/
       SOC_GPIO4_REG,
       138,
       139,
       0,
       0
    },
	    {
	/* GPIO 5*/
       SOC_GPIO5_REG,
       180,
       181,
       0,
       0
    },
    /* "pad to full predefined length of array" */
    {   0,0,0,0,0   }, 
    {   0,0,0,0,0   },
};

/* GPIO configuration structure */
CSL_PUBLIC_CONST GPIOConfigList GPIO_config =
{
    {
        &GPIO_FxnTable_v1,
        NULL,
        NULL
    },
    /* "pad to full predefined length of array" */
    {
        NULL,
        NULL,
        NULL
    },
    {
        NULL,
        NULL,
        NULL
    }
};

