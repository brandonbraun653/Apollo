/**
 *  \file     vpfe.h
 *
 *  \brief    This file contains the prototypes of the APIs present in the
 *            device abstraction layer file of VPFE. This also contains some
 *            related macros and enums.
 *
 *  \details  Programming sequence of VPFE controller:
 *            -# Perform module clock enable and pin-mux configurations.
 *            -# Disable the VPFE module using the API #VPFEModuleEnable.
 *            -# Configure the VPFE registers to match the system requirements,
 *               including interrupt setup.
 *              -# Input Configuration:
 *                -# Input mode configuration:
 *                   -# Raw mode  : Configure using the API #VPFERawModeConfig
 *                   -# YCbCr mode: Configure using the API #VPFEYcbcrModeConfig
 *                      -# Further configuration specific to YCbCr mode as below
 *                        -# YCbCr 8 bit interface: Configure using the API
 *                           #VPFEYcbcr8BitConfig.
 *                        -# YCbCr 16 bit interface: Configure using the API
 *                           #VPFEYcbcr16BitConfig.
 *                -# Configure Synchronization Signal using the API
 *                   #VPFESyncSignalConfig.
 *                -# Field mode configuration:
 *                   -# Configure the input field mode using the API
 *                      #VPFESetFieldMode.
 *                   -# If field mode is "INTERLACED" then perform additional
 *                      configurations using the API
 *                      #VPFEInterlacedFieldParamsCfg.
 *              -# Output Configuration:
 *                 -# Configure the output frame resolution using the
 *                    API #VPFEOutputFrameResConfig.
 *                 -# Configure the output width and how the input lines are
 *                    written to external memory using the API
 *                    #VPFEOutputFormatConfig.
 *                 -# Set the output memory address corresponding to the VPFE
 *                    output buffer using the API #VPFESetBufAddr.
 *                 -# Enable the output(Enable writing of data to output memory)
 *                    using the API #VPFEOutputEnable.
 *              -# VPFE controller can be configured to perform some image
 *                 processing techniques on the input image. This configuration
 *                 is optional.
 *                 -# Optical Black clamping configuration:
 *                    -# If required enable and configure the optical black
 *                       clamping using the API #VPFEOptBlackClampingCfg.
 *                    -# If not required disable the optical black clamping
 *                       using the API #VPFEOptBlackClampingDisable
 *                 -# Black Level compensation:
 *                    -# Configure the black level compensation using the API
 *                       #VPFEBlackLvlCompensationCfg.
 *                    -# The processing is valid for "Raw mode" for other modes
 *                       all the values should be configured to zeros.
 *                 -# LowPassFilter(Anti Aliasing filter):
 *                    -# Enable or disable LPF using the API
 *                       #VPFELpfEnable.
 *                    -# This should be always disabled in YCbCr and BT.656
 *                       input modes.
 *                 -# ALaw compression:
 *                    -# If required, Enable and configure ALaw compression
 *                       using the API #VPFEAlawCompressionEnable.
 *                    -# If not required, disable ALaw compression using the
 *                       API #VPFEAlawCompressionDisable.
 *                    -# ALaw compression should be always disabled in the
 *                       YCbCr and BT.656 modes.
 *              -# Interrupt Configuration:
 *                 -# Configure the required interrupts of the VPFE controller
 *                    using the API #VPFESetIntrHSyncCnt.
 *                 -# Enable the required interrupts using the VPFE controller
 *                    using the API #VPFEIntrEnable.
 *                 -# Disable the non-required interrupts using the VPFE
 *                    controller using the API #VPFEIntrDisable
 *            -# Enable the VPFE controller using the API #VPFEModuleEnable.
 *               VPFE module will start capturing the data after this API is
 *               called.
 *            -# To stop capturing the data, following API has to be called
 *               with the second parameter value as 'FALSE':
 *               #VPFEModuleEnable.
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

#ifndef  VPFE_H_
#define  VPFE_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "hw_vpfe.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*                             Macros & Typedefs                              */
/* ========================================================================== */

/** \brief Number of lines in the CCD color pattern. */
#define VPFE_CCD_CLRPTN_LINES      (4U)

/** \brief Macro to set the end of interrupt bit. */
#define VPFE_INTR_SET_EOI          (1U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the supported VPFE input interface modes. */
typedef enum vpfeInputMode
{
    VPFE_INPUT_MODE_MIN   = 0U,
    /**< Minimum value of enumeration. Used for input validation. */
    VPFE_INPUT_MODE_RAW   = VPFE_INPUT_MODE_MIN,
    /**< Input mode is Raw mode. */
    VPFE_INPUT_MODE_YCBCR = 1U,
    /**< Input mode is digital YCbCr. */
    VPFE_INPUT_MODE_MAX   = VPFE_INPUT_MODE_YCBCR
    /**< Maximum value of enumeration. Used for input validation. */
}vpfeInputMode_t;


/** \brief Supported Field Modes. */
typedef enum vpfeFieldMode
{
    VPFE_FIELD_MODE_NON_INTERLACED = VPFE_SYNMODE_FLDMODE_NON_INTERLACED,
    /**< Field mode is Non-interlaced (Progressive). */
    VPFE_FIELD_MODE_INTERLACED  = VPFE_SYNMODE_FLDMODE_INTERLACED
    /**< Field mode is interlaced. */
}vpfeFieldMode_t;


/** \brief Enumerates the supported Input interface widths(bits per pixel) of
           VPFE controller. */
typedef enum vpfeInWidth
{
    VPFE_IN_WIDTH_16_BITS = VPFE_SYNMODE_DATSIZ_B16,
    /**< Input Width is 16 bits-per-pixel. */
    VPFE_IN_WIDTH_15_BITS = VPFE_SYNMODE_DATSIZ_B15,
    /**< Input Width is 15 bits-per-pixel. */
    VPFE_IN_WIDTH_14_BITS = VPFE_SYNMODE_DATSIZ_B14,
    /**< Input Width is 14 bits-per-pixel. */
    VPFE_IN_WIDTH_13_BITS = VPFE_SYNMODE_DATSIZ_B13,
    /**< Input Width is 13 bits-per-pixel. */
    VPFE_IN_WIDTH_12_BITS = VPFE_SYNMODE_DATSIZ_B12,
    /**< Input Width is 12 bits-per-pixel. */
    VPFE_IN_WIDTH_11_BITS = VPFE_SYNMODE_DATSIZ_B11,
    /**< Input Width is 11 bits-per-pixel. */
    VPFE_IN_WIDTH_10_BITS = VPFE_SYNMODE_DATSIZ_B10,
    /**< Input Width is 10 bits-per-pixel. */
    VPFE_IN_WIDTH_8_BITS  = VPFE_SYNMODE_DATSIZ_B8,
    /**< Input Width is 8 bits-per-pixel. */
}vpfeInWidth_t;


/** \brief Enumerates the supported output data width(bits per pixel). */
typedef enum vpfeOutDataWidth
{
    VPFE_OUT_DATA_WIDTH_8_BITS  = VPFE_SYNMODE_PACK8,
    /**< Output width is 8 bits per pixel. */
    VPFE_OUT_DATA_WIDTH_16_BITS = VPFE_SYNMODE_PACK8_NORMAL
    /**< Output width is 16 bits per pixel. */
}vpfeOutDataWidth_t;


/** \brief Polarities of the Input Data. */
typedef enum vpfeDataPolarity
{
    VPFE_DATA_POLARITY_NORMAL          = VPFE_SYNMODE_DATAPOL_NORMAL,
    /**< Input Data polarity is normal. */
    VPFE_DATA_POLARITY_ONES_COMPLEMENT = VPFE_SYNMODE_DATAPOL_ONES_COMPLEMENT
    /**< Input Data is Ones complement. */
}vpfeDataPolarity_t;


/** \brief Polarities of Horizontal synchronization signal. */
typedef enum vpfeHSyncPolarity
{
    VPFE_H_SYNC_POLARITY_POSITIVE = VPFE_SYNMODE_HDPOL_POSITIVE,
    /**< Horizontal sync polarity is positive. */
    VPFE_H_SYNC_POLARITY_NEGATIVE = VPFE_SYNMODE_HDPOL_NEGATIVE
    /**< Horizontal sync polarity is negative. */
}vpfeHSyncPolarity_t;


/** \brief Polarities of Vertical synchronization signal. */
typedef enum vpfeVSyncPolarity
{
    VPFE_V_SYNC_POLARITY_POSITIVE = VPFE_SYNMODE_VDPOL_POSITIVE,
    /**< Horizontal sync polarity is positive. */
    VPFE_V_SYNC_POLARITY_NEGATIVE = VPFE_SYNMODE_VDPOL_NEGATIVE
    /**< Horizontal sync polarity is negative. */
}vpfeVSyncPolarity_t;


/** \brief Polarities of field indication signal . */
typedef enum vpfeFldPolarity
{
    VPFE_FLD_POLARITY_POSITIVE = VPFE_SYNMODE_FLDPOL_POSITIVE,
    /**< Field indicator polarity is positive. */
    VPFE_FLD_POLARITY_NEGATIVE = VPFE_SYNMODE_FLDPOL_NEGATIVE
    /**< Field indicator polarity is negative. */
}vpfeFldPolarity_t;


/** \brief Direction of Sync signals. */
typedef enum vpfeVdHdDir
{
    VPFE_VDHD_DIR_INPUT  = VPFE_SYNMODE_VDHDOUT_INPUT,
    /**< Vsync and Hsync signals are input signals. */
    VPFE_VDHD_DIR_OUTPUT = VPFE_SYNMODE_VDHDOUT_OUTPUT
    /**< Vsync and Hsync signals are output signals. */
}vpfeVdHdDir_t;


/** \brief Direction of field identification signal . */
typedef enum vpfeFldDir
{
    VPFE_FLD_DIR_INPUT    = VPFE_SYNMODE_FLDOUT_INPUT,
    /**< Field identification signal is input signal. */
    VPFE_FLD_DIR_OUTPUT   = VPFE_SYNMODE_FLDOUT_OUTPUT,
    /**< Field identification signal is output signal. */
}vpfeFldDir_t;


/** \brief Control enums to swap the Y and C inputs in YCbCr 16-bit interface */
typedef enum vpfeYcInSwapCfg
{
    VPFE_YC_IN_SWAP_CFG_NOSWAP = 0U,
    /**< YIN[7:0] = Y signal/CIN[7:0] = C signal. */
    VPFE_YC_IN_SWAP_CFG_SWAP   = 1U
    /**< YIN[7:0] = C signal/CIN[7:0] = Y signal. */
}vpfeYcInSwapCfg_t;


/** \brief Positions of Y sample in YCbCr 8-bit interface mode. */
typedef enum vpfeY8Pos
{
    VPFE_Y8_POS_EVEN = VPFE_CCDCFG_Y8POS_EVEN,
    /**< Y sample is even pixel. */
    VPFE_Y8_POS_ODD  = VPFE_CCDCFG_Y8POS_ODD
    /**< Y sample is odd pixel. */
}vpfeY8Pos_t;


/** \brief Supported Optical black clamping sample lengths. Number of Optical
           Black Sample pixels per line to include in the average calculation */
typedef enum vpfeObSampleLen
{
    VPFE_OB_SAMPLE_LEN_1  = VPFE_CLAMP_OBSLEN_PIXEL1,
    /**< Optical black pixels per line are 1. */
    VPFE_OB_SAMPLE_LEN_2  = VPFE_CLAMP_OBSLEN_PIXEL2,
    /**< Optical black pixels per line are 2. */
    VPFE_OB_SAMPLE_LEN_4  = VPFE_CLAMP_OBSLEN_PIXEL4,
    /**< Optical black pixels per line are 4. */
    VPFE_OB_SAMPLE_LEN_8  = VPFE_CLAMP_OBSLEN_PIXEL8,
    /**< Optical black pixels per line are 8. */
    VPFE_OB_SAMPLE_LEN_16 = VPFE_CLAMP_OBSLEN_PIXEL16
    /**< Optical black pixels per line are 16. */
}vpfeObSampleLen_t;


/** \brief Number of Optical Black Sample lines to include in the average
           calculation. */
typedef enum vpfeObSampleLines
{
    VPFE_OB_SAMPLE_LINES_1  = VPFE_CLAMP_OBSLN_LINE1,
    /**< Number of Optical Black Sample lines are 1. */
    VPFE_OB_SAMPLE_LINES_2  = VPFE_CLAMP_OBSLN_LINE2,
    /**< Number of Optical Black Sample lines are 2. */
    VPFE_OB_SAMPLE_LINES_4  = VPFE_CLAMP_OBSLN_LINE4,
    /**< Number of Optical Black Sample lines are 4. */
    VPFE_OB_SAMPLE_LINES_8  = VPFE_CLAMP_OBSLN_LINE8,
    /**< Number of Optical Black Sample lines are 8. */
    VPFE_OB_SAMPLE_LINES_16 = VPFE_CLAMP_OBSLN_LINE16
    /**< Number of Optical Black Sample lines are 16. */
}vpfeObSampleLines_t;


/** \brief Types of supported color patterns for pixels. */
typedef enum vpfeColorPattern
{
    VPFE_COLOR_PATTERN_RYE   = VPFE_COLPTN_CP0LPC0_RYE,
    /**< Color pattern is Red/yellow. */
    VPFE_COLOR_PATTERN_GRCY  = VPFE_COLPTN_CP0LPC0_GRCY,
    /**< Color pattern is GreenRed/Cyan. */
    VPFE_COLOR_PATTERN_GBG   = VPFE_COLPTN_CP0LPC0_GBG,
    /**< Color pattern is Green/BlueGreen. */
    VPFE_COLOR_PATTERN_BMG   = VPFE_COLPTN_CP0LPC0_BMG
    /**< Color pattern is Blue/Magenta. */
}vpfeColorPattern_t;


/** \brief Enumerates the supported A-law input widths. */
typedef enum vpfeAlawInWidth
{
    VPFE_ALAW_IN_WIDTH_15_6 = VPFE_ALAW_GWDI_BITS15_6,
    /**< Input Width is in the range of 15 to 6 bits. */
    VPFE_ALAW_IN_WIDTH_14_5 = VPFE_ALAW_GWDI_BITS14_5,
    /**< Input Width is in the range of 14 to 5 bits. */
    VPFE_ALAW_IN_WIDTH_13_4 = VPFE_ALAW_GWDI_BITS13_4,
    /**< Input Width is in the range of 13 to 4 bits. */
    VPFE_ALAW_IN_WIDTH_12_3 = VPFE_ALAW_GWDI_BITS12_3,
    /**< Input Width is in the range of 12 to 3 bits. */
    VPFE_ALAW_IN_WIDTH_11_2 = VPFE_ALAW_GWDI_BITS11_2,
    /**< Input Width is in the range of 11 to 2 bits. */
    VPFE_ALAW_IN_WIDTH_10_1 = VPFE_ALAW_GWDI_BITS10_1,
    /**< Input Width is in the range of 10 to 1 bits. */
    VPFE_ALAW_IN_WIDTH_9_0 = VPFE_ALAW_GWDI_BITS9_0,
    /**< Input Width is in the range of 9 to 0 bits. */
}vpfeAlawInWidth_t;

/** \brief Enumerates the line offsets, which controls the way the output lines
  *        are written to the memory.
  *
  * \details Same macros are used for configuring the line offsets 0,1,2,3
  *          because the hardware auto-generated bit field macro values are
  *          same for all the line offsets.
  */
typedef enum vpfeLineOffsetVal
{
    VPFE_LINE_OFFSET_VAL_PLUS_1  = VPFE_SDOFST_LOFTS0_PLUS_L1,
    /**< Line offset value is +1 line. */
    VPFE_LINE_OFFSET_VAL_PLUS_2  = VPFE_SDOFST_LOFTS0_PLUS_L2,
    /**< Line offset value is +2 lines. */
    VPFE_LINE_OFFSET_VAL_PLUS_3  = VPFE_SDOFST_LOFTS0_PLUS_L3,
    /**< Line offset value is +3 lines. */
    VPFE_LINE_OFFSET_VAL_PLUS_4  = VPFE_SDOFST_LOFTS0_PLUS_L4,
    /**< Line offset value is +4 lines. */
    VPFE_LINE_OFFSET_VAL_MINUS_1 = VPFE_SDOFST_LOFTS0_MINUS_L1,
    /**< Line offset value is -1 line. */
    VPFE_LINE_OFFSET_VAL_MINUS_2 = VPFE_SDOFST_LOFTS0_MINUS_L2,
    /**< Line offset value is -2 lines. */
    VPFE_LINE_OFFSET_VAL_MINUS_3 = VPFE_SDOFST_LOFTS0_MINUS_L3,
    /**< Line offset value is -3 lines. */
    VPFE_LINE_OFFSET_VAL_MINUS_4 = VPFE_SDOFST_LOFTS0_MINUS_L4,
    /**< Line offset value is -4 lines. */
}vpfeLineOffsetVal_t;

/** \brief Enumerates the field offset, which controls the way the output fields
           are written to the memory. */
typedef enum vpfeFldOffsetVal
{
    VPFE_FLD_OFFSET_VAL_PLUS_1 = VPFE_SDOFST_FOFST_PLUS_L1,
    /**< Field offset value is +1 line. */
    VPFE_FLD_OFFSET_VAL_PLUS_2 = VPFE_SDOFST_FOFST_PLUS_L2,
    /**< Field offset value is +2 lines. */
    VPFE_FLD_OFFSET_VAL_PLUS_3 = VPFE_SDOFST_FOFST_PLUS_L3,
    /**< Field offset value is +3 lines. */
    VPFE_FLD_OFFSET_VAL_PLUS_4 = VPFE_SDOFST_FOFST_PLUS_L4,
    /**< Field offset value is +4 lines. */
}vpfeFldOffsetVal_t;


/** \brief  Type of interrupts supported by VPFE module. */
typedef enum vpfeIntrMask
{
    VPFE_INTR_MASK_VD0 = VPFE_IRQ_EN_SET_VD0_INT_MASK,
    /**< VD0 interrupt which is occurring relative to VSync. */
    VPFE_INTR_MASK_VD1 = VPFE_IRQ_EN_SET_VD1_INT_MASK,
    /**< VD0 interrupt which is occurring relative to VSync. */
    VPFE_INTR_MASK_VD2 = VPFE_IRQ_EN_SET_VD2_INT_MASK,
    /**< VD2 interrupt occurring at falling edge of the VDIN_WEN signal
         (via an external pin). */
    VPFE_INTR_MASK_ALL = (VPFE_IRQ_EN_SET_VD0_INT_MASK |                       \
        VPFE_IRQ_EN_SET_VD1_INT_MASK | VPFE_IRQ_EN_SET_VD2_INT_MASK)
    /**< Mask specifying all the interrupts. */
}vpfeIntrMask_t;


/** \brief Type of idle mode mechanisms. */
typedef enum vpfeIdleMode
{
    VPFE_IDLE_MODE_FORCE_IDLE = VPFE_SYSCONFIG_IDLEMODE_FORCE_IDLE,
    /**< Force Idle mode. */
    VPFE_IDLE_MODE_NO_IDLE = VPFE_SYSCONFIG_IDLEMODE_NO_IDLE,
    /**< No Idle mode. */
    VPFE_IDLE_MODE_SMART_IDLE = VPFE_SYSCONFIG_IDLEMODE_SMART_IDLE,
    /**< Smart Idle mode. */
    VPFE_IDLE_MODE_SMART_IDLE_WKUP =
        VPFE_SYSCONFIG_IDLEMODE_SMART_IDLE_WAKEUP_CAPABLE
    /**< Smart idle mode with wake up capable. */
}vpfeIdleMode_t;


/** \brief Types of Standby mode mechanisms. */
typedef enum vpfeStandbyMode
{
    VPFE_STANDBY_MODE_FORCE = VPFE_SYSCONFIG_STANDBYMODE_FORCE_STANDBY,
    /**< Force standby mode. */
    VPFE_STANDBY_MODE_NO = VPFE_SYSCONFIG_STANDBYMODE_NO_STANDBY,
    /**< No Standby mode. */
    VPFE_STANDBY_MODE_SMART = VPFE_SYSCONFIG_STANDBYMODE_SMART_STANDBY,
    /**< Smart standby mode. */
    VPFE_STANDBY_MODE_SMART_WKUP =
        VPFE_SYSCONFIG_STANDBYMODE_SMART_STANDBY_WAKEUP_CAPABLE
    /**< Smart standby mode with wakeup capable. */
}vpfeStandbyMode_t;


/** \brief Structure holding the sync signals timing information. */
typedef struct vpfeHvSyncCfg
{
    uint32_t hSyncPolarity;
    /**< Polarity of the Horizontal sync signal. This can take values from
         the following enum #vpfeHSyncPolarity_t. */
    uint32_t vSyncPolarity;
    /**< Polarity of the Vertical sync signal. This can take values from
         the following enum #vpfeVSyncPolarity_t. */
    uint32_t hvSyncDirection;
    /**< Direction of the H/V Sync signals. This can take values from
         the following enum #vpfeVdHdDir_t. */
}vpfeHvSyncCfg_t;


/** \brief Structure holding the configuration of input data lines when the
           input interface mode is Ycbcr(8 or 16 bits). */
typedef struct vpfeYcbcrLineInCfg
{
    uint32_t ycInSwap;
    /**< Swap Y and C data - 16 bit. This can take values from the following
         enum #vpfeYcInSwapCfg_t. */
    uint32_t y8Pos;
    /**< Position of Y data(8-bit) even or odd. This can take values from the
         following enum #vpfeY8Pos_t. */
}vpfeYcbcrLineInCfg_t;

/** \brief Structure holding the input interface configuration parameters. */
typedef struct vpfeInputCfg
{
    uint32_t inputMode;
    /**< VPFE input interface mode. This can take values from the following
         enum #vpfeInputMode_t. */
    uint32_t inputDataWidth;
    /**< Size(bit-width) of input data - always stored in LSBs. This can take
         values from the following enum #vpfeInWidth_t. */
    uint32_t inputDataPolarity;
    /**< Polarity of the input data. This can take value from the following
         enum #vpfeDataPolarity_t. */
    vpfeHvSyncCfg_t syncCfg;
    /**< Structure holding the polarity and direction configuration of
         H/V Sync signals. */
    vpfeYcbcrLineInCfg_t ycbcrInCfg;
    /**< Structure holding the data input line configurations when input mode
         is Ycbcr. */
    uint32_t fieldMode;
     /**< Input field mode. This can take value from the following enum
          #vpfeFieldMode_t. */
    uint32_t fieldDir;
    /**< Field direction information. This can take value from the following
         enum #vpfeFldDir_t. */
    uint32_t fieldPolarity;
    /**< Polarity of the field identification signal. This can take value from
         the following enum #vpfeFldPolarity_t. */
}vpfeInputCfg_t;


/** \brief Structure holding the Optical Black clamping configurations. */
typedef struct vpfeObClampCfg
{
    uint32_t obEnable;
    /**< Control flag to enable/disable optical black clamping. This can take
         following two macro values : TRUE or FALSE */
    uint32_t obSampleLength;
    /**< Number of Optical Black Sample pixels per line to include in the
         average calculation. This can take values from the following enum
         #vpfeObSampleLen_t. */
    uint32_t obSampleLines;
    /**< Number of Optical Black Sample lines to include in the average
         calculation. This can take values from the following enum
         #vpfeObSampleLines_t. */
    uint32_t obStartPixel;
    /**< The start pixel position of optical black samples, specified
         from the start of HD in pixel clocks. */
    uint32_t obgain;
    /**< Gain to apply to the optical black average. Multiply the optical black
         average with the specified gain. */
}vpfeObClampCfg_t;


/** \brief Color pattern of pixels corresponding to the single line. */
typedef struct vpfeColorPatternCfg
{
    uint32_t pixelCnt0;
    /**< Color pattern of pixel counter 0. This can take values from the
         following enum #vpfeColorPattern_t. */
    uint32_t pixelCnt1;
    /**< Color pattern of pixel counter 1. This can take values from the
         following enum #vpfeColorPattern_t. */
    uint32_t pixelCnt2;
    /**< Color pattern of pixel counter 2. This can take values from the
         following enum #vpfeColorPattern_t. */
    uint32_t pixelCnt3;
    /**< Color pattern of pixel counter 3. This can take values from the
         following enum #vpfeColorPattern_t. */
}vpfeColorPatternCfg_t;


/** \brief Structure holding the Black Compensation parameters. */
typedef struct vpfeBlkLvlCompensationCfg
{
    uint32_t enableBlkCompensation;
    /**<  User control flag to enable or disable Black compensation. This
          parameter can take following values: TRUE or FALSE. */
    int32_t rYe;
    /**< Black level compensation for R/Ye pixels. This can take values in the
         following range: -128 to +127. */
    int32_t grCy;
    /**< Black level compensation for Gr/Cy pixels. This can take values in the
         following range: -128 to +127. */
    int32_t gbG;
    /**< Black level compensation for Gb/G pixels. This can take values in the
         following range: -128 to +127. */
    int32_t bMg;
    /**< Black level compensation for B/Mg pixels. This can take values in the
         following range: -128 to +127. */
    vpfeColorPatternCfg_t clrPtn[VPFE_CCD_CLRPTN_LINES];
    /**< CCD color pattern configuration parameters. */
}vpfeBlkLvlCompensationCfg_t;


/** \brief Structure holding the Advanced image processing configurations. */
typedef struct vpfeAdvCfg
{
    vpfeObClampCfg_t obcCfg;
    /**< Structure holding the optical black clamping configurations. */
    uint32_t dcSubLvl;
    /**< DC level to subtract from input pixel data. */
    vpfeBlkLvlCompensationCfg_t blkCompensation;
    /**< Structure holding the black compensation configurations. */
    uint32_t lpfEnable;
    /**< User control flag to enable/disable Low pass filter operation. This
         can take following macro values : TRUE or FALSE */
    uint32_t alawEnable;
    /**< User Control flag to enable/disable A-Law compression. This can take
         following macros: TRUE or FALSE */
    uint32_t alawInWidth;
    /**< Width of input data to A-Law compression module. This can take values
         from the following enum #vpfeAlawInWidth_t. */
}vpfeAdvCfg_t;


/** \brief Structure holding the Output Frame resolution parameters. */
typedef struct vpfeOutputFrameResCfg
{
    uint32_t sph;
    /**< Horizontal Start pixel, that sets the pixel clock position at which
         data output to memory begins, measured from the start of HSync. */
    uint32_t nph;
    /**< Number of horizontal pixels, horizontal. The number of horizontal
         pixels that is output to memory are (nph + 1). */
    uint32_t slv0;
    /**< Vertical Start line for field 0, sets line at which data output to
         external memory will begin, measured from the start of VSync. */
    uint32_t slv1;
    /**< Vertical Start line for field 1, sets line at which data output to
         external memory will begin, measured from the start of VSync. */
    uint32_t nlv;
    /**< Number of vertical lines that will be output to memory. The number
         of lines output to memory = (nlv + 1). */
}vpfeOutputFrameResCfg_t;


/** \brief Structure holding the line offset configuration parameters which
           controls the way the data is written to the memory. */
typedef struct vpfeLineOffsetCfg
{
    uint32_t lnOffset;
    /**< Address offset for each line. This Sets offset for each output line in
         memory to either 16 or 32 pixels depending on setting of PACK8 */
    uint32_t fldOffset;
    /**< Line Offset value of field ID = 1. This can take values from the
         following enum #vpfeFldOffsetVal_t. */
    int32_t lnOffset0;
    /**< Line offset values of even line and even field ID = 0. This can take
         values from the following enum #vpfeLineOffsetVal_t. */
    int32_t lnOffset1;
    /**< Line offset values of odd line and even field ID = 0. This can take
         values from the following enum #vpfeLineOffsetVal_t. */
    int32_t lnOffset2;
    /**< Line offset values of even line and odd field ID = 1. This can take
         values from the following enum #vpfeLineOffsetVal_t. */
    int32_t lnOffset3;
    /**< Line offset values of odd line and odd field ID = 1. This can take
         values from the following enum #vpfeLineOffsetVal_t. */
}vpfeLineOffsetCfg_t;


/** \brief Structure holding the VPFE output configuration parameters. */
typedef struct vpfeOutputCfg
{
    vpfeOutputFrameResCfg_t frmCfg;
    /**< Output Frame resolution information. */
    uint32_t outDataSize;
    /**< Output Data size in bits. This can take values from the following
         enum #vpfeOutDataWidth_t. */
    uint32_t inverseImgEnable;
    /**< User control flag to inverse the received input image. This can take
         following two macro values: TRUE or FALSE */
    vpfeLineOffsetCfg_t lnOffsetCfg;
    /**< Structure holding the line offset configuration parameters. */
}vpfeOutputCfg_t;


/** \brief Structure holding the vpfe configuration parameters. */
typedef struct vpfeCfg
{
    vpfeInputCfg_t inputCfg;
    /**< vpfe input interface configuration parameters. */
    vpfeOutputCfg_t outputCfg;
    /**< vpfe output interface configuration parameters. */
}vpfeCfg_t;


/** \brief Structure holding the VPFE context register values. */
typedef struct vpfeContext
{
    uint32_t peripheralCtrl;
    /**< Peripheral control register value. */
    uint32_t sysConfig;
    /**< System configuration register value. */
    uint32_t synMode;
    /**< VPFE_SYNMODE register value. */
    uint32_t horzInfo;
    /**< VPFE_HORZ_INFO register value. */
    uint32_t vertStart;
    /**< VPFE_VERT_START register value. */
    uint32_t vertLines;
    /**< VPFE_VERT_LINES register value. */
    uint32_t culling;
    /**< VPFE_CULLING register value. */
    uint32_t hsizeOffset;
    /**< VPFE_HSIZE_OFF register value. */
    uint32_t sdOffset;
    /**< VPFE_SDOFST register value. */
    uint32_t sdrAddr;
    /**< VPFE_SDR_ADDR register value. */
    uint32_t clamp;
    /**< VPFE_CLAMP register value. */
    uint32_t dcSub;
    /**< VPFE_DCSUB register value. */
    uint32_t colPtn;
    /**< VPFE_COLPTN register value. */
    uint32_t blkCmp;
    /**< VPFE_BLKCMP register value. */
    uint32_t vdInt;
    /**< VPFE_VDINT register value. */
    uint32_t aLaw;
    /**< VPFE_ALAW register value. */
    uint32_t rec656If;
    /**< VPFE_REC656IF register value. */
    uint32_t ccdCfg;
    /**< VPFE_CCDCFG register value. */
    uint32_t irqEnSet;
    /**< VPFE_IRQ_EN_SET register value. */
}vpfeContext_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  This API returns the revision number, that uniquely identifies the
 *         specific revision of VPFE.
 *
 * \param  baseAddr    The memory address of the VPFE instance.
 *
 * \retval Revision    Revision information of the VPFE.
 *
 * \note   Revision information will contain the following information:
 *         -# BITS[10:8] - Major revision
 *         -# BITS[5:0]  - Minimum revision
 */
uint32_t VPFEGetRevision(uint32_t baseAddr);


/**
 * \brief  This API controls the enabling or disabling of VPFE module.
 *
 * \param  baseAddr    The memory address of the VPFE instance.
 * \param  enableVpfe  Flag to control the enable/disable of VPFE module.
 *         This can take following values.
 *         -# TRUE  - Enable VPFE module.
 *         -# FALSE - Disable VPFE module.
 */
void VPFEModuleEnable(uint32_t baseAddr, uint32_t enableVpfe);


/**
 * \brief  This API configures VPFE input interface to support RAW data mode.
 *
 * \details Raw data mode is a generic parallel interface that supports up to a
 *          16-bit(8-bit to 16-bit) data path to a CMOS or CCD sensor.
 *
 * \param  baseAddr        The memory address of the VPFE instance used.
 * \param  inputDataWidth  Width of input data, in bits per pixel(8 to 16 bits).
 *         This can take following enum values #vpfeInWidth_t.
 * \param  dataPolarity    Polarity of the input data. This can take values from
 *                         the following enum #vpfeDataPolarity_t.
 */
void VPFERawModeConfig(uint32_t baseAddr,
                       uint32_t inputDataWidth,
                       uint32_t dataPolarity);


/**
 * \brief  This API configures VPFE input interface to support digital YCbCr
 *         mode.
 *
 * \details The digital YCbCr interface supports either 8-bit or 16-bit devices.
 *          External Horizontal sync and vertical sync signals are required.
 *          An NTSC/PAL decoder is an example device that can be connected to
 *          the YCbCr interface.
 *
 * \param  baseAddr        The memory address of the VPFE instance used.
 * \param  inputDataWidth  Width of input data, in bits per pixel(8 or 16 bits).
 *         This can take only following two values.
 *         - #VPFE_IN_WIDTH_8_BITS
 *         - #VPFE_IN_WIDTH_16_BITS
 * \param  dataPolarity    Polarity of the input data. This can take values from
 *                         the following enum #vpfeDataPolarity_t.
 */
void VPFEYcbcrModeConfig(uint32_t baseAddr,
                         uint32_t inputDataWidth,
                         uint32_t dataPolarity);


/**
 * \brief  This API configures the interface parameters specific to the Ycbcr
 *         16 bit interface. This configures the position of Y and C samples in
 *         the 16-bit interface.
 *
 * \param  baseAddr        The memory address of the VPFE instance used.
 * \param  ycInSwap        Flag determining which byte of 16-bit data is Y and C
 *         This can take values from the following enum #vpfeYcInSwapCfg_t.
 */
void VPFEYcbcr16BitConfig(uint32_t baseAddr, uint32_t ycInSwap);


/**
 * \brief  This API configures interface parameters specific to the YcbCr 8 bit
 *         input interface. This API configures the Y pixel position(whether it
 *         is even or odd) and configures which 8bit lines are active input
 *         lines among the 16input lines.
 *
 * \param  baseAddr         The memory address of the VPFE instance used.
 * \param  activeInputLines Flag determining, Out of 16 input lines, which lines
 *                          [either YI[7:0] or CI[7:0]] are active and connected
 *                          to the input 8 bits.
 *         This can take values from the following enum #vpfeYcInSwapCfg_t.
 *
 * \param  y8Position  Location of Y signal when YCbCr 8bit data is input. This
 *         can take following values from following enum #vpfeY8Pos_t.
 */
void VPFEYcbcr8BitConfig(uint32_t baseAddr,
                         uint32_t activeInputLines,
                         uint32_t y8Position);


/**
 * \brief  This API configures synchronization signal timing parameters and
 *         direction.
 *
 * \param  baseAddr      The memory address of the VPFE instance.
 * \param  pSigCfg       Pointer to the structure #vpfeHvSyncCfg_t containing
 *                       the synchronization signal configurations.
 */
void VPFESyncSignalConfig(uint32_t baseAddr, vpfeHvSyncCfg_t *pSigCfg);


/**
 * \brief   This API configures the field mode corresponding to the input data.
 *
 * \param  baseAddr        The memory address of the VPFE instance.
 * \param  fieldMode       Input field mode. This can take values from the
 *                         following enum #vpfeFieldMode_t
 */
void VPFESetFieldMode(uint32_t baseAddr, uint32_t fieldMode);


/**
 * \brief  This API configures the field parameters corresponding to the
 *         interlaced field mode.
 *
 * \param  baseAddr        The memory address of the VPFE instance.
 * \param  fieldPolarity   Polarity of the field identification signal.
 *         This can take values from the following enum #vpfeFldPolarity_t.
 * \param  direction       Direction of the field signals.
 *         This can take values from the following enum #vpfeVdHdDir_t.
 */
void VPFEInterlacedFieldParamsCfg(uint32_t baseAddr,
                                  uint32_t fieldPolarity,
                                  uint32_t direction);


/**
 *  \brief  This API configures and enables the Optical Black clamping feature.
 *
 *  \details Sensor manufacturers typically provide some optically masked pixels
 *           at the beginning/end of each line to allow you to determine the
 *           noise floor on any given frame of data. The optical black clamping
 *           function provides a means to average the optically black pixels and
 *           subtract that value from each input pixel as the first step in
 *           reducing the noise on the input pixels.
 *
 *  \param  baseAddr   Memory address of VPFE instance.
 *  \param  inputMode  Input interface mode of VPFE controller. This can take
 *                     following enum values #vpfeInputMode_t;
 *  \param  dcSubLevel DC level to subtract from input pixel data.
 *  \param  pObcCfg    Pointer to the structure #vpfeObClampCfg_t containing the
 *                     Optical Black clamping configuration parameters.
 *
 *  \note   Please find the below notes:
 *          -# By default this feature is disabled.
 *          -# Configuration and enabling of Optical black clamping will be
 *             different based on the input mode as explained below:
 *           -# Raw Mode: All the configuration parameters inside the structure
 *              #vpfeObClampCfg_t should contain valid values for
 *              enabling the above operation and the parameter dcSubLevel is
 *              ignored. Users need to pass the value of 0U for dcSubLevel
 *              parameter.
 *           -# YCbCr Mode: dcSubLevel parameter value will be subtracted from
 *              the Y sample data. The parameter pObcCfg is ignored and should
 *              be passed as NULL.
 */
void VPFEOptBlackClampingCfg(uint32_t baseAddr,
                             uint32_t inputMode,
                             uint32_t dcSubLevel,
                             vpfeObClampCfg_t *pObcCfg);


/**
 *  \brief  This API disables the Optical Black clamping feature.
 *
 *  \details The Black clamping disable operation will be different based on the
 *           input mode as explained below:
 *           -# Raw Mode: Disable black clamp averaging (CLAMPEN bit in the
 *              CLAMP register) and select a constant black value "dcSubLevel"
 *              for subtraction (DCSUB bit in the DCSUB register) instead of
 *              using the calculated average value.
 *           -# YCbCr Mode: Set the dc subtraction value "dcSubLevel" to zero to
 *              disable the feature.
 *
 *  \param  baseAddr    Memory address of VPFE instance.
 *  \param  inputMode   Input interface mode of VPFE controller. This can take
 *                      following enum values #vpfeInputMode_t;
 *  \param  dcSubLevel  DC level to subtract from input pixel data.
 */
void VPFEOptBlackClampingDisable(uint32_t baseAddr,
                                 uint32_t inputMode,
                                 uint32_t dcSubLevel);


/**
 * \brief  This API configures the black level compensation parameters and also
 *         configures the type of color pattern.
 *
 * \param  baseAddr   The memory address of the VPFE instance.
 * \param  inputMode   Input interface mode of VPFE controller. This can take
 *                      following enum values #vpfeInputMode_t;
 * \param  pBlkCfg    Pointer to the structure #vpfeBlkLvlCompensationCfg_t
 *                    holding the black level compensation configuration
 *                    parameters.
 *
 *  \note  If the input mode is "YCbCr" then the parameter pBlkCfg is ignored
 *         and user shall pass NULL for this parameter.
 */
void VPFEBlackLvlCompensationCfg(uint32_t baseAddr,
                                 uint32_t inputMode,
                                 vpfeBlkLvlCompensationCfg_t *pBlkCfg);


/**
 *  \brief  This API configures the resolution of output frame by applying the
 *          framing selection to limit the processing area.
 *
 *  \param  baseAddr   Memory address of VPFE instance.
 *  \param  pCfg       Pointer to the structure #vpfeOutputFrameResCfg_t
 *                     containing the frame resolution parameters.
 */
void VPFEOutputFrameResConfig(uint32_t baseAddr, vpfeOutputFrameResCfg_t *pCfg);


/**
 *  \brief   This API enables/disables the low pass filter(anti-aliasing filter)
 *
 *  \details The low-pass filter consists of a simple 3-tap filter. Two pixels
 *           on the left and two pixels on the right of each line are cropped if
 *           the filter is enabled.
 *
 *  \param   baseAddr  Memory address of VPFE instance.
 *  \param   enableLpf Flag controlling enable/disable of low pass filter.
 *           This can take one of the following values.
 *           -# TRUE   - enable low pass filter.
 *           -# FALSE  - disable low pass filter.
 *
 *  \note    This API should not be called when the input mode is "YCbCr mode".
 */
void VPFELpfEnable(uint32_t baseAddr, uint32_t enableLpf);


/**
 *  \brief   This API enables the A-Law transformation technique and also sets
 *           the width of the input(bits).
 *
 *  \details Enabling the A-Law transformation technique causes the data width
 *           to reduce from 10 bits to 8 bits and allows packing to 8bits/pixel
 *           when saving external memory. Since the data resolution can be
 *           greater than 10 bits at this stage, input width must to be selected
 *           as 10 bits for input to the A-Law operation.
 *
 *  \param   baseAddr    Memory address of VPFE instance.
 *  \param   inputWidth  Width of data(bits) at the input of A-Law processing.
 *           This can take values from the following enum #vpfeAlawInWidth_t.
 *
 *  \note    This API should not be called when the input mode is "YCbCr mode".
 */
void VPFEAlawCompressionEnable(uint32_t baseAddr, uint32_t inputWidth);


/**
 *  \brief  This API disables the A-Law compression technique.
 *
 *  \param  baseAddr  Memory address of VPFE instance.
 *
 *  \note    This API should not be called when the input mode is "YCbCr mode".
 */
void VPFEAlawCompressionDisable(uint32_t baseAddr);


/**
 *  \brief  This API controls how the input pixel data is written to the output
 *          memory. This API configures the output data width, and also
 *          configures how the input fields are written to the output memory.
 *
 *  \param  baseAddr     Memory address of VPFE instance.
 *  \param  outputWidth  Width of output data, in bits per pixel(8/16 bits).
 *                       This can take values from the following enum
 *                       #vpfeOutDataWidth_t.
 *  \param  inverseImage Flag controls whether output image should be inverse of
 *                       input image or not. This can take following input macro
 *                       values:
 *                       - TRUE  - Inverse the image.
 *                       - FALSE - Normal image.
 *  \param  pLnOffsetCfg Pointer to the structure containing the output line
 *                       offset parameters.
 */
void VPFEOutputFormatConfig(uint32_t baseAddr,
                            uint32_t outputWidth,
                            uint32_t inverseImage,
                            vpfeLineOffsetCfg_t *pLnOffsetCfg);


/**
 *  \brief  This API sets the 32-bit memory address corresponding to the
 *          starting address of VPFE output buffer.
 *
 *  \details The detailed description is:
 *           -# This address register will be latched by VSync. This important
 *              feature provides a reliable way for programmers to modify the
 *              memory pointers in-between frames. For example, the VPFE
 *              interrupt service routine (ISR) can program the SDR_ADDR
 *              register to a new value before the end of the current frame.
 *              By doing so, the current frame is received without any
 *              interruption and the new external memory address (SDR_ADDR
 *              register) will be used for receiving the next frame.
 *           -# The address should be aligned on a 32-bit boundary. For optimal
 *              performance in the system, the address should be on a 256-byte
 *              boundary.
 *
 *  \param  baseAddr  Memory address of VPFE instance.
 *  \param  bufAddr   Address of VPFE output buffer(32-bit output memory).
 */
void VPFESetBufAddr(uint32_t baseAddr, uint32_t bufAddr);


/**
 * \brief   This API enables the VPFE output, i.e it enables the data write to
 *          output memory. If data write is not enabled, then image data will
 *          not be written to the output memory.
 *
 * \param  baseAddr     The memory address of the VPFE instance.
 */
void VPFEOutputEnable(uint32_t baseAddr);


/**
 * \brief   This API controls enabling or disabling of latching function
 *          registers on internal VSYNC.
 *
 * \details Please find the below detailed description:
 *          -# If this feature is enabled, changes to the all the register
 *             fields that are VSYNC latched will take effect at the start of a
 *             new frame (i.e., the changes are latched by the VDIN_VD signal).
 *             Reads from these registers/register fields will return the most
 *             recent write value (even though these values may not take effect)
 *          -# If this feature is disabled, then all the register fields that
 *             are VSYNC latched will take on new value immediately. Care should
 *             be taken not to alter fields that can cause undesired behaviour
 *             to the output data.
 *
 * \param  baseAddr     The memory address of the VPFE instance.
 * \param  enableLatch  Flag controlling the enable or disable. This can take
 *         following values:
 *         -# TRUE  - Enable latching on VSYNC
 *         -# FALSE - Disable latching on VSYNC and the effect will be immediate
 *
 * \note   By default the VSync latch is enabled.
 */
void VPFEInternalVSyncLatchEnable(uint32_t baseAddr, uint32_t enableLatch);


/**
 *  \brief  This API configures the number of horizontal signals required to
 *          generate VPFE interrupt. This API is also enables the generation of
 *          interrupts. This API is used to configure VDO and VD1 interrupts.
 *
 *  \param  baseAddr   Memory address of VPFE instance.
 *  \param  intrType   Type of the VPFE interrupt that needs to be configured.
 *          This can take following enum values
 *          - #VPFE_INTR_MASK_VD0
 *          - #VPFE_INTR_MASK_VD1
 *  \param  hSyncCnt   Number of HSyncs after which VPFE interrupt will occur.
 */
void VPFESetIntrHSyncCnt(uint32_t baseAddr,
                         uint32_t intrType,
                         uint32_t hSyncCnt);

/**
 * \brief  This API enables the specific interrupts of VPFE module.
 *
 * \param  baseAddr    The memory address of the VPFE instance.
 * \param  intrMask    The mask of interrupts which need to be enabled.
 *         This can take one or OR of more than one macro corresponding
 *         to the following enum #vpfeIntrMask_t.
 *
 * \note   To enable all the interrupts, following enum value should be passed
 *         #VPFE_INTR_MASK_ALL.
 */
void VPFEIntrEnable(uint32_t baseAddr, uint32_t intrMask);


/**
 * \brief  This API disables the specific interrupts of VPFE module.
 *
 * \param  baseAddr    The memory address of the VPFE instance.
 * \param  intrMask    The mask of interrupts which need to be disabled.
 *         This can take one or OR of more than one macro corresponding
 *         to the following enum #vpfeIntrMask_t.
 *
 * \note   To disable all the interrupts, following enum value should be passed
 *         - #VPFE_INTR_MASK_ALL.
 */
void VPFEIntrDisable(uint32_t baseAddr, uint32_t intrMask);


/**
 * \brief  This API clears the active status of specified VPFE interrupts.
 *
 * \param  baseAddr    The memory address of the VPFE instance.
 * \param  intrMask    The mask of interrupts whose status needs to be returned.
 *         This can take one or OR of more than one macro corresponding
 *         to the following enum #vpfeIntrMask_t.
 *
 * \note   To clear the status all the interrupts, following enum value should
 *         be passed #VPFE_INTR_MASK_ALL.
 */
void VPFEIntrClear(uint32_t baseAddr, uint32_t intrMask);


/**
 * \brief  This API returns the status of the all the VPFE interrupts.
 *
 * \param  baseAddr    The memory address of the VPFE instance.
 *
 * \retval intrStatus  The status of all the VPFE interrupts.
 *
 * \note   To get the status of selected interrupts user has to perform AND of
 *         return value with one of the following enum values #vpfeIntrMask_t.
 */
uint32_t VPFEIntrStatus(uint32_t baseAddr);


/**
 * \brief  This API returns the raw status of all the VPFE interrupts.
 *
 * \param  baseAddr   The memory address of the VPFE instance.
 *
 * \retval rawStatus  The raw status of the all the VPFE interrupts.
 *
 * \note   To get the status of selected interrupts user has to perform AND of
 *         return value with one of the following enum values #vpfeIntrMask_t.
 */
uint32_t VPFEIntrRawStatus(uint32_t baseAddr);


/**
 * \brief  This API sets the end of interrupt bit which indicates the processing
 *         of the current interrupt is finished.
 *
 * \param  baseAddr   The memory address of the VPFE instance.
 */
void VPFEIntrSetEoi(uint32_t baseAddr);


/**
 *  \brief  This API selects one of the idle mode operation mechanisms.
 *
 *  \param  baseAddr  Memory address of VPFE instance.
 *  \param  idleMode  Value which determines the type of idle mode mechanism.
 *          This can take values from the following enum #vpfeIdleMode_t.
 */
void VPFESetIdleMode(uint32_t baseAddr, uint32_t idleMode);


/**
 *  \brief  This API selects one of the standby mode operation mechanisms.
 *
 *  \param  baseAddr    Memory address of VPFE instance.
 *  \param  standbyMode Value which determines the type of standby mode
 *          mechanism. This can take values from the following enum
 *          #vpfeStandbyMode_t.
 */
void VPFESetStandbyMode(uint32_t baseAddr, uint32_t standbyMode);


/**
 * \brief   This API gets the status of VPFE module which indicates whether the
 *          module is busy or not.
 *
 * \details The BUSY status will be set, when the start of frame occurs. It
 *          automatically resets to 0 at the end of frame.
 *
 * \param   baseAddr    The memory address of the VPFE instance.
 *
 * \retval  TRUE  - Module is Busy.
 * \retval  FALSE - Module is not busy.
 */
uint32_t VPFEIsBusy(uint32_t baseAddr);


/**
 * \brief  This API stores the context of the VPFE registers.
 *
 * \param  baseAddr    The memory address of the VPFE instance.
 * \param  pCtx        pointer to the structure #vpfeContext_t holding the VPFE
 *                     context register values.
 */
void VPFEContextSave(uint32_t baseAddr, vpfeContext_t *pCtx);


/**
 * \brief   This API restores the context of VPFE registers.
 *
 * \param  baseAddr    The memory address of the VPFE instance.
 * \param  pCtx        pointer to the structure #vpfeContext_t holding the VPFE
 *                     context register values.
 */
void VPFEContextRestore(uint32_t baseAddr, vpfeContext_t *pCtx);

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef VPFE_H_ */
