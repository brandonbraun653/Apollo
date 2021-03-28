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
 *  \file   hdmi_test_v2.c
 *
 *  \brief  hdmi diagnostic test file.
 *
 *  Targeted Functionality: Verification of hdmi interface.
 *
 *  Operation: This test verifies DPI0 interface by displaying color bar
 *             on connected hdmi monitor.
 *
 *  Supported SoCs: J721E.
 *
 *  Supported Platforms: j721e_evm.
 */

#include "hdmi_test_v2.h"

/**
 *  \brief    This function power downs hdmi bridge.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_hdmiSetPwrDownMode(void)
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
 *  \brief    This function de-initializes DSS DPI0.
 *
 *  \param    displayObj    [IN/OUT]  Display object structure.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_hdmiDeInitDss(BoardDiag_HdmiDisplayObj *displayObj)
{
    int32_t  retVal = FVID2_SOK;

    /* Delete DCTRL handle */
    retVal = Fvid2_delete(displayObj->dctrlHandle, NULL);
    retVal |= Dss_deInit();
    retVal |= Fvid2_deInit(NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("DCTRL handle delete failed!!!\r\n");
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
static int8_t BoardDiag_hdmiEnableColorBar(BoardDiag_HdmiDisplayObj *displayObj)
{
    uint32_t regVal;
    int32_t retVal;
    Dss_DctrlVpParams *vpParams;
    Dss_DctrlOverlayParams *overlayParams;

    vpParams = &displayObj->vpParams;
    overlayParams = &displayObj->overlayParams;
    Dss_dctrlOverlayParamsInit(overlayParams);

    retVal = Fvid2_control(displayObj->dctrlHandle,
                           IOCTL_DSS_DCTRL_SET_VP_PARAMS,
                           vpParams,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Dctrl Set VP Params IOCTL Failed\n");
        return -1;
    }

    /* Select DPI0 */
    regVal = CSL_REG32_RD(CSL_DSS0_DISPC_0_COMMON_M_BASE +
                          CSL_DSS_COMMON_M_DISPC_CONNECTIONS);
    CSL_FINS(regVal,
             DSS_COMMON_M_DISPC_CONNECTIONS_DPI_0_CONN,
             CSL_DSS_COMMON_M_DISPC_CONNECTIONS_DPI_0_CONN_VAL_VP2);

    CSL_REG32_WR(CSL_DSS0_DISPC_0_COMMON_M_BASE +
                 CSL_DSS_COMMON_M_DISPC_CONNECTIONS, regVal);

    overlayParams->overlayId = CSL_DSS_OVERLAY_ID_2;
    overlayParams->colorbarEnable = TRUE;

    retVal = Fvid2_control(displayObj->dctrlHandle,
                           IOCTL_DSS_DCTRL_SET_OVERLAY_PARAMS,
                           overlayParams,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("DCTRL Set Overlay Params IOCTL Failed\n");
        return -1;
    }

    return 0;
}

/**
 *  \brief    This function stops displaying color bar.
 *
 *  \param    displayObj    [IN]      Display object structure.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_hdmiStopDisplay(BoardDiag_HdmiDisplayObj *displayObj)
{
    int32_t retVal;
    Dss_DctrlVpParams *vpParams;

    vpParams = &displayObj->vpParams;

    retVal = Fvid2_control(displayObj->dctrlHandle,
                           IOCTL_DSS_DCTRL_STOP_VP,
                           vpParams,
                           NULL);
    if(retVal != FVID2_SOK)
    {
        UART_printf("VP Stop Failed\n");
        return -1;
    }

    return 0;
}

/**
 *  \brief    This function configures DPI0 signal.
 *
 *  \param    displayObj    [IN]      Display object structure.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_hdmiDisplayCfg(BoardDiag_HdmiDisplayObj *displayObj)
{
    Dss_DctrlVpParams *vpParams;
    int8_t ret;

    vpParams = &displayObj->vpParams;
    Dss_dctrlVpParamsInit(vpParams);

    vpParams->vpId = CSL_DSS_VP_ID_2;

    vpParams->lcdOpTimingCfg.mInfo.standard = FVID2_STD_1080P_60; /* 4K Resolution */
    vpParams->lcdOpTimingCfg.dvoFormat = FVID2_DV_GENERIC_DISCSYNC;
    vpParams->lcdOpTimingCfg.videoIfWidth = FVID2_VIFW_24BIT;

    vpParams->lcdPolarityCfg.actVidPolarity = FVID2_POL_HIGH;
    vpParams->lcdPolarityCfg.pixelClkPolarity = FVID2_EDGE_POL_FALLING;
    vpParams->lcdPolarityCfg.hsPolarity = FVID2_POL_HIGH;
    vpParams->lcdPolarityCfg.vsPolarity = FVID2_POL_HIGH;

    ret = BoardDiag_hdmiEnableColorBar(displayObj);
    if(ret != 0)
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief    This function initializes DSS DPI0.
 *
 *  \param    displayObj    [IN/OUT]  HDMI display object structure.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_hdmiInitDss(BoardDiag_HdmiDisplayObj *displayObj)
{
    int32_t         retVal = FVID2_SOK;
    Fvid2_InitPrms  initPrms;

    Fvid2InitPrms_init(&initPrms);
    retVal = Fvid2_init(&initPrms);
    if(retVal != FVID2_SOK)
    {
        UART_printf("Fvid2 Init Failed\n");
        return -1;
    }

    Dss_initParamsInit(&displayObj->initParams);
    retVal = Dss_init(&displayObj->initParams);
    if(retVal != FVID2_SOK)
    {
        UART_printf("DSS Init Failed\n");
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
        UART_printf("DCTRL Create Failed\n");
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
static int8_t BoardDiag_hdmiHotPlugDetect(void)
{
    Board_STATUS status;
    Board_I2cInitCfg_t i2cCfg;
    uint8_t hpdVal;

    i2cCfg.i2cInst    = BOARD_DIAG_HDMI_HPD_EXP_INSTANCE;
    i2cCfg.socDomain  = BOARD_SOC_DOMAIN_MAIN;
    i2cCfg.enableIntr = false;
    Board_setI2cInitConfig(&i2cCfg);
    status = Board_i2cIoExpInit();
    if(status != BOARD_SOK)
    {
        return -1;
    }

    /* Setting the pin direction as output */
    status = Board_i2cIoExpSetPinDirection(BOARD_DIAG_HDMI_HPD_SLAVE_ADDR,
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
    status = Board_i2cIoExpPinLevelGet(BOARD_DIAG_HDMI_HPD_SLAVE_ADDR,
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
static int8_t BoardDiag_hdmiDpiClkCfg(void)
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
                                          BOARD_DIAG_DSS0_DPI_CLK_FREQ,
                                          TISCI_MSG_FLAG_CLOCK_ALLOW_FREQ_CHANGE,
                                          SCICLIENT_SERVICE_WAIT_FOREVER);
    if (status != PM_SUCCESS)
    {
        return -1;
    }
    return 0;
}

/**
 *  \brief    This function runs HDMI test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_HdmiRunTest(void)
{
    Board_STATUS status;
    BoardDiag_HdmiDisplayObj dispApp_Obj;
    char userInput;
    uint8_t timeOutCnt = 0;
    int8_t ret;

    UART_printf("\n***********************************************\n");
    UART_printf  ("*                  HDMI Test                  *\n");
    UART_printf  ("***********************************************\n");

    UART_printf("\nRunning HDMI Test...\n");

    ret = BoardDiag_hdmiDpiClkCfg();
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
    while(timeOutCnt <= BOARD_DIAG_HDMI_HPD_DETECT_TIMEOUT)
    {
        ret = BoardDiag_hdmiHotPlugDetect();
        if(ret == 1)
        {
            break;
        }
        else if(ret == -1)
        {
            return -1;
        }

        if(timeOutCnt == 0)
            UART_printf("Waiting for HDMI cable to detect...\n\r");
        BOARD_delay(1000000);
        timeOutCnt++;
    }

    if(timeOutCnt > BOARD_DIAG_HDMI_HPD_DETECT_TIMEOUT)
    {
        UART_printf("HDMI cable detection timeout completed\n\r");
        UART_printf("HDMI cable not detected!!\n\r");
        UART_printf("Exiting\n\r");
        BoardDiag_hdmiSetPwrDownMode();
        return -1;
    }
    else
    {
        UART_printf("HDMI cable detected\n\r");
    }

    ret = BoardDiag_hdmiInitDss(&dispApp_Obj);
    if(ret != 0)
    {
        return -1;
    }

    /* Create driver */
    ret = BoardDiag_hdmiDisplayCfg(&dispApp_Obj);
    if(ret != 0)
    {
        return -1;
    }

    UART_printf("press 'y' if color bar displayed on HDMI monitor,\n");
    UART_printf("Else press any other key for failure\n");
    UART_scanFmt("%c", &userInput);

    /* Power down HDMI bridge */
    ret = BoardDiag_hdmiStopDisplay(&dispApp_Obj);
    if(ret != 0)
    {
        return -1;
    }

    ret = BoardDiag_hdmiDeInitDss(&dispApp_Obj);
    if(ret != 0)
    {
        return -1;
    }

    ret = BoardDiag_hdmiSetPwrDownMode();
    if(ret != 0)
    {
        UART_printf("Power down HDMI bridge failed\n");
        return -1;
    }
    if((userInput != 'y') && (userInput != 'Y'))
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief   HDMI Diagnostic test main function
 *
 *  \return  int - HDMI Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
    int8_t ret = 0;

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

    ret = BoardDiag_HdmiRunTest();
    if(ret != 0)
    {
        UART_printf("\nHDMI Test Failed\n");
        return -1;
    }
    else
    {
        UART_printf("\nHDMI Test Passed\n");
    }

    return 0;
}
