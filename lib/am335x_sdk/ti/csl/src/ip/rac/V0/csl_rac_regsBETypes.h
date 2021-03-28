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
 *  @file  csl_rac_regsBETypes.h
 *
 *  @brief  
 *      This file contains all the RAC CSL specific data types and enumeration
 *      types. 
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002, 2003, 2004, 2005, 2006, Texas Instruments, Inc.
 *  @n   Use of this software is controlled by the terms and conditions found 
 *  @n   in the license agreement under which this software has been supplied.
 *  ===========================================================================
 *  \par 
 */
/**
@defgroup CSL_RAC_BE_API RAC Back-End 
*/

/**
@defgroup CSL_RAC_BE_ENUM RAC Back-End Enumerated Data Types
@ingroup CSL_RAC_BE_API
*/

/**
@defgroup CSL_RAC_BE_DATASTRUCT RAC Back-End Data Structures
@ingroup CSL_RAC_BE_API
*/

/**
@defgroup CSL_RAC_BE_FUNCTION RAC Back-End Functions
@ingroup CSL_RAC_BE_API
*/
#ifndef CSL_RAC_BE_TYPES_H
#define CSL_RAC_BE_TYPES_H

#include <ti/csl/csl_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CSL_RAC_BE_ENUM
@{
*/

/** 
 *  @brief  CSL_RAC_BETI_statusBit
 *
 *          Enumeration for specifying getBETIStatus output.
 */
typedef enum
{
    /** BETI is disabled. */
    CSL_RAC_BETI_statusBit_Disable, 

    /** BETI is enabled. */
    CSL_RAC_BETI_statusBit_Enable
} CSL_RAC_BETI_statusBit;

/** 
 *  @brief  CSL_RAC_BETI_wdInterruptStatus    
 *          Enumeration for specifying getWatchDogInterruptStatus 
 *          output.
 */
typedef enum
{
    /** No interrupt has been generated. */
	CSL_RAC_BETI_wdInterruptStatus_NoInt = 0,

    /** An interrupt has been generated and 
     *   forwarded to the BEII.
     */
	CSL_RAC_BETI_wdInterruptStatus_Int   = 1
} CSL_RAC_BETI_wdInterruptStatus;

/** 
 *  @brief  CSL_RAC_BETI_odbtStatusBit
 *          Enumeration for specifying getOdbtStatus output.
 */
typedef enum 
{
    /** No new Output Block Descriptor has been 
     *   generated.        
     */
    CSL_RAC_BETI_odbtStatusBit_noNewObd = 0, 

    /** A new Output Block Descriptor has been 
     *  written to the buffer.
     */
    CSL_RAC_BETI_odbtStatusBit_newObd   = 1
} CSL_RAC_BETI_odbtStatusBit;

/** 
 *  @brief  CSL_RAC_BEII_interrupt    
 *          Enumeration for specifying interrupt enables.
 */
typedef enum
{
    /** No interrupt forwarded. */
    CSL_RAC_BEII_interrupt_Disable = 0, 

    /** Interrupt forwarded. */
    CSL_RAC_BEII_interrupt_Enable  = 1
} CSL_RAC_BEII_interrupt;

/** 
 *  @brief  CSL_RAC_BETI_readParamsUpdateStatus
 *          Enumeration for specifying getReadParamsUpdateStatus.
 */
typedef enum
{
    /** No pending request. A new request can be sent. */     
    CSL_RAC_BETI_readParamsUpdateStatus_Idle    = 0, 
   
    /** A current request is still pending. No new request 
     *  can be sent. 
     */
    CSL_RAC_BETI_readParamsUpdateStatus_Pending = 1
} CSL_RAC_BETI_readParamsUpdateStatus;

/**
@}
*/

/** @addtogroup CSL_RAC_BE_DATASTRUCT
@{
*/


/**
 *  @brief  CSL_RAC_BEII_interruptStatus
 *          This descriptor specifies the parameters obtained 
 *          from the interrupt status register. 
 */
typedef struct CSL_RAC_BEII_interruptStatus_s
{
    /** Denotes the GCCP1 Watchdog status. */       
	Uint8 gccp1WdStat;

    /** Denotes the GCCP0 Watchdog status. */
	Uint8 gccp0WdStat;

    /** Denotes the Front-end Watchdog status. */
	Uint8 feWdStat;

    /** Denotes the BETI ODBT read pointer crossing status. */
	Uint8 odbtRdPtrStat;

    /** Denotes the BETI OBBT read pointer crossing status. */
	Uint8 obbtRdPtrStat;

    /** Denotes the BETI 'end-of-transfer' status. */
	Uint8 eotStat;

    /** Denotes the GCCP1 Sequencer Idle status. */
	Uint8 gccp1SeqStat;

    /** Denotes the GCCP1 FIFO Overflow status. */
	Uint8 gccp1FifoOverStat;

    /** Denotes the GCCP#1 Cycle Overflow status. */
	Uint8 gccp1CycOverStat;

    /** Denotes the GCCP0 Sequencer Idle status. */
	Uint8 gccp0SeqStat;

    /** Denotes the GCCP0 FIFO Overflow status. */
	Uint8 gccp0FifoOverStat;

    /** Denotes the GCCP0 Cycle Overflow status. */
	Uint8 gccp0CycOverStat;

} CSL_RAC_BEII_interruptStatus;

/**
@}
*/


#ifdef __cplusplus
}
#endif

#endif

