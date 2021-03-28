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
 *  \file csirx_display.c
 *
 *  \brief CSIRX display APIs that displays the image captured by CSIRX.
 */

#include "csirx_test.h"

BoardDiag_CsirxDispObj gDispObj;
extern uint8_t gFrms[(BOARD_DIAG_CSIRX_FRAMES_PER_CH * BOARD_DIAG_CSIRX_MAX_CH)][BOARD_DIAG_CSIRX_FRAME_SIZE];
SemaphoreP_Handle gLockSem_dss;
extern SemaphoreP_Handle gLockSem;

/**
 * \brief    This is display callback function.
 *
 * \param    handle    [IN]      Fvid2 handle
 *           dispData  [IN/OUT]  Data back by CB function
 *
 * \return  int32_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int32_t BoardDiag_csirxDispCbFxn(Fvid2_Handle handle, void *dispData)
{
    (void) SemaphoreP_post(gLockSem_dss);
    (void) SemaphoreP_post(gLockSem);
    
    return 0;
}

/**
 * \brief   This function de-initialize dss.
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
int8_t BoardDiag_csirxDispDeInit(void)
{
    int32_t retVal;

    /* Delete DCTRL handle */
    retVal = Dss_deInit();
    if(retVal != FVID2_SOK)
    {
        // UART_printf("Display De-init Failed\n");
        // return -1;
    }

    return 0;
}

/**
 * \brief   This function allocates and queues the frames.
 *
 * \param   dispObj    [IN]      Display object structure
 *          instObj    [IN]      Display instance object
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxDispAllocQFrames(const BoardDiag_CsirxDispObj *dispObj,
                                              DispApp_InstObj *instObj)
{
    Fvid2_Frame *frm;
    Fvid2_FrameList frmList;
    uint32_t frmId;
    uint32_t numFrames;
    int32_t  retVal;

    Fvid2FrameList_init(&frmList);
    frm = &instObj->frames[0U];
    numFrames = BOARD_DIAG_CSIRX_DISP_MAX_FRAME;

    /* init memory pointer for 'numFrames' */
    for(frmId = 0U; frmId < numFrames; frmId++)
    {
        /* init Fvid2_Frame to 0's  */
        Fvid2Frame_init(&frm[frmId]);

        frm[frmId].addr[0U] = (uint64_t) &gFrms[0][0U];

        frm[frmId].fid     = FVID2_FID_FRAME;
        frm[frmId].appData = instObj;

        /* Set number of frame in frame list - one at a time */
        frmList.numFrames  = 1U;
        frmList.frames[0U] = &frm[frmId];

        /*
         * queue the frames in frmList
         * All allocate frames are queued here as an example.
         * In general atleast 2 frames per channel need to queued
         * before starting display,
         * else frame will get dropped until frames are queued
         */
        retVal = Fvid2_queue(instObj->drvHandle, &frmList, 0U);
        if(retVal != FVID2_SOK)
        {
            UART_printf("Display Queue Failed\n");
            return -1;
        }
    }

    return 0;
}

/**
 * \brief   This function initialize DSS parameters.
 *
 * \param   dispObj    [IN]      Display object structure
 *
 */
static void BoardDiag_csirxDispInitParams(BoardDiag_CsirxDispObj *dispObj)
{
    uint32_t index = 0U;
    uint32_t numPipes = 0U;
    uint32_t planeIndex;
    Dss_DispParams *dispParams;
    DispApp_InstObj *instObj;

    numPipes = gDispAppTestParams.numTestPipes;

    for(index = 0U; index < numPipes; index++)
    {
        /* Initialize video pipes */
        instObj = &dispObj->instObj[index];
        instObj->instId = gDispAppTestParams.instId[index];
        Dss_dispCreateParamsInit(&instObj->createParams);

        Fvid2CbParams_init(&instObj->cbParams);

        instObj->cbParams.cbFxn   = &BoardDiag_csirxDispCbFxn;
        instObj->cbParams.appData = instObj;

        dispParams = &instObj->dispParams;

        Dss_dispParamsInit(dispParams);

        dispParams->pipeCfg.pipeType     = gDispAppTestParams.pipeType[index];
        dispParams->pipeCfg.inFmt.width  = gDispAppTestParams.inWidth[index];
        dispParams->pipeCfg.inFmt.height = gDispAppTestParams.inHeight[index];

        for(planeIndex = 0U; planeIndex < FVID2_MAX_PLANES; planeIndex++)
        {
            dispParams->pipeCfg.inFmt.pitch[planeIndex] =
                                        gDispAppTestParams.pitch[index][planeIndex];
        }

        dispParams->pipeCfg.inFmt.dataFormat =
                                        gDispAppTestParams.inDataFmt[index];
        dispParams->pipeCfg.inFmt.scanFormat =
                                        gDispAppTestParams.inScanFmt[index];
        dispParams->pipeCfg.outWidth  = gDispAppTestParams.outWidth[index];
        dispParams->pipeCfg.outHeight = gDispAppTestParams.outHeight[index];
        dispParams->pipeCfg.scEnable  = gDispAppTestParams.scEnable[index];

        dispParams->alphaCfg.globalAlpha =
                                gDispAppTestParams.globalAlpha[index];
        dispParams->alphaCfg.preMultiplyAlpha =
                                gDispAppTestParams.preMultiplyAlpha[index];
        dispParams->layerPos.startX = gDispAppTestParams.posx[index];
        dispParams->layerPos.startY = gDispAppTestParams.posy[index];

        Dss_dispPipeMflagParamsInit(&instObj->mflagParams);
    }
}

/**
 * \brief   This function configures DSS to display image.
 *
 * \param   dispObj    [IN]      Display object structure
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxDispConfig(BoardDiag_CsirxDispObj *dispObj)
{
    Dss_DctrlVpParams *vpParams;
    Dss_DctrlOverlayParams *overlayParams;
    Dss_DctrlOverlayLayerParams *layerParams;
    Dss_DctrlPathInfo *pathInfo;
    Dss_DctrlAdvVpParams *advVpParams;
    Dss_DctrlGlobalDssParams *globalDssParams;
    int32_t retVal;
    uint8_t index = 0;
    uint8_t pipeIdIndex = 0;

    vpParams        = &dispObj->vpParams;
    overlayParams   = &dispObj->overlayParams;
    layerParams     = &dispObj->layerParams;
    pathInfo        = &dispObj->dctrlPathInfo;
    advVpParams     = &dispObj->advVpParams;
    globalDssParams = &dispObj->globalDssParams;

    Dss_dctrlOverlayParamsInit(overlayParams);
    Dss_dctrlOverlayLayerParamsInit(layerParams);
    Dss_dctrlPathInfoInit(pathInfo);
    Dss_dctrlAdvVpParamsInit(advVpParams);
    Dss_dctrlGlobalDssParamsInit(globalDssParams);

    pathInfo->edgeInfo[pathInfo->numEdges].startNode = gDispAppTestParams.pipeNodeId[0U];
    pathInfo->edgeInfo[pathInfo->numEdges].endNode   = BOARD_DIAG_CSIRX_HDMI_OVERLAY_NODE_ID;
    pathInfo->numEdges++;
    pathInfo->edgeInfo[pathInfo->numEdges].startNode = BOARD_DIAG_CSIRX_HDMI_OVERLAY_NODE_ID;
    pathInfo->edgeInfo[pathInfo->numEdges].endNode   = TEST_DCTRL_VP_NODE_ID;
    pathInfo->numEdges++;
    pathInfo->edgeInfo[pathInfo->numEdges].startNode = TEST_DCTRL_VP_NODE_ID;
    pathInfo->edgeInfo[pathInfo->numEdges].endNode   = TEST_DCTRL_OUT_NODE_ID;
    pathInfo->numEdges++;

    if (gDispAppTestParams.numTestPipes > 1U)
    {
        for(index = 1U; index < gDispAppTestParams.numTestPipes; index++)
        {
            pathInfo->edgeInfo[pathInfo->numEdges].startNode =
                                            gDispAppTestParams.pipeNodeId[index];
            pathInfo->edgeInfo[pathInfo->numEdges].endNode =
                                            BOARD_DIAG_CSIRX_HDMI_OVERLAY_NODE_ID;
            pathInfo->numEdges++;
        }
    }

    retVal = Fvid2_control(dispObj->dctrlHandle,
                           IOCTL_DSS_DCTRL_SET_PATH,
                           pathInfo,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Setting Path IOCTL Failed\n");
        return -1;
    }

    retVal = Fvid2_control(dispObj->dctrlHandle,
                           IOCTL_DSS_DCTRL_SET_VP_PARAMS,
                           vpParams,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Setting VP Params IOCTL Failed\n");
        return -1;
    }

    overlayParams->overlayId = BOARD_DIAG_CSIRX_HDMI_OVERLAY_ID;
    overlayParams->colorbarEnable = FALSE;
    overlayParams->overlayCfg.colorKeyEnable = TRUE;
    overlayParams->overlayCfg.colorKeySel = CSL_DSS_OVERLAY_TRANS_COLOR_DEST;
    overlayParams->overlayCfg.backGroundColor = 0xb4eacdU;

    retVal = Fvid2_control(dispObj->dctrlHandle,
                           IOCTL_DSS_DCTRL_SET_OVERLAY_PARAMS,
                           overlayParams,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Setting Overlay Params IOCTL Failed\n");
        return -1;
    }

    layerParams->overlayId = BOARD_DIAG_CSIRX_HDMI_OVERLAY_ID;
    layerParams->pipeLayerNum[gDispAppTestParams.pipeId[0U]] =
                                                CSL_DSS_OVERLAY_LAYER_NUM_0;
    if(gDispAppTestParams.numTestPipes > 1U)
    {
        for(index = 1U; index < gDispAppTestParams.numTestPipes; index++)
        {
            layerParams->pipeLayerNum[gDispAppTestParams.pipeId[index]] = index;
        }
    }

    if(gDispAppTestParams.numTestPipes < CSL_DSS_VID_PIPE_ID_MAX)
    {
        for(index = gDispAppTestParams.numTestPipes; index < CSL_DSS_VID_PIPE_ID_MAX; index++)
        {
            layerParams->pipeLayerNum[gDispAppTestParams.invalidPipeId[pipeIdIndex++]] =
                                                CSL_DSS_OVERLAY_LAYER_INVALID;
        }
    }

    retVal = Fvid2_control(dispObj->dctrlHandle,
                           IOCTL_DSS_DCTRL_SET_LAYER_PARAMS,
                           layerParams,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Setting Layer Params IOCTL Failed\n");
        return -1;
    }

    retVal = Fvid2_control(dispObj->dctrlHandle,
                           IOCTL_DSS_DCTRL_SET_ADV_VP_PARAMS,
                           advVpParams,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Setting Advance VP Params IOCTL Failed\n");
        return -1;
    }

    retVal = Fvid2_control(dispObj->dctrlHandle,
                           IOCTL_DSS_DCTRL_SET_GLOBAL_DSS_PARAMS,
                           globalDssParams,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Setting Global DSS Params IOCTL Failed\n");
        return -1;
    }

    return 0;
}

/**
 * \brief   This function creates display buffer.
 *
 * \param   dispObj    [IN]      Display object structure
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxDispCreate(BoardDiag_CsirxDispObj *dispObj)
{
    int32_t retVal = FVID2_SOK;
    uint32_t index = 0U;
    SemaphoreP_Params semParams;
    Dss_DctrlVpParams *vpParams;
    DispApp_InstObj *instObj;
    int8_t ret;

    BoardDiag_csirxDispInitParams(dispObj);
    vpParams = &dispObj->vpParams;
    Dss_dctrlVpParamsInit(vpParams);

    vpParams->vpId = BOARD_DIAG_CSIRX_HDMI_VP_ID;

    vpParams->lcdOpTimingCfg.mInfo.standard = FVID2_STD_1080P_60;

    vpParams->lcdOpTimingCfg.dvoFormat = FVID2_DV_GENERIC_DISCSYNC;
    vpParams->lcdOpTimingCfg.videoIfWidth = FVID2_VIFW_24BIT;

    vpParams->lcdPolarityCfg.actVidPolarity = FVID2_POL_HIGH;
    vpParams->lcdPolarityCfg.pixelClkPolarity = FVID2_EDGE_POL_FALLING;
    vpParams->lcdPolarityCfg.hsPolarity = FVID2_POL_HIGH;
    vpParams->lcdPolarityCfg.vsPolarity = FVID2_POL_HIGH;

    ret = BoardDiag_csirxDispConfig(dispObj);
    if (ret != 0)
    {
        return -1;
    }

    for(index = 0U; index < gDispAppTestParams.numTestPipes; index++)
    {
        instObj = &dispObj->instObj[index];

        SemaphoreP_Params_init(&semParams);

        semParams.mode = SemaphoreP_Mode_BINARY;
        instObj->syncSem = SemaphoreP_create(0U, &semParams);

        gLockSem_dss = instObj->syncSem;

        instObj->drvHandle = Fvid2_create(DSS_DISP_DRV_ID,
                                          instObj->instId,
                                          &instObj->createParams,
                                          &instObj->createStatus,
                                          &instObj->cbParams);
        if((instObj->drvHandle == NULL) ||
           (instObj->createStatus.retVal != FVID2_SOK))
        {
            UART_printf("Display Create Failed\n");
            return -1;
        }

        retVal = Fvid2_control(instObj->drvHandle,
                               IOCTL_DSS_DISP_SET_DSS_PARAMS,
                               &instObj->dispParams,
                               NULL);
        if(retVal != FVID2_SOK)
        {
            // UART_printf("DSS Set Params IOCTL Failed\n");
            // return -1;
        }

        retVal = Fvid2_control(instObj->drvHandle,
                               IOCTL_DSS_DISP_SET_PIPE_MFLAG_PARAMS,
                               &instObj->mflagParams,
                               NULL);
        if(retVal != FVID2_SOK)
        {
            UART_printf("DSS Set Mflag Params IOCTL Failed\n");
            return -1;
        }

        retVal = BoardDiag_csirxDispAllocQFrames(dispObj, instObj);
        if(retVal != FVID2_SOK)
        {
            UART_printf("Display Alloc and Queue Failed\n");
            return -1;
        }
    }

    UART_printf("Display create complete\n");

    return 0;
}

/**
 * \brief   This function initialize dss.
 *
 * \param   dispObj    [IN]      Display object structure
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_csirxDispInit(BoardDiag_CsirxDispObj *dispObj)
{
    Dss_initParamsInit(&dispObj->initParams);

    Dss_init(&dispObj->initParams);

    /* Create DCTRL handle, used for common driver configuration */
    dispObj->dctrlHandle = Fvid2_create(DSS_DCTRL_DRV_ID,
                                        DSS_DCTRL_INST_0,
                                        NULL,
                                        NULL,
                                        NULL);
    if(dispObj->dctrlHandle == NULL)
    {
        UART_printf("Display Create Failed\n");
        return -1;
    }

    return 0;
}

/**
 * \brief   This function deletes display buffer and stops display.
 *
 * \param   dispObj    [IN]      Display object structure
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
static int8_t BoardDiag_csirxDispDelete(BoardDiag_CsirxDispObj *dispObj)
{
    Dss_DctrlVpParams *vpParams;
    Dss_DctrlPathInfo *pathInfo;
    Dss_DctrlVpErrorStats *pErrorStats;
    DispApp_InstObj *instObj;
    Dss_DispCurrentStatus currStatus;
    uint32_t index;
    int32_t retVal;

    vpParams = &dispObj->vpParams;
    pathInfo = &dispObj->dctrlPathInfo;
    pErrorStats = &dispObj->errorStats;

    for(index = 0U; index < gDispAppTestParams.numTestPipes; index++)
    {
        instObj = &dispObj->instObj[index];

        /* Check for DSS underflow errors */
        retVal = Fvid2_control(instObj->drvHandle,
                               IOCTL_DSS_DISP_GET_CURRENT_STATUS,
                               &currStatus,
                               NULL);
        if(retVal != FVID2_SOK)
        {
            UART_printf("Failed to get Display Status\n");
            return -1;
        }

        /* Print Synclost errors */
        if(currStatus.underflowCount != 0U)
        {
            UART_printf("Underflow occurred\n");
        }

        retVal = Fvid2_delete(instObj->drvHandle, NULL);
        if(retVal != FVID2_SOK)
        {
            UART_printf("Display Delete Failed\n");
            return -1;
        }
    }

    /* Check for DSS synclost errors */
    retVal = Fvid2_control(dispObj->dctrlHandle,
                           IOCTL_DSS_DCTRL_GET_VP_ERROR_STATS,
                           pErrorStats,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Failed to get VP Status\n");
        return -1;
    }

    /* Print Synclost errors */
    if(pErrorStats->syncLost != 0U)
    {
        UART_printf("Sync Lost occurred\n");
    }

    retVal = Fvid2_control(dispObj->dctrlHandle,
                           IOCTL_DSS_DCTRL_CLEAR_PATH,
                           pathInfo,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Clear Path Failed\n");
        return -1;
    }

    retVal = Fvid2_control(dispObj->dctrlHandle,
                           IOCTL_DSS_DCTRL_STOP_VP,
                           vpParams,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("VP Stop Failed\n");
        return -1;
    }

    UART_printf("Display delete complete\n");

    return 0;
}

/**
 * \brief   This function runs csirx display test.
 *
 * \param   dispObj    [IN]      Display object structure
 *
 * \return  int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 */
int8_t BoardDiag_csirxDispRunTest(BoardDiag_CsirxDispObj *dispObj)
{
    int32_t retVal = FVID2_SOK;
    uint32_t index = 0U;
    volatile uint32_t loopCount = 0U;
    DispApp_InstObj *instObj;
    Fvid2_FrameList  frmList;
    int8_t ret;
    char userInput;

    UART_printf("Initializing DSS\n");
    ret = BoardDiag_csirxDispInit(&gDispObj);
    if (ret != 0)
    {
        return -1;
    }

    /* Create driver */
    ret = BoardDiag_csirxDispCreate(dispObj);
    if (ret != 0)
    {
        return -1;
    }

    /* Start driver */
    for(index = 0U; index < gDispAppTestParams.numTestPipes; index++)
    {
        instObj = &dispObj->instObj[index];

        retVal = Fvid2_start(instObj->drvHandle, NULL);
        if(retVal != FVID2_SOK)
        {
            UART_printf("Display Start Failed\n");
            return -1;
        }
    }

    for(index = 0U; index < gDispAppTestParams.numTestPipes; index++)
    {
        instObj = &dispObj->instObj[index];

        retVal = Fvid2_dequeue(instObj->drvHandle,
                               &frmList,
                               0U,
                               FVID2_TIMEOUT_NONE);

        if(retVal != FVID2_SOK)
        {
            UART_printf("Display Dequeue Failed for test pipe - %d\n", index);
            break;
        }

    }

    UART_printf("If test pattern is displayed on HDMI monitor properly press 'y' ");
    UART_printf("Press any other key to indicate failure:\n");
    UART_scanFmt("%c", &userInput);

    for(index = 0U; index < gDispAppTestParams.numTestPipes; index++)
    {
        instObj = &dispObj->instObj[index];
        retVal  = Fvid2_stop(instObj->drvHandle, NULL);
        if(retVal != FVID2_SOK)
        {
            UART_printf("Display Stop Failed\n");
            return -1;
        }
    }

    /* Delete driver */
    ret = BoardDiag_csirxDispDelete(dispObj);
    if (ret != 0)
    {
        UART_printf("Display delete failed\n");
        return -1;
    }

    if((userInput != 'y') && (userInput != 'Y'))
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief    This function power downs hdmi bridge.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_csirxHdmiSetPwrDownMode(void)
{
    Board_STATUS status;
    Board_IoExpCfg_t ioExpCfg;

    UART_printf("Power down HDMI bridge\n");

    ioExpCfg.i2cInst     = BOARD_HDMI_IO_EXP_INSTANCE;
    ioExpCfg.socDomain   = BOARD_SOC_DOMAIN_MAIN;
    ioExpCfg.slaveAddr   = BOARD_HDMI_IO_SLAVE_ADDR;
    ioExpCfg.enableIntr  = false;
    ioExpCfg.ioExpType   = TWO_PORT_IOEXP;
    ioExpCfg.portNum     = PORTNUM_1;
    ioExpCfg.pinNum      = PIN_NUM_0;
    ioExpCfg.signalLevel = GPIO_SIGNAL_LEVEL_LOW;

    status = Board_control(BOARD_CTRL_CMD_SET_IO_EXP_PIN_OUT, &ioExpCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief    This function checks hot plug detection.
 *
 *  \return   int8_t
 *               0 - hotplug not detected
 *               1 - hotplug detected
 *              -1 - in case of error.
 */
static int8_t BoardDiag_csirxHdmiHotPlugDetect(void)
{
    Board_STATUS status;
    Board_I2cInitCfg_t i2cCfg;
    uint8_t hpdVal;

    i2cCfg.i2cInst    = BOARD_DIAG_CSIRX_HDMI_HPD_EXP_INSTANCE;
    i2cCfg.socDomain  = BOARD_SOC_DOMAIN_MAIN;
    i2cCfg.enableIntr = false;
    Board_setI2cInitConfig(&i2cCfg);

    status = Board_i2cIoExpInit();
    if(status != BOARD_SOK)
    {
        return -1;
    }

    /* Setting the pin direction as output */
    status = Board_i2cIoExpSetPinDirection(BOARD_DIAG_CSIRX_HDMI_HPD_SLAVE_ADDR,
                                           TWO_PORT_IOEXP,
                                           PORTNUM_1,
                                           PIN_NUM_2,
                                           PIN_DIRECTION_INPUT);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    BOARD_delay(1000);

    /* Pulling the hdmi power pin to low */
    status = Board_i2cIoExpPinLevelGet(BOARD_DIAG_CSIRX_HDMI_HPD_SLAVE_ADDR,
                                       TWO_PORT_IOEXP,
                                       PORTNUM_1,
                                       PIN_NUM_2,
                                       &hpdVal);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    Board_i2cIoExpDeInit();

    return hpdVal;
}

/**
 *  \brief   This function sets DPI0 clock to generate 148.5MHz.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_csirxHdmiDpiClkCfg(void)
{
    int32_t status;

    status = Sciclient_pmSetModuleClkParent(TISCI_DEV_DSS0,
                                            TISCI_DEV_DSS0_DSS_INST0_DPI_1_IN_2X_CLK,
                                            TISCI_DEV_DSS0_DSS_INST0_DPI_1_IN_2X_CLK_PARENT_DPI0_EXT_CLKSEL_OUT0,
                                            SCICLIENT_SERVICE_WAIT_FOREVER);
    if (status != PM_SUCCESS)
    {
        return -1;
    }

    /* Set the clock at the desirable frequency*/
    status = Sciclient_pmSetModuleClkFreq(TISCI_DEV_DSS0,
                                          TISCI_DEV_DSS0_DSS_INST0_DPI_1_IN_2X_CLK,
                                          BOARD_DIAG_CSIRX_DSS0_DPI_CLK_FREQ,
                                          TISCI_MSG_FLAG_CLOCK_ALLOW_FREQ_CHANGE,
                                          SCICLIENT_SERVICE_WAIT_FOREVER);
    if (status != PM_SUCCESS)
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief   This function configures HDMI
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_csirxConfigHdmi(void)
{
    Board_STATUS status;
    uint8_t timeOutCnt = 0;
    int8_t ret;

    ret = BoardDiag_csirxHdmiDpiClkCfg();
    if(ret != 0)
    {
        return -1;
    }

    /* Configure HDMI mux selection */
    status = Board_control(BOARD_CTRL_CMD_SET_HDMI_MUX, NULL);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    /* Power on HDMI bridge */
    status = Board_control(BOARD_CTRL_CMD_SET_HDMI_PD_HIGH, NULL);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    UART_printf("Detecting HPD..\n");

    while(timeOutCnt <= BOARD_DIAG_CSIRX_HDMI_HPD_DETECT_TIMEOUT)
    {
        ret = BoardDiag_csirxHdmiHotPlugDetect();
        if(ret == 1)
        {
            break;
        }
        else if(ret == -1)
        {
            return -1;
        }

        if(timeOutCnt == 0)
        {
            UART_printf("Waiting for HDMI cable to detect...\n\r");
        }

        BOARD_delay(1000000);

        timeOutCnt++;
    }

    if(timeOutCnt > BOARD_DIAG_CSIRX_HDMI_HPD_DETECT_TIMEOUT)
    {
        UART_printf("HDMI cable detection timeout completed\n\r");
        UART_printf("HDMI cable not detected!!\n\r");
        UART_printf("Exiting\n\r");
        BoardDiag_csirxHdmiSetPwrDownMode();
        return -1;
    }
    else
    {
        UART_printf("HDMI cable detected\n\r");
    }

    return 0;
}
