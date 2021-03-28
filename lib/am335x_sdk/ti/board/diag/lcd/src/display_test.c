/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   dispaly_test.c
 *
 *  \brief  LCD Display diagnostic test file
 *
 *  Targeted Functionality: Verifying the basic functionality of LCD
 *  display interface.
 *
 *  Operation: This test is used to send data to the LCD Display
 *             interface.
 *
 *  Supported SoCs: AM65xx.
 *
 *  Supported Platforms: am65xx_evm & am65xx_idk.
 *
 */

#include "display_test.h"

#if defined (DIAG_STRESS_TEST) && defined (__aarch64__)
#include "dss_display_buffer1.h"
#include "dss_display_buffer2.h"
#endif

volatile uint32_t wait = 1U;
volatile int32_t isrCount = 0;
uint32_t vpAddr, overlayAddr;
uint32_t vpId, vpMask;
#if defined (DIAG_STRESS_TEST) && defined (__aarch64__)
uint32_t width, height, dataFormat, frameAddr;
uint32_t pipeAddr;
uint32_t pipeType;
#endif

hEcapHandle hEcap = (hEcapHandle)CSL_ECAP0_CTL_STS_BASE;

/**
 *
 * \brief    This function is used to set the duty cycle of the PWM waveform.
 *
 * \param    dutyCycle [IN] : Value of the duty cycle to be set.
 *                      50  - 50% duty cycle.
 *                      75  - 75% duty cycle.
 *
 * \return   ECAP SUCCESS    - On Success.
 *           ECAP_ERR        - On Failure.
 *
 */
static int8_t BoardDiag_pwm_set_duty_cycle(uint8_t dutyCycle)
{
    uint32_t acmpValue;

    if (dutyCycle <= 100)
    {
        acmpValue = ECAP_CAP1_APRD_VALUE;
        acmpValue = ((acmpValue * dutyCycle) / 100);

        /* Configure ECAP to generate PWM waveform with dutyCycle */
        CSL_FINS(hEcap->CAP1, ECAP_CAP1_CAP1, ECAP_CAP1_APRD_VALUE);
        CSL_FINS(hEcap->CAP2, ECAP_CAP2_CAP2, acmpValue);

        return 0;
    }

    UART_printf("pwmSetDutyCycle: Invalid input - "
                 "dutyCycle is more than 100\n");

    return -1;
}
#if !defined(DIAG_STRESS_TEST)
static int8_t BoardDiag_lcd_backlight_test()
{
    int32_t ret = 0;
    int8_t  count;

    UART_printf("\n\n\rIncreasing the brightness by varying the\n\r"
                "duty cycle percentage from 0 to 100...\n\r");
    /* Increase the LCD back light brightness from 0 to 100% */
    for (count = 0; count <= 100; count++)
    {
        ret = BoardDiag_pwm_set_duty_cycle(count);
        if(ret != 0)
        {
            return -1;
        }

        /* Wait for 60 milliSec's */
        BOARD_delay(60000);
    }

    /* Wait for 10 milliSec's */
    BOARD_delay(10000);

    UART_printf("\n\n\rDecreasing the brightness by varying the\n\r"
                "duty cycle percentage from 100 to 0...\n\r");
    /* Decrease the LCD back light brightness from 100 to 0% */
    for(count = 100; count >= 0; count--)
    {
        ret = BoardDiag_pwm_set_duty_cycle(count);
        if(ret != 0)
        {
            return -1;
        }

        /* Wait for 60 milliSec's */
        BOARD_delay(60000);
    }

    /* Wait for 10 milliSec's */
    BOARD_delay(10000);

    return ret;
}
#endif
static void App_displayISR(void *handle)
{
    isrCount++;

    CSL_dssClearVpIntr((CSL_dss_commRegs *)(CSL_DSS0_COMMON_BASE),
                        vpId,
                        CSL_DSS_VP_INTR_VSYNC_MASK);
    CSL_dssClearDispcIntr((CSL_dss_commRegs *)(CSL_DSS0_COMMON_BASE),
                          vpId);

    if (isrCount == DSS_RUN_COUNT)
    {
        CSL_dssVpEnable((CSL_dss_vpRegs *)(vpAddr),FALSE);
        wait = 0U;
    }
}

static void App_configureOldiIO(void)
{
    uint32_t regVal;
    regVal = CSL_REG32_RD(CSL_CTRL_MMR0_CFG0_BASE +
                          CSL_MAIN_CTRL_MMR_CFG0_OLDI_DAT0_IO_CTRL);
    CSL_FINS(regVal,
             MAIN_CTRL_MMR_CFG0_OLDI_DAT0_IO_CTRL_PWRDN_TX,
             FALSE);
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE +
                 CSL_MAIN_CTRL_MMR_CFG0_OLDI_DAT0_IO_CTRL, regVal);

    regVal = CSL_REG32_RD(CSL_CTRL_MMR0_CFG0_BASE +
                          CSL_MAIN_CTRL_MMR_CFG0_OLDI_DAT1_IO_CTRL);
    CSL_FINS(regVal,
             MAIN_CTRL_MMR_CFG0_OLDI_DAT1_IO_CTRL_PWRDN_TX,
             FALSE);
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE +
                 CSL_MAIN_CTRL_MMR_CFG0_OLDI_DAT1_IO_CTRL, regVal);

    regVal = CSL_REG32_RD(CSL_CTRL_MMR0_CFG0_BASE +
                          CSL_MAIN_CTRL_MMR_CFG0_OLDI_DAT2_IO_CTRL);
    CSL_FINS(regVal,
             MAIN_CTRL_MMR_CFG0_OLDI_DAT2_IO_CTRL_PWRDN_TX,
             FALSE);
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE +
                 CSL_MAIN_CTRL_MMR_CFG0_OLDI_DAT2_IO_CTRL, regVal);

    regVal = CSL_REG32_RD(CSL_CTRL_MMR0_CFG0_BASE +
                          CSL_MAIN_CTRL_MMR_CFG0_OLDI_DAT3_IO_CTRL);
    CSL_FINS(regVal,
             MAIN_CTRL_MMR_CFG0_OLDI_DAT3_IO_CTRL_PWRDN_TX,
             FALSE);
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE +
                 CSL_MAIN_CTRL_MMR_CFG0_OLDI_DAT3_IO_CTRL, regVal);

    regVal = CSL_REG32_RD(CSL_CTRL_MMR0_CFG0_BASE +
                          CSL_MAIN_CTRL_MMR_CFG0_OLDI_CLK_IO_CTRL);
    CSL_FINS(regVal,
             MAIN_CTRL_MMR_CFG0_OLDI_CLK_IO_CTRL_PWRDN_TX,
             FALSE);
    CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE +
                 CSL_MAIN_CTRL_MMR_CFG0_OLDI_CLK_IO_CTRL, regVal);
}

static int32_t App_configureLCD(void)
{
    int32_t retVal = CSL_PASS;
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UNLOCK_MMR;
    boardStatus = Board_init(boardCfg);

    if (boardStatus != BOARD_SOK)
    {
        retVal = CSL_EFAIL;
        UART_printf("Board Init Failed\n");
    }

    if (CSL_PASS == retVal)
    {
        Board_i2cIoExpInit();
        retVal = Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                               PORTNUM_1,
                                               PIN_NUM_0,
                                               PIN_DIRECTION_OUTPUT);
        if(retVal != 0)
        {
            UART_printf("Setting the direction of LCD Enable line to "
                        "output failed\n\r");
            return -1;
        }

        /* Pull the LCD enable to high */
        retVal = Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                           PORTNUM_1,
                                           PIN_NUM_0,
                                           GPIO_SIGNAL_LEVEL_HIGH);
        if(retVal != 0)
        {
            UART_printf("Pulling the LCD line HIGH using I2C IO Exp "
                        "failed\n\r");
            return -1;
        }

        UART_printf("LCD configured successfully\n");
    }

    return retVal;
}


/**
 *  \brief    The function performs the LCD display test by sending the
 *            data and displaying it on to the LCD Display unit.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_display_test(void)
{
    int32_t retVal = 0;
    uint32_t resetOldi = 0U;
    CSL_DssVpLcdSignalPolarityCfg lcdPolarityCfg;
    CSL_DssVpLcdOpTimingCfg lcdCfg;
    CSL_DssVpOldiCfg oldiCfg;
#if defined (DIAG_STRESS_TEST) && defined (__aarch64__)
    uint8_t count = 0;
    CSL_DssVidPipeCfg vidPipeCfg;
    CSL_DssVidPipeAlphaCfg pipeAlphaCfg;
    CSL_DssOverlayCfg overlayCfg;
    CSL_DssOverlayLayerCfg overlayLayerCfg;
    CSL_DssOverlayPipePosCfg overlayPipePosCfg;
    uint32_t flag = 0x1;
#endif

    /* Initialize structures */
    UART_printf("DSS application started...\n");
    CSL_dssVpLcdSignalPolarityCfgInit(&lcdPolarityCfg);
    CSL_dssVpLcdOpTimingCfgInit(&lcdCfg);
    CSL_dssVpOldiCfgInit(&oldiCfg);
#if defined (DIAG_STRESS_TEST) && defined (__aarch64__)
    CSL_dssVidPipeCfgInit(&vidPipeCfg);
    CSL_dssVidPipeAlphaCfgInit(&pipeAlphaCfg);
    CSL_dssOverlayCfgInit(&overlayCfg);
    CSL_dssOverlayLayerCfgInit(&overlayLayerCfg);
    CSL_dssOverlayPipePosCfgInit(&overlayPipePosCfg);

#if(1U == BUFFERS_RUNTIME)
    char uartInput = '0';
    width = BUFF_WIDTH_480P;
    height = BUFF_HEIGHT_480P;
    dataFormat = FVID2_DF_BGR24_888;
    frameAddr = (uint32_t)&dss_app_buffer[0];
#else
    width = 640;
    height = 400;
    dataFormat = FVID2_DF_BGRA32_8888;
    frameAddr = (uint32_t)&gDispArray1[0U];
#endif
#endif

    /* Configure LCD */
    retVal = App_configureLCD();

#if defined (DIAG_STRESS_TEST) && defined (__aarch64__)
    for(count=0;count<10;count++)
    {
#endif
    if (CSL_PASS == retVal)
    {
        if(TEST_VP_INSTANCE == CSL_DSS_VP_ID_2)
        {
            overlayAddr = CSL_DSS0_OVR2_BASE;
            vpAddr = CSL_DSS0_VP2_BASE;
            vpId = CSL_DSS_VP_ID_2;
            vpMask = CSL_DSS_DISPC_INTR_VP2_MASK;
        }
        else
        {
            overlayAddr = CSL_DSS0_OVR1_BASE;
            vpAddr = CSL_DSS0_VP1_BASE;
            vpId = CSL_DSS_VP_ID_1;
            vpMask = CSL_DSS_DISPC_INTR_VP1_MASK;
        }
#if defined (DIAG_STRESS_TEST) && defined (__aarch64__)
        if(TEST_VID_PIPE == CSL_DSS_VID_PIPE_ID_VID1)
        {
            pipeAddr = CSL_DSS0_VID_BASE;
            pipeType = CSL_DSS_VID_PIPE_TYPE_VID;
        }
        else
        {
            pipeAddr = CSL_DSS0_VIDL1_BASE;
            pipeType = CSL_DSS_VID_PIPE_TYPE_VIDL;
        }
#if (1U == BUFFERS_RUNTIME)
        /* Copy image buffer */
        memset(&dss_app_buffer[0], 0x80, width*height*3);

        UART_printf("Load Image using loadRaw command and then press '1'\n");
        UART_printf("Command is:\n");
        UART_printf("loadRaw(0x90000000, 0, \"C:\\\\Image_rgb888_prog_packed_720_480.tigf\", 32, false);\n");
        UART_printf("Check load address in linker command file\n");

        do
        {
            scanf("%c", &uartInput);
        } while ('1' != uartInput);
#endif
#endif
        /* Reset DSS, make sure all timing generators are disabled before
         * issuing the reset */
        CSL_dssVpEnable((CSL_dss_vpRegs *)(CSL_DSS0_VP1_BASE),FALSE);
        CSL_dssVpEnable((CSL_dss_vpRegs *)(CSL_DSS0_VP2_BASE),FALSE);
        CSL_dssModuleReset((CSL_dss_commRegs *)(CSL_DSS0_COMMON_BASE));

#if defined (DIAG_STRESS_TEST) && defined (__aarch64__)
        CSL_dssOverlayColorBarEnable((CSL_dss_overlayRegs *)(overlayAddr),flag);
#else
        CSL_dssOverlayColorBarEnable((CSL_dss_overlayRegs *)(overlayAddr),TRUE);
#endif

#if defined (DIAG_STRESS_TEST) && defined (__aarch64__)
       /* Set Pipe Configuration */
        vidPipeCfg.pipeType = pipeType;
        vidPipeCfg.inFmt.width = width;
        vidPipeCfg.inFmt.height = height;
        vidPipeCfg.inFmt.pitch[FVID2_RGB_ADDR_IDX] = width*NUM_BYTES_PER_PIXEL;
        vidPipeCfg.inFmt.dataFormat = dataFormat;
        vidPipeCfg.inFmt.scanFormat = FVID2_SF_PROGRESSIVE;
#if (UPSCALING_ENABLE == 1U)
        vidPipeCfg.outWidth = width+200U;
        vidPipeCfg.outHeight = height+100U;
        vidPipeCfg.scEnable = TRUE;
#elif (DOWNSCALING_ENABLE == 1U)
        vidPipeCfg.outWidth = width-200U;
        vidPipeCfg.outHeight = height-100U;
        vidPipeCfg.scEnable = TRUE;
#else
        vidPipeCfg.outWidth = width;
        vidPipeCfg.outHeight = height;
        vidPipeCfg.scEnable = FALSE;
#endif
        retVal = CSL_dssVidPipeSetConfig(
                                    (CSL_dss_pipeRegs *)(pipeAddr),
                                    (const CSL_DssVidPipeCfg *)(&vidPipeCfg),
                                    NULL);
        if(CSL_PASS != retVal)
        {
            UART_printf("Failed to configure Video Pipe\n");
        }

        /* Set alpha parameters */
        pipeAlphaCfg.globalAlpha = 0xFF;
        pipeAlphaCfg.preMultiplyAlpha = FALSE;
        CSL_dssVidPipeSetAlphaConfig(
                               (CSL_dss_pipeRegs *)(pipeAddr),
                               (const CSL_DssVidPipeAlphaCfg *)(&pipeAlphaCfg));

        /* Set Frame address */
        CSL_dssVidPipeSetBuffAddr((CSL_dss_pipeRegs *)(pipeAddr),
                                  FVID2_FID_TOP,
                                  frameAddr,
                                  0x0U);
        UART_printf("Video Pipe configuration done \n");

#if (NUM_VID_PIPES == 2U)
    /* Set Pipe Configuration */
    vidPipeCfg.pipeType = CSL_DSS_VID_PIPE_TYPE_VIDL;
    vidPipeCfg.inFmt.width = 300U;
    vidPipeCfg.inFmt.height = 240U;
    vidPipeCfg.inFmt.pitch[FVID2_RGB_ADDR_IDX] = 300U*NUM_BYTES_PER_PIXEL;
    vidPipeCfg.outWidth = 300U;
    vidPipeCfg.outHeight = 240U;
    vidPipeCfg.scEnable = FALSE;
    retVal = CSL_dssVidPipeSetConfig((CSL_dss_pipeRegs *)(CSL_DSS0_VIDL1_BASE),
                                     (const CSL_DssVidPipeCfg *)(&vidPipeCfg),
                                      NULL);
    if(CSL_PASS != retVal)
    {
        UART_printf("Failed to configure second Video Pipe\n");
    }

    /* Set alpha parameters */
    pipeAlphaCfg.globalAlpha = 0xFF;
    pipeAlphaCfg.preMultiplyAlpha = FALSE;
    CSL_dssVidPipeSetAlphaConfig(
                            (CSL_dss_pipeRegs *)(CSL_DSS0_VIDL1_BASE),
                            (const CSL_DssVidPipeAlphaCfg *)(&pipeAlphaCfg));

    frameAddr = (uint32_t) &gDispArray2[0U];

    /* Set Frame address */
    CSL_dssVidPipeSetBuffAddr((CSL_dss_pipeRegs *)(CSL_DSS0_VIDL1_BASE),
                              FVID2_FID_TOP,
                              frameAddr,
                              0x0U);
    UART_printf("Second Video Pipe configuration done \n");
#endif
        /* Configure background color */
        overlayCfg.colorKeyEnable = TRUE;
        overlayCfg.colorKeySel = CSL_DSS_OVERLAY_TRANS_COLOR_SRC;
        overlayCfg.transColorKeyMin = 0x0U;
        overlayCfg.transColorKeyMax = 0x0U;
        overlayCfg.backGroundColor = 0xc8c800U;
        CSL_dssOverlaySetConfig((CSL_dss_overlayRegs *)(overlayAddr),
                                (const CSL_DssOverlayCfg *)(&overlayCfg));

        /* Configure overlay layer and position */
#if (NUM_VID_PIPES == 2U)
        overlayLayerCfg.layerEnable = TRUE;
        overlayLayerCfg.inputPipe = CSL_DSS_VID_PIPE_ID_VIDL1;
        overlayLayerCfg.layerNum = CSL_DSS_OVERLAY_LAYER_NUM_0;
        CSL_dssOverlaySetLayerConfig(
                            (CSL_dss_overlayRegs *)(overlayAddr),
                            (const CSL_DssOverlayLayerCfg *)(&overlayLayerCfg));
        overlayPipePosCfg.layerPos.startX = 900U;
        overlayPipePosCfg.layerPos.startY = 500U;
        CSL_dssOverlaySetPipePosConfig(
                        (CSL_dss_overlayRegs *)(overlayAddr),
                        (const CSL_DssOverlayPipePosCfg *)(&overlayPipePosCfg),
                        CSL_DSS_OVERLAY_LAYER_NUM_0);
        UART_printf("Overlay configuration for VIDL done \n");
#endif
        overlayLayerCfg.layerEnable = TRUE;
        overlayLayerCfg.inputPipe = TEST_VID_PIPE;
        overlayLayerCfg.layerNum = CSL_DSS_OVERLAY_LAYER_NUM_1;
        CSL_dssOverlaySetLayerConfig(
                        (CSL_dss_overlayRegs *)(overlayAddr),
                        (const CSL_DssOverlayLayerCfg *)(&overlayLayerCfg));
        overlayPipePosCfg.layerPos.startX = 0x10U;
        overlayPipePosCfg.layerPos.startY = 0x10U;
        CSL_dssOverlaySetPipePosConfig(
                        (CSL_dss_overlayRegs *)(overlayAddr),
                        (const CSL_DssOverlayPipePosCfg *)(&overlayPipePosCfg),
                        CSL_DSS_OVERLAY_LAYER_NUM_1);
#endif
        UART_printf("Overlay configuration done \n");

        /* Set LCD polarity */
        lcdPolarityCfg.actVidPolarity = FVID2_POL_HIGH;
        lcdPolarityCfg.pixelClkPolarity = FVID2_EDGE_POL_FALLING;
        lcdPolarityCfg.hsPolarity = FVID2_POL_HIGH;
        lcdPolarityCfg.vsPolarity = FVID2_POL_HIGH;
        CSL_dssVpSetLcdSignalPolarityConfig((CSL_dss_vpRegs *)(vpAddr),
                                            (const CSL_DssVpLcdSignalPolarityCfg *)
                                            (&lcdPolarityCfg));
        /* Set LCD timing */
        /* LCD config doesn't match the standard 1080P_60, hence use custom */
        lcdCfg.mInfo.standard = FVID2_STD_CUSTOM;
        lcdCfg.mInfo.width = 1280U;
        lcdCfg.mInfo.height = 800U;
        lcdCfg.mInfo.hFrontPorch = 48U;
        lcdCfg.mInfo.hBackPorch = 80U;
        lcdCfg.mInfo.hSyncLen = 32U;
        lcdCfg.mInfo.vFrontPorch = 3U;
        lcdCfg.mInfo.vBackPorch = 14U;
        lcdCfg.mInfo.vSyncLen = 6U;
        lcdCfg.dvoFormat = FVID2_DV_GENERIC_DISCSYNC;
        lcdCfg.videoIfWidth = FVID2_VIFW_24BIT;
        retVal = CSL_dssVpSetLcdOpTimingConfig(
                                        (CSL_dss_vpRegs *)(vpAddr),
                                        (CSL_DssVpLcdOpTimingCfg *)(&lcdCfg));
        if(CSL_PASS != retVal)
        {
            UART_printf("Failed to set LCD Timing \n");
        }

        UART_printf("Video Port configuration done \n");
        /* Configure OLDI */
        App_configureOldiIO();
        CSL_dssVpOldiReset((CSL_dss_vpRegs *)(vpAddr));

        do
        {
            resetOldi = CSL_dssIsOldiResetDone((CSL_dss_commRegs *)(CSL_DSS0_COMMON_BASE));
        } while(resetOldi != 1U);

        CSL_dssVpSetOldiConfig((CSL_dss_vpRegs *)(vpAddr),
                               (const CSL_DssVpOldiCfg *)(&oldiCfg));
        CSL_dssVpOldiEnable((CSL_dss_vpRegs *)(vpAddr), TRUE);
#if defined (__aarch64__)
        Intc_Init(0);
        Intc_IntRegister(CSL_GIC0_INTR_DSS0_BUS_DISPC_INTR_REQ_0,
                         (IntrFuncPtr) App_displayISR,
                         0U);
        Intc_IntPrioritySet(CSL_GIC0_INTR_DSS0_BUS_DISPC_INTR_REQ_0, 1U, 0U);
        Intc_SystemEnable(CSL_GIC0_INTR_DSS0_BUS_DISPC_INTR_REQ_0);
#else
        Intc_Init();
        Intc_IntEnable(18U);
        Intc_IntSetSrcType(18U, (uint32_t)CSL_VIM_INTR_TYPE_LEVEL);
        Intc_IntRegister(18U, (IntrFuncPtr) App_displayISR, 0U);
        Intc_IntPrioritySet(18U, 1U, 0U);
        Intc_SystemEnable();
#endif
        CSL_dssEnableVpIntr((CSL_dss_commRegs *)(CSL_DSS0_COMMON_BASE),
                            vpId,
                            CSL_DSS_VP_INTR_VSYNC_MASK,
                            TRUE);
        CSL_dssEnableDispcIntr((CSL_dss_commRegs *)(CSL_DSS0_COMMON_BASE),
                               vpMask,
                               TRUE);
#if defined (DIAG_STRESS_TEST) && defined (__aarch64__)
        CSL_dssVidPipeEnable((CSL_dss_pipeRegs *)(pipeAddr), TRUE);
#if (NUM_VID_PIPES == 2U)
        CSL_dssVidPipeEnable((CSL_dss_pipeRegs *)(CSL_DSS0_VIDL1_BASE), TRUE);
#endif
#endif
        CSL_dssVpSetGoBit((CSL_dss_vpRegs *)(vpAddr));
        CSL_dssVpEnable((CSL_dss_vpRegs *)(vpAddr), TRUE);
    }

    //UART_printf("Display the colour bar with maximum brightness\n\r");
    /* '5' Sec Delay */
    BOARD_delay(5000000);
#if defined (__aarch64__)
    Intc_SystemDisable(CSL_GIC0_INTR_DSS0_BUS_DISPC_INTR_REQ_0);
#else
    Intc_IntDisable(18U);
    Intc_SystemDisable();
#endif
#if defined (DIAG_STRESS_TEST) && defined (__aarch64__)
flag = ~flag;
}
#endif
    return (0);
}

/**
 *
 * \brief    This function initializes the ECAP module and PWM driver.
 *           It also enables the back light with 50% duty cycle.
 *
 * No parameters.
 *
 * \return   ECAP_SUCCESS    - On Success
 *           ECAP_ERR        - On Failure
 *
 */
static void BoardDiag_pwm_init(uint32_t pwmssBaseAddr)
{
#if !(CSL_ECAP_FIXED)
    Uint32 baseAddr = 0;
    Uint32 value = 0;
#endif
    /* TODO ECAP control registers and interrupt registers are 16 bit.
     * But its wrongly defined as 32 bit registers in cslr_ecap.h.
     * Until a fix for that is in place, we will hardcode the ECCTL registers
     */
#if !(CSL_ECAP_FIXED) //Comment the code after fixing CSL
    baseAddr = CSL_ECAP0_CTL_STS_BASE;

    value = CSL_REG32_RD(baseAddr + ECAP_ECCTL1);
    value = value >> 16;
    value |= (ECAP_ECCTL2_APWM_MODE << 9) |
            (ECAP_ECCTL2_SYNCO_SEL_DISABLE << 6) |
            (ECAP_ECCTL2_APWM_POLARITY << 10) |
            (ECAP_ECCTL2_FREERUN_ENABLE << 4);

    CSL_REG32_WR(baseAddr + ECAP_ECCTL1, value << 16);

    BoardDiag_pwm_set_duty_cycle(50);
#endif

#if (CSL_ECAP_FIXED) //TODO Uncomment the code after fixing CSL

    /* Configure ECAP module to operate in APWM mode */
    CSL_FINS(hEcap->ECCTL2, ECAP_ECCTL2_CAP_APWM, ECAP_ECCTL2_APWM_MODE);

    /* Disable sync out */
    CSL_FINS(hEcap->ECCTL2, ECAP_ECCTL2_SYNCO_SEL, ECAP_ECCTL2_SYNCO_SEL_DISABLE);

    /* Configure ECAP to generate PWM waveform with 50% duty cycle. */
    BoardDiag_pwm_set_duty_cycle(100);

    /* Configures output polarity for APWM output. ECAP_PWM_OUT pin as High */
    CSL_FINS(hEcap->ECCTL2, ECAP_ECCTL2_APWMPOL, ECAP_ECCTL2_APWM_POLARITY);

    /* Disable APWM mode */
    CSL_FINS(hEcap->ECCTL2, ECAP_ECCTL2_CAP_APWM, ECAP_ECCTL2_APWM_MODE_DISABLE);

    /* Configures counter to free running */
    CSL_FINS(hEcap->ECCTL2, ECAP_ECCTL2_TSCTRSTOP, ECAP_ECCTL2_FREERUN_ENABLE);

    /* Configure ECAP module to operate in APWM mode */
    CSL_FINS(hEcap->ECCTL2, ECAP_ECCTL2_CAP_APWM, ECAP_ECCTL2_APWM_MODE);
#endif
}

void enableWKUPI2C(void)
{
    I2C_HwAttrs i2cCfg;

    I2C_socGetInitCfg(0, &i2cCfg);

    i2cCfg.baseAddr = CSL_WKUP_I2C0_CFG_BASE;
    i2cCfg.enableIntr = 0;

    I2C_socSetInitCfg(0, &i2cCfg);
}

/**
 *  \brief   LCD display panel Diagnostic test main function
 *
 *  \return  int - DSS panel Diagnostic test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    Board_STATUS status;
    int8_t ret = 0;
    bool isBoardDetected = false;
    Board_initCfg boardCfg;
#if !defined(DIAG_STRESS_TEST)
    char c;
#endif
#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    UART_printf("\n*********************************************\n");
    UART_printf  ("*              Display Test                 *\n");
    UART_printf  ("*********************************************\n");

    enableWKUPI2C();
    isBoardDetected = Board_detectBoard(LCD_BRD_DETECT);
    if(isBoardDetected)
    {
        UART_printf("\nLCD Board detect successfully\n");

        UART_printf("\nRunning LCD Display Test...\n");

#if defined(SOC_AM65XX)
       /* MCU I2C instance will be active by default for R5 core.
        * Need update HW attrs to enable MAIN I2C instance.
        */
        enableMAINI2C(0, CSL_I2C0_CFG_BASE);
#endif

        /* Initialize the PWM Module */
        BoardDiag_pwm_init(CSL_ECAP0_CTL_STS_BASE);

        ret = BoardDiag_display_test();
        if(ret != 0)
        {
            UART_printf("\nLCD Display Test Failed\n");
            return (ret);
        }
        else
        {
            UART_printf("\nLCD Display Test Successfull\n");
        }
#if !defined(DIAG_STRESS_TEST)
        UART_printf("\nRunning LCD Backlight Test\n");

        UART_printf("\nChanging Backlight... WAIT, Check the LCD panel");
        ret = BoardDiag_lcd_backlight_test();
        if(ret != 0)
        {
            UART_printf("\nLCD Backlight Test Failed\n");
            return (ret);
        }
        else
        {
#if !defined(DIAG_COMPLIANCE_TEST)
            UART_printf("  Press 'y' if Brightness is Increasing & Decreasing, Any other key for failure: ");
            UART_scanFmt("%c", &c);
#else
            c = 'y';
#endif
            if((c == 'y') || (c == 'Y'))
            {
                UART_printf("\rChange Backlight - PASS\n");
            }
            else
            {
                UART_printf("\rChange Backlight - FAIL\n");
                ret = -1;
                return ret;
            }
        }
#endif
#if !defined(DIAG_COMPLIANCE_TEST) && !defined(DIAG_STRESS_TEST)
        /* Disbale LCD by Pulling the LCD enable to LOW */
        Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  PORTNUM_1,
                                  PIN_NUM_0,
                                  GPIO_SIGNAL_LEVEL_LOW);

        UART_printf("\nRunning LCD Touch Detect Test\n");
        ret = BoardDiag_lcd_touch_detect_test();
        if(ret != 0)
        {
            UART_printf("LCD touch detect test failed!\n");
        }
        else
        {
            UART_printf("LCD touch detect test passed!\n");
        }
#endif
    }
    else
    {
        UART_printf("\nLCD Board detection failed\n");
        UART_printf("\nExiting test...\n");
    }

    return (ret);
}
