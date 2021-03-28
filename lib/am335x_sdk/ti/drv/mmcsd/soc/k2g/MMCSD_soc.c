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
#include <ti/csl/soc.h>
#include <ti/csl/soc/k2g/src/cslr_soc.h>
#include <ti/csl/soc/k2g/src/cslr_interrupt.h>

#include <ti/drv/mmcsd/soc/MMCSD_soc.h>

/* MMCSD configuration structure */
MMCSD_v1_HwAttrs MMCSDInitCfg[MMCSD_CNT] =
{
    {
        1,/* instNum */
#ifdef _TMS320C6X
        CSL_MMCSD_0_S_REGS, /* baseAddr */
        OSAL_REGINT_INTVEC_EVENT_COMBINER,/* intNum - MMC Peripheral interrupt vector */
        CSL_C66X_COREPAC_CIC_0_OUT36,/* Using CIC_0_OUT_36 , as 32-35 is used by EDMA */
#elif defined(__ARM_ARCH_7A__)
        CSL_MMCSD_0_S_REGS, /* baseAddr */
		CSL_ARM_GIC_MMC_SD_0_INT+32,/* intNum - MMC Peripheral interrupt vector */
		0, /*Host event id is set to 0 for ARM */
#endif
        96000000U,/* inputClk */
        400000U,/* outputClk */
        MMCSD_CARD_SD,/* cardType */
        (MMCSD_BUS_WIDTH_1BIT | MMCSD_BUS_WIDTH_4BIT),/* supportedBusWidth */
		MMCSD_BUS_VOLTAGE_3_0V,
        1,/* isHighSpeed */
        0, /* Interrupt enable */
        NULL, /* &MMCSD_iodelayFxn */
        NULL,/* &MMCSD_switchVoltageFxn */
        NULL,/* MMCSD_inputClockCtrl */
        1,  /* Enable DMA by default */
        CSL_EDMACC_1_MMC_SD_0_RX_EVT,/* rxDmaEventNumber */
        CSL_EDMACC_1_MMC_SD_0_TX_EVT,/* txDmaEventNumber */
        0,/* edmaTxTCC */
        0,/* edmaRxTCC */
        0U,/* edmaTxTC */
        0U,/* edmaRxTC */
        0U,/* version */
        NULL,/* edmaHandle */
#ifdef _TMS320C6X
		0, /* CIC Mux 0 */
        CSL_CIC_MMC_SD_0_INT,
		36 /* CIC Mux Out 36 is being used */
#else
		MMCSD_INVALID_MUXNUM, /* No CIC mux for ARM */
        MMCSD_INVALID_MUX_EVENTNUM,/* No CIC mux for ARM */
		MMCSD_INVALID_MUX_EVENTNUM /* No CIC mux for ARM */
#endif
	},
    {
        2, /* instNum */
#ifdef _TMS320C6X
        CSL_MMCSD_1_S_REGS, /* baseAddr */
        OSAL_REGINT_INTVEC_EVENT_COMBINER,/* intNum - MMC Peripheral interrupt vector */
		CSL_C66X_COREPAC_CIC_0_OUT37,
#elif defined(__ARM_ARCH_7A__)
        CSL_MMCSD_1_S_REGS, /* baseAddr */
		CSL_ARM_GIC_MMC_SD_1_INT+32,/* intNum - MMC Peripheral interrupt vector */
		0, /*Host event id is set to 0 for ARM */
#endif
        96000000U,/* inputClk */
        400000U,/* outputClk */
        MMCSD_CARD_EMMC,/* cardType */
        MMCSD_BUS_WIDTH_8BIT,/* supportedBusWidth */
		MMCSD_BUS_VOLTAGE_3_0V,
        1,/* isHighSpeed */
        0,/* enableInterrupt */
        NULL, /* &MMCSD_iodelayFxn */
        NULL,/* &MMCSD_switchVoltageFxn */
        NULL,/* MMCSD_inputClockCtrl */
        1,  /* Enable DMA by default */
        CSL_EDMACC_1_MMC_SD_1_RX_EVT,/* rxDmaEventNumber */
        CSL_EDMACC_1_MMC_SD_1_TX_EVT,/* txDmaEventNumber */
        0,/* edmaTxTCC */
        0,/* edmaRxTCC */
        0U,/* edmaTxTC */
        0U,/* edmaRxTC */
        0U,/* version */
        NULL,/* edmaHandle */
#ifdef _TMS320C6X
		0, /* CIC Mux 0 */
        CSL_CIC_MMC_SD_1_INT,
		37 /* CIC Mux Out 37 is being used */
#else
		MMCSD_INVALID_MUXNUM, /* No CIC mux for ARM */
        MMCSD_INVALID_MUX_EVENTNUM,/* No CIC mux for ARM */
		MMCSD_INVALID_MUX_EVENTNUM /* No CIC mux for ARM */
#endif
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
    {NULL, NULL, NULL},
    {NULL, NULL, NULL},
    {NULL, NULL, NULL}
};
/* This function converts the local L2 address to a global address and
* will be used for DMA transactions which needs a global address.
*/
uint32_t MMCSD_soc_l2_global_addr (uint32_t addr)
{
    if ((addr >= 0x800000) && (addr < 0x1000000))
    {
    #ifdef _TMS320C6X
        uint32_t coreNum;

        /* Get the core number. */
        coreNum = CSL_chipReadReg(CSL_CHIP_DNUM);

    /* Compute the global address. */
        return ((1 << 28) | (coreNum << 24) | (addr & 0x00ffffff));
    #else
        return addr;
    #endif
    }
    else
    {
        /* non-L2 address range */
        return addr;
    }
}
