/*
*  TEXAS INSTRUMENTS TEXT FILE LICENSE
* 
*   Copyright (c) 2018 Texas Instruments Incorporated
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
 * @file emac_fw_config.c
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
#include <ti/drv/emac/firmware/icss_switch/config/emac_fw_config.h>

EMAC_TX_QUEUE_CONTEXT host_tx_q_msmc_context[EMAC_NUM_TRANSMIT_FW_QUEUES];
EMAC_TX_QUEUE_CONTEXT port_tx_q_msmc_context[EMAC_NUM_TRANSMIT_FW_QUEUES];

EMAC_TX_QUEUE_CONTEXT host_tx_q_desc_context[EMAC_NUM_TRANSMIT_FW_QUEUES];
EMAC_TX_QUEUE_CONTEXT port_tx_q_desc_context[EMAC_NUM_TRANSMIT_FW_QUEUES];


EMAC_FW_STATIC_MMAP emacFwCfgMmap[EMAC_MAX_ICSS*2] = {
    {
        {0,0},
        PORT_QUEUE_CONTEXT_OFFSET,
        {
            EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE
        },
        {
            EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE
        },
        EMAC_ICSSG_SWITCH_FW_MTU_SIZE
    },
    {
                {0,0},

        PORT_QUEUE_CONTEXT_OFFSET,
        {
            EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE
        },
        {
            EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE
        },
        EMAC_ICSSG_SWITCH_FW_MTU_SIZE
    },
    {
                {0,0},

        PORT_QUEUE_CONTEXT_OFFSET,
        {
            EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE
        },
        {
            EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE
        },
        EMAC_ICSSG_SWITCH_FW_MTU_SIZE
    },    
    {
        {0,0},
        PORT_QUEUE_CONTEXT_OFFSET,
        {
            EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE
        },
        {
            EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE
        },
        EMAC_ICSSG_SWITCH_FW_MTU_SIZE
    },
    {
                {0,0},

        PORT_QUEUE_CONTEXT_OFFSET,
        {
            EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE
        },
        {
            EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE
        },
        EMAC_ICSSG_SWITCH_FW_MTU_SIZE
    },
    {
                {0,0},

        PORT_QUEUE_CONTEXT_OFFSET,
        {
            EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_PORT_QUEUE_SIZE
        },
        {
            EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE,EMAC_ICSSG_SWITCH_FW_HOST_QUEUE_SIZE
        },
        EMAC_ICSSG_SWITCH_FW_MTU_SIZE
    }
};

int32_t emacGetFwAppInitCfg(uint32_t portNum, EMAC_FW_APP_CONFIG *pFwAppCfg)
{
    int32_t ret = 0;
    if (pFwAppCfg == NULL)
    {
        ret = -1;
    }
    else if (portNum < (EMAC_MAX_ICSS*2))
   {
        *pFwAppCfg = (emacFwCfgMmap[portNum].fwAppCfg);
    }
    else
    {
        ret = -1;
    }
    return ret;
}

int32_t emacSetFwAppInitCfg(uint32_t portNum, EMAC_FW_APP_CONFIG *pFwAppCfg)
{
    int32_t ret = 0;

     if (pFwAppCfg == NULL)
     {
         ret = -1;
     }
     else if (portNum < (EMAC_MAX_ICSS*2))
    {
          emacFwCfgMmap[portNum].fwAppCfg.txPortQueueHighAddr = pFwAppCfg->txPortQueueHighAddr;
          emacFwCfgMmap[portNum].fwAppCfg.txPortQueueLowAddr = pFwAppCfg->txPortQueueLowAddr;
     }
     else
     {
         ret = -1;
     }
     return ret;
}


int32_t emacGetFwMMapInitConfig(uint32_t portNum, EMAC_FW_STATIC_MMAP *pStaticMMap)
{
    int32_t ret = 0;
    if (pStaticMMap == NULL)
    {
        ret = -1;
    }
    else if (portNum < (EMAC_MAX_ICSS*2))
   {
        *pStaticMMap = emacFwCfgMmap[portNum];
    }
    else
    {
        ret = -1;
    }
    return ret;
}


int32_t emacSetFwMMapInitConfig(uint32_t portNum, const EMAC_FW_STATIC_MMAP *pStaticCfg)
{
    int32_t ret = 0;
    if (pStaticCfg == NULL)
    {
        ret = -1;
    }
    else
    {
        emacFwCfgMmap[portNum] = *pStaticCfg;
    }
    return ret;
}



