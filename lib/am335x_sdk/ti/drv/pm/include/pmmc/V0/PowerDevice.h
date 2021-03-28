/*
 * Copyright (c) 2017, Texas Instruments Incorporated
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
/** ============================================================================
 *  @file       PowerDevice.h
 *
 *  @brief      Power manager interface for the following devices:
 *                  SOC_K2G
 *
 *  The Power header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/pm/Power.h>
 *  #include <ti/drv/pm/PowerExtended.h>
 *  #include <ti/drv/pm/PowerDevice.h>
 *  @endcode
 *
 *  Refer to @ref Power.h and @ref PowerExtended.h for a complete description
 *  of APIs.
 *
 *  ============================================================================
 */

#ifndef POWERDEVICE_H_
#define POWERDEVICE_H_

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */

#include <stdint.h>
#include <ti/drv/pm/PowerExtended.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

/*!< device-specific power capabilities:
 *       0 - not supported on device
 *       1 - supported on device */
#define PowerDevice_CAPABILITY_Thermal        (0U)
#define PowerDevice_CAPABILITY_PmCoprocessor  (1U) /* PMMC */

/*!< base value for device-specific error return codes */
#define PowerDevice_EBASE                     (2048U)
/*!< invalid thermal set point index */
#define Power_EINVALID_SET_POINT_INDEX        (PowerDevice_EBASE + 0U)
/*!< API unimplemented */
#define Power_EUNIMPLEMENTED                  (PowerDevice_EBASE + 1U)

// TODO: Calculate these values
#if defined (__ARM_ARCH_7A__)
/* latency times in microseconds for A15 */
#define PowerDevice_RESUMETIMESLEEP           (154U)
#define PowerDevice_TOTALTIMESLEEP            (320U)
#define PowerDevice_RESUMETIMEDEEPSLEEP       (156U)
#define PowerDevice_TOTALTIMEDEEPSLEEP        (324U)
#elif defined (_TMS320C6X)
/* latency times in microseconds for DSP */
#define PowerDevice_RESUMETIMESLEEP           (182U)
#define PowerDevice_TOTALTIMESLEEP            (339U)
#define PowerDevice_RESUMETIMEDEEPSLEEP       (183U)
#define PowerDevice_TOTALTIMEDEEPSLEEP        (354U)
#endif

/* K2G only has a single OPP according to device spec but PMMC allows for
 * different frequencies.  Investigate allowing other frequency settings */
#if defined (__ARM_ARCH_7A__)
/*!< OPP 50 Frequency */
#define PowerDevice_FREQ_OPP_LOW              (600000000U)
/*!< OPP 100 Frequency */
#define PowerDevice_FREQ_OPP_NOM              (600000000U)
/*!< OPP 120 Frequency */
#define PowerDevice_FREQ_OPP_OD               (600000000U)
/*!< OPP TURBO Frequency */
#define PowerDevice_FREQ_OPP_HIGH             (600000000U)
/*!< OPP NITRO Frequency */
#define PowerDevice_FREQ_OPP_HIGH2            (600000000U)
#endif

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Function Declarations                           */
/* ========================================================================== */

/* default policy init function for config structure */
void PowerDevice_policyInitFxn(void);

/* default policy deinit function for config structure */
void PowerDevice_policyDeinitFxn(void);

/* default power policy function for config structure */
void PowerDevice_policyFxn(void);

#ifdef __cplusplus
}
#endif

#endif /* POWERDEVICE_H_ */
