/**
* @file icss_emacStatistics.c
*
* @brief Main file for Statistics implementation
*        Contains Statistics getter functions
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
#include <stdbool.h>

#include <ti/drv/icss_emac/icss_emacDrv.h>

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/** Variable containing list of implemented protocols*/
extern uint16_t numImplementedProtocols;
/**list of identified protocol types, rest initialized to zero*/
extern uint16_t protocol_impl[MAX_NUM_PROTOCOL_IMPLEMENTED];


#ifdef TEST_DEBUG
int doNotUpdateStatsTX[NUM_PORTS];
int doNotUpdateStatsRX[NUM_PORTS];
#endif

void icss_emac_hw_mem_cpy(const void* addr, const void *ptr, uint32_t element_count)
{
    uint32_t  i;
    volatile uint32_t *dst = (volatile uint32_t *)(uintptr_t)addr;
    uint32_t *src = (uint32_t *)ptr;
    for (i = 0; i < element_count; i++)
    {
        *dst++ = *src++;
    }
}

void icss_emac_hw_mem_set(const void* addr, const uint32_t val, uint32_t element_count)
{
    uint32_t  i;
    volatile uint32_t *dst = (volatile uint32_t *)(uintptr_t)addr;
    for (i = 0; i < element_count; i++)
    {
        *dst++ = val;
    }
}

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void ICSS_EmacReadStats(uint8_t portNum, ICSS_EmacHandle icssEmacHandle)
{
    volatile uint8_t *statsPointer;
    ICSS_EmacPruStatistics_t *pruStatStructPtr;
    uint32_t statisticsOffset = 0U;
    uint32_t statsSize = 0U;

    uint32_t temp_addr = 0U;

    pruStatStructPtr = (ICSS_EmacPruStatistics_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->pruStat);

    statisticsOffset = ((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap.statisticsOffset;
    statsSize = ((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap.statisticsSize;

    if(ICSS_EMAC_MODE_SWITCH != ((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->portMask) {
        portNum = ((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->portMask;
    } else {
        pruStatStructPtr += (portNum - 1U);
    }

    if((uint8_t)ICSS_EMAC_PORT_1 == portNum) {
        temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr +statisticsOffset);
        statsPointer = (uint8_t*)(temp_addr);
    } else {
        temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + statisticsOffset);
        statsPointer = (uint8_t*)(temp_addr);
    }

    icss_emac_hw_mem_cpy((void*)pruStatStructPtr, (void*)statsPointer, (statsSize / sizeof(uint32_t)));
    return;
}

void PurgeStats(uint8_t portNum, ICSS_EmacHandle icssEmacHandle) {

    uint32_t *statsPointer = NULL;

    uint32_t temp_addr = 0U;

    ICSS_EmacPruStatistics_t *pruStatsPtr;
    ICSS_EmacHostStatistics_t * hostStatsPtr;
    ICSS_EmacFwStaticMmap *pStaticMMap = (&((ICSS_EmacObject*)icssEmacHandle->object)->fwStaticMMap);

    pruStatsPtr = (ICSS_EmacPruStatistics_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->pruStat);
    hostStatsPtr = (ICSS_EmacHostStatistics_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->hostStat);

    if(ICSS_EMAC_MODE_SWITCH != ((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->portMask) {
        portNum = ((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->portMask;
    } else {
        pruStatsPtr += (portNum - 1U);
        hostStatsPtr += (portNum - 1U);
    }

    if((uint8_t)ICSS_EMAC_PORT_1 == portNum) {
        temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam0BaseAddr + pStaticMMap->statisticsOffset);
        statsPointer = (uint32_t*)(temp_addr);
    } else {
        temp_addr = ((((ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->dataRam1BaseAddr + pStaticMMap->statisticsOffset);
        statsPointer = (uint32_t*)(temp_addr);
    }

    /*clear PRU  stats*/
    icss_emac_hw_mem_set(statsPointer, 0x0, (pStaticMMap->statisticsSize / sizeof(uint32_t)));

    /*clear port stats*/
    memset(hostStatsPtr, 0x0, sizeof(ICSS_EmacHostStatistics_t));
    memset(pruStatsPtr, 0x0, sizeof(ICSS_EmacPruStatistics_t));

}

void InitStats(uint8_t portNum, ICSS_EmacHandle icssEmacHandle) {

    PurgeStats(portNum, icssEmacHandle);

#ifdef TEST_DEBUG
    doNotUpdateStatsTX[HWPORT0] = 0;
    doNotUpdateStatsTX[HWPORT1] = 0;

    doNotUpdateStatsRX[HWPORT0] = 0;
    doNotUpdateStatsRX[HWPORT1] = 0;
#endif
}

void ICSS_EmacUpdateRxStats(const uint8_t* macAddr,uint32_t packet_len,uint16_t protIdent, ICSS_EmacHostStatistics_t * hostStatsPtr)
{
    uint8_t count=0;
    bool prot_found = 0;
    uint8_t Bcast_mac[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

#ifdef TEST_DEBUG
    /*This is to make sure that the stats query and other custom queries are not counted  */
    if(doNotUpdateStatsRX[portNum-1]) {
        /*clear the flag  */
        doNotUpdateStatsRX[portNum-1] = 0;
        return;
    }
#endif

    /*Broadcast  */
    if(COMPARE_MAC(macAddr, Bcast_mac))
    {
        hostStatsPtr->rxBcast++;
    }
    else if((macAddr[0] & 0x01U) == 1u)      /*Multicast*/
    {
        hostStatsPtr->rxMcast++;
    }
    else /*unicast*/
    {
        hostStatsPtr->rxUcast++;

    }

	hostStatsPtr->rxOctets += (packet_len+4U);

    for(count=0; count < numImplementedProtocols; count++)
    {
        if(protIdent == protocol_impl[count])
        {
            prot_found = (bool)true;
            break;
        }
    }

    if (!prot_found)
    {
        hostStatsPtr->rxUnknownProtocol++;
    }
}

void ICSS_EmacUpdateTxStats(const uint8_t* macAddr,uint32_t packet_len, ICSS_EmacHostStatistics_t * hostStatsPtr) {

#ifdef TEST_DEBUG
    /*This is to make sure that the stats query and other custom queries are not counted   */
    if(doNotUpdateStatsTX[portNum-1]) {
        /*clear the flag  */
        doNotUpdateStatsTX[portNum-1] = 0;
        return;
    }
#endif

    uint8_t Bcast_mac[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

    if(COMPARE_MAC(macAddr, Bcast_mac))
    {
        hostStatsPtr->txBcast++;
    }
    else if((macAddr[0] & 0x01U) == 1u)
    {
        hostStatsPtr->txMcast++;
    }
    else
    {
        hostStatsPtr->txUcast++;

    }
	hostStatsPtr->txOctets += (packet_len+4U);

}

