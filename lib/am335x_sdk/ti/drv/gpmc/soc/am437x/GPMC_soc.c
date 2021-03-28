/**
 *  \file   GPMC_soc.c
 *
 *  \brief  AM437x device specific hardware attributes.
 *
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
#include <ti/drv/gpmc/GPMC.h>
#include <ti/drv/gpmc/soc/GPMC_soc.h>

#define CSL_GPMC_CNT        (1U)

#define CSL_GPMC_REG        (0x50000000U)
#define CSL_ELM_REG         (0x48080000U)

/* GPMC configuration structure */
GPMC_v1_HwAttrs GPMCInitCfg[CSL_GPMC_CNT + 1] =
{
    {
        CSL_GPMC_REG,                 /* gpmcBaseAddr */
        GPMC_DEVICETYPE_NANDLIKE,     /* devType */
        GPMC_DEVICESIZE_8BITS,        /* devSize */
        GPMC_MUXADDDATA_NOMUX,        /* addrDataMux */
        GPMC_TIMEPARAGRANULARITY_X2,  /* timeLatency */
        0,                            /* chipSel */
        0x10000000U,                  /* chipSelBaseAddr */
        GPMC_CS_SIZE_256MB,           /* chipSelAddrSize */
        132 + 32,                     /* intrNum */
        0,                            /* eventId */
        INVALID_INTC_MUX_NUM,         /* intcMuxNum */
        -1,                           /* intcMuxInEvent */
        -1,                           /* intcMuxOutEvent */
        false,                        /* intrEnable */
        0,                            /* waitPinNum */
        GPMC_WAIT_PIN_POLARITY_LOW,   /* waitPinPol */
        {
            0U,                       /* csOnTime */
            7U,                       /* csRdOffTime */
            7U,                       /* csWrOffTime */
            0U,                       /* advOnTime */
            0U,                       /* advRdOffTime */
            7U,                       /* advWrOffTime */
            0U,                       /* advAadMuxOnTime */
            0U,                       /* advAadMuxRdOffTime */
            0U,                       /* advAadMuxWrOffTime */
            0U,                       /* weOnTime */
            5U,                       /* weOffTime */
            0U,                       /* oeOnTime */
            5U,                       /* oeOffTime */
            5U,                       /* oeAadMuxOnTime */
            0U,                       /* oeAadMuxOffTime */
            0U,                       /* pageBurstAccessTime */
            6U,                       /* rdAccessTime */
            6U,                       /* wrAccessTime */
            7U,                       /* rdCycleTime */
            7U,                       /* wrCycleTime */
            7U,                       /* wrDataOnMuxBusTime */
            0U,                       /* cycle2CycleDelay */
            GPMC_CYCLE2CYCLESAMECSEN_NOC2CDELAY, /* cycleDelaySameChipSel */
            GPMC_CYCLE2CYCLEDIFFCSEN_NOC2CDELAY, /* cycleDelayDiffChipSel */
            0U                        /* busTurnAroundTime */
        },
        CSL_ELM_REG,                  /* elmBaseAddr */
        GPMC_NAND_ECC_ALGO_BCH_8BIT   /* eccAlgo */
    },
};


/* GPMC objects */
GPMC_v1_Object GPMCObjects[CSL_GPMC_CNT + 1];


/* GPMC configuration structure */
const GPMC_config_list GPMC_config = {
    {
        &GPMC_FxnTable_v1,
        &GPMCObjects[0],
        &GPMCInitCfg[0]
    },
    {
        NULL,
        NULL,
        NULL
    }
};

/**
 * \brief  This API gets the SoC level of GPMC intial configuration
 *
 * \param  index     GPMC instance index.
 * \param  cfg       Pointer to GPMC SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t GPMC_socGetInitCfg(uint32_t index, GPMC_v1_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (index < CSL_GPMC_CNT)
    {
        *cfg = GPMCInitCfg[index];
    }
    else
    {
        ret = -1;
    }

    return ret;
}

/**
 * \brief  This API sets the SoC level of GPMC intial configuration
 *
 * \param  index     GPMC instance index.
 * \param  cfg       Pointer to GPMC SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t GPMC_socSetInitCfg(uint32_t index, const GPMC_v1_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (index < CSL_GPMC_CNT)
    {
        GPMCInitCfg[index] = *cfg;
    }
    else
    {
        ret = -1;
    }

    return ret;
}

