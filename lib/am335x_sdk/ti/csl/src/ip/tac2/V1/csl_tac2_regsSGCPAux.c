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
 *  @file  csl_tac2_regsSGCPAux.c
 *
 *  @brief This file contains API implementation for the CSL for the TAC2 SGCP
 *         interface.
 *
 */

#include <ti/csl/src/ip/tac2/V0/csl_tac2_regsSGCPAux.h>

/** @addtogroup CSL_TAC_SGCP_FUNCTION
@{
*/

/* =============================================================================
 * Functions linked to SGCP management
 * =============================================================================
 */

/**
 *  @n@b    CSL_TAC_SGCP_enable
 *
 *  @b Description
 *  @n This function enables a Spreader Group Co-Processor (SGCP)
 *     identified by \a sgcpId.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP to enable.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The SGCP Sequencer is enabled.
 *
 *  @b Writes
 *  @n SGCP_CFG_SGCP_SEQ_ENA_ENABLE=1
 *
 *  @b Example
 *  @verbatim
    // Enable SGCP 0
    CSL_TAC_SGCP_enable(0);

    // Enable SGCP 1
    CSL_TAC_SGCP_enable(1);
    @endverbatim
 *
 */
void CSL_TAC_SGCP_enable(
    Uint8 sgcpId
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hSgcpRegs[sgcpId].SGCP_SEQ_ENA,
               SGCP_CFG_SGCP_SEQ_ENA_ENABLE,
               ENABLE);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(SGCP_CFG_SGCP_SEQ_ENA_ENABLE, ENABLE);
        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_SEQ_ENA;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_SGCP_disable
 *
 *  @b Description
 *  @n This function disables a Spreader Group Co-Processor (SGCP)
 *     identified by \a sgcpId.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP to disable.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n None
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n The SGCP Sequencer is disabled.
 *
 *  @b Writes
 *  @n SGCP_CFG_SGCP_SEQ_ENA_ENABLE=0
 *
 *  @b Example
 *  @verbatim
    // Disable SGCP 0
    CSL_TAC_SGCP_disable(0);

    // Disable SGCP 1
    CSL_TAC_SGCP_disable(1);
    @endverbatim
 *
 */
void CSL_TAC_SGCP_disable(
    Uint8 sgcpId
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hSgcpRegs[sgcpId].SGCP_SEQ_ENA,
               SGCP_CFG_SGCP_SEQ_ENA_ENABLE,
               DISABLE);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(SGCP_CFG_SGCP_SEQ_ENA_ENABLE, DISABLE);
        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_SEQ_ENA;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_SGCP_getActiveCycles
 *
 *  @b Description
 *  @n This function returns the number of active cycles in the
 *     previous iteration.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP to get status from.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n The number of active cycles
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n SGCP_CFG_SGCP_SEQ_ACT_ACT_COUNT
 *
 *  @b Example
 *  @verbatim
    Uint16  actCycles;

    // Get the Active cycles for SGCP 0
    actCycles = CSL_TAC_SGCP_getActiveCycles(0);

    // Get the Active cycles for SGCP 1
    actCycles = CSL_TAC_SGCP_getActiveCycles(1);
    @endverbatim
 *
 */
Uint16 CSL_TAC_SGCP_getActiveCycles(
    Uint8 sgcpId
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hSgcpRegs[sgcpId].SGCP_SEQ_ACT;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_SEQ_ACT;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32) tmp;
    }
#endif

    return (Uint16)(CSL_FEXT (word, SGCP_CFG_SGCP_SEQ_ACT_ACT_COUNT));
}

/**
 *  @n@b CSL_TAC_SGCP_getSequencerCycles
 *
 *  @b Description
 *  @n This function returns the number of sequencer-used cycles in the
 *     previous iteration.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP to get status from.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n The number of cycles consumed by the sequencer.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n SGCP_CFG_SGCP_SEQ_CYC_SEQ_COUNT
 *
 *  @b Example
 *  @verbatim
    Uint16  seqCycles;

    // Get the Sequencer used cycles for SGCP 0
    seqCycles = CSL_TAC_SGCP_getSequencerCycles(0);

    // Get the Sequencer used cycles for SGCP 1
    seqCycles = CSL_TAC_SGCP_getSequencerCycles(1);
    @endverbatim
 *
 */
Uint16 CSL_TAC_SGCP_getSequencerCycles(
    Uint8 sgcpId
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hSgcpRegs[sgcpId].SGCP_SEQ_CYC;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_SEQ_CYC;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32) tmp;
    }
#endif

    return (Uint16)(CSL_FEXT (word, SGCP_CFG_SGCP_SEQ_CYC_SEQ_COUNT));
}

/**
 *  @n@b CSL_TAC_SGCP_getReadTime
 *
 *  @b Description
 *  @n This function reads the SGCP 0 read timestamp register.
 *
 *  @b Arguments
 *  @verbatim
    timestamp       Structure with timestamp parameters.
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
 *  @b Reads
 *  @n SGCP_CFG_SGCP_RD_SYS_TIME_CHIP_NB, SGCP_CFG_SGCP_RD_SYS_TIME_SLOT_NB,
 *     SGCP_CFG_SGCP_RD_SYS_TIME_FRAME_NB
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_SGCP_Timestamp_req  timestamp;

    ...
    CSL_TAC_SGCP_getReadTime(&timestamp);
    ...
    @endverbatim
 */
void CSL_TAC_SGCP_getReadTime(
    CSL_TAC_SGCP_Timestamp_req * timestamp
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hSgcpRegs[0].SGCP_RD_SYS_TIME;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hSgcpRegs[0].SGCP_RD_SYS_TIME;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32) tmp;
    }
#endif

    timestamp->chipId  = CSL_FEXT (word, SGCP_CFG_SGCP_RD_SYS_TIME_CHIP_NB);
    timestamp->slotId  = CSL_FEXT (word, SGCP_CFG_SGCP_RD_SYS_TIME_SLOT_NB);
    timestamp->frameId = CSL_FEXT (word, SGCP_CFG_SGCP_RD_SYS_TIME_FRAME_NB);

    return;
}

/**
 *  @n@b CSL_TAC_SGCP_getCycleOverflowStatus
 *
 *  @b Description
 *  @n This function returns the task and page Ids that form the SRM ID
 *     that was last active.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId              Which SGCP to get status from.

    cycleOverflowStatus Structure with cycle over flow parameters.
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
 *  @b Reads
 *  @n SGCP_CFG_SGCP_CYC_OVER_ITE_NB, SGCP_CFG_SGCP_CYC_OVER_CYC_OVER_FLG,
 *     SGCP_CFG_SGCP_CYC_OVER_PAGE_IDX, SGCP_CFG_SGCP_CYC_OVER_TASK_IDX
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_SGCP_cycleOverflowStatus  cycleOverflowStatus;

    ...
    // Get the status for SGCP 0
    CSL_TAC_SGCP_getCycleOverflowStatus(0, &cycleOverflowStatus);
    ...

    // Get the status for SGCP 1
    CSL_TAC_SGCP_getCycleOverflowStatus(1, &cycleOverflowStatus);
    ...
    @endverbatim
 *
 */
void CSL_TAC_SGCP_getCycleOverflowStatus(
    Uint8                              sgcpId,
    CSL_TAC_SGCP_cycleOverflowStatus * cycleOverflowStatus
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hSgcpRegs[sgcpId].SGCP_CYC_OVER;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_CYC_OVER;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32) tmp;
    }
#endif

    cycleOverflowStatus->iteNb =
        CSL_FEXT (word, SGCP_CFG_SGCP_CYC_OVER_ITE_NB);

    cycleOverflowStatus->overflowFlag  =
        CSL_FEXT (word, SGCP_CFG_SGCP_CYC_OVER_CYC_OVER_FLG);

    cycleOverflowStatus->pageIdx =
        CSL_FEXT (word, SGCP_CFG_SGCP_CYC_OVER_PAGE_IDX);

    cycleOverflowStatus->taskIdx  =
        CSL_FEXT (word, SGCP_CFG_SGCP_CYC_OVER_TASK_IDX);

    return;
}

/**
 *  @n@b CSL_TAC_SGCP_resetCycleOverflowStatus
 *
 *  @b Description
 *  @n This function resets the Cycle overflow error status.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId              Which SGCP's error status to reset.
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
 *  @n SGCP_CFG_SGCP_CYC_OVER_CYC_OVER_FLG=1
 *
 *  @b Affects
 *  @n SGCP_CFG_SGCP_CYC_OVER_CYC_OVER_FLG=0
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_SGCP_cycleOverflowStatus  cycleOverflowStatus;

    ...
    // Get the status for SGCP 0
    CSL_TAC_SGCP_getCycleOverflowStatus(0, &cycleOverflowStatus);

    if (cycleOverflowStatus.overflowFlag)
    {
        CSL_TAC_SGCP_resetFIFOOverflowStatus(0);
    }

    // Get the status for SGCP 1
    CSL_TAC_SGCP_getCycleOverflowStatus(1, &cycleOverflowStatus);

    if (cycleOverflowStatus.overflowFlag)
    {
        CSL_TAC_SGCP_resetFIFOOverflowStatus(1);
    }
    @endverbatim
 *
 */
void CSL_TAC_SGCP_resetCycleOverflowStatus(
    Uint8 sgcpId
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hSgcpRegs[sgcpId].SGCP_CYC_OVER,
               SGCP_CFG_SGCP_CYC_OVER_CYC_OVER_FLG,
               ERROR_OCCURED);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(SGCP_CFG_SGCP_CYC_OVER_CYC_OVER_FLG, ERROR_OCCURED);
        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_CYC_OVER;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_SGCP_getSymbolBuffMissStatus
 *
 *  @b Description
 *  @n This function returns the task and page Ids that form the SRM ID.
 *     This is the symbol input buffer location where the write miss
 *     error occured.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId              Which SGCP to get status from.

    symBuffMissStatus   Structure with symbol buffer miss parameters
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
 *  @b Reads
 *  @n SGCP_CFG_SGCP_IB_MISS_ITE_NB, SGCP_CFG_SGCP_IB_MISS_WR_MISS,
 *     SGCP_CFG_SGCP_IB_MISS_PAGE_IDX, SGCP_CFG_SGCP_IB_MISS_TASK_IDX
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_SGCP_symbolBuffMissStatus  symBuffMissStatus;

    ...
    // Get the status for SGCP 0
    CSL_TAC_SGCP_getSymbolBuffMissStatus(0, &symBuffMissStatus);
    ...

    // Get the status for SGCP 1
    CSL_TAC_SGCP_getSymbolBuffMissStatus(1, &symBuffMissStatus);
    ...
    @endverbatim
 *
 */
void CSL_TAC_SGCP_getSymbolBuffMissStatus(
    Uint8                               sgcpId,
    CSL_TAC_SGCP_symbolBuffMissStatus * symBuffMissStatus
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hSgcpRegs[sgcpId].SGCP_IB_MISS;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_IB_MISS;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32) tmp;
    }
#endif

    symBuffMissStatus->iteNb =
        CSL_FEXT (word, SGCP_CFG_SGCP_IB_MISS_ITE_NB);

    symBuffMissStatus->writeMissFlag =
        CSL_FEXT (word, SGCP_CFG_SGCP_IB_MISS_WR_MISS);

    symBuffMissStatus->pageIdx  =
        CSL_FEXT (word, SGCP_CFG_SGCP_IB_MISS_PAGE_IDX);

    symBuffMissStatus->taskIdx  =
        CSL_FEXT (word, SGCP_CFG_SGCP_IB_MISS_TASK_IDX);

    return;
}

/**
 *  @n@b CSL_TAC_SGCP_resetSymbolBuffMissStatus
 *
 *  @b Description
 *  @n This function resets the Symbol Buffer Miss error status.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId              Which SGCP's error status to reset.
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
 *  @n SGCP_CFG_SGCP_IB_MISS_WR_MISS=1
 *
 *  @b Affects
 *  @n SGCP_CFG_SGCP_IB_MISS_WR_MISS=0
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_SGCP_symbolBuffMissStatus  symBuffMissStatus;

    ...
    // Get the status for SGCP 0
    CSL_TAC_SGCP_getSymbolBuffMissStatus(0, &symBuffMissStatus);

    if (symBuffMissStatus.writeMissFlag)
    {
        CSL_TAC_SGCP_resetSymbolBuffMissStatus(0);
    }

    // Get the status for SGCP 1
    CSL_TAC_SGCP_getSymbolBuffMissStatus(1, &symBuffMissStatus);

    if (symBuffMissStatus.writeMissFlag)
    {
        CSL_TAC_SGCP_resetSymbolBuffMissStatus(1);
    }
    @endverbatim
 *
 */
void CSL_TAC_SGCP_resetSymbolBuffMissStatus(
    Uint8 sgcpId
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hSgcpRegs[sgcpId].SGCP_IB_MISS,
               SGCP_CFG_SGCP_IB_MISS_WR_MISS,
               ERROR_OCCURED);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(SGCP_CFG_SGCP_IB_MISS_WR_MISS, ERROR_OCCURED);
        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_IB_MISS;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_SGCP_getFIFOOverflowStatus
 *
 *  @b Description
 *  @n This function returns the task and page Ids that form the SRM ID.
 *     This is the active task that tried to write into a full FIFO.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId              Which SGCP to get status from.

    fifoOverflowStatus  Structure with FIFO over flow parameters
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
 *  @b Reads
 *  @n SGCP_CFG_SGCP_FIFO_OVER_ITE_NB, SGCP_CFG_SGCP_FIFO_OVER_FIFO_ID,
 *     SGCP_CFG_SGCP_FIFO_OVER_CYC_OVER_FLG, SGCP_CFG_SGCP_FIFO_OVER_PAGE_IDX,
 *     SGCP_CFG_SGCP_FIFO_OVER_TASK_IDX
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_SGCP_fifoOverflowStatus  fifoOverflowStatus;

    ...
    // Get the status for SGCP 0
    CSL_TAC_SGCP_getFIFOOverflowStatus(0, &fifoOverflowStatus);
    ...

    // Get the status for SGCP 1
    CSL_TAC_SGCP_getFIFOOverflowStatus(1, &fifoOverflowStatus);
    ...
    @endverbatim
 *
 */
void CSL_TAC_SGCP_getFIFOOverflowStatus(
    Uint8                             sgcpId,
    CSL_TAC_SGCP_fifoOverflowStatus * fifoOverflowStatus
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hSgcpRegs[sgcpId].SGCP_FIFO_OVER;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_FIFO_OVER;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32) tmp;
    }
#endif

    fifoOverflowStatus->iteNb =
        CSL_FEXT (word, SGCP_CFG_SGCP_FIFO_OVER_ITE_NB);

    fifoOverflowStatus->fifoId =
        CSL_FEXT (word, SGCP_CFG_SGCP_FIFO_OVER_FIFO_ID);

    fifoOverflowStatus->overflowFlag =
        CSL_FEXT (word, SGCP_CFG_SGCP_FIFO_OVER_CYC_OVER_FLG);

    fifoOverflowStatus->pageIdx  =
        CSL_FEXT (word, SGCP_CFG_SGCP_FIFO_OVER_PAGE_IDX);

    fifoOverflowStatus->taskIdx  =
        CSL_FEXT (word, SGCP_CFG_SGCP_FIFO_OVER_TASK_IDX);

    return;
}

/**
 *  @n@b CSL_TAC_SGCP_resetFIFOOverflowStatus
 *
 *  @b Description
 *  @n This function resets the FIFO overflow error status.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId              Which SGCP's error status to reset.
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
 *  @n SGCP_CFG_SGCP_FIFO_OVER_CYC_OVER_FLG=1
 *
 *  @b Affects
 *  @n SGCP_CFG_SGCP_FIFO_OVER_CYC_OVER_FLG=0
 *
 *  @b Example
 *  @verbatim
    CSL_TAC_SGCP_fifoOverflowStatus  fifoOverflowStatus;

    ...
    // Get the status for SGCP 0
    CSL_TAC_SGCP_getFIFOOverflowStatus(0, &fifoOverflowStatus);

    if (fifoOverflowStatus.overflowFlag)
    {
        CSL_TAC_SGCP_resetFIFOOverflowStatus(0);
    }

    // Get the status for SGCP 1
    CSL_TAC_SGCP_getFIFOOverflowStatus(1, &fifoOverflowStatus);

    if (fifoOverflowStatus.overflowFlag)
    {
        CSL_TAC_SGCP_resetFIFOOverflowStatus(1);
    }
    @endverbatim
 *
 */
void CSL_TAC_SGCP_resetFIFOOverflowStatus(
    Uint8 sgcpId
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hSgcpRegs[sgcpId].SGCP_FIFO_OVER,
               SGCP_CFG_SGCP_FIFO_OVER_CYC_OVER_FLG,
               ERROR_OCCURED);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(SGCP_CFG_SGCP_FIFO_OVER_CYC_OVER_FLG, ERROR_OCCURED);
        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_FIFO_OVER;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_SGCP_getFetchQLevel
 *
 *  @b Description
 *  @n This function returns the Fetching Transaction Queue Current
 *     Level for a given SGCP ID.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP Fetching queue current level to read.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n The current value of the level
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n SGCP_CFG_FTQ_CURR_LVL_CURR_LVL
 *
 *  @b Example
 *  @verbatim
    Uint16  level;

    // Get the Queue Level for SGCP 0
    level = CSL_TAC_SGCP_getFetchQLevel(0);
    ...

    // Get the Queue Level for SGCP 1
    level = CSL_TAC_SGCP_getFetchQLevel(1);
    ...
    @endverbatim
 *
 */
Uint32 CSL_TAC_SGCP_getFetchQLevel(
    Uint8 sgcpId
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hSgcpRegs[sgcpId].FTQ_CURR_LVL;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hSgcpRegs[sgcpId].FTQ_CURR_LVL;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32) tmp;
    }
#endif

    return CSL_FEXT (word, SGCP_CFG_FTQ_CURR_LVL_CURR_LVL);
}

/**
 *  @n@b CSL_TAC_SGCP_getFetchQWatermark
 *
 *  @b Description
 *  @n This function returns the Fetching Transaction Queue Water Mark
 *     for a given SGCP ID.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP Fetching queue water mark to read.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n The highest level of the queue.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n Reading of this register resets the value to the current level.
 *
 *  @b Reads
 *  @n SGCP_CFG_FTQ_WTMK_LVL_WATERMARK
 *
 *  @b Example
 *  @verbatim
    Uint16  level;

    // Get the Queue Level for SGCP 0
    level = CSL_TAC_SGCP_getFetchQWatermark(0);
    ...

    // Get the Queue Level for SGCP 1
    level = CSL_TAC_SGCP_getFetchQWatermark(1);
    ...
    @endverbatim
 *
 */
Uint32 CSL_TAC_SGCP_getFetchQWatermark(
    Uint8 sgcpId
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hSgcpRegs[sgcpId].FTQ_WTMK_LVL;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hSgcpRegs[sgcpId].FTQ_WTMK_LVL;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32) tmp;
    }
#endif

    return CSL_FEXT (word, SGCP_CFG_FTQ_WTMK_LVL_WATERMARK);
}

/**
 *  @n@b CSL_TAC_SGCP_resetFetchQueue
 *
 *  @b Description
 *  @n This function resets the Fetch Queue of the corresponding
 *     SGCP by writing into the \a TAC_SGCP_FIFO_RESET register.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP's FIFO to reset.
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
 *  @n SGCP_CFG_SGCP_FIFO_RESET_FETCH_RESET=1
 *
 *  @b Affects
 *  @n SGCP_CFG_FTQ_WTMK_LVL_WATERMARK=0,
 *     SGCP_CFG_FTQ_CURR_LVL_CURR_LVL=0,
 *     SGCP_CFG_SGCP_FIFO_RESET_FETCH_RESET=0
 *
 *
 *  @b Example
 *  @verbatim
    ...
    // Reset the Queue for SGCP 0
    CSL_TAC_SGCP_resetFetchQueue(0);
    ...

    // Reset the Queue for SGCP 1
    CSL_TAC_SGCP_resetFetchQueue(1);
    ...
    @endverbatim
 *
 */
void CSL_TAC_SGCP_resetFetchQueue(
    Uint8 sgcpId
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hSgcpRegs[sgcpId].SGCP_FIFO_RESET,
               SGCP_CFG_SGCP_FIFO_RESET_FETCH_RESET, RESET);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(SGCP_CFG_SGCP_FIFO_RESET_FETCH_RESET, RESET);
        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_FIFO_RESET;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_SGCP_getCPMQLevel
 *
 *  @b Description
 *  @n This function returns the Code Power Measurement Transaction
 *     Queue Current Level for a given SGCP ID.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP CPM queue current level to read.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n The current value of the level
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n SGCP_CFG_CTQ_CURR_LVL_CURR_LVL
 *
 *  @b Example
 *  @verbatim
    Uint16  level;

    // Get the Queue Level for SGCP 0
    level = CSL_TAC_SGCP_getCPMQLevel(0);
    ...

    // Get the Queue Level for SGCP 1
    level = CSL_TAC_SGCP_getCPMQLevel(1);
    ...
    @endverbatim
 *
 */
Uint32 CSL_TAC_SGCP_getCPMQLevel(
    Uint8 sgcpId
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hSgcpRegs[sgcpId].CTQ_CURR_LVL;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hSgcpRegs[sgcpId].CTQ_CURR_LVL;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32) tmp;
    }
#endif

    return CSL_FEXT (word, SGCP_CFG_CTQ_CURR_LVL_CURR_LVL);
}

/**
 *  @n@b CSL_TAC_SGCP_getCPMQWatermark
 *
 *  @b Description
 *  @n This function returns the Code Power Measurement Transaction
 *     Queue Water Mark for a given SGCP ID.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP CPM queue water mark to read.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n The highest level of the queue.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n Reading of this register resets the value to the current level.
 *
 *  @b Reads
 *  @n SGCP_CFG_CTQ_WTMK_LVL_WATERMARK
 *
 *  @b Example
 *  @verbatim
    Uint16  level;

    // Get the Queue Level for SGCP 0
    level = CSL_TAC_SGCP_getCPMQWatermark(0);
    ...

    // Get the Queue Level for SGCP 1
    level = CSL_TAC_SGCP_getCPMQWatermark(1);
    ...
    @endverbatim
 *
 */
Uint32 CSL_TAC_SGCP_getCPMQWatermark(
    Uint8 sgcpId
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hSgcpRegs[sgcpId].CTQ_WTMK_LVL;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hSgcpRegs[sgcpId].CTQ_WTMK_LVL;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32) tmp;

        return CSL_FEXT (word, SGCP_CFG_CTQ_WTMK_LVL_WATERMARK);
    }
#endif

    return CSL_FEXT (word, SGCP_CFG_CTQ_WTMK_LVL_WATERMARK);
}

/**
 *  @n@b CSL_TAC_SGCP_resetCPMQueue
 *
 *  @b Description
 *  @n This function resets the Code Power Measurement Queue of the
 *     corresponding SGCP by writing into the \a TAC_SGCP_FIFO_RESET register.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP's FIFO to reset.
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
 *  @n SGCP_CFG_SGCP_FIFO_RESET_CPM_RESET=1
 *
 *  @b Affects
 *  @n SGCP_CFG_CTQ_WTMK_LVL_WATERMARK=0,
 *     SGCP_CFG_CTQ_CURR_LVL_CURR_LVL=0,
 *     SGCP_CFG_SGCP_FIFO_RESET_CPM_RESET=0
 *
 *  @b Example
 *  @verbatim
    ...
    // Reset the Queue for SGCP 0
    CSL_TAC_SGCP_resetCPMQueue(0);
    ...

    // Reset the Queue for SGCP 1
    CSL_TAC_SGCP_resetCPMQueue(1);
    ...
    @endverbatim
 *
 */
void CSL_TAC_SGCP_resetCPMQueue(
    Uint8 sgcpId
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hSgcpRegs[sgcpId].SGCP_FIFO_RESET,
               SGCP_CFG_SGCP_FIFO_RESET_CPM_RESET, RESET);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(SGCP_CFG_SGCP_FIFO_RESET_CPM_RESET, RESET);
        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_FIFO_RESET;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
 *  @n@b CSL_TAC_SGCP_getWarningQLevel
 *
 *  @b Description
 *  @n This function returns the Warning Transaction Queue Current
 *     Level for a given SGCP ID.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP warning queue current level to read.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n The current value of the level
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n None
 *
 *  @b Reads
 *  @n SGCP_CFG_WTQ_CURR_LVL_CURR_LVL
 *
 *  @b Example
 *  @verbatim
    Uint16  level;

    // Get the Queue Level for SGCP 0
    level = CSL_TAC_SGCP_getWarningQLevel(0);
    ...

    // Get the Queue Level for SGCP 1
    level = CSL_TAC_SGCP_getWarningQLevel(1);
    ...
    @endverbatim
 *
 */
Uint32 CSL_TAC_SGCP_getWarningQLevel(
    Uint8 sgcpId
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hSgcpRegs[sgcpId].WTQ_CURR_LVL;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hSgcpRegs[sgcpId].WTQ_CURR_LVL;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32) tmp;
    }
#endif

    return CSL_FEXT (word, SGCP_CFG_WTQ_CURR_LVL_CURR_LVL);
}

/**
 *  @n@b CSL_TAC_SGCP_getWarningQWatermark
 *
 *  @b Description
 *  @n This function returns the Warning Transaction Queue Water Mark
 *     for a given SGCP ID.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP warning queue water mark to read.
    @endverbatim
 *
 *  <b> Return Value </b>
 *  @n The highest level of the queue.
 *
 *  <b> Pre Condition </b>
 *  @n None
 *
 *  <b> Post Condition </b>
 *  @n Reading of this register resets the value to the current level.
 *
 *  @b Reads
 *  @n SGCP_CFG_WTQ_WTMK_LVL_WATERMARK
 *
 *  @b Example
 *  @verbatim
    Uint16  level;

    // Get the Queue Level for SGCP 0
    level = CSL_TAC_SGCP_getWarningQWatermark(0);
    ...

    // Get the Queue Level for SGCP 1
    level = CSL_TAC_SGCP_getWarningQWatermark(1);
    ...
    @endverbatim
 *
 */
Uint32 CSL_TAC_SGCP_getWarningQWatermark(
    Uint8 sgcpId
)
{
    Uint32 word;

#ifndef USE_TAC_MODEL
    word = hSgcpRegs[sgcpId].WTQ_WTMK_LVL;
#else
    {
        Uint32 addr;
        UINT32 tmp;

        addr = (Uint32) &hSgcpRegs[sgcpId].WTQ_WTMK_LVL;
        tacPointer->cfgWordRead(addr, tmp);
        word = (Uint32) tmp;
    }
#endif

    return CSL_FEXT (word, SGCP_CFG_WTQ_WTMK_LVL_WATERMARK);
}

/**
 *  @n@b CSL_TAC_SGCP_resetWarningQueue
 *
 *  @b Description
 *  @n This function resets the Warning Queue of the corresponding
 *     SGCP by writing into the \a TAC_SGCP_FIFO_RESET register.
 *
 *  @b Arguments
 *  @verbatim
    sgcpId          Which SGCP's FIFO to reset.
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
 *  @n SGCP_CFG_SGCP_FIFO_RESET_WARN_RESET=1
 *
 *  @b Affects
 *  @n SGCP_CFG_WTQ_WTMK_LVL_WATERMARK=0,
 *     SGCP_CFG_WTQ_CURR_LVL_CURR_LVL=0,
 *     SGCP_CFG_SGCP_FIFO_RESET_WARN_RESET=0
 *
 *  @b Example
 *  @verbatim
    ...
    // Reset the Queue for SGCP 0
    CSL_TAC_SGCP_resetWarningQueue(0);
    ...

    // Reset the Queue for SGCP 1
    CSL_TAC_SGCP_resetWarningQueue(1);
    ...
    @endverbatim
 *
 */
void CSL_TAC_SGCP_resetWarningQueue(
    Uint8 sgcpId
)
{
#ifndef USE_TAC_MODEL
    CSL_FWRIT (hSgcpRegs[sgcpId].SGCP_FIFO_RESET,
               SGCP_CFG_SGCP_FIFO_RESET_WARN_RESET, RESET);
#else
    {
        Uint32 addr;
        Uint32 word;

        word = CSL_FMKT(SGCP_CFG_SGCP_FIFO_RESET_WARN_RESET, RESET);
        addr = (Uint32) &hSgcpRegs[sgcpId].SGCP_FIFO_RESET;
        tacPointer->cfgWordWrite(addr, word);
    }
#endif

    return;
}

/**
@}
*/

/* end of csl_tac2_regsSGCPAux.c */

