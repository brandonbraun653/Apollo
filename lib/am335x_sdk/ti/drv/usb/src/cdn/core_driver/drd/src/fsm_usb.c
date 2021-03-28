/******************************************************************************
 *
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
 *
 ******************************************************************************/

#include <cdn_inttypes.h>
#include <cdn_log.h>

#include "fsm_usb.h"
#include "fsm_state_a_idle.h"
#include "fsm_state_host.h"
#include "fsm_state_dev.h"

#include "usb_ssp_drd_if.h"
#include "usb_ssp_drd_structs_if.h"
#include "usb_ssp_drd_hw.h"
#include "usb_ssp_drd_regs.h"

/* Interrupt service routine - default for each FSM state. */
static uint32_t defaultIsr (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    privData->defaultTransitionCalls += 1U;
    /* This function will not call a specific Interrupt Service
       Routine. Its purpose is to provide a side effect free function
       that could be called with no consequences. */
    return status;
}

/* Transition function for an event of ID pin level change to high and
   VBUS level change to low - default for each FSM state. */
static uint32_t defaultEventIdUpVBusDown (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    privData->defaultTransitionCalls += 1U;
    /* This function will not call a specific procedure that handles an
       event of ID pin level change to high and VBUS level change to
       low. Its purpose is to provide a side effect free function that
       could be called with no consequences. */
    return status;
}

/*  Transition function for an event of ID pin level change to high
    and VBUS level change to high - default for each FSM state. */
static uint32_t defaultEventIdUpVBusUp (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    privData->defaultTransitionCalls += 1U;
    /* This function will not call a specific procedure that handles an
       event of ID pin level change to high and VBUS level change to
       high. Its purpose is to provide a side effect free function that
       could be called with no consequences. */
    return status;
}

/* Transition function for an event of ID pin level change to low and
   VBUS level change to low - default for each FSM state. */
static uint32_t defaultEventIdDownVBusDown (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    privData->defaultTransitionCalls += 1U;
    /* This function will not call a specific procedure that handles an
       event of ID pin level change to low and VBUS level change to
       low. Its purpose is to provide a side effect free function that
       could be called with no consequences. */
    return status;
}

/*  Transition function for an event of ID pin level change to low
    and VBUS level change to high - default for each FSM state. */
static uint32_t defaultEventIdDownVBusUp (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    privData->defaultTransitionCalls += 1U;
    /* This function will not call a specific procedure that handles an
       event of ID pin level change to low and VBUS level change to
       high. Its purpose is to provide a side effect free function that
       could be called with no consequences. */
    return status;
}

/* Transition function for an event of forcing drd mode - default for
   each FSM state. */
static uint32_t defaultEventEnableDrd (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    privData->defaultTransitionCalls += 1U;
    /* This function will not call a specific procedure that handles an
       event of forcing drd mode. Its purpose is to provide a side
       effect free function that could be called with no
       consequences. */
    return status;
}

/* Transition function for an event of forcing host mode - default for
   each FSM state. */
static uint32_t defaultEventEnableHost (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    privData->defaultTransitionCalls += 1U;
    /* This function will not call a specific procedure that handles an
       event of forcing host mode. Its purpose is to provide a side
       effect free function that could be called with no
       consequences. */
    return status;
}

/* Transition function for an event of forcing device mode - default
   for each FSM state. */
static uint32_t defaultEventEnableDev (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    privData->defaultTransitionCalls += 1U;
    /* This function will not call a specific procedure that handles an
       event of forcing device mode. Its purpose is to provide a side
       effect free function that could be called with no
       consequences. */
    return status;
}

/**
 *  \brief Function checks if USBSSP DRD driver supports hardware.
 *
 *  The driver supports certain IP. Function compares an ID of
 *  hardware that the driver supports with an ID read from hardware.
 *
 *  \param regsBase base register address of an IP
 *  \return CDN_EOK driver supports the hardware
 *  \return CDN_EFAULT driver does not support the hardware
 *  \return CDN_EINVAL input parameters are not valid
 */
static uint32_t checkControllerID(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    uint32_t status = CDN_EOK;
    uint32_t didVal = 0U;
    uint32_t ridVal = 0U;
    /* Read DID and RID number from hardware. */
    didVal = readDID(regsBase);
    ridVal = readRID(regsBase);
    /* Compare RID and DID read form hardware against RID and DID
       number of supported IP. */
    if ((USB_SSP_DRD_DID_VALUE != didVal) ||
        (USB_SSP_DRD_RID_VALUE != ridVal)) {
        DbgMsg(DBG_GEN_MSG,
               DBG_CRIT,
               "ERROR %s: Controller ID read from register doesn't match an ID of controller supported by the driver.\n",
               __func__);
        status = CDN_EFAULT;
    } else {
        status = CDN_EOK;
    }
    return status;
}

/**
 *  \brief Function waits until controller is ready.
 *
 *  USBSSP DRD controller will toggle a specific bit in STATUS
 *  register after it becomes ready. Software should not read or write
 *  any registers, except STATUS, before controller becomes ready.
 *
 *  \param regsBase base register address of an IP

 *  \return CDN_EOK if controller becomes ready before timeout
 *  \return CDN_ETIMEDOUT if controller does not become ready before
 *  timeout
 */
static uint32_t waitForIpReady(USB_SspDrdRegs* regsBase)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    uint32_t status = CDN_EOK;
    bool isReady = false;
    uint64_t timePassed = 0U;
    /* Loop until controller becomes ready or certain time passes. */
    while ((false == isReady) && (USB_SSP_DRD_NRDY_TIMEOUT > timePassed)) {
        /* Read status of controller from hardware. */
        isReady = checkIfControllerIsReady(regsBase);
        timePassed++;
        DbgMsg(DBG_GEN_MSG,
               DBG_FYI,
               "%s: Waiting for controller to be ready. isReady: %d\n",
               isReady,
               __func__);
    }
    if (false == isReady) {
        /* Timed out. Will return an error. */
        status = CDN_ETIMEDOUT;
        DbgMsg(DBG_GEN_MSG,
               DBG_CRIT,
               "ERROR %s: Timed out waiting for DRD controller to become ready.\n",
               __func__);
    } else {
        /* Controller reported that it is ready. */
        status = CDN_EOK;
        DbgMsg(DBG_GEN_MSG,
               DBG_FYI,
               "%s: DRD controller is ready.\n",
               __func__);
    }
    return status;
}


/**
 *  \brief Function sets first transition based strap.
 *
 *  This function reads strap configuration. Depending on the strap a
 *  different driver will be started.
 *
 *  \param privData pointer to drivers private data
 *  \return CDN_EOK transition based on strap succeeded
 *  \return CDN_EFAULT strap mode is not supported
 *  \return other error code, transition failed
 */
static uint32_t setTransitionsBasedOnStrap(USB_SSP_DRD_PrivData* privData)
{
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    uint32_t status = CDN_EOK;
    USB_SSP_DRD_Mode strapMode = USB_SSP_DRD_DRD;

    /* Set default events for FSM. This will prevent from calling
     * incorrect transition function. */
    setDefaultEvent(privData);

    /* Read strap mode from hardware.  */
    strapMode = readStrapMode(privData->regsBase);

    /* Based on strap mode read from hardware process to corresponding
     * state. */
    switch (strapMode) {
    case USB_SSP_DRD_DRD: {
        /* Start DRD operation. */
        status = transitionToAIdle(privData);
        break;
    }
    case USB_SSP_DRD_HOST: {
        /* Start operating as host. */
        status = transitionToHost(privData);
        break;
    }
    case USB_SSP_DRD_DEV: {
        /* Start operating as device. */
        status = transitionToDev(privData);
        break;
    }
    default:
        /* Strap mode read from hardware is not supported. */
        status = CDN_EFAULT;
        break;
    }

    /* Log errors if any. */
    if (CDN_EOK != status) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }

    return status;
}

void setDefaultEvent (USB_SSP_DRD_PrivData* privData)
{
    /* This function will set every event handler of a state to
     * default value. */
    privData->state.isr            = defaultIsr;
    privData->state.idUpVBusDown   = defaultEventIdUpVBusDown;
    privData->state.idUpVBusUp     = defaultEventIdUpVBusUp;
    privData->state.idDownVBusDown = defaultEventIdDownVBusDown;
    privData->state.idDownVBusUp   = defaultEventIdDownVBusUp;
    privData->state.enableDrd      = defaultEventEnableDrd;
    privData->state.enableHost     = defaultEventEnableHost;
    privData->state.enableDev      = defaultEventEnableDev;
    /* This function does not trigger events. It does not return any values. */
}

uint32_t processIdVbus (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    uint32_t idVal = 0U;
    uint32_t vBus = 0U;

    /* Read ID, VBUS from hardware. */
    readIdVbus(privData->regsBase, &idVal, &vBus);

    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s, ID: %d, VBUS: %d\n", __func__, idVal, vBus);

    /* Trigger FSM events based on ID, VBUS. */
    if (1U == idVal) {
        if (1U == vBus) {
            /* ID high, VBUS high */
            status = privData->state.idUpVBusUp(privData);
        } else {
            /* ID high, VBUS low */
            status = privData->state.idUpVBusDown(privData);
        }
    } else {
        if (1U == vBus) {
            /* ID low, VBUS high */
            status = privData->state.idDownVBusUp(privData);
        } else {
            /* ID low, VBUS low */
            status = privData->state.idDownVBusDown(privData);
        }
    }

    /* Log errors if any. */
    if (CDN_EOK != status) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }

    return status;
}

uint32_t startFsm (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Make sure that DRD driver supports hardware that it is running
       on. */
    status = checkControllerID(privData->regsBase);
    if (CDN_EOK == status) {
        /* Wait until hardware reports that it is ready for
         * operation. */
        status = waitForIpReady(privData->regsBase);
        if (CDN_EOK == status) {
            /* Start DRD driver in a mode that corresponds to
             * controller strap configuration. */
            status = setTransitionsBasedOnStrap(privData);
            if (CDN_EOK == status) {
                DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s, Started FSM OK.\n", __func__);
                /* Enable interrupts. */
                enableAllInterrupts(privData->regsBase);
                /* Shorten timeouts for simulation. */
                enableFastSim(privData->regsBase);
                DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s, Enabled interrupts.\n", __func__);
                /* Process state of ID pin and VBUS. Because the USB
                 * plug could have been plugged before the DRD driver
                 * was started the state of ID pin and VBUS has to be
                 * polled. Further changes will be reported by
                 * hardware via interrupts. */
                status = processIdVbus(privData);
            }
        }
    }

    if (CDN_EOK != status) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }

    return status;
}
