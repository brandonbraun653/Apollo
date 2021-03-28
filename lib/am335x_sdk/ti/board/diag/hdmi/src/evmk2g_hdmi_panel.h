/*
 * Copyright (c) 2015, Texas Instruments Incorporated
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
 * \file  evmc66x_hdmi_panel.h
 *
 * \brief This file contains HDMI panel specific structure, typedefs,
 *        function prototypes.
 *
 ******************************************************************************/

#ifndef _EVM66X_HDMI_PANEL_H_
#define _EVM66X_HDMI_PANEL_H_

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
DSS_RET hdmiPanelInit(lcdCfg_t *hdmiCfg);

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
void hdmiColorBarDisplay(lcdCfg_t *hdmiCfg);

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
void hdmiColorDisplay(lcdCfg_t *hdmiCfg, int color);

#endif // _EVM66X_HDMI_PANEL_H_

/* Nothing past this point */
