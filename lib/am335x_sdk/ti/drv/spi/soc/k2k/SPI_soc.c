/**
 *  \file   SPI_soc.c
 *
 *  \brief  K2K SoC specific SPI hardware attributes.
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
SPI_v0_HWAttrs spiInitCfg[CSL_SPI_PER_CNT] =
{
    {
        CSL_SPI_0_SLV_REGS, /* SPI base address */
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in SPI_socSetInitCfg() API */
        30, /* default DSP INTC SPI Event ID, can be set in SPI_socSetInitCfg() API */
        0, /* CIC number 0 */
        CSL_CIC0_SPI_0_INT0, /* CIC SPI Event ID */
        72,  /* default CIC Host Interrupt, map to CIC_OUT72_PLUS_10_MUL_N event */
#else
        CSL_ARM_GIC_SPI_0_INT0 + 32, /* SPI int0 number for ARM GIC INTC */
        0, /* Event ID not used for ARM INTC */
        INVALID_INTC_MUX_NUM, /* CIC num not used in ARM GIC */
        0, /* CIC SPI Event ID not used for ARM GIC*/
        0, /* Host interrupt number not used for ARM GIC */
#endif
        SPI_PINMODE_4_PIN,
        SPI_CS(0),
        true,
        983000000/6,  /* default spi frequency, system clock/6 */
        SPI_INT_LINE_INT0, /* Set interrupt line to INT0 */
        CSL_EDMACC_1_SPI_0_REVT, /* rxDmaEventNumber */
        CSL_EDMACC_1_SPI_0_XEVT, /* txDmaEventNumber */
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
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
        31,
        0,
        CSL_CIC0_SPI_1_INT0,
        73,
#else
        CSL_ARM_GIC_SPI_1_INT0 + 32,
        0,
        INVALID_INTC_MUX_NUM, /* CIC num not used in ARM GIC */
        0,
        0,
#endif
        SPI_PINMODE_4_PIN,
        SPI_CS(0),
        true,
        983000000/6,
        SPI_INT_LINE_INT0,
        CSL_EDMACC_3_SPI_1_REVT,
        CSL_EDMACC_3_SPI_1_XEVT,
        0,
        0,
        0,
        0,
        NULL,
        false,
        0
    },
    {
        CSL_SPI_2_SLV_REGS,
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
        32,
        0,
        CSL_CIC0_SPI_2_INT0,
        74,
#else
        CSL_ARM_GIC_SPI_2_INT0 + 32,
        0,
        INVALID_INTC_MUX_NUM, /* CIC num not used in ARM GIC */
        0,
        0,
#endif
        SPI_PINMODE_4_PIN,
        SPI_CS(0),
        true,
        983000000/6,
        SPI_INT_LINE_INT0,
        CSL_EDMACC_3_SPI_2_REVT,
        CSL_EDMACC_3_SPI_2_XEVT,
        0,
        0,
        0,
        0,
        NULL,
        false,
        0
    },
};


/* SPI objects */
SPI_v0_Object SpiObjects[CSL_SPI_PER_CNT];

/* SPI configuration structure */
CSL_PUBLIC_CONST SPI_Config SPI_config[CSL_SPI_PER_CNT + 1U] = {
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
    {
        &SPI_FxnTable_v0,
        &SpiObjects[2],
        &spiInitCfg[2]
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
    const uint32_t edma3id[CSL_SPI_PER_CNT] = {1, 3, 3};
    const uint32_t edma3RxEvent[CSL_SPI_PER_CNT] =
    {
        CSL_EDMACC_1_SPI_0_REVT,
        CSL_EDMACC_3_SPI_1_REVT,
        CSL_EDMACC_3_SPI_2_REVT,
    };
    const uint32_t edma3TxEvent[CSL_SPI_PER_CNT] =
    {
        CSL_EDMACC_1_SPI_0_XEVT,
        CSL_EDMACC_3_SPI_1_XEVT,
        CSL_EDMACC_3_SPI_2_XEVT,
    };

    *edma3Id = edma3id[index];
    edma3Event[0] = edma3RxEvent[index];
    edma3Event[1] = edma3TxEvent[index];
}
#endif
