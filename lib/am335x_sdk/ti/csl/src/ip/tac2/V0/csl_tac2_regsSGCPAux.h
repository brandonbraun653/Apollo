/********************************************************************
 * Copyright (C) 2003-2011 Texas Instruments Incorporated.
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
 *  @file   csl_tac2_regsSGCPAux.h
 *
 *  @brief  This file contains the enumerations, type definitions and function
 *          declarations for the CSL function layer for the TAC2 SGCP
 *          interface.
 *
 *  @date   05-Oct-2011
 *  @author Vijay Pothukuchi
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2011, Texas Instruments, Inc.
 *  @n   Use of this software is controlled by the terms and conditions found
 *  @n   in the license agreement under which this software has been supplied.
 *  ===========================================================================
 *  \par
 */

/* =============================================================================
 *  Revision History
 *  ===============
 *  05-Oct-2011   VP    File Created
 * =============================================================================
 */

/**
@defgroup CSL_TAC_SGCP_API TAC2 SGCP
*/

/**
@defgroup CSL_TAC_SGCP_DATASTRUCT TAC2 SGCP Data Structures
@ingroup CSL_TAC_SGCP_API
*/

/**
@defgroup CSL_TAC_SGCP_FUNCTION TAC2 SGCP Functions
@ingroup CSL_TAC_SGCP_API
*/

#ifndef CSL_TAC2_SGCP_AUX_H
#define CSL_TAC2_SGCP_AUX_H

#include <ti/csl/src/ip/tac2/V0/csl_tac2_regs.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup CSL_TAC_SGCP_DATASTRUCT
@{
*/

/**
 *  @brief   This descriptor specifies the parameters obtained
 *           when reading the cycle overflow status register.
 *
 */
typedef struct
{
    /** Denotes the iteration number. */
    Uint16 iteNb;

    /** Denotes the overflow status. */
    Uint8  overflowFlag;

    /** Denotes the page index. */
    Uint8  pageIdx;

    /** Denotes the task index. */
    Uint8  taskIdx;

} CSL_TAC_SGCP_cycleOverflowStatus;

/**
 *  @brief   This descriptor specifies the parameters obtained
 *           when reading the FIFO overflow status register.
 *
 */
typedef struct
{
    /** Denotes the iteration number. */
    Uint16 iteNb;

    /** Denotes the FIFO ID */
    Uint8  fifoId;

    /** Denotes the cycle overflow flag */
    Uint8  overflowFlag;

    /** Denotes the page index. */
    Uint8  pageIdx;

    /** Denotes the task index. */
    Uint8  taskIdx;

} CSL_TAC_SGCP_fifoOverflowStatus;

/**
 *  @brief   This descriptor specifies the parameters obtained
 *           when reading the symbol buffer miss status register.
 *
 */
typedef struct
{
    /** Denotes the iteration number. */
    Uint16 iteNb;

    /** Denotes the cycle overflow flag */
    Uint8  writeMissFlag;

    /** Denotes the page index. */
    Uint8  pageIdx;

    /** Denotes the task index. */
    Uint8  taskIdx;

} CSL_TAC_SGCP_symbolBuffMissStatus;

/**
 *  @brief   This descriptor specifies the parameters that comprise the
 *           time stamp.
 */
typedef struct
{
    /** Specifies the chip value. */
    Uint16 chipId;

    /** Specifies the frame value. */
    Uint16 frameId;

    /** Specifies the slot value. */
    Uint8  slotId;

} CSL_TAC_SGCP_Timestamp_req;

/**
@}
*/


/* =============================================================================
 * Functions linked to SGCP management
 * =============================================================================
 */

extern void CSL_TAC_SGCP_enable(
    Uint8 sgcpId
);

extern void CSL_TAC_SGCP_disable(
    Uint8 sgcpId
);

extern Uint16 CSL_TAC_SGCP_getActiveCycles(
    Uint8 sgcpId
);

extern Uint16 CSL_TAC_SGCP_getSequencerCycles(
    Uint8 sgcpId
);

extern void CSL_TAC_SGCP_getReadTime(
    CSL_TAC_SGCP_Timestamp_req * timestamp
);

extern void CSL_TAC_SGCP_getCycleOverflowStatus(
    Uint8                              sgcpId,
    CSL_TAC_SGCP_cycleOverflowStatus * cycleOverflowStatus
);

extern void CSL_TAC_SGCP_resetCycleOverflowStatus(
    Uint8 sgcpId
);

extern void CSL_TAC_SGCP_getSymbolBuffMissStatus(
    Uint8                               sgcpId,
    CSL_TAC_SGCP_symbolBuffMissStatus * symBuffMissStatus
);

extern void CSL_TAC_SGCP_resetSymbolBuffMissStatus(
    Uint8 sgcpId
);

extern void CSL_TAC_SGCP_getFIFOOverflowStatus(
    Uint8                             sgcpId,
    CSL_TAC_SGCP_fifoOverflowStatus * fifoOverflowStatus
);

extern void CSL_TAC_SGCP_resetFIFOOverflowStatus(
    Uint8 sgcpId
);

extern Uint32 CSL_TAC_SGCP_getFetchQLevel(
    Uint8 sgcpId
);

extern Uint32 CSL_TAC_SGCP_getFetchQWatermark(
    Uint8 sgcpId
);

extern void CSL_TAC_SGCP_resetFetchQueue(
    Uint8 sgcpId
);

extern Uint32 CSL_TAC_SGCP_getCPMQLevel(
    Uint8 sgcpId
);

extern Uint32 CSL_TAC_SGCP_getCPMQWatermark(
    Uint8 sgcpId
);

extern void CSL_TAC_SGCP_resetCPMQueue(
    Uint8 sgcpId
);

extern Uint32 CSL_TAC_SGCP_getWarningQLevel(
    Uint8 sgcpId
);

extern Uint32 CSL_TAC_SGCP_getWarningQWatermark(
    Uint8 sgcpId
);

extern void CSL_TAC_SGCP_resetWarningQueue(
    Uint8 sgcpId
);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CSL_TAC2_SGCP_AUX_H */

