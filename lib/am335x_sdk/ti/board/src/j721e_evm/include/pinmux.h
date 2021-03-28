/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *
 *****************************************************************************/

/**
 * \file   pinmux.h
 *
 * \brief  Pinmux header file
 *
 * This file includes the pinmux configuration structures
 *
 */

#ifndef PINMUX_H
#define PINMUX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/tistdtypes.h>

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief Structure defining the pin configuration parameters.
 *
 */
typedef struct pinmuxPerCfg
{
    int16_t pinOffset;
    /**< Register offset for configuring the pin */
    int32_t pinSettings;
    /**< Value to be configured,
          - Active mode configurations like mux mode, pull resistor, and buffer mode
    */
}pinmuxPerCfg_t;

/**
 *  \brief Structure defining the pin configuration for different instances of
 *         a module.
 */
typedef struct pinmuxModuleCfg
{
    int16_t modInstNum;
    /**< Instance number of the ip */
    int16_t doPinConfig;
    /**< Flag indicating whether this instance has to be configured. This flag
         can be altered with separate API (PinMuxConfigEnable()).
         Default configuration will be set to TRUE, but can be altered for
         different scenarios (like power management). */
    pinmuxPerCfg_t* instPins;
    /**< Pointer to list of pins corresponding to this instance */
}pinmuxModuleCfg_t;

/**
 *  \brief Structure defining the pin configuration of a board.
 */
typedef struct pinmuxBoardCfg
{
    int32_t moduleId;
    /**< Module ID */
    pinmuxModuleCfg_t* modulePinCfg;
    /**< Pin config info of a module: #pinmuxModuleCfg_t */
}pinmuxBoardCfg_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
