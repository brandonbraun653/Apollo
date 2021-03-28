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
 *  \ingroup CSL_CBASS
 *  \defgroup CSL_CBASS_QOS CBASS QoS
 *
 *  @{
 */
/**
 *  \file     csl_cbass_qos.h
 *
 *  \brief    This file contains the prototypes of the APIs present in the
 *            device abstraction layer file of CBASS QoS.
 *            This also contains some related macros.
 */

#ifndef CBASS_QOS_H_
#define CBASS_QOS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "ti/csl/cslr_cbass.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup CSL_CBASS_QOS_API CBASS QOS API
 */
/**
@defgroup CSL_CBASS_QOS_DATATYPE CBASS QOS Data Types
@ingroup CSL_CBASS_QOS_API
*/
/**
@defgroup CSL_CBASS_QOS_DATASTRUCT CBASS QOS Data Structures
@ingroup CSL_CBASS_QOS_API
*/
/**
@defgroup CSL_CBASS_QOS_FUNCTION  CBASS QOS Functions
@ingroup CSL_CBASS_QOS_API
*/

/** ===========================================================================
 *  @addtogroup CSL_CBASS_QOS_DATATYPE
    @{
 * ============================================================================
 */

/* ========================================================================== */
/*                            Macros & Typedefs                               */
/* ========================================================================== */

/**
 * \brief  Max number of channels supported in CBASS QoS.
 */
#define CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS    (192U)

/**
 * \brief  CBASS QoS channel map register mask
 */
#define CSL_CBASS_QOS_EP_MAP_MASK            (CSL_CBASS_QOS_EP_MAP_QOS_MASK       | \
                                              CSL_CBASS_QOS_EP_MAP_ORDERID_MASK   | \
                                              CSL_CBASS_QOS_EP_MAP_EPRIORITY_MASK)

/** @} */

/** ============================================================================
 *  @addtogroup CSL_CBASS_QOS_DATASTRUCT
    @{
 * =============================================================================
 */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/** @} */

/** ===========================================================================
 *  @addtogroup CSL_CBASS_QOS_FUNCTION
    @{
 * ============================================================================
 */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Configure the CBASS master QoS signal for given channel.
 *
 * \param   pQosEpRegs      Pointer (of type CSL_cbass_qosRegs_ep *) to the base
 *                          address of the CBASS QoS module.
 * \param   channel         Channel number for which QoS value to be configured.
 * \param   qosVal          QoS signal value for given channel
 *
 * \return  status          CBASS QoS value configuration status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassQosSetQos(const CSL_cbass_qosRegs_ep *pQosEpRegs,
                           uint32_t                    channel,
                           uint32_t                    qosVal);

/**
 * \brief   Get the CBASS master QoS signal for given channel.
 *
 * \param   pQosEpRegs      Pointer (of type CSL_cbass_qosRegs_ep *) to the base
 *                          address of the CBASS QoS module.
 * \param   channel         Channel number for which to get QoS value.
 * \param   pQosVal         Pointer to QoS signal value for given channel
 *
 * \return  status          CBASS QoS value get status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassQosGetQos(const CSL_cbass_qosRegs_ep *pQosEpRegs,
                           uint32_t                    channel,
                           uint32_t                   *pQosVal);

/**
 * \brief   Configure the CBASS master QoS Order ID for given channel.
 *
 * \param   pQosEpRegs      Pointer (of type CSL_cbass_qosRegs_ep *) to the base
 *                          address of the CBASS QoS module.
 * \param   channel         Channel number for which Order ID to be configured.
 * \param   orderId         Order ID for given channel
 *
 * \return  status          CBASS QoS order ID value configuration status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassQosSetOrderID(const CSL_cbass_qosRegs_ep *pQosEpRegs,
                               uint32_t                    channel,
                               uint32_t                    orderId);

/**
 * \brief   Get the CBASS master QoS Order ID for given channel.
 *
 * \param   pQosEpRegs      Pointer (of type CSL_cbass_qosRegs_ep *) to the base
 *                          address of the CBASS QoS module.
 * \param   channel         Channel number for which to get Order ID.
 * \param   pOrderId        Pointer to order ID for given channel
 *
 * \return  status          CBASS QoS order ID get status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassQosGetOrderID(const CSL_cbass_qosRegs_ep *pQosEpRegs,
                               uint32_t                    channel,
                               uint32_t                   *pOrderId);

/**
 * \brief   Configure the CBASS master epriority signal for given channel.
 *
 * \param   pQosEpRegs      Pointer (of type CSL_cbass_qosRegs_ep *) to the base
 *                          address of the CBASS QoS module.
 * \param   channel         Channel number for which epriority to be configured.
 * \param   epriority       Epriority vlaue for given channel
 *
 * \return  status          CBASS QoS epriority configuration status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassQosSetEpriority(const CSL_cbass_qosRegs_ep *pQosEpRegs,
                                 uint32_t                    channel,
                                 uint32_t                    epriority);

/**
 * \brief   Get the CBASS master epriority signal value for given channel.
 *
 * \param   pQosEpRegs      Pointer (of type CSL_cbass_qosRegs_ep *) to the base
 *                          address of the CBASS QoS module.
 * \param   channel         Channel number for which to get epriority.
 * \param   pEpriority      Pointer to epriority for given channel
 *
 * \return  status          CBASS QoS epriority get status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassQosGetEpriority(const CSL_cbass_qosRegs_ep *pQosEpRegs,
                                 uint32_t                    channel,
                                 uint32_t                   *pEpriority);

/**
 * \brief   This API is used to read static registers of CBASS QoS module.
 *          This API needs to be called after the initial configuration is done and
 *          hence mutliple read between static registers do not change the values
 *
 * \param   pQosEpRegs      Pointer (of type CSL_cbass_qosRegs_ep *) to the base
 *                          address of the CBASS QoS module.
 * \param   pStaticRegs     pointer to static registers to be read
 *
 * \return                  CSL_PASS - success
 *                          CSL_EBADARGS - API fails due to bad input arguments
 */
int32_t CSL_cbassQosReadStaticRegs (const CSL_cbass_qosRegs_ep *pQosEpRegs,
                                    CSL_cbass_qosRegs_ep       *pStaticRegs);

/** @} */

#ifdef __cplusplus
}

#endif /*extern "C" */

#endif
 /** @} */
