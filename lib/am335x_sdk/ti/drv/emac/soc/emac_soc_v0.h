/**
 * @file   emac_soc_v0.h
 *
 * @brief  EMAC SoC level config header file
 */
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

#ifndef EMAC_SOC_V0__H
#define EMAC_SOC_V0__H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl_utils.h>
#include <ti/osal/osal.h>

/*!
 *  @brief  EMAC Hardware attributes for OMAPL137
 */
typedef struct EMAC_HwAttrs_V0_s {
    /**< Number of DSP cores */
    uint32_t  numDSPCores;
    /**< MAC select */
    uint32_t  macSel;
    /**< emac mode flag select */
    uint32_t  modeFlags; 
    /**< core num */
    int32_t  coreNum;
    /**< GMAC SW receive packet interrupt number*/
    uint32_t rxIntrNum;
    /**< EMAC SW receive packet  event ID*/
    uint32_t rxEventId;
    /**< EMAC SW transmit packet interrupt number*/
    uint32_t txIntrNum;
    /**< EMAC SW transmit packet  event ID*/
    uint32_t txEventId;
 } EMAC_HwAttrs_V0;

uint32_t EMAC_RMIISpeedSelect(uint32_t tmpval);

int32_t EMAC_sgmiiInitCfg( void);

int32_t EMAC_socGetInitCfg(uint32_t port_num, EMAC_HwAttrs_V0 *cfg);

int32_t EMAC_socSetInitCfg(uint32_t port_num, const EMAC_HwAttrs_V0 *cfg);

#ifdef __cplusplus
}
#endif


#endif /* EMAC_SOC_V0__H */
