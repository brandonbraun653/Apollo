/**
 *  \file       rtc.h
 *
 *  \brief     This file contains declarations of device abstraction layer APIs
 *             corresponding to the RTC module. This also contains necessary
 *             structure, enum and macro definitions.
 *
 *  \details   Programming sequence of RTC is as follows:
 *           -# Enable the module Clocks for RTC through PRCMModuleEnable API.
 *           -# Disable the Write Protection to the registers through the API
 *              #RTCWriteProtectEnable
 *           -# Select the Clock Source for the RTC through the API
 *              #RTCClkSrcSelect.
 *           -# Enable the RTC module to ensure 32k Clock is not gated
 *              through the API #RTCEnable
 *           -# Set the Time information including the hour mode in RTC
 *              registers through the API #RTCSetTime
 *           -# Set the Date information including the day of the week in RTC
 *              registers through the API #RTCSetDate
 *           -# Set the RTC 32k counter to run using the API #RTCRun
 *           -# If periodic interrupts are needed then Enable Timer Interrupts
 *              to occur every desired period using the API #RTCTimerIntrEnable
 *           -# If Alarm interrupts are needed then enable the ALARM
 *              interrupts through the API #RTCAlarmIntrEnable.
 *           -# Alarm Time and Date can be set through the following APIs
 *              #RTCSetAlarm and #RTCGetAlarm.
 *           -# Rounding to nearest minute feature can be enabled through the
 *              API #RTCRoundingEnable.
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

#ifndef RTC_H__
#define RTC_H__

#include "misc.h"
#include "hw_rtc.h"
#include "date_time.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*              API compatibility with Starterware 2.0                        */
/* ========================================================================== */
#define RTCRevisionIDGet              RTCGetRevision
#define RTCIntTimerEnable             RTCTimerIntrEnable
#define RTCEventUpdateGet             RTCTimerIntrStatus
#define RTCIntAlarm2Enable            RTCAlarmIntrEnable
#define RTCIntAlarmEnable             RTCAlarmIntrEnable
#define RTCIntAlarmDisable            RTCAlarmIntrDisable
#define RTCAlarm2IntStatusGet         RTCAlarmIntrStatus
#define RTCAlarmIntStatusGet          RTCAlarmIntrStatus
#define RTCAlarmIntStatusClear        RTCAlarmIntrClear
#define RTCAlarm2IntStatusClear       RTCAlarmIntrClear
#define RTCBusyStatusGet              RTCIsBusy
#define RTCMinRoundingEnable          RTCRoundingEnable
#define RTCScratchPadSet              RTCSetScratchPadVal
#define RTCScratchPadGet              RTCGetScratchPadVal
#define RTCIdleModeConfigure          RTCSetIdleMode
#define RTCConfigPmicPowerEnable      RTCPmicPowerEnable
#define RTCConfigPmicExtWakePolarity  RTCPmicExtWakeupPol
#define RTCPmicExtWakeStatusClear     RTCPmicExtWakeupClear
#define RTCFeedbackResistanceSelect   RTCFeedbackResistorSel
#define RTCCompensationSet            RTCSetCompensationVal
#define RTCCompensationGet            RTCGetCompensationVal
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the different clock sources for RTC */
typedef enum rtcClkSrc
{
    RTC_CLK_SRC_INTERNAL = RTCSS_OSC_REG_32KCLK_SEL_INTERNAL,
    /**< External Clock source for the RTC module */
    RTC_CLK_SRC_EXTERNAL = RTCSS_OSC_REG_32KCLK_SEL_EXTERNAL
    /**< Internal clock source for the RTC module */
}rtcClkSrc_t;

/** \brief Enumerates the different possible Timer Interrupt types */
typedef enum rtcTimerIntrMask
{
    RTC_TIMER_INTR_MASK_EVERY_SEC = RTCSS_INTRS_REG_EVERY_SEC,
    /**< Periodic Timer Interrupt for Every Second */
    RTC_TIMER_INTR_MASK_EVERY_MIN = RTCSS_INTRS_REG_EVERY_MIN,
    /**< Periodic Timer Interrupt for Every Minute */
    RTC_TIMER_INTR_MASK_EVERY_HR = RTCSS_INTRS_REG_EVERY_HOUR,
    /**< Periodic Timer Interrupt for Every Hour */
    RTC_TIMER_INTR_MASK_EVERY_DAY = RTCSS_INTRS_REG_EVERY_DAY,
    /**< Periodic Timer Interrupt for Every Day */
}rtcTimerIntrMask_t;

/** \brief Enumerates the RTC Timer Interrupt Status. */
typedef enum rtcTimerIntrSts
{
    RTC_TIMER_INTR_STS_ONE_DAY = RTCSS_STS_REG_1D_EVT_MASK,
    /**< Indicates 1 Day Interrupt Status */
    RTC_TIMER_INTR_STS_ONE_HR = RTCSS_STS_REG_1H_EVT_MASK,
    /**< Indicates 1 Hour Interrupt Status */
    RTC_TIMER_INTR_STS_ONE_MIN = RTCSS_STS_REG_1M_EVT_MASK,
    /**< Indicates 1 Minute Interrupt Status */
    RTC_TIMER_INTR_STS_ONE_SEC = RTCSS_STS_REG_1S_EVT_MASK,
    /**< Indicates 1 Second Interrupt Status */
    RTC_TIMER_INTR_STS_ALL = (RTCSS_STS_REG_1D_EVT_MASK |
                               RTCSS_STS_REG_1H_EVT_MASK |
                               RTCSS_STS_REG_1M_EVT_MASK |
                               RTCSS_STS_REG_1S_EVT_MASK)
    /**< Mask value to determine occurrence of a Timer event. */
}rtcTimerIntrSts_t;

/** \brief Enumerates the RTC Alarm Interrupt Status. */
typedef enum rtcAlarmIntrSts
{
    RTC_ALARM_INTR_STS_ALARM = RTCSS_STS_REG_ALARM_MASK,
    /**< Indicates the ALARM Interrupt has occured. */
    RTC_ALARM_INTR_STS_ALARM2 = RTCSS_STS_REG_ALARM2_MASK,
    /**< Indicates ALARM2 Interrupt has occured. */
    RTC_ALARM_INTR_STS_ALL = (RTCSS_STS_REG_ALARM_MASK |
                              RTCSS_STS_REG_ALARM2_MASK)
    /**< Mask value to determine occurence of an alarm event. */
}rtcAlarmIntrSts_t;

/** \brief Enumerates the different Alarm events */
typedef enum rtcAlarmNum
{
    RTC_ALARM_NUM_MIN = 1U,
    /**< Minimum Alarm Event Number. */
    RTC_ALARM_NUM_1 = RTC_ALARM_NUM_MIN,
    /**< Alarm Event number 1. */
    RTC_ALARM_NUM_2,
    /**< Alarm Event number 2. */
    RTC_ALARM_NUM_MAX = RTC_ALARM_NUM_2
    /**< Maximum Alarm Event Number. */
}rtcAlarmNum_t;

/** \brief Enumerates the different idle modes supported */
typedef enum rtcIdleMode
{
    RTC_IDLE_MODE_FORCE_IDLE = RTCSS_SYSCONFIG_IDLEMODE_FORCE_IDLE,
    /**< Force Idle mode. */
    RTC_IDLE_MODE_NO_IDLE    = RTCSS_SYSCONFIG_IDLEMODE_NO_IDLE,
    /**< No idle mode. */
    RTC_IDLE_MODE_SMART_IDLE = RTCSS_SYSCONFIG_IDLEMODE_SMART_IDLE,
    /**< Smart idle mode. */
    RTC_IDLE_MODE_SMART_IDLE_WAKEUP =
                            RTCSS_SYSCONFIG_IDLEMODE_SMART_IDLE_WAKEUP
    /**< Smart idle Wakeup mode. */
}rtcIdleMode_t;

/** \brief Enumerates the different wakeup sources for RTC. */
typedef enum rtcWakeupEvtSrc
{
    RTC_WAKEUP_EVT_SRC_MIN = 0U,
    /**< Minimum Wakeup event source used for validation */
    RTC_WAKEUP_EVT_SRC_TIMER = RTC_WAKEUP_EVT_SRC_MIN,
    /**< Timer Wakeup event source. */
    RTC_WAKEUP_EVT_SRC_ALARM,
    /**< Alarm Wakeup event source. */
    RTC_WAKEUP_EVT_SRC_MAX = RTC_WAKEUP_EVT_SRC_ALARM
    /**< Minimum Wakeup event source used for validation. */
}rtcWakeupEvtSrc_t;

/** \brief Enumerates the different external Wakeup event sources which
           can be used to wakeup the RTC module. */
typedef enum rtcExtWakeupSrc
{
    RTC_EXT_WAKEUP_SRC_MIN = 0U,
    /**< Minimum External Wakeup Source. */
    RTC_EXT_WAKEUP_SRC_0 = RTC_EXT_WAKEUP_SRC_MIN,
    /**< External Wakeup Source 0 used to wakeup RTC. */
    RTC_EXT_WAKEUP_SRC_1,
    /**< External Wakeup Source 1 used to wakeup RTC. */
    RTC_EXT_WAKEUP_SRC_2,
    /**< External Wakeup Source 2 used to wakeup RTC. */
    RTC_EXT_WAKEUP_SRC_3,
    /**< External Wakeup Source 3 used to wakeup RTC. */
    RTC_EXT_WAKEUP_SRC_MAX = RTC_EXT_WAKEUP_SRC_3
    /**< Maximum External Wakeup Source */
}rtcExtWakeupSrc_t;

/** \brief Enumerates the external event polarity */
typedef enum rtcWakeupEvtPol
{
    RTC_WAKEUP_EVT_POL_ACTV_HIGH = RTCSS_PMIC_EXT_WAKEUP_POL_ACTIVE_HIGH,
    /**< RTC WAKEUP EVENT POLARITY ACTIVE HIGH */
    RTC_WAKEUP_EVT_POL_ACTV_LOW = RTCSS_PMIC_EXT_WAKEUP_POL_ACTIVE_LOW
    /**< RTC WAKEUP EVENT POLARITY ACTIVE LOW */
}rtcWakeupEvtPol_t;

/** \brief Enumerates the different scratch pad registers. */
typedef enum rtcScratchPadReg
{
    RTC_SCRATCH_PAD_REG_MIN = 0U,
    /**< Minimum Scratch pad register number */
    RTC_SCRATCH_PAD_REG_0 = RTC_SCRATCH_PAD_REG_MIN,
    /**< Scratch pad register number 0 */
    RTC_SCRATCH_PAD_REG_1,
    /**< Scratch pad register number 1 */
    RTC_SCRATCH_PAD_REG_2,
    /**< Scratch pad register number 2 */
    RTC_SCRATCH_PAD_REG_MAX = RTC_SCRATCH_PAD_REG_2
    /**< Maximum Scratch pad register number */
}rtcScratchPadReg_t;

/** \brief Enumerates the Feedback resistor types */
typedef enum rtcFeedbackResistor
{
    RTC_FEEDBACK_RESISTOR_INTERNAL = RTCSS_OSC_REG_RES_SELECT_INTERNAL,
    /**< Internal oscillator feedback resistor */
    RTC_FEEDBACK_RESISTOR_EXTERNAL = RTCSS_OSC_REG_RES_SELECT_EXTERNAL
    /**< External oscillator feedback resistor */
}rtcFeedbackResistor_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function returns the revision Id of the module.
 *
 * \param   baseAddr   The base address of the RTC module.
 *
 * \retval  revision   The revision number of the RTC module.
 *          This will give the information regarding the major and minor
 *          revisions
 *          - Bits[10:8]  - Major revision
 *          - Bits[7:6]   - Custom revision for a particular device
 *          - Bits[5:0]   - Minor revision
 */
uint32_t RTCGetRevision(uint32_t baseAddr);

/**
 * \brief   This function enables/disables the write-protection for RTC
 *          registers.
 *
 * \param   baseAddr            The base address of the RTC module.
 * \param   enableWriteProtect  Value to specify whether write protection
 *                              feature has to be enabled/disabled.
 *          'enableWriteProtect' can take any of the two values
 *          - TRUE  to enable write protection the register are locked from
 *                  spurious writes.
 *          - FALSE to disable write protection to allow write access to RTC
 *                  registers.
 */
void RTCWriteProtectEnable(uint32_t baseAddr, uint32_t enableWriteProtect);

/**
 * \brief  This API selects the clock source for the RTC module.
 *         RTC can be supplied clock either from an
 *         Internal clock source derived from the PLL or an
 *         External clock source.
 *
 * \param  baseAddr  The base address of the RTC module.
 * \param  clkSrc    This specifies the RTC Clock source to be selected
 *        'clkSrc' can take one of the values from the following enum
 *         - #rtcClkSrc_t
 */
void RTCClkSrcSelect(uint32_t baseAddr, uint32_t clkSrc);

/**
 *  \brief    This API enables/disables the RTC module. It also enables
 *            the RTC module to receive clocks from the selected clk source.
 *
 *  \details  On disabling the module the 32kHz reference clock is gated.
 *
 *  \param    baseAddr      The base Address of the RTC module.
 *  \param    enableModule  Value to indicate enabling/disabling of the
 *                          module.
 *            'enableModule' can take any of the two values:
 *            - TRUE to enable the module.
 *            - FALSE to disable the module.
 */
void RTCEnable(uint32_t baseAddr, uint32_t enableModule);

/**
 * \brief    This function sets the RTC to run with the programmed
 *           date and time information.
 *
 * \param    baseAddr   The base address of the RTC module.
 */
void RTCRun(uint32_t baseAddr);

/**
 * \brief   This function stops the RTC.
 *
 * \param   baseAddr   The base address of the RTC module.
 *
 */
void RTCStop(uint32_t baseAddr);

/**
 * \brief      This function enables the periodic timer interrupt.
 *
 * \details    This API also enables the Timer interrupt for a specific period
 *             along with the Timer Interrupt feature.
 *
 * \param      baseAddr    The base address of the RTC module.
 * \param      intrMask    This specifies the period between two consecutive
 *                         Timer interrupts.
 *             'intrMask' can take one of the following
 *                        values from the following enum - #rtcTimerIntrMask_t.
 *
 * \note    If the RTC is busy in updating its registers, then this API waits
 *          until this update is complete.
 */
void RTCTimerIntrEnable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief   This function disables the periodic timer interrupts.
 *
 * \param   baseAddr    The base address of the RTC module.
 *
 * \note    If the RTC is busy in updating its registers, then this API waits
 *          until this update is complete.
 */
void RTCTimerIntrDisable(uint32_t baseAddr);

/**
 * \brief   This function returns the status of TIMER interrupt events.
 *
 * \param   baseAddr    The base address of the RTC module.
 *
 * \retval  timerStatus   This status of timer events.
 *          'timerStatus' can take any of the values from the following enum
 *          - #rtcTimerIntrSts_t
 *
 * \note    To check the status of the specific Timer interrupt event AND the
 *          return value of the API with the mask from the following enum:
 *          - #rtcTimerIntrSts_t
 */
uint32_t RTCTimerIntrStatus(uint32_t baseAddr);

/**
 * \brief   This function enables ALARM interrupts.
 *
 * \param   baseAddr   The base address of the RTC module.
 * \param   alarmNum   The value identifies the alarm register for which the
 *                     Interrupts have to be enabled.
 *          'alarmNum' can take any of the values from the following enum:
 *          - #rtcAlarmNum_t
 *
 * \note    If the RTC is busy in updating its registers, then this API waits
 *          until this update is complete.
 */
void RTCAlarmIntrEnable(uint32_t baseAddr, uint32_t alarmNum);

/**
 * \brief   This function disables the ALARM interrupts.
 *
 * \param   baseAddr   The base address of the RTC module.
 * \param   alarmNum   The value identifies the alarm register for which the
 *                     Interrupts have to be disabled.
 *          'alarmNum' can take any of the values from the following enum:
 *          - #rtcAlarmNum_t
 *
 * \note    If the RTC is busy in updating its registers, then this API waits
 *          until this update is complete.
 */
void RTCAlarmIntrDisable(uint32_t baseAddr, uint32_t alarmNum);

/**
 * \brief   This function returns the status of ALARM interrupt events.
 *
 * \param   baseAddr    The base address of the RTC module.
 *
 * \retval  alarmStatus   This status of alarm events.
 *          'alarmStatus' can take any of the values from the following enum
 *          - #rtcAlarmIntrSts_t
 */
uint32_t RTCAlarmIntrStatus(uint32_t baseAddr);

/**
 * \brief   This function clears the ALARM interrupt status.
 *
 * \param   baseAddr   The base address of the RTC module.
 * \param   alarmNum   The value to identify between ALARM1 and ALARM2
 *                     registers.
 *          'alarmNum' can take any of the values from the following enum:
 *          - #rtcAlarmNum_t
 */
void RTCAlarmIntrClear(uint32_t baseAddr, uint32_t alarmNum);

/**
 * \brief   This function returns the status of RTC module.
 *
 * \param   baseAddr    The base address of the RTC module.
 *
 * \retval  TRUE   indicating RTC is busy updating an event.
 *          FALSE  indicating RTC event update is more than 15 seconds from the
 *                 current time.
 */
uint32_t RTCIsBusy(uint32_t baseAddr);

/**
 * \brief   This function Enables/Disables the feature of minute rounding.
 *
 * \details The set time including the Minute and Second register value is
 *          rounded to the nearest minute with '00' seconds.
 *
 * \param   baseAddr        The base address of the RTC module.
 * \param   enableRounding  value to specify whether the Rounding feature
 *                          has to be enabled/disabled.
 *          'enableRounding' can take any of the two values:
 *          - TRUE to indicate enabling Rounding off feature
 *          - FALSE to indicate disabling Rounding off feature
 */
void RTCRoundingEnable(uint32_t baseAddr, uint32_t enableRounding);

/**
 * \brief   This function programs the specified time information in
 *          the Time registers.
 *
 * \param   baseAddr  The base address of the RTC module.
 * \param   pTime     pointer to the structure timeObj_t which contains the
 *                    variables representing the Time to be set in the RTC.
 *
 * \note    If the RTC is busy in updating its registers, then this API waits
 *          until this update is complete.
 *          This API just sets the time. To start the RTC clock #RTCRun API
 *          needs to be called.
 */
void RTCSetTime(uint32_t baseAddr, timeObj_t *pTime);

/**
 * \brief   This function reads the current time from the registers holding
 *          time information.
 *
 * \param   baseAddr  The base address of the RTC module.
 * \param   pTime     Pointer to the structure timeObj_t which contains the
 *                    variables representing the Time through which the time
 *                    set in the RTC will be returned.
 *
 * \note   If the RTC is busy in updating its registers, then this API waits
 *         until this update is complete.
 */
void RTCGetTime(uint32_t baseAddr, timeObj_t *pTime);

/**
 * \brief  This function sets the specified date information in registers
 *         holding date information.
 *
 * \param   baseAddr  The base address of the RTC module.
 * \param   pDate     pointer to the structure dateObj_t which contains the
 *                    variables representing the Date to be set in the RTC.
 *
 * \note    If the RTC is busy in updating its registers, then this API waits
 *          until this update is complete.
 */
void RTCSetDate(uint32_t baseAddr, dateObj_t *pDate);

/**
 * \brief   This function reads the calendar information from relevant
 *          registers holding date information.
 *
 * \param   baseAddr The base address of the RTC module.
 * \param   pDate    pointer to the structure dateObj_t holding the variables
 *                   representing the Date through which the date set in the RTC
 *                   will be returned.
 *
 * \note   If the RTC is busy in updating its registers, then this API waits
 *         until this update is complete.
 */
void RTCGetDate(uint32_t baseAddr, dateObj_t *pDate);

/**
 * \brief  This function sets the specified alarm register with Alarm
 *         information including Time and Date.
 *
 * \param  baseAddr    The base address of the RTC module.
 * \param  alarmNum    The value identifies the alarm register for which the
 *                     alarm is to be set.
 *         'alarmNum' can take any of the values from the following enum
 *         #rtcAlarmNum_t
 * \param  pAlarmTime  Pointer to the structure timeObj_t which contains the
 *                     variables representing Alarm Time to be set in the RTC.
 * \param  pAlarmDate  Pointer to the structure dateObj_t which contains the
 *                     variables representing Alarm Date to be set in the RTC.
 *
 * \note   If the RTC is busy in updating its registers, then this API waits
 *         until this update is complete.
 */
void RTCSetAlarm(uint32_t baseAddr,
                 uint32_t alarmNum,
                 timeObj_t *pAlarmTime,
                 dateObj_t *pAlarmDate);

/**
 * \brief   This function reads the programmed Alarm information including
 *          Time and Date from the specified alarm register.
 *
 * \param  baseAddr    The base address of the RTC module.
 * \param  alarmNum    The value identifies the alarm register from which the
 *                     alarm info is to be read.
 *         'alarmNum' can take any of the values from the following enum
 *         #rtcAlarmNum_t
 * \param  pAlarmTime  Pointer to the structure timeObj_t which contains the
 *                     variables representing Alarm Time through which the
 *                     set alarm time will be returned.
 * \param  pAlarmDate  Pointer to the structure dateObj_t which contains the
 *                     variables representing Alarm Date to be set in the RTC.
 *
 * \note    If the RTC is busy in updating its registers, then this API waits
 *          until this update is complete.
 */
void RTCGetAlarm(uint32_t baseAddr,
                 uint32_t alarmNum,
                 timeObj_t *pAlarmTime,
                 dateObj_t *pAlarmDate);

/**
 * \brief   This function writes the specified arbitrary value to the specified
 *          scratch register.
 *
 * \param   baseAddr    The base address of the RTC module.
 * \param   regNum      Specifies the scratch register number to be accessed.
 *                      This can take the values from the following enum
 *                      - #rtcScratchPadReg_t
 * \param   scratchVal  Refers to the value to be written to the scratch
 *                      registers.
 */
void RTCSetScratchPadVal(uint32_t baseAddr,
                         uint32_t regNum,
                         uint32_t scratchVal);

/**
 * \brief   This function reads the value stored in a specified scratch
 *          register.
 *
 * \param   baseAddr    The base address of the RTC module.
 * \param   regNum      Specifies the scratch register number to be accessed.
 *                      This can take the values from the following enum
 *                      - #rtcScratchPadReg_t
 *
 * \retval  scratchVal The value read from the scratch pad register.
 */
uint32_t RTCGetScratchPadVal(uint32_t baseAddr, uint32_t regNum);

/**
 * \brief   This API configures the Idle Mode for the RTC.
 *
 * \param   baseAddr  The base address of the RTC module.
 * \param   idleMode  This specifies the idle mode that is to be enabled.
 *          'idleMode' can take any of the values from the following enum
 *          - #rtcIdleMode_t
 */
void RTCSetIdleMode(uint32_t baseAddr, uint32_t idleMode);

/**
 * \brief  This API is used to Enable the Alarm and Timer event Wakeup signal
 *         to the CPU.
 *
 * \param  baseAddr      The base address of the RTC module.
 * \param  wakeupSrc     Value to specify the wakeup event source to disable
 *                       i.e. either the timer or the alarm based wakeup.
 *        'wakeupSrc' can take any of the values from the following enum
 *         - #rtcWakeupEvtSrc_t
 */
void RTCWakeupEnable(uint32_t baseAddr, uint32_t wakeupSrc);

/**
 * \brief  This API is used to Disable the Alarm and Timer event Wakeup signal
 *         to the CPU.
 *
 * \param  baseAddr      The base address of the RTC module.
 * \param  wakeupSrc     Value to specify the wakeup event source to disable
 *                       i.e. either the timer or the alarm based wakeup.
 *        'wakeupSrc' can take any of the values from the following enum
 *         - #rtcWakeupEvtSrc_t
 */
void RTCWakeupDisable(uint32_t baseAddr, uint32_t wakeupSrc);

/**
 * \brief    This API controls the PMIC power enable signal which can be used
 *           to control an external PMIC.
 *
 * \details  When disabled the PMIC Power Enable signal will always be driven to
 *           ON state. When enabled the signal will be controlled by ext_wakeup,
 *           ALARM and ALARM2 events.
 *
 * \param  baseAddr         The base address of the RTC module.
 * \param  enablePmicPower  This specifies whether the PMIC power enable signal
 *                          has to be pulled low or high.
 *         'enablePmicPower' can take any of the two values:
 *          - TRUE to enable PMIC power enable signal
 *          - FALSE to disable PMIC power enable signal
 *
 * \note   ALARM2 event causes the external PMIC to turn OFF(ON to OFF)
 *         ALARM or ext_wakeup event causes PMIC to turn ON(OFF to ON)
 */
void RTCPmicPowerEnable(uint32_t baseAddr, uint32_t enablePmicPower);

/**
 * \brief This API Enables the PMIC External Wakeup feature.
 *
 * \param  baseAddr       The base address of the RTC module.
 * \param  extWakeupSrc   The external Input pin to be configured
 *         'extWakeupSrc' can take any of the values from the following enum
 *          - #rtcExtWakeupSrc_t
 *
 * \note  Currently the RTC module in AM335x and AM43xx SOC supports only
 *        one external wakeup event i.e. only the ext_wakeup0 is supported.
 */
void RTCPmicExtWakeupEnable(uint32_t baseAddr, uint32_t extWakeupSrc);

/**
 * \brief This API Disables the PMIC External Wakeup feature.
 *
 * \param  baseAddr       The base address of the RTC module.
 * \param  extWakeupSrc   The external Input pin to be configured
 *         'extWakeupSrc' can take any of the values from the following enum
 *          - #rtcExtWakeupSrc_t
 *
 * \note  Currently the RTC module in AM335x and AM43xx SOC supports only
 *        one external wakeup event i.e. only the ext_wakeup0 is supported.
 */
void RTCPmicExtWakeupDisable(uint32_t baseAddr, uint32_t extWakeupSrc);

/**
 * \brief This API configures the Polarity of PMIC External Wakeup Pin
 *
 * \param  baseAddr         The base address of the RTC module.
 * \param  extWakeupSrc     The external Input pin to be configured
 *         'extWakeupSrc' can take any of the values from the following enum
 *          - #rtcExtWakeupSrc_t
 * \param  wakeupEvtPol     This specifies whether the PMIC External Wakeup
 *                          Polarity to be low or high.
 *         'wakeupEvtPol' can take any of the values from the following enum
 *          - #rtcWakeupEvtPol_t
 *
 * \note  Currently the RTC module in AM335x and AM43xx SOC supports only
 *        one external wakeup event i.e. only the ext_wakeup0 is supported.
 */
void RTCPmicExtWakeupPol(uint32_t baseAddr,
                         uint32_t extWakeupSrc,
                         uint32_t wakeupEvtPol);

/**
 * \brief  This API clears the PMIC External Wakeup Status
 *
 * \param  baseAddr       The base address of the RTC module.
 * \param  extWakeupSrc   The external Input pin to be configured
 *        'extWakeupSrc' can take any of the values from following enum
 *        - #rtcExtWakeupSrc_t
 *
 * \note  Currently the RTC module in AM335x and AM43xx SOC supports only
 *        one external wakeup event i.e. only the ext_wakeup0 is supported.
 */
void RTCPmicExtWakeupClear(uint32_t baseAddr, uint32_t extWakeupSrc);

/**
 * \brief  This API selects the mode of the Oscillator Feedback resistor to
 *         either internal or external of the SOC.
 *
 * \param  baseAddr      The base address of the RTC module.
 * \param  resistorSel   This specifies whether the Oscillator Feedback
 *                       resistor to be used should be either external or
 *                       internal to the SoC.
 *        'resistorSel' can take one of the following two values from the
 *        following enum - #rtcFeedbackResistor_t
 */
void RTCFeedbackResistorSel(uint32_t baseAddr, uint32_t resistorSel);

/**
 * \brief  This API Enables the External Wakeup Debounce feature.
 *
 * \param  baseAddr        The base address of the RTC module.
 * \param  extWakeupSrc   The external Input pin to be configured
 *        'extWakeupSrc' can take any of the values from following enum
 *        - #rtcExtWakeupSrc_t
 *
 * \note  Currently the RTC module in AM335x and AM43xx SOC supports only
 *        one external wakeup event i.e. only the ext_wakeup0 is supported.
 */
void RTCPmicExtWakeupDebounceEnable(uint32_t baseAddr, uint32_t extWakeupSrc);

/**
 * \brief  This API Disables the External Wakeup Debounce feature.
 *
 * \param  baseAddr        The base address of the RTC module.
 * \param  extWakeupSrc    The external Input pin to be configured
 *        'extWakeupSrc' can take any of the values from following enum
 *        - #rtcExtWakeupSrc_t
 *
 * \note  Currently the RTC module in AM335x and AM43xx SOC supports only
 *        one external wakeup event i.e. only the ext_wakeup0 is supported.
 */
void RTCPmicExtWakeupDebounceDisable(uint32_t baseAddr, uint32_t extWakeupSrc);

/**
 * \brief  This API sets the debounce time for the RTC module.
 *
 * \param  baseAddr        The base address of the RTC module.
 * \param  debounceTime    The value to specify the debounce time.
 */
void RTCSetDebounceTime(uint32_t baseAddr, uint32_t debounceTime);

/**
 * \brief  This API is used to Enable/Disable the Test mode of the RTC.
 *
 * \details In TEST mode the Auto Compensation is enabled when the 32K
 *          counter reaches its end.
 *
 * \param  baseAddr        The base address of the RTC module.
 * \param  enableTestMode  Value to specify enabling/disabling of the Test
 *                         Mode.
 *        'enableTestMode' can take one of the following values:
 *        - TRUE to enable a Test mode of the RTC
 *        - FALSE to disable Test mode and switch back to functional mode.
 */
void RTCTestModeEnable(uint32_t baseAddr, uint32_t enableTestMode);

/**
 * \brief  This API is used to Enable/Disable Crystal Compensation feature
 *         to account for any inaccuracy in 32K oscillator.
 *
 * \param  baseAddr            The base address of the RTC module.
 * \param  enableCompensation  Value to specify enabling/disabling of the Test
 *                             Mode.
 *        'enableCompensation' can take one of the following values:
 *        - TRUE to enable oscillator compensation feature
 *        - FALSE to disable oscillator compensation feature
 */
void RTCCompensationEnable(uint32_t baseAddr, uint32_t enableCompensation);

/**
 * \brief    This function sets the compensation registers with the
 *           specified drift compensation value versus one hour period of the
 *           oscillator frequency.
 *
 * \details  The compensation value to be set must be in decimal form. The API
 *           takes care of writing its 2's complement format into the register.
 *
 * \param   baseAddr   The base address of the RTC module.
 * \param   compVal    The drift compensation value.
 *
 * \note   The compensation value to be written should not be equal to 32769.
 *         As this value is forbidden.
 */
void RTCSetCompensationVal(uint32_t baseAddr, int32_t compVal);

/**
 * \brief   This function reads the compensation value being set in the
 *          compensation registers.
 *
 * \param   baseAddr   The base address of the RTC module.
 *
 * \retval  compVal    The value in the compensation registers COMPMSB and
 *                     COMPLSB.
 */
int32_t RTCGetCompensationVal(uint32_t baseAddr);

/* ========================================================================== */
/*                     Deprecated Macros                                      */
/* ========================================================================== */

/** \brief Macro to indicate the RTC disabled status. */
#define RTC_DISABLED                RTCSS_CTRL_REG_RTC_DISABLE_MASK

/** \brief Macro to indicate the RTC Enabled status. */
#define RTC_ENABELD                 RTCSS_CTRL_REG_RTC_DISABLE_ENABLE

/** \brief Macro to indicate the RTC is Running. */
#define RTC_STATUS_RUNNING          RTCSS_STS_REG_RUN_MASK

/** \brief Macro to indicate the RTC is Frozen. */
#define RTC_STATUS_FROZEN           (~RTCSS_STS_REG_RUN_MASK)

/* ========================================================================== */
/*                     Deprecated Function Declarations                       */
/* ========================================================================== */

/**
 *  \brief   This API checks whether the RTC module is enabled or not and
 *           returns the status.
 */
DEPRECATED(uint32_t RTCEnableStatus(uint32_t baseAddr));

/**
 *  \brief   This API checks whether the RTC module is enabled or not and
 *           returns the status.
 */
DEPRECATED(uint32_t RTCRunStatusGet(uint32_t baseAddr));

#ifdef __cplusplus
}
#endif
#endif
