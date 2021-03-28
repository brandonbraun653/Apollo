/**
 *  \file     edma.h
 *
 *  \brief    This file contains the function prototypes for the device
 *            abstraction layer for EDMA.
 *
 *  \details  Please find the below detailed description of edma dal.
 *            -# Programming sequence for initializing the edma controller
 *               -# Perform the clock configuration of channel controller and
 *                  transfer controllers.
 *               -# To perform initialization of controller use
 *                  -# #EDMAInit for single CPU interface system.
 *                  -# #EDMARegionReset for multi CPU interface system.
 *            -# Programming sequence for setting up edma channel.
 *               -# To configure the PaRAM sets use #EDMAParamConfig. For
 *                  custom use
 *                  -# #EDMAParamXferConfig for transfer configuration.
 *                  -# #EDMAParamDataConfig for data configuration.
 *               -# To Configure channel use #EDMAChConfig.
 *               -# To start transfer use #EDMATransferStart.
 *               -# To stop transfer use #EDMATransferStart.
 *            -# Use #EDMAChReset to reset a channel.
 *            -# Use #EDMAParamReset to reset a PaRAM set.
 *
 *  \copyright Copyright (C) 2013-2019 Texas Instruments Incorporated -
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

#ifndef EDMA_H_
#define EDMA_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */


#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
/** \brief Mask values to set all bits. */
#define EDMA_SET_ALL_BITS             (0xFFFFFFFFU)

/* TODO: Following MACROs have to be generated with auto-generated */
#define EDMA_TPCC_DRAE(n)             ((uint32_t)0x340U + ((n) * 0x8U))
#define EDMA_TPCC_DRAE_NUM_ELEMS      (32U)
#define EDMA_TPCC_DRAEH(n)            ((uint32_t)0x344U + ((n) * 0x8U))
#define EDMA_TPCC_DRAEH_NUM_ELEMS     (32U)

#define EDMA_TPCC_PARAM(n)            ((uint32_t)0x4000U + ((n) * 0x4U * 0x8U))
#define EDMA_TPCC_PARAM_NUM_ELEMS     (256U)

#define EDMA_PARAM_OPT                                     (0x00U)
#define EDMA_PARAM_SRC                                     (0x04U)
#define EDMA_PARAM_A_B_CNT                                 (0x08U)
#define EDMA_PARAM_DST                                     (0x0CU)
#define EDMA_PARAM_SRC_DST_BIDX                            (0x10U)
#define EDMA_PARAM_LINK_BCNT_RLD                           (0x14U)
#define EDMA_PARAM_SRC_DST_CIDX                            (0x18U)
#define EDMA_PARAM_C_CNT                                   (0x1CU)

#define EDMA_PARAM_OPT_PRIV_MASK                           (0x80000000U)
#define EDMA_PARAM_OPT_PRIV_SHIFT                          (31U)
#define EDMA_PARAM_OPT_PRIV_USER                            (0U)
#define EDMA_PARAM_OPT_PRIV_SUPERVISOR                      (1U)

#define EDMA_PARAM_OPT_PRIV_ID_MASK                        (0x0F000000U)
#define EDMA_PARAM_OPT_PRIV_ID_SHIFT                       (24U)

#define EDMA_PARAM_OPT_ITC_CH_EN_MASK                      (0x00800000U)
#define EDMA_PARAM_OPT_ITC_CH_EN_SHIFT                     (23U)
#define EDMA_PARAM_OPT_ITC_CH_EN_ENABLE                     (1U)
#define EDMA_PARAM_OPT_ITC_CH_EN_DISABLE                    (0U)

#define EDMA_PARAM_OPT_TC_CH_EN_MASK                       (0x00400000U)
#define EDMA_PARAM_OPT_TC_CH_EN_SHIFT                      (22U)
#define EDMA_PARAM_OPT_TC_CH_EN_ENABLE                      (1U)
#define EDMA_PARAM_OPT_TC_CH_EN_DISABLE                     (0U)

#define EDMA_PARAM_OPT_ITC_INT_EN_MASK                     (0x00200000U)
#define EDMA_PARAM_OPT_ITC_INT_EN_SHIFT                    (21U)
#define EDMA_PARAM_OPT_ITC_INT_EN_ENABLE                    (1U)
#define EDMA_PARAM_OPT_ITC_INT_EN_DISABLE                   (0U)

#define EDMA_PARAM_OPT_TC_INT_EN_MASK                      (0x00100000U)
#define EDMA_PARAM_OPT_TC_INT_EN_SHIFT                     (20U)
#define EDMA_PARAM_OPT_TC_INT_EN_ENABLE                     (1U)
#define EDMA_PARAM_OPT_TC_INT_EN_DISABLE                    (0U)

#define EDMA_PARAM_OPT_TCC_MASK                            (0x0003F000U)
#define EDMA_PARAM_OPT_TCC_SHIFT                           (12U)

#define EDMA_PARAM_OPT_TCC_MODE_MASK                       (0x00000800U)
#define EDMA_PARAM_OPT_TCC_MODE_SHIFT                      (11U)
#define EDMA_PARAM_OPT_TCC_MODE_NORMAL                      (1U)
#define EDMA_PARAM_OPT_TCC_MODE_EARLY                       (0U)

#define EDMA_PARAM_OPT_FIFO_WIDTH_MASK                     (0x00000700U)
#define EDMA_PARAM_OPT_FIFO_WIDTH_SHIFT                    (8U)

#define EDMA_PARAM_OPT_STATIC_MASK                         (0x00000008U)
#define EDMA_PARAM_OPT_STATIC_SHIFT                        (3U)
#define EDMA_PARAM_OPT_STATIC_ENABLE                        (1U)
#define EDMA_PARAM_OPT_STATIC_DISABLE                       (0U)

#define EDMA_PARAM_OPT_SYNC_DIM_MASK                       (0x00000004U)
#define EDMA_PARAM_OPT_SYNC_DIM_SHIFT                      (2U)
#define EDMA_PARAM_OPT_SYNC_DIM_AB                          (1U)
#define EDMA_PARAM_OPT_SYNC_DIM_A                           (0U)

#define EDMA_PARAM_OPT_DST_ADDR_MODE_MASK                  (0x00000002U)
#define EDMA_PARAM_OPT_DST_ADDR_MODE_SHIFT                 (1U)
#define EDMA_PARAM_OPT_DST_ADDR_MODE_CONST                  (1U)
#define EDMA_PARAM_OPT_DST_ADDR_MODE_INCR                   (0U)

#define EDMA_PARAM_OPT_SRC_ADDR_MODE_MASK                  (0x00000001U)
#define EDMA_PARAM_OPT_SRC_ADDR_MODE_SHIFT                 (0U)
#define EDMA_PARAM_OPT_SRC_ADDR_MODE_CONST                  (1U)
#define EDMA_PARAM_OPT_SRC_ADDR_MODE_INCR                   (0U)

#define EDMA_PARAM_A_CNT_MASK                              (0x0000FFFFU)
#define EDMA_PARAM_A_CNT_SHIFT                             (0U)

#define EDMA_PARAM_B_CNT_MASK                              (0xFFFF0000U)
#define EDMA_PARAM_B_CNT_SHIFT                             (16U)

#define EDMA_PARAM_SRC_BIDX_MASK                           (0x0000FFFFU)
#define EDMA_PARAM_SRC_BIDX_SHIFT                          (0U)

#define EDMA_PARAM_DST_BIDX_MASK                           (0xFFFF0000U)
#define EDMA_PARAM_DST_BIDX_SHIFT                          (16U)

#define EDMA_PARAM_LINK_MASK                               (0x0000FFFFU)
#define EDMA_PARAM_LINK_SHIFT                              (0U)

#define EDMA_PARAM_BCNT_RLD_MASK                           (0xFFFF0000U)
#define EDMA_PARAM_BCNT_RLD_SHIFT                          (16U)

#define EDMA_PARAM_SRC_CIDX_MASK                           (0x0000FFFFU)
#define EDMA_PARAM_SRC_CIDX_SHIFT                          (0U)

#define EDMA_PARAM_DST_CIDX_MASK                           (0xFFFF0000U)
#define EDMA_PARAM_DST_CIDX_SHIFT                          (16U)

#define EDMA_PARAM_C_CNT_MASK                              (0x0000FFFFU)
#define EDMA_PARAM_C_CNT_SHIFT                             (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the transfer complete code mode. */
typedef enum edmaParamTccMode
{
    EDMA_PARAM_TCC_MODE_MIN = 0U,
    /**< Minimum transfer completion mode. */
    EDMA_PARAM_TCC_MODE_NORMAL = EDMA_PARAM_TCC_MODE_MIN,
    /**<
     * Normal completion: A transfer is considered completed after the data has
     * been transferred.
     */
    EDMA_PARAM_TCC_MODE_EARLY,
    /**<
     * Early completion: A transfer is considered completed after the EDMA3CC
     * submits a TR to the EDMA3TC. TC may still be transferring data when the
     * interrupt/chain is triggered.
     */
    EDMA_PARAM_TCC_MODE_MAX = EDMA_PARAM_TCC_MODE_EARLY
    /**< Maximum transfer completion mode. */
}edmaParamTccMode_t;

/** \brief Enumerates the transfer synchronization dimension. */
typedef enum edmaParamSyncType
{
    EDMA_PARAM_SYNC_TYPE_MIN = 0U,
    /**< Minimum trigger type of data synchronization. */
    EDMA_PARAM_SYNC_TYPE_A = EDMA_PARAM_SYNC_TYPE_MIN,
    /**< A-synchronized. Each event triggers the transfer of a single array of
     *   ACNT bytes.
     */
    EDMA_PARAM_SYNC_TYPE_AB,
    /**< AB-synchronized. Each event triggers the transfer of BCNT arrays of
     *   ACNT bytes.
     */
    EDMA_PARAM_SYNC_TYPE_MAX = EDMA_PARAM_SYNC_TYPE_AB
    /**< Maximum trigger type of data synchronization. */
}edmaParamSyncType_t;

/** \brief Enumerates the mask of transfer trigger for chaining and interrupt
 *         generation.
 */
typedef enum edmaParamXferTriggerMask
{
    EDMA_PARAM_XFER_TRIGGER_MASK_NONE = 0x0U,
    /**< Transfer completion type is not configured. */
    EDMA_PARAM_XFER_TRIGGER_MASK_INTERMEDIATE = 0x1U,
    /**< Transfer completion type is configured for intermediate. */
    EDMA_PARAM_XFER_TRIGGER_MASK_COMPLETE = 0x2U
    /**< Transfer completion type is configured for intermediate. */
}edmaParamXferTriggerMask_t;

/**
 * \brief Enumerates the privilege level (supervisor versus user) for the
 *        host/CPU/DMA.
 */
typedef enum edmaParamPrivLvl
{
    EDMA_PARAM_PRIV_LVL_USER,
    /**< User level privilege. */
    EDMA_PARAM_PRIV_LVL_SUPERVISOR,
    /**< Supervisor level privilege. */
}edmaParamPrivLvl_t;

/** \brief Enumerates the channel set. */
typedef enum edmaChSet
{
    EDMA_CH_SET_0_31,
    /**< Maximum number of channels is 32. */
    EDMA_CH_SET_32_63
    /**< Indicates set of channels from 33 to 64. */
}edmaChSet_t;

/** \brief Enumerates the type of channels. */
typedef enum edmaChType
{
    EDMA_CH_TYPE_DMA,
    /**< DMA Channel type. */
    EDMA_CH_TYPE_QDMA
    /**< QDMA channel type. */
}edmaChType_t;

/**
 * \brief Structure holding EDMA Parameter RAM Set in User Configurable format.
 */
typedef struct EDMAParamDataAddrOffset
{
    uint32_t addr;
    /**< Starting byte address of Source. */
    int32_t bCntIdx;
    /**< The byte address offset between source arrays within a frame
         (2nd dimension). Valid values range from -32,768 and 32,767. */
    int16_t cCntIdx;
    /**< Signed value specifying the byte address offset between frames within a
         block (3rd dimension). Valid values range from -32,768 and 32,767.
         A-synchronized transfers: The byte address offset from the beginning of
         the last source array in a frame to the beginning of the first source
         array in the next frame.
         AB-synchronized transfers: The byte address offset from the beginning
         of the first source array in a frame to the beginning of the first
         source array in the next frame. */
}EDMAParamDataAddrOffset_t;

/**
 * \brief Structure holding EDMA Parameter RAM Set in User Configurable format.
 */
typedef struct EDMAParamDataSize
{
    uint32_t aCnt;
    /**< Count for 1st Dimension. Unsigned value specifying the number of
         contiguous bytes within an array (first dimension of the transfer).
         Valid values range from 1 to 65 535. */
    uint32_t bCnt;
    /**< Count for 2nd Dimension. Unsigned value specifying the number of frames
         in a block, where a frame is ACNT arrays of ACNT bytes. Valid values
         range from 1 to 65 535.*/
    uint32_t cCnt;
    /**< Count for 3rd Dimension. Unsigned value specifying the number of frames
         in a block, where a frame is BCNT arrays of ACNT bytes. Valid values
         range from 1 to 65 535. */
    uint32_t bCntRld;
    /**< The count value used to reload BCNT when BCNT decrements to 0 (TR is
         submitted for the last array in 2nd dimension). Only relevant in
         A-synchronized transfers. */
}EDMAParamDataSize_t;

/**
 * \brief Structure holding EDMA PaRAM set data buffer configurations.
 */
typedef struct EDMAParamDataConfig
{
    uint32_t addrMode;
    /**< Address from which data is transferred. Take values
         #dmaXferDataAddrMode_t. */
    uint32_t fifoWidth;
    /**< FIFO Width. Applies if either SAM or DAM is set to constant addressing
         mode. Takes values #dmaXferDataFifoWidth_t. */
    EDMAParamDataAddrOffset_t addrOff;
    /**< Starting byte address of Source. */
    EDMAParamDataSize_t size;
    /**< The byte address offset between source arrays within a frame
         (2nd dimension). Valid values range from -32,768 and 32,767. */
    uint32_t syncType;
    /**< Transfer synchronization dimension. Take values #edmaParamSyncType_t */
}EDMAParamDataConfig_t;

/**
 * \brief Structure holding EDMA PaRAM set configurations.
 */
typedef struct EDMAParamConfig
{
    EDMAParamDataConfig_t *pSrc;
    /**< Channel source data. */
    EDMAParamDataConfig_t *pDst;
    /**< Channel destination data. */
    uint32_t privType;
    /**< Privilege level (supervisor versus user) for the host/CPU/DMA that
         programmed this PaRAM set. Takes values #edmaParamPrivLvl_t. */
    uint32_t privId;
    /**< Privilege identification for the external host/CPU/DMA that programmed
         this PaRAM set. Takes values in range 0x0 to 0xF. */
    uint32_t enableLink;
    /**< The PaRAM address containing the PaRAM set to be linked (copied from)
         when the current PaRAM set is exhausted. A value of FFFFh specifies a
         null link. */
    uint32_t enableStatic;
    /**< # FALSE - Set is not static. The PaRAM set is updated or linked after a
         TR is submitted for DMA channels and for non-final transfers in a
         linked list of QDMA transfers
         # TRUE - The PaRAM set is not updated or linked after a TR is submitted
         for isolated QDMA transfers or for the final transfer in a linked list
         of QDMA transfers. */
    uint32_t linkAddr;
    /**< The PaRAM address containing the PaRAM set to be linked (copied from)
         when the current PaRAM set is exhausted. A value of FFFFh specifies a
         null link. */
    uint32_t enableChain;
    /**< # TRUE  - Transfer chaining is enabled.
         # FALSE - Transfer chaining is disabled. */
    uint32_t chainMask;
    /**< Transfer chaining configuration for intermediate and complete chaining.
         Takes values #edmaParamXferTriggerMask_t. */
    uint32_t tccMode;
    /**< Transfer complete code mode. Indicates the point at which a transfer is
         considered completed for chaining and interrupt generation. Takes values
         #edmaParamTccMode_t. */
    uint32_t tcc;
    /**< Transfer complete code is the channel enabled for chaining and interrupt
         generation. */
    uint32_t intrMask;
    /**< Transfer interrupt configuration for intermediate and complete
         chaining. Takes values #edmaParamXferTriggerMask_t. */
}EDMAParamConfig_t;

/**
 * \brief Structure holding channel options parameter.
 */
typedef struct EDMAParamEntryOptConfig
{
    uint32_t srcAddrMode : 1U;
    /**< Source address mode. */
    uint32_t destAddrMode : 1U;
    /**< Starting byte address of Source. */
    uint32_t syncDimension : 1U;
    /**< Transfer synchronization dimension. */
    uint32_t setStatic : 1U;
    /**< Static set. */
    uint32_t rsvd1 : 4U;
    /**< Reserved bits. */
    uint32_t fifoWidth : 3U;
    /**< FIFO Width. Applies if either SAM or DAM is set to constant addressing mode. */
    uint32_t tccMode : 1U;
    /**< Transfer complete code mode. */
    uint32_t tcc : 6U;
    /**< Transfer complete code. */
    uint32_t rsvd2 : 2U;
    /**< Reserved bits. */
    uint16_t enableTcIntr : 1U;
    /**< Transfer complete interrupt enable. */
    uint16_t enableIntrmTcIntr : 1U;
    /**< Intermediate transfer completion interrupt enable. */
    uint16_t emableTcc : 1U;
    /**< Transfer complete chaining enable. */
    uint16_t enableIntrmTcc : 1U;
    /**< Intermediate transfer complete chaining enable. */
    int16_t  prvId : 4U;
    /**< Privilege identification for the external host/CPU/DMA. */
    uint32_t rsvd3 : 3U;
    /**< Reserved bits. */
    int16_t  prvLvl : 1U;
    /**< Privilege level (supervisor versus user) for the host/CPU/DMA. */
}EDMAParamEntryOptConfig_t;

/**
 * \brief Structure holding EDMA Parameter RAM Set in User Configurable format.
 */
typedef struct EDMAParamEntryConfig
{
    EDMAParamEntryOptConfig_t opt;
    /**< OPT field of PaRAM Set. */
    uint32_t srcAddr;
    /**< Starting byte address of Source. */
    uint16_t aCnt;
    /**< Number of bytes in each Array (ACNT). */
    uint16_t bCnt;
    /**< Number of Arrays in each Frame (BCNT). */
    uint32_t destAddr;
    /**< Starting byte address of destination. */
    int16_t  srcBIdx;
    /**< Index between consec. arrays of a Source Frame (SRCBIDX). */
    int16_t  destBIdx;
    /**< Index between consec. arrays of a Destination Frame (DSTBIDX). */
    uint16_t linkAddr;
    /**<
     * Address for linking (AutoReloading of a PaRAM Set).
     * This must point to a valid aligned 32-byte PaRAM set.
     * A value of 0xFFFF means no linking.
     */
    uint16_t bCntReload;
    /**<
     * Reload value of the numArrInFrame (BCNT).
     * Relevant only for A-sync transfers.
     */
    int16_t  srcCIdx;
    /**< Index between consecutive frames of a Source Block (SRCCIDX). */
    int16_t  destCIdx;
    /**< Index between consecutive frames of a Dest Block (DSTCIDX). */
    uint16_t cCnt;
    /**< Number of Frames in a block (CCNT). */
    uint16_t rsvd;
    /**< This field is Reserved. Write zero to this field. */
}EDMAParamEntryConfig_t;

/**
 * \brief Structure holding EDMA Parameter RAM Set in User Configurable format.
 */
typedef struct EDMAParamEntry
{
    uint32_t word1;
    /**< OPT field of PaRAM Set. */
    uint32_t word2;
    /**< Starting byte address of Source. */
    uint32_t word3;
    /**< Number of bytes in each Array (ACNT) and Frame (BCNT). */
    uint32_t word4;
    /**< Starting byte address of destination. */
    uint32_t word5;
    /**< Index between consec. arrays of a Source and Destination Frame. */
    uint32_t word6;
    /**<
     * Address for linking (AutoReloading of a PaRAM Set).
     * This must point to a valid aligned 32-byte PaRAM set.
     * A value of 0xFFFF means no linking.
     * Reload value of the numArrInFrame (BCNT).
     * Relevant only for A-sync transfers.
     */
    uint32_t  word7;
    /**< Index between consecutive frames of a Source and Destination Block. */
    uint32_t word8;
    /**< Number of Frames in a block (CCNT). */
}EDMAParamEntry_t;

/**
 * \brief Structure holding EDMA Parameter RAM Set in User Configurable format.
 */
typedef struct EDMAEvtConfig
{
    uint32_t chNum;
    /**< DMA/QDMA channel number. */
    uint32_t regionId;
    /**< Region the channel is mapped. */
}EDMAEvtConfig_t;

/**
 * \brief Structure holding EDMA Parameter RAM Set in User Configurable format.
 */
typedef struct EDMAChConfig
{
    uint32_t region;
    /**< Region the channel is mapped. */
    uint32_t paramIdx;
    /**< PaRAM set assigned to channel. */
    uint32_t queueNum;
    /**< Queue to be used for channel. */
    uint16_t enableEvt;
    /**< # TRUE  - Enable channel.
         # FALSE - Disable channel. */
    uint16_t enableIntr;
    /**< # TRUE  - Enable interrupt on channel.
         # FALSE - Disable interrupt on channel. */
}EDMAChConfig_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief  This API initializes all regions of EDMA module.
 *
 *  \param  baseAddr Base address of the EDMA module.
 *  \param  region   Region the given channel to be configured.
 */
void EDMAInit(uint32_t baseAddr, uint32_t region);

/**
 *  \brief   This API resets given region of EDMA module.
 *
 *  \param  baseAddr   Base address of the EDMA instance used.
 *  \param  regionId   Region to be reset.
 */
void EDMARegionReset(uint32_t baseAddr, uint32_t regionId);

/**
 * \brief   This API returns the peripheral id of the EDMA module.
 *
 * \param   baseAddr     Base address of the EDMA module.
 *
 * \retval  peripheralId Peripheral id of the EDMA module.
 */
uint32_t EDMAGetPeripheralId(uint32_t baseAddr);

/**
 * \brief   This API checks if the EDMA module supports memory protection.
 *
 * \param   baseAddr Base address of the EDMA module.
 *
 * \retval  TRUE     Memory protection exists for given EDMA module.
 * \retval  FALSE    Memory protection does not exist for given EDMA module.
 */
uint32_t EDMAIsMemProtectionSupported(uint32_t baseAddr);

/**
 * \brief   This API checks if the EDMA module supports channel mapping.
 *
 * \param   baseAddr Base address of the EDMA module.
 *
 * \retval  TRUE     Channel mapping exists for given EDMA module.
 * \retval  FALSE    Channel mapping does not exist for given EDMA module.
 */
uint32_t EDMAIsChMapSupported(uint32_t baseAddr);

/**
 * \brief   This API gives number of memory protected or shadow regions the EDMA
 *          module supports.
 *
 * \param   baseAddr Base address of the EDMA module.
 *
 * \retval  regions  Number of regions exists for given EDMA module.
 */
uint32_t EDMAGetNumRegions(uint32_t baseAddr);

/**
 * \brief   This API gives number of queues or transfer controllers the EDMA
 *          module supports.
 *
 * \param   baseAddr Base address of the EDMA module.
 *
 * \retval  queues   Number of queues exists for given EDMA module.
 */
uint32_t EDMAGetNumQueues(uint32_t baseAddr);

/**
 * \brief   This API gives number of Parameter sets the EDMA module supports.
 *
 * \param   baseAddr     Base address of the EDMA module.
 *
 * \retval  numParamSets Number of parameter RAM sets exist for given EDMA module.
 */
uint32_t EDMAGetNumParamSets(uint32_t baseAddr);

/**
 * \brief   This API gives number of interrupt channels the EDMA module supports.
 *
 * \param   baseAddr  Base address of the EDMA module.
 *
 * \retval  numIntrCh Number of interrupt channels exists for given EDMA module.
 */
uint32_t EDMAGetNumIntrCh(uint32_t baseAddr);

/**
 * \brief   This API gives number of QDMA channels the EDMA module supports.
 *
 * \param   baseAddr    Base address of the EDMA module.
 *
 * \retval  numQdmaCh   Number of QDMA channels exists for given EDMA module.
 */
uint32_t EDMAGetNumQdmaCh(uint32_t baseAddr);

/**
 * \brief   This API gives number of DMA channels the EDMA module supports.
 *
 * \param   baseAddr    Base address of the EDMA module.
 *
 * \retval  numDmaCh    Number of DMA channels exists for given EDMA module.
 */
uint32_t EDMAGetNumDmaCh(uint32_t baseAddr);

/**
 * \brief  This API enables DMA/QDMA channel in the the given shadow region.
 *
 * \param  baseAddr    Base address of the EDMA instance used.
 * \param  shdwRegion  Shadow region the given channel to be configured.
 * \param  chType      Type of Channel (DMA/QDMA) takes values #edmaChType_t
 * \param  chNum       Channel number.
 *
 * \retval TRUE        Successfully enabled channel in the given shadow region.
 * \retval FALSE       Failed to enable channel in the given shadow region.
 */
int32_t EDMAShdwRegionChEnable(uint32_t baseAddr,
                               uint32_t shdwRegion,
                               uint32_t chType,
                               uint32_t chNum);

/**
 * \brief  This API disable DMA/QDMA channel in the the given shadow region.
 *
 * \param  baseAddr    Base address of the EDMA instance used.
 * \param  shdwRegion  Shadow region the given channel to be configured.
 * \param  chType      Type of Channel (DMA/QDMA) takes values #edmaChType_t
 * \param  chNum       Channel number.
 *
 * \retval S_PASS      Successfully disabled channel in the given shadow region.
 * \retval E_FAIL      Failed to disabled channel in the given shadow region.
 */
int32_t EDMAShdwRegionChDisable(uint32_t baseAddr,
                                uint32_t shdwRegion,
                                uint32_t chType,
                                uint32_t chNum);

/**
 * \brief  This API checks if DMA/QDMA channel is assigned to given region.
 *
 * \param  baseAddr    Base address of the EDMA instance used.
 * \param  shdwRegion  Shadow region the given channel to be checked.
 * \param  chType      Type of Channel (DMA/QDMA) takes values #edmaChType_t
 * \param  chNum       Channel number.
 *
 * \retval TRUE        Channel is assigned to the given shadow region.
 * \retval FALSE       Channel is not assigned to the given shadow region.
 */
uint32_t EDMAIsChInShdwRegion(uint32_t baseAddr,
                              uint32_t shdwRegion,
                              uint32_t chType,
                              uint32_t chNum);

/**
 * \brief  This API maps QDMA/DMA channel to the given PaRAM set.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  chType   Type of Channel (DMA/QDMA) takes values #edmaChType_t
 * \param  chNum    Channel number.
 * \param  paramSet Specifies the paramSet to be mapped for given DMA channel.
 *
 * \retval S_PASS   Successfully mapped QDMA/DMA channel to the given paRAM set.
 * \retval E_FAIL   Failed to map QDMA/DMA channel to the given paRAM set.
 */
int32_t EDMAChToParamSetMap(uint32_t baseAddr,
                            uint32_t chType,
                            uint32_t chNum,
                            uint32_t paramSet);

/**
 * \brief  This API sets the Trigger word for the specific QDMA channel in the
 *         QCHMAP Register. Default QDMA trigger word is CCNT.
 *
 * \param  baseAddr  Base address of the EDMA instance used.
 * \param  qdmaChNum QDMA channel number.
 * \param  triggerWord  The Trigger Word for the QDMA channel. Trigger Word is the
 *                   word in the PaRAM Register Set which, when written to by CPU,
 *                   will start the QDMA transfer automatically.
 *
 * \retval S_PASS   Successfully mapped QDMA/DMA channel to the given event queue.
 * \retval E_FAIL   Failed to map QDMA/DMA channel to the given event queue.
 */
void EDMASetQdmaTriggerWord(uint32_t baseAddr,
                            uint32_t qdmaChNum,
                            uint32_t triggerWord);

/**
 * \brief  This API maps QDMA/DMA channel to the given event queue.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  chType   Type of Channel (DMA/QDMA) takes values #edmaChType_t
 * \param  chNum    Channel number.
 * \param  queueNum Specifies the queue to be mapped for given DMA channel.
 *
 * \retval S_PASS   Successfully mapped QDMA/DMA channel to the given event queue.
 * \retval E_FAIL   Failed to map QDMA/DMA channel to the given event queue.
 */
int32_t EDMAChToEvtQueueMap(uint32_t baseAddr,
                            uint32_t chType,
                            uint32_t chNum,
                            uint32_t queueNum);

/**
 * \brief  This API clears the missed event status for channel in given region.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  region   Region the given channel to be configured.
 * \param  chType   Type of Channel (DMA/QDMA) takes values #edmaChType_t
 * \param  chNum    Channel number.
 *
 * \retval S_PASS   Successfully cleared miss event status.
 * \retval E_FAIL   Failed to clear miss event status.
 */
int32_t EDMAChMissEvtClear(uint32_t baseAddr,
                           uint32_t region,
                           uint32_t chType,
                           uint32_t chNum);

/**
 * \brief  This API gives status of the missed event for given QDMA/DMA channel.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  chType   Type of Channel (DMA/QDMA) takes values #edmaChType_t
 * \param  chNum    Channel number.
 *
 * \retval TRUE     Miss event occurred.
 * \retval FALSE    No missed event.
 */
uint32_t EDMAEvtMissStatus(uint32_t baseAddr,
                           uint32_t chType,
                           uint32_t chNum);

/**
 * \brief  This API clears the completion code error status.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 */
void EDMAComplCodeErrClear(uint32_t baseAddr);

/**
 * \brief  This API clears the threshold error status for given queue.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  queueNum Specifies the queue to be mapped for given DMA channel.
 *
 * \retval S_PASS   Successfully cleared threshold error status for given queue.
 * \retval E_FAIL   Failed to clear threshold error status for given queue.
 */
int32_t EDMAQueueThresholdErrClear(uint32_t baseAddr, uint32_t queueNum);

/**
 * \brief  This API gives the completion code error status.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 *
 * \retval TRUE     Total number of allowed TCCs has been reached.
 * \retval FALSE    Total number of allowed TCCs outstanding has not been reached.
 */
uint32_t EDMAComplCodeErrStatus(uint32_t baseAddr);

/**
 * \brief  This API gives the threshold error status for given queue.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  queueNum Specifies the queue to be mapped for given DMA channel.
 *
 * \retval TRUE     Watermark/threshold has been exceeded.
 * \retval FALSE    Watermark/threshold has not been exceeded.
 */
uint32_t EDMAQueueThresholdErrStatus(uint32_t baseAddr, uint32_t queueNum);

/**
 * \brief  This API manually sets event to initiate transfer on DMA channel in
 *         the the given shadow region.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  region   Region the given channel to be configured.
 * \param  dmaChNum DMA Channel number.
 *
 * \retval S_PASS   Successfully set event of channel in the given region.
 * \retval E_FAIL   Failed to set event of channel in the given region.
 */
int32_t EDMASetEvt(uint32_t baseAddr, uint32_t region, uint32_t dmaChNum);

/**
 * \brief  This API clears event of DMA channel in the given global or shadow
 *         region.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  region   Region the given channel to be configured.
 * \param  dmaChNum DMA Channel number.
 *
 * \retval S_PASS   Event of channel in given region is asserted.
 * \retval E_FAIL   Event of channel in given region is not asserted.
 */
int32_t EDMAEvtClear(uint32_t baseAddr, uint32_t region, uint32_t dmaChNum);

/**
 * \brief  This API gives event status of DMA channel in the given global or
 *         shadow region.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  region   Region the given channel to be configured.
 * \param  dmaChNum DMA Channel number.
 *
 * \retval TRUE     Successfully cleared event of channel in given region.
 * \retval FALSE    Failed to clear event of channel in the given region.
 */
uint32_t EDMAEvtStatus(uint32_t baseAddr, uint32_t region, uint32_t dmaChNum);

/**
 * \brief  This API enables event of channel in the given global or shadow
 *         region.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  region   Region the given channel to be configured.
 * \param  chType   Type of Channel (DMA/QDMA) takes values #edmaChType_t
 * \param  chNum    Channel number.
 *
 * \retval S_PASS   Successfully enabled event of channel in given region.
 * \retval E_FAIL   Failed to enable event of channel in the given region.
 */
int32_t EDMAEvtEnable(uint32_t baseAddr,
                      uint32_t region,
                      uint32_t chType,
                      uint32_t chNum);

/**
 * \brief  This API disables event of channel in the given global or shadow
 *         region.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  region   Region the given channel to be configured.
 * \param  chType   Type of Channel (DMA/QDMA) takes values #edmaChType_t
 * \param  chNum    Channel number.
 *
 * \retval S_PASS   Successfully disables event of channel in given region.
 * \retval E_FAIL   Failed to disable event of channel in the given region.
 */
int32_t EDMAEvtDisable(uint32_t baseAddr,
                       uint32_t region,
                       uint32_t chType,
                       uint32_t chNum);

/**
 * \brief  This API enables interrupt of a channel in the given global or shadow
 *         region.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  region   Region the given channel to be configured.
 * \param  chNum    Channel number.
 *
 * \retval S_PASS   Successfully enabled interrupt of channel in given region.
 * \retval E_FAIL   Failed to enable interrupt of channel in the given region.
 */
int32_t EDMAIntrEnable(uint32_t baseAddr, uint32_t region, uint32_t chNum);

/**
 * \brief  This API disables interrupt of a channel in the given global or shadow
 *         region.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  region   Region the given channel to be configured.
 * \param  chNum    Channel number.
 *
 * \retval S_PASS   Successfully disabled interrupt of channel in given region.
 * \retval E_FAIL   Failed to disable interrupt of channel in the given region.
 */
int32_t EDMAIntrDisable(uint32_t baseAddr, uint32_t region, uint32_t chNum);

/**
 * \brief  This API gives pending interrupt of a set of channel in the given
 *         global or shadow region.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  region   Region the given channel to be configured.
 * \param  chSet    Set of channel number.
 *                  from 0 to 31
 *                  from 32 to 64
 *
 * \retval status   Pending interrupt status for set of channel in given region.
 */
uint32_t EDMAIntrStatus(uint32_t baseAddr, uint32_t region, uint32_t chSet);

/**
 * \brief  This API clear pending interrupt of a channel in the given global or
 *         shadow region.
 *
 * \param  baseAddr Base address of the EDMA instance used.
 * \param  region   Region the given channel to be configured.
 * \param  chNum    Channel number.
 *
 * \retval S_PASS   Successfully cleared pending interrupt of channel in given region.
 * \retval E_FAIL   Failed to clear pending interrupt of channel in the given region.
 */
int32_t EDMAIntrClear(uint32_t baseAddr, uint32_t region, uint32_t chNum);

/**
 * \brief   This API takes a PaRAM Set as input and copies it onto the given
 *          PaRAM Set index.
 *
 * \param   baseAddr     Base address of the EDMA instance used.
 * \param   paRamIdx     PaRAM index to be updated.
 * \param   pParamEntry  Parameter RAM set to be copied to given PaRAM index.
 *
 * \retval  S_PASS       Successfully updated PaRAM set entry.
 * \retval  E_FAIL       Failed update of PaRAM set entry.
 */
int32_t EDMASetParamEntry(uint32_t baseAddr,
                          uint32_t paRamIdx,
                          EDMAParamEntry_t* pParamEntry);

/**
 * \brief   This API gives PaRAM Set of given index.
 *
 * \param   baseAddr     Base address of the EDMA instance used.
 * \param   paRamIdx     PaRAM index to be updated.
 * \param   pParamEntry  Parameter RAM set to be copied to given PaRAM index.
 *
 * \retval  S_PASS       Successfully updated PaRAM set entry.
 * \retval  E_FAIL       Failed update of PaRAM set entry.
 */
int32_t EDMAGetParamEntry(uint32_t baseAddr,
                          uint32_t paRamIdx,
                          EDMAParamEntry_t* pParamEntry);

/**
 * \brief   This API resets the given PaRAM Set index.
 *
 * \param   baseAddr     Base address of the EDMA instance used.
 * \param   paRamIdx     PaRAM index to be updated.
 *
 * \retval  S_PASS       PaRAM set entry reset success.
 * \retval  E_FAIL       Failed to reset PaRAM set entry.
 */
int32_t EDMAParamReset(uint32_t baseAddr, uint32_t paRamIdx);

/**
 * \brief   This API resets the given PaRAM Set index.
 *
 * \param   baseAddr     Base address of the EDMA instance used.
 * \param   paRamIdx     PaRAM index to be updated.
 *
 * \retval  S_PASS       PaRAM set entry reset success.
 * \retval  E_FAIL       Failed to reset PaRAM set entry.
 */
int32_t EDMASetParamDummy(uint32_t baseAddr, uint32_t paRamIdx);

/**
 * \brief   This API takes a PaRAM Set as input and copies it onto the given
 *          PaRAM Set index.
 *
 * \param   baseAddr     Base address of the EDMA instance used.
 * \param   paRamIdx     PaRAM index to be updated.
 * \param   pParamConfig Parameter RAM set to be copied to given PaRAM index.
 *
 * \retval  S_PASS       Successfully updated PaRAM set entry.
 * \retval  E_FAIL       Failed update of PaRAM set entry.
 */
int32_t EDMAParamConfig(uint32_t baseAddr,
                        uint32_t paRamIdx,
                        EDMAParamConfig_t *pParamConfig);

/**
 * \brief   This API takes a PaRAM Set as input and copies it onto the given
 *          PaRAM Set index.
 *
 * \param   baseAddr     Base address of the EDMA instance used.
 * \param   paRamIdx     PaRAM index to be updated.
 * \param   pParamConfig Parameter RAM set to be copied to given PaRAM index.
 *
 * \retval  S_PASS       Successfully updated PaRAM set entry.
 * \retval  E_FAIL       Failed update of PaRAM set entry.
 */
int32_t EDMAParamXferConfig(uint32_t baseAddr,
                            uint32_t paRamIdx,
                            EDMAParamConfig_t *pParamConfig);

/**
 * \brief   This API takes a PaRAM Set as input and copies it onto the given
 *          PaRAM Set index.
 *
 * \param   baseAddr     Base address of the EDMA instance used.
 * \param   paRamIdx     PaRAM index to be updated.
 * \param   pParamConfig Parameter RAM set to be copied to given PaRAM index.
 *
 * \retval  S_PASS       Successfully updated PaRAM set entry.
 * \retval  E_FAIL       Failed update of PaRAM set entry.
 */
int32_t EDMAParamLinkConfig(uint32_t baseAddr,
                            uint32_t paRamIdx,
                            EDMAParamConfig_t *pParamConfig);

/**
 * \brief   This API takes a PaRAM Set as input and copies it onto the given
 *          PaRAM Set index.
 *
 * \param   baseAddr     Base address of the EDMA instance used.
 * \param   paRamIdx     PaRAM index to be updated.
 * \param   pParamConfig Parameter RAM set to be copied to given PaRAM index.
 *
 * \retval  S_PASS       Successfully updated PaRAM set entry.
 * \retval  E_FAIL       Failed update of PaRAM set entry.
 */
int32_t EDMAParamChainConfig(uint32_t baseAddr,
                             uint32_t paRamIdx,
                             EDMAParamConfig_t *pParamConfig);

/**
 * \brief   This API takes a PaRAM Set as input and copies it onto the given
 *          PaRAM Set index.
 *
 * \param   baseAddr     Base address of the EDMA instance used.
 * \param   paRamIdx     PaRAM index to be updated.
 * \param   pParamConfig Parameter RAM set to be copied to given PaRAM index.
 *
 * \retval  S_PASS       Successfully updated PaRAM set entry.
 * \retval  E_FAIL       Failed update of PaRAM set entry.
 */
int32_t EDMAParamIntrConfig(uint32_t baseAddr,
                            uint32_t paRamIdx,
                            EDMAParamConfig_t *pParamConfig);

/**
 * \brief   This API takes a PaRAM Set as input and copies it onto the given
 *          PaRAM Set index.
 *
 * \param   baseAddr     Base address of the EDMA instance used.
 * \param   paRamIdx     PaRAM index to be updated.
 * \param   pParamConfig Parameter RAM set to be copied to given PaRAM index.
 *
 * \retval  S_PASS       Successfully updated PaRAM set entry.
 * \retval  E_FAIL       Failed update of PaRAM set entry.
 */
int32_t EDMAGetParamConfig(uint32_t baseAddr,
                           uint32_t paRamIdx,
                           EDMAParamConfig_t *pParamConfig);

/**
 * \brief   This API configures given channel.
 *
 * \param   baseAddr     Base address of the EDMA instance used.
 * \param   chNum        PaRAM index to be updated.
 * \param   chType       Type of Channel (DMA/QDMA) takes values #edmaChType_t
 * \param   pChConfig    Channel configurations.
 *
 * \retval  S_PASS       Channel configuration successful.
 * \retval  E_FAIL       Failed to configure channel.
 */
uint32_t  EDMAChConfig(uint32_t baseAddr,
                       uint32_t chType,
                       uint32_t chNum,
                       EDMAChConfig_t* pChConfig);

/**
 * \brief   This API resets given channel.
 *
 * \param   baseAddr     Base address of the EDMA instance used.
 * \param   region       Shadow region the given channel to be configured.
 * \param   chType       Type of Channel (DMA/QDMA) takes values #edmaChType_t
 * \param   chNum        PaRAM index to be updated.
 *
 * \retval  S_PASS       Channel reset successful.
 * \retval  E_FAIL       Failed to reset channel.
 */
uint32_t  EDMAChReset(uint32_t baseAddr,
                      uint32_t region,
                      uint32_t chType,
                      uint32_t chNum);

/**
 *  \brief    Start EDMA transfer on the specified channel.
 *
 *  \details  There are multiple ways to trigger an EDMA3 transfer. The
 *            triggering mode option allows choosing from the available
 *            triggering modes: Event,Manual or QDMA.
 *            In event triggered, a peripheral or an externally generated event
 *            triggers the transfer. This API clears the Event and Event Miss
 *            Register and then enables the DMA channel by writing to the EESR.
 *            In manual triggered mode, CPU manually triggers a transfer by
 *            writing a 1 in the Event Set Register ESR. This API writes to the
 *            ESR to start the transfer.
 *            In QDMA triggered mode, a QDMA transfer is triggered when a CPU
 *            (or other EDMA3 programmer) writes to the trigger word of the QDMA
 *            channel PaRAM set (auto-triggered) or when the EDMA3CC performs a
 *            link update on a PaRAM set that has been mapped to a QDMA channel
 *            (link triggered). This API enables the QDMA channel by writing to
 *            the QEESR register.
 *
 * \param baseAddr Base address of the EDMA instance used.
 * \param region   Region the given channel to be configured.
 * \param chNum    PaRAM index to be updated.
 * \param triggerMode Mode of triggering start of transfer (Manual, QDMA or Event).
 *                 trigMode can have values #dmaXferTriggerType_t.
 *
 * \retval  S_PASS Channel reset successful.
 * \retval  E_FAIL Failed to reset channel.
 */
int32_t EDMATransferStart(uint32_t baseAddr,
                          uint32_t region,
                          uint32_t chNum,
                          uint32_t triggerMode);

/**
 * \brief   Stop DMA transfer on the specified channel.
 *
 *          There are multiple ways by which an EDMA3 transfer could be
 *          triggered. The triggering mode option allows choosing from the
 *          available triggering modes.
 *          To disable a channel which was previously triggered in manual mode,
 *          this API clears the Secondary Event Register and Event Miss
 *          Register, if set, for the specific DMA channel.
 *          To disable a channel which was previously triggered in QDMA mode,
 *          this API clears the QDMA Event Enable Register, for the specific
 *          QDMA channel.
 *          To disable a channel which was previously triggered in event mode,
 *          this API clears the Event Enable Register, Event Register,
 *          Secondary Event Register and Event Miss Register, if set, for the
 *          specific DMA channel.
 *
 * \param baseAddr Base address of the EDMA instance used.
 * \param region   Region the given channel to be configured.
 * \param chNum    PaRAM index to be updated.
 * \param triggerMode Mode of triggering start of transfer (Manual, QDMA or Event).
 *                 trigMode can have values #dmaXferTriggerType_t.
 *
 * \retval  S_PASS Channel reset successful.
 * \retval  E_FAIL Failed to reset channel.
 */
int32_t EDMATransferStop(uint32_t baseAddr,
                         uint32_t region,
                         uint32_t chNum,
                         uint32_t triggerMode);

/* ========================================================================== */
/*                   Deprecated Function Declarations                         */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef EDMA_H_ */
