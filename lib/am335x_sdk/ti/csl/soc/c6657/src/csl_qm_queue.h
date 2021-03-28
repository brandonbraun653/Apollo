/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2010-2015
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
 */

/** @defgroup CSL_QMSS_API QMSS
 *
 */
#ifndef CSL_QMSS_QUEUE_C6657_H
#define CSL_QMSS_QUEUE_C6657_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl.h>

/** 
 * @brief Queue start number and maximum number of each type of queue supported.
 */
#define QMSS_LOW_PRIORITY_QUEUE_BASE       	0
#define QMSS_MAX_LOW_PRIORITY_QUEUE         	512
#define QMSS_INTC_QUEUE_BASE                    662
#define QMSS_MAX_INTC_QUEUE                 	10
#define QMSS_SRIO_QUEUE_BASE                    672
#define QMSS_MAX_SRIO_QUEUE                 	16
#define QMSS_HIGH_PRIORITY_QUEUE_BASE           704
#define QMSS_MAX_HIGH_PRIORITY_QUEUE        	32
#define QMSS_STARVATION_COUNTER_QUEUE_BASE  	736
#define QMSS_MAX_STARVATION_COUNTER_QUEUE   	64
#define QMSS_INFRASTRUCTURE_QUEUE_BASE      	800
#define QMSS_MAX_INFRASTRUCTURE_QUEUE       	32
#define QMSS_TRAFFIC_SHAPING_QUEUE_BASE     	832
#define QMSS_MAX_TRAFFIC_SHAPING_QUEUE      	32
#define QMSS_GENERAL_PURPOSE_QUEUE_BASE     	864
#define QMSS_MAX_GENERAL_PURPOSE_QUEUE      	7328

/* Note: Qmss_QueueType moved to ti/drv/qmss/qmss_qm.h */

#ifdef __cplusplus
}
#endif

#endif /* CSL_QMSS_QUEUE_C6657_H */
