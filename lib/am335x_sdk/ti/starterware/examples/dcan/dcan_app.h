/**
 * \file      dcan_app.h
 *
 * \brief     This file contains the function declarations and data structures
 *            corresponding to DCAN application.
 *
 */

/**
 * \copyright Copyright (C) 2014 Texas Instruments Incorporated -
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

#ifndef DCAN_APP_H_
#define DCAN_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "interrupt.h"
#include "hw_types.h"
#include "hw_dcan.h"
#include "edma.h"
#include "dma_utils_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/**
 * \name    Macros used by DCAN application functions.
 */

/** @{ */
/** \brief DCAN bit time calculation maximum error value.
 */
#define CAN_CALC_MAX_ERROR              (50U)

/** \brief Bitrate error warning value.
 */
#define BIT_RATE_ERR_WARN               (2U)

/** \brief Bitrate error maximum value.
 */
#define BIT_RATE_ERR_MAX                (1U)

/** \brief Macro used to extract bit rate prescaler value.
 */
#define EXTRACT_BRPE_VAL                (0x3C0U)

/** \brief Macro used to check no bit rate error.
 */
#define NO_BIT_RATE_ERR                 (3U)

/** \brief Shift value used for bit rate prescaler.
 */
#define BRPE_SHIFT                      (10U)
/** @} */

/**
 * \name    Macros used by DCAN application for selecting the different
 *          frame parameters.
 */

/** @{ */
/** \brief Configure data frame.
 */
#define DCAN_DATA_FRAME                 (0x00000001U)

/** \brief Configure frame with extended ID.
 */
#define DCAN_EXT_FRAME                  (0x00000002U)

/** \brief Configure message direction for transmit.
 */
#define DCAN_MSG_TX_DIR                 (0x00000004U)

/** \brief Configure message direction for receive.
 */
#define DCAN_MSG_RX_DIR                 (0x00000008U)
/** @} */

/**
 * \name    Macros used by DCAN application for DMA operations.
 */

/** @{ */
/** \brief Base address of EDMA Channel Controller.
 */
#define EDMA_TPCC_BASE                  (0x49000000)

/** \brief DCAN frame data size.
 */
#define DCAN_FRAME_SIZE                 8
/** @} */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding DCAN interrupt configuration parameters. */
typedef struct dcanAppIntrCfgObj
{
    intcTrigType_t trigType;
    /**< Type of interrupt Edge/Level. */
    uint32_t intrLine;
    /**< Interrupt line number. */
    uint32_t intrPriority;
    /**< Interrupt priority level. */
    uint32_t enableSecureIntr;
    /**< Secure Interrupt or not */
    volatile uint32_t errVal;
    /**< Value to hold the error value. */
    volatile uint32_t txCtrl;
    /**< Message control to check if transmit frame. */
    volatile uint32_t rxCtrl;
    /**< Message control to check if receive frame. */
    volatile uint32_t intrCount;
    /**< Variable to control the flow between ISR and application. */
    volatile uint32_t totalFrames;
    /**< Variable to check the total frames. */
    volatile uint32_t frameLen;
    /**< Variable to check the frame length. */
    void (*pFnIntrHandler)(uint32_t intrId, uint32_t cpuId, void* pUserParam);
    /**< Function pointer to Interrupt handler which needs to be
     *  registered with the interrupt Controller.- Application needs
     *  to initialize this. If set to null then polling Mode is assumed
     */
}dcanAppIntrCfgObj_t;

/** \brief Structure holding control parameters for DCAN application. */
typedef struct dcanAppCtrl
{
    uint32_t commType;
    /**< Transmit/receive CAN frames. */
    uint32_t frame;
    /**< Single/multiple frames. */
    uint32_t ctrlParams;
    /**< Control parameters. */
    uint32_t canId;
    /**< CAN frame ID. */
    uint32_t dataLengthCode;
    /**< CAN frame data length code. */
    uint32_t *pData;
    /**< Pointer to data buffer. */
    uint32_t appLoopBk;
    /**< Variable to check if loopback is selected. */
}dcanAppCtrl_t;

/** \brief Structure holding the DCAN object data structure. */
typedef struct dcanAppCfgObj
{
    uint32_t instNum;
    /**< DCAN instance number. */
    uint32_t instAddr;
    /**< DCAN instance address. */
    uint32_t inputClk;
    /**< Input clock to DCAN in MHz. */
    uint32_t bitRate;
    /**< Bitrate on DCAN bus. */
    uint32_t maxMsgObjs;
    /**< Maximum no. of message objects supported. */
    uint32_t msgObjNum;
    /**< Message object number. */
    dcanAppIntrCfgObj_t appIntrCfg;
    /**< DCAN Interrupt configuration structure. */
    dcanAppCtrl_t appCtrl;
    /**< DCAN control structure which shall allow user to
         1) Transmit/receive frames.
         2) Transmit single/multiple frames.
    */
}dcanAppCfgObj_t;

/**
 *  \brief Structure defining the parameters for data, interrupt, chain and link
 *         configuration of a transfer.
 */
typedef struct DcanAppDmaCfg
{
    uint32_t             dmaType;
    /**< Type of DMA. */
    uint32_t             frameCnt;
    /**< Number of frames. */
    dmaUtilsEvtInfo_t    rxEvtInfo;
    /**< DCAN RX event configuration. */
    dmaUtilsEvtInfo_t    txEvtInfo;
    /**< DCAN RX event configuration. */
    DMACallBackFxn       pFxnCallBack;
    /**< Call back function to handle DMA status. */
} DcanAppDmaCfg_t;

/**< /brief Structure holding the DCAN application related DMA configuration */
typedef struct DcanAppCfg
{
    uint32_t            enableDma;
    /**< Enable Interrupt */
    DcanAppDmaCfg_t     dmaCfg;
    /**< DCAN DMA Configuration Structure */
} DcanAppCfg_t;

/**< /brief Structure holding the DCAN application related DMA data */
typedef struct DcanAppObj
{
    DcanAppCfg_t         dcanAppCfg;
    /**< DCAN application Configuration Structure */
    uint32_t             instNum;
    /**< DCAN instance number */
    uint32_t             instAddr;
    /**< DCAN instance address */
} DcanAppObj_t;

typedef enum DcanDmaEvt
{
    DCAN_DMA_EVT_TX = 0U,
    /**< RX DMA events. */
    DCAN_DMA_EVT_RX,
    /**< RX DMA events. */
}DcanDmaEvt_t;

/** \brief Enum to choose DCAN mode of operation. */
typedef enum DcanMode
{
    DCAN_MANUAL_MODE = 0U,
    /**< Transmit frames one by one manually. */
    DCAN_DMA_MODE
    /**< Use DMA for DCAN operations. */
}DcanMode_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* Global structure containing the IP configuration defaults */
extern DcanAppObj_t DCANAPPOBJ_DEFAULT;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief    DCAN IP configuration initialization function.
 *
 * \details  This function configures the DCAN controller with the user passed
 *           values.
 *
 * \param    pCfgDcan      Pointer to the DCAN configuration object.
 *
 * \retval   S_PASS        DCAN initialization successful.
 * \retval   E_FAIL        DCAN initialization failed.
 */
int32_t DCANAppInit(dcanAppCfgObj_t *pCfgDcan);

/**
 * \brief   This function will configure DCAN for DMA operation.
 *
 * \param   baseAddr      Base Address of the DCAN Module Registers.
 * \param   enableDma     Enable/disable loopback mode and DMA for DCAN.
 *          enableDma will take the following values.
 *          -# TRUE - Enable Dma.
 *          -# FALSE - Disable Dma.
 */
void DCANAppDmaConfig(uint32_t baseAddr, uint32_t enableDma);

/**
 * \brief   Invalidate a DCAN message object.
 *
 * \param   baseAddr      Base Address of the DCAN Module Registers.
 * \param   msgObjNum     Message object number.
 * \param   ifRegNum      Interface register set used.
 */
void DCANAppInvalidateMsgObject(uint32_t baseAddr,
                               uint32_t msgObjNum,
                               uint32_t ifRegNum);

/**
 * \brief   This function will configure a message object in the DCAN message
 *          RAM.
 *
 * \param   pObj          Pointer to the DCAN application configuration
 *                        structure.
 * \param   mode          DCAN mode of operation
 *          mode will take the following values
 *          -# DCAN_MANUAL_MODE - No DMA is used.
 *          -# DCAN_DMA_MODE - DMA is used.
 */
void DCANAppMsgObjectConfig(dcanAppCfgObj_t *pObj, uint32_t mode);

/**
 * \brief   This function will start the DCAN message transfer.
 *
 * \param   pObj          Pointer to the DCAN application configuration
 *                        structure.
 **/
void DCANAppStartTransfer(dcanAppCfgObj_t *pObj);

/**
 * \brief   This function will stop the DCAN message transfer.
 *
 * \param   pObj          Pointer to the DCAN application configuration
 *                        structure.
 **/
void DCANAppStopTransfer(dcanAppCfgObj_t *pObj);

/**
 * \brief   This function will clear the interrupt pending status
 *          of receive message objects after a new message is received.
 *          This will clear the interrupt pending status of the message
 *          object represented by msgObjNum.
 *
 * \param   baseAddr      Base Address of the DCAN Module Registers.
 * \param   msgObjNum     Message object number.
 * \param   ifRegNum      Interface register set used.
 *
 */
void DCANAppIntrClear(uint32_t baseAddr,
                      uint32_t msgObjNum,
                      uint32_t ifRegNum);

/**
 * \brief   This function will disable the transmit interrupt of a DCAN
 *          message object.
 *
 * \param   baseAddr      Base Address of the DCAN Module Registers.
 * \param   msgObjNum     Message object number.
 * \param   ifRegNum      Interface register set used.
 *
**/
void DCANAppTxIntrDisable(uint32_t baseAddr,
                          uint32_t msgObjNum,
                          uint32_t ifRegNum);

/**
 * \brief   Read data from DCAN message object.
 *
 * \param   baseAddr      Base Address of the DCAN Module Registers.
 * \param   msgObjNum     Message object number.
 * \param   pData         Pointer to fetch data bytes from data registers.
 * \param   ifRegNum      Interface register set used.
 *
*/
void DCANAppReadMsgObjData(uint32_t baseAddr,
                           uint32_t msgObjNum,
                           uint32_t* pData,
                           uint32_t ifRegNum);

/**
 * \brief   This function will disable the receive interrupt of a DCAN
 *          message object.
 *
 * \param   baseAddr      Base Address of the DCAN Module Registers.
 * \param   msgObjNum     Message object number.
 * \param   ifRegNum      Interface register set used.
 *
 */
void DCANAppRxIntrDisable(uint32_t baseAddr,
                          uint32_t msgObjNum,
                          uint32_t ifRegNum);

/**
 * \brief   This API initializes the DMA instance for use.
 *
 * \param   frameCount    Number of frames.
 *
 * \retval  None
 **/
void DcanAppDmaInitialize(uint32_t frameCount);

/**
 * \brief   This API enables and configures the the DMA for DCAN data Transfer.
 *
 * \param   psrcBuffer    Start address of source buffer to be transmitted.
 * \param   pdstBuffer    Start address of destination buffer to be received.
 * \param   frameLength   Length of data transferred per DMA event.
 *
 * \retval  None
 **/
void DcanAppDmaTransfer(uint8_t* srcBuffer, uint8_t* dstBuffer, uint32_t frameLength);

/**
 * \brief   This API returns the status of frame reception completion.
 *
 * \retval  TRUE          DCAN frame reception complete.
 * \retval  FALSE         DCAN frame reception incomplete.
 **/
uint32_t DcanAppDmaReceptionCompleteStatus();

/**
 * \brief   Setup DMA for DCAN RX.
 *
 * \param   pObj          Pointer to the DCAN app configuration.
 * \param   pBuf          Buffer to which received bytes shall be copied.
 * \param   bytesPerEvt   Number bytes for which a DCAN DMA event is generated.
 *
 * \retval  S_PASS        DMA configuration for DCAN RX is successful.
 * \retval  E_FAIL        Failed to configure DMA for DCAN RX.
 *
 */
int32_t DcanAppDmaRxSetup(DcanAppObj_t *pObj,
                          uint8_t *pBuf,
                          uint32_t bytesPerEvt);

/**
 * \brief   Setup DMA for DCAN TX.
 *
 * \param   pObj          Pointer to the DCAN app configuration.
 * \param   pBuf          Buffer from which bytes shall be transmitted.
 * \param   bytesPerEvt   Number bytes for which a DCAN DMA event is generated.
 *
 * \retval  S_PASS        DMA configuration for DCAN TX is successful.
 * \retval  E_FAIL        Failed to configure DMA for DCAN TX.
 *
 */
int32_t DcanAppDmaTxSetup(DcanAppObj_t *pObj,
                          uint8_t *pBuf,
                          uint32_t bytesPerEvt);

/**
 * \brief   Start DCAN DMA transfer.
 *
 * \param   pObj        Pointer to the DCAN app configuration.
 * \param   evt         DCAN transfer event to be initiated.
 *
 * \retval  S_PASS      DCAN transfer initiation successful.
 * \retval  E_FAIL      Failed to initiate DCAN transfer.
 */
int32_t DcanAppDmaXferStart(DcanAppObj_t *pObj, uint32_t evt);

/**
 * \brief   Stop DCAN DMA transfer.
 *
 * \param   pObj        Pointer to the DCAN app configuration.
 * \param   evt         DCAN transfer event to be terminated.
 *
 * \retval  S_PASS      DCAN transfer termination successful.
 * \retval  E_FAIL      Failed to terminate DCAN transfer.
 */
int32_t DcanAppDmaXferStop(DcanAppObj_t *pObj, uint32_t evt);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef DCAN_APP_H_ */
