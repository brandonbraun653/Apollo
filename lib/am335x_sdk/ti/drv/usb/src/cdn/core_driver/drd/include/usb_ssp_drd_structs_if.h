/* parasoft suppress item  MISRA2012-DIR-4_8 "Consider hiding implementation of structure, DRV-4932" */
/**********************************************************************
 * Copyright (C) 2012-2019 Cadence Design Systems, Inc.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************
 * WARNING: This file is auto-generated using api-generator utility.
 *          api-generator: 13.04.5beed88
 *          Do not edit it manually.
 **********************************************************************
 * Cadence Core Driver for USB SSP DRD
 **********************************************************************/
#ifndef USB_SSP_DRD_STRUCTS_IF_H
#define USB_SSP_DRD_STRUCTS_IF_H

#include "cdn_stdtypes.h"
#include "usb_ssp_drd_if.h"
#include "fsm_usb.h"

/** @defgroup DataStructure Dynamic Data Structures
 *  This section defines the data structures used by the driver to provide
 *  hardware information, modification and dynamic operation of the driver.
 *  These data structures are defined in the header file of the core driver
 *  and utilized by the API.
 *  @{
 */

/**********************************************************************
 * Structures and unions
 **********************************************************************/
/** Configuration parameters passed to init function. */
struct USB_SSP_DRD_Config_s
{
    /** Base address of the register space. */
    USB_SspDrdRegs* regsBase;
    /** USB Dev private data */
    CUSBD_PrivateData* cusbdPrivateData;
    /** USB Host private data */
    USBSSP_DriverResourcesT* xhciPrivateData;
};

/** Structure with callbacks to userspace. */
struct USB_SSP_DRD_Callbacks_s
{
    /** This function will be called when things are done. */
    USB_SSP_DRD_GenericCallback interruptDrd;
    /** This callback is for enabling HOST driver. */
    USB_SSP_DRD_GenericCallback enableHost;
    /** This callback is for enabling HOST driver in A_HOST state. */
    USB_SSP_DRD_GenericCallback enableAHost;
    /** This callback is for enabling DEV driver. */
    USB_SSP_DRD_GenericCallback enableDev;
    /** This callback is for enabling DEV driver in B_IDLE mode. */
    USB_SSP_DRD_GenericCallback enableBIdleDev;
    /** This callback is for enabling DEV driver in B_PERIPHERAL mode. */
    USB_SSP_DRD_GenericCallback enableBPeriDev;
    /** This callback is for handling HOST interrupt. */
    USB_SSP_DRD_GenericCallback interruptHost;
    /** This callback is for handling DEV interrupt. */
    USB_SSP_DRD_GenericCallback interruptDev;
    /** This callback is for disabling HOST driver. */
    USB_SSP_DRD_GenericCallback disableHost;
    /** This callback is for disabling DEV driver. */
    USB_SSP_DRD_GenericCallback disableDev;
};

/** This structure represents state of USBSSP DRD FSM. Each member corresponds to a event that can occur during FSM's operation. Upon entering the state, members of this structure are set based on events supported by this state.  */
struct USB_SSP_DRD_State_s
{
    /** Interrupt handler specific for current state. */
    USB_SSP_DRD_InterruptHandler isr;
    /** Transition function for an event of ID pin level change to high. */
    USB_SSP_DRD_EventIdUp idUp;
    /** Transition function for an event of ID pin level change to high and VBUS level change to low. */
    USB_SSP_DRD_EventIdUpVBusDown idUpVBusDown;
    /** Transition function for an event of ID pin level change to high and VBUS level change to high. */
    USB_SSP_DRD_EventIdUpVBusUp idUpVBusUp;
    /** Transition function for an event of ID pin level change to low and VBUS level change to low. */
    USB_SSP_DRD_EventIdDownVBusDown idDownVBusDown;
    /** Transition function for an event of ID pin level change to low and VBUS level change to high. */
    USB_SSP_DRD_EventIdDownVBusUp idDownVBusUp;
    /** Transition function for an event of forcing DRD mode. */
    USB_SSP_DRD_EventEnableDrd enableDrd;
    /** Transition function for an event of forcing host mode. */
    USB_SSP_DRD_EventEnableHost enableHost;
    /** Transition function for an event of forcing device mode. */
    USB_SSP_DRD_EventEnableDev enableDev;
};

/** Driver's Private Data. */
struct USB_SSP_DRD_PrivData_s
{
    /** Base address of the register space. */
    USB_SspDrdRegs* regsBase;
    /** Callback handlers. */
    USB_SSP_DRD_Callbacks callbacks;
    /** State of DRD FSM. */
    USB_SSP_DRD_State state;
    /** USB Dev private data */
    CUSBD_PrivateData* cusbdPrivateData;
    /** USB Host private data */
    USBSSP_DriverResourcesT* xhciPrivateData;
    /** Interrupt vector value of USB SSP DRD. */
    uint32_t interruptVect;
    /** Number of times the default transition of FSM was called. */
    uint32_t defaultTransitionCalls;
};

/** System requirements returned by probe. */
struct USB_SSP_DRD_SysReq_s
{
    /** Size of memory required for driver's private data. */
    uint32_t memReq;
};

/**
 *  @}
 */

#endif	/* USB_SSP_DRD_STRUCTS_IF_H */
