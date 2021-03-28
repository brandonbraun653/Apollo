/*
 *   Copyright (c) Texas Instruments Incorporated 2019
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
 *  \file     csl_cbass_qos.c
 *
 *  \brief    This file contains the implementation of the APIs present in the
 *            device abstraction layer file of CBASS QoS.
 *            This also contains some related macros.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/csl_types.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/cslr_cbass.h>
#include <ti/csl/src/ip/cbass/V0/csl_cbass_qos.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 * Requirement: REQ_TAG(PRSDK-5695)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassQosSetQos(const CSL_cbass_qosRegs_ep *pQosEpRegs,
                           uint32_t                    channel,
                           uint32_t                    qosVal)
{
    int32_t  status;

    if ((pQosEpRegs == (NULL_PTR))                     ||
        (channel >= CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS) ||
        (qosVal > CSL_CBASS_QOS_EP_MAP_QOS_MAX))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        HW_WR_FIELD32(&pQosEpRegs->MAP[channel],
                      CSL_CBASS_QOS_EP_MAP_QOS,
                      qosVal);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5694)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassQosGetQos(const CSL_cbass_qosRegs_ep *pQosEpRegs,
                           uint32_t                    channel,
                           uint32_t                   *pQosVal)
{
    int32_t  status;

    if ((pQosEpRegs == (NULL_PTR))                     ||
        (channel >= CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS) ||
        (pQosVal == (NULL_PTR)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        *pQosVal = HW_RD_FIELD32(&pQosEpRegs->MAP[channel],
                                 CSL_CBASS_QOS_EP_MAP_QOS);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5695)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassQosSetOrderID(const CSL_cbass_qosRegs_ep *pQosEpRegs,
                               uint32_t                    channel,
                               uint32_t                    orderId)
{
    int32_t  status;

    if ((pQosEpRegs == (NULL_PTR))                     ||
        (channel >= CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS) ||
        (orderId > CSL_CBASS_QOS_EP_MAP_ORDERID_MAX))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        HW_WR_FIELD32(&pQosEpRegs->MAP[channel],
                      CSL_CBASS_QOS_EP_MAP_ORDERID,
                      orderId);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5694)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassQosGetOrderID(const CSL_cbass_qosRegs_ep *pQosEpRegs,
                               uint32_t                    channel,
                               uint32_t                   *pOrderId)
{
    int32_t  status;

    if ((pQosEpRegs == (NULL_PTR))                     ||
        (channel >= CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS) ||
        (pOrderId == (NULL_PTR)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        *pOrderId = HW_RD_FIELD32(&pQosEpRegs->MAP[channel],
                                  CSL_CBASS_QOS_EP_MAP_ORDERID);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5695)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassQosSetEpriority(const CSL_cbass_qosRegs_ep *pQosEpRegs,
                                 uint32_t                    channel,
                                 uint32_t                    epriority)
{
    int32_t  status;

    if ((pQosEpRegs == (NULL_PTR))                     ||
        (channel >= CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS) ||
        (epriority > CSL_CBASS_QOS_EP_MAP_EPRIORITY_MAX))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        HW_WR_FIELD32(&pQosEpRegs->MAP[channel],
                      CSL_CBASS_QOS_EP_MAP_EPRIORITY,
                      epriority);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5694)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassQosGetEpriority(const CSL_cbass_qosRegs_ep *pQosEpRegs,
                                 uint32_t                    channel,
                                 uint32_t                   *pEpriority)
{
    int32_t  status;

    if ((pQosEpRegs == (NULL_PTR))                     ||
        (channel >= CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS) ||
        (pEpriority == (NULL_PTR)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        *pEpriority = HW_RD_FIELD32(&pQosEpRegs->MAP[channel],
                                    CSL_CBASS_QOS_EP_MAP_EPRIORITY);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5257) REQ_TAG(PRSDK-5694)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassQosReadStaticRegs (const CSL_cbass_qosRegs_ep *pQosEpRegs,
                                    CSL_cbass_qosRegs_ep       *pStaticRegs)
{
    int32_t  status;
    uint32_t i;

    if ((pQosEpRegs == (NULL_PTR))    ||
        (pStaticRegs == (NULL_PTR)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        /* Read the channel map registers, reset the reserved bits */
        for (i = (uint32_t)(0U); i < CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS; i++)
        {
            pStaticRegs->MAP[i] = pQosEpRegs->MAP[i] & CSL_CBASS_QOS_EP_MAP_MASK;
        }

        status = CSL_PASS;
    }
    return status;
}
