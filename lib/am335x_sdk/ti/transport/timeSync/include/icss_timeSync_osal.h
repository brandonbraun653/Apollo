/******************************************************************************
 * FILE NAME:   icss_timeSync_osal.h
 *
 * DESCRIPTION: Contains, tasks, interrupts, semaphores, timer functions. 
 *              Basically all features related to Operating System.
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


#ifndef ICSS_TIMESYNC_OSAL_H_
#define ICSS_TIMESYNC_OSAL_H_

#include <ti/transport/timeSync/include/icss_timeSync.h>
#include <ti/transport/timeSync/include/icss_timeSyncApi.h>
#include <ti/transport/timeSync/include/icss_timeSync_init.h>

#define DMTIMER_SRC_CLK_FREQ   19200000

#define DMTIMER_4_ID            3

#define DMTIMER_5_ID            4

/**
 * @def PTP_DELAY_REQ_SEND_TASK_PRIORITY
 *      Priority of task which sends Pdelay request frames
 */
#define PTP_DELAY_REQ_SEND_TASK_PRIORITY            10

/**
 * @def PTP_TX_TS_TASK_PRIORITY
 *      Priority of task which takes time stamp and processes them
 */
#define PTP_TX_TS_TASK_PRIORITY                     10

/**
 * @def PTP_TX_TS_TASK_PRIORITY
 *      Priority of task which takes time stamp and processes them
 */
#define PTP_FLW_UP_TX_TASK_PRIORITY                 8

/**
 * @def PTP_SYNC_TASK_PRIORITY
 *      Priority of task which processes sync frame
 */
#define PTP_SYNC_TASK_PRIORITY                      15

/**
 * @def PTP_ANNOUNCE_TASK_PRIORITY
 *      Priority of task which sends Announce frames
 */
#define PTP_ANNOUNCE_TASK_PRIORITY                  10

/**
 * @def PTP_FOLLOW_UP_TASK_PRIORITY
 *      Priority of task which sends Follow Up frames
 */
#define PTP_FOLLOW_UP_TASK_PRIORITY                 10

/**
 * @def PTP_BG_TASK_TICK_PERIOD
 *      PTP BG task ticks at this rate
 */
#define PTP_BG_TASK_TICK_PERIOD                     10

/**
 * @def PTP_TX_CALLBACK_HWI_PRIORITY
 *      Priority for Tx callback interrupt. Range 0-31
 */
#define PTP_TX_CALLBACK_HWI_PRIORITY                20

/**
 * @def PTP_LATCH0_HWI_PRIORITY
 *      Priority for Latch0 interrupt. Range 0-31
 */
#define PTP_LATCH0_HWI_PRIORITY                     20

/**
 * @brief Initialize PTP ISR's, semaphores, tasks and timers
 * @param timeSyncHandle pointer to PTP Handle structure
 * @return Error status
 */
int8_t TimeSync_isrAndTaskInit(TimeSync_ParamsHandle_t timeSyncHandle);

/**
 * @internal
 * @brief This is used for
 * 1. Sending Peer delay request messages used to calculate peer delay
 * @param  a0 generic argument. PTP Handle is passed through this
 * @param  a1 is NULL
 * @return none
 */
void TimeSync_PdelayReqSendTask(UArg a0, UArg a1);

/**
 * @internal
 * @brief This is used for
 *  Sending delay request messages to master to calculate line delay
 * @param  a0 generic argument. PTP Handle is passed through this
 * @param  a1 is NULL
 * @return none
 */
void TimeSync_delayReqSendTask(UArg a0, UArg a1);

/**
 * @internal
 * @brief This is used for
 * 1. Extracting Tx Timestamp information when a callback interrupt is triggered from firmware
 * 2. Checks for the type of packet and calls relevant Tx API
 * 3. For Port 1
 * @param  a0 generic argument. PTP Handle is passed through this
 * @param  a1 is NULL
 * @return none
 */
void TimeSync_TxTSTask_P1(UArg a0, UArg a1);

/**
 * @internal
 * @brief This is used for
 * 1. Extracting Tx Timestamp information when a callback interrupt is triggered from firmware
 * 2. Checks for the type of packet and calls relevant Tx API
 * 3. For Port 2
 * @param  a0 generic argument. PTP Handle is passed through this
 * @param  a1 is NULL
 * @return none
 */
void TimeSync_TxTSTask_P2(UArg a0, UArg a1);
/**
 * @internal
 * @brief This is used for
 * 1. Checking for missed Sync frames
 * 2. Running part of offset stabilization algorithm
 * @param  a0 generic argument. PTP Handle is passed through this
 * @param  a1 is NULL
 * @return none
 */
void TimeSync_BackgroundTask(UArg a0, UArg a1);
/**
 * @internal
 * @brief This is used for
 * Synchronizing to the latch0 input and time of day
 * @param  a0 generic argument. PTP Handle is passed through this
 * @param  a1 is NULL
 * @return none
 */
void TimeSync_latchSyncTask(UArg arg0, UArg arg1);
/**
 * @internal
 * @brief NRT stands for non-real time
 * This task is responsible for processing Peer delay messages and
 * calculating peer delay
 * @param  a0 generic argument. PTP Handle is passed through this
 * @param  a1 is NULL
 * @return none
 */
void TimeSync_NRT_Task(UArg a0, UArg a1);

/**
 * @internal
 * @brief This is the main master task which sends a pre-formatted Sync frame at
 *  designated Sync interval. This is triggered upon DM Timer expiry and
 *  is actually a timer interrupt
 * @param  a0 generic argument. PTP Handle is passed through this
 * @return none
 */
void TimeSync_SyncTxTask(UArg arg);

/**
 * @internal
 * @brief This is task which sends pre-formatted Announce frames when
 * device is configured as a master or boundary clock.
 * @param  a0 generic argument. PTP Handle is passed through this
 * @param  a1 is NULL
 * @return none
 */
void TimeSync_AnnounceTxTask(UArg a0, UArg a1);

/**
 * @internal
 * @brief This task sends a Follow Up frame on a tx callback interrupt
 * when device is configured as 2-step master
 * @param  a0 generic argument. PTP Handle is passed through this
 * @param  a1 is NULL
 * @return none
 */
void TimeSync_FollowUpTxTask(UArg a0, UArg a1);

/**
 * @internal
 * @brief This is triggered by a Time sync frame getting timestamped on exit. It posts
 * a semaphore which in turn triggers the copying of Tx timestamps
 * @param  arg generic argument PTP Handle is passed through this
 * @return none
 */
void TimeSync_txTSIsr(UArg arg);
/**
 * @internal
 * @brief This is triggered by an input on Latch0 pin. Assuming that
 * the latch0 input is fed by 1PPS signal from a master it synchronizes
 * the local clock.
 * @param  arg generic argument PTP Handle is passed through this
 * @return none
 */
void TimeSync_latchIsr(UArg arg);

/**
 * @internal
 * @brief This is the ISR for DMTimer 4 which is configured to Sync send interval. It posts
 * a semaphore which in turn triggers the sending of sync frames
 * @param  arg generic argument PTP Handle is passed through this
 * @return none
 */
void TimeSync_syncTxIsr(UArg arg);

/**
 *  @brief  change from Slave to Master if not already
 * This should be invoked by the BMCA algorithm
 *  @param  timeSyncHandle pointer to PTP Handle structure
 *
 *  @retval None
 *
 */
void TimeSync_enableMaster(TimeSync_ParamsHandle_t timeSyncHandle);
/**
 *  @brief  change from Master mode to slave mode.
 * This should be invoked by the BMCA algorithm
 *  @param  timeSyncHandle pointer to PTP Handle structure
 *
 *  @retval None
 *
 */
void TimeSync_disableMaster(TimeSync_ParamsHandle_t timeSyncHandle);

#endif /* ICSS_TIMESYNC_OSAL_H_ */
