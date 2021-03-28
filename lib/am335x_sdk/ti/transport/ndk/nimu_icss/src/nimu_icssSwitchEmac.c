/**
 *   @file nimu_icssSwitchEmac.c
 *   @brief
 *      Contains helper functions used to implement NDK NIMU transport driver interface for ICSS
 */

/* Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com/ 
 *
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdint.h>
#include <ti/csl/hw_types.h>
#if defined (SOC_AM335x) || defined (SOC_AM437x)
#include <ti/csl/src/ip/mdio/V2/cslr_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdioAux.h>
#elif defined (SOC_AM65XX)
#include <ti/csl/csl_mdio.h>
#else
#include <ti/csl/csl_mdioAux.h>
#endif

#include "ti/transport/ndk/nimu_icss/src/nimu_icss_transport_log.h"
#include "ti/transport/ndk/nimu_icss/src/nimu_icssSwitchEmac.h"
#include "ti/transport/ndk/nimu_icss/nimu_icssIoctl.h"
#include "ti/drv/icss_emac/icss_emacStatistics.h"
#include "ti/drv/icss_emac/icss_emacStormControl.h"
#include "ti/transport/ndk/nimu_icss/nimu_icssEth.h"

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */



void NIMU_ICSS_packetInit(NIMU_IcssEmacPkt* pNimuPacket)
{
    PBM_Handle hPkt;
    hPkt = PBM_alloc(1522U);
    if (hPkt != NULL)
    {
        PBM_setDataOffset( hPkt, 0 );
    
        pNimuPacket->AppPrivate = (uint32_t)hPkt;
        pNimuPacket->pDataBuffer  = PBM_getDataBuffer(hPkt);
        pNimuPacket->BufferLen    = PBM_getBufferLen(hPkt);
        pNimuPacket->DataOffset =  PBM_getDataOffset(hPkt);
    }
}

/**
* @brief The function free Rx packet buffer
* @internal
* @param pi pointer to EMAC object
*
* @retval none
*/
void NIMU_ICSS_packetShutdown(NIMU_IcssPdInfo *pi); /* misra warning */
void NIMU_ICSS_packetShutdown(NIMU_IcssPdInfo *pi)
{

    NIMU_IcssDevice* nimuDevice = (NIMU_IcssDevice*)(((ICSS_EmacObject*)((pi->nimuDrvHandle)->object))->pvtInfo);
    PBM_free( (PBM_Handle)((nimuDevice->nimuPktRx)->AppPrivate));
}

/**
* @brief Update our local copy of the statistics
* @internal
* @param pd pointer to EMAC object
*
* @retval none
*
* @pre EMAC peripheral instance must be opened
*/
static void NIMU_ICSS_updateStats(NIMU_IcssPdInfo *pd, uint8_t portNo); /* misra warning */
static void NIMU_ICSS_updateStats(NIMU_IcssPdInfo *pd, uint8_t portNo)
{
    uint8_t	i = 0;
    ICSS_EmacHandle icssEmacHandle = pd->nimuDrvHandle;
    NIMU_IcssDevice *nimuDevice = (NIMU_IcssDevice*)(((ICSS_EmacObject*)icssEmacHandle->object)->pvtInfo);
    NIMU_IcssStatistics* nimuStats = nimuDevice->nimuStat;
	ICSS_EmacPruStatistics_t *pruStatsPtr;
	ICSS_EmacHostStatistics_t * hostStatsPtr;
	ICSSEMAC_IoctlCmd ioctlParams;

	/*Separate logic to get Switch and Mac statistics*/
	if(ICSS_EMAC_MODE_SWITCH == ((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg->portMask)
	{
		/*IOCTL Command to read Statistics to ICSSEMAC handle*/
		ioctlParams.command = ICSS_EMAC_IOCTL_STAT_CTRL_GET;
		ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_STATS_CTRL, ICSS_EMAC_PORT_1, (void*)&ioctlParams);
		ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_STATS_CTRL, ICSS_EMAC_PORT_2, (void*)&ioctlParams);

		pruStatsPtr = (ICSS_EmacPruStatistics_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->pruStat);
		hostStatsPtr = (ICSS_EmacHostStatistics_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->hostStat);

		/*Getting Host statistics*/
		(nimuStats)->txUcast += ((hostStatsPtr)->txUcast + (hostStatsPtr + 1)->txUcast);
		(nimuStats)->txBcast += ((hostStatsPtr)->txBcast + (hostStatsPtr + 1)->txBcast);
		(nimuStats)->txMcast += ((hostStatsPtr)->txMcast + (hostStatsPtr + 1)->txMcast);
		(nimuStats)->txGoodFrames += ((hostStatsPtr)->txUcast + (hostStatsPtr)->txBcast + (hostStatsPtr)->txMcast);
		(nimuStats)->txNetOctets += ((hostStatsPtr)->txOctets + (hostStatsPtr + 1)->txOctets);
		(nimuStats)->rxUcast+= ((hostStatsPtr)->rxUcast + (hostStatsPtr + 1)->rxUcast);
		(nimuStats)->rxBcast += ((hostStatsPtr)->rxBcast + (hostStatsPtr + 1)->rxBcast);
		(nimuStats)->rxMcast += ((hostStatsPtr)->rxMcast + (hostStatsPtr + 1)->rxMcast);
		(nimuStats)->rxGoodFrames += ((hostStatsPtr)->rxUcast + (hostStatsPtr)->rxBcast + (hostStatsPtr)->rxMcast);
		(nimuStats)->rxNetOctets += ((hostStatsPtr)->rxOctets + (hostStatsPtr + 1)->rxOctets);
        (nimuStats)->rxUnknownProtocol += ((hostStatsPtr)->rxUnknownProtocol + (hostStatsPtr + 1)->rxUnknownProtocol);
        (nimuStats)->droppedPackets = 0U;


        for( i = 0U; i < NIMU_ICSS_NUM_MAC_PORTS; i++) {

            (nimuStats + i + 1U)->txUcast += (pruStatsPtr + i)->txUcast;
            (nimuStats + i + 1U)->txBcast += (pruStatsPtr + i)->txBcast;
            (nimuStats + i + 1U)->txMcast += (pruStatsPtr + i)->txMcast;
            (nimuStats + i + 1U)->txGoodFrames += ((pruStatsPtr + i)->txUcast + (pruStatsPtr + i)->txBcast \
                                             + (pruStatsPtr + i)->txMcast);
            (nimuStats + i + 1U)->txNetOctets += (pruStatsPtr + i)->txOctets;

            (nimuStats + i + 1U)->rxUcast += (pruStatsPtr + i)->rxUcast;
            (nimuStats + i + 1U)->rxBcast += (pruStatsPtr + i)->rxBcast;
            (nimuStats + i + 1U)->rxMcast += (pruStatsPtr + i)->rxMcast;

            (nimuStats + i + 1U)->rxGoodFrames += ((pruStatsPtr + i)->rxUcast + (pruStatsPtr + i)->rxBcast \
                                              + (pruStatsPtr + i)->rxMcast);
            (nimuStats + i + 1U)->rxNetOctets += (pruStatsPtr + i)->rxOctets;
            (nimuStats + i + 1U)->rxErrorFrames += ((pruStatsPtr + i)->rxCRCFrames + (pruStatsPtr + i)->rxOverSizedFrames + (pruStatsPtr + i)->rxUnderSizedFrames
                                                + (pruStatsPtr + i)->rxMisAlignmentFrames);
            (nimuStats + i + 1U)->rxUnknownProtocol += (hostStatsPtr + i)->rxUnknownProtocol;
            (nimuStats + i + 1U)->droppedPackets += ((pruStatsPtr + i)->stormPrevCounter + (pruStatsPtr + i)->droppedPackets);

            (nimuStats + i + 1U)->lateColl     += (pruStatsPtr + i)->lateColl;
            (nimuStats + i + 1U)->excessColl     += (pruStatsPtr + i)->excessColl;
            (nimuStats + i + 1U)->singleColl     += (pruStatsPtr + i)->singleColl;
            (nimuStats + i + 1U)->multiColl     += (pruStatsPtr + i)->multiColl;
            (nimuStats + i + 1U)->defTx         += (pruStatsPtr + i)->defTx;
            (nimuStats + i + 1U)->macRxError     += ((pruStatsPtr + i)->macRxError + (pruStatsPtr + i)->SFDError);

            }

        /*IOCTL Command to Clear Statistics to ICSSEMAC handle.The nimu structure holds the stat */
		/* Increment the nimu structure values in next read */
		ioctlParams.command = ICSS_EMAC_IOCTL_STAT_CTRL_CLEAR;
		ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_STATS_CTRL, ICSS_EMAC_PORT_1, (void*)&ioctlParams);
		ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_STATS_CTRL, ICSS_EMAC_PORT_2, (void*)&ioctlParams);
	}
    else
    {
        /*IOCTL Command to read Statistics to ICSSEMAC handle*/
        ioctlParams.command = ICSS_EMAC_IOCTL_STAT_CTRL_GET;
        ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_STATS_CTRL, portNo, (void*)&ioctlParams);

        pruStatsPtr = (ICSS_EmacPruStatistics_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->pruStat);
        hostStatsPtr = (ICSS_EmacHostStatistics_t*)(((ICSS_EmacObject*)icssEmacHandle->object)->hostStat);

        /*Getting Host statistics*/
        (nimuStats)->txUcast += (hostStatsPtr)->txUcast;
        (nimuStats)->txBcast += (hostStatsPtr)->txBcast;
        (nimuStats)->txMcast += (hostStatsPtr)->txMcast;
        (nimuStats)->txGoodFrames += ((hostStatsPtr)->txUcast + (hostStatsPtr)->txBcast + (hostStatsPtr)->txMcast);
        (nimuStats)->txNetOctets += (hostStatsPtr)->txOctets ;
        (nimuStats)->rxUcast+= (hostStatsPtr)->rxUcast ;
        (nimuStats)->rxBcast += (hostStatsPtr)->rxBcast ;
        (nimuStats)->rxMcast += (hostStatsPtr)->rxMcast ;
        (nimuStats)->rxGoodFrames += ((hostStatsPtr)->rxUcast + (hostStatsPtr)->rxBcast + (hostStatsPtr)->rxMcast); /* NA */
        (nimuStats)->rxNetOctets += (hostStatsPtr)->rxOctets ;
        (nimuStats)->rxUnknownProtocol += (hostStatsPtr)->rxUnknownProtocol;
        (nimuStats)->droppedPackets = 0;

        /*Getting Port statistics*/
        (nimuStats + 1)->txUcast += (pruStatsPtr)->txUcast;
        (nimuStats + 1)->txBcast += (pruStatsPtr)->txBcast;
        (nimuStats + 1)->txMcast += (pruStatsPtr)->txMcast;
        (nimuStats + 1)->txGoodFrames += ((pruStatsPtr)->txUcast + (pruStatsPtr)->txBcast \
                                         + (pruStatsPtr)->txMcast);
        (nimuStats + 1)->txNetOctets += (pruStatsPtr)->txOctets;

        (nimuStats + 1)->rxUcast += (pruStatsPtr)->rxUcast;
        (nimuStats + 1)->rxBcast += (pruStatsPtr)->rxBcast;
        (nimuStats + 1)->rxMcast += (pruStatsPtr)->rxMcast;

        (nimuStats + 1)->rxGoodFrames += ((pruStatsPtr)->rxUcast + (pruStatsPtr)->rxBcast \
                                          + (pruStatsPtr)->rxMcast);
        (nimuStats + 1)->rxNetOctets += (pruStatsPtr)->rxOctets;
        (nimuStats + 1)->rxErrorFrames += ((pruStatsPtr)->rxCRCFrames + (pruStatsPtr)->rxOverSizedFrames + (pruStatsPtr)->rxUnderSizedFrames
                                            + (pruStatsPtr)->rxMisAlignmentFrames);
        (nimuStats + 1)->rxUnknownProtocol += (hostStatsPtr)->rxUnknownProtocol;
        (nimuStats + 1)->droppedPackets += ((pruStatsPtr)->stormPrevCounter + (pruStatsPtr)->droppedPackets);

        (nimuStats + 1)->lateColl     += (pruStatsPtr)->lateColl;
        (nimuStats + 1)->excessColl     += (pruStatsPtr)->excessColl;
        (nimuStats + 1)->singleColl     += (pruStatsPtr)->singleColl;
        (nimuStats + 1)->multiColl     += (pruStatsPtr)->multiColl;
        (nimuStats + 1)->defTx         += (pruStatsPtr)->defTx;
        (nimuStats + 1)->macRxError     += ((pruStatsPtr)->macRxError + (pruStatsPtr)->SFDError);


		/*IOCTL Command to Clear Statistics to ICSSEMAC handle.The nimu structure holds the stat */
		/* Increment the nimu structure values in next read */
		ioctlParams.command = ICSS_EMAC_IOCTL_STAT_CTRL_CLEAR;
		ICSS_EmacIoctl(icssEmacHandle, ICSS_EMAC_IOCTL_STATS_CTRL, portNo, (void*)&ioctlParams);
	}
}


/**********************************************************************
 ***************** Switch Configuration Functions *********************
 **********************************************************************/


/**
* @internal
* @brief Configures Address lookup engine (ALE) of EMAC.
*
* @param hPort       pointer to port object
*
* @retval none
*
*/
static void NIMU_ICSS_setAleCfg(ICSS_EmacHandle handle); /* misra warning */
static void NIMU_ICSS_setAleCfg(ICSS_EmacHandle handle)
{
    ICSSEMAC_IoctlCmd ioctlParams;
    ioctlParams.command = ICSS_EMAC_LEARN_CTRL_INIT_TABLE;
    if(ICSS_EMAC_MODE_SWITCH == (((ICSS_EmacObject*)handle->object)->emacInitcfg)->portMask)
    {
        if((((ICSS_EmacObject*)handle->object)->emacInitcfg)->learningEn)
        {
            ICSS_EmacIoctl(handle, ICSS_EMAC_IOCTL_LEARNING_CTRL, 0, (void*)&ioctlParams);
        }
    }
}


/**
* @internal
* @brief Configures Address lookup engine (ALE) of EMAC.
*
* @param hPort       pointer to port object
*
* @retval none
*
*/
static void NIMU_ICSS_setRateControlCfg(ICSS_EmacHandle handle); /* misra warning */
static void NIMU_ICSS_setRateControlCfg(ICSS_EmacHandle handle)
{
    ICSSEMAC_IoctlCmd ioctlParams;
    ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_INIT;


    switch ((((ICSS_EmacObject*)handle->object)->emacInitcfg)->portMask)
    {
        case ICSS_EMAC_MODE_SWITCH:
        {
            ICSS_EmacIoctl(handle, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, ICSS_EMAC_PORT_1, (void*)&ioctlParams);
            ICSS_EmacIoctl(handle, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, ICSS_EMAC_PORT_2, (void*)&ioctlParams);
            break;
        }
        case ICSS_EMAC_MODE_MAC1:
        {
            ICSS_EmacIoctl(handle, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, ICSS_EMAC_PORT_1, (void*)&ioctlParams);
            break;
        }
        case ICSS_EMAC_MODE_MAC2:
        {
            ICSS_EmacIoctl(handle, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, ICSS_EMAC_PORT_2, (void*)&ioctlParams);
            break;
        }
        default:
        {
            break;
        }
    }

}

/**
* @internal
* @brief Configures Address lookup engine (ALE) of EMAC.
*
* @param hPort       pointer to port object
*
* @retval none
*
*/
static void NIMU_ICSS_setStatisticsCfg(ICSS_EmacHandle handle); /* misra warning */
static void NIMU_ICSS_setStatisticsCfg(ICSS_EmacHandle handle)
{
    ICSSEMAC_IoctlCmd ioctlParams;
    ioctlParams.command = ICSS_EMAC_IOCTL_STAT_CTRL_CLEAR;


    switch ((((ICSS_EmacObject*)handle->object)->emacInitcfg)->portMask)
    {
        case ICSS_EMAC_MODE_SWITCH:
        {
            ICSS_EmacIoctl(handle, ICSS_EMAC_IOCTL_STATS_CTRL, ICSS_EMAC_PORT_1, (void*)&ioctlParams);
            ICSS_EmacIoctl(handle, ICSS_EMAC_IOCTL_STATS_CTRL, ICSS_EMAC_PORT_2, (void*)&ioctlParams);
            break;
        }
        case ICSS_EMAC_MODE_MAC1:
        {
            ICSS_EmacIoctl(handle, ICSS_EMAC_IOCTL_STATS_CTRL, ICSS_EMAC_PORT_1, (void*)&ioctlParams);
            break;
        }
        case ICSS_EMAC_MODE_MAC2:
        {
            ICSS_EmacIoctl(handle, ICSS_EMAC_IOCTL_STATS_CTRL, ICSS_EMAC_PORT_2, (void*)&ioctlParams);
            break;
        }
        default:
        {
            break;
        }
    }
}



/**
* @internal
* @brief This function opens and sets up a MAC port for communication.
*
* @param hPort               Handle to the Port object to setup
*
* @retval none
*
*/
static void NIMU_ICSS_macOpen(uint32_t hPort,NIMU_IcssPdInfo * pi); /* misra warning */
static void NIMU_ICSS_macOpen(uint32_t hPort,NIMU_IcssPdInfo * pi)
{

    uint32_t instId = hPort ;
    ICSS_EmacHandle icssEmacHandle = pi->nimuDrvHandle;
    uint32_t phyNum = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->phyAddr[instId];
    uint32_t phyinst = (hPort + pi->PhysIdx);
    uint32_t PhySel;


    PhySel=phyNum;
    PhySel = PhySel | (0x40U);

    uint32_t baseAddr = (((const ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs;

    baseAddr = baseAddr + CSL_MDIO_USER_PHY_SEL_REG(0U);

    baseAddr = baseAddr + (phyinst*8U);

     HWREG(baseAddr) = PhySel;
}


static void NIMU_ICSS_macClose(uint32_t hPort,NIMU_IcssPdInfo * pi); /* misra warning */
static void NIMU_ICSS_macClose(uint32_t hPort,NIMU_IcssPdInfo * pi)
{

    uint32_t instId = hPort ;
    ICSS_EmacHandle icssEmacHandle = pi->nimuDrvHandle;
    uint32_t phyNum = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->phyAddr[instId];
    uint32_t phyinst = (hPort + pi->PhysIdx);
    uint32_t PhySel;

    PhySel=phyNum;
    PhySel = PhySel & ~((uint32_t)0x40U);

    uint32_t baseAddr = (((const ICSS_EmacHwAttrs*)icssEmacHandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs;

    baseAddr = baseAddr + CSL_MDIO_USER_PHY_SEL_REG(0U);
    baseAddr = baseAddr + (phyinst*8U);

     HWREG(baseAddr) = PhySel;

}

#if defined (__aarch64__) || defined (__TI_ARM_V7R4__)
static void NIMU_ICSS_MDIO_init(uint32_t baseAddr,
              uint32_t mdioInputFreq,
              uint32_t mdioOutputFreq)
{
    uint32_t clkDiv = (mdioInputFreq/mdioOutputFreq) - 1U;
    uint32_t regVal = 0U;

    HW_SET_FIELD(regVal, CSL_MDIO_CONTROL_REG_ENABLE, CSL_MDIO_CONTROL_REG_ENABLE_0X1);
    HW_SET_FIELD(regVal,  CSL_MDIO_CONTROL_REG_PREAMBLE, CSL_MDIO_CONTROL_REG_PREAMBLE_EN_0X1);
    HW_SET_FIELD(regVal, CSL_MDIO_CONTROL_REG_FAULT_DETECT_ENABLE, CSL_MDIO_CONTROL_REG_FAULT_DETECT_ENABLE_0X1);
    HW_SET_FIELD(regVal, CSL_MDIO_CONTROL_REG_CLKDIV, clkDiv);
    HW_WR_REG32(baseAddr + CSL_MDIO_CONTROL_REG, regVal);
}
#endif
void NIMU_ICSS_openPeripheral(NIMU_IcssPdInfo *pi)
{
    uint32_t              i;
    uint32_t numPorts=0U;

    if(ICSS_EMAC_MODE_SWITCH == (uint32_t)((((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->emacInitcfg)->portMask))
    {
        numPorts = 2U;
    }
    else
    {
        numPorts = 1U;
    }
    if(ICSS_EMAC_MODE_MAC2 != (((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->emacInitcfg)->portMask)
    {
#if defined (__aarch64__) || defined (__TI_ARM_V7R4__)
        NIMU_ICSS_MDIO_init((((ICSS_EmacHwAttrs*)(pi->nimuDrvHandle)->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs,
                                 NIMU_ICSS_DEFAULT_MDIOCLOCKFREQ,NIMU_ICSS_DEFAULT_MDIOBUSFREQ);
#else
        CSL_MDIO_init((((ICSS_EmacHwAttrs*)(pi->nimuDrvHandle)->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs,
                                 NIMU_ICSS_DEFAULT_MDIOCLOCKFREQ,NIMU_ICSS_DEFAULT_MDIOBUSFREQ);
#endif
    }

    /* Open all ports */
    for(i=0;i<numPorts; i++)
    {
        NIMU_ICSS_macOpen(i,pi);
    }/* end of for loop over PORTS */

    NIMU_ICSS_setAleCfg(pi->nimuDrvHandle);

    NIMU_ICSS_setRateControlCfg(pi->nimuDrvHandle);

    NIMU_ICSS_setStatisticsCfg(pi->nimuDrvHandle);

}

uint32_t NIMU_ICSS_closePeripheral(NIMU_IcssPdInfo *pi)
{
    uint32_t i;
    uint32_t numPorts;

    if(ICSS_EMAC_MODE_SWITCH == (((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->emacInitcfg)->portMask)
    {
        numPorts =2U;
    }
    else
    {
        numPorts = 1U;
    }
    /* Close all ports */
    for(i=0U;i<numPorts; i++)
    {
        NIMU_ICSS_macClose(i,pi);
    }/* end of for loop over PORTS */

    NIMU_ICSS_packetShutdown(pi);

    /* Exit with interrupts still disabled in the wrapper */
    return (NIMU_ICSS_SUCCESS);
}
/**
* @brief 	Called to get the current device statistics. The statistics structure
*     		contains a collection of event counts for various packet sent and
*     		receive properties. Reading the statistics also clears the current
*     		statistic counters, so the values read represent a delta from the last
*     		call.
* @details  The statistics information is copied into the structure pointed to
*     			by the pStatistics argument.
*     			The function returns zero on success, or an error code on failure.
*     			Possible error code include:
*      			NIMU_ICSS_INVALID_PARAM   - A calling parameter is invalid
* @internal
* @param  hEMAC       handle to the opened EMAC device
* @param  pStatistics Pointer to the device statistics
* @param  portNo   port number
*
* @retval 	Success (0)
*			NIMU_ICSS_INVALID_PARAM   - A calling parameter is invalid
* @pre      EMAC peripheral instance must be opened before calling this API
*
*/
uint32_t NIMU_ICSS_getStatistics(NIMU_IcssPdInfo *pi, NIMU_IcssStatistics *pStatistics,uint8_t portNo)
{
    uint32_t retVal;
    NIMU_IcssDevice *nimuDevice = (NIMU_IcssDevice*)(((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->pvtInfo);
    NIMU_IcssStatistics* nimuStats = nimuDevice->nimuStat;

    if(portNo > NIMU_ICSS_NUM_MAC_PORTS)
    {
            retVal =  NIMU_ICSS_INVALID_PORT;
    }
    else
    {
        /* Update the stats */
        NIMU_ICSS_updateStats(pi, portNo);
        /* Copy the updated stats to the application */
        *pStatistics = *(nimuStats + portNo);
        retVal = NIMU_ICSS_SUCCESS;
    }
    return (retVal);
}
/**
* @brief 	Called to clear the current device statistics for a particular port
* @internal
* @param  pi       handle to the opened EMAC device
* @param  portNo   port to clear statistics
*
* @retval 	Success (0)
*			NIMU_ICSS_INVALID_PARAM   - A calling parameter is invalid
* @pre      EMAC peripheral instance must be opened before calling this API
*
*/
uint32_t NIMU_ICSS_clearStatistics(NIMU_IcssPdInfo *pi,uint8_t portNo)
{
    uint32_t retVal;
    NIMU_IcssDevice *nimuDevice = (NIMU_IcssDevice*)(((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->pvtInfo);
    NIMU_IcssStatistics* nimuStats = nimuDevice->nimuStat;
    if(portNo > NIMU_ICSS_NUM_MAC_PORTS)
    {
            retVal =  NIMU_ICSS_INVALID_PORT;
    }
    else
    {
        NIMU_ICSS_updateStats(pi, portNo);
        memset((nimuStats + portNo),0,sizeof(NIMU_IcssStatistics));
        retVal = NIMU_ICSS_SUCCESS;
    }
    return (retVal);
}


uint32_t NIMU_ICSS_setConfig(NIMU_IcssPdInfo *pi, void* pBuf, uint32_t size)
{
    uint32_t  ret_val = NIMU_ICSS_SUCCESS;
    uint32_t port;
    NIMU_IcssConsCmd * swConsCommand = (NIMU_IcssConsCmd *)pBuf;
    ICSS_EmacHandle emachandle = pi->nimuDrvHandle;
    uint8_t mode =0;
    uint32_t mdioBaseAdd;
    uint32_t phyAddr;
    uint16_t regStatus = 0U;
    mdioBaseAdd= (((ICSS_EmacHwAttrs*)emachandle->hwAttrs)->emacBaseAddrCfg)->prussMiiMdioRegs;
    uint8_t macMode = (((ICSS_EmacObject*)emachandle->object)->emacInitcfg)->portMask;

    switch(swConsCommand->opcode)
    {
        case ICSS_IOCTL_SET_PORT_CONFIG:
        {
            NIMU_IcssPortCmd *lpPortCmd = &swConsCommand->PortCmd;
            uint8_t port = lpPortCmd->port;
            if( (lpPortCmd->port < 2) && (lpPortCmd->EnDis < 2))
            {
                switch(lpPortCmd->value)
                {
                    case 0:
                    {
                        mode=PHY_CONFIG_AUTONEG;
                        break;
                    }
                    case 10:
                    {
                        if(lpPortCmd->EnDis ==1)
                        {
                            mode=PHY_CONFIG_10FD;
                        }
                        else
                        {
                            mode=PHY_CONFIG_10HD;
                        }
                        break;
                    }
                    case 100:
                    {
                        if(lpPortCmd->EnDis ==1)
                        {
                            mode=PHY_CONFIG_100FD;
                        }
                        else
                        {
                            mode=PHY_CONFIG_100HD;
                        }
                         break;
                    }
                    default:
                    {
                        mode=PHY_CONFIG_AUTONEG;
                        break;
                    }
                }/* end of switch construct  */

                if(macMode == ICSS_EMAC_MODE_SWITCH)
                {
                    if(port > 0U)
                    {
                        phyAddr =(((ICSS_EmacObject*)emachandle->object)->emacInitcfg)->phyAddr[port-1U];
                    }
                    else
                    {
                        ret_val = NIMU_ICSS_INVALID_PORT;
                     }
                }
                else
                {
                    phyAddr = (((ICSS_EmacObject*)emachandle->object)->emacInitcfg)->phyAddr[0U];
                }
                if (ret_val == NIMU_ICSS_SUCCESS)
                {
                    regStatus = 0;
                    CSL_MDIO_phyRegRead(mdioBaseAdd, phyAddr, NIMU_ICSS_PHY_BMCR_REG, &regStatus);
                    switch(mode)
                    {
                         case PHY_CONFIG_AUTONEG:
                              regStatus = regStatus | NIMU_ICSS_MII_AUTO_NEGOTIATE_EN;
                             break;
                         case PHY_CONFIG_100FD:
                             regStatus = regStatus & (uint16_t)(~(NIMU_ICSS_MII_AUTO_NEGOTIATE_EN));
                             regStatus = regStatus | NIMU_ICSS_MII_SPEEDSEL_100;
                             regStatus = regStatus | NIMU_ICSS_MII_DUPLEXMODE_FULL;

                             
                             break;
                         case PHY_CONFIG_10FD:
                             regStatus = regStatus & (uint16_t)(~(NIMU_ICSS_MII_AUTO_NEGOTIATE_EN));
                             regStatus = regStatus & (uint16_t)(~(NIMU_ICSS_MII_SPEEDSEL_100));
                             regStatus = regStatus | NIMU_ICSS_MII_DUPLEXMODE_FULL;
                             break;
                         case PHY_CONFIG_100HD:
                             regStatus = regStatus & (uint16_t)(~(NIMU_ICSS_MII_AUTO_NEGOTIATE_EN));
                             regStatus = regStatus | NIMU_ICSS_MII_SPEEDSEL_100;
                             regStatus = regStatus & (uint16_t)(~(NIMU_ICSS_MII_DUPLEXMODE_FULL));
                             break;
                         case PHY_CONFIG_10HD:
                             regStatus = regStatus & (uint16_t)(~(NIMU_ICSS_MII_AUTO_NEGOTIATE_EN));
                             regStatus = regStatus & (uint16_t)(~(NIMU_ICSS_MII_SPEEDSEL_100));
                             regStatus = regStatus & (uint16_t)(~(NIMU_ICSS_MII_DUPLEXMODE_FULL));
                             break;
                         default:
                             regStatus = regStatus | NIMU_ICSS_MII_AUTO_NEGOTIATE_EN;
                             break;
                    }
                CSL_MDIO_phyRegWrite(mdioBaseAdd, phyAddr, NIMU_ICSS_PHY_BMCR_REG, regStatus);
                    }
            }
            else
            {
                NIMU_ICSS_transport_log("SET_PORT_CONFIG:Invalid Arguments\n");
                ret_val = NIMU_ICSS_INVALID_PORT;
            }

            break;
        }
        case ICSS_IOCTL_GET_PORT_CONFIG:
        {
            NIMU_IcssPortCmd *lpPortCmd = &swConsCommand->PortCmd;
            uint8_t i;
            if(lpPortCmd->port == 0)        /*HOST Port*/
            {
                port  = lpPortCmd->port;
                lpPortCmd->ml    = port;
                lpPortCmd->port  = ((uint8_t)1U);
                lpPortCmd->value = ((uint32_t)0U);
                lpPortCmd->EnDis = ((uint8_t)1U);
                lpPortCmd->phyMode = 0;
                for(i=0U;i<6U;i++)
                {
                    lpPortCmd->add[i]= ((((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->emacInitcfg)->macId)[i];
                }
            }
            else if(lpPortCmd->port < ((uint8_t)3U))
            {
                port  = lpPortCmd->port;
                if(macMode == ICSS_EMAC_MODE_SWITCH)
                {
                    phyAddr = (((ICSS_EmacObject*)emachandle->object)->emacInitcfg)->phyAddr[port-1U];
                }
                else
                {
                    phyAddr = (((ICSS_EmacObject*)emachandle->object)->emacInitcfg)->phyAddr[0U];
                }

                CSL_MDIO_phyRegRead(mdioBaseAdd, phyAddr, NIMU_ICSS_PHY_BMCR_REG, &regStatus);

                if(regStatus & NIMU_ICSS_MII_AUTO_NEGOTIATE_EN)
                {
                    lpPortCmd->value =0;
                }
                switch(lpPortCmd->value)
                {
                    case PHY_CONFIG_10FD:
                    {
                        lpPortCmd->EnDis =((uint8_t)1);
                        lpPortCmd->value =10;
                        break;
                    }
                    case PHY_CONFIG_10HD:
                     {
                        lpPortCmd->EnDis =((uint8_t)0U);
                        lpPortCmd->value =((uint32_t)10U);
                         break;
                     }
                    case PHY_CONFIG_100FD:
                     {
                        lpPortCmd->EnDis =((uint8_t)1U);
                        lpPortCmd->value =((uint32_t)100U);
                          break;
                     }
                     case PHY_CONFIG_100HD:
                     {
                        lpPortCmd->EnDis =((uint8_t)0U);
                        lpPortCmd->value =((uint32_t)100U);
                          break;
                     }
                     default:
                     {
                        break;
                     }
                }
                port  = lpPortCmd->port;
                lpPortCmd->ml    = port - 1U;
                lpPortCmd->port  = CSL_MDIO_phyLinkStatus(mdioBaseAdd,phyAddr);
            }
            else
            {
                NIMU_ICSS_transport_log("GET_PORT_CONFIG:Invalid Arguments\n");
                 ret_val = NIMU_ICSS_INVALID_PORT;
            }

            break;
        }
        default:
        {
            break;
        }
    }/* end of switch construct */

    swConsCommand->ret_type = ret_val;

    return ret_val;
}

uint32_t NIMU_ICSS_sendPacket(Handle hEMAC, NIMU_IcssEmacPkt *pPkt)
{
    uint32_t retVal = NIMU_ICSS_SUCCESS;
    uint32_t          fragcnt,pktlen;
    NIMU_IcssEmacPkt        *pPktLast;
    uint32_t txPort;
    ICSS_EmacHandle handle = (ICSS_EmacHandle)hEMAC;
    int32_t ret;
   ICSS_EmacTxArgument txArgs;

    /* Count the number of frags in this packet */
    fragcnt =1U;
    pktlen  = pPkt->PktLength;

    pPktLast = pPkt;
    while ((((pPktLast->Flags & NIMU_ICSS_EMAC_PKT_FLAGS_EOP) != NIMU_ICSS_EMAC_PKT_FLAGS_EOP)) && (retVal == NIMU_ICSS_SUCCESS))
    {
        if (pPktLast->pNext == NULL)
        {
            retVal = NIMU_ICSS_INVALID_PARAM;
        }
        else
        {
            pktlen -= pPktLast->ValidLen;
            pPktLast = pPktLast->pNext;
            fragcnt++;
            /* At this point we can't have another SOP */
            if (pPktLast->Flags & NIMU_ICSS_EMAC_PKT_FLAGS_SOP)
            {
                retVal = NIMU_ICSS_INVALID_PARAM;
            }
        }
    }
    if (retVal == NIMU_ICSS_SUCCESS)
    {
        /* Make sure PktLength and ValidLen agree */
        if (pktlen != pPktLast->ValidLen)
        {
            retVal = NIMU_ICSS_ERR_BADPACKET;
        }
        else
        {
            /* The frag count must be correct */
            if (fragcnt != pPkt->PktFrags)
            {
                retVal = NIMU_ICSS_ERR_BADPACKET;
            }
            else
            {
                /* Now pad for 60 byte min size. We only pad the last fragment */
                if (pPkt->PktLength < 60U)
                {
                    pktlen = 60U - pPkt->PktLength;
                    pPkt->PktLength = 60U;
                    pPktLast->ValidLen += pktlen;
                }
            
            
                if(ICSS_EMAC_MODE_SWITCH == (((ICSS_EmacObject*)handle->object)->emacInitcfg)->portMask)
                { /*Switch Mode*/
                    txPort = ICSS_EMAC_PORT_0;
                } 
                else if(ICSS_EMAC_MODE_MAC1 == (((ICSS_EmacObject*)handle->object)->emacInitcfg)->portMask)
                {
                    txPort = ICSS_EMAC_PORT_1;
                } 
                else if(ICSS_EMAC_MODE_MAC2 == (((ICSS_EmacObject*)handle->object)->emacInitcfg)->portMask) 
                {
                    txPort = ICSS_EMAC_PORT_2;
                }
                else
                {
                    txPort = ICSS_EMAC_PORT_0;
                }
                txArgs.icssEmacHandle = handle;
                txArgs.lengthOfPacket = pPkt->PktLength;
                txArgs.portNumber = txPort;
                txArgs.queuePriority = ICSS_EMAC_QUEUE4;
                txArgs.srcAddress = (const uint8_t *)(pPkt->pDataBuffer + pPkt->DataOffset);
            
                ret = ((((ICSS_EmacObject*)handle->object)->callBackHandle)->txCallBack)->callBack(&txArgs, ((((ICSS_EmacObject *)handle->object)->callBackHandle)->txCallBack)->userArg);
                if(ret != 0)
                {
                    retVal = NIMU_ICSS_ERR_TX_OUT_OF_BD;
                }
            }
        }
    }
    return (retVal);
}

/**
* @internal
* @brief     This function should be called every time there is an EMAC device Rx
*             interrupt to process the packet
* @details  Note that the application has the responsibility for mapping the
*             physical device index to the correct EMAC_serviceCheck() function. If
*             more than one EMAC device is on the same interrupt, the function must be
*             called for each device.
*
* @param  hEMAC       handle to the opened EMAC device
*
* @retval     NIMU_ICSS_SUCCESS (0)
*                NIMU_ICSS_INTERNAL_FAILURE   - Packet provided by firmware has invalid length
* @pre     NIMU_ICSS_openPeripheral function must be called before calling this API.
*
*/
uint32_t NIMU_ICSS_rxServiceCheck(ICSS_EmacHandle hEMAC,int32_t prioQueue)
{
    uint32_t retVal = NIMU_ICSS_SUCCESS;
    NIMU_IcssEmacPkt    *pPkt;
    int32_t        packetLength;
    ICSS_EmacRxArgument rxArgs;
    uint32_t dataBufTemp;

    NIMU_IcssDevice* lclDevice = (NIMU_IcssDevice*)(((ICSS_EmacObject*)hEMAC->object)->pvtInfo);

    rxArgs.icssEmacHandle = hEMAC;
    
    rxArgs.queueNumber = prioQueue;
    rxArgs.more = 1;
    rxArgs.port = 0;

    while ((retVal == NIMU_ICSS_SUCCESS) && (rxArgs.more == 1U))
    {
        pPkt = lclDevice->nimuPktRx;
        if (pPkt != NULL)
        {
            dataBufTemp = ((uint32_t)pPkt->pDataBuffer);
            rxArgs.destAddress =  dataBufTemp + pPkt->DataOffset;
            packetLength =  ((((ICSS_EmacObject*)hEMAC->object)->callBackHandle)->rxCallBack)->callBack(&rxArgs, ((((ICSS_EmacObject *)hEMAC->object)->callBackHandle)->rxCallBack)->userArg);

            if (packetLength > 0)
            {
                /* Fill in the necessary packet header fields */
                pPkt->ValidLen = pPkt->PktLength = (uint32_t)(packetLength) & (0xFFFFU);
                pPkt->PktChannel = (uint32_t)rxArgs.port;
                pPkt->PktFrags = (1U);
                (lclDevice->pfcbRxPacket)(hEMAC,pPkt);
            }
            else
            {
                retVal = NIMU_ICSS_INTERNAL_FAILURE;
            }
        }
        else
        {
            retVal = NIMU_ICSS_INTERNAL_FAILURE;
        }

    }

    return(retVal);
}

