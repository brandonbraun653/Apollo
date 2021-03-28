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

/** ============================================================================
 *  @file  csl_tac2_regsFEAux.c
 *
 *  @brief This file contains API implementation for the CSL for the TAC2
 *         Front-End interface.
 *
 *  @date   05-Sep-2013
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2013, Texas Instruments, Inc.
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

#include <ti/csl/src/ip/tac2/V0/csl_tac2_regsFEAux.h>

/** @addtogroup CSL_TAC_FE_FUNCTION
@{
*/

/**
 *  @n@b CSL_TAC_FE_enable
 *
 *  @b Description
 *  @n This function enables an instance of the TAC2 Front End
 *     Interface (FEI).
 *
 *  @b Arguments
 *  @verbatim
    feiInst     Which FEI to enable.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The Front End Interface instance specified is enabled.
 *
 *  @b Writes
 *  @n TAC_CFG_FE_ENA_ENABLE=1
 *
 *  @b Affects
 *  @n TAC_CFG_FE_STAT_STATUS=1
 *
 *  @b Example
 *  @verbatim
    // Enable FEI 0
    CSL_TAC_FE_enable(0);

    // Enable FEI 1
    CSL_TAC_FE_enable(1);

    @endverbatim
 *
 */
void CSL_TAC_FE_enable(
    Uint8 feiInst
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hTacRegs->FE[feiInst].FE_ENA, TAC_CFG_FE_ENA_ENABLE, ENABLE);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(TAC_CFG_FE_ENA_ENABLE, ENABLE);
        addr = (Uint32) &hTacRegs->FE[feiInst].FE_ENA;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_FE_disable
 *
 *  @b Description
 *  @n This function disables an instance of the TAC2 Front End Interface
 *     (FEI).
 *
 *  @b Arguments
 *  @verbatim
    feiInst     Which FEI to disable.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The Front End Interface instance specified is disabled.
 *
 *  @b Writes
 *  @n TAC_CFG_FE_ENA_ENABLE=0
 *
 *  @b Affects
 *  @n TAC_CFG_FE_STAT_STATUS=0
 *
 *  @b Example
 *  @verbatim

    // Disable FEI 0
    CSL_TAC_FE_disable(0);

    // Disable FEI 1
    CSL_TAC_FE_disable(1);

    @endverbatim
 *
 */
void CSL_TAC_FE_disable(
    Uint8 feiInst
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hTacRegs->FE[feiInst].FE_ENA, TAC_CFG_FE_ENA_ENABLE, DISABLE);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(TAC_CFG_FE_ENA_ENABLE, DISABLE);
        addr = (Uint32) &hTacRegs->FE[feiInst].FE_ENA;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_FE_getEnableStatus
 *
 *  @b Description
 *  @n This function returns the enable status of an instance
 *     of the Front-End Interface.
 *
 *  @b Arguments
 *  @verbatim
    feiInst     For which FEI instance to obtain status
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n CSL_TAC_FE_Disabled
 *      The Front-End is disabled.
 *  @n CSL_TAC_FE_Enabled
 *      The Front-End is enabled.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_FE_STAT_STATUS
 *
 *  @b Example
 *  @verbatim

    // Enable FEI 0
    CSL_TAC_FE_enable(0);

    if (CSL_TAC_FE_getEnableStatus(0) != CSL_TAC_FE_Enabled)
    {
        // The FE should have been enabled.
        ...
    }

    ...
    // Disable FEI 0
    CSL_TAC_FE_disable(0);

    if (CSL_TAC_FE_getEnableStatus(0) != CSL_TAC_FE_Disabled)
    {
        // The FE should have been disabled.
        ...
    }
    @endverbatim
 *
 */
CSL_TAC_FE_enableStatus CSL_TAC_FE_getEnableStatus(
    Uint8 feiInst
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->FE[feiInst].FE_STAT;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->FE[feiInst].FE_STAT;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (CSL_TAC_FE_enableStatus) CSL_FEXT (word, TAC_CFG_FE_STAT_STATUS);
}

/**
 *  @n@b CSL_TAC_FE_softwareReset
 *
 *  @b Description
 *  @n This function resets the Front-End.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The HW takes as long as it needs to perform the reset on all state
 *     machines, queues and counters. During that time, the SW can poll the
 *     same register and the reset flag bit remains equal to 1. When the reset
 *     process is finished, the HW clears the reset flag bit to 0. The SW knows
 *     then that the reset process has been completed.
 *
 *  @b Writes
 *  @n TAC_CFG_FE_SW_RESET_RESET=1
 *
 *  @b Affects
 *  @n TAC_CFG_FE_SW_RESET_RESET=0
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_FE_softwareReset();
    @endverbatim
 *
 */
void CSL_TAC_FE_softwareReset(void)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hTacRegs->FE[0].FE_SW_RESET, TAC_CFG_FE_SW_RESET_RESET, RESET);
    CSL_FWRIT (hTacRegs->FE[1].FE_SW_RESET, TAC_CFG_FE_SW_RESET_RESET, RESET);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(TAC_CFG_FE_SW_RESET_RESET, RESET);
        addr = (Uint32) &hTacRegs->FE[0].FE_SW_RESET;
        tacPointer->cfgWordWrite(addr, word);

        addr = (Uint32) &hTacRegs->FE[1].FE_SW_RESET;
        tacPointer->cfgWordWrite(addr, word);

        addr = (Uint32) &hTacRegs->FE[2].FE_SW_RESET;
        tacPointer->cfgWordWrite(addr, word);

    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_FE_getResetStatus
 *
 *  @b Description
 *  @n This function returns the reset status of the Front-End.
 *
 *  @b Arguments
 *  @verbatim
    feiInst     Which FEI instance to check.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n CSL_TAC_FE_Reset
 *      The Front-End is in reset state.
 *  @n CSL_TAC_FE_NotReset
 *      The Front-End is not in reset state.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The HW takes as long as it needs to perform the reset on all state
 *     machines, queues and counters. During that time, the SW can poll the
 *     same register and the reset flag bit remains equal to 1. When the reset
 *     process is finished, the HW clears the reset flag bit to 0. The SW knows
 *     then that the reset process has been completed.
 *
 *  @b Reads
 *  @n TAC_CFG_FE_SW_RESET_RESET
 *
 *  @b Example
 *  @verbatim
    ...
    // Check reset status for FEI 0.
    while(CSL_TAC_FE_getResetStatus(0) == CSL_TAC_FE_NotReset)
    {
        // The FE is not reset yet.
        ...
    }
    @endverbatim
 *
 */
CSL_TAC_FE_resetStatus CSL_TAC_FE_getResetStatus(
    Uint8   feiInst
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->FE[feiInst].FE_SW_RESET;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->FE[feiInst].FE_SW_RESET;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (CSL_TAC_FE_resetStatus) CSL_FEXT (word, TAC_CFG_FE_SW_RESET_RESET);
}

/**
 *  @n@b CSL_TAC_FE_getStatus
 *
 *  @b Description
 *  @n This function returns the Front End Transfer State for a Front End
 *     Interface instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst     Which FEI instance to check.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  CSL_TAC_FE_status_Idle
 *          The FE is idle.
 *  @n  CSL_TAC_FE_status_Busy
 *          The FE is busy.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_FE_STAT_STATUS
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_FE_statusBit    feStatus;

    // Check status of FEI 1
    feStatus = CSL_TAC_FE_getStatus(1);
    @endverbatim
 *
 */
CSL_TAC_FE_statusBit CSL_TAC_FE_getStatus(
    Uint8 feiInst
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->FE[feiInst].FE_STAT;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->FE[feiInst].FE_STAT;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (CSL_TAC_FE_statusBit)
        CSL_FEXT (word, TAC_CFG_FE_STAT_STATUS);
}

/**
 *  @n@b CSL_TAC_FE_getPeripheralID
 *
 *  @b Description
 *  @n This function reads the content of the Peripheral Id register
 *     and returns the revision information for the specified FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    peripheralId    Structure with the peripheral revision information.
    feiInst	    FEI instance for which the ID will be obtained.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_FE_PID_MIN_REV_NB, TAC_CFG_FE_PID_CUS_REV_NB,
 *     TAC_CFG_FE_PID_MAJ_REV_NB, TAC_CFG_FE_PID_RTL_REV_NB,
 *     TAC_CFG_FE_PID_PID, TAC_CFG_FE_PID_SCHEME
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_FE_PeripheralId_req     pid;
    Uint8			    feiInst;

    feiInst = 0; 
    CSL_TAC_FE_getPeripheralID(&pid, feiInst);
    @endverbatim
 */
void CSL_TAC_FE_getPeripheralID(
    CSL_TAC_FE_PeripheralId_req * peripheralId,
    Uint8                         feiInst
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->FE[feiInst].FE_PID;
#else
    Uint32 addr;
    UINT32 tmp;

    addr = (Uint32) &hTacRegs->FE[feiInst].FE_PID;
    tacPointer->cfgWordRead(addr, tmp);
    word = (Uint32)tmp;
#endif

    peripheralId->minorRevNum =
        CSL_FEXT (word, TAC_CFG_FE_PID_MIN_REV_NB);

    peripheralId->customRevNum =
        CSL_FEXT (word, TAC_CFG_FE_PID_CUS_REV_NB);

    peripheralId->majorRevNum =
        CSL_FEXT (word, TAC_CFG_FE_PID_MAJ_REV_NB);

    peripheralId->rtlRevNum =
        CSL_FEXT (word, TAC_CFG_FE_PID_RTL_REV_NB);

    peripheralId->peripheralId =
        CSL_FEXT (word, TAC_CFG_FE_PID_PID);

    peripheralId->scheme =
        CSL_FEXT (word, TAC_CFG_FE_PID_SCHEME);

    return;
}

/**
 *  @n@b CSL_TAC_FE_setHeadPriority
 *
 *  @b Description
 *  @n This function configures the Header Transfer Priority for the
 *     VBUS transfers for the specified FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI Instance for which Header Priority is set.
    priority        VBUS priority to apply to the transfers. The allowed range
                    is [0..7]. The value out of the reset is 7.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The Header Transfer Priority is set.
 *
 *  @b Writes
 *  @n TAC_CFG_FE_HEAD_PRIO_PRIORITY
 *
 *  @b Example
 *  @verbatim
    Uint8    prio;
    Uint8    feiInst;

    feiInst = 1;

    // Reset the Front End
    CSL_TAC_FE_softwareReset();

    // Check for the reset status of FEI 1
    while(CSL_TAC_FE_getResetStatus(feiInst) == CSL_TAC_FE_NotReset);

    // Read the priority
    prio = CSL_TAC_FE_getHeadPriority(feiInst);
    // prio should be 7

    // Change the priority to 3
    CSL_TAC_FE_setHeadPriority(feiInst, 3);

    // Read the priority again
    prio = CSL_TAC_FE_getHeadPriority(feiInst);
    // prio should be 3
    @endverbatim
 *
 */
void CSL_TAC_FE_setHeadPriority(
    Uint8 feiInst,
    Uint8 priority
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRI (hTacRegs->FE[feiInst].FE_HEAD_PRIO,
              TAC_CFG_FE_HEAD_PRIO_PRIORITY, (Uint32)priority);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMK(TAC_CFG_FE_HEAD_PRIO_PRIORITY, priority);
        addr = (Uint32) &hTacRegs->FE[feiInst].FE_HEAD_PRIO;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_FE_getHeadPriority
 *
 *  @b Description
 *  @n This function returns the Header Transfer Priority for the
 *     VBUS transfers for the specified FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI instance for which priority is requested.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  The Header Transfer Priority [0..7].
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_FE_HEAD_PRIO_PRIORITY
 *
 *  @b Example
 *  @verbatim
    Uint8    prio;
    Uint8    feiInst = 1;

    // Change the priority to 3
    CSL_TAC_FE_setHeadPriority(feiInst, 3);

    // Read the priority again
    prio = CSL_TAC_FE_getHeadPriority(feiInst );
    // prio should be 3
    @endverbatim
 *
 */
Uint8 CSL_TAC_FE_getHeadPriority(
    Uint8 feiInst
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->FE[feiInst].FE_HEAD_PRIO;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->FE[feiInst].FE_HEAD_PRIO;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint8)(CSL_FEXT (word, TAC_CFG_FE_HEAD_PRIO_PRIORITY));
}

/**
 *  @n@b CSL_TAC_FE_setDataPriority
 *
 *  @b Description
 *  @n This function configures the Data Transfer Priority for the
 *     VBUS transfers for the specified FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI Instance for which Data Priority is set.
    priority        VBUS priority to apply to the transfers. The allowed range
                    is [0..7]. The value out of the reset is 7.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The Data Transfer Priority is set.
 *
 *  @b Writes
 *  @n TAC_CFG_FE_DATA_PRIO_PRIORITY
 *
 *  @b Example
 *  @verbatim
    Uint8    prio;
    Uint8    feiInst = 0;

    // Reset the Front End
    CSL_TAC_FE_softwareReset();

    // Check for the reset status
    while(CSL_TAC_FE_getResetStatus(feiInst) == CSL_TAC_FE_NotReset);

    // Read the priority
    prio = CSL_TAC_FE_getDataPriority(feiInst);
    // prio should be 7

    // Change the priority to 3
    CSL_TAC_FE_setDataPriority(feiInst, 3);

    // Read the priority again
    prio = CSL_TAC_FE_getDataPriority(feiInst);
    // prio should be 3
    @endverbatim
 *
 */
void CSL_TAC_FE_setDataPriority(
    Uint8 feiInst,
    Uint8 priority
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRI (hTacRegs->FE[feiInst].FE_DATA_PRIO,
              TAC_CFG_FE_DATA_PRIO_PRIORITY, (Uint32)priority);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMK(TAC_CFG_FE_DATA_PRIO_PRIORITY, priority);
        addr = (Uint32) &hTacRegs->FE[feiInst].FE_DATA_PRIO;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_FE_getDataPriority
 *
 *  @b Description
 *  @n This function returns the Data Transfer Priority for the
 *     VBUS transfers for the specified FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI instance for which priority is requested.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  The Data Transfer Priority [0..7].
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_FE_DATA_PRIO_PRIORITY
 *
 *  @b Example
 *  @verbatim
    Uint8    prio;
    Uint8    feiInst = 1;

    // Set the priority to 3
    CSL_TAC_FE_setDataPriority(feiInst, 3);

    // Read the priority
    prio = CSL_TAC_FE_getDataPriority(feiInst);
    // prio should be 3
    @endverbatim
 *
 */
Uint8 CSL_TAC_FE_getDataPriority(
    Uint8 feiInst
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->FE[feiInst].FE_DATA_PRIO;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->FE[feiInst].FE_DATA_PRIO;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint8)(CSL_FEXT (word, TAC_CFG_FE_DATA_PRIO_PRIORITY));
}

/**
 *  @n@b CSL_TAC_FE_setWarnPriority
 *
 *  @b Description
 *  @n This function configures the Warning Transfer Priority for the
 *     VBUS transfers for the particular FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI Instance for which Warning Priority is set.
    priority        VBUS priority to apply to the transfers. The allowed range
                    is [0..7]. The value out of the reset is 7.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The Warning Transfer Priority is set.
 *
 *  @b Writes
 *  @n TAC_CFG_FE_WARN_PRIO_PRIORITY
 *
 *  @b Example
 *  @verbatim
    Uint8    prio;
    Uint8    feiInst = 0;

    // Reset the Front End
    CSL_TAC_FE_softwareReset();

    // Check for the reset status
    while(CSL_TAC_FE_getResetStatus(feiInst) == CSL_TAC_FE_NotReset);

    // Read the priority
    prio = CSL_TAC_FE_getWarnPriority(feiInst);
    // prio should be 7

    // Change the priority to 3
    CSL_TAC_FE_setWarnPriority(feiInst, 3);

    // Read the priority again
    prio = CSL_TAC_FE_getWarnPriority(feiInst);
    // prio should be 3
    @endverbatim
 *
 */
void CSL_TAC_FE_setWarnPriority(
    Uint8 feiInst,
    Uint8 priority
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRI (hTacRegs->FE[feiInst].FE_WARN_PRIO,
              TAC_CFG_FE_WARN_PRIO_PRIORITY, (Uint32)priority);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMK(TAC_CFG_FE_WARN_PRIO_PRIORITY, priority);
        addr = (Uint32) &hTacRegs->FE[feiInst].FE_WARN_PRIO;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_FE_getWarnPriority
 *
 *  @b Description
 *  @n This function returns the Warning Transfer Priority for the
 *           VBUS transfers for the specified FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI instance for which priority is requested.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  The Warning Transfer Priority [0..7].
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_FE_WARN_PRIO_PRIORITY
 *
 *  @b Example
 *  @verbatim
    Uint8    prio;
    Uint8    feiInst = 1;


    // Set the priority to 3
    CSL_TAC_FE_setWarnPriority(feiInst, 3);

    // Read the priority
    prio = CSL_TAC_FE_getWarnPriority(feiInst);
    // prio should be 3
    @endverbatim
 *
 */
Uint8 CSL_TAC_FE_getWarnPriority(
    Uint8 feiInst
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->FE[feiInst].FE_WARN_PRIO;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->FE[feiInst].FE_WARN_PRIO;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint8)(CSL_FEXT (word, TAC_CFG_FE_WARN_PRIO_PRIORITY));
}

/**
 *  @n@b CSL_TAC_FE_setCPMPriority
 *
 *  @b Description
 *  @n This function configures the CPM Transfer Priority for the
 *     VBUS transfers for the specified FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI Instance for which CPM Priority is set.
    priority        VBUS priority to apply to the transfers. The allowed range
                    is [0..7]. The value out of the reset is 7.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The CPM Transfer Priority is set.
 *
 *  @b Writes
 *  @n TAC_CFG_FE_CPM_PRIO_PRIORITY
 *
 *  @b Example
 *  @verbatim
    Uint8    prio;
    Uint8    feiInst = 0;

    // Reset the Front End
    CSL_TAC_FE_softwareReset();

    // Check for the reset status
    while(CSL_TAC_FE_getResetStatus(feiInst) == CSL_TAC_FE_NotReset);

    // Read the priority
    prio = CSL_TAC_FE_getCPMPriority(feiInst);
    // prio should be 7

    // Change the priority to 3
    CSL_TAC_FE_setCPMPriority(feiInst, 3);

    // Read the priority again
    prio = CSL_TAC_FE_getCPMPriority(feiInst);
    // prio should be 3
    @endverbatim
 *
 */
void CSL_TAC_FE_setCPMPriority(
    Uint8 feiInst,
    Uint8 priority
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRI (hTacRegs->FE[feiInst].FE_CPM_PRIO,
              TAC_CFG_FE_CPM_PRIO_PRIORITY, (Uint32)priority);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMK(TAC_CFG_FE_CPM_PRIO_PRIORITY, priority);
        addr = (Uint32) &hTacRegs->FE[feiInst].FE_CPM_PRIO;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_FE_getCPMPriority
 *
 *  @b Description
 *  @n This function returns the CPM Transfer Priority for the
 *     VBUS transfers for the specified FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI instance for which priority is requested.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n The CPM Transfer Priority [0..7].
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_FE_CPM_PRIO_PRIORITY
 *
 *  @b Example
 *  @verbatim
    Uint8    prio;
    Uint8    feiInst = 1;

    // Set the priority to 3
    CSL_TAC_FE_setCPMPriority(feiInst, 3);

    // Read the priority
    prio = CSL_TAC_FE_getCPMPriority(feiInst);
    // prio should be 3
    @endverbatim
 *
 */
Uint8 CSL_TAC_FE_getCPMPriority(
    Uint8 feiInst
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->FE[feiInst].FE_CPM_PRIO;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->FE[feiInst].FE_CPM_PRIO;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint8)(CSL_FEXT (word, TAC_CFG_FE_CPM_PRIO_PRIORITY));
}

/**
 *  @n@b CSL_TAC_FE_setWatchDog
 *
 *  @b Description
 *  @n This function configures the watch dog in the specified FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI instance for which to set watch dog.
    wdStatus        Structure with watch dog parameters.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @b None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The Front-End watch-dog is configured.
 *
 *  @b Writes
 *  @n TAC_CFG_FE_TRANS_CFG_ENABLE_FLAG, TAC_CFG_FE_TRANS_CFG_INIT_VALUE
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_FE_wdStatus  wdStatus;
    Uint8   feiInst;

    ...
    feiInst             = 1;
    wdStatus.enableFlag = CSL_TAC_FE_wdInterrupt_Enable;
    wdStatus.initCount  = 1023;

    // Enable the FE Watchdog and set the count to 1023
    CSL_TAC_FE_setWatchDog(feiInst, &wdStatus);

    ...
    // Disable the FE Watchdog. The count is not important so any value
    // can be used.
    wdStatus.enableFlag = CSL_TAC_FE_wdInterrupt_Disable;

    CSL_TAC_FE_setWatchDog(feiInst, &wdStatus);
    @endverbatim
 *
 */
void CSL_TAC_FE_setWatchDog(
    Uint8                 feiInst,
    const CSL_TAC_FE_wdStatus * wdStatus
)
{
#ifndef USE_TAC_MODEL
    hTacRegs->FE[feiInst].FE_TRANS_CFG =
    CSL_FMK (TAC_CFG_FE_TRANS_CFG_ENABLE_FLAG, wdStatus->enableFlag) |
    CSL_FMK (TAC_CFG_FE_TRANS_CFG_INIT_VALUE, (Uint32)wdStatus->initCount);
#else
    {
        Uint32 addr;
        Uint32 word;

        word =
        CSL_FMK (TAC_CFG_FE_TRANS_CFG_ENABLE_FLAG, wdStatus->enableFlag) |
        CSL_FMK (TAC_CFG_FE_TRANS_CFG_INIT_VALUE, wdStatus->initCount);
        addr = (Uint32) &hTacRegs->FE[feiInst].FE_TRANS_CFG;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_FE_getWatchDogStatus
 *
 *  @b Description
 *  @n This function returns the FE watch dog configuration for the specified
 *     FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI instance for which to watch dog parameters are sought.
    wdStatus        Structure with Watchdog parameters.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @b None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_FE_TRANS_CFG_ENABLE_FLAG, TAC_CFG_FE_TRANS_CFG_INIT_VALUE
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_FE_wdStatus  wdStatus;
    CSL_TAC_FE_wdStatus  rdWdStatus;
    Uint8                feiInst;

    feiInst             = 1;
    wdStatus.enableFlag = CSL_TAC_FE_wdInterrupt_Enable;
    wdStatus.initCount  = 1023;

    // Enable the FE Watchdog and set the count to 1023
    CSL_TAC_FE_setWatchDog(feiInst, &wdStatus);

    // Read the FE Watchdog status
    CSL_TAC_FE_getWatchDogStatus(feiInst, &rdWdStatus);

    if (rdWdStatus.enableFlag != wdStatus.enableFlag)
    {
        // The watchdog should have been enabled
        ...
    }
    else if (rdWdStatus.initCount != wdStatus.initCount)
    {
        // The watchdog count should be the same
        ...
    }

    // Disable the FE Watchdog. The count is not important so any value
    // can be used.
    wdStatus.enableFlag = CSL_TAC_FE_wdInterrupt_Disable;

    CSL_TAC_FE_setWatchDog(feiInst, &wdStatus);

    // Read the FE Watchdog status
    CSL_TAC_FE_getWatchDogStatus(feiInst, &rdWdStatus);

    if (rdWdStatus.enableFlag != wdStatus.enableFlag)
    {
        // The watchdog should have been disabled
        // ...
    }
    @endverbatim
 *
 */
void CSL_TAC_FE_getWatchDogStatus(
    Uint8                 feiInst,
    CSL_TAC_FE_wdStatus * wdStatus
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->FE[feiInst].FE_TRANS_CFG;
#else
    Uint32 addr;
    UINT32 tmp;

    addr = (Uint32) &hTacRegs->FE[feiInst].FE_TRANS_CFG;
    tacPointer->cfgWordRead(addr, tmp);
    word = (Uint32)tmp;

#endif

    wdStatus->enableFlag = (CSL_TAC_FE_wdEnableFlag)
        CSL_FEXT (word, TAC_CFG_FE_TRANS_CFG_ENABLE_FLAG);

    wdStatus->initCount =
        CSL_FEXT (word, TAC_CFG_FE_TRANS_CFG_INIT_VALUE);

    return;
}

/**
 *  @n@b CSL_TAC_FE_getTransErrorIntStatus
 *
 *  @b Description
 *  @n This function returns the Front-End Transaction Error
 *     Interrupt Status for the specified FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst             FEI instance for which status should be obtained.
    transErrIntStatus   Structure with the Transaction Error Interrupt Status.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_FE_TRANS_INT_MASTER_ID, TAC_CFG_FE_TRANS_INT_TRANS_ID,
 *     TAC_CFG_FE_TRANS_INT_ERROR_FLAG
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_FE_transErrorInterruptStatus  status;
    Uint8  feiInst;

    ...
    feiInst = 1;
    CSL_TAC_FE_getTransErrorIntStatus(feiInst, &status);
    @endverbatim
 *
 */
void CSL_TAC_FE_getTransErrorIntStatus(
    Uint8                                  feiInst,
    CSL_TAC_FE_transErrorInterruptStatus * transErrIntStatus
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->FE[feiInst].FE_TRANS_INT;
#else
    Uint32 addr;
    UINT32 tmp;

    addr = (Uint32) &hTacRegs->FE[feiInst].FE_TRANS_INT;
    tacPointer->cfgWordRead(addr, tmp);
    word = (Uint32)tmp;

#endif

    transErrIntStatus->masterId =
        CSL_FEXT (word, TAC_CFG_FE_TRANS_INT_MASTER_ID);

    transErrIntStatus->transId =
        CSL_FEXT (word, TAC_CFG_FE_TRANS_INT_TRANS_ID);

    transErrIntStatus->errorFlag =
        CSL_FEXT (word, TAC_CFG_FE_TRANS_INT_ERROR_FLAG);

    return;
}

/**
 *  @n@b CSL_TAC_FE_clearTransErrorIntStatus
 *
 *  @b Description
 *  @n This function clears the error flag set in the
 *     Front-End Transaction Error Interrupt Status register.
 *
 *  @b Arguments
 *  @verbatim
    feiInst             FEI instance for which error flags will be
                        cleared.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The FE transaction error interrupt status is cleared.
 *
 *  @b Writes
 *  @n TAC_CFG_FE_TRANS_INT_ERROR_FLAG=1
 *
 *  @b Example
 *  @verbatim
    Uint8 feiInst = 1;

    CSL_TAC_FE_clearTransErrorIntStatus(feiInst);
    @endverbatim
 *
 */
void CSL_TAC_FE_clearTransErrorIntStatus(
    Uint8 feiInst
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hTacRegs->FE[feiInst].FE_TRANS_INT,
               TAC_CFG_FE_TRANS_INT_ERROR_FLAG, ERROR);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT (TAC_CFG_FE_TRANS_INT_ERROR_FLAG, ERROR);
        addr = (Uint32) &hTacRegs->FE[feiInst].FE_TRANS_INT;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/* =============================================================================
 * Functions linked to VBUS Stats registers
 * =============================================================================
 */

/**
 *  @n@b CSL_TAC_Stats_getCfgReadAccess
 *
 *  @b Description
 *  @n This function reads the content of the statistics register for
 *     the total number of read data phases used by the Configuration
 *     interface.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  The count of the total number of read accesses.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_CFG_READ_RD_ACC_NB
 *
 *  @b Example
 *  @verbatim
    Uint16  accessCnt;

    accessCnt = CSL_TAC_Stats_getCfgReadAccess();
    @endverbatim
 *
 */
Uint16 CSL_TAC_Stats_getCfgReadAccess(void)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->CFG_READ;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->CFG_READ;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint16)(CSL_FEXT(word, TAC_CFG_CFG_READ_RD_ACC_NB));
}

/**
 *  @n@b CSL_TAC_Stats_getCfgWriteAccess
 *
 *  @b Description
 *  @n This function reads the content of the statistics register for
 *     the total number of write data phases used by the Configuration
 *     interface.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  The count of the total number of write accesses.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_CFG_WRIT_WR_ACC_NB
 *
 *  @b Example
 *  @verbatim
    Uint16  accessCnt;

    accessCnt = CSL_TAC_Stats_getCfgWriteAccess();
    @endverbatim
 *
 */
Uint16 CSL_TAC_Stats_getCfgWriteAccess(void)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->CFG_WRIT;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->CFG_WRIT;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint16)(CSL_FEXT (word, TAC_CFG_CFG_WRIT_WR_ACC_NB));
}

/**
 *  @n@b CSL_TAC_Stats_getCfgTotalAccess
 *
 *  @b Description
 *  @n This function reads the content of the statistics register for
 *     the total number of data phases used by the Configuration
 *     interface.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  The count of the total number of accesses.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_CFG_TOT_TOT_ACC_NB
 *
 *  @b Example
 *  @verbatim
    Uint16  accessCnt;

    accessCnt = CSL_TAC_Stats_getCfgTotalAccess();
    @endverbatim
 *
 */
Uint16 CSL_TAC_Stats_getCfgTotalAccess(void)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->CFG_TOT;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->CFG_TOT;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint16)(CSL_FEXT (word, TAC_CFG_CFG_TOT_TOT_ACC_NB));
}

/**
 *  @n@b CSL_TAC_Stats_getSlaveReadAccess
 *
 *  @b Description
 *  @n This function reads the content of the statistics register for
 *     the total number of read data phases used by the DMA Slave
 *     interface.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  The count of the total number of read accesses.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_SLV_READ_RD_ACC_NB
 *
 *  @b Example
 *  @verbatim
    Uint16  accessCnt;

    accessCnt = CSL_TAC_Stats_getSlaveReadAccess();
    @endverbatim
 *
 */
Uint16 CSL_TAC_Stats_getSlaveReadAccess(void)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->SLV_READ;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->SLV_READ;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint16)(CSL_FEXT (word, TAC_CFG_SLV_READ_RD_ACC_NB));
}

/**
 *  @n@b CSL_TAC_Stats_getSlaveWriteAccess
 *
 *  @b Description
 *  @n This function reads the content of the statistics register for
 *     the total number of write data phases used by the DMA Slave
 *     interface.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  The count of the total number of write accesses.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_SLV_WRIT_WR_ACC_NB
 *
 *  @b Example
 *  @verbatim
    Uint16  accessCnt;

    accessCnt = CSL_TAC_Stats_getSlaveWriteAccess();
    @endverbatim
 *
 */
Uint16 CSL_TAC_Stats_getSlaveWriteAccess(void)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->SLV_WRIT;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->SLV_WRIT;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint16)(CSL_FEXT (word, TAC_CFG_SLV_WRIT_WR_ACC_NB));
}

/**
 *  @n@b CSL_TAC_Stats_getSlaveTotalAccess
 *
 *  @b Description
 *  @n This function reads the content of the statistics register for
 *      the total number of data phases used by the DMA slave interface.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  The count of the total number of accesses.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_SLV_TOT_TOT_ACC_NB
 *
 *  @b Example
 *  @verbatim
    Uint16  accessCnt;

    accessCnt = CSL_TAC_Stats_getSlaveTotalAccess();
    @endverbatim
 *
 */
Uint16 CSL_TAC_Stats_getSlaveTotalAccess(void)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->SLV_TOT;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->SLV_TOT;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint16)(CSL_FEXT (word, TAC_CFG_SLV_TOT_TOT_ACC_NB));
}

/**
 *  @n@b CSL_TAC_Stats_getMasterReadAccess
 *
 *  @b Description
 *  @n This function reads the content of the statistics register for
 *     the total number of read data phases used by the DMA Master
 *     interface of the FEI instance specified.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI instance for which the statistic will be obtained.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  The count of the total number of read accesses.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_MST2_READ_ACC_NB
 *
 *  @b Example
 *  @verbatim
    Uint16  accessCnt;
    Uint8   feiInst = 1;

    accessCnt = CSL_TAC_Stats_getMasterReadAccess(feiInst);
    @endverbatim
 *
 */
Uint16 CSL_TAC_Stats_getMasterReadAccess(
    Uint8 feiInst
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->MST_STATS[feiInst].MST2;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->MST_STATS[feiInst].MST2;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;

        return CSL_FEXT (word, TAC_CFG_MST2_READ_ACC_NB);
    }
#endif

    return (Uint16)(CSL_FEXT (word, TAC_CFG_MST2_READ_ACC_NB));
}

/**
 *  @n@b CSL_TAC_Stats_getMasterWriteAccess
 *
 *  @b Description
 *  @n This function reads the content of the statistics register for
 *     the total number of write data phases used by the DMA Master
 *     interface for the specified FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI instance for which the statistic will be obtained.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  The count of the total number of write accesses.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_MST1_WRITE_ACC_NB
 *
 *  @b Example
 *  @verbatim
    Uint16  accessCnt;
    Uint8   feiInst = 1;

    accessCnt = CSL_TAC_Stats_getMasterWriteAccess(feiInst);
    @endverbatim
 *
 */
Uint16 CSL_TAC_Stats_getMasterWriteAccess(
    Uint8   feiInst
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->MST_STATS[feiInst].MST1;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->MST_STATS[feiInst].MST1;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint16)(CSL_FEXT (word, TAC_CFG_MST1_WRITE_ACC_NB));
}

/**
 *  @n@b CSL_TAC_Stats_getMasterTotalAccess
 *
 *  @b Description
 *  @n This function reads the content of the statistics register for
 *     the total number of data phases used by the DMA Master interface
 *     for the specified FEI instance.
 *
 *  @b Arguments
 *  @verbatim
    feiInst         FEI instance for which the statistic will be obtained.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  The count of the total number of accesses.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_MST0_TOTAL_ACC_NB
 *
 *  @b Example
 *  @verbatim
    Uint16  accessCnt;
    Uint8   feiInst;

    accessCnt = CSL_TAC_Stats_getMasterTotalAccess(feiInst);
    @endverbatim
 *
 */
Uint16 CSL_TAC_Stats_getMasterTotalAccess(
    Uint8 feiInst
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->MST_STATS[feiInst].MST0;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->MST_STATS[feiInst].MST0;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint16)(CSL_FEXT(word, TAC_CFG_MST0_TOTAL_ACC_NB));
}

/**
@}
*/

/* end of csl_tac2_regsFEAux.c */


