/**
 *  \file     display_utils_dss.c
 *
 *  \brief    This file contains the display utility APIs implementation. This
 *            file contains the implementation specific to DSS IP.
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
#include "error.h"
#include "board.h"
#include "soc.h"
#include "prcm.h"
#include "device.h"
#include "chipdb.h"
#include "console_utils.h"
#include "interrupt.h"
#include "lcd_device.h"
#include "misc.h"

#include "display_utils_ip.h"
#include "display_utils_dss.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief LCD device instance number. */
#define DSS_LCD_INST_NUM           (0U)

/** \brief Function clock of the display sub system. */
/*TODO: This value should be get through board API. */
#define DSS_FUNCTIONAL_CLK         (48U * FREQ_MHZ)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API gets the board info like device id, and calls device
 *          selection and device power on functions.
 *
 * \param   pObj        Pointer to the dss object.
 *
 * \retval  S_PASS      Board info successfully retrieved. LCD is connected to
 *                      DSS on this board.
 * \retval  E_FAIL      This board does not support this application.
 *                      - LCD device may not be available on this board or even
 *                        if it is available, it is not connected to DSS on this
 *                        board.
 */
static int32_t DisplayUtilsGetBoardInfo(displayUtilsDssObj_t *pObj);


/**
 * \brief   This API gets the soc info - base address of DSS instance and
 *          interrupt number of display sub system.
 *
 * \param   pObj        Pointer to the dss object.
 *
 * \retval  S_PASS      Soc info is successfully retrieved.
 * \retval  E_FAIL      Soc info retrieval is failed.
 */
static int32_t DisplayUtilsGetSocInfo(displayUtilsDssObj_t *pObj);


/**
 * \brief   This API updates the device data i.e, LCD timing and polarity
 *          parameter values in the IP configuration data structure.
 *
 * \param   pDss        Pointer to the dss object.
 * \param   pLcdData    Pointer to the structure holding the LCD panel data.
 */
static void DisplayUtilsUpdateIpConfigParams(displayUtilsDssObj_t *pDss,
                                             lcdDeviceData_t *pLcdData);


/**
 * \brief   This API configures the system interrupt controller and enables the
 *          display sub system's system interrupt.
 *
 * \param   intrNum     DSS System interrupt number
 *
 * \retval  S_PASS      Interrupt controller configuration is successful.
 * \retval  E_FAIL      Interrupt controller configuration is failed.
 */
static int32_t DisplayUtilsInterruptConfig(uint32_t intrNum);


/**
 * \brief   This API performs the clock and pin mux configurations of DSS IP.
 *
 * \param   pDss        Pointer to the dss object.
 *
 * \retval  S_PASS Clock and pin mux configuration is successful.
 * \retval  E_FAIL Clock and pin mux configuration is failed.
 */
static int32_t DisplayUtilsDssIpInit(displayUtilsDssObj_t *pDss);


/**
 * \brief   This API performs the IP configuration.
 *
 * \param   pApp    Pointer to the dss object.
 *
 * \retval  S_PASS  IP configuration is successful.
 * \retval  E_FAIL  IP configuration is failed.
 */
static int32_t DisplayUtilsDssConfig(displayUtilsDssObj_t *pApp);


/**
 * \brief   This function performs the display sub system configurations like
 *          software reset and auto idle configuration.
 *
 * \param   baseAddr   Memory address of of Display sub system.
 */
static void DisplayUtilsDssInit(uint32_t baseAddr);


/**
 * \brief   This function performs the entire display controller's configuration
 *          including all the pipeline configurations, LCD parameter
 *          configurations and overlay configuration.
 *
 * \param   baseAddr       Memory address of of Display sub system.
 * \param   functionalClk  Display controller's functional clock value in Hz.
 * \param   inputBufAddr   Starting address of image input buffer
 * \param   pApp           Pointer to the DSS configuration data structure.
 *
 * \retval  S_PASS DISPC configuration is successful.
 * \retval  E_FAIL DISPC configuration is failed.
 */
static int32_t DisplayUtilsDispcConfig(uint32_t baseAddr,
                                       uint32_t functionalClk,
                                       uint32_t inputBufAddr,
                                       displayUtilsDssCfg_t *pApp);


/**
 * \brief   This function performs the configuration of display controller
 *          pipelines.
 *
 * \param   baseAddr       Memory address of of Display sub system.
 * \param   inputBufAddr   Starting address of image input buffer
 * \param   pApp           Pointer to the DSS application data structure.
 *
 * \retval  S_PASS     Pipeline configuration is successful.
 * \retval  E_FAIL     Pipeline configuration is failed.
 */
static int32_t DisplayUtilsDispcPipelineCfg(uint32_t baseAddr,
                                            uint32_t inputBufAddr,
                                            displayUtilsDssCfg_t *pApp);


/**
 * \brief   This function performs video pipeline configurations.
 *
 * \param   baseAddr       Memory address of of Display sub system.
 * \param   vidPipeline    Id of the video pipeline used.
 * \param   inputBufAddr   Starting address of image input buffer
 * \param   pVid           Pointer to the video pipeline configuration data
 *                         structure.
 *
 * \retval  S_PASS  Video pipeline configuration is successful.
 * \retval  E_FAIL  Video pipeline configuration is failed.
 */
static int32_t DisplayUtilsDispcVidPipelineConfig(uint32_t baseAddr,
                                                  uint32_t vidPipeline,
                                                  uint32_t inputBufAddr,
                                            displayUtilsDssDispcVidCfg_t *pVid);


/**
 * \brief   This function configures the lcd parameters like display attributes,
 *          timing parameters and polarities of synchronization signals.
 *
 * \param   baseAddr       Memory address of of Display sub system.
 * \param   functionalClk  DSS functional clock value in Hz.
 * \param   pApp           Pointer to DSS application data structure.
 */
static void DisplayUtilsDispcLcdConfig(uint32_t baseAddr,
                                       uint32_t functionalClk,
                                       displayUtilsDssCfg_t *pApp);

/**
 * \brief   This functions enables the video pipeline. Once enabled the image
 *          data will be driven to the LCD.
 *
 * \param   pDss           Pointer to DSS application data structure.
 */
static void DisplayUtilsLcdDisplayStart(displayUtilsDssObj_t *pDss);

/**
 * \brief   This function configures the display controller's interrupts.
 *
 * \param   baseAddr  Memory address of Display sub system.
 */
static void DisplayUtilsDispcIntrConfig(uint32_t baseAddr);


/**
 * \brief   Display sub system's interrupt service routine.
 *
 * \param   intrId       DSS System interrupt number
 * \param   cpuId        CPU Id.
 * \param   pUserParam   Pointer to the structure containing the IP info.
 */
static void DisplayUtilsIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Array containing the color space conversion coefficients. */
dssDispcCscCoeff_t cscCoeff = {298, 409, 0, 298, -208, -100, 298, 0, 517, 0};

/** \brief Default values of display sub system IP configuration data
           structure. */
displayUtilsDssObj_t   DSSAPPOBJ_DEFAULT =
{
    0U,   /* dssInstAddr */
    0U,   /* dssSysIntrNum */
    0U,   /* dssfunctionalClk */
    0U,   /* lcdPanelPartNum */
    0U, /* inputBufAddr */
    NULL, /* pFnIsrCb */
    0U, /* currBufAddr */
    0U, /* nextBufAddr */
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
                TRUE,                                  /* enableCsc */
                &cscCoeff,                             /* pCscCoeff */
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
        {
            0x00FFFF00U, /* solidBackgndColor */
        },
    }
};


/** \brief Global data structure holding the DSS IP configuration parameters. */
displayUtilsDssObj_t gDss;

/** \brief Counter indicating the number of under flow interrupts. */
volatile uint32_t gDisplayUtilsUnderflowErrCnt = 0U;

/** \brief Counter indicating the number of sync lost interrupts. */
volatile uint32_t gDisplayUtilsSyncLostErrCnt = 0U;



/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t DISPLAYUtilsModuleInit(void)
{
    uint32_t status = E_FAIL;
    lcdDeviceData_t *lcdDeviceData;

    /* Initialize the global IP configuration object with default values. */
    gDss = DSSAPPOBJ_DEFAULT;

    /* Get Board information */
    status = DisplayUtilsGetBoardInfo(&gDss);
    if (S_PASS == status)
    {
        /* Get SOC information */
        status = DisplayUtilsGetSocInfo(&gDss);
        if (S_PASS == status)
        {
            /* Perform initialization of Interrupt controller*/
            INTCInit(FALSE);
            /* DSS Interrupt configuration */
            status = DisplayUtilsInterruptConfig(gDss.dssSysIntrNum);
            if (S_PASS == status)
            {
                /* Get the LCD panel data */
                lcdDeviceData = LCDGetDeviceData(gDss.dssLcdDeviceId);

                /* Update IP config parameters with device,use case values */
                DisplayUtilsUpdateIpConfigParams(&gDss, lcdDeviceData);

                /* DSS clock/pin mux and IP configuration */
                status = DisplayUtilsDssIpInit(&gDss);
                if (S_PASS == status)
                {
                    CONSOLEUtilsPrintf("\n DSS Module init is successful \n");
                }
                else
                {
                    CONSOLEUtilsPrintf("\n DSS IP configuration is failed \n");
                }
            }
            else
            {
                CONSOLEUtilsPrintf("\n Interrupt controller config failed \n");
            }
        }
        else
        {
            CONSOLEUtilsPrintf("\n IP is not present on this board \n");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("\n Board information retrieval failed \n");
    }

    return status;
}


int32_t DISPLAYUtilsIpConfig(uint32_t bufAddr,
                             uint32_t bufSize,
                             uint32_t inputWidth,
                             uint32_t inputHeight,
                             uint32_t inputPixelFormat,
                             DISPLAYUtilsIsrCallbackFxn pFnCb)
{
    int32_t status = E_FAIL;
    uint32_t pixelFmt = 0U;
    displayUtilsDssObj_t *pDss = &gDss;
    uint32_t lcdWidth  = pDss->dssCfg.lcd.timingCfg.ppl;
    uint32_t lcdHeight = pDss->dssCfg.lcd.timingCfg.lpp;

    if ((inputPixelFormat >= DISPLAY_UTILS_PIXEL_FMT_MIN) &&
        (inputPixelFormat <= DISPLAY_UTILS_PIXEL_FMT_MAX))
    {
        /* Map the input pixel format to ip configuration value. */
        switch(inputPixelFormat)
        {
            case DISPLAY_UTILS_PIXEL_FMT_RGB12:
                pixelFmt = DSS_DISPC_VID_FMT_TYPE_RGB12;
                break;

            case DISPLAY_UTILS_PIXEL_FMT_RGB16:
                pixelFmt = DSS_DISPC_VID_FMT_TYPE_RGB16;
                break;

            case DISPLAY_UTILS_PIXEL_FMT_RGB24_UNPACKED:
                pixelFmt = DSS_DISPC_VID_FMT_TYPE_RGB24_UNPACKED;
                break;

            case DISPLAY_UTILS_PIXEL_FMT_YUV2:
                pixelFmt = DSS_DISPC_VID_FMT_TYPE_YUV2;
                break;

            default:
            break;
        }


        CONSOLEUtilsPrintf("\n DISPLAY UTILS Pixel Format = %d \n", pixelFmt);

        /* Update the video window and format configuration parameters. */
        pDss->dssCfg.vid.vidFmt.format = pixelFmt;
        pDss->dssCfg.vid.vidWindow.inputWidth  = inputWidth;
        pDss->dssCfg.vid.vidWindow.inputHeight = inputHeight;

        /* Output size is configured to be same as input size. */
        pDss->dssCfg.vid.vidWindow.outputWidth = inputWidth;
        pDss->dssCfg.vid.vidWindow.outputHeight = inputHeight;

        /* Update the buffer pointer and buffer size. */
        pDss->inputBufAddr = bufAddr;
        pDss->currBufAddr = bufAddr;

        /* Update ISR call back function */
        pDss->pFnIsrCb = pFnCb;

        if((inputWidth <= lcdWidth) && (inputHeight <= lcdHeight))
        {
            /* Display subsystem configuration */
            status = DisplayUtilsDssConfig(pDss);
            if(S_PASS == status)
            {
                /* Enable pipeline and LCD output*/
                DisplayUtilsLcdDisplayStart(pDss);
            }
            else
            {
                CONSOLEUtilsPrintf("\n DSS IP configuration is failed. \n");
                status = E_FAIL;
            }
        }
        else
        {
            CONSOLEUtilsPrintf
                ("\n Input Image Size is not matching with LCD panel size. \n");

            status = E_FAIL;
        }
    }
    else
    {
        CONSOLEUtilsPrintf("\n Input pixel format is not supported. \n");
    }

    return status;
}


void DISPLAYUtilsIpDisplayEnable(void)
{
    DSSDispcLcdOutputEnable(gDss.dssInstAddr, TRUE);
}

void DISPLAYUtilsIpDisplayDisable(void)
{
    DSSDispcLcdOutputEnable(gDss.dssInstAddr, FALSE);
}

void DISPLAYUtilsIpGetDisplayResolution(uint32_t *pWidth, uint32_t *pHeight)
{
    dssDispcLcdTimingCfg_t *pTiming = &gDss.dssCfg.lcd.timingCfg;

    *pWidth  = pTiming->ppl;
    *pHeight = pTiming->lpp;
}


/* ========================================================================== */
/*                        Internal Function Definitions                       */
/* ========================================================================== */

static int32_t DisplayUtilsGetBoardInfo(displayUtilsDssObj_t *pObj)
{
    uint32_t *lcdDeviceIdlist;
    int32_t status = E_FAIL;
    chipdbModuleID_t modId;
    uint32_t devIndex = 0U;

    /* Check which LCD device is present on this board */
    lcdDeviceIdlist = LCDGetDeviceIdList();

    do {
        if (TRUE == BOARDIsDevicePresent(lcdDeviceIdlist[devIndex]))
        {
            /* LCD device found */
            pObj->dssLcdDeviceId = lcdDeviceIdlist[devIndex];
            break;
        }
        devIndex++;
    } while (DEVICE_ID_INVALID != lcdDeviceIdlist[devIndex]);

    if (DEVICE_ID_INVALID == lcdDeviceIdlist[devIndex])
    {
        CONSOLEUtilsPrintf("No LCD device found \n");
    }
    else
    {
        CONSOLEUtilsPrintf("\nLCD Device id = %d \n", pObj->dssLcdDeviceId);

        /* Get the control mod id for the current device */
        modId = BOARDGetDeviceCtrlModId(pObj->dssLcdDeviceId, DSS_LCD_INST_NUM);

        if (CHIPDB_MOD_ID_INVALID == modId)
        {
            CONSOLEUtilsPrintf("Device is not available on this board!\n");
        }
        else if (CHIPDB_MOD_ID_DSS == modId)
        {
            CONSOLEUtilsPrintf("Device is connected to DSS on this board!\n");

            /* Function to power on the device */
            BOARDPowerOnDevice(pObj->dssLcdDeviceId, DSS_LCD_INST_NUM, TRUE);

            /* Function to select LCD/HDMI device */
            BOARDSelectDevice(pObj->dssLcdDeviceId, DSS_LCD_INST_NUM);

            status = S_PASS;
        }
        else
        {
            CONSOLEUtilsPrintf("Device is not connected to DSS!\n");
        }
    }

    return (status);
}


static int32_t DisplayUtilsGetSocInfo(displayUtilsDssObj_t *pObj)
{
    int32_t status = E_FAIL;

    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_DSS, 0U))
    {
        pObj->dssInstAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_DSS, 0U);

        if(SOC_FAMILY_ID_AM43XX == SOCGetSocFamilyId())
        {
            /*TODO: This interrupt number has to be provided by soc info */
            pObj->dssSysIntrNum = 159U;  /* 127 + 32 */
            status = S_PASS;
        }
        else
        {
            /* SOC is not AM43xx */
            status = E_FAIL;
        }
    }
    else
    {
        CONSOLEUtilsPrintf("DSS IP is not present on this SOC!\n");
    }

    return status;
}


static int32_t DisplayUtilsInterruptConfig(uint32_t intrNum)
{
    int32_t status = S_PASS;
    intcIntrParams_t dssIntrParams;

    dssIntrParams.triggerType    = INTC_TRIG_HIGH_LEVEL;
    dssIntrParams.priority       = 0x00;
    dssIntrParams.pFnIntrHandler = &DisplayUtilsIsr;
    dssIntrParams.isIntrSecure   = FALSE;
    dssIntrParams.pUserParam     = &gDss;

    /* Configure the interrupt controller */
    status = INTCConfigIntr(intrNum, &dssIntrParams, FALSE);
    if(S_PASS != status)
    {
        CONSOLEUtilsPrintf(" Interrupt controller configuration failed \n ");
    }

    return status;
}


static void DisplayUtilsUpdateIpConfigParams(displayUtilsDssObj_t *pDss,
                                             lcdDeviceData_t *pLcdData)
{
    dssDispcLcdTimingCfg_t *pTiming = &pDss->dssCfg.lcd.timingCfg;
    dssDispcLcdPolarityCfg_t *pPol  = &pDss->dssCfg.lcd.polarityCfg;

    /* Update LCD timing parameters. */
    pTiming->pixelClk = pLcdData->pixelClk;
    pTiming->ppl      = pLcdData->pixelsPerLine;
    pTiming->hfp      = pLcdData->horzFrontPorch;
    pTiming->hbp      = pLcdData->horzBackPorch;
    pTiming->hsw      = pLcdData->horzSyncWidth;
    pTiming->lpp      = pLcdData->linesPerPanel;
    pTiming->vfp      = pLcdData->vertFrontPorch;
    pTiming->vbp      = pLcdData->vertBackPorch;
    pTiming->vsw      = pLcdData->vertSyncWidth;


    /* Update sync signal polarities */
    pPol->hSyncPolarity = (LCD_SIG_POLARITY_ACTIVE_LOW ==
        pLcdData->hSyncPolarity) ? DSS_DISPC_LCD_H_SYNC_POL_LOW :
        DSS_DISPC_LCD_H_SYNC_POL_HIGH;
    pPol->vSyncPolarity = (LCD_SIG_POLARITY_ACTIVE_LOW ==
        pLcdData->vSyncPolarity) ? DSS_DISPC_LCD_V_SYNC_POL_LOW :
        DSS_DISPC_LCD_V_SYNC_POL_HIGH;
    pPol->outputEnablePolarity = (LCD_SIG_POLARITY_ACTIVE_LOW ==
        pLcdData->outputEnablePolarity) ? DSS_DISPC_LCD_OUTPUT_ENABLE_POL_LOW :
        DSS_DISPC_LCD_OUTPUT_ENABLE_POL_HIGH;
    pPol->pixelClkPolarity = (LCD_ACTIVE_EDGE_RISING ==
        pLcdData->pixelClkPolarity) ? DSS_DISPC_LCD_PCLK_POL_RISING_EDGE :
        DSS_DISPC_LCD_PCLK_POL_FALLING_EDGE;
    pPol->syncEdge = (LCD_ACTIVE_EDGE_RISING == pLcdData->activeSyncEdge) ?
        DSS_DISPC_LCD_ACTIVE_SYNC_EDGE_RISING :
        DSS_DISPC_LCD_ACTIVE_SYNC_EDGE_FALLING;
    pPol->sycnEdgeCtrl = (LCD_SYNC_EDGE_CTRL_SAME_EDGE ==
    pLcdData->syncEdgeControl) ? DSS_DISPC_LCD_SYNC_PCLK_CTRL_OFF :
    DSS_DISPC_LCD_SYNC_PCLK_CTRL_ON;
}


static int32_t DisplayUtilsDssIpInit(displayUtilsDssObj_t *pDss)
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
            status = S_PASS;
        }
    }

    return status;
}


static int32_t DisplayUtilsDssConfig(displayUtilsDssObj_t *pApp)
{
    int32_t status = E_FAIL;

    /* Display Sub System reset and initialization */
    DisplayUtilsDssInit(pApp->dssInstAddr);

    /* Display controller configuration */
    status = DisplayUtilsDispcConfig(pApp->dssInstAddr, pApp->dssfunctionalClk,
        pApp->inputBufAddr, &pApp->dssCfg);

    return status;
}


/* Display sub system reset and idle mode configuration */
static void DisplayUtilsDssInit(uint32_t baseAddr)
{
    /* Soft Reset of Display Sub System */
    DSSSoftReset(baseAddr);

    /* DSS auto idle enable */
    DSSAutoIdleEnable(baseAddr, TRUE);
}


/* Display controller configuration */
static int32_t DisplayUtilsDispcConfig(uint32_t baseAddr,
                                       uint32_t functionalClk,
                                       uint32_t inputBufAddr,
                                       displayUtilsDssCfg_t *pApp)
{
    int32_t status = E_FAIL;

    /* Soft Reset of Display Controller */
    DSSDispcSoftReset(baseAddr);

    /* DISPC auto idle enable */
    DSSDispcAutoIdleEnable(baseAddr, TRUE);

    /* Configure the display controller's pipelines. */
    status = DisplayUtilsDispcPipelineCfg(baseAddr, inputBufAddr, pApp);
    if(S_PASS == status)
    {
        /* Configure Solid back ground color. */
        DSSDispcOverlaySetBackgndColor(baseAddr, pApp->ovly.solidBackGndColor);

        /* Configure LCD panel Attributes */
        DisplayUtilsDispcLcdConfig(baseAddr, functionalClk, pApp);

        /* Bypass RFBI mode */
        DSSDispcSetRfbiBypassMode(baseAddr);

        /* Enable required display controller interrupts */
        DisplayUtilsDispcIntrConfig(baseAddr);
    }
    else
    {
        CONSOLEUtilsPrintf("\n Video pipeline configuration failed. \n");
    }

    return status;
}


static int32_t DisplayUtilsDispcPipelineCfg(uint32_t baseAddr,
                                            uint32_t inputBufAddr,
                                            displayUtilsDssCfg_t *pApp)
{
    int32_t status = E_FAIL;

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
    status = DisplayUtilsDispcVidPipelineConfig(baseAddr,
        DSS_DISPC_VID_PIPELINE_ID_1, inputBufAddr, &pApp->vid);

    return status;
}


static int32_t DisplayUtilsDispcVidPipelineConfig(uint32_t baseAddr,
                                                  uint32_t vidPipeline,
                                                  uint32_t inputBufAddr,
                                             displayUtilsDssDispcVidCfg_t *pVid)
{
    int32_t status = S_PASS;
    uint32_t bufAddr;
    uint32_t priority;
    dssDispcDmaCfg_t *pDmaCfg = &pVid->vidDma;
    dssVidFmtCfg_t *pFmtCfg = &pVid->vidFmt;
    dssDispcVidWindowCfg_t *pWinCfg = &pVid->vidWindow;

    bufAddr  = inputBufAddr;
    priority = DSS_DISPC_VID_PRIORITY_HIGH;

    /* Video pipeline DMA Configuration */
    DSSDispcVidDmaConfig(baseAddr, vidPipeline, pDmaCfg);

    /* Configure video pipeline priority */
    DSSDispcSetVidPriority(baseAddr, vidPipeline, priority);

    /* Disable Self Refresh */
    DSSDispcVidDmaSelfRefreshEnable(baseAddr, vidPipeline, FALSE);

    /* Configure base address of graphics buffer BA0 */
    DSSDispcVidSetBufAddr(baseAddr, vidPipeline, bufAddr,
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
        status = E_FAIL;
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
        status = E_FAIL;
    }

    /* Disable video resize processing. */
    DSSDispcVidResizeDisable(baseAddr, vidPipeline);

    return status;
}


static void DisplayUtilsDispcLcdConfig(uint32_t baseAddr,
                                 uint32_t functionalClk,
                                 displayUtilsDssCfg_t *pApp)
{
    displayUtilsDssDispcLcdCfg_t  *pLcd = &pApp->lcd;
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
static void DisplayUtilsLcdDisplayStart(displayUtilsDssObj_t *pDss)
{
    uint32_t baseAddr = pDss->dssInstAddr;
    displayUtilsDssDispcVidCfg_t *vid = &pDss->dssCfg.vid;

    /* Enable video1 pipeline */
    DSSDispcVidEnable(baseAddr, DSS_DISPC_VID_PIPELINE_ID_1, vid->enableVideo);

    /* Set GoLCD bit: enable shadow register configuration to take effect */
    DSSDispcShadowCfgEnable(baseAddr);
}


/* Display controller Interrupt configuration */
static void DisplayUtilsDispcIntrConfig(uint32_t baseAddr)
{
    /* Clear status of all the interrupts */
    DSSDispcIntrClear(baseAddr, DSS_DISPC_INTR_MASK_ALL);

    /* Enable VSYNC, SYNCLOST, VID1 Under flow interrupts */
    DSSDispcIntrEnable(baseAddr, (DSS_DISPC_INTR_MASK_VSYNC |
        DSS_DISPC_INTR_MASK_VID1_UNDER_FLOW |
        DSS_DISPC_INTR_MASK_SYNC_LOST_LCD));
}


static void DisplayUtilsIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    displayUtilsDssObj_t *pObj = pUserParam;
    uint32_t dssBaseAddr = pObj->dssInstAddr;
    uint32_t intrStatus = 0U;

    intrStatus = DSSDispcIntrStatus(dssBaseAddr);

    if(0 != intrStatus)
    {
        if(intrStatus & DSS_DISPC_INTR_MASK_VSYNC)
        {
            /* Previous frame has been transferred to LCD. Set the address
               of frame buffer from which next frame has to be taken for
               transfer. */
            if (NULL != pObj->pFnIsrCb)
            {
                pObj->nextBufAddr = pObj->pFnIsrCb(pObj->currBufAddr);

                DSSDispcVidSetBufAddr(dssBaseAddr, DSS_DISPC_VID_PIPELINE_ID_1,
                    pObj->nextBufAddr, DSS_DISPC_FRM_BUF_ID_0);

                pObj->currBufAddr = pObj->nextBufAddr;
            }

            /* Clear the interrupt status */
            DSSDispcIntrClear(dssBaseAddr, DSS_DISPC_INTR_MASK_VSYNC);

            /*
             * Set the GoLCD bit so that new buffer address will be
             * taken at next VFP.
             */
            DSSDispcShadowCfgEnable(dssBaseAddr);
        }
        else if (intrStatus & DSS_DISPC_INTR_MASK_VID1_UNDER_FLOW)
        {
            gDisplayUtilsUnderflowErrCnt++;

            /* Clear the interrupt status */
            DSSDispcIntrClear(dssBaseAddr,
                DSS_DISPC_INTR_MASK_VID1_UNDER_FLOW);

        }
        else if (intrStatus & DSS_DISPC_INTR_MASK_SYNC_LOST_LCD)
        {
            gDisplayUtilsSyncLostErrCnt++;

            /* Clear the interrupt status */
            DSSDispcIntrClear(dssBaseAddr,
                DSS_DISPC_INTR_MASK_SYNC_LOST_LCD);
        }
        else
        {
            /* This will not occur as no other interrupts are enabled. */
        }
    }
}
