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
 *  \ingroup CSL_IP_MODULE
 *  \defgroup CSL_DSS DSS CSL-FL
 *
 *  @{
 *
 * The Display Subsystem (DSS) provides the logic to interface display
 * peripherals. DSS has multiple hardware blocks and in order to simplify DSS
 * programming, DSS CSL FL driver has been logically divided into following
 * modules:
 * - <b> DSS Top        </b> (See \ref CSL_DSSTOP) <br>
 * - <b> DSS Common     </b> (See \ref CSL_DSSCOMMON) <br>
 * - <b> DSS Video Pipe </b> (See \ref CSL_DSSVIDEOPIPE) <br>
 * - <b> DSS Overlay    </b> (See \ref CSL_DSSOVERLAY)   <br>
 * - <b> DSS Video Port </b> (See \ref CSL_DSSVIDEOPORT) <br>
 * - <b> DSS WB Pipe    </b> (See \ref CSL_DSSWBPIPE) <br>
 */
 /** @} */

/**
 *  \ingroup CSL_DSS
 *  \defgroup CSL_DSSTOP Top Level CSL FL
 *            This can be used across sub component CSL FLs of DSS
 *
 *  @{
 */

/**
 *  \file csl_dssTop.h
 *
 *  \brief DSS Top CSL FL interface file
 */

#ifndef CSL_DSSTOP_H_
#define CSL_DSSTOP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/csl/soc.h>
#include <ti/csl/csl_fvid2_dataTypes.h>
#include <ti/csl/cslr_dss.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \anchor CSL_DssVidPipeType
 *  \name   DSS Video Pipeline Type
 *  \brief  To distinguish between VID (with scaler) and VIDL (without scaler)
 *
 *  @{
 */
/** \brief Video Pipe is of type VID */
#define CSL_DSS_VID_PIPE_TYPE_VID                   ((uint32_t) 0x0)
/** \brief Video Pipe is of type VIDL */
#define CSL_DSS_VID_PIPE_TYPE_VIDL                  ((uint32_t) 0x1)
/* @} */

/**
 *  \anchor CSL_DssCommRegId
 *  \name   DSS Common Region Id
 *  \brief  Id for different Common Regions
 *
 *  @{
 */
/** \brief Common Region 0 i.e. M region */
#define CSL_DSS_COMM_REG_ID_0                       ((uint32_t) 0x0U)
/** \brief Common Region 1 i.e. S0 region */
#define CSL_DSS_COMM_REG_ID_1                       ((uint32_t) 0x1U)
/** \brief Common Region 2 i.e. S1 region */
#define CSL_DSS_COMM_REG_ID_2                       ((uint32_t) 0x2U)
/** \brief Common Region 3 i.e. S2 region */
#define CSL_DSS_COMM_REG_ID_3                       ((uint32_t) 0x3U)
/** \brief Common Region Max Id */
#define CSL_DSS_COMM_REG_ID_MAX                     ((uint32_t) 0x4U)
/* @} */

/**
 *  \anchor CSL_DssVidPipeId
 *  \name   DSS Video Pipeline Id
 *  \brief  Id for different Video Pipelines
 *
 *  @{
 */
/** \brief Video Pipeline 1 */
#define CSL_DSS_VID_PIPE_ID_VID1                    ((uint32_t) 0x0U)
/** \brief Video Lite Pipeline 1 */
#define CSL_DSS_VID_PIPE_ID_VIDL1                   ((uint32_t) 0x1U)
/** \brief Video Pipeline 2 */
#define CSL_DSS_VID_PIPE_ID_VID2                    ((uint32_t) 0x2U)
/** \brief Video Lite Pipeline 2 */
#define CSL_DSS_VID_PIPE_ID_VIDL2                   ((uint32_t) 0x3U)
/** \brief Video Pipeline Max Id */
#define CSL_DSS_VID_PIPE_ID_MAX                     ((uint32_t) 0x4U)
/* @} */

/**
 *  \anchor CSL_DssOverlayId
 *  \name   DSS Overlay Id
 *  \brief  Id for DSS Overlays
 *
 *  @{
 */
/** \brief Overlay 1 */
#define CSL_DSS_OVERLAY_ID_1                        ((uint32_t) 0x0U)
/** \brief Overlay 2 */
#define CSL_DSS_OVERLAY_ID_2                        ((uint32_t) 0x1U)
/** \brief Overlay 3 */
#define CSL_DSS_OVERLAY_ID_3                        ((uint32_t) 0x2U)
/** \brief Overlay 4 */
#define CSL_DSS_OVERLAY_ID_4                        ((uint32_t) 0x3U)
/** \brief Overlay Max Id */
#define CSL_DSS_OVERLAY_ID_MAX                      ((uint32_t) 0x4U)
/* @} */

/**
 *  \anchor CSL_DssVpId
 *  \name   DSS Video Port Id
 *  \brief  Id for DSS Video Ports
 *
 *  @{
 */
/** \brief Video Port 1 */
#define CSL_DSS_VP_ID_1                             ((uint32_t) 0x0U)
/** \brief Video Port 2 */
#define CSL_DSS_VP_ID_2                             ((uint32_t) 0x1U)
/** \brief Video Port 3 */
#define CSL_DSS_VP_ID_3                             ((uint32_t) 0x2U)
/** \brief Video Port 4 */
#define CSL_DSS_VP_ID_4                             ((uint32_t) 0x3U)
/** \brief Video Port Max Id */
#define CSL_DSS_VP_ID_MAX                           ((uint32_t) 0x4U)
/* @} */

/**
 *  \anchor CSL_DssVpIdMask
 *  \name   DSS Video Port Id Mask
 *  \brief  Mask for DSS Video Ports
 *
 *  @{
 */
/** \brief Video Port 1 */
#define CSL_DSS_VP_ID_1_MASK                        ((uint32_t) 0x1U)
/** \brief Video Port 2 */
#define CSL_DSS_VP_ID_2_MASK                        ((uint32_t) 0x2U)
/** \brief Video Port 3 */
#define CSL_DSS_VP_ID_3_MASK                        ((uint32_t) 0x4U)
/** \brief Video Port 4 */
#define CSL_DSS_VP_ID_4_MASK                        ((uint32_t) 0x8U)
/* @} */

/**
 *  \anchor CSL_DssWbPipeId
 *  \name   DSS Write Back Pipe Id
 *  \brief  Id for different Write Back Pipes
 *
 *  @{
 */
/** \brief Write Back Pipe Id 1 */
#define CSL_DSS_WB_PIPE_ID_1                        ((uint32_t) 0x0U)
/** \brief Write Back Pipe Max Id */
#define CSL_DSS_WB_PIPE_ID_MAX                      ((uint32_t) 0x1U)
/* @} */

/**
 *  \anchor CSL_DssCscRange
 *  \name   DSS CSC Range
 *  \brief  DSS Color Space Conversion range setting
 *
 *  @{
 */
/** \brief Limited range selected */
#define CSL_DSS_CSC_RANGE_LIMITED                   ((uint32_t) 0x0U)
/** \brief Full range selected */
#define CSL_DSS_CSC_RANGE_FULL                      ((uint32_t) 0x1U)
/* @} */

/**
 *  \anchor CSL_DssSafetyChkMode
 *  \name   DSS Safety Check Mode
 *  \brief  Mode of operation of the safety check module
 *
 *  @{
 */
/** \brief Frame freeze detect enabled */
#define CSL_DSS_SAFETY_CHK_FRAME_FREEZE_DETECT     \
        ((uint32_t) CSL_DSS_VID1_SAFETY_ATTRIBUTES_CAPTUREMODE_VAL_FRAMEFREEZE)
/** \brief Data correctness check enabled */
#define CSL_DSS_SAFETY_CHK_DATA_INTEGRITY          \
        ((uint32_t) CSL_DSS_VID1_SAFETY_ATTRIBUTES_CAPTUREMODE_VAL_DATACHECK)
/* @} */

/**
 *  \anchor CSL_DssSafetyChkFrameSkip
 *  \name   DSS Safety Check Frame Skip
 *  \brief  Indicates which frames to be skipped while doing safety check
 *
 *  @{
 */
/** \brief No frames are skipped */
#define CSL_DSS_SAFETY_CHK_FRAME_SKIP_NO           \
            ((uint32_t) CSL_DSS_VID1_SAFETY_ATTRIBUTES_FRAMESKIP_VAL_DISABLE)
/** \brief Even Frames are skipped starting from second frame after enable */
#define CSL_DSS_SAFETY_CHK_FRAME_SKIP_EVEN         \
            ((uint32_t) CSL_DSS_VID1_SAFETY_ATTRIBUTES_FRAMESKIP_VAL_EVEN)
/** \brief Odd Frames are skipped starting from first frame after enable */
#define CSL_DSS_SAFETY_CHK_FRAME_SKIP_ODD          \
            ((uint32_t) CSL_DSS_VID1_SAFETY_ATTRIBUTES_FRAMESKIP_VAL_ODD)
/* @} */

/**
 *  \anchor CSL_DssDpiId
 *  \name   DSS DPI Id
 *
 *  @{
 */
/** \brief DPI DPI Id 0 */
#define CSL_DSS_DPI_ID_DPI_0                        ((uint32_t) 0x0U)
/** \brief DPI Id 1 */
#define CSL_DSS_DPI_ID_DPI_1                        ((uint32_t) 0x1U)
/** \brief EDP DPI Id 0 */
#define CSL_DSS_DPI_ID_EDP_0                        ((uint32_t) 0x2U)
/** \brief EDP DPI Id 1 */
#define CSL_DSS_DPI_ID_EDP_1                        ((uint32_t) 0x3U)
/** \brief EDP DPI Id 2 */
#define CSL_DSS_DPI_ID_EDP_2                        ((uint32_t) 0x4U)
/** \brief EDP DPI Id 3 */
#define CSL_DSS_DPI_ID_EDP_3                        ((uint32_t) 0x5U)
/** \brief DSI DPI Id */
#define CSL_DSS_DPI_ID_DSI                          ((uint32_t) 0x6U)
/** \brief DPI Id Max */
#define CSL_DSS_DPI_ID_MAX                          ((uint32_t) 0x7U)
/* @} */

/** \brief Number of entries for CLUT/Gamma Correction */
#define CSL_DSS_NUM_LUT_ENTRIES                     ((uint32_t) 1024U)

/** \brief Invalid Module Id for DSS modules */
#define CSL_DSS_MODULE_INVALID                      ((uint32_t) 0xFFU)

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/**
 *  \brief Structure containing coefficients for Color Space Conversion
 */
typedef struct
{
    uint32_t cscRange;
    /**< Color Space Conversion range setting
     *   For valid values see \ref CSL_DssCscRange */
    int32_t c00;
    /**< C00 Coefficient Encoded signed value */
    int32_t c01;
    /**< C01 Coefficient Encoded signed value */
    int32_t c02;
    /**< C02 Coefficient Encoded signed value */
    int32_t c10;
    /**< C10 Coefficient Encoded signed value */
    int32_t c11;
    /**< C11 Coefficient Encoded signed value */
    int32_t c12;
    /**< C12 Coefficient Encoded signed value */
    int32_t c20;
    /**< C20 Coefficient Encoded signed value */
    int32_t c21;
    /**< C21 Coefficient Encoded signed value */
    int32_t c22;
    /**< C22 Coefficient Encoded signed value */
    int32_t preOffset1;
    /**< Pre Offset1 Coefficient Encoded signed value */
    int32_t preOffset2;
    /**< Pre Offset2 Coefficient Encoded signed value */
    int32_t preOffset3;
    /**< Pre Offset3 Coefficient Encoded signed value */
    int32_t postOffset1;
    /**< Post Offset1 Coefficient Encoded signed value */
    int32_t postOffset2;
    /**< Post Offset2 Coefficient Encoded signed value */
    int32_t postOffset3;
    /**< Post Offset3 Coefficient Encoded signed value */
} CSL_DssCscCoeff;

/**
 *  \brief Configuration for doing safety checks
 */
typedef struct
{
    uint32_t safetyChkEnable;
    /**< Safety check Enable for the region
     *   FALSE: Disable Safety Check
     *   TRUE: Enable Safety Check */
    uint32_t safetyChkMode;
    /**< Mode of operation of the safety check module
     *   For valid values see \ref CSL_DssSafetyChkMode */
    uint32_t seedSelectEnable;
    /**< Initial seed selection control
     *   FALSE: Initial seed is always 0xFFFFFFFF
     *   TRUE:  Initial seed is defined by SAFETY_LFSR_SEED */
    uint32_t thresholdValue;
    /**< Allowed maximum number of frames with the same frame signature.
     *   When the freeze frame counter reaches thresholdValue+1, a freeze
     *   frame detection will occur */
    uint32_t frameSkip;
    /**< Indicates which frames to be skipped while doing safety checks
     *   For valid values see \ref CSL_DssSafetyChkFrameSkip */
    Fvid2_PosConfig regionPos;
    /**< Position of the safety region described using #Fvid2_PosConfig
     *
     *   <b>startX</b>:<br>
     *   X position of the layer
     *   The first pixel on the left of the screen has the X-position 0 <br>
     *
     *   <b>startY</b>:<br>
     *   Y position of the layer
     *   The first pixel at the top has the Y-position 0 <br>
     */
    Fvid2_SizeConfig regionSize;
    /**< Size of the safety region described using #Fvid2_SizeConfig
     *
     *   <b>width</b>:<br>
     *   Width of the safety region
     *   One pixel wide region has value of 0 <br>
     *
     *   <b>height</b>:<br>
     *   Height of the safety region
     *   One pixel height region has value of 0 <br>
     */
} CSL_DssSafetyChkCfg;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                      Static Function Declarations                          */
/* ========================================================================== */

/**
 *  \brief  CSL_DssCscCoeff structure init function
 *
 *  \param  cscCoeff Pointer to #CSL_DssCscCoeff structure
 *
 *  \return None
 */
static inline void CSL_dssCscCoeffInit(
    CSL_DssCscCoeff *cscCoeff);

/**
 *  \brief  CSL_DssSafetyChkCfg structure init function
 *
 *  \param  safetyCfg Pointer to #CSL_DssSafetyChkCfg structure
 *
 *  \return None
 */
static inline void CSL_dssSafetyChkCfgInit(
    CSL_DssSafetyChkCfg *safetyCfg);

/* ========================================================================== */
/*                       Static Function Definitions                          */
/* ========================================================================== */

static inline void CSL_dssCscCoeffInit(
    CSL_DssCscCoeff *cscCoeff)
{
    if(NULL != cscCoeff)
    {
        cscCoeff->cscRange = CSL_DSS_CSC_RANGE_LIMITED;
        cscCoeff->c00 = 0;
        cscCoeff->c01 = 0;
        cscCoeff->c02 = 0;
        cscCoeff->c10 = 0;
        cscCoeff->c11 = 0;
        cscCoeff->c12 = 0;
        cscCoeff->c20 = 0;
        cscCoeff->c21 = 0;
        cscCoeff->c22 = 0;
        cscCoeff->preOffset1 = 0;
        cscCoeff->preOffset2 = 0;
        cscCoeff->preOffset3 = 0;
        cscCoeff->postOffset1 = 0;
        cscCoeff->postOffset2 = 0;
        cscCoeff->postOffset3 = 0;
    }
}

static inline void CSL_dssSafetyChkCfgInit(
    CSL_DssSafetyChkCfg *safetyCfg)
{
    if(NULL != safetyCfg)
    {
        safetyCfg->safetyChkEnable = FALSE;
        safetyCfg->safetyChkMode = CSL_DSS_SAFETY_CHK_FRAME_FREEZE_DETECT;
        safetyCfg->seedSelectEnable = 0U;
        safetyCfg->thresholdValue = FALSE;
        safetyCfg->frameSkip = CSL_DSS_SAFETY_CHK_FRAME_SKIP_NO;
        safetyCfg->regionPos.startX = 0U;
        safetyCfg->regionPos.startY = 0U;
        safetyCfg->regionSize.width = 0U;
        safetyCfg->regionSize.height = 0U;
    }
}

#ifdef __cplusplus
}
#endif

#endif /* #ifndef CSL_DSSTOP_H_ */

/* @} */
