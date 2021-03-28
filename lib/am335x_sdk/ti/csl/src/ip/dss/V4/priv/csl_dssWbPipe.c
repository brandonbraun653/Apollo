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
 *  \file csl_dssWbPipe.c
 *
 *  \brief File containing the DSS Write Back Pipe CSL FL APIs
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <ti/csl/csl_dss.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define CSL_DSS_WB_PIPE_NUM_SCALING_COEFF_0           ((uint32_t) 9U)

#define CSL_DSS_WB_PIPE_NUM_SCALING_COEFF_12          ((uint32_t) 16U)

#define CSL_DSS_WB_PIPE_NUM_SCALER_PHASES             ((uint32_t) 16U)

#define CSL_DSS_WB_PIPE_NUM_ENTRIES_DATA_FORMAT_TABLE \
    (sizeof (gDssWbPipeDataFmt) / sizeof (gDssWbPipeDataFmt[0]))

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/**
 *  \brief Scaler Coefficients for resizing input picture
 */
typedef struct
{
    int32_t firhc2;
    /**< HC2 Coefficient value */
    int32_t firhc1;
    /**< HC1 Coefficient value */
    int32_t firhc0;
    /**< HC0 Coefficient value */
} CSL_DssWbPipeScalerCoeff;

/**
 *  \brief Data formats are defined separately by FVID2 and DSS. This structure
 *         defines different values for a particular data format
 */
typedef struct
{
    uint32_t fvid2Format;
    /**< FVID2 Format. Refer #Fvid2_DataFormat for values */
    uint32_t dssFormat;
    /**< DSS data format */
} CSL_DssWbPipeDataFmt;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

static void CSL_dssWbPipeConvFvid2DataFmt(uint32_t fvid2Fmt, uint32_t *dssFmt);

static void CSL_dssWbPipeSetOutDataFmt(CSL_dss_wbRegs *wbRegs,
                                       uint32_t dataFmt);

static void CSL_dssWbPipeSetInputRes(CSL_dss_wbRegs *wbRegs,
                                     uint32_t width,
                                     uint32_t height);

static void CSL_dssWbPipeSetInputPos(CSL_dss_wbRegs *wbRegs,
                                     uint32_t xPosition,
                                     uint32_t yPosition);

static void CSL_dssWbPipeSetOutputRes(CSL_dss_wbRegs *wbRegs,
                                      uint32_t width,
                                      uint32_t height);

static void CSL_dssWbPipeSetWbMode(CSL_dss_wbRegs *wbRegs,
                                   uint32_t wbMode);

static void CSL_dssWbPipeCscEnable(CSL_dss_wbRegs *wbRegs,
                                   uint32_t cscEnable);

static void CSL_dssWbPipeAlphaEnable(CSL_dss_wbRegs *wbRegs,
                                     uint32_t alphaEnable);

static int32_t CSL_dssWbPipeGetRowInc(const CSL_dss_wbRegs *wbRegs,
                                      const CSL_DssWbPipeCfg *wbCfg,
                                      uint32_t *rowInc,
                                      uint32_t *rowIncUV);

static int32_t CSL_dssWbPipeUpdateFieldMergeVal(const CSL_DssWbPipeCfg *wbCfg,
                                                uint32_t *fieldMergedP1,
                                                uint32_t *fieldMergedP2);

static int32_t CSL_dssWbPipeGetRowIncYuvIntr(const CSL_dss_wbRegs *wbRegs,
                                             const CSL_DssWbPipeCfg *wbCfg,
                                             uint32_t pitchY,
                                             uint32_t width,
                                             uint32_t *rowInc);

static int32_t CSL_dssWbPipeGetRowIncYuvSp(const CSL_dss_wbRegs *wbRegs,
                                           const CSL_DssWbPipeCfg *wbCfg,
                                           uint32_t pitch,
                                           uint32_t width,
                                           uint32_t *rowInc);

static void CSL_dssWbPipeSetRowInc(CSL_dss_wbRegs *wbRegs,
                                   uint32_t rowInc,
                                   uint32_t rowIncUV);

static void CSL_dssWbPipeSetYUVAttrs(CSL_dss_wbRegs *wbRegs,
                                     uint32_t ccsFormat,
                                     uint32_t yuvAlign);

static const CSL_DssWbPipeScalerCoeff *CSL_dssWbPipeGetScalerCoeff(
                                                        uint32_t inSize,
                                                        uint32_t outSize,
                                                        uint32_t verticalTaps);

static void CSL_dssWbPipeGetChromaRes(uint32_t dataFormat,
                                      uint32_t width,
                                      uint32_t height,
                                      uint32_t *chromaWidth,
                                      uint32_t *chromaHeight);

static void CSL_dssWbPipeSetScalerCoeff(
                                CSL_dss_wbRegs *wbRegs,
                                const CSL_DssWbPipeScalerCoeff *vCoef,
                                const CSL_DssWbPipeScalerCoeff *hCoef,
                                const CSL_DssWbPipeScalerCoeff *vChromaCoef,
                                const CSL_DssWbPipeScalerCoeff *hChromaCoef);

static void CSL_dssWbPipeSetFir(CSL_dss_wbRegs *wbRegs,
                                uint32_t inSizeX,
                                uint32_t inSizeY,
                                uint32_t outSizeX,
                                uint32_t outSizeY);

static void CSL_dssWbPipeSetFir2(CSL_dss_wbRegs *wbRegs,
                                 uint32_t inSizeX,
                                 uint32_t inSizeY,
                                 uint32_t outSizeX,
                                 uint32_t outSizeY);

static void CSL_dssWbPipeVerticalTapsEnable(CSL_dss_wbRegs *wbRegs,
                                            uint32_t verticalTaps);

static void CSL_dssWbPipeScEnable(CSL_dss_wbRegs *wbRegs,
                                  uint32_t scEnable);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* Coefficients for BT601-5 RGB to YUV conversion */
static const CSL_DssCscCoeff gWbCscLimitedRangeCoeff = {
    CSL_DSS_CSC_RANGE_LIMITED,
     66,   129,    25,
    112,   -94,   -18,
    -38,   -74,   112,
      0,     0,     0,
    256,  2048,  2048
};

static const CSL_DssCscCoeff gWbCscFullRangeCoeff = {
    CSL_DSS_CSC_RANGE_FULL,
     77,   150,    29,
    131,  -110,   -21,
    -44,   -87,   131,
      0,     0,     0,
      0,  2048,  2048
};

/**
 * Scaler coefficient for different scaling ratios
 *
 */
static const CSL_DssWbPipeScalerCoeff gScalerCoefUpScale[
                                        CSL_DSS_WB_PIPE_NUM_SCALER_PHASES] =
{
    {0,   0, 512},
    {0,   0, 512},
    {0,  64, 448},
    {0,  64, 448},
    {0, 128, 384},
    {0, 128, 384},
    {0, 192, 320},
    {0, 192, 320},
    {0,   0, 256},
    {0,   0,   0},
    {0,   0,   0},
    {0,   0,   0},
    {0,   0,   0},
    {0,   0,   0},
    {0,   0,   0},
    {0,   0,   0},
};

static const CSL_DssWbPipeScalerCoeff gScalerCoefDownScaleM10[
                                        CSL_DSS_WB_PIPE_NUM_SCALER_PHASES] =
{
    {-16,  72, 400},
    {-20,  96, 398},
    {-24, 120, 396},
    {-28, 148, 384},
    {-32, 176, 372},
    {-34, 204, 354},
    {-36, 232, 336},
    {-34, 260, 312},
    {  0, -32, 288},
    {  0, -26, 312},
    {  0, -20, 336},
    { -2, -10, 354},
    { -4,   0, 372},
    { -8,  16, 384},
    {-12,  32, 396},
    {-14,  52, 398},
};

static const CSL_DssWbPipeScalerCoeff gScalerCoefDownScaleM14[
                                        CSL_DSS_WB_PIPE_NUM_SCALER_PHASES] =
{
    {- 8, 120, 288},
    {- 6, 134, 286},
    {- 4, 148, 284},
    {- 2, 164, 280},
    {  0, 180, 276},
    {  6, 194, 266},
    { 12, 208, 256},
    { 18, 220, 244},
    {  0,  24, 232},
    {- 2,  32, 244},
    {- 4,  40, 256},
    {- 6,  52, 266},
    {- 8,  64, 276},
    {- 8,  78, 280},
    {- 8,  92, 284},
    {- 8, 106, 286},
};

static const CSL_DssWbPipeScalerCoeff gScalerCoefDownScaleM19[
                                        CSL_DSS_WB_PIPE_NUM_SCALER_PHASES] =
{
    {12, 128, 232},
    {14, 140, 232},
    {16, 152, 232},
    {22, 160, 226},
    {28, 168, 220},
    {34, 176, 218},
    {40, 184, 216},
    {48, 192, 208},
    { 0,  56, 200},
    { 0,  64, 208},
    { 0,  72, 216},
    { 2,  82, 218},
    { 4,  92, 220},
    { 4, 100, 226},
    { 4, 108, 232},
    { 8, 118, 232},
};

static const CSL_DssWbPipeScalerCoeff gScalerCoefDownScaleM22[
                                        CSL_DSS_WB_PIPE_NUM_SCALER_PHASES] =
{
    {16, 132, 216},
    {20, 140, 216},
    {24, 148, 216},
    {30, 156, 214},
    {36, 164, 212},
    {42, 172, 208},
    {48, 180, 204},
    {56, 186, 198},
    { 0,  64, 192},
    { 0,  72, 198},
    { 0,  80, 204},
    { 2,  88, 208},
    { 4,  96, 212},
    { 8, 104, 214},
    {12, 112, 216},
    {14, 122, 216},
};

static const CSL_DssWbPipeScalerCoeff gScalerCoefDownScaleM26[
                                        CSL_DSS_WB_PIPE_NUM_SCALER_PHASES] =
{
    {24, 132, 200},
    {28, 138, 202},
    {32, 144, 204},
    {38, 152, 202},
    {44, 160, 200},
    {50, 166, 196},
    {56, 172, 192},
    {64, 178, 188},
    { 0,  72, 184},
    { 2,  80, 188},
    { 4,  88, 192},
    { 6,  94, 196},
    { 8, 100, 200},
    {12, 108, 202},
    {16, 116, 204},
    {20, 124, 202},
};

static const CSL_DssWbPipeScalerCoeff gScalerCoefDownScale3TapM10[
                                        CSL_DSS_WB_PIPE_NUM_SCALER_PHASES] =
{
    {0,  40, 432},
    {0,  62, 424},
    {0,  84, 416},
    {0, 110, 396},
    {0, 136, 376},
    {0, 166, 348},
    {0, 196, 320},
    {0, 226, 288},
    {0,   0, 256},
    {0,  -2,   0},
    {0,  -4,   0},
    {0,  -2,   0},
    {0,   0,   0},
    {0,   6,   0},
    {0,  12,   0},
    {0,  26,   0},
};

static const CSL_DssWbPipeScalerCoeff gScalerCoefDownScale3TapM14[
                                        CSL_DSS_WB_PIPE_NUM_SCALER_PHASES] =
{
    {0,  80, 352},
    {0, 100, 348},
    {0, 120, 344},
    {0, 142, 334},
    {0, 164, 324},
    {0, 186, 310},
    {0, 208, 296},
    {0, 232, 276},
    {0,   0, 256},
    {0,   4,   0},
    {0,   8,   0},
    {0,  16,   0},
    {0,  24,   0},
    {0,  36,   0},
    {0,  48,   0},
    {0,  64,   0},
};

static const CSL_DssWbPipeScalerCoeff gScalerCoefDownScale3TapM19[
                                        CSL_DSS_WB_PIPE_NUM_SCALER_PHASES] =
{
    {0,  96, 320},
    {0, 114, 318},
    {0, 132, 316},
    {0, 152, 310},
    {0, 172, 304},
    {0, 194, 292},
    {0, 216, 280},
    {0, 236, 268},
    {0,   0, 256},
    {0,   8,   0},
    {0,  16,   0},
    {0,  26,   0},
    {0,  36,   0},
    {0,  50,   0},
    {0,  64,   0},
    {0,  80,   0},
};

static const CSL_DssWbPipeScalerCoeff gScalerCoefDownScale3TapM22[
                                        CSL_DSS_WB_PIPE_NUM_SCALER_PHASES] =
{
    {0, 100, 312},
    {0, 118, 310},
    {0, 136, 308},
    {0, 156, 302},
    {0, 176, 296},
    {0, 196, 286},
    {0, 216, 276},
    {0, 236, 266},
    {0,   0, 256},
    {0,  10,   0},
    {0,  20,   0},
    {0,  30,   0},
    {0,  40,   0},
    {0,  54,   0},
    {0,  68,   0},
    {0,  84,   0},
};

static const CSL_DssWbPipeScalerCoeff gScalerCoefDownScale3TapM26[
                                        CSL_DSS_WB_PIPE_NUM_SCALER_PHASES] =
{
    {0, 104, 304},
    {0, 122, 300},
    {0, 140, 296},
    {0, 160, 292},
    {0, 180, 288},
    {0, 198, 282},
    {0, 216, 276},
    {0, 236, 266},
    {0,   0, 256},
    {0,  10,   0},
    {0,  20,   0},
    {0,  32,   0},
    {0,  44,   0},
    {0,  60,   0},
    {0,  76,   0},
    {0,  90,   0},
};

/* Table containing FVID2 data formats and corresponding DSS formats */
static const CSL_DssWbPipeDataFmt gDssWbPipeDataFmt[] = {
    {FVID2_DF_YUV422I_UYVY, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_YUV422_UYVY},
    {FVID2_DF_YUV422I_YUYV, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_YUV422_YUV2},
    {FVID2_DF_YUV422SP_UV,  CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_YUV422_NV12},
    {FVID2_DF_YUV420SP_UV, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_YUV420_NV12},
    {FVID2_DF_XBGR64_16161616,
                            CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_RGBX64_16161616},
    {FVID2_DF_BGRX64_16161616,
                            CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_XRGB64_16161616},
/*    {FVID2_DF_RGBX32_1010102,
                            CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_XBGR32_2101010},
    {FVID2_DF_BGRX32_1010102,
                            CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_XRGB32_2101010}, */
    {FVID2_DF_XRGB32_8888, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_BGRX32_8888},
    {FVID2_DF_XBGR24_8888, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_RGBX32_8888},
    {FVID2_DF_BGRX32_8888, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_XBGR32_8888},
    {FVID2_DF_BGRX24_8888, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_XRGB32_8888},
    {FVID2_DF_BGRX16_1555, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_XBGR16_1555},
    {FVID2_DF_BGRX16_5551, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_XRGB16_1555},
    {FVID2_DF_XBGR_4444, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_RGBX16_4444},
    {FVID2_DF_RGBX16_4444, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_XBGR16_4444},
    {FVID2_DF_BGRX_4444, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_XRGB16_4444},
    {FVID2_DF_RGB16_565_A8, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_BGR565A8},
    {FVID2_DF_BGR16_565_A8, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_RGB565A8},
    {FVID2_DF_ABGR64_16161616,
                            CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_RGBA64_16161616},
    {FVID2_DF_BGRA64_16161616,
                            CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_ARGB64_16161616},
/*    {FVID2_DF_RGBA32_1010102,
                            CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_ABGR32_2101010},
    {FVID2_DF_BGRA32_1010102,
                            CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_ARGB32_2101010},
    {FVID2_DF_RGB24_888, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_BGR24P_888}, */
    {FVID2_DF_BGR24_888, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_RGB24P_888},
    {FVID2_DF_ARGB32_8888, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_BGRA32_8888},
    {FVID2_DF_ABGR32_8888, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_RGBA32_8888},
    {FVID2_DF_RGBA32_8888, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_ABGR32_8888},
    {FVID2_DF_BGRA32_8888, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_ARGB32_8888},
    {FVID2_DF_BGRA16_1555, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_ABGR16_1555},
    {FVID2_DF_BGRA16_5551, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_ARGB16_1555},
    {FVID2_DF_RGB16_565, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_BGR16_565},
    {FVID2_DF_BGR16_565, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_RGB16_565},
    {FVID2_DF_ABGR16_4444, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_RGBA16_4444},
    {FVID2_DF_RGBA16_4444, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_ABGR16_4444},
    {FVID2_DF_BGRA16_4444, CSL_DSS_WB_ATTRIBUTES_FORMAT_VAL_ARGB16_4444}
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t CSL_dssWbPipeSetConfig(CSL_dss_wbRegs *wbRegs,
                               const CSL_DssWbPipeCfg *wbCfg)
{
    int32_t retVal = CSL_PASS;
    int32_t isInDataFmtRgb = FALSE;
    int32_t isOutDataFmtYuv = FALSE;
    int32_t isOutDataFmtRgb = FALSE;
    uint32_t dssFmt, verticalTaps;
    uint32_t scalerVal = CSL_DSS_WB_PIPE_SC_DISABLED;
    const CSL_DssWbPipeScalerCoeff *hCoeff, *vCoeff;
    const CSL_DssWbPipeScalerCoeff *hChromaCoeff, *vChromaCoeff;
    uint32_t rowInc = 0U, rowIncUV = 0U;
    uint32_t chromaInWidth, chromaInHeight;
    uint32_t chromaOutWidth, chromaOutHeight;

    /* Check if input format is ARGB48 */
    isInDataFmtRgb = Fvid2_isDataFmtRgb(wbCfg->inFmt.dataFormat);
    if(FALSE == isInDataFmtRgb)
    {
        retVal = CSL_EBADARGS;
    }

    if(CSL_PASS == retVal)
    {
        /* Get the row increment */
        retVal = CSL_dssWbPipeGetRowInc(wbRegs,
                                        wbCfg,
                                        &rowInc,
                                        &rowIncUV);
    }

    /* Configure WB pipe */
    if(CSL_PASS == retVal)
    {
        CSL_dssWbPipeSetRowInc(wbRegs,
                               rowInc,
                               rowIncUV);

        CSL_dssWbPipeConvFvid2DataFmt(wbCfg->outFmt.dataFormat, &dssFmt);
        CSL_dssWbPipeSetOutDataFmt(wbRegs, dssFmt);

        CSL_dssWbPipeSetInputRes(wbRegs,
                                 wbCfg->inFmt.width,
                                 wbCfg->inFmt.height);

        CSL_dssWbPipeSetInputPos(wbRegs,
                                 wbCfg->inPos.startX,
                                 wbCfg->inPos.startY);

        CSL_dssWbPipeSetOutputRes(wbRegs,
                                  wbCfg->outFmt.width,
                                  wbCfg->outFmt.height);

        CSL_dssWbPipeSetWbMode(wbRegs, wbCfg->wbMode);

        CSL_dssWbPipeAlphaEnable(wbRegs, wbCfg->alphaEnable);

        /* Check for YUV format and enable CSC */
        isOutDataFmtYuv = Fvid2_isDataFmtYuv(wbCfg->outFmt.dataFormat);

        if(TRUE == isOutDataFmtYuv)
        {
            if(CSL_DSS_CSC_RANGE_LIMITED == wbCfg->cscRange)
            {
                CSL_dssWbPipeSetCSCCoeff(wbRegs, &gWbCscLimitedRangeCoeff);
            }
            else
            {
                CSL_dssWbPipeSetCSCCoeff(wbRegs, &gWbCscFullRangeCoeff);
            }
            CSL_dssWbPipeCscEnable(wbRegs, TRUE);
            CSL_dssWbPipeSetYUVAttrs(wbRegs,
                                     wbCfg->outFmt.ccsFormat,
                                     wbCfg->yuvAlign);
        }
        else
        {
            CSL_dssWbPipeCscEnable(wbRegs, FALSE);
        }

        /* Calculate scaler val depending on width & height */
        if (TRUE == wbCfg->scEnable)
        {
            if(wbCfg->outFmt.width != wbCfg->inFmt.width)
            {
                scalerVal |= CSL_DSS_WB_PIPE_SC_ENABLED_H;
            }
            if(wbCfg->outFmt.height != wbCfg->inFmt.height)
            {
                scalerVal |= CSL_DSS_WB_PIPE_SC_ENABLED_V;
            }
        }

        /* Calculate scaler val depending on YUV format */
        if(TRUE == isOutDataFmtYuv)
        {
            if((FVID2_DF_YUV422I_YUYV == wbCfg->outFmt.dataFormat) ||
               (FVID2_DF_YUV422I_UYVY == wbCfg->outFmt.dataFormat) ||
               (FVID2_DF_YUV422SP_UV  == wbCfg->outFmt.dataFormat))
            {
                scalerVal |= CSL_DSS_WB_PIPE_SC_ENABLED_H;
            }
            if(FVID2_DF_YUV420SP_UV == wbCfg->outFmt.dataFormat)
            {
                scalerVal |= CSL_DSS_WB_PIPE_SC_ENABLED_H;
                scalerVal |= CSL_DSS_WB_PIPE_SC_ENABLED_V;
            }
        }

        if(CSL_DSS_WB_PIPE_SC_DISABLED != scalerVal)
        {
            /* Select scaler filter */
            isOutDataFmtRgb = Fvid2_isDataFmtRgb(wbCfg->outFmt.dataFormat);
            if((TRUE == isOutDataFmtRgb) && (wbCfg->outFmt.width > 2048U))
            {
                verticalTaps = CSL_DSS_WB_ATTRIBUTES_VERTICALTAPS_VAL_TAPS3;
            }
            else
            {
                verticalTaps = CSL_DSS_WB_ATTRIBUTES_VERTICALTAPS_VAL_TAPS5;
            }

            CSL_dssWbPipeGetChromaRes(wbCfg->inFmt.dataFormat,
                                      wbCfg->inFmt.width,
                                      wbCfg->inFmt.height,
                                      &chromaInWidth,
                                      &chromaInHeight);

            CSL_dssWbPipeGetChromaRes(wbCfg->outFmt.dataFormat,
                                      wbCfg->outFmt.width,
                                      wbCfg->outFmt.height,
                                      &chromaOutWidth,
                                      &chromaOutHeight);

            hCoeff = CSL_dssWbPipeGetScalerCoeff(wbCfg->inFmt.width,
                                                 wbCfg->outFmt.width,
                                                 verticalTaps);
            vCoeff = CSL_dssWbPipeGetScalerCoeff(wbCfg->inFmt.height,
                                                 wbCfg->outFmt.height,
                                                 verticalTaps);
            hChromaCoeff = CSL_dssWbPipeGetScalerCoeff(chromaInWidth,
                                                       chromaOutWidth,
                                                       verticalTaps);
            vChromaCoeff = CSL_dssWbPipeGetScalerCoeff(chromaInHeight,
                                                       chromaOutHeight,
                                                       verticalTaps);
            CSL_dssWbPipeSetScalerCoeff(wbRegs,
                                        vCoeff,
                                        hCoeff,
                                        vChromaCoeff,
                                        hChromaCoeff);
            CSL_dssWbPipeSetFir(wbRegs,
                                wbCfg->inFmt.width,
                                wbCfg->inFmt.height,
                                wbCfg->outFmt.width,
                                wbCfg->outFmt.height);
            CSL_dssWbPipeVerticalTapsEnable(wbRegs, verticalTaps);

            if((FVID2_DF_YUV422I_YUYV == wbCfg->inFmt.dataFormat) ||
               (FVID2_DF_YUV422I_UYVY == wbCfg->inFmt.dataFormat) ||
               (FVID2_DF_YUV422SP_UV  == wbCfg->inFmt.dataFormat))
            {
                CSL_dssWbPipeSetFir2(wbRegs,
                                     wbCfg->inFmt.width/2U,
                                     wbCfg->inFmt.height,
                                     wbCfg->outFmt.width,
                                     wbCfg->outFmt.height);
            }
            if(FVID2_DF_YUV420SP_UV == wbCfg->inFmt.dataFormat)
            {
                CSL_dssWbPipeSetFir2(wbRegs,
                                     wbCfg->inFmt.width/2U,
                                     wbCfg->inFmt.height/2U,
                                     wbCfg->outFmt.width,
                                     wbCfg->outFmt.height);
            }

            /* Enable scaler */
            CSL_dssWbPipeScEnable(wbRegs, scalerVal);
        }
    }

    return (retVal);
}

void CSL_dssWbPipeSetDmaConfig(CSL_dss_wbRegs *wbRegs,
                               const CSL_DssWbPipeDmaCfg *dmaCfg)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->BUF_THRESHOLD);
    CSL_FINS(regVal,
             DSS_WB_BUF_THRESHOLD_BUFLOWTHRESHOLD,
             dmaCfg->bufLowThreshold);
    CSL_FINS(regVal,
             DSS_WB_BUF_THRESHOLD_BUFHIGHTHRESHOLD,
             dmaCfg->bufHighThreshold);
    CSL_REG32_WR(&wbRegs->BUF_THRESHOLD, regVal);

    regVal = CSL_REG32_RD(&wbRegs->ATTRIBUTES);
    CSL_FINS(regVal,
             DSS_WB_ATTRIBUTES_ARBITRATION,
             dmaCfg->arbitration);
    CSL_FINS(regVal,
             DSS_WB_ATTRIBUTES_CAPTUREMODE,
             dmaCfg->frameCaptureRate);
    CSL_FINS(regVal,
             DSS_WB_ATTRIBUTES_IDLESIZE,
             dmaCfg->idleSize);
    CSL_FINS(regVal,
             DSS_WB_ATTRIBUTES_IDLENUMBER,
             dmaCfg->idleNumber);
    CSL_REG32_WR(&wbRegs->ATTRIBUTES, regVal);
}

void CSL_dssWbPipeSetCSCCoeff(CSL_dss_wbRegs *wbRegs,
                              const CSL_DssCscCoeff *coeff)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->CSC_COEF0);
    CSL_FINS(regVal, DSS_WB_CSC_COEF0_C00, ((uint32_t) coeff->c00));
    CSL_FINS(regVal, DSS_WB_CSC_COEF0_C01, ((uint32_t) coeff->c01));
    CSL_REG32_WR(&wbRegs->CSC_COEF0, regVal);

    regVal = CSL_REG32_RD(&wbRegs->CSC_COEF1);
    CSL_FINS(regVal, DSS_WB_CSC_COEF1_C02, ((uint32_t) coeff->c02));
    CSL_FINS(regVal, DSS_WB_CSC_COEF1_C10, ((uint32_t) coeff->c10));
    CSL_REG32_WR(&wbRegs->CSC_COEF1, regVal);

    regVal = CSL_REG32_RD(&wbRegs->CSC_COEF2);
    CSL_FINS(regVal, DSS_WB_CSC_COEF2_C11, ((uint32_t) coeff->c11));
    CSL_FINS(regVal, DSS_WB_CSC_COEF2_C12, ((uint32_t) coeff->c12));
    CSL_REG32_WR(&wbRegs->CSC_COEF2, regVal);

    regVal = CSL_REG32_RD(&wbRegs->CSC_COEF3);
    CSL_FINS(regVal, DSS_WB_CSC_COEF3_C20, ((uint32_t) coeff->c20));
    CSL_FINS(regVal, DSS_WB_CSC_COEF3_C21, ((uint32_t) coeff->c21));
    CSL_REG32_WR(&wbRegs->CSC_COEF3, regVal);

    regVal = CSL_REG32_RD(&wbRegs->CSC_COEF4);
    CSL_FINS(regVal, DSS_WB_CSC_COEF4_C22, ((uint32_t) coeff->c22));
    CSL_REG32_WR(&wbRegs->CSC_COEF4, regVal);

    regVal = CSL_REG32_RD(&wbRegs->CSC_COEF5);
    CSL_FINS(regVal,
             DSS_WB_CSC_COEF5_PREOFFSET1,
             ((uint32_t) coeff->preOffset1));
    CSL_FINS(regVal,
             DSS_WB_CSC_COEF5_PREOFFSET2,
             ((uint32_t) coeff->preOffset2));
    CSL_REG32_WR(&wbRegs->CSC_COEF5, regVal);

    regVal = CSL_REG32_RD(&wbRegs->CSC_COEF6);
    CSL_FINS(regVal,
             DSS_WB_CSC_COEF6_PREOFFSET3,
             ((uint32_t) coeff->preOffset3));
    CSL_FINS(regVal,
             DSS_WB_CSC_COEF6_POSTOFFSET1,
             ((uint32_t) coeff->postOffset1));
    CSL_REG32_WR(&wbRegs->CSC_COEF6, regVal);

    regVal = CSL_REG32_RD(&wbRegs->CSC_COEF7);
    CSL_FINS(regVal,
             DSS_WB_CSC_COEF7_POSTOFFSET2,
             ((uint32_t) coeff->postOffset2));
    CSL_FINS(regVal,
             DSS_WB_CSC_COEF7_POSTOFFSET3,
             ((uint32_t) coeff->postOffset3));
    CSL_REG32_WR(&wbRegs->CSC_COEF7, regVal);

    regVal = CSL_REG32_RD(&wbRegs->ATTRIBUTES);
    CSL_FINS(regVal, DSS_WB_ATTRIBUTES_FULLRANGE, coeff->cscRange);
    CSL_REG32_WR(&wbRegs->ATTRIBUTES, regVal);
}

void CSL_dssWbPipeSetBuffAddr(CSL_dss_wbRegs *wbRegs,
                              uint32_t field,
                              uint64_t baseAddrRGBY,
                              uint64_t baseAddrUV)
{
    uint32_t addrVal;

    if(FVID2_FID_TOP == field)
    {
        /* Set BA0 with least significant bits */
        addrVal = (uint32_t) baseAddrRGBY & CSL_DSS_WB_BA_0_BA_MASK;
        CSL_REG32_WR(&wbRegs->BA_0, addrVal);

        /* Set BA_EXT_0 with most significant bits */
        addrVal = (uint32_t) (baseAddrRGBY >> 32U) &
                    CSL_DSS_WB_BA_EXT_0_BA_EXT_MASK;
        CSL_REG32_WR(&wbRegs->BA_EXT_0, addrVal);

        if(0U != baseAddrUV)
        {
            /* Set BA_UV_0 with least significant bits */
            addrVal = (uint32_t) baseAddrUV & CSL_DSS_WB_BA_UV_0_BA_MASK;
            CSL_REG32_WR(&wbRegs->BA_UV_0, addrVal);

            /* Set BA_UV_EXT_0 with most significant bits */
            addrVal = (uint32_t) (baseAddrUV >> 32U) &
                        CSL_DSS_WB_BA_UV_EXT_0_BA_UV_EXT_MASK;
            CSL_REG32_WR(&wbRegs->BA_UV_EXT_0, addrVal);
        }
    }
    else /* FVID2_FID_BOTTOM == field */
    {
        /* Set BA1 with 32 least significant bits */
        addrVal = (uint32_t) baseAddrRGBY & CSL_DSS_WB_BA_1_BA_MASK;
        CSL_REG32_WR(&wbRegs->BA_1, addrVal);

        /* Set BA_EXT_1 with most significant bits */
        addrVal = (uint32_t) (baseAddrRGBY >> 32U) &
                    CSL_DSS_WB_BA_EXT_1_BA_EXT_MASK;
        CSL_REG32_WR(&wbRegs->BA_EXT_1, addrVal);

        if(0U != baseAddrUV)
        {
            /* Set BA_UV_1 with least significant bits */
            addrVal = (uint32_t) baseAddrUV & CSL_DSS_WB_BA_UV_1_BA_MASK;
            CSL_REG32_WR(&wbRegs->BA_UV_1, addrVal);

            /* Set BA_UV_EXT_1 with most significant bits */
            addrVal = (uint32_t) (baseAddrUV >> 32U) &
                      CSL_DSS_WB_BA_UV_EXT_1_BA_UV_EXT_MASK;
            CSL_REG32_WR(&wbRegs->BA_UV_EXT_1, addrVal);
        }
    }
}

void CSL_dssWbPipeEnable(CSL_dss_wbRegs *wbRegs, uint32_t enable)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->ATTRIBUTES);
    CSL_FINS(regVal,
             DSS_WB_ATTRIBUTES_ENABLE,
             enable);
    CSL_REG32_WR(&wbRegs->ATTRIBUTES, regVal);
}

void CSL_dssWbPipeSetMflagConfig(CSL_dss_wbRegs *wbRegs,
                                  const CSL_DssWbPipeMFlagCfg *mflagCfg)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->MFLAG_THRESHOLD);
    CSL_FINS(regVal,
             DSS_WB_MFLAG_THRESHOLD_LT_MFLAG,
             mflagCfg->thresholdLow);
    CSL_FINS(regVal,
             DSS_WB_MFLAG_THRESHOLD_HT_MFLAG,
             mflagCfg->thresholdHigh);
    CSL_REG32_WR(&wbRegs->MFLAG_THRESHOLD, regVal);
}

/* ========================================================================== */
/*                       Static Function Definitions                          */
/* ========================================================================== */

static void CSL_dssWbPipeConvFvid2DataFmt(uint32_t fvid2Fmt, uint32_t *dssFmt)
{
    uint32_t index = 0U;
    *dssFmt = FVID2_DF_XBGR24_8888;

    for(index = 0U;
        index <  CSL_DSS_WB_PIPE_NUM_ENTRIES_DATA_FORMAT_TABLE;
        index++)
    {
        if(fvid2Fmt == gDssWbPipeDataFmt[index].fvid2Format)
        {
            *dssFmt = gDssWbPipeDataFmt[index].dssFormat;
            break;
        }
    }
}

static void CSL_dssWbPipeSetOutDataFmt(CSL_dss_wbRegs *wbRegs,
                                       uint32_t dataFmt)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->ATTRIBUTES);
    CSL_FINS(regVal, DSS_WB_ATTRIBUTES_FORMAT, dataFmt);
    CSL_REG32_WR(&wbRegs->ATTRIBUTES, regVal);
}

static void CSL_dssWbPipeSetInputRes(CSL_dss_wbRegs *wbRegs,
                                     uint32_t width,
                                     uint32_t height)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->SIZE);
    CSL_FINS(regVal,
             DSS_WB_SIZE_SIZEX,
             width - 1U);
    CSL_FINS(regVal,
             DSS_WB_SIZE_SIZEY,
             height - 1U);
    CSL_REG32_WR(&wbRegs->SIZE, regVal);
}

static void CSL_dssWbPipeSetInputPos(CSL_dss_wbRegs *wbRegs,
                                     uint32_t xPosition,
                                     uint32_t yPosition)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->POSITION);
    CSL_FINS(regVal,
             DSS_WB_POSITION_POSX,
             xPosition);
    CSL_FINS(regVal,
             DSS_WB_POSITION_POSY,
             yPosition);
    CSL_REG32_WR(&wbRegs->POSITION, regVal);
}

static void CSL_dssWbPipeSetOutputRes(CSL_dss_wbRegs *wbRegs,
                                      uint32_t width,
                                      uint32_t height)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->PICTURE_SIZE);
    CSL_FINS(regVal,
             DSS_WB_PICTURE_SIZE_MEMSIZEX,
             width - 1U);
    CSL_FINS(regVal,
             DSS_WB_PICTURE_SIZE_MEMSIZEY,
             height - 1U);
    CSL_REG32_WR(&wbRegs->PICTURE_SIZE, regVal);
}

static void CSL_dssWbPipeSetWbMode(CSL_dss_wbRegs *wbRegs,
                                   uint32_t wbMode)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->ATTRIBUTES);
    CSL_FINS(regVal,
             DSS_WB_ATTRIBUTES_WRITEBACKMODE,
             wbMode);
    CSL_REG32_WR(&wbRegs->ATTRIBUTES, regVal);
}

static void CSL_dssWbPipeCscEnable(CSL_dss_wbRegs *wbRegs,
                                    uint32_t cscEnable)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->ATTRIBUTES);
    CSL_FINS(regVal,
             DSS_WB_ATTRIBUTES_COLORCONVENABLE,
             cscEnable);
    CSL_REG32_WR(&wbRegs->ATTRIBUTES, regVal);
}

static void CSL_dssWbPipeAlphaEnable(CSL_dss_wbRegs *wbRegs,
                                     uint32_t alphaEnable)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->ATTRIBUTES);
    CSL_FINS(regVal,
             DSS_WB_ATTRIBUTES_ALPHAENABLE,
             alphaEnable);
    CSL_REG32_WR(&wbRegs->ATTRIBUTES, regVal);
}

static int32_t CSL_dssWbPipeGetRowInc(const CSL_dss_wbRegs *wbRegs,
                                      const CSL_DssWbPipeCfg *wbCfg,
                                      uint32_t *rowInc,
                                      uint32_t *rowIncUV)
{
    int32_t retVal = CSL_PASS;
    uint32_t pitchY = 0U, pitchUV = 0U;
    uint32_t width, dataFormat;
    uint32_t fieldMergedP1 = FALSE, fieldMergedP2 = FALSE;

    if((NULL == wbRegs) ||
       (NULL == wbCfg) ||
       (NULL == rowInc) ||
       (NULL == rowIncUV))
    {
        retVal = CSL_EBADARGS;
    }
    if(CSL_PASS == retVal)
    {
        width = wbCfg->outFmt.width;
        dataFormat = wbCfg->outFmt.dataFormat;
        *rowInc = 0U;
        *rowIncUV = 0U;

        if ((int32_t) TRUE == Fvid2_isDataFmtRgb16bit(dataFormat))
        {
            pitchY = wbCfg->outFmt.pitch[FVID2_RGB_ADDR_IDX];
            if (pitchY < (width * 2U))
            {
                retVal = CSL_EBADARGS;
            }
            else
            {
                *rowInc = (pitchY - (width * 2U)) + 1U;
            }
        }
        else if ((int32_t) TRUE == Fvid2_isDataFmtRgb24bit(dataFormat))
        {
            pitchY = wbCfg->outFmt.pitch[FVID2_RGB_ADDR_IDX];
            if (pitchY < (width * 3U))
            {
                retVal = CSL_EBADARGS;
            }
            else
            {
                *rowInc = (pitchY - (width * 3U)) + 1U;
            }
        }
        else if ((int32_t) TRUE == Fvid2_isDataFmtRgb32bit(dataFormat))
        {
            pitchY = wbCfg->outFmt.pitch[FVID2_RGB_ADDR_IDX];
            if (pitchY < (width * 4U))
            {
                retVal = CSL_EBADARGS;
            }
            else
            {
                *rowInc = (pitchY - (width * 4U)) + 1U;
            }
        }
        else if ((int32_t) TRUE == Fvid2_isDataFmtRgb64bit(dataFormat))
        {
            pitchY = wbCfg->outFmt.pitch[FVID2_RGB_ADDR_IDX];
            if (pitchY < (width * 8U))
            {
                retVal = CSL_EBADARGS;
            }
            else
            {
                *rowInc = (pitchY - (width * 8U)) + 1U;
            }
        }
        else if ((int32_t) TRUE == Fvid2_isDataFmtYuv(dataFormat))
        {
            if((int32_t) TRUE == Fvid2_isDataFmtYuv422I(dataFormat))
            {
                pitchY = wbCfg->outFmt.pitch[FVID2_YUV_INT_ADDR_IDX];
                retVal = CSL_dssWbPipeGetRowIncYuvIntr(wbRegs,
                                                       wbCfg,
                                                       pitchY,
                                                       width,
                                                       rowInc);
            }
            else if (((int32_t) TRUE == Fvid2_isDataFmtYuv420Sp(dataFormat)) ||
                     ((int32_t) TRUE == Fvid2_isDataFmtYuv422Sp(dataFormat)))
            {
                pitchY = wbCfg->outFmt.pitch[FVID2_YUV_SP_Y_ADDR_IDX];
                pitchUV = wbCfg->outFmt.pitch[FVID2_YUV_SP_CBCR_ADDR_IDX];
                retVal = CSL_dssWbPipeGetRowIncYuvSp(wbRegs,
                                                     wbCfg,
                                                     pitchY,
                                                     width,
                                                     rowInc);

                retVal += CSL_dssWbPipeGetRowIncYuvSp(wbRegs,
                                                      wbCfg,
                                                      pitchUV,
                                                      width,
                                                      rowIncUV);
            }
            else
            {
                retVal = CSL_EBADARGS;
            }
        }
        else
        {
            retVal = CSL_EBADARGS;
        }

        retVal += CSL_dssWbPipeUpdateFieldMergeVal(wbCfg,
                                                   &fieldMergedP1,
                                                   &fieldMergedP2);

        /* For interlaced buffers we need to skip one line */
        if ((retVal == CSL_PASS) &&
            (FVID2_SF_INTERLACED == wbCfg->outFmt.scanFormat) &&
            (TRUE == fieldMergedP1))
        {
            *rowInc += pitchY;
        }
        if ((retVal == CSL_PASS) &&
            (FVID2_SF_INTERLACED == wbCfg->outFmt.scanFormat) &&
            (TRUE == fieldMergedP2))
        {
            *rowIncUV += pitchUV;
        }
    }

    return (retVal);
}

static int32_t CSL_dssWbPipeUpdateFieldMergeVal(const CSL_DssWbPipeCfg *wbCfg,
                                                uint32_t *fieldMergedP1,
                                                uint32_t *fieldMergedP2)
{
    int32_t retVal = CSL_PASS;
    uint32_t dataFormat = wbCfg->outFmt.dataFormat;

    if ((int32_t) TRUE == Fvid2_isDataFmtRgb(dataFormat))
    {
        *fieldMergedP1 = wbCfg->outFmt.fieldMerged[FVID2_RGB_ADDR_IDX];
    }
    else if((int32_t) TRUE == Fvid2_isDataFmtYuv422I(dataFormat))
    {
        *fieldMergedP1 = wbCfg->outFmt.fieldMerged[FVID2_YUV_INT_ADDR_IDX];
    }
    else if(((int32_t) TRUE == Fvid2_isDataFmtYuv420Sp(dataFormat)) ||
             ((int32_t) TRUE == Fvid2_isDataFmtYuv422Sp(dataFormat)))
    {
        *fieldMergedP1 = wbCfg->outFmt.fieldMerged[FVID2_YUV_SP_Y_ADDR_IDX];
        *fieldMergedP2 = wbCfg->outFmt.fieldMerged[FVID2_YUV_SP_CBCR_ADDR_IDX];
    }
    else
    {
        retVal = CSL_EBADARGS;
    }

    return (retVal);
}

static int32_t CSL_dssWbPipeGetRowIncYuvIntr(const CSL_dss_wbRegs *wbRegs,
                                             const CSL_DssWbPipeCfg *wbCfg,
                                             uint32_t pitchY,
                                             uint32_t width,
                                             uint32_t *rowInc)
{
    int32_t retVal = CSL_PASS;
    if((NULL == wbRegs) ||
       (NULL == wbCfg) ||
       (NULL == rowInc))
    {
        retVal = CSL_EBADARGS;
    }
    if(CSL_PASS == retVal)
    {
        if(FVID2_CCSF_BITS10_UNPACKED16 == wbCfg->outFmt.ccsFormat)
        {
            if (pitchY < (width * 4U))
            {
                retVal = CSL_EBADARGS;
            }
            else
            {
                *rowInc = (pitchY - (width * 4U)) + 1U;
            }
        }
        else if(FVID2_CCSF_BITS10_PACKED == wbCfg->outFmt.ccsFormat)
        {
            if ((pitchY < (uint32_t)((width * 16U)/6U)) ||
                (0U != (width%6U)))
            {
                retVal = CSL_EBADARGS;
            }
            else
            {
                *rowInc = (pitchY - (uint32_t)((width * 16U)/6U)) + 1U;
            }
        }
        else if(FVID2_CCSF_BITS8_PACKED == wbCfg->outFmt.ccsFormat)
        {
            if (pitchY < (width * 2U))
            {
                retVal = CSL_EBADARGS;
            }
            else
            {
                *rowInc = (pitchY - (width * 2U)) + 1U;
            }
        }
        else
        {
            retVal = CSL_EBADARGS;
        }
    }
    return retVal;
}

static int32_t CSL_dssWbPipeGetRowIncYuvSp(const CSL_dss_wbRegs *wbRegs,
                                           const CSL_DssWbPipeCfg *wbCfg,
                                           uint32_t pitch,
                                           uint32_t width,
                                           uint32_t *rowInc)
{
    int32_t retVal = CSL_PASS;
    if((NULL == wbRegs) ||
       (NULL == wbCfg) ||
       (NULL == rowInc))
    {
        retVal = CSL_EBADARGS;
    }
    if(CSL_PASS == retVal)
    {
        if(FVID2_CCSF_BITS10_UNPACKED16 == wbCfg->outFmt.ccsFormat)
        {
            if (pitch < (width * 2U))
            {
                retVal = CSL_EBADARGS;
            }
            else
            {
                *rowInc = (pitch - (width * 2U)) + 1U;
            }
        }
        else if(FVID2_CCSF_BITS10_PACKED == wbCfg->outFmt.ccsFormat)
        {
            if ((pitch < (uint32_t)((width * 8U)/6U)) ||
                (0U != (width%6U)))
            {
                retVal = CSL_EBADARGS;
            }
            else
            {
                *rowInc = (pitch - (uint32_t)((width * 8U)/6U)) + 1U;
            }
        }
        else if(FVID2_CCSF_BITS8_PACKED == wbCfg->outFmt.ccsFormat)
        {
            if (pitch < width)
            {
                retVal = CSL_EBADARGS;
            }
            else
            {
                *rowInc = (pitch - width) + 1U;
            }
        }
        else
        {
            retVal = CSL_EBADARGS;
        }
    }
    return retVal;
}

static void CSL_dssWbPipeSetRowInc(CSL_dss_wbRegs *wbRegs,
                                   uint32_t rowInc,
                                   uint32_t rowIncUV)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->ROW_INC);
    CSL_FINS(regVal,
             DSS_WB_ROW_INC_ROWINC,
             rowInc);
    CSL_REG32_WR(&wbRegs->ROW_INC, regVal);
    regVal = CSL_REG32_RD(&wbRegs->ROW_INC_UV);
    CSL_FINS(regVal,
             DSS_WB_ROW_INC_UV_ROWINC,
             rowIncUV);
    CSL_REG32_WR(&wbRegs->ROW_INC_UV, regVal);
}

static void CSL_dssWbPipeSetYUVAttrs(CSL_dss_wbRegs *wbRegs,
                                     uint32_t ccsFormat,
                                     uint32_t yuvAlign)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->ATTRIBUTES2);
    CSL_FINS(regVal,
             DSS_WB_ATTRIBUTES2_YUV_ALIGN,
             yuvAlign);
    if((FVID2_CCSF_BITS10_UNPACKED16 == ccsFormat) ||
       (FVID2_CCSF_BITS10_PACKED == ccsFormat))
    {
        if(FVID2_CCSF_BITS10_UNPACKED16 == ccsFormat)
        {
            CSL_FINS(regVal,
                     DSS_WB_ATTRIBUTES2_YUV_MODE,
                     CSL_DSS_WB_ATTRIBUTES2_YUV_MODE_VAL_UNPACKED);
        }
        else /* (FVID2_CCSF_BITS10_PACKED == ccsFormat) */
        {
            CSL_FINS(regVal,
                     DSS_WB_ATTRIBUTES2_YUV_MODE,
                     CSL_DSS_WB_ATTRIBUTES2_YUV_MODE_VAL_PACKED);
        }
        CSL_FINS(regVal,
                 DSS_WB_ATTRIBUTES2_YUV_SIZE,
                 CSL_DSS_WB_ATTRIBUTES2_YUV_SIZE_VAL_10B);
    }
    else /* FVID2_CCSF_BITS8_PACKED == ccsFormat */
    {
        CSL_FINS(regVal,
                 DSS_WB_ATTRIBUTES2_YUV_SIZE,
                 CSL_DSS_WB_ATTRIBUTES2_YUV_SIZE_VAL_8B);
    }

    CSL_REG32_WR(&wbRegs->ATTRIBUTES2, regVal);
}

static const CSL_DssWbPipeScalerCoeff *CSL_dssWbPipeGetScalerCoeff(
                                                        uint32_t inSize,
                                                        uint32_t outSize,
                                                        uint32_t verticalTaps)
{
    const CSL_DssWbPipeScalerCoeff *scCoeff = NULL;

    if (inSize <= outSize)
    {
        /* Upscaling coefficient. Common for all ratios */
        scCoeff = gScalerCoefUpScale;
    }
    else
    {
        /* DownScaling coefficient. Pick based on scaling ratio */
        if ((inSize > outSize) && (inSize <= ((outSize * 3U) / 2U)))
        {
            /* For scaling ratio of 1 to 1.5 pick M10 coeff */
            if (verticalTaps == CSL_DSS_WB_ATTRIBUTES_VERTICALTAPS_VAL_TAPS3)
            {
                scCoeff = gScalerCoefDownScale3TapM10;
            }
            else
            {
                scCoeff = gScalerCoefDownScaleM10;
            }
        }
        else if ((inSize > ((outSize * 3U) / 2U)) && (inSize <= (outSize * 2U)))
        {
            /* For scaling ratio of 1.5 to 2 pick M14 coeff */
            if (verticalTaps == CSL_DSS_WB_ATTRIBUTES_VERTICALTAPS_VAL_TAPS3)
            {
                scCoeff = gScalerCoefDownScale3TapM14;
            }
            else
            {
                scCoeff = gScalerCoefDownScaleM14;
            }
        }
        else if ((inSize > (outSize * 2U)) && (inSize <= ((outSize * 5U) / 2U)))
        {
            /* For scaling ratio of 2 to 2.5 pick M19 coeff */
            if (verticalTaps == CSL_DSS_WB_ATTRIBUTES_VERTICALTAPS_VAL_TAPS3)
            {
                scCoeff = gScalerCoefDownScale3TapM19;
            }
            else
            {
                scCoeff = gScalerCoefDownScaleM19;
            }
        }
        else if ((inSize > ((outSize * 5U) / 2U)) && (inSize <= (outSize * 3U)))
        {
            /* For scaling ratio of 2.5 to 3 pick M22 coeff */
            if (verticalTaps == CSL_DSS_WB_ATTRIBUTES_VERTICALTAPS_VAL_TAPS3)
            {
                scCoeff = gScalerCoefDownScale3TapM22;
            }
            else
            {
                scCoeff = gScalerCoefDownScaleM22;
            }
        }
        else if ((inSize > (outSize * 3U)) && (inSize <= (outSize * 4U)))
        {
            /* For scaling ratio of 3 to 4 pick M26 coeff */
            if (verticalTaps == CSL_DSS_WB_ATTRIBUTES_VERTICALTAPS_VAL_TAPS3)
            {
                scCoeff = gScalerCoefDownScale3TapM26;
            }
            else
            {
                scCoeff = gScalerCoefDownScaleM26;
            }
        }
        else
        {
            /* Use M22 coeff as default scaling coeff */
            if (verticalTaps == CSL_DSS_WB_ATTRIBUTES_VERTICALTAPS_VAL_TAPS3)
            {
                scCoeff = gScalerCoefDownScale3TapM22;
            }
            else
            {
                scCoeff = gScalerCoefDownScaleM22;
            }
        }
    }
    return scCoeff;
}

static void CSL_dssWbPipeGetChromaRes(uint32_t dataFormat,
                                      uint32_t width,
                                      uint32_t height,
                                      uint32_t *chromaWidth,
                                      uint32_t *chromaHeight)
{
    if (TRUE == Fvid2_isDataFmtRgb(dataFormat))
    {
        *chromaWidth  = width;
        *chromaHeight = height;
    }
    else if (TRUE == Fvid2_isDataFmtYuv(dataFormat))
    {
        if (TRUE == Fvid2_isDataFmtYuv422(dataFormat))
        {
            *chromaWidth  = width;
            *chromaHeight = height / 2U;
        }
        if (TRUE == Fvid2_isDataFmtYuv420(dataFormat))
        {
            *chromaWidth  = width / 2U;
            *chromaHeight = height / 2U;
        }
        else
        {
            *chromaWidth  = width;
            *chromaHeight = height;
        }
    }
    else
    {
        *chromaWidth  = 0U;
        *chromaHeight = 0U;
    }
}

static void CSL_dssWbPipeSetScalerCoeff(
                                CSL_dss_wbRegs *wbRegs,
                                const CSL_DssWbPipeScalerCoeff *vCoef,
                                const CSL_DssWbPipeScalerCoeff *hCoef,
                                const CSL_DssWbPipeScalerCoeff *vChromaCoef,
                                const CSL_DssWbPipeScalerCoeff *hChromaCoef)
{
    uint32_t regVal, index;

    for(index = 0U; index < CSL_DSS_WB_PIPE_NUM_SCALING_COEFF_0; index++)
    {
        regVal = CSL_REG32_RD(&wbRegs->FIR_COEF_H0[index]);
        CSL_FINS(regVal,
                 DSS_WB_FIR_COEF_H0_FIRHC0,
                 ((uint32_t) hCoef[index].firhc0));
        CSL_REG32_WR(&wbRegs->FIR_COEF_H0[index], regVal);

        regVal = CSL_REG32_RD(&wbRegs->FIR_COEF_H0_C[index]);
        CSL_FINS(regVal,
                 DSS_WB_FIR_COEF_H0_C_FIRHC0,
                 ((uint32_t) hChromaCoef[index].firhc0));
        CSL_REG32_WR(&wbRegs->FIR_COEF_H0_C[index], regVal);

        regVal = CSL_REG32_RD(&wbRegs->FIR_COEF_V0[index]);
        CSL_FINS(regVal,
                 DSS_WB_FIR_COEF_V0_FIRVC0,
                 ((uint32_t) vCoef[index].firhc0));
        CSL_REG32_WR(&wbRegs->FIR_COEF_V0[index], regVal);

        regVal = CSL_REG32_RD(&wbRegs->FIR_COEF_V0_C[index]);
        CSL_FINS(regVal,
                 DSS_WB_FIR_COEF_V0_C_FIRVC0,
                 ((uint32_t) vChromaCoef[index].firhc0));
        CSL_REG32_WR(&wbRegs->FIR_COEF_V0_C[index], regVal);
    }
    for(index = 0U; index < CSL_DSS_WB_PIPE_NUM_SCALING_COEFF_12; index++)
    {
        regVal = CSL_REG32_RD(&wbRegs->FIR_COEF_H12[index]);
        CSL_FINS(regVal,
                 DSS_WB_FIR_COEF_H12_FIRHC1,
                 ((uint32_t) hCoef[index].firhc1));
        CSL_FINS(regVal,
                 DSS_WB_FIR_COEF_H12_FIRHC2,
                 ((uint32_t) hCoef[index].firhc2));
        CSL_REG32_WR(&wbRegs->FIR_COEF_H12[index], regVal);

        regVal = CSL_REG32_RD(&wbRegs->FIR_COEF_H12_C[index]);
        CSL_FINS(regVal,
                 DSS_WB_FIR_COEF_H12_C_FIRHC1,
                 ((uint32_t) hChromaCoef[index].firhc1));
        CSL_FINS(regVal,
                 DSS_WB_FIR_COEF_H12_C_FIRHC2,
                 ((uint32_t) hChromaCoef[index].firhc2));
        CSL_REG32_WR(&wbRegs->FIR_COEF_H12_C[index], regVal);

        regVal = CSL_REG32_RD(&wbRegs->FIR_COEF_V12[index]);
        CSL_FINS(regVal,
                 DSS_WB_FIR_COEF_V12_FIRVC1,
                 ((uint32_t) vCoef[index].firhc1));
        CSL_FINS(regVal,
                 DSS_WB_FIR_COEF_V12_FIRVC2,
                 ((uint32_t) vCoef[index].firhc2));
        CSL_REG32_WR(&wbRegs->FIR_COEF_V12[index], regVal);

        regVal = CSL_REG32_RD(&wbRegs->FIR_COEF_V12_C[index]);
        CSL_FINS(regVal,
                 DSS_WB_FIR_COEF_V12_C_FIRVC1,
                 ((uint32_t) vChromaCoef[index].firhc1));
        CSL_FINS(regVal,
                 DSS_WB_FIR_COEF_V12_C_FIRVC2,
                 ((uint32_t) vChromaCoef[index].firhc2));
        CSL_REG32_WR(&wbRegs->FIR_COEF_V12_C[index], regVal);
    }
}

static void CSL_dssWbPipeSetFir(CSL_dss_wbRegs *wbRegs,
                                 uint32_t inSizeX,
                                 uint32_t inSizeY,
                                 uint32_t outSizeX,
                                 uint32_t outSizeY)
{
    uint32_t firHinc, firVinc, regVal;

    firHinc = (0x200000U * (inSizeX)) / (outSizeX);
    firVinc = (0x200000U * (inSizeY)) / (outSizeY);
    regVal = CSL_REG32_RD(&wbRegs->FIRH);
    CSL_FINS(regVal,
             DSS_WB_FIRH_FIRHINC,
             firHinc);
    CSL_REG32_WR(&wbRegs->FIRH, regVal);
    regVal = CSL_REG32_RD(&wbRegs->FIRV);
    CSL_FINS(regVal,
             DSS_WB_FIRV_FIRVINC,
             firVinc);
    CSL_REG32_WR(&wbRegs->FIRV, regVal);
}

static void CSL_dssWbPipeSetFir2(CSL_dss_wbRegs *wbRegs,
                                  uint32_t inSizeX,
                                  uint32_t inSizeY,
                                  uint32_t outSizeX,
                                  uint32_t outSizeY)
{
    uint32_t firHinc, firVinc, regVal;

    firHinc = (0x200000U * (inSizeX)) / (outSizeX);
    firVinc = (0x200000U * (inSizeY)) / (outSizeY);
    regVal = CSL_REG32_RD(&wbRegs->FIRH2);
    CSL_FINS(regVal,
             DSS_WB_FIRH2_FIRHINC,
             firHinc);
    CSL_REG32_WR(&wbRegs->FIRH2, regVal);
    regVal = CSL_REG32_RD(&wbRegs->FIRV2);
    CSL_FINS(regVal,
             DSS_WB_FIRV2_FIRVINC,
             firVinc);
    CSL_REG32_WR(&wbRegs->FIRV2, regVal);
}

static void CSL_dssWbPipeVerticalTapsEnable(CSL_dss_wbRegs *wbRegs,
                                             uint32_t verticalTaps)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->ATTRIBUTES);
    CSL_FINS(regVal,
             DSS_WB_ATTRIBUTES_VERTICALTAPS,
             verticalTaps);
    CSL_REG32_WR(&wbRegs->ATTRIBUTES, regVal);
}

static void CSL_dssWbPipeScEnable(CSL_dss_wbRegs *wbRegs,
                                   uint32_t scEnable)
{
    uint32_t regVal;

    regVal = CSL_REG32_RD(&wbRegs->ATTRIBUTES);
    CSL_FINS(regVal,
             DSS_WB_ATTRIBUTES_RESIZEENABLE,
             scEnable);
    CSL_REG32_WR(&wbRegs->ATTRIBUTES, regVal);
}
