/******************************************************************************
 * FILE PURPOSE:   ICSS_EMAC Peripheral Device Configuration
 ******************************************************************************
 * FILE NAME:   icss_emacSoc.c
 *
 * DESCRIPTION: ICSS_EMAC Peripheral Device Configuration Mapping
 *
 * REVISION HISTORY:
 *
 *  Copyright (c) Texas Instruments Incorporated 2016
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
 */

#include <stdio.h>
#include <stdint.h>
#include <ti/drv/icss_emac/soc/icss_emacSoc.h>
#include <ti/csl/cslr_device.h>

ICSS_EmacBaseAddrCfgParams icss_EmacBaseAddrCfgParams[2] =
{
    {
        CSL_ICSS_0_MII_MDIO_REGS,
        CSL_ICSS_0_DATA_RAM_8KB_0_REGS,
        CSL_ICSS_0_DATA_RAM_8KB_1_REGS,
        CSL_MSMC_SRAM_REGS,
        CSL_ICSS_0_DATA_RAM_64KB_REGS,
        CSL_ICSS_0_INTC_REGS,
        CSL_ICSS_0_PRU_CTRL_0_REGS,
        CSL_ICSS_0_PRU_CTRL_1_REGS,
        CSL_ICSS_0_IEP_REGS,
        CSL_ICSS_0_CFG_REGS,
        CSL_ICSS_0_MII_RT_CFG_REGS,
        CSL_ICSS_0_DATA_RAM_8KB_0_REGS_SIZE,
        CSL_ICSS_0_DATA_RAM_8KB_1_REGS_SIZE,
        CSL_MSMC_SRAM_REGS_SIZE,
        CSL_ICSS_0_DATA_RAM_64KB_REGS_SIZE
    },
    {
        CSL_ICSS_1_MII_MDIO_REGS,
        CSL_ICSS_1_DATA_RAM_8KB_0_REGS,
        CSL_ICSS_1_DATA_RAM_8KB_1_REGS,
        CSL_MSMC_SRAM_REGS,
        CSL_ICSS_1_DATA_RAM_64KB_REGS,
        CSL_ICSS_1_INTC_REGS,
        CSL_ICSS_1_PRU_CTRL_0_REGS,
        CSL_ICSS_1_PRU_CTRL_1_REGS,
        CSL_ICSS_1_IEP_REGS,
        CSL_ICSS_1_CFG_REGS,
        CSL_ICSS_1_MII_RT_CFG_REGS,
        CSL_ICSS_1_DATA_RAM_8KB_0_REGS_SIZE,
        CSL_ICSS_1_DATA_RAM_8KB_1_REGS_SIZE,
        CSL_MSMC_SRAM_REGS_SIZE,
        CSL_ICSS_1_DATA_RAM_64KB_REGS_SIZE
    }
};

/**
 * \brief  This API gets the SoC level of PRU-ICSS  intial configuration
 *
 * \param  index     PRU-ICSS  instance index.
 * \param  cfg       Pointer to PRU-ICSS  SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t ICSS_EmacSocGetInitCfg(uint32_t instance, ICSS_EmacBaseAddrCfgParams *cfg)
{
    int32_t ret = 0;

    if (instance < PRUICCSS_INSTANCE_MAX)
    {
        *cfg = icss_EmacBaseAddrCfgParams[instance];
    }
    else
    {
        ret = -((int32_t)1);
    }

    return ret;
}

/**
 * \brief  This API sets the SoC level of PRU-ICSS intial configuration
 *
 * \param  index     PRU-ICSS instance index.
 * \param  cfg       Pointer to PRU-ICSS SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t ICSS_EmacSocSetInitCfg(uint32_t instance, const ICSS_EmacBaseAddrCfgParams *cfg)
{
    int32_t ret = 0;

    if (instance < PRUICCSS_INSTANCE_MAX)
    {
        icss_EmacBaseAddrCfgParams[instance] = *cfg;
    }
    else
    {
        ret = -((int32_t)1);
    }

    return ret;
}

