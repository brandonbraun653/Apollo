/**
 *  \file  hsmmcsd_lib_port.h
 *
 * \brief  This file contains the porting of HSMMCSD IP for MMCSD library.
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

#ifndef HSMMCSD_LIB_PORT_H_
#define HSMMCSD_LIB_PORT_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include "error.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/**
 * \brief    Check if the card is inserted and detected
 *
 * \param    pCtrl It holds the mmcsd control information.
 *
 * \retval   TRUE    if the card is inserted and detected
 * \retval   FALSE   if the card is not inserted and detected
 *
 * \note: that this functional may not be available for all instances of the
 * controller. This function, is only useful of the controller has a dedicated
 * card detect pin. If not, the card detection mechanism is application
 * implementation specific
 **/
uint32_t HSMMCSDLibPortIsCardPresent(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief    Enables the controller events to generate a h/w interrupt request
 *
 * \param    pCtrl It holds the mmcsd control information.
 *
 **/
void HSMMCSDLibPortIntrEnable(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief    This function initializes the mmcsd controller.
 *
 * \param    pCtrl It holds the mmcsd control information.
 *
 * \retval   TRUE -  Initialization is successful.
 * \retval   FALSE - Initialization is failed.
 **/
uint32_t HSMMCSDLibPortCtrlInit(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief    This function sends the command to MMCSD.
 *
 * \param    pCtrl    It holds the mmcsd control information.
 * \param    pCmd         It determines the mmcsd cmd
 *
 * \retval   status               Status of the command.
 *
 **/
uint32_t HSMMCSDLibPortCmdSend(mmcsdLibCtrlInfo_t *pCtrl, mmcsdLibCmd_t *pCmd);

/**
 * \brief    Configure the MMC/SD bus width
 *
 * \param    pCtrl It holds the mmcsd control information.
 * \param    busWidth           SD/MMC bus width. Bus width can take the values.
 *                              - HS_MMCSD_BUS_WIDTH_4BIT.\n
 *                              - HS_MMCSD_BUS_WIDTH_1BIT.\n
 *
 * \retval   TRUE  - Bus width configuration successful.
 * \retval   FALSE - Bus width configuration is failed.
 **/
uint32_t HSMMCSDLibPortBusWidthConfig(mmcsdLibCtrlInfo_t *pCtrl, uint32_t busWidth);

/**
 * \brief    Set output bus frequency
 *
 * \param    pCtrl It holds the mmcsd control information.
 * \param    busFreq            The required output frequency on the bus
 *
 * \retval   E_PASS  on clock enable success
 * \retval   E_FAIL  on clock enable fail
 **/
int32_t HSMMCSDLibPortBusFreqConfig(mmcsdLibCtrlInfo_t *pCtrl, uint32_t busFreq);

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef HSMMCSD_LIB_PORT_H_ */
