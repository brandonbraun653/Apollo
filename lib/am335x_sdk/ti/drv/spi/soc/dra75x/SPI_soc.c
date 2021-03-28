/**
 *  \file   SPI_soc.c
 *
 *  \brief  DRA75x device specific hardware attributes.
 *
 */

/*
 * Copyright (C) 2016 - 2019 Texas Instruments Incorporated - http://www.ti.com/
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

#include <ti/csl/soc/dra75x/cslr_soc.h>
#include <ti/drv/spi/MCSPI.h>
#include <ti/drv/spi/soc/SPI_soc.h>

#define CSL_QSPI_PER_CNT    1U

/* NOTE: Interrupt number 25 & 10 Entry not used are used */

/* SPI configuration structure */
SPI_v1_HWAttrs spiInitCfg[CSL_MCSPI_PER_CNT] =
{
    {
        SOC_MCSPI1_BASE,
#if defined (__TI_ARM_V7M4__)
        57,
#elif defined (__ARM_ARCH_7A__)
        97,
#elif defined (_TMS320C6X)
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
#endif
        91,
        SPI_PINMODE_4_PIN,
        MCSPI_CHANNEL_0,
        MCSPI_SINGLE_CH,
        true,
        CSL_MCSPI_0_MODULE_FREQ,
        MCSPI_INITDLY_0,
        MCSPI_RX_TX_FIFO_SIZE,
        MCSPI_RX_TX_FIFO_SIZE,
        {
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_6,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_6,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_6,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_6,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
        },
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        false,
        NULL
    },
    {
        SOC_MCSPI2_BASE,
#if defined (__TI_ARM_V7M4__)
        58,
#elif defined (__ARM_ARCH_7A__)
        98,
#elif defined (_TMS320C6X)
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
#endif
        92,
        SPI_PINMODE_3_PIN,
        MCSPI_CHANNEL_0,
        MCSPI_SINGLE_CH,
        true,
        CSL_MCSPI_1_MODULE_FREQ,
        MCSPI_INITDLY_0,
        MCSPI_RX_TX_FIFO_SIZE,
        MCSPI_RX_TX_FIFO_SIZE,
        {
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_6,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_6,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_6,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_6,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
        },
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        false,
        NULL
    },
    {
        SOC_MCSPI3_BASE,
#if defined (__TI_ARM_V7M4__)
        25,
#elif defined (__ARM_ARCH_7A__)
        123,
#elif defined (_TMS320C6X)
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
#endif
        93,
        SPI_PINMODE_4_PIN,
        MCSPI_CHANNEL_0,
        MCSPI_SINGLE_CH,
        true,
        CSL_MCSPI_2_MODULE_FREQ,
        MCSPI_INITDLY_0,
        MCSPI_RX_TX_FIFO_SIZE,
        MCSPI_RX_TX_FIFO_SIZE,
        {
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_7,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_7,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_7,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_7,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
        },
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        false,
        NULL
    },
    {
        SOC_MCSPI4_BASE,
#if defined (__TI_ARM_V7M4__)
        10,
#elif defined (__ARM_ARCH_7A__)
        80,
#elif defined (_TMS320C6X)
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
#endif
        94,
        SPI_PINMODE_4_PIN,
        MCSPI_CHANNEL_0,
        MCSPI_SINGLE_CH,
        true,
        CSL_MCSPI_3_MODULE_FREQ,
        MCSPI_INITDLY_0,
        MCSPI_RX_TX_FIFO_SIZE,
        MCSPI_RX_TX_FIFO_SIZE,
        {
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_7,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_7,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_7,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_7,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
        },
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        false,
        NULL
     },
};


/* SPI objects */
SPI_v1_Object SpiObjects[CSL_MCSPI_PER_CNT];

/* SPI configuration structure */
QSPI_HwAttrs qspiInitCfg[CSL_QSPI_PER_CNT] =
{
    {
        SOC_QSPI_ADDRSP0_BASE,  /* register baseAddr */
        SOC_QSPI_ADDRSP1_BASE,  /* memMappedBaseAddr */
        64000000,               /* Input frequency */
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
#elif defined(__ARM_ARCH_7A__)
        67U,                    /* 35 + 32 */
#else
        62U,
#endif
#ifdef _TMS320C6X
        38U, /*343U,*/
#elif defined(__ARM_ARCH_7A__)
        35U, /*343U,*/
#else
        0U,  /*343U,*/
#endif
        QSPI_OPER_MODE_MMAP,         /* operMode */
        0U,                          /* chipSelect */
        QSPI_CS_POL_ACTIVE_LOW,      /* csPol */
        QSPI_CLK_MODE_0,             /* frmFmt */
        QSPI_DATA_DELAY_0,           /* dataDelay */
        QSPI_RX_LINES_QUAD,          /* rxLines */
        true,                        /* intrEnable */
        false,                       /* dmaEnable */
        NULL,                        /* edmaHandle */
        0,                           /* edmaTcc */
        0,                           /* edmaChId */
        1U                           /* clkDiv */
    }
};


/* QSPI objects */
QSPI_v1_Object QspiObjects[CSL_QSPI_PER_CNT];


/* SPI configuration structure */
const SPI_config_list SPI_config = {
    {
        &SPI_FxnTable_v1,
        &SpiObjects[0],
        &spiInitCfg[0]
    },
    {
        &SPI_FxnTable_v1,
        &SpiObjects[1],
        &spiInitCfg[1]
    },
    {
        &SPI_FxnTable_v1,
        &SpiObjects[2],
        &spiInitCfg[2]
    },
    {
        &SPI_FxnTable_v1,
        &SpiObjects[3],
        &spiInitCfg[3]
    },
    {
        &QSPI_FxnTable_v1,
        &QspiObjects[0],
        &qspiInitCfg[0]
    },
    /* "pad to full predefined length of array" */
    {NULL, NULL, NULL},
    {NULL, NULL, NULL}
};

/* MCSPI configuration structure */
MCSPI_config_list MCSPI_config = {
    {
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[0])),
            0
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[0])),
            1
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[0])),
            2
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[0])),
            3
        },
    },
    {
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[1])),
            0
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[1])),
            1
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[1])),
            2
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[1])),
            3
        },
    },
    {
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[2])),
            0
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[2])),
            1
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[2])),
            2
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[2])),
            3
        },
    },
    {
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[3])),
            0
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[3])),
            1
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[3])),
            2
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[3])),
            3
        },
    },
    /* "pad to full predefined length of array" */
    {
        {NULL, NULL, 0},
        {NULL, NULL, 0},
        {NULL, NULL, 0},
        {NULL, NULL, 0}
    },
    {
        {NULL, NULL, 0},
        {NULL, NULL, 0},
        {NULL, NULL, 0},
        {NULL, NULL, 0}
    },
    {
        {NULL, NULL, 0},
        {NULL, NULL, 0},
        {NULL, NULL, 0},
        {NULL, NULL, 0}
    }
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
int32_t SPI_socGetInitCfg(uint32_t index, SPI_v1_HWAttrs *cfg)
{
	int32_t ret = 0;

	if (index < CSL_MCSPI_PER_CNT)
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
int32_t SPI_socSetInitCfg(uint32_t index, const SPI_v1_HWAttrs *cfg)
{
	int32_t ret = 0;

	if (index < CSL_MCSPI_PER_CNT)
    {
        spiInitCfg[index] = *cfg;
    }
    else
    {
        ret = -1;
    }
    return ret;
}
