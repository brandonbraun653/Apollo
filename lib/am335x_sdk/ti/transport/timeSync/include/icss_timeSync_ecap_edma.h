/******************************************************************************
 * FILE NAME:   icss_timeSync_ecap_edma.h
 *
 * DESCRIPTION: Include file for icss_timeSync_ecap_edma.c.
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

#ifndef ICSS_TIMESYNC_ECAP_EDMA_H_
#define ICSS_TIMESYNC_ECAP_EDMA_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/sdo/edma3/drv/edma3_drv.h>
#include <ti/sdo/edma3/rm/edma3_rm.h>
#include <ti/sdo/edma3/drv/sample/bios6_edma3_drv_sample.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/cslr_ecap.h>

#include <ti/transport/timeSync/include/icss_timeSync.h>
#include <ti/transport/timeSync/include/icss_timeSyncApi.h>

/**
 * @internal
 * @def EDMA3_ECAPEVT0_CHA_NUM
 *      EDMA3_ECAPEVT0_CHA_NUM
 */
#define EDMA3_ECAPEVT0_CHA_NUM              (38U)

/**
 * @internal
 * @def EDMA3_ECAPEVT0_LINK_CHA_NUM
 *      EDMA3_ECAPEVT0_LINK_CHA_NUM
 */
#define EDMA3_ECAPEVT0_LINK_CHA_NUM         (39U)

/**
 * @internal
 * @def EDMA3_CLEAR_ECAP_CHA_NUM
 *      EDMA3_CLEAR_ECAP_CHA_NUM
 */
#define EDMA3_CLEAR_ECAP_CHA_NUM            (40U)

/**
 * @internal
 * @def EDMA3_CLEAR_ECAP_LINK_CHA_NUM
 *      EDMA3_CLEAR_ECAP_LINK_CHA_NUM
 */
#define EDMA3_CLEAR_ECAP_LINK_CHA_NUM       (41U)

/**
 * @internal
 * @def EDMA3_SYNC0_RETRIGGER_CHA_NUM
 *      EDMA3_SYNC0_RETRIGGER_CHA_NUM
 */
#define EDMA3_SYNC0_RETRIGGER_CHA_NUM       (42)

/**
 * @internal
 * @def EDMA3_SYNC0_RETRIGGER_LINK_CHA_NUM
 *      EDMA3_SYNC0_RETRIGGER_LINK_CHA_NUM
 */
#define EDMA3_SYNC0_RETRIGGER_LINK_CHA_NUM  (43)

/**
 * @internal
 * @def EVT_QUEUE_NUM
 *      EDMA3 Event queue number
 */
#define EVT_QUEUE_NUM                       (0)

/* OPT Field specific defines */
#define OPT_SYNCDIM_SHIFT                   (0x00000002u)
#define OPT_TCC_MASK                        (0x0003F000u)
#define OPT_TCC_SHIFT                       (0x0000000Cu)
#define OPT_ITCINTEN_SHIFT                  (0x00000015u)
#define OPT_TCINTEN_SHIFT                   (0x00000014u)
#define OPT_STATIC_SHIFT                    (0x00000003u)

/**
 * @internal
 * @def MULTIPLICATION_FACTOR
 *      Used to calculate ecap period. Is SoC specific
 */
#if  defined(SOC_AM437x)
#define   MULTIPLICATION_FACTOR     10
#else
#define   MULTIPLICATION_FACTOR     5
#endif

/** @addtogroup PTP_API
 @{ */
/**
 *  @brief Init function which calls other API's to initialize ECAP and EDMA modules
 *  @param timeSyncHandle Pointer to PTP Handle
 *
 *  @retval Error value
 *
 */
int32_t TimeSync_ecapEdmaConfig(TimeSync_ParamsHandle_t timeSyncHandle);

/**
 *  @internal
 *  @brief Initialize ECAP module
 *
 *  @param args timeSyncHandle Pointer to PTP Handle
 *
 *  @retval None
 *
 */
void TimeSync_initEcap(TimeSync_ParamsHandle_t timeSyncHandle);

/**
 *  @internal
 *  @brief Initialize ECAP module
 *
 *  @param args timeSyncHandle Pointer to PTP Handle
 *
 *  @retval Error value
 *
 */
int32_t TimeSync_edmaConfig(TimeSync_ParamsHandle_t timeSyncHandle);

/**
 *  @internal
 *  @brief Computes the ECAP period and adjustment value (per cycle) from the clock drift/offset
 *
 *  @param args timeSyncHandle Pointer to PTP Handle
 *  @param args adjOffset Current clock drift/offset from master
 *
 *  @retval None
 *
 */
void TimeSync_adjTimeEcapEdma(TimeSync_ParamsHandle_t timeSyncHandle,
                              int32_t adjOffset);

/**
@}
*/
#endif /* ICSS_TIMESYNC_ECAP_EDMA_H_ */
