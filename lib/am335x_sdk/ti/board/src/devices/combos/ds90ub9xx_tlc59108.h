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
 *   \file    ds90ub9xx_tlc59108.h
 *
 * This file includes the structures, enums and register offsets
 * for initializing the FPD module for the communicating with the remote slave device.
 *
 */
#ifndef _DS90UB9XX_TLC59108_H_
#define _DS90UB9XX_TLC59108_H_

#include <ti/board/src/devices/common/common.h>
#include <ti/board/src/devices/fpd/ds90ub924.h>
#include <ti/board/src/devices/fpd/ds90ub941.h>
#include <ti/board/src/devices/sensors/tlc59108.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief  Pattern generation config
 *
 * This function is used to initialize the ub941 DSI module.
 *
 * \param   handle         [IN]  Low level driver handle
 * \param   fpdModParams   [IN]  FPD module params
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941PatternGenConfig(void *handle,
                                            Board_FpdModuleObj *fpdModParams);

/**
 * \brief  DSI module init
 *
 * This function is used to initialize the ub941 DSI module.
 *
 * \param   handle         [IN]  Low level driver handle
 * \param   fpdModParams   [IN]  FPD module params
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941DsiModuleInit(void *handle,
                                         Board_FpdModuleObj *fpdModParams);

/**
 * \brief  Board_ub941SerInit
 *
 * This function is used to initialize the serializer
 * connected to host controller.
 *
 * \param   handle        - pointer to the i2c handle
 * \param   fpdParams     – structure holding the fpd params.
 * \param   fpdRmtParams  – structure holding the remote device params.
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SerInit(void *handle,
                                   Board_FpdModuleObj *fpdParams,
                                   Board_FpdRmtDevObj *fpdRmtParams);

/**
 * \brief  DSI module init
 *
 * This function is used to initialize the ub941 DSI module.
 *
 * \param   handle         [IN]  Low level driver handle
 * \param   fpdModParams   [IN]  FPD module params
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb924ModuleInit(void *handle,
                                      Board_FpdModuleObj *fpdModParams);

/**
 * \brief  TLC59108 Led driver config
 *
 * This function is used for configuring the TLC59108 LED driver
 * sesnor device to control backlight.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   fpdRmtParams  [IN]   FPD remote params
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_tlc59108LedDrvCfg(void *handle,
                                     Board_FpdModuleObj *fpdModParams,
                                     Board_FpdRmtDevObj *fpdRmtParams);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DS90UB9XX_TLC59108_H_  */
