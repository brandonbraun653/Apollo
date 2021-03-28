/**
 * @file icss_timeSync.c
 *
 * @brief Contains the main PTP-1588 driver implementation functions like ISR's, 
 *  timers, synchronization, RCF calculation, line and peer delay calculation
 *
 *
 * Copyright (c) 2018, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <xdc/std.h>
#include <math.h>
#include <ti/transport/timeSync/include/icss_timeSync.h>
#include <ti/drv/icss_emac/firmware/icss_dualemac/src/icss_timeSync_memory_map.h>
#include <ti/transport/timeSync/include/icss_timeSyncApi.h>
#include <ti/transport/timeSync/include/icss_timeSync_ecap_edma.h>
#include <ti/transport/timeSync/include/icss_timeSync_init.h>
#include <ti/drv/icss_emac/icss_emac_ver.h>
#include <ti/transport/timeSync/include/icss_timeSync_tools.h>
#include <ti/transport/timeSync/include/soc_icss_header.h>

#if ICSS_EMAC_DRV_VERSION_ID ==(0x01000002)
#include <ti/transport/ndk/nimu_icss/nimu_icssTools.h>
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

void TimeSync_resetIEP(TimeSync_ParamsHandle_t timeSyncHandle)
{
    uint64_t doubleWord = 0;
    uint64_t reminder = 0;
    uint32_t word = 0;
    uint8_t *bytePtr;
    ICSS_EmacBaseAddressHandle_T emacBaseAddr = ((ICSS_EmacHwAttrs *)(
                timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg;

    /*First disable CMP1*/
    word = HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_CMP_CFG_REG);
    /*clear the CMP1 enable bit and store*/
    word &= ~((uint32_t)(4));
    HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_CMP_CFG_REG) = word;

    /*Read IEP value and re-program CMP1*/
    bytePtr = (uint8_t *)(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_COUNT_REG0);
    memcpy(&doubleWord, bytePtr, 8);

    /*We need to make sure that IEP aligns with the start of second boundary
     * This is done by finding the distance to second boundary and setting cmp1
     * to that value. An extra second is added as a margin of safety*/
    reminder = doubleWord % (uint64_t)SEC_TO_NS;

    if(reminder != 0)
    {
        doubleWord += (SEC_TO_NS - reminder) + SEC_TO_NS;
    }

    /*now write this value to CMP1 register*/
    bytePtr = (uint8_t *)(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_CMP1_REG0);
    memcpy(bytePtr, &doubleWord, 8);

    bytePtr = (uint8_t *)((((ICSSEMAC_HwAttrs *)
                            (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                          +  TIMESYNC_CMP1_CMP_OFFSET);
    memcpy(bytePtr, &doubleWord, 8);

    /*Enable CMP1*/
    word = HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_CMP_CFG_REG);
    /*enable CMP1 bit and store back*/
    word |= 0x4;
    HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_CMP_CFG_REG) = word;
}

void TimeSync_doFirstAdjustment(TimeSync_ParamsHandle_t timeSyncHandle,
                                uint8_t portNum)
{
    uint8_t *bytePtr = NULL;
    uint64_t syncRxTime = 0;
    uint64_t doubleWord = 0;
    uint64_t timeElapsed = 0;
    uint64_t iepCount = 0;
    uint32_t iepBaseAddress = (((ICSSEMAC_HwAttrs *)
                                (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->prussIepRegs;

    uint32_t sharedRAMbaseAddress = (((ICSS_EmacHwAttrs *)
                                      (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr;

    if(V2 == timeSyncHandle->timeSyncConfig.icssVersion)
    {
        /*Get origin time stamp in 64 bit format*/
        doubleWord = timeSyncHandle->syncParam[portNum - 1]->originTsSec *
                     (uint64_t)SEC_TO_NS + \
                     (uint64_t)timeSyncHandle->syncParam[portNum - 1]->originTsNs;

        /*Now calculate time elapsed since sync was received*/
        syncRxTime = timeSyncHandle->syncParam[portNum - 1]->rxTsSec *
                     (uint64_t)SEC_TO_NS + \
                     timeSyncHandle->syncParam[portNum - 1]->rxTs;
        bytePtr = (uint8_t *)((uint32_t)(iepBaseAddress + CSL_ICSSIEP_COUNT_REG0));
        memcpy(&iepCount, bytePtr, 8);

        timeElapsed = iepCount - syncRxTime;
        /*Add correction field and peer delay*/
        doubleWord += (timeElapsed + timeSyncHandle->tsRunTimeVar->pathDelay[portNum -
                       1]) + \
                      timeSyncHandle->syncParam[portNum - 1]->correctionField;
        memcpy(bytePtr, &doubleWord, 8);

        /*CMP 1 values need to be reset in case of
         * 64 byte counter or else CMP1 will never hit*/
        TimeSync_resetIEP(timeSyncHandle);

    }

    else
    {
        /*In case of older ICSS versions we write the seconds and nanoseconds
         * value directly into the memory
         */

        /*First calculate the total adjustment
         * timeElapsed here contains the net adjustment required*/

        /*Add correction field and peer delay*/
        timeElapsed = (timeSyncHandle->tsRunTimeVar->pathDelay[portNum - 1]) + \
                      timeSyncHandle->syncParam[portNum - 1]->correctionField;

        /*Now calculate time elapsed since sync was received*/
        bytePtr = (uint8_t *)((uint32_t)(iepBaseAddress + CSL_ICSSIEP_COUNT_REG0));
        memcpy(&iepCount, bytePtr, 4);

        /*The time elapsed refers to the time diff between sync was received
         * and current time which can't be more than 1 second so we just
         * subtract the nanoseconds part
         */
        if(iepCount < timeSyncHandle->syncParam[portNum - 1]->rxTs)
        {
            iepCount  += (uint32_t)SEC_TO_NS;
        }

        timeElapsed += (iepCount - timeSyncHandle->syncParam[portNum - 1]->rxTs);

        timeElapsed += timeSyncHandle->syncParam[portNum - 1]->originTsNs;

        if(timeElapsed >= SEC_TO_NS)
        {
            timeElapsed = SEC_TO_NS - doubleWord;
            doubleWord = timeSyncHandle->syncParam[portNum - 1]->originTsSec + 1;
        }

        else
        {
            doubleWord = timeSyncHandle->syncParam[portNum - 1]->originTsSec;
        }

        /*Write nanoseconds value into IEP register*/
        memcpy(bytePtr, &timeElapsed, 4);
        /*Write seconds value into seconds counter*/
        bytePtr = (uint8_t *)((uint32_t)(sharedRAMbaseAddress +
                                         TIMESYNC_SECONDS_COUNT_OFFSET));
        memcpy(bytePtr, &doubleWord, 6);
    }

}

void TimeSync_getTxTS(TimeSync_ParamsHandle_t timeSyncHandle, uint8_t portNum,
                      ptpFrameTypes_t frameType)
{
    uint8_t *ptpFlwUpPacket = NULL;
    uint8_t *ptpPDelayResFlwUpPacket = NULL;
    ICSS_EmacTxArgument txArg;
    uint32_t nanoseconds = 0;
    uint64_t seconds = 0;
    uint8_t oppPort = 0;
    uint8_t offset = timeSyncHandle->timeSyncConfig.frame_offset;
    uint32_t quePri;

    /* Get the queue priority */
    if (portNum == ICSS_EMAC_PORT_1)
    {
        quePri = ICSS_EMAC_QUEUE1;
    }
    else
    {
        quePri = ICSS_EMAC_QUEUE3;
    }

    /*Get the opposite port*/
    oppPort = ~portNum;
    oppPort &= 0x3;

    /*This gets called only in case of 2-step master and forced 2-step slave*/
    if(SYNC_FRAME == frameType)              /*Sync frame*/
    {
        if(!timeSyncHandle->timeSyncConfig.isMaster)
        {

            /*Set event flag to indicate sync frame tx*/
            EventP_post(timeSyncHandle->ptpSendFollowUpEvtHandle[oppPort - 1],
                        timeSyncHandle->eventIdSync);

        }

        else
        {
            ptpFlwUpPacket = timeSyncHandle->timeSyncBuff.followUp_TxBuf[portNum - 1];

            /*Write seconds into packet*/
            convEndianess(&(timeSyncHandle->syncParam[portNum - 1]->txTsSec),
                          ptpFlwUpPacket + \
                          PTP_REQ_RCPT_TS_SEC_OFFSET - offset, 6);
            /*Write nanoseconds into packet*/
            convEndianess(&(timeSyncHandle->syncParam[portNum - 1]->txTs),
                          ptpFlwUpPacket + \
                          PTP_REQ_RCPT_TS_NSEC_OFFSET - offset, 4);

            /*Add Source Port ID*/
            addHalfWord(ptpFlwUpPacket + PTP_SRC_PORT_ID_OFFSET - offset,
                        portNum);

            if(timeSyncHandle->timeSyncConfig.hsrEnabled ||
                    timeSyncHandle->timeSyncConfig.custom_tx_api)
            {

                txArg.icssEmacHandle = timeSyncHandle->emacHandle;
                txArg.lengthOfPacket = timeSyncHandle->timeSyncBuff.flwUpBuf_size;
                txArg.portNumber = portNum;
                txArg.queuePriority = quePri;
                txArg.srcAddress = ptpFlwUpPacket;

                /*Send follow up frame out*/
                ((((ICSS_EmacObject *)
                   timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->callBack(
                       &txArg,
                       ((((ICSS_EmacObject *)
                          timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->userArg);
            }

            else
            {
                ICSS_EmacTxPacketEnqueue(timeSyncHandle->emacHandle, ptpFlwUpPacket,
                                         portNum, quePri, timeSyncHandle->timeSyncBuff.flwUpBuf_size);
            }

        }

    }

    if(DELAY_RESP_FRAME == frameType)              /*Pdelay response*/
    {
        ptpPDelayResFlwUpPacket =
            timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[portNum - 1];

        TimeSync_getTxTimestamp(timeSyncHandle, DELAY_RESP_FRAME, portNum,
                                &nanoseconds, &seconds);

        /*Encode actual Tx time in Pdelay response frame and send*/
        convEndianess(&seconds, ptpPDelayResFlwUpPacket + \
                      PTP_REQ_RCPT_TS_SEC_OFFSET - offset, 6);
        convEndianess(&nanoseconds, ptpPDelayResFlwUpPacket + \
                      PTP_REQ_RCPT_TS_NSEC_OFFSET - offset, 4);

        if(timeSyncHandle->timeSyncConfig.ll_has_hsrTag ||
                timeSyncHandle->timeSyncConfig.custom_tx_api)
        {
            txArg.icssEmacHandle = timeSyncHandle->emacHandle;
            txArg.lengthOfPacket = TIMESYNC_PDELAY_BUF_SIZE;
            txArg.portNumber = portNum;
            txArg.queuePriority = quePri;
            txArg.srcAddress = ptpPDelayResFlwUpPacket;

            /*Send pdelay response follow up frame out*/
            ((((ICSS_EmacObject *)
               timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->callBack(
                   &txArg,
                   ((((ICSS_EmacObject *)
                      timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->userArg);
        }

        else
        {
            ICSS_EmacTxPacketEnqueue(timeSyncHandle->emacHandle, ptpPDelayResFlwUpPacket,
                                     portNum,
                                     quePri, TIMESYNC_PDELAY_BUF_SIZE);
        }

    }
}

void TimeSync_lineDelayCalc(TimeSync_ParamsHandle_t timeSyncHandle)
{

    /*The formula for calculation is
     * Mean Path Delay = (Master Delay - Slave Delay - Correction Path)/2.
     * Correction Path = Correction Path of (Delay Req + Sync + Follow Up(if present)*/

    /*Slave Delay = Tx timestamp of Delay Req packet - Rcv Timestamp of Sync Packet
     * Master Delay = Rcv Timestamp of Delay Resp - Precise origin timestamp of Follow Up Packet
     */

    uint64_t correctionField = 0, slaveDelay = 0, masterDelay = 0;
    uint64_t doubleWord = 0;
    uint8_t syncPortNum = timeSyncHandle->tsRunTimeVar->syncPortNum - 1;

    /*find total correction*/
    correctionField = timeSyncHandle->syncParam[syncPortNum]->correctionField +
                      timeSyncHandle->delayParams->correctionField;

    /*slave delay calculation*/
    slaveDelay = (timeSyncHandle->syncParam[syncPortNum]->rxTsSec *
                  (uint64_t)SEC_TO_NS) +
                 (uint64_t)timeSyncHandle->syncParam[syncPortNum]->rxTs;

    doubleWord = (timeSyncHandle->delayParams->delReqTxTsSec * (uint64_t)SEC_TO_NS
                  + (uint64_t)timeSyncHandle->delayParams->delReqTxTsNS);

    slaveDelay = doubleWord - slaveDelay;

    /*Do adjustment for MII Rx and Tx delay.
    * Here is the calculation :
    * delReqTxTS = delReqTxTS - Tx adjustment, rxTs = rxTs - Rx adjustment
    *  => delReqTxTS - rxTs = delReqTxTS - rxTs + Rx Adjustment - Tx Adjustment*/


    slaveDelay = (uint32_t)((double)slaveDelay * timeSyncHandle->tsSyntInfo->rcf);

    masterDelay = ((uint64_t)timeSyncHandle->delayParams->timeStampSec *
                   (uint64_t)SEC_TO_NS) +
                  (uint64_t)timeSyncHandle->delayParams->timeStampNS;
    masterDelay = masterDelay - (((uint64_t)
                                  timeSyncHandle->syncParam[syncPortNum]->originTsSec *
                                  (uint64_t)SEC_TO_NS) + (uint64_t)
                                 timeSyncHandle->syncParam[syncPortNum]->originTsNs);

    if(masterDelay > (slaveDelay + correctionField))
    {
        /*Add path delay minus correction divided by 2*/
        timeSyncHandle->tsRunTimeVar->meanPathDelay = (masterDelay - slaveDelay -
                correctionField)
                >> 1;
    }

    else
    {
        timeSyncHandle->tsRunTimeVar->meanPathDelay = 0;
    }

    /*check for illegal value*/
    if(timeSyncHandle->tsRunTimeVar->meanPathDelay >
            TIMESYNC_LINE_DELAY_ERROR_THRESHOLD)
    {
        timeSyncHandle->tsRunTimeVar->meanPathDelay = 0;
    }

    /*First time so assign directly*/
    if((timeSyncHandle->tsRunTimeVar->stateMachine &
            TS_STATE_MACHINE_LINE_DELAY_COMPUTED) == 0)
    {
        timeSyncHandle->tsRunTimeVar->pathDelay[syncPortNum] =
            timeSyncHandle->tsRunTimeVar->meanPathDelay;
        /*Once delay has been computed notify the state machine*/
        timeSyncHandle->tsRunTimeVar->stateMachine |=
            TS_STATE_MACHINE_LINE_DELAY_COMPUTED;
    }

    else
    {
        /*Use exponential averaging filter to get the line delay*/
        timeSyncHandle->tsRunTimeVar->pathDelay[syncPortNum] =
            (uint32_t)((double)
                       timeSyncHandle->tsRunTimeVar->pathDelay[syncPortNum] * \
                       (double)FILTER_ALPHA_COEFF + (double)timeSyncHandle->tsRunTimeVar->meanPathDelay
                       * \
                       (double)(1 - FILTER_ALPHA_COEFF));
    }

}

void TimeSync_peerDelayCalc(TimeSync_ParamsHandle_t timeSyncHandle,
                            uint8_t twoStep, uint8_t portNum)
{

    uint8_t *bytePtr = NULL;

    /*Shown below is the Peer delay logic*/
    /*
        Self           Peer         |
     *    T1            |           T
     *    |             T2          i
     *    |             |           m
     *    |             |           e
     *    |             T3          |
     *    T4            |           |
     *    |             |          \|/
     */

    /* delay on self (device) is T4 - T1 and delay on Peer is T3-T2
     * 2 x peer delay = (T4 - T1) - (T3 - T2)
     */

    uint8_t index = 0;
    uint64_t T3_T2_diff = 0;
    uint64_t T4_T1_diff = 0;

    uint64_t correctionFieldSum = 0;

    uint32_t sharedRAMbaseAddress = (((ICSS_EmacHwAttrs *)
                                      (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr;

    index = portNum - 1;

    /*compute T4 - T1. Time difference on our device, take care of wrap around
     *Only nanoseconds used. Assumption is that transaction is completed within a second */

    if(timeSyncHandle->pDelayParams[index].T4Nsec <
            timeSyncHandle->pDelayParams[index].T1Nsec)
    {
        T4_T1_diff = ((uint64_t)SEC_TO_NS + (uint64_t)
                      timeSyncHandle->pDelayParams[index].T4Nsec)
                     - (uint64_t)timeSyncHandle->pDelayParams[index].T1Nsec;
    }

    else
    {
        T4_T1_diff = timeSyncHandle->pDelayParams[index].T4Nsec -
                     timeSyncHandle->pDelayParams[index].T1Nsec;
    }

    /*Multiply device time with NRR*/
    T4_T1_diff = (uint32_t)((double)T4_T1_diff *
                            timeSyncHandle->tsNrrInfo[index]->nrr);

    /*Special processing if 2-step*/
    if(twoStep == 1)
    {

        /*compute T3-T2*. Time difference on Peer*/
        if(timeSyncHandle->pDelayParams[index].T3Nsec <
                timeSyncHandle->pDelayParams[index].T2Nsec)
        {
            T3_T2_diff = ((uint64_t)SEC_TO_NS +
                          (uint64_t)timeSyncHandle->pDelayParams[index].T3Nsec) -
                         (uint64_t)timeSyncHandle->pDelayParams[index].T2Nsec;
        }

        else
        {
            T3_T2_diff = timeSyncHandle->pDelayParams[index].T3Nsec -
                         timeSyncHandle->pDelayParams[index].T2Nsec;
        }

        /*Compute sum of correction fields*/
        correctionFieldSum = timeSyncHandle->pDelayParams[index].delayResCorrField +
                             timeSyncHandle->pDelayParams[index].delayResFwUpCorrField;

        if(T4_T1_diff >= (T3_T2_diff + correctionFieldSum))
        {
            timeSyncHandle->tsRunTimeVar->meanPathDelay = T4_T1_diff - T3_T2_diff -
                    correctionFieldSum;
            /*Average the delay*/
            timeSyncHandle->tsRunTimeVar->meanPathDelay >>= 1;
        }

        else
        {
            timeSyncHandle->tsRunTimeVar->meanPathDelay = 0;
        }

    }

    else
    {
        /*compute T3-T2*. Time difference on Peer*/
        T3_T2_diff =  timeSyncHandle->pDelayParams[index].delayResCorrField;

        if(T4_T1_diff > T3_T2_diff)
        {
            timeSyncHandle->tsRunTimeVar->meanPathDelay = T4_T1_diff - T3_T2_diff;
            /*Average the delay*/
            timeSyncHandle->tsRunTimeVar->meanPathDelay >>= 1;
        }

        else
        {
            timeSyncHandle->tsRunTimeVar->meanPathDelay = 0;
        }

    }

    if(timeSyncHandle->tsRunTimeVar->meanPathDelay >
            TIMESYNC_PEER_DELAY_ERROR_THRESHOLD)
    {
        timeSyncHandle->tsRunTimeVar->meanPathDelay = 0;
    }

    if((timeSyncHandle->tsRunTimeVar->stateMachine &
            TS_STATE_MACHINE_LINE_DELAY_COMPUTED) == 0)
    {
        timeSyncHandle->tsRunTimeVar->pathDelay[index] =
            timeSyncHandle->tsRunTimeVar->meanPathDelay;

        /*Once delay has been computed notify the state machine*/
        timeSyncHandle->tsRunTimeVar->stateMachine |=
            TS_STATE_MACHINE_LINE_DELAY_COMPUTED;
    }

    else
    {
        /*Use exponential averaging filter to get the peer delay*/
        timeSyncHandle->tsRunTimeVar->pathDelay[index] =
            (uint32_t)((double)timeSyncHandle->tsRunTimeVar->pathDelay[index] *
                       (double)FILTER_ALPHA_COEFF + \
                       (double)timeSyncHandle->tsRunTimeVar->meanPathDelay * (double)(
                           1 - FILTER_ALPHA_COEFF));
    }

    if(ICSS_EMAC_PORT_1 == portNum)
    {
        bytePtr = (uint8_t *)(sharedRAMbaseAddress + P1_SMA_LINE_DELAY_OFFSET);
    }

    else
    {
        bytePtr = (uint8_t *)(sharedRAMbaseAddress + P2_SMA_LINE_DELAY_OFFSET);
    }

    /*For 1-step TC delay asymmetry also gets added to the Sync frame correction
     * This is done by adding it to the path delay written in shared RAM*/
    timeSyncHandle->tsRunTimeVar->pathDelay[index] +=
        timeSyncHandle->timeSyncConfig.asymmetryCorrection[index];

    memcpy(bytePtr, &(timeSyncHandle->tsRunTimeVar->pathDelay[index]), 4);

}

int8_t TimeSync_processTimeOfDay(TimeSync_ParamsHandle_t timeSyncHandle,
                                 uint32_t nanoseconds, uint64_t seconds)
{
    uint8_t *bytePtr = NULL;
    uint64_t doubleWord = 0;

    ICSS_EmacBaseAddressHandle_T emacBaseAddr = ((ICSS_EmacHwAttrs *)(
                timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg;

    if(timeSyncHandle == NULL)
    {
        return TIME_SYNC_HANDLE_NOT_INITIALIZED;
    }

    if(!timeSyncHandle->timeSyncConfig.process_TOD_and_sync_2_1PPS)
    {
        return TIME_SYNC_FEATURE_NOT_ENABLED;
    }

    timeSyncHandle->tsToDParams->ToD_Ts_Sec = seconds;
    timeSyncHandle->tsToDParams->ToD_Ts_NS = nanoseconds;

    if((timeSyncHandle->tsRunTimeVar->stateMachine &
            TS_STATE_MACHINE_FIRST_ADJUSTMENT_DONE) == 0)
    {
        /*write value as it is*/
        /*Get origin time stamp in 64 bit format*/
        doubleWord = seconds * (uint64_t)SEC_TO_NS + (uint64_t)nanoseconds;

        bytePtr = (uint8_t *)((uint32_t)(emacBaseAddr->prussIepRegs +
                                         CSL_ICSSIEP_COUNT_REG0));
        memcpy(bytePtr, &doubleWord, 8);

        /*Reset IEP*/
        TimeSync_resetIEP(timeSyncHandle);

        /*Indicate that first adjustment is done*/
        timeSyncHandle->tsRunTimeVar->stateMachine |=
            TS_STATE_MACHINE_FIRST_ADJUSTMENT_DONE;
    }

    return TIME_SYNC_OK;
}

void TimeSync_synchronizeToD(TimeSync_ParamsHandle_t timeSyncHandle)
{
    uint8_t *bytePtr = NULL;
    uint64_t latch0TS = 0;
    uint64_t doubleWord = 0;
    uint64_t expected_value_ToD_seconds = 0;
    int32_t offset = 0;

    ICSS_EmacBaseAddressHandle_T emacBaseAddr = ((ICSS_EmacHwAttrs *)(
                timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg;

    /*Calculate 64-bit latch and expected time of day timestamp*/

    latch0TS = (uint64_t)timeSyncHandle->tsToDParams->latch_Ts_Sec *
               (uint64_t)SEC_TO_NS
               + timeSyncHandle->tsToDParams->latch_Ts_NS;

    expected_value_ToD_seconds = (uint64_t)(timeSyncHandle->tsToDParams->ToD_Ts_Sec
                                            + 1) * (uint64_t)SEC_TO_NS;

    /*Do a finer adjustment the first time we get a latch after
     * first adjustment is complete*/
    if((timeSyncHandle->tsRunTimeVar->stateMachine &
            TS_STATE_MACHINE_FIRST_ADJUSTMENT_DONE) ==
            TS_STATE_MACHINE_FIRST_ADJUSTMENT_DONE)
    {
        /*Get the current IEP value to get the ISR delay*/
        bytePtr = (uint8_t *)(uint32_t)(emacBaseAddr->prussIepRegs +
                                        CSL_ICSSIEP_COUNT_REG0);
        memcpy(&doubleWord, bytePtr, 8);

        /*The ISR delay is current IEP count minus the latch timestamp*/
        offset =  doubleWord - latch0TS;
        /*
          * The expected value of time stamp is the seconds value that was previously received
          * and a nanoseconds value of 0
         */
        doubleWord = expected_value_ToD_seconds + offset;

        /*Update the IEP counter with the more accurate value*/
        memcpy(bytePtr, &doubleWord, 8);

        /*Line delay is irrelevant here*/
        timeSyncHandle->tsRunTimeVar->stateMachine |=
            TS_STATE_MACHINE_LINE_DELAY_COMPUTED;

    }

    /*Do synchronization when all parameters are available*/
    if((timeSyncHandle->tsRunTimeVar->stateMachine &
            TS_STATE_MACHINE_READY_FOR_SYNC) == TS_STATE_MACHINE_READY_FOR_SYNC)
    {
        /*
         * The expected value of time stamp is the seconds value that was previously received
         * plus 1 and a nanoseconds value of 0
         */
        timeSyncHandle->tsRunTimeVar->currOffset = latch0TS -
                expected_value_ToD_seconds;

        if(timeSyncHandle->tsRunTimeVar->ltaOffset != 0)
        {
            timeSyncHandle->tsRunTimeVar->ltaOffset = (int32_t)((double)(
                        FILTER_ALPHA_COEFF_TOD) *
                    (double)timeSyncHandle->tsRunTimeVar->ltaOffset + (double)(
                        1 - FILTER_ALPHA_COEFF_TOD) *
                    (double)timeSyncHandle->tsRunTimeVar->currOffset);
        }

        else
        {
            timeSyncHandle->tsRunTimeVar->ltaOffset =
                timeSyncHandle->tsRunTimeVar->currOffset;
        }


        if(timeSyncHandle->tsRunTimeVar->driftStable)
        {
            offset = timeSyncHandle->tsRunTimeVar->ltaOffset  +
                     2 * timeSyncHandle->tsRunTimeVar->initialOffset;
        }

        else
        {
            offset = timeSyncHandle->tsRunTimeVar->ltaOffset;
        }

        offset = timeSyncHandle->tsRunTimeVar->ltaOffset;

#if defined(SOC_AM335x) || defined (SOC_AM437x)
        /*Do adjustment*/
        if(V1 == timeSyncHandle->timeSyncConfig.icssVersion)
        {
            TimeSync_adjTimeEcapEdma(timeSyncHandle, offset);
        }

        else
#else
        {
            TimeSync_adjTimeSlowComp(timeSyncHandle, offset);
        }
#endif

        /*Check this condition only if device is in sync*/
        if((timeSyncHandle->tsRunTimeVar->stateMachine &
                TS_STATE_MACHINE_DEVICE_IN_SYNC) ==
                TS_STATE_MACHINE_DEVICE_IN_SYNC)
        {

            /*This is to track any large change in the timebase*/
            if(abs(timeSyncHandle->tsRunTimeVar->currOffset) > OFFSET_THRESHOLD_FOR_RESET)
            {
                /*Reset state machine*/
                TimeSync_reset(timeSyncHandle);
                return;
            }
        }


        /*The code below is part of Statistics collection
         * some of which is used to implement the stabilization algo
         */

        /*Find clock drift*/
        if(timeSyncHandle->tsRunTimeVar->prevOffset != 0)
        {
            timeSyncHandle->tsRunTimeVar->clockDrift += abs(
                        timeSyncHandle->tsRunTimeVar->currOffset -
                        timeSyncHandle->tsRunTimeVar->prevOffset);
            timeSyncHandle->tsRunTimeVar->clockDrift =
                timeSyncHandle->tsRunTimeVar->clockDrift / 2;
        }

        /*set prevoffset to current once drift is computed*/
        timeSyncHandle->tsRunTimeVar->prevOffset =
            timeSyncHandle->tsRunTimeVar->currOffset;

        /*Wait for the drift to stabilize*/
        if(timeSyncHandle->tsRunTimeVar->clockDrift <= STABLE_FILTER_THRESHOLD
                && (timeSyncHandle->tsRunTimeVar->driftStable == 0))
        {
            timeSyncHandle->tsRunTimeVar->driftStable = 1;
            timeSyncHandle->tsRunTimeVar->initialOffset =
                timeSyncHandle->tsRunTimeVar->currOffset;
        }

        /*Wait for offset to become zero*/
        if(abs(timeSyncHandle->tsRunTimeVar->ltaOffset) <= STABLE_FILTER_THRESHOLD
                && (timeSyncHandle->tsRunTimeVar->offsetStable == 0) &&
                (timeSyncHandle->tsRunTimeVar->driftStable))
        {
            timeSyncHandle->tsRunTimeVar->offsetStable = 1;
            /*Indicate that the device is in sync now*/
            timeSyncHandle->tsRunTimeVar->stateMachine |= TS_STATE_MACHINE_DEVICE_IN_SYNC;
        }
    }
}

void TimeSync_synchronizeClock(TimeSync_ParamsHandle_t timeSyncHandle)
{
    uint8_t syncPortNum = 0;
    uint32_t meanPathDelay = 0;
    int64_t tempVar1 = 0;
    int64_t tempVar2 = 0;
    int32_t adjOffset = 0;

    syncPortNum = timeSyncHandle->tsRunTimeVar->syncPortNum - 1;
    /*Once initial adjustment is done, calculate the offset*/
    /*Get mean path delay*/
    meanPathDelay =
        timeSyncHandle->tsRunTimeVar->pathDelay[syncPortNum];

    if(timeSyncHandle->syncParam[syncPortNum]->originTsSec ==
            timeSyncHandle->syncParam[syncPortNum]->rxTsSec)
    {
        timeSyncHandle->tsRunTimeVar->currOffset =
            timeSyncHandle->syncParam[syncPortNum]->rxTs -
            timeSyncHandle->syncParam[syncPortNum]->originTsNs - \
            meanPathDelay - timeSyncHandle->syncParam[syncPortNum]->correctionField;
    }

    else
    {
        tempVar1 = ((int64_t)timeSyncHandle->syncParam[syncPortNum]->rxTsSec - (int64_t)
                    timeSyncHandle->syncParam[syncPortNum]->originTsSec) \
                   * (int64_t)SEC_TO_NS;
        tempVar1 += (int64_t)timeSyncHandle->syncParam[syncPortNum]->rxTs;
        tempVar2 = (int64_t)(timeSyncHandle->syncParam[syncPortNum]->originTsNs +
                             meanPathDelay +
                             timeSyncHandle->syncParam[syncPortNum]->correctionField);

        timeSyncHandle->tsRunTimeVar->currOffset = (int32_t)(tempVar1 - tempVar2);

    }

    /*Take running average of the offset*/
    timeSyncHandle->tsRunTimeVar->ltaOffset = (int32_t)((double)(
                FILTER_ALPHA_COEFF) *
            (double)timeSyncHandle->tsRunTimeVar->ltaOffset + (double)(
                1 - FILTER_ALPHA_COEFF) *
            (double)timeSyncHandle->tsRunTimeVar->currOffset);

    if(timeSyncHandle->tsRunTimeVar->driftStable)
    {
        adjOffset = timeSyncHandle->tsRunTimeVar->currOffset +
                    timeSyncHandle->tsRunTimeVar->ltaOffset  +
                    timeSyncHandle->tsRunTimeVar->initialOffset;
    }

    else
    {
        adjOffset = timeSyncHandle->tsRunTimeVar->currOffset;
    }

#if defined(SOC_AM335x) || defined (SOC_AM437x)
    /*Do adjustment*/
    if(V1 == timeSyncHandle->timeSyncConfig.icssVersion)
    {
        TimeSync_adjTimeEcapEdma(timeSyncHandle, adjOffset);
    }
    else
#else
    {
        TimeSync_adjTimeSlowComp(timeSyncHandle, adjOffset);
    }
#endif
    /*Check this condition only if device is in sync*/
    if((timeSyncHandle->tsRunTimeVar->stateMachine &
            TS_STATE_MACHINE_DEVICE_IN_SYNC) ==
            TS_STATE_MACHINE_DEVICE_IN_SYNC)
    {

        /*This is to track any large change in the timebase*/
        if(abs(timeSyncHandle->tsRunTimeVar->currOffset) > OFFSET_THRESHOLD_FOR_RESET)
        {
            /*Reset state machine*/
            TimeSync_reset(timeSyncHandle);
            return;
        }
    }


    /*The code below is part of Statistics collection
     * some of which is used to implement the stabilization algo
     */

    /*Find clock drift*/
    if(timeSyncHandle->tsRunTimeVar->prevOffset != 0)
    {
        timeSyncHandle->tsRunTimeVar->clockDrift += abs(
                    timeSyncHandle->tsRunTimeVar->currOffset -
                    timeSyncHandle->tsRunTimeVar->prevOffset);
        timeSyncHandle->tsRunTimeVar->clockDrift =
            timeSyncHandle->tsRunTimeVar->clockDrift / 2;
    }

    /*set prevoffset to current once drift is computed*/
    timeSyncHandle->tsRunTimeVar->prevOffset =
        timeSyncHandle->tsRunTimeVar->currOffset;

    /*Wait for the drift to stabilize*/
    if(timeSyncHandle->tsRunTimeVar->clockDrift <= STABLE_FILTER_THRESHOLD
            && (timeSyncHandle->tsRunTimeVar->driftStable == 0))
    {
        timeSyncHandle->tsRunTimeVar->driftStable = 1;
        timeSyncHandle->tsRunTimeVar->initialOffset =
            timeSyncHandle->tsRunTimeVar->currOffset;
    }

    /*Wait for offset to become zero*/
    if(abs(timeSyncHandle->tsRunTimeVar->ltaOffset) <= STABLE_FILTER_THRESHOLD
            && (timeSyncHandle->tsRunTimeVar->offsetStable == 0) &&
            (timeSyncHandle->tsRunTimeVar->driftStable))
    {
        timeSyncHandle->tsRunTimeVar->offsetStable = 1;
        /*Indicate that the device is in sync now*/
        timeSyncHandle->tsRunTimeVar->stateMachine |= TS_STATE_MACHINE_DEVICE_IN_SYNC;
    }

    /*The stabilization logic collects offsets which have a low drift and are
     * clustered together. The idea is that the PPM of the crystal might have shifted
     * and since we are relying on the initial offset measurement to do zero offset correction
     * we need to constantly track this zero offset value or else the PPM might settle into a zone
     * with high value and low drift.
     *
     * To take an example let's say we sync to a master with a fixed offset of 1000 ns.
     * The DUT as a slave will detect this value in the variable timeSyncHandle->tsRunTimeVar->initialOffset
     * After some time, let's say this offset has become 1100 ns. In the absence of this logic the
     * slave will settle into a zone with 100ns offset. If later the offset becomes 1200 ns then DUT
     * will settle into a zone with 200ns offset*/

    /*Run the logic only once we are stable*/
    if(timeSyncHandle->tsRunTimeVar->offsetStable)
    {
        timeSyncHandle->offsetAlgo->lastSeen_good_drift_index++;

        /*If the drift is below our threshold and we have a close cluster
         * then we use this value for our averaging purpose
         */
        if((timeSyncHandle->tsRunTimeVar->clockDrift <
                timeSyncHandle->offsetAlgo->driftThreshold)
                && (timeSyncHandle->offsetAlgo->lastSeen_good_drift_index <
                    OFFSET_ALGO_CLUSTER_SIZE))
        {
            timeSyncHandle->offsetAlgo->lastSeen_good_drift_index = 0;

            if(timeSyncHandle->offsetAlgo->num_entries_index < OFFSET_ALGO_BIN_SIZE)
            {
                /*Store the value for averaging later*/
                timeSyncHandle->offsetAlgo->correction[timeSyncHandle->offsetAlgo->num_entries_index++]
                    =  timeSyncHandle->tsRunTimeVar->currOffset;
            }

            else
            {
                timeSyncHandle->offsetAlgo->binFull = 1;
            }

        }

        /*If cluster is broken then we reset the counters*/
        else if((timeSyncHandle->offsetAlgo->lastSeen_good_drift_index >=
                 OFFSET_ALGO_CLUSTER_SIZE)
                && (timeSyncHandle->offsetAlgo->binFull != 1))
        {
            /*reset the count if we can't find a good match in our window*/
            timeSyncHandle->offsetAlgo->lastSeen_good_drift_index = 0;
            timeSyncHandle->offsetAlgo->num_entries_index = 0;
        }
    }


}

void TimeSync_updateNRRParams(TimeSync_ParamsHandle_t timeSyncHandle,
                              uint8_t portNum)
{

    uint8_t curIndex = 0;

    timeSync_NrrInfo_t *nrrInfo = NULL;
    /*point to the nrr for correct port*/
    nrrInfo = timeSyncHandle->tsNrrInfo[portNum - 1];

    curIndex = (nrrInfo->nrrIndex++) % 3;

    /*Please note that the RCF calculated here is inverse of the RCF described in spec
     * This is because we multiply our time adjustments with this value
     */
    if(curIndex == SYNT_DEPTH)
    {
        curIndex = 0;
    }

    /*This is used later*/
    nrrInfo->curIndex = curIndex;

    /*Populate the array with TS*/
    nrrInfo->deviceRxTS[curIndex] = (uint64_t)
                                    timeSyncHandle->pDelayParams[portNum - 1].T4Sec *
                                    (uint64_t)SEC_TO_NS + timeSyncHandle->pDelayParams[portNum - 1].T4Nsec;

    nrrInfo->correctedPeerTS[curIndex] = \
                                         (uint64_t)timeSyncHandle->pDelayParams[portNum - 1].T3Sec * (uint64_t)SEC_TO_NS
                                         + timeSyncHandle->pDelayParams[portNum - 1].T3Nsec +
                                         timeSyncHandle->tsRunTimeVar->pathDelay[portNum - 1] +
                                         timeSyncHandle->pDelayParams[portNum - 1].delayResCorrField + \
                                         timeSyncHandle->pDelayParams[portNum - 1].delayResFwUpCorrField;

    /*Wait for TS array to be full before starting syntonization*/
    if((!nrrInfo->nrrEnable)
            && (nrrInfo->nrrIndex == (SYNT_DEPTH + 2)))
    {
        nrrInfo->nrrEnable = 1;
    }

}

void TimeSync_calcNRR(TimeSync_ParamsHandle_t timeSyncHandle, uint8_t portNum)
{
    uint64_t num = 0;
    uint64_t den = 0;

    uint8_t curIndex = 0;
    uint8_t prevIndex = 0;

    timeSync_NrrInfo_t *nrrInfo = NULL;
    /*point to the nrr for correct port*/
    nrrInfo = timeSyncHandle->tsNrrInfo[portNum - 1];

    curIndex = nrrInfo->curIndex;

    /*calculate nrr */
    if(nrrInfo->nrrEnable)
    {
        prevIndex = timeSyncHandle->syntIndexMap[curIndex];
        num = nrrInfo->correctedPeerTS[curIndex] -
              nrrInfo->correctedPeerTS[prevIndex];

        den = nrrInfo->deviceRxTS[curIndex] -
              nrrInfo->deviceRxTS[prevIndex];

        /*calculate rcf*/
        nrrInfo->nrr = ((double)num) / den;

    }
}

void TimeSync_calcSyncInterval_ToD(TimeSync_ParamsHandle_t timeSyncHandle)
{
    uint8_t curIndex = 0;
    uint8_t prevIndex = 0;
    uint8_t tempIndex = 0;
    uint8_t count = 0;

    uint64_t syncIntervalAverage = 0;

    if((timeSyncHandle->tsRunTimeVar->stateMachine &
            TS_STATE_MACHINE_LINE_DELAY_COMPUTED) !=
            TS_STATE_MACHINE_LINE_DELAY_COMPUTED)
    {
        return;
    }

    curIndex = (timeSyncHandle->tsSyntInfo->syntIndex++) % 3;

    /*Please note that the RCF calculated here is inverse of the RCF described in spec
     * This is because we multiply our time adjustments with this value
     */
    if(curIndex == SYNT_DEPTH)
    {
        curIndex = 0;
    }

    timeSyncHandle->tsSyntInfo->correctedMasterTs[curIndex] = \
            (uint64_t)timeSyncHandle->tsToDParams->latch_Ts_Sec *
            (uint64_t)SEC_TO_NS
            + timeSyncHandle->tsToDParams->latch_Ts_NS;

    /*Wait for TS array to be full before starting syntonization*/
    if((!timeSyncHandle->tsSyntInfo->syntEnable)
            && (timeSyncHandle->tsSyntInfo->syntIndex == (SYNT_DEPTH + 2)))
    {
        timeSyncHandle->tsSyntInfo->syntEnable = 1;
    }

    /*calculate pulse interval */
    if(timeSyncHandle->tsSyntInfo->syntEnable)
    {
        prevIndex = timeSyncHandle->syntIndexMap[curIndex];

        /*calculate average of difference between two successive sync frames*/
        for(count = 0; count < 3; count++)
        {
            tempIndex = (curIndex + count) % SYNT_DEPTH;
            prevIndex = timeSyncHandle->prevIndexMap[tempIndex];

            if(timeSyncHandle->tsSyntInfo->correctedMasterTs[tempIndex] >
                    timeSyncHandle->tsSyntInfo->correctedMasterTs[prevIndex])
            {
                syncIntervalAverage += (timeSyncHandle->tsSyntInfo->correctedMasterTs[tempIndex]
                                        -
                                        timeSyncHandle->tsSyntInfo->correctedMasterTs[prevIndex]);
            }
        }

        syncIntervalAverage = syncIntervalAverage / 2;

        timeSyncHandle->tsRunTimeVar->currSyncInterval = syncIntervalAverage;

        if(timeSyncHandle->tsRunTimeVar->ltaSyncInterval == 0)
        {
            timeSyncHandle->tsRunTimeVar->ltaSyncInterval =
                timeSyncHandle->tsRunTimeVar->currSyncInterval;
        }

        else
        {
            timeSyncHandle->tsRunTimeVar->ltaSyncInterval =
                (uint32_t)(((double)(timeSyncHandle->tsRunTimeVar->ltaSyncInterval) *
                            FILTER_ALPHA_COEFF) \
                           + ((double)(1 - FILTER_ALPHA_COEFF) * (double)(
                                  timeSyncHandle->tsRunTimeVar->currSyncInterval)));

        }

        timeSyncHandle->tsRunTimeVar->ltaSyncInterval = SEC_TO_NS;
        timeSyncHandle->syncInterval = timeSyncHandle->tsRunTimeVar->ltaSyncInterval;

        /*Once sync interval has been calculated notify the state machine*/
        timeSyncHandle->tsRunTimeVar->stateMachine |=
            TS_STATE_MACHINE_SYNC_INTERVAL_COMPUTED;

    }
}

void TimeSync_calcRcfAndSyncInterval(TimeSync_ParamsHandle_t timeSyncHandle)
{

    uint64_t num = 0;
    uint64_t den = 0;
    uint32_t scaledRCF = 0;
    uint8_t *ptrScaledRcf = NULL;

    uint8_t curIndex = 0;
    uint8_t prevIndex = 0;
    uint8_t tempIndex = 0;
    uint8_t count = 0;
    uint8_t syncPortNum = 0;

    uint64_t syncIntervalAverage = 0;

    double scalingFactor = 0;

    ptrScaledRcf = (uint8_t *)((((ICSS_EmacHwAttrs *)
                                 (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                               +  TIMESYNC_TC_RCF_OFFSET);

    curIndex = (timeSyncHandle->tsSyntInfo->syntIndex++) % 3;

    syncPortNum = timeSyncHandle->tsRunTimeVar->syncPortNum - 1;

    /*Please note that the RCF calculated here is inverse of the RCF described in spec
     * This is because we multiply our time adjustments with this value
     */
    if(curIndex == SYNT_DEPTH)
    {
        curIndex = 0;
    }

    /*Populate the array with TS*/
    timeSyncHandle->tsSyntInfo->syncIngressTs[curIndex] = (uint64_t)
            timeSyncHandle->syncParam[syncPortNum]->rxTsSec *
            (uint64_t)SEC_TO_NS + timeSyncHandle->syncParam[syncPortNum]->rxTs;

    timeSyncHandle->tsSyntInfo->correctedMasterTs[curIndex] = \
            (uint64_t)timeSyncHandle->syncParam[syncPortNum]->originTsSec *
            (uint64_t)SEC_TO_NS
            + timeSyncHandle->syncParam[syncPortNum]->originTsNs +
            timeSyncHandle->tsRunTimeVar->pathDelay[timeSyncHandle->tsRunTimeVar->syncPortNum
                    - 1] +
            timeSyncHandle->syncParam[syncPortNum]->correctionField;

    /*Wait for TS array to be full before starting syntonization*/
    if((!timeSyncHandle->tsSyntInfo->syntEnable)
            && (timeSyncHandle->tsSyntInfo->syntIndex == (SYNT_DEPTH + 2)))
    {
        timeSyncHandle->tsSyntInfo->syntEnable = 1;
    }

    /*calculate rcf */
    if(timeSyncHandle->tsSyntInfo->syntEnable)
    {
        prevIndex = timeSyncHandle->syntIndexMap[curIndex];
        num = timeSyncHandle->tsSyntInfo->correctedMasterTs[curIndex] -
              timeSyncHandle->tsSyntInfo->correctedMasterTs[prevIndex];

        den = timeSyncHandle->tsSyntInfo->syncIngressTs[curIndex] -
              timeSyncHandle->tsSyntInfo->syncIngressTs[prevIndex];

        /*calculate rcf*/
        timeSyncHandle->tsSyntInfo->rcf = ((double)num) / den;
        scaledRCF = (uint32_t)(timeSyncHandle->tsSyntInfo->rcf * 1024);
        /* write into ICSS memory for firmware */
        memcpy(ptrScaledRcf, &scaledRCF, 4);

        /*calculate average of difference between two successive sync frames*/
        for(count = 0; count < 3; count++)
        {

            tempIndex = (curIndex + count) % SYNT_DEPTH;
            prevIndex = timeSyncHandle->prevIndexMap[tempIndex];

            if(timeSyncHandle->tsSyntInfo->correctedMasterTs[tempIndex] >
                    timeSyncHandle->tsSyntInfo->correctedMasterTs[prevIndex])
            {
                syncIntervalAverage += (timeSyncHandle->tsSyntInfo->correctedMasterTs[tempIndex]
                                        -
                                        timeSyncHandle->tsSyntInfo->correctedMasterTs[prevIndex]);
            }
        }

        syncIntervalAverage = syncIntervalAverage / 2;

        timeSyncHandle->tsRunTimeVar->currSyncInterval = syncIntervalAverage;

        if(timeSyncHandle->tsRunTimeVar->ltaSyncInterval == 0)
        {
            timeSyncHandle->tsRunTimeVar->ltaSyncInterval =
                timeSyncHandle->tsRunTimeVar->currSyncInterval;
            timeSyncHandle->tsRunTimeVar->firstSyncInterval =
                timeSyncHandle->tsRunTimeVar->currSyncInterval;

            /*Add 50% extra so minor variations in master don't cause a timeout*/
            timeSyncHandle->tsRunTimeVar->syncTimeoutInterval =
                timeSyncHandle->tsRunTimeVar->currSyncInterval;
            timeSyncHandle->tsRunTimeVar->syncTimeoutInterval +=
                timeSyncHandle->tsRunTimeVar->currSyncInterval >> 1;

            scalingFactor = ((double)1000 / (double)(
                                 timeSyncHandle->timeSyncConfig.tickPeriod));

            /*Multiply/Divide by clock scaling factor*/
            timeSyncHandle->tsRunTimeVar->syncTimeoutInterval =
                (uint32_t)((double)timeSyncHandle->tsRunTimeVar->syncTimeoutInterval *
                           scalingFactor);

            /*convert in terms of PTP BG ticks*/
            timeSyncHandle->tsRunTimeVar->syncTimeoutInterval =
                (uint32_t)((double)timeSyncHandle->tsRunTimeVar->syncTimeoutInterval / (double)(
                               PTP_BG_TASK_TICK_PERIOD * 1000000));

        }

        else
        {
            timeSyncHandle->tsRunTimeVar->ltaSyncInterval =
                (uint32_t)(((double)(timeSyncHandle->tsRunTimeVar->ltaSyncInterval) *
                            FILTER_ALPHA_COEFF) \
                           + ((double)(1 - FILTER_ALPHA_COEFF) * (double)(
                                  timeSyncHandle->tsRunTimeVar->currSyncInterval)));

        }

        timeSyncHandle->syncInterval = timeSyncHandle->tsRunTimeVar->ltaSyncInterval;

        /*Once sync interval has been calculated notify the state machine*/
        timeSyncHandle->tsRunTimeVar->stateMachine |=
            TS_STATE_MACHINE_SYNC_INTERVAL_COMPUTED;

    }

}

void TimeSync_processPTPFrame(TimeSync_ParamsHandle_t timeSyncHandle,
                              uint8_t *pktBuffer, \
                              uint8_t portNum, uint16_t size, uint8_t isLinkLocal)
{
    uint8_t pktType = 0;
    uint8_t ifTwoStep = 0;
    uint8_t offset = 0;
    uint8_t *bytePtr = 0;
    uint32_t nanoseconds = 0;
    uint64_t seconds = 0;

    offset = timeSyncHandle->timeSyncConfig.frame_offset;

    if(TRUE == timeSyncHandle->timeSyncConfig.hsrEnabled)
    {
        if(isLinkLocal)
        {
            /*Read the flag value from shared RAM*/
            bytePtr = (uint8_t *)((((ICSSEMAC_HwAttrs *)
                                    (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                                  + LINK_LOCAL_FRAME_HAS_HSR_TAG);
            timeSyncHandle->timeSyncConfig.ll_has_hsrTag = *bytePtr;

            if(timeSyncHandle->timeSyncConfig.ll_has_hsrTag)
            {
                offset -= HSR_CORRECTION;
            }
        }

        else
        {
            offset -= HSR_CORRECTION;
        }
    }


    pktType = (uint8_t)(*(pktBuffer + PTP_MSG_ID_OFFSET - offset));
    ifTwoStep = (uint8_t)(*(pktBuffer + PTP_FLAG_OFFSET - offset));
    ifTwoStep &= 2;

    /*If timestamp is appended to packet, copy them here*/
    if(!timeSyncHandle->timeSyncConfig.timestamp_from_shared_ram)
    {
        seconds = timeSyncHandle->rxTimestamp_gPTP->seconds;
        nanoseconds = timeSyncHandle->rxTimestamp_gPTP->nanoseconds;
    }

    /*PTPd stack handles announce and management messages*/
    if((PTP_ANNOUNCE_MSG_ID == pktType) || (PTP_MGMT_MSG_ID == pktType))
    {
        /*debug, remove in final code*/
        if(PTP_ANNOUNCE_MSG_ID == pktType)
        {
            /*Just parse the Announce frame for MAC ID
             * and make it master
             */
            TimeSync_dummyBMCA(timeSyncHandle, pktBuffer);
            return;
        }

        /*Should we use the port number???*/
        if(!(timeSyncHandle->stackParams.generalFrameFlag)) /*Make sure the previosn packet is trnasfered to PTP Stack*/
        {
            timeSyncHandle->stackParams.ptpGeneralSize = size;

            if(TRUE == timeSyncHandle->timeSyncConfig.hsrEnabled)
            {
                timeSyncHandle->stackParams.ptpGeneralSize -= HSR_CORRECTION;
                memcpy(timeSyncHandle->stackParams.ptpGeneralFrame, pktBuffer,
                       SRC_DST_MAC_SIZE);
                memcpy(timeSyncHandle->stackParams.ptpGeneralFrame + SRC_DST_MAC_SIZE,
                       pktBuffer + SRC_DST_MAC_SIZE + HSR_CORRECTION, \
                       timeSyncHandle->stackParams.ptpGeneralSize - SRC_DST_MAC_SIZE);
            }

            else
            {
                memcpy(timeSyncHandle->stackParams.ptpGeneralFrame, pktBuffer,
                       timeSyncHandle->stackParams.ptpGeneralSize);
            }

            timeSyncHandle->stackParams.generalFrameFlag = 1;
        }

    }

    else
    {
        if(PTP_PDLY_REQ_MSG_ID == pktType)         /*Pdelay request frame*/
        {
            if(timeSyncHandle->timeSyncConfig.timestamp_from_shared_ram)
            {
                TimeSync_getRxTimestamp(timeSyncHandle, DELAY_REQ_FRAME, portNum, \
                                        &nanoseconds, &seconds);
            }

            timeSyncHandle->pDelayParams[portNum - 1].pDelayReqRcvdTSSec =
                seconds;
            timeSyncHandle->pDelayParams[portNum - 1].pDelayReqRcvdTSNsec =
                nanoseconds;

            /*Copy into buffer and post event*/

            /*Remove HSR tag*/
            if(timeSyncHandle->timeSyncConfig.ll_has_hsrTag)
            {
                memcpy(timeSyncHandle->timeSyncBuff.pdelayReq_RxBuf[portNum - 1], pktBuffer,
                       SRC_DST_MAC_SIZE);
                memcpy(timeSyncHandle->timeSyncBuff.pdelayReq_RxBuf[portNum - 1] +
                       SRC_DST_MAC_SIZE,
                       pktBuffer + SRC_DST_MAC_SIZE + HSR_CORRECTION, \
                       TIMESYNC_PDELAY_BUF_SIZE - SRC_DST_MAC_SIZE);
            }

            else
            {
                memcpy(timeSyncHandle->timeSyncBuff.pdelayReq_RxBuf[portNum - 1],
                       pktBuffer, TIMESYNC_PDELAY_BUF_SIZE);
            }

            EventP_post(timeSyncHandle->ptpPdelayReqEvtHandle[portNum - 1],
                        timeSyncHandle->eventIdPdelayReq);
        }

        else if(PTP_PDLY_RSP_MSG_ID == pktType)         /*Pdelay response frame*/
        {
            if(timeSyncHandle->timeSyncConfig.timestamp_from_shared_ram)
            {
                TimeSync_getRxTimestamp(timeSyncHandle, DELAY_RESP_FRAME, portNum, \
                                        &nanoseconds, &seconds);
            }

            /*T4 timestamp*/
            timeSyncHandle->pDelayParams[portNum - 1].T4Sec =
                seconds;
            timeSyncHandle->pDelayParams[portNum - 1].T4Nsec =
                nanoseconds;

            /*set two step flag. Used in another task*/
            timeSyncHandle->pDelayParams[portNum - 1].ifTwoStep = ifTwoStep;

            if(timeSyncHandle->timeSyncConfig.ll_has_hsrTag)
            {
                memcpy(timeSyncHandle->timeSyncBuff.pdelayRes_RxBuf[portNum - 1],
                       pktBuffer,
                       SRC_DST_MAC_SIZE);
                memcpy(timeSyncHandle->timeSyncBuff.pdelayRes_RxBuf[portNum - 1] +
                       SRC_DST_MAC_SIZE,
                       pktBuffer + SRC_DST_MAC_SIZE + HSR_CORRECTION, \
                       TIMESYNC_PDELAY_BUF_SIZE - SRC_DST_MAC_SIZE);
            }

            else
            {
                /*Copy into buffer and post event*/
                memcpy(timeSyncHandle->timeSyncBuff.pdelayRes_RxBuf[portNum - 1],
                       pktBuffer, TIMESYNC_PDELAY_BUF_SIZE);
            }

            EventP_post(timeSyncHandle->ptpPdelayResEvtHandle[portNum - 1],
                        timeSyncHandle->eventIdPdelayResp);

            /*Another task pends on both Pdelay Resp and
             * Pdelay Resp Follow Up frame. If this is a single step
             * Pdelay response then we don't want that task to
             * pend forever
             */
            if(!ifTwoStep)
            {
                EventP_post(timeSyncHandle->ptpPdelayResEvtHandle[portNum - 1],
                            timeSyncHandle->eventIdPdelayRespFlwUp);
            }

        }

        else if(PTP_PDLY_RESP_FLW_UP_MSG_ID ==
                pktType)         /*Pdelay response follow up frame*/
        {
            /*Copy into buffer and post event*/
            if(timeSyncHandle->timeSyncConfig.ll_has_hsrTag)
            {
                memcpy(timeSyncHandle->timeSyncBuff.pdelayResFlwUp_RxBuf[portNum - 1],
                       pktBuffer,
                       SRC_DST_MAC_SIZE);
                memcpy(timeSyncHandle->timeSyncBuff.pdelayResFlwUp_RxBuf[portNum - 1] +
                       SRC_DST_MAC_SIZE,
                       pktBuffer + SRC_DST_MAC_SIZE + HSR_CORRECTION, \
                       TIMESYNC_PDELAY_BUF_SIZE - SRC_DST_MAC_SIZE);
            }

            else
            {
                memcpy(timeSyncHandle->timeSyncBuff.pdelayResFlwUp_RxBuf[portNum - 1],
                       pktBuffer, TIMESYNC_PDELAY_BUF_SIZE);
            }

            EventP_post(timeSyncHandle->ptpPdelayResEvtHandle[portNum - 1],
                        timeSyncHandle->eventIdPdelayRespFlwUp);
        }

        else if(PTP_SYNC_MSG_ID == pktType)
        {
            /*Get the timestamp. If it's in shared RAM, it's copied here, else
             * it's copied by the RT callback to the structure timeSyncHandle->rxTimestamp_gPTP
             */
            if(timeSyncHandle->timeSyncConfig.timestamp_from_shared_ram)
            {
                TimeSync_getRxTimestamp(timeSyncHandle, SYNC_FRAME, portNum, \
                                        &nanoseconds, &seconds);
            }

            /*Store Rx timestamp*/
            timeSyncHandle->syncParam[portNum - 1]->rxTsSec = seconds;
            timeSyncHandle->syncParam[portNum - 1]->rxTs = nanoseconds;


            /*set two step flag. Used in another task*/
            timeSyncHandle->syncParam[portNum - 1]->ifTwoStep = ifTwoStep;
            TimeSync_processSyncFrame(timeSyncHandle, pktBuffer, FALSE, portNum, size);
        }

        else if(PTP_FOLLOW_UP_MSG_ID == pktType)
        {
            TimeSync_processSyncFrame(timeSyncHandle, pktBuffer, TRUE, portNum, size);
        }

        else if(PTP_DLY_RESP_MSG_ID == pktType)   /*PTP_DLY_RSP_MSG_ID*/
        {
            TimeSync_processDelayResFrame(timeSyncHandle, pktBuffer, portNum);
        }

        else
        {
            return;
        }
    }

}

void TimeSync_processSyncFrame(TimeSync_ParamsHandle_t timeSyncHandle,
                               uint8_t *buff, \
                               uint8_t followUp, uint8_t portNum, uint16_t size)
{
    uint8_t *bytePtr =  NULL;
    uint8_t masterPortNum = 0;
    uint8_t oppPort = 0;
    uint8_t offset = 0;
    uint8_t oppPortlinkStatus = 0;
    uint16_t halfWord = 0;
    uint32_t sharedDataRamBaseAddr = 0;
    uint64_t doubleWord = 0;
    uint64_t followUpCorrectionField = 0;
    uint64_t timeElapsed = 0;

    ICSS_EmacTxArgument txArg;

    uint32_t quePri;

    /* Get the queue priority */
    if (portNum == ICSS_EMAC_PORT_1)
    {
        quePri = ICSS_EMAC_QUEUE1;
    }
    else
    {
        quePri = ICSS_EMAC_QUEUE3;
    }

    sharedDataRamBaseAddr = (((ICSSEMAC_HwAttrs *)
                              timeSyncHandle->emacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr;
    /*packet offset*/
    offset = timeSyncHandle->timeSyncConfig.frame_offset;

    /*Get the opposite port*/
    oppPort = ~portNum;
    oppPort &= 0x3;

    /*Opposite port link status*/
    oppPortlinkStatus = ((ICSS_EmacObject *)
                         (timeSyncHandle->emacHandle)->object)->linkStatus[oppPort - 1];

    /*Since we are processing tagged HSR frames, we need to account for it*/
    if(TRUE == timeSyncHandle->timeSyncConfig.hsrEnabled)
    {
        offset -= HSR_CORRECTION;
    }

    bytePtr = (uint8_t *)(sharedDataRamBaseAddr + MASTER_PORT_NUM_OFFSET);
    masterPortNum = *bytePtr;


    /*Take timestamps and calculate BD since this is common to sync
     * frames from both ports. Synchronization OTOH is done only for
     * sync frames from master port*/

    /*For sync frame*/
    if(!followUp)
    {
        if(masterPortNum == portNum)
        {
            timeSyncHandle->tsRunTimeVar->syncPortNum = portNum;
            /*Reset the last seen counter*/
            timeSyncHandle->tsRunTimeVar->syncLastSeenCounter = 0;
        }

        /*Copy correction field*/
        bytePtr = (uint8_t *)(buff + PTP_CORRECTION_OFFSET - offset);
        convEnd6to8(bytePtr, &(timeSyncHandle->syncParam[portNum -
                               1]->correctionField));

        /*Do asymmetry correction*/
        timeSyncHandle->syncParam[portNum - 1]->correctionField += \
                timeSyncHandle->timeSyncConfig.asymmetryCorrection[portNum - 1];

        /*Copy sequence ID*/
        bytePtr = (uint8_t *)(buff + PTP_SEQ_ID_OFFSET - offset);
        convEndianess(bytePtr, &(timeSyncHandle->tsRunTimeVar->curSyncSeqId[portNum -
                                 1]), 2);

        /*if forced mode is on and it's a 1-step then we send the frame out
         * of the opposite port after setting the 2-step bit*/
        if(!timeSyncHandle->syncParam[portNum - 1]->ifTwoStep &&
                timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TWO_STEP_INDEX] &&
                !timeSyncHandle->timeSyncConfig.emac_mode && oppPortlinkStatus)
        {
            timeSyncHandle->tsRunTimeVar->forced2step[portNum - 1] = TRUE;
            /*set 2-step bit*/
            bytePtr = (uint8_t *)((buff + PTP_FLAG_OFFSET - offset));
            *bytePtr |= 0x2;

            /*Create the follow up frame by changing the frame type field*/
            bytePtr = (uint8_t *)((buff + PTP_MSG_ID_OFFSET - offset));
            *bytePtr = PTP_FOLLOW_UP_MSG_ID;

            bytePtr = (uint8_t *)((buff + PTP_CONTROL_MSG_ID_OFFSET - offset));
            *bytePtr = PTP_FLW_UP_CTRL_MSG_ID;

            /*Strip the HSR tag before copying the follow up frame
              since we will add a different HSR tag*/
            if(timeSyncHandle->timeSyncConfig.hsrEnabled)
            {
                memcpy(timeSyncHandle->timeSyncBuff.followUp_TxBuf[portNum - 1], buff, 12);
                memcpy(timeSyncHandle->timeSyncBuff.followUp_TxBuf[portNum - 1] + 12, buff + 18,
                       size - 18);

            }

            else
            {
                memcpy(timeSyncHandle->timeSyncBuff.followUp_TxBuf[portNum - 1], buff, size);
            }

            /*Set event flag to indicate follow up frame generation*/
            EventP_post(timeSyncHandle->ptpSendFollowUpEvtHandle[portNum - 1],
                        timeSyncHandle->eventIdFlwUpGenerated);

        }

        else
        {
            timeSyncHandle->tsRunTimeVar->forced2step[portNum - 1] = FALSE;

        }

        if((timeSyncHandle->syncParam[portNum - 1]->ifTwoStep)
                || (masterPortNum != portNum))
        {
            return;
        }

        /*Get origin timestamp*/
        bytePtr = (uint8_t *)(buff + PTP_REQ_RCPT_TS_SEC_OFFSET - offset);
        convEnd6to8(bytePtr, &(timeSyncHandle->syncParam[portNum - 1]->originTsSec));

        bytePtr = (uint8_t *)(buff + PTP_REQ_RCPT_TS_NSEC_OFFSET -
                              offset);
        convEndianess(bytePtr, &(timeSyncHandle->syncParam[portNum - 1]->originTsNs),
                      4);



    }

    else
    {
        /*Check for Sync mismatch*/
        bytePtr = (uint8_t *)(buff + PTP_SEQ_ID_OFFSET - offset);
        convEndianess(bytePtr, &(halfWord), 2);

        if(timeSyncHandle->tsRunTimeVar->curSyncSeqId[portNum - 1] != halfWord)
        {
            return;
        }

        /*get correction field in follow up frame*/
        bytePtr = (uint8_t *)(buff + PTP_CORRECTION_OFFSET - offset);
        convEnd6to8(bytePtr, &(followUpCorrectionField));

        /*Correction field contains correction field value in sync frame
         * It needs to be added to the correction field value inside follow up*/
        timeSyncHandle->syncParam[portNum - 1]->correctionField += followUpCorrectionField;

        /*Get origin timestamp*/
        bytePtr = (uint8_t *)(buff + PTP_REQ_RCPT_TS_SEC_OFFSET - offset);
        convEnd6to8(bytePtr, &(timeSyncHandle->syncParam[portNum - 1]->originTsSec));

        bytePtr = (uint8_t *)(buff + PTP_REQ_RCPT_TS_NSEC_OFFSET -
                              offset);
        convEndianess(bytePtr, &(timeSyncHandle->syncParam[portNum - 1]->originTsNs),
                      4);


        /*---If link is up on opposite port then
         * calculate Bridge delay and send out follow up frame---*/

        /*If PTP is configured in EMAC mode then don't do Bridge delay computation*/
        if(!timeSyncHandle->timeSyncConfig.emac_mode)
        {

            if(oppPortlinkStatus)
            {
                doubleWord = timeSyncHandle->syncParam[portNum - 1]->txTsSec *
                             (uint64_t)SEC_TO_NS + \
                             timeSyncHandle->syncParam[portNum - 1]->txTs;
                timeElapsed = timeSyncHandle->syncParam[portNum - 1]->rxTsSec *
                              (uint64_t)SEC_TO_NS + \
                              timeSyncHandle->syncParam[portNum - 1]->rxTs;
                /*This is the BD or bridge delay*/
                timeElapsed = doubleWord - timeElapsed;

                /*Multiply BD with RCF. For 802.1 AB this should be the accumulated rate ratio*/
                timeElapsed = (uint32_t)((double)timeElapsed * timeSyncHandle->tsSyntInfo->rcf);

                /*Add Peer delay for P2P mode*/
                if(P2P == timeSyncHandle->timeSyncConfig.type)
                {
                    timeElapsed += timeSyncHandle->tsRunTimeVar->pathDelay[portNum - 1];
                }

                /*Finally add the BD to existing correction field*/
                timeElapsed += followUpCorrectionField;

                /*timeElapsed now contains the corrected BD.
                * Encode into frame and send out*/
                convEndianess(&timeElapsed,
                              (buff + PTP_CORRECTION_OFFSET - offset), 6);

                if(timeSyncHandle->timeSyncConfig.custom_tx_api)
                {
                    txArg.icssEmacHandle = timeSyncHandle->emacHandle;
                    txArg.lengthOfPacket = size;
                    txArg.portNumber = oppPort;
                    txArg.queuePriority = quePri;
                    txArg.srcAddress = buff;

                    ((((ICSS_EmacObject *)
                       timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->callBack(
                           &txArg,
                           ((((ICSS_EmacObject *)
                              timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->userArg);

                }

                else
                {
                    ICSS_EmacTxPacketEnqueue(timeSyncHandle->emacHandle, buff, oppPort,
                                             quePri, size);

                }
            }
        }

    }



    /*First time*/
    if((timeSyncHandle->tsRunTimeVar->stateMachine &
            TS_STATE_MACHINE_FIRST_ADJUSTMENT_DONE) == 0)
    {

        /* Check to make sure we don't latch on to a sync message before we
           select the master */
        if (timeSyncHandle->tsRunTimeVar->bmcaDone == 1)
        {
            /*Do first adjustment or copying of timestamp directly into IEP*/
            TimeSync_doFirstAdjustment(timeSyncHandle, portNum);

            /*indicate that first adjustment is done*/
            timeSyncHandle->tsRunTimeVar->stateMachine |=
                TS_STATE_MACHINE_FIRST_ADJUSTMENT_DONE;
        }
    }

    else    /*if not first time sync frame*/
    {
        if(timeSyncHandle->tsRunTimeVar->syncPortNum == portNum)
        {
            if((timeSyncHandle->tsRunTimeVar->stateMachine &
                    TS_STATE_MACHINE_READY_FOR_SYNC) == TS_STATE_MACHINE_READY_FOR_SYNC)
            {
                /*Synchronize clock*/
                TimeSync_synchronizeClock(timeSyncHandle);
            }

        }

    }

    if(timeSyncHandle->tsRunTimeVar->syncPortNum == portNum)
    {
        /*Post interrupt to send a delay request frame*/
        if(timeSyncHandle->timeSyncConfig.type == E2E)
        {
            SemaphoreP_post(timeSyncHandle->delayReqTxSemHandle);
        }

        TimeSync_calcRcfAndSyncInterval(timeSyncHandle);
    }

}

void TimeSync_processDelayResFrame(TimeSync_ParamsHandle_t timeSyncHandle,
                                   uint8_t *buff, \
                                   uint8_t portNum)
{
    uint8_t *bytePtr = NULL;
    uint16_t halfWord = 0;
    uint8_t offset = timeSyncHandle->timeSyncConfig.frame_offset;

    /*check if the delay response has the correct sequence ID*/
    bytePtr = (uint8_t *)(buff + PTP_SEQ_ID_OFFSET - offset);
    convEndianess(bytePtr, &(halfWord), 2);

    if((timeSyncHandle->tsRunTimeVar->delReqSequenceID - 1) != halfWord)
    {
        return;
    }

    /*Get the correction field*/
    bytePtr = (uint8_t *)(buff + PTP_CORRECTION_OFFSET - offset);
    convEnd6to8(bytePtr, &(timeSyncHandle->delayParams->correctionField));

    /*Get origin timestamp and calculate line delay*/
    bytePtr = (uint8_t *)(buff + PTP_REQ_RCPT_TS_SEC_OFFSET - offset);
    convEnd6to8(bytePtr, &(timeSyncHandle->delayParams->timeStampSec));

    bytePtr = (uint8_t *)(buff + PTP_REQ_RCPT_TS_NSEC_OFFSET -
                          offset);
    convEndianess(bytePtr, &(timeSyncHandle->delayParams->timeStampNS),
                  4);

    /*We have all the data now, calculate the line delay*/
    TimeSync_lineDelayCalc(timeSyncHandle);
}

void TimeSync_processPdelayReqFrame(TimeSync_ParamsHandle_t timeSyncHandle,
                                    uint8_t *buff, \
                                    uint8_t portNum)
{
    /*Copy contents and echo back on the same port*/
    uint8_t *ptpPDelayResPacket = NULL;
    uint8_t *ptpPDelayResFlwUpPacket = NULL;
    uint8_t *bytePtrSrc =  NULL;
    uint8_t *bytePtrPdelReq = NULL;
    uint8_t *bytePtrPdelRes = NULL;
    uint8_t offset = timeSyncHandle->timeSyncConfig.frame_offset;

    ICSS_EmacTxArgument txArg;

    uint32_t quePri;

    /* Get the queue priority */
    if (portNum == ICSS_EMAC_PORT_1)
    {
        quePri = ICSS_EMAC_QUEUE1;
    }
    else
    {
        quePri = ICSS_EMAC_QUEUE3;
    }

    if(ICSS_EMAC_PORT_1 == portNum)
    {
        ptpPDelayResPacket = timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[0];
        ptpPDelayResFlwUpPacket = timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[0];
    }

    else
    {
        ptpPDelayResPacket = timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[1];
        ptpPDelayResFlwUpPacket = timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[1];
    }

    /*Add Request port clock Identity*/
    bytePtrSrc = (uint8_t *)(buff + PTP_SRC_CLK_IDENTITY - \
                             offset);
    bytePtrPdelReq = (uint8_t *)(ptpPDelayResPacket + PTP_REQ_SRC_PORT_IDENTITY -
                                 offset);
    bytePtrPdelRes = (uint8_t *)(ptpPDelayResFlwUpPacket + PTP_REQ_SRC_PORT_IDENTITY
                                 - offset);
    memcpy(bytePtrPdelReq, bytePtrSrc, 8);
    memcpy(bytePtrPdelRes, bytePtrSrc, 8);

    /*Add Correction Field from delay request*/
    bytePtrSrc = (uint8_t *)(buff + PTP_CORRECTION_OFFSET - \
                             offset);
    bytePtrPdelReq = (uint8_t *)(ptpPDelayResPacket + PTP_CORRECTION_OFFSET - \
                                 offset);
    bytePtrPdelRes = (uint8_t *)(ptpPDelayResFlwUpPacket + PTP_CORRECTION_OFFSET - \
                                 offset);
    memcpy(bytePtrPdelReq, bytePtrSrc, 8);
    memcpy(bytePtrPdelRes, bytePtrSrc, 8);

    /**Add requested source port identity*/
    bytePtrSrc = (uint8_t *)(buff + PTP_SRC_PORT_ID_OFFSET - \
                             offset);
    bytePtrPdelReq = (uint8_t *)(ptpPDelayResPacket + PTP_REQ_SRC_PORT_ID -
                                 offset);
    bytePtrPdelRes = (uint8_t *)(ptpPDelayResFlwUpPacket + PTP_REQ_SRC_PORT_ID -
                                 offset);
    memcpy(bytePtrPdelReq, bytePtrSrc, 2);
    memcpy(bytePtrPdelRes, bytePtrSrc, 2);

    /**Copy sequence ID from Delay Req packet*/
    bytePtrSrc = (uint8_t *)(buff + PTP_SEQ_ID_OFFSET - \
                             offset);
    bytePtrPdelReq = (uint8_t *)(ptpPDelayResPacket + PTP_SEQ_ID_OFFSET -
                                 offset);
    bytePtrPdelRes = (uint8_t *)(ptpPDelayResFlwUpPacket + PTP_SEQ_ID_OFFSET -
                                 offset);
    memcpy(bytePtrPdelReq, bytePtrSrc, 2);
    memcpy(bytePtrPdelRes, bytePtrSrc, 2);

    /*Copy domain number*/
    bytePtrSrc = (uint8_t *)(buff + PTP_DOMAIN_NUM_OFFSET - \
                             offset);
    bytePtrPdelReq = (uint8_t *)(ptpPDelayResPacket + PTP_DOMAIN_NUM_OFFSET -
                                 offset);
    bytePtrPdelRes = (uint8_t *)(ptpPDelayResFlwUpPacket + PTP_DOMAIN_NUM_OFFSET -
                                 offset);
    memcpy(bytePtrPdelReq, bytePtrSrc, 2);
    memcpy(bytePtrPdelRes, bytePtrSrc, 2);

    /*Add Source port ID*/
    addHalfWord(ptpPDelayResPacket + PTP_SRC_PORT_ID_OFFSET - offset,
                portNum);
    addHalfWord(ptpPDelayResFlwUpPacket + PTP_SRC_PORT_ID_OFFSET -
                offset,
                portNum);

    convEndianess(&(timeSyncHandle->pDelayParams[portNum - 1].pDelayReqRcvdTSSec),
                  ptpPDelayResPacket + PTP_REQ_RCPT_TS_SEC_OFFSET -
                  offset, 6);
    convEndianess(&(timeSyncHandle->pDelayParams[portNum - 1].pDelayReqRcvdTSNsec),
                  ptpPDelayResPacket + PTP_REQ_RCPT_TS_NSEC_OFFSET - offset, 4);

    if(timeSyncHandle->timeSyncConfig.ll_has_hsrTag ||
            timeSyncHandle->timeSyncConfig.custom_tx_api)
    {
        txArg.icssEmacHandle = timeSyncHandle->emacHandle;
        txArg.lengthOfPacket = TIMESYNC_PDELAY_BUF_SIZE;
        txArg.portNumber = portNum;
        txArg.queuePriority = quePri;
        txArg.srcAddress = ptpPDelayResPacket;

        /*Send pdelay response follow up frame out*/
        ((((ICSS_EmacObject *)
           timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->callBack(
               &txArg,
               ((((ICSS_EmacObject *)
                  timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->userArg);
    }

    else
    {
        ICSS_EmacTxPacketEnqueue(timeSyncHandle->emacHandle, ptpPDelayResPacket,
                                 portNum,
                                 quePri, TIMESYNC_PDELAY_BUF_SIZE);
    }
}

void TimeSync_processPdelayRespFrame(TimeSync_ParamsHandle_t timeSyncHandle,
                                     uint8_t *buff, \
                                     uint8_t followUp, uint8_t portNum)
{
    uint8_t offset = timeSyncHandle->timeSyncConfig.frame_offset;

    /*generic buffer used for comparison and storing*/
    uint8_t buf_for_comp[8] = {0};
    uint16_t halfWord = 0;

    /*check if this is a valid response frame to our delay request
     * extract parameters and calculate peer delay if so*/

    /*Check for source port identity*/
    memcpy(buf_for_comp, buff + PTP_REQ_SRC_PORT_IDENTITY - offset,
           8);

    if(0 != memcmp(buf_for_comp, timeSyncHandle->timeSyncConfig.clockIdentity, 8))
    {
        return;
    }

    /*check with the sequence id that was sent out*/
    convEndianess(buff + PTP_SEQ_ID_OFFSET - offset, &halfWord, 2);

    if(halfWord != (timeSyncHandle->tsRunTimeVar->pDelReqSequenceID[portNum - 1] -
                    1))
    {
        return;
    }

    if(!followUp)
    {

        /*Extract correction field*/
        convEnd6to8(buff + PTP_CORRECTION_OFFSET - offset, \
                    & (timeSyncHandle->pDelayParams[portNum - 1].delayResCorrField));

        /*Now check if it's a two step, if yes then exit*/
        convEndianess(buff + PTP_FLAG_OFFSET - offset, &halfWord, 2);

        if(halfWord & PTP_TWO_STEP_MASK)
        {
            /*Extract T2 timestamp in seconds*/
            convEnd6to8(buff + PTP_REQ_RCPT_TS_SEC_OFFSET - offset, \
                        & (timeSyncHandle->pDelayParams[portNum - 1].T2Sec));

            /*Extract T2 timestamp in nanoseconds*/
            convEndianess(buff + PTP_REQ_RCPT_TS_NSEC_OFFSET - offset, \
                          & (timeSyncHandle->pDelayParams[portNum - 1].T2Nsec), 4);

            return;
        }

    }

    else
    {
        /*Extract correction field*/
        convEnd6to8(buff + PTP_CORRECTION_OFFSET - offset, \
                    & (timeSyncHandle->pDelayParams[portNum - 1].delayResFwUpCorrField));
        /*Extract T2 timestamp in seconds*/
        convEnd6to8(buff + PTP_REQ_RCPT_TS_SEC_OFFSET - offset, \
                    & (timeSyncHandle->pDelayParams[portNum - 1].T3Sec));

        /*Extract T2 timestamp in nanoseconds.*/
        convEndianess(buff + PTP_REQ_RCPT_TS_NSEC_OFFSET - offset, \
                      & (timeSyncHandle->pDelayParams[portNum - 1].T3Nsec), 4);

    }

    /*Calculate peer delay*/
    TimeSync_peerDelayCalc(timeSyncHandle, followUp, portNum);
    /*Update params here, NRR gets calculated in the background*/
    TimeSync_updateNRRParams(timeSyncHandle, portNum);
    TimeSync_calcNRR(timeSyncHandle, portNum);

    return;

}

void TimeSync_forced2StepBDCalc(TimeSync_ParamsHandle_t timeSyncHandle,
                                uint8_t portNum)
{
    uint8_t *ptpFlwUpPacket = NULL;
    uint64_t doubleWord = 0;
    uint64_t timeElapsed = 0;
    ICSS_EmacTxArgument txArg;
    uint8_t oppPort = 0;
    uint32_t quePri;

    /* Get the queue priority */
    if (portNum == ICSS_EMAC_PORT_1)
    {
        quePri = ICSS_EMAC_QUEUE1;
    }
    else
    {
        quePri = ICSS_EMAC_QUEUE3;
    }

    /*Get the opposite port*/
    oppPort = ~portNum;
    oppPort &= 0x3;

    ptpFlwUpPacket = timeSyncHandle->timeSyncBuff.followUp_TxBuf[portNum - 1];

    /*calculate bridge delay and write into the follow up frame
     * time stamp is already available in syncParam*/
    doubleWord = timeSyncHandle->syncParam[portNum - 1]->txTsSec *
                 (uint64_t)SEC_TO_NS + \
                 timeSyncHandle->syncParam[portNum - 1]->txTs;
    timeElapsed = timeSyncHandle->syncParam[portNum - 1]->rxTsSec *
                  (uint64_t)SEC_TO_NS + \
                  timeSyncHandle->syncParam[portNum - 1]->rxTs;
    /*This is the BD or bridge delay*/
    timeElapsed = doubleWord - timeElapsed;

    /*Multiply BD with RCF. For 802.1 AB this should be the accumulated rate ratio*/
    timeElapsed = (uint32_t)((double)timeElapsed * timeSyncHandle->tsSyntInfo->rcf);

    /*Add Peer delay for P2P mode*/
    if(P2P == timeSyncHandle->timeSyncConfig.type)
    {
        timeElapsed += timeSyncHandle->tsRunTimeVar->pathDelay[portNum - 1];
    }

    /*timeElapsed now contains the corrected BD.
    * Encode into frame and send out*/
    convEndianess(&timeElapsed,
                  (ptpFlwUpPacket + PTP_CORRECTION_OFFSET -
                   timeSyncHandle->timeSyncConfig.frame_offset), 6);

    if(timeSyncHandle->timeSyncConfig.hsrEnabled ||
            timeSyncHandle->timeSyncConfig.custom_tx_api)
    {

        txArg.icssEmacHandle = timeSyncHandle->emacHandle;
        txArg.lengthOfPacket = timeSyncHandle->timeSyncBuff.flwUpBuf_size;
        txArg.portNumber = oppPort;
        txArg.queuePriority = quePri;
        txArg.srcAddress = ptpFlwUpPacket;

        /*Send follow up frame out*/
        ((((ICSS_EmacObject *)
           timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->callBack(
               &txArg,
               ((((ICSS_EmacObject *)
                  timeSyncHandle->emacHandle->object)->callBackHandle)->txCallBack)->userArg);
    }

    else
    {
        ICSS_EmacTxPacketEnqueue(timeSyncHandle->emacHandle, ptpFlwUpPacket,
                                 oppPort, quePri, timeSyncHandle->timeSyncBuff.flwUpBuf_size);
    }

}

void TimeSync_getGeneralMessage(TimeSync_ParamsHandle_t timeSyncHandle,
                                int8_t *buff)
{
    uint8_t *macId = NULL;
    uint8_t count = 0;

    if(timeSyncHandle->stackParams.generalFrameFlag)
    {
        if(E2E == timeSyncHandle->timeSyncConfig.type)
        {
            memcpy(buff, timeSyncHandle->stackParams.ptpGeneralFrame +
                   PTP_E2E_BUFFER_OFFSET,
                   timeSyncHandle->stackParams.ptpGeneralSize - PTP_E2E_BUFFER_OFFSET);
        }

        if(P2P == timeSyncHandle->timeSyncConfig.type)
        {
            memcpy(buff, timeSyncHandle->stackParams.ptpGeneralFrame +
                   PTP_P2P_BUFFER_OFFSET,
                   timeSyncHandle->stackParams.ptpGeneralSize - PTP_P2P_BUFFER_OFFSET);
        }

        macId = (uint8_t *)(timeSyncHandle->stackParams.ptpGeneralFrame +
                            SRC_MAC_OFFSET);

        for(count = 0; count < 6; count++)
        {
            timeSyncHandle->stackParams.ptpSrcMacID[count] = macId[count];
        }

        timeSyncHandle->stackParams.generalFrameFlag = 0;
    }

}

uint8_t TimeSync_isEnabled(TimeSync_ParamsHandle_t timeSyncHandle)
{
    volatile uint8_t *ptpCtrlPtr;
    ptpCtrlPtr = (uint8_t *)((((ICSS_EmacHwAttrs *)
                               (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                             + TIMESYNC_CTRL_VAR_OFFSET);

    return *ptpCtrlPtr;
}

void TimeSync_updateParentAddress(TimeSync_ParamsHandle_t timeSyncHandle,
                                  uint8_t *parentMac)
{
    /*write master mac id*/
    volatile uint8_t *macId = NULL;
    uint8_t count = 0;
    macId = (uint8_t *)((((ICSS_EmacHwAttrs *)
                          (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                        + SYNC_MASTER_MAC_OFFSET);

    for(count = 0; count < 6; count++)
    {
        macId[count] = parentMac[count];
    }
}

void TimeSync_getPrevAddress(TimeSync_ParamsHandle_t timeSyncHandle,
                             uint8_t *prevMac)
{
    uint8_t count = 0;

    for(count = 0; count < 6; count++)
    {
        prevMac[count] = timeSyncHandle->stackParams.ptpSrcMacID[count];
    }
}

void TimeSync_Port1linkResetCallBack(uint8_t linkStatus, void *arg2)
{
    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)arg2;

    /*Reset Port 0 NRR Info*/
    memset(timeSyncHandle->tsNrrInfo[0], 0x0, sizeof(timeSync_NrrInfo_t));
    timeSyncHandle->tsNrrInfo[0]->nrr = 1.0;

    /*reset sequence id on that port*/
    timeSyncHandle->tsRunTimeVar->pDelReqSequenceID[0] = 0;
    /*Reset peer delay params*/
    memset(&(timeSyncHandle->pDelayParams[0]), 0x0, sizeof(peerDelayParams_t));
    /*make peer delay history 0*/
    timeSyncHandle->tsRunTimeVar->pathDelay[0] = 0;

    /*If link loss on port connected to Master then reset the
         *  Syntonization and Sync params*/
    if(timeSyncHandle->tsRunTimeVar->syncPortNum == ICSS_EMAC_PORT_1)
    {
         /*Add this line*/
        TimeSync_reset(timeSyncHandle); /*Do a full reset*/
    }
}

void TimeSync_Port2linkResetCallBack(uint8_t linkStatus, void *arg2)
{

    TimeSync_ParamsHandle_t timeSyncHandle = (TimeSync_ParamsHandle_t)arg2;

    /*Reset Port 1 NRR Info*/
    memset(timeSyncHandle->tsNrrInfo[1], 0x0, sizeof(timeSync_NrrInfo_t));
    timeSyncHandle->tsNrrInfo[1]->nrr = 1.0;
    /*reset sequence id on that port*/
    timeSyncHandle->tsRunTimeVar->pDelReqSequenceID[1] = 0;
    /*Reset peer delay params*/
    memset(&(timeSyncHandle->pDelayParams[1]), 0x0, sizeof(peerDelayParams_t));
    /*make peer delay history 0*/
    timeSyncHandle->tsRunTimeVar->pathDelay[1] = 0;

    /*If link loss on port connected to Master then reset the
     *  Syntonization and Sync params*/
    if(timeSyncHandle->tsRunTimeVar->syncPortNum == ICSS_EMAC_PORT_2)
    {
         /*Add this line*/
        TimeSync_reset(timeSyncHandle); /*Do a full reset*/
    }


}

void TimeSync_reset(TimeSync_ParamsHandle_t timeSyncHandle)
{
    uint8_t *bytePtr = NULL;
    uint8_t *sharedRAMbaseAddress = NULL;

    uint32_t word = 0;

    /*call sync loss callback*/
    if(timeSyncHandle->timeSyncConfig.timeSyncSyncLossCallBackfn != NULL)
    {
        timeSyncHandle->timeSyncConfig.timeSyncSyncLossCallBackfn();
    }

    sharedRAMbaseAddress = (uint8_t *)(((ICSSEMAC_HwAttrs *)
                                        timeSyncHandle->emacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr;

    /*first disable PTP so firmware is not running*/
    TimeSync_drvDisable(timeSyncHandle);

    /*Now reset all values*/

    /*Reset structures*/
    memset((timeSyncHandle->syncParam[0]), 0x0, sizeof(syncParam_t));
    memset((timeSyncHandle->syncParam[1]), 0x0, sizeof(syncParam_t));
    memset((timeSyncHandle->delayParams), 0x0, sizeof(delayReqRespParams_t));
    memset(&(timeSyncHandle->pDelayParams[0]), 0x0, sizeof(peerDelayParams_t));
    memset(&(timeSyncHandle->pDelayParams[1]), 0x0, sizeof(peerDelayParams_t));
    memset((timeSyncHandle->tsSyntInfo), 0x0, sizeof(timeSync_SyntInfo_t));
    memset((timeSyncHandle->tsRunTimeVar), 0x0, sizeof(timeSync_RuntimeVar_t));
    memset(timeSyncHandle->tsNrrInfo[0], 0x0, sizeof(timeSync_NrrInfo_t));
    memset(timeSyncHandle->tsNrrInfo[1], 0x0, sizeof(timeSync_NrrInfo_t));


    memset(sharedRAMbaseAddress + SYNC_MASTER_MAC_OFFSET, 0x0, 6);

    if(V1 == timeSyncHandle->timeSyncConfig.icssVersion)
    {
        memset(sharedRAMbaseAddress + TIMESYNC_SECONDS_COUNT_OFFSET, 0x0, 8);
    }

    word = 1 * 1024;
    bytePtr = (uint8_t *)(sharedRAMbaseAddress + TIMESYNC_TC_RCF_OFFSET);
    memcpy(bytePtr, &word, 4);

    /*Reset structure values*/
    timeSyncHandle->tsRunTimeVar->stateMachine = 0;
    timeSyncHandle->tsSyntInfo->rcf = 1.0;
    timeSyncHandle->tsNrrInfo[0]->nrr = 1.0;
    timeSyncHandle->tsNrrInfo[1]->nrr = 1.0;

    timeSyncHandle->tsRunTimeVar->clockDrift = 10000;
    timeSyncHandle->tsRunTimeVar->syncTimeoutInterval = 10000;

    timeSyncHandle->offsetAlgo->driftThreshold =
        TIMESYNC_OFFSET_STABLE_ALGO_THRESHOLD;

    /*Finally enable PTP*/
    TimeSync_drvEnable(timeSyncHandle);

}

void TimeSync_writeTS_SingleStep_Sync(TimeSync_ParamsHandle_t timeSyncHandle,
                                      uint8_t portNum)
{


    /*The logic of this function works like this
     * Assume three timestamps Y, Y' and Z
     * Y--------------Y'----------------Z
     * Z is the start of the seconds cycle i.e. nanoseconds value of 0
     * Y denotes current time inside this function which is invoked
     * just before transmitting the sync frame. Y' is the actual Tx SOF timestamp
     * and is guaranteed to be within few microsends/miliseconds ahead of Y.
     * Now three possible cases exist
     * Y-----Z-----Y' in which case Y' lies in the next cycle
     * Y-----Y'----Z  in which case Y' is in current cycle
     * corner cases in which Y == Z and Y' == Z also fall under the above 2
     *
     * In firmware the timestamp Y' is compared against Z and it is determined
     * whether it falls in next or previous cycle. The corresponding seconds value
     * of Z is then used to get the seconds value. Nanoseconds value is obtained by
     * subtraction and long division and reminder operation is avoided.
     */

    uint8_t *bytePtr = NULL;
    uint64_t iepCount = 0;
    uint64_t seconds = 0;
    uint32_t iepBaseAddress = (((ICSSEMAC_HwAttrs *)
                                (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->prussIepRegs;
    uint32_t sharedRAMbaseAddress = (((ICSSEMAC_HwAttrs *)
                                      timeSyncHandle->emacHandle->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr;
    bytePtr = (uint8_t *)((uint32_t)(iepBaseAddress + CSL_ICSSIEP_COUNT_REG0));
    /*Get current time 64 bit counter and time in seconds or Y*/
    memcpy(&iepCount, bytePtr, 8);
    seconds = iepCount / (uint64_t)SEC_TO_NS;

    /*Get next start of cycle TS or Z (see comments)*/
    seconds += 1;
    iepCount = seconds * (uint64_t)SEC_TO_NS;

    if(ICSS_EMAC_PORT_1 == portNum)
    {
        memcpy((uint8_t *)(sharedRAMbaseAddress + SINGLE_STEP_IEP_OFFSET_P1), &iepCount,
               8);
        memcpy((uint8_t *)(sharedRAMbaseAddress + SINGLE_STEP_SECONDS_OFFSET_P1),
               &seconds, 8);
    }

    else
    {
        memcpy((uint8_t *)(sharedRAMbaseAddress + SINGLE_STEP_IEP_OFFSET_P2), &iepCount,
               8);
        memcpy((uint8_t *)(sharedRAMbaseAddress + SINGLE_STEP_SECONDS_OFFSET_P2),
               &seconds, 8);
    }

}

void TimeSync_dummyBMCA(TimeSync_ParamsHandle_t timeSyncHandle,
                        uint8_t *pktBuffer)
{
    /*Extract MAC ID and write parent address*/

    if(!timeSyncHandle->tsRunTimeVar->bmcaDone)
    {
        /*pass the source MAC ID*/
        TimeSync_updateParentAddress(timeSyncHandle, pktBuffer + 6);
        timeSyncHandle->tsRunTimeVar->bmcaDone = 1;
    }
}

void TimeSync_rxPhyDelayCorrection(TimeSync_ParamsHandle_t timeSyncHandle)
{
    if(timeSyncHandle->rxTimestamp_gPTP->nanoseconds >= RX_PHY_LATENCY)
    {
        timeSyncHandle->rxTimestamp_gPTP->nanoseconds -= RX_PHY_LATENCY;
    }

    else
    {
        timeSyncHandle->rxTimestamp_gPTP->nanoseconds = SEC_TO_NS -
                (RX_PHY_LATENCY - timeSyncHandle->rxTimestamp_gPTP->nanoseconds);
        timeSyncHandle->rxTimestamp_gPTP->seconds -= 1;
    }
}

uint64_t getIEPTimestamp(TimeSync_ParamsHandle_t timeSyncHandle)
{

    uint8_t *bytePtr;
    uint64_t iepCount = 0;
    uint32_t iepBaseAddress = (((ICSSEMAC_HwAttrs *)
                                (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->prussIepRegs;
    bytePtr = (uint8_t *)((uint32_t)(iepBaseAddress + CSL_ICSSIEP_COUNT_REG0));
    memcpy(&iepCount, bytePtr, 8);

    return iepCount;
}

