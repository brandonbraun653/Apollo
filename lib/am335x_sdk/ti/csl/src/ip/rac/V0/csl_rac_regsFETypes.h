/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2002, 2003, 2004, 2005, 2006, 2018
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
 *   @file  csl_rac_regsFETypes.h
 *
 *   @brief  
 *      This file contains all the RAC CSL specific data types and enumeration
 *      types definitions. 
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002, 2003, 2004, 2005, 2006, Texas Instruments, Inc.
 *  @n   Use of this software is controlled by the terms and conditions found 
 *  @n   in the license agreement under which this software has been supplied.
 *  ===========================================================================
 *  \par 
 */
/**
@defgroup CSL_RAC_FE_API RAC Front-End 
*/

/**
@defgroup CSL_RAC_FE_ENUM RAC Front-End Enumerated Data Types
@ingroup CSL_RAC_FE_API
*/

/**
@defgroup CSL_RAC_FE_DATASTRUCT RAC Front-End Data Structures
@ingroup CSL_RAC_FE_API
*/

/**
@defgroup CSL_RAC_FE_FUNCTION RAC Front-End Functions
@ingroup CSL_RAC_FE_API
*/

#ifndef CSL_RAC_FE_TYPES_H
#define CSL_RAC_FE_TYPES_H

#include <ti/csl/csl_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CSL_RAC_FE_ENUM
@{
*/

/** 
 *  @brief  CSL_RAC_FE_transferState
 *          Enumeration for specifying getFEStatus output.
 */
typedef enum
{
    /** The Front End is waiting for the timestamp write. */        
	CSL_RAC_FE_transferState_WaitingTimestamp   = 0,

    /** The Front End receives samples. */
	CSL_RAC_FE_transferState_ReceivingSamples   = 1,

    /** The Front End has received all samples and is ready 
     *  to start the GCCPs. 
     */
	CSL_RAC_FE_transferState_ReadyToStart       = 2,

    /** The Front End enables the GCCPs. */
	CSL_RAC_FE_transferState_StartGccpIteration = 3
} CSL_RAC_FE_transferState;

/** 
 *  @brief  CSL_RAC_FE_gccpStatus    
 *          Enumeration for specifying getGccpStatus output.
 */
typedef enum
{
    /** The GCCP is idle. The Data memories are accessible 
     *  for debug.
     */      
	CSL_RAC_FE_gccpStatus_Idle   = 0,

    /** The GCCP is busy. The Data memories are not accessible 
     *  for debug.
     */
	CSL_RAC_FE_gccpStatus_Busy   = 1
} CSL_RAC_FE_gccpStatus;

/** 
 *  @brief  CSL_RAC_FE_wdInterruptStatus    
 *          Enumeration for specifying getWatchDogInterruptStatus 
 *          output.
 */
typedef enum
{
    /** No interrupt has been generated. */        
	CSL_RAC_FE_wdInterruptStatus_NoInt = 0,

    /** An interrupt has been generated and forwarded 
     *  to the BEII.
     */
	CSL_RAC_FE_wdInterruptStatus_Int   = 1
} CSL_RAC_FE_wdInterruptStatus;

/**
@}
*/

/** @addtogroup CSL_RAC_FE_DATASTRUCT
@{
*/

/**
 *  @brief  CSL_RAC_FE_Timestamp_req
 *          This descriptor specifies the parameters required 
 *          to setup a timestamp. 
 */
typedef struct CSL_RAC_FE_Timestamp_req_s
{
    /** Specifies the chip value.  */
    Uint16 chipId;

    /** Specifies the slot value.  */
    Uint16 frameId;

    /** Specifies the frame value. */
    Uint8  slotId;
} CSL_RAC_FE_Timestamp_req;

/**
 *  @brief  CSL_RAC_FE_resetStatus   
 *          Enumeration for specifying CSL_RAC_FE_getResetStatus 
 *          output.
 *
 */
typedef enum
{
    /** The Front-End is in reset state. */
	CSL_RAC_FE_Reset     = 0,

    /** The Front-End is not in reset state. */
	CSL_RAC_FE_NotReset  = 1

} CSL_RAC_FE_resetStatus;

/**
@}
*/


#ifdef __cplusplus
}
#endif

#endif

