/******************************************************************************
 * Copyright (c) 2017-2019 Texas Instruments Incorporated - http://www.ti.com
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

/** \file board_clock.h
*
*   \brief This file contains structure, typedefs, functions and
*          prototypes used for am65xx-idk clock.
*/
 
#ifndef BOARD_CLOCK_H
#define BOARD_CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "board_internal.h"

/**
 *  \brief PSC configuration parameters
 *
 *  Each PSC in the device has several power domains that can be turned ON for
 *  operation or OFF to minimize power dissipation.
 *
 *  GPSC: Global Power Sleep Controller, is used to control the power gating
 *  of various power domains.
 * 
 *  LPSC: Local Power Sleep Controller, manages the clock gating for to each 
 *  logic block (or) module.
 * 
 *  domainNum: Power Domain Number
 * 
 *  moduleNum: Module Domain Number
 *
 */
typedef struct
{
	uint32_t domainNum;
	uint32_t moduleNum;
} pscConfig;

extern const pscConfig wkupPscConfigs[];

extern const pscConfig mainPscConfigs[];

extern uint32_t gBoardClkModuleID[];

/**
 *  \brief    This function is used to get the number of \
 *            wkup PSC configs exists.
 *
 * \return
 * \n         uint32_t - Number of wkup PSC configs.
 */
extern uint32_t Board_getNumWkupPscCconfigs();

/**
 *  \brief    This function is used to get the number of \
 *            main PSC configs exists.
 *
 * \return
 * \n         uint32_t - Number of main PSC configs.
 */
extern uint32_t Board_getNumMainPscCconfigs();

/**
 *  \brief    Returns number of module clocks
 *
 * \return
 * \n         uint32_t - number of module clocks
 */
extern uint32_t Board_getNumClkConfigs(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  /* BOARD_CLOCK_H */
