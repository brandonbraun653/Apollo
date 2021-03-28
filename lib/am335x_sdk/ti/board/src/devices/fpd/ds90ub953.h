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
 * \file  ds90ub953.h
 *
 * \brief This file includes the structures, enums and register offsets
 *        for configuring the ds90ub953 serailizer.
 *
 */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD 
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB953 DS90UB953 FPD-Link Library
 *
 *  Provides the interfaces for configuring DS90UB953 FPD-Link device.
 *
 *  @{
 *
 */
/* @} */

#ifndef _DS90UB953_H_
#define _DS90UB953_H_

#include <ti/board/src/devices/common/common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD_DS90UB953
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB953_TYPES Data Types
 *
 *  Data types used by DS90UB953 FPD-Link device library.
 *
 *  @{
 *
 */

/**
 *  \anchor DESUB953_patternType
 *  \name   Pattern type for generation
 *  \brief  Id for pattern generation.
 *
 *  @{
 */
/** \brief Pattern type: RGB888 1920x1080 30fps */
#define BOARD_FPD_UB953_DEFAULT_CFG                           ((uint32_t) 0x0U)
/** \brief Pattern type: RGB888 1920x1080 30fps */
#define BOARD_FPD_UB953_PG_RGB888_1920_1080_30_FPS            ((uint32_t) 0x1U)
/** \brief Pattern type: Maximum Val */
#define BOARD_FPD_UB953_PG_MAX                                ((uint32_t) 0x2U)

/* @} */

/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD_DS90UB953
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB953_APIS Application Interfaces
 *
 *  Application Interfaces provided by DS90UB953 FPD-Link device library.
 *
 *  @{
 *
 */

/**
 * \brief  FPD ub953 pattern generation configurations.
 *
 * This function is used for configuring the pattern generator for FPD UB953
 *
 * \param   handle          [IN]  Low level driver handle
 * \param   fpdModParams    [IN]  FPD module params
 * \param   pgType          [IN]  Pattern Generation Type
 *                                See \ref DESUB953_patternType for details.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb953CfgPG(void *handle,
                                 Board_FpdModuleObj *fpdModParams,
                                 uint32_t pgType);

/**
 * \brief  Initializes the FPD UB953 module.
 *
 * This function is used to initialize the fpd ub953 module
 *
 * \param   handle         [IN]  Low level driver handle
 * \param   fpdModParams   [IN]  FPD module params
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb953SerInit(void *handle,
                                   Board_FpdModuleObj *fpdModParams);

/**
 * \brief  Initializes the FPD UB953 module for OV2775 sensor module.
 *
 * This function is used to initialize the fpd ub953 module for OV2775 sensor
 *
 * \param   handle         [IN]  Low level driver handle
 * \param   fpdModParams   [IN]  FPD module params
] *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb953DesInitFusionBoardTIDA1130(void *handle,
                                            Board_FpdModuleObj *fpdModParams);

/**
 * \brief  FPD ub953 pattern generation configurations.
 *
 * This function is used for configuring the pattern generator for FPD UB953
 *
 * \param   handle          [IN]  Low level driver handle
 * \param   fpdModParams    [IN]  FPD module params
 * \param   ub953Cfg        [IN]  Configuration Info
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb953Cfg(void *handle,
                               Board_FpdModuleObj *fpdModParams,
                               Board_I2cRegProgObj *ub953Cfg);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DS90UB953_H_ */

/* @} */
