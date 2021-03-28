/**
 *  \file    dss.h
 *
 *  \brief   This file contains the function prototypes for the device
 *           abstraction layer for display sub system. It also contains
 *           related macro and structure definitions.
 *
 *  \details Programming sequence of display sub system:
 *           -# Display Sub System Reset:
 *            -# Perform soft reset of display subsystem using the
 *              API #DSSSoftReset.
 *            -# Perform soft reset of the sub module display controller using
 *              the API #DSSDispcSoftReset.
 *           -# Configuring display controller
 *            -# Pipeline configuration
 *             -# Graphics pipeline
 *              -# If enabled, perform following configurations:
 *               -# Configure the graphics DMA using the
 *                  API #DSSDispcGfxDmaConfig.
 *               -# Configure DMA priority using the API #DSSDispcSetGfxPriority
 *               -# Configure DMA self refresh using the API
 *                  #DSSDispcGfxSelfRefreshEnable.
 *               -# Configure the graphics pipe input data format using the API
 *                  #DSSDispcGfxFormatConfig.
 *               -# Configure the palette/gamma table processing using the API
 *                  #DSSDispcGfxPaletteGammaCfg.
 *               -# Configure the position of graphics window in overlay using
 *                  the API #DSSDispcGfxWindowPositionCfg.
 *               -# Configure the size of graphics window in overlay using the
 *                  API #DSSDispcGfxWindowSizeConfig.
 *               -# Set the graphics input image buffer address using the API
 *                  #DSSDispcGfxSetBufAddr.
 *              -# To disable graphics pipeline call the API #DSSDispcGfxEnable
 *                 with enable parameter value as FALSE.
 *             -# Video1 and Video2 pipeline
 *              -# If enabled, perform following configurations:
 *               -# Configure the video DMA using the API #DSSDispcVidDmaConfig.
 *               -# Configure the DMA priority using the
 *                  API #DSSDispcSetVidPriority.
 *               -# Configure the DMA self refresh using the API
 *                  #DSSDispcVidDmaSelfRefreshEnable
 *               -# Configure the video pipeline input data format using the API
 *                  #DSSDispcVidFormatConfig.
 *               -# Configure the position of video window in overlay using
 *                  the API #DSSDispcVidWindowPositionCfg.
 *               -# Configure the video pipeline input and output sizes using
 *                  the API #DSSDispcVidSizeConfig.
 *               -# If input and output sizes are equal then disable the
 *                  resizing the API #DSSDispcVidResizeDisable.
 *               -# If input and output sizes are not equal and if user control
 *                  flag for resizing is On then perform the following resizing
 *                  operations:
 *                -# Enable resizing and configure the type of resizing
 *                  (Horizontal/Vertical/Both) required and filter taps required
 *                  for the resizing operation using the API
 *                  #DSSDispcVidResizeEnable.
 *                -# If horizontal resizing is required, then perform following:
 *                 -# Configure the horizontal resizing parameters using the
 *                    API #DSSDispcVidHorzResizeCfg.
 *                 -# Configure the horizontal resizing coefficients using the
 *                    API #DSSDispcVidHorzResizeCoeffCfg.
 *                -# If vertical resizing is required, then perform following:
 *                 -# Configure the vertical resizing parameters using the
 *                    API #DSSDispcVidVertResizeCfg.
 *                 -# Configure the vertical resizing coefficients using the
 *                    API #DSSDispcVidVertResizeCoeffCfg.
 *               -# Set the video input image buffer address using the
 *                  API #DSSDispcVidSetBufAddr.
 *              -# To disable video pipeline, call the API #DSSDispcVidEnable.
 *                 by passing the enable value as FALSE.
 *            -# Overlay configuration
 *             -# Set the solid background color using the
 *                API #DSSDispcOverlaySetBackgndColor.
 *             -# Transparency color key
 *              -# If disabled, use the API #DSSDispcOverlayTckDisable.
 *              -# If enabled, configure TCK using the
 *                 API #DSSDispcOverlayTckEnable.
 *             -# Alpha blending
 *              -# To enable/disable call the API
 *                 #DSSDispcOverlayAlphaBlenderEnable.
 *              -# Configure the global alpha value using the
 *                 API #DSSDispcOverlaySetGlobalAlpha.
 *            -# LCD parameters configuration
 *             -# Configure the lcd pixel clock using the API
 *                #DSSDispcLcdClkConfig.
 *             -# Configure the lcd display attributes using the
 *                API #DSSDispcLcdDisplayAttrConfig.
 *             -# Configure the lcd panel timing parameters using the
 *                API #DSSDispcLcdTimingConfig.
 *             -# Configure the lcd panel signal polarities using the
 *                API #DSSDispcLcdPolarityConfig.
 *             -# Configure the lcd ac bias configurations using the
 *                API #DSSDispcLcdAcbiasConfig.
 *             -# Configure the lcd signal gated control using the
 *                API #DSSDispcLcdSigGatedCtrl.
 *             -# Spatial/Temporal dithering
 *              -# If disabled, call the API #DSSDispcStDitheringDisable.
 *              -# If enabled, call the API #DSSDispcStDitheringEnable.
 *            -# Configure the display controller's interrupts
 *             -# Enable required interrupts using the API #DSSDispcIntrEnable
 *            -# Configure the display controller in RFBI bypass mode using
 *               the API #DSSDispcSetRfbiBypassMode.
 *           -# Start the LCD display
 *            -# Enable all the required pipelines using the following APIs
 *              (enable parameter should be TRUE)
 *               #DSSDispcGfxEnable, #DSSDispcVidEnable
 *            -# Set the GOLCD bit using the API #DSSDispcShadowCfgEnable so
 *               that the shadow register configurations will be taken effect at
 *               the next VFP.
 *            -# Enable LCD output using the API #DSSDispcLcdOutputEnable.
 *           -# To stop the display following API should be called with the
 *              second parameter value as FALSE: #DSSDispcLcdOutputEnable.
 *
 *  \copyright Copyright (C) 2013 - 2018 Texas Instruments Incorporated -
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

#ifndef DSS_H_
#define DSS_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "hw_dss_submodule_offsets.h"
#include "hw_dss_top.h"
#include "hw_dss_dispc.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Number of pipelines present in Display Sub System. */
#define DSS_NUM_VID_PIPELINES      (2U)

/** \brief Number of phases of re-sizer */
#define DSS_RESIZER_NUM_PHASES     (8U)


/** \brief Maximum divisor value for pixel and logic clocks. */
#define DSS_LCD_DIVISOR_MAX (255U)

/**
 *  \name Programmable line number min and max values
 */
/** @{ */
/** \brief Minimum value for programme line number. */
#define DSS_DISPC_LCD_PL_NUMBER_MIN       (0U)

/** \brief Maximum value for programme line number. */
#define DSS_DISPC_LCD_PL_NUMBER_MAX       (2047U)
/** @} */


/**
 *  \name Graphics window position min and max values
 */
/** @{ */
/** \brief Minimum value of X position of graphics window. */
#define DSS_DISPC_GFX_WINDOW_XPOS_MIN   (0U)

/** \brief Maximum value of X position of graphics window. */
#define DSS_DISPC_GFX_WINDOW_XPOS_MAX   (2047U)

/** \brief Minimum value of Y position of graphics window. */
#define DSS_DISPC_GFX_WINDOW_YPOS_MIN   (0U)

/** \brief Maximum value of Y position of graphics window. */
#define DSS_DISPC_GFX_WINDOW_YPOS_MAX   (2047U)
/** @} */

/**
 *  \name Graphics window size min and max values
 */
/** @{ */
/** \brief Minimum value of width of graphics window. */
#define DSS_DISPC_GFX_SIZE_X_MIN        (1U)

/** \brief Minimum value of width of graphics window. */
#define DSS_DISPC_GFX_SIZE_X_MAX        (2048U)

/** \brief Minimum value of height of graphics window. */
#define DSS_DISPC_GFX_SIZE_Y_MIN        (1U)

/** \brief Minimum value of height of graphics window. */
#define DSS_DISPC_GFX_SIZE_Y_MAX        (2048U)
/** @} */

/**
 *  \name Video window position min and max values
 */
/** @{ */
/** \brief Minimum value of X position of video window. */
#define DSS_DISPC_VID_WINDOW_XPOS_MIN           (0U)

/** \brief Maximum value of X position of video window. */
#define DSS_DISPC_VID_WINDOW_XPOS_MAX           (2047U)

/** \brief Minimum value of Y position of video window. */
#define DSS_DISPC_VID_WINDOW_YPOS_MIN           (0U)

/** \brief Minimum value of Y position of video window. */
#define DSS_DISPC_VID_WINDOW_YPOS_MAX           (2047U)
/** @} */

/**
 *  \name Minimum and maximum values of Video pipeline input image width and
 *        heights.
 */
/** @{ */
/** \brief Minimum value of input image width. */
#define DSS_DISPC_VID_ORG_SIZE_X_MIN            (1U)

/** \brief Maximum value of input image width. */
#define DSS_DISPC_VID_ORG_SIZE_X_MAX            (2048U)

/** \brief Minimum value of input image height. */
#define DSS_DISPC_VID_ORG_SIZE_Y_MIN            (1U)

/** \brief Maximum value of input image height. */
#define DSS_DISPC_VID_ORG_SIZE_Y_MAX            (2048U)
/** @} */

/**
 *  \name Minimum and maximum values of Output Video window width and heights
 */
/** @{ */
/** \brief Minimum value of output width of video window. */
#define DSS_DISPC_VID_SIZE_X_MIN                (1U)

/** \brief Maximum value of output width of video window. */
#define DSS_DISPC_VID_SIZE_X_MAX                (2048U)

/** \brief Minimum value of output height of video window. */
#define DSS_DISPC_VID_SIZE_Y_MIN                (1U)

/** \brief Maximum value of output height of video window. */
#define DSS_DISPC_VID_SIZE_Y_MAX                (2048U)
/** @} */


/**
 *  \name Minimum and maximum values of LCD panel parameters.
 */
/** @{ */
/** \brief Minimum value of Pixel Per Line. */
#define DSS_DISPC_LCD_PPL_MIN         (1U)

/** \brief Maximum value of Pixel Per Line. */
#define DSS_DISPC_LCD_PPL_MAX         (2048U)

/** \brief Minimum value of Lines Per Panel. */
#define DSS_DISPC_LCD_LPP_MIN         (1U)

/** \brief Maximum value of Lines Per Panel. */
#define DSS_DISPC_LCD_LPP_MAX         (2048U)

/** \brief Minimum value of Horizontal Back Porch. */
#define DSS_DISPC_LCD_HBP_MIN         (1U)

/** \brief Maximum value of Horizontal Back Porch. */
#define DSS_DISPC_LCD_HBP_MAX         (4096U)

/** \brief Minimum value of Horizontal Front Porch. */
#define DSS_DISPC_LCD_HFP_MIN         (1U)

/** \brief Maximum value of Horizontal Front Porch. */
#define DSS_DISPC_LCD_HFP_MAX         (4096U)

/** \brief Minimum value of Horizontal Sync Width. */
#define DSS_DISPC_LCD_HSW_MIN         (1U)

/** \brief Maximum value of Horizontal Sync Width. */
#define DSS_DISPC_LCD_HSW_MAX         (256U)

/** \brief Minimum value of Vertical Back Porch. */
#define DSS_DISPC_LCD_VBP_MIN         (0U)

/** \brief Maximum value of Vertical Back Porch. */
#define DSS_DISPC_LCD_VBP_MAX         (4095U)

/** \brief Minimum value of Vertical Front Porch. */
#define DSS_DISPC_LCD_VFP_MIN         (0U)

/** \brief Maximum value of Vertical Back Porch. */
#define DSS_DISPC_LCD_VFP_MAX         (4095U)

/** \brief Minimum value of Vertical Sync Width. */
#define DSS_DISPC_LCD_VSW_MIN         (1U)

/** \brief Maximum value of Vertical Sync Width. */
#define DSS_DISPC_LCD_VSW_MAX         (256U)
/** @} */


/**
 *  \name Minimum and maximum values of global alpha values of graphics and
 *        video2 pipelines.
 */
/** @{ */
/** \brief Minimum value of Video2 Global Alpha. */
#define DSS_DISPC_OVLY_VID2_GLOBAL_ALPHA_MIN  (0U)

/** \brief Maximum value of Video2 Global Alpha. */
#define DSS_DISPC_OVLY_VID2_GLOBAL_ALPHA_MAX  (255U)

/** \brief Minimum value of graphics Global Alpha. */
#define DSS_DISPC_OVLY_GFX_GLOBAL_ALPHA_MIN   (0U)

/** \brief Maximum value of graphics Global Alpha. */
#define DSS_DISPC_OVLY_GFX_GLOBAL_ALPHA_MAX   (255U)
/** @} */


/** \brief Enumerates the display controller's slave idle modes. */
typedef enum dssDispcIdleMode
{
    DSS_DISPC_IDLE_MODE_FORCE_IDLE = DISPC_SYSCFG_SIDLEMODE_FORCEIDLE,
    /**< Force idle mode. */
    DSS_DISPC_IDLE_MODE_NO_IDLE    = DISPC_SYSCFG_SIDLEMODE_NOIDLE,
    /**< No Idle mode. */
    DSS_DISPC_IDLE_MODE_SMART_IDLE = DISPC_SYSCFG_SIDLEMODE_SMARTIDLE
    /**< Smart idle mode. */
}dssDispcIdleMode_t;


/** \brief Enumerates the Display controller's supported standby modes. */
typedef enum dssDispcStandbyMode
{
    DSS_DISPC_STANDBY_MODE_FORCE  = DISPC_SYSCFG_MIDLEMODE_FORCESTANDBY,
    /**< Force stand by mode. */
    DSS_DISPC_STANDBY_MODE_NONE   = DISPC_SYSCFG_MIDLEMODE_NOSTANDBY,
    /**< No stand by mode. */
    DSS_DISPC_STANDBY_MODE_SMART  = DISPC_SYSCFG_MIDLEMODE_SMARTSTANDBY
    /**< Smart stand by mode. */
}dssDispcStandbyMode_t;


/** \brief Enumerates the supported display controller clock activity modes. */
typedef enum dssDispcClkActivity
{
    DSS_DISPC_CLK_ACTIVITY_ICLK_FCLK_OFF =
        DISPC_SYSCFG_CLOCK_ACTIVITY_IN_FUN_OFF,
    /**< Both the interface and functional clocks are off. */
    DSS_DISPC_CLK_ACTIVITY_FLCK_OFF =
        DISPC_SYSCFG_CLOCK_ACTIVITY_FUN_OFF,
        /**< Interface clock is on and functional clock is off. */
    DSS_DISPC_CLK_ACTIVITY_ICLK_OFF =
        DISPC_SYSCFG_CLOCK_ACTIVITY_IN_OFF,
    /**< Interface clock is off and functional clock is on. */
    DSS_DISPC_CLK_ACTIVITY_ICLK_FCLK_ON =
        DISPC_SYSCFG_CLOCK_ACTIVITY_IN_FUN_ON
    /**< Both interface and functional clocks are on. */
}dssDispcClkActivity_t;


/** \brief Enumerates the display controller interrupts. */
typedef enum dssDispcIntrMask
{
    DSS_DISPC_INTR_MASK_FRM_DONE = DISPC_IRQEN_FRM_DONE_MASK,
    /**< Frame done interrupt. */
    DSS_DISPC_INTR_MASK_VSYNC = DISPC_IRQEN_VSYNC_MASK,
    /**< Vertical sync interrupt. */
    DSS_DISPC_INTR_MASK_EVSYNC_EVEN = DISPC_IRQEN_EVSYNC_EVEN_MASK,
    /**< Sync interrupt for even field. */
    DSS_DISPC_INTR_MASK_EVSYNC_ODD = DISPC_IRQEN_EVSYNC_ODD_MASK,
    /**< Sync interrupt for odd field. */
    DSS_DISPC_INTR_MASK_ACBIAS_CNT = DISPC_IRQEN_ACBIAS_COUNT_STS_MASK,
    /**< AC Bias count interrupt. */
    DSS_DISPC_INTR_MASK_PROG_LINE_NO = DISPC_IRQEN_PGM_LINE_NO_MASK,
    /**< Programmed Line number interrupt. */
    DSS_DISPC_INTR_MASK_GFX_UNDER_FLOW = DISPC_IRQEN_GFXFIFO_UFLOW_MASK,
    /**< Fifo underflow interrupt for graphics pipeline. */
    DSS_DISPC_INTR_MASK_GFX_END_WINDOW = DISPC_IRQEN_GFXEND_WINDOW_MASK,
    /**< Graphics pipeline end of window interrupt. */
    DSS_DISPC_INTR_MASK_PALETTE_LOADING =
        DISPC_IRQEN_PALLETE_GAMMA_LOADING_MASK,
    /**< Palette/Gamma table Loaded interrupt. */
    DSS_DISPC_INTR_MASK_OCP_ERROR = DISPC_IRQEN_OCP_ERROR_MASK,
    /**< OCP error interrupt. */
    DSS_DISPC_INTR_MASK_VID1_UNDER_FLOW = DISPC_IRQEN_VID1_FIFO_UFLOW_MASK,
    /**< Fifo underflow interrupt for video1 pipeline. */
    DSS_DISPC_INTR_MASK_VID1_END_WINDOW = DISPC_IRQEN_VID1_END_WINDOW_MASK,
    /**< Video1 pipeline end of window interrupt. */
    DSS_DISPC_INTR_MASK_VID2_UNDER_FLOW = DISPC_IRQEN_VID2_FIFO_UFLOW_MASK,
    /**< Fifo underflow interrupt for video2 pipeline. */
    DSS_DISPC_INTR_MASK_VID2_END_WINDOW = DISPC_IRQEN_VID2_END_WINDOW_MASK,
    /**< Video2 pipeline end of window interrupt. */
    DSS_DISPC_INTR_MASK_SYNC_LOST_LCD = DISPC_IRQEN_SYNC_LOST_MASK,
    /**< Sync lost Interrupt for LCD output. */
    DSS_DISPC_INTR_MASK_SYNC_LOST_DIGITAL = DISPC_IRQEN_SYNC_LOST_DIGITAL_MASK,
    /**< Sync lost interrupt for digital output. */
    DSS_DISPC_INTR_MASK_WAKEUP = DISPC_IRQEN_WAKEUP_MASK,
    /**< Wake up Interrupt. */
    DSS_DISPC_INTR_MASK_ALL    = (DISPC_IRQEN_FRM_DONE_MASK | \
        DISPC_IRQEN_VSYNC_MASK | DISPC_IRQEN_EVSYNC_EVEN_MASK | \
        DISPC_IRQEN_EVSYNC_ODD_MASK | DISPC_IRQEN_ACBIAS_COUNT_STS_MASK | \
        DISPC_IRQEN_PGM_LINE_NO_MASK | DISPC_IRQEN_GFXFIFO_UFLOW_MASK | \
        DISPC_IRQEN_GFXEND_WINDOW_MASK | \
        DISPC_IRQEN_PALLETE_GAMMA_LOADING_MASK | DISPC_IRQEN_OCP_ERROR_MASK | \
        DISPC_IRQEN_VID1_FIFO_UFLOW_MASK | DISPC_IRQEN_VID1_END_WINDOW_MASK | \
        DISPC_IRQEN_VID2_FIFO_UFLOW_MASK | DISPC_IRQEN_VID2_END_WINDOW_MASK | \
        DISPC_IRQEN_SYNC_LOST_MASK | DISPC_IRQEN_SYNC_LOST_DIGITAL_MASK | \
        DISPC_IRQEN_WAKEUP_MASK)
    /**< Interrupt mask to enable/disable for all the display controller's
         interrupts. */
}dssDispcIntrMask_t;


/** \brief Enumerates the Ids of hardware frame buffers of both graphics and
           video pipelines. */
typedef enum dssDispcFrmBufId
{
    DSS_DISPC_FRM_BUF_ID_MIN = 0U,
    /**< Minimum value of enumeration. Used for input validation. */
    DSS_DISPC_FRM_BUF_ID_0   = DSS_DISPC_FRM_BUF_ID_MIN,
    /**< Pipeline hardware frame buffer 0. */
    DSS_DISPC_FRM_BUF_ID_1   = 1U,
    /**< Pipeline hardware frame buffer 1. */
    DSS_DISPC_FRM_BUF_ID_MAX = DSS_DISPC_FRM_BUF_ID_1,
    /**< Maximum value of enumeration. Used for input validation. */
}dssDispcFrmBufId_t;


/** \brief Enumerates the supported values of Graphics pipeline DMA burst
           sizes. */
typedef enum dssDispcGfxDmaBurstSize
{
   DSS_DISPC_GFX_DMA_BURST_SIZE_4  = DISPC_GFX_ATTRS_BURST_SIZE_BITS4X32,
   /**< DMA burst size is 4 x 32 bytes. */
   DSS_DISPC_GFX_DMA_BURST_SIZE_8  = DISPC_GFX_ATTRS_BURST_SIZE_BITS8X32,
   /**< DMA burst size is 8 x 32 bytes. */
   DSS_DISPC_GFX_DMA_BURST_SIZE_16 = DISPC_GFX_ATTRS_BURST_SIZE_BITS16X32,
   /**< DMA burst size is 16 x 32 bytes. */
}dssDispcGfxDmaBurstSize_t;


/** \brief Enumerates the source of the graphics pipeline preload value. */
typedef enum dssDispcGfxPreloadSrc
{
    DSS_DISPC_GFX_PRELOAD_SRC_REG_VAL   = DISPC_GFX_ATTRS_FIFO_PRELOAD_VAL,
    /**< H/W pre fetches pixels up to the preload value defined in the preload
         register. */
    DSS_DISPC_GFX_PRELOAD_SRC_FIFO_HIGH =
        DISPC_GFX_ATTRS_FIFO_PRELOAD_THRESHOLD_VAL
    /**< H/W pre fetches pixels up to high threshold value. */
}dssDispcGfxPreloadSrc_t;


/** \brief Enumerates the types of color look up table. */
typedef enum dssDispcGfxLutType
{
    DSS_DISPC_GFX_LUT_TYPE_PALETTE   = DISPC_CFG_PALETTEGAMMA_TBL_LUT_PALETTE,
    /**< Look Up Table is Color Palette table. */
    DSS_DISPC_GFX_LUT_TYPE_GAMMA_TBL = DISPC_CFG_PALETTEGAMMA_TBL_LUT_GAMMA
    /**< Look Up Table is Gamma table. */
}dssDispcGfxLutType_t;


/** \brief Enumerates the supported the load modes of color look up table. */
typedef enum dssDispcGfxLutLoadMode
{
    DSS_DISPC_GFX_LUT_LOAD_MODE_TBL_DATA_PER_FRAME  =
        DISPC_CFG_LOAD_MODE_GAMMA_TBL_AND_DATA_LOADED_FOR_EVERY_FRAME,
    /**< Palette/Gamma Table and data are loaded every frame. */
    DSS_DISPC_GFX_LUT_LOAD_MODE_TBL   = DISPC_CFG_LOAD_MODE_GAMMA_TBL_LOADED,
    /**< Palette/Gamma Table to be loaded. Users set the bit when the
         palette/gamma table has to be loaded. H/W resets the bit when table
         has been loaded. */
    DSS_DISPC_GFX_LUT_LOAD_MODE_DATA_PER_FRAME =
        DISPC_CFG_LOAD_MODE_DATA_LOADED,
    /**< Frame data only loaded every frame. */
    DSS_DISPC_GFX_LUT_LOAD_MODE_TBL_ONCE =
        DISPC_CFG_LOAD_MODE_GAMMA_TBL_AND_DATA_LOADED_FOR_FIRST_FRAME
    /**< Palette/Gamma Table and frame data loaded on first frame then switch to
         load data only mode. */
}dssDispcLutLoadMode_t;


/** \brief  Enumerates the priorities of the graphics pipeline. */
typedef enum dssDispcGfxPriority
{
    DSS_DISPC_GFX_PRIORITY_NORMAL = DISPC_GFX_ATTRS_ARBITRATION_NORMAL_PRIORITY,
    /**< The graphics pipeline is one of the normal priority pipeline. */
    DSS_DISPC_GFX_PRIORITY_HIGH   = DISPC_GFX_ATTRS_ARBITRATION_HIGH_PRIORITY
    /**< The graphics pipeline is one of the high priority pipeline. */
}dssDispcGfxPriority_t;


/** \brief Enumerates the supported types of graphics pipeline frame data
           formats. */
typedef enum dssDispcGfxFmtType
{
    DSS_DISPC_GFX_FMT_TYPE_BITMAP1  = DISPC_GFX_ATTRS_FMT_BITMAP1,
    /**< Graphics frame format is Bit Map 1(CLUT). */
    DSS_DISPC_GFX_FMT_TYPE_BITMAP2  = DISPC_GFX_ATTRS_FMT_BITMAP2,
    /**< Graphics frame format is Bit Map 2(CLUT). */
    DSS_DISPC_GFX_FMT_TYPE_BITMAP4  = DISPC_GFX_ATTRS_FMT_BITMAP4,
    /**< Graphics frame format is Bit Map 4(CLUT). */
    DSS_DISPC_GFX_FMT_TYPE_BITMAP8  = DISPC_GFX_ATTRS_FMT_BITMAP8,
    /**< Graphics frame format is Bit Map 8(CLUT). */
    DSS_DISPC_GFX_FMT_TYPE_RGB12  = DISPC_GFX_ATTRS_FMT_RGB12,
    /**< Graphics frame format is RGB12(unpacked in 16-bit container). */
    DSS_DISPC_GFX_FMT_TYPE_ARGB16  = DISPC_GFX_ATTRS_FMT_ARGB16,
    /**< Graphics frame format is ARGB16. */
    DSS_DISPC_GFX_FMT_TYPE_RGB16  = DISPC_GFX_ATTRS_FMT_RGB16,
    /**< Graphics frame format is RGB16. */
    DSS_DISPC_GFX_FMT_TYPE_RGB24_UNPACKED  = DISPC_GFX_ATTRS_FMT_RGB24_UNPACKED,
    /**< Graphics frame format is RGB24 unpacked (unpacked in 32-bit container).
         */
    DSS_DISPC_GFX_FMT_TYPE_RGB24_PACKED  = DISPC_GFX_ATTRS_FMT_RGB24_PACKED,
    /**< Graphics frame format is RGB24 packed. */
    DSS_DISPC_GFX_FMT_TYPE_ARGB32  = DISPC_GFX_ATTRS_FMT_ARGB32,
    /**< Graphics frame format is ARGB32. */
    DSS_DISPC_GFX_FMT_TYPE_RGBA32  = DISPC_GFX_ATTRS_FMT_RGBA32,
    /**< Graphics frame format is RGBA32. */
    DSS_DISPC_GFX_FMT_TYPE_RGBX32  = DISPC_GFX_ATTRS_FMT_RGBX32,
    /**< Graphics frame format is RGBX32. 24-bit RGB aligned on MSB of the
         32-bit container*/
}dssDispcGfxFmtType_t;


/** \brief Enumerates the supported endianness of graphics pipeline data. */
typedef enum dssDispcGfxEndian
{
    DSS_DISPC_GFX_ENDIAN_LITTLE = DISPC_GFX_ATTRS_ENDIAN_LITTLE,
    /**< Graphics pipeline data is little endian type. */
    DSS_DISPC_GFX_ENDIAN_BIG    = DISPC_GFX_ATTRS_ENDIAN_BIG
    /**< Graphics pipeline data is big endian type. */
}dssDispcGfxEndian_t;


/** \brief Enumerates the supported number of video pipelines inside the
           display sub system. */
typedef enum dssDispcVidPipelineId
{
    DSS_DISPC_VID_PIPELINE_ID_MIN = 0U,
    /**< Minimum value of video pipeline number. Used for input validation. */
    DSS_DISPC_VID_PIPELINE_ID_1 = DSS_DISPC_VID_PIPELINE_ID_MIN,
    /**< Video 1 pipeline. */
    DSS_DISPC_VID_PIPELINE_ID_2 = 1U,
    /**< Video 2 pipeline. */
    DSS_DISPC_VID_PIPELINE_ID_MAX = DSS_DISPC_VID_PIPELINE_ID_2
    /**< Maximum value of enumeration. Used for input validation. */
}dssDispcVidPipelineId_t;


/** \brief Enumerates the supported values of Video pipeline DMA burst
           sizes. */
typedef enum dssDispcVidDmaBurstSize
{
   DSS_DISPC_VID_DMA_BURST_SIZE_4  = DISPC_VID_ATTRS_BURST_SIZE_BITS4X32,
   /**< DMA burst size is 4 x 32 bytes. */
   DSS_DISPC_VID_DMA_BURST_SIZE_8  = DISPC_VID_ATTRS_BURST_SIZE_BITS8X32,
   /**< DMA burst size is 8 x 32 bytes. */
   DSS_DISPC_VID_DMA_BURST_SIZE_16 = DISPC_VID_ATTRS_BURST_SIZE_BITS16X32,
   /**< DMA burst size is 16 x 32 bytes. */
}dssDispcVidDmaBurstSize_t;


/** \brief Enumerates the source of the video pipeline preload value. */
typedef enum dssDispcVidPreloadSrc
{
    DSS_DISPC_VID_PRELOAD_SRC_REG_VAL   = DISPC_VID_ATTRS_FIFO_PRELOAD_VAL,
    /**< H/W pre fetches pixels up to the preload value defined in the preload
         register. */
    DSS_DISPC_VID_PRELOAD_SRC_FIFO_HIGH =
        DISPC_VID_ATTRS_FIFO_PRELOAD_THRESHOLD_VAL
    /**< H/W pre fetches pixels up to high threshold value. */
}dssDispcVidPreloadSrc_t;


/** \brief  Enumerates the priorities of the video pipeline. */
typedef enum dssDispcVidPriority
{
    DSS_DISPC_VID_PRIORITY_NORMAL = DISPC_VID_ATTRS_ARBITRATION_NORMAL_PRIORITY,
    /**< The Video pipeline is one of the normal priority pipeline. */
    DSS_DISPC_VID_PRIORITY_HIGH   = DISPC_VID_ATTRS_ARBITRATION_HIGH_PRIORITY
    /**< The Video pipeline is one of the high priority pipeline. */
}dssDispcVidPriority_t;


/** \brief  Enumerates the input data formats supported by video pipeline. */
typedef enum dssDispcVidFmtType
{
    DSS_DISPC_VID_FMT_TYPE_RGB12 = DISPC_VID_ATTRS_FMT_RGB12,
    /**< Video frame format is RGB12(unpacked in 16-bit container). */
    DSS_DISPC_VID_FMT_TYPE_ARGB16 = DISPC_VID_ATTRS_FMT_ARGB16,
    /**< Video frame format is ARGB16. */
    DSS_DISPC_VID_FMT_TYPE_RGB16 = DISPC_VID_ATTRS_FMT_RGB16,
    /**< Video frame format is RGB16. */
    DSS_DISPC_VID_FMT_TYPE_RGB24_UNPACKED = DISPC_VID_ATTRS_FMT_RGB24_UNPACKED,
    /**< Video frame format is RGB24 unpacked (unpacked in 32-bit container). */
    DSS_DISPC_VID_FMT_TYPE_RGB24_PACKED = DISPC_VID_ATTRS_FMT_RGB24_PACKED,
    /**< Video frame format is RGB24 packed. */
    DSS_DISPC_VID_FMT_TYPE_YUV2 = DISPC_VID_ATTRS_FMT_YUV2_422,
    /**< Video frame format is YUV2 422 . */
    DSS_DISPC_VID_FMT_TYPE_UYVY = DISPC_VID_ATTRS_FMT_YUVY_422,
    /**< Video frame format is UYVY 422. */
    DSS_DISPC_VID_FMT_TYPE_ARGB32 = DISPC_VID_ATTRS_FMT_ARGB32,
    /**< Video frame format is ARGB32. */
    DSS_DISPC_VID_FMT_TYPE_RGBA32 = DISPC_VID_ATTRS_FMT_RGBA32,
    /**< Video frame format is RGBA32. */
    DSS_DISPC_VID_FMT_TYPE_RGBX32 = DISPC_VID_ATTRS_FMT_RGBX32,
    /**< Video frame format is RGBX32(24-bit RGB aligned on MSB of the 32-bit
         container). */
}dssDispcVidFmtType_t;


/** \brief Enumerates the supported endianness of graphics pipeline data. */
typedef enum dssDispcVidEndian
{
    DSS_DISPC_VID_ENDIAN_LITTLE = DISPC_VID_ATTRS_ENDIAN_LITTLE,
    /**< Video pipeline data is little endian type. */
    DSS_DISPC_VID_ENDIAN_BIG    = DISPC_VID_ATTRS_ENDIAN_BIG
    /**< Video pipeline data is big endian type. */
}dssDispcVidEndian_t;


/** \brief Enumerates the supported types of video resize processing that needs
           to be enabled for the required use case. */
typedef enum dssDispcVidResizeType
{
    DSS_DISPC_VID_RESIZE_TYPE_HORZ       = DISPC_VID_ATTRS_RESIZE_EN_ENABLE_HOR,
    /**< Enable Horizontal resize processing. */
    DSS_DISPC_VID_RESIZE_TYPE_VERT       = DISPC_VID_ATTRS_RESIZE_EN_ENABLE_VER,
    /**< Enable Vertical resize processing.*/
    DSS_DISPC_VID_RESIZE_TYPE_HORZ_VERT  = DISPC_VID_ATTRS_RESIZE_EN_ENABLE_BOTH
    /**< Enable both Horizontal and Vertical Resizing. */
}dssDispcVidResizeType_t;


/** \brief Enumerates the number of filter taps required for the vertical resize
           processing. */
typedef enum dssDispcVidVertResizeFilterTaps
{
    DSS_DISPC_VID_VERT_RESIZE_FILTER_TAPS_3 =
        DISPC_VID_ATTRS_VERTICAL_TAPS_THREE,
    /**< Number of Vertical filter taps are three. */
    DSS_DISPC_VID_VERT_RESIZE_FILTER_TAPS_5 =
        DISPC_VID_ATTRS_VERTICAL_TAPS_FIVE
    /**< Number of Vertical filter taps are five. */
}dssDispcVidVertResizeFilterTaps_t;


/** \brief Enumerates the type of horizontal resizing. */
typedef enum dssDispcVidHorzResizeType
{
    DSS_DISPC_VID_HORZ_RESIZE_TYPE_UP   =
        DISPC_VID_ATTRS_HRESIZE_CONF_UPSAMPLING,
    /**< Enable Horizontal up sampling. */
    DSS_DISPC_VID_HORZ_RESIZE_TYPE_DOWN =
        DISPC_VID_ATTRS_HRESIZE_CONF_DOWNSAMPLING
    /**< Enable Horizontal down sampling. */
}dssDispcVidHorzResizeType_t;


/** \brief Enumerates the type of Vertical resizing. */
typedef enum dssDispcVidVertResizeType
{
    DSS_DISPC_VID_VERT_RESIZE_TYPE_UP   =
        DISPC_VID_ATTRS_VRESIZE_CONF_UPSAMPLING,
    /**< Enable Vertical up sampling. */
    DSS_DISPC_VID_VERT_RESIZE_TYPE_DOWN =
        DISPC_VID_ATTRS_VRESIZE_CONF_DOWNSAMPLING
    /**< Enable Vertical down sampling. */
}dssDispcVidVertResizeType_t;


/** \brief Supported Matrix types of LCD. */
typedef enum dssDispcLcdMatrixType
{
    DSS_DISPC_LCD_MATRIX_TYPE_PASSIVE = DISPC_CTRL_STNTFT_PASSIVE_MATRIX,
    /**< Passive matrix display. */
    DSS_DISPC_LCD_MATRIX_TYPE_ACTIVE  = DISPC_CTRL_STNTFT_ACTIVE_MATRIX,
    /**< Active matrix display. */
}dssDispcLcdMatrixType_t;


/** \brief Display type color or monochrome. */
typedef enum dssDispcLcdDispType
{
    DSS_DISPC_LCD_DISP_TYPE_COLOR = DISPC_CTRL_MONO_COLOR_EN,
    /**< Color display. */
    DSS_DISPC_LCD_DISP_TYPE_MONO  = DISPC_CTRL_MONO_COLOR_MONOCHROME_EN
    /**< Monochrome display. */
}dssDispcLcdDispType_t;


/** \brief LCD output data lines. */
typedef enum dssDispcLcdDataLines
{
    DSS_DISPC_LCD_DATA_LINES_12 = DISPC_CTRL_TFT_DATA_LINES_BIT_12,
    /**< 12 BIT LCD data Lines. */
    DSS_DISPC_LCD_DATA_LINES_16 = DISPC_CTRL_TFT_DATA_LINES_BIT_16,
    /**< 16 BIT LCD data Lines. */
    DSS_DISPC_LCD_DATA_LINES_18 = DISPC_CTRL_TFT_DATA_LINES_BIT_18,
    /**< 18 BIT LCD data Lines. */
    DSS_DISPC_LCD_DATA_LINES_24 = DISPC_CTRL_TFT_DATA_LINES_BIT_24,
    /**< 24 BIT LCD data Lines. */
}dssDispcLcdDataLines_t;


/** \brief Monochromatic LCD bit width. */
typedef enum dssDispcLcdMonoType
{
    DSS_DISPC_LCD_MONO_TYPE_4_BIT = DISPC_CTRL_M8B_PIX_3_0,
    /**< 4 BIT monochromatic display. */
    DSS_DISPC_LCD_MONO_TYPE_8_BIT = DISPC_CTRL_M8B_PIX_7_0,
    /**< 8 BIT monochromatic display. */
}dssDispcLcdMonoType_t;


/** \brief  Polarities of horizontal synchronization signal. */
typedef enum dssDispcLcdHSyncPol
{
    DSS_DISPC_LCD_H_SYNC_POL_HIGH = DISPC_POL_FREQ_IHS_ACTIVE_HIGH,
    /**< Polarity is active high. */
    DSS_DISPC_LCD_H_SYNC_POL_LOW = DISPC_POL_FREQ_IHS_ACTIVE_LOW
    /**< Polarity is active low. */
}dssDispcLcdHSyncPol_t;


/** \brief  Polarities of vertical synchronization signal. */
typedef enum dssDispcLcdVSyncPol
{
    DSS_DISPC_LCD_V_SYNC_POL_HIGH = DISPC_POL_FREQ_IVS_ACTIVE_HIGH,
    /**< Polarity is active high. */
    DSS_DISPC_LCD_V_SYNC_POL_LOW = DISPC_POL_FREQ_IVS_ACTIVE_LOW
    /**< Polarity is active low. */
}dssDispcLcdVSyncPol_t;


/** \brief Polarities of the Output enable signal. */
typedef enum dssDispcLcdOutputEnablePol
{
    DSS_DISPC_LCD_OUTPUT_ENABLE_POL_HIGH = DISPC_POL_FREQ_IEO_ACTIVE_HIGH,
    /**< Polarity is active high. */
    DSS_DISPC_LCD_OUTPUT_ENABLE_POL_LOW  = DISPC_POL_FREQ_IEO_ACTIVE_LOW,
    /**< Polarity is active low. */
}dssDispcLcdOutputEnablePol_t;


/** \brief Active polarities of the pixel clock. */
typedef enum dssDispcLcdPclkPol
{
    DSS_DISPC_LCD_PCLK_POL_RISING_EDGE = DISPC_POL_FREQ_IPC_RISING_EDGE,
    /**< Data is driven on the LCD data lines on the rising-edge of the
         pixel clock. */
    DSS_DISPC_LCD_PCLK_POL_FALLING_EDGE = DISPC_POL_FREQ_IPC_FALLING_EDGE,
    /**< Data is driven on the LCD data lines on the falling-edge of the
         pixel clock. */
}dssDispcLcdPclkPol_t;


/** \brief Active edges of H or v sync signals. */
typedef enum dssDispcLcdActiveSyncEdge
{
    DSS_DISPC_LCD_ACTIVE_SYNC_EDGE_FALLING = DISPC_POL_FREQ_RF_FALLING_EDGE,
    /**< HSYNC and VSYNC are driven on falling edge of pixel clock. */
    DSS_DISPC_LCD_ACTIVE_SYNC_EDGE_RISING = DISPC_POL_FREQ_RF_RISING_EDGE,
    /**< HSYNC and VSYNC are driven on the rising edge of pixel clock. */
}dssDispcLcdActiveSyncEdge_t;


/** \brief HSYNC/VSYNC Pixel clock control on/off. */
typedef enum dssDispcLcdSyncCtrl
{
    DSS_DISPC_LCD_SYNC_PCLK_CTRL_ON  = DISPC_POL_FREQ_ONOFF_OPP_EDGES,
    /**< HSYNC and VSYNC are driven on opposite edges of pixel clock
         than pixel data. */
    DSS_DISPC_LCD_SYNC_PCLK_CTRL_OFF = DISPC_POL_FREQ_ONOFF_ASPER_BIT_16
    /**< HSYNC and VSYNC are driven according to sync edge configuration. */
}dssDispcLcdSyncCtrl_t;


/** \brief LCD enable signal enable control. */
typedef enum dssDispcLcdEnSigCtrl
{
    DSS_DISPC_LCD_EN_SIG_CTRL_DISABLE = DISPC_CTRL_LCD_EN_SIGNAL_DISABLED,
    /**< LCD Enable signal is disabled. */
    DSS_DISPC_LCD_EN_SIG_CTRL_ENABLE = DISPC_CTRL_LCD_EN_SIGNAL_ENABLED,
    /**< LCD Enable signal is enabled. */
}dssDispcLcdEnSigCtrl_t;


/** \brief Polarities of the lcd enable signal. */
typedef enum dssDispcLcdEnSigPol
{
    DSS_DISPC_LCD_EN_SIG_POL_LOW = DISPC_CTRL_LCD_EN_POL_ACTIVE_LOW,
    /**< LCD enable signal polarity is active low. */
    DSS_DISPC_LCD_EN_SIG_POL_HIGH = DISPC_CTRL_LCD_EN_POL_ACTIVE_HIGH,
    /**< LCD enable signal polarity is active high. */
}dssDispcLcdEnSigPol_t;


/** \brief Types of Spatial temporal dithering techniques. */
typedef enum dssDispcStDitherType
{
    DSS_DISPC_ST_DITHER_TYPE_SP_ONLY = DISPC_CTRL_SPATIAL_TEMPORAL_DITHER_ONLY,
    /**< Enable Spatial Dithering only. */
    DSS_DISPC_ST_DITHER_TYPE_SP_TMP_2_FRMS =
        DISPC_CTRL_SPATIAL_TEMPORAL_DITHER_AND_OVR_2_FRAMES,
    /**< Enable Spatial and Temporal dithering over 2 frames. */
    DSS_DISPC_ST_DITHER_TYPE_SP_TMP_4_FRMS =
        DISPC_CTRL_SPATIAL_TEMPORAL_DITHER_AND_OVR_4_FRAMES,
    /**< Enable Spatial and Temporal dithering over 4 frames. */
}dssDispcStDitherType_t;


/** \brief Types of transparency color keys. */
typedef enum dssDispcOvlyTckType
{
    DSS_DISPC_OVLY_TCK_TYPE_GRAPHICS =
        DISPC_CFG_TCK_LCD_SELECTION_GRAPHICS_DEST,
    /**< Graphics destination transparency color key selected in normal mode or
         graphics source transparency color key selected in alpha mode. */
    DSS_DISPC_OVLY_TCK_TYPE_VIDEO =
        DISPC_CFG_TCK_LCD_SELECTION_VIDEO_SOURCE,
    /**< Video source transparency color key selected in normal mode. */
}dssDispcOvlyTckType_t;


/** \brief Types of display controller pipelines. */
typedef enum dssDispcPipelineType
{
    DSS_DISPC_PIPELINE_TYPE_MIN = 0U,
    /**< Minimum value of enumeration. Used for input validation. */
    DSS_DISPC_PIPELINE_TYPE_GRAPHICS = DSS_DISPC_PIPELINE_TYPE_MIN,
    /**< Graphics pipeline. */
    DSS_DISPC_PIPELINE_TYPE_VIDEO1 = 1U,
    /**< Video1 pipeline. */
    DSS_DISPC_PIPELINE_TYPE_VIDEO2 = 2U,
    /**< video2 pipeline. */
    DSS_DISPC_PIPELINE_TYPE_MAX = DSS_DISPC_PIPELINE_TYPE_VIDEO2,
    /**< Maximum value of enumeration. Used for input validation. */
}dssDispcPipelineType_t;


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure defining the pipeline DMA configuration parameters. */
typedef struct dssDispcDmaCfg
{
    uint32_t burstSize;
    /**< DMA Burst Size. This can take following enum values
         #dssDispcGfxDmaBurstSize_t. */
    uint32_t fifoLoThr;
    /**< FIFO Low Threshold value in bytes. */
    uint32_t fifoHiThr;
    /**< FIFO High Threshold value in bytes. */
    uint32_t pixelInc;
    /**< Number of bytes to increment between two pixels. */
    uint32_t rowInc;
    /**< Number of bytes to increment at the end of row. */
    uint32_t preloadSelect;
    /**< Flag selecting the source of preload value: preload register/
         FIFO High Threshold. This can take one of the following enum
         values #dssDispcGfxPreloadSrc_t. */
}dssDispcDmaCfg_t;


/** \brief Structure defining the Colour Space Conversion coefficients. */
typedef struct dssDispcCscCoeff
{
    int32_t ry;
    /**< RY: Red Luminance Y. */
    int32_t rcr;
    /**< RCR: Red Chrominance sample Cr. */
    int32_t rcb;
    /**< RCB: Red Chrominance sample Cb. */
    int32_t gy;
    /**< GY: Green Luminance Y. */
    int32_t gcr;
    /**< GCR: Green Chrominance sample Cr. */
    int32_t gcb;
    /**< GCB: Green Chrominace sample Cr. */
    int32_t by;
    /**< BY: Blue Luminance Y. */
    int32_t bcr;
    /**< BCR: Blue Chrominance sample Cr. */
    int32_t bcb;
    /**< BCB: Blue Chrominance sample Cb. */
    int32_t vidFullRng;
    /**< This value indicates the preprocessing on Y component before
         colour space conversion. This controls whether Limited/Full range of Y
         is used for Color Space Conversion. */
}dssDispcCscCoeff_t;


/** \brief Structure defining the Video pipeline format parameters. */
typedef struct dssVidFmtCfg
{
    uint32_t format;
    /**< Input image data format. This can take values from the following
         enum #dssDispcVidFmtType_t. */
    uint32_t endian;
    /**< Flag indicating the endian of input image data. This can take values
         from the following enum #dssDispcVidEndian_t. */
    uint32_t enableCsc;
    /**< User Control flag to enable Color Space Conversion. This can take
         following two macros:
         TRUE  - enable color space conversion
         FALSE - disable color space conversion. */
    dssDispcCscCoeff_t *pCscCoeff;
    /**< Pointer to the array containing the Color Space Conversion
         coefficients */
    uint32_t enableExtender;
    /**< User Control flag to enable extender module. This can take following
         two macros: TRUE - Enable extender processing  FALSE - Disable
         extender processing. */
}dssVidFmtCfg_t;


/** \brief Structure defining the video window parameters like size and position
           of video window on the overlay. */
typedef struct dssDispcVidWindowCfg
{
    uint32_t inputWidth;
    /**< Input image width in number of pixels per line.*/
    uint32_t inputHeight;
    /**< Input image height in number of lines per image. */
    uint32_t outputWidth;
    /**< Output width of video window in number of pixels per line.*/
    uint32_t outputHeight;
    /**< Output height of the video window in number of lines per image. */
    uint32_t enableResizing;
    /**< User control flag to enable/disable resizing feature. This can accept
         following values: TRUE or FALSE. */
    uint32_t xPos;
    /**< X position of the video window in the overlay. */
    uint32_t yPos;
    /**< Y position of the video window in the overlay. */
}dssDispcVidWindowCfg_t;


/** \brief Structure defining the Horizontal resizing coefficients. */
typedef struct dssDispcHorzResizeCoeff
{
    int32_t hc4;
    /**< HC4*/
    int32_t hc3;
    /**< HC3*/
    uint32_t hc2;
    /**< HC2*/
    int32_t hc1;
    /**< HC1*/
    int32_t hc0;
    /**< HC0*/
}dssDispcHorzResizeCoeff_t;


/** \brief Structure defining the Vertical resizing coefficients. */
typedef struct dssDispcVertResizeCoeff
{
    int32_t vc22;
    /**< VC22*/
    int32_t vc2;
    /**< VC2*/
    uint32_t vc1;
    /**< VC1*/
    int32_t vc0;
    /**< VC0*/
    int32_t vc00;
    /**< VC00*/
}dssDispcVertResizeCoeff_t;


/** \brief Structure defining the LCD display attributes .*/
typedef struct dssDispcLcdAttrCfg
{
    uint32_t displayType;
    /**< Display matrix type. This can take values from the following
         enum  #dssDispcLcdMatrixType_t. */
    uint32_t monoColor;
    /**< LCD display color or monochromatic type. This can take values from the
         following enum #dssDispcLcdDispType_t. */
    uint32_t lcdDataLines;
    /**< Number of LCD Output Data lines. This can take values from the
         following enum #dssDispcLcdDataLines_t. */
    uint32_t mono8Bit;
    /**< Flag indicating Mono 4bit or 8bit interface. This can take values
         from the following enum #dssDispcLcdMonoType_t. */
}dssDispcLcdAttrCfg_t;


/** \brief Structure defining the LCD Panel parameters. */
typedef struct dssDispcLcdTimingCfg
{
  uint32_t ppl;
  /**< Number of Pixels Per Line. This can take values in the following
       range: #DSS_DISPC_LCD_PPL_MIN   to  #DSS_DISPC_LCD_PPL_MAX. */
  uint32_t hfp;
  /**< Horizontal Front Porch. This can take values in the following
       range: #DSS_DISPC_LCD_HFP_MIN   to  #DSS_DISPC_LCD_HFP_MAX. */
  uint32_t hbp;
  /**< Horizontal Back Porch. This can take values in the following
       range: #DSS_DISPC_LCD_HBP_MIN  to  #DSS_DISPC_LCD_HBP_MAX .*/
  uint32_t hsw;
  /**< Horizontal Sync Width. This can take values in the following
       range: #DSS_DISPC_LCD_HSW_MIN  to  #DSS_DISPC_LCD_HSW_MAX .*/
  uint32_t lpp;
  /**< Number of Lines Per Panel. This can take values in the following
       range: #DSS_DISPC_LCD_LPP_MIN  to  #DSS_DISPC_LCD_LPP_MAX .*/
  uint32_t vfp;
  /**< Vertical Front Porch. This can take values in the following
       range: #DSS_DISPC_LCD_VFP_MIN  to  #DSS_DISPC_LCD_VFP_MAX .*/
  uint32_t vbp;
  /**< Vertical Back Porch. This can take values in the following
       range: #DSS_DISPC_LCD_VBP_MIN  to  #DSS_DISPC_LCD_VBP_MAX .*/
  uint32_t vsw;
  /**< Vertical Sync Width. This can take values in the following
       range: #DSS_DISPC_LCD_VSW_MIN  to  #DSS_DISPC_LCD_VSW_MAX .*/
  uint32_t pixelClk;
  /**< Value of LCD pixel clock. */
}dssDispcLcdTimingCfg_t;


/** \brief Structure holding the LCD signal polarity and edge configuration
           parameters. */
typedef struct dssDispcLcdPolarityCfg
{
    uint32_t hSyncPolarity;
    /**< Polarity of Horizontal Sync. This can take values from the following
        enum #dssDispcLcdHSyncPol_t. */
    uint32_t vSyncPolarity;
    /**< Polarity of Vertical Sync. This can take values from the following
        enum #dssDispcLcdVSyncPol_t. */
    uint32_t outputEnablePolarity;
    /**< Polarity of Output Enable Signal. This can take values from the
         following enum #dssDispcLcdOutputEnablePol_t. */
    uint32_t pixelClkPolarity;
    /**< Polarity of Pixel clock. This can take values from the following
        enum #dssDispcLcdPclkPol_t. */
    uint32_t syncEdge;
    /**< Active edge of Horizontal/Vertical Sync. This can take values from the
        following enum #dssDispcLcdActiveSyncEdge_t. */
    uint32_t sycnEdgeCtrl;
    /**< Control of Horizontal/Vertical Sync by pixel clock. This can take
         values from the following enum #dssDispcLcdSyncCtrl_t. */
}dssDispcLcdPolarityCfg_t;


/** \brief Structure holding the ac bias configuration parameters. */
typedef struct dssDispcLcdAcbCfg
{
    uint32_t acbFreq;
    /**<  Number of line clocks to count before transitioning the
          ac-bias pin. */
    uint32_t acbi;
    /**<  Number of ac-bias transitions per interrupt. */
}dssDispcLcdAcbCfg_t;


/** \brief Structure holding the LCD control signals (Synchronization and
           pixel clock) gating control parameters. */
typedef struct dssDispcLcdGatedCtrl
{
    uint32_t hSyncGated;
    /**< Control of Horizontal Sync gating. This can take following values
         TRUE or FALSE. */
    uint32_t vSyncGated;
    /**< Control of Vertical Sync gating. This can take following values
         TRUE or FALSE. */
    uint32_t acbGated;
    /**< Control of acb gating. This can take following values
         TRUE or FALSE. */
    uint32_t pixelClkGated;
    /**< Control of Pixel clock gating. This can take following values
         TRUE or FALSE. */
}dssDispcLcdGatedCtrl_t;


/** \brief Structure defining the DSS Context. */
typedef struct dssContext
{
    uint32_t dssSysConfig;
    /**< DSS System Configuration Register Value. */
    uint32_t dispcSysConfig;
    /**< DISPC System Configuration Register Value. */
    uint32_t irqEnable;
    /**< Interrupt Enable Register Value. */
    uint32_t control;
    /**< DISPC Control Register Value. */
    uint32_t config;
    /**< DISPC Configuration Register Value. */
    uint32_t defaultColor0;
    /**< LCD Background color Register Value. */
    uint32_t transColor0;
    /**< Transparency Color Key Register Value. */
    uint32_t lineNumber;
    /**< Programmable Line number Register Value. */
    uint32_t timingH;
    /**< LCD Horizontal Timings Register Value. */
    uint32_t timingV;
    /**< LCD Vertical Timings Register Value. */
    uint32_t polFreq;
    /**< LCD SYNC Polarities Register Value. */
    uint32_t divisor;
    /**< Pixel clock divisor Register Value. */
    uint32_t globalAlpha;
    /**< Global Alpha Blending Register Value. */
    uint32_t sizeLcd;
    /**< LCD Size Register Value. */

    /* Graphics pipeline */
    uint32_t gfxBA0;
    /**< Graphics pipeline Base Address Register Value. */
    uint32_t gfxPos;
    /**< Graphics window position Register Value. */
    uint32_t gfxSize;
    /**< Graphics window size Register Value. */
    uint32_t gfxAttr;
    /**< Graphics pipeline attributes Register Value. */
    uint32_t gfxFifoThr;
    /**< FIFO Threshold Register Value. */
    uint32_t gfxRowInc;
    /**< Graphics Row Increment Register Value. */
    uint32_t gfxPixInc;
    /**< Graphics Pixel Increment Register Value. */
    uint32_t gfxWindowSkip;
    /**< Graphics Overlay Optimization Window skip Register Value. */
    uint32_t gfxTableBA;
    /**< Palette/Gamma Table Base Address Register Value. */

    /* Video1 and Video2 pipelines */
    uint32_t vidBA0[DSS_NUM_VID_PIPELINES ];
    /**< Video pipeline Base Address Register Values. */
    uint32_t vidPos[DSS_NUM_VID_PIPELINES ];
    /**< Video pipeline window position Register Values. */
    uint32_t vidSize[DSS_NUM_VID_PIPELINES ];
    /**< Video window size Register Values. */
    uint32_t vidAttr[DSS_NUM_VID_PIPELINES ];
    /**< Video pipeline attributes Register Values. */
    uint32_t vidFifoThr[DSS_NUM_VID_PIPELINES ];
    /**< Video pipeline FIFO Threshold Register Values. */
    uint32_t vidPixInc[DSS_NUM_VID_PIPELINES ];
    /**< Video pipeline Pixel Increment Register Values.*/
    uint32_t vidRowInc[DSS_NUM_VID_PIPELINES ];
    /**< Video pipeline Row Increment Register Values.*/
    uint32_t vidFIR[DSS_NUM_VID_PIPELINES ];
    /**< Video pipeline Resizer increment register values. */
    uint32_t vidPictureSize[DSS_NUM_VID_PIPELINES ];
    /**< Video input image size Register Values. */
    uint32_t vidAccu[DSS_NUM_VID_PIPELINES ];
    /**< Video Accumulator Register Values. */
    uint32_t vidFIRCoeffH[DSS_NUM_VID_PIPELINES ][DSS_RESIZER_NUM_PHASES];
    /**< Horizontal Resizing Coefficient Register Values. */
    uint32_t vidFIRCoeffHV[DSS_NUM_VID_PIPELINES ][DSS_RESIZER_NUM_PHASES];
    /**< Horizontal/Vertical Resizing Coefficient Register Values. */
    uint32_t vidFIRCoeffV[DSS_NUM_VID_PIPELINES ][DSS_RESIZER_NUM_PHASES];
    /**< Vertical Resizing Coefficient Register Values. */
    uint32_t vidConvCoeff0[DSS_NUM_VID_PIPELINES ];
    /**< CSC Coefficient Register 0 Values. */
    uint32_t vidConvCoeff1[DSS_NUM_VID_PIPELINES ];
    /**< CSC Coefficient Register 1 Values. */
    uint32_t vidConvCoeff2[DSS_NUM_VID_PIPELINES ];
    /**< CSC Coefficient Register 2 Values. */
    uint32_t vidConvCoeff3[DSS_NUM_VID_PIPELINES ];
    /**< CSC Coefficient Register 3 Values. */
    uint32_t vidConvCoeff4[DSS_NUM_VID_PIPELINES ];
    /**< CSC Coefficient Register 4 Values. */
}dssContext_t;


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/** \brief Color space conversion default coefficient values. */
extern const dssDispcCscCoeff_t CSCCOEFF_DEFAULT;


/** \brief Default values of Horizontal up sampling coefficients of
           video resizer. */
extern const dssDispcHorzResizeCoeff_t
    HORZUPSAMPLECOEFF_DEFAULT[DSS_RESIZER_NUM_PHASES];


/** \brief Default values of Vertical up sampling coefficients in 3 tap
           configuration of video resizer. */
extern const dssDispcVertResizeCoeff_t
    VERTUPSAMPLE3TAPCOEFF_DEFAULT[DSS_RESIZER_NUM_PHASES];


/** \brief Default values of Vertical up sampling coefficients in 5 tap
           configuration of video resizer. */
extern const dssDispcVertResizeCoeff_t
    VERTUPSAMPLE5TAPCOEFF_DEFAULT[DSS_RESIZER_NUM_PHASES];


/** \brief Default values of Horizontal down sampling coefficients of
           video resizer. */
extern const dssDispcHorzResizeCoeff_t
    HORZDOWNSAMPLECOEFF_DEFAULT[DSS_RESIZER_NUM_PHASES];


#ifndef __cplusplus
/** \brief Default values of Vertical down sampling coefficients in 3 tap
           configuration of video resizer. */
const dssDispcVertResizeCoeff_t
    VERTDOWNSAMPLE3TAPCOEFF_DEFAULT[DSS_RESIZER_NUM_PHASES];


/** \brief Default values of Vertical down sampling coefficients in 5 tap
           configuration of video resizer. */
const dssDispcVertResizeCoeff_t
    VERTDOWNSAMPLE5TAPCOEFF_DEFAULT[DSS_RESIZER_NUM_PHASES];

#endif

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API will return the revision number of the DSS module.
 *
 * \param   baseAddr  Memory address of the Display Sub System.
 *
 * \retval  Revision  Revision number of Display Sub System. This will give the
 *                    information regarding the major and minor revisions:
 *                    - Bits[31:8] - Reserved
 *                    - Bits[7:4]  - Major revision
 *                    - Bits[3:0]  - Minor revision
 */
uint32_t DSSGetRevision(uint32_t baseAddr);


/**
 *  \brief   This API performs the module reset of DSS module. It also waits
 *           until the reset is completed.
 *
 *  \param   baseAddr    Memory address of the Display Sub System.
 */
void DSSSoftReset(uint32_t baseAddr);


/**
 * \brief   This API enables or disables the AutoIdle mechanism for
 *          display sub system.
 *
 * \param   baseAddr        Memory address of the Display Sub System.
 * \param   enableAutoIdle  Value controlling the enabling of auto idle
 *                          mechanism. This can take following values:
 *          - TRUE  - Auto idle mechanism is enabled.
 *          - FALSE - Auto idle mechanism is disabled.
 */
void DSSAutoIdleEnable(uint32_t baseAddr, uint32_t enableAutoIdle);


/**
 * \brief   This API returns the status of Display controller's interrupt.
 *          This indicates whether the interrupt is active or inactive.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 *
 * \retval  TRUE        Interrupt is active
 * \retval  FALSE       Interrupt is inactive.
 */
uint32_t DSSDispcIsIntrActive(uint32_t baseAddr);


/**
 * \brief   This API will return the IP revision of the Display controller.
 *
 * \param   baseAddr  Memory address of the Display Sub System.
 *
 * \retval  Revision  Revision number of Display controller. The return value
 *                    contains following information:
 *                    - Bits[31:8] - Reserved.
 *                    - Bits[7:4]  - Major revision.
 *                    - Bits[3:0]  - Minor revision.
 */
uint32_t DSSDispcGetRevision(uint32_t baseAddr);


/**
 * \brief   This API performs the module reset of Display controller.
 *          It also waits until the reset is completed.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 */
void DSSDispcSoftReset(uint32_t baseAddr);


/**
 * \brief   This API enables or disables the auto idle mechanism for
 *          display controller.
 *
 * \param   baseAddr        Memory address of the Display Sub System.
 * \param   enableAutoIdle  Value determining the enabling of auto idle
 *                          mechanism. This can take following values:
 *          - TRUE  - Auto idle mechanism is enabled.
 *          - FALSE - Auto idle mechanism is disabled.
 */
void DSSDispcAutoIdleEnable(uint32_t baseAddr, uint32_t enableAutoIdle);


/**
 * \brief   This API enables or disables the Wakeup feature of DISPC. This
 *          feature is useful in power modes. During sleep state, the module's
 *          clock and power will be gated. To wakeup from the sleep state, the
 *          module should identify the wake up events. This API will be called
 *          to enable the wake up events, so that sleep to normal state
 *          transition will happen.
 *
 * \param   baseAddr      Memory address of the Display Sub System.
 * \param   enableWakeup  This value determines the enabling of wakeup feature.
 *          This can take following values:
 *          - TRUE  - Wakeup feature is enabled.
 *          - FALSE - Wakeup feature is disabled.
 */
void DSSDispcWakeupEnable(uint32_t baseAddr, uint32_t enableWakeup);


/**
 * \brief   This API configures the display controller slave idle mode.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   idleMode    Idle mode of the display controller. This can take
 *          values from the following enum #dssDispcIdleMode_t.
 */
void DSSDispcSetIdleMode(uint32_t baseAddr, uint32_t idleMode);


/**
 * \brief   This API configures display controller in different standby modes
 *          based on the flag argument passed to it.
 *
 * \param   baseAddr     Memory address of the Display Sub System.
 * \param   standbyMode  Standby mode of the display controller. This can take
 *          values from the following enum #dssDispcStandbyMode_t.
 */
void DSSDispcSetStandbyMode(uint32_t baseAddr, uint32_t standbyMode);


/**
 * \brief   This API configures Clock activity during wakeup mode period.
 *
 * \param   baseAddr     Memory address of the Display Sub System.
 * \param   clkActivity  Value determining the clock activity. This can take
 *          values from the following enum #dssDispcClkActivity_t.
 */
void DSSDispcSetClkActivity(uint32_t baseAddr, uint32_t clkActivity);


/**
 * \brief   This API enables specified interrupts in display controller.
 *
 * \param   baseAddr    Memory address of the Display Sub system.
 * \param   intrMask    Mask specifying the interrupts that need to be enabled.
 *          This mask can take single value or OR of multiple values from the
 *          following enum #dssDispcIntrMask_t.
 * \note    To enable more than one interrupt, OR ing of the required interrupt
 *          masks of the enum  #dssDispcIntrMask_t is required.
 */
void DSSDispcIntrEnable(uint32_t baseAddr, uint32_t intrMask);


/**
 * \brief   This API disables specified interrupts in display controller.
 *
 * \param   baseAddr    Memory address of the Display Sub system.
 * \param   intrMask    Mask specifying the interrupts that need to be disabled.
 *          This maks can take single value or OR of multiple values from the
 *          following enum #dssDispcIntrMask_t.
 * \note    To disable more than one interrupt, OR ing of the required interrupt
 *          masks of the enum  #dssDispcIntrMask_t is required.
 */
void DSSDispcIntrDisable(uint32_t baseAddr, uint32_t intrMask);


/**
 * \brief   This API returns the  specified interrupts in display controller.
 *
 * \param   baseAddr    Memory address of the Display Sub system.
 *
 * \retval  Status      Interrupt status of the all the interrupts of the
 *                      display controller.
 * \note    To get the status of the required interrupt, the return value has to
 *          to be AND ed with the respected from the interrupt mask from the
 *          following enum #dssDispcIntrMask_t.
 */
uint32_t DSSDispcIntrStatus(uint32_t baseAddr);


/**
 * \brief   This API clears the status of the specified interrupts in
 *          display controller.
 *
 * \param   baseAddr    Memory address of the Display Sub system.
 * \param   intrMask    Mask specifying, for which interrupts the status has to
 *                      be cleared.
 *
 * \retval  Status      Interrupt status of the all the interrupts of the
 *                      display controller. This can take values from the
 *                      following enum #dssDispcIntrMask_t.
 *
 * \note    To clear status of the more than one interrupt, OR ing of the
 *          required interrupt masks of the enum  #dssDispcIntrMask_t is
 *          required.
 */
void DSSDispcIntrClear(uint32_t baseAddr, uint32_t intrMask);


/**
 * \brief   This API sets the GOLCD bit, which enables, the shadow register
 *          changes to have effect. A shadow register change has no direct
 *          effect on the configuration of the display controller unless the
 *          GOLCD bit in the DISPC_CONTROL is set for the LCD output. In the
 *          case of the LCD output, after programming the shadow registers,GOLCD
 *          bit must be set to 1. This setting indicates that all display
 *          controller shadow registers are programmed and that hardware can
 *          update the internal registers at the VFP start period.
 *
 *          The software must wait for the hardware to reset the bit before
 *          setting it.
 *
 * \param   baseAddr    Memory address of the Display Sub system.
 */
void DSSDispcShadowCfgEnable(uint32_t baseAddr);


/**
 * \brief   This API bypasses the RFBI mode and configures the parallel LCD
 *          interface in Display controller.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 */
void DSSDispcSetRfbiBypassMode(uint32_t baseAddr);


/**
 * \brief   This API configures the LCD line number that defines the line on
 *          which the programmable interrupt is generated.
 *
 * \param   baseAddr    Memory address of the Display Sub system.
 *
 * \param   lineNumber  LCD line number which generates interrupt.
 *          'lineNumber' can take values equal to or in between the following
 *          minimum and  maximum values.
 *          - #DSS_DISPC_LCD_PL_NUMBER_MIN
 *          - #DSS_DISPC_LCD_PL_NUMBER_MAX
 */
void DSSDispcSetProgLineNumber(uint32_t baseAddr, uint32_t lineNumber);


/**
 * \brief   This API returns the current LCD panel display line number.
 *          The first active line has the value 0.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 *
 * \retval  currentLineNumber Currently displayed line number on LCD. Return
 *          value can be in the range #DSS_DISPC_LCD_PL_NUMBER_MIN to
 *          #DSS_DISPC_LCD_PL_NUMBER_MAX.
 */
uint32_t DSSDispcGetDisplayLineNumber(uint32_t baseAddr);


/**
 * \brief   This API enables or disables the graphics pipeline.
 *
 * \details If enabled, graphics pipeline will be active and graphics window
 *          will present on the screen. If disabled, graphics pipeline will be
 *          inactive and graphics window will not present on the screen.
 *
 * \param   baseAddr   Memory address of the Display Sub System.
 * \param   enableGfx  Flag controlling the enable or disable of graphics
 *                     pipeline.
 *          'enableGfx' can take one of the following values
 *          - TRUE  - Graphics pipeline is enabled.
 *          - FALSE - Graphics pipeline is disabled.
 */
void DSSDispcGfxEnable(uint32_t baseAddr, uint32_t enableGfx);


/**
 * \brief   This API configures the Graphics pipeline DMA parameters.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   pCfg        Pointer to structure #dssDispcDmaCfg_t containing the
 *                      DMA configuration parameters.
 */
void DSSDispcGfxDmaConfig(uint32_t baseAddr, dssDispcDmaCfg_t *pCfg);


/**
 * \brief   This API enables or disables the DMA self refresh of the
 *          graphics window from its own FIFO only.
 * \details If enabled, the graphics pipeline does not need any more to fetch
 *          data from memory, only the graphics FIFO is used. If disabled, the
 *          graphics pipeline accesses the interconnect to fetch data from the
 *          system memory.
 *
 * \param   baseAddr            Memory address of the Display Sub System.
 *
 * \param   enableSelfRefresh   Flag controlling the enable or disable of self
 *                              refresh.
 *          'enableSelfRefresh' can take one of the following values
 *          -# TRUE  - DMA self refresh is enabled.
 *          -# FALSE - DMA self refresh is disabled.
 */
void DSSDispcGfxSelfRefreshEnable(uint32_t baseAddr,
                                  uint32_t enableSelfRefresh);


/**
 * \brief   This API configures priority of graphics pipeline.
 *
 * \details It is used to change between normal priority to high priority
 *         (value of 1) for the graphics channel vs video channels.
 *
 * \param   baseAddr  Memory address of the Display Sub System.
 * \param   priority  Value which determines the priority.
 *          'priority' can take one of values from the following enum
 *          - #dssDispcGfxPriority_t.
 */
void DSSDispcSetGfxPriority(uint32_t baseAddr, uint32_t priority);


/**
 * \brief   This API configures the format of graphics pipeline data. This API
 *          also performs the replication logic based on the format.
 *
 * \details Below are details about replication:
 *          -# If replication is enabled, and if the encoded pixel data is in
 *             RGB format RGB16/RGB12 then it can be extended to 24-bit format
 *             with replication of the MSB part to fill up the LSB due to the
 *             24-bit left alignment.
 *          -# If replication is disabled, the encoded pixel data in RGB format
 *             (RGB12/RGB16) can be extended to 24-bit by filling LSB part with
 *             0s.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   frmDataFmt  Format of the graphics pipeline data. This can take one
 *          of the value from the following enum #dssDispcGfxFmtType_t.
 *
 * \param   endian      Graphics data endianness. This can take one of the value
 *          from the following enum #dssDispcGfxEndian_t.
 *
 * \param   enableNibbleMode Control flag enabling or disabling the Graphics
 *          nibble mode(only for 1-, 2- and 4-BPP). This can take following
 *          values.
 *          -# TRUE  - Nibble mode is enabled.
 *          -# FALSE - Nibble mode is disabled.
 *
 * \param   enableExtender   User control flag to enable the replication logic.
 *          'extenderOn' can take following values
 *          -# TRUE  - enable replication logic
 *          -# FALSE - disable replication logic
 */
void DSSDispcGfxFormatConfig(uint32_t baseAddr,
                             uint32_t frmDataFmt,
                             uint32_t endian,
                             uint32_t enableNibbleMode,
                             uint32_t enableExtender);


/**
 * \brief   This API configures the palette/gamma table processing. This API
 *          also configures the load mode of the palette/gamma table and base
 *          address of the table buffer in system memory.
 *
 * \details Below is the detailed description:
 *          -# If configured in palette mode, Look up table(LUT) will be used as
 *             palette. LUT will be used as palette only if graphics format is
 *             BITMAP1, 2, 4, and 8.\n
 *          -# If configured as gamma table, color look up table will be used as
 *             gamma table. LUT will be used as gamma table only if graphics
 *             format is NOT BITMAP1, 2, 4, and 8 or no graphics window present.
 *
 * \param   baseAddr        Memory address of the Display Sub System.
 * \param   palleteGammaSel Flag determining whether the LUT will be used as
 *                          palette or as gamma table.
 *          'palleteGammaSel' can take one of the values from the following
 *          enum #dssDispcGfxLutType_t.
 *
 * \param   loadMode        Loading mode for look up table. This can take values
 *          from the following enum #dssDispcLutLoadMode_t.
 *
 * \param   tableAddr       Base address of palette table in system memory.
 *                          This buffer will contain(24-bit entries in 32-bit
 *                          containers, aligned on 32-bit boundary).
 *
 * \note    Below are few points to note about this API
 *          -# Graphics format should have been configured before calling this
 *             API.
 *          -# For bypassing the palette/gamma processing 'loadMode' should be
 *             configured to #DSS_DISPC_GFX_LUT_LOAD_MODE_DATA_PER_FRAME.
 */
void DSSDispcGfxPaletteGammaCfg(uint32_t baseAddr,
                                uint32_t palleteGammaSel,
                                uint32_t loadMode,
                                uint32_t tableAddr);


/**
 * \brief   This API configures the position of graphics window in overlay.
 *
 * \param   baseAddr   Memory address of the Display Sub System.
 * \param   xPos       X position of graphics window. This can take values in
 *          the following range:
 *          #DSS_DISPC_GFX_WINDOW_XPOS_MIN  to #DSS_DISPC_GFX_WINDOW_XPOS_MAX.
 *
 * \param   yPos       Y position of graphics window. This can take values in
 *          the following range:
 *          #DSS_DISPC_GFX_WINDOW_YPOS_MIN  to  #DSS_DISPC_GFX_WINDOW_YPOS_MAX.
 */
void DSSDispcGfxWindowPositionCfg(uint32_t baseAddr,
                                  uint32_t xPos,
                                  uint32_t yPos);


/**
 * \brief   This API configures the size of graphics window.
 *
 * \param   baseAddr   Memory address of the Display Sub System.
 * \param   width      Number of pixels per line of graphics window
 *                     (Program to value minus one).
 *          width can take values in the following range:
            #DSS_DISPC_GFX_SIZE_X_MIN   to  #DSS_DISPC_GFX_SIZE_X_MAX.
 *
 * \param   height     Number of lines of the graphics window
 *                     (Program to value minus one).
 *          height can take values in the following range:
 *          #DSS_DISPC_GFX_SIZE_Y_MIN   to   #DSS_DISPC_GFX_SIZE_Y_MAX.
 */
void DSSDispcGfxWindowSizeConfig(uint32_t baseAddr,
                                 uint32_t width,
                                 uint32_t height);


/**
 * \brief   This API configures the base address of graphics buffer displayed in
 *          the graphics window.
 *
 * \param   baseAddr      Memory address of the Display Sub System.
 * \param   bufAddr       Base address of array which contain pixels of image to
 *                        be displayed.
 * \param   bufSelectFlag Is the value which selects buffer0 or buffer1.
 *          'bufSelectFlag' can take one of the value from the following enum
 *          - #dssDispcFrmBufId_t.
 */
void DSSDispcGfxSetBufAddr(uint32_t baseAddr,
                           uint32_t bufAddr,
                           uint32_t bufSelectFlag);


/**
 * \brief   This API returns the value of Graphics FIFO size in bytes.
 *
 * \param   baseAddr  Memory address of the Display Sub System.
 *
 * \retval  fifoSize  Size of Graphics FIFO in bytes.
 */
uint32_t DSSDispcGetGfxDmaFifoSize(uint32_t baseAddr);


/**
 * \brief   This API sets the graphics pipeline DMA fifo preload register value.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   preloadVal  Graphics preload value. Number of bytes defining
 *                      the preload value.
 */
void DSSDispcSetGfxFifoPreload(uint32_t baseAddr, uint32_t preloadVal);


/**
 * \brief   This API gets the graphics pipeline DMA fifo preload register value.
 *
 * \param   baseAddr     Memory address of the Display Sub System.
 *
 * \retval  preloadValue Graphics preload value. Number of bytes defining
 *                       the preload value
 */
uint32_t DSSDispcGetGfxFifoPreload(uint32_t baseAddr);


/**
 * \brief   This API enables the overlay optimization.The API also configures
 *          the number of bytes to skip while fetching the graphics-encoded
 *          pixels when reaching the beginning of the video window.
 *
 * \details The optimization allows fetching only the visible graphics pixels.
 *
 * \param   baseAddr       Memory address of the Display Sub System.
 * \param   windowSkipSize Number of bytes to skip while fetching the graphics
 *                         -encoded pixels.
 */
void DSSDispcGfxOvlyOptimizationEnable(uint32_t baseAddr,
                                       uint32_t windowSkipSize);


/**
 * \brief   This API disables the overlay optimization corresponding to the
 *          graphics pipeline.
 *
 * \param   baseAddr   Memory address of the Display Sub System.
 */
void DSSDispcGfxOvlyOptimizationDisable(uint32_t baseAddr);


/**
 * \brief   This API enables or disables the video pipeline.
 *
 * \details If enabled, video pipeline will be active and video window will
 *          present on the screen. If disabled, video pipeline will be inactive
 *          and video window will not present on the screen.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   enableVid  This value determines the enabling of video pipeline.
 *          'enableVid' can take one of the following values
 *          -# TRUE  - Video pipeline is enabled.
 *          -# FALSE - Video pipeline is disable.
 */
void DSSDispcVidEnable(uint32_t baseAddr,
                       uint32_t vidPipeline,
                       uint32_t enableVid);


/**
 * \brief   This API configures the Video pipeline DMA parameters.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   pCfg        Pointer to structure #dssDispcDmaCfg_t containing
 *                      DMA configuration parameters.
 */
void DSSDispcVidDmaConfig(uint32_t baseAddr,
                          uint32_t vidPipeline,
                          dssDispcDmaCfg_t *pCfg);


/**
 * \brief   This API enables or disables the DMA self refresh of the video
 *          window from its own FIFO only.
 *
 * \details If enabled, the video pipeline does not need any more to fetch data
 *          from memory. Only the video FIFO is used. If disabled the video
 *          pipeline accesses the interconnect to fetch data from the system
 *          memory.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   enableSelfRefresh  Flag configures the enabling of self refresh.
 *          enableSelfRefresh can take one of the following values
 *          -# TRUE  - DMA self refresh is enabled.
 *          -# FALSE - DMA self refresh is disabled.
 */
void DSSDispcVidDmaSelfRefreshEnable(uint32_t baseAddr,
                                     uint32_t vidPipeline,
                                     uint32_t enableSelfRefresh);


/**
 * \brief   This API configures priority of video pipeline.
 *
 * \details The video pipeline is one of the high priority pipelines. The
 *          arbitration wheel gives always the priority first to the high
 *          priority pipelines using round-robin between them.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   priority    Value which determines the priority.
 *          'priority' can take values from the following enum
 *          #dssDispcVidPriority_t.
 */
void DSSDispcSetVidPriority(uint32_t baseAddr,
                            uint32_t vidPipeline,
                            uint32_t priority);


/**
 * \brief   This API configures the format of video pipeline data. This API also
 *          performs the colour space conversion and replication based on the
 *          formats and user controlled flags.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   pCfg        Pointer to structure containing video format
 *                      configuration parameters.
 *
 * \note    Below are few points about this API:
 *          -# If color space conversion flag is on, then if input format is
 *             YUV, then it will be converted to RGB format.
 *          -# Extender processing: If enabled the encoded pixel data in RGB
 *             format (RGB16/RGB12) can be extended to 24-bit format with
 *             replication of the MSB part to fill up the LSB due to the 24-bit
 *             left alignment. If disabled, the encoded pixel data in RGB format
 *            (RGB16) can be extended to 24-bit by filling LSB part with 0s.
 */
void DSSDispcVidFormatConfig(uint32_t baseAddr,
                             uint32_t vidPipeline,
                             dssVidFmtCfg_t *pCfg);


/**
 * \brief   This API configures the position of video window in overlay.
 *
 * \param   baseAddr     Memory address of the Display Sub System.
 * \param   vidPipeline  This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   xPos         x position of video window. This can take values in the
 *          following range:
 *          #DSS_DISPC_VID_WINDOW_XPOS_MIN  to #DSS_DISPC_VID_WINDOW_XPOS_MAX.
 *
 * \param   yPos         y position of video window. This can take values in the
 *          following range:
 *          #DSS_DISPC_VID_WINDOW_YPOS_MIN  to #DSS_DISPC_VID_WINDOW_YPOS_MAX.
 */
void DSSDispcVidWindowPositionCfg(uint32_t baseAddr,
                                  uint32_t vidPipeline,
                                  uint32_t xPos,
                                  uint32_t yPos);


/**
 * \brief   This API configures size of video window.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   inputWidth  Original input video buffer width(number of pixels per
 *          line) in system memory.(Program to value minus one). This can take
 *          values in the following range:
 *          #DSS_DISPC_VID_ORG_SIZE_X_MIN   to  #DSS_DISPC_VID_ORG_SIZE_X_MAX.
 *
 * \param   inputHeight Original input video buffer height(number of lines) in
 *          system memory. (Program to value minus one). This can take values in
 *          the following range:
 *          #DSS_DISPC_VID_ORG_SIZE_Y_MIN  to  #DSS_DISPC_VID_ORG_SIZE_Y_MAX.
 *
 * \param   outputWidth  Number of pixels per line of video window. (Program to
 *          value minus one). This can take values in the following range:
 *          #DSS_DISPC_VID_SIZE_X_MIN     to  #DSS_DISPC_VID_SIZE_X_MAX.
 *
 * \param   outputHeight  Number of lines of the video window. (Program to value
 *          minus one). This can take values in the following range:
 *          #DSS_DISPC_VID_SIZE_Y_MIN   to  #DSS_DISPC_VID_SIZE_Y_MAX.
 *
 * \note    Please find the below points regarding size configuration:
 *          -# If the input and output sizes are not matching, then resizer has
 *             to be configured accordingly, to display the output image
 *             properly.
 *          -# If the input and output sizes are not matching and if resizer is
 *             is not enabled, then the output will be a cropped image.
 */
void DSSDispcVidSizeConfig(uint32_t baseAddr,
                           uint32_t vidPipeline,
                           uint32_t inputWidth,
                           uint32_t inputHeight,
                           uint32_t outputWidth,
                           uint32_t outputHeight);


/**
 * \brief   This API enables the resizing feature.
 *
 * \param   baseAddr      Memory address of the Display Sub System.
 * \param   vidPipeline   This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   resizeType  This indicates the type of re-sampling that needs to be
 *          enabled for the use case. This can take values from the following
 *          enum #dssDispcVidResizeType_t.
 *
 * \param   filterTaps   This value determines number of filter taps required
 *          for the resizing operation. This can take values from following
 *          enum #dssDispcVidVertResizeFilterTaps_t.
 */
void DSSDispcVidResizeEnable(uint32_t baseAddr,
                             uint32_t vidPipeline,
                             uint32_t resizeType,
                             uint32_t filterTaps);


/**
 * \brief   This API sets the type of the horizontal resizing i.e Up or down
 *          sampling and also configures the internal parameters required for
 *          the horizontal resizing.
 *
 * \param   baseAddr      Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   upDownType    This value indicates type of re-sampling i.e whether
 *          it is up-sampling or down sampling. This can take values from the
 *          following enum #dssDispcVidHorzResizeType_t.
 *
 * \pre     Below are few of the preconditions:
 *          -# Input width and Output Width register fields should have
 *             been configured before calling this API.
 *          -# This API reads the input and output widths from the register.
 */
void DSSDispcVidHorzResizeCfg(uint32_t baseAddr,
                              uint32_t vidPipeline,
                              uint32_t upDownType);


/**
 * \brief   This API configures the horizontal resizing coefficients.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   horzCoeff   Array of structures containing Horizontal resizing
 *                      coefficients.
 *
 * \note    Please find below note:
 *          -# If user wants to use default coefficients set, then user can pass
 *             the following coefficients sets:
 *            -# For up sampling use the table  HORZUPSAMPLECOEFF_DEFAULT.
 *            -# For down sampling use the table  HORZDOWNSAMPLECOEFF_DEFAULT.
 */
void DSSDispcVidHorzResizeCoeffCfg(uint32_t baseAddr,
                                   uint32_t vidPipeline,
                                   dssDispcHorzResizeCoeff_t horzCoeff[]);


/**
 * \brief   This API sets the type of the vertical resizing i.e Up or down
 *          sampling and also configures the internal parameters required for
 *          the horizontal resizing.
 *
 * \param   baseAddr      Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   upDownType    This value indicates type of re-sampling i.e whether
 *          it is upsampling or down sampling. This can take values from the
 *          following enum #dssDispcVidVertResizeType_t.
 */
void DSSDispcVidVertResizeCfg(uint32_t baseAddr,
                              uint32_t vidPipeline,
                              uint32_t upDownType);


/**
 * \brief   This API configures the vertical resizing coefficients.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   vertCoeff   Array of structures containing Vertical resizing
 *          coefficients.
 *
 * \note    Please find below note:
 *          -# If user wants to use default coefficients set, then user can pass
 *             the following coefficient sets
 *            -# For Up sampling
 *              -# 3 Tap configuration:  VERTUPSAMPLE3TAPCOEFF_DEFAULT
 *              -# 5 Tap configuration:  VERTUPSAMPLE5TAPCOEFF_DEFAULT
 *            -# For Down sampling
 *              -# 3 Tap configuration:  VERTDOWNSAMPLE3TAPCOEFF_DEFAULT
 *              -# 5 Tap configuration:  VERTDOWNSAMPLE5TAPCOEFF_DEFAULT
 */
void DSSDispcVidVertResizeCoeffCfg(uint32_t baseAddr,
                                   uint32_t vidPipeline,
                                   dssDispcVertResizeCoeff_t vertCoeff[]);


/**
 * \brief   This API disables the resizing feature.
 *
 * \param   baseAddr     Memory address of the Display Sub System.
 * \param   vidPipeline  This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 */
void DSSDispcVidResizeDisable(uint32_t baseAddr, uint32_t vidPipeline);


/**
 * \brief   This API configures the base address of video buffer displayed in
 *          the video window.
 *
 * \param   baseAddr      Memory address of the Display Sub System.
 * \param   vidPipeline   This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   bufAddr       Base address of array which contain pixels of image
 *                        to be displayed.
 * \param   bufSelectFlag Is the value which selects buffer0 or buffer1.
 *          bufSelectFlag can take values from the following enum
 *          #dssDispcFrmBufId_t.
 */
void DSSDispcVidSetBufAddr(uint32_t baseAddr,
                           uint32_t vidPipeline,
                           uint32_t bufAddr,
                           uint32_t bufSelectFlag);


/**
 * \brief   This API returns the value of video FIFO size in bytes.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \retval  fifoSize    Number of bytes defining the video dma FIFO value.
 */
uint32_t DSSDispcGetVidDmaFifoSize(uint32_t baseAddr, uint32_t vidPipeline);


/**
 * \brief   This API sets the video pipeline DMA fifo preload register value.
 *
 * \param   baseAddr    Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \param   preloadVal  Video preload value. Number of bytes defining
 *                      the preload value.
 */
void DSSDispcSetVidFifoPreload(uint32_t baseAddr,
                               uint32_t vidPipeline,
                               uint32_t preloadVal);


/**
 * \brief   This API gets the video pipeline DMA fifo preload register value.
 *
 * \param   baseAddr     Memory address of the Display Sub System.
 * \param   vidPipeline This value indicates the number of video pipeline.
 *          'vidPipeline' can take values from the following enum
 *          - #dssDispcVidPipelineId_t.
 *
 * \retval  preloadValue Video preload value. Number of bytes defining
 *                       the preload value.
 */
uint32_t DSSDispcGetVidFifoPreload(uint32_t baseAddr, uint32_t vidPipeline);


/**
 * \brief   This API enables or disables the the LCD output. A valid
 *          configuration must be set before enabling the LCD output.
 *
 * \param   baseAddr   Memory address of the Display Sub System.
 *
 * \param   enableLcd  This value determines the enabling of LCD output.
 *          'enableLcd' can take one of the following values:
 *          -# TRUE  - LCD output is enabled.
 *          -# FALSE - LCD output is disabled.
 */
void DSSDispcLcdOutputEnable(uint32_t baseAddr, uint32_t enableLcd);


/**
 * \brief   This API configures the display attributes of LCD panel like
 *          active/passive display and colour/monochrome etc.
 *
 * \param   baseAddr      Memory address of the Display Sub System.
 * \param   pCfg          Pointer to the structure #dssDispcLcdAttrCfg_t
 *                        containing the display attributes.
 */
void DSSDispcLcdDisplayAttrConfig(uint32_t baseAddr,
                                  dssDispcLcdAttrCfg_t *pCfg);


/**
 * \brief   This API configures the LCD panel timing parameters.
 *
 * \param   baseAddr  Memory address of the Display Sub System.
 * \param   pCfg      Pointer to the structure #dssDispcLcdTimingCfg_t
 *                    containing the LCD panel timing parameters.
 */
void DSSDispcLcdTimingConfig(uint32_t baseAddr, dssDispcLcdTimingCfg_t *pCfg);


/**
 * \brief   This API configures the polarities of the various signals of LCD.
 *
 * \param   baseAddr Memory address of the Display Sub System.
 *
 * \param   pCfg     Pointer to the structure #dssDispcLcdPolarityCfg_t
 *                   containing the polarities of various signals of LCD.
 */
void DSSDispcLcdPolarityConfig(uint32_t baseAddr,
                               dssDispcLcdPolarityCfg_t *pCfg);


/**
 * \brief   This API configures the ACBias signal parameters.
 *
 * \param   baseAddr Memory address of the Display Sub System.
 *
 * \param   pCfg     Pointer to the structure #dssDispcLcdAcbCfg_t
 *                   containing the parameters of ACbias control.
 *
 * \note    This API should be called only for passive LCD displays.
 */
void DSSDispcLcdAcbiasConfig(uint32_t baseAddr,
                             dssDispcLcdAcbCfg_t *pCfg);


/**
 * \brief   This API configures the gating control of LCD sync and pixel clock
 *          signals.
 *
 * \param   baseAddr Memory address of the Display Sub System.
 *
 * \param   pCfg     Pointer to the structure #dssDispcLcdGatedCtrl_t
 *                   containing the gated control parameters.
 */
void DSSDispcLcdSigGatedCtrl(uint32_t baseAddr,
                             dssDispcLcdGatedCtrl_t *pCfg);


/**
 * \brief   This API enables the LCD enable signal and also configures the
 *          polarity of the LCD enable signal.
 *
 * \param   baseAddr      Memory address of the Display Sub System.
 * \param   sigEnable     Value to either enable or disable LCD enable signal.
 *          This can take values from the following enum
 *          #dssDispcLcdEnSigCtrl_t.
 *
 * \param   polarity      Polarity of the LCD enable signal. This can take
 *          values from the following enum #dssDispcLcdEnSigPol_t.
 */
void DSSDispcLcdEnableSigConfig(uint32_t baseAddr,
                                uint32_t sigEnable,
                                uint32_t polarity);


/**
 * \brief   This API calculates the clock dividers and configures the required
 *          clocks - logic clock and pixel clock.
 *
 * \param   baseAddr      Memory address of the Display Sub System.
 * \param   functionalClk is the functional clock to Display Controller.
 * \param   pixelClk      is the required pixel clock frequency.
 *
 * \retval  progPixelClk  This indicates actual pixel clock achieved through
 *                        dividers and the same is configured in the hardware.
 */
uint32_t DSSDispcLcdClkConfig(uint32_t baseAddr,
                              uint32_t functionalClk,
                              uint32_t pixelClk);


/**
 * \brief   This API enables the spatial/temporal dithering logic and
 *          type of dithering logic to be applied.
 *
 * \param   baseAddr        Memory address of the Display Sub System.
 * \param   ditheringType   is the value to select the type of dithering. This
 *          can take values from the following enum #dssDispcStDitherType_t.
 */
void DSSDispcStDitheringEnable(uint32_t baseAddr, uint32_t ditheringType);


/**
 * \brief   This API disables the spatial/temporal dithering logic.
 *
 * \param   baseAddr   Memory address of the Display Sub System.
 */
void DSSDispcStDitheringDisable(uint32_t baseAddr);


/**
 * \brief   This API enables the transparency colour key for LCD output. This
 *          API also configures the colour key value along with type of colour
 *          key - destination graphics(normal mode)/source graphics(alpha mode)
 *          transparency colour key or source video transparency colour key
 *          (normal mode).
 *
 * \param   baseAddr        Memory address of the Display Sub System.
 * \param   keyType         is the value that selects either graphics or video
 *          transparency colour key. This can take values from the following
 *          enum #dssDispcOvlyTckType_t.
 *
 * \param   colorKeyValue   is the value that sets the transparency colour value
 *          for the video/graphics overlays for LCD output.
 *          'colorKeyValue' can be in one of the following formats:
 *          -# [0]   BITMAP 1 (CLUT), [23,1] set to 0s
 *          -# [1:0] BITMAP 2 (CLUT), [23,2] set to 0s
 *          -# [3:0] BITMAP 4 (CLUT), [23,4] set to 0s
 *          -# [7:0] BITMAP 8 (CLUT), [23,8] set to 0s
 *          -# [11:0] RGB 12, [23,12] set to 0s
 *          -# [15:0] RGB 16, [23,16] set to 0s
 *          -# [23:0] RGB 24
 */
void DSSDispcOverlayTckEnable(uint32_t baseAddr,
                              uint32_t keyType,
                              uint32_t colorKeyValue);


/**
 * \brief   This API disables the transparency colour key for LCD output.
 *
 * \param   baseAddr   Memory address of the Display Sub System.
 */
void DSSDispcOverlayTckDisable(uint32_t baseAddr);


/**
 * \brief   This API enables or disables the alpha blending feature for LCD
 *          output.
 *
 * \details If enabled, overlay manager will be in alpha mode. If disabled,
 *          overlay manager will be in normal mode.
 *
 * \param   baseAddr   Memory address of the Display Sub System.
 *
 * \param   enableAlphaBlender Flag controlling the enable/disable of alpha
 *          blending. This can take following values:
 *          -# TRUE  - Alpha blender is enabled.
 *          -# FALSE - Alpha blender is disabled.
 */
void DSSDispcOverlayAlphaBlenderEnable(uint32_t baseAddr,
                                       uint32_t enableAlphaBlender);


/**
 * \brief   This API configures global alpha blending value for graphics
 *          and video2 pipelines.
 *
 * \param   baseAddr  Memory address of the Display Sub System.
 * \param   pipeline  Value to select the pipeline.
 *          'pipeline' can take one of the following values:
 *          - #DSS_DISPC_PIPELINE_TYPE_GRAPHICS - Graphics pipeline is selected.
 *          - #DSS_DISPC_PIPELINE_TYPE_VIDEO2   - Video2 pipeline is selected.
 *
 * \param   globalAlpha     Is the value that sets the global alpha blending
 *          value for video2 pipeline.
 *
 * \note    Please find below notes:
 *          -# 'globalAlpha' can take values in the following range
 *            -# Graphics pipeline:
 *              - #DSS_DISPC_OVLY_GFX_GLOBAL_ALPHA_MIN to
 *                #DSS_DISPC_OVLY_GFX_GLOBAL_ALPHA_MAX.
 *            -# Video2 pipeline:
 *              - #DSS_DISPC_OVLY_VID2_GLOBAL_ALPHA_MIN to
 *                #DSS_DISPC_OVLY_VID2_GLOBAL_ALPHA_MAX.
 *          -# This feature is not supported for VIDEO1 pipeline.
 */
void DSSDispcOverlaySetGlobalAlpha(uint32_t baseAddr,
                                   uint32_t pipeline,
                                   uint32_t globalAlpha);


/**
 * \brief   This API configures the default solid background colour for the
 *          LCD output. This colour will be displayed when there is no data
 *          from the overlays.
 *
 * \param   baseAddr  Memory address of the Display Sub System.
 * \param   color     Is the 24-bit RGB colour value.
 */
void DSSDispcOverlaySetBackgndColor(uint32_t baseAddr, uint32_t color);


/**
 * \brief   This API saves the context of DSS registers.
 *          This is useful in power management, where the power supply to
 *          display sub system will be cut off. This API has to be called
 *          before entering sleep state and before clock and power gating
 *          of DSS module.
 *
 * \param   baseAddr Memory address of the Display Sub System.
 * \param   pCtx     Pointer to the structure where the context has to be saved.
 */
void DSSContextSave(uint32_t baseAddr, dssContext_t *pCtx);


/**
 * \brief   This API restores the context of DSS registers.
 *          This is useful in power management, where the power supply to
 *          display sub system will be cut off. This API has to be called
 *          after waking from sleep state and after power and clock ungating.
 *
 * \param   baseAddr  Memory address of the Display Sub System.
 * \param   pCtx      The pointer to the structure where the context has to be
 *                    restored from.
 */
void DSSContextRestore(uint32_t baseAddr, dssContext_t *pCtx);


#ifdef __cplusplus
}
#endif

#endif /* #ifndef DSS_H_ */
