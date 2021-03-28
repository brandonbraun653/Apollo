/**
 * @file   UART_soc.h
 *
 * @brief  UART SoC level driver
 */
/*
 * Copyright (c) 2015 - 2019, Texas Instruments Incorporated
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

#ifndef ti_drivers_uart_UARTsoc__include
#define ti_drivers_uart_UARTsoc__include

#include <ti/drv/uart/UART.h>
#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138) ||\
    defined(DEVICE_K2H) || defined(DEVICE_K2K) || defined(DEVICE_K2L) || defined(DEVICE_K2E) || defined(DEVICE_K2G) || defined(DEVICE_C6678) || defined(DEVICE_C6657) || defined(DEVICE_OMAPL137) || defined(DEVICE_OMAPL138)
#include <ti/csl/src/ip/uart/V0/uart.h>
#include <ti/drv/uart/src/v0/UART_v0.h>
#else
#include <ti/csl/src/ip/uart/V1/uart.h>
#include <ti/drv/uart/src/v1/UART_v1.h>
#if defined(SOC_AM335x) || defined(SOC_AM335X)
#include <ti/drv/uart/src/v2/UART_v2.h>
#endif
#endif
#include <ti/osal/osal.h>

#ifdef __cplusplus
extern "C" {
#endif

/* UART SoC level API */
#ifdef UART_DMA_ENABLE
extern void UART_getEdmaInfo(uint32_t idx, uint32_t *edma3Id, uint32_t *edma3Event);
#endif

/* UART SoC HW IP level API */
extern int32_t UART_socGetInitCfg(uint32_t idx, UART_HwAttrs *cfg);
extern int32_t UART_socSetInitCfg(uint32_t idx, const UART_HwAttrs *cfg);

/* UART SoC SW IP level API */
#if defined(SOC_AM335x) || defined(SOC_AM335X)
extern int32_t UART_socGetFwCfg(uint32_t index, UART_SWIPAttrs *cfg);
extern int32_t UART_socSetFwCfg(uint32_t index, const UART_SWIPAttrs *cfg);
extern void UART_socInitFwCfg(void);
#endif


#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_UARTsoc__include */
