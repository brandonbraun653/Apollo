/**
 *  \file       ecap.h
 *
 *  \brief      This file contains declarations of device abstraction layer APIs
 *              corresponding to the eCAP module. This also contains necessary
 *              structure, enum and macro definitions.
 *
 *  \details    Programming Sequence of ECAP is as follows:
 *              -# Enable module clocks for PWMSS through PRCMModuleEnable API.
 *              -# Enable clocks for ECAP module in the PWM subsystem through
 *                 the API #ECAPClkEnable
 *              -# Configure the Pinmux functionality through
 *                 PINMUXModuleConfig API.
 *              -# The eCAP module can be configured in Capture or APWM
 *                 operational modes.
 *               -# Capture Mode
 *                -# Configure the ECAP to operate in Capture mode through the
 *                   API #ECAPSetOperMode
 *                -# Set the Capture mode to either one-shot or continuous
 *                   through the API #ECAPSetCaptureMode
 *                -# Enable the capture event feature for the input signal
 *                   through the API #ECAPCaptureLoadEnable
 *                -# Set the Time-Stamp counter base through the API
 *                   #ECAPSetCounterTimeBase
 *                -# Set the Capture Event polarity through the API
 *                   #ECAPSetCaptEvtPol
 *                -# Enable the input event pre scaling feature through the API
 *                   #ECAPSetEvtPrescale
 *                -# Configure the Capture Event interrupts through the APIs
 *                   #ECAPIntrEnable #ECAPIntrDisable #ECAPIntrStatus and
 *                   #ECAPIntrClear
 *                -# Start the time base counter for capture through the API
 *                   #ECAPTimeStampCounterEnable
 *                -# Captured event time stamp can be read through the API
 *                   #ECAPGetTimeStamp
 *               -# Auxiliary PWM mode
 *                -# Configure the ECAP to operate in APWM mode through the
 *                   API #ECAPSetOperMode
 *                -# Set the time base counter through the API
 *                   #ECAPSetCounterTimeBase
 *                -# Configure the Compare and Period Values to generate the PWM
 *                   wave through the API #ECAPApwmOutputConfig
 *                -# Set the APWM output wave polarity through the API
 *                   #ECAPSetApwmOutputPol
 *                -# Configure the required interrupts through the following
 *                   APIs #ECAPIntrEnable #ECAPIntrDisable #ECAPIntrStatus and
 *                   #ECAPIntrClear
 *                -# Start the time base counter for generating PWM output
 *                   through the API #ECAPTimeStampCounterEnable
 */

/**
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

#ifndef ECAP_H_
#define ECAP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "misc.h"
#include "hw_pwmss_submodule_offsets.h"
#include "hw_pwmss.h"
#include "hw_pwmss_ecap.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*              API compatibility with Starterware 2.0                        */
/* ========================================================================== */
#define ECAPPrescaleConfig               ECAPSetEvtPrescale
#define ECAPTimeStampRead                ECAPGetTimeStamp
#define ECAPCounterConfig                ECAPSetCounterTimeBase
#define ECAPOneShotREARM                 ECAPSetOneShotReArmingMode
#define ECAPAPWMCaptureConfig            ECAPApwmOutputConfig
#define ECAPAPWMShadowCaptureConfig      ECAPApwmShadowModeConfig
#define ECAPCounterPhaseValConfig        ECAPSetCounterPhaseVal
#define ECAPPeripheralIdGet              ECAPGetRevision
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the operating modes of the ECAP module. */
typedef enum ecapOperMode
{
    ECAP_OPER_MODE_CAPTURE = PWMSS_ECAP_ECCTL2_CAP_APWM_CAPTURE_MODE,
    /**< Capture mode of the ECAP module. */
    ECAP_OPER_MODE_APWM = PWMSS_ECAP_ECCTL2_CAP_APWM_MODE,
    /**< Auxiliary PWM mode of the ECAP module. */
}ecapOperMode_t;

/** \brief Enumerates the different Capture modes of ECAP. */
typedef enum ecapCaptMode
{
    ECAP_CAPT_MODE_ONESHOT = PWMSS_ECAP_ECCTL2_CONT_ONESHT_ONESHOT,
    /**< One shot mode of operation in Capture Mode */
    ECAP_CAPT_MODE_CONTINUOUS = PWMSS_ECAP_ECCTL2_CONT_ONESHT_CONTINUOUS,
    /**< Continuous mode of operation in Capture Mode. */
}ecapCaptMode_t;

/** \brief Enumerates the different capture events of the ECAP module. */
typedef enum ecapCaptEvt
{
    ECAP_CAPT_EVT_MIN = 1U,
    /**< Minimum value of the ECAP capture events. */
    ECAP_CAPT_EVT_1 = ECAP_CAPT_EVT_MIN,
    /**< ECAP capture event 1. */
    ECAP_CAPT_EVT_2,
    /**< ECAP capture event 2. */
    ECAP_CAPT_EVT_3,
    /**< ECAP capture event 3. */
    ECAP_CAPT_EVT_4,
    /**< ECAP capture event 4. */
    ECAP_CAPT_EVT_MAX = ECAP_CAPT_EVT_4
    /**< Maximum value of the ECAP capture events. */
}ecapCaptEvt_t;

/** \brief Enumerates the polarities of the capture event signal.
 *
 *  \details The macros are assigned with bit field values representing
 *           Rising Edge and Falling edge for Capture Event1 Polarity.
 *
 *  \note   Same macros are used for controlling the polarities of all the
 *          four capture events as the bit field values representing the Rising
 *          and Falling edge are the same
 *          - Rising edge  = 0x0
 *          - Falling edge = 0x1
 */
typedef enum ecapCaptEvtPol
{
    ECAP_CAPT_EVT_POL_RISING_EDGE = PWMSS_ECAP_ECCTL1_CAP1POL_RE,
    /**< Capture Event on Rising Edge of the input signal. */
    ECAP_CAPT_EVT_POL_FALLING_EDGE = PWMSS_ECAP_ECCTL1_CAP1POL_FE
    /**< Capture Event on Falling Edge of the input signal. */
}ecapCaptEvtPol_t;

/** \brief Enumerates the Counter configuration on a Capture Event.
 *
 *  \details The macros are assigned with bit field values representing
 *           Counter Reset and No Reset on Capture Event1.
 *
 *  \note   Same macros are used for controlling the counter behaviour on all
 *          the four capture events as the bit field values representing them
 *          are the same
 *          - No Reset  = 0x0
 *          - Counter Reset = 0x1
 */
typedef enum ecapCaptEvtCounterCfg
{
    ECAP_CAPT_EVT_COUNTER_CFG_RESET = PWMSS_ECAP_ECCTL1_CTRRST1_RESET,
    /**< Counter to Reset after a Capture Event. */
    ECAP_CAPT_EVT_COUNTER_CFG_NO_RESET = PWMSS_ECAP_ECCTL1_CTRRST1_NO_RESET
    /**< Macro to denote counter does not Reset after a Capture Event. */
}ecapCaptEvtCounterCfg_t;

/** \brief    Enumerates the different Interrupt Mask of ECAP. */
typedef enum ecapIntrMask
{
    ECAP_INTR_MASK_CAPT_EVT1 = PWMSS_ECAP_ECEINT_CEVT1_MASK,
    /**< Capture Event 1 Interrupt */
    ECAP_INTR_MASK_CAPT_EVT2 = PWMSS_ECAP_ECEINT_CEVT2_MASK,
    /**< Capture Event 2 Interrupt */
    ECAP_INTR_MASK_CAPT_EVT3 = PWMSS_ECAP_ECEINT_CEVT3_MASK,
    /**< Capture Event 3 Interrupt */
    ECAP_INTR_MASK_CAPT_EVT4 = PWMSS_ECAP_ECEINT_CEVT4_MASK,
    /**< Capture Event 4 Interrupt */
    ECAP_INTR_MASK_COUNTER_OVERFLOW = PWMSS_ECAP_ECEINT_CNTOVF_MASK,
    /**< Counter over flow Interrupt */
    ECAP_INTR_MASK_COUNTER_PERIOD_EQUAL = PWMSS_ECAP_ECEINT_PRDEQ_MASK,
    /**< Counter Period Equal Interrupt */
    ECAP_INTR_MASK_COUNTER_COMPARE_EQUAL = PWMSS_ECAP_ECEINT_CMPEQ_MASK,
    /**< Counter Compare Equal Interrupt */
    ECAP_INTR_MASK_ALL = 0xFFU
    /**< Interrupt Mask value to identify all interrupts. */
}ecapIntrMask_t;

/** \brief Enumerates the Stop/Wrap Values for Capture Events. */
typedef enum ecapStopWrapEvt
{
    ECAP_STOP_WRAP_EVT_1 = PWMSS_ECAP_ECCTL2_STOP_WRAP_CAPT_EVT1,
    /**< Value to indicate the counter behaviour after Capture Event 1 */
    ECAP_STOP_WRAP_EVT_2 = PWMSS_ECAP_ECCTL2_STOP_WRAP_CAPT_EVT2,
    /**< Value to indicate the counter behaviour after Capture Event 2 */
    ECAP_STOP_WRAP_EVT_3 = PWMSS_ECAP_ECCTL2_STOP_WRAP_CAPT_EVT3,
    /**< Value to indicate the counter behaviour after Capture Event 3 */
    ECAP_STOP_WRAP_EVT_4 = PWMSS_ECAP_ECCTL2_STOP_WRAP_CAPT_EVT4,
    /**< Value to indicate the counter behaviour after Capture Event 4 */
}ecapStopWrapEvt_t;

/** \brief Enumerates the different APWM mode output polarity. */
typedef enum ecapApwmOutputPol
{
    ECAP_APWM_OUTPUT_POL_ACT_HIGH = PWMSS_ECAP_ECCTL2_APWMPOL_ACTIVE_HIGH,
    /**< ECAP APWM mode output polarity Active High. */
    ECAP_APWM_OUTPUT_POL_ACT_LOW = PWMSS_ECAP_ECCTL2_APWMPOL_ACTIVE_LOW
    /**< ECAP APWM mode output polarity Active Low. */
}ecapApwmOutputPol_t;

/** \brief Enumerates the different SyncOut Event properties. */
typedef enum ecapSyncOutCfg
{
    ECAP_SYNC_OUT_SEL_SYNCIN = PWMSS_ECAP_ECCTL2_SYNCO_SEL_SYNC_IN,
    /**< Select SyncIn event to be SyncOut signal. */
    ECAP_SYNC_OUT_SEL_PRD_EQUAL_EVT = PWMSS_ECAP_ECCTL2_SYNCO_SEL_PRDEQ,
    /**< Select Period Equal event to be SyncOut signal. */
    ECAP_SYNC_OUT_SEL_DISABLE_SYNCOUT = PWMSS_ECAP_ECCTL2_SYNCO_SEL_DISABLE1
    /**< Disable the Sync out signal. */
}ecapSyncOutCfg_t;

/** \brief Emulation Mode. This selects the behaviour of the ePWM time-base
           counter during emulation events. */
typedef enum ecapEmuCtrl
{
    ECAP_EMU_CTRL_STOP_MODE = PWMSS_ECAP_ECCTL1_FREE_SOFT_STOP,
    /**< Time Stamp counter Stops immediately after emulation suspend. */
    ECAP_EMU_CTRL_COUNTER_0_MODE = PWMSS_ECAP_ECCTL1_FREE_SOFT_RUN_0,
    /**< Time Stamp counter runs till counter becomes 0. */
    ECAP_EMU_CTRL_RUN_FREE_MODE1 = PWMSS_ECAP_ECCTL1_FREE_SOFT_RUN_FREE1,
    /**< Time Stamp counter is not affected by emulation suspend. */
    ECAP_EMU_CTRL_RUN_FREE_MODE2 = PWMSS_ECAP_ECCTL1_FREE_SOFT_RUN_FREE2,
    /**< Time Stamp counter is not affected by emulation suspend. */
}ecapEmuCtrl_t;

/** \brief Structure holding the ECAP register context .*/
typedef struct ecapCtx
{
    uint32_t pwmssClkCfg;
    /**< PWMSS Clock Config register. */
    uint16_t ecapCtrl1;
    /**< ECAP Capture Control 1 register.*/
    uint16_t ecapCtrl2;
    /**< ECAP Capture Control 1 register.*/
    uint16_t ecapIntr;
    /**< ECAP Interrupt Enable register.*/
    uint32_t ecapTimeCounter;
    /**< ECAP Time Stamp Counter register. */
    uint32_t ecapCaptEvt1;
    /**< ECAP Capture Event1 register */
    uint32_t ecapCaptEvt2;
    /**< ECAP Capture Event2 register. */
    uint32_t ecapCaptEvt3;
    /**< ECAP Capture Event3 register */
    uint32_t ecapCaptEvt4;
    /**< ECAP Capture Event4 register. */
}ecapCtx_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function returns the Revision ID of the ECAP module.
 *
 * \param   baseAddr   Base Address of PWMSS instance used.
 *
 * \retval  revision   The Revision ID of the module.
 */
uint32_t ECAPGetRevision(uint32_t baseAddr);

/**
 * \brief   This function Enables/Disables clock for ECAP module in the PWM
 *          subsystem.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   enableClk   It specifies whether to enable/disable the Clocks for
 *                      ECAP module within the PWM subsystem.
 *          'enableClk' can take any of the two values to enable or disable the
 *          clocks.
 *          - TRUE to enable clocks to ECAP.
 *          - FALSE to disable clocks to ECAP.
 *
 * \note    This API enables/disables the clock for the ECAP module which is
 *          part of the PWM subsystem. The clocks for the PWM Sub system will be
 *          enabled/disabled inside the PRCM module.
 */
void ECAPClkEnable(uint32_t baseAddr, uint32_t enableClk);

/**
 * \brief   This API configures the operating mode of ECAP to either Capture
 *          or Auxiliary PWM mode.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   operMode    It is the value to specify selecting one of the modes of
 *                      operation for ECAP.
 *          'operMode'  can take any of the two values from the following enum
 *          - #ecapOperMode_t
 */
void ECAPSetOperMode(uint32_t baseAddr, uint32_t operMode);

/**
 * \brief   This API configures the ECAP in either continuous mode or one shot
 *          Capture Mode.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   captMode    It is the value to specify to select one of the capture
 *                      modes of ECAP.
 *          'captMode'  can take any of the two values from the following enum
 *          - #ecapCaptMode_t
 *
 * \note    The Continuous and One-shot mode are applicable only for capture
 *          functionality of ECAP.
 */
void ECAPSetCaptureMode(uint32_t baseAddr, uint32_t captMode);

/**
 * \brief   This function controls enabling/disabling of the Loading of the
 *          capture registers with the time stamp value on a capture event.
 *
 * \param   baseAddr        Base Address of PWMSS instance used.
 * \param   enableCaptLoad  Value to specify Enabling/Disabling the loading of
 *                          time stamps on to the the  capture registers on
 *                          a capture event.
 *          'enableCaptLoad' can take any of the two values from the following
 *          - TRUE To enable the Capture loading feature.
 *          - FALSE To disable the Capture loading feature.
 */
void ECAPCaptureLoadEnable(uint32_t baseAddr, uint32_t enableCaptLoad);

/**
 * \brief   This function sets the prescale value for the input capture signal.
 *
 * \param   baseAddr     Base Address of PWMSS instance used.
 * \param   prescaleVal  It is the value which is used to pre-scale the incoming
 *                       input.
 *         'prescaleVal' can take any integer value between '0' and '62'
 */
void ECAPSetEvtPrescale(uint32_t baseAddr, uint32_t prescaleVal);

/**
 * \brief   This function returns the time stamp captured for a given capture
 *          event.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   captEvtNum  It is the value which determines for which capture event
 *                      time stamp value has to returned.
 *          'captEvtNum' can take one of the values from the following enum
 *          - #ecapCaptEvt_t
 *
 * \retval  timeStampVal The time stamp captured for the selected capture event.
 */
uint32_t ECAPGetTimeStamp(uint32_t baseAddr, uint32_t captEvtNum);

/**
 *  \brief   This function sets the counter value in Time-Stamp Counter which
 *           serves as the capture time base.
 *
 *  \param   baseAddr       Base Address of PWMSS instance used.
 *  \param   timeBaseVal    The value which has to be set in the Time-Stamp
 *                          counter which serves as the time base.
 *           'timeBaseVal' can take any value from 0 to 0xFFFFFFFF
 */
void ECAPSetCounterTimeBase(uint32_t baseAddr, uint32_t timeBaseVal);

/**
 *  \brief    This function controls the time-stamp counter by programming
 *            it to run in free run mode or stop it.
 *
 *  \param    baseAddr       Base Address of PWMSS instance used.
 *  \param    enableCounter  The value to specify the programming the counter
 *                           in free run mode or stop it.
 *            'enableCounter' can take any of the two values from the following
 *            - TRUE  To enable the counter to run in free-run mode.
 *            - FALSE To stop the Time-stamp counter.
 */
void ECAPTimeStampCounterEnable(uint32_t baseAddr,
                                uint32_t enableCounter);

/**
 *  \brief   This function sets the capture event polarity for a specific event
 *           number.
 *
 *  \param   baseAddr      Base Address of PWMSS instance used.
 *  \param   captEvtNum    Value to select the appropriate capture event.
 *           'captEvtNum' can take any of the values from the following enum
 *           - #ecapCaptEvt_t
 *  \param   evtPol      Value indicating the polarity to be configured for the
 *                       selected capture event.
 *           'evtPol' can take any of the 2 values from the following enum
 *           - #ecapCaptEvtPol_t
 */
void ECAPSetCaptEvtPol(uint32_t baseAddr,
                       uint32_t captEvtNum,
                       uint32_t evtPol);

/**
 *  \brief   This function enables/disables reset of the time stamp counter
 *           after a capture event.
 *
 *  \param   baseAddr        Base Address of PWMSS instance used.
 *  \param   captEvtNum      Value to select the appropriate capture event.
 *           'captEvtNum' can take any of the values from the following enum
 *           - #ecapCaptEvt_t
 *  \param   counterCfg      Value to specify whether counter needs to be
 *           reset after a capture event.
 *           'counterCfg' can take any of the two values from the following
 *           enum #ecapCaptEvtCounterCfg_t
 */
void ECAPCaptEvtCounterResetConfig(uint32_t baseAddr,
                                   uint32_t captEvtNum,
                                   uint32_t counterCfg);

/**
 *  \brief   This function sets the Stop/Wrap Value for a capture Event
 *           in One-shot and Continuous modes.
 *
 *  \details  In One-Shot mode this represents the number of capture values
 *            allowed before the Capture registers are frozen.
 *            In Continuous mode the number of times the circular buffer wraps
 *            around and starts again.
 *
 *  \param    baseAddr       Base Address of PWMSS instance used.
 *  \param    stopWrapVal    Value to specify for which capture event the
 *                           counter is stopped in one shot mode or the Mod4
 *                           counter wraps around in continuous mode.
 *           'stopWrapEvt' can take one of the values from the following enum
 *           - #ecapStopWrapEvt_t
 */
void ECAPSetStopWrapVal(uint32_t baseAddr, uint32_t stopWrapVal);

/**
 *  \brief    This function enables the One-shot Re-Arming feature. This sets
 *            Mod4 counter to zero, Unfreezes the counter and enables the
 *            capture loads.
 *
 *  \param    baseAddr      Base Address of PWMSS instance used.
 */
void ECAPSetOneShotReArmingMode(uint32_t baseAddr);

/**
 *  \brief    This function configures the output polarity of the APWM pulse
 *            output.
 *
 *  \param    baseAddr      Base Address of PWMSS instance used.
 *  \param    outputPol     The value to specify the polarity of APWM output.
 *                          This can take any of the values from the following
 *                          enum - #ecapApwmOutputPol_t
 */
void ECAPSetApwmOutputPol(uint32_t baseAddr, uint32_t outputPol);

/**
 *  \brief    This function configures the Period and Compare Values in APWM
 *            mode to generate a PWM output.
 *
 *  \param    baseAddr      Base Address of PWMSS instance used.
 *  \param    compareVal    The compare value to be set to generate the PWM
 *                          pulse output.
 *  \param    periodVal     The period value to be set to generate the PWM
 *                          pulse output.
 */
void ECAPApwmOutputConfig(uint32_t baseAddr,
                          uint32_t compareVal,
                          uint32_t periodVal);

/**
 *  \brief    This function configures the Period and Compare Values in APWM
 *            mode in the Shadow registers to generate a PWM output.
 *
 *  \param    baseAddr      Base Address of PWMSS instance used.
 *  \param    compareVal    The compare value to be set in shadow register
 *                          to generate the PWM pulse output.
 *  \param    periodVal     The period value to be set in shadow register
 *                          to generate the PWM pulse output.
 */
void ECAPApwmShadowModeConfig(uint32_t baseAddr,
                              uint32_t compareVal,
                              uint32_t periodVal);

/**
 *  \brief    This function sets the Counter Phase offset value
 *
 *  \details  This feature is used to achieve phase control synchronization
 *            with respect to other ECAP and EPWM time bases.
 *
 *  \param    baseAddr    Base Address of PWMSS instance used.
 *  \param    phaseVal    The counter phase value that can be set for phase
 *                        lag/lead.
 *            'phaseVal' accepts any value between '0' and '0xFFFFFFFF'
 */
void ECAPSetCounterPhaseVal(uint32_t baseAddr, uint32_t phaseVal);

/**
 *  \brief    This function controls enabling/disabling the Sync-In select mode.
 *
 *  \details  In Sync-In mode the time-stamp counter is loaded the counter phase
 *            offset value upon either the SYNCI signal or the software event.
 *
 *  \param    baseAddr       Base Address of PWMSS instance used.
 *  \param    enableSyncIn   The value to control enabling/disabling the
 *                           syncIn mode.
 *            'enableSyncIn' can take any of the two values from the following
 *            - TRUE   To enable the Sync-In mode.
 *            - FALSE  To disable the Sync-In mode.
 */
void ECAPSyncInEnable(uint32_t baseAddr, uint32_t enableSyncIn);

/**
 *  \brief    This function enables the Software forced counter synchronizing
 *            feature. This synchronizes all the ECAP time bases.
 *
 *  \param    baseAddr       Base Address of PWMSS instance used.
 */
void ECAPSwSyncForceCounterEnable(uint32_t baseAddr);

/**
 *  \brief    This function configures the Sync-Out Event features like Period
 *            Equal event to be the Sync-out signal, Sync-In to be the Sync-Out
 *            signal(Pass through).
 *
 *  \param    baseAddr       Base Address of PWMSS instance used.
 *  \param    syncOutCtrl    The value which specify different features of the
 *                           syncout to be configured
 *            'syncOutCtrl' can take any of the values from the following enum
 *            - #ecapSyncOutCfg_t
 */
void ECAPSyncOutSignalCtrl(uint32_t baseAddr, uint32_t syncOutCtrl);

/**
 * \brief   This function enables the Interrupts for ECAP module.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   intrMask    This specifies the interrupts which have to be enabled
 *                      for the ECAP.
 *          'intrMask' can take any of the values from the following enum
 *          - #ecapIntrMask_t
 */
void ECAPIntrEnable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief   This function disables the Interrupts for ECAP module.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   intrMask    This specifies the interrupts which have to be disabled
 *                      for the ECAP.
 *          'intrMask' can take any of the values from the following enum
 *          - #ecapIntrMask_t
 */
void ECAPIntrDisable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief  This API returns the status of all active and enabled interrupts.
 *
 * \param  baseAddr  Base Address of PWMSS instance used.
 *
 * \retval status    The status of all the active and enabled Interrupts.
 *
 * \note   To Check the status of a specific interrupt AND the return value
 *         of the API with specific interrupt mask from the following enum.
 *         - #ecapIntrMask_t.
 */
uint32_t ECAPIntrStatus(uint32_t baseAddr);

/**
 * \brief  This API  Clears the status of specified interrupts.
 *
 * \param  baseAddr  Base Address of PWMSS instance used.
 * \param  intrMask  It specifies the interrupts whose status needs to be
 *                   cleared intrMask will be one of the macros from the
 *                   following enum - #ecapIntrMask_t.
 *
 * \note   Along with clearing the status of the specific interrupt. This API
 *         clears the Global Interrupt bit to enable generation of further
 *         interrupts.
 */
void ECAPIntrClear(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief   This function triggers an interrupt request for a specified event.
 *
 * \param   baseAddr    Base Address of PWMSS instance used.
 * \param   intrMask    This specifies the interrupts which have to be triggered
 *                      for the ECAP.
 *          'intrMask' can take any of the values from the following enum
 *          - #ecapIntrMask_t
 *
 * \note   This feature is used for Debug purposes.
 */
void ECAPIntrTrigger(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief   This function configures the behaviour of ECAP module under
 *          Emulation suspend condition.
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 * \param   emuCtrlMode   This specifies the behaviour of ECAP counters on
 *                        emulation suspend.
 *          'emuCtrlMode' can take any of the values from the following enum:
 *          - #ecapEmuCtrl_t
 */
void ECAPSetEmuCtrlMode(uint32_t baseAddr, uint32_t emuCtrlMode);

/**
 * \brief   This API can be used to save the Register context of ECAP
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 * \param   pCtx          Pointer to the #ecapCtx_t structure where ECAP
 *                        register context need to be saved.
 */
void ECAPContextSave(uint32_t baseAddr, ecapCtx_t *pCtx);

/**
 * \brief   This API can be used to restore the register context of ECAP.
 *
 * \param   baseAddr      Base Address of PWMSS instance used.
 * \param   pCtx          Pointer to the #ecapCtx_t structure from where ECAP
 *                        register context need to be restored.
 */
void ECAPContextRestore(uint32_t baseAddr, ecapCtx_t *pCtx);

/*******************************************************************************
*                       Deprecated Function Declarations
*******************************************************************************/

/**
 * \brief   This function determines whether clock to ECAP module is enabled or
 *          not.
 */
DEPRECATED(uint32_t ECAPClockEnableStatusGet(uint32_t baseAddr));

/**
 * \brief   This function determines whether clock to ECAP module is disabled
 *          or not.
 */
DEPRECATED(uint32_t ECAPClockDisableStatusGet(uint32_t baseAddr));

#ifdef __cplusplus
}
#endif

#endif  
