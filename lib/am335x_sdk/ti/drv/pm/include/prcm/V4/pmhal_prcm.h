/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2016
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
 *  \file      pmhal_prcm.h
 *
 *  \brief     This file contains enumeration declarations for different
 *             elements of PRCM like clock, module, power domain, etc.
 *             which uniquely identifies each element of PRCM.
 */

#ifndef PMHAL_PRCM_H_
#define PMHAL_PRCM_H_

/* ========================================================================== */
/*                                Include Files                               */
/* ========================================================================== */

#include <ti/drv/pm/include/prcm/pmhal_prcm_modinc.h>
#include <ti/drv/pm/include/pm_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                             Macros and Typedefs                            */
/* ========================================================================== */

/**< \brief PMHAL_PRCM_AUTO_DPLL_MODE_DISABLE: Macro defining the value for dpll
 *          auto mode disabled  */
#define PMHAL_PRCM_AUTO_DPLL_MODE_DISABLE (0U)

/**< \brief PMHAL_PRCM_NUM_CPU_RESETS_FOR_SUBSYSTEM: Macro defining the number
 *          of CPU resets that a CPU subsystem can have.
 */
#define PMHAL_PRCM_NUM_CPU_RESETS_FOR_SUBSYSTEM (2U)

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */

/**
 *  \brief Enum defining Standby Mode of a module- values are
 *         mapped from register description
 */
typedef enum pmhalPrcmModuleMStbyMode
{
    PMHAL_PRCM_MODULE_MSTANDBYMODE_MIN = 0x0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_MODULE_MSTANDBYMODE_FORCE_STANDBY =
        PMHAL_PRCM_MODULE_MSTANDBYMODE_MIN,
    /**< Forced StandBy Mode */
    PMHAL_PRCM_MODULE_MSTANDBYMODE_NO_STANDBY = 0x1U,
    /**< No StandBy Mode */
    PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY = 0x2U,
    /**< Smart StandBy Mode */
    PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY_WAKEUP_CAPABLE = 0x3U,
    /**< Smart Standby WakeUp Mode */
    PMHAL_PRCM_MODULE_MSTANDBYMODE_MAX =
        PMHAL_PRCM_MODULE_MSTANDBYMODE_SMART_STANDBY_WAKEUP_CAPABLE,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_MODULE_MSTANDBYMODE_INVALID = 0xFF
                                             /**< Invalid value of the enum. Can
                                              * be used for validation. */
} pmhalPrcmModuleMStbyMode_t;

/**
 *  \brief Enum defining different modes of a module.
 */
typedef enum pmhalPrcmModuleSModuleMode
{
    PMHAL_PRCM_MODULE_MODE_MIN = 0x0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_MODULE_MODE_DISABLED = PMHAL_PRCM_MODULE_MODE_MIN,
    /**< Disabled: Any access to module registers will result in error */
    PMHAL_PRCM_MODULE_MODE_RESERVED = 0x1U,
    /**< Operation is undefined. */
    PMHAL_PRCM_MODULE_MODE_ENABLED = 0x2U,
    /**< Enabled: Functional and interface clocks are available and access to
     *   module registers are permitted. */
    PMHAL_PRCM_MODULE_MODE_MAX = PMHAL_PRCM_MODULE_MODE_ENABLED
                                 /**< Max value of the enum. Can be used for
                                  *   validation. */
} pmhalPrcmModuleSModuleMode_t;

/**
 *  \brief Enum defining Idle Mode of a module- values are
 *         mapped from register description
 */
typedef enum pmhalPrcmModuleSIdleMode
{
    PMHAL_PRCM_MODULE_SIDLEMODE_MIN = 0x0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_MODULE_SIDLEMODE_FORCE_IDLE = PMHAL_PRCM_MODULE_SIDLEMODE_MIN,
    /**< PM HAL Prcm Module SIdleMode set to Force Idle mode */
    PMHAL_PRCM_MODULE_SIDLEMODE_NO_IDLE = 0x1U,
    /**< PM HAL Prcm Module SIdleMode set to No Idle mode */
    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE = 0x2U,
    /**< PM HAL Prcm Module SIdleMode set to Smart Idle mode*/
    PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE = 0x3U,
    /**< PM HAL Prcm Module SIdleMode set to Smart Idle wakeup mode */
    PMHAL_PRCM_MODULE_SIDLEMODE_MAX =
        PMHAL_PRCM_MODULE_SIDLEMODE_SMART_IDLE_WAKEUP_CAPABLE,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_MODULE_SIDLEMODE_INVALID = 0xFF
                                          /**< Enum for invalid . Can be used
                                           *for validation. */
} pmhalPrcmModuleSIdleMode_t;

/**
 *  \brief Enum defining idle states of the module. These values can be used to
 *         check the state of the module after configuring the module mode
 *         property.
 */
typedef enum pmhalPrcmModuleSIdleState
{
    PMHAL_PRCM_MODULE_IDLEST_MIN = 0x0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_MODULE_SIDLESTATE_FUNCTIONAL = PMHAL_PRCM_MODULE_IDLEST_MIN,
    /**< Module is functional and can be accessed */
    PMHAL_PRCM_MODULE_SIDLESTATE_INTRANSITION = 0x1U,
    /**< Module is performing transition: wakeup, or sleep,or sleep abortion */
    PMHAL_PRCM_MODULE_SIDLESTATE_INTERFACE_IDLE = 0x2U,
    /**< Module is in Idle mode (only interface part). It is functional if it
     *   uses separate functional clock  */
    PMHAL_PRCM_MODULE_SIDLESTATE_DISABLED = 0x3U,
    /**< Module is in Idle mode (both functional and Interface) */
    PMHAL_PRCM_MODULE_IDLEST_MAX = PMHAL_PRCM_MODULE_SIDLESTATE_DISABLED,
    /**< Max value of the enum. Can be used for
     * validation. */
    PMHAL_PRCM_MODULE_SIDLESTATE_DETERMINED_BY_CLK_STATE =
        PMHAL_PRCM_MODULE_IDLEST_MAX + 1U,
    /**< Used when there is no CLKCTRL register. The module state is
     * determined
     *   by the clock state. Used in PMLIBSysConfig. */
    PMHAL_PRCM_MODULE_SIDLESTATE_UNDEFINED = 0x7FFFFFFFU
                                             /** Undefined Sidle State */
} pmhalPrcmModuleSIdleState_t;

/**
 *  \brief Enum defining standby states of the module (Master only). These
 *         values can be used to check the state of the module after
 *         configuring the module mode property.
 */
typedef enum pmhalPrcmModuleMStbyState
{
    PMHAL_PRCM_CLKCTRL_STBYST_MIN = 0x0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_MODULE_MSTANDBYSTATE_FUNCTIONAL = PMHAL_PRCM_CLKCTRL_STBYST_MIN,
    /**< When master module wants to initiate a transaction on the device
     *   interconnect and it requests specific (functional and interface)
     *   clocks for that purpose. The PRCM module ensures that the required
     *   clocks are active and the module is said to be functional after this
     *   transition completes. */
    PMHAL_PRCM_MODULE_MSTANDBYSTATE_STANDBY = 0x1U,
    /**< When the master module no longer requires the clocks, it informs the
     *   PRCM module, which can then gate the clocks to the module. */
    PMHAL_PRCM_CLKCTRL_STBYST_MAX = PMHAL_PRCM_MODULE_MSTANDBYSTATE_STANDBY
                                    /**< Max value of the enum. Can be used for
                                     *   validation. */
} pmhalPrcmModuleMStbyState_t;

/**
 *  \brief Enum defining content of Clock Activity Settings
 *         for Idle Ack Clock Gating Conditions
 */
typedef enum pmhalPrcmModuleSClockActivity
{
    PMHAL_PRCM_MODULE_SCLOCKACTIVITY_MIN = 0x0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_MODULE_SCLOCKACTIVITY_GATE_FUNC_INT =
        PMHAL_PRCM_MODULE_SCLOCKACTIVITY_MIN,
    /**< Enum for sClkActivity Function Int */
    PMHAL_PRCM_MODULE_SCLOCKACTIVITY_FUNC_NOINT = 0x1U,
    /**< Enum for sClkActivity Function no Int */
    PMHAL_PRCM_MODULE_SCLOCKACTIVITY_NOFUNC_INT = 0x2U,
    /**< Enum for sClkActivity No Function Int */
    PMHAL_PRCM_MODULE_SCLOCKACTIVITY_NOFUNC_NOINT = 0x3U,
    /**< Enum for sClkActivity No Function No Int */
    PMHAL_PRCM_MODULE_SCLOCKACTIVITY_MAX =
        PMHAL_PRCM_MODULE_SCLOCKACTIVITY_NOFUNC_NOINT
        /**< Max value of the enum. Can be used for
         *   validation. */
} pmhalPrcmModuleSClkActivity_t;

/**
 * \brief Index for System Clock Frequency values.
 */
typedef enum pmhalPrcmSysClkVal
{
    PMHAL_PRCM_SYSCLK_19_2_MHZ = 0U,
    /**< System clock frequency 19.2 MHz index */
    PMHAL_PRCM_SYSCLK_MIN = PMHAL_PRCM_SYSCLK_19_2_MHZ,
    /**< Min system clock frequency index */
    PMHAL_PRCM_SYSCLK_24_MHZ = 1U,
    /**< System clock frequency 24 MHz index */
    PMHAL_PRCM_SYSCLK_25_MHZ = 2U,
    /**< System clock frequency 25 MHz index */
    PMHAL_PRCM_SYSCLK_26_MHZ = 3U,
    /**< System clock frequency 26 MHz index */
    PMHAL_PRCM_SYSCLK_MAX = PMHAL_PRCM_SYSCLK_26_MHZ,
    /**< Max system clock frequency index */
    PMHAL_PRCM_SYSCLK_COUNT = PMHAL_PRCM_SYSCLK_MAX + 1U,
    /**< System clock frequency index count */
    PMHAL_PRCM_SYSCLK_UNDEF = 0x7FFFFFFFU
                              /**< Undefined system clock frequency index */
} pmhalPrcmSysClkVal_t;

/**
 *  \brief Enum defining content of clock status
 */
typedef enum pmhalPrcmClockActivityState
{
    PMHAL_PRCM_MODULE_CLOCKACTIVITY_CLK_MIN = 0x0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_MODULE_CLOCKACTIVITY_CLK_GATED =
        PMHAL_PRCM_MODULE_CLOCKACTIVITY_CLK_MIN,
    /**< Enum for Gated Module CLK Activity. */
    PMHAL_PRCM_MODULE_CLOCKACTIVITY_CLK_ENABLED = 0x1U,
    /**< Enum for Gated Module CLK Activity. */
    PMHAL_PRCM_MODULE_CLOCKACTIVITY_CLK_MAX =
        PMHAL_PRCM_MODULE_CLOCKACTIVITY_CLK_ENABLED
        /**< Min value of the enum. Can be
         *   used for validation. */
} pmhalPrcmClockActivityState_t;

/**
 *  \brief Enum defining clock domain control values. These values can be used
 *         to control the clock domain while initializing the system, entering
 *         sleep state and waking up from sleep state.
 */
typedef enum pmhalPrcmCdClkTrnModes
{
    PMHAL_PRCM_CD_CLKTRNMODES_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_CD_CLKTRNMODES_NO_SLEEP = PMHAL_PRCM_CD_CLKTRNMODES_MIN,
    /**< No sleep in the clock domain */
    PMHAL_PRCM_CD_CLKTRNMODES_SW_SLEEP = 1U,
    /**< Start a software forced sleep transition on the clock domain. */
    PMHAL_PRCM_CD_CLKTRNMODES_SW_WAKEUP = 2U,
    /**< Start a software forced wake-up transition on the clock domain. */
    PMHAL_PRCM_CD_CLKTRNMODES_HW_AUTO = 3U,
    /**< If there is no activity in the clock domain HW automatically puts it
     *   into sleep mode. On detecting any activity it wakes up. */
    PMHAL_PRCM_CD_CLKTRNMODES_MAX = PMHAL_PRCM_CD_CLKTRNMODES_HW_AUTO
                                    /**< Max value of the enum. Can be used for
                                     *   validation. */
} pmhalPrcmCdClkTrnModes_t;

/**
 *  \brief Enum defining power domain status values. These values can be used
 *         to control the clock domain while initializing the system, entering
 *         sleep state and waking up from sleep state.
 */
typedef enum pmhalPrcmPdState
{
    PMHAL_PRCM_PD_STATUS_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_PD_STATE_OFF = PMHAL_PRCM_PD_STATUS_MIN,
    /**< Power to the domain is off. */
    PMHAL_PRCM_PD_STATE_RETENTION = 1U,
    /**< Power to the domain is in retention mode and it will not be functional
     *   but the memory will be retained. */
    PMHAL_PRCM_PD_STATE_ON_INACTIVE = 2U,
    /**< Power to the domain is ON INACTIVE. */
    PMHAL_PRCM_PD_STATE_ON_ACTIVE = 3U,
    /**< Power to the domain is ON. */
    PMHAL_PRCM_PD_STATUS_MAX = PMHAL_PRCM_PD_STATE_ON_ACTIVE,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_PD_STATUS_COUNT = PMHAL_PRCM_PD_STATUS_MAX + 1U
                                 /**< Count value of the enum. Can be used for
                                  *   validation. */
} pmhalPrcmPdState_t;

/**
 *  \brief Enumeration for different different post dividers.
 */
typedef enum pmhalPrcmDpllPostDivId
{
    PMHAL_PRCM_DPLL_POST_DIV_INVALID = 0x7FFFFFFFU,
    /**< Invalid value. */
    PMHAL_PRCM_DPLL_POST_DIV_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_POST_DIV_M2 = PMHAL_PRCM_DPLL_POST_DIV_MIN,
    /**< M2 post divider. */
    PMHAL_PRCM_DPLL_POST_DIV_M2X2 = 1U,
    /**< M2X2 post divider. */
    PMHAL_PRCM_DPLL_POST_DIV_M4 = 2U,
    /**< M4 post divider. */
    PMHAL_PRCM_DPLL_POST_DIV_M3 = 3U,
    /**< M3 post divider. */
    PMHAL_PRCM_DPLL_POST_DIV_M5 = 4U,
    /**< M5 post divider. */
    PMHAL_PRCM_DPLL_POST_DIV_M6 = 5U,
    /**< M6 post divider. */
    PMHAL_PRCM_DPLL_POST_DIV_DCO_LDO = 6U,
    /**< DCO_LDO post divider. */
    PMHAL_PRCM_DPLL_POST_DIV_MAX = PMHAL_PRCM_DPLL_POST_DIV_DCO_LDO,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_POST_DIV_COUNT = PMHAL_PRCM_DPLL_POST_DIV_MAX + 1U
                                     /**< Count value of the enum. Can be used
                                      * for
                                      *   validation. */
} pmhalPrcmDpllPostDivId_t;

// NOTE: Only applies to am335x/am437x maps to pll_clkinpulow_ctrl.
//       no function implemented to change this can't find similar in
//       TDA2xx spec.  Need to write function for am335x
/**
 *  \brief Enum defining CLKINPULOW input selection.
 *         These parameters define the clock input to CLKINPULOW signal in
 *         bypass mode.
 */
typedef enum pmhalPrcmDpllClkInputLowSel
{
    PMHAL_PRCM_DPLL_CLKINPULOW_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_CLKINPULOW_CORE_CLKOUTM6 = PMHAL_PRCM_DPLL_CLKINPULOW_MIN,
    /**< Select CORE_CLKOUTM6 as the input for CLKINPULOW. */
    PMHAL_PRCM_DPLL_CLKINPULOW_PER_CLKOUTM2 = 1U,
    /**< Select PER_CLKOUTM2 as the input for CLKINPULOW. */
    PMHAL_PRCM_DPLL_CLKINPULOW_MAX = 1U,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_CLKINPULOW_COUNT = PMHAL_PRCM_DPLL_CLKINPULOW_MAX + 1U
                                       /**< Count value of the enum. Can be used
                                        * for validation. */
} pmhalPrcmDpllClkInputLowSel_t;

/**
 *  \brief Enum defining bypass input clock selection for the PLL.
 *         The bypass clock can either be CLKINP (Master Osc) or CLKINPULOW
 *         (above enum value).
 */
typedef enum pmhalPrcmDpllBypassClkSel
{
    PMHAL_PRCM_DPLL_BYP_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_BYP_CLKINP = PMHAL_PRCM_DPLL_BYP_MIN,
    /**< Select CLKINP (Master Oscillator) as the bypass mode clock. */
    PMHAL_PRCM_DPLL_BYP_CLKINPULOW = 1U,
    /**< Select CLKINPULOW as the bypass mode clock. Refer
     *   prcmDpllClkInputLowSel_t for possible inputs for CLKINPULOW. */
    PMHAL_PRCM_DPLL_BYP_MAX = PMHAL_PRCM_DPLL_BYP_CLKINPULOW,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_BYP_COUNT = PMHAL_PRCM_DPLL_BYP_MAX + 1U
                                /**< Count value of the enum. Can be used for
                                 *   validation. */
} pmhalPrcmDpllBypassClkSel_t;

/**
 *  \brief Enum defining input clocks for the PLL.
 */
typedef enum pmhalPrcmDpllClkInput
{
    PMHAL_PRCM_DPLL_INP_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_INP_CLKINP = PMHAL_PRCM_DPLL_INP_MIN,
    /**< Select CLKINP (Master Oscillator) as the bypass mode clock. */
    PMHAL_PRCM_DPLL_INP_CLKINPULOW = 1U,
    /**< Select CLKINPULOW as the bypass mode clock. Refer
     *   prcmDpllClkInputLowSel_t for possible inputs for CLKINPULOW. */
    PMHAL_PRCM_DPLL_INP_CLKINPHIF = 2U,
    /**< Implicit Select CLKINPHIF as the bypass mode clock for M3 output. Refer
     *   prcmDpllClkInputLowSel_t for possible inputs for CLKINPULOW. */
    PMHAL_PRCM_DPLL_INP_MAX = PMHAL_PRCM_DPLL_INP_CLKINPHIF,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_INP_COUNT = PMHAL_PRCM_DPLL_INP_MAX + 1U
                                /**< Count value of the enum. Can be used for
                                 *   validation. */
} pmhalPrcmDpllClkInput_t;

/**
 *  \brief Enum defining different power modes for the PLL.
 */
typedef enum pmhalPrcmDpllPowerMode
{
    PMHAL_PRCM_DPLL_POWER_MODE_MIN = 4U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_POWER_MODE_MN_BYP_MODE = PMHAL_PRCM_DPLL_POWER_MODE_MIN,
    /**< MN Bypass mode, the value of multiplier and divider of DPLL are set to
     *   Zero. */
    PMHAL_PRCM_DPLL_POWER_MODE_LP_BYP_MODE = 5U,
    /**< Low Power Bypass mode, the value of multiplier and divider of DPLL are
     *   retained. */
    PMHAL_PRCM_DPLL_POWER_MODE_FR_BYP_MODE = 6U,
    /**< Fast relock Bypass mode. */
    PMHAL_PRCM_DPLL_POWER_MODE_LOCK_MODE = 7U,
    /**< DPLL Lock mode. */
    PMHAL_PRCM_DPLL_POWER_MODE_MAX = PMHAL_PRCM_DPLL_POWER_MODE_LOCK_MODE,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_POWER_MODE_COUNT = PMHAL_PRCM_DPLL_POWER_MODE_MAX + 1U,
    /**< Count value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_POWER_MODE_UNDEF = 0x7FFFFFFFU
                                       /**< Mode Not Defined */
} pmhalPrcmDpllPowerMode_t;

/**
 *  \brief Enum defining different ramp levels for the PLL.
 */
typedef enum pmhalPrcmDpllRampLevel
{
    PMHAL_PRCM_DPLL_RAMP_LEVEL_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_RAMP_LEVEL_DISABLE = PMHAL_PRCM_DPLL_RAMP_LEVEL_MIN,
    /**< Ramp level is disabled. */
    PMHAL_PRCM_DPLL_RAMP_LEVEL_ALGO1 = 1U,
    /**< Ramp level to use algorithm1.
     *    CLKOUT   => Bypass clk -> Fout/8 -> Fout/4 -> Fout/2 -> Fout
     *    CLKOUTX2 => Bypass clk -> Foutx2/8 -> Foutx2/4 -> Foutx2/2 -> Foutx2
     */
    PMHAL_PRCM_DPLL_RAMP_LEVEL_ALGO2 = 2U,
    /**< Ramp level to use algorithm2.
     *   CLKOUT   => Bypass clk -> Fout/4 -> Fout/2 -> Fout/1.5 -> Fout
     *   CLKOUTX2 => Bypass clk -> Foutx2/4 -> Foutx2/2 -> Foutx2/1.5 -> Foutx2
     */
    PMHAL_PRCM_DPLL_RAMP_LEVEL_MAX = PMHAL_PRCM_DPLL_RAMP_LEVEL_ALGO2,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_RAMP_LEVEL_COUNT = PMHAL_PRCM_DPLL_RAMP_LEVEL_MAX + 1U
                                       /**< Count value of the enum. Can be used
                                        * for validation. */
} pmhalPrcmDpllRampLevel_t;

/**
 *  \brief Enum defining different ramp rates for the PLL. These rates .
 *         indicates the time spent in each ramp step.
 */
typedef enum pmhalPrcmDpllRampRate
{
    PMHAL_PRCM_DPLL_RAMP_RATE_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_RAMP_RATE_REFCLKX2 = PMHAL_PRCM_DPLL_RAMP_RATE_MIN,
    /**< 2 REFCLKs per each ramp step. */
    PMHAL_PRCM_DPLL_RAMP_RATE_REFCLKX4 = 1U,
    /**< 4 REFCLKs per each ramp step. */
    PMHAL_PRCM_DPLL_RAMP_RATE_REFCLKX8 = 2U,
    /**< 8 REFCLKs per each ramp step. */
    PMHAL_PRCM_DPLL_RAMP_RATE_REFCLKX16 = 3U,
    /**< 16 REFCLKs per each ramp step. */
    PMHAL_PRCM_DPLL_RAMP_RATE_REFCLKX32 = 4U,
    /**< 32 REFCLKs per each ramp step. */
    PMHAL_PRCM_DPLL_RAMP_RATE_REFCLKX64 = 5U,
    /**< 64 REFCLKs per each ramp step. */
    PMHAL_PRCM_DPLL_RAMP_RATE_REFCLKX128 = 6U,
    /**< 128 REFCLKs per each ramp step. */
    PMHAL_PRCM_DPLL_RAMP_RATE_REFCLKX512 = 7U,
    /**< 512 REFCLKs per each ramp step. */
    PMHAL_PRCM_DPLL_RAMP_RATE_MAX = PMHAL_PRCM_DPLL_RAMP_RATE_REFCLKX512,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_DPLL_RAMP_RATE_COUNT = PMHAL_PRCM_DPLL_RAMP_RATE_MAX + 1U
                                      /**< Count value of the enum. Can be used
                                       * for validation. */
} pmhalPrcmDpllRampRate_t;

/**
 *  \brief Enum defining different types of root clock.
 */
typedef enum pmhalPrcmRootClkType
{
    PMHAL_PRCM_ROOT_CLK_FREQ_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_ROOT_CLK_FREQ_FIXED = PMHAL_PRCM_ROOT_CLK_FREQ_MIN,
    /**< Frequency of the root clock is fixed in the SoC. */
    PMHAL_PRCM_ROOT_CLK_FREQ_STATIC_CONFIG = 1U,
    /**< Frequency of the root clock is not fixed in the SoC, but fixed during
     *   board design or system initialization. */
    PMHAL_PRCM_ROOT_CLK_FREQ_MAX = PMHAL_PRCM_ROOT_CLK_FREQ_STATIC_CONFIG,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_ROOT_CLK_FREQ_COUNT = PMHAL_PRCM_ROOT_CLK_FREQ_MAX + 1U
                                     /**< Count value of the enum. Can be used
                                      * for validation. */
} pmhalPrcmRootClkType_t;

/**
 *  \brief Enum defining Logic Retention Power States of Logic Area
 */
typedef enum pmhalPrcmPdLogicRetState
{
    PMHAL_PRCM_PD_RET_STATUS_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_PD_RET_STATUS_OSWR = PMHAL_PRCM_PD_RET_STATUS_MIN,
    /**< One of the Logic Retention States */
    PMHAL_PRCM_PD_RET_STATUS_CSWR = 1U,
    /**< One of the Logic Retention States */
    PMHAL_PRCM_PD_RET_STATUS_MAX = PMHAL_PRCM_PD_RET_STATUS_CSWR,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_PD_RET_STATUS_COUNT = PMHAL_PRCM_PD_RET_STATUS_MAX + 1U
                                     /**< Count value of the enum. Can be used
                                      * for validation. */
} pmhalPrcmPdLogicRetState_t;

/**
 *  \brief Enum defining Low Power Request type of the power domain.
 */
typedef enum pmhalPrcmPdLowPwrStateChangeType
{
    PMHAL_PRCM_PD_LOW_PWR_REQUEST_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_PD_LOW_PWR_NO_REQUEST = PMHAL_PRCM_PD_LOW_PWR_REQUEST_MIN,
    /**< One of the Low Power State Change Request Values */
    PMHAL_PRCM_PD_LOW_PWR_REQUEST = 1U,
    /**< One of the Low Power State Change Request Values */
    PMHAL_PRCM_PD_LOW_PWR_REQUEST_MAX = PMHAL_PRCM_PD_LOW_PWR_REQUEST,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_PD_LOW_PWR_REQUEST_COUNT = PMHAL_PRCM_PD_LOW_PWR_REQUEST_MAX +
                                          1U
                                          /**< Count value of the enum. Can be
                                           * used for validation. */
} pmhalPrcmPdLowPwrStateChangeType_t;

/**
 * \brief Physical memory data retention states
 */
typedef enum pmhalPhyBankRetStates
{
    PMHAL_BANK_RET_OFF = 0U,
    /**< One of the Physical Memory Bank States */
    PMHAL_BANK_RET_MIN = PMHAL_BANK_RET_OFF,
    /**< Lower bound (inclusive) */
    PMHAL_BANK_RET_ON = 1U,
    /**< One of the Physical Memory Bank States */
    PMHAL_BANK_RET_MAX = PMHAL_BANK_RET_ON,
    /**< Enum Upper bound */
    PMHAL_BANK_RET_COUNT = PMHAL_BANK_RET_MAX + 1U,
    /**< Enum Count */
    PMHAL_BANK_RET_UNDEF = 0xFF
                           /**< Undefined value */
} pmhalPhyBankRetStates_t;

/**
 *  \brief Enum defining PD in Transitions or not
 */
typedef enum pmhalPrcmPdTransitionState
{
    PMHAL_PRCM_PD_TRANSIT_STATUS_MIN = 0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_PD_TRANSIT_STATUS_NOTRANS = PMHAL_PRCM_PD_TRANSIT_STATUS_MIN,
    /**< No on-going transition on power domain */
    PMHAL_PRCM_PD_TRANSIT_STATUS_INTRANS = 1U,
    /**< Power domain transition is in progress. */
    PMHAL_PRCM_PD_TRANSIT_STATUS_MAX = PMHAL_PRCM_PD_TRANSIT_STATUS_INTRANS,
    /**< Max value of the enum. Can be used for validation. */
    PMHAL_PRCM_PD_TRANSIT_STATUS_COUNT = PMHAL_PRCM_PD_TRANSIT_STATUS_MAX + 1U
                                         /**< Count value of the enum. Can be
                                          * used for validation. */
} pmhalPrcmPdTransitionState_t;

/**
 * \brief Voltage Domains
 */
typedef enum pmhalPrcmVdId
{
    PMHAL_PRCM_VD_LOWER_BOUND = -1,
    /**< Lower Bound Exclusive */
    PMHAL_PRCM_VD_MIN = 0,
    /**< Minimum Voltage Domain */
    PMHAL_PRCM_VD_MPU = PMHAL_PRCM_VD_MIN,
    /**< VD_MPU Voltage Domain */
    PMHAL_PRCM_VD_CORE = 1,
    /**< VD_CORE Voltage Domain */
    PMHAL_PRCM_VD_RTC = 2,
    /**< VD_RTC Voltage Domain */
    PMHAL_PRCM_VD_TAMPER = 3,
    /**< VD_TAMPER Voltage Domain */
    PMHAL_PRCM_VD_MAX = PMHAL_PRCM_VD_TAMPER,
    /**< Enum Upper bound */
    PMHAL_PRCM_VD_COUNT = PMHAL_PRCM_VD_MAX + 1,
    /**< Enum Count */
    PMHAL_PRCM_VD_UNDEF = 0x7FFFFFFF
                          /**< Undefined value */
} pmhalPrcmVdId_t;

/**
 * \brief The Abstract PMIC Voltage Regulator IDs used by the PMIC Interface.
 *        These abstract regulator IDs represent the regulators connected to
 *        the voltage rail of the respective voltage domains. The mapping
 *        of these abstract regulator IDs to the actual PMIC regulators are
 *        done in the respective HW PMIC module.
 */
typedef enum pmhalPrcmPmicRegulatorId
{
    PMHAL_PRCM_PMIC_REGULATOR_INVALID = -1,
    /**< Invalid PMIC Regulator */
    PMHAL_PRCM_PMIC_REGULATOR_MIN = 0,
    /**< Minimum Abstracted PMIC Regulator */
    PMHAL_PRCM_PMIC_REGULATOR_MPU = PMHAL_PRCM_PMIC_REGULATOR_MIN,
    /**< Abstracted PMIC Regulator ID for MPU */
    PMHAL_PRCM_PMIC_REGULATOR_CORE = 1,
    /**< Abstracted PMIC Regulator ID for CORE */
    PMHAL_PRCM_PMIC_REGULATOR_MMC = 2,
    /**< Abstracted PMIC Regulator ID for MMC */
    PMHAL_PRCM_PMIC_REGULATOR_SHV5 = 3,
    /**< Abstracted PMIC Regulator ID for SHV5  */
    PMHAL_PRCM_PMIC_REGULATOR_1V8PHY = 4,
    /**< Abstracted PMIC Regulator ID for 1V8PHY */
    PMHAL_PRCM_PMIC_REGULATOR_1V8PLL = 5,
    /**< Abstracted PMIC Regulator ID for 1V8PLL */
    PMHAL_PRCM_PMIC_REGULATOR_MAX = PMHAL_PRCM_PMIC_REGULATOR_1V8PLL,
    /**< Maximum Abstracted PMIC Regulator */
    PMHAL_PRCM_PMIC_REGULATOR_COUNT = (PMHAL_PRCM_PMIC_REGULATOR_MAX + 1)
                                      /**< Count for the PMIC regulators */
} pmhalPrcmPmicRegulatorId_t;

/**
 * \brief SRAM LDO Retention states enumeration
 */
typedef enum pmhalPrcmSramLdoRetState
{
    PMHAL_PRCM_SRAM_LDO_RET_STATE_MIN = 0U,
    /**< Minimum SRAM LDO Retention request state */
    PMHAL_PRCM_SRAM_LDO_RET_STATE_NO_RET = PMHAL_PRCM_SRAM_LDO_RET_STATE_MIN,
    /**< SRAM LDO is not allowed to go to Retention */
    PMHAL_PRCM_SRAM_LDO_RET_STATE_RET = 1U,
    /**< SRAM LDO go to RET mode when all memory of voltage domain are
     *   OFF or RET */
    PMHAL_PRCM_SRAM_LDO_RET_STATE_MAX = PMHAL_PRCM_SRAM_LDO_RET_STATE_RET,
    /**< Maximum SRAM LDO Retention request state */
    PMHAL_PRCM_SRAM_LDO_RET_STATE_INVALID = 0xFFU
                                            /**< Invalid SRAM LDO Retention
                                             * Status */
}pmhalPrcmSramLdoRetState_t;

/**
 * \brief SRAM LDO Transition state enumeration.
 */
typedef enum pmhalPrcmSramLdoTransState
{
    PMHAL_PRCM_SRAM_LDO_TRANS_STATE_MIN = 0U,
    /**< Minimum SRAM LDO Transition state */
    PMHAL_PRCM_SRAM_LDO_TRANS_STATE_STABLE =
        PMHAL_PRCM_SRAM_LDO_TRANS_STATE_MIN,
    /**< SRAM LDO state machine is stable */
    PMHAL_PRCM_SRAM_LDO_TRANS_STATE_IN_TRANSITION = 1U,
    /**< SRAM LDO state machine is in transition */
    PMHAL_PRCM_SRAM_LDO_TRANS_STATE_MAX =
        PMHAL_PRCM_SRAM_LDO_TRANS_STATE_IN_TRANSITION,
    /**< Maximum SRAM LDO Transition state */
    PMHAL_PRCM_SRAM_LDO_TRANS_STATE_INVALID = 0xFFU
                                              /**< Invalid SRAM LDO Transition
                                               * Status */
}pmhalPrcmSramLdoTransState_t;

/**
 * \brief SRAM LDO status.
 */
typedef enum pmhalPrcmSramLdoStatus
{
    PMHAL_PRCM_SRAM_LDO_STATUS_MIN = 0U,
    /**< Minimum SRAM LDO Status */
    PMHAL_PRCM_SRAM_LDO_STATUS_ACTIVE = PMHAL_PRCM_SRAM_LDO_STATUS_MIN,
    /**< SRAMLDO is in ACTIVE mode */
    PMHAL_PRCM_SRAM_LDO_STATUS_RETENTION = 1U,
    /**< SRAMLDO is in RETENTION mode. */
    PMHAL_PRCM_SRAM_LDO_STATUS_MAX = PMHAL_PRCM_SRAM_LDO_STATUS_RETENTION,
    /**< Maximum SRAM LDO Status */
    PMHAL_PRCM_SRAM_LDO_STATUS_INVALID = 0xFFU
                                         /**< Invalid SRAM LDO Status */
}pmhalPrcmSramLdoStatus_t;

/**
 * \brief SRAM LDO Setup Register bit field enumeration.
 */
typedef enum pmhalPrcmSramSetupBitFields
{
    PMHAL_PRCM_SLDO_SETUP_BIT_SHIFT_MIN = 0U,
    /**< Minimum shift supported for SRAM LDO Setup register */
    PMHAL_PRCM_SLDO_SETUP_BIT_ENABLE_RTA = PMHAL_PRCM_SLDO_SETUP_BIT_SHIFT_MIN,
    /**< Bit shift for field which is a control for HD memory RTA feature. */
    PMHAL_PRCM_SLDO_SETUP_BIT_ABBOFF_ACT = 1U,
    /**< Bit shift for field which determines whether SRAMNWA is supplied by
     *   VDDS or RW 0x0 VDDAR during active mode. */
    PMHAL_PRCM_SLDO_SETUP_BIT_ABBOFF_SLEEP = 2U,
    /**< Bit shift for field which determines whether SRAMNWA is supplied by
     *   VDDS or RW 0x0 VDDAR during deep-sleep. */
    PMHAL_PRCM_SLDO_SETUP_BIT_ENFUNC1 = 3U,
    /**< Bit shift for field which controls Short Circuit protection */
    PMHAL_PRCM_SLDO_SETUP_BIT_ENFUNC2 = 4U,
    /**< Bit shift for field which determines External Capacitor usage */
    PMHAL_PRCM_SLDO_SETUP_BIT_ENFUNC3 = 5U,
    /**< Bit shift for field which determines if sub-regulation is enabled */
    PMHAL_PRCM_SLDO_SETUP_BIT_ENFUNC4 = 6U,
    /**< Bit shift for field which determines if external clock is supplied to
     *   SRAM LDO */
    PMHAL_PRCM_SLDO_SETUP_BIT_ENFUNC5 = 7U,
    /**< Bit shift for field which determines if active to retention is a one
     *   step or two step transfer */
    PMHAL_PRCM_SLDO_SETUP_BIT_AIPOFF = 8U,
    /**< Bit shift for field which determines if AIPOFF is overridden or not */
    PMHAL_PRCM_SLDO_SETUP_BIT_SHIFT_COUNT = 9U,
    /**< Maximum shift supported for SRAM LDO Setup register */
    PMHAL_PRCM_SLDO_SETUP_BIT_SHIFT_INVALID = 0xFFU
                                              /**< Invalid shift for SRAM LDO
                                               * Setup register */
}pmhalPrcmSramSetupBitFields_t;

/**
 * \brief Power Domains
 */
typedef enum pmhalPrcmPdId
{
    PMHAL_PRCM_PD_LOWER_BOUND = -1,
    /**< Lower bound */
    PMHAL_PRCM_PD_CUSTEFUSE,
    /**< CUSTEFUSE Power Domain */
    PMHAL_PRCM_PD_GFX,
    /**< GFX Power Domain */
    PMHAL_PRCM_PD_MPU,
    /**< MPU Power Domain */
    PMHAL_PRCM_PD_RTC,
    /**< RTC Power Domain */
    PMHAL_PRCM_PD_WKUP,
    /**< WKUP Power Domain */
    PMHAL_PRCM_PD_PER,
    /**< PER Power Domain */
    PMHAL_PRCM_PD_STDEFUSE,
    /**< STDEFUSE Power Domain */
    PMHAL_PRCM_PD_TAMPER,
    /**< TAMPER Power Domain */
    PMHAL_PRCM_PD_COUNT
    /**< Enum Count */
} pmhalPrcmPdId_t;

/**
 * \brief Clock Domains
 */
typedef enum pmhalPrcmCdId
{
    PMHAL_PRCM_CD_LOWER_BOUND = -1,
    /**< Lower bound */
    PMHAL_PRCM_CD_L4LS,
    /**< PER_L4LS (in TRM) Clock Domain */
    PMHAL_PRCM_CD_L3S,
    /**< PER_L3S (in TRM) Clock Domain */
    PMHAL_PRCM_CD_L3,
    /**< PER_L3 (in TRM) Clock Domain */
    PMHAL_PRCM_CD_OCPWP_L3,
    /**< PER_OCPWP_L3 (in TRM) Clock Domain */
    PMHAL_PRCM_CD_ICSS_OCP,
    /**< PER_PRU_ICSS (in TRM) Clock Domain */
    PMHAL_PRCM_CD_CPSW_125MHZ,
    /**< PER_CPSW (in TRM) Clock Domain */
    PMHAL_PRCM_CD_LCD_L3,
    /**< PER_LCDC (in TRM) Clock Domain */
    PMHAL_PRCM_CD_EMIF_L3,
    /**< PER_EMIF (in TRM) Clock Domain */
    PMHAL_PRCM_CD_DSS_L3,
    /**< PER_DSS (in TRM) Clock Domain */
    PMHAL_PRCM_CD_L4_WKUP,
    /**< WKUP (in TRM) Clock Domain */
    PMHAL_PRCM_CD_L3_AON,
    /**< L3 AON Clock Domain */
    PMHAL_PRCM_CD_L4_WKUP_AON,
    /**< L4 WKUP AON Clock Domain */
    PMHAL_PRCM_CD_L3S_TSC,
    /**< L3S_ADC0 (in TRM) Clock Domain */
    PMHAL_PRCM_CD_MPU,
    /**< MPU Clock Domain */
    PMHAL_PRCM_CD_L4_RTC,
    /**< RTC (in TRM) Clock Domain */
    PMHAL_PRCM_CD_GFX_L3,
    /**< GFX L3 Clock Domain */
    PMHAL_PRCM_CD_L4_CEFUSE,
    /**< CEFUSE (in TRM) Clock Domain */
    PMHAL_PRCM_CD_COUNT
    /**< Enum Count */
} pmhalPrcmCdId_t;

/**
 * \brief Clocks
 */
typedef enum pmhalPrcmClockId
{
    PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK = 0U,
    /**< PM HAL Prcm CUST EFUSE SYSCLK Clock */
    PMHAL_PRCM_CLK_MIN = PMHAL_PRCM_CLK_CUST_EFUSE_SYSCLK,
    /**< Lower bound (inclusive) */
    PMHAL_PRCM_CLK_L4_CEFUSE_GCLK = 1U,
    /**< PM HAL Prcm L4 CEFUSE GCLK Clock */
    PMHAL_PRCM_CLK_GFX_GFCLK = 2U,
    /**< PM HAL Prcm GFX GFCLK Clock */
    PMHAL_PRCM_CLK_GFX_L3_GCLK = 3U,
    /**< PM HAL Prcm GFX L3 GCLK Clock */
    PMHAL_PRCM_CLK_MPU_CLK = 4U,
    /**< PM HAL Prcm MPU Clock */
    PMHAL_PRCM_CLK_CAN_CLK = 5U,
    /**< PM HAL Prcm CAN Clock */
    PMHAL_PRCM_CLK_CPSW_125MHZ_GCLK = 6U,
    /**< PM HAL Prcm CPSE 125MHZ GCLK Clock */
    PMHAL_PRCM_CLK_CPSW_250MHZ_CLK = 7U,
    /**< PM HAL Prcm CPSW 250MHZ CLK Clock */
    PMHAL_PRCM_CLK_CPSW_50MHZ_CLK = 8U,
    /**< PM HAL Prcm CPSW 50MHZ CLK Clock */
    PMHAL_PRCM_CLK_CPSW_5MHZ_CLK = 9U,
    /**< PM HAL Prcm CPSW 5MHZ CLK Clock */
    PMHAL_PRCM_CLK_CPSW_CPTS_RFT_CLK = 10U,
    /**< PM HAL Prcm CPSW CPTS RFT CLK Clock */
    PMHAL_PRCM_CLK_DDR_DLL_GCLK = 11U,
    /**< PM HAL Prcm DDR DLL GCLK Clock */
    PMHAL_PRCM_CLK_DLL_AGING_GCLK = 12U,
    /**< PM HAL Prcm DLL AGING GCLK Clock */
    PMHAL_PRCM_CLK_DSS_GCLK = 13U,
    /**< PM HAL Prcm DSS GCLK Clock */
    PMHAL_PRCM_CLK_DSS_L3_GCLK = 14U,
    /**< PM HAL Prcm DSS L3 GCLK Clock */
    PMHAL_PRCM_CLK_DSS_L4_GCLK_EN = 15U,
    /**< PM HAL Prcm DSS L4 GCLK EN Clock */
    PMHAL_PRCM_CLK_DSS_SYSCLK = 16U,
    /**< PM HAL Prcm DSS SYSCLK Clock */
    PMHAL_PRCM_CLK_EMIF_L3_GICLK = 17U,
    /**< PM HAL Prcm EMIF L3 GCLK Clock */
    PMHAL_PRCM_CLK_EMIF_PHY_GCLK = 18U,
    /**< PM HAL Prcm EMIF PHY GCLK Clock */
    PMHAL_PRCM_CLK_GPIO_1_GDBCLK = 19U,
    /**< PM HAL Prcm GPIO 1 GDBCLK Clock */
    PMHAL_PRCM_CLK_GPIO_2_GDBCLK = 20U,
    /**< PM HAL Prcm GPIO 2 GDBCLK Clock */
    PMHAL_PRCM_CLK_GPIO_3_GDBCLK = 21U,
    /**< PM HAL Prcm GPIO 3 GDBCLK Clock */
    PMHAL_PRCM_CLK_GPIO_4_GDBCLK = 22U,
    /**< PM HAL Prcm GPIO 4 GDBCLK Clock */
    PMHAL_PRCM_CLK_GPIO_5_GDBCLK = 23U,
    /**< PM HAL Prcm GPIO 5 GDBCLK Clock */
    PMHAL_PRCM_CLK_HDQ1W_GCLK = 24U,
    /**< PM HAL Prcm HDQ1W GCLK Clock */
    PMHAL_PRCM_CLK_I2C_FCLK = 25U,
    /**< PM HAL Prcm I2C FCLK Clock */
    PMHAL_PRCM_CLK_ICSS_IEP_GCLK = 26U,
    /**< PM HAL Prcm ICSS IEP GCLK Clock */
    PMHAL_PRCM_CLK_ICSS_OCP_GCLK = 27U,
    /**< PM HAL Prcm ICSS OCP GCLK Clock */
    PMHAL_PRCM_CLK_ICSS_UART_GCLK = 28U,
    /**< PM HAL Prcm ICSS UART GCLK Clock */
    PMHAL_PRCM_CLK_L3D2_GCLK = 29U,
    /**< PM HAL Prcm L3D2 GCLK Clock */
    PMHAL_PRCM_CLK_L3S_GCLK = 30U,
    /**< PM HAL Prcm L3S GCLK Clock */
    PMHAL_PRCM_CLK_L3_GCLK = 31U,
    /**< PM HAL Prcm L3 GCLK Clock */
    PMHAL_PRCM_CLK_L4LS_GCLK = 32U,
    /**< PM HAL Prcm L4LS GCLK Clock */
    PMHAL_PRCM_CLK_LCD_GCLK = 33U,
    /**< PM HAL Prcm LCD GCLK Clock */
    PMHAL_PRCM_CLK_LCD_L3_GCLK = 34U,
    /**< PM HAL Prcm LCD L3 GCLK Clock */
    PMHAL_PRCM_CLK_LCD_L4S_GCLK = 35U,
    /**< PM HAL Prcm LCD L4S GCLK Clock */
    PMHAL_PRCM_CLK_MCASP_FCLK = 36U,
    /**< PM HAL Prcm MCASP FCLK Clock */
    PMHAL_PRCM_CLK_MGC_FCLK = 37U,
    /**< PM HAL Prcm MGC FCLK Clock */
    PMHAL_PRCM_CLK_MMC_FCLK = 38U,
    /**< PM HAL Prcm MMC FCLK Clock */
    PMHAL_PRCM_CLK_OCPWP_L3_GCLK = 39U,
    /**< PM HAL Prcm OCPWP L3 GCLK Clock */
    PMHAL_PRCM_CLK_OCPWP_L4_GCLK_EN = 40U,
    /**< PM HAL Prcm OCPWP L4 GCLK EN Clock */
    PMHAL_PRCM_CLK_SPI_GCLK = 41U,
    /**< PM HAL Prcm SPI GCLK Clock */
    PMHAL_PRCM_CLK_TIMER10_GCLK = 42U,
    /**< PM HAL Prcm TIMER10 GCLK Clock */
    PMHAL_PRCM_CLK_TIMER11_GCLK = 43U,
    /**< PM HAL Prcm TIMER11 GCLK Clock */
    PMHAL_PRCM_CLK_TIMER2_GCLK = 44U,
    /**< PM HAL Prcm TIMER2 GCLK Clock */
    PMHAL_PRCM_CLK_TIMER3_GCLK = 45U,
    /**< PM HAL Prcm TIMER3 GCLK Clock */
    PMHAL_PRCM_CLK_TIMER4_GCLK = 46U,
    /**< PM HAL Prcm TIMER4 GCLK Clock */
    PMHAL_PRCM_CLK_TIMER5_GCLK = 47U,
    /**< PM HAL Prcm TIMER5 GCLK Clock */
    PMHAL_PRCM_CLK_TIMER6_GCLK = 48U,
    /**< PM HAL Prcm TIMER6 GCLK Clock */
    PMHAL_PRCM_CLK_TIMER7_GCLK = 49U,
    /**< PM HAL Prcm TIMER7 GCLK Clock */
    PMHAL_PRCM_CLK_TIMER8_GCLK = 50U,
    /**< PM HAL Prcm TIMER8 GCLK Clock */
    PMHAL_PRCM_CLK_TIMER9_GCLK = 51U,
    /**< PM HAL Prcm TIMER9 GCLK Clock */
    PMHAL_PRCM_CLK_UART_GFCLK = 52U,
    /**< PM HAL Prcm UART GFCLK Clock */
    PMHAL_PRCM_CLK_USB_OTG_SS_REFCLK = 53U,
    /**< PM HAL Prcm USB OTG SS REFCLK Clock */
    PMHAL_PRCM_CLK_USB_PLL_CLK = 54U,
    /**< PM HAL Prcm USB PLL CLK Clock */
    PMHAL_PRCM_CLK_USIM0_FCLK = 55U,
    /**< PM HAL Prcm USIM0 FCLK Clock */
    PMHAL_PRCM_CLK_USIM0_FCLK32 = 56U,
    /**< PM HAL Prcm USIM0 FCLK32 Clock */
    PMHAL_PRCM_CLK_USIM1_FCLK = 57U,
    /**< PM HAL Prcm USIM1 FCLK Clock */
    PMHAL_PRCM_CLK_USIM1_FCLK32 = 58U,
    /**< PM HAL Prcm USIM1 FCLK32 Clock */
    PMHAL_PRCM_CLK_L4_RTC_GCLK = 59U,
    /**< PM HAL Prcm L4 RTC GCLK Clock */
    PMHAL_PRCM_CLK_RTC_32KCLK = 60U,
    /**< PM HAL Prcm RTC 32KCLK Clock */
    PMHAL_PRCM_CLK_STD_EFUSE_SYSCLK = 61U,
    /**< PM HAL Prcm STD EFUSE SYSCLK Clock */
    PMHAL_PRCM_CLK_TAMPER_L4_GCLK = 62U,
    /**< PM HAL Prcm TAMPER L4 GCLK Clock */
    PMHAL_PRCM_CLK_ADC_FCLK = 63U,
    /**< PM HAL Prcm ADC FCLK Clock */
    PMHAL_PRCM_CLK_CLK_24MHZ = 64U,
    /**< PM HAL Prcm CLK 24MHZ Clock */
    PMHAL_PRCM_CLK_DBGSYSCLK = 65U,
    /**< PM HAL Prcm DBGSYSCLK Clock */
    PMHAL_PRCM_CLK_DEBUG_CLKA_GCLK = 66U,
    /**< PM HAL Prcm DEBUG CLKA GCLK Clock */
    PMHAL_PRCM_CLK_DEBUG_CLKB_GCLK = 67U,
    /**< PM HAL Prcm DEBUG CLKB GCLK Clock */
    PMHAL_PRCM_CLK_DEBUG_CLKC_GCLK = 68U,
    /**< PM HAL Prcm DEBUG CLKC GCLK Clock */
    PMHAL_PRCM_CLK_GPIO0_GDBCLK = 69U,
    /**< PM HAL Prcm GPIO0 GDBCLK Clock */
    PMHAL_PRCM_CLK_I2C0_GFCLK = 70U,
    /**< PM HAL Prcm I2C0 GFCLK Clock */
    PMHAL_PRCM_CLK_L3S_TSC_GCLK = 71U,
    /**< PM HAL Prcm L3S TSC GCLK Clock */
    PMHAL_PRCM_CLK_L3_AON_GCLK = 72U,
    /**< PM HAL Prcm L3 AON GCLK Clock */
    PMHAL_PRCM_CLK_L4_WKUP_AON_GCLK = 73U,
    /**< PM HAL Prcm L4 WKUP AON GCLK Clock */
    PMHAL_PRCM_CLK_L4_WKUP_GCLK = 74U,
    /**< PM HAL Prcm L4 WKUP GCLK Clock */
    PMHAL_PRCM_CLK_SR_SYSCLK = 75U,
    /**< PM HAL Prcm SR SYSCLK Clock */
    PMHAL_PRCM_CLK_SYNCTIMER32K_GFCLK = 76U,
    /**< PM HAL Prcm SYNCTIMER32K GFCLK Clock */
    PMHAL_PRCM_CLK_TIMER0_GCLK = 77U,
    /**< PM HAL Prcm TIMER0 GCLK Clock */
    PMHAL_PRCM_CLK_TIMER1_GCLK = 78U,
    /**< PM HAL Prcm TIMER1 GCLK Clock */
    PMHAL_PRCM_CLK_UART0_GFCLK = 79U,
    /**< PM HAL Prcm UART0 GFCLK Clock */
    PMHAL_PRCM_CLK_USBPHY_32KHZ_GCLK = 80U,
    /**< PM HAL Prcm USBPHY 32KHZ GCLK Clock */
#if 0 /* WDT0 is not supported according to AM335x TRM and CTT */
    PMHAL_PRCM_CLK_WDT0_GCLK = 81U,
    /**< PM HAL Prcm WDT0 GCLK Clock */
#endif
    PMHAL_PRCM_CLK_WDT1_GCLK = 82U,
    /**< PM HAL Prcm WDT1 GCLK Clock */
    PMHAL_PRCM_CLK_MAX = PMHAL_PRCM_CLK_WDT1_GCLK,
    /**< Enum Upper bound */
    PMHAL_PRCM_CLK_COUNT = PMHAL_PRCM_CLK_MAX + 1U,
    /**< Enum Count */
    PMHAL_PRCM_CLK_GENERIC = PMHAL_PRCM_CLK_COUNT +1U,
    /**< Generic Clock ID for user to return module functional clock.
     *  Refer PMLIB_CLK_RATE functions for more details.*/
    PMHAL_PRCM_CLK_UNDEF = 0x7FFFFFFFU
                           /**< Undefined value */
} pmhalPrcmClockId_t;

/**
 * \brief Reset Groups
 */
typedef enum pmhalPrcmResetGroupId
{
    PMHAL_PRCM_RG_LOWER_BOUND = -1,
    /**< Lower bound placeholder */
    PMHAL_PRCM_RG_ICSS_RST,
    /**< Reset Group ICSS RST */
    PMHAL_PRCM_RG_WKUP_M3_RST,
    /**< Reset Group WKUP M3 RST */
    PMHAL_PRCM_RG_GFX_RST,
    /**< Reset Group GFX RST */
    PMHAL_PRCM_RG_PROGRAMMABLE_RST_COUNT,
    /**< Enum upper bound count for programmable RST Domains for PRCM */
    PMHAL_PRCM_RG_CUST_EFUSE_RST,
    /**< Reset Group CUST EFUSE RST */
    PMHAL_PRCM_RG_GFX_DOM_RST,
    /**< Reset Group GFX DOM RST */
    PMHAL_PRCM_RG_MPU_AO_RST,
    /**< Reset Group MPU AO RST */
    PMHAL_PRCM_RG_MPU_PWRON_RST,
    /**< Reset Group MPU PWRON RST */
    PMHAL_PRCM_RG_MPU_RST,
    /**< Reset Group MPU RST */
    PMHAL_PRCM_RG_DLL_RST,
    /**< Reset Group DLL RST */
    PMHAL_PRCM_RG_EMIF_DDR_PHY_PWRON_RST,
    /**< Reset Group EMIF DDR PHY PWRON RST */
    PMHAL_PRCM_RG_PER_DOM_RST,
    /**< Reset Group PER DOM RST */
    PMHAL_PRCM_RG_USB_POR_RST,
    /**< Reset Group USB POR RST */
    PMHAL_PRCM_RG_RTC_DOM_RST,
    /**< Reset Group RTC DOM RST */
    PMHAL_PRCM_RG_STD_EFUSE_PWRON_RST,
    /**< Reset Group STD EFUSE PWRON RST */
    PMHAL_PRCM_RG_TAMPER_DOM_RST,
    /**< Reset Group TAMPER DOM RST */
    PMHAL_PRCM_RG_DPLL_RST,
    /**< Reset Group DPLL RST */
    PMHAL_PRCM_RG_EMU_EARLY_PWRON_RST,
    /**< Reset Group EMU_EARLY_PWRON RST */
    PMHAL_PRCM_RG_EMU_PWRON_RST,
    /**< Reset Group EMU PWRON RST */
    PMHAL_PRCM_RG_EMU_RST,
    /**< Reset Group EMU RST */
    PMHAL_PRCM_RG_WKUP_DOM_RST,
    /**< Reset Group WKUP DOM RST */
    PMHAL_PRCM_RG_WKUP_PWRON_RST,
    /**< Reset Group WKUP PWRON RST */
    PMHAL_PRCM_RG_WKUP_SYS_PWRON_RST,
    /**< Reset Group WKUP SYS PWRON RST */
    PMHAL_PRCM_RG_COUNT
    /**< Enum Count */
} pmhalPrcmResetGroupId_t;

/**
 * \brief Reset List
 */
typedef enum pmhalPrcmGlobalResetGroupId
{
    PMHAL_PRCM_GLB_RG_LOWER_BOUND = -1,
    /**< Lower bound (exclusive) */
    PMHAL_PRCM_GLB_RG_MIN = 0,
    /**< Lower bound (inclusive) */
    PMHAL_PRCM_GLB_RG_GLOBAL_COLD_RST = PMHAL_PRCM_GLB_RG_MIN,
    /**< Global Reset Group GLOBAL COLD RST */
    PMHAL_PRCM_GLB_RG_GLOBAL_WARM_SW_RST = 1,
    /**< Global Reset Group GLOBAL WARM SW RST */
#if 0 /* WDT0 is not supported according to AM335x TRM and CTT */
    PMHAL_PRCM_GLB_RG_WDT0_RST = ,
    /**< Global Reset Group WDT0 RST */
#endif
    PMHAL_PRCM_GLB_RG_WDT1_RST = 2,
    /**< Global Reset Group WDT1 RST */
    PMHAL_PRCM_GLB_RG_EXTERNAL_WARM_RST = 3,
    /**< Global Reset Group EXTERNAL WARM RST */
    PMHAL_PRCM_GLB_RG_ICEPICK_RST = 4,
    /**< Global Reset Group ICEPICK RST */
    PMHAL_PRCM_GLB_RG_MPU_SECURITY_VIOL_RST = 5,
    /**< Global Reset Group MPU SECURITY VIOL RST */
    PMHAL_PRCM_GLB_RG_MAX = PMHAL_PRCM_GLB_RG_MPU_SECURITY_VIOL_RST,
    /**< Enum Upper bound */
    PMHAL_PRCM_GLB_RG_COUNT = PMHAL_PRCM_GLB_RG_MAX + 1,
    /**< Enum Count */
    PMHAL_PRCM_GLB_RG_UNDEF = 0x7FFFFFFF
                              /**< Undefined value */
} pmhalPrcmGlobalResetGroupId_t;

/**
 * \brief Reset List
 */
typedef enum pmhalPrcmResetId
{
    PMHAL_PRCM_RST_MIN = 0U,
    /**< Enum Lower bound */
    PMHAL_PRCM_RST_MAX = PMHAL_PRCM_RST_MIN,
    /**< Enum Upper bound */
    PMHAL_PRCM_RST_COUNT = PMHAL_PRCM_RST_MAX + 1U,
    /**< Enum Count */
    PMHAL_PRCM_RST_UNDEF = 0x7FFFFFFFU
                           /**< Undefined value */
} pmhalPrcmResetId_t;

/**
 * \brief Specification of Memory ON State
 */
typedef enum pmhalPrcmMemOnState
{
    MEM_ON_MIN = 0U,
    /**< Lower bound (inclusive) */
    MEM_ON_ALWAYS_ON = MEM_ON_MIN,
    /**<  Memory ON State ALWAYS ON */
    MEM_ON_SOFTWARE_CONTROL = 1U,
    /**<  Memory ON State SOFTWARE CONTROL */
    MEM_ON_MAX = MEM_ON_SOFTWARE_CONTROL,
    /**< Enum Upper bound */
    MEM_ON_COUNT = MEM_ON_MAX + 1U,
    /**< Enum Count */
    MEM_ON_UNDEF = 0x7FFFFFFFU
                   /**< Undefined value */
} pmhalPrcmMemOnState_t;

/**
 * \brief Specification of Memory Retention State
 */
typedef enum pmhalPrcmMemRetState
{
    MEM_RET_MIN = 0U,
    /**< Memory Retention State ALWAYS RETENTION */
    MEM_RET_ALWAYS_RETENTION = MEM_RET_MIN,
    /**< Lower bound (inclusive) */
    MEM_RET_SOFTWARE_CONTROL = 1U,
    /**< Memory Retention State SOFTWARE CONTROL */
    MEM_RET_ALWAYS_OFF = 2U,
    /**< Memory Retention State ALWAYS OFF */
    MEM_RET_MAX = MEM_RET_ALWAYS_OFF,
    /**< Enum Upper bound */
    MEM_RET_COUNT = MEM_RET_MAX + 1U,
    /**< Enum Count */
    MEM_RET_UNDEF = 0x7FFFFFFFU
                    /**< Undefined value */
} pmhalPrcmMemRetState_t;

/**
 * \brief Type of DPLL
 */
typedef enum pmhalPrcmDpllType
{
    PMHAL_PRCM_DPLL_TYPE_MIN = 0U,
    /**< DPLL Type of ADPLL */
    PMHAL_PRCM_DPLL_TYPE_ADPLL = PMHAL_PRCM_DPLL_TYPE_MIN,
    /**< Lower bound (inclusive) */
    PMHAL_PRCM_DPLL_TYPE_ADPLLLJ = 1U,
    /**< DPLL Type of ADPLLLJ */
    PMHAL_PRCM_DPLL_TYPE_MAX = PMHAL_PRCM_DPLL_TYPE_ADPLLLJ,
    /**< Enum Upper bound */
    PMHAL_PRCM_DPLL_TYPE_COUNT = PMHAL_PRCM_DPLL_TYPE_MAX + 1U,
    /**< Enum Count */
    PMHAL_PRCM_DPLL_TYPE_UNDEF = 0x7FFFFFFFU
                                 /**< Undefined value */
} pmhalPrcmDpllType_t;

/**
 * \brief PRCM Logic Retention Type
 */
typedef enum pmhalPrcmRetentionType
{
    PMHAL_PRCM_RT_MIN = 0U,
    /**< PM HAL Prcm Retention NO RETENTION */
    PMHAL_PRCM_RT_NO_RETENTION = PMHAL_PRCM_RT_MIN,
    /**< Lower bound (inclusive) */
    PMHAL_PRCM_RT_FULL_RETENTION = 1U,
    /**< PM HAL Prcm Retention FULL RETENTION */
    PMHAL_PRCM_RT_PARTIAL_RETENTION = 2U,
    /**< PM HAL Prcm Retention PARTIAL RETENTION */
    PMHAL_PRCM_RT_MAX = PMHAL_PRCM_RT_PARTIAL_RETENTION,
    /**< Enum Upper bound */
    PMHAL_PRCM_RT_COUNT = PMHAL_PRCM_RT_MAX + 1U,
    /**< Enum Count */
    PMHAL_PRCM_RT_UNDEF = 0x7FFFFFFFU
                          /**< Undefined value */
} pmhalPrcmRetentionType_t;

/**
 * \brief Physical Memories
 */
typedef enum pmhalPrcmPhyMemId
{
    PMHAL_PRCM_PHY_MEM_MIN = 0U,
    /**< PM HAL Prcm Physical Memory of GFX */
    PMHAL_PRCM_PHY_MEM_GFX = PMHAL_PRCM_PHY_MEM_MIN,
    /**< Lower bound (inclusive) */
    PMHAL_PRCM_PHY_MEM_MPU_L1 = 1U,
    /**< PM HAL Prcm Physical Memory of MPU L1 */
    PMHAL_PRCM_PHY_MEM_MPU_L2 = 2U,
    /**< PM HAL Prcm Physical Memory of MPU L2 */
    PMHAL_PRCM_PHY_MEM_MPU_RAM = 3U,
    /**< PM HAL Prcm Physical Memory of MPU RAM */
    PMHAL_PRCM_PHY_MEM_CPGMACSS_R_RAM_CPPI = 4U,
    /**< PM HAL Prcm Physical Memory of CPGMACSS R RAM CPPI */
    PMHAL_PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_ADDR = 5U,
    /**< PM HAL Prcm Physical Memory of CPGMACSS R RAM RX ADDR */
    PMHAL_PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_DB = 6U,
    /**< PM HAL Prcm Physical Memory of CPGMACSS R RAM RX DB */
    PMHAL_PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_INFO = 7U,
    /**< PM HAL Prcm Physical Memory of CPGMACSS R RAM RX INFO */
    PMHAL_PRCM_PHY_MEM_CPGMACSS_R_RAM_RX_ST = 8U,
    /**< PM HAL Prcm Physical Memory of CPGMACSS R RAM RX ST */
    PMHAL_PRCM_PHY_MEM_CPGMACSS_R_RAM_STATE = 9U,
    /**< PM HAL Prcm Physical Memory of CPGMACSS R RAM STATE */
    PMHAL_PRCM_PHY_MEM_CPGMACSS_R_RAM_STATISTICS = 10U,
    /**< PM HAL Prcm Physical Memory of CPGMACSS R RAM STATISTICS */
    PMHAL_PRCM_PHY_MEM_CPGMACSS_R_RAM_TX_DB = 11U,
    /**< PM HAL Prcm Physical Memory of CPGMACSS R RAM TX DB */
    PMHAL_PRCM_PHY_MEM_CPGMACSS_R_RAM_TX_INFO = 12U,
    /**< PM HAL Prcm Physical Memory of CPGMACSS R RAM TX INFO */
    PMHAL_PRCM_PHY_MEM_CPGMACSS_R_RAM_TX_ST = 13U,
    /**< PM HAL Prcm Physical Memory of CPGMACSS R RAM TX ST */
    PMHAL_PRCM_PHY_MEM_DSSMEM = 14U,
    /**< PM HAL Prcm Physical Memory of DSSMEM */
    PMHAL_PRCM_PHY_MEM_MSHSI2COCP = 15U,
    /**< PM HAL Prcm Physical Memory of MSHSI2COCP */
    PMHAL_PRCM_PHY_MEM_DMEM0 = 16U,
    /**< PM HAL Prcm Physical Memory of DMEM0 */
    PMHAL_PRCM_PHY_MEM_DMEM1 = 17U,
    /**< PM HAL Prcm Physical Memory of DMEM1 */
    PMHAL_PRCM_PHY_MEM_DMEM2 = 18U,
    /**< PM HAL Prcm Physical Memory of DMEM2 */
    PMHAL_PRCM_PHY_MEM_DMEM3 = 19U,
    /**< PM HAL Prcm Physical Memory of DMEM3 */
    PMHAL_PRCM_PHY_MEM_IMEM0 = 20U,
    /**< PM HAL Prcm Physical Memory of IMEM0 */
    PMHAL_PRCM_PHY_MEM_IMEM1 = 21U,
    /**< PM HAL Prcm Physical Memory of IMEM1 */
    PMHAL_PRCM_PHY_MEM_IMEM2 = 22U,
    /**< PM HAL Prcm Physical Memory of IMEM2 */
    PMHAL_PRCM_PHY_MEM_IMEM3 = 23U,
    /**< PM HAL Prcm Physical Memory of IMEM3 */
    PMHAL_PRCM_PHY_MEM_PRUSS0 = 24U,
    /**< PM HAL Prcm Physical Memory of PRUSS0 */
    PMHAL_PRCM_PHY_MEM_PRUSS1 = 25U,
    /**< PM HAL Prcm Physical Memory of PRUSS1 */
    PMHAL_PRCM_PHY_MEM_LCD_CORE_PALETTE_RAM = 26U,
    /**< PM HAL Prcm Physical Memory of LCD CORE PALETTE RAM */
    PMHAL_PRCM_PHY_MEM_LCD_DMA_FIFO_RAM = 27U,
    /**< PM HAL Prcm Physical Memory of LCD DMA FIFO RAM */
    PMHAL_PRCM_PHY_MEM_UART = 28U,
    /**< PM HAL Prcm Physical Memory of UART */
    PMHAL_PRCM_PHY_MEM_MBOXSRAM = 29U,
    /**< PM HAL Prcm Physical Memory of MBOXSRAM */
    PMHAL_PRCM_PHY_MEM_MSTR_EXPS = 30U,
    /**< PM HAL Prcm Physical Memory of MSTR EXPS (MemoryBankNoName in FS) */
    PMHAL_PRCM_PHY_MEM_BANK1 = 31U,
    /**< PM HAL Prcm Physical Memory of BANK1 */
    PMHAL_PRCM_PHY_MEM_BANK2 = 32U,
    /**< PM HAL Prcm Physical Memory of BANK2 */
    PMHAL_PRCM_PHY_MEM_PKA = 33U,
    /**< PM HAL Prcm Physical Memory of PKA */
    PMHAL_PRCM_PHY_MEM_TPCC = 34U,
    /**< PM HAL Prcm Physical Memory of TPCC (MemoryBankNoName in FS) */
    PMHAL_PRCM_PHY_MEM_TPTC0 = 35U,
    /**< PM HAL Prcm Physical Memory of TPTC0 (MemoryBankNoName in FS) */
    PMHAL_PRCM_PHY_MEM_TPTC1 = 36U,
    /**< PM HAL Prcm Physical Memory of TPTC1 (MemoryBankNoName in FS) */
    PMHAL_PRCM_PHY_MEM_TPTC2 = 37U,
    /**< PM HAL Prcm Physical Memory of TPTC2 (MemoryBankNoName in FS) */
    PMHAL_PRCM_PHY_MEM_USB = 38U,
    /**< PM HAL Prcm Physical Memory of USB */
    PMHAL_PRCM_PHY_MEM_WB0 = 39U,
    /**< PM HAL Prcm Physical Memory of WB0 */
    PMHAL_PRCM_PHY_MEM_WB1 = 40U,
    /**< PM HAL Prcm Physical Memory of WB1 */
    PMHAL_PRCM_PHY_MEM_DEBUGSS = 41U,
    /**< PM HAL Prcm Physical Memory of DEBUGSS */
    PMHAL_PRCM_PHY_MEM_MAX = PMHAL_PRCM_PHY_MEM_DEBUGSS,
    /**< Enum Upper bound */
    PMHAL_PRCM_PHY_MEM_COUNT = PMHAL_PRCM_PHY_MEM_MAX + 1U,
    /**< Enum Count */
    PMHAL_PRCM_PHY_MEM_UNDEF = 0x7FFFFFFFU
                               /**< Undefined value */
} pmhalPrcmPhyMemId_t;

/**
 * \brief Physical Memory Bank
 */
typedef enum pmhalPrcmPhyMemBankId
{
    PMHAL_PRCM_PHY_BANK_GFX_MEM = 0U,
    /**< PM HAL Prcm Physical Memory Bank of GFX_MEM */
    PMHAL_PRCM_PHY_BANK_MIN = PMHAL_PRCM_PHY_BANK_GFX_MEM,
    /**< Lower bound (inclusive) */
    PMHAL_PRCM_PHY_BANK_MPU_L1 = 1U,
    /**< PM HAL Prcm Physical Memory Bank of MPU_L1 */
    PMHAL_PRCM_PHY_BANK_MPU_L2 = 2U,
    /**< PM HAL Prcm Physical Memory Bank of MPU_L2 */
    PMHAL_PRCM_PHY_BANK_MPU_RAM = 3U,
    /**< PM HAL Prcm Physical Memory Bank of MPU_RAM */
    PMHAL_PRCM_PHY_BANK_PER_MEM = 4U,
    /**< PM HAL Prcm Physical Memory Bank of PER_MEM */
    PMHAL_PRCM_PHY_BANK_ICSS_MEM = 5U,
    /**< PM HAL Prcm Physical Memory Bank of ICSS_MEM */
    PMHAL_PRCM_PHY_BANK_RAM1_MEM = 6U,
    /**< PM HAL Prcm Physical Memory Bank of RAM1_MEM */
    PMHAL_PRCM_PHY_BANK_RAM2_MEM = 7U,
    /**< PM HAL Prcm Physical Memory Bank of RAM2_MEM */
    PMHAL_PRCM_PHY_BANK_DEBUGSS_MEM = 8U,
    /**< PM HAL Prcm Physical Memory Bank of DEBUGSS_MEM */
    PMHAL_PRCM_PHY_BANK_MAX = PMHAL_PRCM_PHY_BANK_DEBUGSS_MEM,
    /**< Enum Upper bound */
    PMHAL_PRCM_PHY_BANK_COUNT = PMHAL_PRCM_PHY_BANK_MAX + 1U
                                /**< Enum Count */
} pmhalPrcmPhyMemBankId_t;

/**
 *  \brief Enum defining modules with SysConfig
 */
typedef enum pmhalPrcmSysConfigModuleId
{
    PMHAL_PRCM_SYSCFG_LOWER_BOUND = -1,
    /**< Lower bound Place Holder(inclusive) */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
    PMHAL_PRCM_SYSCFG_GPMC,
    /**< PM HAL Prcm SysConfig for GPMC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
    PMHAL_PRCM_SYSCFG_ELM,
    /**< PM HAL Prcm SysConfig for ELM */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CONTROL
    PMHAL_PRCM_SYSCFG_CONTROL,
    /**< PM HAL Prcm SysConfig for CONTROL */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
    PMHAL_PRCM_SYSCFG_TPCC,
    /**< PM HAL Prcm SysConfig for TPCC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC0
    PMHAL_PRCM_SYSCFG_TPTC0,
    /**< PM HAL Prcm SysConfig for TPTC0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC1
    PMHAL_PRCM_SYSCFG_TPTC1,
    /**< PM HAL Prcm SysConfig for TPTC1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC2
    PMHAL_PRCM_SYSCFG_TPTC2,
    /**< PM HAL Prcm SysConfig for TPTC2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
    PMHAL_PRCM_SYSCFG_ADC_TSC,
    /**< PM HAL Prcm SysConfig for ADC_TSC */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD
    PMHAL_PRCM_SYSCFG_MAG_CARD,
    /**< PM HAL Prcm SysConfig for MAG_CARD */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DSS
    PMHAL_PRCM_SYSCFG_DSS,
    /**< PM HAL Prcm SysConfig for DSS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE0
    PMHAL_PRCM_SYSCFG_VPFE0,
    /**< PM HAL Prcm SysConfig for VPFE0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE1
    PMHAL_PRCM_SYSCFG_VPFE1,
    /**< PM HAL Prcm SysConfig for VPFE1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0
    PMHAL_PRCM_SYSCFG_EPWMSS0,
    /**< PM HAL Prcm SysConfig for EPWMSS0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1
    PMHAL_PRCM_SYSCFG_EPWMSS1,
    /**< PM HAL Prcm SysConfig for EPWMSS1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2
    PMHAL_PRCM_SYSCFG_EPWMSS2,
    /**< PM HAL Prcm SysConfig for EPWMSS2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3
    PMHAL_PRCM_SYSCFG_EPWMSS3,
    /**< PM HAL Prcm SysConfig for EPWMSS3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4
    PMHAL_PRCM_SYSCFG_EPWMSS4,
    /**< PM HAL Prcm SysConfig for EPWMSS4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5
    PMHAL_PRCM_SYSCFG_EPWMSS5,
    /**< PM HAL Prcm SysConfig for EPWMSS5 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
    PMHAL_PRCM_SYSCFG_MAILBOX0,
    /**< PM HAL Prcm SysConfig for MAILBOX0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
    PMHAL_PRCM_SYSCFG_SPINLOCK,
    /**< PM HAL Prcm SysConfig for SPINLOCK */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
    PMHAL_PRCM_SYSCFG_MMC0,
    /**< PM HAL Prcm SysConfig for MMC0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
    PMHAL_PRCM_SYSCFG_MMC1,
    /**< PM HAL Prcm SysConfig for MMC1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
    PMHAL_PRCM_SYSCFG_MMC2,
    /**< PM HAL Prcm SysConfig for MMC2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER
    PMHAL_PRCM_SYSCFG_SYNCTIMER,
    /**< PM HAL Prcm SysConfig for SYNCTIMER */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
    PMHAL_PRCM_SYSCFG_RTCSS,
    /**< PM HAL Prcm SysConfig for RTCSS */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
    PMHAL_PRCM_SYSCFG_MCASP0,
    /**< PM HAL Prcm SysConfig for MCASP0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
    PMHAL_PRCM_SYSCFG_MCASP1,
    /**< PM HAL Prcm SysConfig for MCASP1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
    PMHAL_PRCM_SYSCFG_SPI0,
    /**< PM HAL Prcm SysConfig for SPI0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
    PMHAL_PRCM_SYSCFG_SPI1,
    /**< PM HAL Prcm SysConfig for SPI1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
    PMHAL_PRCM_SYSCFG_SPI2,
    /**< PM HAL Prcm SysConfig for SPI2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
    PMHAL_PRCM_SYSCFG_SPI3,
    /**< PM HAL Prcm SysConfig for SPI3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI4
    PMHAL_PRCM_SYSCFG_SPI4,
    /**< PM HAL Prcm SysConfig for SPI4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_QSPI
    PMHAL_PRCM_SYSCFG_QSPI,
    /**< PM HAL Prcm SysConfig for QSPI */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
    PMHAL_PRCM_SYSCFG_GPIO0,
    /**< PM HAL Prcm SysConfig for GPIO0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
    PMHAL_PRCM_SYSCFG_GPIO1,
    /**< PM HAL Prcm SysConfig for GPIO1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
    PMHAL_PRCM_SYSCFG_GPIO2,
    /**< PM HAL Prcm SysConfig for GPIO2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
    PMHAL_PRCM_SYSCFG_GPIO3,
    /**< PM HAL Prcm SysConfig for GPIO3 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
    PMHAL_PRCM_SYSCFG_GPIO4,
    /**< PM HAL Prcm SysConfig for GPIO4 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
    PMHAL_PRCM_SYSCFG_GPIO5,
    /**< PM HAL Prcm SysConfig for GPIO5 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
        PMHAL_PRCM_SYSCFG_I2C0,
        /**< PM HAL Prcm SysConfig for I2C0 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
        PMHAL_PRCM_SYSCFG_I2C1,
        /**< PM HAL Prcm SysConfig for I2C1 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
        PMHAL_PRCM_SYSCFG_I2C2,
        /**< PM HAL Prcm SysConfig for I2C2 */
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
    PMHAL_PRCM_SYSCFG_COUNT,
    /**< Enum Upper bound placeholder and Enum Count */
    PMHAL_PRCM_SYSCFG_NOTAPPLICABLE
    /**< Enum not applicable */
} pmhalPrcmSysConfigModuleId_t;

/**
 * \brief control module configured postdividers
 */
typedef enum pmhalCtrlMdlPostDivIdx
{
    PMHAL_CTRL_POSTDIV_MIN = 0U,
    /**< Lower bound (inclusive) */
    PMHAL_CTRL_POSTDIV_MAX = PMHAL_CTRL_POSTDIV_MIN,
    /**< Enum Upper bound */
    PMHAL_CTRL_POSTDIV_COUNT = PMHAL_CTRL_POSTDIV_MAX + 1U,
    /**< Enum Count */
    PMHAL_CTRL_POSTDIV_NOTAPPLICABLE = 0xFFU
                                       /**< Undefined value */
} pmhalCtrlMdlPostDivIdx_t;

/**
 * \brief Clock Tree nodes - RootClk, Div, Mux, Pll
 */
typedef enum pmhalPrcmNodeId
{
    PMHAL_PRCM_ROOT_CLK_MIN = 0U,
    /**< PM HAL Prcm Root Clock for SYS CLKIN */
    PMHAL_PRCM_ROOT_CLK_SYS_CLKIN = PMHAL_PRCM_ROOT_CLK_MIN,
    /**< Lower bound (inclusive) */
    PMHAL_PRCM_NODE_MIN = PMHAL_PRCM_ROOT_CLK_MIN,
    /**< Lower bound for Node */
    PMHAL_PRCM_ROOT_CLK_TCLKIN = 1U,
    /**< PM HAL Prcm Root Clock for TCLKIN */
    PMHAL_PRCM_ROOT_CLK_32K_PER = 2U,
    /**< PM HAL Prcm Root Clock for 32K PER */
    PMHAL_PRCM_ROOT_CLK_32K_RC = 3U,
    /**< PM HAL Prcm Root Clock for 32K_RC */
    PMHAL_PRCM_ROOT_CLK_32K_RTC = 4U,
    /**< PM HAL Prcm Root Clock for 32K_RTC */
    PMHAL_PRCM_ROOT_CLK_32K_TPM = 5U,
    /**< PM HAL Prcm Root Clock for 32K TPM */
    PMHAL_PRCM_ROOT_CLK_32K_MOSC = 6U,
    /**< PM HAL Prcm Root Clock for 32K MOSC */
    PMHAL_PRCM_ROOT_CLK_BOARD_MAX = PMHAL_PRCM_ROOT_CLK_32K_MOSC,
    /**< PM HAL Prcm Root Clock maximum for Board configuration */
    PMHAL_PRCM_ROOT_CLK_MAX = PMHAL_PRCM_ROOT_CLK_32K_MOSC,
    /**< Enum Upper bound */
    PMHAL_PRCM_ROOT_CLK_COUNT = PMHAL_PRCM_ROOT_CLK_MAX + 1U,
    /**< Enum Count */
    PMHAL_PRCM_MUX_GFX_GFCLK_MUX = 7U,
    /**< PM HAL Prcm Mux Element GFX GFCLK MUX */
    PMHAL_PRCM_MUX_MIN = PMHAL_PRCM_MUX_GFX_GFCLK_MUX,
    /**< Lower bound (inclusive) */
    PMHAL_PRCM_MUX_CLKOUT_32K_MUX = 8U,
    /**< PM HAL Prcm Mux Element CLKOUT 32K MUX */
    PMHAL_PRCM_MUX_CLKOUT1SEL2_PREDIV_MUX = 9U,
    /**< PM HAL Prcm Mux Element CLKOUT1SEL2 PREDIVE MUX */
    PMHAL_PRCM_MUX_CLKOUT1_MUX = 10U,
    /**< PM HAL Prcm Mux Element CLKOUT1 MUX */
    PMHAL_PRCM_MUX_CLKOUT2_MUX = 11U,
    /**< PM HAL Prcm Mux Element CLKOUT2 MUX1 OUT MUX */
    PMHAL_PRCM_MUX_MGC_FGCLK_MUX = 12U,
    /**< PM HAL Prcm Mux Element MGC FGCLK MUX */
    PMHAL_PRCM_MUX_DISP_CLK_MUX = 13U,
    /**< PM HAL Prcm Mux Element DISP CLK MUX */
    PMHAL_PRCM_MUX_ICSS_OCP_GCLK_MUX = 14U,
    /**< PM HAL Prcm Mux Element ICSS OCP GCLK MUX */
    PMHAL_PRCM_MUX_TIMER7_CLK_MUX = 15U,
    /**< PM HAL Prcm Mux Element TIMER7 CLK MUX */
    PMHAL_PRCM_MUX_TIMER2_CLK_MUX = 16U,
    /**< PM HAL Prcm Mux Element TIMER2 CLK MUX */
    PMHAL_PRCM_MUX_TIMER3_CLK_MUX = 17U,
    /**< PM HAL Prcm Mux Element TIMER3 CLK MUX */
    PMHAL_PRCM_MUX_TIMER4_CLK_MUX = 18U,
    /**< PM HAL Prcm Mux Element TIMER4 CLK MUX */
    PMHAL_PRCM_MUX_TIMER5_CLK_MUX = 19U,
    /**< PM HAL Prcm Mux Element TIMER5 CLK MUX */
    PMHAL_PRCM_MUX_TIMER6_CLK_MUX = 20U,
    /**< PM HAL Prcm Mux Element TIMER6 CLK MUX */
    PMHAL_PRCM_MUX_TIMER8_CLK_MUX = 21U,
    /**< PM HAL Prcm Mux Element TIMER8 CLK MUX */
    PMHAL_PRCM_MUX_TIMER9_CLK_MUX = 22U,
    /**< PM HAL Prcm Mux Element TIMER9 CLK MUX */
    PMHAL_PRCM_MUX_TIMER10_CLK_MUX = 23U,
    /**< PM HAL Prcm Mux Element TIMER10 CLK MUX */
    PMHAL_PRCM_MUX_TIMER11_CLK_MUX = 24U,
    /**< PM HAL Prcm Mux Element TIMER11 CLK MUX */
    PMHAL_PRCM_MUX_CPSW_CPTS_RFT_CLK_MUX = 25U,
    /**< PM HAL Prcm Mux Element CPSW CPTS RFT CLK MUX */
    PMHAL_PRCM_MUX_USIM0_FCLK_MUX = 26U,
    /**< PM HAL Prcm Mux Element USIM0 FCLK MUX */
    PMHAL_PRCM_MUX_USIM0_FCLK32_MUX = 27U,
    /**< PM HAL Prcm Mux Element USIM0 FCLK32 MUX */
    PMHAL_PRCM_MUX_USIM1_FCLK_MUX = 28U,
    /**< PM HAL Prcm Mux Element USIM1 FCLK MUX */
    PMHAL_PRCM_MUX_TIMER1_GCLK_MUX = 29U,
    /**< PM HAL Prcm Mux Element TIMER1 GCLK MUX */
#if 0 /* TIMER0 and WDT0 are not supported according to AM335x TRM and CTT */
    PMHAL_PRCM_MUX_TIMER0_GCLK_MUX = U,
    /**< PM HAL Prcm Mux Element TIMER0 GCLK MUX */
    PMHAL_PRCM_MUX_WDT0_GCLK_MUX = U,
    /**< PM HAL Prcm Mux Element WDT0 GCLK MUX */
#endif
    PMHAL_PRCM_MUX_WDT1_GCLK_MUX = 30U,
    /**< PM HAL Prcm Mux Element WDT1 GCLK MUX */
    PMHAL_PRCM_MUX_USBPHY_32KHZ_GCLK_MUX = 31U,
    /**< PM HAL Prcm Mux Element USBPHY 32KHZ GCLK MUX */
    PMHAL_PRCM_MUX_GPIO0_GDBCLK_MUX = 32U,
    /**< PM HAL Prcm Mux Element GPIO0 GDBCLK MUX */
    PMHAL_PRCM_MUX_SYNCTIMER32K_GFCLK_MUX = 33U,
    /**< PM HAL Prcm Mux Element SYNCTIMER32K GFCLK MUX */
    PMHAL_PRCM_MUX_MAX = PMHAL_PRCM_MUX_SYNCTIMER32K_GFCLK_MUX,
    /**< Enum Upper bound */
    PMHAL_PRCM_MUX_COUNT = PMHAL_PRCM_MUX_MAX + 1U,
    /**< Enum Count */
    PMHAL_PRCM_DIV_GFX_GFCLK = 34U,
    /**< PM HAL Prcm Div Element GFX GFCLK */
    PMHAL_PRCM_DIV_MIN = PMHAL_PRCM_DIV_GFX_GFCLK,
    /**< Lower bound (inclusive) */
    PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV1 = 35U,
    /**< PM HAL Prcm Div Element CLKOUT1SEL2 PREDIV1 */
    PMHAL_PRCM_DIV_CLKOUT1SEL2_PREDIV2 = 36U,
    /**< PM HAL Prcm Div Element CLKOUT1SEL2 PREDIV2 */
    PMHAL_PRCM_DIV_CLKIN = 37U,
    /**< PM HAL Prcm Div Element CLKIN */
    PMHAL_PRCM_DIV_CLKOUT2_PREDIV1 = 38U,
    /**< PM HAL Prcm Div Element CLKOUT2 PREDIV1 */
    PMHAL_PRCM_DIV_CLKOUT2_PREDIV2 = 39U,
    /**< PM HAL Prcm Div Element CLKOUT2 PREDIV2 */
    PMHAL_PRCM_DIV_DLL_AGING_GCLK = 40U,
    /**< PM HAL Prcm Div Element DLL AGING GCLK */
    PMHAL_PRCM_DIV_UART_CLK = 41U,
    /**< PM HAL Prcm Div Element UART CLK */
    PMHAL_PRCM_DIV_MMC_CLK = 42U,
    /**< PM HAL Prcm Div Element MMC CLK */
    PMHAL_PRCM_DIV_FUNC_12M_CLK = 43U,
    /**< PM HAL Prcm Div Element FUNC 12M CLK */
    PMHAL_PRCM_DIV_CPSW_125MHZ_GCLK = 44U,
    /**< PM HAL Prcm Div Element CPSW 125MHZ GCLK */
    PMHAL_PRCM_DIV_CPSW_50MHZ_CLK = 45U,
    /**< PM HAL Prcm Div Element CPSW 50MHZ CLK */
    PMHAL_PRCM_DIV_CPSW_5MHZ_CLK = 46U,
    /**< PM HAL Prcm Div Element CPSW 5MHZ CLK */
    PMHAL_PRCM_DIV_CORE_200M = 47U,
    /**< PM HAL Prcm Div Element CORE 200M */
    PMHAL_PRCM_DIV_SYSCLK1 = 48U,
    /**< PM HAL Prcm Div Element SYSCLK1 */
    PMHAL_PRCM_DIV_CORE_100M = 49U,
    /**< PM HAL Prcm Div Element CORE 100M */
    PMHAL_PRCM_DIV_CORE_25M = 50U,
    /**< PM HAL Prcm Div Element CORE 25M */
    PMHAL_PRCM_DIV_VTP_CLK = 51U,
    /**< PM HAL Prcm Div Element VTP CLK */
    PMHAL_PRCM_DIV_UART0_CLK = 52U,
    /**< PM HAL Prcm Div Element UART0 CLK */
    PMHAL_PRCM_DIV_CLK_24MHZ = 53U,
    /**< PM HAL Prcm Div Element CLK 24MHZ */
    PMHAL_PRCM_DIV_MAX = PMHAL_PRCM_DIV_CLK_24MHZ,
    /**< Enum Upper bound */
    PMHAL_PRCM_DIV_COUNT = PMHAL_PRCM_DIV_MAX + 1U,
    /**< Enum Count */
    PMHAL_PRCM_DPLL_PER = 54U,
    /**< PM HAL Prcm Dpll Element PER */
    PMHAL_PRCM_DPLL_MIN = PMHAL_PRCM_DPLL_PER,
    /**< Lower bound (inclusive) */
    PMHAL_PRCM_DPLL_MPU = 55U,
    /**< PM HAL Prcm Dpll Element MPU */
    PMHAL_PRCM_DPLL_DDR = 56U,
    /**< PM HAL Prcm Dpll Element DDR */
    PMHAL_PRCM_DPLL_DISP = 57U,
    /**< PM HAL Prcm Dpll Element DISP */
    PMHAL_PRCM_DPLL_CORE = 58U,
    /**< PM HAL Prcm Dpll Element CORE */
    PMHAL_PRCM_DPLL_EXTDEV = 59U,
    /**< PM HAL Prcm Dpll Element EXTDEV */
    PMHAL_PRCM_DPLL_MAX = PMHAL_PRCM_DPLL_EXTDEV,
    /**< Enum Upper bound */
    PMHAL_PRCM_DPLL_COUNT = PMHAL_PRCM_DPLL_MAX + 1U,
    /**< Enum Count */
    PMHAL_PRCM_NODE_MAX = PMHAL_PRCM_DPLL_EXTDEV,
    /**< Upper bound for Node */
    PMHAL_PRCM_NODE_COUNT = PMHAL_PRCM_DPLL_COUNT,
    /**< Enum Count for Node */
    PMHAL_PRCM_ROOT_CLK_UNDEF = 0x7FFFFFFFU,
    /**< Undefined value */
    PMHAL_PRCM_MUX_UNDEF = 0x7FFFFFFFU,
    /**< Undefined value */
    PMHAL_PRCM_DIV_UNDEF = 0x7FFFFFFFU,
    /**< Undefined value */
    PMHAL_PRCM_DPLL_UNDEF = 0x7FFFFFFFU,
    /**< Undefined value */
    PMHAL_PRCM_NODE_UNDEF = 0x7FFFFFFFU,
                                /**< Undefined value */
} pmhalPrcmNodeId_t;

/**
 * \brief Modules (Clk Tree leaf nodes)
 */
typedef enum pmhalPrcmModuleId
{
    PMHAL_PRCM_MOD_LOWER_BOUND = PMHAL_PRCM_NODE_MAX,
    /**< Enum Lower bound placeholder */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_AES0
    PMHAL_PRCM_MOD_AES0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_AES0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0
    PMHAL_PRCM_MOD_CPGMAC0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CPGMAC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CRYPTODMA
    PMHAL_PRCM_MOD_CRYPTODMA,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CRYPTODMA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN0
    PMHAL_PRCM_MOD_DCAN0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DCAN1
    PMHAL_PRCM_MOD_DCAN1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DCAN1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DDRPHY
    PMHAL_PRCM_MOD_DDRPHY,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DDRPHY */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DES
    PMHAL_PRCM_MOD_DES,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DES */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DLL
    PMHAL_PRCM_MOD_DLL,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DLL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DLL_AGING
    PMHAL_PRCM_MOD_DLL_AGING,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DLL_AGING */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DSS
    PMHAL_PRCM_MOD_DSS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ELM
    PMHAL_PRCM_MOD_ELM,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ELM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF
    PMHAL_PRCM_MOD_EMIF,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW
    PMHAL_PRCM_MOD_EMIF_FW,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EMIF_FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0
    PMHAL_PRCM_MOD_EPWMSS0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1
    PMHAL_PRCM_MOD_EPWMSS1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2
    PMHAL_PRCM_MOD_EPWMSS2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3
    PMHAL_PRCM_MOD_EPWMSS3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4
    PMHAL_PRCM_MOD_EPWMSS4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5
    PMHAL_PRCM_MOD_EPWMSS5,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EPWMSS5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ERMC
    PMHAL_PRCM_MOD_ERMC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ERMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO1
    PMHAL_PRCM_MOD_GPIO1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO2
    PMHAL_PRCM_MOD_GPIO2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO3
    PMHAL_PRCM_MOD_GPIO3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO4
    PMHAL_PRCM_MOD_GPIO4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO5
    PMHAL_PRCM_MOD_GPIO5,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPMC
    PMHAL_PRCM_MOD_GPMC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPMC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_HDQ1W
    PMHAL_PRCM_MOD_HDQ1W,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_HDQ1W */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C1
    PMHAL_PRCM_MOD_I2C1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C2
    PMHAL_PRCM_MOD_I2C2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ICSS
    PMHAL_PRCM_MOD_ICSS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ICSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_IEEE5000
    PMHAL_PRCM_MOD_IEEE5000,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_IEEE5000 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3
    PMHAL_PRCM_MOD_L3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR
    PMHAL_PRCM_MOD_L3_INSTR,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L3_INSTR */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4FW
    PMHAL_PRCM_MOD_L4FW,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4FW */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4LS
    PMHAL_PRCM_MOD_L4LS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4LS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4_HS
    PMHAL_PRCM_MOD_L4_HS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4_HS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_LCDC
    PMHAL_PRCM_MOD_LCDC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_LCDC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD
    PMHAL_PRCM_MOD_MAG_CARD,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAG_CARD */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0
    PMHAL_PRCM_MOD_MAILBOX0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MAILBOX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP0
    PMHAL_PRCM_MOD_MCASP0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MCASP1
    PMHAL_PRCM_MOD_MCASP1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MCASP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC0
    PMHAL_PRCM_MOD_MMC0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC1
    PMHAL_PRCM_MOD_MMC1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MMC2
    PMHAL_PRCM_MOD_MMC2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MMC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS
    PMHAL_PRCM_MOD_MSTR_EXPS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MSTR_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM
    PMHAL_PRCM_MOD_OCMCRAM,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCMCRAM */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC
    PMHAL_PRCM_MOD_OCP_WP_NOC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OCP_WP_NOC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_OTFA_EMIF
    PMHAL_PRCM_MOD_OTFA_EMIF,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_OTFA_EMIF */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_PKA
    PMHAL_PRCM_MOD_PKA,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_PKA */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_QSPI
    PMHAL_PRCM_MOD_QSPI,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_QSPI */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RNG
    PMHAL_PRCM_MOD_RNG,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RNG */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SHA0
    PMHAL_PRCM_MOD_SHA0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SHA0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS
    PMHAL_PRCM_MOD_SLV_EXPS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SLV_EXPS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE0
    PMHAL_PRCM_MOD_SPARE0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPARE1
    PMHAL_PRCM_MOD_SPARE1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPARE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI0
    PMHAL_PRCM_MOD_SPI0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI1
    PMHAL_PRCM_MOD_SPI1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI2
    PMHAL_PRCM_MOD_SPI2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI3
    PMHAL_PRCM_MOD_SPI3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPI4
    PMHAL_PRCM_MOD_SPI4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPI4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK
    PMHAL_PRCM_MOD_SPINLOCK,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SPINLOCK */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER10
    PMHAL_PRCM_MOD_TIMER10,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER10 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER11
    PMHAL_PRCM_MOD_TIMER11,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER11 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER2
    PMHAL_PRCM_MOD_TIMER2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER3
    PMHAL_PRCM_MOD_TIMER3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER4
    PMHAL_PRCM_MOD_TIMER4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER5
    PMHAL_PRCM_MOD_TIMER5,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER6
    PMHAL_PRCM_MOD_TIMER6,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER6 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER7
    PMHAL_PRCM_MOD_TIMER7,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER7 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER8
    PMHAL_PRCM_MOD_TIMER8,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER8 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER9
    PMHAL_PRCM_MOD_TIMER9,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER9 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPCC
    PMHAL_PRCM_MOD_TPCC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPCC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC0
    PMHAL_PRCM_MOD_TPTC0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC1
    PMHAL_PRCM_MOD_TPTC1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPTC2
    PMHAL_PRCM_MOD_TPTC2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPTC2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART1
    PMHAL_PRCM_MOD_UART1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART2
    PMHAL_PRCM_MOD_UART2,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART2 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART3
    PMHAL_PRCM_MOD_UART3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART4
    PMHAL_PRCM_MOD_UART4,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART4 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART5
    PMHAL_PRCM_MOD_UART5,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART5 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP0
    PMHAL_PRCM_MOD_USBPHYOCP2SCP0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP1
    PMHAL_PRCM_MOD_USBPHYOCP2SCP1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USBPHYOCP2SCP1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS0
    PMHAL_PRCM_MOD_USB_OTG_SS0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS1
    PMHAL_PRCM_MOD_USB_OTG_SS1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_OTG_SS1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USIM0
    PMHAL_PRCM_MOD_USIM0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USIM0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USIM1
    PMHAL_PRCM_MOD_USIM1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USIM1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE0
    PMHAL_PRCM_MOD_VPFE0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_VPFE1
    PMHAL_PRCM_MOD_VPFE1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_VPFE1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GFX
    PMHAL_PRCM_MOD_GFX,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GFX */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC
    PMHAL_PRCM_MOD_ADC_TSC,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_ADC_TSC */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K
    PMHAL_PRCM_MOD_CLKDIV32K,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CLKDIV32K */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CONTROL
    PMHAL_PRCM_MOD_CONTROL,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CONTROL */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS
    PMHAL_PRCM_MOD_DEBUGSS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_DEBUGSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_GPIO0
    PMHAL_PRCM_MOD_GPIO0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_GPIO0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_I2C0
    PMHAL_PRCM_MOD_I2C0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_I2C0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_L4WKUP
    PMHAL_PRCM_MOD_L4WKUP,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_L4WKUP */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0
    PMHAL_PRCM_MOD_SMARTREFLEX0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1
    PMHAL_PRCM_MOD_SMARTREFLEX1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SMARTREFLEX1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER
    PMHAL_PRCM_MOD_SYNCTIMER,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_SYNCTIMER */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER0
    PMHAL_PRCM_MOD_TIMER0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TIMER1
    PMHAL_PRCM_MOD_TIMER1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TIMER1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_UART0
    PMHAL_PRCM_MOD_UART0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_UART0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON
    PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_PHY0_ALWAYS_ON */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON
    PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_USB_PHY1_ALWAYS_ON */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT0
    PMHAL_PRCM_MOD_WDT0,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT0 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WDT1
    PMHAL_PRCM_MOD_WDT1,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WDT1 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3
    PMHAL_PRCM_MOD_WKUP_M3,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_WKUP_M3 */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_CEFUSE
    PMHAL_PRCM_MOD_CEFUSE,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_CEFUSE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_RTCSS
    PMHAL_PRCM_MOD_RTCSS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_RTCSS */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_MPU
    PMHAL_PRCM_MOD_MPU,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_MPU */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_EFUSE
    PMHAL_PRCM_MOD_EFUSE,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_EFUSE */
#ifdef BUILDCFG_PMHAL_PRCM_MOD_TPMSS
        PMHAL_PRCM_MOD_TPMSS,
#endif /* BUILDCFG_PMHAL_PRCM_MOD_TPMSS */
    PMHAL_PRCM_MOD_COUNT,
    /**< Enum Upper bound placeholder */
    PMHAL_PRCM_MOD_UNDEF
    /**< Undefined value */
} pmhalPrcmModuleId_t;

/**
 *  \brief Enum defining the CPUs available in the SoC.
 */
typedef enum pmhalPrcmSocCpuId
{
    PMHAL_PRCM_SOC_CPU_ID_MIN = 0x0U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_SOC_CPU_ID_MPU = PMHAL_PRCM_SOC_CPU_ID_MIN,
    /**< MPU CPU Id Enumeration */
    PMHAL_PRCM_SOC_CPU_ID_MAX = PMHAL_PRCM_SOC_CPU_ID_MPU
                                /**< Max value of the enum.
                                 * Can be used for validation. */
} pmhalPrcmSocCpuId_t;

/**
 *  \brief  Enum defining the interrupts supported by the PRM. The enumeration
 *          values correspond to their bit shifts. The bit shifts for MPU are
 *          slightly different than the other CPUs. This is taken care of in the
 *          API definition.
 */
typedef enum pmhalPrcmPrmIntId
{
    PMHAL_PRCM_PRM_INT_MIN = 0x8U,
    /**< Min value of the enum. Can be used for validation. */
    PMHAL_PRCM_PRM_INT_TRANSITION = PMHAL_PRCM_PRM_INT_MIN,
    /**< TRANSITION Interrupt Enumeration */
    PMHAL_PRCM_PRM_INT_FORCEWKUP = 0xAU,
    /**< FORCEWKUP Interrupt Enumeration */
    PMHAL_PRCM_PRM_INT_DPLL_MPU_RECAL = 0xBU,
    /**< DPLL_MPU_RECAL Interrupt Enumeration */
    PMHAL_PRCM_PRM_INT_DPLL_CORE_RECAL = 0xCU,
    /**< DPLL_CORE_RECAL Interrupt Enumeration */
    PMHAL_PRCM_PRM_INT_DPLL_PER_RECAL = 0xDU,
    /**< DPLL_PER_RECAL Interrupt Enumeration */
    PMHAL_PRCM_PRM_INT_DPLL_DDR_RECAL = 0xEU,
    /**< DPLL_DDR_RECAL Interrupt Enumeration */
    PMHAL_PRCM_PRM_INT_DPLL_DISP_RECAL = 0xFU,
    /**< DPLL_DISP_RECAL Interrupt Enumeration */
    PMHAL_PRCM_PRM_INT_DPLL_EXTDEV_RECAL = 0x10U,
    /**< DPLL_EXTDEV_RECAL Interrupt Enumeration */
    PMHAL_PRCM_PRM_INT_MAX = PMHAL_PRCM_PRM_INT_DPLL_EXTDEV_RECAL
                             /**< Max Interrupt Number */
} pmhalPrcmPrmIntId_t;

/**
 *  \brief Structure defining pll post divider value with post divider ID.
 *         User will use this struct to pass information to the prcm API's.
 *         The division values are 1-N (direct value written to register),
 *         so mapping to bit-field config value is not needed.
 */
typedef struct pmhalPrcmPllPostDivValue
{
    pmhalPrcmDpllPostDivId_t postDivId;
    /**< Unique Id of the post divider. */
    uint32_t                 configValue;
    /**< Division value. */
} pmhalPrcmPllPostDivValue_t;

/**
 * \brief This shall be used by the APIs to take configuration input from the
 *        user. This struct will not be modelled to represent a PLL.
 */
typedef struct pmhalPrcmDpllConfig
{
    uint16_t                    multiplier;
    /**< Multiplier value for DPLL configuration. */
    uint16_t                    divider;
    /**< Divider value for DPLL configuration. */
    uint32_t                    dutyCycleCorrector;
    /**< DutyCycleCorrector enable or disable */
    pmhalPrcmPllPostDivValue_t *postDivConfList;
    /**< List of post divider configuration values. */
    uint32_t                    maxPostDivElems;
    /**< Maximum postdivider elements. */
    uint32_t                    fracMultiplier;
    /**< Fractional Multipler for DPLL Configuration */
} pmhalPrcmDpllConfig_t;

/**
 * \brief Enumeration of all the Modules that are associated with OPP.
 *        These are the processing units and Interconnect
 */
typedef enum pmhalPrcmCpuId
{
    PMHAL_PRCM_CPU_ID_MIN = 0,
    /**< Minimum CPU Index */
    PMHAL_PRCM_CPU_ID_MPU = PMHAL_PRCM_CPU_ID_MIN,
    /**< CPU Index for MPU */
    PMHAL_PRCM_CPU_ID_MAX = PMHAL_PRCM_CPU_ID_MPU,
    /**< Maximum CPU Index */
    PMHAL_PRCM_CPU_ID_COUNT = PMHAL_PRCM_CPU_ID_MAX + 1,
    /**< CPU Index Count */
    PMHAL_PRCM_CPU_ID_UNDEF = -1
                              /**< Undefined CPU Index */
} pmhalPrcmCpuId_t;

/**
 * \brief Operating Performance Points
 */
typedef enum pmhalPrcmVmOppId
{
    PMHAL_VM_OPP_MIN = 0,
    /**< MIN Operating Point */
    PMHAL_VM_OPP_LOW = 0,
    /**< Low OPP_50 Operating Point */
    PMHAL_VM_OPP_NOM = 1,
    /**< Nominal OPP_100 Operating Point */
    PMHAL_VM_OPP_OD = 2,
    /**< Over Drive OPP_120 Operating Point */
    PMHAL_VM_OPP_HIGH = 3,
    /**< High OPP_TURBO Operating Point */
    PMHAL_VM_OPP_HIGH2 = 4,
    /**< High OPP_NITRO Operating Point */
    PMHAL_VM_OPP_MAX = 5,
    /**< Maximum Operating Point */
    PMHAL_VM_OPP_UNDEF = -1
                         /**< Invalid Operating Point */
} pmhalVmOppId_t;

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

#ifdef __cplusplus
}
#endif

#endif /* PMHAL_PRCM_H_ */

