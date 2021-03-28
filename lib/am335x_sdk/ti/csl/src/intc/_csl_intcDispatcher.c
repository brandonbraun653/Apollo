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

/*
 *  @file  _csl_intcDispatcher.c
 *
 *  @brief   File for functional layer of CSL API CSL_intcDispatcherInit(..)
 *
 *  PATH  $(CSLPATH)\src\intc
 */
 
/* =============================================================================
 *  Revision History
 *  ===============
 *  12-Jun-2004 Ruchika Kharwar File Created
 *  19-Nov-2008 Updated for Doxygen
 * =============================================================================
 */

#include <ti/csl/src/intc/csl_intc.h>
#include <ti/csl/src/intc/_csl_intc.h>
#include <ti/csl/src/intc/csl_intcAux.h>
#if defined(_TMS320C6X)
CSL_SET_CSECT (CSL_intcDispatcher, ".text:csl_section:intc")
#endif

interrupt void CSL_intcDispatcher (void)
{
    Uint32  evtId;
    Uint32  intrId = (CSL_intcCpuIntrTable.currentVectId - \
                    (Uint32)(&CSL_intcCpuIntrTable) - 4U)/4U;
        
    /* Get the Event Source of the Interrupt */
    if (intrId < 8U) 
    {
        evtId = CSL_FEXTR(((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->INTMUX1, \
                            (intrId-4U)*8U+6U,(intrId-4U)*8U);
    }
    else 
    {
        if (intrId < 12U)
        { 
            evtId = CSL_FEXTR(((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->INTMUX2, \
                                (intrId-8U)*8U+6U,(intrId-8U)*8U);
        }
        else 
        {    evtId = CSL_FEXTR(((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->INTMUX3, \
                                (intrId-12U)*8U+6U,(intrId-12U)*8U);
        }
    }
    
    if (CSL_intcEventOffsetMap[evtId] != CSL_INTC_MAPPED_NONE)
    { 
        CSL_intcEventHandlerRecord_p[CSL_intcEventOffsetMap[evtId]].handler (
            CSL_intcEventHandlerRecord_p[CSL_intcEventOffsetMap[evtId]].arg 
            );    
    }
}
