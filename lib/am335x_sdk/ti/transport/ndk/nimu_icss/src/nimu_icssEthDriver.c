/**
 *   @file nimu_icssEthDriver.c
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


#include "ti/osal/HwiP.h"
#ifdef _TMS320C6X
#include <ti/sysbios/family/c64p/Hwi.h>
#include <ti/sysbios/family/c64p/EventCombiner.h>
#endif

#include "ti/drv/icss_emac/icss_emacDrv.h"

#include "ti/transport/ndk/nimu_icss/nimu_icssEth.h"
#include "ti/transport/ndk/nimu_icss/src/nimu_icssSwitchEmac.h"
#include "ti/transport/ndk/nimu_icss/src/nimu_icssEthDriver.h"

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/** @brief Statistics to account for packets dropped because of memory squeeze */
uint32_t         memory_squeeze_error = 0;
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                            Local Variables                                */
/* ========================================================================== */

/** @brief EMAC fatal error */
static uint32_t   emac_fatal_error = 0;
/** @brief Callback to be registered to process protocol specific packets */
static ICSS_EmacCallBack periodicProtTask;
/** @brief User specific data HW Port 1 link ISR */
static void *periodicProtUser;


/**
* @internal
* @brief De-registering the interrupts and disabling global interrupts
*
* @param none
*
* @retval none
*/
void NIMU_ICSS_interruptEnd(NIMU_IcssPdInfo* pi); /* misra warning */
void NIMU_ICSS_interruptEnd(NIMU_IcssPdInfo* pi)
{
    ICSS_EmacHandle icssEmacHandle = pi->nimuDrvHandle;
    ICSS_EMAC_osalHardwareIntDestruct((HwiP_Handle)(((ICSS_EmacObject*)icssEmacHandle->object)->rxintHandle));
    ICSS_EMAC_osalHardwareIntDestruct((HwiP_Handle)(((ICSS_EmacObject*)icssEmacHandle->object)->linkintHandle));
}

/**
* @internal
* @brief Registering Interrupts and Enabling global interrupts
*
* @param pi Packet device information handle
*
* @retval none
*/
int32_t NIMU_ICSS_interruptInit(NIMU_IcssPdInfo* pi); /* misra warning */
#if defined (__ARM_ARCH_7A__) || defined (__TI_ARM_V7M4__) || defined(__aarch64__) || defined(__TI_ARM_V7R4__)
int32_t NIMU_ICSS_interruptInit(NIMU_IcssPdInfo* pi)
{
    int32_t retVal = 0;
    HwiP_Handle rxHwiHandle;
    HwiP_Handle linkHwiHandle;
    static uint32_t cookie = 0;
    ICSS_EmacHandle icssEmacHandle = pi->nimuDrvHandle;
    int32_t linkIntrN = (int32_t)((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->linkIntNum);
    uint32_t rxIntrN = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->rxIntNum;
    
    cookie = ICSS_EMAC_osalHardwareIntDisable();

    HwiP_Params hwiParams;

    ICSS_EMAC_osalHwiParamsInit(&hwiParams);
#if defined (__ARM_ARCH_7A__) && defined (SOC_K2G)
    hwiParams.triggerSensitivity =2; /* use trigger type edge */
#endif
   
    hwiParams.arg = ((uintptr_t)icssEmacHandle);
    hwiParams.evtId = rxIntrN;
    hwiParams.priority = 20U;
    rxHwiHandle = ICSS_EMAC_osalRegisterInterrupt((int32_t)rxIntrN, (HwiP_Fxn)ICSS_EmacRxInterruptHandler, &hwiParams);
    if (rxHwiHandle == NULL) 
    {
        retVal = -1;
    }
    else
    {
        hwiParams.arg = (uintptr_t)icssEmacHandle;
        hwiParams.evtId = (uint32_t)linkIntrN;
        hwiParams.priority = 20U;
        linkHwiHandle = ICSS_EMAC_osalRegisterInterrupt(linkIntrN, (HwiP_Fxn)ICSS_EmacLinkISR, &hwiParams);
    
        if (linkHwiHandle == NULL) 
        {
            retVal = -1;
        }
       else
        {
            ((ICSS_EmacObject*)icssEmacHandle->object)->rxintHandle = rxHwiHandle;
            ((ICSS_EmacObject*)icssEmacHandle->object)->linkintHandle = linkHwiHandle;
        }
    }
    ICSS_EMAC_osalHardwareIntRestore(cookie);
    return (retVal);
}
#else
int32_t NIMU_ICSS_interruptInit(NIMU_IcssPdInfo* pi)
{
    static uint32_t cookie = 0;
    ICSS_EmacHandle icssEmacHandle = pi->nimuDrvHandle;
#ifdef SOC_K2G
   
    MuxIntcP_inParams       muxInParams;
    MuxIntcP_outParams      muxOutParams;
    cookie = ICSS_EMAC_osalHardwareIntDisable();

    muxInParams.arg         = (uintptr_t)icssEmacHandle;
    muxInParams.muxNum      = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgLink.intcMuxNum;
    muxInParams.muxInEvent  = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgLink.intcMuxInEvent;
    muxInParams.muxOutEvent = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgLink.intcMuxOutEvent;
    muxInParams.muxIntcFxn  = (MuxIntcFxn)(&ICSS_EmacLinkISR);

     ICSS_EMAC_osalMuxIntcSetup(&muxInParams, &muxOutParams);

    EventCombiner_dispatchPlug ((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgLink.eventId,
                                                (EventCombiner_FuncPtr)muxOutParams.muxIntcFxn, (UArg)muxOutParams.arg, TRUE);
    EventCombiner_enableEvent( (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgLink.eventId);

    muxInParams.arg         = (uintptr_t)icssEmacHandle;
    muxInParams.muxNum      = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgRxPkt.intcMuxNum;
    muxInParams.muxInEvent  = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgRxPkt.intcMuxInEvent;
    muxInParams.muxOutEvent = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgRxPkt.intcMuxOutEvent;
    muxInParams.muxIntcFxn  = (MuxIntcFxn)(&ICSS_EmacRxInterruptHandler);

     ICSS_EMAC_osalMuxIntcSetup(&muxInParams, &muxOutParams);

    EventCombiner_dispatchPlug ((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgRxPkt.eventId,
                                                (EventCombiner_FuncPtr)muxOutParams.muxIntcFxn, (UArg)muxOutParams.arg, TRUE);
    EventCombiner_enableEvent( (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgRxPkt.eventId);
    muxInParams.arg         = (uintptr_t)icssEmacHandle;
    muxInParams.muxNum      = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgTxComplete.intcMuxNum;
    muxInParams.muxInEvent  = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgTxComplete.intcMuxInEvent;
    muxInParams.muxOutEvent = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgTxComplete.intcMuxOutEvent;

    muxInParams.muxIntcFxn  = (MuxIntcFxn)(&ICSS_EmacTxInterruptHandler);
    
     ICSS_EMAC_osalMuxIntcSetup(&muxInParams, &muxOutParams);

    EventCombiner_dispatchPlug ((((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgTxComplete.eventId,
                                                (EventCombiner_FuncPtr)muxOutParams.muxIntcFxn, (UArg)muxOutParams.arg, TRUE);
    EventCombiner_enableEvent( (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->intrMuxCfgTxComplete.eventId);
#else

    uint32_t linkIntrN = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->linkIntNum;
    uint32_t rxIntrN = (((ICSS_EmacObject*)icssEmacHandle->object)->emacInitcfg)->rxIntNum;

    cookie = ICSS_EMAC_osalHardwareIntDisable();

    EventCombiner_dispatchPlug (linkIntrN,  (EventCombiner_FuncPtr)ICSS_EmacLinkISR, (UArg)icssEmacHandle, (Bool)TRUE);
    EventCombiner_enableEvent(linkIntrN);


    EventCombiner_dispatchPlug (rxIntrN,  (EventCombiner_FuncPtr)ICSS_EmacRxInterruptHandler,(UArg)icssEmacHandle, (Bool)TRUE);
    EventCombiner_enableEvent(rxIntrN);
#endif

    ICSS_EMAC_osalHardwareIntRestore(cookie);
    return 0;
}
#endif



/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */


/**
* @brief This function disables the EMAC interrupts
* @internal
* @param none
*
* @retval none
*/
void NIMU_ICSS_interruptDisable(NIMU_IcssPdInfo * pi);/* misra warning */
void NIMU_ICSS_interruptDisable(NIMU_IcssPdInfo * pi)
{
    uint32_t key;
    ICSS_EmacHandle handle = pi->nimuDrvHandle;
    key = ICSS_EMAC_osalHardwareIntDisable();

#if defined (__ARM_ARCH_7A__) || defined (__TI_ARM_V7M4__) || defined(__aarch64__) || defined(__TI_ARM_V7R4__)
    ICSS_EMAC_osalHardwareInterruptDisable((((ICSS_EmacObject*)handle->object)->emacInitcfg)->linkIntNum);
    ICSS_EMAC_osalHardwareInterruptDisable((((ICSS_EmacObject*)handle->object)->emacInitcfg)->rxIntNum);

#else
    uint8_t linkIntrN = (((ICSS_EmacObject*)handle->object)->emacInitcfg)->linkIntNum;
    uint8_t rxIntrN =   (((ICSS_EmacObject*)handle->object)->emacInitcfg)->rxIntNum;

    EventCombiner_disableEvent(((uint32_t)linkIntrN));
    EventCombiner_disableEvent(((uint32_t)rxIntrN));
#endif

    ICSS_EMAC_osalHardwareIntRestore(key);

}

/**
* @internal
* @brief This function enables the EMAC interrupts
*
* @param none
*
* @retval none
*/
static void EnableEMACInterrupts(NIMU_IcssPdInfo * pi); /* misra warning */
static void EnableEMACInterrupts(NIMU_IcssPdInfo * pi)
{
#if defined (__ARM_ARCH_7A__) || defined (__TI_ARM_V7M4__) || defined(__aarch64__) || defined(__TI_ARM_V7R4__)
    uint32_t key = 0;

    ICSS_EmacHandle handle = pi->nimuDrvHandle;
    key = ICSS_EMAC_osalHardwareIntDisable();

    ICSS_EMAC_osalHardwareInterruptEnable((((ICSS_EmacObject*)handle->object)->emacInitcfg)->linkIntNum);
    ICSS_EMAC_osalHardwareInterruptEnable((((ICSS_EmacObject*)handle->object)->emacInitcfg)->rxIntNum);

    ICSS_EMAC_osalHardwareIntRestore(key);
#endif
}

/**
 *  \name NIMU_ICSS_rxPacket
 *  \brief Function called by CSL to pass the received packet to the driver
 *
 *  \param  hApplication  Driver's handle
 *  \param  cslPkt  NIMU_IcssEmacPkt type packet passed by CSL
 *
 *  \return NIMU_IcssEmacPkt pointer of a packet with buffer to replenish CSL
 */
static NIMU_IcssEmacPkt *NIMU_ICSS_rxPacket(Handle hApplication, NIMU_IcssEmacPkt *cslPkt); /* misra warning */
static NIMU_IcssEmacPkt *NIMU_ICSS_rxPacket(Handle hApplication, NIMU_IcssEmacPkt *cslPkt)
{
    
    PBM_Handle  hPkt;
    uint32_t pktMtu;
    ICSS_EmacHandle handle = (ICSS_EmacHandle)hApplication;
    NIMU_IcssDevice* lcldevice = (NIMU_IcssDevice*)((ICSS_EmacObject*)handle->object)->pvtInfo;

    pktMtu = lcldevice->PktMTU;
    hPkt = PBM_alloc(pktMtu + 4U + NIMU_ICSS_PKT_PREPAD);
    if (hPkt)
    {
        /* Remove the 4 byte header from the packet. Not sure as to why the EMAC
         * is adding an extra 4bytes to the header. This is causing stack to
         * fail checksum validations on IPv6 packets. So, remove the extra 4 bytes
         * tagged by the EMAC.
         */
        PBM_setValidLen((PBM_Handle) cslPkt->AppPrivate, (cslPkt->ValidLen));
        PBMQ_enq( &(lcldevice->nimuPdInfo->PBMQ_rx), (PBM_Handle) cslPkt->AppPrivate );

        /* Notify NDK stack of pending Rx Ethernet packet */
        STKEVENT_signal( lcldevice->nimuPdInfo->hEvent, STKEVENT_ETHERNET, ((uint32_t)1U));

        PBM_setDataOffset( hPkt, NIMU_ICSS_PKT_PREPAD );
        cslPkt->AppPrivate  = (uint32_t)hPkt;
        cslPkt->pDataBuffer = PBM_getDataBuffer(hPkt);
        cslPkt->BufferLen   = PBM_getBufferLen(hPkt);
        cslPkt->DataOffset = PBM_getDataOffset(hPkt);
    }
    else
    {
        /* Increment the statistics to account for packets dropped because
        * of memory squeeze 
        */
        memory_squeeze_error++;
    }
    return (cslPkt);
}



/**
* @internal
* @brief Populate the configuration structures with the switch's default initialization parameters
*
* @param none
*
* @retval none
*/
static void NIMU_ICSS_initConfig(NIMU_IcssDevice* nimuDevice,NIMU_IcssPdInfo* pdInfo); /* misra warning */
static void NIMU_ICSS_initConfig(NIMU_IcssDevice* nimuDevice,NIMU_IcssPdInfo* pdInfo)
{

    int32_t               i;
    NIMU_IcssAddrConfig     addrCfg;

    nimuDevice->PktMTU = 1518U;
    nimuDevice->pfcbRxPacket = &NIMU_ICSS_rxPacket;
    nimuDevice->aleTicks=(NIMU_ICSS_ALE_AGE_OUT_TIME / 100U);
    nimuDevice->aleTimerActive=0;
    nimuDevice->nimuPdInfo = pdInfo;

    nimuDevice->nimuPktRx = (NIMU_IcssEmacPkt*)mmAlloc(sizeof(NIMU_IcssEmacPkt));
    nimuDevice->nimuPktTx = (NIMU_IcssEmacPkt*)mmAlloc(sizeof(NIMU_IcssEmacPkt));

    ((ICSS_EmacObject*)(pdInfo->nimuDrvHandle)->object)->pvtInfo = nimuDevice;

    for (i=0; i<6; i++)
    {
        addrCfg.Addr[i] = ((((ICSS_EmacObject*)(pdInfo->nimuDrvHandle)->object)->emacInitcfg)->macId)[i];
    }

    /* Copy the MAC Address into the PDI Structure */
     mmCopy ((void *)&(pdInfo->bMacAddr[0]), (void *)&addrCfg.Addr[0], 6U);
    return;
}


/**
* @brief Opens and configures EMAC. Configures Interrupts
* @internal
* @param pi  NIMU_IcssPdInfo structure pointer.
*
* @retval Success(0) or failure(Error Codes defined)
*/
int32_t NIMU_ICSS_open(NIMU_IcssPdInfo *pi ); /* misra warning */
int32_t NIMU_ICSS_open(NIMU_IcssPdInfo *pi )
{
    int32_t retVal;
    NIMU_IcssDevice* nCfg;
    ICSS_EmacHandle handle = pi->nimuDrvHandle;
    nCfg = (NIMU_IcssDevice*)mmAlloc(sizeof(NIMU_IcssDevice));

    uint32_t statsSize = sizeof(NIMU_IcssStatistics);

    /* Initialize EMAC setup  */
    NIMU_ICSS_initConfig(nCfg,pi);
    uint8_t numPorts = 1U;

    ICSS_EmacRegisterHwIntRx(handle, (ICSS_EmacCallBack)NIMU_ICSS_interruptRx);

    if(ICSS_EMAC_MODE_SWITCH == ((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->emacInitcfg->portMask)
    {
        numPorts = 2U + 1U;
    }
    else
    {
        numPorts =1U + 1U;
    }
    nCfg->nimuStat = (NIMU_IcssStatistics*)(mmAlloc(statsSize * numPorts));
    

    retVal = NIMU_ICSS_interruptInit(pi);
    if (retVal == 0)
    {
        /* Initialize packet structure for Rx */
        NIMU_ICSS_packetInit(nCfg->nimuPktRx);

        NIMU_ICSS_openPeripheral(pi);
        pi->TxFree = 1;
        EnableEMACInterrupts(pi);
    }
    return (retVal);
}

/**
* @brief Closes EMAC and disables interrupts.
* @internal
* @param pi  NIMU_IcssPdInfo structure pointer.
*
* @retval none
*/
void NIMU_ICSS_close( NIMU_IcssPdInfo *pi ); /* misra warning */
void NIMU_ICSS_close( NIMU_IcssPdInfo *pi )
{
    NIMU_IcssDevice* nCfg;
    nCfg = (NIMU_IcssDevice*)(((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->pvtInfo);

    NIMU_ICSS_interruptDisable(pi);

    NIMU_ICSS_interruptEnd(pi);

    NIMU_ICSS_closePeripheral(pi );
    if (nCfg)
    {
        mmFree(nCfg->nimuStat);
        mmFree(nCfg->nimuPktRx);
        mmFree(nCfg->nimuPktTx);
        mmFree(nCfg);
    }
}

/**
* @brief Routine to send out a packet.
* @internal
* @param pi  NIMU_IcssPdInfo structure pointer.
*
* @retval none
*/
void NIMU_ICSS_pktTxNext( NIMU_IcssPdInfo *pi ); /* misra warning */
void NIMU_ICSS_pktTxNext( NIMU_IcssPdInfo *pi )
{
    PBM_Handle          hPkt;
    NIMU_IcssEmacPkt*            csl_send_pkt;
    NIMU_IcssDevice* nimuDevice = (NIMU_IcssDevice*)(((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->pvtInfo);

    hPkt = PBMQ_deq(&pi->PBMQ_tx);
    if (hPkt)
    {
        csl_send_pkt = nimuDevice->nimuPktTx;
        csl_send_pkt->AppPrivate     = (uint32_t)hPkt;
        csl_send_pkt->pDataBuffer    = PBM_getDataBuffer(hPkt);
        csl_send_pkt->BufferLen      = PBM_getBufferLen(hPkt);
        csl_send_pkt->Flags          = NIMU_ICSS_EMAC_PKT_FLAGS_SOP | NIMU_ICSS_EMAC_PKT_FLAGS_EOP;
        csl_send_pkt->ValidLen       = PBM_getValidLen(hPkt);
        csl_send_pkt->DataOffset     = PBM_getDataOffset(hPkt);
        csl_send_pkt->PktChannel     = 0;
        csl_send_pkt->PktLength      = PBM_getValidLen(hPkt);
        csl_send_pkt->PktFrags       = (uint32_t)1U;
    
        NIMU_ICSS_sendPacket(pi->nimuDrvHandle, csl_send_pkt);
        PBM_free( (PBM_Handle)hPkt );
    }
}

/**
* @brief Low level driver Ioctl interface. This interface can be used for
*  ALE configuration,control,statistics
*
* @internal
* @param pi  NIMU_IcssPdInfo structure pointer.
* @param cmd Ioctl command.
* @param pBuf Ioctl buffer with commands and params to set/get  configuration from hardware.
* @param size Size of Ioctl buffer
*
* @retval none
*/
int32_t NIMU_ICSS_pktIoctl(NIMU_IcssPdInfo *pi, uint32_t cmd, void* param, uint32_t size); /* misra warning */
int32_t NIMU_ICSS_pktIoctl(NIMU_IcssPdInfo *pi, uint32_t cmd, void* param, uint32_t size)
{
    int32_t  retVal = 0;
    uint32_t retVal1 = 0U;
    switch(cmd)
    {
        case ICSS_IOCTL_SWITCH_CMD:
        {
            retVal1 = NIMU_ICSS_setConfig(pi, param, size);
            if( retVal1 != NIMU_ICSS_SUCCESS)
            {
                retVal = -1;
            }
            break;
        }
        case ICSS_IOCTL_STAT_CMD:
        {
            /* handle STATs related IOCTL here */
            NIMU_IcssStatsCmd *statsCommand = (NIMU_IcssStatsCmd*) param;
            switch(statsCommand->opcode)
            {
                case ICSS_IOCTL_STAT_CLEAR:
                {
                    NIMU_ICSS_clearStatistics(pi ,statsCommand->portNum);
                    break;
                }
                case ICSS_IOCTL_STAT_GET:
                {
                    NIMU_ICSS_getStatistics(pi, &(statsCommand->statsObj),statsCommand->portNum);
                    break;
                }
                default:
                {
                    break;
                }
            }
            retVal = 0;
           break;
        }
        default:
        {
            retVal = -1;
            break;
        }
    }
    return retVal;
}

/**
* @brief This function is called at least every 100ms, faster in a
*      polling environment. The fTimerTick flag is set only when
*      called on a 100ms event.
* @internal
*
* @param pi  NIMU_IcssPdInfo structure pointer.
* @param fTimerTick Flag for timer, set when called on a 100ms event..
*
* @retval none
*/
void NIMU_ICSS_pktPoll( NIMU_IcssPdInfo *pi, uint32_t fTimerTick ); /* misra warning */
void NIMU_ICSS_pktPoll( NIMU_IcssPdInfo *pi, uint32_t fTimerTick )
{

    static uint32_t   aleTickCount = 0;
    ICSSEMAC_IoctlCmd ioctlParams;

    NIMU_IcssDevice *nimuDevice = (NIMU_IcssDevice*)(((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->pvtInfo);
    stormPrevention_t* strmPreventionEnable1=NULL;
    stormPrevention_t* strmPreventionEnable2=NULL;
    if( fTimerTick )
    {
        /*Different protocols require periodic processing*/
        if(periodicProtTask)
        {
            periodicProtTask(periodicProtUser, NULL);
        }


        if(ICSS_EMAC_MODE_SWITCH == ((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->emacInitcfg->portMask)
        {
            if((((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->emacInitcfg)->learningEn)
            {
                /*Increment counter in learning for ageing*/
                ioctlParams.command = ICSS_EMAC_LEARN_CTRL_INC_COUNTER;
                ICSS_EmacIoctl(pi->nimuDrvHandle, ICSS_EMAC_IOCTL_LEARNING_CTRL, 0, (void*)&ioctlParams);

                if( (0u != nimuDevice->aleTimerActive) && (0 != nimuDevice->aleTicks))
                {
                    /* Ageoutnow. aleTickCount can become greater if timeout period is changed in between */
                    aleTickCount = aleTickCount + 1U;
                    if( (aleTickCount) >=  (nimuDevice->aleTicks))
                    {
                        ioctlParams.command = ICSS_EMAC_LEARN_CTRL_AGEING;
                        ICSS_EmacIoctl(pi->nimuDrvHandle, ICSS_EMAC_IOCTL_LEARNING_CTRL, ICSS_EMAC_PORT_1, (void*)&ioctlParams);
                        ICSS_EmacIoctl(pi->nimuDrvHandle, ICSS_EMAC_IOCTL_LEARNING_CTRL, ICSS_EMAC_PORT_2, (void*)&ioctlParams);
                        aleTickCount = 0;
                    }
                }
            }
        }

        
        /*Reset the credit values used for Storm prevention*/
        if(ICSS_EMAC_MODE_SWITCH == ((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->emacInitcfg->portMask)
        {
            strmPreventionEnable1 = (stormPrevention_t*)(((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->stormPrevPtr);
            strmPreventionEnable2 = ((stormPrevention_t*)(((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->stormPrevPtr)) + 1;
            if((strmPreventionEnable1->suppressionEnabledBC) | (strmPreventionEnable2->suppressionEnabledBC))
            {
                ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_RESET_BC;
                ICSS_EmacIoctl(pi->nimuDrvHandle, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, 0, (void*)&ioctlParams);
            }
            if((strmPreventionEnable1->suppressionEnabledMC) | (strmPreventionEnable2->suppressionEnabledMC))
            {
                ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_RESET_MC;
                ICSS_EmacIoctl(pi->nimuDrvHandle, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, 0, (void*)&ioctlParams);
            }
            if((strmPreventionEnable1->suppressionEnabledUC) | (strmPreventionEnable2->suppressionEnabledUC))
            {
                ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_RESET_UC;
                ICSS_EmacIoctl(pi->nimuDrvHandle, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, 0, (void*)&ioctlParams);
            }
        }
        else
        {
            strmPreventionEnable1 = (stormPrevention_t*)(((ICSS_EmacObject*)(pi->nimuDrvHandle)->object)->stormPrevPtr);         
            if(strmPreventionEnable1->suppressionEnabledBC)
            {
                ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_RESET_BC;
                ICSS_EmacIoctl(pi->nimuDrvHandle, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, (uint8_t)(pi->PhysIdx + 1U), (void*)&ioctlParams);
            }           
            if(strmPreventionEnable1->suppressionEnabledMC)
            {
                ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_RESET_MC;
                ICSS_EmacIoctl(pi->nimuDrvHandle, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, (uint8_t)(pi->PhysIdx + 1U), (void*)&ioctlParams);
            }
            if(strmPreventionEnable1->suppressionEnabledUC)
            {
                ioctlParams.command = ICSS_EMAC_STORM_PREV_CTRL_RESET_UC;
                ICSS_EmacIoctl(pi->nimuDrvHandle, ICSS_EMAC_IOCTL_STORM_PREV_CTRL, (uint8_t)(pi->PhysIdx + 1U), (void*)&ioctlParams);
            }
        }
    }
}

void NIMU_ICSS_interruptRx(void* queueNum,void* handle); /* misra warning */
void NIMU_ICSS_interruptRx(void* queueNum,void* handle)
{
    uint32_t i;
    int32_t *prioQ = (int32_t*) queueNum;
    i = NIMU_ICSS_rxServiceCheck((ICSS_EmacHandle)handle,*prioQ);
    if( i )
    {
        if (i == NIMU_ICSS_INTERNAL_FAILURE)
        {
            emac_fatal_error++;
        }
    }
}

/**
* @brief Function to register callback function to process periodic protocol processing
*
* @param callBack    Callback function pointer
* @param userArg    user specific parameter
*
* @retval none
*/
void NIMU_ICSS_registerPeriodicCb(ICSS_EmacCallBack callBack, void *userArg); /* misra warning */
void NIMU_ICSS_registerPeriodicCb(ICSS_EmacCallBack callBack, void *userArg)
{
    periodicProtTask = callBack;
    periodicProtUser = userArg;
}

