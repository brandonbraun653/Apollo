/**
 *  \file   am437x/I2C_soc.c
 *
 *  \brief  AM437x SoC specific I2C hardware attributes.
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
#include <ti/starterware/include/hw/am437x.h>

/* I2C configuration structure */
I2C_HwAttrs i2cInitCfg[I2C_HWIP_MAX_CNT] =
{
    {
        SOC_I2C0_REG,
        102,
        0,
        48000000U,
        true,
        {
            /* default own slave addresses */
            0x70, 0x0, 0x0, 0x0
        },
    },
    {
        SOC_I2C1_REG,
        103,
        0,
        48000000U,
        true,
        {
            0x71, 0x0, 0x0, 0x0
        },
    },
    {
        SOC_I2C2_REG,
        62,
        0,
        48000000U,
        true,
        {
            0x72, 0x0, 0x0, 0x0
        },
    }
};

#ifdef PRU_ICSS_FW
/* I2C FW Memory Ptr */
const ICSS_Mem_Ptr i2cFwMemPtr = {
    (uint32_t *)&pru_dmem0_rev1_start,
    (uint32_t *)&pru_imem0_rev1_start,
    (uint32_t *)&pru_dmem0_rev1_end,
    (uint32_t *)&pru_imem0_rev1_end,
    (uint32_t *)&pru_dmem1_rev1_start,
    (uint32_t *)&pru_imem1_rev1_start,
    (uint32_t *)&pru_dmem1_rev1_end,
    (uint32_t *)&pru_imem1_rev1_end
};

/* I2C Soft IP configuration structure */
I2C_SwIPAttrs i2cInitCfg2[I2C_SWIP_MAX_CNT] __attribute__ ((section(".shdata"))) =
{
    {
#ifndef AM437X_ICSS0        
        (uint32_t)SOC_PRU_ICSS1_U_DATA_RAM0 + (uint32_t)ICSS_I2C_INSTANCE0_ADDR,
        (uint32_t)SOC_PRU_ICSS1_U_DATA_RAM0 + (uint32_t)ICSS_I2C_CONFIG_MEMORY,
#else   // AM437X_ICSS0
        (uint32_t)SOC_PRU_ICSS0_U_DATA_RAM0 + (uint32_t)ICSS_I2C_INSTANCE0_ADDR,
        (uint32_t)SOC_PRU_ICSS0_U_DATA_RAM0 + (uint32_t)ICSS_I2C_CONFIG_MEMORY,
#endif  // AM437X_ICSS0
#ifndef AM437X_ICSS0        
        52,
#else   // AM437X_ICSS0
        191,
#endif  // AM437X_ICSS0
        0,
#ifndef AM437X_ICSS0        
        I2C_ICSS_INSTANCE2,
#else   // AM437X_ICSS0
        I2C_ICSS_INSTANCE1,
#endif  // AM437X_ICSS0
        PRUICCSS_PRU0,
        &i2cFwMemPtr,
#ifndef AM437X_ICSS0        
        {0x44E10880,  8, 0x6, 0x5},
        {0x44E10958,  0, 0xF, 0x6},
        {0x44E10884,  9, 0x6, 0x5},
#else   // AM437X_ICSS0
        {0x44E108F0,  8, 0x6, 0x5},
        {0x44E10958,  0, 0xF, 0x6},    
        {0x44E108F4,  9, 0x6, 0x5},    
#endif  // AM437X_ICSS0
        I2C_TRIGLVL_256,
        I2C_TRIGLVL_256,
        I2C_INSTANCE_ID0,
        true
    },
    {
#ifndef AM437X_ICSS0        
        (uint32_t)SOC_PRU_ICSS1_U_DATA_RAM0 + (uint32_t)ICSS_I2C_INSTANCE1_ADDR,
        (uint32_t)SOC_PRU_ICSS1_U_DATA_RAM0 + (uint32_t)ICSS_I2C_CONFIG_MEMORY,
#else   // AM437X_ICSS0
        (uint32_t)SOC_PRU_ICSS0_U_DATA_RAM0 + (uint32_t)ICSS_I2C_INSTANCE1_ADDR,
        (uint32_t)SOC_PRU_ICSS0_U_DATA_RAM0 + (uint32_t)ICSS_I2C_CONFIG_MEMORY,
#endif  // AM437X_ICSS0
#ifndef AM437X_ICSS0        
        52,
#else   // AM437X_ICSS0
        191,
#endif  // AM437X_ICSS0
        0,
#ifndef AM437X_ICSS0        
        I2C_ICSS_INSTANCE2,
#else   // AM437X_ICSS0
        I2C_ICSS_INSTANCE1,
#endif  // AM437X_ICSS0
        PRUICCSS_PRU0,
        &i2cFwMemPtr,
#ifndef AM437X_ICSS0        
        {0x44E10830, 10, 0x6, 0x9},
        {0x44E1095C,  1, 0xF, 0x6},
        {0x44E10834, 11, 0x6, 0x9},
#else   // AM437X_ICSS0
        {0x44E108F8, 10, 0x6, 0x5},
        {0x44E1095C,  1, 0xF, 0x6},
        {0x44E108FC, 11, 0x6, 0x5},
#endif  // AM437X_ICSS0
        I2C_TRIGLVL_256,
        I2C_TRIGLVL_256,
        I2C_INSTANCE_ID1,
        true
    }
};

/* I2C objects */
I2C_v2_Object I2cObjects2[I2C_SWIP_MAX_CNT];
#endif

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

    /*pad to full predefined length of array*/
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
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

#ifdef PRU_ICSS_FW
/**
 * \brief  This API gets the I2C FW configuration
 *
 * \param  index     I2C instance index.
 * \param  cfg       Pointer to I2C FW config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t I2C_socGetFwCfg(uint32_t index, I2C_SwIPAttrs *cfg)
{
    int32_t ret = 0;
    
    index = index - I2C_HWIP_MAX_CNT;
    if (index < I2C_SWIP_MAX_CNT)
    {
        *cfg = i2cInitCfg2[index];
    }
    else
    {
        ret = (-((int32_t)1));
    }

    return ret;
}

/**
 * \brief  This API sets the I2C FW configuration
 *
 * \param  index     I2C instance index.
 * \param  cfg       Pointer to I2C FW config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t I2C_socSetFwCfg(uint32_t index, const I2C_SwIPAttrs *cfg)
{
    int32_t ret = 0;

    index = index - I2C_HWIP_MAX_CNT;
    if (index < I2C_SWIP_MAX_CNT)
    {
        i2cInitCfg2[index] = *cfg;
    }
    else
    {
        ret = (-((int32_t)1));
    }

    return ret;
}

/**
 * \brief  This API initialize the I2C FW configuration
 *
 * \param     none
 *
 * \return    none
 *
 */
void I2C_socInitFwCfg(void)
{
    uint32_t i;

    for (i = 0; i < I2C_SWIP_MAX_CNT; i++)
    {
        I2C_config[I2C_HWIP_MAX_CNT + i].fxnTablePtr = &I2C_v2_FxnTable;
        I2C_config[I2C_HWIP_MAX_CNT + i].object      = (void *)(&I2cObjects2[i]);
        I2C_config[I2C_HWIP_MAX_CNT + i].hwAttrs     = &i2cInitCfg2[i];
    }

    return;
}
#endif
