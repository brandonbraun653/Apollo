/**
 *  \file   am571x/I2C_soc.c
 *
 *  \brief  AM571x SoC specific I2C hardware attributes.
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

#include <ti/csl/soc/am571x/src/cslr_soc.h>
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

/* I2C configuration structure */
I2C_HwAttrs i2cInitCfg[I2C_HWIP_MAX_CNT] =
{
    {
#ifdef _TMS320C6X
        CSL_DSP_I2C1_REGS,
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
#elif defined(__ARM_ARCH_7A__)
        CSL_MPU_I2C1_REGS,
        88,
#else
        CSL_IPU_I2C1_REGS,
        41,
#endif
        82,
        CSL_I2C_0_MODULE_FREQ,
        true,
        {
            /* default own slave addresses */
            0x70, 0x0, 0x0, 0x0
        },
    },
    {
#ifdef _TMS320C6X
        CSL_DSP_I2C2_REGS,
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
#elif defined(__ARM_ARCH_7A__)
        CSL_MPU_I2C2_REGS,
        89,
#else
        CSL_IPU_I2C2_REGS,
        42,
#endif
        83,
        CSL_I2C_1_MODULE_FREQ,
        true,
        {
            0x71, 0x0, 0x0, 0x0
        },
    },
    {
#ifdef _TMS320C6X
        CSL_DSP_I2C3_REGS,
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
#elif defined(__ARM_ARCH_7A__)
        CSL_MPU_I2C3_REGS,
        93,
#else
        CSL_IPU_I2C3_REGS,
        43,
#endif
        87,
        CSL_I2C_2_MODULE_FREQ,
        true,
        {
            0x72, 0x0, 0x0, 0x0
        },
    },
    {
#ifdef _TMS320C6X
        CSL_DSP_I2C4_REGS,
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
#elif defined(__ARM_ARCH_7A__)
        CSL_MPU_I2C4_REGS,
        94,
#else
        CSL_IPU_I2C4_REGS,
        44,
#endif
        88,
        CSL_I2C_3_MODULE_FREQ,
        true,
        {
            0x73, 0x0, 0x0, 0x0
        },
    },
    {
#ifdef _TMS320C6X
        CSL_DSP_I2C5_REGS,
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
#elif defined(__ARM_ARCH_7A__)
        CSL_MPU_I2C5_REGS,
        92,
#else
        CSL_IPU_I2C5_REGS,
        24,
#endif
        86,
        CSL_I2C_4_MODULE_FREQ,
        true,
        {
            0x74, 0x0, 0x0, 0x0
        },
    }
};


/* I2C objects */
I2C_v1_Object I2cObjects[I2C_HWIP_MAX_CNT];


/* I2C configuration structure */
I2C_config_list I2C_config = {
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
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
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
        ret = (-((int32_t)1));
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
        ret = (-((int32_t)1));
    }

    return ret;
}
