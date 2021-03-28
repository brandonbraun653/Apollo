/**
 *  \file   emac_soc.c
 *
 *  \brief  SOC specific EMAC hardware attributes.
 *
 *   This file contains the EMAC hardware attributes like base address and
 *   interrupt ids.
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
#include <ti/csl/soc.h>
#include <ti/csl/csl_device_interrupt.h>
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/soc/emac_soc_v1.h>
#include <ti/drv/emac/src/v1/emac_v1.h>
#include <ti/drv/qmss/qmss_qm.h>
//#include <ti/drv/emac/nss_if.h>
#include <ti/csl/csl_device_interrupt.h>
#ifdef _TMS320C6X
#include <ti/csl/csl_chipAux.h>
#endif


EMAC_HwAttrs_V1 EMACInitCfg[1] =
{
#ifdef _TMS320C6X
{
        NULL,
        1,
        1,
        Qmss_MemRegion_MEMORY_REGION_NOT_SPECIFIED,
        OSAL_REGINT_INTVEC_EVENT_COMBINER,    /* Interrupt number */
        7,    /* Event id offset */
        1,     /* num emac ports */
        0,     /* phy address */
        EMAC_convert_coreLocal2GlobalAddr     /* function ptr to convert l2 to global address*/
}
#else
{
        NULL,
        1,
        1,
        Qmss_MemRegion_MEMORY_REGION_NOT_SPECIFIED,
        CSL_ARM_GIC_NSS_QPEND0 + 32,    /* Interrupt number */
        0,    /* Event id offset */
        1,     /* num emac ports */
        0,     /* phy address */
        EMAC_convert_coreLocal2GlobalAddr     /* function ptr to convert l2 to global address*/
}
#endif

};

/* EMAC configuration structure */
CSL_PUBLIC_CONST EMAC_Cfg EMAC_config[1 + 1] =
{
    {
        &EMAC_FxnTable_v1,
        NULL,
        &EMACInitCfg[0]
    },
    {
        NULL,
        NULL,
        NULL
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
int32_t EMAC_socGetInitCfg(uint32_t port_num, EMAC_HwAttrs_V1 *cfg)
{
    int32_t ret = 0;

    if (port_num  < EMAC_MAX_NUM_EMAC_PORTS)
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
int32_t EMAC_socSetInitCfg(uint32_t port_num, const EMAC_HwAttrs_V1 *cfg)
{
    int32_t ret = 0;
    if (port_num  < EMAC_MAX_NUM_EMAC_PORTS)
        EMACInitCfg[port_num] = *cfg;
    else
        ret = -1;

    return ret;
}

/**
 * \brief  This API converts the local L2 cache address to global L2 address.
 *
 * \param  index     L2 Cache address.
 *
 * \return           32 bit address
 *
 */
uint32_t EMAC_convert_coreLocal2GlobalAddr (uint32_t  addr)
{
#ifdef _TMS320C6X
    uint32_t coreNum;

    /* Get the core number. */
    coreNum = CSL_chipReadReg(CSL_CHIP_DNUM);

    /* Compute the global address. */
    if ((addr < 0x880000) && (addr >= 0x800000)) {
        return ((1 << 28) | (coreNum << 24) | (addr & 0x00ffffff));
    } else {
        return addr;
    }
#else
    return (addr);
#endif
}
