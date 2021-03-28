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
 *   \ingroup PM_LIB PM LIB API
 *   \defgroup CPU_IDLE CPU Idle Configuration
 *      Dynamic power management of the CPUs involves setting the
 *      CPU power state to a lower power state when the CPU has
 *      nothing to do and then wake up from the low power state
 *      when the CPU has to resume its operations.
 *
 *      The CPU context is maintained every time the CPU goes to
 *      low power mode. Interrupts which are configured during the
 *      normal CPU operation can be configured as wakeup events which
 *      bring the CPU out of its low power state.
 *
 *      Some recommended power states for the different CPUs is as below:
 *      \n    - MPU : Subsystem Retention
 *      \n    - DSP : Subsystem Retention
 *
 *
 * @{
 */

/**
 *  \file  pmlib_cpuidle_pmmc.h
 *
 *  \brief  This file declares the interface for PMMC CPU Idle functionality.
 *          This is a low latency power saving mode which allows fast wakeup
 *          depending on the power mode set.
 */

#ifndef PMLIB_CPUIDLE_PMMC_H_
#define PMLIB_CPUIDLE_PMMC_H_

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

/* None  */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Enter the CPU specified into the given low power state.
 *
 * NOTE:    To keep the ADAS power management simple, we only
 *          support one low-power mode per CPU. The power state is
 *          used in the API to enable supporting multiple low power
 *          states in future w/o breaking compatibility.
 *
 * \return  status  Returns the status of the API. This can be the following
 *                  values:
 *                 - #PM_SUCCESS  If the desired power state was met.
 *                 - #PM_FAIL     If the desired power state was not met.
 */
pmErrCode_t PMLIBPmmcCpuIdle(void);

/**
 * \brief CPU mode modifications via PMMC for idle mode entry and wakeup
 *
 * \param   moduleId    Module which is to be modified for CPU Idle/Wakeup
 *                      Refer #pmhalPmmcModuleId_t for the cpu module id
 *
 * \param   mode        CPU state to which the CPU is to be set.
 *                      Refer to pmhal_ti_sci.h for supported modes.
 *
 * \return  status      Returns the status of the API. This can be the
 *                      following values:
 *                     - #PM_SUCCESS  If the desired power state was configured.
 *                     - #PM_FAIL     If the desired power state was not
 *                                    configured.
 */
pmErrCode_t PMLIBPmmcCpuModeModify(pmhalPmmcModuleId_t moduleId, uint32_t mode);

#ifdef __cplusplus
}
#endif

#endif

/* @} */

