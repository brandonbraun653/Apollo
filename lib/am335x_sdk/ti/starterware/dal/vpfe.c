/**
 *  \file     vpfe.c
 *
 *  \brief    This file contains the device abstraction layer APIs for VPFE
 *            peripheral.
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
#include "hw_types.h"
#include "vpfe.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

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

uint32_t VPFEGetRevision(uint32_t baseAddr)
{
    return (HW_RD_REG32(baseAddr + VPFE_REVISION));
}


void VPFEModuleEnable(uint32_t baseAddr, uint32_t enableVpfe)
{
    if (TRUE == enableVpfe)
    {
        HW_WR_FIELD32((baseAddr + VPFE_CONFIG), VPFE_CONFIG_EN, VPFE_CONFIG_EN_ENABLE);
        /* Enable VPFE module */
        HW_WR_FIELD32((baseAddr + VPFE_PCR), VPFE_PCR_EN, VPFE_PCR_EN_ENABLE);

    }
    else
    {
        /* Disable VPFE module */
        HW_WR_FIELD32((baseAddr + VPFE_PCR), VPFE_PCR_EN, VPFE_PCR_EN_DISABLE);
    }
}


void VPFERawModeConfig(uint32_t baseAddr,
                       uint32_t inputDataWidth,
                       uint32_t dataPolarity)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + VPFE_SYNMODE);

    /* Configure the input interface to RAW Mode */
    HW_SET_FIELD(regVal, VPFE_SYNMODE_INPMOD, VPFE_SYNMODE_INPMOD_CCD_RAW);

    /* Configure the input data width */
    HW_SET_FIELD(regVal, VPFE_SYNMODE_DATSIZ, inputDataWidth);

    /* Configure the input data polarity */
    HW_SET_FIELD(regVal, VPFE_SYNMODE_DATAPOL, dataPolarity);

    HW_WR_REG32((baseAddr + VPFE_SYNMODE), regVal);
}


void VPFEYcbcrModeConfig(uint32_t baseAddr,
                         uint32_t inputDataWidth,
                         uint32_t dataPolarity)
{
    uint32_t inputMode = 0U;
    uint32_t regVal = HW_RD_REG32(baseAddr + VPFE_SYNMODE);

    if (VPFE_IN_WIDTH_8_BITS == inputDataWidth)
    {
        inputMode = VPFE_SYNMODE_INPMOD_YCBCR8;
    }
    else if (VPFE_IN_WIDTH_16_BITS == inputDataWidth)
    {
        inputMode = VPFE_SYNMODE_INPMOD_YCBCR16;
    }
    else
    {
        /*
         * This error does not happen because user is expected to pass in the
         * correct parameters.
         */
    }

    /* Configure the input interface to YCbCr8/YCbCr16 Mode */
    HW_SET_FIELD(regVal, VPFE_SYNMODE_INPMOD, inputMode);

    /* Set the input data polarity */
    HW_SET_FIELD(regVal, VPFE_SYNMODE_DATAPOL, dataPolarity);

    HW_WR_REG32((baseAddr + VPFE_SYNMODE), regVal);

    /* Set 656Mode on */
    HW_WR_FIELD32((baseAddr + VPFE_REC656IF),
        VPFE_REC656IF_R656ON, VPFE_REC656IF_R656ON_ENABLE);
}


void VPFEYcbcr16BitConfig(uint32_t baseAddr, uint32_t ycInSwap)
{
    HW_WR_FIELD32((baseAddr + VPFE_CCDCFG), VPFE_CCDCFG_YCINSWP, ycInSwap);
}


void VPFEYcbcr8BitConfig(uint32_t baseAddr,
                         uint32_t activeInputLines,
                         uint32_t y8Position)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + VPFE_CCDCFG);

    /* Configure the active input lines */
    HW_SET_FIELD(regVal, VPFE_CCDCFG_YCINSWP, activeInputLines);

    /* Configure the Y8 Position */
    HW_SET_FIELD(regVal, VPFE_CCDCFG_Y8POS, y8Position);

    HW_WR_REG32((baseAddr + VPFE_CCDCFG), regVal);
}


void VPFESyncSignalConfig(uint32_t baseAddr, vpfeHvSyncCfg_t *pSigCfg)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + VPFE_SYNMODE);

    /* HSync polarity configuration */
    HW_SET_FIELD(regVal, VPFE_SYNMODE_HDPOL, pSigCfg->hSyncPolarity);

    /* VSync polarity configuration*/
    HW_SET_FIELD(regVal, VPFE_SYNMODE_VDPOL, pSigCfg->vSyncPolarity);

    /* H/VSync direction configuration */
    HW_SET_FIELD(regVal, VPFE_SYNMODE_VDHDOUT, pSigCfg->hvSyncDirection);

    HW_WR_REG32((baseAddr + VPFE_SYNMODE), regVal);
}


void VPFESetFieldMode(uint32_t baseAddr, uint32_t fieldMode)
{
    HW_WR_FIELD32((baseAddr + VPFE_SYNMODE), VPFE_SYNMODE_FLDMODE, fieldMode);
}


void VPFEInterlacedFieldParamsCfg(uint32_t baseAddr,
                                  uint32_t fieldPolarity,
                                  uint32_t direction)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + VPFE_SYNMODE);

    /* Set field polarity */
    HW_SET_FIELD(regVal, VPFE_SYNMODE_FLDPOL, fieldPolarity);

    /* Set field direction */
    HW_SET_FIELD(regVal, VPFE_SYNMODE_FLDOUT, direction);

    HW_WR_REG32((baseAddr + VPFE_SYNMODE), regVal);
}


void VPFEOptBlackClampingCfg(uint32_t baseAddr,
                             uint32_t inputMode,
                             uint32_t dcSubLevel,
                             vpfeObClampCfg_t *pObcCfg)
{
    uint32_t regVal = 0U;

    if (VPFE_INPUT_MODE_RAW == inputMode)
    {
        regVal = HW_RD_REG32(baseAddr + VPFE_CLAMP);

        /* Set Optical black sample length */
        HW_SET_FIELD(regVal, VPFE_CLAMP_OBSLEN, pObcCfg->obSampleLength);

        /* Set Optical black sample lines */
        HW_SET_FIELD(regVal, VPFE_CLAMP_OBSLN, pObcCfg->obSampleLines);

        /* Set Start pixel of optical black samples */
        HW_SET_FIELD(regVal, VPFE_CLAMP_OBST, pObcCfg->obStartPixel);

        /* Set Gain to apply to the optical black average */
        HW_SET_FIELD(regVal, VPFE_CLAMP_OBGAIN, pObcCfg->obgain);

        /* Enable Optical black clamping feature */
        HW_SET_FIELD(regVal, VPFE_CLAMP_CLAMPEN, VPFE_CLAMP_CLAMPEN_ENABLE);

        HW_WR_REG32((baseAddr + VPFE_CLAMP), regVal);
    }
    else if (VPFE_INPUT_MODE_YCBCR == inputMode)
    {
        /* For YCbCr mode to enable this feature, it is enough to configure,
         * DC level value, that needs to be subtracted from the input data.
         */
        HW_WR_FIELD32((baseAddr + VPFE_DCSUB), VPFE_DCSUB, dcSubLevel);
    }
    else
    {
        /*
         * This error does not happen because user is expected to pass in the
         * correct parameters.
         */
    }
}


void VPFEOptBlackClampingDisable(uint32_t baseAddr,
                                 uint32_t inputMode,
                                 uint32_t dcSubLevel)
{
    if (VPFE_INPUT_MODE_RAW == inputMode)
    {
        /* For raw mode disable the optical black clamping feature */
        HW_WR_FIELD32((baseAddr + VPFE_CLAMP),
            VPFE_CLAMP_CLAMPEN, VPFE_CLAMP_CLAMPEN_DISABLE);

        /* Set the fixed DC level value */
        HW_WR_FIELD32((baseAddr + VPFE_DCSUB), VPFE_DCSUB, dcSubLevel);
    }
    else if (VPFE_INPUT_MODE_YCBCR == inputMode)
    {
        /* For YCbCr mode, to disable the above feature write 0 to DC level
         * value.
         */
        HW_WR_FIELD32((baseAddr + VPFE_DCSUB), VPFE_DCSUB, 0U);
    }
    else
    {
        /*
         * This error does not happen because user is expected to pass in the
         * correct parameters.
         */
    }
}


void VPFEBlackLvlCompensationCfg(uint32_t baseAddr,
                                 uint32_t inputMode,
                                 vpfeBlkLvlCompensationCfg_t *pBlkCfg)
{
    vpfeColorPatternCfg_t *pPtn;
    uint32_t regVal = 0U;
    vpfeBlkLvlCompensationCfg_t blkCfg;

    /* Set all the configuration values to zero if input mode is YCbCr */
    if (VPFE_INPUT_MODE_YCBCR == inputMode)
    {
        memset(&blkCfg, 0U, sizeof(vpfeBlkLvlCompensationCfg_t));
        pBlkCfg = &blkCfg;
    }
    pPtn = pBlkCfg->clrPtn;

    /* Set black level compensation for R/ye, Gr/Cy, Gb/g, B/Mg pixels */
    regVal = HW_RD_REG32(baseAddr + VPFE_BLKCMP);
    HW_SET_FIELD(regVal, VPFE_BLKCMP_RYE, pBlkCfg->rYe);
    HW_SET_FIELD(regVal, VPFE_BLKCMP_GRCY, pBlkCfg->grCy);
    HW_SET_FIELD(regVal, VPFE_BLKCMP_GBG, pBlkCfg->gbG);
    HW_SET_FIELD(regVal, VPFE_BLKCMP_BMG, pBlkCfg->bMg);
    HW_WR_REG32((baseAddr + VPFE_BLKCMP), regVal);

    /* Configuration of color pattern types of pixels */
    regVal = HW_RD_REG32(baseAddr + VPFE_COLPTN);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP0LPC0, pPtn[0].pixelCnt0);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP0LPC1, pPtn[0].pixelCnt1);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP0LPC2, pPtn[0].pixelCnt2);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP0LPC3, pPtn[0].pixelCnt3);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP1LPC0, pPtn[1].pixelCnt0);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP1LPC1, pPtn[1].pixelCnt1);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP1LPC2, pPtn[1].pixelCnt2);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP1LPC3, pPtn[1].pixelCnt3);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP2LPC0, pPtn[2].pixelCnt0);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP2LPC1, pPtn[2].pixelCnt1);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP2LPC2, pPtn[2].pixelCnt2);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP2LPC3, pPtn[2].pixelCnt3);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP3LPC0, pPtn[3].pixelCnt0);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP3LPC1, pPtn[3].pixelCnt1);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP3LPC2, pPtn[3].pixelCnt2);
    HW_SET_FIELD(regVal, VPFE_COLPTN_CP3LPC3, pPtn[3].pixelCnt3);
    HW_WR_REG32((baseAddr + VPFE_COLPTN), regVal);
}


void VPFEOutputFrameResConfig(uint32_t baseAddr, vpfeOutputFrameResCfg_t *pCfg)
{
    uint32_t regVal = 0U;

    /* Set Horizontal start pixel and number of horizontal pixels */
    regVal = HW_RD_REG32(baseAddr + VPFE_HORZ_INFO);
    HW_SET_FIELD(regVal, VPFE_HORZ_INFO_SPH, pCfg->sph);
    HW_SET_FIELD(regVal, VPFE_HORZ_INFO_NPH, (pCfg->nph - 1U));
    HW_WR_REG32((baseAddr + VPFE_HORZ_INFO), regVal);

    /* Set Vertical start line for Field 0 and Field1 */
    regVal = HW_RD_REG32(baseAddr + VPFE_VERT_START);
    HW_SET_FIELD(regVal, VPFE_VERT_START_SLV0, pCfg->slv0);
    HW_SET_FIELD(regVal, VPFE_VERT_START_SLV1, pCfg->slv1);
    HW_WR_REG32((baseAddr + VPFE_VERT_START), regVal);

    /* Set Number of Vertical Lines */
    HW_WR_FIELD32((baseAddr + VPFE_VERT_LINES), VPFE_VERT_LINES_NLV, (pCfg->nlv - 1U));
}


void VPFELpfEnable(uint32_t baseAddr, uint32_t enableLpf)
{
    if (TRUE == enableLpf)
    {
        /* Enable LPF */
        HW_WR_FIELD32((baseAddr + VPFE_SYNMODE),
            VPFE_SYNMODE_LPF, VPFE_SYNMODE_LPF_ON);
    }
    else
    {
        /* Disable LPF */
        HW_WR_FIELD32((baseAddr + VPFE_SYNMODE),
            VPFE_SYNMODE_LPF, VPFE_SYNMODE_LPF_OFF);
    }
}


void VPFEAlawCompressionEnable(uint32_t baseAddr, uint32_t inputWidth)
{
    uint32_t regVal = 0U;

    /* Set A-law Width Input */
    HW_SET_FIELD(regVal, VPFE_ALAW_GWDI, inputWidth);

    /* Enable A-Law compression */
    HW_SET_FIELD(regVal, VPFE_ALAW_CCDTBL, VPFE_ALAW_CCDTBL_ENABLE);

    HW_WR_REG32((baseAddr + VPFE_ALAW), regVal);
}


void VPFEAlawCompressionDisable(uint32_t baseAddr)
{
    HW_WR_FIELD32((baseAddr + VPFE_ALAW),
        VPFE_ALAW_CCDTBL, VPFE_ALAW_CCDTBL_DISABLE);
}


void VPFEOutputFormatConfig(uint32_t baseAddr,
                            uint32_t outputWidth,
                            uint32_t inverseImage,
                            vpfeLineOffsetCfg_t *pLnOffsetCfg)
{
    uint32_t regVal = 0U;
    uint32_t invImg = (TRUE == inverseImage) ?
        VPFE_SDOFST_FIINV_INVERSE : VPFE_SDOFST_FIINV_NONINVERSE;

    /* Set output width normal(16bits) or packed(8bits) */
    HW_WR_FIELD32((baseAddr + VPFE_SYNMODE), VPFE_SYNMODE_PACK8, outputWidth);

    /* Set the address offset for each line */
    HW_WR_FIELD32((baseAddr + VPFE_HSIZE_OFF),
        VPFE_HSIZE_OFF_LNOFST, pLnOffsetCfg->lnOffset);

    regVal = HW_RD_REG32(baseAddr + VPFE_SDOFST);

    /* Set inverse image control */
    HW_SET_FIELD(regVal, VPFE_SDOFST_FIINV, invImg);

    /* Set Field offset */
    HW_SET_FIELD(regVal, VPFE_SDOFST_FOFST, pLnOffsetCfg->fldOffset);

    /* Set Offset value of even line and even field */
    HW_SET_FIELD(regVal, VPFE_SDOFST_LOFTS0, pLnOffsetCfg->lnOffset0);

    /* Set Offset value of odd line and odd field */
    HW_SET_FIELD(regVal, VPFE_SDOFST_LOFTS1, pLnOffsetCfg->lnOffset1);

    /* Set Offset value of even line and odd field */
    HW_SET_FIELD(regVal, VPFE_SDOFST_LOFTS2, pLnOffsetCfg->lnOffset2);

    /* Set Offset value of odd line and odd field */
    HW_SET_FIELD(regVal, VPFE_SDOFST_LOFTS3, pLnOffsetCfg->lnOffset3);

    HW_WR_REG32((baseAddr + VPFE_SDOFST), regVal);
}


void VPFESetBufAddr(uint32_t baseAddr, uint32_t bufAddr)
{
    HW_WR_REG32((baseAddr + VPFE_SDR_ADDR), bufAddr);
}


void VPFEOutputEnable(uint32_t baseAddr)
{
    /* Set write enable to write input image data to output memory */
    HW_WR_FIELD32((baseAddr + VPFE_SYNMODE),
        VPFE_SYNMODE_WEN, VPFE_SYNMODE_WEN_ENABLE);
}


void VPFEInternalVSyncLatchEnable(uint32_t baseAddr, uint32_t enableLatch)
{
    if (TRUE == enableLatch)
    {
        HW_WR_FIELD32((baseAddr + VPFE_CCDCFG),
            VPFE_CCDCFG_VDLC, VPFE_CCDCFG_VDLC_LATCHED);
    }
    else
    {
        HW_WR_FIELD32((baseAddr + VPFE_CCDCFG),
            VPFE_CCDCFG_VDLC, VPFE_CCDCFG_VDLC_NOT_LATCHED);
    }
}


void VPFESetIntrHSyncCnt(uint32_t baseAddr, uint32_t intrType, uint32_t hSyncCnt)
{
    /* Set Horizontal sync count after which interrupt should occur */
    if (VPFE_INTR_MASK_VD0 == intrType)
    {
        HW_WR_FIELD32((baseAddr + VPFE_VDINT), VPFE_VDINT_VDINT0, hSyncCnt);
    }
    else if (VPFE_INTR_MASK_VD1 == intrType)
    {
        HW_WR_FIELD32((baseAddr + VPFE_VDINT), VPFE_VDINT_VDINT1, hSyncCnt);
    }
    else
    {
        /*
         * This error does not happen because user is expected to pass in the
         * correct parameters.
         */
    }

    /* Set VDHD enable bit so that interrupts will be generated */
    HW_WR_FIELD32((baseAddr + VPFE_SYNMODE),
        VPFE_SYNMODE_VDHDEN, VPFE_SYNMODE_VDHDEN_ENABLE);
}


void VPFEIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + VPFE_IRQ_EN_SET);
    regVal |= intrMask;
    HW_WR_REG32((baseAddr + VPFE_IRQ_EN_SET), regVal);
}


void VPFEIntrDisable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + VPFE_IRQ_EN_SET);
    regVal &= (~intrMask);
    HW_WR_REG32((baseAddr + VPFE_IRQ_EN_SET), regVal);
}


void VPFEIntrClear(uint32_t baseAddr, uint32_t intrMask)
{
    HW_WR_REG32((baseAddr + VPFE_IRQ_STS), intrMask);
}


uint32_t VPFEIntrStatus(uint32_t baseAddr)
{
    return (HW_RD_REG32(baseAddr + VPFE_IRQ_STS));
}


uint32_t VPFEIntrRawStatus(uint32_t baseAddr)
{
    return (HW_RD_REG32(baseAddr + VPFE_IRQ_STS_RAW));
}


void VPFEIntrSetEoi(uint32_t baseAddr)
{
    HW_WR_FIELD32((baseAddr + VPFE_IRQ_EOI), VPFE_IRQ_EOI, VPFE_INTR_SET_EOI);
}


void VPFESetIdleMode(uint32_t baseAddr, uint32_t idleMode)
{
    HW_WR_FIELD32((baseAddr + VPFE_SYSCONFIG),
        VPFE_SYSCONFIG_IDLEMODE, idleMode);
}


void VPFESetStandbyMode(uint32_t baseAddr, uint32_t standbyMode)
{
    HW_WR_FIELD32((baseAddr + VPFE_SYSCONFIG),
        VPFE_SYSCONFIG_STANDBYMODE, standbyMode);
}


uint32_t VPFEIsBusy(uint32_t baseAddr)
{
    uint32_t retVal = FALSE;

    if(VPFE_PCR_BUSY == HW_RD_FIELD32((baseAddr + VPFE_PCR), VPFE_PCR_BUSY))
    {
        retVal = TRUE;
    }

    return retVal;
}


void VPFEContextSave(uint32_t baseAddr, vpfeContext_t *pCtx)
{
    pCtx->peripheralCtrl  = HW_RD_REG32(baseAddr + VPFE_PCR);
    pCtx->sysConfig       = HW_RD_REG32(baseAddr + VPFE_SYSCONFIG);
    pCtx->synMode         = HW_RD_REG32(baseAddr + VPFE_SYNMODE);
    pCtx->horzInfo        = HW_RD_REG32(baseAddr + VPFE_HORZ_INFO);
    pCtx->vertStart       = HW_RD_REG32(baseAddr + VPFE_VERT_START);
    pCtx->vertLines       = HW_RD_REG32(baseAddr + VPFE_VERT_LINES);
    pCtx->culling         = HW_RD_REG32(baseAddr + VPFE_CULLING);
    pCtx->hsizeOffset     = HW_RD_REG32(baseAddr + VPFE_HSIZE_OFF);
    pCtx->sdOffset        = HW_RD_REG32(baseAddr + VPFE_SDOFST);
    pCtx->sdrAddr         = HW_RD_REG32(baseAddr + VPFE_SDR_ADDR);
    pCtx->clamp           = HW_RD_REG32(baseAddr + VPFE_CLAMP);
    pCtx->dcSub           = HW_RD_REG32(baseAddr + VPFE_DCSUB);
    pCtx->colPtn          = HW_RD_REG32(baseAddr + VPFE_COLPTN);
    pCtx->blkCmp          = HW_RD_REG32(baseAddr + VPFE_BLKCMP);
    pCtx->vdInt           = HW_RD_REG32(baseAddr + VPFE_VDINT);
    pCtx->aLaw            = HW_RD_REG32(baseAddr + VPFE_ALAW);
    pCtx->rec656If        = HW_RD_REG32(baseAddr + VPFE_REC656IF);
    pCtx->ccdCfg          = HW_RD_REG32(baseAddr + VPFE_CCDCFG);
    pCtx->irqEnSet        = HW_RD_REG32(baseAddr + VPFE_IRQ_EN_SET);
}


void VPFEContextRestore(uint32_t baseAddr, vpfeContext_t *pCtx)
{
    HW_WR_REG32((baseAddr + VPFE_SYSCONFIG),  pCtx->sysConfig);
    HW_WR_REG32((baseAddr + VPFE_SYNMODE), pCtx->synMode);
    HW_WR_REG32((baseAddr + VPFE_HORZ_INFO), pCtx->horzInfo);
    HW_WR_REG32((baseAddr + VPFE_VERT_START), pCtx->vertStart);
    HW_WR_REG32((baseAddr + VPFE_VERT_LINES), pCtx->vertLines);
    HW_WR_REG32((baseAddr + VPFE_CULLING), pCtx->culling);
    HW_WR_REG32((baseAddr + VPFE_HSIZE_OFF), pCtx->hsizeOffset);
    HW_WR_REG32((baseAddr + VPFE_SDOFST), pCtx->sdOffset);
    HW_WR_REG32((baseAddr + VPFE_SDR_ADDR), pCtx->sdrAddr);
    HW_WR_REG32((baseAddr + VPFE_CLAMP), pCtx->clamp);
    HW_WR_REG32((baseAddr + VPFE_DCSUB), pCtx->dcSub);
    HW_WR_REG32((baseAddr + VPFE_COLPTN), pCtx->colPtn);
    HW_WR_REG32((baseAddr + VPFE_BLKCMP), pCtx->blkCmp);
    HW_WR_REG32((baseAddr + VPFE_VDINT), pCtx->vdInt);
    HW_WR_REG32((baseAddr + VPFE_ALAW), pCtx->aLaw);
    HW_WR_REG32((baseAddr + VPFE_REC656IF), pCtx->rec656If);
    HW_WR_REG32((baseAddr + VPFE_CCDCFG), pCtx->ccdCfg);
    HW_WR_REG32((baseAddr + VPFE_IRQ_EN_SET), pCtx->irqEnSet);
    HW_WR_REG32((baseAddr + baseAddr + VPFE_PCR), pCtx->peripheralCtrl);
}
