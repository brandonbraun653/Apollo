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
 ******************************************************************************
 * USB SSP Dual Role Device controller driver.
 *
 *****************************************************************************/

#include "usb_ssp_drd_regs.h"

#include "fsm_usb.h"
#include "fsm_state_a_idle.h"
#include "fsm_state_a_host.h"
#include "fsm_state_b_peripheral.h"
#include "fsm_state_b_idle.h"

#include "usb_ssp_drd_if.h"
#include "usb_ssp_drd_structs_if.h"
#include "usb_ssp_drd_sanity.h"
#include "usb_ssp_drd_hw.h"

#include <cdn_log.h>

uint32_t USB_SSP_DRD_Probe(USB_SSP_DRD_SysReq* sysReq)
{
    uint32_t status = CDN_EOK;       /* Holds error code. */

    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Call sanity function. */
    status = USB_SSP_DRD_ProbeSF(sysReq);
    /* Check status of sanity function call. */
    if (status != CDN_EOK) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: Invalid arguments.\n", __func__);
    } else {
        /* Retrieve size of USB SSP DRD private data. */
        sysReq->memReq = (uint32_t)(sizeof(USB_SSP_DRD_PrivData));
    }

    return status;
}

uint32_t USB_SSP_DRD_Init(USB_SSP_DRD_PrivData* privData,
                          const USB_SSP_DRD_Config* config,
                          const USB_SSP_DRD_Callbacks* callbacks)
{
    uint32_t status = CDN_EOK;       /* Holds error code. */

    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Call sanity function. */
    status = USB_SSP_DRD_InitSF(privData, config, callbacks);
    /* Check status of sanity function call. */
    if (status != CDN_EOK) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: Invalid arguments.\n", __func__);
    } else {
        /* Set DRD register base address. */
        privData->regsBase = config->regsBase;
        /* Assign host private data */
        privData->xhciPrivateData = config->xhciPrivateData;
        /* Assign device private data */
        privData->cusbdPrivateData = config->cusbdPrivateData;
        /* Assign callbacks. */
        privData->callbacks = *callbacks;
    }

    return status;
}

uint32_t USB_SSP_DRD_Isr(USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;        /* Holds error code. */

    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Call sanity function. */
    status = USB_SSP_DRD_IsrSF(privData);
    /* Check status of sanity function call. */
    if (status != CDN_EOK) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: Invalid arguments.\n", __func__);
    } else {
        /* Read value of DRD interrupt vector. */
        privData->interruptVect = readInterruptVector(privData->regsBase);
        /* Whatever the source of interrupt, clear DRD interrupts. */
        clearAllInterrupts(privData->regsBase);
        /* Check the source of interrupt. */
        if (0U == privData->interruptVect) {
            /* Interrupt source is either USBSSP controller (HOST or DEV). */
            status = privData->state.isr(privData);
            if (CDN_EOK != status) {
                DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: interrupt callback failed\n", __func__);
            }
        } /* else interrupt source is DRD, it will be processed in main thread. */
    }

    return status;
}

uint32_t USB_SSP_DRD_Start(USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;       /* Holds error code. */

    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Call sanity function. */
    status = USB_SSP_DRD_StartSF(privData);
    /* Check status of sanity function call. */
    if (status != CDN_EOK) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: Invalid arguments.\n", __func__);
    } else {
        /* Start FSM and underlying HW. */
        status = startFsm(privData);
    }

    return status;
}

uint32_t USB_SSP_DRD_Stop(const USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;       /* Holds error code. */

    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Call sanity function. */
    status = USB_SSP_DRD_StopSF(privData);
    /* Check status of sanity function call. */
    if (status != CDN_EOK) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: Invalid arguments.\n", __func__);
    }

    /* TODO: add implementation */

    return status;
}

uint32_t USB_SSP_DRD_Destroy(const USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;       /* Holds error code. */

    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Call sanity function. */
    status = USB_SSP_DRD_DestroySF(privData);
    /* Check status of sanity function call. */
    if (status != CDN_EOK) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: Invalid arguments.\n", __func__);
    }

    /* TODO: add implementation */

    return status;
}

uint32_t USB_SSP_DRD_CheckIfReady(USB_SSP_DRD_PrivData* privData, bool* isReady)
{
    uint32_t status = CDN_EOK;       /* Holds error code. */

    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Call sanity function. */
    status = USB_SSP_DRD_CheckIfReadySF(privData, isReady);
    /* Check status of sanity function call. */
    if (status != CDN_EOK) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: Invalid arguments.\n", __func__);
    } else {
        /* Check if controller is ready, read hardware. */
        *isReady = checkIfControllerIsReady(privData->regsBase);
    }

    return status;
}

uint32_t USB_SSP_DRD_CheckStrapMode(USB_SSP_DRD_PrivData* privData,
                                    USB_SSP_DRD_Mode* strapMode)
{
    uint32_t status = CDN_EOK;       /* Holds error code. */
    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Call sanity function. */
    status = USB_SSP_DRD_CheckStrapModeSF(privData, strapMode);
    /* Check status of sanity function call. */
    if (status != CDN_EOK) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: Invalid arguments.\n", __func__);
    } else {
        /* Read hardware to check strap mode. */
        *strapMode = readStrapMode(privData->regsBase);
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "Strap mode is: %d.\n", (uint8_t)*strapMode);
    }

    return status;
}

uint32_t USB_SSP_DRD_CheckOperationMode(const USB_SSP_DRD_PrivData* privData,
                                        USB_SSP_DRD_Mode* operationMode)
{
    uint32_t status = CDN_EOK;       /* Holds error code. */

    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Call sanity function. */
    status = USB_SSP_DRD_CheckOperationMoSF(privData, operationMode);
    /* Check status of sanity function call. */
    if (status != CDN_EOK) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: Invalid arguments.\n", __func__);
    } else {
        *operationMode = readDrdMode(privData->regsBase);
    }

    return status;
}

uint32_t USB_SSP_DRD_SetOperationMode(USB_SSP_DRD_PrivData* privData,
                                      const USB_SSP_DRD_Mode operationMode)
{
    uint32_t status = CDN_EOK;       /* Holds error code. */

    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Call sanity function. */
    status = USB_SSP_DRD_SetOperationModeSF(privData, operationMode);
    /* Check status of sanity function call. */
    if (status != CDN_EOK) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: Invalid arguments.\n", __func__);
    } else {
        if (USB_SSP_DRD_DRD == readStrapMode(privData->regsBase)) {

            /* Based on input parameter an operation mode will be set. */
            switch (operationMode) {
                /* DRD mode will be set. */
            case USB_SSP_DRD_DRD: {
                DbgMsg(DBG_GEN_MSG,
                       DBG_FYI,
                       "%s: Entering operation mode requested: %d\n",
                       operationMode,
                       __func__);
                status = privData->state.enableDrd(privData);
                break;
            }
                /* HOST mode will be set. */
            case USB_SSP_DRD_HOST: {
                DbgMsg(DBG_GEN_MSG,
                       DBG_FYI,
                       "%s: Entering operation mode requested: %d\n",
                       operationMode,
                       __func__);
                status = privData->state.enableHost(privData);
                break;
            }
                /* DEVICE mode will be set. */
            case USB_SSP_DRD_DEV: {
                DbgMsg(DBG_GEN_MSG,
                       DBG_FYI,
                       "%s: Entering operation mode requested: %d\n",
                       operationMode,
                       __func__);
                status = privData->state.enableDev(privData);
                break;
            }
                /* Additional safety if input parameter was invalid. */
            default: {
                DbgMsg(DBG_GEN_MSG,
                       DBG_CRIT,
                       "ERROR %s: Invalid operation mode requested: %d\n",
                       operationMode,
                       __func__);
                status = CDN_EINVAL;
                break;
            }
            }
        } else {
            DbgMsg(DBG_GEN_MSG,
                   DBG_CRIT,
                   "ERROR %s: can't change operation mode because of strap\n",
                   __func__);
            status = CDN_EPROTO;
        }
    }

    return status;
}

uint32_t USB_SSP_DRD_CheckIrq(const USB_SSP_DRD_PrivData* privData, uint32_t* interruptVect)
{
    uint32_t status = CDN_EOK;       /* Holds error code. */

    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Call sanity function. */
    status = USB_SSP_DRD_CheckIrqSF(privData, interruptVect);
    /* Check status of sanity function call. */
    if (status != CDN_EOK) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: Invalid arguments.\n", __func__);
    } else {
        /* Check if an interrupt is pending. */
        *interruptVect = privData->interruptVect;
    }

    return status;
}

uint32_t USB_SSP_DRD_ProcessIrq(USB_SSP_DRD_PrivData* privData)
{
    uint32_t status = CDN_EOK;       /* Holds error code. */

    DbgMsg(DBG_GEN_MSG, DBG_FYI, "%s\n", __func__);

    /* Call sanity function. */
    status = USB_SSP_DRD_ProcessIrqSF(privData);
    /* Check status of sanity function call. */
    if (status != CDN_EOK) {
        DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s: Invalid arguments.\n", __func__);
    } else {
        /* Clear copy of interrupt vector. */
        privData->interruptVect = 0U;
        /* Handle interrupt. */
        status = processIdVbus(privData);
        /* Check status of processing ID interrupt. */
        if (CDN_EOK != status) {
            DbgMsg(DBG_GEN_MSG, DBG_CRIT, "ERROR %s\n", __func__);
        }
    }

    return status;
}
