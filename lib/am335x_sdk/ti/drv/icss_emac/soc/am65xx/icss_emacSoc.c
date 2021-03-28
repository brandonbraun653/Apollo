/******************************************************************************
 * FILE PURPOSE:   ICSS_EMAC Peripheral Device Configuration
 ******************************************************************************
 * FILE NAME:   icss_emacSoc.c
 *
 * DESCRIPTION: ICSS_EMAC Peripheral Device Configuration Mapping
 *
 * REVISION HISTORY:
 *
 */

/* Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
*
*   Redistribution and use in source and binary forms, with or without
*   modification, are permitted provided that the following conditions
*   are met:
*
*     Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*
*     Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the
*     documentation and/or other materials provided with the
*     distribution.
*
*     Neither the name of Texas Instruments Incorporated nor the names of
*     its contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/



#include <stdint.h>
#include <ti/csl/cslr_device.h>
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/icss_emac/soc/icss_emacSoc.h>


ICSS_EmacBaseAddrCfgParams icss_EmacBaseAddrCfgParams[3] =
{
    {

        CSL_PRU_ICSSG0_PR1_MDIO_V1P7_MDIO_BASE,
        CSL_PRU_ICSSG0_DRAM0_SLV_RAM_BASE,
        CSL_PRU_ICSSG0_DRAM1_SLV_RAM_BASE,
        CSL_COMPUTE_CLUSTER0_MSMC_SRAM_BASE + + 0x40000U,
        CSL_PRU_ICSSG0_RAM_SLV_RAM_BASE,
        CSL_PRU_ICSSG0_PR1_ICSS_INTC_INTC_SLV_BASE,
        CSL_PRU_ICSSG0_PR1_PDSP0_IRAM_BASE,
        CSL_PRU_ICSSG0_PR1_PDSP1_IRAM_BASE,
        CSL_PRU_ICSSG0_IEP0_BASE,
        CSL_PRU_ICSSG0_PR1_CFG_SLV_BASE,
        CSL_PRU_ICSSG0_PR1_MII_RT_PR1_MII_RT_CFG_BASE,
        CSL_PRU_ICSSG0_DRAM0_SLV_RAM_SIZE,
        CSL_PRU_ICSSG0_DRAM1_SLV_RAM_SIZE,
        0x40000U,
        CSL_PRU_ICSSG0_RAM_SLV_RAM_SIZE
    },
    {
        CSL_PRU_ICSSG1_PR1_MDIO_V1P7_MDIO_BASE,
        CSL_PRU_ICSSG1_DRAM0_SLV_RAM_BASE,
        CSL_PRU_ICSSG1_DRAM1_SLV_RAM_BASE,
        CSL_COMPUTE_CLUSTER0_MSMC_SRAM_BASE + 0x80000U,
        CSL_PRU_ICSSG1_RAM_SLV_RAM_BASE,
        CSL_PRU_ICSSG1_PR1_ICSS_INTC_INTC_SLV_BASE,
        CSL_PRU_ICSSG1_PR1_PDSP0_IRAM_BASE,
        CSL_PRU_ICSSG1_PR1_PDSP1_IRAM_BASE,
        CSL_PRU_ICSSG1_IEP0_BASE,
        CSL_PRU_ICSSG1_PR1_CFG_SLV_BASE,
        CSL_PRU_ICSSG1_PR1_MII_RT_PR1_MII_RT_CFG_BASE,
        CSL_PRU_ICSSG1_DRAM0_SLV_RAM_SIZE,
        CSL_PRU_ICSSG1_DRAM1_SLV_RAM_SIZE,
        0x40000U,
        CSL_PRU_ICSSG1_RAM_SLV_RAM_SIZE
    },
    {
        CSL_PRU_ICSSG2_PR1_MDIO_V1P7_MDIO_BASE,
        CSL_PRU_ICSSG2_DRAM0_SLV_RAM_BASE,
        CSL_PRU_ICSSG2_DRAM1_SLV_RAM_BASE,
        CSL_COMPUTE_CLUSTER0_MSMC_SRAM_BASE + 0xC0000U,
        CSL_PRU_ICSSG2_RAM_SLV_RAM_BASE,
        CSL_PRU_ICSSG2_PR1_ICSS_INTC_INTC_SLV_BASE,
        CSL_PRU_ICSSG2_PR1_PDSP0_IRAM_BASE,
        CSL_PRU_ICSSG2_PR1_PDSP1_IRAM_BASE,
        CSL_PRU_ICSSG2_IEP0_BASE,
        CSL_PRU_ICSSG2_PR1_CFG_SLV_BASE,
        CSL_PRU_ICSSG2_PR1_MII_RT_PR1_MII_RT_CFG_BASE,
        CSL_PRU_ICSSG2_DRAM0_SLV_RAM_SIZE,
        CSL_PRU_ICSSG2_DRAM1_SLV_RAM_SIZE,
        0x40000U,
        CSL_PRU_ICSSG2_RAM_SLV_RAM_SIZE
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
