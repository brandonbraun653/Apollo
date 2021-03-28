/**
 * \file   dss_app.c
 *
 * \brief  Source file containing the DSS IP related configuration functions.
 *         These functions will be called by example application.
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "chipdb.h"
#include "pinmux.h"
#include "dss.h"
#include "error.h"
#include "console_utils.h"

/* Application header files */
#include "dss_app.h"
#include "prcm.h"


/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* TODO: This has to be get from the PRCM and will be removed later. */
#define DSS_FUNCTIONAL_CLK              (152000000U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function performs the configuration of Display sub system and
 *          all of its sub modules.
 *
 * \param   pApp   Pointer to the display sub system application data structure.
 */
static void DssAppConfig(dssAppObj_t *pApp);


/**
 * \brief   This function performs the display sub system configurations like
 *          software reset and auto idle configuration.
 *
 * \param   pApp   Pointer to the display sub system application data structure.
 */
static void DssAppDssInit(uint32_t baseAddr);


/**
 * \brief   This function performs the entire display controller's configuration
 *          including all the pipeline configurations, LCD parameter
 *          configurations and overlay configuration.
 *
 * \param   baseAddr       Memory address of of Display sub system.
 * \param   functionalClk  Display controller's functional clock value in Hz.
 * \param   pInputBuf      Pointer to the starting address of image input buffer
 * \param   pApp           Pointer to the DSS application data structure.
 */
static void DssAppDispcInit(uint32_t baseAddr,
                            uint32_t functionalClk,
                            uint32_t *pInputBuf,
                            dssAppCfg_t *pApp);


/**
 * \brief   This function performs the configuration of display controller
 *          pipelines.
 *
 * \param   baseAddr       Memory address of of Display sub system.
 * \param   pInputBuf      Pointer to the starting address of image input buffer
 * \param   pApp           Pointer to the DSS application data structure.
 */
static void DssAppDispcPipelineCfg(uint32_t baseAddr,
                                   uint32_t *pInputBuf,
                                   dssAppCfg_t *pApp);

/**
 * \brief   This function performs video pipeline configurations.
 *
 * \param   baseAddr       Memory address of of Display sub system.
 * \param   vidPipeline    Id of the video pipeline used.
 * \param   pInputBuf      Pointer to the starting address of image input buffer
 * \param   pVid           Pointer to the video pipeline configuration data
 *                         structure.
 */
static void DssAppDispcVidPipelineConfig(uint32_t baseAddr,
                                         uint32_t vidPipeline,
                                         uint32_t *pInputBuf,
                                         dssAppVidCfg_t *pVid);


/**
 * \brief   This function configures the lcd parameters like display attributes,
 *          timing parameters and polarities of synchronization signals.
 *
 * \param   baseAddr       Memory address of of Display sub system.
 * \param   functionalClk  DSS functional clock value in Hz.
 * \param   pApp           Pointer to DSS application data structure.
 */
static void DssAppDispcLcdConfig(uint32_t baseAddr,
                                 uint32_t functionalClk,
                                 dssAppCfg_t *pApp);


/**
 * \brief   This function configures the display controller's interrupts.
 *
 * \param   baseAddr  Memory address of Display sub system.
 */
static void DssAppDispcIntrConfig(uint32_t baseAddr);


/**
 * \brief   This functions enables the lcd display. Once enabled the image data
 *          will be driven to the LCD and image will be displayed on the LCD.
 *
 * \param   pApp           Pointer to DSS application data structure.
 */
static void DssAppLcdDisplayStart(dssAppObj_t *pApp);


/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Default values of display sub system IP configuration data
           structure. */
dssAppObj_t   DSSAPPOBJ_DEFAULT =
{
    0U,   /* dssInstAddr */
    0U,   /* dssSysIntrNum */
    0U,   /* dssfunctionalClk */
    0U,   /* lcdPanelPartNum */
    NULL, /* pInputBuf */
    {
        {
            TRUE, /* enableVideo*/
            {
                DSS_DISPC_VID_DMA_BURST_SIZE_16,      /* burstSize */
                0x3C0U,                               /* fifoLoThr */
                0x3FFU,                               /* fifoHiThr */
                1U,                                   /* pixelInc*/
                1U,                                   /* rowInc*/
                DSS_DISPC_VID_PRELOAD_SRC_REG_VAL     /* preloadSelect */
            }, /* dssDispcDmaCfg_t */
            {
                DSS_DISPC_VID_FMT_TYPE_RGB24_UNPACKED, /* format */
                DSS_DISPC_VID_ENDIAN_LITTLE,           /* endian */
                FALSE,                                 /* enableCsc */
                NULL,                                  /* pCscCoeff */
                TRUE,                                  /* enableExtender */
            },  /* dssVidFmtCfg_t */
            {
                800U,      /* inputWidth */
                480U,      /* inputHeight */
                800U,      /* outputWidth */
                480U,      /* outputHeight */
                FALSE,     /* enableResizing */
                0U,        /* xPos */
                0U,        /* yPos */
            },  /* dssDispcVidWindowCfg_t */
        },  /* dssAppVidCfg_t */
        {
            {
              DSS_DISPC_LCD_MATRIX_TYPE_ACTIVE, /* displayType  */
              DSS_DISPC_LCD_DISP_TYPE_COLOR,    /* monoColor */
              DSS_DISPC_LCD_DATA_LINES_24,      /* lcdDataLines */
              DSS_DISPC_LCD_MONO_TYPE_4_BIT,    /* mono8Bit */
            }, /* dssDispcLcdAttrCfg_t */
            {
                800U,      /* ppl */
                240U,      /* hfp */
                15U,       /* hbp */
                30U,       /* hsw */
                480U,      /* lpp */
                32U,       /* vfp */
                10U,       /* vbp */
                13U,       /* vsw */
                38000000U, /* pixelClk */
            }, /* dssDispcLcdTimingCfg_t */
            {
                DSS_DISPC_LCD_H_SYNC_POL_LOW, /* hSyncPolarity */
                DSS_DISPC_LCD_V_SYNC_POL_LOW, /* vSyncPolarity */
                DSS_DISPC_LCD_OUTPUT_ENABLE_POL_HIGH, /* outputEnablePolarity */
                DSS_DISPC_LCD_PCLK_POL_RISING_EDGE, /* pixelClkPolarity */
                DSS_DISPC_LCD_ACTIVE_SYNC_EDGE_FALLING, /* syncEdge */
                DSS_DISPC_LCD_SYNC_PCLK_CTRL_OFF, /* sycnEdgeCtrl */
            }, /* dssDispcLcdPolarityCfg_t */
        },
        0x00FFFF00U /* solidBackgndColor */
    }
};


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t DSSAppInit(dssAppObj_t *pDss)
{
    int32_t status = E_FAIL;

    /* Clock configuration */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_DSS, 0U, FALSE);
    if(S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n Clock configuration is failed \n");
    }
    else
    {

        /*TODO: Get the display controller input functional clock */
        pDss->dssfunctionalClk = DSS_FUNCTIONAL_CLK;

        /* Pin Mux configuration */
        status = PINMUXModuleConfig(CHIPDB_MOD_ID_DSS, 0, NULL);
        if(S_PASS != status)
        {
            CONSOLEUtilsPrintf("\n Pin mux configuration is failed \n");
        }
        else
        {
            /* Display subsystem configuration */
            DssAppConfig(pDss);

            /* Enable pipeline and LCD output*/
            DssAppLcdDisplayStart(pDss);

            status = S_PASS;
        }
    }

    return status;
}

/* ========================================================================== */
/*                        Internal Function Definitions                       */
/* ========================================================================== */

static void DssAppConfig(dssAppObj_t *pApp)
{
    /* Display Sub System reset and initialization */
    DssAppDssInit(pApp->dssInstAddr);

    /* Display controller configuration */
    DssAppDispcInit(pApp->dssInstAddr, pApp->dssfunctionalClk, pApp->pInputBuf,
        &pApp->dssCfg);
}


/* Display sub system reset and idle mode configuration */
static void DssAppDssInit(uint32_t baseAddr)
{
    /* Soft Reset of Display Sub System */
    DSSSoftReset(baseAddr);

    /* DSS auto idle enable */
    DSSAutoIdleEnable(baseAddr, TRUE);
}


/* Display controller configuration */
static void DssAppDispcInit(uint32_t baseAddr,
                            uint32_t functionalClk,
                            uint32_t *pInputBuf,
                            dssAppCfg_t *pApp)
{
    /* Soft Reset of Display Controller */
    DSSDispcSoftReset(baseAddr);

    /* DISPC auto idle enable */
    DSSDispcAutoIdleEnable(baseAddr, TRUE);

    /* Configure the display controller's pipelines. */
    DssAppDispcPipelineCfg(baseAddr, pInputBuf, pApp);

    /* Configure Solid back ground color. */
    DSSDispcOverlaySetBackgndColor(baseAddr, pApp->solidBackgndColor);

    /* Configure LCD panel Attributes */
    DssAppDispcLcdConfig(baseAddr, functionalClk, pApp);

    /* Bypass RFBI mode */
    DSSDispcSetRfbiBypassMode(baseAddr);

    /* Enable required display controller interrupts */
    DssAppDispcIntrConfig(baseAddr);
}


static void DssAppDispcPipelineCfg(uint32_t baseAddr,
                                   uint32_t *pInputBuf,
                                   dssAppCfg_t *pApp)
{
    /* Disable Graphics pipeline */
    DSSDispcGfxEnable(baseAddr, FALSE);

    /* Set the palette load mode as only DATA load */
    DSSDispcGfxPaletteGammaCfg(baseAddr,
                               DSS_DISPC_GFX_LUT_TYPE_PALETTE,
                               DSS_DISPC_GFX_LUT_LOAD_MODE_DATA_PER_FRAME,
                               (uint32_t)NULL);

    /* Disable Video2 pipeline */
    DSSDispcVidEnable(baseAddr, DSS_DISPC_VID_PIPELINE_ID_2, FALSE);

    /* Configure Video1 pipeline */
    DssAppDispcVidPipelineConfig(baseAddr, DSS_DISPC_VID_PIPELINE_ID_1,
        pInputBuf, &pApp->vid);
}


static void DssAppDispcVidPipelineConfig(uint32_t baseAddr,
                                         uint32_t vidPipeline,
                                         uint32_t *pInputBuf,
                                         dssAppVidCfg_t *pVid)
{
    uint32_t bufAddr;
    uint32_t priority;
    dssDispcDmaCfg_t *pDmaCfg = &pVid->vidDma;
    dssVidFmtCfg_t *pFmtCfg = &pVid->vidFmt;
    dssDispcVidWindowCfg_t *pWinCfg = &pVid->vidWindow;

    bufAddr  = (uint32_t)pInputBuf;
    priority = DSS_DISPC_VID_PRIORITY_HIGH;

    /* Video pipeline DMA Configuration */
    DSSDispcVidDmaConfig(baseAddr, vidPipeline, pDmaCfg);

    /* Configure video pipeline priority */
    DSSDispcSetVidPriority(baseAddr, vidPipeline, priority);

    /* Disable Self Refresh */
    DSSDispcVidDmaSelfRefreshEnable(baseAddr, vidPipeline, FALSE);

    /* Configure base address of graphics buffer BA0 */
    DSSDispcVidSetBufAddr(baseAddr,
                          vidPipeline,
                          bufAddr,
                          DSS_DISPC_FRM_BUF_ID_0);

    /* Video window position configuration */
    if((pWinCfg->xPos >= DSS_DISPC_VID_WINDOW_XPOS_MIN) &&
       (pWinCfg->xPos <= DSS_DISPC_VID_WINDOW_XPOS_MAX) &&
       (pWinCfg->yPos >= DSS_DISPC_VID_WINDOW_YPOS_MIN) &&
       (pWinCfg->yPos <= DSS_DISPC_VID_WINDOW_YPOS_MAX))
    {
        DSSDispcVidWindowPositionCfg(baseAddr, vidPipeline, pWinCfg->xPos,
            pWinCfg->yPos);
    }
    else
    {
        CONSOLEUtilsPrintf("Invalid Input parameters: Window position \n");
    }

    /* video format configuration */
    DSSDispcVidFormatConfig(baseAddr, vidPipeline, pFmtCfg);

    if((pWinCfg->inputWidth >= DSS_DISPC_VID_SIZE_X_MIN) &&
       (pWinCfg->inputWidth <= DSS_DISPC_VID_SIZE_X_MAX) &&
       (pWinCfg->inputHeight >= DSS_DISPC_VID_SIZE_Y_MIN) &&
       (pWinCfg->inputHeight <= DSS_DISPC_VID_SIZE_Y_MAX))
    {

        /* Configure input and output sizes of video window */
        DSSDispcVidSizeConfig(baseAddr, vidPipeline, pWinCfg->inputWidth,
            pWinCfg->inputHeight, pWinCfg->outputWidth, pWinCfg->outputHeight);
    }
    else
    {
        CONSOLEUtilsPrintf("Invalid Input parameters: Window size \n");
    }

    /* Disable video resize processing. */
    DSSDispcVidResizeDisable(baseAddr, vidPipeline);
}


static void DssAppDispcLcdConfig(uint32_t baseAddr,
                                 uint32_t functionalClk,
                                 dssAppCfg_t *pApp)
{
    dssAppLcdCfg_t  *pLcd = &pApp->lcd;
    uint32_t pixelClk;
    dssDispcLcdGatedCtrl_t clk;
    dssDispcLcdAcbCfg_t acb;

    /* LCD pixel clock configuration */
    pixelClk = DSSDispcLcdClkConfig(baseAddr, functionalClk,
        pLcd->timingCfg.pixelClk);

    if(pLcd->timingCfg.pixelClk != pixelClk)
    {
        CONSOLEUtilsPrintf(
            "Programmed pixel clk is not matching the required clk \n");
    }

    /* LCD type, monocolor , data lines configuration */
    DSSDispcLcdDisplayAttrConfig(baseAddr, &pLcd->attrCfg);

    /* LCD panel configuration: ppl,lpp,hfp,hbp,hsw,vfp,vbp,vsw */
    DSSDispcLcdTimingConfig(baseAddr, &pLcd->timingCfg);

    /* LCD timing signal polarity configuration */
    DSSDispcLcdPolarityConfig(baseAddr, &pLcd->polarityCfg);

    /* LCD Enable signal Configuration */
    DSSDispcLcdEnableSigConfig(baseAddr,
                               DSS_DISPC_LCD_EN_SIG_CTRL_ENABLE,
                               DSS_DISPC_LCD_EN_SIG_POL_HIGH);

    clk.hSyncGated = DISPC_CFG_HSYNC_GATED_DISABLED;
    clk.vSyncGated = DISPC_CFG_VSYNC_GATED_DISABLED;
    clk.acbGated   = DISPC_CFG_ACBIAS_GATED_DISABLED;
    clk.pixelClkGated = DISPC_CFG_PIXEL_CLK_GATED_DISABLED;
    DSSDispcLcdSigGatedCtrl(baseAddr, &clk);

    acb.acbFreq = 0U;
    acb.acbi    = 0U;
    DSSDispcLcdAcbiasConfig(baseAddr, &acb);
}


/* Enable pipelines and LCD output */
static void DssAppLcdDisplayStart(dssAppObj_t *pDss)
{
    uint32_t baseAddr = pDss->dssInstAddr;
    dssAppVidCfg_t *vid = &pDss->dssCfg.vid;

    /* Enable video1 pipeline */
    DSSDispcVidEnable(baseAddr, DSS_DISPC_VID_PIPELINE_ID_1, vid->enableVideo);

    /* Set GoLCD bit: enable shadow register configuration to take effect */
    DSSDispcShadowCfgEnable(baseAddr);

    /* Enable LCD output in display controller */
    DSSDispcLcdOutputEnable(baseAddr, TRUE);
}


/* Display controller Interrupt configuration */
static void DssAppDispcIntrConfig(uint32_t baseAddr)
{
    /* Clear status of all the interrupts */
    DSSDispcIntrClear(baseAddr, DSS_DISPC_INTR_MASK_ALL);

    /* Enable VSYNC, SYNCLOST, VID1 Under flow interrupts */
    DSSDispcIntrEnable(baseAddr, (DSS_DISPC_INTR_MASK_VSYNC |
        DSS_DISPC_INTR_MASK_VID1_UNDER_FLOW |
        DSS_DISPC_INTR_MASK_SYNC_LOST_LCD));
}
