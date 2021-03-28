/*
 * Copyright (c) 2017-present, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== EventCombinerP_tirtos.c ========
 */
#ifdef _TMS320C6X
#include <ti/osal/osal.h>

#include <ti/osal/EventCombinerP.h>
#include <ti/csl/src/intc/csl_intcAux.h>
#include <ti/csl/src/intc/csl_intcAsmUtils.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ti/osal/src/nonos/Nonos_config.h>

#ifdef __cplusplus
extern "C" {
#endif

/* This is the number of c6x interrupts [0-15] */
#define OSAL_ECM_NUM_INTERRUPTS (16)
/**************************************************************
   Description: Returns the Hwi Handle associated with the event group.
                It returns NULL_PTR if the Event combiner is not registered
				with an  interrupt vector (0-15)  
   Argument:    The Event Combiner group Number [0-3]
   Returns:     The HwiHandle corresponding to the group number. 
                NULL_PTR if it doesnt registered yet.
*******************************************************************/
HwiP_Handle EventCombinerP_getHwi(uint32_t groupNum) {
    HwiP_Handle handle=NULL_PTR;
    int32_t event,i;

    for(i=0;i<OSAL_ECM_NUM_INTERRUPTS;i++) {
       /* Find out the event associated with the interrupt vector number */
       event=HwiP_getEventId(i);

       if((uint32_t)event==groupNum) {
           /* If the associated event is the ECM group (0-3),
            * find out the event associated with the interrupt vector number */
           handle=HwiP_getHandle(i);
           break;
       }
    }
    return(handle);
}
/**************************************************************
   Description: Returns the interrupt vector id  corresponding to a
                event combiner group number [0-3)   
   Argument:    The Event Combiner group Number [0-3]
   Returns:     The interrupt vector id corresponding to a groupNum. 
                -1 if the event combiner is not registered
*******************************************************************/
int32_t EventCombinerP_getIntNum(int32_t groupNum) {

    int32_t event,i,intNum=-1;

    for(i=0;i<OSAL_ECM_NUM_INTERRUPTS;i++) {
       /* Find out the event associated with the interrupt vector number */
       event=HwiP_getEventId(i);

       if(event==groupNum) {
           /* If the associated event is the ECM group (0-3),
            * find out the event associated with the interrupt vector number */
           intNum=i;
           break;
       }
    }

    return(intNum);
}

/**************************************************************
   Description: Register an event combiner interrupt

   Argument:    groupNum: The group number (0-3).
                intNum: The interrupt vector id to register 
				the event combiner to.
   Returns:     OSAL_EVTCOMBINE_GROUPREG_SUCCESS if allocated well.
                OSAL_EVTCOMBINE_ERR_GROUPREG_REGISTER_ERR if error.
*******************************************************************/

int32_t EventCombinerP_SingleRegisterInt(int32_t groupNum, int32_t intNum)
{
    /* There is nothing to be done here as the HwiP_create() already 
	   allocates it */
	return OSAL_EVTCOMBINE_GROUPREG_SUCCESS;
}

/**************************************************************
   Description: Register all the event combiner interrupts

   Argument: intNum[]: The interrupt vector ids to register 
			           the event combiner to. 

	Returns: OSAL_EVTCOMBINE_GROUPREG_SUCCESS 
*******************************************************************/
int32_t EventCombinerP_GroupRegisterInt(int32_t intNum[])
{
    /* There is nothing to be done here as the HwiP_create() already 
	   allocates it */
    return OSAL_EVTCOMBINE_GROUPREG_SUCCESS;
}
/**************************************************************************
   Description: Disable a particular event Number inside the Event Combiner

   Argument: eventNum: The event number(4-127) to disable inside 
             the event combiner

    Returns: OSAL_EVTCOMBINE_GROUPREG_SUCCESS 
****************************************************************************/
int32_t EventCombinerP_enableEvent(uint32_t eventNum)
{
	uint32_t mask,groupId;

    groupId = eventNum/32U;
	mask = (uint32_t)1U << (eventNum%32U);
    /* Get the current mask and clear the bit first */
    (void)CSL_intcCombinedEventEnable((CSL_IntcEventId)groupId, (CSL_BitMask32)mask);
    return OSAL_EVTCOMBINE_GROUPREG_SUCCESS;
}
/**************************************************************************
   Description: Enable a particular event Number inside the Event Combiner

   Argument: eventNum: The event number(4-127) to enable inside 
             the event combiner

    Returns: OSAL_EVTCOMBINE_GROUPREG_SUCCESS 
****************************************************************************/
int32_t EventCombinerP_disableEvent(uint32_t eventNum)
{
	uint32_t groupId,mask;
	
	groupId = eventNum/32U;
	mask = (uint32_t)1U << (eventNum%32U);
    
    (void)CSL_intcCombinedEventDisable((CSL_IntcEventId)groupId,(CSL_BitMask32)mask);
	return OSAL_EVTCOMBINE_GROUPREG_SUCCESS;
}
/**************************************************************************
    Description: Plugs a event's(4-127) to the EventCombiner's dispatcher

    Arguments: eventId: The event number(4-127) 
             eventIsrRoutine: The event's ISR routine
             unmask: TRUE/FALSE: Mask/Unmask the event combiner flag

    Returns: OSAL_EVTCOMBINE_GROUPREG_SUCCESS 
****************************************************************************/
int32_t EventCombinerP_dispatchPlug(uint32_t eventId, EventCombinerP_FuncPtr eventIsrRoutine,uintptr_t arg,bool unmask )
{
   CSL_IntcObj  intcObj;
   CSL_IntcHandle handleTemp=(CSL_IntcHandle)&intcObj;
   
   CSL_IntcEventHandlerRecord  evtHandler;

   CSL_dint();
   /* Plug the function in to the CSL_intcEventHandlerRecord_p */
   /* This is a temporary handle, so that CSL_intcPlugEventHandler() registers the
       actual eventId (>4). The real Handle for Event Combiner has handle->eventId <4.
	   But to register the ISR routine in the  dispatch table CSL_intcEventHandlerRecord_p,
	   we use this temporary handle (which has ->eventId= corepac eventId) so that 
	   the CSL_intcPlugEventHandler(handleTemp,..) registers it 
	*/
   handleTemp->eventId = (CSL_IntcEventId)eventId;
   evtHandler.handler = (CSL_IntcEventHandler)eventIsrRoutine;
   evtHandler.arg     = (void *)arg;
   (void)CSL_intcPlugEventHandler(handleTemp, &evtHandler);
   (void)EventCombinerP_disableEvent(eventId); /* Disable event by default */
   CSL_rint();
   
  /* Nothing to be done, as HwiP_Create() already takes care of this internally, via CSL_intcOpen() */
  return OSAL_EVTCOMBINE_GROUPREG_SUCCESS;
}

#ifdef __cplusplus
}
#endif

#endif /* #ifdef _TMS320C6X */
