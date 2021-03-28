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
 *  \file   display_port_test.c
 *
 *  \brief  displayport diagnostic test file.
 *
 *  Targeted Functionality: Verification of displayport interface.
 *
 *  Operation: This test verifies DisplayPort interface by displaying color bar
 *             on connected DisplayPort monitor.
 *
 *  Supported SoCs: J721E.
 *
 *  Supported Platforms: j721e_evm.
 */

#include "display_port_test.h"

/**
 *  \brief    This function de-initializes DSS DP.
 *
 *  \param    displayObj    [IN/OUT]  Display object structure.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_dpDeInitDss(BoardDiag_DpDisplayObj *displayObj)
{
    int32_t ret;

    ret = Fvid2_control(displayObj->dctrlHandle,
                        IOCTL_DSS_DCTRL_STOP_VP,
                        &displayObj->vpParams,
                        NULL);
    if(ret != FVID2_SOK)
    {
        return -1;
    }

    /* Delete DCTRL handle */
    ret = Fvid2_delete(displayObj->dctrlHandle,
                       NULL);
    if(ret != FVID2_SOK)
    {
        return -1;
    }

    ret = Dss_deInit();
    if(ret != FVID2_SOK)
    {
        return -1;
    }

    ret = Fvid2_deInit(NULL);
    if(ret != FVID2_SOK)
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief    This function enables internal color bar
 *
 *  \param    displayObj    [IN]      Display object structure.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_dpEnableColorBar(BoardDiag_DpDisplayObj *displayObj)
{
    int32_t ret;
    Dss_DctrlVpParams *vpParams;
    Dss_DctrlOverlayParams *overlayParams;
    Dss_DctrlPathInfo *pathInfo;
    Dss_DctrlAdvVpParams *advVpParams;

    vpParams      = &displayObj->vpParams;
    overlayParams = &displayObj->overlayParams;
    pathInfo      = &displayObj->dctrlPathInfo;
    advVpParams   = &displayObj->advVpParams;

    Dss_dctrlOverlayParamsInit(overlayParams);
    Dss_dctrlPathInfoInit(pathInfo);

    pathInfo->edgeInfo[pathInfo->numEdges].startNode =
                                           BOARD_DIAG_DP_DCTRL_VID_NODE_ID;

    pathInfo->edgeInfo[pathInfo->numEdges].endNode =
                                           BOARD_DIAG_DP_DCTRL_OVERLAY_NODE_ID;

    pathInfo->numEdges++;

    pathInfo->edgeInfo[pathInfo->numEdges].startNode =
                                           BOARD_DIAG_DP_DCTRL_OVERLAY_NODE_ID;

    pathInfo->edgeInfo[pathInfo->numEdges].endNode =
                                           BOARD_DIAG_DP_DCTRL_VP_NODE_ID;

    pathInfo->numEdges++;

    pathInfo->edgeInfo[pathInfo->numEdges].startNode =
                                           BOARD_DIAG_DP_DCTRL_VP_NODE_ID;

    pathInfo->edgeInfo[pathInfo->numEdges].endNode =
                                           BOARD_DIAG_DP_DCTRL_OUT_NODE_ID;

    pathInfo->numEdges++;

    ret = Fvid2_control(displayObj->dctrlHandle,
                        IOCTL_DSS_DCTRL_SET_PATH,
                        pathInfo,
                        NULL);
    if(ret != FVID2_SOK)
    {
        UART_printf("Setting Display path failed\n");
        return -1;
    }

    ret = Fvid2_control(displayObj->dctrlHandle,
                        IOCTL_DSS_DCTRL_SET_VP_PARAMS,
                        vpParams,
                        NULL);
    if(ret != FVID2_SOK)
    {
        UART_printf("Setting VP param failed\n");
        return -1;
    }

    ret = Fvid2_control(displayObj->dctrlHandle,
                        IOCTL_DSS_DCTRL_SET_ADV_VP_PARAMS,
                        advVpParams,
                        NULL);
    if(ret != FVID2_SOK)
    {
        UART_printf("Setting Advance VP Params failed\n");
        return -1;
    }

    overlayParams->overlayId = BOARD_DIAG_DP_OVERLAY_ID;
    overlayParams->colorbarEnable = TRUE;

    ret = Fvid2_control(displayObj->dctrlHandle,
                        IOCTL_DSS_DCTRL_SET_OVERLAY_PARAMS,
                        overlayParams,
                        NULL);
    if(ret != FVID2_SOK)
    {
        UART_printf("Setting overlay params failed\n");
        return -1;
    }

    return 0;
}

/**
 *  \brief    This function configures Display Timing parameters.
 *
 *  \param    displayObj    [IN]      Display object structure.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_dpSetDispConfig(BoardDiag_DpDisplayObj *dispObj)
{
    Dss_DctrlVpParams *vpParams;
    int8_t ret;

    vpParams = &dispObj->vpParams;
    Dss_DctrlAdvVpParams *advVpParams;
    Dss_dctrlVpParamsInit(vpParams);

    advVpParams = &dispObj->advVpParams;

    Dss_dctrlAdvVpParamsInit(advVpParams);

    vpParams->vpId = BOARD_DIAG_DP_VP_ID;
    advVpParams->vpId = BOARD_DIAG_DP_VP_ID;
    vpParams->lcdOpTimingCfg.mInfo.standard   = FVID2_STD_1080P_60;
    vpParams->lcdOpTimingCfg.dvoFormat        = FVID2_DV_GENERIC_DISCSYNC;
    vpParams->lcdOpTimingCfg.videoIfWidth     = FVID2_VIFW_36BIT;

    vpParams->lcdPolarityCfg.actVidPolarity   = FVID2_POL_HIGH;
    vpParams->lcdPolarityCfg.pixelClkPolarity = FVID2_EDGE_POL_FALLING;
    vpParams->lcdPolarityCfg.hsPolarity       = FVID2_POL_HIGH;
    vpParams->lcdPolarityCfg.vsPolarity       = FVID2_POL_HIGH;

    advVpParams->lcdAdvSignalCfg.hVAlign = CSL_DSS_VP_HVSYNC_ALIGNED;
    advVpParams->lcdAdvSignalCfg.hVClkControl = CSL_DSS_VP_HVCLK_CONTROL_ON;
    advVpParams->lcdAdvSignalCfg.hVClkRiseFall = FVID2_EDGE_POL_RISING;

    ret = BoardDiag_dpEnableColorBar(dispObj);
    if(ret != 0)
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief    This function initializes DSS DP.
 *
 *  \param    displayObj    [IN/OUT]  Display object structure.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_dpInitDss(BoardDiag_DpDisplayObj *displayObj)
{
    int32_t retVal;
    Fvid2_InitPrms initPrms;

    Fvid2InitPrms_init(&initPrms);

    retVal = Fvid2_init(&initPrms);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Initializing Fvid2 Failed\n");
        return -1;
    }

    Dss_initParamsInit(&displayObj->initParams);
    displayObj->initParams.socParams.dpInitParams.isHpdSupported = FALSE;

    retVal = Dss_init(&displayObj->initParams);
    if(retVal != FVID2_SOK)
    {
        UART_printf("DSS init failed!\n");
        return -1;
    }

    /* Create DCTRL handle, used for common driver configuration */
    displayObj->dctrlHandle = Fvid2_create(DSS_DCTRL_DRV_ID,
                                           DSS_DCTRL_INST_0,
                                           NULL,
                                           NULL,
                                           NULL);
    if(displayObj->dctrlHandle == NULL)
    {
        UART_printf("Display Handle Create Failed\n");
        return -1;
    }

    return 0;
}

/**
 *  \brief   This function sets DP clock to generate 148.5MHz.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_dpConfigDpClk(void)
{
    int32_t status = PM_SUCCESS, regVal;

    UART_printf("Configuring DP clock...\n");
    status = Sciclient_pmSetModuleState(TISCI_DEV_SERDES_10G0,
                                        TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                                        TISCI_MSG_FLAG_AOP,
                                        SCICLIENT_SERVICE_WAIT_FOREVER);
    if(status != PM_SUCCESS)
    {
        return -1;
    }

    status = Sciclient_pmSetModuleState(TISCI_DEV_DSS_EDP0,
                                        TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                                        TISCI_MSG_FLAG_AOP,
                                        SCICLIENT_SERVICE_WAIT_FOREVER);
    if(status != PM_SUCCESS)
    {
        return -1;
    }

    status = Sciclient_pmSetModuleClkParent(TISCI_DEV_DSS0,
                                            TISCI_DEV_DSS0_DSS_INST0_DPI_1_IN_2X_CLK,
                                            TISCI_DEV_DSS0_DSS_INST0_DPI_1_IN_2X_CLK_PARENT_DPI0_EXT_CLKSEL_OUT0,
                                            SCICLIENT_SERVICE_WAIT_FOREVER);
    if(status != PM_SUCCESS)
    {
        return -1;
    }

    status = Sciclient_pmSetModuleState(TISCI_DEV_DSS0,
                                        TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                                        TISCI_MSG_FLAG_AOP,
                                        SCICLIENT_SERVICE_WAIT_FOREVER);
    if(status != PM_SUCCESS)
    {
        return -1;
    }

    status = Sciclient_pmModuleClkRequest(TISCI_DEV_DSS0,
                                          TISCI_DEV_DSS0_DSS_FUNC_CLK,
                                          TISCI_MSG_VALUE_CLOCK_SW_STATE_REQ,
                                          ADDITIONAL_CLK_STATE_FLAG,
                                          SCICLIENT_SERVICE_WAIT_FOREVER);
    if(status != PM_SUCCESS)
    {
        return -1;
    }

    status = Sciclient_pmSetModuleClkFreq(TISCI_DEV_DSS0,
                                          TISCI_DEV_DSS0_DSS_INST0_DPI_1_IN_2X_CLK,
                                          BOARD_DIAG_DP_DISPLAY_CLOCK,
                                          ADDITIONAL_CLK_STATE_FLAG,
                                          SCICLIENT_SERVICE_WAIT_FOREVER);
    if(status != PM_SUCCESS)
    {
        return -1;
    }

    status = Sciclient_pmModuleClkRequest(TISCI_DEV_DSS0,
                                          TISCI_DEV_DSS0_DSS_INST0_DPI_1_IN_2X_CLK,
                                          TISCI_MSG_VALUE_CLOCK_SW_STATE_REQ,
                                          ADDITIONAL_CLK_STATE_FLAG,
                                          SCICLIENT_SERVICE_WAIT_FOREVER);
    if(status != PM_SUCCESS)
    {
        return -1;
    }

    regVal = CSL_REG32_RD(CSL_CTRL_MMR0_CFG0_BASE +
                          CSL_MAIN_CTRL_MMR_CFG0_DSS_DISPC0_CLKSEL3);

    CSL_FINS(regVal,
             MAIN_CTRL_MMR_CFG0_DSS_DISPC0_CLKSEL3_DPI3_PCLK,
             0x5U);

    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE +
                 CSL_MAIN_CTRL_MMR_CFG0_DSS_DISPC0_CLKSEL3,
                 regVal);

    return 0;
}

/**
 *  \brief    This function runs DisplayPort test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_DpRunTest(void)
{
    BoardDiag_DpDisplayObj dispObj;
    int8_t ret;
    char userInput;

    UART_printf("\n***********************************************\n");
    UART_printf  ("*               DISPLAYPORT Test              *\n");
    UART_printf  ("***********************************************\n");

    UART_printf("\nRunning DisplayPort Test...\n");

    ret = BoardDiag_dpConfigDpClk();
    if(ret != 0)
    {
        UART_printf("Configuring DP clock failed!\n");
        return -1;
    }

    ret = BoardDiag_dpInitDss(&dispObj);
    if(ret != 0)
    {
        UART_printf("\nDisplayPort test failed");
        return -1;
    }

    ret = BoardDiag_dpSetDispConfig(&dispObj);
    if(ret != 0)
    {
        UART_printf("\nDisplayPort test failed");
        return -1;
    }

    UART_printf("\nIf color bar displayed on the connected DisplayPort monitor,");
    UART_printf("\n\rpress 'y' or press any other key ");
    UART_scanFmt("%c", &userInput);

    ret = BoardDiag_dpDeInitDss(&dispObj);
    if(ret != 0)
    {
        UART_printf("Failed in DSS de-initializes\n");
        UART_printf("\nDisplayPort test failed");
        return -1;
    }

    if((userInput != 'y') && (userInput != 'Y'))
    {
        UART_printf("\nDisplayPort test failed");
        return -1;
    }

    UART_printf("\nDisplayPort test passed");
    return 0;
}

/**
 *  \brief   DP Diagnostic test main function
 *
 *  \return  int - DP Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif

    /* Board Library Init. */
    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    return BoardDiag_DpRunTest();
}
