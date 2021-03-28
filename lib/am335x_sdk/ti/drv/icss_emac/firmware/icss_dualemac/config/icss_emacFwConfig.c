/*
*  TEXAS INSTRUMENTS TEXT FILE LICENSE
* 
*   Copyright (c) 2017-2018 Texas Instruments Incorporated
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
 * @file icss_emacFwConfig.c
 * @brief ICSS-EMAC firmware configuration file which contain initializtion values for
 *          static configuration parameters (read only) and dynamic configuration
 *          parameters (read/write)
 *
 */


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>


#include <ti/drv/icss_emac/firmware/icss_dualemac/config/icss_emacFwConfig.h>


ICSS_EmacFwStaticMmap icss_emacFwStaticCfg[2] = {
{
    ICSS_EMAC_FW_RELEASE_1_OFFSET,
    ICSS_EMAC_FW_RELEASE_2_OFFSET,
    ICSS_EMAC_FW_FEATURE_OFFSET,
    ICSS_EMAC_FW_RESERVED_FEATURE_OFFSET,
    ICSS_EMAC_FW_STATISTICS_OFFSET,
    ICSS_EMAC_FW_STAT_SIZE,
    ICSS_EMAC_FW_STORM_PREVENTION_OFFSET,
    ICSS_EMAC_FW_PHY_SPEED_OFFSET,
    ICSS_EMAC_FW_PORT_STATUS_OFFSET,
    ICSS_EMAC_FW_PORT_CONTROL_ADDR ,
    ICSS_EMAC_FW_PORT_MAC_ADDR,
    ICSS_EMAC_FW_RX_INT_STATUS_OFFSET,
    ICSS_EMAC_FW_STORM_PREVENTION_OFFSET_MC,
    ICSS_EMAC_FW_STORM_PREVENTION_OFFSET_UC,
    ICSS_EMAC_FW_P0_QUEUE_DESC_OFFSET ,
    ICSS_EMAC_FW_P0_COL_QUEUE_DESC_OFFSET,
    ICSS_EMAC_FW_TTS_BASE_OFFSET,
    ICSS_EMAC_FW_INTERFACE_MAC_ADDR_OFFSET,
    ICSS_EMAC_FW_COLLISION_STATUS_ADDR,
    ICSS_EMAC_FW_PROMISCUOUS_MODE_OFFSET
},
{
    ICSS_EMAC_FW_RELEASE_1_OFFSET ,
    ICSS_EMAC_FW_RELEASE_2_OFFSET,
    ICSS_EMAC_FW_FEATURE_OFFSET,
    ICSS_EMAC_FW_RESERVED_FEATURE_OFFSET,
    ICSS_EMAC_FW_STATISTICS_OFFSET,
    ICSS_EMAC_FW_STAT_SIZE,
    ICSS_EMAC_FW_STORM_PREVENTION_OFFSET,
    ICSS_EMAC_FW_PHY_SPEED_OFFSET,
    ICSS_EMAC_FW_PORT_STATUS_OFFSET,
    ICSS_EMAC_FW_PORT_CONTROL_ADDR ,
    ICSS_EMAC_FW_PORT_MAC_ADDR,
    ICSS_EMAC_FW_RX_INT_STATUS_OFFSET,
    ICSS_EMAC_FW_STORM_PREVENTION_OFFSET_MC,
    ICSS_EMAC_FW_STORM_PREVENTION_OFFSET_UC,
    ICSS_EMAC_FW_P0_QUEUE_DESC_OFFSET ,
    ICSS_EMAC_FW_P0_COL_QUEUE_DESC_OFFSET,
    ICSS_EMAC_FW_TTS_BASE_OFFSET,
    ICSS_EMAC_FW_INTERFACE_MAC_ADDR_OFFSET,
    ICSS_EMAC_FW_COLLISION_STATUS_ADDR,
    ICSS_EMAC_FW_PROMISCUOUS_MODE_OFFSET
}
};

ICSS_EmacFwDynamicMmap icss_emacFwDynamicCfg = {
    {ICSS_EMAC_FW_QUEUE_1_SIZE, ICSS_EMAC_FW_QUEUE_2_SIZE, ICSS_EMAC_FW_QUEUE_3_SIZE, ICSS_EMAC_FW_QUEUE_4_SIZE,
     ICSS_EMAC_FW_QUEUE_5_SIZE, ICSS_EMAC_FW_QUEUE_6_SIZE, ICSS_EMAC_FW_QUEUE_7_SIZE, ICSS_EMAC_FW_QUEUE_8_SIZE,
     ICSS_EMAC_FW_QUEUE_9_SIZE, ICSS_EMAC_FW_QUEUE_10_SIZE, ICSS_EMAC_FW_QUEUE_11_SIZE, ICSS_EMAC_FW_QUEUE_12_SIZE,
     ICSS_EMAC_FW_QUEUE_13_SIZE, ICSS_EMAC_FW_QUEUE_14_SIZE, ICSS_EMAC_FW_QUEUE_15_SIZE, ICSS_EMAC_FW_QUEUE_16_SIZE},
    {ICSS_EMAC_FW_HOST_QUEUE_1_SIZE, ICSS_EMAC_FW_HOST_QUEUE_2_SIZE, ICSS_EMAC_FW_HOST_QUEUE_3_SIZE, ICSS_EMAC_FW_HOST_QUEUE_4_SIZE,
     ICSS_EMAC_FW_HOST_QUEUE_5_SIZE, ICSS_EMAC_FW_HOST_QUEUE_6_SIZE, ICSS_EMAC_FW_HOST_QUEUE_7_SIZE, ICSS_EMAC_FW_HOST_QUEUE_8_SIZE,
     ICSS_EMAC_FW_HOST_QUEUE_9_SIZE, ICSS_EMAC_FW_HOST_QUEUE_10_SIZE, ICSS_EMAC_FW_HOST_QUEUE_11_SIZE, ICSS_EMAC_FW_HOST_QUEUE_12_SIZE,
     ICSS_EMAC_FW_HOST_QUEUE_13_SIZE, ICSS_EMAC_FW_HOST_QUEUE_14_SIZE, ICSS_EMAC_FW_HOST_QUEUE_15_SIZE, ICSS_EMAC_FW_HOST_QUEUE_16_SIZE},
    ICSS_EMAC_FW_COLLISION_QUEUE_SIZE,
    ICSS_EMAC_FW_P0_BUFFER_DESC_OFFSET,
    ICSS_EMAC_FW_P0_COL_BD_OFFSET ,
    ICSS_EMAC_FW_HOST_P0_Q1_BUFFER_OFFSET,
    ICSS_EMAC_FW_TX_QUEUES_BUFFER_OFFSET,
    ICSS_EMAC_FW_P0_COL_BUFFER_OFFSET,
    ICSS_EMAC_FW_HOST_Q1_RX_CONTEXT_OFFSET,
    ICSS_EMAC_FW_SWITCH_P1_Q1_TX_CONTEXT_OFFSET,
    ICSS_EMAC_FW_PORT_QUEUE_DESC_OFFSET,
    ICSS_EMAC_FW_EMAC_Q1_TX_CONTEXT_OFFSET,
    ICSS_EMAC_NUMBER_OF_QUEUES
};

/**
 * \brief  This API gets the ICSS-EMAC  firmware Memory Map intial configuration
 *
 *  @param[in]  instance      PRU-ICSS instance
 *  @param[in]  ppStaticMMap  Address of pointer to be set to static MMap configuration structure.
 *  @param[in]  ppDynamicMMap Address of pointer to be set to dynamic MMap configuration structure.
 *
 * \return 0 success: -1: error
 *
 */
int32_t icss_emacGetFwMMapInitConfig(uint32_t instance, ICSS_EmacFwStaticMmap **ppStaticMMap, ICSS_EmacFwDynamicMmap **ppDynamicMMap)
{
    int32_t ret = 0;
    if ((ppStaticMMap == NULL) || (ppDynamicMMap == NULL))
    {
        ret = -1;
    }
    else if (instance < 2U)
   {
        *ppStaticMMap = &(icss_emacFwStaticCfg[instance]);
        *ppDynamicMMap = &(icss_emacFwDynamicCfg);
    }
    else
    {
        ret = -1;
    }
    return ret;
}




/**
 * \brief  This API sets the ICSS-EMAC firmware Memory Map intial configuration, this API MUST be
 *         called prior to calling ICSS_EmacInit()
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance
 *  @param[in]  instance     PRU-ICSS instance
 *  @param[in]  staticCfg       Pointer to ICSS-EMAC firmware Memory Map initial static config.
 *  @param[in]  dynamicCfg       Pointer to ICSS-EMAC firmware Memory Map initial dynamic config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t icss_emacSetFwMMapInitConfig(ICSS_EmacHandle icssEmacHandle, uint32_t instance, ICSS_EmacFwStaticMmap *staticCfg, ICSS_EmacFwDynamicMmap *dynamicCfg)
{
    int32_t ret = 0;
    ICSS_EmacFwStaticMmap *pStaticMMap;
    ICSS_EmacFwDynamicMmap *pDynamicMMap;
    if ((dynamicCfg == NULL) || (staticCfg == NULL))
    {
        ret = -1;
    }
    else
    {
        icss_emacFwDynamicCfg = *dynamicCfg;
        icss_emacFwStaticCfg[instance] = *staticCfg;

        /* Update LLD with configuration set */
        pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);
        memcpy(pStaticMMap, &(icss_emacFwStaticCfg[instance]), sizeof(ICSS_EmacFwStaticMmap));
        pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);
        memcpy(pDynamicMMap, &icss_emacFwDynamicCfg, sizeof(ICSS_EmacFwDynamicMmap));

        /* Indicates to the LLD that firmware memory map configuration is complete */
        ((ICSS_EmacObject*)icssEmacHandle->object)->fwMmapInitDone = ICSS_EMAC_FW_MMAP_INIT_DONE;
    }
    return ret;
}



