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
 *  @file   csl_tac2_regsFEAux.h
 *
 *  @brief  This file contains the enumerations, type definitions and function
 *          declarations for the CSL function layer for the TAC2 Front-End
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
@defgroup CSL_TAC_FE_API TAC2 Front-End
*/

/**
@defgroup CSL_TAC_FE_ENUM TAC2 Front-End Enumerated Data Types
@ingroup CSL_TAC_FE_API
*/

/**
@defgroup CSL_TAC_FE_DATASTRUCT TAC2 Front-End Data Structures
@ingroup CSL_TAC_FE_API
*/

/**
@defgroup CSL_TAC_FE_FUNCTION TAC2 Front-End Functions
@ingroup CSL_TAC_FE_API
*/

#ifndef CSL_TAC2_FE_AUX_H
#define CSL_TAC2_FE_AUX_H

#include <ti/csl/src/ip/tac2/V0/csl_tac2_regs.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus  */

/** @addtogroup CSL_TAC_FE_ENUM
@{
*/

/**
 *  @brief   Enumeration for specifying \a CSL_TAC_FE_getEnableStatus output.
 *
 */
typedef enum
{
    /** The Front-End is disabled. */
    CSL_TAC_FE_Disabled  = 0,

    /** The Front-End is enabled. */
    CSL_TAC_FE_Enabled   = 1

} CSL_TAC_FE_enableStatus;

/**
 *  @brief   Enumeration for specifying \a CSL_TAC_FE_getResetStatus output.
 *
 */
typedef enum
{
    /** The Front-End is in reset state. */
    CSL_TAC_FE_Reset     = 0,

    /** The Front-End is not in reset state. */
    CSL_TAC_FE_NotReset  = 1

} CSL_TAC_FE_resetStatus;

/**
 *  @brief   Enumeration for specifying \a CSL_TAC_FE_getStatus output.
 *
 */
typedef enum
{
    /** The FE is idle. */
    CSL_TAC_FE_status_Idle   = 0,

    /** The FE is busy. */
    CSL_TAC_FE_status_Busy   = 1

} CSL_TAC_FE_statusBit;

/**
 *  @brief   Enumeration for setting up the FE Watch dog.
 *
 */
typedef enum
{
    /** Disable the Watchdog. */
    CSL_TAC_FE_wdInterrupt_Enable = 0,

    /** Enable the Watchdog. */
    CSL_TAC_FE_wdInterrupt_Disable = 1

} CSL_TAC_FE_wdEnableFlag;

/**
@}
*/

/** @addtogroup CSL_TAC_FE_DATASTRUCT
@{
*/

/**
 *  @brief   This descriptor specifies the fields of Watchdog register.
 *
 */
typedef struct
{
    /** Watchdog enable status flag. */
    CSL_TAC_FE_wdEnableFlag enableFlag;

    /** Watchdog count. */
    Uint16                  initCount;

} CSL_TAC_FE_wdStatus;

/**
 *  @brief   This descriptor specifies the fields of the Transaction Error
 *           Interrupt Status register.
 *
 */
typedef struct
{
    /** The master ID on which the error occurred. */
    Uint8  masterId;

    /** The last available Transaction ID before the error occured. */
    Uint8  transId;

    /** Status of the error. A 1 indicates that an error occured. */
    Uint8  errorFlag;

} CSL_TAC_FE_transErrorInterruptStatus;

/**
 *  @brief   This descriptor specifies the fields of the peripheral Id
 *           register.
 *
 */
typedef struct
{
    /** Specifies the Minor Revision number. */
    Uint8  minorRevNum;

    /** Specifies the Custom Revision number. */
    Uint8  customRevNum;

    /** Specifies the Major Revision number. */
    Uint8  majorRevNum;

    /** Specifies the RTL Revision number. */
    Uint8  rtlRevNum;

    /** Specifies the Peripheral Id (0x807) */
    Uint16 peripheralId;

    /** Specifies the Scheme (0x1 - New Scheme). */
    Uint8  scheme;

} CSL_TAC_FE_PeripheralId_req;

/**
@}
*/


/* =============================================================================
 * Functions linked to FE management
 * =============================================================================
 */

extern void CSL_TAC_FE_enable(
        Uint8 feiInst
);

extern void CSL_TAC_FE_disable(
        Uint8 feiInst
);

extern CSL_TAC_FE_enableStatus CSL_TAC_FE_getEnableStatus(
        Uint8 feiInst
);

extern void CSL_TAC_FE_softwareReset(void);

extern CSL_TAC_FE_resetStatus CSL_TAC_FE_getResetStatus(
        Uint8   feiInst
);

extern CSL_TAC_FE_statusBit CSL_TAC_FE_getStatus(
        Uint8 feiInst
);

extern void CSL_TAC_FE_getPeripheralID(
        CSL_TAC_FE_PeripheralId_req * peripheralId,
        Uint8                         feiInst
);

extern void CSL_TAC_FE_setHeadPriority(
        Uint8 feiInst,
        Uint8 priority
);

extern Uint8 CSL_TAC_FE_getHeadPriority(
        Uint8 feiInst
);

extern void CSL_TAC_FE_setDataPriority(
        Uint8 feiInst,
        Uint8 priority
);

extern Uint8 CSL_TAC_FE_getDataPriority(
        Uint8 feiInst
);

extern void CSL_TAC_FE_setWarnPriority(
        Uint8 feiInst,
        Uint8 priority
);

extern Uint8 CSL_TAC_FE_getWarnPriority(
        Uint8 feiInst
);

extern void CSL_TAC_FE_setCPMPriority(
        Uint8 feiInst,
        Uint8 priority
);

extern Uint8 CSL_TAC_FE_getCPMPriority(
        Uint8 feiInst
);

extern void CSL_TAC_FE_setWatchDog(
        Uint8                       feiInst,
        const CSL_TAC_FE_wdStatus * wdStatus
);

extern void CSL_TAC_FE_getWatchDogStatus(
        Uint8                 feiInst,
        CSL_TAC_FE_wdStatus * wdStatus
);

extern void CSL_TAC_FE_getTransErrorIntStatus(
        Uint8                                  feiInst,
        CSL_TAC_FE_transErrorInterruptStatus * transErrIntStatus
);

extern void CSL_TAC_FE_clearTransErrorIntStatus(
        Uint8 feiInst
);

/* =============================================================================
 * Functions linked to VBUS Stats registers
 * =============================================================================
 */

extern Uint16 CSL_TAC_Stats_getCfgReadAccess(void);

extern Uint16 CSL_TAC_Stats_getCfgWriteAccess(void);

extern Uint16 CSL_TAC_Stats_getCfgTotalAccess(void);

extern Uint16 CSL_TAC_Stats_getSlaveReadAccess(void);

extern Uint16 CSL_TAC_Stats_getSlaveWriteAccess(void);

extern Uint16 CSL_TAC_Stats_getSlaveTotalAccess(void);

extern Uint16 CSL_TAC_Stats_getMasterReadAccess(
    Uint8 feiInst
);

extern Uint16 CSL_TAC_Stats_getMasterWriteAccess(
    Uint8 feiInst
);

extern Uint16 CSL_TAC_Stats_getMasterTotalAccess(
    Uint8 feiInst
);


#ifdef __cplusplus
}
#endif /* __cplusplus  */

#endif /* CSL_TAC2_FE_AUX_H  */

