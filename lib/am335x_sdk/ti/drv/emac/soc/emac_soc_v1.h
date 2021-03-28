/**
 * @file   I2C_soc.h
 *
 * @brief  I2C SoC level driver
 */
/*
 * Copyright (c) 2015-2019, Texas Instruments Incorporated
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

#ifndef EMAC_SOC_V1__H
#define EMAC_SOC_V1__H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl_utils.h>
#include <ti/drv/qmss/qmss_drv.h>
#include <ti/osal/osal.h>

/*!
 *  @brief      Convert L2 cache address to global address.
 */
typedef uint32_t (*EMAC_convertCoreLocal2GlobalAddr) (uint32_t  addr);

/*!
 *  @brief  EMAC Hardware attributes for K2G
 */

typedef struct EMAC_HwAttrs_V1_s {

    /*!  Pointer to descriptor region base to be inserted into the QMSS memory region., must be provided by user application*/
   void* p_desc_base; /* pointer to descriptor region base to be inserted into the QMSS memory region., must be provided by user application*/

    /*!  flag to indicate whether LLD should initialize QMSS sub-system */
    Bool initQmss;
    /*!  flag to indicate whether LLD should initialize CPPI sub-system */
    Bool initCppi;
    /*!  Parameter to allow application to specify memory region, to allow 
           qmss sub-system to select available region, 
           should be set to Qmss_MemRegion_MEMORY_REGION_NOT_SPECIFIED*/
    Qmss_MemRegion qmssMemoryRegion; 
    /*!DSP: int vector number; ARM: GIC int number (peripheral event ID + 32) */
    uint32_t intNum;
    /*!CorePac specific Event ID offset from RX queue , input to CorePac interrupt controller */
    uint32_t eventIdOffset;
    /*!Maximum number of ethernet ports */
    uint32_t numEmacPorts;
    /*!PHY address of ethernet port */
     uint32_t phyAddr;
    /*!Pointer to convert Local cache to global address */
    EMAC_convertCoreLocal2GlobalAddr local2GlobalAddr;
} EMAC_HwAttrs_V1;

int32_t EMAC_socGetInitCfg(uint32_t port_num, EMAC_HwAttrs_V1 *cfg);

int32_t EMAC_socSetInitCfg(uint32_t port_num, const EMAC_HwAttrs_V1 *cfg);

uint32_t EMAC_convert_coreLocal2GlobalAddr (uint32_t  addr);

#ifdef __cplusplus
}
#endif

#endif /* EMAC_SOC_V1__H */
