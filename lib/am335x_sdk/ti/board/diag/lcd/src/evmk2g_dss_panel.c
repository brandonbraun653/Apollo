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
 *  \file  evmk2g_dss_panel.c
 *
 *  \brief This file contains DSS Panel specific functions.
 *
 ******************************************************************************/

#include "platform_internal.h"
#include "keystone_pll.h"

#if (PLATFORM_DSS_IN)

dispCfg_t dispCfg = { 0, DSS_LCD_TYPE_ACTIVE, 3, 0};
dmaCfg_t vidDmaCfg = {0x09FF, 0x09F8, 1, 1, 0x00080000, 2, 0, 0, 0, 0, 7};

dssInfo_t   dssInfo;

extern void init_pll(const pllcConfig *data);

/**
 * \brief This function initializes LCD Panel module.
 *
 * This function should be called before using any other DSS functions.
 * This function configures the LCD parameters and then configures DSS.
 *
 * \param
 *      pLcdCfg     - pointer to LCD configuration
 *
 * \return
 *      DSS_RET_OK - If successful
 *      DSS_RET_FAILED - If failure
 *
 */
DSS_RET lcdPanelInit(lcdCfg_t *pLcdCfg)
{
    DSS_RET       status = DSS_RET_OK;
    pllcConfig    pll_data;


    memcpy(&dssInfo.lcdCfg, pLcdCfg, sizeof(lcdCfg_t));
    memcpy(&dssInfo.dispCfg, &dispCfg, sizeof(dispCfg_t));
    memcpy(&dssInfo.vidDmaCfg, &vidDmaCfg, sizeof(dmaCfg_t));
    memset(&dssInfo.tmgCfg, 0, sizeof(tmgCfg_t));

    /* Configure PLL for LCD PCLK - 24MHz input clock */
    pll_data.pll    = CSL_PLL_DSS;
    pll_data.pll_m	= 12;  // Multiply by 12
    pll_data.pll_d	= 4;   // Divide by 4
    pll_data.pll_od	= 8;   // Divide by 8

    init_pll(&pll_data);

    status = dssInit(&dssInfo);
#if (PLATFORM_DEBUG)
    dssDumpReg(&dssInfo);
#endif

    return status;
}


/**
 * \brief Display color bar on the LCD
 *
 * This function calls the function to put the color bar information on the framebuffer
 * and hence displays the Color bar on the LCD screen
 *
 * \param
 *      pLcdCfg     - pointer to LCD configuration
 *
 * \return
 *          None
 *
 */
void lcdColorBarDisplay(lcdCfg_t *pLcdCfg)
{
    dssInitFrameBuffer(RGB888_GENERATE, pLcdCfg->LcdWidth, pLcdCfg->LcdHeight);
}

#ifdef DISPLAY_LOGO
void lcdLogoDisplay(void)
{
	dssFillFrameBuffer();
}
#endif
/**
 * \brief Display a single color on the LCD screen
 *
 * This function calls the function to put a single color passed as an argument
 * on the framebuffer and hence displays the Color screen on the LCD screen
 *
 * \param
 *      pLcdCfg     - pointer to LCD configuration
 *      color       - Color to be displayed on the screen.
 *
 * \return
 *          None
 *
 */
void lcdColorDisplay(lcdCfg_t *pLcdCfg, int color)
{
     dssFrameBufferColor( pLcdCfg, color );
}

#endif /* #if (PLATFORM_DSS_IN) */

/* Nothing past this point */
