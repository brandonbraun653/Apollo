/**
 *  \file     dma.h
 *
 *  \brief    This file contains the function prototypes for the device
 *            abstraction layer for DMA.
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

#ifndef DMA_H_
#define DMA_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */


#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the source or destination data addressing mode. */
typedef enum dmaXferDataAddrMode
{
    DMA_XFER_DATA_ADDR_MODE_MIN = 0U,
    /**< Minimum data addressing mode. */
    DMA_XFER_DATA_ADDR_MODE_INC = DMA_XFER_DATA_ADDR_MODE_MIN,
    /**<
     * Increment (INCR) mode. Data addressing within an array increments.
     * Data is not a FIFO.
     */
    DMA_XFER_DATA_ADDR_MODE_CONST,
    /**<
     * Constant addressing (CONST) mode. Data addressing within an array wraps
     * around upon reaching FIFO width.
     */
    DMA_XFER_DATA_ADDR_MODE_MAX = DMA_XFER_DATA_ADDR_MODE_CONST
    /**< Maximum data addressing mode. */
}dmaXferDataAddrMode_t;

/**
 * \brief Enumerates the FIFO Width. Applies if either SAM or DAM is set to
 *        constant addressing mode.
 */
typedef enum dmaXferDataFifoWidth
{
    DMA_XFER_DATA_FIFO_WIDTH_MIN = 0U,
    /**< Minimum FIFO width. */
    DMA_XFER_DATA_FIFO_WIDTH_8_BIT = DMA_XFER_DATA_FIFO_WIDTH_MIN,
    /**< FIFO width is 8-bit. */
    DMA_XFER_DATA_FIFO_WIDTH_16_BIT,
    /**< FIFO width is 16-bit. */
    DMA_XFER_DATA_FIFO_WIDTH_32_BIT,
    /**< FIFO width is 32-bit. */
    DMA_XFER_DATA_FIFO_WIDTH_64_BIT,
    /**< FIFO width is 64-bit. */
    DMA_XFER_DATA_FIFO_WIDTH_128_BIT,
    /**< FIFO width is 128-bit. */
    DMA_XFER_DATA_FIFO_WIDTH_256_BIT,
    /**< FIFO width is 256-bit. */
    DMA_XFER_DATA_FIFO_WIDTH_MAX = DMA_XFER_DATA_FIFO_WIDTH_256_BIT
    /**< Maximum FIFO width. */
}dmaXferDataFifoWidth_t;

/**
 *  \brief Enumerates the types of trigger enabled on channel for transfer.
 */
typedef enum dmaXferTriggerType
{
    DMA_XFER_TRIGGER_TYPE_MIN = 0U,
    /**< Min triggered type. */
    DMA_XFER_TRIGGER_TYPE_MANUAL,
    /**< Manual triggered. */
    DMA_XFER_TRIGGER_TYPE_EVENT,
    /**< Event triggered. */
    DMA_XFER_TRIGGER_TYPE_AUTO,
    /**< Link triggered. */
    DMA_XFER_TRIGGER_TYPE_MAX = DMA_XFER_TRIGGER_TYPE_AUTO
    /**< Maximum transfer trigger type. */
} dmaXferTriggerType_t;

/**
 *  \brief Enumerates the mask for types of trigger enabled on channel for transfer.
 */
typedef enum dmaXferTriggerTypeMask
{
    DMA_XFER_TRIGGER_TYPE_MASK_INVALID = 0U,
    /**< Invalid trigger mask. */
    DMA_XFER_TRIGGER_TYPE_MASK_MANUAL = (1U << DMA_XFER_TRIGGER_TYPE_MANUAL),
    /**< Manual trigger mask. */
    DMA_XFER_TRIGGER_TYPE_MASK_EVENT = (1U << DMA_XFER_TRIGGER_TYPE_EVENT),
    /**< Event triggered mask. */
    DMA_XFER_TRIGGER_TYPE_MASK_AUTO = (1U << DMA_XFER_TRIGGER_TYPE_AUTO)
    /**< Link triggered mask. */
} dmaXferTriggerTypeMask_t;

/**
 *  \brief Enumerates the types of transfer status on channel.
 */
typedef enum dmaChXferStatus
{
    DMA_CH_XFER_STATUS_MIN = 0U,
    /**< Min transfer status on channel. */
    DMA_CH_XFER_STATUS_NORMAL = DMA_CH_XFER_STATUS_MIN,
    /**< DMA transfer status on channel is normal or in-progress. */
    DMA_CH_XFER_STATUS_MISS,
    /**< DMA transfer status on channel is missed event. */
    DMA_CH_XFER_STATUS_ERROR,
    /**< DMA transfer error occurred on channel. */
    DMA_CH_XFER_STATUS_MAX = DMA_CH_XFER_STATUS_ERROR
    /**< Maximum transfer status on channel. */
} dmaChXferStatus_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                   Deprecated Function Declarations                         */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef DMA_H_ */
