/**
 *  \file   SPI_soc.c
 *
 *  \brief  C6678 SoC specific SPI hardware attributes.
 *
 *   This file contains the hardware attributes of SPI peripheral like
 *   base address, interrupt number etc.
 */

/*
 * Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com/
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
SPI_v0_HWAttrs spiInitCfg[CSL_SPI_PER_CNT + 1U] =
{
    {
        CSL_SPI_REGS, /* SPI base address */
        OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in SPI_socSetInitCfg() API */
        94, /* default DSP INTC SPI Event ID, can be set in SPI_socSetInitCfg() API */
        0, /* CIC number 0 */
        CSL_INTC0_SPIINT0, /* CIC SPI Event ID */
        6,  /* default CIC Host Interrupt, map to INTC0_OUT(6+8*n) event */
        SPI_PINMODE_4_PIN,
        SPI_CS(0),
        true,
        1000000000/6,  /* default SPI frequency, system clock/6 */
        SPI_INT_LINE_INT0, /* Set interrupt line to INT0 */
        CSL_EDMA3CC1_SPIREVT, /* rxDmaEventNumber */
        CSL_EDMA3CC1_SPIXEVT, /* txDmaEventNumber */
        0, /* edmaTxTCC */
        0, /* edmaRxTCC */
        0, /* edmaTxTC */
        0, /* edmaRxTC */
        NULL, /* edmaHandle */
        false, /* dmaMode */
        0     /* loopback */
    },
    {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        false,
        0,
        0,
        0,
        0,
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
SPI_v0_Object SpiObjects[CSL_SPI_PER_CNT + 1U];

/* SPI configuration structure */
CSL_PUBLIC_CONST SPI_Config SPI_config[CSL_SPI_PER_CNT + 1U] = {
    {
        &SPI_FxnTable_v0,
        &SpiObjects[0],
        &spiInitCfg[0]
    },
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

	if (index < CSL_SPI_PER_CNT)
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

	if (index < CSL_SPI_PER_CNT)
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
    const uint32_t edma3id[CSL_SPI_PER_CNT + 1U] = {1, 0};
    const uint32_t edma3RxEvent[CSL_SPI_PER_CNT + 1U] =
    {
        CSL_EDMA3CC1_SPIREVT,
        0,
    };
    const uint32_t edma3TxEvent[CSL_SPI_PER_CNT + 1U] =
    {
        CSL_EDMA3CC1_SPIXEVT,
        0,
    };

    *edma3Id = edma3id[index];
    edma3Event[0] = edma3RxEvent[index];
    edma3Event[1] = edma3TxEvent[index];
}
#endif
