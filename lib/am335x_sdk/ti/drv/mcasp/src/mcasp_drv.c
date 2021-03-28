/*
 * mcasp_drv.c
 *
 * This file contains Driver Layer Interface implementation for the McASP Driver.
 * McASP Driver provides Driver Layer Interface to do operations on the McASP
 * peripheral like device initialization, channel creation, control commands for
 * peripheral specific operations etc
 *
 * Copyright (C) 2009-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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

/**
 * \file      mcasp_drv.c
 *
 * \brief     Generic McASP Driver for SYS/BIOS Platform.It uses the EDMA for
 *            data transfer.
 *
 *
 *            (C) Copyright 2008, Texas Instruments, Inc
 *
 *
 * \version
 *             0.2  [25-06-2008]  Added the support for non loop job mode
 *             0.1  [17-06-2008]  Created newly.
 *
 */

/* ========================================================================== */
/*                          INCLUDE FILES                                     */
/* ========================================================================== */


#include <ti/drv/mcasp/mcasp_drv.h>
#include <ti/drv/mcasp/mcasp_osal.h>
#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include <ti/drv/mcasp/include/McaspLocal.h>

#include "string.h"
/* -------- constants -------- */

const struct Mcasp_Params_s Mcasp_PARAMS = {
    TRUE,  /* enablecache */
    FALSE,  /* isDataBufferPayloadStructure */
    {
        {
            (uint32_t)0x0,  /* pfunc   */
            (uint32_t)0x1,  /* pdir    */
            (uint32_t)0x0,  /* ctl     */
            (uint32_t)0x0,  /* ditCtl  */
            (uint32_t)0x0,  /* dlbMode */
            (uint32_t)0x2,  /* amute   */
            {
                (uint32_t)0x0,  /* [0] */
                (uint32_t)0x0,  /* [1] */
                (uint32_t)0x0,  /* [2] */
                (uint32_t)0x0,  /* [3] */
                (uint32_t)0x0,  /* [4] */
                (uint32_t)0x0,  /* [5] */
                (uint32_t)0x0,  /* [6] */
                (uint32_t)0x0,  /* [7] */
                (uint32_t)0x0,  /* [8] */
                (uint32_t)0x0,  /* [9] */
                (uint32_t)0x0,  /* [10] */
                (uint32_t)0x0,  /* [11] */
                (uint32_t)0x0,  /* [12] */
                (uint32_t)0x0,  /* [13] */
                (uint32_t)0x0,  /* [14] */
                (uint32_t)0x0,  /* [15] */
            },  /* serSetup */
        },  /* glb */
        {
            (uint32_t)0xffffffffU,  /* mask */
            (uint32_t)0x0,  /* fmt */
            (uint32_t)0x0,  /* frSyncCtl */
            (uint32_t)0x1,  /* tdm */
            (uint32_t)0x0,  /* intCtl */
            (uint32_t)0x1ff,  /* stat */
            (uint32_t)0x0,  /* evtCtl */
            {
                (uint32_t)0x3,  /* clkSetupClk */
                (uint32_t)0x8046,  /* clkSetupHiClk */
                (uint32_t)0x0,  /* clkChk */
            },  /* clk */
        },  /* rx */
        {
            (uint32_t)0xffffffffU,  /* mask */
            (uint32_t)0x0,  /* fmt */
            (uint32_t)0x2,  /* frSyncCtl */
            (uint32_t)0x1,  /* tdm */
            (uint32_t)0x0,  /* intCtl */
            (uint32_t)0x1ff,  /* stat */
            (uint32_t)0x0,  /* evtCtl */
            {
                (uint32_t)0x23,  /* clkSetupClk */
                (uint32_t)0x8046,  /* clkSetupHiClk */
                (uint32_t)0x0,  /* clkChk */
            },  /* clk */
        },  /* tx */
        (uint32_t)0x1,  /* emu */
    },  /* mcaspHwSetup */
    FALSE                 /* pscPwrmEnable  */
};

/* ========================================================================== */
/*                       GLOBAL MODULE STATE                                  */
/* ========================================================================== */
/**
 *  \brief  Array which is part of Mcasp Module State
 *
 */
  Bool inUse[MCASP_CNT];

/*
 * \brief  Array to contain the Isr related information for all instances.
 */
  Mcasp_IsrObject isrInstanceObject[MCASP_CNT];

/**
 *  \brief  Mcasp Module State Object
 */
  Mcasp_Module_State Mcasp_module = {&inUse[0],&isrInstanceObject[0]};

/**
 *  \brief  Array of Mcasp instance State objects array
 */
  Mcasp_Object Mcasp_Instances[MCASP_CNT];

/**
 * \brief  Global array of Hwi handles;
 */
static McaspOsal_IntrHandle gHwiHandle[MCASP_CNT][2];

/**
 *  \brief  Array for device information per instance
 */
Mcasp_HwInfo Mcasp_deviceInstInfo[MCASP_CNT];


#ifdef Mcasp_LOOPJOB_ENABLED
/**
 *  \brief  Destination loop buffer per instance
 *
 * \note   Buffer used during the loop job mode for the Transmit section
 */
Mcasp_TempBuffer          Mcasp_loopDstBuf[MCASP_CNT];
/**
 * \brief  Receive loop buffer per instance
 *
 * \note   Buffer used during the loop job mode for the Receive section
 */
Mcasp_TempBuffer          Mcasp_loopSrcBuf[MCASP_CNT];
#endif /* Mcasp_LOOPJOB_ENABLED */
/**
 *  \brief  Mute buffer per instance
 */
Mcasp_TempBuffer Mcasp_muteBuf[MCASP_CNT];

/* ========================================================================== */
/*                        LOCAL FUNCTION PROTOTYPES                           */
/* ========================================================================== */

void mcaspInit(uint32_t instNum);

void mcaspIsr(void * arg);

void mcaspIsrInput(void * chanp);

void mcaspIsrOutput(void * chanp);

void mcaspUnRegisterInt(uint16_t devid, int32_t evt, int32_t intNum, int32_t mode);

void mcaspBitSetGblCtl(const Mcasp_Object *instHandle,uint32_t bitMaskVal);

void mcaspBitSetGblXCtl(const Mcasp_Object *instHandle, uint32_t bitMaskVal);

void mcaspBitRemoveGblRCtl(const Mcasp_Object *instHandle, uint32_t bitMaskVal);

void mcaspBitRemoveGblXCtl(const Mcasp_Object *instHandle, uint32_t bitMaskVal);

void mcaspMultiSerGlobalRestore(void* chanp);

void mcaspBitSetGblRCtl(const Mcasp_Object *instHandle,uint32_t bitMaskVal);

int32_t mcaspSubmitReq(Mcasp_ChannelHandle chanHandle,
                        MCASP_Packet         *ioPacket);

void mcaspRegisterInt(void*                   chanp,
                         uint32_t                instNum,
                         int32_t                evt,
                         int32_t   intNum,
                         void * intIsr);

void mcaspSetSerXmt(Mcasp_HwHandle       hMcasp,
                        Mcasp_SerializerNum  serNum);

void mcaspSetSerRcv(Mcasp_HwHandle       hMcasp,
                        Mcasp_SerializerNum  serNum);

int32_t mcaspSetDitMode(Mcasp_HwHandle hMcasp,
                         Bool           ditFlag);

Bool mcaspIsRequestedSerzsFree(const Mcasp_Object *instHandle,
                                  void*           params);

int32_t mcaspSetDitMode(Mcasp_HwHandle hMcasp,
                         Bool           ditFlag);

void mcaspMultiSerInitializationRcv(Mcasp_Object *instHandle,
                                       void*           params);

void mcaspMultiSerInitializationXmt(Mcasp_Object *instHandle,
                                       void*           params);

int32_t mcaspConfigureXmtChannel(Mcasp_Object *instHandle,
                                  void*           params);

int32_t mcaspConfigureRcvChannel(Mcasp_Object *instHandle,
                                  void*           params);

int32_t mcaspWriteChanStatRam(Mcasp_HwHandle      hMcasp,
                               Mcasp_ChStatusRam  *const chanStatRam);

int32_t mcaspWriteUserDataRam(Mcasp_HwHandle      hMcasp,
                               Mcasp_UserDataRam  *const userDataRam);

void mcaspConfigureFifo(const Mcasp_HwObj         *hMcasp,
                        const Mcasp_ChannelObj    *chanHandle,
                        Bool                       enableHwFifo);

int32_t  mcaspValidateBufferConfig(Mcasp_ChannelHandle  chanHandle,
                                    Mcasp_ChanParams    *const params);

void Mcasp_localIsrSwiFxn(void * arg0,void * arg1);

#if defined(BIOS_PWRM_ENABLE)
int32_t McaspRegisterNotification(Mcasp_Object *instHandle);

int32_t McaspUnregisterNotification(Mcasp_Object *instHandle);

int32_t McaspUnregisterConstraints(Mcasp_Object *instHandle);

Power_NotifyResponse McaspNotifyCallback(Power_Event    eventType,
                                           void *           eventArg1,
                                           void *           eventArg2,
                                           void *           clientArg);

Power_NotifyResponse McaspSuspendCurrentIops(Mcasp_Object  *instHandle,
                                               Power_Event     eventType);

int32_t McaspUnregisterConstraints(Mcasp_Object *instHandle);

#endif
int32_t mcaspDeleteChan(void* chanp);

#ifndef Mcasp_LOOPJOB_ENABLED
void Mcasp_swiTxFifo(void * arg0,void * arg1);
#endif

static void Mcasp_enableInterrupt(int32_t cpuEventNum,int32_t intNum);
static void Mcasp_disableInterrupt(int32_t cpuEventNum,int32_t intNum);

/* ========================================================================== */
/*                            GLOBAL VARIABLES                                */
/* ========================================================================== */


/* ========================================================================== */
/*                          FUNCTION DEFINTIONS                               */
/* ========================================================================== */

/* ========================================================================== */
/*                           MODULE FUNCTIONS                                 */
/* ========================================================================== */


/*
 *  \brief  Function called by Bios during instance initialisation
 *
 *  \param  devp        [OUT] pointer to hold the device Handle
 *  \param  devId       [IN]  Instance number of the Mcasp to create
 *  \param  devParams   [IN]  Pointer to the user supplied device parameters
 *
 *  \return MCASP_COMPLETED    if success
 *          Error ID         in case of error
 *
 */
  int32_t mcaspBindDev(void* *devp, int32_t devId, void* devParams)
{
    Mcasp_Object   *instHandle = NULL;
    Mcasp_Params   *params     = NULL;
    int32_t           status     = MCASP_COMPLETED;
    uint32_t          count      = 0;
    uint32_t          key        = 0;
    /* Swi_Params      swiParams  = {0}; */

    if (NULL == devParams)
    {
        params = (Mcasp_Params*)&Mcasp_PARAMS;
    }
    else
    {
        params = (Mcasp_Params*) devParams;
    }

/* Begin parameter checking                                                   */
#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
    if (((int32_t)MCASP_CNT) <= devId)
    {
        status = MCASP_EBADARGS;
    }

    if (MCASP_COMPLETED == status)
    {
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */
        instHandle =  &Mcasp_Instances[devId];
#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
        if (TRUE == Mcasp_module.inUse[devId])
        {
            status = MCASP_EBADARGS;
        }
    }
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */
/* End parameter checking                                                     */

    if (MCASP_COMPLETED == status)
    {
        /* critical section starts                                            */
        key = HwiP_disable();

        Mcasp_module.inUse[devId] = (Bool)TRUE;
        instHandle->devState = Mcasp_DriverState_CREATED;

        /* critical section ends                                              */
        HwiP_restore(key);

        /* initialise the data structures                                     */
        instHandle->instNum       = (uint16_t)devId;
        instHandle->enablecache   = (Bool)(params->enablecache);
        instHandle->pscPwrmEnable = (Bool)(params->pscPwrmEnable);

        /* stop the state machine of RX and TX                                */
        instHandle->stopSmFsXmt = (Bool)TRUE;
        instHandle->stopSmFsRcv = (Bool)TRUE;

        instHandle->retryCount = Mcasp_POLLED_RETRYCOUNT;

        instHandle->isDataBufferPayloadStructure =
            (Bool)(params->isDataBufferPayloadStructure);

        /* configure the mcasp hardware info                                  */
        instHandle->mcaspHwSetup = params->mcaspHwSetup;

        /* copy the soc related information                                   */
        /** Todo: merge Mcasp_HwObj and Mcasp_HwInfo since they are redundant */
        memcpy(&instHandle->hwInfo, &Mcasp_deviceInstInfo[devId], sizeof(Mcasp_HwInfo));

        /* configure the default values for the transmit channel              */
        instHandle->XmtObj.chanState = Mcasp_DriverState_CLOSED;
        instHandle->XmtObj.mode  = (uint32_t)MCASP_OUTPUT;
        instHandle->XmtObj.devHandle = instHandle;
        instHandle->XmtObj.cbFxn = NULL;
        instHandle->XmtObj.cbArg = NULL;
        Osal_Queue_construct(&(instHandle->XmtObj.queueReqList), (void *)NULL);
        Osal_Queue_construct(&(instHandle->XmtObj.queueFloatingList), (void *)NULL);
        instHandle->XmtObj.noOfSerAllocated = 0;
        instHandle->XmtObj.channelOpMode = Mcasp_ChanMode_XMT_DIT;
        instHandle->XmtObj.isDmaDriven = (Bool)TRUE;
        instHandle->XmtObj.dataQueuedOnReset = 0;
        instHandle->XmtObj.intStatus = 0;
        instHandle->XmtObj.dataPacket = NULL;
        instHandle->XmtObj.tempPacket = NULL;
        instHandle->XmtObj.isTempPacketValid = (Bool)FALSE;
        instHandle->XmtObj.userDataBufferSize = 0;
        instHandle->XmtObj.submitCount = -1;
        instHandle->XmtObj.loopjobUpdatedinParamset = (Bool)FALSE;
        instHandle->XmtObj.cpuEventNum = 0;
        instHandle->XmtObj.intNum = -1;
        instHandle->XmtObj.xferinProgressIntmode = (Bool)FALSE;
        instHandle->XmtObj.loopJobBuffer = NULL;
        instHandle->XmtObj.loopJobLength = 0;
        instHandle->XmtObj.roundedWordWidth = 0;
        instHandle->XmtObj.currentDataSize =0;
        instHandle->XmtObj.bMuteON = (Bool)FALSE;
        instHandle->XmtObj.paused = (Bool)FALSE;
        instHandle->XmtObj.gblErrCbk  = NULL;
        instHandle->XmtObj.enableHwFifo = (Bool)TRUE;
        instHandle->XmtObj.hwFifoEventDMARatio=1;
        instHandle->XmtObj.nextFlag = (Bool)FALSE;
        instHandle->XmtObj.currentPacketErrorStatus = MCASP_COMPLETED;
        instHandle->XmtObj.noOfSlots = 0;
        instHandle->XmtObj.isDataPacked = (Bool)FALSE;
        instHandle->XmtObj.dataFormat = Mcasp_BufferFormat_1SER_1SLOT;
        instHandle->XmtObj.userLoopJob = (Bool)FALSE;
        instHandle->XmtObj.userIntValue = 0x00000003;
        instHandle->XmtObj.wordBitsSelect = Mcasp_WordBitsSelect_LSB;
        instHandle->XmtObj.frSyncCtl = 0;
        instHandle->XmtObj.fmt = 0;        
        instHandle->XmtObj.channelMode = Mcasp_OpMode_TDM;
        instHandle->XmtObj.noOfChannels = 0;

        /* Initialize the Tx DMA parameters */
        Mcasp_initChanDmaObj(&instHandle->XmtObj);

        instHandle->RcvObj.chanState = Mcasp_DriverState_CLOSED;
        instHandle->RcvObj.mode   = (uint32_t)MCASP_INPUT;
        instHandle->RcvObj.devHandle = instHandle;
        instHandle->RcvObj.cbFxn  = NULL;
        instHandle->RcvObj.cbArg  = NULL;
        Osal_Queue_construct(&(instHandle->RcvObj.queueReqList), (void *) NULL);
        Osal_Queue_construct(&(instHandle->RcvObj.queueFloatingList), (void *) NULL);
        instHandle->RcvObj.noOfSerAllocated = 0;
        instHandle->RcvObj.channelOpMode = Mcasp_ChanMode_RCV;
        instHandle->RcvObj.isDmaDriven = (Bool)TRUE;
        instHandle->RcvObj.dataQueuedOnReset =0;
        instHandle->RcvObj.intStatus = 0;
        instHandle->RcvObj.dataPacket = NULL;
        instHandle->RcvObj.tempPacket = NULL;
        instHandle->RcvObj.isTempPacketValid = (Bool)FALSE;
        instHandle->RcvObj.userDataBufferSize = 0;
        instHandle->RcvObj.submitCount = -1;
        instHandle->RcvObj.loopjobUpdatedinParamset = (Bool)FALSE;
        instHandle->RcvObj.cpuEventNum = 0;
        instHandle->RcvObj.intNum = -1;
        instHandle->RcvObj.xferinProgressIntmode = (Bool)FALSE;
        instHandle->RcvObj.loopJobBuffer = NULL;
        instHandle->RcvObj.loopJobLength = 0;
        instHandle->RcvObj.roundedWordWidth = 0;
        instHandle->RcvObj.currentDataSize =0;
        instHandle->RcvObj.bMuteON = (Bool)FALSE;
        instHandle->RcvObj.paused = (Bool)FALSE;
        instHandle->RcvObj.gblErrCbk  = NULL;
        instHandle->RcvObj.enableHwFifo = (Bool)TRUE;
        instHandle->RcvObj.hwFifoEventDMARatio=1;
        instHandle->RcvObj.nextFlag = (Bool)FALSE;
        instHandle->RcvObj.noOfSlots = 0;
        instHandle->RcvObj.isDataPacked = (Bool)FALSE;
        instHandle->RcvObj.dataFormat = Mcasp_BufferFormat_1SER_1SLOT;
        instHandle->RcvObj.currentPacketErrorStatus = MCASP_COMPLETED;
        instHandle->RcvObj.userLoopJob = (Bool)FALSE;
        instHandle->RcvObj.userLoopJobLength = 0;
        instHandle->RcvObj.userIntValue      = 0x00000003;
        instHandle->RcvObj.wordBitsSelect = Mcasp_WordBitsSelect_LSB;
        instHandle->RcvObj.frSyncCtl = 0;
        instHandle->RcvObj.fmt = 0;        
        instHandle->RcvObj.channelMode = Mcasp_OpMode_TDM;
        instHandle->RcvObj.noOfChannels = 0;

        /* Initialize the Rx DMA parameters */
        Mcasp_initChanDmaObj(&instHandle->RcvObj);

        for (count = 0; count < Mcasp_NUMSERIALIZERS; count++)
        {
            instHandle->serStatus[count] = Mcasp_SerializerStatus_FREE;
            instHandle->XmtObj.indexOfSersRequested[count] = 0;
            instHandle->RcvObj.indexOfSersRequested[count] = 0;
        }

#ifdef Mcasp_LOOPJOB_ENABLED
        /* driver is compiled in loop Job mode                                */
        instHandle->loopJobMode = (Bool) TRUE;

        if ((Bool) TRUE == instHandle->pscPwrmEnable)
        {
            /* power management not supported for loop job mode               */
            status = MCASP_EBADMODE;
        }
#else
        instHandle->loopJobMode = (Bool)FALSE;

#endif
        if ((MCASP_COMPLETED == status) &&
            (FALSE == instHandle->pscPwrmEnable))
        {
#ifdef BIOS_PWRM_ENABLE
            /* power on using bios PWRM API                                   */
            status = (int32_t)Power_setDependency(
                                (Power_Resource)instHandle->hwInfo.pwrmLpscId);
#else
            /* power on using PSC API                                         */
#if 0
            status = Psc_ModuleClkCtrl(
                         (Psc_DevId)instHandle->hwInfo.pscInstance,
                         (uint32_t)instHandle->hwInfo.pwrmLpscId,
                         TRUE);
#endif
#endif
        }

#if defined (BIOS_PWRM_ENABLE) && !defined (Mcasp_LOOPJOB_ENABLED)
        if ((MCASP_COMPLETED == status) && (TRUE == instHandle->pscPwrmEnable))
        {
            memset(&instHandle->pwrmInfo,0x00,sizeof(Mcasp_pwrmInfo));

            /* register the notify function for the PWRM events               */
            status = McaspRegisterNotification(instHandle);
        }
#endif

        if (MCASP_COMPLETED == status)
        {
            /* power on the module                                            */
            status = Mcasp_localLpscOn(instHandle);

            if (MCASP_COMPLETED == status)
            {
                status  = Mcasp_localSetupHwInfo(
                    &instHandle->hwInfo,
                    &instHandle->mcaspHwSetup);

                status = Mcasp_localLpscOff(instHandle);
            }
        }

        /* we need to check if any one of the instance has the Swi created    *
         * else we will create the swi here                                   */
        for (count = 0U; count < MCASP_CNT; count++)
        {
            if (NULL != Mcasp_module.isrObject[count].isrSwiTaskHandle)
            {
                break;
            }
        }

#ifdef BIOS_SWI
        if (count == MCASP_CNT)
        {
            Swi_Params_init(&swiParams);
            
            /* modify the default parameters with the required params         */
            swiParams.priority = Mcasp_SWI_PRIORITY;

            /* create the swi that will be used for ISR handling              */
            Swi_construct(&(instHandle->isrSwiObject), 
                          &Mcasp_localIsrSwiFxn, &swiParams,
                          NULL);
            
            /* copy the swi Handle information to all the module objects      */
            for (count = 0; count < MCASP_CNT; count++)
            {
                Mcasp_module.isrObject[count].isrSwiTaskHandle = \
                    Swi_handle(&instHandle->isrSwiObject);
            }
        }

        instHandle->isrSwiObject = \
            *Swi_struct(Mcasp_module.isrObject[devId].isrSwiTaskHandle);
#endif
        if (MCASP_COMPLETED == status)
        {
#ifndef Mcasp_LOOPJOB_ENABLED
            instHandle->loopJobMode = (Bool) FALSE;
#ifdef BIOS_SWI
            Swi_Params_init(&swiParams);

            /* create the swi to handle the TX FIFO empty case handling       */
            swiParams.priority = Mcasp_SWI_PRIORITY;
            swiParams.arg0     = (void *) & instHandle->XmtObj;
            swiParams.arg1     = (void *) instHandle;

            Swi_construct(&(instHandle->fifoSwiObject),
                          (Swi_FuncPtr) & Mcasp_swiTxFifo, &swiParams, NULL);
#endif
#endif
        }

        if (MCASP_COMPLETED == status)
        {
             instHandle->devState = Mcasp_DriverState_CREATED;
            *devp = (void*)instHandle;
        }
        else
        {
            *devp = NULL;
        }
    }
    return (status);
}

/**
 *  \brief  Closes the McASP device from use.
 *
 *  This function is called when an previously opened channel is to be closed.
 *  it unallocates all the resources allocated during the instance creation
 *  and marks the instance as free for allocation
 *
 *  \param  devp  [IN]  Device handle (returned during device creation)
 *
 *  \return MCASP_COMPLETED   if successful
 *          IOM error       if not successful
 *
 */
  int32_t mcaspUnBindDev(void* devp)
{
    Mcasp_Object       *instHandle = NULL;
    int32_t               retVal     = MCASP_COMPLETED;
    uint32_t       key        = 0;
#ifdef BIOS_SWI
    uint32_t        devId       = 0;
    Bool          destructSwi = (Bool) TRUE;
#endif

/* Begin parameter checking                                                   */
#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
    if (NULL == devp)
    {
        retVal = MCASP_EBADARGS;
    }
    else
    {
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */
        instHandle = (Mcasp_Object *)devp;
#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
        if ((MCASP_CNT <= instHandle->instNum)                  ||
            (Mcasp_DriverState_CLOSED != instHandle->XmtObj.chanState)  ||
            (Mcasp_DriverState_CLOSED != instHandle->RcvObj.chanState))
        {
            retVal = MCASP_EBADARGS;
        }
    }
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */
/* End parameter checking                                                     */

    if (MCASP_COMPLETED == retVal)
    {
        /* Close and free mcasp port handle                                   */
        if (NULL != &(instHandle->hwInfo))
        {
            instHandle->hwInfo.regs    = 0;
            instHandle->hwInfo.numOfSerializers = 0;
            instHandle->hwInfo.ditStatus = (Bool)FALSE;
        }

        /* critical section starts                                            */
        key = HwiP_disable();
        /* Mark driver state as deleted and module as not in use              */
        instHandle->devState = Mcasp_DriverState_DELETED;
        Mcasp_module.inUse[instHandle->instNum] = (Bool)FALSE;

#ifdef BIOS_SWI
        /* Check across all instances to see if any interrupts are still
         *registered */
        for (devId = (uint32_t) 0; devId < MCASP_CNT; devId++)
        {
            if (((Bool) FALSE != Mcasp_module.inUse[devId]))
            {
                destructSwi = (Bool) FALSE;
                break;
            }
        }

        /* Destruct Swi only if all interrupts are properly unregistered */
        if ((Bool) TRUE == destructSwi)
        {
            Swi_destruct(&(instHandle->isrSwiObject));
            for (devId = (uint32_t) 0; devId < MCASP_CNT; devId++)
            {
                 Mcasp_module.isrObject[devId].isrSwiTaskHandle = NULL;
             }
        }
#ifndef Mcasp_LOOPJOB_ENABLED
        Swi_destruct(&(instHandle->fifoSwiObject));
#endif
#endif
        /* critical section ends                                              */
        HwiP_restore(key);

        if (FALSE == instHandle->pscPwrmEnable)
        {
#ifdef BIOS_PWRM_ENABLE
            /* power on using bios PWRM API                                   */
            retVal = (int32_t)Power_releaseDependency(
                                (Power_Resource)instHandle->hwInfo.pwrmLpscId);
#else
            /* power on using PSC API                                         */
#if 0
            retVal = Psc_ModuleClkCtrl(
                         (Psc_DevId)instHandle->hwInfo.pscInstance,
                         (uint32_t)instHandle->hwInfo.pwrmLpscId,
                         FALSE);
#endif
#endif
        }

#if defined (BIOS_PWRM_ENABLE) && !defined (Mcasp_LOOPJOB_ENABLED)
        if ((MCASP_COMPLETED == retVal) && (TRUE == instHandle->pscPwrmEnable))
        {
            /* register the notify function for the PWRM events               */
            retVal = McaspUnregisterNotification(instHandle);
        }
#endif        
    }
    return (retVal);
}

/**
 *  \brief  Creates a communication channel in specified mode to communicate
 *          data between the application and the McASP device instance. This
 *          function sets the required hardware configurations for the data
 *          transactions.it returns configured channel handle to application.
 *          which will be used in all further transactions with the channel.
 *
 *          This function is called in response to a Stream_create call.
 *
 *          Pre-requisites:
 *          1.  Valid chanParams structure
 *              This takes much information pertaining to mcasp channel
 *              configuration such as how many serialisers are used for this
 *              channel what are they communication parameters,clock setting etc
 *          2.  Valid device pointer
 *
 *  \param  chanp        [IN]   Pointer to Mcasp driver object
 *  \param  devp         [IN]   Pointer to Mcasp device object
 *  \param  mode         [IN]   channel  mode -> input or output
 *  \param  chanParams   [IN]   channel parameters from user
 *  \param  cbFxn        [IN]   callback function pointer
 *  \param  cbArg        [IN]   callback function Arguments
 *
 *  \return MCASP_COMPLETED in case of success
 *          Error code  in case of failure
 *
 */
  int32_t mcaspCreateChan(   void*             *chanp,
                             void*              devp,
                             Mcasp_chanMode_e   mode,
                             void*              chanParams,
                             MCASP_TiomCallback cbFxn,
                             void*              cbArg)
{
    Mcasp_Object           *instHandle  = NULL;
    Mcasp_ChannelHandle     chanHandle  = NULL;
    Mcasp_ChanParams       *chanparam   = NULL;
    uint32_t                  key         = 0;
    uint8_t                   count       = 0;
    uint32_t                  mod         = 0;
    Bool                    falsewhile  = (Bool)TRUE;
    Bool                    pscPwrOn    = (Bool)FALSE;
    int32_t                 retVal      = MCASP_COMPLETED;
    uint16_t                tempRoundedWordWidth = 0;
    int32_t                 status      = MCASP_COMPLETED;


/* Begin parameter checking                                                   */
#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
    if (((NULL == chanParams)
        || (NULL == cbFxn)
        || (NULL == devp))
        || ((MCASP_INPUT != mode) && (MCASP_OUTPUT != mode)))
    {
        status = MCASP_EBADARGS;
    }
    else
    {
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */
        chanparam = (Mcasp_ChanParams *)chanParams;
#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
    }
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */
/* End parameter checking                                                     */

    if (MCASP_COMPLETED == status)
    {
        instHandle = (Mcasp_Object *)devp;
#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
        if ((NULL == instHandle->hwInfo.dmaHandle) && (TRUE == chanparam->isDmaDriven))
        {
            status = MCASP_EBADARGS;
#ifdef MCASP_EDMA_ENABLED
            /* Preserving legacy operation: old versions of the EDMA-based
             * driver allowed for EDMA handle to be passed in through the
             * channel parameters instead of the HW info.  If this is the case,
             * we allow for now and don't return a failure status for bad args.
             */
            if (NULL != chanparam->edmaHandle)
            {
                status = MCASP_COMPLETED;
            }
#endif
        }
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */

        /* check the current mode of operation and assign suitable handle */
        if (MCASP_INPUT == mode)
        {
            if((((Mcasp_ChannelHandle)&instHandle->RcvObj) == NULL) ||
                    (Mcasp_DriverState_OPENED == (instHandle->RcvObj).chanState))
            {
                status = MCASP_EBADARGS;
            }
        }
        else
        {
            if((((Mcasp_ChannelHandle)&instHandle->XmtObj) == NULL) ||
                    (Mcasp_DriverState_OPENED == (instHandle->XmtObj).chanState))
            {
                status = MCASP_EBADARGS;
            }
        }
    }

    if (MCASP_COMPLETED == status)
    {
        /* check if requested serialisers are more than device supports.  *
         * This is a first level check, later we check what serialisers   *
         *are remaining and if they match the requested serialisers number*/
        if ((chanparam->noOfSerRequested) >
            (instHandle->hwInfo.numOfSerializers))
        {
            status = MCASP_EBADARGS;
        }

        /* check if  mode (transmit or receive mode) is DIT or TDM        */
        if ((Mcasp_OpMode_TDM != chanparam->channelMode)
            && (Mcasp_OpMode_DIT != chanparam->channelMode))
        {
            status = MCASP_EBADARGS;
        }

        /* validate params for the DIT mode and set an error if incorrect */
        if ((Mcasp_OpMode_DIT == chanparam->channelMode)
            && ((MCASP_OUTPUT != mode)
            || (Mcasp_WordLength_32 != chanparam->wordWidth)))
        {
            status = MCASP_EBADARGS;
        }

        if ((Mcasp_OpMode_DIT == chanparam->channelMode)
            && (FALSE == instHandle->isDataBufferPayloadStructure))
        {
            status = MCASP_EBADARGS;
        }

        /* if this instance is not supporting DIT mode then return error  */
        if ((Mcasp_OpMode_DIT == chanparam->channelMode)
            && (FALSE == instHandle->hwInfo.ditStatus))
        {
            status = MCASP_EBADARGS;
        }

        /* Check requested serializers are free or not                    */
        if (FALSE == mcaspIsRequestedSerzsFree(instHandle, chanparam))
        {
            /* since serializers cannot be allocated, return error        */
            status = MCASP_EBADARGS;
        }
    }


    if (MCASP_COMPLETED == status)
    {
        do
        {
            falsewhile = (Bool)FALSE;

            /* power on the module                                            */
            status = Mcasp_localLpscOn(instHandle);

            if (MCASP_COMPLETED == status)
            {
                /* Able to power ON the module, hence then continue              */
                pscPwrOn = (Bool)TRUE;

                /* initialise buffers required by the mcasp for mute and loop job */
                mcaspInit((uint32_t)instHandle->instNum);

                /* check the current mode of operation and assign suitable handle */
                if (MCASP_INPUT == mode)
                {
                    chanHandle = (Mcasp_ChannelHandle)&instHandle->RcvObj;
                }
                else
                {
                    chanHandle = (Mcasp_ChannelHandle)&instHandle->XmtObj;
                }

                /* enter critical section and update the status of driver         */
                key = HwiP_disable();
            if (((NULL == chanHandle) ||
                 (Mcasp_DriverState_OPENED == chanHandle->chanState)) &&
                (MCASP_COMPLETED == status))
            {
                status = MCASP_EBADARGS;

                /* Leave critical section                                     */
                HwiP_restore(key);
            }
            if (MCASP_COMPLETED == status)
            {
                /* update the driver status as being opened in case of failure    *
                 * status needs to be reverted back                               */
                chanHandle->chanState = Mcasp_DriverState_OPENED;

                /* Leave critical section                                         */
                HwiP_restore(key);
                /* update the channel operational mode  (i.e TX or RX)            */
                chanHandle->mode = (uint32_t)mode;

                /* update the device handle in the channel object structure       */
                chanHandle->devHandle = (void*)instHandle;

                /* update the IOM callback function in channel structure          */
                chanHandle->cbFxn = cbFxn;
                chanHandle->cbArg = (void *)cbArg;
            }

                /* check if the cache is to be supported and flush the cache      *
                 * if the cache support is enabled                                */
                if (TRUE == instHandle->enablecache)
                {
                    CacheP_wb(Mcasp_muteBuf[instHandle->instNum].scratchBuffer,
                                (int32_t)Mcasp_CACHE_LENGTH);
#ifdef Mcasp_LOOPJOB_ENABLED
                CacheP_wb(Mcasp_loopDstBuf[instHandle->instNum].scratchBuffer,(int32_t)Mcasp_CACHE_LENGTH);

                CacheP_wb(Mcasp_loopSrcBuf[instHandle->instNum].scratchBuffer,(int32_t)Mcasp_CACHE_LENGTH);

#endif          /* Mcasp_LOOPJOB_ENABLED */
                }
                if (MCASP_COMPLETED == status)
                {
                    chanHandle->dataPacket    = NULL;
                    chanHandle->currentPacketErrorStatus = MCASP_COMPLETED;

                    /* Initialize Mute parameter                                      */
                    chanHandle->bMuteON = (Bool)FALSE;

                    /* Initialize Pause parameter                                     */
                    chanHandle->paused = (Bool)FALSE;
                }

                /* Since we have request serialisers as free, we allocate them to *
                 * this channel as requested                                      */
                for (count = 0; count < chanparam->noOfSerRequested; count++)
                {
                    chanHandle->indexOfSersRequested[count] =
                        chanparam->indexOfSersRequested[count];
                }

                /* Store the parameters needed during operation or run-time reconfiguration */
                /* Number of serializers allocated to channel                 */
                chanHandle->noOfSerAllocated = chanparam->noOfSerRequested;

                /* Flag indicating data being packed or not                   */
                chanHandle->isDataPacked = chanparam->isDataPacked;

                /* Frame Sync Control Register                                */
                chanHandle->frSyncCtl    = chanparam->mcaspSetup->frSyncCtl;

                /* Bit Stream Format Register                                 */
                chanHandle->fmt          = chanparam->mcaspSetup->fmt;

                /* Channel operation mode: TDM or DIT                         */
                chanHandle->channelMode  = chanparam->channelMode;

                /* Number of data channels to be transmitted after frame sync */
                chanHandle->noOfChannels = chanparam->noOfChannels;

                /* Counter that counts outstanding requests of this channel   */
                chanHandle->submitCount = 0;

                /* Global error callback registered to channel                */
                chanHandle->gblErrCbk = chanparam->gblCbk;

                status = Mcasp_localCalcWordWidth(chanHandle, chanparam->wordWidth, 
                                                  &tempRoundedWordWidth);
                
                chanHandle->roundedWordWidth = tempRoundedWordWidth;

                if (MCASP_COMPLETED == status)
                {
                    if (MCASP_COMPLETED
                        != mcaspValidateBufferConfig(chanHandle, chanparam))
                    {
                        status = MCASP_EBADARGS;
                        break;
                    }
                }

                /* Converting word width from bits to bytes                       */
                chanHandle->roundedWordWidth =  \
                    (uint16_t)(chanHandle->roundedWordWidth >> 3);

                chanHandle->wordBitsSelect=chanparam->wordBitsSelect;
                /* configure the FIFO control registers (only if requested)       */
                chanHandle->enableHwFifo = (Bool)chanparam->enableHwFifo;

                if(chanHandle->enableHwFifo) {
                 /* Check if the throttle has exceeded the max */
                   if((chanHandle->hwFifoEventDMARatio > 0) &&
                      ((chanHandle->hwFifoEventDMARatio*chanHandle->roundedWordWidth*chanHandle->noOfSerAllocated) <= Mcasp_MAX_AFIFO_SIZE)) {
                      /* Fifo hwFifoEventDMARatio should be a non-zero value and the resulting depth should not exceeded the maximum allowed Fifo depth */
                      chanHandle->hwFifoEventDMARatio = chanparam->hwFifoEventDMARatio;
                   } else {
                      status = MCASP_EBADARGS;
                      break;
                   }
                }
                /* Approaches part ways.For interrupt and DMA modes               */
                if (TRUE == chanparam->isDmaDriven)
                {
                    /* Store this info in the channel handle too                  */
                    chanHandle->isDmaDriven = (Bool)TRUE;

#ifdef MCASP_EDMA_ENABLED
                    /* Preserving legacy operation: old versions of the EDMA
                     * based driver allowed for EDMA handle to be passed in
                     * through the channel parameters instead of the HW info.
                     * If this is the case we pull into the channel handle from 
                     * the parameter.
                     *
                     * In this case, we've already confirmed EDMA handle from
                     * the channel parameters is valid, so we pass to the chan
                     * handle now.
                     */
                    if (NULL == instHandle->hwInfo.dmaHandle)
                    {
                        chanHandle->edmaHandle = chanparam->edmaHandle;
                    }
#endif
                    if (MCASP_INPUT == chanHandle->mode)
                    {
                        /* Receive mode */
                        chanHandle->cpuEventNum  = instHandle->hwInfo.cpuRxEventNum;
                        chanHandle->intNum       = instHandle->hwInfo.rxIntNum;
                        chanHandle->muxInEvent = instHandle->hwInfo.rxMuxInEvent;
                        chanHandle->muxOutEvent = instHandle->hwInfo.rxMuxOutEvent;

                    }
                    else
                    {
                        /* Transmit mode */
                        chanHandle->cpuEventNum  = instHandle->hwInfo.cpuTxEventNum;
                        chanHandle->intNum       = instHandle->hwInfo.txIntNum;
                        chanHandle->muxInEvent = instHandle->hwInfo.txMuxInEvent;
                        chanHandle->muxOutEvent = instHandle->hwInfo.txMuxOutEvent;

                    }

                    chanHandle->muxNum      = instHandle->hwInfo.muxNum;
                    
#ifdef Mcasp_LOOPJOB_ENABLED
                /* Configure loop job for the user specified buffer if given  */
                if (NULL == chanparam->userLoopJobBuffer)
                {
                    if (MCASP_INPUT == chanHandle->mode)
                    {
                        chanHandle->loopJobBuffer = \
                            Mcasp_loopDstBuf[(instHandle->instNum)].
                            scratchBuffer;
                    }
                    else
                    {
                        chanHandle->loopJobBuffer = \
                            Mcasp_loopSrcBuf[(instHandle->instNum)].
                            scratchBuffer;
                    }

                    /* Length of uint32_t per serialiser-this is what we have   *
                     * allocated                                              */
                    if (Mcasp_OpMode_DIT == chanparam->channelMode)
                    {
                        /* we need 2 * 24 bit data per subframe. Hence we will*
                         * program the loop job length as 6 bytes             */
                        chanHandle->loopJobLength = 6U;
                    }
                    else
                    {
                        chanHandle->loopJobLength =
                            (chanHandle->roundedWordWidth
                             * chanHandle->noOfSlots
                             * chanHandle->noOfSerAllocated*chanHandle->hwFifoEventDMARatio);
                    }
                    /* user loopJob is not being used                         */
                    chanHandle->userLoopJob = (Bool) FALSE;
                }
                else
                {
                    /* Apps has preference on the loopjob buffer & lets use it*/
                    chanHandle->loopJobBuffer =
                        chanparam->userLoopJobBuffer;
                    chanHandle->userLoopJobLength =
                        chanparam->userLoopJobLength;

                    /* user loopJob is being used                             */
                    chanHandle->userLoopJob = (Bool) TRUE;
                    if (chanHandle->roundedWordWidth >
                        chanparam->userLoopJobLength)
                    {
                        /* not enough loopjob buffer has been provided  we    *
                         * should have aleast loopbuffer for 1 sync event     */
                        status = MCASP_EBADARGS;
                    }
                }
#endif          /* Mcasp_LOOPJOB_ENABLED */

                    /* configure EDMA for this driver                             */
                    if (MCASP_COMPLETED !=
                        Mcasp_setupDmaDuringOpen(chanHandle, &instHandle->hwInfo))
                    {
                        status = MCASP_EBADARGS;
                    }
                } /* if DMA driven*/
                else
                {
                    /* Interrupt driven operation */
                    /* Store this info too in the channel handle.                 */
                    chanHandle->isDmaDriven = (Bool)FALSE;

                    if (MCASP_INPUT == chanHandle->mode)
                    {
                        chanHandle->cpuEventNum  = instHandle->hwInfo.cpuRxEventNum;
                        chanHandle->intNum       = instHandle->hwInfo.rxIntNum;
                        chanHandle->muxInEvent = instHandle->hwInfo.rxMuxInEvent;
                        chanHandle->muxOutEvent = instHandle->hwInfo.rxMuxOutEvent;
                    }
                    else
                    {
                        chanHandle->cpuEventNum     = instHandle->hwInfo.cpuTxEventNum;
                        chanHandle->intNum          = instHandle->hwInfo.txIntNum;
                        chanHandle->muxInEvent     = instHandle->hwInfo.txMuxInEvent;
                        chanHandle->muxOutEvent     = instHandle->hwInfo.txMuxOutEvent;
                    }

                    chanHandle->muxNum      = instHandle->hwInfo.muxNum;
                    
                    /* On being released from reset, the McASP xmt section will   *
                     * trigger two interrupts to fill it's buffers (this has been *
                     * handled in submitreq function.Keep count of packets to     *
                     * service this.                                              */
                    chanHandle->dataQueuedOnReset = 0;
                    chanHandle->xferinProgressIntmode = (Bool)FALSE;
                }
            }
        }while(falsewhile);
    }

    if (MCASP_COMPLETED == status)
    {
        if (MCASP_INPUT == mode)
        {
            /* receive channel */
            /* Reconfigure the RCV section                                */
            if (MCASP_COMPLETED !=
                mcaspConfigureRcvChannel(instHandle, chanparam))
            {
                status = MCASP_EBADARGS;
            }
            else
            {
                /* Mark REQUESTED serializers as RECEIVE mode.This also       *
                 * configures PDIR pins as INPUT pin                          */
                mcaspMultiSerInitializationRcv(instHandle, chanparam);

                /* Set channel operational mode                               */
                chanHandle->channelOpMode= Mcasp_ChanMode_RCV;
            }
        }
        else
        {
            /* transmit channel */
            /* Re-configure the XMT section                               */
            if (MCASP_COMPLETED !=
                mcaspConfigureXmtChannel(instHandle, chanparam))
            {
                status = MCASP_EBADARGS;
            }
            else
            {
                /* Mark REQUESTED serializers as RECEIVE mode. Also configures*
                 * PDIR pins as INPUT pin                                     */
                mcaspMultiSerInitializationXmt(instHandle, chanparam);

                /* Set channel mode                                           */
                if (Mcasp_OpMode_DIT == chanparam->channelMode)
                {
                    /* Channel is to operate in DIT mode                      */
                    chanHandle->channelOpMode= Mcasp_ChanMode_XMT_DIT;
                }
                else
                {
                    /* Channel is to operate in normal TDM mode               */
                    chanHandle->channelOpMode= Mcasp_ChanMode_XMT_TDM;
                }
            }
        }
    }

    if (MCASP_COMPLETED == status)
    {
        /* For burtsmode of operation frame sync error has to ignored     *
         * to indentify that we do the following                          */
        if (MCASP_INPUT == chanHandle->mode)
        {
                    /* Clear the framsync error flag from EVTCTLR
                     *                */
                    mod = McASPTxRxFrameSyncRead
                              (instHandle->hwInfo.regs, (uint8_t) RX);
                    mod &= (uint32_t) MCASP_RXFMCTL_RMOD_MASK;
            if (0U == mod)
            {
                        McASPRxIntDisable(instHandle->hwInfo.regs,
                                          (uint32_t) MCASP_RX_SYNCERROR);
            }
        }
        else
        {
                    mod = McASPTxRxFrameSyncRead
                              (instHandle->hwInfo.regs, (uint8_t) TX);
                    mod &= MCASP_TXFMCTL_XMOD_MASK;
            if (0U == mod)
            {
                        McASPTxIntDisable(instHandle->hwInfo.regs,
                                          (uint32_t) MCASP_TX_SYNCERROR);
            }
        }
        
        if(chanHandle->userIntValue) {
        
            if (MCASP_INPUT == chanHandle->mode)
            {
               /*Interrupt status word to be written back to reset status bits       */
               McASPRxStatusSet(instHandle->hwInfo.regs,
                                McASPRxStatusGet(instHandle->hwInfo.regs));
            } else{
                   /*Interrupt status word to be written back to reset status bits       */
                   McASPTxStatusSet(instHandle->hwInfo.regs,
                                    McASPTxStatusGet(instHandle->hwInfo.regs));
            }
           /* Register the interrupts for events for both  DMA/Interrupt     *
           * modes  because in DMA mode also we will get interrupts for     *
           * errors                                                         */
          
            if ( (chanHandle->intNum!=MCASP_UNASSIGNED_INTNUM) && (chanHandle->cpuEventNum !=MCASP_UNASSIGNED_EVENTNUM))
            {
               mcaspRegisterInt(
                chanHandle,
                (uint32_t)instHandle->instNum,
                chanHandle->cpuEventNum,
                chanHandle->intNum,
                (void *)&mcaspIsr);
            }
        }
#ifdef Mcasp_LOOPJOB_ENABLED
        /* Enable the FIFO if used */
        mcaspConfigureFifo(&(instHandle->hwInfo),
            chanHandle,
            chanHandle->enableHwFifo);

                /*Starting DMA after starting clocks and before Serialiser SM FS
                 * */
                if ((Bool) TRUE == chanHandle->isDmaDriven)
                {
                    /* enable the DMA */
                    Mcasp_enableDMA(chanHandle);
                    /* if DLB mode is set then Enable both state m/c else rcv
                     * or xmt  state machine only needs to be enabled
                     */
                    if (MCASP_INPUT == mode)
                    {
                            /* Receive channel */
                            /* activate RX and TX state machine and frame sync
                             */
                            if(chanHandle->userIntValue) {
                               Mcasp_enableInterrupt(chanHandle->cpuEventNum,chanHandle->intNum);
                            }  
                           status = Mcasp_localActivateSmFsForRcv(instHandle);
                    }
                    else
                    {
                        /* Transmit channel */
                        /* activate RX and TX state machine and frame sync
                        */
                        if(chanHandle->userIntValue) {
                           Mcasp_enableInterrupt(chanHandle->cpuEventNum,chanHandle->intNum);
                        }   
                        status = Mcasp_localActivateSmFsForXmt(instHandle);
                    }
                }
                /* dma driven */

                /* For interrupt mode actual start of mcasp starts in Submit
                 * function and only when enough data packets are available.
                 * Also note that we have not implemented loopjobbuffer for
                 * this mode
                 * */
                /*  update the State m/c stop status
                 */
                instHandle->stopSmFsXmt = (Bool) FALSE;
                instHandle->stopSmFsRcv = (Bool) FALSE;
#endif          /* Mcasp_LOOPJOB_ENABLED */
    }

    if ((TRUE == pscPwrOn) && (MCASP_COMPLETED == status))
    {
        /* power off the module                                           */
        retVal = Mcasp_localLpscOff(instHandle);
    
        if (MCASP_COMPLETED == status)
        {
            status = retVal;
        }
    }

    if (MCASP_COMPLETED != status )
    {
        /* enter critical section                                             */
        key = HwiP_disable();
        /* in case of an error we may not have the reference to channel handle*
         * hence we will explicitly assign it here                            */
        if (NULL != chanHandle)
        {
            /* call the delete function to free all the assigned resources    */
            mcaspDeleteChan(chanHandle);
        }

        /* Leave critical section                                             */
        HwiP_restore(key);
        /* channel opening for transaction has failed                         */
        *chanp = NULL;
    }
    else
    {
        *chanp = chanHandle;
    }
    return status;
}

/**
 *  \brief   Submit a I/O packet to a channel for processing
 *
 *  The stream layer calls this function to cause the IDriver
 *  to process the MCASP_Packet for read/write operations.
 *  This function calls mcaspSubmitReq  function to execute the request.
 *
 *  \param   chanp      [IN]  Handle to the channel
 *  \param   ioPacket   [IN]  Pointer to the packet to be submitted
 *
 *  \return  MCASP_COMPLETED, if packet is fully processed
 *           Error code,   if error in processing
 */
  int32_t mcaspSubmitChan(void* chanp, MCASP_Packet *ioPacket)
{
    Mcasp_ChannelHandle    chanHandle  = NULL;
    Mcasp_Object          *instHandle  = NULL;
    int32_t                  status      = MCASP_COMPLETED;

/* Begin parameter checking                                                   */
#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
    if ((NULL == chanp) || (NULL == ioPacket))
    {
        status = MCASP_EBADARGS;
    }
    else
    {
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */

        chanHandle = (Mcasp_ChannelHandle)chanp;

#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
        if ((NULL == chanHandle) ||
             (Mcasp_DriverState_OPENED != chanHandle->chanState) ||
             (((MCASP_READ == ioPacket->cmd) || (MCASP_WRITE == ioPacket->cmd)) &&
            ((0 == ioPacket->size) || (NULL == ioPacket->addr))))
        {
            status = MCASP_EBADARGS;
        }
    }
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */
/* End parameter checking                                                     */

    /* validate all the input parameters and set error if not OK              */
    if (MCASP_COMPLETED == status)
    {
        /* if the command is for the ABORT or FLUSH                           */
        if ((MCASP_ABORT == ioPacket->cmd) || (MCASP_FLUSH == ioPacket->cmd))
        {
            status = Mcasp_localAbortRequests(chanHandle, NULL);
        }
        else if ((MCASP_WRITE == ioPacket->cmd) || (MCASP_READ == ioPacket->cmd))
        {
            instHandle = (Mcasp_Object *)chanHandle->devHandle;
            if(NULL != instHandle)
            {
              /* switch on the device in the PSC                                */
              status = Mcasp_localLpscOn(instHandle);

              if (MCASP_COMPLETED == status)
              {
                /* submit the IO request to the driver                        */
                status = mcaspSubmitReq(chanHandle,ioPacket);

                if (MCASP_PENDING != status)
                {
                    status = Mcasp_localLpscOff(instHandle);
                }
              }
            } 
            else
            {
               status = MCASP_EINVALIDVAL;
            }  
        }
        else
        {
            /* error: command not found                                       */
            status = MCASP_EBADARGS;
        }
    }
    return status;
}

/**
 *  \brief   This function is called by the application to close a previously
 *           opened channel.it deletes the channel so that it is not available
 *           for further transactions. All the allocated resources are freed
 *           and the channel will be ready for the "open" operation once again.
 *
 *  \param   chanp      [IN]   Handle to the channel.
 *
 *  \return  None
 *
 */
  int32_t mcaspDeleteChan(void* chanp)
{
    Mcasp_Object        *instHandle  = NULL;
    Mcasp_ChannelHandle  chanHandle  = NULL;
    int32_t                status      = MCASP_COMPLETED;
    uint32_t               hwiKey      = 0;
    Bool                 pscPwrOn    = (Bool)FALSE;
    int32_t                retVal      = MCASP_COMPLETED;
    
/* Begin parameter checking                                                   */
#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
    if (NULL == chanp)
    {
        status = MCASP_EBADARGS;
    }
    else
    {
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */
        chanHandle = (Mcasp_ChannelHandle)chanp;
#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
        if (NULL == chanHandle->devHandle)
        {
            status = MCASP_EBADARGS;
        }
    }
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */
/* End parameter checking                                                     */

    /* check if the input parameters are valid                                */
    if (MCASP_COMPLETED == status)
    {
       instHandle = (Mcasp_Object*)chanHandle->devHandle;
       if(NULL != instHandle)
       {  
#if defined (BIOS_PWRM_ENABLE) && !defined (Mcasp_LOOPJOB_ENABLED)
        if (TRUE == instHandle->pscPwrmEnable)
        {
            status = McaspUnregisterConstraints(instHandle);
        }
#endif
        /* before touching McASP registers, place transmit and receive section
         * in reset    */
        if (MCASP_OUTPUT == chanHandle->mode)
        {
            McASPTxReset((uint32_t)instHandle->hwInfo.regs);
        }
        else
        {
            McASPRxReset((uint32_t)instHandle->hwInfo.regs);
        }
        /* DMA driven transaction channel                                     */
        if (TRUE == chanHandle->isDmaDriven)
        {
            /* Unregister the interrupts registered                           */
            if(chanHandle->userIntValue) {
               mcaspUnRegisterInt(
                 instHandle->instNum,
                 chanHandle->cpuEventNum,
                 chanHandle->intNum,
                 (int32_t)chanHandle->mode);
            }   

            status = Mcasp_localLpscOn(instHandle);

            if (MCASP_COMPLETED == status)
            {
                pscPwrOn = (Bool)TRUE;
            }

            if (MCASP_COMPLETED == status)
            {
                /* Stop the xmt/rcv state machine.                            */
                if (Mcasp_ChanMode_RCV == chanHandle->channelOpMode)
                {
                    /* Reset state m/c and frame sync of receive section      */
                    status = Mcasp_localDeactivateSmFsForRcv(instHandle);
                }
                else
                {
                    /* Reset state m/c and frame sync of transmit section     */
                    status = Mcasp_localDeactivateSmFsForXmt(instHandle);
                }
            }

            /* Disable the FIFO */
            mcaspConfigureFifo(&instHandle->hwInfo, chanHandle, FALSE);

            /* Disable the current transfer to make sure that there is        *
             * no running EDMA transfer taking place                          */
            if (MCASP_COMPLETED == status)
            {
                status = Mcasp_disableDMA(chanHandle);
            }

            if (MCASP_COMPLETED != status)
            {
                status = MCASP_EBADMODE;
                /* we will continue inspite of the error here                 */
            }

            status = Mcasp_freeDmaChannel(chanHandle);

            if (MCASP_COMPLETED != status)
            {
                status = MCASP_EBADMODE;
                /* we will continue inspite of the error here                 */
            }
        } /* DMA Driven flag is TRUE if loop */

        /* restore global serializer state.                                   */
        mcaspMultiSerGlobalRestore(chanHandle);

        /* Set the Muted state to FALSE                                       */
        chanHandle->bMuteON = (Bool)FALSE;

        /* Set the Pause state to FALSE                                       */
        chanHandle->paused = (Bool)FALSE;

        /* start of critical section                                          */
        hwiKey = HwiP_disable();
        /* Mark channel as ready to be allocated again.                       */
        chanHandle->chanState = Mcasp_DriverState_CLOSED;

        /* Leave critical section                                             */
        HwiP_restore(hwiKey);
        
        chanHandle->noOfSerAllocated = 0;
        chanHandle->channelOpMode  = Mcasp_ChanMode_FREE;

        if (TRUE == pscPwrOn)
        {
            retVal = Mcasp_localLpscOff(instHandle);

            if (MCASP_COMPLETED == status)
            {
                status = retVal;
            }
        }
      }
      else
      {
		 status = MCASP_EINVALIDVAL; 
	  }
    }
    return (status);
}


/**
 *  \brief    This function allows the control commands to be sent to the Mcasp
 *            driver. it internally calls the mcaspSubmitIoctl Function to
 *            perform the desired operation.
 *
 *  \param    chanp      [IN]    Channel handle
 *  \param    cmd        [IN]    control command given by the application
 *  \param    cmdArgs    [IN]    Optional arguments required for the command
 *
 *  \return  MCASP_COMPLETED if successful
 *           Error code if unsuccessful
 *
 */
  int32_t mcaspControlChan(void* chanp, Mcasp_ioctlCmd cmd, void* cmdArgs)
{
    Mcasp_ChannelHandle  chanHandle = NULL;
    Mcasp_Object        *instHandle = NULL;
    int32_t                status     = MCASP_COMPLETED;
    int32_t                retVal     = MCASP_COMPLETED;

/* Begin parameter checking                                                   */
#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
    if (NULL != chanp)
    {
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */
        chanHandle = (Mcasp_ChannelHandle)chanp;
#ifndef PSP_DISABLE_INPUT_PARAMETER_CHECK
        if (Mcasp_DriverState_OPENED != chanHandle->chanState)
        {
            status = MCASP_EBADARGS;
        }
        else
        {
            if (NULL == chanHandle->devHandle)
            {
                status = MCASP_EBADARGS;
            }
        }
    }
    else
    {
        status = MCASP_EBADARGS;
    }
#endif  /* PSP_DISABLE_INPUT_PARAMETER_CHECK */
/* End parameter checking                                                     */

    /* check if the channel handle passed is valid                            */
    if (MCASP_COMPLETED == status)
    {
        instHandle = (Mcasp_Object *)chanHandle->devHandle;

        status = Mcasp_localLpscOn(instHandle);

        if (MCASP_COMPLETED == status)
        {
            /* channel status is OK Hence the IOCTL can be executed           */
            status = Mcasp_localSubmitIoctl(chanHandle,cmd,(void*)cmdArgs,NULL);

            retVal = Mcasp_localLpscOff(instHandle);

            if (MCASP_COMPLETED == status)
            {
                status = retVal;
            }
        }
    }

    return (status);
}

/* ========================================================================== */
/*                              LOCAL FUNCTIONS                               */
/* ========================================================================== */

/**
 *  \brief  This function configures the  McASP instance registers as per the
 *          values passed in the hardware setup structure.
 *
 *  \param   hMcasp     [IN]    Handle to the McASP instance
 *  \param   myHwSetup  [IN]    Pointer to hardware setup structure
 *                             the query passed
 *
 *  \return  None
 *
 */
int32_t Mcasp_localSetupHwInfo(Mcasp_HwHandle        hMcasp,
                             const Mcasp_HwSetup  *myHwSetup)
{
    Int16   serNum = 0;
    int32_t status = MCASP_COMPLETED;
    
    if((NULL != hMcasp) && (NULL != myHwSetup) && (0 != hMcasp->regs))
    {
    /* Reset McASP to default values by setting GBLCTL = 0                    */
    McASPGlobalCtlReset(hMcasp->regs);

#if defined(SOC_AM571x) || defined(SOC_AM572x) || defined(SOC_AM574x) || defined(SOC_K2G) || defined(SOC_DRA75x) || defined(SOC_TDA2XX) || defined(SOC_TDA2EX) || defined(SOC_TDA3XX) || defined(SOC_DRA78x)
    /* Changing the reset Power ON State of McASP to NO IDLE Configuration.
     * WakeUp Schema for McASP does not work,since we dont have any Power
     * Framework, default Power Status of McASP is changed to NOIDLE  
     * indorder to prevent any issues  which affect McASP wakeup in HW_AUTO Mode 
     * and cause McASP Application Crash. Hence As per TRM recommended
     * Value, it is set to NOIDLE Mode. But there will be huge impact on Power 
     * as McASP will always be ON.
     */
    McASPSetPowerIdleConfig(hMcasp->regs, MCASP_IDLEMODE_NOIDLE);
#endif
    /* Configure the RMASK register                                           */
    McASPRxFmtMaskSet(hMcasp->regs, (uint32_t) myHwSetup->rx.mask);

    /* Configure RFMT                                                         */
    McASPRxFmtSet(hMcasp->regs, (uint32_t) myHwSetup->rx.fmt);

    /* Configure AFSRCTL                                                      */
    McASPRxFrameSyncCfg(
        hMcasp->regs,
        (myHwSetup->rx.frSyncCtl &
         (uint32_t) MCASP_RXFMCTL_RMOD_MASK) >> MCASP_RXFMCTL_RMOD_SHIFT,
        (myHwSetup->rx.frSyncCtl &
         (uint32_t) MCASP_RXFMCTL_FRWID_MASK) >> MCASP_RXFMCTL_FRWID_SHIFT,
        (myHwSetup->rx.frSyncCtl &
         ((uint32_t) MCASP_RXFMCTL_FSRP_MASK |
          (uint32_t) MCASP_RXFMCTL_FSRM_MASK)) >> MCASP_RXFMCTL_FSRP_SHIFT);

    /* Configure ACLKRCTL                                                     */
    McASPRxClkPolaritySet(hMcasp->regs,
                          (myHwSetup->rx.clk.clkSetupClk &
                           (uint32_t) MCASP_ACLKRCTL_CLKRP_MASK));

    McASPRxHFClkPolaritySet(hMcasp->regs,
                            ((myHwSetup->rx.clk.clkSetupHiClk &
                              (uint32_t) MCASP_AHCLKRCTL_HCLKRP_MASK) <<
                             MCASP_AHCLKRCTL_HCLKRP_SHIFT));
    McASPRxClkCfg(hMcasp->regs,
                  ((myHwSetup->rx.clk.clkSetupClk &
                    (uint32_t) MCASP_ACLKRCTL_CLKRM_MASK) |
                   (myHwSetup->rx.clk.clkSetupHiClk &
                    (uint32_t) MCASP_AHCLKRCTL_HCLKRM_MASK)),
                  ((myHwSetup->rx.clk.clkSetupClk &
                    (uint32_t) MCASP_ACLKRCTL_CLKRDIV_MASK) >>
                   MCASP_ACLKRCTL_CLKRDIV_SHIFT),
                  ((myHwSetup->rx.clk.clkSetupHiClk &
                    (uint32_t) MCASP_AHCLKRCTL_HCLKRDIV_MASK) >>
                   MCASP_AHCLKRCTL_HCLKRDIV_SHIFT));

    /* Configure RTDM                                                         */
    McASPRxTimeSlotSet(hMcasp->regs, myHwSetup->rx.tdm);

    /* Configure RINTCTL                                                      */
    McASPRxIntEnable(hMcasp->regs, myHwSetup->rx.intCtl);

    /* Configure RCLKCHK                                                      */
    McASPRxClkCheckRegWrite(hMcasp->regs, myHwSetup->rx.clk.clkChk);

    /* Configure XMASK                                                        */
    McASPTxFmtMaskSet(hMcasp->regs, myHwSetup->tx.mask);

    /* Configure XFMT                                                         */
    McASPTxFmtSet(hMcasp->regs, myHwSetup->tx.fmt);

    /* Configure AFSXCTL                                                      */
    McASPTxFrameSyncCfg(
        hMcasp->regs,
        (myHwSetup->tx.frSyncCtl &
         (uint32_t) MCASP_TXFMCTL_XMOD_MASK) >> MCASP_TXFMCTL_XMOD_SHIFT,
        (myHwSetup->tx.frSyncCtl &
         (uint32_t) MCASP_TXFMCTL_FXWID_MASK) >> MCASP_TXFMCTL_FXWID_SHIFT,
        (myHwSetup->tx.frSyncCtl &
         ((uint32_t) MCASP_TXFMCTL_FSXP_MASK |
          (uint32_t) MCASP_TXFMCTL_FSXM_MASK)) >> MCASP_TXFMCTL_FSXP_SHIFT);

    /* Configure ACLKXCTL                                                     */
    McASPTxClkPolaritySet(hMcasp->regs,
                          (myHwSetup->tx.clk.clkSetupClk &
                           (uint32_t) MCASP_ACLKXCTL_CLKXP_MASK));

    /* Configure AHCLKXCTL                                                    */
    McASPTxHFClkPolaritySet(hMcasp->regs,
                            ((myHwSetup->tx.clk.clkSetupHiClk &
                              (uint32_t) MCASP_AHCLKXCTL_HCLKXP_MASK) <<
                             MCASP_AHCLKXCTL_HCLKXP_SHIFT));

    if ((myHwSetup->tx.clk.clkSetupClk &
         (uint32_t) MCASP_ACLKXCTL_ASYNC_MASK) ==
        (uint32_t) MCASP_ACLKXCTL_ASYNC_MASK)
    {
        McASPTxRxClkSyncDisable(hMcasp->regs);
    }
    else
    {
        McASPTxRxClkSyncEnable(hMcasp->regs);
    }

    McASPTxClkCfg(hMcasp->regs,
                  ((myHwSetup->tx.clk.clkSetupClk &
                    (uint32_t) MCASP_ACLKXCTL_CLKXM_MASK) |
                   (myHwSetup->tx.clk.clkSetupHiClk &
                    (uint32_t) MCASP_AHCLKXCTL_HCLKXM_MASK)),
                  ((myHwSetup->tx.clk.clkSetupClk &
                    (uint32_t) MCASP_ACLKXCTL_CLKXDIV_MASK) >>
                   MCASP_ACLKXCTL_CLKXDIV_SHIFT),
                  ((myHwSetup->tx.clk.clkSetupHiClk &
                    (uint32_t) MCASP_AHCLKXCTL_HCLKXDIV_MASK) >>
                   MCASP_AHCLKXCTL_HCLKXDIV_SHIFT));

    /* Configure XTDM                                                         */
    McASPTxTimeSlotSet(hMcasp->regs, myHwSetup->tx.tdm);

    /* Configure XINTCTL                                                      */
    McASPTxIntEnable(hMcasp->regs, myHwSetup->tx.intCtl);

    /* Configure XCLKCHK                                                      */
    McASPTxClkCheckRegWrite(hMcasp->regs, myHwSetup->tx.clk.clkChk);

    while (serNum < hMcasp->numOfSerializers)
    {
        McASPSerializerSet(hMcasp->regs, (uint32_t) serNum,
                           myHwSetup->glb.serSetup[serNum]);
        serNum++;
    }

    /* Configure pin function register                                        */
    McASPPinGPIOSet(hMcasp->regs, myHwSetup->glb.pfunc);

    /* Configure pin direction register                                       */
    McASPPinDirOutputSet(hMcasp->regs, myHwSetup->glb.pdir);

    /* Configure DITCTL                                                       */
    if (TRUE == hMcasp->ditStatus)
    {
        McASPDITModeCtlWrite(hMcasp->regs, myHwSetup->glb.ditCtl);
    }

    /* Configure DLBCTL                                                       */
    McASPDlbRegWrite(hMcasp->regs, myHwSetup->glb.dlbMode);

#if defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_K2G)
    /* Configure AMUTE                                                        */
    McASPAmuteRegWrite(hMcasp->regs,myHwSetup->glb.amute);
#endif  
    /* Configure RSTAT and XSTAT                                              */
    McASPRxStatusSet(hMcasp->regs, myHwSetup->rx.stat);
    McASPTxStatusSet(hMcasp->regs, myHwSetup->tx.stat);

    /* Configure REVTCTL and XEVTCTL                                          */
    McASPTxRxDMAEvtCntrlWrite(hMcasp->regs, (uint8_t) RX, myHwSetup->rx.evtCtl);
    McASPTxRxDMAEvtCntrlWrite(hMcasp->regs, (uint8_t) TX, myHwSetup->rx.evtCtl);

    /* Initialize the global control register                                 */
    McASPGlobalCtlSet(hMcasp->regs, myHwSetup->glb.ctl);
  }
  else
  {
	  status = MCASP_EBADARGS;
  }
  return(status);
}


/**
 *  \brief   Aborts all the request queued up with the current channel
 *
 *  \param   chanHandle   [IN]   Handle to the mcasp channel
 *
 *  \return  None
 *
 *
 */
int32_t Mcasp_localAbortReset(Mcasp_ChannelHandle chanHandle)
{
    Mcasp_Object        *instHandle = NULL;
    MCASP_Packet          *ioPacket   = NULL;
    uint32_t               hwiKey     = 0;
    Bool                 falsewhile = (Bool)FALSE;
    Bool                 firstReq   = (Bool)TRUE;
    uint32_t            dmaPos = 0;
    int32_t                status     = MCASP_COMPLETED;

    if((NULL != chanHandle) && (NULL != chanHandle->devHandle))
    {
    do
    {
        falsewhile = (Bool)FALSE;

        instHandle = (Mcasp_Object *)chanHandle->devHandle;


        /* This function services both transmit and receive channels. Define  *
         * critical section to avoid corruption of local variables.           *
         * CRITICAL SECTION: begins!                                          */
        hwiKey = HwiP_disable();
        
        /* stop the xmt/rcv state machine.                                    */
        if (Mcasp_ChanMode_RCV == chanHandle->channelOpMode)
        {
            /* Reset state m/c and frame sync of receive section              */
            status = Mcasp_localDeactivateSmFsForRcv(instHandle);
        }
        else
        {
            /* Reset state m/c and frame sync of transmit section             */
            status = Mcasp_localDeactivateSmFsForXmt(instHandle);
        }

        /* Disable the FIFO */
        mcaspConfigureFifo(&instHandle->hwInfo, chanHandle, FALSE);

        /* Disable EDMA  transfer                                             */
        Mcasp_disableDMA(chanHandle);

        /* Clear the error bits of McASP due to stopping of peripheral.       */
        if (MCASP_INPUT == chanHandle->mode)
        {
            McASPRxStatusSet(instHandle->hwInfo.regs,
                             (uint32_t) MCASP_RXSTAT_RDMAERR_MASK);

            McASPRxStatusSet(instHandle->hwInfo.regs,
                             (uint32_t) MCASP_RXSTAT_ROVRN_MASK);

            McASPRxStatusSet(instHandle->hwInfo.regs,
                             (uint32_t) MCASP_RXSTAT_RSYNCERR_MASK);
        }
        else
        {
            McASPTxStatusSet(instHandle->hwInfo.regs,
                             (uint32_t) MCASP_TXSTAT_XDMAERR_MASK);
            McASPTxStatusSet(instHandle->hwInfo.regs,
                             (uint32_t) MCASP_TXSTAT_XUNDRN_MASK);
            McASPTxStatusSet(instHandle->hwInfo.regs,
                             (uint32_t) MCASP_TXSTAT_XSYNCERR_MASK);
        }

        /* Get the current value of cCnt for the actual data transfered       */
        Mcasp_getDmaPosition(chanHandle, &dmaPos);

        firstReq = (Bool)TRUE;

        if (((int32_t)TRUE) == chanHandle->isDmaDriven)
        {
            /* Empty the floating queue.                                      */
            while (((int32_t)TRUE) != Osal_Queue_empty((&(chanHandle->queueFloatingList))))
            {
                ioPacket = (MCASP_Packet *)  \
                                Osal_Queue_get((&(chanHandle->queueFloatingList)));

                if (NULL == ioPacket)
                {
                    status = MCASP_EBADIO;
                    /* Ideally control should not come here                   */
                    break;
                }

                /* set packet status equal to MCASP_ABORTED                     */
                ioPacket->status = MCASP_ABORTED;


                /* Actual data transfer will be equal to size provided by     *
                 * application i.e.userDataBufferSize reduced by current      *
                 * DMA position.                                              */
                if (TRUE == firstReq )
                {
                    ioPacket->size = (uint32_t)(ioPacket->size - dmaPos);
                    firstReq = (Bool)FALSE;
                }

                if (NULL != ioPacket)
                {
                    if (NULL !=  chanHandle->cbFxn)
                    {
                        /*  Application callback                              */
                        (*chanHandle->cbFxn)((void*)chanHandle->cbArg,ioPacket);
                    }
                }
                /* decrement the submit count as request is aborted           */
                chanHandle->submitCount--;
            }
        }
        else
        {
            ioPacket = chanHandle->dataPacket;

            if (NULL != ioPacket)
            {
                /* set packet status equal to Mcasp_E_aborted                 */
                ioPacket->status = MCASP_ABORTED; /* Mcasp_E_aborted; */

                if (NULL != chanHandle->cbFxn)
                {
                        /*  Application callback                              */
                    (*chanHandle->cbFxn)((Ptr) chanHandle->cbArg, ioPacket);
                }
            }
        }
        /* Empty the pendQUE queue.                                           */
        while (((int32_t)TRUE) != Osal_Queue_empty((&(chanHandle->queueReqList))))
        {
            ioPacket = (MCASP_Packet *)Osal_Queue_get((&(chanHandle->queueReqList)));

            if (NULL != ioPacket)
            {
                /* set packet status equal to MCASP_ABORTED                     */
                ioPacket->status = MCASP_ABORTED;
                ioPacket->size   = 0;
                if (NULL !=  chanHandle->cbFxn)
                {
                    /*  Application callback                                  */
                    (*chanHandle->cbFxn)((void*)chanHandle->cbArg,ioPacket);
                }
            }
            /* decrement the submit count as request is aborted */
            chanHandle->submitCount--;
        }

        /* As EDMA is disabled it might have thrown an error and set error    *
         * bit. Clear the error bit to enable the transfer again              */
        Mcasp_clearDmaErrors(chanHandle);

        /* Configure the EDMA channel and EDMA param tables with intialization*
         * configuration as they are configured at the create time.           */
        /** Todo: where is the right place for this? */
        chanHandle->loopjobUpdatedinParamset = (Bool)TRUE;

        Mcasp_setupDmaChan(chanHandle);

#ifdef Mcasp_LOOPJOB_ENABLED

        /* Enable the FIFO if used */
        mcaspConfigureFifo(&instHandle->hwInfo,
                           chanHandle,
                           chanHandle->enableHwFifo);

        /* Enable DMA transfer, state machine and frame sync                  */
        Mcasp_enableDMA(chanHandle);

        if (Mcasp_ChanMode_RCV == chanHandle->channelOpMode)
        {
            /* Reset state m/c and frame sync of receive section              */
            status = Mcasp_localActivateSmFsForRcv(instHandle);
        }
        else
        {
            /* Reset state m/c and frame sync of transmit section             */
            status = Mcasp_localActivateSmFsForXmt(instHandle);
        }
#endif
        /* CRITICAL SECTION: ends!                                            */
      HwiP_restore(hwiKey);
      
    }while(falsewhile);
  } 
  else
  {
    status = MCASP_EBADARGS;
  }
    return (status);
}

/**
 *  \brief   This function activates the receive section state machine and
 *           the corresponding frame sync.
 *
 *  \param   instHandle  [IN]   Handle to the Mcasp instance object
 *
 *  \return  None
 *
 */
int32_t Mcasp_localActivateSmFsForRcv(const Mcasp_Object *instHandle)
{
    int32_t status = MCASP_COMPLETED;
    if(NULL != instHandle)
    {
    McASPRxStatusSet(instHandle->hwInfo.regs,
                     ((uint32_t) MCASP_RXSTAT_RERR_MASK |
                      (uint32_t) MCASP_RXSTAT_RDMAERR_MASK |
                      (uint32_t) MCASP_RXSTAT_RSTAFRM_MASK |
                      (uint32_t) MCASP_RXSTAT_RDATA_MASK |
                      (uint32_t) MCASP_RXSTAT_RLAST_MASK |
                      (uint32_t) MCASP_RXSTAT_RCKFAIL_MASK |
                      (uint32_t) MCASP_RXSTAT_RSYNCERR_MASK |
                      (uint32_t) MCASP_RXSTAT_ROVRN_MASK));

    /*serializer*/
    mcaspBitSetGblRCtl(instHandle,
                       (uint32_t) MCASP_GBLCTLR_RSRCLR_MASK);

    /*state m/c*/
    mcaspBitSetGblRCtl(instHandle,
                       (uint32_t) MCASP_GBLCTLR_RSMRST_MASK);

    /*frame sync*/
    mcaspBitSetGblRCtl(instHandle,
                       (uint32_t) MCASP_GBLCTLR_RFRST_MASK);
 
  }
  else
  {
    status = MCASP_EBADARGS;
  }
  return(status);
}

/**
 *  \brief   This function activates the transmit section state machine and
 *           the corresponding frame sync.
 *
 *  \param   instHandle [IN]  pointer to the Mcasp instance object
 *
 *  \return  None
 *
 */
int32_t Mcasp_localActivateSmFsForXmt(const Mcasp_Object *instHandle)
{
    int32_t status = MCASP_COMPLETED;
    
    if(NULL != instHandle)
    {
    McASPTxStatusSet(instHandle->hwInfo.regs,
                     ((uint32_t) MCASP_TXSTAT_XERR_MASK |
                      (uint32_t) MCASP_TXSTAT_XDMAERR_MASK |
                      (uint32_t) MCASP_TXSTAT_XSTAFRM_MASK |
                      (uint32_t) MCASP_TXSTAT_XDATA_MASK |
                      (uint32_t) MCASP_TXSTAT_XLAST_MASK |
                      (uint32_t) MCASP_TXSTAT_XCKFAIL_MASK |
                      (uint32_t) MCASP_TXSTAT_XSYNCERR_MASK |
                      (uint32_t) MCASP_TXSTAT_XUNDRN_MASK));

    /*Start the Serializer, State M/C and Frame Sync Generator                */
    mcaspBitSetGblXCtl(instHandle,
                       (uint32_t) MCASP_GBLCTLX_XSRCLR_MASK);
    mcaspBitSetGblXCtl(instHandle,
                       (uint32_t) MCASP_GBLCTLX_XSMRST_MASK);
    mcaspBitSetGblXCtl(instHandle,
                       (uint32_t) MCASP_GBLCTLX_XFRST_MASK);
   }
   else
   {
      status = MCASP_EBADARGS;
   }
   return(status);
}

/**
 *  \brief   This function activates the state machine and the corresponding
 *           frame sync for both receive and transmit sections.
 *
 *  \param   instHandle [IN]  pointer to the Mcasp Instance object
 *
 *  \return  None
 *
 */
int32_t Mcasp_localActivateSmFsForBoth(const Mcasp_Object *instHandle)
{
    int32_t status = MCASP_COMPLETED;
    if((NULL != instHandle))
    {

    /* Clear the interrupts                                                   */
    McASPTxStatusSet(instHandle->hwInfo.regs,
                     ((uint32_t) MCASP_TX_STAT_ERR |
                      (uint32_t) MCASP_TX_STAT_DMAERR |
                      (uint32_t) MCASP_TX_STAT_STARTOFFRAME |
                      (uint32_t) MCASP_TX_STAT_DATAREADY |
                      (uint32_t) MCASP_TX_STAT_LASTSLOT |
                      (uint32_t) MCASP_TXSTAT_XCKFAIL_MASK |
                      (uint32_t) MCASP_TX_STAT_SYNCERR |
                      (uint32_t) MCASP_TX_STAT_UNDERRUN));

    McASPRxStatusSet(instHandle->hwInfo.regs,
                     ((uint32_t) MCASP_RXSTAT_RERR_MASK |
                      (uint32_t) MCASP_RXSTAT_RDMAERR_MASK |
                      (uint32_t) MCASP_RXSTAT_RSTAFRM_MASK |
                      (uint32_t) MCASP_RXSTAT_RDATA_MASK |
                      (uint32_t) MCASP_RXSTAT_RLAST_MASK |
                      (uint32_t) MCASP_RXSTAT_RCKFAIL_MASK |
                      (uint32_t) MCASP_RXSTAT_RSYNCERR_MASK |
                      (uint32_t) MCASP_RXSTAT_ROVRN_MASK));

    /*Start the Serializer, State M/C and Frame Sync Generator*/
    mcaspBitSetGblCtl(instHandle,
                      (uint32_t) (MCASP_GBLCTLX_XSRCLR_MASK |
                                MCASP_GBLCTLR_RSRCLR_MASK));
    mcaspBitSetGblCtl(instHandle,
                      (uint32_t) (MCASP_GBLCTLX_XSMRST_MASK |
                                MCASP_GBLCTLR_RSMRST_MASK));
    mcaspBitSetGblCtl(instHandle,
                      (uint32_t) (MCASP_GBLCTLX_XFRST_MASK |
                                MCASP_GBLCTLR_RFRST_MASK));
   }
   else
   {
      status = MCASP_EBADARGS;
   }
   return(status);
}



/**
 *  \brief  Resets the state m/c of the McASP xmt/rcv unit. In case of interrupt
 *          driven transactions, this also resets data queued for servicing the
 *          MCASP xmt/rcv unit when it is taken out of reset.
 *
 *  \param  chanHandle  [IN]  Handle to the mcasp channel to reset
 *
 *  \return  MCASP_COMPLETED if successful
 *           Error code if unsuccessful
 */
int32_t Mcasp_localSmReset(Mcasp_ChannelHandle chanHandle)
{
    Mcasp_Object   *instHandle = NULL;
    int32_t status = MCASP_COMPLETED;

    if((NULL != chanHandle) && (NULL != chanHandle->devHandle))
    {
      instHandle = (Mcasp_Object *)chanHandle->devHandle;

      if (Mcasp_ChanMode_RCV == chanHandle->channelOpMode)
      {
        /* Reset state m/c and frame sync of receive section                  */
        status = Mcasp_localDeactivateSmFsForRcv(instHandle);
      }
      else
      {
        /* Reset state m/c and frame sync of transmit section                 */
        status = Mcasp_localDeactivateSmFsForXmt(instHandle);
      }

      /* Disable the FIFO */
      mcaspConfigureFifo(&instHandle->hwInfo, chanHandle, FALSE);

      if (FALSE == chanHandle->isDmaDriven)
      {
        /* Interrupt driven transactions */

        /* When iohandle state m/c is reactivated, it will require two        *
         * requests to service it. Reset count to ensure this.                */
        chanHandle->dataQueuedOnReset = 0;
        chanHandle->xferinProgressIntmode = (Bool)FALSE;
      }
      else
     {
        Mcasp_disableDMA(chanHandle);
     }
  } 
  else
  {
	  status = MCASP_EBADARGS;
  }   
  return (status);
}

/**
 *  \brief  This function activates the state machine of the Mcasp transmit and
 *          receive sections and enables the edma transfer.
 *
 *  \param  chanHandle  [IN]  Handle to the Mcasp Channel
 *
 *  \return  MCASP_COMPLETED if successful
 *           Error code if unsuccessful
 */
int32_t Mcasp_localSmSet(Mcasp_ChannelHandle chanHandle)
{
    Mcasp_Object *instHandle = NULL;
    int32_t status = MCASP_COMPLETED;

    if((NULL != chanHandle) && (NULL != chanHandle->devHandle))
    {

    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    /* Enable the FIFO if used */
    mcaspConfigureFifo(&instHandle->hwInfo,
                       chanHandle,
                       chanHandle->enableHwFifo);

    if (FALSE == chanHandle->isDmaDriven)
    {
        /* Interrupt driven transactions */

        /* When channel state m/c is reactivated, it will require two         *
         * requests to service it. Reset count to ensure this.                */
        chanHandle->dataQueuedOnReset = 0;
        chanHandle->xferinProgressIntmode = (Bool)FALSE;
    }
    else
    {
        /* Start the DMA chanHandle operation.                                */
        Mcasp_enableDMA(chanHandle);
    }

    if (Mcasp_ChanMode_RCV == chanHandle->channelOpMode)
    {
        /* Reset state m/c and frame sync of receive section                  */
        status = Mcasp_localActivateSmFsForRcv(instHandle);
    }
    else
    {
        /* Reset state m/c and frame sync of transmit section                 */
        status = Mcasp_localActivateSmFsForXmt(instHandle);
    }
  }
  else
  {
     status = MCASP_EBADARGS;
  }
  
  return(status);
  
}

/**
 *  \brief   This function configures format, frame sync, and other parameters
 *           related to the xmt section. Also configures the xmt clk section.
 *
 *  \param   instHandle  [IN]  Pointer to the Mcasp driver object
 *  \param   xmtData     [IN]  data for configuring the TX section
 *
 *  \return  MCASP_COMPLETED  - Successful completion of read
 *          MCASP_EBADARGS   - Invalid parameters
 *
 */
int32_t Mcasp_localConfigXmtSection(Mcasp_Object       *instHandle,
                                  Mcasp_HwSetupData  *const xmtData)
{
    int32_t   status     = MCASP_COMPLETED;
    uint8_t   xCnt       = 0x00;
    uint32_t  xMin       = 0x00;
    uint32_t  xMax       = 0x00;
    uint32_t  retryCount = 5u;
    uint32_t  tempVal    = 0x00;
    uint32_t xCntTemp   = 0x00;
    uint8_t  xMinTemp   = 0x00;
    uint8_t  xMaxTemp   = 0x00;

    if((NULL != instHandle)
           && (NULL != xmtData)
           && (0 != (instHandle->hwInfo.regs)))
   {
    /* Configure TXMASK register                                              */
    McASPTxFmtMaskSet(instHandle->hwInfo.regs, xmtData->mask);

    /* Reset the XSMRST bit in GBLCTL register                                */
    mcaspBitRemoveGblXCtl(instHandle, ~((uint32_t) MCASP_GBLCTLX_XSMRST_MASK));

    /* Set the ROT field based on the word bits order */
    if(instHandle->XmtObj.wordBitsSelect == Mcasp_WordBitsSelect_MSB) {
        /* Shift right 'rot' number of nibbles to make the MSB reach the lower bits from the serializer to the host memory */
        uint32_t rot = 8-(instHandle->XmtObj.roundedWordWidth*2);
        xmtData->fmt = (xmtData->fmt & (~MCASP_TXFMT_XROT_MASK)) | (rot << MCASP_TXFMT_XROT_SHIFT);
    }

    /* Configure TXFMT register                                               */
    McASPTxFmtSet(instHandle->hwInfo.regs, xmtData->fmt);

    /* Reset the XFRST register in GBLCTL                                     */
    mcaspBitRemoveGblXCtl(instHandle, ~((uint32_t) MCASP_GBLCTLX_XFRST_MASK));

    /* Configure TXFMCTL register                                             */
    McASPTxFrameSyncCfg(
        instHandle->hwInfo.regs,
        (xmtData->frSyncCtl &
         (uint32_t) MCASP_RXFMCTL_RMOD_MASK) >> MCASP_RXFMCTL_RMOD_SHIFT,
        (xmtData->frSyncCtl &
         (uint32_t) MCASP_RXFMCTL_FRWID_MASK) >> MCASP_RXFMCTL_FRWID_SHIFT,
        (xmtData->frSyncCtl &
         ((uint32_t) MCASP_RXFMCTL_FSRP_MASK |
          (uint32_t) MCASP_RXFMCTL_FSRM_MASK)) >> MCASP_RXFMCTL_FSRP_SHIFT);

    if ((uint32_t) MCASP_TXFMCTL_FSXM_INTERNAL ==
        (((uint32_t) MCASP_TXFMCTL_FSXM_MASK & xmtData->frSyncCtl)
         >> MCASP_TXFMCTL_FSXM_SHIFT))
    {
        McASPPinDirOutputSet(instHandle->hwInfo.regs, (uint32_t) MCASP_PIN_AFSX);
    }

    mcaspBitRemoveGblXCtl(
        instHandle,
        ~((uint32_t) MCASP_GBLCTLX_XHCLKRST_MASK
          | (uint32_t) MCASP_GBLCTLX_XCLKRST_MASK
          | (uint32_t) MCASP_GBLCTLX_XSRCLR_MASK));


    /* Configure XTDM register                                                */
    McASPTxTimeSlotSet(instHandle->hwInfo.regs, xmtData->tdm);

    /* Configure XCLKCHK register                                             */
    McASPTxClkCheckRegWrite(instHandle->hwInfo.regs, xmtData->clk.clkChk);

    McASPTxClkPolaritySet(instHandle->hwInfo.regs,
                          (xmtData->clk.clkSetupClk &
                           (uint32_t) MCASP_ACLKXCTL_CLKXP_MASK));

    McASPTxHFClkPolaritySet(instHandle->hwInfo.regs,
                            ((xmtData->clk.clkSetupHiClk &
                              (uint32_t) MCASP_AHCLKXCTL_HCLKXP_MASK) <<
                             MCASP_AHCLKXCTL_HCLKXP_SHIFT));
    if ((xmtData->clk.clkSetupClk &
         (uint32_t) MCASP_ACLKXCTL_ASYNC_MASK) ==
        (uint32_t) MCASP_ACLKXCTL_ASYNC_MASK)
    {
        McASPTxRxClkSyncDisable((uint32_t)instHandle->hwInfo.regs);
    }
    else
    {
        McASPTxRxClkSyncEnable((uint32_t)instHandle->hwInfo.regs);
    }

    McASPTxClkCfg(instHandle->hwInfo.regs,
                  ((xmtData->clk.clkSetupClk &
                    (uint32_t) MCASP_ACLKXCTL_CLKXM_MASK) |
                   (xmtData->clk.clkSetupHiClk &
                    (uint32_t) MCASP_AHCLKXCTL_HCLKXM_MASK)),
                  ((xmtData->clk.clkSetupClk &
                    (uint32_t) MCASP_ACLKXCTL_CLKXDIV_MASK) >>
                   MCASP_ACLKXCTL_CLKXDIV_SHIFT),
                  ((xmtData->clk.clkSetupHiClk &
                    (uint32_t) MCASP_AHCLKXCTL_HCLKXDIV_MASK) >>
                   MCASP_AHCLKXCTL_HCLKXDIV_SHIFT));

    /* Sequence of start: starting hclk first                                 */
    mcaspBitSetGblXCtl(instHandle, (uint32_t) MCASP_GBLCTLX_XHCLKRST_MASK);

    /* start ACLKX only if internal clock is used */
    if ((uint32_t) MCASP_ACLKXCTL_CLKXM_INTERNAL ==
        ((xmtData->clk.clkSetupClk & (uint32_t) MCASP_ACLKXCTL_CLKXM_MASK) >>
         MCASP_ACLKXCTL_CLKXM_SHIFT))
    {
        mcaspBitSetGblXCtl(instHandle, (uint32_t) MCASP_GBLCTLX_XCLKRST_MASK);
        McASPPinDirOutputSet(instHandle->hwInfo.regs, (uint32_t) MCASP_PIN_ACLKX);

    }

    /* Configure AHCLKXCTL register                                           */
    if ((uint32_t) MCASP_AHCLKXCTL_HCLKXM_INTERNAL ==
        ((xmtData->clk.clkSetupHiClk & (uint32_t) MCASP_AHCLKXCTL_HCLKXM_MASK) >>
         MCASP_AHCLKXCTL_HCLKXM_SHIFT))
    {
        McASPPinDirOutputSet(instHandle->hwInfo.regs, (uint32_t) MCASP_PIN_AHCLKX);
    }

    /* Configure XEVTCTL register                                             */
    if (Mcasp_TX_CLK_FAIL == (Mcasp_TX_CLK_FAIL & xmtData->intCtl))
    {
        uint32_t tempValue = 0x00;
        tempValue = McASPTxClkCheckRegRead(instHandle->hwInfo.regs);
        /* now read the counter value and set val +1 as max and val -1 as min */
        xCntTemp = ((tempValue & (uint32_t) MCASP_TXCLKCHK_XCNT_MASK) >>
                    MCASP_TXCLKCHK_XCNT_SHIFT);
        xCnt     = (uint8_t) xCntTemp;
        xMaxTemp = (xCnt + (uint8_t) 3U);
        xMinTemp = (xCnt - (uint8_t) 3U);
        xMin     = (uint32_t) xMinTemp;
        xMax     = (uint32_t) xMaxTemp;

        if (xCnt >= 0xFDU)
        {
            xMax = 255u;
        }

        if (xCnt <= 3u)
        {
            xMin = 0u;
        }

        /* now write the value to the register                                */
        tempValue &= ~(MCASP_TXCLKCHK_XMAX_MASK |
                       MCASP_TXCLKCHK_XMIN_MASK);
        McASPTxClkCheckRegWrite(instHandle->hwInfo.regs, tempValue);

        McASPTxClkCheckConfig(instHandle->hwInfo.regs,
                              (xmtData->clk.clkChk &
                               (uint32_t) MCASP_TXCLKCHK_XPS_MASK),
                              (uint8_t) xMin, (uint8_t) xMax);

        /* check if the clock has stablised without any errors                */
        while (retryCount > 0)
        {
            retryCount--;
            /* write to the XCLK FAIL register to clear the failure bit       */
            tempVal = McASPTxStatusGet(instHandle->hwInfo.regs);

            McASPTxStatusSet(instHandle->hwInfo.regs,
                             (tempVal | (uint32_t) MCASP_TXSTAT_XCKFAIL_MASK));

            Osal_delay(10);

            tempVal = McASPTxStatusGet(instHandle->hwInfo.regs);
            /* verify if the clock failure is detected. if not detected then  *
             * we can retry else we can continue with the intialisation       */
            if (Mcasp_TX_CLK_FAIL != (tempVal & (uint32_t) Mcasp_TX_CLK_FAIL))
            {
                break;
            }
        }

        if (0x00U == retryCount)
        {
            /* setting the clock failure interrupt failed                     */
            status = MCASP_EBADARGS;
        }

        McASPTxIntEnable(instHandle->hwInfo.regs, Mcasp_TX_CLK_FAIL);

#if defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_K2G)
        /* set the AMUTE register XCLK bit                                    */
        tempVal=McASPAmuteGetQuery(instHandle->hwInfo.regs);
        tempVal |= (MCASP_AMUTE_XCKFAIL_ENABLE << MCASP_AMUTE_XCKFAIL_SHIFT);
        McASPAmuteRegWrite(instHandle->hwInfo.regs,tempVal);
#endif      
    } else {
           uint32_t tempVal = 0x00;

                    /* write to the XCLK FAIL register to clear the failure bit       */
            tempVal = McASPTxStatusGet(instHandle->hwInfo.regs);

            McASPTxStatusSet(instHandle->hwInfo.regs,
                             (tempVal | (uint32_t) MCASP_TXSTAT_XCKFAIL_MASK));

            Osal_delay(10);
    }

    /* Configure XINTCTL register                                             */
    McASPTxIntEnable(instHandle->hwInfo.regs, xmtData->intCtl);


#ifndef Mcasp_LOOPJOB_ENABLED
    /* copy the user supplied interrupt enable mask                           */
    instHandle->XmtObj.userIntValue = xmtData->intCtl;

#else
    /* Non Const variable assignment, fix for Misra C                         */
    instHandle->XmtObj.userIntValue = instHandle->XmtObj.userIntValue;
#endif /* Mcasp_LOOPJOB_ENABLED  */

    /* Configure XEVTCTL register                                             */
    McASPTxRxDMAEvtCntrlWrite(instHandle->hwInfo.regs, (uint8_t) TX,
                              xmtData->evtCtl);
   
   }
   else
   {
	   status = MCASP_EBADARGS;
   }
    return (status);
}


/**
 *  \brief   This function configures the format, frame sync, and other params
 *           related to the rcv section. Also configures the rcv clk section.
 *
 *  \param   instHandle      [IN]     Handle to the McASP instance
 *  \param   rcvData     [IN]     Receive related parameters
 *  \return
 *           MCASP_COMPLETED   - Successful completion of read
 *           MCASP_EBADARGS    - Invalid parameters or Invalid handle
 *
 */

int32_t Mcasp_localConfigRcvSection(Mcasp_Object       *instHandle,
                                  Mcasp_HwSetupData  *const rcvData)
{
    int32_t   status     = MCASP_COMPLETED;
    uint8_t   rCnt       = 0x00;
    uint32_t  rMin       = 0x00;
    uint32_t  rMax       = 0x00;
    uint32_t  retryCount = 5u;
    uint32_t  tempVal    = 0x00;
    uint32_t rCntTemp   = 0x00;
    uint8_t  rMinTemp   = 0x00;
    uint8_t  rMaxTemp   = 0x00;

    if((NULL != instHandle)
          && (NULL != rcvData)
          && (0 != instHandle->hwInfo.regs))
    {      
          

    /* Configure RMASK register                                               */
    McASPRxFmtMaskSet(instHandle->hwInfo.regs, rcvData->mask);

    /* Reset the RSMRST bit in GBLCTL register                                */
    mcaspBitRemoveGblRCtl(instHandle, ~((uint32_t) MCASP_GBLCTLR_RSMRST_MASK));

	/* Set the ROT field based on the word bits order */
	if(instHandle->RcvObj.wordBitsSelect == Mcasp_WordBitsSelect_MSB) {
	    /* Shift right 'rot' number of nibbles to make the MSB reach the lower bits in the serializer */
	    uint32_t rot = 8-(instHandle->RcvObj.roundedWordWidth*2);
	    rcvData->fmt = (rcvData->fmt & (~MCASP_RXFMT_RROT_MASK)) | (rot << MCASP_RXFMT_RROT_SHIFT);
	}

    /* Configure RFMT register                                                */
    McASPRxFmtSet(instHandle->hwInfo.regs, rcvData->fmt);

    mcaspBitRemoveGblRCtl(instHandle, ~((uint32_t) MCASP_GBLCTLR_RFRST_MASK));

    /* Configure RXFMCTL register                                             */
    McASPRxFrameSyncCfg(
        instHandle->hwInfo.regs,
        (rcvData->frSyncCtl &
         (uint32_t) MCASP_RXFMCTL_RMOD_MASK) >> MCASP_RXFMCTL_RMOD_SHIFT,
        (rcvData->frSyncCtl &
         (uint32_t) MCASP_RXFMCTL_FRWID_MASK) >> MCASP_RXFMCTL_FRWID_SHIFT,
        (rcvData->frSyncCtl &
         ((uint32_t) MCASP_RXFMCTL_FSRP_MASK |
          (uint32_t) MCASP_RXFMCTL_FSRM_MASK)) >> MCASP_RXFMCTL_FSRP_SHIFT);

    if ((uint32_t) MCASP_RXFMCTL_FSRM_INTERNAL ==
        (((uint32_t) MCASP_RXFMCTL_FSRM_MASK & rcvData->frSyncCtl) >>
         MCASP_RXFMCTL_FSRM_SHIFT))
    {
        McASPPinDirOutputSet(instHandle->hwInfo.regs, (uint32_t) MCASP_PIN_AFSR);
    }

    /* Reset RHCLKRST, RCLKRST, RSRCLR in GBLCTL                              */
    mcaspBitRemoveGblRCtl(
        instHandle,
        ~((uint32_t) MCASP_GBLCTLR_RHCLKRST_MASK
          | (uint32_t) MCASP_GBLCTLR_RCLKRST_MASK
          | (uint32_t) MCASP_GBLCTLR_RSRCLR_MASK));

    /* Configure it completely before starting the clocks                     */
    /* Configure RTDM register                                                */
    McASPRxTimeSlotSet(instHandle->hwInfo.regs, rcvData->tdm);

    /* Configure RXCLKCHK register                                            */
    McASPRxClkCheckRegWrite(instHandle->hwInfo.regs,
                            rcvData->clk.clkChk);

    McASPRxClkPolaritySet(instHandle->hwInfo.regs,
                          (rcvData->clk.clkSetupClk &
                           (uint32_t) MCASP_ACLKRCTL_CLKRP_MASK));

    McASPRxHFClkPolaritySet(instHandle->hwInfo.regs,
                            ((rcvData->clk.clkSetupHiClk &
                              (uint32_t) MCASP_AHCLKRCTL_HCLKRP_MASK) <<
                             MCASP_AHCLKRCTL_HCLKRP_SHIFT));

    McASPRxClkCfg(instHandle->hwInfo.regs,
                  ((rcvData->clk.clkSetupClk &
                    (uint32_t) MCASP_ACLKRCTL_CLKRM_MASK) |
                   (rcvData->clk.clkSetupHiClk &
                    (uint32_t) MCASP_AHCLKRCTL_HCLKRM_MASK)),
                  ((rcvData->clk.clkSetupClk &
                    (uint32_t) MCASP_ACLKRCTL_CLKRDIV_MASK) >>
                   MCASP_ACLKRCTL_CLKRDIV_SHIFT),
                  ((rcvData->clk.clkSetupHiClk &
                    (uint32_t) MCASP_AHCLKRCTL_HCLKRDIV_MASK) >>
                   MCASP_AHCLKRCTL_HCLKRDIV_SHIFT));
    /* Sequence of start: starting hclk first                                 */
    /* start AHCLKR                                                           */
    mcaspBitSetGblRCtl(instHandle, (uint32_t) MCASP_GBLCTLR_RHCLKRST_MASK);

    /* start ACLKR only if internal clock is used*/
    if ((uint32_t) MCASP_ACLKRCTL_CLKRM_INTERNAL ==
        ((rcvData->clk.clkSetupClk & (uint32_t) MCASP_ACLKRCTL_CLKRM_MASK) >>
         MCASP_ACLKRCTL_CLKRM_SHIFT))
    {
        mcaspBitSetGblRCtl(instHandle, (uint32_t) MCASP_GBLCTLR_RCLKRST_MASK);
        McASPPinDirOutputSet(instHandle->hwInfo.regs, (uint32_t) MCASP_PIN_ACLKR);
    }

    /* Configure ACLKRCTL register                                            */

    if ((uint32_t) MCASP_AHCLKRCTL_HCLKRM_INTERNAL ==
        ((rcvData->clk.clkSetupHiClk & (uint32_t) MCASP_AHCLKRCTL_HCLKRM_MASK) >>
         MCASP_AHCLKRCTL_HCLKRM_SHIFT))
    {
        McASPPinDirOutputSet(instHandle->hwInfo.regs, 0x40000000U);
    }

    /* Configure REVTCTL register                                             */
    if (Mcasp_RX_CLK_FAIL == (Mcasp_RX_CLK_FAIL & rcvData->intCtl))
    {
        uint32_t tempValue = 0x00;
        tempValue = McASPRxClkCheckRegRead(instHandle->hwInfo.regs);
        /* now read the counter value and set val +1 as max and val -1 as min */
        rCntTemp = ((tempValue & (uint32_t) MCASP_RXCLKCHK_RCNT_MASK) >>
                    MCASP_RXCLKCHK_RCNT_SHIFT);
        rCnt     = (uint8_t) rCntTemp;
        rMaxTemp = rCnt + (uint8_t) 3U;
        rMinTemp = rCnt - (uint8_t) 3U;

        rMax = (uint32_t) rMaxTemp;
        rMin = (uint32_t) rMinTemp;

        if (rCnt >= 0xFDU)
        {
            rMax = 255u;
        }

        if (rCnt <= 3u)
        {
            rMin = 0u;
        }

        /* now write the value to the register                                */
        tempValue &= ~((uint32_t) MCASP_RXCLKCHK_RMAX_MASK |
                       (uint32_t) MCASP_RXCLKCHK_RMIN_MASK);
        McASPRxClkCheckRegWrite(instHandle->hwInfo.regs, tempValue);
        McASPRxClkCheckConfig(instHandle->hwInfo.regs,
                              (rcvData->clk.clkChk &
                               (uint32_t) MCASP_RXCLKCHK_RPS_MASK),
                              (uint8_t) rMin,
                              (uint8_t) rMax);

        /* check if the clock has stablised without any errors                */
        while (retryCount > 0)
        {
            retryCount--;
            /* write to the RCLK FAIL register to clear the failure bit       */
            tempVal = McASPRxStatusGet(instHandle->hwInfo.regs);

            McASPRxStatusSet(instHandle->hwInfo.regs,
                             (tempVal | (uint32_t) MCASP_RXSTAT_RCKFAIL_MASK));

            /* wait for the reading to be taken                               */
            Osal_delay(10);

            tempVal = McASPRxStatusGet(instHandle->hwInfo.regs);
            /* verify if the clock failure is detected. if detected then      *
             * we can retry else we can continue with the intialisation       */
            if ((uint32_t) MCASP_RXSTAT_RCKFAIL_MASK !=
                (tempVal & (uint32_t) MCASP_RXSTAT_RCKFAIL_MASK))
            {
                break;
            }
        }

        if (0x00U == retryCount)
        {
            /* setting the clock failure interrupt failed                     */
            status = MCASP_EBADARGS;
        }


        McASPRxIntEnable(instHandle->hwInfo.regs, Mcasp_RX_CLK_FAIL);
#if defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_K2G)
        /* set the AMUTE register RCLK bit                                    */
        tempVal=McASPAmuteGetQuery(instHandle->hwInfo.regs);
        tempVal |= (MCASP_AMUTE_RCKFAIL_ENABLE << MCASP_AMUTE_RCKFAIL_SHIFT);
        McASPAmuteRegWrite(instHandle->hwInfo.regs,tempVal);
#endif      
    } else {
                    /* write to the XCLK FAIL register to clear the failure bit       */
            tempVal = McASPRxStatusGet(instHandle->hwInfo.regs);

            McASPRxStatusSet(instHandle->hwInfo.regs,
                             (tempVal | (uint32_t) MCASP_RXSTAT_RCKFAIL_MASK));

            Osal_delay(10);
    }

    McASPRxIntEnable(instHandle->hwInfo.regs, rcvData->intCtl);


#ifndef Mcasp_LOOPJOB_ENABLED
    /* copy the user supplied interrupt enable mask                           */
    instHandle->RcvObj.userIntValue = rcvData->intCtl;

#else
    /* Non Const variable assignment fix for Misra C Fixes
     *                    */
    instHandle->RcvObj.userIntValue = instHandle->RcvObj.userIntValue;
#endif /* Mcasp_LOOPJOB_ENABLED  */

    McASPTxRxDMAEvtCntrlWrite(instHandle->hwInfo.regs, (uint8_t) RX,
                              rcvData->evtCtl);
   }
   else
   {
	   status = MCASP_EBADARGS;
   }                           
    return (status);
}


/**
 *  \brief  This function resets the bits related to transmit in XGBLCTL.
 *
 *  \param  hMcasp  [IN] Pointer to the Mcasp Hardware info structure
 *
 *  \return
 *          MCASP_COMPLETED   - Successful completion
 *          MCASP_EBADARGS    - Invalid parameters or Invalid handle
 *
 */
int32_t Mcasp_localResetXmt(Mcasp_HwHandle  hMcasp)
{
    int32_t   status = MCASP_COMPLETED;

    if((NULL != hMcasp) && (0 != hMcasp->regs))
    {
      McASPTxReset(hMcasp->regs);
    }
    else
    {
		status = MCASP_EBADARGS;
	}
    return (status);

}

/**
 *  \brief   This function resets the bits related to receive in RGBLCTL.
 *
 *  \param   hMcasp  [IN] Pointer to the Mcasp Hardware info structure
 *
 *  \return
 *           MCASP_COMPLETED   - Successful completion
 *           MCASP_EBADARGS    - Invalid parameters or Invalid handle
 *
 */
int32_t Mcasp_localResetRcv(Mcasp_HwHandle  hMcasp)
{
    int32_t  status = MCASP_COMPLETED;

    if((NULL != hMcasp) && (0 != hMcasp->regs))
    {
      McASPRxReset(hMcasp->regs);
    }  
    else
    {
		status = MCASP_EBADARGS;
	}
    return (status);

}


#ifdef Mcasp_LOOPJOB_ENABLED
/** Todo: implement common function when loopjob supported for UDMA */

#else
/**
 *  \brief   This callback processes the next request in queue and disables the
 *           channel if the last packet.  Triggers application callback if
 *           requested upon successful completion of packet processing.
 *
 *  \param   chanHandle [IN]    McASP channel handle
 *  \param   status     [IN]    status of DMA transaction
 *
 *  \return  Nothing
 *
 */
void Mcasp_commonDmaCallback(Mcasp_ChannelHandle chanHandle, int32_t status)
{
    Mcasp_Object           *instHandle = NULL;
    Bool                    falseWhile = TRUE;
    uint32_t                dlbMode    = 0;
    int32_t  retVal     = MCASP_COMPLETED;
    uint32_t                hwiKey     = 0x00;
    uint32_t             	key        = 0;
    uint32_t                ret_flag   = 0U;
    /* enter critical section                                         		  */
	key = HwiP_disable();
    do
    {
        falseWhile = FALSE;

        if (1u == chanHandle->submitCount)
        {
            /* This is the last packet available with the driver.Hence we will*
             * stop the EDMA and then proceed to process the packet           */
            Mcasp_disableDMA(chanHandle);

            instHandle = (Mcasp_Object *)chanHandle->devHandle;
            if(NULL != instHandle)
            {
            /* close the IOP now                                              */
            if (MCASP_OUTPUT == chanHandle->mode)
            {

                if (MCASP_TX_UNDERRUN ==
                    (MCASP_TX_UNDERRUN & chanHandle->userIntValue))
                {
                    uint32_t tempVal = 0x0;
                    tempVal  = McASPTxIntrStatusGet(instHandle->hwInfo.regs);
                    tempVal &= (~MCASP_TX_UNDERRUN);
                    McASPTxIntEnable(instHandle->hwInfo.regs,
                                     tempVal);
                }

                /* update the status of the IOP                               */
                if (MCASP_COMPLETED != status)
                {
                    /* update the status of the IOP as error                  */
                    chanHandle->currentPacketErrorStatus = MCASP_EABORT;
                }
                else
                {
                    chanHandle->currentPacketErrorStatus = MCASP_COMPLETED;
                }
                ret_flag = 1U;
#ifdef BIOS_SWI
               Swi_post((Swi_Handle) & instHandle->fifoSwiObject);
#else
             Mcasp_swiTxFifo(&(instHandle->XmtObj),instHandle);
#endif
                break;
            }
            else
            {

                if (MCASP_RX_OVERRUN ==
                    (MCASP_RX_OVERRUN & chanHandle->userIntValue))
                {
                    uint32_t tempVal = 0x0;
                    tempVal  = McASPRxIntrStatusGet(instHandle->hwInfo.regs);
                    tempVal &= (~MCASP_RX_OVERRUN);
                    McASPRxIntEnable(instHandle->hwInfo.regs,
                                     tempVal);
                }
            }

            dlbMode  = McASPDlbRegRead(instHandle->hwInfo.regs);
            dlbMode &= MCASP_LBCTL_DLBEN_MASK;

            if (MCASP_LBCTL_DLBEN_ENABLE == dlbMode)
            {
                (void)Mcasp_localDeactivateSmFsForRcv(instHandle);
                (void)Mcasp_localDeactivateSmFsForXmt(instHandle);
            }
            else
            {
                /* stop the clocks and the EDMA transfers                     */
                /* stop the xmt/rcv state machine.                            */
                if (Mcasp_ChanMode_RCV == chanHandle->channelOpMode)
                {
                    /* Reset state m/c & frame sync of receive section        */
                    status = Mcasp_localDeactivateSmFsForRcv(instHandle);

                    /* reenable the RCV overrun error                         */
                    if (MCASP_RX_OVERRUN ==
                        (MCASP_RX_OVERRUN & chanHandle->userIntValue))
                    {
                        McASPRxIntEnable(instHandle->hwInfo.regs,
                                         MCASP_RX_OVERRUN);
                    }

                    /* Disable the FIFO */
                    mcaspConfigureFifo(&instHandle->hwInfo,
                                       chanHandle,
                                       FALSE);
                }
            }

            /* clear the DMA error bits that have been set                    */
            Mcasp_clearDmaErrors(chanHandle);
          }
          else
          {
			  status = MCASP_EINVALIDVAL;
		  } 
        }

        if (MCASP_COMPLETED != status)
        {
            /* clear the DMA error bits that have been set                    */
            Mcasp_clearDmaErrors(chanHandle);

            /* update the status of the IOP as error                          */
            chanHandle->currentPacketErrorStatus = MCASP_EABORT;
            ret_flag = 1U;
        }
        else
        {
            chanHandle->currentPacketErrorStatus = MCASP_COMPLETED;

            /* reduce the submit count as the packet callback is completed    */
            chanHandle->submitCount--;
        }
    if(ret_flag == 0U)
    {
        /* complete the receive IOP now                                       */
	    hwiKey = HwiP_disable();
        if (((int32_t)TRUE) == Osal_Queue_empty((&(chanHandle->queueFloatingList))))
        {
            /* This cannot happen, if it happens then it is a sprurios one    */
		    HwiP_restore(hwiKey);
            break;
        }
        else
        {
            /* Get the packet from the top of the queue (atomic operation)        */
            chanHandle->tempPacket = (MCASP_Packet *) Osal_Queue_get((&(chanHandle->queueFloatingList)));

            /* end the critical section                                           */
		    HwiP_restore(hwiKey);

            instHandle = (Mcasp_Object *)chanHandle->devHandle;
            if(NULL != instHandle)
            {
            /* If stopSmFs flag for the channel is false and pause is not issued  *
             * control will go in the if part. In case when stopSmFS is issued or *
             * pause is issued, control will go in else part                      */

            if ((((MCASP_INPUT == chanHandle->mode)
                && (FALSE == instHandle->stopSmFsRcv))
                || ((MCASP_OUTPUT == chanHandle->mode)
                    && (FALSE == instHandle->stopSmFsXmt)))
                && (FALSE == chanHandle->paused))
            {
                /* Now that we have done with the last data packet - we check if  *
                 * next packet is available for transmission. Even if we are not  *
                 * having a valid packet - previous programming of linkchannels   *
                 * (designed in such a way) to send out null buffer Also note that*
                 * Mcasp_isValidPacket function will set the                      *
                 * chanHandle->dataPacket with next (current now) data packet from*
                 * queue                                                          */
                if (Mcasp_STATUS_VALID == Mcasp_localIsValidPacket(chanHandle))
                {
                    /* This is a valid data request. Call function to process it. *
                     * If DMA cannot be programmed properly with request contents,*
                     * abort all queued up requests and putstate-machine intoreset*/
                    if (MCASP_COMPLETED != (Mcasp_localDmaProcessPkt(
                                               chanHandle,
                                               chanHandle->dataPacket)))
                    {
                        Mcasp_localCancelAndAbortAllIo(chanHandle);
                    }
                }
            }
            else
            {
                /* Control will come over here when either of receive or transmit *
                 * state machine stop command is issued for receive or transmit   *
                 * channel.If the nextFlag is already set indicates that its time *
                 * to reset the state machines and disable the edma transfer      */
                if (TRUE == chanHandle->nextFlag)
                {
                    chanHandle->nextFlag = FALSE;

                    if (FALSE == chanHandle->paused)
                    {
                    dlbMode  = McASPDlbRegRead(instHandle->hwInfo.regs);
                    dlbMode &= MCASP_LBCTL_DLBEN_MASK;

                    if (MCASP_LBCTL_DLBEN_ENABLE == dlbMode)
                        {
                            /* Stop both RCV and XMT state m/cs                   */
                            /* before touching McASP registers, place receive     *
                             * section in reset                                   */
                        retVal = Mcasp_localResetRcv(&instHandle->hwInfo);

                        if (MCASP_COMPLETED != retVal)
                        {
                            break;
                        }
                            /* before touching McASP registers, place transmit    *
                             * section in reset                                   */
                        retVal = Mcasp_localResetXmt(&instHandle->hwInfo);
                        if (MCASP_COMPLETED != retVal)
                        {
                            break;
                        }
                        }
                        else
                        {
                            if (MCASP_INPUT == chanHandle->mode)
                            {
                                /* stop Receive state m/c */
                                /* before touching McASP registers, place receive *
                                 * section in reset                               */
                            retVal = Mcasp_localResetRcv(&instHandle->hwInfo);
                            if (MCASP_COMPLETED != retVal)
                            {
                                break;
                            }
                            }
                            else
                            {
                                /* stop Transmit state m/c*/
                                /* before touching McASP registers, place transmit*
                                 * section in reset                               */
                            retVal = Mcasp_localResetXmt(&instHandle->hwInfo);

                            if (MCASP_COMPLETED != retVal)
                            {
                                break;
                            }
                            }
                        }

                        Mcasp_disableDMA(chanHandle);
                    }
                }
            }

            chanHandle->isTempPacketValid = TRUE;
            Mcasp_localCompleteCurrentIo(chanHandle);

#if defined (BIOS_PWRM_ENABLE) && !defined (Mcasp_LOOPJOB_ENABLED)
            /* check if the driver is waiting to go to sleep or process DVFS event*
             * (only if the application has requested PWRM support)               */
            if (TRUE == instHandle->pscPwrmEnable)
            {
                Mcasp_localHandlePwrmEvent(instHandle,chanHandle);
            }
#endif /* #ifdef BIOS_PWRM_ENABLE  */
	      }
        }
    }
   } while (falseWhile);

    /* exit critical section                                          		  */
	HwiP_restore(key);
    return;
}
#endif /* Mcasp_LOOPJOB_ENABLED */

/**
 *  \brief  For the transmit operation, the eDMA channel's destination
 *          port is tied to the MCASP DAT port. In case of receive, the eDMA
 *          channel's source port is tied to the MCASP DAT port. The source
 *          address for transmit eDMA channel and the destination address for
 *          the receive eDMA channel are set here.
 *
 *  \param  chanp      [IN]    Pointer to channel
 *  \param  ioPacket   [IN]    Pointer to request to be processed
 *
 *  \return MCASP_COMPLETED, if the address is set correctly
 *          ERROR ID otherwise
 *
 */
int32_t Mcasp_localDmaProcessPkt(void* chanp, MCASP_Packet *ioPacket)
{
    Mcasp_Object           *instHandle  = NULL;
    Mcasp_ChannelHandle     chanHandle  = NULL;
    Mcasp_PktAddrPayload   *payLoad     = NULL;
    int32_t                   status      = MCASP_COMPLETED;
    Bool                    falsewhile  = (Bool)TRUE;

    /* Validate pointers and parameters                                       */
    if((NULL != chanp) && (NULL != ioPacket) && (NULL != ((Mcasp_ChannelHandle)chanp)->devHandle))
    {
    chanHandle = (Mcasp_ChannelHandle)chanp;
    do
    {
        falsewhile = (Bool)FALSE;

        instHandle = (Mcasp_Object *)chanHandle->devHandle;

        if ((Mcasp_ChanMode_RCV != chanHandle->channelOpMode)
            && (Mcasp_ChanMode_XMT_DIT == chanHandle->channelOpMode))
        {
            /* The data should be a payload structure                         */
           payLoad = (Mcasp_PktAddrPayload *)ioPacket->addr;
           if(NULL != payLoad)
           {   
            if (TRUE == payLoad->writeDitParams)
            {
                /* DIT Mode: for DIT mode as of now each packet (IOP)         *
                 * carries/should carry 1 super frame = 192 frames = 384 sub  *
                 * frames of data max                                         */
                status = mcaspWriteChanStatRam(
                            &(instHandle->hwInfo),
                            (Mcasp_ChStatusRam *)payLoad->chStat);

                if (MCASP_COMPLETED != status)
                {
                    status = MCASP_ABORTED;
                }
                else
                {
                    status = mcaspWriteUserDataRam(
                                &(instHandle->hwInfo),
                                (Mcasp_UserDataRam *)payLoad->userData);

                    if (MCASP_COMPLETED != status)
                    {
                        status = MCASP_ABORTED;
                    }
                }
            }
          }
          else
          {
			  status = MCASP_EINVALIDVAL;
		  }  
        }

        if (MCASP_COMPLETED == status)
        {
            /* we are going to update the paramset from DMA callback context.    *
             * That means the one of the param sets are having audio data         *
             * just completed data request and one having currently loaded (active*
             * ) data request Current index is pointing only latest paramset      *
             * (that is active)  so move the index                                */

            /* Todo: Refactor into EDMA code */
            Mcasp_localGetNextIndex(chanHandle);

            /* Link the packet                                                    */
            status = Mcasp_submitPktToDma(chanHandle,ioPacket);
        }

    }while(falsewhile);
   } 
   else
   {
	   status = MCASP_EBADARGS;
   }

    return (status);
}

/**
 *  \brief   This function completes the current pending request and then
 *           invokes the application registered callback.
 *
 *  \param   chanHandle   [IN]  Handle to the channel
 *
 *  \return  None
 *
 */
int32_t inCount=0,outCount=0;
void Mcasp_localCompleteCurrentIo(Mcasp_ChannelHandle chanHandle)
{
    MCASP_Packet    *ioPacket     = NULL;

#ifndef Mcasp_LOOPJOB_ENABLED
    Mcasp_Object  *instHandle   = NULL;

#endif

   if(NULL != chanHandle)
   {

#ifndef Mcasp_LOOPJOB_ENABLED
    if(NULL != chanHandle->devHandle)
    {
     instHandle = (Mcasp_Object *)chanHandle->devHandle;

#endif

    if (TRUE == chanHandle->isTempPacketValid)
    {
        ioPacket = chanHandle->tempPacket;
        chanHandle->isTempPacketValid = (Bool)FALSE;
    }
    else
    {
        ioPacket = chanHandle->dataPacket;
    }
    if(chanHandle->mode == MCASP_INPUT)
    {
        inCount++;
    }
    else
    {
        outCount++;
    }
#ifndef Mcasp_LOOPJOB_ENABLED
    /* reduce the dependency count                                            */
    Mcasp_localLpscOff(instHandle);
#endif

    if (NULL != ioPacket)
    {
        /* call the completion callback function registered with us           *
         * during channel creation                                            */
        if (NULL != chanHandle->cbFxn)
        {
            /*  Application callback                                          */
            (*chanHandle->cbFxn)((void*)chanHandle->cbArg,ioPacket);
        }
    }
    chanHandle->dataPacket = NULL;
    chanHandle->userDataBufferSize = 0;
#ifndef Mcasp_LOOPJOB_ENABLED
   }
#endif

  }  
    
}

/**
 *  \brief   This function aborts all the pending requests in the queue
 *
 *  \param   chanHandle   [IN]  Handle to the channel
 *
 *  \return  MCASP_COMPLETED if successful, error code other wise 
 *
 */
int32_t Mcasp_localCancelAndAbortAllIo(Mcasp_ChannelHandle chanHandle)
{
    uint32_t               dlbMode    = 0u;
    Mcasp_Object        *instHandle = NULL;
    int32_t                status = MCASP_COMPLETED;

    if((NULL != chanHandle) && (NULL != chanHandle->devHandle))
    {
    chanHandle->submitCount--;

    chanHandle->dataPacket->status = MCASP_ABORTED;

    Mcasp_localCompleteCurrentIo(chanHandle);

    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    /* While aborting care should be taken about DLB mode otherwise           *
     * aborting packets in only one direction will make the packet in         *
     * other direction not to return                                          */
    dlbMode = McASPDlbRegRead(instHandle->hwInfo.regs);

    if (MCASP_LBCTL_DLBEN_ENABLE == dlbMode)
    {
        status = Mcasp_localAbortReset((Mcasp_ChannelHandle)&(instHandle->RcvObj));
        if (MCASP_COMPLETED == status)
        {
            status = Mcasp_localAbortReset((Mcasp_ChannelHandle)&(instHandle->XmtObj));
        }
    }
    else
    {
        status = Mcasp_localAbortReset(chanHandle);
    }
   }
   else
   {
	   status = MCASP_EBADARGS;
   }
    return (status);
}

/**
 *  \brief   This function sets the GBLCTL bit and wait and checks that bit is
 *           set or not
 *
 *  \param   instHandle  [IN]  pointer to the mcasp instance object
 *  \param   bitMaskVal  [IN]  mask bit value
 *
 *  \return  None
 *
 */
  void mcaspBitSetGblCtl(const Mcasp_Object *instHandle,uint32_t bitMaskVal)
{
    uint32_t timeout = Mcasp_GBLCTL_TIMEOUT;
    Bool   isTask  = (Bool)FALSE;

    uint32_t tempVal;
    if(NULL != instHandle)
    {
    tempVal = McASPGlobalCtlGet(instHandle->hwInfo.regs);
    /* If already this bit is set then don't set again                        */
    if ((tempVal & bitMaskVal) != bitMaskVal)
    {
        tempVal |= bitMaskVal;

        McASPGlobalCtlSet(instHandle->hwInfo.regs, tempVal);

        tempVal = McASPGlobalCtlGet(instHandle->hwInfo.regs);

        while (((tempVal & bitMaskVal) != bitMaskVal) && (timeout > 0))
        {
            /* reduce the timout count value                                  */
            timeout--;

            isTask = (Osal_ThreadType_Task==Osal_getThreadType());

            /* wait for 1 tick only if called from a task context             */
            if (TRUE == isTask)
            {
                Osal_delay(1);
            }
            tempVal = McASPGlobalCtlGet(instHandle->hwInfo.regs);
        }
        assert(0U != timeout);
    }
  }  
}

/*
 *  \brief Initializes McASP driver's data structures
 *
 *  This function initializes the McASP driver's internal data structures
 *  used by the driver for the mute and loop job. These data structures are
 *  aligned to the proper cache line boundary here.
 *
 *  \param  instNum [IN]  instance num of the data structure to initialise
 *
 *  \return Nothing
 *
 */
  void mcaspInit(uint32_t instNum)
{
    uintptr_t temp_var = 0U;
    if (instNum < MCASP_CNT)
    {
#ifdef Mcasp_LOOPJOB_ENABLED
        /* initialise the mcasp device driver internal buffers                */
        memset((void *) &Mcasp_loopDstBuf[instNum], 0x00,
               sizeof (Mcasp_TempBuffer));
        memset((void *) &Mcasp_loopSrcBuf[instNum], 0x00,
               sizeof (Mcasp_TempBuffer));

        /* align the buffers to the cache line size                           */
        temp_var = ((uintptr_t) & Mcasp_loopSrcBuf[instNum].scratchBuf
                   + (uintptr_t) 0x7FU) & ~(uintptr_t) 0x7FU;
        Mcasp_loopSrcBuf[instNum].scratchBuffer =
            (uintptr_t *) temp_var;

        temp_var = ((uintptr_t) & Mcasp_loopDstBuf[instNum].scratchBuf
                   + (uintptr_t) 0x7FU) & ~(uintptr_t) 0x7FU;
        Mcasp_loopDstBuf[instNum].scratchBuffer =
            (uintptr_t *) temp_var;
#endif  /* Mcasp_LOOPJOB_ENABLED */
        temp_var = (((uintptr_t)Mcasp_muteBuf[instNum].scratchBuf + 0x7FU) & ~((uintptr_t)0x7FU));
        Mcasp_muteBuf[instNum].scratchBuffer = (uintptr_t *)(temp_var);
            
    }
    /* initialisation of driver data structures is completed                  */
    return;
}

/**
 *  \brief   Writes a packet of data to the output channel of the driver
 *           This function is called by the IDriver submit function. This
 *           function is called with handle to the o/p channel and the pointer
 *           to ioRequest structure which takes a set of information need for
 *           the IO.
 *
 *  \param   chanHandle  [IN]   Handle to the McASP channel
 *  \param   ioPacket    [IN]   io request information structure
 *
 *  \return MCASP_COMPLETED or Error code
 *
 */
  int32_t mcaspSubmitReq(Mcasp_ChannelHandle chanHandle,
                            MCASP_Packet         *ioPacket)
{
    Mcasp_Object           *instHandle  = NULL;
    Mcasp_PktAddrPayload   *payLoad     = NULL;
    int32_t                   status      = MCASP_COMPLETED;
    uint32_t                  hwiKey      = 0;
    Bool                    falsewhile  = (Bool)TRUE;
    void*                     pktAddr     = NULL;

#ifdef Mcasp_LOOPJOB_ENABLED
    Bool   chanStopped = (Bool) FALSE;
#endif

   if((NULL != chanHandle) && (NULL != chanHandle->devHandle) && (NULL != ioPacket))
   {

    /* check for the valid packet size                                        */
    assert((0 != ioPacket->size)
        && (Mcasp_MAX_PACKET_SIZE >= 
            ioPacket->size/chanHandle->noOfSerAllocated));

    do
    {
        falsewhile = (Bool)FALSE;
        instHandle = (Mcasp_Object *)chanHandle->devHandle;

        if (TRUE == instHandle->isDataBufferPayloadStructure)
        {
            payLoad = (Mcasp_PktAddrPayload *)ioPacket->addr;
            if(NULL != payLoad) 
            {          
              pktAddr = payLoad->addr;
		    }
		    else
		    {
				status = MCASP_EINVALIDVAL;
				break;
			}
        }
        else
        {
            pktAddr = ioPacket->addr;
        }

        if(NULL != pktAddr)
        {

        /* maintain cache coherency                                           */
        if (MCASP_INPUT == chanHandle->mode)
        {
            /* Cleans and invalidate the D Cache in MVA way                   */
            if (TRUE == instHandle->enablecache)
            {
                CacheP_wbInv(pktAddr, ioPacket->size);
            }

#ifdef Mcasp_LOOPJOB_ENABLED
            /* check if the state machine is stopped. if the state machine is *
             * stopped then we will load the packets in to the pending queue  */
            if ((Bool) TRUE == instHandle->stopSmFsRcv)
            {
                chanStopped = (Bool) TRUE;
            }
#endif
        }
        else
        {
            /* clean the D Cache in MVA way                                   */
            if (TRUE == instHandle->enablecache)
            {
                CacheP_wb(pktAddr, ioPacket->size);
            }

#ifdef Mcasp_LOOPJOB_ENABLED
            /* check if the state machine is stopped. if the state machine is *
             * stopped then we will load the packets in to the pending queue  */
            if ((Bool) TRUE == instHandle->stopSmFsXmt)
            {
                chanStopped = (Bool) TRUE;
            }
#endif
        }

        /*  Enter critical section to protect the submit count                */
        hwiKey = HwiP_disable();

#ifdef Mcasp_LOOPJOB_ENABLED
        if ((chanHandle->maxActiveSubmit <= chanHandle->submitCount) ||
            ((Bool) TRUE == chanStopped) ||
#else
        /* We now have 3 packets loaded in the EDMA                           */
        if (((chanHandle->maxActiveSubmit + 1U) <= chanHandle->submitCount) ||

#endif
            (TRUE == chanHandle->paused) ||
            (Mcasp_DriverState_PWRM_SUSPEND == instHandle->devState))
        {
            /* Already enough requests are in active queue.Hence load in to   *
             * the pending queue                                              */
            chanHandle->submitCount++;
            Osal_Queue_put((Osal_Queue_handle(&(chanHandle->queueReqList))),(Osal_Queue_Elem *)ioPacket);

            /* restore the interrupts                                         */
            HwiP_restore(hwiKey);
        }
        else
        {
            /* Process this packet immediately as active queue is empty       */
            chanHandle->submitCount++;
            Osal_Queue_put((Osal_Queue_handle(&(chanHandle->queueFloatingList))),(Osal_Queue_Elem *)ioPacket);

            /* restore the interrupts                                         */
            HwiP_restore(hwiKey);

            /* load this request in to the EDMA paramsets                     */
            Mcasp_localLoadPktToDma(chanHandle,ioPacket);
        }
        /* return the status as pending as the packet will complete later     */
        status = MCASP_PENDING;
	   }
	   else
	   {
		  status = MCASP_EINVALIDVAL;
	   }
    }while(falsewhile);
  }
  else
  {
	 status = MCASP_EBADARGS;
  }  
    return status;
}

/**
 * \brief   Swi thread which handles the Mcasp module interrupts
 *
 * \param   arg0  [IN]  The pointer to the ISR object holds instance pointer.
 * \param   arg1  [IN]  unused argument
 *
 * \return  None
 *
 */
  void Mcasp_localIsrSwiFxn(void * arg0,void * arg1)
{
    uint32_t            count      = 0;
    Mcasp_Object     *instHandle = NULL;

    /* An interrupt has occured and it could be because of any one of the     *
     * mcasp instances and also either a TX or RX section interrupt.Hence we  *
     * will check all the instances to find which interrupt has occured. Also *
     * note that here we are only intrested in logging the interrupts for the *
     * error conditions only                                                  */

    /* we are only checking the instances which are currently active          */
    for (count = 0; count < MCASP_CNT; count++)
    {
        /* check if the instance has registered for interrupts                */
        if (((Bool) TRUE == Mcasp_module.isrObject[count].isIsrRegistered[0])
            && ((Bool) TRUE == Mcasp_module.isrObject[count].isIsrRegistered[1])
            && (NULL != Mcasp_module.isrObject[count].instHandle))
        {
           instHandle = Mcasp_module.isrObject[count].instHandle;
           if(NULL != instHandle)
           {
            /* check if the RX channel has registered the interrupts          */
            if (TRUE == Mcasp_module.isrObject[count].chanEnabled[0])
            {
                /* check if atleast one error has occured                     */
                if (Mcasp_RSTAT_ERROR ==
                    ((uint32_t) Mcasp_RSTAT_ERROR &
                     (McASPRxStatusGet(instHandle->hwInfo.regs))))
                {
                    mcaspIsrInput((void *)&(instHandle->RcvObj));
                }
            }

            /* check if the TX channel has registered the interrupts          */
            if (TRUE == Mcasp_module.isrObject[count].chanEnabled[1])
            {
                if (Mcasp_XSTAT_ERROR ==
                    ((uint32_t) Mcasp_XSTAT_ERROR &
                     (McASPTxStatusGet(instHandle->hwInfo.regs))))

                {
                    mcaspIsrOutput((void *)&(instHandle->XmtObj));
                }
            }
         }   
            
        }
    }
}


/**
 * \fn        void mcaspIsr()
 *
 * \brief   This function is the interrupt service routine for the mcasp driver.
 *
 * \param   arg  [IN]  The instance number of the first instance to register
 *                     the ISR.
 *
 * \return  None
 *
 */

void mcaspIsr(void * arg)
{
    /* we have got the interrupt for the Mcasp. we need to check which        *
     * instance has generated this interrupt and which section TX or RX. We   *
     * defer the procesing to the Swi thread for the mcasp driver             */

    /* Trigger the SWI thread to handle the interrupts                        *
     * Note : The "arg" here is the instance number of the instance which has *
     * first registered the isr. please note that any valid instance is OK as *
     * all the instances have the same SWI task handle.                       */
    /* Swi_post((Swi_Handle)arg); */
    Mcasp_localIsrSwiFxn(NULL,NULL);
}


/**
 *  \brief   Collect the error stats reading the error register
 *  \param   chanHandle   [IN]  Handle to the mcasp channel
 *  \param   errStatus   [IN]   Pointer to the error data structure to be populated
 *  \return  MCASP_COMPLETED if success
 *           Error code in case of failure
 */

int32_t Mcasp_localCollectRcvErrorStats(Mcasp_ChannelHandle chanHandle,Mcasp_errCbStatus   *errStatus)
{

   Mcasp_Object         *instHandle = NULL;
   int32_t               status     = MCASP_COMPLETED;


   if((NULL != errStatus) && (NULL != chanHandle) && (NULL != chanHandle->devHandle))
   { 
    instHandle = (Mcasp_Object *)chanHandle->devHandle;
    
    /* Initialize */
    errStatus->isClkFailErr=FALSE;
    errStatus->isDMAErr=FALSE;
    errStatus->isRcvOvrRunOrTxUndRunErr=FALSE;
    errStatus->isSyncErr=FALSE;
    errStatus->retVal=MCASP_COMPLETED;

    /* Read interrupt-status register.                                    */
    chanHandle->intStatus = (uint32_t) McASPRxStatusGet(
        instHandle->hwInfo.regs);


    /*Interrupt status word to be written back to reset status bits       */
    McASPRxStatusSet(instHandle->hwInfo.regs,
                     chanHandle->intStatus);


    if ((Mcasp_DMAERR == (Mcasp_DMAERR & chanHandle->intStatus)))
    {
       status = MCASP_EBADIO;
       errStatus->isDMAErr = (Bool) TRUE;
    }

    if ((Mcasp_RCV_OVERRUN ==
        (Mcasp_RCV_OVERRUN & chanHandle->intStatus)))
    {
        status = MCASP_EBADIO;
        errStatus->isRcvOvrRunOrTxUndRunErr = (Bool) TRUE;
    }

    if ((Mcasp_RX_CLK_FAIL ==
        (Mcasp_RX_CLK_FAIL & McASPRxIntrStatusGet(
              instHandle->hwInfo.regs))) && (MCASP_COMPLETED == status))
    {
        if (Mcasp_RX_CLK_FAIL ==
           (Mcasp_RX_CLK_FAIL & chanHandle->intStatus))
        {
             status = MCASP_EBADIO;
             errStatus->isClkFailErr = (Bool) TRUE;
         }
     }
        /* no sync error check for burst mode                             */
     if (((uint32_t) 0 !=     ((instHandle->mcaspHwSetup.rx.frSyncCtl &
            (uint32_t) MCASP_RXFMCTL_RMOD_MASK) >>
            MCASP_RXFMCTL_RMOD_SHIFT)) && (MCASP_COMPLETED == status))
     {
        if ((Mcasp_SYNCERR ==  (Mcasp_SYNCERR & chanHandle->intStatus)))
        {
          status = MCASP_ETIMEOUT;
          errStatus->isClkFailErr = (Bool) TRUE;
        }
     }
     errStatus->retVal = (int32_t) status;
  }
  else
  {
	  status = MCASP_EBADARGS;
  }

     return(status);
}

/**
 *  \brief   This function is a ISR function.it will be called when Mcasp
 *           receive interrupt is triggered.
 *
 *  \param   chanp   [IN]  Handle to the mcasp channel
 *
 *  \return  None
 *
 */
void mcaspIsrInput(void * chanp)
{
    Mcasp_Object         *instHandle = NULL;
    Mcasp_ChannelHandle   chanHandle = NULL;
    Bool                  falsewhile = (Bool)TRUE;
    int32_t               status     = MCASP_COMPLETED;
    uint32_t                dlbMode    = 0;
    Mcasp_errCbStatus   errStatuts =
    {FALSE, FALSE, FALSE, FALSE, MCASP_COMPLETED};

    do
    {
        falsewhile  = (Bool)FALSE;
        chanHandle = (Mcasp_ChannelHandle)chanp;
        if((NULL != chanHandle) && (NULL != ((Mcasp_ChannelHandle)chanp)->devHandle))
        {
        instHandle = (Mcasp_Object *)chanHandle->devHandle;

        /* Interrupt handling starts                                          */

        /* The driver is in DMA mode and it is enough if we handle errors     */

        status=Mcasp_localCollectRcvErrorStats(chanHandle ,&errStatuts);

        if (MCASP_COMPLETED != status)
        {
            /* call the application registered callback if any                */
            if (NULL != (chanHandle->gblErrCbk))
            {
                (chanHandle->gblErrCbk)(errStatuts);
            }

            /* For sync error we call the application callback and we         *
             * abort all other pending IOPs also                              */
            if (MCASP_ETIMEOUT == status)
            {
                /* While aborting care should be taken about DLB mode         *
                 * otherwise aborting packets in only one direction will      *
                 * make the packet in other direction not to return           */
                dlbMode = McASPDlbRegRead(instHandle->hwInfo.regs);

                if ((uint32_t) MCASP_LBCTL_DLBEN_ENABLE == dlbMode)
                {
                    status = Mcasp_localAbortReset(&(instHandle->RcvObj));

                    if (MCASP_COMPLETED == status)
                    {
                        status = Mcasp_localAbortReset(&(instHandle->XmtObj));
                    }
                }
                else
                {
                    status = Mcasp_localAbortReset(chanHandle);
                }
                break;
            } 
            else 
            {
             /* if the error is a non- framesync error - we just send error    *
             * status for the current packet in the callback function and     *
             * continue with other packets for xfer                           */

                /* Disable Serializer, State machine and Frame sync of RCV    *
                 * Section. Also Disable EDMA Transfer.                       */
                status = Mcasp_localSmReset(chanHandle);

                /* Todo: this probably isn't the best function to implement.
                 * Need to revisit after source has been merged. */
                /* Todo: note here we are replacing logic which set ccnt to 0,
                 * whereas later we were setting ccnt to 1.  Further investigation
                 * needed to determine if 0 is acceptable to both.
                 */
                Mcasp_initiateDummyDMAXfer(chanHandle);

                chanHandle->currentPacketErrorStatus = status;

                /* Enable Serializer, State machine and Frame sync of RCV     *
                 * Section.Also Enable EDMA Transfer.                         */
                (void)Mcasp_localSmSet(chanHandle);
            }/*for errors except sync errors*/
        }/*dma transfer for all errors*/
      }
    }while(falsewhile);
}
/**
 *  \brief   Collect the error stats reading the error register
 *  \param   chanHandle     [IN]  Handle to the mcasp channel
 *  \param   errStatus [IN]  Pointer to the Mcasp_errCbStatus structure
 *
 *  \return  MCASP_COMPLETED if successful, error code otherwise
 *
 */

int32_t Mcasp_localCollectXmtErrorStats(Mcasp_ChannelHandle chanHandle,Mcasp_errCbStatus   *errStatus)
{

    Mcasp_Object         *instHandle = NULL;
    int32_t               status     = MCASP_COMPLETED;


    if((NULL != errStatus) && (NULL != chanHandle) && (NULL != chanHandle->devHandle))
    {
    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    /* Initialize */
    errStatus->isClkFailErr=FALSE;
    errStatus->isDMAErr=FALSE;
    errStatus->isRcvOvrRunOrTxUndRunErr=FALSE;
    errStatus->isSyncErr=FALSE;
    errStatus->retVal=MCASP_COMPLETED;

    /* Read interrupt-status register.                                    */
    chanHandle->intStatus = (uint32_t) McASPTxStatusGet(
        instHandle->hwInfo.regs);


    /*Interrupt status word to be written back to reset status bits       */
    McASPTxStatusSet(instHandle->hwInfo.regs,
                     chanHandle->intStatus);


    if (((Mcasp_DMAERR) == (Mcasp_DMAERR & chanHandle->intStatus)))
     {
         status = MCASP_EBADIO;
         errStatus->isDMAErr = (Bool) TRUE;
     }

     if (((Mcasp_XMT_UNDERRUN) ==
         (Mcasp_XMT_UNDERRUN & chanHandle->intStatus)))
     {
         status = MCASP_EBADIO;
         errStatus->isRcvOvrRunOrTxUndRunErr = (Bool) TRUE;
     }

     /* check the mcasp clock failure interrupt only if it is enabled  *
      * in interrupt control register                                  */
     if ((Mcasp_TX_CLK_FAIL ==
          (Mcasp_TX_CLK_FAIL & McASPTxIntrStatusGet(
               instHandle->hwInfo.regs))) && (MCASP_COMPLETED == status))
     {
         if (Mcasp_TX_CLK_FAIL ==
             (Mcasp_TX_CLK_FAIL & chanHandle->intStatus))
         {
             status = MCASP_EBADIO;
             errStatus->isClkFailErr = (Bool) TRUE;
         }
     }

     /* no sync error check for burst mode                             */
     if (((uint32_t) 0 !=
          ((instHandle->mcaspHwSetup.tx.frSyncCtl &
            (uint32_t) MCASP_TXFMCTL_XMOD_MASK) >>
           MCASP_TXFMCTL_XMOD_SHIFT)) && (MCASP_COMPLETED == status))
     {
         if ((Mcasp_SYNCERR ==
             (Mcasp_SYNCERR & chanHandle->intStatus)))
         {
             status = MCASP_ETIMEOUT;
             errStatus->isSyncErr = (Bool) TRUE;
         }
     }

     errStatus->retVal = (int32_t) status;
    }
    else
    {
		status = MCASP_EBADARGS;
	}
    
     return(status);
}
/**
 *  \brief   This function is the ISR function. This is called when Mcasp0 XMT
 *           interrupt is triggered
 *
 *  \param   chanp  [IN]  pointer.The pointer to the channel handle.
 *
 *  \return  None
 *
 */
void mcaspIsrOutput(void * chanp)
{
    Mcasp_Object           *instHandle = NULL;
    Mcasp_ChannelHandle     chanHandle = NULL;
    Bool                    falsewhile = (Bool)TRUE;
    int32_t                 status     = MCASP_COMPLETED;
    uint32_t                  dlbMode    = 0;
    Mcasp_errCbStatus   errStatuts = {FALSE, FALSE, FALSE, FALSE, 0};

    do
    {
        falsewhile = (Bool)FALSE;

        chanHandle = (Mcasp_ChannelHandle)chanp;
        if((NULL != chanHandle) && (NULL != chanHandle->devHandle))
        {
        instHandle = (Mcasp_Object *)chanHandle->devHandle;

        /* Interrupt handling starts                                          */

        status=Mcasp_localCollectXmtErrorStats((Mcasp_ChannelHandle)chanp,&errStatuts);
        if (MCASP_COMPLETED != status)
        {
            /* call the application registered callback if any                */
            if (NULL != (chanHandle->gblErrCbk))
            {
                (chanHandle->gblErrCbk)(errStatuts);
            }

            /* at this point we will decide whether to continue other         *
             * pending IOPs  or abort - it depends on error                   */
            /* For sync error we call the application callback and we         *
             * abort all other pending IOPs also                              */
            if (MCASP_ETIMEOUT == status)
            {
                /* While aborting care should be taken about DLB mode         *
                 * otherwise aborting packets in only one direction will      *
                 * make the packet in other direction not to return           */
                dlbMode = McASPDlbRegRead(instHandle->hwInfo.regs);

                if (CSL_MCASP_DLBCTL_DLBEN_ENABLE == dlbMode)
                {
                    status = Mcasp_localAbortReset(&(instHandle->RcvObj));
                    if (MCASP_COMPLETED == status)
                    {
                        Mcasp_localAbortReset(&(instHandle->XmtObj));
                    }
                }
                else
                {
                    status = Mcasp_localAbortReset(chanHandle);
                }
                break;
            } 
            else
            {
               /* if the error is a non- framesync error - we just send error    *
                * status for the current packet in the callback function and     *
                * continue with other packets for xfer                           */

                /* Disable Serializer, State machine and Frame sync of RCV    *
                 * Section.Also Disable EDMA Transfer.                        */
                status = Mcasp_localSmReset(chanHandle);

                /* Todo: note here we are replacing logic which set ccnt to 1,
                 * whereas before it was setting ccnt to 0.  Further investigation
                 * needed to determine if 0 is acceptable to both.
                 */
                Mcasp_initiateDummyDMAXfer(chanHandle);

                /* When an underrun occurs we reset the MCASP and restart the
                 * the transfers. In case FIFO is used, MCASP expects the FIFO
                 * to be at threshold level before starting it. So we do a manul
                 * trigger to fill the FIFO and avoid next underrun, if this is
                 * not done we will never be able to come out of underrun
                 * scenario. */
                Mcasp_triggerDMA(chanHandle);

                chanHandle->currentPacketErrorStatus = status;

                /* Enable Serializer, State machine and Frame sync of RCV     *
                 * Section. Also Enable EDMA Transfer.                        */
                (void)Mcasp_localSmSet(chanHandle);
            }/*for errors except sync errors*/
        }/*dma transfer for all errors*/
      }  
    }while(falsewhile);
}


/**
 *  \brief    This function sets the GBLCTLR bit and wait and check that bit is
 *            set or not
 *
 *  \param    instHandle  [IN]  pointer to the mcasp instance object
 *  \param    bitMaskVal  [IN]  mask bit value
 *
 *  \return   None
 *
 */
  void mcaspBitSetGblRCtl(const Mcasp_Object *instHandle,uint32_t bitMaskVal)
{
    uint32_t timeout = Mcasp_GBLCTL_TIMEOUT;
    Bool   isTask  = (Bool)FALSE;
    uint32_t tempVal1 = 0x00;
    uint32_t tempVal2 = 0x00;

    if(NULL != instHandle)
    {
    tempVal1 = McASPGlobalCtlGet(instHandle->hwInfo.regs);
    tempVal2 = McASPRxGlobalCtlGet(instHandle->hwInfo.regs);
    /* If already this bit is set then don't set again                        */
    if ((tempVal1 & bitMaskVal) != bitMaskVal)
    {
        if (FALSE == instHandle->RcvObj.isDmaDriven)
        {
           Mcasp_disableInterrupt(instHandle->RcvObj.cpuEventNum,instHandle->RcvObj.intNum); 
        }

        tempVal2 |= bitMaskVal;
        McASPRxGlobalCtlSet(instHandle->hwInfo.regs, tempVal2);
        tempVal1 = McASPGlobalCtlGet(instHandle->hwInfo.regs);

        while (((tempVal1 & bitMaskVal) !=
                bitMaskVal) && (timeout > 0U))
        {
            /* decrement the timeout count                                    */
            timeout--;

            isTask = (Bool)(Osal_getThreadType()==Osal_ThreadType_Swi);

            /* wait for 1 tick only if called from a task context             */
            if (TRUE == isTask)
            {
                Osal_delay(1);
            }
            tempVal1 = McASPGlobalCtlGet(instHandle->hwInfo.regs);
        }

        assert(0U != timeout);

        if (FALSE == instHandle->RcvObj.isDmaDriven)
        {
            /* Leave critical section */
           if(instHandle->RcvObj.userIntValue) {
              Mcasp_enableInterrupt(instHandle->RcvObj.cpuEventNum,instHandle->RcvObj.intNum);
           }      
            
        }
    }
  }  
}

/**
 *  \brief   This function removes the GBLCTLR bit and wait and checks that
 *           bit is set or not
 *
 *  \param   instHandle  [IN]  pointer to the mcasp instance object
 *  \param   bitMaskVal  [IN]  mask bit value
 *
 *  \return  None
 *
 */
  void mcaspBitRemoveGblRCtl(const Mcasp_Object *instHandle, uint32_t bitMaskVal)
{
    uint32_t   temp_bitMaskVal = 0u;
    uint32_t   timeout         = Mcasp_GBLCTL_TIMEOUT;
    Bool     isTask          = (Bool)FALSE;
    uint32_t tempVal1        = 0U;
    uint32_t tempVal2        = 0U;

    temp_bitMaskVal = (0xFFFFFFFFu & (uint32_t)bitMaskVal);

   if(NULL != instHandle)
   { 
    tempVal1 = McASPGlobalCtlGet(instHandle->hwInfo.regs);
    tempVal2 = McASPRxGlobalCtlGet(instHandle->hwInfo.regs);
    /* If already this bit is set then don't set again                        */
    if ((tempVal1 & ~temp_bitMaskVal)
        == ((uint32_t) 0x0000FFFFU & ~temp_bitMaskVal))
    {
        tempVal2 &= (0xFFFF0000U | temp_bitMaskVal);
        McASPRxGlobalCtlSet(instHandle->hwInfo.regs, tempVal2);
        tempVal1 = McASPGlobalCtlGet(instHandle->hwInfo.regs);

        while (((tempVal1 & ~temp_bitMaskVal) ==
                ((uint32_t) 0x0000FFFFU & ~temp_bitMaskVal)) &&
               (timeout > (uint32_t) 0U))
        {
            /* decrement the timeout count                                    */
            timeout--;

            isTask = (Bool)(Osal_getThreadType()==Osal_ThreadType_Swi);

            /* wait for 1 tick only if called from a task context             */
            if (TRUE == isTask)
            {
                Osal_delay(1);
            }

            tempVal1 = McASPGlobalCtlGet(instHandle->hwInfo.regs);
        }

        assert(0U != timeout);
    }
  }  
}

/**
 *  \brief   This function sets the GBLCTLX bit and wait and check that bit is
 *           set or not
 *
 *  \param   instHandle  [IN]  pointer to the mcasp instance object
 *  \param   bitMaskVal  [IN]  mask bit value
 *
 *  \return  None
 *
 */
  void mcaspBitSetGblXCtl(const Mcasp_Object *instHandle, uint32_t bitMaskVal)
{
    uint32_t timeout = Mcasp_GBLCTL_TIMEOUT;
    Bool   isTask  = (Bool)FALSE;
    uint32_t tempVal1 = (uint32_t) 0x00U;
    uint32_t tempVal2 = (uint32_t) 0x00U;

    if(NULL != instHandle)
    {
    tempVal1 = McASPGlobalCtlGet(instHandle->hwInfo.regs);
    tempVal2 = McASPTxGlobalCtlGet(instHandle->hwInfo.regs);

    /* If already this bit is set then don't set again                        */
    if ((tempVal1 & bitMaskVal) != bitMaskVal)
    {
        if (FALSE == instHandle->XmtObj.isDmaDriven)
        {
           Mcasp_disableInterrupt(instHandle->XmtObj.cpuEventNum,instHandle->XmtObj.intNum);
        }
        tempVal2 |= bitMaskVal;

        McASPTxGlobalCtlSet(instHandle->hwInfo.regs, tempVal2);

        tempVal1 = McASPGlobalCtlGet(instHandle->hwInfo.regs);

        while (((tempVal1 & bitMaskVal) !=
            bitMaskVal) && (timeout > 0))
        {
            /* reduce the retry count value                                   */
            timeout--;

            isTask = (Bool)(Osal_getThreadType()==Osal_ThreadType_Swi);

            /* wait for 1 tick only if called from a task context             */
            if (TRUE == isTask)
            {
                Osal_delay(1);
            }
            tempVal1 = McASPGlobalCtlGet(instHandle->hwInfo.regs);
        }

        assert(0U != timeout);

        if (FALSE == instHandle->XmtObj.isDmaDriven)
        {
            /* Leave critical section                                         */
           if(instHandle->XmtObj.userIntValue) {
              Mcasp_enableInterrupt(instHandle->XmtObj.cpuEventNum,instHandle->RcvObj.intNum);
           }  
        }
    }
  }  
}

/**
 *  \brief  This function removes the GBLCTLX bit and wait and checks that bit is
 *          set or not.
 *
 *  \param  instHandle  [IN]  pointer to the mcasp instance object
 *  \param  bitMaskVal  [IN]  mask bit value
 *
 *  \return None
 *
 */
  void mcaspBitRemoveGblXCtl(const Mcasp_Object *instHandle, uint32_t bitMaskVal)
{
    volatile uint32_t temp_bitMaskVal = 0u;
    volatile uint32_t temp_bitMaskVal2 = 0U;
    uint32_t          timeout         = Mcasp_GBLCTL_TIMEOUT;
    Bool            isTask          = (Bool)FALSE;
    uint32_t          tempVal1 = 0U;
    uint32_t          tempVal2 = 0U;

    if(NULL != instHandle)
    {
    tempVal1 = McASPGlobalCtlGet(instHandle->hwInfo.regs);
    tempVal2 = McASPTxGlobalCtlGet(instHandle->hwInfo.regs);
    temp_bitMaskVal = (0xFFFFFFFFu & (uint32_t)bitMaskVal);

    /* If already this bit is set then don't set again                        */
    temp_bitMaskVal2 = (uint32_t) 0x0000FFFFU & ~temp_bitMaskVal;
    if ((tempVal1 & ~temp_bitMaskVal) == temp_bitMaskVal2)
    {
        tempVal2  = McASPTxGlobalCtlGet(instHandle->hwInfo.regs);
        tempVal2 &= (uint32_t) (0xFFFF0000U | temp_bitMaskVal);
        McASPTxGlobalCtlSet(instHandle->hwInfo.regs, tempVal2);

        tempVal1 = McASPGlobalCtlGet(instHandle->hwInfo.regs);

        while (((tempVal1 & ~temp_bitMaskVal) == temp_bitMaskVal2)
               && (timeout > 0))
        {
            /* reduce the retry count value                                   */
            timeout--;

            isTask = (Bool)(Osal_getThreadType()==Osal_ThreadType_Swi);

            /* wait for 1 tick only if called from a task context             */
            if (TRUE == isTask)
            {
                Osal_delay(1);
            }

            tempVal1 = McASPGlobalCtlGet(instHandle->hwInfo.regs);
        }
        assert(0U != timeout);
    }
  } 
}

/*
 *  This function configures the required serializer to transmit mode.
 *
 * \param    hMcasp   [IN]  pointer to the Mcasp Hardware information structure
 * \param    serNum   [IN]  serializer number to configure
 * \param    eb       [OUT] pointer to error block
 *
 * \return
 *           MCASP_COMPLETED   - Successful completion
 *           MCASP_EBADARGS    - Invalid parameters or Invalid handle
 */
  void mcaspSetSerXmt(Mcasp_HwHandle       hMcasp,
                           Mcasp_SerializerNum  serNum)
{
    if( (NULL != hMcasp) && (serNum < hMcasp->numOfSerializers) )
    { 
      McASPSerializerTxSet(hMcasp->regs, serNum);
      McASPPinDirOutputSet(hMcasp->regs, ((uint32_t) 1U << serNum));
    }
}

/*
 *  This function configures the required serializer to receive mode.
 *
 * \param    hMcasp   [IN]  pointer to the Mcasp Hardware information structure
 * \param    serNum   [IN]  serializer number to configure
 * \param    eb       [OUT] pointer to error block
 *
 * \return  None
 *
 */

  void mcaspSetSerRcv(Mcasp_HwHandle       hMcasp,
                           Mcasp_SerializerNum  serNum)
{
    if( (NULL != hMcasp) && (serNum < hMcasp->numOfSerializers) )
    { 
      McASPSerializerRxSet(hMcasp->regs, serNum);
      McASPPinDirInputSet(hMcasp->regs, ((uint32_t) 1U << serNum));
    }  
}

/**
 *  \brief    This function enables/disables the DIT mode.
 *
 *  \param    hMcasp      [IN]     Handle to the McASP hardware info structure
 *  \param    ditFlag     [IN]     Value to loaded into the DITCTL register
 *
 *  \return
 *           MCASP_COMPLETED   - Successful completion
 *           MCASP_EBADARGS    - Invalid parameters or Invalid handle
 *
 */

  int32_t mcaspSetDitMode(Mcasp_HwHandle hMcasp,
                             Bool           ditFlag)
{
    int32_t  status = MCASP_COMPLETED;
    uint32_t tempVal = 0x0;

   if(NULL != hMcasp)
   {
    if (TRUE == hMcasp->ditStatus)
    {
        tempVal = McASPGlobalCtlGet(hMcasp->regs);
        /* Reset XSMRST and XFRST in GBLCTL */
        tempVal &= ~((uint32_t) MCASP_GBLCTL_XSMRST_MASK);
        McASPGlobalCtlSet(hMcasp->regs, tempVal);

        tempVal &= ~((uint32_t) MCASP_GBLCTL_XFRST_MASK);
        McASPGlobalCtlSet(hMcasp->regs,
                          (uint32_t) MCASP_GBLCTL_XFRST_RESET);

        /* Configure DITEN bit of DITCTL    */
        McASPDITModeCtlWrite(hMcasp->regs,
                             ((uint32_t) ditFlag << MCASP_TXDITCTL_DITEN_SHIFT));
    }
   }
   else
   {
	   status = MCASP_EBADARGS;
   }
    return (status);
}

/**
 *  \brief    This function registers the interrupt handler for the given
 *            channel.
 *
 *  \param    chanp        [IN]    Pointer to channel object
 *  \param    instNum      [IN]    instance number
 *  \param    evt          [IN]    event number
 *  \param    intNum       [IN]    The interrupt number
 *  \param    intIsr       [IN]    function pointer
 *
 *  \return   none
 *
 */
  void mcaspRegisterInt(void*      chanp,
                        uint32_t   instNum,
                        int32_t   evt,
                        int32_t   intNum,
                        void *  intIsr)
{
    Mcasp_ChannelHandle  chanHandle    = NULL;
      Uns           hwiKey        = 0;
    Mcasp_Object        *instHandle    = NULL;
    void *               arg;
    int32_t  retVal = MCASP_COMPLETED;
    int                  i = 0;
    OsalRegisterIntrParams_t interruptRegParams;
    OsalInterruptRetCode_e OsalInterruptRetCode;
    MuxIntcP_inParams     muxInParams;
    MuxIntcP_outParams    muxOutParams={(uintptr_t)NULL,0U,(MuxIntcFxn)NULL};
    HwiP_Handle			hwiHandle = NULL;
    if((NULL != chanp) && (NULL != ((Mcasp_ChannelHandle)chanp)->devHandle) && (NULL != intIsr))
    {
    /* get the handle to the channel to register the interrupt                */
    chanHandle = (Mcasp_ChannelHandle)chanp;
    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    if ((MCASP_INPUT != chanHandle->mode) && (MCASP_OUTPUT != chanHandle->mode))
    {
        retVal = MCASP_EBADARGS;
    }
    if (MCASP_CNT <= instNum)
    {
        retVal = MCASP_EBADARGS;
    }
    if (MCASP_COMPLETED == retVal)
    {
    hwiKey = (uint32_t)HwiP_disable();

    /* set the variable to indicate that this channel has registered          *
     * interrupts                                                             */
    Mcasp_module.isrObject[instNum].chanEnabled[chanHandle->mode - 1] = (Bool)TRUE;
    
    /* update the information of the instance which is registering the ISR    */
        if ((Bool) FALSE ==
            Mcasp_module.isrObject[instNum].isIsrRegistered[chanHandle->mode -
                                                            1])
        {
            Mcasp_module.isrObject[instNum].isIsrRegistered[chanHandle->mode -
                                                            1] = (Bool) TRUE;
            Mcasp_module.isrObject[instNum].instHandle = instHandle;
        }
        else
        {
            /* interrupt handler is already plugged in for this instance
             *         */
        }

        arg = (void *)Mcasp_module.isrObject[instNum].isrSwiTaskHandle;
               
             /* Initialize with defaults */
        Osal_RegisterInterrupt_initParams(&interruptRegParams);

        if ((chanHandle->muxNum != MCASP_INVALID_MUX_NUM) &&
            (chanHandle->muxInEvent!=MCASP_INVALID_MUX_EVENTNUM)    &&
            (chanHandle->muxInEvent!=MCASP_UNASSIGNED_MUX_EVENTNUM) && 
            (chanHandle->muxOutEvent!=MCASP_INVALID_MUX_EVENTNUM)   &&  
            (chanHandle->muxOutEvent!=MCASP_UNASSIGNED_MUX_EVENTNUM)) 
        {
           /* Setup the Interrupt Mux  */
          muxInParams.arg         = (uintptr_t)arg;
          muxInParams.muxNum      = chanHandle->muxNum;
          muxInParams.muxInEvent  = chanHandle->muxInEvent;
          muxInParams.muxOutEvent = chanHandle->muxOutEvent;
          muxInParams.muxIntcFxn  = (MuxIntcFxn)(intIsr);
          MuxIntcP_create(&muxInParams, &muxOutParams);

          interruptRegParams.corepacConfig.isrRoutine = (void (*)(uintptr_t))muxOutParams.muxIntcFxn;
          interruptRegParams.corepacConfig.arg        = muxOutParams.arg;
        }
        else
        {
           interruptRegParams.corepacConfig.isrRoutine = (void (*)(uintptr_t))intIsr;
           interruptRegParams.corepacConfig.arg      = (uintptr_t)arg;
        }
        
        /* Populate the interrupt parameters */
        interruptRegParams.corepacConfig.name=NULL;
        interruptRegParams.corepacConfig.corepacEventNum=evt; /* Event going in to CPU */
        interruptRegParams.corepacConfig.intVecNum=intNum; /* Host Interrupt vector */

        if ( (evt!=MCASP_INVALID_EVENTNUM)    &&
             (evt!=MCASP_UNASSIGNED_EVENTNUM) && 
             (intNum!=MCASP_INVALID_INTNUM)   &&  
             (intNum!=MCASP_UNASSIGNED_INTNUM))  
        {
          for(i = 0; i < MCASP_CNT; i++)
          {
            if(	(intNum == Mcasp_deviceInstInfo[i].txIntNum) &&
              ( gHwiHandle[i][MCASP_OUTPUT-1] !=NULL) )
            {
                hwiHandle = gHwiHandle[i][MCASP_OUTPUT-1];
                break;
            }

            if((intNum == Mcasp_deviceInstInfo[i].rxIntNum) &&
              ( gHwiHandle[i][MCASP_INPUT-1] !=NULL) )
            {
                hwiHandle = gHwiHandle[i][MCASP_INPUT-1];
                break;
            }
         }

		  if(hwiHandle == NULL)
		  {
              /* Register interrupts */
              OsalInterruptRetCode=Osal_RegisterInterrupt(&interruptRegParams,(HwiP_Handle *)&(gHwiHandle[instNum][chanHandle->mode - 1]));
              if(OsalInterruptRetCode==OSAL_INT_SUCCESS)
              {
                Osal_EnableInterrupt((int32_t)evt,intNum);
              }
              else
              {
                gHwiHandle[instNum][chanHandle->mode - 1]=NULL;
                retVal = MCASP_EBADARGS;
              }
          }
        }
        
    /* Enabling the interrupts                                                */
       HwiP_restore(hwiKey);
    }
    else
    {   /* interrupts cannot be registered for an invalid mcasp instance */ 
        assert(FALSE);
    }
  }
  else
  {
	  retVal = MCASP_EBADARGS;
  }
}

/**
 *  \brief    unregister interrupt handler for the given channel.
 *
 *  \param    devid        [IN]    instance number
 *  \param    evt          [IN]    The event number
 *  \param    intNum       [IN]    The interrupt number
 *  \param    mode         [IN]    input or output
 *
 *  \return   Nothing
 *
 */
  void mcaspUnRegisterInt(uint16_t devid, int32_t evt,int32_t intNum,int32_t mode)
{
    uint32_t        hwiKey        = 0;
    int32_t  retVal = MCASP_COMPLETED;

    if ((MCASP_INPUT != mode) && (MCASP_OUTPUT != mode))
    {
        retVal = MCASP_EBADARGS;
    }
    if ((uint16_t) MCASP_CNT <= devid)
    {
        retVal = MCASP_EBADARGS;
    }
    if (MCASP_COMPLETED == retVal)
    {

    /* disable the interrupts before unregistering the interrupts             */
    hwiKey = HwiP_disable();
    /* indicate that the channel has unregisterd the interrupts               */
    Mcasp_module.isrObject[devid].chanEnabled[mode-1] = (Bool)FALSE;

    Mcasp_module.isrObject[devid].isIsrRegistered[mode - 1] = (Bool) FALSE;
    Mcasp_module.isrObject[devid].instHandle = NULL;

        /* Disable the event now.
         *                                              */
     
        if ( (evt!=MCASP_INVALID_EVENTNUM)    &&
          (evt!=MCASP_UNASSIGNED_EVENTNUM) && 
          (intNum!=MCASP_INVALID_INTNUM)   &&  
          (intNum!=MCASP_UNASSIGNED_INTNUM))   
        {
           Mcasp_disableInterrupt(evt,intNum); 
        } 

        /* Unregister the interrupt now
         **/
     if(gHwiHandle[devid][mode - 1] !=NULL)
     {
        Osal_DeleteInterrupt(gHwiHandle[devid][mode - 1],evt);
        gHwiHandle[devid][mode - 1]=NULL;
     }

    /* Enabling the interrupts                                                */
    HwiP_restore(hwiKey);
}
    else
    {
        assert(FALSE);
    }
}

/**
 *  \brief   This function Deactivates the receive section state machine and
 *           the corresponding frame sync.
 *
 *  \param   instHandle  [IN]  pointer to the Mcasp instance object
 *
 *  \return  None
 *
 */
int32_t Mcasp_localDeactivateSmFsForRcv(const Mcasp_Object *instHandle)
{
   int32_t status = MCASP_COMPLETED;
 
    if(NULL != instHandle)
    {

    /*frame sync*/
    mcaspBitRemoveGblRCtl(instHandle, ~((uint32_t) MCASP_GBLCTLR_RFRST_MASK));

    /*state m/c*/
    mcaspBitRemoveGblRCtl(instHandle, ~((uint32_t) MCASP_GBLCTLR_RSMRST_MASK));

    /*serializer*/
    mcaspBitRemoveGblRCtl(instHandle, ~((uint32_t) MCASP_GBLCTLR_RSRCLR_MASK));
    /* Clear interrupts, if any */
    /* Its important to clear the interrupt status register after stopping
     * serializer, Frame Sync generator etc... as an error could be
     * generated. There could error due to the reason that, we have stopped
     * the serializer and at that point, the frame syncs is being generated
     * (in case of a master) */
    McASPRxStatusSet((uint32_t)instHandle->hwInfo.regs,
                     ((uint32_t) MCASP_RXSTAT_RERR_MASK |
                      (uint32_t) MCASP_RXSTAT_RDMAERR_MASK |
                      (uint32_t) MCASP_RXSTAT_RSTAFRM_MASK |
                      (uint32_t) MCASP_RXSTAT_RDATA_MASK |
                      (uint32_t) MCASP_RXSTAT_RLAST_MASK |
                      (uint32_t) MCASP_RX_STAT_CURRSLOT_EVEN |
                      (uint32_t) MCASP_RX_STAT_CURRSLOT_ODD |
                      (uint32_t) MCASP_RXSTAT_RCKFAIL_MASK |
                      (uint32_t) MCASP_RXSTAT_RSYNCERR_MASK |
                      (uint32_t) MCASP_RXSTAT_ROVRN_MASK));
  }
  else
  {
     status = MCASP_EBADARGS;
  }
  return(status);
}

/**
 *  \brief   This function deactivates the transmit section state machine and
 *           the corresponding frame sync.
 *
 *  \param   instHandle [IN]  Pointer to the mcasp instance object
 *
 *  \return  None
 *
 */
int32_t Mcasp_localDeactivateSmFsForXmt(const Mcasp_Object *instHandle)
{
    int32_t status = MCASP_COMPLETED;
    
    if(NULL != instHandle) 
    {

    /*Start the Serializer, State M/C and Frame Sync Generator*/
    mcaspBitRemoveGblXCtl(instHandle, ~((uint32_t) MCASP_GBLCTLX_XFRST_MASK));
    mcaspBitRemoveGblXCtl(instHandle, ~((uint32_t) MCASP_GBLCTLX_XSMRST_MASK));
    mcaspBitRemoveGblXCtl(instHandle, ~((uint32_t) MCASP_GBLCTLX_XSRCLR_MASK));

    /* Clear interrupts if any */
    /* Its important to clear the interrupt status register after stopping
     * serializer, Frame Sync generator etc... as an error could be
     * generated. There could error due to the reason that, we have stopped
     * the serializer and at that point, the frame syncs is being generated
     * (in case of a master) */
    McASPTxStatusSet((uint32_t)instHandle->hwInfo.regs,
                     ((uint32_t) MCASP_TX_STAT_ERR |
                      (uint32_t) MCASP_TX_STAT_DMAERR |
                      (uint32_t) MCASP_TX_STAT_STARTOFFRAME |
                      (uint32_t) MCASP_TX_STAT_DATAREADY |
                      (uint32_t) MCASP_TX_STAT_LASTSLOT |
                      (uint32_t) MCASP_TX_STAT_CURRSLOT_EVEN |
                      (uint32_t) MCASP_TX_STAT_CURRSLOT_ODD |
                      (uint32_t) MCASP_TXSTAT_XCKFAIL_MASK |
                      (uint32_t) MCASP_TX_STAT_SYNCERR |
                      (uint32_t) MCASP_TX_STAT_UNDERRUN));
   } 
   else
   {
	  status = MCASP_EBADARGS;
   }
   return(status);
}

/**
 *  \brief  This function checks if the requested serialisers are free or not
 *
 *  \param   instHandle  [IN]  pointer to the Mcasp instance object
 *  \param   params      [IN]  Device parameter structure that supplies
 *                            data to initialize the McASP
 *
 *  \return TRUE if all serializers are free (Mcasp_SerializerStatus_FREE)
 *          FALSE if any one of the requested serializer is not free
 *
 */
  Bool mcaspIsRequestedSerzsFree(const Mcasp_Object *instHandle,
                                      void*           params)
{
    Mcasp_ChanParams  *chanParams = NULL;
    uint32_t             count      = 0 ;
    Bool               status     = (Bool)TRUE;
    Bool               falsewhile = (Bool)TRUE;

   if((NULL != instHandle) && (NULL != params))
   {
    do
    {
        falsewhile  = (Bool)FALSE;

        chanParams = (Mcasp_ChanParams *)params;

        for (count = 0; count < chanParams->noOfSerRequested; count++)
        {
            /* Get serializer number requested by user                        */
            if (Mcasp_SerializerStatus_FREE !=
               (instHandle->serStatus[chanParams->indexOfSersRequested[count]]))
            {
                status = (Bool)FALSE;
                break;
            }
        }
    }while(falsewhile);
  }
    return (status);
}

/**
 *  \brief   This function is used to configure the requested serializers in the
 *           receive mode.
 *
 *  \param    instHandle  [IN]   pointer to the Mcasp instance object
 *  \param    params      [IN]   channel parameters given by user
 *
 *  \return   None
 *
 */
  void mcaspMultiSerInitializationRcv(Mcasp_Object *instHandle,
                                           void*           params)
{
    Mcasp_ChanParams     *chanParams = NULL;
    uint32_t               count       = 0;
    uint32_t               serNum      = 0;
    Mcasp_SerializerNum  serializerToConfigure = (Mcasp_SerializerNum)0;

    if((NULL != instHandle) && (NULL != params))
    {
    chanParams = (Mcasp_ChanParams *)params;

    for (count = 0; count < chanParams->noOfSerRequested; count++)
    {
        /* Get serializer number requested by user                            */
        serNum = (uint32_t)chanParams->indexOfSersRequested[count] ;

        if (Mcasp_SerializerStatus_FREE == instHandle->serStatus[serNum])
        {
            /* Configure requested serialzer as receive mode                  */
            instHandle->serStatus[serNum] = Mcasp_SerializerStatus_RCV;
            serializerToConfigure = (Mcasp_SerializerNum)serNum;

            mcaspSetSerRcv(&(instHandle->hwInfo),serializerToConfigure);
        }
    }
  }  
}


/**
 *  \brief   This function configures the requested serializers in the transmit
 *           mode
 *
 *  \param    instHandle  [IN]   pointer to the Mcasp instance object
 *  \param    params      [IN]   channel parameters given by user
 *
 *  \return   None
 *
 */

  void mcaspMultiSerInitializationXmt(Mcasp_Object *instHandle,
                                           void*           params)
{
    Mcasp_ChanParams      *chanParams  = NULL;
    uint32_t                 count       = 0;
    uint32_t                 serNum      = 0;
    Mcasp_SerializerNum    serializerToConfigure = (Mcasp_SerializerNum)0;

   if((NULL != instHandle) && (NULL != params))
   {
    chanParams = (Mcasp_ChanParams *)params;

    for (count = 0; count < chanParams->noOfSerRequested; count++)
    {
        /* Get serializer number requested by user                            */
        serNum = (uint32_t)chanParams->indexOfSersRequested[count] ;

        if (Mcasp_SerializerStatus_FREE == instHandle->serStatus[serNum])
        {
            /* Configure requested serialzer as transmit mode                 */
            instHandle->serStatus[serNum] = Mcasp_SerializerStatus_XMT;

            serializerToConfigure = (Mcasp_SerializerNum)serNum;

            mcaspSetSerXmt(&(instHandle->hwInfo),serializerToConfigure);
        }
    }
  }  

}


/**
 *  \brief   This function restore global serializer state as available
 *           for further use.
 *
 *  \param   chanp  [IN]   Channel handle
 *
 *  \return  None
 *
 */
  void mcaspMultiSerGlobalRestore(void* chanp)
{
   Mcasp_ChannelHandle     chanHandle  = NULL;
   Mcasp_Object           *instHandle  = NULL;
   uint32_t                  serNum      = 0;

   if ( (NULL != chanp) && (NULL != ((Mcasp_ChannelHandle)chanp)->devHandle))
   {
      chanHandle = (Mcasp_ChannelHandle)chanp;
      instHandle = (Mcasp_Object *)chanHandle->devHandle;

    for (serNum=0; serNum < chanHandle->noOfSerAllocated; serNum++)
    {
        instHandle->serStatus[chanHandle->indexOfSersRequested[serNum]] =
            Mcasp_SerializerStatus_FREE;
            
        McASPSerializerInactivate(instHandle->hwInfo.regs, chanHandle->indexOfSersRequested[serNum]);
        McASPPinDirInputSet(instHandle->hwInfo.regs, ((uint32_t) 1U << chanHandle->indexOfSersRequested[serNum]));
    }
  }  
}


/**
 *  \brief   This function configures the Mcasp transmit sections
 *
 *  \param   instHandle  [IN]   pointer to the Mcasp instance object
 *  \param   params      [IN]   transmit channel parameters
 *
 *  \return  MCASP_COMPLETED If configuration is success
 *           Error code in case of failure.
 *
 */
  int32_t mcaspConfigureXmtChannel(Mcasp_Object *instHandle,
                                      void*           params)
{
    Mcasp_ChanParams  *chanParams = NULL;
    int32_t            status     = MCASP_COMPLETED;
    Bool               falsewhile = (Bool)TRUE;

   if((NULL != instHandle) && (NULL != params))
   {
    do
    {
        falsewhile  = (Bool)FALSE;

        chanParams = (Mcasp_ChanParams *)params;

        /* before touching McASP registers, place transmit section in reset   */
        status = Mcasp_localResetXmt(&(instHandle->hwInfo));

        /* Configure the transmit section of the device: Start transmit high  *
         * clock and clock                                                    */
        status = Mcasp_localConfigXmtSection(
                    instHandle,
                    chanParams->mcaspSetup);

        if (MCASP_COMPLETED == status)
        {
            /* Set DITEN bit if DIT mode else set to I2S mode.                    */
            if (Mcasp_OpMode_DIT == chanParams->channelMode)
            {
                /* check hardware supports dit mode or not                        */
                if (TRUE == instHandle->hwInfo.ditStatus)
                {
                    status = mcaspSetDitMode(
                                &(instHandle->hwInfo),
                                (Bool)chanParams->channelMode);

                    if (MCASP_COMPLETED != status)
                    {
                        break;
                    }
                }
            }
        }

    }while(falsewhile);
  }
  else
  {
	  status = MCASP_EBADARGS;
  }
    return(status);
}

/**
 *  \brief   This function configures the receive section of the mcasp device.
 *
 *  \param   instHandle  [IN]  pointer to the Mcasp instance object
 *  \param   params      [IN]  receive channel parameters
 *
 *  \return  MCASP_COMPLETED in case of success
 *           Error code in case of failure
 *
 */

  int32_t mcaspConfigureRcvChannel(Mcasp_Object *instHandle,
                                      void*           params)
{
    Mcasp_ChanParams    *chanParams  = NULL;
    int32_t                status      = MCASP_COMPLETED ;

    if((NULL != instHandle) && (NULL != params))
    {
    chanParams = (Mcasp_ChanParams *)params;

    /* before touching McASP registers, place receive section in reset    */
    status = Mcasp_localResetRcv(&(instHandle->hwInfo));

    if (MCASP_COMPLETED == status)
    {
    /* Configure the receive section of the device: start Receive high    *
    * clock and clock                                                    */
    status = Mcasp_localConfigRcvSection(
                instHandle,
                chanParams->mcaspSetup);

    }
   } 
   else
   {
	  status = MCASP_EBADARGS;
   }
    return (status);
}


/**
 *  \brief   This function writes to the Channel status RAM (DITCSRA/B0-5)
 *
 *  \param   hMcasp      [IN]     Handle to the McASP instance
 *  \param   chanStatRam [IN]     status to be written
 *
 *  \return
 *           MCASP_COMPLETED   - Successful completion of read
 *           MCASP_EBADARGS    - Invalid parameters or Invalid handle
 */

  int32_t mcaspWriteChanStatRam(Mcasp_HwHandle      hMcasp,
                                   Mcasp_ChStatusRam  *const chanStatRam)
{
    int32_t   status = MCASP_COMPLETED;

    if((NULL != hMcasp) && (TRUE == hMcasp->ditStatus) && (NULL != chanStatRam))
    {
        /* Configure the DIT left channel status registers                    */
        McASPDITLeftChanStatusSet(
            hMcasp->regs, (uint32_t) 0,
            chanStatRam->chStatusLeft[Mcasp_DITRegIndex_0]);

        McASPDITLeftChanStatusSet(
            hMcasp->regs, (uint32_t) 1,
            chanStatRam->chStatusLeft[Mcasp_DITRegIndex_1]);

        McASPDITLeftChanStatusSet(
            hMcasp->regs, (uint32_t) 2,
            chanStatRam->chStatusLeft[Mcasp_DITRegIndex_2]);

        McASPDITLeftChanStatusSet(
            hMcasp->regs, (uint32_t) 3,
            chanStatRam->chStatusLeft[Mcasp_DITRegIndex_3]);

        McASPDITLeftChanStatusSet(
            hMcasp->regs, (uint32_t) 4,
            chanStatRam->chStatusLeft[Mcasp_DITRegIndex_4]);

        McASPDITLeftChanStatusSet(
            hMcasp->regs, (uint32_t) 5,
            chanStatRam->chStatusLeft[Mcasp_DITRegIndex_5]);

        /* Configure the DIT right channel status registers                   */
        McASPDITRightChanStatusSet(hMcasp->regs, (uint32_t) 0,
                                   chanStatRam->chStatusRight[
                                       Mcasp_DITRegIndex_0]);

        McASPDITRightChanStatusSet(hMcasp->regs, (uint32_t) 1,
                                   chanStatRam->chStatusRight[
                                       Mcasp_DITRegIndex_1]);

        McASPDITRightChanStatusSet(hMcasp->regs, (uint32_t) 2,
                                   chanStatRam->chStatusRight[
                                       Mcasp_DITRegIndex_2]);

        McASPDITRightChanStatusSet(hMcasp->regs, (uint32_t) 3,
                                   chanStatRam->chStatusRight[
                                       Mcasp_DITRegIndex_3]);

        McASPDITRightChanStatusSet(hMcasp->regs, (uint32_t) 4,
                                   chanStatRam->chStatusRight[
                                       Mcasp_DITRegIndex_4]);

        McASPDITRightChanStatusSet(hMcasp->regs, (uint32_t) 5,
                                   chanStatRam->chStatusRight[
                                       Mcasp_DITRegIndex_5]);
    }
    else
    {
        status = MCASP_EBADARGS;
    }
    return (status);
}

/**
 *  \brief   This function writes to the User Data RAM (DITUDRA/B0-5)
 *
 *  \param   hMcasp      [IN] pointer to the Mcasp H/W information structure
 *  \param   userDataRam [IN] data to be written
 *
 *  \return
 *           MCASP_COMPLETED   - Successful completion of write
 *           MCASP_EBADARGS    - Invalid parameters or Invalid handle
 *
 */
  int32_t mcaspWriteUserDataRam(Mcasp_HwHandle      hMcasp,
                                   Mcasp_UserDataRam  *const userDataRam)
{
    int32_t   status = MCASP_COMPLETED;

    if((NULL != hMcasp) && (TRUE == hMcasp->ditStatus) && (NULL != userDataRam))
    {
        /* Configure the DIT left user data registers                         */
        McASPDITLeftUserDataRamSet(hMcasp->regs, (uint32_t) 0,
                                   userDataRam->userDataLeft[
                                       Mcasp_DITRegIndex_0]);

        McASPDITLeftUserDataRamSet(hMcasp->regs, (uint32_t) 1,
                                   userDataRam->userDataLeft[
                                       Mcasp_DITRegIndex_1]);

        McASPDITLeftUserDataRamSet(hMcasp->regs, (uint32_t) 2,
                                   userDataRam->userDataLeft[
                                       Mcasp_DITRegIndex_2]);

        McASPDITLeftUserDataRamSet(hMcasp->regs, (uint32_t) 3,
                                   userDataRam->userDataLeft[
                                       Mcasp_DITRegIndex_3]);

        McASPDITLeftUserDataRamSet(hMcasp->regs, (uint32_t) 4,
                                   userDataRam->userDataLeft[
                                       Mcasp_DITRegIndex_4]);

        McASPDITLeftUserDataRamSet(hMcasp->regs, (uint32_t) 5,
                                   userDataRam->userDataLeft[
                                       Mcasp_DITRegIndex_5]);

        /* Configure the DIT right user data registers                        */
        McASPDITRightUserDataRamSet(hMcasp->regs, (uint32_t) 0,
                                    userDataRam->userDataRight[
                                        Mcasp_DITRegIndex_0]);

        McASPDITRightUserDataRamSet(hMcasp->regs, (uint32_t) 1,
                                    userDataRam->userDataRight[
                                        Mcasp_DITRegIndex_1]);

        McASPDITRightUserDataRamSet(hMcasp->regs, (uint32_t) 2,
                                    userDataRam->userDataRight[
                                        Mcasp_DITRegIndex_2]);

        McASPDITRightUserDataRamSet(hMcasp->regs, (uint32_t) 3,
                                    userDataRam->userDataRight[
                                        Mcasp_DITRegIndex_3]);

        McASPDITRightUserDataRamSet(hMcasp->regs, (uint32_t) 4,
                                    userDataRam->userDataRight[
                                        Mcasp_DITRegIndex_4]);

        McASPDITRightUserDataRamSet(hMcasp->regs, (uint32_t) 5,
                                    userDataRam->userDataRight[
                                        Mcasp_DITRegIndex_5]);
    }
    else
    {
        status = MCASP_EBADARGS;
    }
    return (status);
}

/**
 *
 * \brief   This function configures the Hardware FIFO
 *
 * \param   hMcasp       [IN] pointer to the Mcasp Hardware information struct
 * \param   chanHandle   [IN] handle to the channel
 * \param   enableHwFifo [IN] hardware FIFO to be enabled or disabled
 *
 * \return  None
 *
 */
  void mcaspConfigureFifo(const Mcasp_HwObj         *hMcasp,
                          const Mcasp_ChannelObj    *chanHandle,
                          Bool                       enableHwFifo)

{
    /* validate the input parameters                                          */
    if((NULL != hMcasp) && (NULL != hMcasp->fifoRegs) && (NULL != chanHandle))
    {
    /* check if the HW FIFO usage is requested by the user for this channel   */
    if (TRUE == enableHwFifo)
    {
        if (MCASP_INPUT == chanHandle->mode)
        {
            /* configure the receive channel                                  */
            /* Step 1 : configure the "WNUMDMA" and "WNUMEVT" bits before     *
             * enabling the FIFO                                              */
            McASPReadFifoEnable(hMcasp->regs,
                                chanHandle->noOfSerAllocated,
                                chanHandle->hwFifoEventDMARatio);
        }
        else
        {
            /* configure the transmit channel                                 */
            /* Step 1 : configure the "WNUMDMA" and "WNUMEVT" bits before     *
             * enabling the FIFO                                              */
            McASPWriteFifoEnable(hMcasp->regs,
                                 chanHandle->noOfSerAllocated,
                                 chanHandle->hwFifoEventDMARatio);
        }
    }
    else
    {
        /* FIFO needs to be disabled                                          */
        if (MCASP_INPUT == chanHandle->mode)
        {
            /* disable the FIFO now by resetting the "WENA" bit               */
            McASPReadFifoDisable(hMcasp->regs);
        }
        else
        {
            /* disable the FIFO now by resetting the "WENA" bit               */
            McASPWriteFifoDisable(hMcasp->regs);
        }
    }
  }  
}


/**
 *
 * \brief This function validates the application specified buffer formats and
 *          updates the channel handle with the choosen buffer format.
 *
 * Side effect: This function also update the channel environment variable
 *              "noOfSlots" that would be used to compute the EDMA 3 indices.
 *
 * \param   chanHandle    [IN]    Pointer to channel handle
 * \param   params        [IN]    user supplied channel configurations.
 *
 * \return  DriverTypes_COMPLETED on sucess else an error code is returned
 *
 */

  int32_t  mcaspValidateBufferConfig(Mcasp_ChannelHandle  chanHandle,
                                        Mcasp_ChanParams    *const params)
{
    uint32_t    tempVar   = 0x0;
    int32_t   status    = MCASP_COMPLETED;

    if((NULL != chanHandle) && (params != NULL))
    {
    /* get the number of slots to be configured                               */
    tempVar = ((0x0000FF80u) & params->mcaspSetup->frSyncCtl);
    tempVar = tempVar >> 7;

    if (0x01 < params->noOfSerRequested)
    {
        /* multi serializer configuration                                     */
        if (0x01U < tempVar)
        {
            /* multi serialiser multi slot configuration                      */
            if ((Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1
                != params->dataFormat) &&
                (Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2
                != params->dataFormat))
            {
                status = MCASP_EBADARGS;
            }
        }
        else
        {
            /* Multi serialiser single slot configuration                     */
            if ((Mcasp_BufferFormat_MULTISER_1SLOT_SER_INTERLEAVED
                != params->dataFormat) &&
                (Mcasp_BufferFormat_MULTISER_1SLOT_SER_NON_INTERLEAVED
                != params->dataFormat))
            {
                status = MCASP_EBADARGS;
            }
        }
    }
    else
    {
        /* single serialiser configuration                                    */
        if (0x01U < tempVar)
        {
            /* single serializer multi slot configuration                     */
            if ((Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED
                != params->dataFormat) &&
                (Mcasp_BufferFormat_1SER_MULTISLOT_NON_INTERLEAVED
                != params->dataFormat))
            {
                status = MCASP_EBADARGS;
            }
        }
        else
        {
            /* single slot configuration                                      */
            if (Mcasp_BufferFormat_1SER_1SLOT != params->dataFormat)
            {
                status = MCASP_EBADARGS;
            }
        }
    }

    /* update the number of slots in to the channel structure                 */
    chanHandle->noOfSlots = (uint16_t)params->noOfChannels;

    if (MCASP_COMPLETED == status)
    {
        /* copy the data format to the channel structure                      */
        chanHandle->dataFormat = params->dataFormat;
    }
  }
  else
  {
	  status = MCASP_EBADARGS;
  }  
    return status;
}

/*
 *  \brief  This function toggles the index of the edma params
 *
 *  \param  index [IN]  pointer to current index
 *
 *  \return None
 *
 */
void Mcasp_localGetNextIndex(Mcasp_ChannelHandle chanHandle)
{
    /* Todo: will this be needed for UDMA?  Need to refactor */
#ifdef MCASP_EDMA_ENABLED
    chanHandle->nextLinkParamSetToBeUpdated =
        ((chanHandle->nextLinkParamSetToBeUpdated + 1u) & 0x01u);
#endif
}

/**
 *  \brief  This checks is the next request in queue is data request. If this is
 *          an abort request, it calls the appropriate function to deal
 *          with it.
 *
 *  \param  chanHandle [IN]  Handle to the Mcasp Channel
 *
 *  \return MCASP_COMPLETED,if request is Recieved/Transmitted completed
 *          Mcasp_STATUS_VALID/MCASP_EBADARGS, if request is not completed
 *
 */
int32_t Mcasp_localIsValidPacket(Mcasp_ChannelHandle chanHandle)
{
    int32_t  status     = MCASP_COMPLETED;
    Bool   falsewhile = TRUE;

    do
    {
        falsewhile = FALSE;

        if((NULL != chanHandle) && (NULL != chanHandle->devHandle))
        {
        /* Present request validation for int mode transfer                   */
        if (((FALSE == chanHandle->isDmaDriven)
            && (NULL != chanHandle->dataPacket))
            && (0u != chanHandle->currentDataSize))
        {
            /* in interrupt mode - some transaction is going on               */
            status = Mcasp_STATUS_VALID;
        }
        else
        {
            /* Look for new request to be processed                           */
            if (((int32_t)TRUE) == Osal_Queue_empty((&(chanHandle->queueReqList))))
            {
                /* we dont have any packet in queue stop xmt/rct sm before    *
                 * giving error                                               */
                chanHandle->dataPacket = NULL;

                if (FALSE == chanHandle->isDmaDriven)
                {
                    /* As interrupt mode there is not loopjob implementation  *
                     * we have to stop the state machine here                 */
                    chanHandle->dataQueuedOnReset = 0;
                    chanHandle->dataPacket = NULL;
                    chanHandle->currentDataSize = 0;
                    chanHandle->userDataBufferSize = 0;
                    chanHandle->xferinProgressIntmode = FALSE;

                    /* Stopping the state machine is taken care outside this  *
                     * function                                               */
                }/* DMA driven is FALSE if loop */


                /* for DMA mode only status is enought to program the loopjob *
                 * buffer                                                     */
                status = Mcasp_STATUS_INVALID;
            }
            else
            {
                status = Mcasp_STATUS_VALID;

                chanHandle->dataPacket = (MCASP_Packet*)Osal_Queue_get((&(chanHandle->queueReqList)));

                if (NULL != chanHandle->dataPacket)
                {
                    /* we have a valid packet to process next                 */

                    /* in int mode - current packet will be only one hence we *
                     * can use chanHandle->dataPacket for floating / current  *
                     * packet                                                 */

                    chanHandle->currentDataSize =
                        (uint16_t)(chanHandle->dataPacket->size);
                    chanHandle->userDataBufferSize =
                        (uint32_t)(chanHandle->dataPacket->size);
                    status = Mcasp_STATUS_VALID;

                    if (TRUE == chanHandle->isDmaDriven)
                    {
                        /* Additional to assigning the important parameters as*
                         * above for DMA mode , we will have max 2 packets    *
                         * floating and hence we use a active queue to manage */
                        Osal_Queue_put(
                                Osal_Queue_handle(&(chanHandle->queueFloatingList)),
                            (Osal_Queue_Elem*)chanHandle->dataPacket);
                    }
                }
            } /* Request List queue Empty is TRUE if loop */
        }
      }
      else
      {
		  status = MCASP_EBADARGS;
	  }  
    }while(falsewhile);

    return status;
}

/**
 *  \brief  This function loads the packets to the actual EDMA paramset.
 *
 *  \param  chanHandle [IN]  Handle to channel.
 *  \param  ioPacket   [IN]  pointer to the ioPacket
 *
 *  \return None
 *
 */

void Mcasp_localLoadPktToDma(Mcasp_ChannelObj *chanHandle,MCASP_Packet *ioPacket)
{
    Mcasp_Object           *instHandle  = NULL;
    Mcasp_PktAddrPayload   *payLoad     = NULL;
    int32_t                   status      = MCASP_COMPLETED;
    Bool                    falseWhile  = (Bool)TRUE;
    uint32_t                  hwiKey      = 0;
    uint32_t                temp_var    = 0U;


    if( (NULL != chanHandle) && (NULL!= chanHandle->devHandle) && (NULL != ioPacket) )
    {

    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    do
    {
        falseWhile = (Bool)FALSE;

        if (TRUE == instHandle->isDataBufferPayloadStructure)
        {
            payLoad = (Mcasp_PktAddrPayload *)ioPacket->addr;
        }

        /* For a DIT  request,  channel has to be programmed with its contents*
         * (DIT RAM registers also if this is an xmt channel in DIT mode).    */
        if (Mcasp_ChanMode_RCV != chanHandle->channelOpMode)
        {
            if ((Mcasp_ChanMode_XMT_DIT == chanHandle->channelOpMode)
                && (TRUE == instHandle->isDataBufferPayloadStructure)
                && (payLoad != NULL)
                && (TRUE == payLoad->writeDitParams))
            {
                /* DIT Mode: Write to the Channel Status RAM and User Data RAM*/
                temp_var = (uint32_t)mcaspWriteChanStatRam(
                              &(instHandle->hwInfo),
                              payLoad->chStat);

                temp_var |= (uint32_t)mcaspWriteUserDataRam(
                               &(instHandle->hwInfo),
                               payLoad->userData);
                status = (int32_t)temp_var;

                if (MCASP_COMPLETED != status)
                {
                    status = MCASP_ABORTED;
                }
            }
        }

        if (MCASP_COMPLETED == status)
        {   
            chanHandle->currentDataSize = (uint16_t)ioPacket->size;
            chanHandle->userDataBufferSize = (uint32_t)ioPacket->size;

            /* for DMA mode we will not use chanHandle->dataPacket to hold        *
             * current packet - we use floatingqueue                              */
            chanHandle->dataPacket = NULL;

            /*  Enter critical section to protect the submit count                */
            hwiKey = HwiP_disable();

#ifdef Mcasp_LOOPJOB_ENABLED
            if (2U == chanHandle->submitCount)
#else
            /* The second and the third packet will go the link paramsets
             *        */
            if (2U <= chanHandle->submitCount)
#endif

            {
                chanHandle->loopjobUpdatedinParamset = (Bool)FALSE;

                Mcasp_localGetNextIndex(chanHandle);
            }

            status = Mcasp_submitPktToDma(chanHandle,ioPacket);

            if (MCASP_COMPLETED != status)
            {
                status = MCASP_EBADIO;

                /*  Enter critical section to protect the submit count            */
                HwiP_restore(hwiKey);
            }
        }

        if (MCASP_COMPLETED != status)
        {
            break;
        }

        if ((1U == chanHandle->submitCount) && (MCASP_COMPLETED == status))
        {
            /* First packet is being submitted in case of loop job        *
             * mode this will ne loaded in to the link paramset else      *
             * in case of the non loop job this will go in to the main    *
             * channel                                                    */
#ifdef Mcasp_LOOPJOB_ENABLED
            /* if at all this is the very first packet, then one param    *
             * set has loop job loaded , self linked and active with      *
             * the main xfer channel param. other param set is ready      *
             * loaded (just now and has link paramater set as the one     *
             * having loopjob (this is to ensure that if at all we are    *
             * not getting any more packets loopjob be will taken         *
             * over). Now we have to link the floating / newly loaded     *
             * param set to xfer channel.                                 */
            status = EDMA3_DRV_linkChannel(
                chanHandle->edmaHandle,
                chanHandle->xferChan,
                chanHandle->pramTbl \
                [chanHandle->nextLinkParamSetToBeUpdated]);

            if (MCASP_COMPLETED != status)
            {
                status = MCASP_EBADIO;
                /*  exit critical section to protect the submit count     */
            HwiP_restore(hwiKey);
            }
#endif
            if (MCASP_COMPLETED == status)
            {

            HwiP_restore(hwiKey);

#ifndef Mcasp_LOOPJOB_ENABLED
            /* configure the FIFO for the specific channel                    */
            mcaspConfigureFifo(&instHandle->hwInfo,
                               chanHandle,
                               chanHandle->enableHwFifo);


            /* This is the first packet. we would have update the main params *
             * with the ioPacket. we will now just start the transfer so that *
             * the packet is transferred                                      */
            Mcasp_enableDMA(chanHandle);

            /*  update the State m/c stop status                              */
            instHandle->stopSmFsXmt = (Bool)FALSE;
            instHandle->stopSmFsRcv = (Bool)FALSE;

            if(chanHandle->userIntValue) {
              Mcasp_enableInterrupt(chanHandle->cpuEventNum,chanHandle->intNum);
            }  
        
             if (MCASP_INPUT == chanHandle->mode)
             {
                 /* Receive channel */
                 /* activate RX and TX state machine and frame sync*/
                status = Mcasp_localActivateSmFsForRcv(instHandle);
              }
              else
              {
                  /* Transmit channel */
                  /* activate RX and TX state machine and frame sync*/
                status = Mcasp_localActivateSmFsForXmt(instHandle);
              }
#endif
            }
        }
    } while (falseWhile);
  }  
}



#ifndef Mcasp_LOOPJOB_ENABLED
/*
 *  \brief  This function waits for the FIFO to be emptied so that the Framesync
 *          can be stopped.here after the FIFO is empty.
 *
 *  \param  arg0   [IN]  Handle to the TX channel
 *  \param  arg1   [IN]  unused
 *
 *  \return None
 *
 */
void Mcasp_swiTxFifo(void * arg0,void * arg1)
{
    Mcasp_ChannelObj  *chanHandle = NULL;
    Mcasp_Object      *instHandle = NULL;
    uint32_t             timeOut    = 0x00;
    uint32_t             dlbMode    = 0x00;
    uint32_t tempVal = 0x0;

    chanHandle = (Mcasp_ChannelObj *)arg0;
    instHandle = (Mcasp_Object *)arg1;

    if( (NULL != chanHandle) && (NULL != instHandle))
    {
    /* update the timeout value from the instance handle                      */
    timeOut = instHandle->retryCount;

    dlbMode = McASPDlbRegRead(instHandle->hwInfo.regs);


    /* we have come here means that the Mcasp has got an callback but it      *
     * did have any more packet to load Hence here we will wait for the       *
     * FIFO to become empty (if FIFO is enabled) else wait for the TX to      *
     * become empty.then we will disable the TX section                       */
    if (TRUE == chanHandle->enableHwFifo)
    {
        tempVal = McASPTxFifoStatusGet(instHandle->hwInfo.regs);

        while ((0 != (tempVal & 0xFF))  /* Checking for 0-7 bits of the reg */
               && (0 != timeOut))
        {
            /* reduce the timeout count and check if the FIFO is empty        */
            timeOut--;
            tempVal = McASPTxFifoStatusGet(instHandle->hwInfo.regs);
        }
    }

    /* reinitialize the retry count                                           */
    timeOut = instHandle->retryCount;
    tempVal = 0x0;
    tempVal = McASPTxStatusGet(instHandle->hwInfo.regs);
    
    while ((MCASP_TX_STAT_UNDERRUN !=
            (tempVal & MCASP_TX_STAT_UNDERRUN))
         && (0U != timeOut))
    {
        /* reduce the retry count and check if the TX has completed           *
         * transmitting all the bytes                                         */
        timeOut--;
        tempVal = McASPTxStatusGet(instHandle->hwInfo.regs);
    }

    /* Now we can disable the frame sync                                      */
    if (MCASP_LBCTL_DLBEN_ENABLE == dlbMode)
    {
        (void)Mcasp_localDeactivateSmFsForRcv(instHandle);
        (void)Mcasp_localDeactivateSmFsForXmt(instHandle);
    }
    else
    {
        /* Reset state m/c & frame sync of TX section                         */
        (void)Mcasp_localDeactivateSmFsForXmt(instHandle);
    }

    /* Disable the FIFO */
    mcaspConfigureFifo(&instHandle->hwInfo, chanHandle, FALSE);

    if (MCASP_TX_UNDERRUN ==
        (MCASP_TX_UNDERRUN & chanHandle->userIntValue))
    {
        /* clear the underrun error                                           */
        tempVal  = McASPTxStatusGet(instHandle->hwInfo.regs);
        tempVal |= MCASP_TX_STAT_UNDERRUN;
        McASPTxStatusSet(instHandle->hwInfo.regs, tempVal);

        /* enable the underrun error                                          */
        McASPTxIntEnable(instHandle->hwInfo.regs,
                         MCASP_TX_UNDERRUN);
    }

    /* clear the error bits in the EDMA(as this is the last packet)           */
    Mcasp_clearDmaErrors(chanHandle);

    /* complete the IOP now and call the callback to the stream               */
    chanHandle->tempPacket = (MCASP_Packet *) Osal_Queue_get((&(chanHandle->queueFloatingList)));

    /* Decrement the submit count for the IOpackets                           */
    chanHandle->submitCount--;

    chanHandle->isTempPacketValid = (Bool)TRUE;
    chanHandle->tempPacket->status = chanHandle->currentPacketErrorStatus;

    Mcasp_localCompleteCurrentIo(chanHandle);

#if defined (BIOS_PWRM_ENABLE) && !defined (Mcasp_LOOPJOB_ENABLED)
    /* check if the driver is waiting to go to sleep or process DVFS event    *
     * (only if the application has requested PWRM support)                   */
    if (TRUE == instHandle->pscPwrmEnable)
    {
        Mcasp_localHandlePwrmEvent(instHandle,chanHandle);
    }
#endif /* #ifdef BIOS_PWRM_ENABLE  */
  }
}


/**
 * \brief     This function restores the driver to the original state that is it
 *            resumes the normal operation of the driver by picking the IOPs
 *            from the pending queue and putting it to the active IOP.
 * 
 * \param     chanHandle [IN] Handle to the device instance object
 *
 *  \return  status  MCASP_COMPLETED if no errors, error code otherwise
 */
int32_t Mcasp_loadPendedIops(Mcasp_ChannelObj *chanHandle)
{
    MCASP_Packet           *ioPacket        = NULL;
    int32_t                 status          = MCASP_COMPLETED;
    uint32_t                count           = 0x00;
    uint32_t                hwiKey          = 0x00;
    uint32_t                tempSubmitCount = 0x00;

    if(NULL != chanHandle)
    {
    /* reset the submit count to indicate we are loading the first packet     */
    tempSubmitCount = (uint32_t)chanHandle->submitCount;
    chanHandle->submitCount = 0x00;

    for (count = 0; count < (chanHandle->maxActiveSubmit + 1U); count++)
    {
        /* start the critical section                                         */
        hwiKey = HwiP_disable();

        if (((int32_t)TRUE) == Osal_Queue_empty((&chanHandle->queueReqList)))
        {
            break;
        }
        else
        {
            chanHandle->submitCount++;

            /* get the packet out of the pending queue and load it to the     *
             * active Queue                                                   */
            ioPacket = (MCASP_Packet *) Osal_Queue_get((&(chanHandle->queueReqList)));

            /* put the packet in to the active queue                          */
            Osal_Queue_put(Osal_Queue_handle(&(chanHandle->queueFloatingList)),(Osal_Queue_Elem *)ioPacket);
    
            /* load the packet to the edma                                    */
            Mcasp_localLoadPktToDma(chanHandle,ioPacket);
        }
    }

    /* restore the submit count                                               */
    chanHandle->submitCount = (int32_t)tempSubmitCount;
    HwiP_restore(hwiKey);
   }
   else
   {
	   status = MCASP_EBADARGS;
   }
    return status;
}


#endif /* Mcasp_LOOPJOB_ENABLED */


/*============================================================================*/
/*                             PWRM FUNCTIONS                                 */
/*============================================================================*/

/**
 *  \brief    Mcasp_localLpscOn
 *
 *            This function is invoked to power on the Mcasp peripheral and
 *            configure it according to the operating mode. Note that this
 *            function uses different functions to power ON the module,
 *            depending on whether PWRM is enabled in this driver or NOT
 *
 *  \param    instHandle  [IN] Handle to the device instance
 *
 *  \return   MCASP_COMPLETED in case of success, an ERROR code in case of error.
 *
 */
int32_t Mcasp_localLpscOn(const Mcasp_Object *instHandle)
{
    int32_t  status = MCASP_COMPLETED;

    if(NULL != instHandle)
    {
    if (TRUE == instHandle->pscPwrmEnable)
    {
#ifdef BIOS_PWRM_ENABLE
        /* power on using bios PWRM API                                       */
        status = (int32_t)Power_setDependency(
                    (Power_Resource)instHandle->hwInfo.pwrmLpscId);
#else
        /* power on using the PSC API                                         */
#if 0
status = Psc_ModuleClkCtrl(
                    (Psc_DevId)instHandle->hwInfo.pscInstance,
                    (uint32_t)instHandle->hwInfo.pwrmLpscId,
                    TRUE);
#endif
#endif
    }
   }
   else
   {
	   status = MCASP_EBADARGS;
   } 
    return (status);
}

/**
 * \brief    Mcasp_localLpscOff
 *
 *           This function is invoked to power off the module.
 *
 * \param    instHandle  [IN] Handle to the device instance
 *
 * \return   MCASP_COMPLETED in case of success, an ERROR code in case of error.
 *
 */
int32_t Mcasp_localLpscOff(const Mcasp_Object *instHandle)
{
    int32_t  status = MCASP_COMPLETED;

    if(NULL != instHandle)
    {
    if (TRUE == instHandle->pscPwrmEnable)
    {
#ifdef BIOS_PWRM_ENABLE
        /* power off  using PWRM API                                          */
        status = (int32_t)Power_releaseDependency(
                            (Power_Resource)instHandle->hwInfo.pwrmLpscId);
#else
        /* power off using PSC API only if it is an instance other than "0"   */
#if 0
        status = Psc_ModuleClkCtrl(
                    (Psc_DevId)instHandle->hwInfo.pscInstance,
                    (uint32_t)instHandle->hwInfo.pwrmLpscId,
                    FALSE);
#endif
#endif
    }
   } 
   else
   {
	   status = MCASP_EBADARGS;
   } 
    return (status);
}


#if defined (BIOS_PWRM_ENABLE) && !defined (Mcasp_LOOPJOB_ENABLED)
/**
 * \brief   This function handles the power events related to the McASP.it
 *          reduces the dependency count and stops the further IO from being
 *          programmed.
 *
 * \param   instHandle [IN] Handle to the device instance.
 * \param   chanHandle [IN] Handle to the channel
 *
 * \return  None
 */
void Mcasp_localHandlePwrmEvent(Mcasp_Object     *instHandle,
                                Mcasp_ChannelObj *chanHandle)
{
    int32_t   retVal  = MCASP_COMPLETED;
    uint32_t  count   = 0x00;
    uint32_t  dlbMode = 0x00;
    uint32_t tempVal = 0x00;

    if( (NULL != instHandle) && (NULL != chanHandle) )
    {
    /* check if the driver is waiting to go to sleep                          */
    if ((TRUE == instHandle->pscPwrmEnable) &&
        (TRUE == instHandle->pwrmInfo.ioSuspend))
    {
        /* Set the driver state to PWRM suspend so that no more IO can be     *
         * programmed                                                         */
        instHandle->devState = Mcasp_DriverState_PWRM_SUSPEND;

        if (TRUE == Osal_Queue_empty((&chanHandle->queueFloatingList)))
        {
            /* stop the current channel IO processing                         */
            Mcasp_disableDMA(chanHandle);

            /* close the IOP now                                              */
            if (MCASP_OUTPUT == chanHandle->mode)
            {
                if (MCASP_TX_UNDERRUN ==
                    (MCASP_TX_UNDERRUN & chanHandle->userIntValue))
                {
                    tempVal  = McASPTxIntrStatusGet(instHandle->hwInfo.regs);
                    tempVal &= (~MCASP_TX_UNDERRUN);
                    McASPTxIntEnable(instHandle->hwInfo.regs,
                                     tempVal);
                }
            }
            else
            {
                if (MCASP_RX_OVERRUN ==
                    (MCASP_RX_OVERRUN & chanHandle->userIntValue))
                {
                    tempVal  = McASPRxIntrStatusGet(instHandle->hwInfo.regs);
                    tempVal &= (~MCASP_RX_OVERRUN);
                    McASPRxIntEnable(instHandle->hwInfo.regs,
                                     tempVal);
                }
            }

            dlbMode  = McASPDlbRegRead(instHandle->hwInfo.regs);
            dlbMode &= MCASP_LBCTL_DLBEN_MASK;

            if (MCASP_LBCTL_DLBEN_ENABLE == dlbMode)
            {
                (void)Mcasp_localDeactivateSmFsForRcv(instHandle);
                (void)Mcasp_localDeactivateSmFsForXmt(instHandle);
            }
            else
            {
                /* stop the clocks and the EDMA transfers                     */
                /* stop the xmt/rcv state machine.                            */
                if (Mcasp_ChanMode_RCV == chanHandle->channelOpMode)
                {
                    /* Reset state m/c & frame sync of receive section        */
                    (void)Mcasp_localDeactivateSmFsForRcv(instHandle);

                    /* reenable the RCV overrun error                         */
                    if (MCASP_RX_OVERRUN ==
                        (MCASP_RX_OVERRUN & chanHandle->userIntValue))
                    {
                        tempVal  = McASPRxIntrStatusGet(instHandle->hwInfo.regs);
                        tempVal &= (~MCASP_RX_OVERRUN);
                        McASPRxIntEnable(instHandle->hwInfo.regs,
                                         tempVal);
                    }

                    /* Disable the FIFO */
                    mcaspConfigureFifo(&instHandle->hwInfo,
                                       chanHandle,
                                       FALSE);
                }
            }

            /* clear the error bits that have been set                        */
            Mcasp_clearDmaErrors(chanHandle);
        }

        if ((TRUE == Osal_Queue_empty((&instHandle->XmtObj.queueFloatingList))) &&
            (TRUE == Osal_Queue_empty((&instHandle->RcvObj.queueFloatingList))))
        {
            /* if both the channels are inactive then reset the io suspend    */
            instHandle->pwrmInfo.ioSuspend = FALSE;

            if ((Power_GOINGTOSLEEP == instHandle->pwrmInfo.pwrmEvent) ||
                 (Power_GOINGTODEEPSLEEP == instHandle->pwrmInfo.pwrmEvent))
            {
                 /* reduce the dependency count                               */
                 retVal = (int32_t)Power_getDependencyCount(
                                   (Power_Resource)instHandle->hwInfo.pwrmLpscId,
                                   &count);
        
                 instHandle->pwrmInfo.dependencyCount = count;
        
                 if (Power_SOK == retVal)
                 {
                     while (count > 0)
                     {
                         retVal = (int32_t)Power_releaseDependency(
                             (Power_Resource)instHandle->hwInfo.pwrmLpscId);
            
                         if (Power_SOK != retVal)
                         {
                             break;
                         }
                         count--;
                     }
                 }
             }

            /* call the delayed completion function                           */
            (instHandle->pwrmInfo.delayedCompletionFxn  \
                [instHandle->pwrmInfo.pwrmEvent])();
        }
    }
  }
  else
  {
	  status = MCASP_EBADARGS;
  }          
}

/**
 * \brief     This function registers with the BIOS PWRM module for all the 
 *            possible power management events.
 *
 * \param     instHandle [IN] Handle to the driver instance object
 *
 * \return    None
 *
 */
  int32_t McaspRegisterNotification(Mcasp_Object *instHandle)
{
    uint32_t        eventCnt = 0x00;
    Power_Status  retVal   = Power_SOK;
    int32_t         status   = MCASP_COMPLETED;

    if(NULL != instHandle)
    {
    /* register for the events to be notified by the driver                   */
    for (eventCnt = 0; eventCnt < Mcasp_MAX_PWRM_EVENTS; eventCnt++)
    {
        /* register the notify function for the PWRM event                    */
        retVal = Power_registerNotify(
                    (Power_Event)eventCnt,
                    NULL, 
                    &McaspNotifyCallback,
                    (void *)instHandle,
                    &(instHandle->pwrmInfo.notifyHandle[eventCnt]), 
                    &(instHandle->pwrmInfo.delayedCompletionFxn[eventCnt]));

        if (Power_SOK != retVal)
        {
            status = MCASP_EBADARGS;
            break;
        }
    }
   }
   else
   {
	   status = MCASP_EBADARGS;
   } 
    return (status);
}

/**
 * \brief     This function is the notify function called by the BIOS whenever
 *            a power event occurs in the system.This function handles the 
 *            power events and calls the appropriate functions to process the
 *            same.
 *
 * \param     eventType [IN] power event type
 * \param     eventArg1 [IN] event-specific argument
 * \param     eventArg2 [IN] event-specific argument
 * \param     clientArg [IN] argument passed by the PWRM module(usually
 *                          (supplied during the registration of the notifyFxn)
 *
 * \return    None
 *
 */
  Power_NotifyResponse McaspNotifyCallback(Power_Event    eventType,
                                                Arg           eventArg1,
                                                Arg           eventArg2,
                                                Arg           clientArg)
{
    Mcasp_Object           *instHandle = NULL;
    Power_NotifyResponse    pwrmStatus = Power_NOTIFYDONE;
    Power_Status            status     = Power_SOK;

    if(NULL != clientArg)
    {

    eventArg1 = eventArg1;
    eventArg2 = eventArg2;

    instHandle = (Mcasp_Object *)clientArg;

    /* check the event notified by the PWRM module and process accordingly    */
    switch (eventType)
    {
        case Power_GOINGTOSLEEP:
        case Power_GOINGTOSTANDBY:
        case Power_GOINGTODEEPSLEEP:
            pwrmStatus = McaspSuspendCurrentIops(instHandle,eventType);
            break;
        case Power_PENDING_CPU_SETPOINTCHANGE:
        case Power_PENDING_PER_SETPOINTCHANGE:
            /* No DVFS changes required hence return done                     */
            pwrmStatus = Power_NOTIFYDONE;
            break;
        case Power_DONE_CPU_SETPOINTCHANGE:
        case Power_DONE_PER_SETPOINTCHANGE:
            /* No DVFS changes required hence return done                     */
            pwrmStatus = Power_NOTIFYDONE;
            break;
        case Power_AWAKEFROMSLEEP:
        case Power_AWAKEFROMDEEPSLEEP:
            /* restore the dependency count                                   */
            while (instHandle->pwrmInfo.dependencyCount > 0)
            {
                status = Power_setDependency(
                             (Power_Resource)instHandle->hwInfo.pwrmLpscId);

                if (Power_SOK != status)
                {
                    break;
                }
                instHandle->pwrmInfo.dependencyCount--;
            }
         
            if (Power_SOK == status)
            {
                Mcasp_loadPendedIops(&instHandle->XmtObj);
                Mcasp_loadPendedIops(&instHandle->RcvObj);
                instHandle->devState = Mcasp_DriverState_CREATED;                
            }
            else
            {
                pwrmStatus = Power_NOTIFYNOTDONE;
            }
            break;
        case Power_AWAKEFROMSTANDBY:
            Mcasp_loadPendedIops(&instHandle->XmtObj);
            Mcasp_loadPendedIops(&instHandle->RcvObj);

            instHandle->devState = Mcasp_DriverState_CREATED;
            break;
        default:
            break;
    }
  }
  else
  {
	  pwrmStatus = Power_NOTIFYNOTDONE;
  }  
    return (pwrmStatus);
}

/**
 * \brief    This function configures the driver so that the current IOP can be
 *           completed and then supends all the remaining IOPs.
 *
 * \param    instHandle [IN] Handle to the device instance object
 * \param    eventType  [IN] event which has caused this notification call to 
 *                           driver
 *
 * \return   Power_NOTIFYDONE    if no IOPs are pending
 *           Power_NOTIFYNOTDONE if IOPs are pending in the driver.
 */
  Power_NotifyResponse McaspSuspendCurrentIops(Mcasp_Object  *instHandle,
                                                    Power_Event     eventType)
{
    uint32_t                hwiKey = 0x00;
    Power_NotifyResponse  status = Power_NOTIFYDONE; 

    if(NULL != instHandle)
    {

    hwiKey = HwiP_disable();

    if ((TRUE == Osal_Queue_empty((&instHandle->XmtObj.queueFloatingList))) &&
        (TRUE == Osal_Queue_empty((&instHandle->RcvObj.queueFloatingList))))
    {
        /* No IOP is pending currently. we can return the status of the       *
         * notify call as sucess                                              */
        instHandle->devState = Mcasp_DriverState_PWRM_SUSPEND;
        status = Power_NOTIFYDONE;
    }
    else
    {
        /* There are some IOPs pending,hence we will complete processing      *
         * of this request in the ISR context(task in case of polled mode)    *
         * by calling the delayed completion function                         */
        status = Power_NOTIFYNOTDONE;
        instHandle->pwrmInfo.ioSuspend = (Bool)TRUE;
        instHandle->pwrmInfo.pwrmEvent = eventType;
    }
   }
   else
   {
	   pwrmStatus = Power_NOTIFYNOTDONE;
   }
    HwiP_restore(hwiKey);
    return (status);
}


/**
 * \brief     This function unregisters all the power management events 
 *            which were previously registered by the driver instance.
 *
 * \param     instHandle [IN] Handle to the driver instance object
 *
 * \return    MCASP_COMPLETED in case of success
 *            MCASP_EBADARGS  in case of error
 *
 */
  int32_t McaspUnregisterNotification(Mcasp_Object *instHandle)
{
   uint32_t        eventCnt = 0x00;
   Power_Status  retVal   = Power_SOK;
   int32_t         status   = MCASP_COMPLETED;

   if(NULL != instHandle)
   {
    for (eventCnt = 0; eventCnt < Mcasp_MAX_PWRM_EVENTS; eventCnt++)
    {
        /* register the notify function for the PWRM event                    */
        if (NULL != (instHandle->pwrmInfo.notifyHandle[eventCnt]))
        {
            retVal = Power_unregisterNotify(
                        (instHandle->pwrmInfo.notifyHandle[eventCnt]));

            if (Power_SOK != retVal)
            {
                status = MCASP_EBADARGS;
                break;
            }
            else
            {
                instHandle->pwrmInfo.notifyHandle[eventCnt] = 0x00;
            }
        }
    }
  }
  else
  {
    status = MCASP_EBADARGS;
  }  
    return (status);
}

/**
 * \brief     This function unregisters all the constraints for the device 
 *            instance.
 * 
 * \param     instHandle [IN]  Handle to the driver instance object
 *
 * \return    MCASP_COMPLETED in case of success
 *            MCASP_EBADMODE in case of failure
 * 
 */
int32_t McaspUnregisterConstraints(Mcasp_Object *instHandle)
{
    int32_t         status = MCASP_COMPLETED;
    Power_Status  retVal = Power_SOK;
    uint32_t        count  = 0x00;

    if(NULL != instHandle)
    {
    
    for (count = 0; count < Mcasp_MAX_PWRM_CONSTRAINTS; count++)
    {
        if (NULL != instHandle->pwrmInfo.constraintHandle[count])
        {
            retVal = Power_unregisterConstraint(
                         instHandle->pwrmInfo.constraintHandle[count]);

            if (Power_SOK != retVal)
            {
                status = MCASP_EBADMODE;
                break;
            }
            else
            {
                instHandle->pwrmInfo.constraintHandle[count] = 0x00;
            }
        }
    }
   } 
   else
   {
	   status = MCASP_EBADARGS;
   } 
    return (status);
}

#endif
static void Mcasp_enableInterrupt(int32_t cpuEventNum, int32_t intNum)
{
   
    if ( (cpuEventNum!=MCASP_INVALID_EVENTNUM)    &&
         (cpuEventNum!=MCASP_UNASSIGNED_EVENTNUM) &&
         (intNum!=MCASP_INVALID_INTNUM)   &&  
         (intNum!=MCASP_UNASSIGNED_INTNUM))  {
      Osal_EnableInterrupt(cpuEventNum,intNum);
    }
}

static void Mcasp_disableInterrupt(int32_t cpuEventNum,int32_t intNum)
{
    if ( (cpuEventNum!=MCASP_INVALID_EVENTNUM)    &&
         (cpuEventNum!=MCASP_UNASSIGNED_EVENTNUM) &&
         (intNum!=MCASP_INVALID_INTNUM)   &&  
         (intNum!=MCASP_UNASSIGNED_INTNUM))  {
      Osal_DisableInterrupt(cpuEventNum,intNum);
    }
}


/**
 * \brief  This API gets the SoC level of MCASP intial configuration
 *
 * \param  index     MMC instance index.
 * \param  cfg       Pointer to MMCSD SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t Mcasp_socGetInitCfg(uint32_t index, Mcasp_HwInfo *cfg)
{
    int32_t ret = 0;

    if (index < MCASP_CNT)
    {
        *cfg = Mcasp_deviceInstInfo[index];
    }
    else
    {
        ret = -1;
    }

    return ret;
}
/**
 * \brief  This API sets the SoC level of MCASP intial configuration
 *
 * \param  index     MMC instance index.
 * \param  cfg       Pointer to MMC SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t Mcasp_socSetInitCfg(uint32_t index, const Mcasp_HwInfo *cfg)
{
    int32_t ret = 0;

    if (index < MCASP_CNT)
    {
        Mcasp_deviceInstInfo[index] = *cfg;
    }
    else
    {
        ret = -1;
    }

    return ret;
}

/**
 * \brief  This function calculates the rounded word width based on channel 
 *         parameter wordWidth. 
 *
 * \param  chanHandle     McASP channel handle
 * \param  wordWidth      channel parameter wordWidth
 *
 * \param  tempRoundedWordWidth   the calculated rounded word width
 * \return  status                 MCASP_COMPLETED or MCASP_EBADARGS 
 *
 */
int32_t Mcasp_localCalcWordWidth(Mcasp_ChannelHandle chanHandle, 
                                 uint16_t wordWidth, 
                                 uint16_t *tempRoundedWordWidth)
{
    int32_t  status, count;
    uint32_t mask;
    uint16_t roundedWordWidth = 0;
    
    /* Initialize return status */
    status = MCASP_COMPLETED;
    
    /* Decide/calculate the rounded word width based on parameter wordWidth */
    if (TRUE == chanHandle->isDataPacked)
    {
        switch (wordWidth)
        {
            case Mcasp_WordLength_32:
            case Mcasp_WordLength_24:
            case Mcasp_WordLength_16:
            case Mcasp_WordLength_8:
                roundedWordWidth = wordWidth;
                break;

            default:
                status = MCASP_EBADARGS;
                break;
        }
    }
    else
    {
        /* We need to have infomation on what application intends to do.  *
         * for e.g. if application is sending 12bit data and formats it   *
         * in such a way the it in stream it occupies 2 bytes,this members*
         * value should be 16 (Mcasp_WordLength_16). By defaut we assume  *
         * that app has formated the data byte stream for 4 bytes for     *
         * each serialser for each sync event/int from mcasp. Please note *
         * that for burst mode we have 1 sync event/int from mcasp for    *
         * both L and R (in general all slots) where as we have each sync *
         * event /Int from mcasp for L and R (in general all slots)       *
         * seperately                                                     */
        roundedWordWidth = (uint16_t)Mcasp_WordLength_32;

        /* we have 3 options for chanHandle->roundedWordWidth variable    *
         * 32,16 & 8 so we start from 32 (bit 5) and check if bit5 , 4,   *
         * or 3 is set if  param->wordWidth is invalid - we assume the    *
         * default of 32bit width.The following logic translates the      *
         * intermediate bit widths to what this driver wants. It assumes  *
         * that always the data streams is aligned to 8 ,16, 32 bits      *
         ( rounded to ceil)                                               */

        if (Mcasp_WordLength_32 > wordWidth)
        {
            mask = 0x20u;

            for (count = 0; count < (3u); count++)
            {
                if (mask == (mask &  wordWidth))
                {
                    roundedWordWidth = (uint16_t)mask;

                    if (wordWidth > roundedWordWidth)
                    {
                        roundedWordWidth = (uint16_t)(roundedWordWidth << 1);
                    }
                    break;
                }
                mask= (uint32_t)(mask >> 1);
            }
        }
        else 
        {
            status = MCASP_EBADARGS;
        }
    }
    
    if (0U == ((0x0000FF80u) & chanHandle->frSyncCtl))
    {
        /*the driver has been configured for DSP (BURST mode)         */
        if (0 == chanHandle->noOfChannels)
        {
            status = MCASP_EBADARGS;
        }

        roundedWordWidth = (uint16_t)(chanHandle->noOfChannels * roundedWordWidth);

        /* rounded wordwidth can not go beyond 32 bits. In burst mode *
         * multiplication of no of channels and wordwidth can be max. *
         * 32 bits. Beyond that it is not supported                   */
        if (Mcasp_WordLength_32 < roundedWordWidth)
        {
            status = MCASP_EBADARGS;
        }
    }

    /* return calculated rounded word width */
    *tempRoundedWordWidth = roundedWordWidth;
    
    return status;
}

/* ========================================================================== */
/*                             END OF FILE                                    */
/* ========================================================================== */

