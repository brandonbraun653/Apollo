#ifndef CSL_C7X_EVENTS_H_
#define CSL_C7X_EVENTS_H_

/**
 *     C7X Event Functions
 *  \par
 *   ================================================================================
 *
 *   @n   (C)  Copyright 2018 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *      Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *      Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the
 *      distribution.
 *
 *      Neither the name of Texas Instruments Incorporated nor the names of
 *      its contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
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



#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

    /**
     * @n@b CSL_c7x_EvtIntRegister
     *
     * @b Description
     * @n   Register an interrupt handler for a given event number
     *
     * @b Arguments
     * @n uint64_t   estp_addr     Base address of the interrupt vector table
     * @n uint64_t   evt_num       Event number (0-63) the handler is for
     * @n uint64_t   handler_addr  Address of handler to register
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Example
     * @verbatim
     *
     *   void handler0();               // handler to register
     *   uint64_t estp_s    = __ESTP_S; // Base address of Root Supervisor's vector table
     *   uint64_t event_num = 0;        // Event this handler is for
     *
     *   CSL_c7xEvtIntRegister( estp_s, event_num, &handler0 );
     */
    extern void CSL_c7xEvtIntRegister( uint64_t estp_addr,  uint64_t evt_num, uint64_t handler_addr );

    /**
     * @n@b CSL_c7x_EvtIntUnregister
     *
     * @b Description
     * @n   Unregister an interrupt handler for a given event number.
     * @n   Unregistered interrupts that occur will return.
     *
     * @b Arguments
     * @n uint64_t   estp_addr     Base address of the interrupt vector table
     * @n uint64_t   evt_num       Event number (0-63) the handler is for
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Example
     * @verbatim
     *
     *   uint64_t estp_s    = __ESTP_S; // Base address of Root Supervisor's vector table
     *   uint64_t event_num = 0;        // Event this handler is for
     *
     *   CSL_c7xEvtIntUnregister( estp_s, event_num );
     */
    extern void CSL_c7xEvtIntUnregister( uint64_t estp_addr, uint64_t evt_num );

    /**
     * @n@b CSL_c7x_EvtIntEnable
     *
     * @b Description
     * @n   Enables events to trigger interrupts by setting the GEE bit in the TSR
     *
     * @b Arguments
     * @n None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Example
     * @verbatim
     *
     *   CSL_c7xEvtIntEnable( );
     */
    extern void CSL_c7xEvtIntEnable( );

    /**
     * @n@b CSL_c7x_EvtIntDisable
     *
     * @b Description
     * @n   Disables events from triggering interrupts by resetting the GEE bit in the TSR
     *
     * @b Arguments
     * @n None
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Example
     * @verbatim
     *
     *   CSL_c7xEvtIntDisable( );
     */
    extern void CSL_c7xEvtIntDisable( );

    /**
     * @n@b CSL_c7x_EvtIntSystemEnable
     *
     * @b Description
     * @n   Enables a specific event to trigger interrupts by setting its bit in the EER register
     *
     * @b Arguments
     * @n uint64_t  evt_num    The event number (0-63) to allow interrupts for
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Example
     * @verbatim
     *
     *   uint64_t event_num = 0;  //We want to enable event 0
     *   CSL_c7xEvtIntSystemEnable( event_num );
     */
    extern void CSL_c7xIntSystemEnable( uint64_t evt_num );

    /**
     * @n@b CSL_c7x_EvtIntSystemDisable
     *
     * @b Description
     * @n   Disables a specific event to trigger interrupts by resetting its bit in the EER register
     *
     * @b Arguments
     * @n uint64_t  evt_num    The event number (0-63) to disable interrupts for
     *
     * <b> Return Value </b>
     * @n None
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Example
     * @verbatim
     *
     *   uint64_t event_num = 0;  //We want to disable event 0
     *   CSL_c7xEvtIntSystemDisable( event_num );
     */
    extern void CSL_c7xIntSystemDisable( uint64_t evt_num );

    /**
     * @n@b CSL_c7x_EvtIntPrioritySet
     *
     * @b Description
     * @n   Disables a specific event to trigger interrupts by resetting its bit in the EER register
     *
     * @b Arguments
     * @n uint64_t  evt_num    The event number (0-63) to disable interrupts for
     * @n uint64_t  new_pri    The new priority level (0-7) for the event
     *
     * <b> Return Value </b>
     * @n uint64_t             The previous priority level (0-7) of the event
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Example
     * @verbatim
     *
     *   uint64_t event_num     = 0;  //We want to change the priority of event 0
     *   uint64_t new_pri_level = 0;  //Set it to priority 0 (non-maskable)
     *
     *   uint64_t old_pri_level = CSL_c7xEvtIntPrioritySet( event_num, new_pri_level );
     */
    extern uint64_t CSL_c7xEvtIntPrioritySet( uint64_t evt_num, uint64_t new_pri );

#ifdef __cplusplus
}
#endif

#endif             /* end of CSL_C7XECR_H_ definition */
