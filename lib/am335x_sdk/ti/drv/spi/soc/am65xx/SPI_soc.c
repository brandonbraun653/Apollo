/**
 *  \file   SPI_soc.c
 *
 *  \brief  AM65XX device specific hardware attributes.
 *
 */

/*
 * Copyright (C) 2017 - 2018 Texas Instruments Incorporated - http://www.ti.com/
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

#include <ti/csl/soc/am65xx/src/cslr_soc.h>
#include <ti/csl/soc/am65xx/src/csl_psilcfg_thread_map.h>
#include <ti/drv/spi/soc/SPI_soc.h>

#if defined (__aarch64__)
#define SPI_PDMA_TX_THREAD_BASE        (CSL_PSILCFG_NAVSS_MAIN_PDMA_MAIN1_PSILD_THREAD_OFFSET + 0U)
#define SPI_PDMA_RX_THREAD_BASE        (CSL_PSILCFG_NAVSS_MAIN_PDMA_MAIN1_PSILS_THREAD_OFFSET + 0U)
#else
#define SPI_PDMA_TX_THREAD_BASE        (CSL_PSILCFG_NAVSS_MCU_PDMA_MCU1_PSILD_THREAD_OFFSET + 0U)
#define SPI_PDMA_RX_THREAD_BASE        (CSL_PSILCFG_NAVSS_MCU_PDMA_MCU1_PSILS_THREAD_OFFSET + 0U)
#endif

/* SPI configuration structure */
SPI_v1_HWAttrs spiInitCfg[CSL_MCSPI_PER_CNT] =
{
    {
#if defined (__aarch64__)
        /* main domain */
        CSL_MCSPI0_CFG_BASE,                /* baseAddr */
        CSL_GIC0_INTR_MCSPI0_BUS_INTR_SPI,  /* intNum */
#else
        /* mcu domain */
        CSL_MCU_MCSPI0_CFG_BASE,
        CSL_MCU0_INTR_MCSPI0_INTR_SPI,
#endif
        0,                                  /* eventId */
        SPI_PINMODE_4_PIN,                  /* pinMode */
        MCSPI_CHANNEL_0,                    /* chNum */
        MCSPI_SINGLE_CH,                    /* chMode */
        true,                               /* enableIntr */
        48000000,                           /* inputClkFreq */
        MCSPI_INITDLY_0,                    /* initDelay */
        MCSPI_RX_TX_FIFO_SIZE,              /* rxTrigLvl */
        MCSPI_RX_TX_FIFO_SIZE,              /* txTrigLvl */
        {
            {
                MCSPI_CS_POL_LOW,                  /* csPolarity */
                MCSPI_DATA_LINE_COMM_MODE_7,       /* dataLineCommMode */
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,   /* tcs */
                MCSPI_TX_RX_MODE,                  /* trMode */
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
        SPI_PDMA_RX_THREAD_BASE,            /* rxDmaEventNumber */
        SPI_PDMA_TX_THREAD_BASE,            /* txDmaEventNumber */
        0,                                  /* edmaTxTCC */
        0,                                  /* edmaRxTCC */
        0,                                  /* edmaTxTC */
        0,                                  /* edmaRxTC */
        NULL,                               /* edmaHandle */
        false,                              /* dmaMode */
        NULL                                /* dmaInfo */
    },
    {
#if defined (__aarch64__)
        /* main domain */
        CSL_MCSPI1_CFG_BASE,
        CSL_GIC0_INTR_MCSPI1_BUS_INTR_SPI,
#else
        /* mcu domain */
        CSL_MCU_MCSPI1_CFG_BASE,
        CSL_MCU0_INTR_MCSPI1_INTR_SPI,
#endif
        0,
        SPI_PINMODE_4_PIN,
        MCSPI_CHANNEL_0,
        MCSPI_SINGLE_CH,
        true,
        48000000,
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
        SPI_PDMA_RX_THREAD_BASE + 4,
        SPI_PDMA_TX_THREAD_BASE + 4,
        0,
        0,
        0,
        0,
        NULL,
        false,
        NULL
    },
    {
#if defined (__aarch64__)
        /* main domain */
        CSL_MCSPI2_CFG_BASE,
        CSL_GIC0_INTR_MCSPI2_BUS_INTR_SPI,
#else
        /* mcu domain */
        CSL_MCU_MCSPI2_CFG_BASE,
        CSL_MCU0_INTR_MCSPI2_INTR_SPI,
#endif
        0,
        SPI_PINMODE_4_PIN,
        MCSPI_CHANNEL_0,
        MCSPI_SINGLE_CH,
        true,
        48000000,
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
        SPI_PDMA_RX_THREAD_BASE + 8,
        SPI_PDMA_TX_THREAD_BASE + 8,
        0,
        0,
        0,
        0,
        NULL,
        false,
        NULL
    },
    {
#if defined (__aarch64__)
        /* main domain */
        CSL_MCSPI3_CFG_BASE,
        CSL_GIC0_INTR_MCSPI3_BUS_INTR_SPI,
#else
        /* mcu domain */
        0,
        0,
#endif
        0,
        SPI_PINMODE_4_PIN,
        MCSPI_CHANNEL_0,
        MCSPI_SINGLE_CH,
        true,
        48000000,
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
        SPI_PDMA_RX_THREAD_BASE + 12,
        SPI_PDMA_TX_THREAD_BASE + 12,
        0,
        0,
        0,
        0,
        NULL,
        false,
        NULL
    },
    {
#if defined (__aarch64__)
        /* main domain */
        CSL_MCSPI4_CFG_BASE,
        CSL_GIC0_INTR_MCSPI4_BUS_INTR_SPI,
#else
        /* mcu domain */
        0,
        0,
#endif
        0,
        SPI_PINMODE_4_PIN,
        MCSPI_CHANNEL_0,
        MCSPI_SINGLE_CH,
        true,
        48000000,
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
        SPI_PDMA_RX_THREAD_BASE + 16,
        SPI_PDMA_TX_THREAD_BASE + 16,
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

/* OSPI configuration structure */
OSPI_v0_HwAttrs ospiInitCfg[CSL_OSPI_PER_CNT + 1U] =
{
    {
        CSL_MCU_FSS0_OSPI0_CTRL_BASE,      /* flash config register baseAddr */
#if defined (__aarch64__)
        CSL_MCU_FSS0_DAT_REG0_BASE,        /* OSPI data base address */
#else
        CSL_MCU_FSS0_DAT_REG1_BASE,
#endif
        OSPI_MODULE_CLOCK,                 /* Input frequency */
#if defined (__aarch64__)
        CSL_GIC0_INTR_MCU_FSS0_BUS_OSPI0_LVL_INTR,
#else
        CSL_MCU0_INTR_FSS0_OSPI0_LVL_INTR, /* OSPI int number for ARM GIC INTC */
#endif
        0,                                 /* Event ID not used for ARM INTC */
        OSPI_OPER_MODE_CFG,                /* operMode */
        CSL_OSPI_CS0,                      /* chipSelect */
        CSL_OSPI_CLK_MODE_0,               /* frmFmt */
        {
            0,                             /* default Chip Select Start of Transfer Delay */
            0,                             /* default Chip Select End of Transfer Delay */
            0,                             /* default Chip Select De-Assert Different Slaves Delay */
            0                              /* default Chip Select De-Assert Delay */
        },
        256,                               /* device page size is 256 bytes  */
        17,                                /* device block size is 2 ^ 17 = 128K bytes */
        OSPI_XFER_LINES_OCTAL,             /* xferLines */
        (bool)false,                       /* Interrupt mode */
        (bool)true,                        /* Direct Access Controller mode */
        (bool)false,                       /* DMA mode */
        NULL,                              /* dmaInfo */
        (bool)true,                        /* enable PHY */
        0,                                 /* rdDataCapDelay */
        (bool)true,                        /* enable DDR */
        (bool)false,                       /* enable XIP */
        10U                                /* Chip Select Start Of Transfer delay */
    },
    {
        CSL_MCU_FSS0_OSPI1_CTRL_BASE,
#if defined (__aarch64__)
        CSL_MCU_FSS0_OSPI1_R0_BASE,
#else
        CSL_MCU_FSS0_DAT_REG1_BASE + 0x08000000,
#endif
        OSPI_MODULE_CLOCK,
#if defined (__aarch64__)
        CSL_GIC0_INTR_MCU_FSS0_BUS_OSPI1_LVL_INTR,
#else
        CSL_MCU0_INTR_FSS0_OSPI1_LVL_INTR,
#endif
        0,
        OSPI_OPER_MODE_CFG,
        CSL_OSPI_CS0,
        CSL_OSPI_CLK_MODE_0,
        {
            0,
            0,
            0,
            0
        },
        256,
        17,
        OSPI_XFER_LINES_OCTAL,
        (bool)false,
        (bool)true,
        (bool)false,
        NULL,
        (bool)true,
        0,
        (bool)true,
        (bool)false,
        10U
    }
};

/* OSPI objects */
OSPI_v0_Object OspiObjects[CSL_OSPI_PER_CNT + 1U];

/* SPI configuration structure */
CSL_PUBLIC_CONST SPI_config_list SPI_config = {
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
        &SPI_FxnTable_v1,
        &SpiObjects[4],
        &spiInitCfg[4]
    },
    {
        &OSPI_FxnTable_v0,
        &OspiObjects[0],
        &ospiInitCfg[0]
    },
    {
        &OSPI_FxnTable_v0,
        &OspiObjects[1],
        &ospiInitCfg[1]
    },
    {
        NULL,
        NULL,
        NULL
    },
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
    {
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[4])),
            0
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[4])),
            1
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[4])),
            2
        },
        {
            &MCSPI_FxnTable_v1,
            (SPI_Handle)(&(SPI_config[4])),
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
    }
};

/**
 * \brief  This API gets the SoC level of SPI intial configuration
 *
 * \param  idx       SPI instance index.
 * \param  cfg       Pointer to SPI SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t SPI_socGetInitCfg(uint32_t idx, SPI_v1_HWAttrs *cfg)
{
    int32_t ret = 0;

    if (idx < CSL_MCSPI_PER_CNT)
    {
        *cfg = spiInitCfg[idx];
    }
    else
    {
        ret = (int32_t)(-1);
    }
    return ret;
}

/**
 * \brief  This API sets the SoC level of SPI intial configuration
 *
 * \param  idx       SPI instance index.
 * \param  cfg       Pointer to SPI SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t SPI_socSetInitCfg(uint32_t idx, const SPI_v1_HWAttrs *cfg)
{
    int32_t ret = 0;

    if (idx < CSL_MCSPI_PER_CNT)
    {
        spiInitCfg[idx] = *cfg;
    }
    else
    {
        ret = (int32_t)(-1);
    }
    return ret;
}

/**
 * \brief  This API gets the SoC level of OSPI intial configuration
 *
 * \param  idx       OSPI instance index.
 * \param  cfg       Pointer to OSPI SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t OSPI_socGetInitCfg(uint32_t idx, OSPI_v0_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (idx < CSL_OSPI_PER_CNT)
    {
        *cfg = ospiInitCfg[idx];
    }
    else
    {
        ret = -1;
    }

    return ret;
}

/**
 * \brief  This API sets the SoC level of OSPI intial configuration
 *
 * \param  idx       OSPI instance index.
 * \param  cfg       Pointer to OSPI SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t OSPI_socSetInitCfg(uint32_t idx, const OSPI_v0_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (idx < CSL_OSPI_PER_CNT)
    {
        ospiInitCfg[idx] = *cfg;
    }
    else
    {
        ret = -1;
    }

    return ret;
}

