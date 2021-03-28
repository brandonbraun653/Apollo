/*
 *  Copyright (c) Texas Instruments Incorporated 2018
 *  All rights reserved.
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
 *  \ingroup CSL_DSS
 *  \defgroup CSL_DSSWBPIPE DSS Write Back Pipe CSL FL
 *
 *  @{
 */

/**
 *  \file csl_dssWbPipe.h
 *
 *  \brief DSS Write Back Pipe CSL FL interface file
 */

#ifndef CSL_DSSWBPIPE_H_
#define CSL_DSSWBPIPE_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \anchor CSL_DssWbPipeYuvAlign
 *  \name   DSS Write Back Pipe YUV Alignment
 *  \brief  DSS Write Back Pipe alignment for unpacked YUV data
 *
 *  @{
 */
/** \brief Data is LSB aligned (MSB unused) */
#define CSL_DSS_WB_PIPE_YUV_ALIGN_LSB              \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES2_YUV_ALIGN_VAL_LSB)
/** \brief Data is MSB aligned (LSB unused) */
#define CSL_DSS_WB_PIPE_YUV_ALIGN_MSB              \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES2_YUV_ALIGN_VAL_MSB)
/* @} */

/**
 *  \anchor CSL_DssWbPipeScVal
 *  \name   DSS Write Back Pipe Scaler Value
 *
 *  @{
 */
/** \brief Scaler is disabled */
#define CSL_DSS_WB_PIPE_SC_DISABLED              \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_RESIZEENABLE_VAL_RESIZEPROC)
/** \brief Horizontal scaling is enabled */
#define CSL_DSS_WB_PIPE_SC_ENABLED_H             \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_RESIZEENABLE_VAL_HRESIZE)
/** \brief Vertical scaling is enabled */
#define CSL_DSS_WB_PIPE_SC_ENABLED_V             \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_RESIZEENABLE_VAL_VRESIZE)
/** \brief Both horizontal and vertical scaling is enabled */
#define CSL_DSS_WB_PIPE_SC_ENABLED_HV            \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_RESIZEENABLE_VAL_HVRESIZE)
/* @} */

/**
 *  \anchor CSL_DssWbPipePriorityVal
 *  \name   DSS Write Back Pipe Priority Value
 *
 *  @{
 */
/** \brief Priority of write back pipeline is normal */
#define CSL_DSS_WB_PIPE_PRIORITY_NORMAL       \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_ARBITRATION_VAL_NORMALPRIO)
/** \brief Priority of write back pipeline is high */
#define CSL_DSS_WB_PIPE_PRIORITY_HIGH         \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_ARBITRATION_VAL_HIGHPRIO)
/* @} */

/**
 *  \anchor CSL_DssWbPipeMode
 *  \name   DSS Write Back Pipe Mode
 *
 *  @{
 */
/** \brief Capture Write Back Mode */
#define CSL_DSS_WB_PIPE_MODE_CAPTURE       \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_WRITEBACKMODE_VAL_CAPTURE)
/** \brief Memory to memory mode */
#define CSL_DSS_WB_PIPE_MODE_M2M           \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_WRITEBACKMODE_VAL_MEM2MEM)
/* @} */

/**
 *  \anchor CSL_DssWbPipeCaptRate
 *  \name   DSS Write Back Pipe Capture Rate
 *
 *  @{
 */
/** \brief All frames are captured */
#define CSL_DSS_WB_PIPE_CAPT_RATE_ALL           \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_CAPTUREMODE_VAL_ALL)
/** \brief Only one frame is captured */
#define CSL_DSS_WB_PIPE_CAPT_RATE_1             \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_CAPTUREMODE_VAL_ONLY1)
/** \brief Only one out of two frames is captured */
#define CSL_DSS_WB_PIPE_CAPT_RATE_1_FROM_2      \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_CAPTUREMODE_VAL_ONLY1_2)
/** \brief Only one out of three frames is captured */
#define CSL_DSS_WB_PIPE_CAPT_RATE_1_FROM_3      \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_CAPTUREMODE_VAL_ONLY1_3)
/** \brief Only one out of four frames is captured */
#define CSL_DSS_WB_PIPE_CAPT_RATE_1_FROM_4      \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_CAPTUREMODE_VAL_ONLY1_4)
/** \brief Only one out of five frames is captured */
#define CSL_DSS_WB_PIPE_CAPT_RATE_1_FROM_5      \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_CAPTUREMODE_VAL_ONLY1_5)
/** \brief Only one out of six frames is captured */
#define CSL_DSS_WB_PIPE_CAPT_RATE_1_FROM_6      \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_CAPTUREMODE_VAL_ONLY1_6)
/** \brief Only one out of seven frames is captured */
#define CSL_DSS_WB_PIPE_CAPT_RATE_1_FROM_7      \
            ((uint32_t) CSL_DSS_WB_ATTRIBUTES_CAPTUREMODE_VAL_ONLY1_7)
/* @} */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/**
 *  \brief Configuration for DSS Write Back Pipe
 */
typedef struct
{
    Fvid2_Format inFmt;
    /**< Input format described using FVID2 frame format #Fvid2_Format
     *
     *   <b>width</b>:<br>
     *   Input width, in pixels
     *   This represents the input width to be programmed <br>
     *
     *   <b>height</b>:<br>
     *   Input height, in lines
     *   This represents the input height to be programmed <br>
     *
     *   <b>dataFormat</b>:<br>
     *   Input Data format, only FVID2_DF_ARGB48_12121212 is supported<br>
     *
     *   Other fields are not used, set to 0 or default */
    Fvid2_Format outFmt;
    /**< Output format described using FVID2 frame format #Fvid2_Format
     *
     *   <b>width</b>:<br>
     *   Output width, in pixels
     *   This represents the output width to be programmed <br>
     *
     *   <b>height</b>:<br>
     *   Output height, in lines
     *   This represents the output height to be programmed <br>
     *
     *   <b>pitch</b>:<br>
     *   Pitch in bytes between two lines
     *   Pitch can be specified separately for every plane <br>
     *
     *   <b>dataFormat</b>:<br>
     *   Output Data format, valid options are<br>
     *   FVID2_DF_YUV422I_UYVY,<br>
     *   FVID2_DF_YUV422I_YUYV,<br>
     *   FVID2_DF_YUV420SP_UV,<br>
     *   FVID2_DF_XBGR64_16161616,<br>
     *   FVID2_DF_BGRX64_16161616,<br>
     *   FVID2_DF_RGBX32_1010102,<br>
     *   FVID2_DF_BGRX32_1010102,<br>
     *   FVID2_DF_XRGB32_8888,<br>
     *   FVID2_DF_XBGR24_8888,<br>
     *   FVID2_DF_BGRX32_8888,<br>
     *   FVID2_DF_BGRX24_8888,<br>
     *   FVID2_DF_BGRX16_1555,<br>
     *   FVID2_DF_BGRX16_5551,<br>
     *   FVID2_DF_XBGR_4444,<br>
     *   FVID2_DF_RGBX16_4444,<br>
     *   FVID2_DF_BGRX_4444,<br>
     *   FVID2_DF_RGB16_565_A8,<br>
     *   FVID2_DF_BGR16_565_A8,<br>
     *   FVID2_DF_ABGR64_16161616,<br>
     *   FVID2_DF_BGRA64_16161616,<br>
     *   FVID2_DF_RGBA32_1010102,<br>
     *   FVID2_DF_BGRA32_1010102,<br>
     *   FVID2_DF_RGB24_888,<br>
     *   FVID2_DF_BGR24_888,<br>
     *   FVID2_DF_ARGB32_8888,<br>
     *   FVID2_DF_ABGR32_8888,<br>
     *   FVID2_DF_RGBA32_8888,<br>
     *   FVID2_DF_BGRA32_8888,<br>
     *   FVID2_DF_BGRA16_1555,<br>
     *   FVID2_DF_BGRA16_5551,<br>
     *   FVID2_DF_RGB16_565,<br>
     *   FVID2_DF_BGR16_565,<br>
     *   FVID2_DF_ABGR16_4444,<br>
     *   FVID2_DF_RGBA16_4444,<br>
     *   FVID2_DF_BGRA16_4444<br>
     *   For valid values see #Fvid2_DataFormat<br>
     *
     *   <b>scanFormat</b>:<br>
     *   Scan format, valid options are<br>
     *   FVID2_SF_INTERLACED,<br>
     *   FVID2_SF_PROGRESSIVE<br>
     *   For valid values see #Fvid2_ScanFormat<br>
     *
     *   <b>ccsFormat</b>:<br>
     *   Color component storage format, used only in case of YUV data
     *   Valid options are<br>
     *   FVID2_CCSF_BITS8_PACKED,<br>
     *   FVID2_CCSF_BITS10_PACKED,<br>
     *   FVID2_CCSF_BITS10_UNPACKED16<br>
     *   For valid values see #Fvid2_ColorCompStorageFmt<br>
     *
     *   <b>fieldMerged</b>:<br>
     *   Field Merged Flag for interlaced buffers, valid options are<br>
     *   TRUE,<br>
     *   FALSE<br>
     *
     *   <b>chNum</b>: Not used, set to 0 or default */
    Fvid2_PosConfig inPos;
    /**< Position of the picture at input of write back pipeline described using
     *   #Fvid2_PosConfig
     *
     *   <b>startX</b>:<br>
     *   X position of the Input
     *   The first pixel on the left of the screen has the X-position 0 <br>
     *
     *   <b>startY</b>:<br>
     *   Y position of the Input
     *   The line at the top has the Y-position 0 <br>
     */
    uint32_t wbMode;
    /**< Write back mode
     *   For valid values see \ref CSL_DssWbPipeMode */
    uint32_t yuvAlign;
    /**< Alignment for unpacked YUV data
     *   For valid values see \ref CSL_DssWbPipeYuvAlign */
    uint32_t cscRange;
    /**< Color Space Conversion range setting
     *   For valid values see \ref CSL_DssCscRange */
    uint32_t scEnable;
    /**< Enable the scaler, valid only if input and output size are different
     *   FALSE: Disable Scaler
     *   TRUE:  Enable Scaler */
    uint32_t alphaEnable;
    /**< Enable alpha on write back output
     *   FALSE: Alpha support is disabled
     *   TRUE:  Alpha support is enabled */
} CSL_DssWbPipeCfg;

/**
 *  \brief DSS Write Back Pipe DMA related Config parameters
 */
typedef struct
{
    uint32_t bufLowThreshold;
    /**< Write back DMA buffer low threshold. Number of 128 bits defining the
     *   threshold value */
    uint32_t bufHighThreshold;
    /**< Write back DMA buffer high threshold. Number of 128 bits defining the
     *   Threshold value */
    uint32_t arbitration;
    /**< Determines the priority of the write back pipeline.
     *   For valid values see \ref CSL_DssWbPipePriorityVal */
    uint32_t frameCaptureRate;
    /**< Frame capture rate of the write back pipeline.
     *   For valid values see \ref CSL_DssWbPipeCaptRate */
    uint32_t idleSize;
    /**< Determines if idleNumber corresponds to number of bursts or singles.
     *   Possible values are 0 or 1 */
    uint32_t idleNumber;
    /**< Determines the number of idles between requests on the L3 interconnect.
     *   Used only in memory to memory mode. Range depends on idleSize parameter
     *   Range: 0-15 when idleSize is 0
     *          0-120 when idleSize is 1 */
} CSL_DssWbPipeDmaCfg;

/**
 *  \brief DSS Write Back Pipe MFLAG Config parameters
 */
typedef struct
{
    uint32_t thresholdLow;
    /**<  Low threshold for mflag generation */
    uint32_t thresholdHigh;
    /**<  High threshold for mflag generation */
} CSL_DssWbPipeMFlagCfg;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief Configure the Write Back Pipe
 *
 *  \param wbRegs    Pointer to a CSL_dss_wbRegs structure
 *                   containing the Write Back Pipe configuration
 *  \param wbCfg     Pointer to the #CSL_DssWbPipeCfg structure.
 *                   This parameter should not be NULL
 *
 *  \return \ref CSL_ErrType_t
 */
int32_t CSL_dssWbPipeSetConfig(CSL_dss_wbRegs *wbRegs,
                               const CSL_DssWbPipeCfg *wbCfg);

/**
 *  \brief Configure the Write Back Pipe DMA parameters
 *
 *  \param wbRegs    Pointer to a CSL_dss_wbRegs structure
 *                   containing the Write Back Pipe configuration
 *  \param dmaCfg    Pointer to the #CSL_DssWbPipeDmaCfg structure.
 *                   This parameter should not be NULL
 *
 *  \return None
 */
void CSL_dssWbPipeSetDmaConfig(CSL_dss_wbRegs *wbRegs,
                               const CSL_DssWbPipeDmaCfg *dmaCfg);

/**
 *  \brief Configure the coefficients for Color Space Conversion
 *
 *  \param wbRegs    Pointer to a CSL_dss_wbRegs structure
 *                   containing the Write Back Pipe configuration
 *  \param coeff     Pointer to #CSL_DssCscCoeff structure.
 *                   This parameter should not be NULL
 *
 *  \return None
 */
void CSL_dssWbPipeSetCSCCoeff(CSL_dss_wbRegs *wbRegs,
                              const CSL_DssCscCoeff *coeff);

/**
 *  \brief Set the write back buffer address
 *
 *  \param wbRegs        Pointer to a CSL_dss_wbRegs structure
 *                       containing the Write Back Pipe configuration
 *  \param field         Top or bottom field. Refer #Fvid2_Fid for values.
 *                       Top is even field and Bottom is odd
 *  \param baseAddrRGBY  Base address of RGB or Y plane depending on format
 *  \param baseAddrUV    UV base address valid only for YUV420-NV12/NV21
 *
 *  \return None
 */
void CSL_dssWbPipeSetBuffAddr(CSL_dss_wbRegs *wbRegs,
                              uint32_t field,
                              uint64_t baseAddrRGBY,
                              uint64_t baseAddrUV);

/**
 *  \brief Enable the DSS Write Back Pipe
 *
 *  \param wbRegs    Pointer to a CSL_dss_wbRegs structure
 *                   containing the Write Back Pipe configuration
 *  \param enable    Enable or disable the Write Back Pipe
 *                   TRUE: Enable FALSE: Disable
 *
 *  \return None
 */
void CSL_dssWbPipeEnable(CSL_dss_wbRegs *wbRegs, uint32_t enable);

/**
 *  \brief Set the MFLAG configuration
 *
 *  \param wbRegs    Pointer to a CSL_dss_wbRegs structure
 *                   containing the Write Back Pipe configuration
 *  \param mflagCfg  Pointer to #CSL_DssWbPipeMFlagCfg structure.
 *                   This parameter should not be NULL
 *
 *  \return None
 */
void CSL_dssWbPipeSetMflagConfig(CSL_dss_wbRegs *wbRegs,
                                 const CSL_DssWbPipeMFlagCfg *mflagCfg);

/* ========================================================================== */
/*                      Static Function Declarations                          */
/* ========================================================================== */

/**
 *  \brief  CSL_DssWbPipeCfg structure init function
 *
 *  \param  wbCfg  Pointer to #CSL_DssWbPipeCfg structure
 *
 *  \return None
 */
static inline void CSL_dssWbPipeCfgInit(
    CSL_DssWbPipeCfg *wbCfg);

/**
 *  \brief  CSL_DssWbPipeDmaCfg structure init function
 *
 *  \param  dmaCfg Pointer to #CSL_DssWbPipeDmaCfg structure
 *
 *  \return None
 */
static inline void CSL_dssWbPipeDmaCfgInit(
    CSL_DssWbPipeDmaCfg *dmaCfg);

/**
 *  \brief  CSL_DssWbPipeMFlagCfg structure init function
 *
 *  \param  mflagCfg Pointer to #CSL_DssWbPipeMFlagCfg structure
 *
 *  \return None
 */
static inline void CSL_dssWbPipeMFlagCfgInit(
    CSL_DssWbPipeMFlagCfg *mflagCfg);

/* ========================================================================== */
/*                       Static Function Definitions                          */
/* ========================================================================== */

static inline void CSL_dssWbPipeCfgInit(
    CSL_DssWbPipeCfg *wbCfg)
{
    if(NULL != wbCfg)
    {
        Fvid2Format_init(&wbCfg->inFmt);
        Fvid2Format_init(&wbCfg->outFmt);
        Fvid2PosConfig_init(&wbCfg->inPos);
        wbCfg->wbMode      = CSL_DSS_WB_PIPE_MODE_CAPTURE;
        wbCfg->yuvAlign    = CSL_DSS_WB_PIPE_YUV_ALIGN_LSB;
        wbCfg->cscRange    = CSL_DSS_CSC_RANGE_FULL;
        wbCfg->scEnable    = FALSE;
        wbCfg->alphaEnable = FALSE;
    }
}

static inline void CSL_dssWbPipeDmaCfgInit(
    CSL_DssWbPipeDmaCfg *dmaCfg)
{
    if(NULL != dmaCfg)
    {
        dmaCfg->bufLowThreshold  = 0x08U;
        dmaCfg->bufHighThreshold = 0x16U;
        dmaCfg->arbitration      = CSL_DSS_WB_PIPE_PRIORITY_NORMAL;
        dmaCfg->frameCaptureRate = CSL_DSS_WB_PIPE_CAPT_RATE_ALL;
        dmaCfg->idleSize         = 0x0U;
        dmaCfg->idleNumber       = 0x0U;
    }
}

static inline void CSL_dssWbPipeMFlagCfgInit(
    CSL_DssWbPipeMFlagCfg *mflagCfg)
{
    if(NULL != mflagCfg)
    {
        mflagCfg->thresholdLow  = 0U;
        mflagCfg->thresholdHigh = 0U;
    }
}

#ifdef __cplusplus
}
#endif

#endif /* #ifndef CSL_DSSWBPIPE_H_ */

/* @} */
