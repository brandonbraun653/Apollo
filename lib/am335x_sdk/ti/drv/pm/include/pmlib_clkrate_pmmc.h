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
 *  \defgroup CLK_RATE Clock Rate Configuration
 *
 * Initialization of the device involves setting the right frequency
 * for the clocks for the CPUs and peripherals and right voltage for
 * the voltage rails via the PMMC
 *
 * The initialization of the system is carried in 2 stages:
 *  - Download and run PMMC firmware to initialize PLLS, and module clocks
 *    from the SBL
 *  - Configuring peripheral and CPU frequency at run time with
 *    necessary voltage changes. This is taken care by the
 *    PMLIB Clock Rate Configuration APIs.
 *
 * The Clock Rate Configuration provides 2 APIs to set and get the frequency
 * of any clock of any given module.
 * - PMLIBClkRateGet()
 * - PMLIBClkRateSet()
 * @{
 */

/**
 *  \file  pmlib_clkrate_pmmc.h
 *
 *  \brief  PMLIB Clock Rate Manager API interface file.
 */

#ifndef PMLIB_CLKRATE_PMMC_H_
#define PMLIB_CLKRATE_PMMC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <ti/drv/pm/include/pmmc/pmhal_pmmc.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  Set the clock rate of the given module.
 *
 * The API configures the module clock by sending a clock set message to the
 * PMMC.
 *
 * \param  modId           Module ID
 *                         Refer Enum #pmhalPmmcModuleId_t for values.
 * \param  clkId           Clock Id present in the module
 *                         Refer Enum #pmhalPmmcClockId_t for values.
 * \param  clkRate         New clock rate in Hz to be provided for the clockID
 *
 * \retval errorStatus     Status of API call. Can be any of the following,
 *         - #PM_SUCCESS      Indicates the operation is success
 *         - #PM_FAIL         Can Indicate the following:
 *                          - ModId is not valid.
 *                          - ClockRate provided is not supported
 *                          - Structure provided is not properly initialized
 *                          - Refer Enum #pmErrCode_t for detailed values.
 */
pmErrCode_t PMLIBClkRateSet(pmhalPmmcModuleId_t modId,
                            pmhalPmmcClockId_t  clkId,
                            uint32_t            clkRate);

/**
 * \brief Get the current clock rate of the given module.
 *
 * The API requests the module's clock frequency by sending the clock get
 * message to the PMMC.
 *
 * \param modId            Module ID
 *                         Refer Enum #pmhalPmmcModuleId_t for values.
 * \param  clkId           Clock Id present in the module
 *                         Refer Enum #pmhalPmmcClockId_t for values.
 * \param  clkRate         New clock rate in Hz returned for the clockID
 *
 * \retval errorStatus     Status of API call. Can be any of the following,
 *         - #PM_SUCCESS      Indicates the operation is success
 *         - #PM_FAIL         Can Indicate the following:
 *                          - ModId is not valid.
 *                          - ClockId provided is not valid
 *                          - Structure provided is not properly initialized
 *                          - Refer Enum #pmErrCode_t for detailed values.
 */
pmErrCode_t PMLIBClkRateGet(pmhalPmmcModuleId_t modId,
                            pmhalPmmcClockId_t  clkId,
                            uint32_t           *clkRate);

#ifdef __cplusplus
}
#endif

#endif /* PMLIB_CLKRATE_PMMC_H_ */

/* @} */


