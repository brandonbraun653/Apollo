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
#include "fsm_state_a_host.h"
#include "fsm_state_dev.h"
#include "fsm_state_b_idle.h"
#include "fsm_state_b_peripheral.h"

#include "usb_ssp_drd_hw.h"
#include "usb_ssp_drd_regs.h"

#include <cdn_errno.h>
#include <cdn_inttypes.h>

#include "usb_ssp_drd_if.h"
#include "usb_ssp_drd_structs_if.h"

/* Function for transitioning from AIdle to Host. */
static uint32_t transitionFromAIdleToHost (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Transition to Host. */
    status = transitionToHost(privData);
    if (CDN_EOK != status) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }
    return status;
}

/* Function for transitioning from AIdle to Dev. */
static uint32_t transitionFromAIdleToDev (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Transition to Device. */
    status = transitionToDev(privData);
    if (CDN_EOK != status) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }
    return status;
}

/* Function for transitioning from AIdle to A Host. */
static uint32_t transitionFromAIdleToAHost (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Transition to A Host. */
    status = transitionToAHost(privData);
    if (CDN_EOK != status) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }
    return status;
}

/* Function for transitioning from AIdle to B Peripheral. */
static uint32_t transitionFromAIdleToBPerip (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Transition to B Peripheral. */
    status = transitionToBPeripheral(privData);
    if (CDN_EOK != status) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }
    return status;
}

/* Function for transitioning from AIdle to B Idle. */
static uint32_t transitionFromAIdleToBIdle (USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Transition to B Idle. */
    status = transitionToBIdle(privData);
    if (CDN_EOK != status) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }
    return status;
}

/* Function for transitioning to the AIdle state. */
uint32_t transitionToAIdle(USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);
    /* Set default event handlers. */
    setDefaultEvent(privData);
    /* Set only a subset of event handlers supported by the AIdle
       state. */
    privData->state.enableHost   = transitionFromAIdleToHost;
    privData->state.enableDev    = transitionFromAIdleToDev;
    privData->state.idDownVBusUp = transitionFromAIdleToAHost;
    privData->state.idUpVBusDown = transitionFromAIdleToBIdle;
    privData->state.idUpVBusUp   = transitionFromAIdleToBPerip;
    /* Enable pullup of ID pin line. */
    status = enableIdPullup(privData->regsBase);
    if (CDN_EOK != status) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
    }
    return status;
}
