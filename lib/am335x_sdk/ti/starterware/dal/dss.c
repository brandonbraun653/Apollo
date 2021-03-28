/**
 *  \file  dss.c
 *
 *  \brief This file contains the device abstraction layer APIs for
 *         configuration of display subsystem and its sub module
 *         display controller functionalities.
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "hw_types.h"
#include "stdlib.h"
#include "math.h"
#include "dss.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Horizontal resizing accumulator value for LCD output. */
#define DSS_DISPC_VID_HORZ_ACCU_VAL_LCD            (0U)

/** \brief Vertical resizing accumulator value for LCD output. */
#define DSS_DISPC_VID_VERT_ACCU_VAL_LCD            (0U)

/** \brief Multiplication factor for resizing increment value. */
#define DSS_DISPC_VID_RESIZE_INCR_MULT_FACTOR     (1024U)

/** \brief Resizer processing increment factor clip value. */
#define DSS_DISPC_VID_RESIZE_CLIP_VAL             (4096U)

/** \brief Index of the hardware LCD frame buffer. */
#define DSS_LCD_REG_IDX                           (0U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t DSSGetRevision(uint32_t baseAddr)
{
    return (HW_RD_FIELD32((baseAddr + DSS_REVISIONNUMBER),
        DSS_REVISIONNUMBER_REV));
}


void DSSSoftReset(uint32_t baseAddr)
{
    /* Performing Software Reset of the module */
    HW_WR_FIELD32((baseAddr + DSS_SYSCONFIG),
        DSS_SYSCONFIG_SOFTRESET, DSS_SYSCONFIG_SOFTRESET_RESET);

    /* Wait until the process of Module Reset is complete */
    while(0U ==
        (HW_RD_FIELD32((baseAddr + DSS_SYSSTS), DSS_SYSSTS_RESETDONE)));
}


void DSSAutoIdleEnable(uint32_t baseAddr, uint32_t enableAutoIdle)
{
    uint32_t regVal = 0U;

    regVal = (TRUE == enableAutoIdle) ?
        DSS_SYSCONFIG_AUTOIDLE_AUTOMATIC : DSS_SYSCONFIG_AUTOIDLE_FREE_RUNNING;

    HW_WR_FIELD32((baseAddr + DSS_SYSCONFIG), DSS_SYSCONFIG_AUTOIDLE, regVal);
}


uint32_t DSSDispcIsIntrActive(uint32_t baseAddr)
{
    uint32_t retVal = FALSE;

    if (1U == HW_RD_FIELD32((baseAddr + DSS_IRQSTS), DSS_IRQSTS_DISPC_IRQ))
    {
        retVal = TRUE;
    }

    return retVal;
}


uint32_t DSSDispcGetRevision(uint32_t baseAddr)
{
    return (HW_RD_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_REVISION),
        DISPC_REVISION_REV));
}


void DSSDispcSoftReset(uint32_t baseAddr)
{
    /* Performing Software Reset of the module */
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_SYSCFG),
        DISPC_SYSCFG_SOFTRESET, DISPC_SYSCFG_SOFTRESET_RESET);

    /* Wait until the process of Module Reset is complete */
    while(0U == HW_RD_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_SYSSTS),
        DISPC_SYSSTS_RESETDONE));
}


void DSSDispcAutoIdleEnable(uint32_t baseAddr, uint32_t enableAutoIdle)
{
    uint32_t regVal = 0U;

    regVal = (TRUE == enableAutoIdle) ?
        DISPC_SYSCFG_AUTOIDLE_AUTOMATIC : DISPC_SYSCFG_AUTOIDLE_FREE;

    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_SYSCFG),
        DISPC_SYSCFG_AUTOIDLE, regVal);
}


void DSSDispcWakeupEnable(uint32_t baseAddr, uint32_t enableWakeup)
{
    uint32_t regVal = 0U;

    regVal = (TRUE == enableWakeup) ?
        DISPC_SYSCFG_ENWAKEUP_ENABLED : DISPC_SYSCFG_ENWAKEUP_DISABLED;

    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_SYSCFG),
        DISPC_SYSCFG_ENWAKEUP, regVal);
}


void DSSDispcSetIdleMode(uint32_t baseAddr, uint32_t idleMode)
{
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_SYSCFG),
        DISPC_SYSCFG_SIDLEMODE, idleMode);
}


void DSSDispcSetStandbyMode(uint32_t baseAddr, uint32_t standbyMode)
{
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_SYSCFG),
        DISPC_SYSCFG_MIDLEMODE, standbyMode);
}


void DSSDispcSetClkActivity(uint32_t baseAddr, uint32_t clkActivity)
{
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_SYSCFG),
        DISPC_SYSCFG_CLOCK_ACTIVITY, clkActivity);
}


void DSSDispcIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_IRQEN);

    regVal |= intrMask;
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_IRQEN), regVal);
}


void DSSDispcIntrDisable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_IRQEN);

    regVal &= (~intrMask);
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_IRQEN), regVal);
}


uint32_t DSSDispcIntrStatus(uint32_t baseAddr)
{
    return (HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_IRQSTS));
}


void DSSDispcIntrClear(uint32_t baseAddr, uint32_t intrMask)
{
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_IRQSTS), intrMask);
}


void DSSDispcShadowCfgEnable(uint32_t baseAddr)
{
    /* Check to ensure that GOLCD bit is clear */
    while(1U == HW_RD_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL),
        DISPC_CTRL_GO_LCD));

    /* Set the GoLCD bit */
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL),
        DISPC_CTRL_GO_LCD, DISPC_CTRL_GO_LCD_FINISHED_PROGRAMMING);
}


void DSSDispcSetRfbiBypassMode(uint32_t baseAddr)
{
    uint32_t regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL);

    HW_SET_FIELD(regVal, DISPC_CTRL_GPOUT0, DISPC_CTRL_GPOUT0_SET);
    HW_SET_FIELD(regVal, DISPC_CTRL_GPOUT1, DISPC_CTRL_GPOUT1_SET);
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL), regVal);
}


void DSSDispcSetProgLineNumber(uint32_t baseAddr, uint32_t lineNumber)
{
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_LINE_NUMBER),
        DISPC_LINE_NUMBER, lineNumber);
}


uint32_t DSSDispcGetDisplayLineNumber(uint32_t baseAddr)
{
    return (HW_RD_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_LINE_STS),
        DISPC_LINE_STS_NUMBER));
}


void DSSDispcGfxEnable(uint32_t baseAddr, uint32_t enableGfx)
{
    uint32_t regVal = 0U;

    regVal = (TRUE == enableGfx) ? DISPC_GFX_ATTRS_EN_ENABLED :
        DISPC_GFX_ATTRS_EN_DISABLED;

    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_ATTRS),
        DISPC_GFX_ATTRS_EN, regVal);
}


void DSSDispcGfxDmaConfig(uint32_t baseAddr, dssDispcDmaCfg_t *pCfg)
{
    uint32_t regVal = 0U;

    /* Program burst size and preload select values */
    regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_ATTRS);
    HW_SET_FIELD(regVal, DISPC_GFX_ATTRS_BURST_SIZE, pCfg->burstSize);
    HW_SET_FIELD(regVal, DISPC_GFX_ATTRS_FIFO_PRELOAD, pCfg->preloadSelect);
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_ATTRS), regVal);

    /* Program FIFO Low Threshold and high threshold field values */
    regVal = 0U;
    HW_SET_FIELD(regVal, DISPC_GFX_FIFO_THR_LOW, pCfg->fifoLoThr);
    HW_SET_FIELD(regVal, DISPC_GFX_FIFO_THR_HIGH, pCfg->fifoHiThr);
    HW_WR_REG32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_FIFO_THR), regVal);

    /* Program pixel increment value */
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_PIXEL_INC),
        DISPC_GFX_PIXEL_INC, pCfg->pixelInc);

    /* Program Row increment value */
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_ROW_INC),
        DISPC_GFX_ROW_INC, pCfg->rowInc);
}


void DSSDispcGfxSelfRefreshEnable(uint32_t baseAddr,
                                  uint32_t enableSelfRefresh)
{
    uint32_t regVal = 0U;

    regVal = (TRUE == enableSelfRefresh) ? DISPC_GFX_ATTRS_SELF_REFRESH_FIFO :
        DISPC_GFX_ATTRS_SELF_REFRESH_INTERCON;

    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_ATTRS),
        DISPC_GFX_ATTRS_SELF_REFRESH, regVal);
}


void DSSDispcSetGfxPriority(uint32_t baseAddr, uint32_t priority)
{
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_ATTRS),
        DISPC_GFX_ATTRS_ARBITRATION, priority);
}


void DSSDispcGfxFormatConfig(uint32_t baseAddr,
                             uint32_t frmDataFmt,
                             uint32_t endian,
                             uint32_t enableNibbleMode,
                             uint32_t enableExtender)
{
    uint32_t nibbleMode = 0U;
    uint32_t regVal =
        HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_ATTRS);

    /* Program the graphics format */
    HW_SET_FIELD(regVal, DISPC_GFX_ATTRS_FMT, frmDataFmt);

    /* Program the endian */
    HW_SET_FIELD(regVal, DISPC_GFX_ATTRS_ENDIAN, endian);

    /* Program the nibble mode */
    nibbleMode = (TRUE == enableNibbleMode) ?
        DISPC_GFX_ATTRS_NIBBLE_MODE_ENABLED :
        DISPC_GFX_ATTRS_NIBBLE_MODE_DISABLED;
    HW_SET_FIELD(regVal, DISPC_GFX_ATTRS_NIBBLE_MODE, nibbleMode);

    /* Program the extender enable */
    if (TRUE == enableExtender)
    {
        if ((DSS_DISPC_GFX_FMT_TYPE_RGB12 == frmDataFmt) ||
            (DSS_DISPC_GFX_FMT_TYPE_RGB16 == frmDataFmt))
        {
            /* Enable extender processing */
            HW_SET_FIELD(regVal, DISPC_GFX_ATTRS_REPLICATION_EN,
                DISPC_GFX_ATTRS_REPLICATION_EN_ENABLED);
        }
        else
        {
            /* Extender processing is not applicable for other formats. */
        }
    }

    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_ATTRS), regVal);
}


void DSSDispcGfxPaletteGammaCfg(uint32_t baseAddr,
                                uint32_t palleteGammaSel,
                                uint32_t loadMode,
                                uint32_t tableAddr)
{
    uint32_t regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_CFG);

    /* Configure LUT type as palette or Gamma */
    HW_SET_FIELD(regVal, DISPC_CFG_PALETTEGAMMA_TBL, palleteGammaSel);
    /* Program load mode of LUT */
    HW_SET_FIELD(regVal, DISPC_CFG_LOAD_MODE, loadMode);

    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CFG), regVal);

    /* Program base address of LUT */
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_TBL_BA), tableAddr);
}


void DSSDispcGfxWindowPositionCfg(uint32_t baseAddr,
                                  uint32_t xPos,
                                  uint32_t yPos)
{
    uint32_t regVal =
        HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_POSITION);

    /* Program X position and Y Position */
    HW_SET_FIELD(regVal, DISPC_GFX_POSITION_POSX, xPos);
    HW_SET_FIELD(regVal, DISPC_GFX_POSITION_POSY, yPos);
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_POSITION), regVal);
}


void DSSDispcGfxWindowSizeConfig(uint32_t baseAddr,
                                 uint32_t width,
                                 uint32_t height)
{
    uint32_t regVal =
        HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_SIZE);

    /* Program X size(width)  and Y size(height) */
    HW_SET_FIELD(regVal, DISPC_GFX_SIZE_SIZEX, (width - 1U));
    HW_SET_FIELD(regVal, DISPC_GFX_SIZE_SIZEY, (height - 1U));
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_SIZE), regVal);
}


void DSSDispcGfxSetBufAddr(uint32_t baseAddr,
                           uint32_t bufAddr,
                           uint32_t bufSelectFlag)
{
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_BA(bufSelectFlag)),
        bufAddr);
}


uint32_t DSSDispcGetGfxDmaFifoSize(uint32_t baseAddr)
{
    return (
        HW_RD_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_FIFO_SIZE_STS),
        DISPC_GFX_FIFO_SIZE_STS));
}


void DSSDispcSetGfxFifoPreload(uint32_t baseAddr, uint32_t preloadVal)
{
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_PRELOAD),
        DISPC_GFX_PRELOAD, preloadVal);
}


uint32_t DSSDispcGetGfxFifoPreload(uint32_t baseAddr)
{
    return (HW_RD_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_PRELOAD),
        DISPC_GFX_PRELOAD));
}


void DSSDispcGfxOvlyOptimizationEnable(uint32_t baseAddr,
                                       uint32_t windowSkipSize)
{
    /* Enable Overlay Optimization */
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL),
        DISPC_CTRL_OVLY_OPT, DISPC_CTRL_OVLY_OPT_VIDEO_DATA_NOT_FETCHED);

    /* Program graphics window skip size */
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GFX_WINDOW_SKIP),
        DISPC_GFX_WINDOW_SKIP, windowSkipSize);
}


void DSSDispcGfxOvlyOptimizationDisable(uint32_t baseAddr)
{
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL),
        DISPC_CTRL_OVLY_OPT, DISPC_CTRL_OVLY_OPT_VIDEO_DATA_FETCHED);
}


void DSSDispcVidEnable(uint32_t baseAddr,
                       uint32_t vidPipeline,
                       uint32_t enableVid)
{
    uint32_t regVal = 0U;

    regVal = (TRUE == enableVid) ? DISPC_VID_ATTRS_EN_ENABLE :
        DISPC_VID_ATTRS_EN_DISBALE;

    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ATTRS(vidPipeline)),
        DISPC_VID_ATTRS_EN, regVal);
}


void DSSDispcVidDmaConfig(uint32_t baseAddr,
                          uint32_t vidPipeline,
                          dssDispcDmaCfg_t *pCfg)
{
    uint32_t regVal = 0U;

    /* Program the burst size  and preload source selection */
    regVal = HW_RD_REG32(
        (baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ATTRS(vidPipeline));
    HW_SET_FIELD(regVal, DISPC_VID_ATTRS_BURST_SIZE, pCfg->burstSize);
    HW_SET_FIELD(regVal, DISPC_VID_ATTRS_FIFO_PRELOAD, pCfg->preloadSelect);
    HW_WR_REG32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ATTRS(vidPipeline)), regVal);

    /* program the FIFO low threshold and FIFO high threshold */
    regVal = HW_RD_REG32(
        (baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_FIFO_THR(vidPipeline));
    HW_SET_FIELD(regVal, DISPC_VID_FIFO_THR_LOW, pCfg->fifoLoThr);
    HW_SET_FIELD(regVal, DISPC_VID_FIFO_THR_HIGH, pCfg->fifoHiThr);
    HW_WR_REG32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_FIFO_THR(vidPipeline)),
        regVal);

    /* Program row increment value */
    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ROW_INC(vidPipeline)),
        DISPC_VID_ROW_INC, pCfg->rowInc);
    /* Program pixel increment value */
    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_PIXEL_INC(vidPipeline)),
        DISPC_VID_PIXEL_INC, pCfg->pixelInc);
}


void DSSDispcVidDmaSelfRefreshEnable(uint32_t baseAddr,
                                     uint32_t vidPipeline,
                                     uint32_t enableSelfRefresh)
{
    uint32_t regVal = 0U;

    regVal = (TRUE == enableSelfRefresh) ? DISPC_VID_ATTRS_SELF_REFRESH_FIFO :
        DISPC_VID_ATTRS_SELF_REFRESH_INTERCON;

    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ATTRS(vidPipeline)),
        DISPC_VID_ATTRS_SELF_REFRESH, regVal);
}


void DSSDispcSetVidPriority(uint32_t baseAddr,
                            uint32_t vidPipeline,
                            uint32_t priority)
{
    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ATTRS(vidPipeline)),
        DISPC_VID_ATTRS_ARBITRATION, priority);
}


void DSSDispcVidFormatConfig(uint32_t baseAddr,
                             uint32_t vidPipeline,
                             dssVidFmtCfg_t *pCfg)
{
    dssDispcCscCoeff_t *pCsc = (dssDispcCscCoeff_t *)pCfg->pCscCoeff;
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) +
        DISPC_VID_ATTRS(vidPipeline));

    /* Program video format  and endianness*/
    HW_SET_FIELD(regVal, DISPC_VID_ATTRS_FMT, pCfg->format);
    HW_SET_FIELD(regVal, DISPC_VID_ATTRS_ENDIAN, pCfg->endian);

    /* Extender processing */
    if (TRUE == pCfg->enableExtender)
    {
        if ((DSS_DISPC_VID_FMT_TYPE_RGB12 == pCfg->format) ||
            (DSS_DISPC_VID_FMT_TYPE_RGB16 == pCfg->format))
        {
            /* Enable replication */
            HW_SET_FIELD(regVal, DISPC_VID_ATTRS_REPLICATION_EN,
                DISPC_VID_ATTRS_REPLICATION_EN_ENABLE);
        }
        else
        {
            /* Extender processing is not supported for other formats. */
        }
    }
    HW_WR_REG32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ATTRS(vidPipeline)), regVal);

    /* Colour Space Conversion processing */
    if (TRUE == pCfg->enableCsc)
    {
        if ((DSS_DISPC_VID_FMT_TYPE_YUV2 == pCfg->format) ||
            (DSS_DISPC_VID_FMT_TYPE_UYVY == pCfg->format))
        {
            regVal =  HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_ATTRS(vidPipeline));
            /* Program video full range field */
            HW_SET_FIELD(regVal, DISPC_VID_ATTRS_FULL_RANGE, pCsc->vidFullRng);
            /* Enable Colour space conversion */
            HW_SET_FIELD(regVal, DISPC_VID_ATTRS_COLOR_CONV_EN,
                DISPC_VID_ATTRS_COLOR_CONV_EN_ENABLE);
            HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_ATTRS(vidPipeline)), regVal);

            /* Program RY and RCR coefficients */
            regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_CONV_COEF0(vidPipeline));
            HW_SET_FIELD(regVal, DISPC_VID_CONV_COEF0_RY, pCsc->ry);
            HW_SET_FIELD(regVal, DISPC_VID_CONV_COEF0_RCR, pCsc->rcr);
            HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_CONV_COEF0(vidPipeline)), regVal);

            /* Program RCB and GY coefficients */
            regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_CONV_COEF1(vidPipeline));
            HW_SET_FIELD(regVal, DISPC_VID_CONV_COEF1_RCB, pCsc->rcb);
            HW_SET_FIELD(regVal, DISPC_VID_CONV_COEF1_GY, pCsc->gy);
            HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_CONV_COEF1(vidPipeline)), regVal);

            /* Program GCR and GCB coefficients */
            regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_CONV_COEF2(vidPipeline));
            HW_SET_FIELD(regVal, DISPC_VID_CONV_COEF2_GCR, pCsc->gcr);
            HW_SET_FIELD(regVal, DISPC_VID_CONV_COEF2_GCB, pCsc->gcb);
            HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_CONV_COEF2(vidPipeline)), regVal);

            /* Program BY and BCR coefficients */
            regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_CONV_COEF3(vidPipeline));
            HW_SET_FIELD(regVal, DISPC_VID_CONV_COEF3_BY, pCsc->by);
            HW_SET_FIELD(regVal, DISPC_VID_CONV_COEF3_BCR, pCsc->bcr);
            HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_CONV_COEF3(vidPipeline)), regVal);

            /* Program BCB coefficient */
            HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_CONV_COEF4(vidPipeline)),
                DISPC_VID_CONV_COEF4_BCB, pCsc->bcb);
        }
        else
        {
            /* Color space conversion is not required for other formats. */
        }
    }
}


void DSSDispcVidWindowPositionCfg(uint32_t baseAddr,
                                  uint32_t vidPipeline,
                                  uint32_t xPos,
                                  uint32_t yPos)
{
    uint32_t regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) +
        DISPC_VID_POSITION(vidPipeline));

    /* Program the x position and y position */
    HW_SET_FIELD(regVal, DISPC_VID_POSITION_POSX, xPos);
    HW_SET_FIELD(regVal, DISPC_VID_POSITION_POSY, yPos);
    HW_WR_REG32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_POSITION(vidPipeline)),
        regVal);
}


void DSSDispcVidSizeConfig(uint32_t baseAddr,
                           uint32_t vidPipeline,
                           uint32_t inputWidth,
                           uint32_t inputHeight,
                           uint32_t outputWidth,
                           uint32_t outputHeight)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(
        (baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_PICTURE_SIZE(vidPipeline));
    /* Program input width (number of pixels per line) */
    HW_SET_FIELD(regVal, DISPC_VID_PICTURE_SIZE_ORG_X, (inputWidth - 1U));
    /* Program input height (number of lines) */
    HW_SET_FIELD(regVal, DISPC_VID_PICTURE_SIZE_ORG_Y, (inputHeight - 1U));
    HW_WR_REG32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_PICTURE_SIZE(vidPipeline)),
        regVal);


    regVal = HW_RD_REG32(
        (baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_SIZE(vidPipeline));
    /* Program output width (number of pixels per line) */
    HW_SET_FIELD(regVal, DISPC_VID_SIZE_X, (outputWidth - 1U));
    /* Program output height (number of lines) */
    HW_SET_FIELD(regVal, DISPC_VID_SIZE_Y, (outputHeight - 1U));
    HW_WR_REG32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_SIZE(vidPipeline)), regVal);
}


void DSSDispcVidResizeEnable(uint32_t baseAddr,
                             uint32_t vidPipeline,
                             uint32_t resizeType,
                             uint32_t filterTaps)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(
        (baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ATTRS(vidPipeline));

    /* Program resize enable type and filter taps */
    HW_SET_FIELD(regVal, DISPC_VID_ATTRS_RESIZE_EN, resizeType);
    HW_SET_FIELD(regVal, DISPC_VID_ATTRS_VERTICAL_TAPS, filterTaps);

    HW_WR_REG32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ATTRS(vidPipeline)), regVal);
}


void DSSDispcVidHorzResizeCfg(uint32_t baseAddr,
                              uint32_t vidPipeline,
                              uint32_t upDownType)
{
    uint32_t inputWidth = 0U;
    uint32_t outputWidth = 0U;
    uint32_t incr = 0U;

    /* Program resize type: up / down */
    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ATTRS(vidPipeline)),
        DISPC_VID_ATTRS_HRESIZE_CONF, upDownType);

    /* Calculate increment factor value using input and output widths */

    /* Read the input width from the picture size register */
    inputWidth  =
        HW_RD_FIELD32(((baseAddr + DSS_DISPC_OFFSET) +
            DISPC_VID_PICTURE_SIZE(vidPipeline)), DISPC_VID_PICTURE_SIZE_ORG_X);
    /* Read the output width from the size register */
    outputWidth =
        HW_RD_FIELD32(((baseAddr + DSS_DISPC_OFFSET) +
            DISPC_VID_SIZE(vidPipeline)), DISPC_VID_SIZE_X);

    /* Get the exact sizes by adding 1 to the register values */
    inputWidth += 1U;
    outputWidth += 1U;

    /* if output width is '1' then replace it with 2 */
    if (0x1U == outputWidth)
    {
        outputWidth = 0x2U;
    }

    incr = ((DSS_DISPC_VID_RESIZE_INCR_MULT_FACTOR * inputWidth) / outputWidth);

    /* If increment value is greater than 4096 then clip it to 4096 */
    if (incr > DSS_DISPC_VID_RESIZE_CLIP_VAL)
    {
        incr = DSS_DISPC_VID_RESIZE_CLIP_VAL;
    }

    /* Program horizontal increment field value */
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_FIR(vidPipeline)),
        DISPC_VID_FIR_H_INC, incr);

    /* Program the horizontal accumulator value as zero for LCD output */
    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ACCU(vidPipeline, 0U)),
        DISPC_VID_ACCU_HORIZONTAL, DSS_DISPC_VID_HORZ_ACCU_VAL_LCD);
}


void DSSDispcVidHorzResizeCoeffCfg(uint32_t baseAddr,
                                   uint32_t vidPipeline,
                                   dssDispcHorzResizeCoeff_t horzCoeff[])
{
    uint32_t idx = 0U;
    uint32_t regVal = 0U;
    dssDispcHorzResizeCoeff_t hc[DSS_RESIZER_NUM_PHASES];
    uint32_t dispcVidFirCoeffH[DSS_NUM_VID_PIPELINES][DSS_RESIZER_NUM_PHASES];
    uint32_t dispcVidFirCoeffHV[DSS_NUM_VID_PIPELINES][DSS_RESIZER_NUM_PHASES];

    /*
     * Initialize Fir Coefficient register offsets based on pipeline.
     * This is needed because the auto generated header file has defined
     * the offset macros separately for video1 and video2 pipelines for the
     * below registers.
     */
    for(idx = 0U; idx < DSS_RESIZER_NUM_PHASES; idx++)
    {
        if (DSS_DISPC_VID_PIPELINE_ID_1 == vidPipeline)
        {
            dispcVidFirCoeffH[vidPipeline][idx] = DISPC_VID1_FIR_COEF_H(idx);
            dispcVidFirCoeffHV[vidPipeline][idx] = DISPC_VID1_FIR_COEF_HV(idx);
        }
        else if (DSS_DISPC_VID_PIPELINE_ID_2 == vidPipeline)
        {
            dispcVidFirCoeffH[vidPipeline][idx] = DISPC_VID2_FIR_COEF_H(idx);
            dispcVidFirCoeffHV[vidPipeline][idx] = DISPC_VID2_FIR_COEF_HV(idx);
        }
        else
        {
            /*
             * This error does not happen because user is expected to pass in
             * the correct parameters.
             */
        }
    }

    /*
     * Read the coefficients. Total horizontal resize coefficients will be 40.
     * Eight phases * Five coefficients for each phase = 8 * 5 = 40.
     */
    for(idx = 0U; idx < DSS_RESIZER_NUM_PHASES; idx++)
    {
        hc[idx].hc4  = horzCoeff[idx].hc4;
        hc[idx].hc3  = horzCoeff[idx].hc3;
        hc[idx].hc2  = horzCoeff[idx].hc2;
        hc[idx].hc1  = horzCoeff[idx].hc1;
        hc[idx].hc0  = horzCoeff[idx].hc0;
    }

    /* Program the horizontal coefficient fields */
    for(idx = 0U; idx < DSS_RESIZER_NUM_PHASES; idx++)
    {
        /*
         * Note: Bit field masks corresponding to Video1 register are used for
         * both Video 1 and Video2 configurations, because these masks and
         * shift values are same for both video1 and video2.
         */

        /* Program hc0, hc1, hc2 and hc3 */
        regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) +
            dispcVidFirCoeffH[vidPipeline][idx]);
        HW_SET_FIELD(regVal, DISPC_VID1_FIR_COEF_H_HC0, hc[idx].hc0);
        HW_SET_FIELD(regVal, DISPC_VID1_FIR_COEF_H_HC1, hc[idx].hc1);
        HW_SET_FIELD(regVal, DISPC_VID1_FIR_COEF_H_HC2, hc[idx].hc2);
        HW_SET_FIELD(regVal, DISPC_VID1_FIR_COEF_H_HC3, hc[idx].hc3);
        HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) +
            dispcVidFirCoeffH[vidPipeline][idx]), regVal);

        /* Program hc4 */
        HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) +
            dispcVidFirCoeffHV[vidPipeline][idx]),
            DISPC_VID1_FIR_COEF_HV_HC4, hc[idx].hc4);
    }
}


void DSSDispcVidVertResizeCfg(uint32_t baseAddr,
                             uint32_t vidPipeline,
                             uint32_t upDownType)
{
    uint32_t inputHeight = 0U;
    uint32_t outputHeight = 0U;
    uint32_t incr = 0U;

    /* Program resize type: up / down */
    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ATTRS(vidPipeline)),
        DISPC_VID_ATTRS_VRESIZE_CONF, upDownType);

    /* Calculate increment factor value using input and output widths */

    /* Read the input height from the picture size register */
    inputHeight  =
        HW_RD_FIELD32(((baseAddr + DSS_DISPC_OFFSET) +
            DISPC_VID_PICTURE_SIZE(vidPipeline)), DISPC_VID_PICTURE_SIZE_ORG_Y);
    /* Read the output height from the size register */
    outputHeight =
        HW_RD_FIELD32(((baseAddr + DSS_DISPC_OFFSET) +
            DISPC_VID_SIZE(vidPipeline)), DISPC_VID_SIZE_Y);

    /* Get the exact sizes by adding 1 to register values */
    inputHeight += 1U;
    outputHeight += 1U;

    /* if output height is '1' then replace it with 2 */
    if (0x1U == outputHeight)
    {
        outputHeight = 0x2U;
    }

    incr =
        ((DSS_DISPC_VID_RESIZE_INCR_MULT_FACTOR * inputHeight) / outputHeight);

    if (incr > DSS_DISPC_VID_RESIZE_CLIP_VAL)
    {
        incr = DSS_DISPC_VID_RESIZE_CLIP_VAL;
    }

    /* Program vertical increment field value */
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_FIR(vidPipeline)),
        DISPC_VID_FIR_V_INC, incr);

    /* Program the vertical accumulator value as zero for LCD output */
    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ACCU(vidPipeline, 0U)),
        DISPC_VID_ACCU_VERTICAL, DSS_DISPC_VID_VERT_ACCU_VAL_LCD);
}


void DSSDispcVidVertResizeCoeffCfg(uint32_t baseAddr,
                                   uint32_t vidPipeline,
                                   dssDispcVertResizeCoeff_t vertCoeff[])
{
    uint32_t idx = 0U;
    uint32_t taps = 0U;
    uint32_t regVal = 0U;
    dssDispcVertResizeCoeff_t vc[DSS_RESIZER_NUM_PHASES];
    uint32_t dispcVidFirCoeffHV[DSS_NUM_VID_PIPELINES][DSS_RESIZER_NUM_PHASES];

    /*
     * Initialize Fir Coefficient register offsets based on pipeline.
     * This is needed because the auto generated header file has defined
     * the offset macros separately for video1 and video2 pipelines for the
     * below registers.
     */
    for(idx = 0U; idx < DSS_RESIZER_NUM_PHASES; idx++)
    {
        if (DSS_DISPC_VID_PIPELINE_ID_1 == vidPipeline)
        {
            dispcVidFirCoeffHV[vidPipeline][idx] = DISPC_VID1_FIR_COEF_HV(idx);
        }
        else if(DSS_DISPC_VID_PIPELINE_ID_2 == vidPipeline)
        {
            dispcVidFirCoeffHV[vidPipeline][idx] = DISPC_VID2_FIR_COEF_HV(idx);
        }
        else
        {
            /*
             * This error does not happen because user is expected to pass in
             * the correct parameters.
             */
        }
    }

    /* Read vertical filter taps value */
    taps = HW_RD_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ATTRS(vidPipeline)),
        DISPC_VID_ATTRS_VERTICAL_TAPS);

    /*
     * Get the coefficients.
     * For 3 taps :  vc22 and vc00 will be zeros
     * For 5 taps :  8 (phases) * 5 (taps) = 40 coefficients
     */
    for(idx = 0U; idx < DSS_RESIZER_NUM_PHASES; idx++)
    {
        vc[idx].vc22 = vertCoeff[idx].vc22;
        vc[idx].vc2  = vertCoeff[idx].vc2;
        vc[idx].vc1  = vertCoeff[idx].vc1;
        vc[idx].vc0  = vertCoeff[idx].vc0;
        vc[idx].vc00 = vertCoeff[idx].vc00;
    }

    /* Program the vertical resizing coefficients */
    for(idx = 0U; idx < DSS_RESIZER_NUM_PHASES; idx++)
    {
        /*
         * Note: Bit field masks corresponding to Video1 register are used for
         * both Video 1 and Video2 configurations, because these masks and
         * shift values are same for both video1 and video2.
         */

        /* Program vc0, vc1 and vc2 */
        regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) +
            dispcVidFirCoeffHV[vidPipeline][idx]);
        HW_SET_FIELD(regVal, DISPC_VID1_FIR_COEF_HV_VC0,vc[idx].vc0);
        HW_SET_FIELD(regVal, DISPC_VID1_FIR_COEF_HV_VC1, vc[idx].vc1);
        HW_SET_FIELD(regVal, DISPC_VID1_FIR_COEF_HV_VC2, vc[idx].vc2);
        HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) +
            dispcVidFirCoeffHV[vidPipeline][idx]), regVal);

        if (DSS_DISPC_VID_VERT_RESIZE_FILTER_TAPS_5 == taps)
        {
            /* Program vc00 and vc22 */
            regVal =
                HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_FIR_COEF_V(vidPipeline, idx));
            HW_SET_FIELD(regVal, DISPC_VID_FIR_COEF_V_VC00, vc[idx].vc00);
            HW_SET_FIELD(regVal, DISPC_VID_FIR_COEF_V_VC22, vc[idx].vc22);
            HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) +
                DISPC_VID_FIR_COEF_V(vidPipeline, idx)), regVal);
        }
    }
}


void DSSDispcVidResizeDisable(uint32_t baseAddr, uint32_t vidPipeline)
{
    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_ATTRS(vidPipeline)),
        DISPC_VID_ATTRS_RESIZE_EN, DISPC_VID_ATTRS_RESIZE_EN_DISBALE);
}


void DSSDispcVidSetBufAddr(uint32_t baseAddr,
                           uint32_t vidPipeline,
                           uint32_t bufAddr,
                           uint32_t bufSelectFlag)
{
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) +
        DISPC_VID_BA(vidPipeline, bufSelectFlag)), bufAddr);
}


uint32_t DSSDispcGetVidDmaFifoSize(uint32_t baseAddr, uint32_t vidPipeline)
{
    return (HW_RD_FIELD32(((baseAddr + DSS_DISPC_OFFSET) +
        DISPC_VID_FIFO_SIZE_STS(vidPipeline)), DISPC_VID_FIFO_SIZE_STS));
}


void DSSDispcSetVidFifoPreload(uint32_t baseAddr,
                               uint32_t vidPipeline,
                               uint32_t preloadVal)
{
    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_VID_PRELOAD(vidPipeline)),
        DISPC_VID_PRELOAD, preloadVal);
}


uint32_t DSSDispcGetVidFifoPreload(uint32_t baseAddr, uint32_t vidPipeline)
{
    return (HW_RD_FIELD32(((baseAddr + DSS_DISPC_OFFSET) +
            DISPC_VID_PRELOAD(vidPipeline)), DISPC_VID_PRELOAD));
}


void DSSDispcLcdOutputEnable(uint32_t baseAddr, uint32_t enableLcd)
{
    uint32_t regVal = 0U;

    regVal = (TRUE == enableLcd) ? DISPC_CTRL_LCD_EN_ENABLED :
        DISPC_CTRL_LCD_EN_DISABLED;

    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL),
        DISPC_CTRL_LCD_EN, regVal);
}


void DSSDispcLcdDisplayAttrConfig(uint32_t baseAddr,
                                  dssDispcLcdAttrCfg_t *pCfg)
{
    uint32_t regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL);

    /* Configure display type active/passive */
    HW_SET_FIELD(regVal, DISPC_CTRL_STNTFT, pCfg->displayType);
    /* Configure LCD Data Lines */
    HW_SET_FIELD(regVal, DISPC_CTRL_TFT_DATA_LINES, pCfg->lcdDataLines);

    /* Configure passive matrix display specific parameters */
    if (DSS_DISPC_LCD_MATRIX_TYPE_PASSIVE == pCfg->displayType)
    {
        /* Configure Color or Monochrome */
        HW_SET_FIELD(regVal, DISPC_CTRL_MONO_COLOR, pCfg->monoColor);

        if (DSS_DISPC_LCD_DISP_TYPE_MONO == pCfg->monoColor)
        {
            /* Configure Mono8 bit or Mono4 bit interface */
            HW_SET_FIELD(regVal, DISPC_CTRL_M8B, pCfg->mono8Bit);
        }
    }
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL), regVal);
}


void DSSDispcLcdTimingConfig(uint32_t baseAddr, dssDispcLcdTimingCfg_t *pCfg)
{
    uint32_t regVal = 0U;

    /* Program pixels per line and Lines per panel */
    regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_SIZE_LCD);
    HW_SET_FIELD(regVal, DISPC_SIZE_LCD_PPL, (pCfg->ppl - 1U));
    HW_SET_FIELD(regVal, DISPC_SIZE_LCD_LPP, (pCfg->lpp - 1U));
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_SIZE_LCD), regVal);

    /* Program hsw, hfp and hbp values */
    regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_TIMING_H);
    HW_SET_FIELD(regVal, DISPC_TIMING_H_HSW, (pCfg->hsw - 1U));
    HW_SET_FIELD(regVal, DISPC_TIMING_H_HFP, (pCfg->hfp - 1U));
    HW_SET_FIELD(regVal, DISPC_TIMING_H_HBP, (pCfg->hbp - 1U));
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_TIMING_H), regVal);

    /* Program vsw, vfp and vbp values */
    regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_TIMING_V);
    HW_SET_FIELD(regVal, DISPC_TIMING_V_VSW, (pCfg->vsw - 1U));
    HW_SET_FIELD(regVal, DISPC_TIMING_V_VFP, pCfg->vfp);
    HW_SET_FIELD(regVal, DISPC_TIMING_V_VBP, pCfg->vbp);
    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_TIMING_V), regVal);
}


void DSSDispcLcdPolarityConfig(uint32_t baseAddr,
                               dssDispcLcdPolarityCfg_t *pCfg)
{
    uint32_t regVal =
        HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_POL_FREQ);

    /* Program hsync polarity value */
    HW_SET_FIELD(regVal, DISPC_POL_FREQ_IHS, pCfg->hSyncPolarity);
    /* Program vsync polarity value */
    HW_SET_FIELD(regVal, DISPC_POL_FREQ_IVS, pCfg->vSyncPolarity);
    /* Program Output enable signal polarity value */
    HW_SET_FIELD(regVal, DISPC_POL_FREQ_IEO, pCfg->outputEnablePolarity);
    /* Program pixel clock polarity value */
    HW_SET_FIELD(regVal, DISPC_POL_FREQ_IPC, pCfg->pixelClkPolarity);
    /* Program sync edge type */
    HW_SET_FIELD(regVal, DISPC_POL_FREQ_RF, pCfg->syncEdge);
    /* Program sync edge control */
    HW_SET_FIELD(regVal, DISPC_POL_FREQ_ONOFF, pCfg->sycnEdgeCtrl);

    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_POL_FREQ), regVal);
}


void DSSDispcLcdAcbiasConfig(uint32_t baseAddr, dssDispcLcdAcbCfg_t *pCfg)
{
    uint32_t regVal =
        HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_POL_FREQ);

    /* program acb pin frequency */
    HW_SET_FIELD(regVal, DISPC_POL_FREQ_ACB, pCfg->acbFreq);
    /* program acb pin transitions per interrupt */
    HW_SET_FIELD(regVal, DISPC_POL_FREQ_ACBI, pCfg->acbi);

    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_POL_FREQ), regVal);
}


void DSSDispcLcdSigGatedCtrl(uint32_t baseAddr, dssDispcLcdGatedCtrl_t *pCfg)
{
    uint32_t regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_CFG);
    uint32_t gatedCtrl = 0U;

    /* Program hsync clock gated control */
    gatedCtrl = (TRUE == pCfg->hSyncGated) ? DISPC_CFG_HSYNC_GATED_ENABLED :
        DISPC_CFG_HSYNC_GATED_DISABLED;
    HW_SET_FIELD(regVal, DISPC_CFG_HSYNC_GATED, gatedCtrl);

    /* Program vsync clock gated control */
    gatedCtrl = (TRUE == pCfg->vSyncGated) ? DISPC_CFG_VSYNC_GATED_ENABLED :
        DISPC_CFG_VSYNC_GATED_DISABLED;
    HW_SET_FIELD(regVal, DISPC_CFG_VSYNC_GATED, gatedCtrl);

    /* Program acb clock gated control */
    gatedCtrl = (TRUE == pCfg->acbGated) ? DISPC_CFG_ACBIAS_GATED_ENABLED :
        DISPC_CFG_ACBIAS_GATED_DISABLED;
    HW_SET_FIELD(regVal, DISPC_CFG_ACBIAS_GATED, gatedCtrl);

    /* Program pixel clock gated control */
    gatedCtrl = (TRUE == pCfg->pixelClkGated) ?
        DISPC_CFG_PIXEL_CLK_GATED_ENABLED : DISPC_CFG_PIXEL_CLK_GATED_DISABLED;
    HW_SET_FIELD(regVal, DISPC_CFG_PIXEL_CLK_GATED, gatedCtrl);

    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CFG), regVal);
}


void DSSDispcLcdEnableSigConfig(uint32_t baseAddr,
                                uint32_t sigEnable,
                                uint32_t polarity)
{
    uint32_t regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL);

    /* Program LCD enable signal enable control */
    HW_SET_FIELD(regVal, DISPC_CTRL_LCD_EN_SIGNAL, sigEnable);
    /* Program LCD enable signal polarity */
    HW_SET_FIELD(regVal, DISPC_CTRL_LCD_EN_POL, polarity);

    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL), regVal);
}


uint32_t DSSDispcLcdClkConfig(uint32_t baseAddr,
                              uint32_t functionalClk,
                              uint32_t pixelClk)
{
    uint32_t regVal = 0U;
    uint32_t matchFound = FALSE;
    uint32_t lDivIdx = 1U;
    uint32_t pDivIdx = 0U;
    uint32_t prevDiff = 0U;
    uint32_t currDiff = 0U;
    uint32_t logicClk = 0U;
    uint32_t pClk = 0U;
    uint32_t lDivisor = 0U;
    uint32_t pDivisor = 0U;
    uint32_t pDivMin  = 2U;
    uint32_t initFlag = TRUE;

    pDivIdx = pDivMin ;

    while((lDivIdx <= DSS_LCD_DIVISOR_MAX) && (FALSE == matchFound))
    {
        logicClk = functionalClk / lDivIdx;

        while((pDivIdx <= DSS_LCD_DIVISOR_MAX) && (FALSE == matchFound))
        {
            pClk = logicClk / pDivIdx;
            currDiff = abs(pClk - pixelClk);

            if ((currDiff < prevDiff) || (TRUE == initFlag))
            {
                prevDiff = currDiff;
                lDivisor = lDivIdx;
                pDivisor = pDivIdx;
                initFlag = FALSE;
            }
            if (pClk == pixelClk)
            {
                matchFound = TRUE;
            }
            else if (pClk < pixelClk)
            {
                break;
            }
            pDivIdx++;
        }
        if ((logicClk / pDivMin) < pixelClk)
        {
            break;
        }
        lDivIdx++;
    }

    regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_DIVISOR);

    /*program pixel clock divisor */
    HW_SET_FIELD(regVal, DISPC_DIVISOR_PCD, pDivisor);
    /* program logic clock divisor */
    HW_SET_FIELD(regVal, DISPC_DIVISOR_LCD, lDivisor);

    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_DIVISOR), regVal);

    return ((functionalClk / lDivisor) / (pDivisor));
}


void DSSDispcStDitheringEnable(uint32_t baseAddr, uint32_t ditheringType)
{
    uint32_t regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL);

    /* Enable ST dithering */
    HW_SET_FIELD(regVal, DISPC_CTRL_ST_DITHER_EN,
        DISPC_CTRL_ST_DITHER_EN_ENABLED);
    /* Program type of dithering */
    HW_SET_FIELD(regVal, DISPC_CTRL_SPATIAL_TEMPORAL_DITHER, ditheringType);

    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL), regVal);
}


void DSSDispcStDitheringDisable(uint32_t baseAddr)
{
    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CTRL),
        DISPC_CTRL_ST_DITHER_EN, DISPC_CTRL_ST_DITHER_EN_DISABLED);
}


void DSSDispcOverlayTckEnable(uint32_t baseAddr,
                              uint32_t colorKeyType,
                              uint32_t colorKeyValue)
{
    uint32_t regVal = HW_RD_REG32((baseAddr + DSS_DISPC_OFFSET) + DISPC_CFG);

    /* Program the colour key type field */
    HW_SET_FIELD(regVal, DISPC_CFG_TCK_LCD_SELECTION, colorKeyType);
    /* Enable the Transparency colour key */
    HW_SET_FIELD(regVal, DISPC_CFG_TCK_LCD_EN, DISPC_CFG_TCK_LCD_EN_ENABLED);

    HW_WR_REG32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CFG), regVal);

    /* Program the colour key value for LCD output */
    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_TRANS_COLOR(DSS_LCD_REG_IDX)),
        DISPC_TRANS_COLOR_KEY, colorKeyValue);
}


void DSSDispcOverlayTckDisable(uint32_t baseAddr)
{
    HW_WR_FIELD32((((baseAddr + DSS_DISPC_OFFSET) + DISPC_CFG)),
        DISPC_CFG_TCK_LCD_EN, DISPC_CFG_TCK_LCD_EN_DISABLED);
}


void DSSDispcOverlayAlphaBlenderEnable(uint32_t baseAddr,
                                       uint32_t enableAlphaBlender)
{
    uint32_t regVal = 0U;

    regVal = (TRUE == enableAlphaBlender) ? DISPC_CFG_LCD_APLHABLDR_EN_ENABLED :
        DISPC_CFG_LCD_APLHABLDR_EN_DISABLED;

    HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_CFG),
        DISPC_CFG_LCD_APLHABLDR_EN, regVal);
}


void DSSDispcOverlaySetGlobalAlpha(uint32_t baseAddr,
                                   uint32_t pipeline,
                                   uint32_t globalAlpha)
{
    if (DSS_DISPC_PIPELINE_TYPE_GRAPHICS == pipeline)
    {
        HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GLOBAL_ALPHA),
            DISPC_GLOBAL_ALPHA_GFX, globalAlpha);
    }
    else if (DSS_DISPC_PIPELINE_TYPE_VIDEO2 == pipeline)
    {
        HW_WR_FIELD32(((baseAddr + DSS_DISPC_OFFSET) + DISPC_GLOBAL_ALPHA),
            DISPC_GLOBAL_ALPHA_VID2, globalAlpha);
    }
    else
    {
        /*
         * This error does not happen because user is expected to pass in the
         * correct parameters.
         */
    }
}


void DSSDispcOverlaySetBackgndColor(uint32_t baseAddr, uint32_t color)
{
    HW_WR_FIELD32(
        ((baseAddr + DSS_DISPC_OFFSET) + DISPC_DEFAULT_COLOR(DSS_LCD_REG_IDX)),
        DISPC_DEFAULT_COLOR, color);
}


void DSSContextSave(uint32_t baseAddr, dssContext_t *pCtx)
{
    uint32_t idx1 = 0U;
    uint32_t idx2 = 0U;

    pCtx->dssSysConfig = HW_RD_REG32(baseAddr + DSS_SYSCONFIG);

    /* Calculate the offset of Display controller */
    baseAddr = baseAddr + DSS_DISPC_OFFSET;

    pCtx->dispcSysConfig = HW_RD_REG32(baseAddr + DISPC_SYSCFG);
    pCtx->irqEnable      = HW_RD_REG32(baseAddr + DISPC_IRQEN);
    pCtx->control        = HW_RD_REG32(baseAddr + DISPC_CTRL);
    pCtx->config         = HW_RD_REG32(baseAddr + DISPC_CFG);
    pCtx->defaultColor0  =
        HW_RD_REG32(baseAddr + DISPC_DEFAULT_COLOR(DSS_LCD_REG_IDX));
    pCtx->transColor0    =
        HW_RD_REG32(baseAddr + DISPC_TRANS_COLOR(DSS_LCD_REG_IDX));
    pCtx->lineNumber     = HW_RD_REG32(baseAddr + DISPC_LINE_NUMBER);
    pCtx->timingH        = HW_RD_REG32(baseAddr + DISPC_TIMING_H);
    pCtx->timingV        = HW_RD_REG32(baseAddr + DISPC_TIMING_V);
    pCtx->polFreq        = HW_RD_REG32(baseAddr + DISPC_POL_FREQ);
    pCtx->divisor        = HW_RD_REG32(baseAddr + DISPC_DIVISOR);
    pCtx->globalAlpha    = HW_RD_REG32(baseAddr + DISPC_GLOBAL_ALPHA);
    pCtx->sizeLcd        = HW_RD_REG32(baseAddr + DISPC_SIZE_LCD);

    /* Graphics pipeline registers */
    pCtx->gfxBA0        = HW_RD_REG32(baseAddr + DISPC_GFX_BA(DSS_LCD_REG_IDX));
    pCtx->gfxPos        = HW_RD_REG32(baseAddr + DISPC_GFX_POSITION);
    pCtx->gfxSize       = HW_RD_REG32(baseAddr + DISPC_GFX_SIZE);
    pCtx->gfxAttr       = HW_RD_REG32(baseAddr + DISPC_GFX_ATTRS);
    pCtx->gfxFifoThr    = HW_RD_REG32(baseAddr + DISPC_GFX_FIFO_THR);
    pCtx->gfxRowInc     = HW_RD_REG32(baseAddr + DISPC_GFX_ROW_INC);
    pCtx->gfxPixInc     = HW_RD_REG32(baseAddr + DISPC_GFX_PIXEL_INC);
    pCtx->gfxWindowSkip = HW_RD_REG32(baseAddr + DISPC_GFX_WINDOW_SKIP);
    pCtx->gfxTableBA    = HW_RD_REG32(baseAddr + DISPC_GFX_TBL_BA);

    /* Video pipeline registers */
    for(idx1 = 0U; idx1 < DSS_NUM_VID_PIPELINES; idx1++)
    {
        pCtx->vidBA0[idx1]  =
            HW_RD_REG32(baseAddr + DISPC_VID_BA(idx1, DSS_LCD_REG_IDX));
        pCtx->vidPos[idx1]  = HW_RD_REG32(baseAddr + DISPC_VID_POSITION(idx1));
        pCtx->vidSize[idx1] = HW_RD_REG32(baseAddr + DISPC_VID_SIZE(idx1));
        pCtx->vidAttr[idx1] = HW_RD_REG32(baseAddr + DISPC_VID_ATTRS(idx1));
        pCtx->vidFifoThr[idx1] =
            HW_RD_REG32(baseAddr + DISPC_VID_FIFO_THR(idx1));
        pCtx->vidPixInc[idx1] =
            HW_RD_REG32(baseAddr + DISPC_VID_PIXEL_INC(idx1));
        pCtx->vidRowInc[idx1] = HW_RD_REG32(baseAddr + DISPC_VID_ROW_INC(idx1));
        pCtx->vidFIR[idx1]    = HW_RD_REG32(baseAddr + DISPC_VID_FIR(idx1));
        pCtx->vidPictureSize[idx1] =
            HW_RD_REG32(baseAddr + DISPC_VID_PICTURE_SIZE(idx1));
        pCtx->vidAccu[idx1] =
            HW_RD_REG32(baseAddr + DISPC_VID_ACCU(idx1, DSS_LCD_REG_IDX));
        pCtx->vidConvCoeff0[idx1] =
            HW_RD_REG32(baseAddr + DISPC_VID_CONV_COEF0(idx1));
        pCtx->vidConvCoeff1[idx1] =
            HW_RD_REG32(baseAddr + DISPC_VID_CONV_COEF1(idx1));
        pCtx->vidConvCoeff2[idx1] =
            HW_RD_REG32(baseAddr + DISPC_VID_CONV_COEF2(idx1));
        pCtx->vidConvCoeff3[idx1] =
            HW_RD_REG32(baseAddr + DISPC_VID_CONV_COEF3(idx1));
        pCtx->vidConvCoeff4[idx1] =
            HW_RD_REG32(baseAddr + DISPC_VID_CONV_COEF4(idx1));

        for(idx2 = 0U; idx2 < DSS_RESIZER_NUM_PHASES; idx2++)
        {
            pCtx->vidFIRCoeffV[idx1][idx2] =
                HW_RD_REG32(baseAddr + DISPC_VID_FIR_COEF_V(idx1, idx2));
        }
    }

    for(idx2 = 0U; idx2 < DSS_RESIZER_NUM_PHASES; idx2++)
    {
        pCtx->vidFIRCoeffH[DSS_DISPC_VID_PIPELINE_ID_1][idx2] =
            HW_RD_REG32(baseAddr + DISPC_VID1_FIR_COEF_H(idx2));
        pCtx->vidFIRCoeffHV[DSS_DISPC_VID_PIPELINE_ID_1][idx2] =
            HW_RD_REG32(baseAddr + DISPC_VID1_FIR_COEF_HV(idx2));
        pCtx->vidFIRCoeffH[DSS_DISPC_VID_PIPELINE_ID_2][idx2] =
            HW_RD_REG32(baseAddr + DISPC_VID2_FIR_COEF_H(idx2));
        pCtx->vidFIRCoeffHV[DSS_DISPC_VID_PIPELINE_ID_2][idx2] =
            HW_RD_REG32(baseAddr + DISPC_VID2_FIR_COEF_HV(idx2));
    }
}


void DSSContextRestore(uint32_t baseAddr, dssContext_t *pCtx)
{
    uint32_t idx1 = 0U;
    uint32_t idx2 = 0U;

    HW_WR_REG32((baseAddr + DSS_SYSCONFIG), pCtx->dssSysConfig);

    /* Calculate the offset of Display controller */
    baseAddr = baseAddr + DSS_DISPC_OFFSET;

    HW_WR_REG32((baseAddr + DISPC_SYSCFG), pCtx->dispcSysConfig);
    HW_WR_REG32((baseAddr + DISPC_CFG), pCtx->config);
    HW_WR_REG32((baseAddr + DISPC_DEFAULT_COLOR(DSS_LCD_REG_IDX)),
        pCtx->defaultColor0);
    HW_WR_REG32((baseAddr + DISPC_TRANS_COLOR(DSS_LCD_REG_IDX)),
        pCtx->transColor0);
    HW_WR_REG32((baseAddr + DISPC_LINE_NUMBER), pCtx->lineNumber);
    HW_WR_REG32((baseAddr + DISPC_TIMING_H), pCtx->timingH);
    HW_WR_REG32((baseAddr + DISPC_TIMING_V), pCtx->timingV);
    HW_WR_REG32((baseAddr + DISPC_POL_FREQ), pCtx->polFreq);
    HW_WR_REG32((baseAddr + DISPC_DIVISOR), pCtx->divisor);
    HW_WR_REG32((baseAddr + DISPC_GLOBAL_ALPHA), pCtx->globalAlpha);
    HW_WR_REG32((baseAddr + DISPC_SIZE_LCD), pCtx->sizeLcd);

    /* graphics pipeline registers */
    HW_WR_REG32((baseAddr + DISPC_GFX_BA(DSS_LCD_REG_IDX)), pCtx->gfxBA0);
    HW_WR_REG32((baseAddr + DISPC_GFX_POSITION), pCtx->gfxPos);
    HW_WR_REG32((baseAddr + DISPC_GFX_SIZE), pCtx->gfxSize);
    HW_WR_REG32((baseAddr + DISPC_GFX_ATTRS), pCtx->gfxAttr);
    HW_WR_REG32((baseAddr + DISPC_GFX_FIFO_THR), pCtx->gfxFifoThr);
    HW_WR_REG32((baseAddr + DISPC_GFX_ROW_INC), pCtx->gfxRowInc);
    HW_WR_REG32((baseAddr + DISPC_GFX_PIXEL_INC), pCtx->gfxPixInc);
    HW_WR_REG32((baseAddr + DISPC_GFX_WINDOW_SKIP), pCtx->gfxWindowSkip);
    HW_WR_REG32((baseAddr + DISPC_GFX_TBL_BA), pCtx->gfxTableBA);

    /* Video pipeline registers */
    for(idx1 = 0U; idx1 < DSS_NUM_VID_PIPELINES; idx1++)
    {
        HW_WR_REG32((baseAddr + DISPC_VID_BA(idx1, DSS_LCD_REG_IDX)),
            pCtx->vidBA0[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_POSITION(idx1)), pCtx->vidPos[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_SIZE(idx1)), pCtx->vidSize[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_ATTRS(idx1)), pCtx->vidAttr[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_FIFO_THR(idx1)),
            pCtx->vidFifoThr[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_PIXEL_INC(idx1)),
            pCtx->vidPixInc[idx1]);
        HW_WR_REG32(
            (baseAddr + DISPC_VID_ROW_INC(idx1)), pCtx->vidRowInc[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_FIR(idx1)), pCtx->vidFIR[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_PICTURE_SIZE(idx1)),
            pCtx->vidPictureSize[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_ACCU(idx1, DSS_LCD_REG_IDX)),
            pCtx->vidAccu[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_CONV_COEF0(idx1)),
            pCtx->vidConvCoeff0[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_CONV_COEF1(idx1)),
            pCtx->vidConvCoeff1[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_CONV_COEF2(idx1)),
            pCtx->vidConvCoeff2[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_CONV_COEF3(idx1)),
            pCtx->vidConvCoeff3[idx1]);
        HW_WR_REG32((baseAddr + DISPC_VID_CONV_COEF4(idx1)),
            pCtx->vidConvCoeff4[idx1]);

        for(idx2 = 0U; idx2 < DSS_RESIZER_NUM_PHASES; idx2++)
        {
            HW_WR_REG32((baseAddr + DISPC_VID_FIR_COEF_V(idx1, idx2)),
                pCtx->vidFIRCoeffV[idx1][idx2]);
        }
    }

    for(idx2 = 0U; idx2 < DSS_RESIZER_NUM_PHASES; idx2++)
    {
        HW_WR_REG32((baseAddr + DISPC_VID1_FIR_COEF_H(idx2)),
            pCtx->vidFIRCoeffH[DSS_DISPC_VID_PIPELINE_ID_1][idx2]);
        HW_WR_REG32((baseAddr + DISPC_VID1_FIR_COEF_HV(idx2)),
            pCtx->vidFIRCoeffHV[DSS_DISPC_VID_PIPELINE_ID_1][idx2]);
        HW_WR_REG32((baseAddr + DISPC_VID2_FIR_COEF_H(idx2)),
            pCtx->vidFIRCoeffH[DSS_DISPC_VID_PIPELINE_ID_2][idx2]);
        HW_WR_REG32((baseAddr + DISPC_VID2_FIR_COEF_HV(idx2)),
            pCtx->vidFIRCoeffHV[DSS_DISPC_VID_PIPELINE_ID_2][idx2]);
    }

    HW_WR_REG32((baseAddr + DISPC_CTRL), pCtx->control);

    /* Enable interrupts after fully restring the context */
    HW_WR_REG32((baseAddr + DISPC_IRQEN), pCtx->irqEnable);
}