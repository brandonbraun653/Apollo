/**
 *  \file   emac_soc.c
 *
 *  \brief  SOC specific EMAC hardware attributes.
 *
 *   This file contains the EMAC hardware attributes like base address and
 *   interrupt ids.
 */

/*
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com/
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


#include <ti/csl/soc.h>
#include <ti/csl/cslr_device.h>

#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/soc/emac_soc_v4.h>

/* EMAC function table pointer */
extern const EMAC_FxnTable EMAC_FxnTable_v4;

/* EMAC configuration structure */
EMAC_HwAttrs_V4 EMACInitCfg[1] =
{
{
    SOC_GMAC_SS_BASE,
    SOC_GMAC_MDIO_BASE,
    SOC_GMAC_WR_BASE,
    SOC_GMAC_ALE_BASE,
    SOC_GMAC_CPDMA_BASE,
    (SOC_GMAC_SS_BASE + 0x2000U),
    SOC_GMAC_PORT_BASE,
    (SOC_GMAC_SS_BASE + 0x900U),
#if defined(__ARM_ARCH_7A__)
    92 + 32, /* corresponds to CSL_XBAR_INST_MPU_IRQ_92 + 32 */
    0,
    93 + 32, /* corresponds to CSL_XBAR_INST_MPU_IRQ_93 + 32 */
    0,
#elif defined(__TI_ARM_V7M4__)
    60,
    0,
    61,
    0,
#endif
    EMAC_CPSW_CONFIG_MODEFLG_GIGABIT | EMAC_CPSW_CONFIG_MODEFLG_FULLDUPLEX,
    2,
    EMAC_RX_ISR_PER_MSEC_DEFAULT,
    {
        {
            SOC_GMAC_PORT_BASE,
            SOC_GMAC_SL1_BASE,
            0U,
        },
        {
            SOC_GMAC_PORT_BASE,
            SOC_GMAC_SL2_BASE,
            1U,
        }
    }
}
};


/* EMAC configuration structure */
CSL_PUBLIC_CONST EMAC_Cfg EMAC_config[EMAC_NUM_MAX_MAC_PORTS] =
{
    {
        &EMAC_FxnTable_v4,
        NULL,
        &EMACInitCfg[0]
    },
    {
        &EMAC_FxnTable_v4,
        NULL,
        &EMACInitCfg[0]
    }
};

/**
 * \brief  This API gets the SoC level of EMAC intial configuration
 *
 * \param  port_num     EMAC port number.
 * \param  cfg       Pointer to EAMC SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t EMAC_socGetInitCfg(uint32_t port_num, EMAC_HwAttrs_V4 *cfg)
{
    int32_t ret = 0;

    if (port_num  < EMAC_NUM_MAX_MAC_PORTS -1U)
    {
        *cfg = EMACInitCfg[port_num];
    }
    else
    {
        ret = -1;
    }

    return ret;
}

/**
 * \brief  This API sets the SoC level of EMAC intial configuration
 *
 * \param  index     EMAC port number.
 * \param  cfg       Pointer to EMAC SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t EMAC_socSetInitCfg(uint32_t port_num, const EMAC_HwAttrs_V4 *cfg)
{
    int32_t ret = 0;
    if (port_num  < EMAC_NUM_MAX_MAC_PORTS -1U)
        EMACInitCfg[port_num] = *cfg;
    else
        ret = -1;

    return ret;
}

