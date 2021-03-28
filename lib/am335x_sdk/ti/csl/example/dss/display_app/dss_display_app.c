/*
 *  Copyright (c) Texas Instruments Incorporated 2018
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
 */

/**
 *  \file dss_display_app.c
 *
 *  \brief DSS sample application.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <ti/csl/csl_dss.h>
#include <ti/csl/arch/csl_arch.h>
#if defined (SOC_AM65XX)
#include <ti/csl/csl_gpio.h>
#include <ti/board/board.h>
#include <ti/board/src/evmKeystone3/include/board_i2c_io_exp.h>
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* Number of Pipes should be 1 when loading buffers at run time.
 * Test Pipe Id should be VID1 when number of pipes is 2.
 */
#define BUFFERS_RUNTIME                (0U)
#define TEST_VID_PIPE                  (CSL_DSS_VID_PIPE_ID_VID1)
#define NUM_VID_PIPES                  (2U)
#define UPSCALING_ENABLE               (0U)
#define DOWNSCALING_ENABLE             (1U)

/* OLDI can be tested using VP1 */
#if defined (SOC_AM65XX)
#define TEST_VP_INSTANCE               (CSL_DSS_VP_ID_1)
#define TEST_VID1_BASE                 (CSL_DSS0_VID_BASE)
#define TEST_VIDL1_BASE                (CSL_DSS0_VIDL1_BASE)
#define TEST_COMMON_M_BASE             (CSL_DSS0_COMMON_BASE)
#else
#define TEST_VP_INSTANCE               (CSL_DSS_VP_ID_2)
#define TEST_VID1_BASE                 (CSL_DSS0_VID1_BASE)
#define TEST_VIDL1_BASE                (CSL_DSS0_VIDL1_BASE)
#define TEST_COMMON_M_BASE             (CSL_DSS0_DISPC_0_COMMON_M_BASE)
#endif
#define DSS_RUN_COUNT                  (30000U)
#define PWM_GPIO_PIN                   (86U)

#if (1U == BUFFERS_RUNTIME)
#define NUM_BYTES_PER_PIXEL            (3U)
#else
#define NUM_BYTES_PER_PIXEL            (4U)
#endif

#define NUM_BUFFERS                    (1U)
#define BUFF_WIDTH_1080P               (1920U)
#define BUFF_HEIGHT_1080P              (1080U)
#define BUFF_WIDTH_480P                (720U)
#define BUFF_HEIGHT_480P               (480U)

#define MAX_BUFFER_SIZE                (NUM_BUFFERS * NUM_BYTES_PER_PIXEL * \
                                        BUFF_HEIGHT_480P * \
                                        BUFF_WIDTH_480P)

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

static void App_print(const char *str);
static void App_displayISR(void *handle);
#if defined (SOC_AM65XX)
static void App_configureOldiIO(void);
static int32_t App_configureLCD(void);
#endif

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

#if (1U == BUFFERS_RUNTIME)
uint8_t __attribute__((section(".data_buffer"))) dss_app_buffer[
                                                            MAX_BUFFER_SIZE];
uint8_t __attribute__((aligned (4096))) dss_app_buffer[MAX_BUFFER_SIZE];
#else
#include "dss_display_buffer1.h"
#include "dss_display_buffer2.h"
#endif

volatile uint32_t wait = 1U;
volatile int32_t isrCount = 0;
uint32_t width, height, dataFormat, frameAddr;
uint32_t vpAddr, overlayAddr, pipeAddr;
uint32_t vpId, vpMask, pipeType;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*
 * Application main
 */
int main(void)
{
    int32_t retVal = CSL_PASS;
    CSL_DssVidPipeCfg vidPipeCfg;
    CSL_DssVidPipeAlphaCfg pipeAlphaCfg;
    CSL_DssOverlayCfg overlayCfg;
    CSL_DssOverlayLayerCfg overlayLayerCfg;
    CSL_DssOverlayPipePosCfg overlayPipePosCfg;
    CSL_DssVpLcdSignalPolarityCfg lcdPolarityCfg;
    CSL_DssVpLcdOpTimingCfg lcdCfg;
#if defined (SOC_AM65XX)
    uint32_t resetOldi = FALSE;
    CSL_DssVpOldiCfg oldiCfg;
#endif

    /* Initialize structures */
    App_print("DSS application started...\n");
    CSL_dssVidPipeCfgInit(&vidPipeCfg);
    CSL_dssVidPipeAlphaCfgInit(&pipeAlphaCfg);
    CSL_dssOverlayCfgInit(&overlayCfg);
    CSL_dssOverlayLayerCfgInit(&overlayLayerCfg);
    CSL_dssVpLcdSignalPolarityCfgInit(&lcdPolarityCfg);
    CSL_dssVpLcdOpTimingCfgInit(&lcdCfg);
    CSL_dssOverlayPipePosCfgInit(&overlayPipePosCfg);
#if defined (SOC_AM65XX)
    CSL_dssVpOldiCfgInit(&oldiCfg);
#endif

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

#if defined (SOC_AM65XX)
    /* Configure LCD */
    retVal = App_configureLCD();
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

        if(TEST_VID_PIPE == CSL_DSS_VID_PIPE_ID_VID1)
        {
            pipeAddr = TEST_VID1_BASE;
            pipeType = CSL_DSS_VID_PIPE_TYPE_VID;
        }
        else
        {
            pipeAddr = TEST_VIDL1_BASE;
            pipeType = CSL_DSS_VID_PIPE_TYPE_VIDL;
        }
#if (1U == BUFFERS_RUNTIME)
        /* Copy image buffer */
        memset(&dss_app_buffer[0], 0x80, width*height*3);

        App_print("Load Image using loadRaw command and then press '1'\n");
        App_print("Command is:\n");
        App_print("loadRaw(0x90000000, 0, \"C:\\\\Image_rgb888_prog_packed_720_480.tigf\", 32, false);\n");
        App_print("Check load address in linker command file\n");

        do
        {
            scanf("%c", &uartInput);
        } while ('1' != uartInput);
#endif

        /* Reset DSS, make sure all timing generators are disabled before
         * issuing the reset */
        CSL_dssVpEnable((CSL_dss_vpRegs *)(CSL_DSS0_VP1_BASE),FALSE);
        CSL_dssVpEnable((CSL_dss_vpRegs *)(CSL_DSS0_VP2_BASE),FALSE);
        CSL_dssModuleReset((CSL_dss_commRegs *)(TEST_COMMON_M_BASE));

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
            App_print("Failed to configure Video Pipe\n");
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
        App_print("Video Pipe configuration done \n");

#if (NUM_VID_PIPES == 2U)
    /* Set Pipe Configuration */
    vidPipeCfg.pipeType = CSL_DSS_VID_PIPE_TYPE_VIDL;
    vidPipeCfg.inFmt.width = 300U;
    vidPipeCfg.inFmt.height = 240U;
    vidPipeCfg.inFmt.pitch[FVID2_RGB_ADDR_IDX] = 300U*NUM_BYTES_PER_PIXEL;
    vidPipeCfg.outWidth = 300U;
    vidPipeCfg.outHeight = 240U;
    vidPipeCfg.scEnable = FALSE;
    retVal = CSL_dssVidPipeSetConfig((CSL_dss_pipeRegs *)(TEST_VIDL1_BASE),
                                     (const CSL_DssVidPipeCfg *)(&vidPipeCfg),
                                      NULL);
    if(CSL_PASS != retVal)
    {
        App_print("Failed to configure second Video Pipe\n");
    }

    /* Set alpha parameters */
    pipeAlphaCfg.globalAlpha = 0xFF;
    pipeAlphaCfg.preMultiplyAlpha = FALSE;
    CSL_dssVidPipeSetAlphaConfig(
                            (CSL_dss_pipeRegs *)(TEST_VIDL1_BASE),
                            (const CSL_DssVidPipeAlphaCfg *)(&pipeAlphaCfg));

    frameAddr = (uint32_t) &gDispArray2[0U];

    /* Set Frame address */
    CSL_dssVidPipeSetBuffAddr((CSL_dss_pipeRegs *)(TEST_VIDL1_BASE),
                              FVID2_FID_TOP,
                              frameAddr,
                              0x0U);
    App_print("Second Video Pipe configuration done \n");
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
        App_print("Overlay configuration for VIDL done \n");
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
        App_print("Overlay configuration done \n");

        /* Set LCD polarity */
        lcdPolarityCfg.actVidPolarity = FVID2_POL_HIGH;
        lcdPolarityCfg.pixelClkPolarity = FVID2_EDGE_POL_FALLING;
        lcdPolarityCfg.hsPolarity = FVID2_POL_HIGH;
        lcdPolarityCfg.vsPolarity = FVID2_POL_HIGH;
        CSL_dssVpSetLcdSignalPolarityConfig(
                      (CSL_dss_vpRegs *)(vpAddr),
                      (const CSL_DssVpLcdSignalPolarityCfg *)(&lcdPolarityCfg));

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
                                (const CSL_DssVpLcdOpTimingCfg *)(&lcdCfg));
        if(CSL_PASS != retVal)
        {
            App_print("Failed to set LCD Timing \n");
        }
        App_print("Video Port configuration done \n");

#if defined (SOC_AM65XX)
        /* Configure OLDI */
        App_configureOldiIO();
        CSL_dssVpOldiReset((CSL_dss_vpRegs *)(vpAddr));

        do
        {
            resetOldi = CSL_dssIsOldiResetDone(
                                    (CSL_dss_commRegs *)(TEST_COMMON_M_BASE));
        } while (TRUE != resetOldi);

        CSL_dssVpSetOldiConfig((CSL_dss_vpRegs *)(vpAddr),
                               (const CSL_DssVpOldiCfg *)(&oldiCfg));
        CSL_dssVpOldiEnable((CSL_dss_vpRegs *)(vpAddr), TRUE);
#endif

    #if defined (__aarch64__)
        Intc_Init(0);
        Intc_IntRegister(CSL_GIC0_INTR_DSS0_BUS_DISPC_INTR_REQ_0,
                         (IntrFuncPtr) App_displayISR,
                         0U);
        Intc_IntPrioritySet(CSL_GIC0_INTR_DSS0_BUS_DISPC_INTR_REQ_0, 1U, 0U);
        Intc_SystemEnable(CSL_GIC0_INTR_DSS0_BUS_DISPC_INTR_REQ_0);
    #else
        Intc_Init();
        Intc_IntSetSrcType(52U, (uint32_t)CSL_VIM_INTR_TYPE_LEVEL);
        Intc_IntPrioritySet(52U, 1U, 0U);
        Intc_IntRegister(52U, (IntrFuncPtr) App_displayISR, 0U);
        Intc_IntEnable(52U);
        Intc_SystemEnable();
    #endif
        CSL_dssEnableVpIntr((CSL_dss_commRegs *)(TEST_COMMON_M_BASE),
                            vpId,
                            CSL_DSS_VP_INTR_VSYNC_MASK,
                            TRUE);
        CSL_dssEnableDispcIntr((CSL_dss_commRegs *)(TEST_COMMON_M_BASE),
                               vpMask,
                               TRUE);

        CSL_dssVidPipeEnable((CSL_dss_pipeRegs *)(pipeAddr), TRUE);
#if (NUM_VID_PIPES == 2U)
        CSL_dssVidPipeEnable((CSL_dss_pipeRegs *)(TEST_VIDL1_BASE), TRUE);
#endif
        CSL_dssVpSetGoBit((CSL_dss_vpRegs *)(vpAddr));
        CSL_dssVpEnable((CSL_dss_vpRegs *)(vpAddr), TRUE);
    }
    while(wait);

    return (0);
}

static void App_print(const char *str)
{
    printf(str);
    return;
}

static void App_displayISR(void *handle)
{
    isrCount++;

    CSL_dssClearVpIntr((CSL_dss_commRegs *)(TEST_COMMON_M_BASE),
                        vpId,
                        CSL_DSS_VP_INTR_VSYNC_MASK);
    CSL_dssClearDispcIntr((CSL_dss_commRegs *)(TEST_COMMON_M_BASE),
                          vpId);

    if (isrCount == DSS_RUN_COUNT)
    {
        CSL_dssVpEnable((CSL_dss_vpRegs *)(vpAddr),FALSE);
        wait = 0U;
    }
}

#if defined (SOC_AM65XX)
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
        App_print("Board Init Failed\n");
    }

    if (CSL_PASS == retVal)
    {
        Board_i2cIoExpInit();
        Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                      PORTNUM_1,
                                      PIN_NUM_0,
                                      PIN_DIRECTION_OUTPUT);

        /* Pull the LCD enable to high */
        Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  PORTNUM_1,
                                  PIN_NUM_0,
                                  GPIO_SIGNAL_LEVEL_HIGH);

        /* Set PWM pin as GPIO for max brightness */
        GPIOSetDirMode_v0(CSL_GPIO1_BASE, PWM_GPIO_PIN, GPIO_DIRECTION_OUTPUT);
        GPIOPinWrite_v0(CSL_GPIO1_BASE, PWM_GPIO_PIN, GPIO_PIN_LOW);
        CSL_REG32_WR(CSL_CTRL_MMR0_CFG0_BASE +
                     CSL_MAIN_CTRL_MMR_CFG0_PADCONFIG190, 0x50007U);

        App_print("LCD configured successfully\n");
    }
    return retVal;
}
#endif
