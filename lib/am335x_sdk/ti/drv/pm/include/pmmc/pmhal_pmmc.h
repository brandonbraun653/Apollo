/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2017
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
 */

/**
 *  \file  pmhal_pmmc.h
 *
 *  \brief This file contains the M3 PMMC interface declarations.
 */

#ifndef PMHAL_PMMC_TOP_H_
#define PMHAL_PMMC_TOP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#if defined(SOC_K2G)
#include <ti/drv/pm/include/pmmc/V0/pmhal_pmmc.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Default timeout for PMMC message interface */
#define PMHAL_PMMC_TIMEOUT_DEFAULT (100000U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                      Global Variables Declarations                         */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Function to load the PMMC firmware
 *
 * \param   image   Pointer to PMMC firmware image
 *
 * \param   size    Size of PMMC firmware image in bytes
 *
 * \retval errorStatus      Status of the API call. Can be any of the following,
 *        - #PM_SUCCESS                If event is received
 *        - #PM_INVALID_FIRMWARE_IMAGE If firmware image is too big
 */
pmErrCode_t PMHALPmmcLoad(const void *image, uint32_t size);

/**
 * \brief   Function to start the PMMC firmware
 *
 * \param   timeout Timeout for starting firmware
 *
 * \retval errorStatus      Status of the API call. Can be any of the following,
 *        - #PM_SUCCESS                        If event is received
 *        - #PM_INVALID_FIRMWARE_START_TIMEOUT If start times out
 */
pmErrCode_t PMHALPmmcStart(uint32_t timeout);

/**
 * \brief   Function to initialize the PMMC messaging interface
 *
 * \param   None.
 *
 * \return  status  PM_SUCCESS If init completes successfully
 *                  PM_FAIL If init fails
 */
pmErrCode_t PMHALPmmcInterfaceInit(void);

/**
 * \brief   Function to close the PMMC messaging interface
 *
 * \param   None.
 *
 * \return  status  PM_SUCCESS If close completes successfully
 *                  PM_FAIL If close fails
 */
pmErrCode_t PMHALPmmcInterfaceClose(void);

/**
 * \brief   Function to validate communication with the PMMC firmware
 *
 * \param   timeout Timeout for validating communication with firmware
 *
 * \retval errorStatus      Status of the API call. Can be any of the following,
 *        - #PM_SUCCESS If two-way communication established
 *        - #PM_FAIL    If two-way communication fails
 */
pmErrCode_t PMHALPmmcCommsValidate(uint32_t timeout);

/**
 * \brief   Function to set a module's state via the PMMC
 *
 * \param   moduleId Module from #pmhalPmmcModuleId_t
 *
 * \param   state Desired state of the module selected from pmhal_ti_sci.h
 *
 * \param   timeout Timeout for command response
 *
 * \retval errorStatus      Status of the API call. Can be any of the following,
 *        - #PM_SUCCESS If module set state completed successfully
 *        - #PM_FAIL    If module set state failed
 */
pmErrCode_t PMHALPmmcModuleSetState(pmhalPmmcModuleId_t moduleId,
                                    uint32_t state,
                                    uint32_t timeout);

/**
 * \brief   Function to get a module's state via the PMMC
 *
 * \param   moduleId Module from #pmhalPmmcModuleId_t
 *
 * \param   *moduleState Pointer to a structure containing the module's current
 *                       state.
 *
 * \param   timeout Timeout for command response
 *
 * \retval errorStatus      Status of the API call. Can be any of the following,
 *        - #PM_SUCCESS If module get state completed successfully
 *        - #PM_FAIL    If module get state failed
 */
pmErrCode_t PMHALPmmcModuleGetState(pmhalPmmcModuleId_t moduleId,
                                    pmhalPmmcModuleState_t *moduleState,
                                    uint32_t timeout);

/**
 * \brief   Function to set a module's clock state via the PMMC
 *
 * \param   moduleId Module from #pmhalPmmcModuleId_t
 *
 * \param   clockId Module clock from #pmhalPmmcClockId_t
 *
 * \param   flags Module clock flags to set.  Available flags are defined in
 *                ti_sci_msg_req_set_clock_state
 *
 * \param   reqState Requests module clock state.  Available flags are defined
 *                   in ti_sci_msg_req_set_clock_state
 *
 * \param   timeout Timeout for command response
 *
 * \retval errorStatus      Status of the API call. Can be any of the following,
 *        - #PM_SUCCESS If clock set rate completed successfully
 *        - #PM_FAIL    If clock set rate failed
 */
pmErrCode_t PMHALPmmcClockSetState(pmhalPmmcModuleId_t moduleId,
                                   pmhalPmmcClockId_t clockId,
                                   uint32_t flags,
                                   uint32_t reqState,
                                   uint32_t timeout);

/**
 * \brief   Function to get a module's clock state via the PMMC
 *
 * \param   moduleId Module from #pmhalPmmcModuleId_t
 *
 * \param   clockId Module clock from #pmhalPmmcClockId_t
 *
 * \param   *clockState Pointer to a structure containing a module clock's
 *                      state.
 *
 * \param   timeout Timeout for command response
 *
 * \retval errorStatus      Status of the API call. Can be any of the following,
 *        - #PM_SUCCESS If clock get rate completed successfully
 *        - #PM_FAIL    If clock get rate failed
 */
pmErrCode_t PMHALPmmcClockGetState(pmhalPmmcModuleId_t moduleId,
                                   pmhalPmmcClockId_t clockId,
                                   pmhalPmmcClockState_t *clockState,
                                   uint32_t timeout);

/**
 * \brief   Function to set a module's clock rate via the PMMC
 *
 * \param   moduleId Module from #pmhalPmmcModuleId_t
 *
 * \param   clockId Module clock from #pmhalPmmcClockId_t
 *
 * \param   clockRate Desired rate of the module clock selected
 *
 * \retval errorStatus      Status of the API call. Can be any of the following,
 *        - #PM_SUCCESS If clock set rate completed successfully
 *        - #PM_FAIL    If clock set rate failed
 */
pmErrCode_t PMHALPmmcClockSetRate(pmhalPmmcModuleId_t moduleId,
                                  pmhalPmmcClockId_t clockId,
                                  uint32_t clockRate);

/**
 * \brief   Function to get a module's clock rate via the PMMC
 *
 * \param   moduleId Module from #pmhalPmmcModuleId_t
 *
 * \param   clockId Module clock from #pmhalPmmcClockId_t
 *
 * \param   *clockRate Returned rate of the Module clock
 *
 * \retval errorStatus      Status of the API call. Can be any of the following,
 *        - #PM_SUCCESS If clock get rate completed successfully
 *        - #PM_FAIL    If clock get rate failed
 */
pmErrCode_t PMHALPmmcClockGetRate(pmhalPmmcModuleId_t moduleId,
                                  pmhalPmmcClockId_t clockId,
                                  uint32_t *clockRate);

/**
 * \brief This API verifies if the Module Id is valid or not.
 *
 * \param moduleId          Unique ID of the module
 *
 * \retval errorStatus      Status of the API call. Can be any of the following,
 *        - #PM_SUCCESS                   Indicates the operation is success
 *        - #PM_INPUT_PARAM_BAD_MODULE_ID Invalid module id
 */
pmErrCode_t PMHALPmmcModuleIsIdValid(pmhalPmmcModuleId_t moduleId);

/**
 * \brief This API verifies if the Module state is valid or not.
 *
 * \param state             module state
 *
 * \retval errorStatus      Status of the API call. Can be any of the following,
 *        - #PM_SUCCESS       Indicates the operation is success
 *        - #PM_BADARGS       Invalid module state
 */
pmErrCode_t PMHALPmmcModuleIsStateValid(uint32_t state);

#ifdef __cplusplus
}
#endif

#endif
