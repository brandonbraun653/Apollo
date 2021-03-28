/**
 *  \file     display_utils_lcdc.c
 *
 *  \brief    This file contains the display utility APIs corresponding to
 *            the LCDC IP.
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
#include "soc_control.h"

#include "display_utils_ip.h"
#include "display_utils_lcdc.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief LCD device instance number. */
#define LCDC_LCD_INST_NUM           (0U)

/** \brief LCD device instance number. */
/*TODO: This functional value should be read from board. */
#define LCDC_FUNCTIONAL_CLK         (192U * FREQ_MHZ)

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
 * \param   pObj        Pointer to the lcdc object.
 *
 * \retval  S_PASS      Board info successfully retrieved. LCD is connected to
 *                      LCDC on this board.
 * \retval  E_FAIL      This board does not support this application.
 *                      - LCD device may not be available on this board or even
 *                        if it is available, it is not connected to LCDC on
 *                        this board.
 */
static int32_t DisplayUtilsGetBoardInfo(displayUtilsLcdcObj_t *pObj);


/**
 * \brief   This API gets the soc info - base address of LCDC instance and
 *          interrupt number of lcd controller.
 *
 * \param   pObj        Pointer to the lcdc object.
 *
 * \retval  S_PASS      Soc info is successfully retrieved.
 * \retval  E_FAIL      Soc info retrieval is failed.
 */
static int32_t DisplayUtilsGetSocInfo(displayUtilsLcdcObj_t *pObj);


/**
 * \brief   This API configures the system interrupt controller and enables the
 *          lcd controller's system interrupt.
 *
 * \param   intrNum     LCDC System interrupt number
 *
 * \retval  S_PASS      Interrupt controller configuration is successful.
 * \retval  E_FAIL      Interrupt controller configuration is failed.
 */
static int32_t DisplayUtilsInterruptConfig(uint32_t intrNum);


/**
 * \brief   This API updates the device data i.e, LCD timing and polarity
 *          parameter values in the IP configuration data structure.
 *
 * \param   pLcdc       Pointer to the lcdc object.
 * \param   pLcdData    Pointer to the structure holding the LCD panel data.
 */
static void DisplayUtilsUpdateIpConfigParams(displayUtilsLcdcObj_t *pLcdc,
                                             lcdDeviceData_t *pLcdData);


/**
 * \brief   This API performs the clock and pin mux configurations of LCDC IP.
 *
 * \param   pLcdc   Pointer to the lcdc object.
 *
 * \retval  S_PASS  Clock and pin mux configuration is successful.
 * \retval  E_FAIL  Clock and pin mux configuration is failed.
 */
static int32_t DisplayUtilsLcdcIpInit(displayUtilsLcdcObj_t *pLcdc);


/**
 * \brief   This API performs the IP configuration and also frame buffer
 *          configuration.
 *
 * \param   pApp    Pointer to the lcdc object.
 *
 * \retval  S_PASS  IP configuration is successful.
 * \retval  E_FAIL  IP configuration is failed.
 */
static int32_t DisplayUtilsLcdcConfig(displayUtilsLcdcObj_t *pApp);


/**
 * \brief   This API performs the LCDC IP configuration like DMA and lcd
 *          configurations.
 *
 * \param   pApp    Pointer to the lcdc object.
 *
 * \retval  S_PASS  IP configuration is successful.
 * \retval  E_FAIL  IP configuration is failed.
 */
static void DisplayUtilsLcdcInit(displayUtilsLcdcObj_t *pApp);


/**
 * \brief   This function configures the lcd controller's interrupts.
 *
 * \param   baseAddr  Memory address of lcdc.
 */
static void DisplayUtilsLcdcIntrConfig(uint32_t baseAddr);


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

/** \brief Default values of lcd controller IP configuration data
           structure. */
displayUtilsLcdcObj_t   LCDCAPPOBJ_DEFAULT =
{
    0U,   /* lcdcInstAddr */
    0U,   /* lcdcSysIntrNum */
    0U,   /* lcdcfunctionalClk */
    0U,   /* lcdcLcdDeviceId */
    0U,   /* inputBufAddr */
    0U,   /* inputBufSize */
    NULL, /* pFnIsrCb */
    0U,   /* nextBufAddr */
    0U,   /* currBufAddr */
    {
        {
            LCDC_DMA_FRM_MODE_DOUBLE_BUF, /* frameMode */
            LCDC_DMA_BURST_SIZE_16,       /* burstSize */
            LCDC_FIFO_THRESHOLD_8,        /* fifoThreshold */
            LCDC_DMA_DATA_ENDIAN_LITTLE,   /* endian */
        }, /* lcdcDmaCfg_t */
        {
            {
                LCDC_RASTER_MATRIX_MODE_ACTIVE,   /* displayMode */
                LCDC_RASTER_DISPLAY_TYPE_COLOR,   /* displayType */
                LCDC_PIXEL_FORMAT_RGB24_UNPACKED, /* pixelFormat*/
                LCDC_PALETTE_MODE_DATA, /* paletteMode */
                TRUE,                             /* enableExtrapolate */
                LCDC_MONO_TYPE_8_BIT,             /* mono8Bit */
            }, /* lcdcRasterDisplayAttrCfg_t */
            {
                800U,       /* ppl */
                40U,        /* hfp */
                40U,        /* hbp */
                48U,        /* hsw */
                482U,       /* lpp */
                13U,        /* vfp */
                29U,        /* vbp */
                3U,         /* vsw */
                23040000U,  /* pixelClk */
            }, /* lcdcRasterTimingCfg_t */
            {
                LCDC_RASTER_H_SYNC_POL_LOW,         /* hSyncPolarity */
                LCDC_RASTER_V_SYNC_POL_LOW,         /* vSyncPolarity */
                LCDC_RASTER_OUTPUT_ENABLE_POL_HIGH, /*outputEnablePolarity*/
                LCDC_RASTER_PCLK_POL_RISING_EDGE,   /* pixelClkPolarity */
                LCDC_RASTER_ACTIVE_SYNC_EDGE_RISING, /* syncEdge*/
                LCDC_RASTER_SYNC_CTRL_INACTIVE,      /* sycnEdgeCtrl */
            }, /* lcdcRasterPolarityCfg_t */
        }, /* lcdcAppLcdCfg_t */
    }, /* lcdcAppCfg_t */
};


/** \brief Global data structure holding the LCDC IP configuration parameters.*/
displayUtilsLcdcObj_t gLcdc;

/** \brief Counter indicating the number of under flow interrupts. */
volatile uint32_t gDisplayUtilsUnderflowErrCnt = 0U;

/** \brief Counter indicating the number of sync lost interrupts. */
volatile uint32_t gDisplayUtilsSyncLostErrCnt = 0U;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t DISPLAYUtilsModuleInit(void)
{
    int32_t status = S_PASS;
    lcdDeviceData_t *lcdDeviceData;

    /* Initialize the global IP configuration object with default values. */
    gLcdc = LCDCAPPOBJ_DEFAULT;

    /* Get board info */
    status = DisplayUtilsGetBoardInfo(&gLcdc);
    if (S_PASS == status)
    {
        /* Get SoC info */
        status = DisplayUtilsGetSocInfo(&gLcdc);
        if (S_PASS == status)
        {
            /* Perform initialization of Interrupt controller*/
            INTCInit(FALSE);

            /* LCDC Interrupt configuration */
            status = DisplayUtilsInterruptConfig(gLcdc.lcdcSysIntrNum);
            if (S_PASS == status)
            {
                /* Get the LCD panel data */
                lcdDeviceData = LCDGetDeviceData(gLcdc.lcdcLcdDeviceId);

                /* Update IP config parameters with device,use case values */
                DisplayUtilsUpdateIpConfigParams(&gLcdc, lcdDeviceData);

                /* LCDC clock/pin mux and IP configuration */
                status = DisplayUtilsLcdcIpInit(&gLcdc);
                if (S_PASS == status)
                {
                    CONSOLEUtilsPrintf("\n LCDC Module init is successful \n");
                }
                else
                {
                    CONSOLEUtilsPrintf("\n LCDC Module init is failed. \n");
                }
            }
            else
            {
                CONSOLEUtilsPrintf("\nInterrupt configuration failed ...\n");
            }
        }
        else
        {
            CONSOLEUtilsPrintf("\nIP information is not present \n");
        }
    }
    else
    {
        CONSOLEUtilsPrintf("This example is not supported on this board!\n");
    }

    return status;
}


int32_t DISPLAYUtilsIpConfig(uint32_t bufAddr,
                             uint32_t bufSize,
                             uint32_t inputWidth,
                             uint32_t inputHeight,
                             uint32_t inputPixelFmt,
                             DISPLAYUtilsIsrCallbackFxn pFnCb)
{
    uint32_t status = E_FAIL;
    uint32_t pixelFmt = 0U;
    displayUtilsLcdcObj_t *pLcdc = &gLcdc;
    uint32_t lcdWidth  = pLcdc->lcdcCfg.lcd.timingCfg.ppl;
    uint32_t lcdHeight = pLcdc->lcdcCfg.lcd.timingCfg.lpp;

    if((inputPixelFmt >= DISPLAY_UTILS_PIXEL_FMT_MIN) &&
        (inputPixelFmt <= DISPLAY_UTILS_PIXEL_FMT_MAX) &&
        (DISPLAY_UTILS_PIXEL_FMT_YUV2 != inputPixelFmt))
    {
        /* Map the input pixel format to ip configuration value. */
        switch(inputPixelFmt)
        {
            case DISPLAY_UTILS_PIXEL_FMT_RGB12:
                pixelFmt = LCDC_PIXEL_FORMAT_RGB12;
                break;

            case DISPLAY_UTILS_PIXEL_FMT_RGB16:
                pixelFmt = LCDC_PIXEL_FORMAT_RGB16;
                break;

            case DISPLAY_UTILS_PIXEL_FMT_RGB24_UNPACKED:
                pixelFmt = LCDC_PIXEL_FORMAT_RGB24_UNPACKED;
                break;

            default:
            break;
        }

        /* Update the video window and format configuration parameters. */
        pLcdc->lcdcCfg.lcd.attrCfg.pixelFormat = pixelFmt;

        /* Update the buffer pointer  and buffer size */
        pLcdc->inputBufAddr = bufAddr;
        pLcdc->inputBufSize = bufSize;
        pLcdc->currBufAddr  = bufAddr;

        /* Update ISR call back function pointer */
        pLcdc->pFnIsrCb = pFnCb;

        if((inputWidth <= lcdWidth) && (inputHeight <= lcdHeight))
        {
            /* Display subsystem configuration */
            status = DisplayUtilsLcdcConfig(pLcdc);
            if(S_PASS == status)
            {
                CONSOLEUtilsPrintf("\n LCDC IP configuration is successful.\n");
            }
            else
            {
                CONSOLEUtilsPrintf("\n LCDC IP configuration is failed. \n");
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
    LCDCRasterEnable(gLcdc.lcdcInstAddr, TRUE);
}

void DISPLAYUtilsIpDisplayDisable(void)
{
    LCDCRasterEnable(gLcdc.lcdcInstAddr, FALSE);
}


void DISPLAYUtilsIpGetDisplayResolution(uint32_t *pWidth, uint32_t *pHeight)
{
    lcdcRasterTimingCfg_t *pTiming = &gLcdc.lcdcCfg.lcd.timingCfg;

    *pWidth  = pTiming->ppl;
    *pHeight = pTiming->lpp;
}

/* ========================================================================== */
/*                        Internal Function Definitions                       */
/* ========================================================================== */

static int32_t DisplayUtilsGetBoardInfo(displayUtilsLcdcObj_t *pObj)
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
            pObj->lcdcLcdDeviceId = lcdDeviceIdlist[devIndex];
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
        /* Get the control mod id for the current device */
        modId = BOARDGetDeviceCtrlModId(pObj->lcdcLcdDeviceId,
            LCDC_LCD_INST_NUM);

        if (CHIPDB_MOD_ID_INVALID == modId)
        {
            CONSOLEUtilsPrintf("Device is not available on this board!\n");
        }
        else if (CHIPDB_MOD_ID_LCDC == modId)
        {
            CONSOLEUtilsPrintf("Device is connected to LCDC on this board!\n");

            /* Function to power on the device */
            BOARDPowerOnDevice(pObj->lcdcLcdDeviceId, LCDC_LCD_INST_NUM, TRUE);

            status = S_PASS;
        }
        else
        {
            CONSOLEUtilsPrintf("Device is not connected to LCDC!\n");
        }
    }

    return (status);
}


static int32_t DisplayUtilsGetSocInfo(displayUtilsLcdcObj_t *pObj)
{
    int32_t status = E_FAIL;

    if (TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_LCDC, 0U))
    {
        pObj->lcdcInstAddr = CHIPDBBaseAddress(CHIPDB_MOD_ID_LCDC, 0U);

        if (SOC_FAMILY_ID_AM335X == SOCGetSocFamilyId())
        {
            /*TODO: This interrupt number has to be provided by soc info */
            pObj->lcdcSysIntrNum = 36U;
            status = S_PASS;
        }
        else
        {
            /* SOC is not AM335x */
            status = E_FAIL;
        }
    }
    else
    {
        CONSOLEUtilsPrintf("LCDC IP is not present on this SOC!\n");
    }

    return status;
}


static int32_t DisplayUtilsInterruptConfig(uint32_t intrNum)
{
    int32_t status = S_PASS;
    intcIntrParams_t lcdcIntrParams;

    lcdcIntrParams.triggerType    = INTC_TRIG_HIGH_LEVEL;
    lcdcIntrParams.priority       = 0x20U;
    lcdcIntrParams.pFnIntrHandler = &DisplayUtilsIsr;
    lcdcIntrParams.isIntrSecure   = FALSE;
    lcdcIntrParams.pUserParam     = &gLcdc;

    /* Configure the interrupt controller */
    status = INTCConfigIntr(intrNum, &lcdcIntrParams, FALSE);
    if(S_PASS != status)
    {
        CONSOLEUtilsPrintf(" Interrupt controller configuration failed \n ");
    }

    return status;
}


static void DisplayUtilsUpdateIpConfigParams(displayUtilsLcdcObj_t *pLcdc,
                                             lcdDeviceData_t *pLcdData)
{
    lcdcRasterTimingCfg_t *pTiming = &pLcdc->lcdcCfg.lcd.timingCfg;
    lcdcRasterPolarityCfg_t *pPol  = &pLcdc->lcdcCfg.lcd.polarityCfg;

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
        pLcdData->hSyncPolarity) ? LCDC_RASTER_H_SYNC_POL_LOW :
        LCDC_RASTER_H_SYNC_POL_HIGH;
    pPol->vSyncPolarity = (LCD_SIG_POLARITY_ACTIVE_LOW ==
        pLcdData->vSyncPolarity) ? LCDC_RASTER_V_SYNC_POL_LOW :
        LCDC_RASTER_V_SYNC_POL_HIGH;
    pPol->outputEnablePolarity = (LCD_SIG_POLARITY_ACTIVE_LOW ==
        pLcdData->outputEnablePolarity) ? LCDC_RASTER_OUTPUT_ENABLE_POL_LOW :
        LCDC_RASTER_OUTPUT_ENABLE_POL_HIGH;
    pPol->pixelClkPolarity = (LCD_ACTIVE_EDGE_RISING ==
        pLcdData->pixelClkPolarity) ? LCDC_RASTER_PCLK_POL_RISING_EDGE :
        LCDC_RASTER_PCLK_POL_FALLING_EDGE;
    pPol->syncEdge = (LCD_ACTIVE_EDGE_RISING == pLcdData->activeSyncEdge) ?
        LCDC_RASTER_ACTIVE_SYNC_EDGE_RISING :
        LCDC_RASTER_ACTIVE_SYNC_EDGE_FALLING;
    pPol->sycnEdgeCtrl = (LCD_SYNC_EDGE_CTRL_SAME_EDGE ==
    pLcdData->syncEdgeControl) ? LCDC_RASTER_SYNC_CTRL_INACTIVE :
    LCDC_RASTER_SYNC_CTRL_ACTIVE;
}


static int32_t DisplayUtilsLcdcIpInit(displayUtilsLcdcObj_t *pLcdc)
{
    int32_t status = E_FAIL;

    /* Select the input clock source for deriving the pixel clock. */
    SOCCtrlLcdcPixelClkSelect();

    /* Clock configuration */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_LCDC, 0U, FALSE);
    if (S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n Clock configuration is failed \n");
    }
    else
    {
        /*TODO: Get the lcd controller input functional clock */
        pLcdc->lcdcfunctionalClk = LCDC_FUNCTIONAL_CLK;

        /* Pin Mux configuration */
        status = PINMUXModuleConfig(CHIPDB_MOD_ID_LCDC, 0U, NULL);
        if (S_PASS != status)
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


static int32_t DisplayUtilsLcdcConfig(displayUtilsLcdcObj_t *pApp)
{
    int32_t status = S_PASS;

    /* Configure LCDC IP. */
    DisplayUtilsLcdcInit(pApp);

    /* Configure frame buffer0 */
    LCDCDmaFrameBufConfig(pApp->lcdcInstAddr, pApp->inputBufAddr,
        pApp->inputBufAddr + pApp->inputBufSize, LCDC_FRM_BUF_ID_0);

    /* Configure frame buffer1 */
    LCDCDmaFrameBufConfig(pApp->lcdcInstAddr, pApp->inputBufAddr,
        pApp->inputBufAddr + pApp->inputBufSize, LCDC_FRM_BUF_ID_1);

    /* Configure LCDC interrupts. */
    DisplayUtilsLcdcIntrConfig(pApp->lcdcInstAddr);

    return status;
}


static void DisplayUtilsLcdcInit(displayUtilsLcdcObj_t *pApp)
{
    displayUtilsLcdcCfg_t *pLcdc = &pApp->lcdcCfg;
    uint32_t baseAddr  = pApp->lcdcInstAddr;
    lcdcRasterAcbCfg_t acb;

    /* Enable all the clocks inside the LCDC. */
    LCDCClocksEnable(baseAddr);

    /* Disable Raster output. */
    LCDCRasterEnable(baseAddr, FALSE);

    /* Configure clock divider. */
    LCDCClkConfig(baseAddr, pLcdc->lcd.timingCfg.pixelClk,
        pApp->lcdcfunctionalClk);

    /* Configure LCDC DMA parameters. */
    LCDCDmaConfig(baseAddr, &pLcdc->dma);

    /* Configure LCD display attributes. */
    LCDCRasterDisplayModeConfig(baseAddr, &pLcdc->lcd.attrCfg);

    /* Configure LCD panel timing parameters. */
    LCDCRasterTimingConfig(baseAddr, &pLcdc->lcd.timingCfg);

    /* Configure LCD signal polarities. */
    LCDCRasterPolarityConfig(baseAddr, &pLcdc->lcd.polarityCfg);

    /* Configure Ac bias parameters. */
    acb.acbFreq = 255U;
    acb.acbi = 0U;
    LCDCRasterAcbiasConfig(baseAddr, &acb);

    /* Configure DMA fifo delay. */
    LCDCRasterSetDmaFifoDelay(baseAddr, 128U);
}


static void DisplayUtilsLcdcIntrConfig(uint32_t baseAddr)
{
    /* Clear status of all the interrupts */
    LCDCIntrClear(baseAddr, LCDC_INTR_MASK_ALL);

    /* Enable end of frame0 and end of frame1 interrupts. */
    LCDCIntrEnable(baseAddr, (LCDC_INTR_MASK_END_OF_FRAME_0 |
        LCDC_INTR_MASK_END_OF_FRAME_1 | LCDC_INTR_MASK_FIFO_UNDERFLOW |
        LCDC_INTR_MASK_SYNC_LOST));
}


static void DisplayUtilsIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    displayUtilsLcdcObj_t *pObj = pUserParam;
    uint32_t lcdcBaseAddr = pObj->lcdcInstAddr;
    uint32_t intrStatus = 0U;

    intrStatus = LCDCIntrStatus(lcdcBaseAddr);

    if (0U != intrStatus)
    {
        if (intrStatus & LCDC_INTR_MASK_END_OF_FRAME_0)
        {
            if(NULL != pObj->pFnIsrCb)
            {
                pObj->nextBufAddr = pObj->pFnIsrCb(pObj->currBufAddr);

                LCDCDmaFrameBufConfig(lcdcBaseAddr, pObj->inputBufAddr,
                    pObj->inputBufAddr + pObj->inputBufSize, LCDC_FRM_BUF_ID_0);

                pObj->currBufAddr = pObj->nextBufAddr;
            }

            LCDCIntrClear(lcdcBaseAddr, LCDC_INTR_MASK_END_OF_FRAME_0);
        }

        if (intrStatus & LCDC_INTR_MASK_END_OF_FRAME_1)
        {
            if(NULL != pObj->pFnIsrCb)
            {
                pObj->nextBufAddr = pObj->pFnIsrCb(pObj->currBufAddr);

                LCDCDmaFrameBufConfig(lcdcBaseAddr, pObj->inputBufAddr,
                    pObj->inputBufAddr + pObj->inputBufSize, LCDC_FRM_BUF_ID_1);

                pObj->currBufAddr = pObj->nextBufAddr;
            }

            LCDCIntrClear(lcdcBaseAddr, LCDC_INTR_MASK_END_OF_FRAME_1);
        }

        if (intrStatus & LCDC_INTR_MASK_FIFO_UNDERFLOW)
        {
            gDisplayUtilsUnderflowErrCnt++;
            LCDCIntrClear(lcdcBaseAddr, LCDC_INTR_MASK_FIFO_UNDERFLOW);
        }

        if (intrStatus & LCDC_INTR_MASK_SYNC_LOST)
        {
            gDisplayUtilsSyncLostErrCnt++;
            LCDCIntrClear(lcdcBaseAddr, LCDC_INTR_MASK_SYNC_LOST);
        }
    }
}
