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
#include "fsm_state_host.h"
#include "fsm_state_dev.h"
#include "fsm_state_a_idle.h"

#include "usb_ssp_drd_if.h"
#include "usb_ssp_drd_structs_if.h"

#include "usb_ssp_drd_hw.h"
#include "usb_ssp_drd_regs.h"

/* Interrupt handler for DRD controller running in the (A) Host mode. */
uint32_t interruptHostEvent(USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Check if interrupt callback is set. */
    if (NULL == privData->callbacks.interruptHost) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: interruptHost callback is not set\n", __func__);
        status = CDN_EPROTO;
    } else {
        /* Call interrupt callback. This callback is supposed to handle
           interrupt with appropriate driver. */
        status = privData->callbacks.interruptHost(privData);
        if (CDN_EOK != status) {
            DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: interruptHost callback failed\n", __func__);
        }
    }
    return status;
}

/* Function for transitioning from Host to DRD (A Idle state of DRD's
 * FSM). */
static uint32_t transitionFromHostToDrd (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Check if callback for disabling host is set. */
    if (NULL == privData->callbacks.disableHost) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: disableHost callback is not set\n", __func__);
        status = CDN_EPROTO;
    } else {
        /* Disable host by calling a callback. Callback should use a
           host driver. */
        status = privData->callbacks.disableHost(privData);
        if (CDN_EOK != status) {
            DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: disableHost callback failed\n", __func__);
        } else  {
            /* Transition to DRD's inital state (A Idle). */
            status = transitionToAIdle(privData);
            if (CDN_EOK != status) {
                DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
            }
        }
    }
    return status;
}

/* Function for transitioning from Host to Device. */
static uint32_t transitionFromHostToDev (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Check if callback for disabling host is set. */
    if (NULL == privData->callbacks.disableHost) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: disableHost callback is not set\n", __func__);
        status = CDN_EPROTO;
    } else {
        /* Disable host by calling a callback. Callback should use a
           host driver. */
        status = privData->callbacks.disableHost(privData);
        if (CDN_EOK != status) {
            DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: disableHost callback failed\n", __func__);
        } else  {
            /* Transition to device. */
            status = transitionToDev(privData);
            if (CDN_EOK != status) {
                DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
            }
        }
    }
    return status;
}

/* Function for transitioning to the Host state. */
uint32_t transitionToHost (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Check if supplied parameter is correct. */
    /* Set default event handlers. */
    setDefaultEvent(privData);
    /* Set only a subset of event handlers supported by the Host
       state. */
    privData->state.isr       = interruptHostEvent;
    privData->state.enableDrd = transitionFromHostToDrd;
    privData->state.enableDev = transitionFromHostToDev;
    /* Check if callback for enabling host is set. */
    if (NULL == privData->callbacks.enableHost) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: enableHost callback is not set\n", __func__);
        status = CDN_EPROTO;
    } else {
        /* Call callback for enabling host mode. Callback should use a
           host driver.*/
        status = privData->callbacks.enableHost(privData);
        if (CDN_EOK != status) {
            DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: enableHost callback failed\n", __func__);
        }
    }
    return status;
}
