/**
 * @file   UART_soc.c
 *
 * @brief  This file defines the UART interface structure specific to AM437x
 */
/*
 * Copyright (c) 2014-2018, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================*/

#include <ti/csl/csl_utils.h>
#include <ti/drv/uart/UART.h>
#include <ti/starterware/include/types.h>
#include <ti/starterware/include/hw/am437x.h>
#include <ti/drv/uart/soc/UART_soc.h>

#define CSL_EDMA3_CHA_UART0_RX    (27U)
#define CSL_EDMA3_CHA_UART0_TX    (26U)
#define CSL_EDMA3_CHA_UART1_RX    (29U)
#define CSL_EDMA3_CHA_UART1_TX    (28U)
#define CSL_EDMA3_CHA_UART2_RX    (31U)
#define CSL_EDMA3_CHA_UART2_TX    (30U)
#define CSL_EDMA3_CHA_UART3_RX    (8U)     /* Cross bar mapped */
#define CSL_EDMA3_CHA_UART3_TX    (7U)     /* Cross bar mapped */
#define CSL_EDMA3_CHA_UART4_RX    (10U)    /* Cross bar mapped */
#define CSL_EDMA3_CHA_UART4_TX    (9U)     /* Cross bar mapped */
#define CSL_EDMA3_CHA_UART5_RX    (12U)    /* Cross bar mapped */
#define CSL_EDMA3_CHA_UART5_TX    (11U)    /* Cross bar mapped */

#define CSL_UART_PER_CNT_AM437X    (6U)


/* UART configuration structure */
UART_HwAttrs uartInitCfg[CSL_UART_PER_CNT_AM437X] =
{
    {
        SOC_UART0_REG,
        104,
        0,
        48000000U,
        CSL_EDMA3_CHA_UART0_RX,
        CSL_EDMA3_CHA_UART0_TX,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        TRUE, /* default DMA mode */
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE, /* operMode, 16x over sampling mode by default */
    },
    {
        SOC_UART1_REG,
        105,
        0,
        48000000U,
        CSL_EDMA3_CHA_UART1_RX,
        CSL_EDMA3_CHA_UART1_TX,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        TRUE, /* default DMA mode */
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
    {
        SOC_UART2_REG,
        106,
        69,
        48000000U,
        CSL_EDMA3_CHA_UART2_RX,
        CSL_EDMA3_CHA_UART2_TX,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        TRUE, /* default DMA mode */
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
    {
        SOC_UART3_REG,
        76,
        0,
        48000000U,
        CSL_EDMA3_CHA_UART3_RX,
        CSL_EDMA3_CHA_UART3_TX,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        TRUE, /* default DMA mode */
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
    {
        SOC_UART4_REG,
        77,
        0,
        48000000U,
        CSL_EDMA3_CHA_UART4_RX,
        CSL_EDMA3_CHA_UART4_TX,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        TRUE, /* default DMA mode */
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
    {
        SOC_UART5_REG,
        78,
        0,
        48000000U,
        CSL_EDMA3_CHA_UART5_RX,
        CSL_EDMA3_CHA_UART5_TX,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        TRUE, /* default DMA mode */
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
};

/* UART objects */
UART_V1_Object UartObjects[CSL_UART_PER_CNT_AM437X];

/* UART configuration structure */
UART_config_list UART_config = {
    {
        &UART_FxnTable_v1,
        &UartObjects[0],
        &uartInitCfg[0]
    },

    {
         &UART_FxnTable_v1,
         &UartObjects[1],
         &uartInitCfg[1]
    },

    {
         &UART_FxnTable_v1,
         &UartObjects[2],
         &uartInitCfg[2]
    },

    {
         &UART_FxnTable_v1,
         &UartObjects[3],
         &uartInitCfg[3]
    },

    {
         &UART_FxnTable_v1,
         &UartObjects[4],
         &uartInitCfg[4]
     },

     {
          &UART_FxnTable_v1,
          &UartObjects[5],
          &uartInitCfg[5]
     },
     /* pad to full predefined length of array */
     {NULL, NULL, NULL},
     {NULL, NULL, NULL},
     {NULL, NULL, NULL},
     {NULL, NULL, NULL},
     {NULL, NULL, NULL}
};

/**
 * \brief  This API gets the SoC level of UART intial configuration
 *
 * \param  index     UART instance index.
 * \param  cfg       Pointer to UART SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t UART_socGetInitCfg(uint32_t index, UART_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (index < CSL_UART_PER_CNT_AM437X)
    {
        *cfg = uartInitCfg[index];
    }
    else
    {
        ret = -1;
    }

    return ret;
}

/**
 * \brief  This API sets the SoC level of UART intial configuration
 *
 * \param  index     UART instance index.
 * \param  cfg       Pointer to UART SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t UART_socSetInitCfg(uint32_t index, const UART_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (index < CSL_UART_PER_CNT_AM437X)
    {
        uartInitCfg[index] = *cfg;
    }
    else
    {
        ret = -1;
    }

    return ret;
}


