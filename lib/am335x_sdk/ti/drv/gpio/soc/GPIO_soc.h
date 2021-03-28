/**
 * @file   GPIO_soc.h
 *
 * @brief  GPIO SoC level driver
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

#ifndef GPIO__SOC__H
#define GPIO__SOC__H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drv/gpio/GPIO.h>
#include <ti/osal/osal.h>
#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138) || defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
#include <ti/drv/gpio/src/v0/GPIO_v0.h>
#endif

#if defined(SOC_AM574x) || defined(SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_DRA72x) || defined(SOC_DRA75x) || defined(SOC_DRA78x)
#include <ti/drv/gpio/soc/GPIO_v1.h>
#include <ti/csl/src/ip/gpio/V1/gpio_v2.h>
#endif

/* GPIO SoC level API */
#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138) || defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
extern int32_t GPIO_socGetInitCfg(uint32_t idx, GPIO_v0_HwAttrs *cfg);
extern int32_t GPIO_socSetInitCfg(uint32_t idx, const GPIO_v0_HwAttrs *cfg);
extern void GPIO_socGetNumPinsPorts(uint32_t *numPins, uint32_t *numPorts);
#endif

#if defined(SOC_K2G)
extern int32_t GPIO_socSetIntMux(uint32_t index, uint32_t pinNum, const GPIO_IntCfg *cfg, uint32_t muxEvtSel);
#endif

#if defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
extern int32_t GPIO_socSetBankInt(uint32_t index, uint32_t pinNum, const GPIO_IntCfg *cfg);
#endif

#ifdef __cplusplus
}
#endif

#endif /* GPIO__SOC__H */
