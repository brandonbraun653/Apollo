/******************************************************************************
 * FILE NAME:   icss_timeSync_init.c
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <xdc/std.h>
#include <math.h>
#include <ti/transport/timeSync/include/icss_timeSync_init.h>
#include <ti/transport/timeSync/include/soc_icss_header.h>
#include <ti/drv/icss_emac/firmware/icss_dualemac/src/icss_timeSync_memory_map.h>
#include <ti/transport/timeSync/include/icss_timeSync_tools.h>


/* External static variables */
extern uint8_t   ts_syncTxBuf_mem[TIMESYNC_SYNC_BUF_ANNEX_E_SIZE];
extern uint8_t   ts_followUpTxBuf0_mem[TIMESYNC_FOLLOW_UP_BUF_ANNEX_E_SIZE];
extern uint8_t   ts_followUpTxBuf1_mem[TIMESYNC_FOLLOW_UP_BUF_ANNEX_E_SIZE];
extern uint8_t   ts_announceTxBuf_mem[TIMESYNC_ANNOUNCE_BUF_ANNEX_E_SIZE];
extern uint8_t   ts_pDelayReqBuf0_Rx[TIMESYNC_PDELAY_BUF_SIZE];
extern uint8_t   ts_pDelayReqBuf1_Rx[TIMESYNC_PDELAY_BUF_SIZE];
extern uint8_t   ts_pDelayResBuf0_Rx[TIMESYNC_PDELAY_BUF_SIZE];
extern uint8_t   ts_pDelayResBuf1_Rx[TIMESYNC_PDELAY_BUF_SIZE];
extern uint8_t   ts_pDelayResBuf0_FlwUpRx[TIMESYNC_PDELAY_BUF_SIZE];
extern uint8_t   ts_pDelayResBuf1_FlwUpRx[TIMESYNC_PDELAY_BUF_SIZE];
extern uint8_t   ts_pDelayReqBuf0_Tx[TIMESYNC_PDELAY_BUF_SIZE];
extern uint8_t   ts_pDelayReqBuf1_Tx[TIMESYNC_PDELAY_BUF_SIZE];
extern uint8_t   ts_pDelayResBuf0_Tx[TIMESYNC_PDELAY_BUF_SIZE];
extern uint8_t   ts_pDelayResBuf1_Tx[TIMESYNC_PDELAY_BUF_SIZE];
extern uint8_t   ts_pDelayResBuf0_FlwUpTx[TIMESYNC_PDELAY_BUF_SIZE];
extern uint8_t   ts_pDelayResBuf1_FlwUpTx[TIMESYNC_PDELAY_BUF_SIZE];
extern uint8_t   ts_delayReqBuf_Tx[TIMESYNC_DELAY_REQ_BUF_SIZE];

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/**
* @internal
* @def PTP Delay Request Frame
*      Global which contains the packet data
*/
const uint8_t ptpDelayReqPacket[] = \

{
    0x01, 0x00, 0x5E, 0x00, 0x01, 0x81, 0x00, 0x00, 0xBC, 0xCA, 0x8E, 0xF7,
    0x08, 0x00, 0x45, 0xEC, 0x00, 0x48, 0x01, 0x3B, 0x00, 0x00, 0x01, 0x11,
    0x14, 0x23, 0xC0, 0xA8, 0x01, 0x32, 0xE0, 0x00, 0x01, 0x81, 0x01, 0x3F,
    0x01, 0x3F, 0x00, 0x34, 0x00, 0x00, 0x01, 0x02, 0x00, 0x2C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xBC, 0xFF, 0xFE, 0xCA, 0x8E, 0xF7, 0x00, 0x01,
    0x00, 0x2A, 0x01, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/**
* @internal
* @def PTP PDelay Request Frame
*      Global which contains the packet data
*/
const uint8_t ptpPDelayReqPacket[] = \

{
    0x01, 0x80, 0xc2, 0x00, 0x00, 0x0e, 0x00, 0x80, 0x63, 0x00, 0x09, 0xba, 0x88, 0xf7, 0x02, 0x02,
    0x00, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x63, 0xff, 0xff, 0x00, 0x09, 0xba, 0x00, 0x02, 0x04, 0x61, 0x05, 0x7f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00
};

/**
* @internal
* @def PTP PDelay Response Frame for Port 1
*      Global which contains the packet data
*/
const uint8_t ptpPDelayResPacket[] = \

{
    0x01, 0x80, 0xc2, 0x00, 0x00, 0x0e, 0x00, 0x80, 0x63, 0x00, 0x09, 0xba, 0x88, 0xf7, 0x03, 0x02,
    0x00, 0x36, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x63, 0xff, 0xff, 0x00, 0x09, 0xba, 0x00, 0x02, 0x04, 0x61, 0x05, 0x7f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00
};

/**
* @internal
* @def PTP PDelay Response Follow Up Frame for Port 1
*      Global which contains the packet data
*/
const uint8_t ptpPDelayResFlwUpPacket[] = \

{
    0x01, 0x80, 0xc2, 0x00, 0x00, 0x0e, 0x00, 0x80, 0x63, 0x00, 0x09, 0xba, 0x88, 0xf7, 0x0a, 0x02,
    0x00, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x63, 0xff, 0xff, 0x00, 0x09, 0xba, 0x00, 0x02, 0x04, 0x61, 0x05, 0x7f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00
};

/**
* @internal
* @def Sample Layer 2 PTP Follow Up Frame
*      Global which contains the packet data
*/
const uint8_t ptpFlwUpPacket_L2[] = \
{
    0x01 , 0x1b , 0x19 , 0x00 , 0x00 , 0x00 , 0xec , 0x74 , 0xba , 0x1e , 0x13 , 0x02, 0x88 , 0xf7 , 0x08 , 0x02,
    0x00 , 0x2c , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00, 0x00 , 0x00 , 0x00 , 0x00,
    0x00 , 0x00 , 0xec , 0x74 , 0xba , 0xff , 0xfe , 0x1e , 0x13 , 0x02 , 0x00 , 0x03, 0xae , 0x2d , 0x02 , 0x00,
    0x00 , 0x00 , 0x56 , 0x89 , 0xa6 , 0x19 , 0x37 , 0x3b , 0xdc , 0x24 , 0x00 , 0x00, 0x70 , 0xf8 , 0xed , 0xc5
};

/**
* @internal
* @def Sample Layer 3 (PTP over UDP/IPv4) PTP Follow Up Frame
*      Global which contains the packet data
*/
const uint8_t ptpFlwUpPacket_L3[] = \
{
    0x01, 0x00, 0x5e, 0x00, 0x01, 0x81, 0xe4, 0x90, 0x69, 0x9d, 0xd9, 0x25, 0x08, 0x00, 0x45, 0xbc,
    0x00, 0x48, 0xfa, 0x81, 0x00, 0x00, 0x01, 0x11, 0x1b, 0x20, 0xc0, 0xa8, 0x01, 0x1e, 0xe0, 0x00,
    0x01, 0x81, 0x01, 0x40, 0x01, 0x40, 0x00, 0x34, 0xed, 0x91, 0x08, 0x02, 0x00, 0x2c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x90,
    0x69, 0xff, 0xfe, 0x9d, 0xd9, 0x25, 0x00, 0x01, 0x10, 0xdd, 0x02, 0x00, 0x00, 0x00, 0x35, 0x08,
    0x9b, 0x46, 0x27, 0xd5, 0x32, 0xa8
};

/**
 * @internal
 * @def Sample Layer 2 Sync frame
 *      Global which contains packet data
 */
const uint8_t ptpSyncPacket_L2[] = \
{
    0x01, 0x1b, 0x19, 0x00, 0x00, 0x00, 0xec, 0x74, 0xba, 0x1e, 0x13, 0x02, 0x88, 0xf7, 0x00, 0x02,
    0x00, 0x2c, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xec, 0x74, 0xba, 0xff, 0xfe, 0x1e, 0x13, 0x02, 0x00, 0x03, 0x08, 0x76, 0x00, 0x00,
    0x00, 0x00, 0x56, 0x86, 0x0a, 0x25, 0x02, 0x05, 0xe9, 0xf0, 0x00, 0x00
};

/**
 * @internal
 * @def Sample Layer 3 (PTP over UDP/IPv4) Sync frame
 *      Global which contains packet data
 */
const uint8_t ptpSyncPacket_L3[] = \
{
    0x01, 0x00, 0x5e, 0x00, 0x01, 0x81, 0xe4, 0x90, 0x69, 0x9d, 0xd9, 0x25, 0x08, 0x00, 0x45, 0xec,
    0x00, 0x48, 0xf9, 0x81, 0x00, 0x00, 0x01, 0x11, 0x1b, 0xf0, 0xc0, 0xa8, 0x01, 0x1e, 0xe0, 0x00,
    0x01, 0x81, 0x01, 0x3f, 0x01, 0x3f, 0x00, 0x34, 0x8b, 0xee, 0x00, 0x02, 0x00, 0x2c, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x90,
    0x69, 0xff, 0xfe, 0x9d, 0xd9, 0x25, 0x00, 0x01, 0x10, 0xdd, 0x00, 0x00, 0x00, 0x00, 0x35, 0x08,
    0x9b, 0x46, 0x27, 0xd2, 0x62, 0x58
};

/**
 * @internal
 * @def Sample Layer 2 Announce frame
 *      Global which contains packet data
 */
const uint8_t ptpAnnouncePacket_L2[] = \
{
    0x01, 0x1b, 0x19, 0x00, 0x00, 0x00, 0xec, 0x74, 0xba, 0x1e, 0x13, 0x02, 0x88, 0xf7, 0x0b, 0x02,
    0x00, 0x40, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xec, 0x74, 0xba, 0xff, 0xfe, 0x1e, 0x13, 0x02, 0x00, 0x03, 0x04, 0x37, 0x05, 0x01,
    0x00, 0x00, 0x56, 0x86, 0x0a, 0x25, 0x02, 0x05, 0xe9, 0xf0, 0x00, 0x24, 0x00, 0x80, 0xf8, 0x31,
    0x62, 0x20, 0x80, 0xec, 0x74, 0xba, 0xff, 0xfe, 0x1e, 0x13, 0x02, 0x00, 0x00, 0xa0
};

/**
 * @internal
 * @def Sample Layer 3 (PTP over UDP/IPv4) Announce frame
 *      Global which contains packet data
 */
const uint8_t ptpAnnouncePacket_L3[] = \
{
    0x01, 0x00, 0x5e, 0x00, 0x01, 0x81, 0xe4, 0x90, 0x69, 0x9d, 0xd9, 0x25, 0x08, 0x00, 0x45, 0xbc,
    0x00, 0x5c, 0xfc, 0x81, 0x00, 0x00, 0x01, 0x11, 0x19, 0x0c, 0xc0, 0xa8, 0x01, 0x1e, 0xe0, 0x00,
    0x01, 0x81, 0x01, 0x40, 0x01, 0x40, 0x00, 0x48, 0xac, 0x7e, 0x0b, 0x02, 0x00, 0x40, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x90,
    0x69, 0xff, 0xfe, 0x9d, 0xd9, 0x25, 0x00, 0x01, 0x08, 0x6f, 0x05, 0x01, 0x00, 0x00, 0x35, 0x08,
    0x9b, 0x47, 0x27, 0xd0, 0xa7, 0x88, 0x00, 0x22, 0x00, 0x80, 0xf8, 0xfe, 0xff, 0xff, 0x80, 0xe4,
    0x90, 0x69, 0xff, 0xfe, 0x9d, 0xd9, 0x25, 0x00, 0x00, 0xa0
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
static void TimeSync_drvIEPConfig(TimeSync_ParamsHandle_t timeSyncHandle);

int8_t TimeSync_drvInit(TimeSync_ParamsHandle_t timeSyncHandle)
{
    /*Timer initialization variables*/
    uint8_t returnVal = TIME_SYNC_OK;

    TimeSync_setDefaultValue(timeSyncHandle);
    TimeSync_dramInit(timeSyncHandle);

    /*Create PTP Interrupts and Tasks*/
    returnVal = TimeSync_isrAndTaskInit(timeSyncHandle);

    if(returnVal != TIME_SYNC_OK)
    {
        return returnVal;
    }

    if((UDP_IPV4 == timeSyncHandle->timeSyncConfig.protocol)
            && (P2P == timeSyncHandle->timeSyncConfig.type))
    {
        return TIME_SYNC_UNSUPPORTED_FORMAT;
    }

    if((IEEE_802_3 == timeSyncHandle->timeSyncConfig.protocol)
            && (E2E == timeSyncHandle->timeSyncConfig.type))
    {
        return TIME_SYNC_UNSUPPORTED_FORMAT;
    }

#if defined (SOC_AM572x) || defined (SOC_AM571x) || defined (SOC_AM574x)  || defined(SOC_K2G)
#else
    if(V1 == timeSyncHandle->timeSyncConfig.icssVersion)
    {
        returnVal = TimeSync_ecapEdmaConfig(timeSyncHandle);

        if(returnVal != TIME_SYNC_OK)
        {
            return returnVal;
        }
    }
#endif

    TimeSync_drvIEPConfig(timeSyncHandle);

    return returnVal;
}

int8_t TimeSync_alloc_PktBuffer(TimeSync_ParamsHandle_t timeSyncHandle)
{
    /*First configure sizes for allocation*/
    if(E2E == timeSyncHandle->timeSyncConfig.type)
    {
        timeSyncHandle->timeSyncBuff.syncBuf_size = TIMESYNC_SYNC_BUF_ANNEX_E_SIZE;
        timeSyncHandle->timeSyncBuff.flwUpBuf_size =
            TIMESYNC_FOLLOW_UP_BUF_ANNEX_E_SIZE;
        timeSyncHandle->timeSyncBuff.announceBuf_size =
            TIMESYNC_ANNOUNCE_BUF_ANNEX_E_SIZE;
    }

    else
    {
        timeSyncHandle->timeSyncBuff.syncBuf_size = TIMESYNC_SYNC_BUF_ANNEX_F_SIZE;
        timeSyncHandle->timeSyncBuff.flwUpBuf_size =
            TIMESYNC_FOLLOW_UP_BUF_ANNEX_F_SIZE;
        timeSyncHandle->timeSyncBuff.announceBuf_size =
            TIMESYNC_ANNOUNCE_BUF_ANNEX_F_SIZE;
    }

    /*Two buffers are configured, one for each port.*/

    /*Configure Sync, Announce, Follow Up and Management frame buffer*/
    timeSyncHandle->timeSyncBuff.sync_TxBuf = &ts_syncTxBuf_mem[0];

    if(timeSyncHandle->timeSyncBuff.sync_TxBuf == NULL)
    {
        return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
    }

    timeSyncHandle->timeSyncBuff.followUp_TxBuf[0] = &ts_followUpTxBuf0_mem[0];
    timeSyncHandle->timeSyncBuff.followUp_TxBuf[1] = &ts_followUpTxBuf1_mem[0];

    if((timeSyncHandle->timeSyncBuff.followUp_TxBuf[0] == NULL) ||
            (timeSyncHandle->timeSyncBuff.followUp_TxBuf[1] == NULL))
    {
        return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
    }

    timeSyncHandle->timeSyncBuff.announce_TxBuf = &ts_announceTxBuf_mem[0];

    if(timeSyncHandle->timeSyncBuff.announce_TxBuf == NULL)
    {
        return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
    }

    /*Configure P2P buffers. Both Rx and Tx*/
    if(P2P == timeSyncHandle->timeSyncConfig.type)
    {

        timeSyncHandle->timeSyncBuff.pdelayReq_RxBuf[0] = &ts_pDelayReqBuf0_Rx[0];
        timeSyncHandle->timeSyncBuff.pdelayReq_RxBuf[1] = &ts_pDelayReqBuf1_Rx[0];

        if((timeSyncHandle->timeSyncBuff.pdelayReq_RxBuf[0] == NULL) ||
                (timeSyncHandle->timeSyncBuff.pdelayReq_RxBuf[1] == NULL))
        {
            return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
        }

        timeSyncHandle->timeSyncBuff.pdelayResFlwUp_RxBuf[0] = &ts_pDelayResBuf0_FlwUpRx[0];
        timeSyncHandle->timeSyncBuff.pdelayResFlwUp_RxBuf[1] = &ts_pDelayResBuf1_FlwUpRx[0];

        if((timeSyncHandle->timeSyncBuff.pdelayResFlwUp_RxBuf[0] == NULL) ||
                (timeSyncHandle->timeSyncBuff.pdelayResFlwUp_RxBuf[1] == NULL))
        {
            return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
        }

        timeSyncHandle->timeSyncBuff.pdelayRes_RxBuf[0] = &ts_pDelayResBuf0_Rx[0];
        timeSyncHandle->timeSyncBuff.pdelayRes_RxBuf[1] = &ts_pDelayResBuf1_Rx[0];;

        if((timeSyncHandle->timeSyncBuff.pdelayRes_RxBuf[0] == NULL) ||
                (timeSyncHandle->timeSyncBuff.pdelayRes_RxBuf[1] == NULL))
        {
            return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
        }

        timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[0] = &ts_pDelayReqBuf0_Tx[0];
        timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[1] = &ts_pDelayReqBuf1_Tx[0];

        if((timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[0] == NULL) ||
                (timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[1] == NULL))
        {
            return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
        }

        timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[0] = &ts_pDelayResBuf0_FlwUpTx[0];
        timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[1] = &ts_pDelayResBuf1_FlwUpTx[0];

        if((timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[0] == NULL) ||
                (timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[1] == NULL))
        {
            return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
        }

        timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[0] = &ts_pDelayResBuf0_Tx[0];
        timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[1] = &ts_pDelayResBuf1_Tx[0];

        if((timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[0] == NULL) ||
                (timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[1] == NULL))
        {
            return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
        }

    }

    else        /*Configure Delay Req buffers*/
    {
        timeSyncHandle->timeSyncBuff.delayReq_TxBuf = &ts_delayReqBuf_Tx[0];

        if(timeSyncHandle->timeSyncBuff.delayReq_TxBuf == NULL)
        {
            return TIME_SYNC_UNABLE_TO_ALLOC_MEM;
        }
    }

    return TIME_SYNC_OK;

}

void TimeSync_unAlloc_PktBuffer(TimeSync_ParamsHandle_t timeSyncHandle)
{
    /* all the buffers are now statically allocated, no action to free */
    return;
}

void TimeSync_drvEnable(TimeSync_ParamsHandle_t timeSyncHandle)
{
    volatile uint8_t *ptpCtrlPtr = NULL;
    uint8_t byteVal = TRUE;

    ptpCtrlPtr = (uint8_t *)((((ICSS_EmacHwAttrs *)(
                                   timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg->sharedDataRamBaseAddr) +
                             TIMESYNC_CTRL_VAR_OFFSET);

    /*Encode the forced two-step mode value, this tells firmware
     * to treat a 1-step sync as 2-step and process accordingly */
    byteVal |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TWO_STEP_INDEX] <<
         1);

    *(ptpCtrlPtr) = byteVal;
    timeSyncHandle->enabled = TRUE;
}

void TimeSync_drvDisable(TimeSync_ParamsHandle_t timeSyncHandle)
{
    volatile uint8_t *ptpCtrlPtr = NULL;
    ptpCtrlPtr = (uint8_t *)((((ICSS_EmacHwAttrs *)(
                                   timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg->sharedDataRamBaseAddr) +
                             TIMESYNC_CTRL_VAR_OFFSET);
    (*ptpCtrlPtr) = FALSE;
    timeSyncHandle->enabled = FALSE;
}


void TimeSync_drvIEPConfig(TimeSync_ParamsHandle_t timeSyncHandle)
{

    uint32_t iep_reg_val = 0;
    uint8_t *bytePtr = NULL;

    ICSS_EmacBaseAddressHandle_T emacBaseAddr = ((ICSS_EmacHwAttrs *)(
                timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg;

    /*Program compare 1 event value*/
    iep_reg_val = timeSyncHandle->timeSyncConfig.sync0_interval;
    HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_CMP1_REG0) = iep_reg_val;

    /*Enable and program capture config register
     * We have to enable CAP6R in first event mode*/
    iep_reg_val = HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_CAP_CFG_REG);
    iep_reg_val |= 0xC0;
    HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_CAP_CFG_REG) = iep_reg_val;

    /*Program Sync 0 Width. The value in register is multiplied by 5 by HW*/
    iep_reg_val = timeSyncHandle->timeSyncConfig.sync0_interval /
                  (PTP_SYNC0_PERIOD_DIVIDER * 5);
    HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_SYNC_PWIDTH_REG) = iep_reg_val;

    /*Program Sync 0 Start cycles*/
    iep_reg_val = 0;
    HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_SYNC_START_REG) = iep_reg_val;

    /*Enable Sync 0 and Sync 1 in one-shot mode
     * Sync 1 will follow Sync0*/
    iep_reg_val = 0;
    iep_reg_val |= 0x7;
    HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_SYNC_CTRL_REG) = iep_reg_val;

    /*Set Sync1 delay to 0 so it follows Sync0 exactly*/
    iep_reg_val = 0;
    HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_SYNC1_DELAY_REG) = iep_reg_val;

    /*Enable compare 1*/
    iep_reg_val = HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_CMP_CFG_REG);
    iep_reg_val = iep_reg_val | 0x4;

    /*We enable reset on CMP0 only for older ICSS versions which
     * have a 32 bit counter */
    if(V1 == timeSyncHandle->timeSyncConfig.icssVersion)
    {
        /*Enable reset*/
        iep_reg_val = iep_reg_val | 0x1;
        /*Enable compare 0*/
        iep_reg_val = iep_reg_val | 0x2;
        /*Program compare 0. Also the cycle count*/
        HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_CMP0_REG0) = (uint32_t)SEC_TO_NS;
    }

    else
    {
        /*set default increment value and clear slow compensation reg*/
        HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_GLOBAL_CFG_REG) = 0x00000551;
        HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_SLOW_COMPEN_REG) = 0;
    }

    /*Reset IEP count to 0 before enabling compare config regs
      This ensures that we don't hit CMP1 with a large value in IEP*/
    bytePtr = (uint8_t *)((uint32_t)(emacBaseAddr->prussIepRegs +
                                     CSL_ICSSIEP_COUNT_REG0));
    memset(bytePtr, 0x0, 8);

    HWREG(emacBaseAddr->prussIepRegs + CSL_ICSSIEP_CMP_CFG_REG) = iep_reg_val;

}

void TimeSync_dramInit(TimeSync_ParamsHandle_t timeSyncHandle)
{

    uint8_t *bytePtr = NULL;
    uint16_t *halfWordPtr = NULL;
    uint32_t word = 0;
    uint64_t doubleWord = 0;

    /*write MII correction*/
    halfWordPtr = (uint16_t *)((((ICSS_EmacHwAttrs *)
                                 (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                               + MII_RX_CORRECTION_OFFSET);

    *halfWordPtr = RX_PHY_LATENCY;

    /*write MII correction*/
    halfWordPtr = (uint16_t *)((((ICSSEMAC_HwAttrs *)
                                 (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                               +
                               MII_TX_CORRECTION_OFFSET);
    *halfWordPtr = TX_PHY_LATENCY;

    /*Set seconds value to 0*/
    bytePtr = (uint8_t *)((((ICSS_EmacHwAttrs *)
                            (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                          +
                          TIMESYNC_SECONDS_COUNT_OFFSET);
    memset(bytePtr, 0x0, 6);

    /*Initialize rcf to 1 */
    bytePtr = (uint8_t *)((((ICSS_EmacHwAttrs *)
                            (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                          +
                          TIMESYNC_TC_RCF_OFFSET);
    word = 1 * 1024;
    memcpy(bytePtr, &word, 4);

    /*This flag will be set and cleared by firmware */
    /*Write Sync0 period for sync signal generation in PTP memory in shared RAM*/
    bytePtr = (uint8_t *)((((ICSSEMAC_HwAttrs *)
                            (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                          +
                          TIMESYNC_SYNC0_WIDTH_OFFSET);

    word = timeSyncHandle->timeSyncConfig.sync0_interval / PTP_SYNC0_PERIOD_DIVIDER;
    memcpy(bytePtr, &word, 4);

    /*Write CMP1 period for sync signal generation in PTP memory in shared RAM*/
    bytePtr = (uint8_t *)((((ICSSEMAC_HwAttrs *)
                            (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                          +
                          TIMESYNC_CMP1_CMP_OFFSET);
    doubleWord = (uint64_t)timeSyncHandle->timeSyncConfig.sync0_interval;
    memcpy(bytePtr, &doubleWord, 8);

    bytePtr = (uint8_t *)((((ICSSEMAC_HwAttrs *)
                            (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                          +
                          TIMESYNC_CMP1_PERIOD_OFFSET);
    word = timeSyncHandle->timeSyncConfig.sync0_interval;
    memcpy(bytePtr, &word, 4);

    /*Write Sync0 period for sync signal generation in PTP memory in shared RAM*/
    bytePtr = (uint8_t *)((((ICSSEMAC_HwAttrs *)
                            (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                          +
                          TIMESYNC_DOMAIN_NUMBER_LIST);
    /* Configures domainNumber list. Firmware supports 2 domains*/
    memcpy(bytePtr, timeSyncHandle->timeSyncConfig.domainNumber,
           TS_NUM_DOMAINS);

    /*Configure 1-step/2-step*/
    bytePtr = (uint8_t *)((((ICSSEMAC_HwAttrs *)
                            (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                          +
                          DISABLE_SWITCH_SYNC_RELAY_OFFSET);
    *bytePtr =
        timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TWO_STEP_INDEX];

    /*Initialize the location which contains information about
     * whether Link local frames will have HSR tag or not.
     * This configures the setting to LL frame without HSR tag
     */
    bytePtr = (uint8_t *)((((ICSSEMAC_HwAttrs *)
                            (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                          + LINK_LOCAL_FRAME_HAS_HSR_TAG);
    *(bytePtr) = 0;

    /*Populate the source port identity so delay response frames can be compared against this*/
    bytePtr = (uint8_t *)((((ICSSEMAC_HwAttrs *)
                            (timeSyncHandle->emacHandle)->hwAttrs)->emacBaseAddrCfg)->sharedDataRamBaseAddr
                          + PTP_CLK_IDENTITY_OFFSET);
    memcpy(bytePtr, timeSyncHandle->timeSyncConfig.clockIdentity, 8);


}

void TimeSync_setDefaultValue(TimeSync_ParamsHandle_t timeSyncHandle)
{
    uint8_t *ifMacID = NULL;

    double logInterval = 0;
    double normalization_factor = 0;

    normalization_factor = (double)1000 / (double)(
                               timeSyncHandle->timeSyncConfig.tickPeriod);

    /*Initialize all structures*/
    memset((timeSyncHandle->syncParam[0]), 0x0, sizeof(syncParam_t));
    memset((timeSyncHandle->syncParam[1]), 0x0, sizeof(syncParam_t));
    memset((timeSyncHandle->delayParams), 0x0, sizeof(delayReqRespParams_t));
    memset(&(timeSyncHandle->pDelayParams[0]), 0x0, sizeof(peerDelayParams_t));
    memset(&(timeSyncHandle->pDelayParams[1]), 0x0, sizeof(peerDelayParams_t));
    memset((timeSyncHandle->tsSyntInfo), 0x0, sizeof(timeSync_SyntInfo_t));
    memset((timeSyncHandle->tsRunTimeVar), 0x0, sizeof(timeSync_RuntimeVar_t));
    memset((timeSyncHandle->offsetAlgo), 0x0,
           sizeof(timeSync_Offset_Stable_Algo_t));

    /*Calculate actual timer values from config values*/
    logInterval = timeSyncHandle->timeSyncConfig.logPDelReqPktInterval;
    timeSyncHandle->timeSyncConfig.pDelReqPktInterval = (uint32_t)(pow(2.0,
            logInterval) * 1000.0);
    /*Normalize as per tick period*/
    timeSyncHandle->timeSyncConfig.pDelReqPktInterval *= (normalization_factor);

    /*In microseconds. No normalization required*/
    logInterval = timeSyncHandle->timeSyncConfig.logSyncInterval;
    timeSyncHandle->timeSyncConfig.syncSendInterval = (uint32_t)(pow(2.0,
            logInterval) * (double)(SEC_TO_NS / 1000));

    /*Calculate actual value in miliseconds and normalize*/
    logInterval = timeSyncHandle->timeSyncConfig.logAnnounceSendInterval;
    timeSyncHandle->timeSyncConfig.announceSendInterval = (uint32_t)(pow(2.0,
            logInterval) * 1000.0);
    /*Normalize as per tick period*/
    timeSyncHandle->timeSyncConfig.announceSendInterval *= (normalization_factor);

    /*In miliseconds*/
    logInterval = timeSyncHandle->timeSyncConfig.logAnnounceRcptTimeoutInterval;
    timeSyncHandle->timeSyncConfig.announceRcptTimeoutInterval = (uint32_t)(pow(2.0,
            logInterval) * 1000.0);
    /*Normalize as per tick period*/
    timeSyncHandle->timeSyncConfig.announceRcptTimeoutInterval *=
        (normalization_factor);

    /*Normalize pdelayBurstInterval*/
    timeSyncHandle->timeSyncConfig.pdelayBurstInterval *= (normalization_factor);

    /*Calculate offset used for non link local frames*/
    if(E2E == timeSyncHandle->timeSyncConfig.type)
    {
        timeSyncHandle->timeSyncConfig.frame_offset = 0;
    }

    else      /*(P2P == timeSyncHandle->timeSyncConfig.type)*/
    {
        timeSyncHandle->timeSyncConfig.frame_offset = ANNEX_D_ANNEX_F_DIFF;
    }

    ifMacID = ((ICSS_EmacObject *)(
                   timeSyncHandle->emacHandle)->object)->emacInitcfg->macId;

    timeSyncHandle->tsRunTimeVar->stateMachine = 0;

    timeSyncHandle->timeSyncConfig.clockIdentity[0] = ifMacID[0];
    timeSyncHandle->timeSyncConfig.clockIdentity[1] = ifMacID[1];
    timeSyncHandle->timeSyncConfig.clockIdentity[2] = ifMacID[2];
    timeSyncHandle->timeSyncConfig.clockIdentity[3] = 0xFF;
    timeSyncHandle->timeSyncConfig.clockIdentity[4] = 0xFE;
    timeSyncHandle->timeSyncConfig.clockIdentity[5] = ifMacID[3];
    timeSyncHandle->timeSyncConfig.clockIdentity[6] = ifMacID[4];
    timeSyncHandle->timeSyncConfig.clockIdentity[7] = ifMacID[5];

    /*copy local clock identity to gm clock identity*/
    memcpy(timeSyncHandle->timeSyncConfig.masterParams.gmIdentity, \
           timeSyncHandle->timeSyncConfig.clockIdentity, 8);

    /*HSR specific flag, not applicable for other protocols. See definition
     * This configures Link local frames without a tag by default*/
    timeSyncHandle->timeSyncConfig.ll_has_hsrTag = 0;

    /****************PTP Runtime variables****************/
    /*Running offset is set to standard PPM for crystal on ICEv2*/
    timeSyncHandle->tsRunTimeVar->clockDrift = 10000;

    /*set to a high value*/
    timeSyncHandle->tsRunTimeVar->syncTimeoutInterval = 10000;

    /***************Packet Modification****************/
    TimeSync_formatPTPFrames(timeSyncHandle, ifMacID);

    /*This is a fixed mapping. We need a gap of 1 index for syntonization
     * Refer to syntonization algo in design doc*/
    timeSyncHandle->syntIndexMap[0] = 1;
    timeSyncHandle->syntIndexMap[1] = 2;
    timeSyncHandle->syntIndexMap[2] = 0;

    /*Same as above*/
    timeSyncHandle->prevIndexMap[0] = 2;
    timeSyncHandle->prevIndexMap[1] = 0;
    timeSyncHandle->prevIndexMap[2] = 1;

    timeSyncHandle->stackParams.generalFrameFlag = 0;
    memset(&(timeSyncHandle->stackParams.ptpGeneralFrame), 0x0,
           1518 * sizeof(uint8_t));

    /*Set RCF default value*/
    timeSyncHandle->tsSyntInfo->rcf = 1.0;
    /*Set NRR default value*/
    timeSyncHandle->tsNrrInfo[0]->nrr = 1.0;
    timeSyncHandle->tsNrrInfo[1]->nrr = 1.0;

    timeSyncHandle->offsetAlgo->driftThreshold =
        TIMESYNC_OFFSET_STABLE_ALGO_THRESHOLD;
}

void TimeSync_formatPTPFrames(TimeSync_ParamsHandle_t timeSyncHandle,
                              uint8_t *ifMacID)
{
    uint8_t *bytePtr = NULL;
    uint8_t flag_byte0 = 0;
    uint8_t flag_byte1 = 0;
    uint8_t offset = timeSyncHandle->timeSyncConfig.frame_offset;

    /*Initialize frame buffers with standard types*/
    if(P2P == timeSyncHandle->timeSyncConfig.type)
    {
        memcpy(timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[0], ptpPDelayReqPacket,
               TIMESYNC_PDELAY_BUF_SIZE);
        memcpy(timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[1], ptpPDelayReqPacket,
               TIMESYNC_PDELAY_BUF_SIZE);

        memcpy(timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[0], ptpPDelayResPacket,
               TIMESYNC_PDELAY_BUF_SIZE);
        memcpy(timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[1], ptpPDelayResPacket,
               TIMESYNC_PDELAY_BUF_SIZE);

        memcpy(timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[0],
               ptpPDelayResFlwUpPacket, TIMESYNC_PDELAY_BUF_SIZE);
        memcpy(timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[1],
               ptpPDelayResFlwUpPacket, TIMESYNC_PDELAY_BUF_SIZE);


        memcpy(timeSyncHandle->timeSyncBuff.sync_TxBuf, ptpSyncPacket_L2,
               timeSyncHandle->timeSyncBuff.syncBuf_size);

        memcpy(timeSyncHandle->timeSyncBuff.followUp_TxBuf[0], ptpFlwUpPacket_L2,
               timeSyncHandle->timeSyncBuff.flwUpBuf_size);
        memcpy(timeSyncHandle->timeSyncBuff.followUp_TxBuf[1], ptpFlwUpPacket_L2,
               timeSyncHandle->timeSyncBuff.flwUpBuf_size);

        memcpy(timeSyncHandle->timeSyncBuff.announce_TxBuf, ptpAnnouncePacket_L2,
               timeSyncHandle->timeSyncBuff.announceBuf_size);
    }

    else
    {
        memcpy(timeSyncHandle->timeSyncBuff.delayReq_TxBuf, ptpDelayReqPacket,
               TIMESYNC_DELAY_REQ_BUF_SIZE);

        memcpy(timeSyncHandle->timeSyncBuff.sync_TxBuf, ptpSyncPacket_L3,
               timeSyncHandle->timeSyncBuff.syncBuf_size);

        memcpy(timeSyncHandle->timeSyncBuff.followUp_TxBuf[0], ptpFlwUpPacket_L3,
               timeSyncHandle->timeSyncBuff.flwUpBuf_size);
        memcpy(timeSyncHandle->timeSyncBuff.followUp_TxBuf[1], ptpFlwUpPacket_L3,
               timeSyncHandle->timeSyncBuff.flwUpBuf_size);

        memcpy(timeSyncHandle->timeSyncBuff.announce_TxBuf, ptpAnnouncePacket_L3,
               timeSyncHandle->timeSyncBuff.announceBuf_size);

    }

    flag_byte0 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_ALTERNATE_MASTER_INDEX]
         << 0);
    flag_byte0 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TWO_STEP_INDEX] <<
         1);
    flag_byte0 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_UNICAST] << 2);
    flag_byte0 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PROFILE_SPECIFIC_1_INDEX]
         << 5);
    flag_byte0 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PROFILE_SPECIFIC_2_INDEX]
         << 6);

    /*prepare the flag*/
    flag_byte1 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_LEAP_61_INDEX] << 0);
    flag_byte1 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_LEAP_59_INDEX] << 1);
    flag_byte1 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_UTC_REASONABLE_INDEX]
         << 2);
    flag_byte1 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TIMESCALE_INDEX]
         << 3);
    flag_byte1 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_TIME_TRACEABLE_INDEX]
         << 4);
    flag_byte1 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_FREQ_TRACEABLE_INDEX]
         << 5);

    /*--------------------Add source MAC ID--------------------*/

    /*Add MAC ID to Sync frame*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.sync_TxBuf + SRC_MAC_OFFSET);
    memcpy(bytePtr, ifMacID, 6);

    /*Add MAC ID to Announce frame*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          SRC_MAC_OFFSET);
    memcpy(bytePtr, ifMacID, 6);

    /*--------------add source mac----------------*/
    if(E2E == timeSyncHandle->timeSyncConfig.type)
    {
        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.delayReq_TxBuf +
                              SRC_MAC_OFFSET);
        memcpy(bytePtr, ifMacID, 6);
    }

    if(P2P == timeSyncHandle->timeSyncConfig.type)
    {
        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[0] +
                              SRC_MAC_OFFSET);
        memcpy(bytePtr, ifMacID, 6);

        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[1] +
                              SRC_MAC_OFFSET);
        memcpy(bytePtr, ifMacID, 6);

        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[0] +
                              SRC_MAC_OFFSET);
        memcpy(bytePtr, ifMacID, 6);

        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[1] +
                              SRC_MAC_OFFSET);
        memcpy(bytePtr, ifMacID, 6);

        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[0] +
                              SRC_MAC_OFFSET);
        memcpy(bytePtr, ifMacID, 6);

        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[1] +
                              SRC_MAC_OFFSET);
        memcpy(bytePtr, ifMacID, 6);

    }

    /*--------------------Add clock identity--------------------*/
    if(E2E == timeSyncHandle->timeSyncConfig.type)
    {
        /*add clock identity*/
        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.delayReq_TxBuf +
                              PTP_SRC_CLK_IDENTITY);
        memcpy(bytePtr, timeSyncHandle->timeSyncConfig.clockIdentity, 8);

    }

    if(P2P == timeSyncHandle->timeSyncConfig.type)
    {
        /*add clock identity to Pdelay Req frame*/
        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[0] +
                              PTP_SRC_CLK_IDENTITY -
                              offset);
        memcpy(bytePtr, timeSyncHandle->timeSyncConfig.clockIdentity, 8);

        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[1] +
                              PTP_SRC_CLK_IDENTITY -
                              offset);
        memcpy(bytePtr, timeSyncHandle->timeSyncConfig.clockIdentity, 8);

        /*add clock identity to Pdelay Res frame*/
        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[0] +
                              PTP_SRC_CLK_IDENTITY -
                              offset);
        memcpy(bytePtr, timeSyncHandle->timeSyncConfig.clockIdentity, 8);

        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[1] +
                              PTP_SRC_CLK_IDENTITY -
                              offset);
        memcpy(bytePtr, timeSyncHandle->timeSyncConfig.clockIdentity, 8);

        /*add clock identity to Pdelay Res Flw Up frame*/
        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[0] +
                              PTP_SRC_CLK_IDENTITY -
                              offset);
        memcpy(bytePtr, timeSyncHandle->timeSyncConfig.clockIdentity, 8);

        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[1] +
                              PTP_SRC_CLK_IDENTITY -
                              offset);
        memcpy(bytePtr, timeSyncHandle->timeSyncConfig.clockIdentity, 8);
    }

    /*add clock identity to sync frame*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.sync_TxBuf +
                          PTP_SRC_CLK_IDENTITY -
                          offset);
    memcpy(bytePtr, timeSyncHandle->timeSyncConfig.clockIdentity, 8);

    /*add clock identity to announce frame*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_SRC_CLK_IDENTITY -
                          offset);
    memcpy(bytePtr, timeSyncHandle->timeSyncConfig.clockIdentity, 8);

    /*--------------------Add log message interval--------------------*/

    /*Add log message interval to sync and announce frame*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.sync_TxBuf +
                          PTP_LOG_MSG_PERIOD -
                          offset);
    *bytePtr = timeSyncHandle->timeSyncConfig.logSyncInterval;

    /*add announce send interval to announce frame*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_LOG_MSG_PERIOD -
                          offset);
    *bytePtr = timeSyncHandle->timeSyncConfig.logAnnounceSendInterval;

    /*-----------------------Add flags------------------------------*/
    /*--sync--*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.sync_TxBuf + PTP_FLAG_OFFSET
                          -
                          offset);
    *(bytePtr) = flag_byte0 & TS_SYNC_BYTE0_MASK;
    /*Other flags are applicable only to Announce*/
    *(bytePtr + 1) = 0;

    if(E2E == timeSyncHandle->timeSyncConfig.type)
    {
        /*--Delay Req*/
        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.delayReq_TxBuf +
                              PTP_FLAG_OFFSET);
        *(bytePtr) = flag_byte0 & TS_OTHER_FRAMES_BYTE0_MASK;
        /*Other flags are applicable only to Announce*/
        *(bytePtr + 1) = 0;
    }

    /*--Announce--*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_FLAG_OFFSET -
                          offset);
    *(bytePtr) = flag_byte0 & TS_ANNOUNCE_BYTE0_MASK;
    *(bytePtr + 1) = flag_byte1;


    if(P2P == timeSyncHandle->timeSyncConfig.type)
    {
        /*--Pdelay Req--*/
        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[0] +
                              PTP_FLAG_OFFSET -
                              offset);
        *(bytePtr) = flag_byte0 & TS_OTHER_FRAMES_BYTE0_MASK;
        *(bytePtr + 1) = 0;

        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayReq_TxBuf[1] +
                              PTP_FLAG_OFFSET -
                              offset);
        *(bytePtr) = flag_byte0 & TS_OTHER_FRAMES_BYTE0_MASK;
        *(bytePtr + 1) = 0;

        /*--Pdelay Res--*/
        /*Override two-step settings
         * DUT only supports 2-step Peer delay measurement*/
        flag_byte0 |= (1 << 1);
        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[0] +
                              PTP_FLAG_OFFSET -
                              offset);
        *(bytePtr) = flag_byte0 & TS_PDELAY_RESP_BYTE0_MASK;
        *(bytePtr + 1) = 0;
        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayRes_TxBuf[1] +
                              PTP_FLAG_OFFSET -
                              offset);

        *(bytePtr) = flag_byte0 & TS_PDELAY_RESP_BYTE0_MASK;
        *(bytePtr + 1) = 0;

        /*--Pdelay Res Follow Up--*/
        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[0] +
                              PTP_FLAG_OFFSET -
                              offset);
        *(bytePtr) = flag_byte0 & TS_OTHER_FRAMES_BYTE0_MASK;
        *(bytePtr + 1) = 0;
        bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.pdelayResFlwUp_TxBuf[1] +
                              PTP_FLAG_OFFSET -
                              offset);

        *(bytePtr) = flag_byte0 & TS_OTHER_FRAMES_BYTE0_MASK;
        *(bytePtr + 1) = 0;

    }

    /*---------------------Add Announce frame params--------------------*/
    /*Priority 1*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_PRIORITY1_OFFSET -
                          offset);
    *bytePtr = timeSyncHandle->timeSyncConfig.masterParams.priority1;
    /*Priority 2*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_PRIORITY2_OFFSET -
                          offset);
    *bytePtr = timeSyncHandle->timeSyncConfig.masterParams.priority2;
    /*clock class*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_GM_CLK_CLASS_OFFSET -
                          offset);
    *bytePtr = timeSyncHandle->timeSyncConfig.masterParams.clockClass;
    /*clock accuracy*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_GM_CLK_ACCU_OFFSET -
                          offset);
    *bytePtr = timeSyncHandle->timeSyncConfig.masterParams.clockAccuracy;
    /*clock class*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_GM_CLK_CLASS_OFFSET -
                          offset);
    *bytePtr = timeSyncHandle->timeSyncConfig.masterParams.clockClass;
    /*time source*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_TIME_SRC_OFFSET -
                          offset);
    *bytePtr = timeSyncHandle->timeSyncConfig.masterParams.timeSource;
    /*steps removed*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_STEPS_REMOVED_OFFSET -
                          offset);
    addHalfWord(bytePtr, timeSyncHandle->timeSyncConfig.masterParams.stepRemoved);
    /*clock variance*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_GM_CLK_VARIANCE_OFFSET -
                          offset);
    addHalfWord(bytePtr, timeSyncHandle->timeSyncConfig.masterParams.clockVariance);

    /*UTC Offset*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_UTC_OFFSET -
                          offset);
    addHalfWord(bytePtr, timeSyncHandle->timeSyncConfig.masterParams.UTCOffset);

    /*GM clock identity*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.announce_TxBuf +
                          PTP_GM_CLK_IDENTITY_OFFSET -
                          offset);
    memcpy(bytePtr, timeSyncHandle->timeSyncConfig.masterParams.gmIdentity, 8);

}

void TimeSync_initializeFollowUp(TimeSync_ParamsHandle_t timeSyncHandle)
{
    uint8_t *ifMacID = NULL;
    uint8_t *bytePtr = NULL;

    uint8_t flag_byte0 = 0;
    uint8_t flag_byte1 = 0;

    uint8_t offset = timeSyncHandle->timeSyncConfig.frame_offset;

    flag_byte0 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_ALTERNATE_MASTER_INDEX]
         << 0);
    flag_byte0 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TWO_STEP_INDEX] <<
         1);
    flag_byte0 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_UNICAST] << 2);
    flag_byte0 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PROFILE_SPECIFIC_1_INDEX]
         << 5);
    flag_byte0 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PROFILE_SPECIFIC_2_INDEX]
         << 6);

    /*prepare the flag*/
    flag_byte1 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_LEAP_61_INDEX] << 0);
    flag_byte1 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_LEAP_59_INDEX] << 1);
    flag_byte1 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_UTC_REASONABLE_INDEX]
         << 2);
    flag_byte1 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_PTP_TIMESCALE_INDEX]
         << 3);
    flag_byte1 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_TIME_TRACEABLE_INDEX]
         << 4);
    flag_byte1 |=
        (timeSyncHandle->timeSyncConfig.masterParams.ptp_flags[TS_FREQ_TRACEABLE_INDEX]
         << 5);

    /*Pointer to system MAC ID*/
    ifMacID = ((ICSS_EmacObject *)(
                   timeSyncHandle->emacHandle)->object)->emacInitcfg->macId;

    /*Add MAC ID to Follow Up frame for P1*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.followUp_TxBuf[0] +
                          SRC_MAC_OFFSET);
    memcpy(bytePtr, ifMacID, 6);

    /*Add MAC ID to Follow Up frame for P2*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.followUp_TxBuf[1] +
                          SRC_MAC_OFFSET);
    memcpy(bytePtr, ifMacID, 6);

    /*add clock identity to follow up frame for P1*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.followUp_TxBuf[0] +
                          PTP_SRC_CLK_IDENTITY -
                          offset);
    memcpy(bytePtr, timeSyncHandle->timeSyncConfig.clockIdentity, 8);

    /*add clock identity to follow up frame for P2*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.followUp_TxBuf[1] +
                          PTP_SRC_CLK_IDENTITY -
                          offset);
    memcpy(bytePtr, timeSyncHandle->timeSyncConfig.clockIdentity, 8);

    /*add clock identity to announce frame for P1*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.followUp_TxBuf[0] +
                          PTP_LOG_MSG_PERIOD -
                          offset);
    *bytePtr = timeSyncHandle->timeSyncConfig.logSyncInterval;

    /*add clock identity to announce frame for P2*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.followUp_TxBuf[1] +
                          PTP_LOG_MSG_PERIOD -
                          offset);
    *bytePtr = timeSyncHandle->timeSyncConfig.logSyncInterval;

    /*Add port identity*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.followUp_TxBuf[0] +
                          PTP_SRC_PORT_ID_OFFSET -
                          offset);
    *bytePtr = ICSS_EMAC_PORT_1;

    /*Add port identity*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.followUp_TxBuf[1] +
                          PTP_SRC_PORT_ID_OFFSET -
                          offset);
    *bytePtr = ICSS_EMAC_PORT_2;


    /*--------------Add flags---------------*/
    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.followUp_TxBuf[0] +
                          PTP_FLAG_OFFSET -
                          offset);
    *(bytePtr) = flag_byte0 & TS_FOLLOW_UP_BYTE0_MASK;
    /*Other flags are not applicable to Follow Up frames*/
    *(bytePtr + 1) = 0;

    bytePtr = (uint8_t *)(timeSyncHandle->timeSyncBuff.followUp_TxBuf[1] +
                          PTP_FLAG_OFFSET -
                          offset);
    *(bytePtr) = flag_byte0 & TS_FOLLOW_UP_BYTE0_MASK;
    /*Other flags are not applicable to Follow Up frames*/
    *(bytePtr + 1) = 0;

}

void TimeSync_addIP(TimeSync_ParamsHandle_t timeSyncHandle, uint32_t IP)
{
    /*For P2P this should not be called*/
    if(P2P == timeSyncHandle->timeSyncConfig.type)
    {
        return;
    }

    /*Destination IP 224.0.1.129*/
    timeSyncHandle->udpParams.dstIP = 0xE0000181;

    /*add Destination IP*/
    addWord(timeSyncHandle->timeSyncBuff.delayReq_TxBuf + DST_IP_OFFSET,
            timeSyncHandle->udpParams.dstIP);

    /*add Source IP for delay request*/
    timeSyncHandle->udpParams.srcIP = IP;
    addWord(timeSyncHandle->timeSyncBuff.delayReq_TxBuf + SRC_IP_OFFSET,
            timeSyncHandle->udpParams.srcIP);

    calcIPChecksum(timeSyncHandle->timeSyncBuff.delayReq_TxBuf);

    /*add Source IP for Sync*/
    addWord(timeSyncHandle->timeSyncBuff.sync_TxBuf + SRC_IP_OFFSET,
            timeSyncHandle->udpParams.srcIP);
    calcIPChecksum(timeSyncHandle->timeSyncBuff.sync_TxBuf);

    /*add Source IP for Announce*/
    addWord(timeSyncHandle->timeSyncBuff.announce_TxBuf + SRC_IP_OFFSET,
            timeSyncHandle->udpParams.srcIP);
    calcIPChecksum(timeSyncHandle->timeSyncBuff.announce_TxBuf);

    /*add Source IP for Follow Up*/
    addWord(timeSyncHandle->timeSyncBuff.followUp_TxBuf[0] + SRC_IP_OFFSET,
            timeSyncHandle->udpParams.srcIP);
    addWord(timeSyncHandle->timeSyncBuff.followUp_TxBuf[1] + SRC_IP_OFFSET,
            timeSyncHandle->udpParams.srcIP);

    calcIPChecksum(timeSyncHandle->timeSyncBuff.followUp_TxBuf[0]);
    calcIPChecksum(timeSyncHandle->timeSyncBuff.followUp_TxBuf[1]);
}

