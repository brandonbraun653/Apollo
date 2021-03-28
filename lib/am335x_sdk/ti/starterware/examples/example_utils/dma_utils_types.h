/**
 *  \file  dma_utils_types.h
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

#ifndef DMA_UTILS_TYPES_H_
#define DMA_UTILS_TYPES_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Call back function definition to handle interrupts. */
typedef void (*DMACallBackFxn) (uint32_t chNum, uint32_t xferStatus);

/** \brief Enumerates the types of event configured for channel. */
typedef enum dmaUtilsEventMapType
{
    DMA_UTILS_EVENT_MAP_TYPE_MIN = 0U,
    /**< Min event to channel mapping type. */
    DMA_UTILS_EVENT_MAP_TYPE_NONE = DMA_UTILS_EVENT_MAP_TYPE_MIN,
    /**< No event to channel mapping type. */
    DMA_UTILS_EVENT_MAP_TYPE_DIRECT,
    /**< Direct event to channel mapped. */
    DMA_UTILS_EVENT_MAP_TYPE_MAX = DMA_UTILS_EVENT_MAP_TYPE_DIRECT
    /**< Maximum event to channel mapping type. */
} dmaUtilsEventMapType_t;

/** \brief Enumerates the types to configure for transfer operation. */
typedef enum dmaUtilsXferType
{
    DMA_UTILS_XFER_TYPE_MIN =  0U,
    /**< Min transfer type. */
    DMA_UTILS_XFER_TYPE_NORMAL = DMA_UTILS_XFER_TYPE_MIN,
    /**< Normal transfer. */
    DMA_UTILS_XFER_TYPE_LINK,
    /**< Link transfer. */
    DMA_UTILS_XFER_TYPE_MAX = DMA_UTILS_XFER_TYPE_LINK,
    /**< Maximum transfer type. */
} dmaUtilsXferType_t;

/** \brief Enumerates the mask of types to configure for transfer operation. */
typedef enum dmaUtilsXferTypeMask
{
    DMA_UTILS_XFER_TYPE_MASK_INVALID =  0U,
    /**< Invalid transfer mask. */
    DMA_UTILS_XFER_TYPE_MASK_NORMAL = (1U << DMA_UTILS_XFER_TYPE_NORMAL),
    /**< Normal transfer mask. */
    DMA_UTILS_XFER_TYPE_MASK_LINK = (1U << DMA_UTILS_XFER_TYPE_LINK),
    /**< Link transfer mask. */
} dmaUtilsXferTypeMask_t;

/** \brief Enumerates the types of status for transfer on channel. */
typedef enum dmaUtilsXferStatus
{
    DMA_UTILS_XFER_STATUS_MIN = 0U,
    /**< Min transfer status. */
    DMA_UTILS_XFER_STATUS_SUCESS = DMA_UTILS_XFER_STATUS_MIN,
    /**< Transfer successful. */
    DMA_UTILS_XFER_STATUS_FAIL,
    /**< Transfer failed. */
    DMA_UTILS_XFER_STATUS_IN_PROGRESS,
    /**< Transfer in-progress. */
    DMA_UTILS_XFER_STATUS_MAX = DMA_UTILS_XFER_STATUS_IN_PROGRESS
    /**< Maximum transfer status. */
} dmaUtilsXferSts_t;

/** \brief Enumerates the types of data synchronization. */
typedef enum dmaUtilsDataSync
{
    DMA_UTILS_DATA_SYNC_MIN =  0U,
    /**< Min data synchronization. */
    DMA_UTILS_DATA_SYNC_PACKET = DMA_UTILS_DATA_SYNC_MIN,
    /**< Data synchronization on packet. */
    DMA_UTILS_DATA_SYNC_FRAME,
    /**< Data synchronization on frame. */
    DMA_UTILS_DATA_SYNC_BLOCK,
    /**< Data synchronization on block. */
    DMA_UTILS_DATA_SYNC_MAX
    /**< Invalid data synchronization. */
} dmaUtilsDataSync_t;

/** \brief Enumerates the mask of data synchronization types. */
typedef enum dmaUtilsDataSyncMask
{
    DMA_UTILS_DATA_SYNC_MASK_NONE =  0U,
    /**< Invalid data synchronization. */
    DMA_UTILS_DATA_SYNC_MASK_PACKET = (1U << DMA_UTILS_DATA_SYNC_PACKET),
    /**< Mask data synchronization on packet. */
    DMA_UTILS_DATA_SYNC_MASK_FRAME = (1U << DMA_UTILS_DATA_SYNC_FRAME),
    /**< Mask data synchronization on frame. */
    DMA_UTILS_DATA_SYNC_MASK_BLOCK = (1U << DMA_UTILS_DATA_SYNC_BLOCK),
    /**< Mask data synchronization on block. */
} dmaUtilsDataSyncMask_t;

/**
 *  \brief structure defining the parameters required for initializing the
 *         feature support of DMA instance.
 */
typedef struct dmaUtilsInitParams
{
    uint32_t              chMapSupport;
    /**< Channel mapping support existence. */
    uint32_t              crossBarEventSupport;
    /**< Cross bar event to channel mapping support. */
    uint32_t              directEventSupport;
    /**< Direct event to channel mapping support. */
} dmaUtilsInitParams_t;

/**
 *  \brief   Structure defining the parameters required to determine the data
 *           format of source and destination buffer.
 *
 *  \details A packet is defined as the number of bytes. A frame is composition
 *           of packets. Number of such frames to be transferred form a block.
 *           An active packet is the number of contiguous bytes in packet to be
 *           transmitted. The data address shall point to the first active packet
 *           of the block. An active frame is the number of contiguous packets
 *           to be transmitted. A block is number of contiguous frames to be
 *           transmitted.
 *
 *        * - Start address
 *        x - Data not be transferred or inactive size of packet/frame.
 *
 *          t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
 *         k /x x x x x x x x x / x x x x x x /|            /
 *        c /x_x_x_x_x_x_x_x_x_/ x x x x x x //|           /packet
 *       p /                  / x x x x x x ///|          /
 *        /_ _ _ _ _ _ _ _ _ /_x_x_x_x_x_x_////|         /_ _ _ _ _ _ _ _ _
 *      b |*    frame       | x x x x x x |////          |      frame
 *      l |                 | x x x x x x |///           |
 *      o |                 | x x x x x x |//            |
 *      c |                 |_x_x_x_x_x_x_|/             | block
 *      k |_ _ _ _ _ _ _ _ _|<----------->               |
 *         <--------------->   Inactive
 *              Active
 *
 */
typedef struct dmaUtilsDataObj
{
    uint32_t              addr;
    /**< Data address. */
    uint32_t              addrMode;
    /**< Addressing mode supported by the data. #dmaXferDataAddrMode_t */
    uint32_t              fifoWidth;
    /**< FIFO Width. This is applicable for constant addressing mode. */
    uint32_t              packetActSize;
    /**< Number of bytes in packets to be transferred. packetActSize is FIFO
         width for constant address mode. */
    uint32_t              frameActSize;
    /**< Number of packets in frame to be transferred. */
    uint32_t              blockSize;
    /**< Number of frame to be transferred. */
    uint32_t              packetInactSize;
    /**< Number of trailing bytes not to be transferred in a packets. This is
         not applicable for constant addressing mode. */
    uint32_t              frameInactSize;
    /**< Number of trailing packets not to be transferred in a frame. This is
         not applicable for constant addressing mode. */
    uint32_t              syncMode;
    /**< Data sync mode. */
} dmaUtilsDataObj_t;

/**
 *  \brief Structure defining the parameters for data, interrupt, chain and link
 *         configuration of a transfer.
 */
typedef struct dmaUtilsXferObj
{
    dmaUtilsDataObj_t         *pSrc;
    /**< Source data buffer configuration. */
    dmaUtilsDataObj_t         *pDst;
    /**< Destination data buffer configuration. */
    dmaUtilsDataSyncMask_t    intrConfig;
    /**< Interrupt configuration mask takes #dmaUtilsDataSyncMask_t. */
    uint32_t                  linkEnable;
    /**< Enable linking on completion of this transfer. */
    uint32_t                  nxtXferIdx;
    /**< Next transfer object configuration. */
} dmaUtilsXferObj_t;

/**
 *  \brief Structure defining the parameters for configuration of DMA channel.
 */
typedef struct dmaUtilsChObj
{
    uint32_t              triggerType;
    /**< Transfer trigger type #dmaXferTriggerType_t. */
    uint32_t              xferIdx;
    /**< Transfer object for the channel. */
    uint32_t              intrEnable;
    /**< Enable interrupts. */
    DMACallBackFxn        callBack;
    /**< Call back function to handle interrupts. */
    uint32_t              queueNum;
    /**< Queue number the channel is grouped. */
} dmaUtilsChObj_t;

/** \brief Structure defining the DMA event information. */
typedef struct dmaUtilsEvtInfo
{
    uint32_t              dmaType;
    /**< Type of DMA. */
    uint32_t              instNum;
    /**< DMA module instance number. */
    uint32_t              evtToChMapType;
    /**< Type of mapping from Event to channel #dmaUtilsEventMapType_t. */
    uint32_t              evtNum;
    /**< Event number. */
    uint32_t              chNum;
    /**< Channel number for event. */
    uint32_t              xferIdx;
    /**< Transfer index of channel. */
} dmaUtilsEvtInfo_t;

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef DMA_UTILS_TYPES_H_ */
