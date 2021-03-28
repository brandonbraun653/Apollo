/**
 * @file icss_emacLoc.c
 * @brief Contains local functions used the the driver 
 *
 */

/* Copyright (C) {2016} Texas Instruments Incorporated - http://www.ti.com/ 
*
*   Redistribution and use in source and binary forms, with or without 
*   modification, are permitted provided that the following conditions 
*   are met:
*
*     Redistributions of source code must retain the above copyright 
*     notice, this list of conditions and the following disclaimer.
*
*     Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the 
*     documentation and/or other materials provided with the   
*     distribution.
*
*     Neither the name of Texas Instruments Incorporated nor the names of
*     its contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/



/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>


#include <ti/drv/icss_emac/icss_emacDrv.h>
#include <ti/drv/icss_emac/src/icss_emacLoc.h>



ICSS_EmacFwStaticMmap icss_emacFwStaticCfgLocal[2] = {
{
    ICSS_EMAC_DEFAULT_FW_RELEASE_1_OFFSET ,
    ICSS_EMAC_DEFAULT_FW_RELEASE_2_OFFSET ,
    ICSS_EMAC_DEFAULT_FW_FEATURE_OFFSET,
    ICSS_EMAC_DEFAULT_FW_RESERVED_FEATURE_OFFSET,
    ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET,
    ICSS_EMAC_DEFAULT_FW_STAT_SIZE,
    ICSS_EMAC_DEFAULT_FW_STORM_PREVENTION_OFFSET,
    ICSS_EMAC_DEFAULT_FW_PHY_SPEED_OFFSET,
    ICSS_EMAC_DEFAULT_FW_PORT_STATUS_OFFSET,
    ICSS_EMAC_DEFAULT_FW_PORT_CONTROL_ADDR ,
    ICSS_EMAC_DEFAULT_FW_PORT_MAC_ADDR,
    ICSS_EMAC_DEFAULT_FW_RX_INT_STATUS_OFFSET,
    ICSS_EMAC_DEFAULT_FW_STORM_PREVENTION_OFFSET_MC,
    ICSS_EMAC_DEFAULT_FW_STORM_PREVENTION_OFFSET_UC,
    ICSS_EMAC_DEFAULT_FW_P0_QUEUE_DESC_OFFSET ,
    ICSS_EMAC_DEFAULT_FW_P0_COL_QUEUE_DESC_OFFSET,
    ICSS_EMAC_DEFAULT_FW_TTS_BASE_OFFSET,
    ICSS_EMAC_DEFAULT_FW_INTERFACE_MAC_ADDR_OFFSET,
    ICSS_EMAC_DEFAULT_FW_COLLISION_STATUS_ADDR,
    ICSS_EMAC_DEFAULT_FW_PROMISCUOUS_MODE_OFFSET
},
{
    ICSS_EMAC_DEFAULT_FW_RELEASE_1_OFFSET ,
    ICSS_EMAC_DEFAULT_FW_RELEASE_2_OFFSET ,
    ICSS_EMAC_DEFAULT_FW_FEATURE_OFFSET,
    ICSS_EMAC_DEFAULT_FW_RESERVED_FEATURE_OFFSET,
    ICSS_EMAC_DEFAULT_FW_STATISTICS_OFFSET,
    ICSS_EMAC_DEFAULT_FW_STAT_SIZE,
    ICSS_EMAC_DEFAULT_FW_STORM_PREVENTION_OFFSET,
    ICSS_EMAC_DEFAULT_FW_PHY_SPEED_OFFSET,
    ICSS_EMAC_DEFAULT_FW_PORT_STATUS_OFFSET,
    ICSS_EMAC_DEFAULT_FW_PORT_CONTROL_ADDR ,
    ICSS_EMAC_DEFAULT_FW_PORT_MAC_ADDR,
    ICSS_EMAC_DEFAULT_FW_RX_INT_STATUS_OFFSET,
    ICSS_EMAC_DEFAULT_FW_STORM_PREVENTION_OFFSET_MC,
    ICSS_EMAC_DEFAULT_FW_STORM_PREVENTION_OFFSET_UC,
    ICSS_EMAC_DEFAULT_FW_P0_QUEUE_DESC_OFFSET ,
    ICSS_EMAC_DEFAULT_FW_P0_COL_QUEUE_DESC_OFFSET,
    ICSS_EMAC_DEFAULT_FW_TTS_BASE_OFFSET,
    ICSS_EMAC_DEFAULT_FW_INTERFACE_MAC_ADDR_OFFSET,
    ICSS_EMAC_DEFAULT_FW_COLLISION_STATUS_ADDR,
    ICSS_EMAC_DEFAULT_FW_PROMISCUOUS_MODE_OFFSET
}
};

ICSS_EmacFwDynamicMmap icss_emacFwDynamicCfgLocal = {
    {ICSS_EMAC_DEFAULT_FW_QUEUE_1_SIZE, ICSS_EMAC_DEFAULT_FW_QUEUE_2_SIZE, ICSS_EMAC_DEFAULT_FW_QUEUE_3_SIZE, ICSS_EMAC_DEFAULT_FW_QUEUE_4_SIZE,
    ICSS_EMAC_DEFAULT_FW_QUEUE_5_SIZE, ICSS_EMAC_DEFAULT_FW_QUEUE_6_SIZE, ICSS_EMAC_DEFAULT_FW_QUEUE_7_SIZE, ICSS_EMAC_DEFAULT_FW_QUEUE_8_SIZE,
    ICSS_EMAC_DEFAULT_FW_QUEUE_9_SIZE, ICSS_EMAC_DEFAULT_FW_QUEUE_10_SIZE, ICSS_EMAC_DEFAULT_FW_QUEUE_11_SIZE, ICSS_EMAC_DEFAULT_FW_QUEUE_12_SIZE,
    ICSS_EMAC_DEFAULT_FW_QUEUE_13_SIZE, ICSS_EMAC_DEFAULT_FW_QUEUE_14_SIZE, ICSS_EMAC_DEFAULT_FW_QUEUE_15_SIZE, ICSS_EMAC_DEFAULT_FW_QUEUE_16_SIZE},
    {ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_1_SIZE, ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_2_SIZE, ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_3_SIZE, ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_4_SIZE,
    ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_5_SIZE, ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_6_SIZE,ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_7_SIZE, ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_8_SIZE,
    ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_9_SIZE, ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_10_SIZE,ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_11_SIZE, ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_12_SIZE,
    ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_13_SIZE, ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_14_SIZE,ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_15_SIZE, ICSS_EMAC_DEFAULT_FW_HOST_QUEUE_16_SIZE},
    ICSS_EMAC_DEFAULT_FW_COLLISION_QUEUE_SIZE,
    ICSS_EMAC_DEFAULT_FW_P0_BUFFER_DESC_OFFSET,
    ICSS_EMAC_DEFAULT_FW_P0_COL_BD_OFFSET ,
    ICSS_EMAC_DEFAULT_FW_HOST_P0_Q1_BUFFER_OFFSET,
    ICSS_EMAC_DEFAULT_FW_TX_QUEUES_BUFFER_OFFSET,
    ICSS_EMAC_DEFAULT_FW_P0_COL_BUFFER_OFFSET,
    ICSS_EMAC_DEFAULT_FW_HOST_Q1_RX_CONTEXT_OFFSET,
    ICSS_EMAC_DEFAULT_FW_SWITCH_P1_Q1_TX_CONTEXT_OFFSET,
    ICSS_EMAC_DEFAULT_FW_PORT_QUEUE_DESC_OFFSET,
    ICSS_EMAC_DEFAULT_FW_EMAC_Q1_TX_CONTEXT_OFFSET,
    ICSS_EMAC_DEFAULT_NUMBER_OF_QUEUES
};



/**
 * \brief  This API gets the ICSS-EMAC  firmware Memory Map intial configuration
 *
 *  @param[in]  icssEmacHandle handle to ICSS_EMAC Instance
 *  @param[in]  instance     PRU-ICSS instance
 *  @param[in]  staticCfg       Pointer to ICSS-EMAC firmware Memory Map initial static config.
 *  @param[in]  dynamicCfg       Pointer to ICSS-EMAC firmware Memory Map initial dynamic config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t ICSS_EmacGetFwMMapInitConfigLocal(ICSS_EmacHandle icssEmacHandle, uint32_t instance)
{

     ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);
     ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);
     *pStaticMMap =  icss_emacFwStaticCfgLocal[instance];
     *pDynamicMMap = icss_emacFwDynamicCfgLocal;
    ((ICSS_EmacObject*)icssEmacHandle->object)->fwMmapInitDone = ICSS_EMAC_DEFAULT_FW_MMAP_INIT_DONE;
    return 0;
}


void ICSS_EmacCalcPort0BufferOffset(ICSS_EmacHandle icssEmacHandle, uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES], uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES])
{
    uint32_t qCount = 1U;
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);

     bufferOffsets[ICSS_EMAC_QUEUE1] = pDynamicMMap->p0Q1BufferOffset;
    for (qCount = 1U; qCount < pDynamicMMap->numQueues; qCount++)
    {
        bufferOffsets[qCount] = bufferOffsets[qCount-1U] + pDynamicMMap->rxHostQueueSize[qCount-1U] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    }
    bufferOffsets[ICSS_EMAC_COLQUEUE] = pDynamicMMap->p0ColBufferOffset;

    bdOffsets[ICSS_EMAC_QUEUE1] = pDynamicMMap->p0Q1BufferDescOffset;
    for (qCount = 1U; qCount < pDynamicMMap->numQueues; qCount++)
    {
        bdOffsets[qCount] = bdOffsets[qCount-1U] + pDynamicMMap->rxHostQueueSize[qCount - 1U] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    }
    bdOffsets[ICSS_EMAC_COLQUEUE] = pDynamicMMap->p0ColBufferDescOffset;
}
void ICSS_EmacCalcPort1BufferOffset(ICSS_EmacHandle icssEmacHandle, uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES], uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES])
{
    uint32_t qCount = 0U;
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);


    /* required to calcualate base of p1Q1BufferOffset which starts at the end of p0Q8BufferOffset*/
    uint32_t p0Q1BufferOffset = pDynamicMMap->p0Q1BufferOffset;
    uint32_t p0Q2BufferOffset = p0Q1BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE1] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q3BufferOffset = p0Q2BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE2] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q4BufferOffset = p0Q3BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE3] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q5BufferOffset = p0Q4BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE4] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q6BufferOffset = p0Q5BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE5] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q7BufferOffset = p0Q6BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE6] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q8BufferOffset = p0Q7BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE7] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;

    uint32_t p0Q9BufferOffset = p0Q8BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE8] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q10BufferOffset = p0Q9BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE9] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q11BufferOffset = p0Q10BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE10] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q12BufferOffset = p0Q11BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE11] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q13BufferOffset = p0Q12BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE12] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q14BufferOffset = p0Q13BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE13] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q15BufferOffset = p0Q14BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE14] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q16BufferOffset = p0Q15BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE15] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;


    bufferOffsets[ICSS_EMAC_QUEUE1] = p0Q16BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE16] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;

    for (qCount = (ICSS_EMAC_QUEUE1+1U); qCount < pDynamicMMap->numQueues; qCount++)
    {
        bufferOffsets[qCount] = bufferOffsets[qCount-1U] + pDynamicMMap->txQueueSize[qCount-1U] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    }

    bufferOffsets[ICSS_EMAC_COLQUEUE] = pDynamicMMap->p0ColBufferOffset + 1536U;

    /* required to calcualate base of p1Q1BdOffset which starts at the end of  p0Q8BdOffset */
    uint32_t p0Q1BdOffset = pDynamicMMap->p0Q1BufferDescOffset;
    uint32_t p0Q2BdOffset = p0Q1BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE1] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q3BdOffset = p0Q2BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE2] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q4BdOffset = p0Q3BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE3] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q5BdOffset = p0Q4BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE4] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q6BdOffset = p0Q5BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE5] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q7BdOffset = p0Q6BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE6] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q8BdOffset = p0Q7BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE7] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;

    uint32_t p0Q9BdOffset =   p0Q8BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE8] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q10BdOffset = p0Q9BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE9] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q11BdOffset = p0Q10BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE10] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q12BdOffset = p0Q11BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE11] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q13BdOffset = p0Q12BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE12] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q14BdOffset = p0Q13BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE13] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q15BdOffset = p0Q14BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE14] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q16BdOffset = p0Q15BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE15] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;

    bdOffsets[ICSS_EMAC_QUEUE1] =p0Q16BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE16] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;


    for (qCount = (ICSS_EMAC_QUEUE1+1U); qCount < pDynamicMMap->numQueues; qCount++)
    {
        bdOffsets[qCount] =  bdOffsets[qCount-1U] + pDynamicMMap->txQueueSize[qCount-1U] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    }

    bdOffsets[ICSS_EMAC_COLQUEUE] = pDynamicMMap->p0ColBufferDescOffset + ICSS_EMAC_DEFAULT_FW_BD_SIZE * 48U ;
}

void ICSS_EmacCalcPort2BufferOffset(ICSS_EmacHandle icssEmacHandle, uint32_t bufferOffsets[ICSS_EMAC_NUMQUEUES], uint32_t bdOffsets[ICSS_EMAC_NUMQUEUES])
{
    uint32_t qCount = 0U;
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);

    /* required to calcualate base of p1Q1BufferOffset which starts at the end of   p0Q8BufferOffset*/
    uint32_t p0Q1BufferOffset = pDynamicMMap->p0Q1BufferOffset;
    uint32_t p0Q2BufferOffset = p0Q1BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE1] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q3BufferOffset = p0Q2BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE2] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q4BufferOffset = p0Q3BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE3] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q5BufferOffset = p0Q4BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE4] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q6BufferOffset = p0Q5BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE5] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q7BufferOffset = p0Q6BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE6] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q8BufferOffset = p0Q7BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE7] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;

    uint32_t p0Q9BufferOffset = p0Q8BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE8] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q10BufferOffset = p0Q9BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE9] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q11BufferOffset = p0Q10BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE10] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q12BufferOffset = p0Q11BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE11] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q13BufferOffset = p0Q12BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE12] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q14BufferOffset = p0Q13BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE13] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q15BufferOffset = p0Q14BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE14] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p0Q16BufferOffset = p0Q15BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE15] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;



     
    /* required to calcualate base of p2Q1Offset which starts at the end of  p1Q8BufferOffset*/
    uint32_t p1Q1BufferOffset = p0Q16BufferOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE16] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q2BufferOffset = p1Q1BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE1] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q3BufferOffset = p1Q2BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE2] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q4BufferOffset = p1Q3BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE3] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q5BufferOffset = p1Q4BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE4] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q6BufferOffset = p1Q5BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE5] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q7BufferOffset = p1Q6BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE6] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q8BufferOffset = p1Q7BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE7] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;

    uint32_t p1Q9BufferOffset = p1Q8BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE8] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q10BufferOffset = p1Q9BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE9] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q11BufferOffset = p1Q10BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE10] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q12BufferOffset = p1Q11BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE11] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q13BufferOffset = p1Q12BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE12] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q14BufferOffset = p1Q13BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE13] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q15BufferOffset = p1Q14BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE14] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    uint32_t p1Q16BufferOffset = p1Q15BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE15] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;

    bufferOffsets[ICSS_EMAC_QUEUE1] = p1Q16BufferOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE16] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    for (qCount = (ICSS_EMAC_QUEUE1+1U); qCount < pDynamicMMap->numQueues; qCount++)
    {
        bufferOffsets[qCount] = bufferOffsets[qCount-1U] + pDynamicMMap->txQueueSize[qCount-1U] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    }

    bufferOffsets[ICSS_EMAC_COLQUEUE] = pDynamicMMap->p0ColBufferOffset + (1536U*2U);

    /* required to calcualate base of p2Q1BdOffset */
    uint32_t p0Q1BdOffset = pDynamicMMap->p0Q1BufferDescOffset;
    uint32_t p0Q2BdOffset = p0Q1BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE1] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q3BdOffset = p0Q2BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE2] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q4BdOffset = p0Q3BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE3] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q5BdOffset = p0Q4BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE4] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q6BdOffset = p0Q5BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE5] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q7BdOffset = p0Q6BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE6] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q8BdOffset = p0Q7BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE7] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;

    uint32_t p0Q9BdOffset = p0Q8BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE8] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q10BdOffset = p0Q9BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE9] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q11BdOffset = p0Q10BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE10] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q12BdOffset = p0Q11BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE11] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q13BdOffset = p0Q12BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE12] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q14BdOffset = p0Q13BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE13] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q15BdOffset = p0Q14BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE14] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p0Q16BdOffset = p0Q15BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE15] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;


    uint32_t p1Q1BdOffset = p0Q16BdOffset + pDynamicMMap->rxHostQueueSize[ICSS_EMAC_QUEUE16] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q2BdOffset = p1Q1BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE1] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q3BdOffset = p1Q2BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE2] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q4BdOffset = p1Q3BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE3] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q5BdOffset = p1Q4BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE4] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q6BdOffset = p1Q5BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE5] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q7BdOffset = p1Q6BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE6] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q8BdOffset = p1Q7BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE7] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;

    uint32_t p1Q9BdOffset = p1Q8BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE8] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q10BdOffset = p1Q9BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE9] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q11BdOffset = p1Q10BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE10] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q12BdOffset = p1Q11BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE11] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q13BdOffset = p1Q12BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE12] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q14BdOffset = p1Q13BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE13] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q15BdOffset = p1Q14BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE14] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    uint32_t p1Q16BdOffset = p1Q15BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE15] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;


    uint32_t p1ColBDOffset = pDynamicMMap->p0ColBufferDescOffset + ICSS_EMAC_DEFAULT_FW_BD_SIZE * 48U;

    bdOffsets[ICSS_EMAC_QUEUE1] = p1Q16BdOffset + pDynamicMMap->txQueueSize[ICSS_EMAC_QUEUE16] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    for (qCount = (ICSS_EMAC_QUEUE1+1U); qCount < pDynamicMMap->numQueues; qCount++)
    {
        bdOffsets[qCount] = bdOffsets[qCount-1U] + pDynamicMMap->txQueueSize[qCount-1U] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    }

    bdOffsets[ICSS_EMAC_COLQUEUE] = p1ColBDOffset + ICSS_EMAC_DEFAULT_FW_BD_SIZE * 48U;
}

uint32_t ICSS_EmacCalcEndOfBufferBD(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t qCount = 0U;
    uint32_t hostBDSize = 0U;
    uint32_t portBDSize = 0U;
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);

    for (qCount = 0U; qCount < pDynamicMMap->numQueues;qCount++)
    {
        hostBDSize += pDynamicMMap->rxHostQueueSize[qCount] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
        portBDSize  += pDynamicMMap->txQueueSize[qCount] * 2U * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    }

    return (pDynamicMMap->p0Q1BufferDescOffset + hostBDSize + portBDSize);
}


uint32_t ICSS_EmacCalcEndOfColBufferBD(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t eofBufferBD = ICSS_EmacCalcEndOfBufferBD(icssEmacHandle);
    uint32_t eofColBufferBD = eofBufferBD + (3U * ICSS_EMAC_DEFAULT_FW_BD_SIZE * 48U);
    return eofColBufferBD;
}

uint32_t  ICSS_EmacCalcTotalHostBDSize(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t qCount = 0U;
    uint32_t hostBDSize = 0U;
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);

    for (qCount = 0U; qCount < pDynamicMMap->numQueues;qCount++)
    {
        hostBDSize += pDynamicMMap->rxHostQueueSize[qCount] * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    }
    return hostBDSize;
}

uint32_t ICSS_EmacCalcTotalPortBDSize(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t qCount = 0U;
    uint32_t portBDSize = 0U;
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);

    for (qCount = 0U; qCount < pDynamicMMap->numQueues;qCount++)
    {
        portBDSize += pDynamicMMap->txQueueSize[qCount] * 2U * ICSS_EMAC_DEFAULT_FW_BD_SIZE;
    }
    return portBDSize;
}

uint32_t ICSS_EmacCalcTotalBufferPoolSize(ICSS_EmacHandle icssEmacHandle)
{
    uint32_t qCount = 0U;
    uint32_t hostBufferPoolSize = 0U;
    uint32_t txPortBufferPoolSize = 0U;
    ICSS_EmacFwDynamicMmap *pDynamicMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwDynamicMMap);

    for (qCount = 0U; qCount < pDynamicMMap->numQueues;qCount++)
    {
        hostBufferPoolSize += pDynamicMMap->rxHostQueueSize[qCount] * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
        hostBufferPoolSize  += pDynamicMMap->txQueueSize[qCount] * 2U * ICSS_EMAC_DEFAULT_FW_BLOCK_SIZE;
    }

    return (hostBufferPoolSize + txPortBufferPoolSize);
}

int8_t ICSS_EmacValidateFeatureSet(ICSS_EmacHandle icssEmacHandle, uint8_t portNo, uint32_t featureCtrl)
{
    int8_t ret = 0;
    uint32_t icssFwRelease1 = 0U;
    uint32_t icssFwRelease2 = 0U;
    uint32_t icssFwFeatureSet = 0U;
    uint32_t pruDataMem = 0U;
    uint32_t pruDataMem1 = 0U;
    
    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);
    /* ICSS_EMAC_PORT_0 is switch mode, need to validate for both ports */
    if(ICSS_EMAC_PORT_0 == portNo) 
    {
        pruDataMem = (((ICSS_EmacHwAttrs const*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr;
        
        icssFwRelease1 = HW_RD_REG32(pruDataMem +pStaticMMap->versionOffset);
        icssFwRelease2 = HW_RD_REG32(pruDataMem +pStaticMMap->version2Offset);
        icssFwFeatureSet = HW_RD_REG32(pruDataMem +pStaticMMap->featureOffset);
        /* Only check the feature set field if fw release settings are non-zero implying they are valid*/
        if ((icssFwRelease1 != 0U) && (icssFwRelease2 != 0U))
        {
            if (0U==(icssFwFeatureSet & featureCtrl))
            {
                ret = -((int8_t)1);
            }
        }
        if(ret == 0)
        {
            icssFwRelease1 = 0U;
            icssFwRelease2 = 0U;
            icssFwFeatureSet = 0U;
            pruDataMem1 = (((ICSS_EmacHwAttrs const*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr;
            icssFwRelease1 = HW_RD_REG32(pruDataMem1 +pStaticMMap->versionOffset);
            icssFwRelease2 = HW_RD_REG32(pruDataMem1 +pStaticMMap->version2Offset);
            icssFwFeatureSet = HW_RD_REG32(pruDataMem1 +pStaticMMap->featureOffset);
            /* Only check the feature set field if fw release settings are non-zero implying they are valid*/
            if ((icssFwRelease1 != 0U) && (icssFwRelease2 != 0U))
            {
                if (0U==(icssFwFeatureSet & featureCtrl))
                {
                    ret = -((int8_t)1);
                }
            }
        }
    }
    else if(ICSS_EMAC_PORT_1 == portNo)
    {
        pruDataMem = (((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr;
        icssFwRelease1 = HW_RD_REG32(pruDataMem +pStaticMMap->versionOffset);
        icssFwRelease2 = HW_RD_REG32(pruDataMem +pStaticMMap->version2Offset);
        icssFwFeatureSet = HW_RD_REG32(pruDataMem +pStaticMMap->featureOffset);
        /* Only check the feature set field if fw release settings are non-zero implying they are valid*/
        if ((icssFwRelease1 != 0U) && (icssFwRelease2 != 0U))
        {
            if (0U==(icssFwFeatureSet & featureCtrl))
            {
                ret = -((int8_t)1);
            }
        }
    }
    else if(ICSS_EMAC_PORT_2 == portNo)    /*    ICSS_EMAC_PORT_2    */
    {
        pruDataMem1 = (((ICSS_EmacHwAttrs const*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr;
        icssFwRelease1 = HW_RD_REG32(pruDataMem1 +pStaticMMap->versionOffset);
        icssFwRelease2 = HW_RD_REG32(pruDataMem1 +pStaticMMap->version2Offset);
        icssFwFeatureSet = HW_RD_REG32(pruDataMem1 +pStaticMMap->featureOffset);
        /* Only check the feature set field if fw release settings are non-zero implying they are valid*/
        if ((icssFwRelease1 != 0U) && (icssFwRelease2 != 0U))
        {
            if (0U==(icssFwFeatureSet & featureCtrl))
            {
                ret = -((int8_t)1);
            }
        }
    }
    else
    {
        ret = -((int8_t)1);
    }

      return ret;
}

void ICSS_EmacMemInit(uint32_t* addr, uint32_t size)
{
    uint32_t  i;
    if (addr != NULL)
    {
        for ( i= 0U;   i< (size/4u);  i++)
        {
            *(addr + i) = 0x00000000U;
        }
    }
}

void ICSS_EmacInitLinkState(ICSS_EmacHandle icssEmacHandle, uint8_t interfaceId, uint8_t portNo)

{
    uint32_t linkStatus = 0U;
    ICSSEMAC_IoctlCmd ioctlParams;
    uint8_t portVal = 0U;
    volatile uint8_t *portStatusPtr = NULL;
    uint32_t temp_addr = 0U;
    ICSS_EmacFwStaticMmap *pStaticMMap = NULL;


    pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);

    linkStatus = CSL_MDIO_phyLinkStatus((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs,
                                                                (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->phyAddr[interfaceId]);
    if(linkStatus)
    {
        portVal = ICSS_EMAC_IOCTL_PORT_CTRL_ENABLE;
        ioctlParams.ioctlVal = &portVal;
        if (portNo == ICSS_EMAC_PORT_1)
        {
            ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_PORT_CTRL,portNo, &ioctlParams);
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr + pStaticMMap->portStatusOffset);
        }
        else if (portNo == ICSS_EMAC_PORT_2)
        {
            ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_PORT_CTRL,portNo, &ioctlParams);
            temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->portStatusOffset);
        }
        /* switch use case */
        else
        {
            /* ICSS_EMAC_PORT_1 of switch */
            if (interfaceId ==0U)
            {
                ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_PORT_CTRL,ICSS_EMAC_PORT_1, &ioctlParams);
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr + pStaticMMap->portStatusOffset);
            }
            /* ICSS_EMAC_PORT_2 of switch */
            else
            {
                ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_PORT_CTRL,ICSS_EMAC_PORT_2, &ioctlParams);
                temp_addr = ((((ICSS_EmacHwAttrs const *)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->portStatusOffset);
            }
        }
        portStatusPtr = (uint8_t*)(temp_addr);
        *(portStatusPtr) = ICSS_EMAC_PORT_LINK_MASK;

        ((ICSS_EmacObject*)icssEmacHandle->object)->linkStatus[interfaceId] = 1U;
        ((ICSS_EmacObject*)icssEmacHandle->object)->prevlinkStatus[interfaceId] =0U;
    }
    else
    {
        ((ICSS_EmacObject*)icssEmacHandle->object)->linkStatus[interfaceId] =0U;
        ((ICSS_EmacObject*)icssEmacHandle->object)->prevlinkStatus[interfaceId] =0U;
    }
}

