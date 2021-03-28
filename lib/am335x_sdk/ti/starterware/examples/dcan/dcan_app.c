/**
 * \file   dcan_app.c
 *
 * \brief  Source file containing the DCAN IP related configuration functions.
 *         These functions will be called by example application.
 *
 */

/**
 *  \copyright Copyright (C) 2014 Texas Instruments Incorporated -
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "soc_control.h"
#include "chipdb.h"
#include "pinmux.h"
#include "error.h"
#include "console_utils.h"
#include "interrupt.h"
#include "prcm.h"
#include "dcan.h"
#include "soc.h"
#include "board.h"
#include "misc.h"
#include "dma.h"
#include "dma_utils.h"

/* Application header files */
#include "dcan_app.h"

#ifdef RTOS_BUILD
#include <ti/osal/RegisterIntr.h>
#endif

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define DCAN_ERROR_OCCURED                (0x8000U)
#define DCAN_NO_INTR_PENDING              (0x00000000U)
#define DCAN_INST_NUM                     (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**< \brief Structure holding the DCAN bit time configuration data structure. */
typedef struct dcanBitTimeParams{
    uint32_t bitRate;
    /**< Bit rate in bits/second. */
    uint32_t samplePnt;
    /**< Sample point. */
    unsigned long timeQuanta;
    /**< Time quanta in nanoseconds. */
    uint32_t propSeg;
    /**< Propagation segment in time quanta. */
    uint32_t phaseSeg1;
    /**< Phase buffer segment 1 in time quanta. */
    uint32_t phaseSeg2;
    /**< Phase buffer segment 2 in time quanta. */
    uint32_t syncJumpWidth;
    /**< Synchronisation jump width in time quanta. */
    uint32_t bitRatePrescaler;
    /**< Bit-rate prescaler. */
    uint32_t tseg1Min;
    /**< Time segment 1 = prop_seg + phase_seg1 */
    uint32_t tseg1Max;
    /**< Time segment 1 = prop_seg + phase_seg1 */
    uint32_t tseg2Min;
    /**< Time segment 2 = phase_seg2 */
    uint32_t tseg2Max;
    /**< Time segment 2 = phase_seg2 */
    uint32_t syncJumpWidthMax;
    /**< Synchronisation jump width maximum. */
    uint32_t bitRatePrescalerMin;
    /**< Bit-rate prescaler minimum value. */
    uint32_t bitRatePrescalerMax;
    /**< Bit-rate prescaler maximum value. */
    uint32_t bitRatePrescalerInc;
    /**< Bit-rate prescaler incremental value. */
}dcanBitTimeParams_t;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Configure the DCAN interrupts to interrupt controller.
 *
 * \param   pCfgDcan      Pointer to the DCAN configuration structure.
 *          pCfgDcan will point to structure of type
 *          #dcanAppCfgObj_t
 *
 * \retval  S_PASS         Interrupt configuration successful.
 * \retVal  E_FAIL         Interrupt configuration failed.
 *
 */
static int32_t DcanAppIntrConfig(dcanAppCfgObj_t *pCfgDcan);

/**
 * \brief   DCAN Interrupt 0 line service routine. This function will clear the
 *          status of the Tx/Rx message object interrupts. Perform error
 *          handling if error occurs. Handle the transmit interrupts and load
 *          the received data in buffer.
 *
 * \param   intrId         Interrupt ID.
 * \param   cpuId          CPU ID.
 * \param   pUserParam     User parameters.
 */
#ifdef RTOS_BUILD
static void DcanAppIsr(uintptr_t pUserParam);
#else
static void DcanAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);
#endif

/**
 * \brief   This function takes I/P Clk frequency, required bit-rate on the
 *          CAN bus and calculates the value to be programmed to BTR register
 *          and sends the BTR value to 'DCANBitTimeConfig' API.
 *
 * \param   baseAddr       Base Address of the DCAN Module Registers.
 * \param   clkFreq        I/P clock frequency to DCAN controller.
 * \param   bitRate        Required bit-rate on the CAN bus.
 *
 * \retval  errVal         Returns the error value if error is present.
 */
uint32_t DcanSetBitTime(uint32_t baseAddr,
                        uint32_t clkFreq,
                        uint32_t bitRate);

/**
 * \brief   This function will calculate the bit-timing parameters for the
 *          DCAN controller based on the input frequency and required bit-rate
 *          on the CAN bus.
 *
 * \param   pBitTimeParam  Pointer to dcanBitTimeParams_t structure.
 * \param   clkFreq        Clock frequency to DCAN controller in MHz.
 *
 * \retval  errVal         Returns the error value if error is present.
 */
uint32_t DcanBitTimeCalculator(dcanBitTimeParams_t *pBitTimeParam,
                               uint32_t clkFreq);

/**
 * \brief   This function will update the sampling point based on CAN time
 *          segment values
 *
 * \param   pBitTimeParam  Pointer to dcanBitTimeParams_t structure.
 * \param   samplePnt      Sample point value.
 * \param   tseg           Time segment value.
 * \param   tseg1          Pointer to store time segment 1 value.
 * \param   tseg2          Pointer to store time segment 2 value.
 *
 * \retval  samplePnt      Returns the updated sample point value.
 **/
int32_t DcanUpdateSamplePnt(dcanBitTimeParams_t *pBitTimeParam,
                            int32_t samplePnt,
                            int32_t tseg,
                            int32_t *tseg1,
                            int32_t *tseg2);

/**
 * \brief   This API gets the soc info - base address of DCAN instance
 *          and DCAN DMA event numbers.
 *
 * \param   pObj        Pointer to the pin object.
 *
 * \retval  S_PASS      SoC information successfully retrieved.
 * \retval  E_FAIL      SOC info retrieval is failed. Resource is not present.
 */
static int32_t DcanDmaSocInfoGet(DcanAppObj_t *pObj);

/**
 * \brief   This API configures transmit and receive channel PaRAM registers
 *          by updating SRCBIDX and DSTBIDX. This is specific to DCAN
 *          application.
 *
 * \param   pObj          Pointer to the pin object.
 * \param   evt           DCAN transfer event.
 *
 * \retval  None
 **/
static void DcanEdmaParamConfig(DcanAppObj_t *pObj, uint32_t evt);

/**
 * \brief   This API is call back function to handle DMA event.
 *
 * \param   chNum       Channel number on which call back function occurred.
 * \param   xferStatus  Transfer status on the DMA channel number.
 */
static void DcanDmaCallBack(uint32_t chNum, uint32_t xferStatus);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Global object for the DCAN IP configuration. */
static DcanAppObj_t gDcanAppObj;

/** \brief Global status for frame reception completion status. */
static uint32_t gDcanRxStatus = FALSE;

/** \brief IP default configuration */
DcanAppObj_t DCANAPPOBJ_DEFAULT =
{
    {
        FALSE, /* enableDma */
        {
            0U,                                        /* dmaType */
            1U,                                        /* frameCnt */
            {
                0U,                                    /* dmaType */
                0U,                                    /* instNum */
                DMA_UTILS_EVENT_MAP_TYPE_DIRECT,       /* evtToChMapType */
                0U,                                    /* evtNum */
                0U,                                    /* chNum */
                0U                                     /* xferIdx */
            }, /* dmaUtilsEvtInfo_t */
            {
                0U,                                    /* dmaType */
                0U,                                    /* instNum */
                DMA_UTILS_EVENT_MAP_TYPE_DIRECT,       /* evtToChMapType */
                0U,                                    /* evtNum */
                0U,                                    /* chNum */
                0U                                     /* xferIdx */
            } /* dmaUtilsEvtInfo_t */
        } /* DcanAppDmaCfg_t */
    }, /* DcanAppCfg_t */
    0U, /* instNum*/
    0U, /* instAddr*/
}; /* DcanAppObj_t */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t DCANAppInit(dcanAppCfgObj_t *pCfgDcan)
{
    int32_t status = S_PASS;

    /* Clock Configuration. */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_DCAN, pCfgDcan->instNum, FALSE);

    if (S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n Clock Configuration failed !\n");
    }
    else
    {
        /* Perform the DCAN pinmux. */
        status = PINMUXModuleConfig(CHIPDB_MOD_ID_DCAN, pCfgDcan->instNum, NULL);

        /* Configure the DCAN interrupts. */
        DcanAppIntrConfig(pCfgDcan);

        /* Place DCAN in Initialization mode. */
        DCANSetMode(pCfgDcan->instAddr, DCAN_MODE_INIT);

        /* Reset the DCAN instance. */
        DCANReset(pCfgDcan->instAddr);

        /* Set the CAN bit time. */
        DcanSetBitTime(pCfgDcan->instAddr,
                       pCfgDcan->inputClk,
                       pCfgDcan->bitRate);

    }

    return(status);
}

void DCANAppDmaConfig(uint32_t baseAddr, uint32_t enableDma)
{
    /* Enable DMA request line for IF1 */
    DCANDmaRequestLineEnable(baseAddr, DCAN_IF_REG_NUM_1, enableDma);

    /* Enable DMA request line for IF3*/
    DCANDmaRequestLineEnable(baseAddr, DCAN_IF_REG_NUM_3, enableDma);

    /* Configure IF3 flags to complete DMA cycle after reading IF3 data registers */
    if(TRUE == enableDma)
        DCANSetIf3Observation(baseAddr, DCAN_OBS_FIELD_DAT_A | DCAN_OBS_FIELD_DAT_B);
    else
        DCANClearIf3Observation(baseAddr, DCAN_OBS_FIELD_DAT_A | DCAN_OBS_FIELD_DAT_B);
}

void DCANAppMsgObjectConfig(dcanAppCfgObj_t *pObj, uint32_t mode)
{
    uint32_t msgNum = 0U;
    uint32_t idLen = 0U;
    uint32_t ifRegNum = 0U;
    uint32_t msgIndex = 0U;
    uint32_t command = 0U;

    idLen = (pObj->appCtrl.ctrlParams & DCAN_EXT_FRAME) ?
             DCAN_ID_LENGTH_29_BIT : DCAN_ID_LENGTH_11_BIT;

    msgIndex = (pObj->maxMsgObjs / 2U);

    if((pObj->appCtrl.ctrlParams & DCAN_DATA_FRAME) &&
       (pObj->appCtrl.ctrlParams & DCAN_MSG_TX_DIR))
    {
        ifRegNum = DCAN_IF_REG_NUM_1;

        /* Send DMA request to transfer first frame data to data registers */
        if(pObj->appIntrCfg.intrCount == 1 && DCAN_DMA_MODE == mode)
            DCANSetCommand(pObj->instAddr,
                          (DCAN_CMD_MSG_READ |
                           DCAN_CMD_DAT_A_ACCESS |
                           DCAN_CMD_DAT_B_ACCESS |
                           DCAN_CMD_DMA_ACTIVE),
                           msgNum,
                           DCAN_IF_REG_NUM_1);

        /* Set the message valid bit. */
        DCANValidateMsgObj(pObj->instAddr, ifRegNum);

        /* Set the message id of the frame to be transmitted */
        DCANSetMsgId(pObj->instAddr, pObj->appCtrl.canId, idLen, ifRegNum);

        /* Set the message object direction for transmission. */
        DCANSetMsgDirection(pObj->instAddr, DCAN_MSG_DIR_TX, ifRegNum);

        /* Configure the data length code for the Tx message object. */
        DCANSetDataLengthCode(pObj->instAddr,
                              pObj->appCtrl.dataLengthCode,
                              ifRegNum);

        /* Write data to the DCAN data registers. */
        if(DCAN_MANUAL_MODE == mode)
            DCANWriteData(pObj->instAddr, pObj->appCtrl.pData, ifRegNum);

        /* Enable the transmit interrupt for the message object. */
        DCANMsgObjIntrEnable(pObj->instAddr,
                             DCAN_MSG_OBJ_INTR_MASK_TX,
                             ifRegNum);

        /* Enable FIFO end of block. */
        DCANFifoEndOfBlockEnable(pObj->instAddr, TRUE, ifRegNum);

        /* Get the transmit request status */
        msgNum = DCANTxRqstLeastMsgObjStatus(pObj->instAddr);

        command = (DCAN_CMD_DAT_A_ACCESS |
                   DCAN_CMD_MSG_WRITE |
                   DCAN_CMD_TXRQST_ACCESS |
                   DCAN_CMD_DAT_B_ACCESS |
                   DCAN_CMD_ACCESS_CTL_BITS |
                   DCAN_CMD_ACCESS_ARB_BITS);

        /* Request DMA transfer to data registers after every message object
         * transfer except last one */
        if(pObj->appIntrCfg.intrCount < pObj->appIntrCfg.totalFrames && DCAN_DMA_MODE == mode)
            command = command | DCAN_CMD_DMA_ACTIVE;

        /* Configure the DCAN command register */
        DCANSetCommand(pObj->instAddr,
                       command,
                       msgNum,
                       DCAN_IF_REG_NUM_1);
    }
    else if((pObj->appCtrl.ctrlParams & DCAN_DATA_FRAME) &&
            (pObj->appCtrl.ctrlParams & DCAN_MSG_RX_DIR))
    {
        ifRegNum = DCAN_IF_REG_NUM_2;

        /* Enable the acceptance mask. */
        DCANAcceptanceMaskEnable(pObj->instAddr, TRUE, ifRegNum);

        /* Configure the DCAN mask registers for acceptance filtering. */
        DCANMsgObjectMaskConfig(pObj->instAddr,
                                DCAN_IDENTIFIER_MASK(0U, DCAN_ID_MASK_11_BIT),
                                DCAN_MSG_DIR_MASK_NOT_USED,
                                DCAN_EXT_ID_MASK_USED,
                                ifRegNum);

        /* Set the message valid bit. */
        DCANValidateMsgObj(pObj->instAddr, ifRegNum);

        /* Set the message id of the frame to be transmitted */
        DCANSetMsgId(pObj->instAddr, pObj->appCtrl.canId, idLen, ifRegNum);

        /* Set the message object direction for reception. */
        DCANSetMsgDirection(pObj->instAddr, DCAN_MSG_DIR_RX, ifRegNum);

        /* Enable the receive interrupt for the message object. */
        if(DCAN_MANUAL_MODE == mode)
            DCANMsgObjIntrEnable(pObj->instAddr,
                                DCAN_MSG_OBJ_INTR_MASK_RX,
                                ifRegNum);

        /* Enable FIFO end of block. */
        DCANFifoEndOfBlockEnable(pObj->instAddr, TRUE, ifRegNum);

        /* Check for the message valid status for receive objects */
        while((DCANMsgValidStatus(pObj->instAddr, msgIndex)) &&
              (msgIndex <= (pObj->maxMsgObjs - 1U)))
        {
            msgIndex++;
        }

        /* Configure IF3 to automatically receive data on frame reception */
        if(DCAN_DMA_MODE == mode)
            DCANSetIf3RegUpdateEnable(pObj->instAddr, msgIndex);

        /* Configure the command register */
        DCANSetCommand(pObj->instAddr,
                      (DCAN_CMD_ACCESS_CTL_BITS |
                       DCAN_CMD_MSG_WRITE |
                       DCAN_CMD_ACCESS_MSK_BITS |
                       DCAN_CMD_ACCESS_ARB_BITS),
                       msgIndex,
                       DCAN_IF_REG_NUM_2);

    }
    else
    {
        /* Perform nothing. */
    }
}

void DCANAppStartTransfer(dcanAppCfgObj_t *pObj)
{
    /* Start the CAN transfer */
    DCANSetMode(pObj->instAddr, DCAN_MODE_NORMAL);

    /* Enable the error interrupts */
    DCANIntrEnable(pObj->instAddr, DCAN_INTR_MASK_ERROR);

    /* Enable the interrupt line 0 of DCAN module */
    DCANIntrLineEnable(pObj->instAddr, DCAN_INTR_LINE_NUM_0, TRUE);
}

void DCANAppStopTransfer(dcanAppCfgObj_t *pObj)
{
    /* Stop the CAN transfer */
    DCANSetMode(pObj->instAddr, DCAN_MODE_INIT);

    /* Disable the error interrupts */
    DCANIntrDisable(pObj->instAddr, DCAN_INTR_MASK_ERROR);

    /* Disable the interrupt line 0 of DCAN module */
    DCANIntrLineEnable(pObj->instAddr, DCAN_INTR_LINE_NUM_0, FALSE);
}

/* This function initializes the DMA instance for use. */
void DcanAppDmaInitialize(uint32_t frameCount)
{
    uint32_t status = S_PASS;

    DcanAppDmaCfg_t *pDcanDmaCfg = &(gDcanAppObj.dcanAppCfg.dmaCfg);

    /* Initialize the global IP configuration with default configuration. */
    gDcanAppObj = DCANAPPOBJ_DEFAULT;
    gDcanAppObj.dcanAppCfg.enableDma = TRUE;
    gDcanAppObj.dcanAppCfg.dmaCfg.frameCnt = frameCount;

    /* Check which DCAN instance is brought out on the board. */
    /* TBD: Hard-code for now */
    gDcanAppObj.instNum = DCAN_INST_NUM;

    if (S_PASS == status)
    {
        /* Get SoC info */
        status = DcanDmaSocInfoGet(&gDcanAppObj);

        if(S_PASS == status)
        {
            if(S_PASS == status)
            {
                status = DMAUtilsInit(pDcanDmaCfg->dmaType,
                    pDcanDmaCfg->rxEvtInfo.instNum, NULL);
            }
        }
    }
}

void DcanAppDmaTransfer(uint8_t* srcBuffer, uint8_t* dstBuffer, uint32_t frameLength)
{
    int32_t status = S_PASS;

    status = DcanAppDmaTxSetup(&gDcanAppObj, srcBuffer, frameLength);
    if (status != E_FAIL)
    {
        DcanEdmaParamConfig(&gDcanAppObj, DCAN_DMA_EVT_TX);
        status = DcanAppDmaXferStart(&gDcanAppObj, DCAN_DMA_EVT_TX);

        if (status != E_FAIL)
        {
            status = DcanAppDmaRxSetup(&gDcanAppObj, dstBuffer, frameLength);
            if (status != E_FAIL)
            {
                DcanEdmaParamConfig(&gDcanAppObj, DCAN_DMA_EVT_RX);
                status = DcanAppDmaXferStart(&gDcanAppObj, DCAN_DMA_EVT_RX);
                if (E_FAIL == status)
                {
                    CONSOLEUtilsPrintf("Failed to initiate the Transaction \n");
                }
            }
            else
            {
                CONSOLEUtilsPrintf("DCAN Receive Setup failed \n");
            }
        }
        else
        {
            CONSOLEUtilsPrintf("Failed to initiate the Transaction \n");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("DCAN Transmit Setup failed\n");
    }
}

uint32_t DcanAppDmaReceptionCompleteStatus()
{
    uint32_t status = TRUE;

    if(gDcanRxStatus == TRUE)
        status = TRUE;
    else
        status = FALSE;

    return status;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static int32_t DcanAppIntrConfig(dcanAppCfgObj_t *pCfgDcan)
{
    int32_t retVal = S_PASS;

#ifdef RTOS_BUILD
    OsalRegisterIntrParams_t interruptRegParams;
    HwiP_Handle hwiPHandlePtr;

    /* Initialize with defaults */
    Osal_RegisterInterrupt_initParams(&interruptRegParams);

    /* Populate the interrupt parameters */
    interruptRegParams.corepacConfig.arg=(uintptr_t) pCfgDcan;
    interruptRegParams.corepacConfig.name=NULL;
    interruptRegParams.corepacConfig.isrRoutine=DcanAppIsr;
    interruptRegParams.corepacConfig.priority = 0x20U;
    interruptRegParams.corepacConfig.triggerSensitivity =  OSAL_ARM_GIC_TRIG_TYPE_EDGE;
    interruptRegParams.corepacConfig.intVecNum=pCfgDcan->appIntrCfg.intrLine;
    /* Register interrupts */
    Osal_RegisterInterrupt(&interruptRegParams, &hwiPHandlePtr);
#else
	intcIntrParams_t dcanIntrParams;
    INTCInit(FALSE);

    dcanIntrParams.triggerType = pCfgDcan->appIntrCfg.trigType;
    dcanIntrParams.priority = pCfgDcan->appIntrCfg.intrPriority;
    dcanIntrParams.pFnIntrHandler = DcanAppIsr;
    dcanIntrParams.pUserParam = pCfgDcan;
    dcanIntrParams.isIntrSecure = pCfgDcan->appIntrCfg.enableSecureIntr;

    /* Configure the DCAN interrupt line. */
    retVal = INTCConfigIntr(pCfgDcan->appIntrCfg.intrLine,
                            &dcanIntrParams,
                            FALSE);

    if(E_FAIL == retVal)
    {
        CONSOLEUtilsPrintf("FAILURE!!!.\r\n");
        CONSOLEUtilsPrintf("Configuration failed for DCAN interrupt.\r\n");
    }
#endif

    return (retVal);
}

/* Handle the DCAN transmit and receive interrupts. */
/* TODO: The ISR is not generic and is applicable to DCAN loopback application.
         In the ideal case the application should pass a callback function. */
#ifdef RTOS_BUILD
static void DcanAppIsr(uintptr_t pUserParam)
#else
static void DcanAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
#endif
{
    uint8_t *pDataVal;
    uint32_t rxData[2U];
    uint32_t errVal = 0U;
    uint32_t msgObjNum = 0U;
    uint32_t index = 0U;
    uint32_t intrSts = 0U;

    dcanAppCfgObj_t *instObj = (dcanAppCfgObj_t *) pUserParam;

    intrSts = DCANIntrStatus(instObj->instAddr, DCAN_INTR_LINE_NUM_0);

    while(0U != intrSts)
    {
        if(DCAN_ERROR_OCCURED == intrSts)
        {
            errVal = DCANGetErrorStatus(instObj->instAddr);

            if (errVal & DCAN_STS_ERR_CODE_MASK_BUS_OFF)
            {
                CONSOLEUtilsPrintf("**DCAN is in Bus-off state**\n");

                /*
                ** This feature will automatically get the CAN bus to bus-on
                ** state once the error counters are below the error warning
                ** limit.
                */
                DCANAutoBusOnEnable(instObj->instAddr, TRUE);
            }

            if (errVal & DCAN_STS_ERR_CODE_MASK_ERROR_WARNING)
            {
                CONSOLEUtilsPrintf("Atleast one of the error counters have");
                CONSOLEUtilsPrintf(" reached the error warning limit\n");
            }
        }

        if((DCAN_NO_INTR_PENDING != intrSts) && ((DCAN_ERROR_OCCURED != intrSts)))
        {
            /* Get the number of the message object which caused the interrupt */
            msgObjNum = DCANIntrStatus(instObj->instAddr, DCAN_INTR_LINE_NUM_0);

            /* Interrupt handling for transmit objects */
            if(msgObjNum < (instObj->maxMsgObjs/2U))
            {
                /* Clear the Interrupt pending status */
                DCANAppIntrClear(instObj->instAddr,
                                 msgObjNum,
                                 DCAN_IF_REG_NUM_1);

                if(instObj->appIntrCfg.totalFrames == instObj->appIntrCfg.intrCount)
                {
                    /* Disable the transmit interrupt of the message object */
                    DCANAppTxIntrDisable(instObj->instAddr,
                                      msgObjNum,
                                      DCAN_IF_REG_NUM_1);

                    /* Invalidate the transmit message object */
                    DCANAppInvalidateMsgObject(instObj->instAddr,
                                               msgObjNum,
                                               DCAN_IF_REG_NUM_1);
                }

                instObj->appIntrCfg.txCtrl = 0U;
            }

            /* Interrupt handling for receive message objects. */
            if((msgObjNum >= (instObj->maxMsgObjs/2U)) &&
               (msgObjNum < instObj->maxMsgObjs))
            {
                /* Read a received message from message RAM to interface register */
                DCANAppReadMsgObjData(instObj->instAddr,
                                      msgObjNum,
                                      (uint32_t*) rxData,
                                      DCAN_IF_REG_NUM_2);

                /* Clear the Interrupt pending status */
                DCANAppIntrClear(instObj->instAddr,
                                   msgObjNum,
                                   DCAN_IF_REG_NUM_2);

                pDataVal = (uint8_t*) rxData;

                CONSOLEUtilsPrintf("Data received = ");

                instObj->appIntrCfg.frameLen = (DCANIfMsgCtlStatus(instObj->instAddr, DCAN_IF_REG_NUM_2) &
                                             DCAN_MSG_CTL_STS_DAT_LEN_CODE);

                /* Print the received data bytes on the UART console */
                for(index = 0U; index < instObj->appIntrCfg.frameLen; index++)
                {
                    CONSOLEUtilsPrintf("%c", *pDataVal++);
                }

                CONSOLEUtilsPrintf("\r");
                CONSOLEUtilsPrintf("\n");

                if(instObj->appIntrCfg.totalFrames == instObj->appIntrCfg.intrCount)
                {
                    /* Disable the receive interrupt of the message object */
                    DCANAppRxIntrDisable(instObj->instAddr,
                                         msgObjNum,
                                         DCAN_IF_REG_NUM_2);

                    /* Invalidate the receive message object */
                    DCANAppInvalidateMsgObject(instObj->instAddr,
                                               msgObjNum,
                                               DCAN_IF_REG_NUM_2);
                }
                if(TRUE == instObj->appCtrl.appLoopBk)
                {
                    /* Check if frame with extended ID is received. */
                    if((DCANIfArbitrationStatus(instObj->instAddr, DCAN_IF_REG_NUM_2) &
                        DCAN_ARB_STS_EXT_ID) == 0x40000000U)
                    {
                        instObj->appCtrl.ctrlParams = (DCAN_EXT_FRAME | DCAN_DATA_FRAME | DCAN_MSG_TX_DIR);
                        /* Configure a transmit frame with Extended ID */
                        instObj->appCtrl.canId = 1000U;
                    }
                    else
                    {
                        instObj->appCtrl.ctrlParams = (DCAN_DATA_FRAME | DCAN_MSG_TX_DIR);
                        /* Configure a transmit frame with standard ID */
                        instObj->appCtrl.canId = 0x02U;
                    }

                    /* Populate the can_frame structure with the CAN frame information */
                    instObj->appCtrl.dataLengthCode = instObj->appIntrCfg.frameLen;
                    instObj->appCtrl.pData = (uint32_t *)rxData;

                    /* Configure a transmit message object */
                    DCANAppMsgObjectConfig(instObj, DCAN_MANUAL_MODE);
                }

                instObj->appIntrCfg.rxCtrl = 0U;
            }
        }
        intrSts = DCANIntrStatus(instObj->instAddr, DCAN_INTR_LINE_NUM_0);
    }
}

void DCANAppInvalidateMsgObject(uint32_t baseAddr,
                                uint32_t msgObjNum,
                                uint32_t ifRegNum)
{
    /* Clear the MsgVal bit of DCAN_IFARB register. */
    DCANInvalidateMsgObj(baseAddr, ifRegNum);

    /* Set the Arb bit of DCAN_IFCMD register. */
    DCANSetCommand(baseAddr,
                  (DCAN_CMD_ACCESS_ARB_BITS | DCAN_CMD_MSG_WRITE),
                   msgObjNum,
                   ifRegNum);
}

uint32_t DcanSetBitTime(uint32_t baseAddr,
                        uint32_t clkFreq,
                        uint32_t bitRate)
{
    uint32_t errVal = 0U;
    uint32_t btrValue = 0U;
    uint32_t tSeg1 = 0U;
    uint32_t tSeg2 = 0U;

    dcanBitTimeParams_t gDcanBitTime =
    {
        0U,                 /* bitRate */
        0U,                 /* samplePnt */
        0U,                 /* timeQuanta */
        0U,                 /* propSeg */
        0U,                 /* phaseSeg1 */
        0U,                 /* phaseSeg2 */
        0U,                 /* syncJumpWidth */
        0U,                 /* bitRatePrescaler */
        1U,                 /* tseg1Min */
        16U,                /* tseg1Max */
        1U,                 /* tseg2Min */
        8U,                 /* tseg2Max */
        4U,                 /* syncJumpWidthMax */
        1U,                 /* bitRatePrescalerMin */
        1024U,              /* bitRatePrescalerMax */
        1U,                 /* bitRatePrescalerInc */
    };

    gDcanBitTime.bitRate = bitRate;

    errVal = DcanBitTimeCalculator(&gDcanBitTime, clkFreq);

    /* Calculate Time Segment2 value */
    tSeg2 = (gDcanBitTime.phaseSeg2 - 1U);

    /* Calculate Time Segment1 value */
    tSeg1 = (gDcanBitTime.phaseSeg1 + gDcanBitTime.propSeg - 1U);

    /* Write the BRP value */
    btrValue |= ((gDcanBitTime.bitRatePrescaler - 1U) & DCAN_BTR_BRP_MASK);

    /* Write the BRPE value */
    btrValue |= (((gDcanBitTime.bitRatePrescaler - 1U) &
                   EXTRACT_BRPE_VAL) << BRPE_SHIFT);

    /* Write the Time Segment2 value */
    btrValue |= ((tSeg2 << DCAN_BTR_TSEG2_SHIFT) & DCAN_BTR_TSEG2_MASK);

    /* Write the Time Segment1 value */
    btrValue |= ((tSeg1 << DCAN_BTR_TSEG1_SHIFT) & DCAN_BTR_TSEG1_MASK);

    /* Set the BTR value to the DCAN bittiming register */
    DCANBitTimeConfig(baseAddr, btrValue);

    return (errVal);
}

uint32_t DcanBitTimeCalculator(dcanBitTimeParams_t *pBitTimeParam,
                               uint32_t clkFreq)
{
    int32_t samplePnt = 0U, samplePntErr = 1000U, tsegAll = 0U;
    int32_t tseg = 0U, tseg1 = 0U, tseg2 = 0U;
    int32_t brp = 0U, samplePntNew = 0U, bestTseg = 0U, bestBrp = 0U;
    long error = 0U, bestErr = 1000000000U;
    uint32_t errVal = NO_BIT_RATE_ERR;
    uint32_t rate = 0U, timeQuanta = 0U;

    if(pBitTimeParam->bitRate > 800000U)
    {
        samplePnt = 750U;
    }

    else if(pBitTimeParam->bitRate > 500000U)
    {
        samplePnt = 800U;
    }

    else
    {
        samplePnt = 875U;
    }

    for(tseg =
       (pBitTimeParam->tseg1Max + pBitTimeParam->tseg2Max) * 2 + 1;
        tseg >=
       (pBitTimeParam->tseg1Min + pBitTimeParam->tseg2Min) * 2; tseg--)
    {
        tsegAll = 1 + tseg / 2;

        /* Compute all possible tseg choices (tseg = tseg1+tseg2) */
        brp = clkFreq / (tsegAll * pBitTimeParam->bitRate) + tseg % 2;

        /* chose brp step which is possible in system */
        brp = (brp / pBitTimeParam->bitRatePrescalerInc) *
               pBitTimeParam->bitRatePrescalerInc;

        if((brp < pBitTimeParam->bitRatePrescalerMin) ||
           (brp > pBitTimeParam->bitRatePrescalerMax))
            continue;
        rate = clkFreq / (brp * tsegAll);
        error = pBitTimeParam->bitRate - rate;

        /* tseg brp biterror */
        if(error < 0)
        {
            error = -error;
        }
        if(error > bestErr)
        {
            continue;
        }
        bestErr = error;
        if(error == 0)
        {
            samplePntNew = DcanUpdateSamplePnt(pBitTimeParam,
                                               samplePnt,
                                               tseg / 2,
                                               &tseg1,
                                               &tseg2);

            error = samplePnt - samplePntNew;
            if(error < 0)
            {
                error = -error;
            }
            if(error > samplePntErr)
            {
                continue;
            }
            samplePntErr = error;
        }
        bestTseg = tseg / 2;
        bestBrp = brp;
        if(error == 0)
        {
            break;
        }
    }

    if(bestErr)
    {
        /* Error in one-tenth of a percent */
        error = (bestErr * 1000) / pBitTimeParam->bitRate;
        if(error > CAN_CALC_MAX_ERROR)
        {
            errVal = BIT_RATE_ERR_MAX;
        }
        else
        {
            errVal = BIT_RATE_ERR_WARN;
        }
    }

    /* real sample point */
    pBitTimeParam->samplePnt = DcanUpdateSamplePnt(pBitTimeParam,
                                                   samplePnt,
                                                   bestTseg,
                                                   &tseg1,
                                                   &tseg2);

    /* Calculate the time quanta value. */
    timeQuanta = bestBrp * 1000000000UL;

    pBitTimeParam->timeQuanta = timeQuanta;
    pBitTimeParam->propSeg = tseg1 / 2;
    pBitTimeParam->phaseSeg1 = tseg1 - pBitTimeParam->propSeg;
    pBitTimeParam->phaseSeg2 = tseg2;
    pBitTimeParam->syncJumpWidth = 1;
    pBitTimeParam->bitRatePrescaler = bestBrp;
    /* Real bit-rate */
    pBitTimeParam->bitRate =
           clkFreq / (pBitTimeParam->bitRatePrescaler * (tseg1 + tseg2 + 1));

    return (errVal);
}

int32_t DcanUpdateSamplePnt(dcanBitTimeParams_t *pBitTimeParam,
                            int32_t samplePnt,
                            int32_t tseg,
                            int32_t *tseg1,
                            int32_t *tseg2)
{
    *tseg2 = tseg + 1 - (samplePnt * (tseg + 1)) / 1000;

    if(*tseg2 < pBitTimeParam->tseg2Min)
    {
        *tseg2 = pBitTimeParam->tseg2Min;
    }

    if(*tseg2 > pBitTimeParam->tseg2Max)
    {
        *tseg2 = pBitTimeParam->tseg2Max;
    }

    *tseg1 = tseg - *tseg2;

    if (*tseg1 > pBitTimeParam->tseg1Max)
    {
        *tseg1 = pBitTimeParam->tseg1Max;
        *tseg2 = tseg - *tseg1;
    }

    return(1000 * (tseg + 1 - *tseg2) / (tseg + 1));
}


void DCANAppIntrClear(uint32_t baseAddr,
                      uint32_t msgObjNum,
                      uint32_t ifRegNum)
{
    /* Clear the IntPnd bit of DCAN_IFMCTL register */
    DCANIntrClear(baseAddr, ifRegNum);

    /* Set the ClrIntPnd bit of DCAN_IFCMD register */
    DCANSetCommand(baseAddr, DCAN_CMD_CLR_INTPND, msgObjNum, ifRegNum);
}

void DCANAppTxIntrDisable(uint32_t baseAddr,
                          uint32_t msgObjNum,
                          uint32_t ifRegNum)
{
    /* Disable the message object transmit interrupt */
    DCANMsgObjIntrDisable(baseAddr, DCAN_MSG_OBJ_INTR_MASK_TX, ifRegNum);

    /* Set the CTL bit of the command register */
    DCANSetCommand(baseAddr,
                  (DCAN_CMD_ACCESS_CTL_BITS | DCAN_CMD_MSG_WRITE),
                   msgObjNum,
                   ifRegNum);
}

void DCANAppReadMsgObjData(uint32_t baseAddr,
                           uint32_t msgObjNum,
                           uint32_t* pData,
                           uint32_t ifRegNum)
{
    /* Read a message object from CAN message RAM to Interface register */
    DCANSetCommand(baseAddr,
                  (DCAN_CMD_DAT_A_ACCESS | DCAN_CMD_DAT_B_ACCESS |
                   DCAN_CMD_TXRQST_ACCESS | DCAN_CMD_CLR_INTPND |
                   DCAN_CMD_ACCESS_CTL_BITS | DCAN_CMD_ACCESS_ARB_BITS |
                   DCAN_CMD_ACCESS_MSK_BITS | DCAN_CMD_MSG_READ),
                   msgObjNum,
                   ifRegNum);

    /* Clear the NewData bit */
    DCANNewDataConfig(baseAddr, DCAN_NEW_DATA_CFG_CLR, ifRegNum);

    /* Read data bytes from interface register */
    DCANReadData(baseAddr, pData, ifRegNum);
}

void DCANAppRxIntrDisable(uint32_t baseAddr, uint32_t msgObjNum, uint32_t ifRegNum)
{
    /* Disable the message object receive interrupt */
    DCANMsgObjIntrDisable(baseAddr, DCAN_MSG_OBJ_INTR_MASK_RX, ifRegNum);

    /* Set the CTL bit of the command register */
    DCANSetCommand(baseAddr,
                  (DCAN_CMD_ACCESS_CTL_BITS | DCAN_CMD_MSG_WRITE),
                   msgObjNum,
                   ifRegNum);
}

static int32_t DcanDmaSocInfoGet(DcanAppObj_t *pObj)
{
    uint32_t status = S_PASS;

    /* Get the base address of the Module */
    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_DCAN, pObj->instNum))
    {
        pObj->instAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_DCAN, pObj->instNum);

        pObj->dcanAppCfg.dmaCfg.pFxnCallBack = &DcanDmaCallBack;

        pObj->dcanAppCfg.dmaCfg.dmaType = DMA_TYPE_ENHACED;
        pObj->dcanAppCfg.dmaCfg.rxEvtInfo.dmaType = DMA_TYPE_ENHACED;
        pObj->dcanAppCfg.dmaCfg.rxEvtInfo.instNum = 0U;
        pObj->dcanAppCfg.dmaCfg.rxEvtInfo.evtToChMapType = DMA_UTILS_EVENT_MAP_TYPE_DIRECT;
        pObj->dcanAppCfg.dmaCfg.rxEvtInfo.evtNum = 47U;
        pObj->dcanAppCfg.dmaCfg.rxEvtInfo.chNum = 47U;
        pObj->dcanAppCfg.dmaCfg.rxEvtInfo.xferIdx = 47U;
        pObj->dcanAppCfg.dmaCfg.txEvtInfo.instNum = 0U;
        pObj->dcanAppCfg.dmaCfg.txEvtInfo.evtToChMapType = DMA_UTILS_EVENT_MAP_TYPE_DIRECT;
        pObj->dcanAppCfg.dmaCfg.txEvtInfo.evtNum = 40U;
        pObj->dcanAppCfg.dmaCfg.txEvtInfo.chNum = 40U;
        pObj->dcanAppCfg.dmaCfg.txEvtInfo.xferIdx = 40U;
    }
    else
    {
        status = E_FAIL;
    }

    return status;
}

static void DcanEdmaParamConfig(DcanAppObj_t *pObj, uint32_t evt)
{
    EDMAParamEntry_t paramset = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

    if(evt == DCAN_DMA_EVT_TX)
    {
        EDMAGetParamEntry(EDMA_TPCC_BASE, pObj->dcanAppCfg.dmaCfg.txEvtInfo.chNum, &paramset);
        /* DSTBIDX = 0; SRCBIDX = DCAN_FRAME_SIZE */
        paramset.word5 = DCAN_FRAME_SIZE;
        EDMASetParamEntry(EDMA_TPCC_BASE, pObj->dcanAppCfg.dmaCfg.txEvtInfo.chNum, &paramset);
    }
    else if(evt == DCAN_DMA_EVT_RX)
    {
        EDMAGetParamEntry(EDMA_TPCC_BASE, pObj->dcanAppCfg.dmaCfg.rxEvtInfo.chNum, &paramset);
        /* DSTBIDX = DCAN_FRAME_SIZE; SRCBIDX = 0 */
        paramset.word5 = DCAN_FRAME_SIZE << 16;
        EDMASetParamEntry(EDMA_TPCC_BASE, pObj->dcanAppCfg.dmaCfg.rxEvtInfo.chNum, &paramset);
    }
}

void DcanDmaCallBack(uint32_t chNum, uint32_t xferStatus)
{
    DcanAppObj_t *pDcanObj = &gDcanAppObj;

    if(pDcanObj->dcanAppCfg.dmaCfg.txEvtInfo.chNum == chNum)
    {
        DcanAppDmaXferStop(pDcanObj, DCAN_DMA_EVT_TX);
    }
    else if(pDcanObj->dcanAppCfg.dmaCfg.rxEvtInfo.chNum == chNum)
    {
        gDcanRxStatus = TRUE;
        DcanAppDmaXferStop(pDcanObj, DCAN_DMA_EVT_RX);
    }
}

int32_t DcanAppDmaRxSetup(DcanAppObj_t *pObj,
                          uint8_t *pBuf,
                          uint32_t bytesPerEvt)
{
    int32_t retStat = E_FAIL;
    DcanAppDmaCfg_t *pDcanDmaCfg = &(pObj->dcanAppCfg.dmaCfg);
    dmaUtilsDataObj_t fifoDataObj =
    {
        0U,                                        /* addr */
        DMA_XFER_DATA_ADDR_MODE_INC,               /* addrMode */
        0U,                                        /* fifoWidth */
        1U,                                        /* packetActSize */
        1U,                                        /* frameActSize */
        1U,                                        /* blockSize */
        0U,                                        /* packetInactSize */
        0U,                                        /* frameInactSize */
        DMA_UTILS_DATA_SYNC_PACKET                 /* syncMode */
    }; /* dmaUtilsDataObj_t */
    dmaUtilsDataObj_t bufDataObj =
    {
        0U,                                        /* addr */
        DMA_XFER_DATA_ADDR_MODE_INC,               /* addrMode */
        0U,                                        /* fifoWidth */
        1U,                                        /* packetActSize */
        1U,                                        /* frameActSize */
        1U,                                        /* blockSize */
        0U,                                        /* packetInactSize */
        0U,                                        /* frameInactSize */
        DMA_UTILS_DATA_SYNC_PACKET                 /* syncMode */
    }; /* dmaUtilsDataObj_t */
    dmaUtilsXferObj_t xferObj =
    {
        NULL,                                      /* pSrc */
        NULL,                                      /* pDest */
        DMA_UTILS_DATA_SYNC_MASK_BLOCK,            /* intrConfig */
        FALSE,                                     /* linkEnable */
        0U                                         /* nxtXferIdx */
    }; /* dmaUtilsXferObj_t */
    dmaUtilsChObj_t chObj =
    {
        DMA_XFER_TRIGGER_TYPE_EVENT,               /* triggerType */
        0U,                                        /* xferIdx */
        TRUE,                                      /* intrEnable */
        NULL,                                      /* callBack */
        0U                                         /* queueNum */
    }; /* dmaUtilsChObj_t */

    if(NULL != pBuf)
    {
        retStat = S_PASS;
    }

    if((S_PASS == retStat) && (NULL == xferObj.pSrc))
    {
        xferObj.pSrc = &bufDataObj;
    }

    if((S_PASS == retStat) && (NULL == xferObj.pDst))
    {
        xferObj.pDst = &fifoDataObj;
    }

    if(S_PASS == retStat)
    {
        xferObj.pSrc->packetActSize = bytesPerEvt;
        xferObj.pSrc->frameActSize = pDcanDmaCfg->frameCnt;
        xferObj.pSrc->blockSize = 1U;

        xferObj.pSrc->addr = (uint32_t)(pObj->instAddr + DCAN_IFDATA(3)); /* IF3 DATA */
        xferObj.pDst->addr = (uint32_t)pBuf;
        chObj.xferIdx = pDcanDmaCfg->rxEvtInfo.xferIdx;
        chObj.queueNum = 0U;
        chObj.intrEnable = TRUE;
        chObj.callBack = pObj->dcanAppCfg.dmaCfg.pFxnCallBack;
        chObj.triggerType = DMA_XFER_TRIGGER_TYPE_EVENT;

        retStat = DMAUtilsDataXferConfig(pDcanDmaCfg->dmaType,
            pDcanDmaCfg->rxEvtInfo.instNum,
            pDcanDmaCfg->rxEvtInfo.xferIdx,
            &xferObj);

        if(S_PASS == retStat)
        {
            retStat = DMAUtilsChConfig(pDcanDmaCfg->dmaType,
                pDcanDmaCfg->rxEvtInfo.instNum,
                pDcanDmaCfg->rxEvtInfo.chNum,
                &chObj);
        }
    }

    return retStat;
}

int32_t DcanAppDmaTxSetup(DcanAppObj_t *pObj,
                          uint8_t *pBuf,
                          uint32_t bytesPerEvt)
{
    int32_t retStat = E_FAIL;
    DcanAppDmaCfg_t *pDcanDmaCfg = &(pObj->dcanAppCfg.dmaCfg);
    dmaUtilsDataObj_t fifoDataObj =
    {
        0U,                                        /* addr */
        DMA_XFER_DATA_ADDR_MODE_INC,               /* addrMode */
        0U,                                        /* fifoWidth */
        1U,                                        /* packetActSize */
        1U,                                        /* frameActSize */
        1U,                                        /* blockSize */
        0U,                                        /* packetInactSize */
        0U,                                        /* frameInactSize */
        DMA_UTILS_DATA_SYNC_PACKET                 /* syncMode */
    }; /* dmaUtilsDataObj_t */
    dmaUtilsDataObj_t bufDataObj =
    {
        0U,                                        /* addr */
        DMA_XFER_DATA_ADDR_MODE_INC,               /* addrMode */
        0U,                                        /* fifoWidth */
        1U,                                        /* packetActSize */
        1U,                                        /* frameActSize */
        1U,                                        /* blockSize */
        0U,                                        /* packetInactSize */
        0U,                                        /* frameInactSize */
        DMA_UTILS_DATA_SYNC_PACKET                 /* syncMode */
    }; /* dmaUtilsDataObj_t */
    dmaUtilsXferObj_t xferObj =
    {
        NULL,                                      /* pSrc */
        NULL,                                      /* pDest */
        DMA_UTILS_DATA_SYNC_MASK_BLOCK,            /* intrConfig */
        FALSE,                                     /* linkEnable */
        0U                                         /* nxtXferIdx */
    }; /* dmaUtilsXferObj_t */
    dmaUtilsChObj_t chObj =
    {
        DMA_XFER_TRIGGER_TYPE_EVENT,               /* triggerType */
        0U,                                        /* xferIdx */
        TRUE,                                      /* intrEnable */
        NULL,                                      /* callBack */
        0U                                         /* queueNum */
    }; /* dmaUtilsChObj_t */

    if(NULL != pBuf)
    {
        retStat = S_PASS;
    }

    if((S_PASS == retStat) && (NULL == xferObj.pSrc))
    {
        xferObj.pSrc = &fifoDataObj;
    }

    if((S_PASS == retStat) && (NULL == xferObj.pDst))
    {
        xferObj.pDst = &bufDataObj;
    }

    if(S_PASS == retStat)
    {
        xferObj.pSrc->packetActSize = bytesPerEvt;
        xferObj.pSrc->frameActSize = pDcanDmaCfg->frameCnt;
        xferObj.pSrc->blockSize = 1U;

        xferObj.pSrc->addr = (uint32_t)(pBuf);
        xferObj.pDst->addr = (uint32_t)(pObj->instAddr + DCAN_IFDATA(1)); /* IF1 DATA */
        chObj.xferIdx = pDcanDmaCfg->txEvtInfo.xferIdx;
        chObj.queueNum = 0U;
        chObj.intrEnable = TRUE;
        chObj.callBack = pObj->dcanAppCfg.dmaCfg.pFxnCallBack;
        chObj.triggerType = DMA_XFER_TRIGGER_TYPE_EVENT;

        retStat = DMAUtilsDataXferConfig(pDcanDmaCfg->dmaType,
                    pDcanDmaCfg->txEvtInfo.instNum,
                    pDcanDmaCfg->txEvtInfo.xferIdx,
                    &xferObj);

        if (S_PASS == retStat)
        {
            retStat = DMAUtilsChConfig(pDcanDmaCfg->dmaType,
                        pDcanDmaCfg->txEvtInfo.instNum,
                        pDcanDmaCfg->txEvtInfo.chNum,
                        &chObj);
        }
    }

    return retStat;
}

int32_t DcanAppDmaXferStart(DcanAppObj_t *pObj, uint32_t evt)
{
    int32_t retStat = S_PASS;
    DcanAppDmaCfg_t *pDcanDmaCfg = &(pObj->dcanAppCfg.dmaCfg);

    if(DCAN_DMA_EVT_TX == evt)
    {
        DMAUtilsXferStart(pDcanDmaCfg->dmaType, pDcanDmaCfg->txEvtInfo.instNum,
                          pDcanDmaCfg->txEvtInfo.chNum,
                          DMA_XFER_TRIGGER_TYPE_EVENT);
    }
    else if(DCAN_DMA_EVT_RX == evt)
    {
        DMAUtilsXferStart(pDcanDmaCfg->dmaType, pDcanDmaCfg->rxEvtInfo.instNum,
                          pDcanDmaCfg->rxEvtInfo.chNum,
                          DMA_XFER_TRIGGER_TYPE_EVENT);
    }
    else
    {
        retStat = E_FAIL;
    }

    return retStat;
}

int32_t DcanAppDmaXferStop(DcanAppObj_t *pObj, uint32_t evt)
{
    int32_t retStat = S_PASS;
    DcanAppDmaCfg_t *pDcanDmaCfg = &(pObj->dcanAppCfg.dmaCfg);

    if(DCAN_DMA_EVT_TX == evt)
    {
        DMAUtilsXferStop(pDcanDmaCfg->dmaType, pDcanDmaCfg->txEvtInfo.instNum,
                         pDcanDmaCfg->txEvtInfo.chNum,
                         DMA_XFER_TRIGGER_TYPE_EVENT);
    }
    else if(DCAN_DMA_EVT_RX == evt)
    {
        DMAUtilsXferStop(pDcanDmaCfg->dmaType, pDcanDmaCfg->rxEvtInfo.instNum,
                         pDcanDmaCfg->rxEvtInfo.chNum,
                         DMA_XFER_TRIGGER_TYPE_EVENT);
    }
    else
    {
        retStat = E_FAIL;
    }

    return retStat;
}


