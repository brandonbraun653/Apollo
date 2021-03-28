/**
 * \file   lcdc_app.c
 *
 * \brief  Source file containing the LCDC IP related configuration functions.
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
#include "lcdc.h"
#include "error.h"
#include "console_utils.h"
#include "soc_control.h"

/* Application header files */
#include "lcdc_app.h"
#include "prcm.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* TODO: This has to be get from the PRCM and will be removed later. */
#define LCDC_FUNCTIONAL_CLK              (192000000U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function performs the configuration of LCD controller and
 *          all of its sub modules including frame buffers and interrupts.
 *
 * \param   pApp   Pointer to the lcd controller application data structure.
 */
static void LcdcAppConfig(lcdcAppObj_t *pApp);


/**
 * \brief   This function performs the LCDC IP configurations.
 *
 * \param   pApp   Pointer to the lcd controller application data structure.
 */
static void LcdcAppIpInit(lcdcAppObj_t *pApp);


/**
 * \brief   This function configures the lcd controller's interrupts.
 *
 * \param   baseAddr  Memory address of LCDC.
 */
static void LcdcAppIntrConfig(uint32_t baseAddr);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Default values of lcd controller IP configuration data
           structure. */
lcdcAppObj_t   LCDCAPPOBJ_DEFAULT =
{
    0U,   /* lcdcInstAddr */
    0U,   /* lcdcSysIntrNum */
    0U,   /* lcdcfunctionalClk */
    0U,   /* lcdcLcdDeviceId */
    NULL, /* pInputBuf */
    0U,   /* inputBufSize */
    {
        {
            LCDC_DMA_FRM_MODE_DOUBLE_BUF, /* frameMode */
            LCDC_DMA_BURST_SIZE_16,       /* burstSize */
            LCDC_FIFO_THRESHOLD_8,        /* fifoThreshold */
            LCDC_DMA_DATA_ENDIAN_LITTLE   /* endian */
        }, /* lcdcDmaCfg_t */
        {
            {
                LCDC_RASTER_MATRIX_MODE_ACTIVE,   /* displayMode */
                LCDC_RASTER_DISPLAY_TYPE_COLOR,   /* displayType */
                LCDC_PIXEL_FORMAT_RGB24_UNPACKED, /* pixelFormat*/
                LCDC_PALETTE_MODE_BOTH_PALETTE_DATA, /* paletteMode */
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

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t LCDCAppInit(lcdcAppObj_t *pLcdc)
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
            /* LCDC IP configuration */
            LcdcAppConfig(pLcdc);

            status = S_PASS;
        }
    }

    return status;
}

/* ========================================================================== */
/*                        Internal Function Definitions                       */
/* ========================================================================== */

static void LcdcAppConfig(lcdcAppObj_t *pApp)
{
    /* Configure LCDC IP. */
    LcdcAppIpInit(pApp);

    /* Configure frame buffer0 */
    LCDCDmaFrameBufConfig(pApp->lcdcInstAddr, (uint32_t)pApp->pInputBuf,
        (uint32_t)pApp->pInputBuf + pApp->inputBufSize - 2U,
        LCDC_FRM_BUF_ID_0);

    /* Configure frame buffer1 */
    LCDCDmaFrameBufConfig(pApp->lcdcInstAddr, (uint32_t)pApp->pInputBuf,
        (uint32_t)pApp->pInputBuf + pApp->inputBufSize - 2U,
        LCDC_FRM_BUF_ID_1);

    /* Configure LCDC interrupts. */
    LcdcAppIntrConfig(pApp->lcdcInstAddr);

    /* Enable Raster output. */
    LCDCRasterEnable(pApp->lcdcInstAddr, TRUE);
}


static void LcdcAppIpInit(lcdcAppObj_t *pApp)
{
    lcdcAppCfg_t *pLcdc = &pApp->lcdcCfg;
    uint32_t baseAddr  = pApp->lcdcInstAddr;
    lcdcRasterAcbCfg_t acBias;

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
    acBias.acbFreq = 255U;
    acBias.acbi = 0U;
    LCDCRasterAcbiasConfig(baseAddr, &acBias);

    /* Configure DMA fifo delay. */
    LCDCRasterSetDmaFifoDelay(baseAddr, 128U);
}


static void LcdcAppIntrConfig(uint32_t baseAddr)
{
    /* Clear status of all the interrupts */
    LCDCIntrClear(baseAddr, LCDC_INTR_MASK_ALL);

    /* Enable end of frame0 and end of frame1 interrupts. */
    LCDCIntrEnable(baseAddr, (LCDC_INTR_MASK_END_OF_FRAME_0 |
        LCDC_INTR_MASK_END_OF_FRAME_1 | LCDC_INTR_MASK_FIFO_UNDERFLOW |
        LCDC_INTR_MASK_SYNC_LOST));
}
