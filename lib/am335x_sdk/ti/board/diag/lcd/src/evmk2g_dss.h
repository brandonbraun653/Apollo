/*
 * Copyright (c) 2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * \file      evmk2g_dss.h
 *
 * \brief     This file contains DSS specific structure, typedefs, function
 *            prototypes.
 *
 */

#ifndef _EVMK2G_DSS_H_
#define _EVMK2G_DSS_H_

/*******************************************************************************
*                           MACRO DEFINITIONS
*******************************************************************************/
/*****************************************************************************/

#undef DISPLAY_LOGO

/** Return values */
#define DSS_RET_OK          (0)
#define DSS_RET_FAILED      (1)


/** Predefined constants*/

/** Base address of the DSS module, 0x02540000 for Galileo */
#define DSS_BASE_ADDRESS       (CSL_DSSUL_0_CFG_REGS)

/** Base address of the remote frame buffer (RFBI) registers */
#define DSS_RFBI_BASE_ADDRESS  (DSS_BASE_ADDRESS + 0x6000)

/** Base address of the common display controller (DISPC) registers */
#define DSS_DISPC_BASE_ADDRESS (DSS_BASE_ADDRESS + 0x10000)

/** Base address of the video pipeline (VID) registers */
#define DSS_VID_BASE_ADDRESS   (DSS_BASE_ADDRESS + 0x17000)

/** Base address of the overlay manager (OVR) registers */
#define DSS_OVR_BASE_ADDRESS   (DSS_BASE_ADDRESS + 0x1A800)

/** Base address of the cursor pipeline (VP) registers */
#define DSS_VP_BASE_ADDRESS    (DSS_BASE_ADDRESS + 0x1AC00)

/** Base address of the chip level register */
#define CHIP_LEVEL_REG      (0x02620000)

#define KICK0_BASE_ADDRESS  (CHIP_LEVEL_REG + 0x0038)
#define KICK1_BASE_ADDRESS  (CHIP_LEVEL_REG + 0x003C)
#define KICK0_UNLOCK        (0x83E70B13)
#define KICK1_UNLOCK        (0x95A4F1E0)
#define KICK_LOCK           (0)

/** Initiator Priority Register */
#define INITIATOR_PRIORITY_1_OFFSET (0x158)
#define DSS_INITIATOR_LOPRI_SHIFT   (0)
#define DSS_INITIATOR_LOPRI_MASK    (0x00000007)
#define DSS_INITIATOR_HIPRI_SHIFT   (4)
#define DSS_INITIATOR_HIPRI_MASK    (0x00000070)

/** ARMPLL definitions */
#define SEC_PLLCTL0_PLLM_OFFSET     (6)
#define SEC_PLLCTL0_PLLM_MASK       (0xFFFF003F)
#define SEC_PLLCTL0_BWADJ_OFFSET    (24)
#define SEC_PLLCTL0_BWADJ_MASK      (0x00FFFFFF)
#define SEC_PLLCTL0_OD_OFFSET       (19)
#define SEC_PLLCTL0_OD_MASK         (0xFF87FFFF)
#define SEC_PLLCTL0_BYPASS_OFFSET   (23)
#define SEC_PLLCTL0_BYPASS_MASK     (0xFF7FFFFF)
#define SEC_PLLCTL1_RESET_OFFSET    (14)
#define SEC_PLLCTL1_RESET_MASK      (0xFFFFBFFF)
#define SEC_PLLCTL1_PWRDWN_OFFSET   (15)
#define SEC_PLLCTL1_PWRDWN_MASK     (0xFFFF7FFF)
#define SEC_PLLCTL1_ENSTAT_OFFSET   (6)
#define SEC_PLLCTL1_ENSTAT_MASK     (0xFFFFFFBF)

#define DSS_PLL_CTL0_BYPASS_EN    (1)
#define DSS_PLL_CTL0_BYPASS_DIS   (0)
#define DSS_PLL_CTL0_BYPASS_SHIFT (23)
#define DSS_PLL_CTL0_BYPASS_MASK  (0x00000000)
#define DSS_PLL_CTL0_CLKOD_SHIFT  (19)
#define DSS_PLL_CTL0_CLKOD_MASK   (0x00780000)
#define DSS_PLL_CTL0_PLLM_SHIFT   (6)
#define DSS_PLL_CTL0_PLLM_MASK    (0x0007FFC0)
#define DSS_PLL_CTL0_PLLD_SHIFT   (0)
#define DSS_PLL_CTL0_PLLD_MASK    (0x0000003F)

#define DSS_DISPC_VID_BUFFER0 (0)
#define DSS_DISPC_VID_BUFFER1 (1)

/** 4096 possible*/
#define DSS_DISPC_VID_WINDOW_XPOS_MAX (1920)

/** 4096 possible*/
#define DSS_DISPC_VID_WINDOW_YPOS_MAX (1080)

#define DSS_DISPC_VID_SIZE_X_MIN (1)
#define DSS_DISPC_VID_SIZE_X_MAX (4096)
#define DSS_DISPC_VID_SIZE_Y_MIN (1)
#define DSS_DISPC_VID_SIZE_Y_MAX (4096)

#define DSS_DISPC_VID_NIBBLE_MODE_DISABLE (0)
#define DSS_DISPC_VID_NIBBLE_MODE_ENABLE  (1)

#define DSS_DISPC_VID_FMT_RGBA32U (0x09)
#define DSS_DISPC_VID_FMT_RGB24U (0x0B)
#define DSS_DISPC_VID_FMT_RGB32U (0x27)
#define DSS_DISPC_VID_FMT_BGRA32U (0x0A)
#define DSS_DISPC_VID_FMT_ABGR32U (0x08)

#define DSS_LCD_TYPE_PASSIVE (0)
#define DSS_LCD_TYPE_ACTIVE  (1)
#define DSS_LCD_DISPLAY_MONO (1)

/** The max is really 4096 but recommended to stay below 512 for low jitter*/
#define DSS_PLL_MULTIPLIER_MAX     (512)
#define DSS_PLL_REF_DIVIDER_MAX    (64)
#define DSS_PLL_OUTPUT_DIVIDER_MAX (16)

#define DSS_PROG_LINE_NUMBER    (100)

#define MAX_LCD_WIDTH   (1920)
#define MAX_LCD_HEIGHT  (1080)

#define CSL_ARM_GIC_DSS_INT (0x000000F7)
#define CSL_CIC_DSS_INT     (0x0000005F)

/** IMAGE GENERATION SPECIFIC */
#define RGB888_CONSTANT (0x00000001)
#define RGB888_GENERATE (0x00000002)
#define RGB888_ADDRESS (0x00000003)
#if 0
#define BLACK   (0x00000000)
#define WHITE   (0x00FFFFFF)
#define BLUE    (0x000000FF)
#define GREEN   (0x0000FF00)
#define RED     (0x00FF0000)
#define PURPLE  (0x00A020F0)
#define PINK    (0x00FFC0CB)
#define YELLOW  (0x00FFFF00)
#else
#define BLACK   (0x00000000)
#define WHITE   (0x00FFFFFF)
#define BLUE    (0x00FF0000)
#define GREEN   (0x0000FF00)
#define RED     (0x000000FF)
#define PURPLE  (0x00F020A0)
#define PINK    (0x00CBC0FF)
#define YELLOW  (0x0000FFFF)
#endif
/** Frame address  */
#define DDR_FRAME_ADDRESS_START (0x88000000)
#define DDR_FRAME_ADDRESS_END   (0x88FFFFFF)

/** CSL Definitions for VPCFG */
#define CSL_DSSVP_CONTROL_LCDEN_SHIFT    (0u)
#define CSL_DSSVP_CONTROL_LCDEN_MASK     (0x00000001u)
#define CSL_DSSVP_CONTROL_LCDEN_RESETVAL (0x00000000u)
#define CSL_DSSCOMMON_DISPC_SYSCONFIG_SOFTRESET (1)

/** Display Video priority macros */
#define DSS_DISPC_VID_PRIORITY_NORMAL (0)
#define DSS_DISPC_VID_PRIORITY_HIGH   (1)


/*---------------------------------------------------------------------------*/
/* Data Structure                                                            */
/*---------------------------------------------------------------------------*/
/*
 * Configuration parameters specific to each LCD panel
 */
typedef struct _lcdCfg_t
{
    Uint32 LcdWidth;        /**< Pixels per line (PPL)       */
    Uint32 LcdHeight;       /**< Lines per panel (LPP)       */
    Uint32 LcdPclk;         /**< Pixel clock (PCLK)          */
    Uint32 HsyncWidth;      /**< Horizontal Sync Width (HSW) */
    Uint32 HFrontPorch;     /**< Horizontal front porch (HFP)*/
    Uint32 HBackPorch;      /**< Horizontal back porch (HBP)*/
    Uint32 VsyncWidth;      /**< Vertical sync width (VSW)  */
    Uint32 VFrontPorch;     /**< Vertical front porch (VFP) */
    Uint32 VBackPorch;      /**< Vertical back porch (VBP)  */
}lcdCfg_t;

/*
 * Configuration parameters for the Display Controller (DISPC)
 */
typedef struct _dispCfg_t
{
    Uint32 displayType;     /**< Active or Passive display? */
    Uint32 colorMode;       /**< Monochrome or Color? */
    Uint32 dataLines;       /**< How many LCD data lines? */
    Uint32 mono8Bit;

}dispCfg_t;

/*
 * Control signal configuration parameters
 */
typedef struct _tmgCfg_t
{
    Uint32 hsyncPolarity;
    Uint32 vsyncPolarity;
    Uint32 outputEnablePolarity;
    Uint32 syncEdge;
    Uint32 syncEdgeCtrl;
    Uint32 pclkPolarity;
    Uint32 acbFrequency;
    Uint32 acbi;
    Uint32 hsyncGated;
    Uint32 vsyncGated;
    Uint32 acbGated;
    Uint32 pixelClkGated;
}tmgCfg_t;

/*
 * Video pipeline DMA configuration
 */
typedef struct _dmaCfg_t
{
      Uint32 fifoLoThr;
      Uint32 fifoHiThr;
      Uint32 pixelInc;
      Uint32 rowInc;
      Uint32 preloadSelect;
      Uint32 mflagLoThr;
      Uint32 mflagHiThr;
      Uint32 mflagAttrControl;
      Uint32 mflagAttrStart;
      Uint32 dssInitiatorPri_Hi;
      Uint32 dssInitiatorPri_Lo;
}dmaCfg_t;

/*
 * Video pipeline DMA configuration
 */
typedef struct _dssInfo_t
{
    lcdCfg_t  lcdCfg;
    dispCfg_t dispCfg;
    tmgCfg_t  tmgCfg;
    dmaCfg_t  vidDmaCfg;

}dssInfo_t;

/*---------------------------------------------------------------------------*/
/* Global Variables                                                          */
/*---------------------------------------------------------------------------*/

/**  Type of the Return value for the functions */
typedef uint16_t DSS_RET;

/*---------------------------------------------------------------------------*/
/* Function Prototypes                                                       */
/*---------------------------------------------------------------------------*/

/**
 *  \brief    Configures panel specific timing parameters
 *
 *  This function configures the DSS Initiator priority
 *
 *  \param    baseAddr  [IN]   base address of DSSUL Video port register
 *  \param    pLcdCfg   [IN]   pointer to LCD configuration
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcLcdPanelCfg(Uint32 baseAddr, lcdCfg_t *pCfg);

/**
 *  \brief    Configures LCD color attributes
 *
 *  This function configures the LCD color attributes
 *
 *  \param    baseAddr   [IN]   base address of DSSUL Video port register
 *  \param    pDispCfg   [IN]   pointer to LCD configuration
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcLcdDisplayAttribCfg(Uint32 baseAddr,
                                   dispCfg_t *pCfg);

/**
 *  \brief    Configures control signal polarities
 *
 *  This function configures the control signal polarities
 *
 *  \param    baseAddr  [IN]   base address of DSSUL Video port register
 *  \param    pTmgCfg   [IN]   pointer to timing configuration
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcLcdTimingCfg(Uint32 baseAddr,
                            tmgCfg_t *pCfg);

/**
 *  \brief    Initialize the Frame buffer
 *
 *  This function performs initialization of frame buffer, loading of color bar
 *  information to the frame buffer or loading a constant value to the frame
 *  buffer.
 *
 *  \param    mode   [IN]   mode of operation for frame buffer
 *  \param    height [IN]   height of the frame buffer
 *  \param    width  [IN]   width of the frame buffer
 *
 *  \return   NONE
 */
void dssInitFrameBuffer(Uint32 mode, Uint32 width, Uint32 height);

/**
 *  \brief    Puts the given color to the frame buffer
 *
 *  This function puts the color passed as parameter to the
 *  frame buffer to display the given color. This function is
 *  used to test the LCD, frame buffer by passing any desired
 *  color.
 *
 *  \param    plcdCfg   [IN]   pointer to lcdCfg to get height and width
 *  \param    color     [IN]   color to be displayed on the Display panel
 *
 *  \return   NONE
 */
void dssFrameBufferColor(lcdCfg_t *pCfg, Uint32 color);

#ifdef DISPLAY_LOGO
void dssFillFrameBuffer(void);
#endif

/**
 *  \brief    Disables ST Dithering
 *
 *  This function Disables ST Dithering
 *
 *  \param    baseAddr   [IN]   base address of DSSUL register
 *
 *  \return
 *          NONE
 */
void dssDispcSTDitheringDisable(Uint32 baseAddr);

/**
 *  \brief    Bypasses RFBI mode
 *
 *  This function bypasses RFBI mode
 *
 *  \param    baseAddr   [IN]   base address of DSSUL register
 *
 *  \return
 *          NONE
 */
void dssDispcRfbiModeBypass(Uint32 baseAddr);

/**
 *  \brief    Clear existing interrupts
 *
 *  This function clears the interrupt status
 *
 *  \param    baseAddr   [IN]   base address of DSSUL register
 *  \param    intFlag    [IN]   interrupt flag to be cleared
 *
 *  \return
 *          NONE
 */
void dssDispcIntStatusClearEx(Uint32 baseAddr, Uint32 intFlag);

/**
 *  \brief    Configures the line number that generates interrupt
 *
 *  This function configures the line number that generates interrupt
 *
 *  \param    baseAddr   [IN]   base address of DSSUL register
 *  \param    lineNumber [IN]   line number that generates interrupt
 *
 *  \return
 *          NONE
 */
void dssDispcProgLineNumberSet(Uint32 baseAddr, Uint32 lineNumber);

/**
 *  \brief    Enable/Disable DPI Control
 *
 *  This function enables/disables DPI interface from the registers
 *
 *  \param    baseAddr   [IN]   base address of DSSUL register
 *  \param    enableFlag [IN]   flag to indicate enable/disable
 *
 *  \return
 *          NONE
 */
void dssDpiCtrl(Uint32 baseAddr, Uint32 enableFlag);

/**
 *  \brief    Update shadow registers, set the Go bit
 *
 *  This function updates shadow registers and sets the GO bit
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *
 *  \return
 *          NONE
 */
void dssDispcShadowCfgEnable(Uint32 baseAddr);

/**
 *  \brief    Enable LCD output
 *
 *  This function enables/disables LCD output
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    enableFlag [IN]   flag to indicate enable/disable
 *
 *  \return
 *          NONE
 */
void dssDispcLcdOutputEnableCtrl(Uint32 baseAddr, Uint32 enableFlag);

/**
 *  \brief    Performs software reset of the Display Controller
 *
 *  This function performs software reset of the display controller.
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *
 *  \return
 *          NONE
 */
void dssDispcSoftReset(Uint32 baseAddr);

/**
 *  \brief    Enable/Disable the auto-idle function
 *
 *  This function enables/disables the auto idle function of the Display controller
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    enableFlag [IN]   flag to indicate enable/disable
 *
 *  \return
 *          NONE
 */
void dssDispcAutoIdleEnableCtrl(Uint32 baseAddr, Uint32 enableFlag);

/**
 *  \brief    Configures DISPC_GLOBAL_MFLAG_ATTRIBUTE Register
 *
 *  This function configures the Mflag attribute configuratin
 *
 *  \param    baseAddr     [IN]   base address of DSSUL Video config register
 *  \param    lo_threshold [IN]   value of low threshold
 *  \param    hi_threshold [IN]   value of high threshold
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcMflagThresholdCfg(Uint32 baseAddr, Uint32 lo_threshold,
                                   Uint32 hi_threshold);

/**
 *  \brief    Configures DISPC_GLOBAL_MFLAG_ATTRIBUTE Register
 *
 *  This function configures the Mflag attribute configuratin
 *
 *  \param    baseAddr   [IN]   base address of DSSUL Common cfg register
 *  \param    start   [IN]   value of MFlag START to be configured
 *  \param    control [IN]   value of MFlag control to be configured
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 *
 */
DSS_RET dssDispcMflagAttributeCfg(Uint32 baseAddr, Uint32 start, Uint32 control);

/**
 *  \brief    Configures the DSS initiator priority
 *
 *  This function configures the DSS Initiator priority
 *
 *  \param    baseAddr     [IN]   base address of DSSUL Video config register
 *  \param    lo_threshold [IN]   value of low threshold
 *  \param    hi_threshold [IN]   value of high threshold
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssInitiatorPriorityCfg(Uint32 baseAddr, Uint32 lo_priority,
                                Uint32 hi_priority);

/**
 *  \brief    Configure video pipeline DMA specific parameters
 *
 *  This function configures video pipeline DMA specific parameters
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    pDmaCfg    [IN]   pointer to DMA configuration
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcVidDMAConfig(Uint32 baseAddr, dmaCfg_t *pCfg);

/**
 *  \brief    Video pipeline interrupt enable
 *
 *  This function enables video pipeline interrupt
 *
 *  \param    baseAddr [IN]   base address of Video pipeline register
 *  \param    intFlag  [IN]   interrupt flag to enable
 *
 *  \return
 *          NONE
 */
void dssDispcVidIntEnable(Uint32 baseAddr, Uint32 intFlag);

/**
 *  \brief    Video pipeline interrupt disable
 *
 *  This function disables video pipeline interrupt
 *
 *  \param    baseAddr [IN]   base address of Video pipeline register
 *  \param    intFlag  [IN]   interrupt flag to disable
 *
 *  \return
 *          NONE
 */
void dssDispcVidIntDisable(Uint32 baseAddr, Uint32 intFlag);

/**
 *  \brief    Enable the video pipeline
 *
 *  This function enables/disables the video pipeline
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    enableFlag [IN]   flag to indicate enable/disable
 *
 *  \return
 *          NONE
 */
void dssDispcVidEnableCtrl(Uint32 baseAddr, Uint32 enableFlag);

/**
 *  \brief    VP interrupt enable
 *
 *  This function enables VP interrupt
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    intFlag    [IN]   interrupt flag to be enabled
 *
 *  \return
 *          NONE
 */
void dssDispcVPIntEnable(Uint32 baseAddr, Uint32 intFlag);

/**
 *  \brief    VP interrupt disable
 *
 *  This function disables VP interrupt
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    intFlag    [IN]   interrupt flag to be disabled
 *
 *  \return
 *          NONE
 */
void dssDispcVPIntDisable(Uint32 baseAddr, Uint32 intFlag);

/**
 *  \brief    Enable interrupts to VID or VP
 *
 *  This function enables interrupts to VID or VP
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    intFlag    [IN]   interrupt flag to be enabled
 *
 *  \return
 *          NONE
 */
void dssDispcCommonIntEnable(Uint32 baseAddr, Uint32 intFlag);

/**
 *  \brief    Update shadow registers, set the Go bit
 *
 *  This function updates shadow registers and sets the GO bit
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *
 *  \return
 *          NONE
 */
void dssDispcShadowCfgEnable(Uint32 baseAddr);

/**
 *  \brief    Erase frame buffer
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    enableFlag [IN]   flag to indicate enable/disable
 *
 *  \return
 *          NONE
 */
void dssEraseBuffer(lcdCfg_t *pCfg);

/**
 *  \brief    Set priority of Vid DMA
 *
 *  This function set the priority of Video DMA
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    priorityFlag [IN]   flag to indicate priority
 *
 *  \return
 *          NONE
 */
void dssDispcVidPrioritySet(Uint32 baseAddr, Uint32 priorityFlag);

/**
 *  \brief    Enable/Disable self refresh
 *
 *  This function enables/disables the self refresh
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    enableFlag [IN]   flag to indicate enable/disable
 *
 *  \return
 *          NONE
 */
void dssDispcVidSelfRefEnableCtrl(Uint32 baseAddr, Uint32 enableFlag);

/**
 *  \brief    Configure base address of frame buffer
 *
 *  This function configures the base address of frame buffer
 *
 *  \param    baseAddr      [IN]   base address of Video Port register
 *  \param    bufAddr       [IN]   buffer address
 *  \param    bufSelectFlag [IN]   buffer select flag
 *
 *  \return
 *          NONE
 */
void dssDispcVidSetBufAddr(Uint32 baseAddr, Uint32 bufAddr,
                           Uint32 bufSelectFlag);

                           /**
 *  \brief    Configure video window position
 *
 *  This function configures the video window position
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    xPos       [IN]   X position of video window
 *  \param    yPos       [IN]   Y position of video window
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcVidOvlyPositionCfg(Uint32 baseAddr, Uint32 xPos, Uint32 yPos);

/**
 *  \brief    Configure video window size
 *
 *  This function configures the video window size
 *
 *  \param    baseAddr   [IN]   base address of Video Port register
 *  \param    width      [IN]   Video width
 *  \param    height     [IN]   Video height
 *
 *  \return
 *           DSS_RET_OK - if configuration is success
 *           DSS_RET_FAILED - if configuration is failed
 */
DSS_RET dssDispcVidSizeCfg(Uint32 baseAddr, Uint32 width, Uint32 height);

/**
 *  \brief    Configure video window data format
 *
 *  This function configures the video window data format
 *
 *  \param    baseAddr    [IN]   base address of Video Port register
 *  \param    format      [IN]   format to be configured
 *  \param    nibbleModen [IN]   Nibble mode
 *
 *  \return
 *          NONE
 */
void dssDispcVidFormatSet(Uint32 baseAddr, Uint32 format, Uint32 nibbleModen);

#if (PLATFORM_DEBUG)
/**
 *  \brief    DSS Register Dump
 *
 *  This function dumps the DSS module register values
 *
 *  \param    dssInfo    [IN]   dssInfo structure passed from LCD panel init
 *
 *  \return   none
 *
 */
void dssDumpReg(dssInfo_t *dssInfo);
/**
 *  \brief    DSS Initialization
 *
 *  This function initializes the DSS module with the given LCD panel
 *  information, Timing configuration, Display configuration and DMA
 *  configuration.
 *
 *  \param    dssInfo    [IN]   dssInfo structure passed from LCD panel init
 *
 *  \return
 *           DSS_RET_OK -    status to indicate success
 *           DSS_RET_FAILED - if DSS failed to initialize, returns failure.
 *
 */
#endif
DSS_RET dssInit(dssInfo_t *dssInfo);

#endif // _EVMK2G_DSS_H_
