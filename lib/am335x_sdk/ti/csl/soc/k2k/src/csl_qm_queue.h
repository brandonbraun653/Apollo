/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2011-2013
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
 *   @file  csl_qm_queue.h
 *
 *   @brief  
 *      This is the Queue Manager device specific include file. This file defines various queue 
 *      types
 * 
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2011-2012, Texas Instruments, Inc.
 *  @n   Use of this software is controlled by the terms and conditions found 
 *  @n   in the license agreement under which this software has been supplied.
 *  ===========================================================================
 *  \par
 */

/** @defgroup CSL_QMSS_API QMSS
 *
 */
#ifndef CSL_QMSS_QUEUE_K2K_H
#define CSL_QMSS_QUEUE_K2K_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl.h>

/* Queue mapping as per version 2.3.2 interrupt spec */

/** 
 * @brief Queue start number and maximum number of each type of queue supported.
 */
#define QMSS_LOW_PRIORITY_QUEUE_BASE                0
#define QMSS_MAX_LOW_PRIORITY_QUEUE               512

#define QMSS_AIF_QUEUE_BASE                       512
#define QMSS_MAX_AIF_QUEUE                        128

#define QMSS_PASS_QUEUE_BASE                      640
#define QMSS_MAX_PASS_QUEUE                         9

/* Broadcast to CPINTC 0/1/2 */
#define QMSS_INTC_SET1_QUEUE_BASE                 652
#define QMSS_MAX_INTC_SET1_QUEUE                    6
/* For backward compatibility */
#define QMSS_INTC_QUEUE_BASE     QMSS_INTC_SET1_QUEUE_BASE
#define QMSS_MAX_INTC_QUEUE      QMSS_MAX_INTC_SET1_QUEUE

/* Broadcast to CPINTC 0/1/2, GIC, EDMA 4 and Hyperlink */
#define QMSS_INTC_SET2_QUEUE_BASE                 658
#define QMSS_MAX_INTC_SET2_QUEUE                    8

/* Broadcast to CPINTC 0/1/2 */
#define QMSS_INTC_SET3_QUEUE_BASE                 666
#define QMSS_MAX_INTC_SET3_QUEUE                    6

#define QMSS_SRIO_QUEUE_BASE                      672
#define QMSS_MAX_SRIO_QUEUE                        16

#define QMSS_FFTC_A_QUEUE_BASE                    688
#define QMSS_MAX_FFTC_A_QUEUE                       4

#define QMSS_FFTC_B_QUEUE_BASE                    692
#define QMSS_MAX_FFTC_B_QUEUE                       4

#define QMSS_HIGH_PRIORITY_QUEUE_BASE             704
#define QMSS_MAX_HIGH_PRIORITY_QUEUE               32
#define QMSS_STARVATION_COUNTER_QUEUE_BASE        736
#define QMSS_MAX_STARVATION_COUNTER_QUEUE          64

#define QMSS_QM1_INFRASTRUCTURE_DMA_QUEUE_BASE    800
#define QMSS_MAX_QM1_INFRASTRUCTURE_DMA_QUEUE      32
/* For backward compatibility */
#define QMSS_INFRASTRUCTURE_QUEUE_BASE   QMSS_QM1_INFRASTRUCTURE_DMA_QUEUE_BASE
#define QMSS_MAX_INFRASTRUCTURE_QUEUE    QMSS_MAX_QM1_INFRASTRUCTURE_DMA_QUEUE

#define QMSS_TRAFFIC_SHAPING_QUEUE_BASE           832
#define QMSS_MAX_TRAFFIC_SHAPING_QUEUE             32

#define QMSS_BCP_QUEUE_BASE                       864
#define QMSS_MAX_BCP_QUEUE                          8

#define QMSS_FFTC_C_QUEUE_BASE                    872
#define QMSS_MAX_FFTC_C_QUEUE                       4

#define QMSS_FFTC_D_QUEUE_BASE                    876
#define QMSS_MAX_FFTC_D_QUEUE                       4

#define QMSS_FFTC_E_QUEUE_BASE                    880
#define QMSS_MAX_FFTC_E_QUEUE                       4

#define QMSS_FFTC_F_QUEUE_BASE                    884
#define QMSS_MAX_FFTC_F_QUEUE                       4

#define QMSS_GENERAL_PURPOSE_QUEUE_BASE           896
#define QMSS_MAX_GENERAL_PURPOSE_QUEUE           7296

#define QMSS_QM2_LOW_PRIORITY_QUEUE_BASE         8192
#define QMSS_MAX_QM2_LOW_PRIORITY_QUEUE           512

#define QMSS_GIC400_QUEUE_BASE                   8704
#define QMSS_MAX_GIC400_QUEUE                      32

#define QMSS_EDMA4_QUEUE_BASE                    8736
#define QMSS_MAX_EDMA4_QUEUE                        8

#define QMSS_BCAST_HYPERLINK_0_1_QUEUE_BASE      8744
#define QMSS_MAX_BCAST_HYPERLINK_0_1_QUEUE          8

#define QMSS_XGE_QUEUE_BASE                      8752
#define QMSS_MAX_XGE_QUEUE                          8

#define QMSS_HYPERLINK_0_QUEUE_BASE              8796
#define QMSS_MAX_HYPERLINK_0_QUEUE                 16

#define QMSS_DXB_QUEUE_BASE                      8812
#define QMSS_MAX_DXB_QUEUE                         32

/* Broadcast to CPINTC 0/1/2 */                  
#define QMSS_INTC_SET4_QUEUE_BASE                8844
#define QMSS_MAX_INTC_SET4_QUEUE                   20

#define QMSS_HYPERLINK_1_QUEUE_BASE              8864
#define QMSS_MAX_HYPERLINK_1_QUEUE                 16

#define QMSS_QM2_HIGH_PRIORITY_QUEUE_BASE        8896   /* 704 + 8192 */
#define QMSS_MAX_QM2_HIGH_PRIORITY_QUEUE           32
#define QMSS_QM2_STARVATION_COUNTER_QUEUE_BASE   8928
#define QMSS_MAX_QM2_STARVATION_COUNTER_QUEUE      64

#define QMSS_QM2_INFRASTRUCTURE_DMA_QUEUE_BASE   8992
#define QMSS_MAX_QM2_INFRASTRUCTURE_DMA_QUEUE      32

#define QMSS_QM2_GENERAL_PURPOSE_QUEUE_BASE      9024
#define QMSS_MAX_QM2_GENERAL_PURPOSE_QUEUE       7360

#ifdef __cplusplus
}
#endif

#endif /* CSL_QMSS_QUEUE_K2K_H */
