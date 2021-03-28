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
 *  \ingroup PM_LIB PM LIB API
 *  \defgroup PMLIB_SYSCONFIG System Configuration
 *
 *  System Configuration APIs are used to put the module to a desired
 *  power state. It abstracts the programming of PMMC to enable/disable or
 *  auto clock gate a given module. Many modules can be programmed in one go by
 *  providing the list of modules and their desired power state.
 *
 *  The system configuration does not take care of dependencies between
 *  modules and it is the user's responsibility to maintain the right
 *  dependency order to switch off a given module vs another.
 *
 * @{
 */

/**
 *  \file  pmlib_sysconfig_pmmc.h
 *
 *  \brief  This file declares the interface for the system configuration for
 *          switching on or switching off modules or putting them in HW
 *          controlled Auto Clock Gated mode via the PMMC
 */

#ifndef PMLIB_SYSCONFIG_PMMC_H_
#define PMLIB_SYSCONFIG_PMMC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/drv/pm/include/pm_types.h>
#include <ti/drv/pm/include/pmmc/pmhal_pmmc.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 * \brief   Structure to define the system configuration Table for a module.
 */
typedef struct pmlibSysConfigPmmcPowerStateParams
{
    pmhalPmmcModuleId_t        modId;
    /**< Module ID of the Module one wants to program */
    uint32_t                   pwrState;
    /**< Desired Power State for the module */
} pmlibSysConfigPmmcPowerStateParams_t;

/**
 * \brief   Structure to help the user understand if the module configuration
 *          was successful or not. If it is a failure the reason for the
 *          failure is also returned.
 */
typedef struct pmlibSysConfigPmmcErrReturn
{
    pmhalPmmcModuleId_t moduleId;
    /**< Module ID of the Module that is returned */
    pmErrCode_t         failCause;
    /**< Code which indicates cause of the failure */
} pmlibSysConfigPmmcErrReturn_t;

/**
 * \brief   Structure to help the user get the more detailed power mode in the
 *          PMLIBSysConfigPmmcGetPowerState API.
 */
typedef struct pmlibSysConfigPmmcDetailedState
{
    uint32_t contextLossCount;
    /**< Number of context losses experienced by the module */
    uint32_t resets;
    /**< Current state of module resets */
    uint32_t programmedState;
    /**< Requested state of the module */
    uint32_t currentState;
    /**< Current state of the module */
} pmlibSysConfigPmmcDetailedState_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API configures the given module to the desired power state.
 *
 * \param   inputTable      Table of modules and their desired power and
 *                          clock state.
 * \param   numConfig       Number of entries in the system configuration table.
 * \param   timeout         Desired time out for which one should wait for each
 *                          of the modules to reach its desired power state.
 *                        - #PM_TIMEOUT_NOWAIT - The API does not wait.
 *                        - #PM_TIMEOUT_INFINITE  - The API waits infinitely.
 *                        - Any other value - The API waits to any one of the
 *                          events to happen first :
 *                          - (1) Success of operation
 *                          - (2) The timeout is reached.
 * \param   resultReturn    Table which returns success or error codes got
 *                          while programming the power state. Useful for debug
 *                          One must allocate the same number of entries as the
 *                          input table to ensure the API has sufficient space
 *                          to return the error or pass codes. The structure
 *                          returns in the format
 *                          [module, return code (success/fail code)] for all
 *                          the modules given in a one to one mapping.
 *
 * \return  status  Returns the status of the API. This can be the following
 *                  values:
 *                 - #PM_SUCCESS  If the desired power state was met.
 *                 - #PM_FAIL     If the desired power state was not met. One
 **must
 *                              check the resultReturn to check the cause for
 *                              failure.
 */
pmErrCode_t PMLIBSysConfigPmmcSetPowerState(
    const pmlibSysConfigPmmcPowerStateParams_t *inputTable,
    uint32_t                                    numConfig,
    uint32_t                                    timeout,
    pmlibSysConfigPmmcErrReturn_t              *resultReturn);

/**
 * \brief   This API initializes the table for the system config.
 *
 * \param   inputTable      Input table to be initialized
 * \param   numConfig       Number of entries in the system configuration table.
 *
 * \return  status  Returns the status of the API. This can be the following
 *                  values:
 *                 - #PM_SUCCESS  If the initialization is complete.
 *                 - #PM_BADARGS  If the input parameters are not correct.
 */
pmErrCode_t PMLIBSysConfigPmmcPowerStateParams_init(
    pmlibSysConfigPmmcPowerStateParams_t *inputTable,
    uint32_t                              numConfig);

/**
 * \brief   This API is used to get the power state for a given module.
 *
 * \param   moduleId        Module ID of the module one is interested in. Refer
 *                          #pmhalPrcmModuleId_t for details.
 * \param   currState       Returns the final state of the module. Refer
 *                          #pmlibSysConfigPowerState_t for details.
 * \param   detailedState   This is an optional parameter which can be used to
 *                          return the detailed state of the module broken
 *                          down into module state, clock state and power state.
 *                          If one is not interested in knowing the detailed
 *                          state one can put NULL for this parameter.
 *
 * \return  status  Returns the status of the API. This can be the following
 *                  values:
 *                 - #PM_SUCCESS  If the status is obtained correctly.
 *                 - #PM_BADARGS  If currState pointer is NULL.
 */
pmErrCode_t PMLIBSysConfigPmmcGetPowerState(
    pmhalPmmcModuleId_t                moduleId,
    uint32_t                          *currState,
    pmlibSysConfigPmmcDetailedState_t *detailedState);

#ifdef __cplusplus
}
#endif

#endif

/* @} */


