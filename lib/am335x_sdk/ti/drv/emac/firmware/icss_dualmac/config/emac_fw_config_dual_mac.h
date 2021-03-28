/**
 * @file   emac_fw_config_dual_mac.h
 */
/*
 * Copyright (c) 2019, Texas Instruments Incorporated
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



#ifndef EMAC_FW_CONFIG_DUAL_MAC_H_
#define EMAC_FW_CONFIG_DUAL_MAC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drv/emac/src/v5/emac_drv_v5.h>

#define EMAC_ICSSG_DUAL_MAC_FW_HOST_QUEUE_SIZE    ((uint32_t)6144U)       /* ~6.kB per host queue */

extern int32_t emacGetDualMacFwConfig(uint32_t portNum, EMAC_PER_PORT_ICSSG_FW_CFG **pStaticMMap);
extern int32_t emacSettDualMacFwConfig(uint32_t portNum, const EMAC_PER_PORT_ICSSG_FW_CFG *pStaticCfg);
extern int32_t emacGetDualMacFwAppInitCfg(uint32_t portNum, EMAC_FW_APP_CONFIG **pFwAppCfg);
extern int32_t emacSetDualMacFwAppInitCfg(uint32_t portNum, EMAC_FW_APP_CONFIG *pFwAppCfg);

#ifdef __cplusplus
}
#endif /* EMAC_FW_CONFIG_DUAL_MAC_H_ */

#endif

