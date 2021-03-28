/**
 * @file   UART_soc.c
 *
 * @brief  This file defines the UART interface structure specific to OMAPL137
 */
/*
 * Copyright (c) 2015 - 2018, Texas Instruments Incorporated
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
#include <ti/csl/soc.h>
#include <ti/csl/csl_device_interrupt.h>
#include <ti/drv/uart/UART.h>
#ifdef UART_DMA_ENABLE
#include <ti/sdo/edma3/drv/edma3_drv.h>
#endif
#include <ti/drv/uart/soc/UART_soc.h>

/* UART configuration structure */
UART_HwAttrs uartInitCfg[CSL_UART_CNT] =
{
    {
        CSL_UART_0_REGS, /* UART base address */
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER, /* default DSP Interrupt vector number, can be set in UART_socSetInitCfg() API */
        38, /* default DSP INTC UART Event ID, can be set in UART_socSetInitCfg() API */
        UART_INVALID_INTC_MUX_NUM,  /* CIC number */
#else
        25, /* UART int number for ARM GIC INTC */
        0,  /* Event ID not used for ARM INTC */
        UART_INVALID_INTC_MUX_NUM, /* CIC num not used in ARM GIC */
#endif
        CSL_INTC_EVENTID_UARTINT2, /* CIC UART Event ID */
        0, /* default CIC Host Interrupt, map to CIC_0_OUT32 event */
        CSL_EDMA3_CHA_UART0_RX,
        CSL_EDMA3_CHA_UART0_TX,
        CSL_EDMA3_CHA_UART0_TX,
        CSL_EDMA3_CHA_UART0_RX,
        0,
        0,
        300000000/2,  /* default UART frequency, system clock/6 */
        0,  /* version */
        NULL,
        TRUE,             /* dmaMode */
        FALSE,            /* loopback */
        TRUE,             /* enableInterrupt */
        UART_RXTRIGLVL_1, /* rxTrigLvl */
        1,                /* txTrigLvl */
        UART16x_OPER_MODE, /* operMode, 16x over sampling mode by default */
    },
    {
        CSL_UART_1_REGS,
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
        46,
        UART_INVALID_INTC_MUX_NUM,
#else
        53,
        0,
        UART_INVALID_INTC_MUX_NUM, /* CIC num not used in ARM GIC */
#endif
        CSL_INTC_EVENTID_UARTINT2,
        0,
        CSL_EDMA3_CHA_UART1_RX,
        CSL_EDMA3_CHA_UART1_TX,
        CSL_EDMA3_CHA_UART1_TX,
        CSL_EDMA3_CHA_UART1_RX,
        0,
        0,
        300000000/2,
        0,
        NULL,
        TRUE,
        FALSE,
        TRUE,
        UART_RXTRIGLVL_1,
        1,
        UART16x_OPER_MODE,
    },
    {
        CSL_UART_2_REGS,
#ifdef _TMS320C6X
        OSAL_REGINT_INTVEC_EVENT_COMBINER,
        69,
        UART_INVALID_INTC_MUX_NUM,
#else
        0x3D,
        16,
        UART_INVALID_INTC_MUX_NUM, /* CIC num not used in ARM GIC */
#endif
        CSL_INTC_EVENTID_UARTINT2,
        0,
        CSL_EDMA3_CHA_UART2_RX,
        CSL_EDMA3_CHA_UART2_TX,
        CSL_EDMA3_CHA_UART2_TX,
        CSL_EDMA3_CHA_UART2_RX,
        0,
        1,
        300000000/2,
        0,
        NULL,
        TRUE,
        FALSE,
        TRUE,
        UART_RXTRIGLVL_1,
        1,
        UART16x_OPER_MODE,
    },
};

/* UART objects */
UART_V0_Object UartObjects[CSL_UART_CNT];

/* UART configuration structure */
UART_Config UART_config[CSL_UART_CNT + 1U] =
{
    {
        &UART_FxnTable_v0,
        &UartObjects[0],
        &uartInitCfg[0]
    },

    {
        &UART_FxnTable_v0,
        &UartObjects[1],
        &uartInitCfg[1]
    },

    {
        &UART_FxnTable_v0,
        &UartObjects[2],
        &uartInitCfg[2]
    },

    {
        NULL,
        NULL,
        NULL
    }
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

    if (index < CSL_UART_CNT)
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

    if (index < CSL_UART_CNT)
    {
        uartInitCfg[index] = *cfg;
    }
    else
    {
        ret = -1;
    }

    return ret;
}

#ifdef UART_DMA_ENABLE
/**
 * \brief  This API gets the SoC specific EDMA3 info
 *
 * \param  index        UART instance index.
 * \param  edma3Id      pointer to EDMA3CC #.
 * \param  edma3Event   pointer to EDMA3 event array.
 *
 * \return none
 *
 */
void UART_getEdmaInfo(uint32_t index, uint32_t *edma3Id, uint32_t *edma3Event)
{
    const uint32_t edma3id[CSL_UART_CNT] = {0, 0, 0};
    const uint32_t edma3RxEvent[CSL_UART_CNT] =
    {
        CSL_EDMA3_CHA_UART0_RX,
        CSL_EDMA3_CHA_UART1_RX,
        CSL_EDMA3_CHA_UART2_RX
    };
    const uint32_t edma3TxEvent[CSL_UART_CNT] =
    {
        CSL_EDMA3_CHA_UART0_TX,
        CSL_EDMA3_CHA_UART1_TX,
        CSL_EDMA3_CHA_UART2_TX
    };

    *edma3Id = edma3id[index];
    edma3Event[0] = edma3RxEvent[index];
    edma3Event[1] = edma3TxEvent[index];
}
#endif
