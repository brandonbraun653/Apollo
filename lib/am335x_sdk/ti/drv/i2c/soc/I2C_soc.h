/**
 * @file   I2C_soc.h
 *
 * @brief  I2C SoC level driver
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

#ifndef I2C_SOC_H
#define I2C_SOC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl_utils.h>
#include <ti/drv/i2c/I2C.h>
#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2L) || defined(SOC_K2E) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
#include <ti/drv/i2c/soc/I2C_v0.h>
#else
#include <ti/drv/i2c/soc/I2C_v1.h>
#if defined(SOC_AM572x) || defined(SOC_AM574x) || defined(SOC_AM437x) || defined(SOC_AM437X) || defined(SOC_AM335x) || defined(SOC_AM335X)
#include <ti/drv/i2c/soc/I2C_v2.h>
#endif
#endif

#include <ti/osal/osal.h>

/* Number of I2C instances present in the SoC */
#if defined(SOC_AM571x)
#define I2C_HWIP_MAX_CNT         (5U)

#elif defined(SOC_AM572x) || defined(SOC_AM574x)
#define I2C_HWIP_MAX_CNT         (5U)
#define I2C_SWIP_MAX_CNT         (1U)

#elif defined(SOC_AM335x) || defined(SOC_AM335X)
#define I2C_HWIP_MAX_CNT         (3U)
#define I2C_SWIP_MAX_CNT         (1U)

#elif defined(SOC_AM437x) || defined(SOC_AM437X)
#define I2C_HWIP_MAX_CNT         (3U)
#define I2C_SWIP_MAX_CNT         (2U)

#elif defined(SOC_K2G)
#define I2C_HWIP_MAX_CNT         (CSL_I2C_CNT)

#elif defined(SOC_AM65XX)
#define I2C_HWIP_MAX_CNT         (4U)

#elif defined(SOC_J721E) || defined(SOC_J7200)
#define I2C_HWIP_MAX_CNT         (7U)

#endif
/* I2C SoC HW IP level API */
extern int32_t I2C_socGetInitCfg(uint32_t index, I2C_HwAttrs *cfg);
extern int32_t I2C_socSetInitCfg(uint32_t index, const I2C_HwAttrs *cfg);

/* I2C SoC SW IP level API */
#if defined(SOC_AM572x) || defined(SOC_AM574x) || defined(SOC_AM437x) || defined(SOC_AM437X) || defined(SOC_AM335x) || defined(SOC_AM335X)
extern int32_t I2C_socGetFwCfg(uint32_t index, I2C_SwIPAttrs *cfg);
extern int32_t I2C_socSetFwCfg(uint32_t index, const I2C_SwIPAttrs *cfg);
extern void I2C_socInitFwCfg(void);
#endif

#define I2C_MODULE_CLOCK_DIVIDER    (6U)

#ifdef __cplusplus
}
#endif

#endif /* I2C_SOC_H */
