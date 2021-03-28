/*
 * Copyright (c) 2019 - 2020, Texas Instruments Incorporated
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
 *
 */

/**
 *
 * \file  nor_hyperflash.h
 *
 * \brief This file contains structure, typedefs, functions and
 *        prototypes used for HYPERBUS interface for Hyperflash.
 *
 *****************************************************************************/

#ifndef NOR_HYPERFLASH_H_
#define NOR_HYPERFLASH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>

#include <ti/board/src/flash/nor/nor.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/osal/osal.h>

#include <ti/csl/csl_hyperbus.h>

#if defined(j721e_evm) || defined(j7200_evm)
#include <ti/board/src/flash/nor/device/s71ks512s.h>
#endif

#define CSL_FSS0_CFG_BASE                   (0x47000000U)

#define MCU_FSS0_SYSCONFIG                  (0x47000004U)

#define ENABLE_FSS0_HPB                     (0x2U)
#define DISABLE_FSS0_HPB                    (0x0U)

#define HYPERFLASH_CS_PIN                   (0x0U)

typedef struct HPF_Params_s {
    uint8_t                     chipSelect;             /*!< Chip select of hyperflash */
    uint64_t                    regionAddress;          /*!< FSS Region Address */
    uint32_t                    baseAddress;            /*!< Base Address */
    CSL_HyperbusMemTimingReg    hyperbusTimingConfig;   /*!< Hyperbus memory timing parameter configuration */
} HPF_Params;

typedef struct HPF_Object_s
{
    uint32_t baseAddr;
    uint8_t  cs;
    bool     isOpen;
} HPF_Object;

#ifdef __cplusplus
}
#endif

#endif /* NOR_HYPERFLASH_H_ */

/* Nothing past this point */
