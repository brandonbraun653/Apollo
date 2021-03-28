/**
 * @file   emac_fw_config_switch.h
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



#ifndef EMAC_FW_CONFIG_SWITCH_H_
#define EMAC_FW_CONFIG_SWITCH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/drv/emac/src/v5/emac_drv_v5.h>
#include <ti/drv/emac/firmware/icss_switch/bin/switch_mem_map.h>

extern int32_t emacGetSwitchFwConfig(uint32_t portNum, EMAC_PER_PORT_ICSSG_FW_CFG **pStaticMMap);
extern int32_t emacSetSwitchFwConfig(uint32_t portNum, const EMAC_PER_PORT_ICSSG_FW_CFG *pStaticCfg);
extern int32_t emacSetSwitchFwAppInitCfg(uint32_t portNum, EMAC_FW_APP_CONFIG *pFwAppCfg);
extern int32_t emacGetSwitchFwAppInitCfg(uint32_t portNum, EMAC_FW_APP_CONFIG **pFwAppCfg);


/* Size required for configurtion of port queues */
#define NRT_TX_Q_SIZE                           ((NRT_NUM_PORT_QUEUES * (NRT_PORT_QUEUE_SIZE + NRT_RESERVED_MEM)) + (NRT_NUM_HOST_QUEUES * (NRT_HOST_QUEUE_SIZE + NRT_RESERVED_MEM)) + (NRT_NUM_HOST_EGRESS_QUEUES * (NRT_PORT_QUEUE_SIZE + NRT_RESERVED_MEM)) + NRT_RESERVED_MEM)
#define EMAC_TOTAL_PORT_QUEUE_SIZE (((NRT_TX_Q_SIZE)>>1) + 0x3F) & 0xFFFFFFC0



#ifdef __cplusplus
}
#endif /* EMAC_FW_CONFIG_SWITCH_H_ */

#endif

