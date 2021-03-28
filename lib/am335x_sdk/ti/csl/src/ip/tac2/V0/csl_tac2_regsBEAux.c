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
 *  @file  csl_tac2_regsBEAux.c
 *
 *  @brief This file contains API implementation for the CSL for the TAC2
 *         Back-End interface.
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

#include <ti/csl/src/ip/tac2/V0/csl_tac2_regsBEAux.h>

/** @addtogroup CSL_TAC_BE_FUNCTION
@{
*/

/* =============================================================================
 * Functions linked to BETI management
 * =============================================================================
 */

/**
 *  @n@b CSL_TAC_BETI_enable
 *
 *  @b Description
 *  @n This function enables the TAC2 Back End Transfer Interface (BETI).
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
 *  @n The Back End Transfer Interface is enabled.
 *
 *  @b Writes
 *  @n TAC_CFG_BETI_CTRL_ENABLE=1
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BETI_enable();
    @endverbatim
 *
 */
void CSL_TAC_BETI_enable(void)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hTacRegs->BETI_CTRL, TAC_CFG_BETI_CTRL_ENABLE, ENABLE);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(TAC_CFG_BETI_CTRL_ENABLE, ENABLE);
        addr = (Uint32) &hTacRegs->BETI_CTRL;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_BETI_disable
 *
 *  @b Description
 *  @n This function disables the TAC2 Back End Transfer Interface (BETI).
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
 *  @n The Back End Transfer Interface is disabled.
 *
 *  @b Writes
 *  @n TAC_CFG_BETI_CTRL_ENABLE=0
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BETI_disable();
    @endverbatim
 *
 */
void CSL_TAC_BETI_disable(void)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hTacRegs->BETI_CTRL, TAC_CFG_BETI_CTRL_ENABLE, DISABLE);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(TAC_CFG_BETI_CTRL_ENABLE, DISABLE);
        addr = (Uint32) &hTacRegs->BETI_CTRL;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_BETI_getEnableStatus
 *
 *  @b Description
 *  @n This function returns the enable status of the BETI.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n CSL_TAC_BETI_Disabled
 *      The BETI is disabled.
 *  @n CSL_TAC_BETI_Enabled
 *      The BETI is enabled.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_BETI_CTRL_ENABLE
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BETI_enable();

    if (CSL_TAC_BETI_getEnableStatus() != CSL_TAC_BETI_Enabled)
    {
        // The BETI should have been enabled.
        ...
    }

    ...
    CSL_TAC_BETI_disable();

    if (CSL_TAC_BETI_getEnableStatus() != CSL_TAC_BETI_Disabled)
    {
        // The BETI should have been disabled.
        ...
    }
    @endverbatim
 *
 */
CSL_TAC_BETI_enableStatus CSL_TAC_BETI_getEnableStatus(void)
{
    Uint32  word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->BETI_CTRL;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->BETI_CTRL;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (CSL_TAC_BETI_enableStatus)
        CSL_FEXT (word, TAC_CFG_BETI_CTRL_ENABLE);
}

/**
 *  @n@b CSL_TAC_BETI_getStatus
 *
 *  @b Description
 *  @n This function returns the BETI status indicating whether the
 *     SGCPs are Busy or Idle.
 *
 *  @b Arguments
 *  @verbatim
    betiStatus     Status of the SGCPs
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
 *  @n TAC_CFG_BETI_STAT_SGCP0_STATUS, TAC_CFG_BETI_STAT_SGCP1_STATUS
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BETI_status  betiStatus;

    CSL_TAC_BETI_getStatus(&betiStatus);

    if (betiStatus.sgcp0Status == CSL_TAC_BETI_statusBit_Idle)
    {
        // SGCP 0 Idle
        ...
    }

    if (betiStatus.sgcp1Status == CSL_TAC_BETI_statusBit_Busy)
    {
        // SGCP 1 Busy
        ...
    }

    if (betiStatus.sgcp2Status == CSL_TAC_BETI_statusBit_Busy)
    {
        // SGCP 2 Busy
        ...
    }

    if (betiStatus.sgcp3Status == CSL_TAC_BETI_statusBit_Idle)
    {
        // SGCP 3 Idle
        ...
    }


    @endverbatim
 *
 */
void CSL_TAC_BETI_getStatus(
    CSL_TAC_BETI_status * betiStatus
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->BETI_STAT;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->BETI_STAT;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }

#endif

    betiStatus->sgcp0Status = (CSL_TAC_BETI_statusBit)
        CSL_FEXT (word, TAC_CFG_BETI_STAT_SGCP0_STATUS);

    betiStatus->sgcp1Status = (CSL_TAC_BETI_statusBit)
        CSL_FEXT (word, TAC_CFG_BETI_STAT_SGCP1_STATUS);

    betiStatus->sgcp2Status = (CSL_TAC_BETI_statusBit)
        CSL_FEXT (word, TAC_CFG_BETI_STAT_SGCP2_STATUS);

    betiStatus->sgcp3Status = (CSL_TAC_BETI_statusBit)
        CSL_FEXT (word, TAC_CFG_BETI_STAT_SGCP3_STATUS);

    betiStatus->sgcp4Status = (CSL_TAC_BETI_statusBit)
        CSL_FEXT (word, TAC_CFG_BETI_STAT_SGCP4_STATUS);

    betiStatus->sgcp5Status = (CSL_TAC_BETI_statusBit)
        CSL_FEXT (word, TAC_CFG_BETI_STAT_SGCP5_STATUS);

    return;
}

/**
 *  @n@b CSL_TAC_BETI_setWatchDog
 *
 *  @b Description
 *  @n This function configures the watch dog in the BETI.
 *
 *  @b Arguments
 *  @verbatim
    reloadCnt       The value indicates the number of elapsed TAC2 clock cycles
                    between DMA write accesses that will trigger a watchdog
                    interrupt.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @b None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The Back-End watch-dog is configured.
 *
 *  @b Writes
 *  @n TAC_CFG_BETI_WCFG_BE_WD_CFG
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BETI_setWatchDog(100);
    @endverbatim
 *
 */
void CSL_TAC_BETI_setWatchDog(
    Uint16 reloadCnt
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRI (hTacRegs->BETI_WCFG, TAC_CFG_BETI_WCFG_BE_WD_CFG, (Uint32)reloadCnt);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMK(TAC_CFG_BETI_WCFG_BE_WD_CFG, reloadCnt);
        addr = (Uint32) &hTacRegs->BETI_WCFG;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_BETI_getWatchDogStatus
 *
 *  @b Description
 *  @n This function reads the content of the BETI watch dog decounter.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n Current value of the decounter.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_BETI_WST_BE_WD_STAT
 *
 *  @b Example
 *  @verbatim
    Uint16  deCnt;

    deCnt = CSL_TAC_BETI_getWatchDogStatus();
    ...
    @endverbatim
 *
 */
Uint16 CSL_TAC_BETI_getWatchDogStatus(void)
{
    Uint32  word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->BETI_WST;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->BETI_WST;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (Uint16)(CSL_FEXT (word, TAC_CFG_BETI_WST_BE_WD_STAT));
}

/**
 *  @n@b CSL_TAC_BETI_getWatchDogInterruptStatus
 *
 *  @b Description
 *  @n This function reads the content of the watch dog
 *     interrupt status register.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  CSL_TAC_BETI_wdInterruptStatus_NoInt
 *          No interrupt has been generated.
 *  @n  CSL_TAC_BETI_wdInterruptStatus_Int
 *          An interrupt has been generated and forwarded to the BEII.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_BETI_WINT_INT_STAT
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BETI_wdInterruptStatus wdIntStatus;

    wdIntStatus = CSL_TAC_BETI_getWatchDogInterruptStatus();

    if (wdIntStatus == CSL_TAC_BETI_wdInterruptStatus_Int)
    {
        // Interrupt generated and forwarded to BEII
        ...
    }
    @endverbatim
 *
 */
CSL_TAC_BETI_wdInterruptStatus CSL_TAC_BETI_getWatchDogInterruptStatus(void)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->BETI_WINT;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->BETI_WINT;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (CSL_TAC_BETI_wdInterruptStatus)
           CSL_FEXT (word, TAC_CFG_BETI_WINT_INT_STAT);
}

/**
 *  @n@b CSL_TAC_BETI_clearWatchDogInterrupt
 *
 *  @b Description
 *  @n This function clears the interrupt registered in the watch dog
 *     interrupt status register.
 *
 *  @b Arguments
 *  @verbatim
    None
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
 *  @b Writes
 *  @n TAC_CFG_BETI_WINT_INT_STAT=0
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BETI_wdInterruptStatus wdIntStatus;

    wdIntStatus = CSL_TAC_BETI_getWatchDogInterruptStatus();

    if (wdIntStatus == CSL_TAC_BETI_wdInterruptStatus_Int)
    {
        // Interrupt generated and forwarded to BEII
        CSL_TAC_BETI_clearWatchDogInterrupt();
    }
    @endverbatim
 *
 */
void CSL_TAC_BETI_clearWatchDogInterrupt(void)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hTacRegs->BETI_WINT, TAC_CFG_BETI_WINT_INT_STAT, INT_GENERATED);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(TAC_CFG_BETI_WINT_INT_STAT, INT_GENERATED);
        addr = (Uint32) &hTacRegs->BETI_WINT;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/* =============================================================================
 * Functions linked to BEII management
 * =============================================================================
 */

/**
 *  @n@b CSL_TAC_BEII_enable
 *
 *  @b Description
 *  @n This function enables the TAC2 Back End Interrupt Interface (BEII).
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
 *  @n The Back End Interrupt Interface is enabled.
 *
 *  @b Writes
 *  @n TAC_CFG_BEII_CTRL_ENABLE=1
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BEII_enable();
    @endverbatim
 *
 */
void CSL_TAC_BEII_enable(void)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hTacRegs->BEII_CTRL, TAC_CFG_BEII_CTRL_ENABLE, ENABLE);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(TAC_CFG_BEII_CTRL_ENABLE, ENABLE);
        addr = (Uint32) &hTacRegs->BEII_CTRL;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_BEII_disable
 *
 *  @b Description
 *  @n This function disables the TAC2 Back End Interrupt Interface (BEII)
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
 *  @n The Back End Interrupt Interface is disabled.
 *
 *  @b Writes
 *  @n TAC_CFG_BEII_CTRL_ENABLE=0
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BEII_disable();
    @endverbatim
 *
 */
void CSL_TAC_BEII_disable(void)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hTacRegs->BEII_CTRL, TAC_CFG_BEII_CTRL_ENABLE, DISABLE);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(TAC_CFG_BEII_CTRL_ENABLE, DISABLE);
        addr = (Uint32) &hTacRegs->BEII_CTRL;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_BEII_getEnableStatus
 *
 *  @b Description
 *  @n This function returns the enable status of the BEII.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n CSL_TAC_BEII_Disabled
 *      The BEII is disabled.
 *  @n CSL_TAC_BEII_Enabled
 *      The BEII is enabled.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_BEII_CTRL_ENABLE
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BEII_enable();

    if (CSL_TAC_BEII_getEnableStatus() != CSL_TAC_BEII_Enabled)
    {
        // The BEII should have been enabled.
        ...
    }

    ...
    CSL_TAC_BEII_disable();

    if (CSL_TAC_BEII_getEnableStatus() != CSL_TAC_BEII_Disabled)
    {
        // The BEII should have been disabled.
        ...
    }
    @endverbatim
 *
 */
CSL_TAC_BEII_enableStatus CSL_TAC_BEII_getEnableStatus(void)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->BEII_CTRL;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->BEII_CTRL;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (CSL_TAC_BEII_enableStatus)
           CSL_FEXT (word, TAC_CFG_BEII_CTRL_ENABLE);
}

/**
 *  @n@b CSL_TAC_BEII_getInterruptStatus
 *
 *  @b Description
 *  @n This function reads the BEII Interrupt Status
 *
 *  @b Arguments
 *  @verbatim
    interruptStatus Structure with the active BETI interrupt status.
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
 *  @n TAC_CFG_BEII_IRS0_SGCP0_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP0_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP0_SEQ_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP0_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP1_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP1_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP1_SEQ_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP1_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP2_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP2_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP2_SEQ_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP2_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP3_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP3_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP3_SEQ_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP3_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP4_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP4_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP4_SEQ_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP4_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP5_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP5_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP5_SEQ_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP5_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IRS1_FE0_TRANS_STAT,
 *     TAC_CFG_BEII_IRS1_FE1_TRANS_STAT,
 *     TAC_CFG_BEII_IRS1_FE2_TRANS_STAT,
 *     TAC_CFG_BEII_IRS1_BE_WD_STAT
 *
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BEII_interruptStatus  interruptStatus;

    CSL_TAC_BEII_getInterruptStatus(&interruptStatus);

    if (interruptStatus.sgcp0CycOverStat)
    {
        // SGCP 0 Cycle Overflow Interrupt occured
        ...
    }

    if (interruptStatus.sgcp0FifoOverStat)
    {
        // SGCP 0 FIFO Overflow Interrupt occured
        ...
    }

    if (interruptStatus.sgcp0SeqStat)
    {
        // SGCP 0 Cycle Sequencer Idle Interrupt occured
        ...
    }

    if (interruptStatus.sgcp0BuffMissStat)
    {
        // SGCP 0 Input Buffer Miss Interrupt occured
        ...
    }

    if (interruptStatus.sgcp1CycOverStat)
    {
        // SGCP 1 Cycle Overflow Interrupt occured
        ...
    }

    if (interruptStatus.sgcp1FifoOverStat)
    {
        // SGCP 1 FIFO Overflow Interrupt occured
        ...
    }

    if (interruptStatus.sgcp1SeqStat)
    {
        // SGCP 1 Cycle Sequencer Idle Interrupt occured
        ...
    }

    if (interruptStatus.sgcp1BuffMissStat)
    {
        // SGCP 1 Input Buffer Miss Interrupt occured
        ...
    }

    ...
    // Checks for SGCP 2,3,4,5, if necesssary
    ...

    if (interruptStatus.fe0TransErrStat)
    {
        // Front-End # 0 Transaction ID unavailable
        ...
    }

    if (interruptStatus.fe1TransErrStat)
    {
        // Front-End #1 Transaction ID unavailable
        ...
    }

    if (interruptStatus.fe2TransErrStat)
    {
        // Front-End #2 Transaction ID unavailable
        ...
    }

    if (interruptStatus.betiWdStat)
    {
        // The Back-End Watch Dog Timer counter reached 0
        ...
    }

    @endverbatim
 *
 */
void CSL_TAC_BEII_getInterruptStatus(
    CSL_TAC_BEII_interruptStatus * interruptStatus
)
{
    Uint32 word0;
    Uint32 word1;

#ifndef USE_TAC_MODEL
    word0 = hTacRegs->BEII_IRS0;
    word1 = hTacRegs->BEII_IRS1;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->BEII_IRS0;
        tacPointer->cfgWordRead(addr, tmp);
        word0 = (Uint32)tmp;

        addr = (Uint32) &hTacRegs->BEII_IRS1;
        tacPointer->cfgWordRead(addr, tmp);
        word1 = (Uint32)tmp;
    }
#endif

    interruptStatus->sgcp0CycOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP0_CYC_OVER_STAT);

    interruptStatus->sgcp0FifoOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP0_FIFO_OVER_STAT);

    interruptStatus->sgcp0SeqStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP0_SEQ_STAT);

    interruptStatus->sgcp0BuffMissStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP0_IB_WR_MISS_STAT);

    interruptStatus->sgcp1CycOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP1_CYC_OVER_STAT);

    interruptStatus->sgcp1FifoOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP1_FIFO_OVER_STAT);

    interruptStatus->sgcp1SeqStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP1_SEQ_STAT);

    interruptStatus->sgcp1BuffMissStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP1_IB_WR_MISS_STAT);

    interruptStatus->sgcp2CycOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP2_CYC_OVER_STAT);

    interruptStatus->sgcp2FifoOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP2_FIFO_OVER_STAT);

    interruptStatus->sgcp2SeqStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP2_SEQ_STAT);

    interruptStatus->sgcp2BuffMissStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP2_IB_WR_MISS_STAT);

    interruptStatus->sgcp3CycOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP3_CYC_OVER_STAT);

    interruptStatus->sgcp3FifoOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP3_FIFO_OVER_STAT);

    interruptStatus->sgcp3SeqStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP3_SEQ_STAT);

    interruptStatus->sgcp3BuffMissStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP3_IB_WR_MISS_STAT);

    interruptStatus->sgcp4CycOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP4_CYC_OVER_STAT);

    interruptStatus->sgcp4FifoOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP4_FIFO_OVER_STAT);

    interruptStatus->sgcp4SeqStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP4_SEQ_STAT);

    interruptStatus->sgcp4BuffMissStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP4_IB_WR_MISS_STAT);

    interruptStatus->sgcp5CycOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP5_CYC_OVER_STAT);

    interruptStatus->sgcp5FifoOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP5_FIFO_OVER_STAT);

    interruptStatus->sgcp5SeqStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP5_SEQ_STAT);

    interruptStatus->sgcp5BuffMissStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IRS0_SGCP5_IB_WR_MISS_STAT);

    interruptStatus->fe0TransErrStat =
        CSL_FEXT (word1, TAC_CFG_BEII_IRS1_FE0_TRANS_STAT);

    interruptStatus->fe1TransErrStat =
        CSL_FEXT (word1, TAC_CFG_BEII_IRS1_FE1_TRANS_STAT);

    interruptStatus->fe2TransErrStat =
        CSL_FEXT (word1, TAC_CFG_BEII_IRS1_FE2_TRANS_STAT);

    interruptStatus->betiWdStat =
        CSL_FEXT (word1, TAC_CFG_BEII_IRS1_BE_WD_STAT);

    return;
}

/**
 *  @n@b CSL_TAC_BEII_getEnabledInterruptStatus
 *
 *  @b Description
 *  @n This function reads the BEII Interrupt Enable Status
 *
 *  @b Arguments
 *  @verbatim
    interruptEnStatus Structure with the BETI interrupt Enable status.
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
 *  @n TAC_CFG_BEII_IES0_SGCP0_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IES0_SGCP0_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IES0_SGCP0_SEQ_STAT,
 *     TAC_CFG_BEII_IES0_SGCP0_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IES0_SGCP1_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IES0_SGCP1_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IES0_SGCP1_SEQ_STAT,
 *     TAC_CFG_BEII_IES0_SGCP1_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IES0_SGCP2_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IES0_SGCP2_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IES0_SGCP2_SEQ_STAT,
 *     TAC_CFG_BEII_IES0_SGCP2_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IES0_SGCP3_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IES0_SGCP3_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IES0_SGCP3_SEQ_STAT,
 *     TAC_CFG_BEII_IES0_SGCP3_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IES0_SGCP4_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IES0_SGCP4_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IES0_SGCP4_SEQ_STAT,
 *     TAC_CFG_BEII_IES0_SGCP4_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IES0_SGCP5_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IES0_SGCP5_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IES0_SGCP5_SEQ_STAT,
 *     TAC_CFG_BEII_IES0_SGCP5_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IES1_FE0_TRANS_STAT,
 *     TAC_CFG_BEII_IES1_FE1_TRANS_STAT,
 *     TAC_CFG_BEII_IES1_FE2_TRANS_STAT,
 *     TAC_CFG_BEII_IES1_BE_WD_STAT
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BEII_interruptStatus  interruptEnStatus;

    CSL_TAC_BEII_getEnabledInterruptStatus(&interruptEnStatus);

    if (interruptEnStatus.sgcp0CycOverStat)
    {
        // SGCP 0 Cycle Overflow Interrupt is enabled
        ...
    }

    @endverbatim
 *
 */
void CSL_TAC_BEII_getEnabledInterruptStatus(
    CSL_TAC_BEII_interruptStatus * interruptEnStatus
)
{
    Uint32 word0;
    Uint32 word1;

#ifndef USE_TAC_MODEL
    word0 = hTacRegs->BEII_IES0;
    word1 = hTacRegs->BEII_IES1;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->BEII_IES0;
        tacPointer->cfgWordRead(addr, tmp);
        word0 = (Uint32)tmp;

        addr = (Uint32) &hTacRegs->BEII_IES1;
        tacPointer->cfgWordRead(addr, tmp);
        word1 = (Uint32)tmp;
    }
#endif

    interruptEnStatus->sgcp0CycOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP0_CYC_OVER_STAT);

    interruptEnStatus->sgcp0FifoOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP0_FIFO_OVER_STAT);

    interruptEnStatus->sgcp0SeqStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP0_SEQ_STAT);

    interruptEnStatus->sgcp0BuffMissStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP0_IB_WR_MISS_STAT);

    interruptEnStatus->sgcp1CycOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP1_CYC_OVER_STAT);

    interruptEnStatus->sgcp1FifoOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP1_FIFO_OVER_STAT);

    interruptEnStatus->sgcp1SeqStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP1_SEQ_STAT);

    interruptEnStatus->sgcp1BuffMissStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP1_IB_WR_MISS_STAT);

    interruptEnStatus->sgcp2CycOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP2_CYC_OVER_STAT);

    interruptEnStatus->sgcp2FifoOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP2_FIFO_OVER_STAT);

    interruptEnStatus->sgcp2SeqStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP2_SEQ_STAT);

    interruptEnStatus->sgcp2BuffMissStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP2_IB_WR_MISS_STAT);

    interruptEnStatus->sgcp3CycOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP3_CYC_OVER_STAT);

    interruptEnStatus->sgcp3FifoOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP3_FIFO_OVER_STAT);

    interruptEnStatus->sgcp3SeqStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP3_SEQ_STAT);

    interruptEnStatus->sgcp3BuffMissStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP3_IB_WR_MISS_STAT);

    interruptEnStatus->sgcp4CycOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP4_CYC_OVER_STAT);

    interruptEnStatus->sgcp4FifoOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP4_FIFO_OVER_STAT);

    interruptEnStatus->sgcp4SeqStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP4_SEQ_STAT);

    interruptEnStatus->sgcp4BuffMissStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP4_IB_WR_MISS_STAT);

    interruptEnStatus->sgcp5CycOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP5_CYC_OVER_STAT);

    interruptEnStatus->sgcp5FifoOverStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP5_FIFO_OVER_STAT);

    interruptEnStatus->sgcp5SeqStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP5_SEQ_STAT);

    interruptEnStatus->sgcp5BuffMissStat =
        CSL_FEXT (word0, TAC_CFG_BEII_IES0_SGCP5_IB_WR_MISS_STAT);

    interruptEnStatus->fe0TransErrStat =
        CSL_FEXT (word1, TAC_CFG_BEII_IES1_FE0_TRANS_STAT);

    interruptEnStatus->fe1TransErrStat =
        CSL_FEXT (word1, TAC_CFG_BEII_IES1_FE1_TRANS_STAT);

    interruptEnStatus->fe2TransErrStat =
        CSL_FEXT (word1, TAC_CFG_BEII_IES1_FE2_TRANS_STAT);

    interruptEnStatus->betiWdStat =
        CSL_FEXT (word1, TAC_CFG_BEII_IES1_BE_WD_STAT);


    return;
}

/**
 *  @n@b CSL_TAC_BEII_forceInterrupts
 *
 *  @b Description
 *  @n This function sets the BEII Interrupts
 *
 *  @b Arguments
 *  @verbatim
    interruptsToForce Structure with the BETI interrupts to set. A given
                      interrupt will be set if the corresponding flag is
                      set to 1.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The interrupts specified in the interruptsToForce structure are set.
 *
 *  @b Writes
 *  @n TAC_CFG_BEII_IRS0_SGCP0_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP0_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP0_SEQ_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP0_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP1_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP1_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP1_SEQ_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP1_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP2_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP2_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP2_SEQ_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP2_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP3_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP3_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP3_SEQ_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP3_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP4_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP4_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP4_SEQ_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP4_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP5_CYC_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP5_FIFO_OVER_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP5_SEQ_STAT,
 *     TAC_CFG_BEII_IRS0_SGCP5_IB_WR_MISS_STAT,
 *     TAC_CFG_BEII_IRS1_FE0_TRANS_STAT,
 *     TAC_CFG_BEII_IRS1_FE1_TRANS_STAT,
 *     TAC_CFG_BEII_IRS1_FE2_TRANS_STAT,
 *     TAC_CFG_BEII_IRS1_BE_WD_STAT
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BEII_interruptStatus  interruptsToForce;

    // Force the SGCP 0 Cycle Overflow interrupt
    interruptsToForce.sgcp0CycOverStat = 1;

    // Force the SGCP 1 Input Buffer Miss Interrupt
    interruptsToForce.sgcp1BuffMissStat = 1;

    // Don't force the rest of the interrupts
    interruptsToForce.sgcp0FifoOverStat = 0;
    interruptsToForce.sgcp0SeqStat      = 0;
    interruptsToForce.sgcp0BuffMissStat = 0;
    interruptsToForce.sgcp1CycOverStat  = 0;
    interruptsToForce.sgcp1FifoOverStat = 0;
    interruptsToForce.sgcp1SeqStat      = 0;
    interruptsToForce.sgcp2CycOverStat  = 0;
    interruptsToForce.sgcp2FifoOverStat = 0;
    interruptsToForce.sgcp2SeqStat      = 0;
    interruptsToForce.sgcp2BuffMissStat = 0;
    interruptsToForce.sgcp3CycOverStat  = 0;
    interruptsToForce.sgcp3FifoOverStat = 0;
    interruptsToForce.sgcp3SeqStat      = 0;
    interruptsToForce.sgcp3BuffMissStat = 0;
    interruptsToForce.fe1TransErrStat   = 0;
    interruptsToForce.fe1TransErrStat   = 0;
    interruptsToForce.betiWdStat        = 0;

    CSL_TAC_BEII_forceInterrupts(&interruptsToForce);
    @endverbatim
 *
 */
void CSL_TAC_BEII_forceInterrupts(
    const CSL_TAC_BEII_interruptStatus * interruptsToForce
)
{
    Uint32 word0;
    Uint32 word1;

    word0 =
        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP0_CYC_OVER_STAT,
                 (Uint32)interruptsToForce->sgcp0CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP0_FIFO_OVER_STAT,
                 (Uint32)interruptsToForce->sgcp0FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP0_SEQ_STAT,
                 (Uint32)interruptsToForce->sgcp0SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP0_IB_WR_MISS_STAT,
                 (Uint32)interruptsToForce->sgcp0BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP1_CYC_OVER_STAT,
                 (Uint32)interruptsToForce->sgcp1CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP1_FIFO_OVER_STAT,
                 (Uint32)interruptsToForce->sgcp1FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP1_SEQ_STAT,
                 (Uint32)interruptsToForce->sgcp1SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP1_IB_WR_MISS_STAT,
                 (Uint32)interruptsToForce->sgcp1BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP2_CYC_OVER_STAT,
                 (Uint32)interruptsToForce->sgcp2CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP2_FIFO_OVER_STAT,
                 (Uint32)interruptsToForce->sgcp2FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP2_SEQ_STAT,
                 (Uint32)interruptsToForce->sgcp2SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP2_IB_WR_MISS_STAT,
                 (Uint32)interruptsToForce->sgcp2BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP3_CYC_OVER_STAT,
                 (Uint32)interruptsToForce->sgcp3CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP3_FIFO_OVER_STAT,
                 (Uint32)interruptsToForce->sgcp3FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP3_SEQ_STAT,
                 (Uint32)interruptsToForce->sgcp3SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP3_IB_WR_MISS_STAT,
                 (Uint32)interruptsToForce->sgcp3BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP4_CYC_OVER_STAT,
                 (Uint32)interruptsToForce->sgcp4CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP4_FIFO_OVER_STAT,
                 (Uint32)interruptsToForce->sgcp4FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP4_SEQ_STAT,
                 (Uint32)interruptsToForce->sgcp4SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP4_IB_WR_MISS_STAT,
                 (Uint32)interruptsToForce->sgcp4BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP5_CYC_OVER_STAT,
                 (Uint32)interruptsToForce->sgcp5CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP5_FIFO_OVER_STAT,
                 (Uint32)interruptsToForce->sgcp5FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP5_SEQ_STAT,
                 (Uint32)interruptsToForce->sgcp5SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IRS0_SGCP5_IB_WR_MISS_STAT,
                 (Uint32)interruptsToForce->sgcp5BuffMissStat);

    word1 =
        CSL_FMK(TAC_CFG_BEII_IRS1_FE0_TRANS_STAT,
                 (Uint32)interruptsToForce->fe0TransErrStat)    |

        CSL_FMK(TAC_CFG_BEII_IRS1_FE1_TRANS_STAT,
                 (Uint32)interruptsToForce->fe1TransErrStat)    |

        CSL_FMK(TAC_CFG_BEII_IRS1_FE2_TRANS_STAT,
                 (Uint32)interruptsToForce->fe2TransErrStat)    |

        CSL_FMK(TAC_CFG_BEII_IRS1_BE_WD_STAT,
                 (Uint32)interruptsToForce->betiWdStat);


#ifndef USE_TAC_MODEL
    hTacRegs->BEII_IRS0 = word0;
    hTacRegs->BEII_IRS1 = word1;
#else
    {
        Uint32 addr;

        addr = (Uint32) &hTacRegs->BEII_IRS0;
        tacPointer->cfgWordWrite(addr, word0);

        addr = (Uint32) &hTacRegs->BEII_IRS1;
        tacPointer->cfgWordWrite(addr, word1);

    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_BEII_clearInterrupts
 *
 *  @b Description
 *  @n This function clears the BEII Interrupts
 *
 *  @b Arguments
 *  @verbatim
    interruptsToClear Structure with the BETI interrupts to clear. A given
                      interrupt will be cleared if the corresponding flag
                      is set to 1.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The interrupts specified in the interruptsToClear structure
 *     are cleared.
 *
 *  @b Writes
 *  @n TAC_CFG_BEII_ICS0_SGCP0_CYC_OVER_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP0_FIFO_OVER_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP0_SEQ_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP0_IB_WR_MISS_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP1_CYC_OVER_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP1_FIFO_OVER_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP1_SEQ_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP1_IB_WR_MISS_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP2_CYC_OVER_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP2_FIFO_OVER_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP2_SEQ_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP2_IB_WR_MISS_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP3_CYC_OVER_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP3_FIFO_OVER_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP3_SEQ_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP3_IB_WR_MISS_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP4_CYC_OVER_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP4_FIFO_OVER_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP4_SEQ_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP4_IB_WR_MISS_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP5_CYC_OVER_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP5_FIFO_OVER_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP5_SEQ_CLR,
 *     TAC_CFG_BEII_ICS0_SGCP5_IB_WR_MISS_CLR,
 *     TAC_CFG_BEII_ICS1_FE0_TRANS_CLR,
 *     TAC_CFG_BEII_ICS1_FE1_TRANS_CLR,
 *     TAC_CFG_BEII_ICS1_FE2_TRANS_CLR,
 *     TAC_CFG_BEII_ICS1_BE_WD_CLR
 *
 *  @b Affects
 *  @n TAC_CFG_BEII_IRS0_SGCP0_CYC_OVER_STAT     = 0,
 *     TAC_CFG_BEII_IRS0_SGCP0_FIFO_OVER_STAT    = 0,
 *     TAC_CFG_BEII_IRS0_SGCP0_SEQ_STAT          = 0,
 *     TAC_CFG_BEII_IRS0_SGCP0_IB_WR_MISS_STAT   = 0,
 *     TAC_CFG_BEII_IRS0_SGCP1_CYC_OVER_STAT     = 0,
 *     TAC_CFG_BEII_IRS0_SGCP1_FIFO_OVER_STAT    = 0,
 *     TAC_CFG_BEII_IRS0_SGCP1_SEQ_STAT          = 0,
 *     TAC_CFG_BEII_IRS0_SGCP1_IB_WR_MISS_STAT   = 0,
 *     TAC_CFG_BEII_IRS0_SGCP2_CYC_OVER_STAT     = 0,
 *     TAC_CFG_BEII_IRS0_SGCP2_FIFO_OVER_STAT    = 0,
 *     TAC_CFG_BEII_IRS0_SGCP2_SEQ_STAT          = 0,
 *     TAC_CFG_BEII_IRS0_SGCP2_IB_WR_MISS_STAT   = 0,
 *     TAC_CFG_BEII_IRS0_SGCP3_CYC_OVER_STAT     = 0,
 *     TAC_CFG_BEII_IRS0_SGCP3_FIFO_OVER_STAT    = 0,
 *     TAC_CFG_BEII_IRS0_SGCP3_SEQ_STAT          = 0,
 *     TAC_CFG_BEII_IRS0_SGCP3_IB_WR_MISS_STAT   = 0,
 *     TAC_CFG_BEII_IRS0_SGCP4_CYC_OVER_STAT     = 0,
 *     TAC_CFG_BEII_IRS0_SGCP4_FIFO_OVER_STAT    = 0,
 *     TAC_CFG_BEII_IRS0_SGCP4_SEQ_STAT          = 0,
 *     TAC_CFG_BEII_IRS0_SGCP4_IB_WR_MISS_STAT   = 0,
 *     TAC_CFG_BEII_IRS0_SGCP5_CYC_OVER_STAT     = 0,
 *     TAC_CFG_BEII_IRS0_SGCP5_FIFO_OVER_STAT    = 0,
 *     TAC_CFG_BEII_IRS0_SGCP5_SEQ_STAT          = 0,
 *     TAC_CFG_BEII_IRS0_SGCP5_IB_WR_MISS_STAT   = 0,
 *     TAC_CFG_BEII_IRS1_FE0_TRANS_STAT          = 0,
 *     TAC_CFG_BEII_IRS1_FE1_TRANS_STAT          = 0,
 *     TAC_CFG_BEII_IRS1_FE2_TRANS_STAT          = 0,
 *     TAC_CFG_BEII_IRS1_BE_WD_STAT              = 0
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BEII_interruptStatus  interruptStatus;

    // Get the current interrupt status
    CSL_TAC_BEII_getInterruptStatus(&interruptStatus);

    // Clear all the interrupts that have occured
    CSL_TAC_BEII_clearInterrupts(&interruptStatus);
    @endverbatim
 *
 */
void CSL_TAC_BEII_clearInterrupts(
    const CSL_TAC_BEII_interruptStatus * interruptsToClear
)
{
    Uint32 word0;
    Uint32 word1;

    word0 =
        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP0_CYC_OVER_CLR,
                 (Uint32)interruptsToClear->sgcp0CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP0_FIFO_OVER_CLR,
                 (Uint32)interruptsToClear->sgcp0FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP0_SEQ_CLR,
                 (Uint32)interruptsToClear->sgcp0SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP0_IB_WR_MISS_CLR,
                 (Uint32)interruptsToClear->sgcp0BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP1_CYC_OVER_CLR,
                 (Uint32)interruptsToClear->sgcp1CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP1_FIFO_OVER_CLR,
                 (Uint32)interruptsToClear->sgcp1FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP1_SEQ_CLR,
                 (Uint32)interruptsToClear->sgcp1SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP1_IB_WR_MISS_CLR,
                 (Uint32)interruptsToClear->sgcp1BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP2_CYC_OVER_CLR,
                 (Uint32)interruptsToClear->sgcp2CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP2_FIFO_OVER_CLR,
                 (Uint32)interruptsToClear->sgcp2FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP2_SEQ_CLR,
                 (Uint32)interruptsToClear->sgcp2SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP2_IB_WR_MISS_CLR,
                 (Uint32)interruptsToClear->sgcp2BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP3_CYC_OVER_CLR,
                 (Uint32)interruptsToClear->sgcp3CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP3_FIFO_OVER_CLR,
                 (Uint32)interruptsToClear->sgcp3FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP3_SEQ_CLR,
                 (Uint32)interruptsToClear->sgcp3SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP3_IB_WR_MISS_CLR,
                 (Uint32)interruptsToClear->sgcp3BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP4_CYC_OVER_CLR,
                 (Uint32)interruptsToClear->sgcp4CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP4_FIFO_OVER_CLR,
                 (Uint32)interruptsToClear->sgcp4FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP4_SEQ_CLR,
                 (Uint32)interruptsToClear->sgcp4SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP4_IB_WR_MISS_CLR,
                 (Uint32)interruptsToClear->sgcp4BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP5_CYC_OVER_CLR,
                 (Uint32)interruptsToClear->sgcp5CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP5_FIFO_OVER_CLR,
                 (Uint32)interruptsToClear->sgcp5FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP5_SEQ_CLR,
                 (Uint32)interruptsToClear->sgcp5SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_ICS0_SGCP5_IB_WR_MISS_CLR,
                 (Uint32)interruptsToClear->sgcp5BuffMissStat);

    word1 =
        CSL_FMK(TAC_CFG_BEII_ICS1_FE0_TRANS_CLR,
                 (Uint32)interruptsToClear->fe0TransErrStat)    |

        CSL_FMK(TAC_CFG_BEII_ICS1_FE1_TRANS_CLR,
                 (Uint32)interruptsToClear->fe1TransErrStat)    |

        CSL_FMK(TAC_CFG_BEII_ICS1_FE2_TRANS_CLR,
                 (Uint32)interruptsToClear->fe2TransErrStat)    |

        CSL_FMK(TAC_CFG_BEII_ICS1_BE_WD_CLR,
                 (Uint32)interruptsToClear->betiWdStat);



#ifndef USE_TAC_MODEL
    hTacRegs->BEII_ICS0 = word0;
    hTacRegs->BEII_ICS1 = word1;
#else
    {
        Uint32 addr;

        addr = (Uint32) &hTacRegs->BEII_ICS0;
        tacPointer->cfgWordWrite(addr, word0);

        addr = (Uint32) &hTacRegs->BEII_ICS1;
        tacPointer->cfgWordWrite(addr, word1);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_BEII_enableInterrupts
 *
 *  @b Description
 *  @n This function enables the BEII Interrupts
 *
 *  @b Arguments
 *  @verbatim
    interruptsToEnable Structure with the BETI interrupts to enable. A given
                       interrupt will be enabled if the corresponding flag is
                       set to 1.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The interrupts specified in the interruptsToEnable structure are
 *     enabled.
 *
 *  @b Writes
 *  @n TAC_CFG_BEII_IE0_SGCP0_CYC_OVER_ENA,
 *     TAC_CFG_BEII_IE0_SGCP0_FIFO_OVER_ENA,
 *     TAC_CFG_BEII_IE0_SGCP0_SEQ_ENA,
 *     TAC_CFG_BEII_IE0_SGCP0_IB_WR_MISS_ENA,
 *     TAC_CFG_BEII_IE0_SGCP1_CYC_OVER_ENA,
 *     TAC_CFG_BEII_IE0_SGCP1_FIFO_OVER_ENA,
 *     TAC_CFG_BEII_IE0_SGCP1_SEQ_ENA,
 *     TAC_CFG_BEII_IE0_SGCP1_IB_WR_MISS_ENA,
 *     TAC_CFG_BEII_IE0_SGCP2_CYC_OVER_ENA,
 *     TAC_CFG_BEII_IE0_SGCP2_FIFO_OVER_ENA,
 *     TAC_CFG_BEII_IE0_SGCP2_SEQ_ENA,
 *     TAC_CFG_BEII_IE0_SGCP2_IB_WR_MISS_ENA,
 *     TAC_CFG_BEII_IE0_SGCP3_CYC_OVER_ENA,
 *     TAC_CFG_BEII_IE0_SGCP3_FIFO_OVER_ENA,
 *     TAC_CFG_BEII_IE0_SGCP3_SEQ_ENA,
 *     TAC_CFG_BEII_IE0_SGCP3_IB_WR_MISS_ENA,
 *     TAC_CFG_BEII_IE0_SGCP4_CYC_OVER_ENA,
 *     TAC_CFG_BEII_IE0_SGCP4_FIFO_OVER_ENA,
 *     TAC_CFG_BEII_IE0_SGCP4_SEQ_ENA,
 *     TAC_CFG_BEII_IE0_SGCP4_IB_WR_MISS_ENA,
 *     TAC_CFG_BEII_IE0_SGCP5_CYC_OVER_ENA,
 *     TAC_CFG_BEII_IE0_SGCP5_FIFO_OVER_ENA,
 *     TAC_CFG_BEII_IE0_SGCP5_SEQ_ENA,
 *     TAC_CFG_BEII_IE0_SGCP5_IB_WR_MISS_ENA,
 *     TAC_CFG_BEII_IE1_FE0_TRANS_ENA,
 *     TAC_CFG_BEII_IE1_FE1_TRANS_ENA,
 *     TAC_CFG_BEII_IE1_FE2_TRANS_ENA,
 *     TAC_CFG_BEII_IE1_BE_WD_ENA
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BEII_interruptStatus  interruptsToEnable;

    // Enable the SGCP 0 FIFO Overflow interrupt
    interruptsToEnable.sgcp0FifoOverStat = 1;

    // Enable the BETI Watch Dog interrupt
    interruptsToEnable.betiWdStat        = 1;

    // Don't Enable the rest of the interrupts
    interruptsToEnable.sgcp0CycOverStat  = 0;
    interruptsToEnable.sgcp0SeqStat      = 0;
    interruptsToEnable.sgcp0BuffMissStat = 0;
    interruptsToEnable.sgcp1CycOverStat  = 0;
    interruptsToEnable.sgcp1FifoOverStat = 0;
    interruptsToEnable.sgcp1BuffMissStat = 0;
    interruptsToEnable.sgcp1SeqStat      = 0;
    interruptsToEnable.sgcp2CycOverStat  = 0;
    interruptsToEnable.sgcp2FifoOverStat = 0;
    interruptsToEnable.sgcp2BuffMissStat = 0;
    interruptsToEnable.sgcp2SeqStat      = 0;
    interruptsToEnable.sgcp3CycOverStat  = 0;
    interruptsToEnable.sgcp3FifoOverStat = 0;
    interruptsToEnable.sgcp3BuffMissStat = 0;
    interruptsToEnable.sgcp3SeqStat      = 0;
    interruptsToEnable.sgcp4CycOverStat  = 0;
    interruptsToEnable.sgcp4FifoOverStat = 0;
    interruptsToEnable.sgcp4BuffMissStat = 0;
    interruptsToEnable.sgcp4SeqStat      = 0;
    interruptsToEnable.sgcp5CycOverStat  = 0;
    interruptsToEnable.sgcp5FifoOverStat = 0;
    interruptsToEnable.sgcp5BuffMissStat = 0;
    interruptsToEnable.sgcp5SeqStat      = 0;
    interruptsToEnable.fe0TransErrStat   = 0;
    interruptsToEnable.fe1TransErrStat   = 0;
    interruptsToEnable.fe2TransErrStat   = 0;

    CSL_TAC_BEII_enableInterrupts(&interruptsToEnable);
    @endverbatim
 *
 */
void CSL_TAC_BEII_enableInterrupts(
    const CSL_TAC_BEII_interruptStatus * interruptsToEnable
)
{
    Uint32 word0;
    Uint32 word1;

    word0 =
        CSL_FMK(TAC_CFG_BEII_IE0_SGCP0_CYC_OVER_ENA,
                 (Uint32)interruptsToEnable->sgcp0CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP0_FIFO_OVER_ENA,
                 (Uint32)interruptsToEnable->sgcp0FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP0_SEQ_ENA,
                 (Uint32)interruptsToEnable->sgcp0SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP0_IB_WR_MISS_ENA,
                 (Uint32)interruptsToEnable->sgcp0BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP1_CYC_OVER_ENA,
                 (Uint32)interruptsToEnable->sgcp1CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP1_FIFO_OVER_ENA,
                 (Uint32)interruptsToEnable->sgcp1FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP1_SEQ_ENA,
                 (Uint32)interruptsToEnable->sgcp1SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP1_IB_WR_MISS_ENA,
                 (Uint32)interruptsToEnable->sgcp1BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP2_CYC_OVER_ENA,
                 (Uint32)interruptsToEnable->sgcp2CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP2_FIFO_OVER_ENA,
                 (Uint32)interruptsToEnable->sgcp2FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP2_SEQ_ENA,
                 (Uint32)interruptsToEnable->sgcp2SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP2_IB_WR_MISS_ENA,
                 (Uint32)interruptsToEnable->sgcp2BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP3_CYC_OVER_ENA,
                 (Uint32)interruptsToEnable->sgcp3CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP3_FIFO_OVER_ENA,
                 (Uint32)interruptsToEnable->sgcp3FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP3_SEQ_ENA,
                 (Uint32)interruptsToEnable->sgcp3SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP3_IB_WR_MISS_ENA,
                 (Uint32)interruptsToEnable->sgcp3BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP4_CYC_OVER_ENA,
                 (Uint32)interruptsToEnable->sgcp4CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP4_FIFO_OVER_ENA,
                 (Uint32)interruptsToEnable->sgcp4FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP4_SEQ_ENA,
                 (Uint32)interruptsToEnable->sgcp4SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP4_IB_WR_MISS_ENA,
                 (Uint32)interruptsToEnable->sgcp4BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP5_CYC_OVER_ENA,
                 (Uint32)interruptsToEnable->sgcp5CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP5_FIFO_OVER_ENA,
                 (Uint32)interruptsToEnable->sgcp5FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP5_SEQ_ENA,
                 (Uint32)interruptsToEnable->sgcp5SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IE0_SGCP5_IB_WR_MISS_ENA,
                 (Uint32)interruptsToEnable->sgcp5BuffMissStat);

    word1 =
        CSL_FMK(TAC_CFG_BEII_IE1_FE0_TRANS_ENA,
                 (Uint32)interruptsToEnable->fe0TransErrStat)    |

        CSL_FMK(TAC_CFG_BEII_IE1_FE1_TRANS_ENA,
                 (Uint32)interruptsToEnable->fe1TransErrStat)    |

        CSL_FMK(TAC_CFG_BEII_IE1_FE2_TRANS_ENA,
                 (Uint32)interruptsToEnable->fe2TransErrStat)    |

        CSL_FMK(TAC_CFG_BEII_IE1_BE_WD_ENA,
                 (Uint32)interruptsToEnable->betiWdStat);

#ifndef USE_TAC_MODEL
    hTacRegs->BEII_IE0 = word0;
    hTacRegs->BEII_IE1 = word1;
#else
    {
        Uint32 addr;

        addr = (Uint32) &hTacRegs->BEII_IE0;
        tacPointer->cfgWordWrite(addr, word0);

        addr = (Uint32) &hTacRegs->BEII_IE1;
        tacPointer->cfgWordWrite(addr, word1);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_BEII_disableInterrupts
 *
 *  @b Description
 *  @n This function disables the BEII Interrupts
 *
 *  @b Arguments
 *  @verbatim
    interruptsToEnable Structure with the BETI interrupts to disable. A given
                       interrupt will be disabled if the corresponding flag is
                       set to 1.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The interrupts specified in the interruptsToDisable structure are
 *     disabled.
 *
 *  @b Writes
 *  @n TAC_CFG_BEII_IECS0_SGCP0_CYC_OVER_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP0_FIFO_OVER_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP0_SEQ_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP0_IB_WR_MISS_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP1_CYC_OVER_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP1_FIFO_OVER_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP1_SEQ_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP1_IB_WR_MISS_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP2_CYC_OVER_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP2_FIFO_OVER_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP2_SEQ_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP2_IB_WR_MISS_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP3_CYC_OVER_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP3_FIFO_OVER_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP3_SEQ_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP3_IB_WR_MISS_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP4_CYC_OVER_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP4_FIFO_OVER_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP4_SEQ_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP4_IB_WR_MISS_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP5_CYC_OVER_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP5_FIFO_OVER_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP5_SEQ_CLEAR,
 *     TAC_CFG_BEII_IECS0_SGCP5_IB_WR_MISS_CLEAR,
 *     TAC_CFG_BEII_IECS1_FE0_TRANS_CLEAR,
 *     TAC_CFG_BEII_IECS1_FE1_TRANS_CLEAR,
 *     TAC_CFG_BEII_IECS1_FE2_TRANS_CLEAR,
 *     TAC_CFG_BEII_IECS1_BE_WD_CLEAR
 *
 *  @b Affects
 *  @n TAC_CFG_BEII_IE0_SGCP0_CYC_OVER_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP0_FIFO_OVER_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP0_SEQ_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP0_IB_WR_MISS_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP1_CYC_OVER_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP1_FIFO_OVER_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP1_SEQ_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP1_IB_WR_MISS_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP2_CYC_OVER_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP2_FIFO_OVER_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP2_SEQ_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP2_IB_WR_MISS_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP3_CYC_OVER_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP3_FIFO_OVER_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP3_SEQ_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP3_IB_WR_MISS_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP4_CYC_OVER_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP4_FIFO_OVER_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP4_SEQ_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP4_IB_WR_MISS_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP5_CYC_OVER_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP5_FIFO_OVER_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP5_SEQ_ENA=0,
 *     TAC_CFG_BEII_IE0_SGCP5_IB_WR_MISS_ENA=0,
 *     TAC_CFG_BEII_IE1_FE0_TRANS_ENA=0,
 *     TAC_CFG_BEII_IE1_FE1_TRANS_ENA=0,
 *     TAC_CFG_BEII_IE1_FE2_TRANS_ENA=0,
 *     TAC_CFG_BEII_IE1_BE_WD_ENA=0
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BEII_interruptStatus  interruptsToDisable;

    // Disable the SGCP 0 FIFO Overflow interrupt
    interruptsToDisable.sgcp0FifoOverStat = 1;

    // Disable the BETI Watch Dog interrupt
    interruptsToDisable.betiWdStat        = 1;

    // Don't touch the rest of the interrupts
    interruptsToDisable.sgcp0CycOverStat  = 0;
    interruptsToDisable.sgcp0SeqStat      = 0;
    interruptsToDisable.sgcp0BuffMissStat = 0;
    interruptsToDisable.sgcp1CycOverStat  = 0;
    interruptsToDisable.sgcp1FifoOverStat = 0;
    interruptsToDisable.sgcp1BuffMissStat = 0;
    interruptsToDisable.sgcp1SeqStat      = 0;
    interruptsToDisable.sgcp2CycOverStat  = 0;
    interruptsToDisable.sgcp2FifoOverStat = 0;
    interruptsToDisable.sgcp2BuffMissStat = 0;
    interruptsToDisable.sgcp2SeqStat      = 0;
    interruptsToDisable.sgcp3CycOverStat  = 0;
    interruptsToDisable.sgcp3FifoOverStat = 0;
    interruptsToDisable.sgcp3BuffMissStat = 0;
    interruptsToDisable.sgcp3SeqStat      = 0;
    interruptsToDisable.sgcp4CycOverStat  = 0;
    interruptsToDisable.sgcp4FifoOverStat = 0;
    interruptsToDisable.sgcp4BuffMissStat = 0;
    interruptsToDisable.sgcp4SeqStat      = 0;
    interruptsToDisable.sgcp5CycOverStat  = 0;
    interruptsToDisable.sgcp5FifoOverStat = 0;
    interruptsToDisable.sgcp5BuffMissStat = 0;
    interruptsToDisable.sgcp5SeqStat      = 0;
    interruptsToDisable.fe0TransErrStat   = 0;
    interruptsToDisable.fe1TransErrStat   = 0;
    interruptsToDisable.fe2TransErrStat   = 0;

    CSL_TAC_BEII_disableInterrupts(&interruptsToDisable);
    @endverbatim
 *
 */
void CSL_TAC_BEII_disableInterrupts(
    const CSL_TAC_BEII_interruptStatus * interruptsToDisable
)
{
    Uint32 word0;
    Uint32 word1;

    word0 =
        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP0_CYC_OVER_CLEAR,
                 (Uint32)interruptsToDisable->sgcp0CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP0_FIFO_OVER_CLEAR,
                 (Uint32)interruptsToDisable->sgcp0FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP0_SEQ_CLEAR,
                 (Uint32)interruptsToDisable->sgcp0SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP0_IB_WR_MISS_CLEAR,
                 (Uint32)interruptsToDisable->sgcp0BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP1_CYC_OVER_CLEAR,
                 (Uint32)interruptsToDisable->sgcp1CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP1_FIFO_OVER_CLEAR,
                 (Uint32)interruptsToDisable->sgcp1FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP1_SEQ_CLEAR,
                 (Uint32)interruptsToDisable->sgcp1SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP1_IB_WR_MISS_CLEAR,
                 (Uint32)interruptsToDisable->sgcp1BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP2_CYC_OVER_CLEAR,
                 (Uint32)interruptsToDisable->sgcp2CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP2_FIFO_OVER_CLEAR,
                 (Uint32)interruptsToDisable->sgcp2FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP2_SEQ_CLEAR,
                 (Uint32)interruptsToDisable->sgcp2SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP2_IB_WR_MISS_CLEAR,
                 (Uint32)interruptsToDisable->sgcp2BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP3_CYC_OVER_CLEAR,
                 (Uint32)interruptsToDisable->sgcp3CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP3_FIFO_OVER_CLEAR,
                 (Uint32)interruptsToDisable->sgcp3FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP3_SEQ_CLEAR,
                 (Uint32)interruptsToDisable->sgcp3SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP3_IB_WR_MISS_CLEAR,
                 (Uint32)interruptsToDisable->sgcp3BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP4_CYC_OVER_CLEAR,
                 (Uint32)interruptsToDisable->sgcp4CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP4_FIFO_OVER_CLEAR,
                 (Uint32)interruptsToDisable->sgcp4FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP4_SEQ_CLEAR,
                 (Uint32)interruptsToDisable->sgcp4SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP4_IB_WR_MISS_CLEAR,
                 (Uint32)interruptsToDisable->sgcp4BuffMissStat) |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP5_CYC_OVER_CLEAR,
                 (Uint32)interruptsToDisable->sgcp5CycOverStat)  |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP5_FIFO_OVER_CLEAR,
                 (Uint32)interruptsToDisable->sgcp5FifoOverStat) |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP5_SEQ_CLEAR,
                 (Uint32)interruptsToDisable->sgcp5SeqStat)      |

        CSL_FMK(TAC_CFG_BEII_IECS0_SGCP5_IB_WR_MISS_CLEAR,
                 (Uint32)interruptsToDisable->sgcp5BuffMissStat);

    word1 =
        CSL_FMK(TAC_CFG_BEII_IECS1_FE0_TRANS_CLEAR,
                 (Uint32)interruptsToDisable->fe0TransErrStat)    |

        CSL_FMK(TAC_CFG_BEII_IECS1_FE1_TRANS_CLEAR,
                 (Uint32)interruptsToDisable->fe1TransErrStat)    |

        CSL_FMK(TAC_CFG_BEII_IECS1_FE2_TRANS_CLEAR,
                 (Uint32)interruptsToDisable->fe2TransErrStat)    |

        CSL_FMK(TAC_CFG_BEII_IECS1_BE_WD_CLEAR,
             (Uint32)interruptsToDisable->betiWdStat);



#ifndef USE_TAC_MODEL
    hTacRegs->BEII_IECS0 = word0;
    hTacRegs->BEII_IECS1 = word1;
#else
    {
        Uint32 addr;

        addr = (Uint32) &hTacRegs->BEII_IECS0;
        tacPointer->cfgWordWrite(addr, word0);

        addr = (Uint32) &hTacRegs->BEII_IECS1;
        tacPointer->cfgWordWrite(addr, word1);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_BEII_setEOI
 *
 *  @b Description
 *  @n This function configures the BEII End of Interrupt register.
 *
 *  @b Arguments
 *  @verbatim
    eoiVecValue       EOI Vector value
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
 *  @n None
 *
 *  @b Writes
 *  @n TAC_CFG_BEII_EOI_EOI
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BEII_setEOI(5000);
    @endverbatim
 *
 */
void CSL_TAC_BEII_setEOI(
    Uint32 eoiVecValue
)
{
#ifndef USE_TAC_MODEL
    hTacRegs->BEII_EOI = eoiVecValue;
#else
    {
        Uint32 addr;

        addr = (Uint32) &hTacRegs->BEII_EOI;
        tacPointer->cfgWordWrite(addr, eoiVecValue);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_BEII_getEOI
 *
 *  @b Description
 *  @n This function returns the contents of BEII End of Interrupt register.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n Uint32
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_BEII_EOI_EOI
 *
 *  @b Example
 *  @verbatim
    Uint32  eoiVal;

    eoiVal = CSL_TAC_BEII_getEOI();
    @endverbatim
 *
 */
Uint32 CSL_TAC_BEII_getEOI(void)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->BEII_EOI;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->BEII_EOI;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return word;
}

/**
 *  @n@b CSL_TAC_BE_getStrmPwrMeasMode
 *
 *  @b Description
 *  @n This function returns the accumulation mode used
 *     for the stream power measurement.
 *
 *  @b Arguments
 *  @verbatim
    None
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  CSL_TAC_BE_strmPwrMeasMode_SlotMode
 *          The accumulation length is 1 slot (2560 chips)
 *  @n  CSL_TAC_BE_strmPwrMeasMode_SymbolMode
 *          The accumulation length is 1 symbol (256 chips)
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n TAC_CFG_BETI_SPC_ACC_MODE
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BE_strmPwrMeasMode measMode;

    measMode = CSL_TAC_BE_getStrmPwrMeasMode();
    @endverbatim
 *
 */
CSL_TAC_BE_strmPwrMeasMode CSL_TAC_BE_getStrmPwrMeasMode(void)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacRegs->BETI_SPC;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacRegs->BETI_SPC;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32)tmp;
    }
#endif

    return (CSL_TAC_BE_strmPwrMeasMode)
        CSL_FEXT (word, TAC_CFG_BETI_SPC_ACC_MODE);
}

/**
 *  @n@b CSL_TAC_BE_setSwIterStart
 *
 *  @b Description
 *  @n This function enables the Software to bypass the HW iteration start
 *     line and triggers one iteration processing on each SGCP.
 *
 *     This function should be used only for debugging purposes.
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
 *  @n The HW iteration start line is bypassed. After this point the
 *     iteration processing can be triggered only by subsequent calls
 *     to \a CSL_TAC_BE_setSwIterStart() API.
 *
 *     To take the HW out of this mode the application needs to issue a
 *     a device reset using \a CSL_TAC_FE_softwareReset() API.
 *
 *  @b Writes
 *  @n TAC_CFG_BETI_SW_ITE_START_ITE_START=1
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BE_Timestamp_req   timestamp;
    Uint16  frame = 0;
    Uint16  chip  = 0;
    Uint8   slot  = 0;
    Uint16  numIter;

    // Repeat for 640 iterations
    for (numIter = 0; numIter < 640; numIter++)
    {
        // Set the time stamp in the HW
        timestamp.chipId  = chip;
        timestamp.slotId  = slot;
        timestamp.frameId = frame;

        CSL_TAC_BE_setTimestamp(&timestamp);

        // Trigger 1 iteration worth of processing
        CSL_TAC_BE_setSwIterStart();

        ...
        // Increment the chip by 1 iteration (i.e. 4 chips)
        chip += 4;

        // Check for the slot boundary
        if (chip == 2560)
        {
            // Check for the frame boundary
            if (++slot == 15)
            {
                slot = 0;

                // Check for the super frame wrap
                frame = (frame + 1) & 4095;
            }
        }
    }
    @endverbatim
 *
 */
void CSL_TAC_BE_setSwIterStart(void)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hTacRegs->BETI_SW_ITE_START,
               TAC_CFG_BETI_SW_ITE_START_ITE_START,
               TRIGGER);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(TAC_CFG_BETI_SW_ITE_START_ITE_START, TRIGGER);
        addr = (Uint32) &hTacRegs->BETI_SW_ITE_START;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_BE_setTimestamp
 *
 *  @b Description
 *  @n This function configures the Back End Timestamp register.
 *
 *  @b Arguments
 *  @verbatim
    timestamp       Structure with timestamp parameters.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n  None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The Back-End Timestamp register is set.
 *
 *  @b Writes
 *  @n TAC_DATA_BE_TIME_CHIP, TAC_DATA_BE_TIME_SLOT, TAC_DATA_BE_TIME_FRAME
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BE_Timestamp_req   timestamp;

    timestamp.chipId  = 8;
    timestamp.slotId  = 3;
    timestamp.frameId = 6;

    CSL_TAC_BE_setTimestamp(&timestamp);
    @endverbatim
 *
 */
void CSL_TAC_BE_setTimestamp(
    const CSL_TAC_BE_Timestamp_req * timestamp
)
{
    Uint32 word;

    word =
        CSL_FMK(TAC_DATA_BE_TIME_CHIP,(Uint32)timestamp->chipId) |
        CSL_FMK(TAC_DATA_BE_TIME_SLOT,(Uint32)timestamp->slotId) |
        CSL_FMK(TAC_DATA_BE_TIME_FRAME,(Uint32)timestamp->frameId);

#ifndef USE_TAC_MODEL
    hTacData->BE_TIME = word;
#else
    {
        Uint32 addr;

        addr = (Uint32) &hTacData->BE_TIME;
        tacPointer->slaveWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_BE_getTimestamp
 *
 *  @b Description
 *  @n This function reads the Back End Timestamp register.
 *
 *  @b Arguments
 *  @verbatim
    timestamp       Structure with timestamp parameters.
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
 *  @n TAC_DATA_BE_TIME_CHIP, TAC_DATA_BE_TIME_SLOT, TAC_DATA_BE_TIME_FRAME
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_BE_Timestamp_req   timestamp;

    CSL_TAC_BE_getTimestamp(&timestamp);
    @endverbatim
 *
 */
void CSL_TAC_BE_getTimestamp(
    CSL_TAC_BE_Timestamp_req * timestamp
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hTacData->BE_TIME;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hTacData->BE_TIME;
        tacPointer->slaveWordRead(addr, tmp);
        word = (Uint32)tmp;
    }

#endif

    timestamp->chipId  = CSL_FEXT (word, TAC_DATA_BE_TIME_CHIP);
    timestamp->slotId  = CSL_FEXT (word, TAC_DATA_BE_TIME_SLOT);
    timestamp->frameId = CSL_FEXT (word, TAC_DATA_BE_TIME_FRAME);

    return;
}

/**
@}
*/

/* end of csl_tac2_regsBEAux.c */


