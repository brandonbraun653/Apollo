/**
 *  \file  dma_utils.h
 *
 * \brief  This file contains the prototypes of the functions for DMA Utils.
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

#ifndef DMA_UTILS_H_
#define DMA_UTILS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "dma_utils_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief EDMA type of DMA. */
#define DMA_TYPE_ENHACED (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 * \brief Structure holding EDMA PaRAM Set in User Configurable format.
 */
typedef struct dmaUtilsEvtConfig
{
    uint32_t dmaType;
    /**< DMA type. */
    uint32_t dmaInst;
    /**< Instance of DMA type. */
    dmaUtilsChObj_t *pChObj;
    /**< Associated DMA channel object. */
}dmaUtilsEvtConfig_t;

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function initialize the given instance for the given type of
 *          DMA controller.
 *
 * \param   dmaType        Type of DMA.
 * \param   instNum        Instance number of DMA type.
 * \param   pInitParams    Initialization parameter configuration.
 *
 * \retval  S_PASS  DMA controller initialization successful.
 * \retval  E_FAIL  DMA controller initialization failed.
 */
int32_t DMAUtilsInit(uint32_t dmaType,
                     uint32_t instNum,
                     dmaUtilsInitParams_t *pInitParams);

/**
 * \brief   This function performs reset on the given instance for the given
 *          type of DMA controller.
 *
 * \param   dmaType        Type of DMA.
 * \param   instNum        Instance number of DMA type.
 *
 * \retval  S_PASS  DMA controller reset successful.
 * \retval  E_FAIL  DMA controller reset failed.
 */
int32_t DMAUtilsReset(uint32_t dmaType,
                     uint32_t instNum);

/**
 * \brief   This function configures the transfer entry required to perform
 *          normal DMA transfer without chaining and linking.
 *
 * \param   dmaType        Type of DMA.
 * \param   instNum        Instance number of DMA type.
 * \param   xferIdx        Transfer parameter index.
 * \param   pDmaXferConfig DMA transfer configuration.
 *
 * \retval  S_PASS  Transfer configuration successful.
 * \retval  E_FAIL  Transfer configuration failed.
 */
int32_t DMAUtilsDataXferConfig(uint32_t dmaType,
                               uint32_t instNum,
                               uint32_t xferIdx,
                               dmaUtilsXferObj_t *pDmaXferConfig);

/**
 * \brief   This function configures the transfer entry required to perform
 *          normal DMA transfer without chaining and linking.
 *
 * \param   dmaType        Type of DMA.
 * \param   instNum        Instance number of DMA type.
 * \param   xferIdx        Transfer parameter index.
 *
 * \retval  S_PASS  Transfer configuration successful.
 * \retval  E_FAIL  Transfer configuration failed.
 */
int32_t DMAUtilsDataXferReset(uint32_t dmaType,
                              uint32_t instNum,
                              uint32_t xferIdx);

/**
 * \brief   This function configures the transfer entry to perform linking with
 *          another DMA transfer entry.
 *
 * \param   dmaType           Type of DMA.
 * \param   instNum           Instance number of DMA type.
 * \param   pDmaXferConfig    DMA transfer configuration to be linked.
 * \param   pNxtDmaXferConfig DMA transfer configuration linked to.
 *
 * \retval  S_PASS  Link configuration successful.
 * \retval  E_FAIL  Link configuration failed.
 */
int32_t DMAUtilsLinkXferConfig(uint32_t dmaType,
                              uint32_t instNum,
                              dmaUtilsXferObj_t *pDmaXferConfig,
                              dmaUtilsXferObj_t *pNxtDmaXferConfig);

/**
 * \brief   This function configures the parameters entry required to perform
 *          DMA transfer.
 *
 * \param   dmaType        Type of DMA.
 * \param   instNum        Instance number of DMA type.
 * \param   chNum          DMA channel number.
 * \param   pDmaChObj      Channel configuration of DMA.
 *
 * \retval  S_PASS  Channel configuration successful.
 * \retval  E_FAIL  Channel configuration failed.
 */
int32_t DMAUtilsChConfig(uint32_t dmaType,
                        uint32_t instNum,
                        uint32_t chNum,
                        dmaUtilsChObj_t *pDmaChObj);

/**
 * \brief   This function enables the DMA transfer configured for a channel.
 *
 * \param   dmaType      Type of DMA.
 * \param   instNum      Instance number of DMA type.
 * \param   chNum        DMA channel number.
 * \param   triggerType  EDMA transfer trigger type takes #dmaXferTriggerType_t.
 *
 * \retval  S_PASS  Channel transfer enabled.
 * \retval  E_FAIL  Channel transfer enable failed.
 */
int32_t DMAUtilsXferStart(uint32_t dmaType,
                          uint32_t instNum,
                          uint32_t chNum,
                          uint32_t triggerType);

/**
 * \brief   This function disables the DMA transfer configured for a channel.
 *
 * \param   dmaType      Type of DMA.
 * \param   instNum      Instance number of DMA type.
 * \param   chNum        DMA channel number.
 * \param   triggerType  EDMA transfer trigger type takes #dmaXferTriggerType_t.
 *
 * \retval  S_PASS  Channel transfer disabled.
 * \retval  E_FAIL  Channel transfer disable failed.
 */
int32_t DMAUtilsXferStop(uint32_t dmaType,
                         uint32_t instNum,
                         uint32_t chNum,
                         uint32_t triggerType);

/**
 * \brief   This function does memory to memory copy of given number of bytes
 *          from source to destination buffer.
 *
 * \param   dmaType      Type of DMA.
 * \param   instNum      Instance number of DMA type.
 * \param   pSrcBuf      Source buffer.
 * \param   pDstBuf      Destination buffer.
 * \param   noOfBytes    Number of bytes to transfer.
 *
 * \retval  S_PASS  Memory to memory transfer initiated.
 * \retval  E_FAIL  Failed to initiate Memory to memory transfer.
 */
int32_t DMAUtilsMemCopy(uint32_t dmaType,
                        uint32_t instNum,
                        uint8_t *pSrcBuf,
                        uint8_t *pDstBuf,
                        uint32_t noOfBytes);


/**
 * \brief   This function gives status of memory to memory transfer.
 *
 * \retval  TRUE   Transfer complete.
 * \retval  FALSE  Transfer in progress.
 */
uint32_t DMAUtilsMemCopyStatus(void);

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef DMA_UTILS_H_ */
