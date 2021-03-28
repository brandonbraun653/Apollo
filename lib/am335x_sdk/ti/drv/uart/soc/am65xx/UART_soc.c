/**
 * @file   UART_soc.c
 *
 * @brief  This file defines the UART interface structure specific to AM65XX
 */
/*
 * Copyright (c) 2017 - 2018, Texas Instruments Incorporated
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
#include <ti/csl/soc/am65xx/src/cslr_soc.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/soc/UART_soc.h>
#include <ti/drv/udma/udma.h>

#if defined (__aarch64__)
#define UART_PDMA_TX_THREAD_BASE        (CSL_PSILCFG_NAVSS_MAIN_PDMA_MAIN1_PSILD_THREAD_OFFSET + 20U)
#define UART_PDMA_RX_THREAD_BASE        (CSL_PSILCFG_NAVSS_MAIN_PDMA_MAIN1_PSILS_THREAD_OFFSET + 20U)
#else
#define UART_PDMA_TX_THREAD_BASE        (CSL_PSILCFG_NAVSS_MCU_PDMA_MCU1_PSILD_THREAD_OFFSET + 18U)
#define UART_PDMA_RX_THREAD_BASE        (CSL_PSILCFG_NAVSS_MCU_PDMA_MCU1_PSILS_THREAD_OFFSET + 18U)
#endif

/* UART configuration structure */
UART_HwAttrs uartInitCfg[CSL_UART_PER_CNT] =
{
    {
#if defined (__aarch64__) /* main */
        CSL_UART0_BASE,                      /* baseAddr */
        CSL_GIC0_INTR_USART0_BUS_USART_IRQ,  /* intNum */
#else /* mcu */
        CSL_MCU_UART0_BASE,
        CSL_MCU0_INTR_UART1_USART_IRQ,
#endif
        0,                              /* eventId, used only for C6x */
#if defined (__aarch64__) /* main */
        48000000,
#else /* mcu */
        96000000,
#endif
        UART_PDMA_RX_THREAD_BASE,       /* rxDmaEventNumber, used as UART PDMA RX
                                           thread # for the UART instance */
        UART_PDMA_TX_THREAD_BASE,       /* txDmaEventNumber, used as UART PDMA TX
                                           thread # for the UART instance */
        0,                              /* edmaTxTCC */
        0,                              /* edmaRxTCC */
        0,                              /* edmaTxTC */
        0,                              /* edmaRxTC */
        0,                              /* version */
        NULL,                           /* edmaHandle */
        UART_RXTRIGLVL_8,               /* rxTrigLvl */
        UART_TXTRIGLVL_56,              /* txTrigLvl */
        FALSE,                          /* dmaMode */
        FALSE,                          /* loopback */
        TRUE,                           /* enableInterrupt */
        UART16x_OPER_MODE,              /* operMode, 16x over sampling mode by default */
        NULL,                           /* dmaInfo */
        NULL                            /* configSocIntrPath */
    },
    {
#if defined (__aarch64__)
        CSL_UART1_BASE,                      /* baseAddr */
        CSL_GIC0_INTR_USART1_BUS_USART_IRQ,  /* intNum */
#else
        0,
        0,
#endif
        0,
        48000000,
        UART_PDMA_RX_THREAD_BASE + 1U,
        UART_PDMA_TX_THREAD_BASE + 1U,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        FALSE,
        FALSE,
        TRUE,
        UART16x_OPER_MODE,
        NULL,
        NULL
    },
    {
#if defined (__aarch64__)
        CSL_UART2_BASE,                      /* baseAddr */
        CSL_GIC0_INTR_USART2_BUS_USART_IRQ,  /* intNum */
#else
        0,
        0,
#endif
        0,
        48000000,
        UART_PDMA_RX_THREAD_BASE + 2U,
        UART_PDMA_TX_THREAD_BASE + 2U,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        FALSE,
        FALSE,
        TRUE,
        UART16x_OPER_MODE,
        NULL,
        NULL
    },
};

/* UART objects */
UART_V1_Object UartObjects[CSL_UART_PER_CNT];

/* UART configuration structure */
UART_Config UART_config[CSL_UART_PER_CNT + 1U] = {
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

    if (index < CSL_UART_PER_CNT)
    {
        *cfg = uartInitCfg[index];
    }
    else
    {
        ret = (int32_t)(-1);
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

    if (index < CSL_UART_PER_CNT)
    {
        uartInitCfg[index] = *cfg;
    }
    else
    {
        ret = (int32_t)(-1);
    }

    return ret;
}

#if defined (BUILD_MCU)
/**
 * \brief  This API initializes the SoC level of UART configuration
 *         based on the core and domain
 *
 * \param  none
 *
 * \return none
 *
 */
void UART_socInit(void)
{
}
#endif
