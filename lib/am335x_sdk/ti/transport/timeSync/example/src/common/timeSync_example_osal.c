
/******************************************************************************
 * FILE PURPOSE:  OSAL functions to timeSync module
 *
 ******************************************************************************
 * FILE NAME:   timeSYnc_example_osal.c
 *
 * DESCRIPTION: This file contains NDK device config functions.
 *
 * (C) Copyright 2018 Texas Instruments, Inc.
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



/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <xdc/std.h>
#include <ti/transport/timeSync/include/icss_timeSync_osal.h>
#include <ti/drv/icss_emac/firmware/icss_dualemac/src/icss_timeSync_memory_map.h>
#include <ti/transport/timeSync/include/icss_timeSync_tools.h>
#include <src/example.h>

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int8_t TimeSync_isrAndTaskInit(TimeSync_ParamsHandle_t timeSyncHandle)
{

    OsalRegisterIntrParams_t intrInitParams;
    OsalInterruptRetCode_e   regIntrRetCode;
    HwiP_Handle              *pHwiHandle = (HwiP_Handle *) &timeSyncHandle->timeSync_HwiHandle;
    TimerP_Params timerParams;
    TaskP_Params taskParams;
    SemaphoreP_Params semaphoreParams;
    EventP_Params eventParams;


    uint8_t portNum = 0;

    /*-----------Create Interrupts------------*/

    /*Setup Tx callback interrupt*/
    Osal_RegisterInterrupt_initParams(&intrInitParams);
    intrInitParams.corepacConfig.priority = PTP_TX_CALLBACK_HWI_PRIORITY;
    intrInitParams.corepacConfig.arg = (xdc_UArg)timeSyncHandle;
    intrInitParams.corepacConfig.isrRoutine = TimeSync_txTSIsr;
    intrInitParams.corepacConfig.corepacEventNum = timeSyncHandle->timeSyncConfig.txIntNum;

#ifdef _TMS320C6X
    intrInitParams.corepacConfig.intVecNum = OSAL_REGINT_INTVEC_EVENT_COMBINER;
#else
    intrInitParams.corepacConfig.intVecNum = intrInitParams.corepacConfig.corepacEventNum;
#endif


#if defined (__ARM_ARCH_7A__)
    intrInitParams.corepacConfig.triggerSensitivity = OSAL_ARM_GIC_TRIG_TYPE_LEVEL;
#endif

    regIntrRetCode = Osal_RegisterInterrupt(&intrInitParams, pHwiHandle);

    if(regIntrRetCode != OSAL_INT_SUCCESS)
    {
        return TIME_SYNC_UNABLE_TO_CREATE_INTERRUPT;
    }

    /*Enable interrupt*/
    Osal_EnableInterrupt(intrInitParams.corepacConfig.corepacEventNum, intrInitParams.corepacConfig.intVecNum);

    if(timeSyncHandle->timeSyncConfig.process_TOD_and_sync_2_1PPS)
    {
        /*Setup latch0 interrupt*/
        Osal_RegisterInterrupt_initParams(&intrInitParams);
        intrInitParams.corepacConfig.priority = PTP_LATCH0_HWI_PRIORITY;
        intrInitParams.corepacConfig.arg = (xdc_UArg)timeSyncHandle;
        intrInitParams.corepacConfig.isrRoutine = TimeSync_latchIsr;
        intrInitParams.corepacConfig.corepacEventNum = timeSyncHandle->timeSyncConfig.latchIntNum;

#ifdef _TMS320C6X
        intrInitParams.corepacConfig.intVecNum = OSAL_REGINT_INTVEC_EVENT_COMBINER;
#else
        intrInitParams.corepacConfig.intVecNum = intrInitParams.corepacConfig.corepacEventNum;
#endif

#if defined (__ARM_ARCH_7A__)
        intrInitParams.corepacConfig.triggerSensitivity = OSAL_ARM_GIC_TRIG_TYPE_LEVEL;
#endif

        regIntrRetCode = Osal_RegisterInterrupt(&intrInitParams, pHwiHandle);

        if(regIntrRetCode != OSAL_INT_SUCCESS)
        {
            return TIME_SYNC_UNABLE_TO_CREATE_INTERRUPT;
        }

        /*Enable interrupt*/
        Osal_EnableInterrupt(intrInitParams.corepacConfig.corepacEventNum, intrInitParams.corepacConfig.intVecNum);
    }

    /*---------------DM Timer setup---------------------*/
    TimerP_Params_init(&timerParams);

    timerParams.period = timeSyncHandle->timeSyncConfig.syncSendInterval;
    timerParams.periodType = TimerP_PeriodType_MICROSECS;
    timerParams.arg = (void *)timeSyncHandle;
    /*24 Mhz, care must be taken to ensure that this values
     * is modified if the source clock frequency is modified */
    //timerParams.extfreqLo = DMTIMER_SRC_CLK_FREQ;
    //timerParams.extfreqHi = 0;
    timerParams.startMode = TimerP_StartMode_USER;
    timerParams.runMode = TimerP_RunMode_CONTINUOUS;

    timeSyncHandle->timeSync_syncTxTimer = TimerP_create(TIMESYNC_APP_TIMER_ID,
                                           (TimerP_Fxn)TimeSync_syncTxIsr,
                                           &timerParams);

    if(timeSyncHandle->timeSync_syncTxTimer == NULL)
    {
        return TIME_SYNC_UNABLE_TO_CREATE_CLOCK;
    }

    /*Create semaphore for sending Sync frames*/
    SemaphoreP_Params_init(&semaphoreParams);
    semaphoreParams.mode = SemaphoreP_Mode_BINARY;
    timeSyncHandle->syncTxSemHandle = SemaphoreP_create(0, &semaphoreParams);

    if(timeSyncHandle->syncTxSemHandle == NULL)
    {
        return TIME_SYNC_UNABLE_TO_CREATE_SEMAPHORE;
    }

    if(timeSyncHandle->timeSyncConfig.process_TOD_and_sync_2_1PPS)
    {
        /*Create semaphore which is posted by latch ISR which in turn triggers the task used to synchronize the clock*/
        SemaphoreP_Params_init(&semaphoreParams);
        semaphoreParams.mode = SemaphoreP_Mode_BINARY;
        timeSyncHandle->latch_sync_SemHandle = SemaphoreP_create(0, &semaphoreParams);

        if(timeSyncHandle->latch_sync_SemHandle == NULL)
        {
            return TIME_SYNC_UNABLE_TO_CREATE_SEMAPHORE;
        }
    }


    if(timeSyncHandle->timeSyncConfig.type == E2E)
    {
        /*Create semaphore for sending delay request frames*/
        SemaphoreP_Params_init(&semaphoreParams);
        semaphoreParams.mode = SemaphoreP_Mode_BINARY;
        timeSyncHandle->delayReqTxSemHandle = SemaphoreP_create(0, &semaphoreParams);

        if(timeSyncHandle->delayReqTxSemHandle == NULL)
        {
            return TIME_SYNC_UNABLE_TO_CREATE_SEMAPHORE;
        }
    }

    /*Assign event ID's*/
    timeSyncHandle->eventIdSync = EventP_ID_02;
    timeSyncHandle->eventIdPdelayReq = EventP_ID_03;
    timeSyncHandle->eventIdPdelayResp = EventP_ID_04;
    timeSyncHandle->eventIdPdelayRespFlwUp = EventP_ID_05;
    timeSyncHandle->eventIdDelayReq = EventP_ID_06;
    timeSyncHandle->eventIdFlwUpGenerated = EventP_ID_07;

    for(portNum = 0; portNum < NUM_PORTS; portNum++)
    {
        timeSyncHandle->ptpPdelayResEvtHandle[portNum] = EventP_create(&eventParams);

        if(timeSyncHandle->ptpPdelayResEvtHandle[portNum] == NULL)
        {
            return TIME_SYNC_UNABLE_TO_CREATE_EVENT;
        }
    }

    for(portNum = 0; portNum < NUM_PORTS; portNum++)
    {
        timeSyncHandle->txTSAvailableEvtHandle[portNum] = EventP_create(&eventParams);

        if(timeSyncHandle->txTSAvailableEvtHandle[portNum] == NULL)
        {
            return TIME_SYNC_UNABLE_TO_CREATE_EVENT;
        }
    }

    for(portNum = 0; portNum < NUM_PORTS; portNum++)
    {
        timeSyncHandle->ptpPdelayReqEvtHandle[portNum] = EventP_create(&eventParams);

        if(timeSyncHandle->ptpPdelayReqEvtHandle[portNum] == NULL)
        {
            return TIME_SYNC_UNABLE_TO_CREATE_EVENT;
        }
    }

    for(portNum = 0; portNum < NUM_PORTS; portNum++)
    {
        timeSyncHandle->ptpSendFollowUpEvtHandle[portNum] = EventP_create(&eventParams);

        if(timeSyncHandle->ptpSendFollowUpEvtHandle[portNum] == NULL)
        {
            return TIME_SYNC_UNABLE_TO_CREATE_EVENT;
        }
    }

    /*-----------Create Tasks------------*/

    if(timeSyncHandle->timeSyncConfig.type == P2P)
    {
        TaskP_Params_init(&taskParams);
        taskParams.priority = PTP_DELAY_REQ_SEND_TASK_PRIORITY;
        taskParams.arg0 = (void *)timeSyncHandle;
        timeSyncHandle->timeSync_pDelayReqSendTask = TaskP_create(
                    TimeSync_PdelayReqSendTask,
                    &taskParams);

        if(timeSyncHandle->timeSync_pDelayReqSendTask  == NULL)
        {
            return TIME_SYNC_UNABLE_TO_CREATE_TASK;
        }
    }

    if(timeSyncHandle->timeSyncConfig.type == E2E)
    {
        TaskP_Params_init(&taskParams);
        taskParams.priority = PTP_DELAY_REQ_SEND_TASK_PRIORITY;
        taskParams.arg0 = (void *)timeSyncHandle;
        timeSyncHandle->timeSync_delayReqSendTask = TaskP_create(
                    TimeSync_delayReqSendTask,
                    &taskParams);

        if(timeSyncHandle->timeSync_delayReqSendTask  == NULL)
        {
            return TIME_SYNC_UNABLE_TO_CREATE_TASK;
        }
    }

    TaskP_Params_init(&taskParams);
    taskParams.priority = PTP_TX_TS_TASK_PRIORITY;
    taskParams.arg0 = (void *)timeSyncHandle;
    timeSyncHandle->timeSync_TxTSTaskP1 = TaskP_create(TimeSync_TxTSTask_P1,
                                          &taskParams);

    if(timeSyncHandle->timeSync_TxTSTaskP1  == NULL)
    {
        return TIME_SYNC_UNABLE_TO_CREATE_TASK;
    }

    TaskP_Params_init(&taskParams);
    taskParams.priority = PTP_TX_TS_TASK_PRIORITY;
    taskParams.arg0 = (void *)timeSyncHandle;
    timeSyncHandle->timeSync_TxTSTaskP2 = TaskP_create(TimeSync_TxTSTask_P2,
                                          &taskParams);

    if(timeSyncHandle->timeSync_TxTSTaskP2  == NULL)
    {
        return TIME_SYNC_UNABLE_TO_CREATE_TASK;
    }

    /* Sync Tx Task*/
    TaskP_Params_init(&taskParams);
    taskParams.priority = PTP_SYNC_TASK_PRIORITY;
    taskParams.arg0 = (void *)timeSyncHandle;
    timeSyncHandle->timeSync_syncTxTask = TaskP_create(TimeSync_SyncTxTask,
                                          &taskParams);

    if(timeSyncHandle->timeSync_syncTxTask  == NULL)
    {
        return TIME_SYNC_UNABLE_TO_CREATE_TASK;
    }

    /* Announce Tx Task*/
    TaskP_Params_init(&taskParams);
    taskParams.priority = PTP_ANNOUNCE_TASK_PRIORITY;
    taskParams.arg0 = (void *)timeSyncHandle;
    timeSyncHandle->timeSync_announceTxTask = TaskP_create(TimeSync_AnnounceTxTask,
            &taskParams);

    if(timeSyncHandle->timeSync_announceTxTask  == NULL)
    {
        return TIME_SYNC_UNABLE_TO_CREATE_TASK;
    }

    /* NRT Task to process peer delay frames*/
    TaskP_Params_init(&taskParams);
    taskParams.priority = 8;
    taskParams.arg0 = (void *)timeSyncHandle;
    timeSyncHandle->timeSync_NRT_Task = TaskP_create(TimeSync_NRT_Task,
                                        &taskParams);

    if(timeSyncHandle->timeSync_NRT_Task  == NULL)
    {
        return TIME_SYNC_UNABLE_TO_CREATE_TASK;
    }

    /* Background Task to do computation*/
    TaskP_Params_init(&taskParams);
    taskParams.priority = 7;
    taskParams.arg0 = (void *)timeSyncHandle;
    timeSyncHandle->timeSync_backgroundTask = TaskP_create(TimeSync_BackgroundTask,
            &taskParams);

    if(timeSyncHandle->timeSync_backgroundTask  == NULL)
    {
        return TIME_SYNC_UNABLE_TO_CREATE_TASK;
    }

    if(timeSyncHandle->timeSyncConfig.process_TOD_and_sync_2_1PPS)
    {
        /* Task where local clock is synchronized to latch0 timestamp*/
        TaskP_Params_init(&taskParams);
        taskParams.priority = 6;
        taskParams.arg0 = (void *)timeSyncHandle;
        timeSyncHandle->timeSync_latchSyncTask = TaskP_create(TimeSync_latchSyncTask,
                &taskParams);

        if(timeSyncHandle->timeSync_latchSyncTask  == NULL)
        {
            return TIME_SYNC_UNABLE_TO_CREATE_TASK;
        }
    }


    return TIME_SYNC_OK;

}

/* ========================================================================== */
/*                           Task Definitions                                 */
/* ========================================================================== */

void TimeSync_PdelayReqSendTask(UArg a0, UArg a1)
{
    uint8_t linkStatus = 0;
    uint8_t frameCount = 0;
    ICSS_EmacTxArgument txArg;
    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)a0;
    uint8_t offset = timeSyncHandle->timeSyncConfig.frame_offset;
    uint32_t port, quePri, index;

    /* Get the queue priority */
    if (TIMESYNC_TEST_PORT_NUM == 0)
    {
        port   = ICSS_EMAC_PORT_1;
        quePri = ICSS_EMAC_QUEUE1;
        index  = 0;
    }
    else
    {
        port   = ICSS_EMAC_PORT_2;
        quePri = ICSS_EMAC_QUEUE3;
        index  = 1;
    }
    while(1)
    {
        if(P2P == timeSyncHandle->timeSyncConfig.type)
        {

            if(timeSyncHandle->enabled == TRUE)
            {
                /*Construct a Delay Request packet and send it on a ports
                 * as this is supported on dual emac port, only one link status is
                 * available per handle */
                linkStatus = ((ICSS_EmacObject *)
                              (timeSyncHandle->emacHandle)->object)->linkStatus[0];

                /*Send delay request frames in a burst*/
                for(frameCount = 0;
                        frameCount < timeSyncHandle->timeSyncConfig.pdelayBurstNumPkts; frameCount++)
                {
                    if(linkStatus)
                    {
                        /*write sequence id into memory*/
                        addHalfWord(timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[index] + PTP_SEQ_ID_OFFSET
                                    - offset,
                                    timeSyncHandle->tsRunTimeVar->pDelReqSequenceID[port - 1]);

                        /**Add Source Port ID*/
                        addHalfWord(timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[index] +
                                    PTP_SRC_PORT_ID_OFFSET - offset,
                                    port);

                        /*Use registered callback to send packet on Port 1
                         * In case of LL frame with HSR tag*/
                        if(timeSyncHandle->timeSyncConfig.ll_has_hsrTag ||
                                timeSyncHandle->timeSyncConfig.custom_tx_api)
                        {
                            txArg.icssEmacHandle = timeSyncHandle->emacHandle;
                            txArg.lengthOfPacket = TIMESYNC_PDELAY_BUF_SIZE;
                            txArg.portNumber = port;
                            txArg.queuePriority = quePri;
                            txArg.srcAddress = timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[index];

                            if(((((ICSS_EmacObject *)
                                    timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->callBack(
                                        &txArg,
                                        ((((ICSS_EmacObject *)
                                           timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->userArg) ==
                                    0)
                            {
                                timeSyncHandle->tsRunTimeVar->pDelReqSequenceID[port - 1]++;
                            }
                        }

                        else
                        {
                            /*send packet on port 1 without tag*/
                            if(ICSS_EmacTxPacketEnqueue(timeSyncHandle->emacHandle,
                                                        timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[index],
                                                        port,
                                                        quePri, TIMESYNC_PDELAY_BUF_SIZE) ==  0)
                            {
                                timeSyncHandle->tsRunTimeVar->pDelReqSequenceID[port - 1]++;
                            }

                        }

                    }

#if 0
                    /* Below is needed to be done for SWITCH cases, during that modify
                     * above loop to have PORT1
                     */
                    /*Add small delay between two requests on two ports
                     * to avoid collision scenarios
                     */
                    TaskP_sleep(10);

                    /***************************************************/
                    linkStatus = ((ICSS_EmacObject *)
                                  (timeSyncHandle->emacHandle)->object)->linkStatus[ICSS_EMAC_PORT_2 - 1];

                    if(linkStatus)
                    {
                        /*write sequence id into memory*/
                        addHalfWord(timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[1] + PTP_SEQ_ID_OFFSET
                                    - offset,
                                    timeSyncHandle->tsRunTimeVar->pDelReqSequenceID[ICSS_EMAC_PORT_2 - 1]);

                        /**Add Source Port ID*/
                        addHalfWord(timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[1] +
                                    PTP_SRC_PORT_ID_OFFSET - offset,
                                    ICSS_EMAC_PORT_2);

                        /*Use registered callback to send packet on Port 2*/
                        if(timeSyncHandle->timeSyncConfig.ll_has_hsrTag ||
                                timeSyncHandle->timeSyncConfig.custom_tx_api)
                        {
                            txArg.icssEmacHandle = timeSyncHandle->emacHandle;
                            txArg.lengthOfPacket = TIMESYNC_PDELAY_BUF_SIZE;
                            txArg.portNumber = ICSS_EMAC_PORT_2;
                            txArg.queuePriority = ICSS_EMAC_QUEUE3;
                            txArg.srcAddress = timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[1];

                            if(((((ICSS_EmacObject *)
                                    timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->callBack(
                                        &txArg,
                                        ((((ICSS_EmacObject *)
                                           timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->userArg) ==
                                    0)
                            {
                                timeSyncHandle->tsRunTimeVar->pDelReqSequenceID[ICSS_EMAC_PORT_2 - 1]++;
                            }
                        }

                        else
                        {
                            /*send packet on port 2 without tag*/
                            if(ICSS_EmacTxPacketEnqueue(timeSyncHandle->emacHandle,
                                                        timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[1],
                                                        ICSS_EMAC_PORT_2,
                                                        ICSS_EMAC_QUEUE3, TIMESYNC_PDELAY_BUF_SIZE) ==  0)
                            {
                                timeSyncHandle->tsRunTimeVar->pDelReqSequenceID[ICSS_EMAC_PORT_2 - 1]++;
                            }
                        }


                    }
#endif

                    TaskP_sleep(timeSyncHandle->timeSyncConfig.pdelayBurstInterval);
                }

            }

            TaskP_sleep(timeSyncHandle->timeSyncConfig.pDelReqPktInterval);

        }

    }
}

void TimeSync_delayReqSendTask(UArg a0, UArg a1)
{
    ICSS_EmacTxArgument txArg;
    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)a0;
    uint8_t offset = timeSyncHandle->timeSyncConfig.frame_offset;
    uint32_t            port, quePri;

    if (TIMESYNC_TEST_PORT_NUM == 0)
    {
        port = ICSS_EMAC_PORT_1;
        quePri = ICSS_EMAC_QUEUE1;
    }
    else
    {
        port = ICSS_EMAC_PORT_2;
        quePri = ICSS_EMAC_QUEUE3;
    }

    while(1)
    {
        /*Wait for sync frame to post the semaphore
         * and then send a delay request frame on the port on which
         * master is connected
         */
        SemaphoreP_pend(timeSyncHandle->delayReqTxSemHandle, SemaphoreP_WAIT_FOREVER);
        /*Use registered callback to send packet on Port connected to master*/

        /*Add port number*/
        addHalfWord(timeSyncHandle->timeSyncBuff.delayReq_TxBuf +
                    PTP_SRC_PORT_ID_OFFSET - offset,
                    timeSyncHandle->tsRunTimeVar->syncPortNum);

        /*Add sequence ID*/
        addHalfWord(timeSyncHandle->timeSyncBuff.delayReq_TxBuf + PTP_SEQ_ID_OFFSET
                    - offset,
                    timeSyncHandle->tsRunTimeVar->delReqSequenceID);

        if(timeSyncHandle->timeSyncConfig.custom_tx_api)
        {
            txArg.icssEmacHandle = timeSyncHandle->emacHandle;
            txArg.lengthOfPacket = TIMESYNC_DELAY_REQ_BUF_SIZE;
            txArg.portNumber = timeSyncHandle->tsRunTimeVar->syncPortNum;
            txArg.queuePriority = quePri;
            txArg.srcAddress = timeSyncHandle->timeSyncBuff.delayReq_TxBuf;

            if(((((ICSS_EmacObject *)
                    timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->callBack(
                        &txArg, ((((ICSS_EmacObject *)
                                   timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->userArg) ==
                    0)
            {
                timeSyncHandle->tsRunTimeVar->delReqSequenceID++;
            }
        }

        else
        {
            /*send packet on same port as master*/
            if(ICSS_EmacTxPacketEnqueue(timeSyncHandle->emacHandle,
                                        timeSyncHandle->timeSyncBuff.delayReq_TxBuf,
                                        timeSyncHandle->tsRunTimeVar->syncPortNum,
                                        quePri, TIMESYNC_DELAY_REQ_BUF_SIZE) ==  0)
            {
                timeSyncHandle->tsRunTimeVar->delReqSequenceID++;
            }
        }


    }

}


void TimeSync_TxTSTask_P1(UArg a0, UArg a1)
{
    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)a0;
    uint32_t events = 0;

    while(1)
    {
        /*Pend on event to process Tx timestamp interrupt*/
        events = EventP_pend(timeSyncHandle->txTSAvailableEvtHandle[ICSS_EMAC_PORT_1 -
                             1],
                             EventP_ID_NONE,
                             (timeSyncHandle->eventIdPdelayReq + timeSyncHandle->eventIdSync \
                              + timeSyncHandle->eventIdPdelayResp), EventP_WAIT_FOREVER);

        if(events & timeSyncHandle->eventIdSync)
        {
            TimeSync_getTxTS(timeSyncHandle, ICSS_EMAC_PORT_1, SYNC_FRAME);
        }

        if(events & timeSyncHandle->eventIdPdelayReq)
        {
            TimeSync_getTxTS(timeSyncHandle, ICSS_EMAC_PORT_1, DELAY_REQ_FRAME);
        }

        if(events & timeSyncHandle->eventIdPdelayResp)
        {
            TimeSync_getTxTS(timeSyncHandle, ICSS_EMAC_PORT_1, DELAY_RESP_FRAME);
        }

    }
}

void TimeSync_TxTSTask_P2(UArg a0, UArg a1)
{
    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)a0;
    uint32_t events = 0;

    while(1)
    {
        /*Pend on event to process Tx timestamp interrupt*/
        events = EventP_pend(timeSyncHandle->txTSAvailableEvtHandle[ICSS_EMAC_PORT_2 -
                             1],
                             EventP_ID_NONE,
                             (timeSyncHandle->eventIdPdelayReq + timeSyncHandle->eventIdSync \
                              + timeSyncHandle->eventIdPdelayResp), EventP_WAIT_FOREVER);

        if(events & timeSyncHandle->eventIdSync)
        {
            TimeSync_getTxTS(timeSyncHandle, ICSS_EMAC_PORT_2, SYNC_FRAME);
        }

        if(events & timeSyncHandle->eventIdPdelayReq)
        {
            TimeSync_getTxTS(timeSyncHandle, ICSS_EMAC_PORT_2, DELAY_REQ_FRAME);
        }

        if(events & timeSyncHandle->eventIdPdelayResp)
        {
            TimeSync_getTxTS(timeSyncHandle, ICSS_EMAC_PORT_2, DELAY_RESP_FRAME);
        }
    }

}

void TimeSync_NRT_Task(UArg a0, UArg a1)
{
    uint32_t events = 0;
    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)a0;

    while(1)
    {
        /*Wait 1ms then move on to other tasks*/
        events = EventP_pend(timeSyncHandle->ptpPdelayResEvtHandle[ICSS_EMAC_PORT_1 -
                             1],
                             (timeSyncHandle->eventIdPdelayResp + timeSyncHandle->eventIdPdelayRespFlwUp),
                             EventP_ID_NONE, 1);

        /*Calculate Peer Delay on Port 1*/
        if(events)
        {
            TimeSync_processPdelayRespFrame(timeSyncHandle,
                                            timeSyncHandle->timeSyncBuff.pdelayRes_RxBuf[ICSS_EMAC_PORT_1 - 1],
                                            FALSE, ICSS_EMAC_PORT_1);

            if(timeSyncHandle->pDelayParams[ICSS_EMAC_PORT_1 - 1].ifTwoStep)
            {

                TimeSync_processPdelayRespFrame(timeSyncHandle,
                                                timeSyncHandle->timeSyncBuff.pdelayResFlwUp_RxBuf[ICSS_EMAC_PORT_1 - 1],
                                                TRUE, ICSS_EMAC_PORT_1);
            }
        }

        /*Wait 1ms then move on to other tasks*/
        events = EventP_pend(timeSyncHandle->ptpPdelayResEvtHandle[ICSS_EMAC_PORT_2 -
                             1],
                             (timeSyncHandle->eventIdPdelayResp + timeSyncHandle->eventIdPdelayRespFlwUp),
                             EventP_ID_NONE, 1);

        /*Calculate Peer Delay on Port 2*/
        if(events)
        {
            TimeSync_processPdelayRespFrame(timeSyncHandle,
                                            timeSyncHandle->timeSyncBuff.pdelayRes_RxBuf[ICSS_EMAC_PORT_2 - 1],
                                            FALSE, ICSS_EMAC_PORT_2);

            if(timeSyncHandle->pDelayParams[ICSS_EMAC_PORT_2 - 1].ifTwoStep)
            {
                TimeSync_processPdelayRespFrame(timeSyncHandle,
                                                timeSyncHandle->timeSyncBuff.pdelayResFlwUp_RxBuf[ICSS_EMAC_PORT_2 - 1],
                                                TRUE, ICSS_EMAC_PORT_2);
            }
        }

        /*Send Pdelay response on Port 1*/
        events = EventP_pend(timeSyncHandle->ptpPdelayReqEvtHandle[ICSS_EMAC_PORT_1 -
                             1],
                             (timeSyncHandle->eventIdPdelayReq), EventP_ID_NONE, 1);

        if(events)
        {
            TimeSync_processPdelayReqFrame(timeSyncHandle,
                                           timeSyncHandle->timeSyncBuff.pdelayReq_RxBuf[ICSS_EMAC_PORT_1 - 1], \
                                           ICSS_EMAC_PORT_1);
        }

        /*Send Pdelay response on Port 2*/
        events = EventP_pend(timeSyncHandle->ptpPdelayReqEvtHandle[ICSS_EMAC_PORT_2 -
                             1],
                             (timeSyncHandle->eventIdPdelayReq), EventP_ID_NONE, 1);

        if(events)
        {
            TimeSync_processPdelayReqFrame(timeSyncHandle,
                                           timeSyncHandle->timeSyncBuff.pdelayReq_RxBuf[ICSS_EMAC_PORT_2 - 1], \
                                           ICSS_EMAC_PORT_2);
        }

        /*Wait 1ms then move on to other tasks*/
        events = EventP_pend(timeSyncHandle->ptpSendFollowUpEvtHandle[ICSS_EMAC_PORT_1 -
                             1],
                             (timeSyncHandle->eventIdSync + timeSyncHandle->eventIdFlwUpGenerated),
                             EventP_ID_NONE, 1);

        if(events)
        {
            TimeSync_forced2StepBDCalc(timeSyncHandle, ICSS_EMAC_PORT_1);
        }

        /*Wait 1ms then move on to other tasks*/
        events = EventP_pend(timeSyncHandle->ptpSendFollowUpEvtHandle[ICSS_EMAC_PORT_2 -
                             1],
                             (timeSyncHandle->eventIdSync + timeSyncHandle->eventIdFlwUpGenerated),
                             EventP_ID_NONE, 1);

        if(events)
        {
            TimeSync_forced2StepBDCalc(timeSyncHandle, ICSS_EMAC_PORT_2);
        }
    }

}

void TimeSync_BackgroundTask(UArg a0, UArg a1)
{
    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)a0;
    uint32_t sharedRAMbaseAddress = 0;
    uint8_t count = 0;
    int32_t avgCorrection = 0;

    sharedRAMbaseAddress = (((ICSS_EmacHwAttrs *)
                             (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr;



    while(1)
    {
        /*Increment the tick counter*/
        timeSyncHandle->tsRunTimeVar->tickCounter++;

        /*check for sync timeout*/
        if(timeSyncHandle->tsRunTimeVar->syncLastSeenCounter++ >
                timeSyncHandle->tsRunTimeVar->syncTimeoutInterval)
        {

            /*reset the master port used in redundant clock*/
            HWREGB(sharedRAMbaseAddress + MASTER_PORT_NUM_OFFSET) = 0;
            timeSyncHandle->numSyncMissed++;

            /*If we continuously miss sync frames then reset*/
            if((timeSyncHandle->numSyncMissed % NUM_SYNC_MISSED_THRESHOLD) == 0)
            {
                if (timeSyncHandle->timeSyncConfig.isMaster)
                {
                    /* No action for master mode as there is Sync frame to
                       receive, Master sends the Sync Frame */
                }
                else
                {
                    TimeSync_reset(timeSyncHandle);
                }
            }

            /*reset so that we don't keep getting this error*/
            timeSyncHandle->tsRunTimeVar->syncLastSeenCounter = 0;

        }

        /*Check if we have to process the data*/
        if(timeSyncHandle->offsetAlgo->binFull == 1)
        {
            /*get average of all offsets*/
            avgCorrection = 0;

            for(count = 0; count < 5; count++)
            {
                avgCorrection += timeSyncHandle->offsetAlgo->correction[count];
            }

            avgCorrection /= 5;
            /*add the new correction value to initial offset or the PPM value*/
            timeSyncHandle->tsRunTimeVar->initialOffset += avgCorrection;
            /*Reset the variables so another round of measurements can begin*/
            timeSyncHandle->offsetAlgo->binFull = 0;
            timeSyncHandle->offsetAlgo->num_entries_index = 0;
        }

        TaskP_sleep(PTP_BG_TASK_TICK_PERIOD);
    }

}

void TimeSync_SyncTxTask(UArg arg)
{
    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)arg;
    ICSS_EmacTxArgument txArg;
    uint8_t frameSentP1 = 0;
    uint8_t frameSentP2 = 0;
    uint8_t offset = 0;
    uint64_t sec = 0;
    uint32_t n_sec = 0;

    offset = timeSyncHandle->timeSyncConfig.frame_offset;

    while(1)
    {
        /*Pend on semaphore*/
        SemaphoreP_pend(timeSyncHandle->syncTxSemHandle, SemaphoreP_WAIT_FOREVER);

        if(timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TWO_STEP_INDEX])
        {
            /*Use API to get current time*/
            TimeSync_getCurrentTime(timeSyncHandle, &n_sec, &sec);

            /*Write seconds into packet*/
            convEndianess(&sec, timeSyncHandle->timeSyncBuff.sync_TxBuf + \
                          PTP_REQ_RCPT_TS_SEC_OFFSET - offset, 6);
            /*Write nanoseconds into packet*/
            convEndianess(&n_sec, timeSyncHandle->timeSyncBuff.sync_TxBuf + \
                          PTP_REQ_RCPT_TS_NSEC_OFFSET - offset, 4);
        }

        /*write sequence id into frame*/
        addHalfWord(timeSyncHandle->timeSyncBuff.sync_TxBuf + PTP_SEQ_ID_OFFSET -
                    offset,
                    timeSyncHandle->tsRunTimeVar->syncSequenceID);

        /*if 2-step then write same sequence id into follow up frame*/
        if(timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TWO_STEP_INDEX])
        {
            addHalfWord(timeSyncHandle->timeSyncBuff.followUp_TxBuf[0] + PTP_SEQ_ID_OFFSET -
                        offset,
                        timeSyncHandle->tsRunTimeVar->syncSequenceID);

            addHalfWord(timeSyncHandle->timeSyncBuff.followUp_TxBuf[1] + PTP_SEQ_ID_OFFSET -
                        offset,
                        timeSyncHandle->tsRunTimeVar->syncSequenceID);
        }

        /*-----------Send Sync on Port 1-------------*/
#if TIMESYNC_EXAMPLE_TEST_PORT0
        /**Add Source Port ID*/
        addHalfWord(timeSyncHandle->timeSyncBuff.sync_TxBuf + PTP_SRC_PORT_ID_OFFSET -
                    offset,
                    ICSS_EMAC_PORT_1);

        if(!timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TWO_STEP_INDEX]
                &&
                (V2 == timeSyncHandle->timeSyncConfig.icssVersion))
        {
            TimeSync_writeTS_SingleStep_Sync(timeSyncHandle, ICSS_EMAC_PORT_1);
        }

        if(timeSyncHandle->timeSyncConfig.hsrEnabled ||
                timeSyncHandle->timeSyncConfig.custom_tx_api)
        {

            txArg.icssEmacHandle = timeSyncHandle->emacHandle;
            txArg.lengthOfPacket = timeSyncHandle->timeSyncBuff.syncBuf_size;
            txArg.portNumber = ICSS_EMAC_PORT_1;
            txArg.queuePriority = ICSS_EMAC_QUEUE1;
            txArg.srcAddress = timeSyncHandle->timeSyncBuff.sync_TxBuf;

            if(((((ICSS_EmacObject *)
                    timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->callBack(
                        &txArg,
                        ((((ICSS_EmacObject *)
                           timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->userArg) ==
                    0)
            {
                frameSentP1 = 1;
            }
        }

        else
        {
            /*send packet on port 1 without tag*/
            if(ICSS_EmacTxPacketEnqueue(timeSyncHandle->emacHandle,
                                        timeSyncHandle->timeSyncBuff.sync_TxBuf,
                                        ICSS_EMAC_PORT_1,
                                        ICSS_EMAC_QUEUE1, timeSyncHandle->timeSyncBuff.syncBuf_size) ==  0)
            {
                frameSentP1 = 1;
            }
        }
#else
        /**Add Source Port ID*/
        addHalfWord(timeSyncHandle->timeSyncBuff.sync_TxBuf + PTP_SRC_PORT_ID_OFFSET -
                    offset,
                    ICSS_EMAC_PORT_2);

        if(!timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TWO_STEP_INDEX]
                &&
                (V2 == timeSyncHandle->timeSyncConfig.icssVersion))
        {
            TimeSync_writeTS_SingleStep_Sync(timeSyncHandle, ICSS_EMAC_PORT_2);
        }

        if(timeSyncHandle->timeSyncConfig.hsrEnabled ||
                timeSyncHandle->timeSyncConfig.custom_tx_api)
        {

            txArg.icssEmacHandle = timeSyncHandle->emacHandle;
            txArg.lengthOfPacket = timeSyncHandle->timeSyncBuff.syncBuf_size;
            txArg.portNumber = ICSS_EMAC_PORT_2;
            txArg.queuePriority = ICSS_EMAC_QUEUE3;
            txArg.srcAddress = timeSyncHandle->timeSyncBuff.sync_TxBuf;

            if(((((ICSS_EmacObject *)
                    timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->callBack(
                        &txArg,
                        ((((ICSS_EmacObject *)
                           timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->userArg) ==
                    0)
            {
                frameSentP2 = 1;
            }
        }

        else
        {
            /*send packet on port 1 without tag*/
            if(ICSS_EmacTxPacketEnqueue(timeSyncHandle->emacHandle,
                                        timeSyncHandle->timeSyncBuff.sync_TxBuf,
                                        ICSS_EMAC_PORT_2,
                                        ICSS_EMAC_QUEUE3, timeSyncHandle->timeSyncBuff.syncBuf_size) ==  0)
            {
                frameSentP2 = 1;
            }
        }

#endif

        /*If any one frame was sent out, increment counter*/
        if(frameSentP2 | frameSentP1)
        {
            timeSyncHandle->tsRunTimeVar->syncSequenceID++;
        }

    }


}

void TimeSync_AnnounceTxTask(UArg a0, UArg a1)
{
    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)a0;
    ICSS_EmacTxArgument txArg;
    uint8_t frameSentP1 = 0;
    uint8_t frameSentP2 = 0;
    uint64_t sec = 0;
    uint32_t n_sec = 0;
    uint8_t offset = timeSyncHandle->timeSyncConfig.frame_offset;

    while(1)
    {
        /*Send if master is enabled*/
        if(timeSyncHandle->timeSyncConfig.isMaster)
        {

            /*Use API to get current time*/
            TimeSync_getCurrentTime(timeSyncHandle, &n_sec, &sec);

            /*Write seconds into packet*/
            convEndianess(&sec, timeSyncHandle->timeSyncBuff.announce_TxBuf + \
                          PTP_REQ_RCPT_TS_SEC_OFFSET - offset, 6);
            /*Write nanoseconds into packet*/
            convEndianess(&n_sec, timeSyncHandle->timeSyncBuff.announce_TxBuf + \
                          PTP_REQ_RCPT_TS_NSEC_OFFSET - offset, 4);

            /*write sequence id into memory*/
            addHalfWord(timeSyncHandle->timeSyncBuff.announce_TxBuf + PTP_SEQ_ID_OFFSET -
                        offset,
                        timeSyncHandle->tsRunTimeVar->announceSequenceID);

            /*-----------Send Announce on Port 1-------------*/
#if TIMESYNC_EXAMPLE_TEST_PORT0
            /**Add Source Port ID*/
            addHalfWord(timeSyncHandle->timeSyncBuff.announce_TxBuf + PTP_SRC_PORT_ID_OFFSET
                        - offset,
                        ICSS_EMAC_PORT_1);

            if(timeSyncHandle->timeSyncConfig.hsrEnabled ||
                    timeSyncHandle->timeSyncConfig.custom_tx_api)
            {

                txArg.icssEmacHandle = timeSyncHandle->emacHandle;
                txArg.lengthOfPacket = timeSyncHandle->timeSyncBuff.announceBuf_size;
                txArg.portNumber = ICSS_EMAC_PORT_1;
                txArg.queuePriority = ICSS_EMAC_QUEUE1;
                txArg.srcAddress = timeSyncHandle->timeSyncBuff.announce_TxBuf;

                if(((((ICSS_EmacObject *)
                        timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->callBack(
                            &txArg,
                            ((((ICSS_EmacObject *)
                               timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->userArg) ==
                        0)
                {
                    frameSentP1 = 1;
                }
            }

            else
            {
                /*send packet on port 1 without tag*/
                if(ICSS_EmacTxPacketEnqueue(timeSyncHandle->emacHandle,
                                            timeSyncHandle->timeSyncBuff.announce_TxBuf,
                                            ICSS_EMAC_PORT_1,
                                            ICSS_EMAC_QUEUE1, timeSyncHandle->timeSyncBuff.announceBuf_size) ==  0)
                {
                    frameSentP1 = 1;
                }
            }
#else
            /**Add Source Port ID*/
            addHalfWord(timeSyncHandle->timeSyncBuff.announce_TxBuf + PTP_SRC_PORT_ID_OFFSET
                        - offset,
                        ICSS_EMAC_PORT_2);

            if(timeSyncHandle->timeSyncConfig.hsrEnabled ||
                    timeSyncHandle->timeSyncConfig.custom_tx_api)
            {

                txArg.icssEmacHandle = timeSyncHandle->emacHandle;
                txArg.lengthOfPacket = timeSyncHandle->timeSyncBuff.announceBuf_size;
                txArg.portNumber = ICSS_EMAC_PORT_2;
                txArg.queuePriority = ICSS_EMAC_QUEUE3;
                txArg.srcAddress = timeSyncHandle->timeSyncBuff.announce_TxBuf;

                if(((((ICSS_EmacObject *)
                        timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->callBack(
                            &txArg,
                            ((((ICSS_EmacObject *)
                               timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->userArg) ==
                        0)
                {
                    frameSentP2 = 1;
                }
            }
    
            else
            {
                /*send packet on port 1 without tag*/
                if(ICSS_EmacTxPacketEnqueue(timeSyncHandle->emacHandle,
                                            timeSyncHandle->timeSyncBuff.announce_TxBuf,
                                            ICSS_EMAC_PORT_2,
                                            ICSS_EMAC_QUEUE3, timeSyncHandle->timeSyncBuff.announceBuf_size) ==  0)
                {
                    frameSentP2 = 1;
                }
            }

#endif /* TIMESYNC_EXAMPLE_TEST_PORT0 */
            /*If any one frame was sent out, increment counter*/
            if(frameSentP2 | frameSentP1)
            {
                timeSyncHandle->tsRunTimeVar->announceSequenceID++;
            }

        }

        frameSentP1 = 0;
        frameSentP2 = 0;
        TaskP_sleep(timeSyncHandle->timeSyncConfig.announceSendInterval);

    }

}

void TimeSync_latchSyncTask(UArg arg0, UArg arg1)
{
    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)arg0;

    while(1)
    {
        /*Pend on semaphore*/
        SemaphoreP_pend(timeSyncHandle->latch_sync_SemHandle, SemaphoreP_WAIT_FOREVER);

        if(timeSyncHandle->timeSyncConfig.process_TOD_and_sync_2_1PPS)
        {
            /*Get the latch time stamp*/
            TimeSync_getLatchTime(timeSyncHandle,
                                  &(timeSyncHandle->tsToDParams->latch_Ts_NS),
                                  &(timeSyncHandle->tsToDParams->latch_Ts_Sec));
            /*Synchronize the clock*/
            TimeSync_synchronizeToD(timeSyncHandle);
            /*Calculate sync interval*/
            TimeSync_calcSyncInterval_ToD(timeSyncHandle);

        }
    }
}

/* ========================================================================== */
/*                           ISR Definitions                                  */
/* ========================================================================== */

void TimeSync_txTSIsr(UArg arg)
{
    volatile uint32_t *intStatusPtr = NULL;
    volatile uint8_t *bytePtr = NULL;

    uint8_t portNum = 0;
    uint8_t oppPort = 0;
    uint32_t nanoseconds = 0;
    uint32_t sharedRAMbaseAddress = 0;
    uint64_t seconds = 0;

    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)arg;

    sharedRAMbaseAddress = (((ICSS_EmacHwAttrs *)
                             (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr;

    intStatusPtr = (uint32_t *)(uint32_t)((((ICSS_EmacHwAttrs *)
                                            (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs \
                                          + CSL_ICSSINTC_SECR0);

    /*Check which port posted the interrupt*/
    if(*intStatusPtr & TIMESYNC_TX_TS_ISR_MASK_P1)
    {
        bytePtr = (uint8_t *)((uint32_t)(sharedRAMbaseAddress +
                                         TX_TS_NOTIFICATION_OFFSET_SYNC_P1));
        *intStatusPtr = TIMESYNC_TX_TS_ISR_MASK_P1;
        portNum = ICSS_EMAC_PORT_1;
        oppPort = ICSS_EMAC_PORT_2;
    }

    else
    {
        bytePtr = (uint8_t *)((uint32_t)(sharedRAMbaseAddress +
                                         TX_TS_NOTIFICATION_OFFSET_SYNC_P2));
        *intStatusPtr = TIMESYNC_TX_TS_ISR_MASK_P2;
        portNum = ICSS_EMAC_PORT_2;
        oppPort = ICSS_EMAC_PORT_1;
    }

    if(*(bytePtr))      /*sync frame*/
    {
        TimeSync_getTxTimestamp(timeSyncHandle, SYNC_FRAME, portNum,
                                &nanoseconds, &seconds);


        if(timeSyncHandle->timeSyncConfig.isMaster)
        {
            timeSyncHandle->syncParam[portNum - 1]->txTsSec = seconds;
            timeSyncHandle->syncParam[portNum - 1]->txTs = nanoseconds;
        }

        else
        {
            timeSyncHandle->syncParam[oppPort - 1]->txTsSec = seconds;
            timeSyncHandle->syncParam[oppPort - 1]->txTs = nanoseconds;
        }

        /*If master then post event to
         * send out follow up frame*/
        if(timeSyncHandle->timeSyncConfig.isMaster &&
                timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TWO_STEP_INDEX])
        {
            EventP_post(timeSyncHandle->txTSAvailableEvtHandle[portNum - 1],
                        timeSyncHandle->eventIdSync);
        }

        /*If slave and forced 2-step then post event to send out follow up frame*/
        if(timeSyncHandle->tsRunTimeVar->forced2step[oppPort - 1])
        {
            EventP_post(timeSyncHandle->txTSAvailableEvtHandle[portNum - 1],
                        timeSyncHandle->eventIdSync);
        }

        *(bytePtr) = 0;
    }

    if(*(bytePtr + 1))      /*delay request frame*/
    {
        TimeSync_getTxTimestamp(timeSyncHandle, DELAY_REQ_FRAME, portNum,
                                &nanoseconds, &seconds);

        if(timeSyncHandle->timeSyncConfig.type == P2P)
        {
            timeSyncHandle->pDelayParams[portNum - 1].T1Sec = seconds;
            /*Copy nanoseconds*/
            timeSyncHandle->pDelayParams[portNum - 1].T1Nsec = nanoseconds;
        }

        else
        {
            timeSyncHandle->delayParams->delReqTxTsNS = nanoseconds;
            timeSyncHandle->delayParams->delReqTxTsSec = seconds;
        }

        *(bytePtr + 1) = 0;
    }

    if(*(bytePtr + 2))      /*Pdelay response frame*/
    {
        EventP_post(timeSyncHandle->txTSAvailableEvtHandle[portNum - 1],
                    timeSyncHandle->eventIdPdelayResp);
        *(bytePtr + 2) = 0;
    }

}

void TimeSync_latchIsr(UArg arg)
{
    volatile uint32_t *intStatusPtr = NULL;


    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)arg;

    intStatusPtr = (uint32_t *)(uint32_t)((((ICSS_EmacHwAttrs *)
                                            (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->prussIntcRegs \
                                          + CSL_ICSSINTC_SECR0);
    /*clear the interrupt*/
    *intStatusPtr = TIMESYNC_LATCH0_ISR_MASK;

    /*Post semaphore for latch sync task*/
    SemaphoreP_post(timeSyncHandle->latch_sync_SemHandle);

}

void TimeSync_syncTxIsr(UArg arg)
{
    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)arg;
    SemaphoreP_post(timeSyncHandle->syncTxSemHandle);
}

void TimeSync_enableMaster(TimeSync_ParamsHandle_t timeSyncHandle)
{
    uint8_t *bytePtr = NULL;
    /*Enable mode*/
    timeSyncHandle->timeSyncConfig.isMaster = 1;
    /*Write into memory*/
    bytePtr = (uint8_t *)(((ICSSEMAC_HwAttrs *)
                           timeSyncHandle->emacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr +
              DUT_IS_MASTER_OFFSET;
    *bytePtr = 1;

    /*Populate parameters of DUT into the follow up frame*/
    TimeSync_initializeFollowUp(timeSyncHandle);

    /*Start the clock*/
    TimerP_start(timeSyncHandle->timeSync_syncTxTimer);

}

void TimeSync_disableMaster(TimeSync_ParamsHandle_t timeSyncHandle)
{
    uint8_t *bytePtr = NULL;
    /*Disable mode*/
    timeSyncHandle->timeSyncConfig.isMaster = 0;
    /*Write into memory*/
    bytePtr = (uint8_t *)(((ICSSEMAC_HwAttrs *)
                           timeSyncHandle->emacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr +
              DUT_IS_MASTER_OFFSET;
    *bytePtr = 0;
    /*Stop the timer*/
    TimerP_stop(timeSyncHandle->timeSync_syncTxTimer);
}
