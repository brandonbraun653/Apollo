/**
 *  \file  epwm.h
 *
 *  \brief This file contains declarations of device abstraction layer APIs
 *         corresponding to the ePWM module. This also contains necessary
 *         structure, enum and macro definitions and APIs are consolidated to
 *         provide more functional APIs.
 *
 *  \details Programming sequence of EPWM is as follows:
 *           -# Enable Clocks for PWMSS
 *           -# Configure the pinmux functionality
 *           -# Enable the clocks for EPWM through the API EPWMClockEnable.
 *           -# Enable the Time base clock through the API
 *              PWMSSTimebaseClkEnable.
 *           -# The sub-modules of EPWM have to be configured as below:
 *            -# Timebase
 *             -# Configure the time base clock through the API
 *                 #EPWMTbTimebaseClkCfg
 *             -# Configure the output PWM frequency through the API
 *                 #EPWMTbPwmFreqCfg
 *             -# If synchronization is enable, then configure the
 *                synchronization through the API #EPWMTbSyncEnable else disable
 *                synchronization through the API #EPWMTbSyncDisable
 *             -# Set the sync out mode through the API #EPWMTbSetSyncOutMode
 *             -# Set the emulation mode through the API #EPWMTbSetEmulationMode
 *            -# Counter comparator
 *             -# Configure the counter comparator through the API
 *                #EPWMCounterComparatorCfg
 *            -# DeadBand
 *             -# If deadband is enabled, then configure deadband through the
 *                API #EPWMDeadbandCfg else bypass the deadband through the API
 *                #EPWMDeadbandBypass
 *            -# Chopper
 *             -# If chopper is enabled
 *              -# Configure chopper through the API #EPWMChopperCfg
 *              -# Enable the chopper through the API #EPWMChopperEnable by
 *                 passing TRUE as parameter
 *             -# If chopper is disabled
 *              -# Disable chopper through the API #EPWMChopperEnable by passing
 *                 FALSE as parameter
 *            -# TripZone
 *             -# If tripzone is enabled
 *              -# Configure trip action through API #EPWMTzTriggerTripAction
 *              -# Enable trip zone event through the API #EPWMTzTripEventEnable
 *             -# If tripzone is disabled
 *              -# Disable both the trip zone events through the API
 *                 #EPWMTzTripEventDisable
 *            -# Event Trigger
 *             -# Enable event trigger through the API #EPWMEtIntrCfg
 *             -# Disable event trigger through the API #EPWMEtIntrDisable
 *            -# HighResolution
 *             -# If enabled:
 *              -# Configure the High resolution through the API
 *                 #EPWMHighResolutionCfg
 *              -# Load the high resolution values either through the API
 *                 #EPWMHrLoadCmpAHrValue or through the API
 *                 #EPWMHrLoadTbPhaseHrValue
 *             -# If disabled:
 *              -# Disable high-resolution feature through the API
 *                 #EPWMHighResolutionDisable.
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

#ifndef EPWM_H_
#define EPWM_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "hw_pwmss_epwm.h"
#include "hw_pwmss_submodule_offsets.h"
#include "misc.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*              API compatibility with Starterware 2.0                        */
/* ========================================================================== */
#define EHRPWMTimebaseClkConfig             EPWMTbTimebaseClkCfg
#define EHRPWMTimebaseSyncDisable           EPWMTbSyncDisable
#define EHRPWMTriggerSWSync                 EPWMTbTriggerSwSync
#define EHRPWMWriteTBCount                  EPWMTbWriteTbCount
#define EHRPWMReadTBCount                   EPWMTbReadTbCount
#define EHRPWMETEventCount                  EPWMEtGetEventCount
#define EHRPWMETIntStatus                   EPWMEtIntrStatus
#define EHRPWMETIntClear                    EPWMEtIntrClear
#define EHRPWMETIntSWForce                  EPWMEtIntrTrigger
#define EHRPWMLoadTBPHSHR                   EPWMHrLoadTbPhaseHrValue
#define EHRPWMConfigHR                      EPWMHighResolutionCfg
#define EHRPWMHRDisable                     EPWMHighResolutionDisable
#define EHRPWMClockEnable                   EPWMClockEnable
#define EHRPWMClockDisable                  EHRPWMClockDisable
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Number of supported EPWM outputs in a single epwm channel. */
typedef enum epwmOutputCh
{
    EPWM_OUTPUT_CH_MIN = 0U,
    /**< Minimum value of enumeration. Used for input validation. */
    EPWM_OUTPUT_CH_A  = EPWM_OUTPUT_CH_MIN,
    /**< Output channel A. */
    EPWM_OUTPUT_CH_B  = 1U,
    /**< Output channel B. */
    EPWM_OUTPUT_CH_MAX = EPWM_OUTPUT_CH_B
    /**< Maximum value of enumeration. Used for input validation. */
}epwmOutputCh_t;

/** \brief Types of Time base counter direction modes. */
typedef enum epwmTbCounterDir
{
    EPWM_TB_COUNTER_DIR_UP      = PWMSS_EPWM_TBCTL_CTRMODE_UP_COUNT,
    /**< Up Count mode. */
    EPWM_TB_COUNTER_DIR_DOWN    = PWMSS_EPWM_TBCTL_CTRMODE_DOWN_COUNT,
    /**< Down count mode. */
    EPWM_TB_COUNTER_DIR_UP_DOWN = PWMSS_EPWM_TBCTL_CTRMODE_UP_DOWN_COUNT,
    /**< Up down count mode. */
    EPWM_TB_COUNTER_DIR_STOP    = PWMSS_EPWM_TBCTL_CTRMODE_STOP_FREEZE
    /**< stop-freeze counter operation (default on reset). */
}epwmTbCounterDir_t;

/** \brief Shadow register enable or disable control.
 *
 *  \details Same macros will be used to control the following shadow registers
 *           - Time Base period register
 *           - Counter Comparator A register
 *           - Counter Comparator B register
 *
 *  \note   Same macros are used for controlling all the three registers because
 *          the field values are same for all these cases.
 *          - Shadow enable  = 0x0
 *          - Shadow disable = 0x1
 *          In any case if these values changes across the above mentioned
 *          registers then separate macros need to be used.
 *          - Shadow enable macros with value 0x0
 *              - PWMSS_EPWM_TBCTL_PRDLD_LOAD_FROM_SHADOW,
 *              - PWMSS_EPWM_CMPCTL_SHDWAMODE_SHADOW,
 *              - PWMSS_EPWM_CMPCTL_SHDWBMODE_SHADOW
 *          - Shadow disable macros with value 0x1
 *              - PWMSS_EPWM_TBCTL_PRDLD_LOAD_IMMEDIATELY
 *              - PWMSS_EPWM_CMPCTL_SHDWAMODE_IMMEDIATE
 *              - PWMSS_EPWM_CMPCTL_SHDWBMODE_IMMEDIATE
 */
typedef enum epwmShadowRegCtrl
{
    EPWM_SHADOW_REG_CTRL_ENABLE  = PWMSS_EPWM_TBCTL_PRDLD_LOAD_FROM_SHADOW,
    /**< Shadow register value will be used. */
    EPWM_SHADOW_REG_CTRL_DISABLE = PWMSS_EPWM_TBCTL_PRDLD_LOAD_IMMEDIATELY
    /**< Shadow register is disabled and active register value will be used. */
}epwmShadowRegCtrl_t;

/** \brief Counter directions after sync event. */
typedef enum epwmTbCntDirAftSync
{
    EPWM_TB_CNT_DIR_AFT_SYNC_DOWN = PWMSS_EPWM_TBCTL_PHSDIR_COUNT_DOWN,
    /**< Count down after the synchronization event. */
    EPWM_TB_CNT_DIR_AFT_SYNC_UP   = PWMSS_EPWM_TBCTL_PHSDIR_COUNT_UP
    /**< Count up after the synchronization event. */
}epwmTbCntDirAftSync_t;

/** \brief Source of Synchronization output signal. */
typedef enum epwmTbSyncOutEvt
{
    EPWM_TB_SYNC_OUT_EVT_SYNCIN        = PWMSS_EPWM_TBCTL_SYNCOSEL_EPWMXSYNC,
    /**< Sync Input signal. */
    EPWM_TB_SYNC_OUT_EVT_CNT_EQ_ZERO   = PWMSS_EPWM_TBCTL_SYNCOSEL_CTR_0,
    /**< Time-base counter equal to zero. */
    EPWM_TB_SYNC_OUT_EVT_CNT_EQ_CMP_B  = PWMSS_EPWM_TBCTL_SYNCOSEL_CTR_CPMB,
    /**< Time-base counter equal to counter-compare B (TBCNT = CMPB). */
    EPWM_TB_SYNC_OUT_EVT_DISABLE       =
        PWMSS_EPWM_TBCTL_SYNCOSEL_DISABLE_EPWMXSYNCO
    /**< Disable EPWMxSYNCO(Sync Output) signal. */
}epwmTbSyncOutEvt_t;

/** \brief Flags to get the different types of time base status. */
typedef enum epwmTbSts
{
    EPWM_TB_STS_CTR_MAX  = PWMSS_EPWM_TBSTS_CTRMAX_MASK,
    /**< Time-Base Counter Max Latched Status. */
    EPWM_TB_STS_SYNCI    = PWMSS_EPWM_TBSTS_SYNCI_MASK,
    /**< Input Synchronization Latched Status. */
    EPWM_TB_STS_CTR_DIR  = PWMSS_EPWM_TBSTS_CTRDIR_MASK,
    /**< Time-Base Counter Direction Status. */
}epwmTbSts_t;

/** \brief Emulation Mode. This selects the behaviour of the ePWM time-base
           counter during emulation events. */
typedef enum epwmTbEmuMode
{
    EPWM_TB_EMU_MODE_STP_AFT_NEXT_CYCLE  =
        PWMSS_EPWM_TBCTL_FREE_SOFT_STOP_AFTER_NEXT_CTR,
    /**< Stop after the next time-base counter increment or decrement. */
    EPWM_TB_EMU_MODE_STP_AFT_COMPLETE_CYCLE =
        PWMSS_EPWM_TBCTL_FREE_SOFT_STOP_AFTER_CYCLE,
    /**< Stop after the next time-base counter increment or decrement.
         Up-count mode: stop when the time-base counter = period.
         Down-count mode: stop when the time-base counter = 0000.
         Up-down-count mode: stop when the time-base counter = 0000. */
    EPWM_TB_EMU_MODE_FREE_RUN = PWMSS_EPWM_TBCTL_FREE_SOFT_RUN2
    /**< Counter is in Free run. */
}epwmTbEmuMode_t;

/** \ Counter Comparator type either A or B. */
typedef enum epwmCcCmp
{
    EPWM_CC_CMP_MIN = 0U,
     /**< Minimum value of enumeration. Used for input validation. */
    EPWM_CC_CMP_A = EPWM_CC_CMP_MIN,
    /**< Counter Comparator A. */
    EPWM_CC_CMP_B = 1U,
    /**< Counter Comparator B. */
    EPWM_CC_CMP_MAX = EPWM_CC_CMP_B
     /**< Maximum value of enumeration. Used for input validation. */
}epwmCcCmp_t;

/** \brief   Counter-Comparator registers(A and B) load mode flags from shadow
 *           register.
 *
 *  \details Same macros will be used to control the following registers
 *           - Counter Comparator A register
 *           - Counter Comparator B register
 *
 *  \note   Same macros are used for controlling all the three registers because
 *          the field values are same for all these cases.
 *          - load when counter equals zero   = 0x0
 *          - load when counter equals period = 0x1
 *          - load when counter equals zero or period = 0x2
 *          - Do not load                     = 0x3
 *          In any case if these values changes across the above mentioned
 *          registers, then separate macros need to be used.
 *          - Load when counter equals zero macros with value 0x0
 *              - PWMSS_EPWM_CMPCTL_LOADAMODE_CTR_0,
 *              - PWMSS_EPWM_CMPCTL_LOADBMODE_CTR_0,
 *          - Load when counter equals period macros with value 0x1
 *              - PWMSS_EPWM_CMPCTL_LOADAMODE_CTR_PRD
 *              - PWMSS_EPWM_CMPCTL_LOADBMODE_CTR_PRD
 *          - Load when counter equals zero or period macros with value 0x2
 *              - PWMSS_EPWM_CMPCTL_LOADAMODE_CTR_0_OR_PRD
 *              - PWMSS_EPWM_CMPCTL_LOADBMODE_CTR_0_OR_PRD
 *          - Do not load macros with value 0x3
 *              - PWMSS_EPWM_CMPCTL_LOADAMODE_FREEZE
 *              - PWMSS_EPWM_CMPCTL_LOADBMODE_FREEZE
 */
typedef enum epwmCcCmpLoadMode
{
    EPWM_CC_CMP_LOAD_MODE_CNT_EQ_ZERO   = PWMSS_EPWM_CMPCTL_LOADAMODE_CTR_0,
    /**< Load on CTR = 0: Time-base counter equal to zero. */
    EPWM_CC_CMP_LOAD_MODE_CNT_EQ_PRD    = PWMSS_EPWM_CMPCTL_LOADAMODE_CTR_PRD,
    /**< Load on CTR = PRD: Time-base counter equal to period. */
    EPWM_CC_CMP_LOAD_MODE_CNT_EQ_ZERO_OR_PRD    =
        PWMSS_EPWM_CMPCTL_LOADAMODE_CTR_0_OR_PRD,
    /**< Load on either CTR = 0 or CTR = PRD. */
    EPWM_CC_CMP_LOAD_MODE_NO_LOAD       = PWMSS_EPWM_CMPCTL_LOADAMODE_FREEZE
    /**< Freeze (no loads possible). */
}epwmCcCmpLoadMode_t;

/** \brief   Types of Actions that Action Qualifier can take on the Output when
 *           the supported counter compare event occurs.
 *
 *  \details Same actions will be applicable for all the supported events and
 *           same actions are applicable for both A and B channel PWM outputs.
 *
 *  \note    Same macros are used for all the events and for both A and B
 *           because their field values are same.
 *           - Action Do nothing macros with value 0x0
 *              - PWMSS_EPWM_AQCTLx_ZRO_DISABLED
 *              - PWMSS_EPWM_AQCTLx_PRD_DISABLED
 *              - PWMSS_EPWM_AQCTLx_CAU_DISABLED
 *              - PWMSS_EPWM_AQCTLx_CAD_DISABLED
 *              - PWMSS_EPWM_AQCTLx_CBU_DISABLED
 *              - PWMSS_EPWM_AQCTLx_CBD_DISABLED
 *           - Action high macros with value 0x1
 *              - PWMSS_EPWM_AQCTLx_ZRO_CLEAR
 *              - PWMSS_EPWM_AQCTLx_PRD_CLEAR
 *              - PWMSS_EPWM_AQCTLx_CAU_CLEAR
 *              - PWMSS_EPWM_AQCTLx_CAD_CLEAR
 *              - PWMSS_EPWM_AQCTLx_CBU_CLEAR
 *              - PWMSS_EPWM_AQCTLx_CBD_CLEAR
 *           - Action low macros  with value 0x2
 *              - PWMSS_EPWM_AQCTLx_ZRO_SET
 *              - PWMSS_EPWM_AQCTLx_PRD_SET
 *              - PWMSS_EPWM_AQCTLx_CAU_SET
 *              - PWMSS_EPWM_AQCTLx_CAD_SET
 *              - PWMSS_EPWM_AQCTLx_CBU_SET
 *              - PWMSS_EPWM_AQCTLx_CBD_SET
 *           - Action toggle macros  with value 0x3
 *              - PWMSS_EPWM_AQCTLx_ZRO_TOGGLE
 *              - PWMSS_EPWM_AQCTLx_PRD_TOGGLE
 *              - PWMSS_EPWM_AQCTLx_CAU_TOGGLE
 *              - PWMSS_EPWM_AQCTLx_CAD_TOGGLE
 *              - PWMSS_EPWM_AQCTLx_CBU_TOGGLE
 *              - PWMSS_EPWM_AQCTLx_CBD_TOGGLE
 */
typedef enum epwmAqAction
{
    EPWM_AQ_ACTION_DONOTHING  = PWMSS_EPWM_AQCTLA_ZRO_DISABLED,
    /**< Do nothing (Action disabled). */
    EPWM_AQ_ACTION_LOW        = PWMSS_EPWM_AQCTLA_ZRO_CLEAR,
    /**< Clear: Force EPWMx output low. */
    EPWM_AQ_ACTION_HIGH       = PWMSS_EPWM_AQCTLA_ZRO_SET,
    /**< Set: Force EPWMx output high. */
    EPQM_AQ_ACTION_TOLLGE     = PWMSS_EPWM_AQCTLA_ZRO_TOGGLE
    /**< Toggle EPWMx output: low output signal will be forced high,
         and a high signal will be forced low. */
}epwmAqAction_t;

/** \brief Actions to be taken on the output, when Software triggered one time
 *         events will occur.
 *
 *  \details Same macros will be used for both A and B channel outputs because
 *           the bit field values are same.
 *
 *  \note    The following are the similar macros,
 *           - Do nothing macros with value 0x0
 *              - PWMSS_EPWM_AQSFRC_ACTSFA_DISABLED
 *              - PWMSS_EPWM_AQSFRC_ACTSFB_DISABLED
 *           - Action low macros with value 0x1
 *              - PWMSS_EPWM_AQSFRC_ACTSFA_CLEAR
 *              - PWMSS_EPWM_AQSFRC_ACTSFB_CLEAR
 *           - Action high macros with value 0x2
 *              - PWMSS_EPWM_AQSFRC_ACTSFA_SET
 *              - PWMSS_EPWM_AQSFRC_ACTSFB_SET
 *           - Action toggle macros with value 0x3
 *              - PWMSS_EPWM_AQSFRC_ACTSFA_TOGGLE
 *              - PWMSS_EPWM_AQSFRC_ACTSFB_TOGGLE
 */
typedef enum epwmAqSwTrigOtAction
{
    EPWM_AQ_SW_TRIG_OT_ACTION_DONOTHING  = PWMSS_EPWM_AQSFRC_ACTSFA_DISABLED,
    /**< Do nothing (Action disabled). */
    EPWM_AQ_SW_TRIG_OT_ACTION_LOW        = PWMSS_EPWM_AQSFRC_ACTSFA_CLEAR,
    /**< Clear: Output Low. */
    EPWM_AQ_SW_TRIG_OT_ACTION_HIGH       = PWMSS_EPWM_AQSFRC_ACTSFA_SET,
    /**< Set: Output high. */
    EPWM_AQ_SW_TRIG_OT_ACTION_TOGGLE     = PWMSS_EPWM_AQSFRC_ACTSFA_TOGGLE
    /**< Toggle output. */
}epwmAqSwTrigOtAction_t;

/** \brief Types of Continuous software forced actions on output.
 *
 *  \details Same macros will be used for configuration of both A and B PWM
 *           outputs, because bit field values for both A and B are same.
 *
 *  \note    The following are the similar macros,
 *           - Do nothing macros with value 0x0
 *              - PWMSS_EPWM_AQCSFRC_CSFA_DISABLED
 *              - PWMSS_EPWM_AQCSFRC_CSFB_DISABLED
 *           - Action low macros with value 0x1
 *              - PWMSS_EPWM_AQCSFRC_CSFA_LOW_OUTPUT
 *              - PWMSS_EPWM_AQCSFRC_CSFB_LOW_OUTPUT
 *           - Action high macros with value 0x2
 *              - PWMSS_EPWM_AQCSFRC_CSFA_HIGH_OUTPUT
 *              - PWMSS_EPWM_AQCSFRC_CSFB_HIGH_OUTPUT
 *           - Action toggle macros with value 0x3
 *              - PWMSS_EPWM_AQCSFRC_CSFA_NO_EFFECT
 *              - PWMSS_EPWM_AQCSFRC_CSFB_NO_EFFECT
 */
typedef enum epwmAqSwTrigContAction
{
    EPWM_AQ_SW_TRIG_CONT_ACTION_NOEFFECT  = PWMSS_EPWM_AQCSFRC_CSFA_DISABLED,
    /**< Forcing disabled, that is, has no effect. */
    EPWM_AQ_SW_TRIG_CONT_ACTION_LOW       = PWMSS_EPWM_AQCSFRC_CSFA_LOW_OUTPUT,
    /**< Forces a continuous low on output A. */
    EPWM_AQ_SW_TRIG_CONT_ACTION_HIGH      = PWMSS_EPWM_AQCSFRC_CSFA_HIGH_OUTPUT,
    /**< Forces a continuous high on output A. */
    EPWM_AQ_SW_TRIG_CONT_ACTION_SW_DISBALED = PWMSS_EPWM_AQCSFRC_CSFA_NO_EFFECT,
    /**< Software forcing is disabled and has no effect. */
}epwmAqSwTrigContAction_t;

/** \brief Action Qualifier Software Force Active Register Reload From
          Shadow Options. */
typedef enum epwmAqCsfrcRegReload
{
    EPWM_AQ_CSFRC_REG_RELOAD_CNT_EQ_ZRO   = PWMSS_EPWM_AQSFRC_RLDCSF_CTR_0,
    /**< Load on event counter equals zero. */
    EPWM_AQ_CSFRC_REG_RELOAD_CNT_EQ_PRD   = PWMSS_EPWM_AQSFRC_RLDCSF_CTR_PERIOD,
    /**< Load on event counter equals period. */
    EPWM_AQ_CSFRC_REG_RELOAD_CNT_EQ_ZRO_OR_PRD  =
        PWMSS_EPWM_AQSFRC_RLDCSF_CTR_0_OR_PERIOD,
    /**< Load on event counter equals zero or counter equals period. */
    EPWM_AQ_CSFRC_REG_RELOAD_IMMEDIATE    = PWMSS_EPWM_AQSFRC_RLDCSF_IMMEDIATE,
    /**< Load immediately. */
}epwmAqCsfrcRegReload_t;

/** \brief Dead Band Input Mode Control. This allows you to select the
           input source to the falling-edge and rising-edge delay. */
typedef enum epwmDbInMode
{
    EPWM_DB_IN_MODE_A_RED_A_FED = PWMSS_EPWM_DBCTL_IN_MODE_SRC_ARED_AFED,
    /**< EPWMxA In (from the action-qualifier) is the source for both
         falling-edge and rising-edge delay. */
    EPWM_DB_IN_MODE_B_RED_A_FED = PWMSS_EPWM_DBCTL_IN_MODE_SRC_BRED_AFED,
    /**< EPWMxB In (from the action-qualifier) is the source for
         rising-edge delayed signal. EPWMxA In (from the action-qualifier) is
         the source for falling-edge delayed signal. */
    EPWM_DB_IN_MODE_A_RED_B_FED = PWMSS_EPWM_DBCTL_IN_MODE_SRC_ARED_BFED,
    /**< EPWMxA In (from the action-qualifier) is the source for rising-edge
         delayed signal. EPWMxB In (from the action-qualifier) is the source for
         falling-edge delayed signal. */
    EPWM_DB_IN_MODE_B_RED_B_FED = PWMSS_EPWM_DBCTL_IN_MODE_SRC_BRED_BFED
    /**< EPWMxB In (from the action-qualifier) is the source for both
         rising-edge delay and falling-edge delayed signal. */
}epwmDbInMode_t;

/** \brief Polarity Select Control. This allows you to selectively invert one
           of the delayed signals before it is sent out of the dead-band
           sub-module. */
typedef enum epwmDbPolSel
{
    EPWM_DB_POL_SEL_ACTV_HIGH               =
        PWMSS_EPWM_DBCTL_POLSEL_ACTIVE_HIGH,
    /**< Neither EPWMxA nor EPWMxB is inverted (default). */
    EPWM_DB_POL_SEL_ACTV_LOW_COMPLEMENTARY  =
        PWMSS_EPWM_DBCTL_POLSEL_ACTIVE_LOW_COMPLEMENTARY,
    /**< EPWMxA is inverted. */
    EPWM_DB_POL_SEL_ACTV_HIGH_COMPLEMENTARY =
        PWMSS_EPWM_DBCTL_POLSEL_ACTIVE_HIGH_COMPLEMENTARY,
    /**< EPWMxB is inverted. */
    EPWM_DB_POL_SEL_ACTV_LOW                =
        PWMSS_EPWM_DBCTL_POLSEL_ACTIVE_LOW
    /**< Both EPWMxA and EPWMxB are inverted. */
}epwmDbPolSel_t;

/** \brief Dead-band Output Mode Control. This allows you to selectively enable
           or bypass the dead-band generation for the falling-edge and
           rising-edge delay. */
typedef enum epwmDbOutMode
{
    EPWM_DB_OUT_MODE_BYPASS         =
        PWMSS_EPWM_DBCTL_OUT_MODE_DISABLED,
    /**< Dead-band generation is bypassed for both output signals. In this mode,
         both the EPWMxA and EPWMxB output signals from the action-qualifier are
         passed directly to the PWM-chopper sub-module. */
    EPWM_DB_OUT_MODE_NO_RED_B_FED   =
        PWMSS_EPWM_DBCTL_OUT_MODE_DISABLE_RISING_EDGE,
    /**< Disable rising-edge delay. The EPWMxA signal from the action-qualifier
         is passed straight through to the EPWMxA input of the PWM-chopper
         sub-module. The falling-edge delayed signal is seen on output EPWMxB */
    EPWM_DB_OUT_MODE_A_RED_NO_FED   =
        PWMSS_EPWM_DBCTL_OUT_MODE_DISABLE_FALLING_EDGE,
    /**< Disable falling-edge delay. The EPWMxB signal from the action-qualifier
         is passed straight through to the EPWMxB input of the PWM-chopper
         sub-module. The rising-edge delayed signal is seen on output EPWMxA. */
    EPWM_DB_OUT_MODE_A_RED_B_FED    = PWMSS_EPWM_DBCTL_OUT_MODE_ENABLED
    /**< Dead-band is fully enabled for both rising-edge delay on output EPWMxA
         and falling-edge delay on output EPWMxB. */
}epwmDbOutMode_t;

/** \brief Chopping Clock Duty Cycle values. */
typedef enum epwmChpDutyCycle
{
    EPWM_CHP_DUTY_CYCLE_PERC_12PNT5 = PWMSS_EPWM_PCCTL_CHPDUTY_DUTY_12_5,
    /**< Duty cycle 1/8 (12.5%). */
    EPWM_CHP_DUTY_CYCLE_PERC_25     = PWMSS_EPWM_PCCTL_CHPDUTY_DUTY_25,
    /**< Duty cycle 2/8 (25%). */
    EPWM_CHP_DUTY_CYCLE_PERC_37PNT5 = PWMSS_EPWM_PCCTL_CHPDUTY_DUTY_37_5,
    /**< Duty cycle 3/8 (37.5%). */
    EPWM_CHP_DUTY_CYCLE_PERC_50_PER = PWMSS_EPWM_PCCTL_CHPDUTY_DUTY_50,
    /**< Duty cycle 4/8 (50%). */
    EPWM_CHP_DUTY_CYCLE_PERC_62PNT5 = PWMSS_EPWM_PCCTL_CHPDUTY_DUTY_62_5,
    /**< Duty cycle 5/8 (62.5%). */
    EPWM_CHP_DUTY_CYCLE_PERC_75     = PWMSS_EPWM_PCCTL_CHPDUTY_DUTY_75,
    /**< Duty cycle 6/8 (75%). */
    EPWM_CHP_DUTY_CYCLE_PERC_87PNT5 = PWMSS_EPWM_PCCTL_CHPDUTY_DUTY_87_5
    /**< Duty cycle 7/8 (87.5%). */
}epwmChpDutyCycle_t;

/** \brief Chopping Clock Frequency values . */
typedef enum epwmChpClkFreq
{
    EPWM_CHP_CLK_FREQ_DIV_BY_1 = PWMSS_EPWM_PCCTL_CHPFREQ_DIV_1,
    /**< Divide by 1 (no prescale). */
    EPWM_CHP_CLK_FREQ_DIV_BY_2 = PWMSS_EPWM_PCCTL_CHPFREQ_DIV_2,
    /**< Divide by 2. */
    EPWM_CHP_CLK_FREQ_DIV_BY_3 = PWMSS_EPWM_PCCTL_CHPFREQ_DIV_3,
    /**< Divide by 3. */
    EPWM_CHP_CLK_FREQ_DIV_BY_4 = PWMSS_EPWM_PCCTL_CHPFREQ_DIV_4,
    /**< Divide by 4. */
    EPWM_CHP_CLK_FREQ_DIV_BY_5 = PWMSS_EPWM_PCCTL_CHPFREQ_DIV_5,
    /**< Divide by 5. */
    EPWM_CHP_CLK_FREQ_DIV_BY_6 = PWMSS_EPWM_PCCTL_CHPFREQ_DIV_6,
    /**< Divide by 6. */
    EPWM_CHP_CLK_FREQ_DIV_BY_7 = PWMSS_EPWM_PCCTL_CHPFREQ_DIV_7,
    /**< Divide by 7. */
    EPWM_CHP_CLK_FREQ_DIV_BY_8 = PWMSS_EPWM_PCCTL_CHPFREQ_DIV_8,
    /**< Divide by 8. */
}epwmChpClkFreq_t;

/** \brief One-Shot Pulse Width values. */
typedef enum epwmChpOshtWidth
{
    EPWM_CHP_OSHT_WIDTH_MIN = 0U,
    /**< Minimum value of enumeration. Used for input validation. */
    EPWM_CHP_OSHT_WIDTH_1XSYSOUT_BY_8   = EPWM_CHP_OSHT_WIDTH_MIN,
    /**< 1 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_2XSYSOUT_BY_8   = 1U,
    /**< 2 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_3XSYSOUT_BY_8   = 2U,
    /**< 3 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_4XSYSOUT_BY_8   = 3U,
    /**< 4 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_5XSYSOUT_BY_8   = 4U,
    /**< 5 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_6XSYSOUT_BY_8   = 5U,
    /**< 6 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_7XSYSOUT_BY_8   = 6U,
    /**< 7 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_8XSYSOUT_BY_8   = 7U,
    /**< 8 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_9XSYSOUT_BY_8   = 8U,
    /**< 9 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_10XSYSOUT_BY_8  = 9U,
    /**< 10 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_11XSYSOUT_BY_8  = 10U,
    /**< 11 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_12XSYSOUT_BY_8  = 11U,
    /**< 12 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_13XSYSOUT_BY_8  = 12U,
    /**< 13 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_14XSYSOUT_BY_8  = 13U,
    /**< 14 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_15XSYSOUT_BY_8  = 14U,
    /**< 15 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_16XSYSOUT_BY_8  = 15U,
    /**< 16 x SYSCLKOUT/8 wide. */
    EPWM_CHP_OSHT_WIDTH_MAX = EPWM_CHP_OSHT_WIDTH_16XSYSOUT_BY_8
    /**< Maximum value of enumeration. Used for input validation. */
}epwmChpOshtWidth_t;

/** \brief   Action to be taken on PWM output When a trip event occurs.
 *
 *  \details Same macros will be used to control both A and B outputs because
 *           the bit field values are same for A and B channels.
 *
 *  \note    The following are the similar macros
 *           - Tri state action macro with value 0x0
 *              - PWMSS_EPWM_TZCTL_TZA_HIGH_IMPEDANCE
 *              - PWMSS_EPWM_TZCTL_TZB_HIGH_IMPEDANCE
 *           - High action macro  with value 0x1
 *              - PWMSS_EPWM_TZCTL_TZA_HIGH_STATE
 *              - PWMSS_EPWM_TZCTL_TZA_HIGH_STATE
 *           - Low action macro with value 0x2
 *              - PWMSS_EPWM_TZCTL_TZA_LOW_STATE
 *              - PWMSS_EPWM_TZCTL_TZB_LOW_STATE
 *           - Do nothing action macro with value 0x3
 *              - PWMSS_EPWM_TZCTL_TZA_DO_NOTHING
 *              - PWMSS_EPWM_TZCTL_TZB_DO_NOTHING
 */
typedef enum epwmTzTripAction
{
    EPWM_TZ_TRIP_ACTION_TRI_STATE   = PWMSS_EPWM_TZCTL_TZA_HIGH_IMPEDANCE,
    /**< High impedance (EPWMxA = High-impedance state). */
    EPWM_TZ_TRIP_ACTION_HIGH        = PWMSS_EPWM_TZCTL_TZA_HIGH_STATE,
    /**< Force EPWMxA to a high state. */
    EPWM_TZ_TRIP_ACTION_LOW         = PWMSS_EPWM_TZCTL_TZA_LOW_STATE,
    /**< Force EPWMxA to a low state. */
    EPWM_TZ_TRIP_ACTION_DO_NOTHING  = PWMSS_EPWM_TZCTL_TZA_DO_NOTHING
    /**< Do nothing, no action is taken on EPWMxA. */
}epwmTzTripAction_t;

/** \brief Type of trip zone events. */
typedef enum epwmTzEvent
{
    EPWM_TZ_EVENT_MIN = 0x0U,
    /**< Minimum value of enumeration. Used for input validation. */
    EPWM_TZ_EVENT_ONE_SHOT         = EPWM_TZ_EVENT_MIN,
    /**< One shot trip zone event. */
    EPWM_TZ_EVENT_CYCLE_BY_CYCLE   = 0x1U,
    /**< Cycle by cycle trip zone event. */
    EPWM_TZ_EVENT_MAX = EPWM_TZ_EVENT_CYCLE_BY_CYCLE
    /**< Maximum value of enumeration. Used for input validation. */
}epwmTzEvent_t;

/** \brief Trip zone status flags. */
typedef enum epwmTzStsFlg
{
    EPWM_TZ_STS_FLG_OST = PWMSS_EPWM_TZFLG_OST_MASK,
    /**< Latched Status Flag for A One-Shot Trip Event.*/
    EPWM_TZ_STS_FLG_CBC = PWMSS_EPWM_TZFLG_CBC_MASK,
    /**< Latched Status Flag for Cycle-By-Cycle Trip Event.*/
    EPWM_TZ_STS_FLG_INT = PWMSS_EPWM_TZFLG_INT_MASK,
    /**< Latched status for Trip Interrupt .*/
}epwmTzStsFlg_t;

/** \brief ePWM Interrupt (EPWMx_INT) Selection Options. */
typedef enum epwmEtIntrEvt
{
    EPWM_ET_INTR_EVT_CNT_EQ_ZRO       = PWMSS_EPWM_ETSEL_INTSEL_CTR_0,
    /**< Enable event time-base counter equal to zero. (TBCNT = 0000h).*/
    EPWM_ET_INTR_EVT_CNT_EQ_PRD       = PWMSS_EPWM_ETSEL_INTSEL_CTR_PERIOD,
    /**< Enable event time-base counter equal to period (TBCNT = TBPRD).*/
    EPWM_ET_INTR_EVT_CNT_EQ_CMPA_INC  = PWMSS_EPWM_ETSEL_INTSEL_CTR_CMPA_INCR,
    /**< Enable event time-base counter equal to CMPA when the timer is
         incrementing.*/
    EPWM_ET_INTR_EVT_CNT_EQ_CMPA_DEC  = PWMSS_EPWM_ETSEL_INTSEL_CTR_CMPA_DECR,
    /**< Enable event time-base counter equal to CMPA when the timer is
         decrementing.*/
    EPWM_ET_INTR_EVT_CNT_EQ_CMPB_INC  = PWMSS_EPWM_ETSEL_INTSEL_CTR_CMPB_INCR,
    /**< Enable event: time-base counter equal to CMPB when the timer is
         incrementing.*/
    EPWM_ET_INTR_EVT_CNT_EQ_CMPB_DEC  = PWMSS_EPWM_ETSEL_INTSEL_CTR_CMPB_DECR
    /**< Enable event: time-base counter equal to CMPB when the timer is
         decrementing.*/
}epwmEtIntrEvt_t;

/** \brief ePWM Interrupt (EPWMx_INT) Period Select. These values determine how
           many selected events need to occur before an interrupt is
           generated. */
typedef enum epwmEtIntrPeriod
{
    EPWM_ET_INTR_PERIOD_DIS_INTR   = PWMSS_EPWM_ETPS_INTPRD_DISABLE,
    /**< Disable the interrupt event counter. No interrupt will be generated. */
    EPWM_ET_INTR_PERIOD_FIRST_EVT  = PWMSS_EPWM_ETPS_INTPRD_GEN_FIRST_EVT,
    /**< Generate an interrupt on the first event. */
    EPWM_ET_INTR_PERIOD_SECOND_EVT = PWMSS_EPWM_ETPS_INTPRD_GEN_SECOND_EVT,
    /**< Generate an interrupt on the second event. */
    EPWM_ET_INTR_PERIOD_THIRD_EVT  = PWMSS_EPWM_ETPS_INTPRD_GEN_THIRD_EVT
    /**< Generate an interrupt on the third event. */
}epwmEtIntrPeriod_t;

/** \brief Delay Bus Selection, that selects which bus is used to select the
           delay for the PWM pulse. */
typedef enum epwmHrDelayBusSel
{
    EPWM_HR_DELAY_BUS_SEL_CMPAHR   = PWMSS_EPWM_HRCTL_DELBUSSEL_SEL_CMPAHR,
    /**< Select CMPAHR(8) bus from compare module of EPWM (default on reset). */
    EPWM_HR_DELAY_BUS_SEL_TBPHSHR  = PWMSS_EPWM_HRCTL_DELBUSSEL_SEL_TBPHSHR
    /**< Select TBPHSHR(8) bus from time base module. */
}epwmHrDelayBusSelMode_t;

/** \brief Delay Mode Configuration, that selects which edge of the PWM pulse
           the delay is inserted. */
typedef enum epwmHrDelayEdgeCtrl
{
    EPWM_HR_DELAY_EDGE_CTRL_NO_DELAY = PWMSS_EPWM_HRCTL_DELMODE_NO_DELAY,
    /**< No delay inserted (default on reset). */
    EPWM_HR_DELAY_EDGE_CTRL_RISING   =
        PWMSS_EPWM_HRCTL_DELMODE_DELAY_RISING_EDGE,
    /**< Delay inserted rising edge. */
    EPWM_HR_DELAY_EDGE_CTRL_FALLING  =
        PWMSS_EPWM_HRCTL_DELMODE_DELAY_FALLING_EDGE,
    /**< Delay inserted falling edge. */
    EPWM_HR_DELAY_EDGE_CTRL_BOTH     =
        PWMSS_EPWM_HRCTL_DELMODE_DELAY_ON_BOTH_EDGES
    /**< Delay inserted on both edges. */
}epwmHrDelayEdgeCtrl_t;

/** \brief Pulse selection, that selects which pulse to use for timing events
           in the HRPWM module. */
typedef enum epwmHrRegActLoad
{
    EPWM_HR_REG_ACT_LOAD_CNT_ZRO_PULSE  =
        PWMSS_EPWM_HRCTL_PULSESEL_SEL_CNT_ZERO_PULSE,
    /**< Select CNT_zero pulse. */
    EPWM_HR_REG_ACT_LOAD_PRD_EQ_PULSE   =
        PWMSS_EPWM_HRCTL_PULSESEL_SEL_PRD_EQ_PULSE
    /**< Select CNT_zero pulse. */
}epwmHrRegActLoad_t;


/** \brief Structure holding the TimeBase sub-module configuration parameters */
typedef struct epwmTimebaseCfg
{
    uint32_t tbClk;
    /**< Time base clock. */
    uint32_t pwmtbCounterFreqPrd;
    /**< PWM Time base counter Frequency/Period. */
    uint32_t tbCntrDirection;
    /**< Time base counter direction. This can take values from the following
         enum #epwmTbCounterDir_t. */
    uint32_t enableSynchronization;
    /**< Enable synchronization inside the timebase sub-module.  This can take
         following two values TRUE or FALSE. */
    uint32_t cntDirAfterSync;
    /**< Direction of the counter after the sync event is occurred.  This can
         take values from the following enum #epwmTbCntDirAftSync_t. */
    uint32_t phsCountAfterSync;
    /**< Value of the phase counter to be loaded after the sync event. */
    uint32_t syncOutSrc;
    /**< Source of synchronization output signal.  This can take values from the
         following enum #epwmTbSyncOutEvt_t. */
}epwmTimebaseCfg_t;

/** \brief Structure holding the Counter Comparator values. */
typedef struct epwmCounterCmpCfg
{
    uint32_t cmpAValue;
    /**< Counter Comparator A load value. */
    uint32_t cmpBValue;
    /**< Counter Comparator B load value. */
}epwmCounterCmpCfg_t;

/** \brief Structure holding the Action Qualifier actions to be taken on the PWM
           output at the specific events. */
typedef struct epwmAqActionCfg
{
    uint32_t zeroAction;
    /**< Action to be taken when counter equals zero. This can take values from
         the following enum #epwmAqAction_t. */
    uint32_t prdAction;
    /**< Action to be taken when the counter equals the period. This can take
         values from the following enum #epwmAqAction_t. */
    uint32_t cmpAUpAction;
    /**< Action to be taken when the counter equals the active CMPA register
         and the counter is incrementing.  This can take values from the
         following enum #epwmAqAction_t. */
    uint32_t cmpADownAction;
    /**< Action to be taken when the counter equals the active CMPA register
         and the counter is decrementing. This can take values from the
         following enum #epwmAqAction_t. */
    uint32_t cmpBUpAction;
    /**< Action to be taken when the counter equals the active CMPB register
         and the counter is incrementing. This can take values from the
         following enum #epwmAqAction_t. */
    uint32_t cmpBDownAction;
    /**< Action to be taken when the time-base counter equals the active CMPB
         register and the counter is decrementing. This can take values from the
         following enum #epwmAqAction_t. */
}epwmAqActionCfg_t;

/** \brief Structure holding the dead band generation sub-module configuration
           parameters. */
typedef struct epwmDeadbandCfg
{
    uint32_t inputMode;
    /**< Input mode control that selects the input source to the falling-edge
         and rising-edge delay. This can take values from the following
         enum #epwmDbInMode_t. */
    uint32_t outputMode;
    /**< Output mode control that selectively enable or bypass the dead-band
         generation for the falling-edge and rising-edge delay. This can take
         values from the following enum #epwmDbOutMode_t. */
    uint32_t polaritySelect;
    /**< Polarity selection control that allows selectively invert one of the
         delayed signals before it is sent out of the dead-band sub-module. This
         can take values from the following enum #epwmDbPolSel_t. */
    uint32_t risingEdgeDelay;
    /**< Rising edge delay count in cycles. */
    uint32_t fallingEdgeDelay;
    /**< Falling edge delay count in cycles. */
}epwmDeadbandCfg_t;

/** \brief Structure holding the configuration parameters of Chopper
           sub-module. */
typedef struct epwmChopperCfg
{
    uint32_t dutyCycle;
    /**< Chopping clock duty cycle. This can take values from the following
         enum #epwmChpDutyCycle_t. */
    uint32_t clkFrequency;
    /**< Chopping clock frequency. This can take values from the following
         enum #epwmChpClkFreq_t. */
    uint32_t oneShotPulseWidth;
    /**< One shot pulse width: pulse width of first pulse. This can take values
         from the following enum #epwmChpOshtWidth_t. */
}epwmChopperCfg_t;

/** \brief Structure holding the trip-zone sub-module configuration
           parameters. */
typedef struct epwmTripzoneCfg
{
    uint32_t tripAction;
    /**< Action to be taken on Output when trip condition occurs. This can take
         values from the following enum #epwmTzTripAction_t. */
    uint32_t tripEvtType;
    /**< Type of trip event One Shot or Cycle by cycle. This can take values
         from the following enum #epwmTzEvent_t. */
    uint32_t tripPin;
    /**< Trip Pin number on which trip condition has to be monitored. */
    uint32_t enableTripIntr;
    /**< Enable Trip Zone Interrupt. */
}epwmTripzoneCfg_t;

/** \brief Structure holding the Event Trigger Sub-Module configuration
           parameters. */
typedef struct epwmEtCfg
{
    uint32_t intrEvtSource;
    /**< Event which is the source of the interrupt. This can take values from
         the following enum #epwmEtIntrEvt_t. */
    uint32_t intrPrd;
    /**< Interrupt period which determine how many selected events need to occur
         before an interrupt is generated. This can take values from the
         following enum #epwmEtIntrPeriod_t. */
}epwmEtCfg_t;

/** \brief Structure holding the configuration parameters of high resolution
           pwm pulse generation sub module. */
typedef struct epwmHighResolutionCfg
{
    uint32_t pulseSelect;
    /**< Pulse selection bits that selects which pulse to use for timing events
         in the HRPWM module. */
    uint32_t delayBusSelect;
    /**< Delay Bus Selection that selects which bus is used to select the delay
         for the PWM pulse.  This can take values from the following
         enum #epwmHrDelayBusSelMode_t. */
    uint32_t delayMode;
    /**< Delay Mode that selects which edge of the PWM pulse the delay is
         inserted.  This can take values from the following
         enum #epwmHrDelayEdgeCtrl_t. */
    uint32_t tbPhaseHighResVal;
    /**< Time base phase high resolution value. */
    uint32_t cmpAHighResVal;
    /**< Counter comparator A high-resolution bits for MEP step control. A min
         value of 1h is needed to enable HRPWM capabilities. Valid MEP range of
         operation 1-255h. */
}epwmHighResolutionCfg_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API configures the clock divider of the Time base module.
 *
 * \details The clock divider can be calculated using the equation
 *          TBCLK = SYSCLKOUT/(HSPCLKDIV × CLKDIV)
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 * \param   tbClk         Timebase clock to be generated in Hz.
 * \param   moduleClk     Input clock of the PWM module (sysclk2) in Hz.
 */
void EPWMTbTimebaseClkCfg(uint32_t baseAddr,
                          uint32_t tbClk,
                          uint32_t moduleClk);

/**
 * \brief   This API configures the PWM Time base counter Frequency/Period.
 *
 * \details The period count determines the period of the final output waveform.
 *
 * \param   baseAddr     Base Address of PWMSS instance used.
 * \param   tbClk        Timebase clock in Hz.
 * \param   pwmFreq      Frequency of the PWM Output in Hz.
 * \param   counterDir   Direction of the counter(up, down, up-down).
 *          'counterDir' can take values from the following enum
 *          - #epwmTbCounterDir_t.
 * \param   enableShadowWrite   Flag controlling Whether write to Period
 *                              register is to be shadowed or not.
 *          'enableShadowWrite' can take values from the following enum
 *          - #epwmShadowRegCtrl_t.
 *
 * \note     If the counter direction is configured as
 *           #EPWM_TB_COUNTER_DIR_UP_DOWN, then output frequency will be
 *           half the value of required pwm frequency.
 */
void EPWMTbPwmFreqCfg(uint32_t baseAddr,
                      uint32_t tbClk,
                      uint32_t pwmFreq,
                      uint32_t counterDir,
                      uint32_t enableShadowWrite);

/**
 * \brief   This API enables the synchronization of time base sub-module and
 *          also configures the phase count value to be loaded after sync event,
 *          counter direction after sync event.
 *
 * \details When a sync-in event is generated the the time base counter is
 *          reloaded with the new value. After sync the counter will use the new
 *          value and direction as specified after sync event.
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 * \param   tbPhsValue    Phase value to be reloaded after sync
 * \param   counterDir   Count direction after sync.
 *          'counterDir' can take values from the following enum
 *          - #epwmTbCntDirAftSync_t.
 */
void EPWMTbSyncEnable(uint32_t baseAddr,
                      uint32_t tbPhsValue,
                      uint32_t counterDir);

/**
 * \brief   This API disables the synchronization. Even if sync-in event occurs
 *          the count value will not be reloaded.
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 */
void EPWMTbSyncDisable(uint32_t baseAddr);

/**
 * \brief   This API selects the source of the synchronization output signal.
 *          It determines on which of the supported events sync-out has to be
 *          generated.
 *
 * \param   baseAddr        Base Address of PWMSS instance used.
 * \param   syncOutMode     Sync out mode.
 *          'syncOutMode' can take values from the following enum
 *          - #epwmTbSyncOutEvt_t.
 */
void EPWMTbSetSyncOutMode(uint32_t baseAddr, uint32_t syncOutMode);

/**
 * \brief   This API generates software triggered sync pulse.
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 *
 * \note    This API can be used for testing. When this API is called sync-in
 *          event will be generated.
 */
void EPWMTbTriggerSwSync(uint32_t baseAddr);

/**
 * \brief   This API loads the Time base counter. The new value is taken
 *          immediately.
 *
 * \param   baseAddr     Base Address of PWMSS instance used.
 * \param   tbCount      Time base count value to be loaded.
 */
void EPWMTbWriteTbCount(uint32_t baseAddr, uint32_t tbCount);

/**
 * \brief   This API gets the Time base counter current value. The count
 *          operation is not affected by the read.
 *
 * \param   baseAddr     Base Address of PWMSS instance used.
 *
 * \retval  tbCount      Current Timebase count value.
 */
uint16_t EPWMTbReadTbCount(uint32_t baseAddr);

/**
 * \brief   This API gets the Time Base status as indicated by the tbStatusMask
 *          parameter.
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 * \param   tbStatusMask  Flag indicating the type of status needed.
 *          'tbStatusMask' can take values from the following enum
 *          - #epwmTbSts_t.
 *
 * \retval  tbStatus      Requested status is returned.
 *
 * \note    The returned status will depend on the status mask passed.
 *          - For #EPWM_TB_STS_CTR_MAX
 *            -# Zero indicates the time-base counter never reached its max
 *               value.
 *            -# NonZero indicates that the time-base counter reached max
 *               value 0xFFFF
 *          - For #EPWM_TB_STS_SYNCI
 *            -# Zero indicates that no external synchronization event has
 *               occurred.
 *            -# NonZero indicates that an external synchronization event has
 *               occurred.
 *          - For #EPWM_TB_STS_CTR_DIR
 *            -# Zero indicates that Time-Base Counter is currently
 *               counting down.
 *            -# NonZero indicates that Time-Base Counter is currently
 *               counting up.
 */
uint16_t EPWMTbGetStatus(uint32_t baseAddr, uint32_t tbStatusMask);

/**
 * \brief   This API clears the Time base status bits indicated by the
 *          tbStatusClrMask parameter.
 *
 * \param   baseAddr         Base Address of PWMSS instance used.
 * \param   tbStatusClrMask  Mask indicating which status bit need to be cleared
 *          'tbStatusClrMask' can take following values
 *          - #EPWM_TB_STS_CTR_MAX
 *          - #EPWM_TB_STS_SYNCI
 */
void EPWMTbStatusClear(uint32_t baseAddr, uint32_t tbStatusClrMask);

/**
 * \brief  This API configures emulation mode. This setting determines
 *         the behaviour of Timebase counter during emulation (debugging).
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 * \param   mode          Emulation mode.
 *          'mode' can take values from the following enum
 *          - #epwmTbEmuMode_t.
 */
void EPWMTbSetEmulationMode(uint32_t baseAddr, uint32_t mode);

/**
 * \brief   This API configures the counter comparator and loads the comparator
 *          value. When Counter comparator value equals the counter value,
 *          then an event is generated both in the up direction and down
 *          direction.
 *
 * \param   baseAddr                  Base Address of PWMSS instance used.
 * \param   cmpType                   Comparator Type A or B.
 *          'cmpType' can take values from the following enum
 *          - #epwmCcCmp_t.
 * \param   cmpVal                    Comparator value that needs to be loaded.
 * \param   enableShadowWrite         Enable write to shadow register.
 *          'enableShadowWrite' can take values from the following enum
 *          - #epwmShadowRegCtrl_t.
 * \param   shadowToActiveLoadTrigger  Shadow to active register load mode.
 *          'shadowToActiveLoadTrigger' can take values from the following enum
 *          - #epwmCcCmpLoadMode_t.
 * \param   overwriteShadow            Overwrite even if previous value is not
 *                                     loaded to active register.
 *          'overwriteShadow' can take following values
 *          - TRUE
 *          - FALSE
 *
 * \retval  TRUE    Comparator value is written successfully.
 * \retval  FALSE   Comparator value write is failed.
 */
uint32_t EPWMCounterComparatorCfg(uint32_t baseAddr,
                                  uint32_t cmpType,
                                  uint32_t cmpVal,
                                  uint32_t enableShadowWrite,
                                  uint32_t shadowToActiveLoadTrigger,
                                  uint32_t overwriteShadow);

/**
 * \brief  This API configures the action to be taken on output by the Action
 *         qualifier module upon receiving the events. This will determine
 *         the output waveform.
 *
 * \param  baseAddr     Base Address of PWMSS instance used.
 * \param  pwmOutputCh  PWM Output channel type either A or B
 *         'pwmOutputCh' can take values from the following enum
 *         - #epwmOutputCh_t.
 *
 * \param  pCfg         Pointer to the following structure which contains the
 *                      action configuration variables for different events
 *                      - #epwmAqActionCfg_t.
 *
 * \note   Each event can be configured to one of the following enum values.
 *         - #epwmAqAction_t.
 */
void EPWMAqActionOnOutputCfg(uint32_t baseAddr,
                             uint32_t pwmOutputCh,
                             epwmAqActionCfg_t *pCfg);

/**
 * \brief   This API triggers the SW forced single event on the PWM output.
 *
 * \details This can be used for testing the AQ sub-module. Every call to this
 *          API will trigger a single event.
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 * \param   pwmOutputCh   PWM Output channel type either A or B
 *          'pwmOutputCh' can take values from the following enum
 *          - #epwmOutputCh_t.
 * \param   swTrigAction  Action that needs to be taken on the PWM output.
 *          'swTrigAction' can take one of the following enum values
 *          - #epwmAqSwTrigOtAction_t.
 */
void EPWMAqSwTriggerOneTimeAction(uint32_t baseAddr,
                                  uint32_t pwmOutputCh,
                                  uint32_t swTrigAction);

/**
 * \brief   This API forces output value continuously on PWM output channel.
 *          The output can be forced to low or high.
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 * \param   pwmOutputCh   PWM Output channel type either A or B
 *          'pwmOutputCh' can take values from the following enum
 *          - #epwmOutputCh_t.
 * \param   swTrigAction             Value to be forced on the output
 *          This parameter can take values from the following enum
 *          - #epwmAqSwTrigContAction_t
 * \param   activeRegReloadMode  Shadow to active reg load trigger.
 *          This parameter can take values from the following enum
 *          - #epwmAqCsfrcRegReload_t
 */
void EPWMAqSwTriggerContAction(uint32_t baseAddr,
                               uint32_t pwmOutputCh,
                               uint32_t swTrigAction,
                               uint32_t activeRegReloadMode);

/**
 * \brief   This API performs the configuration of the dead band sub-module.
 *          This API configures the input source, output mode, polarity, rising
 *          and falling edge delays.
 *
 * \details The Dead band generator has two sub-modules, one for raising edge
 *          delay and the other for falling edge delay. This can be configured
 *          when a delay is need between two signals during signal change.
 *          The dead band generator is useful in full-inverters.
 *
 * \param   baseAddr  Base Address of PWMSS instance used.
 * \param   pCfg      Pointer to the structure #epwmDeadbandCfg_t containing
 *                    the dead band configuration parameters.
 */
void EPWMDeadbandCfg(uint32_t baseAddr, epwmDeadbandCfg_t *pCfg);

/**
 * \brief   This API bypasses the Dead-band sub-module.
 *
 * \param   baseAddr Base Address of PWMSS instance used.
 */
void EPWMDeadbandBypass(uint32_t baseAddr);

/**
 * \brief   This API performs the configuration of the chopper sub-module.
 *          This API configures chopping clock duty cycle, chopping clock
 *          frequency and pulse width of first pulse of chopping clock.
 *
 * \param   baseAddr  Base Address of PWMSS instance used.
 * \param   pCfg      Pointer to the structure #epwmChopperCfg_t containing
 *                    the chopper configuration parameters.
 */
void EPWMChopperCfg(uint32_t baseAddr, epwmChopperCfg_t *pCfg);

/**
 * \brief   This API controls the enabling or disabling of chopper sub-module.
 *
 * \param   baseAddr        Base Address of PWMSS instance used.
 * \param   enableChopper   Flag controlling the enabling or disabling
 *          'enableChopper' can take one of the following values
 *          - TRUE  - Enable chopper
 *          - FALSE - Disable chopper
 */
void EPWMChopperEnable(uint32_t baseAddr, uint32_t enableChopper);

/**
 * \brief   This API configures the o/p on PWM channel when a trip event is
 *          recognized. The output can be set to high or low or high impedance.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   tripAction  Action to be taken on the PWM output.
 *          This parameter can take values from the following enum
 *          - #epwmTzTripAction_t.
 * \param   pwmOutputCh   PWM Output channel type either A or B
 *          'pwmOutputCh' can take values from the following enum
 *          - #epwmOutputCh_t.
 */
void EPWMTzTriggerTripAction(uint32_t baseAddr,
                             uint32_t tripAction,
                             uint32_t pwmOutputCh);

/**
 * \brief   This API enables the trip event.
 *
 * \details The trip signals indicates external fault, and the ePWM outputs can
 *          be programmed to respond accordingly when faults occur.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   tzEventType Enable OST or CBC trip zone event
 *          This parameter can take values from the following enum
 *          - #epwmTzEvent_t.
 * \param   pinNum      Pin number on which trip zone event has to be enabled.
 */
void EPWMTzTripEventEnable(uint32_t baseAddr,
                           uint32_t tzEventType,
                           uint32_t pinNum);

/**
 * \brief   This API disable the trip event. The disabled trip events will be
 *          ignored.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   tzEventType Disable OST or CBC trip zone event
 *          This parameter can take values from the following enum
 *          - #epwmTzEvent_t.
 * \param   pinNum      Pin number on which trip zone event has to be disabled.
 */
void EPWMTzTripEventDisable(uint32_t baseAddr,
                              uint32_t tzEventType,
                              uint32_t pinNum);

/**
 * \brief   This API enables the trip interrupt. When trip event occurs
 *          the sub-module can be configured to interrupt CPU.
 *
 * \param   baseAddr   Base Address of PWMSS instance used.
 * \param   tzEventType  Trip zone event for which interrupt has to be enabled.
 *          This parameter can take values form the following enum
 *          - #epwmTzEvent_t.
 */
void EPWMTzIntrEnable(uint32_t baseAddr, uint32_t tzEventType);

/**
 * \brief   This API disables the trip interrupt.
 *
 * \param   baseAddr     Base Address of PWMSS instance used.
 * \param   tzEventType  Trip zone event for which interrupt has to be enabled.
 *          This parameter can take values form the following enum
 *          - #epwmTzEvent_t.
 */
void EPWMTzIntrDisable(uint32_t baseAddr, uint32_t tzEventType);

/**
 * \brief   This API returns the selected trip zone event status.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   eventMask   Type of status which has to be read.
 *          This parameter can take values from the following enum
 *          - #epwmTzStsFlg_t.
 *
 * \retval  Status  Status of the required status flag.
 *
 * \note    The return status depends on the type of status flag passed.
 *          -# For #EPWM_TZ_STS_FLG_OST
 *             -# Zero    - No one-shot trip event has occurred.
 *             -# NonZero - Indicates a trip event has occurred on a pin
 *                          selected as a one-shot trip source.
 *          -# For #EPWM_TZ_STS_FLG_CBC
 *             -# Zero    - No cycle-by-cycle trip event has occurred.
 *             -# NonZero - Indicates a trip event has occurred on a pin
 *                          selected as a cycle-by-cycle trip source.
 *          -# For #EPWM_TZ_STS_FLG_INT
 *             -# Zero    - Indicates no interrupt has been generated.
 *             -# NonZero - Indicates an EPWMxTZINT interrupt was generated
 *                          because of a trip condition.
 */
uint16_t EPWMTzEventStatus(uint32_t baseAddr, uint32_t eventMask);

/**
 * \brief   This API clears the selected trip zone event status.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   eventMask   Type of status which has to be read.
 *          This parameter can take values from the following enum
 *          - #epwmTzStsFlg_t.
 */
void EPWMTzEventStatusClear(uint32_t baseAddr, uint32_t eventMask);

/**
 * \brief   This API enables to generate Software forced trip condition.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   tzEventType Type of trip condition which has to be generated.
 *          This parameter can take values from the following enum
 *          - #epwmTzEvent_t.
 */
void EPWMTzTriggerSwEvent(uint32_t baseAddr, uint32_t tzEventType);

/**
 * \brief   This API configures the Event Trigger sub-module. This API
 *          configures the interrupt source and interrupt period.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   intrEvtSrc  Event source which triggers interrupt.
 *          This parameter can take values from the following enum
 *          - #epwmEtIntrEvt_t.
 * \param   intrPrd     prescalar value(This determines how may selected events
 *                      need to occur before an interrupt is generated).
 *          This parameter can take values from the following enum
 *          - #epwmEtIntrPeriod_t.
 */
void EPWMEtIntrCfg(uint32_t baseAddr, uint32_t intrEvtSrc, uint32_t intrPrd);

/**
 * \brief   This API enables the ePWM Event interrupt.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 */
void EPWMEtIntrEnable(uint32_t baseAddr);

/**
 * \brief   This API disables the ePWM Event interrupt.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 */
void EPWMEtIntrDisable(uint32_t baseAddr);

/**
 * \brief   This API returns the ePWM event interrupt status.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 *
 * \retval  0      Interrupt is not generated.
 * \retval  1      Interrupt is generated.
 */
uint16_t EPWMEtIntrStatus(uint32_t baseAddr);

/**
 * \brief   This API clears the interrupt. This will clear the interrupt flag
 *          bit and enable further interrupts pulses to be generated.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 */
void EPWMEtIntrClear(uint32_t baseAddr);

/**
 * \brief   This API forces interrupt to be generated. This API is used for
 *          testing purpose.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 */
void EPWMEtIntrTrigger(uint32_t baseAddr);

/**
 * \brief   This API returns the number of events occurred.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 *
 * \retval  eventCount  number of events occurred. This will have values in the
 *                      range 0 to 3.
 */
uint16_t EPWMEtGetEventCount(uint32_t baseAddr);

/**
 * \brief   This API configures control mode and edge mode of high resolution
 *          sub-module. In also enables the HR sub-module.
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 * \param   ctrlMode      phase control or duty control.
 *          This parameter can take values from the following enum
 *          - #epwmHrDelayBusSelMode_t.
 * \param   mepCtrlEdge   Edge on which MEP to be applied.(rising,falling,both)
 *          This parameter can take values from the following enum
 *          - #epwmHrDelayEdgeCtrl_t.
 *
 * \note    High-resolution feature is supported only on PWM-A channel output.
 */
void EPWMHighResolutionCfg(uint32_t baseAddr,
                           uint32_t ctrlMode,
                           uint32_t mepCtrlEdge);

/**
 * \brief   This API loads the Timebase Phase high resolution register value.
 *
 * \param   baseAddr         Base Address of PWMSS instance used.
 * \param   tbPhsHighResVal  Time-base phase high resolution value.
 */
void EPWMHrLoadTbPhaseHrValue(uint32_t baseAddr, uint32_t tbPhsHighResVal);

/**
 * \brief   This API loads Counter-Comparator A high resolution value and also
 *          configure the pulse select bits, that select which pulse to use for
 *          timing events in the HRPWM module.
 *
 * \param   baseAddr                  Base Address of PWMSS instance used.
 * \param   compAHighResVal           Counter-comparator A high resolution value
 * \param   ShadowToActiveLoadTrigger Condition when the active reg to be loaded.
 *          This parameter can take values from the following enum
 *          - #epwmHrRegActLoad_t;
 */
void EPWMHrLoadCmpAHrValue(uint32_t baseAddr,
                           uint32_t compAHighResVal,
                           uint32_t ShadowToActiveLoadTrigger);

/**
 * \brief   This API disables the high-resolution feature of ePWM.
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 */
void EPWMHighResolutionDisable(uint32_t baseAddr);


/**
 * \brief   This functions enables clock for EPWM module in PWM subsystem.
 *
 * \param   baseAddr   Base Address of PWMSS instance used.
 *
 * \note    This API enables the clock for the EPWM module which is present
 *          inside the PWM subsystem. The clocks for the PWM Sub system will be
 *          enabled inside the PRCM module.
 */
void EPWMClockEnable(uint32_t baseAddr);

/**
 * \brief   This functions disables clock for EPWM sub-module in the
 *          PWM subsystem.
 *
 * \param   baseAddr   Base Address of PWMSS instance used.
 *
 * \note    This API disables the clock for the EPWM module which is present
 *          inside the PWM subsystem. The clocks for the PWM Sub system will be
 *          disabled inside the PRCM module.
 */
void EPWMClockDisable(uint32_t baseAddr);

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This functions determines whether EPWM clock is enabled or not.
 */
DEPRECATED(uint32_t EPWMClockEnableStatusGet(uint32_t baseAddr));

/**
 * \brief   This functions determines whether clock is disabled or not.
 */
DEPRECATED(uint32_t EPWMClockDisableStatusGet(uint32_t baseAddr));

#ifdef __cplusplus
}
#endif

#endif  /* #ifndef EPWM_H_ */
