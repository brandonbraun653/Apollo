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
*
* \file  evmk2g_hdmi_panel.c
*
* \brief This file contains DSS Panel (HDMI) specific functions.
*
******************************************************************************/

#include "platform_internal.h"
#include "keystone_pll.h"

dispCfg_t dispCfg_hdmi = { 0, DSS_LCD_TYPE_ACTIVE, 3, 0};
dmaCfg_t vidDmaCfg_hdmi = {0x09FF, 0x09F8, 1, 1, 0x00080000, 2, 0, 0, 0, 0, 7};
tmgCfg_t tmgCfg_hdmi = {0,0,0,0,0,1,0,0,0,0,0,0};

dssInfo_t   *dssInfo_hdmi;

extern void init_pll(const pllcConfig *data);

/**
 * \brief This function initializes HDMI Panel module.
 *
 * This function should be called before using any other DSS functions.
 * This function configures the HDMI parameters and then configures DSS.
 *
 * \param
 *      hdmiCfg     - pointer to HDMI configuration
 *
 * \return
 *      DSS_RET_OK - If successful
 *      DSS_RET_FAILED - If failure
 *
 */
DSS_RET hdmiPanelInit(lcdCfg_t *hdmiCfg)
{
    DSS_RET status = DSS_RET_OK;
    pllcConfig    pll_data;

    dssInfo_hdmi = (dssInfo_t *)malloc(sizeof(dssInfo_t));
    if (dssInfo_hdmi == NULL)
        return DSS_RET_FAILED;

    /* Configure PLL for LCD PCLK - 24MHz input clock */
    pll_data.pll    = CSL_PLL_DSS;
    pll_data.pll_m	= 198;  // Multiply by 198
    pll_data.pll_d	= 12;   // Divide by 12
    pll_data.pll_od	= 16;   // Divide by 16

    init_pll(&pll_data);

    memcpy(&dssInfo_hdmi->lcdCfg, hdmiCfg, sizeof(lcdCfg_t));
    memcpy(&dssInfo_hdmi->dispCfg, &dispCfg_hdmi, sizeof(dispCfg_t));
    memcpy(&dssInfo_hdmi->vidDmaCfg, &vidDmaCfg_hdmi, sizeof(dmaCfg_t));
    memset(&dssInfo_hdmi->tmgCfg, 0, sizeof(tmgCfg_t));

    status = dssInit(dssInfo_hdmi);
#if (PLATFORM_DEBUG)
    dssDumpReg(dssInfo_hdmi);
#endif

    return status;
}

/**
 * \brief Display color bar on the HDMI
 *
 * This function calls the function to put the color bar information on the framebuffer
 * and hence displays the Color bar on the HDMI screen
 *
 * \param
 *      hdmiCfg     - pointer to HDMI configuration
 *
 * \return
 *          None
 *
 */
void hdmiColorBarDisplay(lcdCfg_t *hdmiCfg)
{
    dssInitFrameBuffer(RGB888_GENERATE, hdmiCfg->LcdWidth, hdmiCfg->LcdHeight);
}

/**
 * \brief Display a single color on the HDMI screen
 *
 * This function calls the function to put a single color passed as an argument on the framebuffer
 * and hence displays the Color screen on the HDMI screen
 *
 * \param
 *      hdmiCfg     - pointer to HDMI configuration
 *      color       - Color to be displayed on the screen.
 *
 * \return
 *          None
 *
 */
void hdmiColorDisplay(lcdCfg_t *hdmiCfg, int color)
{
     dssFrameBufferColor( hdmiCfg, color );
}

/* Nothing past this point */
