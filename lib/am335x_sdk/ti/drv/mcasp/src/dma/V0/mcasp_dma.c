/*
 * mcasp_dma.c
 *
 * This file contains local functions for McASP driver which contain implemen-
 * tation for EDMA operation specifc calls like starting an EDMA transfer for
 * for McASP peripheral, EDMA completion and/or error callbacks etc
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
 *  \file   V0/mcasp_dma.c
 *
 *  \brief  This files contains the edma functions required for the Mcasp driver
 *          to function in the EDMA mode.
 *
 *   (C) Copyright 2019, Texas Instruments, Inc
 *
 *
 * \version   0.2     Added the support for the Non loop job mode
 *            0.1     Newly created.
 */

/* ========================================================================== */
/*                             INCLUDE FILES                                  */
/* ========================================================================== */

#include <ti/csl/cslr_device.h>
#include <ti/sdo/edma3/drv/src/edma3.h>
#include <ti/drv/mcasp/mcasp_drv.h>
#include <ti/drv/mcasp/mcasp_osal.h>
#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include <include/McaspLocal.h>

extern Mcasp_TempBuffer Mcasp_muteBuf[MCASP_CNT];

/* ========================================================================== */
/*                         LOCAL FUNCTION PROTOTYPES                          */
/* ========================================================================== */

/* ========================================================================== */
/*                          FUNCTION DEFINITIONS                              */
/* ========================================================================== */

/**
 *  \brief  This function is called during channel creation (during open)
 *          This function does the following
 *          1) Request the Xfer (in/out depends on mode) channel to EDMA
 *             driver for this peripheral;
 *          2) Requests the link channels for linking (exclusive for each
 *             direction (tx/rx)
 *
 *  \param  chanHandle  [IN]  pointer to the channel object
 *  \param  hwInfo      [IN]  pointer to the Mcasp_HwObj object
 *
 *  \return  status     MCASP_COMPLETED if is sucess
 *                      error id in case of failure
 *
 */
int32_t Mcasp_setupDmaDuringOpen(Mcasp_ChannelHandle chanHandle,
                                 Mcasp_HwObj *hwInfo)
{
    uint32_t              reqTcc      = EDMA3_DRV_TCC_ANY;
    EDMA3_RM_EventQueue queueNum    = 0;
    Bool                falsewhile  = TRUE;
    uint32_t              linkCnt     = 0;
    uint32_t              edmaChanNum = 0;
    uint32_t              count       = 0;
    int32_t               status      = MCASP_COMPLETED;

    do
    {
      if( (NULL != chanHandle) && (NULL != hwInfo) )
      {
        falsewhile  = FALSE;

        chanHandle->edmaCallback = &Mcasp_localEdmaCallback;

        /* For receive use EDMA Queue 1 and for transmit use EDMA queue 0     */
        if (MCASP_INPUT == chanHandle->mode)
        {
            /* Assign unique event queue number for all Rx channels */
            queueNum = (EDMA3_RM_EventQueue)Mcasp_RXEVENTQUE;

            /* Assign the Channel ID and TCC                          */
            chanHandle->xferChan  = hwInfo->dmaRxEventNum;
            chanHandle->tcc = hwInfo->dmaRxEventNum;
        }
        else
        {
            /* Assign unique event queue number for all Tx channels */
            queueNum = (EDMA3_RM_EventQueue)Mcasp_TXEVENTQUE;

            /* Assign the Channel ID and TCC                          */
            chanHandle->xferChan  = hwInfo->dmaTxEventNum;
            chanHandle->tcc   = hwInfo->dmaTxEventNum;
        }

        status = EDMA3_DRV_requestChannel(
                     chanHandle->edmaHandle,
                     &chanHandle->xferChan,
                     &chanHandle->tcc,
                     queueNum,
                     (chanHandle->edmaCallback),
                     chanHandle);

        if (MCASP_COMPLETED != status)
        {
            status = MCASP_EBADARGS;
            break;
        }

        /* Acquire the  PaRAM entries used for EDMA transfers linking         */
        for (count = 0; count < chanHandle->maxActiveSubmit; count++)
        {
            /* For requesting for a PaRam set                                 */
            edmaChanNum = EDMA3_DRV_LINK_CHANNEL;
            reqTcc = EDMA3_DRV_TCC_ANY;

            status = EDMA3_DRV_requestChannel(
                        chanHandle->edmaHandle,
                        &edmaChanNum,
                        &reqTcc,
                        queueNum,
                        (chanHandle->edmaCallback),
                        NULL);

            if (MCASP_COMPLETED == status)
            {
                chanHandle->pramTbl[count] = edmaChanNum;

                status = EDMA3_DRV_getPaRAMPhyAddr(
                            chanHandle->edmaHandle,
                            chanHandle->pramTbl[count],
                            &(chanHandle->pramTblAddr[count]));
            }

            if (MCASP_COMPLETED != status )
            {
                /* free the Synchonized EDMA channel                          */
                EDMA3_DRV_freeChannel(
                    chanHandle->edmaHandle,
                    chanHandle->xferChan);

                /* free the already allocated PaRAM entries                   */
                for (linkCnt = 0; linkCnt <count; linkCnt++)
                {
                    EDMA3_DRV_freeChannel(
                        chanHandle->edmaHandle,
                        chanHandle->pramTbl[linkCnt]);
                }

                status = MCASP_EBADARGS;
                break;
            }
        }

        /* Configure EDMA channels                                            */
        status = Mcasp_setupDmaChan(chanHandle);
     } 
     else
     {
        status = MCASP_EBADARGS;
     }
        
    }while(falsewhile);

    return status;
}

#ifdef Mcasp_LOOPJOB_ENABLED
/**
 *  \brief   This calls the registered application callback for the current
 *           receive request and processes the next request in queue.
 *           This if a mcasp edma callback function called in edma context
 *
 *  \param   tcc     [IN]    tcc number of EDMA
 *  \param   status  [IN]    status of EDMA transaction
 *  \param   data    [IN]    paramaters sent to EDMA ISR (chan handler)
 *
 *  \return  Nothing
 *
 */
void Mcasp_localEdmaCallback(uint32_t tcc, EDMA3_RM_TccStatus status, Ptr data)
{
    Mcasp_Object         *instHandle = NULL;
    Mcasp_ChannelHandle   chanHandle = NULL;
    EDMA3_DRV_PaRAMRegs   pramTbl    = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    MCASP_Packet           *ioPacket   = NULL;
    Bool falsewhile = (Bool) TRUE;
    uint32_t dlbMode  = 0;
    int32_t retVal    = MCASP_COMPLETED;
    Mcasp_PktAddrPayload *payLoad = NULL;
    Bool  getQueueTempStatus;
    void *tempCastPacket;

    do
    {
      falsewhile = (Bool) FALSE;

       /* To remove the compiler warning                                     */
       tcc = tcc;

       chanHandle = (Mcasp_ChannelHandle) data;

       if ((NULL != chanHandle) && (NULL != chanHandle->devHandle) ) 
       {
        instHandle = (Mcasp_Object *) chanHandle->devHandle;
        if ((Bool) TRUE ==
            Osal_Queue_empty(Osal_Queue_handle(&(chanHandle->queueFloatingList))))
        {
            /* This cannot happen, if it happens then it is a sprurios one    */
            retVal = MCASP_EBADMODE;
        }

        /* For DMA transactions all the floating packets are managed in       *
         * queueFloatingList  Now pop out the packet from the queue and       *
         * complete it                                                        */
        if (MCASP_COMPLETED == retVal)
        {
            chanHandle->tempPacket = (MCASP_Packet *) Osal_Queue_get(
                Osal_Queue_handle(&(chanHandle->queueFloatingList)));

            /*
             *                   -------
             | xfer  |
             | chan  |
             |                   -------
             |                                              Floating queue
             |                                              --------------
             |           -------     -------     -------        |
             |       |   |       |   |       |<------
             |   B   |   |   A   |   |   A   |
             |           -------     -------     -------
             |       |
             |   B   |
             |                                   -------
             * As shown in the figure above, There are two IO request present in
             * floating queue. Whenever EDMA completetion callback is called,
             * xfer channel will be transferring data of one of the request. As
             * this is a ping-pong implementation, link params are linked to
             * each other. Meaning once data transfer of IO A is complete,data
             * transfer of IO B will be initiated. Ideally, when control comes to this
             * function xfer channel should be servicing the 2nd request of the
             * floating queue. Here,in above illustration when callback is
             * called, xfer channel should be servicing request B while request A is
             * completed.
 			 * When due to any reason, CPU is halted(it can be due to
             * break-point,memory access view using CCS,accessing variables using watch
             * window etc.) EDMA will continue trasferring data. So assuming when CPU
             * is halted EDMA is servicing request A, data transfer of request A
             * will continue but ISR of transfer complete will not serve as CPU is
             * halted. As request A is complete and param A is linked with param B which
             * is holding request B, EDMA will start servicing request B. Again
             * EDMA will complete the request B service but transfer complete
             * ISR will not come as CPU is halted. But now as this is a
             * ping-pong implementation, EDMA will start servicing request A. This will
             * ping-pong will continue until CPU is taken out of halt. After
             * that first transfer complete ISR is due to which request is not known
             * to driver. It can be either request A or B.The problem will arise
             * when xfer channel is servicing A when callback is called. In that
             * case,request that is in the servicing, will be returned to the app
             * as serviced. This will lead to continuous noise.
             * To take care the above problem, when callback is called, check is
             *  done to verify if the xfer channel is servicing the request A or
             *  B. If EDMA is servicing request A, requests are queued in a
             * proper  sequence and no callback is called. When a next callback is
             * called it will be of request A, so floating queue is dequeued and from
             *  there on normal operation will continue.
			 */

            /* get the param table information of transfer channel
             *               */
            EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle) chanHandle->edmaHandle,
                               chanHandle->xferChan, &pramTbl);
        }
        if ((chanHandle->mode == MCASP_INPUT) && (MCASP_COMPLETED == retVal))
        {
            /* Check if destination address falls into the range of 1st req   *
             * in the floating queue.                                         */
            if ((Bool) TRUE == instHandle->isDataBufferPayloadStructure)
            {
              payLoad = (Mcasp_PktAddrPayload *) chanHandle->tempPacket->addr;
              if(NULL != payLoad)
              {
                getQueueTempStatus =
                    Osal_Queue_empty(Osal_Queue_handle(&(chanHandle->queueFloatingList)));
                if (((pramTbl.destAddr >= (uint32_t) payLoad->addr)
                     && (pramTbl.destAddr < ((uint32_t) payLoad->addr
                                             + chanHandle->tempPacket->size)))
                    &&
                    ((Bool) FALSE == getQueueTempStatus))
                {
                    /* Since we have already dequeue the 1st request, dequeue *
                     * 2nd io request from floating queue                     */
                    ioPacket = (MCASP_Packet *) Osal_Queue_get(
                        Osal_Queue_handle(&chanHandle->queueFloatingList));

                    if(NULL != ioPacket)
                    {
                      /* Queue the tempPacket (i.e. 1st io request) as this pkt *
                     * should be first in a queue                             */
                      tempCastPacket = (void *) chanHandle->tempPacket;
                      Osal_Queue_put(
                        Osal_Queue_handle(&chanHandle->queueFloatingList),
                        (Osal_Queue_Elem *) tempCastPacket);

                      /* Queue the ioPacket i.e. 2nd request in floating queue  */
                      tempCastPacket = (void *) ioPacket;
                      Osal_Queue_put(Osal_Queue_handle(&chanHandle->queueFloatingList),
                              (Osal_Queue_Elem *) tempCastPacket);
                      retVal = MCASP_EBADMODE;
                    }  
                    else
                    {
                       retVal = MCASP_EINVALIDVAL;     
                    }
                }
              }
              else
              {
                retVal = MCASP_EINVALIDVAL;     
              }  
            }
            else
            {
                getQueueTempStatus =
                    Osal_Queue_empty(Osal_Queue_handle(&(chanHandle->queueFloatingList)));
                if (((pramTbl.destAddr >= (uint32_t) chanHandle->tempPacket->addr)
                     && (pramTbl.destAddr <
                         ((uint32_t) chanHandle->tempPacket->addr
                          + chanHandle->tempPacket->size))) &&
                    ((Bool) FALSE == getQueueTempStatus))
                {
                    /* Since we have already dequeue the 1st request, dequeue *
                     * 2nd io request from floating queue                     */
                    ioPacket = (MCASP_Packet *) Osal_Queue_get(
                        Osal_Queue_handle(&chanHandle->queueFloatingList));

                    /* Queue the tempPacket (i.e. 1st io request) as this pkt *
                     * should be first in a queue                             */
                    tempCastPacket = (void *) chanHandle->tempPacket;
                    Osal_Queue_put(
                        Osal_Queue_handle(&chanHandle->queueFloatingList),
                        (Osal_Queue_Elem *) tempCastPacket);

                    /* Queue the ioPacket i.e. 2nd request in floating queue  */
                    tempCastPacket = (void *) ioPacket;
                    Osal_Queue_put(Osal_Queue_handle(&chanHandle->queueFloatingList),
                              (Osal_Queue_Elem *) tempCastPacket);
                    retVal = MCASP_EBADMODE;
                }
            }
        }
        else if ((chanHandle->mode == MCASP_OUTPUT) && (MCASP_COMPLETED == retVal))
        {
            /* Check if destination address falls into the range of1st request*
             * in the floating queue.                                         */
            if ((Bool) TRUE == instHandle->isDataBufferPayloadStructure)
            {
                payLoad = (Mcasp_PktAddrPayload *) chanHandle->tempPacket->addr;
                getQueueTempStatus =
                    Osal_Queue_empty(Osal_Queue_handle(&(chanHandle->queueFloatingList)));
                if (((pramTbl.srcAddr >= (uint32_t) payLoad->addr)
                     && (pramTbl.srcAddr < ((uint32_t) payLoad->addr
                                            + chanHandle->tempPacket->size)))
                    &&
                    ((Bool) FALSE == getQueueTempStatus))
                {
                    /* Since we have already dequeue the 1st request, dequeue *
                     * 2nd io request from floating queue                     */
                    ioPacket = (MCASP_Packet *) Osal_Queue_get(
                        Osal_Queue_handle(&chanHandle->queueFloatingList));

                    /* Queue the tempPacket (i.e. 1st io request) as this     *
                     * packet should be first in a queue                      */
                    tempCastPacket = (void *) chanHandle->tempPacket;
                    Osal_Queue_put(
                        Osal_Queue_handle(&chanHandle->queueFloatingList),
                        (Osal_Queue_Elem *) tempCastPacket);

                    /* Queue the ioPacket i.e. 2nd request in floating queue  */
                    tempCastPacket = (void *) ioPacket;
                    Osal_Queue_put(Osal_Queue_handle(&chanHandle->queueFloatingList),
                              (Osal_Queue_Elem *) tempCastPacket);
                    retVal = MCASP_EBADMODE;
                }
            }
            else
            {
                getQueueTempStatus =
                    Osal_Queue_empty(Osal_Queue_handle(&(chanHandle->queueFloatingList)));
                if (((pramTbl.srcAddr >= (uint32_t) chanHandle->tempPacket->addr)
                     && (pramTbl.srcAddr <
                         ((uint32_t) chanHandle->tempPacket->addr
                          + chanHandle->tempPacket->size))) &&
                    ((Bool) FALSE == getQueueTempStatus))
                {
                    /* Since we have already dequeue the 1st request, dequeue *
                     * io request from floating queue                         */
                    ioPacket = (MCASP_Packet *) Osal_Queue_get(
                        Osal_Queue_handle(&chanHandle->queueFloatingList));

                    /* Queue the tempPacket (i.e. 1st io request) as this     *
                     * packet should be first in a queue                      */
                    tempCastPacket = (void *) chanHandle->tempPacket;
                    Osal_Queue_put(
                        Osal_Queue_handle(&chanHandle->queueFloatingList),
                        (Osal_Queue_Elem *) tempCastPacket);

                    /* Queue the ioPacket i.e. 2nd request in floating queue  */
                    tempCastPacket = (void *) ioPacket;
                    Osal_Queue_put(Osal_Queue_handle(&chanHandle->queueFloatingList),
                              (Osal_Queue_Elem *) tempCastPacket);
                    retVal = MCASP_EBADMODE;
                }
            }
        }
        else
        {
            /* MISRA COMPLIANCE */
            retVal = MCASP_EBADARGS;
        }
        if (MCASP_COMPLETED == retVal)
        {
            if (EDMA3_RM_XFER_COMPLETE != status)
            {
                /* Clear the EDMA Error bits  */
                chanHandle->tempPacket->status = MCASP_EBADIO;

                /* There is a data transfer error in EDMA transfer. Return
                 * actualSize equal to 0 represent that there is an error in the
                 * packet transfer
				 */
                chanHandle->tempPacket->size = 0;

                EDMA3_DRV_clearErrorBits(
                    chanHandle->edmaHandle,
                    chanHandle->xferChan);
            }
            else
            {
                chanHandle->tempPacket->status = MCASP_COMPLETED;
                chanHandle->tempPacket->size   = chanHandle->tempPacket->size;

                if (MCASP_COMPLETED != chanHandle->currentPacketErrorStatus)
                {
                    chanHandle->tempPacket->status =
                        (Int) chanHandle->currentPacketErrorStatus;

                    chanHandle->currentPacketErrorStatus = MCASP_COMPLETED;
                    chanHandle->tempPacket->size         = 0;
                }
            }

            chanHandle->submitCount--;

            /* If stopSmFs flag for the channel is false and pause is not issued
             * control will go in the if part. In case when stopSmFS is issued
             * or pause is issued, control will go in else part
			 */
            if ((((MCASP_INPUT == chanHandle->mode)
                  && ((Bool) FALSE == instHandle->stopSmFsRcv))
                 || ((MCASP_OUTPUT == chanHandle->mode)
                     && ((Bool) FALSE == instHandle->stopSmFsXmt)))
                && ((Bool) FALSE == chanHandle->paused))
            {
                /* Now that we have done with the last data packet - we check if
                 * next packet is available for transmission. Even if we are not
                 * having a valid packet - previous programming of linkchannels
                 * (designed in such a way) to send out null buffer Also note
                 * that Mcasp_isValidPacket function will set the
                 * chanHandle->dataPacket with next (current now) data packet
                 * from queue
                 */
                if ((int32_t) Mcasp_STATUS_VALID ==
                    Mcasp_localIsValidPacket(chanHandle))
                {
                    /* This is a valid data request. Call function to process
                     * it. If DMA cannot be programmed properly with request
                     * contents, abort all queued up requests and putstate-machine
                     * into reset */
                    if (MCASP_COMPLETED != (Mcasp_localDmaProcessPkt(
                                              chanHandle,
                                              chanHandle->dataPacket)))
                    {
                        Mcasp_localCancelAndAbortAllIo(chanHandle);
                    }
                }
                else
                {
                    /* the following function will assign loopjob buffer to free
                     * param set Also the control will come here two times for
                     * last packet and last but one packet (obviously for more
                     * than one packet xfer) For last but packet callback itself
                     * we will come to know that there is no more packet pending
                     * and hence we load loopjob info into next param set and
                     * for the last packet callback will not do it again (for only
                     * one packet scenario the following flag will take care not to
                     * update the loopjob second time)
                     */
                    if ((Bool) FALSE == chanHandle->loopjobUpdatedinParamset)
                    {
                        chanHandle->loopjobUpdatedinParamset = (Bool) TRUE;

                        Mcasp_localGetNextIndex(chanHandle);

                        Mcasp_submitPktToDma(chanHandle, NULL);
                    }
                }
            }
            else
            {
                /* Control will come over here when either of receive or
                 * transmit state machine stop command is issued for receive or transmit
                 * channel.If the nextFlag is already set indicates that its
                 * time to reset the state machines and disable the edma transfer
                 */
                if ((Bool) TRUE == chanHandle->nextFlag)
                {
                    chanHandle->nextFlag = (Bool) FALSE;

                    if ((Bool) FALSE == chanHandle->paused)
                    {
                        dlbMode  = McASPDlbRegRead(instHandle->hwInfo.regs);
                        dlbMode &= MCASP_LBCTL_DLBEN_MASK;

                        if (MCASP_LBCTL_DLBEN_ENABLE == dlbMode)
                        {
                            /* Stop both RCV and XMT state m/cs
                            * before touching McASP registers, place receive
                            * section in reset
                            */
                            retVal = Mcasp_localResetRcv(&instHandle->hwInfo);

                            if (MCASP_COMPLETED == retVal)
                            {
                                /* before touching McASP registers, place
                                 * transmit section in reset
                                 */
                                retVal = Mcasp_localResetXmt(
                                    &instHandle->hwInfo);
                            }
                        }
                        else
                        {
                            if (MCASP_INPUT == chanHandle->mode)
                            {
                                /* stop Receive state m/c 
                                 * before touching McASP registers, place
                                 * receive section in reset
								 */
                                retVal = Mcasp_localResetRcv(
                                    &instHandle->hwInfo);
                            }
                            else
                            {
                                /* stop Transmit state m/c*/
                                /* before touching McASP registers, place
                                 * transmit section in reset
                                 */
                                retVal = Mcasp_localResetXmt(
                                    &instHandle->hwInfo);
                            }
                        }
                        if (MCASP_COMPLETED == retVal)
                        {
                            EDMA3_DRV_disableTransfer(
                                chanHandle->edmaHandle,
                                chanHandle->xferChan,
                                EDMA3_DRV_TRIG_MODE_EVENT);
                        }
                    }
                }
                else
                {
                    /* For the first time when the stop port command is issued
                     * we  will have one more packet linked with the transfer
                     * channel.So we will not stop at this time. We link the packet with
                     * NULL loopjob buffer and set a nextFlag to TRUE. We will
                     * wait for another callback (indicating the io request is
                     * complete) to disable EDMA trasnfer and reset state
                     * machines*/
                    chanHandle->nextFlag = (Bool) TRUE;

                    Mcasp_localGetNextIndex(chanHandle);

                    Mcasp_submitPktToDma(chanHandle, NULL);
                }
            }
            if (MCASP_COMPLETED == retVal)
            {
                chanHandle->isTempPacketValid = (Bool) TRUE;

                Mcasp_localCompleteCurrentIo(chanHandle);
            }
        }
      }  
    } while (falsewhile);

    return;
}

#else
/**
 *  \brief   This calls the registered application callback for the current
 *           receive request and triggers the common DMA callback routine.
 *
 *  \param   tcc     [IN]    tcc number of EDMA
 *  \param   status  [IN]    status of EDMA transaction
 *  \param   data    [IN]    paramaters sent to EDMA ISR (chan handler)
 *
 *  \return  Nothing
 *
 */
void Mcasp_localEdmaCallback(uint32_t tcc, EDMA3_RM_TccStatus status, void* data)
{
    Mcasp_ChannelHandle chanHandle = NULL;
    int32_t             callbackStatus;

    if(NULL != data)
    {
      chanHandle = (Mcasp_ChannelObj *)data;

      /* update the status of the IOP */
      if (EDMA3_RM_XFER_COMPLETE != status)
      {
        callbackStatus = MCASP_EABORT;
      }
      else
      {
        callbackStatus = MCASP_COMPLETED;
      }
    }  

    Mcasp_commonDmaCallback(chanHandle, callbackStatus);
}

#endif /* #ifdef Mcasp_LOOPJOB_ENABLE */

/**
 *  \brief  This function does the following
 *          1) set up the param set of main xfer channel (for loopjob transfers)
 *          2) set up the param sets of all link channel (for loopjob transfers)
 *          3) link the last link channel to itself (this channel will be linked
 *             to  main xfer channel later and to supply the loopjob xfer
 *            information infinely this is done so; other link channels are
 *            setup here just for completion sake
 *
 *  \param  chanHandle [IN]  Handle to the mcasp channel
 *
 *  \return MCASP_COMPLETED if is success
 *          Error id if failed
 *
 */
int32_t Mcasp_setupDmaChan(Mcasp_ChannelHandle chanHandle)
{
    Mcasp_Object        *instHandle  = NULL;
    uint32_t               linkCnt     = 0;
    int32_t                status      = MCASP_COMPLETED;
    Bool                 falsewhile  = TRUE;
    EDMA3_DRV_PaRAMRegs  paramSet    = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    EDMA3_DRV_SyncType   tempSyncType;

    do
    {

     falsewhile = FALSE;

      if((NULL != chanHandle) && (NULL != chanHandle->devHandle))
      {  

        instHandle = (Mcasp_Object *)chanHandle->devHandle;

        /* Configure the McASP synchonized EDMA channel PaRAM entries         *
         * Configure source and destination address / modes first - main xfer *
         * channel                                                            */

        /* following is the explanation behind the EDMA configuration         *
         *
         *  1) We will have n arrays of data (now it is loopjob buffer each of*
         *     length x bytes)                                                *
         *  2) for each sync event we have to fetch the data from each array  *
         *     and write to each serilaiser                                   *
         *  3) and the no. bytes transferred in this case from each array will*
         *     be roundedwordwidth/8                                          *
         *  4) as the loopjob buffer is continous, we configure the counts as *
         *     follows                                                        *
         *     a) consider there are arrays of length roundedwordwidth/8(aCnt)*
         *     b) these arrays are located apart lengthofloopjob size (bindex)*
         *     c) there are 'no.of.serialiser' no. of such arrays  (bCnt)     *
         *     d) (a) and (b) constitute one frame of EDMA transfer and it    *
         *        happens for one sync event in AB sync mode                  *
         *     e) such frames have to be sent till we have buffer - ie        *
         *        lengthofloopjob / (roundedwordwidth/8 )  and this           *
         *        constitutes  cCnt                                           *
         *     f) address of buffer (rather offset from start of previous     *
         *         frame) is roundedwordwidth/8 and this forms cIndex         *
         *  Please take some time to visualise the setup mentioned above to   *
         *  check with EDMA configuration The same kind of setup will be used *
         *  for data transfers also and the change will be buffer pointer     *
         *  and length of data buffer.                                        */

        /* Get the PaRAM set for default parameters                           */
        EDMA3_DRV_getPaRAM(chanHandle->edmaHandle,chanHandle->xferChan,
                           &paramSet);

        if (MCASP_INPUT == chanHandle->mode )
        {
            /* Configuring Source and Dest addresses                          */
            paramSet.srcAddr  = (uint32_t)(instHandle->hwInfo.dataAddr);

#ifdef Mcasp_LOOPJOB_ENABLED
            paramSet.destAddr = (uint32_t) (chanHandle->loopJobBuffer);
#endif
            /* Configurign Src and Dest B&C Indexes                           */
            paramSet.srcBIdx   = 0;
            paramSet.srcCIdx   = 0;

            if (MCASP_COMPLETED != Mcasp_localGetIndicesSyncType(
                                     chanHandle,
                                     &paramSet.destBIdx,
                                     &paramSet.destCIdx,
                                     &paramSet.aCnt,
                                     &paramSet.bCnt,
                                     &paramSet.cCnt,
                                     &tempSyncType,
                                     TRUE))
            {
                status = MCASP_EBADARGS;
            }
        }
        else
        {
            /* Configuring Source and Dest addresses                          */

#ifdef Mcasp_LOOPJOB_ENABLED
            paramSet.srcAddr = (uint32_t) (chanHandle->loopJobBuffer);
#endif
            paramSet.destAddr = (uint32_t)(instHandle->hwInfo.dataAddr);

            /* Configuring dest B&C Indexes                                   */
            paramSet.destBIdx  = 0;
            paramSet.destCIdx  = 0;

            if (MCASP_COMPLETED != Mcasp_localGetIndicesSyncType(
                                     chanHandle,
                                     &paramSet.srcBIdx,
                                     &paramSet.srcCIdx,
                                     &paramSet.aCnt,
                                     &paramSet.bCnt,
                                     &paramSet.cCnt,
                                     &tempSyncType,
                                     TRUE))
            {
                status = MCASP_EBADARGS;
            }
        }

        /* Configuring bCntReload                                             */
        paramSet.bCntReload = paramSet.bCnt;

        /* Src & Dest are in INCR modes                                       */
        paramSet.opt &= 0xFFFFFFFCu;

        /* FIFO width is 8 bit                                                */
        paramSet.opt &= 0xFFFFF8FFu;

        /* Set EDMA3_DRV_OPT_FIELD_TCINTEN to FALSE                           */
        paramSet.opt |= (((uint32_t)0U) << Mcasp_OPT_TCINTEN_SHIFT);

        /* Program the TCC                                                    */
        paramSet.opt |= ((chanHandle->tcc << Mcasp_OPT_TCC_SHIFT)
                          & Mcasp_OPT_TCC_MASK);

        /* EDMA3_DRV_SYNC_AB                                                  */
        paramSet.opt &= (~((uint32_t)0x00000004u));
        paramSet.opt |= (tempSyncType << Mcasp_OPT_SYNCDIM_SHIFT);


        paramSet.opt &= (~((uint32_t)0x00000800u));
        paramSet.opt |= (((uint32_t)1U) << Mcasp_OPT_TCCMOD_SHIFT);
        
        /* reset the interrupt generation bit                                 */
        paramSet.opt &= (~0x00100000u);

        if (MCASP_COMPLETED == status)
        {
            /* Now, write the PaRAM Set.                                      */
            status = EDMA3_DRV_setPaRAM(chanHandle->edmaHandle,
                                        chanHandle->xferChan,
                                        &paramSet);
        }


        /* Configure the link PaRAMs with the appropriate parameters          *
         * Though we configure all the link paramsets, we will be using       *
         * only one of them to link with main xfer channel                    */
        for (linkCnt = 0; linkCnt < chanHandle->maxActiveSubmit; linkCnt++)
        {
            /* Get the PaRAM set for default parameters                       */
            EDMA3_DRV_getPaRAM (chanHandle->edmaHandle,
                                chanHandle->pramTbl[linkCnt],
                                &paramSet);

            if (MCASP_INPUT == chanHandle->mode)
            {
                /* Configuring Source and Dest addresses                      */

#ifdef Mcasp_LOOPJOB_ENABLED
                paramSet.srcAddr = (uint32_t) (instHandle->hwInfo.dataAddr);
#endif
                paramSet.destAddr = (uint32_t)(chanHandle->loopJobBuffer);

                /* Configurign Src and Dest B&C Indexes                       */
                paramSet.srcBIdx   = 0;
                paramSet.srcCIdx   = 0;

                if (MCASP_COMPLETED != Mcasp_localGetIndicesSyncType(
                                         chanHandle,
                                         &paramSet.destBIdx,
                                         &paramSet.destCIdx,
                                         &paramSet.aCnt,
                                         &paramSet.bCnt,
                                         &paramSet.cCnt,
                                         &tempSyncType,
                                         TRUE))
                {
                    status = MCASP_EBADARGS;
                }
            }
            else
            {
                /* Configuring Source and Dest addresses                      */

#ifdef Mcasp_LOOPJOB_ENABLED
                paramSet.srcAddr = (uint32_t) (chanHandle->loopJobBuffer);
#endif
                paramSet.destAddr = (uint32_t)(instHandle->hwInfo.dataAddr);

                paramSet.destBIdx  = 0;
                paramSet.destCIdx  = 0;

                if (MCASP_COMPLETED != Mcasp_localGetIndicesSyncType(
                                         chanHandle,
                                         &paramSet.srcBIdx,
                                         &paramSet.srcCIdx,
                                         &paramSet.aCnt,
                                         &paramSet.bCnt,
                                         &paramSet.cCnt,
                                         &tempSyncType,
                                         TRUE))
                {
                    status = MCASP_EBADARGS;
                }
            }

            /* Configuring bCntReload                                         */
            paramSet.bCntReload = paramSet.bCnt;

            /* Src & Dest are in INCR modes                                   */
            paramSet.opt &= 0xFFFFFFFCu;

            /* FIFO width is 8 bit                                            */
            paramSet.opt &= 0xFFFFF8FFu;

            /* EDMA3_DRV_SYNC_AB                                              */
            paramSet.opt &= (~((uint32_t)0x00000004u));
            paramSet.opt |= (tempSyncType << Mcasp_OPT_SYNCDIM_SHIFT);

            /* Set EDMA3_DRV_OPT_FIELD_TCINTEN to FALSE                       */
            paramSet.opt |= (((uint32_t)0U) << Mcasp_OPT_TCINTEN_SHIFT);

            /* Program the TCC                                                */
            paramSet.opt |= ((chanHandle->tcc << Mcasp_OPT_TCC_SHIFT)
                              & Mcasp_OPT_TCC_MASK);

            /* early completion interrupt                                     */
            paramSet.opt &= (~((uint32_t)0x00000800u));
            paramSet.opt |= (((uint32_t)1U) << Mcasp_OPT_TCCMOD_SHIFT);

            /* reset the interrupt generation bit                                 */
            paramSet.opt &= (~0x00100000u);

            if (MCASP_COMPLETED == status)
            {
                /* Now, write the PaRAM Set.                                  */
                status = EDMA3_DRV_setPaRAM(chanHandle->edmaHandle,
                                            chanHandle->pramTbl[linkCnt],
                                            &paramSet);
            }
#ifdef Mcasp_LOOPJOB_ENABLED
            if ((chanHandle->maxActiveSubmit - 1U) > linkCnt)
            {
                /* link with next paramset both param sets are  linked to each*
                 * other to enable continous xfer - either user audio data or *
                 * loopjob buffer MAXLINKCNT must be 2                        */
                status = EDMA3_DRV_linkChannel(
                    chanHandle->edmaHandle,
                    chanHandle->xferChan,
                    chanHandle->pramTbl[linkCnt + 1U]);

                if (MCASP_COMPLETED != status)
                {
                    status = MCASP_EBADARGS;
                }
                if (MCASP_COMPLETED == status)
                {
                    status = EDMA3_DRV_linkChannel(
                        chanHandle->edmaHandle,
                        chanHandle->pramTbl[linkCnt],
                        chanHandle->pramTbl[linkCnt + 1U]);
                }
                if (MCASP_COMPLETED != status)
                {
                    status = MCASP_EBADARGS;
                }
                if (MCASP_COMPLETED == status)
                {
                    status = EDMA3_DRV_linkChannel(
                        chanHandle->edmaHandle,
                        chanHandle->pramTbl[linkCnt + 1U],
                        chanHandle->pramTbl[linkCnt + 1U]);
                }
                if (MCASP_COMPLETED != status)
                {
                    status = MCASP_EBADARGS;
                }
                if (MCASP_COMPLETED == status)
                {
                    chanHandle->nextLinkParamSetToBeUpdated = 0;
                    chanHandle->loopjobUpdatedinParamset    = (Bool) TRUE;
                }
            }
#endif
        }/* for loop for linkcount*/
      }
      else
      {
         status = MCASP_EBADARGS;
      }  
    }while(falsewhile);

    return status;
}


/*!
 *  \brief  This function updates the link param set accordingly with data or
 *          loopjobbuffer. This uses properly maintained index to idendtify to
 *          what param set the info has to be updated.
 *
 *  \param  chanHandle  [IN]  Handle to the mcasp channel
 *  \param  ioPacket    [IN]  Pointer to I/O packet
 *
 *  \return MCASP_COMPLETED in case of sucess
 *          else Error code in case of failure
 *
 */
int32_t Mcasp_submitPktToDma(Mcasp_ChannelHandle chanHandle,
                             MCASP_Packet *const ioPacket)
{
    Mcasp_Object         *instHandle  = NULL;
    EDMA3_DRV_PaRAMRegs   pramPtr    = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Bool                  falsewhile  = TRUE;
    Mcasp_PktAddrPayload *payLoad     = NULL;
    int32_t                 status      = MCASP_COMPLETED;
    EDMA3_DRV_SyncType    syncType;

    if (NULL == ioPacket)
    {
        status = MCASP_EBADARGS;
    }
    else
    {
        do
        {
         falsewhile = FALSE;

          if((NULL != chanHandle) && (NULL != chanHandle->devHandle))
          {  

            instHandle = (Mcasp_Object *)chanHandle->devHandle;


            /* if at all this is the first packet we will update the main params  *
             * else we will update the link params                                */

#ifdef Mcasp_LOOPJOB_ENABLED
        status = EDMA3_DRV_getPaRAM(
            (EDMA3_DRV_Handle) chanHandle->edmaHandle,
            chanHandle->pramTbl[chanHandle->nextLinkParamSetToBeUpdated],
            &pramPtr);
#else
            if (1u == chanHandle->submitCount)
            {
                status = EDMA3_DRV_getPaRAM(
                             chanHandle->edmaHandle,
                             chanHandle->xferChan,
                             &pramPtr);
            }
            else
            {
                status = EDMA3_DRV_getPaRAM(
                             chanHandle->edmaHandle,
                             chanHandle->pramTbl[chanHandle->nextLinkParamSetToBeUpdated],
                             &pramPtr);
            }

#endif
            if (MCASP_COMPLETED != status )
            {
                status = MCASP_EBADARGS;
                break;
            }

            /* following is the explanation behind the EDMA configuration         *
             *
             *  1) We will have n arrays of data (now it is loopjob buffer each of*
             *     length x bytes)                                                *
             *  2) for each sync event we have to fetch the data from each array  *
             *     and write to each serilaiser                                   *
             *  3) and the no. bytes transferred in this case from each array will*
             *     be roundedwordwidth/8                                          *
             *  4) as the loopjob buffer is continous, we configure the counts as *
             *     follows                                                        *
             *     a) consider there are arrays of length roundedwordwidth/8(aCnt)*
             *     b) these arrays are located apart lengthofloopjob size (bindex)*
             *     c) there are 'no.of.serialiser' no. of such arrays  (bCnt)     *
             *     d) (a) and (b) constitute one frame of EDMA transfer and it    *
             *        happens for one sync event in AB sync mode                  *
             *     e) such frames have to be sent till we have buffer - ie        *
             *        lengthofloopjob / (roundedwordwidth/8 )  and this           *
             *        constitutes  cCnt                                           *
             *     f) address of buffer (rather offset from start of previous     *
             *         frame) is roundedwordwidth/8 and this forms cIndex         *
             *  Please take some time to visualise the setup mentioned above to   *
             *  check with EDMA configuration. Also we change only specific       *
             *  parameters because others will not have change from what we       *
             *  programed intially                                                */

            /* Load the buffer pointer into the EDMA                              */

            /* control will reach this function is two contexts                   *
             *  1) From submitreq function for first time packets                 *
             *  2) From EDMA callback for further handling of packets in Queue    *
             *  -we are from EDMA callback becuase we have completed some user    *
             *  data packet just now                                              */

        if ((NULL != ioPacket) && (MCASP_COMPLETED == status))
        {
            /* 1) when control comes to this function from submitreq control  *
             *    will surely comeinto the block                              *
             * 2) When control comes to this function from EDMA callback,     *
             *    control will some only if there is fuirther more packets to *
             *     handle                                                     */
            if (MCASP_INPUT == chanHandle->mode)
            {

#ifndef Mcasp_LOOPJOB_ENABLED
                pramPtr.srcAddr  = (uint32_t)(instHandle->hwInfo.dataAddr);

#endif
                if (TRUE == instHandle->isDataBufferPayloadStructure)
                {
                    payLoad = (Mcasp_PktAddrPayload *)ioPacket->addr;
                    if(NULL != payLoad) 
                    {
                      pramPtr.destAddr = (uint32_t)payLoad->addr;
                    } 
                    else
                    {
                      pramPtr.destAddr = (uint32_t)NULL;
                    }
                }
                else
                {
                    pramPtr.destAddr = (uint32_t)ioPacket->addr;
                }

                Mcasp_localGetIndicesSyncType(
                    chanHandle,
                    &(pramPtr.destBIdx),
                    &(pramPtr.destCIdx),
                    &(pramPtr.aCnt),
                    &(pramPtr.bCnt),
                    &(pramPtr.cCnt),
                    &syncType,
                    FALSE);
            }
            else
            {

#ifndef Mcasp_LOOPJOB_ENABLED
                pramPtr.destAddr  = (uint32_t)(instHandle->hwInfo.dataAddr);

#endif
                if (TRUE == chanHandle->bMuteON)
                {
                    /* data buffer is changed to local mutebuffer             */
                    pramPtr.srcAddr  =
                        (uint32_t)&Mcasp_muteBuf[(instHandle->instNum)].scratchBuffer;

                    /* calculation is similar to the loop job buffer          */
                    Mcasp_localGetIndicesSyncType(
                        chanHandle,
                        &(pramPtr.srcBIdx),
                        &(pramPtr.srcCIdx),
                        &(pramPtr.aCnt),
                        &(pramPtr.bCnt),
                        &(pramPtr.cCnt),
                        &syncType,
                        TRUE);
                }
                else
                {
                    if (TRUE == instHandle->isDataBufferPayloadStructure)
                    {
                        payLoad = (Mcasp_PktAddrPayload *)ioPacket->addr;
                        pramPtr.srcAddr = (uint32_t)payLoad->addr;
                    }
                    else
                    {
                        pramPtr.srcAddr = (uint32_t)ioPacket->addr;
                    }

                    Mcasp_localGetIndicesSyncType(
                        chanHandle,
                        &(pramPtr.srcBIdx),
                        &(pramPtr.srcCIdx),
                        &(pramPtr.aCnt),
                        &(pramPtr.bCnt),
                        &(pramPtr.cCnt),
                        &syncType,
                        FALSE);
                }/*for mute on/off*/
            }

            /* Here we are enabling the interrupt for this param set info     *
             * we do it here in this way because using int enable API after   *
             * calling EDMA3_DRV_setPaRAM, may fail our intention. This is    *
             * because immediately after the set param the paramset might be  *
             * copied to linked param and will make the consecutive int enable*
             * (set opt field) api useless for our purpose                    */

            pramPtr.opt |= (((uint32_t)0x01u)<<20u);


#ifdef Mcasp_LOOPJOB_ENABLED
            /* we are loading data request in the param set. As per our design*
             * when we load the data,  we should link this param set with next*
             * one most probably                                              *
             *  a)That may have loopjob loaded                                *
             *  b)it may be the currently loaded set, which will be updated in*
             *    next edma callback                                          *
             * hence in both cases to be run next to this data request        */
            pramPtr.linkAddr =
                (uint16_t) (chanHandle->pramTblAddr[ \
                              ((chanHandle->nextLinkParamSetToBeUpdated +
                                1U) & 0x01U)] & 0x0000FFFFU);
#else
            /* set the link address as 0xFFFF                                 */
            pramPtr.linkAddr = 0xFFFFu;
#endif
        }
#ifdef Mcasp_LOOPJOB_ENABLED
        else if (MCASP_COMPLETED == status)
        {
            /* we have reached here becuase we dont have any more packett to  *
             * submit for Xfer assign loop job to params- no change in linking*
             * IMP: The following assignment will be skipped if already both  *
             * params are having loopjob buffer                               */
            if (MCASP_INPUT == chanHandle->mode)
            {
                pramPtr.destAddr = (uint32_t) chanHandle->loopJobBuffer;
                Mcasp_localGetIndicesSyncType(
                    chanHandle,
                    &(pramPtr.destBIdx),
                    &(pramPtr.destCIdx),
                    &(pramPtr.aCnt),
                    &(pramPtr.bCnt),
                    &(pramPtr.cCnt),
                    &syncType,
                    (Bool) TRUE);
            }
            else
            {
                pramPtr.srcAddr = (uint32_t) chanHandle->loopJobBuffer;
                Mcasp_localGetIndicesSyncType(
                    chanHandle,
                    &(pramPtr.srcBIdx),
                    &(pramPtr.srcCIdx),
                    &(pramPtr.aCnt),
                    &(pramPtr.bCnt),
                    &(pramPtr.cCnt),
                    &syncType,
                    (Bool) TRUE);
            }

            /* we are loading loopjob into this param.  That means we have    *
             * reached the end of packets in pending and floating queues. So  *
             * this loopjob had to be  linked to itself.Also we need to point *
             * the index to other param set in order to load data request     *
             * directly from submit call                                      */
            pramPtr.linkAddr =
                (uint16_t) (chanHandle->pramTblAddr[ \
                              chanHandle->nextLinkParamSetToBeUpdated] &
                          0x0000FFFFU);

            pramPtr.opt &= (~((uint32_t) 0x01U << 20U));
        }
        else
        {
            /* MISRA COMPLIANCE */
            status = MCASP_EBADARGS;
        }
#else
        else
        {
            status = MCASP_EBADARGS;
        }
#endif

        if (MCASP_COMPLETED == status)
        {
#ifdef Mcasp_LOOPJOB_ENABLED

            /* Update the changed param set info into the appropriate paramset
             *   */
            status = EDMA3_DRV_setPaRAM(
                (EDMA3_DRV_Handle) chanHandle->edmaHandle,
                chanHandle->pramTbl[chanHandle->nextLinkParamSetToBeUpdated],
                &pramPtr);
        }
#else
            if (1u == chanHandle->submitCount)
            {
                /* Configuring bCntReload                                         */
                pramPtr.bCntReload = pramPtr.bCnt;

                /* Src & Dest are in INCR modes                                   */
                pramPtr.opt &= 0xFFFFFFFCu;

                /* FIFO width is 8 bit                                            */
                pramPtr.opt &= 0xFFFFF8FFu;

                /* Set EDMA3_DRV_OPT_FIELD_TCINTEN to TRUE                        */
                pramPtr.opt |= (((uint32_t)1U) << Mcasp_OPT_TCINTEN_SHIFT);

                /* Program the TCC                                                */
                pramPtr.opt |= ((chanHandle->tcc << Mcasp_OPT_TCC_SHIFT)
                                  & Mcasp_OPT_TCC_MASK);

                /* EDMA3_DRV_SYNC_AB                                              */
                pramPtr.opt &= (~((uint32_t)0x00000004u));
                pramPtr.opt |= (syncType << Mcasp_OPT_SYNCDIM_SHIFT);

                /* set the link address as 0xFFFF                                 */
                pramPtr.linkAddr = 0xFFFFu;

                status = EDMA3_DRV_setPaRAM(
                            chanHandle->edmaHandle,
                            chanHandle->xferChan,
                            &pramPtr);
            }
            else
            {
                status = EDMA3_DRV_setPaRAM(
                             chanHandle->edmaHandle,
                             chanHandle->pramTbl[chanHandle->
                              nextLinkParamSetToBeUpdated],
                             &pramPtr);
            }

            if (MCASP_COMPLETED != status)
            {
                status = MCASP_EBADARGS;
            }
        }

        if ((2u == chanHandle->submitCount) && (MCASP_COMPLETED == status))
        {
            /* link this paramset with the main channel                       */
            status = EDMA3_DRV_linkChannel(
                        chanHandle->edmaHandle,
                        chanHandle->xferChan,
                        chanHandle->pramTbl \
                        [chanHandle->nextLinkParamSetToBeUpdated]);

            if (MCASP_COMPLETED != status)
            {
                status = MCASP_EBADIO;
            }
        }

        /* link this paramset with the other paramset                         */
        if ((3u == chanHandle->submitCount) && (MCASP_COMPLETED == status))
        {
            status = EDMA3_DRV_linkChannel(
                        chanHandle->edmaHandle,
                        chanHandle->pramTbl[
                            (chanHandle->nextLinkParamSetToBeUpdated + 1u) & 0x01u],
                        chanHandle->pramTbl \
                        [chanHandle->nextLinkParamSetToBeUpdated]);

            if (MCASP_COMPLETED != status)
            {
                status = MCASP_EBADIO;
            }
        }
#endif
        if (MCASP_COMPLETED != status)
        {
            status = MCASP_EBADARGS;
        }

#ifdef Mcasp_LOOPJOB_ENABLED
        if ((NULL == ioPacket) && (MCASP_COMPLETED == status))
        {
            /* we are loading loopjob into this param. we need to point the   *
             * index to other param set in order to load data request directly*
             * from submit call                                               */
            Mcasp_localGetNextIndex(chanHandle);
        }
#endif
       } 
       else
       {
          status = MCASP_EBADARGS;
       }
      }while(falsewhile);
    }
    return status;
}

/**
 *  \brief  Mcasp_localGetIndicesSyncType
 *
 *  This function computes the parameters requied to configure EDMA 3 based
 *  on the buffer format seleted while creating the driver.
 *
 *  Entry Criteria : This function expects channel variables such as no of slots
 *                     serializers, length of buffers is updated.
 *
 *  \param    chanHandle       [IN]    Pointer to channel handle
 *  \param    bIndex           [IN]    Pointer to stores computed bIndex
 *  \param    cIndex           [IN]    Pointer to stores computed cIndex
 *  \param    aCnt             [IN]    Pointer to stores computed aCnt
 *  \param    bCnt             [IN]    Pointer to stores computed bCnt
 *  \param    cCnt             [IN]    Pointer to stores computed cCnt
 *  \param    syncType         [IN]    Pointer to stores computed mode of EDMA
 *  \param    forLoopJobBuf    [IN]    To calucalate above for loopJob or data
 *
 * CAUTION : This function could be called with pointer pointing to EDMA 3
 *           paramset pointer (avoiding couple of variables). Care should be
 *           take to ensure that data types used in EDMA 3 paramset is
 *           consistent with EDMA 3 defined data types.
 *
 *  \return  MCASP_EBADARGS on invalid buffer format, else MCASP_COMPLETED
 */
int32_t Mcasp_localGetIndicesSyncType(Mcasp_ChannelHandle chanHandle,
                                    volatile int16_t     *bIndex,
                                    volatile int16_t     *cIndex,
                                    volatile uint16_t    *aCnt,
                                    volatile uint16_t    *bCnt,
                                    volatile uint16_t    *cCnt,
                                    EDMA3_DRV_SyncType *syncType,
                                    Bool                forLoopJobBuf)
{
    uint32_t  tempSize  = 0x0;
    int32_t   status    = MCASP_COMPLETED;
    Uint16    temp_var  = 0x0U;
    Uint16    aCntByBCnt = 0x0U;

    if(((NULL != chanHandle) && (NULL != bIndex) && (NULL != cIndex)
                    && (NULL != aCnt) && (NULL != bCnt) && (NULL != cCnt)
                    && (NULL != syncType)))
    {                


#ifdef Mcasp_LOOPJOB_ENABLED
    /* Get the size of the buffer to be used. In case of mute command and     *
     * normal IOP we will use the actual size of the buffer. For the loop job *
     * case 1. if internal loop job then the minimum loop job length will be  *
     *         used.                                                          *
     * case 2. user supplied loop job buffer then the user loop job length    *
     *         will be used.                                                  */
    if (((Bool) TRUE == forLoopJobBuf) && ((Bool) FALSE == chanHandle->bMuteON))
    {
        if ((Bool) TRUE == chanHandle->userLoopJob)
        {
            /* use the user supplied buffer length for the EDMA params        */
            tempSize = chanHandle->userLoopJobLength;
        }
        else
        {
            tempSize = chanHandle->loopJobLength;
        }
    }
    else
    {
    tempSize = chanHandle->userDataBufferSize;

    }
#else
    tempSize = chanHandle->userDataBufferSize;
#endif

    /* Get the indices                                                        */
    switch (chanHandle->dataFormat)
    {
        case Mcasp_BufferFormat_1SER_1SLOT:
        case Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED:
            *aCnt = chanHandle->roundedWordWidth;
            *bCnt = chanHandle->noOfSerAllocated*chanHandle->hwFifoEventDMARatio;
            *cCnt = (uint16_t)(tempSize/((*aCnt)*(*bCnt)));
            *bIndex = (int16_t)*aCnt;
            *cIndex = (int16_t)(*aCnt)*(*bCnt);
            *syncType = EDMA3_DRV_SYNC_AB;
            break;
        case Mcasp_BufferFormat_MULTISER_1SLOT_SER_NON_INTERLEAVED:
            *aCnt = chanHandle->roundedWordWidth;
            *bCnt = chanHandle->noOfSerAllocated*chanHandle->hwFifoEventDMARatio;
            /* temp Size is always a multiple of the acnt hence the division  *
             * result will always be an integer                               */
            aCntByBCnt = ((*aCnt)*(*bCnt));
            *cCnt = (Uint16)(tempSize/ (uint32_t)aCntByBCnt);
            /* temp Size is always a multiple of the bcnt when using the      *
             * multiple serializers hence the reuslt will be always an integer*/
            temp_var = (((uint16_t)(tempSize))/(*bCnt));
            *bIndex = (int16_t)(temp_var);
            *cIndex = (int16_t)(*aCnt);
            *syncType = EDMA3_DRV_SYNC_AB;
            break;
        case Mcasp_BufferFormat_1SER_MULTISLOT_NON_INTERLEAVED:
            *aCnt = chanHandle->roundedWordWidth;
            *bCnt = chanHandle->noOfSlots*chanHandle->hwFifoEventDMARatio;
            /* temp Size is always a multiple of the acnt hence the division  *
             * result will always be an integer                               */
            aCntByBCnt = ((*aCnt) * (*bCnt));
            *cCnt = (Uint16)(tempSize / (uint32_t)aCntByBCnt);
            /* temp Size is always a multiple of the bcnt when using the      *
             * multiple slots hence the result will be always an integer      */
            temp_var = (((uint16_t)(tempSize))/(*bCnt));
            *bIndex = (int16_t)(temp_var);
            temp_var = ((*aCnt) - (((*bCnt)- ((uint16_t)1u)) * (((uint16_t)(tempSize))/(*bCnt))));
            *cIndex = (int16_t)(temp_var);
            *syncType = EDMA3_DRV_SYNC_A;
            break;
        case Mcasp_BufferFormat_MULTISER_1SLOT_SER_INTERLEAVED:
            *aCnt = (chanHandle->roundedWordWidth);
            *bCnt = chanHandle->noOfSerAllocated*chanHandle->hwFifoEventDMARatio;
            /* temp Size is always a multiple of the bcnt when using the      *
             * multiple serializers hence the result will be always an integer*/
            aCntByBCnt = ((*aCnt) * (*bCnt));
            *cCnt = (Uint16)(tempSize / (uint32_t)aCntByBCnt);
            temp_var = ((*aCnt) * (*bCnt));
            *cIndex = (int16_t)(temp_var);
            *syncType = EDMA3_DRV_SYNC_AB;
            break;
        case Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1:
            *aCnt =  chanHandle->roundedWordWidth;
            *bCnt =  chanHandle->noOfSerAllocated*chanHandle->hwFifoEventDMARatio;
            /* temp Size is always a multiple of the bcnt when using the      *
             * multiple serializers hence the result will be always an integer*/
            aCntByBCnt = ((*aCnt) * (*bCnt));
            *cCnt =  (Uint16)(tempSize/ (uint32_t)aCntByBCnt);
            *bIndex   = (int16_t)(*aCnt);
            temp_var = ((*aCnt) * (*bCnt));
            *cIndex = (int16_t)(temp_var);
            *syncType = EDMA3_DRV_SYNC_AB;
            break;
        case Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2:
            *aCnt = chanHandle->roundedWordWidth;
            *bCnt = chanHandle->noOfSerAllocated*chanHandle->hwFifoEventDMARatio;
            /* temp Size is always a multiple of the acnt hence the division  *
             * result will always be an integer                               */
            aCntByBCnt = ((*aCnt) * (*bCnt));
            *cCnt  = (Uint16)(tempSize/ (uint32_t)aCntByBCnt);
            /* temp Size is always a multiple of the bcnt when using the      *
             * multiple serializers hence the result will be always an integer*/
            temp_var = (((uint16_t)(tempSize))/(*bCnt));
            *bIndex = (int16_t)(temp_var);
            *cIndex = (int16_t)(*aCnt);
            *syncType = EDMA3_DRV_SYNC_AB;
            break;
#if 0
        /* we are unable to support this buffer format because the MCASP gives *
         * tx underrun error.
         * When 2 serializers are configured in 2 slot mode each. The MCASP   *
         * even though it receives two 16 bit samples it considers it as only *
         * one 32 bit sample because of which it will always give an underrun *
         * error. Hence this buffer format cannot be supported                */
        case Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_3:
            *aCnt = ((chanHandle->roundedWordWidth) * chanHandle->noOfSerAllocated);
            *bCnt = chanHandle->noOfSlots;
            *cCnt = (tempSize / ((*aCnt) *(*bCnt)));
            *bIndex = (tempSize/(*bCnt));
            *cIndex = ((*aCnt) - (((*bCnt) - 1) * (tempSize/(*bCnt))));
            *syncType = EDMA3_DRV_SYNC_A;
            break;
#endif
        default:
            status = MCASP_EBADARGS;
               break;
    }

    /* if the loop job buffer being used is the driver internal loop job      *
     * buffer, dont increment the index for it.Same is the case if mute is ON */
    if (TRUE == forLoopJobBuf)
    {
        if ((TRUE == chanHandle->bMuteON) ||
            (FALSE == chanHandle->userLoopJob))
        {
            *bIndex = 0;
            *cIndex = 0;
        }
    }
  }
  else
  {
	  status = MCASP_EBADARGS;
  }  
   return status;
}

void Mcasp_initChanDmaObj(Mcasp_ChannelHandle chanHandle)
{
    Mcasp_Object         *instHandle;

    instHandle = (Mcasp_Object *)chanHandle->devHandle;

    /* EDMA handle should be provided by the HW info.  However, legacy
     * implementation will allow for this to be provided via the channel
     * parameters.
     */
    chanHandle->edmaHandle = instHandle->hwInfo.dmaHandle;

    /* Fixed number of EDMA PaRAM sets allocated for channel linking */
    chanHandle->maxActiveSubmit = Mcasp_MAXLINKCNT;
    chanHandle->xferChan = 0;
    chanHandle->tcc = 0;
    chanHandle->pramTbl[0] = 0;
    chanHandle->pramTbl[1] = 0;
    chanHandle->pramTblAddr[0] = 0;
    chanHandle->pramTblAddr[1] = 0;
    chanHandle->nextLinkParamSetToBeUpdated = 0;
    chanHandle->edmaCallback = NULL;
}

int32_t Mcasp_enableDMA(Mcasp_ChannelHandle chanHandle)
{
    int32_t status;

    /* Starting DMA transfer fresh, so resetting the PaRAM set index */
    chanHandle->nextLinkParamSetToBeUpdated = 0;

    /* Enable the EDMA transfer with EVENT triggering */
    status = EDMA3_DRV_enableTransfer(chanHandle->edmaHandle,
                                      chanHandle->xferChan,
                                      EDMA3_DRV_TRIG_MODE_EVENT);

    return status;
}

int32_t Mcasp_disableDMA(Mcasp_ChannelHandle chanHandle)
{
    int32_t status = 0;

    status = EDMA3_DRV_disableTransfer(chanHandle->edmaHandle,
                                       chanHandle->xferChan,
                                       EDMA3_DRV_TRIG_MODE_EVENT);

    return status;
}

int32_t Mcasp_freeDmaChannel(Mcasp_ChannelHandle chanHandle)
{
    uint8_t linkCnt = 0;
    int32_t status;

    /* Free the main EDMA channel */
    status = EDMA3_DRV_freeChannel(chanHandle->edmaHandle,
                                   chanHandle->xferChan);

    /* free the EDMA PaRAM entries used for Pingpong buffering        */
    for (linkCnt = 0; linkCnt <chanHandle->maxActiveSubmit; linkCnt++)
    {
        status = EDMA3_DRV_freeChannel(chanHandle->edmaHandle,
                                       chanHandle->pramTbl[linkCnt]);
    }

    return status;
}

void Mcasp_getDmaPosition(Mcasp_ChannelHandle chanHandle, uint32_t *dmaPosition)
{
    uint32_t localbCnt = 0;
    uint32_t localcCnt = 0;

    EDMA3_DRV_getPaRAMField(chanHandle->edmaHandle,
                            chanHandle->xferChan,
                            EDMA3_DRV_PARAM_FIELD_CCNT,
                            &localcCnt);

    EDMA3_DRV_getPaRAMField(chanHandle->edmaHandle,
                            chanHandle->xferChan,
                            EDMA3_DRV_PARAM_FIELD_BCNT,
                            &localbCnt);

    *dmaPosition = localcCnt * chanHandle->roundedWordWidth * localbCnt;
}

void Mcasp_clearDmaErrors(Mcasp_ChannelHandle chanHandle)
{
    EDMA3_DRV_clearErrorBits(chanHandle->edmaHandle,
                             chanHandle->xferChan);


}

void Mcasp_initiateDummyDMAXfer(Mcasp_ChannelHandle chanHandle)
{
    EDMA3_DRV_PaRAMRegs pramTbl    = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    /* Initiate dummy transfer (or reduce the c-count to 1) in    *
     * EDMA-current transfer channel param This would load the    *
     * next link paramset and give a edma callback where we       *
     * do futher steps needed to close the current packet and     *
     * load next pending packet etc                               */

    /* get the param table information of transfer channel        */
    EDMA3_DRV_getPaRAM(
        chanHandle->edmaHandle,
        chanHandle->xferChan,
        &pramTbl);

    if (0 != pramTbl.cCnt)
    {
        pramTbl.cCnt = 0;

        EDMA3_DRV_setPaRAM(
            chanHandle->edmaHandle,
            chanHandle->xferChan,
            &pramTbl);
    }

}

void Mcasp_triggerDMA(Mcasp_ChannelHandle chanHandle)
{
    EDMA3_DRV_enableTransfer((EDMA3_DRV_Handle) chanHandle->edmaHandle,
                             chanHandle->xferChan,
                             EDMA3_DRV_TRIG_MODE_MANUAL);
}
/* ========================================================================== */
/*                             END OF FILE                                    */
/* ========================================================================== */
