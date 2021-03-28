/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2012-2013
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
 *      This is the Queue Manager device specific include file. This file defines 
 *      various queue types
 * 
 */

/** @defgroup CSL_QMSS_API QMSS
 *
 */
#ifndef CSL_QMSS_QUEUE_K2E_H
#define CSL_QMSS_QUEUE_K2E_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl.h>
#include "csl_device_interrupt.h"

/* Refer "csl_device_interrupt.h" for queue mapping definitions */

/** 
 * @brief Queue start number and maximum number of each type of NSS (PASS local) queue supported.
 *
 * @note These queues belong to the NSS internal QMSS, which are only used to transfter packets within
 *       NSS via the NSS internal PKTDMA
 */

#define QMSS_NETSS_PASS_QUEUE_BASE                  0
#define QMSS_MAX_NETSS_PASS_QUEUE                   21  

#define QMSS_NETSS_GENERAL_PURPOSE_QUEUE_BASE       21
#define QMSS_MAX_NETSS_GENERAL_PURPOSE_QUEUE        43

#define QMSS_NETSS_GENERAL_PURPOSE_QUEUE_BASE2      64
#define QMSS_MAX_NETSS_GENERAL_PURPOSE_QUEUE2       64

/* ========================================================================= */
/* ========================================================================= */

/* Followings defines are used for maintaining backward compatibility */

#define QMSS_INTC_QUEUE_BASE                        QMSS_CIC_SET_1_QUEUE_BASE
#define QMSS_MAX_INTC_QUEUE                         QMSS_MAX_CIC_SET_1_QUEUE

#define QMSS_INFRASTRUCTURE_QUEUE_BASE              QMSS_QMSS_PKTDMA_QUEUE_BASE
#define QMSS_MAX_INFRASTRUCTURE_QUEUE               QMSS_MAX_QMSS_PKTDMA_QUEUE

#define QMSS_PASS_QUEUE_BASE                        QMSS_NETCP_QUEUE_BASE
/* 
 * There are 128 (QMSS_MAX_NETCP_QUEUE) reserved for NSS Gen 2, but only 21 
 * queues are connected to the corresponding IP sub-modules.
 */
#define QMSS_MAX_PASS_QUEUE                         21


#ifdef __cplusplus
}
#endif

#endif /* CSL_QMSS_QUEUE_K2E_H */
