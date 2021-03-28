/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
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
 * \file	evmc66x_pinmux.h
 *
 * \brief	This file is the header	file for pin mux module
 *
 ******************************************************************************/

#ifndef	_EVMC66X_PINMUX_H_
#define	_EVMC66X_PINMUX_H_

#ifdef __cplusplus
extern "C" {
#endif

/** Maximum number of pad config registers supported */
#define PADCONFIG_MAX_COUNT    (260)

/**
 * \brief Mux mode selection for pad config registers
 */
typedef enum _PadCfgMuxMode
{
    PADCONFIG_MUX_MODE_PRIMARY = 0,  /**< Primary pin mux mode    */
    PADCONFIG_MUX_MODE_SECONDARY,    /**< Secondary pin mux mode  */
    PADCONFIG_MUX_MODE_TERTIARY,     /**< Tertiary pin mux mode   */
    PADCONFIG_MUX_MODE_QUATERNARY,   /**< Quaternary pin mux mode */
    PADCONFIG_MUX_MODE_QUINARY,      /**< Quinary pin mux mode    */
    PADCONFIG_MUX_MODE_SENARY        /**< Senary pin mux mode     */

} PadCfgMuxMode;

/**
 * \brief  Configures default mode for pin muxing in pad config registers
 *
 * \return  none
 */
void pinMuxInit(void);

/**
 * \brief  Configures pin mux mode of a pad config register
 *
 * \param   padCfgId [IN]    Pad config register Id; 0 - 259
 * \param   muxMode  [IN]    Pad config mux mode
 *
 * \return
 * \n       0  - Mux mode configuration is successful
 * \n      -1  - Invalid parameter
 */
int32_t plat_pinMuxSetMode(uint16_t padCfgId, PadCfgMuxMode muxMode);

#ifdef __cplusplus
}
#endif

#endif /* _EVMC66X_PINMUX_H_ */

/* Nothing past this point */
