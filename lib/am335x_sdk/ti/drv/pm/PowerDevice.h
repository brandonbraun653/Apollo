/*
 * Copyright (c) 2016-2017, Texas Instruments Incorporated
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
 *  @brief      Power manager device-specific interface
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

#ifndef POWERDEVICE_TOP_H_
#define POWERDEVICE_TOP_H_

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */

#include <stdint.h>

#include <Power.h>
#if defined(SOC_TDA2XX) || defined(SOC_AM572x) || defined(SOC_DRA75x)
#include <ti/drv/pm/include/prcm/V0/PowerDevice.h>
#endif

#if defined(SOC_TDA2EX) || defined(SOC_AM571x)
#include <ti/drv/pm/include/prcm/V1/PowerDevice.h>
#endif

#if defined(SOC_TDA3XX) || defined(SOC_DRA78x)
#include <ti/drv/pm/include/prcm/V2/PowerDevice.h>
#endif

#if defined(SOC_AM335x)
#include <ti/drv/pm/include/prcm/V3/PowerDevice.h>
#endif

#if defined(SOC_AM437x)
#include <ti/drv/pm/include/prcm/V4/PowerDevice.h>
#endif

#if defined(SOC_K2G)
#include <ti/drv/pm/include/pmmc/V0/PowerDevice.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */

/*! @brief  Power global configuration */
typedef struct PowerDevice_Cfg {
    Power_PolicyInitFxn      policyInitFxn;    /* init function for power
                                                * policy */
    Power_PolicyDeinitFxn    policyDeinitFxn;  /* deinit function for power
                                                * policy */
    Power_PolicyFxn          policyFxn;        /* the power policy function */
    unsigned int             initialPerfLevel; /* initial performance level */
    bool                     enablePolicy;     /* enables power policy function
                                                * to run in idle loop */
    bool                     enablePerf;       /* enables performance level
                                                * control */
    bool                     hwInit;           /* Flag to perform hw init */
    bool                     swInit;           /* Flag to perform sw init */
    unsigned int             siliconPkgType;   /* package type passed from app
                                                * */
#if (PowerDevice_CAPABILITY_Thermal == 1)
    PowerDevice_ThermalCfg_t thermalCfg;       /* thermal config structure */
#endif
#if (PowerDevice_CAPABILITY_PmCoprocessor == 1)
    const void              *pFirmware;        /* pointer to coprocessor
                                                * firmware image */
    unsigned int             sizeFirmware;     /* size of firmware in bytes */
#endif
} PowerDevice_Cfg_t;

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Function Declarations                           */
/* ========================================================================== */

/*!
 *  @brief  Initializes the PowerDevice config structure
 *
 *  This function Initializes PowerDevice config structure to reset state
 *
 *  @param PowerDevice_config Pointer to the configuration structure to be
 *         initialized.
 *
 *  @return A status code indicating success or failure: Power_SOK if the
 *       configuration was initialized, Power_EFAIL if the structure provided
 *       is NULL.
 */
unsigned int PowerDevice_Cfg_Init(PowerDevice_Cfg_t * PowerDevice_config);


#ifdef __cplusplus
}
#endif

#endif /* POWERDEVICE_TOP_H_ */
