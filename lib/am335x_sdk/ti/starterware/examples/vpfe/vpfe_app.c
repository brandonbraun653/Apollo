/**
 * \file   vpfe_app.c
 *
 * \brief  Source file containing the VPFE IP related configuration functions.
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
#include "error.h"
#include "console_utils.h"

/* Application header files */
#include "vpfe_app.h"
#include "prcm.h"


/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API performs the configuration of VPFE IP. This configures
 *          VPFE input, output interfaces and advanced image processing
 *          features.
 *
 * \param   pVpfe   Pointer to the VPFE application data structure.
 */
void VpfeAppIpConfig(vpfeAppObj_t *pVpfe);


/**
 * \brief   This API configures the input interface of the VPFE like type of
 *          input interface, input width etc.
 *
 * \param   baseAddr  Memory address of VPFE instance used.
 * \param   pInput    Pointer to the VPFE input configuration data structure.
 */
void VpfeAppInputConfig(uint32_t baseAddr, vpfeInputCfg_t *pInput);


/**
 * \brief   This API configures the output interface of the VPFE like output
 *          width and output formatting.
 *
 * \param   baseAddr  Memory address of VPFE instance used.
 * \param   pOutput   Pointer to the VPFE output configuration data structure.
 */
void VpfeAppOutputConfig(uint32_t baseAddr, vpfeOutputCfg_t *pOutput);


/**
 * \brief   This API configures the advanced image processing. This includes
 *          configuration of optical black clamping, black level compensation,
 *          lpf, Alaw processing.
 *
 * \param   baseAddr    Memory address of VPFE instance used.
 * \param   inputMode   Input interface mode.
 * \param   pAdv        Pointer to advanced image processing configurations.
 */
void VpfeAppAdvConfig(uint32_t baseAddr,
                      uint32_t inputMode,
                      vpfeAdvCfg_t *pAdv);


/**
 * \brief   This API configures the VPFE interrupts and enables them.
 *
 * \param   baseAddr  Memory address of VPFE instance used.
 * \param   frmHeight Image height in number of lines per frame.
 */
void VpfeAppIntrConfig(uint32_t baseAddr, uint32_t frmHeight);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief Default values of display sub system IP configuration data
           structure. */
vpfeAppObj_t   VPFEAPPOBJ_DEFAULT =
{
    0U,   /* vpfeInstNum */
    0U,   /* vpfeInstAddr */
    0U,   /* vpfeSysIntrNum */
    0U,   /* vpfeCameraDeviceId */
    0U,   /* cameraI2cInstNum */
    NULL, /* pFnIsrCb */
    0U,   /* inputBufAddr */
    0U,   /* outputBufAddr */
    0U,   /* outputBufSize */
    0U,   /* inputFrmWidth */
    0U,   /* inputFrmHeight */
    0U,   /* inputPixelFmt */
    {
        {
            {
                VPFE_INPUT_MODE_RAW, /* inputMode */
                VPFE_IN_WIDTH_10_BITS, /* inputDataWidth */
                0U,                    /* inputDataPolarity */
                {
                    VPFE_H_SYNC_POLARITY_POSITIVE, /* hSyncPolarity */
                    VPFE_V_SYNC_POLARITY_POSITIVE, /* vSyncPolarity */
                    VPFE_VDHD_DIR_INPUT, /* hvSyncDirection */
                }, /* syncCfg*/
                {
                    VPFE_YC_IN_SWAP_CFG_NOSWAP, /* ycInSwap */
                    VPFE_Y8_POS_EVEN,  /* y8Pos */
                }, /* ycbcrInCfg */
                VPFE_FIELD_MODE_NON_INTERLACED, /* fieldMode */
                0U, /* fieldDir */
                0U, /* fieldPolarity */
            }, /* inputCfg */
            {
                {
                    0U, /* sph */
                    0U, /* nph */
                    0U, /* slv0 */
                    0U, /* slv1 */
                    0U, /* nlv  */
                }, /* frmCfg */
                VPFE_OUT_DATA_WIDTH_16_BITS, /* outDataSize */
                FALSE, /* inverseImgEnable */
                {
                    0U, /* lnOffset  */
                    0U, /* fldOffset */
                    0U, /* lnOffset0 */
                    0U, /* lnOffset1 */
                    0U, /* lnOffset2 */
                    0U, /* lnOffset3 */
                }, /* lnOffsetCfg */
            }, /* outputCfg */
        }, /* vpfeCfg_t */
        NULL, /* pAdvCfg */
    } /* vpfeAppCfg_t */
};


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t VPFEAppInit(vpfeAppObj_t *pVpfe)
{
    int32_t status = S_PASS;

    /* Clock configuration */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_VPFE, pVpfe->vpfeInstNum, FALSE);
    if (S_PASS != status)
    {
        CONSOLEUtilsPrintf("\n Clock configuration is failed \n");
    }
    else
    {
        /* Pin Mux configuration */
        status = PINMUXModuleConfig(CHIPDB_MOD_ID_VPFE, pVpfe->vpfeInstNum,
            NULL);
        if (S_PASS != status)
        {
            CONSOLEUtilsPrintf("\n Pin mux configuration is failed \n");
        }
        else
        {
            /* VPFE IP configuration */
            VpfeAppIpConfig(pVpfe);

            status = S_PASS;
        }
    }

    return status;
}

/* ========================================================================== */
/*                        Internal Function Definitions                       */
/* ========================================================================== */

void VpfeAppIpConfig(vpfeAppObj_t *pVpfe)
{
    uint32_t baseAddr = pVpfe->vpfeInstAddr;
    uint32_t inputMode = pVpfe->vpfeCfg.ioCfg.inputCfg.inputMode;

    /* Disable VPFE output */
    VPFEModuleEnable(baseAddr, FALSE);

    /* Idle and standby mode configurations. */
    VPFESetIdleMode(baseAddr, VPFE_IDLE_MODE_NO_IDLE);
    VPFESetStandbyMode(baseAddr, VPFE_STANDBY_MODE_NO);

    /* Input configuration */
    VpfeAppInputConfig(baseAddr, &pVpfe->vpfeCfg.ioCfg.inputCfg);

    /* Output configuration */
    VpfeAppOutputConfig(baseAddr, &pVpfe->vpfeCfg.ioCfg.outputCfg);

    /* Advanced Image processing configuration */
    VpfeAppAdvConfig(baseAddr, inputMode, pVpfe->vpfeCfg.pAdvCfg);

    /* Set VPFE output buffer address. */
    VPFESetBufAddr(baseAddr, pVpfe->inputBufAddr);

    /* Interrupt configuration */
    VpfeAppIntrConfig(baseAddr, pVpfe->inputFrmHeight);

    /* Enable VPFE output */
    VPFEModuleEnable(baseAddr, TRUE);
}


void VpfeAppInputConfig(uint32_t baseAddr, vpfeInputCfg_t *pInput)
{
    /* Raw mode configuration */
    if(VPFE_INPUT_MODE_RAW == pInput->inputMode)
    {
        VPFERawModeConfig(baseAddr, pInput->inputDataWidth,
            pInput->inputDataPolarity);
    }

    /* YCBCR mode configuration */
    if(VPFE_INPUT_MODE_YCBCR == pInput->inputMode)
    {
        VPFEYcbcrModeConfig(baseAddr, pInput->inputDataWidth,
            pInput->inputDataPolarity);

        if(VPFE_IN_WIDTH_8_BITS == pInput->inputDataWidth)
        {
            VPFEYcbcr8BitConfig(baseAddr, pInput->ycbcrInCfg.ycInSwap,
                pInput->ycbcrInCfg.y8Pos);
        }

        if(VPFE_IN_WIDTH_16_BITS == pInput->inputDataWidth)
        {
            VPFEYcbcr16BitConfig(baseAddr, pInput->ycbcrInCfg.ycInSwap);
        }
    }

    /* Synchronization signal configuration */
    VPFESyncSignalConfig(baseAddr, &pInput->syncCfg);

    /* Field Mode configuration */
    VPFESetFieldMode(baseAddr, pInput->fieldMode);

    /* Perform additional configurations for Interlaced field mode */
    if(VPFE_FIELD_MODE_INTERLACED == pInput->fieldMode)
    {
        VPFEInterlacedFieldParamsCfg(baseAddr, pInput->fieldPolarity,
            pInput->fieldDir);
    }
}


void VpfeAppOutputConfig(uint32_t baseAddr, vpfeOutputCfg_t *pOutput)
{
    /* Configure output frame resolution */
    VPFEOutputFrameResConfig(baseAddr, &pOutput->frmCfg);

    /* Configure output frame format */
    VPFEOutputFormatConfig(baseAddr, pOutput->outDataSize,
        pOutput->inverseImgEnable, &pOutput->lnOffsetCfg);

    /* Enable data write to memory */
    VPFEOutputEnable(baseAddr);
}


void VpfeAppAdvConfig(uint32_t baseAddr, uint32_t inputMode, vpfeAdvCfg_t *pAdv)
{
    uint32_t enableLpf = 0U;
    uint32_t dcSubLvl = 0U;
    vpfeObClampCfg_t *pObc = NULL;

    if (NULL != pAdv)
    {
        /* Optical black clamping */
        if(TRUE == pAdv->obcCfg.obEnable)
        {
            dcSubLvl = (VPFE_INPUT_MODE_RAW == inputMode) ? 0U : pAdv->dcSubLvl;
            pObc    = (VPFE_INPUT_MODE_RAW == inputMode) ? &pAdv->obcCfg : NULL;

            VPFEOptBlackClampingCfg(baseAddr, inputMode, dcSubLvl, pObc);
        }
        else
        {
            dcSubLvl = (VPFE_INPUT_MODE_RAW == inputMode) ? pAdv->dcSubLvl : 0U;

            VPFEOptBlackClampingDisable(baseAddr, inputMode, dcSubLvl);
        }


        /* Black level compensation */
        VPFEBlackLvlCompensationCfg(baseAddr, inputMode,
            &pAdv->blkCompensation);

        /* LPF processing */
        enableLpf =
            (VPFE_INPUT_MODE_RAW == inputMode) ? pAdv->lpfEnable : FALSE;
        VPFELpfEnable(baseAddr, enableLpf);

        /* A Law compression */
        if (VPFE_INPUT_MODE_YCBCR == inputMode)
        {
            VPFEAlawCompressionDisable(baseAddr);
        }

        if(VPFE_INPUT_MODE_RAW == inputMode)
        {
            if(TRUE == pAdv->alawEnable)
            {
                VPFEAlawCompressionEnable(baseAddr, pAdv->alawInWidth);
            }
            else
            {
                VPFEAlawCompressionDisable(baseAddr);
            }
        }
    }
}


void VpfeAppIntrConfig(uint32_t baseAddr, uint32_t frmHeight)
{
    uint32_t hSyncCnt = (frmHeight / 2U);

    /* configure VD1 for half the height of the image */
    VPFESetIntrHSyncCnt(baseAddr, VPFE_INTR_MASK_VD1, hSyncCnt);
    VPFEIntrEnable(baseAddr, VPFE_INTR_MASK_VD1);

    /* configure VD0 for 1 Hsync. */
    VPFESetIntrHSyncCnt(baseAddr, VPFE_INTR_MASK_VD0, 1U);
    VPFEIntrEnable(baseAddr, VPFE_INTR_MASK_VD0);
}