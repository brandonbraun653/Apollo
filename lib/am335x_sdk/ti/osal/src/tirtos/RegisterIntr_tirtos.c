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
 *  ======== RegisterIntr_tirtos.c ========
 */


#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include <ti/osal/osal.h>
#include <ti/osal/RegisterIntr.h>

#ifndef NULL_PTR
#define NULL_PTR  ((void *)0x0)
#endif

#if  defined(__ARM_ARCH_7A__)

#if defined(gnu_targets_arm_A15F) || defined(gnu_targets_arm_A9F)
#include <ti/sysbios/family/arm/gic/Hwi.h>
#elif defined(ti_targets_arm_elf_A8F) || \
      defined(ti_targets_arm_elf_A8Fnv) || \
      defined(gnu_targets_arm_A8F)
#include  <ti/sysbios/family/arm/a8/intcps/Hwi.h>
#endif

#elif defined(__aarch64__)
#include <ti/sysbios/family/arm/gicv3/Hwi.h>

#elif ((defined (SOC_OMAPL137) || defined (SOC_OMAPL138)) && (!defined(_TMS320C6X)))
    #include <ti/sysbios/family/arm/da830/Hwi.h>
#else
#ifdef _TMS320C6X
#include <ti/sysbios/family/c64p/Hwi.h>
#include <ti/sysbios/family/c64p/EventCombiner.h>
#else
#include <ti/sysbios/hal/Hwi.h>
#endif
#endif /* __ARM_ARCH_7A__ */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Purpose:     Initializes the interrupt registration config structure
 * Description: Initializes the interrupt registration config structure prior to
 *              invoking the Osal_registerIntr API
 */
void Osal_RegisterInterrupt_initParams(OsalRegisterIntrParams_t *interruptRegParams)
{
  if(interruptRegParams!=NULL_PTR) {
      /* Corepac config */
      interruptRegParams->corepacConfig.name=(char *) NULL_PTR;
      interruptRegParams->corepacConfig.corepacEventNum=-1;
      interruptRegParams->corepacConfig.intVecNum=-1;
      interruptRegParams->corepacConfig.isrRoutine=(Osal_IsrRoutine) NULL_PTR;
      interruptRegParams->corepacConfig.arg=(uintptr_t)NULL_PTR;

#ifdef __TI_ARM_V7R4__
      interruptRegParams->corepacConfig.priority=0x15U; /* Default */
#else
#if defined(__C7100__) || defined(BUILD_DSP_1) || defined(BUILD_DSP_2)
      interruptRegParams->corepacConfig.priority=0x01U; /* Default */
#else
      interruptRegParams->corepacConfig.priority=0x20U; /* Default */
#endif
#endif

#if defined (__ARM_ARCH_7A__)
      interruptRegParams->corepacConfig.triggerSensitivity = 0x3; /* interrupt edge triggered */
#endif

#if defined(__aarch64__) || defined (__TI_ARM_V7R4__)
      interruptRegParams->corepacConfig.triggerSensitivity = (uint32_t)OSAL_ARM_GIC_TRIG_TYPE_LEVEL; /* interrupt level triggered */
#endif

      /* SOC Mux Config */
      interruptRegParams->socMuxConfig.muxInParams=(MuxIntcP_inParams *) NULL_PTR;
      interruptRegParams->socMuxConfig.muxOutParams=(MuxIntcP_outParams *) NULL_PTR;
  }
  return;
}
/*
 * Purpose:     Registers the interrupt for the event with the params provided
 * Description: Registers the event with the event combiner/Interrupt Vector.
 *
 * Returns:     The Hwi Handle and the return codes defined in OsalInterruptRetCode_e
 */
OsalInterruptRetCode_e Osal_RegisterInterrupt(OsalRegisterIntrParams_t *interruptRegParams,HwiP_Handle *hwiPHandlePtr)
{

    OsalInterruptRetCode_e     ret=OSAL_INT_SUCCESS;
    HwiP_Handle                hwiPHandle=NULL_PTR;
    HwiP_Params                hwiInputParams;

     /* Program the corepac interrupt */
      if( (interruptRegParams->corepacConfig.isrRoutine == (Osal_IsrRoutine) NULL_PTR) ||
          (interruptRegParams->corepacConfig.corepacEventNum<0)) {
          ret=OSAL_INT_ERR_INVALID_PARAMS;
      }

      HwiP_Params_init(&hwiInputParams);

      hwiInputParams.name = interruptRegParams->corepacConfig.name;
      hwiInputParams.arg  = (uintptr_t)interruptRegParams->corepacConfig.arg;
      hwiInputParams.priority = interruptRegParams->corepacConfig.priority;
      hwiInputParams.evtId = (uint32_t)interruptRegParams->corepacConfig.corepacEventNum;

#if defined (__ARM_ARCH_7A__) || defined(__aarch64__) || defined (__TI_ARM_V7R4__)
      hwiInputParams.triggerSensitivity = interruptRegParams->corepacConfig.triggerSensitivity;
#endif

#ifdef _TMS320C6X
/*       For C66x
            Use Event Combiner ALWAYS for c6x. Event_combiner_event (0-3) =  core_event_in/32.
            Hook the this Event_combiner_event(0-3) to the core_intVecNum.
            if core_intVecNum is set to -1 as input, it means Let RM find a free unused vector number;
            HwiP_Create(Event_combiner_event,core_intVecNum,Event_dispatcher_plug);
*/
   if(interruptRegParams->corepacConfig.intVecNum == OSAL_REGINT_INTVEC_EVENT_COMBINER) {
      (void)EventCombinerP_dispatchPlug((uint32_t)interruptRegParams->corepacConfig.corepacEventNum,
                                  interruptRegParams->corepacConfig.isrRoutine,
                                  interruptRegParams->corepacConfig.arg,(bool)TRUE);

      (void)EventCombinerP_enableEvent((uint32_t)interruptRegParams->corepacConfig.corepacEventNum);

      /* Map to a particular group */
      if(hwiInputParams.evtId > 3U) {
          /* For C66X the interrupt needs to be grouped to {0,1,2,3} to either of the four 32-bit event registers  */
        hwiInputParams.evtId= ((uint32_t)interruptRegParams->corepacConfig.corepacEventNum/32U);
       }

      /* The dispatch function in the event combiner case is EventCombiner_dispatch */

       /* Find out if the event combiner is already registered, if so, dont re-register */
       hwiPHandle = EventCombinerP_getHwi(hwiInputParams.evtId);

       if(hwiPHandle==NULL_PTR) {
           /* The event hasn't been registered yet. Register it as per the defaults provided by OSAL */
           int32_t eveCombiner_ret;
           Osal_HwAttrs hwAttrs;

           /* Get the default OSAL mapped default interrupt numbers */
           (void)Osal_getHwAttrs(&hwAttrs);

           /* Register the current event> Here we chose to register all ECM interrupts  */
           eveCombiner_ret=EventCombinerP_GroupRegisterInt(hwAttrs.ECM_intNum);

               /* Register the current event */
           if(eveCombiner_ret==OSAL_EVTCOMBINE_GROUPREG_SUCCESS) {
              hwiPHandle = EventCombinerP_getHwi(hwiInputParams.evtId);
           } else {
              hwiPHandle=NULL_PTR;
              ret=OSAL_INT_ERR_EVENTCOMBINER_REG;
           }
       }
   } else {
       /* Do not use the event combiner. Use the supplied ISR routine */
       hwiPHandle =  HwiP_create(interruptRegParams->corepacConfig.intVecNum,interruptRegParams->corepacConfig.isrRoutine, &hwiInputParams);
       if(hwiPHandle ==NULL_PTR) {
          ret=OSAL_INT_ERR_HWICREATE;
       }
   }
#else
   hwiPHandle =  HwiP_create(interruptRegParams->corepacConfig.intVecNum,interruptRegParams->corepacConfig.isrRoutine, &hwiInputParams);
   if(hwiPHandle ==NULL_PTR) {
       ret=OSAL_INT_ERR_HWICREATE;
   }
#endif

 *hwiPHandlePtr=hwiPHandle;
  return ret ;
}
/*
 * Purpose:     Deletes/Unregisters an interrupt
 * Description: Deletes/Unregisters an interrupt associated with an event number(0-127).
 *
 * Returns:     OSAL_INT_SUCCESS if successful,OSAL_INT_ERR_DELETE if failed
 */
OsalInterruptRetCode_e Osal_DeleteInterrupt(HwiP_Handle handle,int32_t corepacEventNum)
{

    OsalInterruptRetCode_e ret=OSAL_INT_SUCCESS;
#ifdef _TMS320C6X
   /* For C66x, it needs to be found out if this is derived out of
    * an event combiner. If so, do not delete the HWI. Just unregister from the event combiner & disable the event.
    */
    {
       void (*isrFunction)(uintptr_t);
       uintptr_t isrArg;
       isrFunction=Hwi_getFunc((Hwi_Object *)handle,&isrArg);
       if(isrFunction==&EventCombiner_dispatch) {
           /* This is event combiner, so do not destroy the hwi, but remove the dispatch table entry */
           (void)EventCombinerP_dispatchPlug((uint32_t)corepacEventNum,(EventCombinerP_FuncPtr) NULL_PTR,0,(bool)FALSE);

           /* Disable the event so that the interrupt is masked and NULL_PTR function is not called */
           (void)EventCombinerP_disableEvent((uint32_t)corepacEventNum);
           /* Return Success */
       } else {
          /* This is not an event dispatcher function, so destruct the HwiP as usual */
           (void)HwiP_delete(handle);
       }

    }
#else
    /* For non-c66x cases, just delete the handle */
    (void)HwiP_delete(handle);
#endif
    return(ret);
}



/*
 * Purpose:     Enables an event/interrupt
 * Description: Enables the interrupt associated with an event number(0-127).
 *              In case of the event combiner, the corresponding event is
 *              enabled within the Event Combiner.
 *
 * Returns:     None
 */
void Osal_EnableInterrupt(int32_t corepacEvent,int32_t interruptNum)
{
#ifdef _TMS320C6X
    if(interruptNum==OSAL_REGINT_INTVEC_EVENT_COMBINER) {
     /* If this is called from a module which uses event combiner */
     /* Just enable the event inside the event combiner and
      * not the whole interrupt as it will be used by the event dispatcher */
        (void)EventCombinerP_enableEvent((uint32_t)corepacEvent);
    } else {
      /* This is not an event combiner based interrupt */
        HwiP_enableInterrupt(interruptNum);
    }
#else
    /* For non c66x cases, there is no event combiner , just invoke the HwiP */
    HwiP_enableInterrupt(interruptNum);
#endif
}

/*
 * Purpose:     Disables an event/interrupt
 * Description: Disables the interrupt associated with an event number(0-127).
 *              In case of the event combiner, the corresponding event is
 *              disabled within the Event Combiner.
 *
 * Returns:     None
 */
void Osal_DisableInterrupt(int32_t corepacEvent,int32_t interruptNum)
{
#ifdef _TMS320C6X
    if(interruptNum==OSAL_REGINT_INTVEC_EVENT_COMBINER) {
     /* If this is called from a module which uses event combiner */
     /* Just enable the event inside the event combiner and
      * not the whole interrupt as it will be used by the event dispatcher */
        (void)EventCombinerP_disableEvent((uint32_t)corepacEvent);
    } else {
      /* This is not an event combiner based interrupt */
        HwiP_disableInterrupt(interruptNum);
    }
#else
    /* For non c66x cases, there is no event combiner , just invoke the HwiP */
    HwiP_disableInterrupt(interruptNum);
#endif
}

/*
 * Purpose:     Clears a pending interrupt
 * Description: Clears a pending interrupt associated with an event number(0-127).
 *
 * Returns:     None
 */
void Osal_ClearInterrupt(int32_t corepacEvent,int32_t interruptNum)
{
    int32_t intNum=interruptNum;
#ifdef _TMS320C6X
    if(interruptNum==OSAL_REGINT_INTVEC_EVENT_COMBINER) {
        int32_t groupNum=(corepacEvent/32);
     /* If this is called from a module which uses event combiner,
      * get the corresponding interrupt number for that particular event
      * before proceeding to clear it */
        intNum=EventCombinerP_getIntNum(groupNum);
     }
     /* Clear the interrupt */
     HwiP_clearInterrupt(intNum);

#else
    /* For non c66x cases, there is no event combiner , just clear the interruptNum's vector */
    HwiP_clearInterrupt(intNum);
#endif
}

#ifdef __cplusplus
}
#endif
