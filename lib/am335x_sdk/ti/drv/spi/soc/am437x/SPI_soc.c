/**
 *  \file   SPI_soc.c
 *
 *  \brief  AM437x device specific hardware attributes.
 *
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

#include <ti/drv/spi/MCSPI.h>
#include <ti/starterware/include/hw/am437x.h>
#include <ti/drv/spi/soc/SPI_soc.h>

#ifdef PRU_ICSS_FW
#include <ti/drv/spi/soc/ESPI_v2.h>
#include <ti/drv/spi/soc/am437x/SPI_icss_hw.h>
#define CSL_ESPI_PER_CNT    (1U)
#endif

#define CSL_MCSPI_PER_CNT   (5U)
#define CSL_QSPI_PER_CNT    (1U)
#define CSL_SPI_HW_CNT	    (CSL_MCSPI_PER_CNT + CSL_QSPI_PER_CNT)

#ifdef PRU_ICSS_FW
#define CSL_SPI_PER_CNT     (CSL_MCSPI_PER_CNT + CSL_QSPI_PER_CNT + CSL_ESPI_PER_CNT)
#else
#define CSL_SPI_PER_CNT     (CSL_MCSPI_PER_CNT + CSL_QSPI_PER_CNT)
#endif

#define CSL_EDMA3_CHA0_MCSPI0_RX  (17)
#define CSL_EDMA3_CHA0_MCSPI0_TX  (16)
#define CSL_EDMA3_CHA0_MCSPI1_RX  (43)
#define CSL_EDMA3_CHA0_MCSPI1_TX  (42)
#define CSL_EDMA3_CHA0_MCSPI2_RX  (17)
#define CSL_EDMA3_CHA0_MCSPI2_TX  (16)
#define CSL_EDMA3_CHA0_MCSPI3_RX  (55)
#define CSL_EDMA3_CHA0_MCSPI3_TX  (54)
#define CSL_EDMA3_CHA0_MCSPI4_RX  (56)
#define CSL_EDMA3_CHA0_MCSPI4_TX  (55)

/* SPI configuration structure */
SPI_v1_HWAttrs spiInitCfg[CSL_MCSPI_PER_CNT] =
{
    {
        SOC_MCSPI0_REG,
        97,
        91,
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
                MCSPI_DATA_LINE_COMM_MODE_1,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_1,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_1,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
            {
                MCSPI_CS_POL_LOW,
                MCSPI_DATA_LINE_COMM_MODE_1,
                MCSPI_CH0CONF_TCS0_ZEROCYCLEDLY,
                MCSPI_TX_RX_MODE,
            },
        },
        CSL_EDMA3_CHA0_MCSPI0_RX,
        CSL_EDMA3_CHA0_MCSPI0_TX,
        0,
        0,
        0,
        0,
        NULL,
        true,
        NULL
    },
    {
        SOC_MCSPI1_REG,
        157,
        92,
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
        CSL_EDMA3_CHA0_MCSPI1_RX,
        CSL_EDMA3_CHA0_MCSPI1_TX,
        0,
        0,
        0,
        0,
        NULL,
        true,
        NULL
    },
    {
        SOC_MCSPI2_REG,
        158,
        38,
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
                MCSPI_DATA_LINE_COMM_MODE_7,  /* SPI_D1: RX */
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
        CSL_EDMA3_CHA0_MCSPI2_RX,
        CSL_EDMA3_CHA0_MCSPI2_TX,
        0,
        0,
        0,
        0,
        NULL,
        true,
        NULL
    },
    {
        SOC_MCSPI3_REG,
        168,
        74,
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
        CSL_EDMA3_CHA0_MCSPI3_RX,
        CSL_EDMA3_CHA0_MCSPI3_TX,
        0,
        0,
        0,
        0,
        NULL,
        true,
        NULL
    },
    {
        SOC_MCSPI4_REG,
        169,
        74,
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
        CSL_EDMA3_CHA0_MCSPI4_RX,
        CSL_EDMA3_CHA0_MCSPI4_TX,
        0,
        0,
        0,
        0,
        NULL,
        true,
        NULL
    },
};


/* SPI objects */
SPI_v1_Object SpiObjects[CSL_MCSPI_PER_CNT];

/* SPI configuration structure */
QSPI_HwAttrs qspiInitCfg[CSL_QSPI_PER_CNT] =
{
    {
        SOC_QSPI_ADDRSP0_REG,  /* register baseAddr */
        SOC_QSPI_REG,          /* memMappedBaseAddr */
        48000000,              /*Input frequency */
        170,
        0,
        QSPI_OPER_MODE_MMAP,         /* operMode */
        0U,                          /* chipSelect */
        QSPI_CS_POL_ACTIVE_LOW,      /* csPol */
        QSPI_CLK_MODE_3,             /* frmFmt */
        QSPI_DATA_DELAY_0,           /* dataDelay */
        QSPI_RX_LINES_QUAD,          /* rxLines */
        false,                       /* intrEnable */
        false,                       /* dmaEnable */
        NULL,                        /* edmaHandle */
        0,                           /* edmaTcc */
        0,                           /* edmaChId */
        1U                           /* clkDiv */
    }
};

#ifdef PRU_ICSS_FW
/* ESPI objects */
ESPI_v2_Object EspiObjects[CSL_ESPI_PER_CNT];

/* ESPI FW Memory Ptr */
const ICSS_Mem_Ptr espiFwMemPtr = {
  (uint32_t *)&pru_dmem0_rev1_start,
  (uint32_t *)&pru_imem0_rev1_start,
  (uint32_t *)&pru_dmem0_rev1_end,
  (uint32_t *)&pru_imem0_rev1_end,
  (uint32_t *)&pru_dmem1_rev1_start,
  (uint32_t *)&pru_imem1_rev1_start,
  (uint32_t *)&pru_dmem1_rev1_end,
  (uint32_t *)&pru_imem1_rev1_end
};

/* ESPI configuration structure */
ESPI_SwIPAttrs espiInitCfg[CSL_ESPI_PER_CNT] __attribute__ ((section(".shdata"))) =
  {
    {
      (uint32_t)SOC_PRU_ICSS1_U_SHARED_RAM,         /* baseAddr */
      (uint32_t)SOC_PRU_ICSS1_U_SHARED_RAM,         /* configAddr */

      20,	/* intNum */
      0,	/* eventId */
      
      ESPI_ICSS_INSTANCE2, /*icssInstance*/
      PRUICCSS_PRU0, /* bitbangPru */
      PRUICCSS_PRU1, /* controlPru */
      &espiFwMemPtr, /* icssMemBuffer */

      /* GPO Pins */
      {0, 0, 0x6, 0x5}, /* d0OutputPin */
      {SOC_CONTROL_MODULE_REG + ESPI_D1_OUT_PIN, ESPI_D1_OUT_PIN_NUM, 0x6, 0x5}, /* d1OutputPin */
      {0, 0, 0x6, 0x5}, /* d2OutputPin */
      {0, 0, 0x6, 0x5}, /* d3OutputPin */
      {SOC_CONTROL_MODULE_REG + ESPI_ALERT_PIN, ESPI_ALERT_PIN_NUM, 0x6, 0x9}, /* alertOutputPin */
      {SOC_CONTROL_MODULE_REG + ESPI_EN_PIN, ESPI_EN_PIN_NUM, 0x6, 0x5}, /* enOutputPin */

      /* GPI Pins */
      {SOC_CONTROL_MODULE_REG + ESPI_D0_IN_PIN, ESPI_D0_IN_PIN_NUM, 0x6, 0x5}, /* d0Input Pin */
      {0, 0, 0x6, 0x5}, /* d1Input Pin */
      {0, 0, 0x6, 0x5}, /* d2Input Pin */
      {0, 0, 0x6, 0x5}, /* d3Input Pin */
      {SOC_CONTROL_MODULE_REG + ESPI_SCL_PIN, ESPI_SCL_PIN_NUM, 0x6, 0x5}, /* sclInputPin  */
      {SOC_CONTROL_MODULE_REG + ESPI_CS_PIN, ESPI_CS_PIN_NUM, 0x6, 0x5}, /* csInputPin  */

      /* GPIO Pins */
      {ESPI_RESET_GPIO_PORT, ESPI_RESET_GPIO_PIN}, /* resetPin  */

      0 /* chNum */	
    }
  };
#endif

/* QSPI objects */
QSPI_v1_Object QspiObjects[CSL_QSPI_PER_CNT];


/* SPI configuration structure */
SPI_config_list SPI_config = {
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
        &QSPI_FxnTable_v1,
        &QspiObjects[0],
        &qspiInitCfg[0]
    },
    
    /* "pad to full predefined length of array" */
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

#ifdef PRU_ICSS_FW
/**
 * \brief  This API gets the ESPI FW configuration
 *
 * \param  index     ESPI instance index.
 * \param  cfg       Pointer to ESPI FW config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t ESPI_socGetFwCfg(uint32_t index, ESPI_SwIPAttrs *cfg)
{
  int32_t ret = 0;
    
  index = index - CSL_MCSPI_PER_CNT ;
  if (index < CSL_ESPI_PER_CNT)
    {
      *cfg = espiInitCfg[index];
    }
  else
    {
      ret = (-((int32_t)1));
    }

  return ret;
}

/**
 * \brief  This API sets the ESPI FW configuration
 *
 * \param  index     ESPI instance index.
 * \param  cfg       Pointer to ESPI FW config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t ESPI_socSetFwCfg(uint32_t index, const ESPI_SwIPAttrs *cfg)
{
  int32_t ret = 0;

  index = index - CSL_MCSPI_PER_CNT ;
  if (index < CSL_ESPI_PER_CNT)
    {
      espiInitCfg[index] = *cfg;
    }
  else
    {
      ret = (-((int32_t)1));
    }

  return ret;
}

/**
 * \brief  This API initialize the ESPI FW configuration
 *
 * \param     none
 *
 * \return    none
 *
 */
void ESPI_socInitFwCfg(void)
{
  SPI_config[6].fxnTablePtr = &ESPI_Init_FxnTable_v2;
  SPI_config[6].object = &EspiObjects[0];
  SPI_config[6].hwAttrs = &espiInitCfg[0];
  
  MCSPI_config[5][0].fxnTablePtr = &ESPI_FxnTable_v2;
  MCSPI_config[5][0].handle      = (SPI_Handle)(&(SPI_config[6]));
  MCSPI_config[5][0].chnNum      = 0;

  return;
}
#endif
