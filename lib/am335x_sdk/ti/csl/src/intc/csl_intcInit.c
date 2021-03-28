/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2002, 2003, 2004, 2005, 2008                 
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
 *  @file  csl_intcInit.c
 *
 *  @brief    File for functional layer of CSL API CSL_intcInit()
 *
 *  PATH  $(CSLPATH)\src\intc
 */

/* =============================================================================
 *  Revision History
 *  ===============
 *  12-Jun-2004 Ruchika Kharwar File Created
 *
 *  16-Mar-2005 brn modified for doxygen documentation
 *  19-Nov-2008 Updated for Doxygen
 * =============================================================================
 */

#include <ti/csl/src/intc/csl_intc.h>
#include <ti/csl/src/intc/_csl_intc.h>
#include <ti/csl/src/intc/csl_intcAux.h>
#include <ti/csl/src/intc/csl_intcAsmUtils.h>

#if defined(_TMS320C6X)
CSL_SET_CSECT (CSL_intcInit, ".text:csl_section:intc")
#endif

CSL_Status CSL_intcInit (
    CSL_IntcContext   *pContext
)
{
    Uint16       i;
    
    CSL_dint();
    
    if (pContext != NULL) {
        CSL_intcEventOffsetMap =  pContext->offsetResv;
        CSL_intcAllocMask = pContext->eventAllocMask;
        CSL_intcNumEvents =  pContext->numEvtEntries;
        
        for (i = 0; i < ((CSL_INTC_EVENTID_CNT + 31U) / 32U); i++)
        {
            CSL_intcAllocMask[i] = 0;
        }        
        for (i = 0; i < CSL_INTC_EVENTID_CNT ; i++)
        {
            CSL_intcEventOffsetMap[i] = (Int8)CSL_INTC_MAPPED_NONE;
        }
        if (pContext->eventhandlerRecord != NULL) 
        {
            CSL_intcEventHandlerRecord_p  = pContext->eventhandlerRecord;            
            for (i = 0; i < CSL_intcNumEvents; i++) 
            {
                CSL_intcEventHandlerRecord_p[i].handler = CSL_INTC_EVTHANDLER_NONE;
            }
        }       
    } 
    CSL_intcIvpSet();
    CSL_intcCpuIntrTable.nmiIsr  = &CSL_intcNmiDummy;
    CSL_intcCpuIntrTable.isr4  = &CSL_intcDispatcher;
    CSL_intcCpuIntrTable.isr5  = &CSL_intcDispatcher;
    CSL_intcCpuIntrTable.isr6  = &CSL_intcDispatcher;
    CSL_intcCpuIntrTable.isr7  = &CSL_intcDispatcher;
    CSL_intcCpuIntrTable.isr8  = &CSL_intcDispatcher;
    CSL_intcCpuIntrTable.isr9  = &CSL_intcDispatcher;
    CSL_intcCpuIntrTable.isr10 = &CSL_intcDispatcher;
    CSL_intcCpuIntrTable.isr11 = &CSL_intcDispatcher;
    CSL_intcCpuIntrTable.isr12 = &CSL_intcDispatcher;
    CSL_intcCpuIntrTable.isr13 = &CSL_intcDispatcher;
    CSL_intcCpuIntrTable.isr14 = &CSL_intcDispatcher;
    CSL_intcCpuIntrTable.isr15 = &CSL_intcDispatcher;
    
    CSL_rint();
    
    return CSL_SOK;
}

