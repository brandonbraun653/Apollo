/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2017
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

/**
 * \file pmhal_pmmc.c
 *
 * \brief   CM3 PMMC interface API definition.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "pm_types.h"

#include "pmhal_pmmc.h"
#include "pmhal_pmmc_includes.h"
#include "pmhal_msgmgr.h"
#include "pmhal_ti_sci.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* PSC Module state enabled */
#define PSC_MODULE_STATE_EN         (0x3)

#if defined (__ARM_ARCH_7A__)
/********* ARM PMMC Definitions *********/
#define PMMC_LOCAL_HOST_ID          (TI_SCI_MSG_HOST_A15)

#elif defined (_TMS320C6X)
/********* DSP PMMC Definitions *********/
#define PMMC_LOCAL_HOST_ID          (TI_SCI_MSG_HOST_DSP)

#else
#error "PMMC not valid for processor"
#endif

/**
 *  \brief Macro for populating the TI_SCI message header
 */
#define BUILD_SCI_HDR(header, t, h, s, f) \
    header.type   = t; \
    header.host   = h; \
    header.seq    = s; \
    header.flags |= f; \

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief Function performs the PMMC TX/RX transaction
 *
 * \param   regData    Pointer to PMMC request message
 * \param   reqSize    Size in bytes of the request message
 * \param   respData   Pointer to PMMC response message
 * \param   respSize   Size in bytes of the response message
 * \param   type       PMMC message type
 * \param   flags      PMMC message flags
 * \param   timeout    Time to wait for response from PMMC
 *
 * \return  status     PM_SUCCESS Transaction was successfull
 *                     PM_FAIL    Transaction was not successfull
 */
static pmErrCode_t PmhalPmmcTransaction(uint32_t *reqData, uint32_t reqSize,
                                        uint32_t *respData, uint32_t respSize,
                                        uint16_t type, uint32_t flags,
                                        uint32_t timeout);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/**
 *  \brief Semaphore used for atomic read/write operations over MSGMGR
 */
SemaphoreP_Handle sem = NULL;

/**
 *  \brief PMIC messages sequence number counter
 */
uint8_t seq = 0;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

pmErrCode_t PMHALPmmcLoad(const void *image, uint32_t size)
{
    pmErrCode_t status = PM_SUCCESS;

    if (size > CSL_PMMC_0_CFG_REGS_SIZE)
    {
        status = PM_INVALID_FIRMWARE_IMAGE;
    }
    else
    {
        /* Load PMMC SW into CM3 address space */
        memcpy((void *)(CSL_PMMC_0_CFG_REGS), image, size);
    }

    return status;
}

pmErrCode_t PMHALPmmcStart(uint32_t timeout)
{
    pmErrCode_t status = PM_SUCCESS;
    uint32_t    ltimeout = timeout;

    /* Disable PMMC module */
    if (CSL_PSC_getModuleNextState(CSL_PSC_LPSC_PMMC) != PSC_MODSTATE_DISABLE)
    {
        CSL_PSC_setModuleLocalReset(CSL_PSC_LPSC_PMMC, PSC_MDLRST_ASSERTED);
        CSL_PSC_setModuleNextState(CSL_PSC_LPSC_PMMC,
                                   PSC_MODSTATE_SWRSTDISABLE);
        CSL_PSC_startStateTransition(CSL_PSC_PD_ALWAYSON);
    }

    while (ltimeout)
    {
        if (CSL_PSC_isStateTransitionDone(CSL_PSC_PD_ALWAYSON))
        {
            ltimeout = timeout;
            break;
        }

        if (!(--ltimeout))
        {
            status = PM_INVALID_FIRMWARE_START_TIMEOUT;
        }
    }

    /* Release PMMC from reset */
    if (status == PM_SUCCESS)
    {
        if (CSL_PSC_getModuleLocalReset(CSL_PSC_LPSC_PMMC) !=
            PSC_MDLRST_DEASSERTED)
        {
            CSL_PSC_setModuleLocalReset(CSL_PSC_LPSC_PMMC,
                                        PSC_MDLRST_DEASSERTED);
        }

        while (ltimeout)
        {
            if ((!(CSL_PSC_getModuleState(CSL_PSC_LPSC_PMMC) &
                   PSC_MODULE_STATE_EN)) &&
                (CSL_PSC_isModuleResetDone(CSL_PSC_LPSC_PMMC) == TRUE) &&
                (CSL_PSC_isModuleLocalResetDone(CSL_PSC_LPSC_PMMC) == TRUE))
            {
                ltimeout = timeout;
                break;
            }

            if (!(--ltimeout))
            {
                status = PM_INVALID_FIRMWARE_START_TIMEOUT;
            }
        }
    }

    /* Enable PMMC module */
    if (status == PM_SUCCESS)
    {
        if (CSL_PSC_getModuleNextState(CSL_PSC_LPSC_PMMC) !=
            PSC_MODSTATE_ENABLE)
        {
            CSL_PSC_setModuleNextState(CSL_PSC_LPSC_PMMC, PSC_MODSTATE_ENABLE);
            CSL_PSC_startStateTransition(CSL_PSC_PD_ALWAYSON);
        }

        while (ltimeout)
        {
            if (CSL_PSC_isStateTransitionDone(CSL_PSC_PD_ALWAYSON))
            {
                break;
            }

            if (!(--ltimeout))
            {
                status = PM_INVALID_FIRMWARE_START_TIMEOUT;
            }
        }
    }

    return status;
}

pmErrCode_t PMHALPmmcInterfaceInit(void)
{
    pmErrCode_t status = PM_SUCCESS;
    SemaphoreP_Params params;

    SemaphoreP_Params_init(&params);
    params.mode = SemaphoreP_Mode_COUNTING;

    /* Create semaphore to prevent simultaneous read/write to proxy */
    sem = SemaphoreP_create(1, &params);
    if (sem == NULL)
    {
        status = PM_FAIL;
    }

    return status;
}

pmErrCode_t PMHALPmmcInterfaceClose(void)
{
    pmErrCode_t status = PM_SUCCESS;

    if (sem)
    {
        if (SemaphoreP_delete(sem) != SemaphoreP_OK)
        {
            status = PM_FAIL;
        }
    }

    return status;
}

pmErrCode_t PMHALPmmcCommsValidate(uint32_t timeout)
{
    pmErrCode_t                    status = PM_SUCCESS;
    struct ti_sci_msg_hdr          revRequest;
    struct ti_sci_msg_resp_version revResponse;

    memset(&revRequest, 0, sizeof(revRequest));
    memset(&revResponse, 0, sizeof(revResponse));

    status = PmhalPmmcTransaction((uint32_t *)&revRequest,
                                  sizeof(revRequest),
                                  (uint32_t *)&revResponse,
                                  sizeof(revResponse),
                                  TI_SCI_MSG_VERSION,
                                  TI_SCI_FLAG_RESP_GENERIC_ACK,
                                  timeout);

    return status;
}

pmErrCode_t PMHALPmmcModuleSetState(pmhalPmmcModuleId_t moduleId,
                                    uint32_t state,
                                    uint32_t timeout)
{
    pmErrCode_t                            status = PM_SUCCESS;
    struct ti_sci_msg_req_set_device_state setRequest;
    struct ti_sci_msg_hdr                  setResponse;

    memset(&setRequest, 0, sizeof(setRequest));
    memset(&setResponse, 0, sizeof(setResponse));

    /* Fill in non-header fields */
    setRequest.id = moduleId;
    setRequest.state = state;

    status = PmhalPmmcTransaction((uint32_t *)&setRequest,
                                  sizeof(setRequest),
                                  (uint32_t *)&setResponse,
                                  sizeof(setResponse),
                                  TI_SCI_MSG_SET_DEVICE_STATE,
                                  TI_SCI_FLAG_RESP_GENERIC_ACK,
                                  timeout);

    return status;
}

pmErrCode_t PMHALPmmcModuleGetState(pmhalPmmcModuleId_t moduleId,
                                    pmhalPmmcModuleState_t *moduleState,
                                    uint32_t timeout)
{
    pmErrCode_t                             status = PM_SUCCESS;
    struct ti_sci_msg_req_get_device_state  getRequest;
    struct ti_sci_msg_resp_get_device_state getResponse;

    if (moduleState == NULL)
    {
        status = PM_BADARGS;
    }

    if (status == PM_SUCCESS)
    {
        memset(&getRequest, 0, sizeof(getRequest));
        memset(&getResponse, 0, sizeof(getResponse));

        /* Fill in non-header fields */
        getRequest.id = moduleId;

        status = PmhalPmmcTransaction((uint32_t *)&getRequest,
                                      sizeof(getRequest),
                                      (uint32_t *)&getResponse,
                                      sizeof(getResponse),
                                      TI_SCI_MSG_GET_DEVICE_STATE,
                                      TI_SCI_FLAG_RESP_GENERIC_ACK,
                                      timeout);

        if (status == PM_SUCCESS)
        {
            moduleState->contextLossCount = getResponse.context_loss_count;
            moduleState->resets = getResponse.resets;
            moduleState->programmedState = getResponse.programmed_state;
            moduleState->currentState = getResponse.current_state;
        }
    }

    return status;
}

pmErrCode_t PMHALPmmcClockSetState(pmhalPmmcModuleId_t moduleId,
                                   pmhalPmmcClockId_t clockId,
                                   uint32_t flags,
                                   uint32_t reqState,
                                   uint32_t timeout)
{
    pmErrCode_t                            status = PM_SUCCESS;
    struct ti_sci_msg_req_set_clock_state  setRequest;
    struct ti_sci_msg_hdr                  setResponse;

    memset(&setRequest, 0, sizeof(setRequest));
    memset(&setResponse, 0, sizeof(setResponse));

    /* Fill in header flags */
    setRequest.hdr.flags = flags;

    /* Fill in non-header fields */
    setRequest.dev_id = moduleId;
    setRequest.clk_id = clockId;
    setRequest.request_state = reqState;

    status = PmhalPmmcTransaction((uint32_t *)&setRequest,
                                  sizeof(setRequest),
                                  (uint32_t *)&setResponse,
                                  sizeof(setResponse),
                                  TI_SCI_MSG_SET_CLOCK_STATE,
                                  TI_SCI_FLAG_RESP_GENERIC_ACK,
                                  timeout);

    return status;
}

pmErrCode_t PMHALPmmcClockGetState(pmhalPmmcModuleId_t moduleId,
                                   pmhalPmmcClockId_t clockId,
                                   pmhalPmmcClockState_t *clockState,
                                   uint32_t timeout)
{
    pmErrCode_t                            status = PM_SUCCESS;
    struct ti_sci_msg_req_get_clock_state  getRequest;
    struct ti_sci_msg_resp_get_clock_state getResponse;

    if (clockState == NULL)
    {
        status = PM_BADARGS;
    }

    if (status == PM_SUCCESS)
    {
        memset(&getRequest, 0, sizeof(getRequest));
        memset(&getResponse, 0, sizeof(getResponse));

        /* Fill in non-header fields */
        getRequest.dev_id = moduleId;
        getRequest.clk_id = clockId;

        status = PmhalPmmcTransaction((uint32_t *)&getRequest,
                                      sizeof(getRequest),
                                      (uint32_t *)&getResponse,
                                      sizeof(getResponse),
                                      TI_SCI_MSG_GET_CLOCK_STATE,
                                      TI_SCI_FLAG_RESP_GENERIC_ACK,
                                      timeout);

        if (status == PM_SUCCESS)
        {
            clockState->programmedState = getResponse.programmed_state;
            clockState->currentState = getResponse.current_state;
        }
    }

    return status;
}

pmErrCode_t PMHALPmmcClockSetRate(pmhalPmmcModuleId_t moduleId,
                                  pmhalPmmcClockId_t clockId,
                                  uint32_t clockRate)
{
    pmErrCode_t                             status = PM_SUCCESS;
    struct ti_sci_msg_req_set_clock_freq    setRequest;
    struct ti_sci_msg_hdr                   setResponse;

    memset(&setRequest, 0, sizeof(setRequest));
    memset(&setResponse, 0, sizeof(setResponse));

    /* Fill in non-header fields */
    setRequest.dev_id = moduleId;
    setRequest.clk_id = clockId;
    /* Eventually PMHAL API should be moved to 64-bit clockRate.  32-bit
     * casted to 64-bit is fine for now since 32-bit equals ~4GHz which is
     * way over the max allowed frequency for current devices.  Also, add
     * +/-1000Hz to account for min/max frequency inputs to PMMC */
    setRequest.min_freq_hz = (uint64_t) (clockRate - 1000);
    setRequest.target_freq_hz = (uint64_t) clockRate;
    setRequest.max_freq_hz = (uint64_t) (clockRate + 1000);

    status = PmhalPmmcTransaction((uint32_t *)&setRequest,
                                  sizeof(setRequest),
                                  (uint32_t *)&setResponse,
                                  sizeof(setResponse),
                                  TI_SCI_MSG_SET_CLOCK_FREQ,
                                  TI_SCI_FLAG_RESP_GENERIC_ACK,
                                  PMHAL_PMMC_TIMEOUT_DEFAULT);

    return status;
}

pmErrCode_t PMHALPmmcClockGetRate(pmhalPmmcModuleId_t moduleId,
                                  pmhalPmmcClockId_t clockId,
                                  uint32_t *clockRate)
{
    pmErrCode_t                             status = PM_SUCCESS;
    struct ti_sci_msg_req_get_clock_freq    getRequest;
    struct ti_sci_msg_resp_get_clock_freq   getResponse;

    if (clockRate == NULL)
    {
        status = PM_BADARGS;
    }

    if (status == PM_SUCCESS)
    {
        memset(&getRequest, 0, sizeof(getRequest));
        memset(&getResponse, 0, sizeof(getResponse));

        /* Fill in non-header fields */
        getRequest.dev_id = moduleId;
        getRequest.clk_id = clockId;

        status = PmhalPmmcTransaction((uint32_t *)&getRequest,
                                      sizeof(getRequest),
                                      (uint32_t *)&getResponse,
                                      sizeof(getResponse),
                                      TI_SCI_MSG_GET_CLOCK_FREQ,
                                      TI_SCI_FLAG_RESP_GENERIC_ACK,
                                      PMHAL_PMMC_TIMEOUT_DEFAULT);

        if (status == PM_SUCCESS)
        {
            /* Eventually PMHAL API should be moved to 64-bit clockRate.  32-bit
             * casted to 64-bit is fine for now since 32-bit equals ~4GHz which is
             * way over the max allowed frequency for current devices. */
            *clockRate = (uint32_t) (getResponse.freq_hz & 0xFFFFFFFF);
        }
    }

    return status;
}

pmErrCode_t PMHALPmmcModuleIsIdValid(pmhalPmmcModuleId_t moduleId)
{
#if !defined (PM_OPTIMIZE)
    /* Assume Inputs are correct when optimization enabled */
    pmErrCode_t retVal;

    /* moduleId is unsigned so can never be less than zero.  Just check
     * upper bound */
    if (moduleId > (PMHAL_PMMC_MOD_COUNT - 1U))
    {
        retVal = PM_INPUT_PARAM_BAD_MODULE_ID;
    }
    else
    {
        retVal = PM_SUCCESS;
    }
    return retVal;
#else
    return PM_SUCCESS;
#endif
}

pmErrCode_t PMHALPmmcModuleIsStateValid(uint32_t state)
{
#if !defined (PM_OPTIMIZE)
    /* Assume Inputs are correct when optimization enabled */
    pmErrCode_t retVal;
    if ((state != MSG_DEVICE_SW_STATE_AUTO_OFF) &&
        (state != MSG_DEVICE_SW_STATE_RETENTION) &&
        (state != MSG_DEVICE_SW_STATE_ON))
    {
        retVal = PM_BADARGS;
    }
    else
    {
        retVal = PM_SUCCESS;
    }
    return retVal;
#else
    return PM_SUCCESS;
#endif
}


/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static pmErrCode_t PmhalPmmcTransaction(uint32_t *reqData, uint32_t reqSize,
                                        uint32_t *respData, uint32_t respSize,
                                        uint16_t type, uint32_t flags,
                                        uint32_t timeout)
{
    pmErrCode_t            status = PM_SUCCESS;
    struct ti_sci_msg_hdr *reqHdr = (struct ti_sci_msg_hdr *)reqData;
    struct ti_sci_msg_hdr *respHdr = (struct ti_sci_msg_hdr *)respData;
    uint8_t                localSeq;

    if (SemaphoreP_pend(sem, SemaphoreP_WAIT_FOREVER) == SemaphoreP_OK)
    {
        BUILD_SCI_HDR((*reqHdr), type, PMMC_LOCAL_HOST_ID, ++seq,
                      flags);
        /* Save sequence number for checking response outside of semaphore */
        localSeq = seq;

        /* Send message */
        status = PMHALMsgmgrWrite(MSGMGR_PROXY, MSGMGR_TX_PMMC_QUEUE,
                                  reqData, reqSize);

        if (status == PM_SUCCESS)
        {
            /* Wait for response */
            status = PMHALMsgmgrPoll(MSGMGR_PROXY, MSGMGR_RX_PMMC_QUEUE,
                                     timeout);
        }

        if (status == PM_SUCCESS)
        {
            /* Get response */
            status = PMHALMsgmgrRead(MSGMGR_PROXY, MSGMGR_RX_PMMC_QUEUE,
                                     respData, respSize);
        }

        if (SemaphoreP_post(sem) != SemaphoreP_OK)
        {
            status = PM_PMMC_FAILED_SEM_POST;
        }
    }
    else
    {
        status = PM_PMMC_FAILED_SEM_PEND;
    }

    if (status == PM_SUCCESS)
    {
        /* Validate response */
        status = PM_PMMC_INVALID_RESPONSE;
        if ((respHdr->host == TI_SCI_MSG_HOST_PMMC) &&
            (respHdr->type == type) &&
            (respHdr->seq == localSeq))
        {
            status = PM_SUCCESS;
        }
    }

    return status;
}

