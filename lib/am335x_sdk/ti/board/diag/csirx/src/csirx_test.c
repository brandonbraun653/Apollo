/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 *  \file   csirx_test.c
 *
 *  \brief  csirx diagnostic test file.
 *
 *  Targeted Functionality: Verification of csirx interface.
 *
 *  Operation: This test verifies CSIRX interface by displaying
               the FPD Link test pattern on the connected HDMI monitor.
 *
 *  Supported SoCs: J721E.
 *
 *  Supported Platforms: j721e_evm.
 */

#include "csirx_test.h"

extern BoardDiag_CsirxDispObj gDispObj;

BoardDiag_CsirxObj gCsirxObj;
/* Memory buffer to hold data */
#pragma DATA_SECTION(gFrms, ".data_buffer")
#pragma DATA_ALIGN(gFrms, 128)
static uint8_t gFrmDropBuf[(BOARD_DIAG_CSIRX_FRAME_WIDTH * BOARD_DIAG_CSIRX_FRAME_BPP)] __attribute__(( aligned(128), section(".data_buffer")));
uint8_t gFrms[(BOARD_DIAG_CSIRX_FRAMES_PER_CH * BOARD_DIAG_CSIRX_MAX_CH)][BOARD_DIAG_CSIRX_FRAME_SIZE] __attribute__(( aligned(128), section(".data_buffer")));

/*
 * UDMA driver objects
 */
struct Udma_DrvObj gUdmaDrvObj;

SemaphoreP_Handle gLockSem;

I2C_Handle gI2cHandle = NULL;
extern SemaphoreP_Handle gLockSem_dss;

/**
 * \brief   This is a Callback function for frame completion.
 *
 * \param   handle    [IN]      Fvid2 handle
 *          cbData    [IN]      Data back by CB function
 *          reserved  [IN]      Not used, reserved.
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxFrameCompletionCb(Fvid2_Handle handle,
                                               Ptr appData,
                                               Ptr reserved)
{
    uint32_t frmIdx = 0U;
    uint32_t idx = 0U;
    int32_t  retVal = FVID2_SOK;
    static Fvid2_FrameList frmList;
    Fvid2_Frame *pFrm;
    BoardDiag_CsirxObj *csirxObj = (BoardDiag_CsirxObj *) appData;

    Fvid2FrameList_init(&frmList);
    retVal = Fvid2_dequeue(csirxObj->drvHandle,
                           &frmList,
                           0U,
                           FVID2_TIMEOUT_NONE);
    if (retVal != FVID2_SOK)
    {
        return -1;
    }

    csirxObj->numFramesRcvd += frmList.numFrames;

    for (frmIdx = 0; frmIdx < frmList.numFrames; frmIdx++)
    {
        pFrm = frmList.frames[frmIdx];
        csirxObj->chFrmCnt[pFrm->chNum]++;

        if (pFrm->status != FVID2_FRAME_STATUS_COMPLETED)
        {
            idx = (csirxObj->frameErrorCnt % BOARD_DIAG_CSIRX_ERR_FRAME_LOG_MAX);
            csirxObj->errFrmCh[idx] = pFrm->chNum;
            csirxObj->errFrmNo[idx] = csirxObj->chFrmCnt[pFrm->chNum];
            csirxObj->errFrmTs[idx] = (uint32_t)(pFrm->timeStamp64 / 1000U);
            csirxObj->frameErrorCnt++;
        }
    }

    /* Queue back de-queued frames,
       last param i.e. streamId is unused in DRV */
    retVal = Fvid2_queue(csirxObj->drvHandle, &frmList, 0U);
    if (retVal != FVID2_SOK)
    {
        UART_printf("Capture Queue Failed\n");
        return -1;
    }

    /* Post semaphore here for sending next Image */
    SemaphoreP_post(gLockSem);

    return 0;
}

/**
 * \brief   This function deletes buffer and de-initialize CSIRX.
 *
 * \param   csirxObj    [IN]      CSIRX Capture Test Object pointer
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxDeinit(BoardDiag_CsirxObj *csirxObj)
{
    static Fvid2_FrameList frmList;
    int32_t retVal = FVID2_SOK;

    Fvid2FrameList_init(&frmList);

    /* Disable Error Events */
    retVal = Fvid2_control(csirxObj->drvHandle,
                           IOCTL_CSIRX_UNREGISTER_EVENT,
                           CSIRX_EVENT_GROUP_ERROR,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Events un-registration Failed\n");
        I2C_close(gI2cHandle);
        return -1;
    }

    retVal = Fvid2_delete(csirxObj->drvHandle, NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("FVID2 Delete Failed\n");
        I2C_close(gI2cHandle);
        return -1;
    }
    else
    {
        csirxObj->drvHandle = NULL;
    }

    /* Close I2C channel */
    I2C_close(gI2cHandle);

    /* Delete semaphore */
    SemaphoreP_delete(gLockSem);

    retVal = Csirx_deInit();
    if (retVal != FVID2_SOK)
    {
        return -1;
    }

    return 0;
}

/**
 * \brief   This function configures remote sensors.
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxSensorConfig(void)
{
    Board_STATUS ret = BOARD_SOK;
    uint8_t regData;

    regData = 0x00;
    ret = Board_i2c8BitRegWr(gI2cHandle,
                             BOARD_DIAG_CSIRX_SENSOR_SLAVE_ADDR,
                             0xB0,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return -1;
    }

    regData = 0x01;
    ret = Board_i2c8BitRegWr(gI2cHandle,
                             BOARD_DIAG_CSIRX_SENSOR_SLAVE_ADDR,
                             0xB1,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return -1;
    }

    regData = 0x01;
    ret = Board_i2c8BitRegWr(gI2cHandle,
                             BOARD_DIAG_CSIRX_SENSOR_SLAVE_ADDR,
                             0xB2,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return -1;
    }

    regData = 0xF0;
    ret = Board_i2c8BitRegWr(gI2cHandle,
                             BOARD_DIAG_CSIRX_SENSOR_SLAVE_ADDR,
                             0x20,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return -1;
    }

    regData = 0x01;
    ret = Board_i2c8BitRegWr(gI2cHandle,
                             BOARD_DIAG_CSIRX_SENSOR_SLAVE_ADDR,
                             0x32,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return -1;
    }

    regData = 0x03;
    ret = Board_i2c8BitRegWr(gI2cHandle,
                             BOARD_DIAG_CSIRX_SENSOR_SLAVE_ADDR,
                             0x33,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return -1;
    }

    regData = 0x12;
    ret = Board_i2c8BitRegWr(gI2cHandle,
                             BOARD_DIAG_CSIRX_SENSOR_SLAVE_ADDR,
                             0x32,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return -1;
    }

    regData = 0x03;
    ret = Board_i2c8BitRegWr(gI2cHandle,
                             BOARD_DIAG_CSIRX_SENSOR_SLAVE_ADDR,
                             0x33,
                             &regData,
                             1U,
                             BOARD_I2C_TRANSACTION_TIMEOUT);
    if(ret != 0)
    {
        return -1;
    }

    return 0;
}

/**
 * \brief   This function frees the frames.
 *
 * \param   csirxObj    [IN]      CSIRX Capture Test Object pointer
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxCaptFreeFrames(BoardDiag_CsirxObj *csirxObj)
{
    static Fvid2_FrameList frmList;
    int32_t retVal = FVID2_SOK;

    /* for every stream and channel in a capture handle */
    Fvid2FrameList_init(&frmList);

    /* De-queue any frames queued more than needed */
    retVal = Fvid2_dequeue(csirxObj->drvHandle,
                           &frmList,
                           0U,
                           FVID2_TIMEOUT_NONE);
    if (retVal != FVID2_SOK)
    {
        return -1;
    }

    return 0;
}

/**
 * \brief   This function queues the frames.
 *
 * \param   csirxObj    [IN]      CSIRX Capture Test Object pointer
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxAllocQFrames(BoardDiag_CsirxObj *csirxObj)
{
    static Fvid2_FrameList frmList;
    Fvid2_Frame  *pFrm;
    uint32_t chIdx = 0U;
    uint32_t frmIdx = 0U;
    int32_t retVal = FVID2_SOK;

    /* for every channel in a capture handle,
       allocate memory for and queue frames */
    Fvid2FrameList_init(&frmList);
    frmList.numFrames = 0U;

    for (chIdx = 0U; chIdx < csirxObj->createPrms.numCh; chIdx++)
    {
        for (frmIdx = 0U; frmIdx < BOARD_DIAG_CSIRX_FRAMES_PER_CH; frmIdx++)
        {
            /* assign frames memory */
            pFrm = (Fvid2_Frame *)
                    &csirxObj->frames[(chIdx * BOARD_DIAG_CSIRX_FRAMES_PER_CH) + frmIdx];
            pFrm->addr[0U] =
               (uint64_t)&gFrms[(chIdx * BOARD_DIAG_CSIRX_FRAMES_PER_CH) + frmIdx][0U];
            pFrm->chNum = csirxObj->createPrms.chCfg[chIdx].chId;
            pFrm->appData = csirxObj;
            frmList.frames[frmList.numFrames] = pFrm;
            frmList.numFrames++;
        }
    }

    retVal = Fvid2_queue(csirxObj->drvHandle, &frmList, 0U);
    if (retVal != FVID2_SOK)
    {
        UART_printf("Capture Queue failed\n");
        return -1;
    }

    return 0;
}

/**
 * \brief   This function initializes FPD module and captures test pattern.
 *
 * \param   csirxObj    [IN]      CSIRX Capture Test Object pointer
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxCaptureTest(BoardDiag_CsirxObj *csirxObj)
{
    int32_t retVal = FVID2_SOK;
    volatile uint32_t lastFrameNo = 0U;
    int8_t ret;

    /* Allocate and queue all available frames */
    ret = BoardDiag_csirxAllocQFrames(csirxObj);
    if (ret != 0)
    {
        return -1;
    }

    /* Configure sensor here */
    ret = BoardDiag_csirxSensorConfig();
    if (ret != 0)
    {
        UART_printf("Sensor configuration failed\n");
        return -1;
    }

    retVal = Fvid2_start(csirxObj->drvHandle, NULL);
    if (retVal != FVID2_SOK)
    {
        UART_printf("Capture Start Failed\n");
        return -1;
    }

    /* Wait for reception completion */
    if (csirxObj->numFramesToCapture != 0U)
    {
        while (csirxObj->numFramesRcvd < csirxObj->numFramesToCapture)
        {
            /* Pend on semaphore until last frame is received */
            SemaphoreP_pend(gLockSem, SemaphoreP_WAIT_FOREVER);
            if ((lastFrameNo == 0U) && (csirxObj->numFramesRcvd))
            {
                lastFrameNo = csirxObj->numFramesRcvd;
            }
        }
    }

    retVal = Fvid2_stop(csirxObj->drvHandle, NULL);
    if (retVal != FVID2_SOK)
    {
        UART_printf("Capture Stop Failed\n");
        return -1;
    }

    ret = BoardDiag_csirxCaptFreeFrames(csirxObj);
    if (ret != 0)
    {
        return -1;
    }

    Csirx_instStatusInit(&csirxObj->captStatus);

    retVal = Fvid2_control(csirxObj->drvHandle,
                            IOCTL_CSIRX_GET_INST_STATUS,
                            &csirxObj->captStatus,
                            NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Get Capture Status Failed\n");
        return -1;
    }

    return 0;
}

/**
 * \brief   This function gets I2C handle to access remote sensors.
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxSetupI2CInst(void)
{
    I2C_HwAttrs i2cConfig;
    I2C_Params i2cParams;
    uint8_t i2cInst = 0U;
    uint8_t i2cAddr = 0U;
    uint8_t index;

    /* Initialize I2C Driver */
    for(index = 0; index < I2C_HWIP_MAX_CNT; index++)
    {
        I2C_socGetInitCfg(index, &i2cConfig);
        i2cConfig.enableIntr = false;
        I2C_socSetInitCfg(index, &i2cConfig);
    }

    /* Initializes the I2C */
    I2C_init();

    /* Initializes the I2C Parameters */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz; /* 400KHz */

    Board_fpdU960GetI2CAddr(&i2cInst, &i2cAddr, BOARD_CSI_INST_0);

    /* Configures the I2C instance with the passed parameters*/
    gI2cHandle = I2C_open(i2cInst, &i2cParams);
    if(gI2cHandle == NULL)
    {
        UART_printf("I2C Open failed\n");
        return -1;
    }

    return 0;
}

/**
 * \brief   This function configures CSIRX.
 *
 * \param   csirxObj    [IN]      CSIRX Capture Test Object pointer
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxConfig(BoardDiag_CsirxObj *csirxObj)
{
    SemaphoreP_Params semParams;
    Fvid2_TimeStampParams tsParams;
    Csirx_DPhyCfg dphyCfg;
    Csirx_EventPrms eventPrms;
    int32_t retVal = FVID2_SOK;
    int8_t ret;

    /* Fvid2_create() */
    csirxObj->drvHandle = Fvid2_create(CSIRX_CAPT_DRV_ID,
                                       csirxObj->instId,
                                       &csirxObj->createPrms,
                                       &csirxObj->createStatus,
                                       &csirxObj->cbPrms);

    if ((csirxObj->drvHandle == NULL) ||
        (csirxObj->createStatus.retVal != FVID2_SOK))
    {
        return -1;
    }

    /* Set CSIRX D-PHY configuration parameters */
    Csirx_initDPhyCfg(&dphyCfg);
    dphyCfg.inst = CSIRX_INSTANCE_ID_0;
    dphyCfg.leftLaneBandSpeed = CSIRX_LANE_BAND_SPEED_1500_TO_1750_MBPS;
    dphyCfg.rightLaneBandSpeed = CSIRX_LANE_BAND_SPEED_1500_TO_1750_MBPS;
    dphyCfg.psmClkFreqDiv = 0x53 ;
    retVal = Fvid2_control(csirxObj->drvHandle,
                           IOCTL_CSIRX_SET_DPHY_CONFIG,
                           &dphyCfg,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("D-PHY configuration failed\n");
        return -1;
    }

    /* Register Error Events */
    Csirx_eventPrmsInit(&eventPrms);
    retVal = Fvid2_control(csirxObj->drvHandle,
                           IOCTL_CSIRX_REGISTER_EVENT,
                           &eventPrms,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Event Registration failed\n");
        return -1;
    }

    /* Allocate instance semaphore */
    SemaphoreP_Params_init(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    gLockSem = SemaphoreP_create(1U, &semParams);
    if (gLockSem == NULL)
    {
        UART_printf("Instance semaphore create failed\n");
        return -1;
    }

    ret = BoardDiag_csirxSetupI2CInst();
    if (ret != 0)
    {
        return -1;
    }

    tsParams.timeStampFxn = (Fvid2_TimeStampFxn)&TimerP_getTimeInUsecs;
    /* register time stamping function */
    retVal = Fvid2_control(csirxObj->drvHandle,
                           FVID2_REGISTER_TIMESTAMP_FXN,
                           &tsParams,
                           NULL);

    if (retVal != FVID2_SOK)
    {
        return -1;
    }

    return 0;
}

/**
 * \brief   This function initializes CSIRX.
 *
 * \param   csirxObj    [IN]      CSIRX Capture Test Object pointer
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxInit(BoardDiag_CsirxObj *csirxObj)
{
    uint32_t instId;
    int32_t retVal = FVID2_SOK;
    int32_t dmaStatus = UDMA_SOK;
    Fvid2_InitPrms initPrms;
    Udma_InitPrms  udmaInitPrms;
    Udma_DrvHandle drvHandle = &gUdmaDrvObj;

    csirxObj->initPrms.drvHandle = drvHandle;

    /* Fvid2 init */
    Fvid2InitPrms_init(&initPrms);

    retVal = Fvid2_init(&initPrms);
    if (retVal != FVID2_SOK)
    {
        UART_printf("Fvid2 Init Failed\n");
        return -1;
    }

    /* UDMA driver init */
    instId = UDMA_INST_ID_MAIN_0;
    UdmaInitPrms_init(instId, &udmaInitPrms);

    dmaStatus = Udma_init(drvHandle, &udmaInitPrms);
    if(UDMA_SOK != dmaStatus)
    {
        UART_printf("UDMA Init Failed\n");
        return -1;
    }

    /* System init */
    retVal = Csirx_init(&csirxObj->initPrms);
    if (retVal != FVID2_SOK)
    {
        UART_printf("CSIRX Init Failed\n");
        return -1;
    }

    return 0;
}

/**
 * \brief   This function initializes CSIRX object structure.
 *
 * \param   csirxObj    [IN]      CSIRX Capture Test Object pointer
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static void BoardDiag_csirxObjInit(BoardDiag_CsirxObj *csirxObj)
{
    uint8_t loopCnt = 0U;

    /* set instance to be used for capture */
    csirxObj->instId = CSIRX_INSTANCE_ID_0;
    /* set instance initialization parameters */
    /* This will be updated once UDMA init is done */
    Csirx_initParamsInit(&csirxObj->initPrms);//null drv handle
    /* set instance configuration parameters */
    Csirx_createParamsInit(&csirxObj->createPrms);
    csirxObj->createPrms.numCh = BOARD_DIAG_CSIRX_MAX_CH;

    /* set channel configuration parameters */
    for (loopCnt = 0U; loopCnt < csirxObj->createPrms.numCh; loopCnt++)
    {
        csirxObj->chFrmCnt[loopCnt] = 0U;
        csirxObj->createPrms.chCfg[loopCnt].chId = loopCnt;
        csirxObj->createPrms.chCfg[loopCnt].chType = CSIRX_CH_TYPE_CAPT;
        csirxObj->createPrms.chCfg[loopCnt].vcNum = loopCnt;
        csirxObj->createPrms.chCfg[loopCnt].inCsiDataType = BOARD_DIAG_CSIRX_IMAGE_DF;
        csirxObj->createPrms.chCfg[loopCnt].outFmt.width = BOARD_DIAG_CSIRX_FRAME_WIDTH;
        csirxObj->createPrms.chCfg[loopCnt].outFmt.height = BOARD_DIAG_CSIRX_FRAME_HEIGHT;
        csirxObj->createPrms.chCfg[loopCnt].outFmt.pitch[0U] =
                                                BOARD_DIAG_CSIRX_FRAME_PITCH;
        csirxObj->createPrms.chCfg[loopCnt].outFmt.dataFormat =
                                                FVID2_DF_BGRX32_8888;
        csirxObj->createPrms.chCfg[loopCnt].outFmt.ccsFormat =
                                                BOARD_DIAG_CSIRX_IMAGE_STORAGE_FORMAT;
    }

    /* set module configuration parameters */
    csirxObj->createPrms.instCfg.enableCsiv2p0Support = (uint32_t)TRUE;
    csirxObj->createPrms.instCfg.numDataLanes = 4U;
    csirxObj->createPrms.instCfg.enableErrbypass = (uint32_t)FALSE;

    for (loopCnt = 0U ;
         loopCnt < csirxObj->createPrms.instCfg.numDataLanes ;
         loopCnt++)
    {
        csirxObj->createPrms.instCfg.dataLanesMap[loopCnt] = (loopCnt + 1U);
    }

    /* set frame drop buffer parameters */
    csirxObj->createPrms.frameDropBufLen =
                                (BOARD_DIAG_CSIRX_FRAME_WIDTH * BOARD_DIAG_CSIRX_FRAME_BPP);
    csirxObj->createPrms.frameDropBuf = (uint64_t)&gFrmDropBuf;
    /* This will be updated once Fvid2_create() is done */
    csirxObj->createStatus.retVal = FVID2_SOK;
    csirxObj->drvHandle = NULL;
    Fvid2CbParams_init(&csirxObj->cbPrms);
    csirxObj->cbPrms.cbFxn   = (Fvid2_CbFxn) &BoardDiag_csirxFrameCompletionCb;
    csirxObj->cbPrms.appData = csirxObj;

    csirxObj->numFramesToCapture = BOARD_DIAG_CSIRX_NUM_OF_FRAMES;
    csirxObj->numFramesRcvd = 0U;
    csirxObj->frameErrorCnt = 0U;
    csirxObj->maxWidth = BOARD_DIAG_CSIRX_FRAME_WIDTH;
    csirxObj->maxHeight = BOARD_DIAG_CSIRX_FRAME_HEIGHT;

    /* Initialize capture instance status */
    Csirx_instStatusInit(&csirxObj->captStatus);
}

/**
 *  \brief    This function runs CSIRX test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_CsirxTest(void)
{
    BoardDiag_CsirxObj *csirxObj;
    Board_I2cInitCfg_t i2cCfg;
    int32_t retVal = FVID2_SOK;
    int8_t ret;

    UART_printf("\n************************************************\n");
    UART_printf  ("*                  CSIRX Test                  *\n");
    UART_printf  ("************************************************\n");

    UART_printf("\nRunning CSIRX Test...\n");
    i2cCfg.i2cInst   = 6U;
    i2cCfg.socDomain = BOARD_SOC_DOMAIN_MAIN;
    Board_setI2cInitConfig(&i2cCfg);

    /* I2C Mux select */
    Board_i2cIoExpInit();
    Board_i2cIoExpSetPinDirection(0x20U,
                                  ONE_PORT_IOEXP,
                                  PORTNUM_0,
                                  PIN_NUM_0,
                                  PIN_DIRECTION_OUTPUT);

    /* Pulling the select input line to low to select port 1 */
    Board_i2cIoExpPinLevelSet(0x20U,
                              ONE_PORT_IOEXP,
                              PORTNUM_0,
                              PIN_NUM_0,
                              GPIO_SIGNAL_LEVEL_HIGH);
    Board_i2cIoExpDeInit();

    csirxObj = &gCsirxObj;
    memset(csirxObj, 0U, sizeof (BoardDiag_CsirxObj));

    /* Initialize CSIRX object for current capture context */\
    BoardDiag_csirxObjInit(csirxObj);

    UART_printf("Initializing CSIRX\n");
    ret = BoardDiag_csirxInit(csirxObj);
    if (ret != 0)
    {
        return -1;
    }

    BoardDiag_csirxConfigHdmi();

    UART_printf("Configuring CSIRX\n");
    ret = BoardDiag_csirxConfig(csirxObj);
    if (ret != 0)
    {
        return -1;
    }

    /* CSI test function */
    ret = BoardDiag_csirxCaptureTest(csirxObj);
    if (retVal != FVID2_SOK)
    {
        UART_printf("CSIRX Capture test failed");
        return -1;
    }

    ret = BoardDiag_csirxDispRunTest(&gDispObj);
    if (ret != 0)
    {
        UART_printf("CSIRX Display failed\n");
        return -1;
    }

    ret = BoardDiag_csirxDeinit(csirxObj);
    if (ret != 0)
    {
        UART_printf("CSIRX De-Init Failed\n");
        return -1;
    }

    ret = BoardDiag_csirxDispDeInit();
    if (ret != 0)
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief   CSIRX Diagnostic test main function
 *
 *  \return  int - CSIRX Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
    int8_t ret;

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    ret = BoardDiag_CsirxTest();
    if(ret != 0)
    {
        UART_printf("\nCSIRX Test Failed\n");
        return -1;
    }
    else
    {
        UART_printf("\nCSIRX Test Passed\n");
    }

    return 0;
}
