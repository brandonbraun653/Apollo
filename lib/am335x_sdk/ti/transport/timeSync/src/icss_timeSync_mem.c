/******************************************************************************
 * FILE NAME:   icss_timeSync_mem.c
 *
 * DESCRIPTION: Contains the memory needs for the timeSync driver.
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
#include <stdint.h>
#include <ti/transport/timeSync/include/icss_timeSync_init.h>

/* ========================================================================== */
/*             Static Global Variables                                        */
/* ========================================================================== */

/* TimeSync driver static buffers */
uint8_t   ts_syncTxBuf_mem[TIMESYNC_SYNC_BUF_ANNEX_E_SIZE];
uint8_t   ts_followUpTxBuf0_mem[TIMESYNC_FOLLOW_UP_BUF_ANNEX_E_SIZE];
uint8_t   ts_followUpTxBuf1_mem[TIMESYNC_FOLLOW_UP_BUF_ANNEX_E_SIZE];
uint8_t   ts_announceTxBuf_mem[TIMESYNC_ANNOUNCE_BUF_ANNEX_E_SIZE];
uint8_t   ts_pDelayReqBuf0_Rx[TIMESYNC_PDELAY_BUF_SIZE];
uint8_t   ts_pDelayReqBuf1_Rx[TIMESYNC_PDELAY_BUF_SIZE];
uint8_t   ts_pDelayResBuf0_Rx[TIMESYNC_PDELAY_BUF_SIZE];
uint8_t   ts_pDelayResBuf1_Rx[TIMESYNC_PDELAY_BUF_SIZE];
uint8_t   ts_pDelayResBuf0_FlwUpRx[TIMESYNC_PDELAY_BUF_SIZE];
uint8_t   ts_pDelayResBuf1_FlwUpRx[TIMESYNC_PDELAY_BUF_SIZE];
uint8_t   ts_pDelayReqBuf0_Tx[TIMESYNC_PDELAY_BUF_SIZE];
uint8_t   ts_pDelayReqBuf1_Tx[TIMESYNC_PDELAY_BUF_SIZE];
uint8_t   ts_pDelayResBuf0_Tx[TIMESYNC_PDELAY_BUF_SIZE];
uint8_t   ts_pDelayResBuf1_Tx[TIMESYNC_PDELAY_BUF_SIZE];
uint8_t   ts_pDelayResBuf0_FlwUpTx[TIMESYNC_PDELAY_BUF_SIZE];
uint8_t   ts_pDelayResBuf1_FlwUpTx[TIMESYNC_PDELAY_BUF_SIZE];
uint8_t   ts_delayReqBuf_Tx[TIMESYNC_DELAY_REQ_BUF_SIZE];


/* Nothing past this point */
