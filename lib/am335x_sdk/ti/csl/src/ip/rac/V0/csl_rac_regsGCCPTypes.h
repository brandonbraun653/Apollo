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
 *   @file  csl_rac_regsGCCPTypes.h
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
@defgroup CSL_RAC_GCCP_API RAC GCCP
*/

/**
@defgroup CSL_RAC_GCCP_DATASTRUCT RAC GCCP Data Structures
@ingroup CSL_RAC_GCCP_API
*/

/**
@defgroup CSL_RAC_GCCP_FUNCTION RAC GCCP Functions
@ingroup CSL_RAC_GCCP_API
*/

#ifndef CSL_RAC_GCCP_TYPES_H
#define CSL_RAC_GCCP_TYPES_H

#include <ti/csl/csl_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CSL_RAC_GCCP_DATASTRUCT
@{
*/

/**
 *  @brief  CSL_RAC_GCCP_cycleOverflowStatus
 *          This descriptor specifies the parameters required obtained
 *          when reading the cycle overflow status register. 
 */
typedef struct CSL_RAC_GCCP_cycleOverflowStatus_s
{
    /** Denotes the iteration Number. */      
    Uint16 iteNb;

    /** Denotes the cycle overflow flag. */
    Uint8  cycOverFlag;

    /** Denotes the page index. */
    Uint8  pageIdx;

    /** Denotes the task index. */
    Uint8  taskIdx;
} CSL_RAC_GCCP_cycleOverflowStatus;

/**
 *  @brief  CSL_RAC_GCCP_fifoOverflowStatus
 *          This descriptor specifies the parameters required obtained
 *          when reading the fifo overflow status register. 
 */
typedef struct CSL_RAC_GCCP_fifoOverflowStatus_s
{
    /** Denotes the iteration Number. */
    Uint16 iteNb;

    /** Denotes the FIFO ID. */
	Uint8  fifoId;

    /** Denotes the cycle overflow flag. */
    Uint8  cycOverFlag;

    /** Denotes the page index. */
    Uint8  pageIdx;

    /** Denotes the page index. */
    Uint8  taskIdx;
} CSL_RAC_GCCP_fifoOverflowStatus;

/**
@}
*/


#ifdef __cplusplus
}
#endif

#endif
