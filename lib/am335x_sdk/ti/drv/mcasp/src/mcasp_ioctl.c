/*
 * mcasp_ioctl.c
 *
 * This file contains local functions for McASP driver which contain implemen-
 * tation for control commands specific for the McASP peripheral.
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
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
 *  \file   mcasp_ioctl.c
 *
 *  \brief  This files contains the ioctl functions required for the Mcasp
 *          driver to execute the control commands.
 *
 *   (C) Copyright 2019, Texas Instruments, Inc
 *
 *
 *  \version   0.2     Added the support for the non loop job mode
 *             0.1     Newly created.
 */

/* ========================================================================== */
/*                             INCLUDE FILES                                  */
/* ========================================================================== */


#include <ti/csl/cslr_device.h>

#include <ti/csl/cslr_mcasp.h>
#include <mcasp_drv.h>
#include <mcasp_osal.h>
#include <include/McaspLocal.h>


#ifdef Mcasp_LOOPJOB_ENABLED
extern Mcasp_TempBuffer Mcasp_loopDstBuf[MCASP_CNT];
extern Mcasp_TempBuffer Mcasp_loopSrcBuf[MCASP_CNT];
#endif  /* Mcasp_LOOPJOB_ENABLED */
/* ========================================================================== */
/*                          LOCAL FUNCTION PROTOTYPES                         */
/* ========================================================================== */

static void mcaspConfigLoopBack(Mcasp_HwHandle hMcasp,Bool loopBack);

#ifdef Mcasp_LOOPJOB_ENABLED
static void mcaspActivateRcvClkSer(Mcasp_HwHandle hMcasp);

static void mcaspActivateXmtClkSer(Mcasp_HwHandle hMcasp);

static void mcaspActivateClkRcvXmt(Mcasp_HwHandle hMcasp);
#endif

static int32_t mcaspSetSamplingRate(Mcasp_ChannelHandle  chanHandle,
                                  void*                  ioctlArg);
static void mcaspDeviceInfoGet(Mcasp_ChannelHandle  chanHandle,
                               void*                  arg);

static int32_t mcaspGetHwStatus(Mcasp_HwHandle        hMcasp,
                              Mcasp_HwStatusQuery   myQuery,
                              void                 *const response);

static void mcaspReadXmtConfig(Mcasp_HwHandle       hMcasp,
                               Mcasp_HwSetupData   *const xmtData);

static void mcaspReadRcvConfig(Mcasp_HwHandle       hMcasp,
                               Mcasp_HwSetupData   *const rcvData);

static void mcaspGetSerMode(Mcasp_HwHandle        hMcasp,
                            Mcasp_SerMode        *serMode,
                            Mcasp_SerializerNum   serNum);

static void mcaspGetSerRcvReady(Mcasp_HwHandle       hMcasp,
                                Bool                *serRcvReady,
                                Mcasp_SerializerNum  serNum);

static void mcaspGetSerXmtReady(Mcasp_HwHandle        hMcasp,
                                Bool                 *serXmtReady,
                                Mcasp_SerializerNum   serNum);
static int32_t Mcasp_localConfigWordWidth(Mcasp_ChannelHandle chanHandle, 
                                   Mcasp_ChanParams *chanParams);

/* ========================================================================== */
/*                           FUNCTION DEFINTIONS                              */
/* ========================================================================== */


/**
 *  \brief  This function executes the control commands passed by the IDriver,
 *          the application passes the control command required to the IDriver
 *          uisng the stream control function. The IDriver function then calls
 *          this function which then actually executes the control command.
 *
 *  \param  chanHandle  [IN]  Handle to channel
 *  \param  cmd         [IN]  Control command number
 *  \param  arg         [IN]  Arguments for control command
 *  \param  param       [IN]  user defined data structure
 *
 *  \return Appropriate error code in case of failure else MCASP_COMPLETED
 *          is returned
 *
 */
int32_t Mcasp_localSubmitIoctl(Mcasp_ChannelHandle      chanHandle,
                             Uns                      cmd,
                             void*                      arg,
                             void*                      param)
{
    Mcasp_Object           *instHandle    = NULL;
    int16_t                   serNum        = 0;
    uint32_t                  tempVal       = 0;
    uint32_t                  queryRes      = 0;
    int32_t                 status        = MCASP_COMPLETED;
    Bool                    dlbMode       = FALSE;
    Bool                    falsewhile    = TRUE;
    Mcasp_HwSetupData      *chanSetup     = NULL;
    Mcasp_HwSetup          *mcaspHwSetup  = NULL;
    uint32_t                  timeout       = Mcasp_POLLED_RETRYCOUNT;
    Mcasp_ChanParams   *params  = NULL;
#ifdef Mcasp_LOOPJOB_ENABLED
    EDMA3_DRV_PaRAMRegs pramPtr = {0};
    EDMA3_DRV_SyncType  syncType;
    MCASP_Packet         *ioPacket = NULL;
    int16_t linkCnt = 0;
    bool   tempQueueStatus;
    void  *tempCastPacket;
    bool   breakLoop = (Bool) FALSE;
#endif
    /* Validate the input parameters                                          */
    if((NULL != chanHandle) && (NULL != chanHandle->devHandle))
    {
    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    /*--------------------MCASP IOCTL FOR HANDLING TIMEOUT--------------------*/

    if ((Mcasp_IOCTL_CHAN_TIMEDOUT == cmd) ||
         (Mcasp_IOCTL_CHAN_RESET == cmd) ||
         (MCASP_CHAN_RESET == cmd) ||
         (MCASP_CHAN_TIMEDOUT ==cmd))
    {
        /* To be called in case of channel timeoutand reset                   */
        status = Mcasp_localAbortReset(chanHandle);
    }
    /*---------------------------MCASP RESET CMD -----------------------------*/
    else if ((Mcasp_IOCTL_DEVICE_RESET == cmd) ||
              (MCASP_DEVICE_RESET == cmd))
    {
        /* Abort all the request, give application callback and configure     *
         * EDMA in the LOOPJOB for both input and output channels             */
        if(instHandle->RcvObj.devHandle!=NULL)
        {
           Mcasp_localAbortRequests(&(instHandle->RcvObj),NULL);
        }
        if(instHandle->XmtObj.devHandle!=NULL)
        {
           Mcasp_localAbortRequests(&(instHandle->XmtObj),NULL);
        }
    }
    /*-------------------------MCASP DRIVER MODE------------------------------*/
    else if (Mcasp_IOCTL_QUERY_LOOPJOB_MODE == cmd)
    {
        /* Query the working mode of the driver                               */
        if(NULL != arg) {
          *(Bool *)arg = instHandle->loopJobMode;
	    }
    }
    /*---------------------MCASP SET CHANNEL SETTINGS CMD --------------------*/
    else if (Mcasp_IOCTL_CNTRL_SET_FORMAT_CHAN == cmd)
    {
        if (NULL == arg)
        {
            status = MCASP_EBADARGS;
        }
        else
        {

            /* Reprogram xmt/rcv format unit registers. State m/c         *
             * associated with channel should have been reset.            *
             * a pointer to h/w setup data would have been passed through *
             * the argument field.                                        */
            chanSetup = (Mcasp_HwSetupData *)arg;

            /* Stop the xmt/rcv state machine.                            */
            status = Mcasp_localSmReset(chanHandle);

            if (Mcasp_ChanMode_RCV == chanHandle->channelOpMode)
            {
                /* Check if receive state machine and frame sync are reset*/
                status = mcaspGetHwStatus(
                            &(instHandle->hwInfo),
                            Mcasp_HwStatusQuery_SM_FS_RCV,
                            &queryRes);
            }
            else
            {
                /* Check if transmit state machine & frame sync are reset */
                status = mcaspGetHwStatus(
                            &(instHandle->hwInfo),
                            Mcasp_HwStatusQuery_SM_FS_XMT,
                            &queryRes);
            }

            if (MCASP_COMPLETED != status)
            {
               status = MCASP_EBADMODE;
            }
            else
            {
                if (Mcasp_SM_RESET != queryRes)
                {
                    /* The corresponding state m/c and frame sync have to be  *
                     * reset. And they are not. So return error.              */
                    status = MCASP_EBADARGS;
                }
            }
            
            if (MCASP_COMPLETED == status)
            {
                do
                {
                    falsewhile = FALSE;

                    if ((Mcasp_ChanMode_XMT_DIT == chanHandle->channelOpMode)
                        || (Mcasp_ChanMode_XMT_TDM == chanHandle->channelOpMode))
                    {
                       /* Configure transmit section                              */
                        status =  Mcasp_localConfigXmtSection(
                                    instHandle,
                                    (Mcasp_HwSetupData *)chanSetup);
                    }
                    else
                    {
                        /* Configure receive section                              */
                        status = Mcasp_localConfigRcvSection(
                                    instHandle,
                                    (Mcasp_HwSetupData *)chanSetup);
                    }

                    if (MCASP_COMPLETED != status)
                    {
                        /* Error configuring section.Mark channel state as INVALID*/
                        chanHandle->chanState = Mcasp_DriverState_CLOSED;
                        break;
                    }
                else
                {
                    /* We need to force the current EDMA transfer to complete.
                     * Otherwise, it is possible that when the state machine
                     * is restarted in the middle of an ongoing transfer, the
                     * first frame is out of sync with the current transfer
                     * parameters and will result in a channel swap.
                     *
                     * Todo: this must be updated if/when McASP FIFO
                     * configurations are more fully supported by the
                     * driver.
                     */
#ifdef Mcasp_LOOPJOB_ENABLED
                    status = EDMA3_DRV_getPaRAM(
                        (EDMA3_DRV_Handle) chanHandle->edmaHandle,
                        chanHandle->xferChan,
                        &pramPtr);

                    if (MCASP_COMPLETED == status)
                    {
                        /* Reset the BCNT */
                        switch (chanHandle->dataFormat)
                        {
                            /* Reset to number of serializers for interleaved
                             * cases.
                             */
                            case Mcasp_BufferFormat_1SER_1SLOT:
                            case Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED:
                            case Mcasp_BufferFormat_MULTISER_1SLOT_SER_NON_INTERLEAVED:
                            case Mcasp_BufferFormat_MULTISER_1SLOT_SER_INTERLEAVED:
                            case Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1:
                            case Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2:
                                pramPtr.bCnt = chanHandle->noOfSerAllocated;
                                break;

                            /* Reset to number of slots for de-interleaved
                             * cases.
                             */
                            case Mcasp_BufferFormat_1SER_MULTISLOT_NON_INTERLEAVED:
                                pramPtr.bCnt = chanHandle->noOfSlots;
                                break;

                            default:
                                status = MCASP_EBADARGS;
                        break;
                    }

                        /* Reduce CCNT to 1 to immediately begin next transfer.
                         */
                        if(1 != pramPtr.cCnt)
                        {
                            pramPtr.cCnt = 1;
                        }
                        status = EDMA3_DRV_setPaRAM(
                            (EDMA3_DRV_Handle) chanHandle->edmaHandle,
                            chanHandle->xferChan,
                            &pramPtr);

                        if (MCASP_COMPLETED == status)
                        {
                            /* Start the xmt/rcv state machine.
                             *                           */
                            status = Mcasp_localSmSet((Mcasp_ChannelHandle) chanHandle);
                        }
                    }
#endif
                 }
              }while(falsewhile);
            }
        }
    }
    /*-----------------MCASP GET CHANNEL SETTINGS CMD --------------------*/
    else if (Mcasp_IOCTL_CNTRL_GET_FORMAT_CHAN == cmd)
    {
        do
        {
            falsewhile = FALSE;

            if (NULL == arg)
            {
                status = MCASP_EBADARGS;
                break;
            }

            /* Read xmt/rcv format unit registers. A pointer to h/w setup *
             * data would have been passed through the argument field.    */
            chanSetup = (Mcasp_HwSetupData *)arg;

            if ((Mcasp_ChanMode_XMT_DIT == chanHandle->channelOpMode)
                || (Mcasp_ChanMode_XMT_TDM == chanHandle->channelOpMode))
            {
                /* Read transmit section infomration                      */
                mcaspReadXmtConfig(&(instHandle->hwInfo),chanSetup);
            }
            else
            {
                /* Read receive section information                       */
                mcaspReadRcvConfig(&(instHandle->hwInfo),chanSetup);
            }
        }while(falsewhile);

    }
    /*---------------------MCASP SET GBL REG CMD -------------------------*/
    else if (Mcasp_IOCTL_CNTRL_SET_GBL_REGS == cmd)
    {
        do
        {
            falsewhile = FALSE;

            if (NULL == arg)
            {
                status = MCASP_EBADARGS;
                break;
            }

            /* This will program the global registers. Both channels will *
             * be reset and global registers programmed. A pointer to h/w *
             * setup would have been passed through the argument field.   */
            mcaspHwSetup = (Mcasp_HwSetup *)arg;

            if ((Mcasp_ChanMode_XMT_DIT == chanHandle->channelOpMode)
                || (Mcasp_ChanMode_XMT_TDM == chanHandle->channelOpMode))
            {
                McASPTxReset(instHandle->hwInfo.regs);
            }
            else
            {
                McASPRxReset(instHandle->hwInfo.regs);
            }

            status = Mcasp_localSetupHwInfo(&instHandle->hwInfo, mcaspHwSetup);

        }while(falsewhile);

    }
    /*-----------------------MCASP SET DIT CMD ---------------------------*/
    else if (Mcasp_IOCTL_SET_DIT_MODE == cmd)
    {
        do
        {
            falsewhile = FALSE;

            if (NULL == arg)
            {
                status = MCASP_EBADARGS;
                break;
            }

            /* This will set the DIT mode                                 */
            tempVal = *(uint32_t *)arg;

            if ((Mcasp_ChanMode_XMT_DIT == instHandle->XmtObj.channelOpMode)
            || (Mcasp_ChanMode_XMT_TDM == instHandle->XmtObj.channelOpMode))
            {
                McASPDITModeCtlWrite(instHandle->hwInfo.regs, tempVal);
                chanHandle->channelOpMode= Mcasp_ChanMode_XMT_DIT;
            }

        }while(falsewhile);

    }
    /*-----------------------MCASP LOOPBACK CMD  -------------------------*/
    else if (Mcasp_IOCTL_SET_DLB_MODE == cmd)
    {
        if (NULL == arg)
        {
            status = MCASP_EBADARGS;
        }
        else if ((NULL == &instHandle->RcvObj) && (NULL == &instHandle->XmtObj))
        {
            status = MCASP_EBADMODE;
        }
        else if ((NULL != (instHandle->RcvObj).dataPacket) && (NULL != (instHandle->XmtObj).dataPacket))
        {
            status = MCASP_EBADMODE;
        }
        else if ((instHandle->RcvObj).noOfSerAllocated != (instHandle->XmtObj).noOfSerAllocated)
        {
            status = MCASP_EBADMODE;
        }
        else
        {
            dlbMode = *((bool *)arg);
            do
            {
                falsewhile = FALSE;

                while (((uint32_t)serNum) < (((uint32_t)instHandle->hwInfo.numOfSerializers) - (1u)))
                {
                    if (Mcasp_SerializerStatus_FREE !=
                        instHandle->serStatus[serNum])
                    {
                        if (Mcasp_SerializerStatus_FREE !=
                            instHandle->serStatus[serNum+1])
                        {
                           /* Increment serializers counter                   */
                           serNum+=2;
                        }
                        else
                        {
                            /* Serializers not in sequence                    */
                            status = MCASP_EBADMODE;
                        }
                    }
                    else
                    {
                        if (Mcasp_SerializerStatus_FREE ==
                            instHandle->serStatus[serNum+1])
                        {
                           /* Increment serializers counter                   */
                           serNum+=2;
                        }
                        else
                        {
                            /* Serializers not in sequence                    */
                            status = MCASP_EBADMODE;
                        }
                    }
                    if (MCASP_COMPLETED != status)
                    {
                        break;
                    }
                }

                mcaspConfigLoopBack(&(instHandle->hwInfo), dlbMode);

                if (MCASP_COMPLETED != status)
                {
                    /* Error in setup!                                        */
                    status = MCASP_EBADIO;
                    break;
                }

                status = Mcasp_localActivateSmFsForBoth(instHandle);

            }while (falsewhile);
        }
    }
    /*------------------------MCASP MUTE CMD  ----------------------------*/
#if defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_K2G)
    else if (Mcasp_IOCTL_CNTRL_AMUTE == cmd)
    {
        do
        {
            falsewhile = FALSE;

            if (NULL == arg)
            {
                status =   MCASP_EBADARGS;
                break;
            }

            tempVal = *(uint32_t *)arg;

            /* Enable or Disable AMUTE register                           */
 		   McASPAmuteRegWrite(instHandle->hwInfo.regs,tempVal);

        }while(falsewhile);

    }
#endif	
    /*----------------------MCASP IOCTL QUERY  CMD -----------------------*/
    else if (Mcasp_IOCTL_QUERY_MUTE == cmd)
    {
        status = mcaspGetHwStatus(
                         &(instHandle->hwInfo),
                         Mcasp_HwStatusQuery_AMUTE,
                         &queryRes);

        /*Sending back the value of the Amute Register                */
        *(uint32_t *)arg = queryRes;
    }
#ifdef Mcasp_LOOPJOB_ENABLED
    /*-------------------MCASP LOOP JOB MODIFY CMD -----------------------*/
    /* Enable / disable loopjob. If the buffer pointer is, NULL then      *
     * disable loopjob not NULL then enable the loop job and asign buffer *
     * pointer to prdbuf                                                  */
    else if (Mcasp_IOCTL_CTRL_MODIFY_LOOPJOB == cmd)
    {
            params     = (Mcasp_ChanParams *) arg;

            if (NULL == params)
            {
                status = MCASP_EBADARGS;
            }

            if (((Bool) TRUE == chanHandle->isDmaDriven) &&
                (MCASP_COMPLETED == status))
            {
                status = EDMA3_DRV_getPaRAM(
                    (EDMA3_DRV_Handle) chanHandle->edmaHandle,
                    chanHandle->pramTbl[ \
                        ((chanHandle->nextLinkParamSetToBeUpdated + 1) % 2)],
                    &pramPtr);

                if (MCASP_COMPLETED == status)
                {
                    /* Here we need to change only the buffer pointer and the *
                     * length of the array which will go into bcnt            */
                    if (MCASP_OUTPUT == (chanHandle->mode))
                    {
                        chanHandle->loopJobBuffer =
                            &Mcasp_loopSrcBuf[(instHandle->instNum)].
                            scratchBuffer;

                        chanHandle->loopJobLength =
                            (chanHandle->roundedWordWidth
                             * chanHandle->noOfSlots
                             * chanHandle->noOfSerAllocated);

                        if (NULL != params->userLoopJobBuffer)
                        {
                            /* user specified loop job is loaded
                             *                 */
                            chanHandle->userLoopJob = (Bool) TRUE;

                            chanHandle->loopJobBuffer =
                                params->userLoopJobBuffer;
                            chanHandle->userLoopJobLength =
                                params->userLoopJobLength;

                            status = Mcasp_localGetIndicesSyncType(
                                chanHandle,
                                &(pramPtr.srcBIdx),
                                &(pramPtr.srcCIdx),
                                &(pramPtr.aCnt),
                                &(pramPtr.bCnt),
                                &(pramPtr.cCnt),
                                &syncType,
                                (Bool) TRUE);
                            pramPtr.srcAddr =
                                (uint32_t) params->userLoopJobBuffer;
                        }
                        else
                        {
                            status = MCASP_EBADARGS;
                        }
                    }
                    else
                    {
                        chanHandle->loopJobBuffer =
                            &Mcasp_loopSrcBuf[(instHandle->instNum)].
                            scratchBuffer;

                        chanHandle->loopJobLength =
                            (chanHandle->roundedWordWidth
                             * chanHandle->noOfSlots
                             * chanHandle->noOfSerAllocated);

                        if (NULL != params->userLoopJobBuffer)
                        {
                            /* user specified loop job is loaded
                             *                 */
                            chanHandle->userLoopJob = (Bool) TRUE;

                            chanHandle->loopJobBuffer =
                                params->userLoopJobBuffer;
                            chanHandle->userLoopJobLength =
                                params->userLoopJobLength;

                            status = Mcasp_localGetIndicesSyncType(
                                chanHandle,
                                &(pramPtr.destBIdx),
                                &(pramPtr.destCIdx),
                                &(pramPtr.aCnt),
                                &(pramPtr.bCnt),
                                &(pramPtr.cCnt),
                                &syncType,
                                (Bool) TRUE);
                            pramPtr.destAddr =
                                (uint32_t) params->userLoopJobBuffer;
                        }
                        else
                        {
                            status = MCASP_EBADARGS;
                        }
                    }
                }
                if (MCASP_COMPLETED == status)
                {
                    status = EDMA3_DRV_setPaRAM(
                        (EDMA3_DRV_Handle) chanHandle->edmaHandle,
                        chanHandle->pramTbl[ \
                            ((chanHandle->nextLinkParamSetToBeUpdated +
                              1) % 2)],
                        &pramPtr);
                }
            }
            else
            {
                status = MCASP_ENOTIMPL;
            }
    }
    /*----------------------- MCASP MUTE ON CMD --------------------------*/
    /* MUTE-ON command implementation Typical implementation for Mute is  *
     * writing zero data in buffer instead of writing real data.          */
    else if (Mcasp_IOCTL_CTRL_MUTE_ON == cmd)
    {
        do
        {
            falsewhile = (Bool) FALSE;

            if (MCASP_OUTPUT == chanHandle->mode)
            {
                if ((Bool) TRUE == chanHandle->bMuteON)
                {
                    status = MCASP_EBADARGS;
                    break;
    }
                chanHandle->bMuteON = (Bool) TRUE;
            }
            else
            {
                status = MCASP_ENOTIMPL;
            }
        } while (falsewhile);
    }
    /*----------------------- MCASP MUTE OFF CMD -------------------------*/
    /* Take out from the the Muted state                                  */
    else if (Mcasp_IOCTL_CTRL_MUTE_OFF == cmd)
    {
        do
        {
            falsewhile = (Bool) FALSE;

            if (MCASP_OUTPUT == chanHandle->mode)
            {
                /* Check if mute is not ON                                */
                if ((Bool) FALSE == chanHandle->bMuteON)
                {
                    status = MCASP_EBADARGS;
                    break;
                }
                chanHandle->bMuteON = (Bool) FALSE;
            } /* if only dma driven transaction */
            else
            {
                status = MCASP_ENOTIMPL;
            }
        } while (falsewhile);
    }
#endif /* Mcasp_LOOPJOB_ENABLED */
    /*--------------------------- MCASP ABORT CMD-------------------------*/
    else if (Mcasp_IOCTL_ABORT == cmd)
    {
        status = Mcasp_localAbortRequests(chanHandle, NULL);
    }
    else if (Mcasp_IOCTL_SET_SAMPLE_RATE == cmd)
    {
        status = mcaspSetSamplingRate(chanHandle,arg);
    }
    else if (Mcasp_IOCTL_GET_DEVINFO == cmd)
    {
        mcaspDeviceInfoGet(chanHandle, arg);
    }
#ifdef Mcasp_LOOPJOB_ENABLED
    /*------------------------MCASP START CMD ----------------------------*/
    else if (Mcasp_IOCTL_START_PORT == cmd)
    {
        if (MCASP_INPUT == chanHandle->mode)
        {
            if ((Bool) TRUE == instHandle->stopSmFsRcv)
            {
                instHandle->stopSmFsRcv = (Bool) FALSE;
            }
            else
            {
                /* Start port is issued without issuing stop              */
                status = MCASP_EBADARGS;
            }
        }
        else
        {
            if ((Bool) TRUE == instHandle->stopSmFsXmt)
            {
                instHandle->stopSmFsXmt = (Bool) FALSE;
            }
            else
            {
                /* Start port is issued without issuing stop              */
                status = MCASP_EBADARGS;
            }
        }
        tempQueueStatus =
            Osal_Queue_empty(Osal_Queue_handle(&(chanHandle->queueFloatingList)));
        if (((Bool) TRUE == chanHandle->isDmaDriven)
            && ((Bool) TRUE == tempQueueStatus))
        {
            for (linkCnt = 0; linkCnt < (int16_t) Mcasp_MAXLINKCNT; linkCnt++)
            {
                if ((Bool) FALSE ==
                    Osal_Queue_empty(Osal_Queue_handle(&(chanHandle->queueReqList))))
                {
                    ioPacket = (MCASP_Packet *) Osal_Queue_get(
                        Osal_Queue_handle(&(chanHandle->queueReqList)));

                    if (NULL == ioPacket)
                    {
                        status = MCASP_EBADARGS;
                    }
                    if (MCASP_COMPLETED == status)
                    {
                        tempCastPacket = (void *) ioPacket;
                        /* floating queue not full . Process this request.    */
                        Osal_Queue_put(Osal_Queue_handle(&(chanHandle->queueFloatingList)),
                                  (Osal_Queue_Elem*) tempCastPacket);

                        chanHandle->currentDataSize =
                            (uint16_t) ioPacket->size;
                        chanHandle->userDataBufferSize =
                            (uint32_t) ioPacket->size;

                        /* For DMA mode we will not use chanHandle->dataPacket*
                         * to hold current packet - we use floatingqueue      */
                        chanHandle->dataPacket = NULL;

                        if (((int16_t) Mcasp_MAXLINKCNT - (int16_t) 1U) == linkCnt)
                        {
                            /* Though we have to post to param set directly   *
                             * from here,there will be differene between first*
                             * such packet and second packet. As we have      *
                             * control here we are second packet and first    *
                             * packet has not yet returned (or corresponding  *
                             * edma callback has not been called.For second   *
                             * packet, we will be updating the second param   *
                             * set, which is currently hosting loopjob        *
                             * parameter. Hence increment the index to point  *
                             * second paramset and since we are moving out    *
                             * loopjob from both param sets,the loopjobUpdated*
                             * inParamset is reset                            */
                            chanHandle->loopjobUpdatedinParamset = (Bool) FALSE;

                            Mcasp_localGetNextIndex(chanHandle);
                        }
                        status = Mcasp_submitPktToDma(
                            chanHandle,
                            ioPacket);
                        if (MCASP_COMPLETED != status)
                        {
                            status = MCASP_EBADIO;
                        }
                    }

                    if ((0 == linkCnt) && (MCASP_COMPLETED == status))
                    {
                        /* if at all this is the very first packet, then  *
                         * one param set has loop job loaded,self linked  *
                         * and active with the main xfer channel param.   *
                         * other param set is ready loaded (just now and  *
                         * has link paramater set as the one having loop  *
                         * job (this is to ensure that if at all we are   *
                         * not getting any more packets loopjob be will   *
                         * take over). Now we have to link the floating   *
                         * newly loaded param set to xfer channel.        */
                        status = EDMA3_DRV_linkChannel(
                            chanHandle->edmaHandle,
                            chanHandle->xferChan,
                            chanHandle->pramTbl[ \
                                chanHandle->nextLinkParamSetToBeUpdated]);

                        if (MCASP_COMPLETED != status)
                        {
                            status = MCASP_EBADIO;
                        }
                    }
                }
                if (MCASP_COMPLETED != status)
                {
                    break;
                }
            }

            EDMA3_DRV_enableTransfer(
                chanHandle->edmaHandle,
                chanHandle->xferChan,
                EDMA3_DRV_TRIG_MODE_EVENT);

            dlbMode =
                (Bool) ((uint32_t) MCASP_LBCTL_DLBEN_ENABLE ==
                        (McASPDlbRegRead((uint32_t)instHandle->hwInfo.regs) &
                         (uint32_t) MCASP_LBCTL_DLBEN_MASK));

            if (dlbMode)
            {
                /* start both RCV and XMT state m/cs                      */
                /* Activate the transmit and receive clocks               */
                mcaspActivateClkRcvXmt(&(instHandle->hwInfo));

                status = Mcasp_localActivateSmFsForBoth(instHandle);
            }
            else
            {
                if (MCASP_INPUT == chanHandle->mode)
                {
                    /* start Receive state m/c */
                    /* before touching McASP registers, place receive     *
                     * section in reset                                   */
                    mcaspActivateRcvClkSer(&(instHandle->hwInfo));

                    status = Mcasp_localActivateSmFsForRcv(instHandle);
                }
                else
                {
                    /* start Transmit state m/c*/
                    /* before touching McASP registers, place transmit    *
                     * section in reset                                   */
                    mcaspActivateXmtClkSer(&(instHandle->hwInfo));

                    status = Mcasp_localActivateSmFsForXmt(instHandle);
                }
            }
        } /* DMA driven is TRUE if loop */
    }
    /*------------------------MCASP STOP CMD  ----------------------------*/
    else if (Mcasp_IOCTL_STOP_PORT == cmd)
    {
        do
        {
            falsewhile = (Bool) FALSE;
            if (MCASP_INPUT == chanHandle->mode)
            {
                if ((Bool) FALSE == instHandle->stopSmFsRcv)
                {
                    instHandle->stopSmFsRcv = (Bool) TRUE;
                }
                else
                {
                    /* Already stop port command is issued. This is a     *
                     * redundant command.                                 */
                    status = MCASP_EBADARGS;
                }
            }
            else
            {
                if ((Bool) FALSE == instHandle->stopSmFsXmt)
                {
                    instHandle->stopSmFsXmt = (Bool) TRUE;
                }
                else
                {
                    /* Already stop port command is issued. This is a    *
                     * redundant command.                                */
                    status = MCASP_EBADARGS;
                }
            }
        } while (falsewhile);
    }
    /*------------------------MCASP PAUSE CMD ----------------------------*/
    else if (Mcasp_IOCTL_PAUSE == cmd)
    {
        if ((Bool) FALSE == chanHandle->paused)
        {
            chanHandle->paused = (Bool) TRUE;
        }
        else
        {
            status = MCASP_EBADARGS;
        }
    }
    /*------------------------MCASP RESUME CMD ---------------------------*/
    else if (Mcasp_IOCTL_RESUME == cmd)
    {
        do
        {
            falsewhile = (Bool) FALSE;

            if ((Bool) FALSE == chanHandle->paused)
            {
                /* Pause is not issued so can not perform resume          */
                status = MCASP_EBADARGS;
                break;
            }
            tempQueueStatus =
                Osal_Queue_empty(Osal_Queue_handle(&(chanHandle->queueFloatingList)));
            if (((Bool) TRUE == chanHandle->isDmaDriven)
                && ((Bool) TRUE == tempQueueStatus))
            {
                for (linkCnt = 0; linkCnt < (int16_t) Mcasp_MAXLINKCNT; linkCnt++)
                {
                    if ((Bool) FALSE ==
                        Osal_Queue_empty(Osal_Queue_handle(&(chanHandle->queueReqList))))
                    {
                        ioPacket = (MCASP_Packet *) Osal_Queue_get(
                            Osal_Queue_handle(&(chanHandle->queueReqList)));

                        if (NULL != ioPacket)
                        {
                            tempCastPacket = (void *) ioPacket;
                            /* floating queue not full.Process this request   */
                            Osal_Queue_put(
                                Osal_Queue_handle(&(chanHandle->queueFloatingList)),
                                (Osal_Queue_Elem*) tempCastPacket);

                            chanHandle->currentDataSize =
                                (uint16_t) ioPacket->size;
                            chanHandle->userDataBufferSize = ioPacket->size;

                            /* For DMA mode we will not use
                             * chanHandle->dataPacket
                             * to hold current packet - we use floatingqueue  */
                            chanHandle->dataPacket = NULL;

                            if (((int16_t) Mcasp_MAXLINKCNT - (int16_t) 1) ==
                                linkCnt)
                            {
                                /* Though we have to post to param set direct *
                                 * from here,there will be differene between  *
                                 * first such packet and second packet. As we *
                                 * have control here we are second packet and *
                                 * first packet has not yet returned (or      *
                                 * corresponding edma callback has not been   *
                                 * called.For second packet, we will be       *
                                 * updating the second param set, which is    *
                                 * currently hosting loopjob parameter. Hence *
                                 * increment the index to point second param  *
                                 * set and since we are moving out loopjob    *
                                 * from both param sets, the loopjobUpdated in*
                                 * Paramset is reset                          */
                                chanHandle->loopjobUpdatedinParamset =
                                    (Bool) FALSE;

                                Mcasp_localGetNextIndex(chanHandle);
                            }

                            if (MCASP_COMPLETED !=
                                Mcasp_submitPktToDma(
                                    chanHandle,
                                    ioPacket))
                            {
                                status = MCASP_EBADIO;
                            }

                            if ((0 == linkCnt) && (MCASP_COMPLETED == status))
                            {
                                /* if at all this is the very first packet,   *
                                 * then one param set has loop job loaded,    *
                                 * self linked and active with the main xfer  *
                                 * channel param. other param set is ready    *
                                 * loaded (just now and has link paramater set*
                                 * as the one having loopjob (this is to      *
                                 * ensure that if at all we are not getting   *
                                 * any more packets loopjob be will taken over*
                                 * ). Now we have to link the floating/newly  *
                                 * loaded param set to xfer channel.          */
                                status = EDMA3_DRV_linkChannel(
                                    chanHandle->edmaHandle,
                                    chanHandle->xferChan,
                                    chanHandle->pramTbl[ \
                                        chanHandle->nextLinkParamSetToBeUpdated
                                    ]);

                                if (MCASP_COMPLETED != status)
                                {
                                    status = MCASP_EBADIO;
                                }
                            }
                        }
                        else
                        {
                            breakLoop = (Bool) TRUE;
                        }
                        if (((Bool) TRUE == breakLoop) ||
                            (MCASP_COMPLETED != status))
                        {
                            break;
                        }
                    }
                }
            }

            chanHandle->paused = (Bool) FALSE;
        } while (falsewhile);
    }
    /*****************command to modify the Timeout count value****************/
    else if (Mcasp_IOCTL_SET_TIMEOUT == cmd)
    {
        if(NULL != arg) {
         /* modify the retry count value to be used                            */
         instHandle->retryCount = *(uint32_t *) arg;
        } 
    }
#endif
    else if (Mcasp_IOCTL_FLUSH_RCV_FIFO == cmd)
    {
        if ((MCASP_INPUT == chanHandle->mode) &&
            (TRUE == chanHandle->enableHwFifo))
        {
            uint32_t tempValue = 0x00;
            tempValue = McASPRxFifoStatusGet(instHandle->hwInfo.regs);
            while (((uint32_t) 0U != (tempValue &
                                    (uint32_t) 0x000000FFU)) &&
                   ((uint32_t) 0U != timeout))
            {
                timeout--;
                /* empty the FIFO now                                         */
                tempVal = *((uint32_t *)instHandle->hwInfo.dataAddr);
                tempValue = McASPRxFifoStatusGet(instHandle->hwInfo.regs);
            }
        }
        else
        {
            status = MCASP_EBADMODE;
        }
    } else if (Mcasp_IOCTL_CHAN_QUERY_ERROR_STATS == cmd) 
	{
       if(NULL != arg)
       {
         if (MCASP_INPUT == chanHandle->mode)
         {   status = Mcasp_localCollectRcvErrorStats(chanHandle,(Mcasp_errCbStatus *)arg);
         }
	     else
         {   status = Mcasp_localCollectXmtErrorStats(chanHandle,(Mcasp_errCbStatus *)arg);
	     }
	   }   
    }
    else if (Mcasp_IOCTL_CHAN_PARAMS_WORD_WIDTH == cmd)
    {
        if(NULL != arg)
        { 
		  params = (Mcasp_ChanParams *) arg;
          Mcasp_localConfigWordWidth(chanHandle, params);
        }  
    }
    /*---------------MCASP GET TX CLOCK DIVIDE RATIO CMD -----------------*/
    else if (Mcasp_IOCTL_CNTRL_GET_FORMAT_CHAN_CLKXDIV == cmd)
    {
        // only XMT & TDM mode are allowed for this command
        if ((NULL == arg) ||
            (Mcasp_ChanMode_XMT_TDM != chanHandle->channelOpMode))
        {
            status = MCASP_EBADARGS;
        }
        else 
        {
            tempVal = McASPTxClkDivGet(instHandle->hwInfo.regs);
            *(uint32_t *)arg = tempVal;
        }
    }
    /*---------------MCASP SET TX CLOCK DIVIDE RATIO CMD------------------*/
    else if (Mcasp_IOCTL_CNTRL_SET_FORMAT_CHAN_CLKXDIV == cmd)
    {
        // only XMT & TDM mode are allowed for this command
        if ((NULL == arg) ||
            (Mcasp_ChanMode_XMT_TDM != chanHandle->channelOpMode))
        {
            status = MCASP_EBADARGS;
        }
        else
        {
            tempVal = *(uint32_t *)arg;
            McASPTxClkDivSet(instHandle->hwInfo.regs, tempVal);
        }
    }
    else
    {
        /* command not executed hence not set status as not implemented   */
        status = MCASP_ENOTIMPL;
    }
  } 
  else
  {
     status = MCASP_EBADARGS;
  }   
  return (status);
}

/**
 * \brief   This function reconfigures the word width of the channel parameters.
 *
 * \param   chanHandle   [IN]  Handle to the McASP channel
 * \param   chanParams   [IN]  Pointer to McASP channel parameters
 *
 * \return
 *          MCASP_COMPLETED   - Successful completion
 *          MCASP_EBADARGS    - Invalid parameters or Invalid handle
 */
int32_t Mcasp_localConfigWordWidth(Mcasp_ChannelHandle chanHandle, 
                                   Mcasp_ChanParams *chanParams)
{
    int32_t  status;
    uint32_t fmt;
    Mcasp_Object *instHandle;
    uint16_t tempRoundedWordWidth = 0;
    
    status = MCASP_COMPLETED;
    
    /* Decide/calculate the rounded word width based on chanParams->wordWidth */
    status = Mcasp_localCalcWordWidth(chanHandle, chanParams->wordWidth, 
                                      &tempRoundedWordWidth);

    if(status != MCASP_COMPLETED) 
    {
        return (status);
    }
    
    /* Converting word width from bits to bytes                       */
    chanHandle->roundedWordWidth = (uint16_t)(tempRoundedWordWidth >> 3);
        
    /* Check if the throttle has exceeded the max */
    if( chanHandle->enableHwFifo &&
       ((chanHandle->hwFifoEventDMARatio*chanHandle->roundedWordWidth
         *chanHandle->noOfSerAllocated) > Mcasp_MAX_AFIFO_SIZE) )
    {
        status = MCASP_EBADARGS;
    }

    if(status != MCASP_COMPLETED) 
    {
        return (status);
    }
    
#ifdef Mcasp_LOOPJOB_ENABLED
    /* Configure loop job for the user specified buffer if given  */
    if (FALSE == chanHandle->userLoopJob)
    {
        /* Length of uint32_t per serialiser-this is what we have allocated */
        if (Mcasp_OpMode_DIT == chanHandle->channelMode)
        {
            /* we need 2 * 24 bit data per subframe. Hence we will
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
    }
    else
    {
        if (chanHandle->roundedWordWidth > chanHandle->userLoopJobLength)
        {
            /* not enough loopjob buffer has been provided  we    *
             * should have aleast loopbuffer for 1 sync event     */
            status = MCASP_EBADARGS;
        }
    }
#endif /* Mcasp_LOOPJOB_ENABLED */

    if(status != MCASP_COMPLETED) 
    {
        return (status);
    }
   
    /* Set the RROT field based on the word bits order */
    if(chanHandle->wordBitsSelect == Mcasp_WordBitsSelect_MSB)
    {
        /* Read the stored Bit Stream Format (FMT) Register */
        fmt = chanHandle->fmt;
        
        /* Shift right 'rot' number of nibbles to make the MSB reach the lower 
           bits in the serializer */
        uint32_t rot = 8-(chanHandle->roundedWordWidth*2);

        /* Change the RROT field of FMT Register                              */
        instHandle = (Mcasp_Object *)chanHandle->devHandle;
        if (chanHandle->mode == MCASP_INPUT)
        {
            fmt = (fmt & (~MCASP_RXFMT_RROT_MASK)) | (rot << MCASP_RXFMT_RROT_SHIFT);
            McASPRxFmtSet(instHandle->hwInfo.regs, fmt);
        }
        else 
        {
            fmt = (fmt & (~MCASP_TXFMT_XROT_MASK)) | (rot << MCASP_TXFMT_XROT_SHIFT);
            McASPTxFmtSet(instHandle->hwInfo.regs, fmt);            
        } 
    }
    
    return (status);
} /* Mcasp_localConfigWordWidth */


/**
 * \brief   This function sets the digital loopback mode
 *
 * \param   hMcasp   [IN]  pointer to the Mcasp Hardware information structure
 * \param   loopBack [IN]     Value to be loaded into the bit filed
 *
 * \return
 *          MCASP_COMPLETED   - Successful completion
 *          MCASP_EBADARGS    - Invalid parameters or Invalid handle
 *
 */

static void mcaspConfigLoopBack(Mcasp_HwHandle hMcasp,Bool loopBack)
{
    Bool       loopBackEnable = 0;
    Bool       orderBit       = 0;
    Int16      serNum         = 0;
    uint32_t     serMode        = 0;
    uint32_t dlbMode        = 0;
    uint32_t tempVal        = 0;
    if((NULL != hMcasp) && (0 != (hMcasp->regs)))
    {
    /* Reset the RSRCLR and XSRCLR registers in GBLCTL                    */
    tempVal  = McASPGlobalCtlGet(hMcasp->regs);
    tempVal &= ~((uint32_t) (MCASP_GBLCTLR_RSRCLR_MASK | MCASP_GBLCTLR_XSRCLR_MASK |
                           MCASP_GBLCTLR_RSMRST_MASK | MCASP_GBLCTLR_XSMRST_MASK |
                           MCASP_GBLCTLR_RFRST_MASK | MCASP_GBLCTLR_XFRST_MASK));

    McASPGlobalCtlSet(hMcasp->regs, tempVal);

    dlbMode  = McASPDlbRegRead(hMcasp->regs);
    dlbMode &= MCASP_LBCTL_DLBEN_MASK;
    dlbMode |= ((uint32_t) loopBack << MCASP_LBCTL_DLBEN_SHIFT);
    McASPDlbRegWrite(hMcasp->regs, dlbMode);


    /* configure loop back mode                                           */
    loopBackEnable =
        (Bool) ((dlbMode & MCASP_LBCTL_DLBEN_MASK) == MCASP_LBCTL_DLBEN_MASK);
    if ((Bool) TRUE == loopBackEnable)
    {
        dlbMode &= MCASP_LBCTL_MODE_MASK;
        dlbMode |= (uint32_t) MCASP_LBCTL_MODE_XMTCLK << MCASP_LBCTL_MODE_SHIFT;
        McASPDlbRegWrite(hMcasp->regs, dlbMode);
    }

    orderBit = (Bool) (((dlbMode & (uint32_t) MCASP_LBCTL_ORD_MASK)
                        >> MCASP_LBCTL_ORD_SHIFT) == MCASP_LBCTL_ORD_EVEN);

    if (orderBit == TRUE)
    {
        while (serNum < hMcasp->numOfSerializers)
        {
            serMode = McASPSerializerGet(hMcasp->regs, (uint32_t) serNum);
            serMode = (serMode & (uint32_t) MCASP_XRSRCTL0_SRMOD_MASK) >>
                      MCASP_XRSRCTL0_SRMOD_SHIFT;

            if (MCASP_XRSRCTL0_SRMOD_INACTIVE != serMode)
            {
                McASPSerializerRxSet(hMcasp->regs, (uint32_t) serNum);

                McASPPinDirInputSet(hMcasp->regs, ((uint32_t) 1U << serNum));
            }
            serNum++;
        }
    }
    else
    {
        while (serNum < hMcasp->numOfSerializers)
        {
            serMode = McASPSerializerGet(hMcasp->regs,
                                         (uint32_t) serNum);
            serMode = (serMode & MCASP_XRSRCTL0_SRMOD_MASK) >>
                      MCASP_XRSRCTL0_SRMOD_SHIFT;

            if (MCASP_XRSRCTL0_SRMOD_INACTIVE != serMode)
            {
                McASPSerializerTxSet(hMcasp->regs, (uint32_t) serNum);

                McASPPinDirOutputSet(hMcasp->regs, ((uint32_t) 1U << serNum));
            }
            serNum++;
        }
    }
  }  
}

#ifdef Mcasp_LOOPJOB_ENABLED
/**
 * \brief   This function activates the receive and transmit clock.
 *
 * \param   hMcasp  [IN]  Handle to the Mcasp Hw info object
 *
 * \return  None
 *
 */
static void mcaspActivateClkRcvXmt(Mcasp_HwHandle hMcasp)
{
    uint32_t bitValue = 0U;
    uint32_t tempVal  = 0;

    if((NULL != hMcasp) && (0 != (hMcasp->regs)))
    {
    /* Sequence of start: starting hclk first                             */
    /* start AHCLKR */
    tempVal = McASPGlobalCtlGet(hMcasp->regs);

    tempVal &= ~MCASP_GBLCTL_RHCLKRST_MASK;
    tempVal |= (MCASP_GBLCTL_RHCLKRST_ACTIVE <<
                MCASP_GBLCTL_RHCLKRST_SHIFT);
    McASPGlobalCtlSet(hMcasp->regs, tempVal);

    bitValue = 0U;

    while (MCASP_GBLCTL_RHCLKRST_ACTIVE != bitValue)
    {
        bitValue = McASPGlobalCtlGet(hMcasp->regs);
        bitValue = ((bitValue & MCASP_GBLCTL_RHCLKRST_MASK)
                    >> MCASP_GBLCTL_RHCLKRST_SHIFT);
    }

    tempVal = 0U;
    tempVal = McASPRxClkPolarityGet(hMcasp->regs);

    /* start ACLKR only if internal clock is used                         */
    if ((uint32_t) MCASP_ACLKRCTL_CLKRM_INTERNAL ==
        ((tempVal & (uint32_t) MCASP_ACLKRCTL_CLKRM_MASK)
         >> MCASP_ACLKRCTL_CLKRM_SHIFT))
    {
        bitValue = McASPGlobalCtlGet(hMcasp->regs);
        bitValue = (bitValue & ~(MCASP_GBLCTL_RCLKRST_MASK))
                   | (MCASP_GBLCTL_RCLKRST_ACTIVE
                      << MCASP_GBLCTL_RCLKRST_SHIFT);
        McASPGlobalCtlSet(hMcasp->regs, bitValue);

        bitValue = 0U;

        while (MCASP_GBLCTL_RCLKRST_ACTIVE != bitValue)
        {
            bitValue = McASPGlobalCtlGet(hMcasp->regs);
            bitValue = ((bitValue & MCASP_GBLCTL_RCLKRST_MASK)
                        >> MCASP_GBLCTL_RCLKRST_SHIFT);
        }
    }

    /* Sequence of start: starting hclk first                             */
    tempVal  = McASPTxGlobalCtlGet(hMcasp->regs);
    tempVal &= ~MCASP_GBLCTLX_XHCLKRST_MASK;
    tempVal |= (MCASP_GBLCTLX_XHCLKRST_ACTIVE <<
                MCASP_GBLCTLX_XHCLKRST_SHIFT);
    McASPTxGlobalCtlSet(hMcasp->regs, tempVal);

    bitValue = 0U;

    while (MCASP_GBLCTL_XHCLKRST_ACTIVE != bitValue)
    {
        bitValue = McASPGlobalCtlGet(hMcasp->regs);
        bitValue = (bitValue & MCASP_GBLCTL_XHCLKRST_MASK)
                   >> MCASP_GBLCTL_XHCLKRST_SHIFT;
    }
    tempVal = 0U;
    tempVal = McASPTxClkPolarityGet(hMcasp->regs);
    /* start ACLKX only if internal clock is used                         */
    if ((uint32_t) MCASP_ACLKXCTL_CLKXM_INTERNAL ==
        ((tempVal & (uint32_t) MCASP_ACLKXCTL_CLKXM_MASK)
         >> MCASP_ACLKXCTL_CLKXM_SHIFT))
    {
        tempVal = McASPTxGlobalCtlGet(hMcasp->regs);
        tempVal = (tempVal & ~(MCASP_GBLCTLX_XCLKRST_MASK))
                  | (MCASP_GBLCTLX_XCLKRST_ACTIVE
                     << MCASP_GBLCTLX_XCLKRST_SHIFT);
        McASPTxGlobalCtlSet(hMcasp->regs, tempVal);

        bitValue = 0U;

        while (MCASP_GBLCTL_XCLKRST_ACTIVE != bitValue)
        {
            bitValue = McASPGlobalCtlGet(hMcasp->regs);
            bitValue = (bitValue & MCASP_GBLCTL_XCLKRST_MASK)
                       >> MCASP_GBLCTL_XCLKRST_SHIFT;
        }
    }
  }  
}

/**
 * \brief   This function sets the bits related to receive in RGBLCTL.
 *
 * \param   hMcasp  [IN] Pointer to the Mcasp Hardware info structure
 *
 * \return
 *          MCASP_COMPLETED   - Successful completion
 *          MCASP_EBADARGS    - Invalid parameters or Invalid handle
 *
 */

static void mcaspActivateRcvClkSer(Mcasp_HwHandle hMcasp)
{
    uint32_t bitValue = 0U;
    uint32_t tempVal  = 0;

    if((NULL != hMcasp) && (0 != (hMcasp->regs)))
    {

    /* Sequence of start: starting hclk first                             */
    /* start AHCLKR */
    tempVal = McASPGlobalCtlGet(hMcasp->regs);
    tempVal = ((tempVal & ~MCASP_GBLCTL_RHCLKRST_MASK) |
               (MCASP_GBLCTL_RHCLKRST_ACTIVE <<
                MCASP_GBLCTL_RHCLKRST_SHIFT));
    McASPGlobalCtlSet((uint32_t)hMcasp->regs, tempVal);

    bitValue = 0U;

    while (MCASP_GBLCTL_RHCLKRST_ACTIVE != bitValue)
    {
        bitValue = McASPGlobalCtlGet(hMcasp->regs);
        bitValue = (bitValue & MCASP_GBLCTL_RHCLKRST_MASK)
                   >> MCASP_GBLCTL_RHCLKRST_SHIFT;
    }
#if 0
    /* start ACLKR only if internal clock is used                         */
    if (CSL_MCASP_ACLKRCTL_CLKRM_INTERNAL ==
        (((hMcasp->regs)->ACLKRCTL & CSL_MCASP_ACLKRCTL_CLKRM_MASK)
         >> CSL_MCASP_ACLKRCTL_CLKRM_SHIFT))
    {
        (hMcasp->regs)->GBLCTL =
            ((hMcasp->regs)->GBLCTL & ~(CSL_MCASP_GBLCTL_RCLKRST_MASK))
            | (CSL_MCASP_GBLCTL_RCLKRST_ACTIVE
               << CSL_MCASP_GBLCTL_RCLKRST_SHIFT);

        bitValue = 0U;

        while (CSL_MCASP_GBLCTL_RCLKRST_ACTIVE != bitValue)
        {
            bitValue = (((hMcasp->regs)->GBLCTL
                         & CSL_MCASP_GBLCTL_RCLKRST_MASK)
                        >> CSL_MCASP_GBLCTL_RCLKRST_SHIFT);
        }
    }
#else
    tempVal = 0U;
    tempVal = McASPRxClkPolarityGet((uint32_t)hMcasp->regs);

    /* start ACLKR only if internal clock is used                         */
    if ((uint32_t) MCASP_ACLKRCTL_CLKRM_INTERNAL ==
        ((tempVal & (uint32_t) MCASP_ACLKRCTL_CLKRM_MASK)
         >> MCASP_ACLKRCTL_CLKRM_SHIFT))
    {
        bitValue = McASPGlobalCtlGet(hMcasp->regs);
        bitValue = (bitValue & ~(MCASP_GBLCTL_RCLKRST_MASK))
                   | (MCASP_GBLCTL_RCLKRST_ACTIVE
                      << MCASP_GBLCTL_RCLKRST_SHIFT);
        McASPGlobalCtlSet((uint32_t)hMcasp->regs, bitValue);

        bitValue = 0U;

        while (MCASP_GBLCTL_RCLKRST_ACTIVE != bitValue)
        {
            bitValue = McASPGlobalCtlGet((uint32_t)hMcasp->regs);
            bitValue = ((bitValue & MCASP_GBLCTL_RCLKRST_MASK)
                        >> MCASP_GBLCTL_RCLKRST_SHIFT);
        }
    }
#endif

#if 0
    (hMcasp->regs)->RGBLCTL =
        ((hMcasp->regs)->RGBLCTL & ~(CSL_MCASP_RGBLCTL_RSRCLR_MASK))
        | (CSL_MCASP_RGBLCTL_RSRCLR_ACTIVE
           << CSL_MCASP_RGBLCTL_RSRCLR_SHIFT);

    bitValue = 0U;

    while (CSL_MCASP_GBLCTL_RSRCLR_ACTIVE != bitValue)
    {
        bitValue = (((hMcasp->regs)->GBLCTL & CSL_MCASP_GBLCTL_RSRCLR_MASK)
                    >> CSL_MCASP_GBLCTL_RSRCLR_SHIFT);
    }
#else
    tempVal = McASPRxGlobalCtlGet(hMcasp->regs);
    tempVal = (tempVal & ~(MCASP_GBLCTL_RSRCLR_MASK))
              | (MCASP_GBLCTL_RSRCLR_ACTIVE
                 << MCASP_GBLCTL_RSRCLR_SHIFT);
    McASPRxGlobalCtlSet(hMcasp->regs, tempVal);

    bitValue = 0U;

    while (MCASP_GBLCTL_RSRCLR_ACTIVE != bitValue)
    {
        bitValue = McASPGlobalCtlGet(hMcasp->regs);
        bitValue = (bitValue & MCASP_GBLCTL_RSRCLR_MASK)
                   >> MCASP_GBLCTL_RSRCLR_SHIFT;
    }
#endif
  }
}

/**
 * \brief   This function sets the bits related to transmit in RGBLCTL.
 *
 * \param   hMcasp  [IN] Pointer to the Mcasp Hardware info structure
 *
 * \return
 *          MCASP_COMPLETED   - Successful completion
 *          MCASP_EBADARGS    - Invalid parameters or Invalid handle
 *
 */
static void mcaspActivateXmtClkSer(Mcasp_HwHandle hMcasp)
{
    uint32_t bitValue = 0U;
    uint32_t tempVal  = 0;

    if((NULL != hMcasp) && (0 != (hMcasp->regs)))
    {
    /* Sequence of start: starting hclk first*/

    tempVal  = McASPTxGlobalCtlGet(hMcasp->regs);
    tempVal &= ~MCASP_GBLCTLX_XHCLKRST_MASK;
    tempVal |= (MCASP_GBLCTLX_XHCLKRST_ACTIVE <<
                MCASP_GBLCTLX_XHCLKRST_SHIFT);
    McASPTxGlobalCtlSet(hMcasp->regs, tempVal);

    bitValue = 0U;

    while (MCASP_GBLCTL_XHCLKRST_ACTIVE != bitValue)
    {
        bitValue = McASPGlobalCtlGet(hMcasp->regs);
        bitValue = (bitValue & MCASP_GBLCTL_XHCLKRST_MASK)
                   >> MCASP_GBLCTL_XHCLKRST_SHIFT;
    }
    tempVal = 0U;
    tempVal = McASPTxClkPolarityGet(hMcasp->regs);

    /* start ACLKX only if internal clock is used*/
    if ((uint32_t) MCASP_ACLKXCTL_CLKXM_INTERNAL ==
        ((tempVal & (uint32_t) MCASP_ACLKXCTL_CLKXM_MASK)
         >> MCASP_ACLKXCTL_CLKXM_SHIFT))
    {
        tempVal = McASPTxGlobalCtlGet(hMcasp->regs);
        tempVal = (tempVal & ~(MCASP_GBLCTLX_XCLKRST_MASK))
                  | (MCASP_GBLCTLX_XCLKRST_ACTIVE
                     << MCASP_GBLCTLX_XCLKRST_SHIFT);
        McASPTxGlobalCtlSet((uint32_t)hMcasp->regs, tempVal);

        bitValue = 0U;

        while (MCASP_GBLCTL_XCLKRST_ACTIVE != bitValue)
        {
            bitValue = McASPGlobalCtlGet(hMcasp->regs);
            bitValue = (bitValue & MCASP_GBLCTL_XCLKRST_MASK)
                       >> MCASP_GBLCTL_XCLKRST_SHIFT;
        }
    }
    tempVal = 0U;

    tempVal  = McASPTxGlobalCtlGet(hMcasp->regs);
    tempVal &= ~MCASP_GBLCTLX_XSRCLR_MASK;
    tempVal |= (MCASP_GBLCTLX_XSRCLR_ACTIVE <<
                MCASP_GBLCTLX_XSRCLR_SHIFT);

    bitValue = 0U;

    while (MCASP_GBLCTL_XSRCLR_ACTIVE != bitValue)
    {
        bitValue = McASPGlobalCtlGet(hMcasp->regs);
        bitValue = (bitValue & MCASP_GBLCTL_XSRCLR_MASK)
                   >> MCASP_GBLCTL_XSRCLR_SHIFT;
    }
  }  
}

#endif
 /*  \brief  This function is used to get the value of various parameters of the
 *          McASP instance. The value returned depends on the query passed.
 *
 *  \param  hMcasp    [IN]    Handle to mcasp H/W information structure
 *  \param  myQuery   [IN]    Query requested by application
 *  \param  response  [IN]    Pointer to buffer to return the data requested by
 *                            the query passed
 *  \param  eb        [IN]    pointer to error block
 *
 *  \return
 *          MCASP_COMPLETED  - Successful completion of the query
 *          IOM error code - in case of error.
 *
 */
static int32_t mcaspGetHwStatus(Mcasp_HwHandle        hMcasp,
                              Mcasp_HwStatusQuery   myQuery,
                              void                 *const response)
{
    int32_t                status      = MCASP_COMPLETED;
	uint32_t               tempVal;
    Mcasp_SerQuery     *serQuery     = NULL;
    Mcasp_SerModeQuery *serModeQuery = NULL;


   if((NULL != hMcasp) && (NULL != response))
   {
    switch (myQuery)
    {
        /* Return current transmit slot being transmitted                 */
        case Mcasp_HwStatusQuery_CURRENT_XSLOT:
            *((Uint16 *)response) =
                McASPCurrTransmitSlot(hMcasp->regs);
            break;

        /* Return current receive slot being received                     */
        case Mcasp_HwStatusQuery_CURRENT_RSLOT:
            *((Uint16 *)response) =
                McASPCurrReceiveSlot(hMcasp->regs);
            break;

        /* Return transmit error status bit                               */
        case Mcasp_HwStatusQuery_XSTAT_XERR:
            *(Bool *)response =
                (Bool) McASPTxErrStatus(hMcasp->regs, MCASP_TX_STAT_ERR);
            break;

        /* Return transmit clock failure flag status                      */
        case Mcasp_HwStatusQuery_XSTAT_XCLKFAIL:
            *(Bool *)response =
                (Bool) McASPTxErrStatus(hMcasp->regs, MCASP_TX_STAT_CLKFAIL);
            break;

        /* Return unexpected transmit frame sync flag status              */
        case Mcasp_HwStatusQuery_XSTAT_XSYNCERR:
            *(Bool *)response =
                (Bool) McASPTxErrStatus(hMcasp->regs, MCASP_TX_STAT_SYNCERR);
            break;

        /* Return transmit underrun flag status                           */
        case Mcasp_HwStatusQuery_XSTAT_XUNDRN:
            *((Bool *)response) =
                (Bool) McASPTxErrStatus(hMcasp->regs, MCASP_TX_STAT_UNDERRUN);
            break;

        /* Return transmit data ready flag status                         */
        case Mcasp_HwStatusQuery_XSTAT_XDATA:
            (*(Bool *)response) =
                (Bool) McASPTxErrStatus(hMcasp->regs, MCASP_TX_STAT_DATAREADY);
            break;

        /* Return receive error status bit                                */
        case Mcasp_HwStatusQuery_RSTAT_RERR:
            *((Bool *)response) =
                (Bool) McASPRxErrStatus(hMcasp->regs, MCASP_RX_STAT_ERR);
            break;

        /* Return receive clk failure flag status                         */
        case Mcasp_HwStatusQuery_RSTAT_RCLKFAIL:
            *((Bool *)response) =
                (Bool) McASPRxErrStatus(hMcasp->regs,
                                        (uint32_t) MCASP_RXSTAT_RCKFAIL_MASK);
            break;

        /* Return unexpected receive frame sync flag status               */
        case Mcasp_HwStatusQuery_RSTAT_RSYNCERR:
            *((Bool *)response) =
                (Bool) McASPRxErrStatus(hMcasp->regs,
                                        (uint32_t) MCASP_RXSTAT_RSYNCERR_MASK);
            break;

        /* Return receive overrun flag status                             */
        case Mcasp_HwStatusQuery_RSTAT_ROVRN:
            *((Bool *)response) =
                (Bool) McASPRxErrStatus(hMcasp->regs,
                                        (uint32_t) MCASP_RXSTAT_ROVRN_MASK);
            break;
        /* Return receive data ready flag status                          */
        case Mcasp_HwStatusQuery_RSTAT_RDATA:
            *((Bool *)response) =
                (Bool) McASPRxErrStatus(hMcasp->regs,
                                        (uint32_t) MCASP_RXSTAT_RDATA_MASK);
            break;

        /* Return status whether rrdy is set or not                       */
        case Mcasp_HwStatusQuery_SRCTL_RRDY:
            {
                serQuery = (Mcasp_SerQuery *)response;
                mcaspGetSerRcvReady(
                             hMcasp,
                             (Bool *)&(serQuery->serStatus),
                             serQuery->serNum);
            }
            break;

        /* Return status whether xrdy is set or not                       */
        case Mcasp_HwStatusQuery_SRCTL_XRDY:
            {
                serQuery = (Mcasp_SerQuery *)response;
                mcaspGetSerXmtReady(
                            hMcasp,
                            (Bool *)&(serQuery->serStatus),
                            serQuery->serNum);
            }
            break;
       /* Return status whether serializer is configured as TX/RX/FREE    */
       case Mcasp_HwStatusQuery_SRCTL_SRMOD:
            {
                serModeQuery = (Mcasp_SerModeQuery *)response;
                mcaspGetSerMode(hMcasp,
                                &(serModeQuery->serMode),
                                serModeQuery->serNum);
                break;
            }

        /* Return the value of XSTAT register                             */
        case Mcasp_HwStatusQuery_XSTAT:
            *((UInt16 *) response) = (UInt16)
                                     McASPTxStatusGet(hMcasp->regs);
            break;

        /* Return the value of RSTAT register                             */
        case Mcasp_HwStatusQuery_RSTAT:
            *((UInt16 *) response) = (UInt16)
                                     McASPRxStatusGet(hMcasp->regs);
            break;

        /* Return the XSMRST and XFRST field values GBLCTL register       */
        case Mcasp_HwStatusQuery_SM_FS_XMT:
            *((uint8_t *) response) = McASPGetSmFsXmt(hMcasp->regs);
            break;

        /* Return the RSMRST and RFRST field values GBLCTL register       */
        case Mcasp_HwStatusQuery_SM_FS_RCV:
            *((uint8_t *) response) = McASPGetSmFsRcv(hMcasp->regs);
            break;

        /* Return status of DITEN bit in DITCTL register                  */
        case Mcasp_HwStatusQuery_DIT_MODE:
            tempVal = McASPDITModeCtlRead(hMcasp->regs);
            tempVal = (tempVal & MCASP_TXDITCTL_DITEN_MASK) >>
                      MCASP_TXDITCTL_DITEN_SHIFT;
            *((Bool *) response) = (Bool) tempVal;
            break;
#if defined(SOC_AM335x) || defined(SOC_AM437x) || defined(SOC_K2G)
        case Mcasp_HwStatusQuery_AMUTE:
            *((Uint16 *)response) = (uint16_t)McASPAmuteGetQuery(hMcasp->regs);
            break;
#endif
        default:
            status = MCASP_EBADARGS;
            break;
    }
  } else
  {
	  status = MCASP_EBADARGS;
  }
    return status;
}

/**
 * \brief   This function checks whether transmit buffer ready bit of serializer
 *          control register is set or not
 *
 * \param   hMcasp      [IN] pointer to the Mcasp Hardware information structure
 * \param   serXmtReady [IN] Status of the serializer will be stored here
 * \param   serNum      [IN] serializer number to be checked
 *
 * \return
 *          MCASP_COMPLETED   - Successful completion
 *          MCASP_EBADARGS    - Invalid parameters or Invalid handle
 *
 */

static void mcaspGetSerXmtReady(Mcasp_HwHandle        hMcasp,
                                Bool                 *serXmtReady,
                                Mcasp_SerializerNum   serNum)
{
    if((NULL != serXmtReady) && (NULL != hMcasp) && (serNum < hMcasp->numOfSerializers))
    {
       *(Bool *)serXmtReady =
       (Bool) McASPIsSerializerXmtReady(hMcasp->regs, serNum);
    }   
}

/**
 * \brief   This function checks whether receive buffer ready bit of serializer
 *          control register is set or not
 *
 * \param   hMcasp      [IN] pointer to the Mcasp Hardware information structure
 * \param   serRcvReady [IN] Serailizer status will be stored here
 * \param   serNum      [IN] Serailizer register to be checked
 *
 * \return
 *          MCASP_COMPLETED   - Successful completion of read
 *          MCASP_EBADARGS    - Invalid parameters or Invalid handle
 *
 *
 */

static void mcaspGetSerRcvReady(Mcasp_HwHandle       hMcasp,
                                 Bool                *serRcvReady,
                                 Mcasp_SerializerNum  serNum)
{

    if((NULL != serRcvReady) && (NULL != hMcasp) && (serNum < hMcasp->numOfSerializers))
    {
      (*(Bool *) serRcvReady) =
         (Bool) McASPIsSerializerRcvReady(hMcasp->regs, serNum);
    }     
}

/**
 * \brief   This function gets the current mode for the serializer requested
 *
 * \param   hMcasp    [IN]  pointer to the Mcasp Hardware information structure
 * \param   serMode   [IN]  Serializer mode will be stored here
 * \param   serNum    [IN]  Serailizer number to be checked
 *
 * \return
 *          MCASP_COMPLETED   - Successful completion
 *          MCASP_EBADARGS    - Invalid parameters or Invalid handle
 *
 */
static void mcaspGetSerMode(Mcasp_HwHandle        hMcasp,
                            Mcasp_SerMode        *serMode,
                            Mcasp_SerializerNum   serNum)
{
    uint32_t serializerVal = 0x0;

    if( (NULL != serMode) && (NULL != hMcasp) && (serNum < hMcasp->numOfSerializers) )
    {
      serializerVal = McASPSerializerGet(hMcasp->regs, serNum);
      *serMode      = (Mcasp_SerMode) ((serializerVal & MCASP_XRSRCTL0_SRMOD_MASK)
                                     >> MCASP_XRSRCTL0_SRMOD_SHIFT);
    }                                 
}


/**
 *  \brief    mcaspReadRcvConfig
 *
 *   Reads the configuration data of the receive section and updates the info
 *   to the pointer provided by the application.
 *
 *  \param    hMcasp         [IN]    Handle to mcasp hw information structure
 *  \param    rcvData        [OUT]   pointer to copy the data to
 *
 *  \return   Nothing
 *
 */
static void mcaspReadRcvConfig(Mcasp_HwHandle       hMcasp,
                               Mcasp_HwSetupData   *const rcvData)
{
    if ((NULL != hMcasp) && (NULL != rcvData))
    {
    /* Read RMASK register             */
    rcvData->mask = (uint32_t) McASPRxFmtMaskGet(hMcasp->regs);

    /* Read RFMT register              */
    rcvData->fmt = (uint32_t) McASPRxFmtGet(hMcasp->regs);

    /* Read AFSRCTL register           */
    rcvData->frSyncCtl = (uint32_t) McASPTxRxFrameSyncRead(hMcasp->regs,
                                                         (uint8_t) RX);

    /* Read AHCLKRCTL register         */
    rcvData->clk.clkSetupClk = (uint32_t)
                               McASPRxClkPolarityGet(hMcasp->regs);

    /* Read ACLKRCTL register          */
    rcvData->clk.clkSetupHiClk = (uint32_t)
                                 McASPRxHClkPolarityGet(hMcasp->regs);

    /* Read RTDM register              */
    rcvData->tdm = (uint32_t)
                   McASPTxRxTimeSlotGet(hMcasp->regs, (uint8_t) RX);

    /* Read RINTCTL register           */
    rcvData->intCtl = (uint32_t) McASPRxIntrStatusGet(hMcasp->regs);

    /* Read RCLKCHK register           */
    rcvData->clk.clkChk = (uint32_t)
                          McASPRxClkCheckRegRead(hMcasp->regs);

    /* Read RSTAT register             */
    rcvData->stat = (uint32_t)
                    McASPRxStatusGet(hMcasp->regs);

    /* Read REVTCTL register           */
    rcvData->evtCtl = (uint32_t)
                      McASPTxRxDMAEvtCntrlRead(hMcasp->regs, (uint8_t) RX);
   }                   
}

/**
 *  \brief    mcaspReadXmtConfig
 *
 *   Reads the configuration data of the transmit section and updates
 *   the info to the pointer provided by the application.
 *
 *  \param    hMcasp        [IN]    Handle to mcasp hw information structure
 *  \param    xmtData       [OUT]   pointer to copy the data from
 *
 *  \return   Nothing
 *
 */
static void mcaspReadXmtConfig(Mcasp_HwHandle       hMcasp,
                               Mcasp_HwSetupData   *const xmtData)
{
    if((NULL != hMcasp) && (NULL != xmtData))
    {
    /* Read XMASK register              */
    xmtData->mask = (uint32_t) McASPTxFmtMaskGet(hMcasp->regs);

    /* Read XFMT register               */
    xmtData->fmt = (uint32_t) McASPTxFmtGet(hMcasp->regs);

    /* Read AFSXCTL register            */
    xmtData->frSyncCtl = (uint32_t) McASPTxRxFrameSyncRead(hMcasp->regs,
                                                         (uint8_t) TX);

    xmtData->clk.clkSetupClk = (uint32_t)
                               McASPTxClkPolarityGet(hMcasp->regs);

    /* Read AHCLKXCTL register          */
    xmtData->clk.clkSetupHiClk = (uint32_t)
                                 McASPTxHClkPolarityGet(hMcasp->regs);

    /* Read XTDM register               */
    xmtData->tdm = (uint32_t)
                   McASPTxRxTimeSlotGet(hMcasp->regs, (uint8_t) TX);

    /* Read XINTCTL register            */
    xmtData->intCtl = (uint32_t) McASPTxIntrStatusGet(hMcasp->regs);

    /* Read XCLKCHK register            */
    xmtData->clk.clkChk = (uint32_t)
                          McASPTxClkCheckRegRead(hMcasp->regs);

    /* Read XSTAT register              */
    xmtData->stat = (uint32_t)
                    McASPTxStatusGet(hMcasp->regs);

    /* Read XEVTCTL register            */
    xmtData->evtCtl = (uint32_t)
                      McASPTxRxDMAEvtCntrlRead(hMcasp->regs, (uint8_t) TX);
   }
}

/*
 *  \brief  Abort the operation of the requested Mcasp Channel. This function
 *          Aborts all current and pending Read and write requests
 *
 *  \param  handle   [IN]   Handle to the McASP channel
 *  \param  arg      [IN]   Unused argument(for future use)
 *  \param  eb       [OUT]  pointer to the error block
 *
 *  \return MCASP_COMPLETED or Error code
 *
 */
int32_t Mcasp_localAbortRequests(void* handle,void* arg)
{
    Mcasp_ChannelHandle   chanHandle = NULL;
    Mcasp_Object         *instHandle = NULL;
    int32_t                 status     = MCASP_COMPLETED;

    if ( (NULL != handle) && (NULL != ((Mcasp_ChannelHandle)handle)->devHandle) )
    {
    chanHandle = (Mcasp_ChannelHandle)handle;

    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    if (Mcasp_DriverState_OPENED == chanHandle->chanState)
    {
        /* Abort the requested channels                               */
        if (MCASP_INPUT == chanHandle->mode)
        {
            status = Mcasp_localAbortReset(&instHandle->RcvObj);
        }
        else
        {
            status = Mcasp_localAbortReset(&instHandle->XmtObj);
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
 *
 * \brief   This function configures the sample rate for the Mcasp.
 *
 * \param   chanHandle  [IN]  handle to the channel
 * \param   ioctlArg    [IN]  Pointer to the IOCTL arguments
 *
 * \return  MCASP_COMPLETED if success or else error code
 *
 */
static int32_t mcaspSetSamplingRate(Mcasp_ChannelHandle  chanHandle,
                                  void*                  ioctlArg)
{
    Mcasp_Object  *instHandle = NULL;
    Mcasp_HwSetup *hwSetUp    = NULL;
    int32_t          status     = MCASP_COMPLETED;

    if ( (NULL != chanHandle) && (NULL != ((Mcasp_ChannelHandle)chanHandle)->devHandle) && (NULL != ioctlArg) )
    {

    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    hwSetUp = (Mcasp_HwSetup *)ioctlArg;

    /* These values will not be changed hence we will take a copy of these    *
     * and reset the same values in the configuring of the TX ans RX sections */
    hwSetUp->tx.mask      = McASPTxFmtMaskGet(instHandle->hwInfo.regs);
    hwSetUp->tx.fmt       = McASPTxFmtGet(instHandle->hwInfo.regs);
    hwSetUp->tx.frSyncCtl = (uint32_t) McASPTxRxFrameSyncRead(
        instHandle->hwInfo.regs,
        (uint8_t) TX);
    hwSetUp->tx.tdm = McASPTxRxTimeSlotGet(instHandle->hwInfo.regs,
                                           (uint8_t) TX);
    hwSetUp->tx.intCtl = McASPTxIntrStatusGet(instHandle->hwInfo.regs);
    hwSetUp->tx.evtCtl =
        McASPTxRxDMAEvtCntrlRead(instHandle->hwInfo.regs, (uint8_t) TX);

    status = Mcasp_localConfigXmtSection(instHandle, &hwSetUp->tx);

    if (MCASP_COMPLETED == status)
    {
        hwSetUp->rx.mask = McASPRxFmtMaskGet(instHandle->hwInfo.regs);
        hwSetUp->rx.fmt  = McASPRxFmtGet(instHandle->hwInfo.regs);

        hwSetUp->tx.frSyncCtl = (uint32_t) McASPTxRxFrameSyncRead(
            instHandle->hwInfo.regs, (uint8_t) RX);

        hwSetUp->rx.tdm =
            McASPTxRxTimeSlotGet(instHandle->hwInfo.regs, (uint8_t) RX);
        hwSetUp->rx.intCtl = McASPRxIntrStatusGet(instHandle->hwInfo.regs);
        hwSetUp->rx.evtCtl = McASPTxRxDMAEvtCntrlRead(instHandle->hwInfo.regs,
                                                      (uint8_t) RX);

        status = Mcasp_localConfigRcvSection(instHandle, &hwSetUp->rx);
    }
  }
  else
  {
     status = MCASP_EBADARGS;
  }  
    return status;
}


/**
 *
 * \brief   This function gets the device related information of the mcasp.
 *
 * \param   chanHandle  [IN]  handle to the channel
 * \param   arg         [IN]  pointer to the Mcasp_AudioDevData structure
 *                            supplied by the application.
 *
 * \return  None
 *
 */
static void mcaspDeviceInfoGet(Mcasp_ChannelHandle  chanHandle,
                               void*                  arg)
{
    Mcasp_Object       *instHandle = NULL;
    Mcasp_AudioDevData *devData    = NULL;
    Bool                isMaster   = FALSE;
    uint32_t tempVal1 = 0x0;
    uint32_t tempVal2 = 0x0;

    if((chanHandle != NULL) && (NULL != arg))
    {
    devData = (Mcasp_AudioDevData *)arg;

    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    if(NULL != instHandle)
    {
    tempVal1 = McASPTxClkPolarityGet(instHandle->hwInfo.regs);
    tempVal2 = McASPRxClkPolarityGet(instHandle->hwInfo.regs);
    /* check if the bit clock of the TX section is generated internally       */
    if ((uint32_t) MCASP_ACLKXCTL_CLKXM_INTERNAL ==
        ((tempVal1 & (uint32_t) MCASP_ACLKXCTL_CLKXM_MASK)
         >> MCASP_ACLKXCTL_CLKXM_SHIFT))
    {
        /* check if both the sections are in sync                             */
        if ((uint32_t) MCASP_ACLKXCTL_ASYNC_SYNC ==
            ((tempVal1 & (uint32_t) MCASP_ACLKXCTL_ASYNC_MASK)
             >> MCASP_ACLKXCTL_ASYNC_SHIFT))
        {
            /* check if the TX and RX sections are in sync                    */
            isMaster = TRUE;
        }
        else
        {
            /* check if the transmit bit clock is generated internally        */
            if ((uint32_t) MCASP_ACLKRCTL_CLKRM_INTERNAL ==
                ((tempVal2 & (uint32_t) MCASP_ACLKRCTL_CLKRM_MASK)
                 >> MCASP_ACLKRCTL_CLKRM_SHIFT))
            {
                isMaster = TRUE;
            }
        }
      }
     }
    /* update the information to the data structure                           */
    devData->isMaster = (uint16_t)isMaster;
   }
}

/* ========================================================================== */
/*                             END OF FILE                                    */
/* ========================================================================== */
