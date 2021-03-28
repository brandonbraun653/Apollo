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
#include "fsm_state_a_host.h"
#include "fsm_state_b_idle.h"
#include "fsm_state_b_peripheral.h"

#include "usb_ssp_drd_if.h"
#include "usb_ssp_drd_structs_if.h"

/* Function for transitioning from B Idle to Host state. */
static uint32_t transitionFromBIdleToHost (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Call function that transitions to Host state. */
    status = transitionToHost(privData);
    if (CDN_EOK != status) {
        /* Check if Host state was enabled. */
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }
    return status;
}

/* Function for transitioning from B Idle to Device state. */
static uint32_t transitionFromBIdleToDev (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Call function that transitions to Device state. */
    status = transitionToDev(privData);
    if (CDN_EOK != status) {
        /* Check if Device state was enabled. */
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }
    return status;
}

/* Function for transitioning from B Idle to A Idle state. */
static uint32_t transitionFromBIdleToAIdle (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Call function that transitions to A Host state. */
    status = transitionToAIdle(privData);
    if (CDN_EOK != status) {
        /* Check if A Idle state was enabled. */
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }
    return status;
}

/* Function for transitioning from B Idle to A Host state. */
static uint32_t transitionFromBIdleToAHost (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Call function that transitions to A Host state. */
    status = transitionToAHost(privData);
    if (CDN_EOK != status) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }
    return status;
}

/* Function for transitioning from B Idle to B Peripheral state. */
static uint32_t transitionFromBIdleToBPeriphera (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Call function that transitions to B Peripheral state. */
    status = transitionToBPeripheral(privData);
    if (CDN_EOK != status) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }
    return status;
}

/* Funtction for transitioning to the B Idle state. */
uint32_t transitionToBIdle (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Set default event handlers. */
    setDefaultEvent(privData);
    /* Set only a subset of event handlers supported by the B Idle
       state. */
    privData->state.enableHost     = transitionFromBIdleToHost;
    privData->state.enableDev      = transitionFromBIdleToDev;
    privData->state.idDownVBusDown = transitionFromBIdleToAIdle;
    privData->state.idDownVBusUp   = transitionFromBIdleToAHost;
    privData->state.idUpVBusUp     = transitionFromBIdleToBPeriphera;
    /* Check if callback for enabling device in B Idle mode. */
    if (NULL == privData->callbacks.enableBIdleDev) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: enableBIdleDev callback is not set\n", __func__);
        status = CDN_EPROTO;
    } else {
        /* Call callback for enabling device in B Idle mode. Callback
           should use device driver. */
        status = privData->callbacks.enableBIdleDev(privData);
        if (CDN_EOK != status) {
            DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: enableBIdleDev callback failed\n", __func__);
        }
    }
    return status;
}
