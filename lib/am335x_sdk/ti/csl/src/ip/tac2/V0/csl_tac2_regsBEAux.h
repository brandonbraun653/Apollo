/********************************************************************
 * Copyright (C) 2003-2013 Texas Instruments Incorporated.
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
 *  @file   csl_tac2_regsBEAux.h
 *
 *  @brief  This file contains the enumerations, type definitions and function
 *          declarations for the CSL function layer for the TAC2 Back-End
 *          interface.
 *
 *  @date   05-Sep-2013
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
@defgroup CSL_TAC_BE_API TAC2 Back-End
*/

/**
@defgroup CSL_TAC_BE_ENUM TAC2 Back-End Enumerated Data Types
@ingroup CSL_TAC_BE_API
*/

/**
@defgroup CSL_TAC_BE_DATASTRUCT TAC2 Back-End Data Structures
@ingroup CSL_TAC_BE_API
*/

/**
@defgroup CSL_TAC_BE_FUNCTION TAC2 Back-End Functions
@ingroup CSL_TAC_BE_API
*/

#ifndef CSL_TAC2_BE_AUX_H
#define CSL_TAC2_BE_AUX_H

#include <ti/csl/src/ip/tac2/V0/csl_tac2_regs.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

/** @addtogroup CSL_TAC_BE_ENUM
@{
*/

/**
 *  @brief   Enumeration for specifying \a CSL_TAC_BETI_getEnableStatus output.
 *
 */
typedef enum
{
    /** The BETI is disabled. */
    CSL_TAC_BETI_Disabled  = 0,

    /** The BETI is enabled. */
    CSL_TAC_BETI_Enabled   = 1

} CSL_TAC_BETI_enableStatus;

/**
 *  @brief   Enumeration for specifying \a CSL_TAC_BEII_getEnableStatus output.
 *
 */
typedef enum
{
    /** The BEII is disabled. */
    CSL_TAC_BEII_Disabled  = 0,

    /** The BEII is enabled. */
    CSL_TAC_BEII_Enabled   = 1

} CSL_TAC_BEII_enableStatus;

/**
 *  @brief   Enumeration for the SGCP status.
 *
 */
typedef enum
{
    /** SGCP is Idle */
    CSL_TAC_BETI_statusBit_Idle,

    /** SGCP is Busy */
    CSL_TAC_BETI_statusBit_Busy

} CSL_TAC_BETI_statusBit;

/**
 *  @brief   Enumeration for specifying
 *           \a CSL_TAC_BETI_getWatchDogInterruptStatus output.
 *
 */
typedef enum
{
    /** No interrupt has been generated. */
    CSL_TAC_BETI_wdInterruptStatus_NoInt = 0,

    /** An interrupt has been generated and forwarded to the BEII. */
    CSL_TAC_BETI_wdInterruptStatus_Int   = 1

} CSL_TAC_BETI_wdInterruptStatus;

/**
 *  @brief   Enumeration for specifying \a CSL_TAC_getStrmPwrMeasMode output.
 *
 */
typedef enum
{
    /** The stream power accumulation length is 1 slot (2560 chips). */
    CSL_TAC_BE_strmPwrMeasMode_SlotMode   = 0,

    /** The stream power accumulation length is 1 Symbol (256 chips). */
    CSL_TAC_BE_strmPwrMeasMode_SymbolMode = 1

} CSL_TAC_BE_strmPwrMeasMode;

/**
@}
*/

/** @addtogroup CSL_TAC_BE_DATASTRUCT
@{
*/

/**
 *  @brief   The descriptor specifies the parameters obtained from the
 *           BETI status register.
 */
typedef struct
{
    /** Status of the SGCP 0 */
    CSL_TAC_BETI_statusBit  sgcp0Status;

    /** Status of the SGCP 1 */
    CSL_TAC_BETI_statusBit  sgcp1Status;

    /** Status of the SGCP 2 */
    CSL_TAC_BETI_statusBit  sgcp2Status;

    /** Status of the SGCP 3 */
    CSL_TAC_BETI_statusBit  sgcp3Status;

    /** Status of the SGCP 4 */
    CSL_TAC_BETI_statusBit  sgcp4Status;

    /** Status of the SGCP 5 */
    CSL_TAC_BETI_statusBit  sgcp5Status;

} CSL_TAC_BETI_status;

/**
 *  @brief   This descriptor specifies the parameters obtained from the
 *           interrupt status register.
 */
typedef struct
{
    /** Denotes the SGCP0 Cycle Overflow status. */
    Uint8 sgcp0CycOverStat;

    /** Denotes the SGCP0 FIFO Overflow status. */
    Uint8 sgcp0FifoOverStat;

    /** Denotes the SGCP0 Sequencer Idle status. */
    Uint8 sgcp0SeqStat;

    /** Denotes the SGCP0 Input Buffer Miss status. */
    Uint8 sgcp0BuffMissStat;

    /** Denotes the SGCP1 Cycle Overflow status. */
    Uint8 sgcp1CycOverStat;

    /** Denotes the SGCP1 FIFO Overflow status. */
    Uint8 sgcp1FifoOverStat;

    /** Denotes the SGCP1 Sequencer Idle status. */
    Uint8 sgcp1SeqStat;

    /** Denotes the SGCP1 Input Buffer Miss status. */
    Uint8 sgcp1BuffMissStat;

    /** Denotes the SGCP2 Cycle Overflow status. */
    Uint8 sgcp2CycOverStat;

    /** Denotes the SGCP2 FIFO Overflow status. */
    Uint8 sgcp2FifoOverStat;

    /** Denotes the SGCP2 Sequencer Idle status. */
    Uint8 sgcp2SeqStat;

    /** Denotes the SGCP2 Input Buffer Miss status. */
    Uint8 sgcp2BuffMissStat;

    /** Denotes the SGCP3 Cycle Overflow status. */
    Uint8 sgcp3CycOverStat;

    /** Denotes the SGCP3 FIFO Overflow status. */
    Uint8 sgcp3FifoOverStat;

    /** Denotes the SGCP3 Sequencer Idle status. */
    Uint8 sgcp3SeqStat;

    /** Denotes the SGCP3 Input Buffer Miss status. */
    Uint8 sgcp3BuffMissStat;

    /** Denotes the SGCP4 Cycle Overflow status. */
    Uint8 sgcp4CycOverStat;

    /** Denotes the SGCP4 FIFO Overflow status. */
    Uint8 sgcp4FifoOverStat;

    /** Denotes the SGCP4 Sequencer Idle status. */
    Uint8 sgcp4SeqStat;

    /** Denotes the SGCP4 Input Buffer Miss status. */
    Uint8 sgcp4BuffMissStat;

    /** Denotes the SGCP5 Cycle Overflow status. */
    Uint8 sgcp5CycOverStat;

    /** Denotes the SGCP5 FIFO Overflow status. */
    Uint8 sgcp5FifoOverStat;

    /** Denotes the SGCP5 Sequencer Idle status. */
    Uint8 sgcp5SeqStat;

    /** Denotes the SGCP5 Input Buffer Miss status. */
    Uint8 sgcp5BuffMissStat;

    /** FE0 transaction error status */
    Uint8 fe0TransErrStat;

    /** FE1 transaction error status */
    Uint8 fe1TransErrStat;

    /** FE2 transaction error status */
    Uint8 fe2TransErrStat;

    /** Denotes the BETI Watchdog status. */
    Uint8 betiWdStat;

} CSL_TAC_BEII_interruptStatus;

/**
 *  @brief   This descriptor specifies the parameters required to setup a
 *           timestamp.
 *
 */
typedef struct
{
    /** Specifies the Chip value. */
    Uint16 chipId;

    /** Specifies the Frame value. */
    Uint16 frameId;

    /** Specifies the Slot value. */
    Uint8  slotId;

} CSL_TAC_BE_Timestamp_req;

/**
@}
*/


/******************************************************************************
 * TAC2 global function declarations
 *****************************************************************************/

/* =============================================================================
 * Functions linked to BETI management
 * =============================================================================
 */

extern void CSL_TAC_BETI_enable(void);

extern void CSL_TAC_BETI_disable(void);

extern CSL_TAC_BETI_enableStatus CSL_TAC_BETI_getEnableStatus(void);

extern void CSL_TAC_BETI_getStatus(
    CSL_TAC_BETI_status * betiStatus
);

extern void CSL_TAC_BETI_setWatchDog(
    Uint16 reloadCnt
);

extern Uint16 CSL_TAC_BETI_getWatchDogStatus(void);

extern CSL_TAC_BETI_wdInterruptStatus CSL_TAC_BETI_getWatchDogInterruptStatus(void);

extern void CSL_TAC_BETI_clearWatchDogInterrupt(void);

/* =============================================================================
 * Functions linked to BEII management
 * =============================================================================
 */

extern void CSL_TAC_BEII_enable(void);

extern void CSL_TAC_BEII_disable(void);

extern CSL_TAC_BEII_enableStatus CSL_TAC_BEII_getEnableStatus(void);

extern void CSL_TAC_BEII_getInterruptStatus(
    CSL_TAC_BEII_interruptStatus * interruptStatus
);

extern void CSL_TAC_BEII_getEnabledInterruptStatus(
    CSL_TAC_BEII_interruptStatus * interruptEnStatus
);

extern void CSL_TAC_BEII_forceInterrupts(
    const CSL_TAC_BEII_interruptStatus * interruptsToForce
);

extern void CSL_TAC_BEII_clearInterrupts(
    const CSL_TAC_BEII_interruptStatus * interruptsToClear
);

extern void CSL_TAC_BEII_enableInterrupts(
    const CSL_TAC_BEII_interruptStatus * interruptsToEnable
);

extern void CSL_TAC_BEII_disableInterrupts(
    const CSL_TAC_BEII_interruptStatus * interruptsToDisable
);

extern void CSL_TAC_BEII_setEOI(
    Uint32 eoiVecValue
);

extern Uint32 CSL_TAC_BEII_getEOI(void);

extern CSL_TAC_BE_strmPwrMeasMode CSL_TAC_BE_getStrmPwrMeasMode(void);

extern void CSL_TAC_BE_setSwIterStart(void);

extern void CSL_TAC_BE_setTimestamp(
    const CSL_TAC_BE_Timestamp_req * timestamp
);

extern void CSL_TAC_BE_getTimestamp(
    CSL_TAC_BE_Timestamp_req * timestamp
);


#ifdef __cplusplus
}
#endif /* __cplusplus  */

#endif /* CSL_TAC2_BE_AUX_H */

