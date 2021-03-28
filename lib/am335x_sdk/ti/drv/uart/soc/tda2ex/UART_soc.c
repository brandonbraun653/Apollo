/**
 * @file   UART_soc.c
 *
 * @brief  This file defines the UART interface structure specific to tda2ex
 */
/*
 * Copyright (c) 2014 - 2018, Texas Instruments Incorporated
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
#include <ti/csl/cslr_device.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/src/v1/UART_v1.h>

/* UART configuration structure */
UART_HwAttrs uartInitCfg[CSL_UART_PER_CNT] =
{
    {
#if defined (__TI_ARM_V7M4__)
        SOC_UART1_BASE,
        44,
#endif
        67,
        CSL_UART_0_MODULE_FREQ,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        FALSE, /* default DMA mode disabled */
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE, /* operMode, 16x over sampling mode by default */
    },
    {
#if defined (__TI_ARM_V7M4__)
        SOC_UART2_BASE,
        60,
#endif
        68,
        CSL_UART_1_MODULE_FREQ,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        FALSE,
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
    {
#if defined (__TI_ARM_V7M4__)
        SOC_UART3_BASE,
        45,
#endif
        69,
        CSL_UART_2_MODULE_FREQ,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        FALSE,
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
    {
#if defined (__TI_ARM_V7M4__)
        SOC_UART4_BASE,
        61,
#endif
        65,
        CSL_UART_3_MODULE_FREQ,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        FALSE,
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
    {
#if defined (__TI_ARM_V7M4__)
        SOC_UART5_BASE,
        62,
#endif
        100,
        CSL_UART_4_MODULE_FREQ,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        FALSE, /* default DMA mode disabled */
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
    {
#if defined (__TI_ARM_V7M4__)
        SOC_UART6_BASE,
        63,
#endif
        101,
        CSL_UART_5_MODULE_FREQ,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        FALSE,
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
    {
#if defined (__TI_ARM_V7M4__)
        SOC_UART7_BASE,
        64,
#endif
        218,
        CSL_UART_6_MODULE_FREQ,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        FALSE,
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
    {
#if defined (__TI_ARM_V7M4__)
        SOC_UART8_BASE,
        65,
#endif
        219,
        CSL_UART_7_MODULE_FREQ,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        FALSE,
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
    {
#if defined (__TI_ARM_V7M4__)
        SOC_UART9_BASE,
        69,
#endif
        220,
        CSL_UART_8_MODULE_FREQ,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        FALSE,
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
    },
    {
#if defined (__TI_ARM_V7M4__)
        SOC_UART10_BASE,
        70,
#endif
        221,
        CSL_UART_9_MODULE_FREQ,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        NULL,
        UART_RXTRIGLVL_8,
        UART_TXTRIGLVL_56,
        FALSE,
        FALSE, /* Loopback disabled by default */
		TRUE, /* Interrupt enabled by default */
        UART16x_OPER_MODE,
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
    {
        &UART_FxnTable_v1,
        &UartObjects[6],
        &uartInitCfg[6]
    },

    {
        &UART_FxnTable_v1,
        &UartObjects[7],
        &uartInitCfg[7]
    },

    {
        &UART_FxnTable_v1,
        &UartObjects[8],
        &uartInitCfg[8]
    },
    {
        &UART_FxnTable_v1,
        &UartObjects[9],
        &uartInitCfg[9]
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

    if (index < CSL_UART_PER_CNT)
    {
        uartInitCfg[index] = *cfg;
    }
    else
    {
        ret = -1;
    }

    return ret;
}

