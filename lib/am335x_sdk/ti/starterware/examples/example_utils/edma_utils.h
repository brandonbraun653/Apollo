/**
 *  \file  edma_utils.h
 *
 * \brief  This file contains the prototypes of the functions for EDMA Utils.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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

#ifndef EDMA_UTILS_H_
#define EDMA_UTILS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "interrupt.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Maximum number of EDMA channel supported. */
#define EDMA_UTILS_CALLBACK_MAX                                   (64U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief structure defining the parameters required for interrupt configuration.
 */
typedef struct edmaUtilsIntrCfgObj
{
    uint32_t complIntrLine;
    /**< EDMA Completion interrupt line. */
    intcIntrParams_t complIntrParams;
    /**< EDMA Completion interrupt configuration. */
    uint32_t errorIntrLine;
    /**< EDMA Error interrupt line. */
    intcIntrParams_t errorIntrParams;
    /**< EDMA Error interrupt configuration. */
}edmaUtilsIntrCfgObj_t;

/**
 *  \brief structure defining the parameters required for EDMA configuration.
 */
typedef struct edmaUtilsObj
{
    uint32_t baseChCtrlAddr;
    /**< Base address of EDMA channel controller. */
    uint32_t region;
    /**< Shadow region interfaced with MPU. */
    uint32_t initStatus;
    /**< Controller initialization status. */
    edmaUtilsIntrCfgObj_t intrCfg;
    /**< EDMA interrupt Configuration Structure. */
    DMACallBackFxn pFnCallBack[EDMA_UTILS_CALLBACK_MAX];
    /**< EDMA call back function. */
} edmaUtilsObj_t;

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function initialize the given instance for the given type of
 *          EDMA controller.
 *
 * \param   instNum        Instance number of EDMA type.
 * \param   pInitParams    Initialization parameter configuration.
 *
 * \retval  S_PASS  EDMA controller initialization successful.
 * \retval  E_FAIL  EDMA controller initialization failed.
 */
int32_t EDMAUtilsInit(uint32_t instNum,
                      dmaUtilsInitParams_t *pInitParams);

/**
 * \brief   This function performs reset on the given instance for the given
 *          type of EDMA controller.
 *
 * \param   instNum Instance number of EDMA type.
 *
 * \retval  S_PASS  EDMA controller reset successful.
 * \retval  E_FAIL  EDMA controller reset failed.
 */
int32_t EDMAUtilsReset(uint32_t instNum);

/**
 * \brief   This function configures the transfer entry required to perform
 *          normal EDMA transfer without chaining and linking.
 *
 * \param   instNum Instance number of EDMA type.
 * \param   xferIdx Transfer parameter RAM index.
 *
 * \retval  S_PASS  Transfer reset successful.
 * \retval  E_FAIL  Transfer reset failed.
 */
int32_t EDMAUtilsDataXferReset(uint32_t instNum, uint32_t xferIdx);

/**
 * \brief   This function configures the transfer entry required to perform
 *          normal EDMA transfer without chaining and linking.
 *
 * \param   instNum        Instance number of EDMA type.
 * \param   xferIdx        Transfer parameter RAM index.
 * \param   pDmaXferConfig EDMA transfer configuration.
 *
 * \retval  S_PASS         Transfer configuration successful.
 * \retval  E_FAIL         Transfer configuration failed.
 */
int32_t EDMAUtilsDataXferConfig(uint32_t instNum,
                                uint32_t xferIdx,
                                dmaUtilsXferObj_t *pDmaXferConfig);

/**
 * \brief   This function configures the parameters entry required to perform
 *          EDMA transfer.
 *
 * \param   instNum      Instance number of EDMA type.
 * \param   chNum        EDMA channel number.
 * \param   pDmaChObj    Channel configuration of EDMA.
 *
 * \retval  S_PASS       Channel configuration successful.
 * \retval  E_FAIL       Channel configuration failed.
 */
int32_t EDMAUtilsChConfig(uint32_t instNum,
                          uint32_t chNum,
                          dmaUtilsChObj_t *pDmaChObj);

/**
 * \brief   This function enables the EDMA transfer configured for a channel.
 *
 * \param   instNum      Instance number of EDMA type.
 * \param   chNum        EDMA channel number.
 * \param   triggerType  EDMA transfer trigger type takes #dmaXferTriggerType_t.
 *
 * \retval  S_PASS       Channel transfer enabled.
 * \retval  E_FAIL       Channel transfer enable failed.
 */
int32_t EDMAUtilsXferStart(uint32_t instNum,
                           uint32_t chNum,
                           uint32_t triggerType);

/**
 * \brief   This function disables the EDMA transfer configured for a channel.
 *
 * \param   instNum      Instance number of EDMA type.
 * \param   chNum        EDMA channel number.
 * \param   triggerType  EDMA transfer trigger type takes #dmaXferTriggerType_t.
 *
 * \retval  S_PASS       Channel transfer disabled.
 * \retval  E_FAIL       Channel transfer disable failed.
 */
int32_t EDMAUtilsXferStop(uint32_t instNum,
                          uint32_t chNum,
                          uint32_t triggerType);

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef EDMA_UTILS_H_ */
