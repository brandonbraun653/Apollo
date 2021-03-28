/*
*  TEXAS INSTRUMENTS TEXT FILE LICENSE
* 
*   Copyright (c) 2019 Texas Instruments Incorporated
* 
*  All rights reserved not granted herein.
*  
*  Limited License.  
* 
*  Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive 
*  license under copyrights and patents it now or hereafter owns or controls to 
*  make, have made, use, import, offer to sell and sell ("Utilize") this software 
*  subject to the terms herein.  With respect to the foregoing patent license, 
*  such license is granted  solely to the extent that any such patent is necessary 
*  to Utilize the software alone.  The patent license shall not apply to any 
*  combinations which include this software, other than combinations with devices 
*  manufactured by or for TI (“TI Devices”).  No hardware patent is licensed hereunder.
* 
*  Redistributions must preserve existing copyright notices and reproduce this license 
*  (including the above copyright notice and the disclaimer and (if applicable) source 
*  code license limitations below) in the documentation and/or other materials provided 
*  with the distribution.
*  
*  Redistribution and use in binary form, without modification, are permitted provided 
*  that the following conditions are met:
* 	No reverse engineering, decompilation, or disassembly of this software is 
*   permitted with respect to any software provided in binary form.
* 	Any redistribution and use are licensed by TI for use only with TI Devices.
* 	Nothing shall obligate TI to provide you with source code for the software 
*   licensed and provided to you in object code.
*  
*  If software source code is provided to you, modification and redistribution of the 
*  source code are permitted provided that the following conditions are met:
* 	Any redistribution and use of the source code, including any resulting derivative 
*   works, are licensed by TI for use only with TI Devices.
* 	Any redistribution and use of any object code compiled from the source code
*   and any resulting derivative works, are licensed by TI for use only with TI Devices.
* 
*  Neither the name of Texas Instruments Incorporated nor the names of its suppliers 
*  may be used to endorse or promote products derived from this software without 
*  specific prior written permission.
* 
*  DISCLAIMER.
* 
*  THIS SOFTWARE IS PROVIDED BY TI AND TI’S LICENSORS "AS IS" AND ANY EXPRESS OR IMPLIED 
*  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
*  AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL TI AND TI’S 
*  LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
*  GOODS OR SERVICES* LOSS OF USE, DATA, OR PROFITS* OR BUSINESS INTERRUPTION) HOWEVER 
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
*  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/ 

/**
 * @file emac_fw_config_switch.c
 * @brief EMAC firmware configuration file which contain initializtion values for
 *          static configuration parameters for ICSSG Firmware.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <ti/csl/cslr_icss.h>
#include <ti/drv/emac/src/v5/emac_drv_v5.h>
#include <ti/drv/emac/firmware/icss_switch/config/emac_fw_config_switch.h>

EMAC_ICSSG_SWITCH_FW_CFG emac_switch_cfg = {
    EMAC_ICSSG_SWITCH_PORT_QUEUE_CONTEXT_OFFSET,
    EMAC_ICSSG_SWITCH_PORT_DESC_QUEUE_CONTEXT_OFFSET,
    {
        NRT_PORT_QUEUE_SIZE,NRT_PORT_QUEUE_SIZE,NRT_PORT_QUEUE_SIZE,NRT_PORT_QUEUE_SIZE,NRT_PORT_QUEUE_SIZE,NRT_PORT_QUEUE_SIZE,NRT_PORT_QUEUE_SIZE,NRT_PORT_QUEUE_SIZE
    },
    {
        NRT_HOST_QUEUE_SIZE,NRT_HOST_QUEUE_SIZE,NRT_HOST_QUEUE_SIZE,NRT_HOST_QUEUE_SIZE,NRT_HOST_QUEUE_SIZE,NRT_HOST_QUEUE_SIZE,NRT_HOST_QUEUE_SIZE,NRT_HOST_QUEUE_SIZE
    },
    PORT_DESC_Q0_OFFSET,
    MTU_SIZE,
    EMAC_ICSSG_SWITCH_DEFAULT_VLAN_TABLE_OFFSET,
    EMAC_ICSSG_SWITCH_PSI_L_REGULAR_FLOW_ID_BASE_OFFSET,
    EMAC_ICSSG_SWITCH_PSI_L_MGMT_FLOW_ID_BASE_OFFSET,
    EMAC_ICSSG_SWITCH_PORT0_DEFAULT_VLAN_OFFSET,
    EMAC_ICSSG_SWITCH_PORT1_DEFAULT_VLAN_OFFSET,
    EMAC_ICSSG_SWITCH_PORT2_DEFAULT_VLAN_OFFSET,
    EMAC_ICSSG_SWITCH_PORT_QUEUE_READ_PTR_OFFSET,
    PORT_Q_PRIORITY_REGEN_OFFSET,
    NRT_PORT_DESC_QUEUE_SIZE,
    NRT_HOST_DESC_QUEUE_SIZE,
    EXPRESS_PRE_EMPTIVE_Q_MAP,
    SPL_PKT_DEFAULT_PRIORITY,
    FDB_AGEING_TIMEOUT_OFFSET,
    PRE_EMPTION_ENABLE_TX, //placeholder for premptionTxEnabledStatusOffset
    PRE_EMPTION_ACTIVE_TX, //placeholder for premptionTxActiveStatusOffset
    PRE_EMPTION_ENABLE_VERIFY, //placeholder for premptionVerifyStateStatusOffset
    PRE_EMPTION_VERIFY_STATUS, //placeholder for premptionVerifyStateValueOffset
    PRE_EMPTION_ADD_FRAG_SIZE_LOCAL, //placeholder for premptionMinFragSizeOffset
    PRE_EMPTION_ADD_FRAG_SIZE_REMOTE, //placeholder for premptionMinFragAddOffset
    DEFAULT_FDB_AGEING_INTERVAL, // Default ageing timeout value
    NUMBER_OF_FDB_BUCKET_ENTRIES, // Number of entries in FDB bucket
    SIZE_OF_FDB, // FDB size
    PORT_Q_PRIORITY_MAPPING_OFFSET, //Port Priority Mapping offset
    P1_QUEUE_NUM_UNTAGGED, // Untagged packet default Queue num offset Port1
    P2_QUEUE_NUM_UNTAGGED  // Untagged packet default Queue num offset Port1
};


EMAC_PER_PORT_ICSSG_FW_CFG emacFwCfgMmapSwitch[EMAC_MAX_ICSS*2] = {
    {
        {0,0},
        (struct EMAC_FW_PORT_CFG*)&emac_switch_cfg,
    },
    {
        {0,0},
        (struct EMAC_FW_PORT_CFG*)&emac_switch_cfg,
    },
    {
        {0,0},
        (struct EMAC_FW_PORT_CFG*)&emac_switch_cfg,
    },    
    {
        {0,0},
        (struct EMAC_FW_PORT_CFG*)&emac_switch_cfg,
    },
    {
        {0,0},
        (struct EMAC_FW_PORT_CFG*)&emac_switch_cfg,
    },
    {
        {0,0},
        (struct EMAC_FW_PORT_CFG*)&emac_switch_cfg,
    }
};

/**
 * \brief Gets the EMAC  switch firmware configuration
 *
 *  @param[in]  port_num      port number
 *  @param[in]  pFwCfg  Address of pointer to be set to firmware configuration structure
 *
 * \return 0 success: -1: error
 *
 */
int32_t emacGetSwitchFwConfig(uint32_t portNum, EMAC_PER_PORT_ICSSG_FW_CFG **pFwCfg)
{
    int32_t ret = -1;
    if ((pFwCfg != NULL) && (portNum < (EMAC_MAX_ICSS*2)))
    {
        *pFwCfg = &(emacFwCfgMmapSwitch[portNum]);
        ret = 0;
    }
    return ret;
}

/**
 * \brief Sets the EMAC switch firmware configuration
 *
 *  @param[in]  port_num      port number
 *  @param[in]  pFwCfg  Pointer to  firmware configuration to be set
 *
 * \return 0 success: -1: error
 */
int32_t emacSetSwitchFwConfig(uint32_t portNum, const EMAC_PER_PORT_ICSSG_FW_CFG *pFwCfg)
{
    int32_t ret = -1;
    if ((pFwCfg != NULL) && (portNum < (EMAC_MAX_ICSS*2)))
    {
        memcpy(&(emacFwCfgMmapSwitch[portNum]),pFwCfg, sizeof(EMAC_PER_PORT_ICSSG_FW_CFG));
        ret = 0;
    }
    return ret;
}


/**
 * \brief Gets the application provided EMAC switch firmware configuration
 *
 *  @param[in]  port_num      port number
 *  @param[in]  pFwCfg  Address of pointer to be set to application provided firmware configuration structure
 *
 * \return 0 success: -1: error
 *
 */
int32_t emacGetSwitchFwAppInitCfg(uint32_t portNum, EMAC_FW_APP_CONFIG **pFwAppCfg)
{
    int32_t ret = -1;
    if ((pFwAppCfg != NULL) && (portNum < (EMAC_MAX_ICSS*2)))
    {
        *pFwAppCfg =&(emacFwCfgMmapSwitch[portNum].fwAppCfg);
        ret = 0;
    }
    return ret;
}

/**
 * \brief Sets the application provided EMAC dual mac firmware configuration
 *
 *  @param[in]  port_num      port number
 *  @param[in]  pFwCfg  Pointer to  application provided firmware configuration to be set
 *
 * \return 0 success: -1: error
 *
 */
int32_t emacSetSwitchFwAppInitCfg(uint32_t portNum, EMAC_FW_APP_CONFIG *pFwAppCfg)
{
    int32_t ret = -1;

     if ((pFwAppCfg != NULL) && (portNum < (EMAC_MAX_ICSS*2)))
     {
          emacFwCfgMmapSwitch[portNum].fwAppCfg.txPortQueueHighAddr = pFwAppCfg->txPortQueueHighAddr;
          emacFwCfgMmapSwitch[portNum].fwAppCfg.txPortQueueLowAddr = pFwAppCfg->txPortQueueLowAddr;
          emacFwCfgMmapSwitch[portNum].fwAppCfg.txPortQueueSize = pFwAppCfg->txPortQueueSize;
          return 0;
     }
     return ret;
}

