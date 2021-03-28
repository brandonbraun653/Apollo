/**
 *  \file   SPI_soc.c
 *
 *  \brief  OMAPL137 SoC specific SPI hardware attributes.
 *
 *   This file contains the hardware attributes of SPI peripheral like
 *   base address, interrupt number etc.
 */

/*
 * Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/csl/csl_device_interrupt.h>
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/SPI_soc.h>

/* SPI configuration structure */
SPI_v0_HWAttrs spiInitCfg[CSL_SPI_CNT] =
{
    {
        CSL_SPI_0_SLV_REGS, /* SPI base address */
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER,  /* Default event combiner ID */
        37, /* default DSP INTC SPI Event ID, can be set in SPI_socSetInitCfg() API */
        INVALID_INTC_MUX_NUM, /* No INTC Mux */
        0, /* No INTC Mux */
        0,  /* No INTC Mux */
#else
        20, /* SPI int0 number for ARM GIC INTC */
        0, /* Event ID not used for ARM INTC */
        INVALID_INTC_MUX_NUM, /* CIC num not used in ARM GIC */
        0, /* CIC SPI Event ID not used for ARM GIC*/
        0, /* Host interrupt number not used for ARM GIC */
#endif
        SPI_PINMODE_4_PIN,
        SPI_CS(0),
        true,  /* Enable interrupt mode*/
        (300000000U/2U),  /* default spi frequency, system clock/6 */
        SPI_INT_LINE_INT1, /* Set interrupt line to INT1 */
        CSL_EDMA3_CHA_SPI0_RX, /* rxDmaEventNumber */
        CSL_EDMA3_CHA_SPI0_TX, /* txDmaEventNumber */
        0, /* edmaTxTCC */
        0, /* edmaRxTCC */
        0, /* edmaTxTC */
        0, /* edmaRxTC */
        NULL, /* edmaHandle */
        false, /* dmaMode */
        0     /* loopback */
    },
    {
        CSL_SPI_1_SLV_REGS,
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER,  /* Default event combiner ID */
        CSL_INTC_EVENTID_SPIINT1,
        INVALID_INTC_MUX_NUM,
        0,
        0,
#else
        56,
        0,
        INVALID_INTC_MUX_NUM, /* CIC num not used in ARM GIC */
        0,
        0,
#endif
        SPI_PINMODE_4_PIN,
        SPI_CS(0),
        true,  /* Enable interrupt mode*/
        (300000000U/2U),  /* default spi frequency, system clock/6 */
        SPI_INT_LINE_INT1,   /* Set interrupt line to INT1 */
        CSL_EDMA3_CHA_SPI1_RX,
        CSL_EDMA3_CHA_SPI1_TX,
        0,
        0,
        0,
        0,
        NULL,
        false,
        0
    }
};


/* SPI objects */
SPI_v0_Object SpiObjects[CSL_SPI_CNT];


/* SPI configuration structure */
const SPI_config_list SPI_config = {
    {
        &SPI_FxnTable_v0,
        &SpiObjects[0],
        &spiInitCfg[0]
    },
    {
        &SPI_FxnTable_v0,
        &SpiObjects[1],
        &spiInitCfg[1]
    },
    /* "pad to full predefined length of array" */
    {NULL, NULL, NULL},
    {NULL, NULL, NULL}
};

/**
 * \brief  This API gets the SoC level of SPI intial configuration
 *
 * \param  index     SPI instance index.
 * \param  cfg       Pointer to SPI SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t SPI_socGetInitCfg(uint32_t index, SPI_v0_HWAttrs *cfg)
{
	int32_t ret = 0;

    if (index < CSL_SPI_CNT)
    {
        *cfg = spiInitCfg[index];
    }
    else
    {
        ret = -1;
    }

    return ret;
}

/**
 * \brief  This API sets the SoC level of SPI intial configuration
 *
 * \param  index     SPI instance index.
 * \param  cfg       Pointer to SPI SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t SPI_socSetInitCfg(uint32_t index, const SPI_v0_HWAttrs *cfg)
{
	int32_t ret = 0;

    if (index < CSL_SPI_CNT)
    {
        spiInitCfg[index] = *cfg;
    }
    else
    {
        ret = -1;
    }

    return ret;
}

#ifdef SPI_DMA_ENABLE
/**
 * \brief  This API gets the SoC specific EDMA3 info
 *
 * \param  index        SPI instance index.
 * \param  edma3Id      pointer to EDMA3CC #.
 * \param  edma3Event   pointer to EDMA3 event array.
 *
 * \return none
 *
 */
void SPI_getEdmaInfo(uint32_t index, uint32_t *edma3Id, uint32_t *edma3Event)
{
    const uint32_t edma3id[CSL_SPI_CNT] = {0, 0};
    const uint32_t edma3RxEvent[CSL_SPI_CNT] =
    {
        CSL_EDMA3_CHA_SPI0_RX,
        CSL_EDMA3_CHA_SPI1_RX,
    };
    const uint32_t edma3TxEvent[CSL_SPI_CNT] =
    {
        CSL_EDMA3_CHA_SPI0_TX,
        CSL_EDMA3_CHA_SPI1_TX,
    };

    *edma3Id = edma3id[index];
    edma3Event[0] = edma3RxEvent[index];
    edma3Event[1] = edma3TxEvent[index];
}
#endif
