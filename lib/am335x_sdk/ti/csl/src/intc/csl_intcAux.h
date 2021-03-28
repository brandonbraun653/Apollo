/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2002, 2003, 2004, 2005, 2008, 2018
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
 
/* @file csl_intcAux.h
 *
 * @brief   Header file for functional layer of CSL
 *
 *  PATH  $(CSLPATH)\\inc
 */
 
/* =============================================================================
 *  Revision History
 *  ===============
 *  12-Jun-2004 Ruchika Kharwar File Created
 *  16-Mar-2005 brn modified for doxygen documentation and removed redundant 
                    CSL_intcInterruptEnable, CSL_intcInterruptDisable and 
                    CSL_intcInterruptRestore functions.
    27-Mar-2006 ds  Removed Read access to Write only EVTSET[3] and EVTCLR[3] 
                    registers 
 * =============================================================================
 */
 

#ifndef CSL_INTCAUX_H
#define CSL_INTCAUX_H

#include <ti/csl/src/intc/csl_intc.h>

#ifdef __cplusplus
extern "C" {
#endif

/* External definition for CSL_intcEventOffsetMap */
extern Int8 *CSL_intcEventOffsetMap;

/* External definition for CSL_intcAllocMask */
extern CSL_BitMask32*    CSL_intcAllocMask;

/* External definition for CSL_intcEventHandlerRecord_p */
extern CSL_IntcEventHandlerRecord* CSL_intcEventHandlerRecord_p;

/* External definition for CSL_intcNumEvents */
extern Uint16 CSL_intcNumEvents;

/*  ============================================================================
 *   @n@b CSL_intcMapEventVector
 *
 *   @b Description
 *      This API Maps the event to the given CPU vector
 *      
 *   @b Arguments
 *   @verbatim
        hInts    Handle to the intcs
        vectId   Intc vector identifier 
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       None 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Maps the event to the given CPU vector 
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcHandle     hIntc;
        CSL_IntcVectId     vectId;
        ...
        CSL_intcMapEventVector (hIntc, vectId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline void CSL_intcMapEventVector (
    CSL_IntcEventId    eventId,
    CSL_IntcVectId     vectId
);
static inline void CSL_intcMapEventVector (
    CSL_IntcEventId    eventId,
    CSL_IntcVectId     vectId
)
{
    
    Uint32         bitLow;
    
    if (vectId < CSL_INTC_VECTID_8) {
        bitLow = ((Uint32)(vectId) - 4U) * 8U;
        CSL_FINSR(((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->INTMUX1, \
                  bitLow+6U,bitLow,(Uint32)eventId);
    } 
    else {
        if (vectId < CSL_INTC_VECTID_12) {
            bitLow = ((Uint32)(vectId) - 8U) * 8U;
            CSL_FINSR(((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->INTMUX2, \
                     bitLow+6U,bitLow,(Uint32)eventId);
        } 
        else {
            bitLow = ((Uint32)(vectId) - 12U) * 8U;
            CSL_FINSR(((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->INTMUX3, \
                     bitLow+6U,bitLow,(Uint32)eventId);
        }   
    }
}

/*  ============================================================================
 *   @n@b CSL_intcEventEnable
 *
 *   @b Description
 *      This API enables particular event (EVTMASK0/1/2/3 bit programmation)
 *      
 *   @b Arguments
 *   @verbatim
        eventId   event identifier
        
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       CSL_IntcEventEnableState - Previous state 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  particular event will be enabled
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId             eventId;
        CSL_IntcEventEnableState   eventStat;
        ...
        eventStat = CSL_intcEventEnable (eventId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline CSL_IntcEventEnableState CSL_intcEventEnable (
    CSL_IntcEventId     eventId
);
static inline CSL_IntcEventEnableState CSL_intcEventEnable (
    CSL_IntcEventId     eventId
)
{
    Uint32                      _x;
    Uint32                      _y;
    Uint32                      _regVal;
    CSL_IntcEventEnableState _oldState;
    
    _y = ((Uint32)eventId) >> 5U;
    _x = ((Uint32)eventId) & 0x1fU;
    _regVal = ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTMASK[_y];
    _oldState = CSL_FEXTR(_regVal,_x,_x);
    CSL_FINSR(_regVal,_x,_x,0U);
    ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTMASK[_y] = _regVal;
    
    return _oldState;
}

/*  ============================================================================
 *   @n@b CSL_intcEventDisable
 *
 *   @b Description
 *      This API disables particular event (EVTMASK0/1/2/3 bit programmation)
 *      
 *   @b Arguments
 *   @verbatim
        eventId   event identifier
        
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       CSL_IntcEventEnableState - Previous state 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  particular event will be disabled
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId             eventId;
        CSL_IntcEventEnableState   eventStat;
        ...
        eventStat = CSL_intcEventDisable (eventId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline CSL_IntcEventEnableState  CSL_intcEventDisable (
    CSL_IntcEventId            eventId
);
static inline CSL_IntcEventEnableState  CSL_intcEventDisable (
    CSL_IntcEventId            eventId
)
{
    Uint32                       _x;
    Uint32                       _y;
    Uint32                      _regVal;
    CSL_IntcEventEnableState oldState;
    
    _y = ((Uint32)eventId) >> 5U;
    _x = ((Uint32)eventId) & 0x1fU;
    _regVal = ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTMASK[_y];
    oldState = CSL_FEXTR(_regVal,_x,_x);
    CSL_FINSR(_regVal,_x,_x,1U);
    ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTMASK[_y] = _regVal;
    
    return oldState;
}

/*  ============================================================================
 *   @n@b CSL_intcEventRestore
 *
 *   @b Description
 *      This API restores particular event (EVTMASK0/1/2/3 bit programmation)
 *      
 *   @b Arguments
 *   @verbatim
        eventId   event identifier
        
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       CSL_IntcEventEnableState - Previous state 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  particular event will be restored
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId             eventId;
        CSL_IntcEventEnableState   restoreVal;
        CSL_IntcEventEnableState   eventStat;
        ...
        eventStat = CSL_intcEventRestore (eventId, restoreVal);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline void  CSL_intcEventRestore(
    CSL_IntcEventId               eventId,
    CSL_IntcEventEnableState      restoreVal
);
static inline void  CSL_intcEventRestore(
    CSL_IntcEventId               eventId,
    CSL_IntcEventEnableState      restoreVal
)
{
    Uint32     _x;
    Uint32     _y;
    
    _y = ((Uint32)eventId) >> 5U;
    _x = ((Uint32)eventId) & 0x1fU;
    
    CSL_FINSR(((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTMASK[_y], _x, _x, \
              restoreVal);
}

/*  ============================================================================
 *   @n@b CSL_intcEventSet
 *
 *   @b Description
 *      This API sets Event  (EVTMASK0/1/2/3 bit programmation)
 *      
 *   @b Arguments
 *   @verbatim
        eventId   event identifier
        
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       None 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  particular event will set
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId             eventId;
        ...
        CSL_intcEventSet (eventId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline void  CSL_intcEventSet(
    CSL_IntcEventId               eventId
);
static inline void  CSL_intcEventSet(
    CSL_IntcEventId               eventId
)
{
    Uint32     _x;
    Uint32     _y;
    
    _y = ((Uint32)eventId) >> 5U;
    _x = ((Uint32)eventId) & 0x1fU;
    
    ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTSET[_y] = CSL_FMKR(_x,_x,1U);
}

/*  ============================================================================
 *   @n@b CSL_intcEventClear
 *
 *   @b Description
 *      This API clears particular event (EVTMASK0/1/2/3 bit programmation)
 *      
 *   @b Arguments
 *   @verbatim
        eventId   event identifier
        
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       None 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  particular event will be cleared
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId             eventId;
        ...
        CSL_intcEventClear (eventId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline void  CSL_intcEventClear (
    CSL_IntcEventId               eventId
);
static inline void  CSL_intcEventClear (
    CSL_IntcEventId               eventId
)
{
    Uint32     _x;
    Uint32     _y;
    
    _y = ((Uint32)eventId) >> 5U;
    _x = ((Uint32)eventId) & 0x1fU;
    
    ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTCLR[_y] = CSL_FMKR(_x,_x,1U);
}

/*  ============================================================================
 *   @n@b CSL_intcCombinedEventClear
 *
 *   @b Description
 *      This API clears particular combined events 
 *      (EVTMASK0/1/2/3 bit programmation)
 *      
 *   @b Arguments
 *   @verbatim
        eventId     event identifier
        clearMask   BitMask of events to be cleared
        
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       None 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  particular combined event will be cleared
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId             eventId;
        ...
        CSL_intcCombinedEventClear (eventId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline void  CSL_intcCombinedEventClear(
    CSL_IntcEventId               eventId,
    CSL_BitMask32                 clearMask
);
static inline void  CSL_intcCombinedEventClear(
    CSL_IntcEventId               eventId,
    CSL_BitMask32                 clearMask
)
{
    ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTCLR[eventId] = clearMask;
}

/*  ============================================================================
 *   @n@b CSL_intcCombinedEventGet
 *
 *   @b Description
 *      This API gets particular combined events 
 *      (EVTMASK0/1/2/3 bit programmation)
 *      
 *   @b Arguments
 *   @verbatim
        eventId     event identifier
                
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       CSL_BitMask32 - The combined events information 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId             eventId;
        CSL_BitMask32              combEvntStat;
        ...
        combEvntStat = CSL_intcCombinedEventGet (eventId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline CSL_BitMask32  CSL_intcCombinedEventGet(
   CSL_IntcEventId               eventId
);
static inline CSL_BitMask32  CSL_intcCombinedEventGet(
   CSL_IntcEventId               eventId
)
{
    return (((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->MEVTFLAG[eventId]);
}

/*  ============================================================================
 *   @n@b CSL_intcCombinedEventEnable
 *
 *   @b Description
 *      This API enables particular combined events 
 *      
 *   @b Arguments
 *   @verbatim
        eventId     event identifier
        enableMask  BitMask of events to be enabled     
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       CSL_BitMask32 - previous state 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId             eventId;
        CSL_BitMask32              enableMask;
        CSL_BitMask32              combEvntStat;
        ...
        combEvntStat = CSL_intcCombinedEventEnable (eventId, enableMask);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline CSL_BitMask32  CSL_intcCombinedEventEnable(
    CSL_IntcEventId               eventId,
    CSL_BitMask32                 enableMask
);
static inline CSL_BitMask32  CSL_intcCombinedEventEnable(
    CSL_IntcEventId               eventId,
    CSL_BitMask32                 enableMask
)
{
    CSL_BitMask32 evtMask = 
            ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTMASK[eventId];
     ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTMASK[eventId] &= ~enableMask;
    
    return evtMask;
}

/** ============================================================================
 *   @n@b CSL_intcCombinedEventDisable
 *
 *   @b Description
 *      This API disables particular combined events 
 *      
 *   @b Arguments
 *   @verbatim
        eventId     event identifier
        enableMask  BitMask of events to be disabled     
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       CSL_BitMask32 - previous state 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId             eventId;
        CSL_BitMask32              enableMask;
        CSL_BitMask32              combEvntStat;
        
        ...
        combEvntStat = CSL_intcCombinedEventDisable (eventId, enableMask);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline CSL_BitMask32  CSL_intcCombinedEventDisable (
    CSL_IntcEventId               eventId,
    CSL_BitMask32                 enableMask
);
static inline CSL_BitMask32  CSL_intcCombinedEventDisable (
    CSL_IntcEventId               eventId,
    CSL_BitMask32                 enableMask
)
{
    CSL_BitMask32 evtMask = 
            ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTMASK[eventId];
    ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTMASK[eventId] |= enableMask;
    
    return evtMask ;    
}

/*  ============================================================================
 *   @n@b CSL_intcCombinedEventRestore
 *
 *   @b Description
 *      This API restores particular combined events 
 *      
 *   @b Arguments
 *   @verbatim
        eventId      event identifier
        restoreMask  BitMask of events to be restored     
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       None 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId             eventId;
        CSL_BitMask32              restoreMask
        ...
        CSL_intcCombinedEventRestore (eventId, restoreMask);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline void  CSL_intcCombinedEventRestore(
    CSL_IntcEventId               eventId,
    CSL_BitMask32                 restoreMask
);
static inline void  CSL_intcCombinedEventRestore(
    CSL_IntcEventId               eventId,
    CSL_BitMask32                 restoreMask
)
{
    ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTMASK[eventId] = restoreMask;

}

/*  ============================================================================
 *   @n@b CSL_intcIntrDropEnable
 *
 *   @b Description
 *      This API enables interrupts for which drop detection 
 *      
 *   @b Arguments
 *   @verbatim
        dropMask  Vector id mask
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       None 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_BitMask32              dropMask
        ...
        CSL_intcIntrDropEnable (dropMask);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline void  CSL_intcInterruptDropEnable (
    CSL_BitMask32                dropMask        
);
static inline void  CSL_intcInterruptDropEnable (
    CSL_BitMask32                dropMask        
)
{
    ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->INTDMASK &= ~dropMask;
    
}

/*  ============================================================================
 *   @n@b CSL_intcIntrDropDisable
 *
 *   @b Description
 *      This API disables interrupts for which drop detection 
 *      
 *   @b Arguments
 *   @verbatim
        dropMask  Vector id mask
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_BitMask32              dropMask
        ...
        CSL_intcIntrDropDisable (dropMask);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline void  CSL_intcInterruptDropDisable (
    CSL_BitMask32                dropMask        
);
static inline void  CSL_intcInterruptDropDisable (
    CSL_BitMask32                dropMask        
)
{
    ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->INTDMASK  |= dropMask;
    
}

/*  ============================================================================
 *   @n@b CSL_intcInvokeEventHandle
 *
 *   @b Description
 *     This API is for the purpose of excption handler which will need to be
 * written by the user. This API invokes the event handler regisered by 
 *      the user at the time of event Open and event handler registration 
 *      
 *   @b Arguments
 *   @verbatim
        evtId  Event Id of the function to be invoked
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       CSL_SOK
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcEventId              evtId;
        CSL_Status                   status;
        ...
        status = CSL_intcInvokeEventHandle (evtId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline CSL_Status CSL_intcInvokeEventHandle (
    CSL_IntcEventId     evtId
);
static inline CSL_Status CSL_intcInvokeEventHandle (
    CSL_IntcEventId     evtId
)
{

    if (CSL_intcEventOffsetMap[evtId] != CSL_INTC_MAPPED_NONE) 
    {
        CSL_intcEventHandlerRecord_p[CSL_intcEventOffsetMap[evtId]].handler (
            CSL_intcEventHandlerRecord_p[CSL_intcEventOffsetMap[evtId]].arg );
    }     
    return CSL_SOK;
}

/*  ============================================================================
 *   @n@b CSL_intcQueryEventStatus
 *
 *   @b Description
 *      This API is to check whether a specified event is enabled or not 
 *
 *   @b Arguments
 *   @verbatim
        evtId      Event Id of the query event
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       Bool
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcEventId              evtId;
        Bool                         return;
        ...
        return = CSL_intcQueryEventStatus (evtId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline Bool CSL_intcQueryEventStatus(CSL_IntcEventId eventId);
static inline Bool CSL_intcQueryEventStatus(CSL_IntcEventId eventId)
{
    Uint32     _x;
    Uint32     _y;
    
    _y = ((Uint32)eventId) >> 5U;
    _x = ((Uint32)eventId) & 0x1fU;
    
    return ((Bool)(CSL_FEXTR(((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTFLAG[_y], \
                            _x,_x)));
}

/* CPU Interrupt Handling routines */

/*  ============================================================================
 *   @n@b CSL_intcInterruptEnable
 *
 *   @b Description
 *      This API is enables Interrupt 
 *      
 *   @b Arguments
 *   @verbatim
        vectId      Vector Id of the query event
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       Uint32     - previous state
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId              vectId;
        Uint32                      return;
        ...
        return = CSL_intcInterruptEnable (vectId);
        ...
     @endverbatim
 * ===========================================================================
 */
Uint32 CSL_intcInterruptEnable (
    CSL_IntcVectId vectId
);

/*  ============================================================================
 *   @n@b CSL_intcInterruptDisable
 *
 *   @b Description
 *      This API is disables Interrupt 
 *      
 *   @b Arguments
 *   @verbatim
        vectId      Vector Id of the query event
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       Uint32     - previous state
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId              vectId;
        Uint32                      return;
        ...
        return = CSL_intcInterruptDisable (vectId);
        ...
     @endverbatim
 * ===========================================================================
 */
Uint32 CSL_intcInterruptDisable (
    CSL_IntcVectId vectId
);

/*  ============================================================================
 *   @n@b CSL_intcInterruptRestore
 *
 *   @b Description
 *      This API is restores Interrupt 
 *      
 *   @b Arguments
 *   @verbatim
        vectId      Vector Id of the query event
        restoreVal  Value to be restored
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       None
 *       
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId              vectId;
        Uint32                      restore;
        ...
        CSL_intcInterruptRestore (vectId, restore);
        ...
     @endverbatim
 * ===========================================================================
 */
static inline void CSL_intcInterruptRestore ( 
    CSL_IntcVectId      vectId,
    Uint32              restoreVal
);

/*  ============================================================================
 *   @n@b CSL_intcInterruptSet
 *
 *   @b Description
 *      This API is sets interrupt(ISR) 
 *
 *   @b Arguments
 *   @verbatim
        vectId       Vector id to set

     @endverbatim
 *
 *   <b> Return Value </b> 
 *       None
 *       
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId              vectId;
        ...
        CSL_intcInterruptSet (vectId);
        ...
     @endverbatim
 * ===========================================================================
 */
void CSL_intcInterruptSet ( 
    CSL_IntcVectId      vectId
);

/*  ============================================================================
 *   @n@b CSL_intcInterruptClear
 *
 *   @b Description
 *      This API is clears specified interrupt  
 *      
 *   @b Arguments
 *   @verbatim
        vectId       Vector id to cleared
        
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId              vectId;
        ...
        CSL_intcInterruptClear (vectId);
        ...
     @endverbatim
 * ===========================================================================
 */
void CSL_intcInterruptClear ( 
    CSL_IntcVectId      vectId
);

/*  ============================================================================
 *   @n@b CSL_intcQueryInterruptStatus
 *
 *   @b Description
 *      This API is to check whether a specified CPU interrupt is pending or not  
 *
 *   @b Arguments
 *   @verbatim
        vectId       Vector id to cleared

     @endverbatim
 *
 *   <b> Return Value </b> 
 *       Bool
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcVectId              vectId;
        Bool                        return;
        ...
        return = CSL_intcQueryInterruptStatus (vectId);
        ...
     @endverbatim
 * ===========================================================================
 */
Bool  CSL_intcQueryInterruptStatus (
    CSL_IntcVectId      vectId
);


/* Exception handling routines */

/*  ============================================================================
 *   @n@b CSL_intcExcepEnable
 *
 *   @b Description
 *      This API is enables the specific exception event  
 *      
 *   @b Arguments
 *   @verbatim
        eventId       event id to be enabled
        
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       CSL_IntcEventEnableState
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcEventId             eventId;
        CSL_IntcEventEnableState    return;
        ...
        return = CSL_intcExcepEnable (eventId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline CSL_IntcEventEnableState  CSL_intcExcepEnable (
    CSL_IntcEventId      eventId
);
static inline CSL_IntcEventEnableState  CSL_intcExcepEnable (
    CSL_IntcEventId      eventId
)
{
    Uint32                         _x;
    Uint32                         _y;
    Uint32                         _regVal;
    CSL_IntcEventEnableState    _oldState;
    
    _y = ((Uint32)eventId) >> 5U;
    _x = ((Uint32)eventId) & 0x1fU;
    _regVal = ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EXPMASK[_y];
    _oldState = CSL_FEXTR(_regVal,_x,_x);
    CSL_FINSR(_regVal,_x,_x,0U);
    ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EXPMASK[_y] = _regVal;
    
    return _oldState;
}

/*  ============================================================================
 *   @n@b CSL_intcExcepDisable
 *
 *   @b Description
 *      This API is disables the specific exception event  
 *      
 *   @b Arguments
 *   @verbatim
        eventId       event id to be disabled
        
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       CSL_IntcEventEnableState
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcEventId             eventId;
        CSL_IntcEventEnableState    return;
        ...
        return = CSL_intcExcepDisable (eventId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline CSL_IntcEventEnableState  CSL_intcExcepDisable (
    CSL_IntcEventId            eventId
);
static inline CSL_IntcEventEnableState  CSL_intcExcepDisable (
    CSL_IntcEventId            eventId
)
{
    Uint32                         _x;
    Uint32                         _y;
    Uint32                         _regVal;
    CSL_IntcEventEnableState    oldState;
    
    _y = ((Uint32)eventId) >> 5U;
    _x = ((Uint32)eventId) & 0x1fU;
    _regVal = ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EXPMASK[_y];
    oldState = CSL_FEXTR(_regVal,_x,_x);
    CSL_FINSR(_regVal,_x,_x,1U);
    ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EXPMASK[_y] = _regVal;
    
    return oldState;
}

/*  ============================================================================
 *   @n@b CSL_intcExcepRestore
 *
 *   @b Description
 *      This API restores the specific exception event 
 *      
 *   @b Arguments
 *   @verbatim
        eventId       event id to be restored 
        restoreVal    restore value
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       None 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcEventId             eventId;
        
        ...
        CSL_intcExcepRestore (eventId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline void  CSL_intcExcepRestore (
    CSL_IntcEventId               eventId,
    Uint32                        restoreVal
);
static inline void  CSL_intcExcepRestore (
    CSL_IntcEventId               eventId,
    Uint32                        restoreVal
)
{
    Uint32         _x;
    Uint32         _y;
    
    _y = ((Uint32)eventId) >> 5U;
    _x = ((Uint32)eventId) & 0x1fU;
    CSL_FINSR(((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EXPMASK[_y],_x,_x, \
             restoreVal);
}

/*  ============================================================================
 *   @n@b CSL_intcExcepClear
 *
 *   @b Description
 *      This API clears the specific exception event 
 *      
 *   @b Arguments
 *   @verbatim
        eventId       event id to be cleared 
        
     @endverbatim
 *
 *   <b> Return Value </b> 
 *       None 
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b  Writes
 *   @n  None
 *
 *   @b  Example
 *   @verbatim
        CSL_IntcEventId             eventId;
        
        ...
        CSL_intcExcepClear (eventId);
        ...
     @endverbatim
 * ===========================================================================
 */
/* for misra warnings*/
static inline void  CSL_intcExcepClear (
    CSL_IntcEventId         eventId
);
static inline void  CSL_intcExcepClear (
    CSL_IntcEventId         eventId
)
{
    Uint32         _x;
    Uint32         _y;
    
    _y = ((Uint32)eventId) >> 5U;
    _x = ((Uint32)eventId) & 0x1fU;
   
    ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTCLR[_y] = CSL_FMKR(_x,_x,1U);
}


#ifdef __cplusplus
}
#endif

#endif
