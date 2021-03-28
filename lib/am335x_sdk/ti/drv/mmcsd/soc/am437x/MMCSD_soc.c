/**
 *  \file   MMCSD_soc.c
 *
 *  \brief  AM572x SoC specific MMCSD hardware attributes.
 *
 *   This file contains the hardware attributes of MMCSD peripheral like
 *   base address, interrupt number etc.
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

#include <stdint.h>
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/starterware/include/hw/am437x.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>

#define CSL_EDMA3_CHA_MMC0_RX    25
#define CSL_EDMA3_CHA_MMC0_TX    24
#define CSL_EDMA3_CHA_MMC1_RX    03
#define CSL_EDMA3_CHA_MMC1_TX    02
#define CSL_EDMA3_CHA_MMC2_RX    64 /* Assigned invalid value. Use xbar config. */
#define CSL_EDMA3_CHA_MMC2_TX    64 /* Assigned invalid value. Use xbar config. */
/* MMCSD configuration structure */
MMCSD_v1_HwAttrs MMCSDInitCfg[MMCSD_CNT] =
{
    {
        0,
        SOC_MMCSD0_REG,
        96,
        82,
        96000000U,
        400000U,
        MMCSD_CARD_SD,
        (MMCSD_BUS_WIDTH_1BIT | MMCSD_BUS_WIDTH_4BIT),
		MMCSD_BUS_VOLTAGE_3_0V,
        1,
        0,
        NULL,
        NULL,
        NULL,
        1,  /* Enable DMA by default */
        CSL_EDMA3_CHA_MMC0_RX,
        CSL_EDMA3_CHA_MMC0_TX,
        0U,
        0U,
        0U,
        0U,
        0U,
        NULL,
	MMCSD_INVALID_MUXNUM, /* Mux not defined for this SOC */
	MMCSD_INVALID_MUX_EVENTNUM, /* Mux not defined for this SOC */
	MMCSD_INVALID_MUX_EVENTNUM, /* Mux not defined for this SOC */
    },
    {
        1,
        SOC_MMCSD1_REG,
        60,
        82,
        96000000U,
        400000U,
        MMCSD_CARD_EMMC,
        MMCSD_BUS_WIDTH_8BIT,
		MMCSD_BUS_VOLTAGE_3_0V,
        1,
        0,
        NULL,
        NULL,
        NULL,
        1,  /* Enable DMA by default */
        CSL_EDMA3_CHA_MMC1_RX,
        CSL_EDMA3_CHA_MMC1_TX,
        0U,
        0U,
        0U,
        0U,
        0U,
        NULL,
	MMCSD_INVALID_MUXNUM, /* Mux not defined for this SOC */
	MMCSD_INVALID_MUX_EVENTNUM, /* Mux not defined for this SOC */
	MMCSD_INVALID_MUX_EVENTNUM, /* Mux not defined for this SOC */
    },
    {
        2,
        SOC_MMCSD2_REG,
        61,
        82,
        96000000U,
        400000U,
        MMCSD_CARD_SD,
        (MMCSD_BUS_WIDTH_1BIT | MMCSD_BUS_WIDTH_4BIT),
		MMCSD_BUS_VOLTAGE_3_0V,
        1,
        0,
        NULL,
        NULL,
        NULL,
        1,  /* Enable DMA by default */
        CSL_EDMA3_CHA_MMC2_RX,
        CSL_EDMA3_CHA_MMC2_TX,
        0U,
        0U,
        0U,
        0U,
        0U,
        NULL,
	MMCSD_INVALID_MUXNUM, /* Mux not defined for this SOC */
	MMCSD_INVALID_MUX_EVENTNUM, /* Mux not defined for this SOC */
	MMCSD_INVALID_MUX_EVENTNUM, /* Mux not defined for this SOC */
    }
};


/* MMCSD objects */
MMCSD_v1_Object MMCSDObjects[MMCSD_CNT];


/* MMC configuration structure */
const MMCSD_Config_list MMCSD_config = {
    {
        &MMCSD_v1_FxnTable,
        &MMCSDObjects[0],
        &MMCSDInitCfg[0]
    },

    {
        &MMCSD_v1_FxnTable,
        &MMCSDObjects[1],
        &MMCSDInitCfg[1]
    },

    {
        &MMCSD_v1_FxnTable,
        &MMCSDObjects[2],
        &MMCSDInitCfg[2]
    },
    /* padding the array to full length*/
    {NULL, NULL, NULL},
    {NULL, NULL, NULL}
};

/*
* This function converts the local L2 address to a global address and
* will be used for DMA transactions which needs a global address.
*/
uint32_t MMCSD_soc_l2_global_addr (uint32_t addr)
{
    return addr;
}
