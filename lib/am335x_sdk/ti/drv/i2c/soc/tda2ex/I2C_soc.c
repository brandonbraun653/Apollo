/**
 *  \file   tda2ex/I2C_soc.c
 *
 *  \brief  TDA2EX SoC specific I2C hardware attributes.
 *
 *   This file contains the hardware attributes of I2C peripheral like
 *   base address, interrupt number etc.
 */

/*
 * Copyright (C) 2014-2019 Texas Instruments Incorporated - http://www.ti.com/
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

#include <stdint.h>
#include <ti/drv/i2c/I2C.h>
#include <ti/csl/soc.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

/* Number of I2C instances present in the SoC */
#define I2C_HWIP_MAX_CNT    6U

/* Note: Entry not used from metadata sheet: Interrupt number 60 mapped to IRQ instance 55
         and Interrupt number 61 mapped to unknown 402*/

/* I2C configuration structure */
I2C_HwAttrs i2cInitCfg[I2C_HWIP_MAX_CNT] =
{
    {
        SOC_I2C1_BASE,
#if defined __TI_ARM_V7M4__
        41,
#endif
        51,
        CSL_I2C_0_MODULE_FREQ,
        true,
    },
    {
        SOC_I2C2_BASE,
#if defined __TI_ARM_V7M4__
        42,
#endif
        52,
        CSL_I2C_1_MODULE_FREQ,
        false,
    },
    {
        SOC_I2C3_BASE,
#if defined __TI_ARM_V7M4__
        43,
#endif
        56,
        CSL_I2C_2_MODULE_FREQ,
        false,
    },
    {
        SOC_I2C4_BASE,
#if defined __TI_ARM_V7M4__
        44,
#endif
        57,
        CSL_I2C_3_MODULE_FREQ,
        false,
    },
    {
        SOC_I2C5_BASE,
#if defined __TI_ARM_V7M4__
        60,
#endif
        55,
        CSL_I2C_4_MODULE_FREQ,
        false,
    },
    {
        SOC_I2C6_BASE,
#if defined __TI_ARM_V7M4__
        61,
#endif
        402,
        CSL_I2C_5_MODULE_FREQ,
        false,
    }
};


/* I2C objects */
I2C_v1_Object I2cObjects[I2C_HWIP_MAX_CNT];


/* I2C configuration structure */
I2C_config_list I2C_config  = {
    {
        &I2C_v1_FxnTable,
        &I2cObjects[0],
        &i2cInitCfg[0]
    },

    {
         &I2C_v1_FxnTable,
         &I2cObjects[1],
         &i2cInitCfg[1]
    },

    {
         &I2C_v1_FxnTable,
         &I2cObjects[2],
         &i2cInitCfg[2]
    },

    {
         &I2C_v1_FxnTable,
         &I2cObjects[3],
         &i2cInitCfg[3]
    },

    {
         &I2C_v1_FxnTable,
         &I2cObjects[4],
         &i2cInitCfg[4]
    },
    {
         &I2C_v1_FxnTable,
         &I2cObjects[5],
         &i2cInitCfg[5]
    },
    {NULL, NULL, NULL}
};

/**
 * \brief  This API gets the SoC level of I2C intial configuration
 *
 * \param  index     I2C instance index.
 * \param  cfg       Pointer to I2C SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t I2C_socGetInitCfg(uint32_t index, I2C_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (index < I2C_HWIP_MAX_CNT)
    {
        *cfg = i2cInitCfg[index];
    }
    else
    {
        ret = -1;
    }

    return ret;
}

/**
 * \brief  This API sets the SoC level of I2C intial configuration
 *
 * \param  index     I2C instance index.
 * \param  cfg       Pointer to I2C SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t I2C_socSetInitCfg(uint32_t index, const I2C_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (index < I2C_HWIP_MAX_CNT)
    {
        i2cInitCfg[index] = *cfg;
    }
    else
    {
        ret = -1;
    }

    return ret;
}
